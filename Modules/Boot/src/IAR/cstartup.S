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
 * @file    IAR/cstartup.s
 * @brief   Generic IAR Boot module source file.
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
 * @brief   VTOR special register initialization.
 * @details VTOR is initialized to point to the vectors table.
 * @note    This option can only be enabled on Cortex-M0+ cores.
 */
#if !defined(CRT0_VTOR_INIT) || defined(__DOXYGEN__)
#define CRT0_VTOR_INIT                      TRUE
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
 * @brief   Heap segment initialization value.
 */
#if !defined(CRT0_HEAP_FILL_PATTERN) || defined(__DOXYGEN__)
#define CRT0_HEAP_FILL_PATTERN              0xCCCCCCCC
#endif

/**
 * @brief   Heap segment initialization switch.
 */
#if !defined(CRT0_INIT_HEAP) || defined(__DOXYGEN__)
#define CRT0_INIT_HEAP                      FALSE
#endif

/*===========================================================================*/
/* Code section.                                                             */
/*===========================================================================*/

#if !defined(__DOXYGEN__)

        MODULE  ?cstartup

        AAPCS INTERWORK, VFP_COMPATIBLE, ROPI
        PRESERVE8
        
        SECTION .reset_handler:CODE:REORDER(2)
        THUMB
        
__reset_handler:
        b        __iar_program_start

        PUBLIC  __iar_program_start
        PUBLIC  __reset_handler
        EXTWEAK __iar_init_core
        EXTWEAK __iar_init_vfp
        EXTERN  __cmain
        EXTERN  __vector_table
        EXTERN  __itcm_start__
        EXTERN  __itcm_end__
        EXTERN  __dtcm_start__
        EXTERN  __dtcm_end__
        EXTWEAK __core_init

        SECTION IRQSTACK:DATA:NOROOT(3)
        SECTION CSTACK:DATA:NOROOT(3)
        SECTION DATABSS:DATA:NOROOT(3)
        SECTION HEAP:DATA:NOROOT(3)

        SECTION .itcm_init:CODE:REORDER(2) 
        SECTION .itcm:CODE:REORDER(2)
        SECTION .text:CODE:REORDER(2)
        THUMB
        
__iar_program_start:
        /* Interrupts are globally masked initially.*/
        cpsid   i
        /* MSP stack pointers initialization.*/
        ldr     r0, =SFE(IRQSTACK)
        msr     MSP, r0
        /* PSP stack pointers initialization.*/
        ldr     r0, =SFE(CSTACK)
        msr     PSP, r0
        movs    r0, #CONTROL_MODE_PRIVILEGED | CONTROL_USE_PSP
        msr     CONTROL, r0
        isb

#if CRT0_INIT_RAM == TRUE
        /* Initialization value.*/
        movs    r0, #0
        movs    r1, #0

        /* RAM initialization. Note, it initializes the whole RAM (IRQSTACK,
           CSTACK, DATABSS, HEAP) used by the application from the start of
           block IRQSTACK to the end of the block HEAP. Moreover, it assumes
           that the size of RAM to initialize (from the start of the block
           IRQSTACK to the end of the block HEAP) is a multiple of 8 so the
           linker file must ensure this.*/
        ldr     r2, =SFB(IRQSTACK)
        ldr     r3, =SFE(HEAP)

ramloop:
        strd    r0, r1, [r2], #8
        cmp     r2, r3
        blt     ramloop
#endif

#if CRT0_INIT_ITCM == TRUE
        /* ITCM initialization.*/
        ldr     r1, =__itcm_start__
        ldr     r2, =__itcm_end__
        
        movs    r4, #0
        movs    r5, #0
itcmloop1:
        strd    r4, r5, [r1], #8
        cmp     r1, r2
        blt     itcmloop1

        /* Copying any data linked into ITCM within core ITCM.*/
        /* In particular, copying number of bytes = __itcm_size__ from memory
           address = __itcm_load__ to memory address = __itcm_start__.*/
        /* r2 = __itcm_size__ */
        ldr     r2, =SIZEOF(.itcm)
        /* If __itcm_size__ == 0 => nothing to copy */
        cmp     r2, #0
        beq     itcmdone

        /* r0 = __itcm_load__ */
        ldr     r0, =SFB(.itcm_init)
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

        /* DTCM initialization.*/
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
#endif

#if CRT0_VTOR_INIT == TRUE
        ldr     r0, =__vector_table  
        movw    r1, #SCB_VTOR & 0xFFFF  
        movt    r1, #SCB_VTOR >> 16  
        str     r0, [r1]  
#endif

#if CRT0_INIT_CORE == TRUE
        /* Core initialization.*/
        bl      __core_init
#endif

#if CRT0_INIT_STACKS == TRUE
        ldr     r0, =CRT0_STACKS_FILL_PATTERN
        ldr     r1, =CRT0_STACKS_FILL_PATTERN
        /* Main Stack initialization. Note, it assumes that the stack size
           is a multiple of 8 so the linker file must ensure this.*/
        ldr     r2, =SFB(IRQSTACK)
        ldr     r3, =SFE(IRQSTACK)
msloop:
        strd    r0, r1, [r2], #8
        cmp     r2, r3
        blt     msloop

        /* Process Stack initialization. Note, it assumes that the stack size
           is a multiple of 8 so the linker file must ensure this.*/
        ldr     r2, =SFB(CSTACK)
        ldr     r3, =SFE(CSTACK)
psloop:
        strd    r0, r1, [r2], #8
        cmp     r2, r3
        blt     psloop
#endif

#if CRT0_INIT_HEAP == TRUE
        ldr     r0, =CRT0_HEAP_FILL_PATTERN
        ldr     r1, =CRT0_HEAP_FILL_PATTERN
        /* Heap initialization. Note, it assumes that the heap size
           is a multiple of 8 so the linker file must ensure this.*/
        ldr     r2, =SFB(HEAP)
        ldr     r3, =SFE(HEAP)
hloop:
        strd    r0, r1, [r2], #8
        cmp     r2, r3
        blt     hloop
#endif

        bl      __early_init
        bl      __iar_init_core
        bl      __iar_init_vfp
        b       __cmain

        SECTION .text:CODE:NOROOT:REORDER(2)
        PUBWEAK __early_init
__early_init:
        bx      lr

        END

#endif /* !defined(__DOXYGEN__) */

/**< @} */
