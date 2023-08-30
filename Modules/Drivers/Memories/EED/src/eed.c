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
 * @file    eed.c
 * @brief   EEPROM Emulation Driver source file.
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

/*===========================================================================*/
/* Module local definitions.                                                 */
/*===========================================================================*/

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
/* Local function prototypes                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Module local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   Resets EED parameters.
 *
 * @param[out] edp      pointer to an @p eed_driver_t structure
 *
 * @notapi
 */
static void eed_reset_parameters(eed_driver_t *edp) {

    edp->cfg.blk_num               = 0U;
    edp->cfg.blk_cfg[0].start_addr = 0U;
    edp->cfg.blk_cfg[0].size       = 0U;
    edp->cfg.blk_cfg[0].space      = 0U;
    edp->cfg.blk_cfg[0].number     = 0U;
    edp->cfg.blk_cfg[1].start_addr = 0U;
    edp->cfg.blk_cfg[1].size       = 0U;
    edp->cfg.blk_cfg[1].space      = 0U;
    edp->cfg.blk_cfg[1].number     = 0U;
    edp->is_init                   = false;
    edp->act_blk                   = EED_NO_ACTIVE_BLOCK;
    edp->freespace                 = 0U;
}

/**
 * @brief   Searches an EEPROM Emulation Driver record.
 *
 * @param[in] edp       pointer to a @p eed_driver_t structure
 * @param[in] id        identifier of the record to be searched
 * @param[out] address  physical address in flash where the record is stored
 * @param[out] size     size of the record
 * @return              operation status: EED_OK if the record is found,
 *                      EED_ERROR_ID_NOT_FOUND otherwise.
 *
 * @notapi
 */
static uint32_t eed_search_id(eed_driver_t *edp, uint16_t id, uint32_t *address, uint16_t *size) {

    uint16_t idnum;
    uint32_t idsize;
    uint32_t actualsize;
    uint64_t idtype;
    uint32_t data;
    uint32_t blockaddress;
    uint32_t sizeaddress;

    /* Skip block metadata.*/
    blockaddress = edp->cfg.blk_cfg[edp->act_blk].start_addr + 16U;

    /* Scan active block searching for the record.*/
    while (blockaddress < edp->cfg.blk_cfg[edp->act_blk].start_addr + edp->cfg.blk_cfg[edp->act_blk].size) {

        idtype = FLASH_READ64(blockaddress);
        sizeaddress = blockaddress + 12UL;
        data = FLASH_READ32(sizeaddress);
        idnum = (uint16_t)(data >> 16);
        idsize = data & 0x0000FFFFUL;
        actualsize = EED_ROUND16(idsize);
        actualsize += 16U;

        if (idtype == EED_TAG_ID_WRITE_COMPLETE) {
            if (idnum == id) {
                *address = blockaddress;
                *size = (uint16_t)idsize;
                return EED_OK;
            } else {
                blockaddress = blockaddress + actualsize;
            }
        } else if (idtype == EED_TAG_ID_INVALID) {
            blockaddress = blockaddress + actualsize;
        } else {
            blockaddress += 16UL;
        }
    }

    return EED_ERROR_ID_NOT_FOUND;
}

/**
 * @brief   Swaps data from the active block into the spare block.
 * @note    The spare block, if needed, is deleted before the swap operation.
 *          During the swap procedure, all the valid records are copied from
 *          the active block into the spare block. When the copy of the valid
 *          records is completed, the active block is maked as invalid, while
 *          the spare block is marked as the new active block.
 *
 * @param[in] edp       pointer to a @p eed_driver_t structure
 * @return              operation status: EED_OK if the swap is correctly
 *                      executed is found, otherwise one of the following error
 *                      codes:
 *            @arg @ref EED_ERROR_FLASH_ERASE
 *            @arg @ref EED_ERROR_FLASH_PROGRAM
 *
 * @notapi
 */
static uint32_t eed_swap_block(eed_driver_t *edp) {

    uint8_t  block;
    bool     eraseblock;
    uint32_t address;
    uint32_t daddress;
    uint32_t idsize;
    uint32_t actualsize;
    uint64_t idtype;
    uint32_t data;
    uint32_t counter;
    uint32_t numcycles;
    uint64_t buffer;
    uint32_t i;
    uint32_t sizeaddress;
    uint32_t buffaddress;
    bool     flash_retval;

    /* Select spare block.*/
    block = (edp->act_blk + 1U) % (edp->cfg.blk_num);

    /* Check if spare block is blank, otherwise erase it.*/
    eraseblock = false;
    flash_retval = eed_dev_flashblankcheck(edp->cfg.blk_cfg[block].start_addr, edp->cfg.blk_cfg[block].size);
    if ((bool)flash_retval != true) {
        eraseblock = true;
    }
    if ((bool)eraseblock == true) {
        flash_retval = eed_dev_flasherase(edp->cfg.blk_cfg[block].number, edp->cfg.blk_cfg[block].space);
        if ((bool)flash_retval != true) {
            return EED_ERROR_FLASH_ERASE;
        }
    }

    /* Start swap operation.*/

    /* Write Block Swap Start tag into spare block.*/
    flash_retval = eed_dev_flashprogram64(edp->cfg.blk_cfg[block].start_addr, (uint64_t)EED_TAG_BLOCK_SWAP_START);
    if ((bool)flash_retval != true) {
        return EED_ERROR_FLASH_PROGRAM;
    }

    /* Search valid records and copy them into spare block.*/
    address = edp->cfg.blk_cfg[edp->act_blk].start_addr + 16UL;
    daddress = edp->cfg.blk_cfg[block].start_addr + 16UL;
    while (address < edp->cfg.blk_cfg[edp->act_blk].start_addr + edp->cfg.blk_cfg[edp->act_blk].size) {
        idtype = FLASH_READ64(address);
        sizeaddress = address + 12UL;
        data = FLASH_READ32(sizeaddress);
        idsize = data & 0x0000FFFFUL;
        actualsize = EED_ROUND16(idsize);
        actualsize += 16U;
        switch (idtype) {
        case EED_TAG_ID_WRITE_COMPLETE:
            //idnum = (uint16_t)(data >> 16);
            numcycles = actualsize / 8U;
            /* Move valid data to spare block.*/
            for (counter = 0; counter < numcycles; counter++) {
                buffer = 0xFFFFFFFFFFFFFFFFUL;
                for (i = 0; i < 8U; i++) {
                    // buffer |= (uint64_t)(*(uint8_t*)source++) << (i * 8);
                    buffaddress = ((uint32_t)(&buffer) + i);
                    EED_WRITE8(buffaddress, EED_READ8(address++));
                }
                flash_retval = eed_dev_flashprogram64(daddress, buffer);
                if ((bool)flash_retval != true) {
                    return EED_ERROR_FLASH_PROGRAM;
                }
                daddress = daddress + 8U;
            }
            break;
        case EED_TAG_ID_INVALID:
            address = address + actualsize;
            break;
        case EED_TAG_ID_BAD:
            address += 16UL;
            break;
        default:
            address += 16UL;
            break;
        }
    }

    /* Invalidate old block writing Old Block tag.*/
    flash_retval = eed_dev_flashprogram64(edp->cfg.blk_cfg[edp->act_blk].start_addr, (uint64_t)EED_TAG_BLOCK_INVALID);
    if ((bool)flash_retval != true) {
        return EED_ERROR_FLASH_PROGRAM;
    }

    /* Set spare block as active writing Block Active tag.*/
    flash_retval = eed_dev_flashprogram64(edp->cfg.blk_cfg[block].start_addr, (uint64_t)EED_TAG_BLOCK_ACTIVE);
    if ((bool)flash_retval != true) {
        return EED_ERROR_FLASH_PROGRAM;
    }

    /* Update new active block information.*/
    edp->act_blk = block;
    edp->freespace = edp->cfg.blk_cfg[edp->act_blk].size - (daddress - edp->cfg.blk_cfg[edp->act_blk].start_addr);

    return EED_OK;
}

/*===========================================================================*/
/* Module exported functions.                                                */
/*===========================================================================*/

void eed_init(eed_driver_t *edp) {

    /* Reset EED parameters.*/
    eed_reset_parameters(edp);
}

void eed_set_cfg(eed_driver_t *edp, uint8_t blk1, uint8_t blk2) {

    edp->cfg.blk_num               = 2U;

    edp->cfg.blk_cfg[0].start_addr = eed_dev_get_start_addr(edp, blk1);
    edp->cfg.blk_cfg[0].size       = eed_dev_get_size(edp, blk1);
    edp->cfg.blk_cfg[0].space      = eed_dev_get_space(edp, blk1);
    edp->cfg.blk_cfg[0].number     = blk1;

    edp->cfg.blk_cfg[1].start_addr = eed_dev_get_start_addr(edp, blk2);
    edp->cfg.blk_cfg[1].size       = eed_dev_get_size(edp, blk2);
    edp->cfg.blk_cfg[1].space      = eed_dev_get_space(edp, blk2);
    edp->cfg.blk_cfg[1].number     = blk2;
}

uint32_t eed_start(eed_driver_t *edp) {

    uint32_t returnvalue;
    uint8_t  counter;
    uint64_t blockstatus;
    uint64_t buffer;
    uint32_t address;
    uint32_t idsize;
    uint32_t actualsize;
    uint64_t idtype;
    uint32_t data;
    uint32_t blockaddress;
    uint32_t sizeaddress;
    bool     flash_retval;

    /* Flash initialization.*/
    flash_retval = eed_dev_flashinit();
    if ((bool)flash_retval != true) {
        return (EED_ERROR_FLASH_INIT);
    }

    for (counter = 0U; counter < edp->cfg.blk_num; counter++) {
        /* Unlock flash blocks used for EEPROM emulation.*/
        flash_retval = eed_dev_flashunlock(edp->cfg.blk_cfg[counter].number, edp->cfg.blk_cfg[counter].space);
        if ((bool)flash_retval != true) {
            return (EED_ERROR_FLASH_UNLOCK);
        }
        /* Check if an active block is available.*/
        blockstatus = FLASH_READ64(edp->cfg.blk_cfg[counter].start_addr);
        if (blockstatus == EED_TAG_BLOCK_ACTIVE) {
            edp->act_blk = counter;
        }
    }

    /* If no active block has been found..*/
    if (edp->act_blk == EED_NO_ACTIVE_BLOCK) {
        /* Delete all blocks used for the EEPROM emulation, then initialize the
           first one as active.*/
        for (counter = 0U; counter < edp->cfg.blk_num; counter++) {
            flash_retval = eed_dev_flasherase(edp->cfg.blk_cfg[counter].number, edp->cfg.blk_cfg[counter].space);
            if ((bool)flash_retval != true) {
                return EED_ERROR_FLASH_ERASE;
            }
        }
        /* Initialize the first block as active.*/
        address = edp->cfg.blk_cfg[0].start_addr;
        buffer = EED_TAG_BLOCK_ACTIVE;
        flash_retval = eed_dev_flashprogram64(address, buffer);
        if ((bool)flash_retval != true) {
            return EED_ERROR_FLASH_PROGRAM;
        }
        /* Update active block to the first one, then update the freespace.*/
        edp->act_blk = 0U;
        /* For a free block the free space is the block size - 16bytes
           (metadata, 8bytes are the block status + 8bytes TDB).*/
        edp->freespace = edp->cfg.blk_cfg[0].size - 16UL;
        returnvalue = EED_FIRST_INIT_OK;
    /*... otherwise (active block found), scan it.*/
    } else {
        //address = edp->cfg.blk_cfg[edp->act_blk].start_addr;
        edp->freespace = edp->cfg.blk_cfg[edp->act_blk].size - 16UL;
        /* Skip block metadata from the scan.*/
        blockaddress = edp->cfg.blk_cfg[edp->act_blk].start_addr + 16U;
        while (blockaddress < edp->cfg.blk_cfg[edp->act_blk].start_addr + edp->cfg.blk_cfg[edp->act_blk].size) {
            idtype = FLASH_READ64(blockaddress);
            sizeaddress = blockaddress + 12UL;
            data = FLASH_READ32(sizeaddress);
            idsize = data & 0x0000FFFFUL;
            actualsize = EED_ROUND16((uint16_t )idsize);
            actualsize += 16U;
            switch (idtype) {
            case EED_TAG_ID_WRITE_COMPLETE:
            case EED_TAG_ID_INVALID:
                edp->freespace -= actualsize;
                blockaddress = blockaddress + actualsize;
                break;
            /* If a power loss occurs during write operation, the record is set
               as BAD.*/
            case EED_TAG_ID_WRITE_START:
                flash_retval = eed_dev_flashprogram64(blockaddress, EED_TAG_ID_BAD);
                if ((bool)flash_retval != true) {
                    return EED_ERROR_FLASH_PROGRAM;
                }
                edp->freespace -= 16UL;
                blockaddress += 16UL;
                break;
            /* Freespace found.*/
            case 0xFFFFFFFFFFFFFFFFUL:
                blockaddress += 16UL;
                break;
            /* Remnants of interrupted write operations.*/
            default:
                edp->freespace -= 16UL;
                blockaddress += 16UL;
                break;
            }
        }
        returnvalue = EED_OK;
    }

    edp->is_init = true;
    return returnvalue;
}

uint32_t eed_write_id(eed_driver_t *edp, uint16_t id, uint16_t size, uint32_t source) {

    uint32_t actualsize;
    uint16_t idsize;
    uint64_t buffer;
    uint32_t buffaddress;
    uint8_t  counter;
    uint8_t  i;
    uint32_t address;
    uint32_t idaddress;
    uint32_t alignedbytes;
    uint32_t notalignedbytes;
    uint32_t nuomofcycles;
    uint32_t tempsource;
    bool     invalidateid;
    uint8_t  data;
    bool     flash_retval;

    /* If no active block is present or the active block is not initialized, an
       error is returned.*/
    if (edp->act_blk == EED_NO_ACTIVE_BLOCK || edp->is_init == false) {
       return EED_ERROR_NOT_INITIALIZED;
    }

    tempsource = source;

    /* Calculate the space needed for the write operation (16bytes are required
       for metadata + data is rounded to 16bytes).*/
    actualsize = (uint32_t)EED_ROUND16(size);
    actualsize += 16U;

    /* Check if there is enough space in the active block.*/
    if (edp->freespace < actualsize) {
        /* If not enough space is available, a swap operation is issued.*/
        if (eed_swap_block(edp) != EED_OK) {
            return EED_ERROR_SWAP;
        }
        /* Check if there is enough space after the swap, otherwise an error is
           returned.*/
        if (edp->freespace < actualsize) {
            return EED_ERROR_NO_SPACE;
        }
    }

    /* Check if the record is already present in flash. If so, it will be
       invalidated after the write operation.*/
    invalidateid = false;
    if (eed_search_id(edp, id, &idaddress, &idsize) == EED_OK) {
        invalidateid = true;
    }

    /* Now the following operations will be performed:
       1. program write start tag     (offset 0x00)
       2. program record ID and size  (offset 0x08)
       3. program record data         (offset 0x10)
       4. program write complete tag  (offset 0x00) */

    /* Program Write Start tag (offset 0x00).*/
    address = edp->cfg.blk_cfg[edp->act_blk].start_addr + edp->cfg.blk_cfg[edp->act_blk].size - edp->freespace;
    flash_retval = eed_dev_flashprogram64(address, EED_TAG_ID_WRITE_START);
    if ((bool)flash_retval != true) {
        return EED_ERROR_FLASH_PROGRAM;
    }

    /* Program record ID and size (offset 0x08).*/
    address += 8U;
    buffer = 0x00000000FFFFFFFFUL;
    buffer = buffer | ((uint64_t)id << 48);
    buffer = buffer | ((uint64_t)size << 32);
    flash_retval = eed_dev_flashprogram64(address, buffer);
    if ((bool)flash_retval != true) {
        return EED_ERROR_FLASH_PROGRAM;
    }

    /* Program record data (offset 0x10).*/
    alignedbytes = (((uint32_t)size) / 8U) * 8U;
    nuomofcycles = alignedbytes / 8U;
    notalignedbytes = ((uint32_t)size) % 8U;
    for (counter = 0; counter < nuomofcycles; counter++) {
        address += 8U;
        buffer = 0xFFFFFFFFFFFFFFFFUL;
        for (i = 0; i < 8U; i++) {
            // buffer |= (uint64_t)(*(uint8_t*)source++) << (i * 8);
            buffaddress = ((uint32_t)(&buffer) + (uint32_t)i);
            EED_WRITE8(buffaddress, EED_READ8(source++));
        }
        flash_retval = eed_dev_flashprogram64(address, buffer);
        if ((bool)flash_retval != true) {
            return EED_ERROR_FLASH_PROGRAM;
        }
    }
    if (notalignedbytes != 0UL) {
        /* Program not aligned 8bytes data.*/
        address += 8U;
        buffer = 0xFFFFFFFFFFFFFFFFUL;
        for (i = 0; i < notalignedbytes; i++) {
            buffaddress =  ((uint32_t)(&buffer) + (uint32_t)i);
            EED_WRITE8(buffaddress, EED_READ8(source++));
        }
        flash_retval = eed_dev_flashprogram64(address, buffer);
        if ((bool)flash_retval != true) {
            return EED_ERROR_FLASH_PROGRAM;
        }
    }
    /* Verify data.*/
    address = edp->cfg.blk_cfg[edp->act_blk].start_addr + edp->cfg.blk_cfg[edp->act_blk].size - edp->freespace;
    /* Skip metadata.*/
    address += 16U;
    for (counter = 0; counter < size; counter++) {
        /* Read data.*/
        data = FLASH_READ8(address);
        if (data != EED_READ8(tempsource)) {
            return EED_ERROR_FLASH_PROGRAM;
        }
        tempsource++;
        address++;
    }

    /* Program Write Complete tag (offset 0x00).*/
    address = edp->cfg.blk_cfg[edp->act_blk].start_addr + edp->cfg.blk_cfg[edp->act_blk].size - edp->freespace;
    flash_retval = eed_dev_flashprogram64(address, EED_TAG_ID_WRITE_COMPLETE);
    if ((bool)flash_retval != true) {
        return EED_ERROR_FLASH_PROGRAM;
    }

    /* If an old record with the same ID is present, invalidate it writing
       Invalid tag.*/
    if ((bool)invalidateid == true) {
        flash_retval = eed_dev_flashprogram64(idaddress, (uint64_t)EED_TAG_ID_INVALID);
        if ((bool)flash_retval != true) {
            return EED_ERROR_FLASH_PROGRAM;
        }
    }

    /* Update freespace size.*/
    edp->freespace -= actualsize;
    return EED_OK;
}

uint32_t eed_read_id(eed_driver_t *edp, uint16_t id, uint16_t *size, uint32_t source) {

    uint16_t idsize;
    uint16_t counter;
    uint32_t idaddress;
    uint32_t address;
    uint32_t buffaddress;

    /* If no active block is present or the active block is not initialized, an
       error is returned.*/
    if (edp->act_blk == EED_NO_ACTIVE_BLOCK || edp->is_init == false) {
        return EED_ERROR_NOT_INITIALIZED;
    }

    if (eed_search_id(edp, id, &idaddress, &idsize) != EED_OK) {
        return EED_ERROR_ID_NOT_FOUND;
    }

    address = idaddress + 16U;
    *size = idsize;
    for (counter = 0; counter < idsize; counter++) {
        buffaddress = (source + counter);
        EED_WRITE8(buffaddress, FLASH_READ8(address++));
    }

    return EED_OK;
}

uint32_t eed_delete_id(eed_driver_t *edp, uint16_t id) {

    uint32_t idaddress;
    uint16_t idsize;
    bool     flash_retval;

    /* If no active block is present or the active block is not initialized, an
       error is returned.*/
    if (edp->act_blk == EED_NO_ACTIVE_BLOCK || edp->is_init == false) {
      return EED_ERROR_NOT_INITIALIZED;
    }

    /* Check if record is present.*/
    if (eed_search_id(edp, id, &idaddress, &idsize) != EED_OK) {
        return EED_ERROR_ID_NOT_FOUND;
    }

    /* Invalidate record writing Invalid tag.*/
    flash_retval = eed_dev_flashprogram64(idaddress, (uint64_t)EED_TAG_ID_INVALID);
    if ((bool)flash_retval != true) {
        return EED_ERROR_FLASH_PROGRAM;
    }

    return EED_OK;
}

uint32_t eed_get_freespace(eed_driver_t *edp) {

    return edp->freespace;
}

uint32_t eed_remove(eed_driver_t *edp) {

    uint8_t  counter;
    bool     flash_retval;

    /* Check if EEPROM emultation driver is initialized.*/
    if (edp->is_init != true) {
        return EED_ERROR_NOT_INITIALIZED;
    }

    /* Delete all blocks used for EEPROM emulation.*/
    for (counter = 0; counter < edp->cfg.blk_num; counter++) {
        flash_retval = eed_dev_flasherase(edp->cfg.blk_cfg[counter].number, edp->cfg.blk_cfg[counter].space);
        if ((bool)flash_retval != true) {
            return EED_ERROR_FLASH_ERASE;
        }
    }

    /* Reset EED parameters.*/
    eed_reset_parameters(edp);

    return EED_OK;
}

/** @} */
