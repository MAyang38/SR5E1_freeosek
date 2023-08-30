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

#ifndef __SR5E1_TDM_H
#define __SR5E1_TDM_H

/******************************************************************************/
/*                                                                            */
/*                                 TDM (TDM)                                  */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO uint32_t TDM_STATUS;       /*!< TDM_STATUS      Address offset: 0x00 */
  __IO uint32_t TDM_LNVMPA;       /*!< TDM_LNVMPA      Address offset: 0x04 */
  __IO uint32_t TDM_DBA_ADDRESS;  /*!< TDM_DBA_ADDRESS Address offset: 0x08 */
       uint32_t RESERVED0;    /*!< Reserved        Address offset: 0x0C */
  __IO uint32_t TDM_STO_KEY0;     /*!< TDM_STO_KEY0    Address offset: 0x10 */
  __IO uint32_t TDM_STO_KEY1;     /*!< TDM_STO_KEY1    Address offset: 0x14 */
  __IO uint32_t TDM_STO_KEY2;     /*!< TDM_STO_KEY2    Address offset: 0x18 */
  __IO uint32_t TDM_STO_KEY3;     /*!< TDM_STO_KEY3    Address offset: 0x1C */
  __IO uint32_t TDM_STO_KEY4;     /*!< TDM_STO_KEY4    Address offset: 0x20 */
  __IO uint32_t TDM_STO_KEY5;     /*!< TDM_STO_KEY5    Address offset: 0x24 */
} TDM_TypeDef;


/****************  Bit definition for TDM_TDM_STATUS register  ****************/
#define TDM_TDM_STATUS_D0S_Pos                (0U)
#define TDM_TDM_STATUS_D0S_Msk                (0x1UL << TDM_TDM_STATUS_D0S_Pos)   /*!< 0x00000001 */
#define TDM_TDM_STATUS_D0S                    TDM_TDM_STATUS_D0S_Msk            /*!< </spirit:description> */
#define TDM_TDM_STATUS_D1S_Pos                (1U)
#define TDM_TDM_STATUS_D1S_Msk                (0x1UL << TDM_TDM_STATUS_D1S_Pos)   /*!< 0x00000002 */
#define TDM_TDM_STATUS_D1S                    TDM_TDM_STATUS_D1S_Msk            /*!< </spirit:description> */
#define TDM_TDM_STATUS_D2S_Pos                (2U)
#define TDM_TDM_STATUS_D2S_Msk                (0x1UL << TDM_TDM_STATUS_D2S_Pos)   /*!< 0x00000004 */
#define TDM_TDM_STATUS_D2S                    TDM_TDM_STATUS_D2S_Msk            /*!< </spirit:description> */
#define TDM_TDM_STATUS_D3S_Pos                (3U)
#define TDM_TDM_STATUS_D3S_Msk                (0x1UL << TDM_TDM_STATUS_D3S_Pos)   /*!< 0x00000008 */
#define TDM_TDM_STATUS_D3S                    TDM_TDM_STATUS_D3S_Msk            /*!< </spirit:description> */
#define TDM_TDM_STATUS_D4S_Pos                (4U)
#define TDM_TDM_STATUS_D4S_Msk                (0x1UL << TDM_TDM_STATUS_D4S_Pos)   /*!< 0x00000010 */
#define TDM_TDM_STATUS_D4S                    TDM_TDM_STATUS_D4S_Msk            /*!< </spirit:description> */
#define TDM_TDM_STATUS_D5S_Pos                (5U)
#define TDM_TDM_STATUS_D5S_Msk                (0x1UL << TDM_TDM_STATUS_D5S_Pos)   /*!< 0x00000020 */
#define TDM_TDM_STATUS_D5S                    TDM_TDM_STATUS_D5S_Msk            /*!< </spirit:description> */
#define TDM_TDM_STATUS_DS0_Pos                (30U)
#define TDM_TDM_STATUS_DS0_Msk                (0x1UL << TDM_TDM_STATUS_DS0_Pos)   /*!< 0x40000000 */
#define TDM_TDM_STATUS_DS0                    TDM_TDM_STATUS_DS0_Msk            /*!< </spirit:description> */
#define TDM_TDM_STATUS_DS1_Pos                (31U)
#define TDM_TDM_STATUS_DS1_Msk                (0x1UL << TDM_TDM_STATUS_DS1_Pos)   /*!< 0x80000000 */
#define TDM_TDM_STATUS_DS1                    TDM_TDM_STATUS_DS1_Msk            /*!< </spirit:description> */

/****************  Bit definition for TDM_TDM_LNVMPA register  ****************/
#define TDM_TDM_LNVMPA_NVM0_Pos               (0U)
#define TDM_TDM_LNVMPA_NVM0_Msk               (0x1UL << TDM_TDM_LNVMPA_NVM0_Pos)  /*!< 0x00000001 */
#define TDM_TDM_LNVMPA_NVM0                   TDM_TDM_LNVMPA_NVM0_Msk           /*!< </spirit:description> */
#define TDM_TDM_LNVMPA_NVM1_Pos               (1U)
#define TDM_TDM_LNVMPA_NVM1_Msk               (0x1UL << TDM_TDM_LNVMPA_NVM1_Pos)  /*!< 0x00000002 */
#define TDM_TDM_LNVMPA_NVM1                   TDM_TDM_LNVMPA_NVM1_Msk           /*!< </spirit:description> */
#define TDM_TDM_LNVMPA_NVM2_Pos               (2U)
#define TDM_TDM_LNVMPA_NVM2_Msk               (0x1UL << TDM_TDM_LNVMPA_NVM2_Pos)  /*!< 0x00000004 */
#define TDM_TDM_LNVMPA_NVM2                   TDM_TDM_LNVMPA_NVM2_Msk           /*!< </spirit:description> */
#define TDM_TDM_LNVMPA_NVM3_Pos               (3U)
#define TDM_TDM_LNVMPA_NVM3_Msk               (0x1UL << TDM_TDM_LNVMPA_NVM3_Pos)  /*!< 0x00000008 */
#define TDM_TDM_LNVMPA_NVM3                   TDM_TDM_LNVMPA_NVM3_Msk           /*!< </spirit:description> */
#define TDM_TDM_LNVMPA_NVM4_Pos               (4U)
#define TDM_TDM_LNVMPA_NVM4_Msk               (0x1UL << TDM_TDM_LNVMPA_NVM4_Pos)  /*!< 0x00000010 */
#define TDM_TDM_LNVMPA_NVM4                   TDM_TDM_LNVMPA_NVM4_Msk           /*!< </spirit:description> */
#define TDM_TDM_LNVMPA_NVM5_Pos               (5U)
#define TDM_TDM_LNVMPA_NVM5_Msk               (0x1UL << TDM_TDM_LNVMPA_NVM5_Pos)  /*!< 0x00000020 */
#define TDM_TDM_LNVMPA_NVM5                   TDM_TDM_LNVMPA_NVM5_Msk           /*!< </spirit:description> */
#define TDM_TDM_LNVMPA_NVM6_Pos               (6U)
#define TDM_TDM_LNVMPA_NVM6_Msk               (0x1UL << TDM_TDM_LNVMPA_NVM6_Pos)  /*!< 0x00000040 */
#define TDM_TDM_LNVMPA_NVM6                   TDM_TDM_LNVMPA_NVM6_Msk           /*!< </spirit:description> */
#define TDM_TDM_LNVMPA_NVM7_Pos               (7U)
#define TDM_TDM_LNVMPA_NVM7_Msk               (0x1UL << TDM_TDM_LNVMPA_NVM7_Pos)  /*!< 0x00000080 */
#define TDM_TDM_LNVMPA_NVM7                   TDM_TDM_LNVMPA_NVM7_Msk           /*!< </spirit:description> */
#define TDM_TDM_LNVMPA_NVM8_Pos               (8U)
#define TDM_TDM_LNVMPA_NVM8_Msk               (0x1UL << TDM_TDM_LNVMPA_NVM8_Pos)  /*!< 0x00000100 */
#define TDM_TDM_LNVMPA_NVM8                   TDM_TDM_LNVMPA_NVM8_Msk           /*!< </spirit:description> */
#define TDM_TDM_LNVMPA_NVM9_Pos               (9U)
#define TDM_TDM_LNVMPA_NVM9_Msk               (0x1UL << TDM_TDM_LNVMPA_NVM9_Pos)  /*!< 0x00000200 */
#define TDM_TDM_LNVMPA_NVM9                   TDM_TDM_LNVMPA_NVM9_Msk           /*!< </spirit:description> */
#define TDM_TDM_LNVMPA_NVM10_Pos              (10U)
#define TDM_TDM_LNVMPA_NVM10_Msk              (0x1UL << TDM_TDM_LNVMPA_NVM10_Pos) /*!< 0x00000400 */
#define TDM_TDM_LNVMPA_NVM10                  TDM_TDM_LNVMPA_NVM10_Msk          /*!< </spirit:description> */
#define TDM_TDM_LNVMPA_NVM11_Pos              (11U)
#define TDM_TDM_LNVMPA_NVM11_Msk              (0x1UL << TDM_TDM_LNVMPA_NVM11_Pos) /*!< 0x00000800 */
#define TDM_TDM_LNVMPA_NVM11                  TDM_TDM_LNVMPA_NVM11_Msk          /*!< </spirit:description> */
#define TDM_TDM_LNVMPA_NVM12_Pos              (12U)
#define TDM_TDM_LNVMPA_NVM12_Msk              (0x1UL << TDM_TDM_LNVMPA_NVM12_Pos) /*!< 0x00001000 */
#define TDM_TDM_LNVMPA_NVM12                  TDM_TDM_LNVMPA_NVM12_Msk          /*!< </spirit:description> */
#define TDM_TDM_LNVMPA_NVM13_Pos              (13U)
#define TDM_TDM_LNVMPA_NVM13_Msk              (0x1UL << TDM_TDM_LNVMPA_NVM13_Pos) /*!< 0x00002000 */
#define TDM_TDM_LNVMPA_NVM13                  TDM_TDM_LNVMPA_NVM13_Msk          /*!< </spirit:description> */
#define TDM_TDM_LNVMPA_NVM14_Pos              (14U)
#define TDM_TDM_LNVMPA_NVM14_Msk              (0x1UL << TDM_TDM_LNVMPA_NVM14_Pos) /*!< 0x00004000 */
#define TDM_TDM_LNVMPA_NVM14                  TDM_TDM_LNVMPA_NVM14_Msk          /*!< </spirit:description> */
#define TDM_TDM_LNVMPA_NVM15_Pos              (15U)
#define TDM_TDM_LNVMPA_NVM15_Msk              (0x1UL << TDM_TDM_LNVMPA_NVM15_Pos) /*!< 0x00008000 */
#define TDM_TDM_LNVMPA_NVM15                  TDM_TDM_LNVMPA_NVM15_Msk          /*!< </spirit:description> */
#define TDM_TDM_LNVMPA_NVM16_Pos              (16U)
#define TDM_TDM_LNVMPA_NVM16_Msk              (0x1UL << TDM_TDM_LNVMPA_NVM16_Pos) /*!< 0x00010000 */
#define TDM_TDM_LNVMPA_NVM16                  TDM_TDM_LNVMPA_NVM16_Msk          /*!< </spirit:description> */
#define TDM_TDM_LNVMPA_NVM17_Pos              (17U)
#define TDM_TDM_LNVMPA_NVM17_Msk              (0x1UL << TDM_TDM_LNVMPA_NVM17_Pos) /*!< 0x00020000 */
#define TDM_TDM_LNVMPA_NVM17                  TDM_TDM_LNVMPA_NVM17_Msk          /*!< </spirit:description> */
#define TDM_TDM_LNVMPA_NVM18_Pos              (18U)
#define TDM_TDM_LNVMPA_NVM18_Msk              (0x1UL << TDM_TDM_LNVMPA_NVM18_Pos) /*!< 0x00040000 */
#define TDM_TDM_LNVMPA_NVM18                  TDM_TDM_LNVMPA_NVM18_Msk          /*!< </spirit:description> */
#define TDM_TDM_LNVMPA_NVM19_Pos              (19U)
#define TDM_TDM_LNVMPA_NVM19_Msk              (0x1UL << TDM_TDM_LNVMPA_NVM19_Pos) /*!< 0x00080000 */
#define TDM_TDM_LNVMPA_NVM19                  TDM_TDM_LNVMPA_NVM19_Msk          /*!< </spirit:description> */
#define TDM_TDM_LNVMPA_NVM20_Pos              (20U)
#define TDM_TDM_LNVMPA_NVM20_Msk              (0x1UL << TDM_TDM_LNVMPA_NVM20_Pos) /*!< 0x00100000 */
#define TDM_TDM_LNVMPA_NVM20                  TDM_TDM_LNVMPA_NVM20_Msk          /*!< </spirit:description> */
#define TDM_TDM_LNVMPA_NVM21_Pos              (21U)
#define TDM_TDM_LNVMPA_NVM21_Msk              (0x1UL << TDM_TDM_LNVMPA_NVM21_Pos) /*!< 0x00200000 */
#define TDM_TDM_LNVMPA_NVM21                  TDM_TDM_LNVMPA_NVM21_Msk          /*!< </spirit:description> */
#define TDM_TDM_LNVMPA_NVM22_Pos              (22U)
#define TDM_TDM_LNVMPA_NVM22_Msk              (0x1UL << TDM_TDM_LNVMPA_NVM22_Pos) /*!< 0x00400000 */
#define TDM_TDM_LNVMPA_NVM22                  TDM_TDM_LNVMPA_NVM22_Msk          /*!< </spirit:description> */
#define TDM_TDM_LNVMPA_NVM23_Pos              (23U)
#define TDM_TDM_LNVMPA_NVM23_Msk              (0x1UL << TDM_TDM_LNVMPA_NVM23_Pos) /*!< 0x00800000 */
#define TDM_TDM_LNVMPA_NVM23                  TDM_TDM_LNVMPA_NVM23_Msk          /*!< </spirit:description> */
#define TDM_TDM_LNVMPA_NVM24_Pos              (24U)
#define TDM_TDM_LNVMPA_NVM24_Msk              (0x1UL << TDM_TDM_LNVMPA_NVM24_Pos) /*!< 0x01000000 */
#define TDM_TDM_LNVMPA_NVM24                  TDM_TDM_LNVMPA_NVM24_Msk          /*!< </spirit:description> */
#define TDM_TDM_LNVMPA_NVM25_Pos              (25U)
#define TDM_TDM_LNVMPA_NVM25_Msk              (0x1UL << TDM_TDM_LNVMPA_NVM25_Pos) /*!< 0x02000000 */
#define TDM_TDM_LNVMPA_NVM25                  TDM_TDM_LNVMPA_NVM25_Msk          /*!< </spirit:description> */
#define TDM_TDM_LNVMPA_NVM26_Pos              (26U)
#define TDM_TDM_LNVMPA_NVM26_Msk              (0x1UL << TDM_TDM_LNVMPA_NVM26_Pos) /*!< 0x04000000 */
#define TDM_TDM_LNVMPA_NVM26                  TDM_TDM_LNVMPA_NVM26_Msk          /*!< </spirit:description> */
#define TDM_TDM_LNVMPA_NVM27_Pos              (27U)
#define TDM_TDM_LNVMPA_NVM27_Msk              (0x1UL << TDM_TDM_LNVMPA_NVM27_Pos) /*!< 0x08000000 */
#define TDM_TDM_LNVMPA_NVM27                  TDM_TDM_LNVMPA_NVM27_Msk          /*!< </spirit:description> */
#define TDM_TDM_LNVMPA_NVM28_Pos              (28U)
#define TDM_TDM_LNVMPA_NVM28_Msk              (0x1UL << TDM_TDM_LNVMPA_NVM28_Pos) /*!< 0x10000000 */
#define TDM_TDM_LNVMPA_NVM28                  TDM_TDM_LNVMPA_NVM28_Msk          /*!< </spirit:description> */
#define TDM_TDM_LNVMPA_NVM29_Pos              (29U)
#define TDM_TDM_LNVMPA_NVM29_Msk              (0x1UL << TDM_TDM_LNVMPA_NVM29_Pos) /*!< 0x20000000 */
#define TDM_TDM_LNVMPA_NVM29                  TDM_TDM_LNVMPA_NVM29_Msk          /*!< </spirit:description> */
#define TDM_TDM_LNVMPA_NVM30_Pos              (30U)
#define TDM_TDM_LNVMPA_NVM30_Msk              (0x1UL << TDM_TDM_LNVMPA_NVM30_Pos) /*!< 0x40000000 */
#define TDM_TDM_LNVMPA_NVM30                  TDM_TDM_LNVMPA_NVM30_Msk          /*!< </spirit:description> */
#define TDM_TDM_LNVMPA_NVM31_Pos              (31U)
#define TDM_TDM_LNVMPA_NVM31_Msk              (0x1UL << TDM_TDM_LNVMPA_NVM31_Pos) /*!< 0x80000000 */
#define TDM_TDM_LNVMPA_NVM31                  TDM_TDM_LNVMPA_NVM31_Msk          /*!< </spirit:description> */

/*************  Bit definition for TDM_TDM_DBA_ADDRESS register  **************/
#define TDM_TDM_DBA_ADDRESS_DBA0_Pos          (0U)
#define TDM_TDM_DBA_ADDRESS_DBA0_Msk          (0x1UL << TDM_TDM_DBA_ADDRESS_DBA0_Pos)     /*!< 0x00000001 */
#define TDM_TDM_DBA_ADDRESS_DBA0              TDM_TDM_DBA_ADDRESS_DBA0_Msk      /*!< </spirit:description> */
#define TDM_TDM_DBA_ADDRESS_DBA1_Pos          (1U)
#define TDM_TDM_DBA_ADDRESS_DBA1_Msk          (0x1UL << TDM_TDM_DBA_ADDRESS_DBA1_Pos)     /*!< 0x00000002 */
#define TDM_TDM_DBA_ADDRESS_DBA1              TDM_TDM_DBA_ADDRESS_DBA1_Msk      /*!< </spirit:description> */
#define TDM_TDM_DBA_ADDRESS_DBA2_Pos          (2U)
#define TDM_TDM_DBA_ADDRESS_DBA2_Msk          (0x1UL << TDM_TDM_DBA_ADDRESS_DBA2_Pos)     /*!< 0x00000004 */
#define TDM_TDM_DBA_ADDRESS_DBA2              TDM_TDM_DBA_ADDRESS_DBA2_Msk      /*!< </spirit:description> */
#define TDM_TDM_DBA_ADDRESS_DBA3_Pos          (3U)
#define TDM_TDM_DBA_ADDRESS_DBA3_Msk          (0x1UL << TDM_TDM_DBA_ADDRESS_DBA3_Pos)     /*!< 0x00000008 */
#define TDM_TDM_DBA_ADDRESS_DBA3              TDM_TDM_DBA_ADDRESS_DBA3_Msk      /*!< </spirit:description> */
#define TDM_TDM_DBA_ADDRESS_DBA4_Pos          (4U)
#define TDM_TDM_DBA_ADDRESS_DBA4_Msk          (0x1UL << TDM_TDM_DBA_ADDRESS_DBA4_Pos)     /*!< 0x00000010 */
#define TDM_TDM_DBA_ADDRESS_DBA4              TDM_TDM_DBA_ADDRESS_DBA4_Msk      /*!< </spirit:description> */
#define TDM_TDM_DBA_ADDRESS_DBA5_Pos          (5U)
#define TDM_TDM_DBA_ADDRESS_DBA5_Msk          (0x1UL << TDM_TDM_DBA_ADDRESS_DBA5_Pos)     /*!< 0x00000020 */
#define TDM_TDM_DBA_ADDRESS_DBA5              TDM_TDM_DBA_ADDRESS_DBA5_Msk      /*!< </spirit:description> */
#define TDM_TDM_DBA_ADDRESS_DBA6_Pos          (6U)
#define TDM_TDM_DBA_ADDRESS_DBA6_Msk          (0x1UL << TDM_TDM_DBA_ADDRESS_DBA6_Pos)     /*!< 0x00000040 */
#define TDM_TDM_DBA_ADDRESS_DBA6              TDM_TDM_DBA_ADDRESS_DBA6_Msk      /*!< </spirit:description> */
#define TDM_TDM_DBA_ADDRESS_DBA7_Pos          (7U)
#define TDM_TDM_DBA_ADDRESS_DBA7_Msk          (0x1UL << TDM_TDM_DBA_ADDRESS_DBA7_Pos)     /*!< 0x00000080 */
#define TDM_TDM_DBA_ADDRESS_DBA7              TDM_TDM_DBA_ADDRESS_DBA7_Msk      /*!< </spirit:description> */
#define TDM_TDM_DBA_ADDRESS_DBA8_Pos          (8U)
#define TDM_TDM_DBA_ADDRESS_DBA8_Msk          (0x1UL << TDM_TDM_DBA_ADDRESS_DBA8_Pos)     /*!< 0x00000100 */
#define TDM_TDM_DBA_ADDRESS_DBA8              TDM_TDM_DBA_ADDRESS_DBA8_Msk      /*!< </spirit:description> */
#define TDM_TDM_DBA_ADDRESS_DBA9_Pos          (9U)
#define TDM_TDM_DBA_ADDRESS_DBA9_Msk          (0x1UL << TDM_TDM_DBA_ADDRESS_DBA9_Pos)     /*!< 0x00000200 */
#define TDM_TDM_DBA_ADDRESS_DBA9              TDM_TDM_DBA_ADDRESS_DBA9_Msk      /*!< </spirit:description> */
#define TDM_TDM_DBA_ADDRESS_DBA10_Pos         (10U)
#define TDM_TDM_DBA_ADDRESS_DBA10_Msk         (0x1UL << TDM_TDM_DBA_ADDRESS_DBA10_Pos)      /*!< 0x00000400 */
#define TDM_TDM_DBA_ADDRESS_DBA10             TDM_TDM_DBA_ADDRESS_DBA10_Msk     /*!< </spirit:description> */
#define TDM_TDM_DBA_ADDRESS_DBA11_Pos         (11U)
#define TDM_TDM_DBA_ADDRESS_DBA11_Msk         (0x1UL << TDM_TDM_DBA_ADDRESS_DBA11_Pos)      /*!< 0x00000800 */
#define TDM_TDM_DBA_ADDRESS_DBA11             TDM_TDM_DBA_ADDRESS_DBA11_Msk     /*!< </spirit:description> */
#define TDM_TDM_DBA_ADDRESS_DBA12_Pos         (12U)
#define TDM_TDM_DBA_ADDRESS_DBA12_Msk         (0x1UL << TDM_TDM_DBA_ADDRESS_DBA12_Pos)      /*!< 0x00001000 */
#define TDM_TDM_DBA_ADDRESS_DBA12             TDM_TDM_DBA_ADDRESS_DBA12_Msk     /*!< </spirit:description> */
#define TDM_TDM_DBA_ADDRESS_DBA13_Pos         (13U)
#define TDM_TDM_DBA_ADDRESS_DBA13_Msk         (0x1UL << TDM_TDM_DBA_ADDRESS_DBA13_Pos)      /*!< 0x00002000 */
#define TDM_TDM_DBA_ADDRESS_DBA13             TDM_TDM_DBA_ADDRESS_DBA13_Msk     /*!< </spirit:description> */
#define TDM_TDM_DBA_ADDRESS_DBA14_Pos         (14U)
#define TDM_TDM_DBA_ADDRESS_DBA14_Msk         (0x1UL << TDM_TDM_DBA_ADDRESS_DBA14_Pos)      /*!< 0x00004000 */
#define TDM_TDM_DBA_ADDRESS_DBA14             TDM_TDM_DBA_ADDRESS_DBA14_Msk     /*!< </spirit:description> */
#define TDM_TDM_DBA_ADDRESS_DBA15_Pos         (15U)
#define TDM_TDM_DBA_ADDRESS_DBA15_Msk         (0x1UL << TDM_TDM_DBA_ADDRESS_DBA15_Pos)      /*!< 0x00008000 */
#define TDM_TDM_DBA_ADDRESS_DBA15             TDM_TDM_DBA_ADDRESS_DBA15_Msk     /*!< </spirit:description> */
#define TDM_TDM_DBA_ADDRESS_DBA16_Pos         (16U)
#define TDM_TDM_DBA_ADDRESS_DBA16_Msk         (0x1UL << TDM_TDM_DBA_ADDRESS_DBA16_Pos)      /*!< 0x00010000 */
#define TDM_TDM_DBA_ADDRESS_DBA16             TDM_TDM_DBA_ADDRESS_DBA16_Msk     /*!< </spirit:description> */
#define TDM_TDM_DBA_ADDRESS_DBA17_Pos         (17U)
#define TDM_TDM_DBA_ADDRESS_DBA17_Msk         (0x1UL << TDM_TDM_DBA_ADDRESS_DBA17_Pos)      /*!< 0x00020000 */
#define TDM_TDM_DBA_ADDRESS_DBA17             TDM_TDM_DBA_ADDRESS_DBA17_Msk     /*!< </spirit:description> */
#define TDM_TDM_DBA_ADDRESS_DBA18_Pos         (18U)
#define TDM_TDM_DBA_ADDRESS_DBA18_Msk         (0x1UL << TDM_TDM_DBA_ADDRESS_DBA18_Pos)      /*!< 0x00040000 */
#define TDM_TDM_DBA_ADDRESS_DBA18             TDM_TDM_DBA_ADDRESS_DBA18_Msk     /*!< </spirit:description> */
#define TDM_TDM_DBA_ADDRESS_DBA19_Pos         (19U)
#define TDM_TDM_DBA_ADDRESS_DBA19_Msk         (0x1UL << TDM_TDM_DBA_ADDRESS_DBA19_Pos)      /*!< 0x00080000 */
#define TDM_TDM_DBA_ADDRESS_DBA19             TDM_TDM_DBA_ADDRESS_DBA19_Msk     /*!< </spirit:description> */
#define TDM_TDM_DBA_ADDRESS_DBA20_Pos         (20U)
#define TDM_TDM_DBA_ADDRESS_DBA20_Msk         (0x1UL << TDM_TDM_DBA_ADDRESS_DBA20_Pos)      /*!< 0x00100000 */
#define TDM_TDM_DBA_ADDRESS_DBA20             TDM_TDM_DBA_ADDRESS_DBA20_Msk     /*!< </spirit:description> */
#define TDM_TDM_DBA_ADDRESS_DBA21_Pos         (21U)
#define TDM_TDM_DBA_ADDRESS_DBA21_Msk         (0x1UL << TDM_TDM_DBA_ADDRESS_DBA21_Pos)      /*!< 0x00200000 */
#define TDM_TDM_DBA_ADDRESS_DBA21             TDM_TDM_DBA_ADDRESS_DBA21_Msk     /*!< </spirit:description> */
#define TDM_TDM_DBA_ADDRESS_DBA22_Pos         (22U)
#define TDM_TDM_DBA_ADDRESS_DBA22_Msk         (0x1UL << TDM_TDM_DBA_ADDRESS_DBA22_Pos)      /*!< 0x00400000 */
#define TDM_TDM_DBA_ADDRESS_DBA22             TDM_TDM_DBA_ADDRESS_DBA22_Msk     /*!< </spirit:description> */
#define TDM_TDM_DBA_ADDRESS_DBA23_Pos         (23U)
#define TDM_TDM_DBA_ADDRESS_DBA23_Msk         (0x1UL << TDM_TDM_DBA_ADDRESS_DBA23_Pos)      /*!< 0x00800000 */
#define TDM_TDM_DBA_ADDRESS_DBA23             TDM_TDM_DBA_ADDRESS_DBA23_Msk     /*!< </spirit:description> */
#define TDM_TDM_DBA_ADDRESS_DBA24_Pos         (24U)
#define TDM_TDM_DBA_ADDRESS_DBA24_Msk         (0x1UL << TDM_TDM_DBA_ADDRESS_DBA24_Pos)      /*!< 0x01000000 */
#define TDM_TDM_DBA_ADDRESS_DBA24             TDM_TDM_DBA_ADDRESS_DBA24_Msk     /*!< </spirit:description> */
#define TDM_TDM_DBA_ADDRESS_DBA25_Pos         (25U)
#define TDM_TDM_DBA_ADDRESS_DBA25_Msk         (0x1UL << TDM_TDM_DBA_ADDRESS_DBA25_Pos)      /*!< 0x02000000 */
#define TDM_TDM_DBA_ADDRESS_DBA25             TDM_TDM_DBA_ADDRESS_DBA25_Msk     /*!< </spirit:description> */
#define TDM_TDM_DBA_ADDRESS_DBA26_Pos         (26U)
#define TDM_TDM_DBA_ADDRESS_DBA26_Msk         (0x1UL << TDM_TDM_DBA_ADDRESS_DBA26_Pos)      /*!< 0x04000000 */
#define TDM_TDM_DBA_ADDRESS_DBA26             TDM_TDM_DBA_ADDRESS_DBA26_Msk     /*!< </spirit:description> */
#define TDM_TDM_DBA_ADDRESS_DBA27_Pos         (27U)
#define TDM_TDM_DBA_ADDRESS_DBA27_Msk         (0x1UL << TDM_TDM_DBA_ADDRESS_DBA27_Pos)      /*!< 0x08000000 */
#define TDM_TDM_DBA_ADDRESS_DBA27             TDM_TDM_DBA_ADDRESS_DBA27_Msk     /*!< </spirit:description> */
#define TDM_TDM_DBA_ADDRESS_DBA28_Pos         (28U)
#define TDM_TDM_DBA_ADDRESS_DBA28_Msk         (0x1UL << TDM_TDM_DBA_ADDRESS_DBA28_Pos)      /*!< 0x10000000 */
#define TDM_TDM_DBA_ADDRESS_DBA28             TDM_TDM_DBA_ADDRESS_DBA28_Msk     /*!< </spirit:description> */
#define TDM_TDM_DBA_ADDRESS_DBA29_Pos         (29U)
#define TDM_TDM_DBA_ADDRESS_DBA29_Msk         (0x1UL << TDM_TDM_DBA_ADDRESS_DBA29_Pos)      /*!< 0x20000000 */
#define TDM_TDM_DBA_ADDRESS_DBA29             TDM_TDM_DBA_ADDRESS_DBA29_Msk     /*!< </spirit:description> */
#define TDM_TDM_DBA_ADDRESS_DBA30_Pos         (30U)
#define TDM_TDM_DBA_ADDRESS_DBA30_Msk         (0x1UL << TDM_TDM_DBA_ADDRESS_DBA30_Pos)      /*!< 0x40000000 */
#define TDM_TDM_DBA_ADDRESS_DBA30             TDM_TDM_DBA_ADDRESS_DBA30_Msk     /*!< </spirit:description> */
#define TDM_TDM_DBA_ADDRESS_DBA31_Pos         (31U)
#define TDM_TDM_DBA_ADDRESS_DBA31_Msk         (0x1UL << TDM_TDM_DBA_ADDRESS_DBA31_Pos)      /*!< 0x80000000 */
#define TDM_TDM_DBA_ADDRESS_DBA31             TDM_TDM_DBA_ADDRESS_DBA31_Msk     /*!< </spirit:description> */

/***************  Bit definition for TDM_TDM_STO_KEY0 register  ***************/
#define TDM_TDM_STO_KEY0_STO_KEY_0_Pos        (0U)
#define TDM_TDM_STO_KEY0_STO_KEY_0_Msk        (0xFFFFFFFFUL << TDM_TDM_STO_KEY0_STO_KEY_0_Pos)              /*!< 0xFFFFFFFF */
#define TDM_TDM_STO_KEY0_STO_KEY_0            TDM_TDM_STO_KEY0_STO_KEY_0_Msk    /*!< </spirit:description> */

/***************  Bit definition for TDM_TDM_STO_KEY1 register  ***************/
#define TDM_TDM_STO_KEY1_STO_KEY_1_Pos        (0U)
#define TDM_TDM_STO_KEY1_STO_KEY_1_Msk        (0xFFFFFFFFUL << TDM_TDM_STO_KEY1_STO_KEY_1_Pos)              /*!< 0xFFFFFFFF */
#define TDM_TDM_STO_KEY1_STO_KEY_1            TDM_TDM_STO_KEY1_STO_KEY_1_Msk    /*!< </spirit:description> */

/***************  Bit definition for TDM_TDM_STO_KEY2 register  ***************/
#define TDM_TDM_STO_KEY2_STO_KEY_2_Pos        (0U)
#define TDM_TDM_STO_KEY2_STO_KEY_2_Msk        (0xFFFFFFFFUL << TDM_TDM_STO_KEY2_STO_KEY_2_Pos)              /*!< 0xFFFFFFFF */
#define TDM_TDM_STO_KEY2_STO_KEY_2            TDM_TDM_STO_KEY2_STO_KEY_2_Msk    /*!< </spirit:description> */

/***************  Bit definition for TDM_TDM_STO_KEY3 register  ***************/
#define TDM_TDM_STO_KEY3_STO_KEY_3_Pos        (0U)
#define TDM_TDM_STO_KEY3_STO_KEY_3_Msk        (0xFFFFFFFFUL << TDM_TDM_STO_KEY3_STO_KEY_3_Pos)              /*!< 0xFFFFFFFF */
#define TDM_TDM_STO_KEY3_STO_KEY_3            TDM_TDM_STO_KEY3_STO_KEY_3_Msk    /*!< </spirit:description> */

/***************  Bit definition for TDM_TDM_STO_KEY4 register  ***************/
#define TDM_TDM_STO_KEY4_STO_KEY_4_Pos        (0U)
#define TDM_TDM_STO_KEY4_STO_KEY_4_Msk        (0xFFFFFFFFUL << TDM_TDM_STO_KEY4_STO_KEY_4_Pos)              /*!< 0xFFFFFFFF */
#define TDM_TDM_STO_KEY4_STO_KEY_4            TDM_TDM_STO_KEY4_STO_KEY_4_Msk    /*!< </spirit:description> */

/***************  Bit definition for TDM_TDM_STO_KEY5 register  ***************/
#define TDM_TDM_STO_KEY5_STO_KEY_5_Pos        (0U)
#define TDM_TDM_STO_KEY5_STO_KEY_5_Msk        (0xFFFFFFFFUL << TDM_TDM_STO_KEY5_STO_KEY_5_Pos)              /*!< 0xFFFFFFFF */
#define TDM_TDM_STO_KEY5_STO_KEY_5            TDM_TDM_STO_KEY5_STO_KEY_5_Msk    /*!< </spirit:description> */

#define TDM_BASE           0x4001F400UL 


#define TDM                ((TDM_TypeDef *) TDM_BASE) 


#endif /* __SR5E1_TDM_H */

