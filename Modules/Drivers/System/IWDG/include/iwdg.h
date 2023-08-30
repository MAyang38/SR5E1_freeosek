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
 * @file    iwdg.h
 * @brief   IWDG driver header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup SYSTEM
 * @ingroup DRIVERS
 * @addtogroup IWDG
 * @ingroup SYSTEM
 * @{
 */

#ifndef _IWDG_H_
#define _IWDG_H_

#include <typedefs.h>

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

/**
 * @name    IWDG Key Register BitMask.
 * @{
 */
#define IWDG_KEY_RELOAD                     0xAAAAU    /**< IWDG Reload Counter Enable                                                    */
#define IWDG_KEY_ENABLE                     0xCCCCU    /**< IWDG Peripheral Enable                                                        */
#define IWDG_KEY_WRITE_ACCESS_ENABLE        0x5555U    /**< IWDG KR Write Access Enable to the IWDG_PR, IWDG_RLR and IWDG_WINR registers  */
#define IWDG_KEY_WRITE_ACCESS_DISABLE       0x0000U    /**< IWDG KR Write Access Disable to the IWDG_PR, IWDG_RLR and IWDG_WINR registers */
/** @} */

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
 * @brief   Type of an IWDG driver.
 */
typedef struct iwdg_driver iwdg_driver_t;

/**
 * @enum iwdg_prescaler_t
 * IWDG supported prescaler values.
 */
typedef enum {
    IWDG_PRESCALER_DIV4   = 0U,        /**< IWDG counter clock = (HSICLK)/4   */
    IWDG_PRESCALER_DIV8   = 1U,        /**< IWDG counter clock = (HSICLK)/8   */
    IWDG_PRESCALER_DIV16  = 2U,        /**< IWDG counter clock = (HSICLK)/16  */
    IWDG_PRESCALER_DIV32  = 3U,        /**< IWDG counter clock = (HSICLK)/32  */
    IWDG_PRESCALER_DIV64  = 4U,        /**< IWDG counter clock = (HSICLK)/64  */
    IWDG_PRESCALER_DIV128 = 5U,        /**< IWDG counter clock = (HSICLK)/128 */
    IWDG_PRESCALER_DIV256 = 6U         /**< IWDG counter clock = (HSICLK)/256 */
} iwdg_prescaler_t;

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

/* Export driver modules.*/
#include <iwdg_instances.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Initializes IWDG instance.
 *
 * @param[out] idp      pointer to a @p iwdg_driver_t structure
 *
 * @api
 */
void iwdg_init(iwdg_driver_t *idp);

/**
 * @brief   Configures IWDG prescaler.
 * @note    This configuration becomes effective after iwdg_start.
 *
 * @param[out] idp      pointer to a @p iwdg_driver_t structure
 * @param[in] prescaler prescaler to be set. It can be one of the following
 *                      values:
 *            @arg @ref IWDG_PRESCALER_DIV4  
 *            @arg @ref IWDG_PRESCALER_DIV8  
 *            @arg @ref IWDG_PRESCALER_DIV16 
 *            @arg @ref IWDG_PRESCALER_DIV32 
 *            @arg @ref IWDG_PRESCALER_DIV64 
 *            @arg @ref IWDG_PRESCALER_DIV128
 *            @arg @ref IWDG_PRESCALER_DIV256
 * @return              previos prescaler value. It can be one of the following
 *                      values:
 *            @arg @ref IWDG_PRESCALER_DIV4  
 *            @arg @ref IWDG_PRESCALER_DIV8  
 *            @arg @ref IWDG_PRESCALER_DIV16 
 *            @arg @ref IWDG_PRESCALER_DIV32 
 *            @arg @ref IWDG_PRESCALER_DIV64 
 *            @arg @ref IWDG_PRESCALER_DIV128
 *            @arg @ref IWDG_PRESCALER_DIV256
 *
 * @api
 */
iwdg_prescaler_t iwdg_set_prescaler(iwdg_driver_t *idp,
                                    iwdg_prescaler_t prescaler);

/**
 * @brief   Configures IWDG counter value.
 * @note    This configuration becomes effective after iwdg_start.
 *
 * @param[out] idp      pointer to a @p iwdg_driver_t structure
 * @param[in] counter   counter to be configured. It must be in the range 
 *                      [0x0:0xFFF]. Min-max timeout value @16MHz (HSI):
 *                      ~25us / ~65.5ms
 * @return              previous counter value.
 *
 * @api
 */
uint16_t iwdg_set_counter(iwdg_driver_t *idp, uint16_t counter);

/**
 * @brief   Configures IWDG window.
 * @note    This configuration becomes effective after iwdg_start.
 *
 * @param[out] idp      pointer to a @p iwdg_driver_t structure
 * @param[in] window    window to be configured. It must be in the range
 *                      [0x0:0xFFF]. Min-max timeout value @16MHz (HSI):
 *                      ~25us / ~65.5ms
 * @return              previous counter value.
 *
 * @api
 */
uint16_t iwdg_set_window(iwdg_driver_t *idp, uint16_t window);

/**
 * @brief   Starts IWDG instance.
 *
 * @param[in] idp       pointer to a @p iwdg_driver_t structure
 *
 * @api
 */
void iwdg_start(iwdg_driver_t *idp);

/**
 * @brief   Refreshs IWDG counter.
 *
 * @param[in] idp       pointer to a @p iwdg_driver_t structure
 *
 * @api
 */
void iwdg_refresh(iwdg_driver_t *idp);

/**
 * @brief   Stops IWDG instance.
 *
 * @param[in] idp       pointer to a @p iwdg_driver_t structure
 *
 * @api
 */
void iwdg_stop(iwdg_driver_t *idp);

/**
 * @brief   Deinitializes IWDG instance.
 *
 * @param[out] idp       pointer to a @p iwdg_driver_t structure
 *
 * @api
 */
void iwdg_deinit(iwdg_driver_t *idp);

#ifdef __cplusplus
}
#endif

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/*===========================================================================*/
/* Module late inclusions.                                                   */
/*===========================================================================*/

#endif /* _IWDG_H_ */

/** @} */
