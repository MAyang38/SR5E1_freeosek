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
 * @file    comp.c
 * @brief   COMP driver source file.
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
 * @brief   Resets COMP parameters.
 *
 * @param[out] cdp      pointer to an @p comp_driver_t structure
 *
 * @notapi
 */
static void comp_reset_paramters(comp_driver_t *cdp) {

    /* Set all driver configuration parameters to default values.*/
    cdp->prio           = IRQ_MIN_PRIORITY;
    cdp->input_plus     = COMP_COMP1_INPUT_PLUS_PB2;
    cdp->input_minus    = COMP_COMP1_INPUT_MINUS_PB1;
    cdp->hysteresis     = COMP_HYSTERESIS_NONE;
    cdp->out_pol        = COMP_OUTPOL_NOTINVERTED;
    cdp->blank_sel      = COMP_COMP1_BLANKSRC_NONE;
    cdp->is_deglitch_en = false;
    cdp->is_lock_en     = false;
    cdp->triggermode    = COMP_TRIGGERMODE_NONE;
    cdp->cb             = NULL;
}

/*===========================================================================*/
/* Module exported functions.                                                */
/*===========================================================================*/

void comp_init(comp_driver_t *cdp) {

    /* Set pointer to COMP register block.*/
    cdp->comp = comp_dev_get_reg_ptr(cdp);

    /* Reset COMP parameters.*/
    comp_reset_paramters(cdp);
}

uint32_t comp_set_prio(comp_driver_t *cdp, uint32_t prio) {

    uint32_t prev_prio;

    prev_prio = cdp->prio;
    cdp->prio = prio;

    return prev_prio;
}

uint8_t comp_set_input_plus(comp_driver_t *cdp, uint8_t input_plus) {

    uint8_t prev_input_plus;

    prev_input_plus = cdp->input_plus;
    cdp->input_plus = input_plus;

    return prev_input_plus;
}

uint8_t comp_set_input_minus(comp_driver_t *cdp, uint8_t input_minus) {

    uint8_t prev_input_minus;

    prev_input_minus = cdp->input_minus;
    cdp->input_minus = input_minus;

    return prev_input_minus;
}

uint8_t comp_set_blank_sel(comp_driver_t *cdp, uint8_t blank_sel) {

    uint8_t prev_blank_sel;

    prev_blank_sel = cdp->blank_sel;
    cdp->blank_sel = blank_sel;

    return prev_blank_sel;
}

comp_hysteresis_t comp_set_hysteresis(comp_driver_t *cdp,
                                      comp_hysteresis_t hysteresis) {

    comp_hysteresis_t prev_hysteresis;

    prev_hysteresis = cdp->hysteresis;
    cdp->hysteresis = hysteresis;

    return prev_hysteresis;
}

comp_outpol_t comp_set_output_polarity(comp_driver_t *cdp,
                                       comp_outpol_t out_pol) {

    comp_outpol_t prev_out_pol;

    prev_out_pol = cdp->out_pol;
    cdp->out_pol = out_pol;

    return prev_out_pol;
}

bool comp_set_deglitch(comp_driver_t *cdp, bool enable) {

    bool prev_enable;

    prev_enable = cdp->is_deglitch_en;
    cdp->is_deglitch_en = enable;

    return prev_enable;
}

bool comp_set_lock(comp_driver_t *cdp, bool enable) {

    bool prev_enable;

    prev_enable = cdp->is_lock_en;
    cdp->is_lock_en = enable;

    return prev_enable;
}

comp_triggermode_t comp_set_triggermode(comp_driver_t *cdp,
                                        comp_triggermode_t triggermode) {

    comp_triggermode_t prev_triggermode;

    prev_triggermode = cdp->triggermode;
    cdp->triggermode = triggermode;

    return prev_triggermode;
}

comp_cb_t comp_set_cb(comp_driver_t *cdp, comp_cb_t cb) {

    comp_cb_t prev_cb;

    prev_cb = cdp->cb;
    cdp->cb = cb;

    return prev_cb;
}

void comp_start(comp_driver_t *cdp) {

    IRQn_Type vector;
    exti_line_t exti_line;

    /* Enable clock.*/
    comp_dev_clock_enable(cdp);

    /* Configure COMP interrupt vector.*/
    vector = comp_dev_get_vector(cdp);
    irq_set_priority(vector, cdp->prio);
    irq_enable(vector);

    /* Configure COMP registers based on COMP parameters.*/
    REG_SET_FIELD(cdp->comp->CSR, COMP_CSR_INPSEL, cdp->input_plus);
    REG_SET_FIELD(cdp->comp->CSR, COMP_CSR_INMSEL, cdp->input_minus);
    REG_SET_FIELD(cdp->comp->CSR, COMP_CSR_HYST, cdp->hysteresis);
    REG_SET_FIELD(cdp->comp->CSR, COMP_CSR_POL, cdp->out_pol);
    REG_SET_FIELD(cdp->comp->CSR, COMP_CSR_BLANKSEL, cdp->blank_sel);
    if (cdp->is_deglitch_en == true) {
        REG_SET_FIELD(cdp->comp->CSR, COMP_CSR_DIG_H, 1U);
    } else {
        REG_SET_FIELD(cdp->comp->CSR, COMP_CSR_DIG_H, 0U);
    }
    if (cdp->is_lock_en == true) {
        REG_SET_FIELD(cdp->comp->CSR, COMP_CSR_LOCK, 1U);
    } else {
        REG_SET_FIELD(cdp->comp->CSR, COMP_CSR_LOCK, 0U);
    }

    /* Get EXTI line related to COMP.*/
    exti_line = comp_dev_get_exti_line(cdp);

    /* Configure triggermode.*/
    switch(cdp->triggermode) {
        case COMP_TRIGGERMODE_NONE:
            break;
        case COMP_TRIGGERMODE_INT_RISING:
            exti_set_line(exti_line, EXTI_MODE_INTERRUPT, EXTI_TRIGGER_RISING);
            break;
        case COMP_TRIGGERMODE_INT_FALLING:
            exti_set_line(exti_line, EXTI_MODE_INTERRUPT, EXTI_TRIGGER_FALLING);
            break;
        case COMP_TRIGGERMODE_INT_BOTH:
            exti_set_line(exti_line, EXTI_MODE_INTERRUPT, EXTI_TRIGGER_BOTH);
            break;
        case COMP_TRIGGERMODE_EVT_RISING:
            exti_set_line(exti_line, EXTI_MODE_EVENT, EXTI_TRIGGER_RISING);
            break;
        case COMP_TRIGGERMODE_EVT_FALLING:
            exti_set_line(exti_line, EXTI_MODE_EVENT, EXTI_TRIGGER_FALLING);
            break;
        case COMP_TRIGGERMODE_EVT_BOTH:
            exti_set_line(exti_line, EXTI_MODE_EVENT, EXTI_TRIGGER_BOTH);
            break;
        default:
            /* Dummy comment as required by MISRA.*/
            break;
    }
}

void comp_enable(comp_driver_t *cdp) {

    REG_SET_FIELD(cdp->comp->CSR, COMP_CSR_EN, 1U);
}

uint8_t comp_get_output(comp_driver_t *cdp) {

    return (uint8_t)REG_READ_FIELD(cdp->comp->CSR, COMP_CSR_VALUE);
}

void comp_disable(comp_driver_t *cdp) {

    REG_SET_FIELD(cdp->comp->CSR, COMP_CSR_EN, 0U);
}

void comp_stop(comp_driver_t *cdp) {

    IRQn_Type vector;
    exti_line_t exti_line;

    /* Disable ADC interrupt.*/
    vector = comp_dev_get_vector(cdp);
    irq_disable(vector);

    /* Clear COMP register*/
    REG_CLEAR(cdp->comp->CSR);

    /* Get EXTI line related to COMP.*/
    exti_line = comp_dev_get_exti_line(cdp);
    /* Disable COMP output triggering through external interrupt line.*/
    exti_set_line(exti_line, EXTI_MODE_NONE, EXTI_TRIGGER_NONE);

    /* Disable COMP clock.*/
    comp_dev_clock_disable(cdp);
}

void comp_deinit(comp_driver_t *cdp) {

    /* Set pointer to COMP register block to NULL.*/
    cdp->comp = NULL;

    /* Reset COMP parameters.*/
    comp_reset_paramters(cdp);
}

void __comp_serve_interrupt(comp_driver_t *cdp) {

    /* Invoke callback if it is configured.*/
    if (cdp->cb != NULL) {
        /* DMA critical error.*/
        cdp->cb(cdp);
    }
}

/** @} */
