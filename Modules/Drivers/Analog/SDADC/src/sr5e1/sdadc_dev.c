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
 * @file    sdadc_dev.c
 * @brief   SDADC device specific source file.
 *
 * @addtogroup DRIVERS
 * @addtogroup ANALOG
 * @ingroup DRIVERS
 * @addtogroup SDADC
 * @ingroup ANALOG
 * @{
 */

#include <sdadc.h>
#include <sdadc_private.h>
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
 * @brief   Returns pointer to the SDADC register block.
 *
 * @param[in] sdp       pointer to a @p sdadc_driver_t structure
 * @return              pointer to the SDADC register block.
 *
 * @notapi
 */
SDADC_TypeDef *sdadc_dev_get_reg_ptr(sdadc_driver_t *sdp) {

    SDADC_TypeDef *sdadc;

    if (sdp == &DRV_SDADC1) {
        sdadc = SD_ADC1;
    } else {
        sdadc = SD_ADC2;
    }

    return sdadc;
}

/**
 * @brief   Enables SDADC clock.
 *
 * @param[in] sdp       pointer to a @p sdadc_driver_t structure
 *
 * @notapi
 */
void sdadc_dev_clock_enable(sdadc_driver_t *sdp) {

    /* Enable SDADC clock.*/
    if (sdp == &DRV_SDADC1) {
        clock_enable_SDADC1(true);
    } else {
        clock_enable_SDADC2(true);
    }
}

/**
 * @brief   Disables SDADC clock.
 *
 * @param[in] sdp       pointer to a @p sdadc_driver_t structure
 *
 * @notapi
 */
void sdadc_dev_clock_disable(sdadc_driver_t *sdp) {

    /* Enable SDADC clock.*/
    if (sdp == &DRV_SDADC1) {
        clock_disable_SDADC1();
    } else {
        clock_disable_SDADC2();
    }
}

/**
 * @brief   Returns SDADC interrupt vector.
 *
 * @param[in] sdp       pointer to a @p sdadc_driver_t structure
 * @return              SDADC interrupt vector
 *
 * @notapi
 */
IRQn_Type sdadc_dev_get_vector(sdadc_driver_t *sdp) {

    IRQn_Type vector;

    if (sdp == &DRV_SDADC1) {
        vector = IRQ_SD_ADC1_VECTOR;
    } else {
        vector = IRQ_SD_ADC2_VECTOR;
    }

    return vector;
}

/**
 * @brief   SDADC1 interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_SD_ADC1_HANDLER)
{
    IRQ_PROLOGUE();

    __sdadc_serve_interrupt(&DRV_SDADC1);

    IRQ_EPILOGUE();
}
 
/**
 * @brief   SDADC2 interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_SD_ADC2_HANDLER)
{
    IRQ_PROLOGUE();

    __sdadc_serve_interrupt(&DRV_SDADC2);

    IRQ_EPILOGUE();
}

/** @} */
