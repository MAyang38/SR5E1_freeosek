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
 * @file    eed_dev.c
 * @brief   EEPROM Emulation Driver device specific source file.
 *
 * @addtogroup DRIVERS
 * @addtogroup MEMORIES
 * @ingroup DRIVERS
 * @addtogroup EED
 * @ingroup MEMORIES
 * @{
 */

#include <eed.h>
#include <eed_private.h>
#include <flash.h>
#include <platform.h>

/*===========================================================================*/
/* Module local definitions.                                                 */
/*===========================================================================*/

/**
 * @name    Data Flash paramters
 * @{
 */
#define DFLASH_BLK_SIZE                     0x4000UL
#define DFLASH_BLK_START_ADDR(_blk_)        ((uint32_t)(0x8F00000UL + (DFLASH_BLK_SIZE * (_blk_))))
/** @} */

/**
 * @name    Unlock all data flash blocks mask
 * @{
 */
#define DFLASH_UNLOCK_ALL_BLOCKS            0xFFFFFFF0UL
/** @} */

/*===========================================================================*/
/* Module exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Module local types.                                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Module local variables.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Module local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Module exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Returns EED data flash block start address.
 *
 * @param[in] edp       pointer to a @p eed_driver_t structure
 * @param[in] blk       data flash block number for which returning the start
 *                      address
 * @return              data flash block start address.
 *
 * @notapi
 */
uint32_t eed_dev_get_start_addr(eed_driver_t *edp, uint8_t blk) {

    (void)edp;

    return (DFLASH_BLK_START_ADDR(blk));
}

/**
 * @brief   Returns EED data flash block size.
 *
 * @param[in] edp       pointer to a @p eed_driver_t structure
 * @param[in] blk       data flash block number for which returning the size
 * @return              data flash block size.
 *
 * @notapi
 */
uint32_t eed_dev_get_size(eed_driver_t *edp, uint8_t blk) {

    (void)edp;
    (void)blk;

    return (DFLASH_BLK_SIZE);
}

/**
 * @brief   Returns space related to an EED data flash block.
 *
 * @param[in] edp       pointer to a @p eed_driver_t structure
 * @param[in] blk       data flash block number for which returning the related
 *                      space
 * @return              space relate to data flash block.
 *
 * @notapi
 */
uint8_t eed_dev_get_space(eed_driver_t *edp, uint8_t blk) {

    (void)edp;
    (void)blk;

    return (C55_BLOCK_HIGH);
}

/**
 * @brief   Initializes flash driver.
 *
 * @return              initialization result ("true" means the initialization
 *                      has been correctly executed, "false" otherwise).
 *
 * @notapi
 */
bool eed_dev_flashinit(void) {

    flash_init();
    flash_start(&FLASHD0);

    return true;
}

/**
 * @brief   Unlocks data flash block.
 *
 * @param[in] block     block to be unlocked
 * @param[in] space     flash space (low, middle or high) related to the block
 *                      to be unlocked
 * @return              unlock result ("true" means the unlock has been
 *                      correctly executed, "false" otherwise).
 *
 * @notapi
 */
bool eed_dev_flashunlock(uint8_t block, uint8_t space) {

    uint32_t blkLockState = 0x00000000UL;

    (void)space;

    if (flash_getLock(&FLASHD0, C55_BLOCK_HIGH, &blkLockState) != ((uint32_t)C55_OK)) {
        return false;
    }

    blkLockState &= ~(1UL << block);

    if (flash_setLock(&FLASHD0, C55_BLOCK_HIGH, blkLockState) != ((uint32_t)C55_OK)) {
        return false;
    }

    return true;
}

/**
 * @brief   Erases data flash block.
 *
 * @param[in] block     block to be erased
 * @param[in] space     flash space (low, middle or high) related to the block
 *                      to be erased
 * @return              erase result ("true" means the erase has been correctly
 *                      executed, "false" otherwise).
 *
 * @notapi
 */
bool eed_dev_flasherase(uint8_t block, uint8_t space) {

    uint32_t lowBlockSelect;
    uint32_t midBlockSelect;
    uint32_t highBlockSelect;
    N256K_BLOCK_SEL n256KBlockSelect;
    uint32_t returnCode;

    (void)space;

    /* Select the block.*/
    lowBlockSelect = 0UL;
    midBlockSelect = 0UL;
    highBlockSelect = (1UL << block);
    n256KBlockSelect.first256KBlockSelect = 0UL;
    n256KBlockSelect.second256KBlockSelect = 0UL;

    /* Erase the block.*/
    returnCode = flash_flashErase(&FLASHD0, C55_ERASE_MAIN, lowBlockSelect, midBlockSelect, highBlockSelect, n256KBlockSelect);

    /* Check if an error occurred.*/
    if (((uint32_t)C55_OK) != returnCode) {
        return false;
    }

    return true;
}

/**
 * @brief   Programs 64bits into data flash.
 *
 * @param[in] address   address to be programmed
 * @param[in] buffer    data to be programmed
 * @return              program result ("true" means the program has been
 *                      correctly executed, "false" otherwise).
 *
 * @notapi
 */
bool eed_dev_flashprogram64(uint32_t address, uint64_t buffer) {

    uint32_t bufferptr;
    uint32_t returnCode;

    bufferptr = (uint32_t)(&buffer);
    (void)buffer;

    /* Program buffer.*/
    returnCode = flash_flashProgram(&FLASHD0, FALSE, address, 8U, bufferptr); 

    /* Check if an error occurred.*/
    if (((uint32_t)C55_OK) != returnCode) {
        return false;
    }

    return true;
}

/**
 * @brief   Blankcheck data flash block.
 *
 * @param[in] address   start address of the block to be checked
 * @param[in] size      size of the block to be checked
 * @return              blankcheck result ("true" means the blankcheck has been
 *                      correctly executed, "false" otherwise).
 *
 * @notapi
 */
bool eed_dev_flashblankcheck(uint32_t address, uint32_t size) {

    uint32_t failAddress;
    uint32_t failData;
    uint32_t returnCode;

    /* Blank check.*/
    returnCode = flash_blankCheck(&FLASHD0, address, size, &failAddress, &failData);

    /* Check if an error occurred.*/
    if (((uint32_t)C55_OK) != returnCode) {
        return false;
    }

    return true;
}

/** @} */
