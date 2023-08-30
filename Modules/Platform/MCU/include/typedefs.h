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
 *****************************************************************************/
/**
 * @file    typedefs.h
 * @brief   Dummy typedefs file.
 *
 * @addtogroup PLATFORM
 * @addtogroup MCU
 * @ingroup PLATFORM
 * @{
 */

#ifndef _TYPEDEFS_H_
#define _TYPEDEFS_H_

#if !defined(_FROM_ASM_)

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/**
 * @name    Common constants
 * @{
 */
#if !defined(FALSE) || defined(__DOXYGEN__)
#define FALSE                               0
#endif

#if !defined(TRUE) || defined(__DOXYGEN__)
#define TRUE                                1
#endif

/*
 * Derived generic types.
 */
typedef volatile int8_t     vint8_t;        /**< Volatile signed 8 bits.    */
typedef volatile uint8_t    vuint8_t;       /**< Volatile unsigned 8 bits.  */
typedef volatile int16_t    vint16_t;       /**< Volatile signed 16 bits.   */
typedef volatile uint16_t   vuint16_t;      /**< Volatile unsigned 16 bits. */
typedef volatile int32_t    vint32_t;       /**< Volatile signed 32 bits.   */
typedef volatile uint32_t   vuint32_t;      /**< Volatile unsigned 32 bits. */
typedef volatile uint64_t   vuint64_t;      /**< Volatile unsigned 64 bits. */

#endif /* !defined(_FROM_ASM_) */

#endif /* _TYPEDEFS_H_ */
