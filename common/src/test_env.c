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
 * @file    test_env.c
 * @brief   Common test environment code.
 *
 * @addtogroup PROJECTS
 * @addtogroup SDKTESTS
 * @ingroup PROJECTS
 * @addtogroup COMMON
 * @ingroup SDKTESTS
 * @{
 */

#include <test_env.h>

/*===========================================================================*/
/* Driver configuration.                                                     */
/*===========================================================================*/

/*===========================================================================*/
/* Driver forward declarations.                                              */
/*===========================================================================*/

/*===========================================================================*/
/* Driver defines.                                                           */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Initializes test environment
 *
 * @init
 * @par Description
 * @details Initializes the test environment.
 * @param   test_init   Bit-mask of modules to be initialized
 * @sa gst_start
 * @sa gst_stop
 */
void test_env_init(TestInit_t test_init)
{
#if defined(BUILD_PLATFORM_CLOCK)
    if ((test_init & TEST_INIT_CLOCK) != 0u) {
        clock_init();
    }
#endif

/* Since board initialization uses the GPIO driver, the GPIO initialization
   must be done before the board initialization.*/
#if defined(BUILD_DRIVERS_GPIO)
    if ((test_init & TEST_INIT_GPIO) != 0u) {
        gpio_init();
    }
#endif

#if defined(BUILD_PLATFORM_BOARD)
    if ((test_init & TEST_INIT_BOARD) != 0u) {
        BOARD_INIT_FUNC(BOARD_NAME);
    }
#endif

#if defined(BUILD_PLATFORM_IRQ)
    if ((test_init & TEST_INIT_IRQ) != 0u) {
        //irq_init();
    }
#endif

#if defined(BUILD_OS_OSAL)
    if ((test_init & TEST_INIT_OSAL) != 0u) {
        osal_init();
    }
#endif

#if defined(BUILD_DRIVERS_DMA)
    if ((test_init & TEST_INIT_DMA) != 0u) {
        //dma_init();
    }
#endif

#if defined(BUILD_DRIVERS_SARADC)
    if ((test_init & TEST_INIT_SARADC) != 0u) {
        //saradc_init();
    }
#endif

#if defined(BUILD_DRIVERS_SPI)
    if ((test_init & TEST_INIT_SPI) != 0u) {
        //spi_init();
    }
#endif

#if defined(BUILD_DRIVERS_UART)
    if ((test_init & TEST_INIT_UART) != 0u) {
        //uart_init();
    }
#endif
}

/** @} */
