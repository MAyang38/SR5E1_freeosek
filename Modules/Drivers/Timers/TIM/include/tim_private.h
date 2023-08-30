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
 * @file    tim_private.h
 * @brief   TIM driver private header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup TIMERS
 * @ingroup DRIVERS
 * @addtogroup TIM
 * @ingroup TIMERS
 * @{
 */

#ifndef _TIM_PRIVATE_H_
#define _TIM_PRIVATE_H_

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
 * @brief   TIM driver structure.
 */
struct tim_driver {
    /**
     * @brief   Associated TIM unit.
     */
    TIM_TypeDef              *tim;
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
     * @brief   Clock division.
     */
    tim_ckd_t                ckd;
    /**
     * @brief   Interrupt priority.
     */
    uint32_t                 prio;
    /**
     * @brief   Driver number of channels.
     */
    uint8_t                  ch_num;
    /**
     * @brief   Driver Break and Dead-time Register switch.
     */
    bool                     is_bdtr;
    /**
     * @brief   TIM prescaler.
     */
    tim_presc_t              presc;
    /**
     * @brief   Rising edge deadtime [ns].
     * @note    Not available for all driver instances.
     */
    uint32_t                 rdt;
    /**
     * @brief   Falling edge deadtime [ns].
     * @note    Not available for all driver instances.
     */
    uint32_t                 fdt;
    /**
     * @brief   Channels mode.
     */
    tim_mode_t               ch_mode[TIM_MAX_CH_NUM];
    /**
     * @brief   Trigger output.
     */
    tim_trgo_t               trgo;
    /**
     * @brief   Trigger output 2.
     */
    tim_trgo2_t              trgo2;
    /**
     * @brief   Slave mode selection.
     */
    tim_sms_t                sms;
    /**
     * @brief   External trigger selection.
     */
    tim_trgi_t               trgi;
    /**
     * @brief   External trigger filter.
     */
    uint8_t                  etf;
    /**
     * @brief   External trigger prescaler.
     */
    tim_etps_t               etps;
    /**
     * @brief   External trigger polarity.
     */
    tim_etp_t                etp;
    /**
     * @brief   Callback associated to the update or capture/compare events or
     *          @p NULL.
     */
    tim_cb_t                 cb[TIM_CB_OPS_MAX];
};

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

IRQ_HANDLER(IRQ_TIM1_BRK_HANDLER);
IRQ_HANDLER(IRQ_TIM1_UP_HANDLER);
IRQ_HANDLER(IRQ_TIM1_TRGCO_HANDLER);
IRQ_HANDLER(IRQ_TIM1_CC_HANDLER);
IRQ_HANDLER(IRQ_TIM2_HANDLER);
IRQ_HANDLER(IRQ_TIM3_HANDLER);
IRQ_HANDLER(IRQ_TIM4_HANDLER);
IRQ_HANDLER(IRQ_TIM5_HANDLER);
IRQ_HANDLER(IRQ_TIM6_HANDLER);
IRQ_HANDLER(IRQ_TIM7_HANDLER);
IRQ_HANDLER(IRQ_TIM8_BRK_HANDLER);
IRQ_HANDLER(IRQ_TIM8_UP_HANDLER);
IRQ_HANDLER(IRQ_TIM8_TRGCO_HANDLER);
IRQ_HANDLER(IRQ_TIM8_CC_HANDLER);
IRQ_HANDLER(IRQ_TIM15_HANDLER);
IRQ_HANDLER(IRQ_TIM16_HANDLER);

TIM_TypeDef *tim_dev_get_reg_ptr(tim_driver_t *tdp);
bool tim_dev_is_bdtr(tim_driver_t *tdp);
uint8_t tim_dev_get_ch_num(tim_driver_t *tdp);
uint32_t tim_dev_get_clock(tim_driver_t *tdp);
void tim_dev_clock_enable(tim_driver_t *tdp);
void tim_dev_clock_disable(tim_driver_t *tdp);
uint8_t tim_dev_get_rdtg(tim_driver_t *tdp);
uint8_t tim_dev_get_fdtg(tim_driver_t *tdp);
void tim_dev_enable_irq(tim_driver_t *tdp, uint32_t prio);
void tim_dev_disable_irq(tim_driver_t *tdp);

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/*===========================================================================*/
/* Module late inclusions.                                                   */
/*===========================================================================*/

#endif /* _TIM_PRIVATE_H_ */

/** @} */

