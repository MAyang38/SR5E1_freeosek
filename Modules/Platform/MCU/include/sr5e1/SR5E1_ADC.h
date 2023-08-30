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

#ifndef __SR5E1_ADC_H
#define __SR5E1_ADC_H

/*******************************************************************************
 * REVISION HISTORY                                                            *
 * REV       DATE       RM REV          DESCRIPTION OF CHANGE                  *
 * ------ ----------- ------------ --------------------------------------------*
 * 1.0C2  16-Mar-2022 Rev 1 Draft C     SR5E1_RDP_0_1_Rev1_C_18FEB22           *
 *                                      Fixed enumerated values                *
 * ------ ----------- ------------ --------------------------------------------*
 * 1.0C1  09-Mar-2022 Rev 1 Draft C     SR5E1_RDP_0_1_Rev1_C_18FEB22           *
 *                                      Added ADC Common tag                   *
 ******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                                   (ADC)                                    */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO uint32_t ISR;           /*!< ISR      Address offset: 0x00 */
  __IO uint32_t IER;           /*!< IER      Address offset: 0x04 */
  __IO uint32_t CR;            /*!< CR       Address offset: 0x08 */
  __IO uint32_t CFGR;          /*!< CFGR     Address offset: 0x0C */
  __IO uint32_t CFGR2;         /*!< CFGR2    Address offset: 0x10 */
  __IO uint32_t SMPR1;         /*!< SMPR1    Address offset: 0x14 */
  __IO uint32_t SMPR2;         /*!< SMPR2    Address offset: 0x18 */
       uint32_t RESERVED0;     /*!< Reserved Address offset: 0x1C */
  __IO uint32_t TR1;           /*!< TR1      Address offset: 0x20 */
  __IO uint32_t TR2;           /*!< TR2      Address offset: 0x24 */
  __IO uint32_t TR3;           /*!< TR3      Address offset: 0x28 */
       uint32_t RESERVED1;     /*!< Reserved Address offset: 0x2C */
  __IO uint32_t SQR1;          /*!< SQR1     Address offset: 0x30 */
  __IO uint32_t SQR2;          /*!< SQR2     Address offset: 0x34 */
  __IO uint32_t SQR3;          /*!< SQR3     Address offset: 0x38 */
  __IO uint32_t SQR4;          /*!< SQR4     Address offset: 0x3C */
  __IO uint32_t DR;            /*!< DR       Address offset: 0x40 */
       uint32_t RESERVED2[2];  /*!< Reserved Address offset: 0x44-0x48 */
  __IO uint32_t JSQR;          /*!< JSQR     Address offset: 0x4C */
       uint32_t RESERVED3[4];  /*!< Reserved Address offset: 0x50-0x5C */
  __IO uint32_t OFR1;          /*!< OFR1     Address offset: 0x60 */
  __IO uint32_t OFR2;          /*!< OFR2     Address offset: 0x64 */
  __IO uint32_t OFR3;          /*!< OFR3     Address offset: 0x68 */
  __IO uint32_t OFR4;          /*!< OFR4     Address offset: 0x6C */
       uint32_t RESERVED4[4];  /*!< Reserved Address offset: 0x70-0x7C */
  __IO uint32_t JDR1;          /*!< JDR1     Address offset: 0x80 */
  __IO uint32_t JDR2;          /*!< JDR2     Address offset: 0x84 */
  __IO uint32_t JDR3;          /*!< JDR3     Address offset: 0x88 */
  __IO uint32_t JDR4;          /*!< JDR4     Address offset: 0x8C */
       uint32_t RESERVED5[4];  /*!< Reserved Address offset: 0x90-0x9C */
  __IO uint32_t AWD2CR;        /*!< AWD2CR   Address offset: 0xA0 */
  __IO uint32_t AWD3CR;        /*!< AWD3CR   Address offset: 0xA4 */
       uint32_t RESERVED6[2];  /*!< Reserved Address offset: 0xA8-0xAC */
  __IO uint32_t DIFSEL;        /*!< DIFSEL   Address offset: 0xB0 */
  __IO uint32_t CALFACT;       /*!< CALFACT  Address offset: 0xB4 */
} ADC_TypeDef;

/******************************************************************************/
/*                                                                            */
/*                          ADC_COMMON (ADC_Common)                           */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __I  uint32_t CSR;        /*!< CSR      Address offset: 0x0 */
       uint32_t RESERVED0;  /*!< Reserved Address offset: 0x4 */
  __IO uint32_t CCR;        /*!< CCR      Address offset: 0x8 */
  __I  uint32_t CDR;        /*!< CDR      Address offset: 0xC */
} ADC_Common_TypeDef;


/*******************  Bit definition for ADC_ISR register  ********************/
#define ADC_ISR_ADRDY_Pos            (0U)
#define ADC_ISR_ADRDY_Msk            (0x1UL << ADC_ISR_ADRDY_Pos) /*!< 0x00000001 */
#define ADC_ISR_ADRDY                ADC_ISR_ADRDY_Msk           /*!< </spirit:description> */
#define ADC_ISR_EOSMP_Pos            (1U)
#define ADC_ISR_EOSMP_Msk            (0x1UL << ADC_ISR_EOSMP_Pos) /*!< 0x00000002 */
#define ADC_ISR_EOSMP                ADC_ISR_EOSMP_Msk           /*!< </spirit:description> */
#define ADC_ISR_EOC_Pos              (2U)
#define ADC_ISR_EOC_Msk              (0x1UL << ADC_ISR_EOC_Pos)   /*!< 0x00000004 */
#define ADC_ISR_EOC                  ADC_ISR_EOC_Msk             /*!< </spirit:description> */
#define ADC_ISR_EOS_Pos              (3U)
#define ADC_ISR_EOS_Msk              (0x1UL << ADC_ISR_EOS_Pos)   /*!< 0x00000008 */
#define ADC_ISR_EOS                  ADC_ISR_EOS_Msk             /*!< </spirit:description> */
#define ADC_ISR_OVR_Pos              (4U)
#define ADC_ISR_OVR_Msk              (0x1UL << ADC_ISR_OVR_Pos)   /*!< 0x00000010 */
#define ADC_ISR_OVR                  ADC_ISR_OVR_Msk             /*!< </spirit:description> */
#define ADC_ISR_JEOC_Pos             (5U)
#define ADC_ISR_JEOC_Msk             (0x1UL << ADC_ISR_JEOC_Pos)  /*!< 0x00000020 */
#define ADC_ISR_JEOC                 ADC_ISR_JEOC_Msk            /*!< </spirit:description> */
#define ADC_ISR_JEOS_Pos             (6U)
#define ADC_ISR_JEOS_Msk             (0x1UL << ADC_ISR_JEOS_Pos)  /*!< 0x00000040 */
#define ADC_ISR_JEOS                 ADC_ISR_JEOS_Msk            /*!< </spirit:description> */
#define ADC_ISR_AWD1_Pos             (7U)
#define ADC_ISR_AWD1_Msk             (0x1UL << ADC_ISR_AWD1_Pos)  /*!< 0x00000080 */
#define ADC_ISR_AWD1                 ADC_ISR_AWD1_Msk            /*!< </spirit:description> */
#define ADC_ISR_AWD2_Pos             (8U)
#define ADC_ISR_AWD2_Msk             (0x1UL << ADC_ISR_AWD2_Pos)  /*!< 0x00000100 */
#define ADC_ISR_AWD2                 ADC_ISR_AWD2_Msk            /*!< </spirit:description> */
#define ADC_ISR_AWD3_Pos             (9U)
#define ADC_ISR_AWD3_Msk             (0x1UL << ADC_ISR_AWD3_Pos)  /*!< 0x00000200 */
#define ADC_ISR_AWD3                 ADC_ISR_AWD3_Msk            /*!< </spirit:description> */
#define ADC_ISR_JQOVF_Pos            (10U)
#define ADC_ISR_JQOVF_Msk            (0x1UL << ADC_ISR_JQOVF_Pos) /*!< 0x00000400 */
#define ADC_ISR_JQOVF                ADC_ISR_JQOVF_Msk           /*!< </spirit:description> */

/*******************  Bit definition for ADC_IER register  ********************/
#define ADC_IER_ADRDYIE_Pos          (0U)
#define ADC_IER_ADRDYIE_Msk          (0x1UL << ADC_IER_ADRDYIE_Pos) /*!< 0x00000001 */
#define ADC_IER_ADRDYIE              ADC_IER_ADRDYIE_Msk         /*!< </spirit:description> */
#define ADC_IER_EOSMPIE_Pos          (1U)
#define ADC_IER_EOSMPIE_Msk          (0x1UL << ADC_IER_EOSMPIE_Pos) /*!< 0x00000002 */
#define ADC_IER_EOSMPIE              ADC_IER_EOSMPIE_Msk         /*!< </spirit:description> */
#define ADC_IER_EOCIE_Pos            (2U)
#define ADC_IER_EOCIE_Msk            (0x1UL << ADC_IER_EOCIE_Pos) /*!< 0x00000004 */
#define ADC_IER_EOCIE                ADC_IER_EOCIE_Msk           /*!< </spirit:description> */
#define ADC_IER_EOSIE_Pos            (3U)
#define ADC_IER_EOSIE_Msk            (0x1UL << ADC_IER_EOSIE_Pos) /*!< 0x00000008 */
#define ADC_IER_EOSIE                ADC_IER_EOSIE_Msk           /*!< </spirit:description> */
#define ADC_IER_OVRIE_Pos            (4U)
#define ADC_IER_OVRIE_Msk            (0x1UL << ADC_IER_OVRIE_Pos) /*!< 0x00000010 */
#define ADC_IER_OVRIE                ADC_IER_OVRIE_Msk           /*!< </spirit:description> */
#define ADC_IER_JEOCIE_Pos           (5U)
#define ADC_IER_JEOCIE_Msk             (0x1UL << ADC_IER_JEOCIE_Pos)  /*!< 0x00000020 */
#define ADC_IER_JEOCIE               ADC_IER_JEOCIE_Msk          /*!< </spirit:description> */
#define ADC_IER_JEOSIE_Pos           (6U)
#define ADC_IER_JEOSIE_Msk             (0x1UL << ADC_IER_JEOSIE_Pos)  /*!< 0x00000040 */
#define ADC_IER_JEOSIE               ADC_IER_JEOSIE_Msk          /*!< </spirit:description> */
#define ADC_IER_AWD1IE_Pos           (7U)
#define ADC_IER_AWD1IE_Msk             (0x1UL << ADC_IER_AWD1IE_Pos)  /*!< 0x00000080 */
#define ADC_IER_AWD1IE               ADC_IER_AWD1IE_Msk          /*!< </spirit:description> */
#define ADC_IER_AWD2IE_Pos           (8U)
#define ADC_IER_AWD2IE_Msk             (0x1UL << ADC_IER_AWD2IE_Pos)  /*!< 0x00000100 */
#define ADC_IER_AWD2IE               ADC_IER_AWD2IE_Msk          /*!< </spirit:description> */
#define ADC_IER_AWD3IE_Pos           (9U)
#define ADC_IER_AWD3IE_Msk             (0x1UL << ADC_IER_AWD3IE_Pos)  /*!< 0x00000200 */
#define ADC_IER_AWD3IE               ADC_IER_AWD3IE_Msk          /*!< </spirit:description> */
#define ADC_IER_JQOVFIE_Pos          (10U)
#define ADC_IER_JQOVFIE_Msk          (0x1UL << ADC_IER_JQOVFIE_Pos) /*!< 0x00000400 */
#define ADC_IER_JQOVFIE              ADC_IER_JQOVFIE_Msk         /*!< </spirit:description> */

/********************  Bit definition for ADC_CR register  ********************/
#define ADC_CR_ADEN_Pos              (0U)
#define ADC_CR_ADEN_Msk              (0x1UL << ADC_CR_ADEN_Pos)   /*!< 0x00000001 */
#define ADC_CR_ADEN                  ADC_CR_ADEN_Msk             /*!< </spirit:description> */
#define ADC_CR_ADDIS_Pos             (1U)
#define ADC_CR_ADDIS_Msk             (0x1UL << ADC_CR_ADDIS_Pos)  /*!< 0x00000002 */
#define ADC_CR_ADDIS                 ADC_CR_ADDIS_Msk            /*!< </spirit:description> */
#define ADC_CR_ADSTART_Pos           (2U)
#define ADC_CR_ADSTART_Msk             (0x1UL << ADC_CR_ADSTART_Pos)  /*!< 0x00000004 */
#define ADC_CR_ADSTART               ADC_CR_ADSTART_Msk          /*!< </spirit:description> */
#define ADC_CR_JADSTART_Pos          (3U)
#define ADC_CR_JADSTART_Msk          (0x1UL << ADC_CR_JADSTART_Pos) /*!< 0x00000008 */
#define ADC_CR_JADSTART              ADC_CR_JADSTART_Msk         /*!< </spirit:description> */
#define ADC_CR_ADSTP_Pos             (4U)
#define ADC_CR_ADSTP_Msk             (0x1UL << ADC_CR_ADSTP_Pos)  /*!< 0x00000010 */
#define ADC_CR_ADSTP                 ADC_CR_ADSTP_Msk            /*!< </spirit:description> */
#define ADC_CR_JADSTP_Pos            (5U)
#define ADC_CR_JADSTP_Msk            (0x1UL << ADC_CR_JADSTP_Pos) /*!< 0x00000020 */
#define ADC_CR_JADSTP                ADC_CR_JADSTP_Msk           /*!< </spirit:description> */
#define ADC_CR_ADVREGEN_Pos          (28U)
#define ADC_CR_ADVREGEN_Msk          (0x1UL << ADC_CR_ADVREGEN_Pos) /*!< 0x10000000 */
#define ADC_CR_ADVREGEN              ADC_CR_ADVREGEN_Msk         /*!< </spirit:description> */
#define ADC_CR_DEEPPWD_Pos           (29U)
#define ADC_CR_DEEPPWD_Msk             (0x1UL << ADC_CR_DEEPPWD_Pos)  /*!< 0x20000000 */
#define ADC_CR_DEEPPWD               ADC_CR_DEEPPWD_Msk          /*!< </spirit:description> */
#define ADC_CR_ADCALDIF_Pos          (30U)
#define ADC_CR_ADCALDIF_Msk          (0x1UL << ADC_CR_ADCALDIF_Pos) /*!< 0x40000000 */
#define ADC_CR_ADCALDIF              ADC_CR_ADCALDIF_Msk         /*!< </spirit:description> */
#define ADC_CR_ADCAL_Pos             (31U)
#define ADC_CR_ADCAL_Msk             (0x1UL << ADC_CR_ADCAL_Pos)  /*!< 0x80000000 */
#define ADC_CR_ADCAL                 ADC_CR_ADCAL_Msk            /*!< </spirit:description> */

/*******************  Bit definition for ADC_CFGR register  *******************/
#define ADC_CFGR_DMAEN_Pos           (0U)
#define ADC_CFGR_DMAEN_Msk             (0x1UL << ADC_CFGR_DMAEN_Pos)  /*!< 0x00000001 */
#define ADC_CFGR_DMAEN               ADC_CFGR_DMAEN_Msk          /*!< </spirit:description> */
#define ADC_CFGR_DMACFG_Pos          (1U)
#define ADC_CFGR_DMACFG_Msk          (0x1UL << ADC_CFGR_DMACFG_Pos) /*!< 0x00000002 */
#define ADC_CFGR_DMACFG              ADC_CFGR_DMACFG_Msk         /*!< </spirit:description> */
#define ADC_CFGR_RES_Pos             (3U)
#define ADC_CFGR_RES_Msk             (0x3UL << ADC_CFGR_RES_Pos) /*!< 0x00000018 */
#define ADC_CFGR_RES                 ADC_CFGR_RES_Msk         /*!< </spirit:description> */
#define ADC_CFGR_RES_0              (0x1UL << ADC_CFGR_RES_Pos)  /*!< 0x00000008 */
#define ADC_CFGR_RES_1              (0x2UL << ADC_CFGR_RES_Pos)  /*!< 0x00000010 */
#define ADC_CFGR_EXTSEL_Pos          (5U)
#define ADC_CFGR_EXTSEL_Msk          (0x1FUL << ADC_CFGR_EXTSEL_Pos)  /*!< 0x000003E0 */
#define ADC_CFGR_EXTSEL              ADC_CFGR_EXTSEL_Msk         /*!< </spirit:description> */
#define ADC_CFGR_EXTSEL_0           (0x1UL << ADC_CFGR_EXTSEL_Pos)    /*!< 0x00000020 */
#define ADC_CFGR_EXTSEL_1           (0x2UL << ADC_CFGR_EXTSEL_Pos)    /*!< 0x00000040 */
#define ADC_CFGR_EXTSEL_2           (0x4UL << ADC_CFGR_EXTSEL_Pos)    /*!< 0x00000080 */
#define ADC_CFGR_EXTSEL_3           (0x8UL << ADC_CFGR_EXTSEL_Pos)    /*!< 0x00000100 */
#define ADC_CFGR_EXTSEL_4           (0x10UL << ADC_CFGR_EXTSEL_Pos)    /*!< 0x00000200 */
#define ADC_CFGR_EXTEN_Pos           (10U)
#define ADC_CFGR_EXTEN_Msk           (0x3UL << ADC_CFGR_EXTEN_Pos)  /*!< 0x00000C00 */
#define ADC_CFGR_EXTEN               ADC_CFGR_EXTEN_Msk          /*!< </spirit:description> */
#define ADC_CFGR_EXTEN_0            (0x1UL << ADC_CFGR_EXTEN_Pos)  /*!< 0x00000400 */
#define ADC_CFGR_EXTEN_1            (0x2UL << ADC_CFGR_EXTEN_Pos)  /*!< 0x00000800 */
#define ADC_CFGR_OVRMOD_Pos          (12U)
#define ADC_CFGR_OVRMOD_Msk          (0x1UL << ADC_CFGR_OVRMOD_Pos) /*!< 0x00001000 */
#define ADC_CFGR_OVRMOD              ADC_CFGR_OVRMOD_Msk         /*!< </spirit:description> */
#define ADC_CFGR_CONT_Pos            (13U)
#define ADC_CFGR_CONT_Msk            (0x1UL << ADC_CFGR_CONT_Pos) /*!< 0x00002000 */
#define ADC_CFGR_CONT                ADC_CFGR_CONT_Msk           /*!< </spirit:description> */
#define ADC_CFGR_AUTDLY_Pos          (14U)
#define ADC_CFGR_AUTDLY_Msk          (0x1UL << ADC_CFGR_AUTDLY_Pos) /*!< 0x00004000 */
#define ADC_CFGR_AUTDLY              ADC_CFGR_AUTDLY_Msk         /*!< </spirit:description> */
#define ADC_CFGR_ALIGN_Pos           (15U)
#define ADC_CFGR_ALIGN_Msk             (0x1UL << ADC_CFGR_ALIGN_Pos)  /*!< 0x00008000 */
#define ADC_CFGR_ALIGN               ADC_CFGR_ALIGN_Msk          /*!< </spirit:description> */
#define ADC_CFGR_DISCEN_Pos          (16U)
#define ADC_CFGR_DISCEN_Msk          (0x1UL << ADC_CFGR_DISCEN_Pos) /*!< 0x00010000 */
#define ADC_CFGR_DISCEN              ADC_CFGR_DISCEN_Msk         /*!< </spirit:description> */
#define ADC_CFGR_DISCNUM_Pos         (17U)
#define ADC_CFGR_DISCNUM_Msk         (0x7UL << ADC_CFGR_DISCNUM_Pos)  /*!< 0x000E0000 */
#define ADC_CFGR_DISCNUM             ADC_CFGR_DISCNUM_Msk        /*!< </spirit:description> */
#define ADC_CFGR_DISCNUM_0          (0x1UL << ADC_CFGR_DISCNUM_Pos)    /*!< 0x00020000 */
#define ADC_CFGR_DISCNUM_1          (0x2UL << ADC_CFGR_DISCNUM_Pos)    /*!< 0x00040000 */
#define ADC_CFGR_DISCNUM_2          (0x4UL << ADC_CFGR_DISCNUM_Pos)    /*!< 0x00080000 */
#define ADC_CFGR_JDISCEN_Pos         (20U)
#define ADC_CFGR_JDISCEN_Msk         (0x1UL << ADC_CFGR_JDISCEN_Pos)  /*!< 0x00100000 */
#define ADC_CFGR_JDISCEN             ADC_CFGR_JDISCEN_Msk        /*!< </spirit:description> */
#define ADC_CFGR_JQM_Pos             (21U)
#define ADC_CFGR_JQM_Msk             (0x1UL << ADC_CFGR_JQM_Pos)  /*!< 0x00200000 */
#define ADC_CFGR_JQM                 ADC_CFGR_JQM_Msk            /*!< </spirit:description> */
#define ADC_CFGR_AWD1SGL_Pos         (22U)
#define ADC_CFGR_AWD1SGL_Msk         (0x1UL << ADC_CFGR_AWD1SGL_Pos)  /*!< 0x00400000 */
#define ADC_CFGR_AWD1SGL             ADC_CFGR_AWD1SGL_Msk        /*!< </spirit:description> */
#define ADC_CFGR_AWD1EN_Pos          (23U)
#define ADC_CFGR_AWD1EN_Msk          (0x1UL << ADC_CFGR_AWD1EN_Pos) /*!< 0x00800000 */
#define ADC_CFGR_AWD1EN              ADC_CFGR_AWD1EN_Msk         /*!< </spirit:description> */
#define ADC_CFGR_JAWD1EN_Pos         (24U)
#define ADC_CFGR_JAWD1EN_Msk         (0x1UL << ADC_CFGR_JAWD1EN_Pos)  /*!< 0x01000000 */
#define ADC_CFGR_JAWD1EN             ADC_CFGR_JAWD1EN_Msk        /*!< </spirit:description> */
#define ADC_CFGR_JAUTO_Pos           (25U)
#define ADC_CFGR_JAUTO_Msk           (0x1UL << ADC_CFGR_JAUTO_Pos) /*!< 0x02000000 */
#define ADC_CFGR_JAUTO               ADC_CFGR_JAUTO_Msk          /*!< </spirit:description> */
#define ADC_CFGR_AWD1CH_Pos          (26U)
#define ADC_CFGR_AWD1CH_Msk          (0x1FUL << ADC_CFGR_AWD1CH_Pos)  /*!< 0x7C000000 */
#define ADC_CFGR_AWD1CH              ADC_CFGR_AWD1CH_Msk         /*!< </spirit:description> */
#define ADC_CFGR_AWD1CH_0           (0x1UL << ADC_CFGR_AWD1CH_Pos)    /*!< 0x04000000 */
#define ADC_CFGR_AWD1CH_1           (0x2UL << ADC_CFGR_AWD1CH_Pos)    /*!< 0x08000000 */
#define ADC_CFGR_AWD1CH_2           (0x4UL << ADC_CFGR_AWD1CH_Pos)    /*!< 0x10000000 */
#define ADC_CFGR_AWD1CH_3           (0x8UL << ADC_CFGR_AWD1CH_Pos)    /*!< 0x20000000 */
#define ADC_CFGR_AWD1CH_4           (0x10UL << ADC_CFGR_AWD1CH_Pos)    /*!< 0x40000000 */
#define ADC_CFGR_JQDIS_Pos           (31U)
#define ADC_CFGR_JQDIS_Msk           (0x1UL << ADC_CFGR_JQDIS_Pos)  /*!< 0x80000000 */
#define ADC_CFGR_JQDIS               ADC_CFGR_JQDIS_Msk          /*!< </spirit:description> */

/******************  Bit definition for ADC_CFGR2 register  *******************/
#define ADC_CFGR2_ROVSE_Pos          (0U)
#define ADC_CFGR2_ROVSE_Msk          (0x1UL << ADC_CFGR2_ROVSE_Pos) /*!< 0x00000001 */
#define ADC_CFGR2_ROVSE              ADC_CFGR2_ROVSE_Msk         /*!< </spirit:description> */
#define ADC_CFGR2_JOVSE_Pos          (1U)
#define ADC_CFGR2_JOVSE_Msk          (0x1UL << ADC_CFGR2_JOVSE_Pos) /*!< 0x00000002 */
#define ADC_CFGR2_JOVSE              ADC_CFGR2_JOVSE_Msk         /*!< </spirit:description> */
#define ADC_CFGR2_OVSR_Pos           (2U)
#define ADC_CFGR2_OVSR_Msk             (0x7UL << ADC_CFGR2_OVSR_Pos)  /*!< 0x0000001C */
#define ADC_CFGR2_OVSR               ADC_CFGR2_OVSR_Msk          /*!< </spirit:description> */
#define ADC_CFGR2_OVSR_0            (0x1UL << ADC_CFGR2_OVSR_Pos)  /*!< 0x00000004 */
#define ADC_CFGR2_OVSR_1            (0x2UL << ADC_CFGR2_OVSR_Pos)  /*!< 0x00000008 */
#define ADC_CFGR2_OVSR_2            (0x4UL << ADC_CFGR2_OVSR_Pos)  /*!< 0x00000010 */
#define ADC_CFGR2_OVSS_Pos           (5U)
#define ADC_CFGR2_OVSS_Msk             (0xFUL << ADC_CFGR2_OVSS_Pos)  /*!< 0x000001E0 */
#define ADC_CFGR2_OVSS               ADC_CFGR2_OVSS_Msk          /*!< </spirit:description> */
#define ADC_CFGR2_OVSS_0            (0x1UL << ADC_CFGR2_OVSS_Pos)  /*!< 0x00000020 */
#define ADC_CFGR2_OVSS_1            (0x2UL << ADC_CFGR2_OVSS_Pos)  /*!< 0x00000040 */
#define ADC_CFGR2_OVSS_2            (0x4UL << ADC_CFGR2_OVSS_Pos)  /*!< 0x00000080 */
#define ADC_CFGR2_OVSS_3            (0x8UL << ADC_CFGR2_OVSS_Pos)  /*!< 0x00000100 */
#define ADC_CFGR2_TROVS_Pos          (9U)
#define ADC_CFGR2_TROVS_Msk          (0x1UL << ADC_CFGR2_TROVS_Pos) /*!< 0x00000200 */
#define ADC_CFGR2_TROVS              ADC_CFGR2_TROVS_Msk         /*!< </spirit:description> */
#define ADC_CFGR2_ROVSM_Pos          (10U)
#define ADC_CFGR2_ROVSM_Msk          (0x1UL << ADC_CFGR2_ROVSM_Pos) /*!< 0x00000400 */
#define ADC_CFGR2_ROVSM              ADC_CFGR2_ROVSM_Msk         /*!< </spirit:description> */
#define ADC_CFGR2_SWTRIG_Pos         (25U)
#define ADC_CFGR2_SWTRIG_Msk         (0x1UL << ADC_CFGR2_SWTRIG_Pos)  /*!< 0x02000000 */
#define ADC_CFGR2_SWTRIG             ADC_CFGR2_SWTRIG_Msk        /*!< </spirit:description> */
#define ADC_CFGR2_BULB_Pos           (26U)
#define ADC_CFGR2_BULB_Msk             (0x1UL << ADC_CFGR2_BULB_Pos)  /*!< 0x04000000 */
#define ADC_CFGR2_BULB               ADC_CFGR2_BULB_Msk          /*!< </spirit:description> */
#define ADC_CFGR2_SMPTRIG_Pos        (27U)
#define ADC_CFGR2_SMPTRIG_Msk        (0x1UL << ADC_CFGR2_SMPTRIG_Pos)   /*!< 0x08000000 */
#define ADC_CFGR2_SMPTRIG            ADC_CFGR2_SMPTRIG_Msk       /*!< </spirit:description> */

/******************  Bit definition for ADC_SMPR1 register  *******************/
#define ADC_SMPR1_SMP0_Pos           (0U)
#define ADC_SMPR1_SMP0_Msk             (0x7UL << ADC_SMPR1_SMP0_Pos)  /*!< 0x00000007 */
#define ADC_SMPR1_SMP0               ADC_SMPR1_SMP0_Msk          /*!< </spirit:description> */
#define ADC_SMPR1_SMP0_0            (0x1UL << ADC_SMPR1_SMP0_Pos)  /*!< 0x00000001 */
#define ADC_SMPR1_SMP0_1            (0x2UL << ADC_SMPR1_SMP0_Pos)  /*!< 0x00000002 */
#define ADC_SMPR1_SMP0_2            (0x4UL << ADC_SMPR1_SMP0_Pos)  /*!< 0x00000004 */
#define ADC_SMPR1_SMP1_Pos           (3U)
#define ADC_SMPR1_SMP1_Msk             (0x7UL << ADC_SMPR1_SMP1_Pos)  /*!< 0x00000038 */
#define ADC_SMPR1_SMP1               ADC_SMPR1_SMP1_Msk          /*!< </spirit:description> */
#define ADC_SMPR1_SMP1_0            (0x1UL << ADC_SMPR1_SMP1_Pos)  /*!< 0x00000008 */
#define ADC_SMPR1_SMP1_1            (0x2UL << ADC_SMPR1_SMP1_Pos)  /*!< 0x00000010 */
#define ADC_SMPR1_SMP1_2            (0x4UL << ADC_SMPR1_SMP1_Pos)  /*!< 0x00000020 */
#define ADC_SMPR1_SMP2_Pos           (6U)
#define ADC_SMPR1_SMP2_Msk             (0x7UL << ADC_SMPR1_SMP2_Pos)  /*!< 0x000001C0 */
#define ADC_SMPR1_SMP2               ADC_SMPR1_SMP2_Msk          /*!< </spirit:description> */
#define ADC_SMPR1_SMP2_0            (0x1UL << ADC_SMPR1_SMP2_Pos)  /*!< 0x00000040 */
#define ADC_SMPR1_SMP2_1            (0x2UL << ADC_SMPR1_SMP2_Pos)  /*!< 0x00000080 */
#define ADC_SMPR1_SMP2_2            (0x4UL << ADC_SMPR1_SMP2_Pos)  /*!< 0x00000100 */
#define ADC_SMPR1_SMP3_Pos           (9U)
#define ADC_SMPR1_SMP3_Msk             (0x7UL << ADC_SMPR1_SMP3_Pos)  /*!< 0x00000E00 */
#define ADC_SMPR1_SMP3               ADC_SMPR1_SMP3_Msk          /*!< </spirit:description> */
#define ADC_SMPR1_SMP3_0            (0x1UL << ADC_SMPR1_SMP3_Pos)  /*!< 0x00000200 */
#define ADC_SMPR1_SMP3_1            (0x2UL << ADC_SMPR1_SMP3_Pos)  /*!< 0x00000400 */
#define ADC_SMPR1_SMP3_2            (0x4UL << ADC_SMPR1_SMP3_Pos)  /*!< 0x00000800 */
#define ADC_SMPR1_SMP4_Pos           (12U)
#define ADC_SMPR1_SMP4_Msk             (0x7UL << ADC_SMPR1_SMP4_Pos)  /*!< 0x00007000 */
#define ADC_SMPR1_SMP4               ADC_SMPR1_SMP4_Msk          /*!< </spirit:description> */
#define ADC_SMPR1_SMP4_0            (0x1UL << ADC_SMPR1_SMP4_Pos)  /*!< 0x00001000 */
#define ADC_SMPR1_SMP4_1            (0x2UL << ADC_SMPR1_SMP4_Pos)  /*!< 0x00002000 */
#define ADC_SMPR1_SMP4_2            (0x4UL << ADC_SMPR1_SMP4_Pos)  /*!< 0x00004000 */
#define ADC_SMPR1_SMP5_Pos           (15U)
#define ADC_SMPR1_SMP5_Msk             (0x7UL << ADC_SMPR1_SMP5_Pos)  /*!< 0x00038000 */
#define ADC_SMPR1_SMP5               ADC_SMPR1_SMP5_Msk          /*!< </spirit:description> */
#define ADC_SMPR1_SMP5_0            (0x1UL << ADC_SMPR1_SMP5_Pos)  /*!< 0x00008000 */
#define ADC_SMPR1_SMP5_1            (0x2UL << ADC_SMPR1_SMP5_Pos)  /*!< 0x00010000 */
#define ADC_SMPR1_SMP5_2            (0x4UL << ADC_SMPR1_SMP5_Pos)  /*!< 0x00020000 */
#define ADC_SMPR1_SMP6_Pos           (18U)
#define ADC_SMPR1_SMP6_Msk             (0x7UL << ADC_SMPR1_SMP6_Pos)  /*!< 0x001C0000 */
#define ADC_SMPR1_SMP6               ADC_SMPR1_SMP6_Msk          /*!< </spirit:description> */
#define ADC_SMPR1_SMP6_0            (0x1UL << ADC_SMPR1_SMP6_Pos)  /*!< 0x00040000 */
#define ADC_SMPR1_SMP6_1            (0x2UL << ADC_SMPR1_SMP6_Pos)  /*!< 0x00080000 */
#define ADC_SMPR1_SMP6_2            (0x4UL << ADC_SMPR1_SMP6_Pos)  /*!< 0x00100000 */
#define ADC_SMPR1_SMP7_Pos           (21U)
#define ADC_SMPR1_SMP7_Msk             (0x7UL << ADC_SMPR1_SMP7_Pos)  /*!< 0x00E00000 */
#define ADC_SMPR1_SMP7               ADC_SMPR1_SMP7_Msk          /*!< </spirit:description> */
#define ADC_SMPR1_SMP7_0            (0x1UL << ADC_SMPR1_SMP7_Pos)  /*!< 0x00200000 */
#define ADC_SMPR1_SMP7_1            (0x2UL << ADC_SMPR1_SMP7_Pos)  /*!< 0x00400000 */
#define ADC_SMPR1_SMP7_2            (0x4UL << ADC_SMPR1_SMP7_Pos)  /*!< 0x00800000 */
#define ADC_SMPR1_SMP8_Pos           (24U)
#define ADC_SMPR1_SMP8_Msk             (0x7UL << ADC_SMPR1_SMP8_Pos)  /*!< 0x07000000 */
#define ADC_SMPR1_SMP8               ADC_SMPR1_SMP8_Msk          /*!< </spirit:description> */
#define ADC_SMPR1_SMP8_0            (0x1UL << ADC_SMPR1_SMP8_Pos)  /*!< 0x01000000 */
#define ADC_SMPR1_SMP8_1            (0x2UL << ADC_SMPR1_SMP8_Pos)  /*!< 0x02000000 */
#define ADC_SMPR1_SMP8_2            (0x4UL << ADC_SMPR1_SMP8_Pos)  /*!< 0x04000000 */
#define ADC_SMPR1_SMP9_Pos           (27U)
#define ADC_SMPR1_SMP9_Msk             (0x7UL << ADC_SMPR1_SMP9_Pos)  /*!< 0x38000000 */
#define ADC_SMPR1_SMP9               ADC_SMPR1_SMP9_Msk          /*!< </spirit:description> */
#define ADC_SMPR1_SMP9_0            (0x1UL << ADC_SMPR1_SMP9_Pos)  /*!< 0x08000000 */
#define ADC_SMPR1_SMP9_1            (0x2UL << ADC_SMPR1_SMP9_Pos)  /*!< 0x10000000 */
#define ADC_SMPR1_SMP9_2            (0x4UL << ADC_SMPR1_SMP9_Pos)  /*!< 0x20000000 */
#define ADC_SMPR1_SMPPLUS_Pos        (31U)
#define ADC_SMPR1_SMPPLUS_Msk        (0x1UL << ADC_SMPR1_SMPPLUS_Pos)   /*!< 0x80000000 */
#define ADC_SMPR1_SMPPLUS            ADC_SMPR1_SMPPLUS_Msk       /*!< </spirit:description> */

/******************  Bit definition for ADC_SMPR2 register  *******************/
#define ADC_SMPR2_SMP10_Pos          (0U)
#define ADC_SMPR2_SMP10_Msk          (0x7UL << ADC_SMPR2_SMP10_Pos) /*!< 0x00000007 */
#define ADC_SMPR2_SMP10              ADC_SMPR2_SMP10_Msk         /*!< </spirit:description> */
#define ADC_SMPR2_SMP10_0           (0x1UL << ADC_SMPR2_SMP10_Pos)   /*!< 0x00000001 */
#define ADC_SMPR2_SMP10_1           (0x2UL << ADC_SMPR2_SMP10_Pos)   /*!< 0x00000002 */
#define ADC_SMPR2_SMP10_2           (0x4UL << ADC_SMPR2_SMP10_Pos)   /*!< 0x00000004 */
#define ADC_SMPR2_SMP11_Pos          (3U)
#define ADC_SMPR2_SMP11_Msk          (0x7UL << ADC_SMPR2_SMP11_Pos) /*!< 0x00000038 */
#define ADC_SMPR2_SMP11              ADC_SMPR2_SMP11_Msk         /*!< </spirit:description> */
#define ADC_SMPR2_SMP11_0           (0x1UL << ADC_SMPR2_SMP11_Pos)   /*!< 0x00000008 */
#define ADC_SMPR2_SMP11_1           (0x2UL << ADC_SMPR2_SMP11_Pos)   /*!< 0x00000010 */
#define ADC_SMPR2_SMP11_2           (0x4UL << ADC_SMPR2_SMP11_Pos)   /*!< 0x00000020 */
#define ADC_SMPR2_SMP12_Pos          (6U)
#define ADC_SMPR2_SMP12_Msk          (0x7UL << ADC_SMPR2_SMP12_Pos) /*!< 0x000001C0 */
#define ADC_SMPR2_SMP12              ADC_SMPR2_SMP12_Msk         /*!< </spirit:description> */
#define ADC_SMPR2_SMP12_0           (0x1UL << ADC_SMPR2_SMP12_Pos)   /*!< 0x00000040 */
#define ADC_SMPR2_SMP12_1           (0x2UL << ADC_SMPR2_SMP12_Pos)   /*!< 0x00000080 */
#define ADC_SMPR2_SMP12_2           (0x4UL << ADC_SMPR2_SMP12_Pos)   /*!< 0x00000100 */
#define ADC_SMPR2_SMP13_Pos          (9U)
#define ADC_SMPR2_SMP13_Msk          (0x7UL << ADC_SMPR2_SMP13_Pos) /*!< 0x00000E00 */
#define ADC_SMPR2_SMP13              ADC_SMPR2_SMP13_Msk         /*!< </spirit:description> */
#define ADC_SMPR2_SMP13_0           (0x1UL << ADC_SMPR2_SMP13_Pos)   /*!< 0x00000200 */
#define ADC_SMPR2_SMP13_1           (0x2UL << ADC_SMPR2_SMP13_Pos)   /*!< 0x00000400 */
#define ADC_SMPR2_SMP13_2           (0x4UL << ADC_SMPR2_SMP13_Pos)   /*!< 0x00000800 */
#define ADC_SMPR2_SMP14_Pos          (12U)
#define ADC_SMPR2_SMP14_Msk          (0x7UL << ADC_SMPR2_SMP14_Pos) /*!< 0x00007000 */
#define ADC_SMPR2_SMP14              ADC_SMPR2_SMP14_Msk         /*!< </spirit:description> */
#define ADC_SMPR2_SMP14_0           (0x1UL << ADC_SMPR2_SMP14_Pos)   /*!< 0x00001000 */
#define ADC_SMPR2_SMP14_1           (0x2UL << ADC_SMPR2_SMP14_Pos)   /*!< 0x00002000 */
#define ADC_SMPR2_SMP14_2           (0x4UL << ADC_SMPR2_SMP14_Pos)   /*!< 0x00004000 */
#define ADC_SMPR2_SMP15_Pos          (15U)
#define ADC_SMPR2_SMP15_Msk          (0x7UL << ADC_SMPR2_SMP15_Pos) /*!< 0x00038000 */
#define ADC_SMPR2_SMP15              ADC_SMPR2_SMP15_Msk         /*!< </spirit:description> */
#define ADC_SMPR2_SMP15_0           (0x1UL << ADC_SMPR2_SMP15_Pos)   /*!< 0x00008000 */
#define ADC_SMPR2_SMP15_1           (0x2UL << ADC_SMPR2_SMP15_Pos)   /*!< 0x00010000 */
#define ADC_SMPR2_SMP15_2           (0x4UL << ADC_SMPR2_SMP15_Pos)   /*!< 0x00020000 */
#define ADC_SMPR2_SMP16_Pos          (18U)
#define ADC_SMPR2_SMP16_Msk          (0x7UL << ADC_SMPR2_SMP16_Pos) /*!< 0x001C0000 */
#define ADC_SMPR2_SMP16              ADC_SMPR2_SMP16_Msk         /*!< </spirit:description> */
#define ADC_SMPR2_SMP16_0           (0x1UL << ADC_SMPR2_SMP16_Pos)   /*!< 0x00040000 */
#define ADC_SMPR2_SMP16_1           (0x2UL << ADC_SMPR2_SMP16_Pos)   /*!< 0x00080000 */
#define ADC_SMPR2_SMP16_2           (0x4UL << ADC_SMPR2_SMP16_Pos)   /*!< 0x00100000 */
#define ADC_SMPR2_SMP17_Pos          (21U)
#define ADC_SMPR2_SMP17_Msk          (0x7UL << ADC_SMPR2_SMP17_Pos) /*!< 0x00E00000 */
#define ADC_SMPR2_SMP17              ADC_SMPR2_SMP17_Msk         /*!< </spirit:description> */
#define ADC_SMPR2_SMP17_0           (0x1UL << ADC_SMPR2_SMP17_Pos)   /*!< 0x00200000 */
#define ADC_SMPR2_SMP17_1           (0x2UL << ADC_SMPR2_SMP17_Pos)   /*!< 0x00400000 */
#define ADC_SMPR2_SMP17_2           (0x4UL << ADC_SMPR2_SMP17_Pos)   /*!< 0x00800000 */
#define ADC_SMPR2_SMP18_Pos          (24U)
#define ADC_SMPR2_SMP18_Msk          (0x7UL << ADC_SMPR2_SMP18_Pos) /*!< 0x07000000 */
#define ADC_SMPR2_SMP18              ADC_SMPR2_SMP18_Msk         /*!< </spirit:description> */
#define ADC_SMPR2_SMP18_0           (0x1UL << ADC_SMPR2_SMP18_Pos)   /*!< 0x01000000 */
#define ADC_SMPR2_SMP18_1           (0x2UL << ADC_SMPR2_SMP18_Pos)   /*!< 0x02000000 */
#define ADC_SMPR2_SMP18_2           (0x4UL << ADC_SMPR2_SMP18_Pos)   /*!< 0x04000000 */

/*******************  Bit definition for ADC_TR1 register  ********************/
#define ADC_TR1_LT1_Pos              (0U)
#define ADC_TR1_LT1_Msk              (0xFFFUL << ADC_TR1_LT1_Pos) /*!< 0x00000FFF */
#define ADC_TR1_LT1                  ADC_TR1_LT1_Msk             /*!< </spirit:description> */
#define ADC_TR1_AWDFILT_Pos          (12U)
#define ADC_TR1_AWDFILT_Msk          (0x7UL << ADC_TR1_AWDFILT_Pos) /*!< 0x00007000 */
#define ADC_TR1_AWDFILT              ADC_TR1_AWDFILT_Msk         /*!< </spirit:description> */
#define ADC_TR1_AWDFILT_0           (0x1UL << ADC_TR1_AWDFILT_Pos)   /*!< 0x00001000 */
#define ADC_TR1_AWDFILT_1           (0x2UL << ADC_TR1_AWDFILT_Pos)   /*!< 0x00002000 */
#define ADC_TR1_AWDFILT_2           (0x4UL << ADC_TR1_AWDFILT_Pos)   /*!< 0x00004000 */
#define ADC_TR1_HT1_Pos              (16U)
#define ADC_TR1_HT1_Msk              (0xFFFUL << ADC_TR1_HT1_Pos) /*!< 0x0FFF0000 */
#define ADC_TR1_HT1                  ADC_TR1_HT1_Msk             /*!< </spirit:description> */

/*******************  Bit definition for ADC_TR2 register  ********************/
#define ADC_TR2_LT2_Pos              (0U)
#define ADC_TR2_LT2_Msk              (0xFFUL << ADC_TR2_LT2_Pos)  /*!< 0x000000FF */
#define ADC_TR2_LT2                  ADC_TR2_LT2_Msk             /*!< </spirit:description> */
#define ADC_TR2_HT2_Pos              (16U)
#define ADC_TR2_HT2_Msk              (0xFFUL << ADC_TR2_HT2_Pos)  /*!< 0x00FF0000 */
#define ADC_TR2_HT2                  ADC_TR2_HT2_Msk             /*!< </spirit:description> */

/*******************  Bit definition for ADC_TR3 register  ********************/
#define ADC_TR3_LT3_Pos              (0U)
#define ADC_TR3_LT3_Msk              (0xFFUL << ADC_TR3_LT3_Pos)  /*!< 0x000000FF */
#define ADC_TR3_LT3                  ADC_TR3_LT3_Msk             /*!< </spirit:description> */
#define ADC_TR3_HT3_Pos              (16U)
#define ADC_TR3_HT3_Msk              (0xFFUL << ADC_TR3_HT3_Pos)  /*!< 0x00FF0000 */
#define ADC_TR3_HT3                  ADC_TR3_HT3_Msk             /*!< </spirit:description> */

/*******************  Bit definition for ADC_SQR1 register  *******************/
#define ADC_SQR1_L_Pos               (0U)
#define ADC_SQR1_L_Msk               (0xFUL << ADC_SQR1_L_Pos)    /*!< 0x0000000F */
#define ADC_SQR1_L                   ADC_SQR1_L_Msk              /*!< </spirit:description> */
#define ADC_SQR1_L_0                (0x1UL << ADC_SQR1_L_Pos)    /*!< 0x00000001 */
#define ADC_SQR1_L_1                (0x2UL << ADC_SQR1_L_Pos)    /*!< 0x00000002 */
#define ADC_SQR1_L_2                (0x4UL << ADC_SQR1_L_Pos)    /*!< 0x00000004 */
#define ADC_SQR1_L_3                (0x8UL << ADC_SQR1_L_Pos)    /*!< 0x00000008 */
#define ADC_SQR1_SQ1_Pos             (6U)
#define ADC_SQR1_SQ1_Msk             (0x1FUL << ADC_SQR1_SQ1_Pos) /*!< 0x000007C0 */
#define ADC_SQR1_SQ1                 ADC_SQR1_SQ1_Msk            /*!< </spirit:description> */
#define ADC_SQR1_SQ1_0              (0x1UL << ADC_SQR1_SQ1_Pos) /*!< 0x00000040 */
#define ADC_SQR1_SQ1_1              (0x2UL << ADC_SQR1_SQ1_Pos) /*!< 0x00000080 */
#define ADC_SQR1_SQ1_2              (0x4UL << ADC_SQR1_SQ1_Pos) /*!< 0x00000100 */
#define ADC_SQR1_SQ1_3              (0x8UL << ADC_SQR1_SQ1_Pos) /*!< 0x00000200 */
#define ADC_SQR1_SQ1_4              (0x10UL << ADC_SQR1_SQ1_Pos) /*!< 0x00000400 */
#define ADC_SQR1_SQ2_Pos             (12U)
#define ADC_SQR1_SQ2_Msk             (0x1FUL << ADC_SQR1_SQ2_Pos) /*!< 0x0001F000 */
#define ADC_SQR1_SQ2                 ADC_SQR1_SQ2_Msk            /*!< </spirit:description> */
#define ADC_SQR1_SQ2_0              (0x1UL << ADC_SQR1_SQ2_Pos) /*!< 0x00001000 */
#define ADC_SQR1_SQ2_1              (0x2UL << ADC_SQR1_SQ2_Pos) /*!< 0x00002000 */
#define ADC_SQR1_SQ2_2              (0x4UL << ADC_SQR1_SQ2_Pos) /*!< 0x00004000 */
#define ADC_SQR1_SQ2_3              (0x8UL << ADC_SQR1_SQ2_Pos) /*!< 0x00008000 */
#define ADC_SQR1_SQ2_4              (0x10UL << ADC_SQR1_SQ2_Pos) /*!< 0x00010000 */
#define ADC_SQR1_SQ3_Pos             (18U)
#define ADC_SQR1_SQ3_Msk             (0x1FUL << ADC_SQR1_SQ3_Pos) /*!< 0x007C0000 */
#define ADC_SQR1_SQ3                 ADC_SQR1_SQ3_Msk            /*!< </spirit:description> */
#define ADC_SQR1_SQ3_0              (0x1UL << ADC_SQR1_SQ3_Pos) /*!< 0x00040000 */
#define ADC_SQR1_SQ3_1              (0x2UL << ADC_SQR1_SQ3_Pos) /*!< 0x00080000 */
#define ADC_SQR1_SQ3_2              (0x4UL << ADC_SQR1_SQ3_Pos) /*!< 0x00100000 */
#define ADC_SQR1_SQ3_3              (0x8UL << ADC_SQR1_SQ3_Pos) /*!< 0x00200000 */
#define ADC_SQR1_SQ3_4              (0x10UL << ADC_SQR1_SQ3_Pos) /*!< 0x00400000 */
#define ADC_SQR1_SQ4_Pos             (24U)
#define ADC_SQR1_SQ4_Msk             (0x1FUL << ADC_SQR1_SQ4_Pos) /*!< 0x1F000000 */
#define ADC_SQR1_SQ4                 ADC_SQR1_SQ4_Msk            /*!< </spirit:description> */
#define ADC_SQR1_SQ4_0              (0x1UL << ADC_SQR1_SQ4_Pos) /*!< 0x01000000 */
#define ADC_SQR1_SQ4_1              (0x2UL << ADC_SQR1_SQ4_Pos) /*!< 0x02000000 */
#define ADC_SQR1_SQ4_2              (0x4UL << ADC_SQR1_SQ4_Pos) /*!< 0x04000000 */
#define ADC_SQR1_SQ4_3              (0x8UL << ADC_SQR1_SQ4_Pos) /*!< 0x08000000 */
#define ADC_SQR1_SQ4_4              (0x10UL << ADC_SQR1_SQ4_Pos) /*!< 0x10000000 */

/*******************  Bit definition for ADC_SQR2 register  *******************/
#define ADC_SQR2_SQ5_Pos             (0U)
#define ADC_SQR2_SQ5_Msk             (0x1FUL << ADC_SQR2_SQ5_Pos) /*!< 0x0000001F */
#define ADC_SQR2_SQ5                 ADC_SQR2_SQ5_Msk            /*!< </spirit:description> */
#define ADC_SQR2_SQ5_0              (0x1UL << ADC_SQR2_SQ5_Pos) /*!< 0x00000001 */
#define ADC_SQR2_SQ5_1              (0x2UL << ADC_SQR2_SQ5_Pos) /*!< 0x00000002 */
#define ADC_SQR2_SQ5_2              (0x4UL << ADC_SQR2_SQ5_Pos) /*!< 0x00000004 */
#define ADC_SQR2_SQ5_3              (0x8UL << ADC_SQR2_SQ5_Pos) /*!< 0x00000008 */
#define ADC_SQR2_SQ5_4              (0x10UL << ADC_SQR2_SQ5_Pos) /*!< 0x00000010 */
#define ADC_SQR2_SQ6_Pos             (6U)
#define ADC_SQR2_SQ6_Msk             (0x1FUL << ADC_SQR2_SQ6_Pos) /*!< 0x000007C0 */
#define ADC_SQR2_SQ6                 ADC_SQR2_SQ6_Msk            /*!< </spirit:description> */
#define ADC_SQR2_SQ6_0              (0x1UL << ADC_SQR2_SQ6_Pos) /*!< 0x00000040 */
#define ADC_SQR2_SQ6_1              (0x2UL << ADC_SQR2_SQ6_Pos) /*!< 0x00000080 */
#define ADC_SQR2_SQ6_2              (0x4UL << ADC_SQR2_SQ6_Pos) /*!< 0x00000100 */
#define ADC_SQR2_SQ6_3              (0x8UL << ADC_SQR2_SQ6_Pos) /*!< 0x00000200 */
#define ADC_SQR2_SQ6_4              (0x10UL << ADC_SQR2_SQ6_Pos) /*!< 0x00000400 */
#define ADC_SQR2_SQ7_Pos             (12U)
#define ADC_SQR2_SQ7_Msk             (0x1FUL << ADC_SQR2_SQ7_Pos) /*!< 0x0001F000 */
#define ADC_SQR2_SQ7                 ADC_SQR2_SQ7_Msk            /*!< </spirit:description> */
#define ADC_SQR2_SQ7_0              (0x1UL << ADC_SQR2_SQ7_Pos) /*!< 0x00001000 */
#define ADC_SQR2_SQ7_1              (0x2UL << ADC_SQR2_SQ7_Pos) /*!< 0x00002000 */
#define ADC_SQR2_SQ7_2              (0x4UL << ADC_SQR2_SQ7_Pos) /*!< 0x00004000 */
#define ADC_SQR2_SQ7_3              (0x8UL << ADC_SQR2_SQ7_Pos) /*!< 0x00008000 */
#define ADC_SQR2_SQ7_4              (0x10UL << ADC_SQR2_SQ7_Pos) /*!< 0x00010000 */
#define ADC_SQR2_SQ8_Pos             (18U)
#define ADC_SQR2_SQ8_Msk             (0x1FUL << ADC_SQR2_SQ8_Pos) /*!< 0x007C0000 */
#define ADC_SQR2_SQ8                 ADC_SQR2_SQ8_Msk            /*!< </spirit:description> */
#define ADC_SQR2_SQ8_0              (0x1UL << ADC_SQR2_SQ8_Pos) /*!< 0x00040000 */
#define ADC_SQR2_SQ8_1              (0x2UL << ADC_SQR2_SQ8_Pos) /*!< 0x00080000 */
#define ADC_SQR2_SQ8_2              (0x4UL << ADC_SQR2_SQ8_Pos) /*!< 0x00100000 */
#define ADC_SQR2_SQ8_3              (0x8UL << ADC_SQR2_SQ8_Pos) /*!< 0x00200000 */
#define ADC_SQR2_SQ8_4              (0x10UL << ADC_SQR2_SQ8_Pos) /*!< 0x00400000 */
#define ADC_SQR2_SQ9_Pos             (24U)
#define ADC_SQR2_SQ9_Msk             (0x1FUL << ADC_SQR2_SQ9_Pos) /*!< 0x1F000000 */
#define ADC_SQR2_SQ9                 ADC_SQR2_SQ9_Msk            /*!< </spirit:description> */
#define ADC_SQR2_SQ9_0              (0x1UL << ADC_SQR2_SQ9_Pos) /*!< 0x01000000 */
#define ADC_SQR2_SQ9_1              (0x2UL << ADC_SQR2_SQ9_Pos) /*!< 0x02000000 */
#define ADC_SQR2_SQ9_2              (0x4UL << ADC_SQR2_SQ9_Pos) /*!< 0x04000000 */
#define ADC_SQR2_SQ9_3              (0x8UL << ADC_SQR2_SQ9_Pos) /*!< 0x08000000 */
#define ADC_SQR2_SQ9_4              (0x10UL << ADC_SQR2_SQ9_Pos) /*!< 0x10000000 */

/*******************  Bit definition for ADC_SQR3 register  *******************/
#define ADC_SQR3_SQ10_Pos            (0U)
#define ADC_SQR3_SQ10_Msk              (0x1FUL << ADC_SQR3_SQ10_Pos)  /*!< 0x0000001F */
#define ADC_SQR3_SQ10                ADC_SQR3_SQ10_Msk           /*!< </spirit:description> */
#define ADC_SQR3_SQ10_0             (0x1UL << ADC_SQR3_SQ10_Pos)  /*!< 0x00000001 */
#define ADC_SQR3_SQ10_1             (0x2UL << ADC_SQR3_SQ10_Pos)  /*!< 0x00000002 */
#define ADC_SQR3_SQ10_2             (0x4UL << ADC_SQR3_SQ10_Pos)  /*!< 0x00000004 */
#define ADC_SQR3_SQ10_3             (0x8UL << ADC_SQR3_SQ10_Pos)  /*!< 0x00000008 */
#define ADC_SQR3_SQ10_4             (0x10UL << ADC_SQR3_SQ10_Pos)  /*!< 0x00000010 */
#define ADC_SQR3_SQ11_Pos            (6U)
#define ADC_SQR3_SQ11_Msk              (0x1FUL << ADC_SQR3_SQ11_Pos)  /*!< 0x000007C0 */
#define ADC_SQR3_SQ11                ADC_SQR3_SQ11_Msk           /*!< </spirit:description> */
#define ADC_SQR3_SQ11_0             (0x1UL << ADC_SQR3_SQ11_Pos)  /*!< 0x00000040 */
#define ADC_SQR3_SQ11_1             (0x2UL << ADC_SQR3_SQ11_Pos)  /*!< 0x00000080 */
#define ADC_SQR3_SQ11_2             (0x4UL << ADC_SQR3_SQ11_Pos)  /*!< 0x00000100 */
#define ADC_SQR3_SQ11_3             (0x8UL << ADC_SQR3_SQ11_Pos)  /*!< 0x00000200 */
#define ADC_SQR3_SQ11_4             (0x10UL << ADC_SQR3_SQ11_Pos)  /*!< 0x00000400 */
#define ADC_SQR3_SQ12_Pos            (12U)
#define ADC_SQR3_SQ12_Msk              (0x1FUL << ADC_SQR3_SQ12_Pos)  /*!< 0x0001F000 */
#define ADC_SQR3_SQ12                ADC_SQR3_SQ12_Msk           /*!< </spirit:description> */
#define ADC_SQR3_SQ12_0             (0x1UL << ADC_SQR3_SQ12_Pos)  /*!< 0x00001000 */
#define ADC_SQR3_SQ12_1             (0x2UL << ADC_SQR3_SQ12_Pos)  /*!< 0x00002000 */
#define ADC_SQR3_SQ12_2             (0x4UL << ADC_SQR3_SQ12_Pos)  /*!< 0x00004000 */
#define ADC_SQR3_SQ12_3             (0x8UL << ADC_SQR3_SQ12_Pos)  /*!< 0x00008000 */
#define ADC_SQR3_SQ12_4             (0x10UL << ADC_SQR3_SQ12_Pos)  /*!< 0x00010000 */
#define ADC_SQR3_SQ13_Pos            (18U)
#define ADC_SQR3_SQ13_Msk              (0x1FUL << ADC_SQR3_SQ13_Pos)  /*!< 0x007C0000 */
#define ADC_SQR3_SQ13                ADC_SQR3_SQ13_Msk           /*!< </spirit:description> */
#define ADC_SQR3_SQ13_0             (0x1UL << ADC_SQR3_SQ13_Pos)  /*!< 0x00040000 */
#define ADC_SQR3_SQ13_1             (0x2UL << ADC_SQR3_SQ13_Pos)  /*!< 0x00080000 */
#define ADC_SQR3_SQ13_2             (0x4UL << ADC_SQR3_SQ13_Pos)  /*!< 0x00100000 */
#define ADC_SQR3_SQ13_3             (0x8UL << ADC_SQR3_SQ13_Pos)  /*!< 0x00200000 */
#define ADC_SQR3_SQ13_4             (0x10UL << ADC_SQR3_SQ13_Pos)  /*!< 0x00400000 */
#define ADC_SQR3_SQ14_Pos            (24U)
#define ADC_SQR3_SQ14_Msk              (0x1FUL << ADC_SQR3_SQ14_Pos)  /*!< 0x1F000000 */
#define ADC_SQR3_SQ14                ADC_SQR3_SQ14_Msk           /*!< </spirit:description> */
#define ADC_SQR3_SQ14_0             (0x1UL << ADC_SQR3_SQ14_Pos)  /*!< 0x01000000 */
#define ADC_SQR3_SQ14_1             (0x2UL << ADC_SQR3_SQ14_Pos)  /*!< 0x02000000 */
#define ADC_SQR3_SQ14_2             (0x4UL << ADC_SQR3_SQ14_Pos)  /*!< 0x04000000 */
#define ADC_SQR3_SQ14_3             (0x8UL << ADC_SQR3_SQ14_Pos)  /*!< 0x08000000 */
#define ADC_SQR3_SQ14_4             (0x10UL << ADC_SQR3_SQ14_Pos)  /*!< 0x10000000 */

/*******************  Bit definition for ADC_SQR4 register  *******************/
#define ADC_SQR4_SQ15_Pos            (0U)
#define ADC_SQR4_SQ15_Msk              (0x1FUL << ADC_SQR4_SQ15_Pos)  /*!< 0x0000001F */
#define ADC_SQR4_SQ15                ADC_SQR4_SQ15_Msk           /*!< </spirit:description> */
#define ADC_SQR4_SQ15_0             (0x1UL << ADC_SQR4_SQ15_Pos)  /*!< 0x00000001 */
#define ADC_SQR4_SQ15_1             (0x2UL << ADC_SQR4_SQ15_Pos)  /*!< 0x00000002 */
#define ADC_SQR4_SQ15_2             (0x4UL << ADC_SQR4_SQ15_Pos)  /*!< 0x00000004 */
#define ADC_SQR4_SQ15_3             (0x8UL << ADC_SQR4_SQ15_Pos)  /*!< 0x00000008 */
#define ADC_SQR4_SQ15_4             (0x10UL << ADC_SQR4_SQ15_Pos)  /*!< 0x00000010 */
#define ADC_SQR4_SQ16_Pos            (6U)
#define ADC_SQR4_SQ16_Msk              (0x1FUL << ADC_SQR4_SQ16_Pos)  /*!< 0x000007C0 */
#define ADC_SQR4_SQ16                ADC_SQR4_SQ16_Msk           /*!< </spirit:description> */
#define ADC_SQR4_SQ16_0             (0x1UL << ADC_SQR4_SQ16_Pos)  /*!< 0x00000040 */
#define ADC_SQR4_SQ16_1             (0x2UL << ADC_SQR4_SQ16_Pos)  /*!< 0x00000080 */
#define ADC_SQR4_SQ16_2             (0x4UL << ADC_SQR4_SQ16_Pos)  /*!< 0x00000100 */
#define ADC_SQR4_SQ16_3             (0x8UL << ADC_SQR4_SQ16_Pos)  /*!< 0x00000200 */
#define ADC_SQR4_SQ16_4             (0x10UL << ADC_SQR4_SQ16_Pos)  /*!< 0x00000400 */

/********************  Bit definition for ADC_DR register  ********************/
#define ADC_DR_RDATA_Pos             (0U)
#define ADC_DR_RDATA_Msk             (0xFFFFFFFFUL << ADC_DR_RDATA_Pos)     /*!< 0xFFFFFFFF */
#define ADC_DR_RDATA                 ADC_DR_RDATA_Msk            /*!< </spirit:description> */

/*******************  Bit definition for ADC_JSQR register  *******************/
#define ADC_JSQR_JL_Pos              (0U)
#define ADC_JSQR_JL_Msk              (0x3UL << ADC_JSQR_JL_Pos)   /*!< 0x00000003 */
#define ADC_JSQR_JL                  ADC_JSQR_JL_Msk             /*!< </spirit:description> */
#define ADC_JSQR_JL_0               (0x1UL << ADC_JSQR_JL_Pos)   /*!< 0x00000001 */
#define ADC_JSQR_JL_1               (0x2UL << ADC_JSQR_JL_Pos)   /*!< 0x00000002 */
#define ADC_JSQR_JEXTSEL_Pos         (2U)
#define ADC_JSQR_JEXTSEL_Msk         (0x1FUL << ADC_JSQR_JEXTSEL_Pos)   /*!< 0x0000007C */
#define ADC_JSQR_JEXTSEL             ADC_JSQR_JEXTSEL_Msk        /*!< </spirit:description> */
#define ADC_JSQR_JEXTSEL_0          (0x1UL << ADC_JSQR_JEXTSEL_Pos)     /*!< 0x00000004 */
#define ADC_JSQR_JEXTSEL_1          (0x2UL << ADC_JSQR_JEXTSEL_Pos)     /*!< 0x00000008 */
#define ADC_JSQR_JEXTSEL_2          (0x4UL << ADC_JSQR_JEXTSEL_Pos)     /*!< 0x00000010 */
#define ADC_JSQR_JEXTSEL_3          (0x8UL << ADC_JSQR_JEXTSEL_Pos)     /*!< 0x00000020 */
#define ADC_JSQR_JEXTSEL_4          (0x10UL << ADC_JSQR_JEXTSEL_Pos)     /*!< 0x00000040 */
#define ADC_JSQR_JEXTEN_Pos          (7U)
#define ADC_JSQR_JEXTEN_Msk          (0x3UL << ADC_JSQR_JEXTEN_Pos) /*!< 0x00000180 */
#define ADC_JSQR_JEXTEN              ADC_JSQR_JEXTEN_Msk         /*!< </spirit:description> */
#define ADC_JSQR_JEXTEN_0           (0x1UL << ADC_JSQR_JEXTEN_Pos)   /*!< 0x00000080 */
#define ADC_JSQR_JEXTEN_1           (0x2UL << ADC_JSQR_JEXTEN_Pos)   /*!< 0x00000100 */
#define ADC_JSQR_JSQ1_Pos            (9U)
#define ADC_JSQR_JSQ1_Msk              (0x1FUL << ADC_JSQR_JSQ1_Pos)  /*!< 0x00003E00 */
#define ADC_JSQR_JSQ1                ADC_JSQR_JSQ1_Msk           /*!< </spirit:description> */
#define ADC_JSQR_JSQ1_0             (0x1UL << ADC_JSQR_JSQ1_Pos)  /*!< 0x00000200 */
#define ADC_JSQR_JSQ1_1             (0x2UL << ADC_JSQR_JSQ1_Pos)  /*!< 0x00000400 */
#define ADC_JSQR_JSQ1_2             (0x4UL << ADC_JSQR_JSQ1_Pos)  /*!< 0x00000800 */
#define ADC_JSQR_JSQ1_3             (0x8UL << ADC_JSQR_JSQ1_Pos)  /*!< 0x00001000 */
#define ADC_JSQR_JSQ1_4             (0x10UL << ADC_JSQR_JSQ1_Pos)  /*!< 0x00002000 */
#define ADC_JSQR_JSQ2_Pos            (15U)
#define ADC_JSQR_JSQ2_Msk              (0x1FUL << ADC_JSQR_JSQ2_Pos)  /*!< 0x000F8000 */
#define ADC_JSQR_JSQ2                ADC_JSQR_JSQ2_Msk           /*!< </spirit:description> */
#define ADC_JSQR_JSQ2_0             (0x1UL << ADC_JSQR_JSQ2_Pos)  /*!< 0x00008000 */
#define ADC_JSQR_JSQ2_1             (0x2UL << ADC_JSQR_JSQ2_Pos)  /*!< 0x00010000 */
#define ADC_JSQR_JSQ2_2             (0x4UL << ADC_JSQR_JSQ2_Pos)  /*!< 0x00020000 */
#define ADC_JSQR_JSQ2_3             (0x8UL << ADC_JSQR_JSQ2_Pos)  /*!< 0x00040000 */
#define ADC_JSQR_JSQ2_4             (0x10UL << ADC_JSQR_JSQ2_Pos)  /*!< 0x00080000 */
#define ADC_JSQR_JSQ3_Pos            (21U)
#define ADC_JSQR_JSQ3_Msk              (0x1FUL << ADC_JSQR_JSQ3_Pos)  /*!< 0x03E00000 */
#define ADC_JSQR_JSQ3                ADC_JSQR_JSQ3_Msk           /*!< </spirit:description> */
#define ADC_JSQR_JSQ3_0             (0x1UL << ADC_JSQR_JSQ3_Pos)  /*!< 0x00200000 */
#define ADC_JSQR_JSQ3_1             (0x2UL << ADC_JSQR_JSQ3_Pos)  /*!< 0x00400000 */
#define ADC_JSQR_JSQ3_2             (0x4UL << ADC_JSQR_JSQ3_Pos)  /*!< 0x00800000 */
#define ADC_JSQR_JSQ3_3             (0x8UL << ADC_JSQR_JSQ3_Pos)  /*!< 0x01000000 */
#define ADC_JSQR_JSQ3_4             (0x10UL << ADC_JSQR_JSQ3_Pos)  /*!< 0x02000000 */
#define ADC_JSQR_JSQ4_Pos            (27U)
#define ADC_JSQR_JSQ4_Msk              (0x1FUL << ADC_JSQR_JSQ4_Pos)  /*!< 0xF8000000 */
#define ADC_JSQR_JSQ4                ADC_JSQR_JSQ4_Msk           /*!< </spirit:description> */
#define ADC_JSQR_JSQ4_0             (0x1UL << ADC_JSQR_JSQ4_Pos)  /*!< 0x08000000 */
#define ADC_JSQR_JSQ4_1             (0x2UL << ADC_JSQR_JSQ4_Pos)  /*!< 0x10000000 */
#define ADC_JSQR_JSQ4_2             (0x4UL << ADC_JSQR_JSQ4_Pos)  /*!< 0x20000000 */
#define ADC_JSQR_JSQ4_3             (0x8UL << ADC_JSQR_JSQ4_Pos)  /*!< 0x40000000 */
#define ADC_JSQR_JSQ4_4             (0x10UL << ADC_JSQR_JSQ4_Pos)  /*!< 0x80000000 */

/*******************  Bit definition for ADC_OFR1 register  *******************/
#define ADC_OFR1_OFFSET1_Pos         (0U)
#define ADC_OFR1_OFFSET1_Msk         (0xFFFUL << ADC_OFR1_OFFSET1_Pos)    /*!< 0x00000FFF */
#define ADC_OFR1_OFFSET1             ADC_OFR1_OFFSET1_Msk        /*!< </spirit:description> */
#define ADC_OFR1_OFFSET1_0          (0x1UL << ADC_OFR1_OFFSET1_Pos)      /*!< 0x00000001 */
#define ADC_OFR1_OFFSET1_1          (0x2UL << ADC_OFR1_OFFSET1_Pos)      /*!< 0x00000002 */
#define ADC_OFR1_OFFSET1_2          (0x4UL << ADC_OFR1_OFFSET1_Pos)      /*!< 0x00000004 */
#define ADC_OFR1_OFFSET1_3          (0x8UL << ADC_OFR1_OFFSET1_Pos)      /*!< 0x00000008 */
#define ADC_OFR1_OFFSET1_4          (0x10UL << ADC_OFR1_OFFSET1_Pos)      /*!< 0x00000010 */
#define ADC_OFR1_OFFSET1_5          (0x20UL << ADC_OFR1_OFFSET1_Pos)      /*!< 0x00000020 */
#define ADC_OFR1_OFFSET1_6          (0x40UL << ADC_OFR1_OFFSET1_Pos)      /*!< 0x00000040 */
#define ADC_OFR1_OFFSET1_7          (0x80UL << ADC_OFR1_OFFSET1_Pos)      /*!< 0x00000080 */
#define ADC_OFR1_OFFSET1_8          (0x100UL << ADC_OFR1_OFFSET1_Pos)      /*!< 0x00000100 */
#define ADC_OFR1_OFFSET1_9          (0x200UL << ADC_OFR1_OFFSET1_Pos)      /*!< 0x00000200 */
#define ADC_OFR1_OFFSET1_10          (0x400UL << ADC_OFR1_OFFSET1_Pos)      /*!< 0x00000400 */
#define ADC_OFR1_OFFSET1_11          (0x800UL << ADC_OFR1_OFFSET1_Pos)      /*!< 0x00000800 */
#define ADC_OFR1_OFFSETPOS_Pos       (24U)
#define ADC_OFR1_OFFSETPOS_Msk       (0x1UL << ADC_OFR1_OFFSETPOS_Pos)    /*!< 0x01000000 */
#define ADC_OFR1_OFFSETPOS           ADC_OFR1_OFFSETPOS_Msk      /*!< </spirit:description> */
#define ADC_OFR1_SATEN_Pos           (25U)
#define ADC_OFR1_SATEN_Msk             (0x1UL << ADC_OFR1_SATEN_Pos)  /*!< 0x02000000 */
#define ADC_OFR1_SATEN               ADC_OFR1_SATEN_Msk          /*!< </spirit:description> */
#define ADC_OFR1_OFFSET1_CH_Pos      (26U)
#define ADC_OFR1_OFFSET1_CH_Msk      (0x1FUL << ADC_OFR1_OFFSET1_CH_Pos)      /*!< 0x7C000000 */
#define ADC_OFR1_OFFSET1_CH          ADC_OFR1_OFFSET1_CH_Msk     /*!< </spirit:description> */
#define ADC_OFR1_OFFSET1_CH_0       (0x1UL << ADC_OFR1_OFFSET1_CH_Pos)        /*!< 0x04000000 */
#define ADC_OFR1_OFFSET1_CH_1       (0x2UL << ADC_OFR1_OFFSET1_CH_Pos)        /*!< 0x08000000 */
#define ADC_OFR1_OFFSET1_CH_2       (0x4UL << ADC_OFR1_OFFSET1_CH_Pos)        /*!< 0x10000000 */
#define ADC_OFR1_OFFSET1_CH_3       (0x8UL << ADC_OFR1_OFFSET1_CH_Pos)        /*!< 0x20000000 */
#define ADC_OFR1_OFFSET1_CH_4       (0x10UL << ADC_OFR1_OFFSET1_CH_Pos)        /*!< 0x40000000 */
#define ADC_OFR1_OFFSET1_EN_Pos      (31U)
#define ADC_OFR1_OFFSET1_EN_Msk      (0x1UL << ADC_OFR1_OFFSET1_EN_Pos)     /*!< 0x80000000 */
#define ADC_OFR1_OFFSET1_EN          ADC_OFR1_OFFSET1_EN_Msk     /*!< </spirit:description> */

/*******************  Bit definition for ADC_OFR2 register  *******************/
#define ADC_OFR2_OFFSET2_Pos         (0U)
#define ADC_OFR2_OFFSET2_Msk         (0xFFFUL << ADC_OFR2_OFFSET2_Pos)    /*!< 0x00000FFF */
#define ADC_OFR2_OFFSET2             ADC_OFR2_OFFSET2_Msk        /*!< </spirit:description> */
#define ADC_OFR2_OFFSET2_0          (0x1UL << ADC_OFR2_OFFSET2_Pos)      /*!< 0x00000001 */
#define ADC_OFR2_OFFSET2_1          (0x2UL << ADC_OFR2_OFFSET2_Pos)      /*!< 0x00000002 */
#define ADC_OFR2_OFFSET2_2          (0x4UL << ADC_OFR2_OFFSET2_Pos)      /*!< 0x00000004 */
#define ADC_OFR2_OFFSET2_3          (0x8UL << ADC_OFR2_OFFSET2_Pos)      /*!< 0x00000008 */
#define ADC_OFR2_OFFSET2_4          (0x10UL << ADC_OFR2_OFFSET2_Pos)      /*!< 0x00000010 */
#define ADC_OFR2_OFFSET2_5          (0x20UL << ADC_OFR2_OFFSET2_Pos)      /*!< 0x00000020 */
#define ADC_OFR2_OFFSET2_6          (0x40UL << ADC_OFR2_OFFSET2_Pos)      /*!< 0x00000040 */
#define ADC_OFR2_OFFSET2_7          (0x80UL << ADC_OFR2_OFFSET2_Pos)      /*!< 0x00000080 */
#define ADC_OFR2_OFFSET2_8          (0x100UL << ADC_OFR2_OFFSET2_Pos)      /*!< 0x00000100 */
#define ADC_OFR2_OFFSET2_9          (0x200UL << ADC_OFR2_OFFSET2_Pos)      /*!< 0x00000200 */
#define ADC_OFR2_OFFSET2_10          (0x400UL << ADC_OFR2_OFFSET2_Pos)      /*!< 0x00000400 */
#define ADC_OFR2_OFFSET2_11          (0x800UL << ADC_OFR2_OFFSET2_Pos)      /*!< 0x00000800 */
#define ADC_OFR2_OFFSETPOS_Pos       (24U)
#define ADC_OFR2_OFFSETPOS_Msk       (0x1UL << ADC_OFR2_OFFSETPOS_Pos)    /*!< 0x01000000 */
#define ADC_OFR2_OFFSETPOS           ADC_OFR2_OFFSETPOS_Msk      /*!< </spirit:description> */
#define ADC_OFR2_SATEN_Pos           (25U)
#define ADC_OFR2_SATEN_Msk             (0x1UL << ADC_OFR2_SATEN_Pos)  /*!< 0x02000000 */
#define ADC_OFR2_SATEN               ADC_OFR2_SATEN_Msk          /*!< </spirit:description> */
#define ADC_OFR2_OFFSET2_CH_Pos      (26U)
#define ADC_OFR2_OFFSET2_CH_Msk      (0x1FUL << ADC_OFR2_OFFSET2_CH_Pos)      /*!< 0x7C000000 */
#define ADC_OFR2_OFFSET2_CH          ADC_OFR2_OFFSET2_CH_Msk     /*!< </spirit:description> */
#define ADC_OFR2_OFFSET2_CH_0       (0x1UL << ADC_OFR2_OFFSET2_CH_Pos)        /*!< 0x04000000 */
#define ADC_OFR2_OFFSET2_CH_1       (0x2UL << ADC_OFR2_OFFSET2_CH_Pos)        /*!< 0x08000000 */
#define ADC_OFR2_OFFSET2_CH_2       (0x4UL << ADC_OFR2_OFFSET2_CH_Pos)        /*!< 0x10000000 */
#define ADC_OFR2_OFFSET2_CH_3       (0x8UL << ADC_OFR2_OFFSET2_CH_Pos)        /*!< 0x20000000 */
#define ADC_OFR2_OFFSET2_CH_4       (0x10UL << ADC_OFR2_OFFSET2_CH_Pos)        /*!< 0x40000000 */
#define ADC_OFR2_OFFSET2_EN_Pos      (31U)
#define ADC_OFR2_OFFSET2_EN_Msk      (0x1UL << ADC_OFR2_OFFSET2_EN_Pos)     /*!< 0x80000000 */
#define ADC_OFR2_OFFSET2_EN          ADC_OFR2_OFFSET2_EN_Msk     /*!< </spirit:description> */

/*******************  Bit definition for ADC_OFR3 register  *******************/
#define ADC_OFR3_OFFSET3_Pos         (0U)
#define ADC_OFR3_OFFSET3_Msk         (0xFFFUL << ADC_OFR3_OFFSET3_Pos)    /*!< 0x00000FFF */
#define ADC_OFR3_OFFSET3             ADC_OFR3_OFFSET3_Msk        /*!< </spirit:description> */
#define ADC_OFR3_OFFSET3_0          (0x1UL << ADC_OFR3_OFFSET3_Pos)      /*!< 0x00000001 */
#define ADC_OFR3_OFFSET3_1          (0x2UL << ADC_OFR3_OFFSET3_Pos)      /*!< 0x00000002 */
#define ADC_OFR3_OFFSET3_2          (0x4UL << ADC_OFR3_OFFSET3_Pos)      /*!< 0x00000004 */
#define ADC_OFR3_OFFSET3_3          (0x8UL << ADC_OFR3_OFFSET3_Pos)      /*!< 0x00000008 */
#define ADC_OFR3_OFFSET3_4          (0x10UL << ADC_OFR3_OFFSET3_Pos)      /*!< 0x00000010 */
#define ADC_OFR3_OFFSET3_5          (0x20UL << ADC_OFR3_OFFSET3_Pos)      /*!< 0x00000020 */
#define ADC_OFR3_OFFSET3_6          (0x40UL << ADC_OFR3_OFFSET3_Pos)      /*!< 0x00000040 */
#define ADC_OFR3_OFFSET3_7          (0x80UL << ADC_OFR3_OFFSET3_Pos)      /*!< 0x00000080 */
#define ADC_OFR3_OFFSET3_8          (0x100UL << ADC_OFR3_OFFSET3_Pos)      /*!< 0x00000100 */
#define ADC_OFR3_OFFSET3_9          (0x200UL << ADC_OFR3_OFFSET3_Pos)      /*!< 0x00000200 */
#define ADC_OFR3_OFFSET3_10          (0x400UL << ADC_OFR3_OFFSET3_Pos)      /*!< 0x00000400 */
#define ADC_OFR3_OFFSET3_11          (0x800UL << ADC_OFR3_OFFSET3_Pos)      /*!< 0x00000800 */
#define ADC_OFR3_OFFSETPOS_Pos       (24U)
#define ADC_OFR3_OFFSETPOS_Msk       (0x1UL << ADC_OFR3_OFFSETPOS_Pos)    /*!< 0x01000000 */
#define ADC_OFR3_OFFSETPOS           ADC_OFR3_OFFSETPOS_Msk      /*!< </spirit:description> */
#define ADC_OFR3_SATEN_Pos           (25U)
#define ADC_OFR3_SATEN_Msk             (0x1UL << ADC_OFR3_SATEN_Pos)  /*!< 0x02000000 */
#define ADC_OFR3_SATEN               ADC_OFR3_SATEN_Msk          /*!< </spirit:description> */
#define ADC_OFR3_OFFSET3_CH_Pos      (26U)
#define ADC_OFR3_OFFSET3_CH_Msk      (0x1FUL << ADC_OFR3_OFFSET3_CH_Pos)      /*!< 0x7C000000 */
#define ADC_OFR3_OFFSET3_CH          ADC_OFR3_OFFSET3_CH_Msk     /*!< </spirit:description> */
#define ADC_OFR3_OFFSET3_CH_0       (0x1UL << ADC_OFR3_OFFSET3_CH_Pos)        /*!< 0x04000000 */
#define ADC_OFR3_OFFSET3_CH_1       (0x2UL << ADC_OFR3_OFFSET3_CH_Pos)        /*!< 0x08000000 */
#define ADC_OFR3_OFFSET3_CH_2       (0x4UL << ADC_OFR3_OFFSET3_CH_Pos)        /*!< 0x10000000 */
#define ADC_OFR3_OFFSET3_CH_3       (0x8UL << ADC_OFR3_OFFSET3_CH_Pos)        /*!< 0x20000000 */
#define ADC_OFR3_OFFSET3_CH_4       (0x10UL << ADC_OFR3_OFFSET3_CH_Pos)        /*!< 0x40000000 */
#define ADC_OFR3_OFFSET3_EN_Pos      (31U)
#define ADC_OFR3_OFFSET3_EN_Msk      (0x1UL << ADC_OFR3_OFFSET3_EN_Pos)     /*!< 0x80000000 */
#define ADC_OFR3_OFFSET3_EN          ADC_OFR3_OFFSET3_EN_Msk     /*!< </spirit:description> */

/*******************  Bit definition for ADC_OFR4 register  *******************/
#define ADC_OFR4_OFFSET4_Pos         (0U)
#define ADC_OFR4_OFFSET4_Msk         (0xFFFUL << ADC_OFR4_OFFSET4_Pos)    /*!< 0x00000FFF */
#define ADC_OFR4_OFFSET4             ADC_OFR4_OFFSET4_Msk        /*!< </spirit:description> */
#define ADC_OFR4_OFFSET4_0          (0x1UL << ADC_OFR4_OFFSET4_Pos)      /*!< 0x00000001 */
#define ADC_OFR4_OFFSET4_1          (0x2UL << ADC_OFR4_OFFSET4_Pos)      /*!< 0x00000002 */
#define ADC_OFR4_OFFSET4_2          (0x4UL << ADC_OFR4_OFFSET4_Pos)      /*!< 0x00000004 */
#define ADC_OFR4_OFFSET4_3          (0x8UL << ADC_OFR4_OFFSET4_Pos)      /*!< 0x00000008 */
#define ADC_OFR4_OFFSET4_4          (0x10UL << ADC_OFR4_OFFSET4_Pos)      /*!< 0x00000010 */
#define ADC_OFR4_OFFSET4_5          (0x20UL << ADC_OFR4_OFFSET4_Pos)      /*!< 0x00000020 */
#define ADC_OFR4_OFFSET4_6          (0x40UL << ADC_OFR4_OFFSET4_Pos)      /*!< 0x00000040 */
#define ADC_OFR4_OFFSET4_7          (0x80UL << ADC_OFR4_OFFSET4_Pos)      /*!< 0x00000080 */
#define ADC_OFR4_OFFSET4_8          (0x100UL << ADC_OFR4_OFFSET4_Pos)      /*!< 0x00000100 */
#define ADC_OFR4_OFFSET4_9          (0x200UL << ADC_OFR4_OFFSET4_Pos)      /*!< 0x00000200 */
#define ADC_OFR4_OFFSET4_10          (0x400UL << ADC_OFR4_OFFSET4_Pos)      /*!< 0x00000400 */
#define ADC_OFR4_OFFSET4_11          (0x800UL << ADC_OFR4_OFFSET4_Pos)      /*!< 0x00000800 */
#define ADC_OFR4_OFFSETPOS_Pos       (24U)
#define ADC_OFR4_OFFSETPOS_Msk       (0x1UL << ADC_OFR4_OFFSETPOS_Pos)    /*!< 0x01000000 */
#define ADC_OFR4_OFFSETPOS           ADC_OFR4_OFFSETPOS_Msk      /*!< </spirit:description> */
#define ADC_OFR4_SATEN_Pos           (25U)
#define ADC_OFR4_SATEN_Msk             (0x1UL << ADC_OFR4_SATEN_Pos)  /*!< 0x02000000 */
#define ADC_OFR4_SATEN               ADC_OFR4_SATEN_Msk          /*!< </spirit:description> */
#define ADC_OFR4_OFFSET4_CH_Pos      (26U)
#define ADC_OFR4_OFFSET4_CH_Msk      (0x1FUL << ADC_OFR4_OFFSET4_CH_Pos)      /*!< 0x7C000000 */
#define ADC_OFR4_OFFSET4_CH          ADC_OFR4_OFFSET4_CH_Msk     /*!< </spirit:description> */
#define ADC_OFR4_OFFSET4_CH_0       (0x1UL << ADC_OFR4_OFFSET4_CH_Pos)        /*!< 0x04000000 */
#define ADC_OFR4_OFFSET4_CH_1       (0x2UL << ADC_OFR4_OFFSET4_CH_Pos)        /*!< 0x08000000 */
#define ADC_OFR4_OFFSET4_CH_2       (0x4UL << ADC_OFR4_OFFSET4_CH_Pos)        /*!< 0x10000000 */
#define ADC_OFR4_OFFSET4_CH_3       (0x8UL << ADC_OFR4_OFFSET4_CH_Pos)        /*!< 0x20000000 */
#define ADC_OFR4_OFFSET4_CH_4       (0x10UL << ADC_OFR4_OFFSET4_CH_Pos)        /*!< 0x40000000 */
#define ADC_OFR4_OFFSET4_EN_Pos      (31U)
#define ADC_OFR4_OFFSET4_EN_Msk      (0x1UL << ADC_OFR4_OFFSET4_EN_Pos)     /*!< 0x80000000 */
#define ADC_OFR4_OFFSET4_EN          ADC_OFR4_OFFSET4_EN_Msk     /*!< </spirit:description> */

/*******************  Bit definition for ADC_JDR1 register  *******************/
#define ADC_JDR1_JDATA_Pos           (0U)
#define ADC_JDR1_JDATA_Msk           (0xFFFFUL << ADC_JDR1_JDATA_Pos)   /*!< 0x0000FFFF */
#define ADC_JDR1_JDATA               ADC_JDR1_JDATA_Msk          /*!< </spirit:description> */
#define ADC_JDR1_JDATA_0            (0x1UL << ADC_JDR1_JDATA_Pos)     /*!< 0x00000001 */
#define ADC_JDR1_JDATA_1            (0x2UL << ADC_JDR1_JDATA_Pos)     /*!< 0x00000002 */
#define ADC_JDR1_JDATA_2            (0x4UL << ADC_JDR1_JDATA_Pos)     /*!< 0x00000004 */
#define ADC_JDR1_JDATA_3            (0x8UL << ADC_JDR1_JDATA_Pos)     /*!< 0x00000008 */
#define ADC_JDR1_JDATA_4            (0x10UL << ADC_JDR1_JDATA_Pos)     /*!< 0x00000010 */
#define ADC_JDR1_JDATA_5            (0x20UL << ADC_JDR1_JDATA_Pos)     /*!< 0x00000020 */
#define ADC_JDR1_JDATA_6            (0x40UL << ADC_JDR1_JDATA_Pos)     /*!< 0x00000040 */
#define ADC_JDR1_JDATA_7            (0x80UL << ADC_JDR1_JDATA_Pos)     /*!< 0x00000080 */
#define ADC_JDR1_JDATA_8            (0x100UL << ADC_JDR1_JDATA_Pos)     /*!< 0x00000100 */
#define ADC_JDR1_JDATA_9            (0x200UL << ADC_JDR1_JDATA_Pos)     /*!< 0x00000200 */
#define ADC_JDR1_JDATA_10            (0x400UL << ADC_JDR1_JDATA_Pos)     /*!< 0x00000400 */
#define ADC_JDR1_JDATA_11            (0x800UL << ADC_JDR1_JDATA_Pos)     /*!< 0x00000800 */
#define ADC_JDR1_JDATA_12            (0x1000UL << ADC_JDR1_JDATA_Pos)     /*!< 0x00001000 */
#define ADC_JDR1_JDATA_13            (0x2000UL << ADC_JDR1_JDATA_Pos)     /*!< 0x00002000 */
#define ADC_JDR1_JDATA_14            (0x4000UL << ADC_JDR1_JDATA_Pos)     /*!< 0x00004000 */
#define ADC_JDR1_JDATA_15            (0x8000UL << ADC_JDR1_JDATA_Pos)     /*!< 0x00008000 */

/*******************  Bit definition for ADC_JDR2 register  *******************/
#define ADC_JDR2_JDATA_Pos           (0U)
#define ADC_JDR2_JDATA_Msk           (0xFFFFUL << ADC_JDR2_JDATA_Pos)   /*!< 0x0000FFFF */
#define ADC_JDR2_JDATA               ADC_JDR2_JDATA_Msk          /*!< </spirit:description> */
#define ADC_JDR2_JDATA_0            (0x1UL << ADC_JDR2_JDATA_Pos)     /*!< 0x00000001 */
#define ADC_JDR2_JDATA_1            (0x2UL << ADC_JDR2_JDATA_Pos)     /*!< 0x00000002 */
#define ADC_JDR2_JDATA_2            (0x4UL << ADC_JDR2_JDATA_Pos)     /*!< 0x00000004 */
#define ADC_JDR2_JDATA_3            (0x8UL << ADC_JDR2_JDATA_Pos)     /*!< 0x00000008 */
#define ADC_JDR2_JDATA_4            (0x10UL << ADC_JDR2_JDATA_Pos)     /*!< 0x00000010 */
#define ADC_JDR2_JDATA_5            (0x20UL << ADC_JDR2_JDATA_Pos)     /*!< 0x00000020 */
#define ADC_JDR2_JDATA_6            (0x40UL << ADC_JDR2_JDATA_Pos)     /*!< 0x00000040 */
#define ADC_JDR2_JDATA_7            (0x80UL << ADC_JDR2_JDATA_Pos)     /*!< 0x00000080 */
#define ADC_JDR2_JDATA_8            (0x100UL << ADC_JDR2_JDATA_Pos)     /*!< 0x00000100 */
#define ADC_JDR2_JDATA_9            (0x200UL << ADC_JDR2_JDATA_Pos)     /*!< 0x00000200 */
#define ADC_JDR2_JDATA_10            (0x400UL << ADC_JDR2_JDATA_Pos)     /*!< 0x00000400 */
#define ADC_JDR2_JDATA_11            (0x800UL << ADC_JDR2_JDATA_Pos)     /*!< 0x00000800 */
#define ADC_JDR2_JDATA_12            (0x1000UL << ADC_JDR2_JDATA_Pos)     /*!< 0x00001000 */
#define ADC_JDR2_JDATA_13            (0x2000UL << ADC_JDR2_JDATA_Pos)     /*!< 0x00002000 */
#define ADC_JDR2_JDATA_14            (0x4000UL << ADC_JDR2_JDATA_Pos)     /*!< 0x00004000 */
#define ADC_JDR2_JDATA_15            (0x8000UL << ADC_JDR2_JDATA_Pos)     /*!< 0x00008000 */

/*******************  Bit definition for ADC_JDR3 register  *******************/
#define ADC_JDR3_JDATA_Pos           (0U)
#define ADC_JDR3_JDATA_Msk           (0xFFFFUL << ADC_JDR3_JDATA_Pos)   /*!< 0x0000FFFF */
#define ADC_JDR3_JDATA               ADC_JDR3_JDATA_Msk          /*!< </spirit:description> */
#define ADC_JDR3_JDATA_0            (0x1UL << ADC_JDR3_JDATA_Pos)     /*!< 0x00000001 */
#define ADC_JDR3_JDATA_1            (0x2UL << ADC_JDR3_JDATA_Pos)     /*!< 0x00000002 */
#define ADC_JDR3_JDATA_2            (0x4UL << ADC_JDR3_JDATA_Pos)     /*!< 0x00000004 */
#define ADC_JDR3_JDATA_3            (0x8UL << ADC_JDR3_JDATA_Pos)     /*!< 0x00000008 */
#define ADC_JDR3_JDATA_4            (0x10UL << ADC_JDR3_JDATA_Pos)     /*!< 0x00000010 */
#define ADC_JDR3_JDATA_5            (0x20UL << ADC_JDR3_JDATA_Pos)     /*!< 0x00000020 */
#define ADC_JDR3_JDATA_6            (0x40UL << ADC_JDR3_JDATA_Pos)     /*!< 0x00000040 */
#define ADC_JDR3_JDATA_7            (0x80UL << ADC_JDR3_JDATA_Pos)     /*!< 0x00000080 */
#define ADC_JDR3_JDATA_8            (0x100UL << ADC_JDR3_JDATA_Pos)     /*!< 0x00000100 */
#define ADC_JDR3_JDATA_9            (0x200UL << ADC_JDR3_JDATA_Pos)     /*!< 0x00000200 */
#define ADC_JDR3_JDATA_10            (0x400UL << ADC_JDR3_JDATA_Pos)     /*!< 0x00000400 */
#define ADC_JDR3_JDATA_11            (0x800UL << ADC_JDR3_JDATA_Pos)     /*!< 0x00000800 */
#define ADC_JDR3_JDATA_12            (0x1000UL << ADC_JDR3_JDATA_Pos)     /*!< 0x00001000 */
#define ADC_JDR3_JDATA_13            (0x2000UL << ADC_JDR3_JDATA_Pos)     /*!< 0x00002000 */
#define ADC_JDR3_JDATA_14            (0x4000UL << ADC_JDR3_JDATA_Pos)     /*!< 0x00004000 */
#define ADC_JDR3_JDATA_15            (0x8000UL << ADC_JDR3_JDATA_Pos)     /*!< 0x00008000 */

/*******************  Bit definition for ADC_JDR4 register  *******************/
#define ADC_JDR4_JDATA_Pos           (0U)
#define ADC_JDR4_JDATA_Msk           (0xFFFFUL << ADC_JDR4_JDATA_Pos)   /*!< 0x0000FFFF */
#define ADC_JDR4_JDATA               ADC_JDR4_JDATA_Msk          /*!< </spirit:description> */
#define ADC_JDR4_JDATA_0            (0x1UL << ADC_JDR4_JDATA_Pos)     /*!< 0x00000001 */
#define ADC_JDR4_JDATA_1            (0x2UL << ADC_JDR4_JDATA_Pos)     /*!< 0x00000002 */
#define ADC_JDR4_JDATA_2            (0x4UL << ADC_JDR4_JDATA_Pos)     /*!< 0x00000004 */
#define ADC_JDR4_JDATA_3            (0x8UL << ADC_JDR4_JDATA_Pos)     /*!< 0x00000008 */
#define ADC_JDR4_JDATA_4            (0x10UL << ADC_JDR4_JDATA_Pos)     /*!< 0x00000010 */
#define ADC_JDR4_JDATA_5            (0x20UL << ADC_JDR4_JDATA_Pos)     /*!< 0x00000020 */
#define ADC_JDR4_JDATA_6            (0x40UL << ADC_JDR4_JDATA_Pos)     /*!< 0x00000040 */
#define ADC_JDR4_JDATA_7            (0x80UL << ADC_JDR4_JDATA_Pos)     /*!< 0x00000080 */
#define ADC_JDR4_JDATA_8            (0x100UL << ADC_JDR4_JDATA_Pos)     /*!< 0x00000100 */
#define ADC_JDR4_JDATA_9            (0x200UL << ADC_JDR4_JDATA_Pos)     /*!< 0x00000200 */
#define ADC_JDR4_JDATA_10            (0x400UL << ADC_JDR4_JDATA_Pos)     /*!< 0x00000400 */
#define ADC_JDR4_JDATA_11            (0x800UL << ADC_JDR4_JDATA_Pos)     /*!< 0x00000800 */
#define ADC_JDR4_JDATA_12            (0x1000UL << ADC_JDR4_JDATA_Pos)     /*!< 0x00001000 */
#define ADC_JDR4_JDATA_13            (0x2000UL << ADC_JDR4_JDATA_Pos)     /*!< 0x00002000 */
#define ADC_JDR4_JDATA_14            (0x4000UL << ADC_JDR4_JDATA_Pos)     /*!< 0x00004000 */
#define ADC_JDR4_JDATA_15            (0x8000UL << ADC_JDR4_JDATA_Pos)     /*!< 0x00008000 */

/******************  Bit definition for ADC_AWD2CR register  ******************/
#define ADC_AWD2CR_AWD2CH_Pos        (0U)
#define ADC_AWD2CR_AWD2CH_Msk        (0x7FFFFUL << ADC_AWD2CR_AWD2CH_Pos)       /*!< 0x0007FFFF */
#define ADC_AWD2CR_AWD2CH            ADC_AWD2CR_AWD2CH_Msk       /*!< </spirit:description> */
#define ADC_AWD2CR_AWD2CH_0         (0x1UL << ADC_AWD2CR_AWD2CH_Pos)         /*!< 0x00000001 */
#define ADC_AWD2CR_AWD2CH_1         (0x2UL << ADC_AWD2CR_AWD2CH_Pos)         /*!< 0x00000002 */
#define ADC_AWD2CR_AWD2CH_2         (0x4UL << ADC_AWD2CR_AWD2CH_Pos)         /*!< 0x00000004 */
#define ADC_AWD2CR_AWD2CH_3         (0x8UL << ADC_AWD2CR_AWD2CH_Pos)         /*!< 0x00000008 */
#define ADC_AWD2CR_AWD2CH_4         (0x10UL << ADC_AWD2CR_AWD2CH_Pos)         /*!< 0x00000010 */
#define ADC_AWD2CR_AWD2CH_5         (0x20UL << ADC_AWD2CR_AWD2CH_Pos)         /*!< 0x00000020 */
#define ADC_AWD2CR_AWD2CH_6         (0x40UL << ADC_AWD2CR_AWD2CH_Pos)         /*!< 0x00000040 */
#define ADC_AWD2CR_AWD2CH_7         (0x80UL << ADC_AWD2CR_AWD2CH_Pos)         /*!< 0x00000080 */
#define ADC_AWD2CR_AWD2CH_8         (0x100UL << ADC_AWD2CR_AWD2CH_Pos)         /*!< 0x00000100 */
#define ADC_AWD2CR_AWD2CH_9         (0x200UL << ADC_AWD2CR_AWD2CH_Pos)         /*!< 0x00000200 */
#define ADC_AWD2CR_AWD2CH_10         (0x400UL << ADC_AWD2CR_AWD2CH_Pos)         /*!< 0x00000400 */
#define ADC_AWD2CR_AWD2CH_11         (0x800UL << ADC_AWD2CR_AWD2CH_Pos)         /*!< 0x00000800 */
#define ADC_AWD2CR_AWD2CH_12         (0x1000UL << ADC_AWD2CR_AWD2CH_Pos)         /*!< 0x00001000 */
#define ADC_AWD2CR_AWD2CH_13         (0x2000UL << ADC_AWD2CR_AWD2CH_Pos)         /*!< 0x00002000 */
#define ADC_AWD2CR_AWD2CH_14         (0x4000UL << ADC_AWD2CR_AWD2CH_Pos)         /*!< 0x00004000 */
#define ADC_AWD2CR_AWD2CH_15         (0x8000UL << ADC_AWD2CR_AWD2CH_Pos)         /*!< 0x00008000 */
#define ADC_AWD2CR_AWD2CH_16         (0x10000UL << ADC_AWD2CR_AWD2CH_Pos)         /*!< 0x00010000 */
#define ADC_AWD2CR_AWD2CH_17         (0x20000UL << ADC_AWD2CR_AWD2CH_Pos)         /*!< 0x00020000 */
#define ADC_AWD2CR_AWD2CH_18         (0x40000UL << ADC_AWD2CR_AWD2CH_Pos)         /*!< 0x00040000 */

/******************  Bit definition for ADC_AWD3CR register  ******************/
#define ADC_AWD3CR_AWD3CH_Pos        (0U)
#define ADC_AWD3CR_AWD3CH_Msk        (0x7FFFFUL << ADC_AWD3CR_AWD3CH_Pos)       /*!< 0x0007FFFF */
#define ADC_AWD3CR_AWD3CH            ADC_AWD3CR_AWD3CH_Msk       /*!< </spirit:description> */
#define ADC_AWD3CR_AWD3CH_0         (0x1UL << ADC_AWD3CR_AWD3CH_Pos)         /*!< 0x00000001 */
#define ADC_AWD3CR_AWD3CH_1         (0x2UL << ADC_AWD3CR_AWD3CH_Pos)         /*!< 0x00000002 */
#define ADC_AWD3CR_AWD3CH_2         (0x4UL << ADC_AWD3CR_AWD3CH_Pos)         /*!< 0x00000004 */
#define ADC_AWD3CR_AWD3CH_3         (0x8UL << ADC_AWD3CR_AWD3CH_Pos)         /*!< 0x00000008 */
#define ADC_AWD3CR_AWD3CH_4         (0x10UL << ADC_AWD3CR_AWD3CH_Pos)         /*!< 0x00000010 */
#define ADC_AWD3CR_AWD3CH_5         (0x20UL << ADC_AWD3CR_AWD3CH_Pos)         /*!< 0x00000020 */
#define ADC_AWD3CR_AWD3CH_6         (0x40UL << ADC_AWD3CR_AWD3CH_Pos)         /*!< 0x00000040 */
#define ADC_AWD3CR_AWD3CH_7         (0x80UL << ADC_AWD3CR_AWD3CH_Pos)         /*!< 0x00000080 */
#define ADC_AWD3CR_AWD3CH_8         (0x100UL << ADC_AWD3CR_AWD3CH_Pos)         /*!< 0x00000100 */
#define ADC_AWD3CR_AWD3CH_9         (0x200UL << ADC_AWD3CR_AWD3CH_Pos)         /*!< 0x00000200 */
#define ADC_AWD3CR_AWD3CH_10         (0x400UL << ADC_AWD3CR_AWD3CH_Pos)         /*!< 0x00000400 */
#define ADC_AWD3CR_AWD3CH_11         (0x800UL << ADC_AWD3CR_AWD3CH_Pos)         /*!< 0x00000800 */
#define ADC_AWD3CR_AWD3CH_12         (0x1000UL << ADC_AWD3CR_AWD3CH_Pos)         /*!< 0x00001000 */
#define ADC_AWD3CR_AWD3CH_13         (0x2000UL << ADC_AWD3CR_AWD3CH_Pos)         /*!< 0x00002000 */
#define ADC_AWD3CR_AWD3CH_14         (0x4000UL << ADC_AWD3CR_AWD3CH_Pos)         /*!< 0x00004000 */
#define ADC_AWD3CR_AWD3CH_15         (0x8000UL << ADC_AWD3CR_AWD3CH_Pos)         /*!< 0x00008000 */
#define ADC_AWD3CR_AWD3CH_16         (0x10000UL << ADC_AWD3CR_AWD3CH_Pos)         /*!< 0x00010000 */
#define ADC_AWD3CR_AWD3CH_17         (0x20000UL << ADC_AWD3CR_AWD3CH_Pos)         /*!< 0x00020000 */
#define ADC_AWD3CR_AWD3CH_18         (0x40000UL << ADC_AWD3CR_AWD3CH_Pos)         /*!< 0x00040000 */

/******************  Bit definition for ADC_DIFSEL register  ******************/
#define ADC_DIFSEL_DIFSEL_Pos        (0U)
#define ADC_DIFSEL_DIFSEL_Msk        (0x7FFFFUL << ADC_DIFSEL_DIFSEL_Pos)       /*!< 0x0007FFFF */
#define ADC_DIFSEL_DIFSEL            ADC_DIFSEL_DIFSEL_Msk       /*!< </spirit:description> */
#define ADC_DIFSEL_DIFSEL_0         (0x1UL << ADC_DIFSEL_DIFSEL_Pos)         /*!< 0x00000001 */
#define ADC_DIFSEL_DIFSEL_1         (0x2UL << ADC_DIFSEL_DIFSEL_Pos)         /*!< 0x00000002 */
#define ADC_DIFSEL_DIFSEL_2         (0x4UL << ADC_DIFSEL_DIFSEL_Pos)         /*!< 0x00000004 */
#define ADC_DIFSEL_DIFSEL_3         (0x8UL << ADC_DIFSEL_DIFSEL_Pos)         /*!< 0x00000008 */
#define ADC_DIFSEL_DIFSEL_4         (0x10UL << ADC_DIFSEL_DIFSEL_Pos)         /*!< 0x00000010 */
#define ADC_DIFSEL_DIFSEL_5         (0x20UL << ADC_DIFSEL_DIFSEL_Pos)         /*!< 0x00000020 */
#define ADC_DIFSEL_DIFSEL_6         (0x40UL << ADC_DIFSEL_DIFSEL_Pos)         /*!< 0x00000040 */
#define ADC_DIFSEL_DIFSEL_7         (0x80UL << ADC_DIFSEL_DIFSEL_Pos)         /*!< 0x00000080 */
#define ADC_DIFSEL_DIFSEL_8         (0x100UL << ADC_DIFSEL_DIFSEL_Pos)         /*!< 0x00000100 */
#define ADC_DIFSEL_DIFSEL_9         (0x200UL << ADC_DIFSEL_DIFSEL_Pos)         /*!< 0x00000200 */
#define ADC_DIFSEL_DIFSEL_10         (0x400UL << ADC_DIFSEL_DIFSEL_Pos)         /*!< 0x00000400 */
#define ADC_DIFSEL_DIFSEL_11         (0x800UL << ADC_DIFSEL_DIFSEL_Pos)         /*!< 0x00000800 */
#define ADC_DIFSEL_DIFSEL_12         (0x1000UL << ADC_DIFSEL_DIFSEL_Pos)         /*!< 0x00001000 */
#define ADC_DIFSEL_DIFSEL_13         (0x2000UL << ADC_DIFSEL_DIFSEL_Pos)         /*!< 0x00002000 */
#define ADC_DIFSEL_DIFSEL_14         (0x4000UL << ADC_DIFSEL_DIFSEL_Pos)         /*!< 0x00004000 */
#define ADC_DIFSEL_DIFSEL_15         (0x8000UL << ADC_DIFSEL_DIFSEL_Pos)         /*!< 0x00008000 */
#define ADC_DIFSEL_DIFSEL_16         (0x10000UL << ADC_DIFSEL_DIFSEL_Pos)         /*!< 0x00010000 */
#define ADC_DIFSEL_DIFSEL_17         (0x20000UL << ADC_DIFSEL_DIFSEL_Pos)         /*!< 0x00020000 */
#define ADC_DIFSEL_DIFSEL_18         (0x40000UL << ADC_DIFSEL_DIFSEL_Pos)         /*!< 0x00040000 */

/*****************  Bit definition for ADC_CALFACT register  ******************/
#define ADC_CALFACT_CALFACT_S_Pos    (0U)
#define ADC_CALFACT_CALFACT_S_Msk    (0x7FUL << ADC_CALFACT_CALFACT_S_Pos)        /*!< 0x0000007F */
#define ADC_CALFACT_CALFACT_S        ADC_CALFACT_CALFACT_S_Msk   /*!< </spirit:description> */
#define ADC_CALFACT_CALFACT_S_0     (0x1UL << ADC_CALFACT_CALFACT_S_Pos)          /*!< 0x00000001 */
#define ADC_CALFACT_CALFACT_S_1     (0x2UL << ADC_CALFACT_CALFACT_S_Pos)          /*!< 0x00000002 */
#define ADC_CALFACT_CALFACT_S_2     (0x4UL << ADC_CALFACT_CALFACT_S_Pos)          /*!< 0x00000004 */
#define ADC_CALFACT_CALFACT_S_3     (0x8UL << ADC_CALFACT_CALFACT_S_Pos)          /*!< 0x00000008 */
#define ADC_CALFACT_CALFACT_S_4     (0x10UL << ADC_CALFACT_CALFACT_S_Pos)          /*!< 0x00000010 */
#define ADC_CALFACT_CALFACT_S_5     (0x20UL << ADC_CALFACT_CALFACT_S_Pos)          /*!< 0x00000020 */
#define ADC_CALFACT_CALFACT_S_6     (0x40UL << ADC_CALFACT_CALFACT_S_Pos)          /*!< 0x00000040 */
#define ADC_CALFACT_CALFACT_D_Pos    (16U)
#define ADC_CALFACT_CALFACT_D_Msk    (0x7FUL << ADC_CALFACT_CALFACT_D_Pos)        /*!< 0x007F0000 */
#define ADC_CALFACT_CALFACT_D        ADC_CALFACT_CALFACT_D_Msk   /*!< </spirit:description> */
#define ADC_CALFACT_CALFACT_D_0     (0x1UL << ADC_CALFACT_CALFACT_D_Pos)          /*!< 0x00010000 */
#define ADC_CALFACT_CALFACT_D_1     (0x2UL << ADC_CALFACT_CALFACT_D_Pos)          /*!< 0x00020000 */
#define ADC_CALFACT_CALFACT_D_2     (0x4UL << ADC_CALFACT_CALFACT_D_Pos)          /*!< 0x00040000 */
#define ADC_CALFACT_CALFACT_D_3     (0x8UL << ADC_CALFACT_CALFACT_D_Pos)          /*!< 0x00080000 */
#define ADC_CALFACT_CALFACT_D_4     (0x10UL << ADC_CALFACT_CALFACT_D_Pos)          /*!< 0x00100000 */
#define ADC_CALFACT_CALFACT_D_5     (0x20UL << ADC_CALFACT_CALFACT_D_Pos)          /*!< 0x00200000 */
#define ADC_CALFACT_CALFACT_D_6     (0x40UL << ADC_CALFACT_CALFACT_D_Pos)          /*!< 0x00400000 */

/****************  Bit definition for ADC_CSR register  ****************/
#define ADC_CSR_ADRDY_MST_Pos     (0U)
#define ADC_CSR_ADRDY_MST_Msk     (0x1UL << ADC_CSR_ADRDY_MST_Pos)          /*!< 0x00000001 */
#define ADC_CSR_ADRDY_MST         ADC_CSR_ADRDY_MST_Msk      /*!< ADRDY_MST */
#define ADC_CSR_EOSMP_MST_Pos     (1U)
#define ADC_CSR_EOSMP_MST_Msk     (0x1UL << ADC_CSR_EOSMP_MST_Pos)          /*!< 0x00000002 */
#define ADC_CSR_EOSMP_MST         ADC_CSR_EOSMP_MST_Msk      /*!< EOSMP_MST */
#define ADC_CSR_EOC_MST_Pos       (2U)
#define ADC_CSR_EOC_MST_Msk       (0x1UL << ADC_CSR_EOC_MST_Pos)        /*!< 0x00000004 */
#define ADC_CSR_EOC_MST            ADC_CSR_EOC_MST_Msk        /*!< EOC_MST */
#define ADC_CSR_EOS_MST_Pos       (3U)
#define ADC_CSR_EOS_MST_Msk       (0x1UL << ADC_CSR_EOS_MST_Pos)        /*!< 0x00000008 */
#define ADC_CSR_EOS_MST            ADC_CSR_EOS_MST_Msk        /*!< EOS_MST */
#define ADC_CSR_OVR_MST_Pos       (4U)
#define ADC_CSR_OVR_MST_Msk       (0x1UL << ADC_CSR_OVR_MST_Pos)        /*!< 0x00000010 */
#define ADC_CSR_OVR_MST            ADC_CSR_OVR_MST_Msk        /*!< OVR_MST */
#define ADC_CSR_JEOC_MST_Pos      (5U)
#define ADC_CSR_JEOC_MST_Msk      (0x1UL << ADC_CSR_JEOC_MST_Pos)         /*!< 0x00000020 */
#define ADC_CSR_JEOC_MST           ADC_CSR_JEOC_MST_Msk       /*!< JEOC_MST */
#define ADC_CSR_JEOS_MST_Pos      (6U)
#define ADC_CSR_JEOS_MST_Msk      (0x1UL << ADC_CSR_JEOS_MST_Pos)         /*!< 0x00000040 */
#define ADC_CSR_JEOS_MST           ADC_CSR_JEOS_MST_Msk       /*!< JEOS_MST */
#define ADC_CSR_AWD1_MST_Pos      (7U)
#define ADC_CSR_AWD1_MST_Msk      (0x1UL << ADC_CSR_AWD1_MST_Pos)         /*!< 0x00000080 */
#define ADC_CSR_AWD1_MST                   ADC_CSR_AWD1_MST_Msk       /*!< AWD1_MST */
#define ADC_CSR_AWD2_MST_Pos      (8U)
#define ADC_CSR_AWD2_MST_Msk      (0x1UL << ADC_CSR_AWD2_MST_Pos)         /*!< 0x00000100 */
#define ADC_CSR_AWD2_MST                   ADC_CSR_AWD2_MST_Msk       /*!< AWD2_MST */
#define ADC_CSR_AWD3_MST_Pos      (9U)
#define ADC_CSR_AWD3_MST_Msk      (0x1UL << ADC_CSR_AWD3_MST_Pos)         /*!< 0x00000200 */
#define ADC_CSR_AWD3_MST                   ADC_CSR_AWD3_MST_Msk       /*!< AWD3_MST */
#define ADC_CSR_JQOVF_MST_Pos     (10U)
#define ADC_CSR_JQOVF_MST_Msk     (0x1UL << ADC_CSR_JQOVF_MST_Pos)          /*!< 0x00000400 */
#define ADC_CSR_JQOVF_MST                  ADC_CSR_JQOVF_MST_Msk      /*!< JQOVF_MST */
#define ADC_CSR_ADRDY_SLV_Pos     (16U)
#define ADC_CSR_ADRDY_SLV_Msk     (0x1UL << ADC_CSR_ADRDY_SLV_Pos)          /*!< 0x00010000 */
#define ADC_CSR_ADRDY_SLV                  ADC_CSR_ADRDY_SLV_Msk      /*!< ADRDY_SLV */
#define ADC_CSR_EOSMP_SLV_Pos     (17U)
#define ADC_CSR_EOSMP_SLV_Msk     (0x1UL << ADC_CSR_EOSMP_SLV_Pos)          /*!< 0x00020000 */
#define ADC_CSR_EOSMP_SLV                  ADC_CSR_EOSMP_SLV_Msk      /*!< EOSMP_SLV */
#define ADC_CSR_EOC_SLV_Pos       (18U)
#define ADC_CSR_EOC_SLV_Msk       (0x1UL << ADC_CSR_EOC_SLV_Pos)        /*!< 0x00040000 */
#define ADC_CSR_EOC_SLV                    ADC_CSR_EOC_SLV_Msk        /*!< EOC_SLV */
#define ADC_CSR_EOS_SLV_Pos       (19U)
#define ADC_CSR_EOS_SLV_Msk       (0x1UL << ADC_CSR_EOS_SLV_Pos)        /*!< 0x00080000 */
#define ADC_CSR_EOS_SLV                    ADC_CSR_EOS_SLV_Msk        /*!< EOS_SLV */
#define ADC_CSR_OVR_SLV_Pos       (20U)
#define ADC_CSR_OVR_SLV_Msk       (0x1UL << ADC_CSR_OVR_SLV_Pos)        /*!< 0x00100000 */
#define ADC_CSR_OVR_SLV                    ADC_CSR_OVR_SLV_Msk        /*!< OVR_SLV */
#define ADC_CSR_JEOC_SLV_Pos      (21U)
#define ADC_CSR_JEOC_SLV_Msk      (0x1UL << ADC_CSR_JEOC_SLV_Pos)         /*!< 0x00200000 */
#define ADC_CSR_JEOC_SLV                   ADC_CSR_JEOC_SLV_Msk       /*!< JEOC_SLV */
#define ADC_CSR_JEOS_SLV_Pos      (22U)
#define ADC_CSR_JEOS_SLV_Msk      (0x1UL << ADC_CSR_JEOS_SLV_Pos)         /*!< 0x00400000 */
#define ADC_CSR_JEOS_SLV                   ADC_CSR_JEOS_SLV_Msk       /*!< JEOS_SLV */
#define ADC_CSR_AWD1_SLV_Pos      (23U)
#define ADC_CSR_AWD1_SLV_Msk      (0x1UL << ADC_CSR_AWD1_SLV_Pos)         /*!< 0x00800000 */
#define ADC_CSR_AWD1_SLV                   ADC_CSR_AWD1_SLV_Msk       /*!< AWD1_SLV */
#define ADC_CSR_AWD2_SLV_Pos      (24U)
#define ADC_CSR_AWD2_SLV_Msk      (0x1UL << ADC_CSR_AWD2_SLV_Pos)         /*!< 0x01000000 */
#define ADC_CSR_AWD2_SLV                   ADC_CSR_AWD2_SLV_Msk       /*!< AWD2_SLV */
#define ADC_CSR_AWD3_SLV_Pos      (25U)
#define ADC_CSR_AWD3_SLV_Msk      (0x1UL << ADC_CSR_AWD3_SLV_Pos)         /*!< 0x02000000 */
#define ADC_CSR_AWD3_SLV                   ADC_CSR_AWD3_SLV_Msk       /*!< AWD3_SLV */
#define ADC_CSR_JQOVF_SLV_Pos     (26U)
#define ADC_CSR_JQOVF_SLV_Msk     (0x1UL << ADC_CSR_JQOVF_SLV_Pos)          /*!< 0x04000000 */
#define ADC_CSR_JQOVF_SLV                  ADC_CSR_JQOVF_SLV_Msk      /*!< JQOVF_SLV */

/****************  Bit definition for ADC_CCR register  ****************/
#define ADC_CCR_DUAL_Pos          (0U)
#define ADC_CCR_DUAL_Msk          (0x1FUL << ADC_CCR_DUAL_Pos)      /*!< 0x0000001F */
#define ADC_CCR_DUAL              ADC_CCR_DUAL_Msk           /*!< DUAL */
#define ADC_CCR_DUAL_0         (0x1UL << ADC_CCR_DUAL_Pos)      /*!< 0x00000001 */
#define ADC_CCR_DUAL_1         (0x2UL << ADC_CCR_DUAL_Pos)      /*!< 0x00000002 */
#define ADC_CCR_DUAL_2         (0x4UL << ADC_CCR_DUAL_Pos)      /*!< 0x00000004 */
#define ADC_CCR_DUAL_3         (0x8UL << ADC_CCR_DUAL_Pos)      /*!< 0x00000008 */
#define ADC_CCR_DUAL_4         (0x10UL << ADC_CCR_DUAL_Pos)      /*!< 0x00000010 */
#define ADC_CCR_DELAY_Pos         (8U)
#define ADC_CCR_DELAY_Msk         (0xFUL << ADC_CCR_DELAY_Pos)      /*!< 0x00000F00 */
#define ADC_CCR_DELAY              ADC_CCR_DELAY_Msk          /*!< DELAY */
#define ADC_CCR_DELAY_0        (0x1UL << ADC_CCR_DELAY_Pos)      /*!< 0x00000100 */
#define ADC_CCR_DELAY_1        (0x2UL << ADC_CCR_DELAY_Pos)      /*!< 0x00000200 */
#define ADC_CCR_DELAY_2        (0x4UL << ADC_CCR_DELAY_Pos)      /*!< 0x00000400 */
#define ADC_CCR_DELAY_3        (0x8UL << ADC_CCR_DELAY_Pos)      /*!< 0x00000800 */
#define ADC_CCR_DMACFG_Pos        (13U)
#define ADC_CCR_DMACFG_Msk        (0x1UL << ADC_CCR_DMACFG_Pos)       /*!< 0x00002000 */
#define ADC_CCR_DMACFG            ADC_CCR_DMACFG_Msk         /*!< DMACFG */
#define ADC_CCR_MDMA_Pos          (14U)
#define ADC_CCR_MDMA_Msk          (0x3UL << ADC_CCR_MDMA_Pos)     /*!< 0x0000C000 */
#define ADC_CCR_MDMA              ADC_CCR_MDMA_Msk           /*!< MDMA */
#define ADC_CCR_MDMA_0            (0x1UL << ADC_CCR_MDMA_Pos)     /*!< 0x00004000 */
#define ADC_CCR_MDMA_1            (0x2UL << ADC_CCR_MDMA_Pos)     /*!< 0x00008000 */
#define ADC_CCR_CKMODE_Pos        (16U)
#define ADC_CCR_CKMODE_Msk        (0x3UL << ADC_CCR_CKMODE_Pos)       /*!< 0x00030000 */
#define ADC_CCR_CKMODE            ADC_CCR_CKMODE_Msk         /*!< CKMODE */
#define ADC_CCR_CKMODE_0       (0x1UL << ADC_CCR_CKMODE_Pos)       /*!< 0x00010000 */
#define ADC_CCR_CKMODE_1       (0x2UL << ADC_CCR_CKMODE_Pos)       /*!< 0x00020000 */
#define ADC_CCR_PRESC_Pos         (18U)
#define ADC_CCR_PRESC_Msk         (0xFUL << ADC_CCR_PRESC_Pos)      /*!< 0x003C0000 */
#define ADC_CCR_PRESC              ADC_CCR_PRESC_Msk          /*!< PRESC */
#define ADC_CCR_PRESC_0        (0x1UL << ADC_CCR_PRESC_Pos)      /*!< 0x00040000 */
#define ADC_CCR_PRESC_1        (0x2UL << ADC_CCR_PRESC_Pos)      /*!< 0x00080000 */
#define ADC_CCR_PRESC_2        (0x4UL << ADC_CCR_PRESC_Pos)      /*!< 0x00100000 */
#define ADC_CCR_PRESC_3        (0x8UL << ADC_CCR_PRESC_Pos)      /*!< 0x00200000 */
#define ADC_CCR_VREFEN_Pos        (22U)
#define ADC_CCR_VREFEN_Msk        (0x1UL << ADC_CCR_VREFEN_Pos)       /*!< 0x00400000 */
#define ADC_CCR_VREFEN             ADC_CCR_VREFEN_Msk         /*!< VREFEN */

/****************  Bit definition for ADC_CDR register  ****************/
#define ADC_CDR_RDATA_MST_Pos     (0U)
#define ADC_CDR_RDATA_MST_Msk     (0xFFFFUL << ADC_CDR_RDATA_MST_Pos)             /*!< 0x0000FFFF */
#define ADC_CDR_RDATA_MST         ADC_CDR_RDATA_MST_Msk      /*!< RDATA_MST */
#define ADC_CDR_RDATA_SLV_Pos     (16U)
#define ADC_CDR_RDATA_SLV_Msk     (0xFFFFUL << ADC_CDR_RDATA_SLV_Pos)             /*!< 0xFFFF0000 */
#define ADC_CDR_RDATA_SLV         ADC_CDR_RDATA_SLV_Msk      /*!< RDATA_SLV */

#define ADC1_BASE           0x48008000UL 
#define ADC2_BASE           0x48008100UL
#define ADC12_COMMON_BASE   0x48008300UL 

#define ADC3_BASE           0x44008000UL
#define ADC4_BASE           0x44008100UL
#define ADC5_BASE           0x44008200UL 
#define ADC345_COMMON_BASE  0x44008300UL


#define ADC1                ((ADC_TypeDef *) ADC1_BASE) 
#define ADC2                ((ADC_TypeDef *) ADC2_BASE)
#define ADC3                ((ADC_TypeDef *) ADC3_BASE) 
#define ADC4                ((ADC_TypeDef *) ADC4_BASE) 
#define ADC5                ((ADC_TypeDef *) ADC5_BASE) 
#define ADC12_COMMON        ((ADC_Common_TypeDef *) ADC12_COMMON_BASE) 
#define ADC345_COMMON       ((ADC_Common_TypeDef *) ADC345_COMMON_BASE) 

#endif /* __SR5E1_ADC_H */

