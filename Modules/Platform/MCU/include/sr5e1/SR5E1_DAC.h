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

#ifndef __SR5E1_DAC_H
#define __SR5E1_DAC_H
/*******************************************************************************
 * REVISION HISTORY                                                            *
 * REV       DATE       RM REV          DESCRIPTION OF CHANGE                  *
 * ------ ----------- ------------ --------------------------------------------*
 * 1.1A1  21-Feb-2022 Reb 1 Draft C     SR5E1_RDP_0_2_Rev1_C_18FEB22           *
 *                                      Updated DAC3 and DAC4 base address     *
 * ------ ----------- ------------ --------------------------------------------*
 * 1.0A1  18-Feb-2022 Rev 1 Draft C     SR5E1_RDP_0_1_Rev1_C_18FEB22           *
 ******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                                   (DAC)                                   */
/*                                                                            */
/******************************************************************************/
typedef struct
{
  __IO uint32_t CR;          /*!< CR         Address offset: 0x00 */
  __IO uint32_t SWTRIGR;     /*!< SWTRIGR    Address offset: 0x04 */
  __IO uint32_t DHR12R1;     /*!< DHR12R1    Address offset: 0x08 */
  __IO uint32_t DHR12L1;     /*!< DHR12L1    Address offset: 0x0C */
  __IO uint32_t DHR8R1;      /*!< DHR8R1     Address offset: 0x10 */
  __IO uint32_t DHR12R2;     /*!< DHR12R2    Address offset: 0x14 */
  __IO uint32_t DHR12L2;     /*!< DHR12L2    Address offset: 0x18 */
  __IO uint32_t DHR8R2;      /*!< DHR8R2     Address offset: 0x1C */
  __IO uint32_t DHR12RD;     /*!< DHR12RD    Address offset: 0x20 */
  __IO uint32_t DHR12LD;     /*!< DHR12LD    Address offset: 0x24 */
  __IO uint32_t DHR8RD;      /*!< DHR8RD     Address offset: 0x28 */
  __IO uint32_t DOR1;        /*!< DOR1       Address offset: 0x2C */
  __IO uint32_t DOR2;        /*!< DOR2       Address offset: 0x30 */
  __IO uint32_t SR;          /*!< SR         Address offset: 0x34 */
  __IO uint32_t CCR;         /*!< CCR        Address offset: 0x38 */
  __IO uint32_t MCR;         /*!< MCR        Address offset: 0x3C */
  __IO uint32_t SHSR1;       /*!< SHSR1      Address offset: 0x40 */
  __IO uint32_t SHSR2;       /*!< SHSR2      Address offset: 0x44 */
  __IO uint32_t SHHR;        /*!< SHHR       Address offset: 0x48 */
  __IO uint32_t SHRR;        /*!< SHRR       Address offset: 0x4C */
       uint32_t RESERVED0[2];  /*!< Reserved Address offset: 0x50-0x54 */
  __IO uint32_t STR1;        /*!< STR1       Address offset: 0x58 */
  __IO uint32_t STR2;        /*!< STR2       Address offset: 0x5C */
  __IO uint32_t STMODR;      /*!< STMODR     Address offset: 0x60 */
} DAC_TypeDef;


/********************  Bit definition for DAC_CR register  ********************/
#define DAC_CR_EN1_Pos                 (0U)
#define DAC_CR_EN1_Msk                  (0x1UL << DAC_CR_EN1_Pos)       /*!< 0x00000001 */
#define DAC_CR_EN1                     DAC_CR_EN1_Msk                  /*!< </spirit:description> */
#define DAC_CR_TEN1_Pos                (1U)
#define DAC_CR_TEN1_Msk                 (0x1UL << DAC_CR_TEN1_Pos)      /*!< 0x00000002 */
#define DAC_CR_TEN1                    DAC_CR_TEN1_Msk                 /*!< </spirit:description> */
#define DAC_CR_TSEL1_Pos               (2U)
#define DAC_CR_TSEL1_Msk                (0xFUL << DAC_CR_TSEL1_Pos)     /*!< 0x0000003C */
#define DAC_CR_TSEL1                   DAC_CR_TSEL1_Msk                /*!< </spirit:description> */
#define DAC_CR_TSEL1_0                 (0x1UL << DAC_CR_TSEL1_Pos)     /*!< 0x00000004 */
#define DAC_CR_TSEL1_1                 (0x2UL << DAC_CR_TSEL1_Pos)     /*!< 0x00000008 */
#define DAC_CR_TSEL1_2                 (0x4UL << DAC_CR_TSEL1_Pos)     /*!< 0x00000010 */
#define DAC_CR_TSEL1_3                 (0x8UL << DAC_CR_TSEL1_Pos)     /*!< 0x00000020 */
#define DAC_CR_WAVE1_Pos               (6U)
#define DAC_CR_WAVE1_Msk                (0x3UL << DAC_CR_WAVE1_Pos)     /*!< 0x000000C0 */
#define DAC_CR_WAVE1                   DAC_CR_WAVE1_Msk                /*!< </spirit:description> */
#define DAC_CR_WAVE1_0                 (0x1UL << DAC_CR_WAVE1_Pos)     /*!< 0x00000040 */
#define DAC_CR_WAVE1_1                 (0x2UL << DAC_CR_WAVE1_Pos)     /*!< 0x00000080 */
#define DAC_CR_MAMP1_Pos               (8U)
#define DAC_CR_MAMP1_Msk                (0xFUL << DAC_CR_MAMP1_Pos)     /*!< 0x00000F00 */
#define DAC_CR_MAMP1                   DAC_CR_MAMP1_Msk                /*!< </spirit:description> */
#define DAC_CR_MAMP1_0                 (0x1UL << DAC_CR_MAMP1_Pos)     /*!< 0x00000100 */
#define DAC_CR_MAMP1_1                 (0x2UL << DAC_CR_MAMP1_Pos)     /*!< 0x00000200 */
#define DAC_CR_MAMP1_2                 (0x4UL << DAC_CR_MAMP1_Pos)     /*!< 0x00000400 */
#define DAC_CR_MAMP1_3                 (0x8UL << DAC_CR_MAMP1_Pos)     /*!< 0x00000800 */
#define DAC_CR_DMAEN1_Pos              (12U)
#define DAC_CR_DMAEN1_Msk               (0x1UL << DAC_CR_DMAEN1_Pos)    /*!< 0x00001000 */
#define DAC_CR_DMAEN1                  DAC_CR_DMAEN1_Msk               /*!< </spirit:description> */
#define DAC_CR_DMAUDRIE1_Pos           (13U)
#define DAC_CR_DMAUDRIE1_Msk              (0x1UL << DAC_CR_DMAUDRIE1_Pos) /*!< 0x00002000 */
#define DAC_CR_DMAUDRIE1               DAC_CR_DMAUDRIE1_Msk            /*!< </spirit:description> */
#define DAC_CR_CEN1_Pos                (14U)
#define DAC_CR_CEN1_Msk                 (0x1UL << DAC_CR_CEN1_Pos)      /*!< 0x00004000 */
#define DAC_CR_CEN1                    DAC_CR_CEN1_Msk                 /*!< </spirit:description> */
#define DAC_CR_HFSEL_Pos               (15U)
#define DAC_CR_HFSEL_Msk                (0x1UL << DAC_CR_HFSEL_Pos)     /*!< 0x00008000 */
#define DAC_CR_HFSEL                   DAC_CR_HFSEL_Msk                /*!< </spirit:description> */
#define DAC_CR_EN2_Pos                 (16U)
#define DAC_CR_EN2_Msk                  (0x1UL << DAC_CR_EN2_Pos)       /*!< 0x00010000 */
#define DAC_CR_EN2                     DAC_CR_EN2_Msk                  /*!< </spirit:description> */
#define DAC_CR_TEN2_Pos                (17U)
#define DAC_CR_TEN2_Msk                 (0x1UL << DAC_CR_TEN2_Pos)      /*!< 0x00020000 */
#define DAC_CR_TEN2                    DAC_CR_TEN2_Msk                 /*!< </spirit:description> */
#define DAC_CR_TSEL2_Pos               (18U)
#define DAC_CR_TSEL2_Msk                (0xFUL << DAC_CR_TSEL2_Pos)     /*!< 0x003C0000 */
#define DAC_CR_TSEL2                   DAC_CR_TSEL2_Msk                /*!< </spirit:description> */
#define DAC_CR_TSEL2_0                 (0x1UL << DAC_CR_TSEL2_Pos)     /*!< 0x00040000 */
#define DAC_CR_TSEL2_1                 (0x2UL << DAC_CR_TSEL2_Pos)     /*!< 0x00080000 */
#define DAC_CR_TSEL2_2                 (0x4UL << DAC_CR_TSEL2_Pos)     /*!< 0x00100000 */
#define DAC_CR_TSEL2_3                 (0x8UL << DAC_CR_TSEL2_Pos)     /*!< 0x00200000 */
#define DAC_CR_WAVE2_Pos               (22U)
#define DAC_CR_WAVE2_Msk                (0x3UL << DAC_CR_WAVE2_Pos)     /*!< 0x00C00000 */
#define DAC_CR_WAVE2                   DAC_CR_WAVE2_Msk                /*!< </spirit:description> */
#define DAC_CR_WAVE2_0                 (0x1UL << DAC_CR_WAVE2_Pos)     /*!< 0x00400000 */
#define DAC_CR_WAVE2_1                 (0x2UL << DAC_CR_WAVE2_Pos)     /*!< 0x00800000 */
#define DAC_CR_MAMP2_Pos               (24U)
#define DAC_CR_MAMP2_Msk                (0xFUL << DAC_CR_MAMP2_Pos)     /*!< 0x0F000000 */
#define DAC_CR_MAMP2                   DAC_CR_MAMP2_Msk                /*!< </spirit:description> */
#define DAC_CR_MAMP2_0                 (0x1UL << DAC_CR_MAMP2_Pos)     /*!< 0x01000000 */
#define DAC_CR_MAMP2_1                 (0x2UL << DAC_CR_MAMP2_Pos)     /*!< 0x02000000 */
#define DAC_CR_MAMP2_2                 (0x4UL << DAC_CR_MAMP2_Pos)     /*!< 0x04000000 */
#define DAC_CR_MAMP2_3                 (0x8UL << DAC_CR_MAMP2_Pos)     /*!< 0x08000000 */
#define DAC_CR_DMAEN2_Pos              (28U)
#define DAC_CR_DMAEN2_Msk               (0x1UL << DAC_CR_DMAEN2_Pos)    /*!< 0x10000000 */
#define DAC_CR_DMAEN2                  DAC_CR_DMAEN2_Msk               /*!< </spirit:description> */
#define DAC_CR_DMAUDRIE2_Pos           (29U)
#define DAC_CR_DMAUDRIE2_Msk              (0x1UL << DAC_CR_DMAUDRIE2_Pos) /*!< 0x20000000 */
#define DAC_CR_DMAUDRIE2               DAC_CR_DMAUDRIE2_Msk            /*!< </spirit:description> */
#define DAC_CR_CEN2_Pos                (30U)
#define DAC_CR_CEN2_Msk                 (0x1UL << DAC_CR_CEN2_Pos)      /*!< 0x40000000 */
#define DAC_CR_CEN2                    DAC_CR_CEN2_Msk                 /*!< </spirit:description> */

/*****************  Bit definition for DAC_SWTRIGR register  ******************/
#define DAC_SWTRIGR_SWTRIG1_Pos        (0U)
#define DAC_SWTRIGR_SWTRIG1_Msk         (0x1UL << DAC_SWTRIGR_SWTRIG1_Pos)  /*!< 0x00000001 */
#define DAC_SWTRIGR_SWTRIG1            DAC_SWTRIGR_SWTRIG1_Msk         /*!< </spirit:description> */
#define DAC_SWTRIGR_SWTRIG2_Pos        (1U)
#define DAC_SWTRIGR_SWTRIG2_Msk         (0x1UL << DAC_SWTRIGR_SWTRIG2_Pos)  /*!< 0x00000002 */
#define DAC_SWTRIGR_SWTRIG2            DAC_SWTRIGR_SWTRIG2_Msk         /*!< </spirit:description> */
#define DAC_SWTRIGR_SWTRIGB1_Pos       (16U)
#define DAC_SWTRIGR_SWTRIGB1_Msk        (0x1UL << DAC_SWTRIGR_SWTRIGB1_Pos)   /*!< 0x00010000 */
#define DAC_SWTRIGR_SWTRIGB1           DAC_SWTRIGR_SWTRIGB1_Msk        /*!< </spirit:description> */
#define DAC_SWTRIGR_SWTRIGB2_Pos       (17U)
#define DAC_SWTRIGR_SWTRIGB2_Msk        (0x1UL << DAC_SWTRIGR_SWTRIGB2_Pos)   /*!< 0x00020000 */
#define DAC_SWTRIGR_SWTRIGB2           DAC_SWTRIGR_SWTRIGB2_Msk        /*!< </spirit:description> */

/*****************  Bit definition for DAC_DHR12R1 register  ******************/
#define DAC_DHR12R1_DACC1DHR_Pos       (0U)
#define DAC_DHR12R1_DACC1DHR_Msk        (0xFFFUL << DAC_DHR12R1_DACC1DHR_Pos)     /*!< 0x00000FFF */
#define DAC_DHR12R1_DACC1DHR           DAC_DHR12R1_DACC1DHR_Msk        /*!< </spirit:description> */
#define DAC_DHR12R1_DACC1DHRB_Pos      (16U)
#define DAC_DHR12R1_DACC1DHRB_Msk       (0xFFFUL << DAC_DHR12R1_DACC1DHRB_Pos)      /*!< 0x0FFF0000 */
#define DAC_DHR12R1_DACC1DHRB          DAC_DHR12R1_DACC1DHRB_Msk       /*!< </spirit:description> */

/*****************  Bit definition for DAC_DHR12L1 register  ******************/
#define DAC_DHR12L1_DACC1DHR_Pos       (4U)
#define DAC_DHR12L1_DACC1DHR_Msk        (0xFFFUL << DAC_DHR12L1_DACC1DHR_Pos)     /*!< 0x0000FFF0 */
#define DAC_DHR12L1_DACC1DHR           DAC_DHR12L1_DACC1DHR_Msk        /*!< </spirit:description> */
#define DAC_DHR12L1_DACC1DHRB_Pos      (20U)
#define DAC_DHR12L1_DACC1DHRB_Msk       (0xFFFUL << DAC_DHR12L1_DACC1DHRB_Pos)      /*!< 0xFFF00000 */
#define DAC_DHR12L1_DACC1DHRB          DAC_DHR12L1_DACC1DHRB_Msk       /*!< </spirit:description> */

/******************  Bit definition for DAC_DHR8R1 register  ******************/
#define DAC_DHR8R1_DACC1DHR_Pos        (0U)
#define DAC_DHR8R1_DACC1DHR_Msk         (0xFFUL << DAC_DHR8R1_DACC1DHR_Pos)   /*!< 0x000000FF */
#define DAC_DHR8R1_DACC1DHR            DAC_DHR8R1_DACC1DHR_Msk         /*!< </spirit:description> */
#define DAC_DHR8R1_DACC1DHRB_Pos       (8U)
#define DAC_DHR8R1_DACC1DHRB_Msk        (0xFFUL << DAC_DHR8R1_DACC1DHRB_Pos)    /*!< 0x0000FF00 */
#define DAC_DHR8R1_DACC1DHRB           DAC_DHR8R1_DACC1DHRB_Msk        /*!< </spirit:description> */

/*****************  Bit definition for DAC_DHR12R2 register  ******************/
#define DAC_DHR12R2_DACC2DHR_Pos       (0U)
#define DAC_DHR12R2_DACC2DHR_Msk        (0xFFFUL << DAC_DHR12R2_DACC2DHR_Pos)     /*!< 0x00000FFF */
#define DAC_DHR12R2_DACC2DHR           DAC_DHR12R2_DACC2DHR_Msk        /*!< </spirit:description> */
#define DAC_DHR12R2_DACC2DHRB_Pos      (16U)
#define DAC_DHR12R2_DACC2DHRB_Msk       (0xFFFUL << DAC_DHR12R2_DACC2DHRB_Pos)      /*!< 0x0FFF0000 */
#define DAC_DHR12R2_DACC2DHRB          DAC_DHR12R2_DACC2DHRB_Msk       /*!< </spirit:description> */

/*****************  Bit definition for DAC_DHR12L2 register  ******************/
#define DAC_DHR12L2_DACC2DHR_Pos       (4U)
#define DAC_DHR12L2_DACC2DHR_Msk        (0xFFFUL << DAC_DHR12L2_DACC2DHR_Pos)     /*!< 0x0000FFF0 */
#define DAC_DHR12L2_DACC2DHR           DAC_DHR12L2_DACC2DHR_Msk        /*!< </spirit:description> */
#define DAC_DHR12L2_DACC2DHRB_Pos      (20U)
#define DAC_DHR12L2_DACC2DHRB_Msk       (0xFFFUL << DAC_DHR12L2_DACC2DHRB_Pos)      /*!< 0xFFF00000 */
#define DAC_DHR12L2_DACC2DHRB          DAC_DHR12L2_DACC2DHRB_Msk       /*!< </spirit:description> */

/******************  Bit definition for DAC_DHR8R2 register  ******************/
#define DAC_DHR8R2_DACC2DHR_Pos        (0U)
#define DAC_DHR8R2_DACC2DHR_Msk         (0xFFUL << DAC_DHR8R2_DACC2DHR_Pos)   /*!< 0x000000FF */
#define DAC_DHR8R2_DACC2DHR            DAC_DHR8R2_DACC2DHR_Msk         /*!< </spirit:description> */
#define DAC_DHR8R2_DACC2DHRB_Pos       (8U)
#define DAC_DHR8R2_DACC2DHRB_Msk        (0xFFUL << DAC_DHR8R2_DACC2DHRB_Pos)    /*!< 0x0000FF00 */
#define DAC_DHR8R2_DACC2DHRB           DAC_DHR8R2_DACC2DHRB_Msk        /*!< </spirit:description> */

/*****************  Bit definition for DAC_DHR12RD register  ******************/
#define DAC_DHR12RD_DACC1DHR_Pos       (0U)
#define DAC_DHR12RD_DACC1DHR_Msk        (0xFFFUL << DAC_DHR12RD_DACC1DHR_Pos)     /*!< 0x00000FFF */
#define DAC_DHR12RD_DACC1DHR           DAC_DHR12RD_DACC1DHR_Msk        /*!< </spirit:description> */
#define DAC_DHR12RD_DACC2DHR_Pos       (16U)
#define DAC_DHR12RD_DACC2DHR_Msk        (0xFFFUL << DAC_DHR12RD_DACC2DHR_Pos)     /*!< 0x0FFF0000 */
#define DAC_DHR12RD_DACC2DHR           DAC_DHR12RD_DACC2DHR_Msk        /*!< </spirit:description> */

/*****************  Bit definition for DAC_DHR12LD register  ******************/
#define DAC_DHR12LD_DACC1DHR_Pos       (4U)
#define DAC_DHR12LD_DACC1DHR_Msk        (0xFFFUL << DAC_DHR12LD_DACC1DHR_Pos)     /*!< 0x0000FFF0 */
#define DAC_DHR12LD_DACC1DHR           DAC_DHR12LD_DACC1DHR_Msk        /*!< </spirit:description> */
#define DAC_DHR12LD_DACC2DHR_Pos       (20U)
#define DAC_DHR12LD_DACC2DHR_Msk        (0xFFFUL << DAC_DHR12LD_DACC2DHR_Pos)     /*!< 0xFFF00000 */
#define DAC_DHR12LD_DACC2DHR           DAC_DHR12LD_DACC2DHR_Msk        /*!< </spirit:description> */

/******************  Bit definition for DAC_DHR8RD register  ******************/
#define DAC_DHR8RD_DACC1DHR_Pos        (0U)
#define DAC_DHR8RD_DACC1DHR_Msk         (0xFFUL << DAC_DHR8RD_DACC1DHR_Pos)   /*!< 0x000000FF */
#define DAC_DHR8RD_DACC1DHR            DAC_DHR8RD_DACC1DHR_Msk         /*!< </spirit:description> */
#define DAC_DHR8RD_DACC2DHR_Pos        (8U)
#define DAC_DHR8RD_DACC2DHR_Msk         (0xFFUL << DAC_DHR8RD_DACC2DHR_Pos)   /*!< 0x0000FF00 */
#define DAC_DHR8RD_DACC2DHR            DAC_DHR8RD_DACC2DHR_Msk         /*!< </spirit:description> */

/*******************  Bit definition for DAC_DOR1 register  *******************/
#define DAC_DOR1_DACC1DOR_Pos          (0U)
#define DAC_DOR1_DACC1DOR_Msk           (0xFFFUL << DAC_DOR1_DACC1DOR_Pos)  /*!< 0x00000FFF */
#define DAC_DOR1_DACC1DOR              DAC_DOR1_DACC1DOR_Msk           /*!< </spirit:description> */
#define DAC_DOR1_DACC1DORB_Pos         (16U)
#define DAC_DOR1_DACC1DORB_Msk          (0xFFFUL << DAC_DOR1_DACC1DORB_Pos)   /*!< 0x0FFF0000 */
#define DAC_DOR1_DACC1DORB             DAC_DOR1_DACC1DORB_Msk          /*!< </spirit:description> */

/*******************  Bit definition for DAC_DOR2 register  *******************/
#define DAC_DOR2_DACC2DOR_Pos          (0U)
#define DAC_DOR2_DACC2DOR_Msk           (0xFFFUL << DAC_DOR2_DACC2DOR_Pos)  /*!< 0x00000FFF */
#define DAC_DOR2_DACC2DOR              DAC_DOR2_DACC2DOR_Msk           /*!< </spirit:description> */
#define DAC_DOR2_DACC2DORB_Pos         (16U)
#define DAC_DOR2_DACC2DORB_Msk          (0xFFFUL << DAC_DOR2_DACC2DORB_Pos)   /*!< 0x0FFF0000 */
#define DAC_DOR2_DACC2DORB             DAC_DOR2_DACC2DORB_Msk          /*!< </spirit:description> */

/********************  Bit definition for DAC_SR register  ********************/
#define DAC_SR_DAC1RDY_Pos               (11U)
#define DAC_SR_DAC1RDY_Msk               (0x1UL << DAC_SR_DAC1RDY_Pos)  /*!< 0x00000800 */
#define DAC_SR_DAC1RDY                   DAC_SR_DAC1RDY_Msk            /*!< </spirit:description> */
#define DAC_SR_DORSTAT1_Pos            (12U)
#define DAC_SR_DORSTAT1_Msk             (0x1UL << DAC_SR_DORSTAT1_Pos)  /*!< 0x00001000 */
#define DAC_SR_DORSTAT1                DAC_SR_DORSTAT1_Msk             /*!< </spirit:description> */
#define DAC_SR_DMAUDR1_Pos             (13U)
#define DAC_SR_DMAUDR1_Msk              (0x1UL << DAC_SR_DMAUDR1_Pos)   /*!< 0x00002000 */
#define DAC_SR_DMAUDR1                 DAC_SR_DMAUDR1_Msk              /*!< </spirit:description> */
#define DAC_SR_CAL_FLAG1_Pos           (14U)
#define DAC_SR_CAL_FLAG1_Msk              (0x1UL << DAC_SR_CAL_FLAG1_Pos) /*!< 0x00004000 */
#define DAC_SR_CAL_FLAG1               DAC_SR_CAL_FLAG1_Msk            /*!< </spirit:description> */
#define DAC_SR_BWST1_Pos               (15U)
#define DAC_SR_BWST1_Msk                (0x1UL << DAC_SR_BWST1_Pos)     /*!< 0x00008000 */
#define DAC_SR_BWST1                   DAC_SR_BWST1_Msk                /*!< </spirit:description> */
#define DAC_SR_DAC2RDY_Pos             (27U)
#define DAC_SR_DAC2RDY_Msk              (0x1UL << DAC_SR_DAC2RDY_Pos)   /*!< 0x08000000 */
#define DAC_SR_DAC2RDY                 DAC_SR_DAC2RDY_Msk              /*!< </spirit:description> */
#define DAC_SR_DORSTAT2_Pos            (28U)
#define DAC_SR_DORSTAT2_Msk             (0x1UL << DAC_SR_DORSTAT2_Pos)  /*!< 0x10000000 */
#define DAC_SR_DORSTAT2                DAC_SR_DORSTAT2_Msk             /*!< </spirit:description> */
#define DAC_SR_DMAUDR2_Pos             (29U)
#define DAC_SR_DMAUDR2_Msk              (0x1UL << DAC_SR_DMAUDR2_Pos)   /*!< 0x20000000 */
#define DAC_SR_DMAUDR2                 DAC_SR_DMAUDR2_Msk              /*!< </spirit:description> */
#define DAC_SR_CAL_FLAG2_Pos           (30U)
#define DAC_SR_CAL_FLAG2_Msk              (0x1UL << DAC_SR_CAL_FLAG2_Pos) /*!< 0x40000000 */
#define DAC_SR_CAL_FLAG2               DAC_SR_CAL_FLAG2_Msk            /*!< </spirit:description> */
#define DAC_SR_BWST2_Pos               (31U)
#define DAC_SR_BWST2_Msk                (0x1UL << DAC_SR_BWST2_Pos)     /*!< 0x80000000 */
#define DAC_SR_BWST2                   DAC_SR_BWST2_Msk                /*!< </spirit:description> */

/*******************  Bit definition for DAC_CCR register  ********************/
#define DAC_CCR_OTRIM1_Pos             (0U)
#define DAC_CCR_OTRIM1_Msk              (0x1FUL << DAC_CCR_OTRIM1_Pos)  /*!< 0x0000001F */
#define DAC_CCR_OTRIM1                 DAC_CCR_OTRIM1_Msk              /*!< </spirit:description> */
#define DAC_CCR_OTRIM2_Pos             (16U)
#define DAC_CCR_OTRIM2_Msk              (0x1FUL << DAC_CCR_OTRIM2_Pos)  /*!< 0x001F0000 */
#define DAC_CCR_OTRIM2                 DAC_CCR_OTRIM2_Msk              /*!< </spirit:description> */

/*******************  Bit definition for DAC_MCR register  ********************/
#define DAC_MCR_MODE1_Pos              (0U)
#define DAC_MCR_MODE1_Msk               (0x7UL << DAC_MCR_MODE1_Pos)    /*!< 0x00000007 */
#define DAC_MCR_MODE1                  DAC_MCR_MODE1_Msk               /*!< </spirit:description> */
#define DAC_MCR_MODE1_0                (0x1UL << DAC_MCR_MODE1_Pos)    /*!< 0x00000001 */
#define DAC_MCR_MODE1_1                (0x2UL << DAC_MCR_MODE1_Pos)    /*!< 0x00000002 */
#define DAC_MCR_MODE1_2                (0x4UL << DAC_MCR_MODE1_Pos)    /*!< 0x00000004 */
#define DAC_MCR_DMADOUBLE1_Pos         (8U)
#define DAC_MCR_DMADOUBLE1_Msk          (0x1UL << DAC_MCR_DMADOUBLE1_Pos) /*!< 0x00000100 */
#define DAC_MCR_DMADOUBLE1             DAC_MCR_DMADOUBLE1_Msk          /*!< </spirit:description> */
#define DAC_MCR_SINFORMAT1_Pos         (9U)
#define DAC_MCR_SINFORMAT1_Msk          (0x1UL << DAC_MCR_SINFORMAT1_Pos) /*!< 0x00000200 */
#define DAC_MCR_SINFORMAT1             DAC_MCR_SINFORMAT1_Msk          /*!< </spirit:description> */
#define DAC_MCR_HFSEL_Pos              (14U)
#define DAC_MCR_HFSEL_Msk               (0x3UL << DAC_MCR_HFSEL_Pos)    /*!< 0x0000C000 */
#define DAC_MCR_HFSEL                  DAC_MCR_HFSEL_Msk               /*!< </spirit:description> */
#define DAC_MCR_HFSEL_0                (0x1UL << DAC_MCR_HFSEL_Pos)    /*!< 0x00004000 */
#define DAC_MCR_HFSEL_1                (0x2UL << DAC_MCR_HFSEL_Pos)    /*!< 0x00008000 */
#define DAC_MCR_MODE2_Pos              (16U)
#define DAC_MCR_MODE2_Msk               (0x7UL << DAC_MCR_MODE2_Pos)    /*!< 0x00070000 */
#define DAC_MCR_MODE2                  DAC_MCR_MODE2_Msk               /*!< </spirit:description> */
#define DAC_MCR_MODE2_0                (0x1UL << DAC_MCR_MODE2_Pos)    /*!< 0x00010000 */
#define DAC_MCR_MODE2_1                (0x2UL << DAC_MCR_MODE2_Pos)    /*!< 0x00020000 */
#define DAC_MCR_MODE2_2                (0x4UL << DAC_MCR_MODE2_Pos)    /*!< 0x00040000 */
#define DAC_MCR_DMADOUBLE2_Pos         (24U)
#define DAC_MCR_DMADOUBLE2_Msk          (0x1UL << DAC_MCR_DMADOUBLE2_Pos) /*!< 0x01000000 */
#define DAC_MCR_DMADOUBLE2             DAC_MCR_DMADOUBLE2_Msk          /*!< </spirit:description> */
#define DAC_MCR_SINFORMAT2_Pos         (25U)
#define DAC_MCR_SINFORMAT2_Msk          (0x1UL << DAC_MCR_SINFORMAT2_Pos) /*!< 0x02000000 */
#define DAC_MCR_SINFORMAT2             DAC_MCR_SINFORMAT2_Msk          /*!< </spirit:description> */

/******************  Bit definition for DAC_SHSR1 register  *******************/
#define DAC_SHSR1_TSAMPLE1_Pos         (0U)
#define DAC_SHSR1_TSAMPLE1_Msk          (0x3FFUL << DAC_SHSR1_TSAMPLE1_Pos)   /*!< 0x000003FF */
#define DAC_SHSR1_TSAMPLE1             DAC_SHSR1_TSAMPLE1_Msk          /*!< </spirit:description> */

/******************  Bit definition for DAC_SHSR2 register  *******************/
#define DAC_SHSR2_TSAMPLE2_Pos         (0U)
#define DAC_SHSR2_TSAMPLE2_Msk          (0x3FFUL << DAC_SHSR2_TSAMPLE2_Pos)   /*!< 0x000003FF */
#define DAC_SHSR2_TSAMPLE2             DAC_SHSR2_TSAMPLE2_Msk          /*!< </spirit:description> */

/*******************  Bit definition for DAC_SHHR register  *******************/
#define DAC_SHHR_THOLD1_Pos            (0U)
#define DAC_SHHR_THOLD1_Msk              (0x3FFUL << DAC_SHHR_THOLD1_Pos) /*!< 0x000003FF */
#define DAC_SHHR_THOLD1                DAC_SHHR_THOLD1_Msk             /*!< </spirit:description> */
#define DAC_SHHR_THOLD2_Pos            (16U)
#define DAC_SHHR_THOLD2_Msk              (0x3FFUL << DAC_SHHR_THOLD2_Pos) /*!< 0x03FF0000 */
#define DAC_SHHR_THOLD2                DAC_SHHR_THOLD2_Msk             /*!< </spirit:description> */

/*******************  Bit definition for DAC_SHRR register  *******************/
#define DAC_SHRR_TREFRESH1_Pos         (0U)
#define DAC_SHRR_TREFRESH1_Msk          (0xFFUL << DAC_SHRR_TREFRESH1_Pos)  /*!< 0x000000FF */
#define DAC_SHRR_TREFRESH1             DAC_SHRR_TREFRESH1_Msk          /*!< </spirit:description> */
#define DAC_SHRR_TREFRESH2_Pos         (16U)
#define DAC_SHRR_TREFRESH2_Msk          (0xFFUL << DAC_SHRR_TREFRESH2_Pos)  /*!< 0x00FF0000 */
#define DAC_SHRR_TREFRESH2             DAC_SHRR_TREFRESH2_Msk          /*!< </spirit:description> */

/*******************  Bit definition for DAC_STR1 register  *******************/
#define DAC_STR1_STRSTDATA1_Pos        (0U)
#define DAC_STR1_STRSTDATA1_Msk         (0xFFFUL << DAC_STR1_STRSTDATA1_Pos)    /*!< 0x00000FFF */
#define DAC_STR1_STRSTDATA1            DAC_STR1_STRSTDATA1_Msk         /*!< </spirit:description> */
#define DAC_STR1_STDIR1_Pos            (12U)
#define DAC_STR1_STDIR1_Msk             (0x1UL << DAC_STR1_STDIR1_Pos)  /*!< 0x00001000 */
#define DAC_STR1_STDIR1                DAC_STR1_STDIR1_Msk             /*!< </spirit:description> */
#define DAC_STR1_STINCDATA1_Pos        (16U)
#define DAC_STR1_STINCDATA1_Msk         (0xFFFFUL << DAC_STR1_STINCDATA1_Pos)     /*!< 0xFFFF0000 */
#define DAC_STR1_STINCDATA1            DAC_STR1_STINCDATA1_Msk         /*!< </spirit:description> */

/*******************  Bit definition for DAC_STR2 register  *******************/
#define DAC_STR2_STRSTDATA2_Pos        (0U)
#define DAC_STR2_STRSTDATA2_Msk         (0xFFFUL << DAC_STR2_STRSTDATA2_Pos)    /*!< 0x00000FFF */
#define DAC_STR2_STRSTDATA2            DAC_STR2_STRSTDATA2_Msk         /*!< </spirit:description> */
#define DAC_STR2_STDIR2_Pos            (12U)
#define DAC_STR2_STDIR2_Msk             (0x1UL << DAC_STR2_STDIR2_Pos)  /*!< 0x00001000 */
#define DAC_STR2_STDIR2                DAC_STR2_STDIR2_Msk             /*!< </spirit:description> */
#define DAC_STR2_STINCDATA2_Pos        (16U)
#define DAC_STR2_STINCDATA2_Msk         (0xFFFFUL << DAC_STR2_STINCDATA2_Pos)     /*!< 0xFFFF0000 */
#define DAC_STR2_STINCDATA2            DAC_STR2_STINCDATA2_Msk         /*!< </spirit:description> */

/******************  Bit definition for DAC_STMODR register  ******************/
#define DAC_STMODR_STRSTTRIGSEL1_Pos   (0U)
#define DAC_STMODR_STRSTTRIGSEL1_Msk    (0xFUL << DAC_STMODR_STRSTTRIGSEL1_Pos)       /*!< 0x0000000F */
#define DAC_STMODR_STRSTTRIGSEL1       DAC_STMODR_STRSTTRIGSEL1_Msk    /*!< </spirit:description> */
#define DAC_STMODR_STRSTTRIGSEL1_0     (0x1UL << DAC_STMODR_STRSTTRIGSEL1_Pos)         /*!< 0x00000001 */
#define DAC_STMODR_STRSTTRIGSEL1_1     (0x2UL << DAC_STMODR_STRSTTRIGSEL1_Pos)         /*!< 0x00000002 */
#define DAC_STMODR_STRSTTRIGSEL1_2     (0x4UL << DAC_STMODR_STRSTTRIGSEL1_Pos)         /*!< 0x00000004 */
#define DAC_STMODR_STRSTTRIGSEL1_3     (0x8UL << DAC_STMODR_STRSTTRIGSEL1_Pos)         /*!< 0x00000008 */
#define DAC_STMODR_STINCTRIGSEL1_Pos   (8U)
#define DAC_STMODR_STINCTRIGSEL1_Msk    (0xFUL << DAC_STMODR_STINCTRIGSEL1_Pos)       /*!< 0x00000F00 */
#define DAC_STMODR_STINCTRIGSEL1       DAC_STMODR_STINCTRIGSEL1_Msk    /*!< </spirit:description> */
#define DAC_STMODR_STINCTRIGSEL1_0     (0x1UL << DAC_STMODR_STINCTRIGSEL1_Pos)         /*!< 0x00000100 */
#define DAC_STMODR_STINCTRIGSEL1_1     (0x2UL << DAC_STMODR_STINCTRIGSEL1_Pos)         /*!< 0x00000200 */
#define DAC_STMODR_STINCTRIGSEL1_2     (0x4UL << DAC_STMODR_STINCTRIGSEL1_Pos)         /*!< 0x00000400 */
#define DAC_STMODR_STINCTRIGSEL1_3     (0x8UL << DAC_STMODR_STINCTRIGSEL1_Pos)         /*!< 0x00000800 */
#define DAC_STMODR_STRSTTRIGSEL2_Pos   (16U)
#define DAC_STMODR_STRSTTRIGSEL2_Msk    (0xFUL << DAC_STMODR_STRSTTRIGSEL2_Pos)       /*!< 0x000F0000 */
#define DAC_STMODR_STRSTTRIGSEL2       DAC_STMODR_STRSTTRIGSEL2_Msk    /*!< </spirit:description> */
#define DAC_STMODR_STRSTTRIGSEL2_0     (0x1UL << DAC_STMODR_STRSTTRIGSEL2_Pos)         /*!< 0x00010000 */
#define DAC_STMODR_STRSTTRIGSEL2_1     (0x2UL << DAC_STMODR_STRSTTRIGSEL2_Pos)         /*!< 0x00020000 */
#define DAC_STMODR_STRSTTRIGSEL2_2     (0x4UL << DAC_STMODR_STRSTTRIGSEL2_Pos)         /*!< 0x00040000 */
#define DAC_STMODR_STRSTTRIGSEL2_3     (0x8UL << DAC_STMODR_STRSTTRIGSEL2_Pos)         /*!< 0x00080000 */
#define DAC_STMODR_STINCTRIGSEL2_Pos   (24U)
#define DAC_STMODR_STINCTRIGSEL2_Msk    (0xFUL << DAC_STMODR_STINCTRIGSEL2_Pos)       /*!< 0x0F000000 */
#define DAC_STMODR_STINCTRIGSEL2       DAC_STMODR_STINCTRIGSEL2_Msk    /*!< </spirit:description> */
#define DAC_STMODR_STINCTRIGSEL2_0     (0x1UL << DAC_STMODR_STINCTRIGSEL2_Pos)         /*!< 0x01000000 */
#define DAC_STMODR_STINCTRIGSEL2_1     (0x2UL << DAC_STMODR_STINCTRIGSEL2_Pos)         /*!< 0x02000000 */
#define DAC_STMODR_STINCTRIGSEL2_2     (0x4UL << DAC_STMODR_STINCTRIGSEL2_Pos)         /*!< 0x04000000 */
#define DAC_STMODR_STINCTRIGSEL2_3     (0x8UL << DAC_STMODR_STINCTRIGSEL2_Pos)         /*!< 0x08000000 */

#define BDAC1_BASE          0x48009000UL 
#define DAC1_BASE           0x48009400UL 
#define DAC2_BASE           0x48009800UL 

#define DAC3_BASE           0x44009400UL 
#define DAC4_BASE           0x44009800UL 

#define BDAC1               ((DAC_TypeDef *) BDAC1_BASE) 
#define DAC1                ((DAC_TypeDef *) DAC1_BASE) 
#define DAC2                ((DAC_TypeDef *) DAC2_BASE) 
#define DAC3                ((DAC_TypeDef *) DAC3_BASE) 
#define DAC4                ((DAC_TypeDef *) DAC4_BASE) 

#endif /* __SR5E1_DAC_H */

