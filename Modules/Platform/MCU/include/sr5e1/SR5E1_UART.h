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

#ifndef __SR5E1_UART_H
#define __SR5E1_UART_H

/******************************************************************************/
/*                                                                            */
/*                                UART (UART)                                 */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO uint32_t CR1;    /*!< CR1   Address offset: 0x00 */
  __IO uint32_t CR2;    /*!< CR2   Address offset: 0x04 */
  __IO uint32_t CR3;    /*!< CR3   Address offset: 0x08 */
  __IO uint32_t BRR;    /*!< BRR   Address offset: 0x0C */
  __IO uint32_t GTPR;   /*!< GTPR  Address offset: 0x10 */
  __IO uint32_t RTOR;   /*!< RTOR  Address offset: 0x14 */
  __IO uint32_t RQR;    /*!< RQR   Address offset: 0x18 */
  __IO uint32_t ISR;    /*!< ISR   Address offset: 0x1C */
  __IO uint32_t ICR;    /*!< ICR   Address offset: 0x20 */
  __IO uint32_t RDR;    /*!< RDR   Address offset: 0x24 */
  __IO uint32_t TDR;    /*!< TDR   Address offset: 0x28 */
  __IO uint32_t PRESC;  /*!< PRESC Address offset: 0x2C */
} UART_TypeDef;


/*******************  Bit definition for UART_CR1 register  *******************/
#define UART_CR1_UE_Pos                 (0U)
#define UART_CR1_UE_Msk                 (0x1UL << UART_CR1_UE_Pos)      /*!< 0x00000001 */
#define UART_CR1_UE                     UART_CR1_UE_Msk                /*!< </spirit:description> */
#define UART_CR1_UESM_Pos               (1U)
#define UART_CR1_UESM_Msk               (0x1UL << UART_CR1_UESM_Pos)    /*!< 0x00000002 */
#define UART_CR1_UESM                   UART_CR1_UESM_Msk              /*!< </spirit:description> */
#define UART_CR1_RE_Pos                 (2U)
#define UART_CR1_RE_Msk                 (0x1UL << UART_CR1_RE_Pos)      /*!< 0x00000004 */
#define UART_CR1_RE                     UART_CR1_RE_Msk                /*!< </spirit:description> */
#define UART_CR1_TE_Pos                 (3U)
#define UART_CR1_TE_Msk                 (0x1UL << UART_CR1_TE_Pos)      /*!< 0x00000008 */
#define UART_CR1_TE                     UART_CR1_TE_Msk                /*!< </spirit:description> */
#define UART_CR1_IDLEIE_Pos             (4U)
#define UART_CR1_IDLEIE_Msk             (0x1UL << UART_CR1_IDLEIE_Pos)  /*!< 0x00000010 */
#define UART_CR1_IDLEIE                 UART_CR1_IDLEIE_Msk            /*!< </spirit:description> */
#define UART_CR1_RXNEIE_RXFNEIE_Pos     (5U)
#define UART_CR1_RXNEIE_RXFNEIE_Msk     (0x1UL << UART_CR1_RXNEIE_RXFNEIE_Pos)      /*!< 0x00000020 */
#define UART_CR1_RXNEIE_RXFNEIE         UART_CR1_RXNEIE_RXFNEIE_Msk    /*!< </spirit:description> */
#define UART_CR1_TCIE_Pos               (6U)
#define UART_CR1_TCIE_Msk               (0x1UL << UART_CR1_TCIE_Pos)    /*!< 0x00000040 */
#define UART_CR1_TCIE                   UART_CR1_TCIE_Msk              /*!< </spirit:description> */
#define UART_CR1_TXEIE_TXFNFIE_Pos      (7U)
#define UART_CR1_TXEIE_TXFNFIE_Msk      (0x1UL << UART_CR1_TXEIE_TXFNFIE_Pos)     /*!< 0x00000080 */
#define UART_CR1_TXEIE_TXFNFIE          UART_CR1_TXEIE_TXFNFIE_Msk     /*!< </spirit:description> */
#define UART_CR1_PEIE_Pos               (8U)
#define UART_CR1_PEIE_Msk               (0x1UL << UART_CR1_PEIE_Pos)    /*!< 0x00000100 */
#define UART_CR1_PEIE                   UART_CR1_PEIE_Msk              /*!< </spirit:description> */
#define UART_CR1_PS_Pos                 (9U)
#define UART_CR1_PS_Msk                 (0x1UL << UART_CR1_PS_Pos)      /*!< 0x00000200 */
#define UART_CR1_PS                     UART_CR1_PS_Msk                /*!< </spirit:description> */
#define UART_CR1_PCE_Pos                (10U)
#define UART_CR1_PCE_Msk                (0x1UL << UART_CR1_PCE_Pos)     /*!< 0x00000400 */
#define UART_CR1_PCE                    UART_CR1_PCE_Msk               /*!< </spirit:description> */
#define UART_CR1_WAKE_Pos               (11U)
#define UART_CR1_WAKE_Msk               (0x1UL << UART_CR1_WAKE_Pos)    /*!< 0x00000800 */
#define UART_CR1_WAKE                   UART_CR1_WAKE_Msk              /*!< </spirit:description> */
#define UART_CR1_M0_Pos                 (12U)
#define UART_CR1_M0_Msk                 (0x1UL << UART_CR1_M0_Pos)      /*!< 0x00001000 */
#define UART_CR1_M0                     UART_CR1_M0_Msk                /*!< </spirit:description> */
#define UART_CR1_MME_Pos                (13U)
#define UART_CR1_MME_Msk                (0x1UL << UART_CR1_MME_Pos)     /*!< 0x00002000 */
#define UART_CR1_MME                    UART_CR1_MME_Msk               /*!< </spirit:description> */
#define UART_CR1_CMIE_Pos               (14U)
#define UART_CR1_CMIE_Msk               (0x1UL << UART_CR1_CMIE_Pos)    /*!< 0x00004000 */
#define UART_CR1_CMIE                   UART_CR1_CMIE_Msk              /*!< </spirit:description> */
#define UART_CR1_OVER8_Pos              (15U)
#define UART_CR1_OVER8_Msk              (0x1UL << UART_CR1_OVER8_Pos)   /*!< 0x00008000 */
#define UART_CR1_OVER8                  UART_CR1_OVER8_Msk             /*!< </spirit:description> */
#define UART_CR1_DEDT_Pos               (16U)
#define UART_CR1_DEDT_Msk               (0x1FUL << UART_CR1_DEDT_Pos)   /*!< 0x001F0000 */
#define UART_CR1_DEDT                   UART_CR1_DEDT_Msk              /*!< </spirit:description> */
#define UART_CR1_DEDT_0               (0x1UL << UART_CR1_DEDT_Pos)    /*!< 0x00010000 */
#define UART_CR1_DEDT_1               (0x2UL << UART_CR1_DEDT_Pos)    /*!< 0x00020000 */
#define UART_CR1_DEDT_2               (0x4UL << UART_CR1_DEDT_Pos)    /*!< 0x00040000 */
#define UART_CR1_DEDT_3               (0x8UL << UART_CR1_DEDT_Pos)    /*!< 0x00080000 */
#define UART_CR1_DEDT_4               (0x10UL << UART_CR1_DEDT_Pos)    /*!< 0x00100000 */
#define UART_CR1_DEAT_Pos               (21U)
#define UART_CR1_DEAT_Msk               (0x1FUL << UART_CR1_DEAT_Pos)   /*!< 0x03E00000 */
#define UART_CR1_DEAT                   UART_CR1_DEAT_Msk              /*!< </spirit:description> */
#define UART_CR1_DEAT_0               (0x1UL << UART_CR1_DEAT_Pos)    /*!< 0x00200000 */
#define UART_CR1_DEAT_1               (0x2UL << UART_CR1_DEAT_Pos)    /*!< 0x00400000 */
#define UART_CR1_DEAT_2               (0x4UL << UART_CR1_DEAT_Pos)    /*!< 0x00800000 */
#define UART_CR1_DEAT_3               (0x8UL << UART_CR1_DEAT_Pos)    /*!< 0x01000000 */
#define UART_CR1_DEAT_4               (0x10UL << UART_CR1_DEAT_Pos)    /*!< 0x02000000 */
#define UART_CR1_RTOIE_Pos              (26U)
#define UART_CR1_RTOIE_Msk              (0x1UL << UART_CR1_RTOIE_Pos)   /*!< 0x04000000 */
#define UART_CR1_RTOIE                  UART_CR1_RTOIE_Msk             /*!< </spirit:description> */
#define UART_CR1_EOBIE_Pos              (27U)
#define UART_CR1_EOBIE_Msk              (0x1UL << UART_CR1_EOBIE_Pos)   /*!< 0x08000000 */
#define UART_CR1_EOBIE                  UART_CR1_EOBIE_Msk             /*!< </spirit:description> */
#define UART_CR1_M1_Pos                 (28U)
#define UART_CR1_M1_Msk                 (0x1UL << UART_CR1_M1_Pos)      /*!< 0x10000000 */
#define UART_CR1_M1                     UART_CR1_M1_Msk                /*!< </spirit:description> */
#define UART_CR1_FIFOEN_Pos             (29U)
#define UART_CR1_FIFOEN_Msk             (0x1UL << UART_CR1_FIFOEN_Pos)  /*!< 0x20000000 */
#define UART_CR1_FIFOEN                 UART_CR1_FIFOEN_Msk            /*!< </spirit:description> */
#define UART_CR1_TXFEIE_Pos             (30U)
#define UART_CR1_TXFEIE_Msk             (0x1UL << UART_CR1_TXFEIE_Pos)  /*!< 0x40000000 */
#define UART_CR1_TXFEIE                 UART_CR1_TXFEIE_Msk            /*!< </spirit:description> */
#define UART_CR1_RXFFIE_Pos             (31U)
#define UART_CR1_RXFFIE_Msk             (0x1UL << UART_CR1_RXFFIE_Pos)  /*!< 0x80000000 */
#define UART_CR1_RXFFIE                 UART_CR1_RXFFIE_Msk            /*!< </spirit:description> */

/*******************  Bit definition for UART_CR2 register  *******************/
#define UART_CR2_SLVEN_Pos              (0U)
#define UART_CR2_SLVEN_Msk              (0x1UL << UART_CR2_SLVEN_Pos)   /*!< 0x00000001 */
#define UART_CR2_SLVEN                  UART_CR2_SLVEN_Msk             /*!< </spirit:description> */
#define UART_CR2_DIS_NSS_Pos            (3U)
#define UART_CR2_DIS_NSS_Msk            (0x1UL << UART_CR2_DIS_NSS_Pos) /*!< 0x00000008 */
#define UART_CR2_DIS_NSS                UART_CR2_DIS_NSS_Msk           /*!< </spirit:description> */
#define UART_CR2_ADDM7_Pos              (4U)
#define UART_CR2_ADDM7_Msk              (0x1UL << UART_CR2_ADDM7_Pos)   /*!< 0x00000010 */
#define UART_CR2_ADDM7                  UART_CR2_ADDM7_Msk             /*!< </spirit:description> */
#define UART_CR2_LBDL_Pos               (5U)
#define UART_CR2_LBDL_Msk               (0x1UL << UART_CR2_LBDL_Pos)    /*!< 0x00000020 */
#define UART_CR2_LBDL                   UART_CR2_LBDL_Msk              /*!< </spirit:description> */
#define UART_CR2_LBDIE_Pos              (6U)
#define UART_CR2_LBDIE_Msk              (0x1UL << UART_CR2_LBDIE_Pos)   /*!< 0x00000040 */
#define UART_CR2_LBDIE                  UART_CR2_LBDIE_Msk             /*!< </spirit:description> */
#define UART_CR2_LBCL_Pos               (8U)
#define UART_CR2_LBCL_Msk               (0x1UL << UART_CR2_LBCL_Pos)    /*!< 0x00000100 */
#define UART_CR2_LBCL                   UART_CR2_LBCL_Msk              /*!< </spirit:description> */
#define UART_CR2_CPHA_Pos               (9U)
#define UART_CR2_CPHA_Msk               (0x1UL << UART_CR2_CPHA_Pos)    /*!< 0x00000200 */
#define UART_CR2_CPHA                   UART_CR2_CPHA_Msk              /*!< </spirit:description> */
#define UART_CR2_CPOL_Pos               (10U)
#define UART_CR2_CPOL_Msk               (0x1UL << UART_CR2_CPOL_Pos)    /*!< 0x00000400 */
#define UART_CR2_CPOL                   UART_CR2_CPOL_Msk              /*!< </spirit:description> */
#define UART_CR2_CLKEN_Pos              (11U)
#define UART_CR2_CLKEN_Msk              (0x1UL << UART_CR2_CLKEN_Pos)   /*!< 0x00000800 */
#define UART_CR2_CLKEN                  UART_CR2_CLKEN_Msk             /*!< </spirit:description> */
#define UART_CR2_STOP_Pos               (12U)
#define UART_CR2_STOP_Msk               (0x3UL << UART_CR2_STOP_Pos)    /*!< 0x00003000 */
#define UART_CR2_STOP                   UART_CR2_STOP_Msk              /*!< </spirit:description> */
#define UART_CR2_STOP_0               (0x1UL << UART_CR2_STOP_Pos)     /*!< 0x00001000 */
#define UART_CR2_STOP_1               (0x2UL << UART_CR2_STOP_Pos)     /*!< 0x00002000 */
#define UART_CR2_LINEN_Pos              (14U)
#define UART_CR2_LINEN_Msk              (0x1UL << UART_CR2_LINEN_Pos)   /*!< 0x00004000 */
#define UART_CR2_LINEN                  UART_CR2_LINEN_Msk             /*!< </spirit:description> */
#define UART_CR2_SWAP_Pos               (15U)
#define UART_CR2_SWAP_Msk               (0x1UL << UART_CR2_SWAP_Pos)    /*!< 0x00008000 */
#define UART_CR2_SWAP                   UART_CR2_SWAP_Msk              /*!< </spirit:description> */
#define UART_CR2_RXINV_Pos              (16U)
#define UART_CR2_RXINV_Msk              (0x1UL << UART_CR2_RXINV_Pos)   /*!< 0x00010000 */
#define UART_CR2_RXINV                  UART_CR2_RXINV_Msk             /*!< </spirit:description> */
#define UART_CR2_TXINV_Pos              (17U)
#define UART_CR2_TXINV_Msk              (0x1UL << UART_CR2_TXINV_Pos)   /*!< 0x00020000 */
#define UART_CR2_TXINV                  UART_CR2_TXINV_Msk             /*!< </spirit:description> */
#define UART_CR2_DATAINV_Pos            (18U)
#define UART_CR2_DATAINV_Msk            (0x1UL << UART_CR2_DATAINV_Pos) /*!< 0x00040000 */
#define UART_CR2_DATAINV                UART_CR2_DATAINV_Msk           /*!< </spirit:description> */
#define UART_CR2_MSBFIRST_Pos           (19U)
#define UART_CR2_MSBFIRST_Msk            (0x1UL << UART_CR2_MSBFIRST_Pos) /*!< 0x00080000 */
#define UART_CR2_MSBFIRST               UART_CR2_MSBFIRST_Msk          /*!< </spirit:description> */
#define UART_CR2_ABREN_Pos              (20U)
#define UART_CR2_ABREN_Msk              (0x1UL << UART_CR2_ABREN_Pos)   /*!< 0x00100000 */
#define UART_CR2_ABREN                  UART_CR2_ABREN_Msk             /*!< </spirit:description> */
#define UART_CR2_ABRMODE_Pos            (21U)
#define UART_CR2_ABRMODE_Msk            (0x3UL << UART_CR2_ABRMODE_Pos) /*!< 0x00600000 */
#define UART_CR2_ABRMODE                UART_CR2_ABRMODE_Msk           /*!< </spirit:description> */
#define UART_CR2_ABRMODE_0            (0x1UL << UART_CR2_ABRMODE_Pos)  /*!< 0x00200000 */
#define UART_CR2_ABRMODE_1            (0x2UL << UART_CR2_ABRMODE_Pos)  /*!< 0x00400000 */
#define UART_CR2_RTOEN_Pos              (23U)
#define UART_CR2_RTOEN_Msk              (0x1UL << UART_CR2_RTOEN_Pos)   /*!< 0x00800000 */
#define UART_CR2_RTOEN                  UART_CR2_RTOEN_Msk             /*!< </spirit:description> */
#define UART_CR2_ADD_Pos                (24U)
#define UART_CR2_ADD_Msk                (0xFFUL << UART_CR2_ADD_Pos)    /*!< 0xFF000000 */
#define UART_CR2_ADD                    UART_CR2_ADD_Msk               /*!< </spirit:description> */

/*******************  Bit definition for UART_CR3 register  *******************/
#define UART_CR3_EIE_Pos                (0U)
#define UART_CR3_EIE_Msk                (0x1UL << UART_CR3_EIE_Pos)     /*!< 0x00000001 */
#define UART_CR3_EIE                    UART_CR3_EIE_Msk               /*!< </spirit:description> */
#define UART_CR3_IREN_Pos               (1U)
#define UART_CR3_IREN_Msk               (0x1UL << UART_CR3_IREN_Pos)    /*!< 0x00000002 */
#define UART_CR3_IREN                   UART_CR3_IREN_Msk              /*!< </spirit:description> */
#define UART_CR3_IRLP_Pos               (2U)
#define UART_CR3_IRLP_Msk               (0x1UL << UART_CR3_IRLP_Pos)    /*!< 0x00000004 */
#define UART_CR3_IRLP                   UART_CR3_IRLP_Msk              /*!< </spirit:description> */
#define UART_CR3_HDSEL_Pos              (3U)
#define UART_CR3_HDSEL_Msk              (0x1UL << UART_CR3_HDSEL_Pos)   /*!< 0x00000008 */
#define UART_CR3_HDSEL                  UART_CR3_HDSEL_Msk             /*!< </spirit:description> */
#define UART_CR3_NACK_Pos               (4U)
#define UART_CR3_NACK_Msk               (0x1UL << UART_CR3_NACK_Pos)    /*!< 0x00000010 */
#define UART_CR3_NACK                   UART_CR3_NACK_Msk              /*!< </spirit:description> */
#define UART_CR3_SCEN_Pos               (5U)
#define UART_CR3_SCEN_Msk               (0x1UL << UART_CR3_SCEN_Pos)    /*!< 0x00000020 */
#define UART_CR3_SCEN                   UART_CR3_SCEN_Msk              /*!< </spirit:description> */
#define UART_CR3_DMAR_Pos               (6U)
#define UART_CR3_DMAR_Msk               (0x1UL << UART_CR3_DMAR_Pos)    /*!< 0x00000040 */
#define UART_CR3_DMAR                   UART_CR3_DMAR_Msk              /*!< </spirit:description> */
#define UART_CR3_DMAT_Pos               (7U)
#define UART_CR3_DMAT_Msk               (0x1UL << UART_CR3_DMAT_Pos)    /*!< 0x00000080 */
#define UART_CR3_DMAT                   UART_CR3_DMAT_Msk              /*!< </spirit:description> */
#define UART_CR3_RTSE_Pos               (8U)
#define UART_CR3_RTSE_Msk               (0x1UL << UART_CR3_RTSE_Pos)    /*!< 0x00000100 */
#define UART_CR3_RTSE                   UART_CR3_RTSE_Msk              /*!< </spirit:description> */
#define UART_CR3_CTSE_Pos               (9U)
#define UART_CR3_CTSE_Msk               (0x1UL << UART_CR3_CTSE_Pos)    /*!< 0x00000200 */
#define UART_CR3_CTSE                   UART_CR3_CTSE_Msk              /*!< </spirit:description> */
#define UART_CR3_CTSIE_Pos              (10U)
#define UART_CR3_CTSIE_Msk              (0x1UL << UART_CR3_CTSIE_Pos)   /*!< 0x00000400 */
#define UART_CR3_CTSIE                  UART_CR3_CTSIE_Msk             /*!< </spirit:description> */
#define UART_CR3_ONEBIT_Pos             (11U)
#define UART_CR3_ONEBIT_Msk             (0x1UL << UART_CR3_ONEBIT_Pos)  /*!< 0x00000800 */
#define UART_CR3_ONEBIT                 UART_CR3_ONEBIT_Msk            /*!< </spirit:description> */
#define UART_CR3_OVRDIS_Pos             (12U)
#define UART_CR3_OVRDIS_Msk             (0x1UL << UART_CR3_OVRDIS_Pos)  /*!< 0x00001000 */
#define UART_CR3_OVRDIS                 UART_CR3_OVRDIS_Msk            /*!< </spirit:description> */
#define UART_CR3_DDRE_Pos               (13U)
#define UART_CR3_DDRE_Msk               (0x1UL << UART_CR3_DDRE_Pos)    /*!< 0x00002000 */
#define UART_CR3_DDRE                   UART_CR3_DDRE_Msk              /*!< </spirit:description> */
#define UART_CR3_DEM_Pos                (14U)
#define UART_CR3_DEM_Msk                (0x1UL << UART_CR3_DEM_Pos)     /*!< 0x00004000 */
#define UART_CR3_DEM                    UART_CR3_DEM_Msk               /*!< </spirit:description> */
#define UART_CR3_DEP_Pos                (15U)
#define UART_CR3_DEP_Msk                (0x1UL << UART_CR3_DEP_Pos)     /*!< 0x00008000 */
#define UART_CR3_DEP                    UART_CR3_DEP_Msk               /*!< </spirit:description> */
#define UART_CR3_SCARCNT_Pos            (17U)
#define UART_CR3_SCARCNT_Msk            (0x7UL << UART_CR3_SCARCNT_Pos) /*!< 0x000E0000 */
#define UART_CR3_SCARCNT                UART_CR3_SCARCNT_Msk           /*!< </spirit:description> */
#define UART_CR3_SCARCNT_0            (0x1UL << UART_CR3_SCARCNT_Pos)  /*!< 0x00020000 */
#define UART_CR3_SCARCNT_1            (0x2UL << UART_CR3_SCARCNT_Pos)  /*!< 0x00040000 */
#define UART_CR3_SCARCNT_2            (0x4UL << UART_CR3_SCARCNT_Pos)  /*!< 0x00080000 */
#define UART_CR3_WUS_Pos                (20U)
#define UART_CR3_WUS_Msk                (0x3UL << UART_CR3_WUS_Pos)     /*!< 0x00300000 */
#define UART_CR3_WUS                    UART_CR3_WUS_Msk               /*!< </spirit:description> */
#define UART_CR3_WUS_0                (0x1UL << UART_CR3_WUS_Pos)      /*!< 0x00100000 */
#define UART_CR3_WUS_1                (0x2UL << UART_CR3_WUS_Pos)      /*!< 0x00200000 */
#define UART_CR3_WUFIE_Pos              (22U)
#define UART_CR3_WUFIE_Msk              (0x1UL << UART_CR3_WUFIE_Pos)   /*!< 0x00400000 */
#define UART_CR3_WUFIE                  UART_CR3_WUFIE_Msk             /*!< </spirit:description> */
#define UART_CR3_TXFTIE_Pos             (23U)
#define UART_CR3_TXFTIE_Msk             (0x1UL << UART_CR3_TXFTIE_Pos)  /*!< 0x00800000 */
#define UART_CR3_TXFTIE                 UART_CR3_TXFTIE_Msk            /*!< </spirit:description> */
#define UART_CR3_TCBGTIE_Pos            (24U)
#define UART_CR3_TCBGTIE_Msk            (0x1UL << UART_CR3_TCBGTIE_Pos) /*!< 0x01000000 */
#define UART_CR3_TCBGTIE                UART_CR3_TCBGTIE_Msk           /*!< </spirit:description> */
#define UART_CR3_RXFTCFG_Pos            (25U)
#define UART_CR3_RXFTCFG_Msk            (0x7UL << UART_CR3_RXFTCFG_Pos) /*!< 0x0E000000 */
#define UART_CR3_RXFTCFG                UART_CR3_RXFTCFG_Msk           /*!< </spirit:description> */
#define UART_CR3_RXFTCFG_0            (0x1UL << UART_CR3_RXFTCFG_Pos)  /*!< 0x02000000 */
#define UART_CR3_RXFTCFG_1            (0x2UL << UART_CR3_RXFTCFG_Pos)  /*!< 0x04000000 */
#define UART_CR3_RXFTCFG_2            (0x4UL << UART_CR3_RXFTCFG_Pos)  /*!< 0x08000000 */
#define UART_CR3_RXFTIE_Pos             (28U)
#define UART_CR3_RXFTIE_Msk             (0x1UL << UART_CR3_RXFTIE_Pos)  /*!< 0x10000000 */
#define UART_CR3_RXFTIE                 UART_CR3_RXFTIE_Msk            /*!< </spirit:description> */
#define UART_CR3_TXFTCFG_Pos            (29U)
#define UART_CR3_TXFTCFG_Msk            (0x7UL << UART_CR3_TXFTCFG_Pos) /*!< 0xE0000000 */
#define UART_CR3_TXFTCFG                UART_CR3_TXFTCFG_Msk           /*!< </spirit:description> */
#define UART_CR3_TXFTCFG_0            (0x1UL << UART_CR3_TXFTCFG_Pos)  /*!< 0x20000000 */
#define UART_CR3_TXFTCFG_1            (0x2UL << UART_CR3_TXFTCFG_Pos)  /*!< 0x40000000 */
#define UART_CR3_TXFTCFG_2            (0x4UL << UART_CR3_TXFTCFG_Pos)  /*!< 0x80000000 */

/*******************  Bit definition for UART_BRR register  *******************/
#define UART_BRR_BRR_Pos                (0U)
#define UART_BRR_BRR_Msk                (0xFFFFUL << UART_BRR_BRR_Pos)  /*!< 0x0000FFFF */
#define UART_BRR_BRR                    UART_BRR_BRR_Msk               /*!< </spirit:description> */

/******************  Bit definition for UART_GTPR register  *******************/
#define UART_GTPR_PSC_Pos               (0U)
#define UART_GTPR_PSC_Msk               (0xFFUL << UART_GTPR_PSC_Pos)   /*!< 0x000000FF */
#define UART_GTPR_PSC                   UART_GTPR_PSC_Msk              /*!< </spirit:description> */
#define UART_GTPR_GT_Pos                (8U)
#define UART_GTPR_GT_Msk                (0xFFUL << UART_GTPR_GT_Pos)    /*!< 0x0000FF00 */
#define UART_GTPR_GT                    UART_GTPR_GT_Msk               /*!< </spirit:description> */

/******************  Bit definition for UART_RTOR register  *******************/
#define UART_RTOR_RTO_Pos               (0U)
#define UART_RTOR_RTO_Msk               (0xFFFFFFUL << UART_RTOR_RTO_Pos) /*!< 0x00FFFFFF */
#define UART_RTOR_RTO                   UART_RTOR_RTO_Msk              /*!< </spirit:description> */
#define UART_RTOR_BLEN_Pos              (24U)
#define UART_RTOR_BLEN_Msk              (0xFFUL << UART_RTOR_BLEN_Pos)  /*!< 0xFF000000 */
#define UART_RTOR_BLEN                  UART_RTOR_BLEN_Msk             /*!< </spirit:description> */

/*******************  Bit definition for UART_RQR register  *******************/
#define UART_RQR_ABRRQ_Pos              (0U)
#define UART_RQR_ABRRQ_Msk              (0x1UL << UART_RQR_ABRRQ_Pos)   /*!< 0x00000001 */
#define UART_RQR_ABRRQ                  UART_RQR_ABRRQ_Msk             /*!< </spirit:description> */
#define UART_RQR_SBKRQ_Pos              (1U)
#define UART_RQR_SBKRQ_Msk              (0x1UL << UART_RQR_SBKRQ_Pos)   /*!< 0x00000002 */
#define UART_RQR_SBKRQ                  UART_RQR_SBKRQ_Msk             /*!< </spirit:description> */
#define UART_RQR_MMRQ_Pos               (2U)
#define UART_RQR_MMRQ_Msk               (0x1UL << UART_RQR_MMRQ_Pos)    /*!< 0x00000004 */
#define UART_RQR_MMRQ                   UART_RQR_MMRQ_Msk              /*!< </spirit:description> */
#define UART_RQR_RXFRQ_Pos              (3U)
#define UART_RQR_RXFRQ_Msk              (0x1UL << UART_RQR_RXFRQ_Pos)   /*!< 0x00000008 */
#define UART_RQR_RXFRQ                  UART_RQR_RXFRQ_Msk             /*!< </spirit:description> */
#define UART_RQR_TXFRQ_Pos              (4U)
#define UART_RQR_TXFRQ_Msk              (0x1UL << UART_RQR_TXFRQ_Pos)   /*!< 0x00000010 */
#define UART_RQR_TXFRQ                  UART_RQR_TXFRQ_Msk             /*!< </spirit:description> */

/*******************  Bit definition for UART_ISR register  *******************/
#define UART_ISR_PE_Pos                 (0U)
#define UART_ISR_PE_Msk                 (0x1UL << UART_ISR_PE_Pos)      /*!< 0x00000001 */
#define UART_ISR_PE                     UART_ISR_PE_Msk                /*!< </spirit:description> */
#define UART_ISR_FE_Pos                 (1U)
#define UART_ISR_FE_Msk                 (0x1UL << UART_ISR_FE_Pos)      /*!< 0x00000002 */
#define UART_ISR_FE                     UART_ISR_FE_Msk                /*!< </spirit:description> */
#define UART_ISR_NE_Pos                 (2U)
#define UART_ISR_NE_Msk                 (0x1UL << UART_ISR_NE_Pos)      /*!< 0x00000004 */
#define UART_ISR_NE                     UART_ISR_NE_Msk                /*!< </spirit:description> */
#define UART_ISR_ORE_Pos                (3U)
#define UART_ISR_ORE_Msk                (0x1UL << UART_ISR_ORE_Pos)     /*!< 0x00000008 */
#define UART_ISR_ORE                    UART_ISR_ORE_Msk               /*!< </spirit:description> */
#define UART_ISR_IDLE_Pos               (4U)
#define UART_ISR_IDLE_Msk               (0x1UL << UART_ISR_IDLE_Pos)    /*!< 0x00000010 */
#define UART_ISR_IDLE                   UART_ISR_IDLE_Msk              /*!< </spirit:description> */
#define UART_ISR_RXNE_RXFNE_Pos         (5U)
#define UART_ISR_RXNE_RXFNE_Msk         (0x1UL << UART_ISR_RXNE_RXFNE_Pos)  /*!< 0x00000020 */
#define UART_ISR_RXNE_RXFNE             UART_ISR_RXNE_RXFNE_Msk        /*!< </spirit:description> */
#define UART_ISR_TC_Pos                 (6U)
#define UART_ISR_TC_Msk                 (0x1UL << UART_ISR_TC_Pos)      /*!< 0x00000040 */
#define UART_ISR_TC                     UART_ISR_TC_Msk                /*!< </spirit:description> */
#define UART_ISR_TXE_TXFNF_Pos          (7U)
#define UART_ISR_TXE_TXFNF_Msk          (0x1UL << UART_ISR_TXE_TXFNF_Pos) /*!< 0x00000080 */
#define UART_ISR_TXE_TXFNF              UART_ISR_TXE_TXFNF_Msk         /*!< </spirit:description> */
#define UART_ISR_LBDF_Pos               (8U)
#define UART_ISR_LBDF_Msk               (0x1UL << UART_ISR_LBDF_Pos)    /*!< 0x00000100 */
#define UART_ISR_LBDF                   UART_ISR_LBDF_Msk              /*!< </spirit:description> */
#define UART_ISR_CTSIF_Pos              (9U)
#define UART_ISR_CTSIF_Msk              (0x1UL << UART_ISR_CTSIF_Pos)   /*!< 0x00000200 */
#define UART_ISR_CTSIF                  UART_ISR_CTSIF_Msk             /*!< </spirit:description> */
#define UART_ISR_CTS_Pos                (10U)
#define UART_ISR_CTS_Msk                (0x1UL << UART_ISR_CTS_Pos)     /*!< 0x00000400 */
#define UART_ISR_CTS                    UART_ISR_CTS_Msk               /*!< </spirit:description> */
#define UART_ISR_RTOF_Pos               (11U)
#define UART_ISR_RTOF_Msk               (0x1UL << UART_ISR_RTOF_Pos)    /*!< 0x00000800 */
#define UART_ISR_RTOF                   UART_ISR_RTOF_Msk              /*!< </spirit:description> */
#define UART_ISR_EOBF_Pos               (12U)
#define UART_ISR_EOBF_Msk               (0x1UL << UART_ISR_EOBF_Pos)    /*!< 0x00001000 */
#define UART_ISR_EOBF                   UART_ISR_EOBF_Msk              /*!< </spirit:description> */
#define UART_ISR_UDR_Pos                (13U)
#define UART_ISR_UDR_Msk                (0x1UL << UART_ISR_UDR_Pos)     /*!< 0x00002000 */
#define UART_ISR_UDR                    UART_ISR_UDR_Msk               /*!< </spirit:description> */
#define UART_ISR_ABRE_Pos               (14U)
#define UART_ISR_ABRE_Msk               (0x1UL << UART_ISR_ABRE_Pos)    /*!< 0x00004000 */
#define UART_ISR_ABRE                   UART_ISR_ABRE_Msk              /*!< </spirit:description> */
#define UART_ISR_ABRF_Pos               (15U)
#define UART_ISR_ABRF_Msk               (0x1UL << UART_ISR_ABRF_Pos)    /*!< 0x00008000 */
#define UART_ISR_ABRF                   UART_ISR_ABRF_Msk              /*!< </spirit:description> */
#define UART_ISR_BUSY_Pos               (16U)
#define UART_ISR_BUSY_Msk               (0x1UL << UART_ISR_BUSY_Pos)    /*!< 0x00010000 */
#define UART_ISR_BUSY                   UART_ISR_BUSY_Msk              /*!< </spirit:description> */
#define UART_ISR_CMF_Pos                (17U)
#define UART_ISR_CMF_Msk                (0x1UL << UART_ISR_CMF_Pos)     /*!< 0x00020000 */
#define UART_ISR_CMF                    UART_ISR_CMF_Msk               /*!< </spirit:description> */
#define UART_ISR_SBKF_Pos               (18U)
#define UART_ISR_SBKF_Msk               (0x1UL << UART_ISR_SBKF_Pos)    /*!< 0x00040000 */
#define UART_ISR_SBKF                   UART_ISR_SBKF_Msk              /*!< </spirit:description> */
#define UART_ISR_RWU_Pos                (19U)
#define UART_ISR_RWU_Msk                (0x1UL << UART_ISR_RWU_Pos)     /*!< 0x00080000 */
#define UART_ISR_RWU                    UART_ISR_RWU_Msk               /*!< </spirit:description> */
#define UART_ISR_WUF_Pos                (20U)
#define UART_ISR_WUF_Msk                (0x1UL << UART_ISR_WUF_Pos)     /*!< 0x00100000 */
#define UART_ISR_WUF                    UART_ISR_WUF_Msk               /*!< </spirit:description> */
#define UART_ISR_TEACK_Pos              (21U)
#define UART_ISR_TEACK_Msk              (0x1UL << UART_ISR_TEACK_Pos)   /*!< 0x00200000 */
#define UART_ISR_TEACK                  UART_ISR_TEACK_Msk             /*!< </spirit:description> */
#define UART_ISR_REACK_Pos              (22U)
#define UART_ISR_REACK_Msk              (0x1UL << UART_ISR_REACK_Pos)   /*!< 0x00400000 */
#define UART_ISR_REACK                  UART_ISR_REACK_Msk             /*!< </spirit:description> */
#define UART_ISR_TXFE_Pos               (23U)
#define UART_ISR_TXFE_Msk               (0x1UL << UART_ISR_TXFE_Pos)    /*!< 0x00800000 */
#define UART_ISR_TXFE                   UART_ISR_TXFE_Msk              /*!< </spirit:description> */
#define UART_ISR_RXFF_Pos               (24U)
#define UART_ISR_RXFF_Msk               (0x1UL << UART_ISR_RXFF_Pos)    /*!< 0x01000000 */
#define UART_ISR_RXFF                   UART_ISR_RXFF_Msk              /*!< </spirit:description> */
#define UART_ISR_TCBGT_Pos              (25U)
#define UART_ISR_TCBGT_Msk              (0x1UL << UART_ISR_TCBGT_Pos)   /*!< 0x02000000 */
#define UART_ISR_TCBGT                  UART_ISR_TCBGT_Msk             /*!< </spirit:description> */
#define UART_ISR_RXFT_Pos               (26U)
#define UART_ISR_RXFT_Msk               (0x1UL << UART_ISR_RXFT_Pos)    /*!< 0x04000000 */
#define UART_ISR_RXFT                   UART_ISR_RXFT_Msk              /*!< </spirit:description> */
#define UART_ISR_TXFT_Pos               (27U)
#define UART_ISR_TXFT_Msk               (0x1UL << UART_ISR_TXFT_Pos)    /*!< 0x08000000 */
#define UART_ISR_TXFT                   UART_ISR_TXFT_Msk              /*!< </spirit:description> */

/*******************  Bit definition for UART_ICR register  *******************/
#define UART_ICR_PECF_Pos               (0U)
#define UART_ICR_PECF_Msk               (0x1UL << UART_ICR_PECF_Pos)    /*!< 0x00000001 */
#define UART_ICR_PECF                   UART_ICR_PECF_Msk              /*!< </spirit:description> */
#define UART_ICR_FECF_Pos               (1U)
#define UART_ICR_FECF_Msk               (0x1UL << UART_ICR_FECF_Pos)    /*!< 0x00000002 */
#define UART_ICR_FECF                   UART_ICR_FECF_Msk              /*!< </spirit:description> */
#define UART_ICR_NECF_Pos               (2U)
#define UART_ICR_NECF_Msk               (0x1UL << UART_ICR_NECF_Pos)    /*!< 0x00000004 */
#define UART_ICR_NECF                   UART_ICR_NECF_Msk              /*!< </spirit:description> */
#define UART_ICR_ORECF_Pos              (3U)
#define UART_ICR_ORECF_Msk              (0x1UL << UART_ICR_ORECF_Pos)   /*!< 0x00000008 */
#define UART_ICR_ORECF                  UART_ICR_ORECF_Msk             /*!< </spirit:description> */
#define UART_ICR_IDLECF_Pos             (4U)
#define UART_ICR_IDLECF_Msk             (0x1UL << UART_ICR_IDLECF_Pos)  /*!< 0x00000010 */
#define UART_ICR_IDLECF                 UART_ICR_IDLECF_Msk            /*!< </spirit:description> */
#define UART_ICR_TXFECF_Pos             (5U)
#define UART_ICR_TXFECF_Msk             (0x1UL << UART_ICR_TXFECF_Pos)  /*!< 0x00000020 */
#define UART_ICR_TXFECF                 UART_ICR_TXFECF_Msk            /*!< </spirit:description> */
#define UART_ICR_TCCF_Pos               (6U)
#define UART_ICR_TCCF_Msk               (0x1UL << UART_ICR_TCCF_Pos)    /*!< 0x00000040 */
#define UART_ICR_TCCF                   UART_ICR_TCCF_Msk              /*!< </spirit:description> */
#define UART_ICR_TCBGTCF_Pos            (7U)
#define UART_ICR_TCBGTCF_Msk            (0x1UL << UART_ICR_TCBGTCF_Pos) /*!< 0x00000080 */
#define UART_ICR_TCBGTCF                UART_ICR_TCBGTCF_Msk           /*!< </spirit:description> */
#define UART_ICR_LBDCF_Pos              (8U)
#define UART_ICR_LBDCF_Msk              (0x1UL << UART_ICR_LBDCF_Pos)   /*!< 0x00000100 */
#define UART_ICR_LBDCF                  UART_ICR_LBDCF_Msk             /*!< </spirit:description> */
#define UART_ICR_CTSCF_Pos              (9U)
#define UART_ICR_CTSCF_Msk              (0x1UL << UART_ICR_CTSCF_Pos)   /*!< 0x00000200 */
#define UART_ICR_CTSCF                  UART_ICR_CTSCF_Msk             /*!< </spirit:description> */
#define UART_ICR_RTOCF_Pos              (11U)
#define UART_ICR_RTOCF_Msk              (0x1UL << UART_ICR_RTOCF_Pos)   /*!< 0x00000800 */
#define UART_ICR_RTOCF                  UART_ICR_RTOCF_Msk             /*!< </spirit:description> */
#define UART_ICR_EOBCF_Pos              (12U)
#define UART_ICR_EOBCF_Msk              (0x1UL << UART_ICR_EOBCF_Pos)   /*!< 0x00001000 */
#define UART_ICR_EOBCF                  UART_ICR_EOBCF_Msk             /*!< </spirit:description> */
#define UART_ICR_UDRCF_Pos              (13U)
#define UART_ICR_UDRCF_Msk              (0x1UL << UART_ICR_UDRCF_Pos)   /*!< 0x00002000 */
#define UART_ICR_UDRCF                  UART_ICR_UDRCF_Msk             /*!< </spirit:description> */
#define UART_ICR_CMCF_Pos               (17U)
#define UART_ICR_CMCF_Msk               (0x1UL << UART_ICR_CMCF_Pos)    /*!< 0x00020000 */
#define UART_ICR_CMCF                   UART_ICR_CMCF_Msk              /*!< </spirit:description> */
#define UART_ICR_WUCF_Pos               (20U)
#define UART_ICR_WUCF_Msk               (0x1UL << UART_ICR_WUCF_Pos)    /*!< 0x00100000 */
#define UART_ICR_WUCF                   UART_ICR_WUCF_Msk              /*!< </spirit:description> */

/*******************  Bit definition for UART_RDR register  *******************/
#define UART_RDR_RDR_Pos                (0U)
#define UART_RDR_RDR_Msk                (0x1FFUL << UART_RDR_RDR_Pos)   /*!< 0x000001FF */
#define UART_RDR_RDR                    UART_RDR_RDR_Msk               /*!< </spirit:description> */

/*******************  Bit definition for UART_TDR register  *******************/
#define UART_TDR_TDR_Pos                (0U)
#define UART_TDR_TDR_Msk                (0x1FFUL << UART_TDR_TDR_Pos)   /*!< 0x000001FF */
#define UART_TDR_TDR                    UART_TDR_TDR_Msk               /*!< </spirit:description> */

/******************  Bit definition for UART_PRESC register  ******************/
#define UART_PRESC_PRESCALER_Pos        (0U)
#define UART_PRESC_PRESCALER_Msk        (0xFUL << UART_PRESC_PRESCALER_Pos)   /*!< 0x0000000F */
#define UART_PRESC_PRESCALER            UART_PRESC_PRESCALER_Msk       /*!< </spirit:description> */
#define UART_PRESC_PRESCALER_0        (0x1UL << UART_PRESC_PRESCALER_Pos)    /*!< 0x00000001 */
#define UART_PRESC_PRESCALER_1        (0x2UL << UART_PRESC_PRESCALER_Pos)    /*!< 0x00000002 */
#define UART_PRESC_PRESCALER_2        (0x4UL << UART_PRESC_PRESCALER_Pos)    /*!< 0x00000004 */
#define UART_PRESC_PRESCALER_3        (0x8UL << UART_PRESC_PRESCALER_Pos)    /*!< 0x00000008 */

#define UART1_BASE           0x42006C00UL
#define UART2_BASE           0x40006C00UL 
#define UART3_BASE           0x40007000UL 

#define UART1                ((UART_TypeDef *) UART1_BASE) 
#define UART2                ((UART_TypeDef *) UART2_BASE) 
#define UART3                ((UART_TypeDef *) UART3_BASE) 

#endif /* __SR5E1_UART_H */

