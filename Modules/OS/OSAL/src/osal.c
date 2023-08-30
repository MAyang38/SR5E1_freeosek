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
 * @file    osal.c
 * @brief   Operating System Abstraction Layer module source file.
 *
 * @addtogroup OS
 * @addtogroup OSAL
 * @ingroup OS
 * @{
 */

#include <osal.h>
#include <clock.h>

/*===========================================================================*/
/* Module local definitions.                                                 */
/*===========================================================================*/

/**
 * @brief   OSAL Tick counter
 */
volatile uint32_t osal_tick_cnt;

/**
 * @brief   OSAL Tick frequency
 * @details Number of ticks per second.
 */
static uint32_t osal_ticks_per_sec;

/*===========================================================================*/
/* Module exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Module local variables.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Module local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   Increments the number of ticks
 * @details This function increments the number of ticks each time an interrupt
 *          occurs.
 *
 * @notapi
 */
void osal_inc_tick(void) {

    osal_tick_cnt++;
}

/**
 * @brief   Initializes SysTick
 * @details This function initializes the SysTick interrupt priority and 
 *          frequency. The interrupt frequency is specified in terms of ticks
 *          per second.
 *
 * @param[in] ticks_per_sec  number of ticks per second
 * @param[in] prio      SysTick interrupt priority
 *
 * @return              SysTick initialization status
 * @retval 0            operation succeeded
 * @retval 1            operation failed
 *
 * @notapi
 */
__STATIC_INLINE uint32_t osal_init_systick(uint32_t ticks_per_sec, uint32_t prio) {

    if (ticks_per_sec != 0U) {
        /* Configure SysTick interrupt frequency.*/
        if (SysTick_Config(SystemCoreClock / ticks_per_sec) == 0U) {
            osal_ticks_per_sec = ticks_per_sec;
            /* Configure SysTick interrupt priority.*/
            if (prio < (1UL << __NVIC_PRIO_BITS)) {
                NVIC_SetPriority(SysTick_IRQn, prio);
            } else {
                return 1U;
            }
        } else {
             return 1U;
        }
    } else {
         return 1U;
    }

    return 0U;
}

/**
 * @brief   Delays execution by specified amount of ticks
 *
 * @param[in] sec       number of ticks to delay
 *
 * @notapi
 */
__STATIC_INLINE void osal_tick_delay(uint32_t ticks) {

    const uint32_t tickstart = osal_get_tick();

    while (osal_get_tick() < tickstart + ticks) {
        ;
    }
}

/**
 * @brief   Converts seconds into number of ticks
 *
 * @param[in] sec       number of seconds
 * @return              number of ticks
 *
 * @notapi
 */
__STATIC_INLINE uint32_t osal_systick_s2tk(uint32_t sec) {

    return ((uint32_t)((sec) * (osal_ticks_per_sec)));
}

/**
 * @brief   Converts milliseconds into number of ticks
 *
 * @param[in] msec      number of milliseconds
 * @return              number of ticks
 *
 * @notapi
 */
__STATIC_INLINE uint32_t osal_systick_ms2tk(uint32_t msec) {

    return ((msec == 0U) ? ((uint32_t) 0) :
                           ((uint32_t)((((msec) * (osal_ticks_per_sec) - 1UL) / 1000UL) + 1UL)));
}

/**
 * @brief   Converts microseconds into number of ticks
 *
 * @param[in] usec      number of microseconds
 * @return              number of ticks
 *
 * @notapi
 */
__STATIC_INLINE uint32_t osal_systick_us2tk(uint32_t usec) {

    return ((usec == 0U) ? ((uint32_t) 0) :
                           ((uint32_t)((((usec) * (osal_ticks_per_sec) - 1UL) / 1000000UL) + 1UL)));
}

/*===========================================================================*/
/* Local function prototypes                                                 */
/*===========================================================================*/

IRQ_HANDLER(SysTick_Handler);

/*===========================================================================*/
/* Hook function prototypes                                                  */
/*===========================================================================*/

/**
 * @brief   OSAL Tick hook function prototype
 * @details When OSAL_CFG_USE_TICK_HOOK is set to TRUE, the application must
 *          provide a hook function with the following prototype that will be
 *          invoked each time the SysTick generate an interrupt.
 */
#if (OSAL_CFG_USE_TICK_HOOK == TRUE)
extern void osal_tick_hook(void);
#endif

/*===========================================================================*/
/* Module interrupt handlers.                                                */
/*===========================================================================*/

/**
 * @brief   SysTick interrupt handler
 *
 * @isr
 */
// IRQ_HANDLER(SysTick_Handler) {

//     IRQ_PROLOGUE();

//     osal_inc_tick();

// #if (OSAL_CFG_USE_TICK_HOOK == TRUE)
//     osal_tick_hook();
// #endif

//     IRQ_EPILOGUE();
// }

/*===========================================================================*/
/* Module exported functions.                                                */
/*===========================================================================*/

void osal_init(void) {

    (void)osal_init_systick(OSAL_CFG_TICKS_PER_SEC, OSAL_CFG_TICK_INT_PRIO);
    osal_tick_cnt = 0;
}

uint32_t osal_get_tick(void) {

    return osal_tick_cnt;
}

void osal_delay_sec(uint32_t sec) {

    osal_tick_delay(osal_systick_s2tk(sec));
}

void osal_delay_millisec(uint32_t msec) {

    osal_tick_delay(osal_systick_ms2tk(msec));
}

void osal_delay_microsec(uint32_t usec) {

    osal_tick_delay(osal_systick_us2tk(usec));
}

uint32_t osal_tk2s(uint32_t ticks) {

    return (uint32_t)(((uint64_t)ticks ) / ((uint64_t)osal_ticks_per_sec));
}

uint32_t osal_tk2ms(uint32_t ticks) {

    return (uint32_t)(((uint64_t)ticks * 1000ULL) / ((uint64_t)osal_ticks_per_sec));
}

uint32_t osal_tk2us(uint32_t ticks) {

    return (uint32_t)(((uint64_t)ticks * 1000000ULL) / ((uint64_t)osal_ticks_per_sec));
}

/** @} */
