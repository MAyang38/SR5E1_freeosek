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

#ifndef __SR5E1_DMAMUX1_H
#define __SR5E1_DMAMUX1_H

/*******************************************************************************
 * REVISION HISTORY                                                            *
 * REV       DATE       RM REV          DESCRIPTION OF CHANGE                  *
 * ------ ----------- ------------ --------------------------------------------*
 * 1.0C1  15-Mar-2022 Rev 1 Draft C     SR5E1_RDP_0_1_Rev1_C_18FEB22           *
 *                                      Fixed registers access rights          *
 *                                      Remamedd BASE addresse to DMAMUX1      *
 ******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                              (DMAMUX_Channel)                             */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO uint32_t CCR;  /*!< CCR Address offset: 0x0 */
} DMAMUX_Channel_TypeDef;


/******************************************************************************/
/*                                                                            */
/*                           (DMAMUX_ChannelStatus)                           */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __I  uint32_t CSR;  /*!< CSR Address offset: 0x0 */
  __O  uint32_t CFR;  /*!< CFR Address offset: 0x4 */
} DMAMUX_ChannelStatus_TypeDef;

/******************************************************************************/
/*                                                                            */
/*                            (DMAMUX_RequestGen)                             */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO uint32_t RGCR;  /*!< RGCR Address offset: 0x0 */
} DMAMUX_RequestGen_TypeDef;


/******************************************************************************/
/*                                                                            */
/*                          (DMAMUX_RequestGenStatus)                         */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __I  uint32_t RGSR;   /*!< RGSR  Address offset: 0x0 */
  __O  uint32_t RGCFR;  /*!< RGCFR Address offset: 0x4 */
} DMAMUX_RequestGenStatus_TypeDef;


/*************  Bit definition for DMAMUX_CCR register  **************/
#define DMAMUX_CCR_DMAREQ_ID_Pos    (0U)
#define DMAMUX_CCR_DMAREQ_ID_Msk    (0xFFUL << DMAMUX_CCR_DMAREQ_ID_Pos)          /*!< 0x000000FF */
#define DMAMUX_CCR_DMAREQ_ID        DMAMUX_CCR_DMAREQ_ID_Msk /*!< </spirit:description> */
#define DMAMUX_CCR_DMAREQ_ID_0      (0x1UL << DMAMUX_CCR_DMAREQ_ID_Pos)               /*!< 0x00000001 */
#define DMAMUX_CCR_DMAREQ_ID_1      (0x2UL << DMAMUX_CCR_DMAREQ_ID_Pos)               /*!< 0x00000002 */
#define DMAMUX_CCR_DMAREQ_ID_2      (0x4UL << DMAMUX_CCR_DMAREQ_ID_Pos)               /*!< 0x00000004 */
#define DMAMUX_CCR_DMAREQ_ID_3      (0x8UL << DMAMUX_CCR_DMAREQ_ID_Pos)               /*!< 0x00000008 */
#define DMAMUX_CCR_DMAREQ_ID_4      (0x10UL << DMAMUX_CCR_DMAREQ_ID_Pos)                /*!< 0x00000010 */
#define DMAMUX_CCR_DMAREQ_ID_5      (0x20UL << DMAMUX_CCR_DMAREQ_ID_Pos)                /*!< 0x00000020 */
#define DMAMUX_CCR_DMAREQ_ID_6      (0x40UL << DMAMUX_CCR_DMAREQ_ID_Pos)                /*!< 0x00000040 */
#define DMAMUX_CCR_DMAREQ_ID_7      (0x80UL << DMAMUX_CCR_DMAREQ_ID_Pos)                /*!< 0x00000080 */
#define DMAMUX_CCR_SOIE_Pos         (8U)
#define DMAMUX_CCR_SOIE_Msk         (0x1UL << DMAMUX_CCR_SOIE_Pos)    /*!< 0x00000100 */
#define DMAMUX_CCR_SOIE             DMAMUX_CCR_SOIE_Msk      /*!< </spirit:description> */
#define DMAMUX_CCR_EGE_Pos          (9U)
#define DMAMUX_CCR_EGE_Msk          (0x1UL << DMAMUX_CCR_EGE_Pos)   /*!< 0x00000200 */
#define DMAMUX_CCR_EGE              DMAMUX_CCR_EGE_Msk       /*!< </spirit:description> */
#define DMAMUX_CCR_SE_Pos           (16U)
#define DMAMUX_CCR_SE_Msk           (0x1UL << DMAMUX_CCR_SE_Pos)  /*!< 0x00010000 */
#define DMAMUX_CCR_SE               DMAMUX_CCR_SE_Msk        /*!< </spirit:description> */
#define DMAMUX_CCR_SPOL_Pos         (17U)
#define DMAMUX_CCR_SPOL_Msk         (0x3UL << DMAMUX_CCR_SPOL_Pos)    /*!< 0x00060000 */
#define DMAMUX_CCR_SPOL             DMAMUX_CCR_SPOL_Msk      /*!< </spirit:description> */
#define DMAMUX_CCR_SPOL_0           (0x1UL << DMAMUX_CCR_SPOL_Pos)              /*!< 0x00020000 */
#define DMAMUX_CCR_SPOL_1           (0x2UL << DMAMUX_CCR_SPOL_Pos)              /*!< 0x00040000 */
#define DMAMUX_CCR_NBREQ_Pos        (19U)
#define DMAMUX_CCR_NBREQ_Msk        (0x1FUL << DMAMUX_CCR_NBREQ_Pos)      /*!< 0x00F80000 */
#define DMAMUX_CCR_NBREQ            DMAMUX_CCR_NBREQ_Msk     /*!< </spirit:description> */
#define DMAMUX_CCR_NBREQ_0          (0x1UL << DMAMUX_CCR_NBREQ_Pos)               /*!< 0x00080000 */
#define DMAMUX_CCR_NBREQ_1          (0x2UL << DMAMUX_CCR_NBREQ_Pos)                /*!< 0x00100000 */
#define DMAMUX_CCR_NBREQ_2          (0x4UL << DMAMUX_CCR_NBREQ_Pos)                /*!< 0x00200000 */
#define DMAMUX_CCR_NBREQ_3          (0x8UL << DMAMUX_CCR_NBREQ_Pos)                /*!< 0x00400000 */
#define DMAMUX_CCR_NBREQ_4          (0x10UL << DMAMUX_CCR_NBREQ_Pos)                /*!< 0x00800000 */
#define DMAMUX_CCR_SYNC_ID_Pos      (24U)
#define DMAMUX_CCR_SYNC_ID_Msk      (0x1FUL << DMAMUX_CCR_SYNC_ID_Pos)        /*!< 0x1F000000 */
#define DMAMUX_CCR_SYNC_ID          DMAMUX_CCR_SYNC_ID_Msk   /*!< </spirit:description> */
#define DMAMUX_CCR_SYNC_ID_0        (0x1UL << DMAMUX_CCR_SYNC_ID_Pos)                   /*!< 0x01000000 */
#define DMAMUX_CCR_SYNC_ID_1        (0x2UL << DMAMUX_CCR_SYNC_ID_Pos)                   /*!< 0x02000000 */
#define DMAMUX_CCR_SYNC_ID_2        (0x4UL << DMAMUX_CCR_SYNC_ID_Pos)                   /*!< 0x04000000 */
#define DMAMUX_CCR_SYNC_ID_3        (0x8UL << DMAMUX_CCR_SYNC_ID_Pos)                   /*!< 0x08000000 */
#define DMAMUX_CCR_SYNC_ID_4        (0x10UL << DMAMUX_CCR_SYNC_ID_Pos)                    /*!< 0x10000000 */

/***********  Bit definition for DMAMUX_CSR register  ***********/
#define DMAMUX_CSR_SOF0_Pos      (0U)
#define DMAMUX_CSR_SOF0_Msk      (0x1UL << DMAMUX_CSR_SOF0_Pos)       /*!< 0x00000001 */
#define DMAMUX_CSR_SOF0          DMAMUX_CSR_SOF0_Msk   /*!< </spirit:description> */
#define DMAMUX_CSR_SOF1_Pos      (1U)
#define DMAMUX_CSR_SOF1_Msk      (0x1UL << DMAMUX_CSR_SOF1_Pos)       /*!< 0x00000002 */
#define DMAMUX_CSR_SOF1          DMAMUX_CSR_SOF1_Msk   /*!< </spirit:description> */
#define DMAMUX_CSR_SOF2_Pos      (2U)
#define DMAMUX_CSR_SOF2_Msk      (0x1UL << DMAMUX_CSR_SOF2_Pos)       /*!< 0x00000004 */
#define DMAMUX_CSR_SOF2          DMAMUX_CSR_SOF2_Msk   /*!< </spirit:description> */
#define DMAMUX_CSR_SOF3_Pos      (3U)
#define DMAMUX_CSR_SOF3_Msk      (0x1UL << DMAMUX_CSR_SOF3_Pos)       /*!< 0x00000008 */
#define DMAMUX_CSR_SOF3          DMAMUX_CSR_SOF3_Msk   /*!< </spirit:description> */
#define DMAMUX_CSR_SOF4_Pos      (4U)
#define DMAMUX_CSR_SOF4_Msk      (0x1UL << DMAMUX_CSR_SOF4_Pos)       /*!< 0x00000010 */
#define DMAMUX_CSR_SOF4          DMAMUX_CSR_SOF4_Msk   /*!< </spirit:description> */
#define DMAMUX_CSR_SOF5_Pos      (5U)
#define DMAMUX_CSR_SOF5_Msk      (0x1UL << DMAMUX_CSR_SOF5_Pos)       /*!< 0x00000020 */
#define DMAMUX_CSR_SOF5          DMAMUX_CSR_SOF5_Msk   /*!< </spirit:description> */
#define DMAMUX_CSR_SOF6_Pos      (6U)
#define DMAMUX_CSR_SOF6_Msk      (0x1UL << DMAMUX_CSR_SOF6_Pos)       /*!< 0x00000040 */
#define DMAMUX_CSR_SOF6          DMAMUX_CSR_SOF6_Msk   /*!< </spirit:description> */
#define DMAMUX_CSR_SOF7_Pos      (7U)
#define DMAMUX_CSR_SOF7_Msk      (0x1UL << DMAMUX_CSR_SOF7_Pos)       /*!< 0x00000080 */
#define DMAMUX_CSR_SOF7          DMAMUX_CSR_SOF7_Msk   /*!< </spirit:description> */
#define DMAMUX_CSR_SOF8_Pos      (8U)
#define DMAMUX_CSR_SOF8_Msk      (0x1UL << DMAMUX_CSR_SOF8_Pos)       /*!< 0x00000100 */
#define DMAMUX_CSR_SOF8          DMAMUX_CSR_SOF8_Msk   /*!< </spirit:description> */
#define DMAMUX_CSR_SOF9_Pos      (9U)
#define DMAMUX_CSR_SOF9_Msk      (0x1UL << DMAMUX_CSR_SOF9_Pos)       /*!< 0x00000200 */
#define DMAMUX_CSR_SOF9          DMAMUX_CSR_SOF9_Msk   /*!< </spirit:description> */
#define DMAMUX_CSR_SOF10_Pos     (10U)
#define DMAMUX_CSR_SOF10_Msk     (0x1UL << DMAMUX_CSR_SOF10_Pos)        /*!< 0x00000400 */
#define DMAMUX_CSR_SOF10         DMAMUX_CSR_SOF10_Msk  /*!< </spirit:description> */
#define DMAMUX_CSR_SOF11_Pos     (11U)
#define DMAMUX_CSR_SOF11_Msk     (0x1UL << DMAMUX_CSR_SOF11_Pos)        /*!< 0x00000800 */
#define DMAMUX_CSR_SOF11         DMAMUX_CSR_SOF11_Msk  /*!< </spirit:description> */
#define DMAMUX_CSR_SOF12_Pos     (12U)
#define DMAMUX_CSR_SOF12_Msk     (0x1UL << DMAMUX_CSR_SOF12_Pos)        /*!< 0x00001000 */
#define DMAMUX_CSR_SOF12         DMAMUX_CSR_SOF12_Msk  /*!< </spirit:description> */
#define DMAMUX_CSR_SOF13_Pos     (13U)
#define DMAMUX_CSR_SOF13_Msk     (0x1UL << DMAMUX_CSR_SOF13_Pos)        /*!< 0x00002000 */
#define DMAMUX_CSR_SOF13         DMAMUX_CSR_SOF13_Msk  /*!< </spirit:description> */
#define DMAMUX_CSR_SOF14_Pos     (14U)
#define DMAMUX_CSR_SOF14_Msk     (0x1UL << DMAMUX_CSR_SOF14_Pos)        /*!< 0x00004000 */
#define DMAMUX_CSR_SOF14         DMAMUX_CSR_SOF14_Msk  /*!< </spirit:description> */
#define DMAMUX_CSR_SOF15_Pos     (15U)
#define DMAMUX_CSR_SOF15_Msk     (0x1UL << DMAMUX_CSR_SOF15_Pos)        /*!< 0x00008000 */
#define DMAMUX_CSR_SOF15         DMAMUX_CSR_SOF15_Msk  /*!< </spirit:description> */

/***********  Bit definition for DMAMUX_CFR register  ***********/
#define DMAMUX_CFR_CSOF0_Pos     (0U)
#define DMAMUX_CFR_CSOF0_Msk     (0x1UL << DMAMUX_CFR_CSOF0_Pos)        /*!< 0x00000001 */
#define DMAMUX_CFR_CSOF0         DMAMUX_CFR_CSOF0_Msk  /*!< </spirit:description> */
#define DMAMUX_CFR_CSOF1_Pos     (1U)
#define DMAMUX_CFR_CSOF1_Msk     (0x1UL << DMAMUX_CFR_CSOF1_Pos)        /*!< 0x00000002 */
#define DMAMUX_CFR_CSOF1         DMAMUX_CFR_CSOF1_Msk  /*!< </spirit:description> */
#define DMAMUX_CFR_CSOF2_Pos     (2U)
#define DMAMUX_CFR_CSOF2_Msk     (0x1UL << DMAMUX_CFR_CSOF2_Pos)        /*!< 0x00000004 */
#define DMAMUX_CFR_CSOF2         DMAMUX_CFR_CSOF2_Msk  /*!< </spirit:description> */
#define DMAMUX_CFR_CSOF3_Pos     (3U)
#define DMAMUX_CFR_CSOF3_Msk     (0x1UL << DMAMUX_CFR_CSOF3_Pos)        /*!< 0x00000008 */
#define DMAMUX_CFR_CSOF3         DMAMUX_CFR_CSOF3_Msk  /*!< </spirit:description> */
#define DMAMUX_CFR_CSOF4_Pos     (4U)
#define DMAMUX_CFR_CSOF4_Msk     (0x1UL << DMAMUX_CFR_CSOF4_Pos)        /*!< 0x00000010 */
#define DMAMUX_CFR_CSOF4         DMAMUX_CFR_CSOF4_Msk  /*!< </spirit:description> */
#define DMAMUX_CFR_CSOF5_Pos     (5U)
#define DMAMUX_CFR_CSOF5_Msk     (0x1UL << DMAMUX_CFR_CSOF5_Pos)        /*!< 0x00000020 */
#define DMAMUX_CFR_CSOF5         DMAMUX_CFR_CSOF5_Msk  /*!< </spirit:description> */
#define DMAMUX_CFR_CSOF6_Pos     (6U)
#define DMAMUX_CFR_CSOF6_Msk     (0x1UL << DMAMUX_CFR_CSOF6_Pos)        /*!< 0x00000040 */
#define DMAMUX_CFR_CSOF6         DMAMUX_CFR_CSOF6_Msk  /*!< </spirit:description> */
#define DMAMUX_CFR_CSOF7_Pos     (7U)
#define DMAMUX_CFR_CSOF7_Msk     (0x1UL << DMAMUX_CFR_CSOF7_Pos)        /*!< 0x00000080 */
#define DMAMUX_CFR_CSOF7         DMAMUX_CFR_CSOF7_Msk  /*!< </spirit:description> */
#define DMAMUX_CFR_CSOF8_Pos     (8U)
#define DMAMUX_CFR_CSOF8_Msk     (0x1UL << DMAMUX_CFR_CSOF8_Pos)        /*!< 0x00000100 */
#define DMAMUX_CFR_CSOF8         DMAMUX_CFR_CSOF8_Msk  /*!< </spirit:description> */
#define DMAMUX_CFR_CSOF9_Pos     (9U)
#define DMAMUX_CFR_CSOF9_Msk     (0x1UL << DMAMUX_CFR_CSOF9_Pos)        /*!< 0x00000200 */
#define DMAMUX_CFR_CSOF9         DMAMUX_CFR_CSOF9_Msk  /*!< </spirit:description> */
#define DMAMUX_CFR_CSOF10_Pos    (10U)
#define DMAMUX_CFR_CSOF10_Msk    (0x1UL << DMAMUX_CFR_CSOF10_Pos)         /*!< 0x00000400 */
#define DMAMUX_CFR_CSOF10        DMAMUX_CFR_CSOF10_Msk /*!< </spirit:description> */
#define DMAMUX_CFR_CSOF11_Pos    (11U)
#define DMAMUX_CFR_CSOF11_Msk    (0x1UL << DMAMUX_CFR_CSOF11_Pos)         /*!< 0x00000800 */
#define DMAMUX_CFR_CSOF11        DMAMUX_CFR_CSOF11_Msk /*!< </spirit:description> */
#define DMAMUX_CFR_CSOF12_Pos    (12U)
#define DMAMUX_CFR_CSOF12_Msk    (0x1UL << DMAMUX_CFR_CSOF12_Pos)         /*!< 0x00001000 */
#define DMAMUX_CFR_CSOF12        DMAMUX_CFR_CSOF12_Msk /*!< </spirit:description> */
#define DMAMUX_CFR_CSOF13_Pos    (13U)
#define DMAMUX_CFR_CSOF13_Msk    (0x1UL << DMAMUX_CFR_CSOF13_Pos)         /*!< 0x00002000 */
#define DMAMUX_CFR_CSOF13        DMAMUX_CFR_CSOF13_Msk /*!< </spirit:description> */
#define DMAMUX_CFR_CSOF14_Pos    (14U)
#define DMAMUX_CFR_CSOF14_Msk    (0x1UL << DMAMUX_CFR_CSOF14_Pos)         /*!< 0x00004000 */
#define DMAMUX_CFR_CSOF14        DMAMUX_CFR_CSOF14_Msk /*!< </spirit:description> */
#define DMAMUX_CFR_CSOF15_Pos    (15U)
#define DMAMUX_CFR_CSOF15_Msk    (0x1UL << DMAMUX_CFR_CSOF15_Pos)         /*!< 0x00008000 */
#define DMAMUX_CFR_CSOF15        DMAMUX_CFR_CSOF15_Msk /*!< </spirit:description> */


/***********  Bit definition for DMAMUX_RGCR register  ************/
#define DMAMUX_RGCR_SIG_ID_Pos    (0U)
#define DMAMUX_RGCR_SIG_ID_Msk    (0x1FUL << DMAMUX_RGCR_SIG_ID_Pos)          /*!< 0x0000001F */
#define DMAMUX_RGCR_SIG_ID        DMAMUX_RGCR_SIG_ID_Msk /*!< </spirit:description> */
#define DMAMUX_RGCR_SIG_ID_0      (0x1UL << DMAMUX_RGCR_SIG_ID_Pos)               /*!< 0x00000001 */
#define DMAMUX_RGCR_SIG_ID_1      (0x2UL << DMAMUX_RGCR_SIG_ID_Pos)               /*!< 0x00000002 */
#define DMAMUX_RGCR_SIG_ID_2      (0x4UL << DMAMUX_RGCR_SIG_ID_Pos)               /*!< 0x00000004 */
#define DMAMUX_RGCR_SIG_ID_3      (0x8UL << DMAMUX_RGCR_SIG_ID_Pos)               /*!< 0x00000008 */
#define DMAMUX_RGCR_SIG_ID_4      (0x10UL << DMAMUX_RGCR_SIG_ID_Pos)                /*!< 0x00000010 */
#define DMAMUX_RGCR_OIE_Pos       (8U)
#define DMAMUX_RGCR_OIE_Msk       (0x1UL << DMAMUX_RGCR_OIE_Pos)      /*!< 0x00000100 */
#define DMAMUX_RGCR_OIE           DMAMUX_RGCR_OIE_Msk    /*!< </spirit:description> */
#define DMAMUX_RGCR_GE_Pos        (16U)
#define DMAMUX_RGCR_GE_Msk        (0x1UL << DMAMUX_RGCR_GE_Pos)     /*!< 0x00010000 */
#define DMAMUX_RGCR_GE            DMAMUX_RGCR_GE_Msk     /*!< </spirit:description> */
#define DMAMUX_RGCR_GPOL_Pos      (17U)
#define DMAMUX_RGCR_GPOL_Msk      (0x3UL << DMAMUX_RGCR_GPOL_Pos)       /*!< 0x00060000 */
#define DMAMUX_RGCR_GPOL          DMAMUX_RGCR_GPOL_Msk   /*!< </spirit:description> */
#define DMAMUX_RGCR_GPOL_0        (0x1UL << DMAMUX_RGCR_GPOL_Pos)                 /*!< 0x00020000 */
#define DMAMUX_RGCR_GPOL_1        (0x2UL << DMAMUX_RGCR_GPOL_Pos)                 /*!< 0x00040000 */
#define DMAMUX_RGCR_GNBREQ_Pos    (19U)
#define DMAMUX_RGCR_GNBREQ_Msk    (0x1FUL << DMAMUX_RGCR_GNBREQ_Pos)          /*!< 0x00F80000 */
#define DMAMUX_RGCR_GNBREQ        DMAMUX_RGCR_GNBREQ_Msk /*!< </spirit:description> */
#define DMAMUX_RGCR_GNBREQ_0      (0x1UL << DMAMUX_RGCR_GNBREQ_Pos)                   /*!< 0x00080000 */
#define DMAMUX_RGCR_GNBREQ_1     (0x2UL << DMAMUX_RGCR_GNBREQ_Pos)                    /*!< 0x00100000 */
#define DMAMUX_RGCR_GNBREQ_2     (0x4UL << DMAMUX_RGCR_GNBREQ_Pos)                    /*!< 0x00200000 */
#define DMAMUX_RGCR_GNBREQ_3     (0x8UL << DMAMUX_RGCR_GNBREQ_Pos)                    /*!< 0x00400000 */
#define DMAMUX_RGCR_GNBREQ_4     (0x10UL << DMAMUX_RGCR_GNBREQ_Pos)                    /*!< 0x00800000 */

/*********  Bit definition for DMAMUX_RGSR register  *********/
#define DMAMUX_RGSR_OF0_Pos      (0U)
#define DMAMUX_RGSR_OF0_Msk      (0x1UL << DMAMUX_RGSR_OF0_Pos)       /*!< 0x00000001 */
#define DMAMUX_RGSR_OF0          DMAMUX_RGSR_OF0_Msk   /*!< </spirit:description> */
#define DMAMUX_RGSR_OF1_Pos      (1U)
#define DMAMUX_RGSR_OF1_Msk      (0x1UL << DMAMUX_RGSR_OF1_Pos)       /*!< 0x00000002 */
#define DMAMUX_RGSR_OF1          DMAMUX_RGSR_OF1_Msk   /*!< </spirit:description> */
#define DMAMUX_RGSR_OF2_Pos      (2U)
#define DMAMUX_RGSR_OF2_Msk      (0x1UL << DMAMUX_RGSR_OF2_Pos)       /*!< 0x00000004 */
#define DMAMUX_RGSR_OF2          DMAMUX_RGSR_OF2_Msk   /*!< </spirit:description> */
#define DMAMUX_RGSR_OF3_Pos      (3U)
#define DMAMUX_RGSR_OF3_Msk      (0x1UL << DMAMUX_RGSR_OF3_Pos)       /*!< 0x00000008 */
#define DMAMUX_RGSR_OF3          DMAMUX_RGSR_OF3_Msk   /*!< </spirit:description> */

/********  Bit definition for DMAMUX_RGCFR register  *********/
#define DMAMUX_RGCFR_COF0_Pos    (0U)
#define DMAMUX_RGCFR_COF0_Msk    (0x1UL << DMAMUX_RGCFR_COF0_Pos)         /*!< 0x00000001 */
#define DMAMUX_RGCFR_COF0        DMAMUX_RGCFR_COF0_Msk /*!< </spirit:description> */
#define DMAMUX_RGCFR_COF1_Pos    (1U)
#define DMAMUX_RGCFR_COF1_Msk    (0x1UL << DMAMUX_RGCFR_COF1_Pos)         /*!< 0x00000002 */
#define DMAMUX_RGCFR_COF1        DMAMUX_RGCFR_COF1_Msk /*!< </spirit:description> */
#define DMAMUX_RGCFR_COF2_Pos    (2U)
#define DMAMUX_RGCFR_COF2_Msk    (0x1UL << DMAMUX_RGCFR_COF2_Pos)         /*!< 0x00000004 */
#define DMAMUX_RGCFR_COF2        DMAMUX_RGCFR_COF2_Msk /*!< </spirit:description> */
#define DMAMUX_RGCFR_COF3_Pos    (3U)
#define DMAMUX_RGCFR_COF3_Msk    (0x1UL << DMAMUX_RGCFR_COF3_Pos)         /*!< 0x00000008 */
#define DMAMUX_RGCFR_COF3        DMAMUX_RGCFR_COF3_Msk /*!< </spirit:description> */

#define DMAMUX1_Channel0_BASE           0x48004400UL 
#define DMAMUX1_Channel1_BASE           0x48004404UL 
#define DMAMUX1_Channel2_BASE           0x48004408UL 
#define DMAMUX1_Channel3_BASE           0x4800440CUL 
#define DMAMUX1_Channel4_BASE           0x48004410UL 
#define DMAMUX1_Channel5_BASE           0x48004414UL 
#define DMAMUX1_Channel6_BASE           0x48004418UL 
#define DMAMUX1_Channel7_BASE           0x4800441CUL 
#define DMAMUX1_Channel8_BASE           0x48004420UL 
#define DMAMUX1_Channel9_BASE           0x48004424UL 
#define DMAMUX1_Channel10_BASE          0x48004428UL 
#define DMAMUX1_Channel11_BASE          0x4800442CUL 
#define DMAMUX1_Channel12_BASE          0x48004430UL 
#define DMAMUX1_Channel13_BASE          0x48004434UL 
#define DMAMUX1_Channel14_BASE          0x48004438UL 
#define DMAMUX1_Channel15_BASE          0x4800443CUL 
#define DMAMUX1_ChannelStatus_BASE      0x48004480UL 
#define DMAMUX1_RequestGen0_BASE        0x48004500UL 
#define DMAMUX1_RequestGen1_BASE        0x48004504UL 
#define DMAMUX1_RequestGen2_BASE        0x48004508UL 
#define DMAMUX1_RequestGen3_BASE        0x4800450CUL 
#define DMAMUX1_RequestGenStatus_BASE   0x48004540UL 


#define DMAMUX1_Channel0                ((DMAMUX_Channel_TypeDef *) DMAMUX1_Channel0_BASE) 
#define DMAMUX1_Channel1                ((DMAMUX_Channel_TypeDef *) DMAMUX1_Channel1_BASE) 
#define DMAMUX1_Channel2                ((DMAMUX_Channel_TypeDef *) DMAMUX1_Channel2_BASE) 
#define DMAMUX1_Channel3                ((DMAMUX_Channel_TypeDef *) DMAMUX1_Channel3_BASE) 
#define DMAMUX1_Channel4                ((DMAMUX_Channel_TypeDef *) DMAMUX1_Channel4_BASE) 
#define DMAMUX1_Channel5                ((DMAMUX_Channel_TypeDef *) DMAMUX1_Channel5_BASE) 
#define DMAMUX1_Channel6                ((DMAMUX_Channel_TypeDef *) DMAMUX1_Channel6_BASE) 
#define DMAMUX1_Channel7                ((DMAMUX_Channel_TypeDef *) DMAMUX1_Channel7_BASE) 
#define DMAMUX1_Channel8                ((DMAMUX_Channel_TypeDef *) DMAMUX1_Channel8_BASE) 
#define DMAMUX1_Channel9                ((DMAMUX_Channel_TypeDef *) DMAMUX1_Channel9_BASE) 
#define DMAMUX1_Channel10               ((DMAMUX_Channel_TypeDef *) DMAMUX1_Channel10_BASE) 
#define DMAMUX1_Channel11               ((DMAMUX_Channel_TypeDef *) DMAMUX1_Channel11_BASE) 
#define DMAMUX1_Channel12               ((DMAMUX_Channel_TypeDef *) DMAMUX1_Channel12_BASE) 
#define DMAMUX1_Channel13               ((DMAMUX_Channel_TypeDef *) DMAMUX1_Channel13_BASE) 
#define DMAMUX1_Channel14               ((DMAMUX_Channel_TypeDef *) DMAMUX1_Channel14_BASE) 
#define DMAMUX1_Channel15               ((DMAMUX_Channel_TypeDef *) DMAMUX1_Channel15_BASE) 
#define DMAMUX1_ChannelStatus           ((DMAMUX_ChannelStatus_TypeDef *) DMAMUX1_ChannelStatus_BASE) 
#define DMAMUX1_RequestGen0             ((DMAMUX_RequestGen_TypeDef *) DMAMUX1_RequestGen0_BASE) 
#define DMAMUX1_RequestGen1             ((DMAMUX_RequestGen_TypeDef *) DMAMUX1_RequestGen1_BASE) 
#define DMAMUX1_RequestGen2             ((DMAMUX_RequestGen_TypeDef *) DMAMUX1_RequestGen2_BASE) 
#define DMAMUX1_RequestGen3             ((DMAMUX_RequestGen_TypeDef *) DMAMUX1_RequestGen3_BASE) 
#define DMAMUX1_RequestGenStatus        ((DMAMUX_RequestGenStatus_TypeDef *) DMAMUX1_RequestGenStatus_BASE) 

#define DMAMUX1_BASE           DMAMUX1_Channel0_BASE 


#define DMAMUX1                ((DMAMUX_Channel_TypeDef *) DMAMUX1_BASE)

#endif /* __SR5E1_DMAMUX1_H */

