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
 * @file    hrtim.c
 * @brief   HRTIM driver source file.
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

/*===========================================================================*/
/* Module local definitions.                                                 */
/*===========================================================================*/

/**
 * @brief   HRTIM CR1 fixed bits.
 */
#define HRTIM_CR1_CFG_FORBIDDEN             (HRTIM_CR1_MUDIS  |             \
                                             HRTIM_CR1_TAUDIS |             \
                                             HRTIM_CR1_TBUDIS |             \
                                             HRTIM_CR1_TCUDIS |             \
                                             HRTIM_CR1_TDUDIS |             \
                                             HRTIM_CR1_TEUDIS |             \
                                             HRTIM_CR1_TFUDIS)

/**
 * @brief   HRTIM CR2 fixed bits.
 */
#define HRTIM_CR2_CFG_FORBIDDEN             (HRTIM_CR2_MSWU   |             \
                                             HRTIM_CR2_TASWU  |             \
                                             HRTIM_CR2_TBSWU  |             \
                                             HRTIM_CR2_TCSWU  |             \
                                             HRTIM_CR2_TDSWU  |             \
                                             HRTIM_CR2_TESWU  |             \
                                             HRTIM_CR2_TFSWU  |             \
                                             HRTIM_CR2_MRST   |             \
                                             HRTIM_CR2_TARST  |             \
                                             HRTIM_CR2_TBRST  |             \
                                             HRTIM_CR2_TCRST  |             \
                                             HRTIM_CR2_TDRST  |             \
                                             HRTIM_CR2_TERST  |             \
                                             HRTIM_CR2_TFRST)

/**
 * @brief   HRTIM DLLCR fixed bits.
 */
#define HRTIM_DLLCR_CFG_FORBIDDEN           (HRTIM_DLLCR_CAL)

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
 * @brief   Resets HRTIM parameters.
 *
 * @param[out] hdp      pointer to an @p hrtim_driver_t structure to
 *                      be reset
 *
 * @notapi
 */
static void hrtim_reset_paramters(hrtim_driver_t *hdp) {

    uint8_t timer, comparator, set, output, adctrigger, eev_index, flt_index;

    /* Set all driver configuration parameters to default values.*/
    hdp->is_enable = false;

    /* Set DLL calibration periodicity: 1048576 * tHRTIM (3.495 ms for fHRTIM
       = 300 MHz).*/
    hdp->cal_period = HRTIM_DLLCR_CALRTE_DIV1048576;

    hdp->prio = IRQ_MIN_PRIORITY;

    hdp->master_mode = HRTIM_MODE_SINGLE_SHOT_NO_RETRIGGERED;
    hdp->master_prescaler = HRTIM_PRSC_DIV1;
    hdp->master_period = 0U;
    for (comparator = 0U; comparator < (uint8_t)HRTIM_COMP_NUM; comparator++) {
        hdp->master_cmp[comparator] = 0U;
    }

    hdp->master_preload.enable = HRTIM_PRELOAD_DISABLED;
    hdp->master_preload.update_event = HRTIM_TIMUPDATETRIGGER_NONE;
    hdp->master_mode_tpg = HRTIM_MODE_HALF_INTLVD_DISABLED;

    for (timer = 0U; timer < (uint8_t)HRTIM_TIMER_NUM; timer++) {
        hdp->timer_cntr_mode[timer] = HRTIM_MODE_SINGLE_SHOT_NO_RETRIGGERED;
        hdp->timer_prescaler[timer] = HRTIM_PRSC_DIV1;
        hdp->timer_period[timer] = 0U;

        for (comparator = 0U; comparator < (uint8_t)HRTIM_COMP_NUM; comparator++) {
            hdp->timer_cmp[timer][comparator] = 0U;
            /* Comparator auto-delayed mode is available only for
               [TimerA:TimerF] and Comparator 2 or Comparator 4).*/
            hdp->timer_cmp_ad_mode[timer][comparator] = HRTIM_CMP_AD_MODE_STANDARD;
        }

        hdp->deadtime[timer].enable    = false;
        hdp->deadtime[timer].prescaler = HRTIM_DT_PRSC_DIV1;
        hdp->deadtime[timer].rvalue    = 0U;
        hdp->deadtime[timer].rsign     = HRTIM_DT_SIGN_POSITIVE;
        hdp->deadtime[timer].fvalue    = 0U;
        hdp->deadtime[timer].fsign     = HRTIM_DT_SIGN_POSITIVE;

        hdp->cb[timer] = NULL;

        hdp->timer_preload[timer].enable = HRTIM_PRELOAD_DISABLED;
        hdp->timer_preload[timer].update_event = HRTIM_TIMUPDATETRIGGER_NONE;
        hdp->timer_mode_tpg[timer] = HRTIM_MODE_HALF_INTLVD_DISABLED;

        hdp->timer_count_mode[timer].up_down_enable = false;
        hdp->timer_count_mode[timer].up_down_mode = HRTIM_COUNTING_MODE_UP;

        for (eev_index = 0U; eev_index < (uint8_t)HRTIM_EXEVENT_NUM; eev_index++) {
            hdp->eev_counter[timer][eev_index].reset_mode = 0U;
            hdp->eev_counter[timer][eev_index].source = 0U;

            hdp->timer_eev_filter[timer][eev_index].latch = 0U;
            hdp->timer_eev_filter[timer][eev_index].filter = 0U;
        }

        hdp->timer_count_mode[timer].fault_event_rollover = HRTIM_ROLLOVER_MODE_BOTH;
        hdp->timer_count_mode[timer].rollover = HRTIM_ROLLOVER_MODE_BOTH;
        hdp->timer_count_mode[timer].out_rollover = HRTIM_ROLLOVER_MODE_BOTH;
        hdp->timer_count_mode[timer].adc_rollover = HRTIM_ROLLOVER_MODE_BOTH;
        hdp->timer_count_mode[timer].burstmode_rollover = HRTIM_ROLLOVER_MODE_BOTH;

        hdp->timer_dualdac_enable[timer] = 0;

        hdp->fault_state[timer][0]  = HRTIM_OUTPUT_FAULTSTATE_NOACTIVE;
        hdp->fault_state[timer][1]  = HRTIM_OUTPUT_FAULTSTATE_NOACTIVE;
        hdp->idle_state[timer][0]   = HRTIM_OUTPUT_IDLESTATE_INACTIVE;
        hdp->idle_state[timer][1]   = HRTIM_OUTPUT_IDLESTATE_INACTIVE;
        hdp->out_polarity[timer][0] = HRTIM_OUTPUT_POLARITY_POSITIVE;
        hdp->out_polarity[timer][1] = HRTIM_OUTPUT_POLARITY_POSITIVE;

        hdp->cpt_unit[timer].capture_trg_1 = HRTIM_CAPTURE_TRG_NONE;
        hdp->cpt_unit[timer].capture_trg_2 = HRTIM_CAPTURE_TRG_NONE;		
    }

    hdp->cb_mt  = NULL;
    hdp->cb_flt = NULL;

    for (set = 0U; set < (uint8_t)HRTIM_EVENT_NUM; set++) {
        for (output = 0U; output < (uint8_t)HRTIM_OUTPUT_NUM; output++) {
            hdp->set_event[set][output] = HRTIM_OUTPUT_NONE;
            hdp->rst_event[set][output] = HRTIM_OUTPUT_NONE;
        }
    }

    for (adctrigger = 0U; adctrigger < (uint8_t)HRTIM_ADCTRIG_NUM; adctrigger++) {
       hdp->adc_trg[adctrigger].update_src = 0U;
       hdp->adc_trg[adctrigger].event_trigger = 0U;
       hdp->adc_trg[adctrigger].post_scaler_rate = 0U;
    }

    for (eev_index = 0U; eev_index < (uint8_t)HRTIM_EXEVENT_NUM; eev_index++) {
       hdp->eev[eev_index].event = (uint8_t)eev_index;
       hdp->eev[eev_index].source = 0U;
       hdp->eev[eev_index].polarity = 0U;
       hdp->eev[eev_index].sensitivity = 0U;
       hdp->eev[eev_index].filter = 0U;
       hdp->eev[eev_index].fast_mode = 0U;
    }

    hdp->eev_prescaler = HRTIM_EVENTPRESCALER_DIV1;

    for (flt_index = 0U; flt_index < (uint8_t)HRTIM_FAULT_NUM; flt_index++) {
        hdp->fault[flt_index].fault_idx = HRTIM_NO_FAULT;
        hdp->fault[flt_index].enable = false;
        hdp->fault[flt_index].source = 0U;
        hdp->fault[flt_index].polarity = HRTIM_FAULTPOLARITY_LOW;
        hdp->fault[flt_index].filter = HRTIM_FAULTFILTER_NONE;
        hdp->fault[flt_index].lock = HRTIM_FAULTLOCK_READWRITE;

        hdp->fault_blnk[flt_index].threshold = 0U;
        hdp->fault_blnk[flt_index].reset_mode = HRTIM_FAULTCOUNTERRST_UNCONDITIONAL;
        hdp->fault_blnk[flt_index].blanking_source = HRTIM_FAULTBLANKINGMODE_RSTALIGNED;
    }

    hdp->fault_prescaler = HRTIM_FAULTPRESCALER_DIV1;
}

/*===========================================================================*/
/* Module exported functions.                                                */
/*===========================================================================*/

void hrtim_init(hrtim_driver_t *hdp) {

    /* Set pointer to HRTIM register block.*/
    hdp->hrtim = hrtim_dev_get_reg_ptr(hdp);

    /* Set HRTIM clock value based on clocktree configuration.*/
    hdp->clock = hrtim_dev_get_clock(hdp);

    /* Reset HRTIM parameters.*/
    hrtim_reset_paramters(hdp);
}

uint32_t hrtim_set_prio(hrtim_driver_t *hdp, uint32_t prio) {

    uint32_t prev_prio;

    prev_prio = hdp->prio;
    hdp->prio = prio;

    return prev_prio;
}

hrtim_cntr_mode_t hrtim_set_timer_mode(hrtim_driver_t *hdp, hrtim_timer_t timer,
                                       hrtim_cntr_mode_t mode) {
    hrtim_cntr_mode_t prev_mode;

    if (timer == HRTIM_TIMER_MASTER) {
        prev_mode = hdp->master_mode;
        hdp->master_mode = mode;
    } else {
        prev_mode = hdp->timer_cntr_mode[timer];
        hdp->timer_cntr_mode[timer] = mode;
    }

    return prev_mode;
}

hrtim_prsc_t hrtim_timer_set_prescaler(hrtim_driver_t *hdp, hrtim_timer_t timer,
                                       hrtim_prsc_t prescaler) {

    hrtim_prsc_t prev_prescaler;

    if (timer == HRTIM_TIMER_MASTER) {
        prev_prescaler = hdp->master_prescaler;
        hdp->master_prescaler = prescaler;
    } else {
        prev_prescaler = hdp->timer_prescaler[timer];
        hdp->timer_prescaler[timer] = prescaler;
    }

    /* Update on-fly.*/
    if (hdp->is_enable == true) {
        if (timer == HRTIM_TIMER_MASTER) {
            hdp->hrtim->sMasterRegs.MCR |= (((uint32_t)prescaler) & HRTIM_MCR_CK_PSC_Msk);
        } else {
            hdp->hrtim->sTimerxRegs[timer].TIMxCR |= (((uint32_t)prescaler) & HRTIM_MCR_CK_PSC_Msk);
        }
    }

    return prev_prescaler;
}

hrtim_prsc_t hrtim_timer_get_prescaler(hrtim_driver_t *hdp, hrtim_timer_t timer) {

    if (timer == HRTIM_TIMER_MASTER) {
        return hdp->master_prescaler;
    } else {
        return hdp->timer_prescaler[timer];
    }
}

uint16_t hrtim_timer_set_period(hrtim_driver_t *hdp, hrtim_timer_t timer,
                                uint16_t period) {
    uint16_t prev_period;

    if (timer == HRTIM_TIMER_MASTER) {
        prev_period = hdp->master_period;
        hdp->master_period = period;
    } else {
        prev_period = hdp->timer_period[timer];
        hdp->timer_period[timer] = period;
    }

    /* Update on-fly.*/
    if (hdp->is_enable == true) {
        if (timer == HRTIM_TIMER_MASTER) {
            hdp->hrtim->sMasterRegs.MPER = (uint32_t)period;
        } else {
            hdp->hrtim->sTimerxRegs[timer].PERxR = (uint32_t)period;
        }
    }

    return prev_period;
}

uint16_t hrtim_timer_get_period(hrtim_driver_t *hdp, hrtim_timer_t timer) {

    if (timer == HRTIM_TIMER_MASTER) {
        return hdp->master_period;
    } else {
        return hdp->timer_period[timer];
    }
}

uint16_t hrtim_timer_set_cmp(hrtim_driver_t *hdp, hrtim_timer_t timer,
                             hrtim_cmp_t comparator, uint16_t value) {

    uint16_t prev_value = 0U;

    if (timer == HRTIM_TIMER_MASTER) {
        switch (comparator) {
            case HRTIM_CMP1:
                prev_value = hdp->master_cmp[HRTIM_CMP1];
                hdp->master_cmp[HRTIM_CMP1] = value;
                break;
            case HRTIM_CMP2:
                prev_value = hdp->master_cmp[HRTIM_CMP2];
                hdp->master_cmp[HRTIM_CMP2] = value;
                break;
            case HRTIM_CMP3:
                prev_value = hdp->master_cmp[HRTIM_CMP3];
                hdp->master_cmp[HRTIM_CMP3] = value;
                break;
            case HRTIM_CMP4:
                prev_value = hdp->master_cmp[HRTIM_CMP4];
                hdp->master_cmp[HRTIM_CMP4] = value;
                break;
            default:
                /* for MISRA compliance */
                break;
        }
    } else {
        switch (comparator) {
            case HRTIM_CMP1:
                prev_value = hdp->timer_cmp[timer][HRTIM_CMP1];
                hdp->timer_cmp[timer][HRTIM_CMP1] = value;
                break;
            case HRTIM_CMP2:
                prev_value = hdp->timer_cmp[timer][HRTIM_CMP2];
                hdp->timer_cmp[timer][HRTIM_CMP2] = value;
                break;
            case HRTIM_CMP3:
                prev_value = hdp->timer_cmp[timer][HRTIM_CMP3];
                hdp->timer_cmp[timer][HRTIM_CMP3] = value;
                break;
            case HRTIM_CMP4:
                prev_value = hdp->timer_cmp[timer][HRTIM_CMP4];
                hdp->timer_cmp[timer][HRTIM_CMP4] = value;
                break;
            default:
                /* for MISRA compliance */
                break;
        }
    }

    /* Update on-fly.*/
    if (hdp->is_enable == true) {
        if (timer == HRTIM_TIMER_MASTER) {
            switch (comparator) {
                case HRTIM_CMP1:
                    hdp->hrtim->sMasterRegs.MCMP1R = (uint32_t)value;
                    break;
                case HRTIM_CMP2:
                    hdp->hrtim->sMasterRegs.MCMP2R = (uint32_t)value;
                    break;
                case HRTIM_CMP3:
                    hdp->hrtim->sMasterRegs.MCMP3R = (uint32_t)value;
                    break;
                case HRTIM_CMP4:
                    hdp->hrtim->sMasterRegs.MCMP4R = (uint32_t)value;
                    break;
                default:
                    /* for MISRA compliance */
                    break;
            }
        } else {
            switch (comparator) {
                case HRTIM_CMP1: 
                    hdp->hrtim->sTimerxRegs[timer].CMP1xR = (uint32_t)value;
                    break;
                case HRTIM_CMP2:
                    hdp->hrtim->sTimerxRegs[timer].CMP2xR = (uint32_t)value;
                    break;
                case HRTIM_CMP3:
                    hdp->hrtim->sTimerxRegs[timer].CMP3xR = (uint32_t)value;
                    break;
                case HRTIM_CMP4:
                    hdp->hrtim->sTimerxRegs[timer].CMP4xR = (uint32_t)value;
                    break;
                default:
                    /* for MISRA compliance */
                    break;
            }
        }
    }

    return prev_value;
}

uint16_t hrtim_timer_get_cmp(hrtim_driver_t *hdp, hrtim_timer_t timer,
                             hrtim_cmp_t comparator){

    if (timer == HRTIM_TIMER_MASTER) {
        switch (comparator) {
            case HRTIM_CMP1:
                return hdp->master_cmp[HRTIM_CMP1];
            case HRTIM_CMP2:
                return hdp->master_cmp[HRTIM_CMP2];
            case HRTIM_CMP3:
                return hdp->master_cmp[HRTIM_CMP3];
            case HRTIM_CMP4:
                return hdp->master_cmp[HRTIM_CMP4];
            default:
                /* for MISRA compliance */
                return 0U;
        }
    } else {
        switch (comparator) {
            case HRTIM_CMP1:
                return hdp->timer_cmp[timer][HRTIM_CMP1];
            case HRTIM_CMP2:
                return hdp->timer_cmp[timer][HRTIM_CMP2];
            case HRTIM_CMP3:
                return hdp->timer_cmp[timer][HRTIM_CMP3];
            case HRTIM_CMP4:
                return hdp->timer_cmp[timer][HRTIM_CMP4];
            default:
                /* for MISRA compliance */
                return 0U;
        }
    }
}

void hrtim_timer_set_autodelay(hrtim_driver_t *hdp,
                               hrtim_timer_t timer,
                               hrtim_cmp_t comparator,
                               hrtim_cmp_ad_mode_t mode) { 

    if (timer != HRTIM_TIMER_MASTER) {
        switch (comparator) {
            case HRTIM_CMP2:
                hdp->timer_cmp_ad_mode[timer][HRTIM_CMP2] = mode;
                break;
            case HRTIM_CMP4:
                hdp->timer_cmp_ad_mode[timer][HRTIM_CMP4] = mode;
                break;
            case HRTIM_CMP1:
            case HRTIM_CMP3:
            default:
                /* for MISRA compliance */
                break;
        }
	    
        /* Update on-fly.*/
        if (hdp->is_enable == true) {
            switch (comparator) {
                case HRTIM_CMP2:
                    hdp->hrtim->sTimerxRegs[timer].TIMxCR = ((uint32_t)mode) << HRTIM_TIMxCR_DELCMP2_Pos;
                    break;
                case HRTIM_CMP4:
                    hdp->hrtim->sTimerxRegs[timer].TIMxCR = ((uint32_t)mode) << HRTIM_TIMxCR_DELCMP4_Pos;
                    break;
                case HRTIM_CMP1:
                case HRTIM_CMP3:
                default:
                    /* for MISRA compliance */
                    break;
            }
        }
    }
}

void hrtim_timer_set_deadtime(hrtim_driver_t *hdp, hrtim_timer_t timer,
                              hrtim_dt_prsc_t prescaler,
                              uint16_t rvalue, hrtim_dt_sign_t rsign,
                              uint16_t fvalue, hrtim_dt_sign_t fsign) {

    hdp->deadtime[timer].prescaler = prescaler;
    hdp->deadtime[timer].rvalue    = rvalue;
    hdp->deadtime[timer].rsign     = rsign;
    hdp->deadtime[timer].fvalue    = fvalue;
    hdp->deadtime[timer].fsign     = fsign;

    /* Update on-fly.*/
    if (hdp->is_enable == true) {
        hdp->hrtim->sTimerxRegs[timer].DTxR = 0U;
        hdp->hrtim->sTimerxRegs[timer].DTxR = (((uint32_t)rvalue)    << HRTIM_DTxR_DTRx_Pos)   |
                                              (((uint32_t)rsign)     << HRTIM_DTxR_SDTRx_Pos)  |
                                              (((uint32_t)prescaler) << HRTIM_DTxR_DTPRSC_Pos) | 
                                              (((uint32_t)fvalue)    << HRTIM_DTxR_DTFx_Pos)   |
                                              (((uint32_t)fsign)     << HRTIM_DTxR_SDTFx_Pos);
    }
}

void hrtim_timer_enable_deadtime(hrtim_driver_t *hdp, hrtim_timer_t timer) {

    hdp->deadtime[timer].enable = true;
    if (hdp->is_enable == true) {
        hdp->hrtim->sTimerxRegs[timer].OUTxR = (1UL << HRTIM_OUTxR_DTEN_Pos);
    }
}

void hrtim_timer_disable_deadtime(hrtim_driver_t *hdp, hrtim_timer_t timer) {

    hdp->deadtime[timer].enable = false;
    if (hdp->is_enable == true) {
        hdp->hrtim->sTimerxRegs[timer].OUTxR = 0U;
    }
}

uint32_t hrtim_timer_set_outputset(hrtim_driver_t *hdp,
                                   hrtim_timer_t timer,
                                   hrtim_out_t output,
                                   uint32_t event) {

    uint32_t prev_event = hdp->set_event[timer][output];

    if (output == HRTIM_TIMER_OUTPUT_1) {
        hdp->set_event[timer][output] |= event;
    }

    if (output == HRTIM_TIMER_OUTPUT_2 && hdp->deadtime[timer].enable == false) {
        hdp->set_event[timer][output] |= event;
    }

    /* Update on-fly.*/
    if (hdp->is_enable == true) {
        if (output == HRTIM_TIMER_OUTPUT_1) {
            hdp->hrtim->sTimerxRegs[timer].SETx1R |= event;
        }

        if (output == HRTIM_TIMER_OUTPUT_2 && hdp->deadtime[timer].enable == false) {
            hdp->hrtim->sTimerxRegs[timer].SETx2R |= event;
        }
    }
 
    return prev_event;
} 

uint32_t hrtim_timer_set_outputrst(hrtim_driver_t *hdp,
                                   hrtim_timer_t timer,
                                   hrtim_out_t output,
                                   uint32_t event) {

    uint32_t prev_event = hdp->rst_event[timer][output];

    if(output == HRTIM_TIMER_OUTPUT_1) {
        hdp->rst_event[timer][output] |= event;
    }

    if (output == HRTIM_TIMER_OUTPUT_2 && hdp->deadtime[timer].enable == false) {
        hdp->rst_event[timer][output] |= event;
    }

    /* Update on-fly.*/
    if (hdp->is_enable == true) {
        if (output == HRTIM_TIMER_OUTPUT_1) {
            hdp->hrtim->sTimerxRegs[timer].RSTx1R |= event;
        }

        if (output == HRTIM_TIMER_OUTPUT_2 && hdp->deadtime[timer].enable == false) {
            hdp->hrtim->sTimerxRegs[timer].RSTx2R |= event;
        }
    }
    
    return prev_event;
}

uint32_t hrtim_timer_clear_outputset(hrtim_driver_t *hdp,
                                     hrtim_timer_t timer,
                                     hrtim_out_t output,
                                     uint32_t event) {

    uint32_t prev_event = hdp->set_event[timer][output];

    if (output == HRTIM_TIMER_OUTPUT_1) {
        hdp->set_event[timer][output] &= ~(event);
    }

    if (output == HRTIM_TIMER_OUTPUT_2 && hdp->deadtime[timer].enable == false) {
        hdp->set_event[timer][output] &= ~(event);
    }

    /* Update on-fly.*/
    if (hdp->is_enable == true) {
        if (output == HRTIM_TIMER_OUTPUT_1) {
            hdp->hrtim->sTimerxRegs[timer].SETx1R &= ~(event);
        }

        if (output == HRTIM_TIMER_OUTPUT_2 && hdp->deadtime[timer].enable == false) {
            hdp->hrtim->sTimerxRegs[timer].SETx2R &= ~(event);
        }
    }

    return prev_event;
} 

uint32_t hrtim_timer_clear_outputrst(hrtim_driver_t *hdp,
                                     hrtim_timer_t timer,
                                     hrtim_out_t output,
                                     uint32_t event) {

    uint32_t prev_event = hdp->rst_event[timer][output];

    if(output == HRTIM_TIMER_OUTPUT_1) {
        hdp->rst_event[timer][output] &= ~(event);
    }

    if (output == HRTIM_TIMER_OUTPUT_2 && hdp->deadtime[timer].enable == false) {
        hdp->rst_event[timer][output] &= ~(event);
    }

    /* Update on-fly.*/
    if (hdp->is_enable == true) {
        if (output == HRTIM_TIMER_OUTPUT_1) {
            hdp->hrtim->sTimerxRegs[timer].RSTx1R &= ~(event);
        }

        if (output == HRTIM_TIMER_OUTPUT_2 && hdp->deadtime[timer].enable == false) {
            hdp->hrtim->sTimerxRegs[timer].RSTx2R &= ~(event);
        }
    }

    return prev_event;
}

hrtim_cb_t hrtim_set_cb(hrtim_driver_t *hdp, hrtim_cb_ops_t cb_op, 
                        hrtim_cb_t cb) {

    hrtim_cb_t prev_cb;

    if (cb_op == HRTIM_CB_MASTER) {
        prev_cb = hdp->cb_mt;
        hdp->cb_mt = cb;
    } else if (cb_op == HRTIM_CB_FAULT) {
        prev_cb = hdp->cb_flt;
        hdp->cb_flt = cb;
    } else {
        prev_cb = hdp->cb[cb_op];
        hdp->cb[cb_op] = cb;
    }

    return prev_cb;
}

void hrtim_start(hrtim_driver_t *hdp) {

    uint32_t cr, mstr_cr; 
    uint8_t i;
    uint8_t  eev_idx;
    uint32_t hrtim_cr1;
    uint32_t hrtim_adcur;
    uint32_t hrtim_eecr1;
    uint32_t hrtim_eecr2;
    uint32_t hrtim_eecr3;
    uint32_t hrtim_eefr3;
    uint32_t hrtim_fltinr1;
    uint32_t hrtim_fltinr2;
    uint32_t source0,source1;
    uint32_t idx;

    /* Enable clock.*/
    hrtim_dev_clock_enable(hdp);

    /* Update enable status.*/
    hdp->is_enable = true;

    /* Configure and enable interrupts.*/
    hrtim_dev_enable_irq(hdp, hdp->prio);

    /* Setup calibration procedure and DLLC.*/
    hrtim_dev_calib_procedure(hdp);

    /* Timer settings.*/
    cr  = 0U;
    mstr_cr  = 0U;

    /* Mode-specific initializations.*/
    for (i = 0U; i < HRTIM_TIMER_NUM; i++) {
        switch (hdp->timer_cntr_mode[i]) {
            case HRTIM_MODE_SINGLE_SHOT_NO_RETRIGGERED:
                break;
            case HRTIM_MODE_SINGLE_SHOT_RETRIGGERED:
                cr |= HRTIM_TIMxCR_RETRIG;
                break;
            case HRTIM_MODE_CONTINUOS:
                cr |= HRTIM_TIMxCR_CONT;
                break;
            default:
                /* for MISRA compliance */
                break;
        }

        switch (hdp->timer_mode_tpg[i]) {
            case HRTIM_MODE_HALF_INTLVD_DISABLED:
                cr &= ~(HRTIM_TIMxCR_HALF     |
                        HRTIM_TIMxCR_INTLVD_0 |
                        HRTIM_TIMxCR_INTLVD_1);
                break;
            case HRTIM_MODE_TRIPLE_INTERVALLED:
                cr &= ~(HRTIM_TIMxCR_HALF);
                cr |= HRTIM_TIMxCR_INTLVD_0;
                break;
            case HRTIM_MODE_QUAD_INTERVALLED:
                cr &= ~(HRTIM_TIMxCR_HALF);
                cr |= HRTIM_TIMxCR_INTLVD_1;
                break;
            case HRTIM_MODE_DUAL_INTERVALLED:
                cr |= HRTIM_TIMxCR_HALF;
                break;
            case HRTIM_MODE_HALF:
                cr |= HRTIM_TIMxCR_HALF;
                break;
            default:
                /* for MISRA compliance */
                break;
        }

        /* Configure comparator auto-delayes modes.*/
        cr |= ((uint32_t)hdp->timer_cmp_ad_mode[i][HRTIM_CMP2]) << HRTIM_TIMxCR_DELCMP2_Pos |
              ((uint32_t)hdp->timer_cmp_ad_mode[i][HRTIM_CMP4]) << HRTIM_TIMxCR_DELCMP4_Pos;

        for (eev_idx = 0U; eev_idx < HRTIM_EXEVENT_NUM; eev_idx++) {
            /* Configure timer event filtering capabilities */
            switch (eev_idx) {
                case HRTIM_EVENT_NONE:
                    hdp->hrtim->sTimerxRegs[i].EEFxR1 = 0U;
                    hdp->hrtim->sTimerxRegs[i].EEFxR2 = 0U;
                    break;
                case HRTIM_EVENT_1:
                    hdp->hrtim->sTimerxRegs[i].EEFxR1 &= ~( HRTIM_EEFxR1_EE1LTCH| HRTIM_EEFxR1_EE1FLTR);
                    hdp->hrtim->sTimerxRegs[i].EEFxR1 |= (uint32_t)(hdp->timer_eev_filter[i][eev_idx - 1U].latch | hdp->timer_eev_filter[i][eev_idx - 1U].filter);
                    break;
                case HRTIM_EVENT_2:
                    hdp->hrtim->sTimerxRegs[i].EEFxR1 &= ~( HRTIM_EEFxR1_EE2LTCH| HRTIM_EEFxR1_EE2FLTR);
                    hdp->hrtim->sTimerxRegs[i].EEFxR1 |= (uint32_t)((hdp->timer_eev_filter[i][eev_idx - 1U].latch | hdp->timer_eev_filter[i][eev_idx - 1U].filter) << 6U);
                    break;
                case HRTIM_EVENT_3:
                    hdp->hrtim->sTimerxRegs[i].EEFxR1 &= ~( HRTIM_EEFxR1_EE3LTCH| HRTIM_EEFxR1_EE3FLTR);
                    hdp->hrtim->sTimerxRegs[i].EEFxR1 |= (uint32_t)((hdp->timer_eev_filter[i][eev_idx - 1U].latch | hdp->timer_eev_filter[i][eev_idx - 1U].filter) << 12U);
                    break;
                case HRTIM_EVENT_4:
                    hdp->hrtim->sTimerxRegs[i].EEFxR1 &= ~( HRTIM_EEFxR1_EE4LTCH| HRTIM_EEFxR1_EE4FLTR);
                    hdp->hrtim->sTimerxRegs[i].EEFxR1 |= (uint32_t)((hdp->timer_eev_filter[i][eev_idx - 1U].latch | hdp->timer_eev_filter[i][eev_idx - 1U].filter) << 18U);
                    break;      
                case HRTIM_EVENT_5:
                    hdp->hrtim->sTimerxRegs[i].EEFxR1 &= ~( HRTIM_EEFxR1_EE5LTCH| HRTIM_EEFxR1_EE5FLTR);
                    hdp->hrtim->sTimerxRegs[i].EEFxR1 |= (uint32_t)((hdp->timer_eev_filter[i][eev_idx - 1U].latch | hdp->timer_eev_filter[i][eev_idx - 1U].filter) << 24U);
                    break;
                case HRTIM_EVENT_6:
                    hdp->hrtim->sTimerxRegs[i].EEFxR2 &= ~( HRTIM_EEFxR2_EE6LTCH| HRTIM_EEFxR2_EE6FLTR);
                    hdp->hrtim->sTimerxRegs[i].EEFxR2 |= (uint32_t)(hdp->timer_eev_filter[i][eev_idx - 1U].latch | hdp->timer_eev_filter[i][eev_idx - 1U].filter);
                    break;
                case HRTIM_EVENT_7:
                    hdp->hrtim->sTimerxRegs[i].EEFxR2 &= ~( HRTIM_EEFxR2_EE7LTCH| HRTIM_EEFxR2_EE7FLTR);
                    hdp->hrtim->sTimerxRegs[i].EEFxR2 |= (uint32_t)((hdp->timer_eev_filter[i][eev_idx - 1U].latch | hdp->timer_eev_filter[i][eev_idx - 1U].filter) << 6U);
                    break;
                case HRTIM_EVENT_8:
                    hdp->hrtim->sTimerxRegs[i].EEFxR2 &= ~( HRTIM_EEFxR2_EE8LTCH| HRTIM_EEFxR2_EE8FLTR);
                    hdp->hrtim->sTimerxRegs[i].EEFxR2 |= (uint32_t)((hdp->timer_eev_filter[i][eev_idx - 1U].latch | hdp->timer_eev_filter[i][eev_idx - 1U].filter) << 12U);
                    break;
                case HRTIM_EVENT_9:
                    hdp->hrtim->sTimerxRegs[i].EEFxR2 &= ~( HRTIM_EEFxR2_EE9LTCH| HRTIM_EEFxR2_EE9FLTR);
                    hdp->hrtim->sTimerxRegs[i].EEFxR2 |= (uint32_t)((hdp->timer_eev_filter[i][eev_idx - 1U].latch | hdp->timer_eev_filter[i][eev_idx - 1U].filter) << 18U);
                    break;
                case HRTIM_EVENT_10:
                    hdp->hrtim->sTimerxRegs[i].EEFxR2 &= ~( HRTIM_EEFxR2_EE10LTCH| HRTIM_EEFxR2_EE10FLTR);
                    hdp->hrtim->sTimerxRegs[i].EEFxR2 |= (uint32_t)((hdp->timer_eev_filter[i][eev_idx - 1U].latch | hdp->timer_eev_filter[i][eev_idx - 1U].filter) << 24U);
                    break;
                default:
                    /* for MISRA compliance */
                    break;
            }

            /* Configure the external Event Counter A of a timer (source,
               threshold, reset mode).*/
            if (hdp->eev_counter[i][eev_idx - 1U].source == HRTIM_EVENT_NONE) {
                /* reset External EventCounter A */
                hdp->hrtim->sTimerxRegs[i].EEFxR3 = 0x00000000U;
            } else {
                /* Set timer External EventCounter A configuration.*/
                hrtim_eefr3  =  (hdp->eev_counter[i][eev_idx - 1U].reset_mode) << HRTIM_EEFxR3_EEVARSTM_Pos;
                hrtim_eefr3 |= ((hdp->eev_counter[i][eev_idx - 1U].source - 1U)) << HRTIM_EEFxR3_EEVASEL_Pos;
                hrtim_eefr3 |=  (hdp->eev_counter[i][eev_idx - 1U].counter) << HRTIM_EEFxR3_EEVACNT_Pos;

                hdp->hrtim->sTimerxRegs[i].EEFxR3 &= ~(HRTIM_EEFxR3_EEVARSTM | HRTIM_EEFxR3_EEVASEL | HRTIM_EEFxR3_EEVACNT);
                hdp->hrtim->sTimerxRegs[i].EEFxR3 |= (uint32_t)hrtim_eefr3;
            }
        }

        /* Timer registers configuration setup.*/
        hdp->hrtim->sTimerxRegs[i].TIMxCR    = cr | (uint32_t)(hdp->timer_prescaler[i])      |
                                                    (uint32_t)(hdp->timer_preload[i].enable) |
                                                    (uint32_t)(hdp->timer_preload[i].update_event);
        hdp->hrtim->sTimerxRegs[i].TIMxDIER  = 0U;
        hdp->hrtim->sTimerxRegs[i].PERxR     = hdp->timer_period[i];
        hdp->hrtim->sTimerxRegs[i].REPxR     = 0U;
        hdp->hrtim->sTimerxRegs[i].CMP1xR    = hdp->timer_cmp[i][HRTIM_CMP1];
        hdp->hrtim->sTimerxRegs[i].CMP2xR    = hdp->timer_cmp[i][HRTIM_CMP2];
        hdp->hrtim->sTimerxRegs[i].CMP3xR    = hdp->timer_cmp[i][HRTIM_CMP3];
        hdp->hrtim->sTimerxRegs[i].CMP4xR    = hdp->timer_cmp[i][HRTIM_CMP4];
        hdp->hrtim->sTimerxRegs[i].DTxR      = (((uint32_t)hdp->deadtime[i].rvalue)    << HRTIM_DTxR_DTRx_Pos)   |
                                               (((uint32_t)hdp->deadtime[i].rsign)     << HRTIM_DTxR_SDTRx_Pos)  |
                                               (((uint32_t)hdp->deadtime[i].prescaler) << HRTIM_DTxR_DTPRSC_Pos) | 
                                               (((uint32_t)hdp->deadtime[i].fvalue)    << HRTIM_DTxR_DTFx_Pos)   |
                                               (((uint32_t)hdp->deadtime[i].fsign)     << HRTIM_DTxR_SDTFx_Pos);
        hdp->hrtim->sTimerxRegs[i].SETx1R    = (uint32_t)(hdp->set_event[i][HRTIM_TIMER_OUTPUT_1]);
        hdp->hrtim->sTimerxRegs[i].RSTx1R    = (uint32_t)(hdp->rst_event[i][HRTIM_TIMER_OUTPUT_1]);
        hdp->hrtim->sTimerxRegs[i].SETx2R    = (uint32_t)(hdp->set_event[i][HRTIM_TIMER_OUTPUT_2]);
        hdp->hrtim->sTimerxRegs[i].RSTx2R    = (uint32_t)(hdp->rst_event[i][HRTIM_TIMER_OUTPUT_2]);
        hdp->hrtim->sTimerxRegs[i].RSTxR     = (uint32_t)(hdp->timer_cntr_rst_event[i]);
        hdp->hrtim->sTimerxRegs[i].CHPxR     = 0U;
        hdp->hrtim->sTimerxRegs[i].CPT1xCR   = hdp->cpt_unit[i].capture_trg_1;
        hdp->hrtim->sTimerxRegs[i].CPT2xCR   = hdp->cpt_unit[i].capture_trg_2;

        if (hdp->deadtime[i].enable == true) {
            hdp->hrtim->sTimerxRegs[i].OUTxR = (1UL << HRTIM_OUTxR_DTEN_Pos);
        } else {
            hdp->hrtim->sTimerxRegs[i].OUTxR = 0U;
        }

        hdp->hrtim->sTimerxRegs[i].OUTxR |= (((((uint32_t)hdp->fault_state[i][HRTIM_TIMER_OUTPUT_1])  << HRTIM_OUTxR_FAULT1_Pos) & HRTIM_OUTxR_FAULT1_Msk) |
                                             ((((uint32_t)hdp->fault_state[i][HRTIM_TIMER_OUTPUT_2])  << HRTIM_OUTxR_FAULT2_Pos) & HRTIM_OUTxR_FAULT2_Msk) |
                                             ((((uint32_t)hdp->idle_state[i][HRTIM_TIMER_OUTPUT_1])   << HRTIM_OUTxR_IDLES1_Pos) & HRTIM_OUTxR_IDLES1)     |
                                             ((((uint32_t)hdp->idle_state[i][HRTIM_TIMER_OUTPUT_2])   << HRTIM_OUTxR_IDLES2_Pos) & HRTIM_OUTxR_IDLES2)     |
                                             ((((uint32_t)hdp->out_polarity[i][HRTIM_TIMER_OUTPUT_1]) << HRTIM_OUTxR_POL1_Pos)   & HRTIM_OUTxR_POL1_Msk)   |
                                             ((((uint32_t)hdp->out_polarity[i][HRTIM_TIMER_OUTPUT_2]) << HRTIM_OUTxR_POL2_Pos)   & HRTIM_OUTxR_POL2_Msk));

        hdp->hrtim->sTimerxRegs[i].FLTxR     = 0U;

        hdp->hrtim->sTimerxRegs[i].TIMxCR2 = (hdp->timer_count_mode[i].up_down_mode)                                                          |
                                             (hdp->timer_dualdac_enable[i])                                                                   |
                                             (hdp->timer_count_mode[i].rollover)                                                              |
                                             (hdp->timer_count_mode[i].out_rollover<<(HRTIM_TIMxCR2_OUTROM_Pos - HRTIM_TIMxCR2_ROM_Pos))      |
                                             (hdp->timer_count_mode[i].adc_rollover<<(HRTIM_TIMxCR2_ADROM_Pos  - HRTIM_TIMxCR2_ROM_Pos))      |
                                             (hdp->timer_count_mode[i].burstmode_rollover<<(HRTIM_TIMxCR2_BMROM_Pos - HRTIM_TIMxCR2_ROM_Pos)) |
                                             (hdp->timer_count_mode[i].fault_event_rollover<<(HRTIM_TIMxCR2_FEROM_Pos - HRTIM_TIMxCR2_ROM_Pos));
    }

    switch (hdp->master_mode) {
        case HRTIM_MODE_SINGLE_SHOT_NO_RETRIGGERED:
            break;
        case HRTIM_MODE_SINGLE_SHOT_RETRIGGERED:
            mstr_cr |= HRTIM_TIMxCR_RETRIG;
            break;
        case HRTIM_MODE_CONTINUOS:
            mstr_cr |= HRTIM_TIMxCR_CONT;
            break;
        default:
            /* for MISRA compliance */
            break;
    }

    /* ADC trigger settings.*/
    /* Set the ADC trigger update source */
    hrtim_cr1 =  hdp->hrtim->sCommonRegs.CR1;
    hrtim_cr1 &= ~((HRTIM_CR1_ADC1USRC) |
                   (HRTIM_CR1_ADC2USRC) |
                   (HRTIM_CR1_ADC3USRC) |
                   (HRTIM_CR1_ADC4USRC));

    hrtim_adcur = hdp->hrtim->sCommonRegs.ADCUR;
    hrtim_adcur &= ~((HRTIM_ADCUR_AD5USRC) |
                     (HRTIM_ADCUR_AD6USRC) | 
                     (HRTIM_ADCUR_AD7USRC) | 
                     (HRTIM_ADCUR_AD8USRC) | 
                     (HRTIM_ADCUR_AD9USRC) | 
                     (HRTIM_ADCUR_AD10USRC));

    for (i = 0U; i < HRTIM_ADCTRIG_NUM; i++) {
        switch (hdp->adc_trg[i].adc_trigger) {
            case HRTIM_ADCTRIGGER_1:
                /* Set the update source.*/
                hrtim_cr1 &= ~(HRTIM_CR1_ADC1USRC);
                hrtim_cr1 |= (hdp->adc_trg[i].update_src & HRTIM_CR1_ADC1USRC);

                /* Set the ADC trigger 1 source.*/
                hdp->hrtim->sCommonRegs.ADC1R |= hdp->adc_trg[i].event_trigger;

                /* Post-Scaler rate.*/
                hdp->hrtim->sCommonRegs.ADCPS1 |= (uint32_t)(hdp->adc_trg[i].post_scaler_rate << HRTIM_ADCPS1_AD1PSC_Pos) & HRTIM_ADCPS1_AD1PSC_Msk;
                break;
            case HRTIM_ADCTRIGGER_2:
                hrtim_cr1 &= ~(HRTIM_CR1_ADC2USRC);
                hrtim_cr1 |= ((hdp->adc_trg[i].update_src << 3U) & HRTIM_CR1_ADC2USRC);

                /* Set the ADC trigger 2 source.*/ 
                hdp->hrtim->sCommonRegs.ADC2R |= hdp->adc_trg[i].event_trigger;

                /* Post-Scaler rate.*/
                hdp->hrtim->sCommonRegs.ADCPS1 |= (uint32_t)(hdp->adc_trg[i].post_scaler_rate << HRTIM_ADCPS1_AD2PSC_Pos) & HRTIM_ADCPS1_AD2PSC_Msk;
                break;
            case HRTIM_ADCTRIGGER_3:
                hrtim_cr1 &= ~(HRTIM_CR1_ADC3USRC);
                hrtim_cr1 |= ((hdp->adc_trg[i].update_src << 6U) & HRTIM_CR1_ADC3USRC);

                /* Set the ADC trigger 3 source.*/ 
                hdp->hrtim->sCommonRegs.ADC3R |= hdp->adc_trg[i].event_trigger;

                /* Post-Scaler rate.*/
                hdp->hrtim->sCommonRegs.ADCPS1 |= (uint32_t)(hdp->adc_trg[i].post_scaler_rate << HRTIM_ADCPS1_AD3PSC_Pos) & HRTIM_ADCPS1_AD3PSC_Msk;
                break;
            case HRTIM_ADCTRIGGER_4:
                hrtim_cr1 &= ~(HRTIM_CR1_ADC4USRC);
                hrtim_cr1 |= ((hdp->adc_trg[i].update_src << 9U) & HRTIM_CR1_ADC4USRC);

                /* Set the ADC trigger 4 source.*/ 
                hdp->hrtim->sCommonRegs.ADC4R |= hdp->adc_trg[i].event_trigger;

                /* Post-Scaler rate.*/
                hdp->hrtim->sCommonRegs.ADCPS1 |= (uint32_t)(hdp->adc_trg[i].post_scaler_rate << HRTIM_ADCPS1_AD4PSC_Pos) & HRTIM_ADCPS1_AD4PSC_Msk;
                break;
            case HRTIM_ADCTRIGGER_5:
                hrtim_adcur &= ~(HRTIM_ADCUR_AD5USRC);
                hrtim_adcur |= ((hdp->adc_trg[i].update_src >> 16U) & HRTIM_ADCUR_AD5USRC);

                /* Set the ADC trigger 5 source.*/
                hdp->hrtim->sCommonRegs.ADCER &= ~(HRTIM_ADCER_AD5TRG);
                hdp->hrtim->sCommonRegs.ADCER |= ((hdp->adc_trg[i].event_trigger << HRTIM_ADCER_AD5TRG_Pos) & HRTIM_ADCER_AD5TRG);

                /*Post-Scaler rate*/
                hdp->hrtim->sCommonRegs.ADCPS1 |= (uint32_t)(hdp->adc_trg[i].post_scaler_rate << HRTIM_ADCPS1_AD5PSC_Pos) & HRTIM_ADCPS1_AD5PSC_Msk;
                break;
            case HRTIM_ADCTRIGGER_6:
                hrtim_adcur &= ~(HRTIM_ADCUR_AD6USRC);
                hrtim_adcur |= ((hdp->adc_trg[i].update_src >> 12U) & HRTIM_ADCUR_AD6USRC);

                /* Set the ADC trigger 6 source.*/
                hdp->hrtim->sCommonRegs.ADCER &= ~(HRTIM_ADCER_AD6TRG);
                hdp->hrtim->sCommonRegs.ADCER |= ((hdp->adc_trg[i].event_trigger << HRTIM_ADCER_AD6TRG_Pos) & HRTIM_ADCER_AD6TRG);

                /* Post-Scaler rate.*/
                hdp->hrtim->sCommonRegs.ADCPS2 |= (uint32_t)(hdp->adc_trg[i].post_scaler_rate << HRTIM_ADCPS2_AD6PSC_Pos) & HRTIM_ADCPS2_AD6PSC_Msk;
                break;
            case HRTIM_ADCTRIGGER_7:
                hrtim_adcur &= ~(HRTIM_ADCUR_AD7USRC);
                hrtim_adcur |= ((hdp->adc_trg[i].update_src >> 8U) & HRTIM_ADCUR_AD7USRC);

                /* Set the ADC trigger 7 source.*/
                hdp->hrtim->sCommonRegs.ADCER &= ~(HRTIM_ADCER_AD7TRG);
                hdp->hrtim->sCommonRegs.ADCER |= ((hdp->adc_trg[i].event_trigger << HRTIM_ADCER_AD7TRG_Pos) & HRTIM_ADCER_AD7TRG);

                /* Post-Scaler rate.*/
                hdp->hrtim->sCommonRegs.ADCPS2 |= (uint32_t)(hdp->adc_trg[i].post_scaler_rate << HRTIM_ADCPS2_AD7PSC_Pos) & HRTIM_ADCPS2_AD7PSC_Msk;
                break;
            case HRTIM_ADCTRIGGER_8:
                hrtim_adcur &= ~(HRTIM_ADCUR_AD8USRC);
                hrtim_adcur |= ((hdp->adc_trg[i].update_src >> 4U) & HRTIM_ADCUR_AD8USRC);

                /* Set the ADC trigger 8 source.*/
                hdp->hrtim->sCommonRegs.ADCER &= ~(HRTIM_ADCER_AD8TRG);
                hdp->hrtim->sCommonRegs.ADCER |= ((hdp->adc_trg[i].event_trigger << HRTIM_ADCER_AD8TRG_Pos) & HRTIM_ADCER_AD8TRG);

                /* Post-Scaler rate.*/
                hdp->hrtim->sCommonRegs.ADCPS2 |= (uint32_t)(hdp->adc_trg[i].post_scaler_rate << HRTIM_ADCPS2_AD8PSC_Pos) & HRTIM_ADCPS2_AD8PSC_Msk;
                break;
            case HRTIM_ADCTRIGGER_9:
                hrtim_adcur &= ~(HRTIM_ADCUR_AD9USRC);
                hrtim_adcur |= ((hdp->adc_trg[i].update_src) & HRTIM_ADCUR_AD9USRC);

                /* Set the ADC trigger 9 source.*/
                hdp->hrtim->sCommonRegs.ADCER &= ~(HRTIM_ADCER_AD9TRG);
                hdp->hrtim->sCommonRegs.ADCER |= ((hdp->adc_trg[i].event_trigger << HRTIM_ADCER_AD9TRG_Pos) & HRTIM_ADCER_AD9TRG);

                /* Post-Scaler rate.*/
                hdp->hrtim->sCommonRegs.ADCPS2 |= (uint32_t)(hdp->adc_trg[i].post_scaler_rate << HRTIM_ADCPS2_AD9PSC_Pos) & HRTIM_ADCPS2_AD9PSC_Msk;
                break;
            case HRTIM_ADCTRIGGER_10:
                hrtim_adcur &= ~(HRTIM_ADCUR_AD10USRC);
                hrtim_adcur |= ((hdp->adc_trg[i].update_src << 4U) & HRTIM_ADCUR_AD10USRC);

                /* Set the ADC trigger 10 source.*/
                hdp->hrtim->sCommonRegs.ADCER &= ~(HRTIM_ADCER_AD10TRG);
                hdp->hrtim->sCommonRegs.ADCER |= ((hdp->adc_trg[i].event_trigger << HRTIM_ADCER_AD10TRG_Pos) & HRTIM_ADCER_AD10TRG);

                /* Post-Scaler rate.*/
                hdp->hrtim->sCommonRegs.ADCPS2 |= (uint32_t)(hdp->adc_trg[i].post_scaler_rate << HRTIM_ADCPS2_AD10PSC_Pos) & HRTIM_ADCPS2_AD10PSC_Msk;
                break;
            default:
                /* for MISRA compliance */
                break;
        }
    }

    /* Update the HRTIM registers.*/
    hdp->hrtim->sCommonRegs.CR1   |= hrtim_cr1;
    hdp->hrtim->sCommonRegs.ADCUR |= hrtim_adcur;

    /* Configure external event channel.*/
    hrtim_eecr1 = hdp->hrtim->sCommonRegs.EECR1;
    hrtim_eecr2 = hdp->hrtim->sCommonRegs.EECR2;
    hrtim_eecr3 = hdp->hrtim->sCommonRegs.EECR3;

    for (i = 0U; i < HRTIM_EXEVENT_NUM; i++) {
        switch (i) {
            case HRTIM_EVENT_NONE:
                /* Update the HRTIM registers */
                hdp->hrtim->sCommonRegs.EECR1 = 0U;
                hdp->hrtim->sCommonRegs.EECR2 = 0U;
                hdp->hrtim->sCommonRegs.EECR3 = 0U;
                break;
            case HRTIM_EVENT_1:
                hrtim_eecr1 &= ~(HRTIM_EECR1_EE1SRC | HRTIM_EECR1_EE1POL | HRTIM_EECR1_EE1SNS | HRTIM_EECR1_EE1FAST);
                hrtim_eecr1 |= ( hdp->eev[i - 1U].source & HRTIM_EECR1_EE1SRC);
                hrtim_eecr1 |= ( hdp->eev[i - 1U].polarity & HRTIM_EECR1_EE1POL);
                hrtim_eecr1 |= ( hdp->eev[i - 1U].sensitivity & HRTIM_EECR1_EE1SNS);
                /* Update the HRTIM registers (all bitfields but EE1FAST bit) */
                hdp->hrtim->sCommonRegs.EECR1 |= hrtim_eecr1;
                /* Update the HRTIM registers (EE1FAST bit) */
                hrtim_eecr1 |= ( hdp->eev[i - 1U].fast_mode  & HRTIM_EECR1_EE1FAST);
                hdp->hrtim->sCommonRegs.EECR1 |= hrtim_eecr1;
                break;
            case HRTIM_EVENT_2:
                hrtim_eecr1 &= ~(HRTIM_EECR1_EE2SRC | HRTIM_EECR1_EE2POL | HRTIM_EECR1_EE2SNS | HRTIM_EECR1_EE2FAST);
                hrtim_eecr1 |= (( hdp->eev[i - 1U].source << 6U) & HRTIM_EECR1_EE2SRC);
                hrtim_eecr1 |= (( hdp->eev[i - 1U].polarity << 6U) & HRTIM_EECR1_EE2POL);
                hrtim_eecr1 |= (( hdp->eev[i - 1U].sensitivity << 6U) & HRTIM_EECR1_EE2SNS);
                /* Update the HRTIM registers (all bitfields but EE2FAST bit) */
                hdp->hrtim->sCommonRegs.EECR1 |= hrtim_eecr1;
                /* Update the HRTIM registers (EE2FAST bit) */
                hrtim_eecr1 |= (( hdp->eev[i - 1U].fast_mode << 6U) & HRTIM_EECR1_EE2FAST);
                hdp->hrtim->sCommonRegs.EECR1 |= hrtim_eecr1;
                break;
            case HRTIM_EVENT_3:
                hrtim_eecr1 &= ~(HRTIM_EECR1_EE3SRC | HRTIM_EECR1_EE3POL | HRTIM_EECR1_EE3SNS | HRTIM_EECR1_EE3FAST);
                hrtim_eecr1 |= (( hdp->eev[i - 1U].source << 12U) & HRTIM_EECR1_EE3SRC);
                hrtim_eecr1 |= (( hdp->eev[i - 1U].polarity << 12U) & HRTIM_EECR1_EE3POL);
                hrtim_eecr1 |= (( hdp->eev[i - 1U].sensitivity << 12U) & HRTIM_EECR1_EE3SNS);
                /* Update the HRTIM registers (all bitfields but EE3FAST bit) */
                hdp->hrtim->sCommonRegs.EECR1 |= hrtim_eecr1;
                /* Update the HRTIM registers (EE3FAST bit) */
                hrtim_eecr1 |= (( hdp->eev[i - 1U].fast_mode << 12U) & HRTIM_EECR1_EE3FAST);
                hdp->hrtim->sCommonRegs.EECR1 |= hrtim_eecr1;
                break;
            case HRTIM_EVENT_4:
                hrtim_eecr1 &= ~(HRTIM_EECR1_EE4SRC | HRTIM_EECR1_EE4POL | HRTIM_EECR1_EE4SNS | HRTIM_EECR1_EE4FAST);
                hrtim_eecr1 |= (( hdp->eev[i - 1U].source << 18U) & HRTIM_EECR1_EE4SRC);
                hrtim_eecr1 |= (( hdp->eev[i - 1U].polarity << 18U) & HRTIM_EECR1_EE4POL);
                hrtim_eecr1 |= (( hdp->eev[i - 1U].sensitivity << 18U) & HRTIM_EECR1_EE4SNS);
                /* Update the HRTIM registers (all bitfields but EE4FAST bit) */
                hdp->hrtim->sCommonRegs.EECR1 |= hrtim_eecr1;
                /* Update the HRTIM registers (EE4FAST bit) */
                hrtim_eecr1 |= (( hdp->eev[i - 1U].fast_mode << 18U) & HRTIM_EECR1_EE4FAST);
                hdp->hrtim->sCommonRegs.EECR1 |= hrtim_eecr1;
                break;
            case HRTIM_EVENT_5:
                hrtim_eecr1 &= ~(HRTIM_EECR1_EE5SRC | HRTIM_EECR1_EE5POL | HRTIM_EECR1_EE5SNS | HRTIM_EECR1_EE5FAST);
                hrtim_eecr1 |= (( hdp->eev[i - 1U].source << 24U) & HRTIM_EECR1_EE5SRC);
                hrtim_eecr1 |= (( hdp->eev[i - 1U].polarity << 24U) & HRTIM_EECR1_EE5POL);
                hrtim_eecr1 |= (( hdp->eev[i - 1U].sensitivity << 24U) & HRTIM_EECR1_EE5SNS);
                /* Update the HRTIM registers (all bitfields but EE5FAST bit) */
                hdp->hrtim->sCommonRegs.EECR1 |= hrtim_eecr1;
                /* Update the HRTIM registers (EE5FAST bit) */
                hrtim_eecr1 |= (( hdp->eev[i - 1U].fast_mode << 24U) & HRTIM_EECR1_EE5FAST);
                hdp->hrtim->sCommonRegs.EECR1 |= hrtim_eecr1;
                break;
            case HRTIM_EVENT_6:
                hrtim_eecr2 &= ~(HRTIM_EECR2_EE6SRC | HRTIM_EECR2_EE6POL | HRTIM_EECR2_EE6SNS);
                hrtim_eecr2 |= ( hdp->eev[i - 1U].source & HRTIM_EECR2_EE6SRC);
                hrtim_eecr2 |= ( hdp->eev[i - 1U].polarity & HRTIM_EECR2_EE6POL);
                hrtim_eecr2 |= ( hdp->eev[i - 1U].sensitivity & HRTIM_EECR2_EE6SNS);
                hrtim_eecr3 &= ~(HRTIM_EECR3_EE6F);
                hrtim_eecr3 |= ( hdp->eev[i - 1U].filter & HRTIM_EECR3_EE6F);
                /* Update the HRTIM registers */
                hdp->hrtim->sCommonRegs.EECR2 |= hrtim_eecr2;
                hdp->hrtim->sCommonRegs.EECR3 |= hrtim_eecr3;
                break;
            case HRTIM_EVENT_7:
                hrtim_eecr2 &= ~(HRTIM_EECR2_EE7SRC | HRTIM_EECR2_EE7POL | HRTIM_EECR2_EE7SNS);
                hrtim_eecr2 |= (( hdp->eev[i - 1U].source << 6U) & HRTIM_EECR2_EE7SRC);
                hrtim_eecr2 |= (( hdp->eev[i - 1U].polarity << 6U) & HRTIM_EECR2_EE7POL);
                hrtim_eecr2 |= (( hdp->eev[i - 1U].sensitivity << 6U) & HRTIM_EECR2_EE7SNS);
                hrtim_eecr3 &= ~(HRTIM_EECR3_EE7F);
                hrtim_eecr3 |= (( hdp->eev[i - 1U].filter << 6U) & HRTIM_EECR3_EE7F);
                /* Update the HRTIM registers */
                hdp->hrtim->sCommonRegs.EECR2 |= hrtim_eecr2;
                hdp->hrtim->sCommonRegs.EECR3 |= hrtim_eecr3;
                break;
            case HRTIM_EVENT_8:
                hrtim_eecr2 &= ~(HRTIM_EECR2_EE8SRC | HRTIM_EECR2_EE8POL | HRTIM_EECR2_EE8SNS);
                hrtim_eecr2 |= (( hdp->eev[i - 1U].source << 12U) & HRTIM_EECR2_EE8SRC);
                hrtim_eecr2 |= (( hdp->eev[i - 1U].polarity << 12U) & HRTIM_EECR2_EE8POL);
                hrtim_eecr2 |= (( hdp->eev[i - 1U].sensitivity << 12U) & HRTIM_EECR2_EE8SNS);
                hrtim_eecr3 &= ~(HRTIM_EECR3_EE8F);
                hrtim_eecr3 |= (( hdp->eev[i - 1U].filter << 12U) & HRTIM_EECR3_EE8F );
                /* Update the HRTIM registers */
                hdp->hrtim->sCommonRegs.EECR2 |= hrtim_eecr2;
                hdp->hrtim->sCommonRegs.EECR3 |= hrtim_eecr3;
                break;
            case HRTIM_EVENT_9:
                hrtim_eecr2 &= ~(HRTIM_EECR2_EE9SRC | HRTIM_EECR2_EE9POL | HRTIM_EECR2_EE9SNS);
                hrtim_eecr2 |= (( hdp->eev[i - 1U].source << 18U) & HRTIM_EECR2_EE9SRC);
                hrtim_eecr2 |= (( hdp->eev[i - 1U].polarity << 18U) & HRTIM_EECR2_EE9POL);
                hrtim_eecr2 |= (( hdp->eev[i - 1U].sensitivity << 18U) & HRTIM_EECR2_EE9SNS);
                hrtim_eecr3 &= ~(HRTIM_EECR3_EE9F);
                hrtim_eecr3 |= (( hdp->eev[i - 1U].filter << 18U) & HRTIM_EECR3_EE9F);
                /* Update the HRTIM registers */
                hdp->hrtim->sCommonRegs.EECR2 |= hrtim_eecr2;
                hdp->hrtim->sCommonRegs.EECR3 |= hrtim_eecr3;
                break;
            case HRTIM_EVENT_10:
                hrtim_eecr2 &= ~(HRTIM_EECR2_EE10SRC | HRTIM_EECR2_EE10POL | HRTIM_EECR2_EE10SNS);
                hrtim_eecr2 |= (( hdp->eev[i - 1U].source << 24U) & HRTIM_EECR2_EE10SRC);
                hrtim_eecr2 |= (( hdp->eev[i - 1U].polarity << 24U) & HRTIM_EECR2_EE10POL);
                hrtim_eecr2 |= (( hdp->eev[i - 1U].sensitivity << 24U) & HRTIM_EECR2_EE10SNS);
                hrtim_eecr3 &= ~(HRTIM_EECR3_EE10F);
                hrtim_eecr3 |= (( hdp->eev[i - 1U].filter << 24U) & HRTIM_EECR3_EE10F);
                /* Update the HRTIM registers */
                hdp->hrtim->sCommonRegs.EECR2 |= hrtim_eecr2;
                hdp->hrtim->sCommonRegs.EECR3 |= hrtim_eecr3;
                break;
            default:
                /* for MISRA compliance */
                break;
        }
    }

    /* Configure the external event conditioning block prescaler.*/
    hdp->hrtim->sCommonRegs.EECR3 |= ((uint32_t)hdp->eev_prescaler) << 30;

    /* Set the external event prescaler.*/
    hdp->hrtim->sCommonRegs.FLTINR2 &= (~(HRTIM_FLTINR2_FLTSD));
    hdp->hrtim->sCommonRegs.FLTINR2 = ((((uint32_t)hdp->fault_prescaler) << 24U) & HRTIM_FLTINR2_FLTSD);

    /* Configure fault channel.*/
    hrtim_fltinr1 = hdp->hrtim->sCommonRegs.FLTINR1;
    hrtim_fltinr2 = hdp->hrtim->sCommonRegs.FLTINR2;

    for (idx = 0U; idx < HRTIM_FAULT_NUM; idx++) {
        source0 =  (hdp->fault[idx].source & 1U);
        source1 =  ((hdp->fault[idx].source & 2U) >> 1);

        switch (hdp->fault[idx].fault_idx) {
            case HRTIM_FAULT_1:
                hrtim_fltinr1 &= ~(HRTIM_FLTINR1_FLT1P | HRTIM_FLTINR1_FLT1SRC_0 | HRTIM_FLTINR1_FLT1F | HRTIM_FLTINR1_FLT1LCK);
                hrtim_fltinr1 |= (hdp->fault[idx].polarity & HRTIM_FLTINR1_FLT1P);
                hrtim_fltinr1 |= (source0 << HRTIM_FLTINR1_FLT1SRC_0_Pos);
                hrtim_fltinr2 &= ~(HRTIM_FLTINR2_FLT1SRC_1);
                hrtim_fltinr2 |= (source1 << HRTIM_FLTINR2_FLT1SRC_1_Pos);
                hrtim_fltinr1 |= (hdp->fault[idx].filter & HRTIM_FLTINR1_FLT1F);
                hrtim_fltinr1 |= (hdp->fault[idx].lock & HRTIM_FLTINR1_FLT1LCK);
                hdp->hrtim->sCommonRegs.FLTINR3 &=~ (HRTIM_FLTINR3_FLT1RSTM | HRTIM_FLTINR3_FLT1CNT);
                hdp->hrtim->sCommonRegs.FLTINR3 = (((uint32_t)hdp->fault_blnk[idx].threshold << HRTIM_FLTINR3_FLT1CNT_Pos) | 
                                                   ((uint32_t)hdp->fault_blnk[idx].reset_mode << HRTIM_FLTINR3_FLT1RSTM_Pos));
                hdp->hrtim->sCommonRegs.FLTINR3 &= ~(HRTIM_FLTINR3_FLT1BLKS | HRTIM_FLTINR3_FLT1BLKE);
                hdp->hrtim->sCommonRegs.FLTINR3 |= (((uint32_t)hdp->fault_blnk[idx].blanking_source << HRTIM_FLTINR3_FLT1BLKS_Pos) | HRTIM_FLTINR3_FLT1BLKE);
                if (hdp->fault[idx].enable == true) {
                    hrtim_fltinr1 |= HRTIM_FLTINR1_FLT1E;
                } else {
                    hrtim_fltinr1 &= ~HRTIM_FLTINR1_FLT1E;
                }
                break;
            case HRTIM_FAULT_2:
                hrtim_fltinr1 &= ~(HRTIM_FLTINR1_FLT2P | HRTIM_FLTINR1_FLT2SRC_0 | HRTIM_FLTINR1_FLT2F | HRTIM_FLTINR1_FLT2LCK);
                hrtim_fltinr1 |= ((hdp->fault[idx].polarity << 8U) & HRTIM_FLTINR1_FLT2P);
                hrtim_fltinr1 |= (source0 << HRTIM_FLTINR1_FLT2SRC_0_Pos);
                hrtim_fltinr2 &= ~(HRTIM_FLTINR2_FLT2SRC_1);
                hrtim_fltinr2 |= (source1 << HRTIM_FLTINR2_FLT2SRC_1_Pos);
                hrtim_fltinr1 |= ((hdp->fault[idx].filter << 8U) & HRTIM_FLTINR1_FLT2F);
                hrtim_fltinr1 |= ((hdp->fault[idx].lock << 8U) & HRTIM_FLTINR1_FLT2LCK);
                hdp->hrtim->sCommonRegs.FLTINR3 &=~ (HRTIM_FLTINR3_FLT2RSTM | HRTIM_FLTINR3_FLT2CNT);
                hdp->hrtim->sCommonRegs.FLTINR3 = (((uint32_t)hdp->fault_blnk[idx].threshold << HRTIM_FLTINR3_FLT2CNT_Pos) | 
                                                   ((uint32_t)hdp->fault_blnk[idx].reset_mode << HRTIM_FLTINR3_FLT2RSTM_Pos));
                hdp->hrtim->sCommonRegs.FLTINR3 &= ~(HRTIM_FLTINR3_FLT2BLKS | HRTIM_FLTINR3_FLT2BLKE);
                hdp->hrtim->sCommonRegs.FLTINR3 |= (((uint32_t)hdp->fault_blnk[idx].blanking_source << HRTIM_FLTINR3_FLT2BLKS_Pos) | HRTIM_FLTINR3_FLT2BLKE);
                if (hdp->fault[idx].enable == true) {
                    hrtim_fltinr1 |= HRTIM_FLTINR1_FLT2E;
                } else {
                    hrtim_fltinr1 &= ~HRTIM_FLTINR1_FLT2E;
                }
                break;
            case HRTIM_FAULT_3:
                hrtim_fltinr1 &= ~(HRTIM_FLTINR1_FLT3P | HRTIM_FLTINR1_FLT3SRC_0 | HRTIM_FLTINR1_FLT3F | HRTIM_FLTINR1_FLT3LCK);
                hrtim_fltinr1 |= ((hdp->fault[idx].polarity << 16U) & HRTIM_FLTINR1_FLT3P);
                hrtim_fltinr1 |= (source0 << HRTIM_FLTINR1_FLT3SRC_0_Pos);
                hrtim_fltinr2 &= ~(HRTIM_FLTINR2_FLT3SRC_1);
                hrtim_fltinr2 |= (source1 << HRTIM_FLTINR2_FLT3SRC_1_Pos);
                hrtim_fltinr1 |= ((hdp->fault[idx].filter << 16U) & HRTIM_FLTINR1_FLT3F);
                hrtim_fltinr1 |= ((hdp->fault[idx].lock << 16U) & HRTIM_FLTINR1_FLT3LCK);
                hdp->hrtim->sCommonRegs.FLTINR3 &=~ (HRTIM_FLTINR3_FLT3RSTM | HRTIM_FLTINR3_FLT3CNT);
                hdp->hrtim->sCommonRegs.FLTINR3 = (((uint32_t)hdp->fault_blnk[idx].threshold << HRTIM_FLTINR3_FLT3CNT_Pos) | 
                                                   ((uint32_t)hdp->fault_blnk[idx].reset_mode << HRTIM_FLTINR3_FLT3RSTM_Pos));
                hdp->hrtim->sCommonRegs.FLTINR3 &= ~(HRTIM_FLTINR3_FLT3BLKS | HRTIM_FLTINR3_FLT3BLKE);
                hdp->hrtim->sCommonRegs.FLTINR3 |= (((uint32_t)hdp->fault_blnk[idx].blanking_source << HRTIM_FLTINR3_FLT3BLKS_Pos) | HRTIM_FLTINR3_FLT3BLKE);
                if (hdp->fault[idx].enable == true) {
                    hrtim_fltinr1 |= HRTIM_FLTINR1_FLT3E;
                } else {
                    hrtim_fltinr1 &= ~HRTIM_FLTINR1_FLT3E;
                }
                break;
            case HRTIM_FAULT_4:
                hrtim_fltinr1 &= ~(HRTIM_FLTINR1_FLT4P | HRTIM_FLTINR1_FLT4SRC_0 | HRTIM_FLTINR1_FLT4F | HRTIM_FLTINR1_FLT4LCK);
                hrtim_fltinr1 |= ((hdp->fault[idx].polarity << 24U) & HRTIM_FLTINR1_FLT4P);
                hrtim_fltinr1 |= (source0 << HRTIM_FLTINR1_FLT4SRC_0_Pos);
                hrtim_fltinr2 &= ~(HRTIM_FLTINR2_FLT4SRC_1);
                hrtim_fltinr2 |= (source1 << HRTIM_FLTINR2_FLT4SRC_1_Pos);
                hrtim_fltinr1 |= ((hdp->fault[idx].filter << 24U) & HRTIM_FLTINR1_FLT4F);
                hrtim_fltinr1 |= ((hdp->fault[idx].lock << 24U) & HRTIM_FLTINR1_FLT4LCK);
                hdp->hrtim->sCommonRegs.FLTINR3 &=~ (HRTIM_FLTINR3_FLT4RSTM | HRTIM_FLTINR3_FLT4CNT);
                hdp->hrtim->sCommonRegs.FLTINR3 = (((uint32_t)hdp->fault_blnk[idx].threshold << HRTIM_FLTINR3_FLT4CNT_Pos) | 
                                                   ((uint32_t)hdp->fault_blnk[idx].reset_mode << HRTIM_FLTINR3_FLT4RSTM_Pos));
                hdp->hrtim->sCommonRegs.FLTINR3 &= ~(HRTIM_FLTINR3_FLT4BLKS | HRTIM_FLTINR3_FLT4BLKE);
                hdp->hrtim->sCommonRegs.FLTINR3 |= (((uint32_t)hdp->fault_blnk[idx].blanking_source << HRTIM_FLTINR3_FLT4BLKS_Pos) | HRTIM_FLTINR3_FLT4BLKE);
                if (hdp->fault[idx].enable == true) {
                    hrtim_fltinr1 |= HRTIM_FLTINR1_FLT4E;
                } else {
                    hrtim_fltinr1 &= ~HRTIM_FLTINR1_FLT4E;
                }
                break;
            case HRTIM_FAULT_5:
                hrtim_fltinr2 &= ~(HRTIM_FLTINR2_FLT5P | HRTIM_FLTINR2_FLT5SRC_0 | HRTIM_FLTINR2_FLT5F | HRTIM_FLTINR2_FLT5LCK);
                hrtim_fltinr2 |= (hdp->fault[idx].polarity & HRTIM_FLTINR2_FLT5P);
                hrtim_fltinr2 |= (source0 << HRTIM_FLTINR2_FLT5SRC_0_Pos);
                hrtim_fltinr2 &= ~(HRTIM_FLTINR2_FLT5SRC_1);
                hrtim_fltinr2 |= (source1 << HRTIM_FLTINR2_FLT5SRC_1_Pos);
                hrtim_fltinr2 |= (hdp->fault[idx].filter & HRTIM_FLTINR2_FLT5F);
                hrtim_fltinr2 |= (hdp->fault[idx].lock & HRTIM_FLTINR2_FLT5LCK);
                hdp->hrtim->sCommonRegs.FLTINR3 &=~ (HRTIM_FLTINR4_FLT5RSTM | HRTIM_FLTINR4_FLT5CNT);
                hdp->hrtim->sCommonRegs.FLTINR3 = (((uint32_t)hdp->fault_blnk[idx].threshold << HRTIM_FLTINR4_FLT5CNT_Pos) | 
                                                   ((uint32_t)hdp->fault_blnk[idx].reset_mode << HRTIM_FLTINR4_FLT5RSTM_Pos));
                hdp->hrtim->sCommonRegs.FLTINR3 &= ~(HRTIM_FLTINR4_FLT5BLKS | HRTIM_FLTINR4_FLT5BLKE);
                hdp->hrtim->sCommonRegs.FLTINR3 |= (((uint32_t)hdp->fault_blnk[idx].blanking_source << HRTIM_FLTINR4_FLT5BLKS_Pos) | HRTIM_FLTINR4_FLT5BLKE);
                if (hdp->fault[idx].enable == true) {
                    hrtim_fltinr2 |= HRTIM_FLTINR2_FLT5E;
                } else {
                    hrtim_fltinr2 &= ~HRTIM_FLTINR2_FLT5E;
                }
                break;
            case HRTIM_FAULT_6:
                hrtim_fltinr2 &= ~(HRTIM_FLTINR2_FLT6P | HRTIM_FLTINR2_FLT6SRC_0 | HRTIM_FLTINR2_FLT6F | HRTIM_FLTINR2_FLT6LCK);
                hrtim_fltinr2 |= ((hdp->fault[idx].polarity << 8U) & HRTIM_FLTINR2_FLT6P);
                hrtim_fltinr2 |= (source0 << HRTIM_FLTINR2_FLT6SRC_0_Pos);
                hrtim_fltinr2 &= ~(HRTIM_FLTINR2_FLT6SRC_1);
                hrtim_fltinr2 |= (source1 << HRTIM_FLTINR2_FLT6SRC_1_Pos);
                hrtim_fltinr2 |= ((hdp->fault[idx].filter << 8U) & HRTIM_FLTINR2_FLT6F);
                hrtim_fltinr2 |= ((hdp->fault[idx].lock << 8U) & HRTIM_FLTINR2_FLT6LCK);
                hdp->hrtim->sCommonRegs.FLTINR3 &=~ (HRTIM_FLTINR4_FLT6RSTM | HRTIM_FLTINR4_FLT6CNT);
                hdp->hrtim->sCommonRegs.FLTINR3 = (((uint32_t)hdp->fault_blnk[idx].threshold << HRTIM_FLTINR4_FLT6CNT_Pos) | 
                                                   ((uint32_t)hdp->fault_blnk[idx].reset_mode << HRTIM_FLTINR4_FLT6RSTM_Pos));
                hdp->hrtim->sCommonRegs.FLTINR3 &= ~(HRTIM_FLTINR4_FLT6BLKS | HRTIM_FLTINR4_FLT6BLKE);
                hdp->hrtim->sCommonRegs.FLTINR3 |= (((uint32_t)hdp->fault_blnk[idx].blanking_source << HRTIM_FLTINR4_FLT6BLKS_Pos) | HRTIM_FLTINR4_FLT6BLKE);
                if (hdp->fault[idx].enable == true) {
                    hrtim_fltinr2 |= HRTIM_FLTINR2_FLT6E;
                } else {
                    hrtim_fltinr2 &= ~HRTIM_FLTINR2_FLT6E;
                }
                break;
            case HRTIM_NO_FAULT:
            default:
                /* for MISRA compliance */
                break;
        }
    }

    /* Update the HRTIM registers except LOCK bit.*/
    hdp->hrtim->sCommonRegs.FLTINR1 = (hrtim_fltinr1 & (~(HRTIM_FLTINR1_FLTxLCK)));
    hdp->hrtim->sCommonRegs.FLTINR2 = (hrtim_fltinr2 & (~(HRTIM_FLTINR2_FLTxLCK)));

    /* Update the HRTIM registers LOCK bit.*/
    hdp->hrtim->sCommonRegs.FLTINR1 |= (hrtim_fltinr1 & HRTIM_FLTINR1_FLTxLCK);
    hdp->hrtim->sCommonRegs.FLTINR2 |= (hrtim_fltinr2 & HRTIM_FLTINR2_FLTxLCK);

    /* Common registers configuration setup.*/
    hdp->hrtim->sCommonRegs.CR2     = 0U & ~HRTIM_CR2_CFG_FORBIDDEN;
    hdp->hrtim->sCommonRegs.IER     = 0U ;
    hdp->hrtim->sCommonRegs.BMCR    = 0U ;
    hdp->hrtim->sCommonRegs.BMTRGR  = 0U ;
    hdp->hrtim->sCommonRegs.BMCMPR  = 0U ;
    hdp->hrtim->sCommonRegs.BMPER   = 0U ;
    hdp->hrtim->sCommonRegs.DLLCR   = ((uint32_t)(hdp->cal_period) | HRTIM_DLLCR_CALEN) & ~HRTIM_DLLCR_CFG_FORBIDDEN;
    hdp->hrtim->sCommonRegs.BDMUPR  = HRTIM_BDMUPR_MPER  | HRTIM_BDMUPR_MCMP1 |
                                      HRTIM_BDMUPR_MCMP2 | HRTIM_BDMUPR_MCMP3 |
                                      HRTIM_BDMUPR_MCMP4;
    hdp->hrtim->sCommonRegs.BDTAUPR = HRTIM_BDTAUPR_TIMPER  | HRTIM_BDTAUPR_TIMCMP1 |
                                      HRTIM_BDTAUPR_TIMCMP2 | HRTIM_BDTAUPR_TIMCMP3 |
                                      HRTIM_BDTAUPR_TIMCMP4;
    hdp->hrtim->sCommonRegs.BDTBUPR = HRTIM_BDTBUPR_TIMPER  | HRTIM_BDTBUPR_TIMCMP1 |
                                      HRTIM_BDTBUPR_TIMCMP2 | HRTIM_BDTBUPR_TIMCMP3 |
                                      HRTIM_BDTBUPR_TIMCMP4;
    hdp->hrtim->sCommonRegs.BDTCUPR = HRTIM_BDTCUPR_TIMPER  | HRTIM_BDTCUPR_TIMCMP1 |
                                      HRTIM_BDTCUPR_TIMCMP2 | HRTIM_BDTCUPR_TIMCMP3 |
                                      HRTIM_BDTCUPR_TIMCMP4;
    hdp->hrtim->sCommonRegs.BDTDUPR = HRTIM_BDTDUPR_TIMPER  | HRTIM_BDTDUPR_TIMCMP1 |
                                      HRTIM_BDTDUPR_TIMCMP2 | HRTIM_BDTDUPR_TIMCMP3 |
                                      HRTIM_BDTDUPR_TIMCMP4;
    hdp->hrtim->sCommonRegs.BDTEUPR = HRTIM_BDTEUPR_TIMPER  | HRTIM_BDTEUPR_TIMCMP1 |
                                      HRTIM_BDTEUPR_TIMCMP2 | HRTIM_BDTEUPR_TIMCMP3 |
                                      HRTIM_BDTEUPR_TIMCMP4;
    hdp->hrtim->sCommonRegs.BDTFUPR = HRTIM_BDTFUPR_TIMPER  | HRTIM_BDTFUPR_TIMCMP1 |
                                      HRTIM_BDTFUPR_TIMCMP2 | HRTIM_BDTFUPR_TIMCMP3 |
                                      HRTIM_BDTFUPR_TIMCMP4;
    hdp->hrtim->sCommonRegs.FLTINR4 = 0U;

    switch (hdp->master_mode_tpg) {
        case HRTIM_MODE_HALF_INTLVD_DISABLED:
            mstr_cr &= ~(HRTIM_MCR_HALF|HRTIM_MCR_INTLVD_0|HRTIM_MCR_INTLVD_1);
            break;
        case HRTIM_MODE_TRIPLE_INTERVALLED:
            mstr_cr &= ~(HRTIM_MCR_HALF);
            mstr_cr |= HRTIM_MCR_INTLVD_0;
            break;
        case HRTIM_MODE_QUAD_INTERVALLED:
            mstr_cr &= ~(HRTIM_MCR_HALF);
            mstr_cr |= HRTIM_MCR_INTLVD_1;
            break;
        case HRTIM_MODE_DUAL_INTERVALLED:
            mstr_cr |= HRTIM_MCR_HALF;
            break;
        case HRTIM_MODE_HALF:
            mstr_cr |= HRTIM_MCR_HALF;
            break;
        default:
            /* for MISRA compliance */
            break;
    }

    /* Master registers configuration setup.*/
    hdp->hrtim->sMasterRegs.MCR   |= mstr_cr | (uint32_t)(hdp->master_prescaler) | 
                                               (uint32_t)(hdp->master_preload.enable);
    hdp->hrtim->sMasterRegs.MDIER  = 0U;
    hdp->hrtim->sMasterRegs.MPER   = hdp->master_period;
    hdp->hrtim->sMasterRegs.MREP   = 0U;
    hdp->hrtim->sMasterRegs.MCMP1R = hdp->master_cmp[HRTIM_CMP1];
    hdp->hrtim->sMasterRegs.MCMP2R = hdp->master_cmp[HRTIM_CMP2];
    hdp->hrtim->sMasterRegs.MCMP3R = hdp->master_cmp[HRTIM_CMP3];
    hdp->hrtim->sMasterRegs.MCMP4R = hdp->master_cmp[HRTIM_CMP4];

    /* Clearing interrupt status bits.*/
    hdp->hrtim->sMasterRegs.MICR = 0xFFFFFFFFU;
    hdp->hrtim->sCommonRegs.ICR  = 0xFFFFFFFFU;
    for (i = 0U; i < HRTIM_TIMER_NUM; i++) {
        hdp->hrtim->sTimerxRegs[i].TIMxICR = 0xFFFFFFFFU;
    }
}

void hrtim_enable_cb(hrtim_driver_t *hdp, hrtim_cb_ops_t cb_op, uint8_t event) {

    uint32_t ier;

    if (hdp->is_enable == true) {
        if (cb_op == HRTIM_CB_MASTER) {
            ier = hdp->hrtim->sMasterRegs.MDIER;
            if ((ier & (1UL << (event))) == 0U) {
                hdp->hrtim->sMasterRegs.MICR  = ~(event);
                hdp->hrtim->sMasterRegs.MDIER =  (event) | ier;
            }
        } else if (cb_op == HRTIM_CB_FAULT) {
            ier = hdp->hrtim->sCommonRegs.IER;
            if ((ier & (1UL << (event))) == 0U) {
                hdp->hrtim->sCommonRegs.ICR = ~(event);
                hdp->hrtim->sCommonRegs.IER =  (event) | ier;
            }
        } else {
            ier = hdp->hrtim->sTimerxRegs[cb_op].TIMxDIER;
            if ((ier & (1UL << (event))) == 0U) {
                hdp->hrtim->sTimerxRegs[cb_op].TIMxICR  = ~(event);
                hdp->hrtim->sTimerxRegs[cb_op].TIMxDIER =  (event) | ier;
            }
        }
    }
}

void hrtim_disable_cb(hrtim_driver_t *hdp, hrtim_cb_ops_t cb_op, uint8_t event) {

    uint32_t ier;

    if (hdp->is_enable == true) {
        if (cb_op == HRTIM_CB_MASTER) {
            ier = hdp->hrtim->sMasterRegs.MDIER;
            if ((ier & (1UL << (event))) != 0U) {
                hdp->hrtim->sMasterRegs.MICR  = ~(event);
                hdp->hrtim->sMasterRegs.MDIER = ~(event) & ier;
            }
        } else if (cb_op == HRTIM_CB_FAULT) {
            ier = hdp->hrtim->sCommonRegs.IER;
            if ((ier & (1UL << (event))) != 0U) {
                hdp->hrtim->sCommonRegs.ICR = ~(event);
                hdp->hrtim->sCommonRegs.IER = ~(event) & ier;
            }
        } else {
            ier = hdp->hrtim->sTimerxRegs[cb_op].TIMxDIER;
            if ((ier & (1UL << (event))) != 0U) {
                hdp->hrtim->sTimerxRegs[cb_op].TIMxICR  = ~(event);
                hdp->hrtim->sTimerxRegs[cb_op].TIMxDIER = ~(event) & ier;
            }
        }
    }
}

void hrtim_timer_enable_output(hrtim_driver_t *hdp, hrtim_timer_t timer,
                               hrtim_out_t output) {

    if (hdp->is_enable == true) {
        hdp->hrtim->sCommonRegs.OENR = (1UL << ((uint8_t)output)) << (2U * ((uint8_t)timer));
    }
}

void hrtim_timer_disable_output(hrtim_driver_t *hdp, hrtim_timer_t timer,
                                hrtim_out_t output) {

    if (hdp->is_enable == true) {
        hdp->hrtim->sCommonRegs.ODISR = (1UL << ((uint8_t)output)) << (2U * ((uint8_t)timer));
    }
}

void hrtim_timer_enable(hrtim_driver_t *hdp, hrtim_timer_t timer) {

    if (hdp->is_enable == true) {
        switch (timer) {
            case HRTIM_TIMER_MASTER:
                hdp->hrtim->sMasterRegs.MCR |= HRTIM_MCR_MCEN;
                break;
            case HRTIM_TIMER_A:
                hdp->hrtim->sMasterRegs.MCR |= HRTIM_MCR_TACEN;
                break;
            case HRTIM_TIMER_B:
                hdp->hrtim->sMasterRegs.MCR |= HRTIM_MCR_TBCEN;
                break;
            case HRTIM_TIMER_C:
                hdp->hrtim->sMasterRegs.MCR |= HRTIM_MCR_TCCEN;
                break;
            case HRTIM_TIMER_D:
                hdp->hrtim->sMasterRegs.MCR |= HRTIM_MCR_TDCEN;
                break;
            case HRTIM_TIMER_E:
                hdp->hrtim->sMasterRegs.MCR |= HRTIM_MCR_TECEN;
                break;
            case HRTIM_TIMER_F:
                hdp->hrtim->sMasterRegs.MCR |= HRTIM_MCR_TFCEN;
                break;
            default:
                /* for MISRA compliance */
                break;
        }
    }
}

void hrtim_timer_disable(hrtim_driver_t *hdp, hrtim_timer_t timer) {

    if (hdp->is_enable == true) {
        switch (timer) {
            case HRTIM_TIMER_MASTER:
                hdp->hrtim->sMasterRegs.MCR &= ~(HRTIM_MCR_MCEN);
                break;
            case HRTIM_TIMER_A:
                hdp->hrtim->sMasterRegs.MCR &= ~(HRTIM_MCR_TACEN);
                break;
            case HRTIM_TIMER_B:
                hdp->hrtim->sMasterRegs.MCR &= ~(HRTIM_MCR_TBCEN);
                break;
            case HRTIM_TIMER_C:
                hdp->hrtim->sMasterRegs.MCR &= ~(HRTIM_MCR_TCCEN);
                break;
            case HRTIM_TIMER_D:
                hdp->hrtim->sMasterRegs.MCR &= ~(HRTIM_MCR_TDCEN);
                break;
            case HRTIM_TIMER_E:
                hdp->hrtim->sMasterRegs.MCR &= ~(HRTIM_MCR_TECEN);
                break;
            case HRTIM_TIMER_F:
                hdp->hrtim->sMasterRegs.MCR &= ~(HRTIM_MCR_TFCEN);
                break;
            default:
                /* for MISRA compliance */
                break;
        }
    }
}

void hrtim_timer_set_counter(hrtim_driver_t *hdp, hrtim_timer_t timer,
                             uint16_t value) {

    if (hdp->is_enable == true) {
        if (timer == HRTIM_TIMER_MASTER) {
            hdp->hrtim->sMasterRegs.MCNTR = (uint32_t)value;
        } else {
            hdp->hrtim->sTimerxRegs[timer].CNTxR = (uint32_t)value;
        }
    }
}

uint16_t hrtim_timer_get_counter(hrtim_driver_t *hdp, hrtim_timer_t timer) {

    if (hdp->is_enable == true) {
        if (timer == HRTIM_TIMER_MASTER) {
            return (uint16_t)(hdp->hrtim->sMasterRegs.MCNTR);
        } else {
            return (uint16_t)hdp->hrtim->sTimerxRegs[timer].CNTxR;
        }
    } else {
        return 0U;
    }
}

void hrtim_timer_set_repetition(hrtim_driver_t *hdp, hrtim_timer_t timer,
                                uint8_t value) {

    if (hdp->is_enable == true) {
        if (timer == HRTIM_TIMER_MASTER) {
            hdp->hrtim->sMasterRegs.MREP = (uint32_t)value;
        } else {
            hdp->hrtim->sTimerxRegs[timer].REPxR = (uint32_t)value;
        }
    }
}

uint8_t hrtim_timer_get_repetition(hrtim_driver_t *hdp, hrtim_timer_t timer) {

    if (hdp->is_enable == true) {
        if (timer == HRTIM_TIMER_MASTER) {
            return (uint8_t)(hdp->hrtim->sMasterRegs.MREP);
        } else {
            return (uint8_t)(hdp->hrtim->sTimerxRegs[timer].REPxR);
        }
    } else {
        return 0U;
    }
}

hrtim_cpt_value_t hrtim_timer_get_cpt(hrtim_driver_t *hdp,
                                      hrtim_timer_t timer,
                                      hrtim_cpt_t cpt_idx) {

    uint32_t tmp;
    hrtim_cpt_value_t captured;

    if (cpt_idx == HRTIM_CAPTUREUNIT_1) {
        tmp = hdp->hrtim->sTimerxRegs[timer].CPT1xR;
        captured.value = tmp & 0x0000FFFFUL;
        captured.dir = (((tmp & 0x00010000UL) == 0x00010000UL)?1UL:0UL);
    } else {
        tmp = hdp->hrtim->sTimerxRegs[timer].CPT2xR;
        captured.value = tmp & 0x0000FFFFUL;
        captured.dir = (((tmp & 0x00010000UL) == 0x00010000UL)?1UL:0UL);
    }
   
    return captured;
}

uint32_t hrtim_timer_set_counter_reset_event(hrtim_driver_t *hdp, 
                                             hrtim_timer_t timer,
                                             uint32_t event) {

    uint32_t prev_event = hdp->timer_cntr_rst_event[timer];

    if (timer != HRTIM_TIMER_MASTER) {
        hdp->timer_cntr_rst_event[timer] |= event;

        /* Update on-fly.*/
        if (hdp->is_enable == true) {
            hdp->hrtim->sTimerxRegs[timer].RSTxR |= event;
        }    
    }

    return prev_event;
}

uint32_t hrtim_timer_clear_counter_reset_event(hrtim_driver_t *hdp, 
                                               hrtim_timer_t timer,
                                               uint32_t event) {

    uint32_t prev_event = hdp->timer_cntr_rst_event[timer];

    if (timer != HRTIM_TIMER_MASTER) {
        hdp->timer_cntr_rst_event[timer] &= ~(event);

        /* Update on-fly.*/
        if (hdp->is_enable == true) {
            hdp->hrtim->sTimerxRegs[timer].RSTxR &= ~(event);
        }
    }

    return prev_event;
}

void hrtim_timer_set_preload_update(hrtim_driver_t *hdp,
                                    hrtim_timer_t timer,
                                    uint32_t preload,
                                    uint32_t update_src) {

    if (timer == HRTIM_TIMER_MASTER) {
        hdp->master_preload.enable = preload;
        hdp->master_preload.update_event = (uint32_t)update_src;
    } else {
        hdp->timer_preload[timer].enable |= preload;
        hdp->timer_preload[timer].update_event |= update_src;
    }

    /* Update on-fly.*/
    if (hdp->is_enable == true) {
        if (timer == HRTIM_TIMER_MASTER) {
            hdp->hrtim->sMasterRegs.MCR |= ((uint32_t)preload);
            hdp->hrtim->sMasterRegs.MCR |= ((uint32_t)update_src);
        } else {
            hdp->hrtim->sTimerxRegs[timer].TIMxCR |= ((uint32_t)preload);
            hdp->hrtim->sTimerxRegs[timer].TIMxCR |= ((uint32_t)update_src);
        }
    }
}

void hrtim_timer_clear_preload_update(hrtim_driver_t *hdp,
                                      hrtim_timer_t timer,
                                      uint32_t preload,
                                      uint32_t update_src) {

    if (timer == HRTIM_TIMER_MASTER) {
        hdp->master_preload.enable &= ~(preload);
        hdp->master_preload.update_event &= ~(update_src);
    } else {
        hdp->timer_preload[timer].enable &= ~(preload);
        hdp->timer_preload[timer].update_event &= ~(update_src);
    }

    /* Update on-fly.*/
    if (hdp->is_enable == true) {
        if (timer == HRTIM_TIMER_MASTER) {
            hdp->hrtim->sMasterRegs.MCR &= ~((uint32_t)preload);
            hdp->hrtim->sMasterRegs.MCR &= ~((uint32_t)update_src);
        } else { 
            hdp->hrtim->sTimerxRegs[timer].TIMxCR &= ~((uint32_t)preload);
            hdp->hrtim->sTimerxRegs[timer].TIMxCR &= ~((uint32_t)update_src);
        }
    }
}

hrtim_mode_tpg_t hrtim_timer_set_half_intlvd_mode(hrtim_driver_t *hdp,
                                                  hrtim_timer_t timer,
                                                  hrtim_mode_tpg_t mode) {

    hrtim_mode_tpg_t  prev_mode;

    if (timer == HRTIM_TIMER_MASTER) {
        prev_mode = hdp->master_mode_tpg;
        hdp->master_mode_tpg = mode;
    } else {
        prev_mode = hdp->timer_mode_tpg[timer];
        hdp->timer_mode_tpg[timer] = mode;
    }    

    return prev_mode;
}

uint32_t hrtim_timer_set_up_down_mode(hrtim_driver_t *hdp,
                                      hrtim_timer_t timer,
                                      uint32_t up_mode){

    uint32_t prev_up_mode = hdp->timer_count_mode[timer].up_down_mode;

    if (timer != HRTIM_TIMER_MASTER) {
        hdp->timer_count_mode[timer].up_down_mode = (uint32_t)up_mode;
    }

    return prev_up_mode;
}


void hrtim_timer_set_sw_update(hrtim_driver_t *hdp,
                               hrtim_timer_t timer) {
 
    /* Update on-fly.*/
    if (hdp->is_enable == true)  {
        if (timer == HRTIM_TIMER_MASTER) {
            hdp->hrtim->sCommonRegs.CR2 |= HRTIM_CR2_MSWU;
        } else {
            hdp->hrtim->sCommonRegs.CR2 |= (HRTIM_CR2_TASWU << (uint32_t)timer);
        }
    }
}

void hrtim_timer_set_adc_trigger(hrtim_driver_t *hdp,
                                 hrtim_timer_adctrigger_t adc_trigger,
                                 uint32_t event_trigger, 
                                 uint32_t update_src) { 
    uint32_t hrtim_cr1;
    uint32_t hrtim_adcur;

    hdp->adc_trg[adc_trigger].adc_trigger  = adc_trigger;
    hdp->adc_trg[adc_trigger].event_trigger = event_trigger;
    hdp->adc_trg[adc_trigger].update_src = update_src;

    /* Update on-fly.*/
    if (hdp->is_enable == true) {
        /* Set the ADC trigger update source */
        hrtim_cr1 =  hdp->hrtim->sCommonRegs.CR1;
        hrtim_adcur = hdp->hrtim->sCommonRegs.ADCUR;

        switch (adc_trigger) {
            case HRTIM_ADCTRIGGER_1:
                hrtim_cr1 &= ~(HRTIM_CR1_ADC2USRC_Msk);
                hrtim_cr1 |= ((uint32_t)(hdp->adc_trg[adc_trigger].update_src << HRTIM_CR1_ADC1USRC_Pos) & HRTIM_CR1_ADC1USRC_Msk);

                /* Set the ADC trigger 1 source.*/
                hdp->hrtim->sCommonRegs.ADC1R |= hdp->adc_trg[adc_trigger].event_trigger;
                break;
            case HRTIM_ADCTRIGGER_2:
                hrtim_cr1 &= ~(HRTIM_CR1_ADC2USRC_Msk);
                hrtim_cr1 |= ((hdp->adc_trg[adc_trigger].update_src << HRTIM_CR1_ADC2USRC_Pos) & HRTIM_CR1_ADC2USRC_Msk);

                /* Set the ADC trigger 2 source.*/
                hdp->hrtim->sCommonRegs.ADC2R |= hdp->adc_trg[adc_trigger].event_trigger;
                break;
            case HRTIM_ADCTRIGGER_3:
                hrtim_cr1 &= ~(HRTIM_CR1_ADC3USRC_Msk);
                hrtim_cr1 |= ((hdp->adc_trg[adc_trigger].update_src << HRTIM_CR1_ADC3USRC_Pos) & HRTIM_CR1_ADC3USRC_Msk);

                /* Set the ADC trigger 3 source.*/
                hdp->hrtim->sCommonRegs.ADC3R |=  hdp->adc_trg[adc_trigger].event_trigger;
                break;
            case HRTIM_ADCTRIGGER_4:
                hrtim_cr1 &= ~(HRTIM_CR1_ADC4USRC_Msk);
                hrtim_cr1 |= ((hdp->adc_trg[adc_trigger].update_src << HRTIM_CR1_ADC4USRC_Pos) & HRTIM_CR1_ADC4USRC_Msk);

                /* Set the ADC trigger 4 source.*/
                hdp->hrtim->sCommonRegs.ADC4R |= hdp->adc_trg[adc_trigger].event_trigger;
                break;
            case HRTIM_ADCTRIGGER_5:
                hrtim_adcur &= ~(HRTIM_ADCUR_AD5USRC_Msk);
                hrtim_adcur |= ((hdp->adc_trg[adc_trigger].update_src << HRTIM_ADCUR_AD5USRC_Pos) & HRTIM_ADCUR_AD5USRC_Msk);

                /* Set the ADC trigger 5 source.*/
                hdp->hrtim->sCommonRegs.ADCER &= ~(HRTIM_ADCER_AD5TRG);
                hdp->hrtim->sCommonRegs.ADCER |= ((hdp->adc_trg[adc_trigger].event_trigger << HRTIM_ADCER_AD5TRG_Pos) & HRTIM_ADCER_AD5TRG);
                break;
            case HRTIM_ADCTRIGGER_6:
                hrtim_adcur &= ~(HRTIM_ADCUR_AD6USRC_Msk);
                hrtim_adcur |= ((hdp->adc_trg[adc_trigger].update_src << HRTIM_ADCUR_AD6USRC_Pos) & HRTIM_ADCUR_AD6USRC_Msk);

                /* Set the ADC trigger 6 source.*/
                hdp->hrtim->sCommonRegs.ADCER &= ~(HRTIM_ADCER_AD6TRG);
                hdp->hrtim->sCommonRegs.ADCER |= ((hdp->adc_trg[adc_trigger].event_trigger << HRTIM_ADCER_AD6TRG_Pos) & HRTIM_ADCER_AD6TRG);
                break;
            case HRTIM_ADCTRIGGER_7:
                hrtim_adcur &= ~(HRTIM_ADCUR_AD7USRC_Msk);
                hrtim_adcur |= ((hdp->adc_trg[adc_trigger].update_src << HRTIM_ADCUR_AD7USRC_Pos) & HRTIM_ADCUR_AD7USRC_Msk);

                /* Set the ADC trigger 7 source.*/
                hdp->hrtim->sCommonRegs.ADCER &= ~(HRTIM_ADCER_AD7TRG);
                hdp->hrtim->sCommonRegs.ADCER |= ((hdp->adc_trg[adc_trigger].event_trigger << HRTIM_ADCER_AD7TRG_Pos) & HRTIM_ADCER_AD7TRG);
                break;
            case HRTIM_ADCTRIGGER_8:
                hrtim_adcur &= ~(HRTIM_ADCUR_AD8USRC_Msk);
                hrtim_adcur |= ((hdp->adc_trg[adc_trigger].update_src << HRTIM_ADCUR_AD8USRC_Pos) & HRTIM_ADCUR_AD8USRC_Msk);

                /* Set the ADC trigger 8 source.*/
                hdp->hrtim->sCommonRegs.ADCER &= ~(HRTIM_ADCER_AD8TRG);
                hdp->hrtim->sCommonRegs.ADCER |= ((hdp->adc_trg[adc_trigger].event_trigger << HRTIM_ADCER_AD8TRG_Pos) & HRTIM_ADCER_AD8TRG);
                break;
            case HRTIM_ADCTRIGGER_9:
                hrtim_adcur &= ~(HRTIM_ADCUR_AD9USRC_Msk);
                hrtim_adcur |= ((hdp->adc_trg[adc_trigger].update_src << HRTIM_ADCUR_AD9USRC_Pos) & HRTIM_ADCUR_AD9USRC_Msk);

                /* Set the ADC trigger 9 source.*/
                hdp->hrtim->sCommonRegs.ADCER &= ~(HRTIM_ADCER_AD9TRG);
                hdp->hrtim->sCommonRegs.ADCER |= ((hdp->adc_trg[adc_trigger].event_trigger << HRTIM_ADCER_AD9TRG_Pos) & HRTIM_ADCER_AD9TRG);
                break;
            case HRTIM_ADCTRIGGER_10:
                hrtim_adcur &= ~(HRTIM_ADCUR_AD10USRC_Msk);
                hrtim_adcur |= ((hdp->adc_trg[adc_trigger].update_src << HRTIM_ADCUR_AD10USRC_Pos) & HRTIM_ADCUR_AD10USRC_Msk);

                /* Set the ADC trigger 10 source.*/
                hdp->hrtim->sCommonRegs.ADCER &= ~(HRTIM_ADCER_AD10TRG);
                hdp->hrtim->sCommonRegs.ADCER |= ((hdp->adc_trg[adc_trigger].event_trigger << HRTIM_ADCER_AD10TRG_Pos) & HRTIM_ADCER_AD10TRG);
                break;
            default:
                /* for MISRA compliance */
                break;
        }

        /* Update the HRTIM registers.*/
        if (adc_trigger < HRTIM_ADCTRIGGER_5) {
            hdp->hrtim->sCommonRegs.CR1 = hrtim_cr1;
        } else {
            hdp->hrtim->sCommonRegs.ADCUR = hrtim_adcur;
        }
    }
}

uint32_t hrtim_timer_set_adc_post_scaler(hrtim_driver_t *hdp,
                                         hrtim_timer_adctrigger_t adc_trigger,
                                         uint32_t postscaler) {

    uint32_t prev_postscaler = hdp->adc_trg[adc_trigger].post_scaler_rate;

    hdp->adc_trg[adc_trigger].post_scaler_rate = postscaler;

    /* Update on-fly.*/
    if (hdp->is_enable == true) {
        switch (adc_trigger) {
            case HRTIM_ADCTRIGGER_1: 
                hdp->hrtim->sCommonRegs.ADCPS1 |= ((uint32_t)(postscaler<<HRTIM_ADCPS1_AD1PSC_Pos)& HRTIM_ADCPS1_AD1PSC_Msk);
                break;
            case HRTIM_ADCTRIGGER_2:
                hdp->hrtim->sCommonRegs.ADCPS1 |= ((uint32_t)(postscaler<<HRTIM_ADCPS1_AD2PSC_Pos)& HRTIM_ADCPS1_AD2PSC_Msk);
                break;
            case HRTIM_ADCTRIGGER_3:
                hdp->hrtim->sCommonRegs.ADCPS1 |= ((uint32_t)(postscaler<<HRTIM_ADCPS1_AD3PSC_Pos)& HRTIM_ADCPS1_AD3PSC_Msk);
                break;
            case HRTIM_ADCTRIGGER_4:
                hdp->hrtim->sCommonRegs.ADCPS1 |= ((uint32_t)(postscaler<<HRTIM_ADCPS1_AD4PSC_Pos)& HRTIM_ADCPS1_AD4PSC_Msk);
                break;
            case HRTIM_ADCTRIGGER_5:
                hdp->hrtim->sCommonRegs.ADCPS1 |= ((uint32_t)(postscaler<<HRTIM_ADCPS1_AD5PSC_Pos)& HRTIM_ADCPS1_AD5PSC_Msk);
                break;
            case HRTIM_ADCTRIGGER_6:
                hdp->hrtim->sCommonRegs.ADCPS2 |= ((uint32_t)(postscaler<<HRTIM_ADCPS2_AD6PSC_Pos)& HRTIM_ADCPS2_AD6PSC_Msk);
                break;
            case HRTIM_ADCTRIGGER_7:
                hdp->hrtim->sCommonRegs.ADCPS2 |= ((uint32_t)(postscaler<<HRTIM_ADCPS2_AD7PSC_Pos)& HRTIM_ADCPS2_AD7PSC_Msk);
                break;
            case HRTIM_ADCTRIGGER_8:
                hdp->hrtim->sCommonRegs.ADCPS2 |= ((uint32_t)(postscaler<<HRTIM_ADCPS2_AD8PSC_Pos)& HRTIM_ADCPS2_AD8PSC_Msk);
                break;
            case HRTIM_ADCTRIGGER_9:
                hdp->hrtim->sCommonRegs.ADCPS2 |= ((uint32_t)(postscaler<<HRTIM_ADCPS2_AD9PSC_Pos)& HRTIM_ADCPS2_AD9PSC_Msk);
                break;
            case HRTIM_ADCTRIGGER_10:
                hdp->hrtim->sCommonRegs.ADCPS2 |= ((uint32_t)(postscaler<<HRTIM_ADCPS2_AD10PSC_Pos)& HRTIM_ADCPS2_AD10PSC_Msk);
                break;
            default:
                /* for MISRA compliance */
                break;
        }
    }

    return prev_postscaler;
}

void hrtim_set_ex_event(hrtim_driver_t *hdp,
                        uint8_t  eev_idx,
                        uint32_t ext_source,
                        uint32_t ext_polarity,
                        uint32_t ext_sensitivity,
                        uint32_t ext_filter,
                        uint32_t ext_fast_mode) {

    uint32_t hrtim_eecr1;
    uint32_t hrtim_eecr2;
    uint32_t hrtim_eecr3;

    hdp->eev[eev_idx].event = eev_idx;
    hdp->eev[eev_idx].source = ext_source;
    hdp->eev[eev_idx].polarity = ext_polarity;
    hdp->eev[eev_idx].sensitivity = ext_sensitivity;
    hdp->eev[eev_idx].filter = ext_filter;
    hdp->eev[eev_idx].fast_mode = ext_fast_mode;

    /* Update on-fly.*/
    if (hdp->is_enable == true) {
        /* Configure external event channel.*/
        hrtim_eecr1 = hdp->hrtim->sCommonRegs.EECR1;
        hrtim_eecr2 = hdp->hrtim->sCommonRegs.EECR2;
        hrtim_eecr3 = hdp->hrtim->sCommonRegs.EECR3;

        switch (eev_idx) {
            case HRTIM_EVENT_NONE:
                /* Update the HRTIM registers */
                hdp->hrtim->sCommonRegs.EECR1 = 0U;
                hdp->hrtim->sCommonRegs.EECR2 = 0U;
                hdp->hrtim->sCommonRegs.EECR3 = 0U;
                break;
            case HRTIM_EVENT_1:
                hrtim_eecr1 &= ~(HRTIM_EECR1_EE1SRC | HRTIM_EECR1_EE1POL | HRTIM_EECR1_EE1SNS | HRTIM_EECR1_EE1FAST);
                hrtim_eecr1 |= ( ext_source & HRTIM_EECR1_EE1SRC);
                hrtim_eecr1 |= ( ext_polarity & HRTIM_EECR1_EE1POL);
                hrtim_eecr1 |= ( ext_sensitivity & HRTIM_EECR1_EE1SNS);
                /* Update the HRTIM registers (all bitfields but EE1FAST bit) */
                hdp->hrtim->sCommonRegs.EECR1 |= hrtim_eecr1;
                /* Update the HRTIM registers (EE1FAST bit) */
                hrtim_eecr1 |= ( ext_fast_mode  & HRTIM_EECR1_EE1FAST);
                hdp->hrtim->sCommonRegs.EECR1 |= hrtim_eecr1;
                break;
            case HRTIM_EVENT_2:
                hrtim_eecr1 &= ~(HRTIM_EECR1_EE2SRC | HRTIM_EECR1_EE2POL | HRTIM_EECR1_EE2SNS | HRTIM_EECR1_EE2FAST);
                hrtim_eecr1 |= (( ext_source << 6U) & HRTIM_EECR1_EE2SRC);
                hrtim_eecr1 |= (( ext_polarity << 6U) & HRTIM_EECR1_EE2POL);
                hrtim_eecr1 |= (( ext_sensitivity << 6U) & HRTIM_EECR1_EE2SNS);
                /* Update the HRTIM registers (all bitfields but EE2FAST bit) */
                hdp->hrtim->sCommonRegs.EECR1 |= hrtim_eecr1;
                /* Update the HRTIM registers (EE2FAST bit) */
                hrtim_eecr1 |= (( ext_fast_mode << 6U) & HRTIM_EECR1_EE2FAST);
                hdp->hrtim->sCommonRegs.EECR1 |= hrtim_eecr1;
                break;
            case HRTIM_EVENT_3:
                hrtim_eecr1 &= ~(HRTIM_EECR1_EE3SRC | HRTIM_EECR1_EE3POL | HRTIM_EECR1_EE3SNS | HRTIM_EECR1_EE3FAST);
                hrtim_eecr1 |= (( ext_source << 12U) & HRTIM_EECR1_EE3SRC);
                hrtim_eecr1 |= (( ext_polarity << 12U) & HRTIM_EECR1_EE3POL);
                hrtim_eecr1 |= (( ext_sensitivity << 12U) & HRTIM_EECR1_EE3SNS);
                /* Update the HRTIM registers (all bitfields but EE3FAST bit) */
                hdp->hrtim->sCommonRegs.EECR1 |= hrtim_eecr1;
                /* Update the HRTIM registers (EE3FAST bit) */
                hrtim_eecr1 |= (( ext_fast_mode << 12U) & HRTIM_EECR1_EE3FAST);
                hdp->hrtim->sCommonRegs.EECR1 |= hrtim_eecr1;
                break;
            case HRTIM_EVENT_4:
                hrtim_eecr1 &= ~(HRTIM_EECR1_EE4SRC | HRTIM_EECR1_EE4POL | HRTIM_EECR1_EE4SNS | HRTIM_EECR1_EE4FAST);
                hrtim_eecr1 |= (( ext_source << 18U) & HRTIM_EECR1_EE4SRC);
                hrtim_eecr1 |= (( ext_polarity << 18U) & HRTIM_EECR1_EE4POL);
                hrtim_eecr1 |= (( ext_sensitivity << 18U) & HRTIM_EECR1_EE4SNS);
                /* Update the HRTIM registers (all bitfields but EE4FAST bit) */
                hdp->hrtim->sCommonRegs.EECR1 |= hrtim_eecr1;
                /* Update the HRTIM registers (EE4FAST bit) */
                hrtim_eecr1 |= (( ext_fast_mode << 18U) & HRTIM_EECR1_EE4FAST);
                hdp->hrtim->sCommonRegs.EECR1 |= hrtim_eecr1;
                break;
            case HRTIM_EVENT_5:
                hrtim_eecr1 &= ~(HRTIM_EECR1_EE5SRC | HRTIM_EECR1_EE5POL | HRTIM_EECR1_EE5SNS | HRTIM_EECR1_EE5FAST);
                hrtim_eecr1 |= (( ext_source << 24U) & HRTIM_EECR1_EE5SRC);
                hrtim_eecr1 |= (( ext_polarity << 24U) & HRTIM_EECR1_EE5POL);
                hrtim_eecr1 |= (( ext_sensitivity << 24U) & HRTIM_EECR1_EE5SNS);
                /* Update the HRTIM registers (all bitfields but EE5FAST bit) */
                hdp->hrtim->sCommonRegs.EECR1 |= hrtim_eecr1;
                /* Update the HRTIM registers (EE5FAST bit) */
                hrtim_eecr1 |= (( ext_fast_mode << 24U) & HRTIM_EECR1_EE5FAST);
                hdp->hrtim->sCommonRegs.EECR1 |= hrtim_eecr1;
                break;
            case HRTIM_EVENT_6:
                hrtim_eecr2 &= ~(HRTIM_EECR2_EE6SRC | HRTIM_EECR2_EE6POL | HRTIM_EECR2_EE6SNS);
                hrtim_eecr2 |= ( ext_source & HRTIM_EECR2_EE6SRC);
                hrtim_eecr2 |= ( ext_polarity & HRTIM_EECR2_EE6POL);
                hrtim_eecr2 |= ( ext_sensitivity & HRTIM_EECR2_EE6SNS);
                hrtim_eecr3 &= ~(HRTIM_EECR3_EE6F);
                hrtim_eecr3 |= ( ext_filter & HRTIM_EECR3_EE6F);
                /* Update the HRTIM registers */
                hdp->hrtim->sCommonRegs.EECR2 |= hrtim_eecr2;
                hdp->hrtim->sCommonRegs.EECR3 |= hrtim_eecr3;
                break;
            case HRTIM_EVENT_7:
                hrtim_eecr2 &= ~(HRTIM_EECR2_EE7SRC | HRTIM_EECR2_EE7POL | HRTIM_EECR2_EE7SNS);
                hrtim_eecr2 |= (( ext_source << 6U) & HRTIM_EECR2_EE7SRC);
                hrtim_eecr2 |= (( ext_polarity << 6U) & HRTIM_EECR2_EE7POL);
                hrtim_eecr2 |= (( ext_sensitivity << 6U) & HRTIM_EECR2_EE7SNS);
                hrtim_eecr3 &= ~(HRTIM_EECR3_EE7F);
                hrtim_eecr3 |= (( ext_filter << 6U) & HRTIM_EECR3_EE7F);
                /* Update the HRTIM registers */
                hdp->hrtim->sCommonRegs.EECR2 |= hrtim_eecr2;
                hdp->hrtim->sCommonRegs.EECR3 |= hrtim_eecr3;
                break;
            case HRTIM_EVENT_8:
                hrtim_eecr2 &= ~(HRTIM_EECR2_EE8SRC | HRTIM_EECR2_EE8POL | HRTIM_EECR2_EE8SNS);
                hrtim_eecr2 |= (( ext_source << 12U) & HRTIM_EECR2_EE8SRC);
                hrtim_eecr2 |= (( ext_polarity << 12U) & HRTIM_EECR2_EE8POL);
                hrtim_eecr2 |= (( ext_sensitivity << 12U) & HRTIM_EECR2_EE8SNS);
                hrtim_eecr3 &= ~(HRTIM_EECR3_EE8F);
                hrtim_eecr3 |= (( ext_filter << 12U) & HRTIM_EECR3_EE8F );
                /* Update the HRTIM registers */
                hdp->hrtim->sCommonRegs.EECR2 |= hrtim_eecr2;
                hdp->hrtim->sCommonRegs.EECR3 |= hrtim_eecr3;
                break;
            case HRTIM_EVENT_9:
                hrtim_eecr2 &= ~(HRTIM_EECR2_EE9SRC | HRTIM_EECR2_EE9POL | HRTIM_EECR2_EE9SNS);
                hrtim_eecr2 |= (( ext_source << 18U) & HRTIM_EECR2_EE9SRC);
                hrtim_eecr2 |= (( ext_polarity << 18U) & HRTIM_EECR2_EE9POL);
                hrtim_eecr2 |= (( ext_sensitivity << 18U) & HRTIM_EECR2_EE9SNS);
                hrtim_eecr3 &= ~(HRTIM_EECR3_EE9F);
                hrtim_eecr3 |= (( ext_filter << 18U) & HRTIM_EECR3_EE9F);
                /* Update the HRTIM registers */
                hdp->hrtim->sCommonRegs.EECR2 |= hrtim_eecr2;
                hdp->hrtim->sCommonRegs.EECR3 |= hrtim_eecr3;
                break;
            case HRTIM_EVENT_10:
                hrtim_eecr2 &= ~(HRTIM_EECR2_EE10SRC | HRTIM_EECR2_EE10POL | HRTIM_EECR2_EE10SNS);
                hrtim_eecr2 |= (( ext_source << 24U) & HRTIM_EECR2_EE10SRC);
                hrtim_eecr2 |= (( ext_polarity << 24U) & HRTIM_EECR2_EE10POL);
                hrtim_eecr2 |= (( ext_sensitivity << 24U) & HRTIM_EECR2_EE10SNS);
                hrtim_eecr3 &= ~(HRTIM_EECR3_EE10F);
                hrtim_eecr3 |= (( ext_filter << 24U) & HRTIM_EECR3_EE10F);
                /* Update the HRTIM registers */
                hdp->hrtim->sCommonRegs.EECR2 |= hrtim_eecr2;
                hdp->hrtim->sCommonRegs.EECR3 |= hrtim_eecr3;
                break;
            default:
                /* for MISRA compliance */
                break;
        }
    }
}

hrtim_eev_prsc_t hrtim_set_event_prescaler(hrtim_driver_t *hdp,
                                           hrtim_eev_prsc_t eev_prsc) {
    hrtim_eev_prsc_t prev_prescaler;

    prev_prescaler = hdp->eev_prescaler;
    hdp->eev_prescaler = eev_prsc;

    return prev_prescaler;
}

void hrtim_timer_set_eev_filtering(hrtim_driver_t *hdp,
                                         hrtim_timer_t timer,
                                         uint8_t eev_idx,
                                         uint32_t filter, 
                                         uint32_t latch) {

    hdp->timer_eev_filter[timer][eev_idx - 1U].filter = (uint32_t)(filter);
    hdp->timer_eev_filter[timer][eev_idx - 1U].latch  = (uint32_t)(latch);
}

void hrtim_ext_even_counter_cfg(hrtim_driver_t *hdp,
                                hrtim_timer_t timer,
                                uint8_t eev_idx,
                                uint32_t reset_mode,
                                uint32_t source,
                                uint32_t counter) {

   hdp->eev_counter[timer][eev_idx - 1U].reset_mode = reset_mode;
   hdp->eev_counter[timer][eev_idx - 1U].source = source;
   hdp->eev_counter[timer][eev_idx - 1U].counter = counter;
}

void hrtim_timer_eev_counter_enable(hrtim_driver_t *hdp, hrtim_timer_t timer) {

    if (hdp->is_enable == true) {
        hdp->hrtim->sTimerxRegs[timer].EEFxR3 = HRTIM_EEFxR3_EEVACE;
    }
}

void hrtim_timer_eev_counter_disable(hrtim_driver_t *hdp, hrtim_timer_t timer) {

    if (hdp->is_enable == true) {
        hdp->hrtim->sTimerxRegs[timer].EEFxR3 &= ~ HRTIM_EEFxR3_EEVACE;
    }
}

void hrtim_timer_eev_counter_reset(hrtim_driver_t *hdp, hrtim_timer_t timer) {

    if (hdp->is_enable == true) {
        hdp->hrtim->sTimerxRegs[timer].EEFxR3 = HRTIM_EEFxR3_EEVACRES;
    }
}

void hrtim_timer_set_dacsync_trigger(hrtim_driver_t *hdp, 
                                     hrtim_timer_t timer,
                                     uint32_t sync_trigger) {

    if (hdp->is_enable == true) {
        if (timer == HRTIM_TIMER_MASTER) {
            hdp->hrtim->sMasterRegs.MCR = ((hdp->hrtim->sMasterRegs.MCR & (~(HRTIM_MCR_DACSYNC_Msk)))) | sync_trigger;
        } else {
            hdp->hrtim->sTimerxRegs[timer].TIMxCR = (hdp->hrtim->sTimerxRegs[timer].TIMxCR & (~(HRTIM_TIMxCR_DACSYNC_Msk))) | sync_trigger;
        }
    }
}
void hrtim_timer_enable_dualdac_trigger(hrtim_driver_t *hdp,
                                        hrtim_timer_t timer) {

    hdp->timer_dualdac_enable[timer] = 1;
}

void hrtim_timer_set_dualdac_trigger(hrtim_driver_t *hdp,
                                     hrtim_timer_t timer,
                                     uint32_t reset_trigger,
                                     uint32_t step_trigger) {

    uint32_t timx_cr2;

    if(hdp->is_enable == true) {
        timx_cr2 = hdp->hrtim->sTimerxRegs[timer].TIMxCR2 & (~(HRTIM_TIMxCR2_DCDR | HRTIM_TIMxCR2_DCDS));
        timx_cr2 |= (reset_trigger | step_trigger);
        hdp->hrtim->sTimerxRegs[timer].TIMxCR2 = timx_cr2;
    } 
}

uint16_t  hrtim_timer_set_adc_rollover(hrtim_driver_t *hdp,
                                       hrtim_timer_t timer,
                                       uint16_t adc_rollover_mode) {

    uint16_t prev_rollover_mode;

    prev_rollover_mode = hdp->timer_count_mode[timer].adc_rollover;
    hdp->timer_count_mode[timer].adc_rollover = adc_rollover_mode;

    return prev_rollover_mode;
}

uint16_t hrtim_timer_set_fault_event_rollover(hrtim_driver_t *hdp,
                                              hrtim_timer_t timer,
                                              uint16_t flt_rollover_mode) {

    uint16_t prev_rollover_mode;

    prev_rollover_mode = hdp->timer_count_mode[timer].fault_event_rollover;
    hdp->timer_count_mode[timer].fault_event_rollover = flt_rollover_mode;

    return prev_rollover_mode;
}

uint16_t hrtim_timer_set_out_rollover(hrtim_driver_t *hdp,
                                      hrtim_timer_t timer,
                                      uint16_t out_rollover_mode) {

    uint16_t prev_rollover_mode;

    prev_rollover_mode = hdp->timer_count_mode[timer].out_rollover;
    hdp->timer_count_mode[timer].out_rollover = out_rollover_mode;

    return prev_rollover_mode;
}

uint16_t hrtim_timer_set_burstmode_rollover(hrtim_driver_t *hdp,
                                            hrtim_timer_t timer,
                                            uint16_t brst_rollover_mode) {

    uint16_t prerv_rollover;

    prerv_rollover = hdp->timer_count_mode[timer].burstmode_rollover;
    hdp->timer_count_mode[timer].burstmode_rollover = brst_rollover_mode;

    return prerv_rollover;
}

uint16_t hrtim_timer_set_rollover(hrtim_driver_t *hdp,
                                  hrtim_timer_t timer,
                                  uint16_t rollover_mode) {

    uint16_t prev_rollover_mode;

    prev_rollover_mode = hdp->timer_count_mode[timer].rollover;
    hdp->timer_count_mode[timer].rollover = rollover_mode;

    return prev_rollover_mode;
}

void hrtim_set_fault_cfg(hrtim_driver_t *hdp,
                         hrtim_fault_t fault_idx,
                         bool enable,
                         uint32_t source,
                         uint32_t polarity,
                         uint32_t filter,
                         uint32_t lock) {

    hdp->fault[fault_idx].fault_idx = fault_idx;
    hdp->fault[fault_idx].enable = enable;
    hdp->fault[fault_idx].source = source;
    hdp->fault[fault_idx].polarity = polarity;
    hdp->fault[fault_idx].filter = filter;
    hdp->fault[fault_idx].lock = lock;
}

hrtim_fault_prsc_t hrtim_set_fault_prsc(hrtim_driver_t *hdp,
                                        hrtim_fault_prsc_t prescaler){

    hrtim_fault_prsc_t prev_fault_prescaler;

    prev_fault_prescaler = hdp->fault_prescaler;
    hdp->fault_prescaler = prescaler;

    return prev_fault_prescaler;
}

void hrtim_set_fault_counter_cfg(hrtim_driver_t *hdp,
                                 hrtim_fault_t fault_idx,
                                 uint32_t threshold, 
                                 uint32_t reset_mode,
                                 uint32_t blanking_source) {

    hdp->fault_blnk[fault_idx].threshold = threshold;
    hdp->fault_blnk[fault_idx].reset_mode = reset_mode;
    hdp->fault_blnk[fault_idx].blanking_source = blanking_source;
}

hrtim_out_faultstate_t hrtim_timer_set_output_faultstate(hrtim_driver_t *hdp,
                                                         hrtim_timer_t timer,
                                                         hrtim_out_t output,
                                                         hrtim_out_faultstate_t fault_state) {
    hrtim_out_faultstate_t prev_fault_state;

    prev_fault_state =  hdp->fault_state[timer][output];
    hdp->fault_state[timer][output] = fault_state;

    return prev_fault_state;
}

hrtim_out_idlestate_t hrtim_timer_set_output_idlestate(hrtim_driver_t *hdp,
                                                       hrtim_timer_t timer,
                                                       hrtim_out_t output,
                                                       hrtim_out_idlestate_t idle_state) {
    hrtim_out_idlestate_t prev_idle_state;

    prev_idle_state = hdp->idle_state[timer][output];
    hdp->idle_state[timer][output] = idle_state;

    return prev_idle_state;
}

hrtim_out_polarity_t hrtim_timer_set_output_polarity(hrtim_driver_t *hdp,
                                                     hrtim_timer_t timer,
                                                     hrtim_out_t output,
                                                     hrtim_out_polarity_t polarity) {

    hrtim_out_polarity_t prev_out_polarity;

    prev_out_polarity = hdp->out_polarity[timer][output];
    hdp->out_polarity[timer][output] = polarity;

    return prev_out_polarity;
}

hrtim_output_state_t hrtim_timer_get_output_state(hrtim_driver_t *hdp,
                                                  hrtim_timer_t timer,
                                                  hrtim_out_t output) {

    uint32_t output_bit = ((0x01UL << ((uint32_t)output)) << (((uint32_t)timer) * 2U));

    if ((hdp->hrtim->sCommonRegs.OENR & output_bit) != 0U) {
        return HRTIM_OUTPUT_STATE_RUN;
    } else {
        if ((hdp->hrtim->sCommonRegs.ODSR & output_bit) != 0U) {
            return HRTIM_OUTPUT_STATE_FAULT;
        } else {
            return HRTIM_OUTPUT_STATE_IDLE;
        }
    }
}

void hrtim_timer_set_capture_unit(hrtim_driver_t *hdp,
                                  hrtim_timer_t timer,
                                  uint32_t cpt1_source,
                                  uint32_t cpt2_source) {

    if (timer != HRTIM_TIMER_MASTER) {
        hdp->cpt_unit[timer].capture_trg_1 = cpt1_source;
        hdp->cpt_unit[timer].capture_trg_2 = cpt2_source;
    }
}

void hrtim_timer_fault_enable(hrtim_driver_t *hdp,
                              hrtim_timer_t timer,
                              hrtim_fault_t flt_source,
                              uint32_t flt_lock) {

    if(hdp->is_enable == true) {
        hdp->hrtim->sTimerxRegs[timer].FLTxR |= (0x01UL << ((uint32_t)flt_source));
        /* The FLTLCK bit(Fault sources lock) is write-once. Once it has been
           set, it cannot be modified till the next system or IP reset.*/
        hdp->hrtim->sTimerxRegs[timer].FLTxR |= flt_lock;
    }
}

void hrtim_stop(hrtim_driver_t *hdp) {

    uint8_t i;

    /* Reset register configuration.*/
    for (i = 0U; i < HRTIM_TIMER_NUM; i++) {
        hdp->hrtim->sTimerxRegs[i].TIMxCR    = 0U;
        hdp->hrtim->sTimerxRegs[i].TIMxDIER  = 0U;
        hdp->hrtim->sTimerxRegs[i].PERxR     = 0x0000FFDFU;
        hdp->hrtim->sTimerxRegs[i].REPxR     = 0U;
        hdp->hrtim->sTimerxRegs[i].CMP1xR    = 0U;
        hdp->hrtim->sTimerxRegs[i].CMP2xR    = 0U;
        hdp->hrtim->sTimerxRegs[i].CMP3xR    = 0U;
        hdp->hrtim->sTimerxRegs[i].CMP4xR    = 0U;
        hdp->hrtim->sTimerxRegs[i].DTxR      = 0U;
        hdp->hrtim->sTimerxRegs[i].SETx1R    = 0U;
        hdp->hrtim->sTimerxRegs[i].RSTx1R    = 0U;
        hdp->hrtim->sTimerxRegs[i].SETx2R    = 0U;
        hdp->hrtim->sTimerxRegs[i].RSTx2R    = 0U;
        hdp->hrtim->sTimerxRegs[i].EEFxR1    = 0U;
        hdp->hrtim->sTimerxRegs[i].EEFxR2    = 0U;
        hdp->hrtim->sTimerxRegs[i].RSTxR     = 0U;
        hdp->hrtim->sTimerxRegs[i].CHPxR     = 0U;
        hdp->hrtim->sTimerxRegs[i].CPT1xCR   = 0U;
        hdp->hrtim->sTimerxRegs[i].CPT2xCR   = 0U;
        hdp->hrtim->sTimerxRegs[i].OUTxR     = 0U;
        hdp->hrtim->sTimerxRegs[i].FLTxR     = 0U;
        hdp->hrtim->sTimerxRegs[i].TIMxCR2   = 0U;
        hdp->hrtim->sTimerxRegs[i].EEFxR3    = 0U;
    }

    hdp->hrtim->sCommonRegs.CR1     = 0U;
    hdp->hrtim->sCommonRegs.CR2     = 0U;
    hdp->hrtim->sCommonRegs.IER     = 0U;
    hdp->hrtim->sCommonRegs.BMCR    = 0U;
    hdp->hrtim->sCommonRegs.BMTRGR  = 0U;
    hdp->hrtim->sCommonRegs.BMCMPR  = 0U;
    hdp->hrtim->sCommonRegs.BMPER   = 0U;
    hdp->hrtim->sCommonRegs.EECR1   = 0U;
    hdp->hrtim->sCommonRegs.EECR2   = 0U;
    hdp->hrtim->sCommonRegs.EECR3   = 0U;
    hdp->hrtim->sCommonRegs.ADC1R   = 0U;
    hdp->hrtim->sCommonRegs.ADC2R   = 0U;
    hdp->hrtim->sCommonRegs.ADC3R   = 0U;
    hdp->hrtim->sCommonRegs.ADC4R   = 0U;
    hdp->hrtim->sCommonRegs.DLLCR   = 0U;
    hdp->hrtim->sCommonRegs.FLTINR1 = 0U;
    hdp->hrtim->sCommonRegs.FLTINR2 = 0U;
    hdp->hrtim->sCommonRegs.BDMUPR  = 0U;
    hdp->hrtim->sCommonRegs.BDTAUPR = 0U;
    hdp->hrtim->sCommonRegs.BDTBUPR = 0U;
    hdp->hrtim->sCommonRegs.BDTCUPR = 0U;
    hdp->hrtim->sCommonRegs.BDTDUPR = 0U;
    hdp->hrtim->sCommonRegs.BDTEUPR = 0U;
    hdp->hrtim->sCommonRegs.BDTFUPR = 0U;
    hdp->hrtim->sCommonRegs.ADCER   = 0U;
    hdp->hrtim->sCommonRegs.ADCUR   = 0U;
    hdp->hrtim->sCommonRegs.ADCPS1  = 0U;
    hdp->hrtim->sCommonRegs.ADCPS2  = 0U;
    hdp->hrtim->sCommonRegs.FLTINR3 = 0U;
    hdp->hrtim->sCommonRegs.FLTINR4 = 0U;

    /* Master registers configuration setup.*/
    hdp->hrtim->sMasterRegs.MCR    = 0U;
    hdp->hrtim->sMasterRegs.MDIER  = 0U;
    hdp->hrtim->sMasterRegs.MPER   = 0x0000FFDFU;
    hdp->hrtim->sMasterRegs.MREP   = 0U;
    hdp->hrtim->sMasterRegs.MCMP1R = 0U;
    hdp->hrtim->sMasterRegs.MCMP2R = 0U;
    hdp->hrtim->sMasterRegs.MCMP3R = 0U;
    hdp->hrtim->sMasterRegs.MCMP4R = 0U;

    /* Clearing interrupt status bits.*/
    hdp->hrtim->sMasterRegs.MICR = 0xFFFFFFFFU;
    hdp->hrtim->sCommonRegs.ICR  = 0xFFFFFFFFU;
    for (i = 0U; i < HRTIM_TIMER_NUM; i++) {
        hdp->hrtim->sTimerxRegs[i].TIMxICR = 0xFFFFFFFFU;
    }

    /* Disable interrupts.*/
    hrtim_dev_disable_irq(hdp);

    /* Update enable status.*/
    hdp->is_enable = false;

    /* Disable clock.*/
    hrtim_dev_clock_disable(hdp);

    hdp->hrtim = NULL;
}

void hrtim_deinit(hrtim_driver_t *hdp) {

   /* Set pointer to HRTIM register block to NULL.*/
    hdp->hrtim = NULL;

    /* Set HRTIM clock value to 0.*/
    hdp->clock = 0U;

    /* Reset HRTIM parameters.*/
    hrtim_reset_paramters(hdp);
}

void __hrtim_serve_flt_interrupt(hrtim_driver_t *hdp) {
    
    HRTIM_Common_TypeDef *ctp = &hdp->hrtim->sCommonRegs;
    uint32_t isr, ier;

    /* Reading and clearing IRQ sources.*/
    ier = ctp->IER;
    isr = ctp->ISR & ier;
    ctp->ICR = isr;

    if (hdp->cb_flt != NULL) {
        hdp->cb_flt(hdp, isr);
    }
}

void __hrtim_serve_timer_interrupt(hrtim_driver_t *hdp, hrtim_timer_t timer) {

    uint32_t isr, ier;

    if (timer == HRTIM_TIMER_MASTER) {
        /* Reading and clearing IRQ sources.*/
        ier = hdp->hrtim->sMasterRegs.MDIER;
        isr = (hdp->hrtim->sMasterRegs.MISR) & ier;
        hdp->hrtim->sMasterRegs.MICR = isr;

        if (hdp->cb_mt != NULL) {
            hdp->cb_mt(hdp, isr);
        }
    } else {
        /* Reading and clearing IRQ sources.*/
        ier = hdp->hrtim->sTimerxRegs[timer].TIMxDIER;
        isr = (hdp->hrtim->sTimerxRegs[timer].TIMxISR) & ier;
        hdp->hrtim->sTimerxRegs[timer].TIMxICR = isr;

        if (hdp->cb[timer] != NULL) {
            hdp->cb[timer](hdp, isr);
        }
    }
}

/** @} */
