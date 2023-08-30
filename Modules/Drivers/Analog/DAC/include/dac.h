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
 * @file    dac.h
 * @brief   DAC driver header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup ANALOG
 * @ingroup DRIVERS
 * @addtogroup DAC
 * @ingroup ANALOG
 * @{
 */

#ifndef _DAC_H_
#define _DAC_H_

#include <typedefs.h>

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

/**
 * @brief   DAC number of channels [CH1:CH2].
 */
#define DAC_CHANNEL_NUM                     2U

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
 * @brief   Type of an DAC driver.
 */
typedef struct dac_driver dac_driver_t;

/**
 * @enum dac_channel_t
 * DAC channel select.
 */
typedef enum {
    DAC_CHANNEL_1 = 0U,      /**< DAC channel 1 */
    DAC_CHANNEL_2 = 1U,      /**< DAC chennel 2 */
} dac_channel_t;

/**
 * @enum dac_hf_mode_t
 * DAC high frequency select (HFSEL bit).
 */
typedef enum {
    DAC_HF_MODE_LESS_80MHZ = 0U,  /**< DAC AHB freq less 80MHz  */
    DAC_HF_MODE_OVER_80MHZ = 1U,  /**< DAC AHB freq over 80MHz  */
    DAC_HF_MODE_OVER_160MHZ = 2U  /**< DAC AHB freq over 160MHz */
} dac_hf_mode_t;

/**
 * @enum dac_data_format_t
 * DAC data format selection.
 */
typedef enum {
    DAC_DATA_8BIT,                /**< DAC 8 bit mode                */
    DAC_DATA_12BIT_LEFT_ALIGN,    /**< DAC 12 bit left aligned mode  */
    DAC_DATA_12BIT_RIGHT_ALIGN    /**< DAC 12 bit right aligned mode */
} dac_data_format_t;

/**
 * @enum dac_trigger_src_t
 * DAC standard trigger source/DAC reset trigger source for sawtooth wave
 * generation.
 */
typedef enum {
    DAC_SWTRIG      = 0U,         /**< DAC software trigger*/
    DAC_CHx_TRIG1   = 1U,         /**< DAC trigger 1 BDAC_DAC1_DAC2_DAC4:TIM8_TRGO*, DAC3:TIM1_TRGO                               */
    DAC_CHx_TRIG2   = 2U,         /**< DAC trigger 2 BDAC_DAC1_DAC2_DAC3_DAC4:TIM7_TRGO                                           */
    DAC_CHx_TRIG3   = 3U,         /**< DAC trigger 3 BDAC_DAC1_DAC2_DAC3_DAC4:TIM15_TRGO                                          */
    DAC_CHx_TRIG4   = 4U,         /**< DAC trigger 4 BDAC_DAC1_DAC2_DAC3_DAC4:TIM2_TRGO                                           */
    DAC_CHx_TRIG5   = 5U,         /**< DAC trigger 5 BDAC_DAC1_DAC2_DAC3_DAC4:TIM4_TRGO                                           */
    DAC_CHx_TRIG6   = 6U,         /**< DAC trigger 6 BDAC_DAC1_DAC2_DAC3_DAC4:EXTI9                                               */
    DAC_CHx_TRIG7   = 7U,         /**< DAC trigger 7 BDAC_DAC1_DAC2_DAC3_DAC4:TIM6_TRGO                                           */
    DAC_CHx_TRIG8   = 8U,         /**< DAC trigger 8 BDAC_DAC1_DAC2_DAC3_DAC4:TIM3_TRGO                                           */
    DAC_CHx_TRIG9   = 9U,         /**< DAC trigger 9  BDAC_DAC1_DAC2:hrtim1_dac_reset_trg1, DAC3_DAC4:hrtim2_dac_reset_trg1       */
    DAC_CHx_TRIG10  = 10U,        /**< DAC trigger 10 BDAC_DAC1_DAC2:hrtim1_dac_reset_trg2, DAC3_DAC4:hrtim2_dac_reset_trg2       */
    DAC_CHx_TRIG11  = 11U,        /**< DAC trigger 11 BDAC_DAC1_DAC2:hrtim1_dac_reset_trg3, DAC3_DAC4:hrtim2_dac_reset_trg3       */
    DAC_CHx_TRIG12  = 12U,        /**< DAC trigger 12 BDAC_DAC1_DAC2:hrtim1_dac_reset_trg4, DAC3_DAC4:hrtim2_dac_reset_trg4       */
    DAC_CHx_TRIG13  = 13U,        /**< DAC trigger 13 BDAC_DAC1_DAC2:hrtim1_dac_reset_trg5, DAC3_DAC4:hrtim2_dac_reset_trg5       */
    DAC_CHx_TRIG14  = 14U,        /**< DAC trigger 14 BDAC_DAC1_DAC2:hrtim1_dac_reset_trg6, DAC3_DAC4:hrtim2_dac_reset_trg6       */
    DAC_CHx_TRIG15  = 15U,        /**< DAC trigger 15 BDAC_DAC1:hrtim1_dac_trg1, DAC2: hrtim1_dac_trg2, DAC3_DAC4:hrtim2_dac_trg1 */
} dac_trigger_src_t;

/**
 * @enum dac_inc_trigger_src_t
 * DAC increment trigger source (for sawtooth wave generation).
 */
typedef enum {
    DAC_INC_SWTRIGB     = 0U,     /**< DAC software trigger*/
    DAC_INC_CHx_TRIG1   = 1U,     /**< DAC trigger 1 BDAC_DAC1_DAC2_DAC4:TIM8_TRGO, DAC3:TIM1_TRGO                          */
    DAC_INC_CHx_TRIG2   = 2U,     /**< DAC trigger 2 BDAC_DAC1_DAC2_DAC3_DAC4:TIM7_TRGO                                     */
    DAC_INC_CHx_TRIG3   = 3U,     /**< DAC trigger 3 BDAC_DAC1_DAC2_DAC3_DAC4:TIM15_TRGO                                    */
    DAC_INC_CHx_TRIG4   = 4U,     /**< DAC trigger 4 BDAC_DAC1_DAC2_DAC3_DAC4:TIM2_TRGO                                     */
    DAC_INC_CHx_TRIG5   = 5U,     /**< DAC trigger 5 BDAC_DAC1_DAC2_DAC3_DAC4:TIM4_TRGO                                     */
    DAC_INC_CHx_TRIG6   = 6U,     /**< DAC trigger 6 BDAC_DAC1_DAC2_DAC3_DAC4:EXTI10                                        */
    DAC_INC_CHx_TRIG7   = 7U,     /**< DAC trigger 7 BDAC_DAC1_DAC2_DAC3_DAC4:TIM6_TRGO                                     */
    DAC_INC_CHx_TRIG8   = 8U,     /**< DAC trigger 8 BDAC_DAC1_DAC2_DAC3_DAC4:TIM3_TRGO                                     */
    DAC_INC_CHx_TRIG9   = 9U,     /**< DAC trigger 9  BDAC_DAC1_DAC2:hrtim1_dac_reset_trg1, DAC3_DAC4:hrtim2_dac_reset_trg1 */
    DAC_INC_CHx_TRIG10  = 10U,    /**< DAC trigger 10 BDAC_DAC1_DAC2:hrtim1_dac_reset_trg2, DAC3_DAC4:hrtim2_dac_reset_trg2 */
    DAC_INC_CHx_TRIG11  = 11U,    /**< DAC trigger 11 BDAC_DAC1_DAC2:hrtim1_dac_reset_trg3, DAC3_DAC4:hrtim2_dac_reset_trg3 */
    DAC_INC_CHx_TRIG12  = 12U,    /**< DAC trigger 12 BDAC_DAC1_DAC2:hrtim1_dac_reset_trg4, DAC3_DAC4:hrtim2_dac_reset_trg4 */
    DAC_INC_CHx_TRIG13  = 13U,    /**< DAC trigger 13 BDAC_DAC1_DAC2:hrtim1_dac_reset_trg5, DAC3_DAC4:hrtim2_dac_reset_trg5 */
    DAC_INC_CHx_TRIG14  = 14U,    /**< DAC trigger 14 BDAC_DAC1_DAC2:hrtim1_dac_reset_trg6, DAC3_DAC4:hrtim2_dac_reset_trg6 */
    DAC_INC_CHx_TRIG15  = 15U,    /**< DAC trigger 15 BDAC_DAC1_DAC2_DAC3_DAC4:none                                         */
} dac_inc_trigger_src_t;

/**
 * @enum dac_rst_trigger_src_t
 * DAC reset trigger source (for sawtooth wave generation).
 */
typedef enum {
    DAC_RST_SWTRIGB     = 0U,     /**< DAC software trigger                                                                 */
    DAC_RST_CHx_TRIG1   = 1U,     /**< DAC trigger 1 BDAC_DAC1_DAC2_DAC4:TIM8_TRGO, DAC3:TIM1_TRGO                          */
    DAC_RST_CHx_TRIG2   = 2U,     /**< DAC trigger 2 BDAC_DAC1_DAC2_DAC3_DAC4:TIM7_TRGO                                     */
    DAC_RST_CHx_TRIG3   = 3U,     /**< DAC trigger 3 BDAC_DAC1_DAC2_DAC3_DAC4:TIM15_TRGO                                    */
    DAC_RST_CHx_TRIG4   = 4U,     /**< DAC trigger 4 BDAC_DAC1_DAC2_DAC3_DAC4:TIM2_TRGO                                     */
    DAC_RST_CHx_TRIG5   = 5U,     /**< DAC trigger 5 BDAC_DAC1_DAC2_DAC3_DAC4:TIM4_TRGO                                     */
    DAC_RST_CHx_TRIG6   = 6U,     /**< DAC trigger 6 BDAC_DAC1_DAC2_DAC3_DAC4:EXTI10                                        */
    DAC_RST_CHx_TRIG7   = 7U,     /**< DAC trigger 7 BDAC_DAC1_DAC2_DAC3_DAC4:TIM6_TRGO                                     */
    DAC_RST_CHx_TRIG8   = 8U,     /**< DAC trigger 8 BDAC_DAC1_DAC2_DAC3_DAC4:TIM3_TRGO                                     */
    DAC_RST_CHx_TRIG9   = 9U,     /**< DAC trigger 9  BDAC_DAC1_DAC2:hrtim1_dac_reset_trg1, DAC3_DAC4:hrtim2_dac_reset_trg1 */
    DAC_RST_CHx_TRIG10  = 10U,    /**< DAC trigger 10 BDAC_DAC1_DAC2:hrtim1_dac_reset_trg2, DAC3_DAC4:hrtim2_dac_reset_trg2 */
    DAC_RST_CHx_TRIG11  = 11U,    /**< DAC trigger 11 BDAC_DAC1_DAC2:hrtim1_dac_reset_trg3, DAC3_DAC4:hrtim2_dac_reset_trg3 */
    DAC_RST_CHx_TRIG12  = 12U,    /**< DAC trigger 12 BDAC_DAC1_DAC2:hrtim1_dac_reset_trg4, DAC3_DAC4:hrtim2_dac_reset_trg4 */
    DAC_RST_CHx_TRIG13  = 13U,    /**< DAC trigger 13 BDAC_DAC1_DAC2:hrtim1_dac_reset_trg5, DAC3_DAC4:hrtim2_dac_reset_trg5 */
    DAC_RST_CHx_TRIG14  = 14U,    /**< DAC trigger 14 BDAC_DAC1_DAC2:hrtim1_dac_reset_trg6, DAC3_DAC4:hrtim2_dac_reset_trg6 */
    DAC_RST_CHx_TRIG15  = 15U,    /**< DAC trigger 15 BDAC_DAC1_DAC2_DAC3_DAC4:none                                         */
} dac_rst_trigger_src_t;

/**
 * @enum dac_drv_mode_t
 * DAC driver mode.
 */
typedef enum {
    DAC_DVR_MODE_SINGLE,     /**< DAC single mode */
    DAC_DVR_MODE_DUAL        /**< DAC dual mode   */
} dac_drv_mode_t;

/**
 * @enum dac_wave_mode_t
 * DAC wave mode.
 */
typedef enum {
    DAC_WAVE_MODE_DISABLE   = 0U,      /**< DAC disable wave  */
    DAC_WAVE_MODE_NOISE     = 1U,      /**< DAC noise wave    */
    DAC_WAVE_MODE_TRIANGLE  = 2U,      /**< DAC triangle wave */
    DAC_WAVE_MODE_SAWTOOTH  = 3U,      /**< DAC sawtooth wave */
} dac_wave_mode_t;

/**
 * @enum dac_out_con_mode_t
 * DAC output connection mode. Including output buffer (only for BDAC), normal
 * and sample & hold mode configuration
 */
typedef enum {
    DAC_OUT_CON_MODE_NORM_PIN_BUF_EN     = 0U,   /**< Normal mode, output connected to external pin with buffer enabled                                 */
    DAC_OUT_CON_MODE_NORM_PIN_PER_BUF_EN = 1U,   /**< Normal mode, output connected to external pin and to on chip peripherals with buffer enabled      */
    DAC_OUT_CON_MODE_NORM_PIN_BUF_DIS    = 2U,   /**< Normal mode, output connected to external pin with buffer disabled                                */
    DAC_OUT_CON_MODE_NORM_PER_BUF_DIS    = 3U,   /**< Normal mode, output connected to on chip peripherals with buffer disabled                         */
    DAC_OUT_CON_MODE_SAHO_PIN_BUF_EN     = 4U,   /**< Sample&Hold mode, output connected to external pin with buffer enabled                            */
    DAC_OUT_CON_MODE_SAHO_PIN_PER_BUF_EN = 5U,   /**< Sample&Hold mode, output connected to external pin and to on chip peripherals with buffer enabled */ 
    DAC_OUT_CON_MODE_SAHO_PIN_BUF_DIS    = 6U,   /**< Sample&Hold mode, output connected to external pin with buffer disabled                           */
    DAC_OUT_CON_MODE_SAHO_PER_BUF_DIS    = 7U,   /**< Sample&Hold mode, output connected to on chip peripherals with buffer disabled                    */
} dac_out_con_mode_t;

/**
 * @enum dac_dma_mode_t
 * DAC DMA configuration.
 */
typedef enum {
    DAC_DMA_OFF,   /**< DMA disabled */
    DAC_DMA_ON,    /**< DMA enabled  */
} dac_dma_mode_t;

/**
 * @brief   Type of an DAC notification callback.
 *
 * @param[in] ddp       pointer to the @p dac_driver_t object
 */
typedef void (*dac_cb_t)(dac_driver_t *ddp);

/**
 * @enum dac_sw_trigger_t
 * enable DAC trigger enable.
 */
typedef enum {
    DAC_SW_TRIGGER_ENABLE,        /**< DAC trigger enable           */
    DAC_SW_TRIGGER_INC_ENABLE     /**< DAC increment trigger enable */
} dac_sw_trigger_t;

/**
 * @enum dac_lfsr_triangle_mask_t
 * DAC LFSR/triangle mask configurations.
 */
typedef enum {
    DAC_LFSR_TRIANGLE_MASK0   = 0U,         /**< DAC LFSR/triangle amplitude is 1    */
    DAC_LFSR_TRIANGLE_MASK1   = 1U,         /**< DAC LFSR/triangle amplitude is 3    */
    DAC_LFSR_TRIANGLE_MASK2   = 2U,         /**< DAC LFSR/triangle amplitude is 7    */
    DAC_LFSR_TRIANGLE_MASK3   = 3U,         /**< DAC LFSR/triangle amplitude is 15   */
    DAC_LFSR_TRIANGLE_MASK4   = 4U,         /**< DAC LFSR/triangle amplitude is 31   */
    DAC_LFSR_TRIANGLE_MASK5   = 5U,         /**< DAC LFSR/triangle amplitude is 63   */
    DAC_LFSR_TRIANGLE_MASK6   = 6U,         /**< DAC LFSR/triangle amplitude is 127  */
    DAC_LFSR_TRIANGLE_MASK7   = 7U,         /**< DAC LFSR/triangle amplitude is 255  */
    DAC_LFSR_TRIANGLE_MASK8   = 8U,         /**< DAC LFSR/triangle amplitude is 511  */
    DAC_LFSR_TRIANGLE_MASK9   = 9U,         /**< DAC LFSR/triangle amplitude is 1023 */
    DAC_LFSR_TRIANGLE_MASK10  = 10U,        /**< DAC LFSR/triangle amplitude is 2047 */
    DAC_LFSR_TRIANGLE_MASK11  = 11U,        /**< DAC LFSR/triangle amplitude is 4095 */
    DAC_LFSR_TRIANGLE_MASK12  = 12U,        /**< DAC LFSR/triangle amplitude is 4095 */
    DAC_LFSR_TRIANGLE_MASK13  = 13U,        /**< DAC LFSR/triangle amplitude is 4095 */
    DAC_LFSR_TRIANGLE_MASK14  = 14U,        /**< DAC LFSR/triangle amplitude is 4095 */
    DAC_LFSR_TRIANGLE_MASK15  = 15U,        /**< DAC LFSR/triangle amplitude is 4095 */
} dac_lfsr_triangle_mask_t;


/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

/* Export driver modules.*/
#include <dac_instances.h>


#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Initializes a DAC instance.
 *
 * @param[out] ddp      pointer to an @p dac_driver_t structure
 *
 * @init
 */
void dac_init(dac_driver_t *ddp);

/**
 * @brief   Configures DAC interrupt priority.
 * @note    This configuration becomes effective after dac_start.
 *
 * @param[in] ddp       pointer to an @p dac_driver_t structure
 * @param[in] prio      interrupt priority to be configured
 * @return              previous interrupt priority.
 *
 * @api
 */
uint32_t dac_set_prio(dac_driver_t *ddp, uint32_t prio);

/**
 * @brief   Enables DAC dedicated channel.
 * @note    This configuration becomes effective after dac_start.
 *
 * @param[out] ddp      pointer to a @p dac_driver_t structure
 * @param[in] channel   DAC dedicated channel. It can be one of the following
 *                      values:
 *            @arg @ref DAC_CHANNEL_1
 *            @arg @ref DAC_CHANNEL_2
 * @param[in]  mode     channel enable flag
 * @return              previous channel enable flag status.
 *
 * @api
 */
bool dac_enable_channel(dac_driver_t *ddp, dac_channel_t channel, bool enable);

/**
 * @brief   Sets DAC high frequency mode.
 * @note    This configuration becomes effective after dac_start.
 *
 * @param[out] ddp      pointer to a @p dac_driver_t structure
 * @param[in] hf_mode   DAC high frequency mode to be configured. It can be one
 *                      of the followingvalues:
 *            @arg @ref DAC_HF_MODE_LESS_80MHZ
 *            @arg @ref DAC_HF_MODE_OVER_80MHZ
 *            @arg @ref DAC_HF_MODE_OVER_160MHZ
 * @return              previous DAC high frequency mode.
 *
 * @api
 */
dac_hf_mode_t dac_set_highfreq_mode(dac_driver_t *ddp, dac_hf_mode_t hf_mode);

/**
 * @brief   Enables DAC dedicated channel calibration.
 * @note    This configuration becomes effective after dac_start.
 *
 * @param[out] ddp      pointer to a @p dac_driver_t structure
 * @param[in] channel   DAC dedicated channel to be calibrated. It can be one
 *                      of the following values:
 *            @arg @ref DAC_CHANNEL_1
 *            @arg @ref DAC_CHANNEL_2
 * @param[in] enable    DAC calibration enable flag.
 * @return              previous channel enable status.
 *
 * @api
 */
bool dac_enable_calibration(dac_driver_t *ddp, dac_channel_t channel,
                            bool enable);

/**
 * @brief   Sets DAC dedicated channel data format.
 * @note    This configuration becomes effective after dac_start.
 *
 * @param[out] ddp      pointer to a @p dac_driver_t structure
 * @param[in] channel   DAC dedicated channelto be configured. It can be one of
 *                      the following values:
 *            @arg @ref DAC_CHANNEL_1
 *            @arg @ref DAC_CHANNEL_2
 * @param[in] data_format DAC data format to be configure. It can be one of the
 *                      following values:
 *            @arg @ref DAC_DATA8BIT
 *            @arg @ref DAC_DATA12BIT_LEFT_ALIGN
 *            @arg @ref DAC_DATA12BIT_RIGHT_ALIGN
 * @return              previous channel data format.
 *
 * @api
 */
dac_data_format_t dac_set_format(dac_driver_t *ddp, dac_channel_t channel,
                                 dac_data_format_t data_format);

/**
 * @brief   Sets DAC dedicated channel trigger source.
 * @note    This configuration becomes effective after dac_start.
 *
 * @param[out] ddp      pointer to a @p dac_driver_t structure
 * @param[in] channel   DAC dedicated channel to be configured. It can be one
 *                      of the following values:
 *            @arg @ref DAC_CHANNEL_1
 *            @arg @ref DAC_CHANNEL_2
 * @param[in] trigger_src DAC channel trigger source to be configured. It can
 *                      be one of the following values:
 *            @arg @ref DAC_SWTRIG
 *            @arg @ref DAC_CHx_TRIG1
 *            @arg @ref DAC_CHx_TRIG2
 *            @arg @ref DAC_CHx_TRIG3
 *            @arg @ref DAC_CHx_TRIG4
 *            @arg @ref DAC_CHx_TRIG5
 *            @arg @ref DAC_CHx_TRIG6
 *            @arg @ref DAC_CHx_TRIG7
 *            @arg @ref DAC_CHx_TRIG8
 *            @arg @ref DAC_CHx_TRIG9
 *            @arg @ref DAC_CHx_TRIG10
 *            @arg @ref DAC_CHx_TRIG11
 *            @arg @ref DAC_CHx_TRIG12
 *            @arg @ref DAC_CHx_TRIG13
 *            @arg @ref DAC_CHx_TRIG14
 *            @arg @ref DAC_CHx_TRIG15
 * @return              previous channel trigger source.
 *
 * @api
 */
dac_trigger_src_t dac_set_trigger_src(dac_driver_t *ddp, dac_channel_t channel,
                                      dac_trigger_src_t trigger_src);

/**
 * @brief   Sets DAC dedicated channel increment trigger source.
 * @note    This configuration becomes effective after dac_start.
 *
 * @param[out] ddp      pointer to a @p dac_driver_t structure
 * @param[in] channel   DAC dedicated channel to be configured. It can be one
 *                      of the following values:
 *            @arg @ref DAC_CHANNEL_1
 *            @arg @ref DAC_CHANNEL_2
 * @param[in] inc_trigger_src DAC channel increment trigger source to be
 *                      configured. It can be one of the following values:
 *            @arg @ref DAC_INC_SWTRIGB
 *            @arg @ref DAC_INC_CHx_TRIG1
 *            @arg @ref DAC_INC_CHx_TRIG2
 *            @arg @ref DAC_INC_CHx_TRIG3
 *            @arg @ref DAC_INC_CHx_TRIG4
 *            @arg @ref DAC_INC_CHx_TRIG5
 *            @arg @ref DAC_INC_CHx_TRIG6
 *            @arg @ref DAC_INC_CHx_TRIG7
 *            @arg @ref DAC_INC_CHx_TRIG8
 *            @arg @ref DAC_INC_CHx_TRIG9
 *            @arg @ref DAC_INC_CHx_TRIG10
 *            @arg @ref DAC_INC_CHx_TRIG11
 *            @arg @ref DAC_INC_CHx_TRIG12
 *            @arg @ref DAC_INC_CHx_TRIG13
 *            @arg @ref DAC_INC_CHx_TRIG14
 *            @arg @ref DAC_INC_CHx_TRIG15
 * @return              previous channel increment trigger source.
 *
 * @api
 */
dac_inc_trigger_src_t dac_set_inc_trigger_src(dac_driver_t *ddp,
                                              dac_channel_t channel,
                                              dac_inc_trigger_src_t inc_trigger_src);

/**
 * @brief   Sets DAC dedicated channel reset trigger source.
 * @note    This configuration becomes effective after dac_start.
 *
 * @param[out] ddp      pointer to a @p dac_driver_t structure
 * @param[in] channel   DAC dedicated channel to be configured. It can be one
 *                      of the following values:
 *            @arg @ref DAC_CHANNEL_1
 *            @arg @ref DAC_CHANNEL_2
 * @param[in] rst_trigger_src DAC channel reset trigger source to be
 *                      configured. It can be one of the following values:
 *            @arg @ref DAC_RST_SWTRIGB
 *            @arg @ref DAC_RST_CHx_TRIG1
 *            @arg @ref DAC_RST_CHx_TRIG2
 *            @arg @ref DAC_RST_CHx_TRIG3
 *            @arg @ref DAC_RST_CHx_TRIG4
 *            @arg @ref DAC_RST_CHx_TRIG5
 *            @arg @ref DAC_RST_CHx_TRIG6
 *            @arg @ref DAC_RST_CHx_TRIG7
 *            @arg @ref DAC_RST_CHx_TRIG8
 *            @arg @ref DAC_RST_CHx_TRIG9
 *            @arg @ref DAC_RST_CHx_TRIG10
 *            @arg @ref DAC_RST_CHx_TRIG11
 *            @arg @ref DAC_RST_CHx_TRIG12
 *            @arg @ref DAC_RST_CHx_TRIG13
 *            @arg @ref DAC_RST_CHx_TRIG14
 *            @arg @ref DAC_RST_CHx_TRIG15
 * @return              previous channel reset trigger source.
 *
 * @api
 */
dac_rst_trigger_src_t dac_set_rst_trigger_src(dac_driver_t *ddp,
                                              dac_channel_t channel,
                                              dac_rst_trigger_src_t rst_trigger_src);

/**
 * @brief   Enables DAC dedicated channel trigger.
 * @note    This configuration becomes effective after dac_start.
 *
 * @param[out] ddp      pointer to a @p dac_driver_t structure
 * @param[in] channel   DAC dedicated channel to be configured. It can be one
 *                      of the following values:
 *            @arg @ref DAC_CHANNEL_1
 *            @arg @ref DAC_CHANNEL_2
 * @param[in] enable    DAC channel trigger enable flag.
 * @return              previous channel trigger enable status.
 *
 * @api
 */
bool dac_enable_trigger(dac_driver_t *ddp, dac_channel_t channel, bool enable);

/**
 * @brief   Sets DAC dedicated channel mode (single or dual).
 * @note    This configuration becomes effective after dac_start.
 *
 * @param[out] ddp      pointer to a @p dac_driver_t structure
 * @param[in] channel   DAC dedicated channel to be configured. It can be one
 *                      of the following values:
 *            @arg @ref DAC_CHANNEL_1
 *            @arg @ref DAC_CHANNEL_2
 * @param[in] drv_mode  DAC driver mode to be configured. It can be one of the
 *                      following values:
 *            @arg @ref DAC_DVR_MODE_SINGLE
 *            @arg @ref DAC_DVR_MODE_DUAL
 * @return              previous DAC driver mode.
 *
 * @api
 */
dac_drv_mode_t dac_set_mode(dac_driver_t *ddp, dac_drv_mode_t drv_mode);

/**
 * @brief   Sets DAC dedicated channel wave mode.
 * @note    This configuration becomes effective after dac_start.
 *
 * @param[out] ddp      pointer to a @p dac_driver_t structure
 * @param[in] channel   DAC dedicated channel to be configured. It can be one
 *                      of the following values:
 *            @arg @ref DAC_CHANNEL_1
 *            @arg @ref DAC_CHANNEL_2
 * @param[in] wave_mode DAC wave mode to be configured. It can be one of the
 *                      following values:
 *            @arg @ref DAC_WAVE_MODE_DISABLE
 *            @arg @ref DAC_WAVE_MODE_NOISE
 *            @arg @ref DAC_WAVE_MODE_TRIANGLE
 *            @arg @ref DAC_WAVE_MODE_SAWTOOTH
 * @return              previous channel wave mode.
 *
 * @api
 */
dac_wave_mode_t dac_set_wave(dac_driver_t *ddp, dac_channel_t channel,
                             dac_wave_mode_t wave_mode);

/**
 * @brief   Sets DAC dedicated channel output connection.
 * @note    This configuration becomes effective after dac_start.
 *
 * @param[out] ddp        pointer to a @p dac_driver_t structure
 * @param[in] channel     DAC dedicated channel to be configured. It can be one
 *                        of the following values:
 *              @arg @ref DAC_CHANNEL_1
 *              @arg @ref DAC_CHANNEL_2
 * @param[in] out_con_mode DAC channel output connection mode to be configured.
 *                        It can be one of the following values:
 *              @arg @ref DAC_OUT_CON_MODE_NORM_PIN_BUF_EN
 *              @arg @ref DAC_OUT_CON_MODE_NORM_PIN_PER_BUF_EN
 *              @arg @ref DAC_OUT_CON_MODE_NORM_PIN_BUF_DIS
 *              @arg @ref DAC_OUT_CON_MODE_NORM_PER_BUF_DIS
 *              @arg @ref DAC_OUT_CON_MODE_SAHO_PIN_BUF_EN
 *              @arg @ref DAC_OUT_CON_MODE_SAHO_PIN_PER_BUF_EN
 *              @arg @ref DAC_OUT_CON_MODE_SAHO_PIN_BUF_DIS
 *              @arg @ref DAC_OUT_CON_MODE_SAHO_PER_BUF_DIS
 *
 * @api
 */
dac_out_con_mode_t dac_set_output_connection(dac_driver_t *ddp,
                                             dac_channel_t channel,
                                             dac_out_con_mode_t out_con_mode);

/**
 * @brief   Configures DAC DMA mode (enabled or disabled).
 * @note    This configuration becomes effective after uart_start.
 *
 * @param[out] ddp      pointer to a @p dac_driver_t structure
 * @param[in] dma_mode  DMA mode to be configured. It can be one of the
 *                      following values:
 *            @arg @ref DAC_DMA_OFF
 *            @arg @ref DAC_DMA_ON
 * @return              previous DMA mode. It can be one of the following
 *                      values:
 *            @arg @ref DAC_DMA_OFF
 *            @arg @ref DAC_DMA_ON
 *
 * @api
 */
dac_dma_mode_t dac_set_dma_mode(dac_driver_t *ddp, dac_channel_t channel, 
                                dac_dma_mode_t dma_mode);

/**
 * @brief   Configures pointers to DAC callback functions.
 *
 * @param[out] ddp      pointer to a @p dac_driver_t structure
 * @param[in] cb        pointer to DAC callback function
 * @return              pointer to previuos DAC callback function.
 *
 * @api
 */
dac_cb_t dac_set_cb(dac_driver_t *ddp, dac_cb_t cb);

/**
 * @brief   Starts a DAC instance.
 *
 * @param[in] ddp       pointer to an @p dac_driver_t structure
 *
 * @api
 */
void dac_start(dac_driver_t *ddp);

/**
 * @brief   Sets DAC dedicated channel digital value.
 * @note    It must be invoked after dac_start, otherwise it doesn't not take
 *          effect.
 *
 * @param[out] ddp      pointer to a @p dac_driver_t structure
 * @param[in] channel   DAC dedicated channel to be configured. It can be one
 *                      of the following values:
 *            @arg @ref DAC_CHANNEL_1
 *            @arg @ref DAC_CHANNEL_2
 * @param[in]  value    DAC channel digital value. 
 *
 * @api
 */
void dac_set_value(dac_driver_t *ddp, dac_channel_t channel, uint32_t value);

/**
 * @brief   Sets DAC dedicated channel software trigger flag.
 * @note    It must be invoked after dac_start, otherwise it doesn't not take
 *          effect.
 *
 * @param[out] ddp      pointer to a @p dac_driver_t structure
 * @param[in] channel   DAC dedicated channel to be configured. It can be one
 *                      of the following values:
 *            @arg @ref DAC_CHANNEL_1
 *            @arg @ref DAC_CHANNEL_2
 * @param[in]  flag     DAC software trigger to be configured. It can be one of
 *                      the following values:
 *            @arg @ref SET_TRIGGER_FLAG
 *            @arg @ref SET_INC_TRIGGER_FLAG
 *
 * @api
 */
void dac_set_sw_trigger(dac_driver_t *ddp, dac_channel_t channel,
                        dac_sw_trigger_t sw_trigger);

/**
 * @brief   Sets DAC dedicated channel noise wave mask.
 * @note    It must be invoked after dac_start, otherwise it doesn't not take
 *          effect.
 *
 * @param[out] ddp      pointer to a @p dac_driver_t structure
 * @param[in] channel   DAC dedicated channel to be configured. It can be one
 *                      of the following values:
 *            @arg @ref DAC_CHANNEL_1
 *            @arg @ref DAC_CHANNEL_2
 * @param[in] mask      DAC noise wave mask to be configured. It can be one of
 *                      the following values:
 *            @arg @ref DAC_LFSR_TRIANGLE_MASK0
 *            @arg @ref DAC_LFSR_TRIANGLE_MASK1
 *            @arg @ref DAC_LFSR_TRIANGLE_MASK2
 *            @arg @ref DAC_LFSR_TRIANGLE_MASK3
 *            @arg @ref DAC_LFSR_TRIANGLE_MASK4
 *            @arg @ref DAC_LFSR_TRIANGLE_MASK5
 *            @arg @ref DAC_LFSR_TRIANGLE_MASK6
 *            @arg @ref DAC_LFSR_TRIANGLE_MASK7
 *            @arg @ref DAC_LFSR_TRIANGLE_MASK8
 *            @arg @ref DAC_LFSR_TRIANGLE_MASK9
 *            @arg @ref DAC_LFSR_TRIANGLE_MASK10
 *            @arg @ref DAC_LFSR_TRIANGLE_MASK11
 *            @arg @ref DAC_LFSR_TRIANGLE_MASK12
 *            @arg @ref DAC_LFSR_TRIANGLE_MASK13
 *            @arg @ref DAC_LFSR_TRIANGLE_MASK14
 *            @arg @ref DAC_LFSR_TRIANGLE_MASK15
 *
 * @api
 */
void dac_noise_generation(dac_driver_t *ddp, dac_channel_t channel, 
                          dac_lfsr_triangle_mask_t mask);

/**
 * @brief   Sets DAC dedicated channel triangle wave mask.
 * @note    It must be invoked after dac_start, otherwise it doesn't not take
 *          effect.
 *
 * @param[out] ddp      pointer to a @p dac_driver_t structure
 * @param[in] channel   DAC dedicated channel to be configured. It can be one
 *                      of the following values:
 *            @arg @ref DAC_CHANNEL_1
 *            @arg @ref DAC_CHANNEL_2
 * @param[in]  mask     DAC triangle wave mask to be configured. It can be one
 *                      of the following values:
 *            @arg @ref DAC_LFSR_TRIANGLE_MASK0
 *            @arg @ref DAC_LFSR_TRIANGLE_MASK1
 *            @arg @ref DAC_LFSR_TRIANGLE_MASK2
 *            @arg @ref DAC_LFSR_TRIANGLE_MASK3
 *            @arg @ref DAC_LFSR_TRIANGLE_MASK4
 *            @arg @ref DAC_LFSR_TRIANGLE_MASK5
 *            @arg @ref DAC_LFSR_TRIANGLE_MASK6
 *            @arg @ref DAC_LFSR_TRIANGLE_MASK7
 *            @arg @ref DAC_LFSR_TRIANGLE_MASK8
 *            @arg @ref DAC_LFSR_TRIANGLE_MASK9
 *            @arg @ref DAC_LFSR_TRIANGLE_MASK10
 *            @arg @ref DAC_LFSR_TRIANGLE_MASK11
 *            @arg @ref DAC_LFSR_TRIANGLE_MASK12
 *            @arg @ref DAC_LFSR_TRIANGLE_MASK13
 *            @arg @ref DAC_LFSR_TRIANGLE_MASK14
 *            @arg @ref DAC_LFSR_TRIANGLE_MASK15
 *
 * @api
 */
void dac_triangle_generation(dac_driver_t *ddp, dac_channel_t channel,
                             dac_lfsr_triangle_mask_t mask); 

/**
 * @brief   Sets DAC dedicated channel sawtooth wave parameters.
 * @note    It must be invoked after dac_start, otherwise it doesn't not take
 *          effect.
 *
 * @param[out] ddp      pointer to a @p dac_driver_t structure
 * @param[in] channel   DAC dedicated channel to be configured. It can be one
 *                      of the following values:
 *            @arg @ref DAC_CHANNEL_1
 *            @arg @ref DAC_CHANNEL_2
 * @param[in] init_value DAC sawtooth wave init value to be configured. 
 * @param[in] inc_value  DAC sawtooth wave increment value to be configured. 
 * @param[in] direction  DAC sawtooth wave direction to be configured; '0' for
 *                       decrement, '1' for increment.
 *
 * @api
 */
void dac_sawtooth_generation(dac_driver_t *ddp, dac_channel_t channel,
                             uint32_t init_value, uint32_t inc_value,
                             uint8_t direction);

/**
 * @brief   Configure DAC dedicated channel trimming.
 * @note    It must be invoked after dac_start, otherwise it doesn't not take
 *          effect.
 *
 * @param[out] ddp      pointer to a @p dac_driver_t structure
 * @param[in] channel   DAC dedicated channel to trimm. It can be one of the
 *                      following values:
 *            @arg @ref DAC_CHANNEL_1
 *            @arg @ref DAC_CHANNEL_2
 *
 * @api
 */
void dac_user_trimming(dac_driver_t *ddp, dac_channel_t channel);

/**
 * @brief   Stops a DAC instance.
 *
 * @param[in] ddp       pointer to an @p dac_driver_t structure
 *
 * @api
 */
void dac_stop(dac_driver_t *ddp);

/**
 * @brief   De-initializes a DAC instance.
 *
 * @param[out] ddp      pointer to an @p dac_driver_t structure
 *
 * @api
 */
void dac_deinit(dac_driver_t *ddp);

/**
 * @brief   Serves a DAC interrupt.
 * @note    Not an API, used internally.
 *
 * @param[in] ddp       pointer to an @p dac_driver_t structure
 *
 * @isr
 */
void __dac_serve_interrupt(dac_driver_t *ddp);

#ifdef __cplusplus
}
#endif

#endif /* _DAC_H_ */

/** @} */
