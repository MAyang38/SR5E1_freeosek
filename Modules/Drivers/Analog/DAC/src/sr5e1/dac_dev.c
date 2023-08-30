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
 * @file    dac_dev.c
 * @brief   DAC device specific source file.
 *
 * @addtogroup DRIVERS
 * @addtogroup ANALOG
 * @ingroup DRIVERS
 * @addtogroup DAC
 * @ingroup ANALOG
 * @{
 */

#include <dac.h>
#include <dac_private.h>
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
 * @brief   Returns pointer to the DAC register block.
 *
 * @param[in] ddp       pointer to a @p dac_driver_t structure
 * @return              pointer to the DAC register block.
 *
 * @notapi
 */

DAC_TypeDef *dac_dev_get_reg_ptr(dac_driver_t *ddp) {

    DAC_TypeDef *dac;

    if (ddp == &DRV_DAC1) {
        dac = DAC1;
    } else if (ddp == &DRV_DAC2) {
        dac = DAC2;
    } else if (ddp == &DRV_DAC3) {
        dac = DAC3;
    } else if (ddp == &DRV_DAC4) {
        dac = DAC4;
    } else {
        dac = BDAC1;
    }

    return dac;
}

/**
 * @brief   Enables DAC clock.
 *
 * @param[in] ddp       pointer to a @p dac_driver_t structure
 *
 * @notapi
 */
void dac_dev_clock_enable(dac_driver_t *ddp) {

    /* Enable DAC clock.*/
    if (ddp == &DRV_DAC1) {
        clock_enable_DAC1(true);
    } else if (ddp == &DRV_DAC2) {
        clock_enable_DAC2(true);
    } else if (ddp == &DRV_DAC3) {
        clock_enable_DAC3(true);
    } else if (ddp == &DRV_DAC4) {
        clock_enable_DAC4(true);
    } else {
        clock_enable_BDAC1(true);
    }
}

/**
 * @brief   Disables DAC clock.
 *
 * @param[in] ddp       pointer to a @p dac_driver_t structure
 *
 * @notapi
 */
void dac_dev_clock_disable(dac_driver_t *ddp) {

    /* Disable DAC clock.*/
    if (ddp == &DRV_DAC1) {
        clock_disable_DAC1();
    } else if (ddp == &DRV_DAC2) {
        clock_disable_DAC2();
    } else if (ddp == &DRV_DAC3) {
        clock_disable_DAC3();
    } else if (ddp == &DRV_DAC4) {
        clock_disable_DAC4();
    } else {
        clock_disable_BDAC1();
    }
}

/**
 * @brief   Returns DAC interrupt vector.
 *
 * @param[in] ddp       pointer to a @p dac_driver_t structure
 * @return              DAC interrupt vector
 *
 * @notapi
 */
IRQn_Type dac_dev_get_vector(dac_driver_t *ddp) {

    IRQn_Type vector;

    if (ddp == &DRV_DAC1) {
        vector = IRQ_DAC1_VECTOR;
    } else if (ddp == &DRV_DAC2) {
        vector = IRQ_DAC2_VECTOR;
    } else if (ddp == &DRV_DAC3) {
        vector = IRQ_DAC3_VECTOR;
    } else if (ddp == &DRV_DAC4) {
        vector = IRQ_DAC4_VECTOR;
    } else {
        vector = IRQ_B_DAC1_VECTOR;
    }

    return vector;
}

/**
 * @brief   DAC1 interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_DAC1_HANDLER)
{
    IRQ_PROLOGUE();

    __dac_serve_interrupt(&DRV_DAC1);

    IRQ_EPILOGUE();
}
 
/**
 * @brief   DAC2 interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_DAC2_HANDLER)
{
    IRQ_PROLOGUE();

    __dac_serve_interrupt(&DRV_DAC2);

    IRQ_EPILOGUE();
}

/**
 * @brief   DAC3 interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_DAC3_HANDLER)
{
    IRQ_PROLOGUE();

    __dac_serve_interrupt(&DRV_DAC3);

    IRQ_EPILOGUE();
}

/**
 * @brief   DAC4 interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_DAC4_HANDLER)
{
    IRQ_PROLOGUE();

    __dac_serve_interrupt(&DRV_DAC4);

    IRQ_EPILOGUE();
}

/**
 * @brief   BDAC1 interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_B_DAC1_HANDLER)
{
    IRQ_PROLOGUE();

    __dac_serve_interrupt(&DRV_BDAC1);

    IRQ_EPILOGUE();
}

/** @} */
