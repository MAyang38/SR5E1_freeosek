/****************************************************************************
 *
 * Copyright (c) 2023 STMicroelectronics - All Rights Reserved
 *
 * License terms: STMicroelectronics Proprietary in accordance with licensing
 * terms SLA0098 at www.st.com.
 *
 * THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
 * INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *****************************************************************************/
/**
 * @file    cem_private.h
 * @brief   CEM driver private header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup SAFETY
 * @ingroup DRIVERS
 * @addtogroup CEM
 * @ingroup SAFETY
 * @{
 */

#ifndef _CEM_PRIVATE_H_
#define _CEM_PRIVATE_H_

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
 * @brief   CEM driver structure.
 * @note    This structure is internal to the CEM driver.
 */
struct cem_driver {
    /**
     * @brief   Pointer to CEM registers block.
     */
    CEM_TypeDef              *cem;
    /**
     * @brief   Number of groups.
     */
    uint16_t                 group_num;
};

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

CEM_TypeDef *cem_dev_get_reg_ptr(cem_driver_t *cdp);
uint8_t cem_dev_get_group_num(cem_driver_t *cdp);
bool cem_dev_get_fccu_fault(cem_driver_t *cdp, uint16_t group_num, uint8_t *fccu_fault);

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/*===========================================================================*/
/* Module late inclusions.                                                   */
/*===========================================================================*/

#endif /* _CEM_PRIVATE_H_ */

/** @} */

