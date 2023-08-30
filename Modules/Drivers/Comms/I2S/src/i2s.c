/****************************************************************************
 *
 * Copyright (c) 2022 STMicroelectronics - All Rights Reserved
 *
 * License terms: STMicroelectronics Proprietary in accordance with licensing
 * terms SLA0098 at www.st.com.
 *
 * THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
 * INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *****************************************************************************/
/**
 * @file    i2s.c
 * @brief   I2S driver source file.
 *
 * @addtogroup DRIVERS
 * @addtogroup COMMS
 * @ingroup DRIVERS
 * @addtogroup I2S
 * @ingroup COMMS
 * @{
 */

#include <i2s.h>
#include <i2s_private.h>

/*===========================================================================*/
/* Module local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Module exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Module local types.                                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Module local variables.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Local function prototypes                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Module local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   Enters in transmit mode.
 * @note    Called when I2S driver enters transmit mode.
 *
 * @param[in] \_idp\_   pointer to a @p i2s_driver_t structure
 *
 * @notapi
 */
#define I2S_TX_IN_PROGRESS(_idp_)                          \
    (_idp_)->tx_busy = I2S_TX_BUSY

/**
 * @brief  Exits from transmit mode.
 * @note   Called when I2S driver exits transmit mode.
 *
 * @param[in] \_idp\_   pointer to a @p i2s_driver_t structure
 *
 * @notapi
 */
#define I2S_TX_DONE(_idp_)                                 \
    (_idp_)->tx_busy = I2S_TX_READY

/**
 * @brief  Waits for transmit end.
 * @note   Called to wait for end of transmit.
 *
 * @param[in] \_idp\_   pointer to a @p i2s_driver_t structure
  *
 * @notapi
 */
#define I2S_WAIT_FOR_TX_COMPLETION(_idp_)                  \
    if ((_idp_)->drv_mode == I2S_DRV_MODE_SYNCHRONOUS) {   \
        while ((_idp_)->tx_busy == I2S_TX_BUSY) {;}        \
    }

/**
 * @brief   Enters in receiving mode.
 * @note    Called when I2S driver enters receiving mode.
 *
 * @param[in] \_idp\_   pointer to a @p i2s_driver_t structure
 *
 * @notapi
 */
#define I2S_RX_IN_PROGRESS(_idp_)                          \
    (_idp_)->rx_busy = I2S_RX_BUSY

/**
 * @brief   Exits from receiving mode.
 * @note    Called when I2S driver exits receiving mode.
 *
 * @param[in] \_idp\_   pointer to a @p i2s_driver_t structure
 *
 * @notapi
 */
#define I2S_RX_DONE(_idp_)                                 \
    (_idp_)->rx_busy = I2S_RX_READY

/**
 * @brief   Waits for receive end.
 * @note    Called to wait for end of receiving mode.
 *
 * @param[in] \_idp\_   pointer to a @p i2s_driver_t structure
 *
 * @notapi
 */
#define I2S_WAIT_FOR_RX_COMPLETION(_idp_)                  \
    if ((_idp_)->drv_mode == I2S_DRV_MODE_SYNCHRONOUS) {   \
        while ((_idp_)->rx_busy == I2S_RX_BUSY) {;}        \
    }

/**
 * @brief   Resets I2S parameters.
 *
 * @param[out] idp      pointer to an @p i2s_driver_t structure
 *
 * @notapi
 */
static void i2s_reset_paramters(i2s_driver_t *idp) {

    uint8_t i;

    /* Set all driver configuration parameters to default values.*/
    idp->tx_buf            = NULL;
    idp->tx_len            = 0U;
    idp->tx_busy           = I2S_TX_READY;
    idp->rx_buf            = NULL;
    idp->rx_len            = 0U;
    idp->rx_busy           = I2S_RX_READY;
    idp->prio              = IRQ_MIN_PRIORITY;
    idp->drv_mode          = I2S_DRV_MODE_SYNCHRONOUS;
    idp->dma_mode          = I2S_DMA_OFF;
    idp->dma_conf          = NULL;
    idp->dma_rx_descriptor = NULL;
    idp->dma_tx_descriptor = NULL;
    idp->mode              = I2S_MODE_SLAVE_TX;
    idp->standard          = I2S_STANDARD_PHILIPS;
    idp->chlen             = I2S_CHANNEL_LENGTH_16B;
    idp->datalen           = I2S_DATA_LENGTH_16B;
    idp->ckpol             = I2S_CLOCK_POLARITY_LOW;
    idp->mckout            = I2S_MASTER_CLOCK_OUTPUT_DISABLE;
    idp->audiofreq         = I2S_AUDIO_FREQUENCY_DEFAULT;

    for (i = 0U; i < (uint8_t)I2S_CB_OPS_MAX; i++) {
        idp->cb[i] = NULL;
    }
}

/**
 * @brief   DMA TX Interrupt handler.
 *
 * @param[in] arg       argument associated to the callback
 * @param[in] sts       DMA callback cause status flags
 *
 * @isr
 */
static void i2s_serve_dma_tx_interrupt(void *arg, uint32_t sts) {

    /*lint -e9087 */
    i2s_driver_t *idp = (i2s_driver_t *)arg;
    /*lint +e9087 */

    /* Checking for errors.*/
    if ((sts & DMA_STS_TEIF) != 0U) {
        if (idp->cb[I2S_CB_OPS_ERR] != NULL) {
            /* DMA critical error.*/
            idp->cb[I2S_CB_OPS_ERR](idp);
        }
    }
    else {
        /* Trasmission completed.*/
        if ((sts & DMA_STS_TCIF) != 0U) {
            if (idp->cb[I2S_CB_OPS_TX] != NULL) {
                idp->cb[I2S_CB_OPS_TX](idp);
            } else {
                ; /* close "if" as required by MISRA */
            }
        } else {
            ; /* close "if" as required by MISRA */
        }
    }

    I2S_TX_DONE(idp);
}

/**
 * @brief   DMA RX Interrupt handler.
 *
 * @param[in] arg       argument associated to the callback
 * @param[in] sts       DMA callback cause status flags
 *
 * @isr
 */
static void i2s_serve_dma_rx_interrupt(void *arg, uint32_t sts) {

    /*lint -e9087 */
    i2s_driver_t *idp = (i2s_driver_t *)arg;
    /*lint +e9087 */

    /* Checking for errors.*/
    if ((sts & DMA_STS_TEIF) != 0U) {
        if (idp->cb[I2S_CB_OPS_ERR] != NULL) {
            /* DMA critical error.*/
            idp->cb[I2S_CB_OPS_ERR](idp);
        }
    }
    else {
        /* Reception completed.*/
        if ((sts & DMA_STS_TCIF) != 0U) {
            if (idp->cb[I2S_CB_OPS_RX] != NULL) {
                idp->cb[I2S_CB_OPS_RX](idp);
            } else {
                ; /* close "if" as required by MISRA */
            }
        } else {
            ; /* close "if" as required by MISRA */
        }
    }

    I2S_RX_DONE(idp);
}

/**
 * @brief   Sends frames via I2S without DMA
 *
 * @param[out] idp      pointer to a @p i2s_driver_t structure
 *
 * @notapi
 */
static void i2s_lld_send(i2s_driver_t *idp) {

    /* Enable transmission buffer empty interrupt and error interrupt.*/
    idp->i2s->CR2 |= SPI_CR2_TXEIE | SPI_CR2_ERRIE;
}

/**
 * @brief   Receives frames from I2S without DMA.
 *
 * @param[out] idp      pointer to a @p i2s_driver_t structure
 *
 * @notapi
 */
static void i2s_lld_receive(i2s_driver_t *idp) {

    /* Enable receive buffer not empty interrupt and error interrupt.*/
    idp->i2s->CR2 |= SPI_CR2_RXNEIE | SPI_CR2_ERRIE;
}

/**
 * @brief   Sends frames via I2S with DMA
 *
 * @param[out] idp      pointer to a @p i2s_driver_t structure
 *
 * @notapi
 */
static void i2s_dma_lld_send(i2s_driver_t *idp) {

    /* Configure DMA TX number of data items.*/
    dma_stream_set_count(idp->dma_tx_descriptor, (uint32_t)(idp->tx_len));

    /* Configure DMA TX stream memory address.*/
    dma_stream_set_memory(idp->dma_tx_descriptor, (uint32_t)(idp->tx_buf));

    /* Enable DMA TX. It will be disabled on the DMA end of transfer.*/
    dma_stream_enable(idp->dma_tx_descriptor);
}

/**
 * @brief   Receives frames from I2S with DMA.
 *
 * @param[out] idp      pointer to a @p i2s_driver_t structure
 *
 * @notapi
 */
static void i2s_dma_lld_receive(i2s_driver_t *idp) {

    /* Configure DMA RX number of data items.*/
    dma_stream_set_count(idp->dma_rx_descriptor, (uint32_t)(idp->rx_len));

    /* Configure DMA RX stream memory address.*/
    dma_stream_set_memory(idp->dma_rx_descriptor, (uint32_t)(idp->rx_buf));

    /* Enable DMA RX. It will be disabled on the DMA end of transfer.*/
    dma_stream_enable(idp->dma_rx_descriptor);
}

/*===========================================================================*/
/* Module exported functions.                                                */
/*===========================================================================*/

void i2s_init(i2s_driver_t *idp) {

    /* Set pointer to I2S register block.*/
    idp->i2s  = i2s_dev_get_reg_ptr(idp);
    /* Set I2S clock value based on clocktree configuration.*/
    idp->clock = i2s_dev_get_clock(idp);

    /* Reset I2S parameters.*/
    i2s_reset_paramters(idp);
}

uint32_t i2s_set_prio(i2s_driver_t *idp, uint32_t prio) {

    uint32_t prev_prio;

    prev_prio = idp->prio;
    idp->prio = prio;

    return prev_prio;
}

i2s_drv_mode_t i2s_set_drv_mode(i2s_driver_t *idp, i2s_drv_mode_t drv_mode) {

    i2s_drv_mode_t prev_drv_mode;

    prev_drv_mode = idp->drv_mode;
    idp->drv_mode = drv_mode;

    return prev_drv_mode;
}

i2s_dma_mode_t i2s_set_dma_mode(i2s_driver_t *idp, i2s_dma_mode_t dma_mode) {

    i2s_dma_mode_t prev_dma_mode;

    prev_dma_mode = idp->dma_mode;
    idp->dma_mode = dma_mode;

    return prev_dma_mode;
}

i2s_dma_conf_t *i2s_set_dma_conf(i2s_driver_t *idp,
                                 i2s_dma_conf_t *dma_conf) {

    i2s_dma_conf_t *prev_dma_conf;

    prev_dma_conf = idp->dma_conf;
    idp->dma_conf = dma_conf;

    return prev_dma_conf;
}

i2s_mode_t i2s_set_mode(i2s_driver_t *idp, i2s_mode_t mode) {

    i2s_mode_t prev_mode;

    prev_mode = idp->mode;
    idp->mode = mode;

    return prev_mode;
}

i2s_standard_t i2s_set_standard(i2s_driver_t *idp, i2s_standard_t standard) {

    i2s_standard_t prev_standard;

    prev_standard = idp->standard;
    idp->standard = standard;

    return prev_standard;
}

i2s_chlen_t i2s_set_chlen(i2s_driver_t *idp, i2s_chlen_t chlen) {

    i2s_chlen_t prev_chlen;

    prev_chlen = idp->chlen;
    idp->chlen = chlen;

    return prev_chlen;
}

i2s_datalen_t i2s_set_datalen(i2s_driver_t *idp, i2s_datalen_t datalen) {

    i2s_datalen_t prev_datalen;

    prev_datalen = idp->datalen;
    idp->datalen = datalen;

    return prev_datalen;
}

i2s_ckpol_t i2s_set_ckpol(i2s_driver_t *idp, i2s_ckpol_t ckpol) {

    i2s_ckpol_t prev_ckpol;

    prev_ckpol = idp->ckpol;
    idp->ckpol = ckpol;

    return prev_ckpol;
}

i2s_mckout_t i2s_set_mckout(i2s_driver_t *idp, i2s_mckout_t mckout) {

    i2s_mckout_t prev_mckout;

    prev_mckout = idp->mckout;
    idp->mckout = mckout;

    return prev_mckout;
}

i2s_audiofreq_t i2s_set_audiofreq(i2s_driver_t *idp, i2s_audiofreq_t audiofreq) {

    i2s_audiofreq_t prev_audiofreq;

    prev_audiofreq = idp->audiofreq;
    idp->audiofreq = audiofreq;

    return prev_audiofreq;
}

i2s_cb_t i2s_set_cb(i2s_driver_t *idp, i2s_cb_ops_t cb_op, i2s_cb_t cb) {

    i2s_cb_t prev_cb;

    prev_cb = idp->cb[cb_op];
    idp->cb[cb_op] = cb;

    return prev_cb;
}

void i2s_start(i2s_driver_t *idp) {

    uint32_t cfgr;
    i2s_pcmsync_t pcmsync;
    i2s_standard_t standard;
    i2s_chlen_t chlen;
    uint32_t psc = 0UL;
    uint8_t odd, div;
    IRQn_Type vector;
    uint32_t dma_tx_mode, dma_rx_mode;
    uint32_t dma_tx_trigger, dma_rx_trigger;

    /* Enable clock.*/
    i2s_dev_clock_enable(idp);

    /* Set PCM frame synchronization based on the selected I2S standard.*/
    if (idp->standard == I2S_STANDARD_PCM_LONG) {
        standard = I2S_STANDARD_PCM_SHORT;
        pcmsync = I2S_PCM_SYNCHRO_LONG;
    } else {
        standard = idp->standard;
        pcmsync = I2S_PCM_SYNCHRO_SHORT;
    }

    /* If data length is greater then 16-bit, channel length is fixed to
       32-bit.*/
    if (idp->datalen != I2S_DATA_LENGTH_16B) {
        chlen = I2S_CHANNEL_LENGTH_32B;
    } else {
        chlen = idp->chlen;
    }

    cfgr = (((uint32_t)chlen        << SPI_I2SCFGR_CHLEN_Pos)   |
            ((uint32_t)idp->datalen << SPI_I2SCFGR_DATLEN_Pos)  |
            ((uint32_t)idp->ckpol   << SPI_I2SCFGR_CKPOL_Pos)   |
            ((uint32_t)standard     << SPI_I2SCFGR_I2SSTD_Pos)  |
            ((uint32_t)pcmsync      << SPI_I2SCFGR_PCMSYNC_Pos) |
            ((uint32_t)idp->mode    << SPI_I2SCFGR_I2SCFG_Pos));

    /*
    if(idp->standard == I2S_STANDARD_PCM_SHORT ||
       idp->standard == I2S_STANDARD_PCM_LONG) {
        cfgr = cfgr | SPI_I2SCFGR_ASTRTEN;
    }
    */

    /* Calculate clock prescaler. Calculation is rounded to integer.*/
    switch(idp->standard) {
        case I2S_STANDARD_PHILIPS:
        case I2S_STANDARD_MSB:
        case I2S_STANDARD_LSB:
            if (idp->mckout == I2S_MASTER_CLOCK_OUTPUT_ENABLE) {
                psc = (idp->clock * 10U) / (256U * ((uint32_t)idp->audiofreq)) + 5U;
            } else {
                psc = (idp->clock * 10U) / (32U * (((uint32_t)chlen) + 1U) * ((uint32_t)idp->audiofreq)) + 5U;
            }
            break;
        case I2S_STANDARD_PCM_SHORT:
        case I2S_STANDARD_PCM_LONG:
            if (idp->mckout == I2S_MASTER_CLOCK_OUTPUT_ENABLE) {
                psc = (idp->clock * 10U) / (128U * ((uint32_t)idp->audiofreq)) + 5U;
            } else {
                psc = (idp->clock * 10U) / (16U * (((uint32_t)chlen) + 1U) * ((uint32_t)idp->audiofreq)) + 5U;
            }
            break;
        default:
            /* dummy comment as required by MISRA */
            break;
    }
    psc = psc / 10U;

    /* Calculate odd factor for the prescaler.*/
    odd = (uint8_t)(psc & 1U);
    /* Calculate linear prescaler.*/
    div = (uint8_t)((psc - odd) / 2U);

    /* Set I2S prescaler.*/
    idp->i2s->I2SPR = (((uint32_t)idp->mckout << SPI_I2SPR_MCKOE_Pos)  |
                       ((uint32_t)odd         << SPI_I2SPR_ODD_Pos)    |
                       ((uint32_t)div         << SPI_I2SPR_I2SDIV_Pos));

    /* If DMA is disabled, configure I2S interrupt...*/
    if (idp->dma_mode != I2S_DMA_ON) {
        vector = i2s_dev_get_vector(idp);
        irq_set_priority(vector, idp->prio);
        irq_enable(vector);
    /* ...otherwise, configure DMA.*/
    } else {
        if ((idp->mode == I2S_MODE_SLAVE_TX) || (idp->mode == I2S_MODE_MASTER_TX)) {
            /* Allocates DMA streams for I2S transmission.*/
            /*lint -e9087 */
            idp->dma_tx_descriptor = dma_stream_take(idp->dma_conf->dma_stream_tx_id,
                                                     idp->dma_conf->dma_stream_irq_prio,
                                                     i2s_serve_dma_tx_interrupt,
                                                     (void *)idp);
            /*lint +e9087 */

            /* Configure DMA stream peripheral addresses.*/
            dma_stream_set_peripheral(idp->dma_tx_descriptor, (uint32_t)(&idp->i2s->DR));

            /* Configure DMA TX triggers.*/
            dma_tx_trigger = i2s_dev_get_dma_tx_trigger(idp);
            dma_stream_set_trigger(idp->dma_tx_descriptor, dma_tx_trigger);

            /* Configure DMA priority level, data transfer direction and enable
               transfer complete and transfer error interrupts.*/
            dma_tx_mode = DMA_CCR_PL_VALUE(idp->dma_conf->dma_stream_bus_prio) |
                          DMA_CCR_DIR_M2P | DMA_CCR_TCIE | DMA_CCR_TEIE;

            /* Configure DMA memory increment mode.*/
            dma_tx_mode |= DMA_CCR_MINC;

            /* Configure DMA frame size.*/
            dma_tx_mode |= DMA_CCR_PSIZE_HWORD | DMA_CCR_MSIZE_HWORD;

            /* Set up calculated DMA mode.*/
            dma_stream_set_transfer_mode(idp->dma_tx_descriptor, dma_tx_mode);

            /* TX buffer DMA enable.*/
            idp->i2s->CR2 |= (SPI_CR2_TXDMAEN);
        } else {
            /* Allocates DMA streams for I2S reception.*/
            /*lint -e9087 */
            idp->dma_rx_descriptor = dma_stream_take(idp->dma_conf->dma_stream_rx_id,
                                                     idp->dma_conf->dma_stream_irq_prio,
                                                     i2s_serve_dma_rx_interrupt,
                                                     (void *)idp);
            /*lint +e9087 */

            /* Configure DMA stream peripheral addresses.*/
            dma_stream_set_peripheral(idp->dma_rx_descriptor, (uint32_t)(&idp->i2s->DR));

            /* Configure DMA RX triggers.*/
            dma_rx_trigger = i2s_dev_get_dma_rx_trigger(idp);
            dma_stream_set_trigger(idp->dma_rx_descriptor, dma_rx_trigger);

            /* Configure DMA priority level, data transfer direction and enable
               transfer complete and transfer error interrupts.*/
            dma_rx_mode = DMA_CCR_PL_VALUE(idp->dma_conf->dma_stream_bus_prio) |
                          DMA_CCR_DIR_P2M | DMA_CCR_TCIE | DMA_CCR_TEIE;

            /* Configure DMA memory increment mode.*/
            dma_rx_mode |= DMA_CCR_MINC;

            /* Configure DMA frame size.*/
            dma_rx_mode |= DMA_CCR_PSIZE_HWORD | DMA_CCR_MSIZE_HWORD;

            /* Set up calculated DMA mode.*/
            dma_stream_set_transfer_mode(idp->dma_rx_descriptor, dma_rx_mode);

            /* RX buffer DMA enable.*/
            idp->i2s->CR2 |= (SPI_CR2_RXDMAEN);
        }
    }

    /* Setting up and starting I2S.*/
    idp->i2s->I2SCFGR = cfgr | SPI_I2SCFGR_I2SMOD | SPI_I2SCFGR_I2SE;
}

uint16_t i2s_send(i2s_driver_t *idp, uint16_t *data, uint16_t len) {

    if (len > 0U) {
        I2S_TX_IN_PROGRESS(idp);

        idp->tx_buf = data;

        if (idp->datalen == I2S_DATA_LENGTH_24B ||
            idp->datalen == I2S_DATA_LENGTH_32B) {
            idp->tx_len = (uint16_t)(len * 2U);
        } else {
            idp->tx_len = len;
        }

        if (idp->dma_mode == I2S_DMA_ON) {
            i2s_dma_lld_send(idp);
        } else {
            i2s_lld_send(idp);
        }

        /* Wait for completion */
        I2S_WAIT_FOR_TX_COMPLETION(idp);
    }

    return len;
}

uint16_t i2s_receive(i2s_driver_t *idp, uint16_t *data, uint16_t len) {

    if (len > 0UL) {
        I2S_RX_IN_PROGRESS(idp);

        idp->rx_buf = data;

        if (idp->datalen == I2S_DATA_LENGTH_24B ||
            idp->datalen == I2S_DATA_LENGTH_32B) {
            idp->rx_len = (uint16_t)(len * 2U);
        } else {
            idp->rx_len = len;
        }

        if (idp->dma_mode == I2S_DMA_ON) {
            i2s_dma_lld_receive(idp);
        } else {
            i2s_lld_receive(idp);
        }

        /* Wait for completion */
        I2S_WAIT_FOR_RX_COMPLETION(idp);
    }

    return len;
}

void i2s_stop(i2s_driver_t *idp) {

    IRQn_Type vector;

    /* If DMA is disabled, disable I2S interrupt...*/
    if (idp->dma_mode != I2S_DMA_ON) {
        vector = i2s_dev_get_vector(idp);
        irq_disable(vector);
    /* ...otherwise, disable DMA TX/RX streams.*/
    } else {
        /* Free and stop DMA TX stream.*/
        dma_stream_free(idp->dma_tx_descriptor);
        dma_stream_disable(idp->dma_tx_descriptor);
        /* Free and stop DMA RX stream.*/
        dma_stream_free(idp->dma_rx_descriptor);
        dma_stream_disable(idp->dma_rx_descriptor);
    }

    /* Stop procedure. Set all registers to default values.*/
    idp->i2s->CR1     = 0x0U;
    idp->i2s->CR2     = 0x700U;
    idp->i2s->I2SCFGR = 0x0U;
    idp->i2s->I2SPR   = 0x2U;

    /* Disable clock.*/
    i2s_dev_clock_disable(idp);
}

void i2s_deinit(i2s_driver_t *idp) {

    /* Set pointer to I2S register block to NULL.*/
    idp->i2s  = NULL;
    /* Set I2S clock value to default value.*/
    idp->clock = 0UL;

    /* Reset I2S parameters.*/
    i2s_reset_paramters(idp);
}

void __i2s_serve_interrupt(i2s_driver_t *idp) {

    uint32_t sr, cr2;

    sr  = idp->i2s->SR;
    cr2 = idp->i2s->CR2;

    /* RX buffer not empty condition.*/
    if (((sr & SPI_SR_OVR) == 0U) &&
        ((sr & SPI_SR_RXNE) != 0U) &&
        ((cr2 & SPI_CR2_RXNEIE) != 0U)) {
        if (idp->rx_buf != NULL) {
            *idp->rx_buf++ = (uint16_t)(idp->i2s->DR);
            idp->rx_len--;
            /* Reception completed.*/
            if (idp->rx_len == 0U) {
                /* Disable receive buffer not empty interrupt and error
                   interrupt.*/
                idp->i2s->CR2 &= ~(SPI_CR2_RXNEIE | SPI_CR2_ERRIE);

                /* If RX complete callback is defined, it is invoked.*/
                if (idp->cb[I2S_CB_OPS_RX] != NULL) {
                    idp->cb[I2S_CB_OPS_RX](idp);
                }

                I2S_RX_DONE(idp);
	        }
        }
    }

    /* TX buffer empty condition.*/
    if (((sr & SPI_SR_UDR) == 0U) &&
        ((sr & SPI_SR_TXE) != 0U) &&
        ((cr2 & SPI_CR2_TXEIE) != 0U)) {
        if (idp->tx_buf != NULL) {
            idp->i2s->DR = *idp->tx_buf++;
            idp->tx_len--;
            /* Trasmission completed.*/
            if (idp->tx_len == 0U) {
                /* Disable transmission buffer empty interrupt and error
                   interrupt.*/
                idp->i2s->CR2 &= ~(SPI_CR2_TXEIE | SPI_CR2_ERRIE);

                /* If TX complete callback is defined, it is invoked.*/
                if (idp->cb[I2S_CB_OPS_TX] != NULL) {
                    idp->cb[I2S_CB_OPS_TX](idp);
                }

                I2S_TX_DONE(idp);
            }
        }
    }

#if 0
    /* TODO: Add Error type.*/
    if ((cr2 & SPI_CR2_ERRIE) != 0U) {
        /* Overrun error.*/
        if ((sr & SPI_SR_OVR) != 0U) {
            /* Disable receive buffer not empty interrupt and error
               interrupt.*/
            idp->i2s->CR2 &= ~(SPI_CR2_RXNEIE | SPI_CR2_ERRIE);

            /* If Error callback is defined, it is invoked.*/
            if (idp->cb[I2S_CB_OPS_ERR] != NULL) {
                idp->cb[I2S_CB_OPS_ERR](idp);
            }
        }

        /* Underrun error.*/
        if ((sr & SPI_SR_UDR) != 0U) {
            /* Disable transmission buffer empty interrupt and error
               interrupt.*/
            idp->i2s->CR2 &= ~(SPI_CR2_TXEIE | SPI_CR2_ERRIE);

            /* If Error callback is defined, it is invoked.*/
            if (idp->cb[I2S_CB_OPS_ERR] != NULL) {
                idp->cb[I2S_CB_OPS_ERR](idp);
            }
        }

        I2S_TX_DONE(idp);
    }
#endif
}

/** @} */
