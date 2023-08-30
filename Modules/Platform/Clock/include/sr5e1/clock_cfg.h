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
 * @file    clock_cfg.h
 * @brief   SR5E1 clock subsystem configuration file.
 *
 * @addtogroup PLATFORM
 * @addtogroup CLOCK
 * @ingroup PLATFORM
 * @{
 */

#ifndef _CLOCKCONF_H_
#define _CLOCKCONF_H_

/**
 * @brief   Platform identifier
 */
#define SR5E1xxx_CLOCKCONF

/**
 * @name    Symmetric MultiProcessing mode settings
 * @{
 */
#define CLOCK_CFG_SMP_MODE                  TRUE
/** @} */

/**
 * @name    Oscillator switches settings
 * @{
 */
#define CLOCK_CFG_XOSC_ENABLED              TRUE
#define CLOCK_CFG_LSI_ENABLED               FALSE
/** @} */

/**
 * @name    External Oscillator settings
 * @{
 */
#define CLOCK_CFG_XOSCCLK                   40000000UL
#define CLOCK_CFG_XOSC_BYPASS               FALSE
/** @} */

/**
 * @name    PLL settings
 * @{
 */
#define CLOCK_CFG_PLL0SRC                   CLOCK_PLL0SRC_XOSC
#define CLOCK_CFG_PLL0MFD_VALUE             24U
#define CLOCK_CFG_PLL0PREDIV_VALUE          2U
#define CLOCK_CFG_PLL0RFDPHI_VALUE          8U
#define CLOCK_CFG_PLL0RFDPHI1_VALUE         8U
#define CLOCK_CFG_PLL1SRC                   CLOCK_PLL1SRC_PLL0PHI1
#define CLOCK_CFG_PLL1MFD_VALUE             20U
#define CLOCK_CFG_PLL1RFDPHI_VALUE          2U
/** @} */

/**
 * @name    System Clock settings
 * @{
 */
#define CLOCK_CFG_SW                        CLOCK_SW_PLL1PHI
#define CLOCK_CFG_SYSPRE_VALUE              0U
/** @} */

/**
 * @name    Peripheral Clock settings
 * @{
 */
#define CLOCK_CFG_UARTSEL                   CLOCK_UARTSEL_XOSC
#define CLOCK_CFG_I2CSEL                    CLOCK_I2CSEL_XOSC
#define CLOCK_CFG_SPISEL                    CLOCK_SPISEL_XOSC
#define CLOCK_CFG_FDCANSEL                  CLOCK_FDCANSEL_XOSC
#define CLOCK_CFG_ADCSEL                    CLOCK_ADCSEL_XOSC
#define CLOCK_CFG_SDADCSEL                  CLOCK_SDADCSEL_XOSC
#define CLOCK_CFG_MCOSEL                    CLOCK_MCOSEL_NOCLOCK
#define CLOCK_CFG_RTCSEL                    CLOCK_RTCSEL_XOSC
#define CLOCK_CFG_UARTPRE_VALUE             0U
#define CLOCK_CFG_I2CPRE_VALUE              0U
#define CLOCK_CFG_SPIPRE_VALUE              0U
#define CLOCK_CFG_FDCANPRE_VALUE            0U
#define CLOCK_CFG_ADCPRE_VALUE              0U
#define CLOCK_CFG_SDADCPRE_VALUE            4U
#define CLOCK_CFG_MCOPRE_VALUE              0U
#define CLOCK_CFG_LSIPRE_VALUE              0U

#define CLOCK_CFG_I2S_CKIN                  0UL
/** @} */

#endif /* _CLOCKCONF_H_ */

/** @} */
