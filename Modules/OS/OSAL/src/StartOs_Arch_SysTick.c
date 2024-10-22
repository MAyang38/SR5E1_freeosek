/* Copyright 2014, Pablo Ridolfi
 *
 * This file is part of CIAA Firmware.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/** \brief Start the system counter
 **
 ** This file includes the function to start the system counter
 **
 **/

/** \addtogroup CIAA_Firmware CIAA Firmware
 ** @{ */
/** \addtogroup FreeOSEK_Os
 ** @{ */
/** \addtogroup FreeOSEK_Os_Internal
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 *
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * yyyymmdd v0.0.1 initials initial version
 */

/*==================[inclusions]=============================================*/
#include "Os_Internal_Arch_Cpu.h"
// #include "stm32f4xx_conf.h"
#include "core_cm7.h"
#include "clock.h"
#include "osal.h"

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/
void StartOs_Arch_SysTick(void)
{
   /* 激活内存故障，页故障，总线故障*/
   /* Activate MemFault, UsageFault and BusFault exceptions */
   SCB->SHCSR |= SCB_SHCSR_MEMFAULTENA_Msk | SCB_SHCSR_USGFAULTENA_Msk | SCB_SHCSR_BUSFAULTENA_Msk;
   /* 设置PendSV的优先级*/
   /* Set lowest priority for SysTick and PendSV */
   NVIC_SetPriority(PendSV_IRQn, (1 << __NVIC_PRIO_BITS) - 1);

   /* 初始化SysTick */ 
   osal_init();
   
   /* Activate SysTick */
   // // osal_inc_tick();
   // SystemCoreClockUpdate();
   // SysTick_Config(SystemCoreClock/1000);

   // /* Update priority set by SysTick_Config */
   // NVIC_SetPriority(SysTick_IRQn, (1<<__NVIC_PRIO_BITS) - 1);
}


// void SystemCoreClockUpdate(void)
// {
//   uint32_t tmp = 0, pllvco = 0, pllp = 2, pllsource = 0, pllm = 2;

//   /* Get SYSCLK source -------------------------------------------------------*/
//   tmp = RCC->CFGR & RCC_CFGR_SWS;

//   switch (tmp)
//   {
//     case 0x00:  /* HSI used as system clock source */
//       SystemCoreClock = HSI_VALUE;
//       break;
//     case 0x04:  /* HSE used as system clock source */
//       SystemCoreClock = HSE_VALUE;
//       break;
//     case 0x08:  /* PLL used as system clock source */

//       /* PLL_VCO = (HSE_VALUE or HSI_VALUE / PLL_M) * PLL_N
//          SYSCLK = PLL_VCO / PLL_P
//          */
//       pllsource = (RCC->PLLCFGR & RCC_PLLCFGR_PLLSRC) >> 22;
//       pllm = RCC->PLLCFGR & RCC_PLLCFGR_PLLM;

//       if (pllsource != 0)
//       {
//         /* HSE used as PLL clock source */
//         pllvco = (HSE_VALUE / pllm) * ((RCC->PLLCFGR & RCC_PLLCFGR_PLLN) >> 6);
//       }
//       else
//       {
//         /* HSI used as PLL clock source */
//         pllvco = (HSI_VALUE / pllm) * ((RCC->PLLCFGR & RCC_PLLCFGR_PLLN) >> 6);
//       }

//       pllp = (((RCC->PLLCFGR & RCC_PLLCFGR_PLLP) >>16) + 1 ) *2;
//       SystemCoreClock = pllvco/pllp;
//       break;
//     default:
//       SystemCoreClock = HSI_VALUE;
//       break;
//   }
//   /* Compute HCLK frequency --------------------------------------------------*/
//   /* Get HCLK prescaler */
//   tmp = AHBPrescTable[((RCC->CFGR & RCC_CFGR_HPRE) >> 4)];
//   /* HCLK frequency */
//   SystemCoreClock >>= tmp;
// }
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

