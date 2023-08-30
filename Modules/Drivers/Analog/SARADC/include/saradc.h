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
 * @file    saradc.h
 * @brief   ADC driver header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup ANALOG
 * @ingroup DRIVERS
 * @addtogroup ADC
 * @ingroup ANALOG
 * @{
 */

#ifndef _SARADC_H_
#define _SARADC_H_

#include <typedefs.h>

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

/**
 * @name    ADC number of channels [0:18]
 * @{
 */
#define ADC_CH_NUM                          19U
/** @} */

/**
 * @name    ADC maximum number of conversions in a regular conversion sequence
 * @{
 */
#define ADC_MAX_REG_SEQ_LEN                 16U
/** @} */

/**
 * @name    ADC maximum number of conversions in an injected conversion sequence
 * @{
 */
#define ADC_MAX_INJ_SEQ_LEN                 4U
/** @} */

/**
 * @name    ADC number of analog watchdogs
 * @{
 */
#define ADC_WATCHDOG_NUM                    3U
/** @} */

/**
 * @name    ADC analog channels
 * @{
 */
#define ADC_CH_IN0                          0U
#define ADC_CH_IN1                          1U
#define ADC_CH_IN2                          2U
#define ADC_CH_IN3                          3U
#define ADC_CH_IN4                          4U
#define ADC_CH_IN5                          5U
#define ADC_CH_IN6                          6U
#define ADC_CH_IN7                          7U
#define ADC_CH_IN8                          8U
#define ADC_CH_IN9                          9U
#define ADC_CH_IN10                         10U
#define ADC_CH_IN11                         11U
#define ADC_CH_IN12                         12U
#define ADC_CH_IN13                         13U
#define ADC_CH_IN14                         14U
#define ADC_CH_IN15                         15U
#define ADC_CH_IN16                         16U
#define ADC_CH_IN17                         17U
#define ADC_CH_IN18                         18U
/** @} */

/**
 * @brief   ADC Regulator Startup Time (us)
 */
#define ADCVREG_STUP_TIME_US                10U

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
 * @brief   Type of an ADC driver.
 */
typedef struct adc_driver adc_driver_t;

/**
 * @brief   Type of an ADC sample.
 */
typedef uint16_t adc_sample_t;

/**
 * @enum adc_clk_mode_t
 * ADC clock mode configuration.
 */
typedef enum {
    ADC_CLK_MODE_ADCCLK = 0,           /**< ADC clock              */
    ADC_CLK_MODE_AHB_DIV2 = 2,         /**< AHB clock divided by 2 */
    ADC_CLK_MODE_AHB_DIV4 = 4,         /**< AHB clock divided by 4 */
} adc_clk_mode_t;

/**
 * @enum adc_clk_presc_t
 * ADC clock prescaler configuration.
 */
typedef enum {
    ADC_CLK_PRESC_DIV_1,               /**< Input ADC clock not divided    */
    ADC_CLK_PRESC_DIV_2,               /**< Input ADC clock divided by 2   */
    ADC_CLK_PRESC_DIV_4,               /**< Input ADC clock divided by 4   */
    ADC_CLK_PRESC_DIV_6,               /**< Input ADC clock divided by 6   */
    ADC_CLK_PRESC_DIV_8,               /**< Input ADC clock divided by 8   */
    ADC_CLK_PRESC_DIV_10,              /**< Input ADC clock divided by 10  */
    ADC_CLK_PRESC_DIV_12,              /**< Input ADC clock divided by 12  */
    ADC_CLK_PRESC_DIV_16,              /**< Input ADC clock divided by 16  */
    ADC_CLK_PRESC_DIV_32,              /**< Input ADC clock divided by 32  */
    ADC_CLK_PRESC_DIV_64,              /**< Input ADC clock divided by 64  */
    ADC_CLK_PRESC_DIV_128,             /**< Input ADC clock divided by 128 */
    ADC_CLK_PRESC_DIV_256,             /**< Input ADC clock divided by 256 */
} adc_clk_presc_t;

/**
 * @enum adc_data_res_t
 * ADC data resolution configuration.
 */
typedef enum {
    ADC_DATA_RES_12,                   /**< 12-bit */
    ADC_DATA_RES_10,                   /**< 10-bit */
    ADC_DATA_RES_8,                    /**< 8-bit  */
    ADC_DATA_RES_6,                    /**< 6-bit  */
} adc_data_res_t;

/**
 * @brief   Type of ADC DMA configuration.
 */
typedef struct {
    /**
     * @brief   ADC DMA stream to be used for regular conversions.
     */
    uint32_t                 dma_stream_id;
    /**
     * @brief   AFDC DMA stream bus priority (3..0).
     */
    uint32_t                 dma_stream_bus_prio;
    /**
     * @brief   ADC DMA stream IRQ priority (3..15).
     */
    uint32_t                 dma_stream_irq_prio;
} adc_dma_conf_t;

/**
 * @enum adc_reg_mode_t
 * ADC regular conversion mode configuration.
 */
typedef enum {
    ADC_REG_SINGLE,                    /**< Single conversion mode     */
    ADC_REG_CONTINUOUS,                /**< Continuous conversion mode */
} adc_reg_mode_t;

/**
 * @enum adc_conv_t
 * ADC conversion type configuration.
 */
typedef enum {
    ADC_REG_CONV,                      /**< Regular conversion type  */
    ADC_INJ_CONV,                      /**< Injected conversion type */
} adc_conv_t;

/**
 * @enum adc_ext_pol_t
 * ADC external trigger polarity configuration.
 */
typedef enum {
    ADC_EXT_POL_DISABLED,              /**< Hardware trigger detection disabled                              */
    ADC_EXT_POL_RISING,                /**< Hardware trigger detection on the rising edge                    */
    ADC_EXT_POL_FALLING,               /**< Hardware trigger detection on the falling edge                   */
    ADC_EXT_POL_BOTH,                  /**< Hardware trigger detection on both the rising and falling edges  */
} adc_ext_pol_t;

/**
 * @enum adc_smp_time_t
 * ADC channel sample time configuration.
 */
typedef enum {
    ADC_SMP_2P5,                       /**< 2.5 ADC clock cycles   */
    ADC_SMP_6P5,                       /**< 6.5 ADC clock cycles   */
    ADC_SMP_12P5,                      /**< 12.5 ADC clock cycles  */
    ADC_SMP_24P5,                      /**< 24.5 ADC clock cycles  */
    ADC_SMP_47P5,                      /**< 47.5 ADC clock cycles  */
    ADC_SMP_92P5,                      /**< 92.5 ADC clock cycles  */
    ADC_SMP_247P5,                     /**< 247.5 ADC clock cycles */
    ADC_SMP_640P5,                     /**< 640.5 ADC clock cycles */
} adc_smp_time_t;

/**
 * @enum adc_op_t
 * ADC normal operation type.
 */
typedef enum {
    ADC_OP_REG_CONV,                   /**< Regular conversion event    */
    ADC_OP_INJ_CONV,                   /**< Injected conversion event   */
    ADC_OP_MAX                         /**< Number of normal operations */
} adc_op_t;

/**
 * @enum adc_err_t
 * ADC error type.
 */
typedef enum {
    ADC_ERR_DMA,                       /**< DMA error event               */
    ADC_ERR_OVF,                       /**< Overflow error event          */
    ADC_ERR_AWD1,                      /**< Analog watchdog 1 error event */
    ADC_ERR_AWD2,                      /**< Analog watchdog 2 error event */
    ADC_ERR_AWD3,                      /**< Analog watchdog 3 error event */
    ADC_ERR_MAX                        /**< Number of errors              */
} adc_err_t;

/**
 * @brief   Type of an ADC callback.
 *
 * @param[in] adp       pointer to the @p adc_driver_t object
 */
typedef void (*adc_cb_t)(adc_driver_t *adp);

/**
 * @brief   Type of an ADC error callback.
 *
 * @param[in] adp       pointer to the @p adc_driver_t object
 * @param[in] err       ADC error code
 */
typedef void (*adc_err_cb_t)(adc_driver_t *adp, adc_err_t err);

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/**
 * @name    TRx registers initializers
 * @{
 */
#define ADC_TR(low, high)                   (((uint32_t)(high) << 16U) | (uint32_t)(low))
#define ADC_TR_DEFAULT                      ADC_TR(0x000U, 0xFFFU)
/** @} */

/**
 * @name    Regular conversion sequence length
 * @{
 */
#define ADC_SQR1_NUM_CH(n)                  (((n) - 1UL) << 0U)
/** @} */

/**
 * @name    Injected conversion sequence length
 * @{
 */
#define ADC_JSQR_NUM_CH(n)                  (((n) - 1UL) << 0U)
/** @} */

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

/* Export driver modules.*/
#include <saradc_instances.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Configures ADC clock mode.
 * @note    This configuration becomes effective after adc_start.
 * @note    This parameter is shared between more ADC instances.
 *
 * @param[out] adp      pointer to a @p adc_driver_t structure
 * @param[in] clk_mode  clock mode to be configured. It can be one of the
 *                      following values:
 *            @arg @ref ADC_CLK_MODE_ADCCLK
 *            @arg @ref ADC_CLK_MODE_AHB_DIV2
 *            @arg @ref ADC_CLK_MODE_AHB_DIV4
 * @return              previous clock mode. It can be one of the following
 *                      values:
 *            @arg @ref ADC_CLK_MODE_ADCCLK
 *            @arg @ref ADC_CLK_MODE_AHB_DIV2
 *            @arg @ref ADC_CLK_MODE_AHB_DIV4
 *
 * @api
 */
adc_clk_mode_t adc_set_clk_mode(adc_driver_t *adp, adc_clk_mode_t clk_mode);

/**
 * @brief   Configures ADC clock prescaler.
 * @note    This configuration becomes effective after adc_start.
 * @note    This parameter is shared between more ADC instances.
 *
 * @param[out] adp      pointer to a @p adc_driver_t structure
 * @param[in] presc     clock prescaler to be configured. It can be one of the
 *                      following values:
 *            @arg @ref ADC_CLK_PRESC_DIV_1
 *            @arg @ref ADC_CLK_PRESC_DIV_2
 *            @arg @ref ADC_CLK_PRESC_DIV_4
 *            @arg @ref ADC_CLK_PRESC_DIV_6
 *            @arg @ref ADC_CLK_PRESC_DIV_8
 *            @arg @ref ADC_CLK_PRESC_DIV_10
 *            @arg @ref ADC_CLK_PRESC_DIV_12
 *            @arg @ref ADC_CLK_PRESC_DIV_16
 *            @arg @ref ADC_CLK_PRESC_DIV_32
 *            @arg @ref ADC_CLK_PRESC_DIV_64
 *            @arg @ref ADC_CLK_PRESC_DIV_128
 *            @arg @ref ADC_CLK_PRESC_DIV_256
 * @return              previous clock prescaler. It can be one of the
 *                      following values:
 *            @arg @ref ADC_CLK_PRESC_DIV_1
 *            @arg @ref ADC_CLK_PRESC_DIV_2
 *            @arg @ref ADC_CLK_PRESC_DIV_4
 *            @arg @ref ADC_CLK_PRESC_DIV_6
 *            @arg @ref ADC_CLK_PRESC_DIV_8
 *            @arg @ref ADC_CLK_PRESC_DIV_10
 *            @arg @ref ADC_CLK_PRESC_DIV_12
 *            @arg @ref ADC_CLK_PRESC_DIV_16
 *            @arg @ref ADC_CLK_PRESC_DIV_32
 *            @arg @ref ADC_CLK_PRESC_DIV_64
 *            @arg @ref ADC_CLK_PRESC_DIV_128
 *            @arg @ref ADC_CLK_PRESC_DIV_256
 *
 * @api
 */
adc_clk_presc_t adc_set_presc(adc_driver_t *adp, adc_clk_presc_t presc);

/**
 * @brief   Configures ADC data resolution.
 * @note    This configuration becomes effective after adc_start.
 *
 * @param[out] adp      pointer to a @p adc_driver_t structure
 * @param[in] data_res  data resolution to be configured. It can be one of the
 *                      following values:
 *            @arg @ref ADC_DATA_RES_12
 *            @arg @ref ADC_DATA_RES_10
 *            @arg @ref ADC_DATA_RES_8
 *            @arg @ref ADC_DATA_RES_6
 * @return              previous data resolution. It can be one of the
 *                      following values:
 *            @arg @ref ADC_DATA_RES_12
 *            @arg @ref ADC_DATA_RES_10
 *            @arg @ref ADC_DATA_RES_8
 *            @arg @ref ADC_DATA_RES_6
 *
 * @api
 */
adc_data_res_t adc_set_data_res(adc_driver_t *adp, adc_data_res_t data_res);

/**
 * @brief   Configures ADC interrupt priority.
 * @note    This configuration becomes effective after adc_start.
 *
 * @param[out] adp      pointer to a @p adc_driver_t structure
 * @param[in] prio      interrupt priority to be configured
 * @return              previous interrupt priority.
 *
 * @api
 */
uint32_t adc_set_prio(adc_driver_t *adp, uint32_t prio);

/**
 * @brief   Enables/Disabled ADC interrupt.
 * @note    This configuration becomes effective after adc_start.
 * @note    Driver features are guaranteed if the related interrupt is enabled
 *          (default condition). If interrupt is disabled, some features as the
 *          single mode injected conversions could not work properly.
 *
 * @param[out] adp      pointer to a @p adc_driver_t structure
 * @param[in] is_interrupt_en interrupt enable status to be configured (true or
 *                      false)
 * @return              previous interrupt enable status.
 *
 * @api
 */
bool adc_set_interrupt_en(adc_driver_t *adp, bool is_interrupt_en);

/**
 * @brief   Configures ADC DMA configuration.
 * @note    This configuration becomes effective after adc_start.
 *
 * @param[out] adp      pointer to a @p adc_driver_t structure
 * @param[in] dma_conf  pointer to DMA configuration to be configured
 * @return              pointer to previous DMA configuration.
 *
 * @api
 */
adc_dma_conf_t *adc_set_dma_conf(adc_driver_t *adp, adc_dma_conf_t *dma_conf);

/**
 * @brief   Configures ADC regular conversion mode (continuous or single).
 * @note    This configuration becomes effective after adc_start.
 *
 * @param[out] adp      pointer to a @p adc_driver_t structure
 * @param[in] reg_mode  regular conversion mode to be configured. It can be one
 *                      of the following values:
 *            @arg @ref ADC_REG_SINGLE
 *            @arg @ref ADC_REG_CONTINUOUS
 * @return              previous regular conversion mode. It can be one of the
 *                      following values:
 *            @arg @ref ADC_REG_SINGLE
 *            @arg @ref ADC_REG_CONTINUOUS
 *
 * @api
 */
adc_reg_mode_t adc_set_reg_mode(adc_driver_t *adp, adc_reg_mode_t reg_mode);

/**
 * @brief   Configures ADC conversion external trigger.
 * @note    This configuration becomes effective after adc_start.
 *
 * @param[out] adp      pointer to a @p adc_driver_t structure
 * @param[in] con_type  conversion type (regular or injected). It can be one of
 *                      the following values:
 *            @arg @ref ADC_REG_CONV
 *            @arg @ref ADC_INJ_CONV
 * @param[in] ext       conversion external trigger to be configured
 * @param[in] ext_pol   conversion external trigger polarity to be configured.
 *                      It can be one of the following values:
 *            @arg @ref ADC_EXT_POL_DISABLED
 *            @arg @ref ADC_EXT_POL_RISING
 *            @arg @ref ADC_EXT_POL_FALLING
 *            @arg @ref ADC_EXT_POL_BOTH
 *
 * @api
 */
void adc_set_ext(adc_driver_t *adp, adc_conv_t con_type, uint32_t ext,
                 adc_ext_pol_t ext_pol);

/**
 * @brief   Disables ADC conversion external trigger.
 * @note    This configuration becomes effective after adc_start.
 *
 * @param[out] adp      pointer to a @p adc_driver_t structure
 * @param[in] con_type  conversion type (regular or injected). It can be one of
 *                      the following values:
 *            @arg @ref ADC_REG_CONV
 *            @arg @ref ADC_INJ_CONV
 *
 * @api
 */
void adc_reset_ext(adc_driver_t *adp, adc_conv_t con_type);

/**
 * @brief   Configures ADC regular conversion sequence.
 * @note    This configuration becomes effective after adc_start.
 * @note    The conversion sequence is the sequence of channels to convert. It
 *          is specified as a vector of n_channels elements, that contains the
 *          list of channels to convert in the desired order.
 * @note    n_channels is in [0:ADC_MAX_REG_SEQ_LEN] for regular conversions or
 *          in [0:ADC_MAX_INJ_SEQ_LEN] for injected conversions. '0' means the
 *          conversion is disabled.
 * @note    seq is a vector of n_channels elements. The element seq[i] is the
 *          number of channel [0:(ADC_CH_NUM - 1)] related to the conversion i.
 * @note    buffer is a vector of n_channels samples.
 *
 * @param[out] adp       pointer to a @p adc_driver_t structure
 * @param[in] con_type   conversion type (regular or injected). It can be one of
 *                      the following values:
 *            @arg @ref ADC_REG_CONV
 *            @arg @ref ADC_INJ_CONV
 * @param[in] n_channels number of channels to convert
 * @param[in] seq        conversion sequence to convert
 * @param[in] buffer     pointer to ADC samples buffer.
 *
 * @api
 */
void adc_set_seq(adc_driver_t *adp, adc_conv_t con_type, uint8_t n_channels, 
                 uint8_t *seq, adc_sample_t *buffer);

/**
 * @brief   Configures ADC channel sample time.
 * @note    This configuration becomes effective after adc_start.
 * @note    ch is in range [0:(ADC_CH_NUM - 1)].
 *
 * @param[out] adp      pointer to a @p adc_driver_t structure
 * @param[in] ch        channel related to sample time to be configured
 * @param[in] smp_time  sample time to be configured. It can be one of the
 *                      following values:
 *            @arg @ref ADC_SMP_2P5
 *            @arg @ref ADC_SMP_6P5
 *            @arg @ref ADC_SMP_12P5
 *            @arg @ref ADC_SMP_24P5
 *            @arg @ref ADC_SMP_47P5
 *            @arg @ref ADC_SMP_92P5
 *            @arg @ref ADC_SMP_247P5
 *            @arg @ref ADC_SMP_640P5
 * @return              previous sample time. It can be one of the following
 *                      values:
 *            @arg @ref ADC_SMP_2P5
 *            @arg @ref ADC_SMP_6P5
 *            @arg @ref ADC_SMP_12P5
 *            @arg @ref ADC_SMP_24P5
 *            @arg @ref ADC_SMP_47P5
 *            @arg @ref ADC_SMP_92P5
 *            @arg @ref ADC_SMP_247P5
 *            @arg @ref ADC_SMP_640P5
 *
 * @api
 */
adc_smp_time_t adc_set_smp_time(adc_driver_t *adp, uint8_t ch,
                                adc_smp_time_t smp_time);


/**
 * @brief   Configures ADC channel differential mode selection.
 * @note    This configuration becomes effective after adc_start.
 * @note    dif_mask allows to configure the ADC channels in single-ended
 *          mode or in differential mode. A '0' in the position i means the
 *          channel i is configured in single ended mode, a '1' in the
 *          position i means the channel i is configured in differential
 *          mode. dif_mask is ADC_CH_NUM bits.
 *
 * @param[out] adp      pointer to a @p adc_driver_t structure
 * @param[in] dif_mask  ADC channels differential mode mask
 * @return              previous differential mode mask.
 *
 * @api
 */
uint16_t adc_set_dif_sel(adc_driver_t *adp, uint16_t dif_mask);

/**
 * @brief   Configures ADC analog watchdog threshold.
 * @note    This configuration becomes effective after adc_start.
 *
 * @param[out] adp      pointer to a @p adc_driver_t structure
 * @param[in] watchdog  watchdog [1:ADC_WATCHDOG_NUM] to be configured
 * @param[in] aw_ltr    analog watchdog lower threshold to be configured
 * @param[in] aw_htr    analog watchdog higher threshold to be configured
 * @return              previous analog watchdog threshold.
 *
 * @api
 */
uint32_t adc_set_aw_tr(adc_driver_t *adp, uint32_t watchdog, uint32_t aw_ltr,
                       uint32_t aw_htr);

/**
 * @brief   Configures pointers to ADC normal operation callback functions.
 *
 * @param[out] adp      pointer to a @p adc_driver_t structure
 * @param[in] op        operation type. It can be one of the following values:
 *            @arg @ref ADC_OP_REG_CONV
 *            @arg @ref ADC_OP_INJ_CONV
 *            @arg @ref ADC_OP_MAX
 * @param[in] op_cb     pointer to ADC callback function related to operation
 *                      specified by op parameter
 * @return              pointer to previuos ADC callback function.
 *
 * @api
 */
adc_cb_t adc_set_op_cb(adc_driver_t *adp, adc_op_t op, adc_cb_t op_cb);

/**
 * @brief   Configures pointers to ADC error callback functions.
 *
 * @param[out] adp      pointer to a @p adc_driver_t structure
 * @param[in] err       error type. It can be one of the following values:
 *            @arg @ref ADC_ERR_DMA
 *            @arg @ref ADC_ERR_OVF
 *            @arg @ref ADC_ERR_AWD1
 *            @arg @ref ADC_ERR_AWD2
 *            @arg @ref ADC_ERR_AWD3
 *            @arg @ref ADC_ERR_MAX
 * @param[in] err_cb    pointer to ADC callback function related to error
 *                      specified by err parameter
 * @return              pointer to previuos ADC callback function.
 *
 * @api
 */
adc_err_cb_t adc_set_err_cb(adc_driver_t *adp, adc_err_t err,
                            adc_err_cb_t err_cb);

/**
 * @brief   Initializes an ADC instance.
 *
 * @param[out] adp      pointer to an @p adc_driver_t structure
 *
 * @api
 */
void adc_init(adc_driver_t *adp);

/**
 * @brief   Starts an ADC instance.
 *
 * @param[in] adp       pointer to a @p adc_driver_t structure
 *
 * @api
 */
void adc_start(adc_driver_t *adp);

/**
 * @brief   Starts ADC regular conversions.
 *
 * @param[in] adp       pointer to the @p adc_driver_t structure
 *
 * @api
 */
void adc_start_regular(adc_driver_t *adp);

/**
 * @brief   Starts ADC injected conversions.
 *
 * @param[in] adp       pointer to the @p adc_driver_t structure
 *
 * @api
 */
void adc_start_injected(adc_driver_t *adp);

/**
 * @brief   Stops ADC regular conversions.
 *
 * @param[in] adp       pointer to the @p adc_driver_t structure
 *
 * @api
 */
void adc_stop_regular(adc_driver_t *adp);

/**
 * @brief   Stops ADC injected conversions.
 *
 * @param[in] adp       pointer to the @p adc_driver_t structure
 *
 * @api
 */
void adc_stop_injected(adc_driver_t *adp);

/**
 * @brief   Stops an ADC instance.
 *
 * @param[in] adp       pointer to an @p adc_driver_t structure
 *
 * @api
 */
void adc_stop(adc_driver_t *adp);

/**
 * @brief   De-initializes an ADC instance.
 *
 * @param[out] adp      pointer to an @p adc_driver_t structure
 *
 * @api
 */
void adc_deinit(adc_driver_t *adp);

/**
 * @brief   Returns the ADC clock value.
 *
 * @param[in] adp       pointer to an @p adc_driver_t structure
 *
 * @api
 */
uint32_t adc_get_clock(adc_driver_t *adp);

/**
 * @brief   Serves an ADC interrupt.
 * @note    Not an API, used internally.
 *
 * @param[in] adp       pointer to an @p adc_driver_t structure
 *
 * @isr
 */
void __adc_serve_interrupt(adc_driver_t *adp);

#ifdef __cplusplus
}
#endif

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/*===========================================================================*/
/* Module late inclusions.                                                   */
/*===========================================================================*/

#endif /* _SARADC_H_ */

/** @} */
