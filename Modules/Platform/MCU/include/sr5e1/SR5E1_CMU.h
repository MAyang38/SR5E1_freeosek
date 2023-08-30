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

#ifndef __SR5E1_CMU_H
#define __SR5E1_CMU_H

/******************************************************************************/
/*                                                                            */
/*                                   (CMU)                                   */
/*                                                                            */
/******************************************************************************/
typedef struct
{
  __IO uint32_t CMU_CSR;     /*!< CMU_CSR    Address offset: 0x00 */
  __IO uint32_t CMU_FDR;     /*!< CMU_FDR    Address offset: 0x04 */
  __IO uint32_t CMU_HFREFR;  /*!< CMU_HFREFR Address offset: 0x08 */
  __IO uint32_t CMU_LFREFR;  /*!< CMU_LFREFR Address offset: 0x0C */
  __IO uint32_t CMU_ISR;     /*!< CMU_ISR    Address offset: 0x10 */
       uint32_t RESERVED0;   /*!< Reserved   Address offset: 0x14 */
  __IO uint32_t CMU_MDR;     /*!< CMU_MDR    Address offset: 0x18 */
} CMU_TypeDef;


/*****************  Bit definition for CMU_CMU_CSR register  ******************/
#define CMU_CMU_CSR_CME_Pos         (0U)
#define CMU_CMU_CSR_CME_Msk         (0x1UL << CMU_CMU_CSR_CME_Pos)  /*!< 0x00000001 */
#define CMU_CMU_CSR_CME             CMU_CMU_CSR_CME_Msk        /*!< </spirit:description> */
#define CMU_CMU_CSR_RCDIV_Pos       (1U)
#define CMU_CMU_CSR_RCDIV_Msk       (0x3UL << CMU_CMU_CSR_RCDIV_Pos)    /*!< 0x00000006 */
#define CMU_CMU_CSR_RCDIV           CMU_CMU_CSR_RCDIV_Msk      /*!< </spirit:description> */
#define CMU_CMU_CSR_RCDIV_0 (0x1UL << CMU_CMU_CSR_RCDIV_Pos)            /*!< 0x00000002 */
#define CMU_CMU_CSR_RCDIV_1 (0x2UL << CMU_CMU_CSR_RCDIV_Pos)            /*!< 0x00000004 */
#define CMU_CMU_CSR_CKSEL1_Pos      (8U)
#define CMU_CMU_CSR_CKSEL1_Msk      (0x3UL << CMU_CMU_CSR_CKSEL1_Pos)     /*!< 0x00000300 */
#define CMU_CMU_CSR_CKSEL1          CMU_CMU_CSR_CKSEL1_Msk     /*!< </spirit:description> */
#define CMU_CMU_CSR_CKSEL1_0  (0x1UL << CMU_CMU_CSR_CKSEL1_Pos)               /*!< 0x00000100 */
#define CMU_CMU_CSR_CKSEL1_1  (0x2UL << CMU_CMU_CSR_CKSEL1_Pos)               /*!< 0x00000200 */
#define CMU_CMU_CSR_SFM_Pos         (23U)
#define CMU_CMU_CSR_SFM_Msk         (0x1UL << CMU_CMU_CSR_SFM_Pos)  /*!< 0x00800000 */
#define CMU_CMU_CSR_SFM             CMU_CMU_CSR_SFM_Msk        /*!< </spirit:description> */

/*****************  Bit definition for CMU_CMU_FDR register  ******************/
#define CMU_CMU_FDR_FD_Pos          (0U)
#define CMU_CMU_FDR_FD_Msk          (0xFFFFFUL << CMU_CMU_FDR_FD_Pos)     /*!< 0x000FFFFF */
#define CMU_CMU_FDR_FD              CMU_CMU_FDR_FD_Msk         /*!< </spirit:description> */

/****************  Bit definition for CMU_CMU_HFREFR register  ****************/
#define CMU_CMU_HFREFR_HFREF_Pos    (0U)
#define CMU_CMU_HFREFR_HFREF_Msk    (0xFFFUL << CMU_CMU_HFREFR_HFREF_Pos)         /*!< 0x00000FFF */
#define CMU_CMU_HFREFR_HFREF        CMU_CMU_HFREFR_HFREF_Msk   /*!< </spirit:description> */

/****************  Bit definition for CMU_CMU_LFREFR register  ****************/
#define CMU_CMU_LFREFR_LFREF_Pos    (0U)
#define CMU_CMU_LFREFR_LFREF_Msk    (0xFFFUL << CMU_CMU_LFREFR_LFREF_Pos)         /*!< 0x00000FFF */
#define CMU_CMU_LFREFR_LFREF        CMU_CMU_LFREFR_LFREF_Msk   /*!< </spirit:description> */

/*****************  Bit definition for CMU_CMU_ISR register  ******************/
#define CMU_CMU_ISR_OLRI_Pos        (0U)
#define CMU_CMU_ISR_OLRI_Msk        (0x1UL << CMU_CMU_ISR_OLRI_Pos)   /*!< 0x00000001 */
#define CMU_CMU_ISR_OLRI            CMU_CMU_ISR_OLRI_Msk       /*!< </spirit:description> */
#define CMU_CMU_ISR_FLLI_Pos        (1U)
#define CMU_CMU_ISR_FLLI_Msk        (0x1UL << CMU_CMU_ISR_FLLI_Pos)   /*!< 0x00000002 */
#define CMU_CMU_ISR_FLLI            CMU_CMU_ISR_FLLI_Msk       /*!< </spirit:description> */
#define CMU_CMU_ISR_FHHI_Pos        (2U)
#define CMU_CMU_ISR_FHHI_Msk        (0x1UL << CMU_CMU_ISR_FHHI_Pos)   /*!< 0x00000004 */
#define CMU_CMU_ISR_FHHI            CMU_CMU_ISR_FHHI_Msk       /*!< </spirit:description> */
#define CMU_CMU_ISR_FLCI_Pos        (3U)
#define CMU_CMU_ISR_FLCI_Msk        (0x1UL << CMU_CMU_ISR_FLCI_Pos)   /*!< 0x00000008 */
#define CMU_CMU_ISR_FLCI            CMU_CMU_ISR_FLCI_Msk       /*!< </spirit:description> */

/*****************  Bit definition for CMU_CMU_MDR register  ******************/
#define CMU_CMU_MDR_MD_Pos          (0U)
#define CMU_CMU_MDR_MD_Msk          (0xFFFFFUL << CMU_CMU_MDR_MD_Pos)     /*!< 0x000FFFFF */
#define CMU_CMU_MDR_MD              CMU_CMU_MDR_MD_Msk         /*!< </spirit:description> */



#define CMU0_BASE          0x42002000UL
#define CMU1_BASE          0x40002040UL 
#define CMU2_BASE          0x40002080UL 
#define CMU3_BASE          0x400020C0UL 
#define CMU4_BASE          0x40002100UL 
#define CMU5_BASE          0x40002140UL 

#define CMU0               ((CMU_TypeDef *) CMU0_BASE) 
#define CMU1               ((CMU_TypeDef *) CMU1_BASE) 
#define CMU2               ((CMU_TypeDef *) CMU2_BASE) 
#define CMU3               ((CMU_TypeDef *) CMU3_BASE) 
#define CMU4               ((CMU_TypeDef *) CMU4_BASE) 
#define CMU5               ((CMU_TypeDef *) CMU5_BASE) 

#endif /* __SR5E1_CMU_H */

