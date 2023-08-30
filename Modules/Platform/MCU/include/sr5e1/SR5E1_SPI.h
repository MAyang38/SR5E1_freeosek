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

#ifndef __SR5E1_SPI_H
#define __SR5E1_SPI_H

/******************************************************************************/
/*                                                                            */
/*                                   (SPI)                                   */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO uint32_t CR1;      /*!< CR1     Address offset: 0x00 */
  __IO uint32_t CR2;      /*!< CR2     Address offset: 0x04 */
  __IO uint32_t SR;       /*!< SR      Address offset: 0x08 */
  __IO uint32_t DR;       /*!< DR      Address offset: 0x0C */
  __IO uint32_t CRCPR;    /*!< CRCPR   Address offset: 0x10 */
  __IO uint32_t RXCRCR;   /*!< RXCRCR  Address offset: 0x14 */
  __IO uint32_t TXCRCR;   /*!< TXCRCR  Address offset: 0x18 */
  __IO uint32_t I2SCFGR;  /*!< I2SCFGR Address offset: 0x1C */
  __IO uint32_t I2SPR;    /*!< I2SPR   Address offset: 0x20 */
} SPI_TypeDef;


/*******************  Bit definition for SPI_CR1 register  ********************/
#define SPI_CR1_CPHA_Pos           (0U)
#define SPI_CR1_CPHA_Msk             (0x1UL << SPI_CR1_CPHA_Pos)  /*!< 0x00000001 */
#define SPI_CR1_CPHA               SPI_CR1_CPHA_Msk          /*!< </spirit:description> */
#define SPI_CR1_CPOL_Pos           (1U)
#define SPI_CR1_CPOL_Msk             (0x1UL << SPI_CR1_CPOL_Pos)  /*!< 0x00000002 */
#define SPI_CR1_CPOL               SPI_CR1_CPOL_Msk          /*!< </spirit:description> */
#define SPI_CR1_MSTR_Pos           (2U)
#define SPI_CR1_MSTR_Msk             (0x1UL << SPI_CR1_MSTR_Pos)  /*!< 0x00000004 */
#define SPI_CR1_MSTR               SPI_CR1_MSTR_Msk          /*!< </spirit:description> */
#define SPI_CR1_BR_Pos             (3U)
#define SPI_CR1_BR_Msk             (0x7UL << SPI_CR1_BR_Pos)  /*!< 0x00000038 */
#define SPI_CR1_BR                 SPI_CR1_BR_Msk            /*!< </spirit:description> */
#define SPI_CR1_BR_0       (0x1UL << SPI_CR1_BR_Pos)      /*!< 0x00000008 */
#define SPI_CR1_BR_1       (0x2UL << SPI_CR1_BR_Pos)       /*!< 0x00000010 */
#define SPI_CR1_BR_2       (0x4UL << SPI_CR1_BR_Pos)       /*!< 0x00000020 */
#define SPI_CR1_SPE_Pos            (6U)
#define SPI_CR1_SPE_Msk            (0x1UL << SPI_CR1_SPE_Pos) /*!< 0x00000040 */
#define SPI_CR1_SPE                SPI_CR1_SPE_Msk           /*!< </spirit:description> */
#define SPI_CR1_LSBFIRST_Pos       (7U)
#define SPI_CR1_LSBFIRST_Msk       (0x1UL << SPI_CR1_LSBFIRST_Pos)    /*!< 0x00000080 */
#define SPI_CR1_LSBFIRST           SPI_CR1_LSBFIRST_Msk      /*!< </spirit:description> */
#define SPI_CR1_SSI_Pos            (8U)
#define SPI_CR1_SSI_Msk            (0x1UL << SPI_CR1_SSI_Pos) /*!< 0x00000100 */
#define SPI_CR1_SSI                SPI_CR1_SSI_Msk           /*!< </spirit:description> */
#define SPI_CR1_SSM_Pos            (9U)
#define SPI_CR1_SSM_Msk            (0x1UL << SPI_CR1_SSM_Pos) /*!< 0x00000200 */
#define SPI_CR1_SSM                SPI_CR1_SSM_Msk           /*!< </spirit:description> */
#define SPI_CR1_RXONLY_Pos         (10U)
#define SPI_CR1_RXONLY_Msk         (0x1UL << SPI_CR1_RXONLY_Pos)  /*!< 0x00000400 */
#define SPI_CR1_RXONLY             SPI_CR1_RXONLY_Msk        /*!< </spirit:description> */
#define SPI_CR1_CRCL_Pos           (11U)
#define SPI_CR1_CRCL_Msk             (0x1UL << SPI_CR1_CRCL_Pos)  /*!< 0x00000800 */
#define SPI_CR1_CRCL               SPI_CR1_CRCL_Msk          /*!< </spirit:description> */
#define SPI_CR1_CRCNEXT_Pos        (12U)
#define SPI_CR1_CRCNEXT_Msk        (0x1UL << SPI_CR1_CRCNEXT_Pos)   /*!< 0x00001000 */
#define SPI_CR1_CRCNEXT            SPI_CR1_CRCNEXT_Msk       /*!< </spirit:description> */
#define SPI_CR1_CRCEN_Pos          (13U)
#define SPI_CR1_CRCEN_Msk          (0x1UL << SPI_CR1_CRCEN_Pos) /*!< 0x00002000 */
#define SPI_CR1_CRCEN              SPI_CR1_CRCEN_Msk         /*!< </spirit:description> */
#define SPI_CR1_BIDIOE_Pos         (14U)
#define SPI_CR1_BIDIOE_Msk         (0x1UL << SPI_CR1_BIDIOE_Pos)  /*!< 0x00004000 */
#define SPI_CR1_BIDIOE             SPI_CR1_BIDIOE_Msk        /*!< </spirit:description> */
#define SPI_CR1_BIDIMODE_Pos       (15U)
#define SPI_CR1_BIDIMODE_Msk       (0x1UL << SPI_CR1_BIDIMODE_Pos)    /*!< 0x00008000 */
#define SPI_CR1_BIDIMODE           SPI_CR1_BIDIMODE_Msk      /*!< </spirit:description> */

/*******************  Bit definition for SPI_CR2 register  ********************/
#define SPI_CR2_RXDMAEN_Pos        (0U)
#define SPI_CR2_RXDMAEN_Msk        (0x1UL << SPI_CR2_RXDMAEN_Pos)   /*!< 0x00000001 */
#define SPI_CR2_RXDMAEN            SPI_CR2_RXDMAEN_Msk       /*!< </spirit:description> */
#define SPI_CR2_TXDMAEN_Pos        (1U)
#define SPI_CR2_TXDMAEN_Msk        (0x1UL << SPI_CR2_TXDMAEN_Pos)   /*!< 0x00000002 */
#define SPI_CR2_TXDMAEN            SPI_CR2_TXDMAEN_Msk       /*!< </spirit:description> */
#define SPI_CR2_SSOE_Pos           (2U)
#define SPI_CR2_SSOE_Msk             (0x1UL << SPI_CR2_SSOE_Pos)  /*!< 0x00000004 */
#define SPI_CR2_SSOE               SPI_CR2_SSOE_Msk          /*!< </spirit:description> */
#define SPI_CR2_NSSP_Pos           (3U)
#define SPI_CR2_NSSP_Msk             (0x1UL << SPI_CR2_NSSP_Pos)  /*!< 0x00000008 */
#define SPI_CR2_NSSP               SPI_CR2_NSSP_Msk          /*!< </spirit:description> */
#define SPI_CR2_FRF_Pos            (4U)
#define SPI_CR2_FRF_Msk            (0x1UL << SPI_CR2_FRF_Pos) /*!< 0x00000010 */
#define SPI_CR2_FRF                SPI_CR2_FRF_Msk           /*!< </spirit:description> */
#define SPI_CR2_ERRIE_Pos          (5U)
#define SPI_CR2_ERRIE_Msk          (0x1UL << SPI_CR2_ERRIE_Pos) /*!< 0x00000020 */
#define SPI_CR2_ERRIE              SPI_CR2_ERRIE_Msk         /*!< </spirit:description> */
#define SPI_CR2_RXNEIE_Pos         (6U)
#define SPI_CR2_RXNEIE_Msk         (0x1UL << SPI_CR2_RXNEIE_Pos)  /*!< 0x00000040 */
#define SPI_CR2_RXNEIE             SPI_CR2_RXNEIE_Msk        /*!< </spirit:description> */
#define SPI_CR2_TXEIE_Pos          (7U)
#define SPI_CR2_TXEIE_Msk          (0x1UL << SPI_CR2_TXEIE_Pos) /*!< 0x00000080 */
#define SPI_CR2_TXEIE              SPI_CR2_TXEIE_Msk         /*!< </spirit:description> */
#define SPI_CR2_DS_Pos             (8U)
#define SPI_CR2_DS_Msk             (0xFUL << SPI_CR2_DS_Pos)  /*!< 0x00000F00 */
#define SPI_CR2_DS                 SPI_CR2_DS_Msk            /*!< </spirit:description> */
#define SPI_CR2_DS_0       (0x1UL << SPI_CR2_DS_Pos)        /*!< 0x00000100 */
#define SPI_CR2_DS_1       (0x2UL << SPI_CR2_DS_Pos)        /*!< 0x00000200 */
#define SPI_CR2_DS_2       (0x4UL << SPI_CR2_DS_Pos)        /*!< 0x00000400 */
#define SPI_CR2_DS_3       (0x8UL << SPI_CR2_DS_Pos)        /*!< 0x00000800 */
#define SPI_CR2_FRXTH_Pos          (12U)
#define SPI_CR2_FRXTH_Msk          (0x1UL << SPI_CR2_FRXTH_Pos) /*!< 0x00001000 */
#define SPI_CR2_FRXTH              SPI_CR2_FRXTH_Msk         /*!< </spirit:description> */
#define SPI_CR2_LDMARX_Pos         (13U)
#define SPI_CR2_LDMARX_Msk         (0x1UL << SPI_CR2_LDMARX_Pos)  /*!< 0x00002000 */
#define SPI_CR2_LDMARX             SPI_CR2_LDMARX_Msk        /*!< </spirit:description> */
#define SPI_CR2_LDMATX_Pos         (14U)
#define SPI_CR2_LDMATX_Msk         (0x1UL << SPI_CR2_LDMATX_Pos)  /*!< 0x00004000 */
#define SPI_CR2_LDMATX             SPI_CR2_LDMATX_Msk        /*!< </spirit:description> */

/********************  Bit definition for SPI_SR register  ********************/
#define SPI_SR_RXNE_Pos            (0U)
#define SPI_SR_RXNE_Msk            (0x1UL << SPI_SR_RXNE_Pos) /*!< 0x00000001 */
#define SPI_SR_RXNE                SPI_SR_RXNE_Msk           /*!< </spirit:description> */
#define SPI_SR_TXE_Pos             (1U)
#define SPI_SR_TXE_Msk             (0x1UL << SPI_SR_TXE_Pos)  /*!< 0x00000002 */
#define SPI_SR_TXE                 SPI_SR_TXE_Msk            /*!< </spirit:description> */
#define SPI_SR_CHSIDE_Pos          (2U)
#define SPI_SR_CHSIDE_Msk          (0x1UL << SPI_SR_CHSIDE_Pos) /*!< 0x00000004 */
#define SPI_SR_CHSIDE              SPI_SR_CHSIDE_Msk         /*!< </spirit:description> */
#define SPI_SR_UDR_Pos             (3U)
#define SPI_SR_UDR_Msk             (0x1UL << SPI_SR_UDR_Pos)  /*!< 0x00000008 */
#define SPI_SR_UDR                 SPI_SR_UDR_Msk            /*!< </spirit:description> */
#define SPI_SR_CRCERR_Pos          (4U)
#define SPI_SR_CRCERR_Msk          (0x1UL << SPI_SR_CRCERR_Pos) /*!< 0x00000010 */
#define SPI_SR_CRCERR              SPI_SR_CRCERR_Msk         /*!< </spirit:description> */
#define SPI_SR_MODF_Pos            (5U)
#define SPI_SR_MODF_Msk            (0x1UL << SPI_SR_MODF_Pos) /*!< 0x00000020 */
#define SPI_SR_MODF                SPI_SR_MODF_Msk           /*!< </spirit:description> */
#define SPI_SR_OVR_Pos             (6U)
#define SPI_SR_OVR_Msk             (0x1UL << SPI_SR_OVR_Pos)  /*!< 0x00000040 */
#define SPI_SR_OVR                 SPI_SR_OVR_Msk            /*!< </spirit:description> */
#define SPI_SR_BSY_Pos             (7U)
#define SPI_SR_BSY_Msk             (0x1UL << SPI_SR_BSY_Pos)  /*!< 0x00000080 */
#define SPI_SR_BSY                 SPI_SR_BSY_Msk            /*!< </spirit:description> */
#define SPI_SR_FRE_Pos             (8U)
#define SPI_SR_FRE_Msk             (0x1UL << SPI_SR_FRE_Pos)  /*!< 0x00000100 */
#define SPI_SR_FRE                 SPI_SR_FRE_Msk            /*!< </spirit:description> */
#define SPI_SR_FRLVL_Pos           (9U)
#define SPI_SR_FRLVL_Msk             (0x3UL << SPI_SR_FRLVL_Pos)  /*!< 0x00000600 */
#define SPI_SR_FRLVL               SPI_SR_FRLVL_Msk          /*!< </spirit:description> */
#define SPI_SR_FRLVL_0     (0x1UL << SPI_SR_FRLVL_Pos)          /*!< 0x00000200 */
#define SPI_SR_FRLVL_1     (0x2UL << SPI_SR_FRLVL_Pos)          /*!< 0x00000400 */
#define SPI_SR_FTLVL_Pos           (11U)
#define SPI_SR_FTLVL_Msk             (0x3UL << SPI_SR_FTLVL_Pos)  /*!< 0x00001800 */
#define SPI_SR_FTLVL               SPI_SR_FTLVL_Msk          /*!< </spirit:description> */
#define SPI_SR_FTLVL_0     (0x1UL << SPI_SR_FTLVL_Pos)          /*!< 0x00000800 */
#define SPI_SR_FTLVL_1     (0x2UL << SPI_SR_FTLVL_Pos)           /*!< 0x00001000 */

/********************  Bit definition for SPI_DR register  ********************/
#define SPI_DR_DR_Pos              (0U)
#define SPI_DR_DR_Msk                (0xFFFFUL << SPI_DR_DR_Pos)  /*!< 0x0000FFFF */
#define SPI_DR_DR                  SPI_DR_DR_Msk             /*!< </spirit:description> */

/******************  Bit definition for SPI_CRCPR register  *******************/
#define SPI_CRCPR_CRCPOLY_Pos      (0U)
#define SPI_CRCPR_CRCPOLY_Msk      (0xFFFFUL << SPI_CRCPR_CRCPOLY_Pos)        /*!< 0x0000FFFF */
#define SPI_CRCPR_CRCPOLY          SPI_CRCPR_CRCPOLY_Msk     /*!< </spirit:description> */

/******************  Bit definition for SPI_RXCRCR register  ******************/
#define SPI_RXCRCR_RXCRC_Pos       (0U)
#define SPI_RXCRCR_RXCRC_Msk       (0xFFFFUL << SPI_RXCRCR_RXCRC_Pos)       /*!< 0x0000FFFF */
#define SPI_RXCRCR_RXCRC           SPI_RXCRCR_RXCRC_Msk      /*!< </spirit:description> */
#define SPI_RXCRCR_RXCRC_0    (0x1UL << SPI_RXCRCR_RXCRC_Pos)            /*!< 0x00000001 */
#define SPI_RXCRCR_RXCRC_1    (0x2UL << SPI_RXCRCR_RXCRC_Pos)            /*!< 0x00000002 */
#define SPI_RXCRCR_RXCRC_2    (0x4UL << SPI_RXCRCR_RXCRC_Pos)            /*!< 0x00000004 */
#define SPI_RXCRCR_RXCRC_3    (0x8UL << SPI_RXCRCR_RXCRC_Pos)            /*!< 0x00000008 */
#define SPI_RXCRCR_RXCRC_4    (0x10UL << SPI_RXCRCR_RXCRC_Pos)             /*!< 0x00000010 */
#define SPI_RXCRCR_RXCRC_5    (0x20UL << SPI_RXCRCR_RXCRC_Pos)             /*!< 0x00000020 */
#define SPI_RXCRCR_RXCRC_6    (0x40UL << SPI_RXCRCR_RXCRC_Pos)             /*!< 0x00000040 */
#define SPI_RXCRCR_RXCRC_7    (0x80UL << SPI_RXCRCR_RXCRC_Pos)             /*!< 0x00000080 */
#define SPI_RXCRCR_RXCRC_8    (0x100UL << SPI_RXCRCR_RXCRC_Pos)              /*!< 0x00000100 */
#define SPI_RXCRCR_RXCRC_9    (0x200UL << SPI_RXCRCR_RXCRC_Pos)              /*!< 0x00000200 */
#define SPI_RXCRCR_RXCRC_10   (0x400UL << SPI_RXCRCR_RXCRC_Pos)              /*!< 0x00000400 */
#define SPI_RXCRCR_RXCRC_11   (0x800UL << SPI_RXCRCR_RXCRC_Pos)              /*!< 0x00000800 */
#define SPI_RXCRCR_RXCRC_12   (0x1000UL << SPI_RXCRCR_RXCRC_Pos)               /*!< 0x00001000 */
#define SPI_RXCRCR_RXCRC_13   (0x2000UL << SPI_RXCRCR_RXCRC_Pos)               /*!< 0x00002000 */
#define SPI_RXCRCR_RXCRC_14   (0x4000UL << SPI_RXCRCR_RXCRC_Pos)               /*!< 0x00004000 */
#define SPI_RXCRCR_RXCRC_15   (0x8000UL << SPI_RXCRCR_RXCRC_Pos)               /*!< 0x00008000 */

/******************  Bit definition for SPI_TXCRCR register  ******************/
#define SPI_TXCRCR_TXCRC_Pos       (0U)
#define SPI_TXCRCR_TXCRC_Msk       (0xFFFFUL << SPI_TXCRCR_TXCRC_Pos)       /*!< 0x0000FFFF */
#define SPI_TXCRCR_TXCRC           SPI_TXCRCR_TXCRC_Msk      /*!< </spirit:description> */

/*****************  Bit definition for SPI_I2SCFGR register  ******************/
#define SPI_I2SCFGR_CHLEN_Pos      (0U)
#define SPI_I2SCFGR_CHLEN_Msk      (0x1UL << SPI_I2SCFGR_CHLEN_Pos)     /*!< 0x00000001 */
#define SPI_I2SCFGR_CHLEN          SPI_I2SCFGR_CHLEN_Msk     /*!< </spirit:description> */
#define SPI_I2SCFGR_DATLEN_Pos     (1U)
#define SPI_I2SCFGR_DATLEN_Msk     (0x3UL << SPI_I2SCFGR_DATLEN_Pos)      /*!< 0x00000006 */
#define SPI_I2SCFGR_DATLEN         SPI_I2SCFGR_DATLEN_Msk    /*!< </spirit:description> */
#define SPI_I2SCFGR_DATLEN_0   (0x1UL << SPI_I2SCFGR_DATLEN_Pos)              /*!< 0x00000002 */
#define SPI_I2SCFGR_DATLEN_1   (0x2UL << SPI_I2SCFGR_DATLEN_Pos)              /*!< 0x00000004 */
#define SPI_I2SCFGR_CKPOL_Pos      (3U)
#define SPI_I2SCFGR_CKPOL_Msk      (0x1UL << SPI_I2SCFGR_CKPOL_Pos)     /*!< 0x00000008 */
#define SPI_I2SCFGR_CKPOL          SPI_I2SCFGR_CKPOL_Msk     /*!< </spirit:description> */
#define SPI_I2SCFGR_I2SSTD_Pos     (4U)
#define SPI_I2SCFGR_I2SSTD_Msk     (0x3UL << SPI_I2SCFGR_I2SSTD_Pos)      /*!< 0x00000030 */
#define SPI_I2SCFGR_I2SSTD         SPI_I2SCFGR_I2SSTD_Msk    /*!< </spirit:description> */
#define SPI_I2SCFGR_I2SSTD_0   (0x1UL << SPI_I2SCFGR_I2SSTD_Pos)               /*!< 0x00000010 */
#define SPI_I2SCFGR_I2SSTD_1   (0x2UL << SPI_I2SCFGR_I2SSTD_Pos)               /*!< 0x00000020 */
#define SPI_I2SCFGR_PCMSYNC_Pos    (7U)
#define SPI_I2SCFGR_PCMSYNC_Msk    (0x1UL << SPI_I2SCFGR_PCMSYNC_Pos)       /*!< 0x00000080 */
#define SPI_I2SCFGR_PCMSYNC        SPI_I2SCFGR_PCMSYNC_Msk   /*!< </spirit:description> */
#define SPI_I2SCFGR_I2SCFG_Pos     (8U)
#define SPI_I2SCFGR_I2SCFG_Msk     (0x3UL << SPI_I2SCFGR_I2SCFG_Pos)      /*!< 0x00000300 */
#define SPI_I2SCFGR_I2SCFG         SPI_I2SCFGR_I2SCFG_Msk    /*!< </spirit:description> */
#define SPI_I2SCFGR_I2SCFG_0   (0x1UL << SPI_I2SCFGR_I2SCFG_Pos)                /*!< 0x00000100 */
#define SPI_I2SCFGR_I2SCFG_1   (0x2UL << SPI_I2SCFGR_I2SCFG_Pos)                /*!< 0x00000200 */
#define SPI_I2SCFGR_I2SE_Pos       (10U)
#define SPI_I2SCFGR_I2SE_Msk       (0x1UL << SPI_I2SCFGR_I2SE_Pos)    /*!< 0x00000400 */
#define SPI_I2SCFGR_I2SE           SPI_I2SCFGR_I2SE_Msk      /*!< </spirit:description> */
#define SPI_I2SCFGR_I2SMOD_Pos     (11U)
#define SPI_I2SCFGR_I2SMOD_Msk     (0x1UL << SPI_I2SCFGR_I2SMOD_Pos)      /*!< 0x00000800 */
#define SPI_I2SCFGR_I2SMOD         SPI_I2SCFGR_I2SMOD_Msk    /*!< </spirit:description> */
#define SPI_I2SCFGR_ASTRTEN_Pos    (12U)
#define SPI_I2SCFGR_ASTRTEN_Msk    (0x1UL << SPI_I2SCFGR_ASTRTEN_Pos)       /*!< 0x00001000 */
#define SPI_I2SCFGR_ASTRTEN        SPI_I2SCFGR_ASTRTEN_Msk   /*!< </spirit:description> */

/******************  Bit definition for SPI_I2SPR register  *******************/
#define SPI_I2SPR_I2SDIV_Pos       (0U)
#define SPI_I2SPR_I2SDIV_Msk       (0xFFUL << SPI_I2SPR_I2SDIV_Pos)     /*!< 0x000000FF */
#define SPI_I2SPR_I2SDIV           SPI_I2SPR_I2SDIV_Msk      /*!< </spirit:description> */
#define SPI_I2SPR_ODD_Pos          (8U)
#define SPI_I2SPR_ODD_Msk          (0x1UL << SPI_I2SPR_ODD_Pos) /*!< 0x00000100 */
#define SPI_I2SPR_ODD              SPI_I2SPR_ODD_Msk         /*!< </spirit:description> */
#define SPI_I2SPR_MCKOE_Pos        (9U)
#define SPI_I2SPR_MCKOE_Msk        (0x1UL << SPI_I2SPR_MCKOE_Pos)   /*!< 0x00000200 */
#define SPI_I2SPR_MCKOE            SPI_I2SPR_MCKOE_Msk       /*!< </spirit:description> */

#define SPI1_BASE           0x42005C00UL 
#define SPI2_BASE           0x40005C00UL 
#define SPI3_BASE           0x40006000UL 
#define SPI4_BASE           0x42006000UL 

#define SPI1                ((SPI_TypeDef *) SPI1_BASE) 
#define SPI2                ((SPI_TypeDef *) SPI2_BASE) 
#define SPI3                ((SPI_TypeDef *) SPI3_BASE) 
#define SPI4                ((SPI_TypeDef *) SPI4_BASE) 


#endif /* __SR5E1_SPI_H */

