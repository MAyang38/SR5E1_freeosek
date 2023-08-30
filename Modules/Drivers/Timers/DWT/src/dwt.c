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
 * @file    dwt.c
 * @brief   DWT driver source file.
 *
 * @addtogroup DRIVERS
 * @addtogroup TIMERS
 * @ingroup DRIVERS
 * @addtogroup DWT
 * @ingroup TIMERS
 * @{
 */

#include <dwt.h>

/*===========================================================================*/
/* Module local definitions.                                                 */
/*===========================================================================*/

/**
 * @brief   DWT tick frequency
 * @details Number of ticks per second.
 */
static uint32_t dwt_ticks_per_sec = 0U;

/*===========================================================================*/
/* Module exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Module local types.                                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Module local variables.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Local function prototypes                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Module local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Module exported functions.                                                */
/*===========================================================================*/

void dwt_init(void) {

    /* Initialize the number of ticks per second to the core frequency.*/
    dwt_ticks_per_sec = CLOCK_SYSCLKDIV;

    /* Enable DWT and ITM blocks.*/
    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;

    /* Unlock access to DWT registers.*/
    DWT->LAR          = 0xC5ACCE55U;
    /* Clear DWT cycle counter.*/
    DWT->CYCCNT       = 0U;
    /* Enable DWT cycle counter.*/
    DWT->CTRL        |= DWT_CTRL_CYCCNTENA_Msk;
}

uint32_t dwt_s2t(uint32_t sec) {

    return ((uint32_t)((sec) * (dwt_ticks_per_sec)));
}

uint32_t dwt_ms2t(uint32_t msec) {

    return ((msec == 0U) ? ((uint32_t) 0) :
                           ((uint32_t)(((((uint64_t)(msec)) * ((uint64_t)(dwt_ticks_per_sec)) - 1ULL) / 1000ULL) + 1ULL)));
}

uint32_t dwt_us2t(uint32_t usec) {

    return ((usec == 0U) ? ((uint32_t) 0) :
                           ((uint32_t)(((((uint64_t)(usec)) * ((uint64_t)(dwt_ticks_per_sec)) - 1ULL) / 1000000ULL) + 1ULL)));
}

uint32_t dwt_ns2t(uint32_t nsec) {

    return ((nsec == 0U) ? ((uint32_t) 0) :
                           ((uint32_t)(((((uint64_t)(nsec)) * ((uint64_t)(dwt_ticks_per_sec)) - 1ULL) / 1000000000ULL) + 1ULL)));
}

uint32_t dwt_t2s(uint32_t ticks) {

    return (uint32_t)(((uint64_t)ticks) / ((uint64_t)dwt_ticks_per_sec));
}

uint32_t dwt_t2ms(uint32_t ticks) {

    return (uint32_t)(((uint64_t)ticks * 1000ULL) / ((uint64_t)dwt_ticks_per_sec));
}

uint32_t dwt_t2us(uint32_t ticks) {

    return (uint32_t)(((uint64_t)ticks * 1000000ULL) / ((uint64_t)dwt_ticks_per_sec));
}

uint32_t dwt_t2ns(uint32_t ticks) {

    return (uint32_t)(((uint64_t)ticks * 1000000000ULL) / ((uint64_t)dwt_ticks_per_sec));
}

void dwt_deinit(void) {

    /* Disable DWT cycle counter.*/
    DWT->CTRL        &= ~DWT_CTRL_CYCCNTENA_Msk;

    /* Clear DWT cycle counter.*/
    DWT->CYCCNT       = 0U;

    /* Disable DWT and ITM blocks.*/
    CoreDebug->DEMCR &= ~CoreDebug_DEMCR_TRCENA_Msk;
}

/** @} */
