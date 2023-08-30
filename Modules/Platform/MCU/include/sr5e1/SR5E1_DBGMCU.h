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

#ifndef __SR5E1_DBGMCU_H
#define __SR5E1_DBGMCU_H

/*******************************************************************************
 * REVISION HISTORY                                                            *
 * REV       DATE       RM REV          DESCRIPTION OF CHANGE                  *
 * ------ ----------- ------------ --------------------------------------------*
 * 1.0C2  22-Mar-2022 Rev 1 Draft C     SR5E1_RDP_0_1_Rev1_C_18FEB22           *
 *                                      Fixed bitOffset for HRTIMER2_FRZ fields*
 *                                      Fixed register offsets for all register*
 * ------ ----------- ------------ --------------------------------------------*
 * 1.0C1  09-Mar-2022 Rev 1 Draft C     SR5E1_RDP_0_1_Rev1_C_18FEB22           *
 *                                      Changed access rights, added DIN_REG   *
 *                                      field                                  *
 ******************************************************************************/


/******************************************************************************/
/*                                                                            */
/*                              DBGMCU (DBGMCU)                               */
/*                                                                            */
/******************************************************************************/
typedef struct
{
  __IO uint32_t APB1_C1_FZ_REG;  /*!< APB1_C1_FZ_REG Address offset: 0x000 */
  __IO uint32_t APB2_C1_FZ_REG;  /*!< APB2_C1_FZ_REG Address offset: 0x004 */
  __IO uint32_t AXI_C1_FZ_REG;   /*!< AXI_C1_FZ_REG  Address offset: 0x008 */
       uint32_t RESERVED0;       /*!< Reserved       Address offset: 0x00C */
  __IO uint32_t APB1_C2_FZ_REG;  /*!< APB1_C2_FZ_REG Address offset: 0x010 */
  __IO uint32_t APB2_C2_FZ_REG;  /*!< APB2_C2_FZ_REG Address offset: 0x014 */
  __IO uint32_t AXI_C2_FZ_REG;   /*!< AXI_C2_FZ_REG  Address offset: 0x018 */
       uint32_t RESERVED1;       /*!< Reserved       Address offset: 0x01C */
  __IO uint32_t DBG_RST_REG;     /*!< DBG_RST_REG    Address offset: 0x020 */
  __IO uint32_t DOUT_REG;        /*!< DOUT_REG       Address offset: 0x024 */
  __IO uint32_t DIN_REG;         /*!< DIN_REG        Address offset: 0x028 */
  __IO uint32_t DMCR;            /*!< DMCR           Address offset: 0x02C */
  __IO uint32_t DMSR;            /*!< DMSR           Address offset: 0x030 */
       uint32_t RESERVED2[3];    /*!< Reserved       Address offset: 0x034-0x03C */
  __IO uint32_t CTI_TRG_SEL;     /*!< CTI_TRG_SEL    Address offset: 0x040 */
  __IO uint32_t DBG_SLEEP_CFG;   /*!< DBG_SLEEP_CFG  Address offset: 0x044 */
       uint32_t RESERVED3[989];  /*!< Reserved       Address offset: 0x048-0xFB8 */
  __I  uint32_t DEVARCH;         /*!< DEVARCH        Address offset: 0xFBC */
       uint32_t RESERVED4[3];    /*!< Reserved       Address offset: 0xFC0-0xFC8 */
  __I  uint32_t DEVTYPE;         /*!< DEVTYPE        Address offset: 0x0FD0 */
  __I  uint32_t PIDR4;           /*!< PIDR4          Address offset: 0xFD0 */
  __I  uint32_t PIDR5;           /*!< PIDR5          Address offset: 0xFD4 */
  __I  uint32_t PIDR6;           /*!< PIDR6          Address offset: 0xFD8 */
  __I  uint32_t PIDR7;           /*!< PIDR7          Address offset: 0xFDC */
  __I  uint32_t PIDR0;           /*!< PIDR0          Address offset: 0xFE0 */
  __I  uint32_t PIDR1;           /*!< PIDR1          Address offset: 0xFE4 */
  __I  uint32_t PIDR2;           /*!< PIDR2          Address offset: 0xFE8 */
  __I  uint32_t PIDR3;           /*!< PIDR3          Address offset: 0xFEC */
  __I  uint32_t CIDR0;           /*!< CIDR0          Address offset: 0xFF0 */
  __I  uint32_t CIDR1;           /*!< CIDR1          Address offset: 0xFF4 */
  __I  uint32_t CIDR2;           /*!< CIDR2          Address offset: 0xFF8 */
  __I  uint32_t CIDR3;           /*!< CIDR3          Address offset: 0xFFC */
} DBGMCU_TypeDef;


/************  Bit definition for DBGMCU_APB1_C1_FZ_REG register  *************/
#define DBGMCU_APB1_C1_FZ_REG_WWDG1_FRZ_Pos         (0U)
#define DBGMCU_APB1_C1_FZ_REG_WWDG1_FRZ_Msk         (0x1UL << DBGMCU_APB1_C1_FZ_REG_WWDG1_FRZ_Pos)  /*!< 0x00000001 */
#define DBGMCU_APB1_C1_FZ_REG_WWDG1_FRZ              DBGMCU_APB1_C1_FZ_REG_WWDG1_FRZ_Msk            /*!< WWDG1_FRZ */
#define DBGMCU_APB1_C1_FZ_REG_WWDG2_FRZ_Pos         (1U)
#define DBGMCU_APB1_C1_FZ_REG_WWDG2_FRZ_Msk         (0x1UL << DBGMCU_APB1_C1_FZ_REG_WWDG2_FRZ_Pos)  /*!< 0x00000002 */
#define DBGMCU_APB1_C1_FZ_REG_WWDG2_FRZ              DBGMCU_APB1_C1_FZ_REG_WWDG2_FRZ_Msk            /*!< WWDG2_FRZ */
#define DBGMCU_APB1_C1_FZ_REG_IWDG1_FRZ_Pos         (4U)
#define DBGMCU_APB1_C1_FZ_REG_IWDG1_FRZ_Msk         (0x1UL << DBGMCU_APB1_C1_FZ_REG_IWDG1_FRZ_Pos)  /*!< 0x00000010 */
#define DBGMCU_APB1_C1_FZ_REG_IWDG1_FRZ              DBGMCU_APB1_C1_FZ_REG_IWDG1_FRZ_Msk            /*!< IWDG1_FRZ */
#define DBGMCU_APB1_C1_FZ_REG_IWDG2_FRZ_Pos         (5U)
#define DBGMCU_APB1_C1_FZ_REG_IWDG2_FRZ_Msk         (0x1UL << DBGMCU_APB1_C1_FZ_REG_IWDG2_FRZ_Pos)  /*!< 0x00000020 */
#define DBGMCU_APB1_C1_FZ_REG_IWDG2_FRZ              DBGMCU_APB1_C1_FZ_REG_IWDG2_FRZ_Msk            /*!< IWDG2_FRZ */
#define DBGMCU_APB1_C1_FZ_REG_RTC_FRZ_Pos           (10U)
#define DBGMCU_APB1_C1_FZ_REG_RTC_FRZ_Msk           (0x1UL << DBGMCU_APB1_C1_FZ_REG_RTC_FRZ_Pos)    /*!< 0x00000400 */
#define DBGMCU_APB1_C1_FZ_REG_RTC_FRZ                DBGMCU_APB1_C1_FZ_REG_RTC_FRZ_Msk              /*!< RTC_FRZ */
#define DBGMCU_APB1_C1_FZ_REG_TIM2_FRZ_Pos          (15U)
#define DBGMCU_APB1_C1_FZ_REG_TIM2_FRZ_Msk          (0x1UL << DBGMCU_APB1_C1_FZ_REG_TIM2_FRZ_Pos)   /*!< 0x00008000 */
#define DBGMCU_APB1_C1_FZ_REG_TIM2_FRZ               DBGMCU_APB1_C1_FZ_REG_TIM2_FRZ_Msk             /*!< TIM2_FRZ */
#define DBGMCU_APB1_C1_FZ_REG_TIM3_FRZ_Pos          (16U)
#define DBGMCU_APB1_C1_FZ_REG_TIM3_FRZ_Msk          (0x1UL << DBGMCU_APB1_C1_FZ_REG_TIM3_FRZ_Pos)   /*!< 0x00010000 */
#define DBGMCU_APB1_C1_FZ_REG_TIM3_FRZ               DBGMCU_APB1_C1_FZ_REG_TIM3_FRZ_Msk             /*!< TIM3_FRZ */
#define DBGMCU_APB1_C1_FZ_REG_TIM6_FRZ_Pos          (17U)
#define DBGMCU_APB1_C1_FZ_REG_TIM6_FRZ_Msk          (0x1UL << DBGMCU_APB1_C1_FZ_REG_TIM6_FRZ_Pos)   /*!< 0x00020000 */
#define DBGMCU_APB1_C1_FZ_REG_TIM6_FRZ               DBGMCU_APB1_C1_FZ_REG_TIM6_FRZ_Msk             /*!< TIM6_FRZ */
#define DBGMCU_APB1_C1_FZ_REG_TIM7_FRZ_Pos          (18U)
#define DBGMCU_APB1_C1_FZ_REG_TIM7_FRZ_Msk          (0x1UL << DBGMCU_APB1_C1_FZ_REG_TIM7_FRZ_Pos)   /*!< 0x00040000 */
#define DBGMCU_APB1_C1_FZ_REG_TIM7_FRZ               DBGMCU_APB1_C1_FZ_REG_TIM7_FRZ_Msk             /*!< TIM7_FRZ */
#define DBGMCU_APB1_C1_FZ_REG_TIM_TS_FRZ_Pos        (19U)
#define DBGMCU_APB1_C1_FZ_REG_TIM_TS_FRZ_Msk        (0x1UL << DBGMCU_APB1_C1_FZ_REG_TIM_TS_FRZ_Pos) /*!< 0x00080000 */
#define DBGMCU_APB1_C1_FZ_REG_TIM_TS_FRZ             DBGMCU_APB1_C1_FZ_REG_TIM_TS_FRZ_Msk           /*!< TIM_TS_FRZ */
#define DBGMCU_APB1_C1_FZ_REG_I2C1_FRZ_Pos          (21U)
#define DBGMCU_APB1_C1_FZ_REG_I2C1_FRZ_Msk          (0x1UL << DBGMCU_APB1_C1_FZ_REG_I2C1_FRZ_Pos)   /*!< 0x00200000 */
#define DBGMCU_APB1_C1_FZ_REG_I2C1_FRZ               DBGMCU_APB1_C1_FZ_REG_I2C1_FRZ_Msk             /*!< I2C1_FRZ */
#define DBGMCU_APB1_C1_FZ_REG_I2C2_FRZ_Pos          (22U)
#define DBGMCU_APB1_C1_FZ_REG_I2C2_FRZ_Msk          (0x1UL << DBGMCU_APB1_C1_FZ_REG_I2C2_FRZ_Pos)   /*!< 0x00400000 */
#define DBGMCU_APB1_C1_FZ_REG_I2C2_FRZ               DBGMCU_APB1_C1_FZ_REG_I2C2_FRZ_Msk             /*!< I2C2_FRZ */
#define DBGMCU_APB1_C1_FZ_REG_FCCU_DBG_Pos          (31U)
#define DBGMCU_APB1_C1_FZ_REG_FCCU_DBG_Msk          (0x1UL << DBGMCU_APB1_C1_FZ_REG_FCCU_DBG_Pos)   /*!< 0x80000000 */
#define DBGMCU_APB1_C1_FZ_REG_FCCU_DBG               DBGMCU_APB1_C1_FZ_REG_FCCU_DBG_Msk             /*!< FCCU_DBG */

/************  Bit definition for DBGMCU_APB2_C1_FZ_REG register  *************/
#define DBGMCU_APB2_C1_FZ_REG_TSU_CAN1_DIS_MORD_Pos (0U)
#define DBGMCU_APB2_C1_FZ_REG_TSU_CAN1_DIS_MORD_Msk (0x1UL << DBGMCU_APB2_C1_FZ_REG_TSU_CAN1_DIS_MORD_Pos)      /*!< 0x00000001 */
#define DBGMCU_APB2_C1_FZ_REG_TSU_CAN1_DIS_MORD      DBGMCU_APB2_C1_FZ_REG_TSU_CAN1_DIS_MORD_Msk    /*!< TSU_CAN1_DIS_MORD */
#define DBGMCU_APB2_C1_FZ_REG_TSU_CAN2_DIS_MORD_Pos (1U)
#define DBGMCU_APB2_C1_FZ_REG_TSU_CAN2_DIS_MORD_Msk (0x1UL << DBGMCU_APB2_C1_FZ_REG_TSU_CAN2_DIS_MORD_Pos)      /*!< 0x00000002 */
#define DBGMCU_APB2_C1_FZ_REG_TSU_CAN2_DIS_MORD      DBGMCU_APB2_C1_FZ_REG_TSU_CAN2_DIS_MORD_Msk    /*!< TSU_CAN2_DIS_MORD */
#define DBGMCU_APB2_C1_FZ_REG_TSU_CAN3_DIS_MORD_Pos (2U)
#define DBGMCU_APB2_C1_FZ_REG_TSU_CAN3_DIS_MORD_Msk (0x1UL << DBGMCU_APB2_C1_FZ_REG_TSU_CAN3_DIS_MORD_Pos)      /*!< 0x00000004 */
#define DBGMCU_APB2_C1_FZ_REG_TSU_CAN3_DIS_MORD      DBGMCU_APB2_C1_FZ_REG_TSU_CAN3_DIS_MORD_Msk    /*!< TSU_CAN3_DIS_MORD */
#define DBGMCU_APB2_C1_FZ_REG_TSU_CAN4_DIS_MORD_Pos (3U)
#define DBGMCU_APB2_C1_FZ_REG_TSU_CAN4_DIS_MORD_Msk (0x1UL << DBGMCU_APB2_C1_FZ_REG_TSU_CAN4_DIS_MORD_Pos)      /*!< 0x00000008 */
#define DBGMCU_APB2_C1_FZ_REG_TSU_CAN4_DIS_MORD      DBGMCU_APB2_C1_FZ_REG_TSU_CAN4_DIS_MORD_Msk    /*!< TSU_CAN4_DIS_MORD */
#define DBGMCU_APB2_C1_FZ_REG_TIM1_PWM_FRZ_Pos      (11U)
#define DBGMCU_APB2_C1_FZ_REG_TIM1_PWM_FRZ_Msk      (0x1UL << DBGMCU_APB2_C1_FZ_REG_TIM1_PWM_FRZ_Pos) /*!< 0x00000800 */
#define DBGMCU_APB2_C1_FZ_REG_TIM1_PWM_FRZ           DBGMCU_APB2_C1_FZ_REG_TIM1_PWM_FRZ_Msk         /*!< TIM1_PWM_FRZ */
#define DBGMCU_APB2_C1_FZ_REG_TIM8_PWM_FRZ_Pos      (12U)
#define DBGMCU_APB2_C1_FZ_REG_TIM8_PWM_FRZ_Msk      (0x1UL << DBGMCU_APB2_C1_FZ_REG_TIM8_PWM_FRZ_Pos) /*!< 0x00001000 */
#define DBGMCU_APB2_C1_FZ_REG_TIM8_PWM_FRZ           DBGMCU_APB2_C1_FZ_REG_TIM8_PWM_FRZ_Msk         /*!< TIM8_PWM_FRZ */
#define DBGMCU_APB2_C1_FZ_REG_TIM4_PWM_FRZ_Pos      (15U)
#define DBGMCU_APB2_C1_FZ_REG_TIM4_PWM_FRZ_Msk      (0x1UL << DBGMCU_APB2_C1_FZ_REG_TIM4_PWM_FRZ_Pos) /*!< 0x00008000 */
#define DBGMCU_APB2_C1_FZ_REG_TIM4_PWM_FRZ           DBGMCU_APB2_C1_FZ_REG_TIM4_PWM_FRZ_Msk         /*!< TIM4_PWM_FRZ */
#define DBGMCU_APB2_C1_FZ_REG_TIM5_PWM_FRZ_Pos      (16U)
#define DBGMCU_APB2_C1_FZ_REG_TIM5_PWM_FRZ_Msk      (0x1UL << DBGMCU_APB2_C1_FZ_REG_TIM5_PWM_FRZ_Pos) /*!< 0x00010000 */
#define DBGMCU_APB2_C1_FZ_REG_TIM5_PWM_FRZ           DBGMCU_APB2_C1_FZ_REG_TIM5_PWM_FRZ_Msk         /*!< TIM5_PWM_FRZ */
#define DBGMCU_APB2_C1_FZ_REG_TIM15_PWM_FRZ_Pos     (17U)
#define DBGMCU_APB2_C1_FZ_REG_TIM15_PWM_FRZ_Msk     (0x1UL << DBGMCU_APB2_C1_FZ_REG_TIM15_PWM_FRZ_Pos)  /*!< 0x00020000 */
#define DBGMCU_APB2_C1_FZ_REG_TIM15_PWM_FRZ          DBGMCU_APB2_C1_FZ_REG_TIM15_PWM_FRZ_Msk        /*!< TIM15_PWM_FRZ */
#define DBGMCU_APB2_C1_FZ_REG_TIM16_PWM_FRZ_Pos     (18U)
#define DBGMCU_APB2_C1_FZ_REG_TIM16_PWM_FRZ_Msk     (0x1UL << DBGMCU_APB2_C1_FZ_REG_TIM16_PWM_FRZ_Pos)  /*!< 0x00040000 */
#define DBGMCU_APB2_C1_FZ_REG_TIM16_PWM_FRZ          DBGMCU_APB2_C1_FZ_REG_TIM16_PWM_FRZ_Msk        /*!< TIM16_PWM_FRZ */
#define DBGMCU_APB2_C1_FZ_REG_SDADC1_DBG_FRZ_Pos    (24U)
#define DBGMCU_APB2_C1_FZ_REG_SDADC1_DBG_FRZ_Msk    (0x1UL << DBGMCU_APB2_C1_FZ_REG_SDADC1_DBG_FRZ_Pos)   /*!< 0x01000000 */
#define DBGMCU_APB2_C1_FZ_REG_SDADC1_DBG_FRZ         DBGMCU_APB2_C1_FZ_REG_SDADC1_DBG_FRZ_Msk       /*!< SDADC1_DBG_FRZ */
#define DBGMCU_APB2_C1_FZ_REG_SDADC2_DBG_FRZ_Pos    (25U)
#define DBGMCU_APB2_C1_FZ_REG_SDADC2_DBG_FRZ_Msk    (0x1UL << DBGMCU_APB2_C1_FZ_REG_SDADC2_DBG_FRZ_Pos)   /*!< 0x02000000 */
#define DBGMCU_APB2_C1_FZ_REG_SDADC2_DBG_FRZ         DBGMCU_APB2_C1_FZ_REG_SDADC2_DBG_FRZ_Msk       /*!< SDADC2_DBG_FRZ */
#define DBGMCU_APB2_C1_FZ_REG_FDCAN1_DIS_MORD_Pos   (28U)
#define DBGMCU_APB2_C1_FZ_REG_FDCAN1_DIS_MORD_Msk   (0x1UL << DBGMCU_APB2_C1_FZ_REG_FDCAN1_DIS_MORD_Pos)    /*!< 0x10000000 */
#define DBGMCU_APB2_C1_FZ_REG_FDCAN1_DIS_MORD        DBGMCU_APB2_C1_FZ_REG_FDCAN1_DIS_MORD_Msk      /*!< FDCAN1_DIS_MORD */
#define DBGMCU_APB2_C1_FZ_REG_FDCAN2_DIS_MORD_Pos   (29U)
#define DBGMCU_APB2_C1_FZ_REG_FDCAN2_DIS_MORD_Msk   (0x1UL << DBGMCU_APB2_C1_FZ_REG_FDCAN2_DIS_MORD_Pos)    /*!< 0x20000000 */
#define DBGMCU_APB2_C1_FZ_REG_FDCAN2_DIS_MORD        DBGMCU_APB2_C1_FZ_REG_FDCAN2_DIS_MORD_Msk      /*!< FDCAN2_DIS_MORD */
#define DBGMCU_APB2_C1_FZ_REG_FDCAN3_DIS_MORD_Pos   (30U)
#define DBGMCU_APB2_C1_FZ_REG_FDCAN3_DIS_MORD_Msk   (0x1UL << DBGMCU_APB2_C1_FZ_REG_FDCAN3_DIS_MORD_Pos)    /*!< 0x40000000 */
#define DBGMCU_APB2_C1_FZ_REG_FDCAN3_DIS_MORD        DBGMCU_APB2_C1_FZ_REG_FDCAN3_DIS_MORD_Msk      /*!< FDCAN3_DIS_MORD */
#define DBGMCU_APB2_C1_FZ_REG_FDCAN4_DIS_MORD_Pos   (31U)
#define DBGMCU_APB2_C1_FZ_REG_FDCAN4_DIS_MORD_Msk   (0x1UL << DBGMCU_APB2_C1_FZ_REG_FDCAN4_DIS_MORD_Pos)    /*!< 0x80000000 */
#define DBGMCU_APB2_C1_FZ_REG_FDCAN4_DIS_MORD        DBGMCU_APB2_C1_FZ_REG_FDCAN4_DIS_MORD_Msk      /*!< FDCAN4_DIS_MORD */

/*************  Bit definition for DBGMCU_AXI_C1_FZ_REG register  *************/
#define DBGMCU_AXI_C1_FZ_REG_HRTIMER1_FRZ_Pos       (0U)
#define DBGMCU_AXI_C1_FZ_REG_HRTIMER1_FRZ_Msk        (0x1UL << DBGMCU_AXI_C1_FZ_REG_HRTIMER1_FRZ_Pos) /*!< 0x00000001 */
#define DBGMCU_AXI_C1_FZ_REG_HRTIMER1_FRZ            DBGMCU_AXI_C1_FZ_REG_HRTIMER1_FRZ_Msk          /*!< HRTIMER1_FRZ */
#define DBGMCU_AXI_C1_FZ_REG_HRTIMER2_FRZ_Pos        (1U)
#define DBGMCU_AXI_C1_FZ_REG_HRTIMER2_FRZ_Msk        (0x1UL << DBGMCU_AXI_C1_FZ_REG_HRTIMER2_FRZ_Pos) /*!< 0x00000002 */
#define DBGMCU_AXI_C1_FZ_REG_HRTIMER2_FRZ            DBGMCU_AXI_C1_FZ_REG_HRTIMER2_FRZ_Msk          /*!< HRTIMER2_FRZ */

/************  Bit definition for DBGMCU_APB1_C2_FZ_REG register  *************/
#define DBGMCU_APB1_C2_FZ_REG_WWDG1_FRZ_Pos         (0U)
#define DBGMCU_APB1_C2_FZ_REG_WWDG1_FRZ_Msk         (0x1UL << DBGMCU_APB1_C2_FZ_REG_WWDG1_FRZ_Pos)  /*!< 0x00000001 */
#define DBGMCU_APB1_C2_FZ_REG_WWDG1_FRZ              DBGMCU_APB1_C2_FZ_REG_WWDG1_FRZ_Msk            /*!< WWDG1_FRZ */
#define DBGMCU_APB1_C2_FZ_REG_WWDG2_FRZ_Pos         (1U)
#define DBGMCU_APB1_C2_FZ_REG_WWDG2_FRZ_Msk         (0x1UL << DBGMCU_APB1_C2_FZ_REG_WWDG2_FRZ_Pos)  /*!< 0x00000002 */
#define DBGMCU_APB1_C2_FZ_REG_WWDG2_FRZ              DBGMCU_APB1_C2_FZ_REG_WWDG2_FRZ_Msk            /*!< WWDG2_FRZ */
#define DBGMCU_APB1_C2_FZ_REG_IWDG1_FRZ_Pos         (4U)
#define DBGMCU_APB1_C2_FZ_REG_IWDG1_FRZ_Msk         (0x1UL << DBGMCU_APB1_C2_FZ_REG_IWDG1_FRZ_Pos)  /*!< 0x00000010 */
#define DBGMCU_APB1_C2_FZ_REG_IWDG1_FRZ              DBGMCU_APB1_C2_FZ_REG_IWDG1_FRZ_Msk            /*!< IWDG1_FRZ */
#define DBGMCU_APB1_C2_FZ_REG_IWDG2_FRZ_Pos         (5U)
#define DBGMCU_APB1_C2_FZ_REG_IWDG2_FRZ_Msk         (0x1UL << DBGMCU_APB1_C2_FZ_REG_IWDG2_FRZ_Pos)  /*!< 0x00000020 */
#define DBGMCU_APB1_C2_FZ_REG_IWDG2_FRZ              DBGMCU_APB1_C2_FZ_REG_IWDG2_FRZ_Msk            /*!< IWDG2_FRZ */
#define DBGMCU_APB1_C2_FZ_REG_RTC_FRZ_Pos           (10U)
#define DBGMCU_APB1_C2_FZ_REG_RTC_FRZ_Msk           (0x1UL << DBGMCU_APB1_C2_FZ_REG_RTC_FRZ_Pos)    /*!< 0x00000400 */
#define DBGMCU_APB1_C2_FZ_REG_RTC_FRZ                DBGMCU_APB1_C2_FZ_REG_RTC_FRZ_Msk              /*!< RTC_FRZ */
#define DBGMCU_APB1_C2_FZ_REG_TIM2_FRZ_Pos          (15U)
#define DBGMCU_APB1_C2_FZ_REG_TIM2_FRZ_Msk          (0x1UL << DBGMCU_APB1_C2_FZ_REG_TIM2_FRZ_Pos)   /*!< 0x00008000 */
#define DBGMCU_APB1_C2_FZ_REG_TIM2_FRZ               DBGMCU_APB1_C2_FZ_REG_TIM2_FRZ_Msk             /*!< TIM2_FRZ */
#define DBGMCU_APB1_C2_FZ_REG_TIM3_FRZ_Pos          (16U)
#define DBGMCU_APB1_C2_FZ_REG_TIM3_FRZ_Msk          (0x1UL << DBGMCU_APB1_C2_FZ_REG_TIM3_FRZ_Pos)   /*!< 0x00010000 */
#define DBGMCU_APB1_C2_FZ_REG_TIM3_FRZ               DBGMCU_APB1_C2_FZ_REG_TIM3_FRZ_Msk             /*!< TIM3_FRZ */
#define DBGMCU_APB1_C2_FZ_REG_TIM6_FRZ_Pos          (17U)
#define DBGMCU_APB1_C2_FZ_REG_TIM6_FRZ_Msk          (0x1UL << DBGMCU_APB1_C2_FZ_REG_TIM6_FRZ_Pos)   /*!< 0x00020000 */
#define DBGMCU_APB1_C2_FZ_REG_TIM6_FRZ               DBGMCU_APB1_C2_FZ_REG_TIM6_FRZ_Msk             /*!< TIM6_FRZ */
#define DBGMCU_APB1_C2_FZ_REG_TIM7_FRZ_Pos          (18U)
#define DBGMCU_APB1_C2_FZ_REG_TIM7_FRZ_Msk          (0x1UL << DBGMCU_APB1_C2_FZ_REG_TIM7_FRZ_Pos)   /*!< 0x00040000 */
#define DBGMCU_APB1_C2_FZ_REG_TIM7_FRZ               DBGMCU_APB1_C2_FZ_REG_TIM7_FRZ_Msk             /*!< TIM7_FRZ */
#define DBGMCU_APB1_C2_FZ_REG_TIM_TS_FRZ_Pos        (19U)
#define DBGMCU_APB1_C2_FZ_REG_TIM_TS_FRZ_Msk        (0x1UL << DBGMCU_APB1_C2_FZ_REG_TIM_TS_FRZ_Pos) /*!< 0x00080000 */
#define DBGMCU_APB1_C2_FZ_REG_TIM_TS_FRZ             DBGMCU_APB1_C2_FZ_REG_TIM_TS_FRZ_Msk           /*!< TIM_TS_FRZ */
#define DBGMCU_APB1_C2_FZ_REG_I2C1_FRZ_Pos          (21U)
#define DBGMCU_APB1_C2_FZ_REG_I2C1_FRZ_Msk          (0x1UL << DBGMCU_APB1_C2_FZ_REG_I2C1_FRZ_Pos)   /*!< 0x00200000 */
#define DBGMCU_APB1_C2_FZ_REG_I2C1_FRZ               DBGMCU_APB1_C2_FZ_REG_I2C1_FRZ_Msk             /*!< I2C1_FRZ */
#define DBGMCU_APB1_C2_FZ_REG_I2C2_FRZ_Pos          (22U)
#define DBGMCU_APB1_C2_FZ_REG_I2C2_FRZ_Msk          (0x1UL << DBGMCU_APB1_C2_FZ_REG_I2C2_FRZ_Pos)   /*!< 0x00400000 */
#define DBGMCU_APB1_C2_FZ_REG_I2C2_FRZ               DBGMCU_APB1_C2_FZ_REG_I2C2_FRZ_Msk             /*!< I2C2_FRZ */
#define DBGMCU_APB1_C2_FZ_REG_FCCU_DBG_Pos          (31U)
#define DBGMCU_APB1_C2_FZ_REG_FCCU_DBG_Msk          (0x1UL << DBGMCU_APB1_C2_FZ_REG_FCCU_DBG_Pos)   /*!< 0x80000000 */
#define DBGMCU_APB1_C2_FZ_REG_FCCU_DBG               DBGMCU_APB1_C2_FZ_REG_FCCU_DBG_Msk             /*!< FCCU_DBG */

/************  Bit definition for DBGMCU_APB2_C2_FZ_REG register  *************/
#define DBGMCU_APB2_C2_FZ_REG_TSU_CAN1_DIS_MORD_Pos (0U)
#define DBGMCU_APB2_C2_FZ_REG_TSU_CAN1_DIS_MORD_Msk (0x1UL << DBGMCU_APB2_C2_FZ_REG_TSU_CAN1_DIS_MORD_Pos)      /*!< 0x00000001 */
#define DBGMCU_APB2_C2_FZ_REG_TSU_CAN1_DIS_MORD      DBGMCU_APB2_C2_FZ_REG_TSU_CAN1_DIS_MORD_Msk    /*!< TSU_CAN1_DIS_MORD */
#define DBGMCU_APB2_C2_FZ_REG_TSU_CAN2_DIS_MORD_Pos (1U)
#define DBGMCU_APB2_C2_FZ_REG_TSU_CAN2_DIS_MORD_Msk (0x1UL << DBGMCU_APB2_C2_FZ_REG_TSU_CAN2_DIS_MORD_Pos)      /*!< 0x00000002 */
#define DBGMCU_APB2_C2_FZ_REG_TSU_CAN2_DIS_MORD      DBGMCU_APB2_C2_FZ_REG_TSU_CAN2_DIS_MORD_Msk    /*!< TSU_CAN2_DIS_MORD */
#define DBGMCU_APB2_C2_FZ_REG_TSU_CAN3_DIS_MORD_Pos (2U)
#define DBGMCU_APB2_C2_FZ_REG_TSU_CAN3_DIS_MORD_Msk (0x1UL << DBGMCU_APB2_C2_FZ_REG_TSU_CAN3_DIS_MORD_Pos)      /*!< 0x00000004 */
#define DBGMCU_APB2_C2_FZ_REG_TSU_CAN3_DIS_MORD      DBGMCU_APB2_C2_FZ_REG_TSU_CAN3_DIS_MORD_Msk    /*!< TSU_CAN3_DIS_MORD */
#define DBGMCU_APB2_C2_FZ_REG_TSU_CAN4_DIS_MORD_Pos (3U)
#define DBGMCU_APB2_C2_FZ_REG_TSU_CAN4_DIS_MORD_Msk (0x1UL << DBGMCU_APB2_C2_FZ_REG_TSU_CAN4_DIS_MORD_Pos)      /*!< 0x00000008 */
#define DBGMCU_APB2_C2_FZ_REG_TSU_CAN4_DIS_MORD      DBGMCU_APB2_C2_FZ_REG_TSU_CAN4_DIS_MORD_Msk    /*!< TSU_CAN4_DIS_MORD */
#define DBGMCU_APB2_C2_FZ_REG_TIM1_PWM_FRZ_Pos      (11U)
#define DBGMCU_APB2_C2_FZ_REG_TIM1_PWM_FRZ_Msk      (0x1UL << DBGMCU_APB2_C2_FZ_REG_TIM1_PWM_FRZ_Pos) /*!< 0x00000800 */
#define DBGMCU_APB2_C2_FZ_REG_TIM1_PWM_FRZ           DBGMCU_APB2_C2_FZ_REG_TIM1_PWM_FRZ_Msk         /*!< TIM1_PWM_FRZ */
#define DBGMCU_APB2_C2_FZ_REG_TIM8_PWM_FRZ_Pos      (12U)
#define DBGMCU_APB2_C2_FZ_REG_TIM8_PWM_FRZ_Msk      (0x1UL << DBGMCU_APB2_C2_FZ_REG_TIM8_PWM_FRZ_Pos) /*!< 0x00001000 */
#define DBGMCU_APB2_C2_FZ_REG_TIM8_PWM_FRZ           DBGMCU_APB2_C2_FZ_REG_TIM8_PWM_FRZ_Msk         /*!< TIM8_PWM_FRZ */
#define DBGMCU_APB2_C2_FZ_REG_TIM4_PWM_FRZ_Pos      (15U)
#define DBGMCU_APB2_C2_FZ_REG_TIM4_PWM_FRZ_Msk      (0x1UL << DBGMCU_APB2_C2_FZ_REG_TIM4_PWM_FRZ_Pos) /*!< 0x00008000 */
#define DBGMCU_APB2_C2_FZ_REG_TIM4_PWM_FRZ           DBGMCU_APB2_C2_FZ_REG_TIM4_PWM_FRZ_Msk         /*!< TIM4_PWM_FRZ */
#define DBGMCU_APB2_C2_FZ_REG_TIM5_PWM_FRZ_Pos      (16U)
#define DBGMCU_APB2_C2_FZ_REG_TIM5_PWM_FRZ_Msk      (0x1UL << DBGMCU_APB2_C2_FZ_REG_TIM5_PWM_FRZ_Pos) /*!< 0x00010000 */
#define DBGMCU_APB2_C2_FZ_REG_TIM5_PWM_FRZ           DBGMCU_APB2_C2_FZ_REG_TIM5_PWM_FRZ_Msk         /*!< TIM5_PWM_FRZ */
#define DBGMCU_APB2_C2_FZ_REG_TIM15_PWM_FRZ_Pos     (17U)
#define DBGMCU_APB2_C2_FZ_REG_TIM15_PWM_FRZ_Msk     (0x1UL << DBGMCU_APB2_C2_FZ_REG_TIM15_PWM_FRZ_Pos)  /*!< 0x00020000 */
#define DBGMCU_APB2_C2_FZ_REG_TIM15_PWM_FRZ          DBGMCU_APB2_C2_FZ_REG_TIM15_PWM_FRZ_Msk        /*!< TIM15_PWM_FRZ */
#define DBGMCU_APB2_C2_FZ_REG_TIM16_PWM_FRZ_Pos     (18U)
#define DBGMCU_APB2_C2_FZ_REG_TIM16_PWM_FRZ_Msk     (0x1UL << DBGMCU_APB2_C2_FZ_REG_TIM16_PWM_FRZ_Pos)  /*!< 0x00040000 */
#define DBGMCU_APB2_C2_FZ_REG_TIM16_PWM_FRZ          DBGMCU_APB2_C2_FZ_REG_TIM16_PWM_FRZ_Msk        /*!< TIM16_PWM_FRZ */
#define DBGMCU_APB2_C2_FZ_REG_SDADC1_DBG_FRZ_Pos    (24U)
#define DBGMCU_APB2_C2_FZ_REG_SDADC1_DBG_FRZ_Msk    (0x1UL << DBGMCU_APB2_C2_FZ_REG_SDADC1_DBG_FRZ_Pos)   /*!< 0x01000000 */
#define DBGMCU_APB2_C2_FZ_REG_SDADC1_DBG_FRZ         DBGMCU_APB2_C2_FZ_REG_SDADC1_DBG_FRZ_Msk       /*!< SDADC1_DBG_FRZ */
#define DBGMCU_APB2_C2_FZ_REG_SDADC2_DBG_FRZ_Pos    (25U)
#define DBGMCU_APB2_C2_FZ_REG_SDADC2_DBG_FRZ_Msk    (0x1UL << DBGMCU_APB2_C2_FZ_REG_SDADC2_DBG_FRZ_Pos)   /*!< 0x02000000 */
#define DBGMCU_APB2_C2_FZ_REG_SDADC2_DBG_FRZ         DBGMCU_APB2_C2_FZ_REG_SDADC2_DBG_FRZ_Msk       /*!< SDADC2_DBG_FRZ */
#define DBGMCU_APB2_C2_FZ_REG_FDCAN1_DIS_MORD_Pos   (28U)
#define DBGMCU_APB2_C2_FZ_REG_FDCAN1_DIS_MORD_Msk   (0x1UL << DBGMCU_APB2_C2_FZ_REG_FDCAN1_DIS_MORD_Pos)    /*!< 0x10000000 */
#define DBGMCU_APB2_C2_FZ_REG_FDCAN1_DIS_MORD        DBGMCU_APB2_C2_FZ_REG_FDCAN1_DIS_MORD_Msk      /*!< FDCAN1_DIS_MORD */
#define DBGMCU_APB2_C2_FZ_REG_FDCAN2_DIS_MORD_Pos   (29U)
#define DBGMCU_APB2_C2_FZ_REG_FDCAN2_DIS_MORD_Msk   (0x1UL << DBGMCU_APB2_C2_FZ_REG_FDCAN2_DIS_MORD_Pos)    /*!< 0x20000000 */
#define DBGMCU_APB2_C2_FZ_REG_FDCAN2_DIS_MORD        DBGMCU_APB2_C2_FZ_REG_FDCAN2_DIS_MORD_Msk      /*!< FDCAN2_DIS_MORD */
#define DBGMCU_APB2_C2_FZ_REG_FDCAN3_DIS_MORD_Pos   (30U)
#define DBGMCU_APB2_C2_FZ_REG_FDCAN3_DIS_MORD_Msk   (0x1UL << DBGMCU_APB2_C2_FZ_REG_FDCAN3_DIS_MORD_Pos)    /*!< 0x40000000 */
#define DBGMCU_APB2_C2_FZ_REG_FDCAN3_DIS_MORD        DBGMCU_APB2_C2_FZ_REG_FDCAN3_DIS_MORD_Msk      /*!< FDCAN3_DIS_MORD */
#define DBGMCU_APB2_C2_FZ_REG_FDCAN4_DIS_MORD_Pos   (31U)
#define DBGMCU_APB2_C2_FZ_REG_FDCAN4_DIS_MORD_Msk   (0x1UL << DBGMCU_APB2_C2_FZ_REG_FDCAN4_DIS_MORD_Pos)    /*!< 0x80000000 */
#define DBGMCU_APB2_C2_FZ_REG_FDCAN4_DIS_MORD        DBGMCU_APB2_C2_FZ_REG_FDCAN4_DIS_MORD_Msk      /*!< FDCAN4_DIS_MORD */

/*************  Bit definition for DBGMCU_AXI_C2_FZ_REG register  *************/
#define DBGMCU_AXI_C2_FZ_REG_HRTIMER1_FRZ_Pos       (0U)
#define DBGMCU_AXI_C2_FZ_REG_HRTIMER1_FRZ_Msk        (0x1UL << DBGMCU_AXI_C2_FZ_REG_HRTIMER1_FRZ_Pos) /*!< 0x00000001 */
#define DBGMCU_AXI_C2_FZ_REG_HRTIMER1_FRZ            DBGMCU_AXI_C2_FZ_REG_HRTIMER1_FRZ_Msk          /*!< HRTIMER1_FRZ */
#define DBGMCU_AXI_C2_FZ_REG_HRTIMER2_FRZ_Pos        (1U)
#define DBGMCU_AXI_C2_FZ_REG_HRTIMER2_FRZ_Msk        (0x1UL << DBGMCU_AXI_C2_FZ_REG_HRTIMER2_FRZ_Pos) /*!< 0x00000002 */
#define DBGMCU_AXI_C2_FZ_REG_HRTIMER2_FRZ            DBGMCU_AXI_C2_FZ_REG_HRTIMER2_FRZ_Msk          /*!< HRTIMER2_FRZ */

/**************  Bit definition for DBGMCU_DBG_RST_REG register  **************/
#define DBGMCU_DBG_RST_REG_FPD_FUNC_Pos             (0U)
#define DBGMCU_DBG_RST_REG_FPD_FUNC_Msk             (0x1UL << DBGMCU_DBG_RST_REG_FPD_FUNC_Pos)      /*!< 0x00000001 */
#define DBGMCU_DBG_RST_REG_FPD_FUNC                  DBGMCU_DBG_RST_REG_FPD_FUNC_Msk                /*!< FPD_FUNC */
#define DBGMCU_DBG_RST_REG_FPD_DEST_Pos             (1U)
#define DBGMCU_DBG_RST_REG_FPD_DEST_Msk             (0x1UL << DBGMCU_DBG_RST_REG_FPD_DEST_Pos)      /*!< 0x00000002 */
#define DBGMCU_DBG_RST_REG_FPD_DEST                  DBGMCU_DBG_RST_REG_FPD_DEST_Msk                /*!< FPD_DEST */

/***************  Bit definition for DBGMCU_DOUT_REG register  ****************/
#define DBGMCU_DOUT_REG_DOUT_Pos                    (0U)
#define DBGMCU_DOUT_REG_DOUT_Msk                    (0xFFFFFFFFUL << DBGMCU_DOUT_REG_DOUT_Pos)      /*!< 0xFFFFFFFF */
#define DBGMCU_DOUT_REG_DOUT                         DBGMCU_DOUT_REG_DOUT_Msk                       /*!< DOUT */

/****************  Bit definition for DBGMCU_DIN_REG register  ****************/
#define DBGMCU_DIN_REG_DIN_Pos                       (0U)
#define DBGMCU_DIN_REG_DIN_Msk                       (0xFFFFFFFFUL << DBGMCU_DIN_REG_DIN_Pos)         /*!< 0xFFFFFFFF */
#define DBGMCU_DIN_REG_DIN                           DBGMCU_DIN_REG_DIN_Msk                         /*!< DIN */

/*****************  Bit definition for DBGMCU_DMCR register  ******************/
#define DBGMCU_DMCR_DOUT_IE_Pos                     (0U)
#define DBGMCU_DMCR_DOUT_IE_Msk                     (0x1UL << DBGMCU_DMCR_DOUT_IE_Pos)              /*!< 0x00000001 */
#define DBGMCU_DMCR_DOUT_IE                          DBGMCU_DMCR_DOUT_IE_Msk                        /*!< DOUT_IE */
#define DBGMCU_DMCR_DIN_IE_Pos                      (16U)
#define DBGMCU_DMCR_DIN_IE_Msk                      (0x1UL << DBGMCU_DMCR_DIN_IE_Pos)               /*!< 0x00010000 */
#define DBGMCU_DMCR_DIN_IE                           DBGMCU_DMCR_DIN_IE_Msk                         /*!< DIN_IE */

/*****************  Bit definition for DBGMCU_DMSR register  ******************/
#define DBGMCU_DMSR_DOUT_RDY_Pos                    (0U)
#define DBGMCU_DMSR_DOUT_RDY_Msk                    (0x1UL << DBGMCU_DMSR_DOUT_RDY_Pos)             /*!< 0x00000001 */
#define DBGMCU_DMSR_DOUT_RDY                         DBGMCU_DMSR_DOUT_RDY_Msk                       /*!< DOUT_RDY */
#define DBGMCU_DMSR_DOUT_IF_Pos                     (8U)
#define DBGMCU_DMSR_DOUT_IF_Msk                     (0x1UL << DBGMCU_DMSR_DOUT_IF_Pos)              /*!< 0x00000100 */
#define DBGMCU_DMSR_DOUT_IF                          DBGMCU_DMSR_DOUT_IF_Msk                        /*!< DOUT_IF */
#define DBGMCU_DMSR_DIN_RDY_Pos                     (16U)
#define DBGMCU_DMSR_DIN_RDY_Msk                     (0x1UL << DBGMCU_DMSR_DIN_RDY_Pos)              /*!< 0x00010000 */
#define DBGMCU_DMSR_DIN_RDY                          DBGMCU_DMSR_DIN_RDY_Msk                        /*!< DIN_RDY */
#define DBGMCU_DMSR_DIN_IF_Pos                      (24U)
#define DBGMCU_DMSR_DIN_IF_Msk                      (0x1UL << DBGMCU_DMSR_DIN_IF_Pos)               /*!< 0x01000000 */
#define DBGMCU_DMSR_DIN_IF                           DBGMCU_DMSR_DIN_IF_Msk                         /*!< DIN_IF */
#define DBGMCU_DMSR_DEVICE_EN_Pos                   (31U)
#define DBGMCU_DMSR_DEVICE_EN_Msk                   (0x1UL << DBGMCU_DMSR_DEVICE_EN_Pos)            /*!< 0x80000000 */
#define DBGMCU_DMSR_DEVICE_EN                        DBGMCU_DMSR_DEVICE_EN_Msk                      /*!< DEVICE_EN */

/**************  Bit definition for DBGMCU_CTI_TRG_SEL register  **************/
#define DBGMCU_CTI_TRG_SEL_TINIDENSEL_Pos           (0U)
#define DBGMCU_CTI_TRG_SEL_TINIDENSEL_Msk           (0xFUL << DBGMCU_CTI_TRG_SEL_TINIDENSEL_Pos)    /*!< 0x0000000F */
#define DBGMCU_CTI_TRG_SEL_TINIDENSEL                DBGMCU_CTI_TRG_SEL_TINIDENSEL_Msk              /*!< TINIDENSEL */
#define DBGMCU_CTI_TRG_SEL_TODBGENSEL_Pos           (16U)
#define DBGMCU_CTI_TRG_SEL_TODBGENSEL_Msk           (0xFUL << DBGMCU_CTI_TRG_SEL_TODBGENSEL_Pos)    /*!< 0x000F0000 */
#define DBGMCU_CTI_TRG_SEL_TODBGENSEL                DBGMCU_CTI_TRG_SEL_TODBGENSEL_Msk              /*!< TODBGENSEL */

/*************  Bit definition for DBGMCU_DBG_SLEEP_CFG register  *************/
#define DBGMCU_DBG_SLEEP_CFG_DBG_SLEEP1_Pos         (0U)
#define DBGMCU_DBG_SLEEP_CFG_DBG_SLEEP1_Msk         (0x1UL << DBGMCU_DBG_SLEEP_CFG_DBG_SLEEP1_Pos)  /*!< 0x00000001 */
#define DBGMCU_DBG_SLEEP_CFG_DBG_SLEEP1              DBGMCU_DBG_SLEEP_CFG_DBG_SLEEP1_Msk            /*!< DBG_SLEEP1 */
#define DBGMCU_DBG_SLEEP_CFG_DBG_SLEEP2_Pos         (1U)
#define DBGMCU_DBG_SLEEP_CFG_DBG_SLEEP2_Msk         (0x1UL << DBGMCU_DBG_SLEEP_CFG_DBG_SLEEP2_Pos)  /*!< 0x00000002 */
#define DBGMCU_DBG_SLEEP_CFG_DBG_SLEEP2              DBGMCU_DBG_SLEEP_CFG_DBG_SLEEP2_Msk            /*!< DBG_SLEEP2 */
#define DBGMCU_DBG_SLEEP_CFG_DBG_SLEEPH_Pos         (16U)
#define DBGMCU_DBG_SLEEP_CFG_DBG_SLEEPH_Msk         (0x1UL << DBGMCU_DBG_SLEEP_CFG_DBG_SLEEPH_Pos)  /*!< 0x00010000 */
#define DBGMCU_DBG_SLEEP_CFG_DBG_SLEEPH              DBGMCU_DBG_SLEEP_CFG_DBG_SLEEPH_Msk            /*!< DBG_SLEEPH */

/****************  Bit definition for DBGMCU_DEVARCH register  ****************/
#define DBGMCU_DEVARCH_DEV_ARCH_Pos                 (0U)
#define DBGMCU_DEVARCH_DEV_ARCH_Msk                 (0xFFFFFFFFUL << DBGMCU_DEVARCH_DEV_ARCH_Pos)   /*!< 0xFFFFFFFF */
#define DBGMCU_DEVARCH_DEV_ARCH                      DBGMCU_DEVARCH_DEV_ARCH_Msk                    /*!< DEV_ARCH */

/****************  Bit definition for DBGMCU_DEVTYPE register  ****************/
#define DBGMCU_DEVTYPE_DEV_TYPE_Pos                 (0U)
#define DBGMCU_DEVTYPE_DEV_TYPE_Msk                 (0xFFUL << DBGMCU_DEVTYPE_DEV_TYPE_Pos)         /*!< 0x000000FF */
#define DBGMCU_DEVTYPE_DEV_TYPE                      DBGMCU_DEVTYPE_DEV_TYPE_Msk                    /*!< DEV_TYPE */

/*****************  Bit definition for DBGMCU_PIDR4 register  *****************/
#define DBGMCU_PIDR4_PIDR4_VAL_Pos                  (0U)
#define DBGMCU_PIDR4_PIDR4_VAL_Msk                  (0xFFFFFFFFUL << DBGMCU_PIDR4_PIDR4_VAL_Pos)    /*!< 0xFFFFFFFF */
#define DBGMCU_PIDR4_PIDR4_VAL                       DBGMCU_PIDR4_PIDR4_VAL_Msk                     /*!< PIDR4_VAL */

/*****************  Bit definition for DBGMCU_PIDR5 register  *****************/
#define DBGMCU_PIDR5_PIDR5_VAL_Pos                  (0U)
#define DBGMCU_PIDR5_PIDR5_VAL_Msk                  (0xFFFFFFFFUL << DBGMCU_PIDR5_PIDR5_VAL_Pos)    /*!< 0xFFFFFFFF */
#define DBGMCU_PIDR5_PIDR5_VAL                       DBGMCU_PIDR5_PIDR5_VAL_Msk                     /*!< PIDR5_VAL */

/*****************  Bit definition for DBGMCU_PIDR6 register  *****************/
#define DBGMCU_PIDR6_PIDR6_VAL_Pos                  (0U)
#define DBGMCU_PIDR6_PIDR6_VAL_Msk                  (0xFFFFFFFFUL << DBGMCU_PIDR6_PIDR6_VAL_Pos)    /*!< 0xFFFFFFFF */
#define DBGMCU_PIDR6_PIDR6_VAL                       DBGMCU_PIDR6_PIDR6_VAL_Msk                     /*!< PIDR6_VAL */

/*****************  Bit definition for DBGMCU_PIDR7 register  *****************/
#define DBGMCU_PIDR7_PIDR7_VAL_Pos                  (0U)
#define DBGMCU_PIDR7_PIDR7_VAL_Msk                  (0xFFFFFFFFUL << DBGMCU_PIDR7_PIDR7_VAL_Pos)    /*!< 0xFFFFFFFF */
#define DBGMCU_PIDR7_PIDR7_VAL                       DBGMCU_PIDR7_PIDR7_VAL_Msk                     /*!< PIDR7_VAL */

/*****************  Bit definition for DBGMCU_PIDR0 register  *****************/
#define DBGMCU_PIDR0_PIDR0_VAL_Pos                  (0U)
#define DBGMCU_PIDR0_PIDR0_VAL_Msk                  (0xFFFFFFFFUL << DBGMCU_PIDR0_PIDR0_VAL_Pos)    /*!< 0xFFFFFFFF */
#define DBGMCU_PIDR0_PIDR0_VAL                       DBGMCU_PIDR0_PIDR0_VAL_Msk                     /*!< PIDR0_VAL */

/*****************  Bit definition for DBGMCU_PIDR1 register  *****************/
#define DBGMCU_PIDR1_PIDR1_VAL_Pos                  (0U)
#define DBGMCU_PIDR1_PIDR1_VAL_Msk                  (0xFFFFFFFFUL << DBGMCU_PIDR1_PIDR1_VAL_Pos)    /*!< 0xFFFFFFFF */
#define DBGMCU_PIDR1_PIDR1_VAL                       DBGMCU_PIDR1_PIDR1_VAL_Msk                     /*!< PIDR1_VAL */

/*****************  Bit definition for DBGMCU_PIDR2 register  *****************/
#define DBGMCU_PIDR2_PIDR2_VAL_Pos                  (0U)
#define DBGMCU_PIDR2_PIDR2_VAL_Msk                  (0xFFFFFFFFUL << DBGMCU_PIDR2_PIDR2_VAL_Pos)    /*!< 0xFFFFFFFF */
#define DBGMCU_PIDR2_PIDR2_VAL                       DBGMCU_PIDR2_PIDR2_VAL_Msk                     /*!< PIDR2_VAL */

/*****************  Bit definition for DBGMCU_PIDR3 register  *****************/
#define DBGMCU_PIDR3_PIDR3_VAL_Pos                  (0U)
#define DBGMCU_PIDR3_PIDR3_VAL_Msk                  (0xFFFFFFFFUL << DBGMCU_PIDR3_PIDR3_VAL_Pos)    /*!< 0xFFFFFFFF */
#define DBGMCU_PIDR3_PIDR3_VAL                       DBGMCU_PIDR3_PIDR3_VAL_Msk                     /*!< PIDR3_VAL */

/*****************  Bit definition for DBGMCU_CIDR0 register  *****************/
#define DBGMCU_CIDR0_CIDR0_VAL_Pos                  (0U)
#define DBGMCU_CIDR0_CIDR0_VAL_Msk                  (0xFFFFFFFFUL << DBGMCU_CIDR0_CIDR0_VAL_Pos)    /*!< 0xFFFFFFFF */
#define DBGMCU_CIDR0_CIDR0_VAL                       DBGMCU_CIDR0_CIDR0_VAL_Msk                     /*!< CIDR0_VAL */

/*****************  Bit definition for DBGMCU_CIDR1 register  *****************/
#define DBGMCU_CIDR1_CIDR1_VAL_Pos                  (0U)
#define DBGMCU_CIDR1_CIDR1_VAL_Msk                  (0xFFFFFFFFUL << DBGMCU_CIDR1_CIDR1_VAL_Pos)    /*!< 0xFFFFFFFF */
#define DBGMCU_CIDR1_CIDR1_VAL                       DBGMCU_CIDR1_CIDR1_VAL_Msk                     /*!< CIDR1_VAL */

/*****************  Bit definition for DBGMCU_CIDR2 register  *****************/
#define DBGMCU_CIDR2_CIDR2_VAL_Pos                  (0U)
#define DBGMCU_CIDR2_CIDR2_VAL_Msk                  (0xFFFFFFFFUL << DBGMCU_CIDR2_CIDR2_VAL_Pos)    /*!< 0xFFFFFFFF */
#define DBGMCU_CIDR2_CIDR2_VAL                       DBGMCU_CIDR2_CIDR2_VAL_Msk                     /*!< CIDR2_VAL */

/*****************  Bit definition for DBGMCU_CIDR3 register  *****************/
#define DBGMCU_CIDR3_CIDR3_VAL_Pos                  (0U)
#define DBGMCU_CIDR3_CIDR3_VAL_Msk                  (0xFFFFFFFFUL << DBGMCU_CIDR3_CIDR3_VAL_Pos)    /*!< 0xFFFFFFFF */
#define DBGMCU_CIDR3_CIDR3_VAL                       DBGMCU_CIDR3_CIDR3_VAL_Msk                     /*!< CIDR3_VAL */

#define DBGMCU_BASE           0x70000000UL 


#define DBGMCU                ((DBGMCU_TypeDef *) DBGMCU_BASE) 


#endif /* __SR5E1_DBGMCU_H */

