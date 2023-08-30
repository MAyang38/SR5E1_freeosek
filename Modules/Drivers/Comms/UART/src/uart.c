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
 * @file    uart.c
 * @brief   UART driver source file.
 *
 * @addtogroup DRIVERS
 * @addtogroup COMMS
 * @ingroup DRIVERS
 * @addtogroup UART
 * @ingroup COMMS
 * @{
 */

#include <uart.h>
#include <uart_private.h>

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
 * @note    Called when UART driver enters transmit mode.
 *
 * @param[in] \_udp\_   pointer to a @p uart_driver_t structure
 *
 * @notapi
 */
#define UART_TX_IN_PROGRESS(_udp_)                                  \
    (_udp_)->tx_busy = UART_TX_BUSY

/**
 * @brief  Exits from transmit mode.
 * @note   Called when UART driver exits transmit mode.
 *
 * @param[in] \_udp\_   pointer to a @p uart_driver_t structure
 *
 * @notapi
 */
#define UART_TX_DONE(_udp_)                                         \
    (_udp_)->tx_busy = UART_TX_READY

/**
 * @brief  Waits for transmit end.
 * @note   Called to wait for end of transmit.
 *
 * @param[in] \_udp\_   pointer to a @p uart_driver_t structure
  *
 * @notapi
 */
#define UART_WAIT_FOR_TX_COMPLETION(_udp_)                          \
    if (((_udp_)->tx_drv_mode == UART_TX_DRV_MODE_INT_SYNC) ||      \
        ((_udp_)->tx_drv_mode == UART_TX_DRV_MODE_DMA_SYNC)) {      \
        while ((_udp_)->tx_busy == UART_TX_BUSY) {;}                \
    }

/**
 * @brief   Enters in receiving mode.
 * @note    Called when UART driver enters receiving mode.
 *
 * @param[in] \_udp\_   pointer to a @p uart_driver_t structure
 *
 * @notapi
 */
#define UART_RX_IN_PROGRESS(_udp_)                                  \
    (_udp_)->rx_busy = UART_RX_BUSY

/**
 * @brief   Exits from receiving mode.
 * @note    Called when UART driver exits receiving mode.
 *
 * @param[in] \_udp\_   pointer to a @p uart_driver_t structure
 *
 * @notapi
 */
#define UART_RX_DONE(_udp_)                                         \
    (_udp_)->rx_busy = UART_RX_READY

/**
 * @brief   Waits for receive end.
 * @note    Called to wait for end of receiving mode.
 *
 * @param[in] \_udp\_   pointer to a @p uart_driver_t structure
 *
 * @notapi
 */
#define UART_WAIT_FOR_RX_COMPLETION(_udp_)                          \
    if (((_udp_)->rx_drv_mode == UART_RX_DRV_MODE_INT_SYNC) ||      \
        ((_udp_)->rx_drv_mode == UART_RX_DRV_MODE_DMA_SYNC) ||      \
        ((_udp_)->rx_drv_mode == UART_RX_DRV_MODE_INT_BUFF_SYNC)) { \
        while ((_udp_)->rx_busy == UART_RX_BUSY) {;}                \
    }

/**
 * @brief   Resets UART parameters.
 *
 * @param[out] udp      pointer to an @p uart_driver_t structure
 *
 * @notapi
 */
static void uart_reset_paramters(uart_driver_t *udp) {

    uint8_t i;

    /* Set all driver configuration parameters to default values.*/
    udp->tx_buf            = NULL;
    udp->tx_len            = 0U;
    udp->tx_busy           = UART_TX_READY;
    udp->rx_buf            = NULL;
    udp->rx_len            = 0U;
    udp->rx_busy           = UART_RX_READY;
    udp->prio              = IRQ_MIN_PRIORITY;
    udp->rx_drv_mode       = UART_RX_DRV_MODE_INT_SYNC;
    udp->tx_drv_mode       = UART_TX_DRV_MODE_INT_SYNC;
    udp->is_fifo_en        = false;
    udp->rxft              = UART_RX_FIFO_THR_1_8;
    udp->txft              = UART_TX_FIFO_THR_1_8;
    udp->rx_fifo_full      = 0U;
    udp->tx_fifo_empty     = 0U;
    udp->dma_conf          = NULL;
    udp->dma_rx_descriptor = NULL;
    udp->dma_tx_descriptor = NULL;
    udp->baud              = UART_BAUDRATE_38400;
    udp->presc             = UART_PRESCALER_DIV1;
    udp->parity            = UART_PARITY_NONE;
    udp->os                = UART_OVERSAMPLING_16;
    udp->sbit              = UART_STOPBIT_1;
    udp->sbrx_buf          = NULL;
    udp->sbrx_size         = 0U;
    udp->sbrx_wr_ptr       = NULL;
    udp->sbrx_rd_ptr       = NULL;
    udp->sbrx_end_ptr      = NULL;

    for (i = 0U; i < (uint8_t)UART_CB_OPS_MAX; i++) {
        udp->cb[i] = NULL;
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
static void uart_serve_dma_tx_interrupt(void *arg, uint32_t sts) {

    /*lint -e9087 */
    uart_driver_t *udp = (uart_driver_t *)arg;
    /*lint +e9087 */

    /* Checking for errors.*/
    if ((sts & DMA_STS_TEIF) != 0U) {
        if (udp->cb[UART_CB_OPS_ERR] != NULL) {
            /* DMA critical error.*/
            udp->cb[UART_CB_OPS_ERR](udp);
        }
    }
    else {
        /* Trasmission completed.*/
        if ((sts & DMA_STS_TCIF) != 0U) {
            if (udp->cb[UART_CB_OPS_TX] != NULL) {
                udp->cb[UART_CB_OPS_TX](udp);
            } else {
                ; /* close "if" as required by MISRA */
            }
        } else {
            ; /* close "if" as required by MISRA */
        }
    }

    UART_TX_DONE(udp);
}

/**
 * @brief   DMA RX Interrupt handler.
 *
 * @param[in] arg       argument associated to the callback
 * @param[in] sts       DMA callback cause status flags
 *
 * @isr
 */
static void uart_serve_dma_rx_interrupt(void *arg, uint32_t sts) {

    /*lint -e9087 */
    uart_driver_t *udp = (uart_driver_t *)arg;
    /*lint +e9087 */

    /* Checking for errors.*/
    if ((sts & DMA_STS_TEIF) != 0U) {
        if (udp->cb[UART_CB_OPS_ERR] != NULL) {
            /* DMA critical error.*/
            udp->cb[UART_CB_OPS_ERR](udp);
        }
    }
    else {
        /* Receiving completed.*/
        if ((sts & DMA_STS_TCIF) != 0U) {
            if (udp->cb[UART_CB_OPS_RX] != NULL) {
                udp->cb[UART_CB_OPS_RX](udp);
            } else {
                ; /* close "if" as required by MISRA */
            }
        } else {
            ; /* close "if" as required by MISRA */
        }
    }

    UART_RX_DONE(udp);
}

/**
 * @brief   Writes frames via UART without DMA.
 *
 * @param[out] udp      pointer to a @p uart_driver_t structure
 *
 * @notapi
 */
static void uart_lld_write(uart_driver_t *udp) {

    /* Start transmission of the first byte.*/
    udp->uart->TDR = (uint32_t)(*udp->tx_buf++);
    udp->tx_len--;

    /* Enable transmission complete interrupt.*/
    udp->uart->CR1 |= UART_CR1_TCIE;
}

/**
 * @brief   Reads frames from UART without DMA.
 *
 * @param[out] udp      pointer to a @p uart_driver_t structure
 *
 * @notapi
 */
static void uart_lld_read(uart_driver_t *udp) {

    uint32_t len = udp->rx_len;

    if (udp->rx_drv_mode == UART_RX_DRV_MODE_INT_BUFF_SYNC) {
        /* Disable data receive interrupt and check if there are bytes
           available in the Synchronous Buffered mode buffer.*/
        udp->uart->CR1 &= ~UART_CR1_RXNEIE_RXFNEIE;
        /* Wait till all required bytes are read from the Synchronous Buffered
           mode buffer.*/
        while (len != 0U) {
            /* If there are available bytes in the Synchronous Buffered mode
               buffer, keep data receive interrupt disable and read them ...*/
            if (udp->sbrx_rd_ptr != udp->sbrx_wr_ptr) {
                udp->uart->CR1 &= ~UART_CR1_RXNEIE_RXFNEIE;
                *udp->rx_buf++ = *udp->sbrx_rd_ptr++;
                if (udp->sbrx_rd_ptr == udp->sbrx_end_ptr) {
                    udp->sbrx_rd_ptr = udp->sbrx_buf;
                }
                len--;
            /* ... otherwise re-enable data receive interrupt.*/
            } else {
                udp->uart->CR1 |= UART_CR1_RXNEIE_RXFNEIE;
            }
        }
        UART_RX_DONE(udp);
        /* Exit from the current read operation with data receive interrupt
           enabled. In this way new data will be stored in the Synchronous
           Buffered mode buffer and will be not lost.*/
        udp->uart->CR1 |= UART_CR1_RXNEIE_RXFNEIE;
    } else {
        /* Enable data receive interrupt.*/
        udp->uart->CR1 |= UART_CR1_RXNEIE_RXFNEIE;
    }
}

/**
 * @brief   Writes frames via UART using FIFO.
 *
 * @param[out] udp      pointer to a @p uart_driver_t structure
 *
 * @notapi
 */
static void uart_fifo_lld_write(uart_driver_t *udp) {

    /* Enable TXFIFO threshold interrupt.*/
    udp->uart->CR3 |= UART_CR3_TXFTIE;
}

/**
 * @brief   Reads frames from UART using FIFO.
 *
 * @param[out] udp      pointer to a @p uart_driver_t structure
 *
 * @notapi
 */
static void uart_fifo_lld_read(uart_driver_t *udp) {

    /* Enable RXFIFO threshold interrupt.*/
    udp->uart->CR3 |= UART_CR3_RXFTIE;
}

/**
 * @brief   Writes frames via UART with DMA.
 *
 * @param[out] udp      pointer to a @p uart_driver_t structure
 *
 * @notapi
 */
static void uart_dma_lld_write(uart_driver_t *udp) {

    /* Configure DMA TX number of data items.*/
    dma_stream_set_count(udp->dma_tx_descriptor, (uint32_t)(udp->tx_len));

    /* Configure DMA TX stream memory address.*/
    dma_stream_set_memory(udp->dma_tx_descriptor, (uint32_t)(udp->tx_buf));

    /* Enable DMA TX. It will be disabled on the DMA end of transfer.*/
    dma_stream_enable(udp->dma_tx_descriptor);
}

/**
 * @brief   Reads frames from UART with DMA.
 *
 * @param[out] udp      pointer to a @p uart_driver_t structure
 *
 * @notapi
 */
static void uart_dma_lld_read(uart_driver_t *udp) {

    /* Configure DMA RX number of data items.*/
    dma_stream_set_count(udp->dma_rx_descriptor, (uint32_t)(udp->rx_len));

    /* Configure DMA RX stream memory address.*/
    dma_stream_set_memory(udp->dma_rx_descriptor, (uint32_t)(udp->rx_buf));

    /* Enable DMA RX. It will be disabled on the DMA end of transfer.*/
    dma_stream_enable(udp->dma_rx_descriptor);
}

/**
 * @brief   Returns the number of elements available in the RX FIFO that can be
 *          read.
 *
 * @param[out] udp      pointer to a @p uart_driver_t structure
 * @return              number of elements available in the TX FIFO.
 *
 * @notapi
 */
static uint8_t uart_get_full_rx_fifo(uart_driver_t *udp) {

    switch (udp->rxft) {
        case UART_RX_FIFO_THR_1_8:
            return 1U;
        case UART_RX_FIFO_THR_1_4:
            return 2U;
        case UART_RX_FIFO_THR_1_2:
            return 4U;
        case UART_RX_FIFO_THR_3_4:
            return 6U;
        case UART_RX_FIFO_THR_7_8:
            return 7U;
        case UART_RX_FIFO_THR_FULL:
        default:
            return 8U;
	}
}

/**
 * @brief   Returns the number of free elements in the RX FIFO that can be
 *          write.
 *
 * @param[out] udp      pointer to a @p uart_driver_t structure
 * @return              number of free elements in the RX FIFO.
 *
 * @notapi
 */
static uint8_t uart_get_empty_tx_fifo(uart_driver_t *udp) {

    switch (udp->txft) {
        case UART_TX_FIFO_THR_1_8:
            return 1U;
        case UART_TX_FIFO_THR_1_4:
            return 2U;
        case UART_TX_FIFO_THR_1_2:
            return 4U;
        case UART_TX_FIFO_THR_3_4:
            return 6U;
        case UART_TX_FIFO_THR_7_8:
            return 7U;
        case UART_TX_FIFO_THR_EMPTY:
        default:
            return 8U;
    }
}

/*===========================================================================*/
/* Module exported functions.                                                */
/*===========================================================================*/

void uart_init(uart_driver_t *udp) {

    /* Set pointer to UART register block.*/
    udp->uart  = uart_dev_get_reg_ptr(udp);
    /* Set UART clock value based on clocktree configuration.*/
    udp->clock = uart_dev_get_clock(udp);

    /* Reset UART parameters.*/
    uart_reset_paramters(udp);
}

uint32_t uart_set_prio(uart_driver_t *udp, uint32_t prio) {

    uint32_t prev_prio;

    prev_prio = udp->prio;
    udp->prio = prio;

    return prev_prio;
}

uart_rx_drv_mode_t uart_set_rx_drv_mode(uart_driver_t *udp,
                                        uart_rx_drv_mode_t rx_drv_mode) {

    uart_rx_drv_mode_t prev_rx_drv_mode;

    prev_rx_drv_mode = udp->rx_drv_mode;
    udp->rx_drv_mode = rx_drv_mode;

    return prev_rx_drv_mode;
}

uart_tx_drv_mode_t uart_set_tx_drv_mode(uart_driver_t *udp,
                                        uart_tx_drv_mode_t tx_drv_mode) {

    uart_tx_drv_mode_t prev_tx_drv_mode;

    prev_tx_drv_mode = udp->tx_drv_mode;
    udp->tx_drv_mode = tx_drv_mode;

    return prev_tx_drv_mode;
}

bool uart_set_fifo_enable(uart_driver_t *udp, bool enable) {

    bool prev_is_fifo_en;

    prev_is_fifo_en = udp->is_fifo_en;
    udp->is_fifo_en = enable;

    return prev_is_fifo_en;
}

void uart_set_fifo_threshold(uart_driver_t *udp, uart_rx_fifo_thr_t rxft,
                             uart_tx_fifo_thr_t txft) {

    udp->rxft = rxft;
    udp->txft = txft;

    /* Calculate emtpy FIFO size based on FIFO threshold configurations.*/
	udp->rx_fifo_full = uart_get_full_rx_fifo(udp);
	udp->tx_fifo_empty = uart_get_empty_tx_fifo(udp);
}

uart_dma_conf_t *uart_set_dma_conf(uart_driver_t *udp,
                                   uart_dma_conf_t *dma_conf) {

    uart_dma_conf_t *prev_dma_conf;

    prev_dma_conf = udp->dma_conf;
    udp->dma_conf = dma_conf;

    return prev_dma_conf;
}

uart_baud_t uart_set_baud(uart_driver_t *udp, uart_baud_t baud) {

    uart_baud_t prev_baud;

    prev_baud = udp->baud;
    udp->baud = baud;

    return prev_baud;
}

uart_presc_t uart_set_presc(uart_driver_t *udp, uart_presc_t presc) {

    uart_presc_t prev_presc;

    prev_presc = udp->presc;
    udp->presc = presc;

    return prev_presc;
}

uart_parity_t uart_set_parity(uart_driver_t *udp, uart_parity_t parity) {

    uart_parity_t prev_parity;

    prev_parity = udp->parity;
    udp->parity = parity;

    return prev_parity;
}

uart_over_t uart_set_over(uart_driver_t *udp, uart_over_t os) {

    uart_over_t prev_os;

    prev_os = udp->os;
    udp->os = os;

    return prev_os;
}

uart_sbit_t uart_set_sbit(uart_driver_t *udp, uart_sbit_t sbit) {

    uart_sbit_t prev_stopbit;

    prev_stopbit = udp->sbit;
    udp->sbit = sbit;

    return prev_stopbit;
}

void uart_set_sbrx_buf(uart_driver_t *udp, uint8_t *sbrx_buf, uint32_t sbrx_size) {

    udp->sbrx_buf = sbrx_buf;
    udp->sbrx_size = sbrx_size;
}

uart_cb_t uart_set_cb(uart_driver_t *udp, uart_cb_ops_t cb_op, uart_cb_t cb) {

    uart_cb_t prev_cb;

    prev_cb = udp->cb[cb_op];
    udp->cb[cb_op] = cb;

    return prev_cb;
}

void uart_start(uart_driver_t *udp) {

    uint32_t cr1 = 0U;
    uint32_t cr3 = 0U;
    uint32_t presc, brr;
    uint32_t dma_tx_mode, dma_rx_mode;

    IRQn_Type vector;
    uint32_t dma_tx_trigger, dma_rx_trigger;

    /* Enable clock.*/
    uart_dev_clock_enable(udp);

    /* BRR calculation.*/
    static const uint32_t prescvals[] = {1, 2, 4, 6, 8, 10, 12, 16, 32, 64, 128, 256};
    presc = prescvals[udp->presc];
    brr = (uint32_t)((udp->clock / presc) / ((uint32_t)udp->baud));

    /* Correcting BRR value when oversampling is 8.*/
    if (udp->os == UART_OVERSAMPLING_8) {
        brr = ((brr & ~7U) * 2U) | (brr & 7U);
    }

    /* Setting up and starting UART.*/
    udp->uart->BRR = brr;
    udp->uart->PRESC = (uint32_t)udp->presc;

    /* TODO: Set UART_CR1_PEIE to have an interrupt in case of parity error */

    /* Configure UART parity.*/
    if (udp->parity != UART_PARITY_NONE) {
        cr1 |= UART_CR1_PCE | UART_CR1_PEIE;
        if (udp->parity == UART_PARITY_ODD) {
            cr1 |= UART_CR1_PS;
        }
    }

    /* Configure UART oversampling.*/
    if(udp->os == UART_OVERSAMPLING_8) {
        cr1 |= UART_CR1_OVER8;
    }

    /* Configure UART FIFO.*/
    if (udp->is_fifo_en == true) {
        cr1 |= UART_CR1_FIFOEN;
        cr3 |= UART_CR3_RXFTCFG_Msk & ((uint32_t)udp->rxft << UART_CR3_RXFTCFG_Pos);
        cr3 |= UART_CR3_TXFTCFG_Msk & ((uint32_t)udp->txft << UART_CR3_TXFTCFG_Pos);
    }

    /* If interrupt mode is selected, configure UART interrupt.*/
    if ((udp->rx_drv_mode == UART_RX_DRV_MODE_INT_SYNC       ||
         udp->rx_drv_mode == UART_RX_DRV_MODE_INT_ASYNC      ||
         udp->rx_drv_mode == UART_RX_DRV_MODE_INT_BUFF_SYNC) ||
        (udp->tx_drv_mode == UART_TX_DRV_MODE_INT_SYNC       ||
         udp->tx_drv_mode == UART_TX_DRV_MODE_INT_ASYNC)) {
        vector = uart_dev_get_vector(udp);
        irq_set_priority(vector, udp->prio);
        irq_enable(vector);

        if (udp->rx_drv_mode == UART_RX_DRV_MODE_INT_BUFF_SYNC) {
            udp->sbrx_wr_ptr  = udp->sbrx_buf;
            udp->sbrx_rd_ptr  = udp->sbrx_buf;
            udp->sbrx_end_ptr = udp->sbrx_buf + udp->sbrx_size;
        }
    }

    /* If RX DMA mode is selected, configure RX DMA.*/
    if (udp->rx_drv_mode == UART_RX_DRV_MODE_DMA_SYNC       ||
        udp->rx_drv_mode == UART_RX_DRV_MODE_DMA_ASYNC) {
        /* Allocates DMA streams for UART transmission/reception.*/
        /*lint -e9087 */
        udp->dma_rx_descriptor = dma_stream_take(udp->dma_conf->dma_stream_rx_id,
                                                 udp->dma_conf->dma_stream_irq_prio,
                                                 uart_serve_dma_rx_interrupt,
                                                 (void *)udp);
        /*lint +e9087 */
	
        /* Configure DMA stream peripheral addresses.*/
        dma_stream_set_peripheral(udp->dma_rx_descriptor, (uint32_t)(&udp->uart->RDR));

        /* Configure DMA RX triggers.*/
        dma_rx_trigger = uart_dev_get_dma_rx_trigger(udp);
        dma_stream_set_trigger(udp->dma_rx_descriptor, dma_rx_trigger);

        /* Configure DMA priority level, data transfer direction and enable
           transfer complete interrupt.*/
        dma_rx_mode = DMA_CCR_PL_VALUE(udp->dma_conf->dma_stream_bus_prio) |
                      DMA_CCR_DIR_P2M | DMA_CCR_TCIE;

        /* Configure DMA memory increment mode.*/
        dma_rx_mode |= DMA_CCR_MINC;

        /* Configure DMA frame size.*/
        dma_rx_mode |= DMA_CCR_PSIZE_BYTE | DMA_CCR_MSIZE_BYTE;

        /* Set up calculated DMA modes.*/
        dma_stream_set_transfer_mode(udp->dma_rx_descriptor, dma_rx_mode);

        /* Enable DMA transmitter.*/
        cr3 |= UART_CR3_DMAR;
    }

    /* If TX DMA mode is selected, configure TX DMA.*/
    if (udp->tx_drv_mode == UART_TX_DRV_MODE_DMA_SYNC       ||
        udp->tx_drv_mode == UART_TX_DRV_MODE_DMA_ASYNC) {
        /* Allocates DMA streams for UART transmission/reception.*/
        /*lint -e9087 */
        udp->dma_tx_descriptor = dma_stream_take(udp->dma_conf->dma_stream_tx_id,
                                                 udp->dma_conf->dma_stream_irq_prio,
                                                 uart_serve_dma_tx_interrupt,
                                                 (void *)udp);
        /*lint +e9087 */

        /* Configure DMA stream peripheral addresses.*/
        dma_stream_set_peripheral(udp->dma_tx_descriptor, (uint32_t)(&udp->uart->TDR));

        /* Configure DMA TX/RX triggers.*/
        dma_tx_trigger = uart_dev_get_dma_tx_trigger(udp);
        dma_stream_set_trigger(udp->dma_tx_descriptor, dma_tx_trigger);

        /* Configure DMA priority level, data transfer direction and enable
           transfer complete interrupt.*/
        dma_tx_mode = DMA_CCR_PL_VALUE(udp->dma_conf->dma_stream_bus_prio) |
                      DMA_CCR_DIR_M2P | DMA_CCR_TCIE;

        /* Configure DMA memory increment mode.*/
        dma_tx_mode |= DMA_CCR_MINC;

        /* Configure DMA frame size.*/
        dma_tx_mode |= DMA_CCR_PSIZE_BYTE | DMA_CCR_MSIZE_BYTE;

        /* Set up calculated DMA modes.*/
        dma_stream_set_transfer_mode(udp->dma_tx_descriptor, dma_tx_mode);

        /* Enable DMA transmitter.*/
        cr3 |= UART_CR3_DMAT;
    }

    /* Setting up and starting UART.*/
    udp->uart->CR1 = cr1;
    /* TODO: Add a new field (pin swap) to set the value SWAP in CR2 */
    udp->uart->CR2 = ((uint32_t)udp->sbit) >> UART_CR2_STOP_Pos;
    udp->uart->CR3 = cr3 | UART_CR3_EIE;
    udp->uart->CR1 = cr1 | UART_CR1_UE | UART_CR1_TE | UART_CR1_RE; /* Enable bits last.*/
    udp->uart->ICR = udp->uart->ISR;
}

size_t uart_write(uart_driver_t *udp, uint8_t *data, size_t len) {

    if (len > 0U) {
        UART_TX_IN_PROGRESS(udp);

        udp->tx_buf = data;
        udp->tx_len = len;

        if (udp->tx_drv_mode == UART_TX_DRV_MODE_DMA_SYNC ||
            udp->tx_drv_mode == UART_TX_DRV_MODE_DMA_ASYNC) {
            uart_dma_lld_write(udp);
        } else if (udp->is_fifo_en == true) {
            uart_fifo_lld_write(udp);
        } else {
            uart_lld_write(udp);
        }

        /* Wait for completion */
        UART_WAIT_FOR_TX_COMPLETION(udp);
    }

    return (size_t)len;
}

size_t uart_read(uart_driver_t *udp, uint8_t *data, size_t len) {

    if (len > 0UL) {
        UART_RX_IN_PROGRESS(udp);

        udp->rx_buf = data;
        udp->rx_len = len;

        if (udp->rx_drv_mode == UART_RX_DRV_MODE_DMA_SYNC ||
            udp->rx_drv_mode == UART_RX_DRV_MODE_DMA_ASYNC) {
            uart_dma_lld_read(udp);
        } else if (udp->is_fifo_en == true) {
            uart_fifo_lld_read(udp);
        } else {
            uart_lld_read(udp);
        }

        /* Wait for completion */
        UART_WAIT_FOR_RX_COMPLETION(udp);
    }

    return (size_t)len;
}

uint32_t uart_get_err_status(uart_driver_t *udp) {

    uint32_t isr;
    uint32_t mask = 0UL;

    isr = udp->uart->ISR;

    if ((isr & UART_ISR_PE) != 0U) {
        mask |= (1UL << 0);
    }
    if ((isr & UART_ISR_FE) != 0U) {
        mask |= (1UL << 1);
    }
    if ((isr & UART_ISR_NE) != 0U) {
        mask |= (1UL << 2);
    }
    if ((isr & UART_ISR_ORE) != 0U) {
        mask |= (1UL << 3);
    }
    if ((isr & UART_ISR_UDR) != 0U) {
        mask |= (1UL << 4);
    }
    if ((isr & UART_ISR_ABRE) != 0U) {
        mask |= (1UL << 5);
    }

    return mask;
}

void uart_stop(uart_driver_t *udp) {

    IRQn_Type vector;

    /* If interrupt mode was selected, disable UART interrupt.*/
    if ((udp->rx_drv_mode == UART_RX_DRV_MODE_INT_SYNC       ||
         udp->rx_drv_mode == UART_RX_DRV_MODE_INT_ASYNC      ||
         udp->rx_drv_mode == UART_RX_DRV_MODE_INT_BUFF_SYNC) ||
        (udp->tx_drv_mode == UART_TX_DRV_MODE_INT_SYNC       ||
         udp->tx_drv_mode == UART_TX_DRV_MODE_INT_ASYNC)) {
        vector = uart_dev_get_vector(udp);
        irq_disable(vector);
    }

    /* If RX DMA mode was selected, disable RX DMA.*/
    if (udp->rx_drv_mode == UART_RX_DRV_MODE_DMA_SYNC       ||
        udp->rx_drv_mode == UART_RX_DRV_MODE_DMA_ASYNC) {
        /* Free and stop DMA RX stream.*/
        dma_stream_free(udp->dma_rx_descriptor);
        dma_stream_disable(udp->dma_rx_descriptor);
    }

    /* If TX DMA mode was selected, disable TX DMA.*/
    if (udp->tx_drv_mode == UART_TX_DRV_MODE_DMA_SYNC       ||
        udp->tx_drv_mode == UART_TX_DRV_MODE_DMA_ASYNC) {
        /* Free and stop DMA TX stream.*/
        dma_stream_free(udp->dma_tx_descriptor);
        dma_stream_disable(udp->dma_tx_descriptor);
    }

    /* Stop procedure.*/
    udp->uart->CR1   = 0U;
    udp->uart->CR2   = 0U;
    udp->uart->CR3   = 0U;
    udp->uart->BRR   = 0U;
    udp->uart->PRESC = 0U;

    /* Disable clock.*/
    uart_dev_clock_disable(udp);
}

void uart_deinit(uart_driver_t *udp) {

    /* Set pointer to UART register block to NULL.*/
    udp->uart  = NULL;
    /* Set UART clock value to default value.*/
    udp->clock = 0UL;

    /* Reset UART parameters.*/
    uart_reset_paramters(udp);
}

void __uart_serve_interrupt(uart_driver_t *udp) {

    uint32_t isr, cr1, cr3;
    uint8_t i;

    /* Reading and clearing status.*/
    isr = udp->uart->ISR;
    udp->uart->ICR = isr;

    /* One read on control registers.*/
    cr1 = udp->uart->CR1;
    cr3 = udp->uart->CR3;

    /* TX ready condition.*/
    if (((cr1 & UART_CR1_TCIE) != 0U) &&
        (isr & UART_ISR_TC) != 0U) {

        if (udp->tx_buf != NULL) {
            if (udp->tx_len > 0U) {
                udp->uart->TDR = (uint32_t)(*udp->tx_buf++);
                udp->tx_len--;
            /* Trasmission completed.*/
            } else {
                /* Disable transmission complete interrupt.*/
                cr1 &= ~UART_CR1_TCIE;

                /* If TX complete callback is defined, it is invoked.*/
                if (udp->cb[UART_CB_OPS_TX] != NULL) {
                    udp->cb[UART_CB_OPS_TX](udp);
                }

                UART_TX_DONE(udp);
            }
        }
    }

    /* RX ready condition.*/
    if (((cr1 & UART_CR1_RXNEIE_RXFNEIE) != 0U) &&
        (isr & UART_ISR_RXNE_RXFNE) != 0U) {
        if (udp->rx_drv_mode == UART_RX_DRV_MODE_INT_BUFF_SYNC) {
            *udp->sbrx_wr_ptr++ = (uint8_t)udp->uart->RDR;
            if (udp->sbrx_wr_ptr == udp->sbrx_end_ptr) {
                udp->sbrx_wr_ptr = udp->sbrx_buf;
            }
            if (udp->sbrx_wr_ptr == udp->sbrx_rd_ptr) {
                udp->sbrx_rd_ptr++;
                if (udp->sbrx_rd_ptr == udp->sbrx_end_ptr) {
                    udp->sbrx_rd_ptr = udp->sbrx_buf;
                }
            }
        } else {
            if (udp->rx_buf != NULL) {
                if (udp->rx_len > 0U) {
                    *udp->rx_buf++ = (uint8_t)udp->uart->RDR;
                    udp->rx_len--;
                    /* Reception completed.*/
                    if (udp->rx_len == 0U) {
                        /* Disable data receive interrupt.*/
                        cr1 &= ~UART_CR1_RXNEIE_RXFNEIE;

                        /* If RX complete callback is defined, it is invoked.*/
                        if (udp->cb[UART_CB_OPS_RX] != NULL) {
                            udp->cb[UART_CB_OPS_RX](udp);
                        }

                        UART_RX_DONE(udp);
                    }
                }
            }
        }
    }

    /* TXFIFO threshold condition.*/
    if (((cr3 & UART_CR3_TXFTIE) != 0U) &&
        (isr & UART_ISR_TXFT) != 0U) {
        if (udp->tx_buf != NULL) {
            for (i = 0; i < udp->tx_fifo_empty; i++) {
                /* Trasmission completed.*/
                if (udp->tx_len == 0U) {
                    /* Disable TXFIFO threshold interrupt.*/
                    cr3 &= ~UART_CR3_TXFTIE;

                    /* If TX complete callback is defined, it is invoked.*/
                    if (udp->cb[UART_CB_OPS_TX] != NULL) {
                        udp->cb[UART_CB_OPS_TX](udp);
                    }

                    UART_TX_DONE(udp);
                } else {
                    udp->uart->TDR = (uint32_t)(*udp->tx_buf++);
                    udp->tx_len--;
                }
            }
        }
	}

    /* RXFIFO threshold condition.*/
    if (((cr3 & UART_CR3_RXFTIE) != 0U) &&
        (isr & UART_ISR_RXFT) != 0U) {
        if (udp->rx_buf != NULL) {
            for (i = 0; i < udp->rx_fifo_full; i++) {
                *udp->rx_buf++ = (uint8_t)udp->uart->RDR;
                udp->rx_len--;
                /* Reception completed.*/
                if (udp->rx_len == 0U) {
                    /* Disable RXFIFO threshold interrupt.*/
                    cr3 &= ~UART_CR3_RXFTIE;

                    /* If TX complete callback is defined, it is invoked.*/
                    if (udp->cb[UART_CB_OPS_RX] != NULL) {
                        udp->cb[UART_CB_OPS_RX](udp);
                    }

                    UART_RX_DONE(udp);
                }
            }
            /* If remaining data to be read is less than the RX FIFO
               threshold, they will be read without FIFO.*/
            if ((udp->rx_len !=0U) && (udp->rx_len < udp->rx_fifo_full)) {
                /* Disable RXFIFO threshold interrupt.*/
                cr3 &= ~UART_CR3_RXFTIE;

                /* Enable data receive interrupt.*/
                cr1 |= UART_CR1_RXNEIE_RXFNEIE;
            }
        }
    }

    /* Error condition.*/
    if (((cr1 & UART_CR3_EIE)  != 0U) &&
        (((isr & UART_ISR_FE)  != 0U) ||
         ((isr & UART_ISR_NE)  != 0U) ||
         ((isr & UART_ISR_ORE) != 0U))) {

        /* If error callback is defined, it is invoked.*/
        if (udp->cb[UART_CB_OPS_ERR] != NULL) {
          udp->cb[UART_CB_OPS_ERR](udp);
        }
    }

    /* Parity error condition.*/
    if (((cr1 & UART_CR1_PEIE) != 0U) &&
        (isr & UART_ISR_PE) != 0U) {

        /* If parity error callback is defined, it is invoked.*/
        if (udp->cb[UART_CB_OPS_PERR] != NULL) {
          udp->cb[UART_CB_OPS_PERR](udp);
        }
    }

    /* One write on control registers.*/
    udp->uart->CR1 = cr1;
    udp->uart->CR3 = cr3;
}

/** @} */
