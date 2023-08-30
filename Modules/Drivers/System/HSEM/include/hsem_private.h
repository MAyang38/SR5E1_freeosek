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
 * @file    hsem_private.h
 * @brief   HSEM driver private header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup SYSTEM
 * @ingroup DRIVERS
 * @addtogroup HSEM
 * @ingroup SYSTEM
 * @{
 */

#ifndef _HSEM_PRIVATE_H_
#define _HSEM_PRIVATE_H_

#include <irq.h>
#include <platform.h>

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Module pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Module data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   HSEM driver structure.
 * @note    This structure is internal to the HSEM driver.
 */
struct hsem_driver {
    /**
     * @brief   Pointer to HSEM registers block.
     */
    HSEM_TypeDef             *hsem;
    /**
     * @brief   Core identifier on which the driver is used.
     */
    hsem_core_id_t           core_id;
    /**
     * @brief   Semaphore interrupt priority.
     */
    uint32_t                 prio;
    /**
     * @brief   Mask of enabled semaphore interrupts.
     */
    uint32_t                 irq_mask;
    /**
     * @brief   Pointers to semaphore callback functions.
     * @note    Set to @p NULL if not required.
     */
    hsem_cb_t                cb[HSEM_SEM_NUM];
};

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

IRQ_HANDLER(IRQ_HSEM_INT1_HANDLER);
IRQ_HANDLER(IRQ_HSEM_INT2_HANDLER);

IRQn_Type hsem_dev_get_vector(hsem_driver_t *hdp);
void hsem_dev_irq_disable_all(void);

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/*===========================================================================*/
/* Module late inclusions.                                                   */
/*===========================================================================*/

#endif /* _HSEM_PRIVATE_H_ */

/** @} */
