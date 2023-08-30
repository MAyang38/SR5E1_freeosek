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
 * @file    systick.c
 * @brief   SYSTICK driver source file.
 *
 * @addtogroup DRIVERS
 * @addtogroup TIMERS
 * @ingroup DRIVERS
 * @addtogroup SYSTICK
 * @ingroup TIMERS
 * @{
 */

#include <systick.h>

/*===========================================================================*/
/* Module local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Module exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   System Core Frequency (Hz)
 * @details This value is calculate by the Clock module.
 */
extern uint32_t SystemCoreClock;

/* SYSTICK driver instance. */
systick_driver_t DRV_SYSTICK;

/*===========================================================================*/
/* Module local variables.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Module local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   SYSTICK interrupt handler.
 * @note    Not an API, used internally.
 *
 * @param[in] sdp       pointer to a @p systick_driver_t structure
 *
 * @isr
 */
__STATIC_INLINE void __systick_serve_interrupt(systick_driver_t *sdp) {

    /* Increments the number of SysTick overflows.*/
    sdp->overflow_cnt++;

    /* If callback is defined, it is invoked.*/
    if (sdp->cb != NULL) {
        sdp->cb(sdp);
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
__STATIC_INLINE uint64_t systick_s2tk(systick_driver_t *sdp, uint32_t sec) {

    return (((uint64_t)(sec)) * (sdp->freq));
}

/**
 * @brief   Converts milliseconds into number of ticks
 *
 * @param[in] msec      number of milliseconds
 * @return              number of ticks
 *
 * @notapi
 */
__STATIC_INLINE uint64_t systick_ms2tk(systick_driver_t *sdp, uint32_t msec) {

    return ((msec == 0U) ? ((uint64_t) 0) :
                           ((uint64_t)(((((uint64_t)(msec)) * (sdp->freq) - 1ULL) / 1000ULL) + 1ULL)));
}

/**
 * @brief   Converts microseconds into number of ticks
 *
 * @param[in] usec      number of microseconds
 * @return              number of ticks
 *
 * @notapi
 */
__STATIC_INLINE uint64_t systick_us2tk(systick_driver_t *sdp, uint32_t usec) {

    return ((usec == 0U) ? ((uint64_t) 0) :
                           ((uint64_t)(((((uint64_t)(usec)) * (sdp->freq) - 1ULL) / 1000000ULL) + 1ULL)));
}

/**
 * @brief   Converts nanoseconds into number of ticks
 *
 * @param[in] usec      number of nanoseconds
 * @return              number of ticks
 *
 * @notapi
 */
__STATIC_INLINE uint64_t systick_ns2tk(systick_driver_t *sdp, uint32_t nsec) {

    return ((nsec == 0U) ? ((uint64_t) 0) :
                           ((uint64_t)(((((uint64_t)(nsec)) * (sdp->freq) - 1ULL) / 1000000000ULL) + 1ULL)));
}

/*===========================================================================*/
/* Local function prototypes                                                 */
/*===========================================================================*/

IRQ_HANDLER(IRQ_SYSTICK_HANDLER);

/*===========================================================================*/
/* Module interrupt handlers.                                                */
/*===========================================================================*/

/**
 * @brief   SysTick interrupt handler
 *
 * @isr
 */
IRQ_HANDLER(IRQ_SYSTICK_HANDLER) {

    IRQ_PROLOGUE();

    __systick_serve_interrupt(&DRV_SYSTICK);

    IRQ_EPILOGUE();
}

/*===========================================================================*/
/* Module exported functions.                                                */
/*===========================================================================*/

void systick_init(systick_driver_t *sdp) {

    /* Set pointer to SYSTICK register block.*/
    sdp->systick      = SysTick;

    /* Set the SYSTICK frequency to the core frequency.*/
    sdp->freq         = SystemCoreClock;

    /* Reset SYSTICK parameters.*/
    sdp->prio         = IRQ_MIN_PRIORITY;
    sdp->relval       = 0U;
    sdp->overflow_cnt = 0U;
    sdp->cb           = NULL;
}

uint32_t systick_set_prio(systick_driver_t *sdp, uint32_t prio) {

    uint32_t prev_prio;

    prev_prio = sdp->prio;
    sdp->prio = prio;

    return prev_prio;
}

uint32_t systick_set_relval(systick_driver_t *sdp, uint32_t relval) {

    uint32_t prev_relval;

    prev_relval = sdp->relval;
    sdp->relval = relval;

    return prev_relval;
}

systick_cb_t systick_set_cb(systick_driver_t *sdp, systick_cb_t cb) {

    systick_cb_t prev_cb;

    prev_cb = sdp->cb;
    sdp->cb = cb;

    return prev_cb;
}

void systick_start(systick_driver_t *sdp) {

    (void)SysTick_Config(sdp->relval);
    NVIC_SetPriority(SysTick_IRQn, sdp->prio);
}

uint64_t systick_get_ticks(systick_driver_t *sdp) {

    /* SysTick is 24-bit clear-on-write, decrementing, wrap-on-zero counter.
       The number of ticks depends on the value of the counter cnt and on the
       number of overflows ovf occurred.*/
    uint64_t cnt = ((uint64_t)(sdp->relval) - (uint64_t)(sdp->systick->VAL));
    uint64_t ovf = ((uint64_t)(sdp->overflow_cnt * ((uint64_t)(sdp->relval) + 1ULL)));

    return (uint64_t)(cnt + ovf);
}

void systick_delay_sec(systick_driver_t *sdp, uint32_t sec) {

    uint64_t tickstart = systick_get_ticks(sdp);
    uint64_t ticks = systick_s2tk(sdp, sec);

    while (systick_get_ticks(sdp) < tickstart + ticks) {
        ;
    }
}

void systick_delay_millisec(systick_driver_t *sdp, uint32_t msec) {

    uint64_t tickstart = systick_get_ticks(sdp);
    uint64_t ticks = systick_ms2tk(sdp, msec);

    while (systick_get_ticks(sdp) < tickstart + ticks) {
        ;
    }
}

void systick_delay_microsec(systick_driver_t *sdp, uint32_t usec) {

    uint64_t tickstart = systick_get_ticks(sdp);
    uint64_t ticks = systick_us2tk(sdp, usec); 

    while (systick_get_ticks(sdp) < tickstart + ticks) {
        ;
    }
}

void systick_delay_nanosec(systick_driver_t *sdp, uint32_t nsec) {

    uint64_t tickstart = systick_get_ticks(sdp);
    uint64_t ticks = systick_ns2tk(sdp, nsec); 

    while (systick_get_ticks(sdp) < tickstart + ticks) {
        ;
    }
}

uint32_t systick_tk2s(systick_driver_t *sdp, uint64_t ticks) {

    return (uint32_t)(ticks / ((uint64_t)(sdp->freq)));
}

uint32_t systick_tk2ms(systick_driver_t *sdp, uint64_t ticks) {

    return (uint32_t)((ticks * 1000ULL) / ((uint64_t)(sdp->freq)));
}

uint32_t systick_tk2us(systick_driver_t *sdp, uint64_t ticks) {

    return (uint32_t)((ticks * 1000000ULL) / ((uint64_t)(sdp->freq)));
}

uint32_t systick_tk2ns(systick_driver_t *sdp, uint64_t ticks) {

    return (uint32_t)((ticks * 1000000000ULL) / ((uint64_t)(sdp->freq)));
}

/** @} */
