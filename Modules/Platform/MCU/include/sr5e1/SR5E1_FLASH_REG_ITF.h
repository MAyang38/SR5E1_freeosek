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

#ifndef __SR5E1_FLASH_REG_ITF_H
#define __SR5E1_FLASH_REG_ITF_H

/******************************************************************************/
/*                                                                            */
/*                       FLASH_REG_ITF (FLASH_REG_ITF)                        */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO uint32_t MCR;            /*!< MCR      Address offset: 0x000 */
  __IO uint32_t MCRA;           /*!< MCRA     Address offset: 0x004 */
  __I  uint32_t MCRE;           /*!< MCRE     Address offset: 0x008 */
       uint32_t RESERVED0;      /*!< Reserved Address offset: 0x00C */
  __IO uint32_t LOCK0;          /*!< LOCK0    Address offset: 0x010 */
  __IO uint32_t LOCK1;          /*!< LOCK1    Address offset: 0x014 */
  __IO uint32_t LOCK2;          /*!< LOCK2    Address offset: 0x018 */
  __IO uint32_t LOCK3;          /*!< LOCK3    Address offset: 0x01C */
       uint32_t RESERVED1[2];   /*!< Reserved Address offset: 0x020-0x024 */
  __IO uint32_t LOCK0A;         /*!< LOCK0A   Address offset: 0x028 */
  __IO uint32_t LOCK1A;         /*!< LOCK1A   Address offset: 0x02C */
       uint32_t RESERVED2[2];   /*!< Reserved Address offset: 0x030-0x034 */
  __IO uint32_t SEL0;           /*!< SEL0     Address offset: 0x038 */
  __IO uint32_t SEL1;           /*!< SEL1     Address offset: 0x03C */
  __IO uint32_t SEL2;           /*!< SEL2     Address offset: 0x040 */
  __IO uint32_t SEL3;           /*!< SEL3     Address offset: 0x044 */
  __IO uint32_t MCR2;           /*!< MCR2     Address offset: 0x048 */
  __I  uint32_t PAR;            /*!< PAR      Address offset: 0x04C */
  __IO uint32_t ADR;            /*!< ADR      Address offset: 0x050 */
  __IO uint32_t UT0;            /*!< UT0      Address offset: 0x054 */
  __IO uint32_t UM0;            /*!< UM0      Address offset: 0x058 */
  __IO uint32_t UM1;            /*!< UM1      Address offset: 0x05C */
  __IO uint32_t UM2;            /*!< UM2      Address offset: 0x060 */
  __IO uint32_t UM3;            /*!< UM3      Address offset: 0x064 */
  __IO uint32_t UM4;            /*!< UM4      Address offset: 0x068 */
  __IO uint32_t UM5;            /*!< UM5      Address offset: 0x06C */
  __IO uint32_t UM6;            /*!< UM6      Address offset: 0x070 */
  __IO uint32_t UM7;            /*!< UM7      Address offset: 0x074 */
  __IO uint32_t UM8;            /*!< UM8      Address offset: 0x078 */
  __IO uint32_t UM9;            /*!< UM9      Address offset: 0x07C */
  __I  uint32_t OPP0;           /*!< OPP0     Address offset: 0x080 */
  __I  uint32_t OPP1;           /*!< OPP1     Address offset: 0x084 */
  __I  uint32_t OPP2;           /*!< OPP2     Address offset: 0x088 */
  __I  uint32_t OPP3;           /*!< OPP3     Address offset: 0x08C */
  __IO uint32_t TMD;            /*!< TMD      Address offset: 0x090 */
  __I  uint32_t ALTSEL0;        /*!< ALTSEL0  Address offset: 0x094 */
  __I  uint32_t ALTSEL1;        /*!< ALTSEL1  Address offset: 0x098 */
       uint32_t RESERVED3[25];  /*!< Reserved Address offset: 0x09C-0x0FC */
  __I  uint32_t ELOCK0;         /*!< ELOCK0   Address offset: 0x100 */
  __I  uint32_t ELOCK1;         /*!< ELOCK1   Address offset: 0x104 */
  __I  uint32_t ELOCK2;         /*!< ELOCK2   Address offset: 0x108 */
  __I  uint32_t ELOCK3;         /*!< ELOCK3   Address offset: 0x10C */
  __I  uint32_t PLOCK0;         /*!< PLOCK0   Address offset: 0x110 */
  __I  uint32_t PLOCK1;         /*!< PLOCK1   Address offset: 0x114 */
  __I  uint32_t PLOCK2;         /*!< PLOCK2   Address offset: 0x118 */
  __I  uint32_t PLOCK3;         /*!< PLOCK3   Address offset: 0x11C */
       uint32_t RESERVED4[5];   /*!< Reserved Address offset: 0x120-0x130 */
  __I  uint32_t ADR2;           /*!< ADR2     Address offset: 0x134 */
} FLASH_REG_ITF_TypeDef;


/**************  Bit definition for FLASH_REG_ITF_MCR register  ***************/
#define FLASH_REG_ITF_MCR_EHV_Pos     (0U)
#define FLASH_REG_ITF_MCR_EHV_Msk     (0x1UL << FLASH_REG_ITF_MCR_EHV_Pos)            /*!< 0x00000001 */
#define FLASH_REG_ITF_MCR_EHV         FLASH_REG_ITF_MCR_EHV_Msk                      /*!< </spirit:description> */
#define FLASH_REG_ITF_MCR_USUS_Pos    (1U)
#define FLASH_REG_ITF_MCR_USUS_Msk    (0x1UL << FLASH_REG_ITF_MCR_USUS_Pos)           /*!< 0x00000002 */
#define FLASH_REG_ITF_MCR_USUS        FLASH_REG_ITF_MCR_USUS_Msk                     /*!< </spirit:description> */
#define FLASH_REG_ITF_MCR_ERS_Pos     (2U)
#define FLASH_REG_ITF_MCR_ERS_Msk     (0x1UL << FLASH_REG_ITF_MCR_ERS_Pos)            /*!< 0x00000004 */
#define FLASH_REG_ITF_MCR_ERS         FLASH_REG_ITF_MCR_ERS_Msk                      /*!< </spirit:description> */
#define FLASH_REG_ITF_MCR_PSUS_Pos    (3U)
#define FLASH_REG_ITF_MCR_PSUS_Msk    (0x1UL << FLASH_REG_ITF_MCR_PSUS_Pos)           /*!< 0x00000008 */
#define FLASH_REG_ITF_MCR_PSUS        FLASH_REG_ITF_MCR_PSUS_Msk                     /*!< </spirit:description> */
#define FLASH_REG_ITF_MCR_PGM_Pos     (4U)
#define FLASH_REG_ITF_MCR_PGM_Msk     (0x1UL << FLASH_REG_ITF_MCR_PGM_Pos)            /*!< 0x00000010 */
#define FLASH_REG_ITF_MCR_PGM         FLASH_REG_ITF_MCR_PGM_Msk                      /*!< </spirit:description> */
#define FLASH_REG_ITF_MCR_FERS_Pos    (7U)
#define FLASH_REG_ITF_MCR_FERS_Msk    (0x1UL << FLASH_REG_ITF_MCR_FERS_Pos)           /*!< 0x00000080 */
#define FLASH_REG_ITF_MCR_FERS        FLASH_REG_ITF_MCR_FERS_Msk                     /*!< </spirit:description> */
#define FLASH_REG_ITF_MCR_PECIE_Pos   (8U)
#define FLASH_REG_ITF_MCR_PECIE_Msk   (0x1UL << FLASH_REG_ITF_MCR_PECIE_Pos)          /*!< 0x00000100 */
#define FLASH_REG_ITF_MCR_PECIE       FLASH_REG_ITF_MCR_PECIE_Msk                    /*!< </spirit:description> */
#define FLASH_REG_ITF_MCR_PEG_Pos     (9U)
#define FLASH_REG_ITF_MCR_PEG_Msk     (0x1UL << FLASH_REG_ITF_MCR_PEG_Pos)            /*!< 0x00000200 */
#define FLASH_REG_ITF_MCR_PEG         FLASH_REG_ITF_MCR_PEG_Msk                      /*!< </spirit:description> */
#define FLASH_REG_ITF_MCR_DONE_Pos    (10U)
#define FLASH_REG_ITF_MCR_DONE_Msk    (0x1UL << FLASH_REG_ITF_MCR_DONE_Pos)           /*!< 0x00000400 */
#define FLASH_REG_ITF_MCR_DONE        FLASH_REG_ITF_MCR_DONE_Msk                     /*!< </spirit:description> */
#define FLASH_REG_ITF_MCR_PEAS_Pos    (11U)
#define FLASH_REG_ITF_MCR_PEAS_Msk    (0x1UL << FLASH_REG_ITF_MCR_PEAS_Pos)           /*!< 0x00000800 */
#define FLASH_REG_ITF_MCR_PEAS        FLASH_REG_ITF_MCR_PEAS_Msk                     /*!< </spirit:description> */
#define FLASH_REG_ITF_MCR_RE_Pos      (12U)
#define FLASH_REG_ITF_MCR_RE_Msk      (0x1UL << FLASH_REG_ITF_MCR_RE_Pos)             /*!< 0x00001000 */
#define FLASH_REG_ITF_MCR_RE          FLASH_REG_ITF_MCR_RE_Msk                       /*!< </spirit:description> */
#define FLASH_REG_ITF_MCR_SBC_Pos     (13U)
#define FLASH_REG_ITF_MCR_SBC_Msk     (0x1UL << FLASH_REG_ITF_MCR_SBC_Pos)            /*!< 0x00002000 */
#define FLASH_REG_ITF_MCR_SBC         FLASH_REG_ITF_MCR_SBC_Msk                      /*!< </spirit:description> */
#define FLASH_REG_ITF_MCR_RWE_Pos     (14U)
#define FLASH_REG_ITF_MCR_RWE_Msk     (0x1UL << FLASH_REG_ITF_MCR_RWE_Pos)            /*!< 0x00004000 */
#define FLASH_REG_ITF_MCR_RWE         FLASH_REG_ITF_MCR_RWE_Msk                      /*!< </spirit:description> */
#define FLASH_REG_ITF_MCR_EER_Pos     (15U)
#define FLASH_REG_ITF_MCR_EER_Msk     (0x1UL << FLASH_REG_ITF_MCR_EER_Pos)            /*!< 0x00008000 */
#define FLASH_REG_ITF_MCR_EER         FLASH_REG_ITF_MCR_EER_Msk                      /*!< </spirit:description> */
#define FLASH_REG_ITF_MCR_PES_Pos     (16U)
#define FLASH_REG_ITF_MCR_PES_Msk     (0x1UL << FLASH_REG_ITF_MCR_PES_Pos)            /*!< 0x00010000 */
#define FLASH_REG_ITF_MCR_PES         FLASH_REG_ITF_MCR_PES_Msk                      /*!< </spirit:description> */
#define FLASH_REG_ITF_MCR_PEP_Pos     (17U)
#define FLASH_REG_ITF_MCR_PEP_Msk     (0x1UL << FLASH_REG_ITF_MCR_PEP_Pos)            /*!< 0x00020000 */
#define FLASH_REG_ITF_MCR_PEP         FLASH_REG_ITF_MCR_PEP_Msk                      /*!< </spirit:description> */
#define FLASH_REG_ITF_MCR_LSW_Pos     (18U)
#define FLASH_REG_ITF_MCR_LSW_Msk     (0x1UL << FLASH_REG_ITF_MCR_LSW_Pos)            /*!< 0x00040000 */
#define FLASH_REG_ITF_MCR_LSW         FLASH_REG_ITF_MCR_LSW_Msk                      /*!< </spirit:description> */
#define FLASH_REG_ITF_MCR_SAK_Pos     (19U)
#define FLASH_REG_ITF_MCR_SAK_Msk     (0x1UL << FLASH_REG_ITF_MCR_SAK_Pos)            /*!< 0x00080000 */
#define FLASH_REG_ITF_MCR_SAK         FLASH_REG_ITF_MCR_SAK_Msk                      /*!< </spirit:description> */
#define FLASH_REG_ITF_MCR_SBC1_Pos    (20U)
#define FLASH_REG_ITF_MCR_SBC1_Msk    (0x1UL << FLASH_REG_ITF_MCR_SBC1_Pos)           /*!< 0x00100000 */
#define FLASH_REG_ITF_MCR_SBC1        FLASH_REG_ITF_MCR_SBC1_Msk                     /*!< </spirit:description> */
#define FLASH_REG_ITF_MCR_DWEE_Pos    (24U)
#define FLASH_REG_ITF_MCR_DWEE_Msk    (0xFUL << FLASH_REG_ITF_MCR_DWEE_Pos)           /*!< 0x0F000000 */
#define FLASH_REG_ITF_MCR_DWEE        FLASH_REG_ITF_MCR_DWEE_Msk                     /*!< </spirit:description> */
#define FLASH_REG_ITF_MCR_EEE_Pos     (28U)
#define FLASH_REG_ITF_MCR_EEE_Msk     (0x1UL << FLASH_REG_ITF_MCR_EEE_Pos)            /*!< 0x10000000 */
#define FLASH_REG_ITF_MCR_EEE         FLASH_REG_ITF_MCR_EEE_Msk                      /*!< </spirit:description> */
#define FLASH_REG_ITF_MCR_AEE_Pos     (29U)
#define FLASH_REG_ITF_MCR_AEE_Msk     (0x1UL << FLASH_REG_ITF_MCR_AEE_Pos)            /*!< 0x20000000 */
#define FLASH_REG_ITF_MCR_AEE         FLASH_REG_ITF_MCR_AEE_Msk                      /*!< </spirit:description> */
#define FLASH_REG_ITF_MCR_RRE_Pos     (30U)
#define FLASH_REG_ITF_MCR_RRE_Msk     (0x1UL << FLASH_REG_ITF_MCR_RRE_Pos)            /*!< 0x40000000 */
#define FLASH_REG_ITF_MCR_RRE         FLASH_REG_ITF_MCR_RRE_Msk                      /*!< </spirit:description> */

/**************  Bit definition for FLASH_REG_ITF_MCRA register  **************/
#define FLASH_REG_ITF_MCRA_EHVA_Pos   (0U)
#define FLASH_REG_ITF_MCRA_EHVA_Msk   (0x1UL << FLASH_REG_ITF_MCRA_EHVA_Pos)          /*!< 0x00000001 */
#define FLASH_REG_ITF_MCRA_EHVA       FLASH_REG_ITF_MCRA_EHVA_Msk                    /*!< </spirit:description> */
#define FLASH_REG_ITF_MCRA_ESUSA_Pos  (1U)
#define FLASH_REG_ITF_MCRA_ESUSA_Msk  (0x1UL << FLASH_REG_ITF_MCRA_ESUSA_Pos)         /*!< 0x00000002 */
#define FLASH_REG_ITF_MCRA_ESUSA      FLASH_REG_ITF_MCRA_ESUSA_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_MCRA_ERSA_Pos   (2U)
#define FLASH_REG_ITF_MCRA_ERSA_Msk   (0x1UL << FLASH_REG_ITF_MCRA_ERSA_Pos)          /*!< 0x00000004 */
#define FLASH_REG_ITF_MCRA_ERSA       FLASH_REG_ITF_MCRA_ERSA_Msk                    /*!< </spirit:description> */
#define FLASH_REG_ITF_MCRA_PSUSA_Pos  (3U)
#define FLASH_REG_ITF_MCRA_PSUSA_Msk  (0x1UL << FLASH_REG_ITF_MCRA_PSUSA_Pos)         /*!< 0x00000008 */
#define FLASH_REG_ITF_MCRA_PSUSA      FLASH_REG_ITF_MCRA_PSUSA_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_MCRA_PGMA_Pos   (4U)
#define FLASH_REG_ITF_MCRA_PGMA_Msk   (0x1UL << FLASH_REG_ITF_MCRA_PGMA_Pos)          /*!< 0x00000010 */
#define FLASH_REG_ITF_MCRA_PGMA       FLASH_REG_ITF_MCRA_PGMA_Msk                    /*!< </spirit:description> */
#define FLASH_REG_ITF_MCRA_PEGA_Pos   (9U)
#define FLASH_REG_ITF_MCRA_PEGA_Msk   (0x1UL << FLASH_REG_ITF_MCRA_PEGA_Pos)          /*!< 0x00000200 */
#define FLASH_REG_ITF_MCRA_PEGA       FLASH_REG_ITF_MCRA_PEGA_Msk                    /*!< </spirit:description> */
#define FLASH_REG_ITF_MCRA_DONEA_Pos  (10U)
#define FLASH_REG_ITF_MCRA_DONEA_Msk  (0x1UL << FLASH_REG_ITF_MCRA_DONEA_Pos)         /*!< 0x00000400 */
#define FLASH_REG_ITF_MCRA_DONEA      FLASH_REG_ITF_MCRA_DONEA_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_MCRA_PEASA_Pos  (11U)
#define FLASH_REG_ITF_MCRA_PEASA_Msk  (0x1UL << FLASH_REG_ITF_MCRA_PEASA_Pos)         /*!< 0x00000800 */
#define FLASH_REG_ITF_MCRA_PEASA      FLASH_REG_ITF_MCRA_PEASA_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_MCRA_PESA_Pos   (16U)
#define FLASH_REG_ITF_MCRA_PESA_Msk   (0x1UL << FLASH_REG_ITF_MCRA_PESA_Pos)          /*!< 0x00010000 */
#define FLASH_REG_ITF_MCRA_PESA       FLASH_REG_ITF_MCRA_PESA_Msk                    /*!< </spirit:description> */
#define FLASH_REG_ITF_MCRA_PEPA_Pos   (17U)
#define FLASH_REG_ITF_MCRA_PEPA_Msk   (0x1UL << FLASH_REG_ITF_MCRA_PEPA_Pos)          /*!< 0x00020000 */
#define FLASH_REG_ITF_MCRA_PEPA       FLASH_REG_ITF_MCRA_PEPA_Msk                    /*!< </spirit:description> */
#define FLASH_REG_ITF_MCRA_LSWA_Pos   (18U)
#define FLASH_REG_ITF_MCRA_LSWA_Msk   (0x1UL << FLASH_REG_ITF_MCRA_LSWA_Pos)          /*!< 0x00040000 */
#define FLASH_REG_ITF_MCRA_LSWA       FLASH_REG_ITF_MCRA_LSWA_Msk                    /*!< </spirit:description> */
#define FLASH_REG_ITF_MCRA_SAKA_Pos   (19U)
#define FLASH_REG_ITF_MCRA_SAKA_Msk   (0x1UL << FLASH_REG_ITF_MCRA_SAKA_Pos)          /*!< 0x00080000 */
#define FLASH_REG_ITF_MCRA_SAKA       FLASH_REG_ITF_MCRA_SAKA_Msk                    /*!< </spirit:description> */

/**************  Bit definition for FLASH_REG_ITF_MCRE register  **************/
#define FLASH_REG_ITF_MCRE_N16KL_Pos  (0U)
#define FLASH_REG_ITF_MCRE_N16KL_Msk  (0x7UL << FLASH_REG_ITF_MCRE_N16KL_Pos)         /*!< 0x00000007 */
#define FLASH_REG_ITF_MCRE_N16KL      FLASH_REG_ITF_MCRE_N16KL_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_MCRE_N32KL_Pos  (3U)
#define FLASH_REG_ITF_MCRE_N32KL_Msk  (0x3UL << FLASH_REG_ITF_MCRE_N32KL_Pos)         /*!< 0x00000018 */
#define FLASH_REG_ITF_MCRE_N32KL      FLASH_REG_ITF_MCRE_N32KL_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_MCRE_N64KL_Pos  (5U)
#define FLASH_REG_ITF_MCRE_N64KL_Msk  (0x7UL << FLASH_REG_ITF_MCRE_N64KL_Pos)         /*!< 0x000000E0 */
#define FLASH_REG_ITF_MCRE_N64KL      FLASH_REG_ITF_MCRE_N64KL_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_MCRE_N16KM_Pos  (8U)
#define FLASH_REG_ITF_MCRE_N16KM_Msk  (0x7UL << FLASH_REG_ITF_MCRE_N16KM_Pos)         /*!< 0x00000700 */
#define FLASH_REG_ITF_MCRE_N16KM      FLASH_REG_ITF_MCRE_N16KM_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_MCRE_N32KM_Pos  (11U)
#define FLASH_REG_ITF_MCRE_N32KM_Msk  (0x3UL << FLASH_REG_ITF_MCRE_N32KM_Pos)         /*!< 0x00001800 */
#define FLASH_REG_ITF_MCRE_N32KM      FLASH_REG_ITF_MCRE_N32KM_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_MCRE_N64KM_Pos  (13U)
#define FLASH_REG_ITF_MCRE_N64KM_Msk  (0x7UL << FLASH_REG_ITF_MCRE_N64KM_Pos)         /*!< 0x0000E000 */
#define FLASH_REG_ITF_MCRE_N64KM      FLASH_REG_ITF_MCRE_N64KM_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_MCRE_N16KH_Pos  (16U)
#define FLASH_REG_ITF_MCRE_N16KH_Msk  (0x7UL << FLASH_REG_ITF_MCRE_N16KH_Pos)         /*!< 0x00070000 */
#define FLASH_REG_ITF_MCRE_N16KH      FLASH_REG_ITF_MCRE_N16KH_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_MCRE_N32KH_Pos  (19U)
#define FLASH_REG_ITF_MCRE_N32KH_Msk  (0x3UL << FLASH_REG_ITF_MCRE_N32KH_Pos)         /*!< 0x00180000 */
#define FLASH_REG_ITF_MCRE_N32KH      FLASH_REG_ITF_MCRE_N32KH_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_MCRE_N64KH_Pos  (21U)
#define FLASH_REG_ITF_MCRE_N64KH_Msk  (0x7UL << FLASH_REG_ITF_MCRE_N64KH_Pos)         /*!< 0x00E00000 */
#define FLASH_REG_ITF_MCRE_N64KH      FLASH_REG_ITF_MCRE_N64KH_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_MCRE_N256K_Pos  (24U)
#define FLASH_REG_ITF_MCRE_N256K_Msk  (0x1FUL << FLASH_REG_ITF_MCRE_N256K_Pos)        /*!< 0x1F000000 */
#define FLASH_REG_ITF_MCRE_N256K      FLASH_REG_ITF_MCRE_N256K_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_MCRE_N128KL_Pos (29U)
#define FLASH_REG_ITF_MCRE_N128KL_Msk (0x3UL << FLASH_REG_ITF_MCRE_N128KL_Pos)        /*!< 0x60000000 */
#define FLASH_REG_ITF_MCRE_N128KL     FLASH_REG_ITF_MCRE_N128KL_Msk                  /*!< </spirit:description> */

/*************  Bit definition for FLASH_REG_ITF_LOCK0 register  **************/
#define FLASH_REG_ITF_LOCK0_MIDLOCK_Pos (0U)
#define FLASH_REG_ITF_LOCK0_MIDLOCK_Msk (0xFFFFUL << FLASH_REG_ITF_LOCK0_MIDLOCK_Pos)   /*!< 0x0000FFFF */
#define FLASH_REG_ITF_LOCK0_MIDLOCK   FLASH_REG_ITF_LOCK0_MIDLOCK_Msk                /*!< </spirit:description> */
#define FLASH_REG_ITF_LOCK0_LOWLOCK_Pos (16U)
#define FLASH_REG_ITF_LOCK0_LOWLOCK_Msk (0x3FFFUL << FLASH_REG_ITF_LOCK0_LOWLOCK_Pos)   /*!< 0x3FFF0000 */
#define FLASH_REG_ITF_LOCK0_LOWLOCK   FLASH_REG_ITF_LOCK0_LOWLOCK_Msk                /*!< </spirit:description> */
#define FLASH_REG_ITF_LOCK0_TSLOCK_Pos     (31U)
#define FLASH_REG_ITF_LOCK0_TSLOCK_Msk     (0x1UL << FLASH_REG_ITF_LOCK0_TSLOCK_Pos)       /*!< 0x80000000 */
#define FLASH_REG_ITF_LOCK0_TSLOCK    FLASH_REG_ITF_LOCK0_TSLOCK_Msk                 /*!< </spirit:description> */

/*************  Bit definition for FLASH_REG_ITF_LOCK1 register  **************/
#define FLASH_REG_ITF_LOCK1_HIGHLOCK_Pos  (0U)
#define FLASH_REG_ITF_LOCK1_HIGHLOCK_Msk  (0xFFFFUL << FLASH_REG_ITF_LOCK1_HIGHLOCK_Pos)  /*!< 0x0000FFFF */
#define FLASH_REG_ITF_LOCK1_HIGHLOCK  FLASH_REG_ITF_LOCK1_HIGHLOCK_Msk               /*!< </spirit:description> */

/*************  Bit definition for FLASH_REG_ITF_LOCK2 register  **************/
#define FLASH_REG_ITF_LOCK2_A256KLOCK_Pos   (0U)
#define FLASH_REG_ITF_LOCK2_A256KLOCK_Msk   (0xFFFFFFFFUL << FLASH_REG_ITF_LOCK2_A256KLOCK_Pos)   /*!< 0xFFFFFFFF */
#define FLASH_REG_ITF_LOCK2_A256KLOCK FLASH_REG_ITF_LOCK2_A256KLOCK_Msk              /*!< </spirit:description> */

/*************  Bit definition for FLASH_REG_ITF_LOCK3 register  **************/
#define FLASH_REG_ITF_LOCK3_A256KLOCK_Pos   (0U)
#define FLASH_REG_ITF_LOCK3_A256KLOCK_Msk   (0xFFFFFFFFUL << FLASH_REG_ITF_LOCK3_A256KLOCK_Pos)   /*!< 0xFFFFFFFF */
#define FLASH_REG_ITF_LOCK3_A256KLOCK FLASH_REG_ITF_LOCK3_A256KLOCK_Msk              /*!< </spirit:description> */

/*************  Bit definition for FLASH_REG_ITF_LOCK0A register  *************/
#define FLASH_REG_ITF_LOCK0A_MIDLOCKA_Pos   (0U)
#define FLASH_REG_ITF_LOCK0A_MIDLOCKA_Msk   (0xFFFFUL << FLASH_REG_ITF_LOCK0A_MIDLOCKA_Pos) /*!< 0x0000FFFF */
#define FLASH_REG_ITF_LOCK0A_MIDLOCKA FLASH_REG_ITF_LOCK0A_MIDLOCKA_Msk              /*!< </spirit:description> */
#define FLASH_REG_ITF_LOCK0A_LOWLOCKA_Pos   (16U)
#define FLASH_REG_ITF_LOCK0A_LOWLOCKA_Msk   (0x3FFFUL << FLASH_REG_ITF_LOCK0A_LOWLOCKA_Pos) /*!< 0x3FFF0000 */
#define FLASH_REG_ITF_LOCK0A_LOWLOCKA FLASH_REG_ITF_LOCK0A_LOWLOCKA_Msk              /*!< </spirit:description> */
#define FLASH_REG_ITF_LOCK0A_TSLOCKA_Pos  (31U)
#define FLASH_REG_ITF_LOCK0A_TSLOCKA_Msk  (0x1UL << FLASH_REG_ITF_LOCK0A_TSLOCKA_Pos)     /*!< 0x80000000 */
#define FLASH_REG_ITF_LOCK0A_TSLOCKA  FLASH_REG_ITF_LOCK0A_TSLOCKA_Msk               /*!< </spirit:description> */

/*************  Bit definition for FLASH_REG_ITF_LOCK1A register  *************/
#define FLASH_REG_ITF_LOCK1A_HIGHLOCKA_Pos    (0U)
#define FLASH_REG_ITF_LOCK1A_HIGHLOCKA_Msk     (0xFFFFUL << FLASH_REG_ITF_LOCK1A_HIGHLOCKA_Pos) /*!< 0x0000FFFF */
#define FLASH_REG_ITF_LOCK1A_HIGHLOCKA FLASH_REG_ITF_LOCK1A_HIGHLOCKA_Msk             /*!< </spirit:description> */

/**************  Bit definition for FLASH_REG_ITF_SEL0 register  **************/
#define FLASH_REG_ITF_SEL0_MIDSEL_Pos (0U)
#define FLASH_REG_ITF_SEL0_MIDSEL_Msk (0xFFFFUL << FLASH_REG_ITF_SEL0_MIDSEL_Pos)     /*!< 0x0000FFFF */
#define FLASH_REG_ITF_SEL0_MIDSEL     FLASH_REG_ITF_SEL0_MIDSEL_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_SEL0_LOWSEL_Pos (16U)
#define FLASH_REG_ITF_SEL0_LOWSEL_Msk (0x3FFFUL << FLASH_REG_ITF_SEL0_LOWSEL_Pos)     /*!< 0x3FFF0000 */
#define FLASH_REG_ITF_SEL0_LOWSEL     FLASH_REG_ITF_SEL0_LOWSEL_Msk                  /*!< </spirit:description> */

/**************  Bit definition for FLASH_REG_ITF_SEL1 register  **************/
#define FLASH_REG_ITF_SEL1_HIGHSEL_Pos        (0U)
#define FLASH_REG_ITF_SEL1_HIGHSEL_Msk        (0xFFFFUL << FLASH_REG_ITF_SEL1_HIGHSEL_Pos)    /*!< 0x0000FFFF */
#define FLASH_REG_ITF_SEL1_HIGHSEL    FLASH_REG_ITF_SEL1_HIGHSEL_Msk                 /*!< </spirit:description> */

/**************  Bit definition for FLASH_REG_ITF_SEL2 register  **************/
#define FLASH_REG_ITF_SEL2_A256KSEL_Pos (0U)
#define FLASH_REG_ITF_SEL2_A256KSEL_Msk (0xFFFFFFFFUL << FLASH_REG_ITF_SEL2_A256KSEL_Pos) /*!< 0xFFFFFFFF */
#define FLASH_REG_ITF_SEL2_A256KSEL   FLASH_REG_ITF_SEL2_A256KSEL_Msk                /*!< </spirit:description> */

/**************  Bit definition for FLASH_REG_ITF_SEL3 register  **************/
#define FLASH_REG_ITF_SEL3_A256KSEL_Pos (0U)
#define FLASH_REG_ITF_SEL3_A256KSEL_Msk (0xFFFFFFFFUL << FLASH_REG_ITF_SEL3_A256KSEL_Pos) /*!< 0xFFFFFFFF */
#define FLASH_REG_ITF_SEL3_A256KSEL   FLASH_REG_ITF_SEL3_A256KSEL_Msk                /*!< </spirit:description> */

/**************  Bit definition for FLASH_REG_ITF_MCR2 register  **************/
#define FLASH_REG_ITF_MCR2_PSBC_Pos   (13U)
#define FLASH_REG_ITF_MCR2_PSBC_Msk   (0x1UL << FLASH_REG_ITF_MCR2_PSBC_Pos)          /*!< 0x00002000 */
#define FLASH_REG_ITF_MCR2_PSBC       FLASH_REG_ITF_MCR2_PSBC_Msk                    /*!< </spirit:description> */
#define FLASH_REG_ITF_MCR2_PRWE_Pos   (14U)
#define FLASH_REG_ITF_MCR2_PRWE_Msk   (0x1UL << FLASH_REG_ITF_MCR2_PRWE_Pos)          /*!< 0x00004000 */
#define FLASH_REG_ITF_MCR2_PRWE       FLASH_REG_ITF_MCR2_PRWE_Msk                    /*!< </spirit:description> */
#define FLASH_REG_ITF_MCR2_PEER_Pos   (15U)
#define FLASH_REG_ITF_MCR2_PEER_Msk   (0x1UL << FLASH_REG_ITF_MCR2_PEER_Pos)          /*!< 0x00008000 */
#define FLASH_REG_ITF_MCR2_PEER       FLASH_REG_ITF_MCR2_PEER_Msk                    /*!< </spirit:description> */
#define FLASH_REG_ITF_MCR2_PSBC1_Pos  (20U)
#define FLASH_REG_ITF_MCR2_PSBC1_Msk  (0x1UL << FLASH_REG_ITF_MCR2_PSBC1_Pos)         /*!< 0x00100000 */
#define FLASH_REG_ITF_MCR2_PSBC1      FLASH_REG_ITF_MCR2_PSBC1_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_MCR2_PDWEE_Pos  (24U)
#define FLASH_REG_ITF_MCR2_PDWEE_Msk  (0xFUL << FLASH_REG_ITF_MCR2_PDWEE_Pos)         /*!< 0x0F000000 */
#define FLASH_REG_ITF_MCR2_PDWEE      FLASH_REG_ITF_MCR2_PDWEE_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_MCR2_PEEE_Pos   (28U)
#define FLASH_REG_ITF_MCR2_PEEE_Msk   (0x1UL << FLASH_REG_ITF_MCR2_PEEE_Pos)          /*!< 0x10000000 */
#define FLASH_REG_ITF_MCR2_PEEE       FLASH_REG_ITF_MCR2_PEEE_Msk                    /*!< </spirit:description> */
#define FLASH_REG_ITF_MCR2_PAEE_Pos   (29U)
#define FLASH_REG_ITF_MCR2_PAEE_Msk   (0x1UL << FLASH_REG_ITF_MCR2_PAEE_Pos)          /*!< 0x20000000 */
#define FLASH_REG_ITF_MCR2_PAEE       FLASH_REG_ITF_MCR2_PAEE_Msk                    /*!< </spirit:description> */

/**************  Bit definition for FLASH_REG_ITF_PAR register  ***************/
#define FLASH_REG_ITF_PAR_PAR_Pos     (3U)
#define FLASH_REG_ITF_PAR_PAR_Msk     (0x1FFFFFUL << FLASH_REG_ITF_PAR_PAR_Pos)       /*!< 0x00FFFFF8 */
#define FLASH_REG_ITF_PAR_PAR         FLASH_REG_ITF_PAR_PAR_Msk                      /*!< </spirit:description> */

/**************  Bit definition for FLASH_REG_ITF_ADR register  ***************/
#define FLASH_REG_ITF_ADR_ADDR_Pos    (3U)
#define FLASH_REG_ITF_ADR_ADDR_Msk    (0x1FFFFFUL << FLASH_REG_ITF_ADR_ADDR_Pos)      /*!< 0x00FFFFF8 */
#define FLASH_REG_ITF_ADR_ADDR        FLASH_REG_ITF_ADR_ADDR_Msk                     /*!< </spirit:description> */
#define FLASH_REG_ITF_ADR_SAD_Pos     (31U)
#define FLASH_REG_ITF_ADR_SAD_Msk     (0x1UL << FLASH_REG_ITF_ADR_SAD_Pos)             /*!< 0x80000000 */
#define FLASH_REG_ITF_ADR_SAD         FLASH_REG_ITF_ADR_SAD_Msk                     /*!< </spirit:description> */

/**************  Bit definition for FLASH_REG_ITF_UT0 register  ***************/
#define FLASH_REG_ITF_UT0_AID_Pos     (0U)
#define FLASH_REG_ITF_UT0_AID_Msk     (0x1UL << FLASH_REG_ITF_UT0_AID_Pos)            /*!< 0x00000001 */
#define FLASH_REG_ITF_UT0_AID         FLASH_REG_ITF_UT0_AID_Msk                      /*!< </spirit:description> */
#define FLASH_REG_ITF_UT0_AIE_Pos     (1U)
#define FLASH_REG_ITF_UT0_AIE_Msk     (0x1UL << FLASH_REG_ITF_UT0_AIE_Pos)            /*!< 0x00000002 */
#define FLASH_REG_ITF_UT0_AIE         FLASH_REG_ITF_UT0_AIE_Msk                      /*!< </spirit:description> */
#define FLASH_REG_ITF_UT0_AIS_Pos     (2U)
#define FLASH_REG_ITF_UT0_AIS_Msk     (0x1UL << FLASH_REG_ITF_UT0_AIS_Pos)            /*!< 0x00000004 */
#define FLASH_REG_ITF_UT0_AIS         FLASH_REG_ITF_UT0_AIS_Msk                      /*!< </spirit:description> */
#define FLASH_REG_ITF_UT0_MRV_Pos     (4U)
#define FLASH_REG_ITF_UT0_MRV_Msk     (0x1UL << FLASH_REG_ITF_UT0_MRV_Pos)            /*!< 0x00000010 */
#define FLASH_REG_ITF_UT0_MRV         FLASH_REG_ITF_UT0_MRV_Msk                      /*!< </spirit:description> */
#define FLASH_REG_ITF_UT0_MRE_Pos     (5U)
#define FLASH_REG_ITF_UT0_MRE_Msk     (0x1UL << FLASH_REG_ITF_UT0_MRE_Pos)            /*!< 0x00000020 */
#define FLASH_REG_ITF_UT0_MRE         FLASH_REG_ITF_UT0_MRE_Msk                      /*!< </spirit:description> */
#define FLASH_REG_ITF_UT0_AISUS_Pos   (6U)
#define FLASH_REG_ITF_UT0_AISUS_Msk   (0x1UL << FLASH_REG_ITF_UT0_AISUS_Pos)          /*!< 0x00000040 */
#define FLASH_REG_ITF_UT0_AISUS       FLASH_REG_ITF_UT0_AISUS_Msk                    /*!< </spirit:description> */
#define FLASH_REG_ITF_UT0_AIBPE_Pos   (8U)
#define FLASH_REG_ITF_UT0_AIBPE_Msk   (0x1UL << FLASH_REG_ITF_UT0_AIBPE_Pos)          /*!< 0x00000100 */
#define FLASH_REG_ITF_UT0_AIBPE       FLASH_REG_ITF_UT0_AIBPE_Msk                    /*!< </spirit:description> */
#define FLASH_REG_ITF_UT0_NAIBP_Pos   (9U)
#define FLASH_REG_ITF_UT0_NAIBP_Msk   (0x1UL << FLASH_REG_ITF_UT0_NAIBP_Pos)          /*!< 0x00000200 */
#define FLASH_REG_ITF_UT0_NAIBP       FLASH_REG_ITF_UT0_NAIBP_Msk                    /*!< </spirit:description> */
#define FLASH_REG_ITF_UT0_VTD_Pos     (12U)
#define FLASH_REG_ITF_UT0_VTD_Msk     (0x1UL << FLASH_REG_ITF_UT0_VTD_Pos)            /*!< 0x00001000 */
#define FLASH_REG_ITF_UT0_VTD         FLASH_REG_ITF_UT0_VTD_Msk                      /*!< </spirit:description> */
#define FLASH_REG_ITF_UT0_CPE_Pos     (16U)
#define FLASH_REG_ITF_UT0_CPE_Msk     (0x1UL << FLASH_REG_ITF_UT0_CPE_Pos)            /*!< 0x00010000 */
#define FLASH_REG_ITF_UT0_CPE         FLASH_REG_ITF_UT0_CPE_Msk                      /*!< </spirit:description> */
#define FLASH_REG_ITF_UT0_CPA_Pos     (17U)
#define FLASH_REG_ITF_UT0_CPA_Msk     (0x1UL << FLASH_REG_ITF_UT0_CPA_Pos)            /*!< 0x00020000 */
#define FLASH_REG_ITF_UT0_CPA         FLASH_REG_ITF_UT0_CPA_Msk                      /*!< </spirit:description> */
#define FLASH_REG_ITF_UT0_CPR_Pos     (18U)
#define FLASH_REG_ITF_UT0_CPR_Msk     (0x1UL << FLASH_REG_ITF_UT0_CPR_Pos)            /*!< 0x00040000 */
#define FLASH_REG_ITF_UT0_CPR         FLASH_REG_ITF_UT0_CPR_Msk                      /*!< </spirit:description> */
#define FLASH_REG_ITF_UT0_DDEF_Pos    (19U)
#define FLASH_REG_ITF_UT0_DDEF_Msk    (0x1UL << FLASH_REG_ITF_UT0_DDEF_Pos)           /*!< 0x00080000 */
#define FLASH_REG_ITF_UT0_DDEF        FLASH_REG_ITF_UT0_DDEF_Msk                     /*!< </spirit:description> */
#define FLASH_REG_ITF_UT0_SBCE1_Pos   (23U)
#define FLASH_REG_ITF_UT0_SBCE1_Msk   (0x1UL << FLASH_REG_ITF_UT0_SBCE1_Pos)          /*!< 0x00800000 */
#define FLASH_REG_ITF_UT0_SBCE1       FLASH_REG_ITF_UT0_SBCE1_Msk                    /*!< </spirit:description> */
#define FLASH_REG_ITF_UT0_SBCE_Pos    (30U)
#define FLASH_REG_ITF_UT0_SBCE_Msk    (0x1UL << FLASH_REG_ITF_UT0_SBCE_Pos)           /*!< 0x40000000 */
#define FLASH_REG_ITF_UT0_SBCE        FLASH_REG_ITF_UT0_SBCE_Msk                     /*!< </spirit:description> */
#define FLASH_REG_ITF_UT0_UTE_Pos     (31U)
#define FLASH_REG_ITF_UT0_UTE_Msk     (0x1UL << FLASH_REG_ITF_UT0_UTE_Pos)            /*!< 0x80000000 */
#define FLASH_REG_ITF_UT0_UTE         FLASH_REG_ITF_UT0_UTE_Msk                      /*!< </spirit:description> */

/**************  Bit definition for FLASH_REG_ITF_UM0 register  ***************/
#define FLASH_REG_ITF_UM0_MISR0_Pos   (0U)
#define FLASH_REG_ITF_UM0_MISR0_Msk   (0x1UL << FLASH_REG_ITF_UM0_MISR0_Pos)          /*!< 0x00000001 */
#define FLASH_REG_ITF_UM0_MISR0       FLASH_REG_ITF_UM0_MISR0_Msk                    /*!< </spirit:description> */
#define FLASH_REG_ITF_UM0_MISR1_Pos   (1U)
#define FLASH_REG_ITF_UM0_MISR1_Msk   (0x1UL << FLASH_REG_ITF_UM0_MISR1_Pos)          /*!< 0x00000002 */
#define FLASH_REG_ITF_UM0_MISR1       FLASH_REG_ITF_UM0_MISR1_Msk                    /*!< </spirit:description> */
#define FLASH_REG_ITF_UM0_MISR2_Pos   (2U)
#define FLASH_REG_ITF_UM0_MISR2_Msk   (0x1UL << FLASH_REG_ITF_UM0_MISR2_Pos)          /*!< 0x00000004 */
#define FLASH_REG_ITF_UM0_MISR2       FLASH_REG_ITF_UM0_MISR2_Msk                    /*!< </spirit:description> */
#define FLASH_REG_ITF_UM0_MISR3_Pos   (3U)
#define FLASH_REG_ITF_UM0_MISR3_Msk   (0x1UL << FLASH_REG_ITF_UM0_MISR3_Pos)          /*!< 0x00000008 */
#define FLASH_REG_ITF_UM0_MISR3       FLASH_REG_ITF_UM0_MISR3_Msk                    /*!< </spirit:description> */
#define FLASH_REG_ITF_UM0_MISR4_Pos   (4U)
#define FLASH_REG_ITF_UM0_MISR4_Msk   (0x1UL << FLASH_REG_ITF_UM0_MISR4_Pos)          /*!< 0x00000010 */
#define FLASH_REG_ITF_UM0_MISR4       FLASH_REG_ITF_UM0_MISR4_Msk                    /*!< </spirit:description> */
#define FLASH_REG_ITF_UM0_MISR5_Pos   (5U)
#define FLASH_REG_ITF_UM0_MISR5_Msk   (0x1UL << FLASH_REG_ITF_UM0_MISR5_Pos)          /*!< 0x00000020 */
#define FLASH_REG_ITF_UM0_MISR5       FLASH_REG_ITF_UM0_MISR5_Msk                    /*!< </spirit:description> */
#define FLASH_REG_ITF_UM0_MISR6_Pos   (6U)
#define FLASH_REG_ITF_UM0_MISR6_Msk   (0x1UL << FLASH_REG_ITF_UM0_MISR6_Pos)          /*!< 0x00000040 */
#define FLASH_REG_ITF_UM0_MISR6       FLASH_REG_ITF_UM0_MISR6_Msk                    /*!< </spirit:description> */
#define FLASH_REG_ITF_UM0_MISR7_Pos   (7U)
#define FLASH_REG_ITF_UM0_MISR7_Msk   (0x1UL << FLASH_REG_ITF_UM0_MISR7_Pos)          /*!< 0x00000080 */
#define FLASH_REG_ITF_UM0_MISR7       FLASH_REG_ITF_UM0_MISR7_Msk                    /*!< </spirit:description> */
#define FLASH_REG_ITF_UM0_MISR8_Pos   (8U)
#define FLASH_REG_ITF_UM0_MISR8_Msk   (0x1UL << FLASH_REG_ITF_UM0_MISR8_Pos)          /*!< 0x00000100 */
#define FLASH_REG_ITF_UM0_MISR8       FLASH_REG_ITF_UM0_MISR8_Msk                    /*!< </spirit:description> */
#define FLASH_REG_ITF_UM0_MISR9_Pos   (9U)
#define FLASH_REG_ITF_UM0_MISR9_Msk   (0x1UL << FLASH_REG_ITF_UM0_MISR9_Pos)          /*!< 0x00000200 */
#define FLASH_REG_ITF_UM0_MISR9       FLASH_REG_ITF_UM0_MISR9_Msk                    /*!< </spirit:description> */
#define FLASH_REG_ITF_UM0_MISR10_Pos  (10U)
#define FLASH_REG_ITF_UM0_MISR10_Msk  (0x1UL << FLASH_REG_ITF_UM0_MISR10_Pos)         /*!< 0x00000400 */
#define FLASH_REG_ITF_UM0_MISR10      FLASH_REG_ITF_UM0_MISR10_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM0_MISR11_Pos  (11U)
#define FLASH_REG_ITF_UM0_MISR11_Msk  (0x1UL << FLASH_REG_ITF_UM0_MISR11_Pos)         /*!< 0x00000800 */
#define FLASH_REG_ITF_UM0_MISR11      FLASH_REG_ITF_UM0_MISR11_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM0_MISR12_Pos  (12U)
#define FLASH_REG_ITF_UM0_MISR12_Msk  (0x1UL << FLASH_REG_ITF_UM0_MISR12_Pos)         /*!< 0x00001000 */
#define FLASH_REG_ITF_UM0_MISR12      FLASH_REG_ITF_UM0_MISR12_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM0_MISR13_Pos  (13U)
#define FLASH_REG_ITF_UM0_MISR13_Msk  (0x1UL << FLASH_REG_ITF_UM0_MISR13_Pos)         /*!< 0x00002000 */
#define FLASH_REG_ITF_UM0_MISR13      FLASH_REG_ITF_UM0_MISR13_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM0_MISR14_Pos  (14U)
#define FLASH_REG_ITF_UM0_MISR14_Msk  (0x1UL << FLASH_REG_ITF_UM0_MISR14_Pos)         /*!< 0x00004000 */
#define FLASH_REG_ITF_UM0_MISR14      FLASH_REG_ITF_UM0_MISR14_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM0_MISR15_Pos  (15U)
#define FLASH_REG_ITF_UM0_MISR15_Msk  (0x1UL << FLASH_REG_ITF_UM0_MISR15_Pos)         /*!< 0x00008000 */
#define FLASH_REG_ITF_UM0_MISR15      FLASH_REG_ITF_UM0_MISR15_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM0_MISR16_Pos  (16U)
#define FLASH_REG_ITF_UM0_MISR16_Msk  (0x1UL << FLASH_REG_ITF_UM0_MISR16_Pos)         /*!< 0x00010000 */
#define FLASH_REG_ITF_UM0_MISR16      FLASH_REG_ITF_UM0_MISR16_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM0_MISR17_Pos  (17U)
#define FLASH_REG_ITF_UM0_MISR17_Msk  (0x1UL << FLASH_REG_ITF_UM0_MISR17_Pos)         /*!< 0x00020000 */
#define FLASH_REG_ITF_UM0_MISR17      FLASH_REG_ITF_UM0_MISR17_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM0_MISR18_Pos  (18U)
#define FLASH_REG_ITF_UM0_MISR18_Msk  (0x1UL << FLASH_REG_ITF_UM0_MISR18_Pos)         /*!< 0x00040000 */
#define FLASH_REG_ITF_UM0_MISR18      FLASH_REG_ITF_UM0_MISR18_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM0_MISR19_Pos  (19U)
#define FLASH_REG_ITF_UM0_MISR19_Msk  (0x1UL << FLASH_REG_ITF_UM0_MISR19_Pos)         /*!< 0x00080000 */
#define FLASH_REG_ITF_UM0_MISR19      FLASH_REG_ITF_UM0_MISR19_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM0_MISR20_Pos  (20U)
#define FLASH_REG_ITF_UM0_MISR20_Msk  (0x1UL << FLASH_REG_ITF_UM0_MISR20_Pos)         /*!< 0x00100000 */
#define FLASH_REG_ITF_UM0_MISR20      FLASH_REG_ITF_UM0_MISR20_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM0_MISR21_Pos  (21U)
#define FLASH_REG_ITF_UM0_MISR21_Msk  (0x1UL << FLASH_REG_ITF_UM0_MISR21_Pos)         /*!< 0x00200000 */
#define FLASH_REG_ITF_UM0_MISR21      FLASH_REG_ITF_UM0_MISR21_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM0_MISR22_Pos  (22U)
#define FLASH_REG_ITF_UM0_MISR22_Msk  (0x1UL << FLASH_REG_ITF_UM0_MISR22_Pos)         /*!< 0x00400000 */
#define FLASH_REG_ITF_UM0_MISR22      FLASH_REG_ITF_UM0_MISR22_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM0_MISR23_Pos  (23U)
#define FLASH_REG_ITF_UM0_MISR23_Msk  (0x1UL << FLASH_REG_ITF_UM0_MISR23_Pos)         /*!< 0x00800000 */
#define FLASH_REG_ITF_UM0_MISR23      FLASH_REG_ITF_UM0_MISR23_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM0_MISR24_Pos  (24U)
#define FLASH_REG_ITF_UM0_MISR24_Msk  (0x1UL << FLASH_REG_ITF_UM0_MISR24_Pos)         /*!< 0x01000000 */
#define FLASH_REG_ITF_UM0_MISR24      FLASH_REG_ITF_UM0_MISR24_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM0_MISR25_Pos  (25U)
#define FLASH_REG_ITF_UM0_MISR25_Msk  (0x1UL << FLASH_REG_ITF_UM0_MISR25_Pos)         /*!< 0x02000000 */
#define FLASH_REG_ITF_UM0_MISR25      FLASH_REG_ITF_UM0_MISR25_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM0_MISR26_Pos  (26U)
#define FLASH_REG_ITF_UM0_MISR26_Msk  (0x1UL << FLASH_REG_ITF_UM0_MISR26_Pos)         /*!< 0x04000000 */
#define FLASH_REG_ITF_UM0_MISR26      FLASH_REG_ITF_UM0_MISR26_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM0_MISR27_Pos  (27U)
#define FLASH_REG_ITF_UM0_MISR27_Msk  (0x1UL << FLASH_REG_ITF_UM0_MISR27_Pos)         /*!< 0x08000000 */
#define FLASH_REG_ITF_UM0_MISR27      FLASH_REG_ITF_UM0_MISR27_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM0_MISR28_Pos  (28U)                                  
#define FLASH_REG_ITF_UM0_MISR28_Msk  (0x1UL << FLASH_REG_ITF_UM0_MISR28_Pos)         /*!< 0x10000000 */
#define FLASH_REG_ITF_UM0_MISR28      FLASH_REG_ITF_UM0_MISR28_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM0_MISR29_Pos  (29U)
#define FLASH_REG_ITF_UM0_MISR29_Msk  (0x1UL << FLASH_REG_ITF_UM0_MISR29_Pos)         /*!< 0x20000000 */
#define FLASH_REG_ITF_UM0_MISR29      FLASH_REG_ITF_UM0_MISR29_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM0_MISR30_Pos  (30U)
#define FLASH_REG_ITF_UM0_MISR30_Msk  (0x1UL << FLASH_REG_ITF_UM0_MISR30_Pos)         /*!< 0x40000000 */
#define FLASH_REG_ITF_UM0_MISR30      FLASH_REG_ITF_UM0_MISR30_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM0_MISR31_Pos  (31U)
#define FLASH_REG_ITF_UM0_MISR31_Msk  (0x1UL << FLASH_REG_ITF_UM0_MISR31_Pos)         /*!< 0x80000000 */
#define FLASH_REG_ITF_UM0_MISR31      FLASH_REG_ITF_UM0_MISR31_Msk                   /*!< </spirit:description> */

/**************  Bit definition for FLASH_REG_ITF_UM1 register  ***************/
#define FLASH_REG_ITF_UM1_MISR32_Pos  (0U)
#define FLASH_REG_ITF_UM1_MISR32_Msk  (0x1UL << FLASH_REG_ITF_UM1_MISR32_Pos)         /*!< 0x00000001 */
#define FLASH_REG_ITF_UM1_MISR32      FLASH_REG_ITF_UM1_MISR32_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM1_MISR33_Pos  (1U)
#define FLASH_REG_ITF_UM1_MISR33_Msk  (0x1UL << FLASH_REG_ITF_UM1_MISR33_Pos)         /*!< 0x00000002 */
#define FLASH_REG_ITF_UM1_MISR33      FLASH_REG_ITF_UM1_MISR33_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM1_MISR34_Pos  (2U)
#define FLASH_REG_ITF_UM1_MISR34_Msk  (0x1UL << FLASH_REG_ITF_UM1_MISR34_Pos)         /*!< 0x00000004 */
#define FLASH_REG_ITF_UM1_MISR34      FLASH_REG_ITF_UM1_MISR34_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM1_MISR35_Pos  (3U)
#define FLASH_REG_ITF_UM1_MISR35_Msk  (0x1UL << FLASH_REG_ITF_UM1_MISR35_Pos)         /*!< 0x00000008 */
#define FLASH_REG_ITF_UM1_MISR35      FLASH_REG_ITF_UM1_MISR35_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM1_MISR36_Pos  (4U)
#define FLASH_REG_ITF_UM1_MISR36_Msk  (0x1UL << FLASH_REG_ITF_UM1_MISR36_Pos)         /*!< 0x00000010 */
#define FLASH_REG_ITF_UM1_MISR36      FLASH_REG_ITF_UM1_MISR36_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM1_MISR37_Pos  (5U)
#define FLASH_REG_ITF_UM1_MISR37_Msk  (0x1UL << FLASH_REG_ITF_UM1_MISR37_Pos)         /*!< 0x00000020 */
#define FLASH_REG_ITF_UM1_MISR37      FLASH_REG_ITF_UM1_MISR37_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM1_MISR38_Pos  (6U)
#define FLASH_REG_ITF_UM1_MISR38_Msk  (0x1UL << FLASH_REG_ITF_UM1_MISR38_Pos)         /*!< 0x00000040 */
#define FLASH_REG_ITF_UM1_MISR38      FLASH_REG_ITF_UM1_MISR38_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM1_MISR39_Pos  (7U)
#define FLASH_REG_ITF_UM1_MISR39_Msk  (0x1UL << FLASH_REG_ITF_UM1_MISR39_Pos)         /*!< 0x00000080 */
#define FLASH_REG_ITF_UM1_MISR39      FLASH_REG_ITF_UM1_MISR39_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM1_MISR40_Pos  (8U)
#define FLASH_REG_ITF_UM1_MISR40_Msk  (0x1UL << FLASH_REG_ITF_UM1_MISR40_Pos)         /*!< 0x00000100 */
#define FLASH_REG_ITF_UM1_MISR40      FLASH_REG_ITF_UM1_MISR40_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM1_MISR41_Pos  (9U)
#define FLASH_REG_ITF_UM1_MISR41_Msk  (0x1UL << FLASH_REG_ITF_UM1_MISR41_Pos)         /*!< 0x00000200 */
#define FLASH_REG_ITF_UM1_MISR41      FLASH_REG_ITF_UM1_MISR41_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM1_MISR42_Pos  (10U)
#define FLASH_REG_ITF_UM1_MISR42_Msk  (0x1UL << FLASH_REG_ITF_UM1_MISR42_Pos)         /*!< 0x00000400 */
#define FLASH_REG_ITF_UM1_MISR42      FLASH_REG_ITF_UM1_MISR42_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM1_MISR43_Pos  (11U)
#define FLASH_REG_ITF_UM1_MISR43_Msk  (0x1UL << FLASH_REG_ITF_UM1_MISR43_Pos)         /*!< 0x00000800 */
#define FLASH_REG_ITF_UM1_MISR43      FLASH_REG_ITF_UM1_MISR43_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM1_MISR44_Pos  (12U)
#define FLASH_REG_ITF_UM1_MISR44_Msk  (0x1UL << FLASH_REG_ITF_UM1_MISR44_Pos)         /*!< 0x00001000 */
#define FLASH_REG_ITF_UM1_MISR44      FLASH_REG_ITF_UM1_MISR44_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM1_MISR45_Pos  (13U)
#define FLASH_REG_ITF_UM1_MISR45_Msk  (0x1UL << FLASH_REG_ITF_UM1_MISR45_Pos)         /*!< 0x00002000 */
#define FLASH_REG_ITF_UM1_MISR45      FLASH_REG_ITF_UM1_MISR45_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM1_MISR46_Pos  (14U)
#define FLASH_REG_ITF_UM1_MISR46_Msk  (0x1UL << FLASH_REG_ITF_UM1_MISR46_Pos)         /*!< 0x00004000 */
#define FLASH_REG_ITF_UM1_MISR46      FLASH_REG_ITF_UM1_MISR46_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM1_MISR47_Pos  (15U)
#define FLASH_REG_ITF_UM1_MISR47_Msk  (0x1UL << FLASH_REG_ITF_UM1_MISR47_Pos)         /*!< 0x00008000 */
#define FLASH_REG_ITF_UM1_MISR47      FLASH_REG_ITF_UM1_MISR47_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM1_MISR48_Pos  (16U)
#define FLASH_REG_ITF_UM1_MISR48_Msk  (0x1UL << FLASH_REG_ITF_UM1_MISR48_Pos)         /*!< 0x00010000 */
#define FLASH_REG_ITF_UM1_MISR48      FLASH_REG_ITF_UM1_MISR48_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM1_MISR49_Pos  (17U)
#define FLASH_REG_ITF_UM1_MISR49_Msk  (0x1UL << FLASH_REG_ITF_UM1_MISR49_Pos)         /*!< 0x00020000 */
#define FLASH_REG_ITF_UM1_MISR49      FLASH_REG_ITF_UM1_MISR49_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM1_MISR50_Pos  (18U)
#define FLASH_REG_ITF_UM1_MISR50_Msk  (0x1UL << FLASH_REG_ITF_UM1_MISR50_Pos)         /*!< 0x00040000 */
#define FLASH_REG_ITF_UM1_MISR50      FLASH_REG_ITF_UM1_MISR50_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM1_MISR51_Pos  (19U)
#define FLASH_REG_ITF_UM1_MISR51_Msk  (0x1UL << FLASH_REG_ITF_UM1_MISR51_Pos)         /*!< 0x00080000 */
#define FLASH_REG_ITF_UM1_MISR51      FLASH_REG_ITF_UM1_MISR51_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM1_MISR52_Pos  (20U)
#define FLASH_REG_ITF_UM1_MISR52_Msk  (0x1UL << FLASH_REG_ITF_UM1_MISR52_Pos)         /*!< 0x00100000 */
#define FLASH_REG_ITF_UM1_MISR52      FLASH_REG_ITF_UM1_MISR52_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM1_MISR53_Pos  (21U)
#define FLASH_REG_ITF_UM1_MISR53_Msk  (0x1UL << FLASH_REG_ITF_UM1_MISR53_Pos)         /*!< 0x00200000 */
#define FLASH_REG_ITF_UM1_MISR53      FLASH_REG_ITF_UM1_MISR53_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM1_MISR54_Pos  (22U)
#define FLASH_REG_ITF_UM1_MISR54_Msk  (0x1UL << FLASH_REG_ITF_UM1_MISR54_Pos)         /*!< 0x00400000 */
#define FLASH_REG_ITF_UM1_MISR54      FLASH_REG_ITF_UM1_MISR54_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM1_MISR55_Pos  (23U)
#define FLASH_REG_ITF_UM1_MISR55_Msk  (0x1UL << FLASH_REG_ITF_UM1_MISR55_Pos)         /*!< 0x00800000 */
#define FLASH_REG_ITF_UM1_MISR55      FLASH_REG_ITF_UM1_MISR55_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM1_MISR56_Pos  (24U)
#define FLASH_REG_ITF_UM1_MISR56_Msk  (0x1UL << FLASH_REG_ITF_UM1_MISR56_Pos)         /*!< 0x01000000 */
#define FLASH_REG_ITF_UM1_MISR56      FLASH_REG_ITF_UM1_MISR56_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM1_MISR57_Pos  (25U)
#define FLASH_REG_ITF_UM1_MISR57_Msk  (0x1UL << FLASH_REG_ITF_UM1_MISR57_Pos)         /*!< 0x02000000 */
#define FLASH_REG_ITF_UM1_MISR57      FLASH_REG_ITF_UM1_MISR57_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM1_MISR58_Pos  (26U)
#define FLASH_REG_ITF_UM1_MISR58_Msk  (0x1UL << FLASH_REG_ITF_UM1_MISR58_Pos)         /*!< 0x04000000 */
#define FLASH_REG_ITF_UM1_MISR58      FLASH_REG_ITF_UM1_MISR58_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM1_MISR59_Pos  (27U)
#define FLASH_REG_ITF_UM1_MISR59_Msk  (0x1UL << FLASH_REG_ITF_UM1_MISR59_Pos)         /*!< 0x08000000 */
#define FLASH_REG_ITF_UM1_MISR59      FLASH_REG_ITF_UM1_MISR59_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM1_MISR60_Pos  (28U)
#define FLASH_REG_ITF_UM1_MISR60_Msk  (0x1UL << FLASH_REG_ITF_UM1_MISR60_Pos)         /*!< 0x10000000 */
#define FLASH_REG_ITF_UM1_MISR60      FLASH_REG_ITF_UM1_MISR60_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM1_MISR61_Pos  (29U)
#define FLASH_REG_ITF_UM1_MISR61_Msk  (0x1UL << FLASH_REG_ITF_UM1_MISR61_Pos)         /*!< 0x20000000 */
#define FLASH_REG_ITF_UM1_MISR61      FLASH_REG_ITF_UM1_MISR61_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM1_MISR62_Pos  (30U)
#define FLASH_REG_ITF_UM1_MISR62_Msk  (0x1UL << FLASH_REG_ITF_UM1_MISR62_Pos)         /*!< 0x40000000 */
#define FLASH_REG_ITF_UM1_MISR62      FLASH_REG_ITF_UM1_MISR62_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM1_MISR63_Pos  (31U)
#define FLASH_REG_ITF_UM1_MISR63_Msk  (0x1UL << FLASH_REG_ITF_UM1_MISR63_Pos)         /*!< 0x80000000 */
#define FLASH_REG_ITF_UM1_MISR63      FLASH_REG_ITF_UM1_MISR63_Msk                   /*!< </spirit:description> */

/**************  Bit definition for FLASH_REG_ITF_UM2 register  ***************/
#define FLASH_REG_ITF_UM2_MISR64_Pos  (0U)
#define FLASH_REG_ITF_UM2_MISR64_Msk  (0x1UL << FLASH_REG_ITF_UM2_MISR64_Pos)         /*!< 0x00000001 */
#define FLASH_REG_ITF_UM2_MISR64      FLASH_REG_ITF_UM2_MISR64_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM2_MISR65_Pos  (1U)
#define FLASH_REG_ITF_UM2_MISR65_Msk  (0x1UL << FLASH_REG_ITF_UM2_MISR65_Pos)         /*!< 0x00000002 */
#define FLASH_REG_ITF_UM2_MISR65      FLASH_REG_ITF_UM2_MISR65_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM2_MISR66_Pos  (2U)
#define FLASH_REG_ITF_UM2_MISR66_Msk  (0x1UL << FLASH_REG_ITF_UM2_MISR66_Pos)         /*!< 0x00000004 */
#define FLASH_REG_ITF_UM2_MISR66      FLASH_REG_ITF_UM2_MISR66_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM2_MISR67_Pos  (3U)
#define FLASH_REG_ITF_UM2_MISR67_Msk  (0x1UL << FLASH_REG_ITF_UM2_MISR67_Pos)         /*!< 0x00000008 */
#define FLASH_REG_ITF_UM2_MISR67      FLASH_REG_ITF_UM2_MISR67_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM2_MISR68_Pos  (4U)
#define FLASH_REG_ITF_UM2_MISR68_Msk  (0x1UL << FLASH_REG_ITF_UM2_MISR68_Pos)         /*!< 0x00000010 */
#define FLASH_REG_ITF_UM2_MISR68      FLASH_REG_ITF_UM2_MISR68_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM2_MISR69_Pos  (5U)
#define FLASH_REG_ITF_UM2_MISR69_Msk  (0x1UL << FLASH_REG_ITF_UM2_MISR69_Pos)         /*!< 0x00000020 */
#define FLASH_REG_ITF_UM2_MISR69      FLASH_REG_ITF_UM2_MISR69_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM2_MISR70_Pos  (6U)
#define FLASH_REG_ITF_UM2_MISR70_Msk  (0x1UL << FLASH_REG_ITF_UM2_MISR70_Pos)         /*!< 0x00000040 */
#define FLASH_REG_ITF_UM2_MISR70      FLASH_REG_ITF_UM2_MISR70_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM2_MISR71_Pos  (7U)
#define FLASH_REG_ITF_UM2_MISR71_Msk  (0x1UL << FLASH_REG_ITF_UM2_MISR71_Pos)         /*!< 0x00000080 */
#define FLASH_REG_ITF_UM2_MISR71      FLASH_REG_ITF_UM2_MISR71_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM2_MISR72_Pos  (8U)
#define FLASH_REG_ITF_UM2_MISR72_Msk  (0x1UL << FLASH_REG_ITF_UM2_MISR72_Pos)         /*!< 0x00000100 */
#define FLASH_REG_ITF_UM2_MISR72      FLASH_REG_ITF_UM2_MISR72_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM2_MISR73_Pos  (9U)
#define FLASH_REG_ITF_UM2_MISR73_Msk  (0x1UL << FLASH_REG_ITF_UM2_MISR73_Pos)         /*!< 0x00000200 */
#define FLASH_REG_ITF_UM2_MISR73      FLASH_REG_ITF_UM2_MISR73_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM2_MISR74_Pos  (10U)
#define FLASH_REG_ITF_UM2_MISR74_Msk  (0x1UL << FLASH_REG_ITF_UM2_MISR74_Pos)         /*!< 0x00000400 */
#define FLASH_REG_ITF_UM2_MISR74      FLASH_REG_ITF_UM2_MISR74_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM2_MISR75_Pos  (11U)
#define FLASH_REG_ITF_UM2_MISR75_Msk  (0x1UL << FLASH_REG_ITF_UM2_MISR75_Pos)         /*!< 0x00000800 */
#define FLASH_REG_ITF_UM2_MISR75      FLASH_REG_ITF_UM2_MISR75_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM2_MISR76_Pos  (12U)
#define FLASH_REG_ITF_UM2_MISR76_Msk  (0x1UL << FLASH_REG_ITF_UM2_MISR76_Pos)         /*!< 0x00001000 */
#define FLASH_REG_ITF_UM2_MISR76      FLASH_REG_ITF_UM2_MISR76_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM2_MISR77_Pos  (13U)
#define FLASH_REG_ITF_UM2_MISR77_Msk  (0x1UL << FLASH_REG_ITF_UM2_MISR77_Pos)         /*!< 0x00002000 */
#define FLASH_REG_ITF_UM2_MISR77      FLASH_REG_ITF_UM2_MISR77_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM2_MISR78_Pos  (14U)
#define FLASH_REG_ITF_UM2_MISR78_Msk  (0x1UL << FLASH_REG_ITF_UM2_MISR78_Pos)         /*!< 0x00004000 */
#define FLASH_REG_ITF_UM2_MISR78      FLASH_REG_ITF_UM2_MISR78_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM2_MISR79_Pos  (15U)
#define FLASH_REG_ITF_UM2_MISR79_Msk  (0x1UL << FLASH_REG_ITF_UM2_MISR79_Pos)         /*!< 0x00008000 */
#define FLASH_REG_ITF_UM2_MISR79      FLASH_REG_ITF_UM2_MISR79_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM2_MISR80_Pos  (16U)
#define FLASH_REG_ITF_UM2_MISR80_Msk  (0x1UL << FLASH_REG_ITF_UM2_MISR80_Pos)         /*!< 0x00010000 */
#define FLASH_REG_ITF_UM2_MISR80      FLASH_REG_ITF_UM2_MISR80_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM2_MISR81_Pos  (17U)
#define FLASH_REG_ITF_UM2_MISR81_Msk  (0x1UL << FLASH_REG_ITF_UM2_MISR81_Pos)         /*!< 0x00020000 */
#define FLASH_REG_ITF_UM2_MISR81      FLASH_REG_ITF_UM2_MISR81_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM2_MISR82_Pos  (18U)
#define FLASH_REG_ITF_UM2_MISR82_Msk  (0x1UL << FLASH_REG_ITF_UM2_MISR82_Pos)         /*!< 0x00040000 */
#define FLASH_REG_ITF_UM2_MISR82      FLASH_REG_ITF_UM2_MISR82_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM2_MISR83_Pos  (19U)
#define FLASH_REG_ITF_UM2_MISR83_Msk  (0x1UL << FLASH_REG_ITF_UM2_MISR83_Pos)         /*!< 0x00080000 */
#define FLASH_REG_ITF_UM2_MISR83      FLASH_REG_ITF_UM2_MISR83_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM2_MISR84_Pos  (20U)
#define FLASH_REG_ITF_UM2_MISR84_Msk  (0x1UL << FLASH_REG_ITF_UM2_MISR84_Pos)         /*!< 0x00100000 */
#define FLASH_REG_ITF_UM2_MISR84      FLASH_REG_ITF_UM2_MISR84_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM2_MISR85_Pos  (21U)
#define FLASH_REG_ITF_UM2_MISR85_Msk  (0x1UL << FLASH_REG_ITF_UM2_MISR85_Pos)         /*!< 0x00200000 */
#define FLASH_REG_ITF_UM2_MISR85      FLASH_REG_ITF_UM2_MISR85_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM2_MISR86_Pos  (22U)
#define FLASH_REG_ITF_UM2_MISR86_Msk  (0x1UL << FLASH_REG_ITF_UM2_MISR86_Pos)         /*!< 0x00400000 */
#define FLASH_REG_ITF_UM2_MISR86      FLASH_REG_ITF_UM2_MISR86_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM2_MISR87_Pos  (23U)
#define FLASH_REG_ITF_UM2_MISR87_Msk  (0x1UL << FLASH_REG_ITF_UM2_MISR87_Pos)         /*!< 0x00800000 */
#define FLASH_REG_ITF_UM2_MISR87      FLASH_REG_ITF_UM2_MISR87_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM2_MISR88_Pos  (24U)
#define FLASH_REG_ITF_UM2_MISR88_Msk  (0x1UL << FLASH_REG_ITF_UM2_MISR88_Pos)         /*!< 0x01000000 */
#define FLASH_REG_ITF_UM2_MISR88      FLASH_REG_ITF_UM2_MISR88_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM2_MISR89_Pos  (25U)
#define FLASH_REG_ITF_UM2_MISR89_Msk  (0x1UL << FLASH_REG_ITF_UM2_MISR89_Pos)         /*!< 0x02000000 */
#define FLASH_REG_ITF_UM2_MISR89      FLASH_REG_ITF_UM2_MISR89_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM2_MISR90_Pos  (26U)
#define FLASH_REG_ITF_UM2_MISR90_Msk  (0x1UL << FLASH_REG_ITF_UM2_MISR90_Pos)         /*!< 0x04000000 */
#define FLASH_REG_ITF_UM2_MISR90      FLASH_REG_ITF_UM2_MISR90_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM2_MISR91_Pos  (27U)
#define FLASH_REG_ITF_UM2_MISR91_Msk  (0x1UL << FLASH_REG_ITF_UM2_MISR91_Pos)         /*!< 0x08000000 */
#define FLASH_REG_ITF_UM2_MISR91      FLASH_REG_ITF_UM2_MISR91_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM2_MISR92_Pos  (28U)
#define FLASH_REG_ITF_UM2_MISR92_Msk  (0x1UL << FLASH_REG_ITF_UM2_MISR92_Pos)         /*!< 0x10000000 */
#define FLASH_REG_ITF_UM2_MISR92      FLASH_REG_ITF_UM2_MISR92_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM2_MISR93_Pos  (29U)
#define FLASH_REG_ITF_UM2_MISR93_Msk  (0x1UL << FLASH_REG_ITF_UM2_MISR93_Pos)         /*!< 0x20000000 */
#define FLASH_REG_ITF_UM2_MISR93      FLASH_REG_ITF_UM2_MISR93_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM2_MISR94_Pos  (30U)
#define FLASH_REG_ITF_UM2_MISR94_Msk  (0x1UL << FLASH_REG_ITF_UM2_MISR94_Pos)         /*!< 0x40000000 */
#define FLASH_REG_ITF_UM2_MISR94      FLASH_REG_ITF_UM2_MISR94_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM2_MISR95_Pos  (31U)
#define FLASH_REG_ITF_UM2_MISR95_Msk  (0x1UL << FLASH_REG_ITF_UM2_MISR95_Pos)         /*!< 0x80000000 */
#define FLASH_REG_ITF_UM2_MISR95      FLASH_REG_ITF_UM2_MISR95_Msk                   /*!< </spirit:description> */

/**************  Bit definition for FLASH_REG_ITF_UM3 register  ***************/
#define FLASH_REG_ITF_UM3_MISR96_Pos  (0U)
#define FLASH_REG_ITF_UM3_MISR96_Msk  (0x1UL << FLASH_REG_ITF_UM3_MISR96_Pos)         /*!< 0x00000001 */
#define FLASH_REG_ITF_UM3_MISR96      FLASH_REG_ITF_UM3_MISR96_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM3_MISR97_Pos  (1U)
#define FLASH_REG_ITF_UM3_MISR97_Msk  (0x1UL << FLASH_REG_ITF_UM3_MISR97_Pos)         /*!< 0x00000002 */
#define FLASH_REG_ITF_UM3_MISR97      FLASH_REG_ITF_UM3_MISR97_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM3_MISR98_Pos  (2U)
#define FLASH_REG_ITF_UM3_MISR98_Msk  (0x1UL << FLASH_REG_ITF_UM3_MISR98_Pos)         /*!< 0x00000004 */
#define FLASH_REG_ITF_UM3_MISR98      FLASH_REG_ITF_UM3_MISR98_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM3_MISR99_Pos  (3U)
#define FLASH_REG_ITF_UM3_MISR99_Msk  (0x1UL << FLASH_REG_ITF_UM3_MISR99_Pos)         /*!< 0x00000008 */
#define FLASH_REG_ITF_UM3_MISR99      FLASH_REG_ITF_UM3_MISR99_Msk                   /*!< </spirit:description> */
#define FLASH_REG_ITF_UM3_MISR100_Pos (4U)
#define FLASH_REG_ITF_UM3_MISR100_Msk (0x1UL << FLASH_REG_ITF_UM3_MISR100_Pos)        /*!< 0x00000010 */
#define FLASH_REG_ITF_UM3_MISR100     FLASH_REG_ITF_UM3_MISR100_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM3_MISR101_Pos (5U)
#define FLASH_REG_ITF_UM3_MISR101_Msk (0x1UL << FLASH_REG_ITF_UM3_MISR101_Pos)        /*!< 0x00000020 */
#define FLASH_REG_ITF_UM3_MISR101     FLASH_REG_ITF_UM3_MISR101_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM3_MISR102_Pos (6U)
#define FLASH_REG_ITF_UM3_MISR102_Msk (0x1UL << FLASH_REG_ITF_UM3_MISR102_Pos)        /*!< 0x00000040 */
#define FLASH_REG_ITF_UM3_MISR102     FLASH_REG_ITF_UM3_MISR102_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM3_MISR103_Pos (7U)
#define FLASH_REG_ITF_UM3_MISR103_Msk (0x1UL << FLASH_REG_ITF_UM3_MISR103_Pos)        /*!< 0x00000080 */
#define FLASH_REG_ITF_UM3_MISR103     FLASH_REG_ITF_UM3_MISR103_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM3_MISR104_Pos (8U)
#define FLASH_REG_ITF_UM3_MISR104_Msk (0x1UL << FLASH_REG_ITF_UM3_MISR104_Pos)        /*!< 0x00000100 */
#define FLASH_REG_ITF_UM3_MISR104     FLASH_REG_ITF_UM3_MISR104_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM3_MISR105_Pos (9U)
#define FLASH_REG_ITF_UM3_MISR105_Msk (0x1UL << FLASH_REG_ITF_UM3_MISR105_Pos)        /*!< 0x00000200 */
#define FLASH_REG_ITF_UM3_MISR105     FLASH_REG_ITF_UM3_MISR105_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM3_MISR106_Pos (10U)
#define FLASH_REG_ITF_UM3_MISR106_Msk (0x1UL << FLASH_REG_ITF_UM3_MISR106_Pos)        /*!< 0x00000400 */
#define FLASH_REG_ITF_UM3_MISR106     FLASH_REG_ITF_UM3_MISR106_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM3_MISR107_Pos (11U)
#define FLASH_REG_ITF_UM3_MISR107_Msk (0x1UL << FLASH_REG_ITF_UM3_MISR107_Pos)        /*!< 0x00000800 */
#define FLASH_REG_ITF_UM3_MISR107     FLASH_REG_ITF_UM3_MISR107_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM3_MISR108_Pos (12U)
#define FLASH_REG_ITF_UM3_MISR108_Msk (0x1UL << FLASH_REG_ITF_UM3_MISR108_Pos)        /*!< 0x00001000 */
#define FLASH_REG_ITF_UM3_MISR108     FLASH_REG_ITF_UM3_MISR108_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM3_MISR109_Pos (13U)
#define FLASH_REG_ITF_UM3_MISR109_Msk (0x1UL << FLASH_REG_ITF_UM3_MISR109_Pos)        /*!< 0x00002000 */
#define FLASH_REG_ITF_UM3_MISR109     FLASH_REG_ITF_UM3_MISR109_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM3_MISR110_Pos (14U)
#define FLASH_REG_ITF_UM3_MISR110_Msk (0x1UL << FLASH_REG_ITF_UM3_MISR110_Pos)        /*!< 0x00004000 */
#define FLASH_REG_ITF_UM3_MISR110     FLASH_REG_ITF_UM3_MISR110_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM3_MISR111_Pos (15U)
#define FLASH_REG_ITF_UM3_MISR111_Msk (0x1UL << FLASH_REG_ITF_UM3_MISR111_Pos)        /*!< 0x00008000 */
#define FLASH_REG_ITF_UM3_MISR111     FLASH_REG_ITF_UM3_MISR111_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM3_MISR112_Pos (16U)
#define FLASH_REG_ITF_UM3_MISR112_Msk (0x1UL << FLASH_REG_ITF_UM3_MISR112_Pos)        /*!< 0x00010000 */
#define FLASH_REG_ITF_UM3_MISR112     FLASH_REG_ITF_UM3_MISR112_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM3_MISR113_Pos (17U)
#define FLASH_REG_ITF_UM3_MISR113_Msk (0x1UL << FLASH_REG_ITF_UM3_MISR113_Pos)        /*!< 0x00020000 */
#define FLASH_REG_ITF_UM3_MISR113     FLASH_REG_ITF_UM3_MISR113_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM3_MISR114_Pos (18U)
#define FLASH_REG_ITF_UM3_MISR114_Msk (0x1UL << FLASH_REG_ITF_UM3_MISR114_Pos)        /*!< 0x00040000 */
#define FLASH_REG_ITF_UM3_MISR114     FLASH_REG_ITF_UM3_MISR114_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM3_MISR115_Pos (19U)
#define FLASH_REG_ITF_UM3_MISR115_Msk (0x1UL << FLASH_REG_ITF_UM3_MISR115_Pos)        /*!< 0x00080000 */
#define FLASH_REG_ITF_UM3_MISR115     FLASH_REG_ITF_UM3_MISR115_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM3_MISR116_Pos (20U)
#define FLASH_REG_ITF_UM3_MISR116_Msk (0x1UL << FLASH_REG_ITF_UM3_MISR116_Pos)        /*!< 0x00100000 */
#define FLASH_REG_ITF_UM3_MISR116     FLASH_REG_ITF_UM3_MISR116_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM3_MISR117_Pos (21U)
#define FLASH_REG_ITF_UM3_MISR117_Msk (0x1UL << FLASH_REG_ITF_UM3_MISR117_Pos)        /*!< 0x00200000 */
#define FLASH_REG_ITF_UM3_MISR117     FLASH_REG_ITF_UM3_MISR117_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM3_MISR118_Pos (22U)
#define FLASH_REG_ITF_UM3_MISR118_Msk (0x1UL << FLASH_REG_ITF_UM3_MISR118_Pos)        /*!< 0x00400000 */
#define FLASH_REG_ITF_UM3_MISR118     FLASH_REG_ITF_UM3_MISR118_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM3_MISR119_Pos (23U)
#define FLASH_REG_ITF_UM3_MISR119_Msk (0x1UL << FLASH_REG_ITF_UM3_MISR119_Pos)        /*!< 0x00800000 */
#define FLASH_REG_ITF_UM3_MISR119     FLASH_REG_ITF_UM3_MISR119_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM3_MISR120_Pos (24U)
#define FLASH_REG_ITF_UM3_MISR120_Msk (0x1UL << FLASH_REG_ITF_UM3_MISR120_Pos)        /*!< 0x01000000 */
#define FLASH_REG_ITF_UM3_MISR120     FLASH_REG_ITF_UM3_MISR120_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM3_MISR121_Pos (25U)
#define FLASH_REG_ITF_UM3_MISR121_Msk (0x1UL << FLASH_REG_ITF_UM3_MISR121_Pos)        /*!< 0x02000000 */
#define FLASH_REG_ITF_UM3_MISR121     FLASH_REG_ITF_UM3_MISR121_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM3_MISR122_Pos (26U)
#define FLASH_REG_ITF_UM3_MISR122_Msk (0x1UL << FLASH_REG_ITF_UM3_MISR122_Pos)        /*!< 0x04000000 */
#define FLASH_REG_ITF_UM3_MISR122     FLASH_REG_ITF_UM3_MISR122_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM3_MISR123_Pos (27U)
#define FLASH_REG_ITF_UM3_MISR123_Msk (0x1UL << FLASH_REG_ITF_UM3_MISR123_Pos)        /*!< 0x08000000 */
#define FLASH_REG_ITF_UM3_MISR123     FLASH_REG_ITF_UM3_MISR123_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM3_MISR124_Pos (28U)
#define FLASH_REG_ITF_UM3_MISR124_Msk (0x1UL << FLASH_REG_ITF_UM3_MISR124_Pos)        /*!< 0x10000000 */
#define FLASH_REG_ITF_UM3_MISR124     FLASH_REG_ITF_UM3_MISR124_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM3_MISR125_Pos (29U)
#define FLASH_REG_ITF_UM3_MISR125_Msk (0x1UL << FLASH_REG_ITF_UM3_MISR125_Pos)        /*!< 0x20000000 */
#define FLASH_REG_ITF_UM3_MISR125     FLASH_REG_ITF_UM3_MISR125_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM3_MISR126_Pos (30U)
#define FLASH_REG_ITF_UM3_MISR126_Msk (0x1UL << FLASH_REG_ITF_UM3_MISR126_Pos)        /*!< 0x40000000 */
#define FLASH_REG_ITF_UM3_MISR126     FLASH_REG_ITF_UM3_MISR126_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM3_MISR127_Pos (31U)
#define FLASH_REG_ITF_UM3_MISR127_Msk (0x1UL << FLASH_REG_ITF_UM3_MISR127_Pos)        /*!< 0x80000000 */
#define FLASH_REG_ITF_UM3_MISR127     FLASH_REG_ITF_UM3_MISR127_Msk                  /*!< </spirit:description> */

/**************  Bit definition for FLASH_REG_ITF_UM4 register  ***************/
#define FLASH_REG_ITF_UM4_MISR128_Pos (0U)
#define FLASH_REG_ITF_UM4_MISR128_Msk (0x1UL << FLASH_REG_ITF_UM4_MISR128_Pos)        /*!< 0x00000001 */
#define FLASH_REG_ITF_UM4_MISR128     FLASH_REG_ITF_UM4_MISR128_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM4_MISR129_Pos (1U)
#define FLASH_REG_ITF_UM4_MISR129_Msk (0x1UL << FLASH_REG_ITF_UM4_MISR129_Pos)        /*!< 0x00000002 */
#define FLASH_REG_ITF_UM4_MISR129     FLASH_REG_ITF_UM4_MISR129_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM4_MISR130_Pos (2U)
#define FLASH_REG_ITF_UM4_MISR130_Msk (0x1UL << FLASH_REG_ITF_UM4_MISR130_Pos)        /*!< 0x00000004 */
#define FLASH_REG_ITF_UM4_MISR130     FLASH_REG_ITF_UM4_MISR130_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM4_MISR131_Pos (3U)
#define FLASH_REG_ITF_UM4_MISR131_Msk (0x1UL << FLASH_REG_ITF_UM4_MISR131_Pos)        /*!< 0x00000008 */
#define FLASH_REG_ITF_UM4_MISR131     FLASH_REG_ITF_UM4_MISR131_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM4_MISR132_Pos (4U)
#define FLASH_REG_ITF_UM4_MISR132_Msk (0x1UL << FLASH_REG_ITF_UM4_MISR132_Pos)        /*!< 0x00000010 */
#define FLASH_REG_ITF_UM4_MISR132     FLASH_REG_ITF_UM4_MISR132_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM4_MISR133_Pos (5U)
#define FLASH_REG_ITF_UM4_MISR133_Msk (0x1UL << FLASH_REG_ITF_UM4_MISR133_Pos)        /*!< 0x00000020 */
#define FLASH_REG_ITF_UM4_MISR133     FLASH_REG_ITF_UM4_MISR133_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM4_MISR134_Pos (6U)
#define FLASH_REG_ITF_UM4_MISR134_Msk (0x1UL << FLASH_REG_ITF_UM4_MISR134_Pos)        /*!< 0x00000040 */
#define FLASH_REG_ITF_UM4_MISR134     FLASH_REG_ITF_UM4_MISR134_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM4_MISR135_Pos (7U)
#define FLASH_REG_ITF_UM4_MISR135_Msk (0x1UL << FLASH_REG_ITF_UM4_MISR135_Pos)        /*!< 0x00000080 */
#define FLASH_REG_ITF_UM4_MISR135     FLASH_REG_ITF_UM4_MISR135_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM4_MISR136_Pos (8U)
#define FLASH_REG_ITF_UM4_MISR136_Msk (0x1UL << FLASH_REG_ITF_UM4_MISR136_Pos)        /*!< 0x00000100 */
#define FLASH_REG_ITF_UM4_MISR136     FLASH_REG_ITF_UM4_MISR136_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM4_MISR137_Pos (9U)
#define FLASH_REG_ITF_UM4_MISR137_Msk (0x1UL << FLASH_REG_ITF_UM4_MISR137_Pos)        /*!< 0x00000200 */
#define FLASH_REG_ITF_UM4_MISR137     FLASH_REG_ITF_UM4_MISR137_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM4_MISR138_Pos (10U)
#define FLASH_REG_ITF_UM4_MISR138_Msk (0x1UL << FLASH_REG_ITF_UM4_MISR138_Pos)        /*!< 0x00000400 */
#define FLASH_REG_ITF_UM4_MISR138     FLASH_REG_ITF_UM4_MISR138_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM4_MISR139_Pos (11U)
#define FLASH_REG_ITF_UM4_MISR139_Msk (0x1UL << FLASH_REG_ITF_UM4_MISR139_Pos)        /*!< 0x00000800 */
#define FLASH_REG_ITF_UM4_MISR139     FLASH_REG_ITF_UM4_MISR139_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM4_MISR140_Pos (12U)
#define FLASH_REG_ITF_UM4_MISR140_Msk (0x1UL << FLASH_REG_ITF_UM4_MISR140_Pos)        /*!< 0x00001000 */
#define FLASH_REG_ITF_UM4_MISR140     FLASH_REG_ITF_UM4_MISR140_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM4_MISR141_Pos (13U)
#define FLASH_REG_ITF_UM4_MISR141_Msk (0x1UL << FLASH_REG_ITF_UM4_MISR141_Pos)        /*!< 0x00002000 */
#define FLASH_REG_ITF_UM4_MISR141     FLASH_REG_ITF_UM4_MISR141_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM4_MISR142_Pos (14U)
#define FLASH_REG_ITF_UM4_MISR142_Msk (0x1UL << FLASH_REG_ITF_UM4_MISR142_Pos)        /*!< 0x00004000 */
#define FLASH_REG_ITF_UM4_MISR142     FLASH_REG_ITF_UM4_MISR142_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM4_MISR143_Pos (15U)
#define FLASH_REG_ITF_UM4_MISR143_Msk (0x1UL << FLASH_REG_ITF_UM4_MISR143_Pos)        /*!< 0x00008000 */
#define FLASH_REG_ITF_UM4_MISR143     FLASH_REG_ITF_UM4_MISR143_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM4_MISR144_Pos (16U)
#define FLASH_REG_ITF_UM4_MISR144_Msk (0x1UL << FLASH_REG_ITF_UM4_MISR144_Pos)        /*!< 0x00010000 */
#define FLASH_REG_ITF_UM4_MISR144     FLASH_REG_ITF_UM4_MISR144_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM4_MISR145_Pos (17U)
#define FLASH_REG_ITF_UM4_MISR145_Msk (0x1UL << FLASH_REG_ITF_UM4_MISR145_Pos)        /*!< 0x00020000 */
#define FLASH_REG_ITF_UM4_MISR145     FLASH_REG_ITF_UM4_MISR145_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM4_MISR146_Pos (18U)
#define FLASH_REG_ITF_UM4_MISR146_Msk (0x1UL << FLASH_REG_ITF_UM4_MISR146_Pos)        /*!< 0x00040000 */
#define FLASH_REG_ITF_UM4_MISR146     FLASH_REG_ITF_UM4_MISR146_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM4_MISR147_Pos (19U)
#define FLASH_REG_ITF_UM4_MISR147_Msk (0x1UL << FLASH_REG_ITF_UM4_MISR147_Pos)        /*!< 0x00080000 */
#define FLASH_REG_ITF_UM4_MISR147     FLASH_REG_ITF_UM4_MISR147_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM4_MISR148_Pos (20U)
#define FLASH_REG_ITF_UM4_MISR148_Msk (0x1UL << FLASH_REG_ITF_UM4_MISR148_Pos)        /*!< 0x00100000 */
#define FLASH_REG_ITF_UM4_MISR148     FLASH_REG_ITF_UM4_MISR148_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM4_MISR149_Pos (21U)
#define FLASH_REG_ITF_UM4_MISR149_Msk (0x1UL << FLASH_REG_ITF_UM4_MISR149_Pos)        /*!< 0x00200000 */
#define FLASH_REG_ITF_UM4_MISR149     FLASH_REG_ITF_UM4_MISR149_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM4_MISR150_Pos (22U)
#define FLASH_REG_ITF_UM4_MISR150_Msk (0x1UL << FLASH_REG_ITF_UM4_MISR150_Pos)        /*!< 0x00400000 */
#define FLASH_REG_ITF_UM4_MISR150     FLASH_REG_ITF_UM4_MISR150_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM4_MISR151_Pos (23U)
#define FLASH_REG_ITF_UM4_MISR151_Msk (0x1UL << FLASH_REG_ITF_UM4_MISR151_Pos)        /*!< 0x00800000 */
#define FLASH_REG_ITF_UM4_MISR151     FLASH_REG_ITF_UM4_MISR151_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM4_MISR152_Pos (24U)
#define FLASH_REG_ITF_UM4_MISR152_Msk (0x1UL << FLASH_REG_ITF_UM4_MISR152_Pos)        /*!< 0x01000000 */
#define FLASH_REG_ITF_UM4_MISR152     FLASH_REG_ITF_UM4_MISR152_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM4_MISR153_Pos (25U)
#define FLASH_REG_ITF_UM4_MISR153_Msk (0x1UL << FLASH_REG_ITF_UM4_MISR153_Pos)        /*!< 0x02000000 */
#define FLASH_REG_ITF_UM4_MISR153     FLASH_REG_ITF_UM4_MISR153_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM4_MISR154_Pos (26U)
#define FLASH_REG_ITF_UM4_MISR154_Msk (0x1UL << FLASH_REG_ITF_UM4_MISR154_Pos)        /*!< 0x04000000 */
#define FLASH_REG_ITF_UM4_MISR154     FLASH_REG_ITF_UM4_MISR154_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM4_MISR155_Pos (27U)
#define FLASH_REG_ITF_UM4_MISR155_Msk (0x1UL << FLASH_REG_ITF_UM4_MISR155_Pos)        /*!< 0x08000000 */
#define FLASH_REG_ITF_UM4_MISR155     FLASH_REG_ITF_UM4_MISR155_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM4_MISR156_Pos (28U)
#define FLASH_REG_ITF_UM4_MISR156_Msk (0x1UL << FLASH_REG_ITF_UM4_MISR156_Pos)        /*!< 0x10000000 */
#define FLASH_REG_ITF_UM4_MISR156     FLASH_REG_ITF_UM4_MISR156_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM4_MISR157_Pos (29U)
#define FLASH_REG_ITF_UM4_MISR157_Msk (0x1UL << FLASH_REG_ITF_UM4_MISR157_Pos)        /*!< 0x20000000 */
#define FLASH_REG_ITF_UM4_MISR157     FLASH_REG_ITF_UM4_MISR157_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM4_MISR158_Pos (30U)
#define FLASH_REG_ITF_UM4_MISR158_Msk (0x1UL << FLASH_REG_ITF_UM4_MISR158_Pos)        /*!< 0x40000000 */
#define FLASH_REG_ITF_UM4_MISR158     FLASH_REG_ITF_UM4_MISR158_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM4_MISR159_Pos (31U)
#define FLASH_REG_ITF_UM4_MISR159_Msk (0x1UL << FLASH_REG_ITF_UM4_MISR159_Pos)        /*!< 0x80000000 */
#define FLASH_REG_ITF_UM4_MISR159     FLASH_REG_ITF_UM4_MISR159_Msk                  /*!< </spirit:description> */

/**************  Bit definition for FLASH_REG_ITF_UM5 register  ***************/
#define FLASH_REG_ITF_UM5_MISR160_Pos (0U)
#define FLASH_REG_ITF_UM5_MISR160_Msk (0x1UL << FLASH_REG_ITF_UM5_MISR160_Pos)        /*!< 0x00000001 */
#define FLASH_REG_ITF_UM5_MISR160     FLASH_REG_ITF_UM5_MISR160_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM5_MISR161_Pos (1U)
#define FLASH_REG_ITF_UM5_MISR161_Msk (0x1UL << FLASH_REG_ITF_UM5_MISR161_Pos)        /*!< 0x00000002 */
#define FLASH_REG_ITF_UM5_MISR161     FLASH_REG_ITF_UM5_MISR161_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM5_MISR162_Pos (2U)
#define FLASH_REG_ITF_UM5_MISR162_Msk (0x1UL << FLASH_REG_ITF_UM5_MISR162_Pos)        /*!< 0x00000004 */
#define FLASH_REG_ITF_UM5_MISR162     FLASH_REG_ITF_UM5_MISR162_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM5_MISR163_Pos (3U)
#define FLASH_REG_ITF_UM5_MISR163_Msk (0x1UL << FLASH_REG_ITF_UM5_MISR163_Pos)        /*!< 0x00000008 */
#define FLASH_REG_ITF_UM5_MISR163     FLASH_REG_ITF_UM5_MISR163_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM5_MISR164_Pos (4U)
#define FLASH_REG_ITF_UM5_MISR164_Msk (0x1UL << FLASH_REG_ITF_UM5_MISR164_Pos)        /*!< 0x00000010 */
#define FLASH_REG_ITF_UM5_MISR164     FLASH_REG_ITF_UM5_MISR164_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM5_MISR165_Pos (5U)
#define FLASH_REG_ITF_UM5_MISR165_Msk (0x1UL << FLASH_REG_ITF_UM5_MISR165_Pos)        /*!< 0x00000020 */
#define FLASH_REG_ITF_UM5_MISR165     FLASH_REG_ITF_UM5_MISR165_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM5_MISR166_Pos (6U)
#define FLASH_REG_ITF_UM5_MISR166_Msk (0x1UL << FLASH_REG_ITF_UM5_MISR166_Pos)        /*!< 0x00000040 */
#define FLASH_REG_ITF_UM5_MISR166     FLASH_REG_ITF_UM5_MISR166_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM5_MISR167_Pos (7U)
#define FLASH_REG_ITF_UM5_MISR167_Msk (0x1UL << FLASH_REG_ITF_UM5_MISR167_Pos)        /*!< 0x00000080 */
#define FLASH_REG_ITF_UM5_MISR167     FLASH_REG_ITF_UM5_MISR167_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM5_MISR168_Pos (8U)
#define FLASH_REG_ITF_UM5_MISR168_Msk (0x1UL << FLASH_REG_ITF_UM5_MISR168_Pos)        /*!< 0x00000100 */
#define FLASH_REG_ITF_UM5_MISR168     FLASH_REG_ITF_UM5_MISR168_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM5_MISR169_Pos (9U)
#define FLASH_REG_ITF_UM5_MISR169_Msk (0x1UL << FLASH_REG_ITF_UM5_MISR169_Pos)        /*!< 0x00000200 */
#define FLASH_REG_ITF_UM5_MISR169     FLASH_REG_ITF_UM5_MISR169_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM5_MISR170_Pos (10U)
#define FLASH_REG_ITF_UM5_MISR170_Msk (0x1UL << FLASH_REG_ITF_UM5_MISR170_Pos)        /*!< 0x00000400 */
#define FLASH_REG_ITF_UM5_MISR170     FLASH_REG_ITF_UM5_MISR170_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM5_MISR171_Pos (11U)
#define FLASH_REG_ITF_UM5_MISR171_Msk (0x1UL << FLASH_REG_ITF_UM5_MISR171_Pos)        /*!< 0x00000800 */
#define FLASH_REG_ITF_UM5_MISR171     FLASH_REG_ITF_UM5_MISR171_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM5_MISR172_Pos (12U)
#define FLASH_REG_ITF_UM5_MISR172_Msk (0x1UL << FLASH_REG_ITF_UM5_MISR172_Pos)        /*!< 0x00001000 */
#define FLASH_REG_ITF_UM5_MISR172     FLASH_REG_ITF_UM5_MISR172_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM5_MISR173_Pos (13U)
#define FLASH_REG_ITF_UM5_MISR173_Msk (0x1UL << FLASH_REG_ITF_UM5_MISR173_Pos)        /*!< 0x00002000 */
#define FLASH_REG_ITF_UM5_MISR173     FLASH_REG_ITF_UM5_MISR173_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM5_MISR174_Pos (14U)
#define FLASH_REG_ITF_UM5_MISR174_Msk (0x1UL << FLASH_REG_ITF_UM5_MISR174_Pos)        /*!< 0x00004000 */
#define FLASH_REG_ITF_UM5_MISR174     FLASH_REG_ITF_UM5_MISR174_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM5_MISR175_Pos (15U)
#define FLASH_REG_ITF_UM5_MISR175_Msk (0x1UL << FLASH_REG_ITF_UM5_MISR175_Pos)        /*!< 0x00008000 */
#define FLASH_REG_ITF_UM5_MISR175     FLASH_REG_ITF_UM5_MISR175_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM5_MISR176_Pos (16U)
#define FLASH_REG_ITF_UM5_MISR176_Msk (0x1UL << FLASH_REG_ITF_UM5_MISR176_Pos)        /*!< 0x00010000 */
#define FLASH_REG_ITF_UM5_MISR176     FLASH_REG_ITF_UM5_MISR176_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM5_MISR177_Pos (17U)
#define FLASH_REG_ITF_UM5_MISR177_Msk (0x1UL << FLASH_REG_ITF_UM5_MISR177_Pos)        /*!< 0x00020000 */
#define FLASH_REG_ITF_UM5_MISR177     FLASH_REG_ITF_UM5_MISR177_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM5_MISR178_Pos (18U)
#define FLASH_REG_ITF_UM5_MISR178_Msk (0x1UL << FLASH_REG_ITF_UM5_MISR178_Pos)        /*!< 0x00040000 */
#define FLASH_REG_ITF_UM5_MISR178     FLASH_REG_ITF_UM5_MISR178_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM5_MISR179_Pos (19U)
#define FLASH_REG_ITF_UM5_MISR179_Msk (0x1UL << FLASH_REG_ITF_UM5_MISR179_Pos)        /*!< 0x00080000 */
#define FLASH_REG_ITF_UM5_MISR179     FLASH_REG_ITF_UM5_MISR179_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM5_MISR180_Pos (20U)
#define FLASH_REG_ITF_UM5_MISR180_Msk (0x1UL << FLASH_REG_ITF_UM5_MISR180_Pos)        /*!< 0x00100000 */
#define FLASH_REG_ITF_UM5_MISR180     FLASH_REG_ITF_UM5_MISR180_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM5_MISR181_Pos (21U)
#define FLASH_REG_ITF_UM5_MISR181_Msk (0x1UL << FLASH_REG_ITF_UM5_MISR181_Pos)        /*!< 0x00200000 */
#define FLASH_REG_ITF_UM5_MISR181     FLASH_REG_ITF_UM5_MISR181_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM5_MISR182_Pos (22U)
#define FLASH_REG_ITF_UM5_MISR182_Msk (0x1UL << FLASH_REG_ITF_UM5_MISR182_Pos)        /*!< 0x00400000 */
#define FLASH_REG_ITF_UM5_MISR182     FLASH_REG_ITF_UM5_MISR182_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM5_MISR183_Pos (23U)
#define FLASH_REG_ITF_UM5_MISR183_Msk (0x1UL << FLASH_REG_ITF_UM5_MISR183_Pos)        /*!< 0x00800000 */
#define FLASH_REG_ITF_UM5_MISR183     FLASH_REG_ITF_UM5_MISR183_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM5_MISR184_Pos (24U)
#define FLASH_REG_ITF_UM5_MISR184_Msk (0x1UL << FLASH_REG_ITF_UM5_MISR184_Pos)        /*!< 0x01000000 */
#define FLASH_REG_ITF_UM5_MISR184     FLASH_REG_ITF_UM5_MISR184_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM5_MISR185_Pos (25U)
#define FLASH_REG_ITF_UM5_MISR185_Msk (0x1UL << FLASH_REG_ITF_UM5_MISR185_Pos)        /*!< 0x02000000 */
#define FLASH_REG_ITF_UM5_MISR185     FLASH_REG_ITF_UM5_MISR185_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM5_MISR186_Pos (26U)
#define FLASH_REG_ITF_UM5_MISR186_Msk (0x1UL << FLASH_REG_ITF_UM5_MISR186_Pos)        /*!< 0x04000000 */
#define FLASH_REG_ITF_UM5_MISR186     FLASH_REG_ITF_UM5_MISR186_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM5_MISR187_Pos (27U)
#define FLASH_REG_ITF_UM5_MISR187_Msk (0x1UL << FLASH_REG_ITF_UM5_MISR187_Pos)        /*!< 0x08000000 */
#define FLASH_REG_ITF_UM5_MISR187     FLASH_REG_ITF_UM5_MISR187_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM5_MISR188_Pos (28U)
#define FLASH_REG_ITF_UM5_MISR188_Msk (0x1UL << FLASH_REG_ITF_UM5_MISR188_Pos)        /*!< 0x10000000 */
#define FLASH_REG_ITF_UM5_MISR188     FLASH_REG_ITF_UM5_MISR188_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM5_MISR189_Pos (29U)
#define FLASH_REG_ITF_UM5_MISR189_Msk (0x1UL << FLASH_REG_ITF_UM5_MISR189_Pos)        /*!< 0x20000000 */
#define FLASH_REG_ITF_UM5_MISR189     FLASH_REG_ITF_UM5_MISR189_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM5_MISR190_Pos (30U)
#define FLASH_REG_ITF_UM5_MISR190_Msk (0x1UL << FLASH_REG_ITF_UM5_MISR190_Pos)        /*!< 0x40000000 */
#define FLASH_REG_ITF_UM5_MISR190     FLASH_REG_ITF_UM5_MISR190_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM5_MISR191_Pos (31U)
#define FLASH_REG_ITF_UM5_MISR191_Msk (0x1UL << FLASH_REG_ITF_UM5_MISR191_Pos)        /*!< 0x80000000 */
#define FLASH_REG_ITF_UM5_MISR191     FLASH_REG_ITF_UM5_MISR191_Msk                  /*!< </spirit:description> */

/**************  Bit definition for FLASH_REG_ITF_UM6 register  ***************/
#define FLASH_REG_ITF_UM6_MISR192_Pos (0U)
#define FLASH_REG_ITF_UM6_MISR192_Msk (0x1UL << FLASH_REG_ITF_UM6_MISR192_Pos)        /*!< 0x00000001 */
#define FLASH_REG_ITF_UM6_MISR192     FLASH_REG_ITF_UM6_MISR192_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM6_MISR193_Pos (1U)
#define FLASH_REG_ITF_UM6_MISR193_Msk (0x1UL << FLASH_REG_ITF_UM6_MISR193_Pos)        /*!< 0x00000002 */
#define FLASH_REG_ITF_UM6_MISR193     FLASH_REG_ITF_UM6_MISR193_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM6_MISR194_Pos (2U)
#define FLASH_REG_ITF_UM6_MISR194_Msk (0x1UL << FLASH_REG_ITF_UM6_MISR194_Pos)        /*!< 0x00000004 */
#define FLASH_REG_ITF_UM6_MISR194     FLASH_REG_ITF_UM6_MISR194_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM6_MISR195_Pos (3U)
#define FLASH_REG_ITF_UM6_MISR195_Msk (0x1UL << FLASH_REG_ITF_UM6_MISR195_Pos)        /*!< 0x00000008 */
#define FLASH_REG_ITF_UM6_MISR195     FLASH_REG_ITF_UM6_MISR195_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM6_MISR196_Pos (4U)
#define FLASH_REG_ITF_UM6_MISR196_Msk (0x1UL << FLASH_REG_ITF_UM6_MISR196_Pos)        /*!< 0x00000010 */
#define FLASH_REG_ITF_UM6_MISR196     FLASH_REG_ITF_UM6_MISR196_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM6_MISR197_Pos (5U)
#define FLASH_REG_ITF_UM6_MISR197_Msk (0x1UL << FLASH_REG_ITF_UM6_MISR197_Pos)        /*!< 0x00000020 */
#define FLASH_REG_ITF_UM6_MISR197     FLASH_REG_ITF_UM6_MISR197_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM6_MISR198_Pos (6U)
#define FLASH_REG_ITF_UM6_MISR198_Msk (0x1UL << FLASH_REG_ITF_UM6_MISR198_Pos)        /*!< 0x00000040 */
#define FLASH_REG_ITF_UM6_MISR198     FLASH_REG_ITF_UM6_MISR198_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM6_MISR199_Pos (7U)
#define FLASH_REG_ITF_UM6_MISR199_Msk (0x1UL << FLASH_REG_ITF_UM6_MISR199_Pos)        /*!< 0x00000080 */
#define FLASH_REG_ITF_UM6_MISR199     FLASH_REG_ITF_UM6_MISR199_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM6_MISR200_Pos (8U)
#define FLASH_REG_ITF_UM6_MISR200_Msk (0x1UL << FLASH_REG_ITF_UM6_MISR200_Pos)        /*!< 0x00000100 */
#define FLASH_REG_ITF_UM6_MISR200     FLASH_REG_ITF_UM6_MISR200_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM6_MISR201_Pos (9U)
#define FLASH_REG_ITF_UM6_MISR201_Msk (0x1UL << FLASH_REG_ITF_UM6_MISR201_Pos)        /*!< 0x00000200 */
#define FLASH_REG_ITF_UM6_MISR201     FLASH_REG_ITF_UM6_MISR201_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM6_MISR202_Pos (10U)
#define FLASH_REG_ITF_UM6_MISR202_Msk (0x1UL << FLASH_REG_ITF_UM6_MISR202_Pos)        /*!< 0x00000400 */
#define FLASH_REG_ITF_UM6_MISR202     FLASH_REG_ITF_UM6_MISR202_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM6_MISR203_Pos (11U)
#define FLASH_REG_ITF_UM6_MISR203_Msk (0x1UL << FLASH_REG_ITF_UM6_MISR203_Pos)        /*!< 0x00000800 */
#define FLASH_REG_ITF_UM6_MISR203     FLASH_REG_ITF_UM6_MISR203_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM6_MISR204_Pos (12U)
#define FLASH_REG_ITF_UM6_MISR204_Msk (0x1UL << FLASH_REG_ITF_UM6_MISR204_Pos)        /*!< 0x00001000 */
#define FLASH_REG_ITF_UM6_MISR204     FLASH_REG_ITF_UM6_MISR204_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM6_MISR205_Pos (13U)
#define FLASH_REG_ITF_UM6_MISR205_Msk (0x1UL << FLASH_REG_ITF_UM6_MISR205_Pos)        /*!< 0x00002000 */
#define FLASH_REG_ITF_UM6_MISR205     FLASH_REG_ITF_UM6_MISR205_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM6_MISR206_Pos (14U)
#define FLASH_REG_ITF_UM6_MISR206_Msk (0x1UL << FLASH_REG_ITF_UM6_MISR206_Pos)        /*!< 0x00004000 */
#define FLASH_REG_ITF_UM6_MISR206     FLASH_REG_ITF_UM6_MISR206_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM6_MISR207_Pos (15U)
#define FLASH_REG_ITF_UM6_MISR207_Msk (0x1UL << FLASH_REG_ITF_UM6_MISR207_Pos)        /*!< 0x00008000 */
#define FLASH_REG_ITF_UM6_MISR207     FLASH_REG_ITF_UM6_MISR207_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM6_MISR208_Pos (16U)
#define FLASH_REG_ITF_UM6_MISR208_Msk (0x1UL << FLASH_REG_ITF_UM6_MISR208_Pos)        /*!< 0x00010000 */
#define FLASH_REG_ITF_UM6_MISR208     FLASH_REG_ITF_UM6_MISR208_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM6_MISR209_Pos (17U)
#define FLASH_REG_ITF_UM6_MISR209_Msk (0x1UL << FLASH_REG_ITF_UM6_MISR209_Pos)        /*!< 0x00020000 */
#define FLASH_REG_ITF_UM6_MISR209     FLASH_REG_ITF_UM6_MISR209_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM6_MISR210_Pos (18U)
#define FLASH_REG_ITF_UM6_MISR210_Msk (0x1UL << FLASH_REG_ITF_UM6_MISR210_Pos)        /*!< 0x00040000 */
#define FLASH_REG_ITF_UM6_MISR210     FLASH_REG_ITF_UM6_MISR210_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM6_MISR211_Pos (19U)
#define FLASH_REG_ITF_UM6_MISR211_Msk (0x1UL << FLASH_REG_ITF_UM6_MISR211_Pos)        /*!< 0x00080000 */
#define FLASH_REG_ITF_UM6_MISR211     FLASH_REG_ITF_UM6_MISR211_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM6_MISR212_Pos (20U)
#define FLASH_REG_ITF_UM6_MISR212_Msk (0x1UL << FLASH_REG_ITF_UM6_MISR212_Pos)        /*!< 0x00100000 */
#define FLASH_REG_ITF_UM6_MISR212     FLASH_REG_ITF_UM6_MISR212_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM6_MISR213_Pos (21U)
#define FLASH_REG_ITF_UM6_MISR213_Msk (0x1UL << FLASH_REG_ITF_UM6_MISR213_Pos)        /*!< 0x00200000 */
#define FLASH_REG_ITF_UM6_MISR213     FLASH_REG_ITF_UM6_MISR213_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM6_MISR214_Pos (22U)
#define FLASH_REG_ITF_UM6_MISR214_Msk (0x1UL << FLASH_REG_ITF_UM6_MISR214_Pos)        /*!< 0x00400000 */
#define FLASH_REG_ITF_UM6_MISR214     FLASH_REG_ITF_UM6_MISR214_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM6_MISR215_Pos (23U)
#define FLASH_REG_ITF_UM6_MISR215_Msk (0x1UL << FLASH_REG_ITF_UM6_MISR215_Pos)        /*!< 0x00800000 */
#define FLASH_REG_ITF_UM6_MISR215     FLASH_REG_ITF_UM6_MISR215_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM6_MISR216_Pos (24U)
#define FLASH_REG_ITF_UM6_MISR216_Msk (0x1UL << FLASH_REG_ITF_UM6_MISR216_Pos)        /*!< 0x01000000 */
#define FLASH_REG_ITF_UM6_MISR216     FLASH_REG_ITF_UM6_MISR216_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM6_MISR217_Pos (25U)
#define FLASH_REG_ITF_UM6_MISR217_Msk (0x1UL << FLASH_REG_ITF_UM6_MISR217_Pos)        /*!< 0x02000000 */
#define FLASH_REG_ITF_UM6_MISR217     FLASH_REG_ITF_UM6_MISR217_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM6_MISR218_Pos (26U)
#define FLASH_REG_ITF_UM6_MISR218_Msk (0x1UL << FLASH_REG_ITF_UM6_MISR218_Pos)        /*!< 0x04000000 */
#define FLASH_REG_ITF_UM6_MISR218     FLASH_REG_ITF_UM6_MISR218_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM6_MISR219_Pos (27U)
#define FLASH_REG_ITF_UM6_MISR219_Msk (0x1UL << FLASH_REG_ITF_UM6_MISR219_Pos)        /*!< 0x08000000 */
#define FLASH_REG_ITF_UM6_MISR219     FLASH_REG_ITF_UM6_MISR219_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM6_MISR220_Pos (28U)
#define FLASH_REG_ITF_UM6_MISR220_Msk (0x1UL << FLASH_REG_ITF_UM6_MISR220_Pos)        /*!< 0x10000000 */
#define FLASH_REG_ITF_UM6_MISR220     FLASH_REG_ITF_UM6_MISR220_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM6_MISR221_Pos (29U)
#define FLASH_REG_ITF_UM6_MISR221_Msk (0x1UL << FLASH_REG_ITF_UM6_MISR221_Pos)        /*!< 0x20000000 */
#define FLASH_REG_ITF_UM6_MISR221     FLASH_REG_ITF_UM6_MISR221_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM6_MISR222_Pos (30U)
#define FLASH_REG_ITF_UM6_MISR222_Msk (0x1UL << FLASH_REG_ITF_UM6_MISR222_Pos)        /*!< 0x40000000 */
#define FLASH_REG_ITF_UM6_MISR222     FLASH_REG_ITF_UM6_MISR222_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM6_MISR223_Pos (31U)
#define FLASH_REG_ITF_UM6_MISR223_Msk (0x1UL << FLASH_REG_ITF_UM6_MISR223_Pos)        /*!< 0x80000000 */
#define FLASH_REG_ITF_UM6_MISR223     FLASH_REG_ITF_UM6_MISR223_Msk                  /*!< </spirit:description> */

/**************  Bit definition for FLASH_REG_ITF_UM7 register  ***************/
#define FLASH_REG_ITF_UM7_MISR224_Pos (0U)
#define FLASH_REG_ITF_UM7_MISR224_Msk (0x1UL << FLASH_REG_ITF_UM7_MISR224_Pos)        /*!< 0x00000001 */
#define FLASH_REG_ITF_UM7_MISR224     FLASH_REG_ITF_UM7_MISR224_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM7_MISR225_Pos (1U)
#define FLASH_REG_ITF_UM7_MISR225_Msk (0x1UL << FLASH_REG_ITF_UM7_MISR225_Pos)        /*!< 0x00000002 */
#define FLASH_REG_ITF_UM7_MISR225     FLASH_REG_ITF_UM7_MISR225_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM7_MISR226_Pos (2U)
#define FLASH_REG_ITF_UM7_MISR226_Msk (0x1UL << FLASH_REG_ITF_UM7_MISR226_Pos)        /*!< 0x00000004 */
#define FLASH_REG_ITF_UM7_MISR226     FLASH_REG_ITF_UM7_MISR226_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM7_MISR227_Pos (3U)
#define FLASH_REG_ITF_UM7_MISR227_Msk (0x1UL << FLASH_REG_ITF_UM7_MISR227_Pos)        /*!< 0x00000008 */
#define FLASH_REG_ITF_UM7_MISR227     FLASH_REG_ITF_UM7_MISR227_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM7_MISR228_Pos (4U)
#define FLASH_REG_ITF_UM7_MISR228_Msk (0x1UL << FLASH_REG_ITF_UM7_MISR228_Pos)        /*!< 0x00000010 */
#define FLASH_REG_ITF_UM7_MISR228     FLASH_REG_ITF_UM7_MISR228_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM7_MISR229_Pos (5U)
#define FLASH_REG_ITF_UM7_MISR229_Msk (0x1UL << FLASH_REG_ITF_UM7_MISR229_Pos)        /*!< 0x00000020 */
#define FLASH_REG_ITF_UM7_MISR229     FLASH_REG_ITF_UM7_MISR229_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM7_MISR230_Pos (6U)
#define FLASH_REG_ITF_UM7_MISR230_Msk (0x1UL << FLASH_REG_ITF_UM7_MISR230_Pos)        /*!< 0x00000040 */
#define FLASH_REG_ITF_UM7_MISR230     FLASH_REG_ITF_UM7_MISR230_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM7_MISR231_Pos (7U)
#define FLASH_REG_ITF_UM7_MISR231_Msk (0x1UL << FLASH_REG_ITF_UM7_MISR231_Pos)        /*!< 0x00000080 */
#define FLASH_REG_ITF_UM7_MISR231     FLASH_REG_ITF_UM7_MISR231_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM7_MISR232_Pos (8U)
#define FLASH_REG_ITF_UM7_MISR232_Msk (0x1UL << FLASH_REG_ITF_UM7_MISR232_Pos)        /*!< 0x00000100 */
#define FLASH_REG_ITF_UM7_MISR232     FLASH_REG_ITF_UM7_MISR232_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM7_MISR233_Pos (9U)
#define FLASH_REG_ITF_UM7_MISR233_Msk (0x1UL << FLASH_REG_ITF_UM7_MISR233_Pos)        /*!< 0x00000200 */
#define FLASH_REG_ITF_UM7_MISR233     FLASH_REG_ITF_UM7_MISR233_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM7_MISR234_Pos (10U)
#define FLASH_REG_ITF_UM7_MISR234_Msk (0x1UL << FLASH_REG_ITF_UM7_MISR234_Pos)        /*!< 0x00000400 */
#define FLASH_REG_ITF_UM7_MISR234     FLASH_REG_ITF_UM7_MISR234_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM7_MISR235_Pos (11U)
#define FLASH_REG_ITF_UM7_MISR235_Msk (0x1UL << FLASH_REG_ITF_UM7_MISR235_Pos)        /*!< 0x00000800 */
#define FLASH_REG_ITF_UM7_MISR235     FLASH_REG_ITF_UM7_MISR235_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM7_MISR236_Pos (12U)
#define FLASH_REG_ITF_UM7_MISR236_Msk (0x1UL << FLASH_REG_ITF_UM7_MISR236_Pos)        /*!< 0x00001000 */
#define FLASH_REG_ITF_UM7_MISR236     FLASH_REG_ITF_UM7_MISR236_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM7_MISR237_Pos (13U)
#define FLASH_REG_ITF_UM7_MISR237_Msk (0x1UL << FLASH_REG_ITF_UM7_MISR237_Pos)        /*!< 0x00002000 */
#define FLASH_REG_ITF_UM7_MISR237     FLASH_REG_ITF_UM7_MISR237_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM7_MISR238_Pos (14U)
#define FLASH_REG_ITF_UM7_MISR238_Msk (0x1UL << FLASH_REG_ITF_UM7_MISR238_Pos)        /*!< 0x00004000 */
#define FLASH_REG_ITF_UM7_MISR238     FLASH_REG_ITF_UM7_MISR238_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM7_MISR239_Pos (15U)
#define FLASH_REG_ITF_UM7_MISR239_Msk (0x1UL << FLASH_REG_ITF_UM7_MISR239_Pos)        /*!< 0x00008000 */
#define FLASH_REG_ITF_UM7_MISR239     FLASH_REG_ITF_UM7_MISR239_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM7_MISR240_Pos (16U)
#define FLASH_REG_ITF_UM7_MISR240_Msk (0x1UL << FLASH_REG_ITF_UM7_MISR240_Pos)        /*!< 0x00010000 */
#define FLASH_REG_ITF_UM7_MISR240     FLASH_REG_ITF_UM7_MISR240_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM7_MISR241_Pos (17U)
#define FLASH_REG_ITF_UM7_MISR241_Msk (0x1UL << FLASH_REG_ITF_UM7_MISR241_Pos)        /*!< 0x00020000 */
#define FLASH_REG_ITF_UM7_MISR241     FLASH_REG_ITF_UM7_MISR241_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM7_MISR242_Pos (18U)
#define FLASH_REG_ITF_UM7_MISR242_Msk (0x1UL << FLASH_REG_ITF_UM7_MISR242_Pos)        /*!< 0x00040000 */
#define FLASH_REG_ITF_UM7_MISR242     FLASH_REG_ITF_UM7_MISR242_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM7_MISR243_Pos (19U)
#define FLASH_REG_ITF_UM7_MISR243_Msk (0x1UL << FLASH_REG_ITF_UM7_MISR243_Pos)        /*!< 0x00080000 */
#define FLASH_REG_ITF_UM7_MISR243     FLASH_REG_ITF_UM7_MISR243_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM7_MISR244_Pos (20U)
#define FLASH_REG_ITF_UM7_MISR244_Msk (0x1UL << FLASH_REG_ITF_UM7_MISR244_Pos)        /*!< 0x00100000 */
#define FLASH_REG_ITF_UM7_MISR244     FLASH_REG_ITF_UM7_MISR244_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM7_MISR245_Pos (21U)
#define FLASH_REG_ITF_UM7_MISR245_Msk (0x1UL << FLASH_REG_ITF_UM7_MISR245_Pos)        /*!< 0x00200000 */
#define FLASH_REG_ITF_UM7_MISR245     FLASH_REG_ITF_UM7_MISR245_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM7_MISR246_Pos (22U)
#define FLASH_REG_ITF_UM7_MISR246_Msk (0x1UL << FLASH_REG_ITF_UM7_MISR246_Pos)        /*!< 0x00400000 */
#define FLASH_REG_ITF_UM7_MISR246     FLASH_REG_ITF_UM7_MISR246_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM7_MISR247_Pos (23U)
#define FLASH_REG_ITF_UM7_MISR247_Msk (0x1UL << FLASH_REG_ITF_UM7_MISR247_Pos)        /*!< 0x00800000 */
#define FLASH_REG_ITF_UM7_MISR247     FLASH_REG_ITF_UM7_MISR247_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM7_MISR248_Pos (24U)
#define FLASH_REG_ITF_UM7_MISR248_Msk (0x1UL << FLASH_REG_ITF_UM7_MISR248_Pos)        /*!< 0x01000000 */
#define FLASH_REG_ITF_UM7_MISR248     FLASH_REG_ITF_UM7_MISR248_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM7_MISR249_Pos (25U)
#define FLASH_REG_ITF_UM7_MISR249_Msk (0x1UL << FLASH_REG_ITF_UM7_MISR249_Pos)        /*!< 0x02000000 */
#define FLASH_REG_ITF_UM7_MISR249     FLASH_REG_ITF_UM7_MISR249_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM7_MISR250_Pos (26U)
#define FLASH_REG_ITF_UM7_MISR250_Msk (0x1UL << FLASH_REG_ITF_UM7_MISR250_Pos)        /*!< 0x04000000 */
#define FLASH_REG_ITF_UM7_MISR250     FLASH_REG_ITF_UM7_MISR250_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM7_MISR251_Pos (27U)
#define FLASH_REG_ITF_UM7_MISR251_Msk (0x1UL << FLASH_REG_ITF_UM7_MISR251_Pos)        /*!< 0x08000000 */
#define FLASH_REG_ITF_UM7_MISR251     FLASH_REG_ITF_UM7_MISR251_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM7_MISR252_Pos (28U)
#define FLASH_REG_ITF_UM7_MISR252_Msk (0x1UL << FLASH_REG_ITF_UM7_MISR252_Pos)        /*!< 0x10000000 */
#define FLASH_REG_ITF_UM7_MISR252     FLASH_REG_ITF_UM7_MISR252_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM7_MISR253_Pos (29U)
#define FLASH_REG_ITF_UM7_MISR253_Msk (0x1UL << FLASH_REG_ITF_UM7_MISR253_Pos)        /*!< 0x20000000 */
#define FLASH_REG_ITF_UM7_MISR253     FLASH_REG_ITF_UM7_MISR253_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM7_MISR254_Pos (30U)
#define FLASH_REG_ITF_UM7_MISR254_Msk (0x1UL << FLASH_REG_ITF_UM7_MISR254_Pos)        /*!< 0x40000000 */
#define FLASH_REG_ITF_UM7_MISR254     FLASH_REG_ITF_UM7_MISR254_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM7_MISR255_Pos (31U)
#define FLASH_REG_ITF_UM7_MISR255_Msk (0x1UL << FLASH_REG_ITF_UM7_MISR255_Pos)        /*!< 0x80000000 */
#define FLASH_REG_ITF_UM7_MISR255     FLASH_REG_ITF_UM7_MISR255_Msk                  /*!< </spirit:description> */

/**************  Bit definition for FLASH_REG_ITF_UM8 register  ***************/
#define FLASH_REG_ITF_UM8_MISR256_Pos (0U)
#define FLASH_REG_ITF_UM8_MISR256_Msk (0x1UL << FLASH_REG_ITF_UM8_MISR256_Pos)        /*!< 0x00000001 */
#define FLASH_REG_ITF_UM8_MISR256     FLASH_REG_ITF_UM8_MISR256_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM8_MISR257_Pos (1U)
#define FLASH_REG_ITF_UM8_MISR257_Msk (0x1UL << FLASH_REG_ITF_UM8_MISR257_Pos)        /*!< 0x00000002 */
#define FLASH_REG_ITF_UM8_MISR257     FLASH_REG_ITF_UM8_MISR257_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM8_MISR258_Pos (2U)
#define FLASH_REG_ITF_UM8_MISR258_Msk (0x1UL << FLASH_REG_ITF_UM8_MISR258_Pos)        /*!< 0x00000004 */
#define FLASH_REG_ITF_UM8_MISR258     FLASH_REG_ITF_UM8_MISR258_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM8_MISR259_Pos (3U)
#define FLASH_REG_ITF_UM8_MISR259_Msk (0x1UL << FLASH_REG_ITF_UM8_MISR259_Pos)        /*!< 0x00000008 */
#define FLASH_REG_ITF_UM8_MISR259     FLASH_REG_ITF_UM8_MISR259_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM8_MISR260_Pos (4U)
#define FLASH_REG_ITF_UM8_MISR260_Msk (0x1UL << FLASH_REG_ITF_UM8_MISR260_Pos)        /*!< 0x00000010 */
#define FLASH_REG_ITF_UM8_MISR260     FLASH_REG_ITF_UM8_MISR260_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM8_MISR261_Pos (5U)
#define FLASH_REG_ITF_UM8_MISR261_Msk (0x1UL << FLASH_REG_ITF_UM8_MISR261_Pos)        /*!< 0x00000020 */
#define FLASH_REG_ITF_UM8_MISR261     FLASH_REG_ITF_UM8_MISR261_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM8_MISR262_Pos (6U)
#define FLASH_REG_ITF_UM8_MISR262_Msk (0x1UL << FLASH_REG_ITF_UM8_MISR262_Pos)        /*!< 0x00000040 */
#define FLASH_REG_ITF_UM8_MISR262     FLASH_REG_ITF_UM8_MISR262_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM8_MISR263_Pos (7U)
#define FLASH_REG_ITF_UM8_MISR263_Msk (0x1UL << FLASH_REG_ITF_UM8_MISR263_Pos)        /*!< 0x00000080 */
#define FLASH_REG_ITF_UM8_MISR263     FLASH_REG_ITF_UM8_MISR263_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM8_MISR264_Pos (8U)
#define FLASH_REG_ITF_UM8_MISR264_Msk (0x1UL << FLASH_REG_ITF_UM8_MISR264_Pos)        /*!< 0x00000100 */
#define FLASH_REG_ITF_UM8_MISR264     FLASH_REG_ITF_UM8_MISR264_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM8_MISR265_Pos (9U)
#define FLASH_REG_ITF_UM8_MISR265_Msk (0x1UL << FLASH_REG_ITF_UM8_MISR265_Pos)        /*!< 0x00000200 */
#define FLASH_REG_ITF_UM8_MISR265     FLASH_REG_ITF_UM8_MISR265_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM8_MISR266_Pos (10U)
#define FLASH_REG_ITF_UM8_MISR266_Msk (0x1UL << FLASH_REG_ITF_UM8_MISR266_Pos)        /*!< 0x00000400 */
#define FLASH_REG_ITF_UM8_MISR266     FLASH_REG_ITF_UM8_MISR266_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM8_MISR267_Pos (11U)
#define FLASH_REG_ITF_UM8_MISR267_Msk (0x1UL << FLASH_REG_ITF_UM8_MISR267_Pos)        /*!< 0x00000800 */
#define FLASH_REG_ITF_UM8_MISR267     FLASH_REG_ITF_UM8_MISR267_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM8_MISR268_Pos (12U)
#define FLASH_REG_ITF_UM8_MISR268_Msk (0x1UL << FLASH_REG_ITF_UM8_MISR268_Pos)        /*!< 0x00001000 */
#define FLASH_REG_ITF_UM8_MISR268     FLASH_REG_ITF_UM8_MISR268_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM8_MISR269_Pos (13U)
#define FLASH_REG_ITF_UM8_MISR269_Msk (0x1UL << FLASH_REG_ITF_UM8_MISR269_Pos)        /*!< 0x00002000 */
#define FLASH_REG_ITF_UM8_MISR269     FLASH_REG_ITF_UM8_MISR269_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM8_MISR270_Pos (14U)
#define FLASH_REG_ITF_UM8_MISR270_Msk (0x1UL << FLASH_REG_ITF_UM8_MISR270_Pos)        /*!< 0x00004000 */
#define FLASH_REG_ITF_UM8_MISR270     FLASH_REG_ITF_UM8_MISR270_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM8_MISR271_Pos (15U)
#define FLASH_REG_ITF_UM8_MISR271_Msk (0x1UL << FLASH_REG_ITF_UM8_MISR271_Pos)        /*!< 0x00008000 */
#define FLASH_REG_ITF_UM8_MISR271     FLASH_REG_ITF_UM8_MISR271_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM8_MISR272_Pos (16U)
#define FLASH_REG_ITF_UM8_MISR272_Msk (0x1UL << FLASH_REG_ITF_UM8_MISR272_Pos)        /*!< 0x00010000 */
#define FLASH_REG_ITF_UM8_MISR272     FLASH_REG_ITF_UM8_MISR272_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM8_MISR273_Pos (17U)
#define FLASH_REG_ITF_UM8_MISR273_Msk (0x1UL << FLASH_REG_ITF_UM8_MISR273_Pos)        /*!< 0x00020000 */
#define FLASH_REG_ITF_UM8_MISR273     FLASH_REG_ITF_UM8_MISR273_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM8_MISR274_Pos (18U)
#define FLASH_REG_ITF_UM8_MISR274_Msk (0x1UL << FLASH_REG_ITF_UM8_MISR274_Pos)        /*!< 0x00040000 */
#define FLASH_REG_ITF_UM8_MISR274     FLASH_REG_ITF_UM8_MISR274_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM8_MISR275_Pos (19U)
#define FLASH_REG_ITF_UM8_MISR275_Msk (0x1UL << FLASH_REG_ITF_UM8_MISR275_Pos)        /*!< 0x00080000 */
#define FLASH_REG_ITF_UM8_MISR275     FLASH_REG_ITF_UM8_MISR275_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM8_MISR276_Pos (20U)
#define FLASH_REG_ITF_UM8_MISR276_Msk (0x1UL << FLASH_REG_ITF_UM8_MISR276_Pos)        /*!< 0x00100000 */
#define FLASH_REG_ITF_UM8_MISR276     FLASH_REG_ITF_UM8_MISR276_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM8_MISR277_Pos (21U)
#define FLASH_REG_ITF_UM8_MISR277_Msk (0x1UL << FLASH_REG_ITF_UM8_MISR277_Pos)        /*!< 0x00200000 */
#define FLASH_REG_ITF_UM8_MISR277     FLASH_REG_ITF_UM8_MISR277_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM8_MISR278_Pos (22U)
#define FLASH_REG_ITF_UM8_MISR278_Msk (0x1UL << FLASH_REG_ITF_UM8_MISR278_Pos)        /*!< 0x00400000 */
#define FLASH_REG_ITF_UM8_MISR278     FLASH_REG_ITF_UM8_MISR278_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM8_MISR279_Pos (23U)
#define FLASH_REG_ITF_UM8_MISR279_Msk (0x1UL << FLASH_REG_ITF_UM8_MISR279_Pos)        /*!< 0x00800000 */
#define FLASH_REG_ITF_UM8_MISR279     FLASH_REG_ITF_UM8_MISR279_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM8_MISR280_Pos (24U)
#define FLASH_REG_ITF_UM8_MISR280_Msk (0x1UL << FLASH_REG_ITF_UM8_MISR280_Pos)        /*!< 0x01000000 */
#define FLASH_REG_ITF_UM8_MISR280     FLASH_REG_ITF_UM8_MISR280_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM8_MISR281_Pos (25U)
#define FLASH_REG_ITF_UM8_MISR281_Msk (0x1UL << FLASH_REG_ITF_UM8_MISR281_Pos)        /*!< 0x02000000 */
#define FLASH_REG_ITF_UM8_MISR281     FLASH_REG_ITF_UM8_MISR281_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM8_MISR282_Pos (26U)
#define FLASH_REG_ITF_UM8_MISR282_Msk (0x1UL << FLASH_REG_ITF_UM8_MISR282_Pos)        /*!< 0x04000000 */
#define FLASH_REG_ITF_UM8_MISR282     FLASH_REG_ITF_UM8_MISR282_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM8_MISR283_Pos (27U)
#define FLASH_REG_ITF_UM8_MISR283_Msk (0x1UL << FLASH_REG_ITF_UM8_MISR283_Pos)        /*!< 0x08000000 */
#define FLASH_REG_ITF_UM8_MISR283     FLASH_REG_ITF_UM8_MISR283_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM8_MISR284_Pos (28U)
#define FLASH_REG_ITF_UM8_MISR284_Msk (0x1UL << FLASH_REG_ITF_UM8_MISR284_Pos)        /*!< 0x10000000 */
#define FLASH_REG_ITF_UM8_MISR284     FLASH_REG_ITF_UM8_MISR284_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM8_MISR285_Pos (29U)
#define FLASH_REG_ITF_UM8_MISR285_Msk (0x1UL << FLASH_REG_ITF_UM8_MISR285_Pos)        /*!< 0x20000000 */
#define FLASH_REG_ITF_UM8_MISR285     FLASH_REG_ITF_UM8_MISR285_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM8_MISR286_Pos (30U)
#define FLASH_REG_ITF_UM8_MISR286_Msk (0x1UL << FLASH_REG_ITF_UM8_MISR286_Pos)        /*!< 0x40000000 */
#define FLASH_REG_ITF_UM8_MISR286     FLASH_REG_ITF_UM8_MISR286_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM8_MISR287_Pos (31U)
#define FLASH_REG_ITF_UM8_MISR287_Msk (0x1UL << FLASH_REG_ITF_UM8_MISR287_Pos)        /*!< 0x80000000 */
#define FLASH_REG_ITF_UM8_MISR287     FLASH_REG_ITF_UM8_MISR287_Msk                  /*!< </spirit:description> */

/**************  Bit definition for FLASH_REG_ITF_UM9 register  ***************/
#define FLASH_REG_ITF_UM9_MISR288_Pos (0U)
#define FLASH_REG_ITF_UM9_MISR288_Msk (0x1UL << FLASH_REG_ITF_UM9_MISR288_Pos)        /*!< 0x00000001 */
#define FLASH_REG_ITF_UM9_MISR288     FLASH_REG_ITF_UM9_MISR288_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM9_MISR289_Pos (1U)
#define FLASH_REG_ITF_UM9_MISR289_Msk (0x1UL << FLASH_REG_ITF_UM9_MISR289_Pos)        /*!< 0x00000002 */
#define FLASH_REG_ITF_UM9_MISR289     FLASH_REG_ITF_UM9_MISR289_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM9_MISR290_Pos (2U)
#define FLASH_REG_ITF_UM9_MISR290_Msk (0x1UL << FLASH_REG_ITF_UM9_MISR290_Pos)        /*!< 0x00000004 */
#define FLASH_REG_ITF_UM9_MISR290     FLASH_REG_ITF_UM9_MISR290_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM9_MISR291_Pos (3U)
#define FLASH_REG_ITF_UM9_MISR291_Msk (0x1UL << FLASH_REG_ITF_UM9_MISR291_Pos)        /*!< 0x00000008 */
#define FLASH_REG_ITF_UM9_MISR291     FLASH_REG_ITF_UM9_MISR291_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM9_MISR292_Pos (4U)
#define FLASH_REG_ITF_UM9_MISR292_Msk (0x1UL << FLASH_REG_ITF_UM9_MISR292_Pos)        /*!< 0x00000010 */
#define FLASH_REG_ITF_UM9_MISR292     FLASH_REG_ITF_UM9_MISR292_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM9_MISR293_Pos (5U)
#define FLASH_REG_ITF_UM9_MISR293_Msk (0x1UL << FLASH_REG_ITF_UM9_MISR293_Pos)        /*!< 0x00000020 */
#define FLASH_REG_ITF_UM9_MISR293     FLASH_REG_ITF_UM9_MISR293_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM9_MISR294_Pos (6U)
#define FLASH_REG_ITF_UM9_MISR294_Msk (0x1UL << FLASH_REG_ITF_UM9_MISR294_Pos)        /*!< 0x00000040 */
#define FLASH_REG_ITF_UM9_MISR294     FLASH_REG_ITF_UM9_MISR294_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM9_MISR295_Pos (7U)
#define FLASH_REG_ITF_UM9_MISR295_Msk (0x1UL << FLASH_REG_ITF_UM9_MISR295_Pos)        /*!< 0x00000080 */
#define FLASH_REG_ITF_UM9_MISR295     FLASH_REG_ITF_UM9_MISR295_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM9_MISR296_Pos (8U)
#define FLASH_REG_ITF_UM9_MISR296_Msk (0x1UL << FLASH_REG_ITF_UM9_MISR296_Pos)        /*!< 0x00000100 */
#define FLASH_REG_ITF_UM9_MISR296     FLASH_REG_ITF_UM9_MISR296_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM9_MISR297_Pos (9U)
#define FLASH_REG_ITF_UM9_MISR297_Msk (0x1UL << FLASH_REG_ITF_UM9_MISR297_Pos)        /*!< 0x00000200 */
#define FLASH_REG_ITF_UM9_MISR297     FLASH_REG_ITF_UM9_MISR297_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM9_MISR298_Pos (10U)
#define FLASH_REG_ITF_UM9_MISR298_Msk (0x1UL << FLASH_REG_ITF_UM9_MISR298_Pos)        /*!< 0x00000400 */
#define FLASH_REG_ITF_UM9_MISR298     FLASH_REG_ITF_UM9_MISR298_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM9_MISR299_Pos (11U)
#define FLASH_REG_ITF_UM9_MISR299_Msk (0x1UL << FLASH_REG_ITF_UM9_MISR299_Pos)        /*!< 0x00000800 */
#define FLASH_REG_ITF_UM9_MISR299     FLASH_REG_ITF_UM9_MISR299_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM9_MISR300_Pos (12U)
#define FLASH_REG_ITF_UM9_MISR300_Msk (0x1UL << FLASH_REG_ITF_UM9_MISR300_Pos)        /*!< 0x00001000 */
#define FLASH_REG_ITF_UM9_MISR300     FLASH_REG_ITF_UM9_MISR300_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM9_MISR301_Pos (13U)
#define FLASH_REG_ITF_UM9_MISR301_Msk (0x1UL << FLASH_REG_ITF_UM9_MISR301_Pos)        /*!< 0x00002000 */
#define FLASH_REG_ITF_UM9_MISR301     FLASH_REG_ITF_UM9_MISR301_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM9_MISR302_Pos (14U)
#define FLASH_REG_ITF_UM9_MISR302_Msk (0x1UL << FLASH_REG_ITF_UM9_MISR302_Pos)        /*!< 0x00004000 */
#define FLASH_REG_ITF_UM9_MISR302     FLASH_REG_ITF_UM9_MISR302_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM9_MISR303_Pos (15U)
#define FLASH_REG_ITF_UM9_MISR303_Msk (0x1UL << FLASH_REG_ITF_UM9_MISR303_Pos)        /*!< 0x00008000 */
#define FLASH_REG_ITF_UM9_MISR303     FLASH_REG_ITF_UM9_MISR303_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM9_MISR304_Pos (16U)
#define FLASH_REG_ITF_UM9_MISR304_Msk (0x1UL << FLASH_REG_ITF_UM9_MISR304_Pos)        /*!< 0x00010000 */
#define FLASH_REG_ITF_UM9_MISR304     FLASH_REG_ITF_UM9_MISR304_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM9_MISR305_Pos (17U)
#define FLASH_REG_ITF_UM9_MISR305_Msk (0x1UL << FLASH_REG_ITF_UM9_MISR305_Pos)        /*!< 0x00020000 */
#define FLASH_REG_ITF_UM9_MISR305     FLASH_REG_ITF_UM9_MISR305_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM9_MISR306_Pos (18U)
#define FLASH_REG_ITF_UM9_MISR306_Msk (0x1UL << FLASH_REG_ITF_UM9_MISR306_Pos)        /*!< 0x00040000 */
#define FLASH_REG_ITF_UM9_MISR306     FLASH_REG_ITF_UM9_MISR306_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM9_MISR307_Pos (19U)
#define FLASH_REG_ITF_UM9_MISR307_Msk (0x1UL << FLASH_REG_ITF_UM9_MISR307_Pos)        /*!< 0x00080000 */
#define FLASH_REG_ITF_UM9_MISR307     FLASH_REG_ITF_UM9_MISR307_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM9_MISR308_Pos (20U)
#define FLASH_REG_ITF_UM9_MISR308_Msk (0x1UL << FLASH_REG_ITF_UM9_MISR308_Pos)        /*!< 0x00100000 */
#define FLASH_REG_ITF_UM9_MISR308     FLASH_REG_ITF_UM9_MISR308_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM9_MISR309_Pos (21U)
#define FLASH_REG_ITF_UM9_MISR309_Msk (0x1UL << FLASH_REG_ITF_UM9_MISR309_Pos)        /*!< 0x00200000 */
#define FLASH_REG_ITF_UM9_MISR309     FLASH_REG_ITF_UM9_MISR309_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM9_MISR310_Pos (22U)
#define FLASH_REG_ITF_UM9_MISR310_Msk (0x1UL << FLASH_REG_ITF_UM9_MISR310_Pos)        /*!< 0x00400000 */
#define FLASH_REG_ITF_UM9_MISR310     FLASH_REG_ITF_UM9_MISR310_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM9_MISR311_Pos (23U)
#define FLASH_REG_ITF_UM9_MISR311_Msk (0x1UL << FLASH_REG_ITF_UM9_MISR311_Pos)        /*!< 0x00800000 */
#define FLASH_REG_ITF_UM9_MISR311     FLASH_REG_ITF_UM9_MISR311_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM9_MISR312_Pos (24U)
#define FLASH_REG_ITF_UM9_MISR312_Msk (0x1UL << FLASH_REG_ITF_UM9_MISR312_Pos)        /*!< 0x01000000 */
#define FLASH_REG_ITF_UM9_MISR312     FLASH_REG_ITF_UM9_MISR312_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM9_MISR313_Pos (25U)
#define FLASH_REG_ITF_UM9_MISR313_Msk (0x1UL << FLASH_REG_ITF_UM9_MISR313_Pos)        /*!< 0x02000000 */
#define FLASH_REG_ITF_UM9_MISR313     FLASH_REG_ITF_UM9_MISR313_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM9_MISR314_Pos (26U)
#define FLASH_REG_ITF_UM9_MISR314_Msk (0x1UL << FLASH_REG_ITF_UM9_MISR314_Pos)        /*!< 0x04000000 */
#define FLASH_REG_ITF_UM9_MISR314     FLASH_REG_ITF_UM9_MISR314_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM9_MISR315_Pos (27U)
#define FLASH_REG_ITF_UM9_MISR315_Msk (0x1UL << FLASH_REG_ITF_UM9_MISR315_Pos)        /*!< 0x08000000 */
#define FLASH_REG_ITF_UM9_MISR315     FLASH_REG_ITF_UM9_MISR315_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM9_MISR316_Pos (28U)
#define FLASH_REG_ITF_UM9_MISR316_Msk (0x1UL << FLASH_REG_ITF_UM9_MISR316_Pos)        /*!< 0x10000000 */
#define FLASH_REG_ITF_UM9_MISR316     FLASH_REG_ITF_UM9_MISR316_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM9_MISR317_Pos (29U)
#define FLASH_REG_ITF_UM9_MISR317_Msk (0x1UL << FLASH_REG_ITF_UM9_MISR317_Pos)        /*!< 0x20000000 */
#define FLASH_REG_ITF_UM9_MISR317     FLASH_REG_ITF_UM9_MISR317_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM9_MISR318_Pos (30U)
#define FLASH_REG_ITF_UM9_MISR318_Msk (0x1UL << FLASH_REG_ITF_UM9_MISR318_Pos)        /*!< 0x40000000 */
#define FLASH_REG_ITF_UM9_MISR318     FLASH_REG_ITF_UM9_MISR318_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_UM9_MISR319_Pos (31U)
#define FLASH_REG_ITF_UM9_MISR319_Msk (0x1UL << FLASH_REG_ITF_UM9_MISR319_Pos)        /*!< 0x80000000 */
#define FLASH_REG_ITF_UM9_MISR319     FLASH_REG_ITF_UM9_MISR319_Msk                  /*!< </spirit:description> */

/**************  Bit definition for FLASH_REG_ITF_OPP0 register  **************/
#define FLASH_REG_ITF_OPP0_MIDOPP_Pos (0U)
#define FLASH_REG_ITF_OPP0_MIDOPP_Msk (0xFFFFUL << FLASH_REG_ITF_OPP0_MIDOPP_Pos)     /*!< 0x0000FFFF */
#define FLASH_REG_ITF_OPP0_MIDOPP     FLASH_REG_ITF_OPP0_MIDOPP_Msk                  /*!< </spirit:description> */
#define FLASH_REG_ITF_OPP0_LOWOPP_Pos (16U)
#define FLASH_REG_ITF_OPP0_LOWOPP_Msk (0x3FFFUL << FLASH_REG_ITF_OPP0_LOWOPP_Pos)     /*!< 0x3FFF0000 */
#define FLASH_REG_ITF_OPP0_LOWOPP     FLASH_REG_ITF_OPP0_LOWOPP_Msk                  /*!< </spirit:description> */

/**************  Bit definition for FLASH_REG_ITF_OPP1 register  **************/
#define FLASH_REG_ITF_OPP1_HIGHOPP_Pos   (0U)
#define FLASH_REG_ITF_OPP1_HIGHOPP_Msk   (0xFFFFUL << FLASH_REG_ITF_OPP1_HIGHOPP_Pos)    /*!< 0x0000FFFF */
#define FLASH_REG_ITF_OPP1_HIGHOPP    FLASH_REG_ITF_OPP1_HIGHOPP_Msk                 /*!< </spirit:description> */

/**************  Bit definition for FLASH_REG_ITF_OPP2 register  **************/
#define FLASH_REG_ITF_OPP2_A256KOPP_Pos (0U)
#define FLASH_REG_ITF_OPP2_A256KOPP_Msk (0xFFFFFFFFUL << FLASH_REG_ITF_OPP2_A256KOPP_Pos) /*!< 0xFFFFFFFF */
#define FLASH_REG_ITF_OPP2_A256KOPP   FLASH_REG_ITF_OPP2_A256KOPP_Msk                /*!< </spirit:description> */

/**************  Bit definition for FLASH_REG_ITF_OPP3 register  **************/
#define FLASH_REG_ITF_OPP3_A256KOPP_Pos (0U)
#define FLASH_REG_ITF_OPP3_A256KOPP_Msk (0xFFFFFFFFUL << FLASH_REG_ITF_OPP3_A256KOPP_Pos) /*!< 0xFFFFFFFF */
#define FLASH_REG_ITF_OPP3_A256KOPP   FLASH_REG_ITF_OPP3_A256KOPP_Msk                /*!< </spirit:description> */

/**************  Bit definition for FLASH_REG_ITF_TMD register  ***************/
#define FLASH_REG_ITF_TMD_PWD_Pos     (0U)
#define FLASH_REG_ITF_TMD_PWD_Msk     (0xFFFFFFFFUL << FLASH_REG_ITF_TMD_PWD_Pos)     /*!< 0xFFFFFFFF */
#define FLASH_REG_ITF_TMD_PWD         FLASH_REG_ITF_TMD_PWD_Msk                      /*!< </spirit:description> */

/************  Bit definition for FLASH_REG_ITF_ALTSEL0 register  *************/
#define FLASH_REG_ITF_ALTSEL0_MIDALTSEL_Pos     (0U)
#define FLASH_REG_ITF_ALTSEL0_MIDALTSEL_Msk     (0xFFFFUL << FLASH_REG_ITF_ALTSEL0_MIDALTSEL_Pos) /*!< 0x0000FFFF */
#define FLASH_REG_ITF_ALTSEL0_MIDALTSEL FLASH_REG_ITF_ALTSEL0_MIDALTSEL_Msk            /*!< </spirit:description> */
#define FLASH_REG_ITF_ALTSEL0_LOWALTSEL_Pos     (16U)
#define FLASH_REG_ITF_ALTSEL0_LOWALTSEL_Msk     (0x3FFFUL << FLASH_REG_ITF_ALTSEL0_LOWALTSEL_Pos) /*!< 0x3FFF0000 */
#define FLASH_REG_ITF_ALTSEL0_LOWALTSEL FLASH_REG_ITF_ALTSEL0_LOWALTSEL_Msk            /*!< </spirit:description> */

/************  Bit definition for FLASH_REG_ITF_ALTSEL1 register  *************/
#define FLASH_REG_ITF_ALTSEL1_HIGHALTSEL_Pos      (0U)
#define FLASH_REG_ITF_ALTSEL1_HIGHALTSEL_Msk      (0xFFFFUL << FLASH_REG_ITF_ALTSEL1_HIGHALTSEL_Pos)  /*!< 0x0000FFFF */
#define FLASH_REG_ITF_ALTSEL1_HIGHALTSEL  FLASH_REG_ITF_ALTSEL1_HIGHALTSEL_Msk           /*!< </spirit:description> */

/*************  Bit definition for FLASH_REG_ITF_ELOCK0 register  *************/
#define FLASH_REG_ITF_ELOCK0_MIDELOCK_Pos   (0U)
#define FLASH_REG_ITF_ELOCK0_MIDELOCK_Msk   (0xFFFFUL << FLASH_REG_ITF_ELOCK0_MIDELOCK_Pos) /*!< 0x0000FFFF */
#define FLASH_REG_ITF_ELOCK0_MIDELOCK FLASH_REG_ITF_ELOCK0_MIDELOCK_Msk              /*!< </spirit:description> */
#define FLASH_REG_ITF_ELOCK0_LOWELOCK_Pos   (16U)
#define FLASH_REG_ITF_ELOCK0_LOWELOCK_Msk   (0xFFFFUL << FLASH_REG_ITF_ELOCK0_LOWELOCK_Pos) /*!< 0xFFFF0000 */
#define FLASH_REG_ITF_ELOCK0_LOWELOCK FLASH_REG_ITF_ELOCK0_LOWELOCK_Msk              /*!< </spirit:description> */

/*************  Bit definition for FLASH_REG_ITF_ELOCK1 register  *************/
#define FLASH_REG_ITF_ELOCK1_HIGHELOCK_Pos    (0U)
#define FLASH_REG_ITF_ELOCK1_HIGHELOCK_Msk     (0xFFFFUL << FLASH_REG_ITF_ELOCK1_HIGHELOCK_Pos) /*!< 0x0000FFFF */
#define FLASH_REG_ITF_ELOCK1_HIGHELOCK FLASH_REG_ITF_ELOCK1_HIGHELOCK_Msk             /*!< </spirit:description> */

/*************  Bit definition for FLASH_REG_ITF_ELOCK2 register  *************/
#define FLASH_REG_ITF_ELOCK2_A256KELOCK_Pos     (0U)
#define FLASH_REG_ITF_ELOCK2_A256KELOCK_Msk     (0xFFFFFFFFUL << FLASH_REG_ITF_ELOCK2_A256KELOCK_Pos)     /*!< 0xFFFFFFFF */
#define FLASH_REG_ITF_ELOCK2_A256KELOCK FLASH_REG_ITF_ELOCK2_A256KELOCK_Msk            /*!< </spirit:description> */

/*************  Bit definition for FLASH_REG_ITF_ELOCK3 register  *************/
#define FLASH_REG_ITF_ELOCK3_A256KELOCK_Pos     (0U)
#define FLASH_REG_ITF_ELOCK3_A256KELOCK_Msk     (0xFFFFFFFFUL << FLASH_REG_ITF_ELOCK3_A256KELOCK_Pos)     /*!< 0xFFFFFFFF */
#define FLASH_REG_ITF_ELOCK3_A256KELOCK FLASH_REG_ITF_ELOCK3_A256KELOCK_Msk            /*!< </spirit:description> */

/*************  Bit definition for FLASH_REG_ITF_PLOCK0 register  *************/
#define FLASH_REG_ITF_PLOCK0_MIDPLOCK_Pos   (0U)
#define FLASH_REG_ITF_PLOCK0_MIDPLOCK_Msk   (0xFFFFUL << FLASH_REG_ITF_PLOCK0_MIDPLOCK_Pos) /*!< 0x0000FFFF */
#define FLASH_REG_ITF_PLOCK0_MIDPLOCK FLASH_REG_ITF_PLOCK0_MIDPLOCK_Msk              /*!< </spirit:description> */
#define FLASH_REG_ITF_PLOCK0_LOWPLOCK_Pos   (0U)
#define FLASH_REG_ITF_PLOCK0_LOWPLOCK_Msk   (0xFFFFUL << FLASH_REG_ITF_PLOCK0_LOWPLOCK_Pos) /*!< 0x0000FFFF */
#define FLASH_REG_ITF_PLOCK0_LOWPLOCK FLASH_REG_ITF_PLOCK0_LOWPLOCK_Msk              /*!< </spirit:description> */

/*************  Bit definition for FLASH_REG_ITF_PLOCK1 register  *************/
#define FLASH_REG_ITF_PLOCK1_HIGHPLOCK_Pos    (0U)
#define FLASH_REG_ITF_PLOCK1_HIGHPLOCK_Msk     (0xFFFFUL << FLASH_REG_ITF_PLOCK1_HIGHPLOCK_Pos) /*!< 0x0000FFFF */
#define FLASH_REG_ITF_PLOCK1_HIGHPLOCK FLASH_REG_ITF_PLOCK1_HIGHPLOCK_Msk             /*!< </spirit:description> */

/*************  Bit definition for FLASH_REG_ITF_PLOCK2 register  *************/
#define FLASH_REG_ITF_PLOCK2_A256KPLOCK_Pos     (0U)
#define FLASH_REG_ITF_PLOCK2_A256KPLOCK_Msk     (0xFFFFFFFFUL << FLASH_REG_ITF_PLOCK2_A256KPLOCK_Pos)     /*!< 0xFFFFFFFF */
#define FLASH_REG_ITF_PLOCK2_A256KPLOCK FLASH_REG_ITF_PLOCK2_A256KPLOCK_Msk            /*!< </spirit:description> */

/*************  Bit definition for FLASH_REG_ITF_PLOCK3 register  *************/
#define FLASH_REG_ITF_PLOCK3_A256KPLOCK_Pos     (0U)
#define FLASH_REG_ITF_PLOCK3_A256KPLOCK_Msk     (0xFFFFFFFFUL << FLASH_REG_ITF_PLOCK3_A256KPLOCK_Pos)     /*!< 0xFFFFFFFF */
#define FLASH_REG_ITF_PLOCK3_A256KPLOCK FLASH_REG_ITF_PLOCK3_A256KPLOCK_Msk            /*!< </spirit:description> */

/**************  Bit definition for FLASH_REG_ITF_ADR2 register  **************/
#define FLASH_REG_ITF_ADR2_PADR_Pos   (3U)
#define FLASH_REG_ITF_ADR2_PADR_Msk   (0x1FFFFFUL << FLASH_REG_ITF_ADR2_PADR_Pos)     /*!< 0x00FFFFF8 */
#define FLASH_REG_ITF_ADR2_PADR       FLASH_REG_ITF_ADR2_PADR_Msk                    /*!< </spirit:description> */

#define FLASH_REG_ITF_BASE           0x40018000UL 


#define FLASH_REG_ITF                ((FLASH_REG_ITF_TypeDef *) FLASH_REG_ITF_BASE) 


#endif /* __SR5E1_FLASH_REG_ITF_H */

