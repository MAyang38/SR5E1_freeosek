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

#ifndef __SR5E1_SDADC_H
#define __SR5E1_SDADC_H

/******************************************************************************/
/*                                                                            */
/*                                  (SD_ADC)                                 */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO uint32_t SDADC_MCR;     /*!< SDADC_MCR    Address offset: 0x00 */
  __IO uint32_t SDADC_CSR;     /*!< SDADC_CSR    Address offset: 0x04 */
  __IO uint32_t SDADC_RKR;     /*!< SDADC_RKR    Address offset: 0x08 */
  __IO uint32_t SDADC_SFR;     /*!< SDADC_SFR    Address offset: 0x0C */
  __IO uint32_t SDADC_RSER;    /*!< SDADC_RSER   Address offset: 0x10 */
  __IO uint32_t SDADC_OSDR;    /*!< SDADC_OSDR   Address offset: 0x14 */
  __IO uint32_t SDADC_FCR;     /*!< SDADC_FCR    Address offset: 0x18 */
  __IO uint32_t SDADC_STKR;    /*!< SDADC_STKR   Address offset: 0x1C */
  __I  uint32_t SDADC_CDR;     /*!< SDADC_CDR    Address offset: 0x20 */
  __IO uint32_t SDADC_WTHHLR;  /*!< SDADC_WTHHLR Address offset: 0x24 */
  __I  uint32_t SDADC_LDREG;   /*!< SDADC_LDREG  Address offset: 0x28 */
  __I  uint32_t SDADC_LTREG;   /*!< SDADC_LTREG  Address offset: 0x2C */
} SDADC_TypeDef;


/***************  Bit definition for SDADC_SDADC_MCR register  ****************/
#define SDADC_SDADC_MCR_EN_Pos                (0U)
#define SDADC_SDADC_MCR_EN_Msk                (0x1UL << SDADC_SDADC_MCR_EN_Pos)       /*!< 0x00000001 */
#define SDADC_SDADC_MCR_EN                    SDADC_SDADC_MCR_EN_Msk                /*!< </spirit:description> */
#define SDADC_SDADC_MCR_MODE_Pos              (1U)
#define SDADC_SDADC_MCR_MODE_Msk              (0x1UL << SDADC_SDADC_MCR_MODE_Pos)     /*!< 0x00000002 */
#define SDADC_SDADC_MCR_MODE                  SDADC_SDADC_MCR_MODE_Msk              /*!< </spirit:description> */
#define SDADC_SDADC_MCR_GECEN_Pos             (2U)
#define SDADC_SDADC_MCR_GECEN_Msk             (0x1UL << SDADC_SDADC_MCR_GECEN_Pos)    /*!< 0x00000004 */
#define SDADC_SDADC_MCR_GECEN                 SDADC_SDADC_MCR_GECEN_Msk             /*!< </spirit:description> */
#define SDADC_SDADC_MCR_WRMODE_Pos            (3U)
#define SDADC_SDADC_MCR_WRMODE_Msk            (0x1UL << SDADC_SDADC_MCR_WRMODE_Pos)   /*!< 0x00000008 */
#define SDADC_SDADC_MCR_WRMODE                SDADC_SDADC_MCR_WRMODE_Msk            /*!< </spirit:description> */
#define SDADC_SDADC_MCR_VCOMSEL_Pos           (4U)
#define SDADC_SDADC_MCR_VCOMSEL_Msk           (0x1UL << SDADC_SDADC_MCR_VCOMSEL_Pos)  /*!< 0x00000010 */
#define SDADC_SDADC_MCR_VCOMSEL               SDADC_SDADC_MCR_VCOMSEL_Msk           /*!< </spirit:description> */
#define SDADC_SDADC_MCR_FSEL_Pos              (5U)
#define SDADC_SDADC_MCR_FSEL_Msk              (0x1UL << SDADC_SDADC_MCR_FSEL_Pos)     /*!< 0x00000020 */
#define SDADC_SDADC_MCR_FSEL                  SDADC_SDADC_MCR_FSEL_Msk              /*!< </spirit:description> */
#define SDADC_SDADC_MCR_BANDSEL_Pos           (6U)
#define SDADC_SDADC_MCR_BANDSEL_Msk           (0x1UL << SDADC_SDADC_MCR_BANDSEL_Pos)  /*!< 0x00000040 */
#define SDADC_SDADC_MCR_BANDSEL               SDADC_SDADC_MCR_BANDSEL_Msk           /*!< </spirit:description> */
#define SDADC_SDADC_MCR_FRZ_Pos               (7U)
#define SDADC_SDADC_MCR_FRZ_Msk               (0x1UL << SDADC_SDADC_MCR_FRZ_Pos)      /*!< 0x00000080 */
#define SDADC_SDADC_MCR_FRZ                   SDADC_SDADC_MCR_FRZ_Msk               /*!< </spirit:description> */
#define SDADC_SDADC_MCR_TRIGSEL_Pos           (8U)
#define SDADC_SDADC_MCR_TRIGSEL_Msk           (0xFUL << SDADC_SDADC_MCR_TRIGSEL_Pos)  /*!< 0x00000F00 */
#define SDADC_SDADC_MCR_TRIGSEL               SDADC_SDADC_MCR_TRIGSEL_Msk           /*!< </spirit:description> */
#define SDADC_SDADC_MCR_TRIGEN_Pos            (12U)
#define SDADC_SDADC_MCR_TRIGEN_Msk            (0x1UL << SDADC_SDADC_MCR_TRIGEN_Pos)   /*!< 0x00001000 */
#define SDADC_SDADC_MCR_TRIGEN                SDADC_SDADC_MCR_TRIGEN_Msk            /*!< </spirit:description> */
#define SDADC_SDADC_MCR_TRIGEDSEL_Pos         (13U)
#define SDADC_SDADC_MCR_TRIGEDSEL_Msk         (0x3UL << SDADC_SDADC_MCR_TRIGEDSEL_Pos)  /*!< 0x00006000 */
#define SDADC_SDADC_MCR_TRIGEDSEL             SDADC_SDADC_MCR_TRIGEDSEL_Msk         /*!< </spirit:description> */
#define SDADC_SDADC_MCR_WDGEN_Pos             (15U)
#define SDADC_SDADC_MCR_WDGEN_Msk             (0x1UL << SDADC_SDADC_MCR_WDGEN_Pos)    /*!< 0x00008000 */
#define SDADC_SDADC_MCR_WDGEN                 SDADC_SDADC_MCR_WDGEN_Msk             /*!< </spirit:description> */
#define SDADC_SDADC_MCR_HPFEN_Pos             (16U)
#define SDADC_SDADC_MCR_HPFEN_Msk             (0x1UL << SDADC_SDADC_MCR_HPFEN_Pos)    /*!< 0x00010000 */
#define SDADC_SDADC_MCR_HPFEN                 SDADC_SDADC_MCR_HPFEN_Msk             /*!< </spirit:description> */
#define SDADC_SDADC_MCR_EMSEL_Pos             (17U)
#define SDADC_SDADC_MCR_EMSEL_Msk             (0x1UL << SDADC_SDADC_MCR_EMSEL_Pos)    /*!< 0x00020000 */
#define SDADC_SDADC_MCR_EMSEL                 SDADC_SDADC_MCR_EMSEL_Msk             /*!< </spirit:description> */
#define SDADC_SDADC_MCR_ODA_Pos               (18U)
#define SDADC_SDADC_MCR_ODA_Msk               (0x1UL << SDADC_SDADC_MCR_ODA_Pos)      /*!< 0x00040000 */
#define SDADC_SDADC_MCR_ODA                   SDADC_SDADC_MCR_ODA_Msk               /*!< </spirit:description> */
#define SDADC_SDADC_MCR_ODF_Pos               (19U)
#define SDADC_SDADC_MCR_ODF_Msk               (0x1UL << SDADC_SDADC_MCR_ODF_Pos)      /*!< 0x00080000 */
#define SDADC_SDADC_MCR_ODF                   SDADC_SDADC_MCR_ODF_Msk               /*!< </spirit:description> */
#define SDADC_SDADC_MCR_PGAN_Pos              (20U)
#define SDADC_SDADC_MCR_PGAN_Msk              (0x7UL << SDADC_SDADC_MCR_PGAN_Pos)     /*!< 0x00700000 */
#define SDADC_SDADC_MCR_PGAN                  SDADC_SDADC_MCR_PGAN_Msk              /*!< </spirit:description> */
#define SDADC_SDADC_MCR_PDR_Pos               (24U)
#define SDADC_SDADC_MCR_PDR_Msk               (0x1FUL << SDADC_SDADC_MCR_PDR_Pos)     /*!< 0x1F000000 */
#define SDADC_SDADC_MCR_PDR                   SDADC_SDADC_MCR_PDR_Msk               /*!< </spirit:description> */
#define SDADC_SDADC_MCR_TRIG_SRC_ADC_Pos      (29U)
#define SDADC_SDADC_MCR_TRIG_SRC_ADC_Msk      (0x1UL << SDADC_SDADC_MCR_TRIG_SRC_ADC_Pos)     /*!< 0x20000000 */
#define SDADC_SDADC_MCR_TRIG_SRC_ADC          SDADC_SDADC_MCR_TRIG_SRC_ADC_Msk      /*!< </spirit:description> */
#define SDADC_SDADC_MCR_LTWM_Pos              (30U)
#define SDADC_SDADC_MCR_LTWM_Msk              (0x1UL << SDADC_SDADC_MCR_LTWM_Pos)     /*!< 0x40000000 */
#define SDADC_SDADC_MCR_LTWM                  SDADC_SDADC_MCR_LTWM_Msk              /*!< </spirit:description> */
#define SDADC_SDADC_MCR_EXTFILTER_Pos         (31U)
#define SDADC_SDADC_MCR_EXTFILTER_Msk         (0x1UL << SDADC_SDADC_MCR_EXTFILTER_Pos)  /*!< 0x80000000 */
#define SDADC_SDADC_MCR_EXTFILTER             SDADC_SDADC_MCR_EXTFILTER_Msk         /*!< </spirit:description> */

/***************  Bit definition for SDADC_SDADC_CSR register  ****************/
#define SDADC_SDADC_CSR_ANCHSEL_Pos           (0U)
#define SDADC_SDADC_CSR_ANCHSEL_Msk           (0x7UL << SDADC_SDADC_CSR_ANCHSEL_Pos)  /*!< 0x00000007 */
#define SDADC_SDADC_CSR_ANCHSEL               SDADC_SDADC_CSR_ANCHSEL_Msk           /*!< </spirit:description> */
#define SDADC_SDADC_CSR_ANCHSEL_WRAP_Pos      (8U)
#define SDADC_SDADC_CSR_ANCHSEL_WRAP_Msk      (0x7UL << SDADC_SDADC_CSR_ANCHSEL_WRAP_Pos)     /*!< 0x00000700 */
#define SDADC_SDADC_CSR_ANCHSEL_WRAP          SDADC_SDADC_CSR_ANCHSEL_WRAP_Msk      /*!< </spirit:description> */
#define SDADC_SDADC_CSR_BIASEN_Pos            (16U)
#define SDADC_SDADC_CSR_BIASEN_Msk            (0xFFUL << SDADC_SDADC_CSR_BIASEN_Pos)  /*!< 0x00FF0000 */
#define SDADC_SDADC_CSR_BIASEN                SDADC_SDADC_CSR_BIASEN_Msk            /*!< </spirit:description> */

/***************  Bit definition for SDADC_SDADC_RKR register  ****************/
#define SDADC_SDADC_RKR_RESET_KEY_Pos         (0U)
#define SDADC_SDADC_RKR_RESET_KEY_Msk         (0xFFFFUL << SDADC_SDADC_RKR_RESET_KEY_Pos)     /*!< 0x0000FFFF */
#define SDADC_SDADC_RKR_RESET_KEY             SDADC_SDADC_RKR_RESET_KEY_Msk         /*!< </spirit:description> */

/***************  Bit definition for SDADC_SDADC_SFR register  ****************/
#define SDADC_SDADC_SFR_DFFF_Pos              (0U)
#define SDADC_SDADC_SFR_DFFF_Msk              (0x1UL << SDADC_SDADC_SFR_DFFF_Pos)     /*!< 0x00000001 */
#define SDADC_SDADC_SFR_DFFF                  SDADC_SDADC_SFR_DFFF_Msk              /*!< </spirit:description> */
#define SDADC_SDADC_SFR_DFORF_Pos             (1U)
#define SDADC_SDADC_SFR_DFORF_Msk             (0x1UL << SDADC_SDADC_SFR_DFORF_Pos)    /*!< 0x00000002 */
#define SDADC_SDADC_SFR_DFORF                 SDADC_SDADC_SFR_DFORF_Msk             /*!< </spirit:description> */
#define SDADC_SDADC_SFR_CDVF_Pos              (2U)
#define SDADC_SDADC_SFR_CDVF_Msk              (0x1UL << SDADC_SDADC_SFR_CDVF_Pos)     /*!< 0x00000004 */
#define SDADC_SDADC_SFR_CDVF                  SDADC_SDADC_SFR_CDVF_Msk              /*!< </spirit:description> */
#define SDADC_SDADC_SFR_WTHL_Pos              (3U)
#define SDADC_SDADC_SFR_WTHL_Msk              (0x1UL << SDADC_SDADC_SFR_WTHL_Pos)     /*!< 0x00000008 */
#define SDADC_SDADC_SFR_WTHL                  SDADC_SDADC_SFR_WTHL_Msk              /*!< </spirit:description> */
#define SDADC_SDADC_SFR_WTHH_Pos              (4U)
#define SDADC_SDADC_SFR_WTHH_Msk              (0x1UL << SDADC_SDADC_SFR_WTHH_Pos)     /*!< 0x00000010 */
#define SDADC_SDADC_SFR_WTHH                  SDADC_SDADC_SFR_WTHH_Msk              /*!< </spirit:description> */
#define SDADC_SDADC_SFR_DFEF_Pos              (8U)
#define SDADC_SDADC_SFR_DFEF_Msk              (0x1UL << SDADC_SDADC_SFR_DFEF_Pos)     /*!< 0x00000100 */
#define SDADC_SDADC_SFR_DFEF                  SDADC_SDADC_SFR_DFEF_Msk              /*!< </spirit:description> */
#define SDADC_SDADC_SFR_ANCHSEL_CNT_Pos       (16U)
#define SDADC_SDADC_SFR_ANCHSEL_CNT_Msk       (0x7UL << SDADC_SDADC_SFR_ANCHSEL_CNT_Pos)    /*!< 0x00070000 */
#define SDADC_SDADC_SFR_ANCHSEL_CNT           SDADC_SDADC_SFR_ANCHSEL_CNT_Msk       /*!< </spirit:description> */

/***************  Bit definition for SDADC_SDADC_RSER register  ***************/
#define SDADC_SDADC_RSER_DFFDIRE_Pos          (0U)
#define SDADC_SDADC_RSER_DFFDIRE_Msk          (0x1UL << SDADC_SDADC_RSER_DFFDIRE_Pos) /*!< 0x00000001 */
#define SDADC_SDADC_RSER_DFFDIRE              SDADC_SDADC_RSER_DFFDIRE_Msk          /*!< </spirit:description> */
#define SDADC_SDADC_RSER_DFORIE_Pos           (1U)
#define SDADC_SDADC_RSER_DFORIE_Msk           (0x1UL << SDADC_SDADC_RSER_DFORIE_Pos)  /*!< 0x00000002 */
#define SDADC_SDADC_RSER_DFORIE               SDADC_SDADC_RSER_DFORIE_Msk           /*!< </spirit:description> */
#define SDADC_SDADC_RSER_CDVEE_Pos            (2U)
#define SDADC_SDADC_RSER_CDVEE_Msk            (0x1UL << SDADC_SDADC_RSER_CDVEE_Pos)   /*!< 0x00000004 */
#define SDADC_SDADC_RSER_CDVEE                SDADC_SDADC_RSER_CDVEE_Msk            /*!< </spirit:description> */
#define SDADC_SDADC_RSER_WTHDIRE_Pos          (3U)
#define SDADC_SDADC_RSER_WTHDIRE_Msk          (0x1UL << SDADC_SDADC_RSER_WTHDIRE_Pos) /*!< 0x00000008 */
#define SDADC_SDADC_RSER_WTHDIRE              SDADC_SDADC_RSER_WTHDIRE_Msk          /*!< </spirit:description> */
#define SDADC_SDADC_RSER_CTRE_Pos             (11U)
#define SDADC_SDADC_RSER_CTRE_Msk             (0x1UL << SDADC_SDADC_RSER_CTRE_Pos)    /*!< 0x00000800 */
#define SDADC_SDADC_RSER_CTRE                 SDADC_SDADC_RSER_CTRE_Msk             /*!< </spirit:description> */
#define SDADC_SDADC_RSER_CLERE_Pos            (12U)
#define SDADC_SDADC_RSER_CLERE_Msk            (0x1UL << SDADC_SDADC_RSER_CLERE_Pos)   /*!< 0x00001000 */
#define SDADC_SDADC_RSER_CLERE                SDADC_SDADC_RSER_CLERE_Msk            /*!< </spirit:description> */
#define SDADC_SDADC_RSER_SGARE_Pos            (13U)
#define SDADC_SDADC_RSER_SGARE_Msk            (0x1UL << SDADC_SDADC_RSER_SGARE_Pos)   /*!< 0x00002000 */
#define SDADC_SDADC_RSER_SGARE                SDADC_SDADC_RSER_SGARE_Msk            /*!< </spirit:description> */
#define SDADC_SDADC_RSER_DIRFWGS_Pos          (14U)
#define SDADC_SDADC_RSER_DIRFWGS_Msk          (0x1UL << SDADC_SDADC_RSER_DIRFWGS_Pos) /*!< 0x00004000 */
#define SDADC_SDADC_RSER_DIRFWGS              SDADC_SDADC_RSER_DIRFWGS_Msk          /*!< </spirit:description> */
#define SDADC_SDADC_RSER_GGE_Pos              (15U)
#define SDADC_SDADC_RSER_GGE_Msk              (0x1UL << SDADC_SDADC_RSER_GGE_Pos)     /*!< 0x00008000 */
#define SDADC_SDADC_RSER_GGE                  SDADC_SDADC_RSER_GGE_Msk              /*!< </spirit:description> */
#define SDADC_SDADC_RSER_DFFDIRS_Pos          (16U)
#define SDADC_SDADC_RSER_DFFDIRS_Msk          (0x1UL << SDADC_SDADC_RSER_DFFDIRS_Pos) /*!< 0x00010000 */
#define SDADC_SDADC_RSER_DFFDIRS              SDADC_SDADC_RSER_DFFDIRS_Msk          /*!< </spirit:description> */
#define SDADC_SDADC_RSER_WTHDIRS_Pos          (17U)
#define SDADC_SDADC_RSER_WTHDIRS_Msk          (0x1UL << SDADC_SDADC_RSER_WTHDIRS_Pos) /*!< 0x00020000 */
#define SDADC_SDADC_RSER_WTHDIRS              SDADC_SDADC_RSER_WTHDIRS_Msk          /*!< </spirit:description> */

/***************  Bit definition for SDADC_SDADC_OSDR register  ***************/
#define SDADC_SDADC_OSDR_OSD_Pos              (0U)
#define SDADC_SDADC_OSDR_OSD_Msk              (0xFFUL << SDADC_SDADC_OSDR_OSD_Pos)    /*!< 0x000000FF */
#define SDADC_SDADC_OSDR_OSD                  SDADC_SDADC_OSDR_OSD_Msk              /*!< </spirit:description> */

/***************  Bit definition for SDADC_SDADC_FCR register  ****************/
#define SDADC_SDADC_FCR_FE_Pos                (0U)
#define SDADC_SDADC_FCR_FE_Msk                (0x1UL << SDADC_SDADC_FCR_FE_Pos)       /*!< 0x00000001 */
#define SDADC_SDADC_FCR_FE                    SDADC_SDADC_FCR_FE_Msk                /*!< </spirit:description> */
#define SDADC_SDADC_FCR_FSIZE_Pos             (1U)
#define SDADC_SDADC_FCR_FSIZE_Msk             (0x3UL << SDADC_SDADC_FCR_FSIZE_Pos)    /*!< 0x00000006 */
#define SDADC_SDADC_FCR_FSIZE                 SDADC_SDADC_FCR_FSIZE_Msk             /*!< </spirit:description> */
#define SDADC_SDADC_FCR_FOWEN_Pos             (3U)
#define SDADC_SDADC_FCR_FOWEN_Msk             (0x1UL << SDADC_SDADC_FCR_FOWEN_Pos)    /*!< 0x00000008 */
#define SDADC_SDADC_FCR_FOWEN                 SDADC_SDADC_FCR_FOWEN_Msk             /*!< </spirit:description> */
#define SDADC_SDADC_FCR_FTHLD_Pos             (8U)
#define SDADC_SDADC_FCR_FTHLD_Msk             (0xFUL << SDADC_SDADC_FCR_FTHLD_Pos)    /*!< 0x00000F00 */
#define SDADC_SDADC_FCR_FTHLD                 SDADC_SDADC_FCR_FTHLD_Msk             /*!< </spirit:description> */
#define SDADC_SDADC_FCR_FRST_Pos              (16U)
#define SDADC_SDADC_FCR_FRST_Msk              (0x1UL << SDADC_SDADC_FCR_FRST_Pos)    /*!< 0x00010000 */
#define SDADC_SDADC_FCR_FRST                  SDADC_SDADC_FCR_FRST_Msk             /*!< </spirit:description> */

/***************  Bit definition for SDADC_SDADC_STKR register  ***************/
#define SDADC_SDADC_STKR_ST_KEY_Pos           (0U)
#define SDADC_SDADC_STKR_ST_KEY_Msk           (0xFFFFUL << SDADC_SDADC_STKR_ST_KEY_Pos)   /*!< 0x0000FFFF */
#define SDADC_SDADC_STKR_ST_KEY               SDADC_SDADC_STKR_ST_KEY_Msk           /*!< </spirit:description> */

/***************  Bit definition for SDADC_SDADC_CDR register  ****************/
#define SDADC_SDADC_CDR_CDATA_Pos             (0U)
#define SDADC_SDADC_CDR_CDATA_Msk             (0xFFFFFFUL << SDADC_SDADC_CDR_CDATA_Pos)   /*!< 0x00FFFFFF */
#define SDADC_SDADC_CDR_CDATA                 SDADC_SDADC_CDR_CDATA_Msk             /*!< </spirit:description> */

/**************  Bit definition for SDADC_SDADC_WTHHLR register  **************/
#define SDADC_SDADC_WTHHLR_THRL_Pos           (0U)
#define SDADC_SDADC_WTHHLR_THRL_Msk           (0xFFFFUL << SDADC_SDADC_WTHHLR_THRL_Pos)       /*!< 0x0000FFFF */
#define SDADC_SDADC_WTHHLR_THRL               SDADC_SDADC_WTHHLR_THRL_Msk           /*!< </spirit:description> */
#define SDADC_SDADC_WTHHLR_THRH_Pos           (16U)
#define SDADC_SDADC_WTHHLR_THRH_Msk           (0xFFFFUL << SDADC_SDADC_WTHHLR_THRH_Pos)       /*!< 0xFFFFF0000 */
#define SDADC_SDADC_WTHHLR_THRH               SDADC_SDADC_WTHHLR_THRH_Msk           /*!< </spirit:description> */

/**************  Bit definition for SDADC_SDADC_LDREG register  ***************/
#define SDADC_SDADC_LDREG_LDR_Pos             (0U)
#define SDADC_SDADC_LDREG_LDR_Msk             (0xFFFFUL << SDADC_SDADC_LDREG_LDR_Pos) /*!< 0x0000FFFF */
#define SDADC_SDADC_LDREG_LDR                 SDADC_SDADC_LDREG_LDR_Msk             /*!< </spirit:description> */

/**************  Bit definition for SDADC_SDADC_LTREG register  ***************/
#define SDADC_SDADC_LTREG_LTR_Pos             (0U)
#define SDADC_SDADC_LTREG_LTR_Msk             (0xFFFFFFUL << SDADC_SDADC_LTREG_LTR_Pos)   /*!< 0x00FFFFFF */
#define SDADC_SDADC_LTREG_LTR                 SDADC_SDADC_LTREG_LTR_Msk             /*!< </spirit:description> */

#define SD_ADC1_BASE           0x42008000UL 
#define SD_ADC2_BASE           0x42008400UL 

#define SD_ADC1                ((SDADC_TypeDef *) SD_ADC1_BASE) 
#define SD_ADC2                ((SDADC_TypeDef *) SD_ADC2_BASE) 

#endif /* __SR5E1_SDADC_H */

