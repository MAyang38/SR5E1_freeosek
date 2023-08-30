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

#ifndef __SR5E1_WWDG_H
#define __SR5E1_WWDG_H

/******************************************************************************/
/*                                                                            */
/*                                   (WWDG)                                  */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO uint32_t CR;   /*!< CR  Address offset: 0x0 */
  __IO uint32_t CFR;  /*!< CFR Address offset: 0x4 */
  __IO uint32_t SR;   /*!< SR  Address offset: 0x8 */
} WWDG_TypeDef;


/*******************  Bit definition for WWDG_CR register  ********************/
#define WWDG_CR_T_Pos       (0U)
#define WWDG_CR_T_Msk       (0x7FUL << WWDG_CR_T_Pos)   /*!< 0x0000007F */
#define WWDG_CR_T           WWDG_CR_T_Msk        /*!< </spirit:description> */
#define WWDG_CR_T_0 (0x01UL << WWDG_CR_T_Pos)          /*!< 0x00000001 */
#define WWDG_CR_T_1 (0x02UL << WWDG_CR_T_Pos)          /*!< 0x00000002 */
#define WWDG_CR_T_2 (0x04UL << WWDG_CR_T_Pos)          /*!< 0x00000004 */
#define WWDG_CR_T_3 (0x08UL << WWDG_CR_T_Pos)          /*!< 0x00000008 */
#define WWDG_CR_T_4 (0x10UL << WWDG_CR_T_Pos)           /*!< 0x00000010 */
#define WWDG_CR_T_5 (0x20UL << WWDG_CR_T_Pos)           /*!< 0x00000020 */
#define WWDG_CR_T_6 (0x40UL << WWDG_CR_T_Pos)           /*!< 0x00000040 */
#define WWDG_CR_WDGA_Pos    (7U)
#define WWDG_CR_WDGA_Msk    (0x1UL << WWDG_CR_WDGA_Pos)     /*!< 0x00000080 */
#define WWDG_CR_WDGA        WWDG_CR_WDGA_Msk     /*!< </spirit:description> */

/*******************  Bit definition for WWDG_CFR register  *******************/
#define WWDG_CFR_W_Pos      (0U)
#define WWDG_CFR_W_Msk      (0x7FUL << WWDG_CFR_W_Pos)    /*!< 0x0000007F */
#define WWDG_CFR_W          WWDG_CFR_W_Msk       /*!< </spirit:description> */
#define WWDG_CFR_W_0  (0x01UL << WWDG_CFR_W_Pos)           /*!< 0x00000001 */
#define WWDG_CFR_W_1  (0x02UL << WWDG_CFR_W_Pos)           /*!< 0x00000002 */
#define WWDG_CFR_W_2  (0x04UL << WWDG_CFR_W_Pos)           /*!< 0x00000004 */
#define WWDG_CFR_W_3  (0x08UL << WWDG_CFR_W_Pos)           /*!< 0x00000008 */
#define WWDG_CFR_W_4  (0x10UL << WWDG_CFR_W_Pos)            /*!< 0x00000010 */
#define WWDG_CFR_W_5  (0x20UL << WWDG_CFR_W_Pos)            /*!< 0x00000020 */
#define WWDG_CFR_W_6  (0x40UL << WWDG_CFR_W_Pos)            /*!< 0x00000040 */
#define WWDG_CFR_WDGTB_Pos  (11U)
#define WWDG_CFR_WDGTB_Msk  (0x7UL << WWDG_CFR_WDGTB_Pos)       /*!< 0x00003800 */
#define WWDG_CFR_WDGTB      WWDG_CFR_WDGTB_Msk   /*!< </spirit:description> */
#define WWDG_CFR_WDGTB_0      (0x1UL << WWDG_CFR_WDGTB_Pos)                 /*!< 0x00000800 */
#define WWDG_CFR_WDGTB_1      (0x2UL << WWDG_CFR_WDGTB_Pos)                  /*!< 0x00001000 */
#define WWDG_CFR_WDGTB_2      (0x4UL << WWDG_CFR_WDGTB_Pos)                  /*!< 0x00002000 */
#define WWDG_CFR_EWI_Pos    (9U)
#define WWDG_CFR_EWI_Msk    (0x1UL << WWDG_CFR_EWI_Pos)     /*!< 0x00000200 */
#define WWDG_CFR_EWI        WWDG_CFR_EWI_Msk     /*!< </spirit:description> */

/*******************  Bit definition for WWDG_SR register  ********************/
#define WWDG_SR_EWIF_Pos    (0U)
#define WWDG_SR_EWIF_Msk    (0x1UL << WWDG_SR_EWIF_Pos)     /*!< 0x00000001 */
#define WWDG_SR_EWIF        WWDG_SR_EWIF_Msk     /*!< </spirit:description> */

#define WWDG1_BASE           0x40000000UL
#define WWDG2_BASE           0x40000400UL 


#define WWDG1                ((WWDG_TypeDef *) WWDG1_BASE) 
#define WWDG2                ((WWDG_TypeDef *) WWDG2_BASE) 


#endif /* __SR5E1_WWDG_H */

