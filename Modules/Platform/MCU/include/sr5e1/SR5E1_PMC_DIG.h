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

#ifndef __SR5E1_PMC_DIG_H
#define __SR5E1_PMC_DIG_H

/******************************************************************************/
/*                                                                            */
/*                             PMC_DIG (PMC_DIG)                              */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO uint32_t EPR_LV0;            /*!< EPR_LV0           Address offset: 0x000 */
  __IO uint32_t REE_LV0;            /*!< REE_LV0           Address offset: 0x004 */
  __IO uint32_t RES_LV0;            /*!< RES_LV0           Address offset: 0x008 */
  __IO uint32_t IE_LV0;             /*!< IE_LV0            Address offset: 0x00C */
  __IO uint32_t FEE_LV0;            /*!< FEE_LV0           Address offset: 0x010 */
       uint32_t RESERVED0[3];       /*!< Reserved          Address offset: 0x014-0x01C */
  __IO uint32_t EPR_LV1;            /*!< EPR_LV1           Address offset: 0x020 */
  __IO uint32_t REE_LV1;            /*!< REE_LV1           Address offset: 0x024 */
  __IO uint32_t RES_LV1;            /*!< RES_LV1           Address offset: 0x028 */
  __IO uint32_t IE_LV1;             /*!< IE_LV1            Address offset: 0x02C */
  __IO uint32_t FEE_LV1;            /*!< FEE_LV1           Address offset: 0x030 */
       uint32_t RESERVED1[3];       /*!< Reserved          Address offset: 0x034-0x03C */
  __IO uint32_t EPR_HV0;            /*!< EPR_HV0           Address offset: 0x040 */
  __IO uint32_t REE_HV0;            /*!< REE_HV0           Address offset: 0x044 */
  __IO uint32_t RES_HV0;            /*!< RES_HV0           Address offset: 0x048 */
  __IO uint32_t IE_HV0;             /*!< IE_HV0            Address offset: 0x04C */
  __IO uint32_t FEE_HV0;            /*!< FEE_HV0           Address offset: 0x050 */
       uint32_t RESERVED2[11];      /*!< Reserved          Address offset: 0x054-0x07C */
  __IO uint32_t GR_S;               /*!< GR_S              Address offset: 0x080 */
  __IO uint32_t GR_P;               /*!< GR_P              Address offset: 0x084 */
  __IO uint32_t IE_G;               /*!< IE_G              Address offset: 0x088 */
       uint32_t RESERVED3[110];     /*!< Reserved          Address offset: 0x08C-0x240 */
  __IO uint32_t HPREG_SMPS_SEL_S;   /*!< HPREG_SMPS_SEL_S  Address offset: 0x244 */
       uint32_t RESERVED4[46];      /*!< Reserved          Address offset: 0x248-0x2FC */
  __IO uint32_t EPR_TD;             /*!< EPR_TD            Address offset: 0x300 */
  __IO uint32_t REE_TD;             /*!< REE_TD            Address offset: 0x304 */
  __IO uint32_t RES_TD;             /*!< RES_TD            Address offset: 0x308 */
  __IO uint32_t CTL_TD;             /*!< CTL_TD            Address offset: 0x30C */
       uint32_t RESERVED5[2];       /*!< Reserved          Address offset: 0x310-0x314 */
  __IO uint32_t FEE_TD;             /*!< FEE_TD            Address offset: 0x318 */
       uint32_t RESERVED6[2];       /*!< Reserved          Address offset: 0x31C-0x320 */
  __IO uint32_t ESR0_CFG;           /*!< ESR0_CFG          Address offset: 0x324 */
       uint32_t RESERVED7[40];      /*!< Reserved          Address offset: 0x328-0x3C4 */
  __IO uint32_t BIST_MASK_STATUS;   /*!< BIST_MASK_STATUS  Address offset: 0x3C8 */
  __IO uint32_t BIST_FLAGS_PHASE1;  /*!< BIST_FLAGS_PHASE1 Address offset: 0x3CC */
  __IO uint32_t BIST_FLAGS_PHASE2;  /*!< BIST_FLAGS_PHASE2 Address offset: 0x3D0 */
  __IO uint32_t BIST_CTRL;          /*!< BIST_CTRL         Address offset: 0x3D4 */
  __IO uint32_t BIST_TIME10;        /*!< BIST_TIME10       Address offset: 0x3D8 */
  __IO uint32_t BIST_TIME32;        /*!< BIST_TIME32       Address offset: 0x3DC */
  __IO uint32_t BIST_TIME65;        /*!< BIST_TIME65       Address offset: 0x3E0 */
  __IO uint32_t BIST_DEBUG;         /*!< BIST_DEBUG        Address offset: 0x3E4 */
} PMC_DIG_TypeDef;


/***************  Bit definition for PMC_DIG_EPR_LV0 register  ****************/
#define PMC_DIG_EPR_LV0_LVD3_C_Pos                     (24U)
#define PMC_DIG_EPR_LV0_LVD3_C_Msk                     (0x1UL << PMC_DIG_EPR_LV0_LVD3_C_Pos)                /*!< 0x01000000 */
#define PMC_DIG_EPR_LV0_LVD3_C                         PMC_DIG_EPR_LV0_LVD3_C_Msk                          /*!< </spirit:description> */
#define PMC_DIG_EPR_LV0_LVD3_FL_Pos                    (26U)
#define PMC_DIG_EPR_LV0_LVD3_FL_Msk                    (0x1UL << PMC_DIG_EPR_LV0_LVD3_FL_Pos)               /*!< 0x04000000 */
#define PMC_DIG_EPR_LV0_LVD3_FL                        PMC_DIG_EPR_LV0_LVD3_FL_Msk                         /*!< </spirit:description> */
#define PMC_DIG_EPR_LV0_LVD3_DD_Pos                    (27U)
#define PMC_DIG_EPR_LV0_LVD3_DD_Msk                    (0x1UL << PMC_DIG_EPR_LV0_LVD3_DD_Pos)               /*!< 0x08000000 */
#define PMC_DIG_EPR_LV0_LVD3_DD                        PMC_DIG_EPR_LV0_LVD3_DD_Msk                         /*!< </spirit:description> */
#define PMC_DIG_EPR_LV0_LVD3_RC_Pos                    (29U)
#define PMC_DIG_EPR_LV0_LVD3_RC_Msk                    (0x1UL << PMC_DIG_EPR_LV0_LVD3_RC_Pos)               /*!< 0x20000000 */
#define PMC_DIG_EPR_LV0_LVD3_RC                        PMC_DIG_EPR_LV0_LVD3_RC_Msk                         /*!< </spirit:description> */
#define PMC_DIG_EPR_LV0_LVD3_PLL0_Pos                  (30U)
#define PMC_DIG_EPR_LV0_LVD3_PLL0_Msk                  (0x1UL << PMC_DIG_EPR_LV0_LVD3_PLL0_Pos)             /*!< 0x40000000 */
#define PMC_DIG_EPR_LV0_LVD3_PLL0                      PMC_DIG_EPR_LV0_LVD3_PLL0_Msk                       /*!< </spirit:description> */
#define PMC_DIG_EPR_LV0_LVD3_PLL1_Pos                  (31U)
#define PMC_DIG_EPR_LV0_LVD3_PLL1_Msk                  (0x1UL << PMC_DIG_EPR_LV0_LVD3_PLL1_Pos)             /*!< 0x80000000 */
#define PMC_DIG_EPR_LV0_LVD3_PLL1                      PMC_DIG_EPR_LV0_LVD3_PLL1_Msk                       /*!< </spirit:description> */

/***************  Bit definition for PMC_DIG_REE_LV0 register  ****************/
#define PMC_DIG_REE_LV0_REE3_C_Pos                     (24U)
#define PMC_DIG_REE_LV0_REE3_C_Msk                     (0x1UL << PMC_DIG_REE_LV0_REE3_C_Pos)                /*!< 0x01000000 */
#define PMC_DIG_REE_LV0_REE3_C                         PMC_DIG_REE_LV0_REE3_C_Msk                          /*!< </spirit:description> */
#define PMC_DIG_REE_LV0_REE3_FL_Pos                    (26U)
#define PMC_DIG_REE_LV0_REE3_FL_Msk                    (0x1UL << PMC_DIG_REE_LV0_REE3_FL_Pos)               /*!< 0x04000000 */
#define PMC_DIG_REE_LV0_REE3_FL                        PMC_DIG_REE_LV0_REE3_FL_Msk                         /*!< </spirit:description> */
#define PMC_DIG_REE_LV0_REE3_DD_Pos                    (27U)
#define PMC_DIG_REE_LV0_REE3_DD_Msk                    (0x1UL << PMC_DIG_REE_LV0_REE3_DD_Pos)               /*!< 0x08000000 */
#define PMC_DIG_REE_LV0_REE3_DD                        PMC_DIG_REE_LV0_REE3_DD_Msk                         /*!< </spirit:description> */
#define PMC_DIG_REE_LV0_REE3_RC_Pos                    (29U)
#define PMC_DIG_REE_LV0_REE3_RC_Msk                    (0x1UL << PMC_DIG_REE_LV0_REE3_RC_Pos)               /*!< 0x20000000 */
#define PMC_DIG_REE_LV0_REE3_RC                        PMC_DIG_REE_LV0_REE3_RC_Msk                         /*!< </spirit:description> */
#define PMC_DIG_REE_LV0_REE3_PLL0_Pos                  (30U)
#define PMC_DIG_REE_LV0_REE3_PLL0_Msk                  (0x1UL << PMC_DIG_REE_LV0_REE3_PLL0_Pos)             /*!< 0x40000000 */
#define PMC_DIG_REE_LV0_REE3_PLL0                      PMC_DIG_REE_LV0_REE3_PLL0_Msk                       /*!< </spirit:description> */
#define PMC_DIG_REE_LV0_REE3_PLL1_Pos                  (31U)
#define PMC_DIG_REE_LV0_REE3_PLL1_Msk                  (0x1UL << PMC_DIG_REE_LV0_REE3_PLL1_Pos)             /*!< 0x80000000 */
#define PMC_DIG_REE_LV0_REE3_PLL1                      PMC_DIG_REE_LV0_REE3_PLL1_Msk                       /*!< </spirit:description> */

/***************  Bit definition for PMC_DIG_RES_LV0 register  ****************/
#define PMC_DIG_RES_LV0_RES3_C_Pos                     (24U)
#define PMC_DIG_RES_LV0_RES3_C_Msk                     (0x1UL << PMC_DIG_RES_LV0_RES3_C_Pos)                /*!< 0x01000000 */
#define PMC_DIG_RES_LV0_RES3_C                         PMC_DIG_RES_LV0_RES3_C_Msk                          /*!< </spirit:description> */
#define PMC_DIG_RES_LV0_RES3_FL_Pos                    (26U)
#define PMC_DIG_RES_LV0_RES3_FL_Msk                    (0x1UL << PMC_DIG_RES_LV0_RES3_FL_Pos)               /*!< 0x04000000 */
#define PMC_DIG_RES_LV0_RES3_FL                        PMC_DIG_RES_LV0_RES3_FL_Msk                         /*!< </spirit:description> */
#define PMC_DIG_RES_LV0_RES3_DD_Pos                    (27U)
#define PMC_DIG_RES_LV0_RES3_DD_Msk                    (0x1UL << PMC_DIG_RES_LV0_RES3_DD_Pos)               /*!< 0x08000000 */
#define PMC_DIG_RES_LV0_RES3_DD                        PMC_DIG_RES_LV0_RES3_DD_Msk                         /*!< </spirit:description> */
#define PMC_DIG_RES_LV0_RES3_RC_Pos                    (29U)
#define PMC_DIG_RES_LV0_RES3_RC_Msk                    (0x1UL << PMC_DIG_RES_LV0_RES3_RC_Pos)               /*!< 0x20000000 */
#define PMC_DIG_RES_LV0_RES3_RC                        PMC_DIG_RES_LV0_RES3_RC_Msk                         /*!< </spirit:description> */
#define PMC_DIG_RES_LV0_RES3_PLL0_Pos                  (30U)
#define PMC_DIG_RES_LV0_RES3_PLL0_Msk                  (0x1UL << PMC_DIG_RES_LV0_RES3_PLL0_Pos)             /*!< 0x40000000 */
#define PMC_DIG_RES_LV0_RES3_PLL0                      PMC_DIG_RES_LV0_RES3_PLL0_Msk                       /*!< </spirit:description> */
#define PMC_DIG_RES_LV0_RES3_PLL1_Pos                  (31U)
#define PMC_DIG_RES_LV0_RES3_PLL1_Msk                  (0x1UL << PMC_DIG_RES_LV0_RES3_PLL1_Pos)             /*!< 0x80000000 */
#define PMC_DIG_RES_LV0_RES3_PLL1                      PMC_DIG_RES_LV0_RES3_PLL1_Msk                       /*!< </spirit:description> */

/****************  Bit definition for PMC_DIG_IE_LV0 register  ****************/
#define PMC_DIG_IE_LV0_VD3IE_C_Pos                     (24U)
#define PMC_DIG_IE_LV0_VD3IE_C_Msk                     (0x1UL << PMC_DIG_IE_LV0_VD3IE_C_Pos)                /*!< 0x01000000 */
#define PMC_DIG_IE_LV0_VD3IE_C                         PMC_DIG_IE_LV0_VD3IE_C_Msk                          /*!< </spirit:description> */
#define PMC_DIG_IE_LV0_VD3IE_FL_Pos                    (26U)
#define PMC_DIG_IE_LV0_VD3IE_FL_Msk                    (0x1UL << PMC_DIG_IE_LV0_VD3IE_FL_Pos)               /*!< 0x04000000 */
#define PMC_DIG_IE_LV0_VD3IE_FL                        PMC_DIG_IE_LV0_VD3IE_FL_Msk                         /*!< </spirit:description> */
#define PMC_DIG_IE_LV0_VD3IE_DD_Pos                    (27U)
#define PMC_DIG_IE_LV0_VD3IE_DD_Msk                    (0x1UL << PMC_DIG_IE_LV0_VD3IE_DD_Pos)               /*!< 0x08000000 */
#define PMC_DIG_IE_LV0_VD3IE_DD                        PMC_DIG_IE_LV0_VD3IE_DD_Msk                         /*!< </spirit:description> */
#define PMC_DIG_IE_LV0_VD3IE_RC_Pos                    (29U)
#define PMC_DIG_IE_LV0_VD3IE_RC_Msk                    (0x1UL << PMC_DIG_IE_LV0_VD3IE_RC_Pos)               /*!< 0x20000000 */
#define PMC_DIG_IE_LV0_VD3IE_RC                        PMC_DIG_IE_LV0_VD3IE_RC_Msk                         /*!< </spirit:description> */
#define PMC_DIG_IE_LV0_VD3IE_PLL0_Pos                  (30U)
#define PMC_DIG_IE_LV0_VD3IE_PLL0_Msk                  (0x1UL << PMC_DIG_IE_LV0_VD3IE_PLL0_Pos)             /*!< 0x40000000 */
#define PMC_DIG_IE_LV0_VD3IE_PLL0                      PMC_DIG_IE_LV0_VD3IE_PLL0_Msk                       /*!< </spirit:description> */
#define PMC_DIG_IE_LV0_VD3IE_PLL1_Pos                  (31U)
#define PMC_DIG_IE_LV0_VD3IE_PLL1_Msk                  (0x1UL << PMC_DIG_IE_LV0_VD3IE_PLL1_Pos)             /*!< 0x80000000 */
#define PMC_DIG_IE_LV0_VD3IE_PLL1                      PMC_DIG_IE_LV0_VD3IE_PLL1_Msk                       /*!< </spirit:description> */

/***************  Bit definition for PMC_DIG_FEE_LV0 register  ****************/
#define PMC_DIG_FEE_LV0_FEE3_C_Pos                     (24U)
#define PMC_DIG_FEE_LV0_FEE3_C_Msk                     (0x1UL << PMC_DIG_FEE_LV0_FEE3_C_Pos)                /*!< 0x01000000 */
#define PMC_DIG_FEE_LV0_FEE3_C                         PMC_DIG_FEE_LV0_FEE3_C_Msk                          /*!< </spirit:description> */
#define PMC_DIG_FEE_LV0_FEE3_FL_Pos                    (26U)
#define PMC_DIG_FEE_LV0_FEE3_FL_Msk                    (0x1UL << PMC_DIG_FEE_LV0_FEE3_FL_Pos)               /*!< 0x04000000 */
#define PMC_DIG_FEE_LV0_FEE3_FL                        PMC_DIG_FEE_LV0_FEE3_FL_Msk                         /*!< </spirit:description> */
#define PMC_DIG_FEE_LV0_FEE3_DD_Pos                    (27U)
#define PMC_DIG_FEE_LV0_FEE3_DD_Msk                    (0x1UL << PMC_DIG_FEE_LV0_FEE3_DD_Pos)               /*!< 0x08000000 */
#define PMC_DIG_FEE_LV0_FEE3_DD                        PMC_DIG_FEE_LV0_FEE3_DD_Msk                         /*!< </spirit:description> */
#define PMC_DIG_FEE_LV0_FEE3_RC_Pos                    (29U)
#define PMC_DIG_FEE_LV0_FEE3_RC_Msk                    (0x1UL << PMC_DIG_FEE_LV0_FEE3_RC_Pos)               /*!< 0x20000000 */
#define PMC_DIG_FEE_LV0_FEE3_RC                        PMC_DIG_FEE_LV0_FEE3_RC_Msk                         /*!< </spirit:description> */
#define PMC_DIG_FEE_LV0_FEE3_PLL0_Pos                  (30U)
#define PMC_DIG_FEE_LV0_FEE3_PLL0_Msk                  (0x1UL << PMC_DIG_FEE_LV0_FEE3_PLL0_Pos)             /*!< 0x40000000 */
#define PMC_DIG_FEE_LV0_FEE3_PLL0                      PMC_DIG_FEE_LV0_FEE3_PLL0_Msk                       /*!< </spirit:description> */
#define PMC_DIG_FEE_LV0_FEE3_PLL1_Pos                  (31U)
#define PMC_DIG_FEE_LV0_FEE3_PLL1_Msk                  (0x1UL << PMC_DIG_FEE_LV0_FEE3_PLL1_Pos)             /*!< 0x80000000 */
#define PMC_DIG_FEE_LV0_FEE3_PLL1                      PMC_DIG_FEE_LV0_FEE3_PLL1_Msk                       /*!< </spirit:description> */

/***************  Bit definition for PMC_DIG_EPR_LV1 register  ****************/
#define PMC_DIG_EPR_LV1_HVD6_C_Pos                     (16U)
#define PMC_DIG_EPR_LV1_HVD6_C_Msk                     (0x1UL << PMC_DIG_EPR_LV1_HVD6_C_Pos)                /*!< 0x00010000 */
#define PMC_DIG_EPR_LV1_HVD6_C                         PMC_DIG_EPR_LV1_HVD6_C_Msk                          /*!< </spirit:description> */
#define PMC_DIG_EPR_LV1_UVD7_RC_Pos                    (29U)
#define PMC_DIG_EPR_LV1_UVD7_RC_Msk                    (0x1UL << PMC_DIG_EPR_LV1_UVD7_RC_Pos)               /*!< 0x20000000 */
#define PMC_DIG_EPR_LV1_UVD7_RC                        PMC_DIG_EPR_LV1_UVD7_RC_Msk                         /*!< </spirit:description> */

/***************  Bit definition for PMC_DIG_REE_LV1 register  ****************/
#define PMC_DIG_REE_LV1_REE6_C_Pos                     (16U)
#define PMC_DIG_REE_LV1_REE6_C_Msk                     (0x1UL << PMC_DIG_REE_LV1_REE6_C_Pos)                /*!< 0x00010000 */
#define PMC_DIG_REE_LV1_REE6_C                         PMC_DIG_REE_LV1_REE6_C_Msk                          /*!< </spirit:description> */
#define PMC_DIG_REE_LV1_REE7_RC_Pos                    (29U)
#define PMC_DIG_REE_LV1_REE7_RC_Msk                    (0x1UL << PMC_DIG_REE_LV1_REE7_RC_Pos)               /*!< 0x20000000 */
#define PMC_DIG_REE_LV1_REE7_RC                        PMC_DIG_REE_LV1_REE7_RC_Msk                         /*!< </spirit:description> */

/***************  Bit definition for PMC_DIG_RES_LV1 register  ****************/
#define PMC_DIG_RES_LV1_RES6_C_Pos                     (16U)
#define PMC_DIG_RES_LV1_RES6_C_Msk                     (0x1UL << PMC_DIG_RES_LV1_RES6_C_Pos)                /*!< 0x00010000 */
#define PMC_DIG_RES_LV1_RES6_C                         PMC_DIG_RES_LV1_RES6_C_Msk                          /*!< </spirit:description> */
#define PMC_DIG_RES_LV1_RES7_RC_Pos                    (29U)
#define PMC_DIG_RES_LV1_RES7_RC_Msk                    (0x1UL << PMC_DIG_RES_LV1_RES7_RC_Pos)               /*!< 0x20000000 */
#define PMC_DIG_RES_LV1_RES7_RC                        PMC_DIG_RES_LV1_RES7_RC_Msk                         /*!< </spirit:description> */

/****************  Bit definition for PMC_DIG_IE_LV1 register  ****************/
#define PMC_DIG_IE_LV1_HVD6IE_C_Pos                    (16U)
#define PMC_DIG_IE_LV1_HVD6IE_C_Msk                    (0x1UL << PMC_DIG_IE_LV1_HVD6IE_C_Pos)               /*!< 0x00010000 */
#define PMC_DIG_IE_LV1_HVD6IE_C                        PMC_DIG_IE_LV1_HVD6IE_C_Msk                         /*!< </spirit:description> */
#define PMC_DIG_IE_LV1_UVD7IE_RC_Pos                   (29U)
#define PMC_DIG_IE_LV1_UVD7IE_RC_Msk                   (0x1UL << PMC_DIG_IE_LV1_UVD7IE_RC_Pos)              /*!< 0x20000000 */
#define PMC_DIG_IE_LV1_UVD7IE_RC                       PMC_DIG_IE_LV1_UVD7IE_RC_Msk                        /*!< </spirit:description> */

/***************  Bit definition for PMC_DIG_FEE_LV1 register  ****************/
#define PMC_DIG_FEE_LV1_FEE6_C_Pos                     (16U)
#define PMC_DIG_FEE_LV1_FEE6_C_Msk                     (0x1UL << PMC_DIG_FEE_LV1_FEE6_C_Pos)                /*!< 0x00010000 */
#define PMC_DIG_FEE_LV1_FEE6_C                         PMC_DIG_FEE_LV1_FEE6_C_Msk                          /*!< </spirit:description> */
#define PMC_DIG_FEE_LV1_FEE7_RC_Pos                    (29U)
#define PMC_DIG_FEE_LV1_FEE7_RC_Msk                    (0x1UL << PMC_DIG_FEE_LV1_FEE7_RC_Pos)               /*!< 0x20000000 */
#define PMC_DIG_FEE_LV1_FEE7_RC                        PMC_DIG_FEE_LV1_FEE7_RC_Msk                         /*!< </spirit:description> */

/***************  Bit definition for PMC_DIG_EPR_HV0 register  ****************/
#define PMC_DIG_EPR_HV0_LVD11_DACCMP_Pos               (16U)
#define PMC_DIG_EPR_HV0_LVD11_DACCMP_Msk               (0x1UL << PMC_DIG_EPR_HV0_LVD11_DACCMP_Pos)          /*!< 0x00010000 */
#define PMC_DIG_EPR_HV0_LVD11_DACCMP                   PMC_DIG_EPR_HV0_LVD11_DACCMP_Msk                    /*!< </spirit:description> */
#define PMC_DIG_EPR_HV0_LVD11_OSC_Pos                  (17U)
#define PMC_DIG_EPR_HV0_LVD11_OSC_Msk                  (0x1UL << PMC_DIG_EPR_HV0_LVD11_OSC_Pos)             /*!< 0x00020000 */
#define PMC_DIG_EPR_HV0_LVD11_OSC                      PMC_DIG_EPR_HV0_LVD11_OSC_Msk                       /*!< </spirit:description> */
#define PMC_DIG_EPR_HV0_UVD15_AS_Pos                   (18U)
#define PMC_DIG_EPR_HV0_UVD15_AS_Msk                   (0x1UL << PMC_DIG_EPR_HV0_UVD15_AS_Pos)              /*!< 0x00040000 */
#define PMC_DIG_EPR_HV0_UVD15_AS                       PMC_DIG_EPR_HV0_UVD15_AS_Msk                        /*!< </spirit:description> */
#define PMC_DIG_EPR_HV0_UVD15_DACCMP_Pos               (19U)
#define PMC_DIG_EPR_HV0_UVD15_DACCMP_Msk               (0x1UL << PMC_DIG_EPR_HV0_UVD15_DACCMP_Pos)          /*!< 0x00080000 */
#define PMC_DIG_EPR_HV0_UVD15_DACCMP                   PMC_DIG_EPR_HV0_UVD15_DACCMP_Msk                    /*!< </spirit:description> */
#define PMC_DIG_EPR_HV0_LVD11_C_Pos                    (24U)
#define PMC_DIG_EPR_HV0_LVD11_C_Msk                    (0x1UL << PMC_DIG_EPR_HV0_LVD11_C_Pos)               /*!< 0x01000000 */
#define PMC_DIG_EPR_HV0_LVD11_C                        PMC_DIG_EPR_HV0_LVD11_C_Msk                         /*!< </spirit:description> */
#define PMC_DIG_EPR_HV0_LVD11_FL_Pos                   (25U)
#define PMC_DIG_EPR_HV0_LVD11_FL_Msk                   (0x1UL << PMC_DIG_EPR_HV0_LVD11_FL_Pos)              /*!< 0x02000000 */
#define PMC_DIG_EPR_HV0_LVD11_FL                       PMC_DIG_EPR_HV0_LVD11_FL_Msk                        /*!< </spirit:description> */
#define PMC_DIG_EPR_HV0_LVD11_IO1_Pos                  (27U)
#define PMC_DIG_EPR_HV0_LVD11_IO1_Msk                  (0x1UL << PMC_DIG_EPR_HV0_LVD11_IO1_Pos)             /*!< 0x08000000 */
#define PMC_DIG_EPR_HV0_LVD11_IO1                      PMC_DIG_EPR_HV0_LVD11_IO1_Msk                       /*!< </spirit:description> */
#define PMC_DIG_EPR_HV0_LVD11_IO0_Pos                  (28U)
#define PMC_DIG_EPR_HV0_LVD11_IO0_Msk                  (0x1UL << PMC_DIG_EPR_HV0_LVD11_IO0_Pos)             /*!< 0x10000000 */
#define PMC_DIG_EPR_HV0_LVD11_IO0                      PMC_DIG_EPR_HV0_LVD11_IO0_Msk                       /*!< </spirit:description> */
#define PMC_DIG_EPR_HV0_LVD11_AS_Pos                   (29U)
#define PMC_DIG_EPR_HV0_LVD11_AS_Msk                   (0x1UL << PMC_DIG_EPR_HV0_LVD11_AS_Pos)              /*!< 0x20000000 */
#define PMC_DIG_EPR_HV0_LVD11_AS                       PMC_DIG_EPR_HV0_LVD11_AS_Msk                        /*!< </spirit:description> */
#define PMC_DIG_EPR_HV0_LVD11_AD_Pos                   (30U)
#define PMC_DIG_EPR_HV0_LVD11_AD_Msk                   (0x1UL << PMC_DIG_EPR_HV0_LVD11_AD_Pos)              /*!< 0x40000000 */
#define PMC_DIG_EPR_HV0_LVD11_AD                       PMC_DIG_EPR_HV0_LVD11_AD_Msk                        /*!< </spirit:description> */

/***************  Bit definition for PMC_DIG_REE_HV0 register  ****************/
#define PMC_DIG_REE_HV0_REE11_DACCMP_Pos               (16U)
#define PMC_DIG_REE_HV0_REE11_DACCMP_Msk               (0x1UL << PMC_DIG_REE_HV0_REE11_DACCMP_Pos)          /*!< 0x00010000 */
#define PMC_DIG_REE_HV0_REE11_DACCMP                   PMC_DIG_REE_HV0_REE11_DACCMP_Msk                    /*!< </spirit:description> */
#define PMC_DIG_REE_HV0_REE11_OSC_Pos                  (17U)
#define PMC_DIG_REE_HV0_REE11_OSC_Msk                  (0x1UL << PMC_DIG_REE_HV0_REE11_OSC_Pos)             /*!< 0x00020000 */
#define PMC_DIG_REE_HV0_REE11_OSC                      PMC_DIG_REE_HV0_REE11_OSC_Msk                       /*!< </spirit:description> */
#define PMC_DIG_REE_HV0_REE15_AS_Pos                   (18U)
#define PMC_DIG_REE_HV0_REE15_AS_Msk                   (0x1UL << PMC_DIG_REE_HV0_REE15_AS_Pos)              /*!< 0x00040000 */
#define PMC_DIG_REE_HV0_REE15_AS                       PMC_DIG_REE_HV0_REE15_AS_Msk                        /*!< </spirit:description> */
#define PMC_DIG_REE_HV0_REE15_DACCMP_Pos               (19U)
#define PMC_DIG_REE_HV0_REE15_DACCMP_Msk               (0x1UL << PMC_DIG_REE_HV0_REE15_DACCMP_Pos)          /*!< 0x00080000 */
#define PMC_DIG_REE_HV0_REE15_DACCMP                   PMC_DIG_REE_HV0_REE15_DACCMP_Msk                    /*!< </spirit:description> */
#define PMC_DIG_REE_HV0_REE11_C_Pos                    (24U)
#define PMC_DIG_REE_HV0_REE11_C_Msk                    (0x1UL << PMC_DIG_REE_HV0_REE11_C_Pos)               /*!< 0x01000000 */
#define PMC_DIG_REE_HV0_REE11_C                        PMC_DIG_REE_HV0_REE11_C_Msk                         /*!< </spirit:description> */
#define PMC_DIG_REE_HV0_REE11_FL_Pos                   (25U)
#define PMC_DIG_REE_HV0_REE11_FL_Msk                   (0x1UL << PMC_DIG_REE_HV0_REE11_FL_Pos)              /*!< 0x02000000 */
#define PMC_DIG_REE_HV0_REE11_FL                       PMC_DIG_REE_HV0_REE11_FL_Msk                        /*!< </spirit:description> */
#define PMC_DIG_REE_HV0_REE11_IO1_Pos                  (27U)
#define PMC_DIG_REE_HV0_REE11_IO1_Msk                  (0x1UL << PMC_DIG_REE_HV0_REE11_IO1_Pos)             /*!< 0x08000000 */
#define PMC_DIG_REE_HV0_REE11_IO1                      PMC_DIG_REE_HV0_REE11_IO1_Msk                       /*!< </spirit:description> */
#define PMC_DIG_REE_HV0_REE11_IO0_Pos                  (28U)
#define PMC_DIG_REE_HV0_REE11_IO0_Msk                  (0x1UL << PMC_DIG_REE_HV0_REE11_IO0_Pos)             /*!< 0x10000000 */
#define PMC_DIG_REE_HV0_REE11_IO0                      PMC_DIG_REE_HV0_REE11_IO0_Msk                       /*!< </spirit:description> */
#define PMC_DIG_REE_HV0_REE11_AS_Pos                   (29U)
#define PMC_DIG_REE_HV0_REE11_AS_Msk                   (0x1UL << PMC_DIG_REE_HV0_REE11_AS_Pos)              /*!< 0x20000000 */
#define PMC_DIG_REE_HV0_REE11_AS                       PMC_DIG_REE_HV0_REE11_AS_Msk                        /*!< </spirit:description> */
#define PMC_DIG_REE_HV0_REE11_AD_Pos                   (30U)
#define PMC_DIG_REE_HV0_REE11_AD_Msk                   (0x1UL << PMC_DIG_REE_HV0_REE11_AD_Pos)              /*!< 0x40000000 */
#define PMC_DIG_REE_HV0_REE11_AD                       PMC_DIG_REE_HV0_REE11_AD_Msk                        /*!< </spirit:description> */

/***************  Bit definition for PMC_DIG_RES_HV0 register  ****************/
#define PMC_DIG_RES_HV0_RES11_DACCMP_Pos               (16U)
#define PMC_DIG_RES_HV0_RES11_DACCMP_Msk               (0x1UL << PMC_DIG_RES_HV0_RES11_DACCMP_Pos)          /*!< 0x00010000 */
#define PMC_DIG_RES_HV0_RES11_DACCMP                   PMC_DIG_RES_HV0_RES11_DACCMP_Msk                    /*!< </spirit:description> */
#define PMC_DIG_RES_HV0_RES11_OSC_Pos                  (17U)
#define PMC_DIG_RES_HV0_RES11_OSC_Msk                  (0x1UL << PMC_DIG_RES_HV0_RES11_OSC_Pos)             /*!< 0x00020000 */
#define PMC_DIG_RES_HV0_RES11_OSC                      PMC_DIG_RES_HV0_RES11_OSC_Msk                       /*!< </spirit:description> */
#define PMC_DIG_RES_HV0_RES15_AS_Pos                   (18U)
#define PMC_DIG_RES_HV0_RES15_AS_Msk                   (0x1UL << PMC_DIG_RES_HV0_RES15_AS_Pos)              /*!< 0x00040000 */
#define PMC_DIG_RES_HV0_RES15_AS                       PMC_DIG_RES_HV0_RES15_AS_Msk                        /*!< </spirit:description> */
#define PMC_DIG_RES_HV0_RES15_DACCMP_Pos               (19U)
#define PMC_DIG_RES_HV0_RES15_DACCMP_Msk               (0x1UL << PMC_DIG_RES_HV0_RES15_DACCMP_Pos)          /*!< 0x00080000 */
#define PMC_DIG_RES_HV0_RES15_DACCMP                   PMC_DIG_RES_HV0_RES15_DACCMP_Msk                    /*!< </spirit:description> */
#define PMC_DIG_RES_HV0_RES11_C_Pos                    (24U)
#define PMC_DIG_RES_HV0_RES11_C_Msk                    (0x1UL << PMC_DIG_RES_HV0_RES11_C_Pos)               /*!< 0x01000000 */
#define PMC_DIG_RES_HV0_RES11_C                        PMC_DIG_RES_HV0_RES11_C_Msk                         /*!< </spirit:description> */
#define PMC_DIG_RES_HV0_RES11_FL_Pos                   (25U)
#define PMC_DIG_RES_HV0_RES11_FL_Msk                   (0x1UL << PMC_DIG_RES_HV0_RES11_FL_Pos)              /*!< 0x02000000 */
#define PMC_DIG_RES_HV0_RES11_FL                       PMC_DIG_RES_HV0_RES11_FL_Msk                        /*!< </spirit:description> */
#define PMC_DIG_RES_HV0_RES11_IO1_Pos                  (27U)
#define PMC_DIG_RES_HV0_RES11_IO1_Msk                  (0x1UL << PMC_DIG_RES_HV0_RES11_IO1_Pos)             /*!< 0x08000000 */
#define PMC_DIG_RES_HV0_RES11_IO1                      PMC_DIG_RES_HV0_RES11_IO1_Msk                       /*!< </spirit:description> */
#define PMC_DIG_RES_HV0_RES11_IO0_Pos                  (28U)
#define PMC_DIG_RES_HV0_RES11_IO0_Msk                  (0x1UL << PMC_DIG_RES_HV0_RES11_IO0_Pos)             /*!< 0x10000000 */
#define PMC_DIG_RES_HV0_RES11_IO0                      PMC_DIG_RES_HV0_RES11_IO0_Msk                       /*!< </spirit:description> */
#define PMC_DIG_RES_HV0_RES11_AS_Pos                   (29U)
#define PMC_DIG_RES_HV0_RES11_AS_Msk                   (0x1UL << PMC_DIG_RES_HV0_RES11_AS_Pos)              /*!< 0x20000000 */
#define PMC_DIG_RES_HV0_RES11_AS                       PMC_DIG_RES_HV0_RES11_AS_Msk                        /*!< </spirit:description> */
#define PMC_DIG_RES_HV0_RES11_AD_Pos                   (30U)
#define PMC_DIG_RES_HV0_RES11_AD_Msk                   (0x1UL << PMC_DIG_RES_HV0_RES11_AD_Pos)              /*!< 0x40000000 */
#define PMC_DIG_RES_HV0_RES11_AD                       PMC_DIG_RES_HV0_RES11_AD_Msk                        /*!< </spirit:description> */

/****************  Bit definition for PMC_DIG_IE_HV0 register  ****************/
#define PMC_DIG_IE_HV0_LVD11IE_DACCMP_Pos              (16U)
#define PMC_DIG_IE_HV0_LVD11IE_DACCMP_Msk              (0x1UL << PMC_DIG_IE_HV0_LVD11IE_DACCMP_Pos)         /*!< 0x00010000 */
#define PMC_DIG_IE_HV0_LVD11IE_DACCMP                  PMC_DIG_IE_HV0_LVD11IE_DACCMP_Msk                   /*!< </spirit:description> */
#define PMC_DIG_IE_HV0_LVD11IE_OSC_Pos                 (17U)
#define PMC_DIG_IE_HV0_LVD11IE_OSC_Msk                 (0x1UL << PMC_DIG_IE_HV0_LVD11IE_OSC_Pos)            /*!< 0x00020000 */
#define PMC_DIG_IE_HV0_LVD11IE_OSC                     PMC_DIG_IE_HV0_LVD11IE_OSC_Msk                      /*!< </spirit:description> */
#define PMC_DIG_IE_HV0_UVD15IE_AS_Pos                  (18U)
#define PMC_DIG_IE_HV0_UVD15IE_AS_Msk                  (0x1UL << PMC_DIG_IE_HV0_UVD15IE_AS_Pos)             /*!< 0x00040000 */
#define PMC_DIG_IE_HV0_UVD15IE_AS                      PMC_DIG_IE_HV0_UVD15IE_AS_Msk                       /*!< </spirit:description> */
#define PMC_DIG_IE_HV0_UVD15IE_DACCMP_Pos              (19U)
#define PMC_DIG_IE_HV0_UVD15IE_DACCMP_Msk              (0x1UL << PMC_DIG_IE_HV0_UVD15IE_DACCMP_Pos)         /*!< 0x00080000 */
#define PMC_DIG_IE_HV0_UVD15IE_DACCMP                  PMC_DIG_IE_HV0_UVD15IE_DACCMP_Msk                   /*!< </spirit:description> */
#define PMC_DIG_IE_HV0_LVD11IE_C_Pos                   (24U)
#define PMC_DIG_IE_HV0_LVD11IE_C_Msk                   (0x1UL << PMC_DIG_IE_HV0_LVD11IE_C_Pos)              /*!< 0x01000000 */
#define PMC_DIG_IE_HV0_LVD11IE_C                       PMC_DIG_IE_HV0_LVD11IE_C_Msk                        /*!< </spirit:description> */
#define PMC_DIG_IE_HV0_LVD11IE_FL_Pos                  (25U)
#define PMC_DIG_IE_HV0_LVD11IE_FL_Msk                  (0x1UL << PMC_DIG_IE_HV0_LVD11IE_FL_Pos)             /*!< 0x02000000 */
#define PMC_DIG_IE_HV0_LVD11IE_FL                      PMC_DIG_IE_HV0_LVD11IE_FL_Msk                       /*!< </spirit:description> */
#define PMC_DIG_IE_HV0_LVD11IE_IO1_Pos                 (27U)
#define PMC_DIG_IE_HV0_LVD11IE_IO1_Msk                 (0x1UL << PMC_DIG_IE_HV0_LVD11IE_IO1_Pos)            /*!< 0x08000000 */
#define PMC_DIG_IE_HV0_LVD11IE_IO1                     PMC_DIG_IE_HV0_LVD11IE_IO1_Msk                      /*!< </spirit:description> */
#define PMC_DIG_IE_HV0_LVD11IE_IO0_Pos                 (28U)
#define PMC_DIG_IE_HV0_LVD11IE_IO0_Msk                 (0x1UL << PMC_DIG_IE_HV0_LVD11IE_IO0_Pos)            /*!< 0x10000000 */
#define PMC_DIG_IE_HV0_LVD11IE_IO0                     PMC_DIG_IE_HV0_LVD11IE_IO0_Msk                      /*!< </spirit:description> */
#define PMC_DIG_IE_HV0_LVD11IE_AS_Pos                  (29U)
#define PMC_DIG_IE_HV0_LVD11IE_AS_Msk                  (0x1UL << PMC_DIG_IE_HV0_LVD11IE_AS_Pos)             /*!< 0x20000000 */
#define PMC_DIG_IE_HV0_LVD11IE_AS                      PMC_DIG_IE_HV0_LVD11IE_AS_Msk                       /*!< </spirit:description> */
#define PMC_DIG_IE_HV0_LVD11IE_AD_Pos                  (30U)
#define PMC_DIG_IE_HV0_LVD11IE_AD_Msk                  (0x1UL << PMC_DIG_IE_HV0_LVD11IE_AD_Pos)             /*!< 0x40000000 */
#define PMC_DIG_IE_HV0_LVD11IE_AD                      PMC_DIG_IE_HV0_LVD11IE_AD_Msk                       /*!< </spirit:description> */

/***************  Bit definition for PMC_DIG_FEE_HV0 register  ****************/
#define PMC_DIG_FEE_HV0_FEE11_DACCMP_Pos               (16U)
#define PMC_DIG_FEE_HV0_FEE11_DACCMP_Msk               (0x1UL << PMC_DIG_FEE_HV0_FEE11_DACCMP_Pos)          /*!< 0x00010000 */
#define PMC_DIG_FEE_HV0_FEE11_DACCMP                   PMC_DIG_FEE_HV0_FEE11_DACCMP_Msk                    /*!< </spirit:description> */
#define PMC_DIG_FEE_HV0_FEE11_OSC_Pos                  (17U)
#define PMC_DIG_FEE_HV0_FEE11_OSC_Msk                  (0x1UL << PMC_DIG_FEE_HV0_FEE11_OSC_Pos)             /*!< 0x00020000 */
#define PMC_DIG_FEE_HV0_FEE11_OSC                      PMC_DIG_FEE_HV0_FEE11_OSC_Msk                       /*!< </spirit:description> */
#define PMC_DIG_FEE_HV0_FEE15_AS_Pos                   (18U)
#define PMC_DIG_FEE_HV0_FEE15_AS_Msk                   (0x1UL << PMC_DIG_FEE_HV0_FEE15_AS_Pos)              /*!< 0x00040000 */
#define PMC_DIG_FEE_HV0_FEE15_AS                       PMC_DIG_FEE_HV0_FEE15_AS_Msk                        /*!< </spirit:description> */
#define PMC_DIG_FEE_HV0_FEE15_DACCMP_Pos               (19U)
#define PMC_DIG_FEE_HV0_FEE15_DACCMP_Msk               (0x1UL << PMC_DIG_FEE_HV0_FEE15_DACCMP_Pos)          /*!< 0x00080000 */
#define PMC_DIG_FEE_HV0_FEE15_DACCMP                   PMC_DIG_FEE_HV0_FEE15_DACCMP_Msk                    /*!< </spirit:description> */
#define PMC_DIG_FEE_HV0_FEE11_C_Pos                    (24U)
#define PMC_DIG_FEE_HV0_FEE11_C_Msk                    (0x1UL << PMC_DIG_FEE_HV0_FEE11_C_Pos)               /*!< 0x01000000 */
#define PMC_DIG_FEE_HV0_FEE11_C                        PMC_DIG_FEE_HV0_FEE11_C_Msk                         /*!< </spirit:description> */
#define PMC_DIG_FEE_HV0_FEE11_FL_Pos                   (25U)
#define PMC_DIG_FEE_HV0_FEE11_FL_Msk                   (0x1UL << PMC_DIG_FEE_HV0_FEE11_FL_Pos)              /*!< 0x02000000 */
#define PMC_DIG_FEE_HV0_FEE11_FL                       PMC_DIG_FEE_HV0_FEE11_FL_Msk                        /*!< </spirit:description> */
#define PMC_DIG_FEE_HV0_FEE11_IO1_Pos                  (27U)
#define PMC_DIG_FEE_HV0_FEE11_IO1_Msk                  (0x1UL << PMC_DIG_FEE_HV0_FEE11_IO1_Pos)             /*!< 0x08000000 */
#define PMC_DIG_FEE_HV0_FEE11_IO1                      PMC_DIG_FEE_HV0_FEE11_IO1_Msk                       /*!< </spirit:description> */
#define PMC_DIG_FEE_HV0_FEE11_IO0_Pos                  (28U)
#define PMC_DIG_FEE_HV0_FEE11_IO0_Msk                  (0x1UL << PMC_DIG_FEE_HV0_FEE11_IO0_Pos)             /*!< 0x10000000 */
#define PMC_DIG_FEE_HV0_FEE11_IO0                      PMC_DIG_FEE_HV0_FEE11_IO0_Msk                       /*!< </spirit:description> */
#define PMC_DIG_FEE_HV0_FEE11_AS_Pos                   (29U)
#define PMC_DIG_FEE_HV0_FEE11_AS_Msk                   (0x1UL << PMC_DIG_FEE_HV0_FEE11_AS_Pos)              /*!< 0x20000000 */
#define PMC_DIG_FEE_HV0_FEE11_AS                       PMC_DIG_FEE_HV0_FEE11_AS_Msk                        /*!< </spirit:description> */
#define PMC_DIG_FEE_HV0_FEE11_AD_Pos                   (30U)
#define PMC_DIG_FEE_HV0_FEE11_AD_Msk                   (0x1UL << PMC_DIG_FEE_HV0_FEE11_AD_Pos)              /*!< 0x40000000 */
#define PMC_DIG_FEE_HV0_FEE11_AD                       PMC_DIG_FEE_HV0_FEE11_AD_Msk                        /*!< </spirit:description> */

/*****************  Bit definition for PMC_DIG_GR_S register  *****************/
#define PMC_DIG_GR_S_VD3_C_Pos                         (0U)
#define PMC_DIG_GR_S_VD3_C_Msk                         (0x1UL << PMC_DIG_GR_S_VD3_C_Pos)                    /*!< 0x00000001 */
#define PMC_DIG_GR_S_VD3_C                             PMC_DIG_GR_S_VD3_C_Msk                              /*!< </spirit:description> */
#define PMC_DIG_GR_S_VD3_FL_Pos                        (1U)
#define PMC_DIG_GR_S_VD3_FL_Msk                        (0x1UL << PMC_DIG_GR_S_VD3_FL_Pos)                   /*!< 0x00000002 */
#define PMC_DIG_GR_S_VD3_FL                            PMC_DIG_GR_S_VD3_FL_Msk                             /*!< </spirit:description> */
#define PMC_DIG_GR_S_VD3_RC_Pos                        (3U)
#define PMC_DIG_GR_S_VD3_RC_Msk                        (0x1UL << PMC_DIG_GR_S_VD3_RC_Pos)                   /*!< 0x00000008 */
#define PMC_DIG_GR_S_VD3_RC                            PMC_DIG_GR_S_VD3_RC_Msk                             /*!< </spirit:description> */
#define PMC_DIG_GR_S_VD6_C_Pos                         (4U)
#define PMC_DIG_GR_S_VD6_C_Msk                         (0x1UL << PMC_DIG_GR_S_VD6_C_Pos)                    /*!< 0x00000010 */
#define PMC_DIG_GR_S_VD6_C                             PMC_DIG_GR_S_VD6_C_Msk                              /*!< </spirit:description> */
#define PMC_DIG_GR_S_VD7_RC_Pos                        (5U)
#define PMC_DIG_GR_S_VD7_RC_Msk                        (0x1UL << PMC_DIG_GR_S_VD7_RC_Pos)                   /*!< 0x00000020 */
#define PMC_DIG_GR_S_VD7_RC                            PMC_DIG_GR_S_VD7_RC_Msk                             /*!< </spirit:description> */
#define PMC_DIG_GR_S_VD11_C_Pos                        (6U)
#define PMC_DIG_GR_S_VD11_C_Msk                        (0x1UL << PMC_DIG_GR_S_VD11_C_Pos)                   /*!< 0x00000040 */
#define PMC_DIG_GR_S_VD11_C                            PMC_DIG_GR_S_VD11_C_Msk                             /*!< </spirit:description> */
#define PMC_DIG_GR_S_VD11_FL_Pos                       (7U)
#define PMC_DIG_GR_S_VD11_FL_Msk                       (0x1UL << PMC_DIG_GR_S_VD11_FL_Pos)                  /*!< 0x00000080 */
#define PMC_DIG_GR_S_VD11_FL                           PMC_DIG_GR_S_VD11_FL_Msk                            /*!< </spirit:description> */
#define PMC_DIG_GR_S_VD11_IO1_Pos                      (8U)
#define PMC_DIG_GR_S_VD11_IO1_Msk                      (0x1UL << PMC_DIG_GR_S_VD11_IO1_Pos)                 /*!< 0x00000100 */
#define PMC_DIG_GR_S_VD11_IO1                          PMC_DIG_GR_S_VD11_IO1_Msk                           /*!< </spirit:description> */
#define PMC_DIG_GR_S_VD11_IO0_Pos                      (9U)
#define PMC_DIG_GR_S_VD11_IO0_Msk                      (0x1UL << PMC_DIG_GR_S_VD11_IO0_Pos)                 /*!< 0x00000200 */
#define PMC_DIG_GR_S_VD11_IO0                          PMC_DIG_GR_S_VD11_IO0_Msk                           /*!< </spirit:description> */
#define PMC_DIG_GR_S_VD11_AS_Pos                       (10U)
#define PMC_DIG_GR_S_VD11_AS_Msk                       (0x1UL << PMC_DIG_GR_S_VD11_AS_Pos)                  /*!< 0x00000400 */
#define PMC_DIG_GR_S_VD11_AS                           PMC_DIG_GR_S_VD11_AS_Msk                            /*!< </spirit:description> */
#define PMC_DIG_GR_S_VD11_AD_Pos                       (11U)
#define PMC_DIG_GR_S_VD11_AD_Msk                       (0x1UL << PMC_DIG_GR_S_VD11_AD_Pos)                  /*!< 0x00000800 */
#define PMC_DIG_GR_S_VD11_AD                           PMC_DIG_GR_S_VD11_AD_Msk                            /*!< </spirit:description> */
#define PMC_DIG_GR_S_VD11_DACCMP_Pos                   (16U)
#define PMC_DIG_GR_S_VD11_DACCMP_Msk                   (0x1UL << PMC_DIG_GR_S_VD11_DACCMP_Pos)              /*!< 0x00010000 */
#define PMC_DIG_GR_S_VD11_DACCMP                       PMC_DIG_GR_S_VD11_DACCMP_Msk                        /*!< </spirit:description> */
#define PMC_DIG_GR_S_VD11_OSC_Pos                      (17U)
#define PMC_DIG_GR_S_VD11_OSC_Msk                      (0x1UL << PMC_DIG_GR_S_VD11_OSC_Pos)                 /*!< 0x00020000 */
#define PMC_DIG_GR_S_VD11_OSC                          PMC_DIG_GR_S_VD11_OSC_Msk                           /*!< </spirit:description> */
#define PMC_DIG_GR_S_VD15_AS_Pos                       (18U)
#define PMC_DIG_GR_S_VD15_AS_Msk                       (0x1UL << PMC_DIG_GR_S_VD15_AS_Pos)                  /*!< 0x00040000 */
#define PMC_DIG_GR_S_VD15_AS                           PMC_DIG_GR_S_VD15_AS_Msk                            /*!< </spirit:description> */
#define PMC_DIG_GR_S_VD15_DACCMP_Pos                   (19U)
#define PMC_DIG_GR_S_VD15_DACCMP_Msk                   (0x1UL << PMC_DIG_GR_S_VD15_DACCMP_Pos)              /*!< 0x00080000 */
#define PMC_DIG_GR_S_VD15_DACCMP                       PMC_DIG_GR_S_VD15_DACCMP_Msk                        /*!< </spirit:description> */
#define PMC_DIG_GR_S_VD3_DD_Pos                        (25U)
#define PMC_DIG_GR_S_VD3_DD_Msk                        (0x1UL << PMC_DIG_GR_S_VD3_DD_Pos)                   /*!< 0x02000000 */
#define PMC_DIG_GR_S_VD3_DD                            PMC_DIG_GR_S_VD3_DD_Msk                             /*!< </spirit:description> */
#define PMC_DIG_GR_S_VD3_PLL0_Pos                      (26U)
#define PMC_DIG_GR_S_VD3_PLL0_Msk                      (0x1UL << PMC_DIG_GR_S_VD3_PLL0_Pos)                 /*!< 0x04000000 */
#define PMC_DIG_GR_S_VD3_PLL0                          PMC_DIG_GR_S_VD3_PLL0_Msk                           /*!< </spirit:description> */
#define PMC_DIG_GR_S_VD3_PLL1_Pos                      (27U)
#define PMC_DIG_GR_S_VD3_PLL1_Msk                      (0x1UL << PMC_DIG_GR_S_VD3_PLL1_Pos)                 /*!< 0x08000000 */
#define PMC_DIG_GR_S_VD3_PLL1                          PMC_DIG_GR_S_VD3_PLL1_Msk                           /*!< </spirit:description> */
#define PMC_DIG_GR_S_TEMP_0_Pos                        (28U)
#define PMC_DIG_GR_S_TEMP_0_Msk                        (0x1UL << PMC_DIG_GR_S_TEMP_0_Pos)                   /*!< 0x10000000 */
#define PMC_DIG_GR_S_TEMP_0                            PMC_DIG_GR_S_TEMP_0_Msk                             /*!< </spirit:description> */
#define PMC_DIG_GR_S_TEMP_1_Pos                        (29U)
#define PMC_DIG_GR_S_TEMP_1_Msk                        (0x1UL << PMC_DIG_GR_S_TEMP_1_Pos)                   /*!< 0x20000000 */
#define PMC_DIG_GR_S_TEMP_1                            PMC_DIG_GR_S_TEMP_1_Msk                             /*!< </spirit:description> */
#define PMC_DIG_GR_S_TEMP_2_Pos                        (30U)
#define PMC_DIG_GR_S_TEMP_2_Msk                        (0x1UL << PMC_DIG_GR_S_TEMP_2_Pos)                   /*!< 0x40000000 */
#define PMC_DIG_GR_S_TEMP_2                            PMC_DIG_GR_S_TEMP_2_Msk                             /*!< </spirit:description> */

/*****************  Bit definition for PMC_DIG_GR_P register  *****************/
#define PMC_DIG_GR_P_IRQ_ST_Pos                        (1U)
#define PMC_DIG_GR_P_IRQ_ST_Msk                        (0x1UL << PMC_DIG_GR_P_IRQ_ST_Pos)                   /*!< 0x00000002 */
#define PMC_DIG_GR_P_IRQ_ST                            PMC_DIG_GR_P_IRQ_ST_Msk                             /*!< </spirit:description> */
#define PMC_DIG_GR_P_VD3_C_Pos                         (3U)
#define PMC_DIG_GR_P_VD3_C_Msk                         (0x1UL << PMC_DIG_GR_P_VD3_C_Pos)                    /*!< 0x00000008 */
#define PMC_DIG_GR_P_VD3_C                             PMC_DIG_GR_P_VD3_C_Msk                              /*!< </spirit:description> */
#define PMC_DIG_GR_P_VD3_FL_Pos                        (4U)
#define PMC_DIG_GR_P_VD3_FL_Msk                        (0x1UL << PMC_DIG_GR_P_VD3_FL_Pos)                   /*!< 0x00000010 */
#define PMC_DIG_GR_P_VD3_FL                            PMC_DIG_GR_P_VD3_FL_Msk                             /*!< </spirit:description> */
#define PMC_DIG_GR_P_VD3_RC_Pos                        (6U)
#define PMC_DIG_GR_P_VD3_RC_Msk                        (0x1UL << PMC_DIG_GR_P_VD3_RC_Pos)                   /*!< 0x00000040 */
#define PMC_DIG_GR_P_VD3_RC                            PMC_DIG_GR_P_VD3_RC_Msk                             /*!< </spirit:description> */
#define PMC_DIG_GR_P_VD6_C_Pos                         (7U)
#define PMC_DIG_GR_P_VD6_C_Msk                         (0x1UL << PMC_DIG_GR_P_VD6_C_Pos)                    /*!< 0x00000080 */
#define PMC_DIG_GR_P_VD6_C                             PMC_DIG_GR_P_VD6_C_Msk                              /*!< </spirit:description> */
#define PMC_DIG_GR_P_VD7_RC_Pos                        (8U)
#define PMC_DIG_GR_P_VD7_RC_Msk                        (0x1UL << PMC_DIG_GR_P_VD7_RC_Pos)                   /*!< 0x00000100 */
#define PMC_DIG_GR_P_VD7_RC                            PMC_DIG_GR_P_VD7_RC_Msk                             /*!< </spirit:description> */
#define PMC_DIG_GR_P_VD11_C_Pos                        (9U)
#define PMC_DIG_GR_P_VD11_C_Msk                        (0x1UL << PMC_DIG_GR_P_VD11_C_Pos)                   /*!< 0x00000200 */
#define PMC_DIG_GR_P_VD11_C                            PMC_DIG_GR_P_VD11_C_Msk                             /*!< </spirit:description> */
#define PMC_DIG_GR_P_VD11_FL_Pos                       (10U)
#define PMC_DIG_GR_P_VD11_FL_Msk                       (0x1UL << PMC_DIG_GR_P_VD11_FL_Pos)                  /*!< 0x00000400 */
#define PMC_DIG_GR_P_VD11_FL                           PMC_DIG_GR_P_VD11_FL_Msk                            /*!< </spirit:description> */
#define PMC_DIG_GR_P_VD11_IO1_Pos                      (11U)
#define PMC_DIG_GR_P_VD11_IO1_Msk                      (0x1UL << PMC_DIG_GR_P_VD11_IO1_Pos)                 /*!< 0x00000800 */
#define PMC_DIG_GR_P_VD11_IO1                          PMC_DIG_GR_P_VD11_IO1_Msk                           /*!< </spirit:description> */
#define PMC_DIG_GR_P_VD11_IO0_Pos                      (12U)
#define PMC_DIG_GR_P_VD11_IO0_Msk                      (0x1UL << PMC_DIG_GR_P_VD11_IO0_Pos)                 /*!< 0x00001000 */
#define PMC_DIG_GR_P_VD11_IO0                          PMC_DIG_GR_P_VD11_IO0_Msk                           /*!< </spirit:description> */
#define PMC_DIG_GR_P_VD11_AS_Pos                       (13U)
#define PMC_DIG_GR_P_VD11_AS_Msk                       (0x1UL << PMC_DIG_GR_P_VD11_AS_Pos)                  /*!< 0x00002000 */
#define PMC_DIG_GR_P_VD11_AS                           PMC_DIG_GR_P_VD11_AS_Msk                            /*!< </spirit:description> */
#define PMC_DIG_GR_P_VD11_AD_Pos                       (14U)
#define PMC_DIG_GR_P_VD11_AD_Msk                       (0x1UL << PMC_DIG_GR_P_VD11_AD_Pos)                  /*!< 0x00004000 */
#define PMC_DIG_GR_P_VD11_AD                           PMC_DIG_GR_P_VD11_AD_Msk                            /*!< </spirit:description> */
#define PMC_DIG_GR_P_VD11_DACCMP_Pos                   (16U)
#define PMC_DIG_GR_P_VD11_DACCMP_Msk                   (0x1UL << PMC_DIG_GR_P_VD11_DACCMP_Pos)              /*!< 0x00010000 */
#define PMC_DIG_GR_P_VD11_DACCMP                       PMC_DIG_GR_P_VD11_DACCMP_Msk                        /*!< </spirit:description> */
#define PMC_DIG_GR_P_VD11_OSC_Pos                      (17U)
#define PMC_DIG_GR_P_VD11_OSC_Msk                      (0x1UL << PMC_DIG_GR_P_VD11_OSC_Pos)                 /*!< 0x00020000 */
#define PMC_DIG_GR_P_VD11_OSC                          PMC_DIG_GR_P_VD11_OSC_Msk                           /*!< </spirit:description> */
#define PMC_DIG_GR_P_VD15_AS_Pos                       (18U)
#define PMC_DIG_GR_P_VD15_AS_Msk                       (0x1UL << PMC_DIG_GR_P_VD15_AS_Pos)                  /*!< 0x00040000 */
#define PMC_DIG_GR_P_VD15_AS                           PMC_DIG_GR_P_VD15_AS_Msk                            /*!< </spirit:description> */
#define PMC_DIG_GR_P_VD15_DACCMP_Pos                   (19U)
#define PMC_DIG_GR_P_VD15_DACCMP_Msk                   (0x1UL << PMC_DIG_GR_P_VD15_DACCMP_Pos)              /*!< 0x00080000 */
#define PMC_DIG_GR_P_VD15_DACCMP                       PMC_DIG_GR_P_VD15_DACCMP_Msk                        /*!< </spirit:description> */
#define PMC_DIG_GR_P_VD3_DD_Pos                        (25U)
#define PMC_DIG_GR_P_VD3_DD_Msk                        (0x1UL << PMC_DIG_GR_P_VD3_DD_Pos)                   /*!< 0x02000000 */
#define PMC_DIG_GR_P_VD3_DD                            PMC_DIG_GR_P_VD3_DD_Msk                             /*!< </spirit:description> */
#define PMC_DIG_GR_P_VD3_PLL0_Pos                      (26U)
#define PMC_DIG_GR_P_VD3_PLL0_Msk                      (0x1UL << PMC_DIG_GR_P_VD3_PLL0_Pos)                 /*!< 0x04000000 */
#define PMC_DIG_GR_P_VD3_PLL0                          PMC_DIG_GR_P_VD3_PLL0_Msk                           /*!< </spirit:description> */
#define PMC_DIG_GR_P_VD3_PLL1_Pos                      (27U)
#define PMC_DIG_GR_P_VD3_PLL1_Msk                      (0x1UL << PMC_DIG_GR_P_VD3_PLL1_Pos)                 /*!< 0x08000000 */
#define PMC_DIG_GR_P_VD3_PLL1                          PMC_DIG_GR_P_VD3_PLL1_Msk                           /*!< </spirit:description> */

/*****************  Bit definition for PMC_DIG_IE_G register  *****************/
#define PMC_DIG_IE_G_IRQ_EN_Pos                        (1U)
#define PMC_DIG_IE_G_IRQ_EN_Msk                        (0x1UL << PMC_DIG_IE_G_IRQ_EN_Pos)                   /*!< 0x00000002 */
#define PMC_DIG_IE_G_IRQ_EN                            PMC_DIG_IE_G_IRQ_EN_Msk                             /*!< </spirit:description> */
#define PMC_DIG_IE_G_VD3IE_C_Pos                       (3U)
#define PMC_DIG_IE_G_VD3IE_C_Msk                       (0x1UL << PMC_DIG_IE_G_VD3IE_C_Pos)                  /*!< 0x00000008 */
#define PMC_DIG_IE_G_VD3IE_C                           PMC_DIG_IE_G_VD3IE_C_Msk                            /*!< </spirit:description> */
#define PMC_DIG_IE_G_VD3IE_FL_Pos                      (4U)
#define PMC_DIG_IE_G_VD3IE_FL_Msk                      (0x1UL << PMC_DIG_IE_G_VD3IE_FL_Pos)                 /*!< 0x00000010 */
#define PMC_DIG_IE_G_VD3IE_FL                          PMC_DIG_IE_G_VD3IE_FL_Msk                           /*!< </spirit:description> */
#define PMC_DIG_IE_G_VD3IE_RC_Pos                      (6U)
#define PMC_DIG_IE_G_VD3IE_RC_Msk                      (0x1UL << PMC_DIG_IE_G_VD3IE_RC_Pos)                 /*!< 0x00000040 */
#define PMC_DIG_IE_G_VD3IE_RC                          PMC_DIG_IE_G_VD3IE_RC_Msk                           /*!< </spirit:description> */
#define PMC_DIG_IE_G_VD6IE_C_Pos                       (7U)
#define PMC_DIG_IE_G_VD6IE_C_Msk                       (0x1UL << PMC_DIG_IE_G_VD6IE_C_Pos)                  /*!< 0x00000080 */
#define PMC_DIG_IE_G_VD6IE_C                           PMC_DIG_IE_G_VD6IE_C_Msk                            /*!< </spirit:description> */
#define PMC_DIG_IE_G_VD7IE_RC_Pos                      (8U)
#define PMC_DIG_IE_G_VD7IE_RC_Msk                      (0x1UL << PMC_DIG_IE_G_VD7IE_RC_Pos)                 /*!< 0x00000100 */
#define PMC_DIG_IE_G_VD7IE_RC                          PMC_DIG_IE_G_VD7IE_RC_Msk                           /*!< </spirit:description> */
#define PMC_DIG_IE_G_VD11IE_C_Pos                      (9U)
#define PMC_DIG_IE_G_VD11IE_C_Msk                      (0x1UL << PMC_DIG_IE_G_VD11IE_C_Pos)                 /*!< 0x00000200 */
#define PMC_DIG_IE_G_VD11IE_C                          PMC_DIG_IE_G_VD11IE_C_Msk                           /*!< </spirit:description> */
#define PMC_DIG_IE_G_VD11IE_FL_Pos                     (10U)
#define PMC_DIG_IE_G_VD11IE_FL_Msk                     (0x1UL << PMC_DIG_IE_G_VD11IE_FL_Pos)                /*!< 0x00000400 */
#define PMC_DIG_IE_G_VD11IE_FL                         PMC_DIG_IE_G_VD11IE_FL_Msk                          /*!< </spirit:description> */
#define PMC_DIG_IE_G_VD11IE_IO1_Pos                    (11U)
#define PMC_DIG_IE_G_VD11IE_IO1_Msk                    (0x1UL << PMC_DIG_IE_G_VD11IE_IO1_Pos)               /*!< 0x00000800 */
#define PMC_DIG_IE_G_VD11IE_IO1                        PMC_DIG_IE_G_VD11IE_IO1_Msk                         /*!< </spirit:description> */
#define PMC_DIG_IE_G_VD11IE_IO0_Pos                    (12U)
#define PMC_DIG_IE_G_VD11IE_IO0_Msk                    (0x1UL << PMC_DIG_IE_G_VD11IE_IO0_Pos)               /*!< 0x00001000 */
#define PMC_DIG_IE_G_VD11IE_IO0                        PMC_DIG_IE_G_VD11IE_IO0_Msk                         /*!< </spirit:description> */
#define PMC_DIG_IE_G_VD11IE_AS_Pos                     (13U)
#define PMC_DIG_IE_G_VD11IE_AS_Msk                     (0x1UL << PMC_DIG_IE_G_VD11IE_AS_Pos)                /*!< 0x00002000 */
#define PMC_DIG_IE_G_VD11IE_AS                         PMC_DIG_IE_G_VD11IE_AS_Msk                          /*!< </spirit:description> */
#define PMC_DIG_IE_G_VD11IE_AD_Pos                     (14U)
#define PMC_DIG_IE_G_VD11IE_AD_Msk                     (0x1UL << PMC_DIG_IE_G_VD11IE_AD_Pos)                /*!< 0x00004000 */
#define PMC_DIG_IE_G_VD11IE_AD                         PMC_DIG_IE_G_VD11IE_AD_Msk                          /*!< </spirit:description> */
#define PMC_DIG_IE_G_VD11IE_DACCMP_Pos                 (16U)
#define PMC_DIG_IE_G_VD11IE_DACCMP_Msk                 (0x1UL << PMC_DIG_IE_G_VD11IE_DACCMP_Pos)            /*!< 0x00010000 */
#define PMC_DIG_IE_G_VD11IE_DACCMP                     PMC_DIG_IE_G_VD11IE_DACCMP_Msk                      /*!< </spirit:description> */
#define PMC_DIG_IE_G_VD11IE_OSC_Pos                    (17U)
#define PMC_DIG_IE_G_VD11IE_OSC_Msk                    (0x1UL << PMC_DIG_IE_G_VD11IE_OSC_Pos)               /*!< 0x00020000 */
#define PMC_DIG_IE_G_VD11IE_OSC                        PMC_DIG_IE_G_VD11IE_OSC_Msk                         /*!< </spirit:description> */
#define PMC_DIG_IE_G_VD15IE_AS_Pos                     (18U)
#define PMC_DIG_IE_G_VD15IE_AS_Msk                     (0x1UL << PMC_DIG_IE_G_VD15IE_AS_Pos)                /*!< 0x00040000 */
#define PMC_DIG_IE_G_VD15IE_AS                         PMC_DIG_IE_G_VD15IE_AS_Msk                          /*!< </spirit:description> */
#define PMC_DIG_IE_G_VD15IE_DACCMP_Pos                 (19U)
#define PMC_DIG_IE_G_VD15IE_DACCMP_Msk                 (0x1UL << PMC_DIG_IE_G_VD15IE_DACCMP_Pos)            /*!< 0x00080000 */
#define PMC_DIG_IE_G_VD15IE_DACCMP                     PMC_DIG_IE_G_VD15IE_DACCMP_Msk                      /*!< </spirit:description> */
#define PMC_DIG_IE_G_VD3IE_DD_Pos                      (25U)
#define PMC_DIG_IE_G_VD3IE_DD_Msk                      (0x1UL << PMC_DIG_IE_G_VD3IE_DD_Pos)                 /*!< 0x02000000 */
#define PMC_DIG_IE_G_VD3IE_DD                          PMC_DIG_IE_G_VD3IE_DD_Msk                           /*!< </spirit:description> */
#define PMC_DIG_IE_G_VD3IE_PLL0_Pos                    (26U)
#define PMC_DIG_IE_G_VD3IE_PLL0_Msk                    (0x1UL << PMC_DIG_IE_G_VD3IE_PLL0_Pos)               /*!< 0x04000000 */
#define PMC_DIG_IE_G_VD3IE_PLL0                        PMC_DIG_IE_G_VD3IE_PLL0_Msk                         /*!< </spirit:description> */
#define PMC_DIG_IE_G_VD3IE_PLL1_Pos                    (27U)
#define PMC_DIG_IE_G_VD3IE_PLL1_Msk                    (0x1UL << PMC_DIG_IE_G_VD3IE_PLL1_Pos)               /*!< 0x08000000 */
#define PMC_DIG_IE_G_VD3IE_PLL1                        PMC_DIG_IE_G_VD3IE_PLL1_Msk                         /*!< </spirit:description> */
#define PMC_DIG_IE_G_IE_EN_Pos                         (31U)
#define PMC_DIG_IE_G_IE_EN_Msk                         (0x1UL << PMC_DIG_IE_G_IE_EN_Pos)                    /*!< 0x80000000 */
#define PMC_DIG_IE_G_IE_EN                             PMC_DIG_IE_G_IE_EN_Msk                              /*!< </spirit:description> */

/***********  Bit definition for PMC_DIG_HPREG_SMPS_SEL_S register  ***********/
#define PMC_DIG_HPREG_SMPS_SEL_S_SMPS_ENB_Pos          (0U)
#define PMC_DIG_HPREG_SMPS_SEL_S_SMPS_ENB_Msk          (0x1UL << PMC_DIG_HPREG_SMPS_SEL_S_SMPS_ENB_Pos)     /*!< 0x00000001 */
#define PMC_DIG_HPREG_SMPS_SEL_S_SMPS_ENB              PMC_DIG_HPREG_SMPS_SEL_S_SMPS_ENB_Msk               /*!< </spirit:description> */

/****************  Bit definition for PMC_DIG_EPR_TD register  ****************/
#define PMC_DIG_EPR_TD_TEMP_0_Pos                      (0U)
#define PMC_DIG_EPR_TD_TEMP_0_Msk                      (0x1UL << PMC_DIG_EPR_TD_TEMP_0_Pos)                 /*!< 0x00000001 */
#define PMC_DIG_EPR_TD_TEMP_0                          PMC_DIG_EPR_TD_TEMP_0_Msk                           /*!< </spirit:description> */
#define PMC_DIG_EPR_TD_TEMP_1_Pos                      (1U)
#define PMC_DIG_EPR_TD_TEMP_1_Msk                      (0x1UL << PMC_DIG_EPR_TD_TEMP_1_Pos)                 /*!< 0x00000002 */
#define PMC_DIG_EPR_TD_TEMP_1                          PMC_DIG_EPR_TD_TEMP_1_Msk                           /*!< </spirit:description> */
#define PMC_DIG_EPR_TD_TEMP_2_Pos                      (2U)
#define PMC_DIG_EPR_TD_TEMP_2_Msk                      (0x1UL << PMC_DIG_EPR_TD_TEMP_2_Pos)                 /*!< 0x00000004 */
#define PMC_DIG_EPR_TD_TEMP_2                          PMC_DIG_EPR_TD_TEMP_2_Msk                           /*!< </spirit:description> */

/****************  Bit definition for PMC_DIG_REE_TD register  ****************/
#define PMC_DIG_REE_TD_TEMP_0_Pos                      (0U)
#define PMC_DIG_REE_TD_TEMP_0_Msk                      (0x1UL << PMC_DIG_REE_TD_TEMP_0_Pos)                 /*!< 0x00000001 */
#define PMC_DIG_REE_TD_TEMP_0                          PMC_DIG_REE_TD_TEMP_0_Msk                           /*!< </spirit:description> */
#define PMC_DIG_REE_TD_TEMP_1_Pos                      (1U)
#define PMC_DIG_REE_TD_TEMP_1_Msk                      (0x1UL << PMC_DIG_REE_TD_TEMP_1_Pos)                 /*!< 0x00000002 */
#define PMC_DIG_REE_TD_TEMP_1                          PMC_DIG_REE_TD_TEMP_1_Msk                           /*!< </spirit:description> */
#define PMC_DIG_REE_TD_TEMP_2_Pos                      (2U)
#define PMC_DIG_REE_TD_TEMP_2_Msk                      (0x1UL << PMC_DIG_REE_TD_TEMP_2_Pos)                 /*!< 0x00000004 */
#define PMC_DIG_REE_TD_TEMP_2                          PMC_DIG_REE_TD_TEMP_2_Msk                           /*!< </spirit:description> */

/****************  Bit definition for PMC_DIG_RES_TD register  ****************/
#define PMC_DIG_RES_TD_TEMP_0_Pos                      (0U)
#define PMC_DIG_RES_TD_TEMP_0_Msk                      (0x1UL << PMC_DIG_RES_TD_TEMP_0_Pos)                 /*!< 0x00000001 */
#define PMC_DIG_RES_TD_TEMP_0                          PMC_DIG_RES_TD_TEMP_0_Msk                           /*!< </spirit:description> */
#define PMC_DIG_RES_TD_TEMP_1_Pos                      (1U)
#define PMC_DIG_RES_TD_TEMP_1_Msk                      (0x1UL << PMC_DIG_RES_TD_TEMP_1_Pos)                 /*!< 0x00000002 */
#define PMC_DIG_RES_TD_TEMP_1                          PMC_DIG_RES_TD_TEMP_1_Msk                           /*!< </spirit:description> */
#define PMC_DIG_RES_TD_TEMP_2_Pos                      (2U)
#define PMC_DIG_RES_TD_TEMP_2_Msk                      (0x1UL << PMC_DIG_RES_TD_TEMP_2_Pos)                 /*!< 0x00000004 */
#define PMC_DIG_RES_TD_TEMP_2                          PMC_DIG_RES_TD_TEMP_2_Msk                           /*!< </spirit:description> */

/****************  Bit definition for PMC_DIG_CTL_TD register  ****************/
#define PMC_DIG_CTL_TD_ADC_AOUT_EN_Pos                 (0U)
#define PMC_DIG_CTL_TD_ADC_AOUT_EN_Msk                 (0x1UL << PMC_DIG_CTL_TD_ADC_AOUT_EN_Pos)            /*!< 0x00000001 */
#define PMC_DIG_CTL_TD_ADC_AOUT_EN                     PMC_DIG_CTL_TD_ADC_AOUT_EN_Msk                      /*!< </spirit:description> */
#define PMC_DIG_CTL_TD_AMUX_CTAT_TS_CTRL_Pos           (1U)
#define PMC_DIG_CTL_TD_AMUX_CTAT_TS_CTRL_Msk           (0x1UL << PMC_DIG_CTL_TD_AMUX_CTAT_TS_CTRL_Pos)      /*!< 0x00000002 */
#define PMC_DIG_CTL_TD_AMUX_CTAT_TS_CTRL               PMC_DIG_CTL_TD_AMUX_CTAT_TS_CTRL_Msk                /*!< </spirit:description> */
#define PMC_DIG_CTL_TD_TRIM_ADJ_UNDER_Pos              (2U)
#define PMC_DIG_CTL_TD_TRIM_ADJ_UNDER_Msk              (0xFUL << PMC_DIG_CTL_TD_TRIM_ADJ_UNDER_Pos)         /*!< 0x0000003C */
#define PMC_DIG_CTL_TD_TRIM_ADJ_UNDER                  PMC_DIG_CTL_TD_TRIM_ADJ_UNDER_Msk                   /*!< </spirit:description> */
#define PMC_DIG_CTL_TD_TRIM_ADJ_OVER_Pos               (8U)
#define PMC_DIG_CTL_TD_TRIM_ADJ_OVER_Msk               (0xFUL << PMC_DIG_CTL_TD_TRIM_ADJ_OVER_Pos)          /*!< 0x00000F00 */
#define PMC_DIG_CTL_TD_TRIM_ADJ_OVER                   PMC_DIG_CTL_TD_TRIM_ADJ_OVER_Msk                    /*!< </spirit:description> */
#define PMC_DIG_CTL_TD_TS0IE_Pos                       (13U)
#define PMC_DIG_CTL_TD_TS0IE_Msk                       (0x1UL << PMC_DIG_CTL_TD_TS0IE_Pos)                  /*!< 0x00002000 */
#define PMC_DIG_CTL_TD_TS0IE                           PMC_DIG_CTL_TD_TS0IE_Msk                            /*!< </spirit:description> */
#define PMC_DIG_CTL_TD_TS1IE_Pos                       (14U)
#define PMC_DIG_CTL_TD_TS1IE_Msk                       (0x1UL << PMC_DIG_CTL_TD_TS1IE_Pos)                  /*!< 0x00004000 */
#define PMC_DIG_CTL_TD_TS1IE                           PMC_DIG_CTL_TD_TS1IE_Msk                            /*!< </spirit:description> */
#define PMC_DIG_CTL_TD_TS2IE_Pos                       (15U)
#define PMC_DIG_CTL_TD_TS2IE_Msk                       (0x1UL << PMC_DIG_CTL_TD_TS2IE_Pos)                  /*!< 0x00008000 */
#define PMC_DIG_CTL_TD_TS2IE                           PMC_DIG_CTL_TD_TS2IE_Msk                            /*!< </spirit:description> */
#define PMC_DIG_CTL_TD_TRIM_ADJ_OVER1_Pos              (16U)
#define PMC_DIG_CTL_TD_TRIM_ADJ_OVER1_Msk              (0xFUL << PMC_DIG_CTL_TD_TRIM_ADJ_OVER1_Pos)         /*!< 0x000F0000 */
#define PMC_DIG_CTL_TD_TRIM_ADJ_OVER1                  PMC_DIG_CTL_TD_TRIM_ADJ_OVER1_Msk                   /*!< </spirit:description> */
#define PMC_DIG_CTL_TD_PMC_AOUT_EN_Pos                 (20U)
#define PMC_DIG_CTL_TD_PMC_AOUT_EN_Msk                 (0x1UL << PMC_DIG_CTL_TD_PMC_AOUT_EN_Pos)            /*!< 0x00100000 */
#define PMC_DIG_CTL_TD_PMC_AOUT_EN                     PMC_DIG_CTL_TD_PMC_AOUT_EN_Msk                      /*!< </spirit:description> */

/****************  Bit definition for PMC_DIG_FEE_TD register  ****************/
#define PMC_DIG_FEE_TD_FEE_TS0_Pos                     (0U)
#define PMC_DIG_FEE_TD_FEE_TS0_Msk                     (0x1UL << PMC_DIG_FEE_TD_FEE_TS0_Pos)                /*!< 0x00000001 */
#define PMC_DIG_FEE_TD_FEE_TS0                         PMC_DIG_FEE_TD_FEE_TS0_Msk                          /*!< </spirit:description> */
#define PMC_DIG_FEE_TD_FEE_TS1_Pos                     (1U)
#define PMC_DIG_FEE_TD_FEE_TS1_Msk                     (0x1UL << PMC_DIG_FEE_TD_FEE_TS1_Pos)                /*!< 0x00000002 */
#define PMC_DIG_FEE_TD_FEE_TS1                         PMC_DIG_FEE_TD_FEE_TS1_Msk                          /*!< </spirit:description> */
#define PMC_DIG_FEE_TD_FEE_TS2_Pos                     (2U)
#define PMC_DIG_FEE_TD_FEE_TS2_Msk                     (0x1UL << PMC_DIG_FEE_TD_FEE_TS2_Pos)                /*!< 0x00000004 */
#define PMC_DIG_FEE_TD_FEE_TS2                         PMC_DIG_FEE_TD_FEE_TS2_Msk                          /*!< </spirit:description> */

/***********  Bit definition for PMC_DIG_BIST_MASK_STATUS register  ***********/
#define PMC_DIG_BIST_MASK_STATUS_BIST_MASK_Pos         (0U)
#define PMC_DIG_BIST_MASK_STATUS_BIST_MASK_Msk         (0x3FFFFFFUL << PMC_DIG_BIST_MASK_STATUS_BIST_MASK_Pos)  /*!< 0x03FFFFFF */
#define PMC_DIG_BIST_MASK_STATUS_BIST_MASK             PMC_DIG_BIST_MASK_STATUS_BIST_MASK_Msk              /*!< </spirit:description> */

/**********  Bit definition for PMC_DIG_BIST_FLAGS_PHASE1 register  ***********/
#define PMC_DIG_BIST_FLAGS_PHASE1_FLAGS_P1_Pos         (0U)
#define PMC_DIG_BIST_FLAGS_PHASE1_FLAGS_P1_Msk         (0x3FFFFFFUL << PMC_DIG_BIST_FLAGS_PHASE1_FLAGS_P1_Pos)  /*!< 0x03FFFFFF */
#define PMC_DIG_BIST_FLAGS_PHASE1_FLAGS_P1             PMC_DIG_BIST_FLAGS_PHASE1_FLAGS_P1_Msk              /*!< </spirit:description> */

/**********  Bit definition for PMC_DIG_BIST_FLAGS_PHASE2 register  ***********/
#define PMC_DIG_BIST_FLAGS_PHASE2_FLAGS_P2_Pos         (0U)
#define PMC_DIG_BIST_FLAGS_PHASE2_FLAGS_P2_Msk         (0x3FFFFFFUL << PMC_DIG_BIST_FLAGS_PHASE2_FLAGS_P2_Pos)  /*!< 0x03FFFFFF */
#define PMC_DIG_BIST_FLAGS_PHASE2_FLAGS_P2             PMC_DIG_BIST_FLAGS_PHASE2_FLAGS_P2_Msk              /*!< </spirit:description> */

/**************  Bit definition for PMC_DIG_BIST_CTRL register  ***************/
#define PMC_DIG_BIST_CTRL_START_Pos                    (0U)
#define PMC_DIG_BIST_CTRL_START_Msk                    (0x1UL << PMC_DIG_BIST_CTRL_START_Pos)               /*!< 0x00000001 */
#define PMC_DIG_BIST_CTRL_START                        PMC_DIG_BIST_CTRL_START_Msk                         /*!< </spirit:description> */
#define PMC_DIG_BIST_CTRL_STATUS_Pos                   (4U)
#define PMC_DIG_BIST_CTRL_STATUS_Msk                   (0x7UL << PMC_DIG_BIST_CTRL_STATUS_Pos)              /*!< 0x00000070 */
#define PMC_DIG_BIST_CTRL_STATUS                       PMC_DIG_BIST_CTRL_STATUS_Msk                        /*!< </spirit:description> */
#define PMC_DIG_BIST_CTRL_STATUS_0                   (0x1UL << PMC_DIG_BIST_CTRL_STATUS_Pos)               /*!< 0x00000010 */
#define PMC_DIG_BIST_CTRL_STATUS_1                   (0x2UL << PMC_DIG_BIST_CTRL_STATUS_Pos)               /*!< 0x00000020 */
#define PMC_DIG_BIST_CTRL_STATUS_2                   (0x4UL << PMC_DIG_BIST_CTRL_STATUS_Pos)               /*!< 0x00000040 */
#define PMC_DIG_BIST_CTRL_NCFEN_Pos                    (8U)
#define PMC_DIG_BIST_CTRL_NCFEN_Msk                    (0x1UL << PMC_DIG_BIST_CTRL_NCFEN_Pos)               /*!< 0x00000100 */
#define PMC_DIG_BIST_CTRL_NCFEN                        PMC_DIG_BIST_CTRL_NCFEN_Msk                         /*!< </spirit:description> */
#define PMC_DIG_BIST_CTRL_NCFST_Pos                    (12U)
#define PMC_DIG_BIST_CTRL_NCFST_Msk                    (0x1UL << PMC_DIG_BIST_CTRL_NCFST_Pos)               /*!< 0x00001000 */
#define PMC_DIG_BIST_CTRL_NCFST                        PMC_DIG_BIST_CTRL_NCFST_Msk                         /*!< </spirit:description> */
#define PMC_DIG_BIST_CTRL_IRQEN_Pos                    (16U)
#define PMC_DIG_BIST_CTRL_IRQEN_Msk                    (0x1UL << PMC_DIG_BIST_CTRL_IRQEN_Pos)               /*!< 0x00010000 */
#define PMC_DIG_BIST_CTRL_IRQEN                        PMC_DIG_BIST_CTRL_IRQEN_Msk                         /*!< </spirit:description> */
#define PMC_DIG_BIST_CTRL_IRQST_Pos                    (20U)
#define PMC_DIG_BIST_CTRL_IRQST_Msk                    (0x1UL << PMC_DIG_BIST_CTRL_IRQST_Pos)               /*!< 0x00100000 */
#define PMC_DIG_BIST_CTRL_IRQST                        PMC_DIG_BIST_CTRL_IRQST_Msk                         /*!< </spirit:description> */

/*************  Bit definition for PMC_DIG_BIST_TIME10 register  **************/
#define PMC_DIG_BIST_TIME10_TIME_0_Pos                 (0U)
#define PMC_DIG_BIST_TIME10_TIME_0_Msk                 (0xFFFUL << PMC_DIG_BIST_TIME10_TIME_0_Pos)          /*!< 0x00000FFF */
#define PMC_DIG_BIST_TIME10_TIME_0                     PMC_DIG_BIST_TIME10_TIME_0_Msk                      /*!< </spirit:description> */
#define PMC_DIG_BIST_TIME10_TIME_1_Pos                 (16U)
#define PMC_DIG_BIST_TIME10_TIME_1_Msk                 (0xFFFUL << PMC_DIG_BIST_TIME10_TIME_1_Pos)          /*!< 0x0FFF0000 */
#define PMC_DIG_BIST_TIME10_TIME_1                     PMC_DIG_BIST_TIME10_TIME_1_Msk                      /*!< </spirit:description> */

/*************  Bit definition for PMC_DIG_BIST_TIME32 register  **************/
#define PMC_DIG_BIST_TIME32_TIME_2_Pos                 (0U)
#define PMC_DIG_BIST_TIME32_TIME_2_Msk                 (0xFFFUL << PMC_DIG_BIST_TIME32_TIME_2_Pos)          /*!< 0x00000FFF */
#define PMC_DIG_BIST_TIME32_TIME_2                     PMC_DIG_BIST_TIME32_TIME_2_Msk                      /*!< </spirit:description> */
#define PMC_DIG_BIST_TIME32_TIME_3_Pos                 (16U)
#define PMC_DIG_BIST_TIME32_TIME_3_Msk                 (0xFFFUL << PMC_DIG_BIST_TIME32_TIME_3_Pos)          /*!< 0x0FFF0000 */
#define PMC_DIG_BIST_TIME32_TIME_3                     PMC_DIG_BIST_TIME32_TIME_3_Msk                      /*!< </spirit:description> */

/*************  Bit definition for PMC_DIG_BIST_TIME65 register  **************/
#define PMC_DIG_BIST_TIME65_TIME_5_Pos                 (0U)
#define PMC_DIG_BIST_TIME65_TIME_5_Msk                 (0xFFFUL << PMC_DIG_BIST_TIME65_TIME_5_Pos)          /*!< 0x00000FFF */
#define PMC_DIG_BIST_TIME65_TIME_5                     PMC_DIG_BIST_TIME65_TIME_5_Msk                      /*!< </spirit:description> */
#define PMC_DIG_BIST_TIME65_TIME_6_Pos                 (16U)
#define PMC_DIG_BIST_TIME65_TIME_6_Msk                 (0xFFFUL << PMC_DIG_BIST_TIME65_TIME_6_Pos)          /*!< 0x0FFF0000 */
#define PMC_DIG_BIST_TIME65_TIME_6                     PMC_DIG_BIST_TIME65_TIME_6_Msk                      /*!< </spirit:description> */

#define PMC_DIG_BASE           0x4000D000UL 


#define PMC_DIG                ((PMC_DIG_TypeDef *) PMC_DIG_BASE) 

#endif /* __SR5E1_PMC_DIG_H */

