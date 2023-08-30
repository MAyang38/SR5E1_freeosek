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
 * @file    flash.c
 * @brief   FLASH driver.
 *
 * @addtogroup FLASH
 * @ingroup MEM
 * @{
 */

#include <typedefs.h>
#include <clock.h>
#include <platform.h>

#include <flash.h>

/*===========================================================================*/
/* External objects                                                          */
/*===========================================================================*/

// Assign function pointer

#ifdef _SSD_SRC_RELEASE_LIB_
PFLASHINIT             pFlashInit             = (PFLASHINIT)FlashInit;
PSETLOCK               pSetLock               = (PSETLOCK)SetLock;
PGETLOCK               pGetLock               = (PGETLOCK)GetLock;
PFLASHPROGRAM          pFlashProgram          = (PFLASHPROGRAM)FlashProgram;
PFLASHCHECKSTATUS      pFlashCheckStatus      = (PFLASHCHECKSTATUS)FlashCheckStatus;
PPROGRAMVERIFY         pProgramVerify         = (PPROGRAMVERIFY)ProgramVerify;
PFLASHERASE            pFlashErase            = (PFLASHERASE)FlashErase;
PBLANKCHECK            pBlankCheck            = (PBLANKCHECK)BlankCheck;
#endif


#ifdef _SSD_SRC_RELEASE_CARRAY_
extern const unsigned int FlashInit_C[];
extern const unsigned int SetLock_C[];
extern const unsigned int GetLock_C[];
extern const unsigned int FlashProgram_C[];
extern const unsigned int ProgramVerify_C[];
extern const unsigned int FlashCheckStatus_C[];
extern const unsigned int FlashErase_C[];
extern const unsigned int BlankCheck_C[];

PFLASHINIT pFlashInit = (PFLASHINIT)FlashInit_C;
PSETLOCK pSetLock = (PSETLOCK)SetLock_C;
PGETLOCK pGetLock = (PGETLOCK)GetLock_C;
PFLASHPROGRAM pFlashProgram = (PFLASHPROGRAM)FlashProgram_C;
PPROGRAMVERIFY pProgramVerify = (PPROGRAMVERIFY)ProgramVerify_C;
PFLASHCHECKSTATUS pFlashCheckStatus = (PFLASHCHECKSTATUS)FlashCheckStatus_C;
PFLASHERASE pFlashErase = (PFLASHERASE)FlashErase_C;
PBLANKCHECK pBlankCheck = (PBLANKCHECK)BlankCheck_C;
#endif



/*===========================================================================*/
/* Global variables                                                          */
/*===========================================================================*/

/*===========================================================================*/
/* Constants and macros                                                      */
/*===========================================================================*/

#define UNUSED(x) (void)(x)

// Main array base 
#define MAIN_ARRAY_BASE 0x18000000  // interlock performed always in B0F0_START_ADDR

#define NVM_DRV_PROG_DEFAULT_SIZE     0x80  /* 128b -> max programmable size */

#define NVM_DRV_MAIN_INTERFACE_SEL    0x1   /* Main interface selection */
#define NVM_DRV_ALT_INTERFACE_SEL     0x0   /* Alternate interface selection */


/*===========================================================================*/
/* Local types                                                               */
/*===========================================================================*/

/** @brief   Structure representing a FLASH driver. */
struct FLASHDriver {
    SSD_CONFIG ssdConfig;       /**< ssdConfig structure. */

    CONTEXT_DATA pgmCtxData;
    CONTEXT_DATA pvCtxData;
    CONTEXT_DATA dummyCtxData;
    CONTEXT_DATA bcCtxData;

    /* Callbacks */
    flash_callback_t    callback[FLASH_CALLBACK_MAX];  /**< Callback pointers */
};


/*===========================================================================*/
/* Local function prototypes                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Local variables                                                           */
/*===========================================================================*/

/** @cond */
/* FLASH driver instance CTRL1. */
FLASHDriver FLASHD0;


/*===========================================================================*/
/* Local functions.                                                          */
/*===========================================================================*/

/**
 * @brief   Low level initialization function
 * @notapi
 * @par Description
 *
 * @details
 *
 * @param flashd  pointer to the @p FLASHDriver object
 * @param nvmRegBase  NVM control register base
 * @param nvmMainArrayBase  base address of main array
 * @param mainInterfaceFlag  interface flag indicate main or alternate interface
 *
 * @sa flash_init
 */
static void flash_dev_init(FLASHDriver *flashd, unsigned long nvmRegBase, uint32_t nvmMainArrayBase, unsigned char mainInterfaceFlag )
{
    uint32_t i;

    flashd->ssdConfig.c55RegBase        = nvmRegBase;
    flashd->ssdConfig.mainArrayBase     = nvmMainArrayBase;
    flashd->ssdConfig.programmableSize  = NVM_DRV_PROG_DEFAULT_SIZE;
    flashd->ssdConfig.mainInterfaceFlag = mainInterfaceFlag;    
    flashd->ssdConfig.BDMEnable         = 0;

    pFlashInit(&flashd->ssdConfig);

    /* set up function pointers in context data */
    flashd->pgmCtxData.pReqCompletionFn = pFlashProgram;
    flashd->pvCtxData.pReqCompletionFn  = pProgramVerify;
    flashd->bcCtxData.pReqCompletionFn  = pBlankCheck;

    /* Init Callbacks */
    for (i = 0U; i < (uint32_t)FLASH_CALLBACK_MAX; i++) {
        flashd->callback[i] = NULL;
    }
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/


/*===========================================================================*/
/* Global functions.                                                         */
/*===========================================================================*/

/**
 * @brief   Initialize FLASH driver instances
 * @init
 * @par Description
 * @details
 *
 * @note 
 *
 * @param
 *
 * @sa flash_dev_init
 */
void flash_init(void)
{
    flash_dev_init(&FLASHD0, FLASH_REG_ITF_BASE, MAIN_ARRAY_BASE, NVM_DRV_MAIN_INTERFACE_SEL);
}


/**
 * @brief    Starts FLASH driver instances
 * @api
 * @par Description
 * @details  Starts the specified FLASH driver instance.
 *
 * @note 
 *
 * @param      flashd      pointer to the @p FLASHDriver object
 *
 * @sa flash_stop
 *
 */
void flash_start(FLASHDriver *flashd)
{
    UNUSED(flashd);
}


/**
 * @brief    Stops FLASH driver instances
 * @api
 * @par Description
 * @details  Stops the specified FLASH driver instance.
 *
 * @note 
 *
 * @param      flashd      pointer to the @p FLASHDriver object
 *
 * @sa flash_start
 *
 */
void flash_stop(FLASHDriver *flashd)
{
    UNUSED(flashd);
}


/**
 * @brief    Gets LOW Blocks info
 * @api
 * @par Description
 * @details  Gets the number of LOW blocks for the specified FLASH driver instance.
 *
 * @note     Returns 0 block for invalid Block indicator  
 *
 * @param      flashd            pointer to the @p FLASHDriver object
 * @param      blkIndicator      Block indicator in the LOW space address for the @p FLASHDriver object
 *
 * @return     Number of blocks in the LOW space address.
 * 
 * @sa
 *
 */
unsigned long flash_getLOWBlockInfo(FLASHDriver *flashd, flash_block_ind_t blkIndicator)   
{
    unsigned long nNumber = 0;

    switch (blkIndicator) 
    {
        case FLASH_BLOCK_16K:
            nNumber = flashd->ssdConfig.lowBlockInfo.n16KBlockNum;
            break;
        case FLASH_BLOCK_32K:
            nNumber = flashd->ssdConfig.lowBlockInfo.n32KBlockNum;
            break;
        case FLASH_BLOCK_64K:
            nNumber = flashd->ssdConfig.lowBlockInfo.n64KBlockNum;
            break;
        case FLASH_BLOCK_128K:
            nNumber = flashd->ssdConfig.lowBlockInfo.n128KBlockNum;
            break;
        default:
            break;
    }
    return nNumber;
}


/**
 * @brief    Gets MID Blocks info
 * @api
 * @par Description
 * @details  Gets the number of MID blocks for the specified FLASH driver instance.
 *
 * @note     Returns 0 block for invalid Block indicator 
 *
 * @param      flashd            pointer to the @p FLASHDriver object
 * @param      blkIndicator      Block indicator in the MID space address for the @p FLASHDriver object
 *
 * @return     Number of blocks in the MID space address.
 * 
 * @sa
 *
 */
unsigned long flash_getMIDBlockInfo(FLASHDriver *flashd, flash_block_ind_t blkIndicator)   
{
    unsigned long nNumber = 0;

    switch (blkIndicator) 
    {
        case FLASH_BLOCK_16K:
            nNumber = flashd->ssdConfig.midBlockInfo.n16KBlockNum;
            break;
        case FLASH_BLOCK_32K:
            nNumber = flashd->ssdConfig.midBlockInfo.n32KBlockNum;
            break;
        case FLASH_BLOCK_64K:
            nNumber = flashd->ssdConfig.midBlockInfo.n64KBlockNum;
            break;
        case FLASH_BLOCK_128K:
            nNumber = flashd->ssdConfig.midBlockInfo.n128KBlockNum;
            break;
        default:
            break;
    }
    return nNumber;
}


/**
 * @brief    Gets HIGH Blocks info
 * @api
 * @par Description
 * @details  Gets the number of HIGH blocks for the specified FLASH driver instance.
 *
 * @note     Returns 0 block for invalid Block indicator 
 *
 * @param      flashd            pointer to the @p FLASHDriver object
 * @param      blkIndicator      Block indicator in the HIGH space address for the @p FLASHDriver object
 *
 * @return     Number of blocks in the HIGH space address.
 * 
 * @sa
 *
 */
unsigned long flash_getHIGHBlockInfo(FLASHDriver *flashd, flash_block_ind_t blkIndicator)   
{
    unsigned long nNumber = 0;

    switch (blkIndicator) 
    {
        case FLASH_BLOCK_16K:
            nNumber = flashd->ssdConfig.highBlockInfo.n16KBlockNum;
            break;
        case FLASH_BLOCK_32K:
            nNumber = flashd->ssdConfig.highBlockInfo.n32KBlockNum;
            break;
        case FLASH_BLOCK_64K:
            nNumber = flashd->ssdConfig.highBlockInfo.n64KBlockNum;
            break;
        case FLASH_BLOCK_128K:
            nNumber = flashd->ssdConfig.highBlockInfo.n128KBlockNum;
            break;
        default:
            break;
    }
    return nNumber;
}


/**
 * @brief    Gets 256K Blocks info
 * @api
 * @par Description
 * @details  Gets the number of 256K blocks for the specified FLASH driver instance.
 *
* @note     Returns 0 block for invalid Block indicator 
 *
 * @param      flashd            pointer to the @p FLASHDriver object
 *
 * @return     Number of blocks in the 256 space address.
 * 
 * @sa
 *
 */
unsigned long flash_get256KBlockInfo(FLASHDriver *flashd)   
{
    return flashd->ssdConfig.n256KBlockNum;
}


/**
 * @brief    Gets programmableSize
 * @api
 * @par Description
 * @details  Gets the programmable size selected for the specified FLASH driver instance.
 *
 * @note 
 *
 * @param      flashd              pointer to the @p FLASHDriver object
 *
 * @return     Programmable size.
 * 
 * @sa
 *
 */
unsigned long flash_getProgrammableSize(FLASHDriver *flashd)   
{
    unsigned long nProgrammableSize = 0;

    nProgrammableSize = flashd->ssdConfig.programmableSize;

    return nProgrammableSize;
}


/**
 * @brief    Sets programmableSize
 * @api
 * @par Description
 * @details  Sets the programmable size selected for the specified FLASH driver instance.
 *
 * @note 
 *
 * @param      flashd            pointer to the @p FLASHDriver object
 * @param      programmableSize  programmable size for the @p FLASHDriver object
 *
 * @sa
 *
 */
void flash_setProgrammableSize(FLASHDriver *flashd, unsigned long programmableSize)   
{
    flashd->ssdConfig.programmableSize = programmableSize;
}


/**
 * @brief   Sets FLASH PROGRAM/PROGRAM_VERIFY callback
 * @api
 *
 * @par Description
 * @details Sets the FLASH callback to be called on program or program_verify operation to check the in progress status
 *
 * @note 
 *
 * @param     flashd    pointer to the @p FLASHDriver object
 * @param     cb_type   callback type (FLASH_CALLBACK_MODE_OP_PROGRAM/FLASH_CALLBACK_MODE_OP_PROGRAM_VERIFY).
 * @param     callback  callback pointer.
 *
 * @return    previous callback pointer.
 *
 * @sa 
 */
flash_callback_t flash_set_callback(FLASHDriver *flashd, flash_cb_type_t cb_type, flash_callback_t callback)
{
    flash_callback_t prev_cb;

    prev_cb = flashd->callback[cb_type];
    flashd->callback[cb_type] = callback;

    return prev_cb;
}


/**
 * @brief    Sets lock
 * @api
 * @par Description
 * @details  Sets the block lock state Low/Middle/High/256K/UTest address space on the
 *           FLASH module to protect them from program.
 *
 * @note 
 *
 * @param      flashd            pointer to the @p FLASHDriver object
 * @param      blkLockIndicator  block lock indicator value for the @p FLASHDriver object
 * @param      blkLockState      block lock state value for the @p FLASHDriver object
 *
 * @return     C55_OK                      Success
 * @return     C55_ERROR_ALTERNATE         The operation is unsupported via alternate interface
 * @return     C55_ERROR_BLOCK_INDICATOR   Invalid block indicator
 * 
 * @sa
 *
 */
unsigned long flash_setLock(FLASHDriver *flashd, unsigned char blkLockIndicator, unsigned long blkLockState)  
{
    unsigned long returnCode = C55_OK;

    returnCode = pSetLock(&flashd->ssdConfig, blkLockIndicator, blkLockState);

    return returnCode;
}


/**
 * @brief    Gets lock
 * @api
 * @par Description
 * @details  Checks the block locking status of Low/Middle/High/256K/UTest address space in the
 *           FLASH module.
 *
 * @note 
 *
 * @param      flashd            pointer to the @p FLASHDriver object
 * @param      blkLockIndicator  block lock indicator value for the @p FLASHDriver object
 * @param      blkLockState      block lock state value for the @p FLASHDriver object
 *
 * @return     C55_OK                      Success
 * @return     C55_ERROR_ALTERNATE         The operation is unsupported via alternate interface
 * @return     C55_ERROR_BLOCK_INDICATOR   Invalid block indicator
 * 
 * @sa
 *
 */
unsigned long flash_getLock(FLASHDriver *flashd, unsigned char blkLockIndicator, unsigned long *blkLockState)  
{
    unsigned long returnCode = C55_OK;

    returnCode = pGetLock(&flashd->ssdConfig, blkLockIndicator, blkLockState);

    return returnCode;
}



/**
 * @brief    Program FLASH
 * @api
 * @par Description
 * @details  This function will program user data to specified FLASH range
 *
 * @note 
 *
 * @param      flashd                      pointer to the @p FLASHDriver object
 * @param      factoryPgmFlag              flag to enable/disable faster write operation (factory program or not)
 * @param      dest                        destination address to be programmed in FLASH memory       
 * @param      size                        size, in bytes, of the FLASH region to be programmed 
 * @param      source                      source program buffer address 
 *
 * @return     C55_OK                      Success
 * @return     C55_ERROR_ALTERNATE         The operation is unsupported via alternate interface
 * @return     C55_ERROR_ALIGNMENT         Alignment error
 * @return     C55_ERROR_BUSY              New program cannot be preformed while previous high voltage operation in progress
 * @return     C55_ERROR_ENABLE            It's impossible to enable this operation
 * @return     C55_ERROR_FACTORY_OP        Factory program cannot be performed
 * @return     C55_ERROR_PGOOD             The program operation is unsuccessful
 *
 * @sa
 *
 */
unsigned long flash_flashProgram(FLASHDriver *flashd, unsigned char factoryPgmFlag, unsigned long dest, unsigned long size, unsigned long source)
{
    unsigned long returnCode = C55_OK;
    unsigned long res = C55_INPROGRESS;
    unsigned long opResult;

    returnCode = pFlashProgram(&flashd->ssdConfig, factoryPgmFlag, dest, size, source, &flashd->pgmCtxData);

    if (C55_OK == returnCode)
    {
        // Call FlashCheckStatus() to check status of the progress 
        while (C55_INPROGRESS == res)
        {
            res = pFlashCheckStatus(&flashd->ssdConfig, C55_MODE_OP_PROGRAM, &opResult, &flashd->pgmCtxData);
            // Using callback to add user code here to take actions
            /* Call the related callback.*/
            if (flashd->callback[FLASH_CALLBACK_MODE_OP_PROGRAM] != NULL){
                flashd->callback[FLASH_CALLBACK_MODE_OP_PROGRAM](flashd, res);
            }
        }

        if (C55_OK != opResult)
        {
           return opResult;
        }
    }
    else{
        return returnCode;
    }

    return returnCode;
}



/**
 * @brief    Program verify FLASH
 * @api
 * @par Description
 * @details  This function will verify programmed data in specified FLASH range.
 *
 * @note 
 *
 * @param      flashd          pointer to the @p FLASHDriver object
 * @param      dest            destination address to be verified in FLASH memory                                          
 * @param      size            size, in bytes, of the FLASH region to be verified                
 * @param      source          verify source buffer address 
 * @param      pFailedAddress  return first failing address in FLASH 
 * @param      pFailedData     returns first mismatch data in FLASH
 * @param      pFailedSource   returns first mismatch data in buffer 
 *
 * @return     C55_OK                      Success
 * @return     C55_ERROR_ALIGNMENT         Alignment error
 * @return     C55_ERROR_VERIFY            There is a mismatch between the source data and content in the checked flash memory
 *
 * @sa
 *
 */
unsigned long flash_programVerify(FLASHDriver *flashd, unsigned long dest, unsigned long size, unsigned long source, unsigned long *pFailedAddress, unsigned long *pFailedData, unsigned long *pFailedSource)
{
    unsigned long returnCode = C55_OK;
    unsigned long res = C55_INPROGRESS;
    unsigned long opResult;

    returnCode = pProgramVerify(&flashd->ssdConfig, dest, size, source, pFailedAddress, pFailedData, pFailedSource, &flashd->pvCtxData);

    if (C55_OK == returnCode)
    {
        // Call FlashCheckStatus() to check status of the progress
        while (C55_INPROGRESS == res)
        {
            res = pFlashCheckStatus(&flashd->ssdConfig, C55_MODE_OP_PROGRAM_VERIFY, &opResult, &flashd->pvCtxData);
            // Using callback to add user code here to check the in progress status
            /* Call the related callback.*/
            if (flashd->callback[FLASH_CALLBACK_MODE_OP_PROGRAM_VERIFY] != NULL){
                flashd->callback[FLASH_CALLBACK_MODE_OP_PROGRAM_VERIFY](flashd, res);
            }
        }

        if (C55_OK != opResult)
        {
           return opResult;
        }
    }
    else{
        return returnCode;
    }

    return returnCode;
}


/**
 * @brief    Erase FLASH
 * @api
 * @par Description
 * @details  This function will erase user data from specified FLASH blocks
 *
 * @note 
 *
 * @param      flashd             pointer to the @p FLASHDriver object
 * @param      eraseOption        erase option
 * @param      lowEnabledBlocks   selected Low Address Space block(s)
 * @param      midEnabledBlocks   selected Mid Address Space block(s)
 * @param      highEnabledBlocks  selected High Address Space block(s) 
 * @param      n256KEnabledBlocks selected 256K Address Space block(s) 
 *
 * @return     C55_OK                      Success
 * @return     C55_ERROR_BUSY              New erase cannot be preformed while previous high voltage operation in progress
 * @return     C55_ERROR_ERASE_OPTION      Invalid erase option
 * @return     C55_ERROR_FACTORY_OP        Could not perform factory erase
 * @return     C55_ERROR_EGOOD             The erase operation is unsuccessful
 *
 * @sa
 *
 */
unsigned long flash_flashErase(FLASHDriver *flashd, unsigned char eraseOption, unsigned long lowBlockSelect, unsigned long midBlockSelect, unsigned long highBlockSelect, N256K_BLOCK_SEL n256KBlockSelect)
{
    unsigned long returnCode = C55_OK;
    unsigned long res = C55_INPROGRESS;
    unsigned long opResult;

    returnCode = pFlashErase(&flashd->ssdConfig, eraseOption, lowBlockSelect, midBlockSelect, highBlockSelect, n256KBlockSelect);

    if (C55_OK == returnCode)
    {
        // Call FlashCheckStatus() to check status of the progress
        while (C55_INPROGRESS == res)
        {
            res = pFlashCheckStatus(&flashd->ssdConfig, C55_MODE_OP_ERASE, &opResult, &flashd->dummyCtxData);
            // Using callback to add user code here to check the in progress status
            /* Call the related callback.*/
            if (flashd->callback[FLASH_CALLBACK_MODE_OP_ERASE] != NULL){
                flashd->callback[FLASH_CALLBACK_MODE_OP_ERASE](flashd, res);
            }
        }

        if (C55_OK != opResult)
        {
           return opResult;
        }
    }
    else{
        return returnCode;
    }

    return returnCode;
}


/**
 * @brief    Blank Check
 * @api
 * @par Description
 * @details  This function will check whether block has been erased
 *
 * @note 
 *
 * @param      flashd               pointer to the @p FLASHDriver object
 * @param      dest                 start flash addr to be checked
 * @param      size                 number of bytes to be checked
 * @param      pFailedAddress       pointer to first failing address
 * @param      pFailedData          pointer to first failing actual data
 *
 * @return     C55_OK                      Success
 * @return     C55_ERROR_NOT_BLANK         Address is not erased
 * @return     C55_ERROR_ALIGNMENT         Invalid alignment 
 *
 * @sa
 *
 */
unsigned long flash_blankCheck(FLASHDriver *flashd, unsigned long dest, unsigned long size, unsigned long *pFailedAddress, unsigned long *pFailedData)
{
    unsigned long returnCode = C55_OK;
    unsigned long res = C55_INPROGRESS;
    unsigned long opResult;

    returnCode = pBlankCheck(&flashd->ssdConfig, dest, size, pFailedAddress, pFailedData, &flashd->bcCtxData);

    if (C55_OK == returnCode)
    {
        // Call FlashCheckStatus() to check status of the progress
        while (C55_INPROGRESS == res)
        {
            res = pFlashCheckStatus(&flashd->ssdConfig, C55_MODE_OP_BLANK_CHECK, &opResult, &flashd->bcCtxData);
            // Using callback to add user code here to check the in progress status
            /* Call the related callback.*/
            if (flashd->callback[FLASH_CALLBACK_MODE_OP_BLANK_CHECK] != NULL){
                flashd->callback[FLASH_CALLBACK_MODE_OP_BLANK_CHECK](flashd, res);
            }
        }

        if (C55_OK != opResult)
        {
           return opResult;
        }
    }
    else{
        return returnCode;
    }

    return returnCode;
}

/** @} */
