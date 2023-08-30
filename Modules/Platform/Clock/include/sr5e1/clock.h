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
 * @file    clock.h
 * @brief   SR5E1 clock subsystem header file.
 *
 * @addtogroup PLATFORM
 * @addtogroup CLOCK
 * @ingroup PLATFORM
 * @{
 */

#ifndef _CLOCK_H_
#define _CLOCK_H_

#include <clock_cfg.h>
#include <platform.h>
#include <typedefs.h>

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

/**
 * @name    RCC CFGR register
 * @{
 */
#define CLOCK_SW_MASK               (3UL << 0U)
#define CLOCK_SW_IRCOSC             (4UL << 0U) /* Internal 16 MHz   */
#define CLOCK_SW_XOSC               (5UL << 0U) /* External 4-40 MHz */
#define CLOCK_SW_PLL0PHI            (6UL << 0U)
#define CLOCK_SW_PLL1PHI            (7UL << 0U)

#define CLOCK_SYSPRE_MASK           (511UL << 8U)
#define CLOCK_SYSPRE_FIELD(n)       (((uint32_t)(n)) << 8U)

#define CLOCK_MCOSEL_MASK           (15UL << 20U)
#define CLOCK_MCOSEL_NOCLOCK        (0UL << 20U)
#define CLOCK_MCOSEL_LSI            (8UL << 20U)
#define CLOCK_MCOSEL_IRCOSC         (9UL << 20U)
#define CLOCK_MCOSEL_XOSC           (10UL << 20U)
#define CLOCK_MCOSEL_PLL0PHI        (11UL << 20U)
#define CLOCK_MCOSEL_PLL1PHI        (12UL << 20U)

#define CLOCK_MCOPRE_MASK           (63UL << 24U)
#define CLOCK_MCOPRE_FIELD(n)       (((uint32_t)(n)) << 24U)
/** @} */

/**
 * @name    RCC PLLCFGR register
 * @{
 */
#define CLOCK_PLL0SRC_MASK          (3UL << 0U)
#define CLOCK_PLL0SRC_NOCLOCK       (0UL << 0U)
#define CLOCK_PLL0SRC_IRCOSC        (2UL << 0U)
#define CLOCK_PLL0SRC_XOSC          (3UL << 0U)

#define CLOCK_PLL1SRC_MASK          (3UL << 8U)
#define CLOCK_PLL1SRC_NOCLOCK       (0UL << 8U)
#define CLOCK_PLL1SRC_PLL0PHI1      (2UL << 8U)
#define CLOCK_PLL1SRC_XOSC          (3UL << 8U)
/** @} */

/**
 * @name    RCC CCIPR1 register
 * @{
 */
#define CLOCK_UARTSEL_MASK          (7UL << 0U)
#define CLOCK_UARTSEL_NOCLOCK       (0UL << 0U)
#define CLOCK_UARTSEL_IRCOSC        (4UL << 0U)
#define CLOCK_UARTSEL_XOSC          (5UL << 0U)
#define CLOCK_UARTSEL_PLL0PHI       (6UL << 0U)
#define CLOCK_UARTSEL_LSI           (7UL << 0U)

#define CLOCK_I2CSEL_MASK           (7UL << 4U)
#define CLOCK_I2CSEL_NOCLOCK        (0UL << 4U)
#define CLOCK_I2CSEL_IRCOSC         (4UL << 4U)
#define CLOCK_I2CSEL_XOSC           (5UL << 4U)
#define CLOCK_I2CSEL_PLL0PHI        (6UL << 4U)

#define CLOCK_SPISEL_MASK           (7UL << 8U)
#define CLOCK_SPISEL_NOCLOCK        (0UL << 8U)
#define CLOCK_SPISEL_IRCOSC         (4UL << 8U)
#define CLOCK_SPISEL_XOSC           (5UL << 8U)
#define CLOCK_SPISEL_PLL0PHI        (6UL << 8U)
#define CLOCK_SPISEL_I2S_CKIN       (7UL << 8U)

#define CLOCK_FDCANSEL_MASK         (7UL << 12U)
#define CLOCK_FDCANSEL_NOCLOCK      (0UL << 12U)
#define CLOCK_FDCANSEL_XOSC         (4UL << 12U)
#define CLOCK_FDCANSEL_PLL0PHI      (5UL << 12U)

#define CLOCK_ADCSEL_MASK           (7UL << 16U)
#define CLOCK_ADCSEL_NOCLOCK        (0UL << 16U)
#define CLOCK_ADCSEL_XOSC           (4UL << 16U)
#define CLOCK_ADCSEL_PLL0PHI        (5UL << 16U)
#define CLOCK_ADCSEL_PLL1PHI        (6UL << 16U)

#define CLOCK_SDADCSEL_MASK         (7UL << 20U)
#define CLOCK_SDADCSEL_NOCLOCK      (0UL << 20U)
#define CLOCK_SDADCSEL_XOSC         (4UL << 20U)
#define CLOCK_SDADCSEL_PLL0PHI      (5UL << 20U)
#define CLOCK_SDADCSEL_PLL1PHI      (6UL << 20U)
/** @} */

/**
 * @name    RCC CCIPR2 register
 * @{
 */
#define CLOCK_UARTPRE_MASK          (31U << 0U)
#define CLOCK_UARTPRE_FIELD(n)      (((uint32_t)(n)) << 0U)

#define CLOCK_I2CPRE_MASK           (31U << 5U)
#define CLOCK_I2CPRE_FIELD(n)       (((uint32_t)(n)) << 5U)

#define CLOCK_SPIPRE_MASK           (31U << 10U)
#define CLOCK_SPIPRE_FIELD(n)       (((uint32_t)(n)) << 10U)

#define CLOCK_FDCANPRE_MASK         (31U << 15U)
#define CLOCK_FDCANPRE_FIELD(n)     (((uint32_t)(n)) << 15U)

#define CLOCK_ADCPRE_MASK           (63U << 20U)
#define CLOCK_ADCPRE_FIELD(n)       (((uint32_t)(n)) << 20U)

#define CLOCK_SDADCPRE_MASK         (63U << 26U)
#define CLOCK_SDADCPRE_FIELD(n)     (((uint32_t)(n)) << 26U)
/** @} */

/**
 * @name    RCC LSCFGR register
 * @{
 */
#define CLOCK_RTCSEL_MASK           (3UL << 9U)
#define CLOCK_RTCSEL_NOCLOCK        (0UL << 9U)
#define CLOCK_RTCSEL_LSI            (2UL << 9U)  /* LSI after LSIPRE prescaler division */
#define CLOCK_RTCSEL_XOSC           (3UL << 9U)  /* XOSC divided by 32 */

#define CLOCK_LSIPRE_MASK           (31UL << 0U)
#define CLOCK_LSIPRE_FIELD(n)       (((uint32_t)(n)) << 0U)
/** @} */

/**
 * @name    PLLDIG PLL0DV register
 * @{
 */
#define CLOCK_PLL0MFD_MASK          (127UL << 0U)
#define CLOCK_PLL0MFD_FIELD(n)      (((uint32_t)(n)) << 0U)

#define CLOCK_PLL0PREDIV_MASK       (7UL << 12U)
#define CLOCK_PLL0PREDIV_FIELD(n)   (((uint32_t)(n)) << 12U)

#define CLOCK_PLL0RFDPHI_MASK       (63UL << 16U)
#define CLOCK_PLL0RFDPHI_FIELD(n)   (((uint32_t)(n)) << 16U)

#define CLOCK_PLL0RFDPHI1_MASK      (15UL << 27U)
#define CLOCK_PLL0RFDPHI1_FIELD(n)  (((uint32_t)(n)) << 27U)
/** @} */

/**
 * @name    PLLDIG PLL1DV register
 * @{
 */
#define CLOCK_PLL1MFD_MASK          (127UL << 0U)
#define CLOCK_PLL1MFD_FIELD(n)      (((uint32_t)(n)) << 0U)

#define CLOCK_PLL1RFDPHI_MASK       (63U << 16U)
#define CLOCK_PLL1RFDPHI_FIELD(n)   (((uint32_t)(n)) << 16U)
/** @} */

/**
 * @name    NVMPC PFCR1 register
 * @{
 */

#define CLOCK_NVMCCBFEN_MASK        (1UL << 0U)
#define CLOCK_NVMCCBFEN_FIELD(n)    (((uint32_t)(n)) << 0U)

#define CLOCK_NVMDCBFEN_MASK        (1UL << 1U)
#define CLOCK_NVMDCBFEN_FIELD(n)    ((n) << 1U)

#define CLOCK_NVMRWSC_MASK          (1FUL << 8U)
#define CLOCK_NVMRWSC_FIELD(n)      (((uint32_t)(n)) << 8U)

#define CLOCK_NVMAPC_MASK           (7UL << 13U)
#define CLOCK_NVMAPC_FIELD(n)       (((uint32_t)(n)) << 13U)
/** @} */

/**
 * @name    Internal oscillators
 * @{
 */
#define CLOCK_IRCOSCCLK             16000000UL
#define CLOCK_LSICLK                1000000UL
/** @} */

/*===========================================================================*/
/* Module pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/* Configuration file checks.*/
#if !defined(SR5E1xxx_CLOCKCONF)
#error "SR5E1xxx_CLOCKCONF not defined in clock_cfg.h"
#endif

#if !defined(CLOCK_CFG_SMP_MODE) || defined(__DOXYGEN__)
#error "CLOCK_CFG_SMP_MODE not defined in clock_cfg.h"
#endif

#if !defined(CLOCK_CFG_XOSC_ENABLED) || defined(__DOXYGEN__)
#error "CLOCK_CFG_XOSC_ENABLED not defined in clock_cfg.h"
#endif

#if !defined(CLOCK_CFG_LSI_ENABLED) || defined(__DOXYGEN__)
#error "CLOCK_CFG_LSI_ENABLED not defined in clock_cfg.h"
#endif

#if !defined(CLOCK_CFG_XOSCCLK)
#error "CLOCK_CFG_XOSCCLK not defined in clock_cfg.h"
#endif

#if !defined(CLOCK_CFG_XOSC_BYPASS)
#error "CLOCK_CFG_XOSC_BYPASS not defined in clock_cfg.h"
#endif

#if !defined(CLOCK_CFG_PLL0SRC) || defined(__DOXYGEN__)
#error "CLOCK_CFG_PLL0SRC not defined in clock_cfg.h"
#endif

#if !defined(CLOCK_CFG_PLL0MFD_VALUE) || defined(__DOXYGEN__)
#error "CLOCK_CFG_PLL0MFD_VALUE not defined in clock_cfg.h"
#endif

#if !defined(CLOCK_CFG_PLL0PREDIV_VALUE) || defined(__DOXYGEN__)
#error "CLOCK_CFG_PLL0PREDIV_VALUE not defined in clock_cfg.h"
#endif

#if !defined(CLOCK_CFG_PLL0RFDPHI_VALUE) || defined(__DOXYGEN__)
#error "CLOCK_CFG_PLL0RFDPHI_VALUE not defined in clock_cfg.h"
#endif

#if !defined(CLOCK_CFG_PLL0RFDPHI1_VALUE) || defined(__DOXYGEN__)
#error "CLOCK_CFG_PLL0RFDPHI1_VALUE not defined in clock_cfg.h"
#endif

#if !defined(CLOCK_CFG_PLL1SRC) || defined(__DOXYGEN__)
#error "CLOCK_CFG_PLL1SRC not defined in clock_cfg.h"
#endif

#if !defined(CLOCK_CFG_PLL1MFD_VALUE) || defined(__DOXYGEN__)
#error "CLOCK_CFG_PLL1MFD_VALUE not defined in clock_cfg.h"
#endif

#if !defined(CLOCK_CFG_PLL1RFDPHI_VALUE) || defined(__DOXYGEN__)
#error "CLOCK_CFG_PLL1RFDPHI_VALUE not defined in clock_cfg.h"
#endif

#if !defined(CLOCK_CFG_SW) || defined(__DOXYGEN__)
#error "CLOCK_CFG_SW not defined in clock_cfg.h"
#endif

#if !defined(CLOCK_CFG_SYSPRE_VALUE) || defined(__DOXYGEN__)
#error "CLOCK_CFG_SYSPRE_VALUE not defined in clock_cfg.h"
#endif

#if !defined(CLOCK_CFG_UARTSEL) || defined(__DOXYGEN__)
#error "CLOCK_CFG_UARTSEL not defined in clock_cfg.h"
#endif

#if !defined(CLOCK_CFG_I2CSEL) || defined(__DOXYGEN__)
#error "CLOCK_CFG_I2CSEL not defined in clock_cfg.h"
#endif

#if !defined(CLOCK_CFG_SPISEL) || defined(__DOXYGEN__)
#error "CLOCK_CFG_SPISEL not defined in clock_cfg.h"
#endif

#if !defined(CLOCK_CFG_FDCANSEL) || defined(__DOXYGEN__)
#error "CLOCK_CFG_FDCANSEL not defined in clock_cfg.h"
#endif

#if !defined(CLOCK_CFG_ADCSEL) || defined(__DOXYGEN__)
#error "CLOCK_CFG_ADCSEL not defined in clock_cfg.h"
#endif

#if !defined(CLOCK_CFG_SDADCSEL) || defined(__DOXYGEN__)
#error "CLOCK_CFG_SDADCSEL not defined in clock_cfg.h"
#endif

#if !defined(CLOCK_CFG_MCOSEL) || defined(__DOXYGEN__)
#error "CLOCK_CFG_MCOSEL not defined in clock_cfg.h"
#endif

#if !defined(CLOCK_CFG_RTCSEL) || defined(__DOXYGEN__)
#error "CLOCK_CFG_RTCSEL not defined in clock_cfg.h"
#endif

#if !defined(CLOCK_CFG_UARTPRE_VALUE) || defined(__DOXYGEN__)
#error "CLOCK_CFG_UARTPRE_VALUE not defined in clock_cfg.h"
#endif

#if !defined(CLOCK_CFG_I2CPRE_VALUE) || defined(__DOXYGEN__)
#error "CLOCK_CFG_I2CPRE_VALUE not defined in clock_cfg.h"
#endif

#if !defined(CLOCK_CFG_SPIPRE_VALUE) || defined(__DOXYGEN__)
#error "CLOCK_CFG_SPIPRE_VALUE not defined in clock_cfg.h"
#endif

#if !defined(CLOCK_CFG_FDCANPRE_VALUE) || defined(__DOXYGEN__)
#error "CLOCK_CFG_FDCANPRE_VALUE not defined in clock_cfg.h"
#endif

#if !defined(CLOCK_CFG_ADCPRE_VALUE) || defined(__DOXYGEN__)
#error "CLOCK_CFG_ADCPRE_VALUE not defined in clock_cfg.h"
#endif

#if !defined(CLOCK_CFG_SDADCPRE_VALUE) || defined(__DOXYGEN__)
#error "CLOCK_CFG_SDADCPRE_VALUE not defined in clock_cfg.h"
#endif

#if !defined(CLOCK_CFG_MCOPRE_VALUE) || defined(__DOXYGEN__)
#error "CLOCK_CFG_MCOPRE_VALUE not defined in clock_cfg.h"
#endif

#if !defined(CLOCK_CFG_LSIPRE_VALUE) || defined(__DOXYGEN__)
#error "CLOCK_CFG_LSIPRE_VALUE not defined in clock_cfg.h"
#endif

/* If SPISEL = I2S_CKIN, the value of I2S clock on the CKIN pin must be
   specified in the clock configuration file.*/
#if (CLOCK_CFG_SPISEL == CLOCK_SPISEL_I2S_CKIN)
#if !defined(CLOCK_CFG_I2S_CKIN) || defined(__DOXYGEN__)
#error "CLOCK_CFG_I2S_CKIN not defined in clock_cfg.h"
#endif
#endif

/* Clock Limits */
#define CLOCK_SYSCLK_MAX            300000000UL

#define CLOCK_XOSCCLK_MAX           40000000UL
#define CLOCK_XOSCCLK_BYP_MAX       100000000UL
#define CLOCK_XOSCCLK_MIN           4000000UL
#define CLOCK_XOSCCLK_BYP_MIN       4000000UL

#define CLOCK_PLL0IN_MAX            56000000UL
#define CLOCK_PLL0IN_MIN            8000000UL
#define CLOCK_PLL0VCO_MAX           1400000000UL
#define CLOCK_PLL0VCO_MIN           600000000UL
#define CLOCK_PLL0PHI_MAX           700000000UL
#define CLOCK_PLL0PHI_MIN           4762000UL
#define CLOCK_PLL0PHI1_MAX          175000000UL
#define CLOCK_PLL0PHI1_MIN          20000000UL
#define CLOCK_PLL1IN_MAX            87500000UL
#define CLOCK_PLL1IN_MIN            37500000UL
#define CLOCK_PLL1VCO_MAX           1400000000UL
#define CLOCK_PLL1VCO_MIN           600000000UL
#define CLOCK_PLL1PHI_MAX           700000000UL
#define CLOCK_PLL1PHI_MIN           4762000UL

#define CLOCK_UARTCLK_MAX           100000000UL
#define CLOCK_I2CCLK_MAX            100000000UL
#define CLOCK_SPICLK_MS_SPI1_4_MAX  50000000UL
#define CLOCK_SPICLK_MS_SPI2_3_MAX  37500000UL
#define CLOCK_SPICLK_SL_MAX         50000000UL
#define CLOCK_I2SCLK_MAX            100000000UL
#define CLOCK_FDCANCLK_MAX          80000000UL
#define CLOCK_ADCCLK_MAX            37500000UL
#define CLOCK_SDADCCLK_MAX          16000000UL

/*Checks on XOSC.*/
#if CLOCK_CFG_XOSC_ENABLED

#if CLOCK_CFG_XOSCCLK == 0U
#error "CLOCK_CFG_XOSCCLK is zero in clock_cfg.h"
#else /* CLOCK_CFG_XOSCCLK != 0 */
#if CLOCK_CFG_XOSC_BYPASS

#if (CLOCK_CFG_XOSCCLK < CLOCK_XOSCCLK_BYP_MIN) ||                          \
    (CLOCK_CFG_XOSCCLK > CLOCK_XOSCCLK_BYP_MAX)
#error "out of limits  CLOCK_XOSCCLK value"
#endif

#else /* !CLOCK_CFG_XOSC_BYPASS */

#if (CLOCK_CFG_XOSCCLK < CLOCK_XOSCCLK_MIN) ||                              \
    (CLOCK_CFG_XOSCCLK > CLOCK_XOSCCLK_MAX)
#error "out of limits  CLOCK_XOSCCLK value"
#endif

#endif /* !CLOCK_CFG_XOSC_BYPASS */
#endif /* CLOCK_CFG_XOSCCLK != 0 */

#else /* !CLOCK_CFG_XOSC_ENABLED */

#if CLOCK_CFG_SW == CLOCK_SW_XOSC
#error "CLOCK_SW requires XOSC"
#endif

#if (CLOCK_CFG_SW == CLOCK_SW_PLL0PHI) &&                                   \
    (CLOCK_CFG_PLL0SRC == CLOCK_PLL0SRC_XOSC)
#error "CLOCK_CFG_SW or CLOCK_CFG_PLL0SRC require XOSC"
#endif

#if (CLOCK_CFG_SW == CLOCK_SW_PLL1PHI) &&                                   \
    (CLOCK_CFG_PLL1SRC == CLOCK_PLL1SRC_XOSC)
#error "CLOCK_CFG_SW or CLOCK_CFG_PLL1SRC require XOSC"
#endif

#if (CLOCK_CFG_SW == CLOCK_SW_PLL1PHI) &&                                   \
    (CLOCK_CFG_PLL1SRC == CLOCK_PLL1SRC_PLL0PHI1) &&                        \
    (CLOCK_CFG_PLL0SRC == CLOCK_PLL0SRC_XOSC)
#error "CLOCK_CFG_SW or CLOCK_CFG_PLL1SRC require XOSC"
#endif

#if (CLOCK_CFG_MCOSEL == CLOCK_MCOSEL_XOSC) ||                              \
    ((CLOCK_CFG_MCOSEL == CLOCK_MCOSEL_PLL0PHI) &&                          \
     (CLOCK_CFG_PLL0SRC == CLOCK_PLL0SRC_XOSC)) ||                          \
    ((CLOCK_CFG_MCOSEL == CLOCK_MCOSEL_PLL1PHI) &&                          \
     (CLOCK_CFG_PLL1SRC == CLOCK_PLL1SRC_XOSC)) 
#error "CLOCK_CFG_MCOSEL requires XOSC"
#endif

#if (CLOCK_CFG_UARTSEL == CLOCK_UARTSEL_XOSC) ||                            \
    ((CLOCK_CFG_UARTSEL == CLOCK_UARTSEL_PLL0PHI) &&                        \
     (CLOCK_CFG_PLL0SRC == CLOCK_PLL0SRC_XOSC))
#error "CLOCK_CFG_UARTSEL requires XOSC"
#endif

#if (CLOCK_CFG_I2CSEL == CLOCK_I2CSEL_XOSC) ||                              \
    ((CLOCK_CFG_I2CSEL == CLOCK_I2CSEL_PLL0PHI) &&                          \
     (CLOCK_CFG_PLL0SRC == CLOCK_PLL0SRC_XOSC))
#error "CLOCK_CFG_I2CSEL requires XOSC"
#endif

#if (CLOCK_CFG_SPISEL == CLOCK_SPISEL_XOSC) ||                              \
    ((CLOCK_CFG_SPISEL == CLOCK_SPISEL_PLL0PHI) &&                          \
     (CLOCK_CFG_PLL0SRC == CLOCK_PLL0SRC_XOSC))
#error "CLOCK_CFG_SPISEL requires XOSC"
#endif

#if (CLOCK_CFG_FDCANSEL == CLOCK_FDCANSEL_XOSC) ||                          \
    ((CLOCK_CFG_FDCANSEL == CLOCK_FDCANSEL_PLL0PHI) &&                      \
     (CLOCK_CFG_PLL0SRC == CLOCK_PLL0SRC_XOSC))
#error "CLOCK_CFG_FDCANSEL requires XOSC"
#endif

#if (CLOCK_CFG_ADCSEL == CLOCK_ADCSEL_XOSC) ||                              \
    ((CLOCK_CFG_ADCSEL == CLOCK_ADCSEL_PLL0PHI) &&                          \
     (CLOCK_CFG_PLL0SRC == CLOCK_PLL0SRC_XOSC)) ||                          \
    ((CLOCK_CFG_ADCSEL == CLOCK_ADCSEL_PLL1PHI) &&                          \
     (CLOCK_CFG_PLL1SRC == CLOCK_PLL1SRC_XOSC)) 
#error "CLOCK_CFG_ADCSEL requires XOSC"
#endif

#if (CLOCK_CFG_SDADCSEL == CLOCK_SDADCSEL_XOSC) ||                          \
    ((CLOCK_CFG_SDADCSEL == CLOCK_SDADCSEL_PLL0PHI) &&                      \
     (CLOCK_CFG_PLL0SRC == CLOCK_PLL0SRC_XOSC)) ||                          \
    ((CLOCK_CFG_SDADCSEL == CLOCK_SDADCSEL_PLL1PHI) &&                      \
     (CLOCK_CFG_PLL1SRC == CLOCK_PLL1SRC_XOSC)) 
#error "CLOCK_CFG_SDADCSEL requires XOSC"
#endif

#if CLOCK_CFG_RTCSEL == CLOCK_RTCSEL_XOSCDIV
#error "CLOCK_CFG_RTCSEL requires XOSC"
#endif

#endif /* CLOCK_CFG_XOSC_ENABLED */

/*
 * LSI related checks.
 */
#if !CLOCK_CFG_LSI_ENABLED

#if CLOCK_CFG_UARTSEL == CLOCK_UARTSEL_LSI
#error "CLOCK_CFG_UARTSEL requires LSI"
#endif

#if CLOCK_CFG_MCOSEL == CLOCK_MCOSEL_LSI
#error "CLOCK_CFG_MCOSEL requires LSI"
#endif

#if CLOCK_CFG_RTCSEL == CLOCK_RTCSEL_LSI
#error "CLOCK_CFG_RTCSEL requires LSI"
#endif

#endif /* !CLOCK_CFG_LSI_ENABLED */

/* PLL0 enable check.*/
#if (CLOCK_CFG_SW == CLOCK_SW_PLL0PHI) ||                                   \
    (CLOCK_CFG_PLL1SRC == CLOCK_PLL1SRC_PLL0PHI1) ||                        \
    (CLOCK_CFG_MCOSEL == CLOCK_MCOSEL_PLL0PHI) ||                           \
    (CLOCK_CFG_UARTSEL == CLOCK_UARTSEL_PLL0PHI) ||                         \
    (CLOCK_CFG_I2CSEL == CLOCK_I2CSEL_PLL0PHI) ||                           \
    (CLOCK_CFG_SPISEL == CLOCK_SPISEL_PLL0PHI) ||                           \
    (CLOCK_CFG_FDCANSEL == CLOCK_FDCANSEL_PLL0PHI) ||                       \
    (CLOCK_CFG_ADCSEL == CLOCK_ADCSEL_PLL0PHI) ||                           \
    (CLOCK_CFG_SDADCSEL == CLOCK_SDADCSEL_PLL0PHI)
#define CLOCK_ACTIVATE_PLL0         TRUE
#else
#define CLOCK_ACTIVATE_PLL0         FALSE
#endif

/* PLL0 fields.*/
#if !((CLOCK_CFG_PLL0MFD_VALUE >= 8U) && (CLOCK_CFG_PLL0MFD_VALUE <= 127U))
#error "invalid CLOCK_CFG_PLL0MFD_VALUE value in clock_cfg.h"
#endif

#if !((CLOCK_CFG_PLL0PREDIV_VALUE >= 0U) && (CLOCK_CFG_PLL0PREDIV_VALUE <= 7U))
#error "invalid CLOCK_CFG_PLL0PREDIV_VALUE value in clock_cfg.h"
#endif

#if !((CLOCK_CFG_PLL0RFDPHI_VALUE >= 1U) && (CLOCK_CFG_PLL0RFDPHI_VALUE <= 63U))
#error "invalid CLOCK_CFG_PLL0RFDPHI_VALUE value in clock_cfg.h"
#endif

#if !((CLOCK_CFG_PLL0RFDPHI1_VALUE >= 4U) && (CLOCK_CFG_PLL0RFDPHI1_VALUE <= 15U))
#error "invalid CLOCK_CFG_PLL0RFDPHI1_VALUE value in clock_cfg.h"
#endif

/* PLL0 input clock.*/
#if (CLOCK_CFG_PLL0SRC == CLOCK_PLL0SRC_XOSC) || defined(__DOXYGEN__)
#define CLOCK_PLL0IN                CLOCK_CFG_XOSCCLK

#elif CLOCK_CFG_PLL0SRC == CLOCK_PLL0SRC_IRCOSC
#define CLOCK_PLL0IN                CLOCK_IRCOSCCLK

#elif CLOCK_CFG_PLL0SRC == CLOCK_PLL0SRC_NOCLOCK
#define CLOCK_PLL0IN                0U

#else
#error "invalid CLOCK_CFG_PLL0SRC value in clock_cfg.h"
#endif

#if (CLOCK_PLL0IN == 0U) && (CLOCK_ACTIVATE_PLL0 == TRUE)
#error "no PLL input clock"
#endif

#if ((CLOCK_PLL0IN != 0U) && (CLOCK_ACTIVATE_PLL0 == TRUE)) &&              \
    ((CLOCK_PLL0IN < CLOCK_PLL0IN_MIN) || (CLOCK_PLL0IN > CLOCK_PLL0IN_MAX))
#error "out of limits CLOCK_PLL0IN value"
#endif

/* PLL0 VCO clock.*/
#if (CLOCK_CFG_PLL0PREDIV_VALUE == 0U)
#define CLOCK_PLL0VCO               0U
#else
#define CLOCK_PLL0VCO                                                       \
  ((2U * CLOCK_CFG_PLL0MFD_VALUE * CLOCK_PLL0IN) / CLOCK_CFG_PLL0PREDIV_VALUE)
#endif

#if (CLOCK_PLL0VCO != 0U) && (CLOCK_ACTIVATE_PLL0 == TRUE) &&               \
    ((CLOCK_PLL0VCO < CLOCK_PLL0VCO_MIN) || (CLOCK_PLL0VCO > CLOCK_PLL0VCO_MAX))
#error "out of limits CLOCK_PLL0VCO value"
#endif

/* PLL0 output clocks.*/
#define CLOCK_PLL0PHI                                                       \
  ((CLOCK_PLL0VCO / CLOCK_CFG_PLL0RFDPHI_VALUE) / 2U)

#if (CLOCK_ACTIVATE_PLL0 == TRUE) &&                                        \
    ((CLOCK_PLL0PHI < CLOCK_PLL0PHI_MIN) || (CLOCK_PLL0PHI > CLOCK_PLL0PHI_MAX))
#error "out of limits CLOCK_PLL0PHI value"
#endif

#define CLOCK_PLL0PHI1                                                      \
  ((CLOCK_PLL0VCO / CLOCK_CFG_PLL0RFDPHI1_VALUE) / 2U)

#if (CLOCK_ACTIVATE_PLL0 == TRUE) &&                                        \
    ((CLOCK_PLL0PHI1 < CLOCK_PLL0PHI1_MIN) || (CLOCK_PLL0PHI1 > CLOCK_PLL0PHI1_MAX))
#error "out of limits CLOCK_PLL0PHI1 value"
#endif

/* PLL1 enable check.*/
#if (CLOCK_CFG_SW == CLOCK_SW_PLL1PHI) ||                                   \
    (CLOCK_CFG_MCOSEL == CLOCK_MCOSEL_PLL1PHI) ||                           \
    (CLOCK_CFG_ADCSEL == CLOCK_ADCSEL_PLL1PHI) ||                           \
    (CLOCK_CFG_SDADCSEL == CLOCK_SDADCSEL_PLL1PHI)
#define CLOCK_ACTIVATE_PLL1         TRUE
#else
#define CLOCK_ACTIVATE_PLL1         FALSE
#endif

/* PLL1 fields.*/
#if !((CLOCK_CFG_PLL1MFD_VALUE >= 16U) && (CLOCK_CFG_PLL1MFD_VALUE <= 34U))
#error "invalid CLOCK_CFG_PLL1MFD_VALUE value in clock_cfg.h"
#endif

#if !((CLOCK_CFG_PLL1RFDPHI_VALUE >= 1U) && (CLOCK_CFG_PLL1RFDPHI_VALUE <= 63U))
#error "invalid CLOCK_CFG_PLL1RFDPHI_VALUE value in clock_cfg.h"
#endif

/* PLL1 input clock.*/
#if (CLOCK_CFG_PLL1SRC == CLOCK_PLL1SRC_PLL0PHI1) || defined(__DOXYGEN__)
#define CLOCK_PLL1IN                CLOCK_PLL0PHI1

#elif CLOCK_CFG_PLL1SRC == CLOCK_PLL1SRC_XOSC
#define CLOCK_PLL1IN                CLOCK_CFG_XOSCCLK

#elif CLOCK_CFG_PLL1SRC == CLOCK_PLL1SRC_NOCLOCK
#define CLOCK_PLL1IN                0U

#else
#error "invalid CLOCK_CFG_PLL1SRC value in clock_cfg.h"
#endif

#if (CLOCK_PLL1IN == 0U && CLOCK_ACTIVATE_PLL1 == TRUE)
#error "no PLL input clock"
#endif

#if ((CLOCK_PLL1IN != 0U) && (CLOCK_ACTIVATE_PLL1 == TRUE)) &&              \
    ((CLOCK_PLL1IN < CLOCK_PLL1IN_MIN) || (CLOCK_PLL1IN > CLOCK_PLL1IN_MAX))
#error "out of limits CLOCK_PLL1IN value"
#endif

/* PLL1 VCO clock.*/
#define CLOCK_PLL1VCO                                                       \
  (CLOCK_PLL1IN * CLOCK_CFG_PLL1MFD_VALUE)

#if (CLOCK_ACTIVATE_PLL1 == TRUE) &&                                        \
    ((CLOCK_PLL1VCO < CLOCK_PLL1VCO_MIN) || (CLOCK_PLL1VCO > CLOCK_PLL1VCO_MAX))
#error "out of limits CLOCK_PLL1VCO value"
#endif

/* PLL1 output clock.*/
#define CLOCK_PLL1PHI                                                       \
  ((CLOCK_PLL1VCO / CLOCK_CFG_PLL1RFDPHI_VALUE) / 2U)

#if (CLOCK_ACTIVATE_PLL1 == TRUE) &&                                        \
    ((CLOCK_PLL1PHI < CLOCK_PLL1PHI_MIN) || (CLOCK_PLL1PHI > CLOCK_PLL1PHI_MAX))
#error "out of limits CLOCK_PLL1PHI value"
#endif

/* SYSCLK source.*/
#if (CLOCK_CFG_SW == CLOCK_SW_IRCOSC) || defined(__DOXYGEN__)
#define CLOCK_SYSCLK                CLOCK_IRCOSCCLK

#elif (CLOCK_CFG_SW == CLOCK_SW_XOSC)
#define CLOCK_SYSCLK                CLOCK_CFG_XOSCCLK

#elif (CLOCK_CFG_SW == CLOCK_SW_PLL0PHI)
#define CLOCK_SYSCLK                CLOCK_PLL0PHI

#elif (CLOCK_CFG_SW == CLOCK_SW_PLL1PHI)
#define CLOCK_SYSCLK                CLOCK_PLL1PHI

#else
#error "invalid CLOCK_CFG_SW value in clock_cfg.h"
#endif

/* SYSCLK check.*/
#if CLOCK_SYSCLK > CLOCK_SYSCLK_MAX
#error "out of limits CLOCK_SYSCLK value"
#endif

/* SYSCLKDIV source.*/
#if ((CLOCK_CFG_SYSPRE_VALUE >= 0U) && (CLOCK_CFG_SYSPRE_VALUE <= 511U))
#define  CLOCK_SYSCLKDIV             (CLOCK_SYSCLK / (CLOCK_CFG_SYSPRE_VALUE + 1U))
#else
#error "invalid CLOCK_CFG_SYSPRE_VALUE value in clock_cfg.h"
#endif

/* APB1 frequency.*/
#define CLOCK_PCLK1                 (CLOCK_SYSCLKDIV / 4U)

/* APB2 frequency.*/
#define CLOCK_PCLK2                 (CLOCK_SYSCLKDIV / 2U)

/**
 * @brief   TIM clock.
 */
#define CLOCK_TIMCLK1               (CLOCK_PCLK2 * 2U)
#define CLOCK_TIMCLK2               (CLOCK_PCLK1 * 2U)
#define CLOCK_TIMCLK3               (CLOCK_PCLK1 * 2U)
#define CLOCK_TIMCLK4               (CLOCK_PCLK2 * 2U)
#define CLOCK_TIMCLK5               (CLOCK_PCLK2 * 2U)
#define CLOCK_TIMCLK6               (CLOCK_PCLK1 * 2U)
#define CLOCK_TIMCLK7               (CLOCK_PCLK1 * 2U)
#define CLOCK_TIMCLK8               (CLOCK_PCLK2 * 2U)
#define CLOCK_TIMCLK15              (CLOCK_PCLK2 * 2U)
#define CLOCK_TIMCLK16              (CLOCK_PCLK2 * 2U)
#define CLOCK_TIMTSCLK              (CLOCK_PCLK1 * 2U)

/**
 * @brief   MCO divider clock frequency.
 */
#if (CLOCK_CFG_MCOSEL == CLOCK_MCOSEL_NOCLOCK) || defined(__DOXYGEN__)
#define CLOCK_MCODIVCLK             0U

#elif CLOCK_CFG_MCOSEL == CLOCK_MCOSEL_LSI
#define CLOCK_MCODIVCLK             CLOCK_LSICLK

#elif CLOCK_CFG_MCOSEL == CLOCK_MCOSEL_IRCOSC
#define CLOCK_MCODIVCLK             CLOCK_IRCOSCCLK

#elif CLOCK_CFG_MCOSEL == CLOCK_MCOSEL_XOSC
#define CLOCK_MCODIVCLK             CLOCK_CFG_XOSCCLK

#elif CLOCK_CFG_MCOSEL == CLOCK_MCOSEL_PLL0PHI
#define CLOCK_MCODIVCLK             CLOCK_PLL0PHI

#elif CLOCK_CFG_MCOSEL == CLOCK_MCOSEL_PLL1PHI
#define CLOCK_MCODIVCLK             CLOCK_PLL1PHI

#else
#error "invalid CLOCK_CFG_MCOSEL value in clock_cfg.h"
#endif

/**
 * @brief   MCO output pin clock frequency.
 */
#if (CLOCK_CFG_MCOPRE_VALUE == 0U)
#define CLOCK_MCOCLK                CLOCK_MCODIVCLK
#elif ((CLOCK_CFG_MCOPRE_VALUE > 0U) && (CLOCK_CFG_MCOPRE_VALUE <= 63U))
#define CLOCK_MCOCLK                (CLOCK_MCODIVCLK / (2U * CLOCK_CFG_MCOPRE_VALUE))
#else
#error "invalid CLOCK_CFG_MCOPRE_VALUE value in clock_cfg.h"
#endif

/**
 * @brief   RTC clock.
 */
#if (CLOCK_CFG_LSIPRE_VALUE == 0U)
#define CLOCK_LSIDIVCLK             CLOCK_LSICLK
#elif ((CLOCK_CFG_LSIPRE_VALUE > 0U) && (CLOCK_CFG_LSIPRE_VALUE <= 31U))
#define CLOCK_LSIDIVCLK             (CLOCK_LSICLK / (2U * CLOCK_CFG_LSIPRE_VALUE))
#else
#error "invalid CLOCK_CFG_LSIPRE_VALUE value in clock_cfg.h"
#endif

#if (CLOCK_CFG_RTCSEL == CLOCK_RTCSEL_NOCLOCK) || defined(__DOXYGEN__)
#define CLOCK_RTCSELCLK             0U

#elif CLOCK_CFG_RTCSEL == CLOCK_RTCSEL_LSI
#define CLOCK_RTCSELCLK             CLOCK_LSIDIVCLK

#elif CLOCK_CFG_RTCSEL == CLOCK_RTCSEL_XOSC
#define CLOCK_RTCSELCLK             CLOCK_CFG_XOSCCLK

#else
#error "invalid CLOCK_CFG_RTCSEL value in clock_cfg.h"
#endif

/**
 * @brief   UART clock.
 */
#if (CLOCK_CFG_UARTSEL == CLOCK_UARTSEL_NOCLOCK) || defined(__DOXYGEN__)
#define CLOCK_UARTSELCLK            0U

#elif CLOCK_CFG_UARTSEL == CLOCK_UARTSEL_IRCOSC
#define CLOCK_UARTSELCLK            CLOCK_IRCOSCCLK

#elif CLOCK_CFG_UARTSEL == CLOCK_UARTSEL_XOSC
#define CLOCK_UARTSELCLK            CLOCK_CFG_XOSCCLK

#elif CLOCK_CFG_UARTSEL == CLOCK_UARTSEL_PLL0PHI
#define CLOCK_UARTSELCLK            CLOCK_PLL0PHI

#elif CLOCK_CFG_UARTSEL == CLOCK_UARTSEL_LSI
#define CLOCK_UARTSELCLK            CLOCK_LSICLK

#else
#error "invalid CLOCK_CFG_UARTSEL value in clock_cfg.h"
#endif

#if ((CLOCK_CFG_UARTPRE_VALUE >= 0U) && (CLOCK_CFG_UARTPRE_VALUE <= 31U))
#define CLOCK_UARTCLK               (CLOCK_UARTSELCLK / (CLOCK_CFG_UARTPRE_VALUE + 1U))
#else
#error "invalid CLOCK_CFG_UARTPRE_VALUE value in clock_cfg.h"
#endif

#if CLOCK_UARTCLK > CLOCK_UARTCLK_MAX
#error "out of limits CLOCK_UARTCLK value"
#endif

#define CLOCK_UART1CLK              CLOCK_UARTCLK
#define CLOCK_UART2CLK              CLOCK_UARTCLK
#define CLOCK_UART3CLK              CLOCK_UARTCLK

/**
 * @brief   I2C clock.
 */
#if (CLOCK_CFG_I2CSEL == CLOCK_I2CSEL_NOCLOCK) || defined(__DOXYGEN__)
#define CLOCK_I2CSELCLK             0U

#elif CLOCK_CFG_I2CSEL == CLOCK_I2CSEL_IRCOSC
#define CLOCK_I2CSELCLK             CLOCK_IRCOSCCLK

#elif CLOCK_CFG_I2CSEL == CLOCK_I2CSEL_XOSC
#define CLOCK_I2CSELCLK             CLOCK_CFG_XOSCCLK

#elif CLOCK_CFG_I2CSEL == CLOCK_I2CSEL_PLL0PHI
#define CLOCK_I2CSELCLK             CLOCK_PLL0PHI

#else
#error "invalid CLOCK_CFG_I2CSEL value in clock_cfg.h"
#endif

#if ((CLOCK_CFG_I2CPRE_VALUE >= 0U) && (CLOCK_CFG_I2CPRE_VALUE <= 31U))
#define CLOCK_I2CCLK                (CLOCK_I2CSELCLK / (CLOCK_CFG_I2CPRE_VALUE + 1U))
#else
#error "invalid CLOCK_CFG_I2CPRE_VALUE value in clock_cfg.h"
#endif

#if CLOCK_I2CCLK > CLOCK_I2CCLK_MAX
#error "out of limits CLOCK_I2CCLK value"
#endif

/**
 * @brief   SPI/I2S clock.
 */
#if (CLOCK_CFG_SPISEL == CLOCK_SPISEL_NOCLOCK) || defined(__DOXYGEN__)
#define CLOCK_SPISELCLK             0U

#elif CLOCK_CFG_SPISEL == CLOCK_SPISEL_IRCOSC
#define CLOCK_SPISELCLK             CLOCK_IRCOSCCLK

#elif CLOCK_CFG_SPISEL == CLOCK_SPISEL_XOSC
#define CLOCK_SPISELCLK             CLOCK_CFG_XOSCCLK

#elif CLOCK_CFG_SPISEL == CLOCK_SPISEL_PLL0PHI
#define CLOCK_SPISELCLK             CLOCK_PLL0PHI

#elif CLOCK_CFG_SPISEL == CLOCK_SPISEL_I2S_CKIN
#define CLOCK_SPISELCLK             CLOCK_CFG_I2S_CKIN

#else
#error "invalid CLOCK_CFG_SPISEL value in clock_cfg.h"
#endif

#if ((CLOCK_CFG_SPIPRE_VALUE >= 0U) && (CLOCK_CFG_SPIPRE_VALUE <= 31U))
#define CLOCK_SPICLK                (CLOCK_SPISELCLK / (CLOCK_CFG_SPIPRE_VALUE + 1U))
#else
#error "invalid CLOCK_CFG_SPIPRE_VALUE value in clock_cfg.h"
#endif

#define CLOCK_SPI1CLK               CLOCK_PCLK2
#define CLOCK_SPI2CLK               CLOCK_PCLK1
#define CLOCK_SPI3CLK               CLOCK_PCLK1
#define CLOCK_SPI4CLK               CLOCK_PCLK2
#define CLOCK_I2S2CLK               CLOCK_SPICLK
#define CLOCK_I2S3CLK               CLOCK_SPICLK

/**
 * @brief   FDCAN clock.
 */
#if (CLOCK_CFG_FDCANSEL == CLOCK_FDCANSEL_NOCLOCK) || defined(__DOXYGEN__)
#define CLOCK_FDCANSELCLK           0U

#elif CLOCK_CFG_FDCANSEL == CLOCK_FDCANSEL_XOSC
#define CLOCK_FDCANSELCLK           CLOCK_CFG_XOSCCLK

#elif CLOCK_CFG_FDCANSEL == CLOCK_FDCANSEL_PLL0PHI
#define CLOCK_FDCANSELCLK           CLOCK_PLL0PHI

#else
#error "invalid CLOCK_CFG_FDCANSEL value in clock_cfg.h"
#endif

#if ((CLOCK_CFG_FDCANPRE_VALUE >= 0U) && (CLOCK_CFG_FDCANPRE_VALUE <= 31U))
#define CLOCK_FDCANCLK              (CLOCK_FDCANSELCLK / (CLOCK_CFG_FDCANPRE_VALUE + 1U))
#else
#error "invalid CLOCK_CFG_FDCANPRE_VALUE value in clock_cfg.h"
#endif

#if CLOCK_FDCANCLK > CLOCK_FDCANCLK_MAX
#error "out of limits CLOCK_FDCANCLK value"
#endif

/**
 * @brief   ADC clock.
 */
#if (CLOCK_CFG_ADCSEL == CLOCK_ADCSEL_NOCLOCK) || defined(__DOXYGEN__)
#define CLOCK_ADCSELCLK             0U

#elif CLOCK_CFG_ADCSEL == CLOCK_ADCSEL_XOSC
#define CLOCK_ADCSELCLK             CLOCK_CFG_XOSCCLK

#elif CLOCK_CFG_ADCSEL == CLOCK_ADCSEL_PLL0PHI
#define CLOCK_ADCSELCLK             CLOCK_PLL0PHI

#elif CLOCK_CFG_ADCSEL == CLOCK_ADCSEL_PLL1PHI
#define CLOCK_ADCSELCLK             CLOCK_PLL1PHI

#else
#error "invalid CLOCK_CFG_ADCSEL value in clock_cfg.h"
#endif
/* The range of values of ADCPRE must be verified */
#if (CLOCK_CFG_ADCPRE_VALUE == 0U)
#define CLOCK_ADCCLK                CLOCK_ADCSELCLK
#elif ((CLOCK_CFG_ADCPRE_VALUE > 0U) && (CLOCK_CFG_ADCPRE_VALUE <= 63U))
#define CLOCK_ADCCLK                (CLOCK_ADCSELCLK / (2U * CLOCK_CFG_ADCPRE_VALUE))
#else
#error "invalid CLOCK_CFG_ADCPRE_VALUE value in clock_cfg.h"
#endif

#define CLOCK_ADC12CLK              CLOCK_ADCCLK
#define CLOCK_ADC345CLK             CLOCK_ADCCLK

/**
 * @brief   SDADC clock.
 */
#if (CLOCK_CFG_SDADCSEL == CLOCK_SDADCSEL_NOCLOCK) || defined(__DOXYGEN__)
#define CLOCK_SDADCSELCLK           0U

#elif CLOCK_CFG_SDADCSEL == CLOCK_SDADCSEL_XOSC
#define CLOCK_SDADCSELCLK           CLOCK_CFG_XOSCCLK

#elif CLOCK_CFG_SDADCSEL == CLOCK_SDADCSEL_PLL0PHI
#define CLOCK_SDADCSELCLK           CLOCK_PLL0PHI

#elif CLOCK_CFG_SDADCSEL == CLOCK_SDADCSEL_PLL1PHI
#define CLOCK_SDADCSELCLK           CLOCK_PLL1PHI

#else
#error "invalid CLOCK_CFG_SDADCSEL value in clock_cfg.h"
#endif
/* The range of values of SDADCPRE must be verified */
#if (CLOCK_CFG_SDADCPRE_VALUE == 0U)
#define CLOCK_SDADCCLK              CLOCK_SDADCSELCLK
#elif ((CLOCK_CFG_SDADCPRE_VALUE > 0U) && (CLOCK_CFG_SDADCPRE_VALUE <= 63U))
#define CLOCK_SDADCCLK              (CLOCK_SDADCSELCLK / (2U * CLOCK_CFG_SDADCPRE_VALUE))
#else
#error "invalid CLOCK_CFG_SDADCPRE_VALUE value in clock_cfg.h"
#endif

#if CLOCK_SDADCCLK > CLOCK_SDADCCLK_MAX
#error "out of limits CLOCK_SDADCCLK value"
#endif

/* Flash wait state (APC = 0) settings.*/
#if (CLOCK_SYSCLKDIV <= 136000000UL) || defined(__DOXYGEN__)
#define CLOCK_NVMRWSC_VALUE         3U /* 0 < core frequency < 136MHz  */

#elif (CLOCK_SYSCLKDIV <= 170000000UL)
#define CLOCK_NVMRWSC_VALUE         4U /* 136MHz < core_freq <= 170MHz */

#elif (CLOCK_SYSCLKDIV <= 204000000UL)
#define CLOCK_NVMRWSC_VALUE         5U /* 170MHz < core_freq <= 204MHz */

#elif (CLOCK_SYSCLKDIV <= 238000000UL)
#define CLOCK_NVMRWSC_VALUE         6U /* 204MHz < core_freq <= 238MHz */

#elif (CLOCK_SYSCLKDIV <= 273000000UL)
#define CLOCK_NVMRWSC_VALUE         7U /* 238MHz < core_freq <= 273MHz */

#else
#define CLOCK_NVMRWSC_VALUE         8U /* 273MHz < core_freq <= 307MHz */

#endif

/*===========================================================================*/
/* Module data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

/**
 * @brief   CMSIS system core clock variable.
 */
extern uint32_t SystemCoreClock;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Initializes clock
 *
 * @api
 */
void clock_init(void);

#ifdef __cplusplus
}
#endif

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/**
 * @brief   Enables AHB1 peripherals clock [Low Word]
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 * @param[in] m         peripheral clock to be enabled
 * @return              value of register AHB1LENR after the update
 *
 * @api
 */
__STATIC_FORCEINLINE uint32_t clock_enable_AHB1L(bool smode, uint32_t m) {

    RCC->AHB1LENR |= m;
    if (smode) {
        RCC->C1_AHB1LSMENR |= m;
#if CLOCK_CFG_SMP_MODE == TRUE
        RCC->C2_AHB1LSMENR |= m;
#endif
    }
    else {
        RCC->C1_AHB1LSMENR &= ~m;
#if CLOCK_CFG_SMP_MODE == TRUE
        RCC->C2_AHB1LSMENR &= ~m;
#endif
    }

    return RCC->AHB1LENR;
}

/**
 * @brief   Disables AHB1 peripherals clock [Low Word]
 *
 * @param[in] m         peripheral clock to be disabled
 * @return              value of register AHB1LENR after the update
 *
 * @api
 */
__STATIC_FORCEINLINE uint32_t clock_disable_AHB1L(uint32_t m) {

    RCC->AHB1LENR &= ~m;
    RCC->C1_AHB1LSMENR &= ~m;
#if CLOCK_CFG_SMP_MODE == TRUE
    RCC->C2_AHB1LSMENR &= ~m;
#endif

    return RCC->AHB1LENR;
}

/**
 * @brief   Checks if AHB1 peripheral clock [Low Word] is enabled
 *
 * @param[in] m         peripheral clock to be checked
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_AHB1L(uint32_t m) {

    return (((RCC->AHB1LENR & m) == m) ? true : false);
}

/**
 * @brief   Resets AHB1 peripherals [Low Word]
 *
 * @param[in] m         peripheral to reset
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_AHB1L(uint32_t m) {

    RCC->AHB1LRSTR |= m;
    RCC->AHB1LRSTR &= ~m;
    (void)RCC->AHB1LRSTR;
}

/**
 * @brief   Enables AHB1 peripherals clock [High Word]
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 * @param[in] m         peripheral clock to be enabled
 * @return              value of register AHB1HENR after the update
 *
 * @api
 */
__STATIC_FORCEINLINE uint32_t clock_enable_AHB1H(bool smode, uint32_t m) {

    RCC->AHB1HENR |= m;
    if (smode) {
        RCC->C1_AHB1HSMENR |= m;
#if CLOCK_CFG_SMP_MODE == TRUE
        RCC->C2_AHB1HSMENR |= m;
#endif
    }
    else {
        RCC->C1_AHB1HSMENR &= ~m;
#if CLOCK_CFG_SMP_MODE == TRUE
        RCC->C2_AHB1HSMENR &= ~m;
#endif
    }

    return RCC->AHB1HENR;
}

/**
 * @brief   Disables AHB1 peripherals clock [High Word]
 *
 * @param[in] m         peripheral clock to be disabled
 * @return              value of register AHB1HENR after the update
 *
 * @api
 */
__STATIC_FORCEINLINE uint32_t clock_disable_AHB1H(uint32_t m) {

    RCC->AHB1HENR &= ~m;
    RCC->C1_AHB1HSMENR &= ~m;
#if CLOCK_CFG_SMP_MODE == TRUE
    RCC->C2_AHB1HSMENR &= ~m;
#endif

    return RCC->AHB1HENR;
}

/**
 * @brief   Checks if AHB1 peripheral clock [High Word] is enabled
 *
 * @param[in] m         peripheral clock to be checked
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_AHB1H(uint32_t m) {

    return (((RCC->AHB1HENR & m) == m) ? true : false);
}

/**
 * @brief   Resets AHB1 peripherals [High Word]
 *
 * @param[in] m         peripheral to reset
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_AHB1H(uint32_t m) {

    RCC->AHB1HRSTR |= m;
    RCC->AHB1HRSTR &= ~m;
    (void)RCC->AHB1HRSTR;
}

/**
 * @brief   Enables AHB2 peripherals clock [Low Word]
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 * @param[in] m         peripheral clock to be enabled
 * @return              value of register AHB2LENR after the update
 *
 * @api
 */
__STATIC_FORCEINLINE uint32_t clock_enable_AHB2L(bool smode, uint32_t m) {

    RCC->AHB2LENR |= m;
    if (smode) {
        RCC->C1_AHB2LSMENR |= m;
#if CLOCK_CFG_SMP_MODE == TRUE
        RCC->C2_AHB2LSMENR |= m;
#endif
    }
    else {
        RCC->C1_AHB2LSMENR &= ~m;
#if CLOCK_CFG_SMP_MODE == TRUE
        RCC->C2_AHB2LSMENR &= ~m;
#endif
    }

    return RCC->AHB2LENR;
}

/**
 * @brief   Disables AHB2 peripherals clock [Low Word]
 *
 * @param[in] m         peripheral clock to be disabled
 * @return              value of register AHB2LENR after the update
 *
 * @api
 */
__STATIC_FORCEINLINE uint32_t clock_disable_AHB2L(uint32_t m) {

    RCC->AHB2LENR &= ~m;
    RCC->C1_AHB2LSMENR &= ~m;
#if CLOCK_CFG_SMP_MODE == TRUE
    RCC->C2_AHB2LSMENR &= ~m;
#endif

    return RCC->AHB2LENR;
}

/**
 * @brief   Checks if AHB2 peripheral clock [Low Word] is enabled
 *
 * @param[in] m         peripheral clock to be checked
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_AHB2L(uint32_t m) {

    return (((RCC->AHB2LENR & m) == m) ? true : false);
}

/**
 * @brief   Resets AHB2 peripherals [Low Word]
 *
 * @param[in] m         peripheral to reset
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_AHB2L(uint32_t m) {

    RCC->AHB2LRSTR |= m;
    RCC->AHB2LRSTR &= ~m;
    (void)RCC->AHB2LRSTR;
}

/**
 * @brief   Enables AHB2 peripherals clock [High Word]
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 * @param[in] m         peripheral clock to be enabled
 * @return              value of register AHB2HENR after the update
 *
 * @api
 */
__STATIC_FORCEINLINE uint32_t clock_enable_AHB2H(bool smode, uint32_t m) {

    RCC->AHB2HENR |= m;
    if (smode) {
        RCC->C1_AHB2HSMENR |= m;
#if CLOCK_CFG_SMP_MODE == TRUE
        RCC->C2_AHB2HSMENR |= m;
#endif
    }
    else {
        RCC->C1_AHB2HSMENR &= ~m;
#if CLOCK_CFG_SMP_MODE == TRUE
        RCC->C2_AHB2HSMENR &= ~m;
#endif
    }

    return RCC->AHB2HENR;
}

/**
 * @brief   Disables AHB2 peripherals clock [High Word]
 *
 * @param[in] m         peripheral clock to be disabled
 * @return              value of register AHB2HENR after the update
 *
 * @api
 */
__STATIC_FORCEINLINE uint32_t clock_disable_AHB2H(uint32_t m) {

    RCC->AHB2HENR &= ~m;
    RCC->C1_AHB2HSMENR &= ~m;
#if CLOCK_CFG_SMP_MODE == TRUE
    RCC->C2_AHB2HSMENR &= ~m;
#endif

    return RCC->AHB2HENR;
}

/**
 * @brief   Checks if AHB2 peripheral clock [High Word] is enabled
 *
 * @param[in] m         peripheral clock to be checked
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_AHB2H(uint32_t m) {

    return (((RCC->AHB2HENR & m) == m) ? true : false);
}

/**
 * @brief   Resets AHB2 peripherals [High Word]
 *
 * @param[in] m         peripheral to reset
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_AHB2H(uint32_t m) {

    RCC->AHB2HRSTR |= m;
    RCC->AHB2HRSTR &= ~m;
    (void)RCC->AHB2HRSTR;
}

/**
 * @brief   Enables APB1 peripherals clock [Low Word]
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 * @param[in] m         peripheral clock to be enabled
 * @return              value of register APB1LENR after the update
 *
 * @api
 */
__STATIC_FORCEINLINE uint32_t clock_enable_APB1L(bool smode, uint32_t m) {

    RCC->APB1LENR |= m;
    if (smode) {
        RCC->C1_APB1LSMENR |= m;
#if CLOCK_CFG_SMP_MODE == TRUE
        RCC->C2_APB1LSMENR |= m;
#endif
    }
    else {
        RCC->C1_APB1LSMENR &= ~m;
#if CLOCK_CFG_SMP_MODE == TRUE
        RCC->C2_APB1LSMENR &= ~m;
#endif
    }

    return RCC->APB1LENR;
}

/**
 * @brief   Disables APB1 peripherals clock [Low Word]
 *
 * @param[in] m         peripheral clock to be disabled
 * @return              value of register APB1LENR after the update
 *
 * @api
 */
__STATIC_FORCEINLINE uint32_t clock_disable_APB1L(uint32_t m) {

    RCC->APB1LENR &= ~m;
    RCC->C1_APB1LSMENR &= ~m;
#if CLOCK_CFG_SMP_MODE == TRUE
    RCC->C2_APB1LSMENR &= ~m;
#endif

    return RCC->APB1LENR;
}

/**
 * @brief   Checks if APB1 peripheral clock [Low Word] is enabled
 *
 * @param[in] m         peripheral clock to be checked
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_APB1L(uint32_t m) {

    return (((RCC->APB1LENR & m) == m) ? true : false);
}

/**
 * @brief   Resets APB1 peripherals [Low Word]
 *
 * @param[in] m         peripheral to reset
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_APB1L(uint32_t m) {

    RCC->APB1LRSTR |= m;
    RCC->APB1LRSTR &= ~m;
    (void)RCC->APB1LRSTR;
}

/**
 * @brief   Enables APB2 peripherals clock [Low Word]
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 * @param[in] m         peripheral clock to be enabled
 * @return              value of register APB2LENR after the update
 *
 * @api
 */
__STATIC_FORCEINLINE uint32_t clock_enable_APB2L(bool smode, uint32_t m) {

    RCC->APB2LENR |= m;
    if (smode) {
        RCC->C1_APB2LSMENR |= m;
#if CLOCK_CFG_SMP_MODE == TRUE
        RCC->C2_APB2LSMENR |= m;
#endif
    }
    else {
        RCC->C1_APB2LSMENR &= ~m;
#if CLOCK_CFG_SMP_MODE == TRUE
        RCC->C2_APB2LSMENR &= ~m;
#endif
    }

    return RCC->APB2LENR;
}

/**
 * @brief   Disables APB2 peripherals clock [Low Word]
 *
 * @param[in] m         peripheral clock to be disabled
 * @return              value of register APB2LENR after the update
 *
 * @api
 */
__STATIC_FORCEINLINE uint32_t clock_disable_APB2L(uint32_t m) {

    RCC->APB2LENR &= ~m;
    RCC->C1_APB2LSMENR &= ~m;
#if CLOCK_CFG_SMP_MODE == TRUE
    RCC->C2_APB2LSMENR &= ~m;
#endif

    return RCC->APB2LENR;
}

/**
 * @brief   Checks if APB2 peripheral clock [Low Word] is enabled
 *
 * @param[in] m         peripheral clock to be checked
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_APB2L(uint32_t m) {

    return (((RCC->APB2LENR & m) == m) ? true : false);
}

/**
 * @brief   Resets APB2 peripherals [Low Word]
 *
 * @param[in] m         peripheral to reset
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_APB2L(uint32_t m) {

    RCC->APB2LRSTR |= m;
    RCC->APB2LRSTR &= ~m;
    (void)RCC->APB2LRSTR;
}

/**
 * @brief   Enables APB2 peripherals clock [High Word]
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 * @param[in] m         peripheral clock to be enabled
 * @return              value of register APB2HENR after the update
 *
 * @api
 */
__STATIC_FORCEINLINE uint32_t clock_enable_APB2H(bool smode, uint32_t m) {

    RCC->APB2HENR |= m;
    if (smode) {
        RCC->C1_APB2HSMENR |= m;
#if CLOCK_CFG_SMP_MODE == TRUE
        RCC->C2_APB2HSMENR |= m;
#endif
    }
    else {
        RCC->C1_APB2HSMENR &= ~m;
#if CLOCK_CFG_SMP_MODE == TRUE
        RCC->C2_APB2HSMENR &= ~m;
#endif
    }

    return RCC->APB2HENR;
}

/**
 * @brief   Disables APB2 peripherals clock [High Word]
 *
 * @param[in] m         peripheral clock to be disabled
 * @return              value of register APB2HENR after the update
 *
 * @api
 */
__STATIC_FORCEINLINE uint32_t clock_disable_APB2H(uint32_t m) {

    RCC->APB2HENR &= ~m;
    RCC->C1_APB2HSMENR &= ~m;
#if CLOCK_CFG_SMP_MODE == TRUE
    RCC->C2_APB2HSMENR &= ~m;
#endif

    return RCC->APB2HENR;
}

/**
 * @brief   Checks if APB2 peripheral clock [High Word] is enabled
 *
 * @param[in] m         peripheral clock to be checked
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_APB2H(uint32_t m) {

    return (((RCC->APB2HENR & m) == m) ? true : false);
}

/**
 * @brief   Resets APB2 peripherals [High Word]
 *
 * @param[in] m         peripheral to reset
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_APB2H(uint32_t m) {

    RCC->APB2HRSTR |= m;
    RCC->APB2HRSTR &= ~m;
    (void)RCC->APB2HRSTR;
}

/**
 * @brief   Enables DMA1 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_DMA1(bool smode) {

    clock_enable_AHB2L(smode, RCC_AHB2LENR_DMA1);
}

/**
 * @brief   Disables DMA1 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_DMA1(void) {

    clock_disable_AHB2L(RCC_AHB2LENR_DMA1);
}

/**
 * @brief   Checks if DMA1 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_DMA1(void) {

    return is_clock_enable_AHB2L(RCC_AHB2LENR_DMA1);
}

/**
 * @brief   Resets DMA1
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_DMA1(void) {

    clock_reset_AHB2L(RCC_AHB2LRSTR_DMA1);
}

/**
 * @brief   Enables DMA2 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_DMA2(bool smode) {

    clock_enable_AHB1L(smode, RCC_AHB1LENR_DMA2);
}

/**
 * @brief   Disables DMA2 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_DMA2(void) {

    clock_disable_AHB1L(RCC_AHB1LENR_DMA2);
}

/**
 * @brief   Checks if DMA2 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_DMA2(void) {

    return is_clock_enable_AHB1L(RCC_AHB1LENR_DMA2);
}

/**
 * @brief   Resets DMA2
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_DMA2(void) {

    clock_reset_AHB1L(RCC_AHB1LRSTR_DMA2);
}

/**
 * @brief   Enables DMAMUX1 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_DMAMUX1(bool smode) {

    clock_enable_AHB2L(smode, RCC_AHB2LENR_DMAMUX1);
}

/**
 * @brief   Disables DMAMUX1 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_DMAMUX1(void) {

    clock_disable_AHB2L(RCC_AHB2LENR_DMAMUX1);
}

/**
 * @brief   Checks if DMAMUX1 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_DMAMUX1(void) {

    return is_clock_enable_AHB2L(RCC_AHB2LENR_DMAMUX1);
}

/**
 * @brief   Resets DMAMUX1
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_DMAMUX1(void) {

    clock_reset_AHB2L(RCC_AHB2LRSTR_DMAMUX1);
}

/**
 * @brief   Enables CORDIC clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_CORDIC(bool smode) {

    clock_enable_AHB1L(smode, RCC_AHB1LENR_CORDIC);
}

/**
 * @brief   Disables CORDIC clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_CORDIC(void) {

    clock_disable_AHB1L(RCC_AHB1LENR_CORDIC);
}

/**
 * @brief   Checks if CORDIC clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_CORDIC(void) {

    return is_clock_enable_AHB1L(RCC_AHB1LENR_CORDIC);
}

/**
 * @brief   Resets CORDIC
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_CORDIC(void) {

    clock_reset_AHB1L(RCC_AHB1LRSTR_CORDIC);
}

/**
 * @brief   Enables CRC clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_CRC(bool smode) {

    clock_enable_AHB1L(smode, RCC_AHB1LENR_CRC);
}

/**
 * @brief   Disables CRC clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_CRC(void) {

    clock_disable_AHB1L(RCC_AHB1LENR_CRC);
}

/**
 * @brief   Checks if CRC clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_CRC(void) {

    return is_clock_enable_AHB1L(RCC_AHB1LENR_CRC);
}

/**
 * @brief   Resets CRC
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_CRC(void) {

    clock_reset_AHB1L(RCC_AHB1LRSTR_CRC);
}

/**
 * @brief   Enables HSEM clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_HSEM(bool smode) {

    clock_enable_AHB1L(smode, RCC_AHB1LENR_HSEM);
}

/**
 * @brief   Disables HSEM clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_HSEM(void) {

    clock_disable_AHB1L(RCC_AHB1LENR_HSEM);
}

/**
 * @brief   Checks if HSEM clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_HSEM(void) {

    return is_clock_enable_AHB1L(RCC_AHB1LENR_HSEM);
}

/**
 * @brief   Resets HSEM
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_HSEM(void) {

    clock_reset_AHB1L(RCC_AHB1LRSTR_HSEM);
}

/**
 * @brief   Enables ADC12 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_ADC12(bool smode) {

    clock_enable_AHB2H(smode, RCC_AHB2HENR_ADC1_ADC2);
}

/**
 * @brief   Disables ADC12 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_ADC12(void) {

    clock_disable_AHB2H(RCC_AHB2HENR_ADC1_ADC2);
}

/**
 * @brief   Checks if ADC12 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_ADC12(void) {

    return is_clock_enable_AHB2H(RCC_AHB2HENR_ADC1_ADC2);
}

/**
 * @brief   Resets ADC12
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_ADC12(void) {

    clock_reset_AHB2H(RCC_AHB2HRSTR_ADC1_ADC2);
}

/**
 * @brief   Enables ADC345 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_ADC345(bool smode) {

    clock_enable_AHB1H(smode, RCC_AHB1HENR_ADC3_ADC4_ADC5);
}

/**
 * @brief   Disables ADC345 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_ADC345(void) {

    clock_disable_AHB1H(RCC_AHB1HENR_ADC3_ADC4_ADC5);
}

/**
 * @brief   Checks if ADC345 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_ADC345(void) {

    return is_clock_enable_AHB1H(RCC_AHB1HENR_ADC3_ADC4_ADC5);
}

/**
 * @brief   Resets ADC345
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_ADC345(void) {

    clock_reset_AHB1H(RCC_AHB1HRSTR_ADC3_ADC4_ADC5);
}

/**
 * @brief   Enables GPIOA clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_GPIOA(bool smode) {

    clock_enable_AHB2L(smode, RCC_AHB2LENR_GPIOA);
}

/**
 * @brief   Disables GPIOA clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_GPIOA(void) {

    clock_disable_AHB2L(RCC_AHB2LENR_GPIOA);
}

/**
 * @brief   Checks if GPIOA clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_GPIOA(void) {

    return is_clock_enable_AHB2L(RCC_AHB2LENR_GPIOA);
}

/**
 * @brief   Resets GPIOA
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_GPIOA(void) {

    clock_reset_AHB2L(RCC_AHB2LRSTR_GPIOA);
}

/**
 * @brief   Enables GPIOB clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_GPIOB(bool smode) {

    clock_enable_AHB2L(smode, RCC_AHB2LENR_GPIOB);
}

/**
 * @brief   Disables GPIOB clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_GPIOB(void) {

    clock_disable_AHB2L(RCC_AHB2LENR_GPIOB);
}

/**
 * @brief   Checks if GPIOB clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_GPIOB(void) {

    return is_clock_enable_AHB2L(RCC_AHB2LENR_GPIOB);
}

/**
 * @brief   Resets GPIOB
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_GPIOB(void) {

    clock_reset_AHB2L(RCC_AHB2LRSTR_GPIOB);
}

/**
 * @brief   Enables GPIOC clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_GPIOC(bool smode) {

    clock_enable_AHB2L(smode, RCC_AHB2LENR_GPIOC);
}

/**
 * @brief   Disables GPIOC clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_GPIOC(void) {

    clock_disable_AHB2L(RCC_AHB2LENR_GPIOC);
}

/**
 * @brief   Checks if GPIOC clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_GPIOC(void) {

    return is_clock_enable_AHB2L(RCC_AHB2LENR_GPIOC);
}

/**
 * @brief   Resets GPIOC
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_GPIOC(void) {

    clock_reset_AHB2L(RCC_AHB2LRSTR_GPIOC);
}

/**
 * @brief   Enables GPIOD clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_GPIOD(bool smode) {

    clock_enable_AHB2L(smode, RCC_AHB2LENR_GPIOD);
}

/**
 * @brief   Disables GPIOD clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_GPIOD(void) {

    clock_disable_AHB2L(RCC_AHB2LENR_GPIOD);
}

/**
 * @brief   Checks if GPIOD clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_GPIOD(void) {

    return is_clock_enable_AHB2L(RCC_AHB2LENR_GPIOD);
}
 
/**
 * @brief   Resets GPIOD
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_GPIOD(void) {

    clock_reset_AHB2L(RCC_AHB2LRSTR_GPIOD);
}

/**
 * @brief   Enables GPIOE clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_GPIOE(bool smode) {

    clock_enable_AHB2L(smode, RCC_AHB2LENR_GPIOE);
}

/**
 * @brief   Disables GPIOE clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_GPIOE(void) {

    clock_disable_AHB2L(RCC_AHB2LENR_GPIOE);
}

/**
 * @brief   Checks if GPIOE clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_GPIOE(void) {

    return is_clock_enable_AHB2L(RCC_AHB2LENR_GPIOE);
}

/**
 * @brief   Resets GPIOE
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_GPIOE(void) {

    clock_reset_AHB2L(RCC_AHB2LRSTR_GPIOE);
}

/**
 * @brief   Enables GPIOF clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_GPIOF(bool smode) {

    clock_enable_AHB2L(smode, RCC_AHB2LENR_GPIOF);
}

/**
 * @brief   Disables GPIOF clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_GPIOF(void) {

    clock_disable_AHB2L(RCC_AHB2LENR_GPIOF);
}

/**
 * @brief   Checks if GPIOF clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_GPIOF(void) {

    return is_clock_enable_AHB2L(RCC_AHB2LENR_GPIOF);
}

/**
 * @brief   Resets GPIOF
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_GPIOF(void) {

    clock_reset_AHB2L(RCC_AHB2LRSTR_GPIOF);
}

/**
 * @brief   Enables GPIOG clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_GPIOG(bool smode) {

    clock_enable_AHB2L(smode, RCC_AHB2LENR_GPIOG);
}

/**
 * @brief   Disables GPIOG clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_GPIOG(void) {

    clock_disable_AHB2L(RCC_AHB2LENR_GPIOG);
}

/**
 * @brief   Checks if GPIOG clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_GPIOG(void) {

    return is_clock_enable_AHB2L(RCC_AHB2LENR_GPIOG);
}

/**
 * @brief   Resets GPIOG
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_GPIOG(void) {

    clock_reset_AHB2L(RCC_AHB2LRSTR_GPIOG);
}

/**
 * @brief   Enables GPIOH clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_GPIOH(bool smode) {

    clock_enable_AHB2L(smode, RCC_AHB2LENR_GPIOH);
}

/**
 * @brief   Disables GPIOH clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_GPIOH(void) {

    clock_disable_AHB2L(RCC_AHB2LENR_GPIOH);
}

/**
 * @brief   Checks if GPIOH clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_GPIOH(void) {

    return is_clock_enable_AHB2L(RCC_AHB2LENR_GPIOH);
}

/**
 * @brief   Resets GPIOH
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_GPIOH(void) {

    clock_reset_AHB2L(RCC_AHB2LRSTR_GPIOH);
}

/**
 * @brief   Enables GPIOI clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_GPIOI(bool smode) {

    clock_enable_AHB2L(smode, RCC_AHB2LENR_GPIOI);
}

/**
 * @brief   Disables GPIOI clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_GPIOI(void) {

    clock_disable_AHB2L(RCC_AHB2LENR_GPIOI);
}

/**
 * @brief   Checks if GPIOI clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_GPIOI(void) {

    return is_clock_enable_AHB2L(RCC_AHB2LENR_GPIOI);
}

/**
 * @brief   Resets GPIOI
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_GPIOI(void) {

    clock_reset_AHB2L(RCC_AHB2LRSTR_GPIOI);
}

/**
 * @brief   Enables BDAC1 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_BDAC1(bool smode) {

    clock_enable_AHB2H(smode, RCC_AHB2HENR_BDAC1);
}

/**
 * @brief   Disables BDAC1 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_BDAC1(void) {

    clock_disable_AHB2H(RCC_AHB2HENR_BDAC1);
}

/**
 * @brief   Checks if BDAC1 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_BDAC1(void) {

    return is_clock_enable_AHB2H(RCC_AHB2HENR_BDAC1);
}

/**
 * @brief   Resets BDAC1
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_BDAC1(void) {

    clock_reset_AHB2H(RCC_AHB2HRSTR_BDAC1);
}

/**
 * @brief   Enables DAC1 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_DAC1(bool smode) {

    clock_enable_AHB2H(smode, RCC_AHB2HENR_DAC1);
}

/**
 * @brief   Disables DAC1 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_DAC1(void) {

    clock_disable_AHB2H(RCC_AHB2HENR_DAC1);
}

/**
 * @brief   Checks if DAC1 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_DAC1(void) {

    return is_clock_enable_AHB2H(RCC_AHB2HENR_DAC1);
}

/**
 * @brief   Resets DAC1
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_DAC1(void) {

    clock_reset_AHB2H(RCC_AHB2HRSTR_DAC1);
}

/**
 * @brief   Enables DAC2 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_DAC2(bool smode) {

    clock_enable_AHB2H(smode, RCC_AHB2HENR_DAC2);
}

/**
 * @brief   Disables DAC2 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_DAC2(void) {

    clock_disable_AHB2H(RCC_AHB2HENR_DAC2);
}

/**
 * @brief   Checks if DAC2 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_DAC2(void) {

    return is_clock_enable_AHB2H(RCC_AHB2HENR_DAC2);
}

/**
 * @brief   Resets DAC2
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_DAC2(void) {

    clock_reset_AHB2H(RCC_AHB2HRSTR_DAC2);
}

/**
 * @brief   Enables DAC3 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_DAC3(bool smode) {

    clock_enable_AHB1H(smode, RCC_AHB1HENR_DAC3);
}

/**
 * @brief   Disables DAC3 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_DAC3(void) {

    clock_disable_AHB1H(RCC_AHB1HENR_DAC3);
}

/**
 * @brief   Checks if DAC3 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_DAC3(void) {

    return is_clock_enable_AHB1H(RCC_AHB1HENR_DAC3);
}

/**
 * @brief   Resets DAC3
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_DAC3(void) {

    clock_reset_AHB1H(RCC_AHB1HRSTR_DAC3);
}

/**
 * @brief   Enables DAC4 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_DAC4(bool smode) {

    clock_enable_AHB1H(smode, RCC_AHB1HENR_DAC4);
}

/**
 * @brief   Disables DAC4 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_DAC4(void) {

    clock_disable_AHB1H(RCC_AHB1HENR_DAC4);
}

/**
 * @brief   Checks if DAC4 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_DAC4(void) {

    return is_clock_enable_AHB1H(RCC_AHB1HENR_DAC4);
}

/**
 * @brief   Resets DAC4
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_DAC4(void) {

    clock_reset_AHB1H(RCC_AHB1HRSTR_DAC4);
}

/**
 * @brief   Enables COMP1 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_COMP1(bool smode) {

    clock_enable_AHB2H(smode, RCC_AHB2HENR_COMP1_DIG);
}

/**
 * @brief   Disables COMP1 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_COMP1(void) {

    clock_disable_AHB2H(RCC_AHB2HENR_COMP1_DIG);
}

/**
 * @brief   Checks if COMP1 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_COMP1(void) {

    return is_clock_enable_AHB2H(RCC_AHB2HENR_COMP1_DIG);
}

/**
 * @brief   Resets COMP1
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_COMP1(void) {

    clock_reset_AHB2H(RCC_AHB2HRSTR_COMP1_DIG);
}

/**
 * @brief   Enables COMP2 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_COMP2(bool smode) {

    clock_enable_AHB1H(smode, RCC_AHB1HENR_COMP2_DIG);
}

/**
 * @brief   Disables COMP2 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_COMP2(void) {

    clock_disable_AHB1H(RCC_AHB1HENR_COMP2_DIG);
}

/**
 * @brief   Checks if COMP2 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_COMP2(void) {

    return is_clock_enable_AHB1H(RCC_AHB1HENR_COMP2_DIG);
}

/**
 * @brief   Resets COMP2
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_COMP2(void) {

    clock_reset_AHB1H(RCC_AHB1HRSTR_COMP2_DIG);
}

/**
 * @brief   Enables HRTIM1 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_HRTIM1(bool smode) {

    clock_enable_AHB1H(smode, RCC_AHB1HENR_HRTIMER1);
}

/**
 * @brief   Disables HRTIM1 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_HRTIM1(void) {

    clock_disable_AHB1H(RCC_AHB1HENR_HRTIMER1);
}

/**
 * @brief   Checks if HRTIM1 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_HRTIM1(void) {

    return is_clock_enable_AHB1H(RCC_AHB1HENR_HRTIMER1);
}

/**
 * @brief   Resets HRTIM1
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_HRTIM1(void) {

    clock_reset_AHB1H(RCC_AHB1HRSTR_HRTIMER1);
}

/**
 * @brief   Enables HRTIM2 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_HRTIM2(bool smode) {

    clock_enable_AHB1H(smode, RCC_AHB1HENR_HRTIMER2);
}

/**
 * @brief   Disables HRTIM2 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_HRTIM2(void) {

    clock_disable_AHB1H(RCC_AHB1HENR_HRTIMER2);
}

/**
 * @brief   Checks if HRTIM2 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_HRTIM2(void) {

    return is_clock_enable_AHB1H(RCC_AHB1HENR_HRTIMER2);
}

/**
 * @brief   Resets HRTIM2
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_HRTIM2(void) {

    clock_reset_AHB1H(RCC_AHB1HRSTR_HRTIMER2);
}

/**
 * @brief   Enables WWDG1 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_WWDG1(bool smode) {

    clock_enable_APB1L(smode, RCC_APB1LENR_WWDG1);
}

/**
 * @brief   Disables WWDG1 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_WWDG1(void) {

    clock_disable_APB1L(RCC_APB1LENR_WWDG1);
}

/**
 * @brief   Checks if WWDG1 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_WWDG1(void) {

    return is_clock_enable_APB1L(RCC_APB1LENR_WWDG1);
}

/**
 * @brief   Resets WWDG1
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_WWDG1(void) {

    clock_reset_APB1L(RCC_APB1LRSTR_WWDG1);
}

/**
 * @brief   Enables WWDG2 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_WWDG2(bool smode) {

    clock_enable_APB1L(smode, RCC_APB1LENR_WWDG2);
}

/**
 * @brief   Disables WWDG2 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_WWDG2(void) {

    clock_disable_APB1L(RCC_APB1LENR_WWDG2);
}

/**
 * @brief   Checks if WWDG2 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_WWDG2(void) {

    return is_clock_enable_APB1L(RCC_APB1LENR_WWDG2);
}

/**
 * @brief   Resets WWDG2
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_WWDG2(void) {

    clock_reset_APB1L(RCC_APB1LRSTR_WWDG2);
}

/**
 * @brief   Enables IWDG1 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_IWDG1(bool smode) {

    clock_enable_APB1L(smode, RCC_APB1LENR_IWDG1);
}

/**
 * @brief   Disables IWDG1 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_IWDG1(void) {

    clock_disable_APB1L(RCC_APB1LENR_IWDG1);
}

/**
 * @brief   Checks if IWDG1 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_IWDG1(void) {

    return is_clock_enable_APB1L(RCC_APB1LENR_IWDG1);
}

/**
 * @brief   Resets IWDG1
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_IWDG1(void) {

    clock_reset_APB1L(RCC_APB1LRSTR_IWDG1);
}

/**
 * @brief   Enables IWDG2 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_IWDG2(bool smode) {

    clock_enable_APB1L(smode, RCC_APB1LENR_IWDG2);
}

/**
 * @brief   Disables IWDG2 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_IWDG2(void) {

    clock_disable_APB1L(RCC_APB1LENR_IWDG2);
}

/**
 * @brief   Checks if IWDG2 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_IWDG2(void) {

    return is_clock_enable_APB1L(RCC_APB1LENR_IWDG2);
}

/**
 * @brief   Resets IWDG2
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_IWDG2(void) {

    clock_reset_APB1L(RCC_APB1LRSTR_IWDG2);
}

/**
 * @brief   Enables I2C1 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_I2C1(bool smode) {

    clock_enable_APB1L(smode, RCC_APB1LENR_I2C1);
}

/**
 * @brief   Disables I2C1 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_I2C1(void) {

    clock_disable_APB1L(RCC_APB1LENR_I2C1);
}

/**
 * @brief   Checks if I2C1 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_I2C1(void) {

    return is_clock_enable_APB1L(RCC_APB1LENR_I2C1);
}

/**
 * @brief   Enables I2C2 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_I2C2(bool smode) {

    clock_enable_APB1L(smode, RCC_APB1LENR_I2C2);
}

/**
 * @brief   Disables I2C2 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_I2C2(void) {

    clock_disable_APB1L(RCC_APB1LENR_I2C2);
}

/**
 * @brief   Checks if I2C2 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_I2C2(void) {

    return is_clock_enable_APB1L(RCC_APB1LENR_I2C2);
}

/**
 * @brief   Enables SPI1 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_SPI1(bool smode) {

    clock_enable_APB2L(smode, RCC_APB2LENR_SPI1);
}

/**
 * @brief   Disables SPI1 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_SPI1(void) {

    clock_disable_APB2L(RCC_APB2LENR_SPI1);
}

/**
 * @brief   Checks if SPI1 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_SPI1(void) {

    return is_clock_enable_APB2L(RCC_APB2LENR_SPI1);
}

/**
 * @brief   Resets SPI1
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_SPI1(void) {

    clock_reset_APB2L(RCC_APB2LRSTR_SPI1);
}

/**
 * @brief   Enables SPI2 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_SPI2(bool smode) {

    clock_enable_APB1L(smode, RCC_APB1LENR_SPI2);
}

/**
 * @brief   Disables SPI2 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_SPI2(void) {

    clock_disable_APB1L(RCC_APB1LENR_SPI2);
}

/**
 * @brief   Checks if SPI2 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_SPI2(void) {

    return is_clock_enable_APB1L(RCC_APB1LENR_SPI2);
}

/**
 * @brief   Resets SPI2
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_SPI2(void) {

    clock_reset_APB1L(RCC_APB1LRSTR_SPI2);
}

/**
 * @brief   Enables SPI3 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_SPI3(bool smode) {

    clock_enable_APB1L(smode, RCC_APB1LENR_SPI3);
}

/**
 * @brief   Disables SPI3 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_SPI3(void) {

    clock_disable_APB1L(RCC_APB1LENR_SPI3);
}

/**
 * @brief   Checks if SPI3 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_SPI3(void) {

    return is_clock_enable_APB1L(RCC_APB1LENR_SPI3);
}

/**
 * @brief   Resets SPI3
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_SPI3(void) {

    clock_reset_APB1L(RCC_APB1LRSTR_SPI3);
}

/**
 * @brief   Enables SPI4 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_SPI4(bool smode) {

    clock_enable_APB2L(smode, RCC_APB2LENR_SPI4);
}

/**
 * @brief   Disables SPI4 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_SPI4(void) {

    clock_disable_APB2L(RCC_APB2LENR_SPI4);
}

/**
 * @brief   Checks if SPI4 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_SPI4(void) {

    return is_clock_enable_APB2L(RCC_APB2LENR_SPI4);
}

/**
 * @brief   Resets SPI4
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_SPI4(void) {

    clock_reset_APB2L(RCC_APB2LRSTR_SPI4);
}

/**
 * @brief   Enables TIM1 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_TIM1(bool smode) {

    clock_enable_APB2L(smode, RCC_APB2LENR_TIM1_PWM);
}

/**
 * @brief   Disables TIM1 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_TIM1(void) {

    clock_disable_APB2L(RCC_APB2LENR_TIM1_PWM);
}

/**
 * @brief   Checks if TIM1 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_TIM1(void) {

    return is_clock_enable_APB2L(RCC_APB2LENR_TIM1_PWM);
}

/**
 * @brief   Resets TIM1
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_TIM1(void) {

    clock_reset_APB2L(RCC_APB2LRSTR_TIM1_PWM);
}

/**
 * @brief   Enables TIM2 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_TIM2(bool smode) {

    clock_enable_APB1L(smode, RCC_APB1LENR_TIM2);
}

/**
 * @brief   Disables TIM2 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_TIM2(void) {

    clock_disable_APB1L(RCC_APB1LENR_TIM2);
}

/**
 * @brief   Checks if TIM2 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_TIM2(void) {

    return is_clock_enable_APB1L(RCC_APB1LENR_TIM2);
}

/**
 * @brief   Resets TIM2
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_TIM2(void) {

    clock_reset_APB1L(RCC_APB1LRSTR_TIM2);
}

/**
 * @brief   Enables TIM3 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_TIM3(bool smode) {

    clock_enable_APB1L(smode, RCC_APB1LENR_TIM3);
}

/**
 * @brief   Disables TIM3 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_TIM3(void) {

    clock_disable_APB1L(RCC_APB1LENR_TIM3);
}

/**
 * @brief   Checks if TIM3 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_TIM3(void) {

    return is_clock_enable_APB1L(RCC_APB1LENR_TIM3);
}

/**
 * @brief   Resets TIM3
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_TIM3(void) {

    clock_reset_APB1L(RCC_APB1LRSTR_TIM3);
}

/**
 * @brief   Enables TIM4 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_TIM4(bool smode) {

    clock_enable_APB2L(smode, RCC_APB2LENR_TIM4);
}

/**
 * @brief   Disables TIM4 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_TIM4(void) {

    clock_disable_APB2L(RCC_APB2LENR_TIM4);
}

/**
 * @brief   Checks if TIM4 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_TIM4(void) {

    return is_clock_enable_APB2L(RCC_APB2LENR_TIM4);
}

/**
 * @brief   Resets TIM4
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_TIM4(void) {

    clock_reset_APB2L(RCC_APB2LRSTR_TIM4);
}

/**
 * @brief   Enables TIM5 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_TIM5(bool smode) {

    clock_enable_APB2L(smode, RCC_APB2LENR_TIM5);
}

/**
 * @brief   Disables TIM5 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_TIM5(void) {

    clock_disable_APB2L(RCC_APB2LENR_TIM5);
}

/**
 * @brief   Checks if TIM5 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_TIM5(void) {

    return is_clock_enable_APB2L(RCC_APB2LENR_TIM5);
}

/**
 * @brief   Resets TIM5
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_TIM5(void) {

    clock_reset_APB2L(RCC_APB2LRSTR_TIM5);
}

/**
 * @brief   Enables TIM6 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_TIM6(bool smode) {

    clock_enable_APB1L(smode, RCC_APB1LENR_TIM6);
}

/**
 * @brief   Disables TIM6 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_TIM6(void) {

    clock_disable_APB1L(RCC_APB1LENR_TIM6);
}

/**
 * @brief   Checks if TIM6 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_TIM6(void) {

    return is_clock_enable_APB1L(RCC_APB1LENR_TIM6);
}

/**
 * @brief   Resets TIM6
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_TIM6(void) {

    clock_reset_APB1L(RCC_APB1LRSTR_TIM6);
}

/**
 * @brief   Enables TIM7 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_TIM7(bool smode) {

    clock_enable_APB1L(smode, RCC_APB1LENR_TIM7);
}

/**
 * @brief   Disables TIM7 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_TIM7(void) {

    clock_disable_APB1L(RCC_APB1LENR_TIM7);
}

/**
 * @brief   Checks if TIM7 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_TIM7(void) {

    return is_clock_enable_APB1L(RCC_APB1LENR_TIM7);
}

/**
 * @brief   Resets TIM7
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_TIM7(void) {

    clock_reset_APB1L(RCC_APB1LRSTR_TIM7);
}

/**
 * @brief   Enables TIM8 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_TIM8(bool smode) {

    clock_enable_APB2L(smode, RCC_APB2LENR_TIM8_PWM);
}

/**
 * @brief   Disables TIM8 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_TIM8(void) {

    clock_disable_APB2L(RCC_APB2LENR_TIM8_PWM);
}

/**
 * @brief   Checks if TIM8 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_TIM8(void) {

    return is_clock_enable_APB2L(RCC_APB2LENR_TIM8_PWM);
}

/**
 * @brief   Resets TIM8
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_TIM8(void) {

    clock_reset_APB2L(RCC_APB2LRSTR_TIM8_PWM);
}

/**
 * @brief   Enables TIM15 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_TIM15(bool smode) {

    clock_enable_APB2L(smode, RCC_APB2LENR_TIM15);
}

/**
 * @brief   Disables TIM15 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_TIM15(void) {

    clock_disable_APB2L(RCC_APB2LENR_TIM15);
}

/**
 * @brief   Checks if TIM15 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_TIM15(void) {

    return is_clock_enable_APB2L(RCC_APB2LENR_TIM15);
}

/**
 * @brief   Resets TIM15
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_TIM15(void) {

    clock_reset_APB2L(RCC_APB2LRSTR_TIM15);
}

/**
 * @brief   Enables TIM16 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_TIM16(bool smode) {

    clock_enable_APB2L(smode, RCC_APB2LENR_TIM16);
}

/**
 * @brief   Disables TIM16 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_TIM16(void) {

    clock_disable_APB2L(RCC_APB2LENR_TIM16);
}

/**
 * @brief   Checks if TIM16 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_TIM16(void) {

    return is_clock_enable_APB2L(RCC_APB2LENR_TIM16);
}

/**
 * @brief   Resets TIM16
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_TIM16(void) {

    clock_reset_APB2L(RCC_APB2LRSTR_TIM16);
}

/**
 * @brief   Enables UART1 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_UART1(bool smode) {

    clock_enable_APB2L(smode, RCC_APB2LENR_UART1);
}

/**
 * @brief   Disables UART1 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_UART1(void) {

    clock_disable_APB2L(RCC_APB2LENR_UART1);
}

/**
 * @brief   Checks if UART1 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_UART1(void) {

    return is_clock_enable_APB2L(RCC_APB2LENR_UART1);
}

/**
 * @brief   Resets UART1
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_UART1(void) {

    clock_reset_APB2L(RCC_APB2LRSTR_UART1);
}

/**
 * @brief   Enables UART2 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_UART2(bool smode) {

    clock_enable_APB1L(smode, RCC_APB1LENR_UART2);
}

/**
 * @brief   Disables UART2 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_UART2(void) {

    clock_disable_APB1L(RCC_APB1LENR_UART2);
}

/**
 * @brief   Checks if UART2 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_UART2(void) {

    return is_clock_enable_APB1L(RCC_APB1LENR_UART2);
}

/**
 * @brief   Resets UART2
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_UART2(void) {

    clock_reset_APB1L(RCC_APB1LRSTR_UART2);
}

/**
 * @brief   Enables UART3 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_UART3(bool smode) {

    clock_enable_APB1L(smode, RCC_APB1LENR_UART3);
}

/**
 * @brief   Disables UART3 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_UART3(void) {

    clock_disable_APB1L(RCC_APB1LENR_UART3);
}

/**
 * @brief   Checks if UART3 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_UART3(void) {

    return is_clock_enable_APB1L(RCC_APB1LENR_UART3);
}

/**
 * @brief   Resets UART3
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_UART3(void) {

    clock_reset_APB1L(RCC_APB1LRSTR_UART3);
}

/**
 * @brief   Enables SDADC1 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_SDADC1(bool smode) {

    clock_enable_APB2H(smode, RCC_APB2HENR_SD_ADC1);
}

/**
 * @brief   Disables SDADC1 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_SDADC1(void) {

    clock_disable_APB2H(RCC_APB2HENR_SD_ADC1);
}

/**
 * @brief   Checks if SDADC1 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_SDADC1(void) {

    return is_clock_enable_APB2H(RCC_APB2HENR_SD_ADC1);
}

/**
 * @brief   Resets SDADC1
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_SDADC1(void) {

    clock_reset_APB2H(RCC_APB2HRSTR_SD_ADC1);
}

/**
 * @brief   Enables SDADC2 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_SDADC2(bool smode) {

    clock_enable_APB2H(smode, RCC_APB2HENR_SD_ADC2);
}

/**
 * @brief   Disables SDADC2 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_SDADC2(void) {

    clock_disable_APB2H(RCC_APB2HENR_SD_ADC2);
}

/**
 * @brief   Checks if SDADC2 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_SDADC2(void) {

    return is_clock_enable_APB2H(RCC_APB2HENR_SD_ADC2);
}

/**
 * @brief   Resets SDADC2
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_SDADC2(void) {

    clock_reset_APB2H(RCC_APB2HRSTR_SD_ADC2);
}

/**
 * @brief   Enables FDCAN1 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_FDCAN1(bool smode) {

    clock_enable_APB2H(smode, RCC_APB2HENR_FDCAN1);
}

/**
 * @brief   Disables FDCAN1 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_FDCAN1(void) {

    clock_disable_APB2H(RCC_APB2HENR_FDCAN1);
}

/**
 * @brief   Checks if FDCAN1 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_FDCAN1(void) {

    return is_clock_enable_APB2H(RCC_APB2HENR_FDCAN1);
}

/**
 * @brief   Resets FDCAN1
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_FDCAN1(void) {

    clock_reset_APB2H(RCC_APB2HRSTR_FDCAN1);
}

/**
 * @brief   Enables FDCAN2 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_FDCAN2(bool smode) {

    clock_enable_APB2H(smode, RCC_APB2HENR_FDCAN2);
}

/**
 * @brief   Disables FDCAN2 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_FDCAN2(void) {

    clock_disable_APB2H(RCC_APB2HENR_FDCAN2);
}

/**
 * @brief   Checks if FDCAN2 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_FDCAN2(void) {

    return is_clock_enable_APB2H(RCC_APB2HENR_FDCAN2);
}

/**
 * @brief   Resets FDCAN2
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_FDCAN2(void) {

    clock_reset_APB2H(RCC_APB2HRSTR_FDCAN2);
}

/**
 * @brief   Enables FDCAN3 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_FDCAN3(bool smode) {

    clock_enable_APB2H(smode, RCC_APB2HENR_FDCAN3);
}

/**
 * @brief   Disables FDCAN3 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_FDCAN3(void) {

    clock_disable_APB2H(RCC_APB2HENR_FDCAN3);
}

/**
 * @brief   Checks if FDCAN3 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_FDCAN3(void) {

    return is_clock_enable_APB2H(RCC_APB2HENR_FDCAN3);
}

/**
 * @brief   Resets FDCAN3
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_FDCAN3(void) {

    clock_reset_APB2H(RCC_APB2HRSTR_FDCAN3);
}

/**
 * @brief   Enables FDCAN4 clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_FDCAN4(bool smode) {

    clock_enable_APB2H(smode, RCC_APB2HENR_FDCAN4);
}

/**
 * @brief   Disables FDCAN4 clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_FDCAN4(void) {

    clock_disable_APB2H(RCC_APB2HENR_FDCAN4);
}

/**
 * @brief   Checks if FDCAN4 clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_FDCAN4(void) {

    return is_clock_enable_APB2H(RCC_APB2HENR_FDCAN4);
}

/**
 * @brief   Resets FDCAN4
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_FDCAN4(void) {

    clock_reset_APB2H(RCC_APB2HRSTR_FDCAN4);
}

/**
 * @brief   Enables FDCAN MRAM clock
 *
 * @param[in] smode     sleep mode (if true, peripheral clock is enabled in
 *                      sleep mode)
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_enable_FDCAN_MRAM(bool smode) {

    clock_enable_APB2H(smode, RCC_APB2HENR_FDCAN_MRAM);
}

/**
 * @brief   Disables FDCAN MRAM clock
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_disable_FDCAN_MRAM(void) {

    clock_disable_APB2H(RCC_APB2HENR_FDCAN_MRAM);
}

/**
 * @brief   Checks if FDCAN MRAM clock is enabled
 *
 * @api
 */
__STATIC_FORCEINLINE bool is_clock_enable_FDCAN_MRAM(void) {

    return is_clock_enable_APB2H(RCC_APB2HENR_FDCAN_MRAM);
}

/**
 * @brief   Resets FDCAN MRAM
 *
 * @api
 */
__STATIC_FORCEINLINE void clock_reset_FDCAN_MRAM(void) {

    clock_reset_APB2H(RCC_APB2HRSTR_FDCAN_MRAM);
}

/*===========================================================================*/
/* Module late inclusions.                                                   */
/*===========================================================================*/

#endif /* _CLOCK_H_ */

/** @} */
