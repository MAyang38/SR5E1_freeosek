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
 * @file    can.c
 * @brief   CAN driver source file.
 *
 * @addtogroup DRIVERS
 * @addtogroup COMMS
 * @ingroup DRIVERS
 * @addtogroup CAN
 * @ingroup COMMS
 * @{
 */

#include <can.h>
#include <can_private.h>
#include <string.h>

/*===========================================================================*/
/* Module local definitions.                                                 */
/*===========================================================================*/

/**
 * @enum can_clock_t
 * CAN clock configuration.
 */
enum {
    CAN_CLOCK_8MHZ     =   8000000U,   /**<   8 MHz */
    CAN_CLOCK_12MHZ    =  12000000U,   /**<  12 MHz */
    CAN_CLOCK_16MHZ    =  16000000U,   /**<  16 MHz */
    CAN_CLOCK_24MHZ    =  24000000U,   /**<  24 MHz */
    CAN_CLOCK_32MHZ    =  32000000U,   /**<  32 MHz */
    CAN_CLOCK_40MHZ    =  40000000U,   /**<  40 MHz */
    CAN_CLOCK_80MHZ    =  80000000U,   /**<  80 MHz */
    CAN_CLOCK_100MHZ   = 100000000U    /**< 100 MHz */
};

/*===========================================================================*/
/* Module exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Module local types.                                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Module local variables.                                                   */
/*===========================================================================*/

static uint32_t dmu_rx0_data[4];
static uint32_t dmu_rx1_data[4];

/*===========================================================================*/
/* Module local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   Converts DLC field into related frame size.
 *
 * @param[in] dcl            DCL field to be converted
 * @return                   frame size.
 *
 * @notapi
 */
static uint8_t can_lld_get_frame_size(uint8_t dlc) {

    switch (dlc) {
        case 9U:
            return 12U;
        case 10U:
            return 16U;
        case 11:
            return 20U;
        case 12:
            return 24U;
        case 13:
            return 32U;
        case 14:
            return 48U;
        case 15:
            return 64U;
        default:
            return dlc;
    }
}

/**
 * @brief   Converts frame size into related DLC field.
 *
 * @param[in] frame_size     frame size to be converted
 * @return                   DLC field value.
 *
 * @notapi
 */
static uint8_t can_lld_get_dlc(uint8_t frame_size) {

    if (frame_size <= 8U) {
        return frame_size;
    } else if (frame_size == 12U) {
        return 9U;
    } else if (frame_size == 16U) {
        return 10U;
    } else if (frame_size == 20U) {
        return 11U;
    } else if (frame_size == 24U) {
        return 12U;
    } else if (frame_size == 32U) {
        return 13U;
    } else if (frame_size == 48U) {
        return 14U;
    } else if (frame_size == 64U) {
        return 15U;
    } else {
        return 0U;
    }
}

/**
 * @brief   Converts CAN message into frame
 *
 * @param[in] data      pointer to message to be converted
 * @param[out] frame    pointer to converted frame
 * @return              data size [word]
 *
 * @notapi
 */
static uint8_t can_lld_data2frame(uint32_t *data, can_frame_t *frame) {

    uint8_t  frame_size;
    uint8_t  data_size;
    uint8_t  i;

    /* Set frame type.*/
    if ((data[0] >> 30U) == (uint32_t)CAN_ID_XTD) {
        frame->TYPE = CAN_ID_XTD;
        frame->ID = (data[0] & 0x1FFFFFFFUL);
    } else {
        frame->TYPE = CAN_ID_STD;
        frame->ID = (data[0] >> 18U);
    }

    /* Set frame size.*/
    frame_size = can_lld_get_frame_size((uint8_t)((data[1] >> 16) & 0x0FU));
    frame->DLC = frame_size;

    /* Set frame operation (Normal or CANFD).*/
    if (((data[1] >> 21U) & 0x1U) == 0U) {
        frame->OPERATION = CAN_OPERATION_NORMAL;
    } else {
        frame->OPERATION = CAN_OPERATION_CANFD;
    }

    /* Set Time Stamp.*/
    frame->TIME = (uint16_t)(data[1] & 0x000000FFUL);

    /* Get data size [word].*/
    if ((frame_size % 4U) == 0U) {
        data_size = (frame_size / 4U);
    } else {
        data_size = (frame_size / 4U) + 1U;
    }

    /* Set frame data.*/
    for (i = 0U; i < data_size; i++) {
        frame->data32[i] = data[i + 2U];
    }

    return data_size;
}

/**
 * @brief   Converts frame into CAN message
 *
 * @param[in] cdp        pointer to a @p can_driver_t structure
 * @param[in] frame      pointer to frame to be converted
 * @param[out] data      pointer to converted message
 * @return               data size [word]
 *
 * @notapi
 */
static uint8_t can_lld_frame2data(can_driver_t *cdp, const can_frame_t *frame, uint32_t *data) {

    uint8_t  data_size;
    uint8_t  i;

    /* Set message word 0 with frame type.*/
    if (frame->TYPE == CAN_ID_XTD) {
        data[0] = (frame->ID | 0x40000000U);
    } else {
        data[0] = (frame->ID << 18);
    }

    /* Set message word 1 with frame size and frame operation (Normal or CANFD).*/
    data[1] = ((uint32_t)(can_lld_get_dlc(frame->DLC)) << 16);
    if (frame->OPERATION == CAN_OPERATION_CANFD) {
        data[1] |= 0x00200000UL;
        if (cdp->is_fd_brs_mode == true) {
            data[1] |= 0x00100000UL;
        }
    }

    /* Get data size [word].*/
    if ((frame->DLC % 4U) == 0U) {
        data_size = (frame->DLC / 4U);
    } else {
        data_size = (frame->DLC / 4U) + 1U;
    }

    /* Set message words [2:N] with frame data.*/
    for (i = 0; i < data_size; i++) {
        data[i + 2U] = frame->data32[i];
    }

    return data_size;
}

/**
 * @brief   DMU FIFO RX0 DMA callback.
 *
 * @param[in] arg       argument associated to the callback
 * @param[in] sts       DMA callback cause status flags
 *
 * @notapi
 */
static void can_dmu_rx0_dma_callback(void *arg, uint32_t sts) {

    can_frame_t frame = {0};

    /*lint -e9087 */
    can_driver_t *cdp = (can_driver_t *)arg;
    /*lint +e9087 */

    if ((sts & DMA_STS_TCIF) != 0U) {
        /* New message fully received on RX0.*/
        if (cdp->cb != NULL) {
            (void)can_lld_data2frame(dmu_rx0_data, &frame);
            cdp->cb(cdp, frame, CAN_CB_DMU_RX0);
        }
        /* Re-enable DMA for DMU RX FIFO0 to be ready for receiving the next
           frame.*/
        dma_stream_enable(cdp->dma_rx0_descriptor);
    } else {
        ; /* close "if" as required by MISRA */
    }
}

/**
 * @brief   DMU FIFO RX1 DMA callback.
 *
 * @param[in] arg       argument associated to the callback
 * @param[in] sts       DMA callback cause status flags
 *
 * @notapi
 */
static void can_dmu_rx1_dma_callback(void *arg, uint32_t sts) {

    can_frame_t frame = {0};

    /*lint -e9087 */
    can_driver_t *cdp = (can_driver_t *)arg;
    /*lint +e9087 */

    if ((sts & DMA_STS_TCIF) != 0U) {
        /* New message fully received on RX1.*/
        if (cdp->cb != NULL) {
            (void)can_lld_data2frame(dmu_rx1_data, &frame);
            cdp->cb(cdp, frame, CAN_CB_DMU_RX1);
        }
        /* Re-enable DMA for DMU RX FIFO1 to be ready for receiving the next
           frame.*/
        dma_stream_enable(cdp->dma_rx1_descriptor);
    } else {
        ; /* close "if" as required by MISRA */
    }
}

/**
 * @brief   Enables/Disables DMU.
 * @note    This configuration becomes effective after can_start.
 *
 * @param[in] cdp       pointer to a @p can_driver_t structure
 * @param[in] enable    true to enable DMU, false otherwise.
 *
 * @notapi
 */
static void can_lld_set_dmu(can_driver_t *cdp, bool enable) {

    uint32_t dma_fifo_mode;
    uint32_t dma_rx_mode, dma_tx_mode;

    if ((bool)enable == true) {
        /* Configure DMU interrupts.*/
        cdp->can->DMU_QC = 0UL;
        cdp->can->DMU_IR = 0xFFFFFFFFUL;
        REG_SET_FIELD(cdp->can->DMU_IE, FDCAN_DMU_IE_TXEEE, 1U);

        /* Configure DMA for DMU.*/

        /* Allocates DMA streams for DMU RX FIFO0/1 and TX FIFO/QUEUE.*/
        /*lint -e9087 */
        cdp->dma_rx0_descriptor = dma_stream_take(cdp->dma_conf->dma_stream_rx0_id,
                                                  cdp->dma_conf->dma_stream_irq_prio,
                                                  can_dmu_rx0_dma_callback,
                                                  (void *)cdp);
        cdp->dma_rx1_descriptor = dma_stream_take(cdp->dma_conf->dma_stream_rx1_id,
                                                  cdp->dma_conf->dma_stream_irq_prio,
                                                  can_dmu_rx1_dma_callback,
                                                  (void *)cdp);
        cdp->dma_tx_descriptor  = dma_stream_take(cdp->dma_conf->dma_stream_tx_id,
                                                  cdp->dma_conf->dma_stream_irq_prio,
                                                  NULL,
                                                  NULL);
        /*lint +e9087 */

        /* Configure DMA triggers for DMU RX FIFO0/1 and TX FIFO/QUEUE.*/
        dma_stream_set_trigger(cdp->dma_rx0_descriptor, can_dev_get_dma_rx0_trigger(cdp));
        dma_stream_set_trigger(cdp->dma_rx1_descriptor, can_dev_get_dma_rx1_trigger(cdp));
        dma_stream_set_trigger(cdp->dma_tx_descriptor,  can_dev_get_dma_tx_trigger(cdp));

        /* Configure DMA stream peripheral addresses for DMU RX FIFO0/1 and TX
           FIFO/QUEUE.*/
        dma_stream_set_peripheral(cdp->dma_rx0_descriptor, (uint32_t)(cdp->can->DMU_RX0));
        dma_stream_set_peripheral(cdp->dma_rx1_descriptor, (uint32_t)(cdp->can->DMU_RX1));
        dma_stream_set_peripheral(cdp->dma_tx_descriptor,  (uint32_t)(cdp->can->DMU_TX));

        /* Configure DMA priority level, data transfer direction and enable
           transfer complete interrupt for DMU RX FIFO0/1 and TX FIFO/QUEUE.*/
        dma_rx_mode = DMA_CCR_PL_VALUE(cdp->dma_conf->dma_stream_bus_prio) |
                      DMA_CCR_DIR_P2M | DMA_CCR_TCIE;
        dma_tx_mode = DMA_CCR_PL_VALUE(cdp->dma_conf->dma_stream_bus_prio) |
                      DMA_CCR_DIR_M2P | DMA_CCR_TCIE;

        /* Configure DMA frame sizes for DMU RX FIFO0/1 and TX FIFO/QUEUE.*/
        dma_rx_mode |= DMA_CCR_PSIZE_WORD | DMA_CCR_MSIZE_WORD;
        dma_tx_mode |= DMA_CCR_PSIZE_WORD | DMA_CCR_MSIZE_WORD;

        /* Configure DMA memory increment modes for DMU RX FIFO0/1 and TX
           FIFO/QUEUE.*/
        dma_rx_mode |= DMA_CCR_MINC | DMA_CCR_PINC;
        dma_tx_mode |= DMA_CCR_MINC | DMA_CCR_PINC;

        /* Configure DMA peripheral burst transfer configurations for DMU RX
           FIFO0/1 and for DMU TX FIFO/QUEUE. Since DMU allows to transfer/
           receive only frames with a frame size of 4 words, peripheral burst
           is fixed to 4.*/
        dma_rx_mode |= DMA_CCR_PBURST_INCR4;
        dma_tx_mode |= DMA_CCR_PBURST_INCR4;

        /* Set up calculated DMA modes for DMU RX FIFO0/1 and for DMU TX
           FIFO/QUEUE.*/
        dma_stream_set_transfer_mode(cdp->dma_rx0_descriptor, dma_rx_mode);
        dma_stream_set_transfer_mode(cdp->dma_rx1_descriptor, dma_rx_mode);
        dma_stream_set_transfer_mode(cdp->dma_tx_descriptor,  dma_tx_mode);

        /* Configure DMA number of data items (words to be received for DMU RX
           FIFO0/1 or words to be transmitted for DMU TX FIFO/QUEUE). Since DMU
           allows to transmit/receive only frames with a frame size of 4 words,
           the number of data items is fixed to 4.*/
        dma_stream_set_count(cdp->dma_rx0_descriptor, 4U);
        dma_stream_set_count(cdp->dma_rx1_descriptor, 4U);
        dma_stream_set_count(cdp->dma_tx_descriptor,  4U);

        /* Configure DMA stream memory addresses for DMU RX FIFO0/1.*/
        dma_stream_set_memory(cdp->dma_rx0_descriptor, (uint32_t)(dmu_rx0_data));
        dma_stream_set_memory(cdp->dma_rx1_descriptor, (uint32_t)(dmu_rx1_data));

        /* Configure DMA FIFO modes for DMU RX FIFO0/1 and TX FIFO/QUEUE.*/
        dma_fifo_mode = DMA_FCR_DMDIS_FIFO_ENABLE | DMA_FCR_FTH_FULL;
        dma_stream_set_fifo_mode(cdp->dma_rx0_descriptor, dma_fifo_mode);
        dma_stream_set_fifo_mode(cdp->dma_rx1_descriptor, dma_fifo_mode);
        dma_stream_set_fifo_mode(cdp->dma_tx_descriptor,  dma_fifo_mode);

        /* Enable DMA for DMU RX FIFO0/1. It will be disabled on the DMA end of
           transfer.*/
        dma_stream_enable(cdp->dma_rx0_descriptor);
        dma_stream_enable(cdp->dma_rx1_descriptor);
    } else {
        cdp->can->DMU_QC = 0UL;
        REG_SET_FIELD(cdp->can->DMU_IE, FDCAN_DMU_IE_TXEEE, 0U);

        /* Disable DMA streams for DMU RX FIFO0/1 and TX FIFO/QUEUE if
           previously enabled.*/
        if (cdp->dma_tx_descriptor != NULL) {
            dma_stream_disable(cdp->dma_tx_descriptor);
        }
        if (cdp->dma_rx0_descriptor != NULL) {
            dma_stream_disable(cdp->dma_rx0_descriptor);
        }
        if (cdp->dma_rx1_descriptor != NULL) {
            dma_stream_disable(cdp->dma_rx1_descriptor);
        }
    }
}

/**
 * @brief   Configures loopback mode.
 * @note    This configuration becomes effective after can_start.
 *
 * @param[in] cdp       pointer to a @p can_driver_t structure
 * @param[in] lb_mode   loopback mode to be configured. It can be one of the
 *                      following values:
 *            @arg @ref CAN_NO_LOOPBACK
 *            @arg @ref CAN_LOOPBACK_INTERNAL
 *            @arg @ref CAN_LOOPBACK_EXTERNAL
 *
 * @notapi
 */
static void can_lld_set_loopback(can_driver_t *cdp, can_lb_mode_t lb_mode) {

    if (lb_mode != CAN_NO_LOOPBACK) {
        REG_SET_FIELD(cdp->can->CCCR, FDCAN_CCCR_TEST_EN, 1U);
        REG_SET_FIELD(cdp->can->TEST, FDCAN_TEST_LBCK, 1U);
        if (lb_mode == CAN_LOOPBACK_INTERNAL) {
            REG_SET_FIELD(cdp->can->CCCR, FDCAN_CCCR_MON, 1U);
        }
    }
}

/**
 * @brief   Enables/Disables Flex Data Rate mode.
 * @note    This configuration becomes effective after can_start.
 *
 * @param[in] cdp       pointer to a @p can_driver_t structure
 * @param[in] enable    true to enable flex data rate, false otherwise.
 *
 * @notapi
 */
static void can_lld_set_flexdatarate(can_driver_t *cdp, bool enable) {

    if ((bool)enable == true) {
        REG_SET_FIELD(cdp->can->CCCR, FDCAN_CCCR_FDOE, 1U);
    } else {
        REG_SET_FIELD(cdp->can->CCCR, FDCAN_CCCR_FDOE, 0U);
    }
}

/**
 * @brief   Configures Baudrate.
 * @note    This configuration becomes effective after can_start.
 * @note    This function configures HW according to the clock settings and the
 *          desired baudrate addressing most common configurations.
 *
 * @param[in] cdp       pointer to a @p can_driver_t structure
 * @param[in] baudrate  baudrate to be configured.
 * @return              operation status (true if the baudrate is correctly
 *                      initialized, false otherwise).
 *
 * @notapi
 */
static bool can_lld_set_baudrate(can_driver_t *cdp, can_baudrate_t baudrate) {

    /* Reset baudrate fields.*/
    cdp->nbtp.nbrp     = 0U;
    cdp->nbtp.ntseg1   = 0U;
    cdp->nbtp.ntseg2   = 0U;
    cdp->nbtp.nsjw     = 0U;
    cdp->dbtp.dbrp     = 0U;
    cdp->dbtp.dtseg1   = 10U;
    cdp->dbtp.dtseg2   = 3U;
    cdp->dbtp.dsjw     = 3U;
    cdp->tdc.is_tdc_en = false;
    cdp->tdc.tdco      = 0U;
    cdp->tdc.tdcf      = 0U;

    /* Standard CAN.*/
    if (cdp->is_fd_mode == false) {
        if (cdp->clock == (uint32_t)CAN_CLOCK_12MHZ) {
            cdp->nbtp.nbrp = (uint16_t)(cdp->clock / ((uint32_t)baudrate * 12U)) - 1U;
            cdp->nbtp.nsjw = 1U;
            cdp->nbtp.ntseg1 = 7U;
            cdp->nbtp.ntseg2 = 2U;
        } else if ((cdp->clock == (uint32_t)CAN_CLOCK_8MHZ)
                || (cdp->clock == (uint32_t)CAN_CLOCK_16MHZ)
                || (cdp->clock == (uint32_t)CAN_CLOCK_24MHZ)
                || (cdp->clock == (uint32_t)CAN_CLOCK_32MHZ)
                || (cdp->clock == (uint32_t)CAN_CLOCK_40MHZ)) {
            cdp->nbtp.nbrp = (uint16_t)(cdp->clock / ((uint32_t)baudrate * 8U)) - 1U;
            cdp->nbtp.nsjw = 1U;
            cdp->nbtp.ntseg1 = 4U;
            cdp->nbtp.ntseg2 = 1U;
        } else {
            return false;
        }
    } else {
        /* Configure arbitration and data segments in case of CAN-FD for all
           clock selections and baudrate.*/
        if (cdp->clock == (uint32_t)CAN_CLOCK_40MHZ) {
            /* Setting arbitration part baud-rate to 1 MBit/s.*/
            cdp->nbtp.nbrp = 0U;
            cdp->nbtp.nsjw = 3U;
            cdp->nbtp.ntseg1 = 28U;
            cdp->nbtp.ntseg2 = 9U;
            /* Supported baudrate selection for the protocol clock.*/
            switch (baudrate) {
                    case CAN_BAUDRATE_1MBIT:
                        cdp->tdc.is_tdc_en = false;
                        cdp->tdc.tdco = 0U;
                        cdp->dbtp.dbrp = (uint8_t)(cdp->clock / ((uint32_t)baudrate * 10U)) - 1U;
                        cdp->dbtp.dsjw = 1U;
                        cdp->dbtp.dtseg1 = 5U;
                        cdp->dbtp.dtseg2 = 2U;
                        break;
                    case CAN_BAUDRATE_2MBIT:
                        cdp->tdc.is_tdc_en = true;
                        cdp->tdc.tdco = 12U;
                        cdp->dbtp.dbrp = (uint8_t)(cdp->clock / ((uint32_t)baudrate * 10U)) - 1U;
                        cdp->dbtp.dsjw = 1U;
                        cdp->dbtp.dtseg1 = 5U;
                        cdp->dbtp.dtseg2 = 2U;
                        break;
                    case CAN_BAUDRATE_4MBIT:
                        cdp->tdc.is_tdc_en = true;
                        cdp->tdc.tdco = 7U;
                        cdp->dbtp.dbrp = (uint8_t)(cdp->clock / ((uint32_t)baudrate * 10U)) - 1U;
                        cdp->dbtp.dsjw = 1U;
                        cdp->dbtp.dtseg1 = 5U;
                        cdp->dbtp.dtseg2 = 2U;
                        break;
                    case CAN_BAUDRATE_5MBIT:
                        cdp->tdc.is_tdc_en = true;
                        cdp->tdc.tdco = 6U;
                        cdp->dbtp.dbrp = (uint8_t)(cdp->clock / ((uint32_t)baudrate * 8U)) - 1U;
                        cdp->dbtp.dsjw = 1U;
                        cdp->dbtp.dtseg1 = 4U;
                        cdp->dbtp.dtseg2 = 1U;
                        break;
                    case CAN_BAUDRATE_8MBIT:
                        cdp->tdc.is_tdc_en = true;
                        cdp->tdc.tdco = 4U;
                        cdp->dbtp.dbrp = (uint8_t)(cdp->clock / ((uint32_t)baudrate * 5U)) - 1U;
                        cdp->dbtp.dsjw = 1U;
                        cdp->dbtp.dtseg1 = 2U;
                        cdp->dbtp.dtseg2 = 0U;
                        break;
                    case CAN_BAUDRATE_2_5MBIT:
                    default:
                        return false;
            }
        } else if (cdp->clock == (uint32_t)CAN_CLOCK_80MHZ) {
            /* Setting arbitration part baud-rate to 1 MBit/s.*/
            cdp->nbtp.nbrp = 1U;
            cdp->nbtp.nsjw = 3U;
            cdp->nbtp.ntseg1 = 28U;
            cdp->nbtp.ntseg2 = 9U;

            switch (baudrate) {
            case CAN_BAUDRATE_1MBIT:
                    cdp->tdc.is_tdc_en = false;
                    cdp->tdc.tdco = 0U;
                    cdp->dbtp.dbrp = (uint8_t)(cdp->clock / ((uint32_t)baudrate * 10U)) - 1U;
                    cdp->dbtp.dsjw = 1U;
                    cdp->dbtp.dtseg1 = 5U;
                    cdp->dbtp.dtseg2 = 2U;
                    break;
                case CAN_BAUDRATE_2MBIT:
                    cdp->tdc.is_tdc_en = false;
                    cdp->tdc.tdco = 0U;
                    cdp->dbtp.dbrp = (uint8_t)(cdp->clock / ((uint32_t)baudrate * 10U)) - 1U;
                    cdp->dbtp.dsjw = 2U;
                    cdp->dbtp.dtseg1 = 5U;
                    cdp->dbtp.dtseg2 = 2U;
                    break;
                case CAN_BAUDRATE_2_5MBIT:
                    cdp->tdc.is_tdc_en = true;
                    cdp->tdc.tdco = 20U;
                    cdp->dbtp.dbrp = (uint8_t)(cdp->clock / ((uint32_t)baudrate * 8U)) - 1U;
                    cdp->dbtp.dsjw = 2U;
                    cdp->dbtp.dtseg1 = 4U;
                    cdp->dbtp.dtseg2 = 1U;
                    break;
                case CAN_BAUDRATE_4MBIT:
                    cdp->tdc.is_tdc_en = true;
                    cdp->tdc.tdco = 12U;
                    cdp->dbtp.dbrp = (uint8_t)(cdp->clock / ((uint32_t)baudrate * 10U)) - 1U;
                    cdp->dbtp.dsjw = 2U;
                    cdp->dbtp.dtseg1 = 5U;
                    cdp->dbtp.dtseg2 = 2U;
                    break;
                case CAN_BAUDRATE_5MBIT:
                    cdp->tdc.is_tdc_en = true;
                    cdp->tdc.tdco = 10U;
                    cdp->dbtp.dbrp = (uint8_t)(cdp->clock / ((uint32_t)baudrate * 8U)) - 1U;
                    cdp->dbtp.dsjw = 2U;
                    cdp->dbtp.dtseg1 = 4U;
                    cdp->dbtp.dtseg2 = 1U;
                    break;
                case CAN_BAUDRATE_8MBIT:
                    cdp->tdc.is_tdc_en = true;
                    cdp->tdc.tdco = 7U;
                    cdp->dbtp.dbrp = (uint8_t)(cdp->clock / ((uint32_t)baudrate * 10U)) - 1U;
                    cdp->dbtp.dsjw = 2U;
                    cdp->dbtp.dtseg1 = 5U;
                    cdp->dbtp.dtseg2 = 2U;
                    break;
                default:
                    return false;
            }
        } else if (cdp->clock == (uint32_t)CAN_CLOCK_100MHZ) {
            /* Setting arbitration part baud-rate to 1 MBit/s.*/
            cdp->nbtp.nbrp = 4U;
            cdp->nbtp.nsjw = 2U;
            cdp->nbtp.ntseg1 = 13U;
            cdp->nbtp.ntseg2 = 4U;

            switch (baudrate) {
                case CAN_BAUDRATE_2_5MBIT:
                    cdp->tdc.is_tdc_en = false;
                    cdp->tdc.tdco = 0U;
                    cdp->dbtp.dbrp = (uint8_t)(cdp->clock / ((uint32_t)baudrate * 10U)) - 1U;
                    cdp->dbtp.dsjw = 2U;
                    cdp->dbtp.dtseg1 = 5U;
                    cdp->dbtp.dtseg2 = 2U;
                    break;
                case CAN_BAUDRATE_5MBIT:
                    cdp->tdc.is_tdc_en = true;
                    cdp->tdc.tdco = 12U;
                    cdp->dbtp.dbrp = (uint8_t)(cdp->clock / ((uint32_t)baudrate * 10U)) - 1U;
                    cdp->dbtp.dsjw = 2U;
                    cdp->dbtp.dtseg1 = 5U;
                    cdp->dbtp.dtseg2 = 2U;
                    break;
                case CAN_BAUDRATE_1MBIT:
                case CAN_BAUDRATE_2MBIT:
                case CAN_BAUDRATE_4MBIT:
                case CAN_BAUDRATE_8MBIT:
                default:
                    return false;
            }
        } else {
            return false;
        }
    }

    return true;
}

/**
 * @brief   Configures data field size.
 * @note    This configuration becomes effective after can_start.
 *
 * @param[in] cdp       pointer to a @p can_driver_t structure
 * @param[in] datasize  data field size to be configured. It can be one of the
 *                      following values:
 *            @arg @ref CAN_DATASIZE_8BYTE
 *            @arg @ref CAN_DATASIZE_12BYTE
 *            @arg @ref CAN_DATASIZE_16BYTE
 *            @arg @ref CAN_DATASIZE_20BYTE
 *            @arg @ref CAN_DATASIZE_24BYTE
 *            @arg @ref CAN_DATASIZE_32BYTE
 *            @arg @ref CAN_DATASIZE_48BYTE
 *            @arg @ref CAN_DATASIZE_64BYTE
 *
 * @notapi
 */
static void can_lld_set_datasize(can_driver_t *cdp, can_datasize_t datasize) {

    uint8_t size = 0U;

    switch(datasize) {
        case CAN_DATASIZE_8BYTE:
            size = 0U;
            break;
        case CAN_DATASIZE_12BYTE:
            size = 1U;
            break;
        case CAN_DATASIZE_16BYTE:
            size = 2U;
            break;
        case CAN_DATASIZE_20BYTE:
            size = 3U;
            break;
        case CAN_DATASIZE_24BYTE:
            size = 4U;
            break;
        case CAN_DATASIZE_32BYTE:
            size = 5U;
            break;
        case CAN_DATASIZE_48BYTE:
            size = 6U;
            break;
        case CAN_DATASIZE_64BYTE:
            size = 7U;
            break;
        default:
            /* Dummy comment as required by MISRA.*/
            break;
    }

    REG_SET_FIELD(cdp->can->RXESC, FDCAN_RXESC_F0DS, size);
    REG_SET_FIELD(cdp->can->RXESC, FDCAN_RXESC_F1DS, size);
    REG_SET_FIELD(cdp->can->RXESC, FDCAN_RXESC_RBDS, size);
    REG_SET_FIELD(cdp->can->TXESC, FDCAN_TXESC_TBDS, size);
}

/**
 * @brief   Configures CAN Shared RAM.
 * @note    This function takes care about internal shared RAM configuration,
 *          including filter configuration.
 * @note    This configuration becomes effective after can_start.
 *
 * @param[in] cdp       pointer to an @p can_driver_t structure
 *
 * @notapi
 */
static void can_lld_set_sram(can_driver_t *cdp) {

    unsigned int i;
    uint32_t val;
    uint32_t filter_offset;
    uint32_t ram_addr, msg_ram_base_addr;

    msg_ram_base_addr = can_dev_get_msg_ram_address(cdp);

    ram_addr = cdp->ram_start - msg_ram_base_addr;

    /* Global Filter Initialization.*/
    /* Reject messages don't match filtering for Standard messages.*/
    REG_SET_FIELD(cdp->can->GFC, FDCAN_GFC_ANFS, 3U);
    /* Reject messages don't match filtering for Extended messages.*/
    REG_SET_FIELD(cdp->can->GFC, FDCAN_GFC_ANFE, 3U);

    /* Shared RAM Initialization */

    /* Standard filters.*/
    REG_SET_FIELD(cdp->can->SIDFC, FDCAN_SIDFC_FLSSA, (ram_addr >> CAN_SA_BIT));
    REG_SET_FIELD(cdp->can->SIDFC, FDCAN_SIDFC_LSS, cdp->std_filter_num);
    ram_addr = ram_addr + (4UL * cdp->std_filter_num);

    /* Extended filters.*/
    REG_SET_FIELD(cdp->can->XIDFC, FDCAN_XIDFC_FLESA, (ram_addr >> CAN_SA_BIT));
    REG_SET_FIELD(cdp->can->XIDFC, FDCAN_XIDFC_LSE, cdp->xtd_filter_num);
    ram_addr = ram_addr + (8UL * cdp->xtd_filter_num);

    /* RX FIFO0.*/
    REG_SET_FIELD(cdp->can->RXF0C, FDCAN_RXF0C_F0SA, (ram_addr >> CAN_SA_BIT));
    REG_SET_FIELD(cdp->can->RXF0C, FDCAN_RXF0C_F0S, cdp->rx_fifo0_num);
    REG_SET_FIELD(cdp->can->RXF0C, FDCAN_RXF0C_F0OM, CAN_FIFO_OVERWRITE_MODE);
    REG_SET_FIELD(cdp->can->RXF0C, FDCAN_RXF0C_F0WM, CAN_FIFO_WATERMARK_DISABLED);
    ram_addr = ram_addr + ((8UL + ((uint8_t)cdp->datasize)) * cdp->rx_fifo0_num);

    /* RX FIFO1*.*/
    REG_SET_FIELD(cdp->can->RXF1C, FDCAN_RXF1C_F1SA, (ram_addr >> CAN_SA_BIT));
    REG_SET_FIELD(cdp->can->RXF1C, FDCAN_RXF1C_F1S, cdp->rx_fifo1_num);
    REG_SET_FIELD(cdp->can->RXF1C, FDCAN_RXF1C_F1OM, CAN_FIFO_OVERWRITE_MODE);
    REG_SET_FIELD(cdp->can->RXF1C, FDCAN_RXF1C_F1WM, CAN_FIFO_WATERMARK_DISABLED);
    ram_addr = ram_addr + ((8UL + ((uint8_t)cdp->datasize)) * cdp->rx_fifo1_num);

    /* RX buffers.*/
    REG_SET_FIELD(cdp->can->RXBC, FDCAN_RXBC_RBSA, (ram_addr >> CAN_SA_BIT));
    ram_addr = ram_addr + ((8UL + ((uint8_t)cdp->datasize)) * cdp->rx_buff_num);

    /* TX Buffers.*/
    REG_SET_FIELD(cdp->can->TXBC, FDCAN_TXBC_TBSA, (ram_addr >> CAN_SA_BIT));
    REG_SET_FIELD(cdp->can->TXBC, FDCAN_TXBC_NDTB, cdp->tx_buff_num);

    if (cdp->tx_mode != CAN_TX_MODE_DEDICATED_BUFF) {
        /* Set FIFO/QUEUE buffer if mode is different from CAN_TX_MODE_DEDICATED_BUFF.*/
        REG_SET_FIELD(cdp->can->TXBC, FDCAN_TXBC_TFQS, cdp->tx_fifoq_num);
        /* Configure Queue mode.*/
        if ((cdp->tx_mode == CAN_TX_MODE_QUEUE) || (cdp->tx_mode == CAN_TX_MODE_MIXED_QUEUE)){
            REG_SET_FIELD(cdp->can->TXBC, FDCAN_TXBC_TFQM, 1U);
        }
    }

    /* Standard filter configuration.*/
    for (i = 0; i < cdp->std_filter_num; i++) {
        val = cdp->std_filter[i].FID2;
        val += ((uint32_t)cdp->std_filter[i].FID1 << 16);
        val += ((uint32_t)cdp->std_filter[i].FEC << 27);
        val += ((uint32_t)cdp->std_filter[i].FT << 30);
        filter_offset = msg_ram_base_addr + (REG_READ_FIELD(cdp->can->SIDFC, FDCAN_SIDFC_FLSSA) << CAN_SA_BIT) + (4UL * i);
        *(vuint32_t*)(filter_offset) = val;
    }

    /* Extended filter configuration.*/
    for (i = 0; i < cdp->xtd_filter_num; i++) {
        /* Word F0.*/
        val = cdp->xtd_filter[i].FID1;
        val += ((uint32_t)cdp->xtd_filter[i].FEC << 29);
        filter_offset = msg_ram_base_addr + (REG_READ_FIELD(cdp->can->XIDFC, FDCAN_XIDFC_FLESA) << CAN_SA_BIT) + (8UL * i);
        *(vuint32_t*)(filter_offset) = val;
        /* Word F1.*/
        val = cdp->xtd_filter[i].FID2;
        val += ((uint32_t)cdp->xtd_filter[i].FT << 30);
        filter_offset = msg_ram_base_addr + (REG_READ_FIELD(cdp->can->XIDFC, FDCAN_XIDFC_FLESA) << CAN_SA_BIT) + (8UL * i) + 4U;
        *(vuint32_t*)(filter_offset) = val;
    }
}

/**
 * @brief   Starts a CAN instance.
 * @note    This function takes care to start a CAN instance applying the
 *          configuration specified with the dedicates APIs.
 *
 * @param[in] cdp       pointer to an @p can_driver_t structure
 *
 * @notapi
 */
static void can_lld_start(can_driver_t *cdp) {

    /* Reset shared RAM..*/
    memset(( void *) cdp->ram_start, 0, cdp->ram_size);

    /* Switch in configuration and initialization mode.*/
    cdp->can->CCCR |= FDCAN_CCCR_CCE | FDCAN_CCCR_INIT;
    while ((cdp->can->CCCR & FDCAN_CCCR_INIT) == 0U) {}

    /* Configure DMU.*/
    can_lld_set_dmu(cdp, cdp->is_dmu_mode);

    /* Configure loopback mode.*/
    can_lld_set_loopback(cdp, cdp->lb_mode);

    /* Configure FD mode.*/
    can_lld_set_flexdatarate(cdp, cdp->is_fd_mode);

    /* Configure baudrate.*/

    /* Configure nominal bit timing and prescaler.*/
    REG_SET_FIELD(cdp->can->NBTP, FDCAN_NBTP_NBRP,   cdp->nbtp.nbrp);
    REG_SET_FIELD(cdp->can->NBTP, FDCAN_NBTP_NTSEG1, cdp->nbtp.ntseg1);
    REG_SET_FIELD(cdp->can->NBTP, FDCAN_NBTP_NTSEG2, cdp->nbtp.ntseg2);
    REG_SET_FIELD(cdp->can->NBTP, FDCAN_NBTP_NSJW,   cdp->nbtp.nsjw);

    if (cdp->is_fd_mode == true) {
        /* Configure data bit timing and prescaler.*/
        REG_SET_FIELD(cdp->can->DBTP, FDCAN_DBTP_DBRP,   cdp->dbtp.dbrp);
        REG_SET_FIELD(cdp->can->DBTP, FDCAN_DBTP_DTSEG1, cdp->dbtp.dtseg1);
        REG_SET_FIELD(cdp->can->DBTP, FDCAN_DBTP_DTSEG2, cdp->dbtp.dtseg2);
        REG_SET_FIELD(cdp->can->DBTP, FDCAN_DBTP_DSJW,   cdp->dbtp.dsjw);

        /* Configure transceiver delay compensation.*/
        if (cdp->tdc.is_tdc_en == true) {
            REG_SET_FIELD(cdp->can->DBTP, FDCAN_DBTP_TDC,  1U);
            REG_SET_FIELD(cdp->can->TDCR, FDCAN_TDCR_TDCO, cdp->tdc.tdco);
            REG_SET_FIELD(cdp->can->TDCR, FDCAN_TDCR_TDCF, cdp->tdc.tdcf);
        } else {
            REG_SET_FIELD(cdp->can->DBTP, FDCAN_DBTP_TDC,  0U);
            REG_SET_FIELD(cdp->can->TDCR, FDCAN_TDCR_TDCO, 0U);
            REG_SET_FIELD(cdp->can->TDCR, FDCAN_TDCR_TDCF, 0U);
        }
    }

    /* Enable/Disable bit rate switch.*/
    if (cdp->is_fd_brs_mode == true) {
        REG_SET_FIELD(cdp->can->CCCR, FDCAN_CCCR_BRSE, 1U);
    } else {
        REG_SET_FIELD(cdp->can->CCCR, FDCAN_CCCR_BRSE, 0U);
    }

    /* Initialize data field size.*/
    can_lld_set_datasize(cdp, cdp->datasize);

    /* Configure shared RAM.*/
    can_lld_set_sram(cdp);

    /* Clear interrupt register.*/
    cdp->can->IR  = 0xFFFFFFFFUL;

    /* Enable interrupts.*/
    cdp->can->IE  = 0x0UL;
    if (((cdp->irq_mask & CAN_IRQ_TC_ENABLED) != 0U) && (cdp->is_dmu_mode == false)) {
        /* Enable transmission completed interrupt.*/
        REG_SET_FIELD(cdp->can->IE, FDCAN_IE_TCE, 1U);
        REG_SET_FIELD(cdp->can->ILS, FDCAN_ILS_TCL, ((uint8_t)cdp->irq_line));
    }
    if ((cdp->irq_mask & CAN_IRQ_TX_FIFO_EMPTY_ENABLED) != 0U) {
        /* Enable TX FIFO empty interrupt.*/
        REG_SET_FIELD(cdp->can->IE, FDCAN_IE_TFEE, 1U);
        REG_SET_FIELD(cdp->can->ILS, FDCAN_ILS_TFEL, ((uint8_t)cdp->irq_line));
    }
    if (cdp->is_rx_polling_mode == false) {
        /* Enable new message in dedicated RX buffer interrupt.*/
        REG_SET_FIELD(cdp->can->IE, FDCAN_IE_DRXE, 1U);
        REG_SET_FIELD(cdp->can->ILS, FDCAN_ILS_DRXL, ((uint8_t)cdp->irq_line));
    }
    if (cdp->is_rx_polling_mode == false && cdp->is_dmu_mode == false) {
        /* Enable RX FIFO 0 new message interrupt.*/
        REG_SET_FIELD(cdp->can->IE, FDCAN_IE_RF0NE, 1U);
        REG_SET_FIELD(cdp->can->ILS, FDCAN_ILS_RF0NL, ((uint8_t)cdp->irq_line));
    }
    if ((cdp->irq_mask & CAN_IRQ_FIFO0_WATERMARK_ENABLED) != 0U) {
        /* Enable RX FIFO 0 watermark reached interrupt.*/
        REG_SET_FIELD(cdp->can->IE, FDCAN_IE_RF0WE, 1U);
        REG_SET_FIELD(cdp->can->ILS, FDCAN_ILS_RF0WL, ((uint8_t)cdp->irq_line));
    }
    if ((cdp->irq_mask & CAN_IRQ_FIFO0_FULL_ENABLED) != 0U) {
        /* Enable RX FIFO 0 full interrupt.*/
        REG_SET_FIELD(cdp->can->IE, FDCAN_IE_RF0FE, 1U);
        REG_SET_FIELD(cdp->can->ILS, FDCAN_ILS_RF0FL, ((uint8_t)cdp->irq_line));
    }
    if ((cdp->irq_mask & CAN_IRQ_FIFO0_LOST_ENABLED) != 0U) {
        /* Enable RX FIFO 0 message lost interrupt.*/
        REG_SET_FIELD(cdp->can->IE, FDCAN_IE_RF0LE, 1U);
        REG_SET_FIELD(cdp->can->ILS, FDCAN_ILS_RF0LL, ((uint8_t)cdp->irq_line));
    }
    if ((cdp->is_rx_polling_mode == false) && (cdp->is_dmu_mode == false)) {
        /* Enable RX FIFO 1 new message interrupt.*/
        REG_SET_FIELD(cdp->can->IE, FDCAN_IE_RF1NE, 1U);
        REG_SET_FIELD(cdp->can->ILS, FDCAN_ILS_RF1NL, ((uint8_t)cdp->irq_line));
    }
    if ((cdp->irq_mask & CAN_IRQ_FIFO1_WATERMARK_ENABLED) != 0U) {
        /* Enable RX FIFO 1 watermark reached interrupt.*/
        REG_SET_FIELD(cdp->can->IE, FDCAN_IE_RF1WE, 1U);
        REG_SET_FIELD(cdp->can->ILS, FDCAN_ILS_RF1WL, ((uint8_t)cdp->irq_line));
    }
    if ((cdp->irq_mask & CAN_IRQ_FIFO1_FULL_ENABLED) != 0U) {
        /* Enable RX FIFO 1 full interrupt.*/
        REG_SET_FIELD(cdp->can->IE, FDCAN_IE_RF1FE, 1U);
        REG_SET_FIELD(cdp->can->ILS, FDCAN_ILS_RF1FL, ((uint8_t)cdp->irq_line));
    }
    if ((cdp->irq_mask & CAN_IRQ_FIFO1_LOST_ENABLED) != 0U) {
        /* Enable RX FIFO 1 message lost interrupt.*/
        REG_SET_FIELD(cdp->can->IE, FDCAN_IE_RF1LE, 1U);
        REG_SET_FIELD(cdp->can->ILS, FDCAN_ILS_RF1LL, ((uint8_t)cdp->irq_line));
    }
    if ((cdp->irq_mask & CAN_IRQ_BOE_ENABLED) != 0U) {
        /* Enable Bus Off status interrupt.*/
        REG_SET_FIELD(cdp->can->IE, FDCAN_IE_BOE, 1U);
        REG_SET_FIELD(cdp->can->ILS, FDCAN_ILS_BOL, ((uint8_t)cdp->irq_line));
    }

    /**
     * @verbatim
     *  Enable interrupts for the following errors:
     *
     *  - MRAF: Message RAM access Failure
     *  - TOO:  Timeout
     *  - BEC:  Bit Error Corrected
     *  - BEU:  Bit Error Uncorrected
     *  - ELO:  Error Logging Overflow
     *  - EP:   Error Passive
     *  - EW:   Warning Status
     *  - WDI:  Watchdog Interrupt
     *  - PEA:  Protocol error in Arbitration Phase
     *  - PED:  Protocol Error In Data Phase
     *  - ARA:  Access to reserved address
     *
     *  CAN_IRQ_ERROR_MASK contains bit map for these errors
     * @endverbatim
     */
    cdp->can->IE |= CAN_IRQ_ERROR_MASK;

    /* Enable interrupt line.*/
    if (cdp->irq_line == CAN_IRQ_LINE0) {
        REG_SET_FIELD(cdp->can->ILE, FDCAN_ILE_EINT0, 1U);
    } else {
        REG_SET_FIELD(cdp->can->ILE, FDCAN_ILE_EINT1, 1U);
    }

    /* Clear RX buffers to start receiving.*/
    cdp->can->NDAT1 = 0xFFFFFFFFUL;
    cdp->can->NDAT2 = 0xFFFFFFFFUL;

    /* Exit Init Mode.*/
    REG_SET_FIELD(cdp->can->CCCR, FDCAN_CCCR_ASM, 0U);
    REG_SET_FIELD(cdp->can->CCCR, FDCAN_CCCR_INIT, 0U);

    while ((cdp->can->CCCR & FDCAN_CCCR_INIT) != 0U) {}
}

/**
 * @brief   Adds a filter (standard or extended).
 * @note    This configuration becomes effective after can_start.
 *
 * @param[out] cdp            pointer to a @p can_driver_t structure
 * @param[in] id1             filter ID1
 * @param[in] id2             filter ID2 or ID1 mask
 * @param[in] msg_filter_type Standard/Extended MessageID filter type. It can
 *                            be one of the following values:
 *            @arg @ref CAN_STD_FILTER_TYPE
 *            @arg @ref CAN_XTD_FILTER_TYPE
 * @param[in] filter_type     Standard/Extended filter type. It can be one of
 *                            the following values:
 *            @arg @ref CAN_FILTER_RANGE
 *            @arg @ref CAN_FILTER_DUALID
 *            @arg @ref CAN_FILTER_CLASSIC
 * @param[in] fec_type        Standard/Extended filter element type. It can be
 *                            one of the following values:
 *            @arg @ref CAN_FEC_DIS
 *            @arg @ref CAN_FEC_FIFO0
 *            @arg @ref CAN_FEC_FIFO1
 *            @arg @ref CAN_FEC_REJ_ONMATCH
 *            @arg @ref CAN_FEC_PRIO_ONMATCH
 *            @arg @ref CAN_FEC_PRIO_FIFO0
 *            @arg @ref CAN_FEC_PRIO_FIFO1
 *            @arg @ref CAN_FEC_RX_BUF
 * @return                    operation status (true if the filter is correctly
 *                            set, false otherwise).
 *
 * @notapi
 */
static bool can_lld_set_filter(can_driver_t *cdp, uint32_t id1,
                               uint32_t id2,
                               can_msg_filter_type_t msg_filter_type,
                               can_filter_type_t filter_type,
                               can_fec_type_t fec_type) {

    unsigned int i;

    if ((id1 == 0U) && (id2 == 0U)) {
        return false;
    }

    if (msg_filter_type == CAN_XTD_FILTER_TYPE) {
        /* Search for extended filter.*/
        for (i = 0; i < CAN_SUB_MAX_XTD_FILTERS ; i++) {
            if (cdp->xtd_filter[i].FID1 == 0U) {
                break;
            }
        }
        /* If no more extended filters can be applied, return.*/
        if (i == CAN_SUB_MAX_XTD_FILTERS) {
            return false;
        }
        cdp->xtd_filter[i].FID1 = id1;
        cdp->xtd_filter[i].FID2 = id2;
        cdp->xtd_filter[i].FT   = filter_type;
        cdp->xtd_filter[i].FEC  = fec_type;
        cdp->xtd_filter_num++;
    } else {
        /* Search for standard filter.*/
        for (i = 0; i < CAN_SUB_MAX_STD_FILTERS ; i++) {
            if (cdp->std_filter[i].FID1 == 0U) {
                break;
            }
        }
        /* If no more standard filters can be applied, return.*/
        if (i == CAN_SUB_MAX_STD_FILTERS) {
            return false;
        }
        cdp->std_filter[i].FID1 = id1;
        cdp->std_filter[i].FID2 = id2;
        cdp->std_filter[i].FT   = filter_type;
        cdp->std_filter[i].FEC  = fec_type;
        cdp->std_filter_num++;
    }

    return true;
}

/**
 * @brief   Writes data into TX buffer.
 *
 * @param[in] cdp       pointer to an @p can_driver_t structure
 * @param[in] msgbuf    TX message buffer to be written
 * @param[in] frame     pointer to frame to be written
 *
 * @notapi
 */
static void can_lld_write_buffer(can_driver_t *cdp, uint8_t msgbuf, const can_frame_t *frame) {

    uint32_t addr, msg_ram_base_addr;
    uint32_t msgbuf_pointer;

    msg_ram_base_addr = can_dev_get_msg_ram_address(cdp);

    msgbuf_pointer = (uint32_t)((8U + ((uint32_t)cdp->datasize)) * msgbuf);

    addr = msg_ram_base_addr + ((uint32_t)(REG_READ_FIELD(cdp->can->TXBC, FDCAN_TXBC_TBSA)) << CAN_SA_BIT) + msgbuf_pointer;

    /* Write frame into TX buffer.*/
    (void)can_lld_frame2data(cdp, frame, (uint32_t *)addr);
}

/**
 * @brief   Writes data into DMU TX buffer.
 *
 * @param[in] cdp       pointer to an @p can_driver_t structure
 * @param[in] frame     pointer to frame to be written
 *
 * @notapi
 */
static void can_lld_write_dmu(can_driver_t *cdp, const can_frame_t *frame) {

    uint32_t data[18];

    /* Write frame into data buffer, then transfer it via DMA.*/
    /* The number of words to transmit via DMA are:
       - 1 word for ID
       - 1 word for Data Length
       - data_size words for Data. */
    (void)can_lld_frame2data(cdp, frame, data);

    /* Configure DMA stream memory address for DMU TX FIFO/QUEUE.*/
    dma_stream_set_memory(cdp->dma_tx_descriptor, (uint32_t)(data));

    /* Enable DMA for DMU TX FIFO/QUEUE. It will be disabled on the DMA end of
       transfer.*/
    dma_stream_enable(cdp->dma_tx_descriptor);
}

/**
 * @brief   Transmits a CAN frame.
 *
 * @param[in] cdp       pointer to a @p can_driver_t structure
 * @param[in] msgbuf    It can be a number X in the range [0:31] to transmit
 *                      via the dedicated buffer X, or one of the following
 *                      values:
 *            @arg @ref CAN_TX_ANY_BUFFER to trasmit via any dedicated buffer
 *            @arg @ref CAN_TX_FIFO       to transmit via FIFO
 *            @arg @ref CAN_TX_QUEUE      to trasmit via Queue
 * @param[in] frame     pointer to frame to be transmitted
 * @return              operation status (true if the frame is correctly
 *                      transmitted, false otherwise).
 *
 * @notapi
 */
static bool can_lld_transmit(can_driver_t *cdp, uint8_t msgbuf,
                             can_frame_t *frame) {

    uint32_t i;
    uint8_t txbuffer;

    txbuffer = 0xFFU;

    /* Check if frame size is correct.*/
    if ((frame->DLC > 8U) && (cdp->is_fd_mode == false)) {
        return false;
    }

    /* Size allowed are 8, 12, 16, 20, 24, 32, 48, 64.*/
    if (can_lld_get_dlc(frame->DLC) == 0U) {
        return false;
    }

    /* Send message using FIFO.*/
    if (msgbuf == CAN_TX_FIFO) {
        if ((cdp->tx_mode != CAN_TX_MODE_FIFO) && (cdp->tx_mode != CAN_TX_MODE_MIXED_FIFO)) {
            return false;
        } else {
            if (cdp->is_dmu_mode == false) {
                /* If FIFO is not full, set the first available txbuffer to write,
                   otherwise return.*/
                if ((cdp->can->TXFQS & FDCAN_TXFQS_TFQF) == 0UL) {
                    txbuffer = (uint8_t)REG_READ_FIELD(cdp->can->TXFQS, FDCAN_TXFQS_TFQPI);
                }
            /* FIFO transmission via DMU.*/
            } else {
                /* Write DMU TX Buffer.*/
                can_lld_write_dmu(cdp, frame);
                return true;
            }
        }
    /* Send message using Queue.*/
    } else if (msgbuf == CAN_TX_QUEUE) {
        if ((cdp->tx_mode != CAN_TX_MODE_QUEUE) && (cdp->tx_mode != CAN_TX_MODE_MIXED_QUEUE)) {
            return false;
        } else {
            if (cdp->is_dmu_mode == false) {
                /* If queue is not full, set the first available txbuffer to write,
                   otherwise return.*/
                if ((cdp->can->TXFQS & FDCAN_TXFQS_TFQF) == 0UL) {
                    txbuffer = (uint8_t)REG_READ_FIELD(cdp->can->TXFQS, FDCAN_TXFQS_TFQPI);
                }
            /* QUEUE transmission via DMU.*/
            } else {
                /* Write DMU TX Buffer.*/
                can_lld_write_dmu(cdp, frame);
                return true;
            }
        }
    /* Send message using dedicated TX buffers.*/
    } else {
        if ((cdp->tx_mode == CAN_TX_MODE_FIFO) || (cdp->tx_mode == CAN_TX_MODE_QUEUE)) {
            return false;
        }
        /* If CAN_TX_ANY_BUFFER, search the first TX buffer free ...*/
        if (msgbuf == CAN_TX_ANY_BUFFER) {
            for (i = 0; i < cdp->tx_buff_num; i++) {
                if (((cdp->can->TXBRP) & (1UL << i)) == 0U) {
                    txbuffer = (uint8_t)i;
                    break;
                }
            }
        /* ...otherwise check if msgbox if free to transmit.*/
        } else {
            if (((cdp->can->TXBRP) & (1UL << msgbuf)) == 0U) {
                txbuffer = (uint8_t)msgbuf;
            }
        }
    }

    /* If txbuffer value is not assigned, no TX buffer available.*/
    if (txbuffer == 0xFFU) {
        return false;
    } else {
        /* Write TX Buffer.*/
        can_lld_write_buffer(cdp, txbuffer, frame);

        /* Send message.*/
        cdp->can->TXBAR = (1UL << txbuffer);
    }

    return true;
}

/**
 * @brief   Reads data from RX buffer.
 *
 * @param[in] cdp       pointer to an @p can_driver_t structure
 * @param[in] rx_mode   reception mode. It can be one of the following values:
 *            @arg @ref CAN_RX_MODE_DEDICATED_BUFF
 *            @arg @ref CAN_RX_MODE_FIFO0
 *            @arg @ref CAN_RX_MODE_FIFO1
 * @param[in] msgbuf    RX message buffer to be read
 * @param[in] frame     pointer to frame to be read
 *
 * @notapi
 */
static void can_lld_read_buffer(can_driver_t *cdp, can_rx_mode_t rx_mode, uint32_t msgbuf, can_frame_t *frame) {

    uint32_t addr, msg_ram_base_addr;

    msg_ram_base_addr = can_dev_get_msg_ram_address(cdp);

    /* Set shared RAM address according to the RX mode.*/
    switch (rx_mode) {
    case CAN_RX_MODE_DEDICATED_BUFF:
        addr = msg_ram_base_addr + ((uint32_t)(REG_READ_FIELD(cdp->can->RXBC, FDCAN_RXBC_RBSA)) << CAN_SA_BIT) + ((8UL + ((uint8_t)cdp->datasize)) * msgbuf);
        break;
    case CAN_RX_MODE_FIFO0:
        addr = msg_ram_base_addr + ((uint32_t)(REG_READ_FIELD(cdp->can->RXF0C, FDCAN_RXF0C_F0SA)) << CAN_SA_BIT) + ((8UL + ((uint8_t)cdp->datasize)) * msgbuf);
        break;
    case CAN_RX_MODE_FIFO1:
        addr = msg_ram_base_addr + ((uint32_t)(REG_READ_FIELD(cdp->can->RXF1C, FDCAN_RXF1C_F1SA)) << CAN_SA_BIT) + ((8UL + ((uint8_t)cdp->datasize)) * msgbuf);
        break;
    default:
        addr = 0;
        break;
    }
    
    /* Read frame.*/
    (void)can_lld_data2frame((uint32_t *)addr, frame);
}

/**
 * @brief   Receives a CAN frame.
 *
 * @param[in] cdp       pointer to a @p can_driver_t structure
 * @param[in] msgbuf    It can be a number X in the range [0:31] to receive
 *                      via the dedicated buffer X, or one of the following
 *                      values:
 *            @arg @ref CAN_RX_ANY_BUFFER to receive via any dedicated buffer
 *            @arg @ref CAN_RX_FIFO0      to receive via FIFO 0
 *            @arg @ref CAN_RX_FIFO1      to receive via FIFO 1
 * @param[in] frame     pointer to frame to be received
 * @return              operation status (true if the frame is correctly
 *                      received, false otherwise).
 *
 * @api
 */
static bool can_lld_receive(can_driver_t *cdp, uint8_t msgbuf, can_frame_t *frame) {

    uint32_t i;
    uint8_t rxbuffer = 0xFFU;

    /* Read from FIFO0.*/
    if (msgbuf == CAN_RX_FIFO0) {
        if ((cdp->can->RXF0S & FDCAN_RXF0S_F0FL) == 0U) {
            return false;
        }
    
        rxbuffer = (uint8_t)(REG_READ_FIELD(cdp->can->RXF0S, FDCAN_RXF0S_F0GI));

        /* Read message from FIFO0.*/
        can_lld_read_buffer(cdp, CAN_RX_MODE_FIFO0, rxbuffer, frame);

        /* Release FIFO0 RX buffer.*/
        REG_SET_FIELD(cdp->can->RXF0A, FDCAN_RXF0A_F0AI, rxbuffer);

    /* Read from FIFO1.*/
    } else if (msgbuf == CAN_RX_FIFO1) {
        if ((cdp->can->RXF1S & FDCAN_RXF1S_F1FL) == 0U) {
            return false;
        }
    
        rxbuffer = (uint8_t)(REG_READ_FIELD(cdp->can->RXF1S, FDCAN_RXF1S_F1GI));

        /* Read message from FIFO1.*/
        can_lld_read_buffer(cdp, CAN_RX_MODE_FIFO1, rxbuffer, frame);

        /* Release FIFO1 RX buffer.*/
        REG_SET_FIELD(cdp->can->RXF1A, FDCAN_RXF1A_F1AI, rxbuffer);

    } else {
        /* Read from first dedicated RX buffer available.*/
        if (msgbuf == CAN_RX_ANY_BUFFER) {
            for (i = 0; i < cdp->rx_buff_num; i++) {
                if (((cdp->can->NDAT1) & (1UL << i)) != 0U) {
                    rxbuffer = (uint8_t)i;
                    break;
                }
            }
        } else {
            /* Read from specific RX buffer.*/
            if (((cdp->can->NDAT1) & (1UL << msgbuf)) != 0U) {
                rxbuffer = (uint8_t)msgbuf;
            }
        }
        /* If RX buffer value is not assigned, no RX buffer available.*/
        if (rxbuffer == 0xFFU) {
            return false;
        } else {
            /* Read Message.*/
            can_lld_read_buffer(cdp, CAN_RX_MODE_DEDICATED_BUFF, rxbuffer, frame);

            /* Release RX buffer.*/
            cdp->can->NDAT1 = (1UL << rxbuffer);
        }
    }

    return true;
}

/**
 * @brief   Returns CAN version.
 *
 * @param[in] cdp       pointer to an @p can_driver_t structure
 * @return              CAN version.
 *
 * @notapi
 */
static uint16_t can_lld_version(can_driver_t *cdp) {

    /* Return (VER | STEP | SUBSTEP) e.g. 0x330 for MCAN 3.3.0 */
    return (uint16_t)(cdp->can->CREL >> FDCAN_TSU_CREL_SUBSTEP_Pos);
}

/**
 * @brief   Resets CAN parameters.
 *
 * @param[out] cdp      pointer to an @p can_driver_t structure
 *
 * @notapi
 */
static void can_reset_paramters(can_driver_t *cdp) {

    uint8_t i;

    /* Set all driver configuration parameters to default values.*/

    cdp->prio                   = IRQ_MIN_PRIORITY;
    cdp->irq_line               = CAN_IRQ_LINE0;
    cdp->irq_mask               = CAN_IRQ_ALL_DISABLED;
    /* Set shared RAM start addredd and size to the default values.*/
    cdp->ram_start              = can_dev_get_ram_start(cdp);
    cdp->ram_size               = can_dev_get_ram_size(cdp);
    cdp->lb_mode                = CAN_NO_LOOPBACK;
    cdp->is_fd_mode             = false;
    cdp->is_fd_brs_mode         = false;
    cdp->nbtp.nbrp              = 0U;
    cdp->nbtp.ntseg1            = 0U;
    cdp->nbtp.ntseg2            = 0U;
    cdp->nbtp.nsjw              = 0U;
    cdp->dbtp.dbrp              = 0U;
    cdp->dbtp.dtseg1            = 10U;
    cdp->dbtp.dtseg2            = 3U;
    cdp->dbtp.dsjw              = 3U;
    cdp->tdc.is_tdc_en          = false;
    cdp->tdc.tdco               = 0U;
    cdp->tdc.tdcf               = 0U;
    cdp->datasize               = CAN_DATASIZE_8BYTE;
    for (i = 0U; i < CAN_SUB_MAX_STD_FILTERS; i++) {
        cdp->std_filter[i].FID1 = 0U;
        cdp->std_filter[i].FID2 = 0U;
        cdp->std_filter[i].FT   = CAN_FILTER_RANGE;
        cdp->std_filter[i].FEC  = CAN_FEC_DIS;
    }
    for (i = 0U; i < CAN_SUB_MAX_XTD_FILTERS; i++) {
        cdp->xtd_filter[i].FID1 = 0U;
        cdp->xtd_filter[i].FID2 = 0U;
        cdp->xtd_filter[i].FT   = CAN_FILTER_RANGE;
        cdp->xtd_filter[i].FEC  = CAN_FEC_DIS;
    }
    cdp->std_filter_num         = 0U;
    cdp->xtd_filter_num         = 0U;
    cdp->rx_buff_num            = 0U;
    cdp->tx_buff_num            = 0U;
    cdp->rx_fifo0_num           = 0U;
    cdp->rx_fifo1_num           = 0U;
    cdp->tx_fifoq_num           = 0U;
    cdp->is_rx_polling_mode     = true;
    cdp->tx_mode                = CAN_TX_MODE_DEDICATED_BUFF;
    cdp->is_dmu_mode            = false;
    cdp->dma_conf               = NULL;
    cdp->dma_rx0_descriptor     = NULL;
    cdp->dma_rx1_descriptor     = NULL;
    cdp->dma_tx_descriptor      = NULL;
    cdp->cb                     = NULL;
    cdp->err_cb                 = NULL;
}

/*===========================================================================*/
/* Module exported functions.                                                */
/*===========================================================================*/

void can_init(can_driver_t *cdp) {

    /* Set pointer to CAN register block.*/
    cdp->can   = can_dev_get_reg_ptr(cdp);
    /* Set CAN clock value based on clocktree configuration.*/
    cdp->clock = can_dev_get_clock(cdp);

    /* Reset CAN parameters.*/
    can_reset_paramters(cdp);
}

uint32_t can_set_prio(can_driver_t *cdp, uint32_t prio) {

    uint32_t prev_prio;

    prev_prio = cdp->prio;
    cdp->prio = prio;

    return prev_prio;
}

can_irq_line_t can_set_irq_line(can_driver_t *cdp, can_irq_line_t irq_line) {

    can_irq_line_t prev_irq_line;

    prev_irq_line = cdp->irq_line;
    cdp->irq_line = irq_line;

    return prev_irq_line;
}

uint32_t can_set_irq_mask(can_driver_t *cdp, uint32_t irq_mask) {

    uint32_t prev_irq_mask;

    prev_irq_mask = cdp->irq_mask;
    cdp->irq_mask = irq_mask;

    return prev_irq_mask;

}

void can_set_ram(can_driver_t *cdp, uint32_t ram_start, uint32_t ram_size) {

    cdp->ram_start = ram_start;
    cdp->ram_size  = ram_size;
}

can_lb_mode_t can_set_loopback(can_driver_t *cdp, can_lb_mode_t lb_mode) {

    can_lb_mode_t prev_lb_mode;

    prev_lb_mode = cdp->lb_mode;
    cdp->lb_mode = lb_mode;

    return prev_lb_mode;
}

bool can_set_fd_mode(can_driver_t *cdp, bool is_fd_mode) {

    bool prev_is_fd_mode;

    prev_is_fd_mode = cdp->is_fd_mode;
    cdp->is_fd_mode = is_fd_mode;

    return prev_is_fd_mode;
}

bool can_set_fd_brs_mode(can_driver_t *cdp, bool is_fd_brs_mode) {

    bool prev_is_fd_brs_mode;

    prev_is_fd_brs_mode = cdp->is_fd_brs_mode;
    cdp->is_fd_brs_mode = is_fd_brs_mode;

    return prev_is_fd_brs_mode;
}

bool can_set_baudrate(can_driver_t *cdp, can_baudrate_t baudrate) {

    return can_lld_set_baudrate(cdp, baudrate);
}

void can_set_nbtp(can_driver_t *cdp, uint16_t nbrp, uint8_t ntseg1,
                  uint8_t ntseg2, uint8_t nsjw) {

    cdp->nbtp.nbrp   = nbrp;
    cdp->nbtp.ntseg1 = ntseg1;
    cdp->nbtp.ntseg2 = ntseg2;
    cdp->nbtp.nsjw   = nsjw;
}

void can_set_dbtp(can_driver_t *cdp, uint8_t dbrp, uint8_t dtseg1,
                  uint8_t dtseg2, uint8_t dsjw) {

    cdp->dbtp.dbrp   = dbrp;
    cdp->dbtp.dtseg1 = dtseg1;
    cdp->dbtp.dtseg2 = dtseg2;
    cdp->dbtp.dsjw   = dsjw;
}

bool can_enable_tdc(can_driver_t *cdp, bool enable) {

    bool prev_is_tdc_en;

    prev_is_tdc_en = cdp->tdc.is_tdc_en;
    cdp->tdc.is_tdc_en = enable;

    return prev_is_tdc_en;
}

void can_set_tdc(can_driver_t *cdp, uint8_t tdco, uint8_t tdcf) {

    cdp->tdc.tdco = tdco;
    cdp->tdc.tdcf = tdcf;
}

can_datasize_t can_set_datasize(can_driver_t *cdp, can_datasize_t datasize) {

    can_datasize_t prev_datasize;

    prev_datasize = cdp->datasize;
    cdp->datasize = datasize;

    return prev_datasize;
}

bool can_set_filter(can_driver_t *cdp, uint32_t id1, uint32_t id2,
                    can_msg_filter_type_t msg_filter_type,
                    can_filter_type_t filter_type, can_fec_type_t fec_type) {

    return can_lld_set_filter(cdp, id1, id2, msg_filter_type, filter_type, fec_type);
}

void can_set_buffers(can_driver_t *cdp, uint8_t rx_buff_num,
                     uint8_t tx_buff_num, uint8_t rx_fifo0_num,
                     uint8_t rx_fifo1_num, uint8_t tx_fifoq_num) {

    cdp->rx_buff_num  = rx_buff_num;
    cdp->tx_buff_num  = tx_buff_num;
    cdp->rx_fifo0_num = rx_fifo0_num;
    cdp->rx_fifo1_num = rx_fifo1_num;
    cdp->tx_fifoq_num = tx_fifoq_num;
}

bool can_set_rx_polling_mode(can_driver_t *cdp, bool is_rx_polling_mode) {

    bool prev_is_rx_polling_mode;

    prev_is_rx_polling_mode = cdp->is_rx_polling_mode;
    cdp->is_rx_polling_mode = is_rx_polling_mode;

    return prev_is_rx_polling_mode;
}

can_tx_mode_t can_set_tx_mode(can_driver_t *cdp, can_tx_mode_t tx_mode) {

    can_tx_mode_t prev_tx_mode;

    prev_tx_mode = cdp->tx_mode;
    cdp->tx_mode = tx_mode;

    return prev_tx_mode;

}

bool can_set_dmu_mode(can_driver_t *cdp, bool is_dmu_mode) {

    bool prev_is_dmu_mode;

    prev_is_dmu_mode = cdp->is_dmu_mode;
    cdp->is_dmu_mode = is_dmu_mode;

    return prev_is_dmu_mode;
}

can_dma_conf_t *can_set_dma_conf(can_driver_t *cdp, can_dma_conf_t *dma_conf) {

    can_dma_conf_t *prev_dma_conf;

    prev_dma_conf = cdp->dma_conf;
    cdp->dma_conf = dma_conf;

    return prev_dma_conf;
}

can_cb_t can_set_cb(can_driver_t *cdp, can_cb_t cb) {

    can_cb_t prev_cb;

    prev_cb = cdp->cb;
    cdp->cb = cb;

    return prev_cb;
}

can_err_cb_t can_set_err_cb(can_driver_t *cdp, can_err_cb_t err_cb) {

    can_err_cb_t prev_err_cb;

    prev_err_cb = cdp->err_cb;
    cdp->err_cb = err_cb;

    return prev_err_cb;
}

void can_start(can_driver_t *cdp) {

    IRQn_Type vector;

    /* Enable clock.*/
    can_dev_clock_enable(cdp);

    /* Enable CAN LINE0/LINE1 interrupt.*/
    if (cdp->irq_line == CAN_IRQ_LINE0) {
        vector = can_dev_get_line0_vector(cdp);
    } else {
        vector = can_dev_get_line1_vector(cdp);
    }
    irq_set_priority(vector, cdp->prio);
    irq_enable(vector);

    /* Enable CAN DMU interrupt.*/
    if (cdp->is_dmu_mode == true) {
        vector = can_dev_get_dmu_vector(cdp);
        irq_set_priority(vector, cdp->prio);
        irq_enable(vector);
    }

    /* Start CAN hardware controller.*/
    can_lld_start(cdp);
}

bool can_transmit(can_driver_t *cdp, uint8_t msgbuf, can_frame_t *frame) {

    return can_lld_transmit(cdp, msgbuf, frame);
}

bool can_receive(can_driver_t *cdp, uint8_t msgbuf, can_frame_t *frame) {

    return can_lld_receive(cdp, msgbuf, frame);
}

bool can_get_bo_status(can_driver_t *cdp) {

    if ((cdp->can->PSR & FDCAN_PSR_BO) != 0U) {
        return true;
    } else {
        return false;
    }
}

uint16_t can_get_version(can_driver_t *cdp) {

    return can_lld_version(cdp);
}

void can_stop(can_driver_t *cdp) {

    IRQn_Type vector;

    /* Disable CAN LINE0/LINE1 interrupt.*/
    if (cdp->irq_line == CAN_IRQ_LINE0) {
        vector = can_dev_get_line0_vector(cdp);
    } else {
        vector = can_dev_get_line1_vector(cdp);
    }
    irq_disable(vector);

    /* Disable CAN DMU interrupt.*/
    if (cdp->is_dmu_mode == true) {
        vector = can_dev_get_dmu_vector(cdp);
        irq_disable(vector);
    }

    /* Clear interrupt register.*/
    cdp->can->IR  = 0xFFFFFFFFUL;

    /* Disable interrupts.*/
    cdp->can->IE  = 0x0UL;
    cdp->can->ILS = 0x0UL;

    /* Clear RX buffers.*/
    cdp->can->NDAT1 = 0xFFFFFFFFUL;
    cdp->can->NDAT2 = 0xFFFFFFFFUL;

    /* Disable clock.*/
    can_dev_clock_disable(cdp);
}

void can_deinit(can_driver_t *cdp) {

    /* Set pointer to CAN register block to NULL.*/
    cdp->can   = NULL;
    /* Set CAN clock value to default value.*/
    cdp->clock = 0UL;

    /* Reset CAN parameters.*/
    can_reset_paramters(cdp);
}

void __can_serve_interrupt(can_driver_t *cdp, can_irq_line_t irq_line) {

    can_frame_t frame = {0};
    uint8_t msgbuf = 0;

    /* Check if transmission completed interrupt occurred.*/
    if ((cdp->can->IR & FDCAN_IR_TC) != 0U) {
        if (REG_READ_FIELD(cdp->can->ILS, FDCAN_ILS_TCL) == (uint8_t)irq_line) {

            /* Invoke callback if it is configured.*/
            if (cdp->cb != NULL) {
                /* Callback is called with the frame as data.*/
                cdp->cb(cdp, frame, CAN_CB_TX);
            }
            /* Clear flag.*/
            cdp->can->IR |= FDCAN_IR_TC;
        }
    }

    /* Check if TX FIFO empty interrupt occurred.*/
    if ((cdp->can->IR & FDCAN_IR_TFE) != 0U) {
        if (REG_READ_FIELD(cdp->can->ILS, FDCAN_ILS_TFEL) == (uint8_t)irq_line) {
            /* Invoke callback if it is configured.*/
            if (cdp->cb != NULL) {
                cdp->cb(cdp, frame, CAN_CB_TX_FIFO_EMPTY);
            }
            /* Clear flag.*/
            cdp->can->IR |= FDCAN_IR_TFE;
        }
    }

    /* Check if RX buffer interrupt occurred.*/
    if ((cdp->can->IR & FDCAN_IR_DRX) != 0U) {
        if (REG_READ_FIELD(cdp->can->ILS, FDCAN_ILS_DRXL) == (uint8_t)irq_line) {
            /* Check if polling mode is not active.*/
            if (cdp->is_rx_polling_mode == false) {
                for (msgbuf = 0; msgbuf < cdp->rx_buff_num; msgbuf++) {
                    if (((cdp->can->NDAT1) & (1UL << msgbuf)) != 0U) {
                        break;
                    }
                }
                /* Read message.*/
                can_lld_read_buffer(cdp, CAN_RX_MODE_DEDICATED_BUFF, msgbuf, &frame);
                /* Release RX buffer.*/
                cdp->can->NDAT1 = (1UL << msgbuf);
            }
            /* Invoke callback if it is configured.*/
            if (cdp->cb != NULL) {
                /* Callback is called with the frame as data.*/
                cdp->cb(cdp, frame, CAN_CB_RX);
            }
            /* Clear flag.*/
            cdp->can->IR |= FDCAN_IR_DRX;
        }
    }

    /* Check if FIFO 0 lost interrupt occurred.*/
    if ((cdp->can->IR & FDCAN_IR_RF0L) != 0U) {
        if (REG_READ_FIELD(cdp->can->ILS, FDCAN_ILS_RF0LL) == (uint8_t)irq_line) {
            /* Invoke callback if it is configured.*/
            if (cdp->cb != NULL) {
                cdp->cb(cdp, frame, CAN_CB_FIFO0_LOST);
            }
            /* Clear flag.*/
            cdp->can->IR |= FDCAN_IR_RF0L;
        }
    }

    /* Check if FIFO 0 full interrupt.*/
    if ((cdp->can->IR & FDCAN_IR_RF0F) != 0U) {
        if (REG_READ_FIELD(cdp->can->ILS, FDCAN_ILS_RF0FL) == (uint8_t)irq_line) {
            /* Invoke callback if it is configured.*/
            if (cdp->cb != NULL) {
                cdp->cb(cdp, frame, CAN_CB_FIFO0_FULL);
            }
            /* Clear flag */
            cdp->can->IR |= FDCAN_IR_RF0F;
        }
    }

    /* Check if FIFO 0 watermark interrupt occurred.*/
    if ((cdp->can->IR & FDCAN_IR_RF0W) != 0U) {
        if (REG_READ_FIELD(cdp->can->ILS, FDCAN_ILS_RF0WL) == (uint8_t)irq_line) {
            /* Invoke callback if it is configured.*/
            if (cdp->cb != NULL) {
                cdp->cb(cdp, frame, CAN_CB_FIFO0_WATERMARK);
            }
            /* Clear flag.*/
            cdp->can->IR |= FDCAN_IR_RF0W;
        }
    }

    /* Check if RX FIFO 0 interrupt occurred.*/
    if (((cdp->can->IR & FDCAN_IR_RF0N) != 0U) && (cdp->is_dmu_mode == false)) {
        if (REG_READ_FIELD(cdp->can->ILS, FDCAN_ILS_RF0NL) == (uint8_t)irq_line) {
            /* Check if polling mode is not active.*/
            if (cdp->is_rx_polling_mode == false) {
                msgbuf = (uint8_t)REG_READ_FIELD(cdp->can->RXF0S, FDCAN_RXF0S_F0GI);
                /* Read message.*/
                can_lld_read_buffer(cdp, CAN_RX_MODE_FIFO0, msgbuf, &frame);
                /* Release RX buffer.*/
                REG_SET_FIELD(cdp->can->RXF0A, FDCAN_RXF0A_F0AI, msgbuf);
            }
            /* Invoke callback if it is configured.*/
            if (cdp->cb != NULL) {
                /* Callback is called with the frame as data.*/
                cdp->cb(cdp, frame, CAN_CB_FIFO0_NEW_MSG);
            }
            /* Clear flag.*/
            cdp->can->IR |= FDCAN_IR_RF0N;
        }
    }

    /* Check if FIFO 1 lost interrupt occurred.*/
    if ((cdp->can->IR & FDCAN_IR_RF1L) != 0U) {
        if (REG_READ_FIELD(cdp->can->ILS, FDCAN_ILS_RF1LL) == (uint8_t)irq_line) {
            /* Invoke callback if it is configured.*/
            if (cdp->cb != NULL) {
                cdp->cb(cdp, frame, CAN_CB_FIFO1_LOST);
            }
            /* Clear flag.*/
            cdp->can->IR |= FDCAN_IR_RF1L;
        }
    }

    /* Check if FIFO 1 full interrupt occurred.*/
    if ((cdp->can->IR & FDCAN_IR_RF1F) != 0U) {
        if (REG_READ_FIELD(cdp->can->ILS, FDCAN_ILS_RF1FL) == (uint8_t)irq_line) {
            /* Invoke callback if it is configured.*/
            if (cdp->cb != NULL) {
                cdp->cb(cdp, frame, CAN_CB_FIFO1_FULL);
            }
            /* Clear flag.*/
            cdp->can->IR |= FDCAN_IR_RF1F;
        }
    }

    /* Check if FIFO 1 watermark interrupt occurred.*/
    if ((cdp->can->IR & FDCAN_IR_RF1W) != 0U) {
        if (REG_READ_FIELD(cdp->can->ILS, FDCAN_ILS_RF1WL) == (uint8_t)irq_line) {
            /* Invoke callback if it is configured.*/
            if (cdp->cb!= NULL) {
                cdp->cb(cdp, frame, CAN_CB_FIFO1_WATERMARK);
            }
            /* Clear flag */
            cdp->can->IR |= FDCAN_IR_RF1W;
        }
    }

    /* Check if RX FIFO 1 interrupt occurred.*/
    if (((cdp->can->IR & FDCAN_IR_RF1N) != 0U) && (cdp->is_dmu_mode == false)) {
        if (REG_READ_FIELD(cdp->can->ILS, FDCAN_ILS_RF1NL) == (uint8_t)irq_line) {
            /* Check if polling mode is not active.*/
            if (cdp->is_rx_polling_mode == false) {
                msgbuf = (uint8_t)REG_READ_FIELD(cdp->can->RXF1S, FDCAN_RXF1S_F1GI);
                /* Read message.*/
                can_lld_read_buffer(cdp, CAN_RX_MODE_FIFO1, msgbuf, &frame);
                /* Release RX buffer.*/
                REG_SET_FIELD(cdp->can->RXF1A, FDCAN_RXF1A_F1AI, msgbuf);
            }
            /* Invoke callback if it is configured.*/
            if (cdp->cb != NULL) {
                cdp->cb(cdp, frame, CAN_CB_FIFO1_NEW_MSG);
            }
            /* Clear flag.*/
            cdp->can->IR |= FDCAN_IR_RF1N;
        }
    }

    /* Error check.*/
    if ((cdp->can->IR & CAN_IRQ_ERROR_MASK) != 0U) {
        uint32_t psr = (uint32_t)cdp->can->PSR;
        if (cdp->err_cb != NULL) {
            cdp->err_cb(cdp, psr);
        }
        /* BUSOFF interrupt management.*/
        if ((cdp->can->IR & FDCAN_IR_BO) != 0U) {
            /* Start Bus Off status exit sequence.*/
            REG_SET_FIELD(cdp->can->CCCR, FDCAN_CCCR_INIT, 0U);
        }
        /* Reset all error bits checked.*/
        cdp->can->IR = CAN_IRQ_ERROR_MASK;
    }
}

void __can_serve_dmu_interrupt(can_driver_t *cdp) {

    can_frame_t frame = {0};

    /* Check if DMU transmission is completed.*/
    if ((cdp->can->DMU_IR & FDCAN_DMU_IR_TXEE) != 0U) {
        if (cdp->cb != NULL) {
            cdp->cb(cdp, frame, CAN_CB_DMU_TX);
        }
        cdp->can->DMU_IR |= FDCAN_DMU_IR_TXEE;
    }
}

/** @} */
