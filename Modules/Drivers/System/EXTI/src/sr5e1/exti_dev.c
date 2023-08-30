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
 * @file    exti_dev.c
 * @brief   EXTI device specific source file.
 *
 * @addtogroup DRIVERS
 * @addtogroup SYSTEM
 * @ingroup DRIVERS
 * @addtogroup EXTI
 * @ingroup SYSTEM
 * @{
 */

#include <exti.h>

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
 * @brief   Returns EXTI interrupt vector related to EXTI lines [0:15].
 *
 * @param[in] line      line to be configured. It can be one of the following
 *                      values:
 *            @arg @ref EXTI_LINE_0
 *            @arg @ref EXTI_LINE_1
 *            @arg @ref EXTI_LINE_2
 *            @arg @ref EXTI_LINE_3
 *            @arg @ref EXTI_LINE_4
 *            @arg @ref EXTI_LINE_5
 *            @arg @ref EXTI_LINE_6
 *            @arg @ref EXTI_LINE_7
 *            @arg @ref EXTI_LINE_8
 *            @arg @ref EXTI_LINE_9
 *            @arg @ref EXTI_LINE_10
 *            @arg @ref EXTI_LINE_11
 *            @arg @ref EXTI_LINE_12
 *            @arg @ref EXTI_LINE_13
 *            @arg @ref EXTI_LINE_14
 *            @arg @ref EXTI_LINE_15
 * @return              EXTI interrupt vector
 *
 * @notapi
 */
IRQn_Type exti_dev_get_vector(exti_line_t line) {

    IRQn_Type vector;

    if (line == EXTI_LINE_0) {
        vector = IRQ_EXTI0_VECTOR;
    } else if (line == EXTI_LINE_1) {
        vector = IRQ_EXTI1_VECTOR;
    } else if (line == EXTI_LINE_2) {
        vector = IRQ_EXTI2_VECTOR;
    } else if (line == EXTI_LINE_3) {
        vector = IRQ_EXTI3_VECTOR;
    } else if (line == EXTI_LINE_4) {
        vector = IRQ_EXTI4_VECTOR;
    } else if (line >= EXTI_LINE_5 && line <= EXTI_LINE_9) {
        vector = IRQ_EXTI9_5_VECTOR;
    } else {
        vector = IRQ_EXTI15_10_VECTOR;
    }

    return vector;
}

/**
 * @brief   EXTI line 0 interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_EXTI0_HANDLER) {

    IRQ_PROLOGUE();

    __exti_serve_interrupt(EXTI_IRQ_LINE0);

    IRQ_EPILOGUE();
}

/**
 * @brief   EXTI line 1 interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_EXTI1_HANDLER) {

    IRQ_PROLOGUE();

    __exti_serve_interrupt(EXTI_IRQ_LINE1);

    IRQ_EPILOGUE();
}

/**
 * @brief   EXTI line 2 interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_EXTI2_HANDLER) {

    IRQ_PROLOGUE();

    __exti_serve_interrupt(EXTI_IRQ_LINE2);

    IRQ_EPILOGUE();
}

/**
 * @brief   EXTI line 3 interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_EXTI3_HANDLER) {

    IRQ_PROLOGUE();

    __exti_serve_interrupt(EXTI_IRQ_LINE3);

    IRQ_EPILOGUE();
}

/**
 * @brief   EXTI line 4 interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_EXTI4_HANDLER) {

    IRQ_PROLOGUE();

    __exti_serve_interrupt(EXTI_IRQ_LINE4);

    IRQ_EPILOGUE();
}

/**
 * @brief   EXTI lines [5:9] interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_EXTI9_5_HANDLER) {

    IRQ_PROLOGUE();

    __exti_serve_interrupt(EXTI_IRQ_LINE9_5);

    IRQ_EPILOGUE();
}

/**
 * @brief   EXTI lines [10:15] interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_EXTI15_10_HANDLER) {

    IRQ_PROLOGUE();

    __exti_serve_interrupt(EXTI_IRQ_LINE15_10);

    IRQ_EPILOGUE();
}

/** @} */
