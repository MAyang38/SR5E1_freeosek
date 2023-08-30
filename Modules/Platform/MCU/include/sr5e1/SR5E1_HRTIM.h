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
/*******************************************************************************
 * REVISION HISTORY                                                            *
 * REV       DATE       RM REV          DESCRIPTION OF CHANGE                  *
 * ------ ----------- ------------ --------------------------------------------*
 * 1.0C2  16-Mar-2022 Rev 1 Draft C     SR5E1_RDP_0_1_Rev1_C_18FEB22           *
 *                                      Fixed Access rights                    *
 *                                      Fixed TF1SET, TF1RST, TIMFCMP1, TIMFCMP2 
 *                                      fields for CPT[12]xCR registers of all *
 *                                      Timers                                 *
 ******************************************************************************/

#ifndef __SR5E1_HRTIM_H
#define __SR5E1_HRTIM_H

#define c7amba_hrtim1_v2_0

/******************************************************************************/
/*                                                                            */
/*                       HRTIM_Master (HRTIM_Master)                          */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO uint32_t MCR;           /*!< MCR          Address offset: 0x00 */
  __I  uint32_t MISR;          /*!< MISR         Address offset: 0x04 */
  __O  uint32_t MICR;          /*!< MICR         Address offset: 0x08 */
  __IO uint32_t MDIER;         /*!< MDIER        Address offset: 0x0C */
  __IO uint32_t MCNTR;         /*!< MCNTR        Address offset: 0x10 */
  __IO uint32_t MPER;          /*!< MPER         Address offset: 0x14 */
  __IO uint32_t MREP;          /*!< MREP         Address offset: 0x18 */
  __IO uint32_t MCMP1R;        /*!< MCMP1R       Address offset: 0x1C */
       uint32_t RESERVED0;     /*!< Reserved     Address offset: 0x20 */
  __IO uint32_t MCMP2R;        /*!< MCMP2R       Address offset: 0x24 */
  __IO uint32_t MCMP3R;        /*!< MCMP3R       Address offset: 0x28 */
  __IO uint32_t MCMP4R;        /*!< MCMP4R       Address offset: 0x2C */
  __IO uint32_t PADDING_0[20]; /*!< Padding to grant alignment in header file Address offset: 0x30-0x7C */
} HRTIM_Master_TypeDef;

/******************************************************************************/
/*                                                                            */
/*                               (HRTIM_Timerx)                               */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO uint32_t TIMxCR;    /*!< TIMxCR   Address offset: 0x00 */
  __I  uint32_t TIMxISR;   /*!< TIMxISR  Address offset: 0x04 */
  __O  uint32_t TIMxICR;   /*!< TIMxICR  Address offset: 0x08 */
  __IO uint32_t TIMxDIER;  /*!< TIMxDIER Address offset: 0x0C */
  __IO uint32_t CNTxR;     /*!< CNTxR    Address offset: 0x10 */
  __IO uint32_t PERxR;     /*!< PERxR    Address offset: 0x14 */
  __IO uint32_t REPxR;     /*!< REPxR    Address offset: 0x18 */
  __IO uint32_t CMP1xR;    /*!< CMP1xR   Address offset: 0x1C */
  __IO uint32_t CMP1CxR;   /*!< CMP1CxR  Address offset: 0x20 */
  __IO uint32_t CMP2xR;    /*!< CMP2xR   Address offset: 0x24 */
  __IO uint32_t CMP3xR;    /*!< CMP3xR   Address offset: 0x28 */
  __IO uint32_t CMP4xR;    /*!< CMP4xR   Address offset: 0x2C */
  __I  uint32_t CPT1xR;    /*!< CPT1xR   Address offset: 0x30 */
  __I  uint32_t CPT2xR;    /*!< CPT2xR   Address offset: 0x34 */
  __IO uint32_t DTxR;      /*!< DTxR     Address offset: 0x38 */
  __IO uint32_t SETx1R;    /*!< SETx1R   Address offset: 0x3C */
  __IO uint32_t RSTx1R;    /*!< RSTx1R   Address offset: 0x40 */
  __IO uint32_t SETx2R;    /*!< SETx2R   Address offset: 0x44 */
  __IO uint32_t RSTx2R;    /*!< RSTx2R   Address offset: 0x48 */
  __IO uint32_t EEFxR1;    /*!< EEFxR1   Address offset: 0x4C */
  __IO uint32_t EEFxR2;    /*!< EEFxR2   Address offset: 0x50 */
  __IO uint32_t RSTxR;     /*!< RSTxR    Address offset: 0x54 */
  __IO uint32_t CHPxR;     /*!< CHPxR    Address offset: 0x58 */
  __IO uint32_t CPT1xCR;   /*!< CPT1xCR  Address offset: 0x5C */
  __IO uint32_t CPT2xCR;   /*!< CPT2xCR  Address offset: 0x60 */
  __IO uint32_t OUTxR;     /*!< OUTxR    Address offset: 0x64 */
  __IO uint32_t FLTxR;     /*!< FLTxR    Address offset: 0x68 */
  __IO uint32_t TIMxCR2;   /*!< TIMxCR2  Address offset: 0x6C */
  __IO uint32_t EEFxR3;    /*!< EEFxR3   Address offset: 0x70 */
  __IO uint32_t PADDING_0[3]; /*!< Padding for alignment Address offset: 0x74-0x7C */
} HRTIM_Timerx_TypeDef;

/******************************************************************************/
/*                                                                            */
/*                       HRTIM_Common (HRTIM_Common)                          */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO uint32_t CR1;      /*!< CR1     Address offset: 0x00 */
  __IO uint32_t CR2;      /*!< CR2     Address offset: 0x04 */
  __I  uint32_t ISR;      /*!< ISR     Address offset: 0x08 */
  __O  uint32_t ICR;      /*!< ICR     Address offset: 0x0C */
  __IO uint32_t IER;      /*!< IER     Address offset: 0x10 */
  __IO uint32_t OENR;     /*!< OENR    Address offset: 0x14 */
  __O  uint32_t ODISR;    /*!< ODISR   Address offset: 0x18 */
  __I  uint32_t ODSR;     /*!< ODSR    Address offset: 0x1C */
  __IO uint32_t BMCR;     /*!< BMCR    Address offset: 0x20 */
  __IO uint32_t BMTRGR;   /*!< BMTRGR  Address offset: 0x24 */
  __IO uint32_t BMCMPR;   /*!< BMCMPR  Address offset: 0x28 */
  __IO uint32_t BMPER;    /*!< BMPER   Address offset: 0x2C */
  __IO uint32_t EECR1;    /*!< EECR1   Address offset: 0x30 */
  __IO uint32_t EECR2;    /*!< EECR2   Address offset: 0x34 */
  __IO uint32_t EECR3;    /*!< EECR3   Address offset: 0x38 */
  __IO uint32_t ADC1R;    /*!< ADC1R   Address offset: 0x3C */
  __IO uint32_t ADC2R;    /*!< ADC2R   Address offset: 0x40 */
  __IO uint32_t ADC3R;    /*!< ADC3R   Address offset: 0x44 */
  __IO uint32_t ADC4R;    /*!< ADC4R   Address offset: 0x48 */
  __IO uint32_t DLLCR;    /*!< DLLCR   Address offset: 0x4C */
  __IO uint32_t FLTINR1;  /*!< FLTINR1 Address offset: 0x50 */
  __IO uint32_t FLTINR2;  /*!< FLTINR2 Address offset: 0x54 */
  __IO uint32_t BDMUPR;   /*!< BDMUPR  Address offset: 0x58 */
  __IO uint32_t BDTAUPR;  /*!< BDTAUPR Address offset: 0x5C */
  __IO uint32_t BDTBUPR;  /*!< BDTBUPR Address offset: 0x60 */
  __IO uint32_t BDTCUPR;  /*!< BDTCUPR Address offset: 0x64 */
  __IO uint32_t BDTDUPR;  /*!< BDTDUPR Address offset: 0x68 */
  __IO uint32_t BDTEUPR;  /*!< BDTEUPR Address offset: 0x6C */
  __O  uint32_t BDMADR;   /*!< BDMADR  Address offset: 0x70 */
  __IO uint32_t BDTFUPR;  /*!< BDTFUPR Address offset: 0x74 */
  __IO uint32_t ADCER;    /*!< ADCER   Address offset: 0x78 */
  __IO uint32_t ADCUR;    /*!< ADCUR   Address offset: 0x7C */
  __IO uint32_t ADCPS1;   /*!< ADCPS1  Address offset: 0x80 */
  __IO uint32_t ADCPS2;   /*!< ADCPS2  Address offset: 0x84 */
  __IO uint32_t FLTINR3;  /*!< FLTINR3 Address offset: 0x88 */
  __IO uint32_t FLTINR4;  /*!< FLTINR4 Address offset: 0x8C */
} HRTIM_Common_TypeDef;



/**************  Bit definition for HRTIM_MCR register  ***************/
#define HRTIM_MCR_CK_PSC_Pos           (0U)
#define HRTIM_MCR_CK_PSC_Msk           (0x7UL << HRTIM_MCR_CK_PSC_Pos)    /*!< 0x00000007 */
#define HRTIM_MCR_CK_PSC                  HRTIM_MCR_CK_PSC_Msk          /*!< CK_PSC */
#define HRTIM_MCR_CK_PSC_0          (0x1UL << HRTIM_MCR_CK_PSC_Pos)    /*!< 0x00000001 */
#define HRTIM_MCR_CK_PSC_1          (0x2UL << HRTIM_MCR_CK_PSC_Pos)    /*!< 0x00000002 */
#define HRTIM_MCR_CK_PSC_2          (0x4UL << HRTIM_MCR_CK_PSC_Pos)    /*!< 0x00000004 */
#define HRTIM_MCR_CONT_Pos            (3U)
#define HRTIM_MCR_CONT_Msk            (0x1UL << HRTIM_MCR_CONT_Pos) /*!< 0x00000008 */
#define HRTIM_MCR_CONT                    HRTIM_MCR_CONT_Msk            /*!< CONT */
#define HRTIM_MCR_RETRIG_Pos          (4U)
#define HRTIM_MCR_RETRIG_Msk          (0x1UL << HRTIM_MCR_RETRIG_Pos)   /*!< 0x00000010 */
#define HRTIM_MCR_RETRIG                  HRTIM_MCR_RETRIG_Msk          /*!< RETRIG */
#define HRTIM_MCR_HALF_Pos            (5U)
#define HRTIM_MCR_HALF_Msk            (0x1UL << HRTIM_MCR_HALF_Pos) /*!< 0x00000020 */
#define HRTIM_MCR_HALF                    HRTIM_MCR_HALF_Msk            /*!< HALF */
#define HRTIM_MCR_INTLVD_Pos          (6U)
#define HRTIM_MCR_INTLVD_Msk          (0x3UL << HRTIM_MCR_INTLVD_Pos)   /*!< 0x000000C0 */
#define HRTIM_MCR_INTLVD                  HRTIM_MCR_INTLVD_Msk          /*!< INTLVD */
#define HRTIM_MCR_INTLVD_0          (0x1UL << HRTIM_MCR_INTLVD_Pos)    /*!< 0x00000040 */
#define HRTIM_MCR_INTLVD_1          (0x2UL << HRTIM_MCR_INTLVD_Pos)    /*!< 0x00000080 */
#define HRTIM_MCR_SYNC_IN_Pos         (8U)
#define HRTIM_MCR_SYNC_IN_Msk         (0x3UL << HRTIM_MCR_SYNC_IN_Pos)    /*!< 0x00000300 */
#define HRTIM_MCR_SYNC_IN                 HRTIM_MCR_SYNC_IN_Msk         /*!< SYNC_IN */
#define HRTIM_MCR_SYNC_IN_0         (0x1UL << HRTIM_MCR_SYNC_IN_Pos)     /*!< 0x00000100 */
#define HRTIM_MCR_SYNC_IN_1         (0x2UL << HRTIM_MCR_SYNC_IN_Pos)     /*!< 0x00000200 */
#define HRTIM_MCR_SYNCRSTM_Pos        (10U)
#define HRTIM_MCR_SYNCRSTM_Msk        (0x1UL << HRTIM_MCR_SYNCRSTM_Pos)     /*!< 0x00000400 */
#define HRTIM_MCR_SYNCRSTM                HRTIM_MCR_SYNCRSTM_Msk        /*!< SYNCRSTM */
#define HRTIM_MCR_SYNCSTRTM_Pos       (11U)
#define HRTIM_MCR_SYNCSTRTM_Msk       (0x1UL << HRTIM_MCR_SYNCSTRTM_Pos)      /*!< 0x00000800 */
#define HRTIM_MCR_SYNCSTRTM               HRTIM_MCR_SYNCSTRTM_Msk       /*!< SYNCSTRTM */
#define HRTIM_MCR_SYNC_OUT_Pos         (12U)
#define HRTIM_MCR_SYNC_OUT_Msk         (0x3UL << HRTIM_MCR_SYNC_OUT_Pos)      /*!< 0x00003000 */
#define HRTIM_MCR_SYNC_OUT                HRTIM_MCR_SYNC_OUT_Msk        /*!< SYNC_OUT */
#define HRTIM_MCR_SYNC_OUT_0        (0x1UL << HRTIM_MCR_SYNC_OUT_Pos)      /*!< 0x00001000 */
#define HRTIM_MCR_SYNC_OUT_1        (0x2UL << HRTIM_MCR_SYNC_OUT_Pos)      /*!< 0x00002000 */
#define HRTIM_MCR_SYNC_SRC_Pos         (14U)
#define HRTIM_MCR_SYNC_SRC_Msk         (0x3UL << HRTIM_MCR_SYNC_SRC_Pos)      /*!< 0x0000C000 */
#define HRTIM_MCR_SYNC_SRC                HRTIM_MCR_SYNC_SRC_Msk        /*!< SYNC_SRC */
#define HRTIM_MCR_SYNC_SRC_0        (0x1UL << HRTIM_MCR_SYNC_SRC_Pos)      /*!< 0x00004000 */
#define HRTIM_MCR_SYNC_SRC_1        (0x2UL << HRTIM_MCR_SYNC_SRC_Pos)      /*!< 0x00008000 */
#define HRTIM_MCR_MCEN_Pos            (16U)
#define HRTIM_MCR_MCEN_Msk            (0x1UL << HRTIM_MCR_MCEN_Pos) /*!< 0x00010000 */
#define HRTIM_MCR_MCEN                    HRTIM_MCR_MCEN_Msk            /*!< MCEN */
#define HRTIM_MCR_TACEN_Pos           (17U)
#define HRTIM_MCR_TACEN_Msk           (0x1UL << HRTIM_MCR_TACEN_Pos)  /*!< 0x00020000 */
#define HRTIM_MCR_TACEN                   HRTIM_MCR_TACEN_Msk           /*!< TACEN */
#define HRTIM_MCR_TBCEN_Pos           (18U)
#define HRTIM_MCR_TBCEN_Msk           (0x1UL << HRTIM_MCR_TBCEN_Pos)  /*!< 0x00040000 */
#define HRTIM_MCR_TBCEN                   HRTIM_MCR_TBCEN_Msk           /*!< TBCEN */
#define HRTIM_MCR_TCCEN_Pos           (19U)
#define HRTIM_MCR_TCCEN_Msk           (0x1UL << HRTIM_MCR_TCCEN_Pos)  /*!< 0x00080000 */
#define HRTIM_MCR_TCCEN                   HRTIM_MCR_TCCEN_Msk           /*!< TCCEN */
#define HRTIM_MCR_TDCEN_Pos           (20U)
#define HRTIM_MCR_TDCEN_Msk           (0x1UL << HRTIM_MCR_TDCEN_Pos)  /*!< 0x00100000 */
#define HRTIM_MCR_TDCEN                   HRTIM_MCR_TDCEN_Msk           /*!< TDCEN */
#define HRTIM_MCR_TECEN_Pos           (21U)
#define HRTIM_MCR_TECEN_Msk           (0x1UL << HRTIM_MCR_TECEN_Pos)  /*!< 0x00200000 */
#define HRTIM_MCR_TECEN                   HRTIM_MCR_TECEN_Msk           /*!< TECEN */
#define HRTIM_MCR_TFCEN_Pos           (22U)
#define HRTIM_MCR_TFCEN_Msk           (0x1UL << HRTIM_MCR_TFCEN_Pos)  /*!< 0x00400000 */
#define HRTIM_MCR_TFCEN                   HRTIM_MCR_TFCEN_Msk           /*!< TFCEN */
#define HRTIM_MCR_DACSYNC_Pos         (25U)
#define HRTIM_MCR_DACSYNC_Msk         (0x3UL << HRTIM_MCR_DACSYNC_Pos)    /*!< 0x06000000 */
#define HRTIM_MCR_DACSYNC                 HRTIM_MCR_DACSYNC_Msk         /*!< DACSYNC */
#define HRTIM_MCR_DACSYNC_0         (0x1UL << HRTIM_MCR_DACSYNC_Pos)     /*!< 0x02000000 */
#define HRTIM_MCR_DACSYNC_1         (0x2UL << HRTIM_MCR_DACSYNC_Pos)     /*!< 0x04000000 */
#define HRTIM_MCR_PREEN_Pos           (27U)
#define HRTIM_MCR_PREEN_Msk           (0x1UL << HRTIM_MCR_PREEN_Pos)  /*!< 0x08000000 */
#define HRTIM_MCR_PREEN                   HRTIM_MCR_PREEN_Msk           /*!< PREEN */
#define HRTIM_MCR_MREPU_Pos           (29U)
#define HRTIM_MCR_MREPU_Msk           (0x1UL << HRTIM_MCR_MREPU_Pos)  /*!< 0x20000000 */
#define HRTIM_MCR_MREPU                   HRTIM_MCR_MREPU_Msk           /*!< MREPU */
#define HRTIM_MCR_BRSTDMA_Pos         (30U)
#define HRTIM_MCR_BRSTDMA_Msk         (0x3UL << HRTIM_MCR_BRSTDMA_Pos)    /*!< 0xC0000000 */
#define HRTIM_MCR_BRSTDMA                 HRTIM_MCR_BRSTDMA_Msk         /*!< BRSTDMA */
#define HRTIM_MCR_BRSTDMA_0         (0x1UL << HRTIM_MCR_BRSTDMA_Pos)     /*!< 0x40000000 */
#define HRTIM_MCR_BRSTDMA_1         (0x2UL << HRTIM_MCR_BRSTDMA_Pos)     /*!< 0x80000000 */

/**************  Bit definition for HRTIM_MISR register  **************/
#define HRTIM_MISR_MCMP1_Pos          (0U)
#define HRTIM_MISR_MCMP1_Msk          (0x1UL << HRTIM_MISR_MCMP1_Pos)   /*!< 0x00000001 */
#define HRTIM_MISR_MCMP1                  HRTIM_MISR_MCMP1_Msk          /*!< MCMP1 */
#define HRTIM_MISR_MCMP2_Pos          (1U)
#define HRTIM_MISR_MCMP2_Msk          (0x1UL << HRTIM_MISR_MCMP2_Pos)   /*!< 0x00000002 */
#define HRTIM_MISR_MCMP2                  HRTIM_MISR_MCMP2_Msk          /*!< MCMP2 */
#define HRTIM_MISR_MCMP3_Pos          (2U)
#define HRTIM_MISR_MCMP3_Msk          (0x1UL << HRTIM_MISR_MCMP3_Pos)   /*!< 0x00000004 */
#define HRTIM_MISR_MCMP3                  HRTIM_MISR_MCMP3_Msk          /*!< MCMP3 */
#define HRTIM_MISR_MCMP4_Pos          (3U)
#define HRTIM_MISR_MCMP4_Msk          (0x1UL << HRTIM_MISR_MCMP4_Pos)   /*!< 0x00000008 */
#define HRTIM_MISR_MCMP4                  HRTIM_MISR_MCMP4_Msk          /*!< MCMP4 */
#define HRTIM_MISR_MREP_Pos           (4U)
#define HRTIM_MISR_MREP_Msk           (0x1UL << HRTIM_MISR_MREP_Pos)  /*!< 0x00000010 */
#define HRTIM_MISR_MREP                   HRTIM_MISR_MREP_Msk           /*!< MREP */
#define HRTIM_MISR_SYNC_Pos           (5U)
#define HRTIM_MISR_SYNC_Msk           (0x1UL << HRTIM_MISR_SYNC_Pos)  /*!< 0x00000020 */
#define HRTIM_MISR_SYNC                   HRTIM_MISR_SYNC_Msk           /*!< SYNC */
#define HRTIM_MISR_MUPD_Pos           (6U)
#define HRTIM_MISR_MUPD_Msk           (0x1UL << HRTIM_MISR_MUPD_Pos)  /*!< 0x00000040 */
#define HRTIM_MISR_MUPD                   HRTIM_MISR_MUPD_Msk           /*!< MUPD */

/**************  Bit definition for HRTIM_MICR register  **************/
#define HRTIM_MICR_MCMP1C_Pos         (0U)
#define HRTIM_MICR_MCMP1C_Msk         (0x1UL << HRTIM_MICR_MCMP1C_Pos)    /*!< 0x00000001 */
#define HRTIM_MICR_MCMP1C                 HRTIM_MICR_MCMP1C_Msk         /*!< MCMP1C */
#define HRTIM_MICR_MCMP2C_Pos         (1U)
#define HRTIM_MICR_MCMP2C_Msk         (0x1UL << HRTIM_MICR_MCMP2C_Pos)    /*!< 0x00000002 */
#define HRTIM_MICR_MCMP2C                 HRTIM_MICR_MCMP2C_Msk         /*!< MCMP2C */
#define HRTIM_MICR_MCMP3C_Pos         (2U)
#define HRTIM_MICR_MCMP3C_Msk         (0x1UL << HRTIM_MICR_MCMP3C_Pos)    /*!< 0x00000004 */
#define HRTIM_MICR_MCMP3C                 HRTIM_MICR_MCMP3C_Msk         /*!< MCMP3C */
#define HRTIM_MICR_MCMP4C_Pos         (3U)
#define HRTIM_MICR_MCMP4C_Msk         (0x1UL << HRTIM_MICR_MCMP4C_Pos)    /*!< 0x00000008 */
#define HRTIM_MICR_MCMP4C                 HRTIM_MICR_MCMP4C_Msk         /*!< MCMP4C */
#define HRTIM_MICR_MREPC_Pos          (4U)
#define HRTIM_MICR_MREPC_Msk          (0x1UL << HRTIM_MICR_MREPC_Pos)   /*!< 0x00000010 */
#define HRTIM_MICR_MREPC                  HRTIM_MICR_MREPC_Msk          /*!< MREPC */
#define HRTIM_MICR_SYNCC_Pos          (5U)
#define HRTIM_MICR_SYNCC_Msk          (0x1UL << HRTIM_MICR_SYNCC_Pos)   /*!< 0x00000020 */
#define HRTIM_MICR_SYNCC                  HRTIM_MICR_SYNCC_Msk          /*!< SYNCC */
#define HRTIM_MICR_MUPDC_Pos          (6U)
#define HRTIM_MICR_MUPDC_Msk          (0x1UL << HRTIM_MICR_MUPDC_Pos)   /*!< 0x00000040 */
#define HRTIM_MICR_MUPDC                  HRTIM_MICR_MUPDC_Msk          /*!< MUPDC */

/*************  Bit definition for HRTIM_MDIER register  **************/
#define HRTIM_MDIER_MCMP1IE_Pos       (0U)
#define HRTIM_MDIER_MCMP1IE_Msk       (0x1UL << HRTIM_MDIER_MCMP1IE_Pos)      /*!< 0x00000001 */
#define HRTIM_MDIER_MCMP1IE               HRTIM_MDIER_MCMP1IE_Msk       /*!< MCMP1IE */
#define HRTIM_MDIER_MCMP2IE_Pos       (1U)
#define HRTIM_MDIER_MCMP2IE_Msk       (0x1UL << HRTIM_MDIER_MCMP2IE_Pos)      /*!< 0x00000002 */
#define HRTIM_MDIER_MCMP2IE               HRTIM_MDIER_MCMP2IE_Msk       /*!< MCMP2IE */
#define HRTIM_MDIER_MCMP3IE_Pos       (2U)
#define HRTIM_MDIER_MCMP3IE_Msk       (0x1UL << HRTIM_MDIER_MCMP3IE_Pos)      /*!< 0x00000004 */
#define HRTIM_MDIER_MCMP3IE               HRTIM_MDIER_MCMP3IE_Msk       /*!< MCMP3IE */
#define HRTIM_MDIER_MCMP4IE_Pos       (3U)
#define HRTIM_MDIER_MCMP4IE_Msk       (0x1UL << HRTIM_MDIER_MCMP4IE_Pos)      /*!< 0x00000008 */
#define HRTIM_MDIER_MCMP4IE               HRTIM_MDIER_MCMP4IE_Msk       /*!< MCMP4IE */
#define HRTIM_MDIER_MREPIE_Pos        (4U)
#define HRTIM_MDIER_MREPIE_Msk        (0x1UL << HRTIM_MDIER_MREPIE_Pos)     /*!< 0x00000010 */
#define HRTIM_MDIER_MREPIE                HRTIM_MDIER_MREPIE_Msk        /*!< MREPIE */
#define HRTIM_MDIER_SYNCIE_Pos        (5U)
#define HRTIM_MDIER_SYNCIE_Msk        (0x1UL << HRTIM_MDIER_SYNCIE_Pos)     /*!< 0x00000020 */
#define HRTIM_MDIER_SYNCIE                HRTIM_MDIER_SYNCIE_Msk        /*!< SYNCIE */
#define HRTIM_MDIER_MUPDIE_Pos        (6U)
#define HRTIM_MDIER_MUPDIE_Msk        (0x1UL << HRTIM_MDIER_MUPDIE_Pos)     /*!< 0x00000040 */
#define HRTIM_MDIER_MUPDIE                HRTIM_MDIER_MUPDIE_Msk        /*!< MUPDIE */
#define HRTIM_MDIER_MCMP1DE_Pos       (16U)
#define HRTIM_MDIER_MCMP1DE_Msk       (0x1UL << HRTIM_MDIER_MCMP1DE_Pos)      /*!< 0x00010000 */
#define HRTIM_MDIER_MCMP1DE               HRTIM_MDIER_MCMP1DE_Msk       /*!< MCMP1DE */
#define HRTIM_MDIER_MCMP2DE_Pos       (17U)
#define HRTIM_MDIER_MCMP2DE_Msk       (0x1UL << HRTIM_MDIER_MCMP2DE_Pos)      /*!< 0x00020000 */
#define HRTIM_MDIER_MCMP2DE               HRTIM_MDIER_MCMP2DE_Msk       /*!< MCMP2DE */
#define HRTIM_MDIER_MCMP3DE_Pos       (18U)
#define HRTIM_MDIER_MCMP3DE_Msk       (0x1UL << HRTIM_MDIER_MCMP3DE_Pos)      /*!< 0x00040000 */
#define HRTIM_MDIER_MCMP3DE               HRTIM_MDIER_MCMP3DE_Msk       /*!< MCMP3DE */
#define HRTIM_MDIER_MCMP4DE_Pos       (19U)
#define HRTIM_MDIER_MCMP4DE_Msk       (0x1UL << HRTIM_MDIER_MCMP4DE_Pos)      /*!< 0x00080000 */
#define HRTIM_MDIER_MCMP4DE               HRTIM_MDIER_MCMP4DE_Msk       /*!< MCMP4DE */
#define HRTIM_MDIER_MREPDE_Pos        (20U)
#define HRTIM_MDIER_MREPDE_Msk        (0x1UL << HRTIM_MDIER_MREPDE_Pos)     /*!< 0x00100000 */
#define HRTIM_MDIER_MREPDE                HRTIM_MDIER_MREPDE_Msk        /*!< MREPDE */
#define HRTIM_MDIER_SYNCDE_Pos        (21U)
#define HRTIM_MDIER_SYNCDE_Msk        (0x1UL << HRTIM_MDIER_SYNCDE_Pos)     /*!< 0x00200000 */
#define HRTIM_MDIER_SYNCDE                HRTIM_MDIER_SYNCDE_Msk        /*!< SYNCDE */
#define HRTIM_MDIER_MUPDDE_Pos        (22U)
#define HRTIM_MDIER_MUPDDE_Msk        (0x1UL << HRTIM_MDIER_MUPDDE_Pos)     /*!< 0x00400000 */
#define HRTIM_MDIER_MUPDDE                HRTIM_MDIER_MUPDDE_Msk        /*!< MUPDDE */

/*************  Bit definition for HRTIM_MCNTR register  **************/
#define HRTIM_MCNTR_MCNT_Pos          (0U)
#define HRTIM_MCNTR_MCNT_Msk          (0xFFFFUL << HRTIM_MCNTR_MCNT_Pos)      /*!< 0x0000FFFF */
#define HRTIM_MCNTR_MCNT                  HRTIM_MCNTR_MCNT_Msk          /*!< MCNT */

/**************  Bit definition for HRTIM_MPER register  **************/
#define HRTIM_MPER_MPER_Pos           (0U)
#define HRTIM_MPER_MPER_Msk           (0xFFFFUL << HRTIM_MPER_MPER_Pos)     /*!< 0x0000FFFF */
#define HRTIM_MPER_MPER                   HRTIM_MPER_MPER_Msk           /*!< MPER */

/**************  Bit definition for HRTIM_MREP register  **************/
#define HRTIM_MREP_MREP_Pos           (0U)
#define HRTIM_MREP_MREP_Msk           (0xFFUL << HRTIM_MREP_MREP_Pos)   /*!< 0x000000FF */
#define HRTIM_MREP_MREP                   HRTIM_MREP_MREP_Msk           /*!< MREP */

/*************  Bit definition for HRTIM_MCMP1R register  *************/
#define HRTIM_MCMP1R_MCMP1_Pos        (0U)
#define HRTIM_MCMP1R_MCMP1_Msk        (0xFFFFUL << HRTIM_MCMP1R_MCMP1_Pos)        /*!< 0x0000FFFF */
#define HRTIM_MCMP1R_MCMP1                HRTIM_MCMP1R_MCMP1_Msk        /*!< MCMP1 */

/*************  Bit definition for HRTIM_MCMP2R register  *************/
#define HRTIM_MCMP2R_MCMP2_Pos        (0U)
#define HRTIM_MCMP2R_MCMP2_Msk        (0xFFFFUL << HRTIM_MCMP2R_MCMP2_Pos)        /*!< 0x0000FFFF */
#define HRTIM_MCMP2R_MCMP2                HRTIM_MCMP2R_MCMP2_Msk        /*!< MCMP2 */

/*************  Bit definition for HRTIM_MCMP3R register  *************/
#define HRTIM_MCMP3R_MCMP3_Pos        (0U)
#define HRTIM_MCMP3R_MCMP3_Msk        (0xFFFFUL << HRTIM_MCMP3R_MCMP3_Pos)        /*!< 0x0000FFFF */
#define HRTIM_MCMP3R_MCMP3                HRTIM_MCMP3R_MCMP3_Msk        /*!< MCMP3 */

/*************  Bit definition for HRTIM_MCMP4R register  *************/
#define HRTIM_MCMP4R_MCMP4_Pos        (0U)
#define HRTIM_MCMP4R_MCMP4_Msk        (0xFFFFUL << HRTIM_MCMP4R_MCMP4_Pos)        /*!< 0x0000FFFF */
#define HRTIM_MCMP4R_MCMP4                HRTIM_MCMP4R_MCMP4_Msk        /*!< MCMP4 */


/*************  Bit definition for HRTIM_TIMxCR register  *************/
#define HRTIM_TIMxCR_CK_PSC_Pos          (0U)
#define HRTIM_TIMxCR_CK_PSC_Msk          (0x7UL << HRTIM_TIMxCR_CK_PSC_Pos)     /*!< 0x00000007 */
#define HRTIM_TIMxCR_CK_PSC               HRTIM_TIMxCR_CK_PSC_Msk               /*!< CK_PSC */
#define HRTIM_TIMxCR_CK_PSC_0         (0x1UL << HRTIM_TIMxCR_CK_PSC_Pos)     /*!< 0x00000001 */
#define HRTIM_TIMxCR_CK_PSC_1         (0x2UL << HRTIM_TIMxCR_CK_PSC_Pos)     /*!< 0x00000002 */
#define HRTIM_TIMxCR_CK_PSC_2         (0x4UL << HRTIM_TIMxCR_CK_PSC_Pos)     /*!< 0x00000004 */
#define HRTIM_TIMxCR_CONT_Pos           (3U)
#define HRTIM_TIMxCR_CONT_Msk           (0x1UL << HRTIM_TIMxCR_CONT_Pos)  /*!< 0x00000008 */
#define HRTIM_TIMxCR_CONT                 HRTIM_TIMxCR_CONT_Msk                 /*!< CONT */
#define HRTIM_TIMxCR_RETRIG_Pos         (4U)
#define HRTIM_TIMxCR_RETRIG_Msk         (0x1UL << HRTIM_TIMxCR_RETRIG_Pos)    /*!< 0x00000010 */
#define HRTIM_TIMxCR_RETRIG               HRTIM_TIMxCR_RETRIG_Msk               /*!< RETRIG */
#define HRTIM_TIMxCR_HALF_Pos           (5U)
#define HRTIM_TIMxCR_HALF_Msk           (0x1UL << HRTIM_TIMxCR_HALF_Pos)  /*!< 0x00000020 */
#define HRTIM_TIMxCR_HALF                 HRTIM_TIMxCR_HALF_Msk         /*!< HALF */
#define HRTIM_TIMxCR_PSHPLL_Pos         (6U)
#define HRTIM_TIMxCR_PSHPLL_Msk         (0x1UL << HRTIM_TIMxCR_PSHPLL_Pos)    /*!< 0x00000040 */
#define HRTIM_TIMxCR_PSHPLL               HRTIM_TIMxCR_PSHPLL_Msk       /*!< PSHPLL */
#define HRTIM_TIMxCR_INTLVD_Pos         (7U)
#define HRTIM_TIMxCR_INTLVD_Msk         (0x3UL << HRTIM_TIMxCR_INTLVD_Pos)    /*!< 0x00000180 */
#define HRTIM_TIMxCR_INTLVD               HRTIM_TIMxCR_INTLVD_Msk       /*!< INTLVD */
#define HRTIM_TIMxCR_INTLVD_0         (0x1UL << HRTIM_TIMxCR_INTLVD_Pos)     /*!< 0x00000080 */
#define HRTIM_TIMxCR_INTLVD_1         (0x2UL << HRTIM_TIMxCR_INTLVD_Pos)     /*!< 0x00000100 */
#define HRTIM_TIMxCR_RSYNCU_Pos         (9U)
#define HRTIM_TIMxCR_RSYNCU_Msk         (0x1UL << HRTIM_TIMxCR_RSYNCU_Pos)    /*!< 0x00000200 */
#define HRTIM_TIMxCR_RSYNCU               HRTIM_TIMxCR_RSYNCU_Msk       /*!< RSYNCU */
#define HRTIM_TIMxCR_SYNCRSTx_Pos       (10U)
#define HRTIM_TIMxCR_SYNCRSTx_Msk       (0x1UL << HRTIM_TIMxCR_SYNCRSTx_Pos)      /*!< 0x00000400 */
#define HRTIM_TIMxCR_SYNCRSTx             HRTIM_TIMxCR_SYNCRSTx_Msk     /*!< SYNCRSTx */
#define HRTIM_TIMxCR_SYNCSTRTx_Pos      (11U)
#define HRTIM_TIMxCR_SYNCSTRTx_Msk      (0x1UL << HRTIM_TIMxCR_SYNCSTRTx_Pos)       /*!< 0x00000800 */
#define HRTIM_TIMxCR_SYNCSTRTx            HRTIM_TIMxCR_SYNCSTRTx_Msk    /*!< SYNCSTRTx */
#define HRTIM_TIMxCR_DELCMP2_Pos        (12U)
#define HRTIM_TIMxCR_DELCMP2_Msk        (0x3UL << HRTIM_TIMxCR_DELCMP2_Pos)     /*!< 0x00003000 */
#define HRTIM_TIMxCR_DELCMP2              HRTIM_TIMxCR_DELCMP2_Msk      /*!< DELCMP2 */
#define HRTIM_TIMxCR_DELCMP2_0        (0x1UL << HRTIM_TIMxCR_DELCMP2_Pos)      /*!< 0x00001000 */
#define HRTIM_TIMxCR_DELCMP2_1        (0x2UL << HRTIM_TIMxCR_DELCMP2_Pos)      /*!< 0x00002000 */
#define HRTIM_TIMxCR_DELCMP4_Pos           (14U)
#define HRTIM_TIMxCR_DELCMP4_Msk        (0x3UL << HRTIM_TIMxCR_DELCMP4_Pos)     /*!< 0x0000C000 */
#define HRTIM_TIMxCR_DELCMP4              HRTIM_TIMxCR_DELCMP4_Msk      /*!< DELCMP4 */
#define HRTIM_TIMxCR_DELCMP4_0        (0x1UL << HRTIM_TIMxCR_DELCMP4_Pos)      /*!< 0x00004000 */
#define HRTIM_TIMxCR_DELCMP4_1        (0x2UL << HRTIM_TIMxCR_DELCMP4_Pos)      /*!< 0x00008000 */
#define HRTIM_TIMxCR_TFU_Pos            (16U)
#define HRTIM_TIMxCR_TFU_Msk            (0x1UL << HRTIM_TIMxCR_TFU_Pos) /*!< 0x00010000 */
#define HRTIM_TIMxCR_TFU                  HRTIM_TIMxCR_TFU_Msk          /*!< TFU */
#define HRTIM_TIMxCR_TxREPU_Pos         (17U)
#define HRTIM_TIMxCR_TxREPU_Msk         (0x1UL << HRTIM_TIMxCR_TxREPU_Pos)    /*!< 0x00020000 */
#define HRTIM_TIMxCR_TxREPU               HRTIM_TIMxCR_TxREPU_Msk       /*!< TxREPU */
#define HRTIM_TIMxCR_TxRSTU_Pos         (18U)
#define HRTIM_TIMxCR_TxRSTU_Msk         (0x1UL << HRTIM_TIMxCR_TxRSTU_Pos)    /*!< 0x00040000 */
#define HRTIM_TIMxCR_TxRSTU               HRTIM_TIMxCR_TxRSTU_Msk       /*!< TxRSTU */
#define HRTIM_TIMxCR_TAU_Pos            (19U)
#define HRTIM_TIMxCR_TAU_Msk            (0x1UL << HRTIM_TIMxCR_TAU_Pos) /*!< 0x00080000 */
#define HRTIM_TIMxCR_TAU                  HRTIM_TIMxCR_TAU_Msk          /*!< TAU */
#define HRTIM_TIMxCR_TBU_Pos            (20U)
#define HRTIM_TIMxCR_TBU_Msk            (0x1UL << HRTIM_TIMxCR_TBU_Pos) /*!< 0x00100000 */
#define HRTIM_TIMxCR_TBU                  HRTIM_TIMxCR_TBU_Msk          /*!< TBU */
#define HRTIM_TIMxCR_TCU_Pos            (21U)
#define HRTIM_TIMxCR_TCU_Msk            (0x1UL << HRTIM_TIMxCR_TCU_Pos) /*!< 0x00200000 */
#define HRTIM_TIMxCR_TCU                  HRTIM_TIMxCR_TCU_Msk          /*!< TCU */
#define HRTIM_TIMxCR_TDU_Pos            (22U)
#define HRTIM_TIMxCR_TDU_Msk            (0x1UL << HRTIM_TIMxCR_TDU_Pos) /*!< 0x00400000 */
#define HRTIM_TIMxCR_TDU                  HRTIM_TIMxCR_TDU_Msk          /*!< TDU */
#define HRTIM_TIMxCR_TEU_Pos            (23U)
#define HRTIM_TIMxCR_TEU_Msk            (0x1UL << HRTIM_TIMxCR_TEU_Pos) /*!< 0x00800000 */
#define HRTIM_TIMxCR_TEU                  HRTIM_TIMxCR_TEU_Msk          /*!< TEU */
#define HRTIM_TIMxCR_MSTU_Pos           (24U)
#define HRTIM_TIMxCR_MSTU_Msk           (0x1UL << HRTIM_TIMxCR_MSTU_Pos)  /*!< 0x01000000 */
#define HRTIM_TIMxCR_MSTU                 HRTIM_TIMxCR_MSTU_Msk         /*!< MSTU */
#define HRTIM_TIMxCR_DACSYNC_Pos        (25U)
#define HRTIM_TIMxCR_DACSYNC_Msk        (0x3UL << HRTIM_TIMxCR_DACSYNC_Pos)     /*!< 0x06000000 */
#define HRTIM_TIMxCR_DACSYNC              HRTIM_TIMxCR_DACSYNC_Msk      /*!< DACSYNC */
#define HRTIM_TIMxCR_DACSYNC_0        (0x1UL << HRTIM_TIMxCR_DACSYNC_Pos)      /*!< 0x02000000 */
#define HRTIM_TIMxCR_DACSYNC_1        (0x2UL << HRTIM_TIMxCR_DACSYNC_Pos)      /*!< 0x04000000 */
#define HRTIM_TIMxCR_PREEN_Pos          (27U)
#define HRTIM_TIMxCR_PREEN_Msk          (0x1UL << HRTIM_TIMxCR_PREEN_Pos)   /*!< 0x08000000 */
#define HRTIM_TIMxCR_PREEN                HRTIM_TIMxCR_PREEN_Msk        /*!< PREEN */
#define HRTIM_TIMxCR_UPDGAT_Pos         (28U)
#define HRTIM_TIMxCR_UPDGAT_Msk         (0xFUL << HRTIM_TIMxCR_UPDGAT_Pos)    /*!< 0xF0000000 */
#define HRTIM_TIMxCR_UPDGAT               HRTIM_TIMxCR_UPDGAT_Msk       /*!< UPDGAT */
#define HRTIM_TIMxCR_UPDGAT_0         (0x1UL << HRTIM_TIMxCR_UPDGAT_Pos)     /*!< 0x10000000 */
#define HRTIM_TIMxCR_UPDGAT_1         (0x2UL << HRTIM_TIMxCR_UPDGAT_Pos)     /*!< 0x20000000 */
#define HRTIM_TIMxCR_UPDGAT_2         (0x4UL << HRTIM_TIMxCR_UPDGAT_Pos)     /*!< 0x40000000 */
#define HRTIM_TIMxCR_UPDGAT_3         (0x8UL << HRTIM_TIMxCR_UPDGAT_Pos)     /*!< 0x80000000 */

/************  Bit definition for HRTIM_TIMxISR register  *************/
#define HRTIM_TIMxISR_CMP1_Pos          (0U)
#define HRTIM_TIMxISR_CMP1_Msk          (0x1UL << HRTIM_TIMxISR_CMP1_Pos)   /*!< 0x00000001 */
#define HRTIM_TIMxISR_CMP1                HRTIM_TIMxISR_CMP1_Msk        /*!< CMP1 */
#define HRTIM_TIMxISR_CMP2_Pos          (1U)
#define HRTIM_TIMxISR_CMP2_Msk          (0x1UL << HRTIM_TIMxISR_CMP2_Pos)   /*!< 0x00000002 */
#define HRTIM_TIMxISR_CMP2                HRTIM_TIMxISR_CMP2_Msk        /*!< CMP2 */
#define HRTIM_TIMxISR_CMP3_Pos          (2U)
#define HRTIM_TIMxISR_CMP3_Msk          (0x1UL << HRTIM_TIMxISR_CMP3_Pos)   /*!< 0x00000004 */
#define HRTIM_TIMxISR_CMP3                HRTIM_TIMxISR_CMP3_Msk        /*!< CMP3 */
#define HRTIM_TIMxISR_CMP4_Pos          (3U)
#define HRTIM_TIMxISR_CMP4_Msk          (0x1UL << HRTIM_TIMxISR_CMP4_Pos)   /*!< 0x00000008 */
#define HRTIM_TIMxISR_CMP4                HRTIM_TIMxISR_CMP4_Msk        /*!< CMP4 */
#define HRTIM_TIMxISR_REP_Pos           (4U)
#define HRTIM_TIMxISR_REP_Msk           (0x1UL << HRTIM_TIMxISR_REP_Pos)  /*!< 0x00000010 */
#define HRTIM_TIMxISR_REP                 HRTIM_TIMxISR_REP_Msk         /*!< REP */
#define HRTIM_TIMxISR_UPD_Pos           (6U)
#define HRTIM_TIMxISR_UPD_Msk           (0x1UL << HRTIM_TIMxISR_UPD_Pos)  /*!< 0x00000040 */
#define HRTIM_TIMxISR_UPD                 HRTIM_TIMxISR_UPD_Msk         /*!< UPD */
#define HRTIM_TIMxISR_CPT1_Pos          (7U)
#define HRTIM_TIMxISR_CPT1_Msk          (0x1UL << HRTIM_TIMxISR_CPT1_Pos)   /*!< 0x00000080 */
#define HRTIM_TIMxISR_CPT1                HRTIM_TIMxISR_CPT1_Msk        /*!< CPT1 */
#define HRTIM_TIMxISR_CPT2_Pos          (8U)
#define HRTIM_TIMxISR_CPT2_Msk          (0x1UL << HRTIM_TIMxISR_CPT2_Pos)   /*!< 0x00000100 */
#define HRTIM_TIMxISR_CPT2                HRTIM_TIMxISR_CPT2_Msk        /*!< CPT2 */
#define HRTIM_TIMxISR_SET1_Pos          (9U)
#define HRTIM_TIMxISR_SET1_Msk          (0x1UL << HRTIM_TIMxISR_SET1_Pos)   /*!< 0x00000200 */
#define HRTIM_TIMxISR_SET1                HRTIM_TIMxISR_SET1_Msk        /*!< SET1 */
#define HRTIM_TIMxISR_RST1_Pos          (10U)
#define HRTIM_TIMxISR_RST1_Msk          (0x1UL << HRTIM_TIMxISR_RST1_Pos)   /*!< 0x00000400 */
#define HRTIM_TIMxISR_RST1                HRTIM_TIMxISR_RST1_Msk        /*!< RST1 */
#define HRTIM_TIMxISR_SET2_Pos          (11U)
#define HRTIM_TIMxISR_SET2_Msk          (0x1UL << HRTIM_TIMxISR_SET2_Pos)   /*!< 0x00000800 */
#define HRTIM_TIMxISR_SET2                HRTIM_TIMxISR_SET2_Msk        /*!< SET2 */
#define HRTIM_TIMxISR_RST2_Pos          (12U)
#define HRTIM_TIMxISR_RST2_Msk          (0x1UL << HRTIM_TIMxISR_RST2_Pos)   /*!< 0x00001000 */
#define HRTIM_TIMxISR_RST2                HRTIM_TIMxISR_RST2_Msk        /*!< RST2 */
#define HRTIM_TIMxISR_RST_Pos           (13U)
#define HRTIM_TIMxISR_RST_Msk           (0x1UL << HRTIM_TIMxISR_RST_Pos)  /*!< 0x00002000 */
#define HRTIM_TIMxISR_RST                 HRTIM_TIMxISR_RST_Msk         /*!< RST */
#define HRTIM_TIMxISR_DLYPRT_Pos        (14U)
#define HRTIM_TIMxISR_DLYPRT_Msk        (0x1UL << HRTIM_TIMxISR_DLYPRT_Pos)     /*!< 0x00004000 */
#define HRTIM_TIMxISR_DLYPRT              HRTIM_TIMxISR_DLYPRT_Msk      /*!< DLYPRT */
#define HRTIM_TIMxISR_CPPSTAT_Pos       (16U)
#define HRTIM_TIMxISR_CPPSTAT_Msk       (0x1UL << HRTIM_TIMxISR_CPPSTAT_Pos)      /*!< 0x00010000 */
#define HRTIM_TIMxISR_CPPSTAT             HRTIM_TIMxISR_CPPSTAT_Msk     /*!< CPPSTAT */
#define HRTIM_TIMxISR_IPPSTAT_Pos       (17U)
#define HRTIM_TIMxISR_IPPSTAT_Msk       (0x1UL << HRTIM_TIMxISR_IPPSTAT_Pos)      /*!< 0x00020000 */
#define HRTIM_TIMxISR_IPPSTAT             HRTIM_TIMxISR_IPPSTAT_Msk     /*!< IPPSTAT */
#define HRTIM_TIMxISR_O1STAT_Pos        (18U)
#define HRTIM_TIMxISR_O1STAT_Msk        (0x1UL << HRTIM_TIMxISR_O1STAT_Pos)     /*!< 0x00040000 */
#define HRTIM_TIMxISR_O1STAT              HRTIM_TIMxISR_O1STAT_Msk      /*!< O1STAT */
#define HRTIM_TIMxISR_O2STAT_Pos        (19U)
#define HRTIM_TIMxISR_O2STAT_Msk        (0x1UL << HRTIM_TIMxISR_O2STAT_Pos)     /*!< 0x00080000 */
#define HRTIM_TIMxISR_O2STAT              HRTIM_TIMxISR_O2STAT_Msk      /*!< O2STAT */
#define HRTIM_TIMxISR_O1CPY_Pos         (20U)
#define HRTIM_TIMxISR_O1CPY_Msk         (0x1UL << HRTIM_TIMxISR_O1CPY_Pos)    /*!< 0x00100000 */
#define HRTIM_TIMxISR_O1CPY               HRTIM_TIMxISR_O1CPY_Msk       /*!< O1CPY */
#define HRTIM_TIMxISR_O2CPY_Pos         (21U)
#define HRTIM_TIMxISR_O2CPY_Msk         (0x1UL << HRTIM_TIMxISR_O2CPY_Pos)    /*!< 0x00200000 */
#define HRTIM_TIMxISR_O2CPY               HRTIM_TIMxISR_O2CPY_Msk       /*!< O2CPY */

/************  Bit definition for HRTIM_TIMxICR register  *************/
#define HRTIM_TIMxICR_CMP1C_Pos         (0U)
#define HRTIM_TIMxICR_CMP1C_Msk         (0x1UL << HRTIM_TIMxICR_CMP1C_Pos)    /*!< 0x00000001 */
#define HRTIM_TIMxICR_CMP1C               HRTIM_TIMxICR_CMP1C_Msk       /*!< CMP1C */
#define HRTIM_TIMxICR_CMP2C_Pos         (1U)
#define HRTIM_TIMxICR_CMP2C_Msk         (0x1UL << HRTIM_TIMxICR_CMP2C_Pos)    /*!< 0x00000002 */
#define HRTIM_TIMxICR_CMP2C               HRTIM_TIMxICR_CMP2C_Msk       /*!< CMP2C */
#define HRTIM_TIMxICR_CMP3C_Pos         (2U)
#define HRTIM_TIMxICR_CMP3C_Msk         (0x1UL << HRTIM_TIMxICR_CMP3C_Pos)    /*!< 0x00000004 */
#define HRTIM_TIMxICR_CMP3C               HRTIM_TIMxICR_CMP3C_Msk       /*!< CMP3C */
#define HRTIM_TIMxICR_CMP4C_Pos         (3U)
#define HRTIM_TIMxICR_CMP4C_Msk         (0x1UL << HRTIM_TIMxICR_CMP4C_Pos)    /*!< 0x00000008 */
#define HRTIM_TIMxICR_CMP4C               HRTIM_TIMxICR_CMP4C_Msk       /*!< CMP4C */
#define HRTIM_TIMxICR_REPC_Pos          (4U)
#define HRTIM_TIMxICR_REPC_Msk          (0x1UL << HRTIM_TIMxICR_REPC_Pos)   /*!< 0x00000010 */
#define HRTIM_TIMxICR_REPC                HRTIM_TIMxICR_REPC_Msk        /*!< REPC */
#define HRTIM_TIMxICR_UPDC_Pos          (6U)
#define HRTIM_TIMxICR_UPDC_Msk          (0x1UL << HRTIM_TIMxICR_UPDC_Pos)   /*!< 0x00000040 */
#define HRTIM_TIMxICR_UPDC                HRTIM_TIMxICR_UPDC_Msk        /*!< UPDC */
#define HRTIM_TIMxICR_CPT1C_Pos         (7U)
#define HRTIM_TIMxICR_CPT1C_Msk         (0x1UL << HRTIM_TIMxICR_CPT1C_Pos)    /*!< 0x00000080 */
#define HRTIM_TIMxICR_CPT1C               HRTIM_TIMxICR_CPT1C_Msk       /*!< CPT1C */
#define HRTIM_TIMxICR_CPT2C_Pos         (8U)
#define HRTIM_TIMxICR_CPT2C_Msk         (0x1UL << HRTIM_TIMxICR_CPT2C_Pos)    /*!< 0x00000100 */
#define HRTIM_TIMxICR_CPT2C               HRTIM_TIMxICR_CPT2C_Msk       /*!< CPT2C */
#define HRTIM_TIMxICR_SET1C_Pos         (9U)
#define HRTIM_TIMxICR_SET1C_Msk         (0x1UL << HRTIM_TIMxICR_SET1C_Pos)    /*!< 0x00000200 */
#define HRTIM_TIMxICR_SET1C               HRTIM_TIMxICR_SET1C_Msk       /*!< SET1C */
#define HRTIM_TIMxICR_RST1C_Pos         (10U)
#define HRTIM_TIMxICR_RST1C_Msk         (0x1UL << HRTIM_TIMxICR_RST1C_Pos)    /*!< 0x00000400 */
#define HRTIM_TIMxICR_RST1C               HRTIM_TIMxICR_RST1C_Msk       /*!< RST1C */
#define HRTIM_TIMxICR_SET2C_Pos         (11U)
#define HRTIM_TIMxICR_SET2C_Msk         (0x1UL << HRTIM_TIMxICR_SET2C_Pos)    /*!< 0x00000800 */
#define HRTIM_TIMxICR_SET2C               HRTIM_TIMxICR_SET2C_Msk       /*!< SET2C */
#define HRTIM_TIMxICR_RST2C_Pos         (12U)
#define HRTIM_TIMxICR_RST2C_Msk         (0x1UL << HRTIM_TIMxICR_RST2C_Pos)    /*!< 0x00001000 */
#define HRTIM_TIMxICR_RST2C               HRTIM_TIMxICR_RST2C_Msk       /*!< RST2C */
#define HRTIM_TIMxICR_RSTC_Pos          (13U)
#define HRTIM_TIMxICR_RSTC_Msk          (0x1UL << HRTIM_TIMxICR_RSTC_Pos)   /*!< 0x00002000 */
#define HRTIM_TIMxICR_RSTC                HRTIM_TIMxICR_RSTC_Msk        /*!< RSTC */
#define HRTIM_TIMxICR_DLYPRTC_Pos       (14U)
#define HRTIM_TIMxICR_DLYPRTC_Msk       (0x1UL << HRTIM_TIMxICR_DLYPRTC_Pos)      /*!< 0x00004000 */
#define HRTIM_TIMxICR_DLYPRTC             HRTIM_TIMxICR_DLYPRTC_Msk     /*!< DLYPRTC */

/************  Bit definition for HRTIM_TIMxDIER register  ************/
#define HRTIM_TIMxDIER_CMP1IE_Pos       (0U)
#define HRTIM_TIMxDIER_CMP1IE_Msk       (0x1UL << HRTIM_TIMxDIER_CMP1IE_Pos)      /*!< 0x00000001 */
#define HRTIM_TIMxDIER_CMP1IE             HRTIM_TIMxDIER_CMP1IE_Msk     /*!< CMP1IE */
#define HRTIM_TIMxDIER_CMP2IE_Pos       (1U)
#define HRTIM_TIMxDIER_CMP2IE_Msk       (0x1UL << HRTIM_TIMxDIER_CMP2IE_Pos)      /*!< 0x00000002 */
#define HRTIM_TIMxDIER_CMP2IE             HRTIM_TIMxDIER_CMP2IE_Msk     /*!< CMP2IE */
#define HRTIM_TIMxDIER_CMP3IE_Pos       (2U)
#define HRTIM_TIMxDIER_CMP3IE_Msk       (0x1UL << HRTIM_TIMxDIER_CMP3IE_Pos)      /*!< 0x00000004 */
#define HRTIM_TIMxDIER_CMP3IE             HRTIM_TIMxDIER_CMP3IE_Msk     /*!< CMP3IE */
#define HRTIM_TIMxDIER_CMP4IE_Pos       (3U)
#define HRTIM_TIMxDIER_CMP4IE_Msk       (0x1UL << HRTIM_TIMxDIER_CMP4IE_Pos)      /*!< 0x00000008 */
#define HRTIM_TIMxDIER_CMP4IE             HRTIM_TIMxDIER_CMP4IE_Msk     /*!< CMP4IE */
#define HRTIM_TIMxDIER_REPIE_Pos        (4U)
#define HRTIM_TIMxDIER_REPIE_Msk        (0x1UL << HRTIM_TIMxDIER_REPIE_Pos)     /*!< 0x00000010 */
#define HRTIM_TIMxDIER_REPIE              HRTIM_TIMxDIER_REPIE_Msk      /*!< REPIE */
#define HRTIM_TIMxDIER_UPDIE_Pos        (6U)
#define HRTIM_TIMxDIER_UPDIE_Msk        (0x1UL << HRTIM_TIMxDIER_UPDIE_Pos)     /*!< 0x00000040 */
#define HRTIM_TIMxDIER_UPDIE              HRTIM_TIMxDIER_UPDIE_Msk      /*!< UPDIE */
#define HRTIM_TIMxDIER_CPT1IE_Pos       (7U)
#define HRTIM_TIMxDIER_CPT1IE_Msk       (0x1UL << HRTIM_TIMxDIER_CPT1IE_Pos)      /*!< 0x00000080 */
#define HRTIM_TIMxDIER_CPT1IE             HRTIM_TIMxDIER_CPT1IE_Msk     /*!< CPT1IE */
#define HRTIM_TIMxDIER_CPT2IE_Pos       (8U)
#define HRTIM_TIMxDIER_CPT2IE_Msk       (0x1UL << HRTIM_TIMxDIER_CPT2IE_Pos)      /*!< 0x00000100 */
#define HRTIM_TIMxDIER_CPT2IE             HRTIM_TIMxDIER_CPT2IE_Msk     /*!< CPT2IE */
#define HRTIM_TIMxDIER_SET1IE_Pos       (9U)
#define HRTIM_TIMxDIER_SET1IE_Msk       (0x1UL << HRTIM_TIMxDIER_SET1IE_Pos)      /*!< 0x00000200 */
#define HRTIM_TIMxDIER_SET1IE             HRTIM_TIMxDIER_SET1IE_Msk     /*!< SET1IE */
#define HRTIM_TIMxDIER_RST1IE_Pos       (10U)
#define HRTIM_TIMxDIER_RST1IE_Msk       (0x1UL << HRTIM_TIMxDIER_RST1IE_Pos)      /*!< 0x00000400 */
#define HRTIM_TIMxDIER_RST1IE             HRTIM_TIMxDIER_RST1IE_Msk     /*!< RST1IE */
#define HRTIM_TIMxDIER_SET2IE_Pos       (11U)
#define HRTIM_TIMxDIER_SET2IE_Msk       (0x1UL << HRTIM_TIMxDIER_SET2IE_Pos)      /*!< 0x00000800 */
#define HRTIM_TIMxDIER_SET2IE             HRTIM_TIMxDIER_SET2IE_Msk     /*!< SET2IE */
#define HRTIM_TIMxDIER_RST2IE_Pos       (12U)
#define HRTIM_TIMxDIER_RST2IE_Msk       (0x1UL << HRTIM_TIMxDIER_RST2IE_Pos)      /*!< 0x00001000 */
#define HRTIM_TIMxDIER_RST2IE             HRTIM_TIMxDIER_RST2IE_Msk     /*!< RST2IE */
#define HRTIM_TIMxDIER_RSTIE_Pos        (13U)
#define HRTIM_TIMxDIER_RSTIE_Msk        (0x1UL << HRTIM_TIMxDIER_RSTIE_Pos)     /*!< 0x00002000 */
#define HRTIM_TIMxDIER_RSTIE              HRTIM_TIMxDIER_RSTIE_Msk      /*!< RSTIE */
#define HRTIM_TIMxDIER_DLYPRTIE_Pos     (14U)
#define HRTIM_TIMxDIER_DLYPRTIE_Msk     (0x1UL << HRTIM_TIMxDIER_DLYPRTIE_Pos)        /*!< 0x00004000 */
#define HRTIM_TIMxDIER_DLYPRTIE           HRTIM_TIMxDIER_DLYPRTIE_Msk   /*!< DLYPRTIE */
#define HRTIM_TIMxDIER_CMP1DE_Pos       (16U)
#define HRTIM_TIMxDIER_CMP1DE_Msk       (0x1UL << HRTIM_TIMxDIER_CMP1DE_Pos)      /*!< 0x00010000 */
#define HRTIM_TIMxDIER_CMP1DE             HRTIM_TIMxDIER_CMP1DE_Msk     /*!< CMP1DE */
#define HRTIM_TIMxDIER_CMP2DE_Pos       (17U)
#define HRTIM_TIMxDIER_CMP2DE_Msk       (0x1UL << HRTIM_TIMxDIER_CMP2DE_Pos)      /*!< 0x00020000 */
#define HRTIM_TIMxDIER_CMP2DE             HRTIM_TIMxDIER_CMP2DE_Msk     /*!< CMP2DE */
#define HRTIM_TIMxDIER_CMP3DE_Pos       (18U)
#define HRTIM_TIMxDIER_CMP3DE_Msk       (0x1UL << HRTIM_TIMxDIER_CMP3DE_Pos)      /*!< 0x00040000 */
#define HRTIM_TIMxDIER_CMP3DE             HRTIM_TIMxDIER_CMP3DE_Msk     /*!< CMP3DE */
#define HRTIM_TIMxDIER_CMP4DE_Pos       (19U)
#define HRTIM_TIMxDIER_CMP4DE_Msk       (0x1UL << HRTIM_TIMxDIER_CMP4DE_Pos)      /*!< 0x00080000 */
#define HRTIM_TIMxDIER_CMP4DE             HRTIM_TIMxDIER_CMP4DE_Msk     /*!< CMP4DE */
#define HRTIM_TIMxDIER_REPDE_Pos        (20U)
#define HRTIM_TIMxDIER_REPDE_Msk        (0x1UL << HRTIM_TIMxDIER_REPDE_Pos)     /*!< 0x00100000 */
#define HRTIM_TIMxDIER_REPDE              HRTIM_TIMxDIER_REPDE_Msk      /*!< REPDE */
#define HRTIM_TIMxDIER_UPDDE_Pos        (22U)
#define HRTIM_TIMxDIER_UPDDE_Msk        (0x1UL << HRTIM_TIMxDIER_UPDDE_Pos)     /*!< 0x00400000 */
#define HRTIM_TIMxDIER_UPDDE              HRTIM_TIMxDIER_UPDDE_Msk      /*!< UPDDE */
#define HRTIM_TIMxDIER_CPT1DE_Pos       (23U)
#define HRTIM_TIMxDIER_CPT1DE_Msk       (0x1UL << HRTIM_TIMxDIER_CPT1DE_Pos)      /*!< 0x00800000 */
#define HRTIM_TIMxDIER_CPT1DE             HRTIM_TIMxDIER_CPT1DE_Msk     /*!< CPT1DE */
#define HRTIM_TIMxDIER_CPT2DE_Pos       (24U)
#define HRTIM_TIMxDIER_CPT2DE_Msk       (0x1UL << HRTIM_TIMxDIER_CPT2DE_Pos)      /*!< 0x01000000 */
#define HRTIM_TIMxDIER_CPT2DE             HRTIM_TIMxDIER_CPT2DE_Msk     /*!< CPT2DE */
#define HRTIM_TIMxDIER_SET1DE_Pos       (25U)
#define HRTIM_TIMxDIER_SET1DE_Msk       (0x1UL << HRTIM_TIMxDIER_SET1DE_Pos)      /*!< 0x02000000 */
#define HRTIM_TIMxDIER_SET1DE             HRTIM_TIMxDIER_SET1DE_Msk     /*!< SET1DE */
#define HRTIM_TIMxDIER_RST1DE_Pos       (26U)
#define HRTIM_TIMxDIER_RST1DE_Msk       (0x1UL << HRTIM_TIMxDIER_RST1DE_Pos)      /*!< 0x04000000 */
#define HRTIM_TIMxDIER_RST1DE             HRTIM_TIMxDIER_RST1DE_Msk     /*!< RST1DE */
#define HRTIM_TIMxDIER_SET2DE_Pos       (27U)
#define HRTIM_TIMxDIER_SET2DE_Msk       (0x1UL << HRTIM_TIMxDIER_SET2DE_Pos)      /*!< 0x08000000 */
#define HRTIM_TIMxDIER_SET2DE             HRTIM_TIMxDIER_SET2DE_Msk     /*!< SET2DE */
#define HRTIM_TIMxDIER_RST2DE_Pos       (28U)
#define HRTIM_TIMxDIER_RST2DE_Msk       (0x1UL << HRTIM_TIMxDIER_RST2DE_Pos)      /*!< 0x10000000 */
#define HRTIM_TIMxDIER_RST2DE             HRTIM_TIMxDIER_RST2DE_Msk     /*!< RST2DE */
#define HRTIM_TIMxDIER_RSTDE_Pos        (29U)
#define HRTIM_TIMxDIER_RSTDE_Msk        (0x1UL << HRTIM_TIMxDIER_RSTDE_Pos)     /*!< 0x20000000 */
#define HRTIM_TIMxDIER_RSTDE              HRTIM_TIMxDIER_RSTDE_Msk      /*!< RSTDE */
#define HRTIM_TIMxDIER_DLYPRTDE_Pos     (30U)
#define HRTIM_TIMxDIER_DLYPRTDE_Msk     (0x1UL << HRTIM_TIMxDIER_DLYPRTDE_Pos)        /*!< 0x40000000 */
#define HRTIM_TIMxDIER_DLYPRTDE           HRTIM_TIMxDIER_DLYPRTDE_Msk   /*!< DLYPRTDE */

/*************  Bit definition for HRTIM_CNTxR register  **************/
#define HRTIM_CNTxR_CNTx_Pos            (0U)
#define HRTIM_CNTxR_CNTx_Msk            (0xFFFFUL << HRTIM_CNTxR_CNTx_Pos)    /*!< 0x0000FFFF */
#define HRTIM_CNTxR_CNTx                  HRTIM_CNTxR_CNTx_Msk          /*!< CNTx */

/*************  Bit definition for HRTIM_PERxR register  **************/
#define HRTIM_PERxR_PERx_Pos            (0U)
#define HRTIM_PERxR_PERx_Msk            (0xFFFFUL << HRTIM_PERxR_PERx_Pos)    /*!< 0x0000FFFF */
#define HRTIM_PERxR_PERx                  HRTIM_PERxR_PERx_Msk          /*!< PERx */

/*************  Bit definition for HRTIM_REPxR register  **************/
#define HRTIM_REPxR_REPx_Pos            (0U)
#define HRTIM_REPxR_REPx_Msk            (0xFFUL << HRTIM_REPxR_REPx_Pos)  /*!< 0x000000FF */
#define HRTIM_REPxR_REPx                  HRTIM_REPxR_REPx_Msk          /*!< REPx */

/*************  Bit definition for HRTIM_CMP1xR register  *************/
#define HRTIM_CMP1xR_CMP1x_Pos          (0U)
#define HRTIM_CMP1xR_CMP1x_Msk          (0xFFFFUL << HRTIM_CMP1xR_CMP1x_Pos)      /*!< 0x0000FFFF */
#define HRTIM_CMP1xR_CMP1x                HRTIM_CMP1xR_CMP1x_Msk        /*!< CMP1x */

/************  Bit definition for HRTIM_CMP1CxR register  *************/
#define HRTIM_CMP1CxR_CMP1x_Pos         (0U)
#define HRTIM_CMP1CxR_CMP1x_Msk         (0xFFFFUL << HRTIM_CMP1CxR_CMP1x_Pos)       /*!< 0x0000FFFF */
#define HRTIM_CMP1CxR_CMP1x               HRTIM_CMP1CxR_CMP1x_Msk       /*!< CMP1x */
#define HRTIM_CMP1CxR_REPx_Pos          (16U)
#define HRTIM_CMP1CxR_REPx_Msk          (0xFFUL << HRTIM_CMP1CxR_REPx_Pos)    /*!< 0x00FF0000 */
#define HRTIM_CMP1CxR_REPx                HRTIM_CMP1CxR_REPx_Msk        /*!< REPx */

/*************  Bit definition for HRTIM_CMP2xR register  *************/
#define HRTIM_CMP2xR_CMP2x_Pos          (0U)
#define HRTIM_CMP2xR_CMP2x_Msk          (0xFFFFUL << HRTIM_CMP2xR_CMP2x_Pos)      /*!< 0x0000FFFF */
#define HRTIM_CMP2xR_CMP2x                HRTIM_CMP2xR_CMP2x_Msk        /*!< CMP2x */

/*************  Bit definition for HRTIM_CMP3xR register  *************/
#define HRTIM_CMP3xR_CMP3x_Pos          (0U)
#define HRTIM_CMP3xR_CMP3x_Msk          (0xFFFFUL << HRTIM_CMP3xR_CMP3x_Pos)      /*!< 0x0000FFFF */
#define HRTIM_CMP3xR_CMP3x                HRTIM_CMP3xR_CMP3x_Msk        /*!< CMP3x */

/*************  Bit definition for HRTIM_CMP4xR register  *************/
#define HRTIM_CMP4xR_CMP4x_Pos          (0U)
#define HRTIM_CMP4xR_CMP4x_Msk          (0xFFFFUL << HRTIM_CMP4xR_CMP4x_Pos)      /*!< 0x0000FFFF */
#define HRTIM_CMP4xR_CMP4x                HRTIM_CMP4xR_CMP4x_Msk        /*!< CMP4x */

/*************  Bit definition for HRTIM_CPT1xR register  *************/
#define HRTIM_CPT1xR_CPT1x_Pos          (0U)
#define HRTIM_CPT1xR_CPT1x_Msk          (0xFFFFUL << HRTIM_CPT1xR_CPT1x_Pos)      /*!< 0x0000FFFF */
#define HRTIM_CPT1xR_CPT1x                HRTIM_CPT1xR_CPT1x_Msk        /*!< CPT1x */
#define HRTIM_CPT1xR_DIR_Pos            (16U)
#define HRTIM_CPT1xR_DIR_Msk            (0x1UL << HRTIM_CPT1xR_DIR_Pos) /*!< 0x00010000 */
#define HRTIM_CPT1xR_DIR                  HRTIM_CPT1xR_DIR_Msk          /*!< DIR */

/*************  Bit definition for HRTIM_CPT2xR register  *************/
#define HRTIM_CPT2xR_CPT2x_Pos          (0U)
#define HRTIM_CPT2xR_CPT2x_Msk          (0xFFFFUL << HRTIM_CPT2xR_CPT2x_Pos)      /*!< 0x0000FFFF */
#define HRTIM_CPT2xR_CPT2x                HRTIM_CPT2xR_CPT2x_Msk        /*!< CPT2x */
#define HRTIM_CPT2xR_DIR_Pos            (16U)
#define HRTIM_CPT2xR_DIR_Msk            (0x1UL << HRTIM_CPT2xR_DIR_Pos) /*!< 0x00010000 */
#define HRTIM_CPT2xR_DIR                  HRTIM_CPT2xR_DIR_Msk          /*!< DIR */

/**************  Bit definition for HRTIM_DTxR register  **************/
#define HRTIM_DTxR_DTRx_Pos             (0U)
#define HRTIM_DTxR_DTRx_Msk             (0x1FFUL << HRTIM_DTxR_DTRx_Pos)  /*!< 0x000001FF */
#define HRTIM_DTxR_DTRx                   HRTIM_DTxR_DTRx_Msk           /*!< DTRx */
#define HRTIM_DTxR_DTRx_0             (0x1UL << HRTIM_DTxR_DTRx_Pos)   /*!< 0x00000001 */
#define HRTIM_DTxR_DTRx_1             (0x2UL << HRTIM_DTxR_DTRx_Pos)   /*!< 0x00000002 */
#define HRTIM_DTxR_DTRx_2             (0x4UL << HRTIM_DTxR_DTRx_Pos)   /*!< 0x00000004 */
#define HRTIM_DTxR_DTRx_3             (0x8UL << HRTIM_DTxR_DTRx_Pos)   /*!< 0x00000008 */
#define HRTIM_DTxR_DTRx_4             (0x10UL << HRTIM_DTxR_DTRx_Pos)   /*!< 0x00000010 */
#define HRTIM_DTxR_DTRx_5             (0x20UL << HRTIM_DTxR_DTRx_Pos)   /*!< 0x00000020 */
#define HRTIM_DTxR_DTRx_6             (0x40UL << HRTIM_DTxR_DTRx_Pos)   /*!< 0x00000040 */
#define HRTIM_DTxR_DTRx_7             (0x80UL << HRTIM_DTxR_DTRx_Pos)   /*!< 0x00000080 */
#define HRTIM_DTxR_DTRx_8             (0x100UL << HRTIM_DTxR_DTRx_Pos)   /*!< 0x00000100 */
#define HRTIM_DTxR_SDTRx_Pos            (9U)
#define HRTIM_DTxR_SDTRx_Msk            (0x1UL << HRTIM_DTxR_SDTRx_Pos) /*!< 0x00000200 */
#define HRTIM_DTxR_SDTRx                  HRTIM_DTxR_SDTRx_Msk          /*!< SDTRx */
#define HRTIM_DTxR_DTPRSC_Pos           (10U)
#define HRTIM_DTxR_DTPRSC_Msk           (0x7UL << HRTIM_DTxR_DTPRSC_Pos)  /*!< 0x00001C00 */
#define HRTIM_DTxR_DTPRSC                 HRTIM_DTxR_DTPRSC_Msk         /*!< DTPRSC */
#define HRTIM_DTxR_DTPRSC_0           (0x1UL << HRTIM_DTxR_DTPRSC_Pos)   /*!< 0x00000400 */
#define HRTIM_DTxR_DTPRSC_1           (0x2UL << HRTIM_DTxR_DTPRSC_Pos)   /*!< 0x00000800 */
#define HRTIM_DTxR_DTPRSC_2           (0x4UL << HRTIM_DTxR_DTPRSC_Pos)   /*!< 0x00001000 */
#define HRTIM_DTxR_DTRSLKx_Pos          (14U)
#define HRTIM_DTxR_DTRSLKx_Msk          (0x1UL << HRTIM_DTxR_DTRSLKx_Pos)   /*!< 0x00004000 */
#define HRTIM_DTxR_DTRSLKx                HRTIM_DTxR_DTRSLKx_Msk        /*!< DTRSLKx */
#define HRTIM_DTxR_DTRLKx_Pos           (15U)
#define HRTIM_DTxR_DTRLKx_Msk           (0x1UL << HRTIM_DTxR_DTRLKx_Pos)  /*!< 0x00008000 */
#define HRTIM_DTxR_DTRLKx                 HRTIM_DTxR_DTRLKx_Msk         /*!< DTRLKx */
#define HRTIM_DTxR_DTFx_Pos             (16U)
#define HRTIM_DTxR_DTFx_Msk             (0x1FFUL << HRTIM_DTxR_DTFx_Pos)  /*!< 0x01FF0000 */
#define HRTIM_DTxR_DTFx                   HRTIM_DTxR_DTFx_Msk           /*!< DTFx */
#define HRTIM_DTxR_DTFx_0             (0x1UL << HRTIM_DTxR_DTFx_Pos)   /*!< 0x00010000 */
#define HRTIM_DTxR_DTFx_1             (0x2UL << HRTIM_DTxR_DTFx_Pos)   /*!< 0x00020000 */
#define HRTIM_DTxR_DTFx_2             (0x4UL << HRTIM_DTxR_DTFx_Pos)   /*!< 0x00040000 */
#define HRTIM_DTxR_DTFx_3             (0x8UL << HRTIM_DTxR_DTFx_Pos)   /*!< 0x00080000 */
#define HRTIM_DTxR_DTFx_4             (0x10UL << HRTIM_DTxR_DTFx_Pos)   /*!< 0x00100000 */
#define HRTIM_DTxR_DTFx_5             (0x20UL << HRTIM_DTxR_DTFx_Pos)   /*!< 0x00200000 */
#define HRTIM_DTxR_DTFx_6             (0x40UL << HRTIM_DTxR_DTFx_Pos)   /*!< 0x00400000 */
#define HRTIM_DTxR_DTFx_7             (0x80UL << HRTIM_DTxR_DTFx_Pos)   /*!< 0x00800000 */
#define HRTIM_DTxR_DTFx_8             (0x100UL << HRTIM_DTxR_DTFx_Pos)   /*!< 0x01000000 */
#define HRTIM_DTxR_SDTFx_Pos            (25U)
#define HRTIM_DTxR_SDTFx_Msk            (0x1UL << HRTIM_DTxR_SDTFx_Pos) /*!< 0x02000000 */
#define HRTIM_DTxR_SDTFx                  HRTIM_DTxR_SDTFx_Msk          /*!< SDTFx */
#define HRTIM_DTxR_SDTFSLKx_Pos         (30U)
#define HRTIM_DTxR_SDTFSLKx_Msk         (0x1UL << HRTIM_DTxR_SDTFSLKx_Pos)    /*!< 0x40000000 */
#define HRTIM_DTxR_SDTFSLKx               HRTIM_DTxR_SDTFSLKx_Msk       /*!< SDTFSLKx */
#define HRTIM_DTxR_DTFLKx_Pos           (31U)
#define HRTIM_DTxR_DTFLKx_Msk           (0x1UL << HRTIM_DTxR_DTFLKx_Pos)  /*!< 0x80000000 */
#define HRTIM_DTxR_DTFLKx                 HRTIM_DTxR_DTFLKx_Msk         /*!< DTFLKx */

/*************  Bit definition for HRTIM_SETx1R register  *************/
#define HRTIM_SETx1R_SST_Pos            (0U)
#define HRTIM_SETx1R_SST_Msk            (0x1UL << HRTIM_SETx1R_SST_Pos) /*!< 0x00000001 */
#define HRTIM_SETx1R_SST                  HRTIM_SETx1R_SST_Msk          /*!< SST */
#define HRTIM_SETx1R_RESYNC_Pos         (1U)
#define HRTIM_SETx1R_RESYNC_Msk         (0x1UL << HRTIM_SETx1R_RESYNC_Pos)    /*!< 0x00000002 */
#define HRTIM_SETx1R_RESYNC               HRTIM_SETx1R_RESYNC_Msk       /*!< RESYNC */
#define HRTIM_SETx1R_PER_Pos            (2U)
#define HRTIM_SETx1R_PER_Msk            (0x1UL << HRTIM_SETx1R_PER_Pos) /*!< 0x00000004 */
#define HRTIM_SETx1R_PER                  HRTIM_SETx1R_PER_Msk          /*!< PER */
#define HRTIM_SETx1R_CMP1_Pos           (3U)
#define HRTIM_SETx1R_CMP1_Msk           (0x1UL << HRTIM_SETx1R_CMP1_Pos)  /*!< 0x00000008 */
#define HRTIM_SETx1R_CMP1                 HRTIM_SETx1R_CMP1_Msk         /*!< CMP1 */
#define HRTIM_SETx1R_CMP2_Pos           (4U)
#define HRTIM_SETx1R_CMP2_Msk           (0x1UL << HRTIM_SETx1R_CMP2_Pos)  /*!< 0x00000010 */
#define HRTIM_SETx1R_CMP2                 HRTIM_SETx1R_CMP2_Msk         /*!< CMP2 */
#define HRTIM_SETx1R_CMP3_Pos           (5U)
#define HRTIM_SETx1R_CMP3_Msk           (0x1UL << HRTIM_SETx1R_CMP3_Pos)  /*!< 0x00000020 */
#define HRTIM_SETx1R_CMP3                 HRTIM_SETx1R_CMP3_Msk         /*!< CMP3 */
#define HRTIM_SETx1R_CMP4_Pos           (6U)
#define HRTIM_SETx1R_CMP4_Msk           (0x1UL << HRTIM_SETx1R_CMP4_Pos)  /*!< 0x00000040 */
#define HRTIM_SETx1R_CMP4                 HRTIM_SETx1R_CMP4_Msk         /*!< CMP4 */
#define HRTIM_SETx1R_MSTPER_Pos         (7U)
#define HRTIM_SETx1R_MSTPER_Msk         (0x1UL << HRTIM_SETx1R_MSTPER_Pos)    /*!< 0x00000080 */
#define HRTIM_SETx1R_MSTPER               HRTIM_SETx1R_MSTPER_Msk       /*!< MSTPER */
#define HRTIM_SETx1R_MSTCMP1_Pos        (8U)
#define HRTIM_SETx1R_MSTCMP1_Msk        (0x1UL << HRTIM_SETx1R_MSTCMP1_Pos)     /*!< 0x00000100 */
#define HRTIM_SETx1R_MSTCMP1              HRTIM_SETx1R_MSTCMP1_Msk      /*!< MSTCMP1 */
#define HRTIM_SETx1R_MSTCMP2_Pos        (9U)
#define HRTIM_SETx1R_MSTCMP2_Msk        (0x1UL << HRTIM_SETx1R_MSTCMP2_Pos)     /*!< 0x00000200 */
#define HRTIM_SETx1R_MSTCMP2              HRTIM_SETx1R_MSTCMP2_Msk      /*!< MSTCMP2 */
#define HRTIM_SETx1R_MSTCMP3_Pos        (10U)
#define HRTIM_SETx1R_MSTCMP3_Msk        (0x1UL << HRTIM_SETx1R_MSTCMP3_Pos)     /*!< 0x00000400 */
#define HRTIM_SETx1R_MSTCMP3              HRTIM_SETx1R_MSTCMP3_Msk      /*!< MSTCMP3 */
#define HRTIM_SETx1R_MSTCMP4_Pos        (11U)
#define HRTIM_SETx1R_MSTCMP4_Msk        (0x1UL << HRTIM_SETx1R_MSTCMP4_Pos)     /*!< 0x00000800 */
#define HRTIM_SETx1R_MSTCMP4              HRTIM_SETx1R_MSTCMP4_Msk      /*!< MSTCMP4 */
#define HRTIM_SETx1R_TIMEVNT1_Pos       (12U)
#define HRTIM_SETx1R_TIMEVNT1_Msk       (0x1UL << HRTIM_SETx1R_TIMEVNT1_Pos)      /*!< 0x00001000 */
#define HRTIM_SETx1R_TIMEVNT1             HRTIM_SETx1R_TIMEVNT1_Msk     /*!< TIMEVNT1 */
#define HRTIM_SETx1R_TIMEVNT2_Pos       (13U)
#define HRTIM_SETx1R_TIMEVNT2_Msk       (0x1UL << HRTIM_SETx1R_TIMEVNT2_Pos)      /*!< 0x00002000 */
#define HRTIM_SETx1R_TIMEVNT2             HRTIM_SETx1R_TIMEVNT2_Msk     /*!< TIMEVNT2 */
#define HRTIM_SETx1R_TIMEVNT3_Pos       (14U)
#define HRTIM_SETx1R_TIMEVNT3_Msk       (0x1UL << HRTIM_SETx1R_TIMEVNT3_Pos)      /*!< 0x00004000 */
#define HRTIM_SETx1R_TIMEVNT3             HRTIM_SETx1R_TIMEVNT3_Msk     /*!< TIMEVNT3 */
#define HRTIM_SETx1R_TIMEVNT4_Pos       (15U)
#define HRTIM_SETx1R_TIMEVNT4_Msk       (0x1UL << HRTIM_SETx1R_TIMEVNT4_Pos)      /*!< 0x00008000 */
#define HRTIM_SETx1R_TIMEVNT4             HRTIM_SETx1R_TIMEVNT4_Msk     /*!< TIMEVNT4 */
#define HRTIM_SETx1R_TIMEVNT5_Pos       (16U)
#define HRTIM_SETx1R_TIMEVNT5_Msk       (0x1UL << HRTIM_SETx1R_TIMEVNT5_Pos)      /*!< 0x00010000 */
#define HRTIM_SETx1R_TIMEVNT5             HRTIM_SETx1R_TIMEVNT5_Msk     /*!< TIMEVNT5 */
#define HRTIM_SETx1R_TIMEVNT6_Pos       (17U)
#define HRTIM_SETx1R_TIMEVNT6_Msk       (0x1UL << HRTIM_SETx1R_TIMEVNT6_Pos)      /*!< 0x00020000 */
#define HRTIM_SETx1R_TIMEVNT6             HRTIM_SETx1R_TIMEVNT6_Msk     /*!< TIMEVNT6 */
#define HRTIM_SETx1R_TIMEVNT7_Pos       (18U)
#define HRTIM_SETx1R_TIMEVNT7_Msk       (0x1UL << HRTIM_SETx1R_TIMEVNT7_Pos)      /*!< 0x00040000 */
#define HRTIM_SETx1R_TIMEVNT7             HRTIM_SETx1R_TIMEVNT7_Msk     /*!< TIMEVNT7 */
#define HRTIM_SETx1R_TIMEVNT8_Pos       (19U)
#define HRTIM_SETx1R_TIMEVNT8_Msk       (0x1UL << HRTIM_SETx1R_TIMEVNT8_Pos)      /*!< 0x00080000 */
#define HRTIM_SETx1R_TIMEVNT8             HRTIM_SETx1R_TIMEVNT8_Msk     /*!< TIMEVNT8 */
#define HRTIM_SETx1R_TIMEVNT9_Pos       (20U)
#define HRTIM_SETx1R_TIMEVNT9_Msk       (0x1UL << HRTIM_SETx1R_TIMEVNT9_Pos)      /*!< 0x00100000 */
#define HRTIM_SETx1R_TIMEVNT9             HRTIM_SETx1R_TIMEVNT9_Msk     /*!< TIMEVNT9 */
#define HRTIM_SETx1R_EXTVNT1_Pos        (21U)
#define HRTIM_SETx1R_EXTVNT1_Msk        (0x1UL << HRTIM_SETx1R_EXTVNT1_Pos)     /*!< 0x00200000 */
#define HRTIM_SETx1R_EXTVNT1              HRTIM_SETx1R_EXTVNT1_Msk      /*!< EXTVNT1 */
#define HRTIM_SETx1R_EXTVNT2_Pos        (22U)
#define HRTIM_SETx1R_EXTVNT2_Msk        (0x1UL << HRTIM_SETx1R_EXTVNT2_Pos)     /*!< 0x00400000 */
#define HRTIM_SETx1R_EXTVNT2              HRTIM_SETx1R_EXTVNT2_Msk      /*!< EXTVNT2 */
#define HRTIM_SETx1R_EXTVNT3_Pos        (23U)
#define HRTIM_SETx1R_EXTVNT3_Msk        (0x1UL << HRTIM_SETx1R_EXTVNT3_Pos)     /*!< 0x00800000 */
#define HRTIM_SETx1R_EXTVNT3              HRTIM_SETx1R_EXTVNT3_Msk      /*!< EXTVNT3 */
#define HRTIM_SETx1R_EXTVNT4_Pos        (24U)
#define HRTIM_SETx1R_EXTVNT4_Msk        (0x1UL << HRTIM_SETx1R_EXTVNT4_Pos)     /*!< 0x01000000 */
#define HRTIM_SETx1R_EXTVNT4              HRTIM_SETx1R_EXTVNT4_Msk      /*!< EXTVNT4 */
#define HRTIM_SETx1R_EXTVNT5_Pos        (25U)
#define HRTIM_SETx1R_EXTVNT5_Msk        (0x1UL << HRTIM_SETx1R_EXTVNT5_Pos)     /*!< 0x02000000 */
#define HRTIM_SETx1R_EXTVNT5              HRTIM_SETx1R_EXTVNT5_Msk      /*!< EXTVNT5 */
#define HRTIM_SETx1R_EXTVNT6_Pos        (26U)
#define HRTIM_SETx1R_EXTVNT6_Msk        (0x1UL << HRTIM_SETx1R_EXTVNT6_Pos)     /*!< 0x04000000 */
#define HRTIM_SETx1R_EXTVNT6              HRTIM_SETx1R_EXTVNT6_Msk      /*!< EXTVNT6 */
#define HRTIM_SETx1R_EXTVNT7_Pos        (27U)
#define HRTIM_SETx1R_EXTVNT7_Msk        (0x1UL << HRTIM_SETx1R_EXTVNT7_Pos)     /*!< 0x08000000 */
#define HRTIM_SETx1R_EXTVNT7              HRTIM_SETx1R_EXTVNT7_Msk      /*!< EXTVNT7 */
#define HRTIM_SETx1R_EXTVNT8_Pos        (28U)
#define HRTIM_SETx1R_EXTVNT8_Msk        (0x1UL << HRTIM_SETx1R_EXTVNT8_Pos)     /*!< 0x10000000 */
#define HRTIM_SETx1R_EXTVNT8              HRTIM_SETx1R_EXTVNT8_Msk      /*!< EXTVNT8 */
#define HRTIM_SETx1R_EXTVNT9_Pos        (29U)
#define HRTIM_SETx1R_EXTVNT9_Msk        (0x1UL << HRTIM_SETx1R_EXTVNT9_Pos)     /*!< 0x20000000 */
#define HRTIM_SETx1R_EXTVNT9              HRTIM_SETx1R_EXTVNT9_Msk      /*!< EXTVNT9 */
#define HRTIM_SETx1R_EXTVNT10_Pos       (30U)
#define HRTIM_SETx1R_EXTVNT10_Msk       (0x1UL << HRTIM_SETx1R_EXTVNT10_Pos)      /*!< 0x40000000 */
#define HRTIM_SETx1R_EXTVNT10             HRTIM_SETx1R_EXTVNT10_Msk     /*!< EXTVNT10 */
#define HRTIM_SETx1R_UPDATE_Pos         (31U)
#define HRTIM_SETx1R_UPDATE_Msk         (0x1UL << HRTIM_SETx1R_UPDATE_Pos)    /*!< 0x80000000 */
#define HRTIM_SETx1R_UPDATE               HRTIM_SETx1R_UPDATE_Msk       /*!< UPDATE */

/*************  Bit definition for HRTIM_RSTx1R register  *************/
#define HRTIM_RSTx1R_SRT_Pos            (0U)
#define HRTIM_RSTx1R_SRT_Msk            (0x1UL << HRTIM_RSTx1R_SRT_Pos) /*!< 0x00000001 */
#define HRTIM_RSTx1R_SRT                  HRTIM_RSTx1R_SRT_Msk          /*!< SRT */
#define HRTIM_RSTx1R_RESYNC_Pos         (1U)
#define HRTIM_RSTx1R_RESYNC_Msk         (0x1UL << HRTIM_RSTx1R_RESYNC_Pos)    /*!< 0x00000002 */
#define HRTIM_RSTx1R_RESYNC               HRTIM_RSTx1R_RESYNC_Msk       /*!< RESYNC */
#define HRTIM_RSTx1R_PER_Pos            (2U)
#define HRTIM_RSTx1R_PER_Msk            (0x1UL << HRTIM_RSTx1R_PER_Pos) /*!< 0x00000004 */
#define HRTIM_RSTx1R_PER                  HRTIM_RSTx1R_PER_Msk          /*!< PER */
#define HRTIM_RSTx1R_CMP1_Pos           (3U)
#define HRTIM_RSTx1R_CMP1_Msk           (0x1UL << HRTIM_RSTx1R_CMP1_Pos)  /*!< 0x00000008 */
#define HRTIM_RSTx1R_CMP1                 HRTIM_RSTx1R_CMP1_Msk         /*!< CMP1 */
#define HRTIM_RSTx1R_CMP2_Pos           (4U)
#define HRTIM_RSTx1R_CMP2_Msk           (0x1UL << HRTIM_RSTx1R_CMP2_Pos)  /*!< 0x00000010 */
#define HRTIM_RSTx1R_CMP2                 HRTIM_RSTx1R_CMP2_Msk         /*!< CMP2 */
#define HRTIM_RSTx1R_CMP3_Pos           (5U)
#define HRTIM_RSTx1R_CMP3_Msk           (0x1UL << HRTIM_RSTx1R_CMP3_Pos)  /*!< 0x00000020 */
#define HRTIM_RSTx1R_CMP3                 HRTIM_RSTx1R_CMP3_Msk         /*!< CMP3 */
#define HRTIM_RSTx1R_CMP4_Pos           (6U)
#define HRTIM_RSTx1R_CMP4_Msk           (0x1UL << HRTIM_RSTx1R_CMP4_Pos)  /*!< 0x00000040 */
#define HRTIM_RSTx1R_CMP4                 HRTIM_RSTx1R_CMP4_Msk         /*!< CMP4 */
#define HRTIM_RSTx1R_MSTPER_Pos         (7U)
#define HRTIM_RSTx1R_MSTPER_Msk         (0x1UL << HRTIM_RSTx1R_MSTPER_Pos)    /*!< 0x00000080 */
#define HRTIM_RSTx1R_MSTPER               HRTIM_RSTx1R_MSTPER_Msk       /*!< MSTPER */
#define HRTIM_RSTx1R_MSTCMP1_Pos        (8U)
#define HRTIM_RSTx1R_MSTCMP1_Msk        (0x1UL << HRTIM_RSTx1R_MSTCMP1_Pos)     /*!< 0x00000100 */
#define HRTIM_RSTx1R_MSTCMP1              HRTIM_RSTx1R_MSTCMP1_Msk      /*!< MSTCMP1 */
#define HRTIM_RSTx1R_MSTCMP2_Pos        (9U)
#define HRTIM_RSTx1R_MSTCMP2_Msk        (0x1UL << HRTIM_RSTx1R_MSTCMP2_Pos)     /*!< 0x00000200 */
#define HRTIM_RSTx1R_MSTCMP2              HRTIM_RSTx1R_MSTCMP2_Msk      /*!< MSTCMP2 */
#define HRTIM_RSTx1R_MSTCMP3_Pos        (10U)
#define HRTIM_RSTx1R_MSTCMP3_Msk        (0x1UL << HRTIM_RSTx1R_MSTCMP3_Pos)     /*!< 0x00000400 */
#define HRTIM_RSTx1R_MSTCMP3              HRTIM_RSTx1R_MSTCMP3_Msk      /*!< MSTCMP3 */
#define HRTIM_RSTx1R_MSTCMP4_Pos        (11U)
#define HRTIM_RSTx1R_MSTCMP4_Msk        (0x1UL << HRTIM_RSTx1R_MSTCMP4_Pos)     /*!< 0x00000800 */
#define HRTIM_RSTx1R_MSTCMP4              HRTIM_RSTx1R_MSTCMP4_Msk      /*!< MSTCMP4 */
#define HRTIM_RSTx1R_TIMEVNT1_Pos       (12U)
#define HRTIM_RSTx1R_TIMEVNT1_Msk       (0x1UL << HRTIM_RSTx1R_TIMEVNT1_Pos)      /*!< 0x00001000 */
#define HRTIM_RSTx1R_TIMEVNT1             HRTIM_RSTx1R_TIMEVNT1_Msk     /*!< TIMEVNT1 */
#define HRTIM_RSTx1R_TIMEVNT2_Pos       (13U)
#define HRTIM_RSTx1R_TIMEVNT2_Msk       (0x1UL << HRTIM_RSTx1R_TIMEVNT2_Pos)      /*!< 0x00002000 */
#define HRTIM_RSTx1R_TIMEVNT2             HRTIM_RSTx1R_TIMEVNT2_Msk     /*!< TIMEVNT2 */
#define HRTIM_RSTx1R_TIMEVNT3_Pos       (14U)
#define HRTIM_RSTx1R_TIMEVNT3_Msk       (0x1UL << HRTIM_RSTx1R_TIMEVNT3_Pos)      /*!< 0x00004000 */
#define HRTIM_RSTx1R_TIMEVNT3             HRTIM_RSTx1R_TIMEVNT3_Msk     /*!< TIMEVNT3 */
#define HRTIM_RSTx1R_TIMEVNT4_Pos       (15U)
#define HRTIM_RSTx1R_TIMEVNT4_Msk       (0x1UL << HRTIM_RSTx1R_TIMEVNT4_Pos)      /*!< 0x00008000 */
#define HRTIM_RSTx1R_TIMEVNT4             HRTIM_RSTx1R_TIMEVNT4_Msk     /*!< TIMEVNT4 */
#define HRTIM_RSTx1R_TIMEVNT5_Pos       (16U)
#define HRTIM_RSTx1R_TIMEVNT5_Msk       (0x1UL << HRTIM_RSTx1R_TIMEVNT5_Pos)      /*!< 0x00010000 */
#define HRTIM_RSTx1R_TIMEVNT5             HRTIM_RSTx1R_TIMEVNT5_Msk     /*!< TIMEVNT5 */
#define HRTIM_RSTx1R_TIMEVNT6_Pos       (17U)
#define HRTIM_RSTx1R_TIMEVNT6_Msk       (0x1UL << HRTIM_RSTx1R_TIMEVNT6_Pos)      /*!< 0x00020000 */
#define HRTIM_RSTx1R_TIMEVNT6             HRTIM_RSTx1R_TIMEVNT6_Msk     /*!< TIMEVNT6 */
#define HRTIM_RSTx1R_TIMEVNT7_Pos       (18U)
#define HRTIM_RSTx1R_TIMEVNT7_Msk       (0x1UL << HRTIM_RSTx1R_TIMEVNT7_Pos)      /*!< 0x00040000 */
#define HRTIM_RSTx1R_TIMEVNT7             HRTIM_RSTx1R_TIMEVNT7_Msk     /*!< TIMEVNT7 */
#define HRTIM_RSTx1R_TIMEVNT8_Pos       (19U)
#define HRTIM_RSTx1R_TIMEVNT8_Msk       (0x1UL << HRTIM_RSTx1R_TIMEVNT8_Pos)      /*!< 0x00080000 */
#define HRTIM_RSTx1R_TIMEVNT8             HRTIM_RSTx1R_TIMEVNT8_Msk     /*!< TIMEVNT8 */
#define HRTIM_RSTx1R_TIMEVNT9_Pos       (20U)
#define HRTIM_RSTx1R_TIMEVNT9_Msk       (0x1UL << HRTIM_RSTx1R_TIMEVNT9_Pos)      /*!< 0x00100000 */
#define HRTIM_RSTx1R_TIMEVNT9             HRTIM_RSTx1R_TIMEVNT9_Msk     /*!< TIMEVNT9 */
#define HRTIM_RSTx1R_EXTVNT1_Pos        (21U)
#define HRTIM_RSTx1R_EXTVNT1_Msk        (0x1UL << HRTIM_RSTx1R_EXTVNT1_Pos)     /*!< 0x00200000 */
#define HRTIM_RSTx1R_EXTVNT1              HRTIM_RSTx1R_EXTVNT1_Msk      /*!< EXTVNT1 */
#define HRTIM_RSTx1R_EXTVNT2_Pos        (22U)
#define HRTIM_RSTx1R_EXTVNT2_Msk        (0x1UL << HRTIM_RSTx1R_EXTVNT2_Pos)     /*!< 0x00400000 */
#define HRTIM_RSTx1R_EXTVNT2              HRTIM_RSTx1R_EXTVNT2_Msk      /*!< EXTVNT2 */
#define HRTIM_RSTx1R_EXTVNT3_Pos        (23U)
#define HRTIM_RSTx1R_EXTVNT3_Msk        (0x1UL << HRTIM_RSTx1R_EXTVNT3_Pos)     /*!< 0x00800000 */
#define HRTIM_RSTx1R_EXTVNT3              HRTIM_RSTx1R_EXTVNT3_Msk      /*!< EXTVNT3 */
#define HRTIM_RSTx1R_EXTVNT4_Pos        (24U)
#define HRTIM_RSTx1R_EXTVNT4_Msk        (0x1UL << HRTIM_RSTx1R_EXTVNT4_Pos)     /*!< 0x01000000 */
#define HRTIM_RSTx1R_EXTVNT4              HRTIM_RSTx1R_EXTVNT4_Msk      /*!< EXTVNT4 */
#define HRTIM_RSTx1R_EXTVNT5_Pos        (25U)
#define HRTIM_RSTx1R_EXTVNT5_Msk        (0x1UL << HRTIM_RSTx1R_EXTVNT5_Pos)     /*!< 0x02000000 */
#define HRTIM_RSTx1R_EXTVNT5              HRTIM_RSTx1R_EXTVNT5_Msk      /*!< EXTVNT5 */
#define HRTIM_RSTx1R_EXTVNT6_Pos        (26U)
#define HRTIM_RSTx1R_EXTVNT6_Msk        (0x1UL << HRTIM_RSTx1R_EXTVNT6_Pos)     /*!< 0x04000000 */
#define HRTIM_RSTx1R_EXTVNT6              HRTIM_RSTx1R_EXTVNT6_Msk      /*!< EXTVNT6 */
#define HRTIM_RSTx1R_EXTVNT7_Pos        (27U)
#define HRTIM_RSTx1R_EXTVNT7_Msk        (0x1UL << HRTIM_RSTx1R_EXTVNT7_Pos)     /*!< 0x08000000 */
#define HRTIM_RSTx1R_EXTVNT7              HRTIM_RSTx1R_EXTVNT7_Msk      /*!< EXTVNT7 */
#define HRTIM_RSTx1R_EXTVNT8_Pos        (28U)
#define HRTIM_RSTx1R_EXTVNT8_Msk        (0x1UL << HRTIM_RSTx1R_EXTVNT8_Pos)     /*!< 0x10000000 */
#define HRTIM_RSTx1R_EXTVNT8              HRTIM_RSTx1R_EXTVNT8_Msk      /*!< EXTVNT8 */
#define HRTIM_RSTx1R_EXTVNT9_Pos        (29U)
#define HRTIM_RSTx1R_EXTVNT9_Msk        (0x1UL << HRTIM_RSTx1R_EXTVNT9_Pos)     /*!< 0x20000000 */
#define HRTIM_RSTx1R_EXTVNT9              HRTIM_RSTx1R_EXTVNT9_Msk      /*!< EXTVNT9 */
#define HRTIM_RSTx1R_EXTVNT10_Pos       (30U)
#define HRTIM_RSTx1R_EXTVNT10_Msk       (0x1UL << HRTIM_RSTx1R_EXTVNT10_Pos)      /*!< 0x40000000 */
#define HRTIM_RSTx1R_EXTVNT10             HRTIM_RSTx1R_EXTVNT10_Msk     /*!< EXTVNT10 */
#define HRTIM_RSTx1R_UPDATE_Pos         (31U)
#define HRTIM_RSTx1R_UPDATE_Msk         (0x1UL << HRTIM_RSTx1R_UPDATE_Pos)    /*!< 0x80000000 */
#define HRTIM_RSTx1R_UPDATE               HRTIM_RSTx1R_UPDATE_Msk       /*!< UPDATE */

/*************  Bit definition for HRTIM_SETx2R register  *************/
#define HRTIM_SETx2R_SST_Pos            (0U)
#define HRTIM_SETx2R_SST_Msk            (0x1UL << HRTIM_SETx2R_SST_Pos) /*!< 0x00000001 */
#define HRTIM_SETx2R_SST                  HRTIM_SETx2R_SST_Msk          /*!< SST */
#define HRTIM_SETx2R_RESYNC_Pos         (1U)
#define HRTIM_SETx2R_RESYNC_Msk         (0x1UL << HRTIM_SETx2R_RESYNC_Pos)    /*!< 0x00000002 */
#define HRTIM_SETx2R_RESYNC               HRTIM_SETx2R_RESYNC_Msk       /*!< RESYNC */
#define HRTIM_SETx2R_PER_Pos            (2U)
#define HRTIM_SETx2R_PER_Msk            (0x1UL << HRTIM_SETx2R_PER_Pos) /*!< 0x00000004 */
#define HRTIM_SETx2R_PER                  HRTIM_SETx2R_PER_Msk          /*!< PER */
#define HRTIM_SETx2R_CMP1_Pos           (3U)
#define HRTIM_SETx2R_CMP1_Msk           (0x1UL << HRTIM_SETx2R_CMP1_Pos)  /*!< 0x00000008 */
#define HRTIM_SETx2R_CMP1                 HRTIM_SETx2R_CMP1_Msk         /*!< CMP1 */
#define HRTIM_SETx2R_CMP2_Pos           (4U)
#define HRTIM_SETx2R_CMP2_Msk           (0x1UL << HRTIM_SETx2R_CMP2_Pos)  /*!< 0x00000010 */
#define HRTIM_SETx2R_CMP2                 HRTIM_SETx2R_CMP2_Msk         /*!< CMP2 */
#define HRTIM_SETx2R_CMP3_Pos           (5U)
#define HRTIM_SETx2R_CMP3_Msk           (0x1UL << HRTIM_SETx2R_CMP3_Pos)  /*!< 0x00000020 */
#define HRTIM_SETx2R_CMP3                 HRTIM_SETx2R_CMP3_Msk         /*!< CMP3 */
#define HRTIM_SETx2R_CMP4_Pos           (6U)
#define HRTIM_SETx2R_CMP4_Msk           (0x1UL << HRTIM_SETx2R_CMP4_Pos)  /*!< 0x00000040 */
#define HRTIM_SETx2R_CMP4                 HRTIM_SETx2R_CMP4_Msk         /*!< CMP4 */
#define HRTIM_SETx2R_MSTPER_Pos         (7U)
#define HRTIM_SETx2R_MSTPER_Msk         (0x1UL << HRTIM_SETx2R_MSTPER_Pos)    /*!< 0x00000080 */
#define HRTIM_SETx2R_MSTPER               HRTIM_SETx2R_MSTPER_Msk       /*!< MSTPER */
#define HRTIM_SETx2R_MSTCMP1_Pos        (8U)
#define HRTIM_SETx2R_MSTCMP1_Msk        (0x1UL << HRTIM_SETx2R_MSTCMP1_Pos)     /*!< 0x00000100 */
#define HRTIM_SETx2R_MSTCMP1              HRTIM_SETx2R_MSTCMP1_Msk      /*!< MSTCMP1 */
#define HRTIM_SETx2R_MSTCMP2_Pos        (9U)
#define HRTIM_SETx2R_MSTCMP2_Msk        (0x1UL << HRTIM_SETx2R_MSTCMP2_Pos)     /*!< 0x00000200 */
#define HRTIM_SETx2R_MSTCMP2              HRTIM_SETx2R_MSTCMP2_Msk      /*!< MSTCMP2 */
#define HRTIM_SETx2R_MSTCMP3_Pos        (10U)
#define HRTIM_SETx2R_MSTCMP3_Msk        (0x1UL << HRTIM_SETx2R_MSTCMP3_Pos)     /*!< 0x00000400 */
#define HRTIM_SETx2R_MSTCMP3              HRTIM_SETx2R_MSTCMP3_Msk      /*!< MSTCMP3 */
#define HRTIM_SETx2R_MSTCMP4_Pos        (11U)
#define HRTIM_SETx2R_MSTCMP4_Msk        (0x1UL << HRTIM_SETx2R_MSTCMP4_Pos)     /*!< 0x00000800 */
#define HRTIM_SETx2R_MSTCMP4              HRTIM_SETx2R_MSTCMP4_Msk      /*!< MSTCMP4 */
#define HRTIM_SETx2R_TIMEVNT1_Pos       (12U)
#define HRTIM_SETx2R_TIMEVNT1_Msk       (0x1UL << HRTIM_SETx2R_TIMEVNT1_Pos)      /*!< 0x00001000 */
#define HRTIM_SETx2R_TIMEVNT1             HRTIM_SETx2R_TIMEVNT1_Msk     /*!< TIMEVNT1 */
#define HRTIM_SETx2R_TIMEVNT2_Pos       (13U)
#define HRTIM_SETx2R_TIMEVNT2_Msk       (0x1UL << HRTIM_SETx2R_TIMEVNT2_Pos)      /*!< 0x00002000 */
#define HRTIM_SETx2R_TIMEVNT2             HRTIM_SETx2R_TIMEVNT2_Msk     /*!< TIMEVNT2 */
#define HRTIM_SETx2R_TIMEVNT3_Pos       (14U)
#define HRTIM_SETx2R_TIMEVNT3_Msk       (0x1UL << HRTIM_SETx2R_TIMEVNT3_Pos)      /*!< 0x00004000 */
#define HRTIM_SETx2R_TIMEVNT3             HRTIM_SETx2R_TIMEVNT3_Msk     /*!< TIMEVNT3 */
#define HRTIM_SETx2R_TIMEVNT4_Pos       (15U)
#define HRTIM_SETx2R_TIMEVNT4_Msk       (0x1UL << HRTIM_SETx2R_TIMEVNT4_Pos)      /*!< 0x00008000 */
#define HRTIM_SETx2R_TIMEVNT4             HRTIM_SETx2R_TIMEVNT4_Msk     /*!< TIMEVNT4 */
#define HRTIM_SETx2R_TIMEVNT5_Pos       (16U)
#define HRTIM_SETx2R_TIMEVNT5_Msk       (0x1UL << HRTIM_SETx2R_TIMEVNT5_Pos)      /*!< 0x00010000 */
#define HRTIM_SETx2R_TIMEVNT5             HRTIM_SETx2R_TIMEVNT5_Msk     /*!< TIMEVNT5 */
#define HRTIM_SETx2R_TIMEVNT6_Pos       (17U)
#define HRTIM_SETx2R_TIMEVNT6_Msk       (0x1UL << HRTIM_SETx2R_TIMEVNT6_Pos)      /*!< 0x00020000 */
#define HRTIM_SETx2R_TIMEVNT6             HRTIM_SETx2R_TIMEVNT6_Msk     /*!< TIMEVNT6 */
#define HRTIM_SETx2R_TIMEVNT7_Pos       (18U)
#define HRTIM_SETx2R_TIMEVNT7_Msk       (0x1UL << HRTIM_SETx2R_TIMEVNT7_Pos)      /*!< 0x00040000 */
#define HRTIM_SETx2R_TIMEVNT7             HRTIM_SETx2R_TIMEVNT7_Msk     /*!< TIMEVNT7 */
#define HRTIM_SETx2R_TIMEVNT8_Pos       (19U)
#define HRTIM_SETx2R_TIMEVNT8_Msk       (0x1UL << HRTIM_SETx2R_TIMEVNT8_Pos)      /*!< 0x00080000 */
#define HRTIM_SETx2R_TIMEVNT8             HRTIM_SETx2R_TIMEVNT8_Msk     /*!< TIMEVNT8 */
#define HRTIM_SETx2R_TIMEVNT9_Pos       (20U)
#define HRTIM_SETx2R_TIMEVNT9_Msk       (0x1UL << HRTIM_SETx2R_TIMEVNT9_Pos)      /*!< 0x00100000 */
#define HRTIM_SETx2R_TIMEVNT9             HRTIM_SETx2R_TIMEVNT9_Msk     /*!< TIMEVNT9 */
#define HRTIM_SETx2R_EXTVNT1_Pos        (21U)
#define HRTIM_SETx2R_EXTVNT1_Msk        (0x1UL << HRTIM_SETx2R_EXTVNT1_Pos)     /*!< 0x00200000 */
#define HRTIM_SETx2R_EXTVNT1              HRTIM_SETx2R_EXTVNT1_Msk      /*!< EXTVNT1 */
#define HRTIM_SETx2R_EXTVNT2_Pos        (22U)
#define HRTIM_SETx2R_EXTVNT2_Msk        (0x1UL << HRTIM_SETx2R_EXTVNT2_Pos)     /*!< 0x00400000 */
#define HRTIM_SETx2R_EXTVNT2              HRTIM_SETx2R_EXTVNT2_Msk      /*!< EXTVNT2 */
#define HRTIM_SETx2R_EXTVNT3_Pos        (23U)
#define HRTIM_SETx2R_EXTVNT3_Msk        (0x1UL << HRTIM_SETx2R_EXTVNT3_Pos)     /*!< 0x00800000 */
#define HRTIM_SETx2R_EXTVNT3              HRTIM_SETx2R_EXTVNT3_Msk      /*!< EXTVNT3 */
#define HRTIM_SETx2R_EXTVNT4_Pos        (24U)
#define HRTIM_SETx2R_EXTVNT4_Msk        (0x1UL << HRTIM_SETx2R_EXTVNT4_Pos)     /*!< 0x01000000 */
#define HRTIM_SETx2R_EXTVNT4              HRTIM_SETx2R_EXTVNT4_Msk      /*!< EXTVNT4 */
#define HRTIM_SETx2R_EXTVNT5_Pos        (25U)
#define HRTIM_SETx2R_EXTVNT5_Msk        (0x1UL << HRTIM_SETx2R_EXTVNT5_Pos)     /*!< 0x02000000 */
#define HRTIM_SETx2R_EXTVNT5              HRTIM_SETx2R_EXTVNT5_Msk      /*!< EXTVNT5 */
#define HRTIM_SETx2R_EXTVNT6_Pos        (26U)
#define HRTIM_SETx2R_EXTVNT6_Msk        (0x1UL << HRTIM_SETx2R_EXTVNT6_Pos)     /*!< 0x04000000 */
#define HRTIM_SETx2R_EXTVNT6              HRTIM_SETx2R_EXTVNT6_Msk      /*!< EXTVNT6 */
#define HRTIM_SETx2R_EXTVNT7_Pos        (27U)
#define HRTIM_SETx2R_EXTVNT7_Msk        (0x1UL << HRTIM_SETx2R_EXTVNT7_Pos)     /*!< 0x08000000 */
#define HRTIM_SETx2R_EXTVNT7              HRTIM_SETx2R_EXTVNT7_Msk      /*!< EXTVNT7 */
#define HRTIM_SETx2R_EXTVNT8_Pos        (28U)
#define HRTIM_SETx2R_EXTVNT8_Msk        (0x1UL << HRTIM_SETx2R_EXTVNT8_Pos)     /*!< 0x10000000 */
#define HRTIM_SETx2R_EXTVNT8              HRTIM_SETx2R_EXTVNT8_Msk      /*!< EXTVNT8 */
#define HRTIM_SETx2R_EXTVNT9_Pos        (29U)
#define HRTIM_SETx2R_EXTVNT9_Msk        (0x1UL << HRTIM_SETx2R_EXTVNT9_Pos)     /*!< 0x20000000 */
#define HRTIM_SETx2R_EXTVNT9              HRTIM_SETx2R_EXTVNT9_Msk      /*!< EXTVNT9 */
#define HRTIM_SETx2R_EXTVNT10_Pos       (30U)
#define HRTIM_SETx2R_EXTVNT10_Msk       (0x1UL << HRTIM_SETx2R_EXTVNT10_Pos)      /*!< 0x40000000 */
#define HRTIM_SETx2R_EXTVNT10             HRTIM_SETx2R_EXTVNT10_Msk     /*!< EXTVNT10 */
#define HRTIM_SETx2R_UPDATE_Pos         (31U)
#define HRTIM_SETx2R_UPDATE_Msk         (0x1UL << HRTIM_SETx2R_UPDATE_Pos)    /*!< 0x80000000 */
#define HRTIM_SETx2R_UPDATE               HRTIM_SETx2R_UPDATE_Msk       /*!< UPDATE */

/*************  Bit definition for HRTIM_RSTx2R register  *************/
#define HRTIM_RSTx2R_SRT_Pos            (0U)
#define HRTIM_RSTx2R_SRT_Msk            (0x1UL << HRTIM_RSTx2R_SRT_Pos) /*!< 0x00000001 */
#define HRTIM_RSTx2R_SRT                  HRTIM_RSTx2R_SRT_Msk          /*!< SRT */
#define HRTIM_RSTx2R_RESYNC_Pos         (1U)
#define HRTIM_RSTx2R_RESYNC_Msk         (0x1UL << HRTIM_RSTx2R_RESYNC_Pos)    /*!< 0x00000002 */
#define HRTIM_RSTx2R_RESYNC               HRTIM_RSTx2R_RESYNC_Msk       /*!< RESYNC */
#define HRTIM_RSTx2R_PER_Pos            (2U)
#define HRTIM_RSTx2R_PER_Msk            (0x1UL << HRTIM_RSTx2R_PER_Pos) /*!< 0x00000004 */
#define HRTIM_RSTx2R_PER                  HRTIM_RSTx2R_PER_Msk          /*!< PER */
#define HRTIM_RSTx2R_CMP1_Pos           (3U)
#define HRTIM_RSTx2R_CMP1_Msk           (0x1UL << HRTIM_RSTx2R_CMP1_Pos)  /*!< 0x00000008 */
#define HRTIM_RSTx2R_CMP1                 HRTIM_RSTx2R_CMP1_Msk         /*!< CMP1 */
#define HRTIM_RSTx2R_CMP2_Pos           (4U)
#define HRTIM_RSTx2R_CMP2_Msk           (0x1UL << HRTIM_RSTx2R_CMP2_Pos)  /*!< 0x00000010 */
#define HRTIM_RSTx2R_CMP2                 HRTIM_RSTx2R_CMP2_Msk         /*!< CMP2 */
#define HRTIM_RSTx2R_CMP3_Pos           (5U)
#define HRTIM_RSTx2R_CMP3_Msk           (0x1UL << HRTIM_RSTx2R_CMP3_Pos)  /*!< 0x00000020 */
#define HRTIM_RSTx2R_CMP3                 HRTIM_RSTx2R_CMP3_Msk         /*!< CMP3 */
#define HRTIM_RSTx2R_CMP4_Pos           (6U)
#define HRTIM_RSTx2R_CMP4_Msk           (0x1UL << HRTIM_RSTx2R_CMP4_Pos)  /*!< 0x00000040 */
#define HRTIM_RSTx2R_CMP4                 HRTIM_RSTx2R_CMP4_Msk         /*!< CMP4 */
#define HRTIM_RSTx2R_MSTPER_Pos         (7U)
#define HRTIM_RSTx2R_MSTPER_Msk         (0x1UL << HRTIM_RSTx2R_MSTPER_Pos)    /*!< 0x00000080 */
#define HRTIM_RSTx2R_MSTPER               HRTIM_RSTx2R_MSTPER_Msk       /*!< MSTPER */
#define HRTIM_RSTx2R_MSTCMP1_Pos        (8U)
#define HRTIM_RSTx2R_MSTCMP1_Msk        (0x1UL << HRTIM_RSTx2R_MSTCMP1_Pos)     /*!< 0x00000100 */
#define HRTIM_RSTx2R_MSTCMP1              HRTIM_RSTx2R_MSTCMP1_Msk      /*!< MSTCMP1 */
#define HRTIM_RSTx2R_MSTCMP2_Pos        (9U)
#define HRTIM_RSTx2R_MSTCMP2_Msk        (0x1UL << HRTIM_RSTx2R_MSTCMP2_Pos)     /*!< 0x00000200 */
#define HRTIM_RSTx2R_MSTCMP2              HRTIM_RSTx2R_MSTCMP2_Msk      /*!< MSTCMP2 */
#define HRTIM_RSTx2R_MSTCMP3_Pos        (10U)
#define HRTIM_RSTx2R_MSTCMP3_Msk        (0x1UL << HRTIM_RSTx2R_MSTCMP3_Pos)     /*!< 0x00000400 */
#define HRTIM_RSTx2R_MSTCMP3              HRTIM_RSTx2R_MSTCMP3_Msk      /*!< MSTCMP3 */
#define HRTIM_RSTx2R_MSTCMP4_Pos        (11U)
#define HRTIM_RSTx2R_MSTCMP4_Msk        (0x1UL << HRTIM_RSTx2R_MSTCMP4_Pos)     /*!< 0x00000800 */
#define HRTIM_RSTx2R_MSTCMP4              HRTIM_RSTx2R_MSTCMP4_Msk      /*!< MSTCMP4 */
#define HRTIM_RSTx2R_TIMEVNT1_Pos       (12U)
#define HRTIM_RSTx2R_TIMEVNT1_Msk       (0x1UL << HRTIM_RSTx2R_TIMEVNT1_Pos)      /*!< 0x00001000 */
#define HRTIM_RSTx2R_TIMEVNT1             HRTIM_RSTx2R_TIMEVNT1_Msk     /*!< TIMEVNT1 */
#define HRTIM_RSTx2R_TIMEVNT2_Pos       (13U)
#define HRTIM_RSTx2R_TIMEVNT2_Msk       (0x1UL << HRTIM_RSTx2R_TIMEVNT2_Pos)      /*!< 0x00002000 */
#define HRTIM_RSTx2R_TIMEVNT2             HRTIM_RSTx2R_TIMEVNT2_Msk     /*!< TIMEVNT2 */
#define HRTIM_RSTx2R_TIMEVNT3_Pos       (14U)
#define HRTIM_RSTx2R_TIMEVNT3_Msk       (0x1UL << HRTIM_RSTx2R_TIMEVNT3_Pos)      /*!< 0x00004000 */
#define HRTIM_RSTx2R_TIMEVNT3             HRTIM_RSTx2R_TIMEVNT3_Msk     /*!< TIMEVNT3 */
#define HRTIM_RSTx2R_TIMEVNT4_Pos       (15U)
#define HRTIM_RSTx2R_TIMEVNT4_Msk       (0x1UL << HRTIM_RSTx2R_TIMEVNT4_Pos)      /*!< 0x00008000 */
#define HRTIM_RSTx2R_TIMEVNT4             HRTIM_RSTx2R_TIMEVNT4_Msk     /*!< TIMEVNT4 */
#define HRTIM_RSTx2R_TIMEVNT5_Pos       (16U)
#define HRTIM_RSTx2R_TIMEVNT5_Msk       (0x1UL << HRTIM_RSTx2R_TIMEVNT5_Pos)      /*!< 0x00010000 */
#define HRTIM_RSTx2R_TIMEVNT5             HRTIM_RSTx2R_TIMEVNT5_Msk     /*!< TIMEVNT5 */
#define HRTIM_RSTx2R_TIMEVNT6_Pos       (17U)
#define HRTIM_RSTx2R_TIMEVNT6_Msk       (0x1UL << HRTIM_RSTx2R_TIMEVNT6_Pos)      /*!< 0x00020000 */
#define HRTIM_RSTx2R_TIMEVNT6             HRTIM_RSTx2R_TIMEVNT6_Msk     /*!< TIMEVNT6 */
#define HRTIM_RSTx2R_TIMEVNT7_Pos       (18U)
#define HRTIM_RSTx2R_TIMEVNT7_Msk       (0x1UL << HRTIM_RSTx2R_TIMEVNT7_Pos)      /*!< 0x00040000 */
#define HRTIM_RSTx2R_TIMEVNT7             HRTIM_RSTx2R_TIMEVNT7_Msk     /*!< TIMEVNT7 */
#define HRTIM_RSTx2R_TIMEVNT8_Pos       (19U)
#define HRTIM_RSTx2R_TIMEVNT8_Msk       (0x1UL << HRTIM_RSTx2R_TIMEVNT8_Pos)      /*!< 0x00080000 */
#define HRTIM_RSTx2R_TIMEVNT8             HRTIM_RSTx2R_TIMEVNT8_Msk     /*!< TIMEVNT8 */
#define HRTIM_RSTx2R_TIMEVNT9_Pos       (20U)
#define HRTIM_RSTx2R_TIMEVNT9_Msk       (0x1UL << HRTIM_RSTx2R_TIMEVNT9_Pos)      /*!< 0x00100000 */
#define HRTIM_RSTx2R_TIMEVNT9             HRTIM_RSTx2R_TIMEVNT9_Msk     /*!< TIMEVNT9 */
#define HRTIM_RSTx2R_EXTVNT1_Pos        (21U)
#define HRTIM_RSTx2R_EXTVNT1_Msk        (0x1UL << HRTIM_RSTx2R_EXTVNT1_Pos)     /*!< 0x00200000 */
#define HRTIM_RSTx2R_EXTVNT1              HRTIM_RSTx2R_EXTVNT1_Msk      /*!< EXTVNT1 */
#define HRTIM_RSTx2R_EXTVNT2_Pos        (22U)
#define HRTIM_RSTx2R_EXTVNT2_Msk        (0x1UL << HRTIM_RSTx2R_EXTVNT2_Pos)     /*!< 0x00400000 */
#define HRTIM_RSTx2R_EXTVNT2              HRTIM_RSTx2R_EXTVNT2_Msk      /*!< EXTVNT2 */
#define HRTIM_RSTx2R_EXTVNT3_Pos        (23U)
#define HRTIM_RSTx2R_EXTVNT3_Msk        (0x1UL << HRTIM_RSTx2R_EXTVNT3_Pos)     /*!< 0x00800000 */
#define HRTIM_RSTx2R_EXTVNT3              HRTIM_RSTx2R_EXTVNT3_Msk      /*!< EXTVNT3 */
#define HRTIM_RSTx2R_EXTVNT4_Pos        (24U)
#define HRTIM_RSTx2R_EXTVNT4_Msk        (0x1UL << HRTIM_RSTx2R_EXTVNT4_Pos)     /*!< 0x01000000 */
#define HRTIM_RSTx2R_EXTVNT4              HRTIM_RSTx2R_EXTVNT4_Msk      /*!< EXTVNT4 */
#define HRTIM_RSTx2R_EXTVNT5_Pos        (25U)
#define HRTIM_RSTx2R_EXTVNT5_Msk        (0x1UL << HRTIM_RSTx2R_EXTVNT5_Pos)     /*!< 0x02000000 */
#define HRTIM_RSTx2R_EXTVNT5              HRTIM_RSTx2R_EXTVNT5_Msk      /*!< EXTVNT5 */
#define HRTIM_RSTx2R_EXTVNT6_Pos        (26U)
#define HRTIM_RSTx2R_EXTVNT6_Msk        (0x1UL << HRTIM_RSTx2R_EXTVNT6_Pos)     /*!< 0x04000000 */
#define HRTIM_RSTx2R_EXTVNT6              HRTIM_RSTx2R_EXTVNT6_Msk      /*!< EXTVNT6 */
#define HRTIM_RSTx2R_EXTVNT7_Pos        (27U)
#define HRTIM_RSTx2R_EXTVNT7_Msk        (0x1UL << HRTIM_RSTx2R_EXTVNT7_Pos)     /*!< 0x08000000 */
#define HRTIM_RSTx2R_EXTVNT7              HRTIM_RSTx2R_EXTVNT7_Msk      /*!< EXTVNT7 */
#define HRTIM_RSTx2R_EXTVNT8_Pos        (28U)
#define HRTIM_RSTx2R_EXTVNT8_Msk        (0x1UL << HRTIM_RSTx2R_EXTVNT8_Pos)     /*!< 0x10000000 */
#define HRTIM_RSTx2R_EXTVNT8              HRTIM_RSTx2R_EXTVNT8_Msk      /*!< EXTVNT8 */
#define HRTIM_RSTx2R_EXTVNT9_Pos        (29U)
#define HRTIM_RSTx2R_EXTVNT9_Msk        (0x1UL << HRTIM_RSTx2R_EXTVNT9_Pos)     /*!< 0x20000000 */
#define HRTIM_RSTx2R_EXTVNT9              HRTIM_RSTx2R_EXTVNT9_Msk      /*!< EXTVNT9 */
#define HRTIM_RSTx2R_EXTVNT10_Pos       (30U)
#define HRTIM_RSTx2R_EXTVNT10_Msk       (0x1UL << HRTIM_RSTx2R_EXTVNT10_Pos)      /*!< 0x40000000 */
#define HRTIM_RSTx2R_EXTVNT10             HRTIM_RSTx2R_EXTVNT10_Msk     /*!< EXTVNT10 */
#define HRTIM_RSTx2R_UPDATE_Pos         (31U)
#define HRTIM_RSTx2R_UPDATE_Msk         (0x1UL << HRTIM_RSTx2R_UPDATE_Pos)    /*!< 0x80000000 */
#define HRTIM_RSTx2R_UPDATE               HRTIM_RSTx2R_UPDATE_Msk       /*!< UPDATE */

/*************  Bit definition for HRTIM_EEFxR1 register  *************/
#define HRTIM_EEFxR1_EE1LTCH_Pos        (0U)
#define HRTIM_EEFxR1_EE1LTCH_Msk        (0x1UL << HRTIM_EEFxR1_EE1LTCH_Pos)     /*!< 0x00000001 */
#define HRTIM_EEFxR1_EE1LTCH              HRTIM_EEFxR1_EE1LTCH_Msk      /*!< EE1LTCH */
#define HRTIM_EEFxR1_EE1FLTR_Pos        (1U)
#define HRTIM_EEFxR1_EE1FLTR_Msk        (0xFUL << HRTIM_EEFxR1_EE1FLTR_Pos)     /*!< 0x0000001E */
#define HRTIM_EEFxR1_EE1FLTR              HRTIM_EEFxR1_EE1FLTR_Msk      /*!< EE1FLTR */
#define HRTIM_EEFxR1_EE1FLTR_0        (0x1UL << HRTIM_EEFxR1_EE1FLTR_Pos)      /*!< 0x00000002 */
#define HRTIM_EEFxR1_EE1FLTR_1        (0x2UL << HRTIM_EEFxR1_EE1FLTR_Pos)      /*!< 0x00000004 */
#define HRTIM_EEFxR1_EE1FLTR_2        (0x4UL << HRTIM_EEFxR1_EE1FLTR_Pos)      /*!< 0x00000008 */
#define HRTIM_EEFxR1_EE1FLTR_3        (0x8UL << HRTIM_EEFxR1_EE1FLTR_Pos)      /*!< 0x00000010 */
#define HRTIM_EEFxR1_EE2LTCH_Pos        (6U)
#define HRTIM_EEFxR1_EE2LTCH_Msk        (0x1UL << HRTIM_EEFxR1_EE2LTCH_Pos)     /*!< 0x00000040 */
#define HRTIM_EEFxR1_EE2LTCH              HRTIM_EEFxR1_EE2LTCH_Msk      /*!< EE2LTCH */
#define HRTIM_EEFxR1_EE2FLTR_Pos        (7U)
#define HRTIM_EEFxR1_EE2FLTR_Msk        (0xFUL << HRTIM_EEFxR1_EE2FLTR_Pos)     /*!< 0x00000780 */
#define HRTIM_EEFxR1_EE2FLTR              HRTIM_EEFxR1_EE2FLTR_Msk      /*!< EE2FLTR */
#define HRTIM_EEFxR1_EE2FLTR_0        (0x1UL << HRTIM_EEFxR1_EE2FLTR_Pos)      /*!< 0x00000080 */
#define HRTIM_EEFxR1_EE2FLTR_1        (0x2UL << HRTIM_EEFxR1_EE2FLTR_Pos)      /*!< 0x00000100 */
#define HRTIM_EEFxR1_EE2FLTR_2        (0x4UL << HRTIM_EEFxR1_EE2FLTR_Pos)      /*!< 0x00000200 */
#define HRTIM_EEFxR1_EE2FLTR_3        (0x8UL << HRTIM_EEFxR1_EE2FLTR_Pos)      /*!< 0x00000400 */
#define HRTIM_EEFxR1_EE3LTCH_Pos        (12U)
#define HRTIM_EEFxR1_EE3LTCH_Msk        (0x1UL << HRTIM_EEFxR1_EE3LTCH_Pos)     /*!< 0x00001000 */
#define HRTIM_EEFxR1_EE3LTCH              HRTIM_EEFxR1_EE3LTCH_Msk      /*!< EE3LTCH */
#define HRTIM_EEFxR1_EE3FLTR_Pos        (13U)
#define HRTIM_EEFxR1_EE3FLTR_Msk        (0xFUL << HRTIM_EEFxR1_EE3FLTR_Pos)     /*!< 0x0001E000 */
#define HRTIM_EEFxR1_EE3FLTR              HRTIM_EEFxR1_EE3FLTR_Msk      /*!< EE3FLTR */
#define HRTIM_EEFxR1_EE3FLTR_0        (0x1UL << HRTIM_EEFxR1_EE3FLTR_Pos)      /*!< 0x00002000 */
#define HRTIM_EEFxR1_EE3FLTR_1        (0x2UL << HRTIM_EEFxR1_EE3FLTR_Pos)      /*!< 0x00004000 */
#define HRTIM_EEFxR1_EE3FLTR_2        (0x4UL << HRTIM_EEFxR1_EE3FLTR_Pos)      /*!< 0x00008000 */
#define HRTIM_EEFxR1_EE3FLTR_3        (0x8UL << HRTIM_EEFxR1_EE3FLTR_Pos)      /*!< 0x00010000 */
#define HRTIM_EEFxR1_EE4LTCH_Pos        (18U)
#define HRTIM_EEFxR1_EE4LTCH_Msk        (0x1UL << HRTIM_EEFxR1_EE4LTCH_Pos)     /*!< 0x00040000 */
#define HRTIM_EEFxR1_EE4LTCH              HRTIM_EEFxR1_EE4LTCH_Msk      /*!< EE4LTCH */
#define HRTIM_EEFxR1_EE4FLTR_Pos        (19U)
#define HRTIM_EEFxR1_EE4FLTR_Msk        (0xFUL << HRTIM_EEFxR1_EE4FLTR_Pos)     /*!< 0x00780000 */
#define HRTIM_EEFxR1_EE4FLTR              HRTIM_EEFxR1_EE4FLTR_Msk      /*!< EE4FLTR */
#define HRTIM_EEFxR1_EE4FLTR_0        (0x1UL << HRTIM_EEFxR1_EE4FLTR_Pos)      /*!< 0x00080000 */
#define HRTIM_EEFxR1_EE4FLTR_1        (0x2UL << HRTIM_EEFxR1_EE4FLTR_Pos)      /*!< 0x00100000 */
#define HRTIM_EEFxR1_EE4FLTR_2        (0x4UL << HRTIM_EEFxR1_EE4FLTR_Pos)      /*!< 0x00200000 */
#define HRTIM_EEFxR1_EE4FLTR_3        (0x8UL << HRTIM_EEFxR1_EE4FLTR_Pos)      /*!< 0x00400000 */
#define HRTIM_EEFxR1_EE5LTCH_Pos        (24U)
#define HRTIM_EEFxR1_EE5LTCH_Msk        (0x1UL << HRTIM_EEFxR1_EE5LTCH_Pos)     /*!< 0x01000000 */
#define HRTIM_EEFxR1_EE5LTCH              HRTIM_EEFxR1_EE5LTCH_Msk      /*!< EE5LTCH */
#define HRTIM_EEFxR1_EE5FLTR_Pos        (25U)
#define HRTIM_EEFxR1_EE5FLTR_Msk        (0xFUL << HRTIM_EEFxR1_EE5FLTR_Pos)     /*!< 0x1E000000 */
#define HRTIM_EEFxR1_EE5FLTR              HRTIM_EEFxR1_EE5FLTR_Msk      /*!< EE5FLTR */
#define HRTIM_EEFxR1_EE5FLTR_0        (0x1UL << HRTIM_EEFxR1_EE5FLTR_Pos)      /*!< 0x02000000 */
#define HRTIM_EEFxR1_EE5FLTR_1        (0x2UL << HRTIM_EEFxR1_EE5FLTR_Pos)      /*!< 0x04000000 */
#define HRTIM_EEFxR1_EE5FLTR_2        (0x4UL << HRTIM_EEFxR1_EE5FLTR_Pos)      /*!< 0x08000000 */
#define HRTIM_EEFxR1_EE5FLTR_3        (0x8UL << HRTIM_EEFxR1_EE5FLTR_Pos)      /*!< 0x10000000 */

/*************  Bit definition for HRTIM_EEFxR2 register  *************/
#define HRTIM_EEFxR2_EE6LTCH_Pos        (0U)
#define HRTIM_EEFxR2_EE6LTCH_Msk        (0x1UL << HRTIM_EEFxR2_EE6LTCH_Pos)     /*!< 0x00000001 */
#define HRTIM_EEFxR2_EE6LTCH              HRTIM_EEFxR2_EE6LTCH_Msk      /*!< EE6LTCH */
#define HRTIM_EEFxR2_EE6FLTR_Pos        (1U)
#define HRTIM_EEFxR2_EE6FLTR_Msk        (0xFUL << HRTIM_EEFxR2_EE6FLTR_Pos)     /*!< 0x0000001E */
#define HRTIM_EEFxR2_EE6FLTR              HRTIM_EEFxR2_EE6FLTR_Msk      /*!< EE6FLTR */
#define HRTIM_EEFxR2_EE6FLTR_0        (0x1UL << HRTIM_EEFxR2_EE6FLTR_Pos)      /*!< 0x00000002 */
#define HRTIM_EEFxR2_EE6FLTR_1        (0x2UL << HRTIM_EEFxR2_EE6FLTR_Pos)      /*!< 0x00000004 */
#define HRTIM_EEFxR2_EE6FLTR_2        (0x4UL << HRTIM_EEFxR2_EE6FLTR_Pos)      /*!< 0x00000008 */
#define HRTIM_EEFxR2_EE6FLTR_3        (0x8UL << HRTIM_EEFxR2_EE6FLTR_Pos)      /*!< 0x00000010 */
#define HRTIM_EEFxR2_EE7LTCH_Pos        (6U)
#define HRTIM_EEFxR2_EE7LTCH_Msk        (0x1UL << HRTIM_EEFxR2_EE7LTCH_Pos)     /*!< 0x00000040 */
#define HRTIM_EEFxR2_EE7LTCH              HRTIM_EEFxR2_EE7LTCH_Msk      /*!< EE7LTCH */
#define HRTIM_EEFxR2_EE7FLTR_Pos        (7U)
#define HRTIM_EEFxR2_EE7FLTR_Msk        (0xFUL << HRTIM_EEFxR2_EE7FLTR_Pos)     /*!< 0x00000780 */
#define HRTIM_EEFxR2_EE7FLTR              HRTIM_EEFxR2_EE7FLTR_Msk      /*!< EE7FLTR */
#define HRTIM_EEFxR2_EE7FLTR_0        (0x1UL << HRTIM_EEFxR2_EE7FLTR_Pos)      /*!< 0x00000080 */
#define HRTIM_EEFxR2_EE7FLTR_1        (0x2UL << HRTIM_EEFxR2_EE7FLTR_Pos)      /*!< 0x00000100 */
#define HRTIM_EEFxR2_EE7FLTR_2        (0x4UL << HRTIM_EEFxR2_EE7FLTR_Pos)      /*!< 0x00000200 */
#define HRTIM_EEFxR2_EE7FLTR_3        (0x8UL << HRTIM_EEFxR2_EE7FLTR_Pos)      /*!< 0x00000400 */
#define HRTIM_EEFxR2_EE8LTCH_Pos        (12U)
#define HRTIM_EEFxR2_EE8LTCH_Msk        (0x1UL << HRTIM_EEFxR2_EE8LTCH_Pos)     /*!< 0x00001000 */
#define HRTIM_EEFxR2_EE8LTCH              HRTIM_EEFxR2_EE8LTCH_Msk      /*!< EE8LTCH */
#define HRTIM_EEFxR2_EE8FLTR_Pos        (13U)
#define HRTIM_EEFxR2_EE8FLTR_Msk        (0xFUL << HRTIM_EEFxR2_EE8FLTR_Pos)     /*!< 0x0001E000 */
#define HRTIM_EEFxR2_EE8FLTR              HRTIM_EEFxR2_EE8FLTR_Msk      /*!< EE8FLTR */
#define HRTIM_EEFxR2_EE8FLTR_0        (0x1UL << HRTIM_EEFxR2_EE8FLTR_Pos)      /*!< 0x00002000 */
#define HRTIM_EEFxR2_EE8FLTR_1        (0x2UL << HRTIM_EEFxR2_EE8FLTR_Pos)      /*!< 0x00004000 */
#define HRTIM_EEFxR2_EE8FLTR_2        (0x4UL << HRTIM_EEFxR2_EE8FLTR_Pos)      /*!< 0x00008000 */
#define HRTIM_EEFxR2_EE8FLTR_3        (0x8UL << HRTIM_EEFxR2_EE8FLTR_Pos)      /*!< 0x00010000 */
#define HRTIM_EEFxR2_EE9LTCH_Pos        (18U)
#define HRTIM_EEFxR2_EE9LTCH_Msk        (0x1UL << HRTIM_EEFxR2_EE9LTCH_Pos)     /*!< 0x00040000 */
#define HRTIM_EEFxR2_EE9LTCH              HRTIM_EEFxR2_EE9LTCH_Msk      /*!< EE9LTCH */
#define HRTIM_EEFxR2_EE9FLTR_Pos        (19U)
#define HRTIM_EEFxR2_EE9FLTR_Msk        (0xFUL << HRTIM_EEFxR2_EE9FLTR_Pos)     /*!< 0x00780000 */
#define HRTIM_EEFxR2_EE9FLTR              HRTIM_EEFxR2_EE9FLTR_Msk      /*!< EE9FLTR */
#define HRTIM_EEFxR2_EE9FLTR_0        (0x1UL << HRTIM_EEFxR2_EE9FLTR_Pos)      /*!< 0x00080000 */
#define HRTIM_EEFxR2_EE9FLTR_1        (0x2UL << HRTIM_EEFxR2_EE9FLTR_Pos)      /*!< 0x00100000 */
#define HRTIM_EEFxR2_EE9FLTR_2        (0x4UL << HRTIM_EEFxR2_EE9FLTR_Pos)      /*!< 0x00200000 */
#define HRTIM_EEFxR2_EE9FLTR_3        (0x8UL << HRTIM_EEFxR2_EE9FLTR_Pos)      /*!< 0x00400000 */
#define HRTIM_EEFxR2_EE10LTCH_Pos       (24U)
#define HRTIM_EEFxR2_EE10LTCH_Msk       (0x1UL << HRTIM_EEFxR2_EE10LTCH_Pos)      /*!< 0x01000000 */
#define HRTIM_EEFxR2_EE10LTCH             HRTIM_EEFxR2_EE10LTCH_Msk     /*!< EE10LTCH */
#define HRTIM_EEFxR2_EE10FLTR_Pos       (25U)
#define HRTIM_EEFxR2_EE10FLTR_Msk       (0xFUL << HRTIM_EEFxR2_EE10FLTR_Pos)      /*!< 0x1E000000 */
#define HRTIM_EEFxR2_EE10FLTR             HRTIM_EEFxR2_EE10FLTR_Msk     /*!< EE10FLTR */
#define HRTIM_EEFxR2_EE10FLTR_0       (0x1UL << HRTIM_EEFxR2_EE10FLTR_Pos)       /*!< 0x02000000 */
#define HRTIM_EEFxR2_EE10FLTR_1       (0x2UL << HRTIM_EEFxR2_EE10FLTR_Pos)       /*!< 0x04000000 */
#define HRTIM_EEFxR2_EE10FLTR_2       (0x4UL << HRTIM_EEFxR2_EE10FLTR_Pos)       /*!< 0x08000000 */
#define HRTIM_EEFxR2_EE10FLTR_3       (0x8UL << HRTIM_EEFxR2_EE10FLTR_Pos)       /*!< 0x10000000 */

/*************  Bit definition for HRTIM_RSTxR register  **************/
#define HRTIM_RSTxR_TIMFCMP1_Pos        (0U)
#define HRTIM_RSTxR_TIMFCMP1_Msk        (0x1UL << HRTIM_RSTxR_TIMFCMP1_Pos)     /*!< 0x00000001 */
#define HRTIM_RSTxR_TIMFCMP1              HRTIM_RSTxR_TIMFCMP1_Msk      /*!< TIMFCMP1 */
#define HRTIM_RSTxR_UPDATE_Pos          (1U)
#define HRTIM_RSTxR_UPDATE_Msk          (0x1UL << HRTIM_RSTxR_UPDATE_Pos)   /*!< 0x00000002 */
#define HRTIM_RSTxR_UPDATE                HRTIM_RSTxR_UPDATE_Msk        /*!< UPDATE */
#define HRTIM_RSTxR_CMP2_Pos            (2U)
#define HRTIM_RSTxR_CMP2_Msk            (0x1UL << HRTIM_RSTxR_CMP2_Pos) /*!< 0x00000004 */
#define HRTIM_RSTxR_CMP2                  HRTIM_RSTxR_CMP2_Msk          /*!< CMP2 */
#define HRTIM_RSTxR_CMP4_Pos            (3U)
#define HRTIM_RSTxR_CMP4_Msk            (0x1UL << HRTIM_RSTxR_CMP4_Pos) /*!< 0x00000008 */
#define HRTIM_RSTxR_CMP4                  HRTIM_RSTxR_CMP4_Msk          /*!< CMP4 */
#define HRTIM_RSTxR_MSTPER_Pos          (4U)
#define HRTIM_RSTxR_MSTPER_Msk          (0x1UL << HRTIM_RSTxR_MSTPER_Pos)   /*!< 0x00000010 */
#define HRTIM_RSTxR_MSTPER                HRTIM_RSTxR_MSTPER_Msk        /*!< MSTPER */
#define HRTIM_RSTxR_MSTCMP1_Pos         (5U)
#define HRTIM_RSTxR_MSTCMP1_Msk         (0x1UL << HRTIM_RSTxR_MSTCMP1_Pos)    /*!< 0x00000020 */
#define HRTIM_RSTxR_MSTCMP1               HRTIM_RSTxR_MSTCMP1_Msk       /*!< MSTCMP1 */
#define HRTIM_RSTxR_MSTCMP2_Pos         (6U)
#define HRTIM_RSTxR_MSTCMP2_Msk         (0x1UL << HRTIM_RSTxR_MSTCMP2_Pos)    /*!< 0x00000040 */
#define HRTIM_RSTxR_MSTCMP2               HRTIM_RSTxR_MSTCMP2_Msk       /*!< MSTCMP2 */
#define HRTIM_RSTxR_MSTCMP3_Pos         (7U)
#define HRTIM_RSTxR_MSTCMP3_Msk         (0x1UL << HRTIM_RSTxR_MSTCMP3_Pos)    /*!< 0x00000080 */
#define HRTIM_RSTxR_MSTCMP3               HRTIM_RSTxR_MSTCMP3_Msk       /*!< MSTCMP3 */
#define HRTIM_RSTxR_MSTCMP4_Pos         (8U)
#define HRTIM_RSTxR_MSTCMP4_Msk         (0x1UL << HRTIM_RSTxR_MSTCMP4_Pos)    /*!< 0x00000100 */
#define HRTIM_RSTxR_MSTCMP4               HRTIM_RSTxR_MSTCMP4_Msk       /*!< MSTCMP4 */
#define HRTIM_RSTxR_EXTEVNT1_Pos        (9U)
#define HRTIM_RSTxR_EXTEVNT1_Msk        (0x1UL << HRTIM_RSTxR_EXTEVNT1_Pos)     /*!< 0x00000200 */
#define HRTIM_RSTxR_EXTEVNT1              HRTIM_RSTxR_EXTEVNT1_Msk      /*!< EXTEVNT1 */
#define HRTIM_RSTxR_EXTEVNT2_Pos        (10U)
#define HRTIM_RSTxR_EXTEVNT2_Msk        (0x1UL << HRTIM_RSTxR_EXTEVNT2_Pos)     /*!< 0x00000400 */
#define HRTIM_RSTxR_EXTEVNT2              HRTIM_RSTxR_EXTEVNT2_Msk      /*!< EXTEVNT2 */
#define HRTIM_RSTxR_EXTEVNT3_Pos        (11U)
#define HRTIM_RSTxR_EXTEVNT3_Msk        (0x1UL << HRTIM_RSTxR_EXTEVNT3_Pos)     /*!< 0x00000800 */
#define HRTIM_RSTxR_EXTEVNT3              HRTIM_RSTxR_EXTEVNT3_Msk      /*!< EXTEVNT3 */
#define HRTIM_RSTxR_EXTEVNT4_Pos        (12U)
#define HRTIM_RSTxR_EXTEVNT4_Msk        (0x1UL << HRTIM_RSTxR_EXTEVNT4_Pos)     /*!< 0x00001000 */
#define HRTIM_RSTxR_EXTEVNT4              HRTIM_RSTxR_EXTEVNT4_Msk      /*!< EXTEVNT4 */
#define HRTIM_RSTxR_EXTEVNT5_Pos        (13U)
#define HRTIM_RSTxR_EXTEVNT5_Msk        (0x1UL << HRTIM_RSTxR_EXTEVNT5_Pos)     /*!< 0x00002000 */
#define HRTIM_RSTxR_EXTEVNT5              HRTIM_RSTxR_EXTEVNT5_Msk      /*!< EXTEVNT5 */
#define HRTIM_RSTxR_EXTEVNT6_Pos        (14U)
#define HRTIM_RSTxR_EXTEVNT6_Msk        (0x1UL << HRTIM_RSTxR_EXTEVNT6_Pos)     /*!< 0x00004000 */
#define HRTIM_RSTxR_EXTEVNT6              HRTIM_RSTxR_EXTEVNT6_Msk      /*!< EXTEVNT6 */
#define HRTIM_RSTxR_EXTEVNT7_Pos        (15U)
#define HRTIM_RSTxR_EXTEVNT7_Msk        (0x1UL << HRTIM_RSTxR_EXTEVNT7_Pos)     /*!< 0x00008000 */
#define HRTIM_RSTxR_EXTEVNT7              HRTIM_RSTxR_EXTEVNT7_Msk      /*!< EXTEVNT7 */
#define HRTIM_RSTxR_EXTEVNT8_Pos        (16U)
#define HRTIM_RSTxR_EXTEVNT8_Msk        (0x1UL << HRTIM_RSTxR_EXTEVNT8_Pos)     /*!< 0x00010000 */
#define HRTIM_RSTxR_EXTEVNT8              HRTIM_RSTxR_EXTEVNT8_Msk      /*!< EXTEVNT8 */
#define HRTIM_RSTxR_EXTEVNT9_Pos        (17U)
#define HRTIM_RSTxR_EXTEVNT9_Msk        (0x1UL << HRTIM_RSTxR_EXTEVNT9_Pos)     /*!< 0x00020000 */
#define HRTIM_RSTxR_EXTEVNT9              HRTIM_RSTxR_EXTEVNT9_Msk      /*!< EXTEVNT9 */
#define HRTIM_RSTxR_EXTEVNT10_Pos       (18U)
#define HRTIM_RSTxR_EXTEVNT10_Msk       (0x1UL << HRTIM_RSTxR_EXTEVNT10_Pos)      /*!< 0x00040000 */
#define HRTIM_RSTxR_EXTEVNT10             HRTIM_RSTxR_EXTEVNT10_Msk     /*!< EXTEVNT10 */
#define HRTIM_RSTxR_TIMBCMP1_Pos        (19U)
#define HRTIM_RSTxR_TIMBCMP1_Msk        (0x1UL << HRTIM_RSTxR_TIMBCMP1_Pos)     /*!< 0x00080000 */
#define HRTIM_RSTxR_TIMBCMP1              HRTIM_RSTxR_TIMBCMP1_Msk      /*!< TIMBCMP1 */
#define HRTIM_RSTxR_TIMBCMP2_Pos        (20U)
#define HRTIM_RSTxR_TIMBCMP2_Msk        (0x1UL << HRTIM_RSTxR_TIMBCMP2_Pos)     /*!< 0x00100000 */
#define HRTIM_RSTxR_TIMBCMP2              HRTIM_RSTxR_TIMBCMP2_Msk      /*!< TIMBCMP2 */
#define HRTIM_RSTxR_TIMBCMP4_Pos        (21U)
#define HRTIM_RSTxR_TIMBCMP4_Msk        (0x1UL << HRTIM_RSTxR_TIMBCMP4_Pos)     /*!< 0x00200000 */
#define HRTIM_RSTxR_TIMBCMP4              HRTIM_RSTxR_TIMBCMP4_Msk      /*!< TIMBCMP4 */
#define HRTIM_RSTxR_TIMCCMP1_Pos        (22U)
#define HRTIM_RSTxR_TIMCCMP1_Msk        (0x1UL << HRTIM_RSTxR_TIMCCMP1_Pos)     /*!< 0x00400000 */
#define HRTIM_RSTxR_TIMCCMP1              HRTIM_RSTxR_TIMCCMP1_Msk      /*!< TIMCCMP1 */
#define HRTIM_RSTxR_TIMCCMP2_Pos        (23U)
#define HRTIM_RSTxR_TIMCCMP2_Msk        (0x1UL << HRTIM_RSTxR_TIMCCMP2_Pos)     /*!< 0x00800000 */
#define HRTIM_RSTxR_TIMCCMP2              HRTIM_RSTxR_TIMCCMP2_Msk      /*!< TIMCCMP2 */
#define HRTIM_RSTxR_TIMCCMP4_Pos        (24U)
#define HRTIM_RSTxR_TIMCCMP4_Msk        (0x1UL << HRTIM_RSTxR_TIMCCMP4_Pos)     /*!< 0x01000000 */
#define HRTIM_RSTxR_TIMCCMP4              HRTIM_RSTxR_TIMCCMP4_Msk      /*!< TIMCCMP4 */
#define HRTIM_RSTxR_TIMDCMP1_Pos        (25U)
#define HRTIM_RSTxR_TIMDCMP1_Msk        (0x1UL << HRTIM_RSTxR_TIMDCMP1_Pos)     /*!< 0x02000000 */
#define HRTIM_RSTxR_TIMDCMP1              HRTIM_RSTxR_TIMDCMP1_Msk      /*!< TIMDCMP1 */
#define HRTIM_RSTxR_TIMDCMP2_Pos        (26U)
#define HRTIM_RSTxR_TIMDCMP2_Msk        (0x1UL << HRTIM_RSTxR_TIMDCMP2_Pos)     /*!< 0x04000000 */
#define HRTIM_RSTxR_TIMDCMP2              HRTIM_RSTxR_TIMDCMP2_Msk      /*!< TIMDCMP2 */
#define HRTIM_RSTxR_TIMDCMP4_Pos        (27U)
#define HRTIM_RSTxR_TIMDCMP4_Msk        (0x1UL << HRTIM_RSTxR_TIMDCMP4_Pos)     /*!< 0x08000000 */
#define HRTIM_RSTxR_TIMDCMP4              HRTIM_RSTxR_TIMDCMP4_Msk      /*!< TIMDCMP4 */
#define HRTIM_RSTxR_TIMECMP1_Pos        (28U)
#define HRTIM_RSTxR_TIMECMP1_Msk        (0x1UL << HRTIM_RSTxR_TIMECMP1_Pos)     /*!< 0x10000000 */
#define HRTIM_RSTxR_TIMECMP1              HRTIM_RSTxR_TIMECMP1_Msk      /*!< TIMECMP1 */
#define HRTIM_RSTxR_TIMECMP2_Pos        (29U)
#define HRTIM_RSTxR_TIMECMP2_Msk        (0x1UL << HRTIM_RSTxR_TIMECMP2_Pos)     /*!< 0x20000000 */
#define HRTIM_RSTxR_TIMECMP2              HRTIM_RSTxR_TIMECMP2_Msk      /*!< TIMECMP2 */
#define HRTIM_RSTxR_TIMECMP4_Pos        (30U)
#define HRTIM_RSTxR_TIMECMP4_Msk        (0x1UL << HRTIM_RSTxR_TIMECMP4_Pos)     /*!< 0x40000000 */
#define HRTIM_RSTxR_TIMECMP4              HRTIM_RSTxR_TIMECMP4_Msk      /*!< TIMECMP4 */
#define HRTIM_RSTxR_TIMFCMP2_Pos        (31U)
#define HRTIM_RSTxR_TIMFCMP2_Msk        (0x1UL << HRTIM_RSTxR_TIMFCMP2_Pos)     /*!< 0x80000000 */
#define HRTIM_RSTxR_TIMFCMP2              HRTIM_RSTxR_TIMFCMP2_Msk      /*!< TIMFCMP2 */

/*************  Bit definition for HRTIM_CHPxR register  **************/
#define HRTIM_CHPxR_CARFRQ_Pos          (0U)
#define HRTIM_CHPxR_CARFRQ_Msk          (0xFUL << HRTIM_CHPxR_CARFRQ_Pos)   /*!< 0x0000000F */
#define HRTIM_CHPxR_CARFRQ                HRTIM_CHPxR_CARFRQ_Msk        /*!< CARFRQ */
#define HRTIM_CHPxR_CARFRQ_0          (0x1UL << HRTIM_CHPxR_CARFRQ_Pos)    /*!< 0x00000001 */
#define HRTIM_CHPxR_CARFRQ_1          (0x2UL << HRTIM_CHPxR_CARFRQ_Pos)    /*!< 0x00000002 */
#define HRTIM_CHPxR_CARFRQ_2          (0x4UL << HRTIM_CHPxR_CARFRQ_Pos)    /*!< 0x00000004 */
#define HRTIM_CHPxR_CARFRQ_3          (0x8UL << HRTIM_CHPxR_CARFRQ_Pos)    /*!< 0x00000008 */
#define HRTIM_CHPxR_CARDTY_Pos          (4U)
#define HRTIM_CHPxR_CARDTY_Msk          (0x7UL << HRTIM_CHPxR_CARDTY_Pos)   /*!< 0x00000070 */
#define HRTIM_CHPxR_CARDTY                HRTIM_CHPxR_CARDTY_Msk        /*!< CARDTY */
#define HRTIM_CHPxR_CARDTY_0          (0x1UL << HRTIM_CHPxR_CARDTY_Pos)    /*!< 0x00000010 */
#define HRTIM_CHPxR_CARDTY_1          (0x2UL << HRTIM_CHPxR_CARDTY_Pos)    /*!< 0x00000020 */
#define HRTIM_CHPxR_CARDTY_2          (0x4UL << HRTIM_CHPxR_CARDTY_Pos)    /*!< 0x00000040 */
#define HRTIM_CHPxR_STRPW_Pos           (7U)
#define HRTIM_CHPxR_STRPW_Msk           (0xFUL << HRTIM_CHPxR_STRPW_Pos)  /*!< 0x00000780 */
#define HRTIM_CHPxR_STRPW                 HRTIM_CHPxR_STRPW_Msk         /*!< STRPW */
#define HRTIM_CHPxR_STRPW_0           (0x1UL << HRTIM_CHPxR_STRPW_Pos)   /*!< 0x00000080 */
#define HRTIM_CHPxR_STRPW_1           (0x2UL << HRTIM_CHPxR_STRPW_Pos)   /*!< 0x00000100 */
#define HRTIM_CHPxR_STRPW_2           (0x4UL << HRTIM_CHPxR_STRPW_Pos)   /*!< 0x00000200 */
#define HRTIM_CHPxR_STRPW_3           (0x8UL << HRTIM_CHPxR_STRPW_Pos)   /*!< 0x00000400 */

/************  Bit definition for HRTIM_CPT1xCR register  *************/
#define HRTIM_CPT1xCR_SWCPT_Pos         (0U)
#define HRTIM_CPT1xCR_SWCPT_Msk         (0x1UL << HRTIM_CPT1xCR_SWCPT_Pos)    /*!< 0x00000001 */
#define HRTIM_CPT1xCR_SWCPT               HRTIM_CPT1xCR_SWCPT_Msk       /*!< SWCPT */
#define HRTIM_CPT1xCR_UPDCPT_Pos        (1U)
#define HRTIM_CPT1xCR_UPDCPT_Msk        (0x1UL << HRTIM_CPT1xCR_UPDCPT_Pos)     /*!< 0x00000002 */
#define HRTIM_CPT1xCR_UPDCPT              HRTIM_CPT1xCR_UPDCPT_Msk      /*!< UPDCPT */
#define HRTIM_CPT1xCR_EXEV1CPT_Pos      (2U)
#define HRTIM_CPT1xCR_EXEV1CPT_Msk      (0x1UL << HRTIM_CPT1xCR_EXEV1CPT_Pos)       /*!< 0x00000004 */
#define HRTIM_CPT1xCR_EXEV1CPT            HRTIM_CPT1xCR_EXEV1CPT_Msk    /*!< EXEV1CPT */
#define HRTIM_CPT1xCR_EXEV2CPT_Pos      (3U)
#define HRTIM_CPT1xCR_EXEV2CPT_Msk      (0x1UL << HRTIM_CPT1xCR_EXEV2CPT_Pos)       /*!< 0x00000008 */
#define HRTIM_CPT1xCR_EXEV2CPT            HRTIM_CPT1xCR_EXEV2CPT_Msk    /*!< EXEV2CPT */
#define HRTIM_CPT1xCR_EXEV3CPT_Pos      (4U)
#define HRTIM_CPT1xCR_EXEV3CPT_Msk      (0x1UL << HRTIM_CPT1xCR_EXEV3CPT_Pos)       /*!< 0x00000010 */
#define HRTIM_CPT1xCR_EXEV3CPT            HRTIM_CPT1xCR_EXEV3CPT_Msk    /*!< EXEV3CPT */
#define HRTIM_CPT1xCR_EXEV4CPT_Pos      (5U)
#define HRTIM_CPT1xCR_EXEV4CPT_Msk      (0x1UL << HRTIM_CPT1xCR_EXEV4CPT_Pos)       /*!< 0x00000020 */
#define HRTIM_CPT1xCR_EXEV4CPT            HRTIM_CPT1xCR_EXEV4CPT_Msk    /*!< EXEV4CPT */
#define HRTIM_CPT1xCR_EXEV5CPT_Pos      (6U)
#define HRTIM_CPT1xCR_EXEV5CPT_Msk      (0x1UL << HRTIM_CPT1xCR_EXEV5CPT_Pos)       /*!< 0x00000040 */
#define HRTIM_CPT1xCR_EXEV5CPT            HRTIM_CPT1xCR_EXEV5CPT_Msk    /*!< EXEV5CPT */
#define HRTIM_CPT1xCR_EXEV6CPT_Pos      (7U)
#define HRTIM_CPT1xCR_EXEV6CPT_Msk      (0x1UL << HRTIM_CPT1xCR_EXEV6CPT_Pos)       /*!< 0x00000080 */
#define HRTIM_CPT1xCR_EXEV6CPT            HRTIM_CPT1xCR_EXEV6CPT_Msk    /*!< EXEV6CPT */
#define HRTIM_CPT1xCR_EXEV7CPT_Pos      (8U)
#define HRTIM_CPT1xCR_EXEV7CPT_Msk      (0x1UL << HRTIM_CPT1xCR_EXEV7CPT_Pos)       /*!< 0x00000100 */
#define HRTIM_CPT1xCR_EXEV7CPT            HRTIM_CPT1xCR_EXEV7CPT_Msk    /*!< EXEV7CPT */
#define HRTIM_CPT1xCR_EXEV8CPT_Pos      (9U)
#define HRTIM_CPT1xCR_EXEV8CPT_Msk      (0x1UL << HRTIM_CPT1xCR_EXEV8CPT_Pos)       /*!< 0x00000200 */
#define HRTIM_CPT1xCR_EXEV8CPT            HRTIM_CPT1xCR_EXEV8CPT_Msk    /*!< EXEV8CPT */
#define HRTIM_CPT1xCR_EXEV9CPT_Pos      (10U)
#define HRTIM_CPT1xCR_EXEV9CPT_Msk      (0x1UL << HRTIM_CPT1xCR_EXEV9CPT_Pos)       /*!< 0x00000400 */
#define HRTIM_CPT1xCR_EXEV9CPT            HRTIM_CPT1xCR_EXEV9CPT_Msk    /*!< EXEV9CPT */
#define HRTIM_CPT1xCR_EXEV10CPT_Pos     (11U)
#define HRTIM_CPT1xCR_EXEV10CPT_Msk     (0x1UL << HRTIM_CPT1xCR_EXEV10CPT_Pos)        /*!< 0x00000800 */
#define HRTIM_CPT1xCR_EXEV10CPT           HRTIM_CPT1xCR_EXEV10CPT_Msk   /*!< EXEV10CPT */
#define HRTIM_CPT1xCR_TA1SET_Pos        (12U)
#define HRTIM_CPT1xCR_TA1SET_Msk        (0x1UL << HRTIM_CPT1xCR_TA1SET_Pos)     /*!< 0x00001000 */
#define HRTIM_CPT1xCR_TA1SET              HRTIM_CPT1xCR_TA1SET_Msk      /*!< TA1SET */
#define HRTIM_CPT1xCR_TA1RST_Pos        (13U)
#define HRTIM_CPT1xCR_TA1RST_Msk        (0x1UL << HRTIM_CPT1xCR_TA1RST_Pos)     /*!< 0x00002000 */
#define HRTIM_CPT1xCR_TA1RST              HRTIM_CPT1xCR_TA1RST_Msk      /*!< TA1RST */
#define HRTIM_CPT1xCR_TIMACMP1_Pos      (14U)
#define HRTIM_CPT1xCR_TIMACMP1_Msk      (0x1UL << HRTIM_CPT1xCR_TIMACMP1_Pos)       /*!< 0x00004000 */
#define HRTIM_CPT1xCR_TIMACMP1            HRTIM_CPT1xCR_TIMACMP1_Msk    /*!< TIMACMP1 */
#define HRTIM_CPT1xCR_TIMACMP2_Pos      (15U)
#define HRTIM_CPT1xCR_TIMACMP2_Msk      (0x1UL << HRTIM_CPT1xCR_TIMACMP2_Pos)       /*!< 0x00008000 */
#define HRTIM_CPT1xCR_TIMACMP2            HRTIM_CPT1xCR_TIMACMP2_Msk    /*!< TIMACMP2 */
#define HRTIM_CPT1xCR_TB1SET_Pos        (16U)
#define HRTIM_CPT1xCR_TB1SET_Msk        (0x1UL << HRTIM_CPT1xCR_TB1SET_Pos)     /*!< 0x00010000 */
#define HRTIM_CPT1xCR_TB1SET              HRTIM_CPT1xCR_TB1SET_Msk      /*!< TB1SET */
#define HRTIM_CPT1xCR_TB1RST_Pos        (17U)
#define HRTIM_CPT1xCR_TB1RST_Msk        (0x1UL << HRTIM_CPT1xCR_TB1RST_Pos)     /*!< 0x00020000 */
#define HRTIM_CPT1xCR_TB1RST              HRTIM_CPT1xCR_TB1RST_Msk      /*!< TB1RST */
#define HRTIM_CPT1xCR_TIMBCMP1_Pos      (18U)
#define HRTIM_CPT1xCR_TIMBCMP1_Msk      (0x1UL << HRTIM_CPT1xCR_TIMBCMP1_Pos)       /*!< 0x00040000 */
#define HRTIM_CPT1xCR_TIMBCMP1            HRTIM_CPT1xCR_TIMBCMP1_Msk    /*!< TIMBCMP1 */
#define HRTIM_CPT1xCR_TIMBCMP2_Pos      (19U)
#define HRTIM_CPT1xCR_TIMBCMP2_Msk      (0x1UL << HRTIM_CPT1xCR_TIMBCMP2_Pos)       /*!< 0x00080000 */
#define HRTIM_CPT1xCR_TIMBCMP2            HRTIM_CPT1xCR_TIMBCMP2_Msk    /*!< TIMBCMP2 */
#define HRTIM_CPT1xCR_TC1SET_Pos        (20U)
#define HRTIM_CPT1xCR_TC1SET_Msk        (0x1UL << HRTIM_CPT1xCR_TC1SET_Pos)     /*!< 0x00100000 */
#define HRTIM_CPT1xCR_TC1SET              HRTIM_CPT1xCR_TC1SET_Msk      /*!< TC1SET */
#define HRTIM_CPT1xCR_TC1RST_Pos        (21U)
#define HRTIM_CPT1xCR_TC1RST_Msk        (0x1UL << HRTIM_CPT1xCR_TC1RST_Pos)     /*!< 0x00200000 */
#define HRTIM_CPT1xCR_TC1RST              HRTIM_CPT1xCR_TC1RST_Msk      /*!< TC1RST */
#define HRTIM_CPT1xCR_TIMCCMP1_Pos      (22U)
#define HRTIM_CPT1xCR_TIMCCMP1_Msk      (0x1UL << HRTIM_CPT1xCR_TIMCCMP1_Pos)       /*!< 0x00400000 */
#define HRTIM_CPT1xCR_TIMCCMP1            HRTIM_CPT1xCR_TIMCCMP1_Msk    /*!< TIMCCMP1 */
#define HRTIM_CPT1xCR_TIMCCMP2_Pos      (23U)
#define HRTIM_CPT1xCR_TIMCCMP2_Msk      (0x1UL << HRTIM_CPT1xCR_TIMCCMP2_Pos)       /*!< 0x00800000 */
#define HRTIM_CPT1xCR_TIMCCMP2            HRTIM_CPT1xCR_TIMCCMP2_Msk    /*!< TIMCCMP2 */
#define HRTIM_CPT1xCR_TD1SET_Pos        (24U)
#define HRTIM_CPT1xCR_TD1SET_Msk        (0x1UL << HRTIM_CPT1xCR_TD1SET_Pos)     /*!< 0x01000000 */
#define HRTIM_CPT1xCR_TD1SET              HRTIM_CPT1xCR_TD1SET_Msk      /*!< TD1SET */
#define HRTIM_CPT1xCR_TD1RST_Pos        (25U)
#define HRTIM_CPT1xCR_TD1RST_Msk        (0x1UL << HRTIM_CPT1xCR_TD1RST_Pos)     /*!< 0x02000000 */
#define HRTIM_CPT1xCR_TD1RST              HRTIM_CPT1xCR_TD1RST_Msk      /*!< TD1RST */
#define HRTIM_CPT1xCR_TIMDCMP1_Pos      (26U)
#define HRTIM_CPT1xCR_TIMDCMP1_Msk      (0x1UL << HRTIM_CPT1xCR_TIMDCMP1_Pos)       /*!< 0x04000000 */
#define HRTIM_CPT1xCR_TIMDCMP1            HRTIM_CPT1xCR_TIMDCMP1_Msk    /*!< TIMDCMP1 */
#define HRTIM_CPT1xCR_TIMDCMP2_Pos      (27U)
#define HRTIM_CPT1xCR_TIMDCMP2_Msk      (0x1UL << HRTIM_CPT1xCR_TIMDCMP2_Pos)       /*!< 0x08000000 */
#define HRTIM_CPT1xCR_TIMDCMP2            HRTIM_CPT1xCR_TIMDCMP2_Msk    /*!< TIMDCMP2 */
#define HRTIM_CPT1xCR_TE1SET_Pos        (28U)
#define HRTIM_CPT1xCR_TE1SET_Msk        (0x1UL << HRTIM_CPT1xCR_TE1SET_Pos)     /*!< 0x10000000 */
#define HRTIM_CPT1xCR_TE1SET              HRTIM_CPT1xCR_TE1SET_Msk      /*!< TE1SET */
#define HRTIM_CPT1xCR_TE1RST_Pos        (29U)
#define HRTIM_CPT1xCR_TE1RST_Msk        (0x1UL << HRTIM_CPT1xCR_TE1RST_Pos)     /*!< 0x20000000 */
#define HRTIM_CPT1xCR_TE1RST              HRTIM_CPT1xCR_TE1RST_Msk      /*!< TE1RST */
#define HRTIM_CPT1xCR_TIMECMP1_Pos      (30U)
#define HRTIM_CPT1xCR_TIMECMP1_Msk      (0x1UL << HRTIM_CPT1xCR_TIMECMP1_Pos)       /*!< 0x40000000 */
#define HRTIM_CPT1xCR_TIMECMP1            HRTIM_CPT1xCR_TIMECMP1_Msk    /*!< TIMECMP1 */
#define HRTIM_CPT1xCR_TIMECMP2_Pos      (31U)
#define HRTIM_CPT1xCR_TIMECMP2_Msk      (0x1UL << HRTIM_CPT1xCR_TIMECMP2_Pos)       /*!< 0x80000000 */
#define HRTIM_CPT1xCR_TIMECMP2            HRTIM_CPT1xCR_TIMECMP2_Msk    /*!< TIMECMP2 */

/*
 *  Macros to access TimerF capture control fileds in other Timers
 *  E.g for TF1SET: 
 *  HRTIM_CPT1ACR_TF1SET is the macro to be used in TimerA for TimerF output 1 set  (offset 12)
 *  HRTIM_CPT1BCR_TF1SET is the macro to be used in TimerB for TimerF output 1 set  (offset 16)
 *  HRTIM_CPT1CCR_TF1SET is the macro to be used in TimerC for TimerF output 1 set  (offset 20)
 *  HRTIM_CPT1DCR_TF1SET is the macro to be used in TimerD for TimerF output 1 set  (offset 24)
 *  HRTIM_CPT1ECR_TF1SET is the macro to be used in TimerE for TimerF output 1 set  (offset 28)
 */
#define HRTIM_CPT1ACR_TF1SET_Pos          (12U)
#define HRTIM_CPT1ACR_TF1SET_Msk          (0x1UL << HRTIM_CPT1ACR_TF1SET_Pos)     /*!< 0x00001000 */
#define HRTIM_CPT1ACR_TF1SET              HRTIM_CPT1ACR_TF1SET_Msk      /*!< TF1SET */
#define HRTIM_CPT1ACR_TF1RST_Pos          (13U)
#define HRTIM_CPT1ACR_TF1RST_Msk          (0x1UL << HRTIM_CPT1ACR_TF1RST_Pos)     /*!< 0x00002000 */
#define HRTIM_CPT1ACR_TF1RST              HRTIM_CPT1ACR_TF1RST_Msk      /*!< TF1RST */
#define HRTIM_CPT1ACR_TFCMP1_Pos          (14U)
#define HRTIM_CPT1ACR_TFCMP1_Msk          (0x1UL << HRTIM_CPT1ACR_TFCMP1_Pos)       /*!< 0x00004000 */
#define HRTIM_CPT1ACR_TFCMP1              HRTIM_CPT1ACR_TFCMP1_Msk    /*!< TFCMP1 */
#define HRTIM_CPT1ACR_TFCMP2_Pos          (15U)
#define HRTIM_CPT1ACR_TFCMP2_Msk          (0x1UL << HRTIM_CPT1ACR_TFCMP2_Pos)       /*!< 0x00008000 */
#define HRTIM_CPT1ACR_TFCMP2              HRTIM_CPT1ACR_TFCMP2_Msk    /*!< TFCMP2 */
#define HRTIM_CPT1BCR_TF1SET_Pos          (16U)
#define HRTIM_CPT1BCR_TF1SET_Msk          (0x1UL << HRTIM_CPT1BCR_TF1SET_Pos)     /*!< 0x00010000 */
#define HRTIM_CPT1BCR_TF1SET              HRTIM_CPT1BCR_TF1SET_Msk      /*!< TF1SET */
#define HRTIM_CPT1BCR_TF1RST_Pos          (17U)
#define HRTIM_CPT1BCR_TF1RST_Msk          (0x1UL << HRTIM_CPT1BCR_TF1RST_Pos)     /*!< 0x00020000 */
#define HRTIM_CPT1BCR_TF1RST              HRTIM_CPT1xCR_TF1RST_Msk      /*!< TF1RST */
#define HRTIM_CPT1BCR_TFCMP1_Pos          (18U)
#define HRTIM_CPT1BCR_TFCMP1_Msk          (0x1UL << HRTIM_CPT1BCR_TFCMP1_Pos)       /*!< 0x00040000 */
#define HRTIM_CPT1BCR_TFCMP1              HRTIM_CPT1BCR_TFCMP1_Msk    /*!< TFCMP1 */
#define HRTIM_CPT1BCR_TFCMP2_Pos          (19U)
#define HRTIM_CPT1BCR_TFCMP2_Msk          (0x1UL << HRTIM_CPT1BCR_TFCMP2_Pos)       /*!< 0x00080000 */
#define HRTIM_CPT1BCR_TFCMP2              HRTIM_CPT1BCR_TFCMP2_Msk    /*!< TFCMP2 */
#define HRTIM_CPT1CCR_TF1SET_Pos          (20U)
#define HRTIM_CPT1CCR_TF1SET_Msk          (0x1UL << HRTIM_CPT1CCR_TF1SET_Pos)     /*!< 0x00100000 */
#define HRTIM_CPT1CCR_TF1SET              HRTIM_CPT1CCR_TF1SET_Msk      /*!< TF1SET */
#define HRTIM_CPT1CCR_TF1RST_Pos          (21U)
#define HRTIM_CPT1CCR_TF1RST_Msk          (0x1UL << HRTIM_CPT1CCR_TF1RST_Pos)     /*!< 0x00200000 */
#define HRTIM_CPT1CCR_TF1RST              HRTIM_CPT1CCR_TF1RST_Msk      /*!< TF1RST */
#define HRTIM_CPT1CCR_TFCMP1_Pos          (22U)
#define HRTIM_CPT1CCR_TFCMP1_Msk          (0x1UL << HRTIM_CPT1CCR_TFCMP1_Pos)       /*!< 0x00400000 */
#define HRTIM_CPT1CCR_TFCMP1              HRTIM_CPT1CCR_TFCMP1_Msk    /*!< TFCMP1 */
#define HRTIM_CPT1CCR_TFCMP2_Pos          (23U)
#define HRTIM_CPT1CCR_TFCMP2_Msk          (0x1UL << HRTIM_CPT1CCR_TFCMP2_Pos)       /*!< 0x00800000 */
#define HRTIM_CPT1CCR_TFCMP2              HRTIM_CPT1CCR_TFCMP2_Msk    /*!< TFCMP2 */
#define HRTIM_CPT1DCR_TF1SET_Pos          (24U)
#define HRTIM_CPT1DCR_TF1SET_Msk          (0x1UL << HRTIM_CPT1DCR_TF1SET_Pos)     /*!< 0x01000000 */
#define HRTIM_CPT1DCR_TF1SET              HRTIM_CPT1DCR_TF1SET_Msk      /*!< TF1SET */
#define HRTIM_CPT1DCR_TF1RST_Pos          (25U)
#define HRTIM_CPT1DCR_TF1RST_Msk          (0x1UL << HRTIM_CPT1DCR_TF1RST_Pos)     /*!< 0x02000000 */
#define HRTIM_CPT1DCR_TF1RST              HRTIM_CPT1DCR_TF1RST_Msk      /*!< TF1RST */
#define HRTIM_CPT1DCR_TFCMP1_Pos          (26U)
#define HRTIM_CPT1DCR_TFCMP1_Msk          (0x1UL << HRTIM_CPT1DCR_TFCMP1_Pos)       /*!< 0x04000000 */
#define HRTIM_CPT1DCR_TFCMP1              HRTIM_CPT1DCR_TFCMP1_Msk    /*!< TFCMP1 */
#define HRTIM_CPT1DCR_TFCMP2_Pos          (27U)
#define HRTIM_CPT1DCR_TFCMP2_Msk          (0x1UL << HRTIM_CPT1DCR_TFCMP2_Pos)       /*!< 0x08000000 */
#define HRTIM_CPT1DCR_TFCMP2              HRTIM_CPT1DCR_TFCMP2_Msk    /*!< TFCMP2 */
#define HRTIM_CPT1ECR_TF1SET_Pos          (28U)
#define HRTIM_CPT1ECR_TF1SET_Msk          (0x1UL << HRTIM_CPT1ECR_TF1SET_Pos)     /*!< 0x10000000 */
#define HRTIM_CPT1ECR_TF1SET              HRTIM_CPT1ECR_TF1SET_Msk      /*!< TF1SET */
#define HRTIM_CPT1ECR_TF1RST_Pos          (29U)
#define HRTIM_CPT1ECR_TF1RST_Msk          (0x1UL << HRTIM_CPT1ECR_TF1RST_Pos)     /*!< 0x20000000 */
#define HRTIM_CPT1ECR_TF1RST              HRTIM_CPT1ECR_TF1RST_Msk      /*!< TF1RST */
#define HRTIM_CPT1ECR_TFCMP1_Pos          (30U)
#define HRTIM_CPT1ECR_TFCMP1_Msk          (0x1UL << HRTIM_CPT1ECR_TFCMP1_Pos)       /*!< 0x40000000 */
#define HRTIM_CPT1ECR_TFCMP1              HRTIM_CPT1ECR_TFCMP1_Msk    /*!< TFCMP1 */
#define HRTIM_CPT1ECR_TFCMP2_Pos          (31U)
#define HRTIM_CPT1ECR_TFCMP2_Msk          (0x1UL << HRTIM_CPT1ECR_TFCMP2_Pos)       /*!< 0x80000000 */
#define HRTIM_CPT1ECR_TFCMP2              HRTIM_CPT1ECR_TFCMP2_Msk    /*!< TFCMP2 */

/************  Bit definition for HRTIM_CPT2xCR register  *************/
#define HRTIM_CPT2xCR_SWCPT_Pos         (0U)
#define HRTIM_CPT2xCR_SWCPT_Msk         (0x1UL << HRTIM_CPT2xCR_SWCPT_Pos)    /*!< 0x00000001 */
#define HRTIM_CPT2xCR_SWCPT               HRTIM_CPT2xCR_SWCPT_Msk       /*!< SWCPT */
#define HRTIM_CPT2xCR_UPDCPT_Pos        (1U)
#define HRTIM_CPT2xCR_UPDCPT_Msk        (0x1UL << HRTIM_CPT2xCR_UPDCPT_Pos)     /*!< 0x00000002 */
#define HRTIM_CPT2xCR_UPDCPT              HRTIM_CPT2xCR_UPDCPT_Msk      /*!< UPDCPT */
#define HRTIM_CPT2xCR_EXEV1CPT_Pos      (2U)
#define HRTIM_CPT2xCR_EXEV1CPT_Msk      (0x1UL << HRTIM_CPT2xCR_EXEV1CPT_Pos)       /*!< 0x00000004 */
#define HRTIM_CPT2xCR_EXEV1CPT            HRTIM_CPT2xCR_EXEV1CPT_Msk    /*!< EXEV1CPT */
#define HRTIM_CPT2xCR_EXEV2CPT_Pos      (3U)
#define HRTIM_CPT2xCR_EXEV2CPT_Msk      (0x1UL << HRTIM_CPT2xCR_EXEV2CPT_Pos)       /*!< 0x00000008 */
#define HRTIM_CPT2xCR_EXEV2CPT            HRTIM_CPT2xCR_EXEV2CPT_Msk    /*!< EXEV2CPT */
#define HRTIM_CPT2xCR_EXEV3CPT_Pos      (4U)
#define HRTIM_CPT2xCR_EXEV3CPT_Msk      (0x1UL << HRTIM_CPT2xCR_EXEV3CPT_Pos)       /*!< 0x00000010 */
#define HRTIM_CPT2xCR_EXEV3CPT            HRTIM_CPT2xCR_EXEV3CPT_Msk    /*!< EXEV3CPT */
#define HRTIM_CPT2xCR_EXEV4CPT_Pos      (5U)
#define HRTIM_CPT2xCR_EXEV4CPT_Msk      (0x1UL << HRTIM_CPT2xCR_EXEV4CPT_Pos)       /*!< 0x00000020 */
#define HRTIM_CPT2xCR_EXEV4CPT            HRTIM_CPT2xCR_EXEV4CPT_Msk    /*!< EXEV4CPT */
#define HRTIM_CPT2xCR_EXEV5CPT_Pos      (6U)
#define HRTIM_CPT2xCR_EXEV5CPT_Msk      (0x1UL << HRTIM_CPT2xCR_EXEV5CPT_Pos)       /*!< 0x00000040 */
#define HRTIM_CPT2xCR_EXEV5CPT            HRTIM_CPT2xCR_EXEV5CPT_Msk    /*!< EXEV5CPT */
#define HRTIM_CPT2xCR_EXEV6CPT_Pos      (7U)
#define HRTIM_CPT2xCR_EXEV6CPT_Msk      (0x1UL << HRTIM_CPT2xCR_EXEV6CPT_Pos)       /*!< 0x00000080 */
#define HRTIM_CPT2xCR_EXEV6CPT            HRTIM_CPT2xCR_EXEV6CPT_Msk    /*!< EXEV6CPT */
#define HRTIM_CPT2xCR_EXEV7CPT_Pos      (8U)
#define HRTIM_CPT2xCR_EXEV7CPT_Msk      (0x1UL << HRTIM_CPT2xCR_EXEV7CPT_Pos)       /*!< 0x00000100 */
#define HRTIM_CPT2xCR_EXEV7CPT            HRTIM_CPT2xCR_EXEV7CPT_Msk    /*!< EXEV7CPT */
#define HRTIM_CPT2xCR_EXEV8CPT_Pos      (9U)
#define HRTIM_CPT2xCR_EXEV8CPT_Msk      (0x1UL << HRTIM_CPT2xCR_EXEV8CPT_Pos)       /*!< 0x00000200 */
#define HRTIM_CPT2xCR_EXEV8CPT            HRTIM_CPT2xCR_EXEV8CPT_Msk    /*!< EXEV8CPT */
#define HRTIM_CPT2xCR_EXEV9CPT_Pos      (10U)
#define HRTIM_CPT2xCR_EXEV9CPT_Msk      (0x1UL << HRTIM_CPT2xCR_EXEV9CPT_Pos)       /*!< 0x00000400 */
#define HRTIM_CPT2xCR_EXEV9CPT            HRTIM_CPT2xCR_EXEV9CPT_Msk    /*!< EXEV9CPT */
#define HRTIM_CPT2xCR_EXEV10CPT_Pos     (11U)
#define HRTIM_CPT2xCR_EXEV10CPT_Msk     (0x1UL << HRTIM_CPT2xCR_EXEV10CPT_Pos)        /*!< 0x00000800 */
#define HRTIM_CPT2xCR_EXEV10CPT           HRTIM_CPT2xCR_EXEV10CPT_Msk   /*!< EXEV10CPT */
#define HRTIM_CPT2xCR_TA1SET_Pos        (12U)
#define HRTIM_CPT2xCR_TA1SET_Msk        (0x1UL << HRTIM_CPT2xCR_TA1SET_Pos)     /*!< 0x00001000 */
#define HRTIM_CPT2xCR_TA1SET              HRTIM_CPT2xCR_TA1SET_Msk      /*!< TA1SET */
#define HRTIM_CPT2xCR_TA1RST_Pos        (13U)
#define HRTIM_CPT2xCR_TA1RST_Msk        (0x1UL << HRTIM_CPT2xCR_TA1RST_Pos)     /*!< 0x00002000 */
#define HRTIM_CPT2xCR_TA1RST              HRTIM_CPT2xCR_TA1RST_Msk      /*!< TA1RST */
#define HRTIM_CPT2xCR_TIMACMP1_Pos      (14U)
#define HRTIM_CPT2xCR_TIMACMP1_Msk      (0x1UL << HRTIM_CPT2xCR_TIMACMP1_Pos)       /*!< 0x00004000 */
#define HRTIM_CPT2xCR_TIMACMP1            HRTIM_CPT2xCR_TIMACMP1_Msk    /*!< TIMACMP1 */
#define HRTIM_CPT2xCR_TIMACMP2_Pos      (15U)
#define HRTIM_CPT2xCR_TIMACMP2_Msk      (0x1UL << HRTIM_CPT2xCR_TIMACMP2_Pos)       /*!< 0x00008000 */
#define HRTIM_CPT2xCR_TIMACMP2            HRTIM_CPT2xCR_TIMACMP2_Msk    /*!< TIMACMP2 */
#define HRTIM_CPT2xCR_TB1SET_Pos        (16U)
#define HRTIM_CPT2xCR_TB1SET_Msk        (0x1UL << HRTIM_CPT2xCR_TB1SET_Pos)     /*!< 0x00010000 */
#define HRTIM_CPT2xCR_TB1SET              HRTIM_CPT2xCR_TB1SET_Msk      /*!< TB1SET */
#define HRTIM_CPT2xCR_TB1RST_Pos        (17U)
#define HRTIM_CPT2xCR_TB1RST_Msk        (0x1UL << HRTIM_CPT2xCR_TB1RST_Pos)     /*!< 0x00020000 */
#define HRTIM_CPT2xCR_TB1RST              HRTIM_CPT2xCR_TB1RST_Msk      /*!< TB1RST */
#define HRTIM_CPT2xCR_TIMBCMP1_Pos      (18U)
#define HRTIM_CPT2xCR_TIMBCMP1_Msk      (0x1UL << HRTIM_CPT2xCR_TIMBCMP1_Pos)       /*!< 0x00040000 */
#define HRTIM_CPT2xCR_TIMBCMP1            HRTIM_CPT2xCR_TIMBCMP1_Msk    /*!< TIMBCMP1 */
#define HRTIM_CPT2xCR_TIMBCMP2_Pos      (19U)
#define HRTIM_CPT2xCR_TIMBCMP2_Msk      (0x1UL << HRTIM_CPT2xCR_TIMBCMP2_Pos)       /*!< 0x00080000 */
#define HRTIM_CPT2xCR_TIMBCMP2            HRTIM_CPT2xCR_TIMBCMP2_Msk    /*!< TIMBCMP2 */
#define HRTIM_CPT2xCR_TC1SET_Pos        (20U)
#define HRTIM_CPT2xCR_TC1SET_Msk        (0x1UL << HRTIM_CPT2xCR_TC1SET_Pos)     /*!< 0x00100000 */
#define HRTIM_CPT2xCR_TC1SET              HRTIM_CPT2xCR_TC1SET_Msk      /*!< TC1SET */
#define HRTIM_CPT2xCR_TC1RST_Pos        (21U)
#define HRTIM_CPT2xCR_TC1RST_Msk        (0x1UL << HRTIM_CPT2xCR_TC1RST_Pos)     /*!< 0x00200000 */
#define HRTIM_CPT2xCR_TC1RST              HRTIM_CPT2xCR_TC1RST_Msk      /*!< TC1RST */
#define HRTIM_CPT2xCR_TIMCCMP1_Pos      (22U)
#define HRTIM_CPT2xCR_TIMCCMP1_Msk      (0x1UL << HRTIM_CPT2xCR_TIMCCMP1_Pos)       /*!< 0x00400000 */
#define HRTIM_CPT2xCR_TIMCCMP1            HRTIM_CPT2xCR_TIMCCMP1_Msk    /*!< TIMCCMP1 */
#define HRTIM_CPT2xCR_TIMCCMP2_Pos      (23U)
#define HRTIM_CPT2xCR_TIMCCMP2_Msk      (0x1UL << HRTIM_CPT2xCR_TIMCCMP2_Pos)       /*!< 0x00800000 */
#define HRTIM_CPT2xCR_TIMCCMP2            HRTIM_CPT2xCR_TIMCCMP2_Msk    /*!< TIMCCMP2 */
#define HRTIM_CPT2xCR_TD1SET_Pos        (24U)
#define HRTIM_CPT2xCR_TD1SET_Msk        (0x1UL << HRTIM_CPT2xCR_TD1SET_Pos)     /*!< 0x01000000 */
#define HRTIM_CPT2xCR_TD1SET              HRTIM_CPT2xCR_TD1SET_Msk      /*!< TD1SET */
#define HRTIM_CPT2xCR_TD1RST_Pos        (25U)
#define HRTIM_CPT2xCR_TD1RST_Msk        (0x1UL << HRTIM_CPT2xCR_TD1RST_Pos)     /*!< 0x02000000 */
#define HRTIM_CPT2xCR_TD1RST              HRTIM_CPT2xCR_TD1RST_Msk      /*!< TD1RST */
#define HRTIM_CPT2xCR_TIMDCMP1_Pos      (26U)
#define HRTIM_CPT2xCR_TIMDCMP1_Msk      (0x1UL << HRTIM_CPT2xCR_TIMDCMP1_Pos)       /*!< 0x04000000 */
#define HRTIM_CPT2xCR_TIMDCMP1            HRTIM_CPT2xCR_TIMDCMP1_Msk    /*!< TIMDCMP1 */
#define HRTIM_CPT2xCR_TIMDCMP2_Pos      (27U)
#define HRTIM_CPT2xCR_TIMDCMP2_Msk      (0x1UL << HRTIM_CPT2xCR_TIMDCMP2_Pos)       /*!< 0x08000000 */
#define HRTIM_CPT2xCR_TIMDCMP2            HRTIM_CPT2xCR_TIMDCMP2_Msk    /*!< TIMDCMP2 */
#define HRTIM_CPT2xCR_TE1SET_Pos        (28U)
#define HRTIM_CPT2xCR_TE1SET_Msk        (0x1UL << HRTIM_CPT2xCR_TE1SET_Pos)     /*!< 0x10000000 */
#define HRTIM_CPT2xCR_TE1SET              HRTIM_CPT2xCR_TE1SET_Msk      /*!< TE1SET */
#define HRTIM_CPT2xCR_TE1RST_Pos        (29U)
#define HRTIM_CPT2xCR_TE1RST_Msk        (0x1UL << HRTIM_CPT2xCR_TE1RST_Pos)     /*!< 0x20000000 */
#define HRTIM_CPT2xCR_TE1RST              HRTIM_CPT2xCR_TE1RST_Msk      /*!< TE1RST */
#define HRTIM_CPT2xCR_TIMECMP1_Pos      (30U)
#define HRTIM_CPT2xCR_TIMECMP1_Msk      (0x1UL << HRTIM_CPT2xCR_TIMECMP1_Pos)       /*!< 0x40000000 */
#define HRTIM_CPT2xCR_TIMECMP1            HRTIM_CPT2xCR_TIMECMP1_Msk    /*!< TIMECMP1 */
#define HRTIM_CPT2xCR_TIMECMP2_Pos      (31U)
#define HRTIM_CPT2xCR_TIMECMP2_Msk      (0x1UL << HRTIM_CPT2xCR_TIMECMP2_Pos)       /*!< 0x80000000 */
#define HRTIM_CPT2xCR_TIMECMP2            HRTIM_CPT2xCR_TIMECMP2_Msk    /*!< TIMECMP2 */

/*
 *  Macros to access TimerF capture control fileds in other Timers
 *  E.g for TF1SET: 
 *  HRTIM_CPT2ACR_TF1SET is the macro to be used in TimerA for TimerF output 1 set  (offset 12)
 *  HRTIM_CPT2BCR_TF1SET is the macro to be used in TimerB for TimerF output 1 set  (offset 16)
 *  HRTIM_CPT2CCR_TF1SET is the macro to be used in TimerC for TimerF output 1 set  (offset 20)
 *  HRTIM_CPT2DCR_TF1SET is the macro to be used in TimerD for TimerF output 1 set  (offset 24)
 *  HRTIM_CPT2ECR_TF1SET is the macro to be used in TimerE for TimerF output 1 set  (offset 28)
 */
#define HRTIM_CPT2ACR_TF1SET_Pos          (12U)
#define HRTIM_CPT2ACR_TF1SET_Msk          (0x1UL << HRTIM_CPT2ACR_TF1SET_Pos)     /*!< 0x00001000 */
#define HRTIM_CPT2ACR_TF1SET              HRTIM_CPT2ACR_TF1SET_Msk      /*!< TF1SET */
#define HRTIM_CPT2ACR_TF1RST_Pos          (13U)
#define HRTIM_CPT2ACR_TF1RST_Msk          (0x1UL << HRTIM_CPT2ACR_TF1RST_Pos)     /*!< 0x00002000 */
#define HRTIM_CPT2ACR_TF1RST              HRTIM_CPT2ACR_TF1RST_Msk      /*!< TF1RST */
#define HRTIM_CPT2ACR_TFCMP1_Pos          (14U)
#define HRTIM_CPT2ACR_TFCMP1_Msk          (0x1UL << HRTIM_CPT2ACR_TFCMP1_Pos)       /*!< 0x00004000 */
#define HRTIM_CPT2ACR_TFCMP1              HRTIM_CPT2ACR_TFCMP1_Msk    /*!< TFCMP1 */
#define HRTIM_CPT2ACR_TFCMP2_Pos          (15U)
#define HRTIM_CPT2ACR_TFCMP2_Msk          (0x1UL << HRTIM_CPT2ACR_TFCMP2_Pos)       /*!< 0x00008000 */
#define HRTIM_CPT2ACR_TFCMP2              HRTIM_CPT2ACR_TFCMP2_Msk    /*!< TFCMP2 */
#define HRTIM_CPT2BCR_TF1SET_Pos          (16U)
#define HRTIM_CPT2BCR_TF1SET_Msk          (0x1UL << HRTIM_CPT2BCR_TF1SET_Pos)     /*!< 0x00010000 */
#define HRTIM_CPT2BCR_TF1SET              HRTIM_CPT2BCR_TF1SET_Msk      /*!< TF1SET */
#define HRTIM_CPT2BCR_TF1RST_Pos          (17U)
#define HRTIM_CPT2BCR_TF1RST_Msk          (0x1UL << HRTIM_CPT2BCR_TF1RST_Pos)     /*!< 0x00020000 */
#define HRTIM_CPT2BCR_TF1RST              HRTIM_CPT2xCR_TF1RST_Msk      /*!< TF1RST */
#define HRTIM_CPT2BCR_TFCMP1_Pos          (18U)
#define HRTIM_CPT2BCR_TFCMP1_Msk          (0x1UL << HRTIM_CPT2BCR_TFCMP1_Pos)       /*!< 0x00040000 */
#define HRTIM_CPT2BCR_TFCMP1              HRTIM_CPT2BCR_TFCMP1_Msk    /*!< TFCMP1 */
#define HRTIM_CPT2BCR_TFCMP2_Pos          (19U)
#define HRTIM_CPT2BCR_TFCMP2_Msk          (0x1UL << HRTIM_CPT2BCR_TFCMP2_Pos)       /*!< 0x00080000 */
#define HRTIM_CPT2BCR_TFCMP2              HRTIM_CPT2BCR_TFCMP2_Msk    /*!< TFCMP2 */
#define HRTIM_CPT2CCR_TF1SET_Pos          (20U)
#define HRTIM_CPT2CCR_TF1SET_Msk          (0x1UL << HRTIM_CPT2CCR_TF1SET_Pos)     /*!< 0x00100000 */
#define HRTIM_CPT2CCR_TF1SET              HRTIM_CPT2CCR_TF1SET_Msk      /*!< TF1SET */
#define HRTIM_CPT2CCR_TF1RST_Pos          (21U)
#define HRTIM_CPT2CCR_TF1RST_Msk          (0x1UL << HRTIM_CPT2CCR_TF1RST_Pos)     /*!< 0x00200000 */
#define HRTIM_CPT2CCR_TF1RST              HRTIM_CPT2CCR_TF1RST_Msk      /*!< TF1RST */
#define HRTIM_CPT2CCR_TFCMP1_Pos          (22U)
#define HRTIM_CPT2CCR_TFCMP1_Msk          (0x1UL << HRTIM_CPT2CCR_TFCMP1_Pos)       /*!< 0x00400000 */
#define HRTIM_CPT2CCR_TFCMP1              HRTIM_CPT2CCR_TFCMP1_Msk    /*!< TFCMP1 */
#define HRTIM_CPT2CCR_TFCMP2_Pos          (23U)
#define HRTIM_CPT2CCR_TFCMP2_Msk          (0x1UL << HRTIM_CPT2CCR_TFCMP2_Pos)       /*!< 0x00800000 */
#define HRTIM_CPT2CCR_TFCMP2              HRTIM_CPT2CCR_TFCMP2_Msk    /*!< TFCMP2 */
#define HRTIM_CPT2DCR_TF1SET_Pos          (24U)
#define HRTIM_CPT2DCR_TF1SET_Msk          (0x1UL << HRTIM_CPT2DCR_TF1SET_Pos)     /*!< 0x01000000 */
#define HRTIM_CPT2DCR_TF1SET              HRTIM_CPT2DCR_TF1SET_Msk      /*!< TF1SET */
#define HRTIM_CPT2DCR_TF1RST_Pos          (25U)
#define HRTIM_CPT2DCR_TF1RST_Msk          (0x1UL << HRTIM_CPT2DCR_TF1RST_Pos)     /*!< 0x02000000 */
#define HRTIM_CPT2DCR_TF1RST              HRTIM_CPT2DCR_TF1RST_Msk      /*!< TF1RST */
#define HRTIM_CPT2DCR_TFCMP1_Pos          (26U)
#define HRTIM_CPT2DCR_TFCMP1_Msk          (0x1UL << HRTIM_CPT2DCR_TFCMP1_Pos)       /*!< 0x04000000 */
#define HRTIM_CPT2DCR_TFCMP1              HRTIM_CPT2DCR_TFCMP1_Msk    /*!< TFCMP1 */
#define HRTIM_CPT2DCR_TFCMP2_Pos          (27U)
#define HRTIM_CPT2DCR_TFCMP2_Msk          (0x1UL << HRTIM_CPT2DCR_TFCMP2_Pos)       /*!< 0x08000000 */
#define HRTIM_CPT2DCR_TFCMP2              HRTIM_CPT2DCR_TFCMP2_Msk    /*!< TFCMP2 */
#define HRTIM_CPT2ECR_TF1SET_Pos          (28U)
#define HRTIM_CPT2ECR_TF1SET_Msk          (0x1UL << HRTIM_CPT2ECR_TF1SET_Pos)     /*!< 0x10000000 */
#define HRTIM_CPT2ECR_TF1SET              HRTIM_CPT2ECR_TF1SET_Msk      /*!< TF1SET */
#define HRTIM_CPT2ECR_TF1RST_Pos          (29U)
#define HRTIM_CPT2ECR_TF1RST_Msk          (0x1UL << HRTIM_CPT2ECR_TF1RST_Pos)     /*!< 0x20000000 */
#define HRTIM_CPT2ECR_TF1RST              HRTIM_CPT2ECR_TF1RST_Msk      /*!< TF1RST */
#define HRTIM_CPT2ECR_TFCMP1_Pos          (30U)
#define HRTIM_CPT2ECR_TFCMP1_Msk          (0x1UL << HRTIM_CPT2ECR_TFCMP1_Pos)       /*!< 0x40000000 */
#define HRTIM_CPT2ECR_TFCMP1              HRTIM_CPT2ECR_TFCMP1_Msk    /*!< TFCMP1 */
#define HRTIM_CPT2ECR_TFCMP2_Pos          (31U)
#define HRTIM_CPT2ECR_TFCMP2_Msk          (0x1UL << HRTIM_CPT2ECR_TFCMP2_Pos)       /*!< 0x80000000 */
#define HRTIM_CPT2ECR_TFCMP2              HRTIM_CPT2ECR_TFCMP2_Msk    /*!< TFCMP2 */


/*************  Bit definition for HRTIM_OUTxR register  **************/
#define HRTIM_OUTxR_POL1_Pos            (1U)
#define HRTIM_OUTxR_POL1_Msk            (0x1UL << HRTIM_OUTxR_POL1_Pos) /*!< 0x00000002 */
#define HRTIM_OUTxR_POL1                  HRTIM_OUTxR_POL1_Msk          /*!< POL1 */
#define HRTIM_OUTxR_IDLM1_Pos           (2U)
#define HRTIM_OUTxR_IDLM1_Msk           (0x1UL << HRTIM_OUTxR_IDLM1_Pos)  /*!< 0x00000004 */
#define HRTIM_OUTxR_IDLM1                 HRTIM_OUTxR_IDLM1_Msk         /*!< IDLM1 */
#define HRTIM_OUTxR_IDLES1_Pos          (3U)
#define HRTIM_OUTxR_IDLES1_Msk          (0x1UL << HRTIM_OUTxR_IDLES1_Pos)   /*!< 0x00000008 */
#define HRTIM_OUTxR_IDLES1                HRTIM_OUTxR_IDLES1_Msk        /*!< IDLES1 */
#define HRTIM_OUTxR_FAULT1_Pos          (4U)
#define HRTIM_OUTxR_FAULT1_Msk          (0x3UL << HRTIM_OUTxR_FAULT1_Pos)   /*!< 0x00000030 */
#define HRTIM_OUTxR_FAULT1                HRTIM_OUTxR_FAULT1_Msk        /*!< FAULT1 */
#define HRTIM_OUTxR_FAULT1_0          (0x1UL << HRTIM_OUTxR_FAULT1_Pos)    /*!< 0x00000010 */
#define HRTIM_OUTxR_FAULT1_1          (0x2UL << HRTIM_OUTxR_FAULT1_Pos)    /*!< 0x00000020 */
#define HRTIM_OUTxR_CHP1_Pos            (6U)
#define HRTIM_OUTxR_CHP1_Msk            (0x1UL << HRTIM_OUTxR_CHP1_Pos) /*!< 0x00000040 */
#define HRTIM_OUTxR_CHP1                  HRTIM_OUTxR_CHP1_Msk          /*!< CHP1 */
#define HRTIM_OUTxR_DIDL1_Pos           (7U)
#define HRTIM_OUTxR_DIDL1_Msk           (0x1UL << HRTIM_OUTxR_DIDL1_Pos)  /*!< 0x00000080 */
#define HRTIM_OUTxR_DIDL1                 HRTIM_OUTxR_DIDL1_Msk         /*!< DIDL1 */
#define HRTIM_OUTxR_DTEN_Pos            (8U)
#define HRTIM_OUTxR_DTEN_Msk            (0x1UL << HRTIM_OUTxR_DTEN_Pos) /*!< 0x00000100 */
#define HRTIM_OUTxR_DTEN                  HRTIM_OUTxR_DTEN_Msk          /*!< DTEN */
#define HRTIM_OUTxR_DLYPRTEN_Pos        (9U)
#define HRTIM_OUTxR_DLYPRTEN_Msk        (0x1UL << HRTIM_OUTxR_DLYPRTEN_Pos)     /*!< 0x00000200 */
#define HRTIM_OUTxR_DLYPRTEN              HRTIM_OUTxR_DLYPRTEN_Msk      /*!< DLYPRTEN */
#define HRTIM_OUTxR_DLYPRT_Pos          (10U)
#define HRTIM_OUTxR_DLYPRT_Msk          (0x7UL << HRTIM_OUTxR_DLYPRT_Pos)   /*!< 0x00001C00 */
#define HRTIM_OUTxR_DLYPRT                HRTIM_OUTxR_DLYPRT_Msk        /*!< DLYPRT */
#define HRTIM_OUTxR_DLYPRT_0          (0x1UL << HRTIM_OUTxR_DLYPRT_Pos)    /*!< 0x00000400 */
#define HRTIM_OUTxR_DLYPRT_1          (0x2UL << HRTIM_OUTxR_DLYPRT_Pos)    /*!< 0x00000800 */
#define HRTIM_OUTxR_DLYPRT_2          (0x4UL << HRTIM_OUTxR_DLYPRT_Pos)    /*!< 0x00001000 */
#define HRTIM_OUTxR_BIAR_Pos            (14U)
#define HRTIM_OUTxR_BIAR_Msk            (0x1UL << HRTIM_OUTxR_BIAR_Pos) /*!< 0x00004000 */
#define HRTIM_OUTxR_BIAR                  HRTIM_OUTxR_BIAR_Msk          /*!< BIAR */
#define HRTIM_OUTxR_POL2_Pos            (17U)
#define HRTIM_OUTxR_POL2_Msk            (0x1UL << HRTIM_OUTxR_POL2_Pos) /*!< 0x00020000 */
#define HRTIM_OUTxR_POL2                  HRTIM_OUTxR_POL2_Msk          /*!< POL2 */
#define HRTIM_OUTxR_IDLM2_Pos           (18U)
#define HRTIM_OUTxR_IDLM2_Msk           (0x1UL << HRTIM_OUTxR_IDLM2_Pos)  /*!< 0x00040000 */
#define HRTIM_OUTxR_IDLM2                 HRTIM_OUTxR_IDLM2_Msk         /*!< IDLM2 */
#define HRTIM_OUTxR_IDLES2_Pos          (19U)
#define HRTIM_OUTxR_IDLES2_Msk          (0x1UL << HRTIM_OUTxR_IDLES2_Pos)   /*!< 0x00080000 */
#define HRTIM_OUTxR_IDLES2                HRTIM_OUTxR_IDLES2_Msk        /*!< IDLES2 */
#define HRTIM_OUTxR_FAULT2_Pos          (20U)
#define HRTIM_OUTxR_FAULT2_Msk          (0x3UL << HRTIM_OUTxR_FAULT2_Pos)   /*!< 0x00300000 */
#define HRTIM_OUTxR_FAULT2                HRTIM_OUTxR_FAULT2_Msk        /*!< FAULT2 */
#define HRTIM_OUTxR_FAULT2_0          (0x1UL << HRTIM_OUTxR_FAULT2_Pos)    /*!< 0x00100000 */
#define HRTIM_OUTxR_FAULT2_1          (0x2UL << HRTIM_OUTxR_FAULT2_Pos)    /*!< 0x00200000 */
#define HRTIM_OUTxR_CHP2_Pos            (22U)
#define HRTIM_OUTxR_CHP2_Msk            (0x1UL << HRTIM_OUTxR_CHP2_Pos) /*!< 0x00400000 */
#define HRTIM_OUTxR_CHP2                  HRTIM_OUTxR_CHP2_Msk          /*!< CHP2 */
#define HRTIM_OUTxR_DIDL2_Pos           (23U)
#define HRTIM_OUTxR_DIDL2_Msk           (0x1UL << HRTIM_OUTxR_DIDL2_Pos)  /*!< 0x00800000 */
#define HRTIM_OUTxR_DIDL2                 HRTIM_OUTxR_DIDL2_Msk         /*!< DIDL2 */

/*************  Bit definition for HRTIM_FLTxR register  **************/
#define HRTIM_FLTxR_FLT1EN_Pos          (0U)
#define HRTIM_FLTxR_FLT1EN_Msk          (0x1UL << HRTIM_FLTxR_FLT1EN_Pos)   /*!< 0x00000001 */
#define HRTIM_FLTxR_FLT1EN                HRTIM_FLTxR_FLT1EN_Msk        /*!< FLT1EN */
#define HRTIM_FLTxR_FLT2EN_Pos          (1U)
#define HRTIM_FLTxR_FLT2EN_Msk          (0x1UL << HRTIM_FLTxR_FLT2EN_Pos)   /*!< 0x00000002 */
#define HRTIM_FLTxR_FLT2EN                HRTIM_FLTxR_FLT2EN_Msk        /*!< FLT2EN */
#define HRTIM_FLTxR_FLT3EN_Pos          (2U)
#define HRTIM_FLTxR_FLT3EN_Msk          (0x1UL << HRTIM_FLTxR_FLT3EN_Pos)   /*!< 0x00000004 */
#define HRTIM_FLTxR_FLT3EN                HRTIM_FLTxR_FLT3EN_Msk        /*!< FLT3EN */
#define HRTIM_FLTxR_FLT4EN_Pos          (3U)
#define HRTIM_FLTxR_FLT4EN_Msk          (0x1UL << HRTIM_FLTxR_FLT4EN_Pos)   /*!< 0x00000008 */
#define HRTIM_FLTxR_FLT4EN                HRTIM_FLTxR_FLT4EN_Msk        /*!< FLT4EN */
#define HRTIM_FLTxR_FLT5EN_Pos          (4U)
#define HRTIM_FLTxR_FLT5EN_Msk          (0x1UL << HRTIM_FLTxR_FLT5EN_Pos)   /*!< 0x00000010 */
#define HRTIM_FLTxR_FLT5EN                HRTIM_FLTxR_FLT5EN_Msk        /*!< FLT5EN */
#define HRTIM_FLTxR_FLT6EN_Pos          (5U)
#define HRTIM_FLTxR_FLT6EN_Msk          (0x1UL << HRTIM_FLTxR_FLT6EN_Pos)   /*!< 0x00000020 */
#define HRTIM_FLTxR_FLT6EN                HRTIM_FLTxR_FLT6EN_Msk        /*!< FLT6EN */
#define HRTIM_FLTxR_FLTLCK_Pos          (31U)
#define HRTIM_FLTxR_FLTLCK_Msk          (0x1UL << HRTIM_FLTxR_FLTLCK_Pos)   /*!< 0x80000000 */
#define HRTIM_FLTxR_FLTLCK                HRTIM_FLTxR_FLTLCK_Msk        /*!< FLTLCK */

/************  Bit definition for HRTIM_TIMxCR2 register  *************/
#define HRTIM_TIMxCR2_DCDE_Pos          (0U)
#define HRTIM_TIMxCR2_DCDE_Msk          (0x1UL << HRTIM_TIMxCR2_DCDE_Pos)   /*!< 0x00000001 */
#define HRTIM_TIMxCR2_DCDE                HRTIM_TIMxCR2_DCDE_Msk        /*!< DCDE */
#define HRTIM_TIMxCR2_DCDS_Pos          (1U)
#define HRTIM_TIMxCR2_DCDS_Msk          (0x1UL << HRTIM_TIMxCR2_DCDS_Pos)   /*!< 0x00000002 */
#define HRTIM_TIMxCR2_DCDS                HRTIM_TIMxCR2_DCDS_Msk        /*!< DCDS */
#define HRTIM_TIMxCR2_DCDR_Pos          (2U)
#define HRTIM_TIMxCR2_DCDR_Msk          (0x1UL << HRTIM_TIMxCR2_DCDR_Pos)   /*!< 0x00000004 */
#define HRTIM_TIMxCR2_DCDR                HRTIM_TIMxCR2_DCDR_Msk        /*!< DCDR */
#define HRTIM_TIMxCR2_UDM_Pos           (4U)
#define HRTIM_TIMxCR2_UDM_Msk           (0x1UL << HRTIM_TIMxCR2_UDM_Pos)  /*!< 0x00000010 */
#define HRTIM_TIMxCR2_UDM                 HRTIM_TIMxCR2_UDM_Msk         /*!< UDM */
#define HRTIM_TIMxCR2_ROM_Pos           (6U)
#define HRTIM_TIMxCR2_ROM_Msk           (0x3UL << HRTIM_TIMxCR2_ROM_Pos)  /*!< 0x000000C0 */
#define HRTIM_TIMxCR2_ROM                 HRTIM_TIMxCR2_ROM_Msk         /*!< ROM */
#define HRTIM_TIMxCR2_ROM_0           (0x1UL << HRTIM_TIMxCR2_ROM_Pos)   /*!< 0x00000040 */
#define HRTIM_TIMxCR2_ROM_1           (0x2UL << HRTIM_TIMxCR2_ROM_Pos)   /*!< 0x00000080 */
#define HRTIM_TIMxCR2_OUTROM_Pos        (8U)
#define HRTIM_TIMxCR2_OUTROM_Msk        (0x3UL << HRTIM_TIMxCR2_OUTROM_Pos)     /*!< 0x00000300 */
#define HRTIM_TIMxCR2_OUTROM              HRTIM_TIMxCR2_OUTROM_Msk      /*!< OUTROM */
#define HRTIM_TIMxCR2_OUTROM_0        (0x1UL << HRTIM_TIMxCR2_OUTROM_Pos)      /*!< 0x00000100 */
#define HRTIM_TIMxCR2_OUTROM_1        (0x2UL << HRTIM_TIMxCR2_OUTROM_Pos)      /*!< 0x00000200 */
#define HRTIM_TIMxCR2_ADROM_Pos         (10U)
#define HRTIM_TIMxCR2_ADROM_Msk         (0x3UL << HRTIM_TIMxCR2_ADROM_Pos)    /*!< 0x00000C00 */
#define HRTIM_TIMxCR2_ADROM               HRTIM_TIMxCR2_ADROM_Msk       /*!< ADROM */
#define HRTIM_TIMxCR2_ADROM_0         (0x1UL << HRTIM_TIMxCR2_ADROM_Pos)     /*!< 0x00000400 */
#define HRTIM_TIMxCR2_ADROM_1         (0x2UL << HRTIM_TIMxCR2_ADROM_Pos)     /*!< 0x00000800 */
#define HRTIM_TIMxCR2_BMROM_Pos         (12U)
#define HRTIM_TIMxCR2_BMROM_Msk         (0x3UL << HRTIM_TIMxCR2_BMROM_Pos)    /*!< 0x00003000 */
#define HRTIM_TIMxCR2_BMROM               HRTIM_TIMxCR2_BMROM_Msk       /*!< BMROM */
#define HRTIM_TIMxCR2_BMROM_0         (0x1UL << HRTIM_TIMxCR2_BMROM_Pos)     /*!< 0x00001000 */
#define HRTIM_TIMxCR2_BMROM_1         (0x2UL << HRTIM_TIMxCR2_BMROM_Pos)     /*!< 0x00002000 */
#define HRTIM_TIMxCR2_FEROM_Pos         (14U)
#define HRTIM_TIMxCR2_FEROM_Msk         (0x3UL << HRTIM_TIMxCR2_FEROM_Pos)    /*!< 0x0000C000 */
#define HRTIM_TIMxCR2_FEROM               HRTIM_TIMxCR2_FEROM_Msk       /*!< FEROM */
#define HRTIM_TIMxCR2_FEROM_0         (0x1UL << HRTIM_TIMxCR2_FEROM_Pos)     /*!< 0x00004000 */
#define HRTIM_TIMxCR2_FEROM_1         (0x2UL << HRTIM_TIMxCR2_FEROM_Pos)     /*!< 0x00008000 */
#define HRTIM_TIMxCR2_GTCMP1_Pos        (16U)
#define HRTIM_TIMxCR2_GTCMP1_Msk        (0x1UL << HRTIM_TIMxCR2_GTCMP1_Pos)     /*!< 0x00010000 */
#define HRTIM_TIMxCR2_GTCMP1              HRTIM_TIMxCR2_GTCMP1_Msk      /*!< GTCMP1 */
#define HRTIM_TIMxCR2_GTCMP3_Pos        (17U)
#define HRTIM_TIMxCR2_GTCMP3_Msk        (0x1UL << HRTIM_TIMxCR2_GTCMP3_Pos)     /*!< 0x00020000 */
#define HRTIM_TIMxCR2_GTCMP3              HRTIM_TIMxCR2_GTCMP3_Msk      /*!< GTCMP3 */
#define HRTIM_TIMxCR2_TRGHLF_Pos        (20U)
#define HRTIM_TIMxCR2_TRGHLF_Msk        (0x1UL << HRTIM_TIMxCR2_TRGHLF_Pos)     /*!< 0x00100000 */
#define HRTIM_TIMxCR2_TRGHLF              HRTIM_TIMxCR2_TRGHLF_Msk      /*!< TRGHLF */

/*************  Bit definition for HRTIM_EEFxR3 register  *************/
#define HRTIM_EEFxR3_EEVACE_Pos         (0U)
#define HRTIM_EEFxR3_EEVACE_Msk         (0x1UL << HRTIM_EEFxR3_EEVACE_Pos)    /*!< 0x00000001 */
#define HRTIM_EEFxR3_EEVACE               HRTIM_EEFxR3_EEVACE_Msk       /*!< EEVACE */
#define HRTIM_EEFxR3_EEVACRES_Pos       (1U)
#define HRTIM_EEFxR3_EEVACRES_Msk       (0x1UL << HRTIM_EEFxR3_EEVACRES_Pos)      /*!< 0x00000002 */
#define HRTIM_EEFxR3_EEVACRES             HRTIM_EEFxR3_EEVACRES_Msk     /*!< EEVACRES */
#define HRTIM_EEFxR3_EEVARSTM_Pos       (2U)
#define HRTIM_EEFxR3_EEVARSTM_Msk       (0x1UL << HRTIM_EEFxR3_EEVARSTM_Pos)      /*!< 0x00000004 */
#define HRTIM_EEFxR3_EEVARSTM             HRTIM_EEFxR3_EEVARSTM_Msk     /*!< EEVARSTM */
#define HRTIM_EEFxR3_EEVASEL_Pos        (4U)
#define HRTIM_EEFxR3_EEVASEL_Msk        (0xFUL << HRTIM_EEFxR3_EEVASEL_Pos)     /*!< 0x000000F0 */
#define HRTIM_EEFxR3_EEVASEL              HRTIM_EEFxR3_EEVASEL_Msk      /*!< EEVASEL */
#define HRTIM_EEFxR3_EEVASEL_0        (0x1UL << HRTIM_EEFxR3_EEVASEL_Pos)      /*!< 0x00000010 */
#define HRTIM_EEFxR3_EEVASEL_1        (0x2UL << HRTIM_EEFxR3_EEVASEL_Pos)      /*!< 0x00000020 */
#define HRTIM_EEFxR3_EEVASEL_2        (0x4UL << HRTIM_EEFxR3_EEVASEL_Pos)      /*!< 0x00000040 */
#define HRTIM_EEFxR3_EEVASEL_3        (0x8UL << HRTIM_EEFxR3_EEVASEL_Pos)      /*!< 0x00000080 */
#define HRTIM_EEFxR3_EEVACNT_Pos        (8U)
#define HRTIM_EEFxR3_EEVACNT_Msk        (0x3FUL << HRTIM_EEFxR3_EEVACNT_Pos)      /*!< 0x00003F00 */
#define HRTIM_EEFxR3_EEVACNT              HRTIM_EEFxR3_EEVACNT_Msk      /*!< EEVACNT */
#define HRTIM_EEFxR3_EEVACNT_0        (0x1UL << HRTIM_EEFxR3_EEVACNT_Pos)       /*!< 0x00000100 */
#define HRTIM_EEFxR3_EEVACNT_1        (0x2UL << HRTIM_EEFxR3_EEVACNT_Pos)       /*!< 0x00000200 */
#define HRTIM_EEFxR3_EEVACNT_2        (0x4UL << HRTIM_EEFxR3_EEVACNT_Pos)       /*!< 0x00000400 */
#define HRTIM_EEFxR3_EEVACNT_3        (0x8UL << HRTIM_EEFxR3_EEVACNT_Pos)       /*!< 0x00000800 */
#define HRTIM_EEFxR3_EEVACNT_4        (0x10UL << HRTIM_EEFxR3_EEVACNT_Pos)       /*!< 0x00001000 */
#define HRTIM_EEFxR3_EEVACNT_5        (0x20UL << HRTIM_EEFxR3_EEVACNT_Pos)       /*!< 0x00002000 */
#define HRTIM_EEFxR3_EEVBCE_Pos         (16U)
#define HRTIM_EEFxR3_EEVBCE_Msk         (0x1UL << HRTIM_EEFxR3_EEVBCE_Pos)    /*!< 0x00010000 */
#define HRTIM_EEFxR3_EEVBCE               HRTIM_EEFxR3_EEVBCE_Msk       /*!< EEVBCE */
#define HRTIM_EEFxR3_EEVBCRES_Pos       (17U)
#define HRTIM_EEFxR3_EEVBCRES_Msk       (0x1UL << HRTIM_EEFxR3_EEVBCRES_Pos)      /*!< 0x00020000 */
#define HRTIM_EEFxR3_EEVBCRES             HRTIM_EEFxR3_EEVBCRES_Msk     /*!< EEVBCRES */
#define HRTIM_EEFxR3_EEVBRSTM_Pos       (18U)
#define HRTIM_EEFxR3_EEVBRSTM_Msk       (0x1UL << HRTIM_EEFxR3_EEVBRSTM_Pos)      /*!< 0x00040000 */
#define HRTIM_EEFxR3_EEVBRSTM             HRTIM_EEFxR3_EEVBRSTM_Msk     /*!< EEVBRSTM */
#define HRTIM_EEFxR3_EEVBSEL_Pos        (20U)
#define HRTIM_EEFxR3_EEVBSEL_Msk        (0xFUL << HRTIM_EEFxR3_EEVBSEL_Pos)     /*!< 0x00F00000 */
#define HRTIM_EEFxR3_EEVBSEL              HRTIM_EEFxR3_EEVBSEL_Msk      /*!< EEVBSEL */
#define HRTIM_EEFxR3_EEVBSEL_0        (0x1UL << HRTIM_EEFxR3_EEVBSEL_Pos)      /*!< 0x00100000 */
#define HRTIM_EEFxR3_EEVBSEL_1        (0x2UL << HRTIM_EEFxR3_EEVBSEL_Pos)      /*!< 0x00200000 */
#define HRTIM_EEFxR3_EEVBSEL_2        (0x4UL << HRTIM_EEFxR3_EEVBSEL_Pos)      /*!< 0x00400000 */
#define HRTIM_EEFxR3_EEVBSEL_3        (0x8UL << HRTIM_EEFxR3_EEVBSEL_Pos)      /*!< 0x00800000 */
#define HRTIM_EEFxR3_EEVBCNT_Pos        (24U)
#define HRTIM_EEFxR3_EEVBCNT_Msk        (0x3FUL << HRTIM_EEFxR3_EEVBCNT_Pos)      /*!< 0x3F000000 */
#define HRTIM_EEFxR3_EEVBCNT              HRTIM_EEFxR3_EEVBCNT_Msk      /*!< EEVBCNT */
#define HRTIM_EEFxR3_EEVBCNT_0        (0x1UL << HRTIM_EEFxR3_EEVBCNT_Pos)       /*!< 0x01000000 */
#define HRTIM_EEFxR3_EEVBCNT_1        (0x2UL << HRTIM_EEFxR3_EEVBCNT_Pos)       /*!< 0x02000000 */
#define HRTIM_EEFxR3_EEVBCNT_2        (0x4UL << HRTIM_EEFxR3_EEVBCNT_Pos)       /*!< 0x04000000 */
#define HRTIM_EEFxR3_EEVBCNT_3        (0x8UL << HRTIM_EEFxR3_EEVBCNT_Pos)       /*!< 0x08000000 */
#define HRTIM_EEFxR3_EEVBCNT_4        (0x10UL << HRTIM_EEFxR3_EEVBCNT_Pos)       /*!< 0x10000000 */
#define HRTIM_EEFxR3_EEVBCNT_5        (0x20UL << HRTIM_EEFxR3_EEVBCNT_Pos)       /*!< 0x20000000 */

/**************  Bit definition for HRTIM_CR1 register  ***************/
#define HRTIM_CR1_MUDIS_Pos            (0U)
#define HRTIM_CR1_MUDIS_Msk            (0x1UL << HRTIM_CR1_MUDIS_Pos) /*!< 0x00000001 */
#define HRTIM_CR1_MUDIS                 HRTIM_CR1_MUDIS_Msk         /*!< MUDIS */
#define HRTIM_CR1_TAUDIS_Pos           (1U)
#define HRTIM_CR1_TAUDIS_Msk           (0x1UL << HRTIM_CR1_TAUDIS_Pos)  /*!< 0x00000002 */
#define HRTIM_CR1_TAUDIS                HRTIM_CR1_TAUDIS_Msk        /*!< TAUDIS */
#define HRTIM_CR1_TBUDIS_Pos           (2U)
#define HRTIM_CR1_TBUDIS_Msk           (0x1UL << HRTIM_CR1_TBUDIS_Pos)  /*!< 0x00000004 */
#define HRTIM_CR1_TBUDIS                HRTIM_CR1_TBUDIS_Msk        /*!< TBUDIS */
#define HRTIM_CR1_TCUDIS_Pos           (3U)
#define HRTIM_CR1_TCUDIS_Msk           (0x1UL << HRTIM_CR1_TCUDIS_Pos)  /*!< 0x00000008 */
#define HRTIM_CR1_TCUDIS                HRTIM_CR1_TCUDIS_Msk        /*!< TCUDIS */
#define HRTIM_CR1_TDUDIS_Pos           (4U)
#define HRTIM_CR1_TDUDIS_Msk           (0x1UL << HRTIM_CR1_TDUDIS_Pos)  /*!< 0x00000010 */
#define HRTIM_CR1_TDUDIS                HRTIM_CR1_TDUDIS_Msk        /*!< TDUDIS */
#define HRTIM_CR1_TEUDIS_Pos           (5U)
#define HRTIM_CR1_TEUDIS_Msk           (0x1UL << HRTIM_CR1_TEUDIS_Pos)  /*!< 0x00000020 */
#define HRTIM_CR1_TEUDIS                HRTIM_CR1_TEUDIS_Msk        /*!< TEUDIS */
#define HRTIM_CR1_TFUDIS_Pos           (6U)
#define HRTIM_CR1_TFUDIS_Msk           (0x1UL << HRTIM_CR1_TFUDIS_Pos)  /*!< 0x00000040 */
#define HRTIM_CR1_TFUDIS                HRTIM_CR1_TFUDIS_Msk        /*!< TFUDIS */
#define HRTIM_CR1_ADC1USRC_Pos         (16U)
#define HRTIM_CR1_ADC1USRC_Msk         (0x7UL << HRTIM_CR1_ADC1USRC_Pos)    /*!< 0x00070000 */
#define HRTIM_CR1_ADC1USRC              HRTIM_CR1_ADC1USRC_Msk      /*!< ADC1USRC */
#define HRTIM_CR1_ADC1USRC_0         (0x1UL << HRTIM_CR1_ADC1USRC_Pos)     /*!< 0x00010000 */
#define HRTIM_CR1_ADC1USRC_1         (0x2UL << HRTIM_CR1_ADC1USRC_Pos)     /*!< 0x00020000 */
#define HRTIM_CR1_ADC1USRC_2         (0x4UL << HRTIM_CR1_ADC1USRC_Pos)     /*!< 0x00040000 */
#define HRTIM_CR1_ADC2USRC_Pos         (19U)
#define HRTIM_CR1_ADC2USRC_Msk         (0x7UL << HRTIM_CR1_ADC2USRC_Pos)    /*!< 0x00380000 */
#define HRTIM_CR1_ADC2USRC              HRTIM_CR1_ADC2USRC_Msk      /*!< ADC2USRC */
#define HRTIM_CR1_ADC2USRC_0         (0x1UL << HRTIM_CR1_ADC2USRC_Pos)     /*!< 0x00080000 */
#define HRTIM_CR1_ADC2USRC_1         (0x2UL << HRTIM_CR1_ADC2USRC_Pos)     /*!< 0x00100000 */
#define HRTIM_CR1_ADC2USRC_2         (0x4UL << HRTIM_CR1_ADC2USRC_Pos)     /*!< 0x00200000 */
#define HRTIM_CR1_ADC3USRC_Pos         (22U)
#define HRTIM_CR1_ADC3USRC_Msk         (0x7UL << HRTIM_CR1_ADC3USRC_Pos)    /*!< 0x01C00000 */
#define HRTIM_CR1_ADC3USRC              HRTIM_CR1_ADC3USRC_Msk      /*!< ADC3USRC */
#define HRTIM_CR1_ADC3USRC_0         (0x1UL << HRTIM_CR1_ADC3USRC_Pos)     /*!< 0x00400000 */
#define HRTIM_CR1_ADC3USRC_1         (0x2UL << HRTIM_CR1_ADC3USRC_Pos)     /*!< 0x00800000 */
#define HRTIM_CR1_ADC3USRC_2         (0x4UL << HRTIM_CR1_ADC3USRC_Pos)     /*!< 0x01000000 */
#define HRTIM_CR1_ADC4USRC_Pos         (25U)
#define HRTIM_CR1_ADC4USRC_Msk         (0x7UL << HRTIM_CR1_ADC4USRC_Pos)    /*!< 0x0E000000 */
#define HRTIM_CR1_ADC4USRC              HRTIM_CR1_ADC4USRC_Msk      /*!< ADC4USRC */
#define HRTIM_CR1_ADC4USRC_0         (0x1UL << HRTIM_CR1_ADC4USRC_Pos)     /*!< 0x02000000 */
#define HRTIM_CR1_ADC4USRC_1         (0x2UL << HRTIM_CR1_ADC4USRC_Pos)     /*!< 0x04000000 */
#define HRTIM_CR1_ADC4USRC_2         (0x4UL << HRTIM_CR1_ADC4USRC_Pos)     /*!< 0x08000000 */

/**************  Bit definition for HRTIM_CR2 register  ***************/
#define HRTIM_CR2_MSWU_Pos             (0U)
#define HRTIM_CR2_MSWU_Msk              (0x1UL << HRTIM_CR2_MSWU_Pos) /*!< 0x00000001 */
#define HRTIM_CR2_MSWU                  HRTIM_CR2_MSWU_Msk          /*!< MSWU */
#define HRTIM_CR2_TASWU_Pos            (1U)
#define HRTIM_CR2_TASWU_Msk            (0x1UL << HRTIM_CR2_TASWU_Pos) /*!< 0x00000002 */
#define HRTIM_CR2_TASWU                 HRTIM_CR2_TASWU_Msk         /*!< TASWU */
#define HRTIM_CR2_TBSWU_Pos            (2U)
#define HRTIM_CR2_TBSWU_Msk            (0x1UL << HRTIM_CR2_TBSWU_Pos) /*!< 0x00000004 */
#define HRTIM_CR2_TBSWU                 HRTIM_CR2_TBSWU_Msk         /*!< TBSWU */
#define HRTIM_CR2_TCSWU_Pos            (3U)
#define HRTIM_CR2_TCSWU_Msk            (0x1UL << HRTIM_CR2_TCSWU_Pos) /*!< 0x00000008 */
#define HRTIM_CR2_TCSWU                 HRTIM_CR2_TCSWU_Msk         /*!< TCSWU */
#define HRTIM_CR2_TDSWU_Pos            (4U)
#define HRTIM_CR2_TDSWU_Msk            (0x1UL << HRTIM_CR2_TDSWU_Pos) /*!< 0x00000010 */
#define HRTIM_CR2_TDSWU                 HRTIM_CR2_TDSWU_Msk         /*!< TDSWU */
#define HRTIM_CR2_TESWU_Pos            (5U)
#define HRTIM_CR2_TESWU_Msk            (0x1UL << HRTIM_CR2_TESWU_Pos) /*!< 0x00000020 */
#define HRTIM_CR2_TESWU                 HRTIM_CR2_TESWU_Msk         /*!< TESWU */
#define HRTIM_CR2_TFSWU_Pos            (6U)
#define HRTIM_CR2_TFSWU_Msk            (0x1UL << HRTIM_CR2_TFSWU_Pos) /*!< 0x00000040 */
#define HRTIM_CR2_TFSWU                 HRTIM_CR2_TFSWU_Msk         /*!< TFSWU */
#define HRTIM_CR2_MRST_Pos             (8U)
#define HRTIM_CR2_MRST_Msk              (0x1UL << HRTIM_CR2_MRST_Pos) /*!< 0x00000100 */
#define HRTIM_CR2_MRST                  HRTIM_CR2_MRST_Msk          /*!< MRST */
#define HRTIM_CR2_TARST_Pos            (9U)
#define HRTIM_CR2_TARST_Msk            (0x1UL << HRTIM_CR2_TARST_Pos) /*!< 0x00000200 */
#define HRTIM_CR2_TARST                 HRTIM_CR2_TARST_Msk         /*!< TARST */
#define HRTIM_CR2_TBRST_Pos            (10U)
#define HRTIM_CR2_TBRST_Msk            (0x1UL << HRTIM_CR2_TBRST_Pos) /*!< 0x00000400 */
#define HRTIM_CR2_TBRST                 HRTIM_CR2_TBRST_Msk         /*!< TBRST */
#define HRTIM_CR2_TCRST_Pos            (11U)
#define HRTIM_CR2_TCRST_Msk            (0x1UL << HRTIM_CR2_TCRST_Pos) /*!< 0x00000800 */
#define HRTIM_CR2_TCRST                 HRTIM_CR2_TCRST_Msk         /*!< TCRST */
#define HRTIM_CR2_TDRST_Pos            (12U)
#define HRTIM_CR2_TDRST_Msk            (0x1UL << HRTIM_CR2_TDRST_Pos) /*!< 0x00001000 */
#define HRTIM_CR2_TDRST                 HRTIM_CR2_TDRST_Msk         /*!< TDRST */
#define HRTIM_CR2_TERST_Pos            (13U)
#define HRTIM_CR2_TERST_Msk            (0x1UL << HRTIM_CR2_TERST_Pos) /*!< 0x00002000 */
#define HRTIM_CR2_TERST                 HRTIM_CR2_TERST_Msk         /*!< TERST */
#define HRTIM_CR2_TFRST_Pos            (14U)
#define HRTIM_CR2_TFRST_Msk            (0x1UL << HRTIM_CR2_TFRST_Pos) /*!< 0x00004000 */
#define HRTIM_CR2_TFRST                 HRTIM_CR2_TFRST_Msk         /*!< TFRST */
#define HRTIM_CR2_SWPA_Pos             (16U)
#define HRTIM_CR2_SWPA_Msk              (0x1UL << HRTIM_CR2_SWPA_Pos) /*!< 0x00010000 */
#define HRTIM_CR2_SWPA                  HRTIM_CR2_SWPA_Msk          /*!< SWPA */
#define HRTIM_CR2_SWPB_Pos             (17U)
#define HRTIM_CR2_SWPB_Msk              (0x1UL << HRTIM_CR2_SWPB_Pos) /*!< 0x00020000 */
#define HRTIM_CR2_SWPB                  HRTIM_CR2_SWPB_Msk          /*!< SWPB */
#define HRTIM_CR2_SWPC_Pos             (18U)
#define HRTIM_CR2_SWPC_Msk              (0x1UL << HRTIM_CR2_SWPC_Pos) /*!< 0x00040000 */
#define HRTIM_CR2_SWPC                  HRTIM_CR2_SWPC_Msk          /*!< SWPC */
#define HRTIM_CR2_SWPD_Pos             (19U)
#define HRTIM_CR2_SWPD_Msk              (0x1UL << HRTIM_CR2_SWPD_Pos) /*!< 0x00080000 */
#define HRTIM_CR2_SWPD                  HRTIM_CR2_SWPD_Msk          /*!< SWPD */
#define HRTIM_CR2_SWPE_Pos             (20U)
#define HRTIM_CR2_SWPE_Msk              (0x1UL << HRTIM_CR2_SWPE_Pos) /*!< 0x00100000 */
#define HRTIM_CR2_SWPE                  HRTIM_CR2_SWPE_Msk          /*!< SWPE */
#define HRTIM_CR2_SWPF_Pos             (21U)
#define HRTIM_CR2_SWPF_Msk              (0x1UL << HRTIM_CR2_SWPF_Pos) /*!< 0x00200000 */
#define HRTIM_CR2_SWPF                  HRTIM_CR2_SWPF_Msk          /*!< SWPF */

/**************  Bit definition for HRTIM_ISR register  ***************/
#define HRTIM_ISR_FLT1_Pos             (0U)
#define HRTIM_ISR_FLT1_Msk              (0x1UL << HRTIM_ISR_FLT1_Pos) /*!< 0x00000001 */
#define HRTIM_ISR_FLT1                  HRTIM_ISR_FLT1_Msk          /*!< FLT1 */
#define HRTIM_ISR_FLT2_Pos             (1U)
#define HRTIM_ISR_FLT2_Msk              (0x1UL << HRTIM_ISR_FLT2_Pos) /*!< 0x00000002 */
#define HRTIM_ISR_FLT2                  HRTIM_ISR_FLT2_Msk          /*!< FLT2 */
#define HRTIM_ISR_FLT3_Pos             (2U)
#define HRTIM_ISR_FLT3_Msk              (0x1UL << HRTIM_ISR_FLT3_Pos) /*!< 0x00000004 */
#define HRTIM_ISR_FLT3                  HRTIM_ISR_FLT3_Msk          /*!< FLT3 */
#define HRTIM_ISR_FLT4_Pos             (3U)
#define HRTIM_ISR_FLT4_Msk              (0x1UL << HRTIM_ISR_FLT4_Pos) /*!< 0x00000008 */
#define HRTIM_ISR_FLT4                  HRTIM_ISR_FLT4_Msk          /*!< FLT4 */
#define HRTIM_ISR_FLT5_Pos             (4U)
#define HRTIM_ISR_FLT5_Msk              (0x1UL << HRTIM_ISR_FLT5_Pos) /*!< 0x00000010 */
#define HRTIM_ISR_FLT5                  HRTIM_ISR_FLT5_Msk          /*!< FLT5 */
#define HRTIM_ISR_SYSFLT_Pos           (5U)
#define HRTIM_ISR_SYSFLT_Msk           (0x1UL << HRTIM_ISR_SYSFLT_Pos)  /*!< 0x00000020 */
#define HRTIM_ISR_SYSFLT                HRTIM_ISR_SYSFLT_Msk        /*!< SYSFLT */
#define HRTIM_ISR_FLT6_Pos             (6U)
#define HRTIM_ISR_FLT6_Msk              (0x1UL << HRTIM_ISR_FLT6_Pos) /*!< 0x00000040 */
#define HRTIM_ISR_FLT6                  HRTIM_ISR_FLT6_Msk          /*!< FLT6 */
#define HRTIM_ISR_DLLRDY_Pos           (16U)
#define HRTIM_ISR_DLLRDY_Msk           (0x1UL << HRTIM_ISR_DLLRDY_Pos)  /*!< 0x00010000 */
#define HRTIM_ISR_DLLRDY                HRTIM_ISR_DLLRDY_Msk        /*!< DLLRDY */
#define HRTIM_ISR_BMPER_Pos            (17U)
#define HRTIM_ISR_BMPER_Msk            (0x1UL << HRTIM_ISR_BMPER_Pos) /*!< 0x00020000 */
#define HRTIM_ISR_BMPER                 HRTIM_ISR_BMPER_Msk         /*!< BMPER */

/**************  Bit definition for HRTIM_ICR register  ***************/
#define HRTIM_ICR_FLT1C_Pos            (0U)
#define HRTIM_ICR_FLT1C_Msk            (0x1UL << HRTIM_ICR_FLT1C_Pos) /*!< 0x00000001 */
#define HRTIM_ICR_FLT1C                 HRTIM_ICR_FLT1C_Msk         /*!< FLT1C */
#define HRTIM_ICR_FLT2C_Pos            (1U)
#define HRTIM_ICR_FLT2C_Msk            (0x1UL << HRTIM_ICR_FLT2C_Pos) /*!< 0x00000002 */
#define HRTIM_ICR_FLT2C                 HRTIM_ICR_FLT2C_Msk         /*!< FLT2C */
#define HRTIM_ICR_FLT3C_Pos            (2U)
#define HRTIM_ICR_FLT3C_Msk            (0x1UL << HRTIM_ICR_FLT3C_Pos) /*!< 0x00000004 */
#define HRTIM_ICR_FLT3C                 HRTIM_ICR_FLT3C_Msk         /*!< FLT3C */
#define HRTIM_ICR_FLT4C_Pos            (3U)
#define HRTIM_ICR_FLT4C_Msk            (0x1UL << HRTIM_ICR_FLT4C_Pos) /*!< 0x00000008 */
#define HRTIM_ICR_FLT4C                 HRTIM_ICR_FLT4C_Msk         /*!< FLT4C */
#define HRTIM_ICR_FLT5C_Pos            (4U)
#define HRTIM_ICR_FLT5C_Msk            (0x1UL << HRTIM_ICR_FLT5C_Pos) /*!< 0x00000010 */
#define HRTIM_ICR_FLT5C                 HRTIM_ICR_FLT5C_Msk         /*!< FLT5C */
#define HRTIM_ICR_SYSFLTC_Pos          (5U)
#define HRTIM_ICR_SYSFLTC_Msk          (0x1UL << HRTIM_ICR_SYSFLTC_Pos)   /*!< 0x00000020 */
#define HRTIM_ICR_SYSFLTC               HRTIM_ICR_SYSFLTC_Msk       /*!< SYSFLTC */
#define HRTIM_ICR_FLT6C_Pos            (6U)
#define HRTIM_ICR_FLT6C_Msk            (0x1UL << HRTIM_ICR_FLT6C_Pos) /*!< 0x00000040 */
#define HRTIM_ICR_FLT6C                 HRTIM_ICR_FLT6C_Msk         /*!< FLT6C */
#define HRTIM_ICR_DLLRDYC_Pos          (16U)
#define HRTIM_ICR_DLLRDYC_Msk          (0x1UL << HRTIM_ICR_DLLRDYC_Pos)   /*!< 0x00010000 */
#define HRTIM_ICR_DLLRDYC               HRTIM_ICR_DLLRDYC_Msk       /*!< DLLRDYC */
#define HRTIM_ICR_BMPERC_Pos           (17U)
#define HRTIM_ICR_BMPERC_Msk           (0x1UL << HRTIM_ICR_BMPERC_Pos)  /*!< 0x00020000 */
#define HRTIM_ICR_BMPERC                HRTIM_ICR_BMPERC_Msk        /*!< BMPERC */

/**************  Bit definition for HRTIM_IER register  ***************/
#define HRTIM_IER_FLT1_Pos             (0U)
#define HRTIM_IER_FLT1_Msk              (0x1UL << HRTIM_IER_FLT1_Pos) /*!< 0x00000001 */
#define HRTIM_IER_FLT1                  HRTIM_IER_FLT1_Msk          /*!< FLT1 */
#define HRTIM_IER_FLT2_Pos             (1U)
#define HRTIM_IER_FLT2_Msk              (0x1UL << HRTIM_IER_FLT2_Pos) /*!< 0x00000002 */
#define HRTIM_IER_FLT2                  HRTIM_IER_FLT2_Msk          /*!< FLT2 */
#define HRTIM_IER_FLT3_Pos             (2U)
#define HRTIM_IER_FLT3_Msk              (0x1UL << HRTIM_IER_FLT3_Pos) /*!< 0x00000004 */
#define HRTIM_IER_FLT3                  HRTIM_IER_FLT3_Msk          /*!< FLT3 */
#define HRTIM_IER_FLT4_Pos             (3U)
#define HRTIM_IER_FLT4_Msk              (0x1UL << HRTIM_IER_FLT4_Pos) /*!< 0x00000008 */
#define HRTIM_IER_FLT4                  HRTIM_IER_FLT4_Msk          /*!< FLT4 */
#define HRTIM_IER_FLT5_Pos             (4U)
#define HRTIM_IER_FLT5_Msk              (0x1UL << HRTIM_IER_FLT5_Pos) /*!< 0x00000010 */
#define HRTIM_IER_FLT5                  HRTIM_IER_FLT5_Msk          /*!< FLT5 */
#define HRTIM_IER_SYSFLT_Pos           (5U)
#define HRTIM_IER_SYSFLT_Msk           (0x1UL << HRTIM_IER_SYSFLT_Pos)  /*!< 0x00000020 */
#define HRTIM_IER_SYSFLT                HRTIM_IER_SYSFLT_Msk        /*!< SYSFLT */
#define HRTIM_IER_FLT6_Pos             (6U)
#define HRTIM_IER_FLT6_Msk              (0x1UL << HRTIM_IER_FLT6_Pos) /*!< 0x00000040 */
#define HRTIM_IER_FLT6                  HRTIM_IER_FLT6_Msk          /*!< FLT6 */
#define HRTIM_IER_DLLRDY_Pos           (16U)
#define HRTIM_IER_DLLRDY_Msk           (0x1UL << HRTIM_IER_DLLRDY_Pos)  /*!< 0x00010000 */
#define HRTIM_IER_DLLRDY                HRTIM_IER_DLLRDY_Msk        /*!< DLLRDY */
#define HRTIM_IER_BMPER_Pos            (17U)
#define HRTIM_IER_BMPER_Msk            (0x1UL << HRTIM_IER_BMPER_Pos) /*!< 0x00020000 */
#define HRTIM_IER_BMPER                 HRTIM_IER_BMPER_Msk         /*!< BMPER */

/**************  Bit definition for HRTIM_OENR register  **************/
#define HRTIM_OENR_TA1OEN_Pos          (0U)
#define HRTIM_OENR_TA1OEN_Msk          (0x1UL << HRTIM_OENR_TA1OEN_Pos)   /*!< 0x00000001 */
#define HRTIM_OENR_TA1OEN               HRTIM_OENR_TA1OEN_Msk       /*!< TA1OEN */
#define HRTIM_OENR_TA2OEN_Pos          (1U)
#define HRTIM_OENR_TA2OEN_Msk          (0x1UL << HRTIM_OENR_TA2OEN_Pos)   /*!< 0x00000002 */
#define HRTIM_OENR_TA2OEN               HRTIM_OENR_TA2OEN_Msk       /*!< TA2OEN */
#define HRTIM_OENR_TB1OEN_Pos          (2U)
#define HRTIM_OENR_TB1OEN_Msk          (0x1UL << HRTIM_OENR_TB1OEN_Pos)   /*!< 0x00000004 */
#define HRTIM_OENR_TB1OEN               HRTIM_OENR_TB1OEN_Msk       /*!< TB1OEN */
#define HRTIM_OENR_TB2OEN_Pos          (3U)
#define HRTIM_OENR_TB2OEN_Msk          (0x1UL << HRTIM_OENR_TB2OEN_Pos)   /*!< 0x00000008 */
#define HRTIM_OENR_TB2OEN               HRTIM_OENR_TB2OEN_Msk       /*!< TB2OEN */
#define HRTIM_OENR_TC1OEN_Pos          (4U)
#define HRTIM_OENR_TC1OEN_Msk          (0x1UL << HRTIM_OENR_TC1OEN_Pos)   /*!< 0x00000010 */
#define HRTIM_OENR_TC1OEN               HRTIM_OENR_TC1OEN_Msk       /*!< TC1OEN */
#define HRTIM_OENR_TC2OEN_Pos          (5U)
#define HRTIM_OENR_TC2OEN_Msk          (0x1UL << HRTIM_OENR_TC2OEN_Pos)   /*!< 0x00000020 */
#define HRTIM_OENR_TC2OEN               HRTIM_OENR_TC2OEN_Msk       /*!< TC2OEN */
#define HRTIM_OENR_TD1OEN_Pos          (6U)
#define HRTIM_OENR_TD1OEN_Msk          (0x1UL << HRTIM_OENR_TD1OEN_Pos)   /*!< 0x00000040 */
#define HRTIM_OENR_TD1OEN               HRTIM_OENR_TD1OEN_Msk       /*!< TD1OEN */
#define HRTIM_OENR_TD2OEN_Pos          (7U)
#define HRTIM_OENR_TD2OEN_Msk          (0x1UL << HRTIM_OENR_TD2OEN_Pos)   /*!< 0x00000080 */
#define HRTIM_OENR_TD2OEN               HRTIM_OENR_TD2OEN_Msk       /*!< TD2OEN */
#define HRTIM_OENR_TE1OEN_Pos          (8U)
#define HRTIM_OENR_TE1OEN_Msk          (0x1UL << HRTIM_OENR_TE1OEN_Pos)   /*!< 0x00000100 */
#define HRTIM_OENR_TE1OEN               HRTIM_OENR_TE1OEN_Msk       /*!< TE1OEN */
#define HRTIM_OENR_TE2OEN_Pos          (9U)
#define HRTIM_OENR_TE2OEN_Msk          (0x1UL << HRTIM_OENR_TE2OEN_Pos)   /*!< 0x00000200 */
#define HRTIM_OENR_TE2OEN               HRTIM_OENR_TE2OEN_Msk       /*!< TE2OEN */
#define HRTIM_OENR_TF1OEN_Pos          (10U)
#define HRTIM_OENR_TF1OEN_Msk          (0x1UL << HRTIM_OENR_TF1OEN_Pos)   /*!< 0x00000400 */
#define HRTIM_OENR_TF1OEN               HRTIM_OENR_TF1OEN_Msk       /*!< TF1OEN */
#define HRTIM_OENR_TF2OEN_Pos          (11U)
#define HRTIM_OENR_TF2OEN_Msk          (0x1UL << HRTIM_OENR_TF2OEN_Pos)   /*!< 0x00000800 */
#define HRTIM_OENR_TF2OEN               HRTIM_OENR_TF2OEN_Msk       /*!< TF2OEN */

/*************  Bit definition for HRTIM_ODISR register  **************/
#define HRTIM_ODISR_TA1ODIS_Pos        (0U)
#define HRTIM_ODISR_TA1ODIS_Msk        (0x1UL << HRTIM_ODISR_TA1ODIS_Pos)     /*!< 0x00000001 */
#define HRTIM_ODISR_TA1ODIS             HRTIM_ODISR_TA1ODIS_Msk     /*!< TA1ODIS */
#define HRTIM_ODISR_TA2ODIS_Pos        (1U)
#define HRTIM_ODISR_TA2ODIS_Msk        (0x1UL << HRTIM_ODISR_TA2ODIS_Pos)     /*!< 0x00000002 */
#define HRTIM_ODISR_TA2ODIS             HRTIM_ODISR_TA2ODIS_Msk     /*!< TA2ODIS */
#define HRTIM_ODISR_TB1ODIS_Pos        (2U)
#define HRTIM_ODISR_TB1ODIS_Msk        (0x1UL << HRTIM_ODISR_TB1ODIS_Pos)     /*!< 0x00000004 */
#define HRTIM_ODISR_TB1ODIS             HRTIM_ODISR_TB1ODIS_Msk     /*!< TB1ODIS */
#define HRTIM_ODISR_TB2ODIS_Pos        (3U)
#define HRTIM_ODISR_TB2ODIS_Msk        (0x1UL << HRTIM_ODISR_TB2ODIS_Pos)     /*!< 0x00000008 */
#define HRTIM_ODISR_TB2ODIS             HRTIM_ODISR_TB2ODIS_Msk     /*!< TB2ODIS */
#define HRTIM_ODISR_TC1ODIS_Pos        (4U)
#define HRTIM_ODISR_TC1ODIS_Msk        (0x1UL << HRTIM_ODISR_TC1ODIS_Pos)     /*!< 0x00000010 */
#define HRTIM_ODISR_TC1ODIS             HRTIM_ODISR_TC1ODIS_Msk     /*!< TC1ODIS */
#define HRTIM_ODISR_TC2ODIS_Pos        (5U)
#define HRTIM_ODISR_TC2ODIS_Msk        (0x1UL << HRTIM_ODISR_TC2ODIS_Pos)     /*!< 0x00000020 */
#define HRTIM_ODISR_TC2ODIS             HRTIM_ODISR_TC2ODIS_Msk     /*!< TC2ODIS */
#define HRTIM_ODISR_TD1ODIS_Pos        (6U)
#define HRTIM_ODISR_TD1ODIS_Msk        (0x1UL << HRTIM_ODISR_TD1ODIS_Pos)     /*!< 0x00000040 */
#define HRTIM_ODISR_TD1ODIS             HRTIM_ODISR_TD1ODIS_Msk     /*!< TD1ODIS */
#define HRTIM_ODISR_TD2ODIS_Pos        (7U)
#define HRTIM_ODISR_TD2ODIS_Msk        (0x1UL << HRTIM_ODISR_TD2ODIS_Pos)     /*!< 0x00000080 */
#define HRTIM_ODISR_TD2ODIS             HRTIM_ODISR_TD2ODIS_Msk     /*!< TD2ODIS */
#define HRTIM_ODISR_TE1ODIS_Pos        (8U)
#define HRTIM_ODISR_TE1ODIS_Msk        (0x1UL << HRTIM_ODISR_TE1ODIS_Pos)     /*!< 0x00000100 */
#define HRTIM_ODISR_TE1ODIS             HRTIM_ODISR_TE1ODIS_Msk     /*!< TE1ODIS */
#define HRTIM_ODISR_TE2ODIS_Pos        (9U)
#define HRTIM_ODISR_TE2ODIS_Msk        (0x1UL << HRTIM_ODISR_TE2ODIS_Pos)     /*!< 0x00000200 */
#define HRTIM_ODISR_TE2ODIS             HRTIM_ODISR_TE2ODIS_Msk     /*!< TE2ODIS */
#define HRTIM_ODISR_TF1ODIS_Pos        (10U)
#define HRTIM_ODISR_TF1ODIS_Msk        (0x1UL << HRTIM_ODISR_TF1ODIS_Pos)     /*!< 0x00000400 */
#define HRTIM_ODISR_TF1ODIS             HRTIM_ODISR_TF1ODIS_Msk     /*!< TF1ODIS */
#define HRTIM_ODISR_TF2ODIS_Pos        (11U)
#define HRTIM_ODISR_TF2ODIS_Msk        (0x1UL << HRTIM_ODISR_TF2ODIS_Pos)     /*!< 0x00000800 */
#define HRTIM_ODISR_TF2ODIS             HRTIM_ODISR_TF2ODIS_Msk     /*!< TF2ODIS */

/**************  Bit definition for HRTIM_ODSR register  **************/
#define HRTIM_ODSR_TA1ODS_Pos          (0U)
#define HRTIM_ODSR_TA1ODS_Msk          (0x1UL << HRTIM_ODSR_TA1ODS_Pos)   /*!< 0x00000001 */
#define HRTIM_ODSR_TA1ODS               HRTIM_ODSR_TA1ODS_Msk       /*!< TA1ODS */
#define HRTIM_ODSR_TA2ODS_Pos          (1U)
#define HRTIM_ODSR_TA2ODS_Msk          (0x1UL << HRTIM_ODSR_TA2ODS_Pos)   /*!< 0x00000002 */
#define HRTIM_ODSR_TA2ODS               HRTIM_ODSR_TA2ODS_Msk       /*!< TA2ODS */
#define HRTIM_ODSR_TB1ODS_Pos          (2U)
#define HRTIM_ODSR_TB1ODS_Msk          (0x1UL << HRTIM_ODSR_TB1ODS_Pos)   /*!< 0x00000004 */
#define HRTIM_ODSR_TB1ODS               HRTIM_ODSR_TB1ODS_Msk       /*!< TB1ODS */
#define HRTIM_ODSR_TB2ODS_Pos          (3U)
#define HRTIM_ODSR_TB2ODS_Msk          (0x1UL << HRTIM_ODSR_TB2ODS_Pos)   /*!< 0x00000008 */
#define HRTIM_ODSR_TB2ODS               HRTIM_ODSR_TB2ODS_Msk       /*!< TB2ODS */
#define HRTIM_ODSR_TC1ODS_Pos          (4U)
#define HRTIM_ODSR_TC1ODS_Msk          (0x1UL << HRTIM_ODSR_TC1ODS_Pos)   /*!< 0x00000010 */
#define HRTIM_ODSR_TC1ODS               HRTIM_ODSR_TC1ODS_Msk       /*!< TC1ODS */
#define HRTIM_ODSR_TC2ODS_Pos          (5U)
#define HRTIM_ODSR_TC2ODS_Msk          (0x1UL << HRTIM_ODSR_TC2ODS_Pos)   /*!< 0x00000020 */
#define HRTIM_ODSR_TC2ODS               HRTIM_ODSR_TC2ODS_Msk       /*!< TC2ODS */
#define HRTIM_ODSR_TD1ODS_Pos          (6U)
#define HRTIM_ODSR_TD1ODS_Msk          (0x1UL << HRTIM_ODSR_TD1ODS_Pos)   /*!< 0x00000040 */
#define HRTIM_ODSR_TD1ODS               HRTIM_ODSR_TD1ODS_Msk       /*!< TD1ODS */
#define HRTIM_ODSR_TD2ODS_Pos          (7U)
#define HRTIM_ODSR_TD2ODS_Msk          (0x1UL << HRTIM_ODSR_TD2ODS_Pos)   /*!< 0x00000080 */
#define HRTIM_ODSR_TD2ODS               HRTIM_ODSR_TD2ODS_Msk       /*!< TD2ODS */
#define HRTIM_ODSR_TE1ODS_Pos          (8U)
#define HRTIM_ODSR_TE1ODS_Msk          (0x1UL << HRTIM_ODSR_TE1ODS_Pos)   /*!< 0x00000100 */
#define HRTIM_ODSR_TE1ODS               HRTIM_ODSR_TE1ODS_Msk       /*!< TE1ODS */
#define HRTIM_ODSR_TE2ODS_Pos          (9U)
#define HRTIM_ODSR_TE2ODS_Msk          (0x1UL << HRTIM_ODSR_TE2ODS_Pos)   /*!< 0x00000200 */
#define HRTIM_ODSR_TE2ODS               HRTIM_ODSR_TE2ODS_Msk       /*!< TE2ODS */
#define HRTIM_ODSR_TF1ODS_Pos          (10U)
#define HRTIM_ODSR_TF1ODS_Msk          (0x1UL << HRTIM_ODSR_TF1ODS_Pos)   /*!< 0x00000400 */
#define HRTIM_ODSR_TF1ODS               HRTIM_ODSR_TF1ODS_Msk       /*!< TF1ODS */
#define HRTIM_ODSR_TF2ODS_Pos          (11U)
#define HRTIM_ODSR_TF2ODS_Msk          (0x1UL << HRTIM_ODSR_TF2ODS_Pos)   /*!< 0x00000800 */
#define HRTIM_ODSR_TF2ODS               HRTIM_ODSR_TF2ODS_Msk       /*!< TF2ODS */

/**************  Bit definition for HRTIM_BMCR register  **************/
#define HRTIM_BMCR_BME_Pos             (0U)
#define HRTIM_BMCR_BME_Msk              (0x1UL << HRTIM_BMCR_BME_Pos) /*!< 0x00000001 */
#define HRTIM_BMCR_BME                  HRTIM_BMCR_BME_Msk          /*!< BME */
#define HRTIM_BMCR_BMOM_Pos            (1U)
#define HRTIM_BMCR_BMOM_Msk            (0x1UL << HRTIM_BMCR_BMOM_Pos) /*!< 0x00000002 */
#define HRTIM_BMCR_BMOM                 HRTIM_BMCR_BMOM_Msk         /*!< BMOM */
#define HRTIM_BMCR_BMCLK_Pos           (2U)
#define HRTIM_BMCR_BMCLK_Msk           (0xFUL << HRTIM_BMCR_BMCLK_Pos)  /*!< 0x0000003C */
#define HRTIM_BMCR_BMCLK                HRTIM_BMCR_BMCLK_Msk        /*!< BMCLK */
#define HRTIM_BMCR_BMCLK_0           (0x1UL << HRTIM_BMCR_BMCLK_Pos)   /*!< 0x00000004 */
#define HRTIM_BMCR_BMCLK_1           (0x2UL << HRTIM_BMCR_BMCLK_Pos)   /*!< 0x00000008 */
#define HRTIM_BMCR_BMCLK_2           (0x4UL << HRTIM_BMCR_BMCLK_Pos)   /*!< 0x00000010 */
#define HRTIM_BMCR_BMCLK_3           (0x8UL << HRTIM_BMCR_BMCLK_Pos)   /*!< 0x00000020 */
#define HRTIM_BMCR_BMPRSC_Pos          (6U)
#define HRTIM_BMCR_BMPRSC_Msk          (0xFUL << HRTIM_BMCR_BMPRSC_Pos)   /*!< 0x000003C0 */
#define HRTIM_BMCR_BMPRSC               HRTIM_BMCR_BMPRSC_Msk       /*!< BMPRSC */
#define HRTIM_BMCR_BMPRSC_0          (0x1UL << HRTIM_BMCR_BMPRSC_Pos)    /*!< 0x00000040 */
#define HRTIM_BMCR_BMPRSC_1          (0x2UL << HRTIM_BMCR_BMPRSC_Pos)    /*!< 0x00000080 */
#define HRTIM_BMCR_BMPRSC_2          (0x4UL << HRTIM_BMCR_BMPRSC_Pos)    /*!< 0x00000100 */
#define HRTIM_BMCR_BMPRSC_3          (0x8UL << HRTIM_BMCR_BMPRSC_Pos)    /*!< 0x00000200 */
#define HRTIM_BMCR_BMPREN_Pos          (10U)
#define HRTIM_BMCR_BMPREN_Msk          (0x1UL << HRTIM_BMCR_BMPREN_Pos)   /*!< 0x00000400 */
#define HRTIM_BMCR_BMPREN               HRTIM_BMCR_BMPREN_Msk       /*!< BMPREN */
#define HRTIM_BMCR_MTBM_Pos            (16U)
#define HRTIM_BMCR_MTBM_Msk            (0x1UL << HRTIM_BMCR_MTBM_Pos) /*!< 0x00010000 */
#define HRTIM_BMCR_MTBM                 HRTIM_BMCR_MTBM_Msk         /*!< MTBM */
#define HRTIM_BMCR_TABM_Pos            (17U)
#define HRTIM_BMCR_TABM_Msk            (0x1UL << HRTIM_BMCR_TABM_Pos) /*!< 0x00020000 */
#define HRTIM_BMCR_TABM                 HRTIM_BMCR_TABM_Msk         /*!< TABM */
#define HRTIM_BMCR_TBBM_Pos            (18U)
#define HRTIM_BMCR_TBBM_Msk            (0x1UL << HRTIM_BMCR_TBBM_Pos) /*!< 0x00040000 */
#define HRTIM_BMCR_TBBM                 HRTIM_BMCR_TBBM_Msk         /*!< TBBM */
#define HRTIM_BMCR_TCBM_Pos            (19U)
#define HRTIM_BMCR_TCBM_Msk            (0x1UL << HRTIM_BMCR_TCBM_Pos) /*!< 0x00080000 */
#define HRTIM_BMCR_TCBM                 HRTIM_BMCR_TCBM_Msk         /*!< TCBM */
#define HRTIM_BMCR_TDBM_Pos            (20U)
#define HRTIM_BMCR_TDBM_Msk            (0x1UL << HRTIM_BMCR_TDBM_Pos) /*!< 0x00100000 */
#define HRTIM_BMCR_TDBM                 HRTIM_BMCR_TDBM_Msk         /*!< TDBM */
#define HRTIM_BMCR_TEBM_Pos            (21U)
#define HRTIM_BMCR_TEBM_Msk            (0x1UL << HRTIM_BMCR_TEBM_Pos) /*!< 0x00200000 */
#define HRTIM_BMCR_TEBM                 HRTIM_BMCR_TEBM_Msk         /*!< TEBM */
#define HRTIM_BMCR_TFBM_Pos            (22U)
#define HRTIM_BMCR_TFBM_Msk            (0x1UL << HRTIM_BMCR_TFBM_Pos) /*!< 0x00400000 */
#define HRTIM_BMCR_TFBM                 HRTIM_BMCR_TFBM_Msk         /*!< TFBM */
#define HRTIM_BMCR_BMSTAT_Pos          (31U)
#define HRTIM_BMCR_BMSTAT_Msk          (0x1UL << HRTIM_BMCR_BMSTAT_Pos)   /*!< 0x80000000 */
#define HRTIM_BMCR_BMSTAT               HRTIM_BMCR_BMSTAT_Msk       /*!< BMSTAT */

/*************  Bit definition for HRTIM_BMTRGR register  *************/
#define HRTIM_BMTRGR_SW_Pos            (0U)
#define HRTIM_BMTRGR_SW_Msk            (0x1UL << HRTIM_BMTRGR_SW_Pos) /*!< 0x00000001 */
#define HRTIM_BMTRGR_SW                 HRTIM_BMTRGR_SW_Msk         /*!< SW */
#define HRTIM_BMTRGR_MSTRST_Pos        (1U)
#define HRTIM_BMTRGR_MSTRST_Msk        (0x1UL << HRTIM_BMTRGR_MSTRST_Pos)     /*!< 0x00000002 */
#define HRTIM_BMTRGR_MSTRST             HRTIM_BMTRGR_MSTRST_Msk     /*!< MSTRST */
#define HRTIM_BMTRGR_MSTREP_Pos        (2U)
#define HRTIM_BMTRGR_MSTREP_Msk        (0x1UL << HRTIM_BMTRGR_MSTREP_Pos)     /*!< 0x00000004 */
#define HRTIM_BMTRGR_MSTREP             HRTIM_BMTRGR_MSTREP_Msk     /*!< MSTREP */
#define HRTIM_BMTRGR_MSTCMP1_Pos       (3U)
#define HRTIM_BMTRGR_MSTCMP1_Msk       (0x1UL << HRTIM_BMTRGR_MSTCMP1_Pos)      /*!< 0x00000008 */
#define HRTIM_BMTRGR_MSTCMP1            HRTIM_BMTRGR_MSTCMP1_Msk    /*!< MSTCMP1 */
#define HRTIM_BMTRGR_MSTCMP2_Pos       (4U)
#define HRTIM_BMTRGR_MSTCMP2_Msk       (0x1UL << HRTIM_BMTRGR_MSTCMP2_Pos)      /*!< 0x00000010 */
#define HRTIM_BMTRGR_MSTCMP2            HRTIM_BMTRGR_MSTCMP2_Msk    /*!< MSTCMP2 */
#define HRTIM_BMTRGR_MSTCMP3_Pos       (5U)
#define HRTIM_BMTRGR_MSTCMP3_Msk       (0x1UL << HRTIM_BMTRGR_MSTCMP3_Pos)      /*!< 0x00000020 */
#define HRTIM_BMTRGR_MSTCMP3            HRTIM_BMTRGR_MSTCMP3_Msk    /*!< MSTCMP3 */
#define HRTIM_BMTRGR_MSTCMP4_Pos       (6U)
#define HRTIM_BMTRGR_MSTCMP4_Msk       (0x1UL << HRTIM_BMTRGR_MSTCMP4_Pos)      /*!< 0x00000040 */
#define HRTIM_BMTRGR_MSTCMP4            HRTIM_BMTRGR_MSTCMP4_Msk    /*!< MSTCMP4 */
#define HRTIM_BMTRGR_TARST_Pos         (7U)
#define HRTIM_BMTRGR_TARST_Msk         (0x1UL << HRTIM_BMTRGR_TARST_Pos)    /*!< 0x00000080 */
#define HRTIM_BMTRGR_TARST              HRTIM_BMTRGR_TARST_Msk      /*!< TARST */
#define HRTIM_BMTRGR_TAREP_Pos         (8U)
#define HRTIM_BMTRGR_TAREP_Msk         (0x1UL << HRTIM_BMTRGR_TAREP_Pos)    /*!< 0x00000100 */
#define HRTIM_BMTRGR_TAREP              HRTIM_BMTRGR_TAREP_Msk      /*!< TAREP */
#define HRTIM_BMTRGR_TACMP1_Pos        (9U)
#define HRTIM_BMTRGR_TACMP1_Msk        (0x1UL << HRTIM_BMTRGR_TACMP1_Pos)     /*!< 0x00000200 */
#define HRTIM_BMTRGR_TACMP1             HRTIM_BMTRGR_TACMP1_Msk     /*!< TACMP1 */
#define HRTIM_BMTRGR_TACMP2_Pos        (10U)
#define HRTIM_BMTRGR_TACMP2_Msk        (0x1UL << HRTIM_BMTRGR_TACMP2_Pos)     /*!< 0x00000400 */
#define HRTIM_BMTRGR_TACMP2             HRTIM_BMTRGR_TACMP2_Msk     /*!< TACMP2 */
#define HRTIM_BMTRGR_TBRST_Pos         (11U)
#define HRTIM_BMTRGR_TBRST_Msk         (0x1UL << HRTIM_BMTRGR_TBRST_Pos)    /*!< 0x00000800 */
#define HRTIM_BMTRGR_TBRST              HRTIM_BMTRGR_TBRST_Msk      /*!< TBRST */
#define HRTIM_BMTRGR_TBREP_Pos         (12U)
#define HRTIM_BMTRGR_TBREP_Msk         (0x1UL << HRTIM_BMTRGR_TBREP_Pos)    /*!< 0x00001000 */
#define HRTIM_BMTRGR_TBREP              HRTIM_BMTRGR_TBREP_Msk      /*!< TBREP */
#define HRTIM_BMTRGR_TBCMP1_Pos        (13U)
#define HRTIM_BMTRGR_TBCMP1_Msk        (0x1UL << HRTIM_BMTRGR_TBCMP1_Pos)     /*!< 0x00002000 */
#define HRTIM_BMTRGR_TBCMP1             HRTIM_BMTRGR_TBCMP1_Msk     /*!< TBCMP1 */
#define HRTIM_BMTRGR_TBCMP2_Pos        (14U)
#define HRTIM_BMTRGR_TBCMP2_Msk        (0x1UL << HRTIM_BMTRGR_TBCMP2_Pos)     /*!< 0x00004000 */
#define HRTIM_BMTRGR_TBCMP2             HRTIM_BMTRGR_TBCMP2_Msk     /*!< TBCMP2 */
#define HRTIM_BMTRGR_TCRST_Pos         (15U)
#define HRTIM_BMTRGR_TCRST_Msk         (0x1UL << HRTIM_BMTRGR_TCRST_Pos)    /*!< 0x00008000 */
#define HRTIM_BMTRGR_TCRST              HRTIM_BMTRGR_TCRST_Msk      /*!< TCRST */
#define HRTIM_BMTRGR_TCREP_Pos         (16U)
#define HRTIM_BMTRGR_TCREP_Msk         (0x1UL << HRTIM_BMTRGR_TCREP_Pos)    /*!< 0x00010000 */
#define HRTIM_BMTRGR_TCREP              HRTIM_BMTRGR_TCREP_Msk      /*!< TCREP */
#define HRTIM_BMTRGR_TCCMP1_Pos        (17U)
#define HRTIM_BMTRGR_TCCMP1_Msk        (0x1UL << HRTIM_BMTRGR_TCCMP1_Pos)     /*!< 0x00020000 */
#define HRTIM_BMTRGR_TCCMP1             HRTIM_BMTRGR_TCCMP1_Msk     /*!< TCCMP1 */
#define HRTIM_BMTRGR_TFRST_Pos         (18U)
#define HRTIM_BMTRGR_TFRST_Msk         (0x1UL << HRTIM_BMTRGR_TFRST_Pos)    /*!< 0x00040000 */
#define HRTIM_BMTRGR_TFRST              HRTIM_BMTRGR_TFRST_Msk      /*!< TFRST */
#define HRTIM_BMTRGR_TDRST_Pos         (19U)
#define HRTIM_BMTRGR_TDRST_Msk         (0x1UL << HRTIM_BMTRGR_TDRST_Pos)    /*!< 0x00080000 */
#define HRTIM_BMTRGR_TDRST              HRTIM_BMTRGR_TDRST_Msk      /*!< TDRST */
#define HRTIM_BMTRGR_TDREP_Pos         (20U)
#define HRTIM_BMTRGR_TDREP_Msk         (0x1UL << HRTIM_BMTRGR_TDREP_Pos)    /*!< 0x00100000 */
#define HRTIM_BMTRGR_TDREP              HRTIM_BMTRGR_TDREP_Msk      /*!< TDREP */
#define HRTIM_BMTRGR_TFREP_Pos         (21U)
#define HRTIM_BMTRGR_TFREP_Msk         (0x1UL << HRTIM_BMTRGR_TFREP_Pos)    /*!< 0x00200000 */
#define HRTIM_BMTRGR_TFREP              HRTIM_BMTRGR_TFREP_Msk      /*!< TFREP */
#define HRTIM_BMTRGR_TDCMP2_Pos        (22U)
#define HRTIM_BMTRGR_TDCMP2_Msk        (0x1UL << HRTIM_BMTRGR_TDCMP2_Pos)     /*!< 0x00400000 */
#define HRTIM_BMTRGR_TDCMP2             HRTIM_BMTRGR_TDCMP2_Msk     /*!< TDCMP2 */
#define HRTIM_BMTRGR_TFCMP1_Pos        (23U)
#define HRTIM_BMTRGR_TFCMP1_Msk        (0x1UL << HRTIM_BMTRGR_TFCMP1_Pos)     /*!< 0x00800000 */
#define HRTIM_BMTRGR_TFCMP1             HRTIM_BMTRGR_TFCMP1_Msk     /*!< TFCMP1 */
#define HRTIM_BMTRGR_TEREP_Pos         (24U)
#define HRTIM_BMTRGR_TEREP_Msk         (0x1UL << HRTIM_BMTRGR_TEREP_Pos)    /*!< 0x01000000 */
#define HRTIM_BMTRGR_TEREP              HRTIM_BMTRGR_TEREP_Msk      /*!< TEREP */
#define HRTIM_BMTRGR_TECMP1_Pos        (25U)
#define HRTIM_BMTRGR_TECMP1_Msk        (0x1UL << HRTIM_BMTRGR_TECMP1_Pos)     /*!< 0x02000000 */
#define HRTIM_BMTRGR_TECMP1             HRTIM_BMTRGR_TECMP1_Msk     /*!< TECMP1 */
#define HRTIM_BMTRGR_TECMP2_Pos        (26U)
#define HRTIM_BMTRGR_TECMP2_Msk        (0x1UL << HRTIM_BMTRGR_TECMP2_Pos)     /*!< 0x04000000 */
#define HRTIM_BMTRGR_TECMP2             HRTIM_BMTRGR_TECMP2_Msk     /*!< TECMP2 */
#define HRTIM_BMTRGR_TAEEV7_Pos        (27U)
#define HRTIM_BMTRGR_TAEEV7_Msk        (0x1UL << HRTIM_BMTRGR_TAEEV7_Pos)     /*!< 0x08000000 */
#define HRTIM_BMTRGR_TAEEV7             HRTIM_BMTRGR_TAEEV7_Msk     /*!< TAEEV7 */
#define HRTIM_BMTRGR_TDEEV8_Pos        (28U)
#define HRTIM_BMTRGR_TDEEV8_Msk        (0x1UL << HRTIM_BMTRGR_TDEEV8_Pos)     /*!< 0x10000000 */
#define HRTIM_BMTRGR_TDEEV8             HRTIM_BMTRGR_TDEEV8_Msk     /*!< TDEEV8 */
#define HRTIM_BMTRGR_EEV7_Pos          (29U)
#define HRTIM_BMTRGR_EEV7_Msk          (0x1UL << HRTIM_BMTRGR_EEV7_Pos)   /*!< 0x20000000 */
#define HRTIM_BMTRGR_EEV7               HRTIM_BMTRGR_EEV7_Msk       /*!< EEV7 */
#define HRTIM_BMTRGR_EEV8_Pos          (30U)
#define HRTIM_BMTRGR_EEV8_Msk          (0x1UL << HRTIM_BMTRGR_EEV8_Pos)   /*!< 0x40000000 */
#define HRTIM_BMTRGR_EEV8               HRTIM_BMTRGR_EEV8_Msk       /*!< EEV8 */
#define HRTIM_BMTRGR_OCHPEV_Pos        (31U)
#define HRTIM_BMTRGR_OCHPEV_Msk        (0x1UL << HRTIM_BMTRGR_OCHPEV_Pos)     /*!< 0x80000000 */
#define HRTIM_BMTRGR_OCHPEV             HRTIM_BMTRGR_OCHPEV_Msk     /*!< OCHPEV */

/*************  Bit definition for HRTIM_BMCMPR register  *************/
#define HRTIM_BMCMPR_BMCMPR_Pos        (0U)
#define HRTIM_BMCMPR_BMCMPR_Msk        (0xFFFFUL << HRTIM_BMCMPR_BMCMPR_Pos)        /*!< 0x0000FFFF */
#define HRTIM_BMCMPR_BMCMPR             HRTIM_BMCMPR_BMCMPR_Msk     /*!< BMCMPR */

/*************  Bit definition for HRTIM_BMPER register  **************/
#define HRTIM_BMPER_BMPER_Pos          (0U)
#define HRTIM_BMPER_BMPER_Msk          (0xFFFFUL << HRTIM_BMPER_BMPER_Pos)      /*!< 0x0000FFFF */
#define HRTIM_BMPER_BMPER               HRTIM_BMPER_BMPER_Msk       /*!< BMPER */

/*************  Bit definition for HRTIM_EECR1 register  **************/
#define HRTIM_EECR1_EE1SRC_Pos         (0U)
#define HRTIM_EECR1_EE1SRC_Msk         (0x3UL << HRTIM_EECR1_EE1SRC_Pos)    /*!< 0x00000003 */
#define HRTIM_EECR1_EE1SRC              HRTIM_EECR1_EE1SRC_Msk      /*!< EE1SRC */
#define HRTIM_EECR1_EE1SRC_0         (0x1UL << HRTIM_EECR1_EE1SRC_Pos)     /*!< 0x00000001 */
#define HRTIM_EECR1_EE1SRC_1         (0x2UL << HRTIM_EECR1_EE1SRC_Pos)     /*!< 0x00000002 */
#define HRTIM_EECR1_EE1POL_Pos         (2U)
#define HRTIM_EECR1_EE1POL_Msk         (0x1UL << HRTIM_EECR1_EE1POL_Pos)    /*!< 0x00000004 */
#define HRTIM_EECR1_EE1POL              HRTIM_EECR1_EE1POL_Msk      /*!< EE1POL */
#define HRTIM_EECR1_EE1SNS_Pos         (3U)
#define HRTIM_EECR1_EE1SNS_Msk         (0x3UL << HRTIM_EECR1_EE1SNS_Pos)    /*!< 0x00000018 */
#define HRTIM_EECR1_EE1SNS              HRTIM_EECR1_EE1SNS_Msk      /*!< EE1SNS */
#define HRTIM_EECR1_EE1SNS_0         (0x1UL << HRTIM_EECR1_EE1SNS_Pos)     /*!< 0x00000008 */
#define HRTIM_EECR1_EE1SNS_1         (0x2UL << HRTIM_EECR1_EE1SNS_Pos)     /*!< 0x00000010 */
#define HRTIM_EECR1_EE1FAST_Pos        (5U)
#define HRTIM_EECR1_EE1FAST_Msk        (0x1UL << HRTIM_EECR1_EE1FAST_Pos)     /*!< 0x00000020 */
#define HRTIM_EECR1_EE1FAST             HRTIM_EECR1_EE1FAST_Msk     /*!< EE1FAST */
#define HRTIM_EECR1_EE2SRC_Pos         (6U)
#define HRTIM_EECR1_EE2SRC_Msk         (0x3UL << HRTIM_EECR1_EE2SRC_Pos)    /*!< 0x000000C0 */
#define HRTIM_EECR1_EE2SRC              HRTIM_EECR1_EE2SRC_Msk      /*!< EE2SRC */
#define HRTIM_EECR1_EE2SRC_0         (0x1UL << HRTIM_EECR1_EE2SRC_Pos)     /*!< 0x00000040 */
#define HRTIM_EECR1_EE2SRC_1         (0x2UL << HRTIM_EECR1_EE2SRC_Pos)     /*!< 0x00000080 */
#define HRTIM_EECR1_EE2POL_Pos         (8U)
#define HRTIM_EECR1_EE2POL_Msk         (0x1UL << HRTIM_EECR1_EE2POL_Pos)    /*!< 0x00000100 */
#define HRTIM_EECR1_EE2POL              HRTIM_EECR1_EE2POL_Msk      /*!< EE2POL */
#define HRTIM_EECR1_EE2SNS_Pos         (9U)
#define HRTIM_EECR1_EE2SNS_Msk         (0x3UL << HRTIM_EECR1_EE2SNS_Pos)    /*!< 0x00000600 */
#define HRTIM_EECR1_EE2SNS              HRTIM_EECR1_EE2SNS_Msk      /*!< EE2SNS */
#define HRTIM_EECR1_EE2SNS_0         (0x1UL << HRTIM_EECR1_EE2SNS_Pos)     /*!< 0x00000200 */
#define HRTIM_EECR1_EE2SNS_1         (0x2UL << HRTIM_EECR1_EE2SNS_Pos)     /*!< 0x00000400 */
#define HRTIM_EECR1_EE2FAST_Pos        (11U)
#define HRTIM_EECR1_EE2FAST_Msk        (0x1UL << HRTIM_EECR1_EE2FAST_Pos)     /*!< 0x00000800 */
#define HRTIM_EECR1_EE2FAST             HRTIM_EECR1_EE2FAST_Msk     /*!< EE2FAST */
#define HRTIM_EECR1_EE3SRC_Pos         (12U)
#define HRTIM_EECR1_EE3SRC_Msk         (0x3UL << HRTIM_EECR1_EE3SRC_Pos)    /*!< 0x00003000 */
#define HRTIM_EECR1_EE3SRC              HRTIM_EECR1_EE3SRC_Msk      /*!< EE3SRC */
#define HRTIM_EECR1_EE3SRC_0         (0x1UL << HRTIM_EECR1_EE3SRC_Pos)     /*!< 0x00001000 */
#define HRTIM_EECR1_EE3SRC_1         (0x2UL << HRTIM_EECR1_EE3SRC_Pos)     /*!< 0x00002000 */
#define HRTIM_EECR1_EE3POL_Pos         (14U)
#define HRTIM_EECR1_EE3POL_Msk         (0x1UL << HRTIM_EECR1_EE3POL_Pos)    /*!< 0x00004000 */
#define HRTIM_EECR1_EE3POL              HRTIM_EECR1_EE3POL_Msk      /*!< EE3POL */
#define HRTIM_EECR1_EE3SNS_Pos         (15U)
#define HRTIM_EECR1_EE3SNS_Msk         (0x3UL << HRTIM_EECR1_EE3SNS_Pos)    /*!< 0x00018000 */
#define HRTIM_EECR1_EE3SNS              HRTIM_EECR1_EE3SNS_Msk      /*!< EE3SNS */
#define HRTIM_EECR1_EE3SNS_0         (0x1UL << HRTIM_EECR1_EE3SNS_Pos)     /*!< 0x00008000 */
#define HRTIM_EECR1_EE3SNS_1         (0x2UL << HRTIM_EECR1_EE3SNS_Pos)     /*!< 0x00010000 */
#define HRTIM_EECR1_EE3FAST_Pos        (17U)
#define HRTIM_EECR1_EE3FAST_Msk        (0x1UL << HRTIM_EECR1_EE3FAST_Pos)     /*!< 0x00020000 */
#define HRTIM_EECR1_EE3FAST             HRTIM_EECR1_EE3FAST_Msk     /*!< EE3FAST */
#define HRTIM_EECR1_EE4SRC_Pos         (18U)
#define HRTIM_EECR1_EE4SRC_Msk         (0x3UL << HRTIM_EECR1_EE4SRC_Pos)    /*!< 0x000C0000 */
#define HRTIM_EECR1_EE4SRC              HRTIM_EECR1_EE4SRC_Msk      /*!< EE4SRC */
#define HRTIM_EECR1_EE4SRC_0         (0x1UL << HRTIM_EECR1_EE4SRC_Pos)     /*!< 0x00040000 */
#define HRTIM_EECR1_EE4SRC_1         (0x2UL << HRTIM_EECR1_EE4SRC_Pos)     /*!< 0x00080000 */
#define HRTIM_EECR1_EE4POL_Pos         (20U)
#define HRTIM_EECR1_EE4POL_Msk         (0x1UL << HRTIM_EECR1_EE4POL_Pos)    /*!< 0x00100000 */
#define HRTIM_EECR1_EE4POL              HRTIM_EECR1_EE4POL_Msk      /*!< EE4POL */
#define HRTIM_EECR1_EE4SNS_Pos         (21U)
#define HRTIM_EECR1_EE4SNS_Msk         (0x3UL << HRTIM_EECR1_EE4SNS_Pos)    /*!< 0x00600000 */
#define HRTIM_EECR1_EE4SNS              HRTIM_EECR1_EE4SNS_Msk      /*!< EE4SNS */
#define HRTIM_EECR1_EE4SNS_0         (0x1UL << HRTIM_EECR1_EE4SNS_Pos)     /*!< 0x00200000 */
#define HRTIM_EECR1_EE4SNS_1         (0x2UL << HRTIM_EECR1_EE4SNS_Pos)     /*!< 0x00400000 */
#define HRTIM_EECR1_EE4FAST_Pos        (23U)
#define HRTIM_EECR1_EE4FAST_Msk        (0x1UL << HRTIM_EECR1_EE4FAST_Pos)     /*!< 0x00800000 */
#define HRTIM_EECR1_EE4FAST             HRTIM_EECR1_EE4FAST_Msk     /*!< EE4FAST */
#define HRTIM_EECR1_EE5SRC_Pos         (24U)
#define HRTIM_EECR1_EE5SRC_Msk         (0x3UL << HRTIM_EECR1_EE5SRC_Pos)    /*!< 0x03000000 */
#define HRTIM_EECR1_EE5SRC              HRTIM_EECR1_EE5SRC_Msk      /*!< EE5SRC */
#define HRTIM_EECR1_EE5SRC_0         (0x1UL << HRTIM_EECR1_EE5SRC_Pos)     /*!< 0x01000000 */
#define HRTIM_EECR1_EE5SRC_1         (0x2UL << HRTIM_EECR1_EE5SRC_Pos)     /*!< 0x02000000 */
#define HRTIM_EECR1_EE5POL_Pos         (26U)
#define HRTIM_EECR1_EE5POL_Msk         (0x1UL << HRTIM_EECR1_EE5POL_Pos)    /*!< 0x04000000 */
#define HRTIM_EECR1_EE5POL              HRTIM_EECR1_EE5POL_Msk      /*!< EE5POL */
#define HRTIM_EECR1_EE5SNS_Pos         (27U)
#define HRTIM_EECR1_EE5SNS_Msk         (0x3UL << HRTIM_EECR1_EE5SNS_Pos)    /*!< 0x18000000 */
#define HRTIM_EECR1_EE5SNS              HRTIM_EECR1_EE5SNS_Msk      /*!< EE5SNS */
#define HRTIM_EECR1_EE5SNS_0         (0x1UL << HRTIM_EECR1_EE5SNS_Pos)     /*!< 0x08000000 */
#define HRTIM_EECR1_EE5SNS_1         (0x2UL << HRTIM_EECR1_EE5SNS_Pos)     /*!< 0x10000000 */
#define HRTIM_EECR1_EE5FAST_Pos        (29U)
#define HRTIM_EECR1_EE5FAST_Msk        (0x1UL << HRTIM_EECR1_EE5FAST_Pos)     /*!< 0x20000000 */
#define HRTIM_EECR1_EE5FAST             HRTIM_EECR1_EE5FAST_Msk     /*!< EE5FAST */

/*************  Bit definition for HRTIM_EECR2 register  **************/
#define HRTIM_EECR2_EE6SRC_Pos         (0U)
#define HRTIM_EECR2_EE6SRC_Msk         (0x3UL << HRTIM_EECR2_EE6SRC_Pos)    /*!< 0x00000003 */
#define HRTIM_EECR2_EE6SRC              HRTIM_EECR2_EE6SRC_Msk      /*!< EE6SRC */
#define HRTIM_EECR2_EE6SRC_0         (0x1UL << HRTIM_EECR2_EE6SRC_Pos)     /*!< 0x00000001 */
#define HRTIM_EECR2_EE6SRC_1         (0x2UL << HRTIM_EECR2_EE6SRC_Pos)     /*!< 0x00000002 */
#define HRTIM_EECR2_EE6POL_Pos         (2U)
#define HRTIM_EECR2_EE6POL_Msk         (0x1UL << HRTIM_EECR2_EE6POL_Pos)    /*!< 0x00000004 */
#define HRTIM_EECR2_EE6POL              HRTIM_EECR2_EE6POL_Msk      /*!< EE6POL */
#define HRTIM_EECR2_EE6SNS_Pos         (3U)
#define HRTIM_EECR2_EE6SNS_Msk         (0x3UL << HRTIM_EECR2_EE6SNS_Pos)    /*!< 0x00000018 */
#define HRTIM_EECR2_EE6SNS              HRTIM_EECR2_EE6SNS_Msk      /*!< EE6SNS */
#define HRTIM_EECR2_EE6SNS_0         (0x1UL << HRTIM_EECR2_EE6SNS_Pos)     /*!< 0x00000008 */
#define HRTIM_EECR2_EE6SNS_1         (0x2UL << HRTIM_EECR2_EE6SNS_Pos)     /*!< 0x00000010 */
#define HRTIM_EECR2_EE7SRC_Pos         (6U)
#define HRTIM_EECR2_EE7SRC_Msk         (0x3UL << HRTIM_EECR2_EE7SRC_Pos)    /*!< 0x000000C0 */
#define HRTIM_EECR2_EE7SRC              HRTIM_EECR2_EE7SRC_Msk      /*!< EE7SRC */
#define HRTIM_EECR2_EE7SRC_0         (0x1UL << HRTIM_EECR2_EE7SRC_Pos)     /*!< 0x00000040 */
#define HRTIM_EECR2_EE7SRC_1         (0x2UL << HRTIM_EECR2_EE7SRC_Pos)     /*!< 0x00000080 */
#define HRTIM_EECR2_EE7POL_Pos         (8U)
#define HRTIM_EECR2_EE7POL_Msk         (0x1UL << HRTIM_EECR2_EE7POL_Pos)    /*!< 0x00000100 */
#define HRTIM_EECR2_EE7POL              HRTIM_EECR2_EE7POL_Msk      /*!< EE7POL */
#define HRTIM_EECR2_EE7SNS_Pos         (9U)
#define HRTIM_EECR2_EE7SNS_Msk         (0x3UL << HRTIM_EECR2_EE7SNS_Pos)    /*!< 0x00000600 */
#define HRTIM_EECR2_EE7SNS              HRTIM_EECR2_EE7SNS_Msk      /*!< EE7SNS */
#define HRTIM_EECR2_EE7SNS_0         (0x1UL << HRTIM_EECR2_EE7SNS_Pos)     /*!< 0x00000200 */
#define HRTIM_EECR2_EE7SNS_1         (0x2UL << HRTIM_EECR2_EE7SNS_Pos)     /*!< 0x00000400 */
#define HRTIM_EECR2_EE8SRC_Pos         (12U)
#define HRTIM_EECR2_EE8SRC_Msk         (0x3UL << HRTIM_EECR2_EE8SRC_Pos)    /*!< 0x00003000 */
#define HRTIM_EECR2_EE8SRC              HRTIM_EECR2_EE8SRC_Msk      /*!< EE8SRC */
#define HRTIM_EECR2_EE8SRC_0         (0x1UL << HRTIM_EECR2_EE8SRC_Pos)     /*!< 0x00001000 */
#define HRTIM_EECR2_EE8SRC_1         (0x2UL << HRTIM_EECR2_EE8SRC_Pos)     /*!< 0x00002000 */
#define HRTIM_EECR2_EE8POL_Pos         (14U)
#define HRTIM_EECR2_EE8POL_Msk         (0x1UL << HRTIM_EECR2_EE8POL_Pos)    /*!< 0x00004000 */
#define HRTIM_EECR2_EE8POL              HRTIM_EECR2_EE8POL_Msk      /*!< EE8POL */
#define HRTIM_EECR2_EE8SNS_Pos         (15U)
#define HRTIM_EECR2_EE8SNS_Msk         (0x3UL << HRTIM_EECR2_EE8SNS_Pos)    /*!< 0x00018000 */
#define HRTIM_EECR2_EE8SNS              HRTIM_EECR2_EE8SNS_Msk      /*!< EE8SNS */
#define HRTIM_EECR2_EE8SNS_0         (0x1UL << HRTIM_EECR2_EE8SNS_Pos)     /*!< 0x00008000 */
#define HRTIM_EECR2_EE8SNS_1         (0x2UL << HRTIM_EECR2_EE8SNS_Pos)     /*!< 0x00010000 */
#define HRTIM_EECR2_EE9SRC_Pos         (18U)
#define HRTIM_EECR2_EE9SRC_Msk         (0x3UL << HRTIM_EECR2_EE9SRC_Pos)    /*!< 0x000C0000 */
#define HRTIM_EECR2_EE9SRC              HRTIM_EECR2_EE9SRC_Msk      /*!< EE9SRC */
#define HRTIM_EECR2_EE9SRC_0         (0x1UL << HRTIM_EECR2_EE9SRC_Pos)     /*!< 0x00040000 */
#define HRTIM_EECR2_EE9SRC_1         (0x2UL << HRTIM_EECR2_EE9SRC_Pos)     /*!< 0x00080000 */
#define HRTIM_EECR2_EE9POL_Pos         (20U)
#define HRTIM_EECR2_EE9POL_Msk         (0x1UL << HRTIM_EECR2_EE9POL_Pos)    /*!< 0x00100000 */
#define HRTIM_EECR2_EE9POL              HRTIM_EECR2_EE9POL_Msk      /*!< EE9POL */
#define HRTIM_EECR2_EE9SNS_Pos         (21U)
#define HRTIM_EECR2_EE9SNS_Msk         (0x3UL << HRTIM_EECR2_EE9SNS_Pos)    /*!< 0x00600000 */
#define HRTIM_EECR2_EE9SNS              HRTIM_EECR2_EE9SNS_Msk      /*!< EE9SNS */
#define HRTIM_EECR2_EE9SNS_0         (0x1UL << HRTIM_EECR2_EE9SNS_Pos)     /*!< 0x00200000 */
#define HRTIM_EECR2_EE9SNS_1         (0x2UL << HRTIM_EECR2_EE9SNS_Pos)     /*!< 0x00400000 */
#define HRTIM_EECR2_EE10SRC_Pos        (24U)
#define HRTIM_EECR2_EE10SRC_Msk        (0x3UL << HRTIM_EECR2_EE10SRC_Pos)     /*!< 0x03000000 */
#define HRTIM_EECR2_EE10SRC             HRTIM_EECR2_EE10SRC_Msk     /*!< EE10SRC */
#define HRTIM_EECR2_EE10SRC_0        (0x1UL << HRTIM_EECR2_EE10SRC_Pos)      /*!< 0x01000000 */
#define HRTIM_EECR2_EE10SRC_1        (0x2UL << HRTIM_EECR2_EE10SRC_Pos)      /*!< 0x02000000 */
#define HRTIM_EECR2_EE10POL_Pos        (26U)
#define HRTIM_EECR2_EE10POL_Msk        (0x1UL << HRTIM_EECR2_EE10POL_Pos)     /*!< 0x04000000 */
#define HRTIM_EECR2_EE10POL             HRTIM_EECR2_EE10POL_Msk     /*!< EE10POL */
#define HRTIM_EECR2_EE10SNS_Pos        (27U)
#define HRTIM_EECR2_EE10SNS_Msk        (0x3UL << HRTIM_EECR2_EE10SNS_Pos)     /*!< 0x18000000 */
#define HRTIM_EECR2_EE10SNS             HRTIM_EECR2_EE10SNS_Msk     /*!< EE10SNS */
#define HRTIM_EECR2_EE10SNS_0        (0x1UL << HRTIM_EECR2_EE10SNS_Pos)      /*!< 0x08000000 */
#define HRTIM_EECR2_EE10SNS_1        (0x2UL << HRTIM_EECR2_EE10SNS_Pos)      /*!< 0x10000000 */

/*************  Bit definition for HRTIM_EECR3 register  **************/
#define HRTIM_EECR3_EE6F_Pos           (0U)
#define HRTIM_EECR3_EE6F_Msk           (0xFUL << HRTIM_EECR3_EE6F_Pos)  /*!< 0x0000000F */
#define HRTIM_EECR3_EE6F                HRTIM_EECR3_EE6F_Msk        /*!< EE6F */
#define HRTIM_EECR3_EE6F_0           (0x1UL << HRTIM_EECR3_EE6F_Pos)   /*!< 0x00000001 */
#define HRTIM_EECR3_EE6F_1           (0x2UL << HRTIM_EECR3_EE6F_Pos)   /*!< 0x00000002 */
#define HRTIM_EECR3_EE6F_2           (0x4UL << HRTIM_EECR3_EE6F_Pos)   /*!< 0x00000004 */
#define HRTIM_EECR3_EE6F_3           (0x8UL << HRTIM_EECR3_EE6F_Pos)   /*!< 0x00000008 */
#define HRTIM_EECR3_EE7F_Pos           (6U)
#define HRTIM_EECR3_EE7F_Msk           (0xFUL << HRTIM_EECR3_EE7F_Pos)  /*!< 0x000003C0 */
#define HRTIM_EECR3_EE7F                HRTIM_EECR3_EE7F_Msk        /*!< EE7F */
#define HRTIM_EECR3_EE7F_0           (0x1UL << HRTIM_EECR3_EE7F_Pos)   /*!< 0x00000040 */
#define HRTIM_EECR3_EE7F_1           (0x2UL << HRTIM_EECR3_EE7F_Pos)   /*!< 0x00000080 */
#define HRTIM_EECR3_EE7F_2           (0x4UL << HRTIM_EECR3_EE7F_Pos)   /*!< 0x00000100 */
#define HRTIM_EECR3_EE7F_3           (0x8UL << HRTIM_EECR3_EE7F_Pos)   /*!< 0x00000200 */
#define HRTIM_EECR3_EE8F_Pos           (12U)
#define HRTIM_EECR3_EE8F_Msk           (0xFUL << HRTIM_EECR3_EE8F_Pos)  /*!< 0x0000F000 */
#define HRTIM_EECR3_EE8F                HRTIM_EECR3_EE8F_Msk        /*!< EE8F */
#define HRTIM_EECR3_EE8F_0           (0x1UL << HRTIM_EECR3_EE8F_Pos)   /*!< 0x00001000 */
#define HRTIM_EECR3_EE8F_1           (0x2UL << HRTIM_EECR3_EE8F_Pos)   /*!< 0x00002000 */
#define HRTIM_EECR3_EE8F_2           (0x4UL << HRTIM_EECR3_EE8F_Pos)   /*!< 0x00004000 */
#define HRTIM_EECR3_EE8F_3           (0x8UL << HRTIM_EECR3_EE8F_Pos)   /*!< 0x00008000 */
#define HRTIM_EECR3_EE9F_Pos           (18U)
#define HRTIM_EECR3_EE9F_Msk           (0xFUL << HRTIM_EECR3_EE9F_Pos)  /*!< 0x003C0000 */
#define HRTIM_EECR3_EE9F                HRTIM_EECR3_EE9F_Msk        /*!< EE9F */
#define HRTIM_EECR3_EE9F_0           (0x1UL << HRTIM_EECR3_EE9F_Pos)   /*!< 0x00040000 */
#define HRTIM_EECR3_EE9F_1           (0x2UL << HRTIM_EECR3_EE9F_Pos)   /*!< 0x00080000 */
#define HRTIM_EECR3_EE9F_2           (0x4UL << HRTIM_EECR3_EE9F_Pos)   /*!< 0x00100000 */
#define HRTIM_EECR3_EE9F_3           (0x8UL << HRTIM_EECR3_EE9F_Pos)   /*!< 0x00200000 */
#define HRTIM_EECR3_EE10F_Pos          (24U)
#define HRTIM_EECR3_EE10F_Msk          (0xFUL << HRTIM_EECR3_EE10F_Pos)   /*!< 0x0F000000 */
#define HRTIM_EECR3_EE10F               HRTIM_EECR3_EE10F_Msk       /*!< EE10F */
#define HRTIM_EECR3_EE10F_0          (0x1UL << HRTIM_EECR3_EE10F_Pos)    /*!< 0x01000000 */
#define HRTIM_EECR3_EE10F_1          (0x2UL << HRTIM_EECR3_EE10F_Pos)    /*!< 0x02000000 */
#define HRTIM_EECR3_EE10F_2          (0x4UL << HRTIM_EECR3_EE10F_Pos)    /*!< 0x04000000 */
#define HRTIM_EECR3_EE10F_3          (0x8UL << HRTIM_EECR3_EE10F_Pos)    /*!< 0x08000000 */
#define HRTIM_EECR3_EEVSD_Pos          (30U)
#define HRTIM_EECR3_EEVSD_Msk          (0x3UL << HRTIM_EECR3_EEVSD_Pos)   /*!< 0xC0000000 */
#define HRTIM_EECR3_EEVSD               HRTIM_EECR3_EEVSD_Msk       /*!< EEVSD */
#define HRTIM_EECR3_EEVSD_0          (0x1UL << HRTIM_EECR3_EEVSD_Pos)    /*!< 0x40000000 */
#define HRTIM_EECR3_EEVSD_1          (0x2UL << HRTIM_EECR3_EEVSD_Pos)    /*!< 0x80000000 */

/*************  Bit definition for HRTIM_ADC1R register  **************/
#define HRTIM_ADC1R_AD1MC1_Pos         (0U)
#define HRTIM_ADC1R_AD1MC1_Msk         (0x1UL << HRTIM_ADC1R_AD1MC1_Pos)    /*!< 0x00000001 */
#define HRTIM_ADC1R_AD1MC1              HRTIM_ADC1R_AD1MC1_Msk      /*!< AD1MC1 */
#define HRTIM_ADC1R_AD1MC2_Pos         (1U)
#define HRTIM_ADC1R_AD1MC2_Msk         (0x1UL << HRTIM_ADC1R_AD1MC2_Pos)    /*!< 0x00000002 */
#define HRTIM_ADC1R_AD1MC2              HRTIM_ADC1R_AD1MC2_Msk      /*!< AD1MC2 */
#define HRTIM_ADC1R_AD1MC3_Pos         (2U)
#define HRTIM_ADC1R_AD1MC3_Msk         (0x1UL << HRTIM_ADC1R_AD1MC3_Pos)    /*!< 0x00000004 */
#define HRTIM_ADC1R_AD1MC3              HRTIM_ADC1R_AD1MC3_Msk      /*!< AD1MC3 */
#define HRTIM_ADC1R_AD1MC4_Pos         (3U)
#define HRTIM_ADC1R_AD1MC4_Msk         (0x1UL << HRTIM_ADC1R_AD1MC4_Pos)    /*!< 0x00000008 */
#define HRTIM_ADC1R_AD1MC4              HRTIM_ADC1R_AD1MC4_Msk      /*!< AD1MC4 */
#define HRTIM_ADC1R_AD1MPER_Pos        (4U)
#define HRTIM_ADC1R_AD1MPER_Msk        (0x1UL << HRTIM_ADC1R_AD1MPER_Pos)     /*!< 0x00000010 */
#define HRTIM_ADC1R_AD1MPER             HRTIM_ADC1R_AD1MPER_Msk     /*!< AD1MPER */
#define HRTIM_ADC1R_AD1EEV1_Pos        (5U)
#define HRTIM_ADC1R_AD1EEV1_Msk        (0x1UL << HRTIM_ADC1R_AD1EEV1_Pos)     /*!< 0x00000020 */
#define HRTIM_ADC1R_AD1EEV1             HRTIM_ADC1R_AD1EEV1_Msk     /*!< AD1EEV1 */
#define HRTIM_ADC1R_AD1EEV2_Pos        (6U)
#define HRTIM_ADC1R_AD1EEV2_Msk        (0x1UL << HRTIM_ADC1R_AD1EEV2_Pos)     /*!< 0x00000040 */
#define HRTIM_ADC1R_AD1EEV2             HRTIM_ADC1R_AD1EEV2_Msk     /*!< AD1EEV2 */
#define HRTIM_ADC1R_AD1EEV3_Pos        (7U)
#define HRTIM_ADC1R_AD1EEV3_Msk        (0x1UL << HRTIM_ADC1R_AD1EEV3_Pos)     /*!< 0x00000080 */
#define HRTIM_ADC1R_AD1EEV3             HRTIM_ADC1R_AD1EEV3_Msk     /*!< AD1EEV3 */
#define HRTIM_ADC1R_AD1EEV4_Pos        (8U)
#define HRTIM_ADC1R_AD1EEV4_Msk        (0x1UL << HRTIM_ADC1R_AD1EEV4_Pos)     /*!< 0x00000100 */
#define HRTIM_ADC1R_AD1EEV4             HRTIM_ADC1R_AD1EEV4_Msk     /*!< AD1EEV4 */
#define HRTIM_ADC1R_AD1EEV5_Pos        (9U)
#define HRTIM_ADC1R_AD1EEV5_Msk        (0x1UL << HRTIM_ADC1R_AD1EEV5_Pos)     /*!< 0x00000200 */
#define HRTIM_ADC1R_AD1EEV5             HRTIM_ADC1R_AD1EEV5_Msk     /*!< AD1EEV5 */
#define HRTIM_ADC1R_AD1TFC2_Pos        (10U)
#define HRTIM_ADC1R_AD1TFC2_Msk        (0x1UL << HRTIM_ADC1R_AD1TFC2_Pos)     /*!< 0x00000400 */
#define HRTIM_ADC1R_AD1TFC2             HRTIM_ADC1R_AD1TFC2_Msk     /*!< AD1TFC2 */
#define HRTIM_ADC1R_AD1TAC3_Pos        (11U)
#define HRTIM_ADC1R_AD1TAC3_Msk        (0x1UL << HRTIM_ADC1R_AD1TAC3_Pos)     /*!< 0x00000800 */
#define HRTIM_ADC1R_AD1TAC3             HRTIM_ADC1R_AD1TAC3_Msk     /*!< AD1TAC3 */
#define HRTIM_ADC1R_AD1TAC4_Pos        (12U)
#define HRTIM_ADC1R_AD1TAC4_Msk        (0x1UL << HRTIM_ADC1R_AD1TAC4_Pos)     /*!< 0x00001000 */
#define HRTIM_ADC1R_AD1TAC4             HRTIM_ADC1R_AD1TAC4_Msk     /*!< AD1TAC4 */
#define HRTIM_ADC1R_AD1TAPER_Pos       (13U)
#define HRTIM_ADC1R_AD1TAPER_Msk       (0x1UL << HRTIM_ADC1R_AD1TAPER_Pos)      /*!< 0x00002000 */
#define HRTIM_ADC1R_AD1TAPER            HRTIM_ADC1R_AD1TAPER_Msk    /*!< AD1TAPER */
#define HRTIM_ADC1R_AD1TARST_Pos       (14U)
#define HRTIM_ADC1R_AD1TARST_Msk       (0x1UL << HRTIM_ADC1R_AD1TARST_Pos)      /*!< 0x00004000 */
#define HRTIM_ADC1R_AD1TARST            HRTIM_ADC1R_AD1TARST_Msk    /*!< AD1TARST */
#define HRTIM_ADC1R_AD1TFC3_Pos        (15U)
#define HRTIM_ADC1R_AD1TFC3_Msk        (0x1UL << HRTIM_ADC1R_AD1TFC3_Pos)     /*!< 0x00008000 */
#define HRTIM_ADC1R_AD1TFC3             HRTIM_ADC1R_AD1TFC3_Msk     /*!< AD1TFC3 */
#define HRTIM_ADC1R_AD1TBC3_Pos        (16U)
#define HRTIM_ADC1R_AD1TBC3_Msk        (0x1UL << HRTIM_ADC1R_AD1TBC3_Pos)     /*!< 0x00010000 */
#define HRTIM_ADC1R_AD1TBC3             HRTIM_ADC1R_AD1TBC3_Msk     /*!< AD1TBC3 */
#define HRTIM_ADC1R_AD1TBC4_Pos        (17U)
#define HRTIM_ADC1R_AD1TBC4_Msk        (0x1UL << HRTIM_ADC1R_AD1TBC4_Pos)     /*!< 0x00020000 */
#define HRTIM_ADC1R_AD1TBC4             HRTIM_ADC1R_AD1TBC4_Msk     /*!< AD1TBC4 */
#define HRTIM_ADC1R_AD1TBPER_Pos       (18U)
#define HRTIM_ADC1R_AD1TBPER_Msk       (0x1UL << HRTIM_ADC1R_AD1TBPER_Pos)      /*!< 0x00040000 */
#define HRTIM_ADC1R_AD1TBPER            HRTIM_ADC1R_AD1TBPER_Msk    /*!< AD1TBPER */
#define HRTIM_ADC1R_AD1TBRST_Pos       (19U)
#define HRTIM_ADC1R_AD1TBRST_Msk       (0x1UL << HRTIM_ADC1R_AD1TBRST_Pos)      /*!< 0x00080000 */
#define HRTIM_ADC1R_AD1TBRST            HRTIM_ADC1R_AD1TBRST_Msk    /*!< AD1TBRST */
#define HRTIM_ADC1R_AD1TFC4_Pos        (20U)
#define HRTIM_ADC1R_AD1TFC4_Msk        (0x1UL << HRTIM_ADC1R_AD1TFC4_Pos)     /*!< 0x00100000 */
#define HRTIM_ADC1R_AD1TFC4             HRTIM_ADC1R_AD1TFC4_Msk     /*!< AD1TFC4 */
#define HRTIM_ADC1R_AD1TCC3_Pos        (21U)
#define HRTIM_ADC1R_AD1TCC3_Msk        (0x1UL << HRTIM_ADC1R_AD1TCC3_Pos)     /*!< 0x00200000 */
#define HRTIM_ADC1R_AD1TCC3             HRTIM_ADC1R_AD1TCC3_Msk     /*!< AD1TCC3 */
#define HRTIM_ADC1R_AD1TCC4_Pos        (22U)
#define HRTIM_ADC1R_AD1TCC4_Msk        (0x1UL << HRTIM_ADC1R_AD1TCC4_Pos)     /*!< 0x00400000 */
#define HRTIM_ADC1R_AD1TCC4             HRTIM_ADC1R_AD1TCC4_Msk     /*!< AD1TCC4 */
#define HRTIM_ADC1R_AD1TCPER_Pos       (23U)
#define HRTIM_ADC1R_AD1TCPER_Msk       (0x1UL << HRTIM_ADC1R_AD1TCPER_Pos)      /*!< 0x00800000 */
#define HRTIM_ADC1R_AD1TCPER            HRTIM_ADC1R_AD1TCPER_Msk    /*!< AD1TCPER */
#define HRTIM_ADC1R_AD1TFPER_Pos       (24U)
#define HRTIM_ADC1R_AD1TFPER_Msk       (0x1UL << HRTIM_ADC1R_AD1TFPER_Pos)      /*!< 0x01000000 */
#define HRTIM_ADC1R_AD1TFPER            HRTIM_ADC1R_AD1TFPER_Msk    /*!< AD1TFPER */
#define HRTIM_ADC1R_AD1TDC3_Pos        (25U)
#define HRTIM_ADC1R_AD1TDC3_Msk        (0x1UL << HRTIM_ADC1R_AD1TDC3_Pos)     /*!< 0x02000000 */
#define HRTIM_ADC1R_AD1TDC3             HRTIM_ADC1R_AD1TDC3_Msk     /*!< AD1TDC3 */
#define HRTIM_ADC1R_AD1TDC4_Pos        (26U)
#define HRTIM_ADC1R_AD1TDC4_Msk        (0x1UL << HRTIM_ADC1R_AD1TDC4_Pos)     /*!< 0x04000000 */
#define HRTIM_ADC1R_AD1TDC4             HRTIM_ADC1R_AD1TDC4_Msk     /*!< AD1TDC4 */
#define HRTIM_ADC1R_AD1TDPER_Pos       (27U)
#define HRTIM_ADC1R_AD1TDPER_Msk       (0x1UL << HRTIM_ADC1R_AD1TDPER_Pos)      /*!< 0x08000000 */
#define HRTIM_ADC1R_AD1TDPER            HRTIM_ADC1R_AD1TDPER_Msk    /*!< AD1TDPER */
#define HRTIM_ADC1R_AD1TFRST_Pos       (28U)
#define HRTIM_ADC1R_AD1TFRST_Msk       (0x1UL << HRTIM_ADC1R_AD1TFRST_Pos)      /*!< 0x10000000 */
#define HRTIM_ADC1R_AD1TFRST            HRTIM_ADC1R_AD1TFRST_Msk    /*!< AD1TFRST */
#define HRTIM_ADC1R_AD1TEC3_Pos        (29U)
#define HRTIM_ADC1R_AD1TEC3_Msk        (0x1UL << HRTIM_ADC1R_AD1TEC3_Pos)     /*!< 0x20000000 */
#define HRTIM_ADC1R_AD1TEC3             HRTIM_ADC1R_AD1TEC3_Msk     /*!< AD1TEC3 */
#define HRTIM_ADC1R_AD1TEC4_Pos        (30U)
#define HRTIM_ADC1R_AD1TEC4_Msk        (0x1UL << HRTIM_ADC1R_AD1TEC4_Pos)     /*!< 0x40000000 */
#define HRTIM_ADC1R_AD1TEC4             HRTIM_ADC1R_AD1TEC4_Msk     /*!< AD1TEC4 */
#define HRTIM_ADC1R_AD1TEPER_Pos       (31U)
#define HRTIM_ADC1R_AD1TEPER_Msk       (0x1UL << HRTIM_ADC1R_AD1TEPER_Pos)      /*!< 0x80000000 */
#define HRTIM_ADC1R_AD1TEPER            HRTIM_ADC1R_AD1TEPER_Msk    /*!< AD1TEPER */

/*************  Bit definition for HRTIM_ADC2R register  **************/
#define HRTIM_ADC2R_AD2MC1_Pos         (0U)
#define HRTIM_ADC2R_AD2MC1_Msk         (0x1UL << HRTIM_ADC2R_AD2MC1_Pos)    /*!< 0x00000001 */
#define HRTIM_ADC2R_AD2MC1              HRTIM_ADC2R_AD2MC1_Msk      /*!< AD2MC1 */
#define HRTIM_ADC2R_AD2MC2_Pos         (1U)
#define HRTIM_ADC2R_AD2MC2_Msk         (0x1UL << HRTIM_ADC2R_AD2MC2_Pos)    /*!< 0x00000002 */
#define HRTIM_ADC2R_AD2MC2              HRTIM_ADC2R_AD2MC2_Msk      /*!< AD2MC2 */
#define HRTIM_ADC2R_AD2MC3_Pos         (2U)
#define HRTIM_ADC2R_AD2MC3_Msk         (0x1UL << HRTIM_ADC2R_AD2MC3_Pos)    /*!< 0x00000004 */
#define HRTIM_ADC2R_AD2MC3              HRTIM_ADC2R_AD2MC3_Msk      /*!< AD2MC3 */
#define HRTIM_ADC2R_AD2MC4_Pos         (3U)
#define HRTIM_ADC2R_AD2MC4_Msk         (0x1UL << HRTIM_ADC2R_AD2MC4_Pos)    /*!< 0x00000008 */
#define HRTIM_ADC2R_AD2MC4              HRTIM_ADC2R_AD2MC4_Msk      /*!< AD2MC4 */
#define HRTIM_ADC2R_AD2MPER_Pos        (4U)
#define HRTIM_ADC2R_AD2MPER_Msk        (0x1UL << HRTIM_ADC2R_AD2MPER_Pos)     /*!< 0x00000010 */
#define HRTIM_ADC2R_AD2MPER             HRTIM_ADC2R_AD2MPER_Msk     /*!< AD2MPER */
#define HRTIM_ADC2R_AD2EEV6_Pos        (5U)
#define HRTIM_ADC2R_AD2EEV6_Msk        (0x1UL << HRTIM_ADC2R_AD2EEV6_Pos)     /*!< 0x00000020 */
#define HRTIM_ADC2R_AD2EEV6             HRTIM_ADC2R_AD2EEV6_Msk     /*!< AD2EEV6 */
#define HRTIM_ADC2R_AD2EEV7_Pos        (6U)
#define HRTIM_ADC2R_AD2EEV7_Msk        (0x1UL << HRTIM_ADC2R_AD2EEV7_Pos)     /*!< 0x00000040 */
#define HRTIM_ADC2R_AD2EEV7             HRTIM_ADC2R_AD2EEV7_Msk     /*!< AD2EEV7 */
#define HRTIM_ADC2R_AD2EEV8_Pos        (7U)
#define HRTIM_ADC2R_AD2EEV8_Msk        (0x1UL << HRTIM_ADC2R_AD2EEV8_Pos)     /*!< 0x00000080 */
#define HRTIM_ADC2R_AD2EEV8             HRTIM_ADC2R_AD2EEV8_Msk     /*!< AD2EEV8 */
#define HRTIM_ADC2R_AD2EEV9_Pos        (8U)
#define HRTIM_ADC2R_AD2EEV9_Msk        (0x1UL << HRTIM_ADC2R_AD2EEV9_Pos)     /*!< 0x00000100 */
#define HRTIM_ADC2R_AD2EEV9             HRTIM_ADC2R_AD2EEV9_Msk     /*!< AD2EEV9 */
#define HRTIM_ADC2R_AD2EEV10_Pos       (9U)
#define HRTIM_ADC2R_AD2EEV10_Msk       (0x1UL << HRTIM_ADC2R_AD2EEV10_Pos)      /*!< 0x00000200 */
#define HRTIM_ADC2R_AD2EEV10            HRTIM_ADC2R_AD2EEV10_Msk    /*!< AD2EEV10 */
#define HRTIM_ADC2R_AD2TAC2_Pos        (10U)
#define HRTIM_ADC2R_AD2TAC2_Msk        (0x1UL << HRTIM_ADC2R_AD2TAC2_Pos)     /*!< 0x00000400 */
#define HRTIM_ADC2R_AD2TAC2             HRTIM_ADC2R_AD2TAC2_Msk     /*!< AD2TAC2 */
#define HRTIM_ADC2R_AD2TFC2_Pos        (11U)
#define HRTIM_ADC2R_AD2TFC2_Msk        (0x1UL << HRTIM_ADC2R_AD2TFC2_Pos)     /*!< 0x00000800 */
#define HRTIM_ADC2R_AD2TFC2             HRTIM_ADC2R_AD2TFC2_Msk     /*!< AD2TFC2 */
#define HRTIM_ADC2R_AD2TAC4_Pos        (12U)
#define HRTIM_ADC2R_AD2TAC4_Msk        (0x1UL << HRTIM_ADC2R_AD2TAC4_Pos)     /*!< 0x00001000 */
#define HRTIM_ADC2R_AD2TAC4             HRTIM_ADC2R_AD2TAC4_Msk     /*!< AD2TAC4 */
#define HRTIM_ADC2R_AD2TAPER_Pos       (13U)
#define HRTIM_ADC2R_AD2TAPER_Msk       (0x1UL << HRTIM_ADC2R_AD2TAPER_Pos)      /*!< 0x00002000 */
#define HRTIM_ADC2R_AD2TAPER            HRTIM_ADC2R_AD2TAPER_Msk    /*!< AD2TAPER */
#define HRTIM_ADC2R_AD2TBC2_Pos        (14U)
#define HRTIM_ADC2R_AD2TBC2_Msk        (0x1UL << HRTIM_ADC2R_AD2TBC2_Pos)     /*!< 0x00004000 */
#define HRTIM_ADC2R_AD2TBC2             HRTIM_ADC2R_AD2TBC2_Msk     /*!< AD2TBC2 */
#define HRTIM_ADC2R_AD2TFC3_Pos        (15U)
#define HRTIM_ADC2R_AD2TFC3_Msk        (0x1UL << HRTIM_ADC2R_AD2TFC3_Pos)     /*!< 0x00008000 */
#define HRTIM_ADC2R_AD2TFC3             HRTIM_ADC2R_AD2TFC3_Msk     /*!< AD2TFC3 */
#define HRTIM_ADC2R_AD2TBC4_Pos        (16U)
#define HRTIM_ADC2R_AD2TBC4_Msk        (0x1UL << HRTIM_ADC2R_AD2TBC4_Pos)     /*!< 0x00010000 */
#define HRTIM_ADC2R_AD2TBC4             HRTIM_ADC2R_AD2TBC4_Msk     /*!< AD2TBC4 */
#define HRTIM_ADC2R_AD2TBPER_Pos       (17U)
#define HRTIM_ADC2R_AD2TBPER_Msk       (0x1UL << HRTIM_ADC2R_AD2TBPER_Pos)      /*!< 0x00020000 */
#define HRTIM_ADC2R_AD2TBPER            HRTIM_ADC2R_AD2TBPER_Msk    /*!< AD2TBPER */
#define HRTIM_ADC2R_AD2TCC2_Pos        (18U)
#define HRTIM_ADC2R_AD2TCC2_Msk        (0x1UL << HRTIM_ADC2R_AD2TCC2_Pos)     /*!< 0x00040000 */
#define HRTIM_ADC2R_AD2TCC2             HRTIM_ADC2R_AD2TCC2_Msk     /*!< AD2TCC2 */
#define HRTIM_ADC2R_AD2TFC4_Pos        (19U)
#define HRTIM_ADC2R_AD2TFC4_Msk        (0x1UL << HRTIM_ADC2R_AD2TFC4_Pos)     /*!< 0x00080000 */
#define HRTIM_ADC2R_AD2TFC4             HRTIM_ADC2R_AD2TFC4_Msk     /*!< AD2TFC4 */
#define HRTIM_ADC2R_AD2TCC4_Pos        (20U)
#define HRTIM_ADC2R_AD2TCC4_Msk        (0x1UL << HRTIM_ADC2R_AD2TCC4_Pos)     /*!< 0x00100000 */
#define HRTIM_ADC2R_AD2TCC4             HRTIM_ADC2R_AD2TCC4_Msk     /*!< AD2TCC4 */
#define HRTIM_ADC2R_AD2TCPER_Pos       (21U)
#define HRTIM_ADC2R_AD2TCPER_Msk       (0x1UL << HRTIM_ADC2R_AD2TCPER_Pos)      /*!< 0x00200000 */
#define HRTIM_ADC2R_AD2TCPER            HRTIM_ADC2R_AD2TCPER_Msk    /*!< AD2TCPER */
#define HRTIM_ADC2R_AD2TCRST_Pos       (22U)
#define HRTIM_ADC2R_AD2TCRST_Msk       (0x1UL << HRTIM_ADC2R_AD2TCRST_Pos)      /*!< 0x00400000 */
#define HRTIM_ADC2R_AD2TCRST            HRTIM_ADC2R_AD2TCRST_Msk    /*!< AD2TCRST */
#define HRTIM_ADC2R_AD2TDC2_Pos        (23U)
#define HRTIM_ADC2R_AD2TDC2_Msk        (0x1UL << HRTIM_ADC2R_AD2TDC2_Pos)     /*!< 0x00800000 */
#define HRTIM_ADC2R_AD2TDC2             HRTIM_ADC2R_AD2TDC2_Msk     /*!< AD2TDC2 */
#define HRTIM_ADC2R_AD2TFPER_Pos       (24U)
#define HRTIM_ADC2R_AD2TFPER_Msk       (0x1UL << HRTIM_ADC2R_AD2TFPER_Pos)      /*!< 0x01000000 */
#define HRTIM_ADC2R_AD2TFPER            HRTIM_ADC2R_AD2TFPER_Msk    /*!< AD2TFPER */
#define HRTIM_ADC2R_AD2TDC4_Pos        (25U)
#define HRTIM_ADC2R_AD2TDC4_Msk        (0x1UL << HRTIM_ADC2R_AD2TDC4_Pos)     /*!< 0x02000000 */
#define HRTIM_ADC2R_AD2TDC4             HRTIM_ADC2R_AD2TDC4_Msk     /*!< AD2TDC4 */
#define HRTIM_ADC2R_AD2TDPER_Pos       (26U)
#define HRTIM_ADC2R_AD2TDPER_Msk       (0x1UL << HRTIM_ADC2R_AD2TDPER_Pos)      /*!< 0x04000000 */
#define HRTIM_ADC2R_AD2TDPER            HRTIM_ADC2R_AD2TDPER_Msk    /*!< AD2TDPER */
#define HRTIM_ADC2R_AD2TDRST_Pos       (27U)
#define HRTIM_ADC2R_AD2TDRST_Msk       (0x1UL << HRTIM_ADC2R_AD2TDRST_Pos)      /*!< 0x08000000 */
#define HRTIM_ADC2R_AD2TDRST            HRTIM_ADC2R_AD2TDRST_Msk    /*!< AD2TDRST */
#define HRTIM_ADC2R_AD2TEC2_Pos        (28U)
#define HRTIM_ADC2R_AD2TEC2_Msk        (0x1UL << HRTIM_ADC2R_AD2TEC2_Pos)     /*!< 0x10000000 */
#define HRTIM_ADC2R_AD2TEC2             HRTIM_ADC2R_AD2TEC2_Msk     /*!< AD2TEC2 */
#define HRTIM_ADC2R_AD2TEC3_Pos        (29U)
#define HRTIM_ADC2R_AD2TEC3_Msk        (0x1UL << HRTIM_ADC2R_AD2TEC3_Pos)     /*!< 0x20000000 */
#define HRTIM_ADC2R_AD2TEC3             HRTIM_ADC2R_AD2TEC3_Msk     /*!< AD2TEC3 */
#define HRTIM_ADC2R_AD2TEC4_Pos        (30U)
#define HRTIM_ADC2R_AD2TEC4_Msk        (0x1UL << HRTIM_ADC2R_AD2TEC4_Pos)     /*!< 0x40000000 */
#define HRTIM_ADC2R_AD2TEC4             HRTIM_ADC2R_AD2TEC4_Msk     /*!< AD2TEC4 */
#define HRTIM_ADC2R_AD2TERST_Pos       (31U)
#define HRTIM_ADC2R_AD2TERST_Msk       (0x1UL << HRTIM_ADC2R_AD2TERST_Pos)      /*!< 0x80000000 */
#define HRTIM_ADC2R_AD2TERST            HRTIM_ADC2R_AD2TERST_Msk    /*!< AD2TERST */

/*************  Bit definition for HRTIM_ADC3R register  **************/
#define HRTIM_ADC3R_AD3MC1_Pos         (0U)
#define HRTIM_ADC3R_AD3MC1_Msk         (0x1UL << HRTIM_ADC3R_AD3MC1_Pos)    /*!< 0x00000001 */
#define HRTIM_ADC3R_AD3MC1              HRTIM_ADC3R_AD3MC1_Msk      /*!< AD3MC1 */
#define HRTIM_ADC3R_AD3MC2_Pos         (1U)
#define HRTIM_ADC3R_AD3MC2_Msk         (0x1UL << HRTIM_ADC3R_AD3MC2_Pos)    /*!< 0x00000002 */
#define HRTIM_ADC3R_AD3MC2              HRTIM_ADC3R_AD3MC2_Msk      /*!< AD3MC2 */
#define HRTIM_ADC3R_AD3MC3_Pos         (2U)
#define HRTIM_ADC3R_AD3MC3_Msk         (0x1UL << HRTIM_ADC3R_AD3MC3_Pos)    /*!< 0x00000004 */
#define HRTIM_ADC3R_AD3MC3              HRTIM_ADC3R_AD3MC3_Msk      /*!< AD3MC3 */
#define HRTIM_ADC3R_AD3MC4_Pos         (3U)
#define HRTIM_ADC3R_AD3MC4_Msk         (0x1UL << HRTIM_ADC3R_AD3MC4_Pos)    /*!< 0x00000008 */
#define HRTIM_ADC3R_AD3MC4              HRTIM_ADC3R_AD3MC4_Msk      /*!< AD3MC4 */
#define HRTIM_ADC3R_AD3MPER_Pos        (4U)
#define HRTIM_ADC3R_AD3MPER_Msk        (0x1UL << HRTIM_ADC3R_AD3MPER_Pos)     /*!< 0x00000010 */
#define HRTIM_ADC3R_AD3MPER             HRTIM_ADC3R_AD3MPER_Msk     /*!< AD3MPER */
#define HRTIM_ADC3R_AD3EEV1_Pos        (5U)
#define HRTIM_ADC3R_AD3EEV1_Msk        (0x1UL << HRTIM_ADC3R_AD3EEV1_Pos)     /*!< 0x00000020 */
#define HRTIM_ADC3R_AD3EEV1             HRTIM_ADC3R_AD3EEV1_Msk     /*!< AD3EEV1 */
#define HRTIM_ADC3R_AD3EEV2_Pos        (6U)
#define HRTIM_ADC3R_AD3EEV2_Msk        (0x1UL << HRTIM_ADC3R_AD3EEV2_Pos)     /*!< 0x00000040 */
#define HRTIM_ADC3R_AD3EEV2             HRTIM_ADC3R_AD3EEV2_Msk     /*!< AD3EEV2 */
#define HRTIM_ADC3R_AD3EEV3_Pos        (7U)
#define HRTIM_ADC3R_AD3EEV3_Msk        (0x1UL << HRTIM_ADC3R_AD3EEV3_Pos)     /*!< 0x00000080 */
#define HRTIM_ADC3R_AD3EEV3             HRTIM_ADC3R_AD3EEV3_Msk     /*!< AD3EEV3 */
#define HRTIM_ADC3R_AD3EEV4_Pos        (8U)
#define HRTIM_ADC3R_AD3EEV4_Msk        (0x1UL << HRTIM_ADC3R_AD3EEV4_Pos)     /*!< 0x00000100 */
#define HRTIM_ADC3R_AD3EEV4             HRTIM_ADC3R_AD3EEV4_Msk     /*!< AD3EEV4 */
#define HRTIM_ADC3R_AD3EEV5_Pos        (9U)
#define HRTIM_ADC3R_AD3EEV5_Msk        (0x1UL << HRTIM_ADC3R_AD3EEV5_Pos)     /*!< 0x00000200 */
#define HRTIM_ADC3R_AD3EEV5             HRTIM_ADC3R_AD3EEV5_Msk     /*!< AD3EEV5 */
#define HRTIM_ADC3R_AD3TFC2_Pos        (10U)
#define HRTIM_ADC3R_AD3TFC2_Msk        (0x1UL << HRTIM_ADC3R_AD3TFC2_Pos)     /*!< 0x00000400 */
#define HRTIM_ADC3R_AD3TFC2             HRTIM_ADC3R_AD3TFC2_Msk     /*!< AD3TFC2 */
#define HRTIM_ADC3R_AD3TAC3_Pos        (11U)
#define HRTIM_ADC3R_AD3TAC3_Msk        (0x1UL << HRTIM_ADC3R_AD3TAC3_Pos)     /*!< 0x00000800 */
#define HRTIM_ADC3R_AD3TAC3             HRTIM_ADC3R_AD3TAC3_Msk     /*!< AD3TAC3 */
#define HRTIM_ADC3R_AD3TAC4_Pos        (12U)
#define HRTIM_ADC3R_AD3TAC4_Msk        (0x1UL << HRTIM_ADC3R_AD3TAC4_Pos)     /*!< 0x00001000 */
#define HRTIM_ADC3R_AD3TAC4             HRTIM_ADC3R_AD3TAC4_Msk     /*!< AD3TAC4 */
#define HRTIM_ADC3R_AD3TAPER_Pos       (13U)
#define HRTIM_ADC3R_AD3TAPER_Msk       (0x1UL << HRTIM_ADC3R_AD3TAPER_Pos)      /*!< 0x00002000 */
#define HRTIM_ADC3R_AD3TAPER            HRTIM_ADC3R_AD3TAPER_Msk    /*!< AD3TAPER */
#define HRTIM_ADC3R_AD3TARST_Pos       (14U)
#define HRTIM_ADC3R_AD3TARST_Msk       (0x1UL << HRTIM_ADC3R_AD3TARST_Pos)      /*!< 0x00004000 */
#define HRTIM_ADC3R_AD3TARST            HRTIM_ADC3R_AD3TARST_Msk    /*!< AD3TARST */
#define HRTIM_ADC3R_AD3TFC3_Pos        (15U)
#define HRTIM_ADC3R_AD3TFC3_Msk        (0x1UL << HRTIM_ADC3R_AD3TFC3_Pos)     /*!< 0x00008000 */
#define HRTIM_ADC3R_AD3TFC3             HRTIM_ADC3R_AD3TFC3_Msk     /*!< AD3TFC3 */
#define HRTIM_ADC3R_AD3TBC3_Pos        (16U)
#define HRTIM_ADC3R_AD3TBC3_Msk        (0x1UL << HRTIM_ADC3R_AD3TBC3_Pos)     /*!< 0x00010000 */
#define HRTIM_ADC3R_AD3TBC3             HRTIM_ADC3R_AD3TBC3_Msk     /*!< AD3TBC3 */
#define HRTIM_ADC3R_AD3TBC4_Pos        (17U)
#define HRTIM_ADC3R_AD3TBC4_Msk        (0x1UL << HRTIM_ADC3R_AD3TBC4_Pos)     /*!< 0x00020000 */
#define HRTIM_ADC3R_AD3TBC4             HRTIM_ADC3R_AD3TBC4_Msk     /*!< AD3TBC4 */
#define HRTIM_ADC3R_AD3TBPER_Pos       (18U)
#define HRTIM_ADC3R_AD3TBPER_Msk       (0x1UL << HRTIM_ADC3R_AD3TBPER_Pos)      /*!< 0x00040000 */
#define HRTIM_ADC3R_AD3TBPER            HRTIM_ADC3R_AD3TBPER_Msk    /*!< AD3TBPER */
#define HRTIM_ADC3R_AD3TBRST_Pos       (19U)
#define HRTIM_ADC3R_AD3TBRST_Msk       (0x1UL << HRTIM_ADC3R_AD3TBRST_Pos)      /*!< 0x00080000 */
#define HRTIM_ADC3R_AD3TBRST            HRTIM_ADC3R_AD3TBRST_Msk    /*!< AD3TBRST */
#define HRTIM_ADC3R_AD3TFC4_Pos        (20U)
#define HRTIM_ADC3R_AD3TFC4_Msk        (0x1UL << HRTIM_ADC3R_AD3TFC4_Pos)     /*!< 0x00100000 */
#define HRTIM_ADC3R_AD3TFC4             HRTIM_ADC3R_AD3TFC4_Msk     /*!< AD3TFC4 */
#define HRTIM_ADC3R_AD3TCC3_Pos        (21U)
#define HRTIM_ADC3R_AD3TCC3_Msk        (0x1UL << HRTIM_ADC3R_AD3TCC3_Pos)     /*!< 0x00200000 */
#define HRTIM_ADC3R_AD3TCC3             HRTIM_ADC3R_AD3TCC3_Msk     /*!< AD3TCC3 */
#define HRTIM_ADC3R_AD3TCC4_Pos        (22U)
#define HRTIM_ADC3R_AD3TCC4_Msk        (0x1UL << HRTIM_ADC3R_AD3TCC4_Pos)     /*!< 0x00400000 */
#define HRTIM_ADC3R_AD3TCC4             HRTIM_ADC3R_AD3TCC4_Msk     /*!< AD3TCC4 */
#define HRTIM_ADC3R_AD3TCPER_Pos       (23U)
#define HRTIM_ADC3R_AD3TCPER_Msk       (0x1UL << HRTIM_ADC3R_AD3TCPER_Pos)      /*!< 0x00800000 */
#define HRTIM_ADC3R_AD3TCPER            HRTIM_ADC3R_AD3TCPER_Msk    /*!< AD3TCPER */
#define HRTIM_ADC3R_AD3TFPER_Pos       (24U)
#define HRTIM_ADC3R_AD3TFPER_Msk       (0x1UL << HRTIM_ADC3R_AD3TFPER_Pos)      /*!< 0x01000000 */
#define HRTIM_ADC3R_AD3TFPER            HRTIM_ADC3R_AD3TFPER_Msk    /*!< AD3TFPER */
#define HRTIM_ADC3R_AD3TDC3_Pos        (25U)
#define HRTIM_ADC3R_AD3TDC3_Msk        (0x1UL << HRTIM_ADC3R_AD3TDC3_Pos)     /*!< 0x02000000 */
#define HRTIM_ADC3R_AD3TDC3             HRTIM_ADC3R_AD3TDC3_Msk     /*!< AD3TDC3 */
#define HRTIM_ADC3R_AD3TDC4_Pos        (26U)
#define HRTIM_ADC3R_AD3TDC4_Msk        (0x1UL << HRTIM_ADC3R_AD3TDC4_Pos)     /*!< 0x04000000 */
#define HRTIM_ADC3R_AD3TDC4             HRTIM_ADC3R_AD3TDC4_Msk     /*!< AD3TDC4 */
#define HRTIM_ADC3R_AD3TDPER_Pos       (27U)
#define HRTIM_ADC3R_AD3TDPER_Msk       (0x1UL << HRTIM_ADC3R_AD3TDPER_Pos)      /*!< 0x08000000 */
#define HRTIM_ADC3R_AD3TDPER            HRTIM_ADC3R_AD3TDPER_Msk    /*!< AD3TDPER */
#define HRTIM_ADC3R_AD3TFRST_Pos       (28U)
#define HRTIM_ADC3R_AD3TFRST_Msk       (0x1UL << HRTIM_ADC3R_AD3TFRST_Pos)      /*!< 0x10000000 */
#define HRTIM_ADC3R_AD3TFRST            HRTIM_ADC3R_AD3TFRST_Msk    /*!< AD3TFRST */
#define HRTIM_ADC3R_AD3TEC3_Pos        (29U)
#define HRTIM_ADC3R_AD3TEC3_Msk        (0x1UL << HRTIM_ADC3R_AD3TEC3_Pos)     /*!< 0x20000000 */
#define HRTIM_ADC3R_AD3TEC3             HRTIM_ADC3R_AD3TEC3_Msk     /*!< AD3TEC3 */
#define HRTIM_ADC3R_AD3TEC4_Pos        (30U)
#define HRTIM_ADC3R_AD3TEC4_Msk        (0x1UL << HRTIM_ADC3R_AD3TEC4_Pos)     /*!< 0x40000000 */
#define HRTIM_ADC3R_AD3TEC4             HRTIM_ADC3R_AD3TEC4_Msk     /*!< AD3TEC4 */
#define HRTIM_ADC3R_AD3TEPER_Pos       (31U)
#define HRTIM_ADC3R_AD3TEPER_Msk       (0x1UL << HRTIM_ADC3R_AD3TEPER_Pos)      /*!< 0x80000000 */
#define HRTIM_ADC3R_AD3TEPER            HRTIM_ADC3R_AD3TEPER_Msk    /*!< AD3TEPER */

/*************  Bit definition for HRTIM_ADC4R register  **************/
#define HRTIM_ADC4R_AD4MC1_Pos         (0U)
#define HRTIM_ADC4R_AD4MC1_Msk         (0x1UL << HRTIM_ADC4R_AD4MC1_Pos)    /*!< 0x00000001 */
#define HRTIM_ADC4R_AD4MC1              HRTIM_ADC4R_AD4MC1_Msk      /*!< AD4MC1 */
#define HRTIM_ADC4R_AD4MC2_Pos         (1U)
#define HRTIM_ADC4R_AD4MC2_Msk         (0x1UL << HRTIM_ADC4R_AD4MC2_Pos)    /*!< 0x00000002 */
#define HRTIM_ADC4R_AD4MC2              HRTIM_ADC4R_AD4MC2_Msk      /*!< AD4MC2 */
#define HRTIM_ADC4R_AD4MC3_Pos         (2U)
#define HRTIM_ADC4R_AD4MC3_Msk         (0x1UL << HRTIM_ADC4R_AD4MC3_Pos)    /*!< 0x00000004 */
#define HRTIM_ADC4R_AD4MC3              HRTIM_ADC4R_AD4MC3_Msk      /*!< AD4MC3 */
#define HRTIM_ADC4R_AD4MC4_Pos         (3U)
#define HRTIM_ADC4R_AD4MC4_Msk         (0x1UL << HRTIM_ADC4R_AD4MC4_Pos)    /*!< 0x00000008 */
#define HRTIM_ADC4R_AD4MC4              HRTIM_ADC4R_AD4MC4_Msk      /*!< AD4MC4 */
#define HRTIM_ADC4R_AD4MPER_Pos        (4U)
#define HRTIM_ADC4R_AD4MPER_Msk        (0x1UL << HRTIM_ADC4R_AD4MPER_Pos)     /*!< 0x00000010 */
#define HRTIM_ADC4R_AD4MPER             HRTIM_ADC4R_AD4MPER_Msk     /*!< AD4MPER */
#define HRTIM_ADC4R_AD4EEV6_Pos        (5U)
#define HRTIM_ADC4R_AD4EEV6_Msk        (0x1UL << HRTIM_ADC4R_AD4EEV6_Pos)     /*!< 0x00000020 */
#define HRTIM_ADC4R_AD4EEV6             HRTIM_ADC4R_AD4EEV6_Msk     /*!< AD4EEV6 */
#define HRTIM_ADC4R_AD4EEV7_Pos        (6U)
#define HRTIM_ADC4R_AD4EEV7_Msk        (0x1UL << HRTIM_ADC4R_AD4EEV7_Pos)     /*!< 0x00000040 */
#define HRTIM_ADC4R_AD4EEV7             HRTIM_ADC4R_AD4EEV7_Msk     /*!< AD4EEV7 */
#define HRTIM_ADC4R_AD4EEV8_Pos        (7U)
#define HRTIM_ADC4R_AD4EEV8_Msk        (0x1UL << HRTIM_ADC4R_AD4EEV8_Pos)     /*!< 0x00000080 */
#define HRTIM_ADC4R_AD4EEV8             HRTIM_ADC4R_AD4EEV8_Msk     /*!< AD4EEV8 */
#define HRTIM_ADC4R_AD4EEV9_Pos        (8U)
#define HRTIM_ADC4R_AD4EEV9_Msk        (0x1UL << HRTIM_ADC4R_AD4EEV9_Pos)     /*!< 0x00000100 */
#define HRTIM_ADC4R_AD4EEV9             HRTIM_ADC4R_AD4EEV9_Msk     /*!< AD4EEV9 */
#define HRTIM_ADC4R_AD4EEV10_Pos       (9U)
#define HRTIM_ADC4R_AD4EEV10_Msk       (0x1UL << HRTIM_ADC4R_AD4EEV10_Pos)      /*!< 0x00000200 */
#define HRTIM_ADC4R_AD4EEV10            HRTIM_ADC4R_AD4EEV10_Msk    /*!< AD4EEV10 */
#define HRTIM_ADC4R_AD4TAC2_Pos        (10U)
#define HRTIM_ADC4R_AD4TAC2_Msk        (0x1UL << HRTIM_ADC4R_AD4TAC2_Pos)     /*!< 0x00000400 */
#define HRTIM_ADC4R_AD4TAC2             HRTIM_ADC4R_AD4TAC2_Msk     /*!< AD4TAC2 */
#define HRTIM_ADC4R_AD4TFC2_Pos        (11U)
#define HRTIM_ADC4R_AD4TFC2_Msk        (0x1UL << HRTIM_ADC4R_AD4TFC2_Pos)     /*!< 0x00000800 */
#define HRTIM_ADC4R_AD4TFC2             HRTIM_ADC4R_AD4TFC2_Msk     /*!< AD4TFC2 */
#define HRTIM_ADC4R_AD4TAC4_Pos        (12U)
#define HRTIM_ADC4R_AD4TAC4_Msk        (0x1UL << HRTIM_ADC4R_AD4TAC4_Pos)     /*!< 0x00001000 */
#define HRTIM_ADC4R_AD4TAC4             HRTIM_ADC4R_AD4TAC4_Msk     /*!< AD4TAC4 */
#define HRTIM_ADC4R_AD4TAPER_Pos       (13U)
#define HRTIM_ADC4R_AD4TAPER_Msk       (0x1UL << HRTIM_ADC4R_AD4TAPER_Pos)      /*!< 0x00002000 */
#define HRTIM_ADC4R_AD4TAPER            HRTIM_ADC4R_AD4TAPER_Msk    /*!< AD4TAPER */
#define HRTIM_ADC4R_AD4TBC2_Pos        (14U)
#define HRTIM_ADC4R_AD4TBC2_Msk        (0x1UL << HRTIM_ADC4R_AD4TBC2_Pos)     /*!< 0x00004000 */
#define HRTIM_ADC4R_AD4TBC2             HRTIM_ADC4R_AD4TBC2_Msk     /*!< AD4TBC2 */
#define HRTIM_ADC4R_AD4TFC3_Pos        (15U)
#define HRTIM_ADC4R_AD4TFC3_Msk        (0x1UL << HRTIM_ADC4R_AD4TFC3_Pos)     /*!< 0x00008000 */
#define HRTIM_ADC4R_AD4TFC3             HRTIM_ADC4R_AD4TFC3_Msk     /*!< AD4TFC3 */
#define HRTIM_ADC4R_AD4TBC4_Pos        (16U)
#define HRTIM_ADC4R_AD4TBC4_Msk        (0x1UL << HRTIM_ADC4R_AD4TBC4_Pos)     /*!< 0x00010000 */
#define HRTIM_ADC4R_AD4TBC4             HRTIM_ADC4R_AD4TBC4_Msk     /*!< AD4TBC4 */
#define HRTIM_ADC4R_AD4TBPER_Pos       (17U)
#define HRTIM_ADC4R_AD4TBPER_Msk       (0x1UL << HRTIM_ADC4R_AD4TBPER_Pos)      /*!< 0x00020000 */
#define HRTIM_ADC4R_AD4TBPER            HRTIM_ADC4R_AD4TBPER_Msk    /*!< AD4TBPER */
#define HRTIM_ADC4R_AD4TCC2_Pos        (18U)
#define HRTIM_ADC4R_AD4TCC2_Msk        (0x1UL << HRTIM_ADC4R_AD4TCC2_Pos)     /*!< 0x00040000 */
#define HRTIM_ADC4R_AD4TCC2             HRTIM_ADC4R_AD4TCC2_Msk     /*!< AD4TCC2 */
#define HRTIM_ADC4R_AD4TFC4_Pos        (19U)
#define HRTIM_ADC4R_AD4TFC4_Msk        (0x1UL << HRTIM_ADC4R_AD4TFC4_Pos)     /*!< 0x00080000 */
#define HRTIM_ADC4R_AD4TFC4             HRTIM_ADC4R_AD4TFC4_Msk     /*!< AD4TFC4 */
#define HRTIM_ADC4R_AD4TCC4_Pos        (20U)
#define HRTIM_ADC4R_AD4TCC4_Msk        (0x1UL << HRTIM_ADC4R_AD4TCC4_Pos)     /*!< 0x00100000 */
#define HRTIM_ADC4R_AD4TCC4             HRTIM_ADC4R_AD4TCC4_Msk     /*!< AD4TCC4 */
#define HRTIM_ADC4R_AD4TCPER_Pos       (21U)
#define HRTIM_ADC4R_AD4TCPER_Msk       (0x1UL << HRTIM_ADC4R_AD4TCPER_Pos)      /*!< 0x00200000 */
#define HRTIM_ADC4R_AD4TCPER            HRTIM_ADC4R_AD4TCPER_Msk    /*!< AD4TCPER */
#define HRTIM_ADC4R_AD4TCRST_Pos       (22U)
#define HRTIM_ADC4R_AD4TCRST_Msk       (0x1UL << HRTIM_ADC4R_AD4TCRST_Pos)      /*!< 0x00400000 */
#define HRTIM_ADC4R_AD4TCRST            HRTIM_ADC4R_AD4TCRST_Msk    /*!< AD4TCRST */
#define HRTIM_ADC4R_AD4TDC2_Pos        (23U)
#define HRTIM_ADC4R_AD4TDC2_Msk        (0x1UL << HRTIM_ADC4R_AD4TDC2_Pos)     /*!< 0x00800000 */
#define HRTIM_ADC4R_AD4TDC2             HRTIM_ADC4R_AD4TDC2_Msk     /*!< AD4TDC2 */
#define HRTIM_ADC4R_AD4TFPER_Pos       (24U)
#define HRTIM_ADC4R_AD4TFPER_Msk       (0x1UL << HRTIM_ADC4R_AD4TFPER_Pos)      /*!< 0x01000000 */
#define HRTIM_ADC4R_AD4TFPER            HRTIM_ADC4R_AD4TFPER_Msk    /*!< AD4TFPER */
#define HRTIM_ADC4R_AD4TDC4_Pos        (25U)
#define HRTIM_ADC4R_AD4TDC4_Msk        (0x1UL << HRTIM_ADC4R_AD4TDC4_Pos)     /*!< 0x02000000 */
#define HRTIM_ADC4R_AD4TDC4             HRTIM_ADC4R_AD4TDC4_Msk     /*!< AD4TDC4 */
#define HRTIM_ADC4R_AD4TDPER_Pos       (26U)
#define HRTIM_ADC4R_AD4TDPER_Msk       (0x1UL << HRTIM_ADC4R_AD4TDPER_Pos)      /*!< 0x04000000 */
#define HRTIM_ADC4R_AD4TDPER            HRTIM_ADC4R_AD4TDPER_Msk    /*!< AD4TDPER */
#define HRTIM_ADC4R_AD4TDRST_Pos       (27U)
#define HRTIM_ADC4R_AD4TDRST_Msk       (0x1UL << HRTIM_ADC4R_AD4TDRST_Pos)      /*!< 0x08000000 */
#define HRTIM_ADC4R_AD4TDRST            HRTIM_ADC4R_AD4TDRST_Msk    /*!< AD4TDRST */
#define HRTIM_ADC4R_AD4TEC2_Pos        (28U)
#define HRTIM_ADC4R_AD4TEC2_Msk        (0x1UL << HRTIM_ADC4R_AD4TEC2_Pos)     /*!< 0x10000000 */
#define HRTIM_ADC4R_AD4TEC2             HRTIM_ADC4R_AD4TEC2_Msk     /*!< AD4TEC2 */
#define HRTIM_ADC4R_AD4TEC3_Pos        (29U)
#define HRTIM_ADC4R_AD4TEC3_Msk        (0x1UL << HRTIM_ADC4R_AD4TEC3_Pos)     /*!< 0x20000000 */
#define HRTIM_ADC4R_AD4TEC3             HRTIM_ADC4R_AD4TEC3_Msk     /*!< AD4TEC3 */
#define HRTIM_ADC4R_AD4TEC4_Pos        (30U)
#define HRTIM_ADC4R_AD4TEC4_Msk        (0x1UL << HRTIM_ADC4R_AD4TEC4_Pos)     /*!< 0x40000000 */
#define HRTIM_ADC4R_AD4TEC4             HRTIM_ADC4R_AD4TEC4_Msk     /*!< AD4TEC4 */
#define HRTIM_ADC4R_AD4TERST_Pos       (31U)
#define HRTIM_ADC4R_AD4TERST_Msk       (0x1UL << HRTIM_ADC4R_AD4TERST_Pos)      /*!< 0x80000000 */
#define HRTIM_ADC4R_AD4TERST            HRTIM_ADC4R_AD4TERST_Msk    /*!< AD4TERST */

/*************  Bit definition for HRTIM_DLLCR register  **************/
#define HRTIM_DLLCR_CAL_Pos            (0U)
#define HRTIM_DLLCR_CAL_Msk            (0x1UL << HRTIM_DLLCR_CAL_Pos) /*!< 0x00000001 */
#define HRTIM_DLLCR_CAL                 HRTIM_DLLCR_CAL_Msk         /*!< CAL */
#define HRTIM_DLLCR_CALEN_Pos          (1U)
#define HRTIM_DLLCR_CALEN_Msk          (0x1UL << HRTIM_DLLCR_CALEN_Pos)   /*!< 0x00000002 */
#define HRTIM_DLLCR_CALEN               HRTIM_DLLCR_CALEN_Msk       /*!< CALEN */
#define HRTIM_DLLCR_CALRTE_Pos         (2U)
#define HRTIM_DLLCR_CALRTE_Msk         (0x3UL << HRTIM_DLLCR_CALRTE_Pos)    /*!< 0x0000000C */
#define HRTIM_DLLCR_CALRTE              HRTIM_DLLCR_CALRTE_Msk      /*!< CALRTE */
#define HRTIM_DLLCR_CALRTE_0         (0x1UL << HRTIM_DLLCR_CALRTE_Pos)     /*!< 0x00000004 */
#define HRTIM_DLLCR_CALRTE_1         (0x2UL << HRTIM_DLLCR_CALRTE_Pos)     /*!< 0x00000008 */

/************  Bit definition for HRTIM_FLTINR1 register  *************/
#define HRTIM_FLTINR1_FLT1E_Pos        (0U)
#define HRTIM_FLTINR1_FLT1E_Msk        (0x1UL << HRTIM_FLTINR1_FLT1E_Pos)     /*!< 0x00000001 */
#define HRTIM_FLTINR1_FLT1E             HRTIM_FLTINR1_FLT1E_Msk     /*!< FLT1E */
#define HRTIM_FLTINR1_FLT1P_Pos        (1U)
#define HRTIM_FLTINR1_FLT1P_Msk        (0x1UL << HRTIM_FLTINR1_FLT1P_Pos)     /*!< 0x00000002 */
#define HRTIM_FLTINR1_FLT1P             HRTIM_FLTINR1_FLT1P_Msk     /*!< FLT1P */
#define HRTIM_FLTINR1_FLT1SRC_0_Pos    (2U)
#define HRTIM_FLTINR1_FLT1SRC_0_Msk    (0x1UL << HRTIM_FLTINR1_FLT1SRC_0_Pos)         /*!< 0x00000004 */
#define HRTIM_FLTINR1_FLT1SRC_0         HRTIM_FLTINR1_FLT1SRC_0_Msk /*!< FLT1SRC_0 */
#define HRTIM_FLTINR1_FLT1F_Pos        (3U)
#define HRTIM_FLTINR1_FLT1F_Msk        (0xFUL << HRTIM_FLTINR1_FLT1F_Pos)     /*!< 0x00000078 */
#define HRTIM_FLTINR1_FLT1F             HRTIM_FLTINR1_FLT1F_Msk     /*!< FLT1F */
#define HRTIM_FLTINR1_FLT1F_0        (0x1UL << HRTIM_FLTINR1_FLT1F_Pos)      /*!< 0x00000008 */
#define HRTIM_FLTINR1_FLT1F_1        (0x2UL << HRTIM_FLTINR1_FLT1F_Pos)      /*!< 0x00000010 */
#define HRTIM_FLTINR1_FLT1F_2        (0x4UL << HRTIM_FLTINR1_FLT1F_Pos)      /*!< 0x00000020 */
#define HRTIM_FLTINR1_FLT1F_3        (0x8UL << HRTIM_FLTINR1_FLT1F_Pos)      /*!< 0x00000040 */
#define HRTIM_FLTINR1_FLT1LCK_Pos      (7U)
#define HRTIM_FLTINR1_FLT1LCK_Msk      (0x1UL << HRTIM_FLTINR1_FLT1LCK_Pos)       /*!< 0x00000080 */
#define HRTIM_FLTINR1_FLT1LCK           HRTIM_FLTINR1_FLT1LCK_Msk   /*!< FLT1LCK */
#define HRTIM_FLTINR1_FLT2E_Pos        (8U)
#define HRTIM_FLTINR1_FLT2E_Msk        (0x1UL << HRTIM_FLTINR1_FLT2E_Pos)     /*!< 0x00000100 */
#define HRTIM_FLTINR1_FLT2E             HRTIM_FLTINR1_FLT2E_Msk     /*!< FLT2E */
#define HRTIM_FLTINR1_FLT2P_Pos        (9U)
#define HRTIM_FLTINR1_FLT2P_Msk        (0x1UL << HRTIM_FLTINR1_FLT2P_Pos)     /*!< 0x00000200 */
#define HRTIM_FLTINR1_FLT2P             HRTIM_FLTINR1_FLT2P_Msk     /*!< FLT2P */
#define HRTIM_FLTINR1_FLT2SRC_0_Pos    (10U)
#define HRTIM_FLTINR1_FLT2SRC_0_Msk    (0x1UL << HRTIM_FLTINR1_FLT2SRC_0_Pos)         /*!< 0x00000400 */
#define HRTIM_FLTINR1_FLT2SRC_0         HRTIM_FLTINR1_FLT2SRC_0_Msk /*!< FLT2SRC_0 */
#define HRTIM_FLTINR1_FLT2F_Pos        (11U)
#define HRTIM_FLTINR1_FLT2F_Msk        (0xFUL << HRTIM_FLTINR1_FLT2F_Pos)     /*!< 0x00007800 */
#define HRTIM_FLTINR1_FLT2F             HRTIM_FLTINR1_FLT2F_Msk     /*!< FLT2F */
#define HRTIM_FLTINR1_FLT2F_0        (0x1UL << HRTIM_FLTINR1_FLT2F_Pos)      /*!< 0x00000800 */
#define HRTIM_FLTINR1_FLT2F_1        (0x2UL << HRTIM_FLTINR1_FLT2F_Pos)      /*!< 0x00001000 */
#define HRTIM_FLTINR1_FLT2F_2        (0x4UL << HRTIM_FLTINR1_FLT2F_Pos)      /*!< 0x00002000 */
#define HRTIM_FLTINR1_FLT2F_3        (0x8UL << HRTIM_FLTINR1_FLT2F_Pos)      /*!< 0x00004000 */
#define HRTIM_FLTINR1_FLT2LCK_Pos      (15U)
#define HRTIM_FLTINR1_FLT2LCK_Msk      (0x1UL << HRTIM_FLTINR1_FLT2LCK_Pos)       /*!< 0x00008000 */
#define HRTIM_FLTINR1_FLT2LCK           HRTIM_FLTINR1_FLT2LCK_Msk   /*!< FLT2LCK */
#define HRTIM_FLTINR1_FLT3E_Pos        (16U)
#define HRTIM_FLTINR1_FLT3E_Msk        (0x1UL << HRTIM_FLTINR1_FLT3E_Pos)     /*!< 0x00010000 */
#define HRTIM_FLTINR1_FLT3E             HRTIM_FLTINR1_FLT3E_Msk     /*!< FLT3E */
#define HRTIM_FLTINR1_FLT3P_Pos        (17U)
#define HRTIM_FLTINR1_FLT3P_Msk        (0x1UL << HRTIM_FLTINR1_FLT3P_Pos)     /*!< 0x00020000 */
#define HRTIM_FLTINR1_FLT3P             HRTIM_FLTINR1_FLT3P_Msk     /*!< FLT3P */
#define HRTIM_FLTINR1_FLT3SRC_0_Pos    (18U)
#define HRTIM_FLTINR1_FLT3SRC_0_Msk    (0x1UL << HRTIM_FLTINR1_FLT3SRC_0_Pos)         /*!< 0x00040000 */
#define HRTIM_FLTINR1_FLT3SRC_0         HRTIM_FLTINR1_FLT3SRC_0_Msk /*!< FLT3SRC_0 */
#define HRTIM_FLTINR1_FLT3F_Pos        (19U)
#define HRTIM_FLTINR1_FLT3F_Msk        (0xFUL << HRTIM_FLTINR1_FLT3F_Pos)     /*!< 0x00780000 */
#define HRTIM_FLTINR1_FLT3F             HRTIM_FLTINR1_FLT3F_Msk     /*!< FLT3F */
#define HRTIM_FLTINR1_FLT3F_0        (0x1UL << HRTIM_FLTINR1_FLT3F_Pos)      /*!< 0x00080000 */
#define HRTIM_FLTINR1_FLT3F_1        (0x2UL << HRTIM_FLTINR1_FLT3F_Pos)      /*!< 0x00100000 */
#define HRTIM_FLTINR1_FLT3F_2        (0x4UL << HRTIM_FLTINR1_FLT3F_Pos)      /*!< 0x00200000 */
#define HRTIM_FLTINR1_FLT3F_3        (0x8UL << HRTIM_FLTINR1_FLT3F_Pos)      /*!< 0x00400000 */
#define HRTIM_FLTINR1_FLT3LCK_Pos      (23U)
#define HRTIM_FLTINR1_FLT3LCK_Msk      (0x1UL << HRTIM_FLTINR1_FLT3LCK_Pos)       /*!< 0x00800000 */
#define HRTIM_FLTINR1_FLT3LCK           HRTIM_FLTINR1_FLT3LCK_Msk   /*!< FLT3LCK */
#define HRTIM_FLTINR1_FLT4E_Pos        (24U)
#define HRTIM_FLTINR1_FLT4E_Msk        (0x1UL << HRTIM_FLTINR1_FLT4E_Pos)     /*!< 0x01000000 */
#define HRTIM_FLTINR1_FLT4E             HRTIM_FLTINR1_FLT4E_Msk     /*!< FLT4E */
#define HRTIM_FLTINR1_FLT4P_Pos        (25U)
#define HRTIM_FLTINR1_FLT4P_Msk        (0x1UL << HRTIM_FLTINR1_FLT4P_Pos)     /*!< 0x02000000 */
#define HRTIM_FLTINR1_FLT4P             HRTIM_FLTINR1_FLT4P_Msk     /*!< FLT4P */
#define HRTIM_FLTINR1_FLT4SRC_0_Pos    (26U)
#define HRTIM_FLTINR1_FLT4SRC_0_Msk    (0x1UL << HRTIM_FLTINR1_FLT4SRC_0_Pos)         /*!< 0x04000000 */
#define HRTIM_FLTINR1_FLT4SRC_0         HRTIM_FLTINR1_FLT4SRC_0_Msk /*!< FLT4SRC_0 */
#define HRTIM_FLTINR1_FLT4F_Pos        (27U)
#define HRTIM_FLTINR1_FLT4F_Msk        (0xFUL << HRTIM_FLTINR1_FLT4F_Pos)     /*!< 0x78000000 */
#define HRTIM_FLTINR1_FLT4F             HRTIM_FLTINR1_FLT4F_Msk     /*!< FLT4F */
#define HRTIM_FLTINR1_FLT4F_0        (0x1UL << HRTIM_FLTINR1_FLT4F_Pos)      /*!< 0x08000000 */
#define HRTIM_FLTINR1_FLT4F_1        (0x2UL << HRTIM_FLTINR1_FLT4F_Pos)      /*!< 0x10000000 */
#define HRTIM_FLTINR1_FLT4F_2        (0x4UL << HRTIM_FLTINR1_FLT4F_Pos)      /*!< 0x20000000 */
#define HRTIM_FLTINR1_FLT4F_3        (0x8UL << HRTIM_FLTINR1_FLT4F_Pos)      /*!< 0x40000000 */
#define HRTIM_FLTINR1_FLT4LCK_Pos      (31U)
#define HRTIM_FLTINR1_FLT4LCK_Msk      (0x1UL << HRTIM_FLTINR1_FLT4LCK_Pos)       /*!< 0x80000000 */
#define HRTIM_FLTINR1_FLT4LCK           HRTIM_FLTINR1_FLT4LCK_Msk   /*!< FLT4LCK */

/************  Bit definition for HRTIM_FLTINR2 register  *************/
#define HRTIM_FLTINR2_FLT5E_Pos        (0U)
#define HRTIM_FLTINR2_FLT5E_Msk        (0x1UL << HRTIM_FLTINR2_FLT5E_Pos)     /*!< 0x00000001 */
#define HRTIM_FLTINR2_FLT5E             HRTIM_FLTINR2_FLT5E_Msk     /*!< FLT5E */
#define HRTIM_FLTINR2_FLT5P_Pos        (1U)
#define HRTIM_FLTINR2_FLT5P_Msk        (0x1UL << HRTIM_FLTINR2_FLT5P_Pos)     /*!< 0x00000002 */
#define HRTIM_FLTINR2_FLT5P             HRTIM_FLTINR2_FLT5P_Msk     /*!< FLT5P */
#define HRTIM_FLTINR2_FLT5SRC_0_Pos    (2U)
#define HRTIM_FLTINR2_FLT5SRC_0_Msk    (0x1UL << HRTIM_FLTINR2_FLT5SRC_0_Pos)         /*!< 0x00000004 */
#define HRTIM_FLTINR2_FLT5SRC_0         HRTIM_FLTINR2_FLT5SRC_0_Msk /*!< FLT5SRC_0 */
#define HRTIM_FLTINR2_FLT5F_Pos        (3U)
#define HRTIM_FLTINR2_FLT5F_Msk        (0xFUL << HRTIM_FLTINR2_FLT5F_Pos)     /*!< 0x00000078 */
#define HRTIM_FLTINR2_FLT5F             HRTIM_FLTINR2_FLT5F_Msk     /*!< FLT5F */
#define HRTIM_FLTINR2_FLT5F_0        (0x1UL << HRTIM_FLTINR2_FLT5F_Pos)      /*!< 0x00000008 */
#define HRTIM_FLTINR2_FLT5F_1        (0x2UL << HRTIM_FLTINR2_FLT5F_Pos)      /*!< 0x00000010 */
#define HRTIM_FLTINR2_FLT5F_2        (0x4UL << HRTIM_FLTINR2_FLT5F_Pos)      /*!< 0x00000020 */
#define HRTIM_FLTINR2_FLT5F_3        (0x8UL << HRTIM_FLTINR2_FLT5F_Pos)      /*!< 0x00000040 */
#define HRTIM_FLTINR2_FLT5LCK_Pos      (7U)
#define HRTIM_FLTINR2_FLT5LCK_Msk      (0x1UL << HRTIM_FLTINR2_FLT5LCK_Pos)       /*!< 0x00000080 */
#define HRTIM_FLTINR2_FLT5LCK           HRTIM_FLTINR2_FLT5LCK_Msk   /*!< FLT5LCK */
#define HRTIM_FLTINR2_FLT6E_Pos        (8U)
#define HRTIM_FLTINR2_FLT6E_Msk        (0x1UL << HRTIM_FLTINR2_FLT6E_Pos)     /*!< 0x00000100 */
#define HRTIM_FLTINR2_FLT6E             HRTIM_FLTINR2_FLT6E_Msk     /*!< FLT6E */
#define HRTIM_FLTINR2_FLT6P_Pos        (9U)
#define HRTIM_FLTINR2_FLT6P_Msk        (0x1UL << HRTIM_FLTINR2_FLT6P_Pos)     /*!< 0x00000200 */
#define HRTIM_FLTINR2_FLT6P             HRTIM_FLTINR2_FLT6P_Msk     /*!< FLT6P */
#define HRTIM_FLTINR2_FLT6SRC_0_Pos    (10U)
#define HRTIM_FLTINR2_FLT6SRC_0_Msk    (0x1UL << HRTIM_FLTINR2_FLT6SRC_0_Pos)         /*!< 0x00000400 */
#define HRTIM_FLTINR2_FLT6SRC_0         HRTIM_FLTINR2_FLT6SRC_0_Msk /*!< FLT6SRC_0 */
#define HRTIM_FLTINR2_FLT6F_Pos        (11U)
#define HRTIM_FLTINR2_FLT6F_Msk        (0xFUL << HRTIM_FLTINR2_FLT6F_Pos)     /*!< 0x00007800 */
#define HRTIM_FLTINR2_FLT6F             HRTIM_FLTINR2_FLT6F_Msk     /*!< FLT6F */
#define HRTIM_FLTINR2_FLT6F_0        (0x1UL << HRTIM_FLTINR2_FLT6F_Pos)      /*!< 0x00000800 */
#define HRTIM_FLTINR2_FLT6F_1        (0x2UL << HRTIM_FLTINR2_FLT6F_Pos)      /*!< 0x00001000 */
#define HRTIM_FLTINR2_FLT6F_2        (0x4UL << HRTIM_FLTINR2_FLT6F_Pos)      /*!< 0x00002000 */
#define HRTIM_FLTINR2_FLT6F_3        (0x8UL << HRTIM_FLTINR2_FLT6F_Pos)      /*!< 0x00004000 */
#define HRTIM_FLTINR2_FLT6LCK_Pos      (15U)
#define HRTIM_FLTINR2_FLT6LCK_Msk      (0x1UL << HRTIM_FLTINR2_FLT6LCK_Pos)       /*!< 0x00008000 */
#define HRTIM_FLTINR2_FLT6LCK           HRTIM_FLTINR2_FLT6LCK_Msk   /*!< FLT6LCK */
#define HRTIM_FLTINR2_FLT1SRC_1_Pos    (16U)
#define HRTIM_FLTINR2_FLT1SRC_1_Msk    (0x1UL << HRTIM_FLTINR2_FLT1SRC_1_Pos)         /*!< 0x00010000 */
#define HRTIM_FLTINR2_FLT1SRC_1         HRTIM_FLTINR2_FLT1SRC_1_Msk /*!< FLT1SRC_1 */
#define HRTIM_FLTINR2_FLT2SRC_1_Pos    (17U)
#define HRTIM_FLTINR2_FLT2SRC_1_Msk    (0x1UL << HRTIM_FLTINR2_FLT2SRC_1_Pos)         /*!< 0x00020000 */
#define HRTIM_FLTINR2_FLT2SRC_1         HRTIM_FLTINR2_FLT2SRC_1_Msk /*!< FLT2SRC_1 */
#define HRTIM_FLTINR2_FLT3SRC_1_Pos    (18U)
#define HRTIM_FLTINR2_FLT3SRC_1_Msk    (0x1UL << HRTIM_FLTINR2_FLT3SRC_1_Pos)         /*!< 0x00040000 */
#define HRTIM_FLTINR2_FLT3SRC_1         HRTIM_FLTINR2_FLT3SRC_1_Msk /*!< FLT3SRC_1 */
#define HRTIM_FLTINR2_FLT4SRC_1_Pos    (19U)
#define HRTIM_FLTINR2_FLT4SRC_1_Msk    (0x1UL << HRTIM_FLTINR2_FLT4SRC_1_Pos)         /*!< 0x00080000 */
#define HRTIM_FLTINR2_FLT4SRC_1         HRTIM_FLTINR2_FLT4SRC_1_Msk /*!< FLT4SRC_1 */
#define HRTIM_FLTINR2_FLT5SRC_1_Pos    (20U)
#define HRTIM_FLTINR2_FLT5SRC_1_Msk    (0x1UL << HRTIM_FLTINR2_FLT5SRC_1_Pos)         /*!< 0x00100000 */
#define HRTIM_FLTINR2_FLT5SRC_1         HRTIM_FLTINR2_FLT5SRC_1_Msk /*!< FLT5SRC_1 */
#define HRTIM_FLTINR2_FLT6SRC_1_Pos    (21U)
#define HRTIM_FLTINR2_FLT6SRC_1_Msk    (0x1UL << HRTIM_FLTINR2_FLT6SRC_1_Pos)         /*!< 0x00200000 */
#define HRTIM_FLTINR2_FLT6SRC_1         HRTIM_FLTINR2_FLT6SRC_1_Msk /*!< FLT6SRC_1 */
#define HRTIM_FLTINR2_FLTSD_Pos        (24U)
#define HRTIM_FLTINR2_FLTSD_Msk        (0x3UL << HRTIM_FLTINR2_FLTSD_Pos)     /*!< 0x03000000 */
#define HRTIM_FLTINR2_FLTSD             HRTIM_FLTINR2_FLTSD_Msk     /*!< FLTSD */
#define HRTIM_FLTINR2_FLTSD_0        (0x1UL << HRTIM_FLTINR2_FLTSD_Pos)      /*!< 0x01000000 */
#define HRTIM_FLTINR2_FLTSD_1        (0x2UL << HRTIM_FLTINR2_FLTSD_Pos)      /*!< 0x02000000 */

/*************  Bit definition for HRTIM_BDMUPR register  *************/
#define HRTIM_BDMUPR_MCR_Pos           (0U)
#define HRTIM_BDMUPR_MCR_Msk           (0x1UL << HRTIM_BDMUPR_MCR_Pos)  /*!< 0x00000001 */
#define HRTIM_BDMUPR_MCR                HRTIM_BDMUPR_MCR_Msk        /*!< MCR */
#define HRTIM_BDMUPR_MICR_Pos          (1U)
#define HRTIM_BDMUPR_MICR_Msk          (0x1UL << HRTIM_BDMUPR_MICR_Pos)   /*!< 0x00000002 */
#define HRTIM_BDMUPR_MICR               HRTIM_BDMUPR_MICR_Msk       /*!< MICR */
#define HRTIM_BDMUPR_MDIER_Pos         (2U)
#define HRTIM_BDMUPR_MDIER_Msk         (0x1UL << HRTIM_BDMUPR_MDIER_Pos)    /*!< 0x00000004 */
#define HRTIM_BDMUPR_MDIER              HRTIM_BDMUPR_MDIER_Msk      /*!< MDIER */
#define HRTIM_BDMUPR_MCNT_Pos          (3U)
#define HRTIM_BDMUPR_MCNT_Msk          (0x1UL << HRTIM_BDMUPR_MCNT_Pos)   /*!< 0x00000008 */
#define HRTIM_BDMUPR_MCNT               HRTIM_BDMUPR_MCNT_Msk       /*!< MCNT */
#define HRTIM_BDMUPR_MPER_Pos          (4U)
#define HRTIM_BDMUPR_MPER_Msk          (0x1UL << HRTIM_BDMUPR_MPER_Pos)   /*!< 0x00000010 */
#define HRTIM_BDMUPR_MPER               HRTIM_BDMUPR_MPER_Msk       /*!< MPER */
#define HRTIM_BDMUPR_MREP_Pos          (5U)
#define HRTIM_BDMUPR_MREP_Msk          (0x1UL << HRTIM_BDMUPR_MREP_Pos)   /*!< 0x00000020 */
#define HRTIM_BDMUPR_MREP               HRTIM_BDMUPR_MREP_Msk       /*!< MREP */
#define HRTIM_BDMUPR_MCMP1_Pos         (6U)
#define HRTIM_BDMUPR_MCMP1_Msk         (0x1UL << HRTIM_BDMUPR_MCMP1_Pos)    /*!< 0x00000040 */
#define HRTIM_BDMUPR_MCMP1              HRTIM_BDMUPR_MCMP1_Msk      /*!< MCMP1 */
#define HRTIM_BDMUPR_MCMP2_Pos         (7U)
#define HRTIM_BDMUPR_MCMP2_Msk         (0x1UL << HRTIM_BDMUPR_MCMP2_Pos)    /*!< 0x00000080 */
#define HRTIM_BDMUPR_MCMP2              HRTIM_BDMUPR_MCMP2_Msk      /*!< MCMP2 */
#define HRTIM_BDMUPR_MCMP3_Pos         (8U)
#define HRTIM_BDMUPR_MCMP3_Msk         (0x1UL << HRTIM_BDMUPR_MCMP3_Pos)    /*!< 0x00000100 */
#define HRTIM_BDMUPR_MCMP3              HRTIM_BDMUPR_MCMP3_Msk      /*!< MCMP3 */
#define HRTIM_BDMUPR_MCMP4_Pos         (9U)
#define HRTIM_BDMUPR_MCMP4_Msk         (0x1UL << HRTIM_BDMUPR_MCMP4_Pos)    /*!< 0x00000200 */
#define HRTIM_BDMUPR_MCMP4              HRTIM_BDMUPR_MCMP4_Msk      /*!< MCMP4 */

/************  Bit definition for HRTIM_BDTAUPR register  *************/
#define HRTIM_BDTAUPR_TIMxCR_Pos       (0U)
#define HRTIM_BDTAUPR_TIMxCR_Msk       (0x1UL << HRTIM_BDTAUPR_TIMxCR_Pos)      /*!< 0x00000001 */
#define HRTIM_BDTAUPR_TIMxCR            HRTIM_BDTAUPR_TIMxCR_Msk    /*!< TIMxCR */
#define HRTIM_BDTAUPR_TIMxICR_Pos      (1U)
#define HRTIM_BDTAUPR_TIMxICR_Msk      (0x1UL << HRTIM_BDTAUPR_TIMxICR_Pos)       /*!< 0x00000002 */
#define HRTIM_BDTAUPR_TIMxICR           HRTIM_BDTAUPR_TIMxICR_Msk   /*!< TIMxICR */
#define HRTIM_BDTAUPR_TIMxDIER_Pos     (2U)
#define HRTIM_BDTAUPR_TIMxDIER_Msk     (0x1UL << HRTIM_BDTAUPR_TIMxDIER_Pos)        /*!< 0x00000004 */
#define HRTIM_BDTAUPR_TIMxDIER          HRTIM_BDTAUPR_TIMxDIER_Msk  /*!< TIMxDIER */
#define HRTIM_BDTAUPR_TIMCNT_Pos       (3U)
#define HRTIM_BDTAUPR_TIMCNT_Msk       (0x1UL << HRTIM_BDTAUPR_TIMCNT_Pos)      /*!< 0x00000008 */
#define HRTIM_BDTAUPR_TIMCNT            HRTIM_BDTAUPR_TIMCNT_Msk    /*!< TIMCNT */
#define HRTIM_BDTAUPR_TIMPER_Pos       (4U)
#define HRTIM_BDTAUPR_TIMPER_Msk       (0x1UL << HRTIM_BDTAUPR_TIMPER_Pos)      /*!< 0x00000010 */
#define HRTIM_BDTAUPR_TIMPER            HRTIM_BDTAUPR_TIMPER_Msk    /*!< TIMPER */
#define HRTIM_BDTAUPR_TIMREP_Pos       (5U)
#define HRTIM_BDTAUPR_TIMREP_Msk       (0x1UL << HRTIM_BDTAUPR_TIMREP_Pos)      /*!< 0x00000020 */
#define HRTIM_BDTAUPR_TIMREP            HRTIM_BDTAUPR_TIMREP_Msk    /*!< TIMREP */
#define HRTIM_BDTAUPR_TIMCMP1_Pos      (6U)
#define HRTIM_BDTAUPR_TIMCMP1_Msk      (0x1UL << HRTIM_BDTAUPR_TIMCMP1_Pos)       /*!< 0x00000040 */
#define HRTIM_BDTAUPR_TIMCMP1           HRTIM_BDTAUPR_TIMCMP1_Msk   /*!< TIMCMP1 */
#define HRTIM_BDTAUPR_TIMCMP2_Pos      (7U)
#define HRTIM_BDTAUPR_TIMCMP2_Msk      (0x1UL << HRTIM_BDTAUPR_TIMCMP2_Pos)       /*!< 0x00000080 */
#define HRTIM_BDTAUPR_TIMCMP2           HRTIM_BDTAUPR_TIMCMP2_Msk   /*!< TIMCMP2 */
#define HRTIM_BDTAUPR_TIMCMP3_Pos      (8U)
#define HRTIM_BDTAUPR_TIMCMP3_Msk      (0x1UL << HRTIM_BDTAUPR_TIMCMP3_Pos)       /*!< 0x00000100 */
#define HRTIM_BDTAUPR_TIMCMP3           HRTIM_BDTAUPR_TIMCMP3_Msk   /*!< TIMCMP3 */
#define HRTIM_BDTAUPR_TIMCMP4_Pos      (9U)
#define HRTIM_BDTAUPR_TIMCMP4_Msk      (0x1UL << HRTIM_BDTAUPR_TIMCMP4_Pos)       /*!< 0x00000200 */
#define HRTIM_BDTAUPR_TIMCMP4           HRTIM_BDTAUPR_TIMCMP4_Msk   /*!< TIMCMP4 */
#define HRTIM_BDTAUPR_TIMDTR_Pos       (10U)
#define HRTIM_BDTAUPR_TIMDTR_Msk       (0x1UL << HRTIM_BDTAUPR_TIMDTR_Pos)      /*!< 0x00000400 */
#define HRTIM_BDTAUPR_TIMDTR            HRTIM_BDTAUPR_TIMDTR_Msk    /*!< TIMDTR */
#define HRTIM_BDTAUPR_TIMSET1R_Pos     (11U)
#define HRTIM_BDTAUPR_TIMSET1R_Msk     (0x1UL << HRTIM_BDTAUPR_TIMSET1R_Pos)        /*!< 0x00000800 */
#define HRTIM_BDTAUPR_TIMSET1R          HRTIM_BDTAUPR_TIMSET1R_Msk  /*!< TIMSET1R */
#define HRTIM_BDTAUPR_TIMRST1R_Pos     (12U)
#define HRTIM_BDTAUPR_TIMRST1R_Msk     (0x1UL << HRTIM_BDTAUPR_TIMRST1R_Pos)        /*!< 0x00001000 */
#define HRTIM_BDTAUPR_TIMRST1R          HRTIM_BDTAUPR_TIMRST1R_Msk  /*!< TIMRST1R */
#define HRTIM_BDTAUPR_TIMSET2R_Pos     (13U)
#define HRTIM_BDTAUPR_TIMSET2R_Msk     (0x1UL << HRTIM_BDTAUPR_TIMSET2R_Pos)        /*!< 0x00002000 */
#define HRTIM_BDTAUPR_TIMSET2R          HRTIM_BDTAUPR_TIMSET2R_Msk  /*!< TIMSET2R */
#define HRTIM_BDTAUPR_TIMRST2R_Pos     (14U)
#define HRTIM_BDTAUPR_TIMRST2R_Msk     (0x1UL << HRTIM_BDTAUPR_TIMRST2R_Pos)        /*!< 0x00004000 */
#define HRTIM_BDTAUPR_TIMRST2R          HRTIM_BDTAUPR_TIMRST2R_Msk  /*!< TIMRST2R */
#define HRTIM_BDTAUPR_TIMEEFR1_Pos     (15U)
#define HRTIM_BDTAUPR_TIMEEFR1_Msk     (0x1UL << HRTIM_BDTAUPR_TIMEEFR1_Pos)        /*!< 0x00008000 */
#define HRTIM_BDTAUPR_TIMEEFR1          HRTIM_BDTAUPR_TIMEEFR1_Msk  /*!< TIMEEFR1 */
#define HRTIM_BDTAUPR_TIMEEFR2_Pos     (16U)
#define HRTIM_BDTAUPR_TIMEEFR2_Msk     (0x1UL << HRTIM_BDTAUPR_TIMEEFR2_Pos)        /*!< 0x00010000 */
#define HRTIM_BDTAUPR_TIMEEFR2          HRTIM_BDTAUPR_TIMEEFR2_Msk  /*!< TIMEEFR2 */
#define HRTIM_BDTAUPR_TIMRSTR_Pos      (17U)
#define HRTIM_BDTAUPR_TIMRSTR_Msk      (0x1UL << HRTIM_BDTAUPR_TIMRSTR_Pos)       /*!< 0x00020000 */
#define HRTIM_BDTAUPR_TIMRSTR           HRTIM_BDTAUPR_TIMRSTR_Msk   /*!< TIMRSTR */
#define HRTIM_BDTAUPR_TIMCHPR_Pos      (18U)
#define HRTIM_BDTAUPR_TIMCHPR_Msk      (0x1UL << HRTIM_BDTAUPR_TIMCHPR_Pos)       /*!< 0x00040000 */
#define HRTIM_BDTAUPR_TIMCHPR           HRTIM_BDTAUPR_TIMCHPR_Msk   /*!< TIMCHPR */
#define HRTIM_BDTAUPR_TIMOUTR_Pos      (19U)
#define HRTIM_BDTAUPR_TIMOUTR_Msk      (0x1UL << HRTIM_BDTAUPR_TIMOUTR_Pos)       /*!< 0x00080000 */
#define HRTIM_BDTAUPR_TIMOUTR           HRTIM_BDTAUPR_TIMOUTR_Msk   /*!< TIMOUTR */
#define HRTIM_BDTAUPR_TIMFLTR_Pos      (20U)
#define HRTIM_BDTAUPR_TIMFLTR_Msk      (0x1UL << HRTIM_BDTAUPR_TIMFLTR_Pos)       /*!< 0x00100000 */
#define HRTIM_BDTAUPR_TIMFLTR           HRTIM_BDTAUPR_TIMFLTR_Msk   /*!< TIMFLTR */
#define HRTIM_BDTAUPR_TIMxCR2_Pos      (21U)
#define HRTIM_BDTAUPR_TIMxCR2_Msk      (0x1UL << HRTIM_BDTAUPR_TIMxCR2_Pos)       /*!< 0x00200000 */
#define HRTIM_BDTAUPR_TIMxCR2           HRTIM_BDTAUPR_TIMxCR2_Msk   /*!< TIMxCR2 */
#define HRTIM_BDTAUPR_TIMEEFR3_Pos     (22U)
#define HRTIM_BDTAUPR_TIMEEFR3_Msk     (0x1UL << HRTIM_BDTAUPR_TIMEEFR3_Pos)        /*!< 0x00400000 */
#define HRTIM_BDTAUPR_TIMEEFR3          HRTIM_BDTAUPR_TIMEEFR3_Msk  /*!< TIMEEFR3 */

/************  Bit definition for HRTIM_BDTBUPR register  *************/
#define HRTIM_BDTBUPR_TIMxCR_Pos       (0U)
#define HRTIM_BDTBUPR_TIMxCR_Msk       (0x1UL << HRTIM_BDTBUPR_TIMxCR_Pos)      /*!< 0x00000001 */
#define HRTIM_BDTBUPR_TIMxCR            HRTIM_BDTBUPR_TIMxCR_Msk    /*!< TIMxCR */
#define HRTIM_BDTBUPR_TIMxICR_Pos      (1U)
#define HRTIM_BDTBUPR_TIMxICR_Msk      (0x1UL << HRTIM_BDTBUPR_TIMxICR_Pos)       /*!< 0x00000002 */
#define HRTIM_BDTBUPR_TIMxICR           HRTIM_BDTBUPR_TIMxICR_Msk   /*!< TIMxICR */
#define HRTIM_BDTBUPR_TIMxDIER_Pos     (2U)
#define HRTIM_BDTBUPR_TIMxDIER_Msk     (0x1UL << HRTIM_BDTBUPR_TIMxDIER_Pos)        /*!< 0x00000004 */
#define HRTIM_BDTBUPR_TIMxDIER          HRTIM_BDTBUPR_TIMxDIER_Msk  /*!< TIMxDIER */
#define HRTIM_BDTBUPR_TIMCNT_Pos       (3U)
#define HRTIM_BDTBUPR_TIMCNT_Msk       (0x1UL << HRTIM_BDTBUPR_TIMCNT_Pos)      /*!< 0x00000008 */
#define HRTIM_BDTBUPR_TIMCNT            HRTIM_BDTBUPR_TIMCNT_Msk    /*!< TIMCNT */
#define HRTIM_BDTBUPR_TIMPER_Pos       (4U)
#define HRTIM_BDTBUPR_TIMPER_Msk       (0x1UL << HRTIM_BDTBUPR_TIMPER_Pos)      /*!< 0x00000010 */
#define HRTIM_BDTBUPR_TIMPER            HRTIM_BDTBUPR_TIMPER_Msk    /*!< TIMPER */
#define HRTIM_BDTBUPR_TIMREP_Pos       (5U)
#define HRTIM_BDTBUPR_TIMREP_Msk       (0x1UL << HRTIM_BDTBUPR_TIMREP_Pos)      /*!< 0x00000020 */
#define HRTIM_BDTBUPR_TIMREP            HRTIM_BDTBUPR_TIMREP_Msk    /*!< TIMREP */
#define HRTIM_BDTBUPR_TIMCMP1_Pos      (6U)
#define HRTIM_BDTBUPR_TIMCMP1_Msk      (0x1UL << HRTIM_BDTBUPR_TIMCMP1_Pos)       /*!< 0x00000040 */
#define HRTIM_BDTBUPR_TIMCMP1           HRTIM_BDTBUPR_TIMCMP1_Msk   /*!< TIMCMP1 */
#define HRTIM_BDTBUPR_TIMCMP2_Pos      (7U)
#define HRTIM_BDTBUPR_TIMCMP2_Msk      (0x1UL << HRTIM_BDTBUPR_TIMCMP2_Pos)       /*!< 0x00000080 */
#define HRTIM_BDTBUPR_TIMCMP2           HRTIM_BDTBUPR_TIMCMP2_Msk   /*!< TIMCMP2 */
#define HRTIM_BDTBUPR_TIMCMP3_Pos      (8U)
#define HRTIM_BDTBUPR_TIMCMP3_Msk      (0x1UL << HRTIM_BDTBUPR_TIMCMP3_Pos)       /*!< 0x00000100 */
#define HRTIM_BDTBUPR_TIMCMP3           HRTIM_BDTBUPR_TIMCMP3_Msk   /*!< TIMCMP3 */
#define HRTIM_BDTBUPR_TIMCMP4_Pos      (9U)
#define HRTIM_BDTBUPR_TIMCMP4_Msk      (0x1UL << HRTIM_BDTBUPR_TIMCMP4_Pos)       /*!< 0x00000200 */
#define HRTIM_BDTBUPR_TIMCMP4           HRTIM_BDTBUPR_TIMCMP4_Msk   /*!< TIMCMP4 */
#define HRTIM_BDTBUPR_TIMDTR_Pos       (10U)
#define HRTIM_BDTBUPR_TIMDTR_Msk       (0x1UL << HRTIM_BDTBUPR_TIMDTR_Pos)      /*!< 0x00000400 */
#define HRTIM_BDTBUPR_TIMDTR            HRTIM_BDTBUPR_TIMDTR_Msk    /*!< TIMDTR */
#define HRTIM_BDTBUPR_TIMSET1R_Pos     (11U)
#define HRTIM_BDTBUPR_TIMSET1R_Msk     (0x1UL << HRTIM_BDTBUPR_TIMSET1R_Pos)        /*!< 0x00000800 */
#define HRTIM_BDTBUPR_TIMSET1R          HRTIM_BDTBUPR_TIMSET1R_Msk  /*!< TIMSET1R */
#define HRTIM_BDTBUPR_TIMRST1R_Pos     (12U)
#define HRTIM_BDTBUPR_TIMRST1R_Msk     (0x1UL << HRTIM_BDTBUPR_TIMRST1R_Pos)        /*!< 0x00001000 */
#define HRTIM_BDTBUPR_TIMRST1R          HRTIM_BDTBUPR_TIMRST1R_Msk  /*!< TIMRST1R */
#define HRTIM_BDTBUPR_TIMSET2R_Pos     (13U)
#define HRTIM_BDTBUPR_TIMSET2R_Msk     (0x1UL << HRTIM_BDTBUPR_TIMSET2R_Pos)        /*!< 0x00002000 */
#define HRTIM_BDTBUPR_TIMSET2R          HRTIM_BDTBUPR_TIMSET2R_Msk  /*!< TIMSET2R */
#define HRTIM_BDTBUPR_TIMRST2R_Pos     (14U)
#define HRTIM_BDTBUPR_TIMRST2R_Msk     (0x1UL << HRTIM_BDTBUPR_TIMRST2R_Pos)        /*!< 0x00004000 */
#define HRTIM_BDTBUPR_TIMRST2R          HRTIM_BDTBUPR_TIMRST2R_Msk  /*!< TIMRST2R */
#define HRTIM_BDTBUPR_TIMEEFR1_Pos     (15U)
#define HRTIM_BDTBUPR_TIMEEFR1_Msk     (0x1UL << HRTIM_BDTBUPR_TIMEEFR1_Pos)        /*!< 0x00008000 */
#define HRTIM_BDTBUPR_TIMEEFR1          HRTIM_BDTBUPR_TIMEEFR1_Msk  /*!< TIMEEFR1 */
#define HRTIM_BDTBUPR_TIMEEFR2_Pos     (16U)
#define HRTIM_BDTBUPR_TIMEEFR2_Msk     (0x1UL << HRTIM_BDTBUPR_TIMEEFR2_Pos)        /*!< 0x00010000 */
#define HRTIM_BDTBUPR_TIMEEFR2          HRTIM_BDTBUPR_TIMEEFR2_Msk  /*!< TIMEEFR2 */
#define HRTIM_BDTBUPR_TIMRSTR_Pos      (17U)
#define HRTIM_BDTBUPR_TIMRSTR_Msk      (0x1UL << HRTIM_BDTBUPR_TIMRSTR_Pos)       /*!< 0x00020000 */
#define HRTIM_BDTBUPR_TIMRSTR           HRTIM_BDTBUPR_TIMRSTR_Msk   /*!< TIMRSTR */
#define HRTIM_BDTBUPR_TIMCHPR_Pos      (18U)
#define HRTIM_BDTBUPR_TIMCHPR_Msk      (0x1UL << HRTIM_BDTBUPR_TIMCHPR_Pos)       /*!< 0x00040000 */
#define HRTIM_BDTBUPR_TIMCHPR           HRTIM_BDTBUPR_TIMCHPR_Msk   /*!< TIMCHPR */
#define HRTIM_BDTBUPR_TIMOUTR_Pos      (19U)
#define HRTIM_BDTBUPR_TIMOUTR_Msk      (0x1UL << HRTIM_BDTBUPR_TIMOUTR_Pos)       /*!< 0x00080000 */
#define HRTIM_BDTBUPR_TIMOUTR           HRTIM_BDTBUPR_TIMOUTR_Msk   /*!< TIMOUTR */
#define HRTIM_BDTBUPR_TIMFLTR_Pos      (20U)
#define HRTIM_BDTBUPR_TIMFLTR_Msk      (0x1UL << HRTIM_BDTBUPR_TIMFLTR_Pos)       /*!< 0x00100000 */
#define HRTIM_BDTBUPR_TIMFLTR           HRTIM_BDTBUPR_TIMFLTR_Msk   /*!< TIMFLTR */
#define HRTIM_BDTBUPR_TIMxCR2_Pos      (21U)
#define HRTIM_BDTBUPR_TIMxCR2_Msk      (0x1UL << HRTIM_BDTBUPR_TIMxCR2_Pos)       /*!< 0x00200000 */
#define HRTIM_BDTBUPR_TIMxCR2           HRTIM_BDTBUPR_TIMxCR2_Msk   /*!< TIMxCR2 */
#define HRTIM_BDTBUPR_TIMEEFR3_Pos     (22U)
#define HRTIM_BDTBUPR_TIMEEFR3_Msk     (0x1UL << HRTIM_BDTBUPR_TIMEEFR3_Pos)        /*!< 0x00400000 */
#define HRTIM_BDTBUPR_TIMEEFR3          HRTIM_BDTBUPR_TIMEEFR3_Msk  /*!< TIMEEFR3 */

/************  Bit definition for HRTIM_BDTCUPR register  *************/
#define HRTIM_BDTCUPR_TIMxCR_Pos       (0U)
#define HRTIM_BDTCUPR_TIMxCR_Msk       (0x1UL << HRTIM_BDTCUPR_TIMxCR_Pos)      /*!< 0x00000001 */
#define HRTIM_BDTCUPR_TIMxCR            HRTIM_BDTCUPR_TIMxCR_Msk    /*!< TIMxCR */
#define HRTIM_BDTCUPR_TIMxICR_Pos      (1U)
#define HRTIM_BDTCUPR_TIMxICR_Msk      (0x1UL << HRTIM_BDTCUPR_TIMxICR_Pos)       /*!< 0x00000002 */
#define HRTIM_BDTCUPR_TIMxICR           HRTIM_BDTCUPR_TIMxICR_Msk   /*!< TIMxICR */
#define HRTIM_BDTCUPR_TIMxDIER_Pos     (2U)
#define HRTIM_BDTCUPR_TIMxDIER_Msk     (0x1UL << HRTIM_BDTCUPR_TIMxDIER_Pos)        /*!< 0x00000004 */
#define HRTIM_BDTCUPR_TIMxDIER          HRTIM_BDTCUPR_TIMxDIER_Msk  /*!< TIMxDIER */
#define HRTIM_BDTCUPR_TIMCNT_Pos       (3U)
#define HRTIM_BDTCUPR_TIMCNT_Msk       (0x1UL << HRTIM_BDTCUPR_TIMCNT_Pos)      /*!< 0x00000008 */
#define HRTIM_BDTCUPR_TIMCNT            HRTIM_BDTCUPR_TIMCNT_Msk    /*!< TIMCNT */
#define HRTIM_BDTCUPR_TIMPER_Pos       (4U)
#define HRTIM_BDTCUPR_TIMPER_Msk       (0x1UL << HRTIM_BDTCUPR_TIMPER_Pos)      /*!< 0x00000010 */
#define HRTIM_BDTCUPR_TIMPER            HRTIM_BDTCUPR_TIMPER_Msk    /*!< TIMPER */
#define HRTIM_BDTCUPR_TIMREP_Pos       (5U)
#define HRTIM_BDTCUPR_TIMREP_Msk       (0x1UL << HRTIM_BDTCUPR_TIMREP_Pos)      /*!< 0x00000020 */
#define HRTIM_BDTCUPR_TIMREP            HRTIM_BDTCUPR_TIMREP_Msk    /*!< TIMREP */
#define HRTIM_BDTCUPR_TIMCMP1_Pos      (6U)
#define HRTIM_BDTCUPR_TIMCMP1_Msk      (0x1UL << HRTIM_BDTCUPR_TIMCMP1_Pos)       /*!< 0x00000040 */
#define HRTIM_BDTCUPR_TIMCMP1           HRTIM_BDTCUPR_TIMCMP1_Msk   /*!< TIMCMP1 */
#define HRTIM_BDTCUPR_TIMCMP2_Pos      (7U)
#define HRTIM_BDTCUPR_TIMCMP2_Msk      (0x1UL << HRTIM_BDTCUPR_TIMCMP2_Pos)       /*!< 0x00000080 */
#define HRTIM_BDTCUPR_TIMCMP2           HRTIM_BDTCUPR_TIMCMP2_Msk   /*!< TIMCMP2 */
#define HRTIM_BDTCUPR_TIMCMP3_Pos      (8U)
#define HRTIM_BDTCUPR_TIMCMP3_Msk      (0x1UL << HRTIM_BDTCUPR_TIMCMP3_Pos)       /*!< 0x00000100 */
#define HRTIM_BDTCUPR_TIMCMP3           HRTIM_BDTCUPR_TIMCMP3_Msk   /*!< TIMCMP3 */
#define HRTIM_BDTCUPR_TIMCMP4_Pos      (9U)
#define HRTIM_BDTCUPR_TIMCMP4_Msk      (0x1UL << HRTIM_BDTCUPR_TIMCMP4_Pos)       /*!< 0x00000200 */
#define HRTIM_BDTCUPR_TIMCMP4           HRTIM_BDTCUPR_TIMCMP4_Msk   /*!< TIMCMP4 */
#define HRTIM_BDTCUPR_TIMDTR_Pos       (10U)
#define HRTIM_BDTCUPR_TIMDTR_Msk       (0x1UL << HRTIM_BDTCUPR_TIMDTR_Pos)      /*!< 0x00000400 */
#define HRTIM_BDTCUPR_TIMDTR            HRTIM_BDTCUPR_TIMDTR_Msk    /*!< TIMDTR */
#define HRTIM_BDTCUPR_TIMSET1R_Pos     (11U)
#define HRTIM_BDTCUPR_TIMSET1R_Msk     (0x1UL << HRTIM_BDTCUPR_TIMSET1R_Pos)        /*!< 0x00000800 */
#define HRTIM_BDTCUPR_TIMSET1R          HRTIM_BDTCUPR_TIMSET1R_Msk  /*!< TIMSET1R */
#define HRTIM_BDTCUPR_TIMRST1R_Pos     (12U)
#define HRTIM_BDTCUPR_TIMRST1R_Msk     (0x1UL << HRTIM_BDTCUPR_TIMRST1R_Pos)        /*!< 0x00001000 */
#define HRTIM_BDTCUPR_TIMRST1R          HRTIM_BDTCUPR_TIMRST1R_Msk  /*!< TIMRST1R */
#define HRTIM_BDTCUPR_TIMSET2R_Pos     (13U)
#define HRTIM_BDTCUPR_TIMSET2R_Msk     (0x1UL << HRTIM_BDTCUPR_TIMSET2R_Pos)        /*!< 0x00002000 */
#define HRTIM_BDTCUPR_TIMSET2R          HRTIM_BDTCUPR_TIMSET2R_Msk  /*!< TIMSET2R */
#define HRTIM_BDTCUPR_TIMRST2R_Pos     (14U)
#define HRTIM_BDTCUPR_TIMRST2R_Msk     (0x1UL << HRTIM_BDTCUPR_TIMRST2R_Pos)        /*!< 0x00004000 */
#define HRTIM_BDTCUPR_TIMRST2R          HRTIM_BDTCUPR_TIMRST2R_Msk  /*!< TIMRST2R */
#define HRTIM_BDTCUPR_TIMEEFR1_Pos     (15U)
#define HRTIM_BDTCUPR_TIMEEFR1_Msk     (0x1UL << HRTIM_BDTCUPR_TIMEEFR1_Pos)        /*!< 0x00008000 */
#define HRTIM_BDTCUPR_TIMEEFR1          HRTIM_BDTCUPR_TIMEEFR1_Msk  /*!< TIMEEFR1 */
#define HRTIM_BDTCUPR_TIMEEFR2_Pos     (16U)
#define HRTIM_BDTCUPR_TIMEEFR2_Msk     (0x1UL << HRTIM_BDTCUPR_TIMEEFR2_Pos)        /*!< 0x00010000 */
#define HRTIM_BDTCUPR_TIMEEFR2          HRTIM_BDTCUPR_TIMEEFR2_Msk  /*!< TIMEEFR2 */
#define HRTIM_BDTCUPR_TIMRSTR_Pos      (17U)
#define HRTIM_BDTCUPR_TIMRSTR_Msk      (0x1UL << HRTIM_BDTCUPR_TIMRSTR_Pos)       /*!< 0x00020000 */
#define HRTIM_BDTCUPR_TIMRSTR           HRTIM_BDTCUPR_TIMRSTR_Msk   /*!< TIMRSTR */
#define HRTIM_BDTCUPR_TIMCHPR_Pos      (18U)
#define HRTIM_BDTCUPR_TIMCHPR_Msk      (0x1UL << HRTIM_BDTCUPR_TIMCHPR_Pos)       /*!< 0x00040000 */
#define HRTIM_BDTCUPR_TIMCHPR           HRTIM_BDTCUPR_TIMCHPR_Msk   /*!< TIMCHPR */
#define HRTIM_BDTCUPR_TIMOUTR_Pos      (19U)
#define HRTIM_BDTCUPR_TIMOUTR_Msk      (0x1UL << HRTIM_BDTCUPR_TIMOUTR_Pos)       /*!< 0x00080000 */
#define HRTIM_BDTCUPR_TIMOUTR           HRTIM_BDTCUPR_TIMOUTR_Msk   /*!< TIMOUTR */
#define HRTIM_BDTCUPR_TIMFLTR_Pos      (20U)
#define HRTIM_BDTCUPR_TIMFLTR_Msk      (0x1UL << HRTIM_BDTCUPR_TIMFLTR_Pos)       /*!< 0x00100000 */
#define HRTIM_BDTCUPR_TIMFLTR           HRTIM_BDTCUPR_TIMFLTR_Msk   /*!< TIMFLTR */
#define HRTIM_BDTCUPR_TIMxCR2_Pos      (21U)
#define HRTIM_BDTCUPR_TIMxCR2_Msk      (0x1UL << HRTIM_BDTCUPR_TIMxCR2_Pos)       /*!< 0x00200000 */
#define HRTIM_BDTCUPR_TIMxCR2           HRTIM_BDTCUPR_TIMxCR2_Msk   /*!< TIMxCR2 */
#define HRTIM_BDTCUPR_TIMEEFR3_Pos     (22U)
#define HRTIM_BDTCUPR_TIMEEFR3_Msk     (0x1UL << HRTIM_BDTCUPR_TIMEEFR3_Pos)        /*!< 0x00400000 */
#define HRTIM_BDTCUPR_TIMEEFR3          HRTIM_BDTCUPR_TIMEEFR3_Msk  /*!< TIMEEFR3 */

/************  Bit definition for HRTIM_BDTDUPR register  *************/
#define HRTIM_BDTDUPR_TIMxCR_Pos       (0U)
#define HRTIM_BDTDUPR_TIMxCR_Msk       (0x1UL << HRTIM_BDTDUPR_TIMxCR_Pos)      /*!< 0x00000001 */
#define HRTIM_BDTDUPR_TIMxCR            HRTIM_BDTDUPR_TIMxCR_Msk    /*!< TIMxCR */
#define HRTIM_BDTDUPR_TIMxICR_Pos      (1U)
#define HRTIM_BDTDUPR_TIMxICR_Msk      (0x1UL << HRTIM_BDTDUPR_TIMxICR_Pos)       /*!< 0x00000002 */
#define HRTIM_BDTDUPR_TIMxICR           HRTIM_BDTDUPR_TIMxICR_Msk   /*!< TIMxICR */
#define HRTIM_BDTDUPR_TIMxDIER_Pos     (2U)
#define HRTIM_BDTDUPR_TIMxDIER_Msk     (0x1UL << HRTIM_BDTDUPR_TIMxDIER_Pos)        /*!< 0x00000004 */
#define HRTIM_BDTDUPR_TIMxDIER          HRTIM_BDTDUPR_TIMxDIER_Msk  /*!< TIMxDIER */
#define HRTIM_BDTDUPR_TIMCNT_Pos       (3U)
#define HRTIM_BDTDUPR_TIMCNT_Msk       (0x1UL << HRTIM_BDTDUPR_TIMCNT_Pos)      /*!< 0x00000008 */
#define HRTIM_BDTDUPR_TIMCNT            HRTIM_BDTDUPR_TIMCNT_Msk    /*!< TIMCNT */
#define HRTIM_BDTDUPR_TIMPER_Pos       (4U)
#define HRTIM_BDTDUPR_TIMPER_Msk       (0x1UL << HRTIM_BDTDUPR_TIMPER_Pos)      /*!< 0x00000010 */
#define HRTIM_BDTDUPR_TIMPER            HRTIM_BDTDUPR_TIMPER_Msk    /*!< TIMPER */
#define HRTIM_BDTDUPR_TIMREP_Pos       (5U)
#define HRTIM_BDTDUPR_TIMREP_Msk       (0x1UL << HRTIM_BDTDUPR_TIMREP_Pos)      /*!< 0x00000020 */
#define HRTIM_BDTDUPR_TIMREP            HRTIM_BDTDUPR_TIMREP_Msk    /*!< TIMREP */
#define HRTIM_BDTDUPR_TIMCMP1_Pos      (6U)
#define HRTIM_BDTDUPR_TIMCMP1_Msk      (0x1UL << HRTIM_BDTDUPR_TIMCMP1_Pos)       /*!< 0x00000040 */
#define HRTIM_BDTDUPR_TIMCMP1           HRTIM_BDTDUPR_TIMCMP1_Msk   /*!< TIMCMP1 */
#define HRTIM_BDTDUPR_TIMCMP2_Pos      (7U)
#define HRTIM_BDTDUPR_TIMCMP2_Msk      (0x1UL << HRTIM_BDTDUPR_TIMCMP2_Pos)       /*!< 0x00000080 */
#define HRTIM_BDTDUPR_TIMCMP2           HRTIM_BDTDUPR_TIMCMP2_Msk   /*!< TIMCMP2 */
#define HRTIM_BDTDUPR_TIMCMP3_Pos      (8U)
#define HRTIM_BDTDUPR_TIMCMP3_Msk      (0x1UL << HRTIM_BDTDUPR_TIMCMP3_Pos)       /*!< 0x00000100 */
#define HRTIM_BDTDUPR_TIMCMP3           HRTIM_BDTDUPR_TIMCMP3_Msk   /*!< TIMCMP3 */
#define HRTIM_BDTDUPR_TIMCMP4_Pos      (9U)
#define HRTIM_BDTDUPR_TIMCMP4_Msk      (0x1UL << HRTIM_BDTDUPR_TIMCMP4_Pos)       /*!< 0x00000200 */
#define HRTIM_BDTDUPR_TIMCMP4           HRTIM_BDTDUPR_TIMCMP4_Msk   /*!< TIMCMP4 */
#define HRTIM_BDTDUPR_TIMDTR_Pos       (10U)
#define HRTIM_BDTDUPR_TIMDTR_Msk       (0x1UL << HRTIM_BDTDUPR_TIMDTR_Pos)      /*!< 0x00000400 */
#define HRTIM_BDTDUPR_TIMDTR            HRTIM_BDTDUPR_TIMDTR_Msk    /*!< TIMDTR */
#define HRTIM_BDTDUPR_TIMSET1R_Pos     (11U)
#define HRTIM_BDTDUPR_TIMSET1R_Msk     (0x1UL << HRTIM_BDTDUPR_TIMSET1R_Pos)        /*!< 0x00000800 */
#define HRTIM_BDTDUPR_TIMSET1R          HRTIM_BDTDUPR_TIMSET1R_Msk  /*!< TIMSET1R */
#define HRTIM_BDTDUPR_TIMRST1R_Pos     (12U)
#define HRTIM_BDTDUPR_TIMRST1R_Msk     (0x1UL << HRTIM_BDTDUPR_TIMRST1R_Pos)        /*!< 0x00001000 */
#define HRTIM_BDTDUPR_TIMRST1R          HRTIM_BDTDUPR_TIMRST1R_Msk  /*!< TIMRST1R */
#define HRTIM_BDTDUPR_TIMSET2R_Pos     (13U)
#define HRTIM_BDTDUPR_TIMSET2R_Msk     (0x1UL << HRTIM_BDTDUPR_TIMSET2R_Pos)        /*!< 0x00002000 */
#define HRTIM_BDTDUPR_TIMSET2R          HRTIM_BDTDUPR_TIMSET2R_Msk  /*!< TIMSET2R */
#define HRTIM_BDTDUPR_TIMRST2R_Pos     (14U)
#define HRTIM_BDTDUPR_TIMRST2R_Msk     (0x1UL << HRTIM_BDTDUPR_TIMRST2R_Pos)        /*!< 0x00004000 */
#define HRTIM_BDTDUPR_TIMRST2R          HRTIM_BDTDUPR_TIMRST2R_Msk  /*!< TIMRST2R */
#define HRTIM_BDTDUPR_TIMEEFR1_Pos     (15U)
#define HRTIM_BDTDUPR_TIMEEFR1_Msk     (0x1UL << HRTIM_BDTDUPR_TIMEEFR1_Pos)        /*!< 0x00008000 */
#define HRTIM_BDTDUPR_TIMEEFR1          HRTIM_BDTDUPR_TIMEEFR1_Msk  /*!< TIMEEFR1 */
#define HRTIM_BDTDUPR_TIMEEFR2_Pos     (16U)
#define HRTIM_BDTDUPR_TIMEEFR2_Msk     (0x1UL << HRTIM_BDTDUPR_TIMEEFR2_Pos)        /*!< 0x00010000 */
#define HRTIM_BDTDUPR_TIMEEFR2          HRTIM_BDTDUPR_TIMEEFR2_Msk  /*!< TIMEEFR2 */
#define HRTIM_BDTDUPR_TIMRSTR_Pos      (17U)
#define HRTIM_BDTDUPR_TIMRSTR_Msk      (0x1UL << HRTIM_BDTDUPR_TIMRSTR_Pos)       /*!< 0x00020000 */
#define HRTIM_BDTDUPR_TIMRSTR           HRTIM_BDTDUPR_TIMRSTR_Msk   /*!< TIMRSTR */
#define HRTIM_BDTDUPR_TIMCHPR_Pos      (18U)
#define HRTIM_BDTDUPR_TIMCHPR_Msk      (0x1UL << HRTIM_BDTDUPR_TIMCHPR_Pos)       /*!< 0x00040000 */
#define HRTIM_BDTDUPR_TIMCHPR           HRTIM_BDTDUPR_TIMCHPR_Msk   /*!< TIMCHPR */
#define HRTIM_BDTDUPR_TIMOUTR_Pos      (19U)
#define HRTIM_BDTDUPR_TIMOUTR_Msk      (0x1UL << HRTIM_BDTDUPR_TIMOUTR_Pos)       /*!< 0x00080000 */
#define HRTIM_BDTDUPR_TIMOUTR           HRTIM_BDTDUPR_TIMOUTR_Msk   /*!< TIMOUTR */
#define HRTIM_BDTDUPR_TIMFLTR_Pos      (20U)
#define HRTIM_BDTDUPR_TIMFLTR_Msk      (0x1UL << HRTIM_BDTDUPR_TIMFLTR_Pos)       /*!< 0x00100000 */
#define HRTIM_BDTDUPR_TIMFLTR           HRTIM_BDTDUPR_TIMFLTR_Msk   /*!< TIMFLTR */
#define HRTIM_BDTDUPR_TIMxCR2_Pos      (21U)
#define HRTIM_BDTDUPR_TIMxCR2_Msk      (0x1UL << HRTIM_BDTDUPR_TIMxCR2_Pos)       /*!< 0x00200000 */
#define HRTIM_BDTDUPR_TIMxCR2           HRTIM_BDTDUPR_TIMxCR2_Msk   /*!< TIMxCR2 */
#define HRTIM_BDTDUPR_TIMEEFR3_Pos     (22U)
#define HRTIM_BDTDUPR_TIMEEFR3_Msk     (0x1UL << HRTIM_BDTDUPR_TIMEEFR3_Pos)        /*!< 0x00400000 */
#define HRTIM_BDTDUPR_TIMEEFR3          HRTIM_BDTDUPR_TIMEEFR3_Msk  /*!< TIMEEFR3 */

/************  Bit definition for HRTIM_BDTEUPR register  *************/
#define HRTIM_BDTEUPR_TIMxCR_Pos       (0U)
#define HRTIM_BDTEUPR_TIMxCR_Msk       (0x1UL << HRTIM_BDTEUPR_TIMxCR_Pos)      /*!< 0x00000001 */
#define HRTIM_BDTEUPR_TIMxCR            HRTIM_BDTEUPR_TIMxCR_Msk    /*!< TIMxCR */
#define HRTIM_BDTEUPR_TIMxICR_Pos      (1U)
#define HRTIM_BDTEUPR_TIMxICR_Msk      (0x1UL << HRTIM_BDTEUPR_TIMxICR_Pos)       /*!< 0x00000002 */
#define HRTIM_BDTEUPR_TIMxICR           HRTIM_BDTEUPR_TIMxICR_Msk   /*!< TIMxICR */
#define HRTIM_BDTEUPR_TIMxDIER_Pos     (2U)
#define HRTIM_BDTEUPR_TIMxDIER_Msk     (0x1UL << HRTIM_BDTEUPR_TIMxDIER_Pos)        /*!< 0x00000004 */
#define HRTIM_BDTEUPR_TIMxDIER          HRTIM_BDTEUPR_TIMxDIER_Msk  /*!< TIMxDIER */
#define HRTIM_BDTEUPR_TIMCNT_Pos       (3U)
#define HRTIM_BDTEUPR_TIMCNT_Msk       (0x1UL << HRTIM_BDTEUPR_TIMCNT_Pos)      /*!< 0x00000008 */
#define HRTIM_BDTEUPR_TIMCNT            HRTIM_BDTEUPR_TIMCNT_Msk    /*!< TIMCNT */
#define HRTIM_BDTEUPR_TIMPER_Pos       (4U)
#define HRTIM_BDTEUPR_TIMPER_Msk       (0x1UL << HRTIM_BDTEUPR_TIMPER_Pos)      /*!< 0x00000010 */
#define HRTIM_BDTEUPR_TIMPER            HRTIM_BDTEUPR_TIMPER_Msk    /*!< TIMPER */
#define HRTIM_BDTEUPR_TIMREP_Pos       (5U)
#define HRTIM_BDTEUPR_TIMREP_Msk       (0x1UL << HRTIM_BDTEUPR_TIMREP_Pos)      /*!< 0x00000020 */
#define HRTIM_BDTEUPR_TIMREP            HRTIM_BDTEUPR_TIMREP_Msk    /*!< TIMREP */
#define HRTIM_BDTEUPR_TIMCMP1_Pos      (6U)
#define HRTIM_BDTEUPR_TIMCMP1_Msk      (0x1UL << HRTIM_BDTEUPR_TIMCMP1_Pos)       /*!< 0x00000040 */
#define HRTIM_BDTEUPR_TIMCMP1           HRTIM_BDTEUPR_TIMCMP1_Msk   /*!< TIMCMP1 */
#define HRTIM_BDTEUPR_TIMCMP2_Pos      (7U)
#define HRTIM_BDTEUPR_TIMCMP2_Msk      (0x1UL << HRTIM_BDTEUPR_TIMCMP2_Pos)       /*!< 0x00000080 */
#define HRTIM_BDTEUPR_TIMCMP2           HRTIM_BDTEUPR_TIMCMP2_Msk   /*!< TIMCMP2 */
#define HRTIM_BDTEUPR_TIMCMP3_Pos      (8U)
#define HRTIM_BDTEUPR_TIMCMP3_Msk      (0x1UL << HRTIM_BDTEUPR_TIMCMP3_Pos)       /*!< 0x00000100 */
#define HRTIM_BDTEUPR_TIMCMP3           HRTIM_BDTEUPR_TIMCMP3_Msk   /*!< TIMCMP3 */
#define HRTIM_BDTEUPR_TIMCMP4_Pos      (9U)
#define HRTIM_BDTEUPR_TIMCMP4_Msk      (0x1UL << HRTIM_BDTEUPR_TIMCMP4_Pos)       /*!< 0x00000200 */
#define HRTIM_BDTEUPR_TIMCMP4           HRTIM_BDTEUPR_TIMCMP4_Msk   /*!< TIMCMP4 */
#define HRTIM_BDTEUPR_TIMDTR_Pos       (10U)
#define HRTIM_BDTEUPR_TIMDTR_Msk       (0x1UL << HRTIM_BDTEUPR_TIMDTR_Pos)      /*!< 0x00000400 */
#define HRTIM_BDTEUPR_TIMDTR            HRTIM_BDTEUPR_TIMDTR_Msk    /*!< TIMDTR */
#define HRTIM_BDTEUPR_TIMSET1R_Pos     (11U)
#define HRTIM_BDTEUPR_TIMSET1R_Msk     (0x1UL << HRTIM_BDTEUPR_TIMSET1R_Pos)        /*!< 0x00000800 */
#define HRTIM_BDTEUPR_TIMSET1R          HRTIM_BDTEUPR_TIMSET1R_Msk  /*!< TIMSET1R */
#define HRTIM_BDTEUPR_TIMRST1R_Pos     (12U)
#define HRTIM_BDTEUPR_TIMRST1R_Msk     (0x1UL << HRTIM_BDTEUPR_TIMRST1R_Pos)        /*!< 0x00001000 */
#define HRTIM_BDTEUPR_TIMRST1R          HRTIM_BDTEUPR_TIMRST1R_Msk  /*!< TIMRST1R */
#define HRTIM_BDTEUPR_TIMSET2R_Pos     (13U)
#define HRTIM_BDTEUPR_TIMSET2R_Msk     (0x1UL << HRTIM_BDTEUPR_TIMSET2R_Pos)        /*!< 0x00002000 */
#define HRTIM_BDTEUPR_TIMSET2R          HRTIM_BDTEUPR_TIMSET2R_Msk  /*!< TIMSET2R */
#define HRTIM_BDTEUPR_TIMRST2R_Pos     (14U)
#define HRTIM_BDTEUPR_TIMRST2R_Msk     (0x1UL << HRTIM_BDTEUPR_TIMRST2R_Pos)        /*!< 0x00004000 */
#define HRTIM_BDTEUPR_TIMRST2R          HRTIM_BDTEUPR_TIMRST2R_Msk  /*!< TIMRST2R */
#define HRTIM_BDTEUPR_TIMEEFR1_Pos     (15U)
#define HRTIM_BDTEUPR_TIMEEFR1_Msk     (0x1UL << HRTIM_BDTEUPR_TIMEEFR1_Pos)        /*!< 0x00008000 */
#define HRTIM_BDTEUPR_TIMEEFR1          HRTIM_BDTEUPR_TIMEEFR1_Msk  /*!< TIMEEFR1 */
#define HRTIM_BDTEUPR_TIMEEFR2_Pos     (16U)
#define HRTIM_BDTEUPR_TIMEEFR2_Msk     (0x1UL << HRTIM_BDTEUPR_TIMEEFR2_Pos)        /*!< 0x00010000 */
#define HRTIM_BDTEUPR_TIMEEFR2          HRTIM_BDTEUPR_TIMEEFR2_Msk  /*!< TIMEEFR2 */
#define HRTIM_BDTEUPR_TIMRSTR_Pos      (17U)
#define HRTIM_BDTEUPR_TIMRSTR_Msk      (0x1UL << HRTIM_BDTEUPR_TIMRSTR_Pos)       /*!< 0x00020000 */
#define HRTIM_BDTEUPR_TIMRSTR           HRTIM_BDTEUPR_TIMRSTR_Msk   /*!< TIMRSTR */
#define HRTIM_BDTEUPR_TIMCHPR_Pos      (18U)
#define HRTIM_BDTEUPR_TIMCHPR_Msk      (0x1UL << HRTIM_BDTEUPR_TIMCHPR_Pos)       /*!< 0x00040000 */
#define HRTIM_BDTEUPR_TIMCHPR           HRTIM_BDTEUPR_TIMCHPR_Msk   /*!< TIMCHPR */
#define HRTIM_BDTEUPR_TIMOUTR_Pos      (19U)
#define HRTIM_BDTEUPR_TIMOUTR_Msk      (0x1UL << HRTIM_BDTEUPR_TIMOUTR_Pos)       /*!< 0x00080000 */
#define HRTIM_BDTEUPR_TIMOUTR           HRTIM_BDTEUPR_TIMOUTR_Msk   /*!< TIMOUTR */
#define HRTIM_BDTEUPR_TIMFLTR_Pos      (20U)
#define HRTIM_BDTEUPR_TIMFLTR_Msk      (0x1UL << HRTIM_BDTEUPR_TIMFLTR_Pos)       /*!< 0x00100000 */
#define HRTIM_BDTEUPR_TIMFLTR           HRTIM_BDTEUPR_TIMFLTR_Msk   /*!< TIMFLTR */
#define HRTIM_BDTEUPR_TIMxCR2_Pos      (21U)
#define HRTIM_BDTEUPR_TIMxCR2_Msk      (0x1UL << HRTIM_BDTEUPR_TIMxCR2_Pos)       /*!< 0x00200000 */
#define HRTIM_BDTEUPR_TIMxCR2           HRTIM_BDTEUPR_TIMxCR2_Msk   /*!< TIMxCR2 */
#define HRTIM_BDTEUPR_TIMEEFR3_Pos     (22U)
#define HRTIM_BDTEUPR_TIMEEFR3_Msk     (0x1UL << HRTIM_BDTEUPR_TIMEEFR3_Pos)        /*!< 0x00400000 */
#define HRTIM_BDTEUPR_TIMEEFR3          HRTIM_BDTEUPR_TIMEEFR3_Msk  /*!< TIMEEFR3 */

/*************  Bit definition for HRTIM_BDMADR register  *************/
#define HRTIM_BDMADR_BDMADR_Pos        (0U)
#define HRTIM_BDMADR_BDMADR_Msk        (0xFFFFFFFFUL << HRTIM_BDMADR_BDMADR_Pos)            /*!< 0xFFFFFFFF */
#define HRTIM_BDMADR_BDMADR             HRTIM_BDMADR_BDMADR_Msk     /*!< BDMADR */

/************  Bit definition for HRTIM_BDTFUPR register  *************/
#define HRTIM_BDTFUPR_TIMxCR_Pos       (0U)
#define HRTIM_BDTFUPR_TIMxCR_Msk       (0x1UL << HRTIM_BDTFUPR_TIMxCR_Pos)      /*!< 0x00000001 */
#define HRTIM_BDTFUPR_TIMxCR            HRTIM_BDTFUPR_TIMxCR_Msk    /*!< TIMxCR */
#define HRTIM_BDTFUPR_TIMxICR_Pos      (1U)
#define HRTIM_BDTFUPR_TIMxICR_Msk      (0x1UL << HRTIM_BDTFUPR_TIMxICR_Pos)       /*!< 0x00000002 */
#define HRTIM_BDTFUPR_TIMxICR           HRTIM_BDTFUPR_TIMxICR_Msk   /*!< TIMxICR */
#define HRTIM_BDTFUPR_TIMxDIER_Pos     (2U)
#define HRTIM_BDTFUPR_TIMxDIER_Msk     (0x1UL << HRTIM_BDTFUPR_TIMxDIER_Pos)        /*!< 0x00000004 */
#define HRTIM_BDTFUPR_TIMxDIER          HRTIM_BDTFUPR_TIMxDIER_Msk  /*!< TIMxDIER */
#define HRTIM_BDTFUPR_TIMCNT_Pos       (3U)
#define HRTIM_BDTFUPR_TIMCNT_Msk       (0x1UL << HRTIM_BDTFUPR_TIMCNT_Pos)      /*!< 0x00000008 */
#define HRTIM_BDTFUPR_TIMCNT            HRTIM_BDTFUPR_TIMCNT_Msk    /*!< TIMCNT */
#define HRTIM_BDTFUPR_TIMPER_Pos       (4U)
#define HRTIM_BDTFUPR_TIMPER_Msk       (0x1UL << HRTIM_BDTFUPR_TIMPER_Pos)      /*!< 0x00000010 */
#define HRTIM_BDTFUPR_TIMPER            HRTIM_BDTFUPR_TIMPER_Msk    /*!< TIMPER */
#define HRTIM_BDTFUPR_TIMREP_Pos       (5U)
#define HRTIM_BDTFUPR_TIMREP_Msk       (0x1UL << HRTIM_BDTFUPR_TIMREP_Pos)      /*!< 0x00000020 */
#define HRTIM_BDTFUPR_TIMREP            HRTIM_BDTFUPR_TIMREP_Msk    /*!< TIMREP */
#define HRTIM_BDTFUPR_TIMCMP1_Pos      (6U)
#define HRTIM_BDTFUPR_TIMCMP1_Msk      (0x1UL << HRTIM_BDTFUPR_TIMCMP1_Pos)       /*!< 0x00000040 */
#define HRTIM_BDTFUPR_TIMCMP1           HRTIM_BDTFUPR_TIMCMP1_Msk   /*!< TIMCMP1 */
#define HRTIM_BDTFUPR_TIMCMP2_Pos      (7U)
#define HRTIM_BDTFUPR_TIMCMP2_Msk      (0x1UL << HRTIM_BDTFUPR_TIMCMP2_Pos)       /*!< 0x00000080 */
#define HRTIM_BDTFUPR_TIMCMP2           HRTIM_BDTFUPR_TIMCMP2_Msk   /*!< TIMCMP2 */
#define HRTIM_BDTFUPR_TIMCMP3_Pos      (8U)
#define HRTIM_BDTFUPR_TIMCMP3_Msk      (0x1UL << HRTIM_BDTFUPR_TIMCMP3_Pos)       /*!< 0x00000100 */
#define HRTIM_BDTFUPR_TIMCMP3           HRTIM_BDTFUPR_TIMCMP3_Msk   /*!< TIMCMP3 */
#define HRTIM_BDTFUPR_TIMCMP4_Pos      (9U)
#define HRTIM_BDTFUPR_TIMCMP4_Msk      (0x1UL << HRTIM_BDTFUPR_TIMCMP4_Pos)       /*!< 0x00000200 */
#define HRTIM_BDTFUPR_TIMCMP4           HRTIM_BDTFUPR_TIMCMP4_Msk   /*!< TIMCMP4 */
#define HRTIM_BDTFUPR_TIMDTR_Pos       (10U)
#define HRTIM_BDTFUPR_TIMDTR_Msk       (0x1UL << HRTIM_BDTFUPR_TIMDTR_Pos)      /*!< 0x00000400 */
#define HRTIM_BDTFUPR_TIMDTR            HRTIM_BDTFUPR_TIMDTR_Msk    /*!< TIMDTR */
#define HRTIM_BDTFUPR_TIMSET1R_Pos     (11U)
#define HRTIM_BDTFUPR_TIMSET1R_Msk     (0x1UL << HRTIM_BDTFUPR_TIMSET1R_Pos)        /*!< 0x00000800 */
#define HRTIM_BDTFUPR_TIMSET1R          HRTIM_BDTFUPR_TIMSET1R_Msk  /*!< TIMSET1R */
#define HRTIM_BDTFUPR_TIMRST1R_Pos     (12U)
#define HRTIM_BDTFUPR_TIMRST1R_Msk     (0x1UL << HRTIM_BDTFUPR_TIMRST1R_Pos)        /*!< 0x00001000 */
#define HRTIM_BDTFUPR_TIMRST1R          HRTIM_BDTFUPR_TIMRST1R_Msk  /*!< TIMRST1R */
#define HRTIM_BDTFUPR_TIMSET2R_Pos     (13U)
#define HRTIM_BDTFUPR_TIMSET2R_Msk     (0x1UL << HRTIM_BDTFUPR_TIMSET2R_Pos)        /*!< 0x00002000 */
#define HRTIM_BDTFUPR_TIMSET2R          HRTIM_BDTFUPR_TIMSET2R_Msk  /*!< TIMSET2R */
#define HRTIM_BDTFUPR_TIMRST2R_Pos     (14U)
#define HRTIM_BDTFUPR_TIMRST2R_Msk     (0x1UL << HRTIM_BDTFUPR_TIMRST2R_Pos)        /*!< 0x00004000 */
#define HRTIM_BDTFUPR_TIMRST2R          HRTIM_BDTFUPR_TIMRST2R_Msk  /*!< TIMRST2R */
#define HRTIM_BDTFUPR_TIMEEFR1_Pos     (15U)
#define HRTIM_BDTFUPR_TIMEEFR1_Msk     (0x1UL << HRTIM_BDTFUPR_TIMEEFR1_Pos)        /*!< 0x00008000 */
#define HRTIM_BDTFUPR_TIMEEFR1          HRTIM_BDTFUPR_TIMEEFR1_Msk  /*!< TIMEEFR1 */
#define HRTIM_BDTFUPR_TIMEEFR2_Pos     (16U)
#define HRTIM_BDTFUPR_TIMEEFR2_Msk     (0x1UL << HRTIM_BDTFUPR_TIMEEFR2_Pos)        /*!< 0x00010000 */
#define HRTIM_BDTFUPR_TIMEEFR2          HRTIM_BDTFUPR_TIMEEFR2_Msk  /*!< TIMEEFR2 */
#define HRTIM_BDTFUPR_TIMRSTR_Pos      (17U)
#define HRTIM_BDTFUPR_TIMRSTR_Msk      (0x1UL << HRTIM_BDTFUPR_TIMRSTR_Pos)       /*!< 0x00020000 */
#define HRTIM_BDTFUPR_TIMRSTR           HRTIM_BDTFUPR_TIMRSTR_Msk   /*!< TIMRSTR */
#define HRTIM_BDTFUPR_TIMCHPR_Pos      (18U)
#define HRTIM_BDTFUPR_TIMCHPR_Msk      (0x1UL << HRTIM_BDTFUPR_TIMCHPR_Pos)       /*!< 0x00040000 */
#define HRTIM_BDTFUPR_TIMCHPR           HRTIM_BDTFUPR_TIMCHPR_Msk   /*!< TIMCHPR */
#define HRTIM_BDTFUPR_TIMOUTR_Pos      (19U)
#define HRTIM_BDTFUPR_TIMOUTR_Msk      (0x1UL << HRTIM_BDTFUPR_TIMOUTR_Pos)       /*!< 0x00080000 */
#define HRTIM_BDTFUPR_TIMOUTR           HRTIM_BDTFUPR_TIMOUTR_Msk   /*!< TIMOUTR */
#define HRTIM_BDTFUPR_TIMFLTR_Pos      (20U)
#define HRTIM_BDTFUPR_TIMFLTR_Msk      (0x1UL << HRTIM_BDTFUPR_TIMFLTR_Pos)       /*!< 0x00100000 */
#define HRTIM_BDTFUPR_TIMFLTR           HRTIM_BDTFUPR_TIMFLTR_Msk   /*!< TIMFLTR */
#define HRTIM_BDTFUPR_TIMxCR2_Pos      (21U)
#define HRTIM_BDTFUPR_TIMxCR2_Msk      (0x1UL << HRTIM_BDTFUPR_TIMxCR2_Pos)       /*!< 0x00200000 */
#define HRTIM_BDTFUPR_TIMxCR2           HRTIM_BDTFUPR_TIMxCR2_Msk   /*!< TIMxCR2 */
#define HRTIM_BDTFUPR_TIMEEFR3_Pos     (22U)
#define HRTIM_BDTFUPR_TIMEEFR3_Msk     (0x1UL << HRTIM_BDTFUPR_TIMEEFR3_Pos)        /*!< 0x00400000 */
#define HRTIM_BDTFUPR_TIMEEFR3          HRTIM_BDTFUPR_TIMEEFR3_Msk  /*!< TIMEEFR3 */

/*************  Bit definition for HRTIM_ADCER register  **************/
#define HRTIM_ADCER_AD5TRG_Pos         (0U)
#define HRTIM_ADCER_AD5TRG_Msk         (0x1FUL << HRTIM_ADCER_AD5TRG_Pos)     /*!< 0x0000001F */
#define HRTIM_ADCER_AD5TRG              HRTIM_ADCER_AD5TRG_Msk      /*!< AD5TRG */
#define HRTIM_ADCER_AD6TRG_Pos         (5U)
#define HRTIM_ADCER_AD6TRG_Msk         (0x1FUL << HRTIM_ADCER_AD6TRG_Pos)     /*!< 0x000003E0 */
#define HRTIM_ADCER_AD6TRG              HRTIM_ADCER_AD6TRG_Msk      /*!< AD6TRG */
#define HRTIM_ADCER_AD7TRG_Pos         (10U)
#define HRTIM_ADCER_AD7TRG_Msk         (0x1FUL << HRTIM_ADCER_AD7TRG_Pos)     /*!< 0x00007C00 */
#define HRTIM_ADCER_AD7TRG              HRTIM_ADCER_AD7TRG_Msk      /*!< AD7TRG */
#define HRTIM_ADCER_AD8TRG_Pos         (16U)
#define HRTIM_ADCER_AD8TRG_Msk         (0x1FUL << HRTIM_ADCER_AD8TRG_Pos)     /*!< 0x001F0000 */
#define HRTIM_ADCER_AD8TRG              HRTIM_ADCER_AD8TRG_Msk      /*!< AD8TRG */
#define HRTIM_ADCER_AD9TRG_Pos         (21U)
#define HRTIM_ADCER_AD9TRG_Msk         (0x1FUL << HRTIM_ADCER_AD9TRG_Pos)     /*!< 0x03E00000 */
#define HRTIM_ADCER_AD9TRG              HRTIM_ADCER_AD9TRG_Msk      /*!< AD9TRG */
#define HRTIM_ADCER_AD10TRG_Pos        (26U)
#define HRTIM_ADCER_AD10TRG_Msk        (0x1FUL << HRTIM_ADCER_AD10TRG_Pos)      /*!< 0x7C000000 */
#define HRTIM_ADCER_AD10TRG             HRTIM_ADCER_AD10TRG_Msk     /*!< AD10TRG */

/*************  Bit definition for HRTIM_ADCUR register  **************/
#define HRTIM_ADCUR_AD5USRC_Pos        (0U)
#define HRTIM_ADCUR_AD5USRC_Msk        (0x7UL << HRTIM_ADCUR_AD5USRC_Pos)     /*!< 0x00000007 */
#define HRTIM_ADCUR_AD5USRC             HRTIM_ADCUR_AD5USRC_Msk     /*!< AD5USRC */
#define HRTIM_ADCUR_AD6USRC_Pos        (4U)
#define HRTIM_ADCUR_AD6USRC_Msk        (0x7UL << HRTIM_ADCUR_AD6USRC_Pos)     /*!< 0x00000070 */
#define HRTIM_ADCUR_AD6USRC             HRTIM_ADCUR_AD6USRC_Msk     /*!< AD6USRC */
#define HRTIM_ADCUR_AD7USRC_Pos        (8U)
#define HRTIM_ADCUR_AD7USRC_Msk        (0x7UL << HRTIM_ADCUR_AD7USRC_Pos)     /*!< 0x00000700 */
#define HRTIM_ADCUR_AD7USRC             HRTIM_ADCUR_AD7USRC_Msk     /*!< AD7USRC */
#define HRTIM_ADCUR_AD8USRC_Pos        (12U)
#define HRTIM_ADCUR_AD8USRC_Msk        (0x7UL << HRTIM_ADCUR_AD8USRC_Pos)     /*!< 0x00007000 */
#define HRTIM_ADCUR_AD8USRC             HRTIM_ADCUR_AD8USRC_Msk     /*!< AD8USRC */
#define HRTIM_ADCUR_AD9USRC_Pos        (16U)
#define HRTIM_ADCUR_AD9USRC_Msk        (0x7UL << HRTIM_ADCUR_AD9USRC_Pos)     /*!< 0x00070000 */
#define HRTIM_ADCUR_AD9USRC             HRTIM_ADCUR_AD9USRC_Msk     /*!< AD9USRC */
#define HRTIM_ADCUR_AD10USRC_Pos       (20U)
#define HRTIM_ADCUR_AD10USRC_Msk       (0x7UL << HRTIM_ADCUR_AD10USRC_Pos)      /*!< 0x00700000 */
#define HRTIM_ADCUR_AD10USRC            HRTIM_ADCUR_AD10USRC_Msk    /*!< AD10USRC */

/*************  Bit definition for HRTIM_ADCPS1 register  *************/
#define HRTIM_ADCPS1_AD1PSC_Pos        (0U)
#define HRTIM_ADCPS1_AD1PSC_Msk        (0x1FUL << HRTIM_ADCPS1_AD1PSC_Pos)      /*!< 0x0000001F */
#define HRTIM_ADCPS1_AD1PSC             HRTIM_ADCPS1_AD1PSC_Msk     /*!< AD1PSC */
#define HRTIM_ADCPS1_AD2PSC_Pos        (6U)
#define HRTIM_ADCPS1_AD2PSC_Msk        (0x1FUL << HRTIM_ADCPS1_AD2PSC_Pos)      /*!< 0x000007C0 */
#define HRTIM_ADCPS1_AD2PSC             HRTIM_ADCPS1_AD2PSC_Msk     /*!< AD2PSC */
#define HRTIM_ADCPS1_AD3PSC_Pos        (12U)
#define HRTIM_ADCPS1_AD3PSC_Msk        (0x1FUL << HRTIM_ADCPS1_AD3PSC_Pos)      /*!< 0x0001F000 */
#define HRTIM_ADCPS1_AD3PSC             HRTIM_ADCPS1_AD3PSC_Msk     /*!< AD3PSC */
#define HRTIM_ADCPS1_AD4PSC_Pos        (18U)
#define HRTIM_ADCPS1_AD4PSC_Msk        (0x1FUL << HRTIM_ADCPS1_AD4PSC_Pos)      /*!< 0x007C0000 */
#define HRTIM_ADCPS1_AD4PSC             HRTIM_ADCPS1_AD4PSC_Msk     /*!< AD4PSC */
#define HRTIM_ADCPS1_AD5PSC_Pos        (24U)
#define HRTIM_ADCPS1_AD5PSC_Msk        (0x1FUL << HRTIM_ADCPS1_AD5PSC_Pos)      /*!< 0x1F000000 */
#define HRTIM_ADCPS1_AD5PSC             HRTIM_ADCPS1_AD5PSC_Msk     /*!< AD5PSC */

/*************  Bit definition for HRTIM_ADCPS2 register  *************/
#define HRTIM_ADCPS2_AD6PSC_Pos        (0U)
#define HRTIM_ADCPS2_AD6PSC_Msk        (0x1FUL << HRTIM_ADCPS2_AD6PSC_Pos)      /*!< 0x0000001F */
#define HRTIM_ADCPS2_AD6PSC             HRTIM_ADCPS2_AD6PSC_Msk     /*!< AD6PSC */
#define HRTIM_ADCPS2_AD7PSC_Pos        (6U)
#define HRTIM_ADCPS2_AD7PSC_Msk        (0x1FUL << HRTIM_ADCPS2_AD7PSC_Pos)      /*!< 0x000007C0 */
#define HRTIM_ADCPS2_AD7PSC             HRTIM_ADCPS2_AD7PSC_Msk     /*!< AD7PSC */
#define HRTIM_ADCPS2_AD8PSC_Pos        (12U)
#define HRTIM_ADCPS2_AD8PSC_Msk        (0x1FUL << HRTIM_ADCPS2_AD8PSC_Pos)      /*!< 0x0001F000 */
#define HRTIM_ADCPS2_AD8PSC             HRTIM_ADCPS2_AD8PSC_Msk     /*!< AD8PSC */
#define HRTIM_ADCPS2_AD9PSC_Pos        (18U)
#define HRTIM_ADCPS2_AD9PSC_Msk        (0x1FUL << HRTIM_ADCPS2_AD9PSC_Pos)      /*!< 0x007C0000 */
#define HRTIM_ADCPS2_AD9PSC             HRTIM_ADCPS2_AD9PSC_Msk     /*!< AD9PSC */
#define HRTIM_ADCPS2_AD10PSC_Pos       (24U)
#define HRTIM_ADCPS2_AD10PSC_Msk       (0x1FUL << HRTIM_ADCPS2_AD10PSC_Pos)       /*!< 0x1F000000 */
#define HRTIM_ADCPS2_AD10PSC            HRTIM_ADCPS2_AD10PSC_Msk    /*!< AD10PSC */

/************  Bit definition for HRTIM_FLTINR3 register  *************/
#define HRTIM_FLTINR3_FLT1BLKE_Pos     (0U)
#define HRTIM_FLTINR3_FLT1BLKE_Msk     (0x1UL << HRTIM_FLTINR3_FLT1BLKE_Pos)        /*!< 0x00000001 */
#define HRTIM_FLTINR3_FLT1BLKE          HRTIM_FLTINR3_FLT1BLKE_Msk  /*!< FLT1BLKE */
#define HRTIM_FLTINR3_FLT1BLKS_Pos     (1U)
#define HRTIM_FLTINR3_FLT1BLKS_Msk     (0x1UL << HRTIM_FLTINR3_FLT1BLKS_Pos)        /*!< 0x00000002 */
#define HRTIM_FLTINR3_FLT1BLKS          HRTIM_FLTINR3_FLT1BLKS_Msk  /*!< FLT1BLKS */
#define HRTIM_FLTINR3_FLT1CNT_Pos      (2U)
#define HRTIM_FLTINR3_FLT1CNT_Msk      (0xFUL << HRTIM_FLTINR3_FLT1CNT_Pos)       /*!< 0x0000003C */
#define HRTIM_FLTINR3_FLT1CNT           HRTIM_FLTINR3_FLT1CNT_Msk   /*!< FLT1CNT */
#define HRTIM_FLTINR3_FLT1CNT_0      (0x1UL << HRTIM_FLTINR3_FLT1CNT_Pos)        /*!< 0x00000004 */
#define HRTIM_FLTINR3_FLT1CNT_1      (0x2UL << HRTIM_FLTINR3_FLT1CNT_Pos)        /*!< 0x00000008 */
#define HRTIM_FLTINR3_FLT1CNT_2      (0x4UL << HRTIM_FLTINR3_FLT1CNT_Pos)        /*!< 0x00000010 */
#define HRTIM_FLTINR3_FLT1CNT_3      (0x8UL << HRTIM_FLTINR3_FLT1CNT_Pos)        /*!< 0x00000020 */
#define HRTIM_FLTINR3_FLT1CRES_Pos     (6U)
#define HRTIM_FLTINR3_FLT1CRES_Msk     (0x1UL << HRTIM_FLTINR3_FLT1CRES_Pos)        /*!< 0x00000040 */
#define HRTIM_FLTINR3_FLT1CRES          HRTIM_FLTINR3_FLT1CRES_Msk  /*!< FLT1CRES */
#define HRTIM_FLTINR3_FLT1RSTM_Pos     (7U)
#define HRTIM_FLTINR3_FLT1RSTM_Msk     (0x1UL << HRTIM_FLTINR3_FLT1RSTM_Pos)        /*!< 0x00000080 */
#define HRTIM_FLTINR3_FLT1RSTM          HRTIM_FLTINR3_FLT1RSTM_Msk  /*!< FLT1RSTM */
#define HRTIM_FLTINR3_FLT2BLKE_Pos     (8U)
#define HRTIM_FLTINR3_FLT2BLKE_Msk     (0x1UL << HRTIM_FLTINR3_FLT2BLKE_Pos)        /*!< 0x00000100 */
#define HRTIM_FLTINR3_FLT2BLKE          HRTIM_FLTINR3_FLT2BLKE_Msk  /*!< FLT2BLKE */
#define HRTIM_FLTINR3_FLT2BLKS_Pos     (9U)
#define HRTIM_FLTINR3_FLT2BLKS_Msk     (0x1UL << HRTIM_FLTINR3_FLT2BLKS_Pos)        /*!< 0x00000200 */
#define HRTIM_FLTINR3_FLT2BLKS          HRTIM_FLTINR3_FLT2BLKS_Msk  /*!< FLT2BLKS */
#define HRTIM_FLTINR3_FLT2CNT_Pos      (10U)
#define HRTIM_FLTINR3_FLT2CNT_Msk      (0xFUL << HRTIM_FLTINR3_FLT2CNT_Pos)       /*!< 0x00003C00 */
#define HRTIM_FLTINR3_FLT2CNT           HRTIM_FLTINR3_FLT2CNT_Msk   /*!< FLT2CNT */
#define HRTIM_FLTINR3_FLT2CNT_0      (0x1UL << HRTIM_FLTINR3_FLT2CNT_Pos)        /*!< 0x00000400 */
#define HRTIM_FLTINR3_FLT2CNT_1      (0x2UL << HRTIM_FLTINR3_FLT2CNT_Pos)        /*!< 0x00000800 */
#define HRTIM_FLTINR3_FLT2CNT_2      (0x4UL << HRTIM_FLTINR3_FLT2CNT_Pos)        /*!< 0x00001000 */
#define HRTIM_FLTINR3_FLT2CNT_3      (0x8UL << HRTIM_FLTINR3_FLT2CNT_Pos)        /*!< 0x00002000 */
#define HRTIM_FLTINR3_FLT2CRES_Pos     (14U)
#define HRTIM_FLTINR3_FLT2CRES_Msk     (0x1UL << HRTIM_FLTINR3_FLT2CRES_Pos)        /*!< 0x00004000 */
#define HRTIM_FLTINR3_FLT2CRES          HRTIM_FLTINR3_FLT2CRES_Msk  /*!< FLT2CRES */
#define HRTIM_FLTINR3_FLT2RSTM_Pos     (15U)
#define HRTIM_FLTINR3_FLT2RSTM_Msk     (0x1UL << HRTIM_FLTINR3_FLT2RSTM_Pos)        /*!< 0x00008000 */
#define HRTIM_FLTINR3_FLT2RSTM          HRTIM_FLTINR3_FLT2RSTM_Msk  /*!< FLT2RSTM */
#define HRTIM_FLTINR3_FLT3BLKE_Pos     (16U)
#define HRTIM_FLTINR3_FLT3BLKE_Msk     (0x1UL << HRTIM_FLTINR3_FLT3BLKE_Pos)        /*!< 0x00010000 */
#define HRTIM_FLTINR3_FLT3BLKE          HRTIM_FLTINR3_FLT3BLKE_Msk  /*!< FLT3BLKE */
#define HRTIM_FLTINR3_FLT3BLKS_Pos     (17U)
#define HRTIM_FLTINR3_FLT3BLKS_Msk     (0x1UL << HRTIM_FLTINR3_FLT3BLKS_Pos)        /*!< 0x00020000 */
#define HRTIM_FLTINR3_FLT3BLKS          HRTIM_FLTINR3_FLT3BLKS_Msk  /*!< FLT3BLKS */
#define HRTIM_FLTINR3_FLT3CNT_Pos      (18U)
#define HRTIM_FLTINR3_FLT3CNT_Msk      (0xFUL << HRTIM_FLTINR3_FLT3CNT_Pos)       /*!< 0x003C0000 */
#define HRTIM_FLTINR3_FLT3CNT           HRTIM_FLTINR3_FLT3CNT_Msk   /*!< FLT3CNT */
#define HRTIM_FLTINR3_FLT3CNT_0      (0x1UL << HRTIM_FLTINR3_FLT3CNT_Pos)        /*!< 0x00040000 */
#define HRTIM_FLTINR3_FLT3CNT_1      (0x2UL << HRTIM_FLTINR3_FLT3CNT_Pos)        /*!< 0x00080000 */
#define HRTIM_FLTINR3_FLT3CNT_2      (0x4UL << HRTIM_FLTINR3_FLT3CNT_Pos)        /*!< 0x00100000 */
#define HRTIM_FLTINR3_FLT3CNT_3      (0x8UL << HRTIM_FLTINR3_FLT3CNT_Pos)        /*!< 0x00200000 */
#define HRTIM_FLTINR3_FLT3CRES_Pos     (22U)
#define HRTIM_FLTINR3_FLT3CRES_Msk     (0x1UL << HRTIM_FLTINR3_FLT3CRES_Pos)        /*!< 0x00400000 */
#define HRTIM_FLTINR3_FLT3CRES          HRTIM_FLTINR3_FLT3CRES_Msk  /*!< FLT3CRES */
#define HRTIM_FLTINR3_FLT3RSTM_Pos     (23U)
#define HRTIM_FLTINR3_FLT3RSTM_Msk     (0x1UL << HRTIM_FLTINR3_FLT3RSTM_Pos)        /*!< 0x00800000 */
#define HRTIM_FLTINR3_FLT3RSTM          HRTIM_FLTINR3_FLT3RSTM_Msk  /*!< FLT3RSTM */
#define HRTIM_FLTINR3_FLT4BLKE_Pos     (24U)
#define HRTIM_FLTINR3_FLT4BLKE_Msk     (0x1UL << HRTIM_FLTINR3_FLT4BLKE_Pos)        /*!< 0x01000000 */
#define HRTIM_FLTINR3_FLT4BLKE          HRTIM_FLTINR3_FLT4BLKE_Msk  /*!< FLT4BLKE */
#define HRTIM_FLTINR3_FLT4BLKS_Pos     (25U)
#define HRTIM_FLTINR3_FLT4BLKS_Msk     (0x1UL << HRTIM_FLTINR3_FLT4BLKS_Pos)        /*!< 0x02000000 */
#define HRTIM_FLTINR3_FLT4BLKS          HRTIM_FLTINR3_FLT4BLKS_Msk  /*!< FLT4BLKS */
#define HRTIM_FLTINR3_FLT4CNT_Pos      (26U)
#define HRTIM_FLTINR3_FLT4CNT_Msk      (0xFUL << HRTIM_FLTINR3_FLT4CNT_Pos)       /*!< 0x3C000000 */
#define HRTIM_FLTINR3_FLT4CNT           HRTIM_FLTINR3_FLT4CNT_Msk   /*!< FLT4CNT */
#define HRTIM_FLTINR3_FLT4CNT_0      (0x1UL << HRTIM_FLTINR3_FLT4CNT_Pos)        /*!< 0x04000000 */
#define HRTIM_FLTINR3_FLT4CNT_1      (0x2UL << HRTIM_FLTINR3_FLT4CNT_Pos)        /*!< 0x08000000 */
#define HRTIM_FLTINR3_FLT4CNT_2      (0x4UL << HRTIM_FLTINR3_FLT4CNT_Pos)        /*!< 0x10000000 */
#define HRTIM_FLTINR3_FLT4CNT_3      (0x8UL << HRTIM_FLTINR3_FLT4CNT_Pos)        /*!< 0x20000000 */
#define HRTIM_FLTINR3_FLT4CRES_Pos     (30U)
#define HRTIM_FLTINR3_FLT4CRES_Msk     (0x1UL << HRTIM_FLTINR3_FLT4CRES_Pos)        /*!< 0x40000000 */
#define HRTIM_FLTINR3_FLT4CRES          HRTIM_FLTINR3_FLT4CRES_Msk  /*!< FLT4CRES */
#define HRTIM_FLTINR3_FLT4RSTM_Pos     (31U)
#define HRTIM_FLTINR3_FLT4RSTM_Msk     (0x1UL << HRTIM_FLTINR3_FLT4RSTM_Pos)        /*!< 0x80000000 */
#define HRTIM_FLTINR3_FLT4RSTM          HRTIM_FLTINR3_FLT4RSTM_Msk  /*!< FLT4RSTM */

/************  Bit definition for HRTIM_FLTINR4 register  *************/
#define HRTIM_FLTINR4_FLT5BLKE_Pos     (0U)
#define HRTIM_FLTINR4_FLT5BLKE_Msk     (0x1UL << HRTIM_FLTINR4_FLT5BLKE_Pos)        /*!< 0x00000001 */
#define HRTIM_FLTINR4_FLT5BLKE          HRTIM_FLTINR4_FLT5BLKE_Msk  /*!< FLT5BLKE */
#define HRTIM_FLTINR4_FLT5BLKS_Pos     (1U)
#define HRTIM_FLTINR4_FLT5BLKS_Msk     (0x1UL << HRTIM_FLTINR4_FLT5BLKS_Pos)        /*!< 0x00000002 */
#define HRTIM_FLTINR4_FLT5BLKS          HRTIM_FLTINR4_FLT5BLKS_Msk  /*!< FLT5BLKS */
#define HRTIM_FLTINR4_FLT5CNT_Pos      (2U)
#define HRTIM_FLTINR4_FLT5CNT_Msk      (0xFUL << HRTIM_FLTINR4_FLT5CNT_Pos)       /*!< 0x0000003C */
#define HRTIM_FLTINR4_FLT5CNT           HRTIM_FLTINR4_FLT5CNT_Msk   /*!< FLT5CNT */
#define HRTIM_FLTINR4_FLT5CNT_0      (0x1UL << HRTIM_FLTINR4_FLT5CNT_Pos)        /*!< 0x00000004 */
#define HRTIM_FLTINR4_FLT5CNT_1      (0x2UL << HRTIM_FLTINR4_FLT5CNT_Pos)        /*!< 0x00000008 */
#define HRTIM_FLTINR4_FLT5CNT_2      (0x4UL << HRTIM_FLTINR4_FLT5CNT_Pos)        /*!< 0x00000010 */
#define HRTIM_FLTINR4_FLT5CNT_3      (0x8UL << HRTIM_FLTINR4_FLT5CNT_Pos)        /*!< 0x00000020 */
#define HRTIM_FLTINR4_FLT5CRES_Pos     (6U)
#define HRTIM_FLTINR4_FLT5CRES_Msk     (0x1UL << HRTIM_FLTINR4_FLT5CRES_Pos)        /*!< 0x00000040 */
#define HRTIM_FLTINR4_FLT5CRES          HRTIM_FLTINR4_FLT5CRES_Msk  /*!< FLT5CRES */
#define HRTIM_FLTINR4_FLT5RSTM_Pos     (7U)
#define HRTIM_FLTINR4_FLT5RSTM_Msk     (0x1UL << HRTIM_FLTINR4_FLT5RSTM_Pos)        /*!< 0x00000080 */
#define HRTIM_FLTINR4_FLT5RSTM          HRTIM_FLTINR4_FLT5RSTM_Msk  /*!< FLT5RSTM */
#define HRTIM_FLTINR4_FLT6BLKE_Pos     (8U)
#define HRTIM_FLTINR4_FLT6BLKE_Msk     (0x1UL << HRTIM_FLTINR4_FLT6BLKE_Pos)        /*!< 0x00000100 */
#define HRTIM_FLTINR4_FLT6BLKE          HRTIM_FLTINR4_FLT6BLKE_Msk  /*!< FLT6BLKE */
#define HRTIM_FLTINR4_FLT6BLKS_Pos     (9U)
#define HRTIM_FLTINR4_FLT6BLKS_Msk     (0x1UL << HRTIM_FLTINR4_FLT6BLKS_Pos)        /*!< 0x00000200 */
#define HRTIM_FLTINR4_FLT6BLKS          HRTIM_FLTINR4_FLT6BLKS_Msk  /*!< FLT6BLKS */
#define HRTIM_FLTINR4_FLT6CNT_Pos      (10U)
#define HRTIM_FLTINR4_FLT6CNT_Msk      (0xFUL << HRTIM_FLTINR4_FLT6CNT_Pos)       /*!< 0x00003C00 */
#define HRTIM_FLTINR4_FLT6CNT           HRTIM_FLTINR4_FLT6CNT_Msk   /*!< FLT6CNT */
#define HRTIM_FLTINR4_FLT6CNT_0      (0x1UL << HRTIM_FLTINR4_FLT6CNT_Pos)        /*!< 0x00000400 */
#define HRTIM_FLTINR4_FLT6CNT_1      (0x2UL << HRTIM_FLTINR4_FLT6CNT_Pos)        /*!< 0x00000800 */
#define HRTIM_FLTINR4_FLT6CNT_2      (0x4UL << HRTIM_FLTINR4_FLT6CNT_Pos)        /*!< 0x00001000 */
#define HRTIM_FLTINR4_FLT6CNT_3      (0x8UL << HRTIM_FLTINR4_FLT6CNT_Pos)        /*!< 0x00002000 */
#define HRTIM_FLTINR4_FLT6CRES_Pos     (14U)
#define HRTIM_FLTINR4_FLT6CRES_Msk     (0x1UL << HRTIM_FLTINR4_FLT6CRES_Pos)        /*!< 0x00004000 */
#define HRTIM_FLTINR4_FLT6CRES          HRTIM_FLTINR4_FLT6CRES_Msk  /*!< FLT6CRES */
#define HRTIM_FLTINR4_FLT6RSTM_Pos     (15U)
#define HRTIM_FLTINR4_FLT6RSTM_Msk     (0x1UL << HRTIM_FLTINR4_FLT6RSTM_Pos)        /*!< 0x00008000 */
#define HRTIM_FLTINR4_FLT6RSTM          HRTIM_FLTINR4_FLT6RSTM_Msk  /*!< FLT6RSTM */

/* HRTIM  register definition */
typedef struct {
  HRTIM_Master_TypeDef sMasterRegs;
  HRTIM_Timerx_TypeDef sTimerxRegs[6];
  HRTIM_Common_TypeDef sCommonRegs;
} HRTIM_TypeDef;


#define HRTIM1_Master_BASE           0xA0000000UL 
#define HRTIM1_TimerA_BASE           0xA0000080UL 
#define HRTIM1_TimerB_BASE           0xA0000100UL 
#define HRTIM1_TimerC_BASE           0xA0000180UL 
#define HRTIM1_TimerD_BASE           0xA0000200UL 
#define HRTIM1_TimerE_BASE           0xA0000280UL 
#define HRTIM1_TimerF_BASE           0xA0000300UL 
#define HRTIM1_Common_BASE           0xA0000380UL 

#define HRTIM2_Master_BASE           0xA0004000UL 
#define HRTIM2_TimerA_BASE           0xA0004080UL 
#define HRTIM2_TimerB_BASE           0xA0004100UL 
#define HRTIM2_TimerC_BASE           0xA0004180UL 
#define HRTIM2_TimerD_BASE           0xA0004200UL 
#define HRTIM2_TimerE_BASE           0xA0004280UL 
#define HRTIM2_TimerF_BASE           0xA0004300UL 
#define HRTIM2_Common_BASE           0xA0004380UL 

#define HRTIM1		             ((HRTIM_TypeDef *) HRTIM1_Master_BASE)
#define HRTIM2		             ((HRTIM_TypeDef *) HRTIM2_Master_BASE)

#define HRTIM1_Master                ((HRTIM_Master_TypeDef *) HRTIM1_Master_BASE) 
#define HRTIM1_TimerA                ((HRTIM_Timerx_TypeDef *) HRTIM1_TimerA_BASE) 
#define HRTIM1_TimerB                ((HRTIM_Timerx_TypeDef *) HRTIM1_TimerB_BASE) 
#define HRTIM1_TimerC                ((HRTIM_Timerx_TypeDef *) HRTIM1_TimerC_BASE) 
#define HRTIM1_TimerD                ((HRTIM_Timerx_TypeDef *) HRTIM1_TimerD_BASE) 
#define HRTIM1_TimerE                ((HRTIM_Timerx_TypeDef *) HRTIM1_TimerE_BASE) 
#define HRTIM1_TimerF                ((HRTIM_Timerx_TypeDef *) HRTIM1_TimerF_BASE) 
#define HRTIM1_Common                ((HRTIM_Common_TypeDef *) HRTIM1_Common_BASE) 

#define HRTIM2_Master                ((HRTIM_Master_TypeDef *) HRTIM2_Master_BASE) 
#define HRTIM2_TimerA                ((HRTIM_Timerx_TypeDef *) HRTIM2_TimerA_BASE) 
#define HRTIM2_TimerB                ((HRTIM_Timerx_TypeDef *) HRTIM2_TimerB_BASE) 
#define HRTIM2_TimerC                ((HRTIM_Timerx_TypeDef *) HRTIM2_TimerC_BASE) 
#define HRTIM2_TimerD                ((HRTIM_Timerx_TypeDef *) HRTIM2_TimerD_BASE) 
#define HRTIM2_TimerE                ((HRTIM_Timerx_TypeDef *) HRTIM2_TimerE_BASE) 
#define HRTIM2_TimerF                ((HRTIM_Timerx_TypeDef *) HRTIM2_TimerF_BASE) 
#define HRTIM2_Common                ((HRTIM_Common_TypeDef *) HRTIM2_Common_BASE) 

#endif /* __SR5E1_HRTIM_H */

