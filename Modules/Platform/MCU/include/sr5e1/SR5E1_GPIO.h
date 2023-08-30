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

#ifndef __SR5E1_GPIO_H
#define __SR5E1_GPIO_H

/*******************************************************************************
 * REVISION HISTORY                                                            *
 * REV       DATE       RM REV          DESCRIPTION OF CHANGE                  *
 * ------ ----------- ------------ --------------------------------------------*
 * 1.1A1  21-Feb-2022 Reb 1 Draft C     SR5E1_RDP_0_2_Rev1_C_18FEB22           *
 *                                      Moved AFRl and AFRH registers in AFR[2]*
 * ------ ----------- ------------ --------------------------------------------*
 * 1.0A1  18-Feb-2022 Rev 1 Draft C     SR5E1_RDP_0_1_Rev1_C_18FEB22           *
 ******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                                 GPIO (ADR)                                 */
/*                                                                            */
/******************************************************************************/
typedef struct
{
  __IO uint32_t MODER;     /*!< MODER    Address offset: 0x3AC */
  __IO uint32_t OTYPER;    /*!< OTYPER   Address offset: 0x3B0 */
  __IO uint32_t OSPEEDR;   /*!< OSPEEDR  Address offset: 0x3B4 */
  __IO uint32_t PUPDR;     /*!< PUPDR    Address offset: 0x3B8 */
  __IO uint32_t IDR;       /*!< IDR      Address offset: 0x3BC */
  __IO uint32_t ODR;       /*!< ODR      Address offset: 0x3C0 */
  __IO uint32_t BSRR;      /*!< BSRR     Address offset: 0x3C4 */
  __IO uint32_t LCKR;      /*!< LCKR     Address offset: 0x3C8 */
  __IO uint32_t AFR[2];    /*!< AFR      Address offset: 0x3CC-0x3D0 */
  __IO uint32_t IHYSTR;    /*!< IHYSTR   Address offset: 0x3D4 */
  __IO uint32_t TRIGENR;   /*!< TRIGENR  Address offset: 0x3D8 */
  __IO uint32_t SAFESELR;  /*!< SAFESELR Address offset: 0x3DC */
  __IO uint32_t SAFEVALR;  /*!< SAFEVALR Address offset: 0x3E0 */
} GPIO_TypeDef;


/******************  Bit definition for GPIO_MODER register  ******************/
#define GPIO_MODER_MODE0_Pos        (0U)
#define GPIO_MODER_MODE0_Msk        (0x3UL << GPIO_MODER_MODE0_Pos) /*!< 0x00000003 */
#define GPIO_MODER_MODE0            GPIO_MODER_MODE0_Msk         /*!< </spirit:description> */
#define GPIO_MODER_MODE0_0  (0x1UL << GPIO_MODER_MODE0_Pos)         /*!< 0x00000001 */
#define GPIO_MODER_MODE0_1  (0x2UL << GPIO_MODER_MODE0_Pos)         /*!< 0x00000002 */
#define GPIO_MODER_MODE1_Pos        (2U)
#define GPIO_MODER_MODE1_Msk        (0x3UL << GPIO_MODER_MODE1_Pos) /*!< 0x0000000C */
#define GPIO_MODER_MODE1            GPIO_MODER_MODE1_Msk         /*!< </spirit:description> */
#define GPIO_MODER_MODE1_0  (0x1UL << GPIO_MODER_MODE1_Pos)         /*!< 0x00000004 */
#define GPIO_MODER_MODE1_1  (0x2UL << GPIO_MODER_MODE1_Pos)         /*!< 0x00000008 */
#define GPIO_MODER_MODE2_Pos        (4U)
#define GPIO_MODER_MODE2_Msk        (0x3UL << GPIO_MODER_MODE2_Pos) /*!< 0x00000030 */
#define GPIO_MODER_MODE2            GPIO_MODER_MODE2_Msk         /*!< </spirit:description> */
#define GPIO_MODER_MODE2_0  (0x1UL << GPIO_MODER_MODE2_Pos)          /*!< 0x00000010 */
#define GPIO_MODER_MODE2_1  (0x2UL << GPIO_MODER_MODE2_Pos)          /*!< 0x00000020 */
#define GPIO_MODER_MODE3_Pos        (6U)
#define GPIO_MODER_MODE3_Msk        (0x3UL << GPIO_MODER_MODE3_Pos) /*!< 0x000000C0 */
#define GPIO_MODER_MODE3            GPIO_MODER_MODE3_Msk         /*!< </spirit:description> */
#define GPIO_MODER_MODE3_0  (0x1UL << GPIO_MODER_MODE3_Pos)          /*!< 0x00000040 */
#define GPIO_MODER_MODE3_1  (0x2UL << GPIO_MODER_MODE3_Pos)          /*!< 0x00000080 */
#define GPIO_MODER_MODE4_Pos        (8U)
#define GPIO_MODER_MODE4_Msk        (0x3UL << GPIO_MODER_MODE4_Pos) /*!< 0x00000300 */
#define GPIO_MODER_MODE4            GPIO_MODER_MODE4_Msk         /*!< </spirit:description> */
#define GPIO_MODER_MODE4_0  (0x1UL << GPIO_MODER_MODE4_Pos)           /*!< 0x00000100 */
#define GPIO_MODER_MODE4_1  (0x2UL << GPIO_MODER_MODE4_Pos)           /*!< 0x00000200 */
#define GPIO_MODER_MODE5_Pos        (10U)
#define GPIO_MODER_MODE5_Msk        (0x3UL << GPIO_MODER_MODE5_Pos) /*!< 0x00000C00 */
#define GPIO_MODER_MODE5            GPIO_MODER_MODE5_Msk         /*!< </spirit:description> */
#define GPIO_MODER_MODE5_0  (0x1UL << GPIO_MODER_MODE5_Pos)           /*!< 0x00000400 */
#define GPIO_MODER_MODE5_1  (0x2UL << GPIO_MODER_MODE5_Pos)           /*!< 0x00000800 */
#define GPIO_MODER_MODE6_Pos        (12U)
#define GPIO_MODER_MODE6_Msk        (0x3UL << GPIO_MODER_MODE6_Pos) /*!< 0x00003000 */
#define GPIO_MODER_MODE6            GPIO_MODER_MODE6_Msk         /*!< </spirit:description> */
#define GPIO_MODER_MODE6_0  (0x1UL << GPIO_MODER_MODE6_Pos)            /*!< 0x00001000 */
#define GPIO_MODER_MODE6_1  (0x2UL << GPIO_MODER_MODE6_Pos)            /*!< 0x00002000 */
#define GPIO_MODER_MODE7_Pos        (14U)
#define GPIO_MODER_MODE7_Msk        (0x3UL << GPIO_MODER_MODE7_Pos) /*!< 0x0000C000 */
#define GPIO_MODER_MODE7            GPIO_MODER_MODE7_Msk         /*!< </spirit:description> */
#define GPIO_MODER_MODE7_0  (0x1UL << GPIO_MODER_MODE7_Pos)            /*!< 0x00004000 */
#define GPIO_MODER_MODE7_1  (0x2UL << GPIO_MODER_MODE7_Pos)            /*!< 0x00008000 */
#define GPIO_MODER_MODE8_Pos        (16U)
#define GPIO_MODER_MODE8_Msk        (0x3UL << GPIO_MODER_MODE8_Pos) /*!< 0x00030000 */
#define GPIO_MODER_MODE8            GPIO_MODER_MODE8_Msk         /*!< </spirit:description> */
#define GPIO_MODER_MODE8_0  (0x1UL << GPIO_MODER_MODE8_Pos)             /*!< 0x00010000 */
#define GPIO_MODER_MODE8_1  (0x2UL << GPIO_MODER_MODE8_Pos)             /*!< 0x00020000 */
#define GPIO_MODER_MODE9_Pos        (18U)
#define GPIO_MODER_MODE9_Msk        (0x3UL << GPIO_MODER_MODE9_Pos) /*!< 0x000C0000 */
#define GPIO_MODER_MODE9            GPIO_MODER_MODE9_Msk         /*!< </spirit:description> */
#define GPIO_MODER_MODE9_0  (0x1UL << GPIO_MODER_MODE9_Pos)             /*!< 0x00040000 */
#define GPIO_MODER_MODE9_1  (0x2UL << GPIO_MODER_MODE9_Pos)             /*!< 0x00080000 */
#define GPIO_MODER_MODE10_Pos       (20U)
#define GPIO_MODER_MODE10_Msk       (0x3UL << GPIO_MODER_MODE10_Pos)  /*!< 0x00300000 */
#define GPIO_MODER_MODE10           GPIO_MODER_MODE10_Msk        /*!< </spirit:description> */
#define GPIO_MODER_MODE10_0 (0x1UL << GPIO_MODER_MODE10_Pos)               /*!< 0x00100000 */
#define GPIO_MODER_MODE10_1 (0x2UL << GPIO_MODER_MODE10_Pos)               /*!< 0x00200000 */
#define GPIO_MODER_MODE11_Pos       (22U)
#define GPIO_MODER_MODE11_Msk       (0x3UL << GPIO_MODER_MODE11_Pos)  /*!< 0x00C00000 */
#define GPIO_MODER_MODE11           GPIO_MODER_MODE11_Msk        /*!< </spirit:description> */
#define GPIO_MODER_MODE11_0 (0x1UL << GPIO_MODER_MODE11_Pos)               /*!< 0x00400000 */
#define GPIO_MODER_MODE11_1 (0x2UL << GPIO_MODER_MODE11_Pos)               /*!< 0x00800000 */
#define GPIO_MODER_MODE12_Pos       (24U)
#define GPIO_MODER_MODE12_Msk       (0x3UL << GPIO_MODER_MODE12_Pos)  /*!< 0x03000000 */
#define GPIO_MODER_MODE12           GPIO_MODER_MODE12_Msk        /*!< </spirit:description> */
#define GPIO_MODER_MODE12_0 (0x1UL << GPIO_MODER_MODE12_Pos)                /*!< 0x01000000 */
#define GPIO_MODER_MODE12_1 (0x2UL << GPIO_MODER_MODE12_Pos)                /*!< 0x02000000 */
#define GPIO_MODER_MODE13_Pos       (26U)
#define GPIO_MODER_MODE13_Msk       (0x3UL << GPIO_MODER_MODE13_Pos)  /*!< 0x0C000000 */
#define GPIO_MODER_MODE13           GPIO_MODER_MODE13_Msk        /*!< </spirit:description> */
#define GPIO_MODER_MODE13_0 (0x1UL << GPIO_MODER_MODE13_Pos)                /*!< 0x04000000 */
#define GPIO_MODER_MODE13_1 (0x2UL << GPIO_MODER_MODE13_Pos)                /*!< 0x08000000 */
#define GPIO_MODER_MODE14_Pos       (28U)
#define GPIO_MODER_MODE14_Msk       (0x3UL << GPIO_MODER_MODE14_Pos)  /*!< 0x30000000 */
#define GPIO_MODER_MODE14           GPIO_MODER_MODE14_Msk        /*!< </spirit:description> */
#define GPIO_MODER_MODE14_0 (0x1UL << GPIO_MODER_MODE14_Pos)                 /*!< 0x10000000 */
#define GPIO_MODER_MODE14_1 (0x2UL << GPIO_MODER_MODE14_Pos)                 /*!< 0x20000000 */
#define GPIO_MODER_MODE15_Pos       (30U)
#define GPIO_MODER_MODE15_Msk       (0x3UL << GPIO_MODER_MODE15_Pos)  /*!< 0xC0000000 */
#define GPIO_MODER_MODE15           GPIO_MODER_MODE15_Msk        /*!< </spirit:description> */
#define GPIO_MODER_MODE15_0 (0x1UL << GPIO_MODER_MODE15_Pos)                 /*!< 0x40000000 */
#define GPIO_MODER_MODE15_1 (0x2UL << GPIO_MODER_MODE15_Pos)                 /*!< 0x80000000 */

/*****************  Bit definition for GPIO_OTYPER register  ******************/
#define GPIO_OTYPER_OT0_Pos         (0U)
#define GPIO_OTYPER_OT0_Msk          (0x1UL << GPIO_OTYPER_OT0_Pos)   /*!< 0x00000001 */
#define GPIO_OTYPER_OT0             GPIO_OTYPER_OT0_Msk          /*!< </spirit:description> */
#define GPIO_OTYPER_OT1_Pos         (1U)
#define GPIO_OTYPER_OT1_Msk          (0x1UL << GPIO_OTYPER_OT1_Pos)   /*!< 0x00000002 */
#define GPIO_OTYPER_OT1             GPIO_OTYPER_OT1_Msk          /*!< </spirit:description> */
#define GPIO_OTYPER_OT2_Pos         (2U)
#define GPIO_OTYPER_OT2_Msk          (0x1UL << GPIO_OTYPER_OT2_Pos)   /*!< 0x00000004 */
#define GPIO_OTYPER_OT2             GPIO_OTYPER_OT2_Msk          /*!< </spirit:description> */
#define GPIO_OTYPER_OT3_Pos         (3U)
#define GPIO_OTYPER_OT3_Msk          (0x1UL << GPIO_OTYPER_OT3_Pos)   /*!< 0x00000008 */
#define GPIO_OTYPER_OT3             GPIO_OTYPER_OT3_Msk          /*!< </spirit:description> */
#define GPIO_OTYPER_OT4_Pos         (4U)
#define GPIO_OTYPER_OT4_Msk          (0x1UL << GPIO_OTYPER_OT4_Pos)   /*!< 0x00000010 */
#define GPIO_OTYPER_OT4             GPIO_OTYPER_OT4_Msk          /*!< </spirit:description> */
#define GPIO_OTYPER_OT5_Pos         (5U)
#define GPIO_OTYPER_OT5_Msk          (0x1UL << GPIO_OTYPER_OT5_Pos)   /*!< 0x00000020 */
#define GPIO_OTYPER_OT5             GPIO_OTYPER_OT5_Msk          /*!< </spirit:description> */
#define GPIO_OTYPER_OT6_Pos         (6U)
#define GPIO_OTYPER_OT6_Msk          (0x1UL << GPIO_OTYPER_OT6_Pos)   /*!< 0x00000040 */
#define GPIO_OTYPER_OT6             GPIO_OTYPER_OT6_Msk          /*!< </spirit:description> */
#define GPIO_OTYPER_OT7_Pos         (7U)
#define GPIO_OTYPER_OT7_Msk          (0x1UL << GPIO_OTYPER_OT7_Pos)   /*!< 0x00000080 */
#define GPIO_OTYPER_OT7             GPIO_OTYPER_OT7_Msk          /*!< </spirit:description> */
#define GPIO_OTYPER_OT8_Pos         (8U)
#define GPIO_OTYPER_OT8_Msk          (0x1UL << GPIO_OTYPER_OT8_Pos)   /*!< 0x00000100 */
#define GPIO_OTYPER_OT8             GPIO_OTYPER_OT8_Msk          /*!< </spirit:description> */
#define GPIO_OTYPER_OT9_Pos         (9U)
#define GPIO_OTYPER_OT9_Msk          (0x1UL << GPIO_OTYPER_OT9_Pos)   /*!< 0x00000200 */
#define GPIO_OTYPER_OT9             GPIO_OTYPER_OT9_Msk          /*!< </spirit:description> */
#define GPIO_OTYPER_OT10_Pos        (10U)
#define GPIO_OTYPER_OT10_Msk        (0x1UL << GPIO_OTYPER_OT10_Pos) /*!< 0x00000400 */
#define GPIO_OTYPER_OT10            GPIO_OTYPER_OT10_Msk         /*!< </spirit:description> */
#define GPIO_OTYPER_OT11_Pos        (11U)
#define GPIO_OTYPER_OT11_Msk        (0x1UL << GPIO_OTYPER_OT11_Pos) /*!< 0x00000800 */
#define GPIO_OTYPER_OT11            GPIO_OTYPER_OT11_Msk         /*!< </spirit:description> */
#define GPIO_OTYPER_OT12_Pos        (12U)
#define GPIO_OTYPER_OT12_Msk        (0x1UL << GPIO_OTYPER_OT12_Pos) /*!< 0x00001000 */
#define GPIO_OTYPER_OT12            GPIO_OTYPER_OT12_Msk         /*!< </spirit:description> */
#define GPIO_OTYPER_OT13_Pos        (13U)
#define GPIO_OTYPER_OT13_Msk        (0x1UL << GPIO_OTYPER_OT13_Pos) /*!< 0x00002000 */
#define GPIO_OTYPER_OT13            GPIO_OTYPER_OT13_Msk         /*!< </spirit:description> */
#define GPIO_OTYPER_OT14_Pos        (14U)
#define GPIO_OTYPER_OT14_Msk        (0x1UL << GPIO_OTYPER_OT14_Pos) /*!< 0x00004000 */
#define GPIO_OTYPER_OT14            GPIO_OTYPER_OT14_Msk         /*!< </spirit:description> */
#define GPIO_OTYPER_OT15_Pos        (15U)
#define GPIO_OTYPER_OT15_Msk        (0x1UL << GPIO_OTYPER_OT15_Pos) /*!< 0x00008000 */
#define GPIO_OTYPER_OT15            GPIO_OTYPER_OT15_Msk         /*!< </spirit:description> */

/*****************  Bit definition for GPIO_OSPEEDR register  *****************/
#define GPIO_OSPEEDR_OSPEED0_Pos    (0U)
#define GPIO_OSPEEDR_OSPEED0_Msk    (0x3UL << GPIO_OSPEEDR_OSPEED0_Pos)     /*!< 0x00000003 */
#define GPIO_OSPEEDR_OSPEED0        GPIO_OSPEEDR_OSPEED0_Msk     /*!< </spirit:description> */
#define GPIO_OSPEEDR_OSPEED0_0    (0x1UL << GPIO_OSPEEDR_OSPEED0_Pos)             /*!< 0x00000001 */
#define GPIO_OSPEEDR_OSPEED0_1    (0x2UL << GPIO_OSPEEDR_OSPEED0_Pos)             /*!< 0x00000002 */
#define GPIO_OSPEEDR_OSPEED1_Pos    (2U)
#define GPIO_OSPEEDR_OSPEED1_Msk    (0x3UL << GPIO_OSPEEDR_OSPEED1_Pos)     /*!< 0x0000000C */
#define GPIO_OSPEEDR_OSPEED1        GPIO_OSPEEDR_OSPEED1_Msk     /*!< </spirit:description> */
#define GPIO_OSPEEDR_OSPEED1_0    (0x1UL << GPIO_OSPEEDR_OSPEED1_Pos)             /*!< 0x00000004 */
#define GPIO_OSPEEDR_OSPEED1_1    (0x2UL << GPIO_OSPEEDR_OSPEED1_Pos)             /*!< 0x00000008 */
#define GPIO_OSPEEDR_OSPEED2_Pos    (4U)
#define GPIO_OSPEEDR_OSPEED2_Msk    (0x3UL << GPIO_OSPEEDR_OSPEED2_Pos)     /*!< 0x00000030 */
#define GPIO_OSPEEDR_OSPEED2        GPIO_OSPEEDR_OSPEED2_Msk     /*!< </spirit:description> */
#define GPIO_OSPEEDR_OSPEED2_0    (0x1UL << GPIO_OSPEEDR_OSPEED2_Pos)              /*!< 0x00000010 */
#define GPIO_OSPEEDR_OSPEED2_1    (0x2UL << GPIO_OSPEEDR_OSPEED2_Pos)              /*!< 0x00000020 */
#define GPIO_OSPEEDR_OSPEED3_Pos    (6U)
#define GPIO_OSPEEDR_OSPEED3_Msk    (0x3UL << GPIO_OSPEEDR_OSPEED3_Pos)     /*!< 0x000000C0 */
#define GPIO_OSPEEDR_OSPEED3        GPIO_OSPEEDR_OSPEED3_Msk     /*!< </spirit:description> */
#define GPIO_OSPEEDR_OSPEED3_0    (0x1UL << GPIO_OSPEEDR_OSPEED3_Pos)              /*!< 0x00000040 */
#define GPIO_OSPEEDR_OSPEED3_1    (0x2UL << GPIO_OSPEEDR_OSPEED3_Pos)              /*!< 0x00000080 */
#define GPIO_OSPEEDR_OSPEED4_Pos    (8U)
#define GPIO_OSPEEDR_OSPEED4_Msk    (0x3UL << GPIO_OSPEEDR_OSPEED4_Pos)     /*!< 0x00000300 */
#define GPIO_OSPEEDR_OSPEED4        GPIO_OSPEEDR_OSPEED4_Msk     /*!< </spirit:description> */
#define GPIO_OSPEEDR_OSPEED4_0    (0x1UL << GPIO_OSPEEDR_OSPEED4_Pos)               /*!< 0x00000100 */
#define GPIO_OSPEEDR_OSPEED4_1    (0x2UL << GPIO_OSPEEDR_OSPEED4_Pos)               /*!< 0x00000200 */
#define GPIO_OSPEEDR_OSPEED5_Pos    (10U)
#define GPIO_OSPEEDR_OSPEED5_Msk    (0x3UL << GPIO_OSPEEDR_OSPEED5_Pos)     /*!< 0x00000C00 */
#define GPIO_OSPEEDR_OSPEED5        GPIO_OSPEEDR_OSPEED5_Msk     /*!< </spirit:description> */
#define GPIO_OSPEEDR_OSPEED5_0    (0x1UL << GPIO_OSPEEDR_OSPEED5_Pos)               /*!< 0x00000400 */
#define GPIO_OSPEEDR_OSPEED5_1    (0x2UL << GPIO_OSPEEDR_OSPEED5_Pos)               /*!< 0x00000800 */
#define GPIO_OSPEEDR_OSPEED6_Pos    (12U)
#define GPIO_OSPEEDR_OSPEED6_Msk    (0x3UL << GPIO_OSPEEDR_OSPEED6_Pos)     /*!< 0x00003000 */
#define GPIO_OSPEEDR_OSPEED6        GPIO_OSPEEDR_OSPEED6_Msk     /*!< </spirit:description> */
#define GPIO_OSPEEDR_OSPEED6_0    (0x1UL << GPIO_OSPEEDR_OSPEED6_Pos)                /*!< 0x00001000 */
#define GPIO_OSPEEDR_OSPEED6_1    (0x2UL << GPIO_OSPEEDR_OSPEED6_Pos)                /*!< 0x00002000 */
#define GPIO_OSPEEDR_OSPEED7_Pos    (14U)
#define GPIO_OSPEEDR_OSPEED7_Msk    (0x3UL << GPIO_OSPEEDR_OSPEED7_Pos)     /*!< 0x0000C000 */
#define GPIO_OSPEEDR_OSPEED7        GPIO_OSPEEDR_OSPEED7_Msk     /*!< </spirit:description> */
#define GPIO_OSPEEDR_OSPEED7_0    (0x1UL << GPIO_OSPEEDR_OSPEED7_Pos)                /*!< 0x00004000 */
#define GPIO_OSPEEDR_OSPEED7_1    (0x2UL << GPIO_OSPEEDR_OSPEED7_Pos)                /*!< 0x00008000 */
#define GPIO_OSPEEDR_OSPEED8_Pos    (16U)
#define GPIO_OSPEEDR_OSPEED8_Msk    (0x3UL << GPIO_OSPEEDR_OSPEED8_Pos)     /*!< 0x00030000 */
#define GPIO_OSPEEDR_OSPEED8        GPIO_OSPEEDR_OSPEED8_Msk     /*!< </spirit:description> */
#define GPIO_OSPEEDR_OSPEED8_0    (0x1UL << GPIO_OSPEEDR_OSPEED8_Pos)                 /*!< 0x00010000 */
#define GPIO_OSPEEDR_OSPEED8_1    (0x2UL << GPIO_OSPEEDR_OSPEED8_Pos)                 /*!< 0x00020000 */
#define GPIO_OSPEEDR_OSPEED9_Pos    (18U)
#define GPIO_OSPEEDR_OSPEED9_Msk    (0x3UL << GPIO_OSPEEDR_OSPEED9_Pos)     /*!< 0x000C0000 */
#define GPIO_OSPEEDR_OSPEED9        GPIO_OSPEEDR_OSPEED9_Msk     /*!< </spirit:description> */
#define GPIO_OSPEEDR_OSPEED9_0    (0x1UL << GPIO_OSPEEDR_OSPEED9_Pos)                 /*!< 0x00040000 */
#define GPIO_OSPEEDR_OSPEED9_1    (0x2UL << GPIO_OSPEEDR_OSPEED9_Pos)                 /*!< 0x00080000 */
#define GPIO_OSPEEDR_OSPEED10_Pos   (20U)
#define GPIO_OSPEEDR_OSPEED10_Msk   (0x3UL << GPIO_OSPEEDR_OSPEED10_Pos)      /*!< 0x00300000 */
#define GPIO_OSPEEDR_OSPEED10       GPIO_OSPEEDR_OSPEED10_Msk    /*!< </spirit:description> */
#define GPIO_OSPEEDR_OSPEED10_0     (0x1UL << GPIO_OSPEEDR_OSPEED10_Pos)                   /*!< 0x00100000 */
#define GPIO_OSPEEDR_OSPEED10_1     (0x2UL << GPIO_OSPEEDR_OSPEED10_Pos)                   /*!< 0x00200000 */
#define GPIO_OSPEEDR_OSPEED11_Pos   (22U)
#define GPIO_OSPEEDR_OSPEED11_Msk   (0x3UL << GPIO_OSPEEDR_OSPEED11_Pos)      /*!< 0x00C00000 */
#define GPIO_OSPEEDR_OSPEED11       GPIO_OSPEEDR_OSPEED11_Msk    /*!< </spirit:description> */
#define GPIO_OSPEEDR_OSPEED11_0     (0x1UL << GPIO_OSPEEDR_OSPEED11_Pos)                   /*!< 0x00400000 */
#define GPIO_OSPEEDR_OSPEED11_1     (0x2UL << GPIO_OSPEEDR_OSPEED11_Pos)                   /*!< 0x00800000 */
#define GPIO_OSPEEDR_OSPEED12_Pos   (24U)
#define GPIO_OSPEEDR_OSPEED12_Msk   (0x3UL << GPIO_OSPEEDR_OSPEED12_Pos)      /*!< 0x03000000 */
#define GPIO_OSPEEDR_OSPEED12       GPIO_OSPEEDR_OSPEED12_Msk    /*!< </spirit:description> */
#define GPIO_OSPEEDR_OSPEED12_0     (0x1UL << GPIO_OSPEEDR_OSPEED12_Pos)                    /*!< 0x01000000 */
#define GPIO_OSPEEDR_OSPEED12_1     (0x2UL << GPIO_OSPEEDR_OSPEED12_Pos)                    /*!< 0x02000000 */
#define GPIO_OSPEEDR_OSPEED13_Pos   (26U)
#define GPIO_OSPEEDR_OSPEED13_Msk   (0x3UL << GPIO_OSPEEDR_OSPEED13_Pos)      /*!< 0x0C000000 */
#define GPIO_OSPEEDR_OSPEED13       GPIO_OSPEEDR_OSPEED13_Msk    /*!< </spirit:description> */
#define GPIO_OSPEEDR_OSPEED13_0     (0x1UL << GPIO_OSPEEDR_OSPEED13_Pos)                    /*!< 0x04000000 */
#define GPIO_OSPEEDR_OSPEED13_1     (0x2UL << GPIO_OSPEEDR_OSPEED13_Pos)                    /*!< 0x08000000 */
#define GPIO_OSPEEDR_OSPEED14_Pos   (28U)
#define GPIO_OSPEEDR_OSPEED14_Msk   (0x3UL << GPIO_OSPEEDR_OSPEED14_Pos)      /*!< 0x30000000 */
#define GPIO_OSPEEDR_OSPEED14       GPIO_OSPEEDR_OSPEED14_Msk    /*!< </spirit:description> */
#define GPIO_OSPEEDR_OSPEED14_0     (0x1UL << GPIO_OSPEEDR_OSPEED14_Pos)                     /*!< 0x10000000 */
#define GPIO_OSPEEDR_OSPEED14_1     (0x2UL << GPIO_OSPEEDR_OSPEED14_Pos)                     /*!< 0x20000000 */
#define GPIO_OSPEEDR_OSPEED15_Pos   (30U)
#define GPIO_OSPEEDR_OSPEED15_Msk   (0x3UL << GPIO_OSPEEDR_OSPEED15_Pos)      /*!< 0xC0000000 */
#define GPIO_OSPEEDR_OSPEED15       GPIO_OSPEEDR_OSPEED15_Msk    /*!< </spirit:description> */
#define GPIO_OSPEEDR_OSPEED15_0     (0x1UL << GPIO_OSPEEDR_OSPEED15_Pos)                     /*!< 0x40000000 */
#define GPIO_OSPEEDR_OSPEED15_1     (0x2UL << GPIO_OSPEEDR_OSPEED15_Pos)                     /*!< 0x80000000 */

/******************  Bit definition for GPIO_PUPDR register  ******************/
#define GPIO_PUPDR_PUPD0_Pos        (0U)
#define GPIO_PUPDR_PUPD0_Msk        (0x3UL << GPIO_PUPDR_PUPD0_Pos) /*!< 0x00000003 */
#define GPIO_PUPDR_PUPD0            GPIO_PUPDR_PUPD0_Msk         /*!< </spirit:description> */
#define GPIO_PUPDR_PUPD0_0  (0x1UL << GPIO_PUPDR_PUPD0_Pos)         /*!< 0x00000001 */
#define GPIO_PUPDR_PUPD0_1  (0x2UL << GPIO_PUPDR_PUPD0_Pos)         /*!< 0x00000002 */
#define GPIO_PUPDR_PUPD1_Pos        (2U)
#define GPIO_PUPDR_PUPD1_Msk        (0x3UL << GPIO_PUPDR_PUPD1_Pos) /*!< 0x0000000C */
#define GPIO_PUPDR_PUPD1            GPIO_PUPDR_PUPD1_Msk         /*!< </spirit:description> */
#define GPIO_PUPDR_PUPD1_0  (0x1UL << GPIO_PUPDR_PUPD1_Pos)         /*!< 0x00000004 */
#define GPIO_PUPDR_PUPD1_1  (0x2UL << GPIO_PUPDR_PUPD1_Pos)         /*!< 0x00000008 */
#define GPIO_PUPDR_PUPD2_Pos        (4U)
#define GPIO_PUPDR_PUPD2_Msk        (0x3UL << GPIO_PUPDR_PUPD2_Pos) /*!< 0x00000030 */
#define GPIO_PUPDR_PUPD2            GPIO_PUPDR_PUPD2_Msk         /*!< </spirit:description> */
#define GPIO_PUPDR_PUPD2_0  (0x1UL << GPIO_PUPDR_PUPD2_Pos)          /*!< 0x00000010 */
#define GPIO_PUPDR_PUPD2_1  (0x2UL << GPIO_PUPDR_PUPD2_Pos)          /*!< 0x00000020 */
#define GPIO_PUPDR_PUPD3_Pos        (6U)
#define GPIO_PUPDR_PUPD3_Msk        (0x3UL << GPIO_PUPDR_PUPD3_Pos) /*!< 0x000000C0 */
#define GPIO_PUPDR_PUPD3            GPIO_PUPDR_PUPD3_Msk         /*!< </spirit:description> */
#define GPIO_PUPDR_PUPD3_0  (0x1UL << GPIO_PUPDR_PUPD3_Pos)          /*!< 0x00000040 */
#define GPIO_PUPDR_PUPD3_1  (0x2UL << GPIO_PUPDR_PUPD3_Pos)          /*!< 0x00000080 */
#define GPIO_PUPDR_PUPD4_Pos        (8U)
#define GPIO_PUPDR_PUPD4_Msk        (0x3UL << GPIO_PUPDR_PUPD4_Pos) /*!< 0x00000300 */
#define GPIO_PUPDR_PUPD4            GPIO_PUPDR_PUPD4_Msk         /*!< </spirit:description> */
#define GPIO_PUPDR_PUPD4_0  (0x1UL << GPIO_PUPDR_PUPD4_Pos)           /*!< 0x00000100 */
#define GPIO_PUPDR_PUPD4_1  (0x2UL << GPIO_PUPDR_PUPD4_Pos)           /*!< 0x00000200 */
#define GPIO_PUPDR_PUPD5_Pos        (10U)
#define GPIO_PUPDR_PUPD5_Msk        (0x3UL << GPIO_PUPDR_PUPD5_Pos) /*!< 0x00000C00 */
#define GPIO_PUPDR_PUPD5            GPIO_PUPDR_PUPD5_Msk         /*!< </spirit:description> */
#define GPIO_PUPDR_PUPD5_0  (0x1UL << GPIO_PUPDR_PUPD5_Pos)           /*!< 0x00000400 */
#define GPIO_PUPDR_PUPD5_1  (0x2UL << GPIO_PUPDR_PUPD5_Pos)           /*!< 0x00000800 */
#define GPIO_PUPDR_PUPD6_Pos        (12U)
#define GPIO_PUPDR_PUPD6_Msk        (0x3UL << GPIO_PUPDR_PUPD6_Pos) /*!< 0x00003000 */
#define GPIO_PUPDR_PUPD6            GPIO_PUPDR_PUPD6_Msk         /*!< </spirit:description> */
#define GPIO_PUPDR_PUPD6_0  (0x1UL << GPIO_PUPDR_PUPD6_Pos)            /*!< 0x00001000 */
#define GPIO_PUPDR_PUPD6_1  (0x2UL << GPIO_PUPDR_PUPD6_Pos)            /*!< 0x00002000 */
#define GPIO_PUPDR_PUPD7_Pos        (14U)
#define GPIO_PUPDR_PUPD7_Msk        (0x3UL << GPIO_PUPDR_PUPD7_Pos) /*!< 0x0000C000 */
#define GPIO_PUPDR_PUPD7            GPIO_PUPDR_PUPD7_Msk         /*!< </spirit:description> */
#define GPIO_PUPDR_PUPD7_0  (0x1UL << GPIO_PUPDR_PUPD7_Pos)            /*!< 0x00004000 */
#define GPIO_PUPDR_PUPD7_1  (0x2UL << GPIO_PUPDR_PUPD7_Pos)            /*!< 0x00008000 */
#define GPIO_PUPDR_PUPD8_Pos        (16U)
#define GPIO_PUPDR_PUPD8_Msk        (0x3UL << GPIO_PUPDR_PUPD8_Pos) /*!< 0x00030000 */
#define GPIO_PUPDR_PUPD8            GPIO_PUPDR_PUPD8_Msk         /*!< </spirit:description> */
#define GPIO_PUPDR_PUPD8_0  (0x1UL << GPIO_PUPDR_PUPD8_Pos)             /*!< 0x00010000 */
#define GPIO_PUPDR_PUPD8_1  (0x2UL << GPIO_PUPDR_PUPD8_Pos)             /*!< 0x00020000 */
#define GPIO_PUPDR_PUPD9_Pos        (18U)
#define GPIO_PUPDR_PUPD9_Msk        (0x3UL << GPIO_PUPDR_PUPD9_Pos) /*!< 0x000C0000 */
#define GPIO_PUPDR_PUPD9            GPIO_PUPDR_PUPD9_Msk         /*!< </spirit:description> */
#define GPIO_PUPDR_PUPD9_0  (0x1UL << GPIO_PUPDR_PUPD9_Pos)             /*!< 0x00040000 */
#define GPIO_PUPDR_PUPD9_1  (0x2UL << GPIO_PUPDR_PUPD9_Pos)             /*!< 0x00080000 */
#define GPIO_PUPDR_PUPD10_Pos       (20U)
#define GPIO_PUPDR_PUPD10_Msk       (0x3UL << GPIO_PUPDR_PUPD10_Pos)  /*!< 0x00300000 */
#define GPIO_PUPDR_PUPD10           GPIO_PUPDR_PUPD10_Msk        /*!< </spirit:description> */
#define GPIO_PUPDR_PUPD10_0 (0x1UL << GPIO_PUPDR_PUPD10_Pos)               /*!< 0x00100000 */
#define GPIO_PUPDR_PUPD10_1 (0x2UL << GPIO_PUPDR_PUPD10_Pos)               /*!< 0x00200000 */
#define GPIO_PUPDR_PUPD11_Pos       (22U)
#define GPIO_PUPDR_PUPD11_Msk       (0x3UL << GPIO_PUPDR_PUPD11_Pos)  /*!< 0x00C00000 */
#define GPIO_PUPDR_PUPD11           GPIO_PUPDR_PUPD11_Msk        /*!< </spirit:description> */
#define GPIO_PUPDR_PUPD11_0 (0x1UL << GPIO_PUPDR_PUPD11_Pos)               /*!< 0x00400000 */
#define GPIO_PUPDR_PUPD11_1 (0x2UL << GPIO_PUPDR_PUPD11_Pos)               /*!< 0x00800000 */
#define GPIO_PUPDR_PUPD12_Pos       (24U)
#define GPIO_PUPDR_PUPD12_Msk       (0x3UL << GPIO_PUPDR_PUPD12_Pos)  /*!< 0x03000000 */
#define GPIO_PUPDR_PUPD12           GPIO_PUPDR_PUPD12_Msk        /*!< </spirit:description> */
#define GPIO_PUPDR_PUPD12_0 (0x1UL << GPIO_PUPDR_PUPD12_Pos)                /*!< 0x01000000 */
#define GPIO_PUPDR_PUPD12_1 (0x2UL << GPIO_PUPDR_PUPD12_Pos)                /*!< 0x02000000 */
#define GPIO_PUPDR_PUPD13_Pos       (26U)
#define GPIO_PUPDR_PUPD13_Msk       (0x3UL << GPIO_PUPDR_PUPD13_Pos)  /*!< 0x0C000000 */
#define GPIO_PUPDR_PUPD13           GPIO_PUPDR_PUPD13_Msk        /*!< </spirit:description> */
#define GPIO_PUPDR_PUPD13_0 (0x1UL << GPIO_PUPDR_PUPD13_Pos)                /*!< 0x04000000 */
#define GPIO_PUPDR_PUPD13_1 (0x2UL << GPIO_PUPDR_PUPD13_Pos)                /*!< 0x08000000 */
#define GPIO_PUPDR_PUPD14_Pos       (28U)
#define GPIO_PUPDR_PUPD14_Msk       (0x3UL << GPIO_PUPDR_PUPD14_Pos)  /*!< 0x30000000 */
#define GPIO_PUPDR_PUPD14           GPIO_PUPDR_PUPD14_Msk        /*!< </spirit:description> */
#define GPIO_PUPDR_PUPD14_0 (0x1UL << GPIO_PUPDR_PUPD14_Pos)                 /*!< 0x10000000 */
#define GPIO_PUPDR_PUPD14_1 (0x2UL << GPIO_PUPDR_PUPD14_Pos)                 /*!< 0x20000000 */
#define GPIO_PUPDR_PUPD15_Pos       (30U)
#define GPIO_PUPDR_PUPD15_Msk       (0x3UL << GPIO_PUPDR_PUPD15_Pos)  /*!< 0xC0000000 */
#define GPIO_PUPDR_PUPD15           GPIO_PUPDR_PUPD15_Msk        /*!< </spirit:description> */
#define GPIO_PUPDR_PUPD15_0 (0x1UL << GPIO_PUPDR_PUPD15_Pos)                 /*!< 0x40000000 */
#define GPIO_PUPDR_PUPD15_1 (0x2UL << GPIO_PUPDR_PUPD15_Pos)                 /*!< 0x80000000 */

/*******************  Bit definition for GPIO_IDR register  *******************/
#define GPIO_IDR_ID0_Pos            (0U)
#define GPIO_IDR_ID0_Msk              (0x1UL << GPIO_IDR_ID0_Pos)   /*!< 0x00000001 */
#define GPIO_IDR_ID0                GPIO_IDR_ID0_Msk             /*!< </spirit:description> */
#define GPIO_IDR_ID1_Pos            (1U)
#define GPIO_IDR_ID1_Msk              (0x1UL << GPIO_IDR_ID1_Pos)   /*!< 0x00000002 */
#define GPIO_IDR_ID1                GPIO_IDR_ID1_Msk             /*!< </spirit:description> */
#define GPIO_IDR_ID2_Pos            (2U)
#define GPIO_IDR_ID2_Msk              (0x1UL << GPIO_IDR_ID2_Pos)   /*!< 0x00000004 */
#define GPIO_IDR_ID2                GPIO_IDR_ID2_Msk             /*!< </spirit:description> */
#define GPIO_IDR_ID3_Pos            (3U)
#define GPIO_IDR_ID3_Msk              (0x1UL << GPIO_IDR_ID3_Pos)   /*!< 0x00000008 */
#define GPIO_IDR_ID3                GPIO_IDR_ID3_Msk             /*!< </spirit:description> */
#define GPIO_IDR_ID4_Pos            (4U)
#define GPIO_IDR_ID4_Msk              (0x1UL << GPIO_IDR_ID4_Pos)   /*!< 0x00000010 */
#define GPIO_IDR_ID4                GPIO_IDR_ID4_Msk             /*!< </spirit:description> */
#define GPIO_IDR_ID5_Pos            (5U)
#define GPIO_IDR_ID5_Msk              (0x1UL << GPIO_IDR_ID5_Pos)   /*!< 0x00000020 */
#define GPIO_IDR_ID5                GPIO_IDR_ID5_Msk             /*!< </spirit:description> */
#define GPIO_IDR_ID6_Pos            (6U)
#define GPIO_IDR_ID6_Msk              (0x1UL << GPIO_IDR_ID6_Pos)   /*!< 0x00000040 */
#define GPIO_IDR_ID6                GPIO_IDR_ID6_Msk             /*!< </spirit:description> */
#define GPIO_IDR_ID7_Pos            (7U)
#define GPIO_IDR_ID7_Msk              (0x1UL << GPIO_IDR_ID7_Pos)   /*!< 0x00000080 */
#define GPIO_IDR_ID7                GPIO_IDR_ID7_Msk             /*!< </spirit:description> */
#define GPIO_IDR_ID8_Pos            (8U)
#define GPIO_IDR_ID8_Msk              (0x1UL << GPIO_IDR_ID8_Pos)   /*!< 0x00000100 */
#define GPIO_IDR_ID8                GPIO_IDR_ID8_Msk             /*!< </spirit:description> */
#define GPIO_IDR_ID9_Pos            (9U)
#define GPIO_IDR_ID9_Msk              (0x1UL << GPIO_IDR_ID9_Pos)   /*!< 0x00000200 */
#define GPIO_IDR_ID9                GPIO_IDR_ID9_Msk             /*!< </spirit:description> */
#define GPIO_IDR_ID10_Pos           (10U)
#define GPIO_IDR_ID10_Msk           (0x1UL << GPIO_IDR_ID10_Pos)  /*!< 0x00000400 */
#define GPIO_IDR_ID10               GPIO_IDR_ID10_Msk            /*!< </spirit:description> */
#define GPIO_IDR_ID11_Pos           (11U)
#define GPIO_IDR_ID11_Msk           (0x1UL << GPIO_IDR_ID11_Pos)  /*!< 0x00000800 */
#define GPIO_IDR_ID11               GPIO_IDR_ID11_Msk            /*!< </spirit:description> */
#define GPIO_IDR_ID12_Pos           (12U)
#define GPIO_IDR_ID12_Msk           (0x1UL << GPIO_IDR_ID12_Pos)  /*!< 0x00001000 */
#define GPIO_IDR_ID12               GPIO_IDR_ID12_Msk            /*!< </spirit:description> */
#define GPIO_IDR_ID13_Pos           (13U)
#define GPIO_IDR_ID13_Msk           (0x1UL << GPIO_IDR_ID13_Pos)  /*!< 0x00002000 */
#define GPIO_IDR_ID13               GPIO_IDR_ID13_Msk            /*!< </spirit:description> */
#define GPIO_IDR_ID14_Pos           (14U)
#define GPIO_IDR_ID14_Msk           (0x1UL << GPIO_IDR_ID14_Pos)  /*!< 0x00004000 */
#define GPIO_IDR_ID14               GPIO_IDR_ID14_Msk            /*!< </spirit:description> */
#define GPIO_IDR_ID15_Pos           (15U)
#define GPIO_IDR_ID15_Msk           (0x1UL << GPIO_IDR_ID15_Pos)  /*!< 0x00008000 */
#define GPIO_IDR_ID15               GPIO_IDR_ID15_Msk            /*!< </spirit:description> */

/*******************  Bit definition for GPIO_ODR register  *******************/
#define GPIO_ODR_OD0_Pos            (0U)
#define GPIO_ODR_OD0_Msk              (0x1UL << GPIO_ODR_OD0_Pos)   /*!< 0x00000001 */
#define GPIO_ODR_OD0                GPIO_ODR_OD0_Msk             /*!< </spirit:description> */
#define GPIO_ODR_OD1_Pos            (1U)
#define GPIO_ODR_OD1_Msk              (0x1UL << GPIO_ODR_OD1_Pos)   /*!< 0x00000002 */
#define GPIO_ODR_OD1                GPIO_ODR_OD1_Msk             /*!< </spirit:description> */
#define GPIO_ODR_OD2_Pos            (2U)
#define GPIO_ODR_OD2_Msk              (0x1UL << GPIO_ODR_OD2_Pos)   /*!< 0x00000004 */
#define GPIO_ODR_OD2                GPIO_ODR_OD2_Msk             /*!< </spirit:description> */
#define GPIO_ODR_OD3_Pos            (3U)
#define GPIO_ODR_OD3_Msk              (0x1UL << GPIO_ODR_OD3_Pos)   /*!< 0x00000008 */
#define GPIO_ODR_OD3                GPIO_ODR_OD3_Msk             /*!< </spirit:description> */
#define GPIO_ODR_OD4_Pos            (4U)
#define GPIO_ODR_OD4_Msk              (0x1UL << GPIO_ODR_OD4_Pos)   /*!< 0x00000010 */
#define GPIO_ODR_OD4                GPIO_ODR_OD4_Msk             /*!< </spirit:description> */
#define GPIO_ODR_OD5_Pos            (5U)
#define GPIO_ODR_OD5_Msk              (0x1UL << GPIO_ODR_OD5_Pos)   /*!< 0x00000020 */
#define GPIO_ODR_OD5                GPIO_ODR_OD5_Msk             /*!< </spirit:description> */
#define GPIO_ODR_OD6_Pos            (6U)
#define GPIO_ODR_OD6_Msk              (0x1UL << GPIO_ODR_OD6_Pos)   /*!< 0x00000040 */
#define GPIO_ODR_OD6                GPIO_ODR_OD6_Msk             /*!< </spirit:description> */
#define GPIO_ODR_OD7_Pos            (7U)
#define GPIO_ODR_OD7_Msk              (0x1UL << GPIO_ODR_OD7_Pos)   /*!< 0x00000080 */
#define GPIO_ODR_OD7                GPIO_ODR_OD7_Msk             /*!< </spirit:description> */
#define GPIO_ODR_OD8_Pos            (8U)
#define GPIO_ODR_OD8_Msk              (0x1UL << GPIO_ODR_OD8_Pos)   /*!< 0x00000100 */
#define GPIO_ODR_OD8                GPIO_ODR_OD8_Msk             /*!< </spirit:description> */
#define GPIO_ODR_OD9_Pos            (9U)
#define GPIO_ODR_OD9_Msk              (0x1UL << GPIO_ODR_OD9_Pos)   /*!< 0x00000200 */
#define GPIO_ODR_OD9                GPIO_ODR_OD9_Msk             /*!< </spirit:description> */
#define GPIO_ODR_OD10_Pos           (10U)
#define GPIO_ODR_OD10_Msk           (0x1UL << GPIO_ODR_OD10_Pos)  /*!< 0x00000400 */
#define GPIO_ODR_OD10               GPIO_ODR_OD10_Msk            /*!< </spirit:description> */
#define GPIO_ODR_OD11_Pos           (11U)
#define GPIO_ODR_OD11_Msk           (0x1UL << GPIO_ODR_OD11_Pos)  /*!< 0x00000800 */
#define GPIO_ODR_OD11               GPIO_ODR_OD11_Msk            /*!< </spirit:description> */
#define GPIO_ODR_OD12_Pos           (12U)
#define GPIO_ODR_OD12_Msk           (0x1UL << GPIO_ODR_OD12_Pos)  /*!< 0x00001000 */
#define GPIO_ODR_OD12               GPIO_ODR_OD12_Msk            /*!< </spirit:description> */
#define GPIO_ODR_OD13_Pos           (13U)
#define GPIO_ODR_OD13_Msk           (0x1UL << GPIO_ODR_OD13_Pos)  /*!< 0x00002000 */
#define GPIO_ODR_OD13               GPIO_ODR_OD13_Msk            /*!< </spirit:description> */
#define GPIO_ODR_OD14_Pos           (14U)
#define GPIO_ODR_OD14_Msk           (0x1UL << GPIO_ODR_OD14_Pos)  /*!< 0x00004000 */
#define GPIO_ODR_OD14               GPIO_ODR_OD14_Msk            /*!< </spirit:description> */
#define GPIO_ODR_OD15_Pos           (15U)
#define GPIO_ODR_OD15_Msk           (0x1UL << GPIO_ODR_OD15_Pos)  /*!< 0x00008000 */
#define GPIO_ODR_OD15               GPIO_ODR_OD15_Msk            /*!< </spirit:description> */

/******************  Bit definition for GPIO_BSRR register  *******************/
#define GPIO_BSRR_BS0_Pos           (0U)
#define GPIO_BSRR_BS0_Msk           (0x1UL << GPIO_BSRR_BS0_Pos)  /*!< 0x00000001 */
#define GPIO_BSRR_BS0               GPIO_BSRR_BS0_Msk            /*!< </spirit:description> */
#define GPIO_BSRR_BS1_Pos           (1U)
#define GPIO_BSRR_BS1_Msk           (0x1UL << GPIO_BSRR_BS1_Pos)  /*!< 0x00000002 */
#define GPIO_BSRR_BS1               GPIO_BSRR_BS1_Msk            /*!< </spirit:description> */
#define GPIO_BSRR_BS2_Pos           (2U)
#define GPIO_BSRR_BS2_Msk           (0x1UL << GPIO_BSRR_BS2_Pos)  /*!< 0x00000004 */
#define GPIO_BSRR_BS2               GPIO_BSRR_BS2_Msk            /*!< </spirit:description> */
#define GPIO_BSRR_BS3_Pos           (3U)
#define GPIO_BSRR_BS3_Msk           (0x1UL << GPIO_BSRR_BS3_Pos)  /*!< 0x00000008 */
#define GPIO_BSRR_BS3               GPIO_BSRR_BS3_Msk            /*!< </spirit:description> */
#define GPIO_BSRR_BS4_Pos           (4U)
#define GPIO_BSRR_BS4_Msk           (0x1UL << GPIO_BSRR_BS4_Pos)  /*!< 0x00000010 */
#define GPIO_BSRR_BS4               GPIO_BSRR_BS4_Msk            /*!< </spirit:description> */
#define GPIO_BSRR_BS5_Pos           (5U)
#define GPIO_BSRR_BS5_Msk           (0x1UL << GPIO_BSRR_BS5_Pos)  /*!< 0x00000020 */
#define GPIO_BSRR_BS5               GPIO_BSRR_BS5_Msk            /*!< </spirit:description> */
#define GPIO_BSRR_BS6_Pos           (6U)
#define GPIO_BSRR_BS6_Msk           (0x1UL << GPIO_BSRR_BS6_Pos)  /*!< 0x00000040 */
#define GPIO_BSRR_BS6               GPIO_BSRR_BS6_Msk            /*!< </spirit:description> */
#define GPIO_BSRR_BS7_Pos           (7U)
#define GPIO_BSRR_BS7_Msk           (0x1UL << GPIO_BSRR_BS7_Pos)  /*!< 0x00000080 */
#define GPIO_BSRR_BS7               GPIO_BSRR_BS7_Msk            /*!< </spirit:description> */
#define GPIO_BSRR_BS8_Pos           (8U)
#define GPIO_BSRR_BS8_Msk           (0x1UL << GPIO_BSRR_BS8_Pos)  /*!< 0x00000100 */
#define GPIO_BSRR_BS8               GPIO_BSRR_BS8_Msk            /*!< </spirit:description> */
#define GPIO_BSRR_BS9_Pos           (9U)
#define GPIO_BSRR_BS9_Msk           (0x1UL << GPIO_BSRR_BS9_Pos)  /*!< 0x00000200 */
#define GPIO_BSRR_BS9               GPIO_BSRR_BS9_Msk            /*!< </spirit:description> */
#define GPIO_BSRR_BS10_Pos          (10U)
#define GPIO_BSRR_BS10_Msk          (0x1UL << GPIO_BSRR_BS10_Pos) /*!< 0x00000400 */
#define GPIO_BSRR_BS10              GPIO_BSRR_BS10_Msk           /*!< </spirit:description> */
#define GPIO_BSRR_BS11_Pos          (11U)
#define GPIO_BSRR_BS11_Msk          (0x1UL << GPIO_BSRR_BS11_Pos) /*!< 0x00000800 */
#define GPIO_BSRR_BS11              GPIO_BSRR_BS11_Msk           /*!< </spirit:description> */
#define GPIO_BSRR_BS12_Pos          (12U)
#define GPIO_BSRR_BS12_Msk          (0x1UL << GPIO_BSRR_BS12_Pos) /*!< 0x00001000 */
#define GPIO_BSRR_BS12              GPIO_BSRR_BS12_Msk           /*!< </spirit:description> */
#define GPIO_BSRR_BS13_Pos          (13U)
#define GPIO_BSRR_BS13_Msk          (0x1UL << GPIO_BSRR_BS13_Pos) /*!< 0x00002000 */
#define GPIO_BSRR_BS13              GPIO_BSRR_BS13_Msk           /*!< </spirit:description> */
#define GPIO_BSRR_BS14_Pos          (14U)
#define GPIO_BSRR_BS14_Msk          (0x1UL << GPIO_BSRR_BS14_Pos) /*!< 0x00004000 */
#define GPIO_BSRR_BS14              GPIO_BSRR_BS14_Msk           /*!< </spirit:description> */
#define GPIO_BSRR_BS15_Pos          (15U)
#define GPIO_BSRR_BS15_Msk          (0x1UL << GPIO_BSRR_BS15_Pos) /*!< 0x00008000 */
#define GPIO_BSRR_BS15              GPIO_BSRR_BS15_Msk           /*!< </spirit:description> */
#define GPIO_BSRR_BR0_Pos           (16U)
#define GPIO_BSRR_BR0_Msk           (0x1UL << GPIO_BSRR_BR0_Pos)  /*!< 0x00010000 */
#define GPIO_BSRR_BR0               GPIO_BSRR_BR0_Msk            /*!< </spirit:description> */
#define GPIO_BSRR_BR1_Pos           (17U)
#define GPIO_BSRR_BR1_Msk           (0x1UL << GPIO_BSRR_BR1_Pos)  /*!< 0x00020000 */
#define GPIO_BSRR_BR1               GPIO_BSRR_BR1_Msk            /*!< </spirit:description> */
#define GPIO_BSRR_BR2_Pos           (18U)
#define GPIO_BSRR_BR2_Msk           (0x1UL << GPIO_BSRR_BR2_Pos)  /*!< 0x00040000 */
#define GPIO_BSRR_BR2               GPIO_BSRR_BR2_Msk            /*!< </spirit:description> */
#define GPIO_BSRR_BR3_Pos           (19U)
#define GPIO_BSRR_BR3_Msk           (0x1UL << GPIO_BSRR_BR3_Pos)  /*!< 0x00080000 */
#define GPIO_BSRR_BR3               GPIO_BSRR_BR3_Msk            /*!< </spirit:description> */
#define GPIO_BSRR_BR4_Pos           (20U)
#define GPIO_BSRR_BR4_Msk           (0x1UL << GPIO_BSRR_BR4_Pos)  /*!< 0x00100000 */
#define GPIO_BSRR_BR4               GPIO_BSRR_BR4_Msk            /*!< </spirit:description> */
#define GPIO_BSRR_BR5_Pos           (21U)
#define GPIO_BSRR_BR5_Msk           (0x1UL << GPIO_BSRR_BR5_Pos)  /*!< 0x00200000 */
#define GPIO_BSRR_BR5               GPIO_BSRR_BR5_Msk            /*!< </spirit:description> */
#define GPIO_BSRR_BR6_Pos           (22U)
#define GPIO_BSRR_BR6_Msk           (0x1UL << GPIO_BSRR_BR6_Pos)  /*!< 0x00400000 */
#define GPIO_BSRR_BR6               GPIO_BSRR_BR6_Msk            /*!< </spirit:description> */
#define GPIO_BSRR_BR7_Pos           (23U)
#define GPIO_BSRR_BR7_Msk           (0x1UL << GPIO_BSRR_BR7_Pos)  /*!< 0x00800000 */
#define GPIO_BSRR_BR7               GPIO_BSRR_BR7_Msk            /*!< </spirit:description> */
#define GPIO_BSRR_BR8_Pos           (24U)
#define GPIO_BSRR_BR8_Msk           (0x1UL << GPIO_BSRR_BR8_Pos)  /*!< 0x01000000 */
#define GPIO_BSRR_BR8               GPIO_BSRR_BR8_Msk            /*!< </spirit:description> */
#define GPIO_BSRR_BR9_Pos           (25U)
#define GPIO_BSRR_BR9_Msk           (0x1UL << GPIO_BSRR_BR9_Pos)  /*!< 0x02000000 */
#define GPIO_BSRR_BR9               GPIO_BSRR_BR9_Msk            /*!< </spirit:description> */
#define GPIO_BSRR_BR10_Pos          (26U)
#define GPIO_BSRR_BR10_Msk          (0x1UL << GPIO_BSRR_BR10_Pos) /*!< 0x04000000 */
#define GPIO_BSRR_BR10              GPIO_BSRR_BR10_Msk           /*!< </spirit:description> */
#define GPIO_BSRR_BR11_Pos          (27U)
#define GPIO_BSRR_BR11_Msk          (0x1UL << GPIO_BSRR_BR11_Pos) /*!< 0x08000000 */
#define GPIO_BSRR_BR11              GPIO_BSRR_BR11_Msk           /*!< </spirit:description> */
#define GPIO_BSRR_BR12_Pos          (28U)
#define GPIO_BSRR_BR12_Msk          (0x1UL << GPIO_BSRR_BR12_Pos) /*!< 0x10000000 */
#define GPIO_BSRR_BR12              GPIO_BSRR_BR12_Msk           /*!< </spirit:description> */
#define GPIO_BSRR_BR13_Pos          (29U)
#define GPIO_BSRR_BR13_Msk          (0x1UL << GPIO_BSRR_BR13_Pos) /*!< 0x20000000 */
#define GPIO_BSRR_BR13              GPIO_BSRR_BR13_Msk           /*!< </spirit:description> */
#define GPIO_BSRR_BR14_Pos          (30U)
#define GPIO_BSRR_BR14_Msk          (0x1UL << GPIO_BSRR_BR14_Pos) /*!< 0x40000000 */
#define GPIO_BSRR_BR14              GPIO_BSRR_BR14_Msk           /*!< </spirit:description> */
#define GPIO_BSRR_BR15_Pos          (31U)
#define GPIO_BSRR_BR15_Msk          (0x1UL << GPIO_BSRR_BR15_Pos) /*!< 0x80000000 */
#define GPIO_BSRR_BR15              GPIO_BSRR_BR15_Msk           /*!< </spirit:description> */

/******************  Bit definition for GPIO_LCKR register  *******************/
#define GPIO_LCKR_LCK0_Pos          (0U)
#define GPIO_LCKR_LCK0_Msk          (0x1UL << GPIO_LCKR_LCK0_Pos) /*!< 0x00000001 */
#define GPIO_LCKR_LCK0              GPIO_LCKR_LCK0_Msk           /*!< </spirit:description> */
#define GPIO_LCKR_LCK1_Pos          (1U)
#define GPIO_LCKR_LCK1_Msk          (0x1UL << GPIO_LCKR_LCK1_Pos) /*!< 0x00000002 */
#define GPIO_LCKR_LCK1              GPIO_LCKR_LCK1_Msk           /*!< </spirit:description> */
#define GPIO_LCKR_LCK2_Pos          (2U)
#define GPIO_LCKR_LCK2_Msk          (0x1UL << GPIO_LCKR_LCK2_Pos) /*!< 0x00000004 */
#define GPIO_LCKR_LCK2              GPIO_LCKR_LCK2_Msk           /*!< </spirit:description> */
#define GPIO_LCKR_LCK3_Pos          (3U)
#define GPIO_LCKR_LCK3_Msk          (0x1UL << GPIO_LCKR_LCK3_Pos) /*!< 0x00000008 */
#define GPIO_LCKR_LCK3              GPIO_LCKR_LCK3_Msk           /*!< </spirit:description> */
#define GPIO_LCKR_LCK4_Pos          (4U)
#define GPIO_LCKR_LCK4_Msk          (0x1UL << GPIO_LCKR_LCK4_Pos) /*!< 0x00000010 */
#define GPIO_LCKR_LCK4              GPIO_LCKR_LCK4_Msk           /*!< </spirit:description> */
#define GPIO_LCKR_LCK5_Pos          (5U)
#define GPIO_LCKR_LCK5_Msk          (0x1UL << GPIO_LCKR_LCK5_Pos) /*!< 0x00000020 */
#define GPIO_LCKR_LCK5              GPIO_LCKR_LCK5_Msk           /*!< </spirit:description> */
#define GPIO_LCKR_LCK6_Pos          (6U)
#define GPIO_LCKR_LCK6_Msk          (0x1UL << GPIO_LCKR_LCK6_Pos) /*!< 0x00000040 */
#define GPIO_LCKR_LCK6              GPIO_LCKR_LCK6_Msk           /*!< </spirit:description> */
#define GPIO_LCKR_LCK7_Pos          (7U)
#define GPIO_LCKR_LCK7_Msk          (0x1UL << GPIO_LCKR_LCK7_Pos) /*!< 0x00000080 */
#define GPIO_LCKR_LCK7              GPIO_LCKR_LCK7_Msk           /*!< </spirit:description> */
#define GPIO_LCKR_LCK8_Pos          (8U)
#define GPIO_LCKR_LCK8_Msk          (0x1UL << GPIO_LCKR_LCK8_Pos) /*!< 0x00000100 */
#define GPIO_LCKR_LCK8              GPIO_LCKR_LCK8_Msk           /*!< </spirit:description> */
#define GPIO_LCKR_LCK9_Pos          (9U)
#define GPIO_LCKR_LCK9_Msk          (0x1UL << GPIO_LCKR_LCK9_Pos) /*!< 0x00000200 */
#define GPIO_LCKR_LCK9              GPIO_LCKR_LCK9_Msk           /*!< </spirit:description> */
#define GPIO_LCKR_LCK10_Pos         (10U)
#define GPIO_LCKR_LCK10_Msk          (0x1UL << GPIO_LCKR_LCK10_Pos)   /*!< 0x00000400 */
#define GPIO_LCKR_LCK10             GPIO_LCKR_LCK10_Msk          /*!< </spirit:description> */
#define GPIO_LCKR_LCK11_Pos         (11U)
#define GPIO_LCKR_LCK11_Msk          (0x1UL << GPIO_LCKR_LCK11_Pos)   /*!< 0x00000800 */
#define GPIO_LCKR_LCK11             GPIO_LCKR_LCK11_Msk          /*!< </spirit:description> */
#define GPIO_LCKR_LCK12_Pos         (12U)
#define GPIO_LCKR_LCK12_Msk          (0x1UL << GPIO_LCKR_LCK12_Pos)   /*!< 0x00001000 */
#define GPIO_LCKR_LCK12             GPIO_LCKR_LCK12_Msk          /*!< </spirit:description> */
#define GPIO_LCKR_LCK13_Pos         (13U)
#define GPIO_LCKR_LCK13_Msk          (0x1UL << GPIO_LCKR_LCK13_Pos)   /*!< 0x00002000 */
#define GPIO_LCKR_LCK13             GPIO_LCKR_LCK13_Msk          /*!< </spirit:description> */
#define GPIO_LCKR_LCK14_Pos         (14U)
#define GPIO_LCKR_LCK14_Msk          (0x1UL << GPIO_LCKR_LCK14_Pos)   /*!< 0x00004000 */
#define GPIO_LCKR_LCK14             GPIO_LCKR_LCK14_Msk          /*!< </spirit:description> */
#define GPIO_LCKR_LCK15_Pos         (15U)
#define GPIO_LCKR_LCK15_Msk          (0x1UL << GPIO_LCKR_LCK15_Pos)   /*!< 0x00008000 */
#define GPIO_LCKR_LCK15             GPIO_LCKR_LCK15_Msk          /*!< </spirit:description> */
#define GPIO_LCKR_LCKK_Pos          (16U)
#define GPIO_LCKR_LCKK_Msk          (0x1UL << GPIO_LCKR_LCKK_Pos) /*!< 0x00010000 */
#define GPIO_LCKR_LCKK              GPIO_LCKR_LCKK_Msk           /*!< </spirit:description> */

/*******************  Bit definition for GPIO_AFR register  *******************/
#define GPIO_AFR_AFSEL0_Pos          (0U)
#define GPIO_AFR_AFSEL0_Msk          (0xFUL << GPIO_AFR_AFSEL0_Pos)   /*!< 0x0000000F */
#define GPIO_AFR_AFSEL0              GPIO_AFR_AFSEL0_Msk       /*!< </spirit:description> */
#define GPIO_AFR_AFSEL0_0   (0x1UL << GPIO_AFR_AFSEL0_Pos)        /*!< 0x00000001 */
#define GPIO_AFR_AFSEL0_1   (0x2UL << GPIO_AFR_AFSEL0_Pos)        /*!< 0x00000002 */
#define GPIO_AFR_AFSEL0_2   (0x4UL << GPIO_AFR_AFSEL0_Pos)        /*!< 0x00000004 */
#define GPIO_AFR_AFSEL0_3   (0x8UL << GPIO_AFR_AFSEL0_Pos)        /*!< 0x00000008 */
#define GPIO_AFR_AFSEL1_Pos          (4U)
#define GPIO_AFR_AFSEL1_Msk          (0xFUL << GPIO_AFR_AFSEL1_Pos)   /*!< 0x000000F0 */
#define GPIO_AFR_AFSEL1              GPIO_AFR_AFSEL1_Msk       /*!< </spirit:description> */
#define GPIO_AFR_AFSEL1_0   (0x1UL << GPIO_AFR_AFSEL1_Pos)         /*!< 0x00000010 */
#define GPIO_AFR_AFSEL1_1   (0x2UL << GPIO_AFR_AFSEL1_Pos)         /*!< 0x00000020 */
#define GPIO_AFR_AFSEL1_2   (0x4UL << GPIO_AFR_AFSEL1_Pos)         /*!< 0x00000040 */
#define GPIO_AFR_AFSEL1_3   (0x8UL << GPIO_AFR_AFSEL1_Pos)         /*!< 0x00000080 */
#define GPIO_AFR_AFSEL2_Pos          (8U)
#define GPIO_AFR_AFSEL2_Msk          (0xFUL << GPIO_AFR_AFSEL2_Pos)   /*!< 0x00000F00 */
#define GPIO_AFR_AFSEL2              GPIO_AFR_AFSEL2_Msk       /*!< </spirit:description> */
#define GPIO_AFR_AFSEL2_0   (0x1UL << GPIO_AFR_AFSEL2_Pos)          /*!< 0x00000100 */
#define GPIO_AFR_AFSEL2_1   (0x2UL << GPIO_AFR_AFSEL2_Pos)          /*!< 0x00000200 */
#define GPIO_AFR_AFSEL2_2   (0x4UL << GPIO_AFR_AFSEL2_Pos)          /*!< 0x00000400 */
#define GPIO_AFR_AFSEL2_3   (0x8UL << GPIO_AFR_AFSEL2_Pos)          /*!< 0x00000800 */
#define GPIO_AFR_AFSEL3_Pos          (12U)
#define GPIO_AFR_AFSEL3_Msk          (0xFUL << GPIO_AFR_AFSEL3_Pos)   /*!< 0x0000F000 */
#define GPIO_AFR_AFSEL3              GPIO_AFR_AFSEL3_Msk       /*!< </spirit:description> */
#define GPIO_AFR_AFSEL3_0   (0x1UL << GPIO_AFR_AFSEL3_Pos)           /*!< 0x00001000 */
#define GPIO_AFR_AFSEL3_1   (0x2UL << GPIO_AFR_AFSEL3_Pos)           /*!< 0x00002000 */
#define GPIO_AFR_AFSEL3_2   (0x4UL << GPIO_AFR_AFSEL3_Pos)           /*!< 0x00004000 */
#define GPIO_AFR_AFSEL3_3   (0x8UL << GPIO_AFR_AFSEL3_Pos)           /*!< 0x00008000 */
#define GPIO_AFR_AFSEL4_Pos          (16U)
#define GPIO_AFR_AFSEL4_Msk          (0xFUL << GPIO_AFR_AFSEL4_Pos)   /*!< 0x000F0000 */
#define GPIO_AFR_AFSEL4              GPIO_AFR_AFSEL4_Msk       /*!< </spirit:description> */
#define GPIO_AFR_AFSEL4_0   (0x1UL << GPIO_AFR_AFSEL4_Pos)            /*!< 0x00010000 */
#define GPIO_AFR_AFSEL4_1   (0x2UL << GPIO_AFR_AFSEL4_Pos)            /*!< 0x00020000 */
#define GPIO_AFR_AFSEL4_2   (0x4UL << GPIO_AFR_AFSEL4_Pos)            /*!< 0x00040000 */
#define GPIO_AFR_AFSEL4_3   (0x8UL << GPIO_AFR_AFSEL4_Pos)            /*!< 0x00080000 */
#define GPIO_AFR_AFSEL5_Pos          (20U)
#define GPIO_AFR_AFSEL5_Msk          (0xFUL << GPIO_AFR_AFSEL5_Pos)   /*!< 0x00F00000 */
#define GPIO_AFR_AFSEL5              GPIO_AFR_AFSEL5_Msk       /*!< </spirit:description> */
#define GPIO_AFR_AFSEL5_0   (0x1UL << GPIO_AFR_AFSEL5_Pos)             /*!< 0x00100000 */
#define GPIO_AFR_AFSEL5_1   (0x2UL << GPIO_AFR_AFSEL5_Pos)             /*!< 0x00200000 */
#define GPIO_AFR_AFSEL5_2   (0x4UL << GPIO_AFR_AFSEL5_Pos)             /*!< 0x00400000 */
#define GPIO_AFR_AFSEL5_3   (0x8UL << GPIO_AFR_AFSEL5_Pos)             /*!< 0x00800000 */
#define GPIO_AFR_AFSEL6_Pos          (24U)
#define GPIO_AFR_AFSEL6_Msk          (0xFUL << GPIO_AFR_AFSEL6_Pos)   /*!< 0x0F000000 */
#define GPIO_AFR_AFSEL6              GPIO_AFR_AFSEL6_Msk       /*!< </spirit:description> */
#define GPIO_AFR_AFSEL6_0   (0x1UL << GPIO_AFR_AFSEL6_Pos)              /*!< 0x01000000 */
#define GPIO_AFR_AFSEL6_1   (0x2UL << GPIO_AFR_AFSEL6_Pos)              /*!< 0x02000000 */
#define GPIO_AFR_AFSEL6_2   (0x4UL << GPIO_AFR_AFSEL6_Pos)              /*!< 0x04000000 */
#define GPIO_AFR_AFSEL6_3   (0x8UL << GPIO_AFR_AFSEL6_Pos)              /*!< 0x08000000 */
#define GPIO_AFR_AFSEL7_Pos          (28U)
#define GPIO_AFR_AFSEL7_Msk          (0xFUL << GPIO_AFR_AFSEL7_Pos)   /*!< 0xF0000000 */
#define GPIO_AFR_AFSEL7              GPIO_AFR_AFSEL7_Msk       /*!< </spirit:description> */
#define GPIO_AFR_AFSEL7_0   (0x1UL << GPIO_AFR_AFSEL7_Pos)               /*!< 0x10000000 */
#define GPIO_AFR_AFSEL7_1   (0x2UL << GPIO_AFR_AFSEL7_Pos)               /*!< 0x20000000 */
#define GPIO_AFR_AFSEL7_2   (0x4UL << GPIO_AFR_AFSEL7_Pos)               /*!< 0x40000000 */
#define GPIO_AFR_AFSEL7_3   (0x8UL << GPIO_AFR_AFSEL7_Pos)               /*!< 0x80000000 */

/*****************  Bit definition for GPIO_IHYSTR register  ******************/
#define GPIO_IHYSTR_IHYSTR0_Pos     (0U)
#define GPIO_IHYSTR_IHYSTR0_Msk     (0x3UL << GPIO_IHYSTR_IHYSTR0_Pos)    /*!< 0x00000003 */
#define GPIO_IHYSTR_IHYSTR0         GPIO_IHYSTR_IHYSTR0_Msk      /*!< </spirit:description> */
#define GPIO_IHYSTR_IHYSTR0_0   (0x1UL << GPIO_IHYSTR_IHYSTR0_Pos)            /*!< 0x00000001 */
#define GPIO_IHYSTR_IHYSTR0_1   (0x2UL << GPIO_IHYSTR_IHYSTR0_Pos)            /*!< 0x00000002 */
#define GPIO_IHYSTR_IHYSTR1_Pos     (2U)
#define GPIO_IHYSTR_IHYSTR1_Msk     (0x3UL << GPIO_IHYSTR_IHYSTR1_Pos)    /*!< 0x0000000C */
#define GPIO_IHYSTR_IHYSTR1         GPIO_IHYSTR_IHYSTR1_Msk      /*!< </spirit:description> */
#define GPIO_IHYSTR_IHYSTR1_0   (0x1UL << GPIO_IHYSTR_IHYSTR1_Pos)            /*!< 0x00000004 */
#define GPIO_IHYSTR_IHYSTR1_1   (0x2UL << GPIO_IHYSTR_IHYSTR1_Pos)            /*!< 0x00000008 */
#define GPIO_IHYSTR_IHYSTR2_Pos     (4U)
#define GPIO_IHYSTR_IHYSTR2_Msk     (0x3UL << GPIO_IHYSTR_IHYSTR2_Pos)    /*!< 0x00000030 */
#define GPIO_IHYSTR_IHYSTR2         GPIO_IHYSTR_IHYSTR2_Msk      /*!< </spirit:description> */
#define GPIO_IHYSTR_IHYSTR2_0   (0x1UL << GPIO_IHYSTR_IHYSTR2_Pos)             /*!< 0x00000010 */
#define GPIO_IHYSTR_IHYSTR2_1   (0x2UL << GPIO_IHYSTR_IHYSTR2_Pos)             /*!< 0x00000020 */
#define GPIO_IHYSTR_IHYSTR3_Pos     (6U)
#define GPIO_IHYSTR_IHYSTR3_Msk     (0x3UL << GPIO_IHYSTR_IHYSTR3_Pos)    /*!< 0x000000C0 */
#define GPIO_IHYSTR_IHYSTR3         GPIO_IHYSTR_IHYSTR3_Msk      /*!< </spirit:description> */
#define GPIO_IHYSTR_IHYSTR3_0   (0x1UL << GPIO_IHYSTR_IHYSTR3_Pos)             /*!< 0x00000040 */
#define GPIO_IHYSTR_IHYSTR3_1   (0x2UL << GPIO_IHYSTR_IHYSTR3_Pos)             /*!< 0x00000080 */
#define GPIO_IHYSTR_IHYSTR4_Pos     (8U)
#define GPIO_IHYSTR_IHYSTR4_Msk     (0x3UL << GPIO_IHYSTR_IHYSTR4_Pos)    /*!< 0x00000300 */
#define GPIO_IHYSTR_IHYSTR4         GPIO_IHYSTR_IHYSTR4_Msk      /*!< </spirit:description> */
#define GPIO_IHYSTR_IHYSTR4_0   (0x1UL << GPIO_IHYSTR_IHYSTR4_Pos)              /*!< 0x00000100 */
#define GPIO_IHYSTR_IHYSTR4_1   (0x2UL << GPIO_IHYSTR_IHYSTR4_Pos)              /*!< 0x00000200 */
#define GPIO_IHYSTR_IHYSTR5_Pos     (10U)
#define GPIO_IHYSTR_IHYSTR5_Msk     (0x3UL << GPIO_IHYSTR_IHYSTR5_Pos)    /*!< 0x00000C00 */
#define GPIO_IHYSTR_IHYSTR5         GPIO_IHYSTR_IHYSTR5_Msk      /*!< </spirit:description> */
#define GPIO_IHYSTR_IHYSTR5_0   (0x1UL << GPIO_IHYSTR_IHYSTR5_Pos)              /*!< 0x00000400 */
#define GPIO_IHYSTR_IHYSTR5_1   (0x2UL << GPIO_IHYSTR_IHYSTR5_Pos)              /*!< 0x00000800 */
#define GPIO_IHYSTR_IHYSTR6_Pos     (12U)
#define GPIO_IHYSTR_IHYSTR6_Msk     (0x3UL << GPIO_IHYSTR_IHYSTR6_Pos)    /*!< 0x00003000 */
#define GPIO_IHYSTR_IHYSTR6         GPIO_IHYSTR_IHYSTR6_Msk      /*!< </spirit:description> */
#define GPIO_IHYSTR_IHYSTR6_0   (0x1UL << GPIO_IHYSTR_IHYSTR6_Pos)               /*!< 0x00001000 */
#define GPIO_IHYSTR_IHYSTR6_1   (0x2UL << GPIO_IHYSTR_IHYSTR6_Pos)               /*!< 0x00002000 */
#define GPIO_IHYSTR_IHYSTR7_Pos     (14U)
#define GPIO_IHYSTR_IHYSTR7_Msk     (0x3UL << GPIO_IHYSTR_IHYSTR7_Pos)    /*!< 0x0000C000 */
#define GPIO_IHYSTR_IHYSTR7         GPIO_IHYSTR_IHYSTR7_Msk      /*!< </spirit:description> */
#define GPIO_IHYSTR_IHYSTR7_0   (0x1UL << GPIO_IHYSTR_IHYSTR7_Pos)               /*!< 0x00004000 */
#define GPIO_IHYSTR_IHYSTR7_1   (0x2UL << GPIO_IHYSTR_IHYSTR7_Pos)               /*!< 0x00008000 */
#define GPIO_IHYSTR_IHYSTR8_Pos     (16U)
#define GPIO_IHYSTR_IHYSTR8_Msk     (0x3UL << GPIO_IHYSTR_IHYSTR8_Pos)    /*!< 0x00030000 */
#define GPIO_IHYSTR_IHYSTR8         GPIO_IHYSTR_IHYSTR8_Msk      /*!< </spirit:description> */
#define GPIO_IHYSTR_IHYSTR8_0   (0x1UL << GPIO_IHYSTR_IHYSTR8_Pos)                /*!< 0x00010000 */
#define GPIO_IHYSTR_IHYSTR8_1   (0x2UL << GPIO_IHYSTR_IHYSTR8_Pos)                /*!< 0x00020000 */
#define GPIO_IHYSTR_IHYSTR9_Pos     (18U)
#define GPIO_IHYSTR_IHYSTR9_Msk     (0x3UL << GPIO_IHYSTR_IHYSTR9_Pos)    /*!< 0x000C0000 */
#define GPIO_IHYSTR_IHYSTR9         GPIO_IHYSTR_IHYSTR9_Msk      /*!< </spirit:description> */
#define GPIO_IHYSTR_IHYSTR9_0   (0x1UL << GPIO_IHYSTR_IHYSTR9_Pos)                /*!< 0x00040000 */
#define GPIO_IHYSTR_IHYSTR9_1   (0x2UL << GPIO_IHYSTR_IHYSTR9_Pos)                /*!< 0x00080000 */
#define GPIO_IHYSTR_IHYSTR10_Pos    (20U)
#define GPIO_IHYSTR_IHYSTR10_Msk    (0x3UL << GPIO_IHYSTR_IHYSTR10_Pos)     /*!< 0x00300000 */
#define GPIO_IHYSTR_IHYSTR10        GPIO_IHYSTR_IHYSTR10_Msk     /*!< </spirit:description> */
#define GPIO_IHYSTR_IHYSTR10_0    (0x1UL << GPIO_IHYSTR_IHYSTR10_Pos)                  /*!< 0x00100000 */
#define GPIO_IHYSTR_IHYSTR10_1    (0x2UL << GPIO_IHYSTR_IHYSTR10_Pos)                  /*!< 0x00200000 */
#define GPIO_IHYSTR_IHYSTR11_Pos    (22U)
#define GPIO_IHYSTR_IHYSTR11_Msk    (0x3UL << GPIO_IHYSTR_IHYSTR11_Pos)     /*!< 0x00C00000 */
#define GPIO_IHYSTR_IHYSTR11        GPIO_IHYSTR_IHYSTR11_Msk     /*!< </spirit:description> */
#define GPIO_IHYSTR_IHYSTR11_0    (0x1UL << GPIO_IHYSTR_IHYSTR11_Pos)                  /*!< 0x00400000 */
#define GPIO_IHYSTR_IHYSTR11_1    (0x2UL << GPIO_IHYSTR_IHYSTR11_Pos)                  /*!< 0x00800000 */
#define GPIO_IHYSTR_IHYSTR12_Pos    (24U)
#define GPIO_IHYSTR_IHYSTR12_Msk    (0x3UL << GPIO_IHYSTR_IHYSTR12_Pos)     /*!< 0x03000000 */
#define GPIO_IHYSTR_IHYSTR12        GPIO_IHYSTR_IHYSTR12_Msk     /*!< </spirit:description> */
#define GPIO_IHYSTR_IHYSTR12_0    (0x1UL << GPIO_IHYSTR_IHYSTR12_Pos)                   /*!< 0x01000000 */
#define GPIO_IHYSTR_IHYSTR12_1    (0x2UL << GPIO_IHYSTR_IHYSTR12_Pos)                   /*!< 0x02000000 */
#define GPIO_IHYSTR_IHYSTR13_Pos    (26U)
#define GPIO_IHYSTR_IHYSTR13_Msk    (0x3UL << GPIO_IHYSTR_IHYSTR13_Pos)     /*!< 0x0C000000 */
#define GPIO_IHYSTR_IHYSTR13        GPIO_IHYSTR_IHYSTR13_Msk     /*!< </spirit:description> */
#define GPIO_IHYSTR_IHYSTR13_0    (0x1UL << GPIO_IHYSTR_IHYSTR13_Pos)                   /*!< 0x04000000 */
#define GPIO_IHYSTR_IHYSTR13_1    (0x2UL << GPIO_IHYSTR_IHYSTR13_Pos)                   /*!< 0x08000000 */
#define GPIO_IHYSTR_IHYSTR14_Pos    (28U)
#define GPIO_IHYSTR_IHYSTR14_Msk    (0x3UL << GPIO_IHYSTR_IHYSTR14_Pos)     /*!< 0x30000000 */
#define GPIO_IHYSTR_IHYSTR14        GPIO_IHYSTR_IHYSTR14_Msk     /*!< </spirit:description> */
#define GPIO_IHYSTR_IHYSTR14_0    (0x1UL << GPIO_IHYSTR_IHYSTR14_Pos)                    /*!< 0x10000000 */
#define GPIO_IHYSTR_IHYSTR14_1    (0x2UL << GPIO_IHYSTR_IHYSTR14_Pos)                    /*!< 0x20000000 */
#define GPIO_IHYSTR_IHYSTR15_Pos    (30U)
#define GPIO_IHYSTR_IHYSTR15_Msk    (0x3UL << GPIO_IHYSTR_IHYSTR15_Pos)     /*!< 0xC0000000 */
#define GPIO_IHYSTR_IHYSTR15        GPIO_IHYSTR_IHYSTR15_Msk     /*!< </spirit:description> */
#define GPIO_IHYSTR_IHYSTR15_0    (0x1UL << GPIO_IHYSTR_IHYSTR15_Pos)                    /*!< 0x40000000 */
#define GPIO_IHYSTR_IHYSTR15_1    (0x2UL << GPIO_IHYSTR_IHYSTR15_Pos)                    /*!< 0x80000000 */

/*****************  Bit definition for GPIO_TRIGENR register  *****************/
#define GPIO_TRIGENR_TR0_Pos        (0U)
#define GPIO_TRIGENR_TR0_Msk        (0x1UL << GPIO_TRIGENR_TR0_Pos) /*!< 0x00000001 */
#define GPIO_TRIGENR_TR0            GPIO_TRIGENR_TR0_Msk         /*!< </spirit:description> */
#define GPIO_TRIGENR_TR1_Pos        (1U)
#define GPIO_TRIGENR_TR1_Msk        (0x1UL << GPIO_TRIGENR_TR1_Pos) /*!< 0x00000002 */
#define GPIO_TRIGENR_TR1            GPIO_TRIGENR_TR1_Msk         /*!< </spirit:description> */
#define GPIO_TRIGENR_TR2_Pos        (2U)
#define GPIO_TRIGENR_TR2_Msk        (0x1UL << GPIO_TRIGENR_TR2_Pos) /*!< 0x00000004 */
#define GPIO_TRIGENR_TR2            GPIO_TRIGENR_TR2_Msk         /*!< </spirit:description> */
#define GPIO_TRIGENR_TR3_Pos        (3U)
#define GPIO_TRIGENR_TR3_Msk        (0x1UL << GPIO_TRIGENR_TR3_Pos) /*!< 0x00000008 */
#define GPIO_TRIGENR_TR3            GPIO_TRIGENR_TR3_Msk         /*!< </spirit:description> */
#define GPIO_TRIGENR_TR4_Pos        (4U)
#define GPIO_TRIGENR_TR4_Msk        (0x1UL << GPIO_TRIGENR_TR4_Pos) /*!< 0x00000010 */
#define GPIO_TRIGENR_TR4            GPIO_TRIGENR_TR4_Msk         /*!< </spirit:description> */
#define GPIO_TRIGENR_TR5_Pos        (5U)
#define GPIO_TRIGENR_TR5_Msk        (0x1UL << GPIO_TRIGENR_TR5_Pos) /*!< 0x00000020 */
#define GPIO_TRIGENR_TR5            GPIO_TRIGENR_TR5_Msk         /*!< </spirit:description> */
#define GPIO_TRIGENR_TR6_Pos        (6U)
#define GPIO_TRIGENR_TR6_Msk        (0x1UL << GPIO_TRIGENR_TR6_Pos) /*!< 0x00000040 */
#define GPIO_TRIGENR_TR6            GPIO_TRIGENR_TR6_Msk         /*!< </spirit:description> */
#define GPIO_TRIGENR_TR7_Pos        (7U)
#define GPIO_TRIGENR_TR7_Msk        (0x1UL << GPIO_TRIGENR_TR7_Pos) /*!< 0x00000080 */
#define GPIO_TRIGENR_TR7            GPIO_TRIGENR_TR7_Msk         /*!< </spirit:description> */
#define GPIO_TRIGENR_TR8_Pos        (8U)
#define GPIO_TRIGENR_TR8_Msk        (0x1UL << GPIO_TRIGENR_TR8_Pos) /*!< 0x00000100 */
#define GPIO_TRIGENR_TR8            GPIO_TRIGENR_TR8_Msk         /*!< </spirit:description> */
#define GPIO_TRIGENR_TR9_Pos        (9U)
#define GPIO_TRIGENR_TR9_Msk        (0x1UL << GPIO_TRIGENR_TR9_Pos) /*!< 0x00000200 */
#define GPIO_TRIGENR_TR9            GPIO_TRIGENR_TR9_Msk         /*!< </spirit:description> */
#define GPIO_TRIGENR_TR10_Pos       (10U)
#define GPIO_TRIGENR_TR10_Msk       (0x1UL << GPIO_TRIGENR_TR10_Pos)  /*!< 0x00000400 */
#define GPIO_TRIGENR_TR10           GPIO_TRIGENR_TR10_Msk        /*!< </spirit:description> */
#define GPIO_TRIGENR_TR11_Pos       (11U)
#define GPIO_TRIGENR_TR11_Msk       (0x1UL << GPIO_TRIGENR_TR11_Pos)  /*!< 0x00000800 */
#define GPIO_TRIGENR_TR11           GPIO_TRIGENR_TR11_Msk        /*!< </spirit:description> */
#define GPIO_TRIGENR_TR12_Pos       (12U)
#define GPIO_TRIGENR_TR12_Msk       (0x1UL << GPIO_TRIGENR_TR12_Pos)  /*!< 0x00001000 */
#define GPIO_TRIGENR_TR12           GPIO_TRIGENR_TR12_Msk        /*!< </spirit:description> */
#define GPIO_TRIGENR_TR13_Pos       (13U)
#define GPIO_TRIGENR_TR13_Msk       (0x1UL << GPIO_TRIGENR_TR13_Pos)  /*!< 0x00002000 */
#define GPIO_TRIGENR_TR13           GPIO_TRIGENR_TR13_Msk        /*!< </spirit:description> */
#define GPIO_TRIGENR_TR14_Pos       (14U)
#define GPIO_TRIGENR_TR14_Msk       (0x1UL << GPIO_TRIGENR_TR14_Pos)  /*!< 0x00004000 */
#define GPIO_TRIGENR_TR14           GPIO_TRIGENR_TR14_Msk        /*!< </spirit:description> */
#define GPIO_TRIGENR_TR15_Pos       (15U)
#define GPIO_TRIGENR_TR15_Msk       (0x1UL << GPIO_TRIGENR_TR15_Pos)  /*!< 0x00008000 */
#define GPIO_TRIGENR_TR15           GPIO_TRIGENR_TR15_Msk        /*!< </spirit:description> */

/****************  Bit definition for GPIO_SAFESELR register  *****************/
#define GPIO_SAFESELR_SFS0_Pos      (0U)
#define GPIO_SAFESELR_SFS0_Msk      (0x1UL << GPIO_SAFESELR_SFS0_Pos)   /*!< 0x00000001 */
#define GPIO_SAFESELR_SFS0          GPIO_SAFESELR_SFS0_Msk       /*!< </spirit:description> */
#define GPIO_SAFESELR_SFS1_Pos      (1U)
#define GPIO_SAFESELR_SFS1_Msk      (0x1UL << GPIO_SAFESELR_SFS1_Pos)   /*!< 0x00000002 */
#define GPIO_SAFESELR_SFS1          GPIO_SAFESELR_SFS1_Msk       /*!< </spirit:description> */
#define GPIO_SAFESELR_SFS2_Pos      (2U)
#define GPIO_SAFESELR_SFS2_Msk      (0x1UL << GPIO_SAFESELR_SFS2_Pos)   /*!< 0x00000004 */
#define GPIO_SAFESELR_SFS2          GPIO_SAFESELR_SFS2_Msk       /*!< </spirit:description> */
#define GPIO_SAFESELR_SFS3_Pos      (3U)
#define GPIO_SAFESELR_SFS3_Msk      (0x1UL << GPIO_SAFESELR_SFS3_Pos)   /*!< 0x00000008 */
#define GPIO_SAFESELR_SFS3          GPIO_SAFESELR_SFS3_Msk       /*!< </spirit:description> */
#define GPIO_SAFESELR_SFS4_Pos      (4U)
#define GPIO_SAFESELR_SFS4_Msk      (0x1UL << GPIO_SAFESELR_SFS4_Pos)   /*!< 0x00000010 */
#define GPIO_SAFESELR_SFS4          GPIO_SAFESELR_SFS4_Msk       /*!< </spirit:description> */
#define GPIO_SAFESELR_SFS5_Pos      (5U)
#define GPIO_SAFESELR_SFS5_Msk      (0x1UL << GPIO_SAFESELR_SFS5_Pos)   /*!< 0x00000020 */
#define GPIO_SAFESELR_SFS5          GPIO_SAFESELR_SFS5_Msk       /*!< </spirit:description> */
#define GPIO_SAFESELR_SFS6_Pos      (6U)
#define GPIO_SAFESELR_SFS6_Msk      (0x1UL << GPIO_SAFESELR_SFS6_Pos)   /*!< 0x00000040 */
#define GPIO_SAFESELR_SFS6          GPIO_SAFESELR_SFS6_Msk       /*!< </spirit:description> */
#define GPIO_SAFESELR_SFS7_Pos      (7U)
#define GPIO_SAFESELR_SFS7_Msk      (0x1UL << GPIO_SAFESELR_SFS7_Pos)   /*!< 0x00000080 */
#define GPIO_SAFESELR_SFS7          GPIO_SAFESELR_SFS7_Msk       /*!< </spirit:description> */
#define GPIO_SAFESELR_SFS8_Pos      (8U)
#define GPIO_SAFESELR_SFS8_Msk      (0x1UL << GPIO_SAFESELR_SFS8_Pos)   /*!< 0x00000100 */
#define GPIO_SAFESELR_SFS8          GPIO_SAFESELR_SFS8_Msk       /*!< </spirit:description> */
#define GPIO_SAFESELR_SFS9_Pos      (9U)
#define GPIO_SAFESELR_SFS9_Msk      (0x1UL << GPIO_SAFESELR_SFS9_Pos)   /*!< 0x00000200 */
#define GPIO_SAFESELR_SFS9          GPIO_SAFESELR_SFS9_Msk       /*!< </spirit:description> */
#define GPIO_SAFESELR_SFS10_Pos     (10U)
#define GPIO_SAFESELR_SFS10_Msk     (0x1UL << GPIO_SAFESELR_SFS10_Pos)    /*!< 0x00000400 */
#define GPIO_SAFESELR_SFS10         GPIO_SAFESELR_SFS10_Msk      /*!< </spirit:description> */
#define GPIO_SAFESELR_SFS11_Pos     (11U)
#define GPIO_SAFESELR_SFS11_Msk     (0x1UL << GPIO_SAFESELR_SFS11_Pos)    /*!< 0x00000800 */
#define GPIO_SAFESELR_SFS11         GPIO_SAFESELR_SFS11_Msk      /*!< </spirit:description> */
#define GPIO_SAFESELR_SFS12_Pos     (12U)
#define GPIO_SAFESELR_SFS12_Msk     (0x1UL << GPIO_SAFESELR_SFS12_Pos)    /*!< 0x00001000 */
#define GPIO_SAFESELR_SFS12         GPIO_SAFESELR_SFS12_Msk      /*!< </spirit:description> */
#define GPIO_SAFESELR_SFS13_Pos     (13U)
#define GPIO_SAFESELR_SFS13_Msk     (0x1UL << GPIO_SAFESELR_SFS13_Pos)    /*!< 0x00002000 */
#define GPIO_SAFESELR_SFS13         GPIO_SAFESELR_SFS13_Msk      /*!< </spirit:description> */
#define GPIO_SAFESELR_SFS14_Pos     (14U)
#define GPIO_SAFESELR_SFS14_Msk     (0x1UL << GPIO_SAFESELR_SFS14_Pos)    /*!< 0x00004000 */
#define GPIO_SAFESELR_SFS14         GPIO_SAFESELR_SFS14_Msk      /*!< </spirit:description> */
#define GPIO_SAFESELR_SFS15_Pos     (15U)
#define GPIO_SAFESELR_SFS15_Msk     (0x1UL << GPIO_SAFESELR_SFS15_Pos)    /*!< 0x00008000 */
#define GPIO_SAFESELR_SFS15         GPIO_SAFESELR_SFS15_Msk      /*!< </spirit:description> */

/****************  Bit definition for GPIO_SAFEVALR register  *****************/
#define GPIO_SAFEVALR_SFV0_Pos      (0U)
#define GPIO_SAFEVALR_SFV0_Msk      (0x1UL << GPIO_SAFEVALR_SFV0_Pos)   /*!< 0x00000001 */
#define GPIO_SAFEVALR_SFV0          GPIO_SAFEVALR_SFV0_Msk       /*!< </spirit:description> */
#define GPIO_SAFEVALR_SFV1_Pos      (1U)
#define GPIO_SAFEVALR_SFV1_Msk      (0x1UL << GPIO_SAFEVALR_SFV1_Pos)   /*!< 0x00000002 */
#define GPIO_SAFEVALR_SFV1          GPIO_SAFEVALR_SFV1_Msk       /*!< </spirit:description> */
#define GPIO_SAFEVALR_SFV2_Pos      (2U)
#define GPIO_SAFEVALR_SFV2_Msk      (0x1UL << GPIO_SAFEVALR_SFV2_Pos)   /*!< 0x00000004 */
#define GPIO_SAFEVALR_SFV2          GPIO_SAFEVALR_SFV2_Msk       /*!< </spirit:description> */
#define GPIO_SAFEVALR_SFV3_Pos      (3U)
#define GPIO_SAFEVALR_SFV3_Msk      (0x1UL << GPIO_SAFEVALR_SFV3_Pos)   /*!< 0x00000008 */
#define GPIO_SAFEVALR_SFV3          GPIO_SAFEVALR_SFV3_Msk       /*!< </spirit:description> */
#define GPIO_SAFEVALR_SFV4_Pos      (4U)
#define GPIO_SAFEVALR_SFV4_Msk      (0x1UL << GPIO_SAFEVALR_SFV4_Pos)   /*!< 0x00000010 */
#define GPIO_SAFEVALR_SFV4          GPIO_SAFEVALR_SFV4_Msk       /*!< </spirit:description> */
#define GPIO_SAFEVALR_SFV5_Pos      (5U)
#define GPIO_SAFEVALR_SFV5_Msk      (0x1UL << GPIO_SAFEVALR_SFV5_Pos)   /*!< 0x00000020 */
#define GPIO_SAFEVALR_SFV5          GPIO_SAFEVALR_SFV5_Msk       /*!< </spirit:description> */
#define GPIO_SAFEVALR_SFV6_Pos      (6U)
#define GPIO_SAFEVALR_SFV6_Msk      (0x1UL << GPIO_SAFEVALR_SFV6_Pos)   /*!< 0x00000040 */
#define GPIO_SAFEVALR_SFV6          GPIO_SAFEVALR_SFV6_Msk       /*!< </spirit:description> */
#define GPIO_SAFEVALR_SFV7_Pos      (7U)
#define GPIO_SAFEVALR_SFV7_Msk      (0x1UL << GPIO_SAFEVALR_SFV7_Pos)   /*!< 0x00000080 */
#define GPIO_SAFEVALR_SFV7          GPIO_SAFEVALR_SFV7_Msk       /*!< </spirit:description> */
#define GPIO_SAFEVALR_SFV8_Pos      (8U)
#define GPIO_SAFEVALR_SFV8_Msk      (0x1UL << GPIO_SAFEVALR_SFV8_Pos)   /*!< 0x00000100 */
#define GPIO_SAFEVALR_SFV8          GPIO_SAFEVALR_SFV8_Msk       /*!< </spirit:description> */
#define GPIO_SAFEVALR_SFV9_Pos      (9U)
#define GPIO_SAFEVALR_SFV9_Msk      (0x1UL << GPIO_SAFEVALR_SFV9_Pos)   /*!< 0x00000200 */
#define GPIO_SAFEVALR_SFV9          GPIO_SAFEVALR_SFV9_Msk       /*!< </spirit:description> */
#define GPIO_SAFEVALR_SFV10_Pos     (10U)
#define GPIO_SAFEVALR_SFV10_Msk     (0x1UL << GPIO_SAFEVALR_SFV10_Pos)    /*!< 0x00000400 */
#define GPIO_SAFEVALR_SFV10         GPIO_SAFEVALR_SFV10_Msk      /*!< </spirit:description> */
#define GPIO_SAFEVALR_SFV11_Pos     (11U)
#define GPIO_SAFEVALR_SFV11_Msk     (0x1UL << GPIO_SAFEVALR_SFV11_Pos)    /*!< 0x00000800 */
#define GPIO_SAFEVALR_SFV11         GPIO_SAFEVALR_SFV11_Msk      /*!< </spirit:description> */
#define GPIO_SAFEVALR_SFV12_Pos     (12U)
#define GPIO_SAFEVALR_SFV12_Msk     (0x1UL << GPIO_SAFEVALR_SFV12_Pos)    /*!< 0x00001000 */
#define GPIO_SAFEVALR_SFV12         GPIO_SAFEVALR_SFV12_Msk      /*!< </spirit:description> */
#define GPIO_SAFEVALR_SFV13_Pos     (13U)
#define GPIO_SAFEVALR_SFV13_Msk     (0x1UL << GPIO_SAFEVALR_SFV13_Pos)    /*!< 0x00002000 */
#define GPIO_SAFEVALR_SFV13         GPIO_SAFEVALR_SFV13_Msk      /*!< </spirit:description> */
#define GPIO_SAFEVALR_SFV14_Pos     (14U)
#define GPIO_SAFEVALR_SFV14_Msk     (0x1UL << GPIO_SAFEVALR_SFV14_Pos)    /*!< 0x00004000 */
#define GPIO_SAFEVALR_SFV14         GPIO_SAFEVALR_SFV14_Msk      /*!< </spirit:description> */
#define GPIO_SAFEVALR_SFV15_Pos     (15U)
#define GPIO_SAFEVALR_SFV15_Msk     (0x1UL << GPIO_SAFEVALR_SFV15_Pos)    /*!< 0x00008000 */
#define GPIO_SAFEVALR_SFV15         GPIO_SAFEVALR_SFV15_Msk      /*!< </spirit:description> */

#define GPIOA_BASE           0x48000000UL 
#define GPIOB_BASE           0x48000400UL 
#define GPIOC_BASE           0x48000800UL 
#define GPIOD_BASE           0x48000C00UL 
#define GPIOE_BASE           0x48001000UL 
#define GPIOF_BASE           0x48001400UL 
#define GPIOG_BASE           0x48001800UL 
#define GPIOH_BASE           0x48001C00UL 
#define GPIOI_BASE           0x48002000UL 

#define GPIOA                ((GPIO_TypeDef *) GPIOA_BASE) 
#define GPIOB                ((GPIO_TypeDef *) GPIOB_BASE) 
#define GPIOC                ((GPIO_TypeDef *) GPIOC_BASE) 
#define GPIOD                ((GPIO_TypeDef *) GPIOD_BASE) 
#define GPIOE                ((GPIO_TypeDef *) GPIOE_BASE) 
#define GPIOF                ((GPIO_TypeDef *) GPIOF_BASE) 
#define GPIOG                ((GPIO_TypeDef *) GPIOG_BASE) 
#define GPIOH                ((GPIO_TypeDef *) GPIOH_BASE) 
#define GPIOI                ((GPIO_TypeDef *) GPIOI_BASE) 

#endif /* __SR5E1_GPIO_H */

