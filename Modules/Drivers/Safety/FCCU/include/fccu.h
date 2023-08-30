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
 * @file    fccu.h
 * @brief   FCCU driver header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup SAFETY
 * @ingroup DRIVERS
 * @addtogroup FCCU
 * @ingroup SAFETY
 * @{
 */

#ifndef _FCCU_H_
#define _FCCU_H_

#include <typedefs.h>

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

/**
 * @name    FCCU Transition Unlocking Key
 * @{
 */
#define FCCU_TRANS_UNLOCK_KEY               0xBCU
/** @} */

/**
 * @name    Number of FCCU channels
 * @{
 */
#define FCCU_CH_NUMBER                      82U
/** @} */

/**
 * @name    FCCU RF Enable registers reset values
 * @{
 */
#define FCCU_RF_E_RESET                     {0x00000120UL, 0x00000000UL, 0x00000000UL, 0x00000000UL}
/** @} */

/*===========================================================================*/
/* Module pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/**
 * @name    FCCU Control Register - Operation status definitions
 * @{
 */
#define FCCU_CTRL_OPS_IDLE                  0U   /**<  Operation status = Idle.        */
#define FCCU_CTRL_OPS_PROGRESS              1U   /**<  Operation status = In progress. */
#define FCCU_CTRL_OPS_ABORTED               2U   /**<  Operation status = Aborted.     */
#define FCCU_CTRL_OPS_SUCCESS               3U   /**<  Operation status = Successful.  */
/** @} */

/**
 * @name    FCCU Control Register - Operation definitions
 * @{
 */
#define FCCU_CTRL_OPR_OP0                   0U   /**<  No operation.                                                          */
#define FCCU_CTRL_OPR_OP1                   1U   /**<  Set the FCCU into the CONFIG state.                                    */
#define FCCU_CTRL_OPR_OP2                   2U   /**<  Set the FCCU into the NORMAL state.                                    */
#define FCCU_CTRL_OPR_OP3                   3U   /**<  Read the FCCU state.                                                   */
#define FCCU_CTRL_OPR_OP4                   4U   /**<  Read the FCCU frozen status flags (refer to the N2AF_STATUS register). */
#define FCCU_CTRL_OPR_OP5                   5U   /**<  Read the FCCU frozen status flags (refer to the A2FF_STATUS register). */
#define FCCU_CTRL_OPR_OP6                   6U   /**<  Read the FCCU frozen status flags (refer to the N2FF_STATUS register). */
#define FCCU_CTRL_OPR_OP7                   7U   /**<  Read the FCCU frozen status flags (refer to the F2A_STATUS register).  */
#define FCCU_CTRL_OPR_OP10                  10U  /**<  Read the RF status register.                                           */
#define FCCU_CTRL_OPR_OP12                  12U  /**<  RF status clear operation in progress.                                 */
#define FCCU_CTRL_OPR_OP13                  13U  /**<  Clear the freeze status registers.                                     */
#define FCCU_CTRL_OPR_OP14                  14U  /**<  CONFIG to NORMAL FCCU state (configuration timeout) in progress.       */
#define FCCU_CTRL_OPR_OP15                  15U  /**<  Clear the operation status.                                            */
#define FCCU_CTRL_OPR_OP17                  17U  /**<  Read the ALARM timer.                                                  */
#define FCCU_CTRL_OPR_OP19                  19U  /**<  Read the CFG timer.                                                    */
#define FCCU_CTRL_OPR_OP20                  20U  /**<  Read the Error Pin low counter value.                                  */
/** @} */

/**
 * @name    FCCU Control Key Register - Key definitions
 * @{
 */
#define FCCU_CTRLK_OP1_KEY                  0x913756AFUL   /**<  Key for the operation OP1 */
#define FCCU_CTRLK_OP2_KEY                  0x825A132BUL   /**<  Key for the operation OP2 */
/** @} */

/**
 * @name    FCCU RF Configuration Registers parameters
 * @{
 */
#define FCCU_RFCFG_MASK                     0x1U      /**<  Recoverable fault configuration mask */
/** @} */

/**
 * @name    FCCU RFS Configuration Registers parameters
 * @{
 */
#define FCCU_RFSC_MASK                      0x3U      /**<  Recoverable fault state configuration mask */
/** @} */

/**
 * @name    FCCU Recoverable Fault Key Register parameters
 * @{
 */
#define FCCU_RECOVERABLE_FAULT_KEY          0xAB3498FEUL   /**<  Recoverable fault key */
/** @} */

/**
 * @name    FCCU RF Enable Registers parameters
 * @{
 */
#define FCCU_RFE_MASK                       0x1U      /**<  Recoverable fault enable mask */
#define FCCU_RFE_DISABLE                    0x0U      /**<  Recoverable fault disable     */
#define FCCU_RFE_ENABLE                     0x1U      /**<  Recoverable fault enable      */
/** @} */

/**
 * @name    FCCU RF Timeout Enable Registers parameters
 * @{
 */
#define FCCU_RFTOE_MASK                     0x1U      /**<  Fault timeout enable mask */
#define FCCU_RFTOE_DISABLE                  0x0U      /**<  Fault timeout disable     */
#define FCCU_RFTOE_ENABLE                   0x1U      /**<  Fault timeout enable      */
/** @} */

/**
 * @name    FCCU IRQ Alarm Enable Registers parameters
 * @{
 */
#define FCCU_IRQEN_MASK                     0x1U      /**<  IRQ alarm enable mask */
#define FCCU_IRQEN_DISABLE                  0x0U      /**<  IRQ alarm disable     */
#define FCCU_IRQEN_ENABLE                   0x1U      /**<  IRQ alarm enable      */
/** @} */

/**
 * @name    FCCU NMI Enable register Registers parameters
 * @{
 */
#define FCCU_NMIEN_MASK                     0x1U      /**<  NMI enable mask */
#define FCCU_NMIEN_DISABLE                  0x0U      /**<  NMI disable     */
#define FCCU_NMIEN_ENABLE                   0x1U      /**<  NMI enable      */
/** @} */

/**
 * @name    FCCU NMI Enable register Registers parameters
 * @{
 */
#define FCCU_EOUTEN_MASK                    0x1U      /**<  EOUT signaling enable mask */
#define FCCU_EOUTEN_DISABLE                 0x0U      /**<  EOUT signaling disable     */
#define FCCU_EOUTEN_ENABLE                  0x1U      /**<  EOUT signaling enable      */
/** @} */

/*===========================================================================*/
/* Module data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Type of an FCCU driver.
 */
typedef struct fccu_driver fccu_driver_t;

/**
 * @enum fccu_fsm_state_t
 * FCCU finite state machine states.
 */
typedef enum {
    FCCU_FSM_STATE_NORMAL = 0U,      /**<  FCCU FSM in NORMAL state */
    FCCU_FSM_STATE_CONFIG = 1U,      /**<  FCCU FSM in CONFIG state */
    FCCU_FSM_STATE_ALARM = 2U,       /**<  FCCU FSM in ALARM  state */
    FCCU_FSM_STATE_FAULT = 3U        /**<  FCCU FSM in FAULT  state */
} fccu_fsm_state_t;

/**
 * @enum fccu_rf_cfg_t
 * FCCU supported recoverable fault configurations.
 */
typedef enum {
    FCCU_RF_CONFIG_HW = 0U,  /**< Hardware recoverable fault */
    FCCU_RF_CONFIG_SW = 1U   /**< Software recoverable fault */
} fccu_rf_cfg_t;

/**
 * @enum fccu_reaction_t
 * FCCU supported internal recoverable fault reactions.
 */
typedef enum {
    FCCU_REACTION_NO_RESET = 0U,            /**< No reset reaction                    */
    FCCU_REACTION_SHORT_FUNCTIONAL = 1U,    /**< Short functional reset request pulse */
    FCCU_REACTION_LONG_FUNCTIONAL = 2U      /**< Long functional reset request pulse  */
} fccu_reaction_t;

/**
 * @enum fccu_fom_t
 * FCCU supported fault output modes.
 */
typedef enum {
    FCCU_FOM_DUAL_RAIL = 0U,      /**< Fault Output Mode = Dual Rail (default state) */
    FCCU_FOM_TIME_SWITCHING = 1U, /**< Fault Output Mode = Time Switching)           */
    FCCU_FOM_BI_STABLE = 2U       /**< Fault Output Mode = Bi-Stable                 */
} fccu_fom_t;

/**
 * @enum fccu_ps_t
 * FCCU supported polarity selections.
 */
typedef enum {
    FCCU_PS_ACTIVE_LOW = 0U,      /**< Polarity Selection = Active Low  */
    FCCU_PS_ACTIVE_HIGH = 1U      /**< Polarity Selection = Active High */
} fccu_ps_t;

/**
 * @enum fccu_sm_t
 * FCCU supported switching modes.
 */
typedef enum {
    FCCU_SM_SLOW = 0U,       /**< Switching Mode = Slow */
    FCCU_SM_FAST = 1U        /**< Switching Mode = Fast */
} fccu_sm_t;

/**
 * @enum fccu_od_t
 * FCCU supported EOUT pin modes.
 */
typedef enum {
    FCCU_OD_PUSH_PULL = 0U,       /**< EOUT Pin Modes = Push Pull  */
    FCCU_OD_OPEN_DRAIN = 1U       /**< EOUT Pin Modes = Open Drain */
} fccu_od_t;

/**
 * @enum fccu_config_to_t
 * FCCU configuration timeout supported values.
 */
typedef enum {
    FCCU_CFG_TO_64US = 0U,        /**< Configuration Timeout = 64us    */
    FCCU_CFG_TO_128US = 1U,       /**< Configuration Timeout = 128us   */
    FCCU_CFG_TO_256US = 2U,       /**< Configuration Timeout = 256us   */
    FCCU_CFG_TO_512US = 3U,       /**< Configuration Timeout = 512us   */
    FCCU_CFG_TO_1024US = 4U,      /**< Configuration Timeout = 1.024ms */
    FCCU_CFG_TO_2048US = 5U,      /**< Configuration Timeout = 2.048ms */
    FCCU_CFG_TO_4096US = 6U,      /**< Configuration Timeout = 4.096ms */
    FCCU_CFG_TO_8192US = 7U       /**< Configuration Timeout = 8.192ms */
} fccu_config_to_t;

/**
 * @brief   Type of a FCCU callback.
 *
 * @param[in] fdp       pointer to the @p fccu_driver_t object
 */
typedef void (*fccu_cb_t)(fccu_driver_t *cdp);

/**
 * @enum fccu_eout_cfg_t
 * FCCU EOUT configuration type.
 */
typedef struct {
    /**
     * @brief   EOUT pin after reset enable flag ('true' means the EOUT pins
     *          are enabled after the reset, 'false' otherwise).
     */
    bool                     is_eout_ar_en;
    /**
     * @brief  Fault output mode selection.
     */
    fccu_fom_t               fom;
    /**
     * @brief  Polarity selection.
     */
    fccu_ps_t                ps;
    /**
     * @brief  Switching mode.
     */
    fccu_sm_t                sm;
    /**
     * @brief  Open drain.
     */
    fccu_od_t                od;
} fccu_eout_cfg_t;

/**
 * @enum fccu_ch_cfg_t
 * FCCU channel configuration type.
 */
typedef struct {
    /**
     * @brief   Channel enable flag ('true' means the channel is enabled,
     *          'false' otherwise).
     */
    bool                     is_enable;
    /**
     * @brief    Recoverable fault configuration (HW or SW).
     */
    fccu_rf_cfg_t            rf_cfg;
    /**
     * @brief   Alarm timeout enable flag ('true' means the alarm timeout is
     *          enabled, 'false' otherwise).
     */
    bool                     is_alarm_to_en;
    /**
     * @brief   Alarm timeout interrupt enable flag ('true' means the alarm
     *          timeout interrupt is enabled, 'false' otherwise).
     */
    bool                     is_alarm_to_irq_en;
    /**
     * @brief    Alarm timeout interrupt callback.
     */
    fccu_cb_t                alarm_to_irq_cb;
    /**
     * @brief   Internal recoverable fault reaction.
     */
    fccu_reaction_t          reaction;
    /**
     * @brief   Non-Maskerable Interrupt enable flag ('true' means the NMI is
     *          enabled, 'false' otherwise).
     */
    bool                     is_nmi_en;
    /**
     * @brief   Error out signaling enable flag ('true' means the error out
     *          signaling is enabled, 'false' otherwise).
     */
    bool                     is_eout_en;
} fccu_ch_cfg_t;

/**
 * @enum fccu_status_t
 * FCCU status type.
 */
typedef struct {
    /**
     * @brief  FCCU fault flag ('true' means a fault is occurred, 'false'
     *         otherwise).
     */
    bool                     is_fault;
    /**
     * @brief  FCCU finite state machine status.
     */
    fccu_fsm_state_t         fsm_state;
    /**
     * @brief  FCCU RF Status register values.
     */
    uint32_t                 rf_status_reg[4U];
} fccu_status_t;

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/**
 * @brief   Updates FCCU register field
 * @details This macro updates a field in a 32-bit register to a specified
 *          value.
 *
 * @param[in] _regp_    pointer to register contains the field to be updated
 * @param[in] _mask_    mask of field to be updated
 * @param[in] _pos_     position of field to be updated
 * @param[in] _value_   value to be updated
 *
 * @notapi
 */
#define FCCU_SET_REG_FIELD(_reg_, _mask_, _pos_, _val_)                        \
    ((_reg_) = (((uint32_t)(_reg_) & ~((uint32_t)(_mask_) << (_pos_))) | ((uint32_t)(_val_) << (_pos_))))

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

/* Export driver modules.*/
#include <fccu_instances.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Initializes FCCU instance.
 *
 * @param[out] fdp      pointer to a @p fccu_driver_t structure
 *
 * @api
 */
void fccu_init(fccu_driver_t *fdp);

/**
 * @brief   Configures FCCU interrupt priority.
 * @note    This configuration becomes effective after fccu_start.
 *
 * @param[out] fdp      pointer to a @p fccu_driver_t structure
 * @param[in] prio      interrupt priority to be configured
 * @return              previous interrupt priority.
 *
 * @api
 */
uint32_t fccu_set_prio(fccu_driver_t *fdp, uint32_t prio);

/**
 * @brief   Configures EOUT protocol parameters.
 * @note    This configuration becomes effective after fccu_start.
 *
 * @param[out] fdp           pointer to a @p fccu_driver_t structure
 * @param[in] is_eout_ar_en  enable EOUT pins after reset flag ('true' means
 *                           EOUT pins are enabled, 'false' otherwise)
 * @param[in] fom            fault output mode selection. It can be one of the
 *                           following values:
 *                 @arg @ref FCCU_FOM_DUAL_RAIL
 *                 @arg @ref FCCU_FOM_TIME_SWITCHING
 *                 @arg @ref FCCU_FOM_BI_STABLE
 * @param[in] ps             polarity selection. It can be one of the following
 *                           values:
 *                 @arg @ref FCCU_PS_ACTIVE_LOW
 *                 @arg @ref FCCU_PS_ACTIVE_HIGH
 * @param[in] sm             switching mode. It can be one of the following
 *                           values:
 *                 @arg @ref FCCU_SM_SLOW
 *                 @arg @ref FCCU_SM_FAST
 * @param[in] od             EOUT pin mode. It can be one of the following
 *                           values:
 *                 @arg @ref FCCU_OD_PUSH_PULL
 *                 @arg @ref FCCU_OD_OPEN_DRAIN
 *
 * @api
 */
void fccu_set_eout_cfg(fccu_driver_t *fdp, bool is_eout_ar_en, fccu_fom_t fom,
                       fccu_ps_t ps, fccu_sm_t sm, fccu_od_t od);

/**
 * @brief   Configures FCCU configuration timeout.
 * @note    This configuration becomes effective after fccu_start.
 *
 * @param[out] fdp      pointer to a @p fccu_driver_t structure
 * @param[in] config_to configuration timeout to be set. It can be one of the
 *                      following values:
 *            @arg @ref FCCU_CFG_TO_64US
 *            @arg @ref FCCU_CFG_TO_128US
 *            @arg @ref FCCU_CFG_TO_256US
 *            @arg @ref FCCU_CFG_TO_512US
 *            @arg @ref FCCU_CFG_TO_1024US
 *            @arg @ref FCCU_CFG_TO_2048US
 *            @arg @ref FCCU_CFG_TO_4096US
 *            @arg @ref FCCU_CFG_TO_8192US
 * @return              previous configuration timeout.
 *
 * @api
 */
fccu_config_to_t fccu_set_config_to(fccu_driver_t *fdp,
                                    fccu_config_to_t config_to);

/**
 * @brief   Enables/Disables FCCU configuration timeout interrupt.
 * @note    This configuration becomes effective after fccu_start.
 *
 * @param[out] fdp      pointer to a @p fccu_driver_t structure
 * @param[in] enable    configuration timeout interrupt enable status ('true'
 *                      means the configuration timeout interrupt is eanbled,
 *                      'false' otherwise)
 * @return              previous configuration timeout interrupt enable status.
 *
 * @api
 */
bool fccu_set_is_config_to_irq_en(fccu_driver_t *fdp, bool enable);

/**
 * @brief   Configures FCCU alarm timeout.
 * @note    This configuration becomes effective after fccu_start.
 *
 * @param[out] fdp      pointer to a @p fccu_driver_t structure
 * @param[in] alarm_to  alarm timeout to be set
 * @return              previous alarm timeout.
 *
 * @api
 */
uint32_t fccu_set_alarm_to(fccu_driver_t *fdp, uint32_t alarm_to);

/**
 * @brief   Configures FCCU Delta_T (in microseconds).
 * @note    This configuration becomes effective after fccu_start.
 * @note    Delta_T maximum value can be 10000us (10ms)
 *
 * @param[out] fdp      pointer to a @p fccu_driver_t structure
 * @param[in] delta_t   delta_t to be set
 * @return              previous delta_t.
 *
 * @api
 */
uint32_t fccu_set_delta_t(fccu_driver_t *fdp, uint32_t delta_t);

/**
 * @brief   Configures FCCU channel parameters.
 * @note    This configuration becomes effective after fccu_start.
 *
 * @param[out] fdp                pointer to a @p fccu_driver_t structure
 * @param[in] ch                  channel to be configured. Its value is in the
 *                                range [0:FCCU_CH_NUMBER-1]
 * @param[in] is_enable           channel enable flag ('true' means the channel
 *                                is enabled, 'false' otherwise
 * @param[in] rf_cfg              recoverable fault configuration. It can be
 *                                one of the following values:
 *                      @arg @ref FCCU_RF_CONFIG_HW
 *                      @arg @ref FCCU_RF_CONFIG_SW
 * @param[in] is_alarm_to_en      alarm timeout enable flag ('true' means alarm
 *                                timeout is eanbled, 'false' otherwise)
 * @param[in] is_alarm_to_irq_en  alarm timeout interrupt enable flag ('true'
 *                                means alarm timeout interrupt is enabled,
 *                                'false' otherwise)
 * @param[in] alarm_to_irq_cb     alarm timeout interrupt callback
 * @param[in] reaction            internal recoverable fault reaction. It can
 *                                be one of the following values:
 *                      @arg @ref FCCU_REACTION_NO_RESET
 *                      @arg @ref FCCU_REACTION_SHORT_FUNCTIONAL
 *                      @arg @ref FCCU_REACTION_LONG_FUNCTIONAL
 * @param[in] is_nmi_en           non-maskerable Interrupt enable flag ('true'
 *                                means NMI is enabled, 'false' otherwise)
 * @param[in] is_eout_en          error out signaling enable flag ('true' means
 *                                error out signaling is enabled, 'false'
 *                                otherwise
 *
 * @api
 */
void fccu_set_ch_cfg(fccu_driver_t *fdp, uint8_t ch, bool is_enable,
                     fccu_rf_cfg_t rf_cfg, bool is_alarm_to_en,
                     bool is_alarm_to_irq_en, fccu_cb_t alarm_to_irq_cb,
                     fccu_reaction_t reaction, bool is_nmi_en, bool is_eout_en);

/**
 * @brief   Configures configuration timeout interrupt callback.
 * @note    This configuration becomes effective after can_start.
 *
 * @param[out] fdp      pointer to a @p fccu_driver_t structure
 * @param[in] cb        pointer to the callback function.
 * @return              pointer to the previous callback function.
 *
 * @api
 */
fccu_cb_t fccu_set_config_to_irq_cb(fccu_driver_t *fdp,
                                    fccu_cb_t config_to_irq_cb);

/**
 * @brief   Starts a FCCU instance.
 *
 * @param[in] fdp       pointer to a @p fccu_driver_t structure
 *
 * @api
 */
void fccu_start(fccu_driver_t *fdp);

/**
 * @brief   Injects a FCCU fault on a specified channel.
 * @note    This function is intended to debug purposes.
 *
 * @param[in] fdp       pointer to a @p fccu_driver_t structure
 * @param[in] ch        channel on which to inject the fault. Its value is in
 *                      the range [0:FCCU_CH_NUMBER-1]
 *
 * @api
 */
void fccu_inject_fault(fccu_driver_t *fdp, uint8_t ch);

/**
 * @brief   Return FCCU status.
 *
 * @param[in] fdp       pointer to a @p fccu_driver_t structure
 * @return              FCCU status.
 *
 * @api
 */
fccu_status_t fccu_get_status(fccu_driver_t *fdp);

/**
 * @brief   Clears FCCU fault related to a specific channel.
 *
 * @param[in] fdp       pointer to a @p fccu_driver_t structure
 * @param[in] ch        channel related to fault to clear. Its value is in the
 *                      range [0:FCCU_CH_NUMBER-1]
 *
 * @api
 */
void fccu_clear_fault(fccu_driver_t *fdp, uint8_t ch);

/**
 * @brief   Clears all FCCU faults.
 *
 * @param[in] fdp       pointer to a @p fccu_driver_t structure
 *
 * @api
 */
void fccu_clear(fccu_driver_t *fdp);

/**
 * @brief   Resets FCCU.
 * @note    This function must be invoked after a functional reset of the system
 *          arising out of reset request from FCCU or other sources, before to
 *          reconfigure the FCCU.
 *
 * @param[in] fdp       pointer to a @p fccu_driver_t structure
 *
 * @api
 */
void fccu_reset(fccu_driver_t *fdp);

/**
 * @brief   Stops the FCCU instance.
 *
 * @param[in] fdp       pointer to an @p fccu_driver_t structure
 *
 * @api
 */
void fccu_stop(fccu_driver_t *fdp);

/**
 * @brief   Deinitializes the FCCU instance.
 *
 * @param[out] fdp      pointer to a @p fccu_driver_t structure
 *
 * @api
 */
void fccu_deinit(fccu_driver_t *fdp);

/**
 * @brief   Serves a FCCU interrupt.
 * @note    Not an API, used internally.
 *
 * @param[in] fdp       pointer to an @p fccu_driver_t structure
 *
 * @isr
 */
void __fccu_serve_interrupt(fccu_driver_t *fdp);

#ifdef __cplusplus
}
#endif

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/*===========================================================================*/
/* Module late inclusions.                                                   */
/*===========================================================================*/

#endif /* _FCCU_H_ */

/** @} */
