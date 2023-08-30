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
 * @file    evbe7000p.h
 * @brief   SR5E1-EVBE7000P board header file.
 *
 * @addtogroup PLATFORM
 * @addtogroup BOARD
 * @ingroup PLATFORM
 * @addtogroup EVBE7000P
 * @ingroup BOARD
 * @{
 */

#ifndef _EVBE7000P_H_
#define _EVBE7000P_H_

#include <gpio.h>
#include <platform.h>
#include <typedefs.h>

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

#define EVBE7000P 1

/* GPIO-related settings.*/

/* PortA pin settings. */
#define TIM16_CH1 gpio_iopack(GPIO_PORT_A, GPIO_PIN_0)
#define TIM16_CH1_CFG                            \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(1U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define TIM16_CH1N gpio_iopack(GPIO_PORT_A, GPIO_PIN_1)
#define TIM16_CH1N_CFG                           \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(1U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define TIM16_BKIN gpio_iopack(GPIO_PORT_A, GPIO_PIN_2)
#define TIM16_BKIN_CFG                           \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(1U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define TIM8_ETR gpio_iopack(GPIO_PORT_A, GPIO_PIN_3)
#define TIM8_ETR_CFG                             \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(4U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define CAN1_RX gpio_iopack(GPIO_PORT_A, GPIO_PIN_4)
#define CAN1_RX_CFG                              \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_HIGH |                    \
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
     GPIO_MODE_OSPEEDR_HIGH |                    \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(6U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define I2C_SDA gpio_iopack(GPIO_PORT_A, GPIO_PIN_6)
#define I2C_SDA_CFG                              \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(6U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define I2C_SCL gpio_iopack(GPIO_PORT_A, GPIO_PIN_7)			  
#define I2C_SCL_CFG                              \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(6U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define I2C_SMBA gpio_iopack(GPIO_PORT_A, GPIO_PIN_8)
#define I2C_SMBA_CFG                             \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(6U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define CAN2_TX gpio_iopack(GPIO_PORT_A, GPIO_PIN_11)
#define CAN2_TX_CFG                              \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_HIGH |                    \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(6U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define CAN2_RX gpio_iopack(GPIO_PORT_A, GPIO_PIN_12)
#define CAN2_RX_CFG                              \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_HIGH |                    \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(6U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SDADC_1_0_IO gpio_iopack(GPIO_PORT_A, GPIO_PIN_13)
#define SDADC_1_0_IO_CFG                         \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SDADC_1_1_IO gpio_iopack(GPIO_PORT_A, GPIO_PIN_14)
#define SDADC_1_1_IO_CFG                         \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SDADC_2_0_IO gpio_iopack(GPIO_PORT_A, GPIO_PIN_15)
#define SDADC_2_0_IO_CFG                         \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

/* PortB pin settings. */
#define SDADC_2_1_IO gpio_iopack(GPIO_PORT_B, GPIO_PIN_0)
#define SDADC_2_1_IO_CFG                         \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define DAC_1_IO gpio_iopack(GPIO_PORT_B, GPIO_PIN_1)
#define DAC_1_IO_CFG                             \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SAR1_1_IO gpio_iopack(GPIO_PORT_B, GPIO_PIN_2)
#define SAR1_1_IO_CFG                            \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SAR1_2_IO gpio_iopack(GPIO_PORT_B, GPIO_PIN_3)
#define SAR1_2_IO_CFG                            \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SAR1_3_IO gpio_iopack(GPIO_PORT_B, GPIO_PIN_4)
#define SAR1_3_IO_CFG                            \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SAR1_4_IO gpio_iopack(GPIO_PORT_B, GPIO_PIN_5)
#define SAR1_4_IO_CFG                            \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SAR1_5_IO gpio_iopack(GPIO_PORT_B, GPIO_PIN_6)
#define SAR1_5_IO_CFG                            \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SAR2_1_IO gpio_iopack(GPIO_PORT_B, GPIO_PIN_7)
#define SAR2_1_IO_CFG                            \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SAR2_2_IO gpio_iopack(GPIO_PORT_B, GPIO_PIN_8)
#define SAR2_2_IO_CFG                            \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SAR2_3_IO gpio_iopack(GPIO_PORT_B, GPIO_PIN_9)
#define SAR2_3_IO_CFG                            \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SAR2_4_IO gpio_iopack(GPIO_PORT_B, GPIO_PIN_10)
#define SAR2_4_IO_CFG                            \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SAR2_5_IO gpio_iopack(GPIO_PORT_B, GPIO_PIN_11)
#define SAR2_5_IO_CFG                            \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SAR3_1_IO gpio_iopack(GPIO_PORT_B, GPIO_PIN_12)
#define SAR3_1_IO_CFG                            \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SAR3_2_IO gpio_iopack(GPIO_PORT_B, GPIO_PIN_13)
#define SAR3_2_IO_CFG                            \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SAR3_3_IO gpio_iopack(GPIO_PORT_B, GPIO_PIN_14)
#define SAR3_3_IO_CFG                            \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SAR3_4_IO gpio_iopack(GPIO_PORT_B, GPIO_PIN_15)
#define SAR3_4_IO_CFG                            \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

/* PortC pin settings. */
#define SAR3_5_IO gpio_iopack(GPIO_PORT_C, GPIO_PIN_0)
#define SAR3_5_IO_CFG                            \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SAR_CAL_1 gpio_iopack(GPIO_PORT_C, GPIO_PIN_1)
#define SAR_CAL_1_CFG                            \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SAR_CAL_2 gpio_iopack(GPIO_PORT_C, GPIO_PIN_2)
#define SAR_CAL_2_CFG                            \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SAR4_1_IO gpio_iopack(GPIO_PORT_C, GPIO_PIN_3)
#define SAR4_1_IO_CFG                            \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SAR4_2_IO gpio_iopack(GPIO_PORT_C, GPIO_PIN_4)
#define SAR4_2_IO_CFG                            \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define DAC_2_IO gpio_iopack(GPIO_PORT_C, GPIO_PIN_5)
#define DAC_2_IO_CFG                             \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SAR4_3_IO gpio_iopack(GPIO_PORT_C, GPIO_PIN_6)
#define SAR4_3_IO_CFG                            \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SAR4_4_IO gpio_iopack(GPIO_PORT_C, GPIO_PIN_7)
#define SAR4_4_IO_CFG                            \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SAR4_5_IO gpio_iopack(GPIO_PORT_C, GPIO_PIN_8)
#define SAR4_5_IO_CFG                            \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SAR5_1_IO gpio_iopack(GPIO_PORT_C, GPIO_PIN_9)
#define SAR5_1_IO_CFG                            \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SAR5_2_IO gpio_iopack(GPIO_PORT_C, GPIO_PIN_10)
#define SAR5_2_IO_CFG                            \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SAR5_3_IO gpio_iopack(GPIO_PORT_C, GPIO_PIN_11)
#define SAR5_3_IO_CFG                            \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SAR5_4_IO gpio_iopack(GPIO_PORT_C, GPIO_PIN_12)
#define SAR5_4_IO_CFG                            \
    (GPIO_MODE_MODER_ANALOG |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SAR5_5_IO gpio_iopack(GPIO_PORT_C, GPIO_PIN_13)
#define SAR5_5_IO_CFG                            \
    (GPIO_MODE_MODER_INPUT |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define TIM1_CH1N gpio_iopack(GPIO_PORT_C, GPIO_PIN_14)
#define TIM1_CH1N_CFG                            \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
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
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(4U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

/* PortD pin settings. */
#define TIM1_CH2N gpio_iopack(GPIO_PORT_D, GPIO_PIN_0)
#define TIM1_CH2N_CFG                            \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
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
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(4U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
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
     GPIO_MODE_OSPEEDR_LOW |                     \
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
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(4U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define TIM1_CH4N gpio_iopack(GPIO_PORT_D, GPIO_PIN_5)
#define TIM1_CH4N_CFG                            \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(4U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define TIM1_CH4 gpio_iopack(GPIO_PORT_D, GPIO_PIN_6)
#define TIM1_CH4_CFG                             \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(4U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define HRTIM1_CHF2 gpio_iopack(GPIO_PORT_D, GPIO_PIN_7)
#define HRTIM1_CHF2_CFG                          \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(3U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define HRTIM1_CHF1 gpio_iopack(GPIO_PORT_D, GPIO_PIN_8)
#define HRTIM1_CHF1_CFG                          \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(3U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define HRTIM1_EEV2 gpio_iopack(GPIO_PORT_D, GPIO_PIN_9)
#define HRTIM1_EEV2_CFG                          \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(3U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define HRTIM1_CHE2 gpio_iopack(GPIO_PORT_D, GPIO_PIN_10)
#define HRTIM1_CHE2_CFG                          \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(3U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define HRTIM1_CHE1 gpio_iopack(GPIO_PORT_D, GPIO_PIN_11)
#define HRTIM1_CHE1_CFG                          \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(3U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define HRTIM1_CHD2 gpio_iopack(GPIO_PORT_D, GPIO_PIN_12)
#define HRTIM1_CHD2_CFG                          \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(3U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define HRTIM1_CHD1 gpio_iopack(GPIO_PORT_D, GPIO_PIN_13)
#define HRTIM1_CHD1_CFG                          \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(3U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define HRTIM1_CHC2 gpio_iopack(GPIO_PORT_D, GPIO_PIN_14)
#define HRTIM1_CHC2_CFG                          \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(3U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define HRTIM1_CHC1 gpio_iopack(GPIO_PORT_D, GPIO_PIN_15)
#define HRTIM1_CHC1_CFG                          \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(3U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

/* PortE pin settings. */
/* GPIOE[0] is used to drive the USER_LED_1
#define HRTIM1_EEV6 gpio_iopack(GPIO_PORT_E, GPIO_PIN_0)
#define HRTIM1_EEV6_CFG                          \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(3U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)
*/
#define USER_LED_1 gpio_iopack(GPIO_PORT_E, GPIO_PIN_0)
#define USER_LED_1_CFG                           \
    (GPIO_MODE_MODER_OUTPUT |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_HIGH |                    \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define HRTIM1_CHB2 gpio_iopack(GPIO_PORT_E, GPIO_PIN_1)
#define HRTIM1_CHB2_CFG                          \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(3U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define HRTIM1_CHB1 gpio_iopack(GPIO_PORT_E, GPIO_PIN_2)
#define HRTIM1_CHB1_CFG                          \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(3U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define HRTIM1_CHA2 gpio_iopack(GPIO_PORT_E, GPIO_PIN_3)
#define HRTIM1_CHA2_CFG                          \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(3U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define HRTIM1_CHA1 gpio_iopack(GPIO_PORT_E, GPIO_PIN_4)
#define HRTIM1_CHA1_CFG                          \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(3U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SPI1_MOSI gpio_iopack(GPIO_PORT_E, GPIO_PIN_5)
#define SPI1_MOSI_CFG                            \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_HIGH |                    \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(5U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
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
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define HRTIM2_CHA1 gpio_iopack(GPIO_PORT_E, GPIO_PIN_9)
#define HRTIM2_CHA1_CFG                          \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(3U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define HRTIM2_CHA2 gpio_iopack(GPIO_PORT_E, GPIO_PIN_10)
#define HRTIM2_CHA2_CFG                          \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(3U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define HRTIM2_CHB1 gpio_iopack(GPIO_PORT_E, GPIO_PIN_11)
#define HRTIM2_CHB1_CFG                          \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(3U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define HRTIM2_CHB2 gpio_iopack(GPIO_PORT_E, GPIO_PIN_12)
#define HRTIM2_CHB2_CFG                          \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(3U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

/* GPIOE[13] is used to drive the USER_LED_0
#define HRTIM2_EEV6 gpio_iopack(GPIO_PORT_E, GPIO_PIN_13)
#define HRTIM2_EEV6_CFG                          \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(3U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)
*/
#define USER_LED_0 gpio_iopack(GPIO_PORT_E, GPIO_PIN_13)
#define USER_LED_0_CFG                           \
    (GPIO_MODE_MODER_OUTPUT |                    \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_HIGH |                    \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(0U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define HRTIM2_CHC1 gpio_iopack(GPIO_PORT_E, GPIO_PIN_14)
#define HRTIM2_CHC1_CFG                          \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(3U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define HRTIM2_CHC2 gpio_iopack(GPIO_PORT_E, GPIO_PIN_15)
#define HRTIM2_CHC2_CFG                          \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(3U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

/* PortF pin settings. */
#define HRTIM2_CHD1 gpio_iopack(GPIO_PORT_F, GPIO_PIN_0)
#define HRTIM2_CHD1_CFG                          \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(3U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define HRTIM2_CHD2 gpio_iopack(GPIO_PORT_F, GPIO_PIN_1)
#define HRTIM2_CHD2_CFG                          \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(3U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define HRTIM2_CHE1 gpio_iopack(GPIO_PORT_F, GPIO_PIN_2)
#define HRTIM2_CHE1_CFG                          \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(3U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define HRTIM2_CHE2 gpio_iopack(GPIO_PORT_F, GPIO_PIN_3)
#define HRTIM2_CHE2_CFG                          \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(3U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define HRTIM2_CHF1 gpio_iopack(GPIO_PORT_F, GPIO_PIN_4)
#define HRTIM2_CHF1_CFG                          \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(3U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define HRTIM2_CHF2 gpio_iopack(GPIO_PORT_F, GPIO_PIN_5)
#define HRTIM2_CHF2_CFG                          \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(3U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define HRTIM2_EEV2 gpio_iopack(GPIO_PORT_F, GPIO_PIN_6)
#define HRTIM2_EEV2_CFG                          \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(3U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

/* PortG pin settings. */
#define SPI4_SCK gpio_iopack(GPIO_PORT_G, GPIO_PIN_5)
#define SPI4_SCK_CFG                             \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_HIGH |                    \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(5U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SPI4_MISO gpio_iopack(GPIO_PORT_G, GPIO_PIN_6)
#define SPI4_MISO_CFG                            \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_HIGH |                    \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(5U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SPI4_MOSI gpio_iopack(GPIO_PORT_G, GPIO_PIN_7)
#define SPI4_MOSI_CFG                            \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_HIGH |                    \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(5U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SPI4_NSS gpio_iopack(GPIO_PORT_G, GPIO_PIN_8)
#define SPI4_NSS_CFG                             \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_HIGH |                    \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(5U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SPI2_MISO gpio_iopack(GPIO_PORT_G, GPIO_PIN_9)
#define SPI2_MISO_CFG                            \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_HIGH |                    \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(5U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SPI2_MOSI gpio_iopack(GPIO_PORT_G, GPIO_PIN_10)
#define SPI2_MOSI_CFG                            \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_HIGH |                    \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(5U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SPI2_SCK gpio_iopack(GPIO_PORT_G, GPIO_PIN_11)
#define SPI2_SCK_CFG                             \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_HIGH |                    \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(5U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define SPI2_NSS gpio_iopack(GPIO_PORT_G, GPIO_PIN_12)
#define SPI2_NSS_CFG                             \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_HIGH |                    \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(5U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define TIM3_ETR gpio_iopack(GPIO_PORT_G, GPIO_PIN_13)
#define TIM3_ETR_CFG                             \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(2U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

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

#define TIM2_CH4 gpio_iopack(GPIO_PORT_H, GPIO_PIN_5)
#define TIM2_CH4_CFG                             \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(1U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define TIM15_CH1 gpio_iopack(GPIO_PORT_H, GPIO_PIN_6)
#define TIM15_CH1_CFG                            \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(1U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define TIM15_CH1N gpio_iopack(GPIO_PORT_H, GPIO_PIN_7)
#define TIM15_CH1N_CFG                           \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(1U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define TIM15_CH2 gpio_iopack(GPIO_PORT_H, GPIO_PIN_8)
#define TIM15_CH2_CFG                            \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(1U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define TIM15_BKIN gpio_iopack(GPIO_PORT_H, GPIO_PIN_9)
#define TIM15_BKIN_CFG                           \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(1U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define CAN3_TX gpio_iopack(GPIO_PORT_H, GPIO_PIN_10)
#define CAN3_TX_CFG                              \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_HIGH |                    \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(6U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define CAN3_RX gpio_iopack(GPIO_PORT_H, GPIO_PIN_11)
#define CAN3_RX_CFG                              \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_HIGH |                    \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(6U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define CAN4_TX gpio_iopack(GPIO_PORT_H, GPIO_PIN_12)
#define CAN4_TX_CFG                              \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_HIGH |                    \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(6U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define CAN4_RX gpio_iopack(GPIO_PORT_H, GPIO_PIN_13)
#define CAN4_RX_CFG                              \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_HIGH |                    \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(6U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define UART3_RX gpio_iopack(GPIO_PORT_H, GPIO_PIN_14)
#define UART3_RX_CFG                             \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(7U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define UART3_TX gpio_iopack(GPIO_PORT_H, GPIO_PIN_15)
#define UART3_TX_CFG                             \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(7U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

/* PortI pin settings. */
#define TIM8_CH1 gpio_iopack(GPIO_PORT_I, GPIO_PIN_0)
#define TIM8_CH1_CFG                             \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(4U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define TIM8_CH1N gpio_iopack(GPIO_PORT_I, GPIO_PIN_1)
#define TIM8_CH1N_CFG                            \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(4U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define TIM8_CH2 gpio_iopack(GPIO_PORT_I, GPIO_PIN_2)
#define TIM8_CH2_CFG                             \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(4U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define TIM8_CH2N gpio_iopack(GPIO_PORT_I, GPIO_PIN_3)
#define TIM8_CH2N_CFG                            \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(4U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define TIM8_CH3 gpio_iopack(GPIO_PORT_I, GPIO_PIN_4)
#define TIM8_CH3_CFG                             \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(4U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define TIM8_CH3N gpio_iopack(GPIO_PORT_I, GPIO_PIN_5)
#define TIM8_CH3N_CFG                            \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(4U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define TIM8_CH4 gpio_iopack(GPIO_PORT_I, GPIO_PIN_6)
#define TIM8_CH4_CFG                             \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(4U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define TIM8_CH4N gpio_iopack(GPIO_PORT_I, GPIO_PIN_7)
#define TIM8_CH4N_CFG                            \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(4U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_DISABLED |             \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define TIM8_BKIN gpio_iopack(GPIO_PORT_I, GPIO_PIN_8)
#define TIM8_BKIN_CFG                            \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(4U) |                         \
     GPIO_MODE_IHYSTR_CMOS |                     \
     GPIO_MODE_TRIGENR_IN_ENABLED |              \
     GPIO_MODE_SAFESELR_DISABLED |               \
     GPIO_MODE_SAFEVALR_LOW)

#define TIM8_BKIN2 gpio_iopack(GPIO_PORT_I, GPIO_PIN_9)
#define TIM8_BKIN2_CFG                           \
    (GPIO_MODE_MODER_ALTERNATE |                 \
     GPIO_MODE_OTYPER_PUSHPULL |                 \
     GPIO_MODE_OSPEEDR_LOW |                     \
     GPIO_MODE_PUPDR_FLOATING |                  \
     GPIO_MODE_AFR(4U) |                         \
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

__STATIC_INLINE void evbe7000p_init(void) {

    /* PortA pin settings.*/
    gpio_set_pin_mode(TIM16_CH1, TIM16_CH1_CFG);
    gpio_set_pin_mode(TIM16_CH1N, TIM16_CH1N_CFG);
    gpio_set_pin_mode(TIM16_BKIN, TIM16_BKIN_CFG);
    gpio_set_pin_mode(TIM8_ETR, TIM8_ETR_CFG);
    gpio_set_pin_mode(CAN1_RX, CAN1_RX_CFG);
    gpio_set_pin_mode(CAN1_TX, CAN1_TX_CFG);
    gpio_set_pin_mode(I2C_SDA, I2C_SDA_CFG);
    gpio_set_pin_mode(I2C_SCL, I2C_SCL_CFG);
    gpio_set_pin_mode(I2C_SMBA, I2C_SMBA_CFG);
    gpio_set_pin_mode(CAN2_TX, CAN2_TX_CFG);
    gpio_set_pin_mode(CAN2_RX, CAN2_RX_CFG);
    gpio_set_pin_mode(SDADC_1_0_IO, SDADC_1_0_IO_CFG);
    gpio_set_pin_mode(SDADC_1_1_IO, SDADC_1_1_IO_CFG);
    gpio_set_pin_mode(SDADC_2_0_IO, SDADC_2_0_IO_CFG);

    /* PortB pin settings.*/
    gpio_set_pin_mode(SDADC_2_1_IO, SDADC_2_1_IO_CFG);
    gpio_set_pin_mode(DAC_1_IO, DAC_1_IO_CFG);
    gpio_set_pin_mode(SAR1_1_IO, SAR1_1_IO_CFG);
    gpio_set_pin_mode(SAR1_2_IO, SAR1_2_IO_CFG);
    gpio_set_pin_mode(SAR1_3_IO, SAR1_3_IO_CFG);
    gpio_set_pin_mode(SAR1_4_IO, SAR1_4_IO_CFG);
    gpio_set_pin_mode(SAR1_5_IO, SAR1_5_IO_CFG);
    gpio_set_pin_mode(SAR2_1_IO, SAR2_1_IO_CFG);
    gpio_set_pin_mode(SAR2_2_IO, SAR2_2_IO_CFG);
    gpio_set_pin_mode(SAR2_3_IO, SAR2_3_IO_CFG);
    gpio_set_pin_mode(SAR2_4_IO, SAR2_4_IO_CFG);
    gpio_set_pin_mode(SAR2_5_IO, SAR2_5_IO_CFG);
    gpio_set_pin_mode(SAR3_1_IO, SAR3_1_IO_CFG);
    gpio_set_pin_mode(SAR3_2_IO, SAR3_2_IO_CFG);
    gpio_set_pin_mode(SAR3_3_IO, SAR3_3_IO_CFG);
    gpio_set_pin_mode(SAR3_4_IO, SAR3_4_IO_CFG);

    /* PortC pin settings.*/
    gpio_set_pin_mode(SAR3_5_IO, SAR3_5_IO_CFG);
    gpio_set_pin_mode(SAR_CAL_1, SAR_CAL_1_CFG);
    gpio_set_pin_mode(SAR_CAL_2, SAR_CAL_2_CFG);
    gpio_set_pin_mode(SAR4_1_IO, SAR4_1_IO_CFG);
    gpio_set_pin_mode(SAR4_2_IO, SAR4_2_IO_CFG);
    gpio_set_pin_mode(DAC_2_IO, DAC_2_IO_CFG);
    gpio_set_pin_mode(SAR4_3_IO, SAR4_3_IO_CFG);
    gpio_set_pin_mode(SAR4_4_IO, SAR4_4_IO_CFG);
    gpio_set_pin_mode(SAR4_5_IO, SAR4_5_IO_CFG);
    gpio_set_pin_mode(SAR5_1_IO, SAR5_1_IO_CFG);
    gpio_set_pin_mode(SAR5_2_IO, SAR5_2_IO_CFG);
    gpio_set_pin_mode(SAR5_3_IO, SAR5_3_IO_CFG);
    gpio_set_pin_mode(SAR5_4_IO, SAR5_4_IO_CFG);
    gpio_set_pin_mode(SAR5_5_IO, SAR5_5_IO_CFG);
    gpio_set_pin_mode(TIM1_CH1N, TIM1_CH1N_CFG);
    gpio_set_pin_mode(TIM1_CH1, TIM1_CH1_CFG);

    /* PortD pin settings.*/
    gpio_set_pin_mode(TIM1_CH2N, TIM1_CH2N_CFG);
    gpio_set_pin_mode(TIM1_CH2, TIM1_CH2_CFG);
    gpio_set_pin_mode(TIM1_BKIN, TIM1_BKIN_CFG);
    gpio_set_pin_mode(TIM1_CH3N, TIM1_CH3N_CFG);
    gpio_set_pin_mode(TIM1_CH3, TIM1_CH3_CFG);
    gpio_set_pin_mode(TIM1_CH4N, TIM1_CH4N_CFG);
    gpio_set_pin_mode(TIM1_CH4, TIM1_CH4_CFG);
    gpio_set_pin_mode(HRTIM1_CHF2, HRTIM1_CHF2_CFG);
    gpio_set_pin_mode(HRTIM1_CHF1, HRTIM1_CHF1_CFG);
    gpio_set_pin_mode(HRTIM1_EEV2, HRTIM1_EEV2_CFG);
    gpio_set_pin_mode(HRTIM1_CHE2, HRTIM1_CHE2_CFG);
    gpio_set_pin_mode(HRTIM1_CHE1, HRTIM1_CHE1_CFG);
    gpio_set_pin_mode(HRTIM1_CHD2, HRTIM1_CHD2_CFG);
    gpio_set_pin_mode(HRTIM1_CHD1, HRTIM1_CHD1_CFG);
    gpio_set_pin_mode(HRTIM1_CHC2, HRTIM1_CHC2_CFG);
    gpio_set_pin_mode(HRTIM1_CHC1, HRTIM1_CHC1_CFG);

    /* PortE pin settings.*/
    /* GPIOE[0] is used to drive the USER_LED_1 */
    /* gpio_set_pin_mode(HRTIM1_EEV6, HRTIM1_EEV6_CFG); */
    gpio_set_pin_mode(USER_LED_1, USER_LED_1_CFG);
    gpio_set_pin_mode(HRTIM1_CHB2, HRTIM1_CHB2_CFG); 
    gpio_set_pin_mode(HRTIM1_CHB1, HRTIM1_CHB1_CFG); 
    gpio_set_pin_mode(HRTIM1_CHA2, HRTIM1_CHA2_CFG); 
    gpio_set_pin_mode(HRTIM1_CHA1, HRTIM1_CHA1_CFG); 
    gpio_set_pin_mode(SPI1_MOSI, SPI1_MOSI_CFG);
    gpio_set_pin_mode(SPI1_MISO, SPI1_MISO_CFG);
    gpio_set_pin_mode(SPI1_SCK, SPI1_SCK_CFG);
    gpio_set_pin_mode(SPI1_NSS, SPI1_NSS_CFG);
    gpio_set_pin_mode(HRTIM2_CHA1, HRTIM2_CHA1_CFG);
    gpio_set_pin_mode(HRTIM2_CHA2, HRTIM2_CHA2_CFG);
    gpio_set_pin_mode(HRTIM2_CHB1, HRTIM2_CHB1_CFG);
    gpio_set_pin_mode(HRTIM2_CHB2, HRTIM2_CHB2_CFG);
    /* GPIOE[13] is used to drive the USER_LED_0 */
    /* gpio_set_pin_mode(HRTIM2_EEV6, HRTIM2_EEV6_CFG); */
    gpio_set_pin_mode(USER_LED_0, USER_LED_0_CFG);
    gpio_set_pin_mode(HRTIM2_CHC1, HRTIM2_CHC1_CFG);
    gpio_set_pin_mode(HRTIM2_CHC2, HRTIM2_CHC2_CFG);

    /* PortF pin settings.*/
    gpio_set_pin_mode(HRTIM2_CHD1, HRTIM2_CHD1_CFG);
    gpio_set_pin_mode(HRTIM2_CHD2, HRTIM2_CHD2_CFG);
    gpio_set_pin_mode(HRTIM2_CHE1, HRTIM2_CHE1_CFG);
    gpio_set_pin_mode(HRTIM2_CHE2, HRTIM2_CHE2_CFG);
    gpio_set_pin_mode(HRTIM2_CHF1, HRTIM2_CHF1_CFG);
    gpio_set_pin_mode(HRTIM2_CHF2, HRTIM2_CHF2_CFG);
    gpio_set_pin_mode(HRTIM2_EEV2, HRTIM2_EEV2_CFG);

    /* PortG pin settings.*/
    gpio_set_pin_mode(SPI4_SCK, SPI4_SCK_CFG);
    gpio_set_pin_mode(SPI4_MISO, SPI4_MISO_CFG);
    gpio_set_pin_mode(SPI4_MOSI, SPI4_MOSI_CFG);
    gpio_set_pin_mode(SPI4_NSS, SPI4_NSS_CFG);
    gpio_set_pin_mode(SPI2_MISO, SPI2_MISO_CFG);
    gpio_set_pin_mode(SPI2_MOSI, SPI2_MOSI_CFG);
    gpio_set_pin_mode(SPI2_SCK, SPI2_SCK_CFG);
    gpio_set_pin_mode(SPI2_NSS, SPI2_NSS_CFG);
    gpio_set_pin_mode(TIM3_ETR, TIM3_ETR_CFG);
    gpio_set_pin_mode(TIM3_CH1, TIM3_CH1_CFG);
    gpio_set_pin_mode(TIM3_CH2, TIM3_CH2_CFG);

    /* PortH pin settings. */
    gpio_set_pin_mode(TIM3_CH3, TIM3_CH3_CFG);
    gpio_set_pin_mode(TIM3_CH4, TIM3_CH4_CFG);
    gpio_set_pin_mode(TIM2_CH1, TIM2_CH1_CFG);
    gpio_set_pin_mode(TIM2_CH2, TIM2_CH2_CFG);
    gpio_set_pin_mode(TIM2_CH3, TIM2_CH3_CFG);
    gpio_set_pin_mode(TIM2_CH4, TIM2_CH4_CFG);
    gpio_set_pin_mode(TIM15_CH1, TIM15_CH1_CFG);
    gpio_set_pin_mode(TIM15_CH1N, TIM15_CH1N_CFG);
    gpio_set_pin_mode(TIM15_CH2, TIM15_CH2_CFG);
    gpio_set_pin_mode(TIM15_BKIN, TIM15_BKIN_CFG);
    gpio_set_pin_mode(CAN3_TX, CAN3_TX_CFG);
    gpio_set_pin_mode(CAN3_RX, CAN3_RX_CFG);
    gpio_set_pin_mode(CAN4_TX, CAN4_TX_CFG);
    gpio_set_pin_mode(CAN4_RX, CAN4_RX_CFG);
    gpio_set_pin_mode(UART3_RX, UART3_RX_CFG);
    gpio_set_pin_mode(UART3_TX, UART3_TX_CFG);

    /* PortI pin settings.*/
    gpio_set_pin_mode(TIM8_CH1, TIM8_CH1_CFG);
    gpio_set_pin_mode(TIM8_CH1N, TIM8_CH1N_CFG);
    gpio_set_pin_mode(TIM8_CH2, TIM8_CH2_CFG);
    gpio_set_pin_mode(TIM8_CH2N, TIM8_CH2N_CFG);
    gpio_set_pin_mode(TIM8_CH3, TIM8_CH3_CFG);
    gpio_set_pin_mode(TIM8_CH3N, TIM8_CH3N_CFG);
    gpio_set_pin_mode(TIM8_CH4, TIM8_CH4_CFG);
    gpio_set_pin_mode(TIM8_CH4N, TIM8_CH4N_CFG);
    gpio_set_pin_mode(TIM8_BKIN, TIM8_BKIN_CFG);
    gpio_set_pin_mode(TIM8_BKIN2, TIM8_BKIN2_CFG);
}

/*===========================================================================*/
/* Module late inclusions.                                                   */
/*===========================================================================*/

#endif /* _EVBE7000P_H_ */

/** @} */
