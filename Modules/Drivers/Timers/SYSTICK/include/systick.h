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
 * @file    systick.h
 * @brief   SYSTICK driver header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup TIMERS
 * @ingroup DRIVERS
 * @addtogroup SYSTICK
 * @ingroup TIMERS
 * @{
 */

#ifndef _SYSTICK_H_
#define _SYSTICK_H_

#include <irq.h>
#include <platform.h>
#include <typedefs.h>

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

/**
 * @brief   SysTick maximum reload value. SysTick is a 24-bit timer.
 */
#define SYSTICK_MAX_RELVAL                  0xFFFFFFU

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
 * @brief   Type of a SYSTICK driver.
 */
typedef struct systick_driver systick_driver_t;

/**
 * @brief   Type of SYSTICK callback.
 *
 * @param[in] sdp       pointer to the @p systick_driver_t object
 */
typedef void (*systick_cb_t)(systick_driver_t *sdp);

/**
 * @brief   SYSTICK driver structure.
 * @note    This structure is internal to the SYSTICK driver.
 */
struct systick_driver {
    /**
     * @brief   Pointer to SYSTICK registers block.
     */
    SysTick_Type             *systick;
    /**
     * @brief   SYSTICK interrupt priority.
     */
    uint32_t                 prio;
    /**
     * @brief   SYSTICK frequency (MHz).
     */
    uint32_t                 freq;
    /**
     * @brief   SYSTICK reload value (24bit).
     */
    uint32_t                 relval;
    /**
     * @brief   SYSTICK overflow counter.
     */
    volatile uint32_t        overflow_cnt;
    /**
     * @brief   Pointers to SYSTICK callback function.
     * @note    Set to @p NULL if not required.
     */
    systick_cb_t             cb;
};

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

extern systick_driver_t DRV_SYSTICK;

#ifdef __cplusplus
extern "C" {
#endif
/**
 * @brief   Initializes SYSTICK instance.
 *
 * @param[out] sdp      pointer to a @p systick_driver_t structure
 *
 * @api
 */
void systick_init(systick_driver_t *sdp);

/**
 * @brief   Configures SYSTICK interrupt priority.
 * @note    This configuration becomes effective after systick_start.
 *
 * @param[out] sdp      pointer to a @p systick_driver_t structure
 * @param[in] prio      interrupt priority to be configured
 * @return              previous interrupt priority.
 *
 * @api
 */
uint32_t systick_set_prio(systick_driver_t *sdp, uint32_t prio);

/**
 * @brief   Configures SYSTICK reload value.
 * @note    This configuration becomes effective after systick_start.
 *
 * @param[out] sdp      pointer to a @p systick_driver_t structure
 * @param[in] relval    reload value to be configured
 * @return              previous reload value.
 *
 * @api
 */
uint32_t systick_set_relval(systick_driver_t *sdp, uint32_t relval);

/**
 * @brief   Configures pointers to SYSTICK callback function.
 *
 * @param[out] sdp      pointer to a @p systick_driver_t structure
 * @param[in] cb        pointer to SYSTICK callback function
 * @return              pointer to previuos SYSTICK callback function.
 *
 * @api
 */
systick_cb_t systick_set_cb(systick_driver_t *sdp, systick_cb_t cb);

/**
 * @brief   Starts an SYSTICK instance.
 *
 * @param[out] sdp      pointer to a @p systick_driver_t structure
 *
 * @api
 */
void systick_start(systick_driver_t *sdp);

/**
 * @brief   Returns the current number of ticks
 *
 * @param[in] sdp       pointer to a @p systick_driver_t structure
 * @return              current number of ticks
 *
 * @api
 */
uint64_t systick_get_ticks(systick_driver_t *sdp);

/**
 * @brief   Delays execution by specified amount of seconds
 * @details This function sets a delay (busy wait) for the specified amount of
 *          seconds.
 *
 * @param[in] sdp       pointer to a @p systick_driver_t structure
 * @param[in] sec       delay time (in seconds)
 *
 * @api
 */
void systick_delay_sec(systick_driver_t *sdp, uint32_t sec);


/**
 * @brief   Delays execution by specified amount of milliseconds
 * @details This function sets a delay (busy wait) for the specified amount of
 *          milliseconds.
 *
 * @param[in] sdp       pointer to a @p systick_driver_t structure
 * @param[in] msec      delay time (in milliseconds)
 *
 * @api
 */
void systick_delay_millisec(systick_driver_t *sdp, uint32_t msec);

/**
 * @brief   Delays execution by specified amount of microseconds
 * @details This function sets a delay (busy wait) for the specified amount of
 *          microseconds.
 *
 * @param[in] sdp       pointer to a @p systick_driver_t structure
 * @param[in] usec      delay time (in microseconds)
 *
 * @api
 */
void systick_delay_microsec(systick_driver_t *sdp, uint32_t usec);

/**
 * @brief   Delays execution by specified amount of nanoseconds
 * @details This function sets a delay (busy wait) for the specified amount of
 *          nanoseconds.
 *
 * @param[in] sdp       pointer to a @p systick_driver_t structure
 * @param[in] nsec      delay time (in nanoseconds)
 *
 * @api
 */
void systick_delay_nanosec(systick_driver_t *sdp, uint32_t nsec);

/**
 * @brief   Converts number of ticks into seconds
 *
 * @param[in] sdp       pointer to a @p systick_driver_t structure
 * @param[in] ticks     number of ticks
 * @return              number of seconds
 *
 * @api
 */
uint32_t systick_tk2s(systick_driver_t *sdp, uint64_t ticks);

/**
 * @brief   Converts number of ticks into milliseconds
 *
 * @param[in] sdp       pointer to a @p systick_driver_t structure
 * @param[in] ticks     number of ticks
 * @return              number of milliseconds
 *
 * @api
 */
uint32_t systick_tk2ms(systick_driver_t *sdp, uint64_t ticks);

/**
 * @brief   Converts number of ticks into microseconds
 *
 * @param[in] sdp       pointer to a @p systick_driver_t structure
 * @param[in] ticks     number of ticks
 * @return              number of microseconds
 *
 * @api
 */
uint32_t systick_tk2us(systick_driver_t *sdp, uint64_t ticks);

/**
 * @brief   Converts number of ticks into nanoseconds
 *
 * @param[in] sdp       pointer to a @p systick_driver_t structure
 * @param[in] ticks     number of ticks
 * @return              number of nanoseconds
 *
 * @api
 */
uint32_t systick_tk2ns(systick_driver_t *sdp, uint64_t ticks);

#ifdef __cplusplus
}
#endif

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

#endif /* _SYSTICK_H_ */
