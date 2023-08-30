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
 * @file    spi_dev.c
 * @brief   SPI specific device source file.
 *
 * @addtogroup DRIVERS
 * @addtogroup COMMS
 * @ingroup DRIVERS
 * @addtogroup SPI
 * @ingroup COMMS
 * @{
 */

#include <spi.h>
#include <spi_private.h>
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
/* Local function prototypes                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Module local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Module exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Returns pointer to the SPI register block.
 *
 * @param[in] sdp       pointer to a @p spi_driver_t structure
 * @return              pointer to the SPI register block.
 *
 * @notapi
 */
SPI_TypeDef *spi_dev_get_reg_ptr(spi_driver_t *sdp) {

    SPI_TypeDef *spi;

    if (sdp == &DRV_SPI1) {
        spi = SPI1;
    } else if (sdp == &DRV_SPI2) {
        spi = SPI2;
    } else if (sdp == &DRV_SPI3) {
        spi = SPI3;
    } else {
        spi = SPI4;
    }

    return spi;
}

/**
 * @brief   Returns value of SPI clock.
 *
 * @param[in] sdp       pointer to a @p spi_driver_t structure
 * @return              SPI clock.
 *
 * @notapi
 */
uint32_t spi_dev_get_clock(spi_driver_t *sdp) {

    uint32_t clock;

    if (sdp == &DRV_SPI1) {
        clock = CLOCK_SPI1CLK;
    } else if (sdp == &DRV_SPI2) {
        clock = CLOCK_SPI2CLK;
    } else if (sdp == &DRV_SPI3) {
        clock = CLOCK_SPI3CLK;
    } else {
        clock = CLOCK_SPI4CLK;
    }

    return clock;
}

/**
 * @brief   Enables SPI clock.
 *
 * @param[in] sdp       pointer to a @p spi_driver_t structure
 *
 * @notapi
 */
void spi_dev_clock_enable(spi_driver_t *sdp) {

    if (sdp == &DRV_SPI1) {
        clock_enable_SPI1(true);
    } else if (sdp == &DRV_SPI2) {
        clock_enable_SPI2(true);
    } else if (sdp == &DRV_SPI3) {
        clock_enable_SPI3(true);
    } else {
        clock_enable_SPI4(true);
    }
}

/**
 * @brief   Disables SPI clock.
 *
 * @param[in] sdp       pointer to a @p spi_driver_t structure
 *
 * @notapi
 */
void spi_dev_clock_disable(spi_driver_t *sdp) {

    if (sdp == &DRV_SPI1) {
        clock_disable_SPI1();
    } else if (sdp == &DRV_SPI2) {
        clock_disable_SPI2();
    } else if (sdp == &DRV_SPI3) {
        clock_disable_SPI3();
    } else {
        clock_disable_SPI4();
    }
}

/**
 * @brief   Returns SPI DMA TX trigger.
 *
 * @param[in] sdp       pointer to a @p spi_driver_t structure
 * @return              DMA TX trigger.
 *
 * @notapi
 */
uint32_t spi_dev_get_dma_tx_trigger(spi_driver_t *sdp) {

    uint32_t dma_tx_trigger;

    if (sdp == &DRV_SPI1) {
        dma_tx_trigger = DMAMUX1_SPI1_TX;
    } else if (sdp == &DRV_SPI2) {
        dma_tx_trigger = DMAMUX1_SPI2_TX;
    } else if (sdp == &DRV_SPI3) {
        dma_tx_trigger = DMAMUX1_SPI3_TX;
    } else {
        dma_tx_trigger = DMAMUX1_SPI4_TX;
    }

    return dma_tx_trigger;
}

/**
 * @brief   Returns SPI DMA RX trigger.
 *
 * @param[in] sdp       pointer to a @p spi_driver_t structure
 * @return              DMA RX trigger.
 *
 * @notapi
 */
uint32_t spi_dev_get_dma_rx_trigger(spi_driver_t *sdp) {

    uint32_t dma_rx_trigger;

    if (sdp == &DRV_SPI1) {
        dma_rx_trigger = DMAMUX1_SPI1_RX;
    } else if (sdp == &DRV_SPI2) {
        dma_rx_trigger = DMAMUX1_SPI2_RX;
    } else if (sdp == &DRV_SPI3) {
        dma_rx_trigger = DMAMUX1_SPI3_RX;
    } else {
        dma_rx_trigger = DMAMUX1_SPI4_RX;
    }

    return dma_rx_trigger;
}

/**
 * @brief   Returns SPI interrupt vector.
 *
 * @param[in] sdp       pointer to a @p spi_driver_t structure
 * @return              SPI interrupt vector
 *
 * @notapi
 */
IRQn_Type spi_dev_get_vector(spi_driver_t *sdp) {

    IRQn_Type vector;

    if (sdp == &DRV_SPI1) {
        vector = IRQ_SPI1_VECTOR;
    } else if (sdp == &DRV_SPI2) {
        vector = IRQ_SPI2_VECTOR;
    } else if (sdp == &DRV_SPI3) {
        vector = IRQ_SPI3_VECTOR;
    } else {
        vector = IRQ_SPI4_VECTOR;
    }

    return vector;
}

/**
 * @brief   SPI1 interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_SPI1_HANDLER) {

    IRQ_PROLOGUE();

    __spi_serve_interrupt(&DRV_SPI1);

    IRQ_EPILOGUE();
}

/**
 * @brief   SPI2 interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_SPI2_HANDLER) {

    IRQ_PROLOGUE();

    __spi_serve_interrupt(&DRV_SPI2);

    IRQ_EPILOGUE();
}

/**
 * @brief   SPI3 interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_SPI3_HANDLER) {

    IRQ_PROLOGUE();

    __spi_serve_interrupt(&DRV_SPI3);

    IRQ_EPILOGUE();
}

/**
 * @brief   SPI4 interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_SPI4_HANDLER) {

    IRQ_PROLOGUE();

    __spi_serve_interrupt(&DRV_SPI4);

    IRQ_EPILOGUE();
}

/** @} */
