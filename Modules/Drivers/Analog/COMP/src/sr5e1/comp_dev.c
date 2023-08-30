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
 * @file    comp_dev.c
 * @brief   COMP device specific source file.
 *
 * @addtogroup DRIVERS
 * @addtogroup ANALOG
 * @ingroup DRIVERS
 * @addtogroup COMP
 * @ingroup ANALOG
 * @{
 */

#include <comp.h>
#include <comp_private.h>
#include <clock.h>
#include <platform.h>

/*===========================================================================*/
/* Module local definitions.                                                 */
/*===========================================================================*/

/**
 * @brief   Comparator EXTI lines.
 */
#define COMP_EXTI_LINE_COMP1_OUT            EXTI_LINE_21
#define COMP_EXTI_LINE_COMP2_OUT            EXTI_LINE_22
#define COMP_EXTI_LINE_COMP3_OUT            EXTI_LINE_29
#define COMP_EXTI_LINE_COMP4_OUT            EXTI_LINE_30
#define COMP_EXTI_LINE_COMP5_OUT            EXTI_LINE_31
#define COMP_EXTI_LINE_COMP6_OUT            EXTI_LINE_32
#define COMP_EXTI_LINE_COMP7_OUT            EXTI_LINE_33
#define COMP_EXTI_LINE_COMP8_OUT            EXTI_LINE_34

/*===========================================================================*/
/* Module exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Module local types.                                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Module local variables.                                                   */
/*===========================================================================*/

static uint32_t enabled_comp = 0U;

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
 * @brief   Returns pointer to the COMP register block.
 *
 * @param[in] cdp       pointer to a @p comp_driver_t structure
 * @return              pointer to the COMP register block.
 *
 * @notapi
 */
COMP_TypeDef *comp_dev_get_reg_ptr(comp_driver_t *cdp) {

    COMP_TypeDef *comp;

    if (cdp == &DRV_COMP1) {
        comp = COMP1;
    } else if (cdp == &DRV_COMP2) {
        comp = COMP2;
    } else if (cdp == &DRV_COMP3) {
        comp = COMP3;
    } else if (cdp == &DRV_COMP4) {
        comp = COMP4;
    } else if (cdp == &DRV_COMP5) {
        comp = COMP5;
    } else if (cdp == &DRV_COMP6) {
        comp = COMP6;
    } else if (cdp == &DRV_COMP7) {
        comp = COMP7;
    } else {
        comp = COMP8;
    }

    return comp;
}

/**
 * @brief   Enables COMP clock.
 *
 * @param[in] cdp       pointer to a @p comp_driver_t structure
 *
 * @notapi
 */
void comp_dev_clock_enable(comp_driver_t *cdp) {

    /* Enable COMP clock only if it is not already enabled.*/
    if ((cdp == &DRV_COMP1) || (cdp == &DRV_COMP2) ||
        (cdp == &DRV_COMP3) || (cdp == &DRV_COMP4)) {
        if ((enabled_comp & 0xFUL) == 0U) {
            clock_enable_COMP1(true);
        }
    } else {
        if ((enabled_comp & 0xF0UL) == 0U) {
            clock_enable_COMP2(true);
        }
    }

    /* Update the mask of enabled COMPs.*/
    if (cdp == &DRV_COMP1) {
        enabled_comp |= (1UL << 0U);
    } else if (cdp == &DRV_COMP2) {
        enabled_comp |= (1UL << 1U);
    } else if (cdp == &DRV_COMP3) {
        enabled_comp |= (1UL << 2U);
    } else if (cdp == &DRV_COMP4) {
        enabled_comp |= (1UL << 3U);
    } else if (cdp == &DRV_COMP5) {
        enabled_comp |= (1UL << 4U);
    } else if (cdp == &DRV_COMP6) {
        enabled_comp |= (1UL << 5U);
    } else if (cdp == &DRV_COMP7) {
        enabled_comp |= (1UL << 6U);
    } else {
        enabled_comp |= (1UL << 7U);
    }
}

/**
 * @brief   Disables COMP clock.
 *
 * @param[in] cdp       pointer to a @p comp_driver_t structure
 *
 * @notapi
 */
void comp_dev_clock_disable(comp_driver_t *cdp) {

    /* Update the mask of enabled COMPs.*/
    if (cdp == &DRV_COMP1) {
        enabled_comp &= ~(1UL << 0U);
    } else if (cdp == &DRV_COMP2) {
        enabled_comp &= ~(1UL << 1U);
    } else if (cdp == &DRV_COMP3) {
        enabled_comp &= ~(1UL << 2U);
    } else if (cdp == &DRV_COMP4) {
        enabled_comp &= ~(1UL << 3U);
    } else if (cdp == &DRV_COMP5) {
        enabled_comp &= ~(1UL << 4U);
    } else if (cdp == &DRV_COMP6) {
        enabled_comp &= ~(1UL << 5U);
    } else if (cdp == &DRV_COMP7) {
        enabled_comp &= ~(1UL << 6U);
    } else {
        enabled_comp &= ~(1UL << 7U);
    }

    /* Disable COMP clock only if all COMP instances related to the clock are
       disabled.*/
    if ((cdp == &DRV_COMP1) || (cdp == &DRV_COMP2) ||
        (cdp == &DRV_COMP3) || (cdp == &DRV_COMP4)) {
        if ((enabled_comp & 0xFUL) == 0U) {
            clock_disable_COMP1();
        }
    } else {
        if ((enabled_comp & 0xF0UL) == 0U) {
            clock_disable_COMP2();
        }
    }
}

/**
 * @brief   Returns COMP interrupt vector.
 *
 * @param[in] cdp       pointer to a @p comp_driver_t structure
 * @return              COMP interrupt vector
 *
 * @notapi
 */
IRQn_Type comp_dev_get_vector(comp_driver_t *cdp) {

    IRQn_Type vector;

    if ((cdp == &DRV_COMP1) || (cdp == &DRV_COMP2)) {
        vector = IRQ_COMP_1_2_VECTOR;
    } else if ((cdp == &DRV_COMP3) || (cdp == &DRV_COMP4)) {
        vector = IRQ_COMP_3_4_VECTOR;
    } else if ((cdp == &DRV_COMP5) || (cdp == &DRV_COMP6)) {
        vector = IRQ_COMP_5_6_VECTOR;
    } else {
        vector = IRQ_COMP_7_8_VECTOR;
    } 

    return vector;
}

/**
 * @brief   Returns EXTI line associated to COMP output.
 *
 * @param[in] cdp       pointer to a @p comp_driver_t structure
 * @return              EXTI line associated to comparator output
 *
 * @notapi
 */
exti_line_t comp_dev_get_exti_line(comp_driver_t *cdp) {

    if (cdp == &DRV_COMP1) {
        return COMP_EXTI_LINE_COMP1_OUT;
    } else if (cdp == &DRV_COMP2) {
        return COMP_EXTI_LINE_COMP2_OUT;
    } else if (cdp == &DRV_COMP3) {
        return COMP_EXTI_LINE_COMP3_OUT;
    } else if (cdp == &DRV_COMP4) {
        return COMP_EXTI_LINE_COMP4_OUT;
    } else if (cdp == &DRV_COMP5) {
        return COMP_EXTI_LINE_COMP5_OUT;
    } else if (cdp == &DRV_COMP6) {
        return COMP_EXTI_LINE_COMP6_OUT;
    } else if (cdp == &DRV_COMP7) {
        return COMP_EXTI_LINE_COMP7_OUT;
    } else {
        return COMP_EXTI_LINE_COMP8_OUT;
    }

}

/**
 * @brief   COMP1/2 interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_COMP_1_2_HANDLER)
{
    IRQ_PROLOGUE();

    if (exti_is_pending(COMP_EXTI_LINE_COMP1_OUT) == true) {
        __comp_serve_interrupt(&DRV_COMP1);
        exti_clear_pending(COMP_EXTI_LINE_COMP1_OUT);
    } else {
        __comp_serve_interrupt(&DRV_COMP2);
        exti_clear_pending(COMP_EXTI_LINE_COMP2_OUT);
    }

    IRQ_EPILOGUE();
}

/**
 * @brief   COMP3/4 interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_COMP_3_4_HANDLER)
{
    IRQ_PROLOGUE();

    if (exti_is_pending(COMP_EXTI_LINE_COMP3_OUT) == true) {
        __comp_serve_interrupt(&DRV_COMP3);
        exti_clear_pending(COMP_EXTI_LINE_COMP3_OUT);
    } else {
        __comp_serve_interrupt(&DRV_COMP4);
        exti_clear_pending(COMP_EXTI_LINE_COMP4_OUT);
    }

    IRQ_EPILOGUE();
}

/**
 * @brief   COMP5/6 interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_COMP_5_6_HANDLER)
{
    IRQ_PROLOGUE();

    if (exti_is_pending(COMP_EXTI_LINE_COMP5_OUT) == true) {
        __comp_serve_interrupt(&DRV_COMP5);
        exti_clear_pending(COMP_EXTI_LINE_COMP5_OUT);
    } else {
        __comp_serve_interrupt(&DRV_COMP6);
        exti_clear_pending(COMP_EXTI_LINE_COMP6_OUT);
    }

    IRQ_EPILOGUE();
}

/**
 * @brief   COMP7/8 interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_COMP_7_8_HANDLER)
{
    IRQ_PROLOGUE();

    if (exti_is_pending(COMP_EXTI_LINE_COMP7_OUT) == true) {
        __comp_serve_interrupt(&DRV_COMP7);
        exti_clear_pending(COMP_EXTI_LINE_COMP7_OUT);
    } else {
        __comp_serve_interrupt(&DRV_COMP8);
        exti_clear_pending(COMP_EXTI_LINE_COMP8_OUT);
    }

    IRQ_EPILOGUE();
}

/** @} */
