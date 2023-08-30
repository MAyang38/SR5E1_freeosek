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
 * @file    wwdg.h
 * @brief   WWDG driver header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup SYSTEM
 * @ingroup DRIVERS
 * @addtogroup WWDG
 * @ingroup SYSTEM
 * @{
 */

#ifndef _WWDG_H_
#define _WWDG_H_

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
 * @brief   Type of an WWDG driver.
 */
typedef struct wwdg_driver wwdg_driver_t;

/**
 * @enum wwdg_prescaler_t
 * WWDG supported prescaler values.
 */
typedef enum {
    WWDG_PRESCALER_DIV1   = 0U,        /**< WWDG counter clock = (PCLK1/4096)/1   */
    WWDG_PRESCALER_DIV2   = 1U,        /**< WWDG counter clock = (PCLK1/4096)/2   */
    WWDG_PRESCALER_DIV4   = 2U,        /**< WWDG counter clock = (PCLK1/4096)/4   */
    WWDG_PRESCALER_DIV8   = 3U,        /**< WWDG counter clock = (PCLK1/4096)/8   */
    WWDG_PRESCALER_DIV16  = 4U,        /**< WWDG counter clock = (PCLK1/4096)/16  */
    WWDG_PRESCALER_DIV32  = 5U,        /**< WWDG counter clock = (PCLK1/4096)/32  */
    WWDG_PRESCALER_DIV64  = 6U,        /**< WWDG counter clock = (PCLK1/4096)/64  */
    WWDG_PRESCALER_DIV128 = 7U         /**< WWDG counter clock = (PCLK1/4096)/128 */
} wwdg_prescaler_t;

/**
 * @brief   Type of WWDG callbacks.
 *
 * @param[in] wdp       pointer to the @p wwdg_driver_t object
 */
typedef void (*wwdg_cb_t)(wwdg_driver_t *wdp);

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

/* Export driver modules.*/
#include <wwdg_instances.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Initializes WWDG instance.
 *
 * @param[out] wdp      pointer to a @p wwdg_driver_t structure
 *
 * @api
 */
void wwdg_init(wwdg_driver_t *wdp);

/**
 * @brief   Configures WWDG interrupt priority.
 * @note    This configuration becomes effective after wwdg_start.
 *
 * @param[out] wdp      pointer to a @p wwdg_driver_t structure
 * @param[in] prio      interrupt priority to be configured
 * @return              previous interrupt priority.
 *
 * @api
 */
uint32_t wwdg_set_prio(wwdg_driver_t *wdp, uint32_t prio);

/**
 * @brief   Configures WWDG prescaler.
 * @note    This configuration becomes effective after wwdg_start.
 *
 * @param[out] wdp      pointer to a @p wdg_driver_t structure
 * @param[in] prescaler prescaler to be set. It can be one of the following
 *                      values:
 *            @arg @ref WWDG_PRESCALER_DIV1
 *            @arg @ref WWDG_PRESCALER_DIV2
 *            @arg @ref WWDG_PRESCALER_DIV4
 *            @arg @ref WWDG_PRESCALER_DIV8
 *            @arg @ref WWDG_PRESCALER_DIV16
 *            @arg @ref WWDG_PRESCALER_DIV32
 *            @arg @ref WWDG_PRESCALER_DIV64
 *            @arg @ref WWDG_PRESCALER_DIV128
 * @return              previos prescaler value. It can be one of the following
 *                      values:
 *            @arg @ref WWDG_PRESCALER_DIV1
 *            @arg @ref WWDG_PRESCALER_DIV2
 *            @arg @ref WWDG_PRESCALER_DIV4
 *            @arg @ref WWDG_PRESCALER_DIV8
 *            @arg @ref WWDG_PRESCALER_DIV16
 *            @arg @ref WWDG_PRESCALER_DIV32
 *            @arg @ref WWDG_PRESCALER_DIV64
 *            @arg @ref WWDG_PRESCALER_DIV128
 *
 * @api
 */
wwdg_prescaler_t wwdg_set_prescaler(wwdg_driver_t *wdp,
                                    wwdg_prescaler_t prescaler);

/**
 * @brief   Configures WWDG counter value.
 * @note    This configuration becomes effective after wwdg_start.
 *
 * @param[out] wdp      pointer to a @p wwdg_driver_t structure
 * @param[in] counter   counter to be configured. It must be in the range
 *                      [0x40:0x7F]
 * @return              previous counter value.
 *
 * @api
 */
uint16_t wwdg_set_counter(wwdg_driver_t *wdp, uint16_t counter);

/**
 * @brief   Configures WWDG window.
 * @note    This configuration becomes effective after wwdg_start.
 *
 * @param[out] wdp      pointer to a @p wwdg_driver_t structure
 * @param[in] window    window to be configured. It must be in the range
 *                      [0x40:0x7F]
 * @return              previous counter value.
 *
 * @api
 */
uint16_t wwdg_set_window(wwdg_driver_t *wdp, uint16_t window);

/**
 * @brief   Enables/Disables WWDG erly wakeup interrupt.
 * @note    This configuration becomes effective after wwdg_start.
 *
 * @param[out] wdp      pointer to a @p wwdg_driver_t structure
 * @param[in] enable    early wakeup interrupt enable flag ("true" means the
 *                      the wakeup interrupt is enabled, "false" otherwise)
 * @return              previous counter wakeup interrupt enable flag.
 *
 * @api
 */
bool wwdg_set_is_ewk_irq_en(wwdg_driver_t *wdp, bool enable);

/**
 * @brief   Configures pointers to WWDG callback function.
 *
 * @param[out] wdp      pointer to a @p wdg_driver_t structure
 * @param[in] cb        pointer to WWDG callback function
 * @return              pointer to previuos WWDG callback function.
 *
 * @api
 */
wwdg_cb_t wwdg_set_cb(wwdg_driver_t *wdp, wwdg_cb_t cb);

/**
 * @brief   Starts WWDG instance.
 *
 * @param[in] wdp       pointer to a @p wwdg_driver_t structure
 *
 * @api
 */
void wwdg_start(wwdg_driver_t *wdp);

/**
 * @brief   Refreshs WWDG counter.
 *
 * @param[in] wdp       pointer to a @p wwdg_driver_t structure
 *
 * @api
 */
void wwdg_refresh(wwdg_driver_t *wdp);

/**
 * @brief   Stops WWDG instance.
 *
 * @param[in] wdp       pointer to a @p wwdg_driver_t structure
 *
 * @api
 */
void wwdg_stop(wwdg_driver_t *wdp);

/**
 * @brief   Deinitializes WWDG instance.
 *
 * @param[out] wdp      pointer to a @p wwdg_driver_t structure
 *
 * @api
 */
void wwdg_deinit(wwdg_driver_t *wdp);

/**
 * @brief   Shared interrupt handler.
 * @note    Not an API, used internally.
 * @note    The early wakeup interrupt is generated whenever the ounter reaches
 *          the value 0x40. This interrupt is only cleared by hardware after a
 *          reset.
 *
 * @param[in] wdp       pointer to a @p wwdg_driver_t structure
 *
 * @isr
 */
void __wwdg_serve_interrupt(wwdg_driver_t *wdp);

#ifdef __cplusplus
}
#endif

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/*===========================================================================*/
/* Module late inclusions.                                                   */
/*===========================================================================*/

#endif /* _WWDG_H_ */

/** @} */
