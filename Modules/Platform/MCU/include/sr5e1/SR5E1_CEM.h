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

#ifndef __SR5E1_CEM_H
#define __SR5E1_CEM_H


/******************************************************************************/
/*                                                                            */
/*                                 CEM (CEM)                                  */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO uint32_t CMD;             /*!< Command register                                   Address offset: 0x00 */
  __IO uint32_t RDATA;           /*!< Read data register                                 Address offset: 0x04 */
  __IO uint32_t WDATA;           /*!< Write data register                                Address offset: 0x08 */
        uint8_t RESERVED0[4];    /*!< Reserved                                           Address offset: 0x0C-0x0F */
  __IO uint32_t WMASK;           /*!< Write mask register                                Address offset: 0x10 */
  __I  uint32_t CMD_STATUS;      /*!< Command status register                            Address offset: 0x14 */
        uint8_t RESERVED1[12];   /*!< Reserved                                           Address offset: 0x18-0x23 */
  __IO uint32_t SUPERKEY;        /*!< Super key register                                 Address offset: 0x24 */
        uint8_t RESERVED2[8];    /*!< Reserved                                           Address offset: 0x28-0x2F */
  __I  uint32_t HW_CFG;          /*!< Hardware configuration register                    Address offset: 0x30 */
  __I  uint32_t VERSION;         /*!< Version register                                   Address offset: 0x34 */
} CEM_TypeDef;





/*******************  Bit definition for CEM_CMD register  ********************/

#define CEM_CMD_FAULT_OR_GRP_NUM_Pos          (0U)
#define CEM_CMD_FAULT_OR_GRP_NUM_Msk          (0x7FFUL << CEM_CMD_FAULT_OR_GRP_NUM_Pos) /*!< 0x000007FF */
#define CEM_CMD_FAULT_OR_GRP_NUM              CEM_CMD_FAULT_OR_GRP_NUM_Msk
#define CEM_CMD_CMD_Pos                       (11U)
#define CEM_CMD_CMD_Msk                       (0x1FUL << CEM_CMD_CMD_Pos) /*!< 0x0000F800 */
#define CEM_CMD_CMD                           CEM_CMD_CMD_Msk
#define CEM_CMD_KEY_Pos                       (16U)
#define CEM_CMD_KEY_Msk                       (0xFFFFUL << CEM_CMD_KEY_Pos) /*!< 0xFFFF0000 */
#define CEM_CMD_KEY                           CEM_CMD_KEY_Msk

/******************  Bit definition for CEM_RDATA register  *******************/

#define CEM_RDATA_READ_DATA_Pos               (0U)
#define CEM_RDATA_READ_DATA_Msk               (0xFFFFFFFFUL << CEM_RDATA_READ_DATA_Pos) /*!< 0xFFFFFFFF */
#define CEM_RDATA_READ_DATA                   CEM_RDATA_READ_DATA_Msk

/******************  Bit definition for CEM_WDATA register  *******************/

#define CEM_WDATA_WRITE_DATA_Pos              (0U)
#define CEM_WDATA_WRITE_DATA_Msk              (0xFFFFFFFFUL << CEM_WDATA_WRITE_DATA_Pos) /*!< 0xFFFFFFFF */
#define CEM_WDATA_WRITE_DATA                  CEM_WDATA_WRITE_DATA_Msk

/******************  Bit definition for CEM_WMASK register  *******************/

#define CEM_WMASK_MASK_Pos                    (0U)
#define CEM_WMASK_MASK_Msk                    (0xFFFFFFFFUL << CEM_WMASK_MASK_Pos) /*!< 0xFFFFFFFF */
#define CEM_WMASK_MASK                        CEM_WMASK_MASK_Msk

/****************  Bit definition for CEM_CMD_STATUS register  ****************/

#define CEM_CMD_STATUS_INV_REG_Pos            (0U)
#define CEM_CMD_STATUS_INV_REG_Msk            (0x1UL << CEM_CMD_STATUS_INV_REG_Pos) /*!< 0x00000001 */
#define CEM_CMD_STATUS_INV_REG                CEM_CMD_STATUS_INV_REG_Msk
#define CEM_CMD_STATUS_INV_KEY_Pos            (1U)
#define CEM_CMD_STATUS_INV_KEY_Msk            (0x1UL << CEM_CMD_STATUS_INV_KEY_Pos) /*!< 0x00000002 */
#define CEM_CMD_STATUS_INV_KEY                CEM_CMD_STATUS_INV_KEY_Msk
#define CEM_CMD_STATUS_INV_CMD_Pos            (2U)
#define CEM_CMD_STATUS_INV_CMD_Msk            (0x1UL << CEM_CMD_STATUS_INV_CMD_Pos) /*!< 0x00000004 */
#define CEM_CMD_STATUS_INV_CMD                CEM_CMD_STATUS_INV_CMD_Msk

/*****************  Bit definition for CEM_SUPERKEY register  *****************/

#define CEM_SUPERKEY_SUPERKEY_Pos             (0U)
#define CEM_SUPERKEY_SUPERKEY_Msk             (0xFFFFUL << CEM_SUPERKEY_SUPERKEY_Pos) /*!< 0x0000FFFF */
#define CEM_SUPERKEY_SUPERKEY                 CEM_SUPERKEY_SUPERKEY_Msk

/******************  Bit definition for CEM_HW_CFG register  ******************/

#define CEM_HW_CFG_HW_CFG_PARAM_Pos           (0U)
#define CEM_HW_CFG_HW_CFG_PARAM_Msk           (0xFFFFFFFFUL << CEM_HW_CFG_HW_CFG_PARAM_Pos) /*!< 0xFFFFFFFF */
#define CEM_HW_CFG_HW_CFG_PARAM               CEM_HW_CFG_HW_CFG_PARAM_Msk

/*****************  Bit definition for CEM_VERSION register  ******************/

#define CEM_VERSION_VERSION_Pos               (0U)
#define CEM_VERSION_VERSION_Msk               (0xFFFFFFFFUL << CEM_VERSION_VERSION_Pos) /*!< 0xFFFFFFFF */
#define CEM_VERSION_VERSION                   CEM_VERSION_VERSION_Msk

#define CEM0_BASE           0x4000F400UL
#define CEM1_BASE           0x4000F440UL
#define CEM2_BASE           0x4000F480UL
#define CEM3_BASE           0x4000F4C0UL
#define CEM4_BASE           0x4000F500UL
#define CEM5_BASE           0x4000F540UL
#define CEM6_BASE           0x4000F580UL
#define CEM7_BASE           0x4000F5C0UL
#define CEM8_BASE           0x4000F600UL
#define CEM9_BASE           0x4000F640UL
#define CEM10_BASE          0x4000F680UL
#define CEM11_BASE          0x4000F6C0UL
#define CEM12_BASE          0x4000F700UL
#define CEM13_BASE          0x4000F740UL
#define CEM14_BASE          0x4000F780UL

#define CEM0                ((CEM_TypeDef *) CEM0_BASE)
#define CEM1                ((CEM_TypeDef *) CEM1_BASE)
#define CEM2                ((CEM_TypeDef *) CEM2_BASE)
#define CEM3                ((CEM_TypeDef *) CEM3_BASE)
#define CEM4                ((CEM_TypeDef *) CEM4_BASE)
#define CEM5                ((CEM_TypeDef *) CEM5_BASE)
#define CEM6                ((CEM_TypeDef *) CEM6_BASE)
#define CEM7                ((CEM_TypeDef *) CEM7_BASE)
#define CEM8                ((CEM_TypeDef *) CEM8_BASE)
#define CEM9                ((CEM_TypeDef *) CEM9_BASE)
#define CEM10               ((CEM_TypeDef *) CEM10_BASE)
#define CEM11               ((CEM_TypeDef *) CEM11_BASE)
#define CEM12               ((CEM_TypeDef *) CEM12_BASE)
#define CEM13               ((CEM_TypeDef *) CEM13_BASE)
#define CEM14               ((CEM_TypeDef *) CEM14_BASE)

#endif /* __SR5E1_CEM_H */

