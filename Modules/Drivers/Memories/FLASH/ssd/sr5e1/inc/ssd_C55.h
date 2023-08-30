/****************************************************************************
 *
 * Copyright (c) 2015-2019 STMicroelectronics - All Rights Reserved
 *
 * License terms: STMicroelectronics Proprietary in accordance with licensing
 * terms SLA0098 at www.st.com.
 *
 * THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
 * INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *****************************************************************************/

/*************************************************************************
*                                                                       *
*               Standard Software Driver for C55                        *
*                                                                       *
* FILE NAME     :  ssd_c55.h                                            *
* DATE          :  February 04, 2022                                    *
* AUTHOR        :  ...                                                  *
* E-mail        :  ...                                                  *
*                                                                       *
*************************************************************************/

/******************************* CHANGES *********************************
  0.1.0   04.02.2022      G. Cuce     Initial Version
*************************************************************************/

#ifndef _SSD_C55_H_
#define _SSD_C55_H_

#include "ssd_types.h"


/*************************************************************************/
/*                  Offsets of C55 Control Registers                     */
/*************************************************************************/
#define C55_MCR             0x0000       /* Module Configuration Register */
#define C55_MCRA            0x0004       /* Alternate Module Configuration Register */
#define C55_MCRE            0x0008       /* Extended Module Configuration Register */
#define C55_LOCK0           0x0010       /* Lock 0 Register */
#define C55_LOCK1           0x0014       /* Lock 1 Register */
#define C55_LOCK2           0x0018       /* Lock 2 Register */
#define C55_LOCK3           0x001C       /* Lock 3 Register */
#define C55_LOCK0A          0x0028       /* Alternate Lock 0 Register */
#define C55_LOCK1A          0x002C       /* Alternate Lock 1 Register */
#define C55_SEL0            0x0038       /* Select 0 Register */
#define C55_SEL1            0x003C       /* Select 1 Register */
#define C55_SEL2            0x0040       /* Select 2 Register */
#define C55_SEL3            0x0044       /* Select 3 Register */
#define C55_ADR             0x0050       /* Address Register */
#define C55_UT0             0x0054       /* User Test 0 register */
#define C55_UM0             0x0058       /* User MISR 0 Register */
#define C55_UM1             0x005C       /* User MISR 1 Register */
#define C55_UM2             0x0060       /* User MISR 2 Register */
#define C55_UM3             0x0064       /* User MISR 3 Register */
#define C55_UM4             0x0068       /* User MISR 4 Register */
#define C55_UM5             0x006C       /* User MISR 5 Register */
#define C55_UM6             0x0070       /* User MISR 6 Register */
#define C55_UM7             0x0074       /* User MISR 7 Register */
#define C55_UM8             0x0078       /* User MISR 8 Register */
#define C55_UM9             0x007C       /* User MISR 9 Register */
#define C55_OPP0            0x0080       /* Over-Program Protection 0 Register */
#define C55_OPP1            0x0084       /* Over-Program Protection 1 Register */
#define C55_OPP2            0x0088       /* Over-Program Protection 2 Register */
#define C55_OPP3            0x008C       /* Over-Program Protection 3 Register */

/*************************************************************************/
/*              C55 Module Control Registers Field Definitions           */
/*************************************************************************/
/* Module Configuration Register */
#define C55_MCR_RVE         0x80000000   /* Read Voltage Error */
#define C55_MCR_RRE         0x40000000   /* Read Reference Error */
#define C55_MCR_AEE         0x20000000   /* Address Encode Error */
#define C55_MCR_EEE         0x10000000   /* ECC after ECC Error */
#define C55_MCR_EER         0x00008000   /* ECC Event Error */
#define C55_MCR_RWE         0x00004000   /* Read While Write Event Error */
#define C55_MCR_SBC         0x00002000   /* Single Bit Correction Error */
#define C55_MCR_PEAS        0x00000800   /* Program/Erase Access Space */
#define C55_MCR_DONE        0x00000400   /* State Machine Status */
#define C55_MCR_PEG         0x00000200   /* Program/Erase Good */
#define C55_MCR_PECIE       0x00000100   /* Program/Erase Complete Interrupt Enable */
#define C55_MCR_FERS        0x00000080   /* Factory Erase */
#define C55_MCR_PGM         0x00000010   /* Program */
#define C55_MCR_PSUS        0x00000008   /* Program Suspend */
#define C55_MCR_ERS         0x00000004   /* Erase */
#define C55_MCR_ESUS        0x00000002   /* Erase Suspend */
#define C55_MCR_EHV         0x00000001   /* Enable High Voltage */

/* User Test 0 Register */
#define C55_UT0_UTE         0x80000000
#define C55_UT0_SBCE        0x40000000
#define C55_UT0_NAIBP       0x00000200
#define C55_UT0_AIBPE       0x00000100
#define C55_UT0_AISUS       0x00000040
#define C55_UT0_MRE         0x00000020
#define C55_UT0_MRV         0x00000010
#define C55_UT0_AIS         0x00000004
#define C55_UT0_AIE         0x00000002
#define C55_UT0_AID         0x00000001

/*************************************************************************/
/*                   Return Codes for SSD functions                      */
/*************************************************************************/

#define C55_OK                      0x00000000
#define C55_ERROR_ALIGNMENT         0x00000001   /* Alignment error */
#define C55_ERROR_ENABLE            0x00000002   /* it's impossible to enable an operation */
#define C55_ERROR_BUSY              0x00000004   /* New program/erase cannot be preformed while previous high voltage operation in progress */
#define C55_ERROR_PGOOD             0x00000008   /* The program operation is unsuccessful */
#define C55_ERROR_EGOOD             0x00000010   /* The erase operation is unsuccessful */
#define C55_ERROR_NOT_BLANK         0x00000020   /* There is non-blank location in the checked flash memory */
#define C55_ERROR_VERIFY            0x00000040   /* There is a mismatch between the source data and content in the checked flash memory */
#define C55_ERROR_BLOCK_INDICATOR   0x00000080   /* Invalid block indicator */
#define C55_ERROR_ALTERNATE         0x00000100   /* The operation is unsupported via alternate interface */
#define C55_ERROR_FACTORY_OP        0x00000200   /* Factory erase/program cannot be performed */
#define C55_ERROR_MISMATCH          0x00000400   /* The MISR generated by the AIC hardware doesnot match the MISR passed by the user */
#define C55_ERROR_NO_BLOCK          0x00000800   /* No blocks have been enabled for Array Integrity check */
#define C55_ERROR_ADDR_SEQ          0x00001000   /* Invalid address sequence */
#define C55_ERROR_MARGIN_LEVEL      0x00002000   /* Invalid margin level */
#define C55_ERROR_ERASE_OPTION      0x00004000   /* Invalid erase option */
#define C55_ERROR_MODE_OP           0x00008000   /* Invalid mode op */

#define C55_DONE                    0x00010000   /* Done status */
#define C55_INPROGRESS              0x00020000   /* InProgress status */

/*************************************************************************/
/*            Predefined values for flags, options variables             */
/*************************************************************************/

/* Checking mode used in FlashCheckStatus */
#define C55_MODE_OP_PROGRAM         0x00
#define C55_MODE_OP_ERASE           0x01
#define C55_MODE_OP_PROGRAM_VERIFY  0x02
#define C55_MODE_OP_BLANK_CHECK     0x03
#define C55_MODE_OP_CHECK_SUM       0x04
#define C55_MODE_OP_USER_TEST_CHECK 0x05

/* Indicators for getting/setting block lock state */
#define C55_BLOCK_LOW               0x00   /* Block lock protection of low address space */
#define C55_BLOCK_MID               0x01   /* Block lock protection of mid address space */
#define C55_BLOCK_HIGH              0x02   /* Block lock protection of high address space */
#define C55_BLOCK_LARGE_FIRST       0x03   /* Block lock protection of first 32 blocks in 256K address space */
#define C55_BLOCK_LARGE_SECOND      0x04   /* Block lock protection of next 16 blocks in 256K address space */
#define C55_BLOCK_UTEST             0x05   /* Block lock protection of UTest address space */

/* Declarations for flash suspend operation */
#define C55_SUS_NOTHING             0x10   /* No program/erase operation */
#define C55_PGM_WRITE               0x11   /* A program sequence in interlock write stage. */
#define C55_ERS_WRITE               0x12   /* An erase sequence in interlock write stage. */
#define C55_ERS_SUS_PGM_WRITE       0x13   /* An erase-suspend program sequence in interlock write stage. */
#define C55_PGM_SUS                 0x14   /* The program operation is in suspend state */
#define C55_ERS_SUS                 0x15   /* The erase operation is in suspend state */
#define C55_ERS_SUS_PGM_SUS         0x16   /* The erase-suspended program operation is in suspend state */
#define C55_USER_TEST_SUS           0x17   /* The UTest check operation is in suspend state */

/* Declarations for flash resume operation */
#define C55_RES_NOTHING             0x20   /* No suspended program/erase operation */
#define C55_RES_PGM                 0x21   /* The program operation is resumed */
#define C55_RES_ERS                 0x22   /* The erase operation is resumed */
#define C55_RES_ERS_PGM             0x23   /* The erase-suspended program operation is resumed */
#define C55_RES_USER_TEST           0x24   /* The UTest check operation is resumed */

#define C55_USER_TEST_BREAK_SBC     0x30   /* The UTest check operation is broken by Single bit correction */
#define C55_USER_TEST_BREAK_DBD     0x31   /* The UTest check operation is broken by Double bit detection */

/* Declarations of margin levels */
#define C55_MARGIN_LEVEL_PROGRAM    0x00
#define C55_MARGIN_LEVEL_ERASE      0x01

/* Declarations of address sequences */
#define C55_ADDR_SEQ_PROPRIETARY    0x00
#define C55_ADDR_SEQ_LINEAR         0x01

/* Declarations of break options */
#define C55_BREAK_NONE              0x00   /* No break at all */
#define C55_BREAK_ON_DBD            0x01   /* Break on Double bit detection */
#define C55_BREAK_ON_DBD_SBC        0x02   /* Break on bot Double bit detection and Single bit correction */

/* Declarations of erase options */
#define C55_ERASE_MAIN              0x00   /* Perform normal erase on main array */
#define C55_ERASE_MAIN_FERS         0x01   /* Perform factory erase on main array */
#define C55_ERASE_UTEST             0x02   /* Perform erase on UTest array */
#define C55_ERASE_UTEST_FERS        0x03   /* Perform factory erase on UTest array */

/*************************************************************************/
/*                   Other Macros for SSD functions                      */
/*************************************************************************/

#define C55_WORD_SIZE               4      /* size of a word in byte */
#define C55_DWORD_SIZE              8      /* size of a double word in byte */

#define C55_USER_TEST_ENABLE_PASSWORD      0xF9F99999
#define C55_FACTORY_ERASE_DIARY_LOCATION   0x0020

#define NULL_POINTER                ((void *)0xFFFFFFFF)

/* Macros for Accessing the Registers */
#define C55_REG_BIT_SET(address, mask)        (*(VUINT32*)(address) |= (mask))
#define C55_REG_BIT_CLEAR(address, mask)      (*(VUINT32*)(address) &= ~(mask))
#define C55_REG_BIT_TEST(address, mask)       (*(VUINT32*)(address) & (mask))
#define C55_REG_WRITE(address, value)         (*(VUINT32*)(address) = (value))
#define C55_REG_READ(address)                 ((UINT32)(*(VUINT32*)(address)))
#define C55_GET_BIT(value, position)          (UINT8)(((value) >> (position)) & 0x01)

/* Set/Clear C55-MCR bits without affecting MCR-EER, MCR-RWE, and MCR-SBC */
#define C55_MCR_BIT_SET(MCRAddress, mask)      \
    C55_REG_WRITE(MCRAddress, ((mask | C55_REG_READ(MCRAddress)) & (~(C55_MCR_EER | C55_MCR_RWE | C55_MCR_SBC))))

#define C55_MCR_BIT_CLEAR(MCRAddress, mask)    \
    C55_REG_WRITE(MCRAddress, (((~mask) & C55_REG_READ(MCRAddress)) & (~(C55_MCR_EER | C55_MCR_RWE | C55_MCR_SBC))))

#define C55_MCR_EER_CLEAR(MCRAddress)    \
    C55_REG_WRITE(MCRAddress, (C55_REG_READ(MCRAddress) | C55_MCR_RWE | C55_MCR_SBC))
    
#define C55_MCR_RWE_CLEAR(MCRAddress)    \
    C55_REG_WRITE(MCRAddress, (C55_REG_READ(MCRAddress) | C55_MCR_EER | C55_MCR_SBC))
    
#define C55_MCR_SBC_CLEAR(MCRAddress)    \
    C55_REG_WRITE(MCRAddress, (C55_REG_READ(MCRAddress) | C55_MCR_EER | C55_MCR_RWE))
    
#define C55_MCR_EER_RWE_SBC_CLEAR(MCRAddress)    \
    C55_REG_WRITE(MCRAddress, (C55_REG_READ(MCRAddress) | C55_MCR_EER | C55_MCR_RWE | C55_MCR_SBC))



#define C55_MAIN_ARRAY_SIZE(pSSDConfig)    \
    ((((pSSDConfig->lowBlockInfo.n16KBlockNum + pSSDConfig->midBlockInfo.n16KBlockNum + \
    pSSDConfig->highBlockInfo.n16KBlockNum) << 4 /*16*/) + \
    ((pSSDConfig->lowBlockInfo.n32KBlockNum + pSSDConfig->midBlockInfo.n32KBlockNum + \
    pSSDConfig->highBlockInfo.n32KBlockNum) << 5 /*32*/) + \
    ((pSSDConfig->lowBlockInfo.n64KBlockNum + pSSDConfig->midBlockInfo.n64KBlockNum + \
    pSSDConfig->highBlockInfo.n64KBlockNum) << 6 /*64*/) + \
    ((pSSDConfig->lowBlockInfo.n128KBlockNum + pSSDConfig->midBlockInfo.n128KBlockNum + \
    pSSDConfig->highBlockInfo.n128KBlockNum) << 7 /*64*/) + \
    (pSSDConfig->nLargeBlockNum << 8)) << 10 /*1024*/)   



#define C55_LOW_BLOCK_NUM(pSSDConfig)     \
    (pSSDConfig->lowBlockInfo.n16KBlockNum + pSSDConfig->lowBlockInfo.n32KBlockNum +  \
    pSSDConfig->lowBlockInfo.n64KBlockNum + pSSDConfig->lowBlockInfo.n128KBlockNum)
    
#define C55_MID_BLOCK_NUM(pSSDConfig)     \
    (pSSDConfig->midBlockInfo.n16KBlockNum + pSSDConfig->midBlockInfo.n32KBlockNum +  \
    pSSDConfig->midBlockInfo.n64KBlockNum + pSSDConfig->midBlockInfo.n128KBlockNum)

#define C55_HIGH_BLOCK_NUM(pSSDConfig)     \
    (pSSDConfig->highBlockInfo.n16KBlockNum + pSSDConfig->highBlockInfo.n32KBlockNum +  \
    pSSDConfig->highBlockInfo.n64KBlockNum + pSSDConfig->highBlockInfo.n128KBlockNum)



/*************************************************************************/
/*                   SSD Configuration Structure                         */
/*************************************************************************/

/* Block information for an address space */

typedef struct _c55_block_info
{
    UINT32 n16KBlockNum;         /* Number of 16K blocks */
    UINT32 n32KBlockNum;         /* Number of 32K blocks */
    UINT32 n64KBlockNum;         /* Number of 64K blocks */
    UINT32 n128KBlockNum;        /* Number of 128K blocks */

} BLOCK_INFO, *PBLOCK_INFO;


/* SSD Configuration Structure */
typedef struct _c55_ssd_config
{
    UINT32 c55RegBase;           /* C55 control register base */
    UINT32 mainArrayBase;        /* base of main array */
    BLOCK_INFO lowBlockInfo;     /* blocks info of low address space */
    BLOCK_INFO midBlockInfo;     /* blocks info of mid address space */
    BLOCK_INFO highBlockInfo;    /* blocks info of high address space */
   
    UINT32 n256KBlockNum;        /* number of blocks in 256K address space */

    UINT32 uTestArrayBase;       /* base of UTEST array */
    BOOL mainInterfaceFlag;      /* interface flag indicate main or alternate interface */
    UINT32 programmableSize;     /* programmable size */
    BOOL BDMEnable;              /* debug mode selection */
} SSD_CONFIG, *PSSD_CONFIG;

/* MISR structure */
typedef struct _c55_misr
{
    UINT32 W0;
    UINT32 W1;
    UINT32 W2;
    UINT32 W3;
    UINT32 W4;
    UINT32 W5;
    UINT32 W6;
    UINT32 W7;
    UINT32 W8;
    UINT32 W9;
} MISR, *PMISR;

/* Structure data for the context values */
typedef struct _c55_context_data
{
    UINT32 dest;
    UINT32 size;
    UINT32 source;
    UINT32 *pFailedAddress;
    UINT32 *pFailedData;
    UINT32 *pFailedSource;
    UINT32 *pSum;
    PMISR pMisr;
    void* pReqCompletionFn;
} CONTEXT_DATA, *PCONTEXT_DATA;

/* Block select structure for Large address space */
typedef struct _c55_n256K_block_sel
{
    UINT32 first256KBlockSelect;
    UINT32 second256KBlockSelect;
} N256K_BLOCK_SEL, *PN256K_BLOCK_SEL;

/*************************************************************************/
/*                      Prototypes of wrapper SSD Functions              */
/*************************************************************************/

extern UINT32 FlashInit ( PSSD_CONFIG pSSDConfig );

extern UINT32 FlashErase ( PSSD_CONFIG pSSDConfig,
                    UINT8 eraseOption,
                    UINT32 lowBlockSelect,
                    UINT32 midBlockSelect,
                    UINT32 highBlockSelect,
                    N256K_BLOCK_SEL n256KBlockSelect
                    );
extern UINT32 BlankCheck ( PSSD_CONFIG pSSDConfig,
                    UINT32 dest,
                    UINT32 size,
                    UINT32 *pFailedAddress,
                    UINT32 *pFailedData,
                    PCONTEXT_DATA pCtxData
                    );
extern UINT32 FlashProgram ( PSSD_CONFIG pSSDConfig,
                    BOOL factoryPgmFlag,
                    UINT32 dest,
                    UINT32 size,
                    UINT32 source,
                    PCONTEXT_DATA pCtxData
                    );

extern UINT32 ProgramVerify ( PSSD_CONFIG pSSDConfig,
                    UINT32 dest,
                    UINT32 size,
                    UINT32 source,
                    UINT32 *pFailedAddress,
                    UINT32 *pFailedData,
                    UINT32 *pFailedSource,
                    PCONTEXT_DATA pCtxData
                    );

extern UINT32 FlashCheckStatus ( PSSD_CONFIG pSSDConfig,
                    UINT8 modeOp,
                    UINT32 *opResult,
                    PCONTEXT_DATA pCtxData
                    );

extern UINT32 GetLock ( PSSD_CONFIG pSSDConfig,
                    UINT8 blkLockIndicator,
                    UINT32 *blkLockState
                    );

extern UINT32 SetLock ( PSSD_CONFIG pSSDConfig,
                    UINT8 blkLockIndicator,
                    UINT32 blkLockState
                    );


/*************************************************************************/
/*                      SSD Function Pointer Types                       */
/*************************************************************************/

typedef UINT32 (*PFLASHINIT) ( PSSD_CONFIG pSSDConfig );

typedef UINT32 (*PFLASHERASE) ( PSSD_CONFIG pSSDConfig,
                    UINT8 eraseOption,
                    UINT32 lowBlockSelect,
                    UINT32 midBlockSelect,
                    UINT32 highBlockSelect,
                    N256K_BLOCK_SEL n256KBlockSelect
                    );
typedef UINT32 (*PBLANKCHECK) ( PSSD_CONFIG pSSDConfig,
                    UINT32 dest,
                    UINT32 size,
                    UINT32 *pFailedAddress,
                    UINT32 *pFailedData,
                    PCONTEXT_DATA pCtxData
                    );

typedef UINT32 (*PFLASHPROGRAM) ( PSSD_CONFIG pSSDConfig,
                    BOOL factoryPgmFlag,
                    UINT32 dest,
                    UINT32 size,
                    UINT32 source,
                    PCONTEXT_DATA pCtxData
                    );

typedef UINT32 (*PPROGRAMVERIFY) ( PSSD_CONFIG pSSDConfig,
                    UINT32 dest,
                    UINT32 size,
                    UINT32 source,
                    UINT32 *pFailedAddress,
                    UINT32 *pFailedData,
                    UINT32 *pFailedSource,
                    PCONTEXT_DATA pCtxData
                    );

typedef UINT32 (*PFLASHCHECKSTATUS) ( PSSD_CONFIG pSSDConfig,
                    UINT8 modeOp,
                    UINT32 *opResult,
                    PCONTEXT_DATA pCtxData
                    );

typedef UINT32 (*PGETLOCK) ( PSSD_CONFIG pSSDConfig,
                    UINT8 blkLockIndicator,
                    UINT32 *blkLockState
                    );

typedef UINT32 (*PSETLOCK) ( PSSD_CONFIG pSSDConfig,
                    UINT8 blkLockIndicator,
                    UINT32 blkLockState
                    );

#endif /* _SSD_C55_H_ */
