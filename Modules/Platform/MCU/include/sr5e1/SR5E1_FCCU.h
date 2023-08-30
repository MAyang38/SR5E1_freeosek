/****************************************************************************
 *                                                                           
 * Copyright (c) 2023 STMicroelectronics - All Rights Reserved               
 *                                                                           
 * License terms: STMicroelectronics Proprietary in accordance with licensing
 * terms SLA0098 at www.st.com.                                              
 *                                                                           
 * THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
 * INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.           
 *                                                                           
 *****************************************************************************/

#ifndef __SR5E1_FCCU_H
#define __SR5E1_FCCU_H


/******************************************************************************/
/*                                                                            */
/*                                FCCU (FCCU)                                 */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO uint32_t CTRL;              /*!< FCCU Control register                                      Address offset: 0x000 */
  __O  uint32_t CTRLK;             /*!< FCCU CTRL Key register                                     Address offset: 0x004 */
  __IO uint32_t CFG;               /*!< FCCU Configuration register                                Address offset: 0x008 */
        uint8_t RESERVED0[16];     /*!< Reserved                                                   Address offset: 0x00C-0x01B */
  __IO uint32_t RF_CFG[4];         /*!< FCCU RF Configuration Register n (RF_CFG[0-2])             Address offset: 0x01C-0x028 */
        uint8_t RESERVED1[32];     /*!< Reserved                                                   Address offset: 0x02C-0x04B */
  __IO uint32_t RFS_CFG[8];        /*!< FCCU RFS Configuration Register n (RFS_CFG[0-5])           Address offset: 0x04C-0x068 */
        uint8_t RESERVED2[20];     /*!< Reserved                                                   Address offset: 0x06C-0x07F */
  __IO uint32_t RF_S[4];           /*!< FCCU RF Status register n (FCCU_RF_S[0-2])                 Address offset: 0x080-0x08C */
  __O  uint32_t RFK;               /*!< FCCU RF Key register (RFK)                                 Address offset: 0x090 */
  __IO uint32_t RF_E[4];           /*!< FCCU RF Enable Register n (FCCU_RF_E[0-2])                 Address offset: 0x094-0x0A0 */
  __IO uint32_t RF_TOE[4];         /*!< FCCU RF Timeout Enable Register n (RF_TOE[0-2])            Address offset: 0x0A4-0x0B0 */
  __IO uint32_t RF_TO;             /*!< FCCU RF Timeout Register (FCCU_RF_TO)                      Address offset: 0x0B4 */
  __IO uint32_t CFG_TO;            /*!< FCCU CFG Timeout Register (FCCU_CFG_TO)                    Address offset: 0x0B8 */
  __IO uint32_t EINOUT;            /*!< FCCU IO Control Register                                   Address offset: 0x0BC */
  __IO uint32_t STAT;              /*!< FCCU Status Register                                       Address offset: 0x0C0 */
  __IO uint32_t N2AF_STATUS;       /*!< FCCU NA Freeze Status Register                             Address offset: 0x0C4 */
  __IO uint32_t A2FF_STATUS;       /*!< FCCU AF Freeze Status Register (A2FF_STATUS)               Address offset: 0x0C8 */
  __IO uint32_t N2FF_STATUS;       /*!< FCCU NF Freeze Status Register (N2FF_STATUS)               Address offset: 0x0CC */
  __IO uint32_t F2A_STATUS;        /*!< FCCU FA Freeze Status Register                             Address offset: 0x0D0 */
        uint8_t RESERVED3[8];      /*!< Reserved                                                   Address offset: 0x0D4-0x0DB */
  __O  uint32_t RFF;               /*!< FCCU RF Fake Register                                      Address offset: 0x0DC */
  __IO uint32_t IRQ_STAT;          /*!< FCCU IRQ Status Register                                   Address offset: 0x0E0 */
  __IO uint32_t IRQ_EN;            /*!< FCCU IRQ Enable Register                                   Address offset: 0x0E4 */
  __IO uint32_t XTMR;              /*!< FCCU XTMR Register                                         Address offset: 0x0E8 */
        uint8_t RESERVED4[4];      /*!< Reserved                                                   Address offset: 0x0EC-0x0EF */
  __O  uint32_t TRANS_LOCK;        /*!< FCCU Transient Register                                    Address offset: 0x0F0 */
  __O  uint32_t PERMNT_LOCK;       /*!< FCCU Permanent Lock Register                               Address offset: 0x0F4 */
  __IO uint32_t DELTA_T;           /*!< FCCU Delta T Register                                      Address offset: 0x0F8 */
  __IO uint32_t IRQ_ALARM_EN[4];   /*!< FCCU IRQ Alarm Enable register n (IRQ_ALARM_EN[0-2])       Address offset: 0x0FC-0x108 */
  __IO uint32_t NMI_EN[4];         /*!< FCCU NMI Enable registers n (NMI_EN[0-2])                  Address offset: 0x10C-0x118 */
  __IO uint32_t EOUT_SIG_EN[4];    /*!< FCCU EOUT Signaling Enable registers n (EOUT_SIG_EN[0-2])  Address offset: 0x11C-0x128 */
  __IO uint32_t NMI2_EN[4];        /*!< FCCU NMI2 Enable registers n (NMI2_EN[0-2])                Address offset: 0x12C-0x138 */
} FCCU_TypeDef;





/******************  Bit definition for FCCU_CTRL register  *******************/

#define FCCU_CTRL_OPR_Pos                           (0U)
#define FCCU_CTRL_OPR_Msk                           (0x1FUL << FCCU_CTRL_OPR_Pos) /*!< 0x0000001F */
#define FCCU_CTRL_OPR                               FCCU_CTRL_OPR_Msk
#define FCCU_CTRL_OPS_Pos                           (6U)
#define FCCU_CTRL_OPS_Msk                           (0x3UL << FCCU_CTRL_OPS_Pos) /*!< 0x000000C0 */
#define FCCU_CTRL_OPS                               FCCU_CTRL_OPS_Msk
#define FCCU_CTRL_DEBUG_Pos                         (9U)
#define FCCU_CTRL_DEBUG_Msk                         (0x1UL << FCCU_CTRL_DEBUG_Pos) /*!< 0x00000200 */
#define FCCU_CTRL_DEBUG                             FCCU_CTRL_DEBUG_Msk

/******************  Bit definition for FCCU_CTRLK register  ******************/

#define FCCU_CTRLK_CTRLK_VAL_Pos                    (0U)
#define FCCU_CTRLK_CTRLK_VAL_Msk                    (0xFFFFFFFFUL << FCCU_CTRLK_CTRLK_VAL_Pos) /*!< 0xFFFFFFFF */
#define FCCU_CTRLK_CTRLK_VAL                        FCCU_CTRLK_CTRLK_VAL_Msk

/*******************  Bit definition for FCCU_CFG register  *******************/

#define FCCU_CFG_FOM_Pos                            (6U)
#define FCCU_CFG_FOM_Msk                            (0x7UL << FCCU_CFG_FOM_Pos) /*!< 0x000001C0 */
#define FCCU_CFG_FOM                                FCCU_CFG_FOM_Msk
#define FCCU_CFG_PS_Pos                             (9U)
#define FCCU_CFG_PS_Msk                             (0x1UL << FCCU_CFG_PS_Pos) /*!< 0x00000200 */
#define FCCU_CFG_PS                                 FCCU_CFG_PS_Msk
#define FCCU_CFG_SM_Pos                             (10U)
#define FCCU_CFG_SM_Msk                             (0x1UL << FCCU_CFG_SM_Pos) /*!< 0x00000400 */
#define FCCU_CFG_SM                                 FCCU_CFG_SM_Msk
#define FCCU_CFG_OD_Pos                             (12U)
#define FCCU_CFG_OD_Msk                             (0x1UL << FCCU_CFG_OD_Pos) /*!< 0x00001000 */
#define FCCU_CFG_OD                                 FCCU_CFG_OD_Msk
#define FCCU_CFG_SET_CLEAR_Pos                      (22U)
#define FCCU_CFG_SET_CLEAR_Msk                      (0x3UL << FCCU_CFG_SET_CLEAR_Pos) /*!< 0x00C00000 */
#define FCCU_CFG_SET_CLEAR                          FCCU_CFG_SET_CLEAR_Msk
#define FCCU_CFG_SET_AFTER_RESET_Pos                (24U)
#define FCCU_CFG_SET_AFTER_RESET_Msk                (0x1UL << FCCU_CFG_SET_AFTER_RESET_Pos) /*!< 0x01000000 */
#define FCCU_CFG_SET_AFTER_RESET                    FCCU_CFG_SET_AFTER_RESET_Msk

/*****************  Bit definition for FCCU_RF_CFG register  ******************/

#define FCCU_RF_CFG_RFC_Pos                         (0U)
#define FCCU_RF_CFG_RFC_Msk                         (0xFFFFFFFFUL << FCCU_RF_CFG_RFC_Pos) /*!< 0xFFFFFFFF */
#define FCCU_RF_CFG_RFC                             FCCU_RF_CFG_RFC_Msk

/*****************  Bit definition for FCCU_RFS_CFG register  *****************/

#define FCCU_RFS_CFG_RFSC0_Pos                      (0U)
#define FCCU_RFS_CFG_RFSC0_Msk                      (0x3UL << FCCU_RFS_CFG_RFSC0_Pos) /*!< 0x00000003 */
#define FCCU_RFS_CFG_RFSC0                          FCCU_RFS_CFG_RFSC0_Msk
#define FCCU_RFS_CFG_RFSC1_Pos                      (2U)
#define FCCU_RFS_CFG_RFSC1_Msk                      (0x3UL << FCCU_RFS_CFG_RFSC1_Pos) /*!< 0x0000000C */
#define FCCU_RFS_CFG_RFSC1                          FCCU_RFS_CFG_RFSC1_Msk
#define FCCU_RFS_CFG_RFSC2_Pos                      (4U)
#define FCCU_RFS_CFG_RFSC2_Msk                      (0x3UL << FCCU_RFS_CFG_RFSC2_Pos) /*!< 0x00000030 */
#define FCCU_RFS_CFG_RFSC2                          FCCU_RFS_CFG_RFSC2_Msk
#define FCCU_RFS_CFG_RFSC3_Pos                      (6U)
#define FCCU_RFS_CFG_RFSC3_Msk                      (0x3UL << FCCU_RFS_CFG_RFSC3_Pos) /*!< 0x000000C0 */
#define FCCU_RFS_CFG_RFSC3                          FCCU_RFS_CFG_RFSC3_Msk
#define FCCU_RFS_CFG_RFSC4_Pos                      (8U)
#define FCCU_RFS_CFG_RFSC4_Msk                      (0x3UL << FCCU_RFS_CFG_RFSC4_Pos) /*!< 0x00000300 */
#define FCCU_RFS_CFG_RFSC4                          FCCU_RFS_CFG_RFSC4_Msk
#define FCCU_RFS_CFG_RFSC5_Pos                      (10U)
#define FCCU_RFS_CFG_RFSC5_Msk                      (0x3UL << FCCU_RFS_CFG_RFSC5_Pos) /*!< 0x00000C00 */
#define FCCU_RFS_CFG_RFSC5                          FCCU_RFS_CFG_RFSC5_Msk
#define FCCU_RFS_CFG_RFSC6_Pos                      (12U)
#define FCCU_RFS_CFG_RFSC6_Msk                      (0x3UL << FCCU_RFS_CFG_RFSC6_Pos) /*!< 0x00003000 */
#define FCCU_RFS_CFG_RFSC6                          FCCU_RFS_CFG_RFSC6_Msk
#define FCCU_RFS_CFG_RFSC7_Pos                      (14U)
#define FCCU_RFS_CFG_RFSC7_Msk                      (0x3UL << FCCU_RFS_CFG_RFSC7_Pos) /*!< 0x0000C000 */
#define FCCU_RFS_CFG_RFSC7                          FCCU_RFS_CFG_RFSC7_Msk
#define FCCU_RFS_CFG_RFSC8_Pos                      (16U)
#define FCCU_RFS_CFG_RFSC8_Msk                      (0x3UL << FCCU_RFS_CFG_RFSC8_Pos) /*!< 0x00030000 */
#define FCCU_RFS_CFG_RFSC8                          FCCU_RFS_CFG_RFSC8_Msk
#define FCCU_RFS_CFG_RFSC9_Pos                      (18U)
#define FCCU_RFS_CFG_RFSC9_Msk                      (0x3UL << FCCU_RFS_CFG_RFSC9_Pos) /*!< 0x000C0000 */
#define FCCU_RFS_CFG_RFSC9                          FCCU_RFS_CFG_RFSC9_Msk
#define FCCU_RFS_CFG_RFSC10_Pos                     (20U)
#define FCCU_RFS_CFG_RFSC10_Msk                     (0x3UL << FCCU_RFS_CFG_RFSC10_Pos) /*!< 0x00300000 */
#define FCCU_RFS_CFG_RFSC10                         FCCU_RFS_CFG_RFSC10_Msk
#define FCCU_RFS_CFG_RFSC11_Pos                     (22U)
#define FCCU_RFS_CFG_RFSC11_Msk                     (0x3UL << FCCU_RFS_CFG_RFSC11_Pos) /*!< 0x00C00000 */
#define FCCU_RFS_CFG_RFSC11                         FCCU_RFS_CFG_RFSC11_Msk
#define FCCU_RFS_CFG_RFSC12_Pos                     (24U)
#define FCCU_RFS_CFG_RFSC12_Msk                     (0x3UL << FCCU_RFS_CFG_RFSC12_Pos) /*!< 0x03000000 */
#define FCCU_RFS_CFG_RFSC12                         FCCU_RFS_CFG_RFSC12_Msk
#define FCCU_RFS_CFG_RFSC13_Pos                     (26U)
#define FCCU_RFS_CFG_RFSC13_Msk                     (0x3UL << FCCU_RFS_CFG_RFSC13_Pos) /*!< 0x0C000000 */
#define FCCU_RFS_CFG_RFSC13                         FCCU_RFS_CFG_RFSC13_Msk
#define FCCU_RFS_CFG_RFSC14_Pos                     (28U)
#define FCCU_RFS_CFG_RFSC14_Msk                     (0x3UL << FCCU_RFS_CFG_RFSC14_Pos) /*!< 0x30000000 */
#define FCCU_RFS_CFG_RFSC14                         FCCU_RFS_CFG_RFSC14_Msk
#define FCCU_RFS_CFG_RFSC15_Pos                     (30U)
#define FCCU_RFS_CFG_RFSC15_Msk                     (0x3UL << FCCU_RFS_CFG_RFSC15_Pos) /*!< 0xC0000000 */
#define FCCU_RFS_CFG_RFSC15                         FCCU_RFS_CFG_RFSC15_Msk

/******************  Bit definition for FCCU_RF_S register  *******************/

#define FCCU_RF_S_RFS_Pos                           (0U)
#define FCCU_RF_S_RFS_Msk                           (0xFFFFFFFFUL << FCCU_RF_S_RFS_Pos) /*!< 0xFFFFFFFF */
#define FCCU_RF_S_RFS                               FCCU_RF_S_RFS_Msk

/*******************  Bit definition for FCCU_RFK register  *******************/

#define FCCU_RFK_RFK_VAL_Pos                        (0U)
#define FCCU_RFK_RFK_VAL_Msk                        (0xFFFFFFFFUL << FCCU_RFK_RFK_VAL_Pos) /*!< 0xFFFFFFFF */
#define FCCU_RFK_RFK_VAL                            FCCU_RFK_RFK_VAL_Msk

/******************  Bit definition for FCCU_RF_E register  *******************/

#define FCCU_RF_E_RFE_Pos                           (0U)
#define FCCU_RF_E_RFE_Msk                           (0xFFFFFFFFUL << FCCU_RF_E_RFE_Pos) /*!< 0xFFFFFFFF */
#define FCCU_RF_E_RFE                               FCCU_RF_E_RFE_Msk

/*****************  Bit definition for FCCU_RF_TOE register  ******************/

#define FCCU_RF_TOE_RFTOE_Pos                       (0U)
#define FCCU_RF_TOE_RFTOE_Msk                       (0xFFFFFFFFUL << FCCU_RF_TOE_RFTOE_Pos) /*!< 0xFFFFFFFF */
#define FCCU_RF_TOE_RFTOE                           FCCU_RF_TOE_RFTOE_Msk

/******************  Bit definition for FCCU_RF_TO register  ******************/

#define FCCU_RF_TO_TO_Pos                           (0U)
#define FCCU_RF_TO_TO_Msk                           (0xFFFFFFFFUL << FCCU_RF_TO_TO_Pos) /*!< 0xFFFFFFFF */
#define FCCU_RF_TO_TO                               FCCU_RF_TO_TO_Msk

/*****************  Bit definition for FCCU_CFG_TO register  ******************/

#define FCCU_CFG_TO_TO_Pos                          (0U)
#define FCCU_CFG_TO_TO_Msk                          (0x7UL << FCCU_CFG_TO_TO_Pos) /*!< 0x00000007 */
#define FCCU_CFG_TO_TO                              FCCU_CFG_TO_TO_Msk

/*****************  Bit definition for FCCU_EINOUT register  ******************/

#define FCCU_EINOUT_EOUT0_Pos                       (0U)
#define FCCU_EINOUT_EOUT0_Msk                       (0x1UL << FCCU_EINOUT_EOUT0_Pos) /*!< 0x00000001 */
#define FCCU_EINOUT_EOUT0                           FCCU_EINOUT_EOUT0_Msk
#define FCCU_EINOUT_EOUT1_Pos                       (1U)
#define FCCU_EINOUT_EOUT1_Msk                       (0x1UL << FCCU_EINOUT_EOUT1_Pos) /*!< 0x00000002 */
#define FCCU_EINOUT_EOUT1                           FCCU_EINOUT_EOUT1_Msk
#define FCCU_EINOUT_EIN0_Pos                        (4U)
#define FCCU_EINOUT_EIN0_Msk                        (0x1UL << FCCU_EINOUT_EIN0_Pos) /*!< 0x00000010 */
#define FCCU_EINOUT_EIN0                            FCCU_EINOUT_EIN0_Msk
#define FCCU_EINOUT_EIN1_Pos                        (5U)
#define FCCU_EINOUT_EIN1_Msk                        (0x1UL << FCCU_EINOUT_EIN1_Pos) /*!< 0x00000020 */
#define FCCU_EINOUT_EIN1                            FCCU_EINOUT_EIN1_Msk

/******************  Bit definition for FCCU_STAT register  *******************/

#define FCCU_STAT_STATUS_Pos                        (0U)
#define FCCU_STAT_STATUS_Msk                        (0x3UL << FCCU_STAT_STATUS_Pos) /*!< 0x00000003 */
#define FCCU_STAT_STATUS                            FCCU_STAT_STATUS_Msk
#define FCCU_STAT_ESTAT_Pos                         (3U)
#define FCCU_STAT_ESTAT_Msk                         (0x1UL << FCCU_STAT_ESTAT_Pos) /*!< 0x00000008 */
#define FCCU_STAT_ESTAT                             FCCU_STAT_ESTAT_Msk
#define FCCU_STAT_PHYSICERRORPIN_Pos                (4U)
#define FCCU_STAT_PHYSICERRORPIN_Msk                (0x3UL << FCCU_STAT_PHYSICERRORPIN_Pos) /*!< 0x00000030 */
#define FCCU_STAT_PHYSICERRORPIN                    FCCU_STAT_PHYSICERRORPIN_Msk

/***************  Bit definition for FCCU_N2AF_STATUS register  ***************/

#define FCCU_N2AF_STATUS_NAFS_Pos                   (0U)
#define FCCU_N2AF_STATUS_NAFS_Msk                   (0xFFUL << FCCU_N2AF_STATUS_NAFS_Pos) /*!< 0x000000FF */
#define FCCU_N2AF_STATUS_NAFS                       FCCU_N2AF_STATUS_NAFS_Msk

/***************  Bit definition for FCCU_A2FF_STATUS register  ***************/

#define FCCU_A2FF_STATUS_AFFS_Pos                   (0U)
#define FCCU_A2FF_STATUS_AFFS_Msk                   (0xFFUL << FCCU_A2FF_STATUS_AFFS_Pos) /*!< 0x000000FF */
#define FCCU_A2FF_STATUS_AFFS                       FCCU_A2FF_STATUS_AFFS_Msk
#define FCCU_A2FF_STATUS_AF_SRC_Pos                 (8U)
#define FCCU_A2FF_STATUS_AF_SRC_Msk                 (0x3UL << FCCU_A2FF_STATUS_AF_SRC_Pos) /*!< 0x00000300 */
#define FCCU_A2FF_STATUS_AF_SRC                     FCCU_A2FF_STATUS_AF_SRC_Msk

/***************  Bit definition for FCCU_N2FF_STATUS register  ***************/

#define FCCU_N2FF_STATUS_NFFS_Pos                   (0U)
#define FCCU_N2FF_STATUS_NFFS_Msk                   (0xFFUL << FCCU_N2FF_STATUS_NFFS_Pos) /*!< 0x000000FF */
#define FCCU_N2FF_STATUS_NFFS                       FCCU_N2FF_STATUS_NFFS_Msk
#define FCCU_N2FF_STATUS_NF_SRC_Pos                 (8U)
#define FCCU_N2FF_STATUS_NF_SRC_Msk                 (0x3UL << FCCU_N2FF_STATUS_NF_SRC_Pos) /*!< 0x00000300 */
#define FCCU_N2FF_STATUS_NF_SRC                     FCCU_N2FF_STATUS_NF_SRC_Msk

/***************  Bit definition for FCCU_F2A_STATUS register  ****************/

#define FCCU_F2A_STATUS_FAFS_Pos                    (0U)
#define FCCU_F2A_STATUS_FAFS_Msk                    (0xFFUL << FCCU_F2A_STATUS_FAFS_Pos) /*!< 0x000000FF */
#define FCCU_F2A_STATUS_FAFS                        FCCU_F2A_STATUS_FAFS_Msk

/*******************  Bit definition for FCCU_RFF register  *******************/

#define FCCU_RFF_FRFC_Pos                           (0U)
#define FCCU_RFF_FRFC_Msk                           (0x7FUL << FCCU_RFF_FRFC_Pos) /*!< 0x0000007F */
#define FCCU_RFF_FRFC                               FCCU_RFF_FRFC_Msk

/****************  Bit definition for FCCU_IRQ_STAT register  *****************/

#define FCCU_IRQ_STAT_CFG_TO_STAT_Pos               (0U)
#define FCCU_IRQ_STAT_CFG_TO_STAT_Msk               (0x1UL << FCCU_IRQ_STAT_CFG_TO_STAT_Pos) /*!< 0x00000001 */
#define FCCU_IRQ_STAT_CFG_TO_STAT                   FCCU_IRQ_STAT_CFG_TO_STAT_Msk
#define FCCU_IRQ_STAT_ALRM_STAT_Pos                 (1U)
#define FCCU_IRQ_STAT_ALRM_STAT_Msk                 (0x1UL << FCCU_IRQ_STAT_ALRM_STAT_Pos) /*!< 0x00000002 */
#define FCCU_IRQ_STAT_ALRM_STAT                     FCCU_IRQ_STAT_ALRM_STAT_Msk
#define FCCU_IRQ_STAT_NMI_STAT_Pos                  (2U)
#define FCCU_IRQ_STAT_NMI_STAT_Msk                  (0x1UL << FCCU_IRQ_STAT_NMI_STAT_Pos) /*!< 0x00000004 */
#define FCCU_IRQ_STAT_NMI_STAT                      FCCU_IRQ_STAT_NMI_STAT_Msk

/*****************  Bit definition for FCCU_IRQ_EN register  ******************/

#define FCCU_IRQ_EN_CFG_TO_IEN_Pos                  (0U)
#define FCCU_IRQ_EN_CFG_TO_IEN_Msk                  (0x1UL << FCCU_IRQ_EN_CFG_TO_IEN_Pos) /*!< 0x00000001 */
#define FCCU_IRQ_EN_CFG_TO_IEN                      FCCU_IRQ_EN_CFG_TO_IEN_Msk

/******************  Bit definition for FCCU_XTMR register  *******************/

#define FCCU_XTMR_VAL_Pos                           (0U)
#define FCCU_XTMR_VAL_Msk                           (0xFFFFFFFFUL << FCCU_XTMR_VAL_Pos) /*!< 0xFFFFFFFF */
#define FCCU_XTMR_VAL                               FCCU_XTMR_VAL_Msk

/***************  Bit definition for FCCU_TRANS_LOCK register  ****************/

#define FCCU_TRANS_LOCK_TRANSKEY_Pos                (0U)
#define FCCU_TRANS_LOCK_TRANSKEY_Msk                (0xFFUL << FCCU_TRANS_LOCK_TRANSKEY_Pos) /*!< 0x000000FF */
#define FCCU_TRANS_LOCK_TRANSKEY                    FCCU_TRANS_LOCK_TRANSKEY_Msk

/***************  Bit definition for FCCU_PERMNT_LOCK register  ***************/

#define FCCU_PERMNT_LOCK_PERMNTKEY_Pos              (0U)
#define FCCU_PERMNT_LOCK_PERMNTKEY_Msk              (0xFFUL << FCCU_PERMNT_LOCK_PERMNTKEY_Pos) /*!< 0x000000FF */
#define FCCU_PERMNT_LOCK_PERMNTKEY                  FCCU_PERMNT_LOCK_PERMNTKEY_Msk

/*****************  Bit definition for FCCU_DELTA_T register  *****************/

#define FCCU_DELTA_T_DELTA_T_VAL_Pos                (0U)
#define FCCU_DELTA_T_DELTA_T_VAL_Msk                (0x3FFFUL << FCCU_DELTA_T_DELTA_T_VAL_Pos) /*!< 0x00003FFF */
#define FCCU_DELTA_T_DELTA_T_VAL                    FCCU_DELTA_T_DELTA_T_VAL_Msk

/**************  Bit definition for FCCU_IRQ_ALARM_EN register  ***************/

#define FCCU_IRQ_ALARM_EN_IRQEN_Pos                 (0U)
#define FCCU_IRQ_ALARM_EN_IRQEN_Msk                 (0xFFFFFFFFUL << FCCU_IRQ_ALARM_EN_IRQEN_Pos) /*!< 0xFFFFFFFF */
#define FCCU_IRQ_ALARM_EN_IRQEN                     FCCU_IRQ_ALARM_EN_IRQEN_Msk

/*****************  Bit definition for FCCU_NMI_EN register  ******************/

#define FCCU_NMI_EN_NMIEN_Pos                       (0U)
#define FCCU_NMI_EN_NMIEN_Msk                       (0xFFFFFFFFUL << FCCU_NMI_EN_NMIEN_Pos) /*!< 0xFFFFFFFF */
#define FCCU_NMI_EN_NMIEN                           FCCU_NMI_EN_NMIEN_Msk

/***************  Bit definition for FCCU_EOUT_SIG_EN register  ***************/

#define FCCU_EOUT_SIG_EN_EOUTEN_Pos                 (0U)
#define FCCU_EOUT_SIG_EN_EOUTEN_Msk                 (0xFFFFFFFFUL << FCCU_EOUT_SIG_EN_EOUTEN_Pos) /*!< 0xFFFFFFFF */
#define FCCU_EOUT_SIG_EN_EOUTEN                     FCCU_EOUT_SIG_EN_EOUTEN_Msk

/*****************  Bit definition for FCCU_NMI2_EN register  *****************/

#define FCCU_NMI2_EN_NMI2EN_Pos                     (0U)
#define FCCU_NMI2_EN_NMI2EN_Msk                     (0x0UL << FCCU_NMI2_EN_NMI2EN_Pos) /*!< 0x00000000 */
#define FCCU_NMI2_EN_NMI2EN                         FCCU_NMI2_EN_NMI2EN_Msk

#define FCCU_BASE                      0x4000fc00UL 

#define FCCU                           ((FCCU_TypeDef *) FCCU_BASE) 

#endif /* __SR5E1_FCCU_H */
