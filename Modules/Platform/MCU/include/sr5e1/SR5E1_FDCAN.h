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

#ifndef __SR5E1_FDCAN_H
#define __SR5E1_FDCAN_H

/******************************************************************************/
/*                                                                            */
/*                               FDCAN (FDCAN)                                */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __I  uint32_t CREL;            /*!< CREL          Address offset: 0x000 */
  __I  uint32_t ENDN;            /*!< ENDN          Address offset: 0x004 */
       uint32_t RESERVED0;       /*!< Reserved      Address offset: 0x008 */
  __IO uint32_t DBTP;            /*!< DBTP          Address offset: 0x00C */
  __IO uint32_t TEST;            /*!< TEST          Address offset: 0x010 */
  __IO uint32_t RWD;             /*!< RWD           Address offset: 0x014 */
  __IO uint32_t CCCR;            /*!< CCCR          Address offset: 0x018 */
  __IO uint32_t NBTP;            /*!< NBTP          Address offset: 0x01C */
  __IO uint32_t TSCC;            /*!< TSCC          Address offset: 0x020 */
  __IO uint32_t TSCV;            /*!< TSCV          Address offset: 0x024 */
  __IO uint32_t TOCC;            /*!< TOCC          Address offset: 0x028 */
  __IO uint32_t TOCV;            /*!< TOCV          Address offset: 0x02C */
       uint32_t RESERVED1[4];    /*!< Reserved      Address offset: 0x030-0x03C */
  __I  uint32_t ECR;             /*!< ECR           Address offset: 0x040 */
  __I  uint32_t PSR;             /*!< PSR           Address offset: 0x044 */
  __IO uint32_t TDCR;            /*!< TDCR          Address offset: 0x048 */
       uint32_t RESERVED2;       /*!< Reserved      Address offset: 0x04C */
  __IO uint32_t IR;              /*!< IR            Address offset: 0x050 */
  __IO uint32_t IE;              /*!< IE            Address offset: 0x054 */
  __IO uint32_t ILS;             /*!< ILS           Address offset: 0x058 */
  __IO uint32_t ILE;             /*!< ILE           Address offset: 0x05C */
       uint32_t RESERVED3[8];    /*!< Reserved      Address offset: 0x060-0x07C */
  __IO uint32_t GFC;             /*!< GFC           Address offset: 0x080 */
  __IO uint32_t SIDFC;           /*!< SIDFC         Address offset: 0x084 */
  __IO uint32_t XIDFC;           /*!< XIDFC         Address offset: 0x088 */
       uint32_t RESERVED4;       /*!< Reserved      Address offset: 0x08C */
  __IO uint32_t XIDAM;           /*!< XIDAM         Address offset: 0x090 */
  __I  uint32_t HPMS;            /*!< HPMS          Address offset: 0x094 */
  __IO uint32_t NDAT1;           /*!< NDAT1         Address offset: 0x098 */
  __IO uint32_t NDAT2;           /*!< NDAT2         Address offset: 0x09C */
  __IO uint32_t RXF0C;           /*!< RXF0C         Address offset: 0x0A0 */
  __I  uint32_t RXF0S;           /*!< RXF0S         Address offset: 0x0A4 */
  __IO uint32_t RXF0A;           /*!< RXF0A         Address offset: 0x0A8 */
  __IO uint32_t RXBC;            /*!< RXBC          Address offset: 0x0AC */
  __IO uint32_t RXF1C;           /*!< RXF1C         Address offset: 0x0B0 */
  __I  uint32_t RXF1S;           /*!< RXF1S         Address offset: 0x0B4 */
  __IO uint32_t RXF1A;           /*!< RXF1A         Address offset: 0x0B8 */
  __IO uint32_t RXESC;           /*!< RXESC         Address offset: 0x0BC */
  __IO uint32_t TXBC;            /*!< TXBC          Address offset: 0x0C0 */
  __I  uint32_t TXFQS;           /*!< TXFQS         Address offset: 0x0C4 */
  __IO uint32_t TXESC;           /*!< TXESC         Address offset: 0x0C8 */
  __I  uint32_t TXBRP;           /*!< TXBRP         Address offset: 0x0CC */
  __IO uint32_t TXBAR;           /*!< TXBAR         Address offset: 0x0D0 */
  __IO uint32_t TXBCR;           /*!< TXBCR         Address offset: 0x0D4 */
  __I  uint32_t TXBTO;           /*!< TXBTO         Address offset: 0x0D8 */
  __I  uint32_t TXBCF;           /*!< TXBCF         Address offset: 0x0DC */
  __IO uint32_t TXBTIE;          /*!< TXBTIE        Address offset: 0x0E0 */
  __IO uint32_t TXBCIE;          /*!< TXBCIE        Address offset: 0x0E4 */
       uint32_t RESERVED5[2];    /*!< Reserved      Address offset: 0x0E8-0x0EC */
  __IO uint32_t TXEFC;           /*!< TXEFC         Address offset: 0x0F0 */
  __I  uint32_t TXEFS;           /*!< TXEFS         Address offset: 0x0F4 */
  __IO uint32_t TXEFA;           /*!< TXEFA         Address offset: 0x0F8 */
       uint32_t RESERVED6[25];   /*!< Reserved      Address offset: 0x0FC-0x15C */
  __I  uint32_t TSU_CREL;        /*!< TSU_CREL      Address offset: 0x160 */
  __I  uint32_t TSU_TSCFG;       /*!< TSU_TSCFG     Address offset: 0x164 */
  __IO uint32_t TSU_TSS1;        /*!< TSU_TSS1      Address offset: 0x168 */
  __I  uint32_t TSU_TSS2;        /*!< TSU_TSS2      Address offset: 0x16C */
  __I  uint32_t TSU_TS[8];      /*!< TSU_TS        Address offset: 0x170-0x18C */
       uint32_t RESERVED7[8];    /*!< Reserved      Address offset: 0x190-0x1AC */
  __I  uint32_t TSU_ATB;         /*!< TSU_ATB       Address offset: 0x1B0 */
       uint32_t RESERVED8[19];   /*!< Reserved      Address offset: 0x1B4-0x1FC */
  __O  uint32_t DMU_TX[18];      /*!< DMU_TX        Address offset: 0x200-0x244 */
       uint32_t RESERVED9[14];   /*!< Reserved      Address offset: 0x248-0x27C */
  __I  uint32_t DMU_RX0[18];     /*!< DMU_RX0       Address offset: 0x280-0x2C4 */
       uint32_t RESERVED10[14];  /*!< Reserved      Address offset: 0x2C8-0x2FC */
  __I  uint32_t DMU_RX1[18];     /*!< DMU_RX1       Address offset: 0x300-0x344 */
       uint32_t RESERVED11[14];  /*!< Reserved      Address offset: 0x348-0x37C */
  __I  uint32_t DMU_TXEVT[3];   /*!< DMU_TXEVT     Address offset: 0x380-0x388 */
       uint32_t RESERVED12[13];  /*!< Reserved      Address offset: 0x38C-0x3BC */
  __I  uint32_t DMU_CR;          /*!< DMU_CR        Address offset: 0x3C0 */
  __IO uint32_t DMU_I;           /*!< DMU_I         Address offset: 0x3C4 */
  __IO uint32_t DMU_QC;          /*!< DMU_QC        Address offset: 0x3C8 */
  __IO uint32_t DMU_IR;          /*!< DMU_IR        Address offset: 0x3CC */
  __IO uint32_t DMU_IE;          /*!< DMU_IE        Address offset: 0x3D0 */
  __I  uint32_t DMU_C;           /*!< DMU_C         Address offset: 0x3D4 */
       uint32_t RESERVED13[10];  /*!< Reserved      Address offset: 0x3D8-0x3FC */
  __I  uint32_t DMU_TX_DBG[18];  /*!< DMU_TX_DBG    Address offset: 0x400-0x444 */
       uint32_t RESERVED14[14];  /*!< Reserved      Address offset: 0x448-0x47C */
  __I  uint32_t DMU_RX0_DBG[18]; /*!< DMU_RX0_DBG   Address offset: 0x480-0x4C4 */
       uint32_t RESERVED15[14];  /*!< Reserved      Address offset: 0x4C8-0x4FC */
  __I  uint32_t DMU_RX1_DBG[18]; /*!< DMU_RX1_DBG   Address offset: 0x500-0x544 */
       uint32_t RESERVED16[14];  /*!< Reserved      Address offset: 0x548-0x57C */
  __I  uint32_t DMU_TXEVT_DBG[3];   /*!< DMU_TXEVT_DBG Address offset: 0x580-0x588 */
} FDCAN_TypeDef;


/******************  Bit definition for FDCAN_CREL register  ******************/
#define FDCAN_CREL_DAY_Pos                (0U)
#define FDCAN_CREL_DAY_Msk                (0xFFUL << FDCAN_CREL_DAY_Pos)      /*!< 0x000000FF */
#define FDCAN_CREL_DAY                    FDCAN_CREL_DAY_Msk                 /*!< </spirit:description> */
#define FDCAN_CREL_TS_MON_Pos             (8U)
#define FDCAN_CREL_TS_MON_Msk             (0xFFUL << FDCAN_CREL_TS_MON_Pos)   /*!< 0x0000FF00 */
#define FDCAN_CREL_TS_MON                 FDCAN_CREL_TS_MON_Msk              /*!< </spirit:description> */
#define FDCAN_CREL_YEAR_Pos               (16U)
#define FDCAN_CREL_YEAR_Msk               (0xFUL << FDCAN_CREL_YEAR_Pos)      /*!< 0x000F0000 */
#define FDCAN_CREL_YEAR                   FDCAN_CREL_YEAR_Msk                /*!< </spirit:description> */
#define FDCAN_CREL_SUBSTEP_Pos            (20U)
#define FDCAN_CREL_SUBSTEP_Msk            (0xFUL << FDCAN_CREL_SUBSTEP_Pos)   /*!< 0x00F00000 */
#define FDCAN_CREL_SUBSTEP                FDCAN_CREL_SUBSTEP_Msk             /*!< </spirit:description> */
#define FDCAN_CREL_STEP_Pos               (24U)
#define FDCAN_CREL_STEP_Msk               (0xFUL << FDCAN_CREL_STEP_Pos)      /*!< 0x0F000000 */
#define FDCAN_CREL_STEP                   FDCAN_CREL_STEP_Msk                /*!< </spirit:description> */
#define FDCAN_CREL_REL_Pos                (28U)
#define FDCAN_CREL_REL_Msk                (0xFUL << FDCAN_CREL_REL_Pos)       /*!< 0xF0000000 */
#define FDCAN_CREL_REL                    FDCAN_CREL_REL_Msk                 /*!< </spirit:description> */

/******************  Bit definition for FDCAN_ENDN register  ******************/
#define FDCAN_ENDN_ETV_Pos                (0U)
#define FDCAN_ENDN_ETV_Msk                (0xFFFFUL << FDCAN_ENDN_ETV_Pos)   /*!< 0x0000FFFF */
#define FDCAN_ENDN_ETV                    FDCAN_ENDN_ETV_Msk                 /*!< </spirit:description> */

/******************  Bit definition for FDCAN_DBTP register  ******************/
#define FDCAN_DBTP_DSJW_Pos               (0U)
#define FDCAN_DBTP_DSJW_Msk               (0xFUL << FDCAN_DBTP_DSJW_Pos)      /*!< 0x0000000F */
#define FDCAN_DBTP_DSJW                   FDCAN_DBTP_DSJW_Msk                /*!< </spirit:description> */
#define FDCAN_DBTP_DTSEG2_Pos             (4U)
#define FDCAN_DBTP_DTSEG2_Msk             (0xFUL << FDCAN_DBTP_DTSEG2_Pos)    /*!< 0x000000F0 */
#define FDCAN_DBTP_DTSEG2                 FDCAN_DBTP_DTSEG2_Msk              /*!< </spirit:description> */
#define FDCAN_DBTP_DTSEG1_Pos             (8U)
#define FDCAN_DBTP_DTSEG1_Msk             (0x1FUL << FDCAN_DBTP_DTSEG1_Pos)   /*!< 0x00001F00 */
#define FDCAN_DBTP_DTSEG1                 FDCAN_DBTP_DTSEG1_Msk              /*!< </spirit:description> */
#define FDCAN_DBTP_DBRP_Pos               (16U)
#define FDCAN_DBTP_DBRP_Msk               (0x1FUL << FDCAN_DBTP_DBRP_Pos)     /*!< 0x001F0000 */
#define FDCAN_DBTP_DBRP                   FDCAN_DBTP_DBRP_Msk                /*!< </spirit:description> */
#define FDCAN_DBTP_TDC_Pos                (23U)
#define FDCAN_DBTP_TDC_Msk                (0x1UL << FDCAN_DBTP_TDC_Pos)       /*!< 0x00800000 */
#define FDCAN_DBTP_TDC                    FDCAN_DBTP_TDC_Msk                 /*!< </spirit:description> */

/******************  Bit definition for FDCAN_TEST register  ******************/
#define FDCAN_TEST_LBCK_Pos               (4U)
#define FDCAN_TEST_LBCK_Msk               (0x1UL << FDCAN_TEST_LBCK_Pos)      /*!< 0x00000010 */
#define FDCAN_TEST_LBCK                   FDCAN_TEST_LBCK_Msk                /*!< </spirit:description> */
#define FDCAN_TEST_TX_Pos                 (5U)
#define FDCAN_TEST_TX_Msk                 (0x3UL << FDCAN_TEST_TX_Pos)        /*!< 0x00000060 */
#define FDCAN_TEST_TX                     FDCAN_TEST_TX_Msk                  /*!< </spirit:description> */
#define FDCAN_TEST_RX_Pos                 (7U)
#define FDCAN_TEST_RX_Msk                 (0x1UL << FDCAN_TEST_RX_Pos)        /*!< 0x00000080 */
#define FDCAN_TEST_RX                     FDCAN_TEST_RX_Msk                  /*!< </spirit:description> */
#define FDCAN_TEST_TXBNP_Pos              (8U)
#define FDCAN_TEST_TXBNP_Msk              (0x1FUL << FDCAN_TEST_TXBNP_Pos)    /*!< 0x00001F00 */
#define FDCAN_TEST_TXBNP                  FDCAN_TEST_TXBNP_Msk               /*!< </spirit:description> */
#define FDCAN_TEST_PVAL_Pos               (13U)
#define FDCAN_TEST_PVAL_Msk               (0x1UL << FDCAN_TEST_PVAL_Pos)      /*!< 0x00002000 */
#define FDCAN_TEST_PVAL                   FDCAN_TEST_PVAL_Msk                /*!< </spirit:description> */
#define FDCAN_TEST_TXBNS_Pos              (16U)
#define FDCAN_TEST_TXBNS_Msk              (0x1FUL << FDCAN_TEST_TXBNS_Pos)    /*!< 0x001F0000 */
#define FDCAN_TEST_TXBNS                  FDCAN_TEST_TXBNS_Msk               /*!< </spirit:description> */
#define FDCAN_TEST_SVAL_Pos               (21U)
#define FDCAN_TEST_SVAL_Msk               (0x1UL << FDCAN_TEST_SVAL_Pos)      /*!< 0x00200000 */
#define FDCAN_TEST_SVAL                   FDCAN_TEST_SVAL_Msk                /*!< </spirit:description> */

/******************  Bit definition for FDCAN_RWD register  *******************/
#define FDCAN_RWD_WDC_Pos                 (0U)
#define FDCAN_RWD_WDC_Msk                 (0xFFUL << FDCAN_RWD_WDC_Pos)       /*!< 0x000000FF */
#define FDCAN_RWD_WDC                     FDCAN_RWD_WDC_Msk                  /*!< </spirit:description> */
#define FDCAN_RWD_WDV_Pos                 (8U)
#define FDCAN_RWD_WDV_Msk                 (0xFFUL << FDCAN_RWD_WDV_Pos)       /*!< 0x0000FF00 */
#define FDCAN_RWD_WDV                     FDCAN_RWD_WDV_Msk                  /*!< </spirit:description> */

/******************  Bit definition for FDCAN_CCCR register  ******************/
#define FDCAN_CCCR_INIT_Pos               (0U)
#define FDCAN_CCCR_INIT_Msk               (0x1UL << FDCAN_CCCR_INIT_Pos)      /*!< 0x00000001 */
#define FDCAN_CCCR_INIT                   FDCAN_CCCR_INIT_Msk                /*!< </spirit:description> */
#define FDCAN_CCCR_CCE_Pos                (1U)
#define FDCAN_CCCR_CCE_Msk                (0x1UL << FDCAN_CCCR_CCE_Pos)       /*!< 0x00000002 */
#define FDCAN_CCCR_CCE                    FDCAN_CCCR_CCE_Msk                 /*!< </spirit:description> */
#define FDCAN_CCCR_ASM_Pos                (2U)
#define FDCAN_CCCR_ASM_Msk                (0x1UL << FDCAN_CCCR_ASM_Pos)       /*!< 0x00000004 */
#define FDCAN_CCCR_ASM                    FDCAN_CCCR_ASM_Msk                 /*!< </spirit:description> */
#define FDCAN_CCCR_CSA_Pos                (3U)
#define FDCAN_CCCR_CSA_Msk                (0x1UL << FDCAN_CCCR_CSA_Pos)       /*!< 0x00000008 */
#define FDCAN_CCCR_CSA                    FDCAN_CCCR_CSA_Msk                 /*!< </spirit:description> */
#define FDCAN_CCCR_CSR_Pos                (4U)
#define FDCAN_CCCR_CSR_Msk                (0x1UL << FDCAN_CCCR_CSR_Pos)       /*!< 0x00000010 */
#define FDCAN_CCCR_CSR                    FDCAN_CCCR_CSR_Msk                 /*!< </spirit:description> */
#define FDCAN_CCCR_MON_Pos                (5U)
#define FDCAN_CCCR_MON_Msk                (0x1UL << FDCAN_CCCR_MON_Pos)       /*!< 0x00000020 */
#define FDCAN_CCCR_MON                    FDCAN_CCCR_MON_Msk                 /*!< </spirit:description> */
#define FDCAN_CCCR_DAR_Pos                (6U)
#define FDCAN_CCCR_DAR_Msk                (0x1UL << FDCAN_CCCR_DAR_Pos)       /*!< 0x00000040 */
#define FDCAN_CCCR_DAR                    FDCAN_CCCR_DAR_Msk                 /*!< </spirit:description> */
#define FDCAN_CCCR_TEST_EN_Pos            (7U)
#define FDCAN_CCCR_TEST_EN_Msk            (0x1UL << FDCAN_CCCR_TEST_EN_Pos)   /*!< 0x00000080 */
#define FDCAN_CCCR_TEST_EN                FDCAN_CCCR_TEST_EN_Msk             /*!< </spirit:description> */
#define FDCAN_CCCR_FDOE_Pos               (8U)
#define FDCAN_CCCR_FDOE_Msk               (0x1UL << FDCAN_CCCR_FDOE_Pos)      /*!< 0x00000100 */
#define FDCAN_CCCR_FDOE                   FDCAN_CCCR_FDOE_Msk                /*!< </spirit:description> */
#define FDCAN_CCCR_BRSE_Pos               (9U)
#define FDCAN_CCCR_BRSE_Msk               (0x1UL << FDCAN_CCCR_BRSE_Pos)      /*!< 0x00000200 */
#define FDCAN_CCCR_BRSE                   FDCAN_CCCR_BRSE_Msk                /*!< </spirit:description> */
#define FDCAN_CCCR_UTSU_Pos               (10U)
#define FDCAN_CCCR_UTSU_Msk               (0x1UL << FDCAN_CCCR_UTSU_Pos)      /*!< 0x00000400 */
#define FDCAN_CCCR_UTSU                   FDCAN_CCCR_UTSU_Msk                /*!< </spirit:description> */
#define FDCAN_CCCR_WMM_Pos                (11U)
#define FDCAN_CCCR_WMM_Msk                (0x1UL << FDCAN_CCCR_WMM_Pos)       /*!< 0x00000800 */
#define FDCAN_CCCR_WMM                    FDCAN_CCCR_WMM_Msk                 /*!< </spirit:description> */
#define FDCAN_CCCR_PXHD_Pos               (12U)
#define FDCAN_CCCR_PXHD_Msk               (0x1UL << FDCAN_CCCR_PXHD_Pos)      /*!< 0x00001000 */
#define FDCAN_CCCR_PXHD                   FDCAN_CCCR_PXHD_Msk                /*!< </spirit:description> */
#define FDCAN_CCCR_EFBI_Pos               (13U)
#define FDCAN_CCCR_EFBI_Msk               (0x1UL << FDCAN_CCCR_EFBI_Pos)      /*!< 0x00002000 */
#define FDCAN_CCCR_EFBI                   FDCAN_CCCR_EFBI_Msk                /*!< </spirit:description> */
#define FDCAN_CCCR_TXP_Pos                (14U)
#define FDCAN_CCCR_TXP_Msk                (0x1UL << FDCAN_CCCR_TXP_Pos)       /*!< 0x00004000 */
#define FDCAN_CCCR_TXP                    FDCAN_CCCR_TXP_Msk                 /*!< </spirit:description> */
#define FDCAN_CCCR_NISO_Pos               (15U)
#define FDCAN_CCCR_NISO_Msk               (0x1UL << FDCAN_CCCR_NISO_Pos)      /*!< 0x00008000 */
#define FDCAN_CCCR_NISO                   FDCAN_CCCR_NISO_Msk                /*!< </spirit:description> */

/******************  Bit definition for FDCAN_NBTP register  ******************/
#define FDCAN_NBTP_NTSEG2_Pos             (0U)
#define FDCAN_NBTP_NTSEG2_Msk             (0x7FUL << FDCAN_NBTP_NTSEG2_Pos)   /*!< 0x0000007F */
#define FDCAN_NBTP_NTSEG2                 FDCAN_NBTP_NTSEG2_Msk              /*!< </spirit:description> */
#define FDCAN_NBTP_NTSEG1_Pos             (8U)
#define FDCAN_NBTP_NTSEG1_Msk             (0xFFUL << FDCAN_NBTP_NTSEG1_Pos)   /*!< 0x0000FF00 */
#define FDCAN_NBTP_NTSEG1                 FDCAN_NBTP_NTSEG1_Msk              /*!< </spirit:description> */
#define FDCAN_NBTP_NBRP_Pos               (16U)
#define FDCAN_NBTP_NBRP_Msk               (0x1FFUL << FDCAN_NBTP_NBRP_Pos)    /*!< 0x01FF0000 */
#define FDCAN_NBTP_NBRP                   FDCAN_NBTP_NBRP_Msk                /*!< </spirit:description> */
#define FDCAN_NBTP_NSJW_Pos               (25U)
#define FDCAN_NBTP_NSJW_Msk               (0x7FUL << FDCAN_NBTP_NSJW_Pos)     /*!< 0xFE000000 */
#define FDCAN_NBTP_NSJW                   FDCAN_NBTP_NSJW_Msk                /*!< </spirit:description> */

/******************  Bit definition for FDCAN_TSCC register  ******************/
#define FDCAN_TSCC_TSS_Pos                (0U)
#define FDCAN_TSCC_TSS_Msk                (0x3UL << FDCAN_TSCC_TSS_Pos)       /*!< 0x00000003 */
#define FDCAN_TSCC_TSS                    FDCAN_TSCC_TSS_Msk                 /*!< </spirit:description> */
#define FDCAN_TSCC_TCP_Pos                (16U)
#define FDCAN_TSCC_TCP_Msk                (0xFUL << FDCAN_TSCC_TCP_Pos)       /*!< 0x000F0000 */
#define FDCAN_TSCC_TCP                    FDCAN_TSCC_TCP_Msk                 /*!< </spirit:description> */

/******************  Bit definition for FDCAN_TSCV register  ******************/
#define FDCAN_TSCV_TSC_Pos                (0U)
#define FDCAN_TSCV_TSC_Msk                (0xFFFFUL << FDCAN_TSCV_TSC_Pos)    /*!< 0x0000FFFF */
#define FDCAN_TSCV_TSC                    FDCAN_TSCV_TSC_Msk                 /*!< </spirit:description> */

/******************  Bit definition for FDCAN_TOCC register  ******************/
#define FDCAN_TOCC_ETOC_Pos               (0U)
#define FDCAN_TOCC_ETOC_Msk               (0x1UL << FDCAN_TOCC_ETOC_Pos)      /*!< 0x00000001 */
#define FDCAN_TOCC_ETOC                   FDCAN_TOCC_ETOC_Msk                /*!< </spirit:description> */
#define FDCAN_TOCC_TOS_Pos                (1U)
#define FDCAN_TOCC_TOS_Msk                (0x3UL << FDCAN_TOCC_TOS_Pos)       /*!< 0x00000006 */
#define FDCAN_TOCC_TOS                    FDCAN_TOCC_TOS_Msk                 /*!< </spirit:description> */
#define FDCAN_TOCC_TOP_Pos                (16U)
#define FDCAN_TOCC_TOP_Msk                (0xFFFFUL << FDCAN_TOCC_TOP_Pos)    /*!< 0xFFFF0000 */
#define FDCAN_TOCC_TOP                    FDCAN_TOCC_TOP_Msk                 /*!< </spirit:description> */

/******************  Bit definition for FDCAN_TOCV register  ******************/
#define FDCAN_TOCV_TOC_Pos                (0U)
#define FDCAN_TOCV_TOC_Msk                (0xFFFFUL << FDCAN_TOCV_TOC_Pos)    /*!< 0x0000FFFF */
#define FDCAN_TOCV_TOC                    FDCAN_TOCV_TOC_Msk                 /*!< </spirit:description> */

/******************  Bit definition for FDCAN_ECR register  *******************/
#define FDCAN_ECR_TEC_Pos                 (0U)
#define FDCAN_ECR_TEC_Msk                 (0xFFUL << FDCAN_ECR_TEC_Pos)       /*!< 0x000000FF */
#define FDCAN_ECR_TEC                     FDCAN_ECR_TEC_Msk                  /*!< </spirit:description> */
#define FDCAN_ECR_REC_Pos                 (8U)
#define FDCAN_ECR_REC_Msk                 (0x7FUL << FDCAN_ECR_REC_Pos)       /*!< 0x00007F00 */
#define FDCAN_ECR_REC                     FDCAN_ECR_REC_Msk                  /*!< </spirit:description> */
#define FDCAN_ECR_RP_Pos                  (15U)
#define FDCAN_ECR_RP_Msk                  (0x1UL << FDCAN_ECR_RP_Pos)         /*!< 0x00008000 */
#define FDCAN_ECR_RP                      FDCAN_ECR_RP_Msk                   /*!< </spirit:description> */
#define FDCAN_ECR_CEL_Pos                 (16U)
#define FDCAN_ECR_CEL_Msk                 (0xFFUL << FDCAN_ECR_CEL_Pos)       /*!< 0x00FF0000 */
#define FDCAN_ECR_CEL                     FDCAN_ECR_CEL_Msk                  /*!< </spirit:description> */

/******************  Bit definition for FDCAN_PSR register  *******************/
#define FDCAN_PSR_LEC_Pos                 (0U)
#define FDCAN_PSR_LEC_Msk                 (0x7UL << FDCAN_PSR_LEC_Pos)        /*!< 0x00000007 */
#define FDCAN_PSR_LEC                     FDCAN_PSR_LEC_Msk                  /*!< </spirit:description> */
#define FDCAN_PSR_ACT_Pos                 (3U)
#define FDCAN_PSR_ACT_Msk                 (0x3UL << FDCAN_PSR_ACT_Pos)        /*!< 0x00000018 */
#define FDCAN_PSR_ACT                     FDCAN_PSR_ACT_Msk                  /*!< </spirit:description> */
#define FDCAN_PSR_EP_Pos                  (5U)
#define FDCAN_PSR_EP_Msk                  (0x1UL << FDCAN_PSR_EP_Pos)         /*!< 0x00000020 */
#define FDCAN_PSR_EP                      FDCAN_PSR_EP_Msk                   /*!< </spirit:description> */
#define FDCAN_PSR_EW_Pos                  (6U)
#define FDCAN_PSR_EW_Msk                  (0x1UL << FDCAN_PSR_EW_Pos)         /*!< 0x00000040 */
#define FDCAN_PSR_EW                      FDCAN_PSR_EW_Msk                   /*!< </spirit:description> */
#define FDCAN_PSR_BO_Pos                  (7U)
#define FDCAN_PSR_BO_Msk                  (0x1UL << FDCAN_PSR_BO_Pos)         /*!< 0x00000080 */
#define FDCAN_PSR_BO                      FDCAN_PSR_BO_Msk                   /*!< </spirit:description> */
#define FDCAN_PSR_DLEC_Pos                (8U)
#define FDCAN_PSR_DLEC_Msk                (0x7UL << FDCAN_PSR_DLEC_Pos)       /*!< 0x00000700 */
#define FDCAN_PSR_DLEC                    FDCAN_PSR_DLEC_Msk                 /*!< </spirit:description> */
#define FDCAN_PSR_RESI_Pos                (11U)
#define FDCAN_PSR_RESI_Msk                (0x1UL << FDCAN_PSR_RESI_Pos)       /*!< 0x00000800 */
#define FDCAN_PSR_RESI                    FDCAN_PSR_RESI_Msk                 /*!< </spirit:description> */
#define FDCAN_PSR_RBRS_Pos                (12U)
#define FDCAN_PSR_RBRS_Msk                (0x1UL << FDCAN_PSR_RBRS_Pos)       /*!< 0x00001000 */
#define FDCAN_PSR_RBRS                    FDCAN_PSR_RBRS_Msk                 /*!< </spirit:description> */
#define FDCAN_PSR_RFDF_Pos                (13U)
#define FDCAN_PSR_RFDF_Msk                (0x1UL << FDCAN_PSR_RFDF_Pos)       /*!< 0x00002000 */
#define FDCAN_PSR_RFDF                    FDCAN_PSR_RFDF_Msk                 /*!< </spirit:description> */
#define FDCAN_PSR_PXE_Pos                 (14U)
#define FDCAN_PSR_PXE_Msk                 (0x1UL << FDCAN_PSR_PXE_Pos)        /*!< 0x00004000 */
#define FDCAN_PSR_PXE                     FDCAN_PSR_PXE_Msk                  /*!< </spirit:description> */
#define FDCAN_PSR_TDCV_Pos                (16U)
#define FDCAN_PSR_TDCV_Msk                (0x7FUL << FDCAN_PSR_TDCV_Pos)      /*!< 0x007F0000 */
#define FDCAN_PSR_TDCV                    FDCAN_PSR_TDCV_Msk                 /*!< </spirit:description> */

/******************  Bit definition for FDCAN_TDCR register  ******************/
#define FDCAN_TDCR_TDCF_Pos               (0U)
#define FDCAN_TDCR_TDCF_Msk               (0x7FUL << FDCAN_TDCR_TDCF_Pos)     /*!< 0x0000007F */
#define FDCAN_TDCR_TDCF                   FDCAN_TDCR_TDCF_Msk                /*!< </spirit:description> */
#define FDCAN_TDCR_TDCO_Pos               (8U)
#define FDCAN_TDCR_TDCO_Msk               (0x7FUL << FDCAN_TDCR_TDCO_Pos)     /*!< 0x00007F00 */
#define FDCAN_TDCR_TDCO                   FDCAN_TDCR_TDCO_Msk                /*!< </spirit:description> */

/*******************  Bit definition for FDCAN_IR register  *******************/
#define FDCAN_IR_RF0N_Pos                 (0U)
#define FDCAN_IR_RF0N_Msk                 (0x1UL << FDCAN_IR_RF0N_Pos)        /*!< 0x00000001 */
#define FDCAN_IR_RF0N                     FDCAN_IR_RF0N_Msk                  /*!< </spirit:description> */
#define FDCAN_IR_RF0W_Pos                 (1U)
#define FDCAN_IR_RF0W_Msk                 (0x1UL << FDCAN_IR_RF0W_Pos)        /*!< 0x00000002 */
#define FDCAN_IR_RF0W                     FDCAN_IR_RF0W_Msk                  /*!< </spirit:description> */
#define FDCAN_IR_RF0F_Pos                 (2U)
#define FDCAN_IR_RF0F_Msk                 (0x1UL << FDCAN_IR_RF0F_Pos)        /*!< 0x00000004 */
#define FDCAN_IR_RF0F                     FDCAN_IR_RF0F_Msk                  /*!< </spirit:description> */
#define FDCAN_IR_RF0L_Pos                 (3U)
#define FDCAN_IR_RF0L_Msk                 (0x1UL << FDCAN_IR_RF0L_Pos)        /*!< 0x00000008 */
#define FDCAN_IR_RF0L                     FDCAN_IR_RF0L_Msk                  /*!< </spirit:description> */
#define FDCAN_IR_RF1N_Pos                 (4U)
#define FDCAN_IR_RF1N_Msk                 (0x1UL << FDCAN_IR_RF1N_Pos)        /*!< 0x00000010 */
#define FDCAN_IR_RF1N                     FDCAN_IR_RF1N_Msk                  /*!< </spirit:description> */
#define FDCAN_IR_RF1W_Pos                 (5U)
#define FDCAN_IR_RF1W_Msk                 (0x1UL << FDCAN_IR_RF1W_Pos)        /*!< 0x00000020 */
#define FDCAN_IR_RF1W                     FDCAN_IR_RF1W_Msk                  /*!< </spirit:description> */
#define FDCAN_IR_RF1F_Pos                 (6U)
#define FDCAN_IR_RF1F_Msk                 (0x1UL << FDCAN_IR_RF1F_Pos)        /*!< 0x00000040 */
#define FDCAN_IR_RF1F                     FDCAN_IR_RF1F_Msk                  /*!< </spirit:description> */
#define FDCAN_IR_RF1L_Pos                 (7U)
#define FDCAN_IR_RF1L_Msk                 (0x1UL << FDCAN_IR_RF1L_Pos)        /*!< 0x00000080 */
#define FDCAN_IR_RF1L                     FDCAN_IR_RF1L_Msk                  /*!< </spirit:description> */
#define FDCAN_IR_HPM_Pos                  (8U)
#define FDCAN_IR_HPM_Msk                  (0x1UL << FDCAN_IR_HPM_Pos)         /*!< 0x00000100 */
#define FDCAN_IR_HPM                      FDCAN_IR_HPM_Msk                   /*!< </spirit:description> */
#define FDCAN_IR_TC_Pos                   (9U)
#define FDCAN_IR_TC_Msk                   (0x1UL << FDCAN_IR_TC_Pos)          /*!< 0x00000200 */
#define FDCAN_IR_TC                       FDCAN_IR_TC_Msk                    /*!< </spirit:description> */
#define FDCAN_IR_TCF_Pos                  (10U)
#define FDCAN_IR_TCF_Msk                  (0x1UL << FDCAN_IR_TCF_Pos)         /*!< 0x00000400 */
#define FDCAN_IR_TCF                      FDCAN_IR_TCF_Msk                   /*!< </spirit:description> */
#define FDCAN_IR_TFE_Pos                  (11U)
#define FDCAN_IR_TFE_Msk                  (0x1UL << FDCAN_IR_TFE_Pos)         /*!< 0x00000800 */
#define FDCAN_IR_TFE                      FDCAN_IR_TFE_Msk                   /*!< </spirit:description> */
#define FDCAN_IR_TEFN_Pos                 (12U)
#define FDCAN_IR_TEFN_Msk                 (0x1UL << FDCAN_IR_TEFN_Pos)        /*!< 0x00001000 */
#define FDCAN_IR_TEFN                     FDCAN_IR_TEFN_Msk                  /*!< </spirit:description> */
#define FDCAN_IR_TEFW_Pos                 (13U)
#define FDCAN_IR_TEFW_Msk                 (0x1UL << FDCAN_IR_TEFW_Pos)        /*!< 0x00002000 */
#define FDCAN_IR_TEFW                     FDCAN_IR_TEFW_Msk                  /*!< </spirit:description> */
#define FDCAN_IR_TEFF_Pos                 (14U)
#define FDCAN_IR_TEFF_Msk                 (0x1UL << FDCAN_IR_TEFF_Pos)        /*!< 0x00004000 */
#define FDCAN_IR_TEFF                     FDCAN_IR_TEFF_Msk                  /*!< </spirit:description> */
#define FDCAN_IR_TEFL_Pos                 (15U)
#define FDCAN_IR_TEFL_Msk                 (0x1UL << FDCAN_IR_TEFL_Pos)        /*!< 0x00008000 */
#define FDCAN_IR_TEFL                     FDCAN_IR_TEFL_Msk                  /*!< </spirit:description> */
#define FDCAN_IR_TSW_Pos                  (16U)
#define FDCAN_IR_TSW_Msk                  (0x1UL << FDCAN_IR_TSW_Pos)         /*!< 0x00010000 */
#define FDCAN_IR_TSW                      FDCAN_IR_TSW_Msk                   /*!< </spirit:description> */
#define FDCAN_IR_MRAF_Pos                 (17U)
#define FDCAN_IR_MRAF_Msk                 (0x1UL << FDCAN_IR_MRAF_Pos)        /*!< 0x00020000 */
#define FDCAN_IR_MRAF                     FDCAN_IR_MRAF_Msk                  /*!< </spirit:description> */
#define FDCAN_IR_TOO_Pos                  (18U)
#define FDCAN_IR_TOO_Msk                  (0x1UL << FDCAN_IR_TOO_Pos)         /*!< 0x00040000 */
#define FDCAN_IR_TOO                      FDCAN_IR_TOO_Msk                   /*!< </spirit:description> */
#define FDCAN_IR_DRX_Pos                  (19U)
#define FDCAN_IR_DRX_Msk                  (0x1UL << FDCAN_IR_DRX_Pos)         /*!< 0x00080000 */
#define FDCAN_IR_DRX                      FDCAN_IR_DRX_Msk                   /*!< </spirit:description> */
#define FDCAN_IR_BEC_Pos                  (20U)
#define FDCAN_IR_BEC_Msk                  (0x1UL << FDCAN_IR_BEC_Pos)         /*!< 0x00100000 */
#define FDCAN_IR_BEC                      FDCAN_IR_BEC_Msk                   /*!< </spirit:description> */
#define FDCAN_IR_BEU_Pos                  (21U)
#define FDCAN_IR_BEU_Msk                  (0x1UL << FDCAN_IR_BEU_Pos)         /*!< 0x00200000 */
#define FDCAN_IR_BEU                      FDCAN_IR_BEU_Msk                   /*!< </spirit:description> */
#define FDCAN_IR_ELO_Pos                  (22U)
#define FDCAN_IR_ELO_Msk                  (0x1UL << FDCAN_IR_ELO_Pos)         /*!< 0x00400000 */
#define FDCAN_IR_ELO                      FDCAN_IR_ELO_Msk                   /*!< </spirit:description> */
#define FDCAN_IR_EP_Pos                   (23U)
#define FDCAN_IR_EP_Msk                   (0x1UL << FDCAN_IR_EP_Pos)          /*!< 0x00800000 */
#define FDCAN_IR_EP                       FDCAN_IR_EP_Msk                    /*!< </spirit:description> */
#define FDCAN_IR_EW_Pos                   (24U)
#define FDCAN_IR_EW_Msk                   (0x1UL << FDCAN_IR_EW_Pos)          /*!< 0x01000000 */
#define FDCAN_IR_EW                       FDCAN_IR_EW_Msk                    /*!< </spirit:description> */
#define FDCAN_IR_BO_Pos                   (25U)
#define FDCAN_IR_BO_Msk                   (0x1UL << FDCAN_IR_BO_Pos)          /*!< 0x02000000 */
#define FDCAN_IR_BO                       FDCAN_IR_BO_Msk                    /*!< </spirit:description> */
#define FDCAN_IR_WDI_Pos                  (26U)
#define FDCAN_IR_WDI_Msk                  (0x1UL << FDCAN_IR_WDI_Pos)         /*!< 0x04000000 */
#define FDCAN_IR_WDI                      FDCAN_IR_WDI_Msk                   /*!< </spirit:description> */
#define FDCAN_IR_PEA_Pos                  (27U)
#define FDCAN_IR_PEA_Msk                  (0x1UL << FDCAN_IR_PEA_Pos)         /*!< 0x08000000 */
#define FDCAN_IR_PEA                      FDCAN_IR_PEA_Msk                   /*!< </spirit:description> */
#define FDCAN_IR_PED_Pos                  (28U)
#define FDCAN_IR_PED_Msk                  (0x1UL << FDCAN_IR_PED_Pos)         /*!< 0x10000000 */
#define FDCAN_IR_PED                      FDCAN_IR_PED_Msk                   /*!< </spirit:description> */
#define FDCAN_IR_ARA_Pos                  (29U)
#define FDCAN_IR_ARA_Msk                  (0x1UL << FDCAN_IR_ARA_Pos)         /*!< 0x20000000 */
#define FDCAN_IR_ARA                      FDCAN_IR_ARA_Msk                   /*!< </spirit:description> */

/*******************  Bit definition for FDCAN_IE register  *******************/
#define FDCAN_IE_RF0NE_Pos                (0U)
#define FDCAN_IE_RF0NE_Msk                (0x1UL << FDCAN_IE_RF0NE_Pos)       /*!< 0x00000001 */
#define FDCAN_IE_RF0NE                    FDCAN_IE_RF0NE_Msk                 /*!< </spirit:description> */
#define FDCAN_IE_RF0WE_Pos                (1U)
#define FDCAN_IE_RF0WE_Msk                (0x1UL << FDCAN_IE_RF0WE_Pos)       /*!< 0x00000002 */
#define FDCAN_IE_RF0WE                    FDCAN_IE_RF0WE_Msk                 /*!< </spirit:description> */
#define FDCAN_IE_RF0FE_Pos                (2U)
#define FDCAN_IE_RF0FE_Msk                (0x1UL << FDCAN_IE_RF0FE_Pos)       /*!< 0x00000004 */
#define FDCAN_IE_RF0FE                    FDCAN_IE_RF0FE_Msk                 /*!< </spirit:description> */
#define FDCAN_IE_RF0LE_Pos                (3U)
#define FDCAN_IE_RF0LE_Msk                (0x1UL << FDCAN_IE_RF0LE_Pos)       /*!< 0x00000008 */
#define FDCAN_IE_RF0LE                    FDCAN_IE_RF0LE_Msk                 /*!< </spirit:description> */
#define FDCAN_IE_RF1NE_Pos                (4U)
#define FDCAN_IE_RF1NE_Msk                (0x1UL << FDCAN_IE_RF1NE_Pos)       /*!< 0x00000010 */
#define FDCAN_IE_RF1NE                    FDCAN_IE_RF1NE_Msk                 /*!< </spirit:description> */
#define FDCAN_IE_RF1WE_Pos                (5U)
#define FDCAN_IE_RF1WE_Msk                (0x1UL << FDCAN_IE_RF1WE_Pos)       /*!< 0x00000020 */
#define FDCAN_IE_RF1WE                    FDCAN_IE_RF1WE_Msk                 /*!< </spirit:description> */
#define FDCAN_IE_RF1FE_Pos                (6U)
#define FDCAN_IE_RF1FE_Msk                (0x1UL << FDCAN_IE_RF1FE_Pos)       /*!< 0x00000040 */
#define FDCAN_IE_RF1FE                    FDCAN_IE_RF1FE_Msk                 /*!< </spirit:description> */
#define FDCAN_IE_RF1LE_Pos                (7U)
#define FDCAN_IE_RF1LE_Msk                (0x1UL << FDCAN_IE_RF1LE_Pos)       /*!< 0x00000080 */
#define FDCAN_IE_RF1LE                    FDCAN_IE_RF1LE_Msk                 /*!< </spirit:description> */
#define FDCAN_IE_HPME_Pos                 (8U)
#define FDCAN_IE_HPME_Msk                 (0x1UL << FDCAN_IE_HPME_Pos)        /*!< 0x00000100 */
#define FDCAN_IE_HPME                     FDCAN_IE_HPME_Msk                  /*!< </spirit:description> */
#define FDCAN_IE_TCE_Pos                  (9U)
#define FDCAN_IE_TCE_Msk                  (0x1UL << FDCAN_IE_TCE_Pos)         /*!< 0x00000200 */
#define FDCAN_IE_TCE                      FDCAN_IE_TCE_Msk                   /*!< </spirit:description> */
#define FDCAN_IE_TCFE_Pos                 (10U)
#define FDCAN_IE_TCFE_Msk                 (0x1UL << FDCAN_IE_TCFE_Pos)        /*!< 0x00000400 */
#define FDCAN_IE_TCFE                     FDCAN_IE_TCFE_Msk                  /*!< </spirit:description> */
#define FDCAN_IE_TFEE_Pos                 (11U)
#define FDCAN_IE_TFEE_Msk                 (0x1UL << FDCAN_IE_TFEE_Pos)        /*!< 0x00000800 */
#define FDCAN_IE_TFEE                     FDCAN_IE_TFEE_Msk                  /*!< </spirit:description> */
#define FDCAN_IE_TEFNE_Pos                (12U)
#define FDCAN_IE_TEFNE_Msk                (0x1UL << FDCAN_IE_TEFNE_Pos)       /*!< 0x00001000 */
#define FDCAN_IE_TEFNE                    FDCAN_IE_TEFNE_Msk                 /*!< </spirit:description> */
#define FDCAN_IE_TEFWE_Pos                (13U)
#define FDCAN_IE_TEFWE_Msk                (0x1UL << FDCAN_IE_TEFWE_Pos)       /*!< 0x00002000 */
#define FDCAN_IE_TEFWE                    FDCAN_IE_TEFWE_Msk                 /*!< </spirit:description> */
#define FDCAN_IE_TEFFE_Pos                (14U)
#define FDCAN_IE_TEFFE_Msk                (0x1UL << FDCAN_IE_TEFFE_Pos)       /*!< 0x00004000 */
#define FDCAN_IE_TEFFE                    FDCAN_IE_TEFFE_Msk                 /*!< </spirit:description> */
#define FDCAN_IE_TEFLE_Pos                (15U)
#define FDCAN_IE_TEFLE_Msk                (0x1UL << FDCAN_IE_TEFLE_Pos)       /*!< 0x00008000 */
#define FDCAN_IE_TEFLE                    FDCAN_IE_TEFLE_Msk                 /*!< </spirit:description> */
#define FDCAN_IE_TSWE_Pos                 (16U)
#define FDCAN_IE_TSWE_Msk                 (0x1UL << FDCAN_IE_TSWE_Pos)        /*!< 0x00010000 */
#define FDCAN_IE_TSWE                     FDCAN_IE_TSWE_Msk                  /*!< </spirit:description> */
#define FDCAN_IE_MRAFE_Pos                (17U)
#define FDCAN_IE_MRAFE_Msk                (0x1UL << FDCAN_IE_MRAFE_Pos)       /*!< 0x00020000 */
#define FDCAN_IE_MRAFE                    FDCAN_IE_MRAFE_Msk                 /*!< </spirit:description> */
#define FDCAN_IE_TOOE_Pos                 (18U)
#define FDCAN_IE_TOOE_Msk                 (0x1UL << FDCAN_IE_TOOE_Pos)        /*!< 0x00040000 */
#define FDCAN_IE_TOOE                     FDCAN_IE_TOOE_Msk                  /*!< </spirit:description> */
#define FDCAN_IE_DRXE_Pos                 (19U)
#define FDCAN_IE_DRXE_Msk                 (0x1UL << FDCAN_IE_DRXE_Pos)        /*!< 0x00080000 */
#define FDCAN_IE_DRXE                     FDCAN_IE_DRXE_Msk                  /*!< </spirit:description> */
#define FDCAN_IE_BECE_Pos                 (20U)
#define FDCAN_IE_BECE_Msk                 (0x1UL << FDCAN_IE_BECE_Pos)        /*!< 0x00100000 */
#define FDCAN_IE_BECE                     FDCAN_IE_BECE_Msk                  /*!< </spirit:description> */
#define FDCAN_IE_BEUE_Pos                 (21U)
#define FDCAN_IE_BEUE_Msk                 (0x1UL << FDCAN_IE_BEUE_Pos)        /*!< 0x00200000 */
#define FDCAN_IE_BEUE                     FDCAN_IE_BEUE_Msk                  /*!< </spirit:description> */
#define FDCAN_IE_ELOE_Pos                 (22U)
#define FDCAN_IE_ELOE_Msk                 (0x1UL << FDCAN_IE_ELOE_Pos)        /*!< 0x00400000 */
#define FDCAN_IE_ELOE                     FDCAN_IE_ELOE_Msk                  /*!< </spirit:description> */
#define FDCAN_IE_EPE_Pos                  (23U)
#define FDCAN_IE_EPE_Msk                  (0x1UL << FDCAN_IE_EPE_Pos)         /*!< 0x00800000 */
#define FDCAN_IE_EPE                      FDCAN_IE_EPE_Msk                   /*!< </spirit:description> */
#define FDCAN_IE_EWE_Pos                  (24U)
#define FDCAN_IE_EWE_Msk                  (0x1UL << FDCAN_IE_EWE_Pos)         /*!< 0x01000000 */
#define FDCAN_IE_EWE                      FDCAN_IE_EWE_Msk                   /*!< </spirit:description> */
#define FDCAN_IE_BOE_Pos                  (25U)
#define FDCAN_IE_BOE_Msk                  (0x1UL << FDCAN_IE_BOE_Pos)         /*!< 0x02000000 */
#define FDCAN_IE_BOE                      FDCAN_IE_BOE_Msk                   /*!< </spirit:description> */
#define FDCAN_IE_WDIE_Pos                 (26U)
#define FDCAN_IE_WDIE_Msk                 (0x1UL << FDCAN_IE_WDIE_Pos)        /*!< 0x04000000 */
#define FDCAN_IE_WDIE                     FDCAN_IE_WDIE_Msk                  /*!< </spirit:description> */
#define FDCAN_IE_PEAE_Pos                 (27U)
#define FDCAN_IE_PEAE_Msk                 (0x1UL << FDCAN_IE_PEAE_Pos)        /*!< 0x08000000 */
#define FDCAN_IE_PEAE                     FDCAN_IE_PEAE_Msk                  /*!< </spirit:description> */
#define FDCAN_IE_PEDE_Pos                 (28U)
#define FDCAN_IE_PEDE_Msk                 (0x1UL << FDCAN_IE_PEDE_Pos)        /*!< 0x10000000 */
#define FDCAN_IE_PEDE                     FDCAN_IE_PEDE_Msk                  /*!< </spirit:description> */
#define FDCAN_IE_ARAE_Pos                 (29U)
#define FDCAN_IE_ARAE_Msk                 (0x1UL << FDCAN_IE_ARAE_Pos)        /*!< 0x20000000 */
#define FDCAN_IE_ARAE                     FDCAN_IE_ARAE_Msk                  /*!< </spirit:description> */

/******************  Bit definition for FDCAN_ILS register  *******************/
#define FDCAN_ILS_RF0NL_Pos               (0U)
#define FDCAN_ILS_RF0NL_Msk               (0x1UL << FDCAN_ILS_RF0NL_Pos)      /*!< 0x00000001 */
#define FDCAN_ILS_RF0NL                   FDCAN_ILS_RF0NL_Msk                /*!< </spirit:description> */
#define FDCAN_ILS_RF0WL_Pos               (1U)
#define FDCAN_ILS_RF0WL_Msk               (0x1UL << FDCAN_ILS_RF0WL_Pos)      /*!< 0x00000002 */
#define FDCAN_ILS_RF0WL                   FDCAN_ILS_RF0WL_Msk                /*!< </spirit:description> */
#define FDCAN_ILS_RF0FL_Pos               (2U)
#define FDCAN_ILS_RF0FL_Msk               (0x1UL << FDCAN_ILS_RF0FL_Pos)      /*!< 0x00000004 */
#define FDCAN_ILS_RF0FL                   FDCAN_ILS_RF0FL_Msk                /*!< </spirit:description> */
#define FDCAN_ILS_RF0LL_Pos               (3U)
#define FDCAN_ILS_RF0LL_Msk               (0x1UL << FDCAN_ILS_RF0LL_Pos)      /*!< 0x00000008 */
#define FDCAN_ILS_RF0LL                   FDCAN_ILS_RF0LL_Msk                /*!< </spirit:description> */
#define FDCAN_ILS_RF1NL_Pos               (4U)
#define FDCAN_ILS_RF1NL_Msk               (0x1UL << FDCAN_ILS_RF1NL_Pos)      /*!< 0x00000010 */
#define FDCAN_ILS_RF1NL                   FDCAN_ILS_RF1NL_Msk                /*!< </spirit:description> */
#define FDCAN_ILS_RF1WL_Pos               (5U)
#define FDCAN_ILS_RF1WL_Msk               (0x1UL << FDCAN_ILS_RF1WL_Pos)      /*!< 0x00000020 */
#define FDCAN_ILS_RF1WL                   FDCAN_ILS_RF1WL_Msk                /*!< </spirit:description> */
#define FDCAN_ILS_RF1FL_Pos               (6U)
#define FDCAN_ILS_RF1FL_Msk               (0x1UL << FDCAN_ILS_RF1FL_Pos)      /*!< 0x00000040 */
#define FDCAN_ILS_RF1FL                   FDCAN_ILS_RF1FL_Msk                /*!< </spirit:description> */
#define FDCAN_ILS_RF1LL_Pos               (7U)
#define FDCAN_ILS_RF1LL_Msk               (0x1UL << FDCAN_ILS_RF1LL_Pos)      /*!< 0x00000080 */
#define FDCAN_ILS_RF1LL                   FDCAN_ILS_RF1LL_Msk                /*!< </spirit:description> */
#define FDCAN_ILS_HPML_Pos                (8U)
#define FDCAN_ILS_HPML_Msk                (0x1UL << FDCAN_ILS_HPML_Pos)       /*!< 0x00000100 */
#define FDCAN_ILS_HPML                    FDCAN_ILS_HPML_Msk                 /*!< </spirit:description> */
#define FDCAN_ILS_TCL_Pos                 (9U)
#define FDCAN_ILS_TCL_Msk                 (0x1UL << FDCAN_ILS_TCL_Pos)        /*!< 0x00000200 */
#define FDCAN_ILS_TCL                     FDCAN_ILS_TCL_Msk                  /*!< </spirit:description> */
#define FDCAN_ILS_TCFL_Pos                (10U)
#define FDCAN_ILS_TCFL_Msk                (0x1UL << FDCAN_ILS_TCFL_Pos)       /*!< 0x00000400 */
#define FDCAN_ILS_TCFL                    FDCAN_ILS_TCFL_Msk                 /*!< </spirit:description> */
#define FDCAN_ILS_TFEL_Pos                (11U)
#define FDCAN_ILS_TFEL_Msk                (0x1UL << FDCAN_ILS_TFEL_Pos)       /*!< 0x00000800 */
#define FDCAN_ILS_TFEL                    FDCAN_ILS_TFEL_Msk                 /*!< </spirit:description> */
#define FDCAN_ILS_TEFNL_Pos               (12U)
#define FDCAN_ILS_TEFNL_Msk               (0x1UL << FDCAN_ILS_TEFNL_Pos)      /*!< 0x00001000 */
#define FDCAN_ILS_TEFNL                   FDCAN_ILS_TEFNL_Msk                /*!< </spirit:description> */
#define FDCAN_ILS_TEFWL_Pos               (13U)
#define FDCAN_ILS_TEFWL_Msk               (0x1UL << FDCAN_ILS_TEFWL_Pos)      /*!< 0x00002000 */
#define FDCAN_ILS_TEFWL                   FDCAN_ILS_TEFWL_Msk                /*!< </spirit:description> */
#define FDCAN_ILS_TEFFL_Pos               (14U)
#define FDCAN_ILS_TEFFL_Msk               (0x1UL << FDCAN_ILS_TEFFL_Pos)      /*!< 0x00004000 */
#define FDCAN_ILS_TEFFL                   FDCAN_ILS_TEFFL_Msk                /*!< </spirit:description> */
#define FDCAN_ILS_TEFLL_Pos               (15U)
#define FDCAN_ILS_TEFLL_Msk               (0x1UL << FDCAN_ILS_TEFLL_Pos)      /*!< 0x00008000 */
#define FDCAN_ILS_TEFLL                   FDCAN_ILS_TEFLL_Msk                /*!< </spirit:description> */
#define FDCAN_ILS_TSWL_Pos                (16U)
#define FDCAN_ILS_TSWL_Msk                (0x1UL << FDCAN_ILS_TSWL_Pos)       /*!< 0x00010000 */
#define FDCAN_ILS_TSWL                    FDCAN_ILS_TSWL_Msk                 /*!< </spirit:description> */
#define FDCAN_ILS_MRAFL_Pos               (17U)
#define FDCAN_ILS_MRAFL_Msk               (0x1UL << FDCAN_ILS_MRAFL_Pos)      /*!< 0x00020000 */
#define FDCAN_ILS_MRAFL                   FDCAN_ILS_MRAFL_Msk                /*!< </spirit:description> */
#define FDCAN_ILS_TOOL_Pos                (18U)
#define FDCAN_ILS_TOOL_Msk                (0x1UL << FDCAN_ILS_TOOL_Pos)       /*!< 0x00040000 */
#define FDCAN_ILS_TOOL                    FDCAN_ILS_TOOL_Msk                 /*!< </spirit:description> */
#define FDCAN_ILS_DRXL_Pos                (19U)
#define FDCAN_ILS_DRXL_Msk                (0x1UL << FDCAN_ILS_DRXL_Pos)       /*!< 0x00080000 */
#define FDCAN_ILS_DRXL                    FDCAN_ILS_DRXL_Msk                 /*!< </spirit:description> */
#define FDCAN_ILS_BECL_Pos                (20U)
#define FDCAN_ILS_BECL_Msk                (0x1UL << FDCAN_ILS_BECL_Pos)       /*!< 0x00100000 */
#define FDCAN_ILS_BECL                    FDCAN_ILS_BECL_Msk                 /*!< </spirit:description> */
#define FDCAN_ILS_BEUL_Pos                (21U)
#define FDCAN_ILS_BEUL_Msk                (0x1UL << FDCAN_ILS_BEUL_Pos)       /*!< 0x00200000 */
#define FDCAN_ILS_BEUL                    FDCAN_ILS_BEUL_Msk                 /*!< </spirit:description> */
#define FDCAN_ILS_ELOL_Pos                (22U)
#define FDCAN_ILS_ELOL_Msk                (0x1UL << FDCAN_ILS_ELOL_Pos)       /*!< 0x00400000 */
#define FDCAN_ILS_ELOL                    FDCAN_ILS_ELOL_Msk                 /*!< </spirit:description> */
#define FDCAN_ILS_EPL_Pos                 (23U)
#define FDCAN_ILS_EPL_Msk                 (0x1UL << FDCAN_ILS_EPL_Pos)        /*!< 0x00800000 */
#define FDCAN_ILS_EPL                     FDCAN_ILS_EPL_Msk                  /*!< </spirit:description> */
#define FDCAN_ILS_EWL_Pos                 (24U)
#define FDCAN_ILS_EWL_Msk                 (0x1UL << FDCAN_ILS_EWL_Pos)        /*!< 0x01000000 */
#define FDCAN_ILS_EWL                     FDCAN_ILS_EWL_Msk                  /*!< </spirit:description> */
#define FDCAN_ILS_BOL_Pos                 (25U)
#define FDCAN_ILS_BOL_Msk                 (0x1UL << FDCAN_ILS_BOL_Pos)        /*!< 0x02000000 */
#define FDCAN_ILS_BOL                     FDCAN_ILS_BOL_Msk                  /*!< </spirit:description> */
#define FDCAN_ILS_WDIL_Pos                (26U)
#define FDCAN_ILS_WDIL_Msk                (0x1UL << FDCAN_ILS_WDIL_Pos)       /*!< 0x04000000 */
#define FDCAN_ILS_WDIL                    FDCAN_ILS_WDIL_Msk                 /*!< </spirit:description> */
#define FDCAN_ILS_PEAL_Pos                (27U)
#define FDCAN_ILS_PEAL_Msk                (0x1UL << FDCAN_ILS_PEAL_Pos)       /*!< 0x08000000 */
#define FDCAN_ILS_PEAL                    FDCAN_ILS_PEAL_Msk                 /*!< </spirit:description> */
#define FDCAN_ILS_PEDL_Pos                (28U)
#define FDCAN_ILS_PEDL_Msk                (0x1UL << FDCAN_ILS_PEDL_Pos)       /*!< 0x10000000 */
#define FDCAN_ILS_PEDL                    FDCAN_ILS_PEDL_Msk                 /*!< </spirit:description> */
#define FDCAN_ILS_ARAL_Pos                (29U)
#define FDCAN_ILS_ARAL_Msk                (0x1UL << FDCAN_ILS_ARAL_Pos)       /*!< 0x20000000 */
#define FDCAN_ILS_ARAL                    FDCAN_ILS_ARAL_Msk                 /*!< </spirit:description> */

/******************  Bit definition for FDCAN_ILE register  *******************/
#define FDCAN_ILE_EINT0_Pos               (0U)
#define FDCAN_ILE_EINT0_Msk               (0x1UL << FDCAN_ILE_EINT0_Pos)      /*!< 0x00000001 */
#define FDCAN_ILE_EINT0                   FDCAN_ILE_EINT0_Msk                /*!< </spirit:description> */
#define FDCAN_ILE_EINT1_Pos               (1U)
#define FDCAN_ILE_EINT1_Msk               (0x1UL << FDCAN_ILE_EINT1_Pos)      /*!< 0x00000002 */
#define FDCAN_ILE_EINT1                   FDCAN_ILE_EINT1_Msk                /*!< </spirit:description> */

/******************  Bit definition for FDCAN_GFC register  *******************/
#define FDCAN_GFC_RRFE_Pos                (0U)
#define FDCAN_GFC_RRFE_Msk                (0x1UL << FDCAN_GFC_RRFE_Pos)       /*!< 0x00000001 */
#define FDCAN_GFC_RRFE                    FDCAN_GFC_RRFE_Msk                 /*!< </spirit:description> */
#define FDCAN_GFC_RRFS_Pos                (1U)
#define FDCAN_GFC_RRFS_Msk                (0x1UL << FDCAN_GFC_RRFS_Pos)       /*!< 0x00000002 */
#define FDCAN_GFC_RRFS                    FDCAN_GFC_RRFS_Msk                 /*!< </spirit:description> */
#define FDCAN_GFC_ANFE_Pos                (2U)
#define FDCAN_GFC_ANFE_Msk                (0x3UL << FDCAN_GFC_ANFE_Pos)       /*!< 0x0000000C */
#define FDCAN_GFC_ANFE                    FDCAN_GFC_ANFE_Msk                 /*!< </spirit:description> */
#define FDCAN_GFC_ANFS_Pos                (4U)
#define FDCAN_GFC_ANFS_Msk                (0x3UL << FDCAN_GFC_ANFS_Pos)       /*!< 0x00000030 */
#define FDCAN_GFC_ANFS                    FDCAN_GFC_ANFS_Msk                 /*!< </spirit:description> */

/*****************  Bit definition for FDCAN_SIDFC register  ******************/
#define FDCAN_SIDFC_FLSSA_Pos             (2U)
#define FDCAN_SIDFC_FLSSA_Msk             (0x3FFFUL << FDCAN_SIDFC_FLSSA_Pos) /*!< 0x0000FFFC */
#define FDCAN_SIDFC_FLSSA                 FDCAN_SIDFC_FLSSA_Msk              /*!< </spirit:description> */
#define FDCAN_SIDFC_LSS_Pos               (16U)
#define FDCAN_SIDFC_LSS_Msk               (0xFFUL << FDCAN_SIDFC_LSS_Pos)     /*!< 0x00FF0000 */
#define FDCAN_SIDFC_LSS                   FDCAN_SIDFC_LSS_Msk                /*!< </spirit:description> */

/*****************  Bit definition for FDCAN_XIDFC register  ******************/
#define FDCAN_XIDFC_FLESA_Pos             (2U)
#define FDCAN_XIDFC_FLESA_Msk             (0x3FFFUL << FDCAN_XIDFC_FLESA_Pos) /*!< 0x0000FFFC */
#define FDCAN_XIDFC_FLESA                 FDCAN_XIDFC_FLESA_Msk              /*!< </spirit:description> */
#define FDCAN_XIDFC_LSE_Pos               (16U)
#define FDCAN_XIDFC_LSE_Msk               (0xFFUL << FDCAN_XIDFC_LSE_Pos)     /*!< 0x00FF0000 */
#define FDCAN_XIDFC_LSE                   FDCAN_XIDFC_LSE_Msk                /*!< </spirit:description> */

/*****************  Bit definition for FDCAN_XIDAM register  ******************/
#define FDCAN_XIDAM_EIDM_Pos              (0U)
#define FDCAN_XIDAM_EIDM_Msk              (0x1FFFFFFFUL << FDCAN_XIDAM_EIDM_Pos)  /*!< 0x1FFFFFFF */
#define FDCAN_XIDAM_EIDM                  FDCAN_XIDAM_EIDM_Msk               /*!< </spirit:description> */

/******************  Bit definition for FDCAN_HPMS register  ******************/
#define FDCAN_HPMS_BIDX_Pos               (0U)
#define FDCAN_HPMS_BIDX_Msk               (0x3FUL << FDCAN_HPMS_BIDX_Pos)     /*!< 0x0000003F */
#define FDCAN_HPMS_BIDX                   FDCAN_HPMS_BIDX_Msk                /*!< </spirit:description> */
#define FDCAN_HPMS_MSI_Pos                (6U)
#define FDCAN_HPMS_MSI_Msk                (0x3UL << FDCAN_HPMS_MSI_Pos)       /*!< 0x000000C0 */
#define FDCAN_HPMS_MSI                    FDCAN_HPMS_MSI_Msk                 /*!< </spirit:description> */
#define FDCAN_HPMS_FIDX_Pos               (8U)
#define FDCAN_HPMS_FIDX_Msk               (0x7FUL << FDCAN_HPMS_FIDX_Pos)     /*!< 0x00007F00 */
#define FDCAN_HPMS_FIDX                   FDCAN_HPMS_FIDX_Msk                /*!< </spirit:description> */
#define FDCAN_HPMS_FLST_Pos               (15U)
#define FDCAN_HPMS_FLST_Msk               (0x1UL << FDCAN_HPMS_FLST_Pos)      /*!< 0x00008000 */
#define FDCAN_HPMS_FLST                   FDCAN_HPMS_FLST_Msk                /*!< </spirit:description> */

/*****************  Bit definition for FDCAN_NDAT1 register  ******************/
#define FDCAN_NDAT1_ND0_Pos               (0U)
#define FDCAN_NDAT1_ND0_Msk               (0x1UL << FDCAN_NDAT1_ND0_Pos)      /*!< 0x00000001 */
#define FDCAN_NDAT1_ND0                   FDCAN_NDAT1_ND0_Msk                /*!< </spirit:description> */
#define FDCAN_NDAT1_ND1_Pos               (1U)
#define FDCAN_NDAT1_ND1_Msk               (0x1UL << FDCAN_NDAT1_ND1_Pos)      /*!< 0x00000002 */
#define FDCAN_NDAT1_ND1                   FDCAN_NDAT1_ND1_Msk                /*!< </spirit:description> */
#define FDCAN_NDAT1_ND2_Pos               (2U)
#define FDCAN_NDAT1_ND2_Msk               (0x1UL << FDCAN_NDAT1_ND2_Pos)      /*!< 0x00000004 */
#define FDCAN_NDAT1_ND2                   FDCAN_NDAT1_ND2_Msk                /*!< </spirit:description> */
#define FDCAN_NDAT1_ND3_Pos               (3U)
#define FDCAN_NDAT1_ND3_Msk               (0x1UL << FDCAN_NDAT1_ND3_Pos)      /*!< 0x00000008 */
#define FDCAN_NDAT1_ND3                   FDCAN_NDAT1_ND3_Msk                /*!< </spirit:description> */
#define FDCAN_NDAT1_ND4_Pos               (4U)
#define FDCAN_NDAT1_ND4_Msk               (0x1UL << FDCAN_NDAT1_ND4_Pos)      /*!< 0x00000010 */
#define FDCAN_NDAT1_ND4                   FDCAN_NDAT1_ND4_Msk                /*!< </spirit:description> */
#define FDCAN_NDAT1_ND5_Pos               (5U)
#define FDCAN_NDAT1_ND5_Msk               (0x1UL << FDCAN_NDAT1_ND5_Pos)      /*!< 0x00000020 */
#define FDCAN_NDAT1_ND5                   FDCAN_NDAT1_ND5_Msk                /*!< </spirit:description> */
#define FDCAN_NDAT1_ND6_Pos               (6U)
#define FDCAN_NDAT1_ND6_Msk               (0x1UL << FDCAN_NDAT1_ND6_Pos)      /*!< 0x00000040 */
#define FDCAN_NDAT1_ND6                   FDCAN_NDAT1_ND6_Msk                /*!< </spirit:description> */
#define FDCAN_NDAT1_ND7_Pos               (7U)
#define FDCAN_NDAT1_ND7_Msk               (0x1UL << FDCAN_NDAT1_ND7_Pos)      /*!< 0x00000080 */
#define FDCAN_NDAT1_ND7                   FDCAN_NDAT1_ND7_Msk                /*!< </spirit:description> */
#define FDCAN_NDAT1_ND8_Pos               (8U)
#define FDCAN_NDAT1_ND8_Msk               (0x1UL << FDCAN_NDAT1_ND8_Pos)      /*!< 0x00000100 */
#define FDCAN_NDAT1_ND8                   FDCAN_NDAT1_ND8_Msk                /*!< </spirit:description> */
#define FDCAN_NDAT1_ND9_Pos               (9U)
#define FDCAN_NDAT1_ND9_Msk               (0x1UL << FDCAN_NDAT1_ND9_Pos)      /*!< 0x00000200 */
#define FDCAN_NDAT1_ND9                   FDCAN_NDAT1_ND9_Msk                /*!< </spirit:description> */
#define FDCAN_NDAT1_ND10_Pos              (10U)
#define FDCAN_NDAT1_ND10_Msk              (0x1UL << FDCAN_NDAT1_ND10_Pos)     /*!< 0x00000400 */
#define FDCAN_NDAT1_ND10                  FDCAN_NDAT1_ND10_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT1_ND11_Pos              (11U)
#define FDCAN_NDAT1_ND11_Msk              (0x1UL << FDCAN_NDAT1_ND11_Pos)     /*!< 0x00000800 */
#define FDCAN_NDAT1_ND11                  FDCAN_NDAT1_ND11_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT1_ND12_Pos              (12U)
#define FDCAN_NDAT1_ND12_Msk              (0x1UL << FDCAN_NDAT1_ND12_Pos)     /*!< 0x00001000 */
#define FDCAN_NDAT1_ND12                  FDCAN_NDAT1_ND12_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT1_ND13_Pos              (13U)
#define FDCAN_NDAT1_ND13_Msk              (0x1UL << FDCAN_NDAT1_ND13_Pos)     /*!< 0x00002000 */
#define FDCAN_NDAT1_ND13                  FDCAN_NDAT1_ND13_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT1_ND14_Pos              (14U)
#define FDCAN_NDAT1_ND14_Msk              (0x1UL << FDCAN_NDAT1_ND14_Pos)     /*!< 0x00004000 */
#define FDCAN_NDAT1_ND14                  FDCAN_NDAT1_ND14_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT1_ND15_Pos              (15U)
#define FDCAN_NDAT1_ND15_Msk              (0x1UL << FDCAN_NDAT1_ND15_Pos)     /*!< 0x00008000 */
#define FDCAN_NDAT1_ND15                  FDCAN_NDAT1_ND15_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT1_ND16_Pos              (16U)
#define FDCAN_NDAT1_ND16_Msk              (0x1UL << FDCAN_NDAT1_ND16_Pos)     /*!< 0x00010000 */
#define FDCAN_NDAT1_ND16                  FDCAN_NDAT1_ND16_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT1_ND17_Pos              (17U)
#define FDCAN_NDAT1_ND17_Msk              (0x1UL << FDCAN_NDAT1_ND17_Pos)     /*!< 0x00020000 */
#define FDCAN_NDAT1_ND17                  FDCAN_NDAT1_ND17_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT1_ND18_Pos              (18U)
#define FDCAN_NDAT1_ND18_Msk              (0x1UL << FDCAN_NDAT1_ND18_Pos)     /*!< 0x00040000 */
#define FDCAN_NDAT1_ND18                  FDCAN_NDAT1_ND18_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT1_ND19_Pos              (19U)
#define FDCAN_NDAT1_ND19_Msk              (0x1UL << FDCAN_NDAT1_ND19_Pos)     /*!< 0x00080000 */
#define FDCAN_NDAT1_ND19                  FDCAN_NDAT1_ND19_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT1_ND20_Pos              (20U)
#define FDCAN_NDAT1_ND20_Msk              (0x1UL << FDCAN_NDAT1_ND20_Pos)     /*!< 0x00100000 */
#define FDCAN_NDAT1_ND20                  FDCAN_NDAT1_ND20_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT1_ND21_Pos              (21U)
#define FDCAN_NDAT1_ND21_Msk              (0x1UL << FDCAN_NDAT1_ND21_Pos)     /*!< 0x00200000 */
#define FDCAN_NDAT1_ND21                  FDCAN_NDAT1_ND21_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT1_ND22_Pos              (22U)
#define FDCAN_NDAT1_ND22_Msk              (0x1UL << FDCAN_NDAT1_ND22_Pos)     /*!< 0x00400000 */
#define FDCAN_NDAT1_ND22                  FDCAN_NDAT1_ND22_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT1_ND23_Pos              (23U)
#define FDCAN_NDAT1_ND23_Msk              (0x1UL << FDCAN_NDAT1_ND23_Pos)     /*!< 0x00800000 */
#define FDCAN_NDAT1_ND23                  FDCAN_NDAT1_ND23_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT1_ND24_Pos              (24U)
#define FDCAN_NDAT1_ND24_Msk              (0x1UL << FDCAN_NDAT1_ND24_Pos)     /*!< 0x01000000 */
#define FDCAN_NDAT1_ND24                  FDCAN_NDAT1_ND24_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT1_ND25_Pos              (25U)
#define FDCAN_NDAT1_ND25_Msk              (0x1UL << FDCAN_NDAT1_ND25_Pos)     /*!< 0x02000000 */
#define FDCAN_NDAT1_ND25                  FDCAN_NDAT1_ND25_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT1_ND26_Pos              (26U)
#define FDCAN_NDAT1_ND26_Msk              (0x1UL << FDCAN_NDAT1_ND26_Pos)     /*!< 0x04000000 */
#define FDCAN_NDAT1_ND26                  FDCAN_NDAT1_ND26_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT1_ND27_Pos              (27U)
#define FDCAN_NDAT1_ND27_Msk              (0x1UL << FDCAN_NDAT1_ND27_Pos)     /*!< 0x08000000 */
#define FDCAN_NDAT1_ND27                  FDCAN_NDAT1_ND27_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT1_ND28_Pos              (28U)
#define FDCAN_NDAT1_ND28_Msk              (0x1UL << FDCAN_NDAT1_ND28_Pos)     /*!< 0x10000000 */
#define FDCAN_NDAT1_ND28                  FDCAN_NDAT1_ND28_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT1_ND29_Pos              (29U)
#define FDCAN_NDAT1_ND29_Msk              (0x1UL << FDCAN_NDAT1_ND29_Pos)     /*!< 0x20000000 */
#define FDCAN_NDAT1_ND29                  FDCAN_NDAT1_ND29_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT1_ND30_Pos              (30U)
#define FDCAN_NDAT1_ND30_Msk              (0x1UL << FDCAN_NDAT1_ND30_Pos)     /*!< 0x40000000 */
#define FDCAN_NDAT1_ND30                  FDCAN_NDAT1_ND30_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT1_ND31_Pos              (31U)
#define FDCAN_NDAT1_ND31_Msk              (0x1UL << FDCAN_NDAT1_ND31_Pos)     /*!< 0x80000000 */
#define FDCAN_NDAT1_ND31                  FDCAN_NDAT1_ND31_Msk               /*!< </spirit:description> */

/*****************  Bit definition for FDCAN_NDAT2 register  ******************/
#define FDCAN_NDAT2_ND32_Pos              (0U)
#define FDCAN_NDAT2_ND32_Msk              (0x1UL << FDCAN_NDAT2_ND32_Pos)     /*!< 0x00000001 */
#define FDCAN_NDAT2_ND32                  FDCAN_NDAT2_ND32_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT2_ND33_Pos              (1U)
#define FDCAN_NDAT2_ND33_Msk              (0x1UL << FDCAN_NDAT2_ND33_Pos)     /*!< 0x00000002 */
#define FDCAN_NDAT2_ND33                  FDCAN_NDAT2_ND33_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT2_ND34_Pos              (2U)
#define FDCAN_NDAT2_ND34_Msk              (0x1UL << FDCAN_NDAT2_ND34_Pos)     /*!< 0x00000004 */
#define FDCAN_NDAT2_ND34                  FDCAN_NDAT2_ND34_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT2_ND35_Pos              (3U)
#define FDCAN_NDAT2_ND35_Msk              (0x1UL << FDCAN_NDAT2_ND35_Pos)     /*!< 0x00000008 */
#define FDCAN_NDAT2_ND35                  FDCAN_NDAT2_ND35_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT2_ND36_Pos              (4U)
#define FDCAN_NDAT2_ND36_Msk              (0x1UL << FDCAN_NDAT2_ND36_Pos)     /*!< 0x00000010 */
#define FDCAN_NDAT2_ND36                  FDCAN_NDAT2_ND36_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT2_ND37_Pos              (5U)
#define FDCAN_NDAT2_ND37_Msk              (0x1UL << FDCAN_NDAT2_ND37_Pos)     /*!< 0x00000020 */
#define FDCAN_NDAT2_ND37                  FDCAN_NDAT2_ND37_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT2_ND38_Pos              (6U)
#define FDCAN_NDAT2_ND38_Msk              (0x1UL << FDCAN_NDAT2_ND38_Pos)     /*!< 0x00000040 */
#define FDCAN_NDAT2_ND38                  FDCAN_NDAT2_ND38_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT2_ND39_Pos              (7U)
#define FDCAN_NDAT2_ND39_Msk              (0x1UL << FDCAN_NDAT2_ND39_Pos)     /*!< 0x00000080 */
#define FDCAN_NDAT2_ND39                  FDCAN_NDAT2_ND39_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT2_ND40_Pos              (8U)
#define FDCAN_NDAT2_ND40_Msk              (0x1UL << FDCAN_NDAT2_ND40_Pos)     /*!< 0x00000100 */
#define FDCAN_NDAT2_ND40                  FDCAN_NDAT2_ND40_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT2_ND41_Pos              (9U)
#define FDCAN_NDAT2_ND41_Msk              (0x1UL << FDCAN_NDAT2_ND41_Pos)     /*!< 0x00000200 */
#define FDCAN_NDAT2_ND41                  FDCAN_NDAT2_ND41_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT2_ND42_Pos              (10U)
#define FDCAN_NDAT2_ND42_Msk              (0x1UL << FDCAN_NDAT2_ND42_Pos)     /*!< 0x00000400 */
#define FDCAN_NDAT2_ND42                  FDCAN_NDAT2_ND42_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT2_ND43_Pos              (11U)
#define FDCAN_NDAT2_ND43_Msk              (0x1UL << FDCAN_NDAT2_ND43_Pos)     /*!< 0x00000800 */
#define FDCAN_NDAT2_ND43                  FDCAN_NDAT2_ND43_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT2_ND44_Pos              (12U)
#define FDCAN_NDAT2_ND44_Msk              (0x1UL << FDCAN_NDAT2_ND44_Pos)     /*!< 0x00001000 */
#define FDCAN_NDAT2_ND44                  FDCAN_NDAT2_ND44_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT2_ND45_Pos              (13U)
#define FDCAN_NDAT2_ND45_Msk              (0x1UL << FDCAN_NDAT2_ND45_Pos)     /*!< 0x00002000 */
#define FDCAN_NDAT2_ND45                  FDCAN_NDAT2_ND45_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT2_ND46_Pos              (14U)
#define FDCAN_NDAT2_ND46_Msk              (0x1UL << FDCAN_NDAT2_ND46_Pos)     /*!< 0x00004000 */
#define FDCAN_NDAT2_ND46                  FDCAN_NDAT2_ND46_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT2_ND47_Pos              (15U)
#define FDCAN_NDAT2_ND47_Msk              (0x1UL << FDCAN_NDAT2_ND47_Pos)     /*!< 0x00008000 */
#define FDCAN_NDAT2_ND47                  FDCAN_NDAT2_ND47_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT2_ND48_Pos              (16U)
#define FDCAN_NDAT2_ND48_Msk              (0x1UL << FDCAN_NDAT2_ND48_Pos)     /*!< 0x00010000 */
#define FDCAN_NDAT2_ND48                  FDCAN_NDAT2_ND48_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT2_ND49_Pos              (17U)
#define FDCAN_NDAT2_ND49_Msk              (0x1UL << FDCAN_NDAT2_ND49_Pos)     /*!< 0x00020000 */
#define FDCAN_NDAT2_ND49                  FDCAN_NDAT2_ND49_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT2_ND50_Pos              (18U)
#define FDCAN_NDAT2_ND50_Msk              (0x1UL << FDCAN_NDAT2_ND50_Pos)     /*!< 0x00040000 */
#define FDCAN_NDAT2_ND50                  FDCAN_NDAT2_ND50_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT2_ND51_Pos              (19U)
#define FDCAN_NDAT2_ND51_Msk              (0x1UL << FDCAN_NDAT2_ND51_Pos)     /*!< 0x00080000 */
#define FDCAN_NDAT2_ND51                  FDCAN_NDAT2_ND51_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT2_ND52_Pos              (20U)
#define FDCAN_NDAT2_ND52_Msk              (0x1UL << FDCAN_NDAT2_ND52_Pos)     /*!< 0x00100000 */
#define FDCAN_NDAT2_ND52                  FDCAN_NDAT2_ND52_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT2_ND53_Pos              (21U)
#define FDCAN_NDAT2_ND53_Msk              (0x1UL << FDCAN_NDAT2_ND53_Pos)     /*!< 0x00200000 */
#define FDCAN_NDAT2_ND53                  FDCAN_NDAT2_ND53_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT2_ND54_Pos              (22U)
#define FDCAN_NDAT2_ND54_Msk              (0x1UL << FDCAN_NDAT2_ND54_Pos)     /*!< 0x00400000 */
#define FDCAN_NDAT2_ND54                  FDCAN_NDAT2_ND54_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT2_ND55_Pos              (23U)
#define FDCAN_NDAT2_ND55_Msk              (0x1UL << FDCAN_NDAT2_ND55_Pos)     /*!< 0x00800000 */
#define FDCAN_NDAT2_ND55                  FDCAN_NDAT2_ND55_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT2_ND56_Pos              (24U)
#define FDCAN_NDAT2_ND56_Msk              (0x1UL << FDCAN_NDAT2_ND56_Pos)     /*!< 0x01000000 */
#define FDCAN_NDAT2_ND56                  FDCAN_NDAT2_ND56_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT2_ND57_Pos              (25U)
#define FDCAN_NDAT2_ND57_Msk              (0x1UL << FDCAN_NDAT2_ND57_Pos)     /*!< 0x02000000 */
#define FDCAN_NDAT2_ND57                  FDCAN_NDAT2_ND57_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT2_ND58_Pos              (26U)
#define FDCAN_NDAT2_ND58_Msk              (0x1UL << FDCAN_NDAT2_ND58_Pos)     /*!< 0x04000000 */
#define FDCAN_NDAT2_ND58                  FDCAN_NDAT2_ND58_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT2_ND59_Pos              (27U)
#define FDCAN_NDAT2_ND59_Msk              (0x1UL << FDCAN_NDAT2_ND59_Pos)     /*!< 0x08000000 */
#define FDCAN_NDAT2_ND59                  FDCAN_NDAT2_ND59_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT2_ND60_Pos              (28U)
#define FDCAN_NDAT2_ND60_Msk              (0x1UL << FDCAN_NDAT2_ND60_Pos)     /*!< 0x10000000 */
#define FDCAN_NDAT2_ND60                  FDCAN_NDAT2_ND60_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT2_ND61_Pos              (29U)
#define FDCAN_NDAT2_ND61_Msk              (0x1UL << FDCAN_NDAT2_ND61_Pos)     /*!< 0x20000000 */
#define FDCAN_NDAT2_ND61                  FDCAN_NDAT2_ND61_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT2_ND62_Pos              (30U)
#define FDCAN_NDAT2_ND62_Msk              (0x1UL << FDCAN_NDAT2_ND62_Pos)     /*!< 0x40000000 */
#define FDCAN_NDAT2_ND62                  FDCAN_NDAT2_ND62_Msk               /*!< </spirit:description> */
#define FDCAN_NDAT2_ND63_Pos              (31U)
#define FDCAN_NDAT2_ND63_Msk              (0x1UL << FDCAN_NDAT2_ND63_Pos)     /*!< 0x80000000 */
#define FDCAN_NDAT2_ND63                  FDCAN_NDAT2_ND63_Msk               /*!< </spirit:description> */

/*****************  Bit definition for FDCAN_RXF0C register  ******************/
#define FDCAN_RXF0C_F0SA_Pos              (2U)
#define FDCAN_RXF0C_F0SA_Msk              (0x3FFFUL << FDCAN_RXF0C_F0SA_Pos)  /*!< 0x0000FFFC */
#define FDCAN_RXF0C_F0SA                  FDCAN_RXF0C_F0SA_Msk               /*!< </spirit:description> */
#define FDCAN_RXF0C_F0S_Pos               (16U)
#define FDCAN_RXF0C_F0S_Msk               (0x7FUL << FDCAN_RXF0C_F0S_Pos)     /*!< 0x007F0000 */
#define FDCAN_RXF0C_F0S                   FDCAN_RXF0C_F0S_Msk                /*!< </spirit:description> */
#define FDCAN_RXF0C_F0WM_Pos              (24U)
#define FDCAN_RXF0C_F0WM_Msk              (0x7FUL << FDCAN_RXF0C_F0WM_Pos)    /*!< 0x7F000000 */
#define FDCAN_RXF0C_F0WM                  FDCAN_RXF0C_F0WM_Msk               /*!< </spirit:description> */
#define FDCAN_RXF0C_F0OM_Pos              (31U)
#define FDCAN_RXF0C_F0OM_Msk              (0x1UL << FDCAN_RXF0C_F0OM_Pos)     /*!< 0x80000000 */
#define FDCAN_RXF0C_F0OM                  FDCAN_RXF0C_F0OM_Msk               /*!< </spirit:description> */

/*****************  Bit definition for FDCAN_RXF0S register  ******************/
#define FDCAN_RXF0S_F0FL_Pos              (0U)
#define FDCAN_RXF0S_F0FL_Msk              (0x7FUL << FDCAN_RXF0S_F0FL_Pos)    /*!< 0x0000007F */
#define FDCAN_RXF0S_F0FL                  FDCAN_RXF0S_F0FL_Msk               /*!< </spirit:description> */
#define FDCAN_RXF0S_F0GI_Pos              (8U)
#define FDCAN_RXF0S_F0GI_Msk              (0x3FUL << FDCAN_RXF0S_F0GI_Pos)    /*!< 0x00003F00 */
#define FDCAN_RXF0S_F0GI                  FDCAN_RXF0S_F0GI_Msk               /*!< </spirit:description> */
#define FDCAN_RXF0S_F0PI_Pos              (16U)
#define FDCAN_RXF0S_F0PI_Msk              (0x3FUL << FDCAN_RXF0S_F0PI_Pos)    /*!< 0x003F0000 */
#define FDCAN_RXF0S_F0PI                  FDCAN_RXF0S_F0PI_Msk               /*!< </spirit:description> */
#define FDCAN_RXF0S_F0F_Pos               (24U)
#define FDCAN_RXF0S_F0F_Msk               (0x1UL << FDCAN_RXF0S_F0F_Pos)      /*!< 0x01000000 */
#define FDCAN_RXF0S_F0F                   FDCAN_RXF0S_F0F_Msk                /*!< </spirit:description> */
#define FDCAN_RXF0S_RF0L_Pos              (25U)
#define FDCAN_RXF0S_RF0L_Msk              (0x1UL << FDCAN_RXF0S_RF0L_Pos)     /*!< 0x02000000 */
#define FDCAN_RXF0S_RF0L                  FDCAN_RXF0S_RF0L_Msk               /*!< </spirit:description> */

/*****************  Bit definition for FDCAN_RXF0A register  ******************/
#define FDCAN_RXF0A_F0AI_Pos              (0U)
#define FDCAN_RXF0A_F0AI_Msk              (0x3FUL << FDCAN_RXF0A_F0AI_Pos)    /*!< 0x0000003F */
#define FDCAN_RXF0A_F0AI                  FDCAN_RXF0A_F0AI_Msk               /*!< </spirit:description> */

/******************  Bit definition for FDCAN_RXBC register  ******************/
#define FDCAN_RXBC_RBSA_Pos               (2U)
#define FDCAN_RXBC_RBSA_Msk               (0x3FFFUL << FDCAN_RXBC_RBSA_Pos)   /*!< 0x0000FFFC */
#define FDCAN_RXBC_RBSA                   FDCAN_RXBC_RBSA_Msk                /*!< </spirit:description> */

/*****************  Bit definition for FDCAN_RXF1C register  ******************/
#define FDCAN_RXF1C_F1SA_Pos              (2U)
#define FDCAN_RXF1C_F1SA_Msk              (0x3FFFUL << FDCAN_RXF1C_F1SA_Pos)  /*!< 0x0000FFFC */
#define FDCAN_RXF1C_F1SA                  FDCAN_RXF1C_F1SA_Msk               /*!< </spirit:description> */
#define FDCAN_RXF1C_F1S_Pos               (16U)
#define FDCAN_RXF1C_F1S_Msk               (0x7FUL << FDCAN_RXF1C_F1S_Pos)     /*!< 0x007F0000 */
#define FDCAN_RXF1C_F1S                   FDCAN_RXF1C_F1S_Msk                /*!< </spirit:description> */
#define FDCAN_RXF1C_F1WM_Pos              (24U)
#define FDCAN_RXF1C_F1WM_Msk              (0x7FUL << FDCAN_RXF1C_F1WM_Pos)    /*!< 0x7F000000 */
#define FDCAN_RXF1C_F1WM                  FDCAN_RXF1C_F1WM_Msk               /*!< </spirit:description> */
#define FDCAN_RXF1C_F1OM_Pos              (31U)
#define FDCAN_RXF1C_F1OM_Msk              (0x1UL << FDCAN_RXF1C_F1OM_Pos)     /*!< 0x80000000 */
#define FDCAN_RXF1C_F1OM                  FDCAN_RXF1C_F1OM_Msk               /*!< </spirit:description> */

/*****************  Bit definition for FDCAN_RXF1S register  ******************/
#define FDCAN_RXF1S_F1FL_Pos              (0U)
#define FDCAN_RXF1S_F1FL_Msk              (0x7FUL << FDCAN_RXF1S_F1FL_Pos)    /*!< 0x0000007F */
#define FDCAN_RXF1S_F1FL                  FDCAN_RXF1S_F1FL_Msk               /*!< </spirit:description> */
#define FDCAN_RXF1S_F1GI_Pos              (8U)
#define FDCAN_RXF1S_F1GI_Msk              (0x3FUL << FDCAN_RXF1S_F1GI_Pos)    /*!< 0x00003F00 */
#define FDCAN_RXF1S_F1GI                  FDCAN_RXF1S_F1GI_Msk               /*!< </spirit:description> */
#define FDCAN_RXF1S_F1PI_Pos              (16U)
#define FDCAN_RXF1S_F1PI_Msk              (0x3FUL << FDCAN_RXF1S_F1PI_Pos)    /*!< 0x003F0000 */
#define FDCAN_RXF1S_F1PI                  FDCAN_RXF1S_F1PI_Msk               /*!< </spirit:description> */
#define FDCAN_RXF1S_F1F_Pos               (24U)
#define FDCAN_RXF1S_F1F_Msk               (0x1UL << FDCAN_RXF1S_F1F_Pos)      /*!< 0x01000000 */
#define FDCAN_RXF1S_F1F                   FDCAN_RXF1S_F1F_Msk                /*!< </spirit:description> */
#define FDCAN_RXF1S_RF1L_Pos              (25U)
#define FDCAN_RXF1S_RF1L_Msk              (0x1UL << FDCAN_RXF1S_RF1L_Pos)     /*!< 0x02000000 */
#define FDCAN_RXF1S_RF1L                  FDCAN_RXF1S_RF1L_Msk               /*!< </spirit:description> */
#define FDCAN_RXF1S_DMS_Pos               (30U)
#define FDCAN_RXF1S_DMS_Msk               (0x3UL << FDCAN_RXF1S_DMS_Pos)      /*!< 0xC0000000 */
#define FDCAN_RXF1S_DMS                   FDCAN_RXF1S_DMS_Msk                /*!< </spirit:description> */

/*****************  Bit definition for FDCAN_RXF1A register  ******************/
#define FDCAN_RXF1A_F1AI_Pos              (0U)
#define FDCAN_RXF1A_F1AI_Msk              (0x3FUL << FDCAN_RXF1A_F1AI_Pos)    /*!< 0x0000003F */
#define FDCAN_RXF1A_F1AI                  FDCAN_RXF1A_F1AI_Msk               /*!< </spirit:description> */

/*****************  Bit definition for FDCAN_RXESC register  ******************/
#define FDCAN_RXESC_F0DS_Pos              (0U)
#define FDCAN_RXESC_F0DS_Msk              (0x7UL << FDCAN_RXESC_F0DS_Pos)     /*!< 0x00000007 */
#define FDCAN_RXESC_F0DS                  FDCAN_RXESC_F0DS_Msk               /*!< </spirit:description> */
#define FDCAN_RXESC_F1DS_Pos              (4U)
#define FDCAN_RXESC_F1DS_Msk              (0x7UL << FDCAN_RXESC_F1DS_Pos)     /*!< 0x00000070 */
#define FDCAN_RXESC_F1DS                  FDCAN_RXESC_F1DS_Msk               /*!< </spirit:description> */
#define FDCAN_RXESC_RBDS_Pos              (8U)
#define FDCAN_RXESC_RBDS_Msk              (0x7UL << FDCAN_RXESC_RBDS_Pos)     /*!< 0x00000700 */
#define FDCAN_RXESC_RBDS                  FDCAN_RXESC_RBDS_Msk               /*!< </spirit:description> */

/******************  Bit definition for FDCAN_TXBC register  ******************/
#define FDCAN_TXBC_TBSA_Pos               (2U)
#define FDCAN_TXBC_TBSA_Msk               (0x3FFFUL << FDCAN_TXBC_TBSA_Pos)   /*!< 0x0000FFFC */
#define FDCAN_TXBC_TBSA                   FDCAN_TXBC_TBSA_Msk                /*!< </spirit:description> */
#define FDCAN_TXBC_NDTB_Pos               (16U)
#define FDCAN_TXBC_NDTB_Msk               (0x3FUL << FDCAN_TXBC_NDTB_Pos)     /*!< 0x003F0000 */
#define FDCAN_TXBC_NDTB                   FDCAN_TXBC_NDTB_Msk                /*!< </spirit:description> */
#define FDCAN_TXBC_TFQS_Pos               (24U)
#define FDCAN_TXBC_TFQS_Msk               (0x3FUL << FDCAN_TXBC_TFQS_Pos)     /*!< 0x3F000000 */
#define FDCAN_TXBC_TFQS                   FDCAN_TXBC_TFQS_Msk                /*!< </spirit:description> */
#define FDCAN_TXBC_TFQM_Pos               (30U)
#define FDCAN_TXBC_TFQM_Msk               (0x1UL << FDCAN_TXBC_TFQM_Pos)      /*!< 0x40000000 */
#define FDCAN_TXBC_TFQM                   FDCAN_TXBC_TFQM_Msk                /*!< </spirit:description> */

/*****************  Bit definition for FDCAN_TXFQS register  ******************/
#define FDCAN_TXFQS_TFFL_Pos              (0U)
#define FDCAN_TXFQS_TFFL_Msk              (0x3FUL << FDCAN_TXFQS_TFFL_Pos)    /*!< 0x0000003F */
#define FDCAN_TXFQS_TFFL                  FDCAN_TXFQS_TFFL_Msk               /*!< </spirit:description> */
#define FDCAN_TXFQS_TFGI_Pos              (8U)
#define FDCAN_TXFQS_TFGI_Msk              (0x1FUL << FDCAN_TXFQS_TFGI_Pos)    /*!< 0x00001F00 */
#define FDCAN_TXFQS_TFGI                  FDCAN_TXFQS_TFGI_Msk               /*!< </spirit:description> */
#define FDCAN_TXFQS_TFQPI_Pos             (16U)
#define FDCAN_TXFQS_TFQPI_Msk             (0x1FUL << FDCAN_TXFQS_TFQPI_Pos)   /*!< 0x001F0000 */
#define FDCAN_TXFQS_TFQPI                 FDCAN_TXFQS_TFQPI_Msk              /*!< </spirit:description> */
#define FDCAN_TXFQS_TFQF_Pos              (21U)
#define FDCAN_TXFQS_TFQF_Msk              (0x1UL << FDCAN_TXFQS_TFQF_Pos)     /*!< 0x00200000 */
#define FDCAN_TXFQS_TFQF                  FDCAN_TXFQS_TFQF_Msk               /*!< </spirit:description> */

/*****************  Bit definition for FDCAN_TXESC register  ******************/
#define FDCAN_TXESC_TBDS_Pos              (0U)
#define FDCAN_TXESC_TBDS_Msk              (0x7UL << FDCAN_TXESC_TBDS_Pos)     /*!< 0x00000007 */
#define FDCAN_TXESC_TBDS                  FDCAN_TXESC_TBDS_Msk               /*!< </spirit:description> */

/*****************  Bit definition for FDCAN_TXBRP register  ******************/
#define FDCAN_TXBRP_TRP0_Pos              (0U)
#define FDCAN_TXBRP_TRP0_Msk              (0x1UL << FDCAN_TXBRP_TRP0_Pos)     /*!< 0x00000001 */
#define FDCAN_TXBRP_TRP0                  FDCAN_TXBRP_TRP0_Msk               /*!< </spirit:description> */
#define FDCAN_TXBRP_TRP1_Pos              (1U)
#define FDCAN_TXBRP_TRP1_Msk              (0x1UL << FDCAN_TXBRP_TRP1_Pos)     /*!< 0x00000002 */
#define FDCAN_TXBRP_TRP1                  FDCAN_TXBRP_TRP1_Msk               /*!< </spirit:description> */
#define FDCAN_TXBRP_TRP2_Pos              (2U)
#define FDCAN_TXBRP_TRP2_Msk              (0x1UL << FDCAN_TXBRP_TRP2_Pos)     /*!< 0x00000004 */
#define FDCAN_TXBRP_TRP2                  FDCAN_TXBRP_TRP2_Msk               /*!< </spirit:description> */
#define FDCAN_TXBRP_TRP3_Pos              (3U)
#define FDCAN_TXBRP_TRP3_Msk              (0x1UL << FDCAN_TXBRP_TRP3_Pos)     /*!< 0x00000008 */
#define FDCAN_TXBRP_TRP3                  FDCAN_TXBRP_TRP3_Msk               /*!< </spirit:description> */
#define FDCAN_TXBRP_TRP4_Pos              (4U)
#define FDCAN_TXBRP_TRP4_Msk              (0x1UL << FDCAN_TXBRP_TRP4_Pos)     /*!< 0x00000010 */
#define FDCAN_TXBRP_TRP4                  FDCAN_TXBRP_TRP4_Msk               /*!< </spirit:description> */
#define FDCAN_TXBRP_TRP5_Pos              (5U)
#define FDCAN_TXBRP_TRP5_Msk              (0x1UL << FDCAN_TXBRP_TRP5_Pos)     /*!< 0x00000020 */
#define FDCAN_TXBRP_TRP5                  FDCAN_TXBRP_TRP5_Msk               /*!< </spirit:description> */
#define FDCAN_TXBRP_TRP6_Pos              (6U)
#define FDCAN_TXBRP_TRP6_Msk              (0x1UL << FDCAN_TXBRP_TRP6_Pos)     /*!< 0x00000040 */
#define FDCAN_TXBRP_TRP6                  FDCAN_TXBRP_TRP6_Msk               /*!< </spirit:description> */
#define FDCAN_TXBRP_TRP7_Pos              (7U)
#define FDCAN_TXBRP_TRP7_Msk              (0x1UL << FDCAN_TXBRP_TRP7_Pos)     /*!< 0x00000080 */
#define FDCAN_TXBRP_TRP7                  FDCAN_TXBRP_TRP7_Msk               /*!< </spirit:description> */
#define FDCAN_TXBRP_TRP8_Pos              (8U)
#define FDCAN_TXBRP_TRP8_Msk              (0x1UL << FDCAN_TXBRP_TRP8_Pos)     /*!< 0x00000100 */
#define FDCAN_TXBRP_TRP8                  FDCAN_TXBRP_TRP8_Msk               /*!< </spirit:description> */
#define FDCAN_TXBRP_TRP9_Pos              (9U)
#define FDCAN_TXBRP_TRP9_Msk              (0x1UL << FDCAN_TXBRP_TRP9_Pos)     /*!< 0x00000200 */
#define FDCAN_TXBRP_TRP9                  FDCAN_TXBRP_TRP9_Msk               /*!< </spirit:description> */
#define FDCAN_TXBRP_TRP10_Pos             (10U)
#define FDCAN_TXBRP_TRP10_Msk             (0x1UL << FDCAN_TXBRP_TRP10_Pos)    /*!< 0x00000400 */
#define FDCAN_TXBRP_TRP10                 FDCAN_TXBRP_TRP10_Msk              /*!< </spirit:description> */
#define FDCAN_TXBRP_TRP11_Pos             (11U)
#define FDCAN_TXBRP_TRP11_Msk             (0x1UL << FDCAN_TXBRP_TRP11_Pos)    /*!< 0x00000800 */
#define FDCAN_TXBRP_TRP11                 FDCAN_TXBRP_TRP11_Msk              /*!< </spirit:description> */
#define FDCAN_TXBRP_TRP12_Pos             (12U)
#define FDCAN_TXBRP_TRP12_Msk             (0x1UL << FDCAN_TXBRP_TRP12_Pos)    /*!< 0x00001000 */
#define FDCAN_TXBRP_TRP12                 FDCAN_TXBRP_TRP12_Msk              /*!< </spirit:description> */
#define FDCAN_TXBRP_TRP13_Pos             (13U)
#define FDCAN_TXBRP_TRP13_Msk             (0x1UL << FDCAN_TXBRP_TRP13_Pos)    /*!< 0x00002000 */
#define FDCAN_TXBRP_TRP13                 FDCAN_TXBRP_TRP13_Msk              /*!< </spirit:description> */
#define FDCAN_TXBRP_TRP14_Pos             (14U)
#define FDCAN_TXBRP_TRP14_Msk             (0x1UL << FDCAN_TXBRP_TRP14_Pos)    /*!< 0x00004000 */
#define FDCAN_TXBRP_TRP14                 FDCAN_TXBRP_TRP14_Msk              /*!< </spirit:description> */
#define FDCAN_TXBRP_TRP15_Pos             (15U)
#define FDCAN_TXBRP_TRP15_Msk             (0x1UL << FDCAN_TXBRP_TRP15_Pos)    /*!< 0x00008000 */
#define FDCAN_TXBRP_TRP15                 FDCAN_TXBRP_TRP15_Msk              /*!< </spirit:description> */
#define FDCAN_TXBRP_TRP16_Pos             (16U)
#define FDCAN_TXBRP_TRP16_Msk             (0x1UL << FDCAN_TXBRP_TRP16_Pos)    /*!< 0x00010000 */
#define FDCAN_TXBRP_TRP16                 FDCAN_TXBRP_TRP16_Msk              /*!< </spirit:description> */
#define FDCAN_TXBRP_TRP17_Pos             (17U)
#define FDCAN_TXBRP_TRP17_Msk             (0x1UL << FDCAN_TXBRP_TRP17_Pos)    /*!< 0x00020000 */
#define FDCAN_TXBRP_TRP17                 FDCAN_TXBRP_TRP17_Msk              /*!< </spirit:description> */
#define FDCAN_TXBRP_TRP18_Pos             (18U)
#define FDCAN_TXBRP_TRP18_Msk             (0x1UL << FDCAN_TXBRP_TRP18_Pos)    /*!< 0x00040000 */
#define FDCAN_TXBRP_TRP18                 FDCAN_TXBRP_TRP18_Msk              /*!< </spirit:description> */
#define FDCAN_TXBRP_TRP19_Pos             (19U)
#define FDCAN_TXBRP_TRP19_Msk             (0x1UL << FDCAN_TXBRP_TRP19_Pos)    /*!< 0x00080000 */
#define FDCAN_TXBRP_TRP19                 FDCAN_TXBRP_TRP19_Msk              /*!< </spirit:description> */
#define FDCAN_TXBRP_TRP20_Pos             (20U)
#define FDCAN_TXBRP_TRP20_Msk             (0x1UL << FDCAN_TXBRP_TRP20_Pos)    /*!< 0x00100000 */
#define FDCAN_TXBRP_TRP20                 FDCAN_TXBRP_TRP20_Msk              /*!< </spirit:description> */
#define FDCAN_TXBRP_TRP21_Pos             (21U)
#define FDCAN_TXBRP_TRP21_Msk             (0x1UL << FDCAN_TXBRP_TRP21_Pos)    /*!< 0x00200000 */
#define FDCAN_TXBRP_TRP21                 FDCAN_TXBRP_TRP21_Msk              /*!< </spirit:description> */
#define FDCAN_TXBRP_TRP22_Pos             (22U)
#define FDCAN_TXBRP_TRP22_Msk             (0x1UL << FDCAN_TXBRP_TRP22_Pos)    /*!< 0x00400000 */
#define FDCAN_TXBRP_TRP22                 FDCAN_TXBRP_TRP22_Msk              /*!< </spirit:description> */
#define FDCAN_TXBRP_TRP23_Pos             (23U)
#define FDCAN_TXBRP_TRP23_Msk             (0x1UL << FDCAN_TXBRP_TRP23_Pos)    /*!< 0x00800000 */
#define FDCAN_TXBRP_TRP23                 FDCAN_TXBRP_TRP23_Msk              /*!< </spirit:description> */
#define FDCAN_TXBRP_TRP24_Pos             (24U)
#define FDCAN_TXBRP_TRP24_Msk             (0x1UL << FDCAN_TXBRP_TRP24_Pos)    /*!< 0x01000000 */
#define FDCAN_TXBRP_TRP24                 FDCAN_TXBRP_TRP24_Msk              /*!< </spirit:description> */
#define FDCAN_TXBRP_TRP25_Pos             (25U)
#define FDCAN_TXBRP_TRP25_Msk             (0x1UL << FDCAN_TXBRP_TRP25_Pos)    /*!< 0x02000000 */
#define FDCAN_TXBRP_TRP25                 FDCAN_TXBRP_TRP25_Msk              /*!< </spirit:description> */
#define FDCAN_TXBRP_TRP26_Pos             (26U)
#define FDCAN_TXBRP_TRP26_Msk             (0x1UL << FDCAN_TXBRP_TRP26_Pos)    /*!< 0x04000000 */
#define FDCAN_TXBRP_TRP26                 FDCAN_TXBRP_TRP26_Msk              /*!< </spirit:description> */
#define FDCAN_TXBRP_TRP27_Pos             (27U)
#define FDCAN_TXBRP_TRP27_Msk             (0x1UL << FDCAN_TXBRP_TRP27_Pos)    /*!< 0x08000000 */
#define FDCAN_TXBRP_TRP27                 FDCAN_TXBRP_TRP27_Msk              /*!< </spirit:description> */
#define FDCAN_TXBRP_TRP28_Pos             (28U)
#define FDCAN_TXBRP_TRP28_Msk             (0x1UL << FDCAN_TXBRP_TRP28_Pos)    /*!< 0x10000000 */
#define FDCAN_TXBRP_TRP28                 FDCAN_TXBRP_TRP28_Msk              /*!< </spirit:description> */
#define FDCAN_TXBRP_TRP29_Pos             (29U)
#define FDCAN_TXBRP_TRP29_Msk             (0x1UL << FDCAN_TXBRP_TRP29_Pos)    /*!< 0x20000000 */
#define FDCAN_TXBRP_TRP29                 FDCAN_TXBRP_TRP29_Msk              /*!< </spirit:description> */
#define FDCAN_TXBRP_TRP30_Pos             (30U)
#define FDCAN_TXBRP_TRP30_Msk             (0x1UL << FDCAN_TXBRP_TRP30_Pos)    /*!< 0x40000000 */
#define FDCAN_TXBRP_TRP30                 FDCAN_TXBRP_TRP30_Msk              /*!< </spirit:description> */
#define FDCAN_TXBRP_TRP31_Pos             (31U)
#define FDCAN_TXBRP_TRP31_Msk             (0x1UL << FDCAN_TXBRP_TRP31_Pos)    /*!< 0x80000000 */
#define FDCAN_TXBRP_TRP31                 FDCAN_TXBRP_TRP31_Msk              /*!< </spirit:description> */

/*****************  Bit definition for FDCAN_TXBAR register  ******************/
#define FDCAN_TXBAR_AR0_Pos               (0U)
#define FDCAN_TXBAR_AR0_Msk               (0x1UL << FDCAN_TXBAR_AR0_Pos)      /*!< 0x00000001 */
#define FDCAN_TXBAR_AR0                   FDCAN_TXBAR_AR0_Msk                /*!< </spirit:description> */
#define FDCAN_TXBAR_AR1_Pos               (1U)
#define FDCAN_TXBAR_AR1_Msk               (0x1UL << FDCAN_TXBAR_AR1_Pos)      /*!< 0x00000002 */
#define FDCAN_TXBAR_AR1                   FDCAN_TXBAR_AR1_Msk                /*!< </spirit:description> */
#define FDCAN_TXBAR_AR2_Pos               (2U)
#define FDCAN_TXBAR_AR2_Msk               (0x1UL << FDCAN_TXBAR_AR2_Pos)      /*!< 0x00000004 */
#define FDCAN_TXBAR_AR2                   FDCAN_TXBAR_AR2_Msk                /*!< </spirit:description> */
#define FDCAN_TXBAR_AR3_Pos               (3U)
#define FDCAN_TXBAR_AR3_Msk               (0x1UL << FDCAN_TXBAR_AR3_Pos)      /*!< 0x00000008 */
#define FDCAN_TXBAR_AR3                   FDCAN_TXBAR_AR3_Msk                /*!< </spirit:description> */
#define FDCAN_TXBAR_AR4_Pos               (4U)
#define FDCAN_TXBAR_AR4_Msk               (0x1UL << FDCAN_TXBAR_AR4_Pos)      /*!< 0x00000010 */
#define FDCAN_TXBAR_AR4                   FDCAN_TXBAR_AR4_Msk                /*!< </spirit:description> */
#define FDCAN_TXBAR_AR5_Pos               (5U)
#define FDCAN_TXBAR_AR5_Msk               (0x1UL << FDCAN_TXBAR_AR5_Pos)      /*!< 0x00000020 */
#define FDCAN_TXBAR_AR5                   FDCAN_TXBAR_AR5_Msk                /*!< </spirit:description> */
#define FDCAN_TXBAR_AR6_Pos               (6U)
#define FDCAN_TXBAR_AR6_Msk               (0x1UL << FDCAN_TXBAR_AR6_Pos)      /*!< 0x00000040 */
#define FDCAN_TXBAR_AR6                   FDCAN_TXBAR_AR6_Msk                /*!< </spirit:description> */
#define FDCAN_TXBAR_AR7_Pos               (7U)
#define FDCAN_TXBAR_AR7_Msk               (0x1UL << FDCAN_TXBAR_AR7_Pos)      /*!< 0x00000080 */
#define FDCAN_TXBAR_AR7                   FDCAN_TXBAR_AR7_Msk                /*!< </spirit:description> */
#define FDCAN_TXBAR_AR8_Pos               (8U)
#define FDCAN_TXBAR_AR8_Msk               (0x1UL << FDCAN_TXBAR_AR8_Pos)      /*!< 0x00000100 */
#define FDCAN_TXBAR_AR8                   FDCAN_TXBAR_AR8_Msk                /*!< </spirit:description> */
#define FDCAN_TXBAR_AR9_Pos               (9U)
#define FDCAN_TXBAR_AR9_Msk               (0x1UL << FDCAN_TXBAR_AR9_Pos)      /*!< 0x00000200 */
#define FDCAN_TXBAR_AR9                   FDCAN_TXBAR_AR9_Msk                /*!< </spirit:description> */
#define FDCAN_TXBAR_AR10_Pos              (10U)
#define FDCAN_TXBAR_AR10_Msk              (0x1UL << FDCAN_TXBAR_AR10_Pos)     /*!< 0x00000400 */
#define FDCAN_TXBAR_AR10                  FDCAN_TXBAR_AR10_Msk               /*!< </spirit:description> */
#define FDCAN_TXBAR_AR11_Pos              (11U)
#define FDCAN_TXBAR_AR11_Msk              (0x1UL << FDCAN_TXBAR_AR11_Pos)     /*!< 0x00000800 */
#define FDCAN_TXBAR_AR11                  FDCAN_TXBAR_AR11_Msk               /*!< </spirit:description> */
#define FDCAN_TXBAR_AR12_Pos              (12U)
#define FDCAN_TXBAR_AR12_Msk              (0x1UL << FDCAN_TXBAR_AR12_Pos)     /*!< 0x00001000 */
#define FDCAN_TXBAR_AR12                  FDCAN_TXBAR_AR12_Msk               /*!< </spirit:description> */
#define FDCAN_TXBAR_AR13_Pos              (13U)
#define FDCAN_TXBAR_AR13_Msk              (0x1UL << FDCAN_TXBAR_AR13_Pos)     /*!< 0x00002000 */
#define FDCAN_TXBAR_AR13                  FDCAN_TXBAR_AR13_Msk               /*!< </spirit:description> */
#define FDCAN_TXBAR_AR14_Pos              (14U)
#define FDCAN_TXBAR_AR14_Msk              (0x1UL << FDCAN_TXBAR_AR14_Pos)     /*!< 0x00004000 */
#define FDCAN_TXBAR_AR14                  FDCAN_TXBAR_AR14_Msk               /*!< </spirit:description> */
#define FDCAN_TXBAR_AR15_Pos              (15U)
#define FDCAN_TXBAR_AR15_Msk              (0x1UL << FDCAN_TXBAR_AR15_Pos)     /*!< 0x00008000 */
#define FDCAN_TXBAR_AR15                  FDCAN_TXBAR_AR15_Msk               /*!< </spirit:description> */
#define FDCAN_TXBAR_AR16_Pos              (16U)
#define FDCAN_TXBAR_AR16_Msk              (0x1UL << FDCAN_TXBAR_AR16_Pos)     /*!< 0x00010000 */
#define FDCAN_TXBAR_AR16                  FDCAN_TXBAR_AR16_Msk               /*!< </spirit:description> */
#define FDCAN_TXBAR_AR17_Pos              (17U)
#define FDCAN_TXBAR_AR17_Msk              (0x1UL << FDCAN_TXBAR_AR17_Pos)     /*!< 0x00020000 */
#define FDCAN_TXBAR_AR17                  FDCAN_TXBAR_AR17_Msk               /*!< </spirit:description> */
#define FDCAN_TXBAR_AR18_Pos              (18U)
#define FDCAN_TXBAR_AR18_Msk              (0x1UL << FDCAN_TXBAR_AR18_Pos)     /*!< 0x00040000 */
#define FDCAN_TXBAR_AR18                  FDCAN_TXBAR_AR18_Msk               /*!< </spirit:description> */
#define FDCAN_TXBAR_AR19_Pos              (19U)
#define FDCAN_TXBAR_AR19_Msk              (0x1UL << FDCAN_TXBAR_AR19_Pos)     /*!< 0x00080000 */
#define FDCAN_TXBAR_AR19                  FDCAN_TXBAR_AR19_Msk               /*!< </spirit:description> */
#define FDCAN_TXBAR_AR20_Pos              (20U)
#define FDCAN_TXBAR_AR20_Msk              (0x1UL << FDCAN_TXBAR_AR20_Pos)     /*!< 0x00100000 */
#define FDCAN_TXBAR_AR20                  FDCAN_TXBAR_AR20_Msk               /*!< </spirit:description> */
#define FDCAN_TXBAR_AR21_Pos              (21U)
#define FDCAN_TXBAR_AR21_Msk              (0x1UL << FDCAN_TXBAR_AR21_Pos)     /*!< 0x00200000 */
#define FDCAN_TXBAR_AR21                  FDCAN_TXBAR_AR21_Msk               /*!< </spirit:description> */
#define FDCAN_TXBAR_AR22_Pos              (22U)
#define FDCAN_TXBAR_AR22_Msk              (0x1UL << FDCAN_TXBAR_AR22_Pos)     /*!< 0x00400000 */
#define FDCAN_TXBAR_AR22                  FDCAN_TXBAR_AR22_Msk               /*!< </spirit:description> */
#define FDCAN_TXBAR_AR23_Pos              (23U)
#define FDCAN_TXBAR_AR23_Msk              (0x1UL << FDCAN_TXBAR_AR23_Pos)     /*!< 0x00800000 */
#define FDCAN_TXBAR_AR23                  FDCAN_TXBAR_AR23_Msk               /*!< </spirit:description> */
#define FDCAN_TXBAR_AR24_Pos              (24U)
#define FDCAN_TXBAR_AR24_Msk              (0x1UL << FDCAN_TXBAR_AR24_Pos)     /*!< 0x01000000 */
#define FDCAN_TXBAR_AR24                  FDCAN_TXBAR_AR24_Msk               /*!< </spirit:description> */
#define FDCAN_TXBAR_AR25_Pos              (25U)
#define FDCAN_TXBAR_AR25_Msk              (0x1UL << FDCAN_TXBAR_AR25_Pos)     /*!< 0x02000000 */
#define FDCAN_TXBAR_AR25                  FDCAN_TXBAR_AR25_Msk               /*!< </spirit:description> */
#define FDCAN_TXBAR_AR26_Pos              (26U)
#define FDCAN_TXBAR_AR26_Msk              (0x1UL << FDCAN_TXBAR_AR26_Pos)     /*!< 0x04000000 */
#define FDCAN_TXBAR_AR26                  FDCAN_TXBAR_AR26_Msk               /*!< </spirit:description> */
#define FDCAN_TXBAR_AR27_Pos              (27U)
#define FDCAN_TXBAR_AR27_Msk              (0x1UL << FDCAN_TXBAR_AR27_Pos)     /*!< 0x08000000 */
#define FDCAN_TXBAR_AR27                  FDCAN_TXBAR_AR27_Msk               /*!< </spirit:description> */
#define FDCAN_TXBAR_AR28_Pos              (28U)
#define FDCAN_TXBAR_AR28_Msk              (0x1UL << FDCAN_TXBAR_AR28_Pos)     /*!< 0x10000000 */
#define FDCAN_TXBAR_AR28                  FDCAN_TXBAR_AR28_Msk               /*!< </spirit:description> */
#define FDCAN_TXBAR_AR29_Pos              (29U)
#define FDCAN_TXBAR_AR29_Msk              (0x1UL << FDCAN_TXBAR_AR29_Pos)     /*!< 0x20000000 */
#define FDCAN_TXBAR_AR29                  FDCAN_TXBAR_AR29_Msk               /*!< </spirit:description> */
#define FDCAN_TXBAR_AR30_Pos              (30U)
#define FDCAN_TXBAR_AR30_Msk              (0x1UL << FDCAN_TXBAR_AR30_Pos)     /*!< 0x40000000 */
#define FDCAN_TXBAR_AR30                  FDCAN_TXBAR_AR30_Msk               /*!< </spirit:description> */
#define FDCAN_TXBAR_AR31_Pos              (31U)
#define FDCAN_TXBAR_AR31_Msk              (0x1UL << FDCAN_TXBAR_AR31_Pos)     /*!< 0x80000000 */
#define FDCAN_TXBAR_AR31                  FDCAN_TXBAR_AR31_Msk               /*!< </spirit:description> */

/*****************  Bit definition for FDCAN_TXBCR register  ******************/
#define FDCAN_TXBCR_CR0_Pos               (0U)
#define FDCAN_TXBCR_CR0_Msk               (0x1UL << FDCAN_TXBCR_CR0_Pos)      /*!< 0x00000001 */
#define FDCAN_TXBCR_CR0                   FDCAN_TXBCR_CR0_Msk                /*!< </spirit:description> */
#define FDCAN_TXBCR_CR1_Pos               (1U)
#define FDCAN_TXBCR_CR1_Msk               (0x1UL << FDCAN_TXBCR_CR1_Pos)      /*!< 0x00000002 */
#define FDCAN_TXBCR_CR1                   FDCAN_TXBCR_CR1_Msk                /*!< </spirit:description> */
#define FDCAN_TXBCR_CR2_Pos               (2U)
#define FDCAN_TXBCR_CR2_Msk               (0x1UL << FDCAN_TXBCR_CR2_Pos)      /*!< 0x00000004 */
#define FDCAN_TXBCR_CR2                   FDCAN_TXBCR_CR2_Msk                /*!< </spirit:description> */
#define FDCAN_TXBCR_CR3_Pos               (3U)
#define FDCAN_TXBCR_CR3_Msk               (0x1UL << FDCAN_TXBCR_CR3_Pos)      /*!< 0x00000008 */
#define FDCAN_TXBCR_CR3                   FDCAN_TXBCR_CR3_Msk                /*!< </spirit:description> */
#define FDCAN_TXBCR_CR4_Pos               (4U)
#define FDCAN_TXBCR_CR4_Msk               (0x1UL << FDCAN_TXBCR_CR4_Pos)      /*!< 0x00000010 */
#define FDCAN_TXBCR_CR4                   FDCAN_TXBCR_CR4_Msk                /*!< </spirit:description> */
#define FDCAN_TXBCR_CR5_Pos               (5U)
#define FDCAN_TXBCR_CR5_Msk               (0x1UL << FDCAN_TXBCR_CR5_Pos)      /*!< 0x00000020 */
#define FDCAN_TXBCR_CR5                   FDCAN_TXBCR_CR5_Msk                /*!< </spirit:description> */
#define FDCAN_TXBCR_CR6_Pos               (6U)
#define FDCAN_TXBCR_CR6_Msk               (0x1UL << FDCAN_TXBCR_CR6_Pos)      /*!< 0x00000040 */
#define FDCAN_TXBCR_CR6                   FDCAN_TXBCR_CR6_Msk                /*!< </spirit:description> */
#define FDCAN_TXBCR_CR7_Pos               (7U)
#define FDCAN_TXBCR_CR7_Msk               (0x1UL << FDCAN_TXBCR_CR7_Pos)      /*!< 0x00000080 */
#define FDCAN_TXBCR_CR7                   FDCAN_TXBCR_CR7_Msk                /*!< </spirit:description> */
#define FDCAN_TXBCR_CR8_Pos               (8U)
#define FDCAN_TXBCR_CR8_Msk               (0x1UL << FDCAN_TXBCR_CR8_Pos)      /*!< 0x00000100 */
#define FDCAN_TXBCR_CR8                   FDCAN_TXBCR_CR8_Msk                /*!< </spirit:description> */
#define FDCAN_TXBCR_CR9_Pos               (9U)
#define FDCAN_TXBCR_CR9_Msk               (0x1UL << FDCAN_TXBCR_CR9_Pos)      /*!< 0x00000200 */
#define FDCAN_TXBCR_CR9                   FDCAN_TXBCR_CR9_Msk                /*!< </spirit:description> */
#define FDCAN_TXBCR_CR10_Pos              (10U)
#define FDCAN_TXBCR_CR10_Msk              (0x1UL << FDCAN_TXBCR_CR10_Pos)     /*!< 0x00000400 */
#define FDCAN_TXBCR_CR10                  FDCAN_TXBCR_CR10_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCR_CR11_Pos              (11U)
#define FDCAN_TXBCR_CR11_Msk              (0x1UL << FDCAN_TXBCR_CR11_Pos)     /*!< 0x00000800 */
#define FDCAN_TXBCR_CR11                  FDCAN_TXBCR_CR11_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCR_CR12_Pos              (12U)
#define FDCAN_TXBCR_CR12_Msk              (0x1UL << FDCAN_TXBCR_CR12_Pos)     /*!< 0x00001000 */
#define FDCAN_TXBCR_CR12                  FDCAN_TXBCR_CR12_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCR_CR13_Pos              (13U)
#define FDCAN_TXBCR_CR13_Msk              (0x1UL << FDCAN_TXBCR_CR13_Pos)     /*!< 0x00002000 */
#define FDCAN_TXBCR_CR13                  FDCAN_TXBCR_CR13_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCR_CR14_Pos              (14U)
#define FDCAN_TXBCR_CR14_Msk              (0x1UL << FDCAN_TXBCR_CR14_Pos)     /*!< 0x00004000 */
#define FDCAN_TXBCR_CR14                  FDCAN_TXBCR_CR14_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCR_CR15_Pos              (15U)
#define FDCAN_TXBCR_CR15_Msk              (0x1UL << FDCAN_TXBCR_CR15_Pos)     /*!< 0x00008000 */
#define FDCAN_TXBCR_CR15                  FDCAN_TXBCR_CR15_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCR_CR16_Pos              (16U)
#define FDCAN_TXBCR_CR16_Msk              (0x1UL << FDCAN_TXBCR_CR16_Pos)     /*!< 0x00010000 */
#define FDCAN_TXBCR_CR16                  FDCAN_TXBCR_CR16_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCR_CR17_Pos              (17U)
#define FDCAN_TXBCR_CR17_Msk              (0x1UL << FDCAN_TXBCR_CR17_Pos)     /*!< 0x00020000 */
#define FDCAN_TXBCR_CR17                  FDCAN_TXBCR_CR17_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCR_CR18_Pos              (18U)
#define FDCAN_TXBCR_CR18_Msk              (0x1UL << FDCAN_TXBCR_CR18_Pos)     /*!< 0x00040000 */
#define FDCAN_TXBCR_CR18                  FDCAN_TXBCR_CR18_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCR_CR19_Pos              (19U)
#define FDCAN_TXBCR_CR19_Msk              (0x1UL << FDCAN_TXBCR_CR19_Pos)     /*!< 0x00080000 */
#define FDCAN_TXBCR_CR19                  FDCAN_TXBCR_CR19_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCR_CR20_Pos              (20U)
#define FDCAN_TXBCR_CR20_Msk              (0x1UL << FDCAN_TXBCR_CR20_Pos)     /*!< 0x00100000 */
#define FDCAN_TXBCR_CR20                  FDCAN_TXBCR_CR20_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCR_CR21_Pos              (21U)
#define FDCAN_TXBCR_CR21_Msk              (0x1UL << FDCAN_TXBCR_CR21_Pos)     /*!< 0x00200000 */
#define FDCAN_TXBCR_CR21                  FDCAN_TXBCR_CR21_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCR_CR22_Pos              (22U)
#define FDCAN_TXBCR_CR22_Msk              (0x1UL << FDCAN_TXBCR_CR22_Pos)     /*!< 0x00400000 */
#define FDCAN_TXBCR_CR22                  FDCAN_TXBCR_CR22_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCR_CR23_Pos              (23U)
#define FDCAN_TXBCR_CR23_Msk              (0x1UL << FDCAN_TXBCR_CR23_Pos)     /*!< 0x00800000 */
#define FDCAN_TXBCR_CR23                  FDCAN_TXBCR_CR23_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCR_CR24_Pos              (24U)
#define FDCAN_TXBCR_CR24_Msk              (0x1UL << FDCAN_TXBCR_CR24_Pos)     /*!< 0x01000000 */
#define FDCAN_TXBCR_CR24                  FDCAN_TXBCR_CR24_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCR_CR25_Pos              (25U)
#define FDCAN_TXBCR_CR25_Msk              (0x1UL << FDCAN_TXBCR_CR25_Pos)     /*!< 0x02000000 */
#define FDCAN_TXBCR_CR25                  FDCAN_TXBCR_CR25_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCR_CR26_Pos              (26U)
#define FDCAN_TXBCR_CR26_Msk              (0x1UL << FDCAN_TXBCR_CR26_Pos)     /*!< 0x04000000 */
#define FDCAN_TXBCR_CR26                  FDCAN_TXBCR_CR26_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCR_CR27_Pos              (27U)
#define FDCAN_TXBCR_CR27_Msk              (0x1UL << FDCAN_TXBCR_CR27_Pos)     /*!< 0x08000000 */
#define FDCAN_TXBCR_CR27                  FDCAN_TXBCR_CR27_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCR_CR28_Pos              (28U)
#define FDCAN_TXBCR_CR28_Msk              (0x1UL << FDCAN_TXBCR_CR28_Pos)     /*!< 0x10000000 */
#define FDCAN_TXBCR_CR28                  FDCAN_TXBCR_CR28_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCR_CR29_Pos              (29U)
#define FDCAN_TXBCR_CR29_Msk              (0x1UL << FDCAN_TXBCR_CR29_Pos)     /*!< 0x20000000 */
#define FDCAN_TXBCR_CR29                  FDCAN_TXBCR_CR29_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCR_CR30_Pos              (30U)
#define FDCAN_TXBCR_CR30_Msk              (0x1UL << FDCAN_TXBCR_CR30_Pos)     /*!< 0x40000000 */
#define FDCAN_TXBCR_CR30                  FDCAN_TXBCR_CR30_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCR_CR31_Pos              (31U)
#define FDCAN_TXBCR_CR31_Msk              (0x1UL << FDCAN_TXBCR_CR31_Pos)     /*!< 0x80000000 */
#define FDCAN_TXBCR_CR31                  FDCAN_TXBCR_CR31_Msk               /*!< </spirit:description> */

/*****************  Bit definition for FDCAN_TXBTO register  ******************/
#define FDCAN_TXBTO_TO0_Pos               (0U)
#define FDCAN_TXBTO_TO0_Msk               (0x1UL << FDCAN_TXBTO_TO0_Pos)      /*!< 0x00000001 */
#define FDCAN_TXBTO_TO0                   FDCAN_TXBTO_TO0_Msk                /*!< </spirit:description> */
#define FDCAN_TXBTO_TO1_Pos               (1U)
#define FDCAN_TXBTO_TO1_Msk               (0x1UL << FDCAN_TXBTO_TO1_Pos)      /*!< 0x00000002 */
#define FDCAN_TXBTO_TO1                   FDCAN_TXBTO_TO1_Msk                /*!< </spirit:description> */
#define FDCAN_TXBTO_TO2_Pos               (2U)
#define FDCAN_TXBTO_TO2_Msk               (0x1UL << FDCAN_TXBTO_TO2_Pos)      /*!< 0x00000004 */
#define FDCAN_TXBTO_TO2                   FDCAN_TXBTO_TO2_Msk                /*!< </spirit:description> */
#define FDCAN_TXBTO_TO3_Pos               (3U)
#define FDCAN_TXBTO_TO3_Msk               (0x1UL << FDCAN_TXBTO_TO3_Pos)      /*!< 0x00000008 */
#define FDCAN_TXBTO_TO3                   FDCAN_TXBTO_TO3_Msk                /*!< </spirit:description> */
#define FDCAN_TXBTO_TO4_Pos               (4U)
#define FDCAN_TXBTO_TO4_Msk               (0x1UL << FDCAN_TXBTO_TO4_Pos)      /*!< 0x00000010 */
#define FDCAN_TXBTO_TO4                   FDCAN_TXBTO_TO4_Msk                /*!< </spirit:description> */
#define FDCAN_TXBTO_TO5_Pos               (5U)
#define FDCAN_TXBTO_TO5_Msk               (0x1UL << FDCAN_TXBTO_TO5_Pos)      /*!< 0x00000020 */
#define FDCAN_TXBTO_TO5                   FDCAN_TXBTO_TO5_Msk                /*!< </spirit:description> */
#define FDCAN_TXBTO_TO6_Pos               (6U)
#define FDCAN_TXBTO_TO6_Msk               (0x1UL << FDCAN_TXBTO_TO6_Pos)      /*!< 0x00000040 */
#define FDCAN_TXBTO_TO6                   FDCAN_TXBTO_TO6_Msk                /*!< </spirit:description> */
#define FDCAN_TXBTO_TO7_Pos               (7U)
#define FDCAN_TXBTO_TO7_Msk               (0x1UL << FDCAN_TXBTO_TO7_Pos)      /*!< 0x00000080 */
#define FDCAN_TXBTO_TO7                   FDCAN_TXBTO_TO7_Msk                /*!< </spirit:description> */
#define FDCAN_TXBTO_TO8_Pos               (8U)
#define FDCAN_TXBTO_TO8_Msk               (0x1UL << FDCAN_TXBTO_TO8_Pos)      /*!< 0x00000100 */
#define FDCAN_TXBTO_TO8                   FDCAN_TXBTO_TO8_Msk                /*!< </spirit:description> */
#define FDCAN_TXBTO_TO9_Pos               (9U)
#define FDCAN_TXBTO_TO9_Msk               (0x1UL << FDCAN_TXBTO_TO9_Pos)      /*!< 0x00000200 */
#define FDCAN_TXBTO_TO9                   FDCAN_TXBTO_TO9_Msk                /*!< </spirit:description> */
#define FDCAN_TXBTO_TO10_Pos              (10U)
#define FDCAN_TXBTO_TO10_Msk              (0x1UL << FDCAN_TXBTO_TO10_Pos)     /*!< 0x00000400 */
#define FDCAN_TXBTO_TO10                  FDCAN_TXBTO_TO10_Msk               /*!< </spirit:description> */
#define FDCAN_TXBTO_TO11_Pos              (11U)
#define FDCAN_TXBTO_TO11_Msk              (0x1UL << FDCAN_TXBTO_TO11_Pos)     /*!< 0x00000800 */
#define FDCAN_TXBTO_TO11                  FDCAN_TXBTO_TO11_Msk               /*!< </spirit:description> */
#define FDCAN_TXBTO_TO12_Pos              (12U)
#define FDCAN_TXBTO_TO12_Msk              (0x1UL << FDCAN_TXBTO_TO12_Pos)     /*!< 0x00001000 */
#define FDCAN_TXBTO_TO12                  FDCAN_TXBTO_TO12_Msk               /*!< </spirit:description> */
#define FDCAN_TXBTO_TO13_Pos              (13U)
#define FDCAN_TXBTO_TO13_Msk              (0x1UL << FDCAN_TXBTO_TO13_Pos)     /*!< 0x00002000 */
#define FDCAN_TXBTO_TO13                  FDCAN_TXBTO_TO13_Msk               /*!< </spirit:description> */
#define FDCAN_TXBTO_TO14_Pos              (14U)
#define FDCAN_TXBTO_TO14_Msk              (0x1UL << FDCAN_TXBTO_TO14_Pos)     /*!< 0x00004000 */
#define FDCAN_TXBTO_TO14                  FDCAN_TXBTO_TO14_Msk               /*!< </spirit:description> */
#define FDCAN_TXBTO_TO15_Pos              (15U)
#define FDCAN_TXBTO_TO15_Msk              (0x1UL << FDCAN_TXBTO_TO15_Pos)     /*!< 0x00008000 */
#define FDCAN_TXBTO_TO15                  FDCAN_TXBTO_TO15_Msk               /*!< </spirit:description> */
#define FDCAN_TXBTO_TO16_Pos              (16U)
#define FDCAN_TXBTO_TO16_Msk              (0x1UL << FDCAN_TXBTO_TO16_Pos)     /*!< 0x00010000 */
#define FDCAN_TXBTO_TO16                  FDCAN_TXBTO_TO16_Msk               /*!< </spirit:description> */
#define FDCAN_TXBTO_TO17_Pos              (17U)
#define FDCAN_TXBTO_TO17_Msk              (0x1UL << FDCAN_TXBTO_TO17_Pos)     /*!< 0x00020000 */
#define FDCAN_TXBTO_TO17                  FDCAN_TXBTO_TO17_Msk               /*!< </spirit:description> */
#define FDCAN_TXBTO_TO18_Pos              (18U)
#define FDCAN_TXBTO_TO18_Msk              (0x1UL << FDCAN_TXBTO_TO18_Pos)     /*!< 0x00040000 */
#define FDCAN_TXBTO_TO18                  FDCAN_TXBTO_TO18_Msk               /*!< </spirit:description> */
#define FDCAN_TXBTO_TO19_Pos              (19U)
#define FDCAN_TXBTO_TO19_Msk              (0x1UL << FDCAN_TXBTO_TO19_Pos)     /*!< 0x00080000 */
#define FDCAN_TXBTO_TO19                  FDCAN_TXBTO_TO19_Msk               /*!< </spirit:description> */
#define FDCAN_TXBTO_TO20_Pos              (20U)
#define FDCAN_TXBTO_TO20_Msk              (0x1UL << FDCAN_TXBTO_TO20_Pos)     /*!< 0x00100000 */
#define FDCAN_TXBTO_TO20                  FDCAN_TXBTO_TO20_Msk               /*!< </spirit:description> */
#define FDCAN_TXBTO_TO21_Pos              (21U)
#define FDCAN_TXBTO_TO21_Msk              (0x1UL << FDCAN_TXBTO_TO21_Pos)     /*!< 0x00200000 */
#define FDCAN_TXBTO_TO21                  FDCAN_TXBTO_TO21_Msk               /*!< </spirit:description> */
#define FDCAN_TXBTO_TO22_Pos              (22U)
#define FDCAN_TXBTO_TO22_Msk              (0x1UL << FDCAN_TXBTO_TO22_Pos)     /*!< 0x00400000 */
#define FDCAN_TXBTO_TO22                  FDCAN_TXBTO_TO22_Msk               /*!< </spirit:description> */
#define FDCAN_TXBTO_TO23_Pos              (23U)
#define FDCAN_TXBTO_TO23_Msk              (0x1UL << FDCAN_TXBTO_TO23_Pos)     /*!< 0x00800000 */
#define FDCAN_TXBTO_TO23                  FDCAN_TXBTO_TO23_Msk               /*!< </spirit:description> */
#define FDCAN_TXBTO_TO24_Pos              (24U)
#define FDCAN_TXBTO_TO24_Msk              (0x1UL << FDCAN_TXBTO_TO24_Pos)     /*!< 0x01000000 */
#define FDCAN_TXBTO_TO24                  FDCAN_TXBTO_TO24_Msk               /*!< </spirit:description> */
#define FDCAN_TXBTO_TO25_Pos              (25U)
#define FDCAN_TXBTO_TO25_Msk              (0x1UL << FDCAN_TXBTO_TO25_Pos)     /*!< 0x02000000 */
#define FDCAN_TXBTO_TO25                  FDCAN_TXBTO_TO25_Msk               /*!< </spirit:description> */
#define FDCAN_TXBTO_TO26_Pos              (26U)
#define FDCAN_TXBTO_TO26_Msk              (0x1UL << FDCAN_TXBTO_TO26_Pos)     /*!< 0x04000000 */
#define FDCAN_TXBTO_TO26                  FDCAN_TXBTO_TO26_Msk               /*!< </spirit:description> */
#define FDCAN_TXBTO_TO27_Pos              (27U)
#define FDCAN_TXBTO_TO27_Msk              (0x1UL << FDCAN_TXBTO_TO27_Pos)     /*!< 0x08000000 */
#define FDCAN_TXBTO_TO27                  FDCAN_TXBTO_TO27_Msk               /*!< </spirit:description> */
#define FDCAN_TXBTO_TO28_Pos              (28U)
#define FDCAN_TXBTO_TO28_Msk              (0x1UL << FDCAN_TXBTO_TO28_Pos)     /*!< 0x10000000 */
#define FDCAN_TXBTO_TO28                  FDCAN_TXBTO_TO28_Msk               /*!< </spirit:description> */
#define FDCAN_TXBTO_TO29_Pos              (29U)
#define FDCAN_TXBTO_TO29_Msk              (0x1UL << FDCAN_TXBTO_TO29_Pos)     /*!< 0x20000000 */
#define FDCAN_TXBTO_TO29                  FDCAN_TXBTO_TO29_Msk               /*!< </spirit:description> */
#define FDCAN_TXBTO_TO30_Pos              (30U)
#define FDCAN_TXBTO_TO30_Msk              (0x1UL << FDCAN_TXBTO_TO30_Pos)     /*!< 0x40000000 */
#define FDCAN_TXBTO_TO30                  FDCAN_TXBTO_TO30_Msk               /*!< </spirit:description> */
#define FDCAN_TXBTO_TO31_Pos              (31U)
#define FDCAN_TXBTO_TO31_Msk              (0x1UL << FDCAN_TXBTO_TO31_Pos)     /*!< 0x80000000 */
#define FDCAN_TXBTO_TO31                  FDCAN_TXBTO_TO31_Msk               /*!< </spirit:description> */

/*****************  Bit definition for FDCAN_TXBCF register  ******************/
#define FDCAN_TXBCF_CF0_Pos               (0U)
#define FDCAN_TXBCF_CF0_Msk               (0x1UL << FDCAN_TXBCF_CF0_Pos)      /*!< 0x00000001 */
#define FDCAN_TXBCF_CF0                   FDCAN_TXBCF_CF0_Msk                /*!< </spirit:description> */
#define FDCAN_TXBCF_CF1_Pos               (1U)
#define FDCAN_TXBCF_CF1_Msk               (0x1UL << FDCAN_TXBCF_CF1_Pos)      /*!< 0x00000002 */
#define FDCAN_TXBCF_CF1                   FDCAN_TXBCF_CF1_Msk                /*!< </spirit:description> */
#define FDCAN_TXBCF_CF2_Pos               (2U)
#define FDCAN_TXBCF_CF2_Msk               (0x1UL << FDCAN_TXBCF_CF2_Pos)      /*!< 0x00000004 */
#define FDCAN_TXBCF_CF2                   FDCAN_TXBCF_CF2_Msk                /*!< </spirit:description> */
#define FDCAN_TXBCF_CF3_Pos               (3U)
#define FDCAN_TXBCF_CF3_Msk               (0x1UL << FDCAN_TXBCF_CF3_Pos)      /*!< 0x00000008 */
#define FDCAN_TXBCF_CF3                   FDCAN_TXBCF_CF3_Msk                /*!< </spirit:description> */
#define FDCAN_TXBCF_CF4_Pos               (4U)
#define FDCAN_TXBCF_CF4_Msk               (0x1UL << FDCAN_TXBCF_CF4_Pos)      /*!< 0x00000010 */
#define FDCAN_TXBCF_CF4                   FDCAN_TXBCF_CF4_Msk                /*!< </spirit:description> */
#define FDCAN_TXBCF_CF5_Pos               (5U)
#define FDCAN_TXBCF_CF5_Msk               (0x1UL << FDCAN_TXBCF_CF5_Pos)      /*!< 0x00000020 */
#define FDCAN_TXBCF_CF5                   FDCAN_TXBCF_CF5_Msk                /*!< </spirit:description> */
#define FDCAN_TXBCF_CF6_Pos               (6U)
#define FDCAN_TXBCF_CF6_Msk               (0x1UL << FDCAN_TXBCF_CF6_Pos)      /*!< 0x00000040 */
#define FDCAN_TXBCF_CF6                   FDCAN_TXBCF_CF6_Msk                /*!< </spirit:description> */
#define FDCAN_TXBCF_CF7_Pos               (7U)
#define FDCAN_TXBCF_CF7_Msk               (0x1UL << FDCAN_TXBCF_CF7_Pos)      /*!< 0x00000080 */
#define FDCAN_TXBCF_CF7                   FDCAN_TXBCF_CF7_Msk                /*!< </spirit:description> */
#define FDCAN_TXBCF_CF8_Pos               (8U)
#define FDCAN_TXBCF_CF8_Msk               (0x1UL << FDCAN_TXBCF_CF8_Pos)      /*!< 0x00000100 */
#define FDCAN_TXBCF_CF8                   FDCAN_TXBCF_CF8_Msk                /*!< </spirit:description> */
#define FDCAN_TXBCF_CF9_Pos               (9U)
#define FDCAN_TXBCF_CF9_Msk               (0x1UL << FDCAN_TXBCF_CF9_Pos)      /*!< 0x00000200 */
#define FDCAN_TXBCF_CF9                   FDCAN_TXBCF_CF9_Msk                /*!< </spirit:description> */
#define FDCAN_TXBCF_CF10_Pos              (10U)
#define FDCAN_TXBCF_CF10_Msk              (0x1UL << FDCAN_TXBCF_CF10_Pos)     /*!< 0x00000400 */
#define FDCAN_TXBCF_CF10                  FDCAN_TXBCF_CF10_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCF_CF11_Pos              (11U)
#define FDCAN_TXBCF_CF11_Msk              (0x1UL << FDCAN_TXBCF_CF11_Pos)     /*!< 0x00000800 */
#define FDCAN_TXBCF_CF11                  FDCAN_TXBCF_CF11_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCF_CF12_Pos              (12U)
#define FDCAN_TXBCF_CF12_Msk              (0x1UL << FDCAN_TXBCF_CF12_Pos)     /*!< 0x00001000 */
#define FDCAN_TXBCF_CF12                  FDCAN_TXBCF_CF12_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCF_CF13_Pos              (13U)
#define FDCAN_TXBCF_CF13_Msk              (0x1UL << FDCAN_TXBCF_CF13_Pos)     /*!< 0x00002000 */
#define FDCAN_TXBCF_CF13                  FDCAN_TXBCF_CF13_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCF_CF14_Pos              (14U)
#define FDCAN_TXBCF_CF14_Msk              (0x1UL << FDCAN_TXBCF_CF14_Pos)     /*!< 0x00004000 */
#define FDCAN_TXBCF_CF14                  FDCAN_TXBCF_CF14_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCF_CF15_Pos              (15U)
#define FDCAN_TXBCF_CF15_Msk              (0x1UL << FDCAN_TXBCF_CF15_Pos)     /*!< 0x00008000 */
#define FDCAN_TXBCF_CF15                  FDCAN_TXBCF_CF15_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCF_CF16_Pos              (16U)
#define FDCAN_TXBCF_CF16_Msk              (0x1UL << FDCAN_TXBCF_CF16_Pos)     /*!< 0x00010000 */
#define FDCAN_TXBCF_CF16                  FDCAN_TXBCF_CF16_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCF_CF17_Pos              (17U)
#define FDCAN_TXBCF_CF17_Msk              (0x1UL << FDCAN_TXBCF_CF17_Pos)     /*!< 0x00020000 */
#define FDCAN_TXBCF_CF17                  FDCAN_TXBCF_CF17_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCF_CF18_Pos              (18U)
#define FDCAN_TXBCF_CF18_Msk              (0x1UL << FDCAN_TXBCF_CF18_Pos)     /*!< 0x00040000 */
#define FDCAN_TXBCF_CF18                  FDCAN_TXBCF_CF18_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCF_CF19_Pos              (19U)
#define FDCAN_TXBCF_CF19_Msk              (0x1UL << FDCAN_TXBCF_CF19_Pos)     /*!< 0x00080000 */
#define FDCAN_TXBCF_CF19                  FDCAN_TXBCF_CF19_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCF_CF20_Pos              (20U)
#define FDCAN_TXBCF_CF20_Msk              (0x1UL << FDCAN_TXBCF_CF20_Pos)     /*!< 0x00100000 */
#define FDCAN_TXBCF_CF20                  FDCAN_TXBCF_CF20_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCF_CF21_Pos              (21U)
#define FDCAN_TXBCF_CF21_Msk              (0x1UL << FDCAN_TXBCF_CF21_Pos)     /*!< 0x00200000 */
#define FDCAN_TXBCF_CF21                  FDCAN_TXBCF_CF21_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCF_CF22_Pos              (22U)
#define FDCAN_TXBCF_CF22_Msk              (0x1UL << FDCAN_TXBCF_CF22_Pos)     /*!< 0x00400000 */
#define FDCAN_TXBCF_CF22                  FDCAN_TXBCF_CF22_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCF_CF23_Pos              (23U)
#define FDCAN_TXBCF_CF23_Msk              (0x1UL << FDCAN_TXBCF_CF23_Pos)     /*!< 0x00800000 */
#define FDCAN_TXBCF_CF23                  FDCAN_TXBCF_CF23_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCF_CF24_Pos              (24U)
#define FDCAN_TXBCF_CF24_Msk              (0x1UL << FDCAN_TXBCF_CF24_Pos)     /*!< 0x01000000 */
#define FDCAN_TXBCF_CF24                  FDCAN_TXBCF_CF24_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCF_CF25_Pos              (25U)
#define FDCAN_TXBCF_CF25_Msk              (0x1UL << FDCAN_TXBCF_CF25_Pos)     /*!< 0x02000000 */
#define FDCAN_TXBCF_CF25                  FDCAN_TXBCF_CF25_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCF_CF26_Pos              (26U)
#define FDCAN_TXBCF_CF26_Msk              (0x1UL << FDCAN_TXBCF_CF26_Pos)     /*!< 0x04000000 */
#define FDCAN_TXBCF_CF26                  FDCAN_TXBCF_CF26_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCF_CF27_Pos              (27U)
#define FDCAN_TXBCF_CF27_Msk              (0x1UL << FDCAN_TXBCF_CF27_Pos)     /*!< 0x08000000 */
#define FDCAN_TXBCF_CF27                  FDCAN_TXBCF_CF27_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCF_CF28_Pos              (28U)
#define FDCAN_TXBCF_CF28_Msk              (0x1UL << FDCAN_TXBCF_CF28_Pos)     /*!< 0x10000000 */
#define FDCAN_TXBCF_CF28                  FDCAN_TXBCF_CF28_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCF_CF29_Pos              (29U)
#define FDCAN_TXBCF_CF29_Msk              (0x1UL << FDCAN_TXBCF_CF29_Pos)     /*!< 0x20000000 */
#define FDCAN_TXBCF_CF29                  FDCAN_TXBCF_CF29_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCF_CF30_Pos              (30U)
#define FDCAN_TXBCF_CF30_Msk              (0x1UL << FDCAN_TXBCF_CF30_Pos)     /*!< 0x40000000 */
#define FDCAN_TXBCF_CF30                  FDCAN_TXBCF_CF30_Msk               /*!< </spirit:description> */
#define FDCAN_TXBCF_CF31_Pos              (31U)
#define FDCAN_TXBCF_CF31_Msk              (0x1UL << FDCAN_TXBCF_CF31_Pos)     /*!< 0x80000000 */
#define FDCAN_TXBCF_CF31                  FDCAN_TXBCF_CF31_Msk               /*!< </spirit:description> */

/*****************  Bit definition for FDCAN_TXBTIE register  *****************/
#define FDCAN_TXBTIE_TIE0_Pos             (0U)
#define FDCAN_TXBTIE_TIE0_Msk             (0x1UL << FDCAN_TXBTIE_TIE0_Pos)    /*!< 0x00000001 */
#define FDCAN_TXBTIE_TIE0                 FDCAN_TXBTIE_TIE0_Msk              /*!< </spirit:description> */
#define FDCAN_TXBTIE_TIE1_Pos             (1U)
#define FDCAN_TXBTIE_TIE1_Msk             (0x1UL << FDCAN_TXBTIE_TIE1_Pos)    /*!< 0x00000002 */
#define FDCAN_TXBTIE_TIE1                 FDCAN_TXBTIE_TIE1_Msk              /*!< </spirit:description> */
#define FDCAN_TXBTIE_TIE2_Pos             (2U)
#define FDCAN_TXBTIE_TIE2_Msk             (0x1UL << FDCAN_TXBTIE_TIE2_Pos)    /*!< 0x00000004 */
#define FDCAN_TXBTIE_TIE2                 FDCAN_TXBTIE_TIE2_Msk              /*!< </spirit:description> */
#define FDCAN_TXBTIE_TIE3_Pos             (3U)
#define FDCAN_TXBTIE_TIE3_Msk             (0x1UL << FDCAN_TXBTIE_TIE3_Pos)    /*!< 0x00000008 */
#define FDCAN_TXBTIE_TIE3                 FDCAN_TXBTIE_TIE3_Msk              /*!< </spirit:description> */
#define FDCAN_TXBTIE_TIE4_Pos             (4U)
#define FDCAN_TXBTIE_TIE4_Msk             (0x1UL << FDCAN_TXBTIE_TIE4_Pos)    /*!< 0x00000010 */
#define FDCAN_TXBTIE_TIE4                 FDCAN_TXBTIE_TIE4_Msk              /*!< </spirit:description> */
#define FDCAN_TXBTIE_TIE5_Pos             (5U)
#define FDCAN_TXBTIE_TIE5_Msk             (0x1UL << FDCAN_TXBTIE_TIE5_Pos)    /*!< 0x00000020 */
#define FDCAN_TXBTIE_TIE5                 FDCAN_TXBTIE_TIE5_Msk              /*!< </spirit:description> */
#define FDCAN_TXBTIE_TIE6_Pos             (6U)
#define FDCAN_TXBTIE_TIE6_Msk             (0x1UL << FDCAN_TXBTIE_TIE6_Pos)    /*!< 0x00000040 */
#define FDCAN_TXBTIE_TIE6                 FDCAN_TXBTIE_TIE6_Msk              /*!< </spirit:description> */
#define FDCAN_TXBTIE_TIE7_Pos             (7U)
#define FDCAN_TXBTIE_TIE7_Msk             (0x1UL << FDCAN_TXBTIE_TIE7_Pos)    /*!< 0x00000080 */
#define FDCAN_TXBTIE_TIE7                 FDCAN_TXBTIE_TIE7_Msk              /*!< </spirit:description> */
#define FDCAN_TXBTIE_TIE8_Pos             (8U)
#define FDCAN_TXBTIE_TIE8_Msk             (0x1UL << FDCAN_TXBTIE_TIE8_Pos)    /*!< 0x00000100 */
#define FDCAN_TXBTIE_TIE8                 FDCAN_TXBTIE_TIE8_Msk              /*!< </spirit:description> */
#define FDCAN_TXBTIE_TIE9_Pos             (9U)
#define FDCAN_TXBTIE_TIE9_Msk             (0x1UL << FDCAN_TXBTIE_TIE9_Pos)    /*!< 0x00000200 */
#define FDCAN_TXBTIE_TIE9                 FDCAN_TXBTIE_TIE9_Msk              /*!< </spirit:description> */
#define FDCAN_TXBTIE_TIE10_Pos            (10U)
#define FDCAN_TXBTIE_TIE10_Msk            (0x1UL << FDCAN_TXBTIE_TIE10_Pos)   /*!< 0x00000400 */
#define FDCAN_TXBTIE_TIE10                FDCAN_TXBTIE_TIE10_Msk             /*!< </spirit:description> */
#define FDCAN_TXBTIE_TIE11_Pos            (11U)
#define FDCAN_TXBTIE_TIE11_Msk            (0x1UL << FDCAN_TXBTIE_TIE11_Pos)   /*!< 0x00000800 */
#define FDCAN_TXBTIE_TIE11                FDCAN_TXBTIE_TIE11_Msk             /*!< </spirit:description> */
#define FDCAN_TXBTIE_TIE12_Pos            (12U)
#define FDCAN_TXBTIE_TIE12_Msk            (0x1UL << FDCAN_TXBTIE_TIE12_Pos)   /*!< 0x00001000 */
#define FDCAN_TXBTIE_TIE12                FDCAN_TXBTIE_TIE12_Msk             /*!< </spirit:description> */
#define FDCAN_TXBTIE_TIE13_Pos            (13U)
#define FDCAN_TXBTIE_TIE13_Msk            (0x1UL << FDCAN_TXBTIE_TIE13_Pos)   /*!< 0x00002000 */
#define FDCAN_TXBTIE_TIE13                FDCAN_TXBTIE_TIE13_Msk             /*!< </spirit:description> */
#define FDCAN_TXBTIE_TIE14_Pos            (14U)
#define FDCAN_TXBTIE_TIE14_Msk            (0x1UL << FDCAN_TXBTIE_TIE14_Pos)   /*!< 0x00004000 */
#define FDCAN_TXBTIE_TIE14                FDCAN_TXBTIE_TIE14_Msk             /*!< </spirit:description> */
#define FDCAN_TXBTIE_TIE15_Pos            (15U)
#define FDCAN_TXBTIE_TIE15_Msk            (0x1UL << FDCAN_TXBTIE_TIE15_Pos)   /*!< 0x00008000 */
#define FDCAN_TXBTIE_TIE15                FDCAN_TXBTIE_TIE15_Msk             /*!< </spirit:description> */
#define FDCAN_TXBTIE_TIE16_Pos            (16U)
#define FDCAN_TXBTIE_TIE16_Msk            (0x1UL << FDCAN_TXBTIE_TIE16_Pos)   /*!< 0x00010000 */
#define FDCAN_TXBTIE_TIE16                FDCAN_TXBTIE_TIE16_Msk             /*!< </spirit:description> */
#define FDCAN_TXBTIE_TIE17_Pos            (17U)
#define FDCAN_TXBTIE_TIE17_Msk            (0x1UL << FDCAN_TXBTIE_TIE17_Pos)   /*!< 0x00020000 */
#define FDCAN_TXBTIE_TIE17                FDCAN_TXBTIE_TIE17_Msk             /*!< </spirit:description> */
#define FDCAN_TXBTIE_TIE18_Pos            (18U)
#define FDCAN_TXBTIE_TIE18_Msk            (0x1UL << FDCAN_TXBTIE_TIE18_Pos)   /*!< 0x00040000 */
#define FDCAN_TXBTIE_TIE18                FDCAN_TXBTIE_TIE18_Msk             /*!< </spirit:description> */
#define FDCAN_TXBTIE_TIE19_Pos            (19U)
#define FDCAN_TXBTIE_TIE19_Msk            (0x1UL << FDCAN_TXBTIE_TIE19_Pos)   /*!< 0x00080000 */
#define FDCAN_TXBTIE_TIE19                FDCAN_TXBTIE_TIE19_Msk             /*!< </spirit:description> */
#define FDCAN_TXBTIE_TIE20_Pos            (20U)
#define FDCAN_TXBTIE_TIE20_Msk            (0x1UL << FDCAN_TXBTIE_TIE20_Pos)   /*!< 0x00100000 */
#define FDCAN_TXBTIE_TIE20                FDCAN_TXBTIE_TIE20_Msk             /*!< </spirit:description> */
#define FDCAN_TXBTIE_TIE21_Pos            (21U)
#define FDCAN_TXBTIE_TIE21_Msk            (0x1UL << FDCAN_TXBTIE_TIE21_Pos)   /*!< 0x00200000 */
#define FDCAN_TXBTIE_TIE21                FDCAN_TXBTIE_TIE21_Msk             /*!< </spirit:description> */
#define FDCAN_TXBTIE_TIE22_Pos            (22U)
#define FDCAN_TXBTIE_TIE22_Msk            (0x1UL << FDCAN_TXBTIE_TIE22_Pos)   /*!< 0x00400000 */
#define FDCAN_TXBTIE_TIE22                FDCAN_TXBTIE_TIE22_Msk             /*!< </spirit:description> */
#define FDCAN_TXBTIE_TIE23_Pos            (23U)
#define FDCAN_TXBTIE_TIE23_Msk            (0x1UL << FDCAN_TXBTIE_TIE23_Pos)   /*!< 0x00800000 */
#define FDCAN_TXBTIE_TIE23                FDCAN_TXBTIE_TIE23_Msk             /*!< </spirit:description> */
#define FDCAN_TXBTIE_TIE24_Pos            (24U)
#define FDCAN_TXBTIE_TIE24_Msk            (0x1UL << FDCAN_TXBTIE_TIE24_Pos)   /*!< 0x01000000 */
#define FDCAN_TXBTIE_TIE24                FDCAN_TXBTIE_TIE24_Msk             /*!< </spirit:description> */
#define FDCAN_TXBTIE_TIE25_Pos            (25U)
#define FDCAN_TXBTIE_TIE25_Msk            (0x1UL << FDCAN_TXBTIE_TIE25_Pos)   /*!< 0x02000000 */
#define FDCAN_TXBTIE_TIE25                FDCAN_TXBTIE_TIE25_Msk             /*!< </spirit:description> */
#define FDCAN_TXBTIE_TIE26_Pos            (26U)
#define FDCAN_TXBTIE_TIE26_Msk            (0x1UL << FDCAN_TXBTIE_TIE26_Pos)   /*!< 0x04000000 */
#define FDCAN_TXBTIE_TIE26                FDCAN_TXBTIE_TIE26_Msk             /*!< </spirit:description> */
#define FDCAN_TXBTIE_TIE27_Pos            (27U)
#define FDCAN_TXBTIE_TIE27_Msk            (0x1UL << FDCAN_TXBTIE_TIE27_Pos)   /*!< 0x08000000 */
#define FDCAN_TXBTIE_TIE27                FDCAN_TXBTIE_TIE27_Msk             /*!< </spirit:description> */
#define FDCAN_TXBTIE_TIE28_Pos            (28U)
#define FDCAN_TXBTIE_TIE28_Msk            (0x1UL << FDCAN_TXBTIE_TIE28_Pos)   /*!< 0x10000000 */
#define FDCAN_TXBTIE_TIE28                FDCAN_TXBTIE_TIE28_Msk             /*!< </spirit:description> */
#define FDCAN_TXBTIE_TIE29_Pos            (29U)
#define FDCAN_TXBTIE_TIE29_Msk            (0x1UL << FDCAN_TXBTIE_TIE29_Pos)   /*!< 0x20000000 */
#define FDCAN_TXBTIE_TIE29                FDCAN_TXBTIE_TIE29_Msk             /*!< </spirit:description> */
#define FDCAN_TXBTIE_TIE30_Pos            (30U)
#define FDCAN_TXBTIE_TIE30_Msk            (0x1UL << FDCAN_TXBTIE_TIE30_Pos)   /*!< 0x40000000 */
#define FDCAN_TXBTIE_TIE30                FDCAN_TXBTIE_TIE30_Msk             /*!< </spirit:description> */
#define FDCAN_TXBTIE_TIE31_Pos            (31U)
#define FDCAN_TXBTIE_TIE31_Msk            (0x1UL << FDCAN_TXBTIE_TIE31_Pos)   /*!< 0x80000000 */
#define FDCAN_TXBTIE_TIE31                FDCAN_TXBTIE_TIE31_Msk             /*!< </spirit:description> */

/*****************  Bit definition for FDCAN_TXBCIE register  *****************/
#define FDCAN_TXBCIE_CFIE0_Pos            (0U)
#define FDCAN_TXBCIE_CFIE0_Msk            (0x1UL << FDCAN_TXBCIE_CFIE0_Pos)   /*!< 0x00000001 */
#define FDCAN_TXBCIE_CFIE0                FDCAN_TXBCIE_CFIE0_Msk             /*!< </spirit:description> */
#define FDCAN_TXBCIE_CFIE1_Pos            (1U)
#define FDCAN_TXBCIE_CFIE1_Msk            (0x1UL << FDCAN_TXBCIE_CFIE1_Pos)   /*!< 0x00000002 */
#define FDCAN_TXBCIE_CFIE1                FDCAN_TXBCIE_CFIE1_Msk             /*!< </spirit:description> */
#define FDCAN_TXBCIE_CFIE2_Pos            (2U)
#define FDCAN_TXBCIE_CFIE2_Msk            (0x1UL << FDCAN_TXBCIE_CFIE2_Pos)   /*!< 0x00000004 */
#define FDCAN_TXBCIE_CFIE2                FDCAN_TXBCIE_CFIE2_Msk             /*!< </spirit:description> */
#define FDCAN_TXBCIE_CFIE3_Pos            (3U)
#define FDCAN_TXBCIE_CFIE3_Msk            (0x1UL << FDCAN_TXBCIE_CFIE3_Pos)   /*!< 0x00000008 */
#define FDCAN_TXBCIE_CFIE3                FDCAN_TXBCIE_CFIE3_Msk             /*!< </spirit:description> */
#define FDCAN_TXBCIE_CFIE4_Pos            (4U)
#define FDCAN_TXBCIE_CFIE4_Msk            (0x1UL << FDCAN_TXBCIE_CFIE4_Pos)   /*!< 0x00000010 */
#define FDCAN_TXBCIE_CFIE4                FDCAN_TXBCIE_CFIE4_Msk             /*!< </spirit:description> */
#define FDCAN_TXBCIE_CFIE5_Pos            (5U)
#define FDCAN_TXBCIE_CFIE5_Msk            (0x1UL << FDCAN_TXBCIE_CFIE5_Pos)   /*!< 0x00000020 */
#define FDCAN_TXBCIE_CFIE5                FDCAN_TXBCIE_CFIE5_Msk             /*!< </spirit:description> */
#define FDCAN_TXBCIE_CFIE6_Pos            (6U)
#define FDCAN_TXBCIE_CFIE6_Msk            (0x1UL << FDCAN_TXBCIE_CFIE6_Pos)   /*!< 0x00000040 */
#define FDCAN_TXBCIE_CFIE6                FDCAN_TXBCIE_CFIE6_Msk             /*!< </spirit:description> */
#define FDCAN_TXBCIE_CFIE7_Pos            (7U)
#define FDCAN_TXBCIE_CFIE7_Msk            (0x1UL << FDCAN_TXBCIE_CFIE7_Pos)   /*!< 0x00000080 */
#define FDCAN_TXBCIE_CFIE7                FDCAN_TXBCIE_CFIE7_Msk             /*!< </spirit:description> */
#define FDCAN_TXBCIE_CFIE8_Pos            (8U)
#define FDCAN_TXBCIE_CFIE8_Msk            (0x1UL << FDCAN_TXBCIE_CFIE8_Pos)   /*!< 0x00000100 */
#define FDCAN_TXBCIE_CFIE8                FDCAN_TXBCIE_CFIE8_Msk             /*!< </spirit:description> */
#define FDCAN_TXBCIE_CFIE9_Pos            (9U)
#define FDCAN_TXBCIE_CFIE9_Msk            (0x1UL << FDCAN_TXBCIE_CFIE9_Pos)   /*!< 0x00000200 */
#define FDCAN_TXBCIE_CFIE9                FDCAN_TXBCIE_CFIE9_Msk             /*!< </spirit:description> */
#define FDCAN_TXBCIE_CFIE10_Pos           (10U)
#define FDCAN_TXBCIE_CFIE10_Msk           (0x1UL << FDCAN_TXBCIE_CFIE10_Pos)  /*!< 0x00000400 */
#define FDCAN_TXBCIE_CFIE10               FDCAN_TXBCIE_CFIE10_Msk            /*!< </spirit:description> */
#define FDCAN_TXBCIE_CFIE11_Pos           (11U)
#define FDCAN_TXBCIE_CFIE11_Msk           (0x1UL << FDCAN_TXBCIE_CFIE11_Pos)  /*!< 0x00000800 */
#define FDCAN_TXBCIE_CFIE11               FDCAN_TXBCIE_CFIE11_Msk            /*!< </spirit:description> */
#define FDCAN_TXBCIE_CFIE12_Pos           (12U)
#define FDCAN_TXBCIE_CFIE12_Msk           (0x1UL << FDCAN_TXBCIE_CFIE12_Pos)  /*!< 0x00001000 */
#define FDCAN_TXBCIE_CFIE12               FDCAN_TXBCIE_CFIE12_Msk            /*!< </spirit:description> */
#define FDCAN_TXBCIE_CFIE13_Pos           (13U)
#define FDCAN_TXBCIE_CFIE13_Msk           (0x1UL << FDCAN_TXBCIE_CFIE13_Pos)  /*!< 0x00002000 */
#define FDCAN_TXBCIE_CFIE13               FDCAN_TXBCIE_CFIE13_Msk            /*!< </spirit:description> */
#define FDCAN_TXBCIE_CFIE14_Pos           (14U)
#define FDCAN_TXBCIE_CFIE14_Msk           (0x1UL << FDCAN_TXBCIE_CFIE14_Pos)  /*!< 0x00004000 */
#define FDCAN_TXBCIE_CFIE14               FDCAN_TXBCIE_CFIE14_Msk            /*!< </spirit:description> */
#define FDCAN_TXBCIE_CFIE15_Pos           (15U)
#define FDCAN_TXBCIE_CFIE15_Msk           (0x1UL << FDCAN_TXBCIE_CFIE15_Pos)  /*!< 0x00008000 */
#define FDCAN_TXBCIE_CFIE15               FDCAN_TXBCIE_CFIE15_Msk            /*!< </spirit:description> */
#define FDCAN_TXBCIE_CFIE16_Pos           (16U)
#define FDCAN_TXBCIE_CFIE16_Msk           (0x1UL << FDCAN_TXBCIE_CFIE16_Pos)  /*!< 0x00010000 */
#define FDCAN_TXBCIE_CFIE16               FDCAN_TXBCIE_CFIE16_Msk            /*!< </spirit:description> */
#define FDCAN_TXBCIE_CFIE17_Pos           (17U)
#define FDCAN_TXBCIE_CFIE17_Msk           (0x1UL << FDCAN_TXBCIE_CFIE17_Pos)  /*!< 0x00020000 */
#define FDCAN_TXBCIE_CFIE17               FDCAN_TXBCIE_CFIE17_Msk            /*!< </spirit:description> */
#define FDCAN_TXBCIE_CFIE18_Pos           (18U)
#define FDCAN_TXBCIE_CFIE18_Msk           (0x1UL << FDCAN_TXBCIE_CFIE18_Pos)  /*!< 0x00040000 */
#define FDCAN_TXBCIE_CFIE18               FDCAN_TXBCIE_CFIE18_Msk            /*!< </spirit:description> */
#define FDCAN_TXBCIE_CFIE19_Pos           (19U)
#define FDCAN_TXBCIE_CFIE19_Msk           (0x1UL << FDCAN_TXBCIE_CFIE19_Pos)  /*!< 0x00080000 */
#define FDCAN_TXBCIE_CFIE19               FDCAN_TXBCIE_CFIE19_Msk            /*!< </spirit:description> */
#define FDCAN_TXBCIE_CFIE20_Pos           (20U)
#define FDCAN_TXBCIE_CFIE20_Msk           (0x1UL << FDCAN_TXBCIE_CFIE20_Pos)  /*!< 0x00100000 */
#define FDCAN_TXBCIE_CFIE20               FDCAN_TXBCIE_CFIE20_Msk            /*!< </spirit:description> */
#define FDCAN_TXBCIE_CFIE21_Pos           (21U)
#define FDCAN_TXBCIE_CFIE21_Msk           (0x1UL << FDCAN_TXBCIE_CFIE21_Pos)  /*!< 0x00200000 */
#define FDCAN_TXBCIE_CFIE21               FDCAN_TXBCIE_CFIE21_Msk            /*!< </spirit:description> */
#define FDCAN_TXBCIE_CFIE22_Pos           (22U)
#define FDCAN_TXBCIE_CFIE22_Msk           (0x1UL << FDCAN_TXBCIE_CFIE22_Pos)  /*!< 0x00400000 */
#define FDCAN_TXBCIE_CFIE22               FDCAN_TXBCIE_CFIE22_Msk            /*!< </spirit:description> */
#define FDCAN_TXBCIE_CFIE23_Pos           (23U)
#define FDCAN_TXBCIE_CFIE23_Msk           (0x1UL << FDCAN_TXBCIE_CFIE23_Pos)  /*!< 0x00800000 */
#define FDCAN_TXBCIE_CFIE23               FDCAN_TXBCIE_CFIE23_Msk            /*!< </spirit:description> */
#define FDCAN_TXBCIE_CFIE24_Pos           (24U)
#define FDCAN_TXBCIE_CFIE24_Msk           (0x1UL << FDCAN_TXBCIE_CFIE24_Pos)  /*!< 0x01000000 */
#define FDCAN_TXBCIE_CFIE24               FDCAN_TXBCIE_CFIE24_Msk            /*!< </spirit:description> */
#define FDCAN_TXBCIE_CFIE25_Pos           (25U)
#define FDCAN_TXBCIE_CFIE25_Msk           (0x1UL << FDCAN_TXBCIE_CFIE25_Pos)  /*!< 0x02000000 */
#define FDCAN_TXBCIE_CFIE25               FDCAN_TXBCIE_CFIE25_Msk            /*!< </spirit:description> */
#define FDCAN_TXBCIE_CFIE26_Pos           (26U)
#define FDCAN_TXBCIE_CFIE26_Msk           (0x1UL << FDCAN_TXBCIE_CFIE26_Pos)  /*!< 0x04000000 */
#define FDCAN_TXBCIE_CFIE26               FDCAN_TXBCIE_CFIE26_Msk            /*!< </spirit:description> */
#define FDCAN_TXBCIE_CFIE27_Pos           (27U)
#define FDCAN_TXBCIE_CFIE27_Msk           (0x1UL << FDCAN_TXBCIE_CFIE27_Pos)  /*!< 0x08000000 */
#define FDCAN_TXBCIE_CFIE27               FDCAN_TXBCIE_CFIE27_Msk            /*!< </spirit:description> */
#define FDCAN_TXBCIE_CFIE28_Pos           (28U)
#define FDCAN_TXBCIE_CFIE28_Msk           (0x1UL << FDCAN_TXBCIE_CFIE28_Pos)  /*!< 0x10000000 */
#define FDCAN_TXBCIE_CFIE28               FDCAN_TXBCIE_CFIE28_Msk            /*!< </spirit:description> */
#define FDCAN_TXBCIE_CFIE29_Pos           (29U)
#define FDCAN_TXBCIE_CFIE29_Msk           (0x1UL << FDCAN_TXBCIE_CFIE29_Pos)  /*!< 0x20000000 */
#define FDCAN_TXBCIE_CFIE29               FDCAN_TXBCIE_CFIE29_Msk            /*!< </spirit:description> */
#define FDCAN_TXBCIE_CFIE30_Pos           (30U)
#define FDCAN_TXBCIE_CFIE30_Msk           (0x1UL << FDCAN_TXBCIE_CFIE30_Pos)  /*!< 0x40000000 */
#define FDCAN_TXBCIE_CFIE30               FDCAN_TXBCIE_CFIE30_Msk            /*!< </spirit:description> */
#define FDCAN_TXBCIE_CFIE31_Pos           (31U)
#define FDCAN_TXBCIE_CFIE31_Msk           (0x1UL << FDCAN_TXBCIE_CFIE31_Pos)  /*!< 0x80000000 */
#define FDCAN_TXBCIE_CFIE31               FDCAN_TXBCIE_CFIE31_Msk            /*!< </spirit:description> */

/*****************  Bit definition for FDCAN_TXEFC register  ******************/
#define FDCAN_TXEFC_EFSA_Pos              (2U)
#define FDCAN_TXEFC_EFSA_Msk              (0x3FFFUL << FDCAN_TXEFC_EFSA_Pos)  /*!< 0x0000FFFC */
#define FDCAN_TXEFC_EFSA                  FDCAN_TXEFC_EFSA_Msk               /*!< </spirit:description> */
#define FDCAN_TXEFC_EFS_Pos               (16U)
#define FDCAN_TXEFC_EFS_Msk               (0x3FUL << FDCAN_TXEFC_EFS_Pos)     /*!< 0x003F0000 */
#define FDCAN_TXEFC_EFS                   FDCAN_TXEFC_EFS_Msk                /*!< </spirit:description> */
#define FDCAN_TXEFC_EFWM_Pos              (24U)
#define FDCAN_TXEFC_EFWM_Msk              (0x3FUL << FDCAN_TXEFC_EFWM_Pos)    /*!< 0x3F000000 */
#define FDCAN_TXEFC_EFWM                  FDCAN_TXEFC_EFWM_Msk               /*!< </spirit:description> */

/*****************  Bit definition for FDCAN_TXEFS register  ******************/
#define FDCAN_TXEFS_EFFL_Pos              (0U)
#define FDCAN_TXEFS_EFFL_Msk              (0x3FUL << FDCAN_TXEFS_EFFL_Pos)    /*!< 0x0000003F */
#define FDCAN_TXEFS_EFFL                  FDCAN_TXEFS_EFFL_Msk               /*!< </spirit:description> */
#define FDCAN_TXEFS_EFGI_Pos              (8U)
#define FDCAN_TXEFS_EFGI_Msk              (0x1FUL << FDCAN_TXEFS_EFGI_Pos)    /*!< 0x00001F00 */
#define FDCAN_TXEFS_EFGI                  FDCAN_TXEFS_EFGI_Msk               /*!< </spirit:description> */
#define FDCAN_TXEFS_EFPI_Pos              (16U)
#define FDCAN_TXEFS_EFPI_Msk              (0x1FUL << FDCAN_TXEFS_EFPI_Pos)    /*!< 0x001F0000 */
#define FDCAN_TXEFS_EFPI                  FDCAN_TXEFS_EFPI_Msk               /*!< </spirit:description> */
#define FDCAN_TXEFS_EFF_Pos               (24U)
#define FDCAN_TXEFS_EFF_Msk               (0x1UL << FDCAN_TXEFS_EFF_Pos)      /*!< 0x01000000 */
#define FDCAN_TXEFS_EFF                   FDCAN_TXEFS_EFF_Msk                /*!< </spirit:description> */
#define FDCAN_TXEFS_TEFL_Pos              (25U)
#define FDCAN_TXEFS_TEFL_Msk              (0x1UL << FDCAN_TXEFS_TEFL_Pos)     /*!< 0x02000000 */
#define FDCAN_TXEFS_TEFL                  FDCAN_TXEFS_TEFL_Msk               /*!< </spirit:description> */

/*****************  Bit definition for FDCAN_TXEFA register  ******************/
#define FDCAN_TXEFA_EFAI_Pos              (0U)
#define FDCAN_TXEFA_EFAI_Msk              (0x1FUL << FDCAN_TXEFA_EFAI_Pos)    /*!< 0x0000001F */
#define FDCAN_TXEFA_EFAI                  FDCAN_TXEFA_EFAI_Msk               /*!< </spirit:description> */

/****************  Bit definition for FDCAN_TSU_CREL register  ****************/
#define FDCAN_TSU_CREL_DAY_Pos            (0U)
#define FDCAN_TSU_CREL_DAY_Msk            (0xFFUL << FDCAN_TSU_CREL_DAY_Pos)  /*!< 0x000000FF */
#define FDCAN_TSU_CREL_DAY                FDCAN_TSU_CREL_DAY_Msk             /*!< Time Stamp Day */
#define FDCAN_TSU_CREL_MON_Pos            (8U)
#define FDCAN_TSU_CREL_MON_Msk            (0xFFUL << FDCAN_TSU_CREL_MON_Pos)  /*!< 0x0000FF00 */
#define FDCAN_TSU_CREL_MON                FDCAN_TSU_CREL_MON_Msk             /*!< Time Stamp Month */
#define FDCAN_TSU_CREL_YEAR_Pos           (16U)
#define FDCAN_TSU_CREL_YEAR_Msk           (0xFUL << FDCAN_TSU_CREL_YEAR_Pos)  /*!< 0x000F0000 */
#define FDCAN_TSU_CREL_YEAR               FDCAN_TSU_CREL_YEAR_Msk            /*!< Time Stamp Year */
#define FDCAN_TSU_CREL_SUBSTEP_Pos        (20U)
#define FDCAN_TSU_CREL_SUBSTEP_Msk        (0xFUL << FDCAN_TSU_CREL_SUBSTEP_Pos) /*!< 0x00F00000 */
#define FDCAN_TSU_CREL_SUBSTEP            FDCAN_TSU_CREL_SUBSTEP_Msk         /*!< </spirit:description> */
#define FDCAN_TSU_CREL_STEP_Pos           (24U)
#define FDCAN_TSU_CREL_STEP_Msk           (0xFUL << FDCAN_TSU_CREL_STEP_Pos)  /*!< 0x0F000000 */
#define FDCAN_TSU_CREL_STEP               FDCAN_TSU_CREL_STEP_Msk            /*!< </spirit:description> */
#define FDCAN_TSU_CREL_REL_Pos            (28U)
#define FDCAN_TSU_CREL_REL_Msk            (0xFUL << FDCAN_TSU_CREL_REL_Pos)   /*!< 0xF0000000 */
#define FDCAN_TSU_CREL_REL                FDCAN_TSU_CREL_REL_Msk             /*!< </spirit:description> */

/***************  Bit definition for FDCAN_TSU_TSCFG register  ****************/
#define FDCAN_TSU_TSCFG_TSUE_Pos          (0U)
#define FDCAN_TSU_TSCFG_TSUE_Msk          (0x1UL << FDCAN_TSU_TSCFG_TSUE_Pos) /*!< 0x00000001 */
#define FDCAN_TSU_TSCFG_TSUE              FDCAN_TSU_TSCFG_TSUE_Msk           /*!< Time Stamp Unit Enable */
#define FDCAN_TSU_TSCFG_TBCS_Pos          (1U)
#define FDCAN_TSU_TSCFG_TBCS_Msk          (0x1UL << FDCAN_TSU_TSCFG_TBCS_Pos) /*!< 0x00000002 */
#define FDCAN_TSU_TSCFG_TBCS              FDCAN_TSU_TSCFG_TBCS_Msk           /*!< Time Base Counter Select */
#define FDCAN_TSU_TSCFG_SCP_Pos           (2U)
#define FDCAN_TSU_TSCFG_SCP_Msk           (0x1UL << FDCAN_TSU_TSCFG_SCP_Pos)  /*!< 0x00000004 */
#define FDCAN_TSU_TSCFG_SCP               FDCAN_TSU_TSCFG_SCP_Msk            /*!< </spirit:description> */
#define FDCAN_TSU_TSCFG_TBPRE_Pos         (8U)
#define FDCAN_TSU_TSCFG_TBPRE_Msk         (0xFFUL << FDCAN_TSU_TSCFG_TBPRE_Pos) /*!< 0x0000FF00 */
#define FDCAN_TSU_TSCFG_TBPRE             FDCAN_TSU_TSCFG_TBPRE_Msk          /*!< </spirit:description> */

/****************  Bit definition for FDCAN_TSU_TSS1 register  ****************/
#define FDCAN_TSU_TSS1_TSN0_Pos           (0U)
#define FDCAN_TSU_TSS1_TSN0_Msk           (0x1UL << FDCAN_TSU_TSS1_TSN0_Pos)  /*!< 0x00000001 */
#define FDCAN_TSU_TSS1_TSN0               FDCAN_TSU_TSS1_TSN0_Msk            /*!< </spirit:description> */
#define FDCAN_TSU_TSS1_TSN1_Pos           (1U)
#define FDCAN_TSU_TSS1_TSN1_Msk           (0x1UL << FDCAN_TSU_TSS1_TSN1_Pos)  /*!< 0x00000002 */
#define FDCAN_TSU_TSS1_TSN1               FDCAN_TSU_TSS1_TSN1_Msk            /*!< </spirit:description> */
#define FDCAN_TSU_TSS1_TSN2_Pos           (2U)
#define FDCAN_TSU_TSS1_TSN2_Msk           (0x1UL << FDCAN_TSU_TSS1_TSN2_Pos)  /*!< 0x00000004 */
#define FDCAN_TSU_TSS1_TSN2               FDCAN_TSU_TSS1_TSN2_Msk            /*!< </spirit:description> */
#define FDCAN_TSU_TSS1_TSN3_Pos           (3U)
#define FDCAN_TSU_TSS1_TSN3_Msk           (0x1UL << FDCAN_TSU_TSS1_TSN3_Pos)  /*!< 0x00000008 */
#define FDCAN_TSU_TSS1_TSN3               FDCAN_TSU_TSS1_TSN3_Msk            /*!< </spirit:description> */
#define FDCAN_TSU_TSS1_TSN4_Pos           (4U)
#define FDCAN_TSU_TSS1_TSN4_Msk           (0x1UL << FDCAN_TSU_TSS1_TSN4_Pos)  /*!< 0x00000010 */
#define FDCAN_TSU_TSS1_TSN4               FDCAN_TSU_TSS1_TSN4_Msk            /*!< </spirit:description> */
#define FDCAN_TSU_TSS1_TSN5_Pos           (5U)
#define FDCAN_TSU_TSS1_TSN5_Msk           (0x1UL << FDCAN_TSU_TSS1_TSN5_Pos)  /*!< 0x00000020 */
#define FDCAN_TSU_TSS1_TSN5               FDCAN_TSU_TSS1_TSN5_Msk            /*!< </spirit:description> */
#define FDCAN_TSU_TSS1_TSN6_Pos           (6U)
#define FDCAN_TSU_TSS1_TSN6_Msk           (0x1UL << FDCAN_TSU_TSS1_TSN6_Pos)  /*!< 0x00000040 */
#define FDCAN_TSU_TSS1_TSN6               FDCAN_TSU_TSS1_TSN6_Msk            /*!< </spirit:description> */
#define FDCAN_TSU_TSS1_TSN7_Pos           (7U)
#define FDCAN_TSU_TSS1_TSN7_Msk           (0x1UL << FDCAN_TSU_TSS1_TSN7_Pos)  /*!< 0x00000080 */
#define FDCAN_TSU_TSS1_TSN7               FDCAN_TSU_TSS1_TSN7_Msk            /*!< </spirit:description> */
#define FDCAN_TSU_TSS1_TSN8_Pos           (8U)
#define FDCAN_TSU_TSS1_TSN8_Msk           (0x1UL << FDCAN_TSU_TSS1_TSN8_Pos)  /*!< 0x00000100 */
#define FDCAN_TSU_TSS1_TSN8               FDCAN_TSU_TSS1_TSN8_Msk            /*!< </spirit:description> */
#define FDCAN_TSU_TSS1_TSN9_Pos           (9U)
#define FDCAN_TSU_TSS1_TSN9_Msk           (0x1UL << FDCAN_TSU_TSS1_TSN9_Pos)  /*!< 0x00000200 */
#define FDCAN_TSU_TSS1_TSN9               FDCAN_TSU_TSS1_TSN9_Msk            /*!< </spirit:description> */
#define FDCAN_TSU_TSS1_TSN10_Pos          (10U)
#define FDCAN_TSU_TSS1_TSN10_Msk          (0x1UL << FDCAN_TSU_TSS1_TSN10_Pos) /*!< 0x00000400 */
#define FDCAN_TSU_TSS1_TSN10              FDCAN_TSU_TSS1_TSN10_Msk           /*!< </spirit:description> */
#define FDCAN_TSU_TSS1_TSN11_Pos          (11U)
#define FDCAN_TSU_TSS1_TSN11_Msk          (0x1UL << FDCAN_TSU_TSS1_TSN11_Pos) /*!< 0x00000800 */
#define FDCAN_TSU_TSS1_TSN11              FDCAN_TSU_TSS1_TSN11_Msk           /*!< </spirit:description> */
#define FDCAN_TSU_TSS1_TSN12_Pos          (12U)
#define FDCAN_TSU_TSS1_TSN12_Msk          (0x1UL << FDCAN_TSU_TSS1_TSN12_Pos) /*!< 0x00001000 */
#define FDCAN_TSU_TSS1_TSN12              FDCAN_TSU_TSS1_TSN12_Msk           /*!< </spirit:description> */
#define FDCAN_TSU_TSS1_TSN13_Pos          (13U)
#define FDCAN_TSU_TSS1_TSN13_Msk          (0x1UL << FDCAN_TSU_TSS1_TSN13_Pos) /*!< 0x00002000 */
#define FDCAN_TSU_TSS1_TSN13              FDCAN_TSU_TSS1_TSN13_Msk           /*!< </spirit:description> */
#define FDCAN_TSU_TSS1_TSN14_Pos          (14U)
#define FDCAN_TSU_TSS1_TSN14_Msk          (0x1UL << FDCAN_TSU_TSS1_TSN14_Pos) /*!< 0x00004000 */
#define FDCAN_TSU_TSS1_TSN14              FDCAN_TSU_TSS1_TSN14_Msk           /*!< </spirit:description> */
#define FDCAN_TSU_TSS1_TSN15_Pos          (15U)
#define FDCAN_TSU_TSS1_TSN15_Msk          (0x1UL << FDCAN_TSU_TSS1_TSN15_Pos) /*!< 0x00008000 */
#define FDCAN_TSU_TSS1_TSN15              FDCAN_TSU_TSS1_TSN15_Msk           /*!< </spirit:description> */
#define FDCAN_TSU_TSS1_TSL0_Pos           (0U)
#define FDCAN_TSU_TSS1_TSL0_Msk           (0x1UL << FDCAN_TSU_TSS1_TSL0_Pos)  /*!< 0x00000001 */
#define FDCAN_TSU_TSS1_TSL0               FDCAN_TSU_TSS1_TSL0_Msk            /*!< </spirit:description> */
#define FDCAN_TSU_TSS1_TSL1_Pos           (1U)
#define FDCAN_TSU_TSS1_TSL1_Msk           (0x1UL << FDCAN_TSU_TSS1_TSL1_Pos)  /*!< 0x00000002 */
#define FDCAN_TSU_TSS1_TSL1               FDCAN_TSU_TSS1_TSL1_Msk            /*!< </spirit:description> */
#define FDCAN_TSU_TSS1_TSL2_Pos           (2U)
#define FDCAN_TSU_TSS1_TSL2_Msk           (0x1UL << FDCAN_TSU_TSS1_TSL2_Pos)  /*!< 0x00000004 */
#define FDCAN_TSU_TSS1_TSL2               FDCAN_TSU_TSS1_TSL2_Msk            /*!< </spirit:description> */
#define FDCAN_TSU_TSS1_TSL3_Pos           (3U)
#define FDCAN_TSU_TSS1_TSL3_Msk           (0x1UL << FDCAN_TSU_TSS1_TSL3_Pos)  /*!< 0x00000008 */
#define FDCAN_TSU_TSS1_TSL3               FDCAN_TSU_TSS1_TSL3_Msk            /*!< </spirit:description> */
#define FDCAN_TSU_TSS1_TSL4_Pos           (4U)
#define FDCAN_TSU_TSS1_TSL4_Msk           (0x1UL << FDCAN_TSU_TSS1_TSL4_Pos)  /*!< 0x00000010 */
#define FDCAN_TSU_TSS1_TSL4               FDCAN_TSU_TSS1_TSL4_Msk            /*!< </spirit:description> */
#define FDCAN_TSU_TSS1_TSL5_Pos           (5U)
#define FDCAN_TSU_TSS1_TSL5_Msk           (0x1UL << FDCAN_TSU_TSS1_TSL5_Pos)  /*!< 0x00000020 */
#define FDCAN_TSU_TSS1_TSL5               FDCAN_TSU_TSS1_TSL5_Msk            /*!< </spirit:description> */
#define FDCAN_TSU_TSS1_TSL6_Pos           (6U)
#define FDCAN_TSU_TSS1_TSL6_Msk           (0x1UL << FDCAN_TSU_TSS1_TSL6_Pos)  /*!< 0x00000040 */
#define FDCAN_TSU_TSS1_TSL6               FDCAN_TSU_TSS1_TSL6_Msk            /*!< </spirit:description> */
#define FDCAN_TSU_TSS1_TSL7_Pos           (7U)
#define FDCAN_TSU_TSS1_TSL7_Msk           (0x1UL << FDCAN_TSU_TSS1_TSL7_Pos)  /*!< 0x00000080 */
#define FDCAN_TSU_TSS1_TSL7               FDCAN_TSU_TSS1_TSL7_Msk            /*!< </spirit:description> */
#define FDCAN_TSU_TSS1_TSL8_Pos           (8U)
#define FDCAN_TSU_TSS1_TSL8_Msk           (0x1UL << FDCAN_TSU_TSS1_TSL8_Pos)  /*!< 0x00000100 */
#define FDCAN_TSU_TSS1_TSL8               FDCAN_TSU_TSS1_TSL8_Msk            /*!< </spirit:description> */
#define FDCAN_TSU_TSS1_TSL9_Pos           (9U)
#define FDCAN_TSU_TSS1_TSL9_Msk           (0x1UL << FDCAN_TSU_TSS1_TSL9_Pos)  /*!< 0x00000200 */
#define FDCAN_TSU_TSS1_TSL9               FDCAN_TSU_TSS1_TSL9_Msk            /*!< </spirit:description> */
#define FDCAN_TSU_TSS1_TSL10_Pos          (10U)
#define FDCAN_TSU_TSS1_TSL10_Msk          (0x1UL << FDCAN_TSU_TSS1_TSL10_Pos) /*!< 0x00000400 */
#define FDCAN_TSU_TSS1_TSL10              FDCAN_TSU_TSS1_TSL10_Msk           /*!< </spirit:description> */
#define FDCAN_TSU_TSS1_TSL11_Pos          (11U)
#define FDCAN_TSU_TSS1_TSL11_Msk          (0x1UL << FDCAN_TSU_TSS1_TSL11_Pos) /*!< 0x00000800 */
#define FDCAN_TSU_TSS1_TSL11              FDCAN_TSU_TSS1_TSL11_Msk           /*!< </spirit:description> */
#define FDCAN_TSU_TSS1_TSL12_Pos          (12U)
#define FDCAN_TSU_TSS1_TSL12_Msk          (0x1UL << FDCAN_TSU_TSS1_TSL12_Pos) /*!< 0x00001000 */
#define FDCAN_TSU_TSS1_TSL12              FDCAN_TSU_TSS1_TSL12_Msk           /*!< </spirit:description> */
#define FDCAN_TSU_TSS1_TSL13_Pos          (13U)
#define FDCAN_TSU_TSS1_TSL13_Msk          (0x1UL << FDCAN_TSU_TSS1_TSL13_Pos) /*!< 0x00002000 */
#define FDCAN_TSU_TSS1_TSL13              FDCAN_TSU_TSS1_TSL13_Msk           /*!< </spirit:description> */
#define FDCAN_TSU_TSS1_TSL14_Pos          (14U)
#define FDCAN_TSU_TSS1_TSL14_Msk          (0x1UL << FDCAN_TSU_TSS1_TSL14_Pos) /*!< 0x00004000 */
#define FDCAN_TSU_TSS1_TSL14              FDCAN_TSU_TSS1_TSL14_Msk           /*!< </spirit:description> */
#define FDCAN_TSU_TSS1_TSL15_Pos          (15U)
#define FDCAN_TSU_TSS1_TSL15_Msk          (0x1UL << FDCAN_TSU_TSS1_TSL15_Pos) /*!< 0x00008000 */
#define FDCAN_TSU_TSS1_TSL15              FDCAN_TSU_TSS1_TSL15_Msk           /*!< </spirit:description> */

/****************  Bit definition for FDCAN_TSU_TSS2 register  ****************/
#define FDCAN_TSU_TSS2_TSP_Pos            (0U)
#define FDCAN_TSU_TSS2_TSP_Msk            (0xFUL << FDCAN_TSU_TSS2_TSP_Pos)   /*!< 0x0000000F */
#define FDCAN_TSU_TSS2_TSP                FDCAN_TSU_TSS2_TSP_Msk             /*!< </spirit:description> */
#define FDCAN_TSU_TSS2_NTSG_Pos           (12U)
#define FDCAN_TSU_TSS2_NTSG_Msk           (0x3UL << FDCAN_TSU_TSS2_NTSG_Pos)  /*!< 0x00003000 */
#define FDCAN_TSU_TSS2_NTSG               FDCAN_TSU_TSS2_NTSG_Msk            /*!< </spirit:description> */
#define FDCAN_TSU_TSS2_ITBG_Pos           (14U)
#define FDCAN_TSU_TSS2_ITBG_Msk           (0x3UL << FDCAN_TSU_TSS2_ITBG_Pos)  /*!< 0x0000C000 */
#define FDCAN_TSU_TSS2_ITBG               FDCAN_TSU_TSS2_ITBG_Msk            /*!< </spirit:description> */

/*****************  Bit definition for FDCAN_TSU_TS register  *****************/
#define FDCAN_TSU_TS_TS_Pos               (0U)
#define FDCAN_TSU_TS_TS_Msk               (0xFFFFFFFFUL << FDCAN_TSU_TS_TS_Pos) /*!< 0xFFFFFFFF */
#define FDCAN_TSU_TS_TS                   FDCAN_TSU_TS_TS_Msk                /*!< </spirit:description> */

/****************  Bit definition for FDCAN_TSU_ATB register  *****************/
#define FDCAN_TSU_ATB_TB_Pos              (0U)
#define FDCAN_TSU_ATB_TB_Msk              (0xFFFFFFFFUL << FDCAN_TSU_ATB_TB_Pos)  /*!< 0xFFFFFFFF */
#define FDCAN_TSU_ATB_TB                  FDCAN_TSU_ATB_TB_Msk               /*!< </spirit:description> */

/*****************  Bit definition for FDCAN_DMU_CR register  *****************/
#define FDCAN_DMU_CR_DAY_Pos              (0U)
#define FDCAN_DMU_CR_DAY_Msk              (0xFFUL << FDCAN_DMU_CR_DAY_Pos)    /*!< 0x000000FF */
#define FDCAN_DMU_CR_DAY                  FDCAN_DMU_CR_DAY_Msk               /*!< Time Stamp Day */
#define FDCAN_DMU_CR_MON_Pos              (8U)
#define FDCAN_DMU_CR_MON_Msk              (0xFFUL << FDCAN_DMU_CR_MON_Pos)    /*!< 0x0000FF00 */
#define FDCAN_DMU_CR_MON                  FDCAN_DMU_CR_MON_Msk               /*!< Time Stamp Month */
#define FDCAN_DMU_CR_YEAR_Pos             (16U)
#define FDCAN_DMU_CR_YEAR_Msk             (0xFUL << FDCAN_DMU_CR_YEAR_Pos)    /*!< 0x000F0000 */
#define FDCAN_DMU_CR_YEAR                 FDCAN_DMU_CR_YEAR_Msk              /*!< Time Stamp Year */
#define FDCAN_DMU_CR_SUBSTEP_Pos          (20U)
#define FDCAN_DMU_CR_SUBSTEP_Msk          (0xFUL << FDCAN_DMU_CR_SUBSTEP_Pos) /*!< 0x00F00000 */
#define FDCAN_DMU_CR_SUBSTEP              FDCAN_DMU_CR_SUBSTEP_Msk           /*!< </spirit:description> */
#define FDCAN_DMU_CR_STEP_Pos             (24U)
#define FDCAN_DMU_CR_STEP_Msk             (0xFUL << FDCAN_DMU_CR_STEP_Pos)    /*!< 0x0F000000 */
#define FDCAN_DMU_CR_STEP                 FDCAN_DMU_CR_STEP_Msk              /*!< </spirit:description> */
#define FDCAN_DMU_CR_REL_Pos              (28U)
#define FDCAN_DMU_CR_REL_Msk              (0xFUL << FDCAN_DMU_CR_REL_Pos)     /*!< 0xF0000000 */
#define FDCAN_DMU_CR_REL                  FDCAN_DMU_CR_REL_Msk               /*!< </spirit:description> */

/*****************  Bit definition for FDCAN_DMU_I register  ******************/
#define FDCAN_DMU_I_TXR_Pos               (0U)
#define FDCAN_DMU_I_TXR_Msk               (0x1UL << FDCAN_DMU_I_TXR_Pos)      /*!< 0x00000001 */
#define FDCAN_DMU_I_TXR                   FDCAN_DMU_I_TXR_Msk                /*!< </spirit:description> */
#define FDCAN_DMU_I_RX0R_Pos              (1U)
#define FDCAN_DMU_I_RX0R_Msk              (0x1UL << FDCAN_DMU_I_RX0R_Pos)     /*!< 0x00000002 */
#define FDCAN_DMU_I_RX0R                  FDCAN_DMU_I_RX0R_Msk               /*!< </spirit:description> */
#define FDCAN_DMU_I_RX1R_Pos              (2U)
#define FDCAN_DMU_I_RX1R_Msk              (0x1UL << FDCAN_DMU_I_RX1R_Pos)     /*!< 0x00000004 */
#define FDCAN_DMU_I_RX1R                  FDCAN_DMU_I_RX1R_Msk               /*!< </spirit:description> */
#define FDCAN_DMU_I_TFQPIP_Pos            (8U)
#define FDCAN_DMU_I_TFQPIP_Msk            (0x1FUL << FDCAN_DMU_I_TFQPIP_Pos)  /*!< 0x00001F00 */
#define FDCAN_DMU_I_TFQPIP                FDCAN_DMU_I_TFQPIP_Msk             /*!< </spirit:description> */
#define FDCAN_DMU_I_ENA_Pos               (15U)
#define FDCAN_DMU_I_ENA_Msk               (0x1UL << FDCAN_DMU_I_ENA_Pos)      /*!< 0x00008000 */
#define FDCAN_DMU_I_ENA                   FDCAN_DMU_I_ENA_Msk                /*!< </spirit:description> */
#define FDCAN_DMU_I_DHES_Pos              (16U)
#define FDCAN_DMU_I_DHES_Msk              (0x7UL << FDCAN_DMU_I_DHES_Pos)     /*!< 0x00070000 */
#define FDCAN_DMU_I_DHES                  FDCAN_DMU_I_DHES_Msk               /*!< </spirit:description> */
#define FDCAN_DMU_I_DTX_Pos               (20U)
#define FDCAN_DMU_I_DTX_Msk               (0x1UL << FDCAN_DMU_I_DTX_Pos)      /*!< 0x00100000 */
#define FDCAN_DMU_I_DTX                   FDCAN_DMU_I_DTX_Msk                /*!< </spirit:description> */
#define FDCAN_DMU_I_DTX0_Pos              (21U)
#define FDCAN_DMU_I_DTX0_Msk              (0x1UL << FDCAN_DMU_I_DTX0_Pos)     /*!< 0x00200000 */
#define FDCAN_DMU_I_DTX0                  FDCAN_DMU_I_DTX0_Msk               /*!< </spirit:description> */
#define FDCAN_DMU_I_DTX1_Pos              (22U)
#define FDCAN_DMU_I_DTX1_Msk              (0x1UL << FDCAN_DMU_I_DTX1_Pos)     /*!< 0x00400000 */
#define FDCAN_DMU_I_DTX1                  FDCAN_DMU_I_DTX1_Msk               /*!< </spirit:description> */
#define FDCAN_DMU_I_EHS_Pos               (24U)
#define FDCAN_DMU_I_EHS_Msk               (0x7UL << FDCAN_DMU_I_EHS_Pos)      /*!< 0x07000000 */
#define FDCAN_DMU_I_EHS                   FDCAN_DMU_I_EHS_Msk                /*!< </spirit:description> */
#define FDCAN_DMU_I_TX_Pos                (28U)
#define FDCAN_DMU_I_TX_Msk                (0x1UL << FDCAN_DMU_I_TX_Pos)       /*!< 0x10000000 */
#define FDCAN_DMU_I_TX                    FDCAN_DMU_I_TX_Msk                 /*!< </spirit:description> */
#define FDCAN_DMU_I_RX0_Pos               (29U)
#define FDCAN_DMU_I_RX0_Msk               (0x1UL << FDCAN_DMU_I_RX0_Pos)      /*!< 0x20000000 */
#define FDCAN_DMU_I_RX0                   FDCAN_DMU_I_RX0_Msk                /*!< </spirit:description> */
#define FDCAN_DMU_I_RX1_Pos               (30U)
#define FDCAN_DMU_I_RX1_Msk               (0x1UL << FDCAN_DMU_I_RX1_Pos)      /*!< 0x40000000 */
#define FDCAN_DMU_I_RX1                   FDCAN_DMU_I_RX1_Msk                /*!< </spirit:description> */
#define FDCAN_DMU_I_TXE_Pos               (31U)
#define FDCAN_DMU_I_TXE_Msk               (0x1UL << FDCAN_DMU_I_TXE_Pos)      /*!< 0x80000000 */
#define FDCAN_DMU_I_TXE                   FDCAN_DMU_I_TXE_Msk                /*!< </spirit:description> */

/*****************  Bit definition for FDCAN_DMU_QC register  *****************/
#define FDCAN_DMU_QC_TXEEC_Pos            (0U)
#define FDCAN_DMU_QC_TXEEC_Msk            (0xFFUL << FDCAN_DMU_QC_TXEEC_Pos)  /*!< 0x000000FF */
#define FDCAN_DMU_QC_TXEEC                FDCAN_DMU_QC_TXEEC_Msk             /*!< </spirit:description> */
#define FDCAN_DMU_QC_RX0EDC_Pos           (8U)
#define FDCAN_DMU_QC_RX0EDC_Msk           (0xFFUL << FDCAN_DMU_QC_RX0EDC_Pos) /*!< 0x0000FF00 */
#define FDCAN_DMU_QC_RX0EDC               FDCAN_DMU_QC_RX0EDC_Msk            /*!< </spirit:description> */
#define FDCAN_DMU_QC_RX1EDC_Pos           (16U)
#define FDCAN_DMU_QC_RX1EDC_Msk           (0xFFUL << FDCAN_DMU_QC_RX1EDC_Pos) /*!< 0x00FF0000 */
#define FDCAN_DMU_QC_RX1EDC               FDCAN_DMU_QC_RX1EDC_Msk            /*!< </spirit:description> */
#define FDCAN_DMU_QC_TXEEDC_Pos           (24U)
#define FDCAN_DMU_QC_TXEEDC_Msk           (0xFFUL << FDCAN_DMU_QC_TXEEDC_Pos) /*!< 0xFF000000 */
#define FDCAN_DMU_QC_TXEEDC               FDCAN_DMU_QC_TXEEDC_Msk            /*!< </spirit:description> */

/*****************  Bit definition for FDCAN_DMU_IR register  *****************/
#define FDCAN_DMU_IR_TXENSA_Pos           (0U)
#define FDCAN_DMU_IR_TXENSA_Msk           (0x1UL << FDCAN_DMU_IR_TXENSA_Pos)  /*!< 0x00000001 */
#define FDCAN_DMU_IR_TXENSA               FDCAN_DMU_IR_TXENSA_Msk            /*!< </spirit:description> */
#define FDCAN_DMU_IR_TXEIE_Pos            (1U)
#define FDCAN_DMU_IR_TXEIE_Msk            (0x1UL << FDCAN_DMU_IR_TXEIE_Pos)   /*!< 0x00000002 */
#define FDCAN_DMU_IR_TXEIE                FDCAN_DMU_IR_TXEIE_Msk             /*!< </spirit:description> */
#define FDCAN_DMU_IR_TXEIAS_Pos           (2U)
#define FDCAN_DMU_IR_TXEIAS_Msk           (0x1UL << FDCAN_DMU_IR_TXEIAS_Pos)  /*!< 0x00000004 */
#define FDCAN_DMU_IR_TXEIAS               FDCAN_DMU_IR_TXEIAS_Msk            /*!< </spirit:description> */
#define FDCAN_DMU_IR_TXEIDLC_Pos          (3U)
#define FDCAN_DMU_IR_TXEIDLC_Msk          (0x1UL << FDCAN_DMU_IR_TXEIDLC_Pos) /*!< 0x00000008 */
#define FDCAN_DMU_IR_TXEIDLC              FDCAN_DMU_IR_TXEIDLC_Msk           /*!< </spirit:description> */
#define FDCAN_DMU_IR_TXEWATA_Pos          (4U)
#define FDCAN_DMU_IR_TXEWATA_Msk          (0x1UL << FDCAN_DMU_IR_TXEWATA_Pos) /*!< 0x00000010 */
#define FDCAN_DMU_IR_TXEWATA              FDCAN_DMU_IR_TXEWATA_Msk           /*!< </spirit:description> */
#define FDCAN_DMU_IR_TXEIR_Pos            (5U)
#define FDCAN_DMU_IR_TXEIR_Msk            (0x1UL << FDCAN_DMU_IR_TXEIR_Pos)   /*!< 0x00000020 */
#define FDCAN_DMU_IR_TXEIR                FDCAN_DMU_IR_TXEIR_Msk             /*!< </spirit:description> */
#define FDCAN_DMU_IR_TXEE_Pos             (6U)
#define FDCAN_DMU_IR_TXEE_Msk             (0x1UL << FDCAN_DMU_IR_TXEE_Pos)    /*!< 0x00000040 */
#define FDCAN_DMU_IR_TXEE                 FDCAN_DMU_IR_TXEE_Msk              /*!< </spirit:description> */
#define FDCAN_DMU_IR_RX0ENSA_Pos          (8U)
#define FDCAN_DMU_IR_RX0ENSA_Msk          (0x1UL << FDCAN_DMU_IR_RX0ENSA_Pos) /*!< 0x00000100 */
#define FDCAN_DMU_IR_RX0ENSA              FDCAN_DMU_IR_RX0ENSA_Msk           /*!< </spirit:description> */
#define FDCAN_DMU_IR_RX0EID_Pos           (9U)
#define FDCAN_DMU_IR_RX0EID_Msk           (0x1UL << FDCAN_DMU_IR_RX0EID_Pos)  /*!< 0x00000200 */
#define FDCAN_DMU_IR_RX0EID               FDCAN_DMU_IR_RX0EID_Msk            /*!< </spirit:description> */
#define FDCAN_DMU_IR_RX0EIAS_Pos          (10U)
#define FDCAN_DMU_IR_RX0EIAS_Msk          (0x1UL << FDCAN_DMU_IR_RX0EIAS_Pos) /*!< 0x00000400 */
#define FDCAN_DMU_IR_RX0EIAS              FDCAN_DMU_IR_RX0EIAS_Msk           /*!< </spirit:description> */
#define FDCAN_DMU_IR_RX0EIW_Pos           (11U)
#define FDCAN_DMU_IR_RX0EIW_Msk           (0x1UL << FDCAN_DMU_IR_RX0EIW_Pos)  /*!< 0x00000800 */
#define FDCAN_DMU_IR_RX0EIW               FDCAN_DMU_IR_RX0EIW_Msk            /*!< </spirit:description> */
#define FDCAN_DMU_IR_RX0ED_Pos            (12U)
#define FDCAN_DMU_IR_RX0ED_Msk            (0x1UL << FDCAN_DMU_IR_RX0ED_Pos)   /*!< 0x00001000 */
#define FDCAN_DMU_IR_RX0ED                FDCAN_DMU_IR_RX0ED_Msk             /*!< </spirit:description> */
#define FDCAN_DMU_IR_RX0EIO_Pos           (13U)
#define FDCAN_DMU_IR_RX0EIO_Msk           (0x1UL << FDCAN_DMU_IR_RX0EIO_Pos)  /*!< 0x00002000 */
#define FDCAN_DMU_IR_RX0EIO               FDCAN_DMU_IR_RX0EIO_Msk            /*!< </spirit:description> */
#define FDCAN_DMU_IR_BEC_Pos              (14U)
#define FDCAN_DMU_IR_BEC_Msk              (0x1UL << FDCAN_DMU_IR_BEC_Pos)     /*!< 0x00004000 */
#define FDCAN_DMU_IR_BEC                  FDCAN_DMU_IR_BEC_Msk               /*!< </spirit:description> */
#define FDCAN_DMU_IR_BEU_Pos              (15U)
#define FDCAN_DMU_IR_BEU_Msk              (0x1UL << FDCAN_DMU_IR_BEU_Pos)     /*!< 0x00008000 */
#define FDCAN_DMU_IR_BEU                  FDCAN_DMU_IR_BEU_Msk               /*!< </spirit:description> */
#define FDCAN_DMU_IR_RX1ENSA_Pos          (16U)
#define FDCAN_DMU_IR_RX1ENSA_Msk          (0x1UL << FDCAN_DMU_IR_RX1ENSA_Pos) /*!< 0x00010000 */
#define FDCAN_DMU_IR_RX1ENSA              FDCAN_DMU_IR_RX1ENSA_Msk           /*!< </spirit:description> */
#define FDCAN_DMU_IR_RX1EID_Pos           (17U)
#define FDCAN_DMU_IR_RX1EID_Msk           (0x1UL << FDCAN_DMU_IR_RX1EID_Pos)  /*!< 0x00020000 */
#define FDCAN_DMU_IR_RX1EID               FDCAN_DMU_IR_RX1EID_Msk            /*!< </spirit:description> */
#define FDCAN_DMU_IR_RX1EIAS_Pos          (18U)
#define FDCAN_DMU_IR_RX1EIAS_Msk          (0x1UL << FDCAN_DMU_IR_RX1EIAS_Pos) /*!< 0x00040000 */
#define FDCAN_DMU_IR_RX1EIAS              FDCAN_DMU_IR_RX1EIAS_Msk           /*!< </spirit:description> */
#define FDCAN_DMU_IR_RX1EIW_Pos           (19U)
#define FDCAN_DMU_IR_RX1EIW_Msk           (0x1UL << FDCAN_DMU_IR_RX1EIW_Pos)  /*!< 0x00080000 */
#define FDCAN_DMU_IR_RX1EIW               FDCAN_DMU_IR_RX1EIW_Msk            /*!< </spirit:description> */
#define FDCAN_DMU_IR_RX1ED_Pos            (20U)
#define FDCAN_DMU_IR_RX1ED_Msk            (0x1UL << FDCAN_DMU_IR_RX1ED_Pos)   /*!< 0x00100000 */
#define FDCAN_DMU_IR_RX1ED                FDCAN_DMU_IR_RX1ED_Msk             /*!< </spirit:description> */
#define FDCAN_DMU_IR_RX1EIO_Pos           (21U)
#define FDCAN_DMU_IR_RX1EIO_Msk           (0x1UL << FDCAN_DMU_IR_RX1EIO_Pos)  /*!< 0x00200000 */
#define FDCAN_DMU_IR_RX1EIO               FDCAN_DMU_IR_RX1EIO_Msk            /*!< </spirit:description> */
#define FDCAN_DMU_IR_TXEENSA_Pos          (24U)
#define FDCAN_DMU_IR_TXEENSA_Msk          (0x1UL << FDCAN_DMU_IR_TXEENSA_Pos) /*!< 0x01000000 */
#define FDCAN_DMU_IR_TXEENSA              FDCAN_DMU_IR_TXEENSA_Msk           /*!< </spirit:description> */
#define FDCAN_DMU_IR_TXEEID_Pos           (25U)
#define FDCAN_DMU_IR_TXEEID_Msk           (0x1UL << FDCAN_DMU_IR_TXEEID_Pos)  /*!< 0x02000000 */
#define FDCAN_DMU_IR_TXEEID               FDCAN_DMU_IR_TXEEID_Msk            /*!< </spirit:description> */
#define FDCAN_DMU_IR_TXEEIAS_Pos          (26U)
#define FDCAN_DMU_IR_TXEEIAS_Msk          (0x1UL << FDCAN_DMU_IR_TXEEIAS_Pos) /*!< 0x04000000 */
#define FDCAN_DMU_IR_TXEEIAS              FDCAN_DMU_IR_TXEEIAS_Msk           /*!< </spirit:description> */
#define FDCAN_DMU_IR_TXEEIW_Pos           (27U)
#define FDCAN_DMU_IR_TXEEIW_Msk           (0x1UL << FDCAN_DMU_IR_TXEEIW_Pos)  /*!< 0x08000000 */
#define FDCAN_DMU_IR_TXEEIW               FDCAN_DMU_IR_TXEEIW_Msk            /*!< </spirit:description> */
#define FDCAN_DMU_IR_TXEED_Pos            (28U)
#define FDCAN_DMU_IR_TXEED_Msk            (0x1UL << FDCAN_DMU_IR_TXEED_Pos)   /*!< 0x10000000 */
#define FDCAN_DMU_IR_TXEED                FDCAN_DMU_IR_TXEED_Msk             /*!< </spirit:description> */
#define FDCAN_DMU_IR_DT_Pos               (29U)
#define FDCAN_DMU_IR_DT_Msk               (0x1UL << FDCAN_DMU_IR_DT_Pos)      /*!< 0x20000000 */
#define FDCAN_DMU_IR_DT                   FDCAN_DMU_IR_DT_Msk                /*!< </spirit:description> */
#define FDCAN_DMU_IR_IAC_Pos              (29U)
#define FDCAN_DMU_IR_IAC_Msk              (0x1UL << FDCAN_DMU_IR_IAC_Pos)     /*!< 0x20000000 */
#define FDCAN_DMU_IR_IAC                  FDCAN_DMU_IR_IAC_Msk               /*!< </spirit:description> */

/*****************  Bit definition for FDCAN_DMU_IE register  *****************/
#define FDCAN_DMU_IE_TXENSAE_Pos          (0U)
#define FDCAN_DMU_IE_TXENSAE_Msk          (0x1UL << FDCAN_DMU_IE_TXENSAE_Pos) /*!< 0x00000001 */
#define FDCAN_DMU_IE_TXENSAE              FDCAN_DMU_IE_TXENSAE_Msk           /*!< </spirit:description> */
#define FDCAN_DMU_IE_TXEIEE_Pos           (1U)
#define FDCAN_DMU_IE_TXEIEE_Msk           (0x1UL << FDCAN_DMU_IE_TXEIEE_Pos)  /*!< 0x00000002 */
#define FDCAN_DMU_IE_TXEIEE               FDCAN_DMU_IE_TXEIEE_Msk            /*!< </spirit:description> */
#define FDCAN_DMU_IE_TXEIASE_Pos          (2U)
#define FDCAN_DMU_IE_TXEIASE_Msk          (0x1UL << FDCAN_DMU_IE_TXEIASE_Pos) /*!< 0x00000004 */
#define FDCAN_DMU_IE_TXEIASE              FDCAN_DMU_IE_TXEIASE_Msk           /*!< </spirit:description> */
#define FDCAN_DMU_IE_TXEIDLCE_Pos         (3U)
#define FDCAN_DMU_IE_TXEIDLCE_Msk          (0x1UL << FDCAN_DMU_IE_TXEIDLCE_Pos) /*!< 0x00000008 */
#define FDCAN_DMU_IE_TXEIDLCE             FDCAN_DMU_IE_TXEIDLCE_Msk          /*!< </spirit:description> */
#define FDCAN_DMU_IE_TXEWATAE_Pos         (4U)
#define FDCAN_DMU_IE_TXEWATAE_Msk          (0x1UL << FDCAN_DMU_IE_TXEWATAE_Pos) /*!< 0x00000010 */
#define FDCAN_DMU_IE_TXEWATAE             FDCAN_DMU_IE_TXEWATAE_Msk          /*!< </spirit:description> */
#define FDCAN_DMU_IE_TXEIRE_Pos           (5U)
#define FDCAN_DMU_IE_TXEIRE_Msk           (0x1UL << FDCAN_DMU_IE_TXEIRE_Pos)  /*!< 0x00000020 */
#define FDCAN_DMU_IE_TXEIRE               FDCAN_DMU_IE_TXEIRE_Msk            /*!< </spirit:description> */
#define FDCAN_DMU_IE_TXEEE_Pos            (6U)
#define FDCAN_DMU_IE_TXEEE_Msk            (0x1UL << FDCAN_DMU_IE_TXEEE_Pos)   /*!< 0x00000040 */
#define FDCAN_DMU_IE_TXEEE                FDCAN_DMU_IE_TXEEE_Msk             /*!< </spirit:description> */
#define FDCAN_DMU_IE_RX0ENSAE_Pos         (8U)
#define FDCAN_DMU_IE_RX0ENSAE_Msk          (0x1UL << FDCAN_DMU_IE_RX0ENSAE_Pos) /*!< 0x00000100 */
#define FDCAN_DMU_IE_RX0ENSAE             FDCAN_DMU_IE_RX0ENSAE_Msk          /*!< </spirit:description> */
#define FDCAN_DMU_IE_RX0EIDE_Pos          (9U)
#define FDCAN_DMU_IE_RX0EIDE_Msk          (0x1UL << FDCAN_DMU_IE_RX0EIDE_Pos) /*!< 0x00000200 */
#define FDCAN_DMU_IE_RX0EIDE              FDCAN_DMU_IE_RX0EIDE_Msk           /*!< </spirit:description> */
#define FDCAN_DMU_IE_RX0EIASE_Pos         (10U)
#define FDCAN_DMU_IE_RX0EIASE_Msk          (0x1UL << FDCAN_DMU_IE_RX0EIASE_Pos) /*!< 0x00000400 */
#define FDCAN_DMU_IE_RX0EIASE             FDCAN_DMU_IE_RX0EIASE_Msk          /*!< </spirit:description> */
#define FDCAN_DMU_IE_RX0EIWE_Pos          (11U)
#define FDCAN_DMU_IE_RX0EIWE_Msk          (0x1UL << FDCAN_DMU_IE_RX0EIWE_Pos) /*!< 0x00000800 */
#define FDCAN_DMU_IE_RX0EIWE              FDCAN_DMU_IE_RX0EIWE_Msk           /*!< </spirit:description> */
#define FDCAN_DMU_IE_RX0EDE_Pos           (12U)
#define FDCAN_DMU_IE_RX0EDE_Msk           (0x1UL << FDCAN_DMU_IE_RX0EDE_Pos)  /*!< 0x00001000 */
#define FDCAN_DMU_IE_RX0EDE               FDCAN_DMU_IE_RX0EDE_Msk            /*!< </spirit:description> */
#define FDCAN_DMU_IE_RX0EIOE_Pos          (13U)
#define FDCAN_DMU_IE_RX0EIOE_Msk          (0x1UL << FDCAN_DMU_IE_RX0EIOE_Pos) /*!< 0x00002000 */
#define FDCAN_DMU_IE_RX0EIOE              FDCAN_DMU_IE_RX0EIOE_Msk           /*!< </spirit:description> */
#define FDCAN_DMU_IE_BECE_Pos             (14U)
#define FDCAN_DMU_IE_BECE_Msk             (0x1UL << FDCAN_DMU_IE_BECE_Pos)    /*!< 0x00004000 */
#define FDCAN_DMU_IE_BECE                 FDCAN_DMU_IE_BECE_Msk              /*!< </spirit:description> */
#define FDCAN_DMU_IE_BEUE_Pos             (15U)
#define FDCAN_DMU_IE_BEUE_Msk             (0x1UL << FDCAN_DMU_IE_BEUE_Pos)    /*!< 0x00008000 */
#define FDCAN_DMU_IE_BEUE                 FDCAN_DMU_IE_BEUE_Msk              /*!< </spirit:description> */
#define FDCAN_DMU_IE_RX1ENSAE_Pos         (16U)
#define FDCAN_DMU_IE_RX1ENSAE_Msk          (0x1UL << FDCAN_DMU_IE_RX1ENSAE_Pos) /*!< 0x00010000 */
#define FDCAN_DMU_IE_RX1ENSAE             FDCAN_DMU_IE_RX1ENSAE_Msk          /*!< </spirit:description> */
#define FDCAN_DMU_IE_RX1EIDE_Pos          (17U)
#define FDCAN_DMU_IE_RX1EIDE_Msk          (0x1UL << FDCAN_DMU_IE_RX1EIDE_Pos) /*!< 0x00020000 */
#define FDCAN_DMU_IE_RX1EIDE              FDCAN_DMU_IE_RX1EIDE_Msk           /*!< </spirit:description> */
#define FDCAN_DMU_IE_RX1EIASE_Pos         (18U)
#define FDCAN_DMU_IE_RX1EIASE_Msk          (0x1UL << FDCAN_DMU_IE_RX1EIASE_Pos) /*!< 0x00040000 */
#define FDCAN_DMU_IE_RX1EIASE             FDCAN_DMU_IE_RX1EIASE_Msk          /*!< </spirit:description> */
#define FDCAN_DMU_IE_RX1EIWE_Pos          (19U)
#define FDCAN_DMU_IE_RX1EIWE_Msk          (0x1UL << FDCAN_DMU_IE_RX1EIWE_Pos) /*!< 0x00080000 */
#define FDCAN_DMU_IE_RX1EIWE              FDCAN_DMU_IE_RX1EIWE_Msk           /*!< </spirit:description> */
#define FDCAN_DMU_IE_RX1EDE_Pos           (20U)
#define FDCAN_DMU_IE_RX1EDE_Msk           (0x1UL << FDCAN_DMU_IE_RX1EDE_Pos)  /*!< 0x00100000 */
#define FDCAN_DMU_IE_RX1EDE               FDCAN_DMU_IE_RX1EDE_Msk            /*!< </spirit:description> */
#define FDCAN_DMU_IE_RX1EIOE_Pos          (21U)
#define FDCAN_DMU_IE_RX1EIOE_Msk          (0x1UL << FDCAN_DMU_IE_RX1EIOE_Pos) /*!< 0x00200000 */
#define FDCAN_DMU_IE_RX1EIOE              FDCAN_DMU_IE_RX1EIOE_Msk           /*!< </spirit:description> */
#define FDCAN_DMU_IE_TXEENSAE_Pos         (24U)
#define FDCAN_DMU_IE_TXEENSAE_Msk          (0x1UL << FDCAN_DMU_IE_TXEENSAE_Pos) /*!< 0x01000000 */
#define FDCAN_DMU_IE_TXEENSAE             FDCAN_DMU_IE_TXEENSAE_Msk          /*!< </spirit:description> */
#define FDCAN_DMU_IE_TXEEIDE_Pos          (25U)
#define FDCAN_DMU_IE_TXEEIDE_Msk          (0x1UL << FDCAN_DMU_IE_TXEEIDE_Pos) /*!< 0x02000000 */
#define FDCAN_DMU_IE_TXEEIDE              FDCAN_DMU_IE_TXEEIDE_Msk           /*!< </spirit:description> */
#define FDCAN_DMU_IE_TXEEIASE_Pos         (26U)
#define FDCAN_DMU_IE_TXEEIASE_Msk          (0x1UL << FDCAN_DMU_IE_TXEEIASE_Pos) /*!< 0x04000000 */
#define FDCAN_DMU_IE_TXEEIASE             FDCAN_DMU_IE_TXEEIASE_Msk          /*!< </spirit:description> */
#define FDCAN_DMU_IE_TXEEIWE_Pos          (27U)
#define FDCAN_DMU_IE_TXEEIWE_Msk          (0x1UL << FDCAN_DMU_IE_TXEEIWE_Pos) /*!< 0x08000000 */
#define FDCAN_DMU_IE_TXEEIWE              FDCAN_DMU_IE_TXEEIWE_Msk           /*!< </spirit:description> */
#define FDCAN_DMU_IE_TXEEDE_Pos           (28U)
#define FDCAN_DMU_IE_TXEEDE_Msk           (0x1UL << FDCAN_DMU_IE_TXEEDE_Pos)  /*!< 0x10000000 */
#define FDCAN_DMU_IE_TXEEDE               FDCAN_DMU_IE_TXEEDE_Msk            /*!< </spirit:description> */
#define FDCAN_DMU_IE_DTE_Pos              (29U)
#define FDCAN_DMU_IE_DTE_Msk              (0x1UL << FDCAN_DMU_IE_DTE_Pos)     /*!< 0x20000000 */
#define FDCAN_DMU_IE_DTE                  FDCAN_DMU_IE_DTE_Msk               /*!< </spirit:description> */
#define FDCAN_DMU_IE_IACE_Pos             (29U)
#define FDCAN_DMU_IE_IACE_Msk             (0x1UL << FDCAN_DMU_IE_IACE_Pos)    /*!< 0x20000000 */
#define FDCAN_DMU_IE_IACE                 FDCAN_DMU_IE_IACE_Msk              /*!< </spirit:description> */

/*****************  Bit definition for FDCAN_DMU_C register  ******************/
#define FDCAN_DMU_C_TTS_Pos               (0U)
#define FDCAN_DMU_C_TTS_Msk               (0x1UL << FDCAN_DMU_C_TTS_Pos)      /*!< 0x00000001 */
#define FDCAN_DMU_C_TTS                   FDCAN_DMU_C_TTS_Msk                /*!< </spirit:description> */

#define FDCAN1_BASE           0x4200A000UL 
#define FDCAN2_BASE           0x4200A800UL 
#define FDCAN3_BASE           0x4200B000UL 
#define FDCAN4_BASE           0x4200B800UL 
#define SRAMCAN_BASE          0x4200C000UL


#define FDCAN1                ((FDCAN_TypeDef *) FDCAN1_BASE) 
#define FDCAN2                ((FDCAN_TypeDef *) FDCAN2_BASE) 
#define FDCAN3                ((FDCAN_TypeDef *) FDCAN3_BASE) 
#define FDCAN4                ((FDCAN_TypeDef *) FDCAN4_BASE)

#endif /* __SR5E1_FDCAN_H */

