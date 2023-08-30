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
 * @file    evbe7000s.h
 * @brief   SR5E1-EVBE7000S board header file.
 *
 * @addtogroup PLATFORM
 * @addtogroup BOARD
 * @ingroup PLATFORM
 * @addtogroup EVBE7000S
 * @ingroup BOARD
 * @{
 */

#ifndef _EVBE7000S_H_
#define _EVBE7000S_H_

#include <gpio.h>
#include <platform.h>
#include <typedefs.h>

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

#define EVBE7000S 1

/* GPIO-related settings.*/

/* PortA pin settings. */
#define CAN1_RX gpio_iopack(GPIO_PORT_A, GPIO_PIN_4)
#define CAN1_RX_CFG                              \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(6U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define CAN1_TX gpio_iopack(GPIO_PORT_A, GPIO_PIN_5)
#define CAN1_TX_CFG                              \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(6U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SDADC1_IN0 gpio_iopack(GPIO_PORT_A, GPIO_PIN_13)
#define SDADC1_IN0_CFG                           \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SDADC1_IN1 gpio_iopack(GPIO_PORT_A, GPIO_PIN_14)
#define SDADC1_IN1_CFG                           \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

/* PortB pin settings. */
#define B_DAC1_OUT gpio_iopack(GPIO_PORT_B, GPIO_PIN_1)
#define B_DAC1_OUT_CFG                           \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SAR1_IN1 gpio_iopack(GPIO_PORT_B, GPIO_PIN_2)
#define SAR1_IN1_CFG                             \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SAR2_IN1 gpio_iopack(GPIO_PORT_B, GPIO_PIN_7)
#define SAR2_IN1_CFG                             \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SAR3_IN1 gpio_iopack(GPIO_PORT_B, GPIO_PIN_12)
#define SAR3_IN1_CFG                             \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

/* PortC pin settings. */
#define SAR_CAL1 gpio_iopack(GPIO_PORT_C, GPIO_PIN_1)
#define SAR_CAL1_CFG                             \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SAR4_IN1 gpio_iopack(GPIO_PORT_C, GPIO_PIN_3)
#define SAR4_IN1_CFG                             \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define B_DAC2_OUT gpio_iopack(GPIO_PORT_C, GPIO_PIN_5)
#define B_DAC2_OUT_CFG                           \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SAR5_IN1 gpio_iopack(GPIO_PORT_C, GPIO_PIN_9)
#define SAR5_IN1_CFG                             \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SAR5_IN2 gpio_iopack(GPIO_PORT_C, GPIO_PIN_10)
#define SAR5_IN2_CFG                             \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SAR5_IN3 gpio_iopack(GPIO_PORT_C, GPIO_PIN_11)
#define SAR5_IN3_CFG                             \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define TIM1_CH1N gpio_iopack(GPIO_PORT_C, GPIO_PIN_14)
#define TIM1_CH1N_CFG                            \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_HIGH |                    \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(4U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define TIM1_CH1 gpio_iopack(GPIO_PORT_C, GPIO_PIN_15)
#define TIM1_CH1_CFG                             \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_HIGH |                    \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(4U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

/* PortD pin settings. */
#define TIM1_CH2N gpio_iopack(GPIO_PORT_D, GPIO_PIN_0)
#define TIM1_CH2N_CFG                            \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_HIGH |                    \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(4U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define TIM1_CH2 gpio_iopack(GPIO_PORT_D, GPIO_PIN_1)
#define TIM1_CH2_CFG                             \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_HIGH |                    \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(4U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define TIM1_BKIN gpio_iopack(GPIO_PORT_D, GPIO_PIN_2)
#define TIM1_BKIN_CFG                            \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(4U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define TIM1_CH3N gpio_iopack(GPIO_PORT_D, GPIO_PIN_3)
#define TIM1_CH3N_CFG                            \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_HIGH |                    \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(4U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define TIM1_CH3 gpio_iopack(GPIO_PORT_D, GPIO_PIN_4)
#define TIM1_CH3_CFG                             \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_HIGH |                    \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(4U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

/* PortE pin settings. */
#define SPI1_MOSI gpio_iopack(GPIO_PORT_E, GPIO_PIN_5)
#define SPI1_MOSI_CFG                            \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_HIGH |                    \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(5U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SPI1_MISO gpio_iopack(GPIO_PORT_E, GPIO_PIN_6)
#define SPI1_MISO_CFG                            \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_HIGH |                    \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(5U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SPI1_SCK gpio_iopack(GPIO_PORT_E, GPIO_PIN_7)
#define SPI1_SCK_CFG                             \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_HIGH |                    \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(5U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SPI1_NSS gpio_iopack(GPIO_PORT_E, GPIO_PIN_8)
#define SPI1_NSS_CFG                             \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_HIGH |                    \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(5U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

/* PortG pin settings. */
#define TIM3_CH1 gpio_iopack(GPIO_PORT_G, GPIO_PIN_14)
#define TIM3_CH1_CFG                             \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(2U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define TIM3_CH2 gpio_iopack(GPIO_PORT_G, GPIO_PIN_15)
#define TIM3_CH2_CFG                             \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(2U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

/* PortH pin settings. */
#define TIM3_CH3 gpio_iopack(GPIO_PORT_H, GPIO_PIN_0)
#define TIM3_CH3_CFG                             \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(2U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define TIM3_CH4 gpio_iopack(GPIO_PORT_H, GPIO_PIN_1)
#define TIM3_CH4_CFG                             \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(2U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define TIM2_CH1 gpio_iopack(GPIO_PORT_H, GPIO_PIN_2)
#define TIM2_CH1_CFG                             \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(1U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define TIM2_CH2 gpio_iopack(GPIO_PORT_H, GPIO_PIN_3)
#define TIM2_CH2_CFG                             \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(1U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define TIM2_CH3 gpio_iopack(GPIO_PORT_H, GPIO_PIN_4)
#define TIM2_CH3_CFG                             \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(1U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define USER_LED_1 gpio_iopack(GPIO_PORT_H, GPIO_PIN_11)
#define USER_LED_1_CFG                           \
    (GPIO_MODE_MODER_OUTPUT |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define USER_LED_2 gpio_iopack(GPIO_PORT_H, GPIO_PIN_12)
#define USER_LED_2_CFG                           \
    (GPIO_MODE_MODER_OUTPUT |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

/* UART3_RX is configured as TX as workaround for an hw issue on EVBE7000S */
#define UART3_RX gpio_iopack(GPIO_PORT_H, GPIO_PIN_14)
#define UART3_RX_CFG                             \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(7U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

/* UART3_TX is configured as RX as workaround for an hw issue on EVBE7000S */
#define UART3_TX gpio_iopack(GPIO_PORT_H, GPIO_PIN_15)
#define UART3_TX_CFG                             \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(7U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

/* PortI pin settings. */
#define L9907_EN1 gpio_iopack(GPIO_PORT_I, GPIO_PIN_0)
#define L9907_EN1_CFG                            \
    (GPIO_MODE_MODER_OUTPUT |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define L9907_EN2 gpio_iopack(GPIO_PORT_I, GPIO_PIN_1)
#define L9907_EN2_CFG                            \
    (GPIO_MODE_MODER_OUTPUT |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define L9907_FS_FLAG gpio_iopack(GPIO_PORT_I, GPIO_PIN_2)
#define L9907_FS_FLAG_CFG                        \
    (GPIO_MODE_MODER_OUTPUT |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define L9907_EN2_BUT gpio_iopack(GPIO_PORT_I, GPIO_PIN_6)
#define L9907_EN2_BUT_CFG                        \
    (GPIO_MODE_MODER_OUTPUT |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

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

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

__STATIC_INLINE void evbe7000s_init(void) {

    /* PortA pin settings.*/
    gpio_set_pin_mode(CAN1_RX, CAN1_RX_CFG);
    gpio_set_pin_mode(CAN1_TX, CAN1_TX_CFG);
    gpio_set_pin_mode(SDADC1_IN0, SDADC1_IN0_CFG);
    gpio_set_pin_mode(SDADC1_IN1, SDADC1_IN1_CFG);

    /* PortB pin settings. */
    gpio_set_pin_mode(B_DAC1_OUT, B_DAC1_OUT_CFG);
    gpio_set_pin_mode(SAR1_IN1, SAR1_IN1_CFG);
    gpio_set_pin_mode(SAR2_IN1, SAR2_IN1_CFG);
    gpio_set_pin_mode(SAR3_IN1, SAR3_IN1_CFG);

    /* PortC pin settings. */
    gpio_set_pin_mode(SAR_CAL1, SAR_CAL1_CFG);
    gpio_set_pin_mode(SAR4_IN1, SAR4_IN1_CFG);
    gpio_set_pin_mode(B_DAC2_OUT, B_DAC2_OUT_CFG);
    gpio_set_pin_mode(SAR5_IN1, SAR5_IN1_CFG);
    gpio_set_pin_mode(SAR5_IN2, SAR5_IN2_CFG);
    gpio_set_pin_mode(SAR5_IN3, SAR5_IN3_CFG);
    gpio_set_pin_mode(TIM1_CH1N, TIM1_CH1N_CFG);
    gpio_set_pin_mode(TIM1_CH1, TIM1_CH1_CFG);

    /* PortD pin settings. */
    gpio_set_pin_mode(TIM1_CH2N, TIM1_CH2N_CFG);
    gpio_set_pin_mode(TIM1_CH2, TIM1_CH2_CFG);
    gpio_set_pin_mode(TIM1_BKIN, TIM1_BKIN_CFG);
    gpio_set_pin_mode(TIM1_CH3N, TIM1_CH3N_CFG);
    gpio_set_pin_mode(TIM1_CH3, TIM1_CH3_CFG);

    /* PortE pin settings. */
    gpio_set_pin_mode(SPI1_MOSI, SPI1_MOSI_CFG);
    gpio_set_pin_mode(SPI1_MISO, SPI1_MISO_CFG);
    gpio_set_pin_mode(SPI1_SCK, SPI1_SCK_CFG);
    gpio_set_pin_mode(SPI1_NSS, SPI1_NSS_CFG);

    /* PortG pin settings. */
    gpio_set_pin_mode(TIM3_CH1, TIM3_CH1_CFG);
    gpio_set_pin_mode(TIM3_CH2, TIM3_CH2_CFG);

    /* PortH pin settings. */
    gpio_set_pin_mode(TIM3_CH3, TIM3_CH3_CFG);
    gpio_set_pin_mode(TIM3_CH4, TIM3_CH4_CFG);
    gpio_set_pin_mode(TIM2_CH1, TIM2_CH1_CFG);
    gpio_set_pin_mode(TIM2_CH2, TIM2_CH2_CFG);
    gpio_set_pin_mode(TIM2_CH3, TIM2_CH3_CFG);
    gpio_set_pin_mode(USER_LED_1, USER_LED_1_CFG);
    gpio_set_pin_mode(USER_LED_2, USER_LED_2_CFG);
    gpio_set_pin_mode(UART3_RX, UART3_RX_CFG);
    gpio_set_pin_mode(UART3_TX, UART3_TX_CFG);

    /* PortI pin settings. */
    gpio_set_pin_mode(L9907_EN1, L9907_EN1_CFG);
    gpio_set_pin_mode(L9907_EN2, L9907_EN2_CFG);
    gpio_set_pin_mode(L9907_FS_FLAG, L9907_FS_FLAG_CFG);
    gpio_set_pin_mode(L9907_EN2_BUT, L9907_EN2_BUT_CFG);
}

/*===========================================================================*/
/* Module late inclusions.                                                   */
/*===========================================================================*/

#endif /* _EVBE7000S_H_ */

/** @} */
