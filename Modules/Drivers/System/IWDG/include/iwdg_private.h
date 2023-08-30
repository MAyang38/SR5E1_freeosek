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
 * @file    iwdg_private.h
 * @brief   IWDG driver private header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup SYSTEM
 * @ingroup DRIVERS
 * @addtogroup IWDG
 * @ingroup SYSTEM
 * @{
 */

#ifndef _IWDG_PRIVATE_H_
#define _IWDG_PRIVATE_H_

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
 * @brief   IWDG driver structure.
 * @note    This structure is internal to the IWDG driver.
 */
struct iwdg_driver {
    /**
     * @brief   Pointer to IWDG registers block.
     */
    IWDG_TypeDef             *iwdg;
    /**
     * @brief   IWDG prescaler.
     */
    iwdg_prescaler_t         prescaler;
    /**
     * @brief   IWDG down-counter reload value[0x0:0xFFF].
     */
    uint16_t                 counter;
    /**
     * @brief   IWDG window value,compared to the down-counter [0x0:0xFFF].
     */
    uint16_t                 window;
};

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

IWDG_TypeDef *iwdg_dev_get_reg_ptr(iwdg_driver_t *idp);
uint8_t iwdg_dev_is_hw_en(iwdg_driver_t *idp);

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/*===========================================================================*/
/* Module late inclusions.                                                   */
/*===========================================================================*/

#endif /* _IWDG_PRIVATE_H_ */

/** @} */

