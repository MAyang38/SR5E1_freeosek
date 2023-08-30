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
 * @file    tim_dev.c
 * @brief   TIM device specific source file.
 *
 * @addtogroup DRIVERS
 * @addtogroup TIMERS
 * @ingroup DRIVERS
 * @addtogroup TIM
 * @ingroup TIMERS
 * @{
 */

#include <tim.h>
#include <tim_private.h>
#include <clock.h>
#include <irq.h>
#include <platform.h>

/*===========================================================================*/
/* Module local definitions.                                                 */
/*===========================================================================*/

#define TIM_DT_MAX_STEP_1         127U
#define TIM_DT_MAX_STEP_2         63U
#define TIM_DT_MAX_STEP_3         31U
#define TIM_DT_MAX_STEP_4         31U

#define TIM_DT_MASK_1             0x00U
#define TIM_DT_MASK_2             0x80U
#define TIM_DT_MASK_3             0xC0U
#define TIM_DT_MASK_4             0xE0U

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
 * @brief   Returns TIM deadtime sampling period [ps].
 *
 * @param[in] tdp       pointer to a @p tim_driver_t structure
 * @return              deadtime sampling period [ps].
 *
 * @notapi
 */
static uint64_t tim_dev_get_dts(tim_driver_t *tdp) {

    if (tdp->ckd == TIM_CKD_1) {
        return (1000000000000UL / (tdp->clock));
    } else if (tdp->ckd == TIM_CKD_2) {
        return (1000000000000UL / ((uint64_t)2U * tdp->clock));
    } else {
        return (1000000000000UL / ((uint64_t)4U * tdp->clock));
    }
}

/**
 * @brief   Returns TIM deadtime genarator value.
 * @note    This functions returns the deadtime generator value (field DTG[7:0]
 *          of register BDTR and field DTGF of register DTR2) based on value of
 *          desired deadtime.
 *
 * @param[in] dt_ps     desired deadtime [ps]
 * @param[in] dts       deadtime sampling period [ps]
 * @return              deadtime genarator value, or 0 if the desired value is
 *                      not supported.
 *
 * @notapi
 */
static uint8_t tim_dev_get_dtg(uint64_t dt_ps, uint64_t dts) {

    /* Calculate deadtime generator value.*/
    if (dt_ps < ((TIM_DT_MAX_STEP_1 + 1U) * dts)) {
        return (uint8_t)(TIM_DT_MASK_1 | ((uint8_t)((dt_ps / dts) & TIM_DT_MAX_STEP_1)));
    } else if (dt_ps < ((64U + (TIM_DT_MAX_STEP_2 + 1U)) * 2U  * dts)) {
        return (uint8_t)(TIM_DT_MASK_2 | ((uint8_t)((((dt_ps / dts) / 2U)  - 64U) & TIM_DT_MAX_STEP_2)));
    } else if (dt_ps < ((32U + (TIM_DT_MAX_STEP_3 + 1U)) * 8U  * dts)) {
        return (uint8_t)(TIM_DT_MASK_3 | ((uint8_t)((((dt_ps / dts) / 8U)  - 32U) & TIM_DT_MAX_STEP_3)));
    } else if (dt_ps < ((32U + (TIM_DT_MAX_STEP_4 + 1U)) * 16U * dts)) {
        return (uint8_t)(TIM_DT_MASK_4 | ((uint8_t)((((dt_ps / dts) / 16U) - 32U) & TIM_DT_MAX_STEP_4)));
    } else {
        return 0U;
    }
}

/*===========================================================================*/
/* Module exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Returns pointer to the TIM register block.
 *
 * @param[in] tdp       pointer to a @p tim_driver_t structure
 * @return              pointer to the TIM register block.
 *
 * @notapi
 */
TIM_TypeDef *tim_dev_get_reg_ptr(tim_driver_t *tdp) {

    TIM_TypeDef *tim;

    if (tdp == &DRV_TIM1) {
        tim = TIM1;
    } else if (tdp == &DRV_TIM2) {
        tim = TIM2;
    } else if (tdp == &DRV_TIM3) {
        tim = TIM3;
    } else if (tdp == &DRV_TIM4) {
        tim = TIM4;
    } else if (tdp == &DRV_TIM5) {
        tim = TIM5;
    } else if (tdp == &DRV_TIM6) {
        tim = TIM6;
    } else if (tdp == &DRV_TIM7) {
        tim = TIM7;
    } else if (tdp == &DRV_TIM8) {
        tim = TIM8;
    } else if (tdp == &DRV_TIM15) {
        tim = TIM15;
    } else {
        tim = TIM16;
    }

    return tim;
}

/**
 * @brief   Checks if the TIM includes the Break and Dead-time Register (BDTR).
 *
 * @param[in] tdp       pointer to a @p tim_driver_t structure
 * @return              true if the TIM includes the BDTR, false otherwise.
 *
 * @notapi
 */
bool tim_dev_is_bdtr(tim_driver_t *tdp) {

    if (tdp == &DRV_TIM1  || tdp == &DRV_TIM8 ||
        tdp == &DRV_TIM15 || tdp == &DRV_TIM16) {
        return true;
    } else {
        return false;
    }
}

/**
 * @brief   Returns the TIM nuber of channels.
 *
 * @param[in] tdp       pointer to a @p tim_driver_t structure
 * @return              number of channels.
 *
 * @notapi
 */
uint8_t tim_dev_get_ch_num(tim_driver_t *tdp) {

    uint8_t ch_num;


    if (tdp == &DRV_TIM1 || tdp == &DRV_TIM2 ||
        tdp == &DRV_TIM3 || tdp == &DRV_TIM4 ||
        tdp == &DRV_TIM5 || tdp == &DRV_TIM8) {
        ch_num = 4U;
    } else if (tdp == &DRV_TIM15) {
        ch_num = 2U;
    } else if (tdp == &DRV_TIM16) {
        ch_num = 1U;
    } else {
        ch_num = 0U;
    }

    return ch_num;
}

/**
 * @brief   Returns value of TIM clock.
 *
 * @param[in] tdp       pointer to a @p tim_driver_t structure
 * @return              TIM clock.
 *
 * @notapi
 */
uint32_t tim_dev_get_clock(tim_driver_t *tdp) {

    uint32_t clock;

    if (tdp == &DRV_TIM1) {
        clock = CLOCK_TIMCLK1;
    } else if (tdp == &DRV_TIM2) {
        clock = CLOCK_TIMCLK2;
    } else if (tdp == &DRV_TIM3) {
        clock = CLOCK_TIMCLK3;
    } else if (tdp == &DRV_TIM4) {
        clock = CLOCK_TIMCLK4;
    } else if (tdp == &DRV_TIM5) {
        clock = CLOCK_TIMCLK5;
    } else if (tdp == &DRV_TIM6) {
        clock = CLOCK_TIMCLK6;
    } else if (tdp == &DRV_TIM7) {
        clock = CLOCK_TIMCLK7;
    } else if (tdp == &DRV_TIM8) {
        clock = CLOCK_TIMCLK8;
    } else if (tdp == &DRV_TIM15) {
        clock = CLOCK_TIMCLK15;
    } else {
        clock = CLOCK_TIMCLK16;
    }

    return clock;
}

/**
 * @brief   Enables TIM clock.
 *
 * @param[in] tdp       pointer to a @p tim_driver_t structure
 *
 * @notapi
 */
void tim_dev_clock_enable(tim_driver_t *tdp) {

    if (tdp == &DRV_TIM1) {
        clock_enable_TIM1(true);
    } else if (tdp == &DRV_TIM2) {
        clock_enable_TIM2(true);
    } else if (tdp == &DRV_TIM3) {
        clock_enable_TIM3(true);
    } else if (tdp == &DRV_TIM4) {
        clock_enable_TIM4(true);
    } else if (tdp == &DRV_TIM5) {
        clock_enable_TIM5(true);
    } else if (tdp == &DRV_TIM6) {
        clock_enable_TIM6(true);
    } else if (tdp == &DRV_TIM7) {
        clock_enable_TIM7(true);
    } else if (tdp == &DRV_TIM8) {
        clock_enable_TIM8(true);
    } else if (tdp == &DRV_TIM15) {
        clock_enable_TIM15(true);
    } else {
        clock_enable_TIM16(true);
    }
}

/**
 * @brief   Disables TIM clock.
 *
 * @param[in] tdp       pointer to a @p tim_driver_t structure
 *
 * @notapi
 */
void tim_dev_clock_disable(tim_driver_t *tdp) {

    if (tdp == &DRV_TIM1) {
        clock_disable_TIM1();
    } else if (tdp == &DRV_TIM2) {
        clock_disable_TIM2();
    } else if (tdp == &DRV_TIM3) {
        clock_disable_TIM3();
    } else if (tdp == &DRV_TIM4) {
        clock_disable_TIM4();
    } else if (tdp == &DRV_TIM5) {
        clock_disable_TIM5();
    } else if (tdp == &DRV_TIM6) {
        clock_disable_TIM6();
    } else if (tdp == &DRV_TIM7) {
        clock_disable_TIM7();
    } else if (tdp == &DRV_TIM8) {
        clock_disable_TIM8();
    } else if (tdp == &DRV_TIM15) {
        clock_disable_TIM15();
    } else {
        clock_disable_TIM16();
    }
}

/**
 * @brief   Returns TIM rising edge deadtime genarator value.
 * @note    This functions returns the rising edge deadtime generator value
 *          (field DTG[7:0] of register BDTR) based on the value of the
 *          desired deadtime.
 *
 * @param[in] tdp       pointer to a @p tim_driver_t structure
 * @return              rising edge deadtime genarator value.
 *
 * @notapi
 */
uint8_t tim_dev_get_rdtg(tim_driver_t *tdp) {

    uint64_t rdt_ps;
    uint64_t dts;

    /* Convert desired rising edge deadtime in ps.*/
    rdt_ps = ((uint64_t)tdp->rdt * 1000U);

    /* Calculate deadtime sampling period [ps].*/
    dts = tim_dev_get_dts(tdp);

    return tim_dev_get_dtg(rdt_ps, dts);
}

/**
 * @brief   Returns TIM falling edge deadtime genarator value.
 * @note    This functions returns the falling edge deadtime generator value
 *          (field DTGF[7:0] of register DTR2) based on the value of the
 *          desired deadtime.
 *
 * @param[in] tdp       pointer to a @p tim_driver_t structure
 * @return              falling edge deadtime genarator value.
 *
 * @notapi
 */
uint8_t tim_dev_get_fdtg(tim_driver_t *tdp) {

    uint64_t fdt_ps;
    uint64_t dts;

    /* Convert desired falling edge deadtime in ps.*/
    fdt_ps = ((uint64_t)tdp->fdt * 1000U);

    /* Calculate deadtime sampling period [ps].*/
    dts = tim_dev_get_dts(tdp);

    return tim_dev_get_dtg(fdt_ps, dts);
}

/**
 * @brief   Enables TIM interrupts.
 *
 * @param[in] tdp       pointer to a @p tim_driver_t structure
 * @param[in] prio      interrupts priority
 *
 * @notapi
 */
void tim_dev_enable_irq(tim_driver_t *tdp, uint32_t prio) {

    if (tdp == &DRV_TIM1) {
        irq_set_priority(IRQ_TIM1_BRK_VECTOR, prio);
        irq_enable(IRQ_TIM1_BRK_VECTOR);
        irq_set_priority(IRQ_TIM1_UP_VECTOR, prio);
        irq_enable(IRQ_TIM1_UP_VECTOR);
        irq_set_priority(IRQ_TIM1_TRGCO_VECTOR, prio);
        irq_enable(IRQ_TIM1_TRGCO_VECTOR);
        irq_set_priority(IRQ_TIM1_CC_VECTOR, prio);
        irq_enable(IRQ_TIM1_CC_VECTOR);
    } else if (tdp == &DRV_TIM2) {
        irq_set_priority(IRQ_TIM2_VECTOR, prio);
        irq_enable(IRQ_TIM2_VECTOR);
    } else if (tdp == &DRV_TIM3) {
        irq_set_priority(IRQ_TIM3_VECTOR, prio);
        irq_enable(IRQ_TIM3_VECTOR);
    } else if (tdp == &DRV_TIM4) {
        irq_set_priority(IRQ_TIM4_VECTOR, prio);
        irq_enable(IRQ_TIM4_VECTOR);
    } else if (tdp == &DRV_TIM5) {
        irq_set_priority(IRQ_TIM5_VECTOR, prio);
        irq_enable(IRQ_TIM5_VECTOR);
    } else if (tdp == &DRV_TIM6) {
        irq_set_priority(IRQ_TIM6_VECTOR, prio);
        irq_enable(IRQ_TIM6_VECTOR);
    } else if (tdp == &DRV_TIM7) {
        irq_set_priority(IRQ_TIM7_VECTOR, prio);
        irq_enable(IRQ_TIM7_VECTOR);
    } else if (tdp == &DRV_TIM8) {
        irq_set_priority(IRQ_TIM8_BRK_VECTOR, prio);
        irq_enable(IRQ_TIM8_BRK_VECTOR);
        irq_set_priority(IRQ_TIM8_UP_VECTOR, prio);
        irq_enable(IRQ_TIM8_UP_VECTOR);
        irq_set_priority(IRQ_TIM8_TRGCO_VECTOR, prio);
        irq_enable(IRQ_TIM8_TRGCO_VECTOR);
        irq_set_priority(IRQ_TIM8_CC_VECTOR, prio);
        irq_enable(IRQ_TIM8_CC_VECTOR);
    } else if (tdp == &DRV_TIM15) {
        irq_set_priority(IRQ_TIM15_VECTOR, prio);
        irq_enable(IRQ_TIM15_VECTOR);
    } else {
        irq_set_priority(IRQ_TIM16_VECTOR, prio);
        irq_enable(IRQ_TIM16_VECTOR);
    }
}

/**
 * @brief   Disables TIM interrupts.
 *
 * @param[in] tdp       pointer to a @p tim_driver_t structure
 *
 * @notapi
 */
void tim_dev_disable_irq(tim_driver_t *tdp) {

    if (tdp == &DRV_TIM1) {
        irq_disable(IRQ_TIM1_BRK_VECTOR);
        irq_disable(IRQ_TIM1_UP_VECTOR);
        irq_disable(IRQ_TIM1_TRGCO_VECTOR);
        irq_disable(IRQ_TIM1_CC_VECTOR);
    } else if (tdp == &DRV_TIM2) {
        irq_disable(IRQ_TIM2_VECTOR);
    } else if (tdp == &DRV_TIM3) {
        irq_disable(IRQ_TIM3_VECTOR);
    } else if (tdp == &DRV_TIM4) {
        irq_disable(IRQ_TIM4_VECTOR);
    } else if (tdp == &DRV_TIM5) {
        irq_disable(IRQ_TIM5_VECTOR);
    } else if (tdp == &DRV_TIM6) {
        irq_disable(IRQ_TIM6_VECTOR);
    } else if (tdp == &DRV_TIM7) {
        irq_disable(IRQ_TIM7_VECTOR);
    } else if (tdp == &DRV_TIM8) {
        irq_disable(IRQ_TIM8_BRK_VECTOR);
        irq_disable(IRQ_TIM8_UP_VECTOR);
        irq_disable(IRQ_TIM8_TRGCO_VECTOR);
        irq_disable(IRQ_TIM8_CC_VECTOR);
    } else if (tdp == &DRV_TIM15) {
        irq_disable(IRQ_TIM15_VECTOR);
    } else {
        irq_disable(IRQ_TIM16_VECTOR);
    }
}

/**
 * @brief   TIM1 Break interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_TIM1_BRK_HANDLER) {

    IRQ_PROLOGUE();

    __tim_serve_interrupt(&DRV_TIM1);

    IRQ_EPILOGUE();
}

/**
 * @brief   TIM1 Update interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_TIM1_UP_HANDLER) {

    IRQ_PROLOGUE();

    __tim_serve_interrupt(&DRV_TIM1);

    IRQ_EPILOGUE();
}

/**
 * @brief   TIM1 Trigger and Commutation interrupts handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_TIM1_TRGCO_HANDLER) {

    IRQ_PROLOGUE();

    __tim_serve_interrupt(&DRV_TIM1);

    IRQ_EPILOGUE();
}

/**
 * @brief   TIM1 Capture Compare interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_TIM1_CC_HANDLER) {

    IRQ_PROLOGUE();

    __tim_serve_interrupt(&DRV_TIM1);

    IRQ_EPILOGUE();
}

/**
 * @brief   TIM2 global interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_TIM2_HANDLER) {

    IRQ_PROLOGUE();

    __tim_serve_interrupt(&DRV_TIM2);

    IRQ_EPILOGUE();
}

/**
 * @brief   TIM3 global interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_TIM3_HANDLER) {

    IRQ_PROLOGUE();

    __tim_serve_interrupt(&DRV_TIM3);

    IRQ_EPILOGUE();
}

/**
 * @brief   TIM4 global interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_TIM4_HANDLER) {

    IRQ_PROLOGUE();

    __tim_serve_interrupt(&DRV_TIM4);

    IRQ_EPILOGUE();
}

/**
 * @brief   TIM5 global interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_TIM5_HANDLER) {

    IRQ_PROLOGUE();

    __tim_serve_interrupt(&DRV_TIM5);

    IRQ_EPILOGUE();
}

/**
 * @brief   TIM6 global interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_TIM6_HANDLER) {

    IRQ_PROLOGUE();

    __tim_serve_interrupt(&DRV_TIM6);

    IRQ_EPILOGUE();
}

/**
 * @brief   TIM7 global interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_TIM7_HANDLER) {

  IRQ_PROLOGUE();

  __tim_serve_interrupt(&DRV_TIM7);

  IRQ_EPILOGUE();
}

/**
 * @brief   TIM8 Break interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_TIM8_BRK_HANDLER) {

    IRQ_PROLOGUE();

    __tim_serve_interrupt(&DRV_TIM8);

    IRQ_EPILOGUE();
}

/**
 * @brief   TIM1 Update interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_TIM8_UP_HANDLER) {

    IRQ_PROLOGUE();

    __tim_serve_interrupt(&DRV_TIM8);

    IRQ_EPILOGUE();
}

/**
 * @brief   TIM1 Trigger and Commutation interrupts handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_TIM8_TRGCO_HANDLER) {

    IRQ_PROLOGUE();

    __tim_serve_interrupt(&DRV_TIM8);

    IRQ_EPILOGUE();
}

/**
 * @brief   TIM1 Capture Compare interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_TIM8_CC_HANDLER) {

    IRQ_PROLOGUE();

    __tim_serve_interrupt(&DRV_TIM8);

    IRQ_EPILOGUE();
}

/**
 * @brief   TIM15 global interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_TIM15_HANDLER) {

    IRQ_PROLOGUE();

    __tim_serve_interrupt(&DRV_TIM15);

    IRQ_EPILOGUE();
}

/**
 * @brief   TIM16 global interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_TIM16_HANDLER) {

    IRQ_PROLOGUE();

    __tim_serve_interrupt(&DRV_TIM16);

    IRQ_EPILOGUE();
}

/** @} */
