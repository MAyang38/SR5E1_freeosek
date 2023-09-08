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
 * @file    osal_cfg.h
 * @brief   Operating System Abstraction Layer module configuration file.
 *
 * @addtogroup OS
 * @addtogroup OSAL
 * @ingroup OS
 * @{
 */

#ifndef _OSAL_CFG_H_
#define _OSAL_CFG_H_



// #define AppMode1 0

/**
 * @name    OSAL Tick Frequency
 * @{
 */
#define OSAL_CFG_TICKS_PER_SEC              OSAL_TICKS_PER_SEC_2000
/** @} */

/** 
 * @name    OSAL Tick Interrupt Priority
 * @{
 */
#define OSAL_CFG_TICK_INT_PRIO              (4UL)
/** @} */

/** 
 * @name    OSAL Tick Hook Enable Switch
 * @{
 */

#define OSAL_CFG_USE_TICK_HOOK              FALSE
/** @} */

#endif /* _OSAL_CFG_H_ */
