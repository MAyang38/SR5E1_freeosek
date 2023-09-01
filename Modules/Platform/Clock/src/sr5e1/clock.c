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
 * @file    clock.c
 * @brief   SR5E1 clock subsystem source file.
 *
 * @addtogroup PLATFORM
 * @addtogroup CLOCK
 * @ingroup PLATFORM
 * @{
 */

#include <clock.h>

/*===========================================================================*/
/* Module local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Module exported variables.                                                */
/*===========================================================================*/

uint32_t SystemCoreClock = CLOCK_SYSCLKDIV;

/*===========================================================================*/
/* Module local types.                                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Module local variables.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Module local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   Initializes flash wait states
 * @note    Since flash wait states cannot be updated while reading from flash,
 *          the code for wait states updating is executed from ITCM.
 *
 * @notapi
 */
static void __attribute__((section(".itcm"))) flash_ws_init(void) {

    NVM_CTRL1->PFCR1 = CLOCK_NVMAPC_FIELD(0U)                   | 
                       CLOCK_NVMRWSC_FIELD(CLOCK_NVMRWSC_VALUE);
    NVM_CTRL2->PFCR1 = CLOCK_NVMAPC_FIELD(0U)                   | 
                       CLOCK_NVMRWSC_FIELD(CLOCK_NVMRWSC_VALUE);
}

/*===========================================================================*/
/* Module exported functions.                                                */
/*===========================================================================*/

void clock_init(void) {

    /* Resets everything, required for clean debugging sessions.*/
    clock_reset_AHB1L(0xFFFFFFFFU);
    clock_reset_AHB1H(0xFFFFFFFFU);
    clock_reset_AHB2L(0xFFFFFE00U); /* Not GPIOs.*/
    clock_reset_AHB2H(0xFFFFFFFFU);
    clock_reset_APB1L(0xFFFFFFFFU);
    clock_reset_APB2L(0xFFFFFFFFU);
    clock_reset_APB2H(0xFFFFFFFFU);

    /* Enables various clocks.*/
    (void)clock_enable_APB1L(false, RCC_APB1LENR_RTC);
    (void)clock_enable_APB2L(false, RCC_APB2LENR_SYSCFG);

    /* Wait IRCOSC is ready.*/
    while ((RCC->CR & RCC_CR_IRCOSCRDY) == 0U) {
    }

#if CLOCK_CFG_XOSC_ENABLED
#if CLOCK_CFG_XOSC_BYPASS
    /* XOSC activation with bypass.*/
    RCC->CR |= RCC_CR_XOSCON | RCC_CR_XOSCBYP;
#else
    /* XOSC activation.*/
    RCC->CR |= RCC_CR_XOSCON;
#endif
    /* Wait XOSC is ready.*/
    while ((RCC->CR & RCC_CR_XOSCRDY) == 0U) {
    }
#endif

#if CLOCK_CFG_LSI_ENABLED
    /* LSI activation if not already active.*/
    RCC->CR |= RCC_CR_LSION;
    /* Wait LSI is ready.*/
    while ((RCC->CR & RCC_CR_LSIRDY) == 0U) {
    }
#endif

#if CLOCK_ACTIVATE_PLL0
    /* PLL0 configuration and activation.*/
    RCC->PLLCFGR |= CLOCK_CFG_PLL0SRC;
    
    PLLDIG->PLL0DV = CLOCK_PLL0RFDPHI1_FIELD(CLOCK_CFG_PLL0RFDPHI1_VALUE) |
                     CLOCK_PLL0RFDPHI_FIELD(CLOCK_CFG_PLL0RFDPHI_VALUE)   |
                     CLOCK_PLL0PREDIV_FIELD(CLOCK_CFG_PLL0PREDIV_VALUE)   |
                     CLOCK_PLL0MFD_FIELD(CLOCK_CFG_PLL0MFD_VALUE);

    RCC->CR |= RCC_CR_PLL0ON;
    while ((RCC->CR & RCC_CR_PLL0LOCK) == 0U) {
    }
#endif

#if CLOCK_ACTIVATE_PLL1
    /* PLL1 configuration and activation.*/
    RCC->PLLCFGR |= CLOCK_CFG_PLL1SRC;

    PLLDIG->PLL1DV = CLOCK_PLL1RFDPHI_FIELD(CLOCK_CFG_PLL1RFDPHI_VALUE)  | 
                     CLOCK_PLL1MFD_FIELD(CLOCK_CFG_PLL1MFD_VALUE);

    RCC->CR |= RCC_CR_PLL1ON;
    while ((RCC->CR & RCC_CR_PLL1LOCK) == 0U) {
    }
#endif

    /* Clock tree settings.*/
    RCC->CFGR   = CLOCK_MCOPRE_FIELD(CLOCK_CFG_MCOPRE_VALUE) |
                  CLOCK_CFG_MCOSEL                           |
                  CLOCK_SYSPRE_FIELD(CLOCK_CFG_SYSPRE_VALUE);

    RCC->CCIPR1 = CLOCK_CFG_SDADCSEL | CLOCK_CFG_ADCSEL   |
                  CLOCK_CFG_FDCANSEL | CLOCK_CFG_SPISEL   |
                  CLOCK_CFG_I2CSEL   | CLOCK_CFG_UARTSEL;

    RCC->CCIPR2 = CLOCK_SDADCPRE_FIELD(CLOCK_CFG_SDADCPRE_VALUE) | 
                  CLOCK_ADCPRE_FIELD(CLOCK_CFG_ADCPRE_VALUE)     |
                  CLOCK_FDCANPRE_FIELD(CLOCK_CFG_FDCANPRE_VALUE) | 
                  CLOCK_SPIPRE_FIELD(CLOCK_CFG_SPIPRE_VALUE)     |
                  CLOCK_I2CPRE_FIELD(CLOCK_CFG_I2CPRE_VALUE)     | 
                  CLOCK_UARTPRE_FIELD(CLOCK_CFG_UARTPRE_VALUE);

    RCC->LSCFGR = CLOCK_CFG_RTCSEL                           |
                  CLOCK_LSIPRE_FIELD(CLOCK_CFG_LSIPRE_VALUE);

    /* Set flash wait states.*/
    flash_ws_init();    

    /* Final clock source.*/
    RCC->CFGR |= CLOCK_CFG_SW;
    while ((RCC->CFGR & RCC_CFGR_SWS) != (CLOCK_CFG_SW << 3U)) {
    }
}

/** @} */
