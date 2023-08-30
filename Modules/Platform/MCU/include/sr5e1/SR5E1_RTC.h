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

#ifndef __SR5E1_RTC_H
#define __SR5E1_RTC_H

/******************************************************************************/
/*                                                                            */
/*                                    (RTC)                                   */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO uint32_t TR;            /*!< TR       Address offset: 0x00 */
  __IO uint32_t DR;            /*!< DR       Address offset: 0x04 */
  __I  uint32_t SSR;           /*!< SSR      Address offset: 0x08 */
  __IO uint32_t ICSR;          /*!< ICSR     Address offset: 0x0C */
  __IO uint32_t PRER;          /*!< PRER     Address offset: 0x10 */
  __IO uint32_t WUTR;          /*!< WUTR     Address offset: 0x14 */
  __IO uint32_t CR;            /*!< CR       Address offset: 0x18 */
       uint32_t RESERVED0[2];  /*!< Reserved Address offset: 0x1C-0x20 */
  __O  uint32_t WPR;           /*!< WPR      Address offset: 0x24 */
  __IO uint32_t CALR;          /*!< CALR     Address offset: 0x28 */
  __O  uint32_t SHIFTR;        /*!< SHIFTR   Address offset: 0x2C */
       uint32_t RESERVED1[4];  /*!< Reserved Address offset: 0x30-0x3C */
  __IO uint32_t ALRMAR;        /*!< ALRMAR   Address offset: 0x40 */
  __IO uint32_t ALRMASSR;      /*!< ALRMASSR Address offset: 0x44 */
       uint32_t RESERVED2[2];  /*!< Reserved Address offset: 0x48-0x4C */
  __I  uint32_t SR;            /*!< SR       Address offset: 0x50 */
  __I  uint32_t MISR;          /*!< MISR     Address offset: 0x54 */
       uint32_t RESERVED3;     /*!< Reserved Address offset: 0x58 */
  __IO uint32_t SCR;           /*!< SCR      Address offset: 0x5C */
} RTC_TypeDef;


/********************  Bit definition for RTC_TR register  ********************/
#define RTC_TR_SU_Pos                      (0U)
#define RTC_TR_SU_Msk                      (0xFUL << RTC_TR_SU_Pos)         /*!< 0x0000000F */
#define RTC_TR_SU                          RTC_TR_SU_Msk                  /*!< Second units in BCD format */
#define RTC_TR_ST_Pos                      (4U)
#define RTC_TR_ST_Msk                      (0x7UL << RTC_TR_ST_Pos)         /*!< 0x00000070 */
#define RTC_TR_ST                          RTC_TR_ST_Msk                  /*!< Second tens in BCD format */
#define RTC_TR_MNU_Pos                     (8U)
#define RTC_TR_MNU_Msk                     (0xFUL << RTC_TR_MNU_Pos)        /*!< 0x00000F00 */
#define RTC_TR_MNU                         RTC_TR_MNU_Msk                 /*!< Minute units in BCD format */
#define RTC_TR_MNT_Pos                     (12U)
#define RTC_TR_MNT_Msk                     (0x7UL << RTC_TR_MNT_Pos)        /*!< 0x00007000 */
#define RTC_TR_MNT                         RTC_TR_MNT_Msk                 /*!< Minute tens in BCD format */
#define RTC_TR_HU_Pos                      (16U)
#define RTC_TR_HU_Msk                      (0xFUL << RTC_TR_HU_Pos)         /*!< 0x000F0000 */
#define RTC_TR_HU                          RTC_TR_HU_Msk                  /*!< Hour units in BCD format */
#define RTC_TR_HT_Pos                      (20U)
#define RTC_TR_HT_Msk                      (0x3UL << RTC_TR_HT_Pos)         /*!< 0x00300000 */
#define RTC_TR_HT                          RTC_TR_HT_Msk                  /*!< Hour tens in BCD format */
#define RTC_TR_PM_Pos                      (22U)
#define RTC_TR_PM_Msk                      (0x1UL << RTC_TR_PM_Pos)         /*!< 0x00400000 */
#define RTC_TR_PM                          RTC_TR_PM_Msk                  /*!< AM/PM notation */
#define RTC_TR_PM_AM                     (0x0UL << RTC_TR_PM_Pos)         /*!< 0x00000000 */
#define RTC_TR_PM_PM                     (0x1UL << RTC_TR_PM_Pos)         /*!< 0x00400000 */

/********************  Bit definition for RTC_DR register  ********************/
#define RTC_DR_DU_Pos                      (0U)
#define RTC_DR_DU_Msk                      (0xFUL << RTC_DR_DU_Pos)         /*!< 0x0000000F */
#define RTC_DR_DU                          RTC_DR_DU_Msk                  /*!< Date units in BCD format */
#define RTC_DR_DT_Pos                      (4U)
#define RTC_DR_DT_Msk                      (0x3UL << RTC_DR_DT_Pos)         /*!< 0x00000030 */
#define RTC_DR_DT                          RTC_DR_DT_Msk                  /*!< Date tens in BCD format */
#define RTC_DR_MU_Pos                      (8U)
#define RTC_DR_MU_Msk                      (0xFUL << RTC_DR_MU_Pos)         /*!< 0x00000F00 */
#define RTC_DR_MU                          RTC_DR_MU_Msk                  /*!< </spirit:description> */
#define RTC_DR_MT_Pos                      (12U)
#define RTC_DR_MT_Msk                      (0x1UL << RTC_DR_MT_Pos)         /*!< 0x00001000 */
#define RTC_DR_MT                          RTC_DR_MT_Msk                  /*!< </spirit:description> */
#define RTC_DR_WDU_Pos                     (13U)
#define RTC_DR_WDU_Msk                     (0x7UL << RTC_DR_WDU_Pos)        /*!< 0x0000E000 */
#define RTC_DR_WDU                         RTC_DR_WDU_Msk                 /*!< </spirit:description> */
#define RTC_DR_YU_Pos                      (16U)
#define RTC_DR_YU_Msk                      (0xFUL << RTC_DR_YU_Pos)         /*!< 0x000F0000 */
#define RTC_DR_YU                          RTC_DR_YU_Msk                  /*!< </spirit:description> */
#define RTC_DR_YT_Pos                      (20U)
#define RTC_DR_YT_Msk                      (0xFUL << RTC_DR_YT_Pos)         /*!< 0x00F00000 */
#define RTC_DR_YT                          RTC_DR_YT_Msk                  /*!< </spirit:description> */

/*******************  Bit definition for RTC_SSR register  ********************/
#define RTC_SSR_SS_Pos                     (0U)
#define RTC_SSR_SS_Msk                     (0xFFFFUL << RTC_SSR_SS_Pos)     /*!< 0x0000FFFF */
#define RTC_SSR_SS                         RTC_SSR_SS_Msk                 /*!< Sub second value */

/*******************  Bit definition for RTC_ICSR register  *******************/
#define RTC_ICSR_ALRAWF_Pos                (0U)
#define RTC_ICSR_ALRAWF_Msk                (0x1UL << RTC_ICSR_ALRAWF_Pos)   /*!< 0x00000001 */
#define RTC_ICSR_ALRAWF                    RTC_ICSR_ALRAWF_Msk            /*!< Alarm A write flag */
#define RTC_ICSR_WUTWF_Pos                 (2U)
#define RTC_ICSR_WUTWF_Msk                 (0x1UL << RTC_ICSR_WUTWF_Pos)    /*!< 0x00000004 */
#define RTC_ICSR_WUTWF                     RTC_ICSR_WUTWF_Msk             /*!< Wakeup timer write flag */
#define RTC_ICSR_SHPF_Pos                  (3U)
#define RTC_ICSR_SHPF_Msk                  (0x1UL << RTC_ICSR_SHPF_Pos)     /*!< 0x00000008 */
#define RTC_ICSR_SHPF                      RTC_ICSR_SHPF_Msk              /*!< Shift operation pending */
#define RTC_ICSR_INITS_Pos                 (4U)
#define RTC_ICSR_INITS_Msk                 (0x1UL << RTC_ICSR_INITS_Pos)    /*!< 0x00000010 */
#define RTC_ICSR_INITS                     RTC_ICSR_INITS_Msk             /*!< Initialization status flag */
#define RTC_ICSR_RSF_Pos                   (5U)
#define RTC_ICSR_RSF_Msk                   (0x1UL << RTC_ICSR_RSF_Pos)      /*!< 0x00000020 */
#define RTC_ICSR_RSF                       RTC_ICSR_RSF_Msk               /*!< Registers synchronization flag */
#define RTC_ICSR_INITF_Pos                 (6U)
#define RTC_ICSR_INITF_Msk                 (0x1UL << RTC_ICSR_INITF_Pos)    /*!< 0x00000040 */
#define RTC_ICSR_INITF                     RTC_ICSR_INITF_Msk             /*!< Initialization flag */
#define RTC_ICSR_INIT_Pos                  (7U)
#define RTC_ICSR_INIT_Msk                  (0x1UL << RTC_ICSR_INIT_Pos)     /*!< 0x00000080 */
#define RTC_ICSR_INIT                      RTC_ICSR_INIT_Msk              /*!< Initialization mode */
#define RTC_ICSR_RECALPF_Pos               (16U)
#define RTC_ICSR_RECALPF_Msk               (0x1UL << RTC_ICSR_RECALPF_Pos)  /*!< 0x00010000 */
#define RTC_ICSR_RECALPF                   RTC_ICSR_RECALPF_Msk           /*!< Recalibration pending Flag */

/*******************  Bit definition for RTC_PRER register  *******************/
#define RTC_PRER_PREDIV_S_Pos              (0U)
#define RTC_PRER_PREDIV_S_Msk              (0x7FFFUL << RTC_PRER_PREDIV_S_Pos)    /*!< 0x00007FFF */
#define RTC_PRER_PREDIV_S                  RTC_PRER_PREDIV_S_Msk          /*!< </spirit:description> */
#define RTC_PRER_PREDIV_A_Pos              (16U)
#define RTC_PRER_PREDIV_A_Msk              (0x7FUL << RTC_PRER_PREDIV_A_Pos)  /*!< 0x007F0000 */
#define RTC_PRER_PREDIV_A                  RTC_PRER_PREDIV_A_Msk          /*!< </spirit:description> */

/*******************  Bit definition for RTC_WUTR register  *******************/
#define RTC_WUTR_WUT_Pos                   (0U)
#define RTC_WUTR_WUT_Msk                   (0xFFFFUL << RTC_WUTR_WUT_Pos)   /*!< 0x0000FFFF */
#define RTC_WUTR_WUT                       RTC_WUTR_WUT_Msk               /*!< </spirit:description> */

/********************  Bit definition for RTC_CR register  ********************/
#define RTC_CR_WUCKSEL_Pos                 (0U)
#define RTC_CR_WUCKSEL_Msk                 (0x7UL << RTC_CR_WUCKSEL_Pos)    /*!< 0x00000007 */
#define RTC_CR_WUCKSEL                     RTC_CR_WUCKSEL_Msk             /*!< </spirit:description> */
#define RTC_CR_REFCON_Pos                  (4U)
#define RTC_CR_REFCON_Msk                  (0x1UL << RTC_CR_REFCON_Pos)     /*!< 0x00000010 */
#define RTC_CR_REFCON                      RTC_CR_REFCON_Msk              /*!< </spirit:description> */
#define RTC_CR_BYPSHAD_Pos                 (5U)
#define RTC_CR_BYPSHAD_Msk                 (0x1UL << RTC_CR_BYPSHAD_Pos)    /*!< 0x00000020 */
#define RTC_CR_BYPSHAD                     RTC_CR_BYPSHAD_Msk             /*!< </spirit:description> */
#define RTC_CR_FMT_Pos                     (6U)
#define RTC_CR_FMT_Msk                     (0x1UL << RTC_CR_FMT_Pos)        /*!< 0x00000040 */
#define RTC_CR_FMT                         RTC_CR_FMT_Msk                 /*!< </spirit:description> */
#define RTC_CR_ALRAE_Pos                   (8U)
#define RTC_CR_ALRAE_Msk                   (0x1UL << RTC_CR_ALRAE_Pos)      /*!< 0x00000100 */
#define RTC_CR_ALRAE                       RTC_CR_ALRAE_Msk               /*!< </spirit:description> */
#define RTC_CR_WUTE_Pos                    (10U)
#define RTC_CR_WUTE_Msk                    (0x1UL << RTC_CR_WUTE_Pos)       /*!< 0x00000400 */
#define RTC_CR_WUTE                        RTC_CR_WUTE_Msk                /*!< </spirit:description> */
#define RTC_CR_ALRAIE_Pos                  (12U)
#define RTC_CR_ALRAIE_Msk                  (0x1UL << RTC_CR_ALRAIE_Pos)     /*!< 0x00001000 */
#define RTC_CR_ALRAIE                      RTC_CR_ALRAIE_Msk              /*!< </spirit:description> */
#define RTC_CR_WUTIE_Pos                   (14U)
#define RTC_CR_WUTIE_Msk                   (0x1UL << RTC_CR_WUTIE_Pos)      /*!< 0x00004000 */
#define RTC_CR_WUTIE                       RTC_CR_WUTIE_Msk               /*!< </spirit:description> */
#define RTC_CR_ADD1H_Pos                   (16U)
#define RTC_CR_ADD1H_Msk                   (0x1UL << RTC_CR_ADD1H_Pos)      /*!< 0x00010000 */
#define RTC_CR_ADD1H                       RTC_CR_ADD1H_Msk               /*!< </spirit:description> */
#define RTC_CR_SUB1H_Pos                   (17U)
#define RTC_CR_SUB1H_Msk                   (0x1UL << RTC_CR_SUB1H_Pos)      /*!< 0x00020000 */
#define RTC_CR_SUB1H                       RTC_CR_SUB1H_Msk               /*!< </spirit:description> */
#define RTC_CR_BKP_Pos                     (18U)
#define RTC_CR_BKP_Msk                     (0x1UL << RTC_CR_BKP_Pos)        /*!< 0x00040000 */
#define RTC_CR_BKP                         RTC_CR_BKP_Msk                 /*!< </spirit:description> */
#define RTC_CR_COSEL_Pos                   (19U)
#define RTC_CR_COSEL_Msk                   (0x1UL << RTC_CR_COSEL_Pos)      /*!< 0x00080000 */
#define RTC_CR_COSEL                       RTC_CR_COSEL_Msk               /*!< </spirit:description> */
#define RTC_CR_POL_Pos                     (20U)
#define RTC_CR_POL_Msk                     (0x1UL << RTC_CR_POL_Pos)        /*!< 0x00100000 */
#define RTC_CR_POL                         RTC_CR_POL_Msk                 /*!< </spirit:description> */
#define RTC_CR_OSEL_Pos                    (21U)
#define RTC_CR_OSEL_Msk                    (0x3UL << RTC_CR_OSEL_Pos)       /*!< 0x00600000 */
#define RTC_CR_OSEL                        RTC_CR_OSEL_Msk                /*!< </spirit:description> */
#define RTC_CR_OSEL_DISABLED               (0x0UL << RTC_CR_OSEL_Pos)       /*!< 0x00000000 */
#define RTC_CR_OSEL_OUTA_EN                (0x1UL << RTC_CR_OSEL_Pos)       /*!< 0x00200000 */
#define RTC_CR_OSEL_WKPOUT_EN              (0x3UL << RTC_CR_OSEL_Pos)       /*!< 0x00600000 */
#define RTC_CR_COE_Pos                     (23U)
#define RTC_CR_COE_Msk                     (0x1UL << RTC_CR_COE_Pos)        /*!< 0x00800000 */
#define RTC_CR_COE                         RTC_CR_COE_Msk                 /*!< </spirit:description> */
#define RTC_CR_TAMPOE_Pos                  (28U)
#define RTC_CR_TAMPOE_Msk                  (0x1UL << RTC_CR_TAMPOE_Pos)     /*!< 0x10000000 */
#define RTC_CR_TAMPOE                      RTC_CR_TAMPOE_Msk              /*!< </spirit:description> */
#define RTC_CR_TAMPALRM_PU_Pos             (29U)
#define RTC_CR_TAMPALRM_PU_Msk             (0x1UL << RTC_CR_TAMPALRM_PU_Pos)  /*!< 0x20000000 */
#define RTC_CR_TAMPALRM_PU                 RTC_CR_TAMPALRM_PU_Msk         /*!< </spirit:description> */
#define RTC_CR_TAMPALRM_TYPE_Pos           (30U)
#define RTC_CR_TAMPALRM_TYPE_Msk           (0x1UL << RTC_CR_TAMPALRM_TYPE_Pos)    /*!< 0x40000000 */
#define RTC_CR_TAMPALRM_TYPE               RTC_CR_TAMPALRM_TYPE_Msk       /*!< </spirit:description> */
#define RTC_CR_OUT2EN_Pos                  (31U)
#define RTC_CR_OUT2EN_Msk                  (0x1UL << RTC_CR_OUT2EN_Pos)     /*!< 0x80000000 */
#define RTC_CR_OUT2EN                      RTC_CR_OUT2EN_Msk              /*!< </spirit:description> */

/*******************  Bit definition for RTC_WPR register  ********************/
#define RTC_WPR_KEY_Pos                    (0U)
#define RTC_WPR_KEY_Msk                    (0xFFUL << RTC_WPR_KEY_Pos)      /*!< 0x000000FF */
#define RTC_WPR_KEY                        RTC_WPR_KEY_Msk                /*!< </spirit:description> */

/*******************  Bit definition for RTC_CALR register  *******************/
#define RTC_CALR_CALM_Pos                  (0U)
#define RTC_CALR_CALM_Msk                  (0x1FFUL << RTC_CALR_CALM_Pos)   /*!< 0x000001FF */
#define RTC_CALR_CALM                      RTC_CALR_CALM_Msk              /*!< </spirit:description> */
#define RTC_CALR_CALW16_Pos                (13U)
#define RTC_CALR_CALW16_Msk                (0x1UL << RTC_CALR_CALW16_Pos)   /*!< 0x00002000 */
#define RTC_CALR_CALW16                    RTC_CALR_CALW16_Msk            /*!< </spirit:description> */
#define RTC_CALR_CALW8_Pos                 (14U)
#define RTC_CALR_CALW8_Msk                 (0x1UL << RTC_CALR_CALW8_Pos)    /*!< 0x00004000 */
#define RTC_CALR_CALW8                     RTC_CALR_CALW8_Msk             /*!< </spirit:description> */
#define RTC_CALR_CALP_Pos                  (15U)
#define RTC_CALR_CALP_Msk                  (0x1UL << RTC_CALR_CALP_Pos)     /*!< 0x00008000 */
#define RTC_CALR_CALP                      RTC_CALR_CALP_Msk              /*!< </spirit:description> */

/******************  Bit definition for RTC_SHIFTR register  ******************/
#define RTC_SHIFTR_SUBFS_Pos               (0U)
#define RTC_SHIFTR_SUBFS_Msk               (0x7FFFUL << RTC_SHIFTR_SUBFS_Pos)   /*!< 0x00007FFF */
#define RTC_SHIFTR_SUBFS                   RTC_SHIFTR_SUBFS_Msk           /*!< </spirit:description> */
#define RTC_SHIFTR_ADD1S_Pos               (31U)
#define RTC_SHIFTR_ADD1S_Msk               (0x1UL << RTC_SHIFTR_ADD1S_Pos)  /*!< 0x80000000 */
#define RTC_SHIFTR_ADD1S                   RTC_SHIFTR_ADD1S_Msk           /*!< </spirit:description> */

/******************  Bit definition for RTC_ALRMAR register  ******************/
#define RTC_ALRMAR_SU_Pos                  (0U)
#define RTC_ALRMAR_SU_Msk                  (0xFUL << RTC_ALRMAR_SU_Pos)     /*!< 0x0000000F */
#define RTC_ALRMAR_SU                      RTC_ALRMAR_SU_Msk              /*!< </spirit:description> */
#define RTC_ALRMAR_ST_Pos                  (4U)
#define RTC_ALRMAR_ST_Msk                  (0x7UL << RTC_ALRMAR_ST_Pos)     /*!< 0x00000070 */
#define RTC_ALRMAR_ST                      RTC_ALRMAR_ST_Msk              /*!< </spirit:description> */
#define RTC_ALRMAR_MSK1_Pos                (7U)
#define RTC_ALRMAR_MSK1_Msk                (0x1UL << RTC_ALRMAR_MSK1_Pos)   /*!< 0x00000080 */
#define RTC_ALRMAR_MSK1                    RTC_ALRMAR_MSK1_Msk            /*!< </spirit:description> */
#define RTC_ALRMAR_MNU_Pos                 (8U)
#define RTC_ALRMAR_MNU_Msk                 (0xFUL << RTC_ALRMAR_MNU_Pos)    /*!< 0x00000F00 */
#define RTC_ALRMAR_MNU                     RTC_ALRMAR_MNU_Msk             /*!< </spirit:description> */
#define RTC_ALRMAR_MNT_Pos                 (12U)
#define RTC_ALRMAR_MNT_Msk                 (0x7UL << RTC_ALRMAR_MNT_Pos)    /*!< 0x00007000 */
#define RTC_ALRMAR_MNT                     RTC_ALRMAR_MNT_Msk             /*!< </spirit:description> */
#define RTC_ALRMAR_MSK2_Pos                (15U)
#define RTC_ALRMAR_MSK2_Msk                (0x1UL << RTC_ALRMAR_MSK2_Pos)   /*!< 0x00008000 */
#define RTC_ALRMAR_MSK2                    RTC_ALRMAR_MSK2_Msk            /*!< </spirit:description> */
#define RTC_ALRMAR_HU_Pos                  (16U)
#define RTC_ALRMAR_HU_Msk                  (0xFUL << RTC_ALRMAR_HU_Pos)     /*!< 0x000F0000 */
#define RTC_ALRMAR_HU                      RTC_ALRMAR_HU_Msk              /*!< </spirit:description> */
#define RTC_ALRMAR_HT_Pos                  (20U)
#define RTC_ALRMAR_HT_Msk                  (0x3UL << RTC_ALRMAR_HT_Pos)     /*!< 0x00300000 */
#define RTC_ALRMAR_HT                      RTC_ALRMAR_HT_Msk              /*!< </spirit:description> */
#define RTC_ALRMAR_PM_Pos                  (22U)
#define RTC_ALRMAR_PM_Msk                  (0x1UL << RTC_ALRMAR_PM_Pos)     /*!< 0x00400000 */
#define RTC_ALRMAR_PM                      RTC_ALRMAR_PM_Msk              /*!< </spirit:description> */
#define RTC_ALRMAR_MSK3_Pos                (23U)
#define RTC_ALRMAR_MSK3_Msk                (0x1UL << RTC_ALRMAR_MSK3_Pos)   /*!< 0x00800000 */
#define RTC_ALRMAR_MSK3                    RTC_ALRMAR_MSK3_Msk            /*!< </spirit:description> */
#define RTC_ALRMAR_DU_Pos                  (24U)
#define RTC_ALRMAR_DU_Msk                  (0xFUL << RTC_ALRMAR_DU_Pos)     /*!< 0x0F000000 */
#define RTC_ALRMAR_DU                      RTC_ALRMAR_DU_Msk              /*!< </spirit:description> */
#define RTC_ALRMAR_DT_Pos                  (28U)
#define RTC_ALRMAR_DT_Msk                  (0x3UL << RTC_ALRMAR_DT_Pos)     /*!< 0x30000000 */
#define RTC_ALRMAR_DT                      RTC_ALRMAR_DT_Msk              /*!< </spirit:description> */
#define RTC_ALRMAR_WDSEL_Pos               (30U)
#define RTC_ALRMAR_WDSEL_Msk               (0x1UL << RTC_ALRMAR_WDSEL_Pos)  /*!< 0x40000000 */
#define RTC_ALRMAR_WDSEL                   RTC_ALRMAR_WDSEL_Msk           /*!< </spirit:description> */
#define RTC_ALRMAR_MSK4_Pos                (31U)
#define RTC_ALRMAR_MSK4_Msk                (0x1UL << RTC_ALRMAR_MSK4_Pos)   /*!< 0x80000000 */
#define RTC_ALRMAR_MSK4                    RTC_ALRMAR_MSK4_Msk            /*!< </spirit:description> */

/*****************  Bit definition for RTC_ALRMASSR register  *****************/
#define RTC_ALRMASSR_SS_Pos                (0U)
#define RTC_ALRMASSR_SS_Msk                (0x7FFFUL << RTC_ALRMASSR_SS_Pos)  /*!< 0x00007FFF */
#define RTC_ALRMASSR_SS                    RTC_ALRMASSR_SS_Msk            /*!< </spirit:description> */
#define RTC_ALRMASSR_MAKSS_Pos             (24U)
#define RTC_ALRMASSR_MAKSS_Msk             (0xFUL << RTC_ALRMASSR_MAKSS_Pos)  /*!< 0x0F000000 */
#define RTC_ALRMASSR_MAKSS                 RTC_ALRMASSR_MAKSS_Msk         /*!< </spirit:description> */

/********************  Bit definition for RTC_SR register  ********************/
#define RTC_SR_ALRAF_Pos                   (0U)
#define RTC_SR_ALRAF_Msk                   (0x1UL << RTC_SR_ALRAF_Pos)      /*!< 0x00000001 */
#define RTC_SR_ALRAF                       RTC_SR_ALRAF_Msk               /*!< </spirit:description> */
#define RTC_SR_WUTF_Pos                    (2U)
#define RTC_SR_WUTF_Msk                    (0x1UL << RTC_SR_WUTF_Pos)       /*!< 0x00000004 */
#define RTC_SR_WUTF                        RTC_SR_WUTF_Msk                /*!< </spirit:description> */
#define RTC_SR_TSF_Pos                     (3U)
#define RTC_SR_TSF_Msk                     (0x1UL << RTC_SR_TSF_Pos)        /*!< 0x00000008 */
#define RTC_SR_TSF                         RTC_SR_TSF_Msk                 /*!< </spirit:description> */
#define RTC_SR_TSOVF_Pos                   (4U)
#define RTC_SR_TSOVF_Msk                   (0x1UL << RTC_SR_TSOVF_Pos)      /*!< 0x00000010 */
#define RTC_SR_TSOVF                       RTC_SR_TSOVF_Msk               /*!< </spirit:description> */
#define RTC_SR_ITSF_Pos                    (5U)
#define RTC_SR_ITSF_Msk                    (0x1UL << RTC_SR_ITSF_Pos)       /*!< 0x00000020 */
#define RTC_SR_ITSF                        RTC_SR_ITSF_Msk                /*!< </spirit:description> */

/*******************  Bit definition for RTC_MISR register  *******************/
#define RTC_MISR_ALRAMF_Pos                (0U)
#define RTC_MISR_ALRAMF_Msk                (0x1UL << RTC_MISR_ALRAMF_Pos)   /*!< 0x00000001 */
#define RTC_MISR_ALRAMF                    RTC_MISR_ALRAMF_Msk            /*!< </spirit:description> */
#define RTC_MISR_WUTMF_Pos                 (2U)
#define RTC_MISR_WUTMF_Msk                 (0x1UL << RTC_MISR_WUTMF_Pos)    /*!< 0x00000004 */
#define RTC_MISR_WUTMF                     RTC_MISR_WUTMF_Msk             /*!< </spirit:description> */
#define RTC_MISR_TSMF_Pos                  (3U)
#define RTC_MISR_TSMF_Msk                  (0x1UL << RTC_MISR_TSMF_Pos)     /*!< 0x00000008 */
#define RTC_MISR_TSMF                      RTC_MISR_TSMF_Msk              /*!< </spirit:description> */
#define RTC_MISR_TSOVMF_Pos                (4U)
#define RTC_MISR_TSOVMF_Msk                (0x1UL << RTC_MISR_TSOVMF_Pos)   /*!< 0x00000010 */
#define RTC_MISR_TSOVMF                    RTC_MISR_TSOVMF_Msk            /*!< </spirit:description> */
#define RTC_MISR_ITSMF_Pos                 (5U)
#define RTC_MISR_ITSMF_Msk                 (0x1UL << RTC_MISR_ITSMF_Pos)    /*!< 0x00000020 */
#define RTC_MISR_ITSMF                     RTC_MISR_ITSMF_Msk             /*!< </spirit:description> */

/*******************  Bit definition for RTC_SCR register  ********************/
#define RTC_SCR_CALRAF_Pos                 (0U)
#define RTC_SCR_CALRAF_Msk                 (0x1UL << RTC_SCR_CALRAF_Pos)    /*!< 0x00000001 */
#define RTC_SCR_CALRAF                     RTC_SCR_CALRAF_Msk             /*!< </spirit:description> */
#define RTC_SCR_CWUTF_Pos                  (2U)
#define RTC_SCR_CWUTF_Msk                  (0x1UL << RTC_SCR_CWUTF_Pos)     /*!< 0x00000004 */
#define RTC_SCR_CWUTF                      RTC_SCR_CWUTF_Msk              /*!< </spirit:description> */
#define RTC_SCR_CTSF_Pos                   (3U)
#define RTC_SCR_CTSF_Msk                   (0x1UL << RTC_SCR_CTSF_Pos)      /*!< 0x00000008 */
#define RTC_SCR_CTSF                       RTC_SCR_CTSF_Msk               /*!< </spirit:description> */
#define RTC_SCR_CTSOVF_Pos                 (4U)
#define RTC_SCR_CTSOVF_Msk                 (0x1UL << RTC_SCR_CTSOVF_Pos)    /*!< 0x00000010 */
#define RTC_SCR_CTSOVF                     RTC_SCR_CTSOVF_Msk             /*!< </spirit:description> */
#define RTC_SCR_CITSF_Pos                  (5U)
#define RTC_SCR_CITSF_Msk                  (0x1UL << RTC_SCR_CITSF_Pos)     /*!< 0x00000020 */
#define RTC_SCR_CITSF                      RTC_SCR_CITSF_Msk              /*!< </spirit:description> */

#define RTC_BASE           0x40002800UL 


#define RTC                ((RTC_TypeDef *) RTC_BASE) 


#endif /* __SR5E1_RTC_H */

