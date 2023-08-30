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
 * @file    GCC/crt0.S
 * @brief   Generic GCC Boot module source file.
 *
 * @addtogroup BOOT
 * @{
 */

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

#if !defined(FALSE) || defined(__DOXYGEN__)
#define FALSE                               0
#endif

#if !defined(TRUE) || defined(__DOXYGEN__)
#define TRUE                                1
#endif

#define _FROM_ASM_
#include "cmparams.h"
#include "toolchain.h"

#define CONTROL_MODE_PRIVILEGED             0
#define CONTROL_MODE_UNPRIVILEGED           1
#define CONTROL_USE_MSP                     0
#define CONTROL_USE_PSP                     2
#define CONTROL_FPCA                        4

#define FPCCR_ASPEN                         (1 << 31)
#define FPCCR_LSPEN                         (1 << 30)

#define SCB_VTOR                            0xE000ED08
#define SCB_CPACR                           0xE000ED88
#define SCB_FPCCR                           0xE000EF34
#define SCB_FPDSCR                          0xE000EF3C

/*===========================================================================*/
/* Module pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @brief   RAM initialization switch.
 */
#if !defined(CRT0_INIT_RAM) || defined(__DOXYGEN__)
#define CRT0_INIT_RAM                       TRUE
#endif

/**
 * @brief   ITCM initialization switch.
 */
#if !defined(CRT0_INIT_ITCM) || defined(__DOXYGEN__)
#define CRT0_INIT_ITCM                      TRUE
#endif

/**
 * @brief   DTCM initialization switch.
 */
#if !defined(CRT0_INIT_DTCM) || defined(__DOXYGEN__)
#define CRT0_INIT_DTCM                      TRUE
#endif

/**
 * @brief   Enforces initialization of MSP.
 * @note    This is required if the boot process is not reliable for whatever
 *          reason (bad ROMs, bad bootloaders, bad debuggers).
 */
#if !defined(CRT0_FORCE_MSP_INIT) || defined(__DOXYGEN__)
#define CRT0_FORCE_MSP_INIT                 TRUE
#endif

/**
 * @brief   VTOR special register initialization.
 * @details VTOR is initialized to point to the vectors table.
 * @note    This option can only be enabled on Cortex-M0+ cores.
 */
#if !defined(CRT0_VTOR_INIT) || defined(__DOXYGEN__)
#define CRT0_VTOR_INIT                      TRUE
#endif

/**
 * @brief   FPU initialization switch.
 * @note    Its value depedens on compiling options.
 */
#if defined(USE_FPU) || defined(__DOXYGEN__)
#define CRT0_INIT_FPU                       TRUE
#else
#define CRT0_INIT_FPU                       FALSE
#endif

/**
 * @brief   Control special register initialization value.
 * @details The system is setup to run in privileged mode using the PSP
 *          stack (dual stack mode).
 */
#if !defined(CRT0_CONTROL_INIT) || defined(__DOXYGEN__)
#define CRT0_CONTROL_INIT                   (CONTROL_USE_PSP |              \
                                             CONTROL_MODE_PRIVILEGED)
#endif

/**
 * @brief   Core initialization switch.
 */
#if !defined(CRT0_INIT_CORE) || defined(__DOXYGEN__)
#define CRT0_INIT_CORE                      TRUE
#endif

/**
 * @brief   Stack segments initialization value.
 */
#if !defined(CRT0_STACKS_FILL_PATTERN) || defined(__DOXYGEN__)
#define CRT0_STACKS_FILL_PATTERN            0x55555555
#endif

/**
 * @brief   Stack segments initialization switch.
 */
#if !defined(CRT0_INIT_STACKS) || defined(__DOXYGEN__)
#define CRT0_INIT_STACKS                    FALSE
#endif

/**
 * @brief   DATA segment initialization switch.
 */
#if !defined(CRT0_INIT_DATA) || defined(__DOXYGEN__)
#define CRT0_INIT_DATA                      TRUE
#endif

/**
 * @brief   Constructors invocation switch.
 */
#if !defined(CRT0_CALL_CONSTRUCTORS) || defined(__DOXYGEN__)
#define CRT0_CALL_CONSTRUCTORS              TRUE
#endif

/**
 * @brief   Destructors invocation switch.
 */
#if !defined(CRT0_CALL_DESTRUCTORS) || defined(__DOXYGEN__)
#define CRT0_CALL_DESTRUCTORS               TRUE
#endif

/**
 * @brief   FPU FPCCR register initialization value.
 * @note    Only used if @p CRT0_INIT_FPU is equal to @p TRUE.
 */
#if !defined(CRT0_FPCCR_INIT) || defined(__DOXYGEN__)
#define CRT0_FPCCR_INIT                     (FPCCR_ASPEN | FPCCR_LSPEN)
#endif

/**
 * @brief   CPACR register initialization value.
 * @note    Only used if @p CRT0_INIT_FPU is equal to @p TRUE.
 */
#if !defined(CRT0_CPACR_INIT) || defined(__DOXYGEN__)
#define CRT0_CPACR_INIT                     0x00F00000
#endif

/*===========================================================================*/
/* Code section.                                                             */
/*===========================================================================*/

#if !defined(__DOXYGEN__)

                _ASM_THUMB_
                .text

/*
 * CRT0 entry point.
 */
                .align  2
                _ASM_THUMB_FUNCTION_
                .global _crt0_entry
_crt0_entry:

#if CRT0_INIT_RAM == TRUE
                /* Initialization value.*/
                movs    r0, #0
                movs    r1, #0

                /* Initializing RAM. Note, it assumes that the size of RAM to
                   initialize (from __mem_start__ to __mem_end__) is a multiple
                   of 8, so the linker file must ensure this.*/
                ldr     r2, =__mem_start__
                ldr     r3, =__mem_end__
ramloop:
                strd    r0, r1, [r2], #8
                cmp     r2, r3
                blt     ramloop
#endif

#if CRT0_INIT_ITCM == TRUE
                /* Initializing core ITCM.*/
                ldr     r1, =__itcm_start__
                ldr     r2, =__itcm_end__

                movs    r4, #0
                movs    r5, #0
itcmloop1:
                strd    r4, r5, [r1], #8
                cmp     r1, r2
                blt     itcmloop1

                /* Copying any data linked into ITCM within core ITCM */
                ldr     r2, =__itcm_size__
                /* If __itcm_size__ == 0 => nothing to copy */
                cmp     r2, #0
                beq     itcmdone

                ldr     r0, =__itcm_load__
                ldr     r1, =__itcm_start__
                add     r3, r1, r2

itcmloop2:
                ldrd    r4, r5, [r0], #8
                strd    r4, r5, [r1], #8
                cmp     r1, r3
                blt     itcmloop2
itcmdone:
#endif

#if CRT0_INIT_DTCM == TRUE
                /* Initialization value.*/
                movs    r0, #0

                /* Initializing core DTCM.*/
                ldr     r1, =__dtcm_start__
                ldr     r2, =__dtcm_end__
dtcmloop1:
                str     r0, [r1, #0]
                str     r0, [r1, #4]
                str     r0, [r1, #8]
                str     r0, [r1, #12]
                str     r0, [r1, #16]
                str     r0, [r1, #20]
                str     r0, [r1, #24]
                str     r0, [r1, #28]
                add     r1, r1, #32
                cmp     r1, r2
                blt     dtcmloop1

                /* Copying any data linked into DTCM within core DTCM */
                /* Copy __dtcm_size__ bytes from address __dtcm_load__ to
                   address __dtcm_start__. If __dtcm_size__ == 0 => copy
                   is skipped.*/
                ldr     r2, =__dtcm_size__
                cmp     r2, #0
                beq     dtcmdone

                ldr     r0, =__dtcm_load__
                ldr     r1, =__dtcm_start__
                add     r3, r1, r2

dtcmloop2:
                ldr     r4, [r0]
                str     r4, [r1]
                add     r0, r0, #4
                add     r1, r1, #4
                cmp     r1, r3
                blt     dtcmloop2
dtcmdone:
#endif

                /* Interrupts are globally masked initially.*/
                cpsid   i

#if CRT0_FORCE_MSP_INIT == TRUE
                /* MSP stack pointers initialization.*/
                ldr     r0, =__main_stack_end__
                msr     MSP, r0
#endif

                /* PSP stack pointers initialization.*/
                ldr     r0, =__process_stack_end__
                msr     PSP, r0

#if CRT0_VTOR_INIT == TRUE
                ldr     r0, =_vectors
                ldr     r1, =SCB_VTOR
                str     r0, [r1]
#endif

#if (CRT0_INIT_FPU == TRUE)
                /* FPU FPCCR initialization.*/
                movw    r0, #CRT0_FPCCR_INIT & 0xFFFF
                movt    r0, #CRT0_FPCCR_INIT >> 16
                movw    r1, #SCB_FPCCR & 0xFFFF
                movt    r1, #SCB_FPCCR >> 16
                str     r0, [r1]
                dsb
                isb

                /* CPACR initialization.*/
                movw    r0, #CRT0_CPACR_INIT & 0xFFFF
                movt    r0, #CRT0_CPACR_INIT >> 16
                movw    r1, #SCB_CPACR & 0xFFFF
                movt    r1, #SCB_CPACR >> 16
                str     r0, [r1]
                dsb
                isb

                /* FPU FPSCR initially cleared.*/
                mov     r0, #0
                vmsr    FPSCR, r0

                /* FPU FPDSCR initially cleared.*/
                movw    r1, #SCB_FPDSCR & 0xFFFF
                movt    r1, #SCB_FPDSCR >> 16
                str     r0, [r1]

                /* Enforcing FPCA bit in the CONTROL register.*/
                movs    r0, #CRT0_CONTROL_INIT | CONTROL_FPCA

#else
                movs    r0, #CRT0_CONTROL_INIT
#endif

                /* CONTROL register initialization as configured.*/
                msr     CONTROL, r0
                isb

#if CRT0_INIT_CORE == TRUE
                /* Core initialization.*/
                bl      __core_init
#endif

#if CRT0_INIT_STACKS == TRUE
                ldr     r0, =CRT0_STACKS_FILL_PATTERN
                ldr     r1, =CRT0_STACKS_FILL_PATTERN
                /* Main Stack initialization. Note, it assumes that the
                   stack size is a multiple of 8 so the linker file must
                   ensure this.*/
                ldr     r2, =__main_stack_base__
                ldr     r3, =__main_stack_end__
msloop:
                strd    r0, r1, [r2], #8
                cmp     r2, r3
                blt     msloop

                /* Process Stack initialization. Note, it assumes that the
                   stack size is a multiple of 8 so the linker file must
                   ensure this.*/
                ldr     r2, =__process_stack_base__
                ldr     r3, =__process_stack_end__
psloop:
                strd    r0, r1, [r2], #8
                cmp     r2, r3
                blt     psloop
#endif

                /* Early initialization..*/
                bl      __early_init

#if CRT0_INIT_DATA == TRUE
                /* Data initialization. Note, it assumes that the DATA size
                   is a multiple of 4 so the linker file must ensure this.*/
                ldr     r1, =__data_load__
                ldr     r2, =__data_start__
                ldr     r3, =__data_end__
dloop:
                cmp     r2, r3
                bge     enddloop
                ldr     r0, [r1]
                str     r0, [r2]
                add     r1, r1, #4
                add     r2, r2, #4
                b       dloop
enddloop:
#endif

                /* Late initialization..*/
                bl      __late_init

#if CRT0_CALL_CONSTRUCTORS == TRUE
                /* Constructors invocation.*/
                ldr     r4, =__init_array_start
                ldr     r5, =__init_array_end
initloop:
                cmp     r4, r5
                bge     endinitloop
                ldr     r1, [r4]
                blx     r1
                add     r4, r4, #4
                b       initloop
endinitloop:
#endif

                /* Main program invocation, r0 contains the returned value.*/
                bl      main

#if CRT0_CALL_DESTRUCTORS == TRUE
                /* Destructors invocation.*/
                ldr     r4, =__fini_array_start
                ldr     r5, =__fini_array_end
finiloop:
                cmp     r4, r5
                bge     endfiniloop
                ldr     r1, [r4]
                blx     r1
                add     r4, r4, #4
                b       finiloop
endfiniloop:
#endif

                /* Branching to the defined exit handler.*/
                ldr     r1, =__default_exit
                bx      r1

#endif

/** @} */
