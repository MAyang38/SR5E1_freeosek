/****************************************************************************
 *
 * Copyright (c) 2023 STMicroelectronics - All Rights Reserved
 *
 * License terms: STMicroelectronics Proprietary in accordance with licensing
 * terms SLA0098 at www.st.com.
 *
 * THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
 * INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *****************************************************************************/
/**
 * @file    wwdg.c
 * @brief   WWDG driver source file.
 *
 * @addtogroup DRIVERS
 * @addtogroup SYSTEM
 * @ingroup DRIVERS
 * @addtogroup WWDG
 * @ingroup SYSTEM
 * @{
 */

#include <wwdg.h>
#include <wwdg_private.h>

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

/**
 * @brief   Resets WWDG parameters.
 *
 * @param[out] wdp      pointer to an @p wwdg_driver_t structure
 *
 * @notapi
 */
static void wwdg_reset_paramters(wwdg_driver_t *wdp) {

    wdp->prio              = IRQ_MIN_PRIORITY;
    wdp->prescaler         = WWDG_PRESCALER_DIV1;
    wdp->counter           = 0x7F;
    wdp->window            = 0x7F;
    wdp->is_ewk_irq_en     = false;
    wdp->cb                = NULL;
}

/*===========================================================================*/
/* Module exported functions.                                                */
/*===========================================================================*/

void wwdg_init(wwdg_driver_t *wdp) {

    /* Set pointer to WWDG register block.*/
    wdp->wwdg = wwdg_dev_get_reg_ptr(wdp);

    /* Reset WWDG parameters.*/
    wwdg_reset_paramters(wdp);
}

uint32_t wwdg_set_prio(wwdg_driver_t *wdp, uint32_t prio) {

    uint32_t prev_prio;

    prev_prio = wdp->prio;
    wdp->prio = prio;

    return prev_prio;
}

wwdg_prescaler_t wwdg_set_prescaler(wwdg_driver_t *wdp,
                                    wwdg_prescaler_t prescaler) {

    wwdg_prescaler_t prev_prescaler;

    prev_prescaler = wdp->prescaler;
    wdp->prescaler = prescaler;

    return prev_prescaler;
}

uint16_t wwdg_set_counter(wwdg_driver_t *wdp, uint16_t counter) {

    uint16_t prev_counter;

    prev_counter = wdp->counter;
    wdp->counter = counter;

    return prev_counter;
}

uint16_t wwdg_set_window(wwdg_driver_t *wdp, uint16_t window) {

    uint16_t prev_window;

    prev_window = wdp->window;
    wdp->window = window;

    return prev_window;
}

bool wwdg_set_is_ewk_irq_en(wwdg_driver_t *wdp, bool enable) {

    bool prev_is_ewk_irq_en;

    prev_is_ewk_irq_en = wdp->is_ewk_irq_en;
    wdp->is_ewk_irq_en = enable;

    return prev_is_ewk_irq_en;
}

wwdg_cb_t wwdg_set_cb(wwdg_driver_t *wdp, wwdg_cb_t cb) {

    wwdg_cb_t prev_cb;

    prev_cb = wdp->cb;
    wdp->cb = cb;

    return prev_cb;
}

void wwdg_start(wwdg_driver_t *wdp) {

    IRQn_Type vector;
    uint32_t cr, cfr;

    /* Enable clock.*/
    wwdg_dev_clock_enable(wdp);

    cr = WWDG_CR_WDGA | (WWDG_CR_T_Msk & ((uint8_t)(wdp->counter) << WWDG_CR_T_Pos));

    cfr = (WWDG_CFR_W_Msk & (((uint32_t)wdp->window) << WWDG_CFR_W_Pos)) |
          (WWDG_CFR_WDGTB_Msk & (((uint32_t)wdp->prescaler) << WWDG_CFR_WDGTB_Pos));

    /* Get WWDG interrupt vector.*/
    vector = wwdg_dev_get_vector(wdp);

    /* Enable/Disable early wakeup interrupt.*/
    if (wdp->is_ewk_irq_en == true) {
        cfr |= WWDG_CFR_EWI;

        /* Enable WWDG interrupt.*/
        irq_set_priority(vector, wdp->prio);
        irq_enable(vector);
    } else {
        cfr &= ~WWDG_CFR_EWI;

        /* Disable WWDG interrupt.*/
        irq_disable(vector);
    }

    /* Clear pending early wakeup interrupt.*/
    REG_SET_FIELD(wdp->wwdg->SR, WWDG_SR_EWIF, 0U);

    /* Configure counter and enable watchdog.*/
    wdp->wwdg->CR = cr;

    /* Configure prescaler, early interrupt enable and window.*/
    wdp->wwdg->CFR = cfr;
}

void wwdg_refresh(wwdg_driver_t *wdp) {

    /* Refresh WWDG counter.*/
    REG_SET_FIELD(wdp->wwdg->CR, WWDG_CR_T, wdp->counter);
}

void wwdg_stop(wwdg_driver_t *wdp) {

    /* Disable WWDG.*/
    REG_SET_FIELD(wdp->wwdg->CR, WWDG_CR_WDGA, 0U);

    /* Clear pending early wakeup interrupt.*/
    REG_SET_FIELD(wdp->wwdg->SR, WWDG_SR_EWIF, 0U);

    /* Disable clock.*/
    wwdg_dev_clock_disable(wdp);
}

void wwdg_deinit(wwdg_driver_t *wdp) {

    /* Reset pointer to WWDG register block.*/
    wdp->wwdg = NULL;

    /* Reset WWDG parameters.*/
    wwdg_reset_paramters(wdp);
}

void __wwdg_serve_interrupt(wwdg_driver_t *wdp) {

    (void)wdp;

    /* Check if early wakeup interrupt is enabled.*/
    if (REG_READ_FIELD(wdp->wwdg->CFR, WWDG_CFR_EWI) == 1U) {
        /* Check if an eary wakeup interrupt occurred.*/
        if (REG_READ_FIELD(wdp->wwdg->SR, WWDG_SR_EWIF) == 1U) {

            /* Clear early wakeup interrupt.*/
            REG_SET_FIELD(wdp->wwdg->SR, WWDG_SR_EWIF, 0U);

            /* If a callback is defined, it is invoked.*/
            if (wdp->cb != NULL) {
                wdp->cb(wdp);
            }
        }
    }
}

/** @} */
