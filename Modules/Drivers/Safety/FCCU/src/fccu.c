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
 * @file    fccu.c
 * @brief   FCCU driver source file.
 *
 * @addtogroup DRIVERS
 * @addtogroup SAFETY
 * @ingroup DRIVERS
 * @addtogroup FCCU
 * @ingroup SAFETY
 * @{
 */

#include <fccu.h>
#include <fccu_private.h>
#include <osal.h>

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
 * @brief   Rounds up the result of division (num / den).
 *
 * @param[in] num       numerator of division
 * @param[in] den       denominator of division
 *
 * @notapi
 */
__STATIC_INLINE uint8_t fccu_lld_round_up(uint8_t num, uint8_t den) {

    return (((num % den) == 0U) ? (num / den) : ((num / den) + 1U));
}

/**
 * @brief   Unlocks FCCU.
 *
 * @param[out] fdp      pointer to a @p fccu_driver_t structure
 *
 * @notapi
 */
__STATIC_INLINE void fccu_lld_trans_unlock(fccu_driver_t *fdp) {

    REG_SET_FIELD(fdp->fccu->TRANS_LOCK, FCCU_TRANS_LOCK_TRANSKEY, FCCU_TRANS_UNLOCK_KEY);
}

/**
 * @brief   Gets FCCU operation status.
 *
 * @param[out] fdp      pointer to a @p fccu_driver_t structure
 * @return              operation status.
 *
 * @notapi
 */
__STATIC_INLINE uint8_t fccu_lld_get_op_status(fccu_driver_t *fdp) {

    return (uint8_t)REG_READ_FIELD(fdp->fccu->CTRL, FCCU_CTRL_OPS);
}

/**
 * @brief   Sets FCCU in CONFIG state.
 *
 * @param[out] fdp      pointer to a @p fccu_driver_t structure
 *
 * @notapi
 */
static void fccu_lld_set_in_config_state(fccu_driver_t *fdp) {

    uint32_t ctrl;

    ctrl = fdp->fccu->CTRL;
    ctrl &= ~(FCCU_CTRL_OPR_Msk);
    ctrl |= FCCU_CTRL_OPR_OP1;

    REG_SET_FIELD(fdp->fccu->CTRLK, FCCU_CTRLK_CTRLK_VAL, FCCU_CTRLK_OP1_KEY);
    fdp->fccu->CTRL = ctrl;

    while (fccu_lld_get_op_status(fdp) != FCCU_CTRL_OPS_SUCCESS) {

    }
}

/**
 * @brief   Sets FCCU in NORMAL state.
 *
 * @param[out] fdp      pointer to a @p fccu_driver_t structure
 *
 * @notapi
 */
static void fccu_lld_set_in_normal_state(fccu_driver_t *fdp) {

    uint32_t ctrl;

    ctrl = fdp->fccu->CTRL;
    ctrl &= ~(FCCU_CTRL_OPR_Msk);
    ctrl |= FCCU_CTRL_OPR_OP2;

    REG_SET_FIELD(fdp->fccu->CTRLK, FCCU_CTRLK_CTRLK_VAL, FCCU_CTRLK_OP2_KEY);
    fdp->fccu->CTRL = ctrl;

    while (fccu_lld_get_op_status(fdp) != FCCU_CTRL_OPS_SUCCESS) {

    }
}

/**
 * @brief   Gets FCCU finite state machine state.
 *
 * @param[out] fdp      pointer to a @p fccu_driver_t structure
 * @return              FCCU finite state machine state. It can be one of the
 *                      following values:
 *            @arg @ref FCCU_FSM_STATE_NORMAL
 *            @arg @ref FCCU_FSM_STATE_CONFIG
 *            @arg @ref FCCU_FSM_STATE_ALARM
 *            @arg @ref FCCU_FSM_STATE_FAULT
 *
 * @notapi
 */
__STATIC_INLINE fccu_fsm_state_t fccu_lld_get_fsm_state(fccu_driver_t *fdp) {

    uint8_t fsm_state;

    REG_SET_FIELD(fdp->fccu->CTRL, FCCU_CTRL_OPR, FCCU_CTRL_OPR_OP3);

    while (fccu_lld_get_op_status(fdp) != FCCU_CTRL_OPS_SUCCESS) {

    }

    fsm_state = (uint8_t)(REG_READ_FIELD(fdp->fccu->STAT, FCCU_STAT_STATUS));
    if (fsm_state == 0U) {
        return FCCU_FSM_STATE_NORMAL;
    } else if (fsm_state == 1U) {
        return FCCU_FSM_STATE_CONFIG;
    } else if (fsm_state == 2U) {
        return FCCU_FSM_STATE_ALARM;
    } else {
        return FCCU_FSM_STATE_FAULT;
    }
}

/**
 * @brief   Gets FCCU RF Status register.
 *
 * @param[out] fdp      pointer to a @p fccu_driver_t structure
 * @param[in] rf_reg    FCCU RF Status register to be read
 * @return              FCCU RF Status register value.
 *
 * @notapi
 */
__STATIC_INLINE uint32_t fccu_lld_get_rf_status_reg(fccu_driver_t *fdp,
                                                    uint8_t rf_reg) {

    REG_SET_FIELD(fdp->fccu->CTRL, FCCU_CTRL_OPR, FCCU_CTRL_OPR_OP10);

    while (fccu_lld_get_op_status(fdp) != FCCU_CTRL_OPS_SUCCESS) {

    }

    return (uint32_t)(fdp->fccu->RF_S[rf_reg]);
}

/**
 * @brief   Clears status bits in FCCU RF Status register.
 *
 * @param[out] fdp      pointer to a @p fccu_driver_t structure
 * @param[in] rf_reg    FCCU RF Status register to be cleared
 * @param[in] mask      mask with status bits to be cleared ('1' in position i
 *                      means the related status be must be cleared)
 *
 * @notapi
 */
__STATIC_INLINE void fccu_lld_clear_rf_status(fccu_driver_t *fdp,
                                              uint8_t rf_reg, uint32_t mask) {

    do {
        fdp->fccu->RFK = FCCU_RECOVERABLE_FAULT_KEY;
        fdp->fccu->RF_S[rf_reg] = mask;

        while (fccu_lld_get_op_status(fdp) != FCCU_CTRL_OPS_SUCCESS) {

        }
        /* Read fault status register and check if all faults indicated by mask
           have been correctly cleared, otherwise repeat the sequence.*/
    } while (((fccu_lld_get_rf_status_reg(fdp, rf_reg)) & mask)  != 0U);
}

/**
 * @brief   Checks FCCU RF Enable registers are reset to their default value.
 *
 * @param[out] fdp      pointer to a @p fccu_driver_t structure
 * @return              check result ('true' means the RF Enable registers are
 *                      reset, 'false' otherwise.
 *
 * @notapi
 */
__STATIC_INLINE bool fccu_check_rf_e_reset(fccu_driver_t *fdp) {

    uint32_t rf_e_reg_reset[] = FCCU_RF_E_RESET;
    uint8_t i;

    for (i = 0U; i < fccu_lld_round_up(FCCU_CH_NUMBER, 32U); i++) {
        if (fdp->fccu->RF_E[i] != rf_e_reg_reset[i]) {
            return false;
        }
    }
    return true;
}

/**
 * @brief   Resets all FCCU registers to their default values.
 * @note    If FCCU is in CONFIG state and a configuration timeout occurs, all
 *          FCCU registers will return to the default value. So, in order to
 *          reset all FCCU registers, it is enough to move the FCCU in CONFIG
 *          state and wait till the configuration timeout occurs and the FCCU
 *          returns in NORMAL state.
 *
 * @param[out] fdp      pointer to a @p fccu_driver_t structure
 *
 * @notapi
 */
static void fccu_lld_reset(fccu_driver_t *fdp) {

    /* Unlock FCCU.*/
    fccu_lld_trans_unlock(fdp);

    /* Disable configuration timeout interrupt.*/
    fdp->fccu->IRQ_EN = 0x0UL;

    /* Set FCCU in CONFIG state.*/
    fccu_lld_set_in_config_state(fdp);

    do {
        ;
    } while (fccu_lld_get_fsm_state(fdp) != FCCU_FSM_STATE_NORMAL);
}

/**
 * @brief   Resets FCCU parameters.
 *
 * @param[out] fdp      pointer to an @p fccu_driver_t structure
 *
 * @notapi
 */
static void fccu_reset_paramters(fccu_driver_t *fdp) {

    uint8_t i;

    /* Set all driver configuration parameters to default values.*/
    fdp->prio                   = IRQ_MIN_PRIORITY;
    fdp->eout_cfg.is_eout_ar_en = false;
    fdp->eout_cfg.fom           = FCCU_FOM_DUAL_RAIL;
    fdp->eout_cfg.ps            = FCCU_PS_ACTIVE_LOW;
    fdp->eout_cfg.sm            = FCCU_SM_SLOW;
    fdp->eout_cfg.od            = FCCU_OD_PUSH_PULL;
    fdp->config_to              = FCCU_CFG_TO_4096US;
    fdp->is_config_to_irq_en    = false;
    fdp->config_to_irq_cb       = NULL;
    fdp->alarm_to               = 0x0UL;
    fdp->delta_t                = 0x0UL;

    for (i = 0U; i < FCCU_CH_NUMBER; i++) {
        fdp->ch_cfg[i].is_enable          = false;
        fdp->ch_cfg[i].rf_cfg             = FCCU_RF_CONFIG_SW;
        fdp->ch_cfg[i].is_alarm_to_en     = false;
        fdp->ch_cfg[i].is_alarm_to_irq_en = false;
        fdp->ch_cfg[i].alarm_to_irq_cb    = NULL;
        fdp->ch_cfg[i].reaction           = FCCU_REACTION_NO_RESET;
        fdp->ch_cfg[i].is_nmi_en          = false;
        fdp->ch_cfg[i].is_eout_en         = false;
    }
}

/*===========================================================================*/
/* Module exported functions.                                                */
/*===========================================================================*/

void fccu_init(fccu_driver_t *fdp) {

    /* Set pointer to FCCU register block.*/
    fdp->fccu = fccu_dev_get_reg_ptr(fdp);

    /* Reset FCCU parameters.*/
    fccu_reset_paramters(fdp);
}

uint32_t fccu_set_prio(fccu_driver_t *fdp, uint32_t prio) {

    uint32_t prev_prio;

    prev_prio = fdp->prio;
    fdp->prio = prio;

    return prev_prio;
}

void fccu_set_eout_cfg(fccu_driver_t *fdp, bool is_eout_ar_en, fccu_fom_t fom,
                       fccu_ps_t ps, fccu_sm_t sm, fccu_od_t od) {

    fdp->eout_cfg.is_eout_ar_en = is_eout_ar_en;
    fdp->eout_cfg.fom           = fom;
    fdp->eout_cfg.ps            = ps;
    fdp->eout_cfg.sm            = sm;
    fdp->eout_cfg.od            = od;
}

fccu_config_to_t fccu_set_config_to(fccu_driver_t *fdp,
                                    fccu_config_to_t config_to) {

    fccu_config_to_t prev_config_to;

    prev_config_to = fdp->config_to;
    fdp->config_to = config_to;

    return prev_config_to;
}

bool fccu_set_is_config_to_irq_en(fccu_driver_t *fdp, bool enable) {

    bool prev_is_config_to_irq_en;

    prev_is_config_to_irq_en = fdp->is_config_to_irq_en;
    fdp->is_config_to_irq_en = enable;

    return prev_is_config_to_irq_en;
}

uint32_t fccu_set_alarm_to(fccu_driver_t *fdp, uint32_t alarm_to) {

    uint32_t prev_alarm_to;

    prev_alarm_to = fdp->alarm_to;
    fdp->alarm_to = alarm_to;

    return prev_alarm_to;
}

uint32_t fccu_set_delta_t(fccu_driver_t *fdp, uint32_t delta_t) {

    uint32_t prev_delta_t;

    prev_delta_t = fdp->delta_t;
    fdp->delta_t = delta_t;

    return prev_delta_t;
}

void fccu_set_ch_cfg(fccu_driver_t *fdp, uint8_t ch, bool is_enable,
                     fccu_rf_cfg_t rf_cfg, bool is_alarm_to_en,
                     bool is_alarm_to_irq_en, fccu_cb_t alarm_to_irq_cb,
                     fccu_reaction_t reaction, bool is_nmi_en, bool is_eout_en) {

    if (ch < FCCU_CH_NUMBER) {
        fdp->ch_cfg[ch].is_enable          = is_enable;
        fdp->ch_cfg[ch].rf_cfg             = rf_cfg;
        fdp->ch_cfg[ch].is_alarm_to_en     = is_alarm_to_en;
        fdp->ch_cfg[ch].is_alarm_to_irq_en = is_alarm_to_irq_en;
        fdp->ch_cfg[ch].alarm_to_irq_cb    = alarm_to_irq_cb;
        fdp->ch_cfg[ch].reaction           = reaction;
        fdp->ch_cfg[ch].is_nmi_en          = is_nmi_en;
        fdp->ch_cfg[ch].is_eout_en         = is_eout_en;
    }
}

fccu_cb_t fccu_set_config_to_irq_cb(fccu_driver_t *fdp,
                                    fccu_cb_t config_to_irq_cb) {

    fccu_cb_t prev_config_to_irq_cb;

    prev_config_to_irq_cb = fdp->config_to_irq_cb;
    fdp->config_to_irq_cb = config_to_irq_cb;

    return prev_config_to_irq_cb;
}

void fccu_start(fccu_driver_t *fdp) {

    IRQn_Type vector;
    uint8_t ch_reg, ch_pos;
    uint8_t i;

    /* Set prio */
    vector = fccu_dev_get_vector(fdp);
    irq_set_priority(vector, fdp->prio);
    irq_enable(vector);

    /* Unlock FCCU.*/
    fccu_lld_trans_unlock(fdp);

    /* Configure FCCU configuration timeout.*/
    fdp->fccu->CFG_TO = (uint8_t)(fdp->config_to);

    /* Enable/Disable configuration timeout interrupt.*/
    if (fdp->is_config_to_irq_en == true) {
        fdp->fccu->IRQ_EN = 0x1UL;
    } else {
        fdp->fccu->IRQ_EN = 0x0UL;
    }

    /* Set FCCU in CONFIG state.*/
    fccu_lld_set_in_config_state(fdp);

    /* Check FCCU is in CONFIG state.*/
    if (fccu_lld_get_fsm_state(fdp) != FCCU_FSM_STATE_CONFIG) {
        return;
    }

    /* Setup recoverable fault configuration.*/
    for (i = 0U; i < FCCU_CH_NUMBER; i++) {
        /* Calculate RF_CFG register related to FCCU channel.*/
        ch_reg = i / 32U;
        /* Calculate position in RF_CFG register related to FCCU channel.*/
        ch_pos = (i % 32U);

        FCCU_SET_REG_FIELD(fdp->fccu->RF_CFG[ch_reg], FCCU_RFCFG_MASK, ch_pos, fdp->ch_cfg[i].rf_cfg);
    }

    /* Setup recoverable fault state configurations.*/
    for (i = 0U; i < FCCU_CH_NUMBER; i++) {
        /* Calculate RFS register related to FCCU channel.*/
        ch_reg = i / 16U;
        /* Calculate position in RFS register related to FCCU channel.*/
        ch_pos = ((i % 16U) * 2U);

        if (fdp->ch_cfg[i].is_enable == true) {
            FCCU_SET_REG_FIELD(fdp->fccu->RFS_CFG[ch_reg], FCCU_RFSC_MASK, ch_pos, fdp->ch_cfg[i].reaction);
        } else {
            FCCU_SET_REG_FIELD(fdp->fccu->RFS_CFG[ch_reg], FCCU_RFSC_MASK, ch_pos, FCCU_REACTION_NO_RESET);
        }
    }

    /* Enable/Disable recoverable faults.*/
    for (i = 0U; i < FCCU_CH_NUMBER; i++) {
        /* Calculate RF_EN register related to FCCU channel.*/
        ch_reg = i / 32U;
        /* Calculate position in RF_EN register related to FCCU channel.*/
        ch_pos = (i % 32U);

        if (fdp->ch_cfg[i].is_enable == true) {
            FCCU_SET_REG_FIELD(fdp->fccu->RF_E[ch_reg], FCCU_RFE_MASK, ch_pos, FCCU_RFE_ENABLE);
        } else {
            FCCU_SET_REG_FIELD(fdp->fccu->RF_E[ch_reg], FCCU_RFE_MASK, ch_pos, FCCU_RFE_DISABLE);
        }
    }

    /* Configure timeout.*/
    for (i = 0U; i < FCCU_CH_NUMBER; i++) {
        /* Calculate RF_TOE register related to FCCU channel.*/
        ch_reg = i / 32U;
        /* Calculate position in RF_TOE register related to FCCU channel.*/
        ch_pos = (i % 32U);

        if ((fdp->ch_cfg[i].is_enable == true) && (fdp->ch_cfg[i].is_alarm_to_en == true)) {
            FCCU_SET_REG_FIELD(fdp->fccu->RF_TOE[ch_reg], FCCU_RFTOE_MASK, ch_pos, FCCU_RFTOE_ENABLE);
        } else {
            FCCU_SET_REG_FIELD(fdp->fccu->RF_TOE[ch_reg], FCCU_RFTOE_MASK, ch_pos, FCCU_RFTOE_DISABLE);
        }
    }

    /* Set Alarm Timeout.*/
    fdp->fccu->RF_TO = fdp->alarm_to;

    /* Set delta_t value (Tmin = 250us + delta_t).*/
    fdp->fccu->DELTA_T = fdp->delta_t;

    /* Configure alarm interrupt.*/
    for (i = 0U; i < FCCU_CH_NUMBER; i++) {
        /* Calculate IRQ_ALARM_EN register related to FCCU channel.*/
        ch_reg = i / 32U;
        /* Calculate position in IRQ_ALARM_EN register related to FCCU channel.*/
        ch_pos = (i % 32U);

        if ((fdp->ch_cfg[i].is_enable == true) && (fdp->ch_cfg[i].is_alarm_to_irq_en == true)) {
            FCCU_SET_REG_FIELD(fdp->fccu->IRQ_ALARM_EN[ch_reg], FCCU_IRQEN_MASK, ch_pos, FCCU_IRQEN_ENABLE);
        } else {
            FCCU_SET_REG_FIELD(fdp->fccu->IRQ_ALARM_EN[ch_reg], FCCU_IRQEN_MASK, ch_pos, FCCU_IRQEN_DISABLE);
        }
    }

    /* Configure non-maskerable interrupt.*/
    for (i = 0U; i < FCCU_CH_NUMBER; i++) {
        /* Calculate NMI_EN register related to FCCU channel.*/
        ch_reg = i / 32U;
        /* Calculate position in NMI_EN register related to FCCU channel.*/
        ch_pos = (i % 32U);

        if ((fdp->ch_cfg[i].is_enable == true) && (fdp->ch_cfg[i].is_nmi_en == true)) {
            FCCU_SET_REG_FIELD(fdp->fccu->NMI_EN[ch_reg], FCCU_NMIEN_MASK, ch_pos, FCCU_NMIEN_ENABLE);
        } else {
            FCCU_SET_REG_FIELD(fdp->fccu->NMI_EN[ch_reg], FCCU_NMIEN_MASK, ch_pos, FCCU_NMIEN_DISABLE);
        }
    }

    /* Configure error out signaling.*/
    for (i = 0U; i < FCCU_CH_NUMBER; i++) {
        /* Calculate EOUT_SIG_EN register related to FCCU channel.*/
        ch_reg = i / 32U;
        /* Calculate position in EOUT_SIG_EN register related to FCCU channel.*/
        ch_pos = (i % 32U);

        if ((fdp->ch_cfg[i].is_enable == true) && (fdp->ch_cfg[i].is_eout_en == true)) {
            FCCU_SET_REG_FIELD(fdp->fccu->EOUT_SIG_EN[ch_reg], FCCU_EOUTEN_MASK, ch_pos, FCCU_EOUTEN_ENABLE);
        } else {
            FCCU_SET_REG_FIELD(fdp->fccu->EOUT_SIG_EN[ch_reg], FCCU_EOUTEN_MASK, ch_pos, FCCU_EOUTEN_DISABLE);
        }
    }

    /* Configure EOUT protocol parameters.*/
    if (fdp->eout_cfg.is_eout_ar_en == true) {
        REG_SET_FIELD(fdp->fccu->CFG, FCCU_CFG_FOM, (uint8_t)(fdp->eout_cfg.fom));
        REG_SET_FIELD(fdp->fccu->CFG, FCCU_CFG_PS,  (uint8_t)(fdp->eout_cfg.ps));
        REG_SET_FIELD(fdp->fccu->CFG, FCCU_CFG_SM,  (uint8_t)(fdp->eout_cfg.sm));
        REG_SET_FIELD(fdp->fccu->CFG, FCCU_CFG_OD,  (uint8_t)(fdp->eout_cfg.od));
        /* Enable EOUT pins.*/
        REG_SET_FIELD(fdp->fccu->CFG, FCCU_CFG_SET_AFTER_RESET, 1U);
    } else {
        /* Disable EOUT pins.*/
        REG_SET_FIELD(fdp->fccu->CFG, FCCU_CFG_SET_AFTER_RESET, 0U);
    }

    /* Set FCCU in NORMAL state.*/
    fccu_lld_set_in_normal_state(fdp);

    /* Check FCCU is in NORMAL state.*/
    if (fccu_lld_get_fsm_state(fdp) != FCCU_FSM_STATE_NORMAL) {
        return;
    }
}

void fccu_inject_fault(fccu_driver_t *fdp, uint8_t ch) {

    if (ch < FCCU_CH_NUMBER) {
        fdp->fccu->RFF = ch;
    }
}

fccu_status_t fccu_get_status(fccu_driver_t *fdp) {

    fccu_status_t status;
    uint8_t i;

    /* Initialize fault flag.*/
    status.is_fault = false;

    /* Get FCCU finite state machine state.*/
    status.fsm_state = fccu_lld_get_fsm_state(fdp);

    /* Initialize variables in which to store the RF Status register values.*/
    for (i = 0U; i < 4U; i++) {
        status.rf_status_reg[i] = 0UL;
    }

    /* Get FCCR RF Status registers.*/
    for (i = 0U; i < fccu_lld_round_up(FCCU_CH_NUMBER, 32U); i++) {
        status.rf_status_reg[i] = fccu_lld_get_rf_status_reg(fdp, i);
        if (status.rf_status_reg[i] != 0U) {
            status.is_fault = true;
        }
    }

    return status;
}

void fccu_clear_fault(fccu_driver_t *fdp, uint8_t ch) {

    /* Check the FCCU channel is valid.*/
    if (ch >= FCCU_CH_NUMBER) {
        return;
    }

    /* Unlock FCCU.*/
    fccu_lld_trans_unlock(fdp);

    do {
        /* Clear fault related to the specified channel.*/
        fccu_lld_clear_rf_status(fdp, (ch / 32U), (1UL << (ch % 32U)));
    } while (fccu_lld_get_fsm_state(fdp) != FCCU_FSM_STATE_NORMAL);
}

void fccu_clear(fccu_driver_t *fdp) {

    uint8_t i;

    /* Unlock FCCU.*/
    fccu_lld_trans_unlock(fdp);

    /* Clear all RF Status registers.*/
    do {
        for (i = 0U; i < fccu_lld_round_up(FCCU_CH_NUMBER, 32U); i++) {
            fccu_lld_clear_rf_status(fdp, i, 0xFFFFFFFFUL);
        }
    } while (fccu_lld_get_fsm_state(fdp) != FCCU_FSM_STATE_NORMAL);
}

void fccu_reset(fccu_driver_t *fdp) {

    uint8_t i;

    /* Unlock FCCU.*/
    fccu_lld_trans_unlock(fdp);

    if (fccu_lld_get_fsm_state(fdp) == FCCU_FSM_STATE_FAULT) {
        osal_delay_microsec(250U + 10000U);
    }

    /* Clear all RF Status registers.*/
    do {
        for (i = 0U; i < fccu_lld_round_up(FCCU_CH_NUMBER, 32U); i++) {
            fccu_lld_clear_rf_status(fdp, i, 0xFFFFFFFFUL);
        }

        /* Reset FCCU registers to default values.*/
        fccu_lld_reset(fdp);

        /* Verify FCCU RF Enable registers are to default value.*/
        do {
            ;
        } while(fccu_check_rf_e_reset(fdp) != true);
    } while (fccu_lld_get_fsm_state(fdp) != FCCU_FSM_STATE_NORMAL);
}

void fccu_stop(fccu_driver_t *fdp) {

    IRQn_Type vector;
    uint8_t i;
    uint32_t rf_e_reg_reset[] = FCCU_RF_E_RESET;

    /* Set prio */
    vector = fccu_dev_get_vector(fdp);
    irq_disable(vector);

    /* Disable configuration timeout interrupt.*/
    fdp->fccu->IRQ_EN = 0x0UL;

    /* Set FCCU in CONFIG state.*/
    fccu_lld_set_in_config_state(fdp);

    /* Check FCCU is in CONFIG state.*/
    if (fccu_lld_get_fsm_state(fdp) != FCCU_FSM_STATE_CONFIG) {
        return;
    }

    /* Disable all recoverable faults.*/
    for (i = 0U; i < FCCU_CH_NUMBER / 32U; i++) {
        fdp->fccu->RF_E[i] = rf_e_reg_reset[i];
    }

    /* Set FCCU in NORMAL state.*/
    fccu_lld_set_in_normal_state(fdp);

    /* Check FCCU is in NORMAL state.*/
    if (fccu_lld_get_fsm_state(fdp) != FCCU_FSM_STATE_NORMAL) {
        return;
    }
}

void fccu_deinit(fccu_driver_t *fdp) {

    /* Set pointer to FCCU register block to NULL.*/
    fdp->fccu = NULL;

    /* Reset FCCU parameters.*/
    fccu_reset_paramters(fdp);
}

void __fccu_serve_interrupt(fccu_driver_t *fdp) {

    uint32_t rf_status_reg;
    uint32_t rf_toe_reg;
    uint32_t irq_alarm_en;
    uint8_t i, j;

    /* Configuration timeout interrupt management.*/
    if ((fdp->fccu->IRQ_STAT & FCCU_IRQ_STAT_CFG_TO_STAT) == FCCU_IRQ_STAT_CFG_TO_STAT) {
        if (fdp->config_to_irq_cb != NULL) {
            fdp->config_to_irq_cb(fdp);
        }
        /* Clear configuration timeout interrupt.*/
        fdp->fccu->IRQ_STAT = FCCU_IRQ_STAT_CFG_TO_STAT;
    }

    /* Alarm timeout interrupt management.*/
    if ((fdp->fccu->IRQ_STAT & FCCU_IRQ_STAT_ALRM_STAT) == FCCU_IRQ_STAT_ALRM_STAT) {
        for (i = 0U; i < fccu_lld_round_up(FCCU_CH_NUMBER, 32U); i++) {
            rf_status_reg = fccu_lld_get_rf_status_reg(fdp, i);
            rf_toe_reg = fdp->fccu->RF_TOE[i];
            irq_alarm_en = fdp->fccu->IRQ_ALARM_EN[i];
            if (rf_status_reg != 0U) {
                for (j = 0U; j < 32U; j++) {
                    /* If a recovery fault occurs and the related alarm timeout
                       is enabled and an alarm timeout callback is defined, the
                       callback is invoked.*/
                    if (((0x1U & (rf_status_reg >> j)) == 1U)  &&
                        ((0x1U & (rf_toe_reg >> j)) == 1U) &&
                        ((0x1U & (irq_alarm_en >> j)) == 1U) &&
                        (fdp->ch_cfg[(i * 32U + j)].alarm_to_irq_cb != NULL)) {
                        fdp->ch_cfg[(i * 32U + j)].alarm_to_irq_cb(fdp);
                    }
                }
            }
        }
    }
}

/** @} */
