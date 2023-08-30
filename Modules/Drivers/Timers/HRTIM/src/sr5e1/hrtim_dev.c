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
 * @file    hrtim_dev.c
 * @brief   HRTIM instances source file.
 *
 * @addtogroup DRIVERS
 * @addtogroup TIMERS
 * @ingroup DRIVERS
 * @addtogroup HRTIM
 * @ingroup TIMERS
 * @{
 */

#include <hrtim.h>
#include <hrtim_private.h> 
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

/**
 * @brief   Returns pointer to the HRTIM register block.
 *
 * @param[in] hdp       pointer to a @p hrtim_driver_t structure
 * @return              pointer to the HRTIM register block.
 *
 * @notapi
 */
HRTIM_TypeDef *hrtim_dev_get_reg_ptr(hrtim_driver_t *hdp) {

    HRTIM_TypeDef *hrtim;

    if (hdp == &DRV_HRTIM1) {
        hrtim = HRTIM1;
    } else {
        hrtim = HRTIM2;
    }

    return hrtim;
}

/**
 * @brief   Returns value of HRTIM clock.
 *
 * @param[in] hdp       pointer to a @p hrtim_driver_t structure
 * @return              HRTIM clock.
 *
 * @notapi
 */
uint32_t hrtim_dev_get_clock(hrtim_driver_t *hdp) {

    (void)(hdp);
    return CLOCK_SYSCLKDIV;
}

/**
 * @brief   Enables HRTIM clock.
 *
 * @param[in] hdp       pointer to a @p hrtim_driver_t structure
 *
 * @notapi
 */
void hrtim_dev_clock_enable(hrtim_driver_t *hdp) {

    if (hdp == &DRV_HRTIM1) {
        clock_enable_HRTIM1(true);
    } else {
        clock_enable_HRTIM2(true);
    }
}

/**
 * @brief   Disables HRTIM clock.
 *
 * @param[in] hdp       pointer to a @p hrtim_driver_t structure
 *
 * @notapi
 */
void hrtim_dev_clock_disable(hrtim_driver_t *hdp) {

    if (hdp == &DRV_HRTIM1) {
        clock_disable_HRTIM1();
    } else {
        clock_disable_HRTIM2();
    }
}

/**
 * @brief   Enables HRTIM interrupts.
 *
 * @param[in] hdp       pointer to a @p hrtim_driver_t structure
 * @param[in] prio      interrupts priority
 *
 * @notapi
 */
void hrtim_dev_enable_irq(hrtim_driver_t *hdp, uint32_t prio) {

    if (hdp == &DRV_HRTIM1) {
        irq_set_priority(IRQ_HRTIM1_MT_VECTOR, prio);
        irq_enable(IRQ_HRTIM1_MT_VECTOR);
        irq_set_priority(IRQ_HRTIM1_TA_VECTOR, prio);
        irq_enable(IRQ_HRTIM1_TA_VECTOR);
        irq_set_priority(IRQ_HRTIM1_TB_VECTOR, prio);
        irq_enable(IRQ_HRTIM1_TB_VECTOR);
        irq_set_priority(IRQ_HRTIM1_TC_VECTOR, prio);
        irq_enable(IRQ_HRTIM1_TC_VECTOR);
        irq_set_priority(IRQ_HRTIM1_TD_VECTOR, prio);
        irq_enable(IRQ_HRTIM1_TD_VECTOR);
        irq_set_priority(IRQ_HRTIM1_TE_VECTOR, prio);
        irq_enable(IRQ_HRTIM1_TE_VECTOR);
        irq_set_priority(IRQ_HRTIM1_FLT_VECTOR, prio);
        irq_enable(IRQ_HRTIM1_FLT_VECTOR);
        irq_set_priority(IRQ_HRTIM1_TF_VECTOR, prio);
        irq_enable(IRQ_HRTIM1_TF_VECTOR);
    } else {
        irq_set_priority(IRQ_HRTIM2_MT_VECTOR, prio);
        irq_enable(IRQ_HRTIM2_MT_VECTOR);
        irq_set_priority(IRQ_HRTIM2_TA_VECTOR, prio);
        irq_enable(IRQ_HRTIM2_TA_VECTOR);
        irq_set_priority(IRQ_HRTIM2_TB_VECTOR, prio);
        irq_enable(IRQ_HRTIM2_TB_VECTOR);
        irq_set_priority(IRQ_HRTIM2_TC_VECTOR, prio);
        irq_enable(IRQ_HRTIM2_TC_VECTOR);
        irq_set_priority(IRQ_HRTIM2_TD_VECTOR, prio);
        irq_enable(IRQ_HRTIM2_TD_VECTOR);
        irq_set_priority(IRQ_HRTIM2_TE_VECTOR, prio);
        irq_enable(IRQ_HRTIM2_TE_VECTOR);
        irq_set_priority(IRQ_HRTIM2_FLT_VECTOR, prio);
        irq_enable(IRQ_HRTIM2_FLT_VECTOR);
        irq_set_priority(IRQ_HRTIM2_TF_VECTOR, prio);
        irq_enable(IRQ_HRTIM2_TF_VECTOR);
    }
}

/**
 * @brief   Disables HRTIM interrupts.
 *
 * @param[in] hdp       pointer to a @p hrtim_driver_t structure
 *
 * @notapi
 */
void hrtim_dev_disable_irq(hrtim_driver_t *hdp) {

    if (hdp == &DRV_HRTIM1) {
        irq_disable(IRQ_HRTIM1_MT_VECTOR);
        irq_disable(IRQ_HRTIM1_TA_VECTOR);
        irq_disable(IRQ_HRTIM1_TB_VECTOR);
        irq_disable(IRQ_HRTIM1_TC_VECTOR);
        irq_disable(IRQ_HRTIM1_TD_VECTOR);
        irq_disable(IRQ_HRTIM1_TE_VECTOR);
        irq_disable(IRQ_HRTIM1_FLT_VECTOR);
        irq_disable(IRQ_HRTIM1_TF_VECTOR);
    } else {
        irq_disable(IRQ_HRTIM2_MT_VECTOR);
        irq_disable(IRQ_HRTIM2_TA_VECTOR);
        irq_disable(IRQ_HRTIM2_TB_VECTOR);
        irq_disable(IRQ_HRTIM2_TC_VECTOR);
        irq_disable(IRQ_HRTIM2_TD_VECTOR);
        irq_disable(IRQ_HRTIM2_TE_VECTOR);
        irq_disable(IRQ_HRTIM2_FLT_VECTOR);
        irq_disable(IRQ_HRTIM2_TF_VECTOR);
    }
}

/**
 * @brief   Calibration procedure and DLLCR setup.
 *
 * @param[in] hdp       pointer to a @p hrtim_driver_t structure
 *
 * @notapi
 */
void hrtim_dev_calib_procedure(hrtim_driver_t *hdp) {

    /* Calibration procedure and DLLCR setup.*/
    hdp->hrtim->sCommonRegs.ICR   = ~0U;
    hdp->hrtim->sCommonRegs.DLLCR = HRTIM_DLLCR_CAL;
    while ((hdp->hrtim->sCommonRegs.ISR & HRTIM_ISR_DLLRDY) == 0U) {
    }
}

/**
 * @brief   HRTIM1 master interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_HRTIM1_MT_HANDLER) {

    IRQ_PROLOGUE();

    __hrtim_serve_timer_interrupt(&DRV_HRTIM1, HRTIM_TIMER_MASTER);

    IRQ_EPILOGUE();
}

/**
 * @brief   HRTIM1 unit A interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_HRTIM1_TA_HANDLER) {

    IRQ_PROLOGUE();

    __hrtim_serve_timer_interrupt(&DRV_HRTIM1, HRTIM_TIMER_A);

    IRQ_EPILOGUE();
}

/**
 * @brief   HRTIM1 unit B interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_HRTIM1_TB_HANDLER) {

    IRQ_PROLOGUE();

    __hrtim_serve_timer_interrupt(&DRV_HRTIM1, HRTIM_TIMER_B);

    IRQ_EPILOGUE();
}

/**
 * @brief   HRTIM1 unit C interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_HRTIM1_TC_HANDLER) {

    IRQ_PROLOGUE();

    __hrtim_serve_timer_interrupt(&DRV_HRTIM1, HRTIM_TIMER_C);

    IRQ_EPILOGUE();
}

/**
 * @brief   HRTIM1 unit D interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_HRTIM1_TD_HANDLER) {

    IRQ_PROLOGUE();

    __hrtim_serve_timer_interrupt(&DRV_HRTIM1, HRTIM_TIMER_D);

    IRQ_EPILOGUE();
}

/**
 * @brief   HRTIM1 unit E interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_HRTIM1_TE_HANDLER) {

    IRQ_PROLOGUE();

    __hrtim_serve_timer_interrupt(&DRV_HRTIM1, HRTIM_TIMER_E);

    IRQ_EPILOGUE();
}

/**
 * @brief   HRTIM1 fault interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_HRTIM1_FLT_HANDLER) {

    IRQ_PROLOGUE();

    __hrtim_serve_flt_interrupt(&DRV_HRTIM1);

    IRQ_EPILOGUE();
}

/**
 * @brief   HRTIM1 unit F interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_HRTIM1_TF_HANDLER) {

    IRQ_PROLOGUE();

    __hrtim_serve_timer_interrupt(&DRV_HRTIM1, HRTIM_TIMER_F);

    IRQ_EPILOGUE();
}

/**
 * @brief   HRTIM2 master interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_HRTIM2_MT_HANDLER) {

    IRQ_PROLOGUE();

    __hrtim_serve_timer_interrupt(&DRV_HRTIM2, HRTIM_TIMER_MASTER);

    IRQ_EPILOGUE();
}

/**
 * @brief   HRTIM2 unit A interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_HRTIM2_TA_HANDLER) {

    IRQ_PROLOGUE();

    __hrtim_serve_timer_interrupt(&DRV_HRTIM2, HRTIM_TIMER_A);

    IRQ_EPILOGUE();
}

/**
 * @brief   HRTIM2 unit B interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_HRTIM2_TB_HANDLER) {

    IRQ_PROLOGUE();

    __hrtim_serve_timer_interrupt(&DRV_HRTIM2, HRTIM_TIMER_B);

    IRQ_EPILOGUE();
}

/**
 * @brief   HRTIM2 unit C interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_HRTIM2_TC_HANDLER) {

    IRQ_PROLOGUE();

    __hrtim_serve_timer_interrupt(&DRV_HRTIM2, HRTIM_TIMER_C);

    IRQ_EPILOGUE();
}

/**
 * @brief   HRTIM2 unit D interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_HRTIM2_TD_HANDLER) {

    IRQ_PROLOGUE();

    __hrtim_serve_timer_interrupt(&DRV_HRTIM2, HRTIM_TIMER_D);

    IRQ_EPILOGUE();
}

/**
 * @brief   HRTIM2 unit E interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_HRTIM2_TE_HANDLER) {

    IRQ_PROLOGUE();

    __hrtim_serve_timer_interrupt(&DRV_HRTIM2, HRTIM_TIMER_E);

    IRQ_EPILOGUE();
}

/**
 * @brief   HRTIM2 fault interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_HRTIM2_FLT_HANDLER) {

    IRQ_PROLOGUE();

    __hrtim_serve_flt_interrupt(&DRV_HRTIM2);

    IRQ_EPILOGUE();
}

/**
 * @brief   HRTIM2 unit F interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_HRTIM2_TF_HANDLER) {

    IRQ_PROLOGUE();

    __hrtim_serve_timer_interrupt(&DRV_HRTIM2, HRTIM_TIMER_F);

    IRQ_EPILOGUE();
}

/*===========================================================================*/
/* Module exported functions.                                                */
/*===========================================================================*/

/** @} */
