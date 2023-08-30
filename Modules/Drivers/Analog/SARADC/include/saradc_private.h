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
 * @file    saradc_private.h
 * @brief   ADC driver private header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup ANALOG
 * @ingroup DRIVERS
 * @addtogroup ADC
 * @ingroup ANALOG
 * @{
 */

#ifndef _SARADC_PRIVATE_H_
#define _SARADC_PRIVATE_H_

#include <dma.h>

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
 * @brief   ADC driver structure.
 * @note    This structure is internal to the ADC driver.
 */
struct adc_driver {
    /**
     * @brief   Pointer to ADC registers block.
     */
    ADC_TypeDef              *adc;
    /**
     * @brief   Pointer to ADC Common registers block.
     */
    ADC_Common_TypeDef       *adc_common;
    /**
     * @brief   ADC Clock value.
     */
    uint32_t                 clock;
    /**
     * @brief   ADC clock mode.
     */
    adc_clk_mode_t           clk_mode;
    /**
     * @brief   ADC clock prescaler.
     */
    adc_clk_presc_t          presc;
    /**
     * @brief   Data resolution.
     */
    adc_data_res_t           data_res;
    /**
     * @brief   ADC interrupt priority.
     */
    uint32_t                 prio;
    /**
     * @brief   ADC interrupt enable flag (true by default).
     */
    bool                     is_interrupt_en;
    /* Regular conversion parameters.*/
    /**
     * @brief   DMA configuration.
     */
    adc_dma_conf_t           *dma_conf;
    /**
     * @brief   Allocated DMA descriptor.
     * @note    DMA is used only for regular conversions.
     */
    const dma_descriptor_t   *dma_descriptor;
    /**
     * @brief   Regular conversion mode (continuous or single conversion).
     * @note    Only for regular conversions.
     */
    adc_reg_mode_t           reg_mode;
    /**
     * @brief   Regualar conversions external trigger.
     */
    uint32_t                 reg_ext;
    /**
     * @brief   Regualar conversions external trigger polarity.
     */
    adc_ext_pol_t            reg_ext_pol;
    /**
     * @brief   Number of the analog channels of regular conversion.
     * @note    It must be in the range [0:ADC_MAX_REG_SEQ_LEN]; '0' means
     *          regular conversions are disabled.
     */
    uint8_t                  n_reg_channels;
    /**
     * @brief   Regular conversion sequence.
     * @note    It is a vector of n_reg_channels samples, that specifies the
     *          list of channels in the desired order.
     */
    uint8_t                  *reg_seq;
    /**
     * @brief   Pointer to the ADC samples buffer for regular conversions.
     * @note    It is a vector of n_reg_channels samples.
     */
    adc_sample_t             *reg_buffer;
    /* Injeced conversion parameters.*/
    /**
     * @brief   Injected conversions external trigger.
     */
    uint32_t                 inj_ext;
    /**
     * @brief   Injected conversions external trigger polarity.
     */
    adc_ext_pol_t            inj_ext_pol;
    /**
     * @brief   Number of the analog channels of injected conversion.
     * @note    It must be in the range [0:ADC_MAX_INJ_SEQ_LEN]. '0' means
     *          injected conversions are disabled.
     */
    uint32_t                 n_inj_channels;
    /**
     * @brief   Injected conversion sequence.
     * @note    It is a vector of n_inj_channels samples, that specifies the
     *          list of channels in the desired order.
     */
    uint8_t                  *inj_seq;
    /**
     * @brief   Pointer to the ADC samples buffer for injected conversions.
     * @note    It is a vector of n_inj_channels samples.
     */
    adc_sample_t             *inj_buffer;
    /**
     * @brief   Channel sample times.
     */
    adc_smp_time_t           smp_time[ADC_CH_NUM];
    /**
     * @brief   Analog watchdog thresholds.
     */
    uint32_t                 aw_tr[ADC_WATCHDOG_NUM];
    /**
     * @brief   Channel differential mode selection mask.
     * @note    This mask allows to configure the ADC channels in single-ended
     *          mode or in differential mode. A '0' in the position i means the
     *          channel i is configured in single ended mode, a '1' in the
     *          position i means the channel i is configured in differential
     *          mode.
     */
    uint16_t                 dif_mask;
    /**
     * @brief   Pointers to ADC normal operation callback functions.
     * @note    Set to @p NULL if not required.
     */
    adc_cb_t                 op_cb[ADC_OP_MAX];
    /**
     * @brief   Pointers to ADC error callback functions.
     * @note    Set to @p NULL if not required.
     */
    adc_err_cb_t             err_cb[ADC_ERR_MAX];
};

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

IRQ_HANDLER(IRQ_ADC1_HANDLER);
IRQ_HANDLER(IRQ_ADC2_HANDLER);
IRQ_HANDLER(IRQ_ADC3_HANDLER);
IRQ_HANDLER(IRQ_ADC4_HANDLER);
IRQ_HANDLER(IRQ_ADC5_HANDLER);

ADC_TypeDef *adc_dev_get_reg_ptr(adc_driver_t *adp);
ADC_Common_TypeDef *adc_common_dev_get_reg_ptr(adc_driver_t *adp);
uint32_t adc_dev_get_clock(adc_driver_t *adp);
void adc_dev_clock_enable(adc_driver_t *adp);
void adc_dev_clock_disable(adc_driver_t *adp);
uint32_t adc_dev_get_dma_trigger(adc_driver_t *adp);
IRQn_Type adc_dev_get_vector(adc_driver_t *adp) ;

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/*===========================================================================*/
/* Module late inclusions.                                                   */
/*===========================================================================*/

#endif /* _SARADC_PRIVATE_H_ */

/** @} */
