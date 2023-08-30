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

#ifndef __SR5E1_TIM_H
#define __SR5E1_TIM_H

/******************************************************************************/
/*                                                                            */
/*                                (TIM)                                       */
/*                                                                            */
/******************************************************************************/
typedef struct
{
  __IO uint32_t CR1;             /*!< CR1                   Address offset: 0x000 */
  __IO uint32_t CR2;             /*!< CR2                   Address offset: 0x004 */
  __IO uint32_t SMCR;            /*!< SMCR                  Address offset: 0x008 */
  __IO uint32_t DIER;            /*!< DIER                  Address offset: 0x00C */
  __IO uint32_t SR;              /*!< SR                    Address offset: 0x010 */
  __IO uint32_t EGR;             /*!< EGR                   Address offset: 0x014 */
  __IO uint32_t CCMR1;           /*!< CCMR1                 Address offset: 0x018 */
  __IO uint32_t CCMR2;           /*!< CCMR2                 Address offset: 0x01C */
  __IO uint32_t CCER;            /*!< CCER                  Address offset: 0x020 */
  __IO uint32_t CNT;             /*!< CNT                   Address offset: 0x024 */
  __IO uint32_t PSC;             /*!< PSC                   Address offset: 0x028 */
  __IO uint32_t ARR;             /*!< ARR                   Address offset: 0x02C */
  __IO uint32_t RCR;             /*!< RCR                   Address offset: 0x030 */
  __IO uint32_t CCR1;            /*!< CCR1                  Address offset: 0x034 */
  __IO uint32_t CCR2;            /*!< CCR2                  Address offset: 0x038 */
  __IO uint32_t CCR3;            /*!< CCR3                  Address offset: 0x03C */
  __IO uint32_t CCR4;            /*!< CCR4                  Address offset: 0x040 */
  __IO uint32_t BDTR;            /*!< BDTR                  Address offset: 0x044 */
  __IO uint32_t CCR5;            /*!< CCR5                  Address offset: 0x048 */
  __IO uint32_t CCR6;            /*!< CCR6                  Address offset: 0x04C */
  __IO uint32_t CCMR3;           /*!< CCMR3                 Address offset: 0x050 */
  __IO uint32_t DTR2;            /*!< DTR2                  Address offset: 0x054 */
  __IO uint32_t ECR;             /*!< ECR                   Address offset: 0x058 */
  __IO uint32_t TISEL;           /*!< TISEL                 Address offset: 0x05C */
  __IO uint32_t AF1;             /*!< AF1                   Address offset: 0x060 */
  __IO uint32_t AF2;             /*!< AF2                   Address offset: 0x064 */
       uint32_t RESERVED0[221];  /*!< Reserved              Address offset: 0x068-0x3D8 */
  __IO uint32_t DCR;             /*!< DCR                   Address offset: 0x3DC */
  __IO uint32_t DMAR;            /*!< DMAR                  Address offset: 0x3E0 */
} TIM_TypeDef;


/*******************  Bit definition for TIM_CR1 register  ********************/
#define TIM_CR1_CEN_Pos                      (0U)
#define TIM_CR1_CEN_Msk          (0x1UL << TIM_CR1_CEN_Pos) /*!< 0x00000001 */
#define TIM_CR1_CEN                          TIM_CR1_CEN_Msk                     /*!< </spirit:description> */
#define TIM_CR1_UDIS_Pos                     (1U)
#define TIM_CR1_UDIS_Msk         (0x1UL << TIM_CR1_UDIS_Pos)  /*!< 0x00000002 */
#define TIM_CR1_UDIS                         TIM_CR1_UDIS_Msk                    /*!< </spirit:description> */
#define TIM_CR1_URS_Pos                      (2U)
#define TIM_CR1_URS_Msk          (0x1UL << TIM_CR1_URS_Pos) /*!< 0x00000004 */
#define TIM_CR1_URS                          TIM_CR1_URS_Msk                     /*!< </spirit:description> */
#define TIM_CR1_OPM_Pos                      (3U)
#define TIM_CR1_OPM_Msk          (0x1UL << TIM_CR1_OPM_Pos) /*!< 0x00000008 */
#define TIM_CR1_OPM                          TIM_CR1_OPM_Msk                     /*!< </spirit:description> */
#define TIM_CR1_DIR_Pos                      (4U)
#define TIM_CR1_DIR_Msk          (0x1UL << TIM_CR1_DIR_Pos) /*!< 0x00000010 */
#define TIM_CR1_DIR                          TIM_CR1_DIR_Msk                     /*!< </spirit:description> */
#define TIM_CR1_CMS_Pos                      (5U)
#define TIM_CR1_CMS_Msk          (0x3UL << TIM_CR1_CMS_Pos) /*!< 0x00000060 */
#define TIM_CR1_CMS                          TIM_CR1_CMS_Msk                     /*!< </spirit:description> */
#define TIM_CR1_CMS_0           (0x1UL << TIM_CR1_CMS_Pos)   /*!< 0x00000020 */
#define TIM_CR1_CMS_1           (0x2UL << TIM_CR1_CMS_Pos)   /*!< 0x00000040 */
#define TIM_CR1_ARPE_Pos                     (7U)
#define TIM_CR1_ARPE_Msk         (0x1UL << TIM_CR1_ARPE_Pos)  /*!< 0x00000080 */
#define TIM_CR1_ARPE                         TIM_CR1_ARPE_Msk                    /*!< </spirit:description> */
#define TIM_CR1_CKD_Pos                      (8U)
#define TIM_CR1_CKD_Msk          (0x3UL << TIM_CR1_CKD_Pos) /*!< 0x00000300 */
#define TIM_CR1_CKD                          TIM_CR1_CKD_Msk                     /*!< </spirit:description> */
#define TIM_CR1_CKD_0           (0x1UL << TIM_CR1_CKD_Pos)   /*!< 0x00000100 */
#define TIM_CR1_CKD_1           (0x2UL << TIM_CR1_CKD_Pos)   /*!< 0x00000200 */
#define TIM_CR1_UIFREMAP_Pos                 (11U)
#define TIM_CR1_UIFREMAP_Msk     (0x1UL << TIM_CR1_UIFREMAP_Pos)      /*!< 0x00000800 */
#define TIM_CR1_UIFREMAP                     TIM_CR1_UIFREMAP_Msk                /*!< </spirit:description> */
#define TIM_CR1_DITHEN_Pos                   (12U)
#define TIM_CR1_DITHEN_Msk       (0x1UL << TIM_CR1_DITHEN_Pos)    /*!< 0x00001000 */
#define TIM_CR1_DITHEN                       TIM_CR1_DITHEN_Msk                  /*!< </spirit:description> */

/*******************  Bit definition for TIM_CR2 register  ********************/
#define TIM_CR2_CCPC_Pos                     (0U)
#define TIM_CR2_CCPC_Msk         (0x1UL << TIM_CR2_CCPC_Pos)  /*!< 0x00000001 */
#define TIM_CR2_CCPC                         TIM_CR2_CCPC_Msk                    /*!< </spirit:description> */
#define TIM_CR2_CCUS_Pos                     (2U)
#define TIM_CR2_CCUS_Msk         (0x1UL << TIM_CR2_CCUS_Pos)  /*!< 0x00000004 */
#define TIM_CR2_CCUS                         TIM_CR2_CCUS_Msk                    /*!< </spirit:description> */
#define TIM_CR2_CCDS_Pos                     (3U)
#define TIM_CR2_CCDS_Msk         (0x1UL << TIM_CR2_CCDS_Pos)  /*!< 0x00000008 */
#define TIM_CR2_CCDS                         TIM_CR2_CCDS_Msk                    /*!< </spirit:description> */
#define TIM_CR2_MMS_Pos                      (4U)
#define TIM_CR2_MMS_Msk          (0x200007UL << TIM_CR2_MMS_Pos) /*!< 0x02000070 */
#define TIM_CR2_MMS                          TIM_CR2_MMS_Msk                     /*!< </spirit:description> */
#define TIM_CR2_MMS_0           (0x1UL << TIM_CR2_MMS_Pos)   /*!< 0x00000010 */
#define TIM_CR2_MMS_1           (0x2UL << TIM_CR2_MMS_Pos)   /*!< 0x00000020 */
#define TIM_CR2_MMS_2           (0x4UL << TIM_CR2_MMS_Pos)   /*!< 0x00000040 */
#define TIM_CR2_MMS_3           (0x200000UL << TIM_CR2_MMS_Pos)   /*!< 0x02000000 */
#define TIM_CR2_TI1S_Pos                     (7U)
#define TIM_CR2_TI1S_Msk         (0x1UL << TIM_CR2_TI1S_Pos)  /*!< 0x00000080 */
#define TIM_CR2_TI1S                         TIM_CR2_TI1S_Msk                    /*!< </spirit:description> */
#define TIM_CR2_OIS1_Pos                     (8U)
#define TIM_CR2_OIS1_Msk         (0x1UL << TIM_CR2_OIS1_Pos)  /*!< 0x00000100 */
#define TIM_CR2_OIS1                         TIM_CR2_OIS1_Msk                    /*!< </spirit:description> */
#define TIM_CR2_OIS1N_Pos                    (9U)
#define TIM_CR2_OIS1N_Msk        (0x1UL << TIM_CR2_OIS1N_Pos)   /*!< 0x00000200 */
#define TIM_CR2_OIS1N                        TIM_CR2_OIS1N_Msk                   /*!< </spirit:description> */
#define TIM_CR2_OIS2_Pos                     (10U)
#define TIM_CR2_OIS2_Msk         (0x1UL << TIM_CR2_OIS2_Pos)  /*!< 0x00000400 */
#define TIM_CR2_OIS2                         TIM_CR2_OIS2_Msk                    /*!< </spirit:description> */
#define TIM_CR2_OIS2N_Pos                    (11U)
#define TIM_CR2_OIS2N_Msk        (0x1UL << TIM_CR2_OIS2N_Pos)   /*!< 0x00000800 */
#define TIM_CR2_OIS2N                        TIM_CR2_OIS2N_Msk                   /*!< </spirit:description> */
#define TIM_CR2_OIS3_Pos                     (12U)
#define TIM_CR2_OIS3_Msk         (0x1UL << TIM_CR2_OIS3_Pos)  /*!< 0x00001000 */
#define TIM_CR2_OIS3                         TIM_CR2_OIS3_Msk                    /*!< </spirit:description> */
#define TIM_CR2_OIS3N_Pos                    (13U)
#define TIM_CR2_OIS3N_Msk        (0x1UL << TIM_CR2_OIS3N_Pos)   /*!< 0x00002000 */
#define TIM_CR2_OIS3N                        TIM_CR2_OIS3N_Msk                   /*!< </spirit:description> */
#define TIM_CR2_OIS4_Pos                     (14U)
#define TIM_CR2_OIS4_Msk         (0x1UL << TIM_CR2_OIS4_Pos)  /*!< 0x00004000 */
#define TIM_CR2_OIS4                         TIM_CR2_OIS4_Msk                    /*!< </spirit:description> */
#define TIM_CR2_OIS4N_Pos                    (15U)
#define TIM_CR2_OIS4N_Msk        (0x1UL << TIM_CR2_OIS4N_Pos)   /*!< 0x00008000 */
#define TIM_CR2_OIS4N                        TIM_CR2_OIS4N_Msk                   /*!< </spirit:description> */
#define TIM_CR2_OIS5_Pos                     (16U)
#define TIM_CR2_OIS5_Msk         (0x1UL << TIM_CR2_OIS5_Pos)  /*!< 0x00010000 */
#define TIM_CR2_OIS5                         TIM_CR2_OIS5_Msk                    /*!< </spirit:description> */
#define TIM_CR2_OIS6_Pos                     (18U)
#define TIM_CR2_OIS6_Msk         (0x1UL << TIM_CR2_OIS6_Pos)  /*!< 0x00040000 */
#define TIM_CR2_OIS6                         TIM_CR2_OIS6_Msk                    /*!< </spirit:description> */
#define TIM_CR2_MMS2_Pos                     (20U)
#define TIM_CR2_MMS2_Msk         (0xFUL << TIM_CR2_MMS2_Pos)  /*!< 0x00F00000 */
#define TIM_CR2_MMS2                         TIM_CR2_MMS2_Msk                    /*!< </spirit:description> */
#define TIM_CR2_MMS2_0          (0x1UL << TIM_CR2_MMS2_Pos)    /*!< 0x00100000 */
#define TIM_CR2_MMS2_1          (0x2UL << TIM_CR2_MMS2_Pos)    /*!< 0x00200000 */
#define TIM_CR2_MMS2_2          (0x4UL << TIM_CR2_MMS2_Pos)    /*!< 0x00400000 */
#define TIM_CR2_MMS2_3          (0x8UL << TIM_CR2_MMS2_Pos)    /*!< 0x00800000 */

/*******************  Bit definition for TIM_SMCR register  *******************/
#define TIM_SMCR_SMS_Pos                     (0U)
#define TIM_SMCR_SMS_Msk         (0xFUL << TIM_SMCR_SMS_Pos)  /*!< 0x0000000F */
#define TIM_SMCR_SMS                         TIM_SMCR_SMS_Msk                    /*!< </spirit:description> */
#define TIM_SMCR_SMS_0          (0x1UL << TIM_SMCR_SMS_Pos)    /*!< 0x00000001 */
#define TIM_SMCR_SMS_1          (0x2UL << TIM_SMCR_SMS_Pos)    /*!< 0x00000002 */
#define TIM_SMCR_SMS_2          (0x4UL << TIM_SMCR_SMS_Pos)    /*!< 0x00000004 */
#define TIM_SMCR_SMS_3          (0x10000UL << TIM_SMCR_SMS_Pos)    /*!< 0x00010000 */
#define TIM_SMCR_OCCS_Pos                    (3U)
#define TIM_SMCR_OCCS_Msk        (0x1UL << TIM_SMCR_OCCS_Pos)   /*!< 0x00000008 */
#define TIM_SMCR_OCCS                        TIM_SMCR_OCCS_Msk                   /*!< </spirit:description> */
#define TIM_SMCR_TS_Pos                      (4U)
#define TIM_SMCR_TS_Msk          (0x1FUL << TIM_SMCR_TS_Pos)  /*!< 0x000001F0 */
#define TIM_SMCR_TS                          TIM_SMCR_TS_Msk                     /*!< </spirit:description> */
#define TIM_SMCR_TS_0           (0x1UL << TIM_SMCR_TS_Pos)    /*!< 0x00000010 */
#define TIM_SMCR_TS_1           (0x2UL << TIM_SMCR_TS_Pos)    /*!< 0x00000020 */
#define TIM_SMCR_TS_2           (0x4UL << TIM_SMCR_TS_Pos)    /*!< 0x00000040 */
#define TIM_SMCR_TS_3           (0x10000UL << TIM_SMCR_TS_Pos)    /*!< 0x00100000 */
#define TIM_SMCR_TS_4           (0x20000UL << TIM_SMCR_TS_Pos)    /*!< 0x00200000 */
#define TIM_SMCR_MSM_Pos                     (7U)
#define TIM_SMCR_MSM_Msk         (0x1UL << TIM_SMCR_MSM_Pos)  /*!< 0x00000080 */
#define TIM_SMCR_MSM                         TIM_SMCR_MSM_Msk                    /*!< </spirit:description> */
#define TIM_SMCR_ETF_Pos                     (8U)
#define TIM_SMCR_ETF_Msk         (0xFUL << TIM_SMCR_ETF_Pos)  /*!< 0x00000F00 */
#define TIM_SMCR_ETF                         TIM_SMCR_ETF_Msk                    /*!< </spirit:description> */
#define TIM_SMCR_ETF_0          (0x1UL << TIM_SMCR_ETF_Pos)    /*!< 0x00000100 */
#define TIM_SMCR_ETF_1          (0x2UL << TIM_SMCR_ETF_Pos)    /*!< 0x00000200 */
#define TIM_SMCR_ETF_2          (0x4UL << TIM_SMCR_ETF_Pos)    /*!< 0x00000400 */
#define TIM_SMCR_ETF_3          (0x8UL << TIM_SMCR_ETF_Pos)    /*!< 0x00000800 */
#define TIM_SMCR_ETPS_Pos                    (12U)
#define TIM_SMCR_ETPS_Msk        (0x3UL << TIM_SMCR_ETPS_Pos)   /*!< 0x00003000 */
#define TIM_SMCR_ETPS                        TIM_SMCR_ETPS_Msk                   /*!< </spirit:description> */
#define TIM_SMCR_ETPS_0         (0x1UL << TIM_SMCR_ETPS_Pos)     /*!< 0x00001000 */
#define TIM_SMCR_ETPS_1         (0x2UL << TIM_SMCR_ETPS_Pos)     /*!< 0x00002000 */
#define TIM_SMCR_ECE_Pos                     (14U)
#define TIM_SMCR_ECE_Msk         (0x1UL << TIM_SMCR_ECE_Pos)  /*!< 0x00004000 */
#define TIM_SMCR_ECE                         TIM_SMCR_ECE_Msk                    /*!< </spirit:description> */
#define TIM_SMCR_ETP_Pos                     (15U)
#define TIM_SMCR_ETP_Msk         (0x1UL << TIM_SMCR_ETP_Pos)  /*!< 0x00008000 */
#define TIM_SMCR_ETP                         TIM_SMCR_ETP_Msk                    /*!< </spirit:description> */
#define TIM_SMCR_SMSPE_Pos                   (24U)
#define TIM_SMCR_SMSPE_Msk       (0x1UL << TIM_SMCR_SMSPE_Pos)    /*!< 0x01000000 */
#define TIM_SMCR_SMSPE                       TIM_SMCR_SMSPE_Msk                  /*!< </spirit:description> */
#define TIM_SMCR_SMSPS_Pos                   (25U)
#define TIM_SMCR_SMSPS_Msk       (0x1UL << TIM_SMCR_SMSPS_Pos)    /*!< 0x02000000 */
#define TIM_SMCR_SMSPS                       TIM_SMCR_SMSPS_Msk                  /*!< </spirit:description> */

/*******************  Bit definition for TIM_DIER register  *******************/
#define TIM_DIER_UIE_Pos                     (0U)
#define TIM_DIER_UIE_Msk         (0x1UL << TIM_DIER_UIE_Pos)  /*!< 0x00000001 */
#define TIM_DIER_UIE                         TIM_DIER_UIE_Msk                    /*!< </spirit:description> */
#define TIM_DIER_CC1IE_Pos                   (1U)
#define TIM_DIER_CC1IE_Msk       (0x1UL << TIM_DIER_CC1IE_Pos)    /*!< 0x00000002 */
#define TIM_DIER_CC1IE                       TIM_DIER_CC1IE_Msk                  /*!< </spirit:description> */
#define TIM_DIER_CC2IE_Pos                   (2U)
#define TIM_DIER_CC2IE_Msk       (0x1UL << TIM_DIER_CC2IE_Pos)    /*!< 0x00000004 */
#define TIM_DIER_CC2IE                       TIM_DIER_CC2IE_Msk                  /*!< </spirit:description> */
#define TIM_DIER_CC3IE_Pos                   (3U)
#define TIM_DIER_CC3IE_Msk       (0x1UL << TIM_DIER_CC3IE_Pos)    /*!< 0x00000008 */
#define TIM_DIER_CC3IE                       TIM_DIER_CC3IE_Msk                  /*!< </spirit:description> */
#define TIM_DIER_CC4IE_Pos                   (4U)
#define TIM_DIER_CC4IE_Msk       (0x1UL << TIM_DIER_CC4IE_Pos)    /*!< 0x00000010 */
#define TIM_DIER_CC4IE                       TIM_DIER_CC4IE_Msk                  /*!< </spirit:description> */
#define TIM_DIER_COMIE_Pos                   (5U)
#define TIM_DIER_COMIE_Msk       (0x1UL << TIM_DIER_COMIE_Pos)    /*!< 0x00000020 */
#define TIM_DIER_COMIE                       TIM_DIER_COMIE_Msk                  /*!< </spirit:description> */
#define TIM_DIER_TIE_Pos                     (6U)
#define TIM_DIER_TIE_Msk         (0x1UL << TIM_DIER_TIE_Pos)  /*!< 0x00000040 */
#define TIM_DIER_TIE                         TIM_DIER_TIE_Msk                    /*!< </spirit:description> */
#define TIM_DIER_BIE_Pos                     (7U)
#define TIM_DIER_BIE_Msk         (0x1UL << TIM_DIER_BIE_Pos)  /*!< 0x00000080 */
#define TIM_DIER_BIE                         TIM_DIER_BIE_Msk                    /*!< </spirit:description> */
#define TIM_DIER_UDE_Pos                     (8U)
#define TIM_DIER_UDE_Msk         (0x1UL << TIM_DIER_UDE_Pos)  /*!< 0x00000100 */
#define TIM_DIER_UDE                         TIM_DIER_UDE_Msk                    /*!< </spirit:description> */
#define TIM_DIER_CC1DE_Pos                   (9U)
#define TIM_DIER_CC1DE_Msk       (0x1UL << TIM_DIER_CC1DE_Pos)    /*!< 0x00000200 */
#define TIM_DIER_CC1DE                       TIM_DIER_CC1DE_Msk                  /*!< </spirit:description> */
#define TIM_DIER_CC2DE_Pos                   (10U)
#define TIM_DIER_CC2DE_Msk       (0x1UL << TIM_DIER_CC2DE_Pos)    /*!< 0x00000400 */
#define TIM_DIER_CC2DE                       TIM_DIER_CC2DE_Msk                  /*!< </spirit:description> */
#define TIM_DIER_CC3DE_Pos                   (11U)
#define TIM_DIER_CC3DE_Msk       (0x1UL << TIM_DIER_CC3DE_Pos)    /*!< 0x00000800 */
#define TIM_DIER_CC3DE                       TIM_DIER_CC3DE_Msk                  /*!< </spirit:description> */
#define TIM_DIER_CC4DE_Pos                   (12U)
#define TIM_DIER_CC4DE_Msk       (0x1UL << TIM_DIER_CC4DE_Pos)    /*!< 0x00001000 */
#define TIM_DIER_CC4DE                       TIM_DIER_CC4DE_Msk                  /*!< </spirit:description> */
#define TIM_DIER_COMDE_Pos                   (13U)
#define TIM_DIER_COMDE_Msk       (0x1UL << TIM_DIER_COMDE_Pos)    /*!< 0x00002000 */
#define TIM_DIER_COMDE                       TIM_DIER_COMDE_Msk                  /*!< </spirit:description> */
#define TIM_DIER_TDE_Pos                     (14U)
#define TIM_DIER_TDE_Msk         (0x1UL << TIM_DIER_TDE_Pos)  /*!< 0x00004000 */
#define TIM_DIER_TDE                         TIM_DIER_TDE_Msk                    /*!< </spirit:description> */
#define TIM_DIER_IDXIE_Pos                   (20U)
#define TIM_DIER_IDXIE_Msk       (0x1UL << TIM_DIER_IDXIE_Pos)    /*!< 0x00100000 */
#define TIM_DIER_IDXIE                       TIM_DIER_IDXIE_Msk                  /*!< </spirit:description> */
#define TIM_DIER_DIRIE_Pos                   (21U)
#define TIM_DIER_DIRIE_Msk       (0x1UL << TIM_DIER_DIRIE_Pos)    /*!< 0x00200000 */
#define TIM_DIER_DIRIE                       TIM_DIER_DIRIE_Msk                  /*!< </spirit:description> */
#define TIM_DIER_IERRIE_Pos                  (22U)
#define TIM_DIER_IERRIE_Msk      (0x1UL << TIM_DIER_IERRIE_Pos)     /*!< 0x00400000 */
#define TIM_DIER_IERRIE                      TIM_DIER_IERRIE_Msk                 /*!< </spirit:description> */
#define TIM_DIER_TERRIE_Pos                  (23U)
#define TIM_DIER_TERRIE_Msk      (0x1UL << TIM_DIER_TERRIE_Pos)     /*!< 0x00800000 */
#define TIM_DIER_TERRIE                      TIM_DIER_TERRIE_Msk                 /*!< </spirit:description> */

/********************  Bit definition for TIM_SR register  ********************/
#define TIM_SR_UIF_Pos                       (0U)
#define TIM_SR_UIF_Msk             (0x1UL << TIM_SR_UIF_Pos)  /*!< 0x00000001 */
#define TIM_SR_UIF                           TIM_SR_UIF_Msk                      /*!< </spirit:description> */
#define TIM_SR_CC1IF_Pos                     (1U)
#define TIM_SR_CC1IF_Msk         (0x1UL << TIM_SR_CC1IF_Pos)  /*!< 0x00000002 */
#define TIM_SR_CC1IF                         TIM_SR_CC1IF_Msk                    /*!< </spirit:description> */
#define TIM_SR_CC2IF_Pos                     (2U)
#define TIM_SR_CC2IF_Msk         (0x1UL << TIM_SR_CC2IF_Pos)  /*!< 0x00000004 */
#define TIM_SR_CC2IF                         TIM_SR_CC2IF_Msk                    /*!< </spirit:description> */
#define TIM_SR_CC3IF_Pos                     (3U)
#define TIM_SR_CC3IF_Msk         (0x1UL << TIM_SR_CC3IF_Pos)  /*!< 0x00000008 */
#define TIM_SR_CC3IF                         TIM_SR_CC3IF_Msk                    /*!< </spirit:description> */
#define TIM_SR_CC4IF_Pos                     (4U)
#define TIM_SR_CC4IF_Msk         (0x1UL << TIM_SR_CC4IF_Pos)  /*!< 0x00000010 */
#define TIM_SR_CC4IF                         TIM_SR_CC4IF_Msk                    /*!< </spirit:description> */
#define TIM_SR_COMIF_Pos                     (5U)
#define TIM_SR_COMIF_Msk         (0x1UL << TIM_SR_COMIF_Pos)  /*!< 0x00000020 */
#define TIM_SR_COMIF                         TIM_SR_COMIF_Msk                    /*!< </spirit:description> */
#define TIM_SR_TIF_Pos                       (6U)
#define TIM_SR_TIF_Msk             (0x1UL << TIM_SR_TIF_Pos)  /*!< 0x00000040 */
#define TIM_SR_TIF                           TIM_SR_TIF_Msk                      /*!< </spirit:description> */
#define TIM_SR_BIF_Pos                       (7U)
#define TIM_SR_BIF_Msk             (0x1UL << TIM_SR_BIF_Pos)  /*!< 0x00000080 */
#define TIM_SR_BIF                           TIM_SR_BIF_Msk                      /*!< </spirit:description> */
#define TIM_SR_B2IF_Pos                      (8U)
#define TIM_SR_B2IF_Msk          (0x1UL << TIM_SR_B2IF_Pos) /*!< 0x00000100 */
#define TIM_SR_B2IF                          TIM_SR_B2IF_Msk                     /*!< </spirit:description> */
#define TIM_SR_CC1OF_Pos                     (9U)
#define TIM_SR_CC1OF_Msk         (0x1UL << TIM_SR_CC1OF_Pos)  /*!< 0x00000200 */
#define TIM_SR_CC1OF                         TIM_SR_CC1OF_Msk                    /*!< </spirit:description> */
#define TIM_SR_CC2OF_Pos                     (10U)
#define TIM_SR_CC2OF_Msk         (0x1UL << TIM_SR_CC2OF_Pos)  /*!< 0x00000400 */
#define TIM_SR_CC2OF                         TIM_SR_CC2OF_Msk                    /*!< </spirit:description> */
#define TIM_SR_CC3OF_Pos                     (11U)
#define TIM_SR_CC3OF_Msk         (0x1UL << TIM_SR_CC3OF_Pos)  /*!< 0x00000800 */
#define TIM_SR_CC3OF                         TIM_SR_CC3OF_Msk                    /*!< </spirit:description> */
#define TIM_SR_CC4OF_Pos                     (12U)
#define TIM_SR_CC4OF_Msk         (0x1UL << TIM_SR_CC4OF_Pos)  /*!< 0x00001000 */
#define TIM_SR_CC4OF                         TIM_SR_CC4OF_Msk                    /*!< </spirit:description> */
#define TIM_SR_SBIF_Pos                      (13U)
#define TIM_SR_SBIF_Msk          (0x1UL << TIM_SR_SBIF_Pos) /*!< 0x00002000 */
#define TIM_SR_SBIF                          TIM_SR_SBIF_Msk                     /*!< </spirit:description> */
#define TIM_SR_CC5IF_Pos                     (16U)
#define TIM_SR_CC5IF_Msk         (0x1UL << TIM_SR_CC5IF_Pos)  /*!< 0x00010000 */
#define TIM_SR_CC5IF                         TIM_SR_CC5IF_Msk                    /*!< </spirit:description> */
#define TIM_SR_CC6IF_Pos                     (17U)
#define TIM_SR_CC6IF_Msk         (0x1UL << TIM_SR_CC6IF_Pos)  /*!< 0x00020000 */
#define TIM_SR_CC6IF                         TIM_SR_CC6IF_Msk                    /*!< </spirit:description> */
#define TIM_SR_IDXF_Pos                      (20U)
#define TIM_SR_IDXF_Msk          (0x1UL << TIM_SR_IDXF_Pos) /*!< 0x00100000 */
#define TIM_SR_IDXF                          TIM_SR_IDXF_Msk                     /*!< </spirit:description> */
#define TIM_SR_DIRF_Pos                      (21U)
#define TIM_SR_DIRF_Msk          (0x1UL << TIM_SR_DIRF_Pos) /*!< 0x00200000 */
#define TIM_SR_DIRF                          TIM_SR_DIRF_Msk                     /*!< </spirit:description> */
#define TIM_SR_IERRF_Pos                     (22U)
#define TIM_SR_IERRF_Msk         (0x1UL << TIM_SR_IERRF_Pos)  /*!< 0x00400000 */
#define TIM_SR_IERRF                         TIM_SR_IERRF_Msk                    /*!< </spirit:description> */
#define TIM_SR_TERRF_Pos                     (23U)
#define TIM_SR_TERRF_Msk         (0x1UL << TIM_SR_TERRF_Pos)  /*!< 0x00800000 */
#define TIM_SR_TERRF                         TIM_SR_TERRF_Msk                    /*!< </spirit:description> */

/*******************  Bit definition for TIM_EGR register  ********************/
#define TIM_EGR_UG_Pos                       (0U)
#define TIM_EGR_UG_Msk             (0x1UL << TIM_EGR_UG_Pos)  /*!< 0x00000001 */
#define TIM_EGR_UG                           TIM_EGR_UG_Msk                      /*!< </spirit:description> */
#define TIM_EGR_CC1G_Pos                     (1U)
#define TIM_EGR_CC1G_Msk         (0x1UL << TIM_EGR_CC1G_Pos)  /*!< 0x00000002 */
#define TIM_EGR_CC1G                         TIM_EGR_CC1G_Msk                    /*!< </spirit:description> */
#define TIM_EGR_CC2G_Pos                     (2U)
#define TIM_EGR_CC2G_Msk         (0x1UL << TIM_EGR_CC2G_Pos)  /*!< 0x00000004 */
#define TIM_EGR_CC2G                         TIM_EGR_CC2G_Msk                    /*!< </spirit:description> */
#define TIM_EGR_CC3G_Pos                     (3U)
#define TIM_EGR_CC3G_Msk         (0x1UL << TIM_EGR_CC3G_Pos)  /*!< 0x00000008 */
#define TIM_EGR_CC3G                         TIM_EGR_CC3G_Msk                    /*!< </spirit:description> */
#define TIM_EGR_CC4G_Pos                     (4U)
#define TIM_EGR_CC4G_Msk         (0x1UL << TIM_EGR_CC4G_Pos)  /*!< 0x00000010 */
#define TIM_EGR_CC4G                         TIM_EGR_CC4G_Msk                    /*!< </spirit:description> */
#define TIM_EGR_COMG_Pos                     (5U)
#define TIM_EGR_COMG_Msk         (0x1UL << TIM_EGR_COMG_Pos)  /*!< 0x00000020 */
#define TIM_EGR_COMG                         TIM_EGR_COMG_Msk                    /*!< </spirit:description> */
#define TIM_EGR_TG_Pos                       (6U)
#define TIM_EGR_TG_Msk             (0x1UL << TIM_EGR_TG_Pos)  /*!< 0x00000040 */
#define TIM_EGR_TG                           TIM_EGR_TG_Msk                      /*!< </spirit:description> */
#define TIM_EGR_BG_Pos                       (7U)
#define TIM_EGR_BG_Msk             (0x1UL << TIM_EGR_BG_Pos)  /*!< 0x00000080 */
#define TIM_EGR_BG                           TIM_EGR_BG_Msk                      /*!< </spirit:description> */
#define TIM_EGR_B2G_Pos                      (8U)
#define TIM_EGR_B2G_Msk          (0x1UL << TIM_EGR_B2G_Pos) /*!< 0x00000100 */
#define TIM_EGR_B2G                          TIM_EGR_B2G_Msk                     /*!< </spirit:description> */

/******************  Bit definition for TIM_CCMR1 register  *******************/
#define TIM_CCMR1_CC1S_Pos                   (0U)
#define TIM_CCMR1_CC1S_Msk       (0x3UL << TIM_CCMR1_CC1S_Pos)    /*!< 0x00000003 */
#define TIM_CCMR1_CC1S                       TIM_CCMR1_CC1S_Msk                  /*!< </spirit:description> */
#define TIM_CCMR1_CC1S_0        (0x1UL << TIM_CCMR1_CC1S_Pos)      /*!< 0x00000001 */
#define TIM_CCMR1_CC1S_1        (0x2UL << TIM_CCMR1_CC1S_Pos)      /*!< 0x00000002 */
#define TIM_CCMR1_OC1FE_Pos                  (2U)
#define TIM_CCMR1_OC1FE_Msk      (0x1UL << TIM_CCMR1_OC1FE_Pos)     /*!< 0x00000004 */
#define TIM_CCMR1_OC1FE                      TIM_CCMR1_OC1FE_Msk                 /*!< </spirit:description> */
#define TIM_CCMR1_OC1PE_Pos                  (3U)
#define TIM_CCMR1_OC1PE_Msk      (0x1UL << TIM_CCMR1_OC1PE_Pos)     /*!< 0x00000008 */
#define TIM_CCMR1_OC1PE                      TIM_CCMR1_OC1PE_Msk                 /*!< </spirit:description> */
#define TIM_CCMR1_OC1M_Pos                   (4U)
#define TIM_CCMR1_OC1M_Msk       (0x1007UL << TIM_CCMR1_OC1M_Pos)    /*!< 0x00010070 */
#define TIM_CCMR1_OC1M                       TIM_CCMR1_OC1M_Msk                  /*!< </spirit:description> */
#define TIM_CCMR1_OC1M_0        (0x1UL << TIM_CCMR1_OC1M_Pos)      /*!< 0x00000010 */
#define TIM_CCMR1_OC1M_1        (0x2UL << TIM_CCMR1_OC1M_Pos)      /*!< 0x00000020 */
#define TIM_CCMR1_OC1M_2        (0x4UL << TIM_CCMR1_OC1M_Pos)      /*!< 0x00000040 */
#define TIM_CCMR1_OC1M_3        (0x1000UL << TIM_CCMR1_OC1M_Pos)      /*!< 0x00010000 */
#define TIM_CCMR1_OC1CE_Pos                  (7U)
#define TIM_CCMR1_OC1CE_Msk      (0x1UL << TIM_CCMR1_OC1CE_Pos)     /*!< 0x00000080 */
#define TIM_CCMR1_OC1CE                      TIM_CCMR1_OC1CE_Msk                 /*!< </spirit:description> */
#define TIM_CCMR1_CC2S_Pos                   (8U)
#define TIM_CCMR1_CC2S_Msk       (0x3UL << TIM_CCMR1_CC2S_Pos)    /*!< 0x00000300 */
#define TIM_CCMR1_CC2S                       TIM_CCMR1_CC2S_Msk                  /*!< </spirit:description> */
#define TIM_CCMR1_CC2S_0        (0x1UL << TIM_CCMR1_CC2S_Pos)      /*!< 0x00000100 */
#define TIM_CCMR1_CC2S_1        (0x2UL << TIM_CCMR1_CC2S_Pos)      /*!< 0x00000200 */
#define TIM_CCMR1_OC2FE_Pos                  (10U)
#define TIM_CCMR1_OC2FE_Msk      (0x1UL << TIM_CCMR1_OC2FE_Pos)     /*!< 0x00000400 */
#define TIM_CCMR1_OC2FE                      TIM_CCMR1_OC2FE_Msk                 /*!< </spirit:description> */
#define TIM_CCMR1_OC2PE_Pos                  (11U)
#define TIM_CCMR1_OC2PE_Msk      (0x1UL << TIM_CCMR1_OC2PE_Pos)     /*!< 0x00000800 */
#define TIM_CCMR1_OC2PE                      TIM_CCMR1_OC2PE_Msk                 /*!< </spirit:description> */
#define TIM_CCMR1_OC2M_Pos                   (12U)
#define TIM_CCMR1_OC2M_Msk       (0x1007UL << TIM_CCMR1_OC2M_Pos)    /*!< 0x01007000 */
#define TIM_CCMR1_OC2M                       TIM_CCMR1_OC2M_Msk                  /*!< </spirit:description> */
#define TIM_CCMR1_OC2M_0        (0x1UL << TIM_CCMR1_OC2M_Pos)      /*!< 0x00001000 */
#define TIM_CCMR1_OC2M_1        (0x2UL << TIM_CCMR1_OC2M_Pos)      /*!< 0x00002000 */
#define TIM_CCMR1_OC2M_2        (0x4UL << TIM_CCMR1_OC2M_Pos)      /*!< 0x00004000 */
#define TIM_CCMR1_OC2M_3        (0x1000UL << TIM_CCMR1_OC2M_Pos)      /*!< 0x01000000 */
#define TIM_CCMR1_OC2CE_Pos                  (15U)
#define TIM_CCMR1_OC2CE_Msk      (0x1UL << TIM_CCMR1_OC2CE_Pos)     /*!< 0x00008000 */
#define TIM_CCMR1_OC2CE                      TIM_CCMR1_OC2CE_Msk                 /*!< </spirit:description> */
#define TIM_CCMR1_IC1PSC_Pos                 (2U)
#define TIM_CCMR1_IC1PSC_Msk     (0x3UL << TIM_CCMR1_IC1PSC_Pos)      /*!< 0x0000000C */
#define TIM_CCMR1_IC1PSC                     TIM_CCMR1_IC1PSC_Msk                /*!< </spirit:description> */
#define TIM_CCMR1_IC1PSC_0      (0x1UL << TIM_CCMR1_IC1PSC_Pos)        /*!< 0x00000004 */
#define TIM_CCMR1_IC1PSC_1      (0x2UL << TIM_CCMR1_IC1PSC_Pos)        /*!< 0x00000008 */
#define TIM_CCMR1_IC1F_Pos                   (4U)
#define TIM_CCMR1_IC1F_Msk       (0xFUL << TIM_CCMR1_IC1F_Pos)    /*!< 0x000000F0 */
#define TIM_CCMR1_IC1F                       TIM_CCMR1_IC1F_Msk                  /*!< </spirit:description> */
#define TIM_CCMR1_IC1F_0        (0x1UL << TIM_CCMR1_IC1F_Pos)      /*!< 0x00000010 */
#define TIM_CCMR1_IC1F_1        (0x2UL << TIM_CCMR1_IC1F_Pos)      /*!< 0x00000020 */
#define TIM_CCMR1_IC1F_2        (0x4UL << TIM_CCMR1_IC1F_Pos)      /*!< 0x00000040 */
#define TIM_CCMR1_IC1F_3        (0x8UL << TIM_CCMR1_IC1F_Pos)      /*!< 0x00000080 */
#define TIM_CCMR1_IC2PSC_Pos                 (10U)
#define TIM_CCMR1_IC2PSC_Msk     (0x3UL << TIM_CCMR1_IC2PSC_Pos)      /*!< 0x00000C00 */
#define TIM_CCMR1_IC2PSC                     TIM_CCMR1_IC2PSC_Msk                /*!< </spirit:description> */
#define TIM_CCMR1_IC2PSC_0      (0x1UL << TIM_CCMR1_IC2PSC_Pos)        /*!< 0x00000400 */
#define TIM_CCMR1_IC2PSC_1      (0x2UL << TIM_CCMR1_IC2PSC_Pos)        /*!< 0x00000800 */
#define TIM_CCMR1_IC2F_Pos                   (12U)
#define TIM_CCMR1_IC2F_Msk       (0xFUL << TIM_CCMR1_IC2F_Pos)    /*!< 0x0000F000 */
#define TIM_CCMR1_IC2F                       TIM_CCMR1_IC2F_Msk                  /*!< </spirit:description> */
#define TIM_CCMR1_IC2F_0        (0x1UL << TIM_CCMR1_IC2F_Pos)      /*!< 0x00001000 */
#define TIM_CCMR1_IC2F_1        (0x2UL << TIM_CCMR1_IC2F_Pos)      /*!< 0x00002000 */
#define TIM_CCMR1_IC2F_2        (0x4UL << TIM_CCMR1_IC2F_Pos)      /*!< 0x00004000 */
#define TIM_CCMR1_IC2F_3        (0x8UL << TIM_CCMR1_IC2F_Pos)      /*!< 0x00008000 */

/******************  Bit definition for TIM_CCMR2 register  *******************/
#define TIM_CCMR2_CC3S_Pos                   (0U)
#define TIM_CCMR2_CC3S_Msk       (0x3UL << TIM_CCMR2_CC3S_Pos)    /*!< 0x00000003 */
#define TIM_CCMR2_CC3S                       TIM_CCMR2_CC3S_Msk                  /*!< </spirit:description> */
#define TIM_CCMR2_CC3S_0        (0x1UL << TIM_CCMR2_CC3S_Pos)      /*!< 0x00000001 */
#define TIM_CCMR2_CC3S_1        (0x2UL << TIM_CCMR2_CC3S_Pos)      /*!< 0x00000002 */
#define TIM_CCMR2_OC3FE_Pos                  (2U)
#define TIM_CCMR2_OC3FE_Msk      (0x1UL << TIM_CCMR2_OC3FE_Pos)     /*!< 0x00000004 */
#define TIM_CCMR2_OC3FE                      TIM_CCMR2_OC3FE_Msk                 /*!< </spirit:description> */
#define TIM_CCMR2_OC3PE_Pos                  (3U)
#define TIM_CCMR2_OC3PE_Msk      (0x1UL << TIM_CCMR2_OC3PE_Pos)     /*!< 0x00000008 */
#define TIM_CCMR2_OC3PE                      TIM_CCMR2_OC3PE_Msk                 /*!< </spirit:description> */
#define TIM_CCMR2_OC3M_Pos                   (4U)
#define TIM_CCMR2_OC3M_Msk       (0x1007UL << TIM_CCMR2_OC3M_Pos)    /*!< 0x00010070 */
#define TIM_CCMR2_OC3M                       TIM_CCMR2_OC3M_Msk                  /*!< </spirit:description> */
#define TIM_CCMR2_OC3M_0        (0x1UL << TIM_CCMR2_OC3M_Pos)      /*!< 0x00000010 */
#define TIM_CCMR2_OC3M_1        (0x2UL << TIM_CCMR2_OC3M_Pos)      /*!< 0x00000020 */
#define TIM_CCMR2_OC3M_2        (0x4UL << TIM_CCMR2_OC3M_Pos)      /*!< 0x00000040 */
#define TIM_CCMR2_OC3M_3        (0x1000UL << TIM_CCMR2_OC3M_Pos)      /*!< 0x00010000 */
#define TIM_CCMR2_OC3CE_Pos                  (7U)
#define TIM_CCMR2_OC3CE_Msk      (0x1UL << TIM_CCMR2_OC3CE_Pos)     /*!< 0x00000080 */
#define TIM_CCMR2_OC3CE                      TIM_CCMR2_OC3CE_Msk                 /*!< </spirit:description> */
#define TIM_CCMR2_CC4S_Pos                   (8U)
#define TIM_CCMR2_CC4S_Msk       (0x3UL << TIM_CCMR2_CC4S_Pos)    /*!< 0x00000300 */
#define TIM_CCMR2_CC4S                       TIM_CCMR2_CC4S_Msk                  /*!< </spirit:description> */
#define TIM_CCMR2_CC4S_0        (0x1UL << TIM_CCMR2_CC4S_Pos)      /*!< 0x00000100 */
#define TIM_CCMR2_CC4S_1        (0x2UL << TIM_CCMR2_CC4S_Pos)      /*!< 0x00000200 */
#define TIM_CCMR2_OC4FE_Pos                  (10U)
#define TIM_CCMR2_OC4FE_Msk      (0x1UL << TIM_CCMR2_OC4FE_Pos)     /*!< 0x00000400 */
#define TIM_CCMR2_OC4FE                      TIM_CCMR2_OC4FE_Msk                 /*!< </spirit:description> */
#define TIM_CCMR2_OC4PE_Pos                  (11U)
#define TIM_CCMR2_OC4PE_Msk      (0x1UL << TIM_CCMR2_OC4PE_Pos)     /*!< 0x00000800 */
#define TIM_CCMR2_OC4PE                      TIM_CCMR2_OC4PE_Msk                 /*!< </spirit:description> */
#define TIM_CCMR2_OC4M_Pos                   (12U)
#define TIM_CCMR2_OC4M_Msk       (0x1007UL << TIM_CCMR2_OC4M_Pos)    /*!< 0x01007000 */
#define TIM_CCMR2_OC4M                       TIM_CCMR2_OC4M_Msk                  /*!< </spirit:description> */
#define TIM_CCMR2_OC4M_0        (0x1UL << TIM_CCMR2_OC4M_Pos)      /*!< 0x00001000 */
#define TIM_CCMR2_OC4M_1        (0x2UL << TIM_CCMR2_OC4M_Pos)      /*!< 0x00002000 */
#define TIM_CCMR2_OC4M_2        (0x4UL << TIM_CCMR2_OC4M_Pos)      /*!< 0x00004000 */
#define TIM_CCMR2_OC4M_3        (0x1000UL << TIM_CCMR2_OC4M_Pos)      /*!< 0x01000000 */
#define TIM_CCMR2_OC4CE_Pos                  (15U)
#define TIM_CCMR2_OC4CE_Msk      (0x1UL << TIM_CCMR2_OC4CE_Pos)     /*!< 0x00008000 */
#define TIM_CCMR2_OC4CE                      TIM_CCMR2_OC4CE_Msk                 /*!< </spirit:description> */
#define TIM_CCMR2_IC3PSC_Pos                 (2U)
#define TIM_CCMR2_IC3PSC_Msk     (0x3UL << TIM_CCMR2_IC3PSC_Pos)      /*!< 0x0000000C */
#define TIM_CCMR2_IC3PSC                     TIM_CCMR2_IC3PSC_Msk                /*!< </spirit:description> */
#define TIM_CCMR2_IC3PSC_0      (0x1UL << TIM_CCMR2_IC3PSC_Pos)        /*!< 0x00000004 */
#define TIM_CCMR2_IC3PSC_1      (0x2UL << TIM_CCMR2_IC3PSC_Pos)        /*!< 0x00000008 */
#define TIM_CCMR2_IC3F_Pos                   (4U)
#define TIM_CCMR2_IC3F_Msk       (0xFUL << TIM_CCMR2_IC3F_Pos)    /*!< 0x000000F0 */
#define TIM_CCMR2_IC3F                       TIM_CCMR2_IC3F_Msk                  /*!< </spirit:description> */
#define TIM_CCMR2_IC3F_0        (0x1UL << TIM_CCMR2_IC3F_Pos)      /*!< 0x00000010 */
#define TIM_CCMR2_IC3F_1        (0x2UL << TIM_CCMR2_IC3F_Pos)      /*!< 0x00000020 */
#define TIM_CCMR2_IC3F_2        (0x4UL << TIM_CCMR2_IC3F_Pos)      /*!< 0x00000040 */
#define TIM_CCMR2_IC3F_3        (0x8UL << TIM_CCMR2_IC3F_Pos)      /*!< 0x00000080 */
#define TIM_CCMR2_IC4PSC_Pos                 (10U)
#define TIM_CCMR2_IC4PSC_Msk     (0x3UL << TIM_CCMR2_IC4PSC_Pos)      /*!< 0x00000C00 */
#define TIM_CCMR2_IC4PSC                     TIM_CCMR2_IC4PSC_Msk                /*!< </spirit:description> */
#define TIM_CCMR2_IC4PSC_0      (0x1UL << TIM_CCMR2_IC4PSC_Pos)        /*!< 0x00000400 */
#define TIM_CCMR2_IC4PSC_1      (0x2UL << TIM_CCMR2_IC4PSC_Pos)        /*!< 0x00000800 */
#define TIM_CCMR2_IC4F_Pos                   (12U)
#define TIM_CCMR2_IC4F_Msk       (0xFUL << TIM_CCMR2_IC4F_Pos)    /*!< 0x0000F000 */
#define TIM_CCMR2_IC4F                       TIM_CCMR2_IC4F_Msk                  /*!< </spirit:description> */
#define TIM_CCMR2_IC4F_0        (0x1UL << TIM_CCMR2_IC4F_Pos)      /*!< 0x00001000 */
#define TIM_CCMR2_IC4F_1        (0x2UL << TIM_CCMR2_IC4F_Pos)      /*!< 0x00002000 */
#define TIM_CCMR2_IC4F_2        (0x4UL << TIM_CCMR2_IC4F_Pos)      /*!< 0x00004000 */
#define TIM_CCMR2_IC4F_3        (0x8UL << TIM_CCMR2_IC4F_Pos)      /*!< 0x00008000 */

/*******************  Bit definition for TIM_CCER register  *******************/
#define TIM_CCER_CC1E_Pos                    (0U)
#define TIM_CCER_CC1E_Msk        (0x1UL << TIM_CCER_CC1E_Pos)   /*!< 0x00000001 */
#define TIM_CCER_CC1E                        TIM_CCER_CC1E_Msk                   /*!< </spirit:description> */
#define TIM_CCER_CC1P_Pos                    (1U)
#define TIM_CCER_CC1P_Msk        (0x1UL << TIM_CCER_CC1P_Pos)   /*!< 0x00000002 */
#define TIM_CCER_CC1P                        TIM_CCER_CC1P_Msk                   /*!< </spirit:description> */
#define TIM_CCER_CC1NE_Pos                   (2U)
#define TIM_CCER_CC1NE_Msk       (0x1UL << TIM_CCER_CC1NE_Pos)    /*!< 0x00000004 */
#define TIM_CCER_CC1NE                       TIM_CCER_CC1NE_Msk                  /*!< </spirit:description> */
#define TIM_CCER_CC1NP_Pos                   (3U)
#define TIM_CCER_CC1NP_Msk       (0x1UL << TIM_CCER_CC1NP_Pos)    /*!< 0x00000008 */
#define TIM_CCER_CC1NP                       TIM_CCER_CC1NP_Msk                  /*!< </spirit:description> */
#define TIM_CCER_CC2E_Pos                    (4U)
#define TIM_CCER_CC2E_Msk        (0x1UL << TIM_CCER_CC2E_Pos)   /*!< 0x00000010 */
#define TIM_CCER_CC2E                        TIM_CCER_CC2E_Msk                   /*!< </spirit:description> */
#define TIM_CCER_CC2P_Pos                    (5U)
#define TIM_CCER_CC2P_Msk        (0x1UL << TIM_CCER_CC2P_Pos)   /*!< 0x00000020 */
#define TIM_CCER_CC2P                        TIM_CCER_CC2P_Msk                   /*!< </spirit:description> */
#define TIM_CCER_CC2NE_Pos                   (6U)
#define TIM_CCER_CC2NE_Msk       (0x1UL << TIM_CCER_CC2NE_Pos)    /*!< 0x00000040 */
#define TIM_CCER_CC2NE                       TIM_CCER_CC2NE_Msk                  /*!< </spirit:description> */
#define TIM_CCER_CC2NP_Pos                   (7U)
#define TIM_CCER_CC2NP_Msk       (0x1UL << TIM_CCER_CC2NP_Pos)    /*!< 0x00000080 */
#define TIM_CCER_CC2NP                       TIM_CCER_CC2NP_Msk                  /*!< </spirit:description> */
#define TIM_CCER_CC3E_Pos                    (8U)
#define TIM_CCER_CC3E_Msk        (0x1UL << TIM_CCER_CC3E_Pos)   /*!< 0x00000100 */
#define TIM_CCER_CC3E                        TIM_CCER_CC3E_Msk                   /*!< </spirit:description> */
#define TIM_CCER_CC3P_Pos                    (9U)
#define TIM_CCER_CC3P_Msk        (0x1UL << TIM_CCER_CC3P_Pos)   /*!< 0x00000200 */
#define TIM_CCER_CC3P                        TIM_CCER_CC3P_Msk                   /*!< </spirit:description> */
#define TIM_CCER_CC3NE_Pos                   (10U)
#define TIM_CCER_CC3NE_Msk       (0x1UL << TIM_CCER_CC3NE_Pos)    /*!< 0x00000400 */
#define TIM_CCER_CC3NE                       TIM_CCER_CC3NE_Msk                  /*!< </spirit:description> */
#define TIM_CCER_CC3NP_Pos                   (11U)
#define TIM_CCER_CC3NP_Msk       (0x1UL << TIM_CCER_CC3NP_Pos)    /*!< 0x00000800 */
#define TIM_CCER_CC3NP                       TIM_CCER_CC3NP_Msk                  /*!< </spirit:description> */
#define TIM_CCER_CC4E_Pos                    (12U)
#define TIM_CCER_CC4E_Msk        (0x1UL << TIM_CCER_CC4E_Pos)   /*!< 0x00001000 */
#define TIM_CCER_CC4E                        TIM_CCER_CC4E_Msk                   /*!< </spirit:description> */
#define TIM_CCER_CC4P_Pos                    (13U)
#define TIM_CCER_CC4P_Msk        (0x1UL << TIM_CCER_CC4P_Pos)   /*!< 0x00002000 */
#define TIM_CCER_CC4P                        TIM_CCER_CC4P_Msk                   /*!< </spirit:description> */
#define TIM_CCER_CC4NE_Pos                   (14U)
#define TIM_CCER_CC4NE_Msk       (0x1UL << TIM_CCER_CC4NE_Pos)    /*!< 0x00004000 */
#define TIM_CCER_CC4NE                       TIM_CCER_CC4NE_Msk                  /*!< </spirit:description> */
#define TIM_CCER_CC4NP_Pos                   (15U)
#define TIM_CCER_CC4NP_Msk       (0x1UL << TIM_CCER_CC4NP_Pos)    /*!< 0x00008000 */
#define TIM_CCER_CC4NP                       TIM_CCER_CC4NP_Msk                  /*!< </spirit:description> */
#define TIM_CCER_CC5E_Pos                    (16U)
#define TIM_CCER_CC5E_Msk        (0x1UL << TIM_CCER_CC5E_Pos)   /*!< 0x00010000 */
#define TIM_CCER_CC5E                        TIM_CCER_CC5E_Msk                   /*!< </spirit:description> */
#define TIM_CCER_CC5P_Pos                    (17U)
#define TIM_CCER_CC5P_Msk        (0x1UL << TIM_CCER_CC5P_Pos)   /*!< 0x00020000 */
#define TIM_CCER_CC5P                        TIM_CCER_CC5P_Msk                   /*!< </spirit:description> */
#define TIM_CCER_CC6E_Pos                    (20U)
#define TIM_CCER_CC6E_Msk        (0x1UL << TIM_CCER_CC6E_Pos)   /*!< 0x00100000 */
#define TIM_CCER_CC6E                        TIM_CCER_CC6E_Msk                   /*!< </spirit:description> */
#define TIM_CCER_CC6P_Pos                    (21U)
#define TIM_CCER_CC6P_Msk        (0x1UL << TIM_CCER_CC6P_Pos)   /*!< 0x00200000 */
#define TIM_CCER_CC6P                        TIM_CCER_CC6P_Msk                   /*!< </spirit:description> */

/*******************  Bit definition for TIM_CNT register  ********************/
#define TIM_CNT_CNT_Pos                      (0U)
#define TIM_CNT_CNT_Msk          (0xFFFFFFFFUL << TIM_CNT_CNT_Pos)        /*!< 0xFFFFFFFF */
#define TIM_CNT_CNT                          TIM_CNT_CNT_Msk                     /*!< </spirit:description> */
#define TIM_CNT_UIFCPY_Pos                   (31U)
#define TIM_CNT_UIFCPY_Msk       (0x1UL << TIM_CNT_UIFCPY_Pos)    /*!< 0x80000000 */
#define TIM_CNT_UIFCPY                       TIM_CNT_UIFCPY_Msk                  /*!< </spirit:description> */

/*******************  Bit definition for TIM_PSC register  ********************/
#define TIM_PSC_PSC_Pos                      (0U)
#define TIM_PSC_PSC_Msk          (0xFFFFUL << TIM_PSC_PSC_Pos)    /*!< 0x0000FFFF */
#define TIM_PSC_PSC                          TIM_PSC_PSC_Msk                     /*!< </spirit:description> */

/*******************  Bit definition for TIM_ARR register  ********************/
#define TIM_ARR_ARR_Pos                      (0U)
#define TIM_ARR_ARR_Msk          (0xFFFFFFFFUL << TIM_ARR_ARR_Pos)        /*!< 0xFFFFFFFF */
#define TIM_ARR_ARR                          TIM_ARR_ARR_Msk                     /*!< </spirit:description> */

/*******************  Bit definition for TIM_RCR register  ********************/
#define TIM_RCR_REP_Pos                      (0U)
#define TIM_RCR_REP_Msk          (0xFFFFUL << TIM_RCR_REP_Pos)    /*!< 0x0000FFFF */
#define TIM_RCR_REP                          TIM_RCR_REP_Msk                     /*!< </spirit:description> */

/*******************  Bit definition for TIM_CCR1 register  *******************/
#define TIM_CCR1_CCR1_Pos                    (0U)
#define TIM_CCR1_CCR1_Msk        (0xFFFFFFFFUL << TIM_CCR1_CCR1_Pos)          /*!< 0xFFFFFFFF */
#define TIM_CCR1_CCR1                        TIM_CCR1_CCR1_Msk                   /*!< </spirit:description> */

/*******************  Bit definition for TIM_CCR2 register  *******************/
#define TIM_CCR2_CCR2_Pos                    (0U)
#define TIM_CCR2_CCR2_Msk        (0xFFFFFFFFUL << TIM_CCR2_CCR2_Pos)          /*!< 0xFFFFFFFF */
#define TIM_CCR2_CCR2                        TIM_CCR2_CCR2_Msk                   /*!< </spirit:description> */

/*******************  Bit definition for TIM_CCR3 register  *******************/
#define TIM_CCR3_CCR3_Pos                    (0U)
#define TIM_CCR3_CCR3_Msk        (0xFFFFFFFFUL << TIM_CCR3_CCR3_Pos)          /*!< 0xFFFFFFFF */
#define TIM_CCR3_CCR3                        TIM_CCR3_CCR3_Msk                   /*!< </spirit:description> */

/*******************  Bit definition for TIM_CCR4 register  *******************/
#define TIM_CCR4_CCR4_Pos                    (0U)
#define TIM_CCR4_CCR4_Msk        (0xFFFFFFFFUL << TIM_CCR4_CCR4_Pos)          /*!< 0xFFFFFFFF */
#define TIM_CCR4_CCR4                        TIM_CCR4_CCR4_Msk                   /*!< </spirit:description> */

/*******************  Bit definition for TIM_BDTR register  *******************/
#define TIM_BDTR_DTG_Pos                     (0U)
#define TIM_BDTR_DTG_Msk         (0xFFUL << TIM_BDTR_DTG_Pos)   /*!< 0x000000FF */
#define TIM_BDTR_DTG                         TIM_BDTR_DTG_Msk                    /*!< </spirit:description> */
#define TIM_BDTR_DTG_0          (0x1UL << TIM_BDTR_DTG_Pos)     /*!< 0x00000001 */
#define TIM_BDTR_DTG_1          (0x2UL << TIM_BDTR_DTG_Pos)     /*!< 0x00000002 */
#define TIM_BDTR_DTG_2          (0x4UL << TIM_BDTR_DTG_Pos)     /*!< 0x00000004 */
#define TIM_BDTR_DTG_3          (0x8UL << TIM_BDTR_DTG_Pos)     /*!< 0x00000008 */
#define TIM_BDTR_DTG_4          (0x10UL << TIM_BDTR_DTG_Pos)     /*!< 0x00000010 */
#define TIM_BDTR_DTG_5          (0x20UL << TIM_BDTR_DTG_Pos)     /*!< 0x00000020 */
#define TIM_BDTR_DTG_6          (0x40UL << TIM_BDTR_DTG_Pos)     /*!< 0x00000040 */
#define TIM_BDTR_DTG_7          (0x80UL << TIM_BDTR_DTG_Pos)     /*!< 0x00000080 */
#define TIM_BDTR_LOCK_Pos                    (8U)
#define TIM_BDTR_LOCK_Msk        (0x3UL << TIM_BDTR_LOCK_Pos)   /*!< 0x00000300 */
#define TIM_BDTR_LOCK                        TIM_BDTR_LOCK_Msk                   /*!< </spirit:description> */
#define TIM_BDTR_LOCK_0         (0x1UL << TIM_BDTR_LOCK_Pos)     /*!< 0x00000100 */
#define TIM_BDTR_LOCK_1         (0x2UL << TIM_BDTR_LOCK_Pos)     /*!< 0x00000200 */
#define TIM_BDTR_OSSI_Pos                    (10U)
#define TIM_BDTR_OSSI_Msk        (0x1UL << TIM_BDTR_OSSI_Pos)   /*!< 0x00000400 */
#define TIM_BDTR_OSSI                        TIM_BDTR_OSSI_Msk                   /*!< </spirit:description> */
#define TIM_BDTR_OSSR_Pos                    (11U)
#define TIM_BDTR_OSSR_Msk        (0x1UL << TIM_BDTR_OSSR_Pos)   /*!< 0x00000800 */
#define TIM_BDTR_OSSR                        TIM_BDTR_OSSR_Msk                   /*!< </spirit:description> */
#define TIM_BDTR_BKE_Pos                     (12U)
#define TIM_BDTR_BKE_Msk         (0x1UL << TIM_BDTR_BKE_Pos)  /*!< 0x00001000 */
#define TIM_BDTR_BKE                         TIM_BDTR_BKE_Msk                    /*!< </spirit:description> */
#define TIM_BDTR_BKP_Pos                     (13U)
#define TIM_BDTR_BKP_Msk         (0x1UL << TIM_BDTR_BKP_Pos)  /*!< 0x00002000 */
#define TIM_BDTR_BKP                         TIM_BDTR_BKP_Msk                    /*!< </spirit:description> */
#define TIM_BDTR_AOE_Pos                     (14U)
#define TIM_BDTR_AOE_Msk         (0x1UL << TIM_BDTR_AOE_Pos)  /*!< 0x00004000 */
#define TIM_BDTR_AOE                         TIM_BDTR_AOE_Msk                    /*!< </spirit:description> */
#define TIM_BDTR_MOE_Pos                     (15U)
#define TIM_BDTR_MOE_Msk         (0x1UL << TIM_BDTR_MOE_Pos)  /*!< 0x00008000 */
#define TIM_BDTR_MOE                         TIM_BDTR_MOE_Msk                    /*!< </spirit:description> */
#define TIM_BDTR_BKF_Pos                     (16U)
#define TIM_BDTR_BKF_Msk         (0xFUL << TIM_BDTR_BKF_Pos)  /*!< 0x000F0000 */
#define TIM_BDTR_BKF                         TIM_BDTR_BKF_Msk                    /*!< </spirit:description> */
#define TIM_BDTR_BK2F_Pos                    (20U)
#define TIM_BDTR_BK2F_Msk        (0xFUL << TIM_BDTR_BK2F_Pos)   /*!< 0x00F00000 */
#define TIM_BDTR_BK2F                        TIM_BDTR_BK2F_Msk                   /*!< </spirit:description> */
#define TIM_BDTR_BK2E_Pos                    (24U)
#define TIM_BDTR_BK2E_Msk        (0x1UL << TIM_BDTR_BK2E_Pos)   /*!< 0x01000000 */
#define TIM_BDTR_BK2E                        TIM_BDTR_BK2E_Msk                   /*!< </spirit:description> */
#define TIM_BDTR_BK2P_Pos                    (25U)
#define TIM_BDTR_BK2P_Msk        (0x1UL << TIM_BDTR_BK2P_Pos)   /*!< 0x02000000 */
#define TIM_BDTR_BK2P                        TIM_BDTR_BK2P_Msk                   /*!< </spirit:description> */
#define TIM_BDTR_BKDSRM_Pos                  (26U)
#define TIM_BDTR_BKDSRM_Msk      (0x1UL << TIM_BDTR_BKDSRM_Pos)     /*!< 0x04000000 */
#define TIM_BDTR_BKDSRM                      TIM_BDTR_BKDSRM_Msk                 /*!< </spirit:description> */
#define TIM_BDTR_BK2DSRM_Pos                 (27U)
#define TIM_BDTR_BK2DSRM_Msk     (0x1UL << TIM_BDTR_BK2DSRM_Pos)      /*!< 0x08000000 */
#define TIM_BDTR_BK2DSRM                     TIM_BDTR_BK2DSRM_Msk                /*!< </spirit:description> */
#define TIM_BDTR_BKBID_Pos                   (28U)
#define TIM_BDTR_BKBID_Msk       (0x1UL << TIM_BDTR_BKBID_Pos)    /*!< 0x10000000 */
#define TIM_BDTR_BKBID                       TIM_BDTR_BKBID_Msk                  /*!< </spirit:description> */
#define TIM_BDTR_BK2BID_Pos                  (29U)
#define TIM_BDTR_BK2BID_Msk      (0x1UL << TIM_BDTR_BK2BID_Pos)     /*!< 0x20000000 */
#define TIM_BDTR_BK2BID                      TIM_BDTR_BK2BID_Msk                 /*!< </spirit:description> */

/*******************  Bit definition for TIM_CCR5 register  *******************/
#define TIM_CCR5_CCR5_Pos                    (0U)
#define TIM_CCR5_CCR5_Msk        (0xFFFFFFFFUL << TIM_CCR5_CCR5_Pos)          /*!< 0xFFFFFFFF */
#define TIM_CCR5_CCR5                        TIM_CCR5_CCR5_Msk                   /*!< </spirit:description> */
#define TIM_CCR5_GC5C1_Pos                   (29U)
#define TIM_CCR5_GC5C1_Msk       (0x1UL << TIM_CCR5_GC5C1_Pos)    /*!< 0x20000000 */
#define TIM_CCR5_GC5C1                       TIM_CCR5_GC5C1_Msk                  /*!< </spirit:description> */
#define TIM_CCR5_GC5C2_Pos                   (30U)
#define TIM_CCR5_GC5C2_Msk       (0x1UL << TIM_CCR5_GC5C2_Pos)    /*!< 0x40000000 */
#define TIM_CCR5_GC5C2                       TIM_CCR5_GC5C2_Msk                  /*!< </spirit:description> */
#define TIM_CCR5_GC5C3_Pos                   (31U)
#define TIM_CCR5_GC5C3_Msk       (0x1UL << TIM_CCR5_GC5C3_Pos)    /*!< 0x80000000 */
#define TIM_CCR5_GC5C3                       TIM_CCR5_GC5C3_Msk                  /*!< </spirit:description> */

/*******************  Bit definition for TIM_CCR6 register  *******************/
#define TIM_CCR6_CCR6_Pos                    (0U)
#define TIM_CCR6_CCR6_Msk        (0xFFFFFFFFUL << TIM_CCR6_CCR6_Pos)          /*!< 0xFFFFFFFF */
#define TIM_CCR6_CCR6                        TIM_CCR6_CCR6_Msk                   /*!< </spirit:description> */

/******************  Bit definition for TIM_CCMR3 register  *******************/
#define TIM_CCMR3_OC5FE_Pos                  (2U)
#define TIM_CCMR3_OC5FE_Msk      (0x1UL << TIM_CCMR3_OC5FE_Pos)     /*!< 0x00000004 */
#define TIM_CCMR3_OC5FE                      TIM_CCMR3_OC5FE_Msk                 /*!< </spirit:description> */
#define TIM_CCMR3_OC5PE_Pos                  (3U)
#define TIM_CCMR3_OC5PE_Msk      (0x1UL << TIM_CCMR3_OC5PE_Pos)     /*!< 0x00000008 */
#define TIM_CCMR3_OC5PE                      TIM_CCMR3_OC5PE_Msk                 /*!< </spirit:description> */
#define TIM_CCMR3_OC5M_Pos                   (4U)
#define TIM_CCMR3_OC5M_Msk       (0x1007UL << TIM_CCMR3_OC5M_Pos)    /*!< 0x00010070 */
#define TIM_CCMR3_OC5M                       TIM_CCMR3_OC5M_Msk                  /*!< </spirit:description> */
#define TIM_CCMR3_OC5M_0        (0x1UL << TIM_CCMR3_OC5M_Pos)      /*!< 0x00000010 */
#define TIM_CCMR3_OC5M_1        (0x2UL << TIM_CCMR3_OC5M_Pos)      /*!< 0x00000020 */
#define TIM_CCMR3_OC5M_2        (0x4UL << TIM_CCMR3_OC5M_Pos)      /*!< 0x00000040 */
#define TIM_CCMR3_OC5M_3        (0x1000UL << TIM_CCMR3_OC5M_Pos)      /*!< 0x00010000 */
#define TIM_CCMR3_OC5CE_Pos                  (7U)
#define TIM_CCMR3_OC5CE_Msk      (0x1UL << TIM_CCMR3_OC5CE_Pos)     /*!< 0x00000080 */
#define TIM_CCMR3_OC5CE                      TIM_CCMR3_OC5CE_Msk                 /*!< </spirit:description> */
#define TIM_CCMR3_OC6FE_Pos                  (10U)
#define TIM_CCMR3_OC6FE_Msk      (0x1UL << TIM_CCMR3_OC6FE_Pos)     /*!< 0x00000400 */
#define TIM_CCMR3_OC6FE                      TIM_CCMR3_OC6FE_Msk                 /*!< </spirit:description> */
#define TIM_CCMR3_OC6PE_Pos                  (11U)
#define TIM_CCMR3_OC6PE_Msk      (0x1UL << TIM_CCMR3_OC6PE_Pos)     /*!< 0x00000800 */
#define TIM_CCMR3_OC6PE                      TIM_CCMR3_OC6PE_Msk                 /*!< </spirit:description> */
#define TIM_CCMR3_OC6M_Pos                   (12U)
#define TIM_CCMR3_OC6M_Msk       (0x1007UL << TIM_CCMR3_OC6M_Pos)    /*!< 0x01007000 */
#define TIM_CCMR3_OC6M                       TIM_CCMR3_OC6M_Msk                  /*!< </spirit:description> */
#define TIM_CCMR3_OC6M_0        (0x1UL << TIM_CCMR3_OC6M_Pos)      /*!< 0x00001000 */
#define TIM_CCMR3_OC6M_1        (0x2UL << TIM_CCMR3_OC6M_Pos)      /*!< 0x00002000 */
#define TIM_CCMR3_OC6M_2        (0x4UL << TIM_CCMR3_OC6M_Pos)      /*!< 0x00004000 */
#define TIM_CCMR3_OC6M_3        (0x1000UL << TIM_CCMR3_OC6M_Pos)      /*!< 0x01000000 */
#define TIM_CCMR3_OC6CE_Pos                  (15U)
#define TIM_CCMR3_OC6CE_Msk      (0x1UL << TIM_CCMR3_OC6CE_Pos)     /*!< 0x00008000 */
#define TIM_CCMR3_OC6CE                      TIM_CCMR3_OC6CE_Msk                 /*!< </spirit:description> */

/*******************  Bit definition for TIM_DTR2 register  *******************/
#define TIM_DTR2_DTGF_Pos                    (0U)
#define TIM_DTR2_DTGF_Msk        (0xFFUL << TIM_DTR2_DTGF_Pos)    /*!< 0x000000FF */
#define TIM_DTR2_DTGF                        TIM_DTR2_DTGF_Msk                   /*!< </spirit:description> */
#define TIM_DTR2_DTGF_0         (0x1UL << TIM_DTR2_DTGF_Pos)      /*!< 0x00000001 */
#define TIM_DTR2_DTGF_1         (0x2UL << TIM_DTR2_DTGF_Pos)      /*!< 0x00000002 */
#define TIM_DTR2_DTGF_2         (0x4UL << TIM_DTR2_DTGF_Pos)      /*!< 0x00000004 */
#define TIM_DTR2_DTGF_3         (0x8UL << TIM_DTR2_DTGF_Pos)      /*!< 0x00000008 */
#define TIM_DTR2_DTGF_4         (0x10UL << TIM_DTR2_DTGF_Pos)      /*!< 0x00000010 */
#define TIM_DTR2_DTGF_5         (0x20UL << TIM_DTR2_DTGF_Pos)      /*!< 0x00000020 */
#define TIM_DTR2_DTGF_6         (0x40UL << TIM_DTR2_DTGF_Pos)      /*!< 0x00000040 */
#define TIM_DTR2_DTGF_7         (0x80UL << TIM_DTR2_DTGF_Pos)      /*!< 0x00000080 */
#define TIM_DTR2_DTAE_Pos                    (16U)
#define TIM_DTR2_DTAE_Msk        (0x1UL << TIM_DTR2_DTAE_Pos)   /*!< 0x00010000 */
#define TIM_DTR2_DTAE                        TIM_DTR2_DTAE_Msk                   /*!< </spirit:description> */
#define TIM_DTR2_DTPE_Pos                    (17U)
#define TIM_DTR2_DTPE_Msk        (0x1UL << TIM_DTR2_DTPE_Pos)   /*!< 0x00020000 */
#define TIM_DTR2_DTPE                        TIM_DTR2_DTPE_Msk                   /*!< </spirit:description> */

/*******************  Bit definition for TIM_ECR register  ********************/
#define TIM_ECR_IE_Pos                       (0U)
#define TIM_ECR_IE_Msk             (0x1UL << TIM_ECR_IE_Pos)  /*!< 0x00000001 */
#define TIM_ECR_IE                           TIM_ECR_IE_Msk                      /*!< </spirit:description> */
#define TIM_ECR_IDIR_Pos                     (1U)
#define TIM_ECR_IDIR_Msk         (0x3UL << TIM_ECR_IDIR_Pos)  /*!< 0x00000006 */
#define TIM_ECR_IDIR                         TIM_ECR_IDIR_Msk                    /*!< </spirit:description> */
#define TIM_ECR_IDIR_0          (0x1UL << TIM_ECR_IDIR_Pos)    /*!< 0x00000002 */
#define TIM_ECR_IDIR_1          (0x2UL << TIM_ECR_IDIR_Pos)    /*!< 0x00000004 */
#define TIM_ECR_FIDX_Pos                     (5U)
#define TIM_ECR_FIDX_Msk         (0x1UL << TIM_ECR_FIDX_Pos)  /*!< 0x00000020 */
#define TIM_ECR_FIDX                         TIM_ECR_FIDX_Msk                    /*!< </spirit:description> */
#define TIM_ECR_IPOS_Pos                     (6U)
#define TIM_ECR_IPOS_Msk         (0x3UL << TIM_ECR_IPOS_Pos)  /*!< 0x000000C0 */
#define TIM_ECR_IPOS                         TIM_ECR_IPOS_Msk                    /*!< </spirit:description> */
#define TIM_ECR_IPOS_0          (0x1UL << TIM_ECR_IPOS_Pos)    /*!< 0x00000040 */
#define TIM_ECR_IPOS_1          (0x2UL << TIM_ECR_IPOS_Pos)    /*!< 0x00000080 */
#define TIM_ECR_PW_Pos                       (16U)
#define TIM_ECR_PW_Msk           (0xFFUL << TIM_ECR_PW_Pos) /*!< 0x00FF0000 */
#define TIM_ECR_PW                           TIM_ECR_PW_Msk                      /*!< </spirit:description> */
#define TIM_ECR_PW_0            (0x1UL << TIM_ECR_PW_Pos)   /*!< 0x00010000 */
#define TIM_ECR_PW_1            (0x2UL << TIM_ECR_PW_Pos)   /*!< 0x00020000 */
#define TIM_ECR_PW_2            (0x4UL << TIM_ECR_PW_Pos)   /*!< 0x00040000 */
#define TIM_ECR_PW_3            (0x8UL << TIM_ECR_PW_Pos)   /*!< 0x00080000 */
#define TIM_ECR_PW_4            (0x10UL << TIM_ECR_PW_Pos)   /*!< 0x00100000 */
#define TIM_ECR_PW_5            (0x20UL << TIM_ECR_PW_Pos)   /*!< 0x00200000 */
#define TIM_ECR_PW_6            (0x40UL << TIM_ECR_PW_Pos)   /*!< 0x00400000 */
#define TIM_ECR_PW_7            (0x80UL << TIM_ECR_PW_Pos)   /*!< 0x00800000 */
#define TIM_ECR_PWPRSC_Pos                   (24U)
#define TIM_ECR_PWPRSC_Msk       (0x7UL << TIM_ECR_PWPRSC_Pos)    /*!< 0x07000000 */
#define TIM_ECR_PWPRSC                       TIM_ECR_PWPRSC_Msk                  /*!< </spirit:description> */
#define TIM_ECR_PWPRSC_0        (0x1UL << TIM_ECR_PWPRSC_Pos)      /*!< 0x01000000 */
#define TIM_ECR_PWPRSC_1        (0x2UL << TIM_ECR_PWPRSC_Pos)      /*!< 0x02000000 */
#define TIM_ECR_PWPRSC_2        (0x4UL << TIM_ECR_PWPRSC_Pos)      /*!< 0x04000000 */

/******************  Bit definition for TIM_TISEL register  *******************/
#define TIM_TISEL_TI1SEL_Pos                 (0U)
#define TIM_TISEL_TI1SEL_Msk     (0xFUL << TIM_TISEL_TI1SEL_Pos)      /*!< 0x0000000F */
#define TIM_TISEL_TI1SEL                     TIM_TISEL_TI1SEL_Msk                /*!< </spirit:description> */
#define TIM_TISEL_TI1SEL_0      (0x1UL << TIM_TISEL_TI1SEL_Pos)        /*!< 0x00000001 */
#define TIM_TISEL_TI1SEL_1      (0x2UL << TIM_TISEL_TI1SEL_Pos)        /*!< 0x00000002 */
#define TIM_TISEL_TI1SEL_2      (0x4UL << TIM_TISEL_TI1SEL_Pos)        /*!< 0x00000004 */
#define TIM_TISEL_TI1SEL_3      (0x8UL << TIM_TISEL_TI1SEL_Pos)        /*!< 0x00000008 */
#define TIM_TISEL_TI2SEL_Pos                 (8U)
#define TIM_TISEL_TI2SEL_Msk     (0xFUL << TIM_TISEL_TI2SEL_Pos)      /*!< 0x00000F00 */
#define TIM_TISEL_TI2SEL                     TIM_TISEL_TI2SEL_Msk                /*!< </spirit:description> */
#define TIM_TISEL_TI2SEL_0      (0x1UL << TIM_TISEL_TI2SEL_Pos)        /*!< 0x00000100 */
#define TIM_TISEL_TI2SEL_1      (0x2UL << TIM_TISEL_TI2SEL_Pos)        /*!< 0x00000200 */
#define TIM_TISEL_TI2SEL_2      (0x4UL << TIM_TISEL_TI2SEL_Pos)        /*!< 0x00000400 */
#define TIM_TISEL_TI2SEL_3      (0x8UL << TIM_TISEL_TI2SEL_Pos)        /*!< 0x00000800 */
#define TIM_TISEL_TI3SEL_Pos                 (16U)
#define TIM_TISEL_TI3SEL_Msk     (0xFUL << TIM_TISEL_TI3SEL_Pos)      /*!< 0x000F0000 */
#define TIM_TISEL_TI3SEL                     TIM_TISEL_TI3SEL_Msk                /*!< </spirit:description> */
#define TIM_TISEL_TI3SEL_0      (0x1UL << TIM_TISEL_TI3SEL_Pos)        /*!< 0x00010000 */
#define TIM_TISEL_TI3SEL_1      (0x2UL << TIM_TISEL_TI3SEL_Pos)        /*!< 0x00020000 */
#define TIM_TISEL_TI3SEL_2      (0x4UL << TIM_TISEL_TI3SEL_Pos)        /*!< 0x00040000 */
#define TIM_TISEL_TI3SEL_3      (0x8UL << TIM_TISEL_TI3SEL_Pos)        /*!< 0x00080000 */
#define TIM_TISEL_TI4SEL_Pos                 (24U)
#define TIM_TISEL_TI4SEL_Msk     (0xFUL << TIM_TISEL_TI4SEL_Pos)      /*!< 0x0F000000 */
#define TIM_TISEL_TI4SEL                     TIM_TISEL_TI4SEL_Msk                /*!< </spirit:description> */
#define TIM_TISEL_TI4SEL_0      (0x1UL << TIM_TISEL_TI4SEL_Pos)        /*!< 0x01000000 */
#define TIM_TISEL_TI4SEL_1      (0x2UL << TIM_TISEL_TI4SEL_Pos)        /*!< 0x02000000 */
#define TIM_TISEL_TI4SEL_2      (0x4UL << TIM_TISEL_TI4SEL_Pos)        /*!< 0x04000000 */
#define TIM_TISEL_TI4SEL_3      (0x8UL << TIM_TISEL_TI4SEL_Pos)        /*!< 0x08000000 */

/*******************  Bit definition for TIM_AF1 register  ********************/
#define TIM_AF1_BKINE_Pos                    (0U)
#define TIM_AF1_BKINE_Msk        (0x1UL << TIM_AF1_BKINE_Pos)   /*!< 0x00000001 */
#define TIM_AF1_BKINE                        TIM_AF1_BKINE_Msk                   /*!< </spirit:description> */
#define TIM_AF1_BKCMP1E_Pos                  (1U)
#define TIM_AF1_BKCMP1E_Msk      (0x1UL << TIM_AF1_BKCMP1E_Pos)     /*!< 0x00000002 */
#define TIM_AF1_BKCMP1E                      TIM_AF1_BKCMP1E_Msk                 /*!< </spirit:description> */
#define TIM_AF1_BKCMP2E_Pos                  (2U)
#define TIM_AF1_BKCMP2E_Msk      (0x1UL << TIM_AF1_BKCMP2E_Pos)     /*!< 0x00000004 */
#define TIM_AF1_BKCMP2E                      TIM_AF1_BKCMP2E_Msk                 /*!< </spirit:description> */
#define TIM_AF1_BKCMP3E_Pos                  (3U)
#define TIM_AF1_BKCMP3E_Msk      (0x1UL << TIM_AF1_BKCMP3E_Pos)     /*!< 0x00000008 */
#define TIM_AF1_BKCMP3E                      TIM_AF1_BKCMP3E_Msk                 /*!< </spirit:description> */
#define TIM_AF1_BKCMP4E_Pos                  (4U)
#define TIM_AF1_BKCMP4E_Msk      (0x1UL << TIM_AF1_BKCMP4E_Pos)     /*!< 0x00000010 */
#define TIM_AF1_BKCMP4E                      TIM_AF1_BKCMP4E_Msk                 /*!< </spirit:description> */
#define TIM_AF1_BKCMP5E_Pos                  (5U)
#define TIM_AF1_BKCMP5E_Msk      (0x1UL << TIM_AF1_BKCMP5E_Pos)     /*!< 0x00000020 */
#define TIM_AF1_BKCMP5E                      TIM_AF1_BKCMP5E_Msk                 /*!< </spirit:description> */
#define TIM_AF1_BKCMP6E_Pos                  (6U)
#define TIM_AF1_BKCMP6E_Msk      (0x1UL << TIM_AF1_BKCMP6E_Pos)     /*!< 0x00000040 */
#define TIM_AF1_BKCMP6E                      TIM_AF1_BKCMP6E_Msk                 /*!< </spirit:description> */
#define TIM_AF1_BKCMP7E_Pos                  (7U)
#define TIM_AF1_BKCMP7E_Msk      (0x1UL << TIM_AF1_BKCMP7E_Pos)     /*!< 0x00000080 */
#define TIM_AF1_BKCMP7E                      TIM_AF1_BKCMP7E_Msk                 /*!< </spirit:description> */
#define TIM_AF1_BKCMP8E_Pos                  (8U)
#define TIM_AF1_BKCMP8E_Msk      (0x1UL << TIM_AF1_BKCMP8E_Pos)     /*!< 0x00000100 */
#define TIM_AF1_BKCMP8E                      TIM_AF1_BKCMP8E_Msk                 /*!< </spirit:description> */
#define TIM_AF1_BKINP_Pos                    (9U)
#define TIM_AF1_BKINP_Msk        (0x1UL << TIM_AF1_BKINP_Pos)   /*!< 0x00000200 */
#define TIM_AF1_BKINP                        TIM_AF1_BKINP_Msk                   /*!< </spirit:description> */
#define TIM_AF1_BKCMP1P_Pos                  (10U)
#define TIM_AF1_BKCMP1P_Msk      (0x1UL << TIM_AF1_BKCMP1P_Pos)     /*!< 0x00000400 */
#define TIM_AF1_BKCMP1P                      TIM_AF1_BKCMP1P_Msk                 /*!< </spirit:description> */
#define TIM_AF1_BKCMP2P_Pos                  (11U)
#define TIM_AF1_BKCMP2P_Msk      (0x1UL << TIM_AF1_BKCMP2P_Pos)     /*!< 0x00000800 */
#define TIM_AF1_BKCMP2P                      TIM_AF1_BKCMP2P_Msk                 /*!< </spirit:description> */
#define TIM_AF1_BKCMP3P_Pos                  (12U)
#define TIM_AF1_BKCMP3P_Msk      (0x1UL << TIM_AF1_BKCMP3P_Pos)     /*!< 0x00001000 */
#define TIM_AF1_BKCMP3P                      TIM_AF1_BKCMP3P_Msk                 /*!< </spirit:description> */
#define TIM_AF1_BKCMP4P_Pos                  (13U)
#define TIM_AF1_BKCMP4P_Msk      (0x1UL << TIM_AF1_BKCMP4P_Pos)     /*!< 0x00002000 */
#define TIM_AF1_BKCMP4P                      TIM_AF1_BKCMP4P_Msk                 /*!< </spirit:description> */
#define TIM_AF1_ETRSEL_Pos                   (14U)
#define TIM_AF1_ETRSEL_Msk       (0xFUL << TIM_AF1_ETRSEL_Pos)    /*!< 0x0003C000 */
#define TIM_AF1_ETRSEL                       TIM_AF1_ETRSEL_Msk                  /*!< </spirit:description> */
#define TIM_AF1_ETRSEL_0        (0x1UL << TIM_AF1_ETRSEL_Pos)      /*!< 0x00004000 */
#define TIM_AF1_ETRSEL_1        (0x2UL << TIM_AF1_ETRSEL_Pos)      /*!< 0x00008000 */
#define TIM_AF1_ETRSEL_2        (0x4UL << TIM_AF1_ETRSEL_Pos)      /*!< 0x00010000 */
#define TIM_AF1_ETRSEL_3        (0x8UL << TIM_AF1_ETRSEL_Pos)      /*!< 0x00020000 */

/*******************  Bit definition for TIM_AF2 register  ********************/
#define TIM_AF2_BK2INE_Pos                   (0U)
#define TIM_AF2_BK2INE_Msk       (0x1UL << TIM_AF2_BK2INE_Pos)    /*!< 0x00000001 */
#define TIM_AF2_BK2INE                       TIM_AF2_BK2INE_Msk                  /*!< </spirit:description> */
#define TIM_AF2_BK2CMP1E_Pos                 (1U)
#define TIM_AF2_BK2CMP1E_Msk     (0x1UL << TIM_AF2_BK2CMP1E_Pos)      /*!< 0x00000002 */
#define TIM_AF2_BK2CMP1E                     TIM_AF2_BK2CMP1E_Msk                /*!< </spirit:description> */
#define TIM_AF2_BK2CMP2E_Pos                 (2U)
#define TIM_AF2_BK2CMP2E_Msk     (0x1UL << TIM_AF2_BK2CMP2E_Pos)      /*!< 0x00000004 */
#define TIM_AF2_BK2CMP2E                     TIM_AF2_BK2CMP2E_Msk                /*!< </spirit:description> */
#define TIM_AF2_BK2CMP3E_Pos                 (3U)
#define TIM_AF2_BK2CMP3E_Msk     (0x1UL << TIM_AF2_BK2CMP3E_Pos)      /*!< 0x00000008 */
#define TIM_AF2_BK2CMP3E                     TIM_AF2_BK2CMP3E_Msk                /*!< </spirit:description> */
#define TIM_AF2_BK2CMP4E_Pos                 (4U)
#define TIM_AF2_BK2CMP4E_Msk     (0x1UL << TIM_AF2_BK2CMP4E_Pos)      /*!< 0x00000010 */
#define TIM_AF2_BK2CMP4E                     TIM_AF2_BK2CMP4E_Msk                /*!< </spirit:description> */
#define TIM_AF2_BK2CMP5E_Pos                 (5U)
#define TIM_AF2_BK2CMP5E_Msk     (0x1UL << TIM_AF2_BK2CMP5E_Pos)      /*!< 0x00000020 */
#define TIM_AF2_BK2CMP5E                     TIM_AF2_BK2CMP5E_Msk                /*!< </spirit:description> */
#define TIM_AF2_BK2CMP6E_Pos                 (6U)
#define TIM_AF2_BK2CMP6E_Msk     (0x1UL << TIM_AF2_BK2CMP6E_Pos)      /*!< 0x00000040 */
#define TIM_AF2_BK2CMP6E                     TIM_AF2_BK2CMP6E_Msk                /*!< </spirit:description> */
#define TIM_AF2_BK2CMP7E_Pos                 (7U)
#define TIM_AF2_BK2CMP7E_Msk     (0x1UL << TIM_AF2_BK2CMP7E_Pos)      /*!< 0x00000080 */
#define TIM_AF2_BK2CMP7E                     TIM_AF2_BK2CMP7E_Msk                /*!< </spirit:description> */
#define TIM_AF2_BK2CMP8E_Pos                 (8U)
#define TIM_AF2_BK2CMP8E_Msk     (0x1UL << TIM_AF2_BK2CMP8E_Pos)      /*!< 0x00000100 */
#define TIM_AF2_BK2CMP8E                     TIM_AF2_BK2CMP8E_Msk                /*!< </spirit:description> */
#define TIM_AF2_BK2INP_Pos                   (9U)
#define TIM_AF2_BK2INP_Msk       (0x1UL << TIM_AF2_BK2INP_Pos)    /*!< 0x00000200 */
#define TIM_AF2_BK2INP                       TIM_AF2_BK2INP_Msk                  /*!< </spirit:description> */
#define TIM_AF2_BK2CMP1P_Pos                 (10U)
#define TIM_AF2_BK2CMP1P_Msk     (0x1UL << TIM_AF2_BK2CMP1P_Pos)      /*!< 0x00000400 */
#define TIM_AF2_BK2CMP1P                     TIM_AF2_BK2CMP1P_Msk                /*!< </spirit:description> */
#define TIM_AF2_BK2CMP2P_Pos                 (11U)
#define TIM_AF2_BK2CMP2P_Msk     (0x1UL << TIM_AF2_BK2CMP2P_Pos)      /*!< 0x00000800 */
#define TIM_AF2_BK2CMP2P                     TIM_AF2_BK2CMP2P_Msk                /*!< </spirit:description> */
#define TIM_AF2_BK2CMP3P_Pos                 (12U)
#define TIM_AF2_BK2CMP3P_Msk     (0x1UL << TIM_AF2_BK2CMP3P_Pos)      /*!< 0x00001000 */
#define TIM_AF2_BK2CMP3P                     TIM_AF2_BK2CMP3P_Msk                /*!< </spirit:description> */
#define TIM_AF2_BK2CMP4P_Pos                 (13U)
#define TIM_AF2_BK2CMP4P_Msk     (0x1UL << TIM_AF2_BK2CMP4P_Pos)      /*!< 0x00002000 */
#define TIM_AF2_BK2CMP4P                     TIM_AF2_BK2CMP4P_Msk                /*!< </spirit:description> */
#define TIM_AF2_OCRSEL_Pos                   (16U)
#define TIM_AF2_OCRSEL_Msk       (0x7UL << TIM_AF2_OCRSEL_Pos)    /*!< 0x00070000 */
#define TIM_AF2_OCRSEL                       TIM_AF2_OCRSEL_Msk                  /*!< </spirit:description> */
#define TIM_AF2_OCRSEL_0        (0x1UL << TIM_AF2_OCRSEL_Pos)      /*!< 0x00010000 */
#define TIM_AF2_OCRSEL_1        (0x2UL << TIM_AF2_OCRSEL_Pos)      /*!< 0x00020000 */
#define TIM_AF2_OCRSEL_2        (0x4UL << TIM_AF2_OCRSEL_Pos)      /*!< 0x00040000 */

/*******************  Bit definition for TIM_DCR register  ********************/
#define TIM_DCR_DBA_Pos                      (0U)
#define TIM_DCR_DBA_Msk          (0x1FUL << TIM_DCR_DBA_Pos)  /*!< 0x0000001F */
#define TIM_DCR_DBA                          TIM_DCR_DBA_Msk                     /*!< </spirit:description> */
#define TIM_DCR_DBA_0           (0x1UL << TIM_DCR_DBA_Pos)    /*!< 0x00000001 */
#define TIM_DCR_DBA_1           (0x2UL << TIM_DCR_DBA_Pos)    /*!< 0x00000002 */
#define TIM_DCR_DBA_2           (0x4UL << TIM_DCR_DBA_Pos)    /*!< 0x00000004 */
#define TIM_DCR_DBA_3           (0x8UL << TIM_DCR_DBA_Pos)    /*!< 0x00000008 */
#define TIM_DCR_DBA_4           (0x10UL << TIM_DCR_DBA_Pos)    /*!< 0x00000010 */
#define TIM_DCR_DBL_Pos                      (8U)
#define TIM_DCR_DBL_Msk          (0x1FUL << TIM_DCR_DBL_Pos)  /*!< 0x00001F00 */
#define TIM_DCR_DBL                          TIM_DCR_DBL_Msk                     /*!< </spirit:description> */
#define TIM_DCR_DBL_0           (0x1UL << TIM_DCR_DBL_Pos)    /*!< 0x00000100 */
#define TIM_DCR_DBL_1           (0x2UL << TIM_DCR_DBL_Pos)    /*!< 0x00000200 */
#define TIM_DCR_DBL_2           (0x4UL << TIM_DCR_DBL_Pos)    /*!< 0x00000400 */
#define TIM_DCR_DBL_3           (0x8UL << TIM_DCR_DBL_Pos)    /*!< 0x00000800 */
#define TIM_DCR_DBL_4           (0x10UL << TIM_DCR_DBL_Pos)    /*!< 0x00001000 */

/*******************  Bit definition for TIM_DMAR register  *******************/
#define TIM_DMAR_DMAB_Pos                    (0U)
#define TIM_DMAR_DMAB_Msk        (0xFFFFFFFFUL << TIM_DMAR_DMAB_Pos)          /*!< 0xFFFFFFFF */
#define TIM_DMAR_DMAB                        TIM_DMAR_DMAB_Msk                   /*!< </spirit:description> */


#define TIM1_PWM_BASE       0x42002C00UL
#define TIM2_BASE           0x40003C00UL
#define TIM3_BASE           0x40004000UL
#define TIM4_BASE           0x42003C00UL
#define TIM5_BASE           0x42004000UL
#define TIM6_BASE           0x40004400UL
#define TIM7_BASE           0x40004800UL
#define TIM8_PWM_BASE       0x42003000UL
#define TIM15_BASE          0x42004400UL
#define TIM16_BASE          0x42004800UL
#define TIM_TS_BASE         0x40004C00UL

#define TIM1_PWM            ((TIM_TypeDef *) TIM1_PWM_BASE) 
#define TIM2                ((TIM_TypeDef *) TIM2_BASE) 
#define TIM3                ((TIM_TypeDef *) TIM3_BASE) 
#define TIM4                ((TIM_TypeDef *) TIM4_BASE) 
#define TIM5                ((TIM_TypeDef *) TIM5_BASE) 
#define TIM6                ((TIM_TypeDef *) TIM6_BASE) 
#define TIM7                ((TIM_TypeDef *) TIM7_BASE) 
#define TIM8_PWM            ((TIM_TypeDef *) TIM8_PWM_BASE) 
#define TIM15               ((TIM_TypeDef *) TIM15_BASE) 
#define TIM16               ((TIM_TypeDef *) TIM16_BASE) 
#define TIM_TS              ((TIM_TypeDef *) TIM_TS_BASE)  

/* Compatibility.*/
#define TIM1                    TIM1_PWM
#define TIM8                    TIM8_PWM

#endif /* __SR5E1_TIM_H */

