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
 * @file    hrtim_cfg.h
 * @brief   HRTIM driver configuration file.
 *
 * @addtogroup DRIVERS
 * @addtogroup TIMERS
 * @ingroup DRIVERS
 * @addtogroup HRTIM
 * @ingroup TIMERS
 * @{
 */

#ifndef _HRTIM_PRIVATE_H_
#define _HRTIM_PRIVATE_H_

#include <irq.h>
#include <platform.h>

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Module pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Module data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   HRTIM driver structure.
 */
struct hrtim_driver {
    /**
     * @brief   Associated HRTIM unit.
     */
    HRTIM_TypeDef            *hrtim;
    /**
     * @brief   Enable status.
     * @note    Flag set on true when clock is enabled, false otherwise.
     */
    bool                     is_enable;
    /**
     * @brief   Clock value.
     */
    uint32_t                 clock;   
    /**
     * @brief   Calibration period.
     */
    uint32_t                 cal_period;
    /**
     * @brief   Interrupt priority.
     */
    uint32_t                 prio;
    /**
     * @brief   Master mode.
     */
    hrtim_cntr_mode_t        master_mode;
    /**
     * @brief   Master prescaler.
     */
    hrtim_prsc_t             master_prescaler;
    /**
     * @brief   Master period.
     */
    uint16_t                 master_period;
    /**
     * @brief   Master comparators.
     */
    uint16_t                 master_cmp[HRTIM_COMP_NUM];
    /**
     * @brief   Timer counter modes.
     */
    hrtim_cntr_mode_t        timer_cntr_mode[HRTIM_TIMER_NUM];
    /**
     * @brief   Timer prescalers.
     */
    hrtim_prsc_t             timer_prescaler[HRTIM_TIMER_NUM];
    /**
     * @brief   Timer periods.
     */
    uint16_t                 timer_period[HRTIM_TIMER_NUM];
    /**
     * @brief   Timer comparators.
     */
    uint16_t                 timer_cmp[HRTIM_TIMER_NUM][HRTIM_COMP_NUM];
    /**
     * @brief   Timer comparator auto-delayed mode (available only for
     *          [TimerA:TimerF] and Comparator 2 or Comparator 4).
     */
    hrtim_cmp_ad_mode_t      timer_cmp_ad_mode[HRTIM_TIMER_NUM][HRTIM_COMP_NUM];
    /**
     * @brief   Timer deadtimes.
     */
    hrtim_dt_t               deadtime[HRTIM_TIMER_NUM];
    /**
     * @brief   Output set event.
     */
    uint32_t                 set_event[HRTIM_EVENT_NUM][HRTIM_OUTPUT_NUM];
    /**
     * @brief   Output reset event.
     */
    uint32_t                 rst_event[HRTIM_EVENT_NUM][HRTIM_OUTPUT_NUM];
    /**
     * @brief   Callback associated to the timer events or @p NULL.
     */
    hrtim_cb_t               cb[HRTIM_TIMER_NUM];
    /**
     * @brief   Callback associated to the master events or @p NULL.
     */
    hrtim_cb_t               cb_mt;
    /**
     * @brief   Callback associated to the fault events or @p NULL.
     */
    hrtim_cb_t               cb_flt;
    /**
     * @brief   Timer counter reset event.
     */
    uint32_t                 timer_cntr_rst_event[HRTIM_TIMER_NUM];
    /**
     * @brief   Timer preload.
     */
    hrtim_pl_t               timer_preload[HRTIM_TIMER_NUM];
    /**
     * @brief   Master preload.
     */
    hrtim_pl_t               master_preload;
    /**
     * @brief   Master topology mode.
     */
    hrtim_mode_tpg_t         master_mode_tpg;
    /**
     * @brief   ADC trigger.
     */
    hrtim_adc_trigger_cfg_t  adc_trg[HRTIM_ADCTRIG_NUM];
    /**
     * @brief   Timer topology mode.
     */
    hrtim_mode_tpg_t         timer_mode_tpg[HRTIM_TIMER_NUM];
    /**
     * @brief   Timer counter mode.
     */
    hrtim_countmode_t        timer_count_mode[HRTIM_TIMER_NUM];
    /**
     * @brief   Timer update source.
     */
    uint32_t                 timer_update_source[HRTIM_TIMER_NUM];
    /**
     * @brief   Event channel configuration.
     */
    hrtim_eev_cfg_t          eev[HRTIM_EXEVENT_NUM];
    /**
     * @brief   External event counter A configuration.
     */
    hrtim_eev_counter_cfg_t  eev_counter[HRTIM_TIMER_NUM][HRTIM_EXEVENT_NUM];
    /**
     * @brief   External event filtering in timing units configuration.
     */
    hrtim_eev_fltr_cfg_t     timer_eev_filter[HRTIM_TIMER_NUM][HRTIM_EXEVENT_NUM];
    /**
     * @brief   External event sampling clock.
     */
    hrtim_eev_prsc_t  eev_prescaler;
    /**
     * @brief   Dual channel DAC trigger enable flag.
     */
    uint8_t                  timer_dualdac_enable[HRTIM_TIMER_NUM];
    /**
     * @brief   Fault input
     */
    hrtim_fault_cfg_t        fault[HRTIM_FAULT_NUM];
    /**
     * @brief   Fault sampling clock.
     */
    hrtim_fault_prsc_t       fault_prescaler;
    /**
     * @brief   Fault sampling clock.
     */
    hrtim_fault_blnk_cfg_t   fault_blnk[HRTIM_FAULT_NUM];
    /**
     * @brief   Timer output level in FAUTL state.
     */
    hrtim_out_faultstate_t   fault_state[HRTIM_TIMER_NUM][HRTIM_OUTPUT_NUM];
    /**
     * @brief   Timer output level in IDLE state.
     */
    hrtim_out_idlestate_t    idle_state[HRTIM_TIMER_NUM][HRTIM_OUTPUT_NUM];
    /**
     * @brief   Timer output polarity.
     */
    hrtim_out_polarity_t     out_polarity[HRTIM_TIMER_NUM][HRTIM_OUTPUT_NUM];
    /**
     * @brief   Capture 1/2 unit
     */
    hrtim_cpt_unit_cfg_t     cpt_unit[HRTIM_TIMER_NUM];
};

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

IRQ_HANDLER(IRQ_HRTIM1_MT_HANDLER);
IRQ_HANDLER(IRQ_HRTIM1_TA_HANDLER);
IRQ_HANDLER(IRQ_HRTIM1_TB_HANDLER);
IRQ_HANDLER(IRQ_HRTIM1_TC_HANDLER);
IRQ_HANDLER(IRQ_HRTIM1_TD_HANDLER);
IRQ_HANDLER(IRQ_HRTIM1_TE_HANDLER);
IRQ_HANDLER(IRQ_HRTIM1_FLT_HANDLER);
IRQ_HANDLER(IRQ_HRTIM1_TF_HANDLER);
IRQ_HANDLER(IRQ_HRTIM2_MT_HANDLER);
IRQ_HANDLER(IRQ_HRTIM2_TA_HANDLER);
IRQ_HANDLER(IRQ_HRTIM2_TB_HANDLER);
IRQ_HANDLER(IRQ_HRTIM2_TC_HANDLER);
IRQ_HANDLER(IRQ_HRTIM2_TD_HANDLER);
IRQ_HANDLER(IRQ_HRTIM2_TE_HANDLER);
IRQ_HANDLER(IRQ_HRTIM2_FLT_HANDLER);
IRQ_HANDLER(IRQ_HRTIM2_TF_HANDLER);

HRTIM_TypeDef *hrtim_dev_get_reg_ptr(hrtim_driver_t *hdp);
uint32_t hrtim_dev_get_clock(hrtim_driver_t *hdp);
void hrtim_dev_clock_enable(hrtim_driver_t *hdp);
void hrtim_dev_clock_disable(hrtim_driver_t *hdp);
void hrtim_dev_enable_irq(hrtim_driver_t *hdp, uint32_t prio);
void hrtim_dev_disable_irq(hrtim_driver_t *hdp);
void hrtim_dev_calib_procedure(hrtim_driver_t *hdp);

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/*===========================================================================*/
/* Module late inclusions.                                                   */
/*===========================================================================*/

#endif /* _HRTIM_PRIVATE_H_ */

/** @} */
