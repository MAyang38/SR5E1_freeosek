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

#ifndef __SR5E1_HSEM_H
#define __SR5E1_HSEM_H

/******************************************************************************/
/*                                                                            */
/*                                HSEM (HSEM)                                 */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO uint32_t R[32];         /*!< R        Address offset: 0x000-0x07C */
  __IO uint32_t RLR[32];       /*!< RLR      Address offset: 0x080-0x0FC */
  __IO uint32_t C1IER;         /*!< C1IER    Address offset: 0x100 */
  __IO uint32_t C1ICR;         /*!< C1ICR    Address offset: 0x104 */
  __IO uint32_t C1ISR;         /*!< C1ISR    Address offset: 0x108 */
  __IO uint32_t C1MISR;        /*!< C1MISR   Address offset: 0x10C */
  __IO uint32_t C2IER;         /*!< C2IER    Address offset: 0x110 */
  __IO uint32_t C2ICR;         /*!< C2ICR    Address offset: 0x114 */
  __IO uint32_t C2ISR;         /*!< C2ISR    Address offset: 0x118 */
  __IO uint32_t C2MISR;        /*!< C2MISR   Address offset: 0x11C */
  __IO uint32_t C3IER;         /*!< C3IER    Address offset: 0x120 */
  __IO uint32_t C3ICR;         /*!< C3ICR    Address offset: 0x124 */
  __IO uint32_t C3ISR;         /*!< C3ISR    Address offset: 0x128 */
  __IO uint32_t C3MISR;        /*!< C3MISR   Address offset: 0x12C */
       uint32_t RESERVED0[4];  /*!< Reserved Address offset: 0x130-0x13C */
  __IO uint32_t CR;            /*!< CR       Address offset: 0x140 */
  __IO uint32_t KEYR;          /*!< KEYR     Address offset: 0x144 */
} HSEM_TypeDef;


/********************  Bit definition for HSEM_R register  ********************/
#define HSEM_R_PROCID_Pos          (0U)
#define HSEM_R_PROCID_Msk          (0xFFUL << HSEM_R_PROCID_Pos)  /*!< 0x000000FF */
#define HSEM_R_PROCID              HSEM_R_PROCID_Msk         /*!< </spirit:description> */
#define HSEM_R_COREID_Pos          (8U)
#define HSEM_R_COREID_Msk          (0xFUL << HSEM_R_COREID_Pos) /*!< 0x00000F00 */
#define HSEM_R_COREID              HSEM_R_COREID_Msk         /*!< </spirit:description> */
#define HSEM_R_LOCK_Pos            (31U)
#define HSEM_R_LOCK_Msk            (0x1UL << HSEM_R_LOCK_Pos) /*!< 0x80000000 */
#define HSEM_R_LOCK                HSEM_R_LOCK_Msk           /*!< </spirit:description> */

/*******************  Bit definition for HSEM_RLR register  *******************/
#define HSEM_RLR_PROCID_Pos        (0U)
#define HSEM_RLR_PROCID_Msk        (0xFFUL << HSEM_RLR_PROCID_Pos)    /*!< 0x000000FF */
#define HSEM_RLR_PROCID            HSEM_RLR_PROCID_Msk       /*!< </spirit:description> */
#define HSEM_RLR_COREID_Pos        (8U)
#define HSEM_RLR_COREID_Msk        (0xFUL << HSEM_RLR_COREID_Pos)   /*!< 0x00000F00 */
#define HSEM_RLR_COREID            HSEM_RLR_COREID_Msk       /*!< </spirit:description> */
#define HSEM_RLR_LOCK_Pos          (31U)
#define HSEM_RLR_LOCK_Msk          (0x1UL << HSEM_RLR_LOCK_Pos) /*!< 0x80000000 */
#define HSEM_RLR_LOCK              HSEM_RLR_LOCK_Msk         /*!< </spirit:description> */

/******************  Bit definition for HSEM_C1IER register  ******************/
#define HSEM_C1IER_ISE0_Pos        (0U)
#define HSEM_C1IER_ISE0_Msk        (0x1UL << HSEM_C1IER_ISE0_Pos)   /*!< 0x00000001 */
#define HSEM_C1IER_ISE0            HSEM_C1IER_ISE0_Msk       /*!< </spirit:description> */
#define HSEM_C1IER_ISE1_Pos        (1U)
#define HSEM_C1IER_ISE1_Msk        (0x1UL << HSEM_C1IER_ISE1_Pos)   /*!< 0x00000002 */
#define HSEM_C1IER_ISE1            HSEM_C1IER_ISE1_Msk       /*!< </spirit:description> */
#define HSEM_C1IER_ISE2_Pos        (2U)
#define HSEM_C1IER_ISE2_Msk        (0x1UL << HSEM_C1IER_ISE2_Pos)   /*!< 0x00000004 */
#define HSEM_C1IER_ISE2            HSEM_C1IER_ISE2_Msk       /*!< </spirit:description> */
#define HSEM_C1IER_ISE3_Pos        (3U)
#define HSEM_C1IER_ISE3_Msk        (0x1UL << HSEM_C1IER_ISE3_Pos)   /*!< 0x00000008 */
#define HSEM_C1IER_ISE3            HSEM_C1IER_ISE3_Msk       /*!< </spirit:description> */
#define HSEM_C1IER_ISE4_Pos        (4U)
#define HSEM_C1IER_ISE4_Msk        (0x1UL << HSEM_C1IER_ISE4_Pos)   /*!< 0x00000010 */
#define HSEM_C1IER_ISE4            HSEM_C1IER_ISE4_Msk       /*!< </spirit:description> */
#define HSEM_C1IER_ISE5_Pos        (5U)
#define HSEM_C1IER_ISE5_Msk        (0x1UL << HSEM_C1IER_ISE5_Pos)   /*!< 0x00000020 */
#define HSEM_C1IER_ISE5            HSEM_C1IER_ISE5_Msk       /*!< </spirit:description> */
#define HSEM_C1IER_ISE6_Pos        (6U)
#define HSEM_C1IER_ISE6_Msk        (0x1UL << HSEM_C1IER_ISE6_Pos)   /*!< 0x00000040 */
#define HSEM_C1IER_ISE6            HSEM_C1IER_ISE6_Msk       /*!< </spirit:description> */
#define HSEM_C1IER_ISE7_Pos        (7U)
#define HSEM_C1IER_ISE7_Msk        (0x1UL << HSEM_C1IER_ISE7_Pos)   /*!< 0x00000080 */
#define HSEM_C1IER_ISE7            HSEM_C1IER_ISE7_Msk       /*!< </spirit:description> */
#define HSEM_C1IER_ISE8_Pos        (8U)
#define HSEM_C1IER_ISE8_Msk        (0x1UL << HSEM_C1IER_ISE8_Pos)   /*!< 0x00000100 */
#define HSEM_C1IER_ISE8            HSEM_C1IER_ISE8_Msk       /*!< </spirit:description> */
#define HSEM_C1IER_ISE9_Pos        (9U)
#define HSEM_C1IER_ISE9_Msk        (0x1UL << HSEM_C1IER_ISE9_Pos)   /*!< 0x00000200 */
#define HSEM_C1IER_ISE9            HSEM_C1IER_ISE9_Msk       /*!< </spirit:description> */
#define HSEM_C1IER_ISE10_Pos       (10U)
#define HSEM_C1IER_ISE10_Msk       (0x1UL << HSEM_C1IER_ISE10_Pos)    /*!< 0x00000400 */
#define HSEM_C1IER_ISE10           HSEM_C1IER_ISE10_Msk      /*!< </spirit:description> */
#define HSEM_C1IER_ISE11_Pos       (11U)
#define HSEM_C1IER_ISE11_Msk       (0x1UL << HSEM_C1IER_ISE11_Pos)    /*!< 0x00000800 */
#define HSEM_C1IER_ISE11           HSEM_C1IER_ISE11_Msk      /*!< </spirit:description> */
#define HSEM_C1IER_ISE12_Pos       (12U)
#define HSEM_C1IER_ISE12_Msk       (0x1UL << HSEM_C1IER_ISE12_Pos)    /*!< 0x00001000 */
#define HSEM_C1IER_ISE12           HSEM_C1IER_ISE12_Msk      /*!< </spirit:description> */
#define HSEM_C1IER_ISE13_Pos       (13U)
#define HSEM_C1IER_ISE13_Msk       (0x1UL << HSEM_C1IER_ISE13_Pos)    /*!< 0x00002000 */
#define HSEM_C1IER_ISE13           HSEM_C1IER_ISE13_Msk      /*!< </spirit:description> */
#define HSEM_C1IER_ISE14_Pos       (14U)
#define HSEM_C1IER_ISE14_Msk       (0x1UL << HSEM_C1IER_ISE14_Pos)    /*!< 0x00004000 */
#define HSEM_C1IER_ISE14           HSEM_C1IER_ISE14_Msk      /*!< </spirit:description> */
#define HSEM_C1IER_ISE15_Pos       (15U)
#define HSEM_C1IER_ISE15_Msk       (0x1UL << HSEM_C1IER_ISE15_Pos)    /*!< 0x00008000 */
#define HSEM_C1IER_ISE15           HSEM_C1IER_ISE15_Msk      /*!< </spirit:description> */
#define HSEM_C1IER_ISE16_Pos       (16U)
#define HSEM_C1IER_ISE16_Msk       (0x1UL << HSEM_C1IER_ISE16_Pos)    /*!< 0x00010000 */
#define HSEM_C1IER_ISE16           HSEM_C1IER_ISE16_Msk      /*!< </spirit:description> */
#define HSEM_C1IER_ISE17_Pos       (17U)
#define HSEM_C1IER_ISE17_Msk       (0x1UL << HSEM_C1IER_ISE17_Pos)    /*!< 0x00020000 */
#define HSEM_C1IER_ISE17           HSEM_C1IER_ISE17_Msk      /*!< </spirit:description> */
#define HSEM_C1IER_ISE18_Pos       (18U)
#define HSEM_C1IER_ISE18_Msk       (0x1UL << HSEM_C1IER_ISE18_Pos)    /*!< 0x00040000 */
#define HSEM_C1IER_ISE18           HSEM_C1IER_ISE18_Msk      /*!< </spirit:description> */
#define HSEM_C1IER_ISE19_Pos       (19U)
#define HSEM_C1IER_ISE19_Msk       (0x1UL << HSEM_C1IER_ISE19_Pos)    /*!< 0x00080000 */
#define HSEM_C1IER_ISE19           HSEM_C1IER_ISE19_Msk      /*!< </spirit:description> */
#define HSEM_C1IER_ISE20_Pos       (20U)
#define HSEM_C1IER_ISE20_Msk       (0x1UL << HSEM_C1IER_ISE20_Pos)    /*!< 0x00100000 */
#define HSEM_C1IER_ISE20           HSEM_C1IER_ISE20_Msk      /*!< </spirit:description> */
#define HSEM_C1IER_ISE21_Pos       (21U)
#define HSEM_C1IER_ISE21_Msk       (0x1UL << HSEM_C1IER_ISE21_Pos)    /*!< 0x00200000 */
#define HSEM_C1IER_ISE21           HSEM_C1IER_ISE21_Msk      /*!< </spirit:description> */
#define HSEM_C1IER_ISE22_Pos       (22U)
#define HSEM_C1IER_ISE22_Msk       (0x1UL << HSEM_C1IER_ISE22_Pos)    /*!< 0x00400000 */
#define HSEM_C1IER_ISE22           HSEM_C1IER_ISE22_Msk      /*!< </spirit:description> */
#define HSEM_C1IER_ISE23_Pos       (23U)
#define HSEM_C1IER_ISE23_Msk       (0x1UL << HSEM_C1IER_ISE23_Pos)    /*!< 0x00800000 */
#define HSEM_C1IER_ISE23           HSEM_C1IER_ISE23_Msk      /*!< </spirit:description> */
#define HSEM_C1IER_ISE24_Pos       (24U)
#define HSEM_C1IER_ISE24_Msk       (0x1UL << HSEM_C1IER_ISE24_Pos)    /*!< 0x01000000 */
#define HSEM_C1IER_ISE24           HSEM_C1IER_ISE24_Msk      /*!< </spirit:description> */
#define HSEM_C1IER_ISE25_Pos       (25U)
#define HSEM_C1IER_ISE25_Msk       (0x1UL << HSEM_C1IER_ISE25_Pos)    /*!< 0x02000000 */
#define HSEM_C1IER_ISE25           HSEM_C1IER_ISE25_Msk      /*!< </spirit:description> */
#define HSEM_C1IER_ISE26_Pos       (26U)
#define HSEM_C1IER_ISE26_Msk       (0x1UL << HSEM_C1IER_ISE26_Pos)    /*!< 0x04000000 */
#define HSEM_C1IER_ISE26           HSEM_C1IER_ISE26_Msk      /*!< </spirit:description> */
#define HSEM_C1IER_ISE27_Pos       (27U)
#define HSEM_C1IER_ISE27_Msk       (0x1UL << HSEM_C1IER_ISE27_Pos)    /*!< 0x08000000 */
#define HSEM_C1IER_ISE27           HSEM_C1IER_ISE27_Msk      /*!< </spirit:description> */
#define HSEM_C1IER_ISE28_Pos       (28U)
#define HSEM_C1IER_ISE28_Msk       (0x1UL << HSEM_C1IER_ISE28_Pos)    /*!< 0x10000000 */
#define HSEM_C1IER_ISE28           HSEM_C1IER_ISE28_Msk      /*!< </spirit:description> */
#define HSEM_C1IER_ISE29_Pos       (29U)
#define HSEM_C1IER_ISE29_Msk       (0x1UL << HSEM_C1IER_ISE29_Pos)    /*!< 0x20000000 */
#define HSEM_C1IER_ISE29           HSEM_C1IER_ISE29_Msk      /*!< </spirit:description> */
#define HSEM_C1IER_ISE30_Pos       (30U)
#define HSEM_C1IER_ISE30_Msk       (0x1UL << HSEM_C1IER_ISE30_Pos)    /*!< 0x40000000 */
#define HSEM_C1IER_ISE30           HSEM_C1IER_ISE30_Msk      /*!< </spirit:description> */
#define HSEM_C1IER_ISE31_Pos       (31U)
#define HSEM_C1IER_ISE31_Msk       (0x1UL << HSEM_C1IER_ISE31_Pos)    /*!< 0x80000000 */
#define HSEM_C1IER_ISE31           HSEM_C1IER_ISE31_Msk      /*!< </spirit:description> */

/******************  Bit definition for HSEM_C1ICR register  ******************/
#define HSEM_C1ICR_ISC0_Pos        (0U)
#define HSEM_C1ICR_ISC0_Msk        (0x1UL << HSEM_C1ICR_ISC0_Pos)   /*!< 0x00000001 */
#define HSEM_C1ICR_ISC0            HSEM_C1ICR_ISC0_Msk       /*!< </spirit:description> */
#define HSEM_C1ICR_ISC1_Pos        (1U)
#define HSEM_C1ICR_ISC1_Msk        (0x1UL << HSEM_C1ICR_ISC1_Pos)   /*!< 0x00000002 */
#define HSEM_C1ICR_ISC1            HSEM_C1ICR_ISC1_Msk       /*!< </spirit:description> */
#define HSEM_C1ICR_ISC2_Pos        (2U)
#define HSEM_C1ICR_ISC2_Msk        (0x1UL << HSEM_C1ICR_ISC2_Pos)   /*!< 0x00000004 */
#define HSEM_C1ICR_ISC2            HSEM_C1ICR_ISC2_Msk       /*!< </spirit:description> */
#define HSEM_C1ICR_ISC3_Pos        (3U)
#define HSEM_C1ICR_ISC3_Msk        (0x1UL << HSEM_C1ICR_ISC3_Pos)   /*!< 0x00000008 */
#define HSEM_C1ICR_ISC3            HSEM_C1ICR_ISC3_Msk       /*!< </spirit:description> */
#define HSEM_C1ICR_ISC4_Pos        (4U)
#define HSEM_C1ICR_ISC4_Msk        (0x1UL << HSEM_C1ICR_ISC4_Pos)   /*!< 0x00000010 */
#define HSEM_C1ICR_ISC4            HSEM_C1ICR_ISC4_Msk       /*!< </spirit:description> */
#define HSEM_C1ICR_ISC5_Pos        (5U)
#define HSEM_C1ICR_ISC5_Msk        (0x1UL << HSEM_C1ICR_ISC5_Pos)   /*!< 0x00000020 */
#define HSEM_C1ICR_ISC5            HSEM_C1ICR_ISC5_Msk       /*!< </spirit:description> */
#define HSEM_C1ICR_ISC6_Pos        (6U)
#define HSEM_C1ICR_ISC6_Msk        (0x1UL << HSEM_C1ICR_ISC6_Pos)   /*!< 0x00000040 */
#define HSEM_C1ICR_ISC6            HSEM_C1ICR_ISC6_Msk       /*!< </spirit:description> */
#define HSEM_C1ICR_ISC7_Pos        (7U)
#define HSEM_C1ICR_ISC7_Msk        (0x1UL << HSEM_C1ICR_ISC7_Pos)   /*!< 0x00000080 */
#define HSEM_C1ICR_ISC7            HSEM_C1ICR_ISC7_Msk       /*!< </spirit:description> */
#define HSEM_C1ICR_ISC8_Pos        (8U)
#define HSEM_C1ICR_ISC8_Msk        (0x1UL << HSEM_C1ICR_ISC8_Pos)   /*!< 0x00000100 */
#define HSEM_C1ICR_ISC8            HSEM_C1ICR_ISC8_Msk       /*!< </spirit:description> */
#define HSEM_C1ICR_ISC9_Pos        (9U)
#define HSEM_C1ICR_ISC9_Msk        (0x1UL << HSEM_C1ICR_ISC9_Pos)   /*!< 0x00000200 */
#define HSEM_C1ICR_ISC9            HSEM_C1ICR_ISC9_Msk       /*!< </spirit:description> */
#define HSEM_C1ICR_ISC10_Pos       (10U)
#define HSEM_C1ICR_ISC10_Msk       (0x1UL << HSEM_C1ICR_ISC10_Pos)    /*!< 0x00000400 */
#define HSEM_C1ICR_ISC10           HSEM_C1ICR_ISC10_Msk      /*!< </spirit:description> */
#define HSEM_C1ICR_ISC11_Pos       (11U)
#define HSEM_C1ICR_ISC11_Msk       (0x1UL << HSEM_C1ICR_ISC11_Pos)    /*!< 0x00000800 */
#define HSEM_C1ICR_ISC11           HSEM_C1ICR_ISC11_Msk      /*!< </spirit:description> */
#define HSEM_C1ICR_ISC12_Pos       (12U)
#define HSEM_C1ICR_ISC12_Msk       (0x1UL << HSEM_C1ICR_ISC12_Pos)    /*!< 0x00001000 */
#define HSEM_C1ICR_ISC12           HSEM_C1ICR_ISC12_Msk      /*!< </spirit:description> */
#define HSEM_C1ICR_ISC13_Pos       (13U)
#define HSEM_C1ICR_ISC13_Msk       (0x1UL << HSEM_C1ICR_ISC13_Pos)    /*!< 0x00002000 */
#define HSEM_C1ICR_ISC13           HSEM_C1ICR_ISC13_Msk      /*!< </spirit:description> */
#define HSEM_C1ICR_ISC14_Pos       (14U)
#define HSEM_C1ICR_ISC14_Msk       (0x1UL << HSEM_C1ICR_ISC14_Pos)    /*!< 0x00004000 */
#define HSEM_C1ICR_ISC14           HSEM_C1ICR_ISC14_Msk      /*!< </spirit:description> */
#define HSEM_C1ICR_ISC15_Pos       (15U)
#define HSEM_C1ICR_ISC15_Msk       (0x1UL << HSEM_C1ICR_ISC15_Pos)    /*!< 0x00008000 */
#define HSEM_C1ICR_ISC15           HSEM_C1ICR_ISC15_Msk      /*!< </spirit:description> */
#define HSEM_C1ICR_ISC16_Pos       (16U)
#define HSEM_C1ICR_ISC16_Msk       (0x1UL << HSEM_C1ICR_ISC16_Pos)    /*!< 0x00010000 */
#define HSEM_C1ICR_ISC16           HSEM_C1ICR_ISC16_Msk      /*!< </spirit:description> */
#define HSEM_C1ICR_ISC17_Pos       (17U)
#define HSEM_C1ICR_ISC17_Msk       (0x1UL << HSEM_C1ICR_ISC17_Pos)    /*!< 0x00020000 */
#define HSEM_C1ICR_ISC17           HSEM_C1ICR_ISC17_Msk      /*!< </spirit:description> */
#define HSEM_C1ICR_ISC18_Pos       (18U)
#define HSEM_C1ICR_ISC18_Msk       (0x1UL << HSEM_C1ICR_ISC18_Pos)    /*!< 0x00040000 */
#define HSEM_C1ICR_ISC18           HSEM_C1ICR_ISC18_Msk      /*!< </spirit:description> */
#define HSEM_C1ICR_ISC19_Pos       (19U)
#define HSEM_C1ICR_ISC19_Msk       (0x1UL << HSEM_C1ICR_ISC19_Pos)    /*!< 0x00080000 */
#define HSEM_C1ICR_ISC19           HSEM_C1ICR_ISC19_Msk      /*!< </spirit:description> */
#define HSEM_C1ICR_ISC20_Pos       (20U)
#define HSEM_C1ICR_ISC20_Msk       (0x1UL << HSEM_C1ICR_ISC20_Pos)    /*!< 0x00100000 */
#define HSEM_C1ICR_ISC20           HSEM_C1ICR_ISC20_Msk      /*!< </spirit:description> */
#define HSEM_C1ICR_ISC21_Pos       (21U)
#define HSEM_C1ICR_ISC21_Msk       (0x1UL << HSEM_C1ICR_ISC21_Pos)    /*!< 0x00200000 */
#define HSEM_C1ICR_ISC21           HSEM_C1ICR_ISC21_Msk      /*!< </spirit:description> */
#define HSEM_C1ICR_ISC22_Pos       (22U)
#define HSEM_C1ICR_ISC22_Msk       (0x1UL << HSEM_C1ICR_ISC22_Pos)    /*!< 0x00400000 */
#define HSEM_C1ICR_ISC22           HSEM_C1ICR_ISC22_Msk      /*!< </spirit:description> */
#define HSEM_C1ICR_ISC23_Pos       (23U)
#define HSEM_C1ICR_ISC23_Msk       (0x1UL << HSEM_C1ICR_ISC23_Pos)    /*!< 0x00800000 */
#define HSEM_C1ICR_ISC23           HSEM_C1ICR_ISC23_Msk      /*!< </spirit:description> */
#define HSEM_C1ICR_ISC24_Pos       (24U)
#define HSEM_C1ICR_ISC24_Msk       (0x1UL << HSEM_C1ICR_ISC24_Pos)    /*!< 0x01000000 */
#define HSEM_C1ICR_ISC24           HSEM_C1ICR_ISC24_Msk      /*!< </spirit:description> */
#define HSEM_C1ICR_ISC25_Pos       (25U)
#define HSEM_C1ICR_ISC25_Msk       (0x1UL << HSEM_C1ICR_ISC25_Pos)    /*!< 0x02000000 */
#define HSEM_C1ICR_ISC25           HSEM_C1ICR_ISC25_Msk      /*!< </spirit:description> */
#define HSEM_C1ICR_ISC26_Pos       (26U)
#define HSEM_C1ICR_ISC26_Msk       (0x1UL << HSEM_C1ICR_ISC26_Pos)    /*!< 0x04000000 */
#define HSEM_C1ICR_ISC26           HSEM_C1ICR_ISC26_Msk      /*!< </spirit:description> */
#define HSEM_C1ICR_ISC27_Pos       (27U)
#define HSEM_C1ICR_ISC27_Msk       (0x1UL << HSEM_C1ICR_ISC27_Pos)    /*!< 0x08000000 */
#define HSEM_C1ICR_ISC27           HSEM_C1ICR_ISC27_Msk      /*!< </spirit:description> */
#define HSEM_C1ICR_ISC28_Pos       (28U)
#define HSEM_C1ICR_ISC28_Msk       (0x1UL << HSEM_C1ICR_ISC28_Pos)    /*!< 0x10000000 */
#define HSEM_C1ICR_ISC28           HSEM_C1ICR_ISC28_Msk      /*!< </spirit:description> */
#define HSEM_C1ICR_ISC29_Pos       (29U)
#define HSEM_C1ICR_ISC29_Msk       (0x1UL << HSEM_C1ICR_ISC29_Pos)    /*!< 0x20000000 */
#define HSEM_C1ICR_ISC29           HSEM_C1ICR_ISC29_Msk      /*!< </spirit:description> */
#define HSEM_C1ICR_ISC30_Pos       (30U)
#define HSEM_C1ICR_ISC30_Msk       (0x1UL << HSEM_C1ICR_ISC30_Pos)    /*!< 0x40000000 */
#define HSEM_C1ICR_ISC30           HSEM_C1ICR_ISC30_Msk      /*!< </spirit:description> */
#define HSEM_C1ICR_ISC31_Pos       (31U)
#define HSEM_C1ICR_ISC31_Msk       (0x1UL << HSEM_C1ICR_ISC31_Pos)    /*!< 0x80000000 */
#define HSEM_C1ICR_ISC31           HSEM_C1ICR_ISC31_Msk      /*!< </spirit:description> */

/******************  Bit definition for HSEM_C1ISR register  ******************/
#define HSEM_C1ISR_ISF0_Pos        (0U)
#define HSEM_C1ISR_ISF0_Msk        (0x1UL << HSEM_C1ISR_ISF0_Pos)   /*!< 0x00000001 */
#define HSEM_C1ISR_ISF0            HSEM_C1ISR_ISF0_Msk       /*!< </spirit:description> */
#define HSEM_C1ISR_ISF1_Pos        (1U)
#define HSEM_C1ISR_ISF1_Msk        (0x1UL << HSEM_C1ISR_ISF1_Pos)   /*!< 0x00000002 */
#define HSEM_C1ISR_ISF1            HSEM_C1ISR_ISF1_Msk       /*!< </spirit:description> */
#define HSEM_C1ISR_ISF2_Pos        (2U)
#define HSEM_C1ISR_ISF2_Msk        (0x1UL << HSEM_C1ISR_ISF2_Pos)   /*!< 0x00000004 */
#define HSEM_C1ISR_ISF2            HSEM_C1ISR_ISF2_Msk       /*!< </spirit:description> */
#define HSEM_C1ISR_ISF3_Pos        (3U)
#define HSEM_C1ISR_ISF3_Msk        (0x1UL << HSEM_C1ISR_ISF3_Pos)   /*!< 0x00000008 */
#define HSEM_C1ISR_ISF3            HSEM_C1ISR_ISF3_Msk       /*!< </spirit:description> */
#define HSEM_C1ISR_ISF4_Pos        (4U)
#define HSEM_C1ISR_ISF4_Msk        (0x1UL << HSEM_C1ISR_ISF4_Pos)   /*!< 0x00000010 */
#define HSEM_C1ISR_ISF4            HSEM_C1ISR_ISF4_Msk       /*!< </spirit:description> */
#define HSEM_C1ISR_ISF5_Pos        (5U)
#define HSEM_C1ISR_ISF5_Msk        (0x1UL << HSEM_C1ISR_ISF5_Pos)   /*!< 0x00000020 */
#define HSEM_C1ISR_ISF5            HSEM_C1ISR_ISF5_Msk       /*!< </spirit:description> */
#define HSEM_C1ISR_ISF6_Pos        (6U)
#define HSEM_C1ISR_ISF6_Msk        (0x1UL << HSEM_C1ISR_ISF6_Pos)   /*!< 0x00000040 */
#define HSEM_C1ISR_ISF6            HSEM_C1ISR_ISF6_Msk       /*!< </spirit:description> */
#define HSEM_C1ISR_ISF7_Pos        (7U)
#define HSEM_C1ISR_ISF7_Msk        (0x1UL << HSEM_C1ISR_ISF7_Pos)   /*!< 0x00000080 */
#define HSEM_C1ISR_ISF7            HSEM_C1ISR_ISF7_Msk       /*!< </spirit:description> */
#define HSEM_C1ISR_ISF8_Pos        (8U)
#define HSEM_C1ISR_ISF8_Msk        (0x1UL << HSEM_C1ISR_ISF8_Pos)   /*!< 0x00000100 */
#define HSEM_C1ISR_ISF8            HSEM_C1ISR_ISF8_Msk       /*!< </spirit:description> */
#define HSEM_C1ISR_ISF9_Pos        (9U)
#define HSEM_C1ISR_ISF9_Msk        (0x1UL << HSEM_C1ISR_ISF9_Pos)   /*!< 0x00000200 */
#define HSEM_C1ISR_ISF9            HSEM_C1ISR_ISF9_Msk       /*!< </spirit:description> */
#define HSEM_C1ISR_ISF10_Pos       (10U)
#define HSEM_C1ISR_ISF10_Msk       (0x1UL << HSEM_C1ISR_ISF10_Pos)    /*!< 0x00000400 */
#define HSEM_C1ISR_ISF10           HSEM_C1ISR_ISF10_Msk      /*!< </spirit:description> */
#define HSEM_C1ISR_ISF11_Pos       (11U)
#define HSEM_C1ISR_ISF11_Msk       (0x1UL << HSEM_C1ISR_ISF11_Pos)    /*!< 0x00000800 */
#define HSEM_C1ISR_ISF11           HSEM_C1ISR_ISF11_Msk      /*!< </spirit:description> */
#define HSEM_C1ISR_ISF12_Pos       (12U)
#define HSEM_C1ISR_ISF12_Msk       (0x1UL << HSEM_C1ISR_ISF12_Pos)    /*!< 0x00001000 */
#define HSEM_C1ISR_ISF12           HSEM_C1ISR_ISF12_Msk      /*!< </spirit:description> */
#define HSEM_C1ISR_ISF13_Pos       (13U)
#define HSEM_C1ISR_ISF13_Msk       (0x1UL << HSEM_C1ISR_ISF13_Pos)    /*!< 0x00002000 */
#define HSEM_C1ISR_ISF13           HSEM_C1ISR_ISF13_Msk      /*!< </spirit:description> */
#define HSEM_C1ISR_ISF14_Pos       (14U)
#define HSEM_C1ISR_ISF14_Msk       (0x1UL << HSEM_C1ISR_ISF14_Pos)    /*!< 0x00004000 */
#define HSEM_C1ISR_ISF14           HSEM_C1ISR_ISF14_Msk      /*!< </spirit:description> */
#define HSEM_C1ISR_ISF15_Pos       (15U)
#define HSEM_C1ISR_ISF15_Msk       (0x1UL << HSEM_C1ISR_ISF15_Pos)    /*!< 0x00008000 */
#define HSEM_C1ISR_ISF15           HSEM_C1ISR_ISF15_Msk      /*!< </spirit:description> */
#define HSEM_C1ISR_ISF16_Pos       (16U)
#define HSEM_C1ISR_ISF16_Msk       (0x1UL << HSEM_C1ISR_ISF16_Pos)    /*!< 0x00010000 */
#define HSEM_C1ISR_ISF16           HSEM_C1ISR_ISF16_Msk      /*!< </spirit:description> */
#define HSEM_C1ISR_ISF17_Pos       (17U)
#define HSEM_C1ISR_ISF17_Msk       (0x1UL << HSEM_C1ISR_ISF17_Pos)    /*!< 0x00020000 */
#define HSEM_C1ISR_ISF17           HSEM_C1ISR_ISF17_Msk      /*!< </spirit:description> */
#define HSEM_C1ISR_ISF18_Pos       (18U)
#define HSEM_C1ISR_ISF18_Msk       (0x1UL << HSEM_C1ISR_ISF18_Pos)    /*!< 0x00040000 */
#define HSEM_C1ISR_ISF18           HSEM_C1ISR_ISF18_Msk      /*!< </spirit:description> */
#define HSEM_C1ISR_ISF19_Pos       (19U)
#define HSEM_C1ISR_ISF19_Msk       (0x1UL << HSEM_C1ISR_ISF19_Pos)    /*!< 0x00080000 */
#define HSEM_C1ISR_ISF19           HSEM_C1ISR_ISF19_Msk      /*!< </spirit:description> */
#define HSEM_C1ISR_ISF20_Pos       (20U)
#define HSEM_C1ISR_ISF20_Msk       (0x1UL << HSEM_C1ISR_ISF20_Pos)    /*!< 0x00100000 */
#define HSEM_C1ISR_ISF20           HSEM_C1ISR_ISF20_Msk      /*!< </spirit:description> */
#define HSEM_C1ISR_ISF21_Pos       (21U)
#define HSEM_C1ISR_ISF21_Msk       (0x1UL << HSEM_C1ISR_ISF21_Pos)    /*!< 0x00200000 */
#define HSEM_C1ISR_ISF21           HSEM_C1ISR_ISF21_Msk      /*!< </spirit:description> */
#define HSEM_C1ISR_ISF22_Pos       (22U)
#define HSEM_C1ISR_ISF22_Msk       (0x1UL << HSEM_C1ISR_ISF22_Pos)    /*!< 0x00400000 */
#define HSEM_C1ISR_ISF22           HSEM_C1ISR_ISF22_Msk      /*!< </spirit:description> */
#define HSEM_C1ISR_ISF23_Pos       (23U)
#define HSEM_C1ISR_ISF23_Msk       (0x1UL << HSEM_C1ISR_ISF23_Pos)    /*!< 0x00800000 */
#define HSEM_C1ISR_ISF23           HSEM_C1ISR_ISF23_Msk      /*!< </spirit:description> */
#define HSEM_C1ISR_ISF24_Pos       (24U)
#define HSEM_C1ISR_ISF24_Msk       (0x1UL << HSEM_C1ISR_ISF24_Pos)    /*!< 0x01000000 */
#define HSEM_C1ISR_ISF24           HSEM_C1ISR_ISF24_Msk      /*!< </spirit:description> */
#define HSEM_C1ISR_ISF25_Pos       (25U)
#define HSEM_C1ISR_ISF25_Msk       (0x1UL << HSEM_C1ISR_ISF25_Pos)    /*!< 0x02000000 */
#define HSEM_C1ISR_ISF25           HSEM_C1ISR_ISF25_Msk      /*!< </spirit:description> */
#define HSEM_C1ISR_ISF26_Pos       (26U)
#define HSEM_C1ISR_ISF26_Msk       (0x1UL << HSEM_C1ISR_ISF26_Pos)    /*!< 0x04000000 */
#define HSEM_C1ISR_ISF26           HSEM_C1ISR_ISF26_Msk      /*!< </spirit:description> */
#define HSEM_C1ISR_ISF27_Pos       (27U)
#define HSEM_C1ISR_ISF27_Msk       (0x1UL << HSEM_C1ISR_ISF27_Pos)    /*!< 0x08000000 */
#define HSEM_C1ISR_ISF27           HSEM_C1ISR_ISF27_Msk      /*!< </spirit:description> */
#define HSEM_C1ISR_ISF28_Pos       (28U)
#define HSEM_C1ISR_ISF28_Msk       (0x1UL << HSEM_C1ISR_ISF28_Pos)    /*!< 0x10000000 */
#define HSEM_C1ISR_ISF28           HSEM_C1ISR_ISF28_Msk      /*!< </spirit:description> */
#define HSEM_C1ISR_ISF29_Pos       (29U)
#define HSEM_C1ISR_ISF29_Msk       (0x1UL << HSEM_C1ISR_ISF29_Pos)    /*!< 0x20000000 */
#define HSEM_C1ISR_ISF29           HSEM_C1ISR_ISF29_Msk      /*!< </spirit:description> */
#define HSEM_C1ISR_ISF30_Pos       (30U)
#define HSEM_C1ISR_ISF30_Msk       (0x1UL << HSEM_C1ISR_ISF30_Pos)    /*!< 0x40000000 */
#define HSEM_C1ISR_ISF30           HSEM_C1ISR_ISF30_Msk      /*!< </spirit:description> */
#define HSEM_C1ISR_ISF31_Pos       (31U)
#define HSEM_C1ISR_ISF31_Msk       (0x1UL << HSEM_C1ISR_ISF31_Pos)    /*!< 0x80000000 */
#define HSEM_C1ISR_ISF31           HSEM_C1ISR_ISF31_Msk      /*!< </spirit:description> */

/*****************  Bit definition for HSEM_C1MISR register  ******************/
#define HSEM_C1MISR_MISF0_Pos      (0U)
#define HSEM_C1MISR_MISF0_Msk      (0x1UL << HSEM_C1MISR_MISF0_Pos)     /*!< 0x00000001 */
#define HSEM_C1MISR_MISF0          HSEM_C1MISR_MISF0_Msk     /*!< </spirit:description> */
#define HSEM_C1MISR_MISF1_Pos      (1U)
#define HSEM_C1MISR_MISF1_Msk      (0x1UL << HSEM_C1MISR_MISF1_Pos)     /*!< 0x00000002 */
#define HSEM_C1MISR_MISF1          HSEM_C1MISR_MISF1_Msk     /*!< </spirit:description> */
#define HSEM_C1MISR_MISF2_Pos      (2U)
#define HSEM_C1MISR_MISF2_Msk      (0x1UL << HSEM_C1MISR_MISF2_Pos)     /*!< 0x00000004 */
#define HSEM_C1MISR_MISF2          HSEM_C1MISR_MISF2_Msk     /*!< </spirit:description> */
#define HSEM_C1MISR_MISF3_Pos      (3U)
#define HSEM_C1MISR_MISF3_Msk      (0x1UL << HSEM_C1MISR_MISF3_Pos)     /*!< 0x00000008 */
#define HSEM_C1MISR_MISF3          HSEM_C1MISR_MISF3_Msk     /*!< </spirit:description> */
#define HSEM_C1MISR_MISF4_Pos      (4U)
#define HSEM_C1MISR_MISF4_Msk      (0x1UL << HSEM_C1MISR_MISF4_Pos)     /*!< 0x00000010 */
#define HSEM_C1MISR_MISF4          HSEM_C1MISR_MISF4_Msk     /*!< </spirit:description> */
#define HSEM_C1MISR_MISF5_Pos      (5U)
#define HSEM_C1MISR_MISF5_Msk      (0x1UL << HSEM_C1MISR_MISF5_Pos)     /*!< 0x00000020 */
#define HSEM_C1MISR_MISF5          HSEM_C1MISR_MISF5_Msk     /*!< </spirit:description> */
#define HSEM_C1MISR_MISF6_Pos      (6U)
#define HSEM_C1MISR_MISF6_Msk      (0x1UL << HSEM_C1MISR_MISF6_Pos)     /*!< 0x00000040 */
#define HSEM_C1MISR_MISF6          HSEM_C1MISR_MISF6_Msk     /*!< </spirit:description> */
#define HSEM_C1MISR_MISF7_Pos      (7U)
#define HSEM_C1MISR_MISF7_Msk      (0x1UL << HSEM_C1MISR_MISF7_Pos)     /*!< 0x00000080 */
#define HSEM_C1MISR_MISF7          HSEM_C1MISR_MISF7_Msk     /*!< </spirit:description> */
#define HSEM_C1MISR_MISF8_Pos      (8U)
#define HSEM_C1MISR_MISF8_Msk      (0x1UL << HSEM_C1MISR_MISF8_Pos)     /*!< 0x00000100 */
#define HSEM_C1MISR_MISF8          HSEM_C1MISR_MISF8_Msk     /*!< </spirit:description> */
#define HSEM_C1MISR_MISF9_Pos      (9U)
#define HSEM_C1MISR_MISF9_Msk      (0x1UL << HSEM_C1MISR_MISF9_Pos)     /*!< 0x00000200 */
#define HSEM_C1MISR_MISF9          HSEM_C1MISR_MISF9_Msk     /*!< </spirit:description> */
#define HSEM_C1MISR_MISF10_Pos     (10U)
#define HSEM_C1MISR_MISF10_Msk     (0x1UL << HSEM_C1MISR_MISF10_Pos)      /*!< 0x00000400 */
#define HSEM_C1MISR_MISF10         HSEM_C1MISR_MISF10_Msk    /*!< </spirit:description> */
#define HSEM_C1MISR_MISF11_Pos     (11U)
#define HSEM_C1MISR_MISF11_Msk     (0x1UL << HSEM_C1MISR_MISF11_Pos)      /*!< 0x00000800 */
#define HSEM_C1MISR_MISF11         HSEM_C1MISR_MISF11_Msk    /*!< </spirit:description> */
#define HSEM_C1MISR_MISF12_Pos     (12U)
#define HSEM_C1MISR_MISF12_Msk     (0x1UL << HSEM_C1MISR_MISF12_Pos)      /*!< 0x00001000 */
#define HSEM_C1MISR_MISF12         HSEM_C1MISR_MISF12_Msk    /*!< </spirit:description> */
#define HSEM_C1MISR_MISF13_Pos     (13U)
#define HSEM_C1MISR_MISF13_Msk     (0x1UL << HSEM_C1MISR_MISF13_Pos)      /*!< 0x00002000 */
#define HSEM_C1MISR_MISF13         HSEM_C1MISR_MISF13_Msk    /*!< </spirit:description> */
#define HSEM_C1MISR_MISF14_Pos     (14U)
#define HSEM_C1MISR_MISF14_Msk     (0x1UL << HSEM_C1MISR_MISF14_Pos)      /*!< 0x00004000 */
#define HSEM_C1MISR_MISF14         HSEM_C1MISR_MISF14_Msk    /*!< </spirit:description> */
#define HSEM_C1MISR_MISF15_Pos     (15U)
#define HSEM_C1MISR_MISF15_Msk     (0x1UL << HSEM_C1MISR_MISF15_Pos)      /*!< 0x00008000 */
#define HSEM_C1MISR_MISF15         HSEM_C1MISR_MISF15_Msk    /*!< </spirit:description> */
#define HSEM_C1MISR_MISF16_Pos     (16U)
#define HSEM_C1MISR_MISF16_Msk     (0x1UL << HSEM_C1MISR_MISF16_Pos)      /*!< 0x00010000 */
#define HSEM_C1MISR_MISF16         HSEM_C1MISR_MISF16_Msk    /*!< </spirit:description> */
#define HSEM_C1MISR_MISF17_Pos     (17U)
#define HSEM_C1MISR_MISF17_Msk     (0x1UL << HSEM_C1MISR_MISF17_Pos)      /*!< 0x00020000 */
#define HSEM_C1MISR_MISF17         HSEM_C1MISR_MISF17_Msk    /*!< </spirit:description> */
#define HSEM_C1MISR_MISF18_Pos     (18U)
#define HSEM_C1MISR_MISF18_Msk     (0x1UL << HSEM_C1MISR_MISF18_Pos)      /*!< 0x00040000 */
#define HSEM_C1MISR_MISF18         HSEM_C1MISR_MISF18_Msk    /*!< </spirit:description> */
#define HSEM_C1MISR_MISF19_Pos     (19U)
#define HSEM_C1MISR_MISF19_Msk     (0x1UL << HSEM_C1MISR_MISF19_Pos)      /*!< 0x00080000 */
#define HSEM_C1MISR_MISF19         HSEM_C1MISR_MISF19_Msk    /*!< </spirit:description> */
#define HSEM_C1MISR_MISF20_Pos     (20U)
#define HSEM_C1MISR_MISF20_Msk     (0x1UL << HSEM_C1MISR_MISF20_Pos)      /*!< 0x00100000 */
#define HSEM_C1MISR_MISF20         HSEM_C1MISR_MISF20_Msk    /*!< </spirit:description> */
#define HSEM_C1MISR_MISF21_Pos     (21U)
#define HSEM_C1MISR_MISF21_Msk     (0x1UL << HSEM_C1MISR_MISF21_Pos)      /*!< 0x00200000 */
#define HSEM_C1MISR_MISF21         HSEM_C1MISR_MISF21_Msk    /*!< </spirit:description> */
#define HSEM_C1MISR_MISF22_Pos     (22U)
#define HSEM_C1MISR_MISF22_Msk     (0x1UL << HSEM_C1MISR_MISF22_Pos)      /*!< 0x00400000 */
#define HSEM_C1MISR_MISF22         HSEM_C1MISR_MISF22_Msk    /*!< </spirit:description> */
#define HSEM_C1MISR_MISF23_Pos     (23U)
#define HSEM_C1MISR_MISF23_Msk     (0x1UL << HSEM_C1MISR_MISF23_Pos)      /*!< 0x00800000 */
#define HSEM_C1MISR_MISF23         HSEM_C1MISR_MISF23_Msk    /*!< </spirit:description> */
#define HSEM_C1MISR_MISF24_Pos     (24U)
#define HSEM_C1MISR_MISF24_Msk     (0x1UL << HSEM_C1MISR_MISF24_Pos)      /*!< 0x01000000 */
#define HSEM_C1MISR_MISF24         HSEM_C1MISR_MISF24_Msk    /*!< </spirit:description> */
#define HSEM_C1MISR_MISF25_Pos     (25U)
#define HSEM_C1MISR_MISF25_Msk     (0x1UL << HSEM_C1MISR_MISF25_Pos)      /*!< 0x02000000 */
#define HSEM_C1MISR_MISF25         HSEM_C1MISR_MISF25_Msk    /*!< </spirit:description> */
#define HSEM_C1MISR_MISF26_Pos     (26U)
#define HSEM_C1MISR_MISF26_Msk     (0x1UL << HSEM_C1MISR_MISF26_Pos)      /*!< 0x04000000 */
#define HSEM_C1MISR_MISF26         HSEM_C1MISR_MISF26_Msk    /*!< </spirit:description> */
#define HSEM_C1MISR_MISF27_Pos     (27U)
#define HSEM_C1MISR_MISF27_Msk     (0x1UL << HSEM_C1MISR_MISF27_Pos)      /*!< 0x08000000 */
#define HSEM_C1MISR_MISF27         HSEM_C1MISR_MISF27_Msk    /*!< </spirit:description> */
#define HSEM_C1MISR_MISF28_Pos     (28U)
#define HSEM_C1MISR_MISF28_Msk     (0x1UL << HSEM_C1MISR_MISF28_Pos)      /*!< 0x10000000 */
#define HSEM_C1MISR_MISF28         HSEM_C1MISR_MISF28_Msk    /*!< </spirit:description> */
#define HSEM_C1MISR_MISF29_Pos     (29U)
#define HSEM_C1MISR_MISF29_Msk     (0x1UL << HSEM_C1MISR_MISF29_Pos)      /*!< 0x20000000 */
#define HSEM_C1MISR_MISF29         HSEM_C1MISR_MISF29_Msk    /*!< </spirit:description> */
#define HSEM_C1MISR_MISF30_Pos     (30U)
#define HSEM_C1MISR_MISF30_Msk     (0x1UL << HSEM_C1MISR_MISF30_Pos)      /*!< 0x40000000 */
#define HSEM_C1MISR_MISF30         HSEM_C1MISR_MISF30_Msk    /*!< </spirit:description> */
#define HSEM_C1MISR_MISF31_Pos     (31U)
#define HSEM_C1MISR_MISF31_Msk     (0x1UL << HSEM_C1MISR_MISF31_Pos)      /*!< 0x80000000 */
#define HSEM_C1MISR_MISF31         HSEM_C1MISR_MISF31_Msk    /*!< </spirit:description> */

/******************  Bit definition for HSEM_C2IER register  ******************/
#define HSEM_C2IER_ISE0_Pos        (0U)
#define HSEM_C2IER_ISE0_Msk        (0x1UL << HSEM_C2IER_ISE0_Pos)   /*!< 0x00000001 */
#define HSEM_C2IER_ISE0            HSEM_C2IER_ISE0_Msk       /*!< </spirit:description> */
#define HSEM_C2IER_ISE1_Pos        (1U)
#define HSEM_C2IER_ISE1_Msk        (0x1UL << HSEM_C2IER_ISE1_Pos)   /*!< 0x00000002 */
#define HSEM_C2IER_ISE1            HSEM_C2IER_ISE1_Msk       /*!< </spirit:description> */
#define HSEM_C2IER_ISE2_Pos        (2U)
#define HSEM_C2IER_ISE2_Msk        (0x1UL << HSEM_C2IER_ISE2_Pos)   /*!< 0x00000004 */
#define HSEM_C2IER_ISE2            HSEM_C2IER_ISE2_Msk       /*!< </spirit:description> */
#define HSEM_C2IER_ISE3_Pos        (3U)
#define HSEM_C2IER_ISE3_Msk        (0x1UL << HSEM_C2IER_ISE3_Pos)   /*!< 0x00000008 */
#define HSEM_C2IER_ISE3            HSEM_C2IER_ISE3_Msk       /*!< </spirit:description> */
#define HSEM_C2IER_ISE4_Pos        (4U)
#define HSEM_C2IER_ISE4_Msk        (0x1UL << HSEM_C2IER_ISE4_Pos)   /*!< 0x00000010 */
#define HSEM_C2IER_ISE4            HSEM_C2IER_ISE4_Msk       /*!< </spirit:description> */
#define HSEM_C2IER_ISE5_Pos        (5U)
#define HSEM_C2IER_ISE5_Msk        (0x1UL << HSEM_C2IER_ISE5_Pos)   /*!< 0x00000020 */
#define HSEM_C2IER_ISE5            HSEM_C2IER_ISE5_Msk       /*!< </spirit:description> */
#define HSEM_C2IER_ISE6_Pos        (6U)
#define HSEM_C2IER_ISE6_Msk        (0x1UL << HSEM_C2IER_ISE6_Pos)   /*!< 0x00000040 */
#define HSEM_C2IER_ISE6            HSEM_C2IER_ISE6_Msk       /*!< </spirit:description> */
#define HSEM_C2IER_ISE7_Pos        (7U)
#define HSEM_C2IER_ISE7_Msk        (0x1UL << HSEM_C2IER_ISE7_Pos)   /*!< 0x00000080 */
#define HSEM_C2IER_ISE7            HSEM_C2IER_ISE7_Msk       /*!< </spirit:description> */
#define HSEM_C2IER_ISE8_Pos        (8U)
#define HSEM_C2IER_ISE8_Msk        (0x1UL << HSEM_C2IER_ISE8_Pos)   /*!< 0x00000100 */
#define HSEM_C2IER_ISE8            HSEM_C2IER_ISE8_Msk       /*!< </spirit:description> */
#define HSEM_C2IER_ISE9_Pos        (9U)
#define HSEM_C2IER_ISE9_Msk        (0x1UL << HSEM_C2IER_ISE9_Pos)   /*!< 0x00000200 */
#define HSEM_C2IER_ISE9            HSEM_C2IER_ISE9_Msk       /*!< </spirit:description> */
#define HSEM_C2IER_ISE10_Pos       (10U)
#define HSEM_C2IER_ISE10_Msk       (0x1UL << HSEM_C2IER_ISE10_Pos)    /*!< 0x00000400 */
#define HSEM_C2IER_ISE10           HSEM_C2IER_ISE10_Msk      /*!< </spirit:description> */
#define HSEM_C2IER_ISE11_Pos       (11U)
#define HSEM_C2IER_ISE11_Msk       (0x1UL << HSEM_C2IER_ISE11_Pos)    /*!< 0x00000800 */
#define HSEM_C2IER_ISE11           HSEM_C2IER_ISE11_Msk      /*!< </spirit:description> */
#define HSEM_C2IER_ISE12_Pos       (12U)
#define HSEM_C2IER_ISE12_Msk       (0x1UL << HSEM_C2IER_ISE12_Pos)    /*!< 0x00001000 */
#define HSEM_C2IER_ISE12           HSEM_C2IER_ISE12_Msk      /*!< </spirit:description> */
#define HSEM_C2IER_ISE13_Pos       (13U)
#define HSEM_C2IER_ISE13_Msk       (0x1UL << HSEM_C2IER_ISE13_Pos)    /*!< 0x00002000 */
#define HSEM_C2IER_ISE13           HSEM_C2IER_ISE13_Msk      /*!< </spirit:description> */
#define HSEM_C2IER_ISE14_Pos       (14U)
#define HSEM_C2IER_ISE14_Msk       (0x1UL << HSEM_C2IER_ISE14_Pos)    /*!< 0x00004000 */
#define HSEM_C2IER_ISE14           HSEM_C2IER_ISE14_Msk      /*!< </spirit:description> */
#define HSEM_C2IER_ISE15_Pos       (15U)
#define HSEM_C2IER_ISE15_Msk       (0x1UL << HSEM_C2IER_ISE15_Pos)    /*!< 0x00008000 */
#define HSEM_C2IER_ISE15           HSEM_C2IER_ISE15_Msk      /*!< </spirit:description> */
#define HSEM_C2IER_ISE16_Pos       (16U)
#define HSEM_C2IER_ISE16_Msk       (0x1UL << HSEM_C2IER_ISE16_Pos)    /*!< 0x00010000 */
#define HSEM_C2IER_ISE16           HSEM_C2IER_ISE16_Msk      /*!< </spirit:description> */
#define HSEM_C2IER_ISE17_Pos       (17U)
#define HSEM_C2IER_ISE17_Msk       (0x1UL << HSEM_C2IER_ISE17_Pos)    /*!< 0x00020000 */
#define HSEM_C2IER_ISE17           HSEM_C2IER_ISE17_Msk      /*!< </spirit:description> */
#define HSEM_C2IER_ISE18_Pos       (18U)
#define HSEM_C2IER_ISE18_Msk       (0x1UL << HSEM_C2IER_ISE18_Pos)    /*!< 0x00040000 */
#define HSEM_C2IER_ISE18           HSEM_C2IER_ISE18_Msk      /*!< </spirit:description> */
#define HSEM_C2IER_ISE19_Pos       (19U)
#define HSEM_C2IER_ISE19_Msk       (0x1UL << HSEM_C2IER_ISE19_Pos)    /*!< 0x00080000 */
#define HSEM_C2IER_ISE19           HSEM_C2IER_ISE19_Msk      /*!< </spirit:description> */
#define HSEM_C2IER_ISE20_Pos       (20U)
#define HSEM_C2IER_ISE20_Msk       (0x1UL << HSEM_C2IER_ISE20_Pos)    /*!< 0x00100000 */
#define HSEM_C2IER_ISE20           HSEM_C2IER_ISE20_Msk      /*!< </spirit:description> */
#define HSEM_C2IER_ISE21_Pos       (21U)
#define HSEM_C2IER_ISE21_Msk       (0x1UL << HSEM_C2IER_ISE21_Pos)    /*!< 0x00200000 */
#define HSEM_C2IER_ISE21           HSEM_C2IER_ISE21_Msk      /*!< </spirit:description> */
#define HSEM_C2IER_ISE22_Pos       (22U)
#define HSEM_C2IER_ISE22_Msk       (0x1UL << HSEM_C2IER_ISE22_Pos)    /*!< 0x00400000 */
#define HSEM_C2IER_ISE22           HSEM_C2IER_ISE22_Msk      /*!< </spirit:description> */
#define HSEM_C2IER_ISE23_Pos       (23U)
#define HSEM_C2IER_ISE23_Msk       (0x1UL << HSEM_C2IER_ISE23_Pos)    /*!< 0x00800000 */
#define HSEM_C2IER_ISE23           HSEM_C2IER_ISE23_Msk      /*!< </spirit:description> */
#define HSEM_C2IER_ISE24_Pos       (24U)
#define HSEM_C2IER_ISE24_Msk       (0x1UL << HSEM_C2IER_ISE24_Pos)    /*!< 0x01000000 */
#define HSEM_C2IER_ISE24           HSEM_C2IER_ISE24_Msk      /*!< </spirit:description> */
#define HSEM_C2IER_ISE25_Pos       (25U)
#define HSEM_C2IER_ISE25_Msk       (0x1UL << HSEM_C2IER_ISE25_Pos)    /*!< 0x02000000 */
#define HSEM_C2IER_ISE25           HSEM_C2IER_ISE25_Msk      /*!< </spirit:description> */
#define HSEM_C2IER_ISE26_Pos       (26U)
#define HSEM_C2IER_ISE26_Msk       (0x1UL << HSEM_C2IER_ISE26_Pos)    /*!< 0x04000000 */
#define HSEM_C2IER_ISE26           HSEM_C2IER_ISE26_Msk      /*!< </spirit:description> */
#define HSEM_C2IER_ISE27_Pos       (27U)
#define HSEM_C2IER_ISE27_Msk       (0x1UL << HSEM_C2IER_ISE27_Pos)    /*!< 0x08000000 */
#define HSEM_C2IER_ISE27           HSEM_C2IER_ISE27_Msk      /*!< </spirit:description> */
#define HSEM_C2IER_ISE28_Pos       (28U)
#define HSEM_C2IER_ISE28_Msk       (0x1UL << HSEM_C2IER_ISE28_Pos)    /*!< 0x10000000 */
#define HSEM_C2IER_ISE28           HSEM_C2IER_ISE28_Msk      /*!< </spirit:description> */
#define HSEM_C2IER_ISE29_Pos       (29U)
#define HSEM_C2IER_ISE29_Msk       (0x1UL << HSEM_C2IER_ISE29_Pos)    /*!< 0x20000000 */
#define HSEM_C2IER_ISE29           HSEM_C2IER_ISE29_Msk      /*!< </spirit:description> */
#define HSEM_C2IER_ISE30_Pos       (30U)
#define HSEM_C2IER_ISE30_Msk       (0x1UL << HSEM_C2IER_ISE30_Pos)    /*!< 0x40000000 */
#define HSEM_C2IER_ISE30           HSEM_C2IER_ISE30_Msk      /*!< </spirit:description> */
#define HSEM_C2IER_ISE31_Pos       (31U)
#define HSEM_C2IER_ISE31_Msk       (0x1UL << HSEM_C2IER_ISE31_Pos)    /*!< 0x80000000 */
#define HSEM_C2IER_ISE31           HSEM_C2IER_ISE31_Msk      /*!< </spirit:description> */

/******************  Bit definition for HSEM_C2ICR register  ******************/
#define HSEM_C2ICR_ISC0_Pos        (0U)
#define HSEM_C2ICR_ISC0_Msk        (0x1UL << HSEM_C2ICR_ISC0_Pos)   /*!< 0x00000001 */
#define HSEM_C2ICR_ISC0            HSEM_C2ICR_ISC0_Msk       /*!< </spirit:description> */
#define HSEM_C2ICR_ISC1_Pos        (1U)
#define HSEM_C2ICR_ISC1_Msk        (0x1UL << HSEM_C2ICR_ISC1_Pos)   /*!< 0x00000002 */
#define HSEM_C2ICR_ISC1            HSEM_C2ICR_ISC1_Msk       /*!< </spirit:description> */
#define HSEM_C2ICR_ISC2_Pos        (2U)
#define HSEM_C2ICR_ISC2_Msk        (0x1UL << HSEM_C2ICR_ISC2_Pos)   /*!< 0x00000004 */
#define HSEM_C2ICR_ISC2            HSEM_C2ICR_ISC2_Msk       /*!< </spirit:description> */
#define HSEM_C2ICR_ISC3_Pos        (3U)
#define HSEM_C2ICR_ISC3_Msk        (0x1UL << HSEM_C2ICR_ISC3_Pos)   /*!< 0x00000008 */
#define HSEM_C2ICR_ISC3            HSEM_C2ICR_ISC3_Msk       /*!< </spirit:description> */
#define HSEM_C2ICR_ISC4_Pos        (4U)
#define HSEM_C2ICR_ISC4_Msk        (0x1UL << HSEM_C2ICR_ISC4_Pos)   /*!< 0x00000010 */
#define HSEM_C2ICR_ISC4            HSEM_C2ICR_ISC4_Msk       /*!< </spirit:description> */
#define HSEM_C2ICR_ISC5_Pos        (5U)
#define HSEM_C2ICR_ISC5_Msk        (0x1UL << HSEM_C2ICR_ISC5_Pos)   /*!< 0x00000020 */
#define HSEM_C2ICR_ISC5            HSEM_C2ICR_ISC5_Msk       /*!< </spirit:description> */
#define HSEM_C2ICR_ISC6_Pos        (6U)
#define HSEM_C2ICR_ISC6_Msk        (0x1UL << HSEM_C2ICR_ISC6_Pos)   /*!< 0x00000040 */
#define HSEM_C2ICR_ISC6            HSEM_C2ICR_ISC6_Msk       /*!< </spirit:description> */
#define HSEM_C2ICR_ISC7_Pos        (7U)
#define HSEM_C2ICR_ISC7_Msk        (0x1UL << HSEM_C2ICR_ISC7_Pos)   /*!< 0x00000080 */
#define HSEM_C2ICR_ISC7            HSEM_C2ICR_ISC7_Msk       /*!< </spirit:description> */
#define HSEM_C2ICR_ISC8_Pos        (8U)
#define HSEM_C2ICR_ISC8_Msk        (0x1UL << HSEM_C2ICR_ISC8_Pos)   /*!< 0x00000100 */
#define HSEM_C2ICR_ISC8            HSEM_C2ICR_ISC8_Msk       /*!< </spirit:description> */
#define HSEM_C2ICR_ISC9_Pos        (9U)
#define HSEM_C2ICR_ISC9_Msk        (0x1UL << HSEM_C2ICR_ISC9_Pos)   /*!< 0x00000200 */
#define HSEM_C2ICR_ISC9            HSEM_C2ICR_ISC9_Msk       /*!< </spirit:description> */
#define HSEM_C2ICR_ISC10_Pos       (10U)
#define HSEM_C2ICR_ISC10_Msk       (0x1UL << HSEM_C2ICR_ISC10_Pos)    /*!< 0x00000400 */
#define HSEM_C2ICR_ISC10           HSEM_C2ICR_ISC10_Msk      /*!< </spirit:description> */
#define HSEM_C2ICR_ISC11_Pos       (11U)
#define HSEM_C2ICR_ISC11_Msk       (0x1UL << HSEM_C2ICR_ISC11_Pos)    /*!< 0x00000800 */
#define HSEM_C2ICR_ISC11           HSEM_C2ICR_ISC11_Msk      /*!< </spirit:description> */
#define HSEM_C2ICR_ISC12_Pos       (12U)
#define HSEM_C2ICR_ISC12_Msk       (0x1UL << HSEM_C2ICR_ISC12_Pos)    /*!< 0x00001000 */
#define HSEM_C2ICR_ISC12           HSEM_C2ICR_ISC12_Msk      /*!< </spirit:description> */
#define HSEM_C2ICR_ISC13_Pos       (13U)
#define HSEM_C2ICR_ISC13_Msk       (0x1UL << HSEM_C2ICR_ISC13_Pos)    /*!< 0x00002000 */
#define HSEM_C2ICR_ISC13           HSEM_C2ICR_ISC13_Msk      /*!< </spirit:description> */
#define HSEM_C2ICR_ISC14_Pos       (14U)
#define HSEM_C2ICR_ISC14_Msk       (0x1UL << HSEM_C2ICR_ISC14_Pos)    /*!< 0x00004000 */
#define HSEM_C2ICR_ISC14           HSEM_C2ICR_ISC14_Msk      /*!< </spirit:description> */
#define HSEM_C2ICR_ISC15_Pos       (15U)
#define HSEM_C2ICR_ISC15_Msk       (0x1UL << HSEM_C2ICR_ISC15_Pos)    /*!< 0x00008000 */
#define HSEM_C2ICR_ISC15           HSEM_C2ICR_ISC15_Msk      /*!< </spirit:description> */
#define HSEM_C2ICR_ISC16_Pos       (16U)
#define HSEM_C2ICR_ISC16_Msk       (0x1UL << HSEM_C2ICR_ISC16_Pos)    /*!< 0x00010000 */
#define HSEM_C2ICR_ISC16           HSEM_C2ICR_ISC16_Msk      /*!< </spirit:description> */
#define HSEM_C2ICR_ISC17_Pos       (17U)
#define HSEM_C2ICR_ISC17_Msk       (0x1UL << HSEM_C2ICR_ISC17_Pos)    /*!< 0x00020000 */
#define HSEM_C2ICR_ISC17           HSEM_C2ICR_ISC17_Msk      /*!< </spirit:description> */
#define HSEM_C2ICR_ISC18_Pos       (18U)
#define HSEM_C2ICR_ISC18_Msk       (0x1UL << HSEM_C2ICR_ISC18_Pos)    /*!< 0x00040000 */
#define HSEM_C2ICR_ISC18           HSEM_C2ICR_ISC18_Msk      /*!< </spirit:description> */
#define HSEM_C2ICR_ISC19_Pos       (19U)
#define HSEM_C2ICR_ISC19_Msk       (0x1UL << HSEM_C2ICR_ISC19_Pos)    /*!< 0x00080000 */
#define HSEM_C2ICR_ISC19           HSEM_C2ICR_ISC19_Msk      /*!< </spirit:description> */
#define HSEM_C2ICR_ISC20_Pos       (20U)
#define HSEM_C2ICR_ISC20_Msk       (0x1UL << HSEM_C2ICR_ISC20_Pos)    /*!< 0x00100000 */
#define HSEM_C2ICR_ISC20           HSEM_C2ICR_ISC20_Msk      /*!< </spirit:description> */
#define HSEM_C2ICR_ISC21_Pos       (21U)
#define HSEM_C2ICR_ISC21_Msk       (0x1UL << HSEM_C2ICR_ISC21_Pos)    /*!< 0x00200000 */
#define HSEM_C2ICR_ISC21           HSEM_C2ICR_ISC21_Msk      /*!< </spirit:description> */
#define HSEM_C2ICR_ISC22_Pos       (22U)
#define HSEM_C2ICR_ISC22_Msk       (0x1UL << HSEM_C2ICR_ISC22_Pos)    /*!< 0x00400000 */
#define HSEM_C2ICR_ISC22           HSEM_C2ICR_ISC22_Msk      /*!< </spirit:description> */
#define HSEM_C2ICR_ISC23_Pos       (23U)
#define HSEM_C2ICR_ISC23_Msk       (0x1UL << HSEM_C2ICR_ISC23_Pos)    /*!< 0x00800000 */
#define HSEM_C2ICR_ISC23           HSEM_C2ICR_ISC23_Msk      /*!< </spirit:description> */
#define HSEM_C2ICR_ISC24_Pos       (24U)
#define HSEM_C2ICR_ISC24_Msk       (0x1UL << HSEM_C2ICR_ISC24_Pos)    /*!< 0x01000000 */
#define HSEM_C2ICR_ISC24           HSEM_C2ICR_ISC24_Msk      /*!< </spirit:description> */
#define HSEM_C2ICR_ISC25_Pos       (25U)
#define HSEM_C2ICR_ISC25_Msk       (0x1UL << HSEM_C2ICR_ISC25_Pos)    /*!< 0x02000000 */
#define HSEM_C2ICR_ISC25           HSEM_C2ICR_ISC25_Msk      /*!< </spirit:description> */
#define HSEM_C2ICR_ISC26_Pos       (26U)
#define HSEM_C2ICR_ISC26_Msk       (0x1UL << HSEM_C2ICR_ISC26_Pos)    /*!< 0x04000000 */
#define HSEM_C2ICR_ISC26           HSEM_C2ICR_ISC26_Msk      /*!< </spirit:description> */
#define HSEM_C2ICR_ISC27_Pos       (27U)
#define HSEM_C2ICR_ISC27_Msk       (0x1UL << HSEM_C2ICR_ISC27_Pos)    /*!< 0x08000000 */
#define HSEM_C2ICR_ISC27           HSEM_C2ICR_ISC27_Msk      /*!< </spirit:description> */
#define HSEM_C2ICR_ISC28_Pos       (28U)
#define HSEM_C2ICR_ISC28_Msk       (0x1UL << HSEM_C2ICR_ISC28_Pos)    /*!< 0x10000000 */
#define HSEM_C2ICR_ISC28           HSEM_C2ICR_ISC28_Msk      /*!< </spirit:description> */
#define HSEM_C2ICR_ISC29_Pos       (29U)
#define HSEM_C2ICR_ISC29_Msk       (0x1UL << HSEM_C2ICR_ISC29_Pos)    /*!< 0x20000000 */
#define HSEM_C2ICR_ISC29           HSEM_C2ICR_ISC29_Msk      /*!< </spirit:description> */
#define HSEM_C2ICR_ISC30_Pos       (30U)
#define HSEM_C2ICR_ISC30_Msk       (0x1UL << HSEM_C2ICR_ISC30_Pos)    /*!< 0x40000000 */
#define HSEM_C2ICR_ISC30           HSEM_C2ICR_ISC30_Msk      /*!< </spirit:description> */
#define HSEM_C2ICR_ISC31_Pos       (31U)
#define HSEM_C2ICR_ISC31_Msk       (0x1UL << HSEM_C2ICR_ISC31_Pos)    /*!< 0x80000000 */
#define HSEM_C2ICR_ISC31           HSEM_C2ICR_ISC31_Msk      /*!< </spirit:description> */

/******************  Bit definition for HSEM_C2ISR register  ******************/
#define HSEM_C2ISR_ISF0_Pos        (0U)
#define HSEM_C2ISR_ISF0_Msk        (0x1UL << HSEM_C2ISR_ISF0_Pos)   /*!< 0x00000001 */
#define HSEM_C2ISR_ISF0            HSEM_C2ISR_ISF0_Msk       /*!< </spirit:description> */
#define HSEM_C2ISR_ISF1_Pos        (1U)
#define HSEM_C2ISR_ISF1_Msk        (0x1UL << HSEM_C2ISR_ISF1_Pos)   /*!< 0x00000002 */
#define HSEM_C2ISR_ISF1            HSEM_C2ISR_ISF1_Msk       /*!< </spirit:description> */
#define HSEM_C2ISR_ISF2_Pos        (2U)
#define HSEM_C2ISR_ISF2_Msk        (0x1UL << HSEM_C2ISR_ISF2_Pos)   /*!< 0x00000004 */
#define HSEM_C2ISR_ISF2            HSEM_C2ISR_ISF2_Msk       /*!< </spirit:description> */
#define HSEM_C2ISR_ISF3_Pos        (3U)
#define HSEM_C2ISR_ISF3_Msk        (0x1UL << HSEM_C2ISR_ISF3_Pos)   /*!< 0x00000008 */
#define HSEM_C2ISR_ISF3            HSEM_C2ISR_ISF3_Msk       /*!< </spirit:description> */
#define HSEM_C2ISR_ISF4_Pos        (4U)
#define HSEM_C2ISR_ISF4_Msk        (0x1UL << HSEM_C2ISR_ISF4_Pos)   /*!< 0x00000010 */
#define HSEM_C2ISR_ISF4            HSEM_C2ISR_ISF4_Msk       /*!< </spirit:description> */
#define HSEM_C2ISR_ISF5_Pos        (5U)
#define HSEM_C2ISR_ISF5_Msk        (0x1UL << HSEM_C2ISR_ISF5_Pos)   /*!< 0x00000020 */
#define HSEM_C2ISR_ISF5            HSEM_C2ISR_ISF5_Msk       /*!< </spirit:description> */
#define HSEM_C2ISR_ISF6_Pos        (6U)
#define HSEM_C2ISR_ISF6_Msk        (0x1UL << HSEM_C2ISR_ISF6_Pos)   /*!< 0x00000040 */
#define HSEM_C2ISR_ISF6            HSEM_C2ISR_ISF6_Msk       /*!< </spirit:description> */
#define HSEM_C2ISR_ISF7_Pos        (7U)
#define HSEM_C2ISR_ISF7_Msk        (0x1UL << HSEM_C2ISR_ISF7_Pos)   /*!< 0x00000080 */
#define HSEM_C2ISR_ISF7            HSEM_C2ISR_ISF7_Msk       /*!< </spirit:description> */
#define HSEM_C2ISR_ISF8_Pos        (8U)
#define HSEM_C2ISR_ISF8_Msk        (0x1UL << HSEM_C2ISR_ISF8_Pos)   /*!< 0x00000100 */
#define HSEM_C2ISR_ISF8            HSEM_C2ISR_ISF8_Msk       /*!< </spirit:description> */
#define HSEM_C2ISR_ISF9_Pos        (9U)
#define HSEM_C2ISR_ISF9_Msk        (0x1UL << HSEM_C2ISR_ISF9_Pos)   /*!< 0x00000200 */
#define HSEM_C2ISR_ISF9            HSEM_C2ISR_ISF9_Msk       /*!< </spirit:description> */
#define HSEM_C2ISR_ISF10_Pos       (10U)
#define HSEM_C2ISR_ISF10_Msk       (0x1UL << HSEM_C2ISR_ISF10_Pos)    /*!< 0x00000400 */
#define HSEM_C2ISR_ISF10           HSEM_C2ISR_ISF10_Msk      /*!< </spirit:description> */
#define HSEM_C2ISR_ISF11_Pos       (11U)
#define HSEM_C2ISR_ISF11_Msk       (0x1UL << HSEM_C2ISR_ISF11_Pos)    /*!< 0x00000800 */
#define HSEM_C2ISR_ISF11           HSEM_C2ISR_ISF11_Msk      /*!< </spirit:description> */
#define HSEM_C2ISR_ISF12_Pos       (12U)
#define HSEM_C2ISR_ISF12_Msk       (0x1UL << HSEM_C2ISR_ISF12_Pos)    /*!< 0x00001000 */
#define HSEM_C2ISR_ISF12           HSEM_C2ISR_ISF12_Msk      /*!< </spirit:description> */
#define HSEM_C2ISR_ISF13_Pos       (13U)
#define HSEM_C2ISR_ISF13_Msk       (0x1UL << HSEM_C2ISR_ISF13_Pos)    /*!< 0x00002000 */
#define HSEM_C2ISR_ISF13           HSEM_C2ISR_ISF13_Msk      /*!< </spirit:description> */
#define HSEM_C2ISR_ISF14_Pos       (14U)
#define HSEM_C2ISR_ISF14_Msk       (0x1UL << HSEM_C2ISR_ISF14_Pos)    /*!< 0x00004000 */
#define HSEM_C2ISR_ISF14           HSEM_C2ISR_ISF14_Msk      /*!< </spirit:description> */
#define HSEM_C2ISR_ISF15_Pos       (15U)
#define HSEM_C2ISR_ISF15_Msk       (0x1UL << HSEM_C2ISR_ISF15_Pos)    /*!< 0x00008000 */
#define HSEM_C2ISR_ISF15           HSEM_C2ISR_ISF15_Msk      /*!< </spirit:description> */
#define HSEM_C2ISR_ISF16_Pos       (16U)
#define HSEM_C2ISR_ISF16_Msk       (0x1UL << HSEM_C2ISR_ISF16_Pos)    /*!< 0x00010000 */
#define HSEM_C2ISR_ISF16           HSEM_C2ISR_ISF16_Msk      /*!< </spirit:description> */
#define HSEM_C2ISR_ISF17_Pos       (17U)
#define HSEM_C2ISR_ISF17_Msk       (0x1UL << HSEM_C2ISR_ISF17_Pos)    /*!< 0x00020000 */
#define HSEM_C2ISR_ISF17           HSEM_C2ISR_ISF17_Msk      /*!< </spirit:description> */
#define HSEM_C2ISR_ISF18_Pos       (18U)
#define HSEM_C2ISR_ISF18_Msk       (0x1UL << HSEM_C2ISR_ISF18_Pos)    /*!< 0x00040000 */
#define HSEM_C2ISR_ISF18           HSEM_C2ISR_ISF18_Msk      /*!< </spirit:description> */
#define HSEM_C2ISR_ISF19_Pos       (19U)
#define HSEM_C2ISR_ISF19_Msk       (0x1UL << HSEM_C2ISR_ISF19_Pos)    /*!< 0x00080000 */
#define HSEM_C2ISR_ISF19           HSEM_C2ISR_ISF19_Msk      /*!< </spirit:description> */
#define HSEM_C2ISR_ISF20_Pos       (20U)
#define HSEM_C2ISR_ISF20_Msk       (0x1UL << HSEM_C2ISR_ISF20_Pos)    /*!< 0x00100000 */
#define HSEM_C2ISR_ISF20           HSEM_C2ISR_ISF20_Msk      /*!< </spirit:description> */
#define HSEM_C2ISR_ISF21_Pos       (21U)
#define HSEM_C2ISR_ISF21_Msk       (0x1UL << HSEM_C2ISR_ISF21_Pos)    /*!< 0x00200000 */
#define HSEM_C2ISR_ISF21           HSEM_C2ISR_ISF21_Msk      /*!< </spirit:description> */
#define HSEM_C2ISR_ISF22_Pos       (22U)
#define HSEM_C2ISR_ISF22_Msk       (0x1UL << HSEM_C2ISR_ISF22_Pos)    /*!< 0x00400000 */
#define HSEM_C2ISR_ISF22           HSEM_C2ISR_ISF22_Msk      /*!< </spirit:description> */
#define HSEM_C2ISR_ISF23_Pos       (23U)
#define HSEM_C2ISR_ISF23_Msk       (0x1UL << HSEM_C2ISR_ISF23_Pos)    /*!< 0x00800000 */
#define HSEM_C2ISR_ISF23           HSEM_C2ISR_ISF23_Msk      /*!< </spirit:description> */
#define HSEM_C2ISR_ISF24_Pos       (24U)
#define HSEM_C2ISR_ISF24_Msk       (0x1UL << HSEM_C2ISR_ISF24_Pos)    /*!< 0x01000000 */
#define HSEM_C2ISR_ISF24           HSEM_C2ISR_ISF24_Msk      /*!< </spirit:description> */
#define HSEM_C2ISR_ISF25_Pos       (25U)
#define HSEM_C2ISR_ISF25_Msk       (0x1UL << HSEM_C2ISR_ISF25_Pos)    /*!< 0x02000000 */
#define HSEM_C2ISR_ISF25           HSEM_C2ISR_ISF25_Msk      /*!< </spirit:description> */
#define HSEM_C2ISR_ISF26_Pos       (26U)
#define HSEM_C2ISR_ISF26_Msk       (0x1UL << HSEM_C2ISR_ISF26_Pos)    /*!< 0x04000000 */
#define HSEM_C2ISR_ISF26           HSEM_C2ISR_ISF26_Msk      /*!< </spirit:description> */
#define HSEM_C2ISR_ISF27_Pos       (27U)
#define HSEM_C2ISR_ISF27_Msk       (0x1UL << HSEM_C2ISR_ISF27_Pos)    /*!< 0x08000000 */
#define HSEM_C2ISR_ISF27           HSEM_C2ISR_ISF27_Msk      /*!< </spirit:description> */
#define HSEM_C2ISR_ISF28_Pos       (28U)
#define HSEM_C2ISR_ISF28_Msk       (0x1UL << HSEM_C2ISR_ISF28_Pos)    /*!< 0x10000000 */
#define HSEM_C2ISR_ISF28           HSEM_C2ISR_ISF28_Msk      /*!< </spirit:description> */
#define HSEM_C2ISR_ISF29_Pos       (29U)
#define HSEM_C2ISR_ISF29_Msk       (0x1UL << HSEM_C2ISR_ISF29_Pos)    /*!< 0x20000000 */
#define HSEM_C2ISR_ISF29           HSEM_C2ISR_ISF29_Msk      /*!< </spirit:description> */
#define HSEM_C2ISR_ISF30_Pos       (30U)
#define HSEM_C2ISR_ISF30_Msk       (0x1UL << HSEM_C2ISR_ISF30_Pos)    /*!< 0x40000000 */
#define HSEM_C2ISR_ISF30           HSEM_C2ISR_ISF30_Msk      /*!< </spirit:description> */
#define HSEM_C2ISR_ISF31_Pos       (31U)
#define HSEM_C2ISR_ISF31_Msk       (0x1UL << HSEM_C2ISR_ISF31_Pos)    /*!< 0x80000000 */
#define HSEM_C2ISR_ISF31           HSEM_C2ISR_ISF31_Msk      /*!< </spirit:description> */

/*****************  Bit definition for HSEM_C2MISR register  ******************/
#define HSEM_C2MISR_MISF0_Pos      (0U)
#define HSEM_C2MISR_MISF0_Msk      (0x1UL << HSEM_C2MISR_MISF0_Pos)     /*!< 0x00000001 */
#define HSEM_C2MISR_MISF0          HSEM_C2MISR_MISF0_Msk     /*!< </spirit:description> */
#define HSEM_C2MISR_MISF1_Pos      (1U)
#define HSEM_C2MISR_MISF1_Msk      (0x1UL << HSEM_C2MISR_MISF1_Pos)     /*!< 0x00000002 */
#define HSEM_C2MISR_MISF1          HSEM_C2MISR_MISF1_Msk     /*!< </spirit:description> */
#define HSEM_C2MISR_MISF2_Pos      (2U)
#define HSEM_C2MISR_MISF2_Msk      (0x1UL << HSEM_C2MISR_MISF2_Pos)     /*!< 0x00000004 */
#define HSEM_C2MISR_MISF2          HSEM_C2MISR_MISF2_Msk     /*!< </spirit:description> */
#define HSEM_C2MISR_MISF3_Pos      (3U)
#define HSEM_C2MISR_MISF3_Msk      (0x1UL << HSEM_C2MISR_MISF3_Pos)     /*!< 0x00000008 */
#define HSEM_C2MISR_MISF3          HSEM_C2MISR_MISF3_Msk     /*!< </spirit:description> */
#define HSEM_C2MISR_MISF4_Pos      (4U)
#define HSEM_C2MISR_MISF4_Msk      (0x1UL << HSEM_C2MISR_MISF4_Pos)     /*!< 0x00000010 */
#define HSEM_C2MISR_MISF4          HSEM_C2MISR_MISF4_Msk     /*!< </spirit:description> */
#define HSEM_C2MISR_MISF5_Pos      (5U)
#define HSEM_C2MISR_MISF5_Msk      (0x1UL << HSEM_C2MISR_MISF5_Pos)     /*!< 0x00000020 */
#define HSEM_C2MISR_MISF5          HSEM_C2MISR_MISF5_Msk     /*!< </spirit:description> */
#define HSEM_C2MISR_MISF6_Pos      (6U)
#define HSEM_C2MISR_MISF6_Msk      (0x1UL << HSEM_C2MISR_MISF6_Pos)     /*!< 0x00000040 */
#define HSEM_C2MISR_MISF6          HSEM_C2MISR_MISF6_Msk     /*!< </spirit:description> */
#define HSEM_C2MISR_MISF7_Pos      (7U)
#define HSEM_C2MISR_MISF7_Msk      (0x1UL << HSEM_C2MISR_MISF7_Pos)     /*!< 0x00000080 */
#define HSEM_C2MISR_MISF7          HSEM_C2MISR_MISF7_Msk     /*!< </spirit:description> */
#define HSEM_C2MISR_MISF8_Pos      (8U)
#define HSEM_C2MISR_MISF8_Msk      (0x1UL << HSEM_C2MISR_MISF8_Pos)     /*!< 0x00000100 */
#define HSEM_C2MISR_MISF8          HSEM_C2MISR_MISF8_Msk     /*!< </spirit:description> */
#define HSEM_C2MISR_MISF9_Pos      (9U)
#define HSEM_C2MISR_MISF9_Msk      (0x1UL << HSEM_C2MISR_MISF9_Pos)     /*!< 0x00000200 */
#define HSEM_C2MISR_MISF9          HSEM_C2MISR_MISF9_Msk     /*!< </spirit:description> */
#define HSEM_C2MISR_MISF10_Pos     (10U)
#define HSEM_C2MISR_MISF10_Msk     (0x1UL << HSEM_C2MISR_MISF10_Pos)      /*!< 0x00000400 */
#define HSEM_C2MISR_MISF10         HSEM_C2MISR_MISF10_Msk    /*!< </spirit:description> */
#define HSEM_C2MISR_MISF11_Pos     (11U)
#define HSEM_C2MISR_MISF11_Msk     (0x1UL << HSEM_C2MISR_MISF11_Pos)      /*!< 0x00000800 */
#define HSEM_C2MISR_MISF11         HSEM_C2MISR_MISF11_Msk    /*!< </spirit:description> */
#define HSEM_C2MISR_MISF12_Pos     (12U)
#define HSEM_C2MISR_MISF12_Msk     (0x1UL << HSEM_C2MISR_MISF12_Pos)      /*!< 0x00001000 */
#define HSEM_C2MISR_MISF12         HSEM_C2MISR_MISF12_Msk    /*!< </spirit:description> */
#define HSEM_C2MISR_MISF13_Pos     (13U)
#define HSEM_C2MISR_MISF13_Msk     (0x1UL << HSEM_C2MISR_MISF13_Pos)      /*!< 0x00002000 */
#define HSEM_C2MISR_MISF13         HSEM_C2MISR_MISF13_Msk    /*!< </spirit:description> */
#define HSEM_C2MISR_MISF14_Pos     (14U)
#define HSEM_C2MISR_MISF14_Msk     (0x1UL << HSEM_C2MISR_MISF14_Pos)      /*!< 0x00004000 */
#define HSEM_C2MISR_MISF14         HSEM_C2MISR_MISF14_Msk    /*!< </spirit:description> */
#define HSEM_C2MISR_MISF15_Pos     (15U)
#define HSEM_C2MISR_MISF15_Msk     (0x1UL << HSEM_C2MISR_MISF15_Pos)      /*!< 0x00008000 */
#define HSEM_C2MISR_MISF15         HSEM_C2MISR_MISF15_Msk    /*!< </spirit:description> */
#define HSEM_C2MISR_MISF16_Pos     (16U)
#define HSEM_C2MISR_MISF16_Msk     (0x1UL << HSEM_C2MISR_MISF16_Pos)      /*!< 0x00010000 */
#define HSEM_C2MISR_MISF16         HSEM_C2MISR_MISF16_Msk    /*!< </spirit:description> */
#define HSEM_C2MISR_MISF17_Pos     (17U)
#define HSEM_C2MISR_MISF17_Msk     (0x1UL << HSEM_C2MISR_MISF17_Pos)      /*!< 0x00020000 */
#define HSEM_C2MISR_MISF17         HSEM_C2MISR_MISF17_Msk    /*!< </spirit:description> */
#define HSEM_C2MISR_MISF18_Pos     (18U)
#define HSEM_C2MISR_MISF18_Msk     (0x1UL << HSEM_C2MISR_MISF18_Pos)      /*!< 0x00040000 */
#define HSEM_C2MISR_MISF18         HSEM_C2MISR_MISF18_Msk    /*!< </spirit:description> */
#define HSEM_C2MISR_MISF19_Pos     (19U)
#define HSEM_C2MISR_MISF19_Msk     (0x1UL << HSEM_C2MISR_MISF19_Pos)      /*!< 0x00080000 */
#define HSEM_C2MISR_MISF19         HSEM_C2MISR_MISF19_Msk    /*!< </spirit:description> */
#define HSEM_C2MISR_MISF20_Pos     (20U)
#define HSEM_C2MISR_MISF20_Msk     (0x1UL << HSEM_C2MISR_MISF20_Pos)      /*!< 0x00100000 */
#define HSEM_C2MISR_MISF20         HSEM_C2MISR_MISF20_Msk    /*!< </spirit:description> */
#define HSEM_C2MISR_MISF21_Pos     (21U)
#define HSEM_C2MISR_MISF21_Msk     (0x1UL << HSEM_C2MISR_MISF21_Pos)      /*!< 0x00200000 */
#define HSEM_C2MISR_MISF21         HSEM_C2MISR_MISF21_Msk    /*!< </spirit:description> */
#define HSEM_C2MISR_MISF22_Pos     (22U)
#define HSEM_C2MISR_MISF22_Msk     (0x1UL << HSEM_C2MISR_MISF22_Pos)      /*!< 0x00400000 */
#define HSEM_C2MISR_MISF22         HSEM_C2MISR_MISF22_Msk    /*!< </spirit:description> */
#define HSEM_C2MISR_MISF23_Pos     (23U)
#define HSEM_C2MISR_MISF23_Msk     (0x1UL << HSEM_C2MISR_MISF23_Pos)      /*!< 0x00800000 */
#define HSEM_C2MISR_MISF23         HSEM_C2MISR_MISF23_Msk    /*!< </spirit:description> */
#define HSEM_C2MISR_MISF24_Pos     (24U)
#define HSEM_C2MISR_MISF24_Msk     (0x1UL << HSEM_C2MISR_MISF24_Pos)      /*!< 0x01000000 */
#define HSEM_C2MISR_MISF24         HSEM_C2MISR_MISF24_Msk    /*!< </spirit:description> */
#define HSEM_C2MISR_MISF25_Pos     (25U)
#define HSEM_C2MISR_MISF25_Msk     (0x1UL << HSEM_C2MISR_MISF25_Pos)      /*!< 0x02000000 */
#define HSEM_C2MISR_MISF25         HSEM_C2MISR_MISF25_Msk    /*!< </spirit:description> */
#define HSEM_C2MISR_MISF26_Pos     (26U)
#define HSEM_C2MISR_MISF26_Msk     (0x1UL << HSEM_C2MISR_MISF26_Pos)      /*!< 0x04000000 */
#define HSEM_C2MISR_MISF26         HSEM_C2MISR_MISF26_Msk    /*!< </spirit:description> */
#define HSEM_C2MISR_MISF27_Pos     (27U)
#define HSEM_C2MISR_MISF27_Msk     (0x1UL << HSEM_C2MISR_MISF27_Pos)      /*!< 0x08000000 */
#define HSEM_C2MISR_MISF27         HSEM_C2MISR_MISF27_Msk    /*!< </spirit:description> */
#define HSEM_C2MISR_MISF28_Pos     (28U)
#define HSEM_C2MISR_MISF28_Msk     (0x1UL << HSEM_C2MISR_MISF28_Pos)      /*!< 0x10000000 */
#define HSEM_C2MISR_MISF28         HSEM_C2MISR_MISF28_Msk    /*!< </spirit:description> */
#define HSEM_C2MISR_MISF29_Pos     (29U)
#define HSEM_C2MISR_MISF29_Msk     (0x1UL << HSEM_C2MISR_MISF29_Pos)      /*!< 0x20000000 */
#define HSEM_C2MISR_MISF29         HSEM_C2MISR_MISF29_Msk    /*!< </spirit:description> */
#define HSEM_C2MISR_MISF30_Pos     (30U)
#define HSEM_C2MISR_MISF30_Msk     (0x1UL << HSEM_C2MISR_MISF30_Pos)      /*!< 0x40000000 */
#define HSEM_C2MISR_MISF30         HSEM_C2MISR_MISF30_Msk    /*!< </spirit:description> */
#define HSEM_C2MISR_MISF31_Pos     (31U)
#define HSEM_C2MISR_MISF31_Msk     (0x1UL << HSEM_C2MISR_MISF31_Pos)      /*!< 0x80000000 */
#define HSEM_C2MISR_MISF31         HSEM_C2MISR_MISF31_Msk    /*!< </spirit:description> */

/******************  Bit definition for HSEM_C3IER register  ******************/
#define HSEM_C3IER_ISE0_Pos        (0U)
#define HSEM_C3IER_ISE0_Msk        (0x1UL << HSEM_C3IER_ISE0_Pos)   /*!< 0x00000001 */
#define HSEM_C3IER_ISE0            HSEM_C3IER_ISE0_Msk       /*!< </spirit:description> */
#define HSEM_C3IER_ISE1_Pos        (1U)
#define HSEM_C3IER_ISE1_Msk        (0x1UL << HSEM_C3IER_ISE1_Pos)   /*!< 0x00000002 */
#define HSEM_C3IER_ISE1            HSEM_C3IER_ISE1_Msk       /*!< </spirit:description> */
#define HSEM_C3IER_ISE2_Pos        (2U)
#define HSEM_C3IER_ISE2_Msk        (0x1UL << HSEM_C3IER_ISE2_Pos)   /*!< 0x00000004 */
#define HSEM_C3IER_ISE2            HSEM_C3IER_ISE2_Msk       /*!< </spirit:description> */
#define HSEM_C3IER_ISE3_Pos        (3U)
#define HSEM_C3IER_ISE3_Msk        (0x1UL << HSEM_C3IER_ISE3_Pos)   /*!< 0x00000008 */
#define HSEM_C3IER_ISE3            HSEM_C3IER_ISE3_Msk       /*!< </spirit:description> */
#define HSEM_C3IER_ISE4_Pos        (4U)
#define HSEM_C3IER_ISE4_Msk        (0x1UL << HSEM_C3IER_ISE4_Pos)   /*!< 0x00000010 */
#define HSEM_C3IER_ISE4            HSEM_C3IER_ISE4_Msk       /*!< </spirit:description> */
#define HSEM_C3IER_ISE5_Pos        (5U)
#define HSEM_C3IER_ISE5_Msk        (0x1UL << HSEM_C3IER_ISE5_Pos)   /*!< 0x00000020 */
#define HSEM_C3IER_ISE5            HSEM_C3IER_ISE5_Msk       /*!< </spirit:description> */
#define HSEM_C3IER_ISE6_Pos        (6U)
#define HSEM_C3IER_ISE6_Msk        (0x1UL << HSEM_C3IER_ISE6_Pos)   /*!< 0x00000040 */
#define HSEM_C3IER_ISE6            HSEM_C3IER_ISE6_Msk       /*!< </spirit:description> */
#define HSEM_C3IER_ISE7_Pos        (7U)
#define HSEM_C3IER_ISE7_Msk        (0x1UL << HSEM_C3IER_ISE7_Pos)   /*!< 0x00000080 */
#define HSEM_C3IER_ISE7            HSEM_C3IER_ISE7_Msk       /*!< </spirit:description> */
#define HSEM_C3IER_ISE8_Pos        (8U)
#define HSEM_C3IER_ISE8_Msk        (0x1UL << HSEM_C3IER_ISE8_Pos)   /*!< 0x00000100 */
#define HSEM_C3IER_ISE8            HSEM_C3IER_ISE8_Msk       /*!< </spirit:description> */
#define HSEM_C3IER_ISE9_Pos        (9U)
#define HSEM_C3IER_ISE9_Msk        (0x1UL << HSEM_C3IER_ISE9_Pos)   /*!< 0x00000200 */
#define HSEM_C3IER_ISE9            HSEM_C3IER_ISE9_Msk       /*!< </spirit:description> */
#define HSEM_C3IER_ISE10_Pos       (10U)
#define HSEM_C3IER_ISE10_Msk       (0x1UL << HSEM_C3IER_ISE10_Pos)    /*!< 0x00000400 */
#define HSEM_C3IER_ISE10           HSEM_C3IER_ISE10_Msk      /*!< </spirit:description> */
#define HSEM_C3IER_ISE11_Pos       (11U)
#define HSEM_C3IER_ISE11_Msk       (0x1UL << HSEM_C3IER_ISE11_Pos)    /*!< 0x00000800 */
#define HSEM_C3IER_ISE11           HSEM_C3IER_ISE11_Msk      /*!< </spirit:description> */
#define HSEM_C3IER_ISE12_Pos       (12U)
#define HSEM_C3IER_ISE12_Msk       (0x1UL << HSEM_C3IER_ISE12_Pos)    /*!< 0x00001000 */
#define HSEM_C3IER_ISE12           HSEM_C3IER_ISE12_Msk      /*!< </spirit:description> */
#define HSEM_C3IER_ISE13_Pos       (13U)
#define HSEM_C3IER_ISE13_Msk       (0x1UL << HSEM_C3IER_ISE13_Pos)    /*!< 0x00002000 */
#define HSEM_C3IER_ISE13           HSEM_C3IER_ISE13_Msk      /*!< </spirit:description> */
#define HSEM_C3IER_ISE14_Pos       (14U)
#define HSEM_C3IER_ISE14_Msk       (0x1UL << HSEM_C3IER_ISE14_Pos)    /*!< 0x00004000 */
#define HSEM_C3IER_ISE14           HSEM_C3IER_ISE14_Msk      /*!< </spirit:description> */
#define HSEM_C3IER_ISE15_Pos       (15U)
#define HSEM_C3IER_ISE15_Msk       (0x1UL << HSEM_C3IER_ISE15_Pos)    /*!< 0x00008000 */
#define HSEM_C3IER_ISE15           HSEM_C3IER_ISE15_Msk      /*!< </spirit:description> */
#define HSEM_C3IER_ISE16_Pos       (16U)
#define HSEM_C3IER_ISE16_Msk       (0x1UL << HSEM_C3IER_ISE16_Pos)    /*!< 0x00010000 */
#define HSEM_C3IER_ISE16           HSEM_C3IER_ISE16_Msk      /*!< </spirit:description> */
#define HSEM_C3IER_ISE17_Pos       (17U)
#define HSEM_C3IER_ISE17_Msk       (0x1UL << HSEM_C3IER_ISE17_Pos)    /*!< 0x00020000 */
#define HSEM_C3IER_ISE17           HSEM_C3IER_ISE17_Msk      /*!< </spirit:description> */
#define HSEM_C3IER_ISE18_Pos       (18U)
#define HSEM_C3IER_ISE18_Msk       (0x1UL << HSEM_C3IER_ISE18_Pos)    /*!< 0x00040000 */
#define HSEM_C3IER_ISE18           HSEM_C3IER_ISE18_Msk      /*!< </spirit:description> */
#define HSEM_C3IER_ISE19_Pos       (19U)
#define HSEM_C3IER_ISE19_Msk       (0x1UL << HSEM_C3IER_ISE19_Pos)    /*!< 0x00080000 */
#define HSEM_C3IER_ISE19           HSEM_C3IER_ISE19_Msk      /*!< </spirit:description> */
#define HSEM_C3IER_ISE20_Pos       (20U)
#define HSEM_C3IER_ISE20_Msk       (0x1UL << HSEM_C3IER_ISE20_Pos)    /*!< 0x00100000 */
#define HSEM_C3IER_ISE20           HSEM_C3IER_ISE20_Msk      /*!< </spirit:description> */
#define HSEM_C3IER_ISE21_Pos       (21U)
#define HSEM_C3IER_ISE21_Msk       (0x1UL << HSEM_C3IER_ISE21_Pos)    /*!< 0x00200000 */
#define HSEM_C3IER_ISE21           HSEM_C3IER_ISE21_Msk      /*!< </spirit:description> */
#define HSEM_C3IER_ISE22_Pos       (22U)
#define HSEM_C3IER_ISE22_Msk       (0x1UL << HSEM_C3IER_ISE22_Pos)    /*!< 0x00400000 */
#define HSEM_C3IER_ISE22           HSEM_C3IER_ISE22_Msk      /*!< </spirit:description> */
#define HSEM_C3IER_ISE23_Pos       (23U)
#define HSEM_C3IER_ISE23_Msk       (0x1UL << HSEM_C3IER_ISE23_Pos)    /*!< 0x00800000 */
#define HSEM_C3IER_ISE23           HSEM_C3IER_ISE23_Msk      /*!< </spirit:description> */
#define HSEM_C3IER_ISE24_Pos       (24U)
#define HSEM_C3IER_ISE24_Msk       (0x1UL << HSEM_C3IER_ISE24_Pos)    /*!< 0x01000000 */
#define HSEM_C3IER_ISE24           HSEM_C3IER_ISE24_Msk      /*!< </spirit:description> */
#define HSEM_C3IER_ISE25_Pos       (25U)
#define HSEM_C3IER_ISE25_Msk       (0x1UL << HSEM_C3IER_ISE25_Pos)    /*!< 0x02000000 */
#define HSEM_C3IER_ISE25           HSEM_C3IER_ISE25_Msk      /*!< </spirit:description> */
#define HSEM_C3IER_ISE26_Pos       (26U)
#define HSEM_C3IER_ISE26_Msk       (0x1UL << HSEM_C3IER_ISE26_Pos)    /*!< 0x04000000 */
#define HSEM_C3IER_ISE26           HSEM_C3IER_ISE26_Msk      /*!< </spirit:description> */
#define HSEM_C3IER_ISE27_Pos       (27U)
#define HSEM_C3IER_ISE27_Msk       (0x1UL << HSEM_C3IER_ISE27_Pos)    /*!< 0x08000000 */
#define HSEM_C3IER_ISE27           HSEM_C3IER_ISE27_Msk      /*!< </spirit:description> */
#define HSEM_C3IER_ISE28_Pos       (28U)
#define HSEM_C3IER_ISE28_Msk       (0x1UL << HSEM_C3IER_ISE28_Pos)    /*!< 0x10000000 */
#define HSEM_C3IER_ISE28           HSEM_C3IER_ISE28_Msk      /*!< </spirit:description> */
#define HSEM_C3IER_ISE29_Pos       (29U)
#define HSEM_C3IER_ISE29_Msk       (0x1UL << HSEM_C3IER_ISE29_Pos)    /*!< 0x20000000 */
#define HSEM_C3IER_ISE29           HSEM_C3IER_ISE29_Msk      /*!< </spirit:description> */
#define HSEM_C3IER_ISE30_Pos       (30U)
#define HSEM_C3IER_ISE30_Msk       (0x1UL << HSEM_C3IER_ISE30_Pos)    /*!< 0x40000000 */
#define HSEM_C3IER_ISE30           HSEM_C3IER_ISE30_Msk      /*!< </spirit:description> */
#define HSEM_C3IER_ISE31_Pos       (31U)
#define HSEM_C3IER_ISE31_Msk       (0x1UL << HSEM_C3IER_ISE31_Pos)    /*!< 0x80000000 */
#define HSEM_C3IER_ISE31           HSEM_C3IER_ISE31_Msk      /*!< </spirit:description> */

/******************  Bit definition for HSEM_C3ICR register  ******************/
#define HSEM_C3ICR_ISC0_Pos        (0U)
#define HSEM_C3ICR_ISC0_Msk        (0x1UL << HSEM_C3ICR_ISC0_Pos)   /*!< 0x00000001 */
#define HSEM_C3ICR_ISC0            HSEM_C3ICR_ISC0_Msk       /*!< </spirit:description> */
#define HSEM_C3ICR_ISC1_Pos        (1U)
#define HSEM_C3ICR_ISC1_Msk        (0x1UL << HSEM_C3ICR_ISC1_Pos)   /*!< 0x00000002 */
#define HSEM_C3ICR_ISC1            HSEM_C3ICR_ISC1_Msk       /*!< </spirit:description> */
#define HSEM_C3ICR_ISC2_Pos        (2U)
#define HSEM_C3ICR_ISC2_Msk        (0x1UL << HSEM_C3ICR_ISC2_Pos)   /*!< 0x00000004 */
#define HSEM_C3ICR_ISC2            HSEM_C3ICR_ISC2_Msk       /*!< </spirit:description> */
#define HSEM_C3ICR_ISC3_Pos        (3U)
#define HSEM_C3ICR_ISC3_Msk        (0x1UL << HSEM_C3ICR_ISC3_Pos)   /*!< 0x00000008 */
#define HSEM_C3ICR_ISC3            HSEM_C3ICR_ISC3_Msk       /*!< </spirit:description> */
#define HSEM_C3ICR_ISC4_Pos        (4U)
#define HSEM_C3ICR_ISC4_Msk        (0x1UL << HSEM_C3ICR_ISC4_Pos)   /*!< 0x00000010 */
#define HSEM_C3ICR_ISC4            HSEM_C3ICR_ISC4_Msk       /*!< </spirit:description> */
#define HSEM_C3ICR_ISC5_Pos        (5U)
#define HSEM_C3ICR_ISC5_Msk        (0x1UL << HSEM_C3ICR_ISC5_Pos)   /*!< 0x00000020 */
#define HSEM_C3ICR_ISC5            HSEM_C3ICR_ISC5_Msk       /*!< </spirit:description> */
#define HSEM_C3ICR_ISC6_Pos        (6U)
#define HSEM_C3ICR_ISC6_Msk        (0x1UL << HSEM_C3ICR_ISC6_Pos)   /*!< 0x00000040 */
#define HSEM_C3ICR_ISC6            HSEM_C3ICR_ISC6_Msk       /*!< </spirit:description> */
#define HSEM_C3ICR_ISC7_Pos        (7U)
#define HSEM_C3ICR_ISC7_Msk        (0x1UL << HSEM_C3ICR_ISC7_Pos)   /*!< 0x00000080 */
#define HSEM_C3ICR_ISC7            HSEM_C3ICR_ISC7_Msk       /*!< </spirit:description> */
#define HSEM_C3ICR_ISC8_Pos        (8U)
#define HSEM_C3ICR_ISC8_Msk        (0x1UL << HSEM_C3ICR_ISC8_Pos)   /*!< 0x00000100 */
#define HSEM_C3ICR_ISC8            HSEM_C3ICR_ISC8_Msk       /*!< </spirit:description> */
#define HSEM_C3ICR_ISC9_Pos        (9U)
#define HSEM_C3ICR_ISC9_Msk        (0x1UL << HSEM_C3ICR_ISC9_Pos)   /*!< 0x00000200 */
#define HSEM_C3ICR_ISC9            HSEM_C3ICR_ISC9_Msk       /*!< </spirit:description> */
#define HSEM_C3ICR_ISC10_Pos       (10U)
#define HSEM_C3ICR_ISC10_Msk       (0x1UL << HSEM_C3ICR_ISC10_Pos)    /*!< 0x00000400 */
#define HSEM_C3ICR_ISC10           HSEM_C3ICR_ISC10_Msk      /*!< </spirit:description> */
#define HSEM_C3ICR_ISC11_Pos       (11U)
#define HSEM_C3ICR_ISC11_Msk       (0x1UL << HSEM_C3ICR_ISC11_Pos)    /*!< 0x00000800 */
#define HSEM_C3ICR_ISC11           HSEM_C3ICR_ISC11_Msk      /*!< </spirit:description> */
#define HSEM_C3ICR_ISC12_Pos       (12U)
#define HSEM_C3ICR_ISC12_Msk       (0x1UL << HSEM_C3ICR_ISC12_Pos)    /*!< 0x00001000 */
#define HSEM_C3ICR_ISC12           HSEM_C3ICR_ISC12_Msk      /*!< </spirit:description> */
#define HSEM_C3ICR_ISC13_Pos       (13U)
#define HSEM_C3ICR_ISC13_Msk       (0x1UL << HSEM_C3ICR_ISC13_Pos)    /*!< 0x00002000 */
#define HSEM_C3ICR_ISC13           HSEM_C3ICR_ISC13_Msk      /*!< </spirit:description> */
#define HSEM_C3ICR_ISC14_Pos       (14U)
#define HSEM_C3ICR_ISC14_Msk       (0x1UL << HSEM_C3ICR_ISC14_Pos)    /*!< 0x00004000 */
#define HSEM_C3ICR_ISC14           HSEM_C3ICR_ISC14_Msk      /*!< </spirit:description> */
#define HSEM_C3ICR_ISC15_Pos       (15U)
#define HSEM_C3ICR_ISC15_Msk       (0x1UL << HSEM_C3ICR_ISC15_Pos)    /*!< 0x00008000 */
#define HSEM_C3ICR_ISC15           HSEM_C3ICR_ISC15_Msk      /*!< </spirit:description> */
#define HSEM_C3ICR_ISC16_Pos       (16U)
#define HSEM_C3ICR_ISC16_Msk       (0x1UL << HSEM_C3ICR_ISC16_Pos)    /*!< 0x00010000 */
#define HSEM_C3ICR_ISC16           HSEM_C3ICR_ISC16_Msk      /*!< </spirit:description> */
#define HSEM_C3ICR_ISC17_Pos       (17U)
#define HSEM_C3ICR_ISC17_Msk       (0x1UL << HSEM_C3ICR_ISC17_Pos)    /*!< 0x00020000 */
#define HSEM_C3ICR_ISC17           HSEM_C3ICR_ISC17_Msk      /*!< </spirit:description> */
#define HSEM_C3ICR_ISC18_Pos       (18U)
#define HSEM_C3ICR_ISC18_Msk       (0x1UL << HSEM_C3ICR_ISC18_Pos)    /*!< 0x00040000 */
#define HSEM_C3ICR_ISC18           HSEM_C3ICR_ISC18_Msk      /*!< </spirit:description> */
#define HSEM_C3ICR_ISC19_Pos       (19U)
#define HSEM_C3ICR_ISC19_Msk       (0x1UL << HSEM_C3ICR_ISC19_Pos)    /*!< 0x00080000 */
#define HSEM_C3ICR_ISC19           HSEM_C3ICR_ISC19_Msk      /*!< </spirit:description> */
#define HSEM_C3ICR_ISC20_Pos       (20U)
#define HSEM_C3ICR_ISC20_Msk       (0x1UL << HSEM_C3ICR_ISC20_Pos)    /*!< 0x00100000 */
#define HSEM_C3ICR_ISC20           HSEM_C3ICR_ISC20_Msk      /*!< </spirit:description> */
#define HSEM_C3ICR_ISC21_Pos       (21U)
#define HSEM_C3ICR_ISC21_Msk       (0x1UL << HSEM_C3ICR_ISC21_Pos)    /*!< 0x00200000 */
#define HSEM_C3ICR_ISC21           HSEM_C3ICR_ISC21_Msk      /*!< </spirit:description> */
#define HSEM_C3ICR_ISC22_Pos       (22U)
#define HSEM_C3ICR_ISC22_Msk       (0x1UL << HSEM_C3ICR_ISC22_Pos)    /*!< 0x00400000 */
#define HSEM_C3ICR_ISC22           HSEM_C3ICR_ISC22_Msk      /*!< </spirit:description> */
#define HSEM_C3ICR_ISC23_Pos       (23U)
#define HSEM_C3ICR_ISC23_Msk       (0x1UL << HSEM_C3ICR_ISC23_Pos)    /*!< 0x00800000 */
#define HSEM_C3ICR_ISC23           HSEM_C3ICR_ISC23_Msk      /*!< </spirit:description> */
#define HSEM_C3ICR_ISC24_Pos       (24U)
#define HSEM_C3ICR_ISC24_Msk       (0x1UL << HSEM_C3ICR_ISC24_Pos)    /*!< 0x01000000 */
#define HSEM_C3ICR_ISC24           HSEM_C3ICR_ISC24_Msk      /*!< </spirit:description> */
#define HSEM_C3ICR_ISC25_Pos       (25U)
#define HSEM_C3ICR_ISC25_Msk       (0x1UL << HSEM_C3ICR_ISC25_Pos)    /*!< 0x02000000 */
#define HSEM_C3ICR_ISC25           HSEM_C3ICR_ISC25_Msk      /*!< </spirit:description> */
#define HSEM_C3ICR_ISC26_Pos       (26U)
#define HSEM_C3ICR_ISC26_Msk       (0x1UL << HSEM_C3ICR_ISC26_Pos)    /*!< 0x04000000 */
#define HSEM_C3ICR_ISC26           HSEM_C3ICR_ISC26_Msk      /*!< </spirit:description> */
#define HSEM_C3ICR_ISC27_Pos       (27U)
#define HSEM_C3ICR_ISC27_Msk       (0x1UL << HSEM_C3ICR_ISC27_Pos)    /*!< 0x08000000 */
#define HSEM_C3ICR_ISC27           HSEM_C3ICR_ISC27_Msk      /*!< </spirit:description> */
#define HSEM_C3ICR_ISC28_Pos       (28U)
#define HSEM_C3ICR_ISC28_Msk       (0x1UL << HSEM_C3ICR_ISC28_Pos)    /*!< 0x10000000 */
#define HSEM_C3ICR_ISC28           HSEM_C3ICR_ISC28_Msk      /*!< </spirit:description> */
#define HSEM_C3ICR_ISC29_Pos       (29U)
#define HSEM_C3ICR_ISC29_Msk       (0x1UL << HSEM_C3ICR_ISC29_Pos)    /*!< 0x20000000 */
#define HSEM_C3ICR_ISC29           HSEM_C3ICR_ISC29_Msk      /*!< </spirit:description> */
#define HSEM_C3ICR_ISC30_Pos       (30U)
#define HSEM_C3ICR_ISC30_Msk       (0x1UL << HSEM_C3ICR_ISC30_Pos)    /*!< 0x40000000 */
#define HSEM_C3ICR_ISC30           HSEM_C3ICR_ISC30_Msk      /*!< </spirit:description> */
#define HSEM_C3ICR_ISC31_Pos       (31U)
#define HSEM_C3ICR_ISC31_Msk       (0x1UL << HSEM_C3ICR_ISC31_Pos)    /*!< 0x80000000 */
#define HSEM_C3ICR_ISC31           HSEM_C3ICR_ISC31_Msk      /*!< </spirit:description> */

/******************  Bit definition for HSEM_C3ISR register  ******************/
#define HSEM_C3ISR_ISF0_Pos        (0U)
#define HSEM_C3ISR_ISF0_Msk        (0x1UL << HSEM_C3ISR_ISF0_Pos)   /*!< 0x00000001 */
#define HSEM_C3ISR_ISF0            HSEM_C3ISR_ISF0_Msk       /*!< </spirit:description> */
#define HSEM_C3ISR_ISF1_Pos        (1U)
#define HSEM_C3ISR_ISF1_Msk        (0x1UL << HSEM_C3ISR_ISF1_Pos)   /*!< 0x00000002 */
#define HSEM_C3ISR_ISF1            HSEM_C3ISR_ISF1_Msk       /*!< </spirit:description> */
#define HSEM_C3ISR_ISF2_Pos        (2U)
#define HSEM_C3ISR_ISF2_Msk        (0x1UL << HSEM_C3ISR_ISF2_Pos)   /*!< 0x00000004 */
#define HSEM_C3ISR_ISF2            HSEM_C3ISR_ISF2_Msk       /*!< </spirit:description> */
#define HSEM_C3ISR_ISF3_Pos        (3U)
#define HSEM_C3ISR_ISF3_Msk        (0x1UL << HSEM_C3ISR_ISF3_Pos)   /*!< 0x00000008 */
#define HSEM_C3ISR_ISF3            HSEM_C3ISR_ISF3_Msk       /*!< </spirit:description> */
#define HSEM_C3ISR_ISF4_Pos        (4U)
#define HSEM_C3ISR_ISF4_Msk        (0x1UL << HSEM_C3ISR_ISF4_Pos)   /*!< 0x00000010 */
#define HSEM_C3ISR_ISF4            HSEM_C3ISR_ISF4_Msk       /*!< </spirit:description> */
#define HSEM_C3ISR_ISF5_Pos        (5U)
#define HSEM_C3ISR_ISF5_Msk        (0x1UL << HSEM_C3ISR_ISF5_Pos)   /*!< 0x00000020 */
#define HSEM_C3ISR_ISF5            HSEM_C3ISR_ISF5_Msk       /*!< </spirit:description> */
#define HSEM_C3ISR_ISF6_Pos        (6U)
#define HSEM_C3ISR_ISF6_Msk        (0x1UL << HSEM_C3ISR_ISF6_Pos)   /*!< 0x00000040 */
#define HSEM_C3ISR_ISF6            HSEM_C3ISR_ISF6_Msk       /*!< </spirit:description> */
#define HSEM_C3ISR_ISF7_Pos        (7U)
#define HSEM_C3ISR_ISF7_Msk        (0x1UL << HSEM_C3ISR_ISF7_Pos)   /*!< 0x00000080 */
#define HSEM_C3ISR_ISF7            HSEM_C3ISR_ISF7_Msk       /*!< </spirit:description> */
#define HSEM_C3ISR_ISF8_Pos        (8U)
#define HSEM_C3ISR_ISF8_Msk        (0x1UL << HSEM_C3ISR_ISF8_Pos)   /*!< 0x00000100 */
#define HSEM_C3ISR_ISF8            HSEM_C3ISR_ISF8_Msk       /*!< </spirit:description> */
#define HSEM_C3ISR_ISF9_Pos        (9U)
#define HSEM_C3ISR_ISF9_Msk        (0x1UL << HSEM_C3ISR_ISF9_Pos)   /*!< 0x00000200 */
#define HSEM_C3ISR_ISF9            HSEM_C3ISR_ISF9_Msk       /*!< </spirit:description> */
#define HSEM_C3ISR_ISF10_Pos       (10U)
#define HSEM_C3ISR_ISF10_Msk       (0x1UL << HSEM_C3ISR_ISF10_Pos)    /*!< 0x00000400 */
#define HSEM_C3ISR_ISF10           HSEM_C3ISR_ISF10_Msk      /*!< </spirit:description> */
#define HSEM_C3ISR_ISF11_Pos       (11U)
#define HSEM_C3ISR_ISF11_Msk       (0x1UL << HSEM_C3ISR_ISF11_Pos)    /*!< 0x00000800 */
#define HSEM_C3ISR_ISF11           HSEM_C3ISR_ISF11_Msk      /*!< </spirit:description> */
#define HSEM_C3ISR_ISF12_Pos       (12U)
#define HSEM_C3ISR_ISF12_Msk       (0x1UL << HSEM_C3ISR_ISF12_Pos)    /*!< 0x00001000 */
#define HSEM_C3ISR_ISF12           HSEM_C3ISR_ISF12_Msk      /*!< </spirit:description> */
#define HSEM_C3ISR_ISF13_Pos       (13U)
#define HSEM_C3ISR_ISF13_Msk       (0x1UL << HSEM_C3ISR_ISF13_Pos)    /*!< 0x00002000 */
#define HSEM_C3ISR_ISF13           HSEM_C3ISR_ISF13_Msk      /*!< </spirit:description> */
#define HSEM_C3ISR_ISF14_Pos       (14U)
#define HSEM_C3ISR_ISF14_Msk       (0x1UL << HSEM_C3ISR_ISF14_Pos)    /*!< 0x00004000 */
#define HSEM_C3ISR_ISF14           HSEM_C3ISR_ISF14_Msk      /*!< </spirit:description> */
#define HSEM_C3ISR_ISF15_Pos       (15U)
#define HSEM_C3ISR_ISF15_Msk       (0x1UL << HSEM_C3ISR_ISF15_Pos)    /*!< 0x00008000 */
#define HSEM_C3ISR_ISF15           HSEM_C3ISR_ISF15_Msk      /*!< </spirit:description> */
#define HSEM_C3ISR_ISF16_Pos       (16U)
#define HSEM_C3ISR_ISF16_Msk       (0x1UL << HSEM_C3ISR_ISF16_Pos)    /*!< 0x00010000 */
#define HSEM_C3ISR_ISF16           HSEM_C3ISR_ISF16_Msk      /*!< </spirit:description> */
#define HSEM_C3ISR_ISF17_Pos       (17U)
#define HSEM_C3ISR_ISF17_Msk       (0x1UL << HSEM_C3ISR_ISF17_Pos)    /*!< 0x00020000 */
#define HSEM_C3ISR_ISF17           HSEM_C3ISR_ISF17_Msk      /*!< </spirit:description> */
#define HSEM_C3ISR_ISF18_Pos       (18U)
#define HSEM_C3ISR_ISF18_Msk       (0x1UL << HSEM_C3ISR_ISF18_Pos)    /*!< 0x00040000 */
#define HSEM_C3ISR_ISF18           HSEM_C3ISR_ISF18_Msk      /*!< </spirit:description> */
#define HSEM_C3ISR_ISF19_Pos       (19U)
#define HSEM_C3ISR_ISF19_Msk       (0x1UL << HSEM_C3ISR_ISF19_Pos)    /*!< 0x00080000 */
#define HSEM_C3ISR_ISF19           HSEM_C3ISR_ISF19_Msk      /*!< </spirit:description> */
#define HSEM_C3ISR_ISF20_Pos       (20U)
#define HSEM_C3ISR_ISF20_Msk       (0x1UL << HSEM_C3ISR_ISF20_Pos)    /*!< 0x00100000 */
#define HSEM_C3ISR_ISF20           HSEM_C3ISR_ISF20_Msk      /*!< </spirit:description> */
#define HSEM_C3ISR_ISF21_Pos       (21U)
#define HSEM_C3ISR_ISF21_Msk       (0x1UL << HSEM_C3ISR_ISF21_Pos)    /*!< 0x00200000 */
#define HSEM_C3ISR_ISF21           HSEM_C3ISR_ISF21_Msk      /*!< </spirit:description> */
#define HSEM_C3ISR_ISF22_Pos       (22U)
#define HSEM_C3ISR_ISF22_Msk       (0x1UL << HSEM_C3ISR_ISF22_Pos)    /*!< 0x00400000 */
#define HSEM_C3ISR_ISF22           HSEM_C3ISR_ISF22_Msk      /*!< </spirit:description> */
#define HSEM_C3ISR_ISF23_Pos       (23U)
#define HSEM_C3ISR_ISF23_Msk       (0x1UL << HSEM_C3ISR_ISF23_Pos)    /*!< 0x00800000 */
#define HSEM_C3ISR_ISF23           HSEM_C3ISR_ISF23_Msk      /*!< </spirit:description> */
#define HSEM_C3ISR_ISF24_Pos       (24U)
#define HSEM_C3ISR_ISF24_Msk       (0x1UL << HSEM_C3ISR_ISF24_Pos)    /*!< 0x01000000 */
#define HSEM_C3ISR_ISF24           HSEM_C3ISR_ISF24_Msk      /*!< </spirit:description> */
#define HSEM_C3ISR_ISF25_Pos       (25U)
#define HSEM_C3ISR_ISF25_Msk       (0x1UL << HSEM_C3ISR_ISF25_Pos)    /*!< 0x02000000 */
#define HSEM_C3ISR_ISF25           HSEM_C3ISR_ISF25_Msk      /*!< </spirit:description> */
#define HSEM_C3ISR_ISF26_Pos       (26U)
#define HSEM_C3ISR_ISF26_Msk       (0x1UL << HSEM_C3ISR_ISF26_Pos)    /*!< 0x04000000 */
#define HSEM_C3ISR_ISF26           HSEM_C3ISR_ISF26_Msk      /*!< </spirit:description> */
#define HSEM_C3ISR_ISF27_Pos       (27U)
#define HSEM_C3ISR_ISF27_Msk       (0x1UL << HSEM_C3ISR_ISF27_Pos)    /*!< 0x08000000 */
#define HSEM_C3ISR_ISF27           HSEM_C3ISR_ISF27_Msk      /*!< </spirit:description> */
#define HSEM_C3ISR_ISF28_Pos       (28U)
#define HSEM_C3ISR_ISF28_Msk       (0x1UL << HSEM_C3ISR_ISF28_Pos)    /*!< 0x10000000 */
#define HSEM_C3ISR_ISF28           HSEM_C3ISR_ISF28_Msk      /*!< </spirit:description> */
#define HSEM_C3ISR_ISF29_Pos       (29U)
#define HSEM_C3ISR_ISF29_Msk       (0x1UL << HSEM_C3ISR_ISF29_Pos)    /*!< 0x20000000 */
#define HSEM_C3ISR_ISF29           HSEM_C3ISR_ISF29_Msk      /*!< </spirit:description> */
#define HSEM_C3ISR_ISF30_Pos       (30U)
#define HSEM_C3ISR_ISF30_Msk       (0x1UL << HSEM_C3ISR_ISF30_Pos)    /*!< 0x40000000 */
#define HSEM_C3ISR_ISF30           HSEM_C3ISR_ISF30_Msk      /*!< </spirit:description> */
#define HSEM_C3ISR_ISF31_Pos       (31U)
#define HSEM_C3ISR_ISF31_Msk       (0x1UL << HSEM_C3ISR_ISF31_Pos)    /*!< 0x80000000 */
#define HSEM_C3ISR_ISF31           HSEM_C3ISR_ISF31_Msk      /*!< </spirit:description> */

/*****************  Bit definition for HSEM_C3MISR register  ******************/
#define HSEM_C3MISR_MISF0_Pos      (0U)
#define HSEM_C3MISR_MISF0_Msk      (0x1UL << HSEM_C3MISR_MISF0_Pos)     /*!< 0x00000001 */
#define HSEM_C3MISR_MISF0          HSEM_C3MISR_MISF0_Msk     /*!< </spirit:description> */
#define HSEM_C3MISR_MISF1_Pos      (1U)
#define HSEM_C3MISR_MISF1_Msk      (0x1UL << HSEM_C3MISR_MISF1_Pos)     /*!< 0x00000002 */
#define HSEM_C3MISR_MISF1          HSEM_C3MISR_MISF1_Msk     /*!< </spirit:description> */
#define HSEM_C3MISR_MISF2_Pos      (2U)
#define HSEM_C3MISR_MISF2_Msk      (0x1UL << HSEM_C3MISR_MISF2_Pos)     /*!< 0x00000004 */
#define HSEM_C3MISR_MISF2          HSEM_C3MISR_MISF2_Msk     /*!< </spirit:description> */
#define HSEM_C3MISR_MISF3_Pos      (3U)
#define HSEM_C3MISR_MISF3_Msk      (0x1UL << HSEM_C3MISR_MISF3_Pos)     /*!< 0x00000008 */
#define HSEM_C3MISR_MISF3          HSEM_C3MISR_MISF3_Msk     /*!< </spirit:description> */
#define HSEM_C3MISR_MISF4_Pos      (4U)
#define HSEM_C3MISR_MISF4_Msk      (0x1UL << HSEM_C3MISR_MISF4_Pos)     /*!< 0x00000010 */
#define HSEM_C3MISR_MISF4          HSEM_C3MISR_MISF4_Msk     /*!< </spirit:description> */
#define HSEM_C3MISR_MISF5_Pos      (5U)
#define HSEM_C3MISR_MISF5_Msk      (0x1UL << HSEM_C3MISR_MISF5_Pos)     /*!< 0x00000020 */
#define HSEM_C3MISR_MISF5          HSEM_C3MISR_MISF5_Msk     /*!< </spirit:description> */
#define HSEM_C3MISR_MISF6_Pos      (6U)
#define HSEM_C3MISR_MISF6_Msk      (0x1UL << HSEM_C3MISR_MISF6_Pos)     /*!< 0x00000040 */
#define HSEM_C3MISR_MISF6          HSEM_C3MISR_MISF6_Msk     /*!< </spirit:description> */
#define HSEM_C3MISR_MISF7_Pos      (7U)
#define HSEM_C3MISR_MISF7_Msk      (0x1UL << HSEM_C3MISR_MISF7_Pos)     /*!< 0x00000080 */
#define HSEM_C3MISR_MISF7          HSEM_C3MISR_MISF7_Msk     /*!< </spirit:description> */
#define HSEM_C3MISR_MISF8_Pos      (8U)
#define HSEM_C3MISR_MISF8_Msk      (0x1UL << HSEM_C3MISR_MISF8_Pos)     /*!< 0x00000100 */
#define HSEM_C3MISR_MISF8          HSEM_C3MISR_MISF8_Msk     /*!< </spirit:description> */
#define HSEM_C3MISR_MISF9_Pos      (9U)
#define HSEM_C3MISR_MISF9_Msk      (0x1UL << HSEM_C3MISR_MISF9_Pos)     /*!< 0x00000200 */
#define HSEM_C3MISR_MISF9          HSEM_C3MISR_MISF9_Msk     /*!< </spirit:description> */
#define HSEM_C3MISR_MISF10_Pos     (10U)
#define HSEM_C3MISR_MISF10_Msk     (0x1UL << HSEM_C3MISR_MISF10_Pos)      /*!< 0x00000400 */
#define HSEM_C3MISR_MISF10         HSEM_C3MISR_MISF10_Msk    /*!< </spirit:description> */
#define HSEM_C3MISR_MISF11_Pos     (11U)
#define HSEM_C3MISR_MISF11_Msk     (0x1UL << HSEM_C3MISR_MISF11_Pos)      /*!< 0x00000800 */
#define HSEM_C3MISR_MISF11         HSEM_C3MISR_MISF11_Msk    /*!< </spirit:description> */
#define HSEM_C3MISR_MISF12_Pos     (12U)
#define HSEM_C3MISR_MISF12_Msk     (0x1UL << HSEM_C3MISR_MISF12_Pos)      /*!< 0x00001000 */
#define HSEM_C3MISR_MISF12         HSEM_C3MISR_MISF12_Msk    /*!< </spirit:description> */
#define HSEM_C3MISR_MISF13_Pos     (13U)
#define HSEM_C3MISR_MISF13_Msk     (0x1UL << HSEM_C3MISR_MISF13_Pos)      /*!< 0x00002000 */
#define HSEM_C3MISR_MISF13         HSEM_C3MISR_MISF13_Msk    /*!< </spirit:description> */
#define HSEM_C3MISR_MISF14_Pos     (14U)
#define HSEM_C3MISR_MISF14_Msk     (0x1UL << HSEM_C3MISR_MISF14_Pos)      /*!< 0x00004000 */
#define HSEM_C3MISR_MISF14         HSEM_C3MISR_MISF14_Msk    /*!< </spirit:description> */
#define HSEM_C3MISR_MISF15_Pos     (15U)
#define HSEM_C3MISR_MISF15_Msk     (0x1UL << HSEM_C3MISR_MISF15_Pos)      /*!< 0x00008000 */
#define HSEM_C3MISR_MISF15         HSEM_C3MISR_MISF15_Msk    /*!< </spirit:description> */
#define HSEM_C3MISR_MISF16_Pos     (16U)
#define HSEM_C3MISR_MISF16_Msk     (0x1UL << HSEM_C3MISR_MISF16_Pos)      /*!< 0x00010000 */
#define HSEM_C3MISR_MISF16         HSEM_C3MISR_MISF16_Msk    /*!< </spirit:description> */
#define HSEM_C3MISR_MISF17_Pos     (17U)
#define HSEM_C3MISR_MISF17_Msk     (0x1UL << HSEM_C3MISR_MISF17_Pos)      /*!< 0x00020000 */
#define HSEM_C3MISR_MISF17         HSEM_C3MISR_MISF17_Msk    /*!< </spirit:description> */
#define HSEM_C3MISR_MISF18_Pos     (18U)
#define HSEM_C3MISR_MISF18_Msk     (0x1UL << HSEM_C3MISR_MISF18_Pos)      /*!< 0x00040000 */
#define HSEM_C3MISR_MISF18         HSEM_C3MISR_MISF18_Msk    /*!< </spirit:description> */
#define HSEM_C3MISR_MISF19_Pos     (19U)
#define HSEM_C3MISR_MISF19_Msk     (0x1UL << HSEM_C3MISR_MISF19_Pos)      /*!< 0x00080000 */
#define HSEM_C3MISR_MISF19         HSEM_C3MISR_MISF19_Msk    /*!< </spirit:description> */
#define HSEM_C3MISR_MISF20_Pos     (20U)
#define HSEM_C3MISR_MISF20_Msk     (0x1UL << HSEM_C3MISR_MISF20_Pos)      /*!< 0x00100000 */
#define HSEM_C3MISR_MISF20         HSEM_C3MISR_MISF20_Msk    /*!< </spirit:description> */
#define HSEM_C3MISR_MISF21_Pos     (21U)
#define HSEM_C3MISR_MISF21_Msk     (0x1UL << HSEM_C3MISR_MISF21_Pos)      /*!< 0x00200000 */
#define HSEM_C3MISR_MISF21         HSEM_C3MISR_MISF21_Msk    /*!< </spirit:description> */
#define HSEM_C3MISR_MISF22_Pos     (22U)
#define HSEM_C3MISR_MISF22_Msk     (0x1UL << HSEM_C3MISR_MISF22_Pos)      /*!< 0x00400000 */
#define HSEM_C3MISR_MISF22         HSEM_C3MISR_MISF22_Msk    /*!< </spirit:description> */
#define HSEM_C3MISR_MISF23_Pos     (23U)
#define HSEM_C3MISR_MISF23_Msk     (0x1UL << HSEM_C3MISR_MISF23_Pos)      /*!< 0x00800000 */
#define HSEM_C3MISR_MISF23         HSEM_C3MISR_MISF23_Msk    /*!< </spirit:description> */
#define HSEM_C3MISR_MISF24_Pos     (24U)
#define HSEM_C3MISR_MISF24_Msk     (0x1UL << HSEM_C3MISR_MISF24_Pos)      /*!< 0x01000000 */
#define HSEM_C3MISR_MISF24         HSEM_C3MISR_MISF24_Msk    /*!< </spirit:description> */
#define HSEM_C3MISR_MISF25_Pos     (25U)
#define HSEM_C3MISR_MISF25_Msk     (0x1UL << HSEM_C3MISR_MISF25_Pos)      /*!< 0x02000000 */
#define HSEM_C3MISR_MISF25         HSEM_C3MISR_MISF25_Msk    /*!< </spirit:description> */
#define HSEM_C3MISR_MISF26_Pos     (26U)
#define HSEM_C3MISR_MISF26_Msk     (0x1UL << HSEM_C3MISR_MISF26_Pos)      /*!< 0x04000000 */
#define HSEM_C3MISR_MISF26         HSEM_C3MISR_MISF26_Msk    /*!< </spirit:description> */
#define HSEM_C3MISR_MISF27_Pos     (27U)
#define HSEM_C3MISR_MISF27_Msk     (0x1UL << HSEM_C3MISR_MISF27_Pos)      /*!< 0x08000000 */
#define HSEM_C3MISR_MISF27         HSEM_C3MISR_MISF27_Msk    /*!< </spirit:description> */
#define HSEM_C3MISR_MISF28_Pos     (28U)
#define HSEM_C3MISR_MISF28_Msk     (0x1UL << HSEM_C3MISR_MISF28_Pos)      /*!< 0x10000000 */
#define HSEM_C3MISR_MISF28         HSEM_C3MISR_MISF28_Msk    /*!< </spirit:description> */
#define HSEM_C3MISR_MISF29_Pos     (29U)
#define HSEM_C3MISR_MISF29_Msk     (0x1UL << HSEM_C3MISR_MISF29_Pos)      /*!< 0x20000000 */
#define HSEM_C3MISR_MISF29         HSEM_C3MISR_MISF29_Msk    /*!< </spirit:description> */
#define HSEM_C3MISR_MISF30_Pos     (30U)
#define HSEM_C3MISR_MISF30_Msk     (0x1UL << HSEM_C3MISR_MISF30_Pos)      /*!< 0x40000000 */
#define HSEM_C3MISR_MISF30         HSEM_C3MISR_MISF30_Msk    /*!< </spirit:description> */
#define HSEM_C3MISR_MISF31_Pos     (31U)
#define HSEM_C3MISR_MISF31_Msk     (0x1UL << HSEM_C3MISR_MISF31_Pos)      /*!< 0x80000000 */
#define HSEM_C3MISR_MISF31         HSEM_C3MISR_MISF31_Msk    /*!< </spirit:description> */

/*******************  Bit definition for HSEM_CR register  ********************/
#define HSEM_CR_COREID_Pos         (8U)
#define HSEM_CR_COREID_Msk         (0xFFUL << HSEM_CR_COREID_Pos)   /*!< 0x0000FF00 */
#define HSEM_CR_COREID             HSEM_CR_COREID_Msk        /*!< </spirit:description> */
#define HSEM_CR_KEY_Pos            (16U)
#define HSEM_CR_KEY_Msk            (0xFFFFUL << HSEM_CR_KEY_Pos)  /*!< 0xFFFF0000 */
#define HSEM_CR_KEY                HSEM_CR_KEY_Msk           /*!< </spirit:description> */

/******************  Bit definition for HSEM_KEYR register  *******************/
#define HSEM_KEYR_KEY_Pos          (16U)
#define HSEM_KEYR_KEY_Msk          (0xFFFFUL << HSEM_KEYR_KEY_Pos)    /*!< 0xFFFF0000 */
#define HSEM_KEYR_KEY              HSEM_KEYR_KEY_Msk         /*!< </spirit:description> */

#define HSEM_BASE           0x44002C00UL 


#define HSEM                ((HSEM_TypeDef *) HSEM_BASE) 

#endif /* __SR5E1_HSEM_H */

