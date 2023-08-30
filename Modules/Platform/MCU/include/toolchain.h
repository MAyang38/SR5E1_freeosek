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
 * @file    toolchain.h
 * @brief   toolchain for ARM compilers.
 *
 * @addtogroup PLATFORM
 * @addtogroup MCU
 * @ingroup PLATFORM
 * @{
 */

#ifndef _TOOLCHAIN_H_
#define _TOOLCHAIN_H_

/***************/
/* Green Hills */
/***************/
#if defined(__ghs__)

#define _ASM_THUMB_               .thumb2

#define _ASM_THUMB_FUNCTION_

/****************/
/* HIGHTEC, GCC */
/****************/
#else

#define _ASM_THUMB_               .thumb

#define _ASM_THUMB_FUNCTION_      .thumb_func

#endif

#endif /* _TOOLCHAIN_H_ */
