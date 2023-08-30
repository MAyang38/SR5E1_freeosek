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
 * @file    dmamux.h
 * @brief   DMAMUX header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup SYSTEM
 * @ingroup DRIVERS
 * @addtogroup DMA
 * @ingroup SYSTEM
 * @{
 */

#ifndef _DMAMUX_H_
#define _DMAMUX_H_

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

/**
 * @name    DMAMUX1 request sources
 * @{
 */
#define DMAMUX1_REQ_GEN0                1
#define DMAMUX1_REQ_GEN1                2
#define DMAMUX1_REQ_GEN2                3
#define DMAMUX1_REQ_GEN3                4
#define DMAMUX1_ADC1                    5
#define DMAMUX1_BDAC1_CH1               6
#define DMAMUX1_BDAC1_CH2               7
#define DMAMUX1_TIM6_UP                 8
#define DMAMUX1_TIM7_UP                 9
#define DMAMUX1_SPI1_RX                 10
#define DMAMUX1_SPI1_TX                 11
#define DMAMUX1_SPI2_RX                 12
#define DMAMUX1_SPI2_TX                 13
#define DMAMUX1_SPI3_RX                 14
#define DMAMUX1_SPI3_TX                 15
#define DMAMUX1_I2C1_RX                 16
#define DMAMUX1_I2C1_TX                 17
#define DMAMUX1_I2C2_RX                 18
#define DMAMUX1_I2C2_TX                 19

#define DMAMUX1_UART1_RX                24
#define DMAMUX1_UART1_TX                25
#define DMAMUX1_UART2_RX                26
#define DMAMUX1_UART2_TX                27
#define DMAMUX1_UART3_RX                28
#define DMAMUX1_UART3_TX                29

#define DMAMUX1_ADC2                    36
#define DMAMUX1_ADC3                    37
#define DMAMUX1_ADC4                    38
#define DMAMUX1_ADC5                    39

#define DMAMUX1_TIM1_CH1                42
#define DMAMUX1_TIM1_CH2                43
#define DMAMUX1_TIM1_CH3                44
#define DMAMUX1_TIM1_CH4                45
#define DMAMUX1_TIM1_UP                 46
#define DMAMUX1_TIM1_TRIG               47
#define DMAMUX1_TIM1_COM                48
#define DMAMUX1_TIM8_CH1                49
#define DMAMUX1_TIM8_CH2                50
#define DMAMUX1_TIM8_CH3                51
#define DMAMUX1_TIM8_CH4                52
#define DMAMUX1_TIM8_UP                 53
#define DMAMUX1_TIM8_TRIG               54
#define DMAMUX1_TIM8_COM                55
#define DMAMUX1_TIM2_CH1                56
#define DMAMUX1_TIM2_CH2                57
#define DMAMUX1_TIM2_CH3                58
#define DMAMUX1_TIM2_CH4                59
#define DMAMUX1_TIM2_UP                 60
#define DMAMUX1_TIM3_CH1                61
#define DMAMUX1_TIM3_CH2                62
#define DMAMUX1_TIM3_CH3                63
#define DMAMUX1_TIM3_CH4                64
#define DMAMUX1_TIM3_UP                 65
#define DMAMUX1_TIM3_TRIG               66
#define DMAMUX1_TIM4_CH1                67
#define DMAMUX1_TIM4_CH2                68
#define DMAMUX1_TIM4_CH3                69
#define DMAMUX1_TIM4_CH4                70
#define DMAMUX1_TIM4_UP                 71
#define DMAMUX1_TIM5_CH1                72
#define DMAMUX1_TIM5_CH2                73
#define DMAMUX1_TIM5_CH3                74
#define DMAMUX1_TIM5_CH4                75
#define DMAMUX1_TIM5_UP                 76
#define DMAMUX1_TIM5_TRIG               77
#define DMAMUX1_TIM15_CH1               78
#define DMAMUX1_TIM15_UP                79
#define DMAMUX1_TIM15_TRIG              80
#define DMAMUX1_TIM15_COM               81
#define DMAMUX1_TIM16_CH1               82
#define DMAMUX1_TIM16_UP                83
#define DMAMUX1_TIM_TS_UP               84

#define DMAMUX1_DAC1_CH1                91
#define DMAMUX1_DAC1_CH2                92
#define DMAMUX1_DAC2_CH1                93
#define DMAMUX1_DAC2_CH2                94
#define DMAMUX1_HRTIM1_MASTER           95
#define DMAMUX1_HRTIM1_TIMA             96
#define DMAMUX1_HRTIM1_TIMB             97
#define DMAMUX1_HRTIM1_TIMC             98
#define DMAMUX1_HRTIM1_TIMD             99
#define DMAMUX1_HRTIM1_TIME             100
#define DMAMUX1_HRTIM1_TIMF             101
#define DMAMUX1_DAC3_CH1                102
#define DMAMUX1_DAC3_CH2                103
#define DMAMUX1_DAC4_CH1                104
#define DMAMUX1_DAC4_CH2                105
#define DMAMUX1_SPI4_RX                 106
#define DMAMUX1_SPI4_TX                 107

#define DMAMUX1_CORDIC_READ             112
#define DMAMUX1_CORDIC_WRITE            113

#define DMAMUX1_HRTIM2_MASTER           116
#define DMAMUX1_HRTIM2_TIMA             117
#define DMAMUX1_HRTIM2_TIMB             118
#define DMAMUX1_HRTIM2_TIMC             119
#define DMAMUX1_HRTIM2_TIMD             120
#define DMAMUX1_HRTIM2_TIME             121
#define DMAMUX1_HRTIM2_TIMF             122

#define DMAMUX1_CAN_SUB_1_DMU_1_TX      130
#define DMAMUX1_CAN_SUB_1_DMU_1_TXE     131
#define DMAMUX1_CAN_SUB_1_DMU_1_RX0     132
#define DMAMUX1_CAN_SUB_1_DMU_1_RX1     133
#define DMAMUX1_CAN_SUB_1_DMU_2_TX      134
#define DMAMUX1_CAN_SUB_1_DMU_2_TXE     135
#define DMAMUX1_CAN_SUB_1_DMU_2_RX0     136
#define DMAMUX1_CAN_SUB_1_DMU_2_RX1     137
#define DMAMUX1_CAN_SUB_1_DMU_3_TX      138
#define DMAMUX1_CAN_SUB_1_DMU_3_TXE     139
#define DMAMUX1_CAN_SUB_1_DMU_3_RX0     140
#define DMAMUX1_CAN_SUB_1_DMU_3_RX1     141
#define DMAMUX1_CAN_SUB_1_DMU_4_TX      142
#define DMAMUX1_CAN_SUB_1_DMU_4_TXE     143
#define DMAMUX1_CAN_SUB_1_DMU_4_RX0     144
#define DMAMUX1_CAN_SUB_1_DMU_4_RX1     145
#define DMAMUX1_CAN_SUB_M_CAN_1         146
#define DMAMUX1_CAN_SUB_M_CAN_2         147

#define DMAMUX1_SD_ADC1                 150
#define DMAMUX1_SD_ADC2                 151
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

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/*===========================================================================*/
/* Module late inclusions.                                                   */
/*===========================================================================*/

#endif /* _DMAMUX_H_ */

/** @} */
