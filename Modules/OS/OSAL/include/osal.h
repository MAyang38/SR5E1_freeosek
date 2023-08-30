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
 * @file    osal.h
 * @brief   Operating System Abstraction Layer module header file.
 *
 * @addtogroup OS
 * @addtogroup OSAL
 * @ingroup OS
 * @{
 */

#ifndef _OSAL_H_
#define _OSAL_H_

#include <osal_cfg.h>
#include <irq.h>
#include <platform.h>
#include <typedefs.h>

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

/** 
 * @name OSAL Tick Frequency macros
 * @{
 */
#define OSAL_TICKS_PER_SEC_1000     1000U /* 1000 ticks per second -> 1 tick per ms */
#define OSAL_TICKS_PER_SEC_100      100U  /* 100  ticks per second -> 1 tick per 10ms */
#define OSAL_TICKS_PER_SEC_10       10U   /* 10   ticks per second -> 1 tick per 100ms */
#define OSAL_TICKS_PER_SEC_1        1U    /* 1    tick  per second -> 1 tick per sec */
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

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/**
 * @name    Debug macros
 * @{
 */

/**
 * @brief   Dummy condition assertion
 *
 * @param[in] c         condition to be verified
 * @param[in] r         remark string
 *
 * @api
 */
#define osal_dbg_assert(c, s) (void)(c)

/**
 * @brief   Condition assertion
 * @details If the condition check fails, the system halts. The remark string
 *          currently is not used.
 *
 * @param[in] c         condition to be verified
 * @param[in] r         remark string
 *
 * @api
 */
#if !defined(osal_dbg_assert)
#define osal_dbg_assert(c, r) do {                                          \
    if (!(c)) {                                                             \
        osal_sys_halt();                                                    \
    }                                                                       \
} while (0)
#endif /* !defined(osal_dbg_assert) */

/** @} */

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Initializes OSAL layer
 *
 * @api
 */
void osal_init(void);

/**
 * @brief   Returns the current number of ticks
 *
 * @return              current number of ticks
 *
 * @api
 */


void osal_inc_tick(void);
uint32_t osal_get_tick(void);

/**
 * @brief   Delays execution by specified amount of seconds
 * @details This function sets a delay (busy wait) for the specified amount of
 *          seconds.
 *
 * @param[in] sec       delay time (in seconds)
 *
 * @api
 */
void osal_delay_sec(uint32_t sec);

/**
 * @brief   Delays execution by specified amount of milliseconds
 * @details This function sets a delay (busy wait) for the specified amount of
 *          milliseconds.
 *
 * @param[in] msec      delay time (in milliseconds)
 *
 * @api
 */
void osal_delay_millisec(uint32_t msec);

/**
 * @brief   Delays execution by specified amount of microseconds
 * @details This function sets a delay (busy wait) for the specified amount of
 *          microseconds.
 *
 * @param[in] usec      delay time (in microseconds)
 *
 * @api
 */
void osal_delay_microsec(uint32_t usec);

/**
 * @brief   Converts number of ticks into seconds
 *
 * @param[in] ticks     number of ticks
 * @return              number of seconds
 *
 * @api
 */
uint32_t osal_tk2s(uint32_t ticks);

/**
 * @brief   Converts number of ticks into milliseconds
 *
 * @param[in] ticks     number of ticks
 * @return              number of milliseconds
 *
 * @api
 */
uint32_t osal_tk2ms(uint32_t ticks);

/**
 * @brief   Converts number of ticks into microseconds
 *
 * @param[in] ticks     number of ticks
 * @return              number of microseconds
 *
 * @api
 */
uint32_t osal_tk2us(uint32_t ticks);

#ifdef __cplusplus
}
#endif

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/**
 * @brief   Enters into a critical zone
 *
 * @api
 */
__STATIC_FORCEINLINE void osal_sys_lock(void) {

    irq_disable_all();
}

/**
 * @brief   Leaves a critical zone
 *
 * @api
 */
__STATIC_FORCEINLINE void osal_sys_unlock(void) {

    irq_enable_all();
}

/**
 * @brief   Enters into a critical zone from ISR
 *
 * @api
 */
__STATIC_FORCEINLINE void osal_sys_lock_from_isr(void) {

    irq_disable_all();
}

/**
 * @brief   Leaves a critical zone from ISR
 *
 * @api
 */
__STATIC_FORCEINLINE void osal_sys_unlock_from_isr(void) {

    irq_enable_all();
}

/**
 * @brief   System halt 
 *
 * @api
 */
__STATIC_FORCEINLINE void osal_sys_halt(void) {

    irq_disable_all();

    /* Infinite loop.*/
    while (true) {
    }
}

#endif /* _OSAL_H_ */
