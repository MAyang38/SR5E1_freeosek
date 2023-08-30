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

#ifndef __SR5E1_IWDG_H
#define __SR5E1_IWDG_H

/******************************************************************************/
/*                                                                            */
/*                                   (IWDG)                                  */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO uint32_t KR;    /*!< KR   Address offset: 0x00 */
  __IO uint32_t PR;    /*!< PR   Address offset: 0x04 */
  __IO uint32_t RLR;   /*!< RLR  Address offset: 0x08 */
  __IO uint32_t SR;    /*!< SR   Address offset: 0x0C */
  __IO uint32_t WINR;  /*!< WINR Address offset: 0x10 */
} IWDG_TypeDef;


/*******************  Bit definition for IWDG_KR register  ********************/
#define IWDG_KR_KEY_Pos    (0U)
#define IWDG_KR_KEY_Msk    (0xFFFFUL << IWDG_KR_KEY_Pos)        /*!< 0x0000FFFF */
#define IWDG_KR_KEY        IWDG_KR_KEY_Msk     /*!< </spirit:description> */

/*******************  Bit definition for IWDG_PR register  ********************/
#define IWDG_PR_PR_Pos     (0U)
#define IWDG_PR_PR_Msk     (0x7UL << IWDG_PR_PR_Pos)    /*!< 0x00000007 */
#define IWDG_PR_PR         IWDG_PR_PR_Msk      /*!< </spirit:description> */
#define IWDG_PR_PR_0   (0x1UL << IWDG_PR_PR_Pos)            /*!< 0x00000001 */
#define IWDG_PR_PR_1   (0x2UL << IWDG_PR_PR_Pos)            /*!< 0x00000002 */
#define IWDG_PR_PR_2   (0x4UL << IWDG_PR_PR_Pos)            /*!< 0x00000004 */

/*******************  Bit definition for IWDG_RLR register  *******************/
#define IWDG_RLR_RL_Pos    (0U)
#define IWDG_RLR_RL_Msk    (0xFFFUL << IWDG_RLR_RL_Pos)       /*!< 0x00000FFF */
#define IWDG_RLR_RL        IWDG_RLR_RL_Msk     /*!< </spirit:description> */

/*******************  Bit definition for IWDG_SR register  ********************/
#define IWDG_SR_PVU_Pos    (0U)
#define IWDG_SR_PVU_Msk    (0x1UL << IWDG_SR_PVU_Pos)     /*!< 0x00000001 */
#define IWDG_SR_PVU        IWDG_SR_PVU_Msk     /*!< </spirit:description> */
#define IWDG_SR_RVU_Pos    (1U)
#define IWDG_SR_RVU_Msk    (0x1UL << IWDG_SR_RVU_Pos)     /*!< 0x00000002 */
#define IWDG_SR_RVU        IWDG_SR_RVU_Msk     /*!< </spirit:description> */
#define IWDG_SR_WVU_Pos    (2U)
#define IWDG_SR_WVU_Msk    (0x1UL << IWDG_SR_WVU_Pos)     /*!< 0x00000004 */
#define IWDG_SR_WVU        IWDG_SR_WVU_Msk     /*!< </spirit:description> */

/******************  Bit definition for IWDG_WINR register  *******************/
#define IWDG_WINR_WIN_Pos  (0U)
#define IWDG_WINR_WIN_Msk  (0xFFFUL << IWDG_WINR_WIN_Pos)         /*!< 0x00000FFF */
#define IWDG_WINR_WIN      IWDG_WINR_WIN_Msk   /*!< </spirit:description> */

#define IWDG1_BASE           0x40001000UL 
#define IWDG2_BASE           0x40001400UL 

#define IWDG1                ((IWDG_TypeDef *) IWDG1_BASE) 
#define IWDG2                ((IWDG_TypeDef *) IWDG2_BASE) 

#endif /* __SR5E1_IWDG_H */

