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

#ifndef __SR5E1_DMA_H
#define __SR5E1_DMA_H

/*******************************************************************************
 * REVISION HISTORY                                                            *
 * REV       DATE       RM REV          DESCRIPTION OF CHANGE                  *
 * ------ ----------- ------------ --------------------------------------------*
 * 1.0C2  21-Feb-2022 Reb 1 Draft C     SR5E1_RDP_0_2_Rev1_C_18FEB22           *
 *                                      Removed registers:                     *
 *                                        HWCFGR1-2 VERR IPDR SIDR             *
 * ------ ----------- ------------ --------------------------------------------*
 * 1.0C1  18-Feb-2022 Rev 1 Draft C     SR5E1_RDP_0_1_Rev1_C_18FEB22           *
 ******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                                   (DMA)                                    */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO uint32_t LISR;   /*!< LISR  Address offset: 0x0 */
  __IO uint32_t HISR;   /*!< HISR  Address offset: 0x4 */
  __IO uint32_t LIFCR;  /*!< LIFCR Address offset: 0x8 */
  __IO uint32_t HIFCR;  /*!< HIFCR Address offset: 0xC */
} DMA_TypeDef;

/******************************************************************************/
/*                                                                            */
/*                               (DMA_Stream)                               */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO uint32_t SxCR;    /*!< SxCR   Address offset: 0x00 */
  __IO uint32_t SxNDTR;  /*!< SxNDTR Address offset: 0x04 */
  __IO uint32_t SxPAR;   /*!< SxPAR  Address offset: 0x08 */
  __IO uint32_t SxM0AR;  /*!< SxM0AR Address offset: 0x0C */
  __IO uint32_t SxM1AR;  /*!< SxM1AR Address offset: 0x10 */
  __IO uint32_t SxFCR;   /*!< SxFCR  Address offset: 0x14 */
} DMA_Stream_TypeDef;


/*******************  Bit definition for DMA_LISR register  *******************/
#define DMA_LISR_TCIF3_Pos                  (27U)
#define DMA_LISR_TCIF3_Msk                  (0x1UL << DMA_LISR_TCIF3_Pos)     /*!< 0x08000000 */
#define DMA_LISR_TCIF3                      DMA_LISR_TCIF3_Msk               /*!< </spirit:description> */
#define DMA_LISR_HTIF3_Pos                  (26U)
#define DMA_LISR_HTIF3_Msk                  (0x1UL << DMA_LISR_HTIF3_Pos)     /*!< 0x04000000 */
#define DMA_LISR_HTIF3                      DMA_LISR_HTIF3_Msk               /*!< </spirit:description> */
#define DMA_LISR_TEIF3_Pos                  (25U)
#define DMA_LISR_TEIF3_Msk                  (0x1UL << DMA_LISR_TEIF3_Pos)     /*!< 0x02000000 */
#define DMA_LISR_TEIF3                      DMA_LISR_TEIF3_Msk               /*!< </spirit:description> */
#define DMA_LISR_DMEIF3_Pos                 (24U)
#define DMA_LISR_DMEIF3_Msk                 (0x1UL << DMA_LISR_DMEIF3_Pos)    /*!< 0x01000000 */
#define DMA_LISR_DMEIF3                     DMA_LISR_DMEIF3_Msk              /*!< </spirit:description> */
#define DMA_LISR_FEIF3_Pos                  (22U)
#define DMA_LISR_FEIF3_Msk                  (0x1UL << DMA_LISR_FEIF3_Pos)     /*!< 0x00400000 */
#define DMA_LISR_FEIF3                      DMA_LISR_FEIF3_Msk               /*!< </spirit:description> */
#define DMA_LISR_TCIF2_Pos                  (21U)
#define DMA_LISR_TCIF2_Msk                  (0x1UL << DMA_LISR_TCIF2_Pos)     /*!< 0x00200000 */
#define DMA_LISR_TCIF2                      DMA_LISR_TCIF2_Msk               /*!< </spirit:description> */
#define DMA_LISR_HTIF2_Pos                  (20U)
#define DMA_LISR_HTIF2_Msk                  (0x1UL << DMA_LISR_HTIF2_Pos)     /*!< 0x00100000 */
#define DMA_LISR_HTIF2                      DMA_LISR_HTIF2_Msk               /*!< </spirit:description> */
#define DMA_LISR_TEIF2_Pos                  (19U)
#define DMA_LISR_TEIF2_Msk                  (0x1UL << DMA_LISR_TEIF2_Pos)     /*!< 0x00080000 */
#define DMA_LISR_TEIF2                      DMA_LISR_TEIF2_Msk               /*!< </spirit:description> */
#define DMA_LISR_DMEIF2_Pos                 (18U)
#define DMA_LISR_DMEIF2_Msk                 (0x1UL << DMA_LISR_DMEIF2_Pos)    /*!< 0x00040000 */
#define DMA_LISR_DMEIF2                     DMA_LISR_DMEIF2_Msk              /*!< </spirit:description> */
#define DMA_LISR_FEIF2_Pos                  (16U)
#define DMA_LISR_FEIF2_Msk                  (0x1UL << DMA_LISR_FEIF2_Pos)     /*!< 0x00010000 */
#define DMA_LISR_FEIF2                      DMA_LISR_FEIF2_Msk               /*!< </spirit:description> */
#define DMA_LISR_TCIF1_Pos                  (11U)
#define DMA_LISR_TCIF1_Msk                  (0x1UL << DMA_LISR_TCIF1_Pos)     /*!< 0x00000800 */
#define DMA_LISR_TCIF1                      DMA_LISR_TCIF1_Msk               /*!< </spirit:description> */
#define DMA_LISR_HTIF1_Pos                  (10U)
#define DMA_LISR_HTIF1_Msk                  (0x1UL << DMA_LISR_HTIF1_Pos)     /*!< 0x00000400 */
#define DMA_LISR_HTIF1                      DMA_LISR_HTIF1_Msk               /*!< </spirit:description> */
#define DMA_LISR_TEIF1_Pos                  (9U)
#define DMA_LISR_TEIF1_Msk                  (0x1UL << DMA_LISR_TEIF1_Pos)     /*!< 0x00000200 */
#define DMA_LISR_TEIF1                      DMA_LISR_TEIF1_Msk               /*!< </spirit:description> */
#define DMA_LISR_DMEIF1_Pos                 (8U)
#define DMA_LISR_DMEIF1_Msk                 (0x1UL << DMA_LISR_DMEIF1_Pos)    /*!< 0x00000100 */
#define DMA_LISR_DMEIF1                     DMA_LISR_DMEIF1_Msk              /*!< </spirit:description> */
#define DMA_LISR_FEIF1_Pos                  (6U)
#define DMA_LISR_FEIF1_Msk                  (0x1UL << DMA_LISR_FEIF1_Pos)     /*!< 0x00000040 */
#define DMA_LISR_FEIF1                      DMA_LISR_FEIF1_Msk               /*!< </spirit:description> */
#define DMA_LISR_TCIF0_Pos                  (5U)
#define DMA_LISR_TCIF0_Msk                  (0x1UL << DMA_LISR_TCIF0_Pos)     /*!< 0x00000020 */
#define DMA_LISR_TCIF0                      DMA_LISR_TCIF0_Msk               /*!< </spirit:description> */
#define DMA_LISR_HTIF0_Pos                  (4U)
#define DMA_LISR_HTIF0_Msk                  (0x1UL << DMA_LISR_HTIF0_Pos)     /*!< 0x00000010 */
#define DMA_LISR_HTIF0                      DMA_LISR_HTIF0_Msk               /*!< </spirit:description> */
#define DMA_LISR_TEIF0_Pos                  (3U)
#define DMA_LISR_TEIF0_Msk                  (0x1UL << DMA_LISR_TEIF0_Pos)     /*!< 0x00000008 */
#define DMA_LISR_TEIF0                      DMA_LISR_TEIF0_Msk               /*!< </spirit:description> */
#define DMA_LISR_DMEIF0_Pos                 (2U)
#define DMA_LISR_DMEIF0_Msk                 (0x1UL << DMA_LISR_DMEIF0_Pos)    /*!< 0x00000004 */
#define DMA_LISR_DMEIF0                     DMA_LISR_DMEIF0_Msk              /*!< </spirit:description> */
#define DMA_LISR_FEIF0_Pos                  (0U)
#define DMA_LISR_FEIF0_Msk                  (0x1UL << DMA_LISR_FEIF0_Pos)     /*!< 0x00000001 */
#define DMA_LISR_FEIF0                      DMA_LISR_FEIF0_Msk               /*!< </spirit:description> */

/*******************  Bit definition for DMA_HISR register  *******************/
#define DMA_HISR_TCIF7_Pos                  (27U)
#define DMA_HISR_TCIF7_Msk                  (0x1UL << DMA_HISR_TCIF7_Pos)     /*!< 0x08000000 */
#define DMA_HISR_TCIF7                      DMA_HISR_TCIF7_Msk               /*!< </spirit:description> */
#define DMA_HISR_HTIF7_Pos                  (26U)
#define DMA_HISR_HTIF7_Msk                  (0x1UL << DMA_HISR_HTIF7_Pos)     /*!< 0x04000000 */
#define DMA_HISR_HTIF7                      DMA_HISR_HTIF7_Msk               /*!< </spirit:description> */
#define DMA_HISR_TEIF7_Pos                  (25U)
#define DMA_HISR_TEIF7_Msk                  (0x1UL << DMA_HISR_TEIF7_Pos)     /*!< 0x02000000 */
#define DMA_HISR_TEIF7                      DMA_HISR_TEIF7_Msk               /*!< </spirit:description> */
#define DMA_HISR_DMEIF7_Pos                 (24U)
#define DMA_HISR_DMEIF7_Msk                 (0x1UL << DMA_HISR_DMEIF7_Pos)    /*!< 0x01000000 */
#define DMA_HISR_DMEIF7                     DMA_HISR_DMEIF7_Msk              /*!< </spirit:description> */
#define DMA_HISR_FEIF7_Pos                  (22U)
#define DMA_HISR_FEIF7_Msk                  (0x1UL << DMA_HISR_FEIF7_Pos)     /*!< 0x00400000 */
#define DMA_HISR_FEIF7                      DMA_HISR_FEIF7_Msk               /*!< </spirit:description> */
#define DMA_HISR_TCIF6_Pos                  (21U)
#define DMA_HISR_TCIF6_Msk                  (0x1UL << DMA_HISR_TCIF6_Pos)     /*!< 0x00200000 */
#define DMA_HISR_TCIF6                      DMA_HISR_TCIF6_Msk               /*!< </spirit:description> */
#define DMA_HISR_HTIF6_Pos                  (20U)
#define DMA_HISR_HTIF6_Msk                  (0x1UL << DMA_HISR_HTIF6_Pos)     /*!< 0x00100000 */
#define DMA_HISR_HTIF6                      DMA_HISR_HTIF6_Msk               /*!< </spirit:description> */
#define DMA_HISR_TEIF6_Pos                  (19U)
#define DMA_HISR_TEIF6_Msk                  (0x1UL << DMA_HISR_TEIF6_Pos)     /*!< 0x00080000 */
#define DMA_HISR_TEIF6                      DMA_HISR_TEIF6_Msk               /*!< </spirit:description> */
#define DMA_HISR_DMEIF6_Pos                 (18U)
#define DMA_HISR_DMEIF6_Msk                 (0x1UL << DMA_HISR_DMEIF6_Pos)    /*!< 0x00040000 */
#define DMA_HISR_DMEIF6                     DMA_HISR_DMEIF6_Msk              /*!< </spirit:description> */
#define DMA_HISR_FEIF6_Pos                  (16U)
#define DMA_HISR_FEIF6_Msk                  (0x1UL << DMA_HISR_FEIF6_Pos)     /*!< 0x00010000 */
#define DMA_HISR_FEIF6                      DMA_HISR_FEIF6_Msk               /*!< </spirit:description> */
#define DMA_HISR_TCIF5_Pos                  (11U)
#define DMA_HISR_TCIF5_Msk                  (0x1UL << DMA_HISR_TCIF5_Pos)     /*!< 0x00000800 */
#define DMA_HISR_TCIF5                      DMA_HISR_TCIF5_Msk               /*!< </spirit:description> */
#define DMA_HISR_HTIF5_Pos                  (10U)
#define DMA_HISR_HTIF5_Msk                  (0x1UL << DMA_HISR_HTIF5_Pos)     /*!< 0x00000400 */
#define DMA_HISR_HTIF5                      DMA_HISR_HTIF5_Msk               /*!< </spirit:description> */
#define DMA_HISR_TEIF5_Pos                  (9U)
#define DMA_HISR_TEIF5_Msk                  (0x1UL << DMA_HISR_TEIF5_Pos)     /*!< 0x00000200 */
#define DMA_HISR_TEIF5                      DMA_HISR_TEIF5_Msk               /*!< </spirit:description> */
#define DMA_HISR_DMEIF5_Pos                 (8U)
#define DMA_HISR_DMEIF5_Msk                 (0x1UL << DMA_HISR_DMEIF5_Pos)    /*!< 0x00000100 */
#define DMA_HISR_DMEIF5                     DMA_HISR_DMEIF5_Msk              /*!< </spirit:description> */
#define DMA_HISR_FEIF5_Pos                  (6U)
#define DMA_HISR_FEIF5_Msk                  (0x1UL << DMA_HISR_FEIF5_Pos)     /*!< 0x00000040 */
#define DMA_HISR_FEIF5                      DMA_HISR_FEIF5_Msk               /*!< </spirit:description> */
#define DMA_HISR_TCIF4_Pos                  (5U)
#define DMA_HISR_TCIF4_Msk                  (0x1UL << DMA_HISR_TCIF4_Pos)     /*!< 0x00000020 */
#define DMA_HISR_TCIF4                      DMA_HISR_TCIF4_Msk               /*!< </spirit:description> */
#define DMA_HISR_HTIF4_Pos                  (4U)
#define DMA_HISR_HTIF4_Msk                  (0x1UL << DMA_HISR_HTIF4_Pos)     /*!< 0x00000010 */
#define DMA_HISR_HTIF4                      DMA_HISR_HTIF4_Msk               /*!< </spirit:description> */
#define DMA_HISR_TEIF4_Pos                  (3U)
#define DMA_HISR_TEIF4_Msk                  (0x1UL << DMA_HISR_TEIF4_Pos)     /*!< 0x00000008 */
#define DMA_HISR_TEIF4                      DMA_HISR_TEIF4_Msk               /*!< </spirit:description> */
#define DMA_HISR_DMEIF4_Pos                 (2U)
#define DMA_HISR_DMEIF4_Msk                 (0x1UL << DMA_HISR_DMEIF4_Pos)    /*!< 0x00000004 */
#define DMA_HISR_DMEIF4                     DMA_HISR_DMEIF4_Msk              /*!< </spirit:description> */
#define DMA_HISR_FEIF4_Pos                  (0U)
#define DMA_HISR_FEIF4_Msk                  (0x1UL << DMA_HISR_FEIF4_Pos)     /*!< 0x00000001 */
#define DMA_HISR_FEIF4                      DMA_HISR_FEIF4_Msk               /*!< </spirit:description> */

/******************  Bit definition for DMA_LIFCR register  *******************/
#define DMA_LIFCR_CTCIF3_Pos                (27U)
#define DMA_LIFCR_CTCIF3_Msk                (0x1UL << DMA_LIFCR_CTCIF3_Pos)   /*!< 0x08000000 */
#define DMA_LIFCR_CTCIF3                    DMA_LIFCR_CTCIF3_Msk             /*!< </spirit:description> */
#define DMA_LIFCR_CHTIF3_Pos                (26U)
#define DMA_LIFCR_CHTIF3_Msk                (0x1UL << DMA_LIFCR_CHTIF3_Pos)   /*!< 0x04000000 */
#define DMA_LIFCR_CHTIF3                    DMA_LIFCR_CHTIF3_Msk             /*!< </spirit:description> */
#define DMA_LIFCR_CTEIF3_Pos                (25U)
#define DMA_LIFCR_CTEIF3_Msk                (0x1UL << DMA_LIFCR_CTEIF3_Pos)   /*!< 0x02000000 */
#define DMA_LIFCR_CTEIF3                    DMA_LIFCR_CTEIF3_Msk             /*!< </spirit:description> */
#define DMA_LIFCR_CDMEIF3_Pos               (24U)
#define DMA_LIFCR_CDMEIF3_Msk               (0x1UL << DMA_LIFCR_CDMEIF3_Pos)  /*!< 0x01000000 */
#define DMA_LIFCR_CDMEIF3                   DMA_LIFCR_CDMEIF3_Msk            /*!< </spirit:description> */
#define DMA_LIFCR_CFEIF3_Pos                (22U)
#define DMA_LIFCR_CFEIF3_Msk                (0x1UL << DMA_LIFCR_CFEIF3_Pos)   /*!< 0x00400000 */
#define DMA_LIFCR_CFEIF3                    DMA_LIFCR_CFEIF3_Msk             /*!< </spirit:description> */
#define DMA_LIFCR_CTCIF2_Pos                (21U)
#define DMA_LIFCR_CTCIF2_Msk                (0x1UL << DMA_LIFCR_CTCIF2_Pos)   /*!< 0x00200000 */
#define DMA_LIFCR_CTCIF2                    DMA_LIFCR_CTCIF2_Msk             /*!< </spirit:description> */
#define DMA_LIFCR_CHTIF2_Pos                (20U)
#define DMA_LIFCR_CHTIF2_Msk                (0x1UL << DMA_LIFCR_CHTIF2_Pos)   /*!< 0x00100000 */
#define DMA_LIFCR_CHTIF2                    DMA_LIFCR_CHTIF2_Msk             /*!< </spirit:description> */
#define DMA_LIFCR_CTEIF2_Pos                (19U)
#define DMA_LIFCR_CTEIF2_Msk                (0x1UL << DMA_LIFCR_CTEIF2_Pos)   /*!< 0x00080000 */
#define DMA_LIFCR_CTEIF2                    DMA_LIFCR_CTEIF2_Msk             /*!< </spirit:description> */
#define DMA_LIFCR_CDMEIF2_Pos               (18U)
#define DMA_LIFCR_CDMEIF2_Msk               (0x1UL << DMA_LIFCR_CDMEIF2_Pos)  /*!< 0x00040000 */
#define DMA_LIFCR_CDMEIF2                   DMA_LIFCR_CDMEIF2_Msk            /*!< </spirit:description> */
#define DMA_LIFCR_CFEIF2_Pos                (16U)
#define DMA_LIFCR_CFEIF2_Msk                (0x1UL << DMA_LIFCR_CFEIF2_Pos)   /*!< 0x00010000 */
#define DMA_LIFCR_CFEIF2                    DMA_LIFCR_CFEIF2_Msk             /*!< </spirit:description> */
#define DMA_LIFCR_CTCIF1_Pos                (11U)
#define DMA_LIFCR_CTCIF1_Msk                (0x1UL << DMA_LIFCR_CTCIF1_Pos)   /*!< 0x00000800 */
#define DMA_LIFCR_CTCIF1                    DMA_LIFCR_CTCIF1_Msk             /*!< </spirit:description> */
#define DMA_LIFCR_CHTIF1_Pos                (10U)
#define DMA_LIFCR_CHTIF1_Msk                (0x1UL << DMA_LIFCR_CHTIF1_Pos)   /*!< 0x00000400 */
#define DMA_LIFCR_CHTIF1                    DMA_LIFCR_CHTIF1_Msk             /*!< </spirit:description> */
#define DMA_LIFCR_CTEIF1_Pos                (9U)
#define DMA_LIFCR_CTEIF1_Msk                (0x1UL << DMA_LIFCR_CTEIF1_Pos)   /*!< 0x00000200 */
#define DMA_LIFCR_CTEIF1                    DMA_LIFCR_CTEIF1_Msk             /*!< </spirit:description> */
#define DMA_LIFCR_CDMEIF1_Pos               (8U)
#define DMA_LIFCR_CDMEIF1_Msk               (0x1UL << DMA_LIFCR_CDMEIF1_Pos)  /*!< 0x00000100 */
#define DMA_LIFCR_CDMEIF1                   DMA_LIFCR_CDMEIF1_Msk            /*!< </spirit:description> */
#define DMA_LIFCR_CFEIF1_Pos                (6U)
#define DMA_LIFCR_CFEIF1_Msk                (0x1UL << DMA_LIFCR_CFEIF1_Pos)   /*!< 0x00000040 */
#define DMA_LIFCR_CFEIF1                    DMA_LIFCR_CFEIF1_Msk             /*!< </spirit:description> */
#define DMA_LIFCR_CTCIF0_Pos                (5U)
#define DMA_LIFCR_CTCIF0_Msk                (0x1UL << DMA_LIFCR_CTCIF0_Pos)   /*!< 0x00000020 */
#define DMA_LIFCR_CTCIF0                    DMA_LIFCR_CTCIF0_Msk             /*!< </spirit:description> */
#define DMA_LIFCR_CHTIF0_Pos                (4U)
#define DMA_LIFCR_CHTIF0_Msk                (0x1UL << DMA_LIFCR_CHTIF0_Pos)   /*!< 0x00000010 */
#define DMA_LIFCR_CHTIF0                    DMA_LIFCR_CHTIF0_Msk             /*!< </spirit:description> */
#define DMA_LIFCR_CTEIF0_Pos                (3U)
#define DMA_LIFCR_CTEIF0_Msk                (0x1UL << DMA_LIFCR_CTEIF0_Pos)   /*!< 0x00000008 */
#define DMA_LIFCR_CTEIF0                    DMA_LIFCR_CTEIF0_Msk             /*!< </spirit:description> */
#define DMA_LIFCR_CDMEIF0_Pos               (2U)
#define DMA_LIFCR_CDMEIF0_Msk               (0x1UL << DMA_LIFCR_CDMEIF0_Pos)  /*!< 0x00000004 */
#define DMA_LIFCR_CDMEIF0                   DMA_LIFCR_CDMEIF0_Msk            /*!< </spirit:description> */
#define DMA_LIFCR_CFEIF0_Pos                (0U)
#define DMA_LIFCR_CFEIF0_Msk                (0x1UL << DMA_LIFCR_CFEIF0_Pos)   /*!< 0x00000001 */
#define DMA_LIFCR_CFEIF0                    DMA_LIFCR_CFEIF0_Msk             /*!< </spirit:description> */

/******************  Bit definition for DMA_HIFCR register  *******************/
#define DMA_HIFCR_CTCIF7_Pos                (27U)
#define DMA_HIFCR_CTCIF7_Msk                (0x1UL << DMA_HIFCR_CTCIF7_Pos)   /*!< 0x08000000 */
#define DMA_HIFCR_CTCIF7                    DMA_HIFCR_CTCIF7_Msk             /*!< </spirit:description> */
#define DMA_HIFCR_CHTIF7_Pos                (26U)
#define DMA_HIFCR_CHTIF7_Msk                (0x1UL << DMA_HIFCR_CHTIF7_Pos)   /*!< 0x04000000 */
#define DMA_HIFCR_CHTIF7                    DMA_HIFCR_CHTIF7_Msk             /*!< </spirit:description> */
#define DMA_HIFCR_CTEIF7_Pos                (25U)
#define DMA_HIFCR_CTEIF7_Msk                (0x1UL << DMA_HIFCR_CTEIF7_Pos)   /*!< 0x02000000 */
#define DMA_HIFCR_CTEIF7                    DMA_HIFCR_CTEIF7_Msk             /*!< </spirit:description> */
#define DMA_HIFCR_CDMEIF7_Pos               (24U)
#define DMA_HIFCR_CDMEIF7_Msk               (0x1UL << DMA_HIFCR_CDMEIF7_Pos)  /*!< 0x01000000 */
#define DMA_HIFCR_CDMEIF7                   DMA_HIFCR_CDMEIF7_Msk            /*!< </spirit:description> */
#define DMA_HIFCR_CFEIF7_Pos                (22U)
#define DMA_HIFCR_CFEIF7_Msk                (0x1UL << DMA_HIFCR_CFEIF7_Pos)   /*!< 0x00400000 */
#define DMA_HIFCR_CFEIF7                    DMA_HIFCR_CFEIF7_Msk             /*!< </spirit:description> */
#define DMA_HIFCR_CTCIF6_Pos                (21U)
#define DMA_HIFCR_CTCIF6_Msk                (0x1UL << DMA_HIFCR_CTCIF6_Pos)   /*!< 0x00200000 */
#define DMA_HIFCR_CTCIF6                    DMA_HIFCR_CTCIF6_Msk             /*!< </spirit:description> */
#define DMA_HIFCR_CHTIF6_Pos                (20U)
#define DMA_HIFCR_CHTIF6_Msk                (0x1UL << DMA_HIFCR_CHTIF6_Pos)   /*!< 0x00100000 */
#define DMA_HIFCR_CHTIF6                    DMA_HIFCR_CHTIF6_Msk             /*!< </spirit:description> */
#define DMA_HIFCR_CTEIF6_Pos                (19U)
#define DMA_HIFCR_CTEIF6_Msk                (0x1UL << DMA_HIFCR_CTEIF6_Pos)   /*!< 0x00080000 */
#define DMA_HIFCR_CTEIF6                    DMA_HIFCR_CTEIF6_Msk             /*!< </spirit:description> */
#define DMA_HIFCR_CDMEIF6_Pos               (18U)
#define DMA_HIFCR_CDMEIF6_Msk               (0x1UL << DMA_HIFCR_CDMEIF6_Pos)  /*!< 0x00040000 */
#define DMA_HIFCR_CDMEIF6                   DMA_HIFCR_CDMEIF6_Msk            /*!< </spirit:description> */
#define DMA_HIFCR_CFEIF6_Pos                (16U)
#define DMA_HIFCR_CFEIF6_Msk                (0x1UL << DMA_HIFCR_CFEIF6_Pos)   /*!< 0x00010000 */
#define DMA_HIFCR_CFEIF6                    DMA_HIFCR_CFEIF6_Msk             /*!< </spirit:description> */
#define DMA_HIFCR_CTCIF5_Pos                (11U)
#define DMA_HIFCR_CTCIF5_Msk                (0x1UL << DMA_HIFCR_CTCIF5_Pos)   /*!< 0x00000800 */
#define DMA_HIFCR_CTCIF5                    DMA_HIFCR_CTCIF5_Msk             /*!< </spirit:description> */
#define DMA_HIFCR_CHTIF5_Pos                (10U)
#define DMA_HIFCR_CHTIF5_Msk                (0x1UL << DMA_HIFCR_CHTIF5_Pos)   /*!< 0x00000400 */
#define DMA_HIFCR_CHTIF5                    DMA_HIFCR_CHTIF5_Msk             /*!< </spirit:description> */
#define DMA_HIFCR_CTEIF5_Pos                (9U)
#define DMA_HIFCR_CTEIF5_Msk                (0x1UL << DMA_HIFCR_CTEIF5_Pos)   /*!< 0x00000200 */
#define DMA_HIFCR_CTEIF5                    DMA_HIFCR_CTEIF5_Msk             /*!< </spirit:description> */
#define DMA_HIFCR_CDMEIF5_Pos               (8U)
#define DMA_HIFCR_CDMEIF5_Msk               (0x1UL << DMA_HIFCR_CDMEIF5_Pos)  /*!< 0x00000100 */
#define DMA_HIFCR_CDMEIF5                   DMA_HIFCR_CDMEIF5_Msk            /*!< </spirit:description> */
#define DMA_HIFCR_CFEIF5_Pos                (6U)
#define DMA_HIFCR_CFEIF5_Msk                (0x1UL << DMA_HIFCR_CFEIF5_Pos)   /*!< 0x00000040 */
#define DMA_HIFCR_CFEIF5                    DMA_HIFCR_CFEIF5_Msk             /*!< </spirit:description> */
#define DMA_HIFCR_CTCIF4_Pos                (5U)
#define DMA_HIFCR_CTCIF4_Msk                (0x1UL << DMA_HIFCR_CTCIF4_Pos)   /*!< 0x00000020 */
#define DMA_HIFCR_CTCIF4                    DMA_HIFCR_CTCIF4_Msk             /*!< </spirit:description> */
#define DMA_HIFCR_CHTIF4_Pos                (4U)
#define DMA_HIFCR_CHTIF4_Msk                (0x1UL << DMA_HIFCR_CHTIF4_Pos)   /*!< 0x00000010 */
#define DMA_HIFCR_CHTIF4                    DMA_HIFCR_CHTIF4_Msk             /*!< </spirit:description> */
#define DMA_HIFCR_CTEIF4_Pos                (3U)
#define DMA_HIFCR_CTEIF4_Msk                (0x1UL << DMA_HIFCR_CTEIF4_Pos)   /*!< 0x00000008 */
#define DMA_HIFCR_CTEIF4                    DMA_HIFCR_CTEIF4_Msk             /*!< </spirit:description> */
#define DMA_HIFCR_CDMEIF4_Pos               (2U)
#define DMA_HIFCR_CDMEIF4_Msk               (0x1UL << DMA_HIFCR_CDMEIF4_Pos)  /*!< 0x00000004 */
#define DMA_HIFCR_CDMEIF4                   DMA_HIFCR_CDMEIF4_Msk            /*!< </spirit:description> */
#define DMA_HIFCR_CFEIF4_Pos                (0U)
#define DMA_HIFCR_CFEIF4_Msk                (0x1UL << DMA_HIFCR_CFEIF4_Pos)   /*!< 0x00000001 */
#define DMA_HIFCR_CFEIF4                    DMA_HIFCR_CFEIF4_Msk             /*!< </spirit:description> */


/***************  Bit definition for DMA_SxCR register  ***************/
#define DMA_SxCR_EN_Pos          (0U)
#define DMA_SxCR_EN_Msk          (0x1UL << DMA_SxCR_EN_Pos)   /*!< 0x00000001 */
#define DMA_SxCR_EN              DMA_SxCR_EN_Msk       /*!< </spirit:description> */
#define DMA_SxCR_DMEIE_Pos       (1U)
#define DMA_SxCR_DMEIE_Msk       (0x1UL << DMA_SxCR_DMEIE_Pos)      /*!< 0x00000002 */
#define DMA_SxCR_DMEIE           DMA_SxCR_DMEIE_Msk    /*!< </spirit:description> */
#define DMA_SxCR_TEIE_Pos        (2U)
#define DMA_SxCR_TEIE_Msk        (0x1UL << DMA_SxCR_TEIE_Pos)     /*!< 0x00000004 */
#define DMA_SxCR_TEIE            DMA_SxCR_TEIE_Msk     /*!< </spirit:description> */
#define DMA_SxCR_HTIE_Pos        (3U)
#define DMA_SxCR_HTIE_Msk        (0x1UL << DMA_SxCR_HTIE_Pos)     /*!< 0x00000008 */
#define DMA_SxCR_HTIE            DMA_SxCR_HTIE_Msk     /*!< </spirit:description> */
#define DMA_SxCR_TCIE_Pos        (4U)
#define DMA_SxCR_TCIE_Msk        (0x1UL << DMA_SxCR_TCIE_Pos)     /*!< 0x00000010 */
#define DMA_SxCR_TCIE            DMA_SxCR_TCIE_Msk     /*!< </spirit:description> */
#define DMA_SxCR_PFCTRL_Pos      (5U)
#define DMA_SxCR_PFCTRL_Msk      (0x1UL << DMA_SxCR_PFCTRL_Pos)       /*!< 0x00000020 */
#define DMA_SxCR_PFCTRL          DMA_SxCR_PFCTRL_Msk   /*!< </spirit:description> */
#define DMA_SxCR_DIR_Pos         (6U)
#define DMA_SxCR_DIR_Msk         (0x3UL << DMA_SxCR_DIR_Pos)    /*!< 0x000000C0 */
#define DMA_SxCR_DIR             DMA_SxCR_DIR_Msk      /*!< </spirit:description> */
#define DMA_SxCR_DIR_0  (0x1UL << DMA_SxCR_DIR_Pos)            /*!< 0x00000040 */
#define DMA_SxCR_DIR_1  (0x2UL << DMA_SxCR_DIR_Pos)            /*!< 0x00000080 */
#define DMA_SxCR_CIRC_Pos        (8U)
#define DMA_SxCR_CIRC_Msk        (0x1UL << DMA_SxCR_CIRC_Pos)     /*!< 0x00000100 */
#define DMA_SxCR_CIRC            DMA_SxCR_CIRC_Msk     /*!< </spirit:description> */
#define DMA_SxCR_PINC_Pos        (9U)
#define DMA_SxCR_PINC_Msk        (0x1UL << DMA_SxCR_PINC_Pos)     /*!< 0x00000200 */
#define DMA_SxCR_PINC            DMA_SxCR_PINC_Msk     /*!< </spirit:description> */
#define DMA_SxCR_MINC_Pos        (10U)
#define DMA_SxCR_MINC_Msk        (0x1UL << DMA_SxCR_MINC_Pos)     /*!< 0x00000400 */
#define DMA_SxCR_MINC            DMA_SxCR_MINC_Msk     /*!< </spirit:description> */
#define DMA_SxCR_PSIZE_Pos       (11U)
#define DMA_SxCR_PSIZE_Msk       (0x3UL << DMA_SxCR_PSIZE_Pos)      /*!< 0x00001800 */
#define DMA_SxCR_PSIZE           DMA_SxCR_PSIZE_Msk    /*!< </spirit:description> */
#define DMA_SxCR_PSIZE_0  (0x1UL << DMA_SxCR_PSIZE_Pos)               /*!< 0x00000800 */
#define DMA_SxCR_PSIZE_1  (0x2UL << DMA_SxCR_PSIZE_Pos)                /*!< 0x00001000 */
#define DMA_SxCR_MSIZE_Pos       (13U)
#define DMA_SxCR_MSIZE_Msk       (0x3UL << DMA_SxCR_MSIZE_Pos)      /*!< 0x00006000 */
#define DMA_SxCR_MSIZE           DMA_SxCR_MSIZE_Msk    /*!< </spirit:description> */
#define DMA_SxCR_MSIZE_0  (0x1UL << DMA_SxCR_MSIZE_Pos)                /*!< 0x00002000 */
#define DMA_SxCR_MSIZE_1  (0x2UL << DMA_SxCR_MSIZE_Pos)                /*!< 0x00004000 */
#define DMA_SxCR_PINCOS_Pos      (15U)
#define DMA_SxCR_PINCOS_Msk      (0x1UL << DMA_SxCR_PINCOS_Pos)       /*!< 0x00008000 */
#define DMA_SxCR_PINCOS          DMA_SxCR_PINCOS_Msk   /*!< </spirit:description> */
#define DMA_SxCR_PL_Pos          (16U)
#define DMA_SxCR_PL_Msk          (0x3UL << DMA_SxCR_PL_Pos)   /*!< 0x00030000 */
#define DMA_SxCR_PL              DMA_SxCR_PL_Msk       /*!< </spirit:description> */
#define DMA_SxCR_PL_0   (0x1UL << DMA_SxCR_PL_Pos)              /*!< 0x00010000 */
#define DMA_SxCR_PL_1   (0x2UL << DMA_SxCR_PL_Pos)              /*!< 0x00020000 */
#define DMA_SxCR_DBM_Pos         (18U)
#define DMA_SxCR_DBM_Msk         (0x1UL << DMA_SxCR_DBM_Pos)    /*!< 0x00040000 */
#define DMA_SxCR_DBM             DMA_SxCR_DBM_Msk      /*!< </spirit:description> */
#define DMA_SxCR_CT_Pos          (19U)
#define DMA_SxCR_CT_Msk          (0x1UL << DMA_SxCR_CT_Pos)   /*!< 0x00080000 */
#define DMA_SxCR_CT              DMA_SxCR_CT_Msk       /*!< </spirit:description> */
#define DMA_SxCR_TRBUFF_Pos      (20U)
#define DMA_SxCR_TRBUFF_Msk      (0x1UL << DMA_SxCR_TRBUFF_Pos)       /*!< 0x00100000 */
#define DMA_SxCR_TRBUFF          DMA_SxCR_TRBUFF_Msk   /*!< </spirit:description> */
#define DMA_SxCR_PBURST_Pos      (21U)
#define DMA_SxCR_PBURST_Msk      (0x3UL << DMA_SxCR_PBURST_Pos)       /*!< 0x00600000 */
#define DMA_SxCR_PBURST          DMA_SxCR_PBURST_Msk   /*!< </spirit:description> */
#define DMA_SxCR_PBURST_0   (0x1UL << DMA_SxCR_PBURST_Pos)                   /*!< 0x00200000 */
#define DMA_SxCR_PBURST_1   (0x2UL << DMA_SxCR_PBURST_Pos)                   /*!< 0x00400000 */
#define DMA_SxCR_MBURST_Pos      (23U)
#define DMA_SxCR_MBURST_Msk      (0x3UL << DMA_SxCR_MBURST_Pos)       /*!< 0x01800000 */
#define DMA_SxCR_MBURST          DMA_SxCR_MBURST_Msk   /*!< </spirit:description> */
#define DMA_SxCR_MBURST_0   (0x1UL << DMA_SxCR_MBURST_Pos)                   /*!< 0x00800000 */
#define DMA_SxCR_MBURST_1   (0x2UL << DMA_SxCR_MBURST_Pos)                    /*!< 0x01000000 */

/**************  Bit definition for DMA_SxNDTR register  **************/
#define DMA_SxNDTR_NDT_Pos       (0U)
#define DMA_SxNDTR_NDT_Msk       (0xFFFFUL << DMA_SxNDTR_NDT_Pos)         /*!< 0x0000FFFF */
#define DMA_SxNDTR_NDT           DMA_SxNDTR_NDT_Msk    /*!< </spirit:description> */
#define DMA_SxNDTR_NDT_0  (0x1UL << DMA_SxNDTR_NDT_Pos)             /*!< 0x00000001 */
#define DMA_SxNDTR_NDT_1  (0x2UL << DMA_SxNDTR_NDT_Pos)             /*!< 0x00000002 */
#define DMA_SxNDTR_NDT_2  (0x4UL << DMA_SxNDTR_NDT_Pos)             /*!< 0x00000004 */
#define DMA_SxNDTR_NDT_3  (0x8UL << DMA_SxNDTR_NDT_Pos)             /*!< 0x00000008 */
#define DMA_SxNDTR_NDT_4  (0x10UL << DMA_SxNDTR_NDT_Pos)              /*!< 0x00000010 */
#define DMA_SxNDTR_NDT_5  (0x20UL << DMA_SxNDTR_NDT_Pos)              /*!< 0x00000020 */
#define DMA_SxNDTR_NDT_6  (0x40UL << DMA_SxNDTR_NDT_Pos)              /*!< 0x00000040 */
#define DMA_SxNDTR_NDT_7  (0x80UL << DMA_SxNDTR_NDT_Pos)              /*!< 0x00000080 */
#define DMA_SxNDTR_NDT_8  (0x100UL << DMA_SxNDTR_NDT_Pos)               /*!< 0x00000100 */
#define DMA_SxNDTR_NDT_9  (0x200UL << DMA_SxNDTR_NDT_Pos)               /*!< 0x00000200 */
#define DMA_SxNDTR_NDT_10 (0x400UL << DMA_SxNDTR_NDT_Pos)               /*!< 0x00000400 */
#define DMA_SxNDTR_NDT_11 (0x800UL << DMA_SxNDTR_NDT_Pos)               /*!< 0x00000800 */
#define DMA_SxNDTR_NDT_12 (0x1000UL << DMA_SxNDTR_NDT_Pos)                /*!< 0x00001000 */
#define DMA_SxNDTR_NDT_13 (0x2000UL << DMA_SxNDTR_NDT_Pos)                /*!< 0x00002000 */
#define DMA_SxNDTR_NDT_14 (0x4000UL << DMA_SxNDTR_NDT_Pos)                /*!< 0x00004000 */
#define DMA_SxNDTR_NDT_15 (0x8000UL << DMA_SxNDTR_NDT_Pos)                /*!< 0x00008000 */

/**************  Bit definition for DMA_SxPAR register  ***************/
#define DMA_SxPAR_PA_Pos         (0U)
#define DMA_SxPAR_PA_Msk         (0xFFFFFFFFUL << DMA_SxPAR_PA_Pos)           /*!< 0xFFFFFFFF */
#define DMA_SxPAR_PA             DMA_SxPAR_PA_Msk      /*!< </spirit:description> */

/**************  Bit definition for DMA_SxM0AR register  **************/
#define DMA_SxM0AR_M0A_Pos       (0U)
#define DMA_SxM0AR_M0A_Msk       (0xFFFFFFFFUL << DMA_SxM0AR_M0A_Pos)             /*!< 0xFFFFFFFF */
#define DMA_SxM0AR_M0A           DMA_SxM0AR_M0A_Msk    /*!< </spirit:description> */

/**************  Bit definition for DMA_SxM1AR register  **************/
#define DMA_SxM1AR_M1A_Pos       (0U)
#define DMA_SxM1AR_M1A_Msk       (0xFFFFFFFFUL << DMA_SxM1AR_M1A_Pos)             /*!< 0xFFFFFFFF */
#define DMA_SxM1AR_M1A           DMA_SxM1AR_M1A_Msk    /*!< </spirit:description> */

/**************  Bit definition for DMA_SxFCR register  ***************/
#define DMA_SxFCR_FTH_Pos        (0U)
#define DMA_SxFCR_FTH_Msk        (0x3UL << DMA_SxFCR_FTH_Pos)     /*!< 0x00000003 */
#define DMA_SxFCR_FTH            DMA_SxFCR_FTH_Msk     /*!< </spirit:description> */
#define DMA_SxFCR_FTH_0          (0x1UL << DMA_SxFCR_FTH_Pos)
#define DMA_SxFCR_FTH_1          (0x2UL << DMA_SxFCR_FTH_Pos)
#define DMA_SxFCR_DMDIS_Pos      (2U)
#define DMA_SxFCR_DMDIS_Msk      (0x1UL << DMA_SxFCR_DMDIS_Pos)       /*!< 0x00000004 */
#define DMA_SxFCR_DMDIS          DMA_SxFCR_DMDIS_Msk   /*!< </spirit:description> */
#define DMA_SxFCR_FS_Pos         (3U)
#define DMA_SxFCR_FS_Msk         (0x7UL << DMA_SxFCR_FS_Pos)    /*!< 0x00000038 */
#define DMA_SxFCR_FS             DMA_SxFCR_FS_Msk      /*!< </spirit:description> */
#define DMA_SxFCR_FS_0           (0x1UL << DMA_SxFCR_FS_Pos)
#define DMA_SxFCR_FS_1           (0x2UL << DMA_SxFCR_FS_Pos)
#define DMA_SxFCR_FS_2           (0x4UL << DMA_SxFCR_FS_Pos)
#define DMA_SxFCR_FEIE_Pos       (7U)
#define DMA_SxFCR_FEIE_Msk       (0x1UL << DMA_SxFCR_FEIE_Pos)      /*!< 0x00000080 */
#define DMA_SxFCR_FEIE           DMA_SxFCR_FEIE_Msk    /*!< </spirit:description> */

#define DMA1_BASE                   0x48004000UL 
#define DMA1_Stream0_BASE           0x48004010UL 
#define DMA1_Stream1_BASE           0x48004028UL 
#define DMA1_Stream2_BASE           0x48004040UL 
#define DMA1_Stream3_BASE           0x48004058UL 
#define DMA1_Stream4_BASE           0x48004070UL 
#define DMA1_Stream5_BASE           0x48004088UL 
#define DMA1_Stream6_BASE           0x480040A0UL 
#define DMA1_Stream7_BASE           0x480040B8UL 


#define DMA1                        ((DMA_TypeDef *) DMA1_BASE) 
#define DMA1_Stream0                ((DMA_Stream_TypeDef *) DMA1_Stream0_BASE) 
#define DMA1_Stream1                ((DMA_Stream_TypeDef *) DMA1_Stream1_BASE) 
#define DMA1_Stream2                ((DMA_Stream_TypeDef *) DMA1_Stream2_BASE) 
#define DMA1_Stream3                ((DMA_Stream_TypeDef *) DMA1_Stream3_BASE) 
#define DMA1_Stream4                ((DMA_Stream_TypeDef *) DMA1_Stream4_BASE) 
#define DMA1_Stream5                ((DMA_Stream_TypeDef *) DMA1_Stream5_BASE) 
#define DMA1_Stream6                ((DMA_Stream_TypeDef *) DMA1_Stream6_BASE) 
#define DMA1_Stream7                ((DMA_Stream_TypeDef *) DMA1_Stream7_BASE) 

#define DMA2_BASE                   0x44004000UL 
#define DMA2_Stream0_BASE           0x44004010UL 
#define DMA2_Stream1_BASE           0x44004028UL 
#define DMA2_Stream2_BASE           0x44004040UL 
#define DMA2_Stream3_BASE           0x44004058UL 
#define DMA2_Stream4_BASE           0x44004070UL 
#define DMA2_Stream5_BASE           0x44004088UL 
#define DMA2_Stream6_BASE           0x440040A0UL 
#define DMA2_Stream7_BASE           0x440040B8UL 


#define DMA2                        ((DMA_TypeDef *) DMA2_BASE) 
#define DMA2_Stream0                ((DMA_Stream_TypeDef *) DMA2_Stream0_BASE) 
#define DMA2_Stream1                ((DMA_Stream_TypeDef *) DMA2_Stream1_BASE) 
#define DMA2_Stream2                ((DMA_Stream_TypeDef *) DMA2_Stream2_BASE) 
#define DMA2_Stream3                ((DMA_Stream_TypeDef *) DMA2_Stream3_BASE) 
#define DMA2_Stream4                ((DMA_Stream_TypeDef *) DMA2_Stream4_BASE) 
#define DMA2_Stream5                ((DMA_Stream_TypeDef *) DMA2_Stream5_BASE) 
#define DMA2_Stream6                ((DMA_Stream_TypeDef *) DMA2_Stream6_BASE) 
#define DMA2_Stream7                ((DMA_Stream_TypeDef *) DMA2_Stream7_BASE) 



#endif /* __SR5E1_DMA_H */

