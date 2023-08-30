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

#ifndef __SR5E1_SYSCFG_H
#define __SR5E1_SYSCFG_H

/******************************************************************************/
/*                                                                            */
/*                              SYSCFG (SYSCFG)                               */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __I  uint32_t MIDR1;                 /*!< MIDR1                Address offset: 0x000 */
  __I  uint32_t MIDR2;                 /*!< MIDR2                Address offset: 0x004 */
  __IO uint32_t EXTICR[4];             /*!< EXTICR               Address offset: 0x008-0x014 */
       uint32_t RESERVED0[2];          /*!< Reserved             Address offset: 0x018-0x01C */
  __IO uint32_t SDADCX_EXT_GATE_SEL;   /*!< SDADCX_EXT_GATE_SEL  Address offset: 0x020 */
       uint32_t RESERVED1[3];          /*!< Reserved             Address offset: 0x024-0x02C */
  __IO uint32_t ADC_BIASEN;            /*!< ADC_BIASEN           Address offset: 0x030 */
       uint32_t RESERVED2[3];          /*!< Reserved             Address offset: 0x034-0x03C */
  __IO uint32_t FCCU_FILTER1;          /*!< FCCU_FILTER1         Address offset: 0x040 */
  __IO uint32_t FCCU_FILTER2;          /*!< FCCU_FILTER2         Address offset: 0x044 */
       uint32_t RESERVED3[110];        /*!< Reserved             Address offset: 0x048-0x1FC */
  __IO uint32_t ST_VREF_SEL1;          /*!< ST_VREF_SEL1         Address offset: 0x200 */
  __IO uint32_t ST_VREF_SEL2;          /*!< ST_VREF_SEL2         Address offset: 0x204 */
       uint32_t RESERVED4[62];         /*!< Reserved             Address offset: 0x208-0x2FC */
  __IO uint32_t HRTIMX_UPDATE_EN;      /*!< HRTIMX_UPDATE_EN     Address offset: 0x300 */
  __IO uint32_t HRTIMXFLT_TIMXBRK_EN;  /*!< HRTIMXFLT_TIMXBRK_EN Address offset: 0x304 */
} SYSCFG_TypeDef;


/*****************  Bit definition for SYSCFG_MIDR1 register  *****************/
#define SYSCFG_MIDR1_MINOR_MASK_Pos                          (0U)
#define SYSCFG_MIDR1_MINOR_MASK_Msk                          (0xFUL << SYSCFG_MIDR1_MINOR_MASK_Pos)                   /*!< 0x0000000F */
#define SYSCFG_MIDR1_MINOR_MASK                              SYSCFG_MIDR1_MINOR_MASK_Msk                             /*!< </spirit:description> */
#define SYSCFG_MIDR1_MAJOR_MASK_Pos                          (4U)
#define SYSCFG_MIDR1_MAJOR_MASK_Msk                          (0xFUL << SYSCFG_MIDR1_MAJOR_MASK_Pos)                   /*!< 0x000000F0 */
#define SYSCFG_MIDR1_MAJOR_MASK                              SYSCFG_MIDR1_MAJOR_MASK_Msk                             /*!< </spirit:description> */
#define SYSCFG_MIDR1_PACKAGE_Pos                             (10U)
#define SYSCFG_MIDR1_PACKAGE_Msk                             (0x1FUL << SYSCFG_MIDR1_PACKAGE_Pos)                     /*!< 0x00007C00 */
#define SYSCFG_MIDR1_PACKAGE                                 SYSCFG_MIDR1_PACKAGE_Msk                                /*!< </spirit:description> */
#define SYSCFG_MIDR1_DEVICE_INFO_Pos                         (16U)
#define SYSCFG_MIDR1_DEVICE_INFO_Msk                         (0xFFFFUL << SYSCFG_MIDR1_DEVICE_INFO_Pos)                /*!< 0xFFFF0000 */
#define SYSCFG_MIDR1_DEVICE_INFO                             SYSCFG_MIDR1_DEVICE_INFO_Msk                            /*!< </spirit:description> */

/*****************  Bit definition for SYSCFG_MIDR2 register  *****************/
#define SYSCFG_MIDR2_SERIE_Pos                               (8U)
#define SYSCFG_MIDR2_SERIE_Msk                               (0xFFUL << SYSCFG_MIDR2_SERIE_Pos)                       /*!< 0x0000FF00 */
#define SYSCFG_MIDR2_SERIE                                   SYSCFG_MIDR2_SERIE_Msk                                  /*!< </spirit:description> */
#define SYSCFG_MIDR2_NVM_SIZE_2_Pos                          (23U)
#define SYSCFG_MIDR2_NVM_SIZE_2_Msk                          (0xFUL << SYSCFG_MIDR2_NVM_SIZE_2_Pos)                   /*!< 0x07800000 */
#define SYSCFG_MIDR2_NVM_SIZE_2                              SYSCFG_MIDR2_NVM_SIZE_2_Msk                             /*!< </spirit:description> */
#define SYSCFG_MIDR2_NVM_SIZE_1_Pos                          (27U)
#define SYSCFG_MIDR2_NVM_SIZE_1_Msk                          (0xFUL << SYSCFG_MIDR2_NVM_SIZE_1_Pos)                   /*!< 0x78000000 */
#define SYSCFG_MIDR2_NVM_SIZE_1                              SYSCFG_MIDR2_NVM_SIZE_1_Msk                             /*!< </spirit:description> */
#define SYSCFG_MIDR2_SF_Pos                                  (31U)
#define SYSCFG_MIDR2_SF_Msk                                  (0x1UL << SYSCFG_MIDR2_SF_Pos)                           /*!< 0x80000000 */
#define SYSCFG_MIDR2_SF                                      SYSCFG_MIDR2_SF_Msk                                     /*!< </spirit:description> */

/****************  Bit definition for SYSCFG_EXTICR register  *****************/
#define SYSCFG_EXTICR_EXTI0_Pos                              (0U)
#define SYSCFG_EXTICR_EXTI0_Msk                              (0xFUL << SYSCFG_EXTICR_EXTI0_Pos)                       /*!< 0x0000000F */
#define SYSCFG_EXTICR_EXTI0                                  SYSCFG_EXTICR_EXTI0_Msk                                 /*!< </spirit:description> */
#define SYSCFG_EXTICR_EXTI1_Pos                              (4U)
#define SYSCFG_EXTICR_EXTI1_Msk                              (0xFUL << SYSCFG_EXTICR_EXTI1_Pos)                       /*!< 0x000000F0 */
#define SYSCFG_EXTICR_EXTI1                                  SYSCFG_EXTICR_EXTI1_Msk                                 /*!< </spirit:description> */
#define SYSCFG_EXTICR_EXTI2_Pos                              (8U)
#define SYSCFG_EXTICR_EXTI2_Msk                              (0xFUL << SYSCFG_EXTICR_EXTI2_Pos)                       /*!< 0x00000F00 */
#define SYSCFG_EXTICR_EXTI2                                  SYSCFG_EXTICR_EXTI2_Msk                                 /*!< </spirit:description> */
#define SYSCFG_EXTICR_EXTI3_Pos                              (12U)
#define SYSCFG_EXTICR_EXTI3_Msk                              (0xFUL << SYSCFG_EXTICR_EXTI3_Pos)                       /*!< 0x0000F000 */
#define SYSCFG_EXTICR_EXTI3                                  SYSCFG_EXTICR_EXTI3_Msk                                 /*!< </spirit:description> */

/**********  Bit definition for SYSCFG_SDADCX_EXT_GATE_SEL register  **********/
#define SYSCFG_SDADCX_EXT_GATE_SEL_SDADC1_EXT_GATE_SEL_Pos   (0U)
#define SYSCFG_SDADCX_EXT_GATE_SEL_SDADC1_EXT_GATE_SEL_Msk   (0xFUL << SYSCFG_SDADCX_EXT_GATE_SEL_SDADC1_EXT_GATE_SEL_Pos)    /*!< 0x0000000F */
#define SYSCFG_SDADCX_EXT_GATE_SEL_SDADC1_EXT_GATE_SEL       SYSCFG_SDADCX_EXT_GATE_SEL_SDADC1_EXT_GATE_SEL_Msk      /*!< </spirit:description> */
#define SYSCFG_SDADCX_EXT_GATE_SEL_SDADC1_EXT_GATE_SEL_0     (0x1UL << SYSCFG_SDADCX_EXT_GATE_SEL_SDADC1_EXT_GATE_SEL_Pos)    /*!< 0x00000001 */
#define SYSCFG_SDADCX_EXT_GATE_SEL_SDADC1_EXT_GATE_SEL_1     (0x2UL << SYSCFG_SDADCX_EXT_GATE_SEL_SDADC1_EXT_GATE_SEL_Pos)    /*!< 0x00000002 */
#define SYSCFG_SDADCX_EXT_GATE_SEL_SDADC1_EXT_GATE_SEL_2     (0x4UL << SYSCFG_SDADCX_EXT_GATE_SEL_SDADC1_EXT_GATE_SEL_Pos)    /*!< 0x00000004 */
#define SYSCFG_SDADCX_EXT_GATE_SEL_SDADC1_EXT_GATE_SEL_3     (0x8UL << SYSCFG_SDADCX_EXT_GATE_SEL_SDADC1_EXT_GATE_SEL_Pos)    /*!< 0x00000008 */
#define SYSCFG_SDADCX_EXT_GATE_SEL_SDADC2_EXT_GATE_SEL_Pos   (16U)
#define SYSCFG_SDADCX_EXT_GATE_SEL_SDADC2_EXT_GATE_SEL_Msk   (0xFUL << SYSCFG_SDADCX_EXT_GATE_SEL_SDADC2_EXT_GATE_SEL_Pos)    /*!< 0x000F0000 */
#define SYSCFG_SDADCX_EXT_GATE_SEL_SDADC2_EXT_GATE_SEL       SYSCFG_SDADCX_EXT_GATE_SEL_SDADC2_EXT_GATE_SEL_Msk      /*!< </spirit:description> */
#define SYSCFG_SDADCX_EXT_GATE_SEL_SDADC2_EXT_GATE_SEL_0     (0x1UL << SYSCFG_SDADCX_EXT_GATE_SEL_SDADC2_EXT_GATE_SEL_Pos)    /*!< 0x00010000 */
#define SYSCFG_SDADCX_EXT_GATE_SEL_SDADC2_EXT_GATE_SEL_1     (0x2UL << SYSCFG_SDADCX_EXT_GATE_SEL_SDADC2_EXT_GATE_SEL_Pos)    /*!< 0x00020000 */
#define SYSCFG_SDADCX_EXT_GATE_SEL_SDADC2_EXT_GATE_SEL_2     (0x4UL << SYSCFG_SDADCX_EXT_GATE_SEL_SDADC2_EXT_GATE_SEL_Pos)    /*!< 0x00040000 */
#define SYSCFG_SDADCX_EXT_GATE_SEL_SDADC2_EXT_GATE_SEL_3     (0x8UL << SYSCFG_SDADCX_EXT_GATE_SEL_SDADC2_EXT_GATE_SEL_Pos)    /*!< 0x00080000 */

/**************  Bit definition for SYSCFG_ADC_BIASEN register  ***************/
#define SYSCFG_ADC_BIASEN_GLOBAL_BIAS_EN_Pos                 (0U)
#define SYSCFG_ADC_BIASEN_GLOBAL_BIAS_EN_Msk                 (0x1UL << SYSCFG_ADC_BIASEN_GLOBAL_BIAS_EN_Pos)          /*!< 0x00000001 */
#define SYSCFG_ADC_BIASEN_GLOBAL_BIAS_EN                     SYSCFG_ADC_BIASEN_GLOBAL_BIAS_EN_Msk                    /*!< </spirit:description> */

/*************  Bit definition for SYSCFG_FCCU_FILTER1 register  **************/
#define SYSCFG_FCCU_FILTER1_FILTER_WIDTH_Pos                 (29U)
#define SYSCFG_FCCU_FILTER1_FILTER_WIDTH_Msk                 (0x3UL << SYSCFG_FCCU_FILTER1_FILTER_WIDTH_Pos)          /*!< 0x60000000 */
#define SYSCFG_FCCU_FILTER1_FILTER_WIDTH                     SYSCFG_FCCU_FILTER1_FILTER_WIDTH_Msk                    /*!< </spirit:description> */
#define SYSCFG_FCCU_FILTER1_FILTER_WIDTH_0                   (0x1UL << SYSCFG_FCCU_FILTER1_FILTER_WIDTH_Pos)          /*!< 0x20000000 */
#define SYSCFG_FCCU_FILTER1_FILTER_WIDTH_1                   (0x2UL << SYSCFG_FCCU_FILTER1_FILTER_WIDTH_Pos)          /*!< 0x40000000 */
#define SYSCFG_FCCU_FILTER1_FILTER_BYPASS_Pos                (31U)
#define SYSCFG_FCCU_FILTER1_FILTER_BYPASS_Msk                (0x1UL << SYSCFG_FCCU_FILTER1_FILTER_BYPASS_Pos)         /*!< 0x80000000 */
#define SYSCFG_FCCU_FILTER1_FILTER_BYPASS                    SYSCFG_FCCU_FILTER1_FILTER_BYPASS_Msk                   /*!< </spirit:description> */

/*************  Bit definition for SYSCFG_FCCU_FILTER2 register  **************/
#define SYSCFG_FCCU_FILTER2_FILTER_WIDTH_Pos                 (29U)
#define SYSCFG_FCCU_FILTER2_FILTER_WIDTH_Msk                 (0x3UL << SYSCFG_FCCU_FILTER2_FILTER_WIDTH_Pos)          /*!< 0x60000000 */
#define SYSCFG_FCCU_FILTER2_FILTER_WIDTH                     SYSCFG_FCCU_FILTER2_FILTER_WIDTH_Msk                    /*!< </spirit:description> */
#define SYSCFG_FCCU_FILTER2_FILTER_WIDTH_0                   (0x1UL << SYSCFG_FCCU_FILTER2_FILTER_WIDTH_Pos)          /*!< 0x20000000 */
#define SYSCFG_FCCU_FILTER2_FILTER_WIDTH_1                   (0x2UL << SYSCFG_FCCU_FILTER2_FILTER_WIDTH_Pos)          /*!< 0x40000000 */
#define SYSCFG_FCCU_FILTER2_FILTER_BYPASS_Pos                (31U)
#define SYSCFG_FCCU_FILTER2_FILTER_BYPASS_Msk                (0x1UL << SYSCFG_FCCU_FILTER2_FILTER_BYPASS_Pos)         /*!< 0x80000000 */
#define SYSCFG_FCCU_FILTER2_FILTER_BYPASS                    SYSCFG_FCCU_FILTER2_FILTER_BYPASS_Msk                   /*!< </spirit:description> */

/*************  Bit definition for SYSCFG_ST_VREF_SEL1 register  **************/
#define SYSCFG_ST_VREF_SEL1_COMP_TESTVREF_SEL_Pos            (0U)
#define SYSCFG_ST_VREF_SEL1_COMP_TESTVREF_SEL_Msk            (0x3UL << SYSCFG_ST_VREF_SEL1_COMP_TESTVREF_SEL_Pos)     /*!< 0x00000003 */
#define SYSCFG_ST_VREF_SEL1_COMP_TESTVREF_SEL                SYSCFG_ST_VREF_SEL1_COMP_TESTVREF_SEL_Msk               /*!< </spirit:description> */
#define SYSCFG_ST_VREF_SEL1_COMP_TESTVREF_SEL_0              (0x1UL << SYSCFG_ST_VREF_SEL1_COMP_TESTVREF_SEL_Pos)     /*!< 0x00000001 */
#define SYSCFG_ST_VREF_SEL1_COMP_TESTVREF_SEL_1              (0x2UL << SYSCFG_ST_VREF_SEL1_COMP_TESTVREF_SEL_Pos)     /*!< 0x00000002 */
#define SYSCFG_ST_VREF_SEL1_SELFTEST_EN_Pos                  (15U)
#define SYSCFG_ST_VREF_SEL1_SELFTEST_EN_Msk                  (0x1UL << SYSCFG_ST_VREF_SEL1_SELFTEST_EN_Pos)           /*!< 0x00008000 */
#define SYSCFG_ST_VREF_SEL1_SELFTEST_EN                      SYSCFG_ST_VREF_SEL1_SELFTEST_EN_Msk                     /*!< </spirit:description> */
#define SYSCFG_ST_VREF_SEL1_COMPBIAS_EN_Pos                  (31U)
#define SYSCFG_ST_VREF_SEL1_COMPBIAS_EN_Msk                  (0x1UL << SYSCFG_ST_VREF_SEL1_COMPBIAS_EN_Pos)           /*!< 0x80000000 */
#define SYSCFG_ST_VREF_SEL1_COMPBIAS_EN                      SYSCFG_ST_VREF_SEL1_COMPBIAS_EN_Msk                     /*!< </spirit:description> */

/*************  Bit definition for SYSCFG_ST_VREF_SEL2 register  **************/
#define SYSCFG_ST_VREF_SEL2_SAR_TESTVREF_SEL_Pos             (0U)
#define SYSCFG_ST_VREF_SEL2_SAR_TESTVREF_SEL_Msk             (0x3UL << SYSCFG_ST_VREF_SEL2_SAR_TESTVREF_SEL_Pos)      /*!< 0x00000003 */
#define SYSCFG_ST_VREF_SEL2_SAR_TESTVREF_SEL                 SYSCFG_ST_VREF_SEL2_SAR_TESTVREF_SEL_Msk                /*!< </spirit:description> */
#define SYSCFG_ST_VREF_SEL1_SAR_TESTVREF_SEL_0               (0x1UL << SYSCFG_ST_VREF_SEL2_SAR_TESTVREF_SEL_Pos)      /*!< 0x00000001 */
#define SYSCFG_ST_VREF_SEL1_SAR_TESTVREF_SEL_1               (0x2UL << SYSCFG_ST_VREF_SEL2_SAR_TESTVREF_SEL_Pos)      /*!< 0x00000002 */
#define SYSCFG_ST_VREF_SEL2_SELFTEST_EN_Pos                  (15U)
#define SYSCFG_ST_VREF_SEL2_SELFTEST_EN_Msk                  (0x1UL << SYSCFG_ST_VREF_SEL2_SELFTEST_EN_Pos)           /*!< 0x00008000 */
#define SYSCFG_ST_VREF_SEL2_SELFTEST_EN                      SYSCFG_ST_VREF_SEL2_SELFTEST_EN_Msk                     /*!< </spirit:description> */
#define SYSCFG_ST_VREF_SEL2_SARBIAS_EN_Pos                   (31U)
#define SYSCFG_ST_VREF_SEL2_SARBIAS_EN_Msk                   (0x1UL << SYSCFG_ST_VREF_SEL2_SARBIAS_EN_Pos)            /*!< 0x80000000 */
#define SYSCFG_ST_VREF_SEL2_SARBIAS_EN                       SYSCFG_ST_VREF_SEL2_SARBIAS_EN_Msk                      /*!< </spirit:description> */

/***********  Bit definition for SYSCFG_HRTIMX_UPDATE_EN register  ************/
#define SYSCFG_HRTIMX_UPDATE_EN_UPDATE_EN_Pos                (0U)
#define SYSCFG_HRTIMX_UPDATE_EN_UPDATE_EN_Msk                (0x1UL << SYSCFG_HRTIMX_UPDATE_EN_UPDATE_EN_Pos)         /*!< 0x00000001 */
#define SYSCFG_HRTIMX_UPDATE_EN_UPDATE_EN                    SYSCFG_HRTIMX_UPDATE_EN_UPDATE_EN_Msk                   /*!< </spirit:description> */

/*********  Bit definition for SYSCFG_HRTIMXFLT_TIMXBRK_EN register  **********/
#define SYSCFG_HRTIMXFLT_TIMXBRK_EN_HRTIMERX_FLT_EN_Pos      (0U)
#define SYSCFG_HRTIMXFLT_TIMXBRK_EN_HRTIMERX_FLT_EN_Msk      (0x1UL << SYSCFG_HRTIMXFLT_TIMXBRK_EN_HRTIMERX_FLT_EN_Pos) /*!< 0x00000001 */
#define SYSCFG_HRTIMXFLT_TIMXBRK_EN_HRTIMERX_FLT_EN          SYSCFG_HRTIMXFLT_TIMXBRK_EN_HRTIMERX_FLT_EN_Msk         /*!< </spirit:description> */
#define SYSCFG_HRTIMXFLT_TIMXBRK_EN_HRTIMERX_SAFEMODE_EN_Pos (1U)
#define SYSCFG_HRTIMXFLT_TIMXBRK_EN_HRTIMERX_SAFEMODE_EN_Msk (0x1UL << SYSCFG_HRTIMXFLT_TIMXBRK_EN_HRTIMERX_SAFEMODE_EN_Pos)      /*!< 0x00000002 */
#define SYSCFG_HRTIMXFLT_TIMXBRK_EN_HRTIMERX_SAFEMODE_EN     SYSCFG_HRTIMXFLT_TIMXBRK_EN_HRTIMERX_SAFEMODE_EN_Msk    /*!< </spirit:description> */
#define SYSCFG_HRTIMXFLT_TIMXBRK_EN_TIMX_FLT_EN_Pos          (2U)
#define SYSCFG_HRTIMXFLT_TIMXBRK_EN_TIMX_FLT_EN_Msk          (0x1UL << SYSCFG_HRTIMXFLT_TIMXBRK_EN_TIMX_FLT_EN_Pos)   /*!< 0x00000004 */
#define SYSCFG_HRTIMXFLT_TIMXBRK_EN_TIMX_FLT_EN              SYSCFG_HRTIMXFLT_TIMXBRK_EN_TIMX_FLT_EN_Msk             /*!< </spirit:description> */
#define SYSCFG_HRTIMXFLT_TIMXBRK_EN_TIMX_SAFEMODE_EN_Pos     (3U)
#define SYSCFG_HRTIMXFLT_TIMXBRK_EN_TIMX_SAFEMODE_EN_Msk     (0x1UL << SYSCFG_HRTIMXFLT_TIMXBRK_EN_TIMX_SAFEMODE_EN_Pos)  /*!< 0x00000008 */
#define SYSCFG_HRTIMXFLT_TIMXBRK_EN_TIMX_SAFEMODE_EN         SYSCFG_HRTIMXFLT_TIMXBRK_EN_TIMX_SAFEMODE_EN_Msk        /*!< </spirit:description> */

#define SYSCFG_BASE           0x42000000UL 


#define SYSCFG                ((SYSCFG_TypeDef *) SYSCFG_BASE) 


#endif /* __SR5E1_SYSCFG_H */

