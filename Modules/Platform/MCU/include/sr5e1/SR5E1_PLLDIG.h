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

#ifndef __SR5E1_PLLDIG_H
#define __SR5E1_PLLDIG_H

/******************************************************************************/
/*                                                                            */
/*                              PLLDIG (PLLDIG)                               */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO uint32_t PLL0CR;        /*!< PLL0CR   Address offset: 0x00 */
  __IO uint32_t PLL0SR;        /*!< PLL0SR   Address offset: 0x04 */
  __IO uint32_t PLL0DV;        /*!< PLL0DV   Address offset: 0x08 */
       uint32_t RESERVED0[5];  /*!< Reserved Address offset: 0x0C-0x1C */
  __IO uint32_t PLL1CR;        /*!< PLL1CR   Address offset: 0x20 */
  __IO uint32_t PLL1SR;        /*!< PLL1SR   Address offset: 0x24 */
  __IO uint32_t PLL1DV;        /*!< PLL1DV   Address offset: 0x28 */
  __IO uint32_t PLL1FM;        /*!< PLL1FM   Address offset: 0x2C */
  __IO uint32_t PLL1FD;        /*!< PLL1FD   Address offset: 0x30 */
} PLLDIG_TypeDef;


/****************  Bit definition for PLLDIG_PLL0CR register  *****************/
#define PLLDIG_PLL0CR_LOLIE_Pos   (3U)
#define PLLDIG_PLL0CR_LOLIE_Msk   (0x1UL << PLLDIG_PLL0CR_LOLIE_Pos)    /*!< 0x00000008 */
#define PLLDIG_PLL0CR_LOLIE       PLLDIG_PLL0CR_LOLIE_Msk      /*!< </spirit:description> */
#define PLLDIG_PLL0CR_CLKCFG_Pos  (8U)
#define PLLDIG_PLL0CR_CLKCFG_Msk  (0x3UL << PLLDIG_PLL0CR_CLKCFG_Pos)     /*!< 0x00000300 */
#define PLLDIG_PLL0CR_CLKCFG      PLLDIG_PLL0CR_CLKCFG_Msk     /*!< </spirit:description> */

/****************  Bit definition for PLLDIG_PLL0SR register  *****************/
#define PLLDIG_PLL0SR_LOCK_Pos    (2U)
#define PLLDIG_PLL0SR_LOCK_Msk    (0x1UL << PLLDIG_PLL0SR_LOCK_Pos)   /*!< 0x00000004 */
#define PLLDIG_PLL0SR_LOCK        PLLDIG_PLL0SR_LOCK_Msk       /*!< </spirit:description> */
#define PLLDIG_PLL0SR_LOLF_Pos    (3U)
#define PLLDIG_PLL0SR_LOLF_Msk    (0x1UL << PLLDIG_PLL0SR_LOLF_Pos)   /*!< 0x00000008 */
#define PLLDIG_PLL0SR_LOLF        PLLDIG_PLL0SR_LOLF_Msk       /*!< </spirit:description> */

/****************  Bit definition for PLLDIG_PLL0DV register  *****************/
#define PLLDIG_PLL0DV_MFD_Pos     (0U)
#define PLLDIG_PLL0DV_MFD_Msk     (0x7FUL << PLLDIG_PLL0DV_MFD_Pos)  /*!< 0x0000007F */
#define PLLDIG_PLL0DV_MFD         PLLDIG_PLL0DV_MFD_Msk        /*!< </spirit:description> */
#define PLLDIG_PLL0DV_PREDIV_Pos  (12U)
#define PLLDIG_PLL0DV_PREDIV_Msk  (0x7UL << PLLDIG_PLL0DV_PREDIV_Pos)     /*!< 0x00007000 */
#define PLLDIG_PLL0DV_PREDIV      PLLDIG_PLL0DV_PREDIV_Msk     /*!< </spirit:description> */
#define PLLDIG_PLL0DV_RFDPHI_Pos  (16U)
#define PLLDIG_PLL0DV_RFDPHI_Msk  (0x3FUL << PLLDIG_PLL0DV_RFDPHI_Pos)      /*!< 0x003F0000 */
#define PLLDIG_PLL0DV_RFDPHI      PLLDIG_PLL0DV_RFDPHI_Msk     /*!< </spirit:description> */
#define PLLDIG_PLL0DV_RFDPHI1_Pos (27U)
#define PLLDIG_PLL0DV_RFDPHI1_Msk (0xFUL << PLLDIG_PLL0DV_RFDPHI1_Pos)      /*!< 0x78000000 */
#define PLLDIG_PLL0DV_RFDPHI1     PLLDIG_PLL0DV_RFDPHI1_Msk    /*!< </spirit:description> */

/****************  Bit definition for PLLDIG_PLL1CR register  *****************/
#define PLLDIG_PLL1CR_LOLIE_Pos   (3U)
#define PLLDIG_PLL1CR_LOLIE_Msk   (0x1UL << PLLDIG_PLL1CR_LOLIE_Pos)    /*!< 0x00000008 */
#define PLLDIG_PLL1CR_LOLIE       PLLDIG_PLL1CR_LOLIE_Msk      /*!< </spirit:description> */
#define PLLDIG_PLL1CR_CLKCFG_Pos  (8U)
#define PLLDIG_PLL1CR_CLKCFG_Msk  (0x3UL << PLLDIG_PLL1CR_CLKCFG_Pos)     /*!< 0x00000300 */
#define PLLDIG_PLL1CR_CLKCFG      PLLDIG_PLL1CR_CLKCFG_Msk     /*!< </spirit:description> */

/****************  Bit definition for PLLDIG_PLL1SR register  *****************/
#define PLLDIG_PLL1SR_LOCK_Pos    (2U)
#define PLLDIG_PLL1SR_LOCK_Msk    (0x1UL << PLLDIG_PLL1SR_LOCK_Pos)   /*!< 0x00000004 */
#define PLLDIG_PLL1SR_LOCK        PLLDIG_PLL1SR_LOCK_Msk       /*!< </spirit:description> */
#define PLLDIG_PLL1SR_LOLF_Pos    (3U)
#define PLLDIG_PLL1SR_LOLF_Msk    (0x1UL << PLLDIG_PLL1SR_LOLF_Pos)   /*!< 0x00000008 */
#define PLLDIG_PLL1SR_LOLF        PLLDIG_PLL1SR_LOLF_Msk       /*!< </spirit:description> */

/****************  Bit definition for PLLDIG_PLL1DV register  *****************/
#define PLLDIG_PLL1DV_MFD_Pos     (0U)
#define PLLDIG_PLL1DV_MFD_Msk     (0x7FUL << PLLDIG_PLL1DV_MFD_Pos)  /*!< 0x0000007F */
#define PLLDIG_PLL1DV_MFD         PLLDIG_PLL1DV_MFD_Msk        /*!< </spirit:description> */
#define PLLDIG_PLL1DV_RFDPHI_Pos  (16U)
#define PLLDIG_PLL1DV_RFDPHI_Msk  (0x3FUL << PLLDIG_PLL1DV_RFDPHI_Pos)      /*!< 0x003F0000 */
#define PLLDIG_PLL1DV_RFDPHI      PLLDIG_PLL1DV_RFDPHI_Msk     /*!< </spirit:description> */

/****************  Bit definition for PLLDIG_PLL1FM register  *****************/
#define PLLDIG_PLL1FM_INCSTP_Pos  (0U)
#define PLLDIG_PLL1FM_INCSTP_Msk  (0x7FFFUL << PLLDIG_PLL1FM_INCSTP_Pos)        /*!< 0x00007FFF */
#define PLLDIG_PLL1FM_INCSTP      PLLDIG_PLL1FM_INCSTP_Msk     /*!< </spirit:description> */
#define PLLDIG_PLL1FM_MODPRD_Pos  (16U)
#define PLLDIG_PLL1FM_MODPRD_Msk  (0x1FFFUL << PLLDIG_PLL1FM_MODPRD_Pos)        /*!< 0x1FFF0000 */
#define PLLDIG_PLL1FM_MODPRD      PLLDIG_PLL1FM_MODPRD_Msk     /*!< </spirit:description> */
#define PLLDIG_PLL1FM_MODSEL_Pos  (29U)
#define PLLDIG_PLL1FM_MODSEL_Msk  (0x1UL << PLLDIG_PLL1FM_MODSEL_Pos)     /*!< 0x20000000 */
#define PLLDIG_PLL1FM_MODSEL      PLLDIG_PLL1FM_MODSEL_Msk     /*!< </spirit:description> */
#define PLLDIG_PLL1FM_MODEN_Pos   (30U)
#define PLLDIG_PLL1FM_MODEN_Msk   (0x1UL << PLLDIG_PLL1FM_MODEN_Pos)    /*!< 0x40000000 */
#define PLLDIG_PLL1FM_MODEN       PLLDIG_PLL1FM_MODEN_Msk      /*!< </spirit:description> */

/****************  Bit definition for PLLDIG_PLL1FD register  *****************/
#define PLLDIG_PLL1FD_FRCDIV_Pos  (0U)
#define PLLDIG_PLL1FD_FRCDIV_Msk  (0xFFFUL << PLLDIG_PLL1FD_FRCDIV_Pos)       /*!< 0x00000FFF */
#define PLLDIG_PLL1FD_FRCDIV      PLLDIG_PLL1FD_FRCDIV_Msk     /*!< </spirit:description> */
#define PLLDIG_PLL1FD_DTHDIS_Pos  (16U)
#define PLLDIG_PLL1FD_DTHDIS_Msk  (0x3UL << PLLDIG_PLL1FD_DTHDIS_Pos)     /*!< 0x00030000 */
#define PLLDIG_PLL1FD_DTHDIS      PLLDIG_PLL1FD_DTHDIS_Msk     /*!< </spirit:description> */
#define PLLDIG_PLL1FD_FDEN_Pos    (30U)
#define PLLDIG_PLL1FD_FDEN_Msk    (0x1UL << PLLDIG_PLL1FD_FDEN_Pos)   /*!< 0x40000000 */
#define PLLDIG_PLL1FD_FDEN        PLLDIG_PLL1FD_FDEN_Msk       /*!< </spirit:description> */

#define PLLDIG_BASE           0x4001D800UL 


#define PLLDIG                ((PLLDIG_TypeDef *) PLLDIG_BASE) 


#endif /* __SR5E1_PLLDIG_H */

