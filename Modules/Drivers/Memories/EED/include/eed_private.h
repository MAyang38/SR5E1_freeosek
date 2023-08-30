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
 * @file    eed_private.h
 * @brief   EEPROM Emulation Driver private header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup MEMORIES
 * @ingroup DRIVERS
 * @addtogroup EED
 * @ingroup MEMORIES
 * @{
 */

#ifndef _EED_PRIVATE_H_
#define _EED_PRIVATE_H_

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
 * @brief   EED driver structure.
 * @note    This structure is internal to the EED driver.
 */
struct eed_driver {
    /**
     * @brief   EED configuration.
     */
    eed_cfg_t                cfg;
    /**
     * @brief   EED initilization flag ("true" means the EDD is initiliazed,
     *          "false" otherwise).
     */
    bool                     is_init;
    /**
     * @brief   EED active block.
     */
    uint8_t                  act_blk;
    /**
     * @brief   EED free space in active block.
     */
    uint32_t                 freespace;
};

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

uint32_t eed_dev_get_start_addr(eed_driver_t *edp, uint8_t blk);
uint32_t eed_dev_get_size(eed_driver_t *edp, uint8_t blk);
uint8_t  eed_dev_get_space(eed_driver_t *edp, uint8_t blk);
bool eed_dev_flashinit(void);
bool eed_dev_flashunlock(uint8_t block, uint8_t space);
bool eed_dev_flasherase(uint8_t block, uint8_t space);
bool eed_dev_flashprogram64(uint32_t address, uint64_t buffer);
bool eed_dev_flashblankcheck(uint32_t address, uint32_t size);

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/*===========================================================================*/
/* Module late inclusions.                                                   */
/*===========================================================================*/

#endif /* _EED_PRIVATE_H_ */

/** @} */

