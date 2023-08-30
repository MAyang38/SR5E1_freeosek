/****************************************************************************
 *                                                                           
 * Copyright (c) 2022 STMicroelectronics - All Rights Reserved               
 *                                                                           
 * License terms: STMicroelectronics Proprietary in accordance with licensing
 * terms SLA0098 at www.st.com.                                              
 *                                                                           
 * THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,  
 * INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.           
 *                                                                           
 *****************************************************************************/

#ifndef __SR5E1_CRC_H
#define __SR5E1_CRC_H

/******************************************************************************/
/*                                                                            */
/*                                 CRC (CRC)                                  */
/*                                                                            */
/******************************************************************************/
typedef struct
{
  __IO uint32_t DR;         /*!< DR       Address offset: 0x00 */
  __IO uint32_t IDR;        /*!< IDR      Address offset: 0x04 */
  __IO uint32_t CR;         /*!< CR       Address offset: 0x08 */
       uint32_t RESERVED0;  /*!< Reserved Address offset: 0x0C */
  __IO uint32_t INIT;       /*!< INIT     Address offset: 0x10 */
  __IO uint32_t POL;        /*!< POL      Address offset: 0x14 */
} CRC_TypeDef;


/********************  Bit definition for CRC_DR register  ********************/
#define CRC_DR_DR_Pos             (0U)
#define CRC_DR_DR_Msk             (0xFFFFFFFFUL << CRC_DR_DR_Pos)         /*!< 0xFFFFFFFF */
#define CRC_DR_DR                 CRC_DR_DR_Msk         /*!< </spirit:description> */

/*******************  Bit definition for CRC_IDR register  ********************/
#define CRC_IDR_IDR_Pos          (0U)
#define CRC_IDR_IDR_Msk          (0xFFFFFFFFUL << CRC_IDR_IDR_Pos)          /*!< 0xFFFFFFFF */
#define CRC_IDR_IDR              CRC_IDR_IDR_Msk       /*!< </spirit:description> */

/********************  Bit definition for CRC_CR register  ********************/
#define CRC_CR_IEET_Pos          (0U)
#define CRC_CR_IEET_Msk          (0x1UL << CRC_CR_IEET_Pos)   /*!< 0x00000001 */
#define CRC_CR_IEET              CRC_CR_IEET_Msk       /*!< </spirit:description> */
#define CRC_CR_POLYSIZE_Pos      (3U)
#define CRC_CR_POLYSIZE_Msk      (0x3UL << CRC_CR_POLYSIZE_Pos)       /*!< 0x00000018 */
#define CRC_CR_POLYSIZE          CRC_CR_POLYSIZE_Msk   /*!< </spirit:description> */
#define CRC_CR_POLYSIZE_0      (0x1UL << CRC_CR_POLYSIZE_Pos)        /*!< 0x00000008 */
#define CRC_CR_POLYSIZE_1      (0x2UL << CRC_CR_POLYSIZE_Pos)        /*!< 0x00000010 */
#define CRC_CR_REV_IN_Pos        (5U)
#define CRC_CR_REV_IN_Msk        (0x3UL << CRC_CR_REV_IN_Pos)     /*!< 0x00000060 */
#define CRC_CR_REV_IN            CRC_CR_REV_IN_Msk     /*!< </spirit:description> */
#define CRC_CR_REV_IN_0        (0x1UL << CRC_CR_REV_IN_Pos)      /*!< 0x00000020 */
#define CRC_CR_REV_IN_1        (0x2UL << CRC_CR_REV_IN_Pos)      /*!< 0x00000040 */
#define CRC_CR_REV_OUT_Pos       (7U)
#define CRC_CR_REV_OUT_Msk       (0x1UL << CRC_CR_REV_OUT_Pos)      /*!< 0x00000080 */
#define CRC_CR_REV_OUT           CRC_CR_REV_OUT_Msk    /*!< </spirit:description> */

/*******************  Bit definition for CRC_INIT register  *******************/
#define CRC_INIT_INIT_Pos        (0U)
#define CRC_INIT_INIT_Msk        (0xFFFFFFFFUL << CRC_INIT_INIT_Pos)            /*!< 0xFFFFFFFF */
#define CRC_INIT_INIT            CRC_INIT_INIT_Msk     /*!< </spirit:description> */

/*******************  Bit definition for CRC_POL register  ********************/
#define CRC_POL_POL_Pos          (0U)
#define CRC_POL_POL_Msk          (0xFFFFFFFFUL << CRC_POL_POL_Pos)          /*!< 0xFFFFFFFF */
#define CRC_POL_POL              CRC_POL_POL_Msk       /*!< </spirit:description> */

#define CRC_BASE           0x44003000UL 


#define CRC                ((CRC_TypeDef *) CRC_BASE) 


#endif /* __SR5E1_CRC_H */

