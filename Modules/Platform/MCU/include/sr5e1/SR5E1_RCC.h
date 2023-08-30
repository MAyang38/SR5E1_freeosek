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

#ifndef __SR5E1_RCC_H
#define __SR5E1_RCC_H
/*******************************************************************************
 * REVISION HISTORY                                                            *
 * REV       DATE       RM REV          DESCRIPTION OF CHANGE                  *
 * ------ ----------- ------------   ------------------------------------------*
 * 2.0A1  08-Jun-2022 Rev 2 Draft A     SR5E1_RDP_Rev2_A_08JUN22               *
 *                                    Replaced HSI in IRCOSC in all fields     *
 * ------ ----------- ------------   ------------------------------------------*
 * 1.1    30-Mar-2022 Rev 1 Draft C     SR5E1_RDP_Rev1_C_18MAR22               *
 *                                    Cancelled DMAMUX2 fields                 *
 ******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                                 RCC (RCC)                                  */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO uint32_t CR;                 /*!< CR                Address offset: 0x000 */
  __IO uint32_t ICSR;               /*!< ICSR              Address offset: 0x004 */
  __IO uint32_t CFGR;               /*!< CFGR              Address offset: 0x008 */
  __IO uint32_t PLLCFGR;            /*!< PLLCFGR           Address offset: 0x00C */
       uint32_t RESERVED0[2];       /*!< Reserved          Address offset: 0x010-0x014 */
  __IO uint32_t CIER;               /*!< CIER              Address offset: 0x018 */
  __IO uint32_t CIFR;               /*!< CIFR              Address offset: 0x01C */
  __IO uint32_t CICR;               /*!< CICR              Address offset: 0x020 */
  __IO uint32_t CCIPR1;             /*!< CCIPR1            Address offset: 0x024 */
  __IO uint32_t CCIPR2;             /*!< CCIPR2            Address offset: 0x028 */
  __IO uint32_t LSCFGR;             /*!< LSCFGR            Address offset: 0x02C */
  __IO uint32_t CRRCR;              /*!< CRRCR             Address offset: 0x030 */
       uint32_t RESERVED1[7];       /*!< Reserved          Address offset: 0x034-0x04C */
  __IO uint32_t AHB1LRSTR;          /*!< AHB1LRSTR         Address offset: 0x050 */
  __IO uint32_t AHB1HRSTR;          /*!< AHB1HRSTR         Address offset: 0x054 */
  __IO uint32_t AHB2LRSTR;          /*!< AHB2LRSTR         Address offset: 0x058 */
  __IO uint32_t AHB2HRSTR;          /*!< AHB2HRSTR         Address offset: 0x05C */
  __IO uint32_t APB1LRSTR;          /*!< APB1LRSTR         Address offset: 0x060 */
       uint32_t RESERVED2;          /*!< Reserved          Address offset: 0x064 */
  __IO uint32_t APB2LRSTR;          /*!< APB2LRSTR         Address offset: 0x068 */
  __IO uint32_t APB2HRSTR;          /*!< APB2HRSTR         Address offset: 0x06C */
  __IO uint32_t AHB1LENR;           /*!< AHB1LENR          Address offset: 0x070 */
  __IO uint32_t AHB1HENR;           /*!< AHB1HENR          Address offset: 0x074 */
  __IO uint32_t AHB2LENR;           /*!< AHB2LENR          Address offset: 0x078 */
  __IO uint32_t AHB2HENR;           /*!< AHB2HENR          Address offset: 0x07C */
  __IO uint32_t APB1LENR;           /*!< APB1LENR          Address offset: 0x080 */
       uint32_t RESERVED3;          /*!< Reserved          Address offset: 0x084 */
  __IO uint32_t APB2LENR;           /*!< APB2LENR          Address offset: 0x088 */
  __IO uint32_t APB2HENR;           /*!< APB2HENR          Address offset: 0x08C */
  __IO uint32_t C1_AHB1LSMENR;      /*!< C1_AHB1LSMENR     Address offset: 0x090 */
  __IO uint32_t C1_AHB1HSMENR;      /*!< C1_AHB1HSMENR     Address offset: 0x094 */
  __IO uint32_t C1_AHB2LSMENR;      /*!< C1_AHB2LSMENR     Address offset: 0x098 */
  __IO uint32_t C1_AHB2HSMENR;      /*!< C1_AHB2HSMENR     Address offset: 0x09C */
  __IO uint32_t C1_APB1LSMENR;      /*!< C1_APB1LSMENR     Address offset: 0x0A0 */
       uint32_t RESERVED4;          /*!< Reserved          Address offset: 0x0A4 */
  __IO uint32_t C1_APB2LSMENR;      /*!< C1_APB2LSMENR     Address offset: 0x0A8 */
  __IO uint32_t C1_APB2HSMENR;      /*!< C1_APB2HSMENR     Address offset: 0x0AC */
  __IO uint32_t C2_AHB1LSMENR;      /*!< C2_AHB1LSMENR     Address offset: 0x0B0 */
  __IO uint32_t C2_AHB1HSMENR;      /*!< C2_AHB1HSMENR     Address offset: 0x0B4 */
  __IO uint32_t C2_AHB2LSMENR;      /*!< C2_AHB2LSMENR     Address offset: 0x0B8 */
  __IO uint32_t C2_AHB2HSMENR;      /*!< C2_AHB2HSMENR     Address offset: 0x0BC */
  __IO uint32_t C2_APB1LSMENR;      /*!< C2_APB1LSMENR     Address offset: 0x0C0 */
       uint32_t RESERVED5;          /*!< Reserved          Address offset: 0x0C4 */
  __IO uint32_t C2_APB2LSMENR;      /*!< C2_APB2LSMENR     Address offset: 0x0C8 */
  __IO uint32_t C2_APB2HSMENR;      /*!< C2_APB2HSMENR     Address offset: 0x0CC */
  __IO uint32_t DBGCR;              /*!< DBGCR             Address offset: 0x0D0 */
  __IO uint32_t CMUR;               /*!< CMUR              Address offset: 0x0D4 */
  __IO uint32_t HSM_SW_CTRLR;       /*!< HSM_SW_CTRLR      Address offset: 0x0D8 */
       uint32_t RESERVED6[9];       /*!< Reserved          Address offset: 0x0DC-0x0FC */
  __IO uint32_t DSWRR;              /*!< DSWRR             Address offset: 0x100 */
  __IO uint32_t DRETR;              /*!< DRETR             Address offset: 0x104 */
  __IO uint32_t DESR;               /*!< DESR              Address offset: 0x108 */
  __IO uint32_t DORER;              /*!< DORER             Address offset: 0x10C */
       uint32_t RESERVED7[60];      /*!< Reserved          Address offset: 0x110-0x1FC */
  __IO uint32_t FSWRR;              /*!< FSWRR             Address offset: 0x200 */
  __IO uint32_t FRETR;              /*!< FRETR             Address offset: 0x204 */
  __IO uint32_t FESR;               /*!< FESR              Address offset: 0x208 */
  __IO uint32_t FORER;              /*!< FORER             Address offset: 0x20C */
  __IO uint32_t FERDR;              /*!< FERDR             Address offset: 0x210 */
  __IO uint32_t FESSR;              /*!< FESSR             Address offset: 0x214 */
       uint32_t RESERVED8[58];      /*!< Reserved          Address offset: 0x218-0x2FC */
  __IO uint32_t SYS_CFG_REG;        /*!< SYS_CFG_REG       Address offset: 0x300 */
  __IO uint32_t C1_VTOR_INIT_REG;   /*!< C1_VTOR_INIT_REG  Address offset: 0x304 */
  __IO uint32_t C2_VTOR_INIT_REG;   /*!< C2_VTOR_INIT_REG  Address offset: 0x308 */
  __IO uint32_t C1_APPLI_ADDR_REG;  /*!< C1_APPLI_ADDR_REG Address offset: 0x30C */
  __IO uint32_t C1_BOOT_CTRL_REG;   /*!< C1_BOOT_CTRL_REG  Address offset: 0x310 */
  __IO uint32_t C2_BOOT_CTRL_REG;   /*!< C2_BOOT_CTRL_REG  Address offset: 0x314 */
  __IO uint32_t C_SLEEP_STS_REG;    /*!< C_SLEEP_STS_REG   Address offset: 0x318 */
       uint32_t RESERVED9[25];      /*!< Reserved          Address offset: 0x31C-0x37C */
  __IO uint32_t PCS_CTRL_REG;       /*!< PCS_CTRL_REG      Address offset: 0x380 */
  __IO uint32_t PCS_SUDR_REG;       /*!< PCS_SUDR_REG      Address offset: 0x384 */
  __IO uint32_t PCS_DIVC_XOSC_REG;  /*!< PCS_DIVC_XOSC_REG Address offset: 0x388 */
  __IO uint32_t PCS_DIVE_XOSC_REG;  /*!< PCS_DIVE_XOSC_REG Address offset: 0x38C */
  __IO uint32_t PCS_DIVS_XOSC_REG;  /*!< PCS_DIVS_XOSC_REG Address offset: 0x390 */
  __IO uint32_t PCS_DIVC_PLL0_REG;  /*!< PCS_DIVC_PLL0_REG Address offset: 0x394 */
  __IO uint32_t PCS_DIVE_PLL0_REG;  /*!< PCS_DIVE_PLL0_REG Address offset: 0x398 */
  __IO uint32_t PCS_DIVS_PPL0_REG;  /*!< PCS_DIVS_PPL0_REG Address offset: 0x39C */
  __IO uint32_t PCS_DIVC_PLL1_REG;  /*!< PCS_DIVC_PLL1_REG Address offset: 0x3A0 */
  __IO uint32_t PCS_DIVE_PLL1_REG;  /*!< PCS_DIVE_PLL1_REG Address offset: 0x3A4 */
  __IO uint32_t PCS_DIVS_PPL1_REG;  /*!< PCS_DIVS_PPL1_REG Address offset: 0x3A8 */
} RCC_TypeDef;



/********************  Bit definition for RCC_CR register  ********************/
#define RCC_CR_LSION_Pos                                   (0U)
#define RCC_CR_LSION_Msk                                   (0x1UL << RCC_CR_LSION_Pos)                      /*!< 0x00000001 */
#define RCC_CR_LSION                                       RCC_CR_LSION_Msk                                 /*!< LSION */
#define RCC_CR_LSIRDY_Pos                                  (1U)
#define RCC_CR_LSIRDY_Msk                                  (0x1UL << RCC_CR_LSIRDY_Pos)                     /*!< 0x00000002 */
#define RCC_CR_LSIRDY                                      RCC_CR_LSIRDY_Msk                                /*!< LSIRDY */
#define RCC_CR_IRCOSCRDY_Pos                               (10U)
#define RCC_CR_IRCOSCRDY_Msk                               (0x1UL << RCC_CR_IRCOSCRDY_Pos)                  /*!< 0x00000400 */
#define RCC_CR_IRCOSCRDY                                   RCC_CR_IRCOSCRDY_Msk                             /*!< IRCOSCRDY */
#define RCC_CR_XOSCON_Pos                                  (16U)
#define RCC_CR_XOSCON_Msk                                  (0x1UL << RCC_CR_XOSCON_Pos)                     /*!< 0x00010000 */
#define RCC_CR_XOSCON                                      RCC_CR_XOSCON_Msk                                /*!< XOSCON */
#define RCC_CR_XOSCRDY_Pos                                 (17U)
#define RCC_CR_XOSCRDY_Msk                                 (0x1UL << RCC_CR_XOSCRDY_Pos)                    /*!< 0x00020000 */
#define RCC_CR_XOSCRDY                                     RCC_CR_XOSCRDY_Msk                               /*!< XOSCRDY */
#define RCC_CR_XOSCBYP_Pos                                 (18U)
#define RCC_CR_XOSCBYP_Msk                                 (0x1UL << RCC_CR_XOSCBYP_Pos)                    /*!< 0x00040000 */
#define RCC_CR_XOSCBYP                                     RCC_CR_XOSCBYP_Msk                               /*!< XOSCBYP */
#define RCC_CR_PLL0ON_Pos                                  (24U)
#define RCC_CR_PLL0ON_Msk                                  (0x1UL << RCC_CR_PLL0ON_Pos)                     /*!< 0x01000000 */
#define RCC_CR_PLL0ON                                      RCC_CR_PLL0ON_Msk                                /*!< PLL0ON */
#define RCC_CR_PLL0LOCK_Pos                                (25U)
#define RCC_CR_PLL0LOCK_Msk                                (0x1UL << RCC_CR_PLL0LOCK_Pos)                   /*!< 0x02000000 */
#define RCC_CR_PLL0LOCK                                    RCC_CR_PLL0LOCK_Msk                              /*!< PLL0LOCK */
#define RCC_CR_PLL1ON_Pos                                  (28U)
#define RCC_CR_PLL1ON_Msk                                  (0x1UL << RCC_CR_PLL1ON_Pos)                     /*!< 0x10000000 */
#define RCC_CR_PLL1ON                                      RCC_CR_PLL1ON_Msk                                /*!< PLL1ON */
#define RCC_CR_PLL1LOCK_Pos                                (29U)
#define RCC_CR_PLL1LOCK_Msk                                (0x1UL << RCC_CR_PLL1LOCK_Pos)                   /*!< 0x20000000 */
#define RCC_CR_PLL1LOCK                                    RCC_CR_PLL1LOCK_Msk                              /*!< PLL1LOCK */

/*******************  Bit definition for RCC_ICSR register  *******************/
#define RCC_ICSR_IRCOSC_FT_CODE_Pos                        (0U)
#define RCC_ICSR_IRCOSC_FT_CODE_Msk                        (0x3FUL << RCC_ICSR_IRCOSC_FT_CODE_Pos)          /*!< 0x0000003F */
#define RCC_ICSR_IRCOSC_FT_CODE                            RCC_ICSR_IRCOSC_FT_CODE_Msk                      /*!< IRCOSC_FT_CODE */
#define RCC_ICSR_IRCOSC_TRIM_Pos                           (16U)                                           
#define RCC_ICSR_IRCOSC_TRIM_Msk                           (0xFFUL << RCC_ICSR_IRCOSC_TRIM_Pos)             /*!< 0x00FF0000 */
#define RCC_ICSR_IRCOSC_TRIM                               RCC_ICSR_IRCOSC_TRIM_Msk                         /*!< IRCOSC_TRIM */
#define RCC_ICSR_IRCOSC_TRIM_USER_Pos                      (24U)                                           
#define RCC_ICSR_IRCOSC_TRIM_USER_Msk                      (0x3FUL << RCC_ICSR_IRCOSC_TRIM_USER_Pos)        /*!< 0x3F000000 */
#define RCC_ICSR_IRCOSC_TRIM_USER                          RCC_ICSR_IRCOSC_TRIM_USER_Msk                    /*!< IRCOSC_TRIM_USER */

/*******************  Bit definition for RCC_CFGR register  *******************/
#define RCC_CFGR_SW_Pos                                    (0U)
#define RCC_CFGR_SW_Msk                                    (0x7UL << RCC_CFGR_SW_Pos)                       /*!< 0x00000007 */
#define RCC_CFGR_SW                                        RCC_CFGR_SW_Msk                                  /*!< SW */
#define RCC_CFGR_SWS_Pos                                   (3U)
#define RCC_CFGR_SWS_Msk                                   (0x7UL << RCC_CFGR_SWS_Pos)                      /*!< 0x00000038 */
#define RCC_CFGR_SWS                                       RCC_CFGR_SWS_Msk                                 /*!< SWS */
#define RCC_CFGR_SYSPRE_Pos                                (8U)
#define RCC_CFGR_SYSPRE_Msk                                (0x1FFUL << RCC_CFGR_SYSPRE_Pos)                 /*!< 0x0001FF00 */
#define RCC_CFGR_SYSPRE                                    RCC_CFGR_SYSPRE_Msk                              /*!< SYSPRE */
#define RCC_CFGR_MCOSEL_Pos                                (20U)
#define RCC_CFGR_MCOSEL_Msk                                (0xFUL << RCC_CFGR_MCOSEL_Pos)                  /*!< 0x00F00000 */
#define RCC_CFGR_MCOSEL                                    RCC_CFGR_MCOSEL_Msk                             /*!< MCOSEL */
#define RCC_CFGR_MCOPRE_Pos                                (24U)
#define RCC_CFGR_MCOPRE_Msk                                (0x3FUL << RCC_CFGR_MCOPRE_Pos)                  /*!< 0x3F000000 */
#define RCC_CFGR_MCOPRE                                    RCC_CFGR_MCOPRE_Msk                              /*!< MCOPRE */

/*****************  Bit definition for RCC_PLLCFGR register  ******************/
#define RCC_PLLCFGR_PLL0SRC_Pos                            (0U)
#define RCC_PLLCFGR_PLL0SRC_Msk                            (0x3UL << RCC_PLLCFGR_PLL0SRC_Pos)               /*!< 0x00000003 */
#define RCC_PLLCFGR_PLL0SRC                                RCC_PLLCFGR_PLL0SRC_Msk                          /*!< PLL0SRC */
#define RCC_PLLCFGR_PLL0SRC_0                              (0x1UL << RCC_PLLCFGR_PLL0SRC_Pos)               /*!< 0x00000001 */
#define RCC_PLLCFGR_PLL0SRC_1                              (0x2UL << RCC_PLLCFGR_PLL0SRC_Pos)               /*!< 0x00000002 */
#define RCC_PLLCFGR_PLL1SRC_Pos                            (8U)
#define RCC_PLLCFGR_PLL1SRC_Msk                            (0x3UL << RCC_PLLCFGR_PLL1SRC_Pos)               /*!< 0x00000300 */
#define RCC_PLLCFGR_PLL1SRC                                RCC_PLLCFGR_PLL1SRC_Msk                          /*!< PLL1SRC */
#define RCC_PLLCFGR_PLL1SRC_0                              (0x1UL << RCC_PLLCFGR_PLL1SRC_Pos)               /*!< 0x00000100 */
#define RCC_PLLCFGR_PLL1SRC_1                              (0x2UL << RCC_PLLCFGR_PLL1SRC_Pos)               /*!< 0x00000200 */

/*******************  Bit definition for RCC_CIER register  *******************/
#define RCC_CIER_LSIRDY_IE_Pos                             (0U)
#define RCC_CIER_LSIRDY_IE_Msk                             (0x1UL << RCC_CIER_LSIRDY_IE_Pos)                /*!< 0x00000001 */
#define RCC_CIER_LSIRDY_IE                                 RCC_CIER_LSIRDY_IE_Msk                           /*!< LSIRDY_IE */
#define RCC_CIER_XOSCRDY_IE_Pos                            (4U)
#define RCC_CIER_XOSCRDY_IE_Msk                            (0x1UL << RCC_CIER_XOSCRDY_IE_Pos)               /*!< 0x00000010 */
#define RCC_CIER_XOSCRDY_IE                                RCC_CIER_XOSCRDY_IE_Msk                          /*!< XOSCRDY_IE */
#define RCC_CIER_PLL0LOCK_IE_Pos                           (5U)
#define RCC_CIER_PLL0LOCK_IE_Msk                           (0x1UL << RCC_CIER_PLL0LOCK_IE_Pos)              /*!< 0x00000020 */
#define RCC_CIER_PLL0LOCK_IE                               RCC_CIER_PLL0LOCK_IE_Msk                         /*!< PLL0LOCK_IE */
#define RCC_CIER_PLL1LOCK_IE_Pos                           (6U)
#define RCC_CIER_PLL1LOCK_IE_Msk                           (0x1UL << RCC_CIER_PLL1LOCK_IE_Pos)              /*!< 0x00000040 */
#define RCC_CIER_PLL1LOCK_IE                               RCC_CIER_PLL1LOCK_IE_Msk                         /*!< PLL1LOCK_IE */
#define RCC_CIER_SAFEMODE_FE_Pos                           (16U)
#define RCC_CIER_SAFEMODE_FE_Msk                           (0x1UL << RCC_CIER_SAFEMODE_FE_Pos)              /*!< 0x00010000 */
#define RCC_CIER_SAFEMODE_FE                               RCC_CIER_SAFEMODE_FE_Msk                         /*!< SAFEMODE_FE */

/*******************  Bit definition for RCC_CIFR register  *******************/
#define RCC_CIFR_LSIRDY_IF_Pos                             (0U)
#define RCC_CIFR_LSIRDY_IF_Msk                             (0x1UL << RCC_CIFR_LSIRDY_IF_Pos)                /*!< 0x00000001 */
#define RCC_CIFR_LSIRDY_IF                                 RCC_CIFR_LSIRDY_IF_Msk                           /*!< LSIRDY_IF */
#define RCC_CIFR_XOSCRDY_IF_Pos                            (4U)
#define RCC_CIFR_XOSCRDY_IF_Msk                            (0x1UL << RCC_CIFR_XOSCRDY_IF_Pos)               /*!< 0x00000010 */
#define RCC_CIFR_XOSCRDY_IF                                RCC_CIFR_XOSCRDY_IF_Msk                          /*!< XOSCRDY_IF */
#define RCC_CIFR_PLL0LOCK_IF_Pos                           (5U)
#define RCC_CIFR_PLL0LOCK_IF_Msk                           (0x1UL << RCC_CIFR_PLL0LOCK_IF_Pos)              /*!< 0x00000020 */
#define RCC_CIFR_PLL0LOCK_IF                               RCC_CIFR_PLL0LOCK_IF_Msk                         /*!< PLL0LOCK_IF */
#define RCC_CIFR_PLL1LOCK_IF_Pos                           (6U)
#define RCC_CIFR_PLL1LOCK_IF_Msk                           (0x1UL << RCC_CIFR_PLL1LOCK_IF_Pos)              /*!< 0x00000040 */
#define RCC_CIFR_PLL1LOCK_IF                               RCC_CIFR_PLL1LOCK_IF_Msk                         /*!< PLL1LOCK_IF */
#define RCC_CIFR_SAFEMODE_FF_Pos                           (16U)
#define RCC_CIFR_SAFEMODE_FF_Msk                           (0x1UL << RCC_CIFR_SAFEMODE_FF_Pos)              /*!< 0x00010000 */
#define RCC_CIFR_SAFEMODE_FF                               RCC_CIFR_SAFEMODE_FF_Msk                         /*!< SAFEMODE_FF */

/*******************  Bit definition for RCC_CICR register  *******************/
#define RCC_CICR_LSIRDY_IC_Pos                             (0U)
#define RCC_CICR_LSIRDY_IC_Msk                             (0x1UL << RCC_CICR_LSIRDY_IC_Pos)                /*!< 0x00000001 */
#define RCC_CICR_LSIRDY_IC                                 RCC_CICR_LSIRDY_IC_Msk                           /*!< LSIRDY_IC */
#define RCC_CICR_XOSCRDY_IC_Pos                            (4U)
#define RCC_CICR_XOSCRDY_IC_Msk                            (0x1UL << RCC_CICR_XOSCRDY_IC_Pos)               /*!< 0x00000010 */
#define RCC_CICR_XOSCRDY_IC                                RCC_CICR_XOSCRDY_IC_Msk                          /*!< XOSCRDY_IC */
#define RCC_CICR_PLL0LOCK_IC_Pos                           (5U)
#define RCC_CICR_PLL0LOCK_IC_Msk                           (0x1UL << RCC_CICR_PLL0LOCK_IC_Pos)              /*!< 0x00000020 */
#define RCC_CICR_PLL0LOCK_IC                               RCC_CICR_PLL0LOCK_IC_Msk                         /*!< PLL0LOCK_IC */
#define RCC_CICR_PLL1LOCK_IC_Pos                           (6U)
#define RCC_CICR_PLL1LOCK_IC_Msk                           (0x1UL << RCC_CICR_PLL1LOCK_IC_Pos)              /*!< 0x00000040 */
#define RCC_CICR_PLL1LOCK_IC                               RCC_CICR_PLL1LOCK_IC_Msk                         /*!< PLL1LOCK_IC */
#define RCC_CICR_SAFEMODE_FC_Pos                           (16U)
#define RCC_CICR_SAFEMODE_FC_Msk                           (0x1UL << RCC_CICR_SAFEMODE_FC_Pos)              /*!< 0x00010000 */
#define RCC_CICR_SAFEMODE_FC                               RCC_CICR_SAFEMODE_FC_Msk                         /*!< SAFEMODE_FC */

/******************  Bit definition for RCC_CCIPR1 register  ******************/
#define RCC_CCIPR1_UART_SEL_Pos                            (0U)
#define RCC_CCIPR1_UART_SEL_Msk                            (0x7UL << RCC_CCIPR1_UART_SEL_Pos)               /*!< 0x00000007 */
#define RCC_CCIPR1_UART_SEL                                RCC_CCIPR1_UART_SEL_Msk                          /*!< UART_SEL */
#define RCC_CCIPR1_UART_SEL_0                              (0x1UL << RCC_CCIPR1_UART_SEL_Pos)               /*!< 0x00000001 */
#define RCC_CCIPR1_UART_SEL_1                              (0x2UL << RCC_CCIPR1_UART_SEL_Pos)               /*!< 0x00000002 */
#define RCC_CCIPR1_UART_SEL_2                              (0x4UL << RCC_CCIPR1_UART_SEL_Pos)               /*!< 0x00000004 */
#define RCC_CCIPR1_I2C_SEL_Pos                             (4U)
#define RCC_CCIPR1_I2C_SEL_Msk                             (0x7UL << RCC_CCIPR1_I2C_SEL_Pos)                /*!< 0x00000070 */
#define RCC_CCIPR1_I2C_SEL                                 RCC_CCIPR1_I2C_SEL_Msk                           /*!< I2C_SEL */
#define RCC_CCIPR1_I2C_SEL_0                               (0x1UL << RCC_CCIPR1_I2C_SEL_Pos)                /*!< 0x00000010 */
#define RCC_CCIPR1_I2C_SEL_1                               (0x2UL << RCC_CCIPR1_I2C_SEL_Pos)                /*!< 0x00000020 */
#define RCC_CCIPR1_I2C_SEL_2                               (0x4UL << RCC_CCIPR1_I2C_SEL_Pos)                /*!< 0x00000040 */
#define RCC_CCIPR1_SPI_SEL_Pos                             (8U)
#define RCC_CCIPR1_SPI_SEL_Msk                             (0x7UL << RCC_CCIPR1_SPI_SEL_Pos)                /*!< 0x00000700 */
#define RCC_CCIPR1_SPI_SEL                                 RCC_CCIPR1_SPI_SEL_Msk                           /*!< SPI_SEL */
#define RCC_CCIPR1_SPI_SEL_0                               (0x1UL << RCC_CCIPR1_SPI_SEL_Pos)                /*!< 0x00000100 */
#define RCC_CCIPR1_SPI_SEL_1                               (0x2UL << RCC_CCIPR1_SPI_SEL_Pos)                /*!< 0x00000200 */
#define RCC_CCIPR1_SPI_SEL_2                               (0x4UL << RCC_CCIPR1_SPI_SEL_Pos)                /*!< 0x00000400 */
#define RCC_CCIPR1_FDCAN_SEL_Pos                           (12U)
#define RCC_CCIPR1_FDCAN_SEL_Msk                           (0x7UL << RCC_CCIPR1_FDCAN_SEL_Pos)              /*!< 0x00007000 */
#define RCC_CCIPR1_FDCAN_SEL                               RCC_CCIPR1_FDCAN_SEL_Msk                         /*!< FDCAN_SEL */
#define RCC_CCIPR1_FDCAN_SEL_0                             (0x1UL << RCC_CCIPR1_FDCAN_SEL_Pos)              /*!< 0x00001000 */
#define RCC_CCIPR1_FDCAN_SEL_1                             (0x2UL << RCC_CCIPR1_FDCAN_SEL_Pos)              /*!< 0x00002000 */
#define RCC_CCIPR1_FDCAN_SEL_2                             (0x4UL << RCC_CCIPR1_FDCAN_SEL_Pos)              /*!< 0x00004000 */
#define RCC_CCIPR1_ADC_SEL_Pos                             (16U)
#define RCC_CCIPR1_ADC_SEL_Msk                             (0x7UL << RCC_CCIPR1_ADC_SEL_Pos)                /*!< 0x00070000 */
#define RCC_CCIPR1_ADC_SEL                                 RCC_CCIPR1_ADC_SEL_Msk                           /*!< ADC_SEL */
#define RCC_CCIPR1_ADC_SEL_0                               (0x1UL << RCC_CCIPR1_ADC_SEL_Pos)                /*!< 0x00010000 */
#define RCC_CCIPR1_ADC_SEL_1                               (0x2UL << RCC_CCIPR1_ADC_SEL_Pos)                /*!< 0x00020000 */
#define RCC_CCIPR1_ADC_SEL_2                               (0x4UL << RCC_CCIPR1_ADC_SEL_Pos)                /*!< 0x00040000 */
#define RCC_CCIPR1_SD_ADC_SEL_Pos                          (20U)
#define RCC_CCIPR1_SD_ADC_SEL_Msk                          (0x7UL << RCC_CCIPR1_SD_ADC_SEL_Pos)             /*!< 0x00700000 */
#define RCC_CCIPR1_SD_ADC_SEL                              RCC_CCIPR1_SD_ADC_SEL_Msk                        /*!< SD_ADC_SEL */
#define RCC_CCIPR1_SD_ADC_SEL_0                           (0x1UL << RCC_CCIPR1_SD_ADC_SEL_Pos)              /*!< 0x00100000 */
#define RCC_CCIPR1_SD_ADC_SEL_1                           (0x2UL << RCC_CCIPR1_SD_ADC_SEL_Pos)              /*!< 0x00200000 */
#define RCC_CCIPR1_SD_ADC_SEL_2                           (0x4UL << RCC_CCIPR1_SD_ADC_SEL_Pos)              /*!< 0x00400000 */

/******************  Bit definition for RCC_CCIPR2 register  ******************/
#define RCC_CCIPR2_UART_PRE_Pos                            (0U)
#define RCC_CCIPR2_UART_PRE_Msk                            (0x1FUL << RCC_CCIPR2_UART_PRE_Pos)              /*!< 0x0000001F */
#define RCC_CCIPR2_UART_PRE                                RCC_CCIPR2_UART_PRE_Msk                          /*!< UART_PRE */
#define RCC_CCIPR2_I2C_PRE_Pos                             (5U)
#define RCC_CCIPR2_I2C_PRE_Msk                             (0x1FUL << RCC_CCIPR2_I2C_PRE_Pos)               /*!< 0x000003E0 */
#define RCC_CCIPR2_I2C_PRE                                 RCC_CCIPR2_I2C_PRE_Msk                           /*!< I2C_PRE */
#define RCC_CCIPR2_SPI_PRE_Pos                             (10U)
#define RCC_CCIPR2_SPI_PRE_Msk                             (0x1FUL << RCC_CCIPR2_SPI_PRE_Pos)               /*!< 0x00007C00 */
#define RCC_CCIPR2_SPI_PRE                                 RCC_CCIPR2_SPI_PRE_Msk                           /*!< SPI_PRE */
#define RCC_CCIPR2_FDCAN_PRE_Pos                           (15U)
#define RCC_CCIPR2_FDCAN_PRE_Msk                           (0x1FUL << RCC_CCIPR2_FDCAN_PRE_Pos)             /*!< 0x000F8000 */
#define RCC_CCIPR2_FDCAN_PRE                               RCC_CCIPR2_FDCAN_PRE_Msk                         /*!< FDCAN_PRE */
#define RCC_CCIPR2_ADC_PRE_Pos                             (20U)
#define RCC_CCIPR2_ADC_PRE_Msk                             (0x3FUL << RCC_CCIPR2_ADC_PRE_Pos)               /*!< 0x03F00000 */
#define RCC_CCIPR2_ADC_PRE                                 RCC_CCIPR2_ADC_PRE_Msk                           /*!< ADC_PRE */
#define RCC_CCIPR2_SD_ADC_PRE_Pos                          (26U)
#define RCC_CCIPR2_SD_ADC_PRE_Msk                          (0x3FUL << RCC_CCIPR2_SD_ADC_PRE_Pos)            /*!< 0xFC000000 */
#define RCC_CCIPR2_SD_ADC_PRE                              RCC_CCIPR2_SD_ADC_PRE_Msk                        /*!< SD_ADC_PRE */

/******************  Bit definition for RCC_LSCFGR register  ******************/
#define RCC_LSCFGR_LSIPRE_Pos                              (0U)
#define RCC_LSCFGR_LSIPRE_Msk                              (0x1FUL << RCC_LSCFGR_LSIPRE_Pos)                /*!< 0x0000001F */
#define RCC_LSCFGR_LSIPRE                                  RCC_LSCFGR_LSIPRE_Msk                            /*!< LSIPRE */
#define RCC_LSCFGR_RTCSTS_Pos                              (8U)
#define RCC_LSCFGR_RTCSTS_Msk                              (0x1UL << RCC_LSCFGR_RTCSTS_Pos)                 /*!< 0x00000100 */
#define RCC_LSCFGR_RTCSTS                                  RCC_LSCFGR_RTCSTS_Msk                            /*!< RTCSTS */
#define RCC_LSCFGR_RTCSEL_Pos                              (9U)
#define RCC_LSCFGR_RTCSEL_Msk                              (0x3UL << RCC_LSCFGR_RTCSEL_Pos)                 /*!< 0x00000600 */
#define RCC_LSCFGR_RTCSEL                                  RCC_LSCFGR_RTCSEL_Msk                            /*!< RTCSEL */
#define RCC_LSCFGR_RTCSEL_0                                (0x1UL << RCC_LSCFGR_RTCSEL_Pos)                 /*!< 0x00000200 */
#define RCC_LSCFGR_RTCSEL_1                                (0x2UL << RCC_LSCFGR_RTCSEL_Pos)                 /*!< 0x00000400 */
#define RCC_LSCFGR_LSCOEN_Pos                              (24U)
#define RCC_LSCFGR_LSCOEN_Msk                              (0x1UL << RCC_LSCFGR_LSCOEN_Pos)                 /*!< 0x01000000 */
#define RCC_LSCFGR_LSCOEN                                  RCC_LSCFGR_LSCOEN_Msk                            /*!< LSCOEN */
#define RCC_LSCFGR_LSCOSEL_Pos                             (25U)
#define RCC_LSCFGR_LSCOSEL_Msk                             (0x3UL << RCC_LSCFGR_LSCOSEL_Pos)                /*!< 0x06000000 */
#define RCC_LSCFGR_LSCOSEL                                 RCC_LSCFGR_LSCOSEL_Msk                           /*!< LSCOSEL */
#define RCC_LSCFGR_LSCOSEL_0                               (0x1UL << RCC_LSCFGR_LSCOSEL_Pos)                /*!< 0x02000000 */
#define RCC_LSCFGR_LSCOSEL_1                               (0x2UL << RCC_LSCFGR_LSCOSEL_Pos)                /*!< 0x04000000 */

/******************  Bit definition for RCC_CRRCR register  *******************/
#define RCC_CRRCR_XOSC_LOC_SAFE_EN_Pos                     (0U)
#define RCC_CRRCR_XOSC_LOC_SAFE_EN_Msk                     (0x1UL << RCC_CRRCR_XOSC_LOC_SAFE_EN_Pos)        /*!< 0x00000001 */
#define RCC_CRRCR_XOSC_LOC_SAFE_EN                         RCC_CRRCR_XOSC_LOC_SAFE_EN_Msk                   /*!< XOSC_LOC_SAFE_EN */
#define RCC_CRRCR_PLL0_LOL_SAFE_EN_Pos                     (8U)
#define RCC_CRRCR_PLL0_LOL_SAFE_EN_Msk                     (0x1UL << RCC_CRRCR_PLL0_LOL_SAFE_EN_Pos)        /*!< 0x00000100 */
#define RCC_CRRCR_PLL0_LOL_SAFE_EN                         RCC_CRRCR_PLL0_LOL_SAFE_EN_Msk                   /*!< PLL0_LOL_SAFE_EN */
#define RCC_CRRCR_PLL1_LOL_SAFE_EN_Pos                     (9U)
#define RCC_CRRCR_PLL1_LOL_SAFE_EN_Msk                     (0x1UL << RCC_CRRCR_PLL1_LOL_SAFE_EN_Pos)        /*!< 0x00000200 */
#define RCC_CRRCR_PLL1_LOL_SAFE_EN                         RCC_CRRCR_PLL1_LOL_SAFE_EN_Msk                   /*!< PLL1_LOL_SAFE_EN */
#define RCC_CRRCR_SYSCLK_LOL_SAFE_EN_Pos                   (16U)
#define RCC_CRRCR_SYSCLK_LOL_SAFE_EN_Msk                   (0x1UL << RCC_CRRCR_SYSCLK_LOL_SAFE_EN_Pos)      /*!< 0x00010000 */
#define RCC_CRRCR_SYSCLK_LOL_SAFE_EN                       RCC_CRRCR_SYSCLK_LOL_SAFE_EN_Msk                 /*!< SYSCLK_LOL_SAFE_EN */

/****************  Bit definition for RCC_AHB1LRSTR register  *****************/
#define RCC_AHB1LRSTR_HSEM_Pos                             (11U)
#define RCC_AHB1LRSTR_HSEM_Msk                             (0x1UL << RCC_AHB1LRSTR_HSEM_Pos)                /*!< 0x00000800 */
#define RCC_AHB1LRSTR_HSEM                                 RCC_AHB1LRSTR_HSEM_Msk                           /*!< HSEM */
#define RCC_AHB1LRSTR_CRC_Pos                              (12U)
#define RCC_AHB1LRSTR_CRC_Msk                              (0x1UL << RCC_AHB1LRSTR_CRC_Pos)                 /*!< 0x00001000 */
#define RCC_AHB1LRSTR_CRC                                  RCC_AHB1LRSTR_CRC_Msk                            /*!< CRC */
#define RCC_AHB1LRSTR_CORDIC_Pos                           (13U)
#define RCC_AHB1LRSTR_CORDIC_Msk                           (0x1UL << RCC_AHB1LRSTR_CORDIC_Pos)              /*!< 0x00002000 */
#define RCC_AHB1LRSTR_CORDIC                               RCC_AHB1LRSTR_CORDIC_Msk                         /*!< CORDIC */
#define RCC_AHB1LRSTR_DMA2_Pos                             (16U)
#define RCC_AHB1LRSTR_DMA2_Msk                             (0x1UL << RCC_AHB1LRSTR_DMA2_Pos)                /*!< 0x00010000 */
#define RCC_AHB1LRSTR_DMA2                                 RCC_AHB1LRSTR_DMA2_Msk                           /*!< DMA2 */

/****************  Bit definition for RCC_AHB1HRSTR register  *****************/
#define RCC_AHB1HRSTR_ADC3_ADC4_ADC5_Pos                   (0U)
#define RCC_AHB1HRSTR_ADC3_ADC4_ADC5_Msk                   (0x1UL << RCC_AHB1HRSTR_ADC3_ADC4_ADC5_Pos)      /*!< 0x00000001 */
#define RCC_AHB1HRSTR_ADC3_ADC4_ADC5                       RCC_AHB1HRSTR_ADC3_ADC4_ADC5_Msk                 /*!< ADC3_ADC4_ADC5 */
#define RCC_AHB1HRSTR_DAC3_Pos                             (5U)
#define RCC_AHB1HRSTR_DAC3_Msk                             (0x1UL << RCC_AHB1HRSTR_DAC3_Pos)                /*!< 0x00000020 */
#define RCC_AHB1HRSTR_DAC3                                 RCC_AHB1HRSTR_DAC3_Msk                           /*!< DAC3 */
#define RCC_AHB1HRSTR_DAC4_Pos                             (6U)
#define RCC_AHB1HRSTR_DAC4_Msk                             (0x1UL << RCC_AHB1HRSTR_DAC4_Pos)                /*!< 0x00000040 */
#define RCC_AHB1HRSTR_DAC4                                 RCC_AHB1HRSTR_DAC4_Msk                           /*!< DAC4 */
#define RCC_AHB1HRSTR_COMP2_DIG_Pos                        (12U)
#define RCC_AHB1HRSTR_COMP2_DIG_Msk                        (0x1UL << RCC_AHB1HRSTR_COMP2_DIG_Pos)           /*!< 0x00001000 */
#define RCC_AHB1HRSTR_COMP2_DIG                            RCC_AHB1HRSTR_COMP2_DIG_Msk                      /*!< COMP2_DIG */
#define RCC_AHB1HRSTR_HRTIMER1_Pos                         (28U)
#define RCC_AHB1HRSTR_HRTIMER1_Msk                         (0x1UL << RCC_AHB1HRSTR_HRTIMER1_Pos)            /*!< 0x10000000 */
#define RCC_AHB1HRSTR_HRTIMER1                             RCC_AHB1HRSTR_HRTIMER1_Msk                       /*!< HRTIMER1 */
#define RCC_AHB1HRSTR_HRTIMER2_Pos                         (29U)
#define RCC_AHB1HRSTR_HRTIMER2_Msk                         (0x1UL << RCC_AHB1HRSTR_HRTIMER2_Pos)            /*!< 0x20000000 */
#define RCC_AHB1HRSTR_HRTIMER2                             RCC_AHB1HRSTR_HRTIMER2_Msk                       /*!< HRTIMER2 */

/****************  Bit definition for RCC_AHB2LRSTR register  *****************/
#define RCC_AHB2LRSTR_GPIOA_Pos                            (0U)
#define RCC_AHB2LRSTR_GPIOA_Msk                            (0x1UL << RCC_AHB2LRSTR_GPIOA_Pos)               /*!< 0x00000001 */
#define RCC_AHB2LRSTR_GPIOA                                RCC_AHB2LRSTR_GPIOA_Msk                          /*!< GPIOA */
#define RCC_AHB2LRSTR_GPIOB_Pos                            (1U)
#define RCC_AHB2LRSTR_GPIOB_Msk                            (0x1UL << RCC_AHB2LRSTR_GPIOB_Pos)               /*!< 0x00000002 */
#define RCC_AHB2LRSTR_GPIOB                                RCC_AHB2LRSTR_GPIOB_Msk                          /*!< GPIOB */
#define RCC_AHB2LRSTR_GPIOC_Pos                            (2U)
#define RCC_AHB2LRSTR_GPIOC_Msk                            (0x1UL << RCC_AHB2LRSTR_GPIOC_Pos)               /*!< 0x00000004 */
#define RCC_AHB2LRSTR_GPIOC                                RCC_AHB2LRSTR_GPIOC_Msk                          /*!< GPIOC */
#define RCC_AHB2LRSTR_GPIOD_Pos                            (3U)
#define RCC_AHB2LRSTR_GPIOD_Msk                            (0x1UL << RCC_AHB2LRSTR_GPIOD_Pos)               /*!< 0x00000008 */
#define RCC_AHB2LRSTR_GPIOD                                RCC_AHB2LRSTR_GPIOD_Msk                          /*!< GPIOD */
#define RCC_AHB2LRSTR_GPIOE_Pos                            (4U)
#define RCC_AHB2LRSTR_GPIOE_Msk                            (0x1UL << RCC_AHB2LRSTR_GPIOE_Pos)               /*!< 0x00000010 */
#define RCC_AHB2LRSTR_GPIOE                                RCC_AHB2LRSTR_GPIOE_Msk                          /*!< GPIOE */
#define RCC_AHB2LRSTR_GPIOF_Pos                            (5U)
#define RCC_AHB2LRSTR_GPIOF_Msk                            (0x1UL << RCC_AHB2LRSTR_GPIOF_Pos)               /*!< 0x00000020 */
#define RCC_AHB2LRSTR_GPIOF                                RCC_AHB2LRSTR_GPIOF_Msk                          /*!< GPIOF */
#define RCC_AHB2LRSTR_GPIOG_Pos                            (6U)
#define RCC_AHB2LRSTR_GPIOG_Msk                            (0x1UL << RCC_AHB2LRSTR_GPIOG_Pos)               /*!< 0x00000040 */
#define RCC_AHB2LRSTR_GPIOG                                RCC_AHB2LRSTR_GPIOG_Msk                          /*!< GPIOG */
#define RCC_AHB2LRSTR_GPIOH_Pos                            (7U)
#define RCC_AHB2LRSTR_GPIOH_Msk                            (0x1UL << RCC_AHB2LRSTR_GPIOH_Pos)               /*!< 0x00000080 */
#define RCC_AHB2LRSTR_GPIOH                                RCC_AHB2LRSTR_GPIOH_Msk                          /*!< GPIOH */
#define RCC_AHB2LRSTR_GPIOI_Pos                            (8U)
#define RCC_AHB2LRSTR_GPIOI_Msk                            (0x1UL << RCC_AHB2LRSTR_GPIOI_Pos)               /*!< 0x00000100 */
#define RCC_AHB2LRSTR_GPIOI                                RCC_AHB2LRSTR_GPIOI_Msk                          /*!< GPIOI */
#define RCC_AHB2LRSTR_DMA1_Pos                             (16U)
#define RCC_AHB2LRSTR_DMA1_Msk                             (0x1UL << RCC_AHB2LRSTR_DMA1_Pos)                /*!< 0x00010000 */
#define RCC_AHB2LRSTR_DMA1                                 RCC_AHB2LRSTR_DMA1_Msk                           /*!< DMA1 */
#define RCC_AHB2LRSTR_DMAMUX1_Pos                          (17U)
#define RCC_AHB2LRSTR_DMAMUX1_Msk                          (0x1UL << RCC_AHB2LRSTR_DMAMUX1_Pos)             /*!< 0x00020000 */
#define RCC_AHB2LRSTR_DMAMUX1                              RCC_AHB2LRSTR_DMAMUX1_Msk                        /*!< DMAMUX1 */

/****************  Bit definition for RCC_AHB2HRSTR register  *****************/
#define RCC_AHB2HRSTR_ADC1_ADC2_Pos                        (0U)
#define RCC_AHB2HRSTR_ADC1_ADC2_Msk                        (0x1UL << RCC_AHB2HRSTR_ADC1_ADC2_Pos)           /*!< 0x00000001 */
#define RCC_AHB2HRSTR_ADC1_ADC2                            RCC_AHB2HRSTR_ADC1_ADC2_Msk                      /*!< ADC1_ADC2 */
#define RCC_AHB2HRSTR_BDAC1_Pos                            (4U)
#define RCC_AHB2HRSTR_BDAC1_Msk                            (0x1UL << RCC_AHB2HRSTR_BDAC1_Pos)               /*!< 0x00000010 */
#define RCC_AHB2HRSTR_BDAC1                                RCC_AHB2HRSTR_BDAC1_Msk                          /*!< BDAC1 */
#define RCC_AHB2HRSTR_DAC1_Pos                             (5U)
#define RCC_AHB2HRSTR_DAC1_Msk                             (0x1UL << RCC_AHB2HRSTR_DAC1_Pos)                /*!< 0x00000020 */
#define RCC_AHB2HRSTR_DAC1                                 RCC_AHB2HRSTR_DAC1_Msk                           /*!< DAC1 */
#define RCC_AHB2HRSTR_DAC2_Pos                             (6U)
#define RCC_AHB2HRSTR_DAC2_Msk                             (0x1UL << RCC_AHB2HRSTR_DAC2_Pos)                /*!< 0x00000040 */
#define RCC_AHB2HRSTR_DAC2                                 RCC_AHB2HRSTR_DAC2_Msk                           /*!< DAC2 */
#define RCC_AHB2HRSTR_COMP1_DIG_Pos                        (12U)
#define RCC_AHB2HRSTR_COMP1_DIG_Msk                        (0x1UL << RCC_AHB2HRSTR_COMP1_DIG_Pos)           /*!< 0x00001000 */
#define RCC_AHB2HRSTR_COMP1_DIG                            RCC_AHB2HRSTR_COMP1_DIG_Msk                      /*!< COMP1_DIG */

/****************  Bit definition for RCC_APB1LRSTR register  *****************/
#define RCC_APB1LRSTR_WWDG1_Pos                            (0U)
#define RCC_APB1LRSTR_WWDG1_Msk                            (0x1UL << RCC_APB1LRSTR_WWDG1_Pos)               /*!< 0x00000001 */
#define RCC_APB1LRSTR_WWDG1                                RCC_APB1LRSTR_WWDG1_Msk                          /*!< WWDG1 */
#define RCC_APB1LRSTR_WWDG2_Pos                            (1U)
#define RCC_APB1LRSTR_WWDG2_Msk                            (0x1UL << RCC_APB1LRSTR_WWDG2_Pos)               /*!< 0x00000002 */
#define RCC_APB1LRSTR_WWDG2                                RCC_APB1LRSTR_WWDG2_Msk                          /*!< WWDG2 */
#define RCC_APB1LRSTR_IWDG1_Pos                            (4U)
#define RCC_APB1LRSTR_IWDG1_Msk                            (0x1UL << RCC_APB1LRSTR_IWDG1_Pos)               /*!< 0x00000010 */
#define RCC_APB1LRSTR_IWDG1                                RCC_APB1LRSTR_IWDG1_Msk                          /*!< IWDG1 */
#define RCC_APB1LRSTR_IWDG2_Pos                            (5U)
#define RCC_APB1LRSTR_IWDG2_Msk                            (0x1UL << RCC_APB1LRSTR_IWDG2_Pos)               /*!< 0x00000020 */
#define RCC_APB1LRSTR_IWDG2                                RCC_APB1LRSTR_IWDG2_Msk                          /*!< IWDG2 */
#define RCC_APB1LRSTR_RTC_Pos                              (10U)
#define RCC_APB1LRSTR_RTC_Msk                              (0x1UL << RCC_APB1LRSTR_RTC_Pos)                 /*!< 0x00000400 */
#define RCC_APB1LRSTR_RTC                                  RCC_APB1LRSTR_RTC_Msk                            /*!< RTC */
#define RCC_APB1LRSTR_TIM2_Pos                             (15U)
#define RCC_APB1LRSTR_TIM2_Msk                             (0x1UL << RCC_APB1LRSTR_TIM2_Pos)                /*!< 0x00008000 */
#define RCC_APB1LRSTR_TIM2                                 RCC_APB1LRSTR_TIM2_Msk                           /*!< TIM2 */
#define RCC_APB1LRSTR_TIM3_Pos                             (16U)
#define RCC_APB1LRSTR_TIM3_Msk                             (0x1UL << RCC_APB1LRSTR_TIM3_Pos)                /*!< 0x00010000 */
#define RCC_APB1LRSTR_TIM3                                 RCC_APB1LRSTR_TIM3_Msk                           /*!< TIM3 */
#define RCC_APB1LRSTR_TIM6_Pos                             (17U)
#define RCC_APB1LRSTR_TIM6_Msk                             (0x1UL << RCC_APB1LRSTR_TIM6_Pos)                /*!< 0x00020000 */
#define RCC_APB1LRSTR_TIM6                                 RCC_APB1LRSTR_TIM6_Msk                           /*!< TIM6 */
#define RCC_APB1LRSTR_TIM7_Pos                             (18U)
#define RCC_APB1LRSTR_TIM7_Msk                             (0x1UL << RCC_APB1LRSTR_TIM7_Pos)                /*!< 0x00040000 */
#define RCC_APB1LRSTR_TIM7                                 RCC_APB1LRSTR_TIM7_Msk                           /*!< TIM7 */
#define RCC_APB1LRSTR_TIM_TS_Pos                           (19U)
#define RCC_APB1LRSTR_TIM_TS_Msk                           (0x1UL << RCC_APB1LRSTR_TIM_TS_Pos)              /*!< 0x00080000 */
#define RCC_APB1LRSTR_TIM_TS                               RCC_APB1LRSTR_TIM_TS_Msk                         /*!< TIM_TS */
#define RCC_APB1LRSTR_I2C1_Pos                             (21U)
#define RCC_APB1LRSTR_I2C1_Msk                             (0x1UL << RCC_APB1LRSTR_I2C1_Pos)                /*!< 0x00200000 */
#define RCC_APB1LRSTR_I2C1                                 RCC_APB1LRSTR_I2C1_Msk                           /*!< I2C1 */
#define RCC_APB1LRSTR_I2C2_Pos                             (22U)
#define RCC_APB1LRSTR_I2C2_Msk                             (0x1UL << RCC_APB1LRSTR_I2C2_Pos)                /*!< 0x00400000 */
#define RCC_APB1LRSTR_I2C2                                 RCC_APB1LRSTR_I2C2_Msk                           /*!< I2C2 */
#define RCC_APB1LRSTR_SPI2_Pos                             (23U)
#define RCC_APB1LRSTR_SPI2_Msk                             (0x1UL << RCC_APB1LRSTR_SPI2_Pos)                /*!< 0x00800000 */
#define RCC_APB1LRSTR_SPI2                                 RCC_APB1LRSTR_SPI2_Msk                           /*!< SPI2 */
#define RCC_APB1LRSTR_SPI3_Pos                             (24U)
#define RCC_APB1LRSTR_SPI3_Msk                             (0x1UL << RCC_APB1LRSTR_SPI3_Pos)                /*!< 0x01000000 */
#define RCC_APB1LRSTR_SPI3                                 RCC_APB1LRSTR_SPI3_Msk                           /*!< SPI3 */
#define RCC_APB1LRSTR_UART2_Pos                            (27U)
#define RCC_APB1LRSTR_UART2_Msk                            (0x1UL << RCC_APB1LRSTR_UART2_Pos)               /*!< 0x08000000 */
#define RCC_APB1LRSTR_UART2                                RCC_APB1LRSTR_UART2_Msk                          /*!< UART2 */
#define RCC_APB1LRSTR_UART3_Pos                            (28U)
#define RCC_APB1LRSTR_UART3_Msk                            (0x1UL << RCC_APB1LRSTR_UART3_Pos)               /*!< 0x10000000 */
#define RCC_APB1LRSTR_UART3                                RCC_APB1LRSTR_UART3_Msk                          /*!< UART3 */

/****************  Bit definition for RCC_APB2LRSTR register  *****************/
#define RCC_APB2LRSTR_SYSCFG_Pos                           (0U)
#define RCC_APB2LRSTR_SYSCFG_Msk                           (0x1UL << RCC_APB2LRSTR_SYSCFG_Pos)              /*!< 0x00000001 */
#define RCC_APB2LRSTR_SYSCFG                               RCC_APB2LRSTR_SYSCFG_Msk                         /*!< SYSCFG */
#define RCC_APB2LRSTR_SMPU_Pos                             (2U)
#define RCC_APB2LRSTR_SMPU_Msk                             (0x1UL << RCC_APB2LRSTR_SMPU_Pos)                /*!< 0x00000004 */
#define RCC_APB2LRSTR_SMPU                                 RCC_APB2LRSTR_SMPU_Msk                           /*!< SMPU */
#define RCC_APB2LRSTR_TIM1_PWM_Pos                         (11U)
#define RCC_APB2LRSTR_TIM1_PWM_Msk                         (0x1UL << RCC_APB2LRSTR_TIM1_PWM_Pos)            /*!< 0x00000800 */
#define RCC_APB2LRSTR_TIM1_PWM                             RCC_APB2LRSTR_TIM1_PWM_Msk                       /*!< TIM1_PWM */
#define RCC_APB2LRSTR_TIM8_PWM_Pos                         (12U)
#define RCC_APB2LRSTR_TIM8_PWM_Msk                         (0x1UL << RCC_APB2LRSTR_TIM8_PWM_Pos)            /*!< 0x00001000 */
#define RCC_APB2LRSTR_TIM8_PWM                             RCC_APB2LRSTR_TIM8_PWM_Msk                       /*!< TIM8_PWM */
#define RCC_APB2LRSTR_TIM4_Pos                             (15U)
#define RCC_APB2LRSTR_TIM4_Msk                             (0x1UL << RCC_APB2LRSTR_TIM4_Pos)                /*!< 0x00008000 */
#define RCC_APB2LRSTR_TIM4                                 RCC_APB2LRSTR_TIM4_Msk                           /*!< TIM4 */
#define RCC_APB2LRSTR_TIM5_Pos                             (16U)
#define RCC_APB2LRSTR_TIM5_Msk                             (0x1UL << RCC_APB2LRSTR_TIM5_Pos)                /*!< 0x00010000 */
#define RCC_APB2LRSTR_TIM5                                 RCC_APB2LRSTR_TIM5_Msk                           /*!< TIM5 */
#define RCC_APB2LRSTR_TIM15_Pos                            (17U)
#define RCC_APB2LRSTR_TIM15_Msk                            (0x1UL << RCC_APB2LRSTR_TIM15_Pos)               /*!< 0x00020000 */
#define RCC_APB2LRSTR_TIM15                                RCC_APB2LRSTR_TIM15_Msk                          /*!< TIM15 */
#define RCC_APB2LRSTR_TIM16_Pos                            (18U)
#define RCC_APB2LRSTR_TIM16_Msk                            (0x1UL << RCC_APB2LRSTR_TIM16_Pos)               /*!< 0x00040000 */
#define RCC_APB2LRSTR_TIM16                                RCC_APB2LRSTR_TIM16_Msk                          /*!< TIM16 */
#define RCC_APB2LRSTR_SPI1_Pos                             (23U)
#define RCC_APB2LRSTR_SPI1_Msk                             (0x1UL << RCC_APB2LRSTR_SPI1_Pos)                /*!< 0x00800000 */
#define RCC_APB2LRSTR_SPI1                                 RCC_APB2LRSTR_SPI1_Msk                           /*!< SPI1 */
#define RCC_APB2LRSTR_SPI4_Pos                             (24U)
#define RCC_APB2LRSTR_SPI4_Msk                             (0x1UL << RCC_APB2LRSTR_SPI4_Pos)                /*!< 0x01000000 */
#define RCC_APB2LRSTR_SPI4                                 RCC_APB2LRSTR_SPI4_Msk                           /*!< SPI4 */
#define RCC_APB2LRSTR_UART1_Pos                            (27U)
#define RCC_APB2LRSTR_UART1_Msk                            (0x1UL << RCC_APB2LRSTR_UART1_Pos)               /*!< 0x08000000 */
#define RCC_APB2LRSTR_UART1                                RCC_APB2LRSTR_UART1_Msk                          /*!< UART1 */

/****************  Bit definition for RCC_APB2HRSTR register  *****************/
#define RCC_APB2HRSTR_SD_ADC1_Pos                          (0U)
#define RCC_APB2HRSTR_SD_ADC1_Msk                          (0x1UL << RCC_APB2HRSTR_SD_ADC1_Pos)             /*!< 0x00000001 */
#define RCC_APB2HRSTR_SD_ADC1                              RCC_APB2HRSTR_SD_ADC1_Msk                        /*!< SD_ADC1 */
#define RCC_APB2HRSTR_SD_ADC2_Pos                          (1U)
#define RCC_APB2HRSTR_SD_ADC2_Msk                          (0x1UL << RCC_APB2HRSTR_SD_ADC2_Pos)             /*!< 0x00000002 */
#define RCC_APB2HRSTR_SD_ADC2                              RCC_APB2HRSTR_SD_ADC2_Msk                        /*!< SD_ADC2 */
#define RCC_APB2HRSTR_FDCAN1_Pos                           (8U)
#define RCC_APB2HRSTR_FDCAN1_Msk                           (0x1UL << RCC_APB2HRSTR_FDCAN1_Pos)              /*!< 0x00000100 */
#define RCC_APB2HRSTR_FDCAN1                               RCC_APB2HRSTR_FDCAN1_Msk                         /*!< FDCAN1 */
#define RCC_APB2HRSTR_FDCAN2_Pos                           (10U)
#define RCC_APB2HRSTR_FDCAN2_Msk                           (0x1UL << RCC_APB2HRSTR_FDCAN2_Pos)              /*!< 0x00000400 */
#define RCC_APB2HRSTR_FDCAN2                               RCC_APB2HRSTR_FDCAN2_Msk                         /*!< FDCAN2 */
#define RCC_APB2HRSTR_FDCAN3_Pos                           (12U)
#define RCC_APB2HRSTR_FDCAN3_Msk                           (0x1UL << RCC_APB2HRSTR_FDCAN3_Pos)              /*!< 0x00001000 */
#define RCC_APB2HRSTR_FDCAN3                               RCC_APB2HRSTR_FDCAN3_Msk                         /*!< FDCAN3 */
#define RCC_APB2HRSTR_FDCAN4_Pos                           (14U)
#define RCC_APB2HRSTR_FDCAN4_Msk                           (0x1UL << RCC_APB2HRSTR_FDCAN4_Pos)              /*!< 0x00004000 */
#define RCC_APB2HRSTR_FDCAN4                               RCC_APB2HRSTR_FDCAN4_Msk                         /*!< FDCAN4 */
#define RCC_APB2HRSTR_FDCAN_MRAM_Pos                       (16U)
#define RCC_APB2HRSTR_FDCAN_MRAM_Msk                       (0x1UL << RCC_APB2HRSTR_FDCAN_MRAM_Pos)          /*!< 0x00010000 */
#define RCC_APB2HRSTR_FDCAN_MRAM                           RCC_APB2HRSTR_FDCAN_MRAM_Msk                     /*!< FDCAN_MRAM */

/*****************  Bit definition for RCC_AHB1LENR register  *****************/
#define RCC_AHB1LENR_HSEM_Pos                              (11U)
#define RCC_AHB1LENR_HSEM_Msk                              (0x1UL << RCC_AHB1LENR_HSEM_Pos)                 /*!< 0x00000800 */
#define RCC_AHB1LENR_HSEM                                  RCC_AHB1LENR_HSEM_Msk                            /*!< HSEM */
#define RCC_AHB1LENR_CRC_Pos                               (12U)
#define RCC_AHB1LENR_CRC_Msk                               (0x1UL << RCC_AHB1LENR_CRC_Pos)                  /*!< 0x00001000 */
#define RCC_AHB1LENR_CRC                                   RCC_AHB1LENR_CRC_Msk                             /*!< CRC */
#define RCC_AHB1LENR_CORDIC_Pos                            (13U)
#define RCC_AHB1LENR_CORDIC_Msk                            (0x1UL << RCC_AHB1LENR_CORDIC_Pos)               /*!< 0x00002000 */
#define RCC_AHB1LENR_CORDIC                                RCC_AHB1LENR_CORDIC_Msk                          /*!< CORDIC */
#define RCC_AHB1LENR_DMA2_Pos                              (16U)
#define RCC_AHB1LENR_DMA2_Msk                              (0x1UL << RCC_AHB1LENR_DMA2_Pos)                 /*!< 0x00010000 */
#define RCC_AHB1LENR_DMA2                                  RCC_AHB1LENR_DMA2_Msk                            /*!< DMA2 */

/*****************  Bit definition for RCC_AHB1HENR register  *****************/
#define RCC_AHB1HENR_ADC3_ADC4_ADC5_Pos                    (0U)
#define RCC_AHB1HENR_ADC3_ADC4_ADC5_Msk                    (0x1UL << RCC_AHB1HENR_ADC3_ADC4_ADC5_Pos)       /*!< 0x00000001 */
#define RCC_AHB1HENR_ADC3_ADC4_ADC5                        RCC_AHB1HENR_ADC3_ADC4_ADC5_Msk                  /*!< ADC3_ADC4_ADC5 */
#define RCC_AHB1HENR_DAC3_Pos                              (5U)
#define RCC_AHB1HENR_DAC3_Msk                              (0x1UL << RCC_AHB1HENR_DAC3_Pos)                 /*!< 0x00000020 */
#define RCC_AHB1HENR_DAC3                                  RCC_AHB1HENR_DAC3_Msk                            /*!< DAC3 */
#define RCC_AHB1HENR_DAC4_Pos                              (6U)
#define RCC_AHB1HENR_DAC4_Msk                              (0x1UL << RCC_AHB1HENR_DAC4_Pos)                 /*!< 0x00000040 */
#define RCC_AHB1HENR_DAC4                                  RCC_AHB1HENR_DAC4_Msk                            /*!< DAC4 */
#define RCC_AHB1HENR_COMP2_DIG_Pos                         (12U)
#define RCC_AHB1HENR_COMP2_DIG_Msk                         (0x1UL << RCC_AHB1HENR_COMP2_DIG_Pos)            /*!< 0x00001000 */
#define RCC_AHB1HENR_COMP2_DIG                             RCC_AHB1HENR_COMP2_DIG_Msk                       /*!< COMP2_DIG */
#define RCC_AHB1HENR_HRTIMER1_Pos                          (28U)
#define RCC_AHB1HENR_HRTIMER1_Msk                          (0x1UL << RCC_AHB1HENR_HRTIMER1_Pos)             /*!< 0x10000000 */
#define RCC_AHB1HENR_HRTIMER1                              RCC_AHB1HENR_HRTIMER1_Msk                        /*!< HRTIMER1 */
#define RCC_AHB1HENR_HRTIMER2_Pos                          (29U)
#define RCC_AHB1HENR_HRTIMER2_Msk                          (0x1UL << RCC_AHB1HENR_HRTIMER2_Pos)             /*!< 0x20000000 */
#define RCC_AHB1HENR_HRTIMER2                              RCC_AHB1HENR_HRTIMER2_Msk                        /*!< HRTIMER2 */

/*****************  Bit definition for RCC_AHB2LENR register  *****************/
#define RCC_AHB2LENR_GPIOA_Pos                             (0U)
#define RCC_AHB2LENR_GPIOA_Msk                             (0x1UL << RCC_AHB2LENR_GPIOA_Pos)                /*!< 0x00000001 */
#define RCC_AHB2LENR_GPIOA                                 RCC_AHB2LENR_GPIOA_Msk                           /*!< GPIOA */
#define RCC_AHB2LENR_GPIOB_Pos                             (1U)
#define RCC_AHB2LENR_GPIOB_Msk                             (0x1UL << RCC_AHB2LENR_GPIOB_Pos)                /*!< 0x00000002 */
#define RCC_AHB2LENR_GPIOB                                 RCC_AHB2LENR_GPIOB_Msk                           /*!< GPIOB */
#define RCC_AHB2LENR_GPIOC_Pos                             (2U)
#define RCC_AHB2LENR_GPIOC_Msk                             (0x1UL << RCC_AHB2LENR_GPIOC_Pos)                /*!< 0x00000004 */
#define RCC_AHB2LENR_GPIOC                                 RCC_AHB2LENR_GPIOC_Msk                           /*!< GPIOC */
#define RCC_AHB2LENR_GPIOD_Pos                             (3U)
#define RCC_AHB2LENR_GPIOD_Msk                             (0x1UL << RCC_AHB2LENR_GPIOD_Pos)                /*!< 0x00000008 */
#define RCC_AHB2LENR_GPIOD                                 RCC_AHB2LENR_GPIOD_Msk                           /*!< GPIOD */
#define RCC_AHB2LENR_GPIOE_Pos                             (4U)
#define RCC_AHB2LENR_GPIOE_Msk                             (0x1UL << RCC_AHB2LENR_GPIOE_Pos)                /*!< 0x00000010 */
#define RCC_AHB2LENR_GPIOE                                 RCC_AHB2LENR_GPIOE_Msk                           /*!< GPIOE */
#define RCC_AHB2LENR_GPIOF_Pos                             (5U)
#define RCC_AHB2LENR_GPIOF_Msk                             (0x1UL << RCC_AHB2LENR_GPIOF_Pos)                /*!< 0x00000020 */
#define RCC_AHB2LENR_GPIOF                                 RCC_AHB2LENR_GPIOF_Msk                           /*!< GPIOF */
#define RCC_AHB2LENR_GPIOG_Pos                             (6U)
#define RCC_AHB2LENR_GPIOG_Msk                             (0x1UL << RCC_AHB2LENR_GPIOG_Pos)                /*!< 0x00000040 */
#define RCC_AHB2LENR_GPIOG                                 RCC_AHB2LENR_GPIOG_Msk                           /*!< GPIOG */
#define RCC_AHB2LENR_GPIOH_Pos                             (7U)
#define RCC_AHB2LENR_GPIOH_Msk                             (0x1UL << RCC_AHB2LENR_GPIOH_Pos)                /*!< 0x00000080 */
#define RCC_AHB2LENR_GPIOH                                 RCC_AHB2LENR_GPIOH_Msk                           /*!< GPIOH */
#define RCC_AHB2LENR_GPIOI_Pos                             (8U)
#define RCC_AHB2LENR_GPIOI_Msk                             (0x1UL << RCC_AHB2LENR_GPIOI_Pos)                /*!< 0x00000100 */
#define RCC_AHB2LENR_GPIOI                                 RCC_AHB2LENR_GPIOI_Msk                           /*!< GPIOI */
#define RCC_AHB2LENR_DMA1_Pos                              (16U)
#define RCC_AHB2LENR_DMA1_Msk                              (0x1UL << RCC_AHB2LENR_DMA1_Pos)                 /*!< 0x00010000 */
#define RCC_AHB2LENR_DMA1                                  RCC_AHB2LENR_DMA1_Msk                            /*!< DMA1 */
#define RCC_AHB2LENR_DMAMUX1_Pos                           (17U)
#define RCC_AHB2LENR_DMAMUX1_Msk                           (0x1UL << RCC_AHB2LENR_DMAMUX1_Pos)              /*!< 0x00020000 */
#define RCC_AHB2LENR_DMAMUX1                               RCC_AHB2LENR_DMAMUX1_Msk                         /*!< DMAMUX1 */

/*****************  Bit definition for RCC_AHB2HENR register  *****************/
#define RCC_AHB2HENR_ADC1_ADC2_Pos                         (0U)
#define RCC_AHB2HENR_ADC1_ADC2_Msk                         (0x1UL << RCC_AHB2HENR_ADC1_ADC2_Pos)            /*!< 0x00000001 */
#define RCC_AHB2HENR_ADC1_ADC2                             RCC_AHB2HENR_ADC1_ADC2_Msk                       /*!< ADC1_ADC2 */
#define RCC_AHB2HENR_BDAC1_Pos                             (4U)
#define RCC_AHB2HENR_BDAC1_Msk                             (0x1UL << RCC_AHB2HENR_BDAC1_Pos)                /*!< 0x00000010 */
#define RCC_AHB2HENR_BDAC1                                 RCC_AHB2HENR_BDAC1_Msk                           /*!< BDAC1 */
#define RCC_AHB2HENR_DAC1_Pos                              (5U)
#define RCC_AHB2HENR_DAC1_Msk                              (0x1UL << RCC_AHB2HENR_DAC1_Pos)                 /*!< 0x00000020 */
#define RCC_AHB2HENR_DAC1                                  RCC_AHB2HENR_DAC1_Msk                            /*!< DAC1 */
#define RCC_AHB2HENR_DAC2_Pos                              (6U)
#define RCC_AHB2HENR_DAC2_Msk                              (0x1UL << RCC_AHB2HENR_DAC2_Pos)                 /*!< 0x00000040 */
#define RCC_AHB2HENR_DAC2                                  RCC_AHB2HENR_DAC2_Msk                            /*!< DAC2 */
#define RCC_AHB2HENR_COMP1_DIG_Pos                         (12U)
#define RCC_AHB2HENR_COMP1_DIG_Msk                         (0x1UL << RCC_AHB2HENR_COMP1_DIG_Pos)            /*!< 0x00001000 */
#define RCC_AHB2HENR_COMP1_DIG                             RCC_AHB2HENR_COMP1_DIG_Msk                       /*!< COMP1_DIG */

/*****************  Bit definition for RCC_APB1LENR register  *****************/
#define RCC_APB1LENR_WWDG1_Pos                             (0U)
#define RCC_APB1LENR_WWDG1_Msk                             (0x1UL << RCC_APB1LENR_WWDG1_Pos)                /*!< 0x00000001 */
#define RCC_APB1LENR_WWDG1                                 RCC_APB1LENR_WWDG1_Msk                           /*!< WWDG1 */
#define RCC_APB1LENR_WWDG2_Pos                             (1U)
#define RCC_APB1LENR_WWDG2_Msk                             (0x1UL << RCC_APB1LENR_WWDG2_Pos)                /*!< 0x00000002 */
#define RCC_APB1LENR_WWDG2                                 RCC_APB1LENR_WWDG2_Msk                           /*!< WWDG2 */
#define RCC_APB1LENR_IWDG1_Pos                             (4U)
#define RCC_APB1LENR_IWDG1_Msk                             (0x1UL << RCC_APB1LENR_IWDG1_Pos)                /*!< 0x00000010 */
#define RCC_APB1LENR_IWDG1                                 RCC_APB1LENR_IWDG1_Msk                           /*!< IWDG1 */
#define RCC_APB1LENR_IWDG2_Pos                             (5U)
#define RCC_APB1LENR_IWDG2_Msk                             (0x1UL << RCC_APB1LENR_IWDG2_Pos)                /*!< 0x00000020 */
#define RCC_APB1LENR_IWDG2                                 RCC_APB1LENR_IWDG2_Msk                           /*!< IWDG2 */
#define RCC_APB1LENR_RTC_Pos                               (10U)
#define RCC_APB1LENR_RTC_Msk                               (0x1UL << RCC_APB1LENR_RTC_Pos)                  /*!< 0x00000400 */
#define RCC_APB1LENR_RTC                                   RCC_APB1LENR_RTC_Msk                             /*!< RTC */
#define RCC_APB1LENR_TIM2_Pos                              (15U)
#define RCC_APB1LENR_TIM2_Msk                              (0x1UL << RCC_APB1LENR_TIM2_Pos)                 /*!< 0x00008000 */
#define RCC_APB1LENR_TIM2                                  RCC_APB1LENR_TIM2_Msk                            /*!< TIM2 */
#define RCC_APB1LENR_TIM3_Pos                              (16U)
#define RCC_APB1LENR_TIM3_Msk                              (0x1UL << RCC_APB1LENR_TIM3_Pos)                 /*!< 0x00010000 */
#define RCC_APB1LENR_TIM3                                  RCC_APB1LENR_TIM3_Msk                            /*!< TIM3 */
#define RCC_APB1LENR_TIM6_Pos                              (17U)
#define RCC_APB1LENR_TIM6_Msk                              (0x1UL << RCC_APB1LENR_TIM6_Pos)                 /*!< 0x00020000 */
#define RCC_APB1LENR_TIM6                                  RCC_APB1LENR_TIM6_Msk                            /*!< TIM6 */
#define RCC_APB1LENR_TIM7_Pos                              (18U)
#define RCC_APB1LENR_TIM7_Msk                              (0x1UL << RCC_APB1LENR_TIM7_Pos)                 /*!< 0x00040000 */
#define RCC_APB1LENR_TIM7                                  RCC_APB1LENR_TIM7_Msk                            /*!< TIM7 */
#define RCC_APB1LENR_TIM_TS_Pos                            (19U)
#define RCC_APB1LENR_TIM_TS_Msk                            (0x1UL << RCC_APB1LENR_TIM_TS_Pos)               /*!< 0x00080000 */
#define RCC_APB1LENR_TIM_TS                                RCC_APB1LENR_TIM_TS_Msk                          /*!< TIM_TS */
#define RCC_APB1LENR_I2C1_Pos                              (21U)
#define RCC_APB1LENR_I2C1_Msk                              (0x1UL << RCC_APB1LENR_I2C1_Pos)                 /*!< 0x00200000 */
#define RCC_APB1LENR_I2C1                                  RCC_APB1LENR_I2C1_Msk                            /*!< I2C1 */
#define RCC_APB1LENR_I2C2_Pos                              (22U)
#define RCC_APB1LENR_I2C2_Msk                              (0x1UL << RCC_APB1LENR_I2C2_Pos)                 /*!< 0x00400000 */
#define RCC_APB1LENR_I2C2                                  RCC_APB1LENR_I2C2_Msk                            /*!< I2C2 */
#define RCC_APB1LENR_SPI2_Pos                              (23U)
#define RCC_APB1LENR_SPI2_Msk                              (0x1UL << RCC_APB1LENR_SPI2_Pos)                 /*!< 0x00800000 */
#define RCC_APB1LENR_SPI2                                  RCC_APB1LENR_SPI2_Msk                            /*!< SPI2 */
#define RCC_APB1LENR_SPI3_Pos                              (24U)
#define RCC_APB1LENR_SPI3_Msk                              (0x1UL << RCC_APB1LENR_SPI3_Pos)                 /*!< 0x01000000 */
#define RCC_APB1LENR_SPI3                                  RCC_APB1LENR_SPI3_Msk                            /*!< SPI3 */
#define RCC_APB1LENR_UART2_Pos                             (27U)
#define RCC_APB1LENR_UART2_Msk                             (0x1UL << RCC_APB1LENR_UART2_Pos)                /*!< 0x08000000 */
#define RCC_APB1LENR_UART2                                 RCC_APB1LENR_UART2_Msk                           /*!< UART2 */
#define RCC_APB1LENR_UART3_Pos                             (28U)
#define RCC_APB1LENR_UART3_Msk                             (0x1UL << RCC_APB1LENR_UART3_Pos)                /*!< 0x10000000 */
#define RCC_APB1LENR_UART3                                 RCC_APB1LENR_UART3_Msk                           /*!< UART3 */

/*****************  Bit definition for RCC_APB2LENR register  *****************/
#define RCC_APB2LENR_SYSCFG_Pos                            (0U)
#define RCC_APB2LENR_SYSCFG_Msk                            (0x1UL << RCC_APB2LENR_SYSCFG_Pos)               /*!< 0x00000001 */
#define RCC_APB2LENR_SYSCFG                                RCC_APB2LENR_SYSCFG_Msk                          /*!< SYSCFG */
#define RCC_APB2LENR_SMPU_Pos                              (2U)
#define RCC_APB2LENR_SMPU_Msk                              (0x1UL << RCC_APB2LENR_SMPU_Pos)                 /*!< 0x00000004 */
#define RCC_APB2LENR_SMPU                                  RCC_APB2LENR_SMPU_Msk                            /*!< SMPU */
#define RCC_APB2LENR_TIM1_PWM_Pos                          (11U)
#define RCC_APB2LENR_TIM1_PWM_Msk                          (0x1UL << RCC_APB2LENR_TIM1_PWM_Pos)             /*!< 0x00000800 */
#define RCC_APB2LENR_TIM1_PWM                              RCC_APB2LENR_TIM1_PWM_Msk                        /*!< TIM1_PWM */
#define RCC_APB2LENR_TIM8_PWM_Pos                          (12U)
#define RCC_APB2LENR_TIM8_PWM_Msk                          (0x1UL << RCC_APB2LENR_TIM8_PWM_Pos)             /*!< 0x00001000 */
#define RCC_APB2LENR_TIM8_PWM                              RCC_APB2LENR_TIM8_PWM_Msk                        /*!< TIM8_PWM */
#define RCC_APB2LENR_TIM4_Pos                              (15U)
#define RCC_APB2LENR_TIM4_Msk                              (0x1UL << RCC_APB2LENR_TIM4_Pos)                 /*!< 0x00008000 */
#define RCC_APB2LENR_TIM4                                  RCC_APB2LENR_TIM4_Msk                            /*!< TIM4 */
#define RCC_APB2LENR_TIM5_Pos                              (16U)
#define RCC_APB2LENR_TIM5_Msk                              (0x1UL << RCC_APB2LENR_TIM5_Pos)                 /*!< 0x00010000 */
#define RCC_APB2LENR_TIM5                                  RCC_APB2LENR_TIM5_Msk                            /*!< TIM5 */
#define RCC_APB2LENR_TIM15_Pos                             (17U)
#define RCC_APB2LENR_TIM15_Msk                             (0x1UL << RCC_APB2LENR_TIM15_Pos)                /*!< 0x00020000 */
#define RCC_APB2LENR_TIM15                                 RCC_APB2LENR_TIM15_Msk                           /*!< TIM15 */
#define RCC_APB2LENR_TIM16_Pos                             (18U)
#define RCC_APB2LENR_TIM16_Msk                             (0x1UL << RCC_APB2LENR_TIM16_Pos)                /*!< 0x00040000 */
#define RCC_APB2LENR_TIM16                                 RCC_APB2LENR_TIM16_Msk                           /*!< TIM16 */
#define RCC_APB2LENR_SPI1_Pos                              (23U)
#define RCC_APB2LENR_SPI1_Msk                              (0x1UL << RCC_APB2LENR_SPI1_Pos)                 /*!< 0x00800000 */
#define RCC_APB2LENR_SPI1                                  RCC_APB2LENR_SPI1_Msk                            /*!< SPI1 */
#define RCC_APB2LENR_SPI4_Pos                              (24U)
#define RCC_APB2LENR_SPI4_Msk                              (0x1UL << RCC_APB2LENR_SPI4_Pos)                 /*!< 0x01000000 */
#define RCC_APB2LENR_SPI4                                  RCC_APB2LENR_SPI4_Msk                            /*!< SPI4 */
#define RCC_APB2LENR_UART1_Pos                             (27U)
#define RCC_APB2LENR_UART1_Msk                             (0x1UL << RCC_APB2LENR_UART1_Pos)                /*!< 0x08000000 */
#define RCC_APB2LENR_UART1                                 RCC_APB2LENR_UART1_Msk                           /*!< UART1 */

/*****************  Bit definition for RCC_APB2HENR register  *****************/
#define RCC_APB2HENR_SD_ADC1_Pos                           (0U)
#define RCC_APB2HENR_SD_ADC1_Msk                           (0x1UL << RCC_APB2HENR_SD_ADC1_Pos)              /*!< 0x00000001 */
#define RCC_APB2HENR_SD_ADC1                               RCC_APB2HENR_SD_ADC1_Msk                         /*!< SD_ADC1 */
#define RCC_APB2HENR_SD_ADC2_Pos                           (1U)
#define RCC_APB2HENR_SD_ADC2_Msk                           (0x1UL << RCC_APB2HENR_SD_ADC2_Pos)              /*!< 0x00000002 */
#define RCC_APB2HENR_SD_ADC2                               RCC_APB2HENR_SD_ADC2_Msk                         /*!< SD_ADC2 */
#define RCC_APB2HENR_FDCAN1_Pos                            (8U)
#define RCC_APB2HENR_FDCAN1_Msk                            (0x1UL << RCC_APB2HENR_FDCAN1_Pos)               /*!< 0x00000100 */
#define RCC_APB2HENR_FDCAN1                                RCC_APB2HENR_FDCAN1_Msk                          /*!< FDCAN1 */
#define RCC_APB2HENR_FDCAN2_Pos                            (10U)
#define RCC_APB2HENR_FDCAN2_Msk                            (0x1UL << RCC_APB2HENR_FDCAN2_Pos)               /*!< 0x00000400 */
#define RCC_APB2HENR_FDCAN2                                RCC_APB2HENR_FDCAN2_Msk                          /*!< FDCAN2 */
#define RCC_APB2HENR_FDCAN3_Pos                            (12U)
#define RCC_APB2HENR_FDCAN3_Msk                            (0x1UL << RCC_APB2HENR_FDCAN3_Pos)               /*!< 0x00001000 */
#define RCC_APB2HENR_FDCAN3                                RCC_APB2HENR_FDCAN3_Msk                          /*!< FDCAN3 */
#define RCC_APB2HENR_FDCAN4_Pos                            (14U)
#define RCC_APB2HENR_FDCAN4_Msk                            (0x1UL << RCC_APB2HENR_FDCAN4_Pos)               /*!< 0x00004000 */
#define RCC_APB2HENR_FDCAN4                                RCC_APB2HENR_FDCAN4_Msk                          /*!< FDCAN4 */
#define RCC_APB2HENR_FDCAN_MRAM_Pos                        (16U)
#define RCC_APB2HENR_FDCAN_MRAM_Msk                        (0x1UL << RCC_APB2HENR_FDCAN_MRAM_Pos)           /*!< 0x00010000 */
#define RCC_APB2HENR_FDCAN_MRAM                            RCC_APB2HENR_FDCAN_MRAM_Msk                      /*!< FDCAN_MRAM */

/**************  Bit definition for RCC_C1_AHB1LSMENR register  ***************/
#define RCC_C1_AHB1LSMENR_HSEM_Pos                         (11U)
#define RCC_C1_AHB1LSMENR_HSEM_Msk                         (0x1UL << RCC_C1_AHB1LSMENR_HSEM_Pos)            /*!< 0x00000800 */
#define RCC_C1_AHB1LSMENR_HSEM                             RCC_C1_AHB1LSMENR_HSEM_Msk                       /*!< HSEM */
#define RCC_C1_AHB1LSMENR_CRC_Pos                          (12U)
#define RCC_C1_AHB1LSMENR_CRC_Msk                          (0x1UL << RCC_C1_AHB1LSMENR_CRC_Pos)             /*!< 0x00001000 */
#define RCC_C1_AHB1LSMENR_CRC                              RCC_C1_AHB1LSMENR_CRC_Msk                        /*!< CRC */
#define RCC_C1_AHB1LSMENR_CORDIC_Pos                       (13U)
#define RCC_C1_AHB1LSMENR_CORDIC_Msk                       (0x1UL << RCC_C1_AHB1LSMENR_CORDIC_Pos)          /*!< 0x00002000 */
#define RCC_C1_AHB1LSMENR_CORDIC                           RCC_C1_AHB1LSMENR_CORDIC_Msk                     /*!< CORDIC */
#define RCC_C1_AHB1LSMENR_DMA2_Pos                         (16U)
#define RCC_C1_AHB1LSMENR_DMA2_Msk                         (0x1UL << RCC_C1_AHB1LSMENR_DMA2_Pos)            /*!< 0x00010000 */
#define RCC_C1_AHB1LSMENR_DMA2                             RCC_C1_AHB1LSMENR_DMA2_Msk                       /*!< DMA2 */

/**************  Bit definition for RCC_C1_AHB1HSMENR register  ***************/
#define RCC_C1_AHB1HSMENR_ADC3_ADC4_ADC5_Pos               (0U)
#define RCC_C1_AHB1HSMENR_ADC3_ADC4_ADC5_Msk               (0x1UL << RCC_C1_AHB1HSMENR_ADC3_ADC4_ADC5_Pos)  /*!< 0x00000001 */
#define RCC_C1_AHB1HSMENR_ADC3_ADC4_ADC5                   RCC_C1_AHB1HSMENR_ADC3_ADC4_ADC5_Msk             /*!< ADC3_ADC4_ADC5 */
#define RCC_C1_AHB1HSMENR_DAC3_Pos                         (5U)
#define RCC_C1_AHB1HSMENR_DAC3_Msk                         (0x1UL << RCC_C1_AHB1HSMENR_DAC3_Pos)            /*!< 0x00000020 */
#define RCC_C1_AHB1HSMENR_DAC3                             RCC_C1_AHB1HSMENR_DAC3_Msk                       /*!< DAC3 */
#define RCC_C1_AHB1HSMENR_DAC4_Pos                         (6U)
#define RCC_C1_AHB1HSMENR_DAC4_Msk                         (0x1UL << RCC_C1_AHB1HSMENR_DAC4_Pos)            /*!< 0x00000040 */
#define RCC_C1_AHB1HSMENR_DAC4                             RCC_C1_AHB1HSMENR_DAC4_Msk                       /*!< DAC4 */
#define RCC_C1_AHB1HSMENR_COMP2_DIG_Pos                    (12U)
#define RCC_C1_AHB1HSMENR_COMP2_DIG_Msk                    (0x1UL << RCC_C1_AHB1HSMENR_COMP2_DIG_Pos)       /*!< 0x00001000 */
#define RCC_C1_AHB1HSMENR_COMP2_DIG                        RCC_C1_AHB1HSMENR_COMP2_DIG_Msk                  /*!< COMP2_DIG */
#define RCC_C1_AHB1HSMENR_HRTIMER1_Pos                     (28U)
#define RCC_C1_AHB1HSMENR_HRTIMER1_Msk                     (0x1UL << RCC_C1_AHB1HSMENR_HRTIMER1_Pos)        /*!< 0x10000000 */
#define RCC_C1_AHB1HSMENR_HRTIMER1                         RCC_C1_AHB1HSMENR_HRTIMER1_Msk                   /*!< HRTIMER1 */
#define RCC_C1_AHB1HSMENR_HRTIMER2_Pos                     (29U)
#define RCC_C1_AHB1HSMENR_HRTIMER2_Msk                     (0x1UL << RCC_C1_AHB1HSMENR_HRTIMER2_Pos)        /*!< 0x20000000 */
#define RCC_C1_AHB1HSMENR_HRTIMER2                         RCC_C1_AHB1HSMENR_HRTIMER2_Msk                   /*!< HRTIMER2 */

/**************  Bit definition for RCC_C1_AHB2LSMENR register  ***************/
#define RCC_C1_AHB2LSMENR_GPIOA_Pos                        (0U)
#define RCC_C1_AHB2LSMENR_GPIOA_Msk                        (0x1UL << RCC_C1_AHB2LSMENR_GPIOA_Pos)           /*!< 0x00000001 */
#define RCC_C1_AHB2LSMENR_GPIOA                            RCC_C1_AHB2LSMENR_GPIOA_Msk                      /*!< GPIOA */
#define RCC_C1_AHB2LSMENR_GPIOB_Pos                        (1U)
#define RCC_C1_AHB2LSMENR_GPIOB_Msk                        (0x1UL << RCC_C1_AHB2LSMENR_GPIOB_Pos)           /*!< 0x00000002 */
#define RCC_C1_AHB2LSMENR_GPIOB                            RCC_C1_AHB2LSMENR_GPIOB_Msk                      /*!< GPIOB */
#define RCC_C1_AHB2LSMENR_GPIOC_Pos                        (2U)
#define RCC_C1_AHB2LSMENR_GPIOC_Msk                        (0x1UL << RCC_C1_AHB2LSMENR_GPIOC_Pos)           /*!< 0x00000004 */
#define RCC_C1_AHB2LSMENR_GPIOC                            RCC_C1_AHB2LSMENR_GPIOC_Msk                      /*!< GPIOC */
#define RCC_C1_AHB2LSMENR_GPIOD_Pos                        (3U)
#define RCC_C1_AHB2LSMENR_GPIOD_Msk                        (0x1UL << RCC_C1_AHB2LSMENR_GPIOD_Pos)           /*!< 0x00000008 */
#define RCC_C1_AHB2LSMENR_GPIOD                            RCC_C1_AHB2LSMENR_GPIOD_Msk                      /*!< GPIOD */
#define RCC_C1_AHB2LSMENR_GPIOE_Pos                        (4U)
#define RCC_C1_AHB2LSMENR_GPIOE_Msk                        (0x1UL << RCC_C1_AHB2LSMENR_GPIOE_Pos)           /*!< 0x00000010 */
#define RCC_C1_AHB2LSMENR_GPIOE                            RCC_C1_AHB2LSMENR_GPIOE_Msk                      /*!< GPIOE */
#define RCC_C1_AHB2LSMENR_GPIOF_Pos                        (5U)
#define RCC_C1_AHB2LSMENR_GPIOF_Msk                        (0x1UL << RCC_C1_AHB2LSMENR_GPIOF_Pos)           /*!< 0x00000020 */
#define RCC_C1_AHB2LSMENR_GPIOF                            RCC_C1_AHB2LSMENR_GPIOF_Msk                      /*!< GPIOF */
#define RCC_C1_AHB2LSMENR_GPIOG_Pos                        (6U)
#define RCC_C1_AHB2LSMENR_GPIOG_Msk                        (0x1UL << RCC_C1_AHB2LSMENR_GPIOG_Pos)           /*!< 0x00000040 */
#define RCC_C1_AHB2LSMENR_GPIOG                            RCC_C1_AHB2LSMENR_GPIOG_Msk                      /*!< GPIOG */
#define RCC_C1_AHB2LSMENR_GPIOH_Pos                        (7U)
#define RCC_C1_AHB2LSMENR_GPIOH_Msk                        (0x1UL << RCC_C1_AHB2LSMENR_GPIOH_Pos)           /*!< 0x00000080 */
#define RCC_C1_AHB2LSMENR_GPIOH                            RCC_C1_AHB2LSMENR_GPIOH_Msk                      /*!< GPIOH */
#define RCC_C1_AHB2LSMENR_GPIOI_Pos                        (8U)
#define RCC_C1_AHB2LSMENR_GPIOI_Msk                        (0x1UL << RCC_C1_AHB2LSMENR_GPIOI_Pos)           /*!< 0x00000100 */
#define RCC_C1_AHB2LSMENR_GPIOI                            RCC_C1_AHB2LSMENR_GPIOI_Msk                      /*!< GPIOI */
#define RCC_C1_AHB2LSMENR_DMA1_Pos                         (16U)
#define RCC_C1_AHB2LSMENR_DMA1_Msk                         (0x1UL << RCC_C1_AHB2LSMENR_DMA1_Pos)            /*!< 0x00010000 */
#define RCC_C1_AHB2LSMENR_DMA1                             RCC_C1_AHB2LSMENR_DMA1_Msk                       /*!< DMA1 */
#define RCC_C1_AHB2LSMENR_DMAMUX1_Pos                      (17U)
#define RCC_C1_AHB2LSMENR_DMAMUX1_Msk                      (0x1UL << RCC_C1_AHB2LSMENR_DMAMUX1_Pos)         /*!< 0x00020000 */
#define RCC_C1_AHB2LSMENR_DMAMUX1                          RCC_C1_AHB2LSMENR_DMAMUX1_Msk                    /*!< DMAMUX1 */

/**************  Bit definition for RCC_C1_AHB2HSMENR register  ***************/
#define RCC_C1_AHB2HSMENR_ADC1_ADC2_Pos                    (0U)
#define RCC_C1_AHB2HSMENR_ADC1_ADC2_Msk                    (0x1UL << RCC_C1_AHB2HSMENR_ADC1_ADC2_Pos)       /*!< 0x00000001 */
#define RCC_C1_AHB2HSMENR_ADC1_ADC2                        RCC_C1_AHB2HSMENR_ADC1_ADC2_Msk                  /*!< ADC1_ADC2 */
#define RCC_C1_AHB2HSMENR_BDAC1_Pos                        (4U)
#define RCC_C1_AHB2HSMENR_BDAC1_Msk                        (0x1UL << RCC_C1_AHB2HSMENR_BDAC1_Pos)           /*!< 0x00000010 */
#define RCC_C1_AHB2HSMENR_BDAC1                            RCC_C1_AHB2HSMENR_BDAC1_Msk                      /*!< BDAC1 */
#define RCC_C1_AHB2HSMENR_DAC1_Pos                         (5U)
#define RCC_C1_AHB2HSMENR_DAC1_Msk                         (0x1UL << RCC_C1_AHB2HSMENR_DAC1_Pos)            /*!< 0x00000020 */
#define RCC_C1_AHB2HSMENR_DAC1                             RCC_C1_AHB2HSMENR_DAC1_Msk                       /*!< DAC1 */
#define RCC_C1_AHB2HSMENR_DAC2_Pos                         (6U)
#define RCC_C1_AHB2HSMENR_DAC2_Msk                         (0x1UL << RCC_C1_AHB2HSMENR_DAC2_Pos)            /*!< 0x00000040 */
#define RCC_C1_AHB2HSMENR_DAC2                             RCC_C1_AHB2HSMENR_DAC2_Msk                       /*!< DAC2 */
#define RCC_C1_AHB2HSMENR_COMP1_DIG_Pos                    (12U)
#define RCC_C1_AHB2HSMENR_COMP1_DIG_Msk                    (0x1UL << RCC_C1_AHB2HSMENR_COMP1_DIG_Pos)       /*!< 0x00001000 */
#define RCC_C1_AHB2HSMENR_COMP1_DIG                        RCC_C1_AHB2HSMENR_COMP1_DIG_Msk                  /*!< COMP1_DIG */

/**************  Bit definition for RCC_C1_APB1LSMENR register  ***************/
#define RCC_C1_APB1LSMENR_WWDG1_Pos                        (0U)
#define RCC_C1_APB1LSMENR_WWDG1_Msk                        (0x1UL << RCC_C1_APB1LSMENR_WWDG1_Pos)           /*!< 0x00000001 */
#define RCC_C1_APB1LSMENR_WWDG1                            RCC_C1_APB1LSMENR_WWDG1_Msk                      /*!< WWDG1 */
#define RCC_C1_APB1LSMENR_WWDG2_Pos                        (1U)
#define RCC_C1_APB1LSMENR_WWDG2_Msk                        (0x1UL << RCC_C1_APB1LSMENR_WWDG2_Pos)           /*!< 0x00000002 */
#define RCC_C1_APB1LSMENR_WWDG2                            RCC_C1_APB1LSMENR_WWDG2_Msk                      /*!< WWDG2 */
#define RCC_C1_APB1LSMENR_IWDG1_Pos                        (4U)
#define RCC_C1_APB1LSMENR_IWDG1_Msk                        (0x1UL << RCC_C1_APB1LSMENR_IWDG1_Pos)           /*!< 0x00000010 */
#define RCC_C1_APB1LSMENR_IWDG1                            RCC_C1_APB1LSMENR_IWDG1_Msk                      /*!< IWDG1 */
#define RCC_C1_APB1LSMENR_IWDG2_Pos                        (5U)
#define RCC_C1_APB1LSMENR_IWDG2_Msk                        (0x1UL << RCC_C1_APB1LSMENR_IWDG2_Pos)           /*!< 0x00000020 */
#define RCC_C1_APB1LSMENR_IWDG2                            RCC_C1_APB1LSMENR_IWDG2_Msk                      /*!< IWDG2 */
#define RCC_C1_APB1LSMENR_RTC_Pos                          (10U)
#define RCC_C1_APB1LSMENR_RTC_Msk                          (0x1UL << RCC_C1_APB1LSMENR_RTC_Pos)             /*!< 0x00000400 */
#define RCC_C1_APB1LSMENR_RTC                              RCC_C1_APB1LSMENR_RTC_Msk                        /*!< RTC */
#define RCC_C1_APB1LSMENR_TIM2_Pos                         (15U)
#define RCC_C1_APB1LSMENR_TIM2_Msk                         (0x1UL << RCC_C1_APB1LSMENR_TIM2_Pos)            /*!< 0x00008000 */
#define RCC_C1_APB1LSMENR_TIM2                             RCC_C1_APB1LSMENR_TIM2_Msk                       /*!< TIM2 */
#define RCC_C1_APB1LSMENR_TIM3_Pos                         (16U)
#define RCC_C1_APB1LSMENR_TIM3_Msk                         (0x1UL << RCC_C1_APB1LSMENR_TIM3_Pos)            /*!< 0x00010000 */
#define RCC_C1_APB1LSMENR_TIM3                             RCC_C1_APB1LSMENR_TIM3_Msk                       /*!< TIM3 */
#define RCC_C1_APB1LSMENR_TIM6_Pos                         (17U)
#define RCC_C1_APB1LSMENR_TIM6_Msk                         (0x1UL << RCC_C1_APB1LSMENR_TIM6_Pos)            /*!< 0x00020000 */
#define RCC_C1_APB1LSMENR_TIM6                             RCC_C1_APB1LSMENR_TIM6_Msk                       /*!< TIM6 */
#define RCC_C1_APB1LSMENR_TIM7_Pos                         (18U)
#define RCC_C1_APB1LSMENR_TIM7_Msk                         (0x1UL << RCC_C1_APB1LSMENR_TIM7_Pos)            /*!< 0x00040000 */
#define RCC_C1_APB1LSMENR_TIM7                             RCC_C1_APB1LSMENR_TIM7_Msk                       /*!< TIM7 */
#define RCC_C1_APB1LSMENR_TIM_TS_Pos                       (19U)
#define RCC_C1_APB1LSMENR_TIM_TS_Msk                       (0x1UL << RCC_C1_APB1LSMENR_TIM_TS_Pos)          /*!< 0x00080000 */
#define RCC_C1_APB1LSMENR_TIM_TS                           RCC_C1_APB1LSMENR_TIM_TS_Msk                     /*!< TIM_TS */
#define RCC_C1_APB1LSMENR_I2C1_Pos                         (21U)
#define RCC_C1_APB1LSMENR_I2C1_Msk                         (0x1UL << RCC_C1_APB1LSMENR_I2C1_Pos)            /*!< 0x00200000 */
#define RCC_C1_APB1LSMENR_I2C1                             RCC_C1_APB1LSMENR_I2C1_Msk                       /*!< I2C1 */
#define RCC_C1_APB1LSMENR_I2C2_Pos                         (22U)
#define RCC_C1_APB1LSMENR_I2C2_Msk                         (0x1UL << RCC_C1_APB1LSMENR_I2C2_Pos)            /*!< 0x00400000 */
#define RCC_C1_APB1LSMENR_I2C2                             RCC_C1_APB1LSMENR_I2C2_Msk                       /*!< I2C2 */
#define RCC_C1_APB1LSMENR_SPI2_Pos                         (23U)
#define RCC_C1_APB1LSMENR_SPI2_Msk                         (0x1UL << RCC_C1_APB1LSMENR_SPI2_Pos)            /*!< 0x00800000 */
#define RCC_C1_APB1LSMENR_SPI2                             RCC_C1_APB1LSMENR_SPI2_Msk                       /*!< SPI2 */
#define RCC_C1_APB1LSMENR_SPI3_Pos                         (24U)
#define RCC_C1_APB1LSMENR_SPI3_Msk                         (0x1UL << RCC_C1_APB1LSMENR_SPI3_Pos)            /*!< 0x01000000 */
#define RCC_C1_APB1LSMENR_SPI3                             RCC_C1_APB1LSMENR_SPI3_Msk                       /*!< SPI3 */
#define RCC_C1_APB1LSMENR_UART2_Pos                        (27U)
#define RCC_C1_APB1LSMENR_UART2_Msk                        (0x1UL << RCC_C1_APB1LSMENR_UART2_Pos)           /*!< 0x08000000 */
#define RCC_C1_APB1LSMENR_UART2                            RCC_C1_APB1LSMENR_UART2_Msk                      /*!< UART2 */
#define RCC_C1_APB1LSMENR_UART3_Pos                        (28U)
#define RCC_C1_APB1LSMENR_UART3_Msk                        (0x1UL << RCC_C1_APB1LSMENR_UART3_Pos)           /*!< 0x10000000 */
#define RCC_C1_APB1LSMENR_UART3                            RCC_C1_APB1LSMENR_UART3_Msk                      /*!< UART3 */

/**************  Bit definition for RCC_C1_APB2LSMENR register  ***************/
#define RCC_C1_APB2LSMENR_SYSCFG_Pos                       (0U)
#define RCC_C1_APB2LSMENR_SYSCFG_Msk                       (0x1UL << RCC_C1_APB2LSMENR_SYSCFG_Pos)          /*!< 0x00000001 */
#define RCC_C1_APB2LSMENR_SYSCFG                           RCC_C1_APB2LSMENR_SYSCFG_Msk                     /*!< SYSCFG */
#define RCC_C1_APB2LSMENR_SMPU_Pos                         (2U)
#define RCC_C1_APB2LSMENR_SMPU_Msk                         (0x1UL << RCC_C1_APB2LSMENR_SMPU_Pos)            /*!< 0x00000004 */
#define RCC_C1_APB2LSMENR_SMPU                             RCC_C1_APB2LSMENR_SMPU_Msk                       /*!< SMPU */
#define RCC_C1_APB2LSMENR_TIM1_PWM_Pos                     (11U)
#define RCC_C1_APB2LSMENR_TIM1_PWM_Msk                     (0x1UL << RCC_C1_APB2LSMENR_TIM1_PWM_Pos)        /*!< 0x00000800 */
#define RCC_C1_APB2LSMENR_TIM1_PWM                         RCC_C1_APB2LSMENR_TIM1_PWM_Msk                   /*!< TIM1_PWM */
#define RCC_C1_APB2LSMENR_TIM8_PWM_Pos                     (12U)
#define RCC_C1_APB2LSMENR_TIM8_PWM_Msk                     (0x1UL << RCC_C1_APB2LSMENR_TIM8_PWM_Pos)        /*!< 0x00001000 */
#define RCC_C1_APB2LSMENR_TIM8_PWM                         RCC_C1_APB2LSMENR_TIM8_PWM_Msk                   /*!< TIM8_PWM */
#define RCC_C1_APB2LSMENR_TIM4_Pos                         (15U)
#define RCC_C1_APB2LSMENR_TIM4_Msk                         (0x1UL << RCC_C1_APB2LSMENR_TIM4_Pos)            /*!< 0x00008000 */
#define RCC_C1_APB2LSMENR_TIM4                             RCC_C1_APB2LSMENR_TIM4_Msk                       /*!< TIM4 */
#define RCC_C1_APB2LSMENR_TIM5_Pos                         (16U)
#define RCC_C1_APB2LSMENR_TIM5_Msk                         (0x1UL << RCC_C1_APB2LSMENR_TIM5_Pos)            /*!< 0x00010000 */
#define RCC_C1_APB2LSMENR_TIM5                             RCC_C1_APB2LSMENR_TIM5_Msk                       /*!< TIM5 */
#define RCC_C1_APB2LSMENR_TIM15_Pos                        (17U)
#define RCC_C1_APB2LSMENR_TIM15_Msk                        (0x1UL << RCC_C1_APB2LSMENR_TIM15_Pos)           /*!< 0x00020000 */
#define RCC_C1_APB2LSMENR_TIM15                            RCC_C1_APB2LSMENR_TIM15_Msk                      /*!< TIM15 */
#define RCC_C1_APB2LSMENR_TIM16_Pos                        (18U)
#define RCC_C1_APB2LSMENR_TIM16_Msk                        (0x1UL << RCC_C1_APB2LSMENR_TIM16_Pos)           /*!< 0x00040000 */
#define RCC_C1_APB2LSMENR_TIM16                            RCC_C1_APB2LSMENR_TIM16_Msk                      /*!< TIM16 */
#define RCC_C1_APB2LSMENR_SPI1_Pos                         (23U)
#define RCC_C1_APB2LSMENR_SPI1_Msk                         (0x1UL << RCC_C1_APB2LSMENR_SPI1_Pos)            /*!< 0x00800000 */
#define RCC_C1_APB2LSMENR_SPI1                             RCC_C1_APB2LSMENR_SPI1_Msk                       /*!< SPI1 */
#define RCC_C1_APB2LSMENR_SPI4_Pos                         (24U)
#define RCC_C1_APB2LSMENR_SPI4_Msk                         (0x1UL << RCC_C1_APB2LSMENR_SPI4_Pos)            /*!< 0x01000000 */
#define RCC_C1_APB2LSMENR_SPI4                             RCC_C1_APB2LSMENR_SPI4_Msk                       /*!< SPI4 */
#define RCC_C1_APB2LSMENR_UART1_Pos                        (27U)
#define RCC_C1_APB2LSMENR_UART1_Msk                        (0x1UL << RCC_C1_APB2LSMENR_UART1_Pos)           /*!< 0x08000000 */
#define RCC_C1_APB2LSMENR_UART1                            RCC_C1_APB2LSMENR_UART1_Msk                      /*!< UART1 */

/**************  Bit definition for RCC_C1_APB2HSMENR register  ***************/
#define RCC_C1_APB2HSMENR_SD_ADC1_Pos                      (0U)
#define RCC_C1_APB2HSMENR_SD_ADC1_Msk                      (0x1UL << RCC_C1_APB2HSMENR_SD_ADC1_Pos)         /*!< 0x00000001 */
#define RCC_C1_APB2HSMENR_SD_ADC1                          RCC_C1_APB2HSMENR_SD_ADC1_Msk                    /*!< SD_ADC1 */
#define RCC_C1_APB2HSMENR_SD_ADC2_Pos                      (1U)
#define RCC_C1_APB2HSMENR_SD_ADC2_Msk                      (0x1UL << RCC_C1_APB2HSMENR_SD_ADC2_Pos)         /*!< 0x00000002 */
#define RCC_C1_APB2HSMENR_SD_ADC2                          RCC_C1_APB2HSMENR_SD_ADC2_Msk                    /*!< SD_ADC2 */
#define RCC_C1_APB2HSMENR_FDCAN1_Pos                       (8U)
#define RCC_C1_APB2HSMENR_FDCAN1_Msk                       (0x1UL << RCC_C1_APB2HSMENR_FDCAN1_Pos)          /*!< 0x00000100 */
#define RCC_C1_APB2HSMENR_FDCAN1                           RCC_C1_APB2HSMENR_FDCAN1_Msk                     /*!< FDCAN1 */
#define RCC_C1_APB2HSMENR_FDCAN2_Pos                       (10U)
#define RCC_C1_APB2HSMENR_FDCAN2_Msk                       (0x1UL << RCC_C1_APB2HSMENR_FDCAN2_Pos)          /*!< 0x00000400 */
#define RCC_C1_APB2HSMENR_FDCAN2                           RCC_C1_APB2HSMENR_FDCAN2_Msk                     /*!< FDCAN2 */
#define RCC_C1_APB2HSMENR_FDCAN3_Pos                       (12U)
#define RCC_C1_APB2HSMENR_FDCAN3_Msk                       (0x1UL << RCC_C1_APB2HSMENR_FDCAN3_Pos)          /*!< 0x00001000 */
#define RCC_C1_APB2HSMENR_FDCAN3                           RCC_C1_APB2HSMENR_FDCAN3_Msk                     /*!< FDCAN3 */
#define RCC_C1_APB2HSMENR_FDCAN4_Pos                       (14U)
#define RCC_C1_APB2HSMENR_FDCAN4_Msk                       (0x1UL << RCC_C1_APB2HSMENR_FDCAN4_Pos)          /*!< 0x00004000 */
#define RCC_C1_APB2HSMENR_FDCAN4                           RCC_C1_APB2HSMENR_FDCAN4_Msk                     /*!< FDCAN4 */
#define RCC_C1_APB2HSMENR_FDCAN_MRAM_Pos                   (16U)
#define RCC_C1_APB2HSMENR_FDCAN_MRAM_Msk                   (0x1UL << RCC_C1_APB2HSMENR_FDCAN_MRAM_Pos)      /*!< 0x00010000 */
#define RCC_C1_APB2HSMENR_FDCAN_MRAM                       RCC_C1_APB2HSMENR_FDCAN_MRAM_Msk                 /*!< FDCAN_MRAM */

/**************  Bit definition for RCC_C2_AHB1LSMENR register  ***************/
#define RCC_C2_AHB1LSMENR_XOSCM_Pos                        (11U)
#define RCC_C2_AHB1LSMENR_XOSCM_Msk                        (0x1UL << RCC_C2_AHB1LSMENR_XOSCM_Pos)           /*!< 0x00000800 */
#define RCC_C2_AHB1LSMENR_XOSCM                            RCC_C2_AHB1LSMENR_XOSCM_Msk                      /*!< XOSCM */
#define RCC_C2_AHB1LSMENR_CRC_Pos                          (12U)
#define RCC_C2_AHB1LSMENR_CRC_Msk                          (0x1UL << RCC_C2_AHB1LSMENR_CRC_Pos)             /*!< 0x00001000 */
#define RCC_C2_AHB1LSMENR_CRC                              RCC_C2_AHB1LSMENR_CRC_Msk                        /*!< CRC */
#define RCC_C2_AHB1LSMENR_CORDIC_Pos                       (13U)
#define RCC_C2_AHB1LSMENR_CORDIC_Msk                       (0x1UL << RCC_C2_AHB1LSMENR_CORDIC_Pos)          /*!< 0x00002000 */
#define RCC_C2_AHB1LSMENR_CORDIC                           RCC_C2_AHB1LSMENR_CORDIC_Msk                     /*!< CORDIC */
#define RCC_C2_AHB1LSMENR_DMA2_Pos                         (16U)
#define RCC_C2_AHB1LSMENR_DMA2_Msk                         (0x1UL << RCC_C2_AHB1LSMENR_DMA2_Pos)            /*!< 0x00010000 */
#define RCC_C2_AHB1LSMENR_DMA2                             RCC_C2_AHB1LSMENR_DMA2_Msk                       /*!< DMA2 */

/**************  Bit definition for RCC_C2_AHB1HSMENR register  ***************/
#define RCC_C2_AHB1HSMENR_ADC3_ADC4_ADC5_Pos               (0U)
#define RCC_C2_AHB1HSMENR_ADC3_ADC4_ADC5_Msk               (0x1UL << RCC_C2_AHB1HSMENR_ADC3_ADC4_ADC5_Pos)  /*!< 0x00000001 */
#define RCC_C2_AHB1HSMENR_ADC3_ADC4_ADC5                   RCC_C2_AHB1HSMENR_ADC3_ADC4_ADC5_Msk             /*!< ADC3_ADC4_ADC5 */
#define RCC_C2_AHB1HSMENR_DAC3_Pos                         (5U)
#define RCC_C2_AHB1HSMENR_DAC3_Msk                         (0x1UL << RCC_C2_AHB1HSMENR_DAC3_Pos)            /*!< 0x00000020 */
#define RCC_C2_AHB1HSMENR_DAC3                             RCC_C2_AHB1HSMENR_DAC3_Msk                       /*!< DAC3 */
#define RCC_C2_AHB1HSMENR_DAC4_Pos                         (6U)
#define RCC_C2_AHB1HSMENR_DAC4_Msk                         (0x1UL << RCC_C2_AHB1HSMENR_DAC4_Pos)            /*!< 0x00000040 */
#define RCC_C2_AHB1HSMENR_DAC4                             RCC_C2_AHB1HSMENR_DAC4_Msk                       /*!< DAC4 */
#define RCC_C2_AHB1HSMENR_COMP2_DIG_Pos                    (12U)
#define RCC_C2_AHB1HSMENR_COMP2_DIG_Msk                    (0x1UL << RCC_C2_AHB1HSMENR_COMP2_DIG_Pos)       /*!< 0x00001000 */
#define RCC_C2_AHB1HSMENR_COMP2_DIG                        RCC_C2_AHB1HSMENR_COMP2_DIG_Msk                  /*!< COMP2_DIG */
#define RCC_C2_AHB1HSMENR_HRTIMER1_Pos                     (28U)
#define RCC_C2_AHB1HSMENR_HRTIMER1_Msk                     (0x1UL << RCC_C2_AHB1HSMENR_HRTIMER1_Pos)        /*!< 0x10000000 */
#define RCC_C2_AHB1HSMENR_HRTIMER1                         RCC_C2_AHB1HSMENR_HRTIMER1_Msk                   /*!< HRTIMER1 */
#define RCC_C2_AHB1HSMENR_HRTIMER2_Pos                     (29U)
#define RCC_C2_AHB1HSMENR_HRTIMER2_Msk                     (0x1UL << RCC_C2_AHB1HSMENR_HRTIMER2_Pos)        /*!< 0x20000000 */
#define RCC_C2_AHB1HSMENR_HRTIMER2                         RCC_C2_AHB1HSMENR_HRTIMER2_Msk                   /*!< HRTIMER2 */

/**************  Bit definition for RCC_C2_AHB2LSMENR register  ***************/
#define RCC_C2_AHB2LSMENR_GPIOA_Pos                        (0U)
#define RCC_C2_AHB2LSMENR_GPIOA_Msk                        (0x1UL << RCC_C2_AHB2LSMENR_GPIOA_Pos)           /*!< 0x00000001 */
#define RCC_C2_AHB2LSMENR_GPIOA                            RCC_C2_AHB2LSMENR_GPIOA_Msk                      /*!< GPIOA */
#define RCC_C2_AHB2LSMENR_GPIOB_Pos                        (1U)
#define RCC_C2_AHB2LSMENR_GPIOB_Msk                        (0x1UL << RCC_C2_AHB2LSMENR_GPIOB_Pos)           /*!< 0x00000002 */
#define RCC_C2_AHB2LSMENR_GPIOB                            RCC_C2_AHB2LSMENR_GPIOB_Msk                      /*!< GPIOB */
#define RCC_C2_AHB2LSMENR_GPIOC_Pos                        (2U)
#define RCC_C2_AHB2LSMENR_GPIOC_Msk                        (0x1UL << RCC_C2_AHB2LSMENR_GPIOC_Pos)           /*!< 0x00000004 */
#define RCC_C2_AHB2LSMENR_GPIOC                            RCC_C2_AHB2LSMENR_GPIOC_Msk                      /*!< GPIOC */
#define RCC_C2_AHB2LSMENR_GPIOD_Pos                        (3U)
#define RCC_C2_AHB2LSMENR_GPIOD_Msk                        (0x1UL << RCC_C2_AHB2LSMENR_GPIOD_Pos)           /*!< 0x00000008 */
#define RCC_C2_AHB2LSMENR_GPIOD                            RCC_C2_AHB2LSMENR_GPIOD_Msk                      /*!< GPIOD */
#define RCC_C2_AHB2LSMENR_GPIOE_Pos                        (4U)
#define RCC_C2_AHB2LSMENR_GPIOE_Msk                        (0x1UL << RCC_C2_AHB2LSMENR_GPIOE_Pos)           /*!< 0x00000010 */
#define RCC_C2_AHB2LSMENR_GPIOE                            RCC_C2_AHB2LSMENR_GPIOE_Msk                      /*!< GPIOE */
#define RCC_C2_AHB2LSMENR_GPIOF_Pos                        (5U)
#define RCC_C2_AHB2LSMENR_GPIOF_Msk                        (0x1UL << RCC_C2_AHB2LSMENR_GPIOF_Pos)           /*!< 0x00000020 */
#define RCC_C2_AHB2LSMENR_GPIOF                            RCC_C2_AHB2LSMENR_GPIOF_Msk                      /*!< GPIOF */
#define RCC_C2_AHB2LSMENR_GPIOG_Pos                        (6U)
#define RCC_C2_AHB2LSMENR_GPIOG_Msk                        (0x1UL << RCC_C2_AHB2LSMENR_GPIOG_Pos)           /*!< 0x00000040 */
#define RCC_C2_AHB2LSMENR_GPIOG                            RCC_C2_AHB2LSMENR_GPIOG_Msk                      /*!< GPIOG */
#define RCC_C2_AHB2LSMENR_GPIOH_Pos                        (7U)
#define RCC_C2_AHB2LSMENR_GPIOH_Msk                        (0x1UL << RCC_C2_AHB2LSMENR_GPIOH_Pos)           /*!< 0x00000080 */
#define RCC_C2_AHB2LSMENR_GPIOH                            RCC_C2_AHB2LSMENR_GPIOH_Msk                      /*!< GPIOH */
#define RCC_C2_AHB2LSMENR_GPIOI_Pos                        (8U)
#define RCC_C2_AHB2LSMENR_GPIOI_Msk                        (0x1UL << RCC_C2_AHB2LSMENR_GPIOI_Pos)           /*!< 0x00000100 */
#define RCC_C2_AHB2LSMENR_GPIOI                            RCC_C2_AHB2LSMENR_GPIOI_Msk                      /*!< GPIOI */
#define RCC_C2_AHB2LSMENR_DMA1_Pos                         (16U)
#define RCC_C2_AHB2LSMENR_DMA1_Msk                         (0x1UL << RCC_C2_AHB2LSMENR_DMA1_Pos)            /*!< 0x00010000 */
#define RCC_C2_AHB2LSMENR_DMA1                             RCC_C2_AHB2LSMENR_DMA1_Msk                       /*!< DMA1 */
#define RCC_C2_AHB2LSMENR_DMAMUX1_Pos                      (17U)
#define RCC_C2_AHB2LSMENR_DMAMUX1_Msk                      (0x1UL << RCC_C2_AHB2LSMENR_DMAMUX1_Pos)         /*!< 0x00020000 */
#define RCC_C2_AHB2LSMENR_DMAMUX1                          RCC_C2_AHB2LSMENR_DMAMUX1_Msk                    /*!< DMAMUX1 */

/**************  Bit definition for RCC_C2_AHB2HSMENR register  ***************/
#define RCC_C2_AHB2HSMENR_ADC1_ADC2_Pos                    (0U)
#define RCC_C2_AHB2HSMENR_ADC1_ADC2_Msk                    (0x1UL << RCC_C2_AHB2HSMENR_ADC1_ADC2_Pos)       /*!< 0x00000001 */
#define RCC_C2_AHB2HSMENR_ADC1_ADC2                        RCC_C2_AHB2HSMENR_ADC1_ADC2_Msk                  /*!< ADC1_ADC2 */
#define RCC_C2_AHB2HSMENR_BDAC1_Pos                        (4U)
#define RCC_C2_AHB2HSMENR_BDAC1_Msk                        (0x1UL << RCC_C2_AHB2HSMENR_BDAC1_Pos)           /*!< 0x00000010 */
#define RCC_C2_AHB2HSMENR_BDAC1                            RCC_C2_AHB2HSMENR_BDAC1_Msk                      /*!< BDAC1 */
#define RCC_C2_AHB2HSMENR_DAC1_Pos                         (5U)
#define RCC_C2_AHB2HSMENR_DAC1_Msk                         (0x1UL << RCC_C2_AHB2HSMENR_DAC1_Pos)            /*!< 0x00000020 */
#define RCC_C2_AHB2HSMENR_DAC1                             RCC_C2_AHB2HSMENR_DAC1_Msk                       /*!< DAC1 */
#define RCC_C2_AHB2HSMENR_DAC2_Pos                         (6U)
#define RCC_C2_AHB2HSMENR_DAC2_Msk                         (0x1UL << RCC_C2_AHB2HSMENR_DAC2_Pos)            /*!< 0x00000040 */
#define RCC_C2_AHB2HSMENR_DAC2                             RCC_C2_AHB2HSMENR_DAC2_Msk                       /*!< DAC2 */
#define RCC_C2_AHB2HSMENR_COMP1_DIG_Pos                    (12U)
#define RCC_C2_AHB2HSMENR_COMP1_DIG_Msk                    (0x1UL << RCC_C2_AHB2HSMENR_COMP1_DIG_Pos)       /*!< 0x00001000 */
#define RCC_C2_AHB2HSMENR_COMP1_DIG                        RCC_C2_AHB2HSMENR_COMP1_DIG_Msk                  /*!< COMP1_DIG */

/**************  Bit definition for RCC_C2_APB1LSMENR register  ***************/
#define RCC_C2_APB1LSMENR_WWDG1_Pos                        (0U)
#define RCC_C2_APB1LSMENR_WWDG1_Msk                        (0x1UL << RCC_C2_APB1LSMENR_WWDG1_Pos)           /*!< 0x00000001 */
#define RCC_C2_APB1LSMENR_WWDG1                            RCC_C2_APB1LSMENR_WWDG1_Msk                      /*!< WWDG1 */
#define RCC_C2_APB1LSMENR_WWDG2_Pos                        (1U)
#define RCC_C2_APB1LSMENR_WWDG2_Msk                        (0x1UL << RCC_C2_APB1LSMENR_WWDG2_Pos)           /*!< 0x00000002 */
#define RCC_C2_APB1LSMENR_WWDG2                            RCC_C2_APB1LSMENR_WWDG2_Msk                      /*!< WWDG2 */
#define RCC_C2_APB1LSMENR_IWDG1_Pos                        (4U)
#define RCC_C2_APB1LSMENR_IWDG1_Msk                        (0x1UL << RCC_C2_APB1LSMENR_IWDG1_Pos)           /*!< 0x00000010 */
#define RCC_C2_APB1LSMENR_IWDG1                            RCC_C2_APB1LSMENR_IWDG1_Msk                      /*!< IWDG1 */
#define RCC_C2_APB1LSMENR_IWDG2_Pos                        (5U)
#define RCC_C2_APB1LSMENR_IWDG2_Msk                        (0x1UL << RCC_C2_APB1LSMENR_IWDG2_Pos)           /*!< 0x00000020 */
#define RCC_C2_APB1LSMENR_IWDG2                            RCC_C2_APB1LSMENR_IWDG2_Msk                      /*!< IWDG2 */
#define RCC_C2_APB1LSMENR_RTC_Pos                          (10U)
#define RCC_C2_APB1LSMENR_RTC_Msk                          (0x1UL << RCC_C2_APB1LSMENR_RTC_Pos)             /*!< 0x00000400 */
#define RCC_C2_APB1LSMENR_RTC                              RCC_C2_APB1LSMENR_RTC_Msk                        /*!< RTC */
#define RCC_C2_APB1LSMENR_TIM2_Pos                         (15U)
#define RCC_C2_APB1LSMENR_TIM2_Msk                         (0x1UL << RCC_C2_APB1LSMENR_TIM2_Pos)            /*!< 0x00008000 */
#define RCC_C2_APB1LSMENR_TIM2                             RCC_C2_APB1LSMENR_TIM2_Msk                       /*!< TIM2 */
#define RCC_C2_APB1LSMENR_TIM3_Pos                         (16U)
#define RCC_C2_APB1LSMENR_TIM3_Msk                         (0x1UL << RCC_C2_APB1LSMENR_TIM3_Pos)            /*!< 0x00010000 */
#define RCC_C2_APB1LSMENR_TIM3                             RCC_C2_APB1LSMENR_TIM3_Msk                       /*!< TIM3 */
#define RCC_C2_APB1LSMENR_TIM6_Pos                         (17U)
#define RCC_C2_APB1LSMENR_TIM6_Msk                         (0x1UL << RCC_C2_APB1LSMENR_TIM6_Pos)            /*!< 0x00020000 */
#define RCC_C2_APB1LSMENR_TIM6                             RCC_C2_APB1LSMENR_TIM6_Msk                       /*!< TIM6 */
#define RCC_C2_APB1LSMENR_TIM7_Pos                         (18U)
#define RCC_C2_APB1LSMENR_TIM7_Msk                         (0x1UL << RCC_C2_APB1LSMENR_TIM7_Pos)            /*!< 0x00040000 */
#define RCC_C2_APB1LSMENR_TIM7                             RCC_C2_APB1LSMENR_TIM7_Msk                       /*!< TIM7 */
#define RCC_C2_APB1LSMENR_TIM_TS_Pos                       (19U)
#define RCC_C2_APB1LSMENR_TIM_TS_Msk                       (0x1UL << RCC_C2_APB1LSMENR_TIM_TS_Pos)          /*!< 0x00080000 */
#define RCC_C2_APB1LSMENR_TIM_TS                           RCC_C2_APB1LSMENR_TIM_TS_Msk                     /*!< TIM_TS */
#define RCC_C2_APB1LSMENR_I2C1_Pos                         (21U)
#define RCC_C2_APB1LSMENR_I2C1_Msk                         (0x1UL << RCC_C2_APB1LSMENR_I2C1_Pos)            /*!< 0x00200000 */
#define RCC_C2_APB1LSMENR_I2C1                             RCC_C2_APB1LSMENR_I2C1_Msk                       /*!< I2C1 */
#define RCC_C2_APB1LSMENR_I2C2_Pos                         (22U)
#define RCC_C2_APB1LSMENR_I2C2_Msk                         (0x1UL << RCC_C2_APB1LSMENR_I2C2_Pos)            /*!< 0x00400000 */
#define RCC_C2_APB1LSMENR_I2C2                             RCC_C2_APB1LSMENR_I2C2_Msk                       /*!< I2C2 */
#define RCC_C2_APB1LSMENR_SPI2_Pos                         (23U)
#define RCC_C2_APB1LSMENR_SPI2_Msk                         (0x1UL << RCC_C2_APB1LSMENR_SPI2_Pos)            /*!< 0x00800000 */
#define RCC_C2_APB1LSMENR_SPI2                             RCC_C2_APB1LSMENR_SPI2_Msk                       /*!< SPI2 */
#define RCC_C2_APB1LSMENR_SPI3_Pos                         (24U)
#define RCC_C2_APB1LSMENR_SPI3_Msk                         (0x1UL << RCC_C2_APB1LSMENR_SPI3_Pos)            /*!< 0x01000000 */
#define RCC_C2_APB1LSMENR_SPI3                             RCC_C2_APB1LSMENR_SPI3_Msk                       /*!< SPI3 */
#define RCC_C2_APB1LSMENR_UART2_Pos                        (27U)
#define RCC_C2_APB1LSMENR_UART2_Msk                        (0x1UL << RCC_C2_APB1LSMENR_UART2_Pos)           /*!< 0x08000000 */
#define RCC_C2_APB1LSMENR_UART2                            RCC_C2_APB1LSMENR_UART2_Msk                      /*!< UART2 */
#define RCC_C2_APB1LSMENR_UART3_Pos                        (28U)
#define RCC_C2_APB1LSMENR_UART3_Msk                        (0x1UL << RCC_C2_APB1LSMENR_UART3_Pos)           /*!< 0x10000000 */
#define RCC_C2_APB1LSMENR_UART3                            RCC_C2_APB1LSMENR_UART3_Msk                      /*!< UART3 */

/**************  Bit definition for RCC_C2_APB2LSMENR register  ***************/
#define RCC_C2_APB2LSMENR_SYSCFG_Pos                       (0U)
#define RCC_C2_APB2LSMENR_SYSCFG_Msk                       (0x1UL << RCC_C2_APB2LSMENR_SYSCFG_Pos)          /*!< 0x00000001 */
#define RCC_C2_APB2LSMENR_SYSCFG                           RCC_C2_APB2LSMENR_SYSCFG_Msk                     /*!< SYSCFG */
#define RCC_C2_APB2LSMENR_SMPU_Pos                         (2U)
#define RCC_C2_APB2LSMENR_SMPU_Msk                         (0x1UL << RCC_C2_APB2LSMENR_SMPU_Pos)            /*!< 0x00000004 */
#define RCC_C2_APB2LSMENR_SMPU                             RCC_C2_APB2LSMENR_SMPU_Msk                       /*!< SMPU */
#define RCC_C2_APB2LSMENR_TIM1_PWM_Pos                     (11U)
#define RCC_C2_APB2LSMENR_TIM1_PWM_Msk                     (0x1UL << RCC_C2_APB2LSMENR_TIM1_PWM_Pos)        /*!< 0x00000800 */
#define RCC_C2_APB2LSMENR_TIM1_PWM                         RCC_C2_APB2LSMENR_TIM1_PWM_Msk                   /*!< TIM1_PWM */
#define RCC_C2_APB2LSMENR_TIM8_PWM_Pos                     (12U)
#define RCC_C2_APB2LSMENR_TIM8_PWM_Msk                     (0x1UL << RCC_C2_APB2LSMENR_TIM8_PWM_Pos)        /*!< 0x00001000 */
#define RCC_C2_APB2LSMENR_TIM8_PWM                         RCC_C2_APB2LSMENR_TIM8_PWM_Msk                   /*!< TIM8_PWM */
#define RCC_C2_APB2LSMENR_TIM4_Pos                         (15U)
#define RCC_C2_APB2LSMENR_TIM4_Msk                         (0x1UL << RCC_C2_APB2LSMENR_TIM4_Pos)            /*!< 0x00008000 */
#define RCC_C2_APB2LSMENR_TIM4                             RCC_C2_APB2LSMENR_TIM4_Msk                       /*!< TIM4 */
#define RCC_C2_APB2LSMENR_TIM5_Pos                         (16U)
#define RCC_C2_APB2LSMENR_TIM5_Msk                         (0x1UL << RCC_C2_APB2LSMENR_TIM5_Pos)            /*!< 0x00010000 */
#define RCC_C2_APB2LSMENR_TIM5                             RCC_C2_APB2LSMENR_TIM5_Msk                       /*!< TIM5 */
#define RCC_C2_APB2LSMENR_TIM15_Pos                        (17U)
#define RCC_C2_APB2LSMENR_TIM15_Msk                        (0x1UL << RCC_C2_APB2LSMENR_TIM15_Pos)           /*!< 0x00020000 */
#define RCC_C2_APB2LSMENR_TIM15                            RCC_C2_APB2LSMENR_TIM15_Msk                      /*!< TIM15 */
#define RCC_C2_APB2LSMENR_TIM16_Pos                        (18U)
#define RCC_C2_APB2LSMENR_TIM16_Msk                        (0x1UL << RCC_C2_APB2LSMENR_TIM16_Pos)           /*!< 0x00040000 */
#define RCC_C2_APB2LSMENR_TIM16                            RCC_C2_APB2LSMENR_TIM16_Msk                      /*!< TIM16 */
#define RCC_C2_APB2LSMENR_SPI1_Pos                         (23U)
#define RCC_C2_APB2LSMENR_SPI1_Msk                         (0x1UL << RCC_C2_APB2LSMENR_SPI1_Pos)            /*!< 0x00800000 */
#define RCC_C2_APB2LSMENR_SPI1                             RCC_C2_APB2LSMENR_SPI1_Msk                       /*!< SPI1 */
#define RCC_C2_APB2LSMENR_SPI4_Pos                         (24U)
#define RCC_C2_APB2LSMENR_SPI4_Msk                         (0x1UL << RCC_C2_APB2LSMENR_SPI4_Pos)            /*!< 0x01000000 */
#define RCC_C2_APB2LSMENR_SPI4                             RCC_C2_APB2LSMENR_SPI4_Msk                       /*!< SPI4 */
#define RCC_C2_APB2LSMENR_UART1_Pos                        (27U)
#define RCC_C2_APB2LSMENR_UART1_Msk                        (0x1UL << RCC_C2_APB2LSMENR_UART1_Pos)           /*!< 0x08000000 */
#define RCC_C2_APB2LSMENR_UART1                            RCC_C2_APB2LSMENR_UART1_Msk                      /*!< UART1 */

/**************  Bit definition for RCC_C2_APB2HSMENR register  ***************/
#define RCC_C2_APB2HSMENR_SD_ADC1_Pos                      (0U)
#define RCC_C2_APB2HSMENR_SD_ADC1_Msk                      (0x1UL << RCC_C2_APB2HSMENR_SD_ADC1_Pos)         /*!< 0x00000001 */
#define RCC_C2_APB2HSMENR_SD_ADC1                          RCC_C2_APB2HSMENR_SD_ADC1_Msk                    /*!< SD_ADC1 */
#define RCC_C2_APB2HSMENR_SD_ADC2_Pos                      (1U)
#define RCC_C2_APB2HSMENR_SD_ADC2_Msk                      (0x1UL << RCC_C2_APB2HSMENR_SD_ADC2_Pos)         /*!< 0x00000002 */
#define RCC_C2_APB2HSMENR_SD_ADC2                          RCC_C2_APB2HSMENR_SD_ADC2_Msk                    /*!< SD_ADC2 */
#define RCC_C2_APB2HSMENR_FDCAN1_Pos                       (8U)
#define RCC_C2_APB2HSMENR_FDCAN1_Msk                       (0x1UL << RCC_C2_APB2HSMENR_FDCAN1_Pos)          /*!< 0x00000100 */
#define RCC_C2_APB2HSMENR_FDCAN1                           RCC_C2_APB2HSMENR_FDCAN1_Msk                     /*!< FDCAN1 */
#define RCC_C2_APB2HSMENR_FDCAN2_Pos                       (10U)
#define RCC_C2_APB2HSMENR_FDCAN2_Msk                       (0x1UL << RCC_C2_APB2HSMENR_FDCAN2_Pos)          /*!< 0x00000400 */
#define RCC_C2_APB2HSMENR_FDCAN2                           RCC_C2_APB2HSMENR_FDCAN2_Msk                     /*!< FDCAN2 */
#define RCC_C2_APB2HSMENR_FDCAN3_Pos                       (12U)
#define RCC_C2_APB2HSMENR_FDCAN3_Msk                       (0x1UL << RCC_C2_APB2HSMENR_FDCAN3_Pos)          /*!< 0x00001000 */
#define RCC_C2_APB2HSMENR_FDCAN3                           RCC_C2_APB2HSMENR_FDCAN3_Msk                     /*!< FDCAN3 */
#define RCC_C2_APB2HSMENR_FDCAN4_Pos                       (14U)
#define RCC_C2_APB2HSMENR_FDCAN4_Msk                       (0x1UL << RCC_C2_APB2HSMENR_FDCAN4_Pos)          /*!< 0x00004000 */
#define RCC_C2_APB2HSMENR_FDCAN4                           RCC_C2_APB2HSMENR_FDCAN4_Msk                     /*!< FDCAN4 */
#define RCC_C2_APB2HSMENR_FDCAN_MRAM_Pos                   (16U)
#define RCC_C2_APB2HSMENR_FDCAN_MRAM_Msk                   (0x1UL << RCC_C2_APB2HSMENR_FDCAN_MRAM_Pos)      /*!< 0x00010000 */
#define RCC_C2_APB2HSMENR_FDCAN_MRAM                       RCC_C2_APB2HSMENR_FDCAN_MRAM_Msk                 /*!< FDCAN_MRAM */

/******************  Bit definition for RCC_DBGCR register  *******************/
#define RCC_DBGCR_DGB_CLK_0_Pos                            (0U)
#define RCC_DBGCR_DGB_CLK_0_Msk                            (0x1UL << RCC_DBGCR_DGB_CLK_0_Pos)               /*!< 0x00000001 */
#define RCC_DBGCR_DGB_CLK_0                                RCC_DBGCR_DGB_CLK_0_Msk                          /*!< DGB_CLK_0 */
#define RCC_DBGCR_DGB_CLK_1_Pos                            (1U)
#define RCC_DBGCR_DGB_CLK_1_Msk                            (0x1UL << RCC_DBGCR_DGB_CLK_1_Pos)               /*!< 0x00000002 */
#define RCC_DBGCR_DGB_CLK_1                                RCC_DBGCR_DGB_CLK_1_Msk                          /*!< DGB_CLK_1 */
#define RCC_DBGCR_DGB_CLK_2_Pos                            (2U)
#define RCC_DBGCR_DGB_CLK_2_Msk                            (0x1UL << RCC_DBGCR_DGB_CLK_2_Pos)               /*!< 0x00000004 */
#define RCC_DBGCR_DGB_CLK_2                                RCC_DBGCR_DGB_CLK_2_Msk                          /*!< DGB_CLK_2 */
#define RCC_DBGCR_DGB_CLK_3_Pos                            (3U)
#define RCC_DBGCR_DGB_CLK_3_Msk                            (0x1UL << RCC_DBGCR_DGB_CLK_3_Pos)               /*!< 0x00000008 */
#define RCC_DBGCR_DGB_CLK_3                                RCC_DBGCR_DGB_CLK_3_Msk                          /*!< DGB_CLK_3 */
#define RCC_DBGCR_DGB_CLK_4_Pos                            (4U)
#define RCC_DBGCR_DGB_CLK_4_Msk                            (0x1UL << RCC_DBGCR_DGB_CLK_4_Pos)               /*!< 0x00000010 */
#define RCC_DBGCR_DGB_CLK_4                                RCC_DBGCR_DGB_CLK_4_Msk                          /*!< DGB_CLK_4 */
#define RCC_DBGCR_DGB_CLK_5_Pos                            (5U)
#define RCC_DBGCR_DGB_CLK_5_Msk                            (0x1UL << RCC_DBGCR_DGB_CLK_5_Pos)               /*!< 0x00000020 */
#define RCC_DBGCR_DGB_CLK_5                                RCC_DBGCR_DGB_CLK_5_Msk                          /*!< DGB_CLK_5 */
#define RCC_DBGCR_ATB_CLK_Pos                              (8U)
#define RCC_DBGCR_ATB_CLK_Msk                              (0x1UL << RCC_DBGCR_ATB_CLK_Pos)                 /*!< 0x00000100 */
#define RCC_DBGCR_ATB_CLK                                  RCC_DBGCR_ATB_CLK_Msk                            /*!< ATB_CLK */
#define RCC_DBGCR_ATB_TPIU_CLK_Pos                         (9U)
#define RCC_DBGCR_ATB_TPIU_CLK_Msk                         (0x1UL << RCC_DBGCR_ATB_TPIU_CLK_Pos)            /*!< 0x00000200 */
#define RCC_DBGCR_ATB_TPIU_CLK                             RCC_DBGCR_ATB_TPIU_CLK_Msk                       /*!< ATB_TPIU_CLK */
#define RCC_DBGCR_ATB_TPIU_PRE_Pos                         (16U)
#define RCC_DBGCR_ATB_TPIU_PRE_Msk                         (0x7UL << RCC_DBGCR_ATB_TPIU_PRE_Pos)            /*!< 0x00070000 */
#define RCC_DBGCR_ATB_TPIU_PRE                             RCC_DBGCR_ATB_TPIU_PRE_Msk                       /*!< ATB_TPIU_PRE */
#define RCC_DBGCR_DBG_RST_Pos                              (24U)
#define RCC_DBGCR_DBG_RST_Msk                              (0x1UL << RCC_DBGCR_DBG_RST_Pos)                 /*!< 0x01000000 */
#define RCC_DBGCR_DBG_RST                                  RCC_DBGCR_DBG_RST_Msk                            /*!< DBG_RST */

/*******************  Bit definition for RCC_CMUR register  *******************/
#define RCC_CMUR_CMU0RST_Pos                               (0U)
#define RCC_CMUR_CMU0RST_Msk                               (0x1UL << RCC_CMUR_CMU0RST_Pos)                  /*!< 0x00000001 */
#define RCC_CMUR_CMU0RST                                   RCC_CMUR_CMU0RST_Msk                             /*!< CMU0RST */
#define RCC_CMUR_CMU1RST_Pos                               (1U)
#define RCC_CMUR_CMU1RST_Msk                               (0x1UL << RCC_CMUR_CMU1RST_Pos)                  /*!< 0x00000002 */
#define RCC_CMUR_CMU1RST                                   RCC_CMUR_CMU1RST_Msk                             /*!< CMU1RST */
#define RCC_CMUR_CMU2RST_Pos                               (2U)
#define RCC_CMUR_CMU2RST_Msk                               (0x1UL << RCC_CMUR_CMU2RST_Pos)                  /*!< 0x00000004 */
#define RCC_CMUR_CMU2RST                                   RCC_CMUR_CMU2RST_Msk                             /*!< CMU2RST */
#define RCC_CMUR_CMU3RST_Pos                               (3U)
#define RCC_CMUR_CMU3RST_Msk                               (0x1UL << RCC_CMUR_CMU3RST_Pos)                  /*!< 0x00000008 */
#define RCC_CMUR_CMU3RST                                   RCC_CMUR_CMU3RST_Msk                             /*!< CMU3RST */
#define RCC_CMUR_CMU4RST_Pos                               (4U)
#define RCC_CMUR_CMU4RST_Msk                               (0x1UL << RCC_CMUR_CMU4RST_Pos)                  /*!< 0x00000010 */
#define RCC_CMUR_CMU4RST                                   RCC_CMUR_CMU4RST_Msk                             /*!< CMU4RST */
#define RCC_CMUR_CMU5RST_Pos                               (5U)
#define RCC_CMUR_CMU5RST_Msk                               (0x1UL << RCC_CMUR_CMU5RST_Pos)                  /*!< 0x00000020 */
#define RCC_CMUR_CMU5RST                                   RCC_CMUR_CMU5RST_Msk                             /*!< CMU5RST */
#define RCC_CMUR_CMU0EN_Pos                                (8U)
#define RCC_CMUR_CMU0EN_Msk                                (0x1UL << RCC_CMUR_CMU0EN_Pos)                   /*!< 0x00000100 */
#define RCC_CMUR_CMU0EN                                    RCC_CMUR_CMU0EN_Msk                              /*!< CMU0EN */
#define RCC_CMUR_CMU1EN_Pos                                (9U)
#define RCC_CMUR_CMU1EN_Msk                                (0x1UL << RCC_CMUR_CMU1EN_Pos)                   /*!< 0x00000200 */
#define RCC_CMUR_CMU1EN                                    RCC_CMUR_CMU1EN_Msk                              /*!< CMU1EN */
#define RCC_CMUR_CMU2EN_Pos                                (10U)
#define RCC_CMUR_CMU2EN_Msk                                (0x1UL << RCC_CMUR_CMU2EN_Pos)                   /*!< 0x00000400 */
#define RCC_CMUR_CMU2EN                                    RCC_CMUR_CMU2EN_Msk                              /*!< CMU2EN */
#define RCC_CMUR_CMU3EN_Pos                                (11U)
#define RCC_CMUR_CMU3EN_Msk                                (0x1UL << RCC_CMUR_CMU3EN_Pos)                   /*!< 0x00000800 */
#define RCC_CMUR_CMU3EN                                    RCC_CMUR_CMU3EN_Msk                              /*!< CMU3EN */
#define RCC_CMUR_CMU4EN_Pos                                (12U)
#define RCC_CMUR_CMU4EN_Msk                                (0x1UL << RCC_CMUR_CMU4EN_Pos)                   /*!< 0x00001000 */
#define RCC_CMUR_CMU4EN                                    RCC_CMUR_CMU4EN_Msk                              /*!< CMU4EN */
#define RCC_CMUR_CMU5EN_Pos                                (13U)
#define RCC_CMUR_CMU5EN_Msk                                (0x1UL << RCC_CMUR_CMU5EN_Pos)                   /*!< 0x00002000 */
#define RCC_CMUR_CMU5EN                                    RCC_CMUR_CMU5EN_Msk                              /*!< CMU5EN */

/***************  Bit definition for RCC_HSM_SW_CTRLR register  ***************/
#define RCC_HSM_SW_CTRLR_HSM_SW_EN_Pos                     (0U)
#define RCC_HSM_SW_CTRLR_HSM_SW_EN_Msk                     (0x1UL << RCC_HSM_SW_CTRLR_HSM_SW_EN_Pos)        /*!< 0x00000001 */
#define RCC_HSM_SW_CTRLR_HSM_SW_EN                         RCC_HSM_SW_CTRLR_HSM_SW_EN_Msk                   /*!< HSM_SW_EN */

/******************  Bit definition for RCC_DSWRR register  *******************/
#define RCC_DSWRR_DSWR_Pos                                 (0U)
#define RCC_DSWRR_DSWR_Msk                                 (0xFFFFFFFFUL << RCC_DSWRR_DSWR_Pos)             /*!< 0xFFFFFFFF */
#define RCC_DSWRR_DSWR                                     RCC_DSWRR_DSWR_Msk                               /*!< DSWR */

/******************  Bit definition for RCC_DRETR register  *******************/
#define RCC_DRETR_DRET_Pos                                 (0U)
#define RCC_DRETR_DRET_Msk                                 (0xFUL << RCC_DRETR_DRET_Pos)                    /*!< 0x0000000F */
#define RCC_DRETR_DRET                                     RCC_DRETR_DRET_Msk                               /*!< DRET */

/*******************  Bit definition for RCC_DESR register  *******************/
#define RCC_DESR_D_POR_Pos                                 (0U)
#define RCC_DESR_D_POR_Msk                                 (0x1UL << RCC_DESR_D_POR_Pos)                    /*!< 0x00000001 */
#define RCC_DESR_D_POR                                     RCC_DESR_D_POR_Msk                               /*!< D_POR */
#define RCC_DESR_D_IEET_IN_Pos                             (1U)
#define RCC_DESR_D_IEET_IN_Msk                             (0x1UL << RCC_DESR_D_IEET_IN_Pos)                /*!< 0x00000002 */
#define RCC_DESR_D_IEET_IN                                 RCC_DESR_D_IEET_IN_Msk                           /*!< D_IEET_IN */
#define RCC_DESR_D_RCC_SW_Pos                              (3U)
#define RCC_DESR_D_RCC_SW_Msk                              (0x1UL << RCC_DESR_D_RCC_SW_Pos)                 /*!< 0x00000008 */
#define RCC_DESR_D_RCC_SW                                  RCC_DESR_D_RCC_SW_Msk                            /*!< D_RCC_SW */
#define RCC_DESR_D_FCCU_Pos                                (4U)
#define RCC_DESR_D_FCCU_Msk                                (0x1UL << RCC_DESR_D_FCCU_Pos)                   /*!< 0x00000010 */
#define RCC_DESR_D_FCCU                                    RCC_DESR_D_FCCU_Msk                              /*!< D_FCCU */
#define RCC_DESR_D_STCU_CF_Pos                             (5U)
#define RCC_DESR_D_STCU_CF_Msk                             (0x1UL << RCC_DESR_D_STCU_CF_Pos)                /*!< 0x00000020 */
#define RCC_DESR_D_STCU_CF                                 RCC_DESR_D_STCU_CF_Msk                           /*!< D_STCU_CF */
#define RCC_DESR_D_EDR_Pos                                 (8U)
#define RCC_DESR_D_EDR_Msk                                 (0x1UL << RCC_DESR_D_EDR_Pos)                    /*!< 0x00000100 */
#define RCC_DESR_D_EDR                                     RCC_DESR_D_EDR_Msk                               /*!< D_EDR */
#define RCC_DESR_D_SWT_BOOT_Pos                            (9U)
#define RCC_DESR_D_SWT_BOOT_Msk                            (0x1UL << RCC_DESR_D_SWT_BOOT_Pos)               /*!< 0x00000200 */
#define RCC_DESR_D_SWT_BOOT                                RCC_DESR_D_SWT_BOOT_Msk                          /*!< D_SWT_BOOT */
#define RCC_DESR_D_JTAG_Pos                                (10U)
#define RCC_DESR_D_JTAG_Msk                                (0x1UL << RCC_DESR_D_JTAG_Pos)                   /*!< 0x00000400 */
#define RCC_DESR_D_JTAG                                    RCC_DESR_D_JTAG_Msk                              /*!< D_JTAG */
#define RCC_DESR_D_SSCM_Pos                                (14U)
#define RCC_DESR_D_SSCM_Msk                                (0x1UL << RCC_DESR_D_SSCM_Pos)                   /*!< 0x00004000 */
#define RCC_DESR_D_SSCM                                    RCC_DESR_D_SSCM_Msk                              /*!< D_SSCM */
#define RCC_DESR_D_HSM_Pos                                 (15U)
#define RCC_DESR_D_HSM_Msk                                 (0x1UL << RCC_DESR_D_HSM_Pos)                    /*!< 0x00008000 */
#define RCC_DESR_D_HSM                                     RCC_DESR_D_HSM_Msk                               /*!< D_HSM */
#define RCC_DESR_D_TENS_Pos                                (16U)
#define RCC_DESR_D_TENS_Msk                                (0x1UL << RCC_DESR_D_TENS_Pos)                   /*!< 0x00010000 */
#define RCC_DESR_D_TENS                                    RCC_DESR_D_TENS_Msk                              /*!< D_TENS */
#define RCC_DESR_D_VD_Pos                                  (24U)
#define RCC_DESR_D_VD_Msk                                  (0x1UL << RCC_DESR_D_VD_Pos)                     /*!< 0x01000000 */
#define RCC_DESR_D_VD                                      RCC_DESR_D_VD_Msk                                /*!< D_VD */

/******************  Bit definition for RCC_DORER register  *******************/
#define RCC_DORER_D_POR_Pos                                (0U)
#define RCC_DORER_D_POR_Msk                                (0x1UL << RCC_DORER_D_POR_Pos)                   /*!< 0x00000001 */
#define RCC_DORER_D_POR                                    RCC_DORER_D_POR_Msk                              /*!< D_POR */
#define RCC_DORER_D_IEET_IN_Pos                            (1U)
#define RCC_DORER_D_IEET_IN_Msk                            (0x1UL << RCC_DORER_D_IEET_IN_Pos)               /*!< 0x00000002 */
#define RCC_DORER_D_IEET_IN                                RCC_DORER_D_IEET_IN_Msk                          /*!< D_IEET_IN */
#define RCC_DORER_D_RCC_SW_Pos                             (3U)
#define RCC_DORER_D_RCC_SW_Msk                             (0x1UL << RCC_DORER_D_RCC_SW_Pos)                /*!< 0x00000008 */
#define RCC_DORER_D_RCC_SW                                 RCC_DORER_D_RCC_SW_Msk                           /*!< D_RCC_SW */
#define RCC_DORER_D_FCCU_Pos                               (4U)
#define RCC_DORER_D_FCCU_Msk                               (0x1UL << RCC_DORER_D_FCCU_Pos)                  /*!< 0x00000010 */
#define RCC_DORER_D_FCCU                                   RCC_DORER_D_FCCU_Msk                             /*!< D_FCCU */
#define RCC_DORER_D_STCU_CF_Pos                            (5U)
#define RCC_DORER_D_STCU_CF_Msk                            (0x1UL << RCC_DORER_D_STCU_CF_Pos)               /*!< 0x00000020 */
#define RCC_DORER_D_STCU_CF                                RCC_DORER_D_STCU_CF_Msk                          /*!< D_STCU_CF */
#define RCC_DORER_D_EDR_Pos                                (8U)
#define RCC_DORER_D_EDR_Msk                                (0x1UL << RCC_DORER_D_EDR_Pos)                   /*!< 0x00000100 */
#define RCC_DORER_D_EDR                                    RCC_DORER_D_EDR_Msk                              /*!< D_EDR */
#define RCC_DORER_D_SWT_BOOT_Pos                           (9U)
#define RCC_DORER_D_SWT_BOOT_Msk                           (0x1UL << RCC_DORER_D_SWT_BOOT_Pos)              /*!< 0x00000200 */
#define RCC_DORER_D_SWT_BOOT                               RCC_DORER_D_SWT_BOOT_Msk                         /*!< D_SWT_BOOT */
#define RCC_DORER_D_JTAG_Pos                               (10U)
#define RCC_DORER_D_JTAG_Msk                               (0x1UL << RCC_DORER_D_JTAG_Pos)                  /*!< 0x00000400 */
#define RCC_DORER_D_JTAG                                   RCC_DORER_D_JTAG_Msk                             /*!< D_JTAG */
#define RCC_DORER_D_SSCM_Pos                               (14U)
#define RCC_DORER_D_SSCM_Msk                               (0x1UL << RCC_DORER_D_SSCM_Pos)                  /*!< 0x00004000 */
#define RCC_DORER_D_SSCM                                   RCC_DORER_D_SSCM_Msk                             /*!< D_SSCM */
#define RCC_DORER_D_HSM_Pos                                (15U)
#define RCC_DORER_D_HSM_Msk                                (0x1UL << RCC_DORER_D_HSM_Pos)                   /*!< 0x00008000 */
#define RCC_DORER_D_HSM                                    RCC_DORER_D_HSM_Msk                              /*!< D_HSM */
#define RCC_DORER_D_TENS_Pos                               (16U)
#define RCC_DORER_D_TENS_Msk                               (0x1UL << RCC_DORER_D_TENS_Pos)                  /*!< 0x00010000 */
#define RCC_DORER_D_TENS                                   RCC_DORER_D_TENS_Msk                             /*!< D_TENS */
#define RCC_DORER_D_VD_Pos                                 (24U)
#define RCC_DORER_D_VD_Msk                                 (0x1UL << RCC_DORER_D_VD_Pos)                    /*!< 0x01000000 */
#define RCC_DORER_D_VD                                     RCC_DORER_D_VD_Msk                               /*!< D_VD */

/******************  Bit definition for RCC_FSWRR register  *******************/
#define RCC_FSWRR_FSWR_Pos                                 (0U)
#define RCC_FSWRR_FSWR_Msk                                 (0xFFFFFFFFUL << RCC_FSWRR_FSWR_Pos)             /*!< 0xFFFFFFFF */
#define RCC_FSWRR_FSWR                                     RCC_FSWRR_FSWR_Msk                               /*!< FSWR */

/******************  Bit definition for RCC_FRETR register  *******************/
#define RCC_FRETR_FRET_Pos                                 (0U)
#define RCC_FRETR_FRET_Msk                                 (0xFUL << RCC_FRETR_FRET_Pos)                    /*!< 0x0000000F */
#define RCC_FRETR_FRET                                     RCC_FRETR_FRET_Msk                               /*!< FRET */

/*******************  Bit definition for RCC_FESR register  *******************/
#define RCC_FESR_F_ST_DONE_Pos                             (2U)
#define RCC_FESR_F_ST_DONE_Msk                             (0x1UL << RCC_FESR_F_ST_DONE_Pos)                /*!< 0x00000004 */
#define RCC_FESR_F_ST_DONE                                 RCC_FESR_F_ST_DONE_Msk                           /*!< F_ST_DONE */
#define RCC_FESR_F_RCC_SW_Pos                              (3U)
#define RCC_FESR_F_RCC_SW_Msk                              (0x1UL << RCC_FESR_F_RCC_SW_Pos)                 /*!< 0x00000008 */
#define RCC_FESR_F_RCC_SW                                  RCC_FESR_F_RCC_SW_Msk                            /*!< F_RCC_SW */
#define RCC_FESR_F_FCCU_LONG_Pos                           (5U)
#define RCC_FESR_F_FCCU_LONG_Msk                           (0x1UL << RCC_FESR_F_FCCU_LONG_Pos)              /*!< 0x00000020 */
#define RCC_FESR_F_FCCU_LONG                               RCC_FESR_F_FCCU_LONG_Msk                         /*!< F_FCCU_LONG */
#define RCC_FESR_F_FCCU_SHORT_Pos                          (6U)
#define RCC_FESR_F_FCCU_SHORT_Msk                          (0x1UL << RCC_FESR_F_FCCU_SHORT_Pos)             /*!< 0x00000040 */
#define RCC_FESR_F_FCCU_SHORT                              RCC_FESR_F_FCCU_SHORT_Msk                        /*!< F_FCCU_SHORT */
#define RCC_FESR_F_JTAG_Pos                                (10U)
#define RCC_FESR_F_JTAG_Msk                                (0x1UL << RCC_FESR_F_JTAG_Pos)                   /*!< 0x00000400 */
#define RCC_FESR_F_JTAG                                    RCC_FESR_F_JTAG_Msk                              /*!< F_JTAG */
#define RCC_FESR_F_HSM_Pos                                 (15U)
#define RCC_FESR_F_HSM_Msk                                 (0x1UL << RCC_FESR_F_HSM_Pos)                    /*!< 0x00008000 */
#define RCC_FESR_F_HSM                                     RCC_FESR_F_HSM_Msk                               /*!< F_HSM */
#define RCC_FESR_F_TENS_Pos                                (16U)
#define RCC_FESR_F_TENS_Msk                                (0x1UL << RCC_FESR_F_TENS_Pos)                   /*!< 0x00010000 */
#define RCC_FESR_F_TENS                                    RCC_FESR_F_TENS_Msk                              /*!< F_TENS */
#define RCC_FESR_F_VD_Pos                                  (24U)
#define RCC_FESR_F_VD_Msk                                  (0x1UL << RCC_FESR_F_VD_Pos)                     /*!< 0x01000000 */
#define RCC_FESR_F_VD                                      RCC_FESR_F_VD_Msk                                /*!< F_VD */

/******************  Bit definition for RCC_FORER register  *******************/
#define RCC_FORER_F_ST_DONE_Pos                            (2U)
#define RCC_FORER_F_ST_DONE_Msk                            (0x1UL << RCC_FORER_F_ST_DONE_Pos)               /*!< 0x00000004 */
#define RCC_FORER_F_ST_DONE                                RCC_FORER_F_ST_DONE_Msk                          /*!< F_ST_DONE */
#define RCC_FORER_F_RCC_SW_Pos                             (3U)
#define RCC_FORER_F_RCC_SW_Msk                             (0x1UL << RCC_FORER_F_RCC_SW_Pos)                /*!< 0x00000008 */
#define RCC_FORER_F_RCC_SW                                 RCC_FORER_F_RCC_SW_Msk                           /*!< F_RCC_SW */
#define RCC_FORER_F_FCCU_LONG_Pos                          (5U)
#define RCC_FORER_F_FCCU_LONG_Msk                          (0x1UL << RCC_FORER_F_FCCU_LONG_Pos)             /*!< 0x00000020 */
#define RCC_FORER_F_FCCU_LONG                              RCC_FORER_F_FCCU_LONG_Msk                        /*!< F_FCCU_LONG */
#define RCC_FORER_F_FCCU_SHORT_Pos                         (6U)
#define RCC_FORER_F_FCCU_SHORT_Msk                         (0x1UL << RCC_FORER_F_FCCU_SHORT_Pos)            /*!< 0x00000040 */
#define RCC_FORER_F_FCCU_SHORT                             RCC_FORER_F_FCCU_SHORT_Msk                       /*!< F_FCCU_SHORT */
#define RCC_FORER_F_JTAG_Pos                               (10U)
#define RCC_FORER_F_JTAG_Msk                               (0x1UL << RCC_FORER_F_JTAG_Pos)                  /*!< 0x00000400 */
#define RCC_FORER_F_JTAG                                   RCC_FORER_F_JTAG_Msk                             /*!< F_JTAG */
#define RCC_FORER_F_HSM_Pos                                (15U)
#define RCC_FORER_F_HSM_Msk                                (0x1UL << RCC_FORER_F_HSM_Pos)                   /*!< 0x00008000 */
#define RCC_FORER_F_HSM                                    RCC_FORER_F_HSM_Msk                              /*!< F_HSM */
#define RCC_FORER_F_TENS_Pos                               (16U)
#define RCC_FORER_F_TENS_Msk                               (0x1UL << RCC_FORER_F_TENS_Pos)                  /*!< 0x00010000 */
#define RCC_FORER_F_TENS                                   RCC_FORER_F_TENS_Msk                             /*!< F_TENS */
#define RCC_FORER_F_VD_Pos                                 (24U)
#define RCC_FORER_F_VD_Msk                                 (0x1UL << RCC_FORER_F_VD_Pos)                    /*!< 0x01000000 */
#define RCC_FORER_F_VD                                     RCC_FORER_F_VD_Msk                               /*!< F_VD */

/******************  Bit definition for RCC_FERDR register  *******************/
#define RCC_FERDR_F_ST_DONE_Pos                            (2U)
#define RCC_FERDR_F_ST_DONE_Msk                            (0x1UL << RCC_FERDR_F_ST_DONE_Pos)               /*!< 0x00000004 */
#define RCC_FERDR_F_ST_DONE                                RCC_FERDR_F_ST_DONE_Msk                          /*!< F_ST_DONE */
#define RCC_FERDR_F_RCC_SW_Pos                             (3U)
#define RCC_FERDR_F_RCC_SW_Msk                             (0x1UL << RCC_FERDR_F_RCC_SW_Pos)                /*!< 0x00000008 */
#define RCC_FERDR_F_RCC_SW                                 RCC_FERDR_F_RCC_SW_Msk                           /*!< F_RCC_SW */
#define RCC_FERDR_F_FCCU_LONG_Pos                          (5U)
#define RCC_FERDR_F_FCCU_LONG_Msk                          (0x1UL << RCC_FERDR_F_FCCU_LONG_Pos)             /*!< 0x00000020 */
#define RCC_FERDR_F_FCCU_LONG                              RCC_FERDR_F_FCCU_LONG_Msk                        /*!< F_FCCU_LONG */
#define RCC_FERDR_F_FCCU_SHORT_Pos                         (6U)
#define RCC_FERDR_F_FCCU_SHORT_Msk                         (0x1UL << RCC_FERDR_F_FCCU_SHORT_Pos)            /*!< 0x00000040 */
#define RCC_FERDR_F_FCCU_SHORT                             RCC_FERDR_F_FCCU_SHORT_Msk                       /*!< F_FCCU_SHORT */
#define RCC_FERDR_F_JTAG_Pos                               (10U)
#define RCC_FERDR_F_JTAG_Msk                               (0x1UL << RCC_FERDR_F_JTAG_Pos)                  /*!< 0x00000400 */
#define RCC_FERDR_F_JTAG                                   RCC_FERDR_F_JTAG_Msk                             /*!< F_JTAG */
#define RCC_FERDR_F_HSM_Pos                                (15U)
#define RCC_FERDR_F_HSM_Msk                                (0x1UL << RCC_FERDR_F_HSM_Pos)                   /*!< 0x00008000 */
#define RCC_FERDR_F_HSM                                    RCC_FERDR_F_HSM_Msk                              /*!< F_HSM */
#define RCC_FERDR_F_TENS_Pos                               (16U)
#define RCC_FERDR_F_TENS_Msk                               (0x1UL << RCC_FERDR_F_TENS_Pos)                  /*!< 0x00010000 */
#define RCC_FERDR_F_TENS                                   RCC_FERDR_F_TENS_Msk                             /*!< F_TENS */
#define RCC_FERDR_F_VD_Pos                                 (24U)
#define RCC_FERDR_F_VD_Msk                                 (0x1UL << RCC_FERDR_F_VD_Pos)                    /*!< 0x01000000 */
#define RCC_FERDR_F_VD                                     RCC_FERDR_F_VD_Msk                               /*!< F_VD */

/******************  Bit definition for RCC_FESSR register  *******************/
#define RCC_FESSR_F_ST_DONE_Pos                            (2U)
#define RCC_FESSR_F_ST_DONE_Msk                            (0x1UL << RCC_FESSR_F_ST_DONE_Pos)               /*!< 0x00000004 */
#define RCC_FESSR_F_ST_DONE                                RCC_FESSR_F_ST_DONE_Msk                          /*!< F_ST_DONE */
#define RCC_FESSR_F_RCC_SW_Pos                             (3U)
#define RCC_FESSR_F_RCC_SW_Msk                             (0x1UL << RCC_FESSR_F_RCC_SW_Pos)                /*!< 0x00000008 */
#define RCC_FESSR_F_RCC_SW                                 RCC_FESSR_F_RCC_SW_Msk                           /*!< F_RCC_SW */
#define RCC_FESSR_F_FCCU_LONG_Pos                          (5U)
#define RCC_FESSR_F_FCCU_LONG_Msk                          (0x1UL << RCC_FESSR_F_FCCU_LONG_Pos)             /*!< 0x00000020 */
#define RCC_FESSR_F_FCCU_LONG                              RCC_FESSR_F_FCCU_LONG_Msk                        /*!< F_FCCU_LONG */
#define RCC_FESSR_F_FCCU_SHORT_Pos                         (6U)
#define RCC_FESSR_F_FCCU_SHORT_Msk                         (0x1UL << RCC_FESSR_F_FCCU_SHORT_Pos)            /*!< 0x00000040 */
#define RCC_FESSR_F_FCCU_SHORT                             RCC_FESSR_F_FCCU_SHORT_Msk                       /*!< F_FCCU_SHORT */
#define RCC_FESSR_F_JTAG_Pos                               (10U)
#define RCC_FESSR_F_JTAG_Msk                               (0x1UL << RCC_FESSR_F_JTAG_Pos)                  /*!< 0x00000400 */
#define RCC_FESSR_F_JTAG                                   RCC_FESSR_F_JTAG_Msk                             /*!< F_JTAG */
#define RCC_FESSR_F_HSM_Pos                                (15U)
#define RCC_FESSR_F_HSM_Msk                                (0x1UL << RCC_FESSR_F_HSM_Pos)                   /*!< 0x00008000 */
#define RCC_FESSR_F_HSM                                    RCC_FESSR_F_HSM_Msk                              /*!< F_HSM */
#define RCC_FESSR_F_TENS_Pos                               (16U)
#define RCC_FESSR_F_TENS_Msk                               (0x1UL << RCC_FESSR_F_TENS_Pos)                  /*!< 0x00010000 */
#define RCC_FESSR_F_TENS                                   RCC_FESSR_F_TENS_Msk                             /*!< F_TENS */
#define RCC_FESSR_F_VD_Pos                                 (24U)
#define RCC_FESSR_F_VD_Msk                                 (0x1UL << RCC_FESSR_F_VD_Pos)                    /*!< 0x01000000 */
#define RCC_FESSR_F_VD                                     RCC_FESSR_F_VD_Msk                               /*!< F_VD */

/***************  Bit definition for RCC_SYS_CFG_REG register  ****************/
#define RCC_SYS_CFG_REG_BOOT_CORE1_Pos                     (1U)
#define RCC_SYS_CFG_REG_BOOT_CORE1_Msk                     (0x1UL << RCC_SYS_CFG_REG_BOOT_CORE1_Pos)        /*!< 0x00000002 */
#define RCC_SYS_CFG_REG_BOOT_CORE1                         RCC_SYS_CFG_REG_BOOT_CORE1_Msk                   /*!< BOOT_CORE1 */
#define RCC_SYS_CFG_REG_BOOT_CORE2_Pos                     (2U)
#define RCC_SYS_CFG_REG_BOOT_CORE2_Msk                     (0x1UL << RCC_SYS_CFG_REG_BOOT_CORE2_Pos)        /*!< 0x00000004 */
#define RCC_SYS_CFG_REG_BOOT_CORE2                         RCC_SYS_CFG_REG_BOOT_CORE2_Msk                   /*!< BOOT_CORE2 */
#define RCC_SYS_CFG_REG_LS_CORE1_2_Pos                     (8U)
#define RCC_SYS_CFG_REG_LS_CORE1_2_Msk                     (0x1UL << RCC_SYS_CFG_REG_LS_CORE1_2_Pos)        /*!< 0x00000100 */
#define RCC_SYS_CFG_REG_LS_CORE1_2                         RCC_SYS_CFG_REG_LS_CORE1_2_Msk                   /*!< LS_CORE1_2 */
#define RCC_SYS_CFG_REG_LS_DMA_Pos                         (16U)
#define RCC_SYS_CFG_REG_LS_DMA_Msk                         (0x1UL << RCC_SYS_CFG_REG_LS_DMA_Pos)            /*!< 0x00010000 */
#define RCC_SYS_CFG_REG_LS_DMA                             RCC_SYS_CFG_REG_LS_DMA_Msk                       /*!< LS_DMA */
#define RCC_SYS_CFG_REG_OTA_EN_Pos                         (24U)
#define RCC_SYS_CFG_REG_OTA_EN_Msk                         (0x1UL << RCC_SYS_CFG_REG_OTA_EN_Pos)            /*!< 0x01000000 */
#define RCC_SYS_CFG_REG_OTA_EN                             RCC_SYS_CFG_REG_OTA_EN_Msk                       /*!< OTA_EN */

/*************  Bit definition for RCC_C1_VTOR_INIT_REG register  *************/
#define RCC_C1_VTOR_INIT_REG_C1_VTOR_INIT_Pos              (7U)
#define RCC_C1_VTOR_INIT_REG_C1_VTOR_INIT_Msk              (0x1FFFFFFUL << RCC_C1_VTOR_INIT_REG_C1_VTOR_INIT_Pos)   /*!< 0xFFFFFF80 */
#define RCC_C1_VTOR_INIT_REG_C1_VTOR_INIT                  RCC_C1_VTOR_INIT_REG_C1_VTOR_INIT_Msk                    /*!< C1_VTOR_INIT */

/*************  Bit definition for RCC_C2_VTOR_INIT_REG register  *************/
#define RCC_C2_VTOR_INIT_REG_UPDATE_COUNTS_Pos             (0U)
#define RCC_C2_VTOR_INIT_REG_UPDATE_COUNTS_Msk             (0x7UL << RCC_C2_VTOR_INIT_REG_UPDATE_COUNTS_Pos)        /*!< 0x00000007 */
#define RCC_C2_VTOR_INIT_REG_UPDATE_COUNTS                 RCC_C2_VTOR_INIT_REG_UPDATE_COUNTS_Msk                   /*!< UPDATE_COUNTS */
#define RCC_C2_VTOR_INIT_REG_C2_VTOR_INIT_Pos              (7U)
#define RCC_C2_VTOR_INIT_REG_C2_VTOR_INIT_Msk              (0x1FFFFFFUL << RCC_C2_VTOR_INIT_REG_C2_VTOR_INIT_Pos)   /*!< 0xFFFFFF80 */
#define RCC_C2_VTOR_INIT_REG_C2_VTOR_INIT                  RCC_C2_VTOR_INIT_REG_C2_VTOR_INIT_Msk                    /*!< C2_VTOR_INIT */

/************  Bit definition for RCC_C1_APPLI_ADDR_REG register  *************/
#define RCC_C1_APPLI_ADDR_REG_UPDATE_COUNTS_Pos            (0U)
#define RCC_C1_APPLI_ADDR_REG_UPDATE_COUNTS_Msk            (0x7UL << RCC_C1_APPLI_ADDR_REG_UPDATE_COUNTS_Pos)       /*!< 0x00000007 */
#define RCC_C1_APPLI_ADDR_REG_UPDATE_COUNTS                RCC_C1_APPLI_ADDR_REG_UPDATE_COUNTS_Msk                  /*!< UPDATE_COUNTS */
#define RCC_C1_APPLI_ADDR_REG_C1_APPLI_ADDR_Pos            (7U)
#define RCC_C1_APPLI_ADDR_REG_C1_APPLI_ADDR_Msk            (0x1FFFFFFUL << RCC_C1_APPLI_ADDR_REG_C1_APPLI_ADDR_Pos) /*!< 0xFFFFFF80 */
#define RCC_C1_APPLI_ADDR_REG_C1_APPLI_ADDR                RCC_C1_APPLI_ADDR_REG_C1_APPLI_ADDR_Msk                  /*!< C1_APPLI_ADDR */

/*************  Bit definition for RCC_C1_BOOT_CTRL_REG register  *************/
#define RCC_C1_BOOT_CTRL_REG_C1_RES_RELEASE_Pos            (0U)
#define RCC_C1_BOOT_CTRL_REG_C1_RES_RELEASE_Msk            (0x1UL << RCC_C1_BOOT_CTRL_REG_C1_RES_RELEASE_Pos)       /*!< 0x00000001 */
#define RCC_C1_BOOT_CTRL_REG_C1_RES_RELEASE                RCC_C1_BOOT_CTRL_REG_C1_RES_RELEASE_Msk                  /*!< C1_RES_RELEASE */
#define RCC_C1_BOOT_CTRL_REG_C1_CPU_WAIT_RELEASE_Pos       (1U)
#define RCC_C1_BOOT_CTRL_REG_C1_CPU_WAIT_RELEASE_Msk       (0x1UL << RCC_C1_BOOT_CTRL_REG_C1_CPU_WAIT_RELEASE_Pos)  /*!< 0x00000002 */
#define RCC_C1_BOOT_CTRL_REG_C1_CPU_WAIT_RELEASE           RCC_C1_BOOT_CTRL_REG_C1_CPU_WAIT_RELEASE_Msk             /*!< C1_CPU_WAIT_RELEASE */
#define RCC_C1_BOOT_CTRL_REG_C1_LOCK_Pos                   (31U)
#define RCC_C1_BOOT_CTRL_REG_C1_LOCK_Msk                   (0x1UL << RCC_C1_BOOT_CTRL_REG_C1_LOCK_Pos)              /*!< 0x80000000 */
#define RCC_C1_BOOT_CTRL_REG_C1_LOCK                       RCC_C1_BOOT_CTRL_REG_C1_LOCK_Msk                         /*!< C1_LOCK */

/*************  Bit definition for RCC_C2_BOOT_CTRL_REG register  *************/
#define RCC_C2_BOOT_CTRL_REG_C2_RES_RELEASE_Pos            (0U)
#define RCC_C2_BOOT_CTRL_REG_C2_RES_RELEASE_Msk            (0x1UL << RCC_C2_BOOT_CTRL_REG_C2_RES_RELEASE_Pos)       /*!< 0x00000001 */
#define RCC_C2_BOOT_CTRL_REG_C2_RES_RELEASE                RCC_C2_BOOT_CTRL_REG_C2_RES_RELEASE_Msk                  /*!< C2_RES_RELEASE */
#define RCC_C2_BOOT_CTRL_REG_C2_CPU_WAIT_RELEASE_Pos       (1U)
#define RCC_C2_BOOT_CTRL_REG_C2_CPU_WAIT_RELEASE_Msk       (0x1UL << RCC_C2_BOOT_CTRL_REG_C2_CPU_WAIT_RELEASE_Pos)  /*!< 0x00000002 */
#define RCC_C2_BOOT_CTRL_REG_C2_CPU_WAIT_RELEASE           RCC_C2_BOOT_CTRL_REG_C2_CPU_WAIT_RELEASE_Msk             /*!< C2_CPU_WAIT_RELEASE */
#define RCC_C2_BOOT_CTRL_REG_C2_LOCK_Pos                   (31U)
#define RCC_C2_BOOT_CTRL_REG_C2_LOCK_Msk                   (0x1UL << RCC_C2_BOOT_CTRL_REG_C2_LOCK_Pos)              /*!< 0x80000000 */
#define RCC_C2_BOOT_CTRL_REG_C2_LOCK                       RCC_C2_BOOT_CTRL_REG_C2_LOCK_Msk                         /*!< C2_LOCK */

/*************  Bit definition for RCC_C_SLEEP_STS_REG register  **************/
#define RCC_C_SLEEP_STS_REG_C1_SLEEP_MODE_STS_Pos          (0U)
#define RCC_C_SLEEP_STS_REG_C1_SLEEP_MODE_STS_Msk          (0x1UL << RCC_C_SLEEP_STS_REG_C1_SLEEP_MODE_STS_Pos)     /*!< 0x00000001 */
#define RCC_C_SLEEP_STS_REG_C1_SLEEP_MODE_STS              RCC_C_SLEEP_STS_REG_C1_SLEEP_MODE_STS_Msk                /*!< C1_SLEEP_MODE_STS */
#define RCC_C_SLEEP_STS_REG_C2_SLEEP_MODE_STS_Pos          (8U)
#define RCC_C_SLEEP_STS_REG_C2_SLEEP_MODE_STS_Msk          (0x1UL << RCC_C_SLEEP_STS_REG_C2_SLEEP_MODE_STS_Pos)     /*!< 0x00000100 */
#define RCC_C_SLEEP_STS_REG_C2_SLEEP_MODE_STS              RCC_C_SLEEP_STS_REG_C2_SLEEP_MODE_STS_Msk                /*!< C2_SLEEP_MODE_STS */

/***************  Bit definition for RCC_PCS_CTRL_REG register  ***************/
#define RCC_PCS_CTRL_REG_PCS_CTL_Pos                       (0U)
#define RCC_PCS_CTRL_REG_PCS_CTL_Msk                       (0x7UL << RCC_PCS_CTRL_REG_PCS_CTL_Pos)          /*!< 0x00000007 */
#define RCC_PCS_CTRL_REG_PCS_CTL                           RCC_PCS_CTRL_REG_PCS_CTL_Msk                     /*!< PCS_CTL */
#define RCC_PCS_CTRL_REG_PCS_CTL_0                         (0x1UL << RCC_PCS_CTRL_REG_PCS_CTL_Pos)          /*!< 0x00000001 */
#define RCC_PCS_CTRL_REG_PCS_CTL_1                         (0x2UL << RCC_PCS_CTRL_REG_PCS_CTL_Pos)          /*!< 0x00000002 */
#define RCC_PCS_CTRL_REG_PCS_CTL_2                         (0x4UL << RCC_PCS_CTRL_REG_PCS_CTL_Pos)          /*!< 0x00000004 */
#define RCC_PCS_CTRL_REG_PCS_BUSY_Pos                      (8U)
#define RCC_PCS_CTRL_REG_PCS_BUSY_Msk                      (0x1UL << RCC_PCS_CTRL_REG_PCS_BUSY_Pos)         /*!< 0x00000100 */
#define RCC_PCS_CTRL_REG_PCS_BUSY                          RCC_PCS_CTRL_REG_PCS_BUSY_Msk                    /*!< PCS_BUSY */

/************  Bit definition for RCC_PCS_DIVC_XOSC_REG register  *************/
#define RCC_PCS_DIVC_XOSC_REG_RATE_Pos                     (0U)
#define RCC_PCS_DIVC_XOSC_REG_RATE_Msk                     (0xFFUL << RCC_PCS_DIVC_XOSC_REG_RATE_Pos)       /*!< 0x000000FF */
#define RCC_PCS_DIVC_XOSC_REG_RATE                         RCC_PCS_DIVC_XOSC_REG_RATE_Msk                   /*!< RATE */
#define RCC_PCS_DIVC_XOSC_REG_INIT_Pos                     (16U)
#define RCC_PCS_DIVC_XOSC_REG_INIT_Msk                     (0xFFFFUL << RCC_PCS_DIVC_XOSC_REG_INIT_Pos)     /*!< 0xFFFF0000 */
#define RCC_PCS_DIVC_XOSC_REG_INIT                         RCC_PCS_DIVC_XOSC_REG_INIT_Msk                   /*!< INIT */

/************  Bit definition for RCC_PCS_DIVE_XOSC_REG register  *************/
#define RCC_PCS_DIVE_XOSC_REG_DIVE_Pos                     (0U)
#define RCC_PCS_DIVE_XOSC_REG_DIVE_Msk                     (0x7FFFFUL << RCC_PCS_DIVE_XOSC_REG_DIVE_Pos)    /*!< 0x0007FFFF */
#define RCC_PCS_DIVE_XOSC_REG_DIVE                         RCC_PCS_DIVE_XOSC_REG_DIVE_Msk                   /*!< DIVE */

/************  Bit definition for RCC_PCS_DIVC_PLL0_REG register  *************/
#define RCC_PCS_DIVC_PLL0_REG_RATE_Pos                     (0U)
#define RCC_PCS_DIVC_PLL0_REG_RATE_Msk                     (0xFFUL << RCC_PCS_DIVC_PLL0_REG_RATE_Pos)       /*!< 0x000000FF */
#define RCC_PCS_DIVC_PLL0_REG_RATE                         RCC_PCS_DIVC_PLL0_REG_RATE_Msk                   /*!< RATE */
#define RCC_PCS_DIVC_PLL0_REG_INIT_Pos                     (16U)
#define RCC_PCS_DIVC_PLL0_REG_INIT_Msk                     (0xFFUL << RCC_PCS_DIVC_PLL0_REG_INIT_Pos)       /*!< 0x00FF0000 */
#define RCC_PCS_DIVC_PLL0_REG_INIT                         RCC_PCS_DIVC_PLL0_REG_INIT_Msk                   /*!< INIT */

/************  Bit definition for RCC_PCS_DIVE_PLL0_REG register  *************/
#define RCC_PCS_DIVE_PLL0_REG_DIVE_Pos                     (0U)
#define RCC_PCS_DIVE_PLL0_REG_DIVE_Msk                     (0x7FFFFUL << RCC_PCS_DIVE_PLL0_REG_DIVE_Pos)    /*!< 0x0007FFFF */
#define RCC_PCS_DIVE_PLL0_REG_DIVE                         RCC_PCS_DIVE_PLL0_REG_DIVE_Msk                   /*!< DIVE */

/************  Bit definition for RCC_PCS_DIVC_PLL1_REG register  *************/
#define RCC_PCS_DIVC_PLL1_REG_RATE_Pos                     (0U)
#define RCC_PCS_DIVC_PLL1_REG_RATE_Msk                     (0xFFUL << RCC_PCS_DIVC_PLL1_REG_RATE_Pos)       /*!< 0x000000FF */
#define RCC_PCS_DIVC_PLL1_REG_RATE                         RCC_PCS_DIVC_PLL1_REG_RATE_Msk                   /*!< RATE */
#define RCC_PCS_DIVC_PLL1_REG_INIT_Pos                     (16U)
#define RCC_PCS_DIVC_PLL1_REG_INIT_Msk                     (0xFFUL << RCC_PCS_DIVC_PLL1_REG_INIT_Pos)       /*!< 0x00FF0000 */
#define RCC_PCS_DIVC_PLL1_REG_INIT                         RCC_PCS_DIVC_PLL1_REG_INIT_Msk                   /*!< INIT */

/************  Bit definition for RCC_PCS_DIVE_PLL1_REG register  *************/
#define RCC_PCS_DIVE_PLL1_REG_DIVE_Pos                     (0U)
#define RCC_PCS_DIVE_PLL1_REG_DIVE_Msk                     (0x7FFFFUL << RCC_PCS_DIVE_PLL1_REG_DIVE_Pos)    /*!< 0x0007FFFF */
#define RCC_PCS_DIVE_PLL1_REG_DIVE                         RCC_PCS_DIVE_PLL1_REG_DIVE_Msk                   /*!< DIVE */

#define RCC_BASE           0x44000000UL 


#define RCC                ((RCC_TypeDef *) RCC_BASE)               


#endif /* __SR5E1_RCC_H */

