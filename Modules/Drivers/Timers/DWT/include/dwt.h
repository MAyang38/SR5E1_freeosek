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
 * @file    dwt.h
 * @brief   DWT driver header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup TIMERS
 * @ingroup DRIVERS
 * @addtogroup DWT
 * @ingroup TIMERS
 * @{
 */

#ifndef _DWT_H_
#define _DWT_H_

#include <clock.h>
#include <platform.h>
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

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/**
 * @brief   Returns the number of ticks of DWT
 * @details This functionaly is related to a macro instead of a function in
 *          order to reduce the impact of code on timer measurament.
 *
 * @return              number of ticks
 *
 * @api
 */
#define dwt_get_ticks()                                                        \
    ((uint32_t)(DWT->CYCCNT))

/**
 * @brief   Reset DWT instance.
 * @details This functionaly is related to a macro instead of a function in
 *          order to reduce the impact of code on timer measurament.
 *
 * @api
 */
#define dwt_reset()                                                            \
    (DWT->CYCCNT = 0U)

/**
 * @brief   Delays execution by specified amount of ticks
 * @details This functionaly is related to a macro instead of a function in
 *          order to reduce the impact of code on timer measurament.
 *
 * @param[in] ticks     number of ticks to delay
 *
 * @api
 */
#define dwt_delay_ticks(_ticks_)                                               \
    do {                                                                       \
        uint32_t start_tick = dwt_get_ticks();                                 \
        while (dwt_get_ticks() < start_tick + _ticks_) {                       \
            ;                                                                  \
        }                                                                      \
    } while(0);

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Initializes DWT instance.
 *
 * @api
 */
void dwt_init(void);

/**
 * @brief   Converts seconds into number of ticks
 *
 * @param[in] sec       number of seconds
 * @return              number of ticks
 *
 * @api
 */
uint32_t dwt_s2t(uint32_t sec);

/**
 * @brief   Converts milliseconds into number of ticks
 *
 * @param[in] msec      number of milliseconds
 * @return              number of ticks
 *
 * @api
 */
uint32_t dwt_ms2t(uint32_t msec);

/**
 * @brief   Converts microseconds into number of ticks
 *
 * @param[in] usec      number of microseconds
 * @return              number of ticks
 *
 * @api
 */
uint32_t dwt_us2t(uint32_t usec);

/**
 * @brief   Converts nanoseconds into number of ticks
 *
 * @param[in] nsec      number of nanoseconds
 * @return              number of ticks
 *
 * @api
 */
uint32_t dwt_ns2t(uint32_t nsec);

/**
 * @brief   Converts number of ticks into seconds
 *
 * @param[in] ticks     number of ticks
 * @return              number of seconds
 *
 * @api
 */
uint32_t dwt_t2s (uint32_t ticks);

/**
 * @brief   Converts number of ticks into milliseconds
 *
 * @param[in] ticks     number of ticks
 * @return              number of milliseconds
 *
 * @api
 */
uint32_t dwt_t2ms(uint32_t ticks);

/**
 * @brief   Converts number of ticks into microseconds
 *
 * @param[in] ticks     number of ticks
 * @return              number of microseconds
 *
 * @api
 */
uint32_t dwt_t2us(uint32_t ticks);

/**
 * @brief   Converts number of ticks into nanoseconds
 *
 * @param[in] ticks     number of ticks
 * @return              number of nanoseconds
 *
 * @api
 */
uint32_t dwt_t2ns(uint32_t ticks);

/**
 * @brief   De-initializes DWT instance.
 *
 * @api
 */
void dwt_deinit(void);

#ifdef __cplusplus
}
#endif

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/*===========================================================================*/
/* Module late inclusions.                                                   */
/*===========================================================================*/

#endif /* _DWT_H_ */

/** @} */
