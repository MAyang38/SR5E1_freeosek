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

#ifndef __SR5E1_I2C_H
#define __SR5E1_I2C_H

/******************************************************************************/
/*                                                                            */
/*                                 I2C (I2C)                                  */
/*                                                                            */
/******************************************************************************/
typedef struct
{
  __IO uint32_t CR1;       /*!< CR1      Address offset: 0x00 */
  __IO uint32_t CR2;       /*!< CR2      Address offset: 0x04 */
  __IO uint32_t OAR1;      /*!< OAR1     Address offset: 0x08 */
  __IO uint32_t OAR2;      /*!< OAR2     Address offset: 0x0C */
  __IO uint32_t TIMINGR;   /*!< TIMINGR  Address offset: 0x10 */
  __IO uint32_t TIMEOUTR;  /*!< TIMEOUTR Address offset: 0x14 */
  __IO uint32_t ISR;       /*!< ISR      Address offset: 0x18 */
  __IO uint32_t ICR;       /*!< ICR      Address offset: 0x1C */
  __IO uint32_t PECR;      /*!< PECR     Address offset: 0x20 */
  __IO uint32_t RXDR;      /*!< RXDR     Address offset: 0x24 */
  __IO uint32_t TXDR;      /*!< TXDR     Address offset: 0x28 */
} I2C_TypeDef;


/*******************  Bit definition for I2C_CR1 register  ********************/
#define I2C_CR1_PE_Pos               (0U)
#define I2C_CR1_PE_Msk               (0x1UL << I2C_CR1_PE_Pos)    /*!< 0x00000001 */
#define I2C_CR1_PE                   I2C_CR1_PE_Msk              /*!< </spirit:description> */
#define I2C_CR1_TXIE_Pos             (1U)
#define I2C_CR1_TXIE_Msk             (0x1UL << I2C_CR1_TXIE_Pos)  /*!< 0x00000002 */
#define I2C_CR1_TXIE                 I2C_CR1_TXIE_Msk            /*!< </spirit:description> */
#define I2C_CR1_RXIE_Pos             (2U)
#define I2C_CR1_RXIE_Msk             (0x1UL << I2C_CR1_RXIE_Pos)  /*!< 0x00000004 */
#define I2C_CR1_RXIE                 I2C_CR1_RXIE_Msk            /*!< </spirit:description> */
#define I2C_CR1_ADDRIE_Pos           (3U)
#define I2C_CR1_ADDRIE_Msk             (0x1UL << I2C_CR1_ADDRIE_Pos)  /*!< 0x00000008 */
#define I2C_CR1_ADDRIE               I2C_CR1_ADDRIE_Msk          /*!< </spirit:description> */
#define I2C_CR1_NACKIE_Pos           (4U)
#define I2C_CR1_NACKIE_Msk             (0x1UL << I2C_CR1_NACKIE_Pos)  /*!< 0x00000010 */
#define I2C_CR1_NACKIE               I2C_CR1_NACKIE_Msk          /*!< </spirit:description> */
#define I2C_CR1_STOPIE_Pos           (5U)
#define I2C_CR1_STOPIE_Msk             (0x1UL << I2C_CR1_STOPIE_Pos)  /*!< 0x00000020 */
#define I2C_CR1_STOPIE               I2C_CR1_STOPIE_Msk          /*!< </spirit:description> */
#define I2C_CR1_TCIE_Pos             (6U)
#define I2C_CR1_TCIE_Msk             (0x1UL << I2C_CR1_TCIE_Pos)  /*!< 0x00000040 */
#define I2C_CR1_TCIE                 I2C_CR1_TCIE_Msk            /*!< </spirit:description> */
#define I2C_CR1_ERRIE_Pos            (7U)
#define I2C_CR1_ERRIE_Msk            (0x1UL << I2C_CR1_ERRIE_Pos) /*!< 0x00000080 */
#define I2C_CR1_ERRIE                I2C_CR1_ERRIE_Msk           /*!< </spirit:description> */
#define I2C_CR1_DNF_Pos              (8U)
#define I2C_CR1_DNF_Msk              (0xFUL << I2C_CR1_DNF_Pos)   /*!< 0x00000F00 */
#define I2C_CR1_DNF                  I2C_CR1_DNF_Msk             /*!< </spirit:description> */
#define I2C_CR1_ANFOFF_Pos           (12U)
#define I2C_CR1_ANFOFF_Msk             (0x1UL << I2C_CR1_ANFOFF_Pos)  /*!< 0x00001000 */
#define I2C_CR1_ANFOFF               I2C_CR1_ANFOFF_Msk          /*!< </spirit:description> */
#define I2C_CR1_SWRST_Pos            (13U)
#define I2C_CR1_SWRST_Msk            (0x1UL << I2C_CR1_SWRST_Pos) /*!< 0x00002000 */
#define I2C_CR1_SWRST                I2C_CR1_SWRST_Msk           /*!< </spirit:description> */
#define I2C_CR1_TXDMAEN_Pos          (14U)
#define I2C_CR1_TXDMAEN_Msk          (0x1UL << I2C_CR1_TXDMAEN_Pos) /*!< 0x00004000 */
#define I2C_CR1_TXDMAEN              I2C_CR1_TXDMAEN_Msk         /*!< </spirit:description> */
#define I2C_CR1_RXDMAEN_Pos          (15U)
#define I2C_CR1_RXDMAEN_Msk          (0x1UL << I2C_CR1_RXDMAEN_Pos) /*!< 0x00008000 */
#define I2C_CR1_RXDMAEN              I2C_CR1_RXDMAEN_Msk         /*!< </spirit:description> */
#define I2C_CR1_SBC_Pos              (16U)
#define I2C_CR1_SBC_Msk              (0x1UL << I2C_CR1_SBC_Pos)   /*!< 0x00010000 */
#define I2C_CR1_SBC                  I2C_CR1_SBC_Msk             /*!< </spirit:description> */
#define I2C_CR1_NOSTRETCH_Pos        (17U)
#define I2C_CR1_NOSTRETCH_Msk        (0x1UL << I2C_CR1_NOSTRETCH_Pos)   /*!< 0x00020000 */
#define I2C_CR1_NOSTRETCH            I2C_CR1_NOSTRETCH_Msk       /*!< </spirit:description> */
#define I2C_CR1_WUPEN_Pos            (18U)
#define I2C_CR1_WUPEN_Msk            (0x1UL << I2C_CR1_WUPEN_Pos) /*!< 0x00040000 */
#define I2C_CR1_WUPEN                I2C_CR1_WUPEN_Msk           /*!< </spirit:description> */
#define I2C_CR1_GCEN_Pos             (19U)
#define I2C_CR1_GCEN_Msk             (0x1UL << I2C_CR1_GCEN_Pos)  /*!< 0x00080000 */
#define I2C_CR1_GCEN                 I2C_CR1_GCEN_Msk            /*!< </spirit:description> */
#define I2C_CR1_SMBHEN_Pos           (20U)
#define I2C_CR1_SMBHEN_Msk             (0x1UL << I2C_CR1_SMBHEN_Pos)  /*!< 0x00100000 */
#define I2C_CR1_SMBHEN               I2C_CR1_SMBHEN_Msk          /*!< </spirit:description> */
#define I2C_CR1_SMBDEN_Pos           (21U)
#define I2C_CR1_SMBDEN_Msk             (0x1UL << I2C_CR1_SMBDEN_Pos)  /*!< 0x00200000 */
#define I2C_CR1_SMBDEN               I2C_CR1_SMBDEN_Msk          /*!< </spirit:description> */
#define I2C_CR1_ALERTEN_Pos          (22U)
#define I2C_CR1_ALERTEN_Msk          (0x1UL << I2C_CR1_ALERTEN_Pos) /*!< 0x00400000 */
#define I2C_CR1_ALERTEN              I2C_CR1_ALERTEN_Msk         /*!< </spirit:description> */
#define I2C_CR1_PECEN_Pos            (23U)
#define I2C_CR1_PECEN_Msk            (0x1UL << I2C_CR1_PECEN_Pos) /*!< 0x00800000 */
#define I2C_CR1_PECEN                I2C_CR1_PECEN_Msk           /*!< </spirit:description> */

/*******************  Bit definition for I2C_CR2 register  ********************/
#define I2C_CR2_SADD_Pos             (0U)
#define I2C_CR2_SADD_Msk               (0x3FFUL << I2C_CR2_SADD_Pos)  /*!< 0x000003FF */
#define I2C_CR2_SADD                 I2C_CR2_SADD_Msk            /*!< </spirit:description> */
#define I2C_CR2_RD_WRN_Pos           (10U)
#define I2C_CR2_RD_WRN_Msk             (0x1UL << I2C_CR2_RD_WRN_Pos)  /*!< 0x00000400 */
#define I2C_CR2_RD_WRN               I2C_CR2_RD_WRN_Msk          /*!< </spirit:description> */
#define I2C_CR2_ADD10_Pos            (11U)
#define I2C_CR2_ADD10_Msk            (0x1UL << I2C_CR2_ADD10_Pos) /*!< 0x00000800 */
#define I2C_CR2_ADD10                I2C_CR2_ADD10_Msk           /*!< </spirit:description> */
#define I2C_CR2_HEAD10R_Pos          (12U)
#define I2C_CR2_HEAD10R_Msk          (0x1UL << I2C_CR2_HEAD10R_Pos) /*!< 0x00001000 */
#define I2C_CR2_HEAD10R              I2C_CR2_HEAD10R_Msk         /*!< </spirit:description> */
#define I2C_CR2_START_Pos            (13U)
#define I2C_CR2_START_Msk            (0x1UL << I2C_CR2_START_Pos) /*!< 0x00002000 */
#define I2C_CR2_START                I2C_CR2_START_Msk           /*!< </spirit:description> */
#define I2C_CR2_STOP_Pos             (14U)
#define I2C_CR2_STOP_Msk             (0x1UL << I2C_CR2_STOP_Pos)  /*!< 0x00004000 */
#define I2C_CR2_STOP                 I2C_CR2_STOP_Msk            /*!< </spirit:description> */
#define I2C_CR2_NACK_Pos             (15U)
#define I2C_CR2_NACK_Msk             (0x1UL << I2C_CR2_NACK_Pos)  /*!< 0x00008000 */
#define I2C_CR2_NACK                 I2C_CR2_NACK_Msk            /*!< </spirit:description> */
#define I2C_CR2_NBYTES_Pos           (16U)
#define I2C_CR2_NBYTES_Msk           (0xFFUL << I2C_CR2_NBYTES_Pos) /*!< 0x00FF0000 */
#define I2C_CR2_NBYTES               I2C_CR2_NBYTES_Msk          /*!< </spirit:description> */
#define I2C_CR2_RELOAD_Pos           (24U)
#define I2C_CR2_RELOAD_Msk             (0x1UL << I2C_CR2_RELOAD_Pos)  /*!< 0x01000000 */
#define I2C_CR2_RELOAD               I2C_CR2_RELOAD_Msk          /*!< </spirit:description> */
#define I2C_CR2_AUTOEND_Pos          (25U)
#define I2C_CR2_AUTOEND_Msk          (0x1UL << I2C_CR2_AUTOEND_Pos) /*!< 0x02000000 */
#define I2C_CR2_AUTOEND              I2C_CR2_AUTOEND_Msk         /*!< </spirit:description> */
#define I2C_CR2_PECBYTE_Pos          (26U)
#define I2C_CR2_PECBYTE_Msk          (0x1UL << I2C_CR2_PECBYTE_Pos) /*!< 0x04000000 */
#define I2C_CR2_PECBYTE              I2C_CR2_PECBYTE_Msk         /*!< </spirit:description> */

/*******************  Bit definition for I2C_OAR1 register  *******************/
#define I2C_OAR1_OA1_Pos             (0U)
#define I2C_OAR1_OA1_Msk               (0x3FFUL << I2C_OAR1_OA1_Pos)  /*!< 0x000003FF */
#define I2C_OAR1_OA1                 I2C_OAR1_OA1_Msk            /*!< </spirit:description> */
#define I2C_OAR1_OA1MODE_Pos         (10U)
#define I2C_OAR1_OA1MODE_Msk         (0x1UL << I2C_OAR1_OA1MODE_Pos)  /*!< 0x00000400 */
#define I2C_OAR1_OA1MODE             I2C_OAR1_OA1MODE_Msk        /*!< </spirit:description> */
#define I2C_OAR1_OA1EN_Pos           (15U)
#define I2C_OAR1_OA1EN_Msk             (0x1UL << I2C_OAR1_OA1EN_Pos)  /*!< 0x00008000 */
#define I2C_OAR1_OA1EN               I2C_OAR1_OA1EN_Msk          /*!< </spirit:description> */

/*******************  Bit definition for I2C_OAR2 register  *******************/
#define I2C_OAR2_OA2_Pos             (1U)
#define I2C_OAR2_OA2_Msk             (0x7FUL << I2C_OAR2_OA2_Pos) /*!< 0x000000FE */
#define I2C_OAR2_OA2                 I2C_OAR2_OA2_Msk            /*!< </spirit:description> */
#define I2C_OAR2_OA2MSK_Pos          (8U)
#define I2C_OAR2_OA2MSK_Msk          (0x7UL << I2C_OAR2_OA2MSK_Pos) /*!< 0x00000700 */
#define I2C_OAR2_OA2MSK              I2C_OAR2_OA2MSK_Msk         /*!< </spirit:description> */
#define I2C_OAR2_OA2NOMASK           (0x0UL << I2C_OAR2_OA2MSK_Pos)   /*!< 0x00000000 */
#define I2C_OAR2_OA2MASK01           (0x1UL << I2C_OAR2_OA2MSK_Pos)   /*!< 0x00000100 */
#define I2C_OAR2_OA2MASK02           (0x2UL << I2C_OAR2_OA2MSK_Pos)   /*!< 0x00000200 */
#define I2C_OAR2_OA2MASK03           (0x3UL << I2C_OAR2_OA2MSK_Pos)   /*!< 0x00000300 */
#define I2C_OAR2_OA2MASK04           (0x4UL << I2C_OAR2_OA2MSK_Pos)   /*!< 0x00000400 */
#define I2C_OAR2_OA2MASK05           (0x5UL << I2C_OAR2_OA2MSK_Pos)   /*!< 0x00000500 */
#define I2C_OAR2_OA2MASK06           (0x6UL << I2C_OAR2_OA2MSK_Pos)   /*!< 0x00000600 */
#define I2C_OAR2_OA2MASK07           (0x7UL << I2C_OAR2_OA2MSK_Pos)   /*!< 0x00000700 */
#define I2C_OAR2_OA2EN_Pos           (15U)
#define I2C_OAR2_OA2EN_Msk           (0x1UL << I2C_OAR2_OA2EN_Pos)  /*!< 0x00008000 */
#define I2C_OAR2_OA2EN               I2C_OAR2_OA2EN_Msk          /*!< </spirit:description> */

/*****************  Bit definition for I2C_TIMINGR register  ******************/
#define I2C_TIMINGR_SCLL_Pos         (0U)
#define I2C_TIMINGR_SCLL_Msk         (0xFFUL << I2C_TIMINGR_SCLL_Pos)   /*!< 0x000000FF */
#define I2C_TIMINGR_SCLL             I2C_TIMINGR_SCLL_Msk        /*!< </spirit:description> */
#define I2C_TIMINGR_SCLH_Pos         (8U)
#define I2C_TIMINGR_SCLH_Msk         (0xFFUL << I2C_TIMINGR_SCLH_Pos)   /*!< 0x0000FF00 */
#define I2C_TIMINGR_SCLH             I2C_TIMINGR_SCLH_Msk        /*!< </spirit:description> */
#define I2C_TIMINGR_SDADEL_Pos       (16U)
#define I2C_TIMINGR_SDADEL_Msk       (0xFUL << I2C_TIMINGR_SDADEL_Pos)    /*!< 0x000F0000 */
#define I2C_TIMINGR_SDADEL           I2C_TIMINGR_SDADEL_Msk      /*!< </spirit:description> */
#define I2C_TIMINGR_SCLDEL_Pos       (20U)
#define I2C_TIMINGR_SCLDEL_Msk       (0xFUL << I2C_TIMINGR_SCLDEL_Pos)    /*!< 0x00F00000 */
#define I2C_TIMINGR_SCLDEL           I2C_TIMINGR_SCLDEL_Msk      /*!< </spirit:description> */
#define I2C_TIMINGR_PRESC_Pos        (28U)
#define I2C_TIMINGR_PRESC_Msk        (0xFUL << I2C_TIMINGR_PRESC_Pos)   /*!< 0xF0000000 */
#define I2C_TIMINGR_PRESC            I2C_TIMINGR_PRESC_Msk       /*!< </spirit:description> */

/*****************  Bit definition for I2C_TIMEOUTR register  *****************/
#define I2C_TIMEOUTR_TIMEOUTA_Pos    (0U)
#define I2C_TIMEOUTR_TIMEOUTA_Msk    (0xFFFUL << I2C_TIMEOUTR_TIMEOUTA_Pos)         /*!< 0x00000FFF */
#define I2C_TIMEOUTR_TIMEOUTA        I2C_TIMEOUTR_TIMEOUTA_Msk   /*!< </spirit:description> */
#define I2C_TIMEOUTR_TIDLE_Pos       (12U)
#define I2C_TIMEOUTR_TIDLE_Msk       (0x1UL << I2C_TIMEOUTR_TIDLE_Pos)    /*!< 0x00001000 */
#define I2C_TIMEOUTR_TIDLE           I2C_TIMEOUTR_TIDLE_Msk      /*!< </spirit:description> */
#define I2C_TIMEOUTR_TIMOUTEN_Pos    (15U)
#define I2C_TIMEOUTR_TIMOUTEN_Msk    (0x1UL << I2C_TIMEOUTR_TIMOUTEN_Pos)       /*!< 0x00008000 */
#define I2C_TIMEOUTR_TIMOUTEN        I2C_TIMEOUTR_TIMOUTEN_Msk   /*!< </spirit:description> */
#define I2C_TIMEOUTR_TIMEOUTB_Pos    (16U)
#define I2C_TIMEOUTR_TIMEOUTB_Msk    (0xFFFUL << I2C_TIMEOUTR_TIMEOUTB_Pos)         /*!< 0x0FFF0000 */
#define I2C_TIMEOUTR_TIMEOUTB        I2C_TIMEOUTR_TIMEOUTB_Msk   /*!< </spirit:description> */
#define I2C_TIMEOUTR_TEXTEN_Pos      (31U)
#define I2C_TIMEOUTR_TEXTEN_Msk      (0x1UL << I2C_TIMEOUTR_TEXTEN_Pos)     /*!< 0x80000000 */
#define I2C_TIMEOUTR_TEXTEN          I2C_TIMEOUTR_TEXTEN_Msk     /*!< </spirit:description> */

/*******************  Bit definition for I2C_ISR register  ********************/
#define I2C_ISR_TXE_Pos              (0U)
#define I2C_ISR_TXE_Msk              (0x1UL << I2C_ISR_TXE_Pos)   /*!< 0x00000001 */
#define I2C_ISR_TXE                  I2C_ISR_TXE_Msk             /*!< </spirit:description> */
#define I2C_ISR_TXIS_Pos             (1U)
#define I2C_ISR_TXIS_Msk             (0x1UL << I2C_ISR_TXIS_Pos)  /*!< 0x00000002 */
#define I2C_ISR_TXIS                 I2C_ISR_TXIS_Msk            /*!< </spirit:description> */
#define I2C_ISR_RXNE_Pos             (2U)
#define I2C_ISR_RXNE_Msk             (0x1UL << I2C_ISR_RXNE_Pos)  /*!< 0x00000004 */
#define I2C_ISR_RXNE                 I2C_ISR_RXNE_Msk            /*!< </spirit:description> */
#define I2C_ISR_ADDR_Pos             (3U)
#define I2C_ISR_ADDR_Msk             (0x1UL << I2C_ISR_ADDR_Pos)  /*!< 0x00000008 */
#define I2C_ISR_ADDR                 I2C_ISR_ADDR_Msk            /*!< </spirit:description> */
#define I2C_ISR_NACKF_Pos            (4U)
#define I2C_ISR_NACKF_Msk            (0x1UL << I2C_ISR_NACKF_Pos) /*!< 0x00000010 */
#define I2C_ISR_NACKF                I2C_ISR_NACKF_Msk           /*!< </spirit:description> */
#define I2C_ISR_STOPF_Pos            (5U)
#define I2C_ISR_STOPF_Msk            (0x1UL << I2C_ISR_STOPF_Pos) /*!< 0x00000020 */
#define I2C_ISR_STOPF                I2C_ISR_STOPF_Msk           /*!< </spirit:description> */
#define I2C_ISR_TC_Pos               (6U)
#define I2C_ISR_TC_Msk               (0x1UL << I2C_ISR_TC_Pos)    /*!< 0x00000040 */
#define I2C_ISR_TC                   I2C_ISR_TC_Msk              /*!< </spirit:description> */
#define I2C_ISR_TCR_Pos              (7U)
#define I2C_ISR_TCR_Msk              (0x1UL << I2C_ISR_TCR_Pos)   /*!< 0x00000080 */
#define I2C_ISR_TCR                  I2C_ISR_TCR_Msk             /*!< </spirit:description> */
#define I2C_ISR_BERR_Pos             (8U)
#define I2C_ISR_BERR_Msk             (0x1UL << I2C_ISR_BERR_Pos)  /*!< 0x00000100 */
#define I2C_ISR_BERR                 I2C_ISR_BERR_Msk            /*!< </spirit:description> */
#define I2C_ISR_ARLO_Pos             (9U)
#define I2C_ISR_ARLO_Msk             (0x1UL << I2C_ISR_ARLO_Pos)  /*!< 0x00000200 */
#define I2C_ISR_ARLO                 I2C_ISR_ARLO_Msk            /*!< </spirit:description> */
#define I2C_ISR_OVR_Pos              (10U)
#define I2C_ISR_OVR_Msk              (0x1UL << I2C_ISR_OVR_Pos)   /*!< 0x00000400 */
#define I2C_ISR_OVR                  I2C_ISR_OVR_Msk             /*!< </spirit:description> */
#define I2C_ISR_PECERR_Pos           (11U)
#define I2C_ISR_PECERR_Msk             (0x1UL << I2C_ISR_PECERR_Pos)  /*!< 0x00000800 */
#define I2C_ISR_PECERR               I2C_ISR_PECERR_Msk          /*!< </spirit:description> */
#define I2C_ISR_TIMEOUT_Pos          (12U)
#define I2C_ISR_TIMEOUT_Msk          (0x1UL << I2C_ISR_TIMEOUT_Pos) /*!< 0x00001000 */
#define I2C_ISR_TIMEOUT              I2C_ISR_TIMEOUT_Msk         /*!< </spirit:description> */
#define I2C_ISR_ALERT_Pos            (13U)
#define I2C_ISR_ALERT_Msk            (0x1UL << I2C_ISR_ALERT_Pos) /*!< 0x00002000 */
#define I2C_ISR_ALERT                I2C_ISR_ALERT_Msk           /*!< </spirit:description> */
#define I2C_ISR_BUSY_Pos             (15U)
#define I2C_ISR_BUSY_Msk             (0x1UL << I2C_ISR_BUSY_Pos)  /*!< 0x00008000 */
#define I2C_ISR_BUSY                 I2C_ISR_BUSY_Msk            /*!< </spirit:description> */
#define I2C_ISR_DIR_Pos              (16U)
#define I2C_ISR_DIR_Msk              (0x1UL << I2C_ISR_DIR_Pos)   /*!< 0x00010000 */
#define I2C_ISR_DIR                  I2C_ISR_DIR_Msk             /*!< </spirit:description> */
#define I2C_ISR_ADDCODE_Pos          (17U)
#define I2C_ISR_ADDCODE_Msk          (0x7FUL << I2C_ISR_ADDCODE_Pos)  /*!< 0x00FE0000 */
#define I2C_ISR_ADDCODE              I2C_ISR_ADDCODE_Msk         /*!< </spirit:description> */

/*******************  Bit definition for I2C_ICR register  ********************/
#define I2C_ICR_ADDRCF_Pos           (3U)
#define I2C_ICR_ADDRCF_Msk             (0x1UL << I2C_ICR_ADDRCF_Pos)  /*!< 0x00000008 */
#define I2C_ICR_ADDRCF               I2C_ICR_ADDRCF_Msk          /*!< </spirit:description> */
#define I2C_ICR_NACKCF_Pos           (4U)
#define I2C_ICR_NACKCF_Msk             (0x1UL << I2C_ICR_NACKCF_Pos)  /*!< 0x00000010 */
#define I2C_ICR_NACKCF               I2C_ICR_NACKCF_Msk          /*!< </spirit:description> */
#define I2C_ICR_STOPCF_Pos           (5U)
#define I2C_ICR_STOPCF_Msk             (0x1UL << I2C_ICR_STOPCF_Pos)  /*!< 0x00000020 */
#define I2C_ICR_STOPCF               I2C_ICR_STOPCF_Msk          /*!< </spirit:description> */
#define I2C_ICR_BERRCF_Pos           (8U)
#define I2C_ICR_BERRCF_Msk             (0x1UL << I2C_ICR_BERRCF_Pos)  /*!< 0x00000100 */
#define I2C_ICR_BERRCF               I2C_ICR_BERRCF_Msk          /*!< </spirit:description> */
#define I2C_ICR_ARLOCF_Pos           (9U)
#define I2C_ICR_ARLOCF_Msk             (0x1UL << I2C_ICR_ARLOCF_Pos)  /*!< 0x00000200 */
#define I2C_ICR_ARLOCF               I2C_ICR_ARLOCF_Msk          /*!< </spirit:description> */
#define I2C_ICR_OVRCF_Pos            (10U)
#define I2C_ICR_OVRCF_Msk            (0x1UL << I2C_ICR_OVRCF_Pos) /*!< 0x00000400 */
#define I2C_ICR_OVRCF                I2C_ICR_OVRCF_Msk           /*!< </spirit:description> */
#define I2C_ICR_PECCF_Pos            (11U)
#define I2C_ICR_PECCF_Msk            (0x1UL << I2C_ICR_PECCF_Pos) /*!< 0x00000800 */
#define I2C_ICR_PECCF                I2C_ICR_PECCF_Msk           /*!< </spirit:description> */
#define I2C_ICR_TIMOUTCF_Pos         (12U)
#define I2C_ICR_TIMOUTCF_Msk         (0x1UL << I2C_ICR_TIMOUTCF_Pos)  /*!< 0x00001000 */
#define I2C_ICR_TIMOUTCF             I2C_ICR_TIMOUTCF_Msk        /*!< </spirit:description> */
#define I2C_ICR_ALERTCF_Pos          (13U)
#define I2C_ICR_ALERTCF_Msk          (0x1UL << I2C_ICR_ALERTCF_Pos) /*!< 0x00002000 */
#define I2C_ICR_ALERTCF              I2C_ICR_ALERTCF_Msk         /*!< </spirit:description> */

/*******************  Bit definition for I2C_PECR register  *******************/
#define I2C_PECR_PEC_Pos             (0U)
#define I2C_PECR_PEC_Msk             (0xFFUL << I2C_PECR_PEC_Pos) /*!< 0x000000FF */
#define I2C_PECR_PEC                 I2C_PECR_PEC_Msk            /*!< </spirit:description> */

/*******************  Bit definition for I2C_RXDR register  *******************/
#define I2C_RXDR_RXDATA_Pos          (0U)
#define I2C_RXDR_RXDATA_Msk          (0xFFUL << I2C_RXDR_RXDATA_Pos)  /*!< 0x000000FF */
#define I2C_RXDR_RXDATA              I2C_RXDR_RXDATA_Msk         /*!< </spirit:description> */

/*******************  Bit definition for I2C_TXDR register  *******************/
#define I2C_TXDR_TXDATA_Pos          (0U)
#define I2C_TXDR_TXDATA_Msk          (0xFFUL << I2C_TXDR_TXDATA_Pos)  /*!< 0x000000FF */
#define I2C_TXDR_TXDATA              I2C_TXDR_TXDATA_Msk         /*!< </spirit:description> */

#define I2C1_BASE           0x40005400UL 
#define I2C2_BASE           0x40005800UL 

#define I2C1                ((I2C_TypeDef *) I2C1_BASE) 
#define I2C2                ((I2C_TypeDef *) I2C2_BASE) 


#endif /* __SR5E1_I2C_H */

