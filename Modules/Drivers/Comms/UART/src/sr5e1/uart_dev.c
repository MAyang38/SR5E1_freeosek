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
 * @file    uart_dev.c
 * @brief   UART device specific source file.
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
#include <dma.h>
#include <clock.h>
#include <irq.h>
#include <platform.h>

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
/* Module local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Module exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Returns pointer to the UART register block.
 *
 * @param[in] udp       pointer to a @p uart_driver_t structure
 * @return              pointer to the UART register block.
 *
 * @notapi
 */
UART_TypeDef *uart_dev_get_reg_ptr(uart_driver_t *udp) {

    UART_TypeDef *uart;

    if (udp == &DRV_UART1) {
        uart = UART1;
    } else if (udp == &DRV_UART2) {
        uart = UART2;
    } else {
        uart = UART3;
    }

    return uart;
}

/**
 * @brief   Returns value of UART clock.
 *
 * @param[in] udp       pointer to a @p uart_driver_t structure
 * @return              UART clock.
 *
 * @notapi
 */
uint32_t uart_dev_get_clock(uart_driver_t *udp) {

    uint32_t clock;

    if (udp == &DRV_UART1) {
        clock = CLOCK_UART1CLK;
    } else if (udp == &DRV_UART2) {
        clock = CLOCK_UART2CLK;
    } else {
        clock = CLOCK_UART3CLK;
    }

    return clock;
}

/**
 * @brief   Enables UART clock.
 *
 * @param[in] udp       pointer to a @p uart_driver_t structure
 *
 * @notapi
 */
void uart_dev_clock_enable(uart_driver_t *udp) {

    if (udp == &DRV_UART1) {
        clock_enable_UART1(true);
    } else if (udp == &DRV_UART2) {
        clock_enable_UART2(true);
    } else {
        clock_enable_UART3(true);
    }
}

/**
 * @brief   Disables UART clock.
 *
 * @param[in] udp       pointer to a @p uart_driver_t structure
 *
 * @notapi
 */
void uart_dev_clock_disable(uart_driver_t *udp) {

    if (udp == &DRV_UART1) {
        clock_disable_UART1();
    } else if (udp == &DRV_UART2) {
        clock_disable_UART2();
    } else {
        clock_disable_UART3();
    }
}

/**
 * @brief   Returns UART DMA TX trigger.
 *
 * @param[in] udp       pointer to a @p uart_driver_t structure
 * @return              DMA TX trigger.
 *
 * @notapi
 */
uint32_t uart_dev_get_dma_tx_trigger(uart_driver_t *udp) {

    uint32_t dma_tx_trigger;

    if (udp == &DRV_UART1) {
        dma_tx_trigger = DMAMUX1_UART1_TX;
    } else if (udp == &DRV_UART2) {
        dma_tx_trigger = DMAMUX1_UART2_TX;
    } else {
        dma_tx_trigger = DMAMUX1_UART3_TX;
    }

    return dma_tx_trigger;
}

/**
 * @brief   Returns UART DMA RX trigger.
 *
 * @param[in] udp       pointer to a @p uart_driver_t structure
 * @return              DMA RX trigger.
 *
 * @notapi
 */
uint32_t uart_dev_get_dma_rx_trigger(uart_driver_t *udp) {

    uint32_t dma_rx_trigger;

    if (udp == &DRV_UART1) {
        dma_rx_trigger = DMAMUX1_UART1_RX;
    } else if (udp == &DRV_UART2) {
        dma_rx_trigger = DMAMUX1_UART2_RX;
    } else {
        dma_rx_trigger = DMAMUX1_UART3_RX;
    }

    return dma_rx_trigger;
}

/**
 * @brief   Returns UART interrupt vector.
 *
 * @param[in] udp       pointer to a @p uart_driver_t structure
 * @return              UART interrupt vector
 *
 * @notapi
 */
IRQn_Type uart_dev_get_vector(uart_driver_t *udp) {

    IRQn_Type vector;

    if (udp == &DRV_UART1) {
        vector = IRQ_UART1_VECTOR;
    } else if (udp == &DRV_UART2) {
        vector = IRQ_UART2_VECTOR;
    } else {
        vector = IRQ_UART3_VECTOR;
    }

    return vector;
}

/**
 * @brief   UART1 interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_UART1_HANDLER) {

    IRQ_PROLOGUE();

    __uart_serve_interrupt(&DRV_UART1);

    IRQ_EPILOGUE();
}

/**
 * @brief   UART2 interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_UART2_HANDLER) {

    IRQ_PROLOGUE();

    __uart_serve_interrupt(&DRV_UART2);

    IRQ_EPILOGUE();
}

/**
 * @brief   UART3 interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_UART3_HANDLER) {

    IRQ_PROLOGUE();

    __uart_serve_interrupt(&DRV_UART3);

    IRQ_EPILOGUE();
}

/** @} */
