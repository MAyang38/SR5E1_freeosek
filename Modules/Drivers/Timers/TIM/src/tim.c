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
 * @file    tim.c
 * @brief   TIM driver source file.
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

/*===========================================================================*/
/* Module local definitions.                                                 */
/*===========================================================================*/

/**
 * @brief   Mask of the allowed DIER settings in configuration.
 */
#define TIM_DIER_CFG_ALLOWED           (TIM_DIER_TDE   | TIM_DIER_UDE   |   \
                                        TIM_DIER_CC4DE | TIM_DIER_CC3DE |   \
                                        TIM_DIER_CC2DE | TIM_DIER_CC1DE)

/**
 * @brief   Mask of the handled TIM IRQ status bits.
 */
#define TIM_DIER_IRQ_MASK              (TIM_DIER_CC4IE | TIM_DIER_CC3IE |   \
                                        TIM_DIER_CC2IE | TIM_DIER_CC1IE |   \
                                        TIM_DIER_UIE)

/**
 * @brief   Mask of TIM CR1 fixed bits.
 */
#define TIM_CR1_FIXED_BITS             (TIM_CR1_ARPE   | TIM_CR1_URS    |   \
                                        TIM_CR1_CEN)

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
 * @brief   Resets TIM parameters.
 *
 * @param[out] tdp      pointer to an @p tim_driver_t structure to
 *                      be reset
 *
 * @notapi
 */
static void tim_reset_paramters(tim_driver_t *tdp) {

    uint8_t i;

    /* Set all driver configuration parameters to default values.*/
    tdp->is_enable = false;
    tdp->ckd       = TIM_CKD_1;
    tdp->prio      = IRQ_MIN_PRIORITY;
    tdp->presc     = 0x0U;
    tdp->rdt       = 0U;
    tdp->fdt       = 0U;

    for (i = 0U; i < (uint8_t)TIM_MAX_CH_NUM; i++) {
        tdp->ch_mode[i] = TIM_MODE_PERIODIC;
    }

    tdp->trgo  = TIM_TRGO_RESET;
    tdp->trgo2 = TIM_TRGO2_RESET;
    tdp->sms   = TIM_SMODE_DISABLED;
    tdp->trgi  = TIM_TRGI_ITR0;
    tdp->etf   = 0U;
    tdp->etps  = TIM_ETPS_DIV1;
    tdp->etp   = TIM_ETPS_NOT_INVERTED;

    for (i = 0U; i < (uint8_t)TIM_CB_OPS_MAX; i++) {
        tdp->cb[i] = NULL;
    }
}

/*===========================================================================*/
/* Module exported functions.                                                */
/*===========================================================================*/

void tim_init(tim_driver_t *tdp) {

    /* Set pointer to TIM register block.*/
    tdp->tim     = tim_dev_get_reg_ptr(tdp);
    /* Set TIM clock value based on clocktree configuration.*/
    tdp->clock   = tim_dev_get_clock(tdp);
    /* Set BDTR flag.*/
    tdp->is_bdtr = tim_dev_is_bdtr(tdp);
    /* Set the number of channels related to the TIM.*/
    tdp->ch_num  = tim_dev_get_ch_num(tdp);

    /* Reset TIM parameters.*/
    tim_reset_paramters(tdp);
}

tim_ckd_t tim_set_ckd(tim_driver_t *tdp, tim_ckd_t ckd) {

    tim_ckd_t prev_ckd;

    prev_ckd = tdp->ckd;
    tdp->ckd = ckd;

    return prev_ckd;
}

uint32_t tim_set_prio(tim_driver_t *tdp, uint32_t prio) {

    uint32_t prev_prio;

    prev_prio = tdp->prio;
    tdp->prio = prio;

    return prev_prio;
}

tim_presc_t tim_set_presc(tim_driver_t *tdp, tim_presc_t presc) {

    tim_presc_t prev_presc;

    prev_presc = tdp->presc;
    tdp->presc = presc;

    return prev_presc;
}

void tim_set_dt(tim_driver_t *tdp, uint32_t rdt, uint32_t fdt) {

    tdp->rdt = rdt;
    tdp->fdt = fdt;
}

tim_mode_t tim_set_ch_mode(tim_driver_t *tdp, uint8_t channel,
                           tim_mode_t ch_mode) {

    tim_mode_t prev_ch_mode;

    prev_ch_mode               = tdp->ch_mode[channel - 1U];
    tdp->ch_mode[channel - 1U] = ch_mode;

    return prev_ch_mode;
}

tim_trgo_t tim_set_trgo(tim_driver_t *tdp, tim_trgo_t trgo) {

    tim_trgo_t prev_trgo;

    prev_trgo = tdp->trgo;
    tdp->trgo = trgo;

    return prev_trgo;
}

tim_trgo2_t tim_set_trgo2(tim_driver_t *tdp, tim_trgo2_t trgo2) {

    tim_trgo2_t prev_trgo2;

    prev_trgo2 = tdp->trgo2;
    tdp->trgo2 = trgo2;

    return prev_trgo2;
}

tim_sms_t tim_set_sms(tim_driver_t *tdp, tim_sms_t sms) {

    tim_sms_t prev_sms;

    prev_sms = tdp->sms;
    tdp->sms = sms;

    return prev_sms;
}

tim_trgi_t tim_set_trgi(tim_driver_t *tdp, tim_trgi_t trgi) {

    tim_trgi_t prev_trgi;

    prev_trgi = tdp->trgi;
    tdp->trgi = trgi;

    return prev_trgi;
}

uint8_t tim_set_etf(tim_driver_t *tdp, uint8_t etf) {

    uint8_t prev_etf;

    prev_etf = tdp->etf;
    tdp->etf = etf;

    return prev_etf;

}

tim_etps_t tim_set_etps(tim_driver_t *tdp, tim_etps_t etps) {

    tim_etps_t prev_etps;

    prev_etps = tdp->etps;
    tdp->etps = etps;

    return prev_etps;
}

tim_etp_t tim_set_etp(tim_driver_t *tdp, tim_etp_t etp) {

    tim_etp_t prev_etp;

    prev_etp = tdp->etp;
    tdp->etp = etp;

    return prev_etp;
}

tim_cb_t tim_set_cb(tim_driver_t *tdp, tim_cb_ops_t cb_op, tim_cb_t cb) {

    tim_cb_t prev_cb;

    prev_cb        = tdp->cb[cb_op];
    tdp->cb[cb_op] = cb;

    return prev_cb;
}

void tim_start(tim_driver_t *tdp) {

    uint32_t cr2, ccer, smcr, ccmr1, ccmr2;
    uint8_t i;

    /* Enable clock.*/
    tim_dev_clock_enable(tdp);

    /* Update enable status.*/
    tdp->is_enable = true;

    /* Configure and enable interrupts.*/
    tim_dev_enable_irq(tdp, tdp->prio);

    /* Channel settings.*/
    ccer  = 0U;
    ccmr1 = 0U;
    ccmr2 = 0U;

    /* Mode-specific initializations.*/
    for (i = 0U; i < TIM_MAX_CH_NUM; i++) {
        switch (tdp->ch_mode[i]) {
        case TIM_MODE_PERIODIC:

            break;
        case TIM_MODE_PWM_ACTIVE_HIGH_COMP:
            switch(i) {
            case 0U:
                ccer |= TIM_CCER_CC1NE;
                break;
            case 1U:
                ccer |= TIM_CCER_CC2NE;
                break;
            case 2U:
                ccer |= TIM_CCER_CC3NE;
                break;
            case 3U:
                ccer |= TIM_CCER_CC4NE;
                break;
            default:
                /* for MISRA compliance */
                break;
            }
            /* Fall-through.*/
        case TIM_MODE_PWM_ACTIVE_HIGH:
            switch(i) {
            case 0U:
                ccer  |= TIM_CCER_CC1E;
                ccmr1 |= TIM_CCMR1_OC1M_VALUE(6U) | TIM_CCMR1_OC1PE;
                break;
            case 1U:
                ccer  |= TIM_CCER_CC2E;
                ccmr1 |= TIM_CCMR1_OC2M_VALUE(6U) | TIM_CCMR1_OC2PE;
                break;
            case 2U:
                ccer  |= TIM_CCER_CC3E;
                ccmr2 |= TIM_CCMR2_OC3M_VALUE(6U) | TIM_CCMR2_OC3PE;
                break;
            case 3U:
                ccer  |= TIM_CCER_CC4E;
                ccmr2 |= TIM_CCMR2_OC4M_VALUE(6U) | TIM_CCMR2_OC4PE;
                break;
            default:
                /* for MISRA compliance */
                break;
            }
            break;
        case TIM_MODE_ICU_RISING_EDGE:
            switch(i) {
            case 0U:
                ccer  |= TIM_CCER_CC1E;
                ccmr1 |= TIM_CCMR1_CC1S_0;
                break;
            case 1U:
                ccer  |= TIM_CCER_CC2E;
                ccmr1 |= TIM_CCMR1_CC2S_0;
                break;
            case 2U:
                ccer  |= TIM_CCER_CC3E;
                ccmr2 |= TIM_CCMR2_CC3S_0;
                break;
            case 3U:
                ccer  |= TIM_CCER_CC4E;
                ccmr2 |= TIM_CCMR2_CC4S_0;
                break;
            default:
                /* for MISRA compliance */
                break;
            }
            break;
        case TIM_MODE_ICU_FALLING_EDGE:
            switch(i) {
            case 0U:
                ccer  |= TIM_CCER_CC1E | TIM_CCER_CC1P;
                ccmr1 |= TIM_CCMR1_CC1S_0;
                break;
            case 1U:
                ccer  |= TIM_CCER_CC2E | TIM_CCER_CC2P;
                ccmr1 |= TIM_CCMR1_CC2S_0;
                break;
            case 2U:
                ccer  |= TIM_CCER_CC3E | TIM_CCER_CC3P;
                ccmr2 |= TIM_CCMR2_CC3S_0;
                break;
            case 3U:
                ccer  |= TIM_CCER_CC4E | TIM_CCER_CC4P;
                ccmr2 |= TIM_CCMR2_CC4S_0;
                break;
            default:
                /* for MISRA compliance */
                break;
            }
            break;
        case TIM_MODE_ICU_BOTH_EDGES:
            switch(i) {
            case 0U:
                ccer  |= TIM_CCER_CC1E | TIM_CCER_CC1P | TIM_CCER_CC1NP;
                ccmr1 |= TIM_CCMR1_CC1S_0;
                break;
            case 1U:
                ccer  |= TIM_CCER_CC2E | TIM_CCER_CC2P | TIM_CCER_CC2NP;
                ccmr1 |= TIM_CCMR1_CC2S_0;
                break;
            case 2U:
                ccer  |= TIM_CCER_CC3E | TIM_CCER_CC3P | TIM_CCER_CC3NP;
                ccmr2 |= TIM_CCMR2_CC3S_0;
                break;
            case 3U:
                ccer  |= TIM_CCER_CC4E | TIM_CCER_CC4P | TIM_CCER_CC4NP;
                ccmr2 |= TIM_CCMR2_CC4S_0;
                break;
            default:
                /* for MISRA compliance */
                break;
            }
            break;
        case TIM_MODE_ICU_RISING_EDGE_IND:
            switch(i) {
            case 0U:
                ccer  |= TIM_CCER_CC1E;
                ccmr1 |= TIM_CCMR1_CC1S_1;
                break;
            case 1U:
                ccer  |= TIM_CCER_CC2E;
                ccmr1 |= TIM_CCMR1_CC2S_1;
                break;
            case 2U:
                ccer  |= TIM_CCER_CC3E;
                ccmr2 |= TIM_CCMR2_CC3S_1;
                break;
            case 3U:
                ccer  |= TIM_CCER_CC4E;
                ccmr2 |= TIM_CCMR2_CC4S_1;
                break;
            default:
                /* for MISRA compliance */
                break;
            }
            break;
        case TIM_MODE_ICU_FALLING_EDGE_IND:
            switch(i) {
            case 0U:
                ccer  |= TIM_CCER_CC1E | TIM_CCER_CC1P;
                ccmr1 |= TIM_CCMR1_CC1S_1;
                break;
            case 1U:
                ccer  |= TIM_CCER_CC2E | TIM_CCER_CC2P;
                ccmr1 |= TIM_CCMR1_CC2S_1;
                break;
            case 2U:
                ccer  |= TIM_CCER_CC3E | TIM_CCER_CC3P;
                ccmr2 |= TIM_CCMR2_CC3S_1;
                break;
            case 3U:
                ccer  |= TIM_CCER_CC4E | TIM_CCER_CC4P;
                ccmr2 |= TIM_CCMR2_CC4S_1;
                break;
            default:
                /* for MISRA compliance */
                break;
            }
            break;

        default:
            /* for MISRA compliance */
            break;
        }
    }

    cr2 = 0UL;
    /* Configure trigger outputs.*/
    if (tdp->trgo >= TIM_TRGO_ENCODERCLK) {
        cr2 |= TIM_CR2_MMS_3 | ((0x7UL & ((uint32_t)tdp->trgo)) << TIM_CR2_MMS_Pos);
    } else {
        cr2 |= ((uint32_t)tdp->trgo) << TIM_CR2_MMS_Pos;
    }
    /* Configure trigger outputs 2.*/
    cr2 |= ((uint32_t)tdp->trgo2) << TIM_CR2_MMS2_Pos;

    /* Configure slave mode control.*/
    smcr = 0UL;
    smcr |= ((TIM_SMCR_SMS_Msk  & ((uint32_t)tdp->sms))  << TIM_SMCR_SMS_Pos)  |
            ((0x7UL             & ((uint32_t)tdp->trgi)) << TIM_SMCR_TS_Pos)   |
            ((TIM_SMCR_ETF_Msk  & ((uint32_t)tdp->etf))  << TIM_SMCR_ETF_Pos)  | 
            ((TIM_SMCR_ETPS_Msk & ((uint32_t)tdp->etps)) << TIM_SMCR_ETPS_Pos) |
            ((TIM_SMCR_ETP_Msk  & ((uint32_t)tdp->etp))  << TIM_SMCR_ETP_Pos)  |
            ((0x3UL             & (((uint32_t)tdp->trgi) >> 3U)) << 20U); 

    /* Timer initialization.*/
    tdp->tim->CR1   = ((uint32_t)(tdp->ckd)) << TIM_CR1_CKD_Pos; /* Initially stopped.*/
    tdp->tim->CR2   = cr2;
    tdp->tim->SMCR  = smcr;
    tdp->tim->PSC   = tdp->presc;
    tdp->tim->CNT   = 0U;
    tdp->tim->ARR   = 0U;
    tdp->tim->CCMR1 = ccmr1;
    tdp->tim->CCMR2 = ccmr2;
    tdp->tim->CCR1  = 0U;
    tdp->tim->CCR2  = 0U;
    tdp->tim->CCR3  = 0U;
    tdp->tim->CCR4  = 0U;
    tdp->tim->CCER  = ccer;
    if (tdp->is_bdtr == true) {
        tdp->tim->BDTR = TIM_BDTR_AOE;
        tdp->tim->DTR2 = 0U;
        if (tdp->rdt != 0U || tdp->fdt != 0U) {
            const uint8_t dtg  = tim_dev_get_rdtg(tdp);
            const uint8_t dtgf = tim_dev_get_fdtg(tdp);
            tdp->tim->BDTR |= TIM_BDTR_DTG_VALUE(dtg);
            tdp->tim->DTR2 |= TIM_DTR2_DTAE | TIM_DTR2_DTGF_VALUE(dtgf);
        }
    }
    tdp->tim->EGR   = TIM_EGR_UG;
    tdp->tim->SR    = 0U;
    //tdp->tim->DIER  = tdp->DIER & TIM_DIER_CFG_ALLOWED; //TODO: manage DMA request enable with specific APIs
}

void tim_enable(tim_driver_t *tdp) {

    if (tdp->is_enable == true) {
        tdp->tim->CR1 |= TIM_CR1_FIXED_BITS;
    }
}

void tim_disable(tim_driver_t *tdp) {

    if (tdp->is_enable == true) {
        tdp->tim->CR1 &= ~(TIM_CR1_FIXED_BITS);
        tdp->tim->SR  = 0U;
    }
}

void tim_enable_update_callback(tim_driver_t *tdp) {

    uint32_t dier;

    if (tdp->is_enable == true) {
        dier = tdp->tim->DIER;
        if ((dier & TIM_DIER_UIE) == 0U) {
            tdp->tim->SR   = ~TIM_SR_UIF;
            tdp->tim->DIER =  TIM_DIER_UIE | dier;
        }
    }
}

void tim_disable_update_callback(tim_driver_t *tdp) {

    if (tdp->is_enable == true) {
        tdp->tim->DIER &= ~TIM_DIER_UIE;
    }
}

void tim_enable_channel_callback(tim_driver_t *tdp, uint8_t channel) {

    uint32_t dier;

    if (tdp->is_enable == true) {
        dier = tdp->tim->DIER;
        if ((dier & (2UL << (channel - 1U))) == 0U) {
            tdp->tim->SR   = ~(2UL << (channel - 1U));
            tdp->tim->DIER =  (2UL << (channel - 1U)) | dier;
        }
    }
}

void tim_disable_channel_callback(tim_driver_t *tdp, uint8_t channel) {

    if (tdp->is_enable == true) {
        tdp->tim->DIER &= ~(2UL << (channel - 1U));
    }
}

void tim_set_interval(tim_driver_t *tdp, uint32_t interval) {

    if (tdp->is_enable == true) {
        tdp->tim->ARR = interval - 1U;
    }
}

uint32_t tim_get_interval(tim_driver_t *tdp) {

    if (tdp->is_enable == true) {
        return tdp->tim->ARR;
    } else {
        return 0U;
    }
}

void tim_set_comparator(tim_driver_t *tdp, uint8_t channel, uint32_t cmpval) {

    if (tdp->is_enable == true) {
        switch (channel) {
            case 1U:
                tdp->tim->CCR1 = cmpval;
                break;
            case 2U:
                tdp->tim->CCR2 = cmpval;
                break;
            case 3U:
                tdp->tim->CCR3 = cmpval;
                break;
            case 4U:
                tdp->tim->CCR4 = cmpval;
                break;
            case 5U:
                tdp->tim->CCR5 = cmpval;
                break;
            case 6U:
                tdp->tim->CCR6 = cmpval;
                break;
            default:
                /* dummy comment as required by MISRA.*/
                break;
        }
    }
}

uint32_t tim_get_comparator(tim_driver_t *tdp, uint8_t channel) {

    if (tdp->is_enable == true) {
        switch (channel) {
            case 1U:
                return tdp->tim->CCR1;
            case 2U:
                return tdp->tim->CCR2;
            case 3U:
                return tdp->tim->CCR3;
            case 4U:
                return tdp->tim->CCR4;
            case 5U:
                return tdp->tim->CCR5;
            case 6U:
                return tdp->tim->CCR6;
            default:
                return 0U;
        }
    } else {
        return 0U;
    }
}

void tim_stop(tim_driver_t *tdp) {

    /* Stopping the timer.*/
    tdp->tim->CR1   = 0U;
    tdp->tim->CR2   = 0U;
    tdp->tim->SMCR  = 0U;
    tdp->tim->PSC   = 0U;
    tdp->tim->CCMR1 = 0U;
    tdp->tim->CCMR2 = 0U;
    tdp->tim->DIER  = 0U;
    tdp->tim->SR    = 0U;

    /* Disable interrupts.*/
    tim_dev_disable_irq(tdp);

    /* Update enable status.*/
    tdp->is_enable = false;

    /* Disable clock.*/
    tim_dev_clock_disable(tdp);

    tdp->tim = NULL;
}

void tim_deinit(tim_driver_t *tdp) {

    /* Set pointer to TIM register block to NULL.*/
    tdp->tim     = NULL;
    /* Set TIM clock value to 0.*/
    tdp->clock   = 0U;
    /* Set BDTR flag to false.*/
    tdp->is_bdtr = false;
    /* Set the number of channels related to the TIM to 0.*/
    tdp->ch_num  = 0U;

    /* Reset TIM parameters.*/
    tim_reset_paramters(tdp);
}

void __tim_serve_interrupt(tim_driver_t *tdp) {

    uint32_t sr;

    sr  = tdp->tim->SR;
    sr &= tdp->tim->DIER & TIM_DIER_IRQ_MASK;
    tdp->tim->SR = ~sr;

    if (((sr & TIM_SR_UIF) != 0U) && (tdp->cb[TIM_CB_OPS_UPDATE] != NULL)) {
        tdp->cb[TIM_CB_OPS_UPDATE](tdp);
    }

    if (((sr & TIM_SR_CC1IF) != 0U) && (tdp->cb[TIM_CB_OPS_CC1] != NULL)) {
        tdp->cb[TIM_CB_OPS_CC1](tdp);
    }

    if (((sr & TIM_SR_CC2IF) != 0U) && (tdp->cb[TIM_CB_OPS_CC2] != NULL)) {
        tdp->cb[TIM_CB_OPS_CC2](tdp);
    }

    if (((sr & TIM_SR_CC3IF) != 0U) && (tdp->cb[TIM_CB_OPS_CC3] != NULL)) {
        tdp->cb[TIM_CB_OPS_CC3](tdp);
    }

    if (((sr & TIM_SR_CC4IF) != 0U) && (tdp->cb[TIM_CB_OPS_CC4] != NULL)) {
        tdp->cb[TIM_CB_OPS_CC4](tdp);
    }
}

/** @} */
