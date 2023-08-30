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

#ifndef __SR5E1_EXTI_H
#define __SR5E1_EXTI_H

/******************************************************************************/
/*                                                                            */
/*                                EXTI (EXTI)                                 */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO uint32_t RTSR1;          /*!< RTSR1    Address offset: 0x00 */
  __IO uint32_t FTSR1;          /*!< FTSR1    Address offset: 0x04 */
  __IO uint32_t SWIER1;         /*!< SWIER1   Address offset: 0x08 */
       uint32_t RESERVED0[5];   /*!< Reserved Address offset: 0x0C-0x1C */
  __IO uint32_t RTSR2;          /*!< RTSR2    Address offset: 0x20 */
  __IO uint32_t FTSR2;          /*!< FTSR2    Address offset: 0x24 */
  __IO uint32_t SWIER2;         /*!< SWIER2   Address offset: 0x28 */
       uint32_t RESERVED1[21];  /*!< Reserved Address offset: 0x2C-0x7C */
  __IO uint32_t C1IMR1;         /*!< C1IMR1   Address offset: 0x80 */
  __IO uint32_t C1EMR1;         /*!< C1EMR1   Address offset: 0x84 */
  __IO uint32_t C1PR1;          /*!< C1PR1    Address offset: 0x88 */
       uint32_t RESERVED2;      /*!< Reserved Address offset: 0x8C */
  __IO uint32_t C1IMR2;         /*!< C1IMR2   Address offset: 0x90 */
  __IO uint32_t C1EMR2;         /*!< C1EMR2   Address offset: 0x94 */
  __IO uint32_t C1PR2;          /*!< C1PR2    Address offset: 0x98 */
       uint32_t RESERVED3[9];   /*!< Reserved Address offset: 0x9C-0xBC */
  __IO uint32_t C2IMR1;         /*!< C2IMR1   Address offset: 0xC0 */
  __IO uint32_t C2EMR1;         /*!< C2EMR1   Address offset: 0xC4 */
  __IO uint32_t C2PR1;          /*!< C2PR1    Address offset: 0xC8 */
       uint32_t RESERVED4;      /*!< Reserved Address offset: 0xCC */
  __IO uint32_t C2IMR2;         /*!< C2IMR2   Address offset: 0xD0 */
  __IO uint32_t C2EMR2;         /*!< C2EMR2   Address offset: 0xD4 */
  __IO uint32_t C2PR2;          /*!< C2PR2    Address offset: 0xD8 */
} EXTI_TypeDef;


/******************  Bit definition for EXTI_RTSR1 register  ******************/
#define EXTI_RTSR1_TR0_Pos        (0U)
#define EXTI_RTSR1_TR0_Msk        (0x1UL << EXTI_RTSR1_TR0_Pos)   /*!< 0x00000001 */
#define EXTI_RTSR1_TR0            EXTI_RTSR1_TR0_Msk       /*!< </spirit:description> */
#define EXTI_RTSR1_TR1_Pos        (1U)
#define EXTI_RTSR1_TR1_Msk        (0x1UL << EXTI_RTSR1_TR1_Pos)   /*!< 0x00000002 */
#define EXTI_RTSR1_TR1            EXTI_RTSR1_TR1_Msk       /*!< </spirit:description> */
#define EXTI_RTSR1_TR2_Pos        (2U)
#define EXTI_RTSR1_TR2_Msk        (0x1UL << EXTI_RTSR1_TR2_Pos)   /*!< 0x00000004 */
#define EXTI_RTSR1_TR2            EXTI_RTSR1_TR2_Msk       /*!< </spirit:description> */
#define EXTI_RTSR1_TR3_Pos        (3U)
#define EXTI_RTSR1_TR3_Msk        (0x1UL << EXTI_RTSR1_TR3_Pos)   /*!< 0x00000008 */
#define EXTI_RTSR1_TR3            EXTI_RTSR1_TR3_Msk       /*!< </spirit:description> */
#define EXTI_RTSR1_TR4_Pos        (4U)
#define EXTI_RTSR1_TR4_Msk        (0x1UL << EXTI_RTSR1_TR4_Pos)   /*!< 0x00000010 */
#define EXTI_RTSR1_TR4            EXTI_RTSR1_TR4_Msk       /*!< </spirit:description> */
#define EXTI_RTSR1_TR5_Pos        (5U)
#define EXTI_RTSR1_TR5_Msk        (0x1UL << EXTI_RTSR1_TR5_Pos)   /*!< 0x00000020 */
#define EXTI_RTSR1_TR5            EXTI_RTSR1_TR5_Msk       /*!< </spirit:description> */
#define EXTI_RTSR1_TR6_Pos        (6U)
#define EXTI_RTSR1_TR6_Msk        (0x1UL << EXTI_RTSR1_TR6_Pos)   /*!< 0x00000040 */
#define EXTI_RTSR1_TR6            EXTI_RTSR1_TR6_Msk       /*!< </spirit:description> */
#define EXTI_RTSR1_TR7_Pos        (7U)
#define EXTI_RTSR1_TR7_Msk        (0x1UL << EXTI_RTSR1_TR7_Pos)   /*!< 0x00000080 */
#define EXTI_RTSR1_TR7            EXTI_RTSR1_TR7_Msk       /*!< </spirit:description> */
#define EXTI_RTSR1_TR8_Pos        (8U)
#define EXTI_RTSR1_TR8_Msk        (0x1UL << EXTI_RTSR1_TR8_Pos)   /*!< 0x00000100 */
#define EXTI_RTSR1_TR8            EXTI_RTSR1_TR8_Msk       /*!< </spirit:description> */
#define EXTI_RTSR1_TR9_Pos        (9U)
#define EXTI_RTSR1_TR9_Msk        (0x1UL << EXTI_RTSR1_TR9_Pos)   /*!< 0x00000200 */
#define EXTI_RTSR1_TR9            EXTI_RTSR1_TR9_Msk       /*!< </spirit:description> */
#define EXTI_RTSR1_TR10_Pos       (10U)
#define EXTI_RTSR1_TR10_Msk       (0x1UL << EXTI_RTSR1_TR10_Pos)    /*!< 0x00000400 */
#define EXTI_RTSR1_TR10           EXTI_RTSR1_TR10_Msk      /*!< </spirit:description> */
#define EXTI_RTSR1_TR11_Pos       (11U)
#define EXTI_RTSR1_TR11_Msk       (0x1UL << EXTI_RTSR1_TR11_Pos)    /*!< 0x00000800 */
#define EXTI_RTSR1_TR11           EXTI_RTSR1_TR11_Msk      /*!< </spirit:description> */
#define EXTI_RTSR1_TR12_Pos       (12U)
#define EXTI_RTSR1_TR12_Msk       (0x1UL << EXTI_RTSR1_TR12_Pos)    /*!< 0x00001000 */
#define EXTI_RTSR1_TR12           EXTI_RTSR1_TR12_Msk      /*!< </spirit:description> */
#define EXTI_RTSR1_TR13_Pos       (13U)
#define EXTI_RTSR1_TR13_Msk       (0x1UL << EXTI_RTSR1_TR13_Pos)    /*!< 0x00002000 */
#define EXTI_RTSR1_TR13           EXTI_RTSR1_TR13_Msk      /*!< </spirit:description> */
#define EXTI_RTSR1_TR14_Pos       (14U)
#define EXTI_RTSR1_TR14_Msk       (0x1UL << EXTI_RTSR1_TR14_Pos)    /*!< 0x00004000 */
#define EXTI_RTSR1_TR14           EXTI_RTSR1_TR14_Msk      /*!< </spirit:description> */
#define EXTI_RTSR1_TR15_Pos       (15U)
#define EXTI_RTSR1_TR15_Msk       (0x1UL << EXTI_RTSR1_TR15_Pos)    /*!< 0x00008000 */
#define EXTI_RTSR1_TR15           EXTI_RTSR1_TR15_Msk      /*!< </spirit:description> */
#define EXTI_RTSR1_TR18_Pos       (18U)
#define EXTI_RTSR1_TR18_Msk       (0x1UL << EXTI_RTSR1_TR18_Pos)    /*!< 0x00040000 */
#define EXTI_RTSR1_TR18           EXTI_RTSR1_TR18_Msk      /*!< </spirit:description> */
#define EXTI_RTSR1_TR20_Pos       (20U)
#define EXTI_RTSR1_TR20_Msk       (0x1UL << EXTI_RTSR1_TR20_Pos)    /*!< 0x00100000 */
#define EXTI_RTSR1_TR20           EXTI_RTSR1_TR20_Msk      /*!< </spirit:description> */
#define EXTI_RTSR1_TR21_Pos       (21U)
#define EXTI_RTSR1_TR21_Msk       (0x1UL << EXTI_RTSR1_TR21_Pos)    /*!< 0x00200000 */
#define EXTI_RTSR1_TR21           EXTI_RTSR1_TR21_Msk      /*!< </spirit:description> */
#define EXTI_RTSR1_TR22_Pos       (22U)
#define EXTI_RTSR1_TR22_Msk       (0x1UL << EXTI_RTSR1_TR22_Pos)    /*!< 0x00400000 */
#define EXTI_RTSR1_TR22           EXTI_RTSR1_TR22_Msk      /*!< </spirit:description> */
#define EXTI_RTSR1_TR29_Pos       (29U)
#define EXTI_RTSR1_TR29_Msk       (0x1UL << EXTI_RTSR1_TR29_Pos)    /*!< 0x20000000 */
#define EXTI_RTSR1_TR29           EXTI_RTSR1_TR29_Msk      /*!< </spirit:description> */
#define EXTI_RTSR1_TR30_Pos       (30U)
#define EXTI_RTSR1_TR30_Msk       (0x1UL << EXTI_RTSR1_TR30_Pos)    /*!< 0x40000000 */
#define EXTI_RTSR1_TR30           EXTI_RTSR1_TR30_Msk      /*!< </spirit:description> */
#define EXTI_RTSR1_TR31_Pos       (31U)
#define EXTI_RTSR1_TR31_Msk       (0x1UL << EXTI_RTSR1_TR31_Pos)    /*!< 0x80000000 */
#define EXTI_RTSR1_TR31           EXTI_RTSR1_TR31_Msk      /*!< </spirit:description> */

/******************  Bit definition for EXTI_FTSR1 register  ******************/
#define EXTI_FTSR1_TR0_Pos        (0U)
#define EXTI_FTSR1_TR0_Msk        (0x1UL << EXTI_FTSR1_TR0_Pos)   /*!< 0x00000001 */
#define EXTI_FTSR1_TR0            EXTI_FTSR1_TR0_Msk       /*!< </spirit:description> */
#define EXTI_FTSR1_TR1_Pos        (1U)
#define EXTI_FTSR1_TR1_Msk        (0x1UL << EXTI_FTSR1_TR1_Pos)   /*!< 0x00000002 */
#define EXTI_FTSR1_TR1            EXTI_FTSR1_TR1_Msk       /*!< </spirit:description> */
#define EXTI_FTSR1_TR2_Pos        (2U)
#define EXTI_FTSR1_TR2_Msk        (0x1UL << EXTI_FTSR1_TR2_Pos)   /*!< 0x00000004 */
#define EXTI_FTSR1_TR2            EXTI_FTSR1_TR2_Msk       /*!< </spirit:description> */
#define EXTI_FTSR1_TR3_Pos        (3U)
#define EXTI_FTSR1_TR3_Msk        (0x1UL << EXTI_FTSR1_TR3_Pos)   /*!< 0x00000008 */
#define EXTI_FTSR1_TR3            EXTI_FTSR1_TR3_Msk       /*!< </spirit:description> */
#define EXTI_FTSR1_TR4_Pos        (4U)
#define EXTI_FTSR1_TR4_Msk        (0x1UL << EXTI_FTSR1_TR4_Pos)   /*!< 0x00000010 */
#define EXTI_FTSR1_TR4            EXTI_FTSR1_TR4_Msk       /*!< </spirit:description> */
#define EXTI_FTSR1_TR5_Pos        (5U)
#define EXTI_FTSR1_TR5_Msk        (0x1UL << EXTI_FTSR1_TR5_Pos)   /*!< 0x00000020 */
#define EXTI_FTSR1_TR5            EXTI_FTSR1_TR5_Msk       /*!< </spirit:description> */
#define EXTI_FTSR1_TR6_Pos        (6U)
#define EXTI_FTSR1_TR6_Msk        (0x1UL << EXTI_FTSR1_TR6_Pos)   /*!< 0x00000040 */
#define EXTI_FTSR1_TR6            EXTI_FTSR1_TR6_Msk       /*!< </spirit:description> */
#define EXTI_FTSR1_TR7_Pos        (7U)
#define EXTI_FTSR1_TR7_Msk        (0x1UL << EXTI_FTSR1_TR7_Pos)   /*!< 0x00000080 */
#define EXTI_FTSR1_TR7            EXTI_FTSR1_TR7_Msk       /*!< </spirit:description> */
#define EXTI_FTSR1_TR8_Pos        (8U)
#define EXTI_FTSR1_TR8_Msk        (0x1UL << EXTI_FTSR1_TR8_Pos)   /*!< 0x00000100 */
#define EXTI_FTSR1_TR8            EXTI_FTSR1_TR8_Msk       /*!< </spirit:description> */
#define EXTI_FTSR1_TR9_Pos        (9U)
#define EXTI_FTSR1_TR9_Msk        (0x1UL << EXTI_FTSR1_TR9_Pos)   /*!< 0x00000200 */
#define EXTI_FTSR1_TR9            EXTI_FTSR1_TR9_Msk       /*!< </spirit:description> */
#define EXTI_FTSR1_TR10_Pos       (10U)
#define EXTI_FTSR1_TR10_Msk       (0x1UL << EXTI_FTSR1_TR10_Pos)    /*!< 0x00000400 */
#define EXTI_FTSR1_TR10           EXTI_FTSR1_TR10_Msk      /*!< </spirit:description> */
#define EXTI_FTSR1_TR11_Pos       (11U)
#define EXTI_FTSR1_TR11_Msk       (0x1UL << EXTI_FTSR1_TR11_Pos)    /*!< 0x00000800 */
#define EXTI_FTSR1_TR11           EXTI_FTSR1_TR11_Msk      /*!< </spirit:description> */
#define EXTI_FTSR1_TR12_Pos       (12U)
#define EXTI_FTSR1_TR12_Msk       (0x1UL << EXTI_FTSR1_TR12_Pos)    /*!< 0x00001000 */
#define EXTI_FTSR1_TR12           EXTI_FTSR1_TR12_Msk      /*!< </spirit:description> */
#define EXTI_FTSR1_TR13_Pos       (13U)
#define EXTI_FTSR1_TR13_Msk       (0x1UL << EXTI_FTSR1_TR13_Pos)    /*!< 0x00002000 */
#define EXTI_FTSR1_TR13           EXTI_FTSR1_TR13_Msk      /*!< </spirit:description> */
#define EXTI_FTSR1_TR14_Pos       (14U)
#define EXTI_FTSR1_TR14_Msk       (0x1UL << EXTI_FTSR1_TR14_Pos)    /*!< 0x00004000 */
#define EXTI_FTSR1_TR14           EXTI_FTSR1_TR14_Msk      /*!< </spirit:description> */
#define EXTI_FTSR1_TR15_Pos       (15U)
#define EXTI_FTSR1_TR15_Msk       (0x1UL << EXTI_FTSR1_TR15_Pos)    /*!< 0x00008000 */
#define EXTI_FTSR1_TR15           EXTI_FTSR1_TR15_Msk      /*!< </spirit:description> */
#define EXTI_FTSR1_TR18_Pos       (18U)
#define EXTI_FTSR1_TR18_Msk       (0x1UL << EXTI_FTSR1_TR18_Pos)    /*!< 0x00040000 */
#define EXTI_FTSR1_TR18           EXTI_FTSR1_TR18_Msk      /*!< </spirit:description> */
#define EXTI_FTSR1_TR20_Pos       (20U)
#define EXTI_FTSR1_TR20_Msk       (0x1UL << EXTI_FTSR1_TR20_Pos)    /*!< 0x00100000 */
#define EXTI_FTSR1_TR20           EXTI_FTSR1_TR20_Msk      /*!< </spirit:description> */
#define EXTI_FTSR1_TR21_Pos       (21U)
#define EXTI_FTSR1_TR21_Msk       (0x1UL << EXTI_FTSR1_TR21_Pos)    /*!< 0x00200000 */
#define EXTI_FTSR1_TR21           EXTI_FTSR1_TR21_Msk      /*!< </spirit:description> */
#define EXTI_FTSR1_TR22_Pos       (22U)
#define EXTI_FTSR1_TR22_Msk       (0x1UL << EXTI_FTSR1_TR22_Pos)    /*!< 0x00400000 */
#define EXTI_FTSR1_TR22           EXTI_FTSR1_TR22_Msk      /*!< </spirit:description> */
#define EXTI_FTSR1_TR29_Pos       (29U)
#define EXTI_FTSR1_TR29_Msk       (0x1UL << EXTI_FTSR1_TR29_Pos)    /*!< 0x20000000 */
#define EXTI_FTSR1_TR29           EXTI_FTSR1_TR29_Msk      /*!< </spirit:description> */
#define EXTI_FTSR1_TR30_Pos       (30U)
#define EXTI_FTSR1_TR30_Msk       (0x1UL << EXTI_FTSR1_TR30_Pos)    /*!< 0x40000000 */
#define EXTI_FTSR1_TR30           EXTI_FTSR1_TR30_Msk      /*!< </spirit:description> */
#define EXTI_FTSR1_TR31_Pos       (31U)
#define EXTI_FTSR1_TR31_Msk       (0x1UL << EXTI_FTSR1_TR31_Pos)    /*!< 0x80000000 */
#define EXTI_FTSR1_TR31           EXTI_FTSR1_TR31_Msk      /*!< </spirit:description> */

/*****************  Bit definition for EXTI_SWIER1 register  ******************/
#define EXTI_SWIER1_SWIER0_Pos    (0U)
#define EXTI_SWIER1_SWIER0_Msk    (0x1UL << EXTI_SWIER1_SWIER0_Pos)       /*!< 0x00000001 */
#define EXTI_SWIER1_SWIER0        EXTI_SWIER1_SWIER0_Msk   /*!< </spirit:description> */
#define EXTI_SWIER1_SWIER1_Pos    (1U)
#define EXTI_SWIER1_SWIER1_Msk    (0x1UL << EXTI_SWIER1_SWIER1_Pos)       /*!< 0x00000002 */
#define EXTI_SWIER1_SWIER1        EXTI_SWIER1_SWIER1_Msk   /*!< </spirit:description> */
#define EXTI_SWIER1_SWIER2_Pos    (2U)
#define EXTI_SWIER1_SWIER2_Msk    (0x1UL << EXTI_SWIER1_SWIER2_Pos)       /*!< 0x00000004 */
#define EXTI_SWIER1_SWIER2        EXTI_SWIER1_SWIER2_Msk   /*!< </spirit:description> */
#define EXTI_SWIER1_SWIER3_Pos    (3U)
#define EXTI_SWIER1_SWIER3_Msk    (0x1UL << EXTI_SWIER1_SWIER3_Pos)       /*!< 0x00000008 */
#define EXTI_SWIER1_SWIER3        EXTI_SWIER1_SWIER3_Msk   /*!< </spirit:description> */
#define EXTI_SWIER1_SWIER4_Pos    (4U)
#define EXTI_SWIER1_SWIER4_Msk    (0x1UL << EXTI_SWIER1_SWIER4_Pos)       /*!< 0x00000010 */
#define EXTI_SWIER1_SWIER4        EXTI_SWIER1_SWIER4_Msk   /*!< </spirit:description> */
#define EXTI_SWIER1_SWIER5_Pos    (5U)
#define EXTI_SWIER1_SWIER5_Msk    (0x1UL << EXTI_SWIER1_SWIER5_Pos)       /*!< 0x00000020 */
#define EXTI_SWIER1_SWIER5        EXTI_SWIER1_SWIER5_Msk   /*!< </spirit:description> */
#define EXTI_SWIER1_SWIER6_Pos    (6U)
#define EXTI_SWIER1_SWIER6_Msk    (0x1UL << EXTI_SWIER1_SWIER6_Pos)       /*!< 0x00000040 */
#define EXTI_SWIER1_SWIER6        EXTI_SWIER1_SWIER6_Msk   /*!< </spirit:description> */
#define EXTI_SWIER1_SWIER7_Pos    (7U)
#define EXTI_SWIER1_SWIER7_Msk    (0x1UL << EXTI_SWIER1_SWIER7_Pos)       /*!< 0x00000080 */
#define EXTI_SWIER1_SWIER7        EXTI_SWIER1_SWIER7_Msk   /*!< </spirit:description> */
#define EXTI_SWIER1_SWIER8_Pos    (8U)
#define EXTI_SWIER1_SWIER8_Msk    (0x1UL << EXTI_SWIER1_SWIER8_Pos)       /*!< 0x00000100 */
#define EXTI_SWIER1_SWIER8        EXTI_SWIER1_SWIER8_Msk   /*!< </spirit:description> */
#define EXTI_SWIER1_SWIER9_Pos    (9U)
#define EXTI_SWIER1_SWIER9_Msk    (0x1UL << EXTI_SWIER1_SWIER9_Pos)       /*!< 0x00000200 */
#define EXTI_SWIER1_SWIER9        EXTI_SWIER1_SWIER9_Msk   /*!< </spirit:description> */
#define EXTI_SWIER1_SWIER10_Pos   (10U)
#define EXTI_SWIER1_SWIER10_Msk   (0x1UL << EXTI_SWIER1_SWIER10_Pos)        /*!< 0x00000400 */
#define EXTI_SWIER1_SWIER10       EXTI_SWIER1_SWIER10_Msk  /*!< </spirit:description> */
#define EXTI_SWIER1_SWIER11_Pos   (11U)
#define EXTI_SWIER1_SWIER11_Msk   (0x1UL << EXTI_SWIER1_SWIER11_Pos)        /*!< 0x00000800 */
#define EXTI_SWIER1_SWIER11       EXTI_SWIER1_SWIER11_Msk  /*!< </spirit:description> */
#define EXTI_SWIER1_SWIER12_Pos   (12U)
#define EXTI_SWIER1_SWIER12_Msk   (0x1UL << EXTI_SWIER1_SWIER12_Pos)        /*!< 0x00001000 */
#define EXTI_SWIER1_SWIER12       EXTI_SWIER1_SWIER12_Msk  /*!< </spirit:description> */
#define EXTI_SWIER1_SWIER13_Pos   (13U)
#define EXTI_SWIER1_SWIER13_Msk   (0x1UL << EXTI_SWIER1_SWIER13_Pos)        /*!< 0x00002000 */
#define EXTI_SWIER1_SWIER13       EXTI_SWIER1_SWIER13_Msk  /*!< </spirit:description> */
#define EXTI_SWIER1_SWIER14_Pos   (14U)
#define EXTI_SWIER1_SWIER14_Msk   (0x1UL << EXTI_SWIER1_SWIER14_Pos)        /*!< 0x00004000 */
#define EXTI_SWIER1_SWIER14       EXTI_SWIER1_SWIER14_Msk  /*!< </spirit:description> */
#define EXTI_SWIER1_SWIER15_Pos   (15U)
#define EXTI_SWIER1_SWIER15_Msk   (0x1UL << EXTI_SWIER1_SWIER15_Pos)        /*!< 0x00008000 */
#define EXTI_SWIER1_SWIER15       EXTI_SWIER1_SWIER15_Msk  /*!< </spirit:description> */
#define EXTI_SWIER1_SWIER18_Pos   (18U)
#define EXTI_SWIER1_SWIER18_Msk   (0x1UL << EXTI_SWIER1_SWIER18_Pos)        /*!< 0x00040000 */
#define EXTI_SWIER1_SWIER18       EXTI_SWIER1_SWIER18_Msk  /*!< </spirit:description> */
#define EXTI_SWIER1_SWIER20_Pos   (20U)
#define EXTI_SWIER1_SWIER20_Msk   (0x1UL << EXTI_SWIER1_SWIER20_Pos)        /*!< 0x00100000 */
#define EXTI_SWIER1_SWIER20       EXTI_SWIER1_SWIER20_Msk  /*!< </spirit:description> */
#define EXTI_SWIER1_SWIER21_Pos   (21U)
#define EXTI_SWIER1_SWIER21_Msk   (0x1UL << EXTI_SWIER1_SWIER21_Pos)        /*!< 0x00200000 */
#define EXTI_SWIER1_SWIER21       EXTI_SWIER1_SWIER21_Msk  /*!< </spirit:description> */
#define EXTI_SWIER1_SWIER22_Pos   (22U)
#define EXTI_SWIER1_SWIER22_Msk   (0x1UL << EXTI_SWIER1_SWIER22_Pos)        /*!< 0x00400000 */
#define EXTI_SWIER1_SWIER22       EXTI_SWIER1_SWIER22_Msk  /*!< </spirit:description> */
#define EXTI_SWIER1_SWIER29_Pos   (29U)
#define EXTI_SWIER1_SWIER29_Msk   (0x1UL << EXTI_SWIER1_SWIER29_Pos)        /*!< 0x20000000 */
#define EXTI_SWIER1_SWIER29       EXTI_SWIER1_SWIER29_Msk  /*!< </spirit:description> */
#define EXTI_SWIER1_SWIER30_Pos   (30U)
#define EXTI_SWIER1_SWIER30_Msk   (0x1UL << EXTI_SWIER1_SWIER30_Pos)        /*!< 0x40000000 */
#define EXTI_SWIER1_SWIER30       EXTI_SWIER1_SWIER30_Msk  /*!< </spirit:description> */
#define EXTI_SWIER1_SWIER31_Pos   (31U)
#define EXTI_SWIER1_SWIER31_Msk   (0x1UL << EXTI_SWIER1_SWIER31_Pos)        /*!< 0x80000000 */
#define EXTI_SWIER1_SWIER31       EXTI_SWIER1_SWIER31_Msk  /*!< </spirit:description> */

/******************  Bit definition for EXTI_RTSR2 register  ******************/
#define EXTI_RTSR2_TR32_Pos       (0U)
#define EXTI_RTSR2_TR32_Msk       (0x1UL << EXTI_RTSR2_TR32_Pos)    /*!< 0x00000001 */
#define EXTI_RTSR2_TR32           EXTI_RTSR2_TR32_Msk      /*!< </spirit:description> */
#define EXTI_RTSR2_TR33_Pos       (1U)
#define EXTI_RTSR2_TR33_Msk       (0x1UL << EXTI_RTSR2_TR33_Pos)    /*!< 0x00000002 */
#define EXTI_RTSR2_TR33           EXTI_RTSR2_TR33_Msk      /*!< </spirit:description> */
#define EXTI_RTSR2_TR34_Pos       (2U)
#define EXTI_RTSR2_TR34_Msk       (0x1UL << EXTI_RTSR2_TR34_Pos)    /*!< 0x00000004 */
#define EXTI_RTSR2_TR34           EXTI_RTSR2_TR34_Msk      /*!< </spirit:description> */

/******************  Bit definition for EXTI_FTSR2 register  ******************/
#define EXTI_FTSR2_TR32_Pos       (0U)
#define EXTI_FTSR2_TR32_Msk       (0x1UL << EXTI_FTSR2_TR32_Pos)    /*!< 0x00000001 */
#define EXTI_FTSR2_TR32           EXTI_FTSR2_TR32_Msk      /*!< </spirit:description> */
#define EXTI_FTSR2_TR33_Pos       (1U)
#define EXTI_FTSR2_TR33_Msk       (0x1UL << EXTI_FTSR2_TR33_Pos)    /*!< 0x00000002 */
#define EXTI_FTSR2_TR33           EXTI_FTSR2_TR33_Msk      /*!< </spirit:description> */
#define EXTI_FTSR2_TR34_Pos       (2U)
#define EXTI_FTSR2_TR34_Msk       (0x1UL << EXTI_FTSR2_TR34_Pos)    /*!< 0x00000004 */
#define EXTI_FTSR2_TR34           EXTI_FTSR2_TR34_Msk      /*!< </spirit:description> */

/*****************  Bit definition for EXTI_SWIER2 register  ******************/
#define EXTI_SWIER2_SWIER32_Pos   (0U)
#define EXTI_SWIER2_SWIER32_Msk   (0x1UL << EXTI_SWIER2_SWIER32_Pos)         /*!< 0x00000001 */
#define EXTI_SWIER2_SWIER32       EXTI_SWIER2_SWIER32_Msk  /*!< </spirit:description> */
#define EXTI_SWIER2_SWIER33_Pos   (1U)
#define EXTI_SWIER2_SWIER33_Msk   (0x1UL << EXTI_SWIER2_SWIER33_Pos)         /*!< 0x00000002 */
#define EXTI_SWIER2_SWIER33       EXTI_SWIER2_SWIER33_Msk  /*!< </spirit:description> */
#define EXTI_SWIER2_SWIER34_Pos   (2U)
#define EXTI_SWIER2_SWIER34_Msk   (0x1UL << EXTI_SWIER2_SWIER34_Pos)         /*!< 0x00000004 */
#define EXTI_SWIER2_SWIER34       EXTI_SWIER2_SWIER34_Msk  /*!< </spirit:description> */

/*****************  Bit definition for EXTI_IMR1 register  ******************/
#define EXTI_IMR1_MR0_Pos         (0U)
#define EXTI_IMR1_MR0_Msk         (0x1UL << EXTI_IMR1_MR0_Pos)     /*!< 0x00000001 */
#define EXTI_IMR1_MR0             EXTI_IMR1_MR0_Msk      /*!< </spirit:description> */
#define EXTI_IMR1_MR1_Pos         (1U)
#define EXTI_IMR1_MR1_Msk         (0x1UL << EXTI_IMR1_MR1_Pos)     /*!< 0x00000002 */
#define EXTI_IMR1_MR1             EXTI_IMR1_MR1_Msk      /*!< </spirit:description> */
#define EXTI_IMR1_MR2_Pos         (2U)
#define EXTI_IMR1_MR2_Msk         (0x1UL << EXTI_IMR1_MR2_Pos)     /*!< 0x00000004 */
#define EXTI_IMR1_MR2             EXTI_IMR1_MR2_Msk      /*!< </spirit:description> */
#define EXTI_IMR1_MR3_Pos         (3U)
#define EXTI_IMR1_MR3_Msk         (0x1UL << EXTI_IMR1_MR3_Pos)     /*!< 0x00000008 */
#define EXTI_IMR1_MR3             EXTI_IMR1_MR3_Msk      /*!< </spirit:description> */
#define EXTI_IMR1_MR4_Pos         (4U)
#define EXTI_IMR1_MR4_Msk         (0x1UL << EXTI_IMR1_MR4_Pos)     /*!< 0x00000010 */
#define EXTI_IMR1_MR4             EXTI_IMR1_MR4_Msk      /*!< </spirit:description> */
#define EXTI_IMR1_MR5_Pos         (5U)
#define EXTI_IMR1_MR5_Msk         (0x1UL << EXTI_IMR1_MR5_Pos)     /*!< 0x00000020 */
#define EXTI_IMR1_MR5             EXTI_IMR1_MR5_Msk      /*!< </spirit:description> */
#define EXTI_IMR1_MR6_Pos         (6U)
#define EXTI_IMR1_MR6_Msk         (0x1UL << EXTI_IMR1_MR6_Pos)     /*!< 0x00000040 */
#define EXTI_IMR1_MR6             EXTI_IMR1_MR6_Msk      /*!< </spirit:description> */
#define EXTI_IMR1_MR7_Pos         (7U)
#define EXTI_IMR1_MR7_Msk         (0x1UL << EXTI_IMR1_MR7_Pos)     /*!< 0x00000080 */
#define EXTI_IMR1_MR7             EXTI_IMR1_MR7_Msk      /*!< </spirit:description> */
#define EXTI_IMR1_MR8_Pos         (8U)
#define EXTI_IMR1_MR8_Msk         (0x1UL << EXTI_IMR1_MR8_Pos)     /*!< 0x00000100 */
#define EXTI_IMR1_MR8             EXTI_IMR1_MR8_Msk      /*!< </spirit:description> */
#define EXTI_IMR1_MR9_Pos         (9U)
#define EXTI_IMR1_MR9_Msk         (0x1UL << EXTI_IMR1_MR9_Pos)     /*!< 0x00000200 */
#define EXTI_IMR1_MR9             EXTI_IMR1_MR9_Msk      /*!< </spirit:description> */
#define EXTI_IMR1_MR10_Pos        (10U)
#define EXTI_IMR1_MR10_Msk        (0x1UL << EXTI_IMR1_MR10_Pos)      /*!< 0x00000400 */
#define EXTI_IMR1_MR10            EXTI_IMR1_MR10_Msk     /*!< </spirit:description> */
#define EXTI_IMR1_MR11_Pos        (11U)
#define EXTI_IMR1_MR11_Msk        (0x1UL << EXTI_IMR1_MR11_Pos)      /*!< 0x00000800 */
#define EXTI_IMR1_MR11            EXTI_IMR1_MR11_Msk     /*!< </spirit:description> */
#define EXTI_IMR1_MR12_Pos        (12U)
#define EXTI_IMR1_MR12_Msk        (0x1UL << EXTI_IMR1_MR12_Pos)      /*!< 0x00001000 */
#define EXTI_IMR1_MR12            EXTI_IMR1_MR12_Msk     /*!< </spirit:description> */
#define EXTI_IMR1_MR13_Pos        (13U)
#define EXTI_IMR1_MR13_Msk        (0x1UL << EXTI_IMR1_MR13_Pos)      /*!< 0x00002000 */
#define EXTI_IMR1_MR13            EXTI_IMR1_MR13_Msk     /*!< </spirit:description> */
#define EXTI_IMR1_MR14_Pos        (14U)
#define EXTI_IMR1_MR14_Msk        (0x1UL << EXTI_IMR1_MR14_Pos)      /*!< 0x00004000 */
#define EXTI_IMR1_MR14            EXTI_IMR1_MR14_Msk     /*!< </spirit:description> */
#define EXTI_IMR1_MR15_Pos        (15U)
#define EXTI_IMR1_MR15_Msk        (0x1UL << EXTI_IMR1_MR15_Pos)      /*!< 0x00008000 */
#define EXTI_IMR1_MR15            EXTI_IMR1_MR15_Msk     /*!< </spirit:description> */
#define EXTI_IMR1_MR18_Pos        (18U)
#define EXTI_IMR1_MR18_Msk        (0x1UL << EXTI_IMR1_MR18_Pos)      /*!< 0x00040000 */
#define EXTI_IMR1_MR18            EXTI_IMR1_MR18_Msk     /*!< </spirit:description> */
#define EXTI_IMR1_MR20_Pos        (20U)
#define EXTI_IMR1_MR20_Msk        (0x1UL << EXTI_IMR1_MR20_Pos)      /*!< 0x00100000 */
#define EXTI_IMR1_MR20            EXTI_IMR1_MR20_Msk     /*!< </spirit:description> */
#define EXTI_IMR1_MR21_Pos        (21U)
#define EXTI_IMR1_MR21_Msk        (0x1UL << EXTI_IMR1_MR21_Pos)      /*!< 0x00200000 */
#define EXTI_IMR1_MR21            EXTI_IMR1_MR21_Msk     /*!< </spirit:description> */
#define EXTI_IMR1_MR22_Pos        (22U)
#define EXTI_IMR1_MR22_Msk        (0x1UL << EXTI_IMR1_MR22_Pos)      /*!< 0x00400000 */
#define EXTI_IMR1_MR22            EXTI_IMR1_MR22_Msk     /*!< </spirit:description> */
#define EXTI_IMR1_MR23_Pos        (23U)
#define EXTI_IMR1_MR23_Msk        (0x1UL << EXTI_IMR1_MR23_Pos)      /*!< 0x00800000 */
#define EXTI_IMR1_MR23            EXTI_IMR1_MR23_Msk     /*!< </spirit:description> */
#define EXTI_IMR1_MR24_Pos        (24U)
#define EXTI_IMR1_MR24_Msk        (0x1UL << EXTI_IMR1_MR24_Pos)      /*!< 0x01000000 */
#define EXTI_IMR1_MR24            EXTI_IMR1_MR24_Msk     /*!< </spirit:description> */
#define EXTI_IMR1_MR25_Pos        (25U)
#define EXTI_IMR1_MR25_Msk        (0x1UL << EXTI_IMR1_MR25_Pos)      /*!< 0x02000000 */
#define EXTI_IMR1_MR25            EXTI_IMR1_MR25_Msk     /*!< </spirit:description> */
#define EXTI_IMR1_MR26_Pos        (26U)
#define EXTI_IMR1_MR26_Msk        (0x1UL << EXTI_IMR1_MR26_Pos)      /*!< 0x04000000 */
#define EXTI_IMR1_MR26            EXTI_IMR1_MR26_Msk     /*!< </spirit:description> */
#define EXTI_IMR1_MR28_Pos        (28U)
#define EXTI_IMR1_MR28_Msk        (0x1UL << EXTI_IMR1_MR28_Pos)      /*!< 0x10000000 */
#define EXTI_IMR1_MR28            EXTI_IMR1_MR28_Msk     /*!< </spirit:description> */
#define EXTI_IMR1_MR29_Pos        (29U)
#define EXTI_IMR1_MR29_Msk        (0x1UL << EXTI_IMR1_MR29_Pos)      /*!< 0x20000000 */
#define EXTI_IMR1_MR29            EXTI_IMR1_MR29_Msk     /*!< </spirit:description> */
#define EXTI_IMR1_MR30_Pos        (30U)
#define EXTI_IMR1_MR30_Msk        (0x1UL << EXTI_IMR1_MR30_Pos)      /*!< 0x40000000 */
#define EXTI_IMR1_MR30            EXTI_IMR1_MR30_Msk     /*!< </spirit:description> */
#define EXTI_IMR1_MR31_Pos        (31U)
#define EXTI_IMR1_MR31_Msk        (0x1UL << EXTI_IMR1_MR31_Pos)      /*!< 0x80000000 */
#define EXTI_IMR1_MR31            EXTI_IMR1_MR31_Msk     /*!< </spirit:description> */

/*****************  Bit definition for EXTI_EMR1 register  ******************/
#define EXTI_EMR1_MR0_Pos         (0U)
#define EXTI_EMR1_MR0_Msk         (0x1UL << EXTI_EMR1_MR0_Pos)     /*!< 0x00000001 */
#define EXTI_EMR1_MR0             EXTI_EMR1_MR0_Msk      /*!< </spirit:description> */
#define EXTI_EMR1_MR1_Pos         (1U)
#define EXTI_EMR1_MR1_Msk         (0x1UL << EXTI_EMR1_MR1_Pos)     /*!< 0x00000002 */
#define EXTI_EMR1_MR1             EXTI_EMR1_MR1_Msk      /*!< </spirit:description> */
#define EXTI_EMR1_MR2_Pos         (2U)
#define EXTI_EMR1_MR2_Msk         (0x1UL << EXTI_EMR1_MR2_Pos)     /*!< 0x00000004 */
#define EXTI_EMR1_MR2             EXTI_EMR1_MR2_Msk      /*!< </spirit:description> */
#define EXTI_EMR1_MR3_Pos         (3U)
#define EXTI_EMR1_MR3_Msk         (0x1UL << EXTI_EMR1_MR3_Pos)     /*!< 0x00000008 */
#define EXTI_EMR1_MR3             EXTI_EMR1_MR3_Msk      /*!< </spirit:description> */
#define EXTI_EMR1_MR4_Pos         (4U)
#define EXTI_EMR1_MR4_Msk         (0x1UL << EXTI_EMR1_MR4_Pos)     /*!< 0x00000010 */
#define EXTI_EMR1_MR4             EXTI_EMR1_MR4_Msk      /*!< </spirit:description> */
#define EXTI_EMR1_MR5_Pos         (5U)
#define EXTI_EMR1_MR5_Msk         (0x1UL << EXTI_EMR1_MR5_Pos)     /*!< 0x00000020 */
#define EXTI_EMR1_MR5             EXTI_EMR1_MR5_Msk      /*!< </spirit:description> */
#define EXTI_EMR1_MR6_Pos         (6U)
#define EXTI_EMR1_MR6_Msk         (0x1UL << EXTI_EMR1_MR6_Pos)     /*!< 0x00000040 */
#define EXTI_EMR1_MR6             EXTI_EMR1_MR6_Msk      /*!< </spirit:description> */
#define EXTI_EMR1_MR7_Pos         (7U)
#define EXTI_EMR1_MR7_Msk         (0x1UL << EXTI_EMR1_MR7_Pos)     /*!< 0x00000080 */
#define EXTI_EMR1_MR7             EXTI_EMR1_MR7_Msk      /*!< </spirit:description> */
#define EXTI_EMR1_MR8_Pos         (8U)
#define EXTI_EMR1_MR8_Msk         (0x1UL << EXTI_EMR1_MR8_Pos)     /*!< 0x00000100 */
#define EXTI_EMR1_MR8             EXTI_EMR1_MR8_Msk      /*!< </spirit:description> */
#define EXTI_EMR1_MR9_Pos         (9U)
#define EXTI_EMR1_MR9_Msk         (0x1UL << EXTI_EMR1_MR9_Pos)     /*!< 0x00000200 */
#define EXTI_EMR1_MR9             EXTI_EMR1_MR9_Msk      /*!< </spirit:description> */
#define EXTI_EMR1_MR10_Pos        (10U)
#define EXTI_EMR1_MR10_Msk        (0x1UL << EXTI_EMR1_MR10_Pos)      /*!< 0x00000400 */
#define EXTI_EMR1_MR10            EXTI_EMR1_MR10_Msk     /*!< </spirit:description> */
#define EXTI_EMR1_MR11_Pos        (11U)
#define EXTI_EMR1_MR11_Msk        (0x1UL << EXTI_EMR1_MR11_Pos)      /*!< 0x00000800 */
#define EXTI_EMR1_MR11            EXTI_EMR1_MR11_Msk     /*!< </spirit:description> */
#define EXTI_EMR1_MR12_Pos        (12U)
#define EXTI_EMR1_MR12_Msk        (0x1UL << EXTI_EMR1_MR12_Pos)      /*!< 0x00001000 */
#define EXTI_EMR1_MR12            EXTI_EMR1_MR12_Msk     /*!< </spirit:description> */
#define EXTI_EMR1_MR13_Pos        (13U)
#define EXTI_EMR1_MR13_Msk        (0x1UL << EXTI_EMR1_MR13_Pos)      /*!< 0x00002000 */
#define EXTI_EMR1_MR13            EXTI_EMR1_MR13_Msk     /*!< </spirit:description> */
#define EXTI_EMR1_MR14_Pos        (14U)
#define EXTI_EMR1_MR14_Msk        (0x1UL << EXTI_EMR1_MR14_Pos)      /*!< 0x00004000 */
#define EXTI_EMR1_MR14            EXTI_EMR1_MR14_Msk     /*!< </spirit:description> */
#define EXTI_EMR1_MR15_Pos        (15U)
#define EXTI_EMR1_MR15_Msk        (0x1UL << EXTI_EMR1_MR15_Pos)      /*!< 0x00008000 */
#define EXTI_EMR1_MR15            EXTI_EMR1_MR15_Msk     /*!< </spirit:description> */
#define EXTI_EMR1_MR18_Pos        (18U)
#define EXTI_EMR1_MR18_Msk        (0x1UL << EXTI_EMR1_MR18_Pos)      /*!< 0x00040000 */
#define EXTI_EMR1_MR18            EXTI_EMR1_MR18_Msk     /*!< </spirit:description> */
#define EXTI_EMR1_MR20_Pos        (20U)
#define EXTI_EMR1_MR20_Msk        (0x1UL << EXTI_EMR1_MR20_Pos)      /*!< 0x00100000 */
#define EXTI_EMR1_MR20            EXTI_EMR1_MR20_Msk     /*!< </spirit:description> */
#define EXTI_EMR1_MR21_Pos        (21U)
#define EXTI_EMR1_MR21_Msk        (0x1UL << EXTI_EMR1_MR21_Pos)      /*!< 0x00200000 */
#define EXTI_EMR1_MR21            EXTI_EMR1_MR21_Msk     /*!< </spirit:description> */
#define EXTI_EMR1_MR22_Pos        (22U)
#define EXTI_EMR1_MR22_Msk        (0x1UL << EXTI_EMR1_MR22_Pos)      /*!< 0x00400000 */
#define EXTI_EMR1_MR22            EXTI_EMR1_MR22_Msk     /*!< </spirit:description> */
#define EXTI_EMR1_MR23_Pos        (23U)
#define EXTI_EMR1_MR23_Msk        (0x1UL << EXTI_EMR1_MR23_Pos)      /*!< 0x00800000 */
#define EXTI_EMR1_MR23            EXTI_EMR1_MR23_Msk     /*!< </spirit:description> */
#define EXTI_EMR1_MR24_Pos        (24U)
#define EXTI_EMR1_MR24_Msk        (0x1UL << EXTI_EMR1_MR24_Pos)      /*!< 0x01000000 */
#define EXTI_EMR1_MR24            EXTI_EMR1_MR24_Msk     /*!< </spirit:description> */
#define EXTI_EMR1_MR25_Pos        (25U)
#define EXTI_EMR1_MR25_Msk        (0x1UL << EXTI_EMR1_MR25_Pos)      /*!< 0x02000000 */
#define EXTI_EMR1_MR25            EXTI_EMR1_MR25_Msk     /*!< </spirit:description> */
#define EXTI_EMR1_MR26_Pos        (26U)
#define EXTI_EMR1_MR26_Msk        (0x1UL << EXTI_EMR1_MR26_Pos)      /*!< 0x04000000 */
#define EXTI_EMR1_MR26            EXTI_EMR1_MR26_Msk     /*!< </spirit:description> */
#define EXTI_EMR1_MR28_Pos        (28U)
#define EXTI_EMR1_MR28_Msk        (0x1UL << EXTI_EMR1_MR28_Pos)      /*!< 0x10000000 */
#define EXTI_EMR1_MR28            EXTI_EMR1_MR28_Msk     /*!< </spirit:description> */
#define EXTI_EMR1_MR29_Pos        (29U)
#define EXTI_EMR1_MR29_Msk        (0x1UL << EXTI_EMR1_MR29_Pos)      /*!< 0x20000000 */
#define EXTI_EMR1_MR29            EXTI_EMR1_MR29_Msk     /*!< </spirit:description> */
#define EXTI_EMR1_MR30_Pos        (30U)
#define EXTI_EMR1_MR30_Msk        (0x1UL << EXTI_EMR1_MR30_Pos)      /*!< 0x40000000 */
#define EXTI_EMR1_MR30            EXTI_EMR1_MR30_Msk     /*!< </spirit:description> */
#define EXTI_EMR1_MR31_Pos        (31U)
#define EXTI_EMR1_MR31_Msk        (0x1UL << EXTI_EMR1_MR31_Pos)      /*!< 0x80000000 */
#define EXTI_EMR1_MR31            EXTI_EMR1_MR31_Msk     /*!< </spirit:description> */

/******************  Bit definition for EXTI_PR1 register  ******************/
#define EXTI_PR1_PR0_Pos          (0U)
#define EXTI_PR1_PR0_Msk          (0x1UL << EXTI_PR1_PR0_Pos)    /*!< 0x00000001 */
#define EXTI_PR1_PR0              EXTI_PR1_PR0_Msk       /*!< </spirit:description> */
#define EXTI_PR1_PR1_Pos          (1U)
#define EXTI_PR1_PR1_Msk          (0x1UL << EXTI_PR1_PR1_Pos)    /*!< 0x00000002 */
#define EXTI_PR1_PR1              EXTI_PR1_PR1_Msk       /*!< </spirit:description> */
#define EXTI_PR1_PR2_Pos          (2U)
#define EXTI_PR1_PR2_Msk          (0x1UL << EXTI_PR1_PR2_Pos)    /*!< 0x00000004 */
#define EXTI_PR1_PR2              EXTI_PR1_PR2_Msk       /*!< </spirit:description> */
#define EXTI_PR1_PR3_Pos          (3U)
#define EXTI_PR1_PR3_Msk          (0x1UL << EXTI_PR1_PR3_Pos)    /*!< 0x00000008 */
#define EXTI_PR1_PR3              EXTI_PR1_PR3_Msk       /*!< </spirit:description> */
#define EXTI_PR1_PR4_Pos          (4U)
#define EXTI_PR1_PR4_Msk          (0x1UL << EXTI_PR1_PR4_Pos)    /*!< 0x00000010 */
#define EXTI_PR1_PR4              EXTI_PR1_PR4_Msk       /*!< </spirit:description> */
#define EXTI_PR1_PR5_Pos          (5U)
#define EXTI_PR1_PR5_Msk          (0x1UL << EXTI_PR1_PR5_Pos)    /*!< 0x00000020 */
#define EXTI_PR1_PR5              EXTI_PR1_PR5_Msk       /*!< </spirit:description> */
#define EXTI_PR1_PR6_Pos          (6U)
#define EXTI_PR1_PR6_Msk          (0x1UL << EXTI_PR1_PR6_Pos)    /*!< 0x00000040 */
#define EXTI_PR1_PR6              EXTI_PR1_PR6_Msk       /*!< </spirit:description> */
#define EXTI_PR1_PR7_Pos          (7U)
#define EXTI_PR1_PR7_Msk          (0x1UL << EXTI_PR1_PR7_Pos)    /*!< 0x00000080 */
#define EXTI_PR1_PR7              EXTI_PR1_PR7_Msk       /*!< </spirit:description> */
#define EXTI_PR1_PR8_Pos          (8U)
#define EXTI_PR1_PR8_Msk          (0x1UL << EXTI_PR1_PR8_Pos)    /*!< 0x00000100 */
#define EXTI_PR1_PR8              EXTI_PR1_PR8_Msk       /*!< </spirit:description> */
#define EXTI_PR1_PR9_Pos          (9U)
#define EXTI_PR1_PR9_Msk          (0x1UL << EXTI_PR1_PR9_Pos)    /*!< 0x00000200 */
#define EXTI_PR1_PR9              EXTI_PR1_PR9_Msk       /*!< </spirit:description> */
#define EXTI_PR1_PR10_Pos         (10U)
#define EXTI_PR1_PR10_Msk         (0x1UL << EXTI_PR1_PR10_Pos)     /*!< 0x00000400 */
#define EXTI_PR1_PR10             EXTI_PR1_PR10_Msk      /*!< </spirit:description> */
#define EXTI_PR1_PR11_Pos         (11U)
#define EXTI_PR1_PR11_Msk         (0x1UL << EXTI_PR1_PR11_Pos)     /*!< 0x00000800 */
#define EXTI_PR1_PR11             EXTI_PR1_PR11_Msk      /*!< </spirit:description> */
#define EXTI_PR1_PR12_Pos         (12U)
#define EXTI_PR1_PR12_Msk         (0x1UL << EXTI_PR1_PR12_Pos)     /*!< 0x00001000 */
#define EXTI_PR1_PR12             EXTI_PR1_PR12_Msk      /*!< </spirit:description> */
#define EXTI_PR1_PR13_Pos         (13U)
#define EXTI_PR1_PR13_Msk         (0x1UL << EXTI_PR1_PR13_Pos)     /*!< 0x00002000 */
#define EXTI_PR1_PR13             EXTI_PR1_PR13_Msk      /*!< </spirit:description> */
#define EXTI_PR1_PR14_Pos         (14U)
#define EXTI_PR1_PR14_Msk         (0x1UL << EXTI_PR1_PR14_Pos)     /*!< 0x00004000 */
#define EXTI_PR1_PR14             EXTI_PR1_PR14_Msk      /*!< </spirit:description> */
#define EXTI_PR1_PR15_Pos         (15U)
#define EXTI_PR1_PR15_Msk         (0x1UL << EXTI_PR1_PR15_Pos)     /*!< 0x00008000 */
#define EXTI_PR1_PR15             EXTI_PR1_PR15_Msk      /*!< </spirit:description> */
#define EXTI_PR1_PR18_Pos         (18U)
#define EXTI_PR1_PR18_Msk         (0x1UL << EXTI_PR1_PR18_Pos)     /*!< 0x00040000 */
#define EXTI_PR1_PR18             EXTI_PR1_PR18_Msk      /*!< </spirit:description> */
#define EXTI_PR1_PR20_Pos         (20U)
#define EXTI_PR1_PR20_Msk         (0x1UL << EXTI_PR1_PR20_Pos)     /*!< 0x00100000 */
#define EXTI_PR1_PR20             EXTI_PR1_PR20_Msk      /*!< </spirit:description> */
#define EXTI_PR1_PR21_Pos         (21U)
#define EXTI_PR1_PR21_Msk         (0x1UL << EXTI_PR1_PR21_Pos)     /*!< 0x00200000 */
#define EXTI_PR1_PR21             EXTI_PR1_PR21_Msk      /*!< </spirit:description> */
#define EXTI_PR1_PR22_Pos         (22U)
#define EXTI_PR1_PR22_Msk         (0x1UL << EXTI_PR1_PR22_Pos)     /*!< 0x00400000 */
#define EXTI_PR1_PR22             EXTI_PR1_PR22_Msk      /*!< </spirit:description> */
#define EXTI_PR1_PR29_Pos         (29U)
#define EXTI_PR1_PR29_Msk         (0x1UL << EXTI_PR1_PR29_Pos)     /*!< 0x20000000 */
#define EXTI_PR1_PR29             EXTI_PR1_PR29_Msk      /*!< </spirit:description> */
#define EXTI_PR1_PR30_Pos         (30U)
#define EXTI_PR1_PR30_Msk         (0x1UL << EXTI_PR1_PR30_Pos)     /*!< 0x40000000 */
#define EXTI_PR1_PR30             EXTI_PR1_PR30_Msk      /*!< </spirit:description> */
#define EXTI_PR1_PR31_Pos         (31U)
#define EXTI_PR1_PR31_Msk         (0x1UL << EXTI_PR1_PR31_Pos)     /*!< 0x80000000 */
#define EXTI_PR1_PR31             EXTI_PR1_PR31_Msk      /*!< </spirit:description> */

/*****************  Bit definition for EXTI_IMR2 register  ******************/
#define EXTI_IMR2_MR32_Pos        (0U)
#define EXTI_IMR2_MR32_Msk        (0x1UL << EXTI_IMR2_MR32_Pos)      /*!< 0x00000001 */
#define EXTI_IMR2_MR32            EXTI_IMR2_MR32_Msk     /*!< </spirit:description> */
#define EXTI_IMR2_MR33_Pos        (1U)
#define EXTI_IMR2_MR33_Msk        (0x1UL << EXTI_IMR2_MR33_Pos)      /*!< 0x00000002 */
#define EXTI_IMR2_MR33            EXTI_IMR2_MR33_Msk     /*!< </spirit:description> */
#define EXTI_IMR2_MR34_Pos        (2U)
#define EXTI_IMR2_MR34_Msk        (0x1UL << EXTI_IMR2_MR34_Pos)      /*!< 0x00000004 */
#define EXTI_IMR2_MR34            EXTI_IMR2_MR34_Msk     /*!< </spirit:description> */
#define EXTI_IMR2_MR44_Pos        (12U)
#define EXTI_IMR2_MR44_Msk        (0x1UL << EXTI_IMR2_MR44_Pos)      /*!< 0x00001000 */
#define EXTI_IMR2_MR44            EXTI_IMR2_MR44_Msk     /*!< </spirit:description> */
#define EXTI_IMR2_MR45_Pos        (13U)
#define EXTI_IMR2_MR45_Msk        (0x1UL << EXTI_IMR2_MR45_Pos)      /*!< 0x00002000 */
#define EXTI_IMR2_MR45            EXTI_IMR2_MR45_Msk     /*!< </spirit:description> */

/*****************  Bit definition for EXTI_EMR2 register  ******************/
#define EXTI_EMR2_MR32_Pos        (0U)
#define EXTI_EMR2_MR32_Msk        (0x1UL << EXTI_EMR2_MR32_Pos)      /*!< 0x00000001 */
#define EXTI_EMR2_MR32            EXTI_EMR2_MR32_Msk     /*!< </spirit:description> */
#define EXTI_EMR2_MR33_Pos        (1U)
#define EXTI_EMR2_MR33_Msk        (0x1UL << EXTI_EMR2_MR33_Pos)      /*!< 0x00000002 */
#define EXTI_EMR2_MR33            EXTI_EMR2_MR33_Msk     /*!< </spirit:description> */
#define EXTI_EMR2_MR34_Pos        (2U)
#define EXTI_EMR2_MR34_Msk        (0x1UL << EXTI_EMR2_MR34_Pos)      /*!< 0x00000004 */
#define EXTI_EMR2_MR34            EXTI_EMR2_MR34_Msk     /*!< </spirit:description> */
#define EXTI_EMR2_MR44_Pos        (12U)
#define EXTI_EMR2_MR44_Msk        (0x1UL << EXTI_EMR2_MR44_Pos)      /*!< 0x00001000 */
#define EXTI_EMR2_MR44            EXTI_EMR2_MR44_Msk     /*!< </spirit:description> */
#define EXTI_EMR2_MR45_Pos        (13U)
#define EXTI_EMR2_MR45_Msk        (0x1UL << EXTI_EMR2_MR45_Pos)      /*!< 0x00002000 */
#define EXTI_EMR2_MR45            EXTI_EMR2_MR45_Msk     /*!< </spirit:description> */

/******************  Bit definition for EXTI_PR2 register  ******************/
#define EXTI_PR2_PR32_Pos         (0U)
#define EXTI_PR2_PR32_Msk         (0x1UL << EXTI_PR2_PR32_Pos)     /*!< 0x00000001 */
#define EXTI_PR2_PR32             EXTI_PR2_PR32_Msk      /*!< </spirit:description> */
#define EXTI_PR2_PR33_Pos         (1U)
#define EXTI_PR2_PR33_Msk         (0x1UL << EXTI_PR2_PR33_Pos)     /*!< 0x00000002 */
#define EXTI_PR2_PR33             EXTI_PR2_PR33_Msk      /*!< </spirit:description> */
#define EXTI_PR2_PR34_Pos         (2U)
#define EXTI_PR2_PR34_Msk         (0x1UL << EXTI_PR2_PR34_Pos)     /*!< 0x00000004 */
#define EXTI_PR2_PR34             EXTI_PR2_PR34_Msk      /*!< </spirit:description> */

#define EXTI_BASE           0x42000400UL 


#define EXTI                ((EXTI_TypeDef *) EXTI_BASE) 


#endif /* __SR5E1_EXTI_H */

