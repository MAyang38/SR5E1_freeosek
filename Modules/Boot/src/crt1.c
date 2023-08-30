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
 * @file    crt1.c
 * @brief   Boot module source file.
 *
 * @addtogroup BOOT
 * @{
 */

#include <stdbool.h>

#include "cmparams.h"

/*===========================================================================*/
/* Module local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Module exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Module local types.                                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Module local variables.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Module local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Local function prototypes                                                 */
/*===========================================================================*/

#if !defined(__DOXYGEN__)
__attribute__((weak))
#endif
void __core_init(void);

#if !defined(__DOXYGEN__)
__attribute__((weak))
#endif
void __early_init(void);

#if !defined(__DOXYGEN__)
__attribute__((weak))
#endif
void __late_init(void);

#if !defined(__DOXYGEN__)
__attribute__((noreturn, weak))
#endif
void __default_exit(void);

/*===========================================================================*/
/* Module exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Architecture-dependent core initialization.
 * @details This hook is invoked immediately after the stack initialization
 *          and before the DATA and BSS segments initialization.
 * @note    This function is a weak symbol.
 */
#if !defined(__DOXYGEN__)
__attribute__((weak))
#endif
void __core_init(void) {

    SCB_EnableICache();
    //SCB_EnableDCache();
}

/**
 * @brief   Early initialization.
 * @details This hook is invoked immediately after the stack and core
 *          initialization and before the DATA and BSS segments
 *          initialization.
 * @note    This function is a weak symbol.
 */
#if !defined(__DOXYGEN__)
__attribute__((weak))
#endif
void __early_init(void) {}

/**
 * @brief   Late initialization.
 * @details This hook is invoked after the DATA and BSS segments
 *          initialization and before any static constructor. The
 *          default behavior is to do nothing.
 * @note    This function is a weak symbol.
 */
#if !defined(__DOXYGEN__)
__attribute__((weak))
#endif
void __late_init(void) {}

/**
 * @brief   Default @p main() function exit handler.
 * @details This handler is invoked or the @p main() function exit. The
 *          default behavior is to enter an infinite loop.
 * @note    This function is a weak symbol.
 */
#if !defined(__DOXYGEN__)
__attribute__((noreturn, weak))
#endif
void __default_exit(void) {

    while (true) {
    }
}

/** @} */
