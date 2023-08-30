/****************************************************************************
 *
 * Copyright (c) 2021 STMicroelectronics - All Rights Reserved
 *
 * License terms: STMicroelectronics Proprietary in accordance with licensing
 * terms SLA0098 at www.st.com.
 *
 * THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
 * INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *****************************************************************************/
/**
 * @file    flash.h
 * @brief   FLASH driver header.
 *
 * @defgroup DRIVERS DRIVERS
 * @defgroup MEM MEM
 * @ingroup DRIVERS
 * @addtogroup FLASH
 * @ingroup MEM
 * @{
 */
#ifndef _FLASH_H_
#define _FLASH_H_

/*===========================================================================*/
/* Includes.                                                                 */
/*===========================================================================*/
#include <ssd_C55.h>

/*===========================================================================*/
/* Constants.                                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Macros.                                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Types.                                                                    */
/*===========================================================================*/

/** @brief   Type of a structure representing an FLASH driver. */
typedef struct FLASHDriver FLASHDriver;

/**
 * @enum flash_block_ind_t
 * FLASH Indicators for getting the number of blocks in the NVM address space.
 */
typedef enum {
    FLASH_BLOCK_16K,
    FLASH_BLOCK_32K,
    FLASH_BLOCK_64K,
    FLASH_BLOCK_128K
} flash_block_ind_t;

/**
 * @brief   FLASH notification callback type.
 *
 * @param flashd         pointer to the @p FLASHDriver object triggering the callback
 * @param opStatus       the current status of the in-progress operation
 */
typedef void (*flash_callback_t)(FLASHDriver *flashd, unsigned long opStatus);

/**
 * @enum flash_cb_type_t
 * FLASH callback type.
 */
typedef enum {
    FLASH_CALLBACK_MODE_OP_PROGRAM,          /**< program callback */
    FLASH_CALLBACK_MODE_OP_PROGRAM_VERIFY,   /**< program verify callback */
    FLASH_CALLBACK_MODE_OP_ERASE,            /**< erase callback */
    FLASH_CALLBACK_MODE_OP_BLANK_CHECK,      /**< blank check callback */
    FLASH_CALLBACK_MAX                       /**< Number of callbacks */
} flash_cb_type_t;


/*===========================================================================*/
/* Global variables                                                          */
/*===========================================================================*/

/** @brief   FLASH  CTRL1 driver instance. */
extern FLASHDriver FLASHD0;

/*===========================================================================*/
/* Global functions.                                                         */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

void flash_start(FLASHDriver *flashd);
void flash_stop(FLASHDriver *flashd);

void          flash_init(void);

unsigned long flash_setLock(FLASHDriver *flashd, unsigned char blkLockIndicator, unsigned long blkLockState);
unsigned long flash_getLock(FLASHDriver *flashd, unsigned char blkLockIndicator, unsigned long *blkLockState);
unsigned long flash_flashProgram(FLASHDriver *flashd, unsigned char factoryPgmFlag, unsigned long dest, unsigned long size, unsigned long source);
unsigned long flash_programVerify(FLASHDriver *flashd, unsigned long dest, unsigned long size, unsigned long source, unsigned long *pFailedAddress, unsigned long *pFailedData, unsigned long *pFailedSource);
unsigned long flash_flashErase(FLASHDriver *flashd, unsigned char eraseOption, unsigned long lowBlockSelect, unsigned long midBlockSelect, unsigned long highBlockSelect, N256K_BLOCK_SEL n256KBlockSelect);
unsigned long flash_blankCheck(FLASHDriver *flashd, unsigned long dest, unsigned long size, unsigned long *pFailedAddress, unsigned long *pFailedData);

flash_callback_t flash_set_callback(FLASHDriver *flashd, flash_cb_type_t cb_type, flash_callback_t callback);
unsigned long flash_getLOWBlockInfo(FLASHDriver *flashd, flash_block_ind_t blkLockIndicator);
unsigned long flash_getMIDBlockInfo(FLASHDriver *flashd, flash_block_ind_t blkLockIndicator);
unsigned long flash_getHIGHBlockInfo(FLASHDriver *flashd, flash_block_ind_t blkLockIndicator);
unsigned long flash_get256KBlockInfo(FLASHDriver *flashd);
unsigned long flash_getProgrammableSize(FLASHDriver *flashd);
void          flash_setProgrammableSize(FLASHDriver *flashd, unsigned long programmableSize);

#ifdef __cplusplus
}
#endif

#endif /* _FLASH_H_ */
/** @} */
