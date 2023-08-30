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
 * @file    sdadc.h
 * @brief   SDADC driver header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup ANALOG
 * @ingroup DRIVERS
 * @addtogroup SDADC
 * @ingroup ANALOG
 * @{
 */

#ifndef _SDADC_H_
#define _SDADC_H_

#include <typedefs.h>

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
 * @brief   Type of an SDADC driver.
 */
typedef struct sdadc_driver sdadc_driver_t;

/**
 * @brief   Type of an SDADC notification callback.
 *
 * @param[in] sdp       pointer to the @p sdadc_driver_t object
 */
typedef void (*sdadc_cb_t)(sdadc_driver_t *sdp);

/**
 * @enum sdadc_calibration_t
 * SDADC calibration configuration.
 */
typedef enum {
    SDADC_CALIBRATION_OFFSET,          /**< Offset calibration        */
    SDADC_CALIBRATION_GAIN,            /**< Gain calibration          */
    SDADC_CALIBRATION_BOTH,            /**< Offset + Gain calibration */
} sdadc_calibration_t;

/**
 * @enum sdadc_mode_t
 * SDADC mode configuration.
 */
typedef enum {
    SDADC_MODE_DIFFERENTIAL_INPUT,     /**< Differential input mode */
    SDADC_MODE_SINGLE_ENDED_INPUT,     /**< Single-ended input mode */
} sdadc_mode_t;

/**
 * @enum sdadc_vcomsel_t
 * SDADC common voltage bias selection configuration.
 */
typedef enum {
    SDADC_VCOMSEL_VREFN,               /**< Negative input terminal is biased with VREFN                     */
    SDADC_VCOMSEL_VREFPDIV2,           /**< Negative input terminal is biased with VREFP/2 (half-scale bias) */
} sdadc_vcomsel_t;

/**
 * @enum sdadc_anchsel_t
 * SDADC analog channel selection configuration.
 */
typedef enum {
    SDADC_ANCHSEL_0,                   /**< Analog channel selection = 0 */
    SDADC_ANCHSEL_1,                   /**< Analog channel selection = 1 */
    SDADC_ANCHSEL_2,                   /**< Analog channel selection = 2 */
    SDADC_ANCHSEL_3,                   /**< Analog channel selection = 3 */
    SDADC_ANCHSEL_4,                   /**< Analog channel selection = 4 */
    SDADC_ANCHSEL_5,                   /**< Analog channel selection = 5 */
    SDADC_ANCHSEL_6,                   /**< Analog channel selection = 6 */
    SDADC_ANCHSEL_7,                   /**< Analog channel selection = 7 */
} sdadc_anchsel_t;

/**
 * @enum sdadc_pdr_t
 * SDADC programmable decimation rate configuration.
 */
typedef enum {
    SDADC_PDR_24,                      /**< Programmable decimation rate = 24   */
    SDADC_PDR_28,                      /**< Programmable decimation rate = 28   */
    SDADC_PDR_32,                      /**< Programmable decimation rate = 32   */
    SDADC_PDR_36,                      /**< Programmable decimation rate = 36   */
    SDADC_PDR_40,                      /**< Programmable decimation rate = 40   */
    SDADC_PDR_44,                      /**< Programmable decimation rate = 44   */
    SDADC_PDR_48,                      /**< Programmable decimation rate = 48   */
    SDADC_PDR_56,                      /**< Programmable decimation rate = 56   */
    SDADC_PDR_64,                      /**< Programmable decimation rate = 64   */
    SDADC_PDR_72,                      /**< Programmable decimation rate = 72   */
    SDADC_PDR_75,                      /**< Programmable decimation rate = 75   */
    SDADC_PDR_80,                      /**< Programmable decimation rate = 80   */
    SDADC_PDR_88,                      /**< Programmable decimation rate = 88   */
    SDADC_PDR_96,                      /**< Programmable decimation rate = 96   */
    SDADC_PDR_112,                     /**< Programmable decimation rate = 112  */
    SDADC_PDR_128,                     /**< Programmable decimation rate = 128  */
    SDADC_PDR_144,                     /**< Programmable decimation rate = 144  */
    SDADC_PDR_160,                     /**< Programmable decimation rate = 160  */
    SDADC_PDR_176,                     /**< Programmable decimation rate = 176  */
    SDADC_PDR_192,                     /**< Programmable decimation rate = 192  */
    SDADC_PDR_224,                     /**< Programmable decimation rate = 224  */
    SDADC_PDR_256,                     /**< Programmable decimation rate = 256  */
    SDADC_PDR_512,                     /**< Programmable decimation rate = 512  */
    SDADC_PDR_1024,                    /**< Programmable decimation rate = 1024 */
} sdadc_pdr_t;

/**
 * @enum sdadc_pgain_t
 * SDADC programmable gain configuration.
 */
typedef enum {
    SDADC_PGAIN_1 = 0,                 /**< Programmable gain = 1  */
    SDADC_PGAIN_2 = 1,                 /**< Programmable gain = 2  */
    SDADC_PGAIN_4 = 2,                 /**< Programmable gain = 4  */
    SDADC_PGAIN_8 = 3,                 /**< Programmable gain = 8  */
    SDADC_PGAIN_16 = 7,                /**< Programmable gain = 16 */
} sdadc_pgain_t;

/**
 * @enum sdadc_fsize_t
 * SDADC FIFO size configuration.
 */
typedef enum {
    SDADC_FIFO_SIZE_1,                 /**< FIFO depth = 1 data word   */
    SDADC_FIFO_SIZE_4,                 /**< FIFO depth = 4 data words  */
    SDADC_FIFO_SIZE_8,                 /**< FIFO depth = 8 data words  */
    SDADC_FIFO_SIZE_16,                /**< FIFO depth = 16 data words */
} sdadc_fsize_t;

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/**
 * @name    SDADC Mode selection initializer
 * @{
 */
#define SDADC_MCR_MODE(_x_)                                          \
    ((((uint32_t)(_x_)) << SDADC_SDADC_MCR_MODE_Pos) & SDADC_SDADC_MCR_MODE)
/** @} */

/**
 * @name    SDADC Common Voltage Bias Selection initializer
 * @{
 */
#define SDADC_MCR_VCOMSEL(_x_)                                       \
    ((((uint32_t)(_x_)) << SDADC_SDADC_MCR_VCOMSEL_Pos) & SDADC_SDADC_MCR_VCOMSEL)
/** @} */

/**
 * @name    SDADC Programmable Gain initializer
 * @{
 */
#define SDADC_MCR_PGAIN(_x_)                                         \
    ((((uint32_t)(_x_)) << SDADC_SDADC_MCR_PGAN_Pos) & SDADC_SDADC_MCR_PGAN)
/** @} */

/**
 * @name    SDADC Programmable Decimation Rate initializer
 * @{
 */
#define SDADC_MCR_PDR(_x_)                                           \
    ((((uint32_t)(_x_)) << SDADC_SDADC_MCR_PDR_Pos) & SDADC_SDADC_MCR_PDR)
/** @} */

/**
 * @name    SDADC Analog Channel Selection initializer
 * @{
 */
#define SDADC_CSR_ANCHSEL(_x_)                                       \
    ((((uint32_t)(_x_)) << SDADC_SDADC_CSR_ANCHSEL_Pos) & SDADC_SDADC_CSR_ANCHSEL)
/** @} */

/**
 * @name    SDADC Output Settling Delay initializer
 * @{
 */
#define SDADC_OSDR_OSD(_x_)                                          \
    ((((uint32_t)(_x_)) << SDADC_SDADC_OSDR_OSD_Pos) & SDADC_SDADC_OSDR_OSD)
/** @} */

/**
 * @name    SDADC FIFO Size initializer
 * @{
 */
#define SDADC_FCR_FSIZE(_x_)                                         \
    ((((uint32_t)(_x_)) << SDADC_SDADC_FCR_FSIZE_Pos) & SDADC_SDADC_FCR_FSIZE)
/** @} */

/**
 * @name    SDADC FIFO Threshold initializer
 * @{
 */
#define SDADC_FCR_THRESHOLD(_x_)                                     \
    ((((uint32_t)((_x_) - 1UL)) << SDADC_SDADC_FCR_FTHLD_Pos) & SDADC_SDADC_FCR_FTHLD)
/** @} */

/**
 * @name    SDADC Watchdog Lower Threshold Value initializer
 * @{
 */
#define SDADC_WTHHLR_THHL(_x_)                                       \
    ((((uint32_t)(_x_)) << SDADC_SDADC_WTHHLR_THRL_Pos) & SDADC_SDADC_WTHHLR_THRL)
/** @} */

/**
 * @name    DADC Watchdog Upper Threshold Value initializer
 * @{
 */
#define SDADC_WTHHLR_THHH(_x_)                                       \
    ((((uint32_t)(_x_)) << SDADC_SDADC_WTHHLR_THRH_Pos) & SDADC_SDADC_WTHHLR_THRH)
/** @} */

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

/* Export driver modules.*/
#include <sdadc_instances.h>


#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Initializes an SDADC instance.
 *
 * @param[out] sdp      pointer to an @p sdadc_driver_t structure
 *
 * @init
 */
void sdadc_init(sdadc_driver_t *sdp);

/**
 * @brief   Configures SDADC interrupt priority.
 * @note    This configuration becomes effective after sdadc_start.
 *
 * @param[in] sdp       pointer to an @p sdadc_driver_t structure
 * @param[in] prio      interrupt priority to be configured
 * @return              previous interrupt priority.
 *
 * @api
 */
uint32_t sdadc_set_prio(sdadc_driver_t *sdp, uint32_t prio);

/**
 * @brief   Sets ground reference.
 * @note    This configuration becomes effective after sdadc_start.
 *
 * @param[in] sdp       pointer to an @p sdadc_driver_t structure
 * @param[in] gnd_ref   ground reference value to be set
 * @return              previous ground reference value.
 *
 * @api
 */
float sdadc_set_ground(sdadc_driver_t *sdp, float gnd_ref);

/**
 * @brief   Returns ground reference.
 *
 * @param[in] sdp       pointer to an @p sdadc_driver_t structure
 * @return              Ground reference value.
 *
 * @api
 */
float sdadc_get_ground(sdadc_driver_t *sdp);

/**
 * @brief   Sets voltage reference.
 * @note    This configuration becomes effective after sdadc_start.
 *
 * @param[in] sdp       pointer to an @p sdadc_driver_t structure
 * @param[in] vol_ref   voltage reference value to be set
 * @return              previous voltage reference value.
 *
 * @api
 */
float sdadc_set_voltage(sdadc_driver_t *sdp, float vol_ref);

/**
 * @brief   Returns voltage reference.
 *
 * @param[in] sdp       pointer to an @p sdadc_driver_t structure
 * @return              Voltage reference value.
 *
 * @api
 */
float sdadc_get_voltage(sdadc_driver_t *sdp);

/**
 * @brief   Sets calibration type.
 * @note    This configuration becomes effective after sdadc_start.
 *
 * @param[in] sdp       pointer to an @p sdadc_driver_t structure
 * @param[in] calibration calibration type to be set. It can be one of the
 *                      following values:
 *            @arg @ref SDADC_CALIBRATION_OFFSET
 *            @arg @ref SDADC_CALIBRATION_GAIN
 *            @arg @ref SDADC_CALIBRATION_BOTH
 * @return              previous calibration type. It can be one of the
 *                      following values:
 *            @arg @ref SDADC_CALIBRATION_OFFSET
 *            @arg @ref SDADC_CALIBRATION_GAIN
 *            @arg @ref SDADC_CALIBRATION_BOTH
 *
 * @api
 */
sdadc_calibration_t sdadc_set_calibration(sdadc_driver_t *sdp,
                                          sdadc_calibration_t calibration);

/**
 * @brief   Sets mode.
 * @note    This configuration becomes effective after sdadc_start.
 *
 * @param[in] sdp       pointer to an @p sdadc_driver_t structure
 * @param[in] mode      mode to be set. It can be one of the following values:
 *            @arg @ref SDADC_MODE_DIFFERENTIAL_INPUT
 *            @arg @ref SDADC_MODE_SINGLE_ENDED_INPUT
 * @return              previous mode value. It can be one of the following
 *                      values:
 *            @arg @ref SDADC_MODE_DIFFERENTIAL_INPUT
 *            @arg @ref SDADC_MODE_SINGLE_ENDED_INPUT
 *
 * @api
 */
sdadc_mode_t sdadc_set_mode(sdadc_driver_t *sdp, sdadc_mode_t mode);

/**
 * @brief   Sets common voltage bias for single ended mode.
 * @note    This configuration becomes effective after sdadc_start.
 *
 * @param[in] sdp       pointer to an @p sdadc_driver_t structure
 * @param[in] bias      common voltate bias value to be set. It can be one of,
 *                      the following values:
 *            @arg @ref SDADC_VCOMSEL_VREFN
 *            @arg @ref SDADC_VCOMSEL_VREFPDIV2
 * @return              previous common voltage bias value. It can be one of
 *                      the following values:
 *            @arg @ref SDADC_VCOMSEL_VREFN
 *            @arg @ref SDADC_VCOMSEL_VREFPDIV2
 *
 * @api
 */
sdadc_vcomsel_t sdadc_set_common_bias(sdadc_driver_t *sdp, sdadc_vcomsel_t bias);

/**
 * @brief   Sets analog channel selection.
 * @note    This configuration becomes effective after sdadc_start.
 *
 * @param[in] sdp       pointer to an @p sdadc_driver_t structure
 * @param[in] anchsel   analog channel selection. It can be one of the
 *                      following values:
 *            @arg @ref SDADC_ANCHSEL_0
 *            @arg @ref SDADC_ANCHSEL_1
 *            @arg @ref SDADC_ANCHSEL_2
 *            @arg @ref SDADC_ANCHSEL_3
 *            @arg @ref SDADC_ANCHSEL_4
 *            @arg @ref SDADC_ANCHSEL_5
 *            @arg @ref SDADC_ANCHSEL_6
 *            @arg @ref SDADC_ANCHSEL_7
 * @return              previous analog channel selection. It can be one of
 *                      the following values:
 *            @arg @ref SDADC_ANCHSEL_0
 *            @arg @ref SDADC_ANCHSEL_1
 *            @arg @ref SDADC_ANCHSEL_2
 *            @arg @ref SDADC_ANCHSEL_3
 *            @arg @ref SDADC_ANCHSEL_4
 *            @arg @ref SDADC_ANCHSEL_5
 *            @arg @ref SDADC_ANCHSEL_6
 *            @arg @ref SDADC_ANCHSEL_7
 *
 * @api
 */
sdadc_anchsel_t sdadc_set_channel(sdadc_driver_t *sdp, sdadc_anchsel_t anchsel);

/**
 * @brief   Sets programmable decimation rate.
 * @note    This configuration becomes effective after sdadc_start.
 *
 * @param[in] sdp       pointer to an @p sdadc_driver_t structure
 * @param[in] pdr       Programmable decimation rate value to be set. It can be
 *                      one of the following values:
 *            @arg @ref SDADC_PDR_24
 *            @arg @ref SDADC_PDR_28
 *            @arg @ref SDADC_PDR_32
 *            @arg @ref SDADC_PDR_36
 *            @arg @ref SDADC_PDR_40
 *            @arg @ref SDADC_PDR_44
 *            @arg @ref SDADC_PDR_48
 *            @arg @ref SDADC_PDR_56
 *            @arg @ref SDADC_PDR_64
 *            @arg @ref SDADC_PDR_72
 *            @arg @ref SDADC_PDR_75
 *            @arg @ref SDADC_PDR_80
 *            @arg @ref SDADC_PDR_88
 *            @arg @ref SDADC_PDR_96
 *            @arg @ref SDADC_PDR_112
 *            @arg @ref SDADC_PDR_128
 *            @arg @ref SDADC_PDR_144
 *            @arg @ref SDADC_PDR_160
 *            @arg @ref SDADC_PDR_176
 *            @arg @ref SDADC_PDR_192
 *            @arg @ref SDADC_PDR_224
 *            @arg @ref SDADC_PDR_256
 *            @arg @ref SDADC_PDR_512
 *            @arg @ref SDADC_PDR_1024
 * @return              previous programmable decimation rate value. It can be
 *                      one of the following values:
 *            @arg @ref SDADC_PDR_24
 *            @arg @ref SDADC_PDR_28
 *            @arg @ref SDADC_PDR_32
 *            @arg @ref SDADC_PDR_36
 *            @arg @ref SDADC_PDR_40
 *            @arg @ref SDADC_PDR_44
 *            @arg @ref SDADC_PDR_48
 *            @arg @ref SDADC_PDR_56
 *            @arg @ref SDADC_PDR_64
 *            @arg @ref SDADC_PDR_72
 *            @arg @ref SDADC_PDR_75
 *            @arg @ref SDADC_PDR_80
 *            @arg @ref SDADC_PDR_88
 *            @arg @ref SDADC_PDR_96
 *            @arg @ref SDADC_PDR_112
 *            @arg @ref SDADC_PDR_128
 *            @arg @ref SDADC_PDR_144
 *            @arg @ref SDADC_PDR_160
 *            @arg @ref SDADC_PDR_176
 *            @arg @ref SDADC_PDR_192
 *            @arg @ref SDADC_PDR_224
 *            @arg @ref SDADC_PDR_256
 *            @arg @ref SDADC_PDR_512
 *            @arg @ref SDADC_PDR_1024
 *
 * @api
 */
sdadc_pdr_t sdadc_set_pdr(sdadc_driver_t *sdp, sdadc_pdr_t pdr);

/**
 * @brief   Sets programmable gain.
 * @note    This configuration becomes effective after sdadc_start.
 *
 * @param[in] sdp       pointer to an @p sdadc_driver_t structure
 * @param[in] pgain     Programmable gain value to be set. It can be one of the
 *                      following values:
 *            @arg @ref SDADC_PGAIN_1
 *            @arg @ref SDADC_PGAIN_2
 *            @arg @ref SDADC_PGAIN_4
 *            @arg @ref SDADC_PGAIN_8
 *            @arg @ref SDADC_PGAIN_16
 * @return              previous programmable gain value. It can be one of the
 *                      following values:
 *            @arg @ref SDADC_PGAIN_1
 *            @arg @ref SDADC_PGAIN_2
 *            @arg @ref SDADC_PGAIN_4
 *            @arg @ref SDADC_PGAIN_8
 *            @arg @ref SDADC_PGAIN_16
 *
 * @api
 */
sdadc_pgain_t sdadc_set_pgain(sdadc_driver_t *sdp, sdadc_pgain_t pgain);

/**
 * @brief   Enables high pass filter.
 * @note    This configuration becomes effective after sdadc_start.
 *
 * @param[in] sdp       pointer to an @p sdadc_driver_t structure
 * @return              previous high pass filter status (true if enabled,
 *                      false otherwise).
 *
 * @api
 */
bool sdadc_enable_highpass(sdadc_driver_t *sdp);

/**
 * @brief   Enables BIAS.
 *
 * @param[in] sdp       pointer to an @p sdadc_driver_t structure
 * @return              previous BIAS status (true if enabled, false otherwise).
 *
 * @api
 */
bool sdadc_enable_bias(sdadc_driver_t *sdp);

/**
 * @brief   Sets output settling delay.
 * @note    This configuration becomes effective after sdadc_start.
 *
 * @param[in] sdp       pointer to an @p sdadc_driver_t structure
 * @param[in] osd       Output settling delay value to be set
 * @return              previous output settling delay value.
 *
 * @api
 */
uint8_t sdadc_set_osd(sdadc_driver_t *sdp, uint8_t osd);

/**
 * @brief   Sets FIFO size.
 *
 * @param[in] sdp       pointer to an @p sdadc_driver_t structure
 * @param[in] fsize     Fifo size value to be set. It can be one of the
 *                      following values:
 *            @arg @ref SDADC_FIFO_SIZE_1
 *            @arg @ref SDADC_FIFO_SIZE_4
 *            @arg @ref SDADC_FIFO_SIZE_8
 *            @arg @ref SDADC_FIFO_SIZE_16
 * @return              previous FIFO size value. It can be one of the
 *                      following values:
 *            @arg @ref SDADC_FIFO_SIZE_1
 *            @arg @ref SDADC_FIFO_SIZE_4
 *            @arg @ref SDADC_FIFO_SIZE_8
 *            @arg @ref SDADC_FIFO_SIZE_16
 *
 * @api
 */
sdadc_fsize_t sdadc_set_fsize(sdadc_driver_t *sdp, sdadc_fsize_t fsize);

/**
 * @brief   Enables FIFO overwrite.
 * @note    This configuration becomes effective after sdadc_start.
 *
 * @param[in] sdp       pointer to an @p sdadc_driver_t structure
 * @return              previous FIFO overwrite status (true if enabled, false
 *                      otherwise).
 *
 * @api
 */
bool sdadc_enable_fifo_overwrite(sdadc_driver_t *sdp);

/**
 * @brief   Enables and configures FIFO full event interrupt.
 * @note    This configuration becomes effective after sdadc_start.
 *
 * @param[in] sdp            pointer to an @p sdadc_driver_t structure
 * @param[in] fifo_threshold FIFO threshold to generate FIFO full event.
 * @param[in] fifo_full_cb   FIFO full event callback
 *
 * @api
 */
void sdadc_enable_fifo_full_event(sdadc_driver_t *sdp, uint8_t fifo_threshold,
                                  sdadc_cb_t fifo_full_cb);

/**
 * @brief   Enables and configures FIFO overrun event interrupt.
 * @note    This configuration becomes effective after sdadc_start.
 *
 * @param[in] sdp             pointer to an @p sdadc_driver_t structure
 * @param[in] fifo_overrun_cb FIFO overrun event callback
 *
 * @api
 */
void sdadc_enable_fifo_overrun_event(sdadc_driver_t *sdp,
                                     sdadc_cb_t fifo_overrun_cb);

/**
 * @brief   Enables and configures watchdog event interrupt.
 * @note    This configuration becomes effective after sdadc_start.
 *
 * @param[in] sdp             pointer to an @p sdadc_driver_t structure
 * @param[in] watchdog_lowth  watchdog lower threshold value.
 * @param[in] watchdog_highth watchdog higher threshold value.
 * @param[in] watchdog_cb     watchdog event callback
 *
 * @api
 */
void sdadc_enable_watchdog_event(sdadc_driver_t *sdp, float watchdog_lowth,
                                 float watchdog_highth, sdadc_cb_t watchdog_cb);

/**
 * @brief   Starts an SDADC instance.
 *
 * @param[in] sdp       pointer to an @p sdadc_driver_t structure
 *
 * @api
 */
void sdadc_start(sdadc_driver_t *sdp);

/**
 * @brief   Starts an SDADC conversion.
 *
 * @param[in] sdp       pointer to an @p sdadc_driver_t structure
 *
 * @api
 */
void sdadc_start_conversion(sdadc_driver_t *sdp);

/**
 * @brief   Stops an SDADC ongoing conversion.
 *
 * @param[in] sdp       pointer to an @p sdadc_driver_t structure
 *
 * @api
 */
void sdadc_stop_conversion(sdadc_driver_t *sdp);

/**
 * @brief   Reads SDADC conversion value.
 *
 * @param[in] sdp       pointer to an @p sdadc_driver_t structure
 * @param[in] value     pointer to variable in which the converted value is
 *                      stored
 * @return              data validity (true if data is valid, false otherwise).
 *
 * @api
 */
bool sdadc_read(sdadc_driver_t *sdp, float *value);

/**
 * @brief   Returns SDADC offset calbration value.
 *
 * @param[in] sdp       pointer to an @p sdadc_driver_t structure
 * @return              Offset calibration value.
 *
 * @notapi
 */
float sdadc_get_offset_calibration(sdadc_driver_t *sdp);

/**
 * @brief   Returns gain calbration value.
 *
 * @param[in] sdp       pointer to an @p sdadc_driver_t structure
 * @return              Gain calibration value.
 *
 * @notapi
 */
float sdadc_get_gain_calibration(sdadc_driver_t *sdp);

/**
 * @brief   Stops an SDADC instance.
 *
 * @param[in] sdp       pointer to an @p sdadc_driver_t structure
 *
 * @api
 */
void sdadc_stop(sdadc_driver_t *sdp);

/**
 * @brief   De-initializes an SDADC instance.
 *
 * @param[out] sdp      pointer to an @p sdadc_driver_t structure
 *
 * @api
 */
void sdadc_deinit(sdadc_driver_t *sdp);

/**
 * @brief   Serves an SDADC interrupt.
 * @note    Not an API, used internally.
 *
 * @param[in] sdp       pointer to an @p sdadc_driver_t structure
 *
 * @isr
 */
void __sdadc_serve_interrupt(sdadc_driver_t *sdp);

#ifdef __cplusplus
}
#endif

#endif /* _SDADC_H_ */

/** @} */
