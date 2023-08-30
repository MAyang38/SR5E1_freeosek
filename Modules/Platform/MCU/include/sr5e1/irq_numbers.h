/****************************************************************************
*
* Copyright (c) 2019-2022 STMicroelectronics - All Rights Reserved
*
* License terms: STMicroelectronics Proprietary in accordance with licensing
* terms SLA0098 at www.st.com.
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* EVALUATION ONLY – NOT FOR USE IN PRODUCTION
*****************************************************************************/
/**
 * @file    irq_numbers.h
 * @brief   Interrupts header file.
 *
 * @addtogroup PLATFORM
 * @addtogroup MCU
 * @ingroup PLATFORM
 * @{
 */

#ifndef _IRQ_NUMBERS_H_
#define _IRQ_NUMBERS_H_

#include <sr5e1xx.h>
#include <typedefs.h>

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

/**
 * @name    Interrupt vectors and handlers
 * @{
 */
/* SYSTICK */
#define IRQ_SYSTICK_HANDLER                 SysTick_Handler

/* WWDG */
#define IRQ_WWDG_VECTOR                     WWDG_IRQn

#define IRQ_WWDG_HANDLER                    Vector40

/* EXTIs */
#define IRQ_EXTI0_VECTOR                    EXTI0_IRQn
#define IRQ_EXTI1_VECTOR                    EXTI1_IRQn
#define IRQ_EXTI2_VECTOR                    EXTI2_IRQn
#define IRQ_EXTI3_VECTOR                    EXTI3_IRQn
#define IRQ_EXTI4_VECTOR                    EXTI4_IRQn
#define IRQ_EXTI9_5_VECTOR                  EXTI9_5_IRQn
#define IRQ_EXTI15_10_VECTOR                EXTI15_10_IRQn

#define IRQ_EXTI0_HANDLER                   Vector58
#define IRQ_EXTI1_HANDLER                   Vector5C
#define IRQ_EXTI2_HANDLER                   Vector60
#define IRQ_EXTI3_HANDLER                   Vector64
#define IRQ_EXTI4_HANDLER                   Vector68
#define IRQ_EXTI9_5_HANDLER                 VectorE0
#define IRQ_EXTI15_10_HANDLER               VectorE4

/* TIMs */
#define IRQ_TIM1_BRK_VECTOR                 TIM1_BRK_IRQn
#define IRQ_TIM1_UP_VECTOR                  TIM1_UP_IRQn
#define IRQ_TIM1_TRGCO_VECTOR               TIM1_TRG_COM_IRQn
#define IRQ_TIM1_CC_VECTOR                  TIM1_CC_IRQn
#define IRQ_TIM2_VECTOR                     TIM2_IRQn
#define IRQ_TIM3_VECTOR                     TIM3_IRQn
#define IRQ_TIM4_VECTOR                     TIM4_IRQn
#define IRQ_TIM5_VECTOR                     TIM5_IRQn
#define IRQ_TIM6_VECTOR                     TIM6_IRQn
#define IRQ_TIM7_VECTOR                     TIM7_IRQn
#define IRQ_TIM8_BRK_VECTOR                 TIM8_BRK_IRQn
#define IRQ_TIM8_UP_VECTOR                  TIM8_UP_IRQn
#define IRQ_TIM8_TRGCO_VECTOR               TIM8_TRG_COM_IRQn
#define IRQ_TIM8_CC_VECTOR                  TIM8_CC_IRQn
#define IRQ_TIM15_VECTOR                    TIM15_IRQn
#define IRQ_TIM16_VECTOR                    TIM16_IRQn

#define IRQ_TIM1_BRK_HANDLER                VectorA0
#define IRQ_TIM1_UP_HANDLER                 VectorA4
#define IRQ_TIM1_TRGCO_HANDLER              VectorA8
#define IRQ_TIM1_CC_HANDLER                 VectorAC
#define IRQ_TIM2_HANDLER                    VectorB0
#define IRQ_TIM3_HANDLER                    VectorB4
#define IRQ_TIM4_HANDLER                    VectorB8
#define IRQ_TIM5_HANDLER                    VectorFC
#define IRQ_TIM6_HANDLER                    Vector100
#define IRQ_TIM7_HANDLER                    Vector104
#define IRQ_TIM8_BRK_HANDLER                VectorEC
#define IRQ_TIM8_UP_HANDLER                 VectorF0
#define IRQ_TIM8_TRGCO_HANDLER              VectorF4
#define IRQ_TIM8_CC_HANDLER                 VectorF8
#define IRQ_TIM15_HANDLER                   Vector8C
#define IRQ_TIM16_HANDLER                   Vector90

/* I2Cs */
#define IRQ_I2C1_EV_VECTOR                  I2C1_EV_IRQn
#define IRQ_I2C1_ER_VECTOR                  I2C1_ER_IRQn
#define IRQ_I2C2_EV_VECTOR                  I2C2_EV_IRQn
#define IRQ_I2C2_ER_VECTOR                  I2C2_ER_IRQn

#define IRQ_I2C1_EV_HANDLER                 VectorBC
#define IRQ_I2C1_ER_HANDLER                 VectorC0
#define IRQ_I2C2_EV_HANDLER                 VectorC4
#define IRQ_I2C2_ER_HANDLER                 VectorC8

/* SPIs */
#define IRQ_SPI1_VECTOR                     SPI1_IRQn
#define IRQ_SPI2_VECTOR                     SPI2_IRQn
#define IRQ_SPI3_VECTOR                     SPI3_IRQn
#define IRQ_SPI4_VECTOR                     SPI4_IRQn

#define IRQ_SPI1_HANDLER                    VectorCC
#define IRQ_SPI2_HANDLER                    VectorD0
#define IRQ_SPI3_HANDLER                    Vector10C
#define IRQ_SPI4_HANDLER                    Vector110

/* UARTs */
#define IRQ_UART1_VECTOR                    UART1_IRQn
#define IRQ_UART2_VECTOR                    UART2_IRQn
#define IRQ_UART3_VECTOR                    UART3_IRQn

#define IRQ_UART1_HANDLER                   VectorD4
#define IRQ_UART2_HANDLER                   VectorD8
#define IRQ_UART3_HANDLER                   VectorDC

/* DMAs */
#define IRQ_DMA1_ST0_VECTOR                 DMA1_STREAM0_IRQn
#define IRQ_DMA1_ST1_VECTOR                 DMA1_STREAM1_IRQn
#define IRQ_DMA1_ST2_VECTOR                 DMA1_STREAM2_IRQn
#define IRQ_DMA1_ST3_VECTOR                 DMA1_STREAM3_IRQn
#define IRQ_DMA1_ST4_VECTOR                 DMA1_STREAM4_IRQn
#define IRQ_DMA1_ST5_VECTOR                 DMA1_STREAM5_IRQn
#define IRQ_DMA1_ST6_VECTOR                 DMA1_STREAM6_IRQn
#define IRQ_DMA1_ST7_VECTOR                 DMA1_STREAM7_IRQn
#define IRQ_DMA2_ST0_VECTOR                 DMA2_STREAM0_IRQn
#define IRQ_DMA2_ST1_VECTOR                 DMA2_STREAM1_IRQn
#define IRQ_DMA2_ST2_VECTOR                 DMA2_STREAM2_IRQn
#define IRQ_DMA2_ST3_VECTOR                 DMA2_STREAM3_IRQn
#define IRQ_DMA2_ST4_VECTOR                 DMA2_STREAM4_IRQn
#define IRQ_DMA2_ST5_VECTOR                 DMA2_STREAM5_IRQn
#define IRQ_DMA2_ST6_VECTOR                 DMA2_STREAM6_IRQn
#define IRQ_DMA2_ST7_VECTOR                 DMA2_STREAM7_IRQn

#define IRQ_DMA1_ST0_HANDLER                Vector6C
#define IRQ_DMA1_ST1_HANDLER                Vector70
#define IRQ_DMA1_ST2_HANDLER                Vector74
#define IRQ_DMA1_ST3_HANDLER                Vector78
#define IRQ_DMA1_ST4_HANDLER                Vector7C
#define IRQ_DMA1_ST5_HANDLER                Vector80
#define IRQ_DMA1_ST6_HANDLER                Vector84
#define IRQ_DMA1_ST7_HANDLER                Vector88
#define IRQ_DMA2_ST0_HANDLER                Vector120
#define IRQ_DMA2_ST1_HANDLER                Vector124
#define IRQ_DMA2_ST2_HANDLER                Vector128
#define IRQ_DMA2_ST3_HANDLER                Vector12C
#define IRQ_DMA2_ST4_HANDLER                Vector130
#define IRQ_DMA2_ST5_HANDLER                Vector134
#define IRQ_DMA2_ST6_HANDLER                Vector138
#define IRQ_DMA2_ST7_HANDLER                Vector13C

/* HRTIMs */
#define IRQ_HRTIM1_MT_VECTOR                HRTIM1_MASTER_INT_IRQn
#define IRQ_HRTIM1_TA_VECTOR                HRTIM1_TIMA_INT_IRQn
#define IRQ_HRTIM1_TB_VECTOR                HRTIM1_TIMB_INT_IRQn
#define IRQ_HRTIM1_TC_VECTOR                HRTIM1_TIMC_INT_IRQn
#define IRQ_HRTIM1_TD_VECTOR                HRTIM1_TIMD_INT_IRQn
#define IRQ_HRTIM1_TE_VECTOR                HRTIM1_TIME_INT_IRQn
#define IRQ_HRTIM1_FLT_VECTOR               HRTIM1_TIM_FLT_INT_IRQn
#define IRQ_HRTIM1_TF_VECTOR                HRTIM1_TIMF_INT_IRQn
#define IRQ_HRTIM2_MT_VECTOR                HRTIM2_MASTER_INT_IRQn
#define IRQ_HRTIM2_TA_VECTOR                HRTIM2_TIMA_INT_IRQn
#define IRQ_HRTIM2_TB_VECTOR                HRTIM2_TIMB_INT_IRQn
#define IRQ_HRTIM2_TC_VECTOR                HRTIM2_TIMC_INT_IRQn
#define IRQ_HRTIM2_TD_VECTOR                HRTIM2_TIMD_INT_IRQn
#define IRQ_HRTIM2_TE_VECTOR                HRTIM2_TIME_INT_IRQn
#define IRQ_HRTIM2_FLT_VECTOR               HRTIM2_TIM_FLT_INT_IRQn
#define IRQ_HRTIM2_TF_VECTOR                HRTIM2_TIMF_INT_IRQn

#define IRQ_HRTIM1_MT_HANDLER               Vector14C
#define IRQ_HRTIM1_TA_HANDLER               Vector150
#define IRQ_HRTIM1_TB_HANDLER               Vector154
#define IRQ_HRTIM1_TC_HANDLER               Vector158
#define IRQ_HRTIM1_TD_HANDLER               Vector15C
#define IRQ_HRTIM1_TE_HANDLER               Vector160
#define IRQ_HRTIM1_FLT_HANDLER              Vector164
#define IRQ_HRTIM1_TF_HANDLER               Vector168
#define IRQ_HRTIM2_MT_HANDLER               Vector1E0
#define IRQ_HRTIM2_TA_HANDLER               Vector1E4
#define IRQ_HRTIM2_TB_HANDLER               Vector1E8
#define IRQ_HRTIM2_TC_HANDLER               Vector1EC
#define IRQ_HRTIM2_TD_HANDLER               Vector1F0
#define IRQ_HRTIM2_TE_HANDLER               Vector1F4
#define IRQ_HRTIM2_FLT_HANDLER              Vector1F8
#define IRQ_HRTIM2_TF_HANDLER               Vector1FC

/* FDCANs */
#define IRQ_CAN1_LINE0_VECTOR               M_CAN_1_INT0_IRQn  
#define IRQ_CAN1_LINE1_VECTOR               M_CAN_1_INT1_IRQn  
#define IRQ_CAN1_DMU_VECTOR                 MCAN_1_DMU_INT_IRQn
#define IRQ_CAN2_LINE0_VECTOR               M_CAN_2_INT0_IRQn  
#define IRQ_CAN2_LINE1_VECTOR               M_CAN_2_INT1_IRQn  
#define IRQ_CAN2_DMU_VECTOR                 MCAN_2_DMU_INT_IRQn
#define IRQ_CAN3_LINE0_VECTOR               M_CAN_3_INT0_IRQn  
#define IRQ_CAN3_LINE1_VECTOR               M_CAN_3_INT1_IRQn  
#define IRQ_CAN3_DMU_VECTOR                 MCAN_3_DMU_INT_IRQn
#define IRQ_CAN4_LINE0_VECTOR               M_CAN_4_INT0_IRQn  
#define IRQ_CAN4_LINE1_VECTOR               M_CAN_4_INT1_IRQn  
#define IRQ_CAN4_DMU_VECTOR                 MCAN_4_DMU_INT_IRQn

#define IRQ_CAN1_LINE0_HANDLER              Vector190
#define IRQ_CAN1_LINE1_HANDLER              Vector194
#define IRQ_CAN1_DMU_HANDLER                Vector198
#define IRQ_CAN2_LINE0_HANDLER              Vector19C
#define IRQ_CAN2_LINE1_HANDLER              Vector1A0
#define IRQ_CAN2_DMU_HANDLER                Vector1A4
#define IRQ_CAN3_LINE0_HANDLER              Vector1A8
#define IRQ_CAN3_LINE1_HANDLER              Vector1AC
#define IRQ_CAN3_DMU_HANDLER                Vector1B0
#define IRQ_CAN4_LINE0_HANDLER              Vector1B4
#define IRQ_CAN4_LINE1_HANDLER              Vector1B8
#define IRQ_CAN4_DMU_HANDLER                Vector1BC

/* CORDIC */
#define IRQ_CORDIC_VECTOR                   CORDIC_IRQn

#define IRQ_CORDIC_HANDLER                  Vector1C0

/* HSEM */
#define IRQ_HSEM_INT1_VECTOR                HSEM_INT1_IRQn
#define IRQ_HSEM_INT2_VECTOR                HSEM_INT2_IRQn

#define IRQ_HSEM_INT1_HANDLER               Vector1C8
#define IRQ_HSEM_INT2_HANDLER               Vector1CC

/* DACs */
#define IRQ_B_DAC1_VECTOR                   B_DAC1_IRQn
#define IRQ_DAC1_VECTOR                     DAC1_IRQn
#define IRQ_DAC2_VECTOR                     DAC2_IRQn
#define IRQ_DAC3_VECTOR                     DAC3_IRQn
#define IRQ_DAC4_VECTOR                     DAC4_IRQn

#define IRQ_B_DAC1_HANDLER                  Vector220
#define IRQ_DAC1_HANDLER                    Vector224
#define IRQ_DAC2_HANDLER                    Vector228
#define IRQ_DAC3_HANDLER                    Vector22C
#define IRQ_DAC4_HANDLER                    Vector230

/* COMPARATORs */
#define IRQ_COMP_1_2_VECTOR                 COMP_1_2_IRQn
#define IRQ_COMP_3_4_VECTOR                 COMP_3_4_IRQn
#define IRQ_COMP_5_6_VECTOR                 COMP_5_6_IRQn
#define IRQ_COMP_7_8_VECTOR                 COMP_7_8_IRQn

#define IRQ_COMP_1_2_HANDLER                Vector244
#define IRQ_COMP_3_4_HANDLER                Vector248
#define IRQ_COMP_5_6_HANDLER                Vector24C
#define IRQ_COMP_7_8_HANDLER                Vector250

/* ADCs */
#define IRQ_ADC1_VECTOR                     ADC1_IRQn
#define IRQ_ADC2_VECTOR                     ADC2_IRQn
#define IRQ_ADC3_VECTOR                     ADC3_IRQn
#define IRQ_ADC4_VECTOR                     ADC4_IRQn
#define IRQ_ADC5_VECTOR                     ADC5_IRQn

#define IRQ_ADC1_HANDLER                    Vector264
#define IRQ_ADC2_HANDLER                    Vector268
#define IRQ_ADC3_HANDLER                    Vector26C
#define IRQ_ADC4_HANDLER                    Vector270
#define IRQ_ADC5_HANDLER                    Vector274

/* SD ADCs */
#define IRQ_SD_ADC1_VECTOR                  SD_ADC1_IRQn
#define IRQ_SD_ADC2_VECTOR                  SD_ADC2_IRQn

#define IRQ_SD_ADC1_HANDLER                 Vector284
#define IRQ_SD_ADC2_HANDLER                 Vector288

/* FCCU */
#define IRQ_FCCU_VECTOR                     FCCU_INT_IRQn

#define IRQ_FCCU_HANDLER                    Vector2A8
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

#endif /* _IRQ_NUMBERS_H_ */

/** @} */
