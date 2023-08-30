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
 * @file    eed.h
 * @brief   EEPROM Emulation Driver header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup MEMORIES
 * @ingroup DRIVERS
 * @addtogroup EED
 * @ingroup MEMORIES
 * @{
 */

#ifndef _EED_H_
#define _EED_H_

#include <typedefs.h>

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

/**
 * @name    EEPROM Emulation Driver no active block state definition
 * @{
 */
#define EED_NO_ACTIVE_BLOCK                 0xFFU          /**<  No active block available */
/** @} */

/**
 * @name    EEPROM Emulation Driver error definitions
 * @{
 */
#define EED_OK                              0x00000000UL   /**<  No error                             */
#define EED_FIRST_INIT_OK                   0x80000000UL   /**<  No error during first initialization */
#define EED_ERROR_FLASH_INIT                0x00000001UL   /**<  Flash initialization error           */
#define EED_ERROR_FLASH_UNLOCK              0x00000002UL   /**<  Flash unlock error                   */
#define EED_ERROR_FLASH_ERASE               0x00000004UL   /**<  Flash erase error                    */
#define EED_ERROR_FLASH_PROGRAM             0x00000008UL   /**<  Flash program error                  */
#define EED_ERROR_NOT_INITIALIZED           0x00000010UL   /**<  EED not initialized error            */
#define EED_ERROR_ID_NOT_FOUND              0x00000020UL   /**<  Record not found error               */
#define EED_ERROR_NO_SPACE                  0x00000040UL   /**<  No free space error                  */
#define EED_ERROR_SWAP                      0x00000080UL   /**<  Swap error                           */
/** @} */

/**
 * @name    EEPROM Emulation Driver block tag definitions (see bits
 *          manipulation table on RM)
 * @{
 */
#define EED_TAG_BLOCK_ACTIVE                0xFFFFFFFFFEFEFC80UL     /**<  Set when a block is marked as active                                          */
#define EED_TAG_BLOCK_INVALID               0xFFFFFFFCFEFCFC80UL     /**<  Set to invalidate a block when a new one is set as active                     */
#define EED_TAG_BLOCK_SWAP_START            0xFFFFFFFFFFFFFFFEUL     /**<  Set to mark a spare block when the data swap from the old active block starts */
/** @} */

/**
 * @name    EEPROM Emulation Driver record tag definitions (see bits
 *          manipulation table on RM)
 * @{
 */
#define EED_TAG_ID_WRITE_START              0xFCFCFFFCFCFCF880UL     /**<  Set when a record writing starts                                          */
#define EED_TAG_ID_WRITE_COMPLETE           0xFCF8F8F0FCE0E080UL     /**<  Set when a record writing is completed                                    */
#define EED_TAG_ID_INVALID                  0xF8F8E080F0E0E000UL     /**<  Set to invalidate an old occurrence of a record when a new one is written */
#define EED_TAG_ID_BAD                      0xE0E0E080E0E0C000UL     /**<  Set when the content of a record is bad                                   */                   
/** @} */

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
 * @brief   Type of EED block configuration.
 */
typedef struct {
    /**
     * @brief   Block start address.
     */
    uint32_t                 start_addr;
    /**
     * @brief   Block size.
     */
    uint32_t                 size;
    /**
     * @brief   Space (low, middle or high) related to the block.
     */
    uint8_t                  space;

    /**
     * @brief   Block number in the related space.
     */
    uint8_t                  number;
} eed_blk_cfg_t;

/**
 * @brief   Type of EED configuration.
 */
typedef struct {

    /**
     * @brief   Number of blocks used for EEPROM emulation.
     */
    uint8_t                  blk_num;
    /**
     * @brief   Pointer to block configuration array.
     */
    eed_blk_cfg_t            blk_cfg[2];
} eed_cfg_t;

/**
 * @brief   Type of an EEPROM Emulation Driver.
 */
typedef struct eed_driver eed_driver_t;

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/**
 * @brief   Rounds to 16bit boundary
 *
 * @param[in] _x_       value to round
 * @return              rounded value.
 *
 * @notapi
 */
#define EED_ROUND16(_x_)                                                       \
    ((((uint32_t)(_x_) % 16UL) == 0UL) ? ((uint32_t)(_x_)) : ((((uint32_t)(_x_) / 16UL) + 1UL) * 16UL))

/**
 * @brief   Reads 1byte
 *
 * @param[in] _addr_    address to read
 * @return              read value (1byte).
 *
 * @notapi
 */
#define EED_READ8(_addr_)                                                      \
    ((vuint8_t)(*(vuint8_t*)(_addr_)))

/**
 * @brief   Writes 1byte
 *
 * @param[in] _addr_    address to write
 * @param[in] _val_     value (1byte) to write
 *
 * @notapi
 */
#define EED_WRITE8(_addr_, _val_)                                              \
    (*(vuint8_t*)(_addr_) = (_val_))

/**
 * @brief   Writes 8bytes
 *
 * @param[in] _addr_    address to write
 * @param[in] _val_     value (8bytes) to write
 *
 * @notapi
 */
#define EED_WRITE64(_addr_, _val_)                                             \
    (*(vuint64_t*)(_addr_) = (_val_))

/**
 * @brief   Reads 1byte from flash
 *
 * @param[in] _addr_    address to read
 * @return              read value (1byte).
 *
 * @notapi
 */
#define FLASH_READ8(_addr_)                                                    \
    ((uint8_t)(*(vuint8_t*)(_addr_)))

/**
 * @brief   Reads 2bytes from flash
 *
 * @param[in] _addr_    address to read
 * @return              read value (2bytes).
 *
 * @notapi
 */
#define FLASH_READ16(_addr_)                                                   \
    ((uint16_t)(*(vuint16_t*)(_addr_)))

/**
 * @brief   Reads 4bytes from flash
 *
 * @param[in] _addr_    address to read
 * @return              read value (4bytes).
 *
 * @notapi
 */
#define FLASH_READ32(_addr_)                                                   \
    ((uint32_t)(*(vuint32_t*)(_addr_)))

/**
 * @brief   Reads 8bytes from flash
 *
 * @param[in] _addr_    address to read
 * @return              read value (8bytes).
 *
 * @notapi
 */
#define FLASH_READ64(_addr_)                                                   \
    ((uint64_t)(*(vuint64_t*)(_addr_)))

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

/* Export driver modules.*/
#include <eed_instances.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Initializes EED instance.
 *
 * @param[out] edp      pointer to a @p eed_driver_t structure
 *
 * @api
 */
void eed_init(eed_driver_t *edp);

/**
 * @brief   Configures EEPROM Emulation Driver blocks.
 * @note    This configuration becomes effective after eed_start.
 * @note    Currently version of the EEPROM Emulation Driver allows to use only
 *          2 blocks of the data flash.
 *
 * @param[out] edp      pointer to a @p eed_driver_t structure
 * @param[in] blk1      number of first data flash block used by the EEPROM
 *                      Emulation Driver
 * @param[in] blk2      number of second data flash block used by the EEPROM
 *                      Emulation Driver
 *
 * @api
 */
void eed_set_cfg(eed_driver_t *edp, uint8_t blk1, uint8_t blk2);


/**
 * @brief   Starts EEPROM Emulation Driver.
 *
 * @param[in] edp       pointer to a @p eed_driver_t structure
 * @return              operation status: EED_OK if no error occurs, otherwise
 *                      one of the following error codes:
 *            @arg @ref EED_ERROR_FLASH_INIT
 *            @arg @ref EED_ERROR_FLASH_UNLOCK
 *            @arg @ref EED_ERROR_FLASH_ERASE
 *            @arg @ref EED_ERROR_FLASH_PROGRAM
 *
 * @api
 */
uint32_t eed_start(eed_driver_t *edp);

/**
 * @brief   Writes an EEPROM Emulation Driver record.
 *
 * @param[in] edp       pointer to a @p eed_driver_t structure
 * @param[in] id        identifier of the record to be written
 * @param[in] size      size of the record
 * @param[in] source    data of the record
 * @return              operation status: EED_OK if the record is correctly
 *                      written, otherwise one of the following error codes:
 *            @arg @ref EED_ERROR_FLASH_PROGRAM
 *            @arg @ref EED_ERROR_NOT_INITIALIZED
 *            @arg @ref EED_ERROR_NO_SPACE
 *            @arg @ref EED_ERROR_SWAP
 *
 * @api
 */
uint32_t eed_write_id(eed_driver_t *edp, uint16_t id, uint16_t size, uint32_t source);

/**
 * @brief   Reads an EEPROM Emulation Driver record.
 *
 * @param[in] edp       pointer to a @p eed_driver_t structure
 * @param[in] id        identifier of the record to be read
 * @param[out] size     size of the record
 * @param[tuy] source   addrress of buffer in which data of  the record to be
 *                      read is stored
 * @return              operation status: EED_OK if the record is correctly
 *                      read, otherwise one of the following error codes:
 *            @arg @ref EED_ERROR_NOT_INITIALIZED
 *            @arg @ref EED_ERROR_ID_NOT_FOUND
 *
 * @api
 */
uint32_t eed_read_id(eed_driver_t *edp, uint16_t id, uint16_t *size, uint32_t source);

/**
 * @brief   Deletes an EEPROM Emulation Driver record.
 *
 * @param[in] edp       pointer to a @p eed_driver_t structure
 * @param[in] id        identifier of the record to be deleted
 * @return              operation status: EED_OK if the record is correctly
 *                      deleted, otherwise one of the following error codes:
 *            @arg @ref EED_ERROR_FLASH_PROGRAM
 *            @arg @ref EED_ERROR_NOT_INITIALIZED
 *            @arg @ref EED_ERROR_ID_NOT_FOUND
 *
 * @api
 */
uint32_t eed_delete_id(eed_driver_t *edp, uint16_t id);

/**
 * @brief   Returns the EEPROM Emulation Driver free space.
 *
 * @param[in] edp       pointer to a @p eed_driver_t structure
 * @return              the amount of free space [bytes].
 *
 * @api
 */
uint32_t eed_get_freespace(eed_driver_t *edp);

/**
 * @brief   Removes the EEPROM Emulation Driver.
 * @note    This functions deletes all blocks involved in the EEPROM emulation
 *          and reset all EEPROM Emulation Driver parameters.
 *
 * @param[in] edp       pointer to a @p eed_driver_t structure
 * @return              operation status: EED_OK if the record is correctly
 *                      deleted, otherwise one of the following error codes:
 *            @arg @ref EED_ERROR_FLASH_ERASE
 *            @arg @ref EED_ERROR_NOT_INITIALIZED
 *
 * @api
 */
uint32_t eed_remove(eed_driver_t *edp);

#ifdef __cplusplus
}
#endif

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/*===========================================================================*/
/* Module late inclusions.                                                   */
/*===========================================================================*/

#endif /* _EED_H_ */

/** @} */
