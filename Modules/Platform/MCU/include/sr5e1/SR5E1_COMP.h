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

#ifndef __SR5E1_COMP_H
#define __SR5E1_COMP_H

/*******************************************************************************
 * REVISION HISTORY                                                            *
 * REV       DATE       RM REV          DESCRIPTION OF CHANGE                  *
 * ------ ----------- ------------ --------------------------------------------*
 * 1.0C2  15-Mar-2022 Rev 1 Draft C     SR5E1_RDP_0_1_Rev1_C_18FEB22           *
 *                                      Fixed COMP5-8_BASE addresses           *              *
 * ------ ----------- ------------ --------------------------------------------*
 * 1.0C1  18-Feb-2022 Rev 1 Draft C     SR5E1_RDP_0_1_Rev1_C_18FEB22           *
 *                                      Fixed CSR bitfield                     *
 ******************************************************************************/
 
/******************************************************************************/
/*                                                                            */
/*                                   (COMP)                                   */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO uint32_t CSR;  /*!< CSR Address offset: 0x0 */
} COMP_TypeDef;


/*******************  Bit definition for COMP_CSR register  *******************/
#define COMP_CSR_EN_Pos        (0U)
#define COMP_CSR_EN_Msk        (0x1UL << COMP_CSR_EN_Pos) /*!< 0x00000001 */
#define COMP_CSR_EN            COMP_CSR_EN_Msk         /*!< </spirit:description> */
#define COMP_CSR_DIG_H_Pos     (1U)
#define COMP_CSR_DIG_H_Msk     (0x1UL << COMP_CSR_DIG_H_Pos)    /*!< 0x00000002 */
#define COMP_CSR_DIG_H         COMP_CSR_DIG_H_Msk      /*!< </spirit:description> */
#define COMP_CSR_INMSEL_Pos    (4U)
#define COMP_CSR_INMSEL_Msk    (0xFUL << COMP_CSR_INMSEL_Pos)     /*!< 0x000000F0 */
#define COMP_CSR_INMSEL        COMP_CSR_INMSEL_Msk     /*!< </spirit:description> */
#define COMP_CSR_INMSEL_0    (0x1UL << COMP_CSR_INMSEL_Pos)              /*!< 0x00000010 */
#define COMP_CSR_INMSEL_1    (0x2UL << COMP_CSR_INMSEL_Pos)              /*!< 0x00000020 */
#define COMP_CSR_INMSEL_2    (0x4UL << COMP_CSR_INMSEL_Pos)              /*!< 0x00000040 */
#define COMP_CSR_INMSEL_3    (0x8UL << COMP_CSR_INMSEL_Pos)              /*!< 0x00000080 */
#define COMP_CSR_INPSEL_Pos    (8U)
#define COMP_CSR_INPSEL_Msk    (0x1UL << COMP_CSR_INPSEL_Pos)     /*!< 0x00000100 */
#define COMP_CSR_INPSEL        COMP_CSR_INPSEL_Msk     /*!< </spirit:description> */
#define COMP_CSR_POL_Pos       (15U)
#define COMP_CSR_POL_Msk       (0x1UL << COMP_CSR_POL_Pos)    /*!< 0x00008000 */
#define COMP_CSR_POL           COMP_CSR_POL_Msk        /*!< </spirit:description> */
#define COMP_CSR_HYST_Pos      (16U)
#define COMP_CSR_HYST_Msk      (0x7UL << COMP_CSR_HYST_Pos)     /*!< 0x00070000 */
#define COMP_CSR_HYST          COMP_CSR_HYST_Msk       /*!< </spirit:description> */
#define COMP_CSR_HYST_0  (0x1UL << COMP_CSR_HYST_Pos)               /*!< 0x00010000 */
#define COMP_CSR_HYST_1  (0x2UL << COMP_CSR_HYST_Pos)               /*!< 0x00020000 */
#define COMP_CSR_HYST_2  (0x4UL << COMP_CSR_HYST_Pos)               /*!< 0x00040000 */
#define COMP_CSR_BLANKSEL_Pos  (19U)
#define COMP_CSR_BLANKSEL_Msk  (0x7UL << COMP_CSR_BLANKSEL_Pos)         /*!< 0x00380000 */
#define COMP_CSR_BLANKSEL      COMP_CSR_BLANKSEL_Msk   /*!< </spirit:description> */
#define COMP_CSR_BLANKSEL_0    (0x1UL << COMP_CSR_BLANKSEL_Pos)                   /*!< 0x00080000 */
#define COMP_CSR_BLANKSEL_1    (0x2UL << COMP_CSR_BLANKSEL_Pos)                    /*!< 0x00100000 */
#define COMP_CSR_BLANKSEL_2    (0x4UL << COMP_CSR_BLANKSEL_Pos)                    /*!< 0x00200000 */
#define COMP_CSR_VALUE_Pos     (30U)
#define COMP_CSR_VALUE_Msk     (0x1UL << COMP_CSR_VALUE_Pos)      /*!< 0x40000000 */
#define COMP_CSR_VALUE         COMP_CSR_VALUE_Msk      /*!< </spirit:description> */
#define COMP_CSR_LOCK_Pos      (31U)
#define COMP_CSR_LOCK_Msk      (0x1UL << COMP_CSR_LOCK_Pos)     /*!< 0x80000000 */
#define COMP_CSR_LOCK          COMP_CSR_LOCK_Msk      /*!< </spirit:description> */

#define COMP1_BASE           0x4800B000UL 
#define COMP2_BASE           0x4800B004UL 
#define COMP3_BASE           0x4800B008UL 
#define COMP4_BASE           0x4800B00CUL 
#define COMP5_BASE           0x4400B000UL 
#define COMP6_BASE           0x4400B004UL 
#define COMP7_BASE           0x4400B008UL 
#define COMP8_BASE           0x4400B00CUL 

#define COMP1                ((COMP_TypeDef *) COMP1_BASE) 
#define COMP2                ((COMP_TypeDef *) COMP2_BASE) 
#define COMP3                ((COMP_TypeDef *) COMP3_BASE) 
#define COMP4                ((COMP_TypeDef *) COMP4_BASE) 
#define COMP5                ((COMP_TypeDef *) COMP5_BASE) 
#define COMP6                ((COMP_TypeDef *) COMP6_BASE) 
#define COMP7                ((COMP_TypeDef *) COMP7_BASE) 
#define COMP8                ((COMP_TypeDef *) COMP8_BASE) 

#endif /* __SR5E1_COMP_H */

