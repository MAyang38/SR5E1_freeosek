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
 * @file    saradc_dev.c
 * @brief   ADC device specific source file.
 *
 * @addtogroup DRIVERS
 * @addtogroup ANALOG
 * @ingroup DRIVERS
 * @addtogroup ADC
 * @ingroup ANALOG
 * @{
 */

#include <saradc.h>
#include <saradc_private.h>
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

static uint32_t adc_enabled_clocks = 0U;

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
 * @brief   Returns pointer to the ADC register block.
 *
 * @param[in] adp       pointer to a @p adc_driver_t structure
 * @return              pointer to the ADC register block.
 *
 * @notapi
 */
ADC_TypeDef *adc_dev_get_reg_ptr(adc_driver_t *adp) {

    ADC_TypeDef *adc;

    if (adp == &DRV_ADC1) {
        adc = ADC1;
    } else if (adp == &DRV_ADC2) {
        adc = ADC2;
    } else if (adp == &DRV_ADC3) {
        adc = ADC3;
    } else if (adp == &DRV_ADC4) {
        adc = ADC4;
    } else {
        adc = ADC5;
    }

    return adc;
}

/**
 * @brief   Returns pointer to the ADC Common register block.
 *
 * @param[in] adp       pointer to a @p adc_driver_t structure
 * @return              pointer to the ADC Common register block.
 *
 * @notapi
 */
ADC_Common_TypeDef *adc_common_dev_get_reg_ptr(adc_driver_t *adp) {

    ADC_Common_TypeDef *adc_common;

    if (adp == &DRV_ADC1 || adp == &DRV_ADC2) {
        adc_common = ADC12_COMMON;
    } else {
        adc_common = ADC345_COMMON;
    }

    return adc_common;
}

/**
 * @brief   Returns value of ADC clock.
 *
 * @param[in] adp       pointer to a @p adc_driver_t structure
 * @return              ADC clock.
 *
 * @notapi
 */
uint32_t adc_dev_get_clock(adc_driver_t *adp) {

    uint32_t clock;

    if (adp == &DRV_ADC1 || adp == &DRV_ADC2) {
        clock = CLOCK_ADC12CLK;
    } else {
        clock = CLOCK_ADC345CLK;
    }

    return clock;
}

/**
 * @brief   Enables ADC clock.
 *
 * @param[in] adp       pointer to a @p adc_driver_t structure
 *
 * @notapi
 */
void adc_dev_clock_enable(adc_driver_t *adp) {

    /* Enable ADC clock only if it is not already enabled.*/
    if (adp == &DRV_ADC1 || adp == &DRV_ADC2) {
        if ((adc_enabled_clocks & 0x3UL) == 0U) {
            clock_enable_ADC12(true);
        }
    } else {
        if ((adc_enabled_clocks & 0x1CUL) == 0U) {
            clock_enable_ADC345(true);
        }
    }

    /* Update the mask of ADC enabled clocks.*/
    if (adp == &DRV_ADC1) {
        adc_enabled_clocks |= (1UL << 0U);
    } else if (adp == &DRV_ADC2) {
        adc_enabled_clocks |= (1UL << 1U);
    } else if (adp == &DRV_ADC3) {
        adc_enabled_clocks |= (1UL << 2U);
    } else if (adp == &DRV_ADC4) {
        adc_enabled_clocks |= (1UL << 3U);
    } else {
        adc_enabled_clocks |= (1UL << 4U);
    }
}

/**
 * @brief   Disables ADC clock.
 *
 * @param[in] adp       pointer to a @p adc_driver_t structure
 *
 * @notapi
 */
void adc_dev_clock_disable(adc_driver_t *adp) {

    /* Update the mask of ADC enabled clocks.*/
    if (adp == &DRV_ADC1) {
        adc_enabled_clocks &= ~(1UL << 0U);
    } else if (adp == &DRV_ADC2) {
        adc_enabled_clocks &= ~(1UL << 1U);
    } else if (adp == &DRV_ADC3) {
        adc_enabled_clocks &= ~(1UL << 2U);
    } else if (adp == &DRV_ADC4) {
        adc_enabled_clocks &= ~(1UL << 3U);
    } else {
        adc_enabled_clocks &= ~(1UL << 4U);
    }

    /* Disable ADC clock only if all ADC instances related to the clock are
       disabled.*/
    if (adp == &DRV_ADC1 || adp == &DRV_ADC2) {
        if ((adc_enabled_clocks & 0x3UL) == 0U) {
            clock_disable_ADC12();
        }
    } else {
        if ((adc_enabled_clocks & 0x1CUL) == 0U) {
            clock_disable_ADC345();
        }
    }
}

/**
 * @brief   Returns ADC DMA trigger.
 *
 * @param[in] adp       pointer to a @p adc_driver_t structure
 * @return              DMA trigger.
 *
 * @notapi
 */
uint32_t adc_dev_get_dma_trigger(adc_driver_t *adp) {

    uint32_t dma_trigger;

    if (adp == &DRV_ADC1) {
        dma_trigger = DMAMUX1_ADC1;
    } else if (adp == &DRV_ADC2) {
        dma_trigger = DMAMUX1_ADC2;
    } else if (adp == &DRV_ADC3) {
        dma_trigger = DMAMUX1_ADC3;
    } else if (adp == &DRV_ADC4) {
        dma_trigger = DMAMUX1_ADC4;
    } else {
        dma_trigger = DMAMUX1_ADC5;
    }

    return dma_trigger;
}

/**
 * @brief   Returns ADC interrupt vector.
 *
 * @param[in] adp       pointer to a @p adc_driver_t structure
 * @return              ADC interrupt vector
 *
 * @notapi
 */
IRQn_Type adc_dev_get_vector(adc_driver_t *adp) {

    IRQn_Type vector;

    if (adp == &DRV_ADC1) {
        vector = IRQ_ADC1_VECTOR;
    } else if (adp == &DRV_ADC2) {
        vector = IRQ_ADC2_VECTOR;
    } else if (adp == &DRV_ADC3) {
        vector = IRQ_ADC3_VECTOR;
    } else if (adp == &DRV_ADC4) {
        vector = IRQ_ADC4_VECTOR;
    } else {
        vector = IRQ_ADC5_VECTOR;
    }

    return vector;
}

/**
 * @brief   ADC1 interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_ADC1_HANDLER) {

    IRQ_PROLOGUE();

    __adc_serve_interrupt(&DRV_ADC1);

    IRQ_EPILOGUE();
}

/**
 * @brief   ADC2 interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_ADC2_HANDLER) {

    IRQ_PROLOGUE();

    __adc_serve_interrupt(&DRV_ADC2);

    IRQ_EPILOGUE();
}

/**
 * @brief   ADC3 interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_ADC3_HANDLER) {

    IRQ_PROLOGUE();

    __adc_serve_interrupt(&DRV_ADC3);

    IRQ_EPILOGUE();
}

/**
 * @brief   ADC4 interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_ADC4_HANDLER) {

    IRQ_PROLOGUE();

    __adc_serve_interrupt(&DRV_ADC4);

    IRQ_EPILOGUE();
}

/**
 * @brief   ADC5 interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_ADC5_HANDLER) {

    IRQ_PROLOGUE();

    __adc_serve_interrupt(&DRV_ADC5);

    IRQ_EPILOGUE();
}

/** @} */
