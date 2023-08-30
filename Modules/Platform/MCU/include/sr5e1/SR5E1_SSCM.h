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

#ifndef __SR5E1_SSCM_H
#define __SR5E1_SSCM_H

/******************************************************************************/
/*                                                                            */
/*                                SSCM (SSCM)                                 */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO uint32_t STATUS;        /*!< STATUS   Address offset: 0x00 */
  __I  uint32_t ERROR;         /*!< ERROR    Address offset: 0x04 */
       uint32_t RESERVED0[6];  /*!< Reserved Address offset: 0x08-0x1C */
  __I  uint32_t UOPS;          /*!< UOPS     Address offset: 0x20 */
       uint32_t RESERVED1[4];  /*!< Reserved Address offset: 0x24-0x30 */
  __I  uint32_t LCSTAT;        /*!< LCSTAT   Address offset: 0x34 */
  __I  uint32_t OSAL;          /*!< OSAL     Address offset: 0x38 */
       uint32_t RESERVED2[4];  /*!< Reserved Address offset: 0x3C-0x48 */
  __I  uint32_t NACLA;         /*!< NACLA    Address offset: 0x4C */
} SSCM_TypeDef;


/*****************  Bit definition for SSCM_STATUS register  ******************/
#define SSCM_STATUS_MREV_Pos                      (1U)
#define SSCM_STATUS_MREV_Msk                      (0xFUL << SSCM_STATUS_MREV_Pos)           /*!< 0x0000001E */
#define SSCM_STATUS_MREV                          SSCM_STATUS_MREV_Msk                     /*!< </spirit:description> */
#define SSCM_STATUS_JPIN_Pos                      (6U)
#define SSCM_STATUS_JPIN_Msk                      (0x3FFUL << SSCM_STATUS_JPIN_Pos)         /*!< 0x0000FFC0 */
#define SSCM_STATUS_JPIN                          SSCM_STATUS_JPIN_Msk                     /*!< </spirit:description> */
#define SSCM_STATUS_CER_Pos                       (30U)
#define SSCM_STATUS_CER_Msk                       (0x1UL << SSCM_STATUS_CER_Pos)            /*!< 0x40000000 */
#define SSCM_STATUS_CER                           SSCM_STATUS_CER_Msk                      /*!< </spirit:description> */

/******************  Bit definition for SSCM_ERROR register  ******************/
#define SSCM_ERROR_OTA_ER_Pos                     (2U)
#define SSCM_ERROR_OTA_ER_Msk                     (0x1UL << SSCM_ERROR_OTA_ER_Pos)          /*!< 0x00000004 */
#define SSCM_ERROR_OTA_ER                         SSCM_ERROR_OTA_ER_Msk                    /*!< </spirit:description> */

/******************  Bit definition for SSCM_UOPS register  *******************/
#define SSCM_UOPS_XOSC_Pos                        (0U)
#define SSCM_UOPS_XOSC_Msk                        (0x1UL << SSCM_UOPS_XOSC_Pos)             /*!< 0x00000001 */
#define SSCM_UOPS_XOSC                            SSCM_UOPS_XOSC_Msk                       /*!< </spirit:description> */
#define SSCM_UOPS_HSB_Pos                         (1U)
#define SSCM_UOPS_HSB_Msk                         (0x7UL << SSCM_UOPS_HSB_Pos)              /*!< 0x0000000E */
#define SSCM_UOPS_HSB                             SSCM_UOPS_HSB_Msk                        /*!< </spirit:description> */
#define SSCM_UOPS_FTMPL_Pos                       (8U)
#define SSCM_UOPS_FTMPL_Msk                       (0x1UL << SSCM_UOPS_FTMPL_Pos)            /*!< 0x00000100 */
#define SSCM_UOPS_FTMPL                           SSCM_UOPS_FTMPL_Msk                      /*!< </spirit:description> */
#define SSCM_UOPS_FTMPE_Pos                       (9U)
#define SSCM_UOPS_FTMPE_Msk                       (0x1UL << SSCM_UOPS_FTMPE_Pos)            /*!< 0x00000200 */
#define SSCM_UOPS_FTMPE                           SSCM_UOPS_FTMPE_Msk                      /*!< </spirit:description> */
#define SSCM_UOPS_RTE_Pos                         (10U)
#define SSCM_UOPS_RTE_Msk                         (0x1UL << SSCM_UOPS_RTE_Pos)              /*!< 0x00000400 */
#define SSCM_UOPS_RTE                             SSCM_UOPS_RTE_Msk                        /*!< </spirit:description> */
#define SSCM_UOPS_BAF_FA_Pos                      (15U)
#define SSCM_UOPS_BAF_FA_Msk                      (0x1UL << SSCM_UOPS_BAF_FA_Pos)           /*!< 0x00008000 */
#define SSCM_UOPS_BAF_FA                          SSCM_UOPS_BAF_FA_Msk                     /*!< </spirit:description> */
#define SSCM_UOPS_HSM_EN_FA_Pos                   (26U)
#define SSCM_UOPS_HSM_EN_FA_Msk                   (0x1UL << SSCM_UOPS_HSM_EN_FA_Pos)        /*!< 0x04000000 */
#define SSCM_UOPS_HSM_EN_FA                       SSCM_UOPS_HSM_EN_FA_Msk                  /*!< </spirit:description> */
#define SSCM_UOPS_IWDG1_HW_EN_Pos                 (28U)
#define SSCM_UOPS_IWDG1_HW_EN_Msk                 (0x1UL << SSCM_UOPS_IWDG1_HW_EN_Pos)      /*!< 0x10000000 */
#define SSCM_UOPS_IWDG1_HW_EN                     SSCM_UOPS_IWDG1_HW_EN_Msk                /*!< </spirit:description> */
#define SSCM_UOPS_IWDG2_HW_EN_Pos                 (29U)
#define SSCM_UOPS_IWDG2_HW_EN_Msk                 (0x1UL << SSCM_UOPS_IWDG2_HW_EN_Pos)      /*!< 0x20000000 */
#define SSCM_UOPS_IWDG2_HW_EN                     SSCM_UOPS_IWDG2_HW_EN_Msk                /*!< </spirit:description> */

/*****************  Bit definition for SSCM_LCSTAT register  ******************/
#define SSCM_LCSTAT_LC_Pos                        (0U)
#define SSCM_LCSTAT_LC_Msk                        (0x7UL << SSCM_LCSTAT_LC_Pos)             /*!< 0x00000007 */
#define SSCM_LCSTAT_LC                            SSCM_LCSTAT_LC_Msk                       /*!< </spirit:description> */

/******************  Bit definition for SSCM_OSAL register  *******************/
#define SSCM_OSAL_OTA_SIG_ADDR_Pos                (2U)
#define SSCM_OSAL_OTA_SIG_ADDR_Msk                (0x3FFFFFFFUL << SSCM_OSAL_OTA_SIG_ADDR_Pos)  /*!< 0xFFFFFFFC */
#define SSCM_OSAL_OTA_SIG_ADDR                    SSCM_OSAL_OTA_SIG_ADDR_Msk               /*!< </spirit:description> */

/******************  Bit definition for SSCM_NACLA register  ******************/
#define SSCM_NACLA_NON_ACTIVE_LOGICAL_ADDR_Pos    (0U)
#define SSCM_NACLA_NON_ACTIVE_LOGICAL_ADDR_Msk    (0xFFFFFFFFUL << SSCM_NACLA_NON_ACTIVE_LOGICAL_ADDR_Pos)              /*!< 0xFFFFFFFF */
#define SSCM_NACLA_NON_ACTIVE_LOGICAL_ADDR        SSCM_NACLA_NON_ACTIVE_LOGICAL_ADDR_Msk   /*!< </spirit:description> */

#define SSCM_BASE           0x4001EC00UL 


#define SSCM                ((SSCM_TypeDef *) SSCM_BASE) 


#endif /* __SR5E1_SSCM_H */

