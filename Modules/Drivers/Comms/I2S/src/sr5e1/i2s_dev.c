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
 * @file    i2s_dev.c
 * @brief   I2S device specific source file.
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
 * @brief   Returns pointer to the I2S register block.
 *
 * @param[in] idp       pointer to a @p i2s_driver_t structure
 * @return              pointer to the I2S register block.
 *
 * @notapi
 */
SPI_TypeDef *i2s_dev_get_reg_ptr(i2s_driver_t *idp) {

    SPI_TypeDef *i2s;

    if (idp == &DRV_I2S2) {
        i2s = SPI2;
    } else {
        i2s = SPI3;
    }

    return i2s;
}

/**
 * @brief   Returns value of I2S clock.
 *
 * @param[in] idp       pointer to a @p i2s_driver_t structure
 * @return              I2S clock.
 *
 * @notapi
 */
uint32_t i2s_dev_get_clock(i2s_driver_t *idp) {

    uint32_t clock;

    if (idp == &DRV_I2S2) {
        clock = CLOCK_I2S2CLK;
    } else {
        clock = CLOCK_I2S3CLK;
    }

    return clock;
}

/**
 * @brief   Enables I2S clock.
 *
 * @param[in] idp       pointer to a @p i2s_driver_t structure
 *
 * @notapi
 */
void i2s_dev_clock_enable(i2s_driver_t *idp) {

    if (idp == &DRV_I2S2) {
        clock_enable_SPI2(true);
    } else {
        clock_enable_SPI3(true);
    }
}

/**
 * @brief   Disables I2S clock.
 *
 * @param[in] idp       pointer to a @p i2s_driver_t structure
 *
 * @notapi
 */
void i2s_dev_clock_disable(i2s_driver_t *idp) {

    if (idp == &DRV_I2S2) {
        clock_disable_SPI2();
    } else {
        clock_disable_SPI3();
    }
}

/**
 * @brief   Returns I2S DMA TX trigger.
 *
 * @param[in] idp       pointer to a @p i2s_driver_t structure
 * @return              DMA TX trigger.
 *
 * @notapi
 */
uint32_t i2s_dev_get_dma_tx_trigger(i2s_driver_t *idp) {

    uint32_t dma_tx_trigger;

    if (idp == &DRV_I2S2) {
        dma_tx_trigger = DMAMUX1_SPI2_TX;
    } else {
        dma_tx_trigger = DMAMUX1_SPI3_TX;
    }

    return dma_tx_trigger;
}

/**
 * @brief   Returns I2S DMA RX trigger.
 *
 * @param[in] idp       pointer to a @p i2s_driver_t structure
 * @return              DMA RX trigger.
 *
 * @notapi
 */
uint32_t i2s_dev_get_dma_rx_trigger(i2s_driver_t *idp) {

    uint32_t dma_rx_trigger;

    if (idp == &DRV_I2S2) {
        dma_rx_trigger = DMAMUX1_SPI2_RX;
    } else {
        dma_rx_trigger = DMAMUX1_SPI3_RX;
    }

    return dma_rx_trigger;
}

/**
 * @brief   Returns I2S interrupt vector.
 *
 * @param[in] idp       pointer to a @p i2s_driver_t structure
 * @return              I2S interrupt vector
 *
 * @notapi
 */
IRQn_Type i2s_dev_get_vector(i2s_driver_t *idp) {

    IRQn_Type vector;

    if (idp == &DRV_I2S2) {
        vector = IRQ_SPI2_VECTOR;
    } else {
        vector = IRQ_SPI3_VECTOR;
    }

    return vector;
}

/**
 * @brief   I2S2 interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_SPI2_HANDLER) {

    IRQ_PROLOGUE();

    __i2s_serve_interrupt(&DRV_I2S2);

    IRQ_EPILOGUE();
}

/**
 * @brief   I2S3 interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_SPI3_HANDLER) {

    IRQ_PROLOGUE();

    __i2s_serve_interrupt(&DRV_I2S3);

    IRQ_EPILOGUE();
}

/** @} */
