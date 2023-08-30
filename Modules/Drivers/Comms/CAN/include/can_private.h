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
 * @file    can_private.h
 * @brief   CAN driver private header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup COMMS
 * @ingroup DRIVERS
 * @addtogroup CAN
 * @ingroup COMMS
 * @{
 */

#ifndef _CAN_PRIVATE_H_
#define _CAN_PRIVATE_H_

#include <dma.h>
#include <irq.h>
#include <platform.h>

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Module pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Module data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   CAN driver structure.
 * @note    This structure is internal to the CAN driver.
 */
struct can_driver {
    /**
     * @brief  Pointer to CAN registers block.
     */
    FDCAN_TypeDef            *can;
    /**
     * @brief   CAN clock value (MHz).
     */
    uint32_t                 clock;
    /**
     * @brief   CAN interrupt priority.
     */
    uint32_t                 prio;
    /**
     * @brief   Interrupt line.
     */
    can_irq_line_t           irq_line;
    /**
     * @brief   Interrupt mask.
     */
    uint32_t                 irq_mask;
    /**
     * @brief   Internal shared RAM address.
     */
    uint32_t                 ram_start;
    /**
     * @brief   Internal shared RAM size.
     */
    uint32_t                 ram_size;
    /**
     * @brief   Loopback mode.
     */
    can_lb_mode_t            lb_mode;
    /**
     * @brief   CANFD enable flag.
     */
    bool                     is_fd_mode;
    /**
     * @brief   CANFD bit rate switch enable flag.
     */
    bool                     is_fd_brs_mode;
    /**
     * @brief   Nominal bit timing and prescaler.
     */
    can_nbtp_t               nbtp;
    /**
     * @brief   Data bit timing and prescaler (only for CAN-FD).
     */
    can_dbtp_t               dbtp;
    /**
     * @brief   Transciver delay compensation.
     */
    can_tdc_t                tdc;
    /**
     * @brief   Data field size.
     */
    can_datasize_t           datasize;
    /**
     * @brief   Standard filter table.
     */
    can_filter_t             std_filter[CAN_SUB_MAX_STD_FILTERS];
    /**
     * @brief   Extended filter table.
     */
    can_filter_t             xtd_filter[CAN_SUB_MAX_XTD_FILTERS];
    /**
     * @brief   Number of standard filters.
     */
    uint32_t                 std_filter_num;
    /**
     * @brief   Number of extended filters.
     */
    uint32_t                 xtd_filter_num;
    /**
     * @brief   Number of dedicated RX buffers.
     */
    uint8_t                  rx_buff_num;
    /**
     * @brief   Number of dedicated TX buffers.
     */
    uint8_t                  tx_buff_num;
    /**
     * @brief   Number of RX buffers in RX FIFO 0.
     */
    uint8_t                  rx_fifo0_num;
    /**
     * @brief   Number of RX buffers in RX FIFO 1.
     */
    uint8_t                  rx_fifo1_num;
    /**
     * @brief   Number of TX buffers in TX FIFO/Queue.
     */
    uint8_t                  tx_fifoq_num;
    /**
     * @brief   RX polling mode enable flag.
     */
    bool                     is_rx_polling_mode;
    /**
     * @brief   TX transmission mode.
     */
    can_tx_mode_t            tx_mode;
    /**
     * @brief   DMU mode enable flag.
     */
    bool                     is_dmu_mode;
    /**
     * @brief   DMA configuration.
     */
    can_dma_conf_t           *dma_conf;
    /**
     * @brief   Allocated RX DMA descriptor for DMU RX FIFO0.
     */
    const dma_descriptor_t   *dma_rx0_descriptor;
    /**
     * @brief   Allocated RX DMA descriptor for DMU RX FIFO1.
     */
    const dma_descriptor_t   *dma_rx1_descriptor;
    /**
     * @brief   Allocated TX DMA descriptor for DMU TX FIFO/QUEUE.
     */
    const dma_descriptor_t   *dma_tx_descriptor;
    /**
     * @brief   Notify callback.
     * @note    Set to @p NULL if not required.
     */
    can_cb_t                 cb;
    /**
     * @brief   Error callback.
     * @note    Set to @p NULL if not required.
     */
    can_err_cb_t             err_cb;
};

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

IRQ_HANDLER(IRQ_CAN1_LINE0_HANDLER);
IRQ_HANDLER(IRQ_CAN1_LINE1_HANDLER);
IRQ_HANDLER(IRQ_CAN1_DMU_HANDLER);
IRQ_HANDLER(IRQ_CAN2_LINE0_HANDLER);
IRQ_HANDLER(IRQ_CAN2_LINE1_HANDLER);
IRQ_HANDLER(IRQ_CAN2_DMU_HANDLER);
IRQ_HANDLER(IRQ_CAN3_LINE0_HANDLER);
IRQ_HANDLER(IRQ_CAN3_LINE1_HANDLER);
IRQ_HANDLER(IRQ_CAN3_DMU_HANDLER);
IRQ_HANDLER(IRQ_CAN4_LINE0_HANDLER);
IRQ_HANDLER(IRQ_CAN4_LINE1_HANDLER);
IRQ_HANDLER(IRQ_CAN4_DMU_HANDLER);

FDCAN_TypeDef *can_dev_get_reg_ptr(can_driver_t *cdp);
uint32_t can_dev_get_clock(can_driver_t *cdp);
void can_dev_clock_enable(can_driver_t *cdp);
void can_dev_clock_disable(can_driver_t *cdp);
uint32_t can_dev_get_dma_tx_trigger(can_driver_t *cdp);
uint32_t can_dev_get_dma_rx0_trigger(can_driver_t *cdp);
uint32_t can_dev_get_dma_rx1_trigger(can_driver_t *cdp);
IRQn_Type can_dev_get_line0_vector(can_driver_t *cdp);
IRQn_Type can_dev_get_line1_vector(can_driver_t *cdp);
IRQn_Type can_dev_get_dmu_vector(can_driver_t *cdp);
uint32_t can_dev_get_msg_ram_address(can_driver_t *cdp);
uint32_t can_dev_get_msg_ram_size(can_driver_t *cdp);
uint32_t can_dev_get_ram_start(can_driver_t *cdp);
uint32_t can_dev_get_ram_size(can_driver_t *cdp);

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/*===========================================================================*/
/* Module late inclusions.                                                   */
/*===========================================================================*/

#endif /* _CAN_PRIVATE_H_ */

/** @} */
