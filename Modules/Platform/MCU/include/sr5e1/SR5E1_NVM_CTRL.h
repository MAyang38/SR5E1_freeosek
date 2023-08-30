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

#ifndef __SR5E1_NVM_H
#define __SR5E1_NVM_H

/******************************************************************************/
/*                                                                            */
/*                                 NVM (NVM)                                  */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO uint32_t PFCR1;        /*!< PFCR1    Address offset: 0x00 */
       uint32_t RESERVED0[1]; /*!< Reserved Address offset: 0x04 */
  __IO uint32_t PFCR3;        /*!< PFCR3    Address offset: 0x08 */
  __IO uint32_t PFSR;         /*!< PFSR     Address offset: 0x0C */
  __IO uint32_t FLTENA;       /*!< FLTENA   Address offset: 0x10 */
  __IO uint32_t FLTFRC;       /*!< FLTFRC   Address offset: 0x14 */
  __IO uint32_t FLTSCR;       /*!< FLTSCR   Address offset: 0x18 */
  __IO uint32_t FLTADR;       /*!< FLTADR   Address offset: 0x1C */
} NVM_TypeDef;


/******************  Bit definition for NVM_PFCR1 register  *******************/
#define NVM_PFCR1_RWSC_Pos               (8U)
#define NVM_PFCR1_RWSC_Msk               (0x1FUL << NVM_PFCR1_RWSC_Pos) /*!< 0x00001F00 */
#define NVM_PFCR1_RWSC                   NVM_PFCR1_RWSC_Msk           /*!< </spirit:description> */
#define NVM_PFCR1_APC_Pos                (13U)
#define NVM_PFCR1_APC_Msk                (0x7UL << NVM_PFCR1_APC_Pos)  /*!< 0x0000E000 */
#define NVM_PFCR1_APC                    NVM_PFCR1_APC_Msk           /*!< </spirit:description> */

/******************  Bit definition for NVM_PFCR3 register  *******************/
#define NVM_PFCR3_BAF_DIS_Pos            (15U)
#define NVM_PFCR3_BAF_DIS_Msk            (0x1UL << NVM_PFCR3_BAF_DIS_Pos)   /*!< 0x00008000 */
#define NVM_PFCR3_BAF_DIS                NVM_PFCR3_BAF_DIS_Msk        /*!< </spirit:description> */

/*******************  Bit definition for NVM_PFSR register  *******************/
#define NVM_PFSR_NVMPCFLHBUSY_Pos        (0U)
#define NVM_PFSR_NVMPCFLHBUSY_Msk        (0x1UL << NVM_PFSR_NVMPCFLHBUSY_Pos)       /*!< 0x00000001 */
#define NVM_PFSR_NVMPCFLHBUSY            NVM_PFSR_NVMPCFLHBUSY_Msk    /*!< </spirit:description> */

/******************  Bit definition for NVM_FLTENA register  ******************/
#define NVM_FLTENA_NVMPCENSWAP_Pos       (0U)
#define NVM_FLTENA_NVMPCENSWAP_Msk       (0x1UL << NVM_FLTENA_NVMPCENSWAP_Pos)        /*!< 0x00000001 */
#define NVM_FLTENA_NVMPCENSWAP           NVM_FLTENA_NVMPCENSWAP_Msk   /*!< </spirit:description> */
#define NVM_FLTENA_NVMPCENC_Pos          (1U)
#define NVM_FLTENA_NVMPCENC_Msk          (0x1UL << NVM_FLTENA_NVMPCENC_Pos)     /*!< 0x00000002 */
#define NVM_FLTENA_NVMPCENC              NVM_FLTENA_NVMPCENC_Msk      /*!< </spirit:description> */
#define NVM_FLTENA_NVMDEDC_Pos           (2U)
#define NVM_FLTENA_NVMDEDC_Msk           (0x1UL << NVM_FLTENA_NVMDEDC_Pos)    /*!< 0x00000004 */
#define NVM_FLTENA_NVMDEDC               NVM_FLTENA_NVMDEDC_Msk       /*!< </spirit:description> */
#define NVM_FLTENA_NVMCEDC_Pos           (3U)
#define NVM_FLTENA_NVMCEDC_Msk           (0x1UL << NVM_FLTENA_NVMCEDC_Pos)    /*!< 0x00000008 */
#define NVM_FLTENA_NVMCEDC               NVM_FLTENA_NVMCEDC_Msk       /*!< </spirit:description> */
#define NVM_FLTENA_NVMENCE_Pos           (4U)
#define NVM_FLTENA_NVMENCE_Msk           (0x1UL << NVM_FLTENA_NVMENCE_Pos)    /*!< 0x00000010 */
#define NVM_FLTENA_NVMENCE               NVM_FLTENA_NVMENCE_Msk       /*!< </spirit:description> */
#define NVM_FLTENA_NVMDSBC_Pos           (5U)
#define NVM_FLTENA_NVMDSBC_Msk           (0x1UL << NVM_FLTENA_NVMDSBC_Pos)    /*!< 0x00000020 */
#define NVM_FLTENA_NVMDSBC               NVM_FLTENA_NVMDSBC_Msk       /*!< </spirit:description> */
#define NVM_FLTENA_NVMDDBC_Pos           (6U)
#define NVM_FLTENA_NVMDDBC_Msk           (0x1UL << NVM_FLTENA_NVMDDBC_Pos)    /*!< 0x00000040 */
#define NVM_FLTENA_NVMDDBC               NVM_FLTENA_NVMDDBC_Msk       /*!< </spirit:description> */
#define NVM_FLTENA_NVMDTED_Pos           (7U)
#define NVM_FLTENA_NVMDTED_Msk           (0x1UL << NVM_FLTENA_NVMDTED_Pos)    /*!< 0x00000080 */
#define NVM_FLTENA_NVMDTED               NVM_FLTENA_NVMDTED_Msk       /*!< </spirit:description> */
#define NVM_FLTENA_NVMCSBC_Pos           (8U)
#define NVM_FLTENA_NVMCSBC_Msk           (0x1UL << NVM_FLTENA_NVMCSBC_Pos)    /*!< 0x00000100 */
#define NVM_FLTENA_NVMCSBC               NVM_FLTENA_NVMCSBC_Msk       /*!< </spirit:description> */
#define NVM_FLTENA_NVMCDBC_Pos           (9U)
#define NVM_FLTENA_NVMCDBC_Msk           (0x1UL << NVM_FLTENA_NVMCDBC_Pos)    /*!< 0x00000200 */
#define NVM_FLTENA_NVMCDBC               NVM_FLTENA_NVMCDBC_Msk       /*!< </spirit:description> */
#define NVM_FLTENA_NVMCTED_Pos           (10U)
#define NVM_FLTENA_NVMCTED_Msk           (0x1UL << NVM_FLTENA_NVMCTED_Pos)    /*!< 0x00000400 */
#define NVM_FLTENA_NVMCTED               NVM_FLTENA_NVMCTED_Msk       /*!< </spirit:description> */

/******************  Bit definition for NVM_FLTFRC register  ******************/
#define NVM_FLTFRC_NVMPCENSWAP_Pos       (0U)
#define NVM_FLTFRC_NVMPCENSWAP_Msk       (0x1UL << NVM_FLTFRC_NVMPCENSWAP_Pos)        /*!< 0x00000001 */
#define NVM_FLTFRC_NVMPCENSWAP           NVM_FLTFRC_NVMPCENSWAP_Msk   /*!< </spirit:description> */
#define NVM_FLTFRC_NVMPCENC_Pos          (1U)
#define NVM_FLTFRC_NVMPCENC_Msk          (0x1UL << NVM_FLTFRC_NVMPCENC_Pos)     /*!< 0x00000002 */
#define NVM_FLTFRC_NVMPCENC              NVM_FLTFRC_NVMPCENC_Msk      /*!< </spirit:description> */
#define NVM_FLTFRC_NVMDEDC_Pos           (2U)
#define NVM_FLTFRC_NVMDEDC_Msk           (0x1UL << NVM_FLTFRC_NVMDEDC_Pos)    /*!< 0x00000004 */
#define NVM_FLTFRC_NVMDEDC               NVM_FLTFRC_NVMDEDC_Msk       /*!< </spirit:description> */
#define NVM_FLTFRC_NVMCEDC_Pos           (3U)
#define NVM_FLTFRC_NVMCEDC_Msk           (0x1UL << NVM_FLTFRC_NVMCEDC_Pos)    /*!< 0x00000008 */
#define NVM_FLTFRC_NVMCEDC               NVM_FLTFRC_NVMCEDC_Msk       /*!< </spirit:description> */
#define NVM_FLTFRC_NVMENCE_Pos           (4U)
#define NVM_FLTFRC_NVMENCE_Msk           (0x1UL << NVM_FLTFRC_NVMENCE_Pos)    /*!< 0x00000010 */
#define NVM_FLTFRC_NVMENCE               NVM_FLTFRC_NVMENCE_Msk       /*!< </spirit:description> */
#define NVM_FLTFRC_NVMDSBC_Pos           (5U)
#define NVM_FLTFRC_NVMDSBC_Msk           (0x1UL << NVM_FLTFRC_NVMDSBC_Pos)    /*!< 0x00000020 */
#define NVM_FLTFRC_NVMDSBC               NVM_FLTFRC_NVMDSBC_Msk       /*!< </spirit:description> */
#define NVM_FLTFRC_NVMDDBC_Pos           (6U)
#define NVM_FLTFRC_NVMDDBC_Msk           (0x1UL << NVM_FLTFRC_NVMDDBC_Pos)    /*!< 0x00000040 */
#define NVM_FLTFRC_NVMDDBC               NVM_FLTFRC_NVMDDBC_Msk       /*!< </spirit:description> */
#define NVM_FLTFRC_NVMDTED_Pos           (7U)
#define NVM_FLTFRC_NVMDTED_Msk           (0x1UL << NVM_FLTFRC_NVMDTED_Pos)    /*!< 0x00000080 */
#define NVM_FLTFRC_NVMDTED               NVM_FLTFRC_NVMDTED_Msk       /*!< </spirit:description> */
#define NVM_FLTFRC_NVMCSBC_Pos           (8U)
#define NVM_FLTFRC_NVMCSBC_Msk           (0x1UL << NVM_FLTFRC_NVMCSBC_Pos)    /*!< 0x00000100 */
#define NVM_FLTFRC_NVMCSBC               NVM_FLTFRC_NVMCSBC_Msk       /*!< </spirit:description> */
#define NVM_FLTFRC_NVMCDBC_Pos           (9U)
#define NVM_FLTFRC_NVMCDBC_Msk           (0x1UL << NVM_FLTFRC_NVMCDBC_Pos)    /*!< 0x00000200 */
#define NVM_FLTFRC_NVMCDBC               NVM_FLTFRC_NVMCDBC_Msk       /*!< </spirit:description> */
#define NVM_FLTFRC_NVMCTED_Pos           (10U)
#define NVM_FLTFRC_NVMCTED_Msk           (0x1UL << NVM_FLTFRC_NVMCTED_Pos)    /*!< 0x00000400 */
#define NVM_FLTFRC_NVMCTED               NVM_FLTFRC_NVMCTED_Msk       /*!< </spirit:description> */

/******************  Bit definition for NVM_FLTSCR register  ******************/
#define NVM_FLTSCR_NVMPCENSWAP_Pos       (0U)
#define NVM_FLTSCR_NVMPCENSWAP_Msk       (0x1UL << NVM_FLTSCR_NVMPCENSWAP_Pos)        /*!< 0x00000001 */
#define NVM_FLTSCR_NVMPCENSWAP           NVM_FLTSCR_NVMPCENSWAP_Msk   /*!< </spirit:description> */
#define NVM_FLTSCR_NVMPCENC_Pos          (1U)
#define NVM_FLTSCR_NVMPCENC_Msk          (0x1UL << NVM_FLTSCR_NVMPCENC_Pos)     /*!< 0x00000002 */
#define NVM_FLTSCR_NVMPCENC              NVM_FLTSCR_NVMPCENC_Msk      /*!< </spirit:description> */
#define NVM_FLTSCR_NVMDEDC_Pos           (2U)
#define NVM_FLTSCR_NVMDEDC_Msk           (0x1UL << NVM_FLTSCR_NVMDEDC_Pos)    /*!< 0x00000004 */
#define NVM_FLTSCR_NVMDEDC               NVM_FLTSCR_NVMDEDC_Msk       /*!< </spirit:description> */
#define NVM_FLTSCR_NVMCEDC_Pos           (3U)
#define NVM_FLTSCR_NVMCEDC_Msk           (0x1UL << NVM_FLTSCR_NVMCEDC_Pos)    /*!< 0x00000008 */
#define NVM_FLTSCR_NVMCEDC               NVM_FLTSCR_NVMCEDC_Msk       /*!< </spirit:description> */
#define NVM_FLTSCR_NVMENCE_Pos           (4U)
#define NVM_FLTSCR_NVMENCE_Msk           (0x1UL << NVM_FLTSCR_NVMENCE_Pos)    /*!< 0x00000010 */
#define NVM_FLTSCR_NVMENCE               NVM_FLTSCR_NVMENCE_Msk       /*!< </spirit:description> */
#define NVM_FLTSCR_NVMDSBC_Pos           (5U)
#define NVM_FLTSCR_NVMDSBC_Msk           (0x1UL << NVM_FLTSCR_NVMDSBC_Pos)    /*!< 0x00000020 */
#define NVM_FLTSCR_NVMDSBC               NVM_FLTSCR_NVMDSBC_Msk       /*!< </spirit:description> */
#define NVM_FLTSCR_NVMDDBC_Pos           (6U)
#define NVM_FLTSCR_NVMDDBC_Msk           (0x1UL << NVM_FLTSCR_NVMDDBC_Pos)    /*!< 0x00000040 */
#define NVM_FLTSCR_NVMDDBC               NVM_FLTSCR_NVMDDBC_Msk       /*!< </spirit:description> */
#define NVM_FLTSCR_NVMDTED_Pos           (7U)
#define NVM_FLTSCR_NVMDTED_Msk           (0x1UL << NVM_FLTSCR_NVMDTED_Pos)    /*!< 0x00000080 */
#define NVM_FLTSCR_NVMDTED               NVM_FLTSCR_NVMDTED_Msk       /*!< </spirit:description> */
#define NVM_FLTSCR_NVMCSBC_Pos           (8U)
#define NVM_FLTSCR_NVMCSBC_Msk           (0x1UL << NVM_FLTSCR_NVMCSBC_Pos)    /*!< 0x00000100 */
#define NVM_FLTSCR_NVMCSBC               NVM_FLTSCR_NVMCSBC_Msk       /*!< </spirit:description> */
#define NVM_FLTSCR_NVMCDBC_Pos           (9U)
#define NVM_FLTSCR_NVMCDBC_Msk           (0x1UL << NVM_FLTSCR_NVMCDBC_Pos)    /*!< 0x00000200 */
#define NVM_FLTSCR_NVMCDBC               NVM_FLTSCR_NVMCDBC_Msk       /*!< </spirit:description> */
#define NVM_FLTSCR_NVMCTED_Pos           (10U)
#define NVM_FLTSCR_NVMCTED_Msk           (0x1UL << NVM_FLTSCR_NVMCTED_Pos)    /*!< 0x00000400 */
#define NVM_FLTSCR_NVMCTED               NVM_FLTSCR_NVMCTED_Msk       /*!< </spirit:description> */

/******************  Bit definition for NVM_FLTADR register  ******************/
#define NVM_FLTADR_FADR_Pos              (0U)
#define NVM_FLTADR_FADR_Msk              (0xFFFFFFFFUL << NVM_FLTADR_FADR_Pos)        /*!< 0xFFFFFFFF */
#define NVM_FLTADR_FADR                  NVM_FLTADR_FADR_Msk          /*!< </spirit:description> */

#define NVM_CTRL1_BASE           0x42001800UL 
#define NVM_CTRL2_BASE           0x42001C00UL 


#define NVM_CTRL1                ((NVM_TypeDef *) NVM_CTRL1_BASE) 
#define NVM_CTRL2                ((NVM_TypeDef *) NVM_CTRL2_BASE) 

#endif /* __SR5E1_NVM_H */

