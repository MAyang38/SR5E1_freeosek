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
 * @file    uart_private.h
 * @brief   UART driver private header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup COMMS
 * @ingroup DRIVERS
 * @addtogroup UART
 * @ingroup COMMS
 * @{
 */

#ifndef _UART_PRIVATE_H_
#define _UART_PRIVATE_H_

#include <dma.h>

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
 * @brief   UART driver structure.
 * @note    This structure is internal to the UART driver.
 */
struct uart_driver {
    /**
     * @brief   Pointer to UART registers block.
     */
    UART_TypeDef             *uart;
    /**
     * @brief   UART Clock value.
     */
    uint32_t                 clock;
    /**
     * @brief   Pointer to transmission buffer.
     */
    uint8_t                  *tx_buf;
    /**
     * @brief   Transmission buffer length.
     */
    uint32_t                 tx_len;
    /**
     * @brief   Transmission in progress flag.
     */
    volatile uart_tx_sts_t   tx_busy;
    /**
     * @brief   Pointer to receiving buffer.
     */
    uint8_t                  *rx_buf;
    /**
     * @brief   Receiving buffer length.
     */
    uint32_t                 rx_len;
    /**
     * @brief  Receiving in progress flag.
     */
    volatile uart_rx_sts_t   rx_busy;
    /**
     * @brief   UART interrupt priority.
     */
    uint32_t                 prio;
    /**
     * @brief   RX driver mode.
     */
    uart_rx_drv_mode_t       rx_drv_mode;
    /**
     * @brief   TX driver mode.
     */
    uart_tx_drv_mode_t       tx_drv_mode;
    /**
     * @brief   FIFO Enable flag.
     */
    bool                     is_fifo_en;
    /**
     * @brief   RXFIFO threshold configuration.
     */
    uart_rx_fifo_thr_t       rxft;
    /**
     * @brief   TXFIFO threshold configuration.
     */
    uart_tx_fifo_thr_t       txft;
    /**
     * @brief   Number of elements available in the RX FIFO.
     */
    uint8_t                  rx_fifo_full;
    /**
     * @brief   Number of free elements in the TX FIFO.
     */
    uint8_t                  tx_fifo_empty;
    /**
     * @brief   DMA configuration.
     */
    uart_dma_conf_t          *dma_conf;
    /**
     * @brief   Allocated RX DMA descriptor.
     */
    const dma_descriptor_t   *dma_rx_descriptor;
    /**
     * @brief   Allocated TX DMA descriptor.
     */
    const dma_descriptor_t   *dma_tx_descriptor;
    /**
     * @brief   UART baud rate.
     */
    uart_baud_t              baud;
    /**
     * @brief   UART clock prescaler.
     */
    uart_presc_t             presc;
    /**
     * @brief   UART parity control.
     */
    uart_parity_t            parity;
    /**
     * @brief   UART oversampling.
     */
    uart_over_t              os;
    /**
     * @brief   UART stop bit value.
     */
    uart_sbit_t              sbit;
    /**
     * @brief   Pointer to the Synchronous Buffered mode buffer.
     */
    uint8_t                  *sbrx_buf;
    /**
     * @brief   Size of the Synchronous Buffered mode buffer.
     */
    uint32_t                 sbrx_size;
    /**
     * @brief   Pointer to the first available byte in the Synchronous Buffered
     *          mode buffer.
     */
    uint8_t                  *sbrx_wr_ptr;
    /**
     * @brief   Pointer to the first valid byte in the Synchronous Buffered
     *          mode buffer.
     */
    uint8_t                  *sbrx_rd_ptr;
    /**
     * @brief   Pointer to the end of the Synchronous Buffered mode buffer.
     */
    uint8_t                  *sbrx_end_ptr;
    /**
     * @brief   Pointers to UART callback functions.
     * @note    Set to @p NULL if not required.
     */
    uart_cb_t                cb[UART_CB_OPS_MAX];
};

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

IRQ_HANDLER(IRQ_UART1_HANDLER);
IRQ_HANDLER(IRQ_UART2_HANDLER);
IRQ_HANDLER(IRQ_UART3_HANDLER);

UART_TypeDef *uart_dev_get_reg_ptr(uart_driver_t *udp);
uint32_t uart_dev_get_clock(uart_driver_t *udp);
void uart_dev_clock_enable(uart_driver_t *udp);
void uart_dev_clock_disable(uart_driver_t *udp);
uint32_t uart_dev_get_dma_tx_trigger(uart_driver_t *udp);
uint32_t uart_dev_get_dma_rx_trigger(uart_driver_t *udp);
IRQn_Type uart_dev_get_vector(uart_driver_t *udp);

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/*===========================================================================*/
/* Module late inclusions.                                                   */
/*===========================================================================*/

#endif /* _UART_PRIVATE_H_ */

/** @} */
