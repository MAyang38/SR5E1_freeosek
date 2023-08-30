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
 * @file    exti_dev.h
 * @brief   EXTI device specific header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup SYSTEM
 * @ingroup DRIVERS
 * @addtogroup EXTI
 * @ingroup SYSTEM
 * @{
 */

#ifndef _EXTI_DEV_H_
#define _EXTI_DEV_H_

#include <irq.h>
#include <platform.h>

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Module pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived conants and error checks.                                       */
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

IRQn_Type exti_dev_get_vector(exti_line_t line);

IRQ_HANDLER(IRQ_EXTI0_HANDLER);
IRQ_HANDLER(IRQ_EXTI1_HANDLER);
IRQ_HANDLER(IRQ_EXTI2_HANDLER);
IRQ_HANDLER(IRQ_EXTI3_HANDLER);
IRQ_HANDLER(IRQ_EXTI4_HANDLER);
IRQ_HANDLER(IRQ_EXTI9_5_HANDLER);
IRQ_HANDLER(IRQ_EXTI15_10_HANDLER);

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/*===========================================================================*/
/* Module late inclusions.                                                   */
/*===========================================================================*/

#endif /* _EXTI_DEV_H_ */

/** @} */
