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

/*******************************************************************************
 * REVISION HISTORY                                                            *
 * REV       DATE       RM REV          DESCRIPTION OF CHANGE                  *
 * ------ ----------- ------------ --------------------------------------------*
 * 1.0C i 16-Mar-2022 Rev 1 Draft C     SR5E1_RDP_1_C_Rev1_C_16MAR22           *
 *                                      Initial review                         *
 ******************************************************************************/

#ifndef __SR5E1_CM7_H
#define __SR5E1_CM7_H

#define __CM7_REV               0x0100U  
#define __MPU_PRESENT           1
// #define __NVIC_PRIO_BITS        4     
#define __Vendor_SysTickConfig  0      
#define __FPU_PRESENT           1
#define __ICACHE_PRESENT        1
#define __DCACHE_PRESENT        1

// typedef enum {
//   NonMaskableInt_IRQn         = -14,
//   HardFault_IRQn              = -13,
//   MemoryManagement_IRQn       = -12,
//   BusFault_IRQn               = -11,
//   UsageFault_IRQn             = -10,
//   SVCall_IRQn                 = -5,
//   DebugMonitor_IRQn           = -4,
//   PendSV_IRQn                 = -2,
//   SysTick_IRQn                = -1,
// /********* SR5E1 specific interrupt handler *************/
//   WWDG_IRQn                    = 0,
//   RTC_ALARM_IRQn               = 1,
//   RTC_WKPU_IRQn                = 3,
//   FLASH_IRQn                   = 4,
//   RCC_IRQn                     = 5,
//   EXTI0_IRQn                   = 6,
//   EXTI1_IRQn                   = 7,
//   EXTI2_IRQn                   = 8,
//   EXTI3_IRQn                   = 9,
//   EXTI4_IRQn                   = 10,
//   DMA1_STREAM0_IRQn            = 11,
//   DMA1_STREAM1_IRQn            = 12,
//   DMA1_STREAM2_IRQn            = 13,
//   DMA1_STREAM3_IRQn            = 14,
//   DMA1_STREAM4_IRQn            = 15,
//   DMA1_STREAM5_IRQn            = 16,
//   DMA1_STREAM6_IRQn            = 17,
//   DMA1_STREAM7_IRQn            = 18,
//   TIM15_IRQn                   = 19,
//   TIM16_IRQn                   = 20,
//   TIM1_BRK_IRQn                = 24,
//   TIM1_UP_IRQn                 = 25,
//   TIM1_TRG_COM_IRQn            = 26,
//   TIM1_CC_IRQn                 = 27,
//   TIM2_IRQn                    = 28,
//   TIM3_IRQn                    = 29,
//   TIM4_IRQn                    = 30,
//   I2C1_EV_IRQn                 = 31,
//   I2C1_ER_IRQn                 = 32,
//   I2C2_EV_IRQn                 = 33,
//   I2C2_ER_IRQn                 = 34,
//   SPI1_IRQn                    = 35,
//   SPI2_IRQn                    = 36,
//   UART1_IRQn                   = 37,
//   UART2_IRQn                   = 38,
//   UART3_IRQn                   = 39,
//   EXTI9_5_IRQn                 = 40,
//   EXTI15_10_IRQn               = 41,
//   TIM8_BRK_IRQn                = 43,
//   TIM8_UP_IRQn                 = 44,
//   TIM8_TRG_COM_IRQn            = 45,
//   TIM8_CC_IRQn                 = 46,
//   TIM5_IRQn                    = 47,
//   TIM6_IRQn                    = 48,
//   TIM7_IRQn                    = 49,
//   TIM_TS_IRQn                  = 50,
//   SPI3_IRQn                    = 51,
//   SPI4_IRQn                    = 52,
//   DMA2_STREAM0_IRQn            = 56,
//   DMA2_STREAM1_IRQn            = 57,
//   DMA2_STREAM2_IRQn            = 58,
//   DMA2_STREAM3_IRQn            = 59,
//   DMA2_STREAM4_IRQn            = 60,
//   DMA2_STREAM5_IRQn            = 61,
//   DMA2_STREAM6_IRQn            = 62,
//   DMA2_STREAM7_IRQn            = 63,
//   DMAMUX1_OVR_IRQn             = 64,
//   HRTIM1_MASTER_INT_IRQn       = 67,
//   HRTIM1_TIMA_INT_IRQn         = 68,
//   HRTIM1_TIMB_INT_IRQn         = 69,
//   HRTIM1_TIMC_INT_IRQn         = 70,
//   HRTIM1_TIMD_INT_IRQn         = 71,
//   HRTIM1_TIME_INT_IRQn         = 72,
//   HRTIM1_TIM_FLT_INT_IRQn      = 73,
//   HRTIM1_TIMF_INT_IRQn         = 74,
//   FPU_IRQn                     = 81,
//   M_CAN_1_INT0_IRQn            = 84,
//   M_CAN_1_INT1_IRQn            = 85,
//   MCAN_1_DMU_INT_IRQn          = 86,
//   M_CAN_2_INT0_IRQn            = 87,
//   M_CAN_2_INT1_IRQn            = 88,
//   MCAN_2_DMU_INT_IRQn          = 89,
//   M_CAN_3_INT0_IRQn            = 90,
//   M_CAN_3_INT1_IRQn            = 91,
//   MCAN_3_DMU_INT_IRQn          = 92,
//   M_CAN_4_INT0_IRQn            = 93,
//   M_CAN_4_INT1_IRQn            = 94,
//   MCAN_4_DMU_INT_IRQn          = 95,
//   CORDIC_IRQn                  = 96,
//   HSEM_INT1_IRQn               = 98,
//   HSEM_INT2_IRQn               = 99,
//   HRTIM2_MASTER_INT_IRQn       = 104,
//   HRTIM2_TIMA_INT_IRQn         = 105,
//   HRTIM2_TIMB_INT_IRQn         = 106,
//   HRTIM2_TIMC_INT_IRQn         = 107,
//   HRTIM2_TIMD_INT_IRQn         = 108,
//   HRTIM2_TIME_INT_IRQn         = 109,
//   HRTIM2_TIM_FLT_INT_IRQn      = 110,
//   HRTIM2_TIMF_INT_IRQn         = 111,
//   B_DAC1_IRQn                  = 120,
//   DAC1_IRQn                    = 121,
//   DAC2_IRQn                    = 122,
//   DAC3_IRQn                    = 123,
//   DAC4_IRQn                    = 124,
//   COMP_1_2_IRQn                = 129,
//   COMP_3_4_IRQn                = 130,
//   COMP_5_6_IRQn                = 131,
//   COMP_7_8_IRQn                = 132,
//   ADC1_IRQn                    = 137,
//   ADC2_IRQn                    = 138,
//   ADC3_IRQn                    = 139,
//   ADC4_IRQn                    = 140,
//   ADC5_IRQn                    = 141,
//   SD_ADC1_IRQn                 = 145,
//   SD_ADC2_IRQn                 = 146,
//   CORE2_SEV_IRQn               = 150,
//   CORE1_SEV_IRQn               = 151,
//   FCCU_INT_IRQn                = 154,
//   STCU_INT_IRQn                = 156, /* reserved? */
//   PMC_DIG_IRQn                 = 160,
//   HSM2HST0_15_IRQn             = 164,
//   HSM2HST16_31_IRQn            = 165,
//   JDC_IRQn                     = 168
// } IRQn_Type;

#include "core_cm7.h"

#include "SR5E1_ADC.h"
#include "SR5E1_CEM.h"
#include "SR5E1_CMU.h"
#include "SR5E1_COMP.h"
#include "SR5E1_CORDIC.h"
#include "SR5E1_CRC.h"
#include "SR5E1_DAC.h"
#include "SR5E1_DBGMCU.h"
#include "SR5E1_DMA.h"
#include "SR5E1_DMAMUX.h"
#include "SR5E1_EXTI.h"
#include "SR5E1_FCCU.h"
#include "SR5E1_FDCAN.h"
#include "SR5E1_FLASH_REG_ITF.h"
#include "SR5E1_GPIO.h"
#include "SR5E1_HRTIM.h"
#include "SR5E1_HSEM.h"
#include "SR5E1_I2C.h"
#include "SR5E1_IWDG.h"
#include "SR5E1_NVM_CTRL.h"
#include "SR5E1_PLLDIG.h"
#include "SR5E1_PMC_DIG.h"
#include "SR5E1_RCC.h"
#include "SR5E1_RTC.h"
#include "SR5E1_SD_ADC.h"
#include "SR5E1_SPI.h"
#include "SR5E1_SSCM.h"
#include "SR5E1_SYSCFG.h"
#include "SR5E1_TDM.h"
#include "SR5E1_TIM.h"
#include "SR5E1_UART.h"
#include "SR5E1_WWDG.h"



#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif /* __SR5E1_CM7_H */
