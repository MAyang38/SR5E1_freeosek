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
/**
 * @file    hrtim.h
 * @brief   HRTIM driver header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup TIMERS
 * @ingroup DRIVERS
 * @addtogroup HRTIM
 * @ingroup TIMERS
 * @{
 */

#ifndef _HRTIM_H_
#define _HRTIM_H_

#include <typedefs.h>

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

/**
 * @name    HRTIM number of timers [TA:TF]
 * @{
 */
#define HRTIM_TIMER_NUM                     6U
/** @} */

/**
 * @name    HRTIM number of comparetors x master/timer
 * @{
 */
#define HRTIM_COMP_NUM                      4U
/** @} */

/**
 * @name    HRTIM number of outputs x timer
 * @{
 */
#define HRTIM_OUTPUT_NUM                    2U
/** @} */

/**
 * @name    HRTIM number of output set/reset event
 * @{
 */
#define HRTIM_EVENT_NUM                     32U
/** @} */

/**
 * @name    DLLCR register additional macros
 * @{
 */
#define HRTIM_DLLCR_CALRTE_DIV1048576       0U            /**< Calibration rate = 1048576 * tHRTIM */
#define HRTIM_DLLCR_CALRTE_DIV131072        1U            /**< Calibration rate = 131072  * tHRTIM */
#define HRTIM_DLLCR_CALRTE_DIV16384         2U            /**< Calibration rate = 16384   * tHRTIM */
#define HRTIM_DLLCR_CALRTE_DIV2048          3U            /**< Calibration rate = 2048    * tHRTIM */
/** @} */

/**
 * @name    HRTIM output set/reset events
 * @{
 */
#define HRTIM_OUTPUT_TIMEVNT(n)             ((uint32_t)(0x00000800U) <<(n))
#define HRTIM_OUTPUT_EXT_EVN(n)             ((uint32_t)(0x00100000U) <<(n))

#define HRTIM_OUTPUT_NONE                   0x00000000UL                /*!< Reset the output set crossbar                               */
#define HRTIM_OUTPUT_SST                    0x00000001UL                /**< Software set trigger event                                  */
#define HRTIM_OUTPUT_RESYNC                 0x00000002UL                /*!< Timer reset event coming solely from software or SYNC input */
#define HRTIM_OUTPUT_TIMPER                 0x00000004UL                /*!< Timer period event                                          */
#define HRTIM_OUTPUT_TIMCMP1                0x00000008UL                /*!< Timer compare 1 event                                       */
#define HRTIM_OUTPUT_TIMCMP2                0x00000010UL                /*!< Timer compare 2 event                                       */
#define HRTIM_OUTPUT_TIMCMP3                0x00000020UL                /*!< Timer compare 3 event                                       */
#define HRTIM_OUTPUT_TIMCMP4                0x00000040UL                /*!< Timer compare 4 event                                       */
#define HRTIM_OUTPUT_MASTERPER              0x00000080UL                /*!< The master timer period                                     */
#define HRTIM_OUTPUT_MASTERCMP1             0x00000100UL                /*!< Master Timer compare 1                                      */
#define HRTIM_OUTPUT_MASTERCMP2             0x00000200UL                /*!< Master Timer compare 2                                      */
#define HRTIM_OUTPUT_MASTERCMP3             0x00000400UL                /*!< Master Timer compare 3                                      */
#define HRTIM_OUTPUT_MASTERCMP4             0x00000800UL                /*!< Master Timer compare 4                                      */
/* Timer Events mapping for Timer A */
#define HRTIM_OUTPUT_TIMAEV1_TIMBCMP1       (HRTIM_OUTPUT_TIMEVNT(1))   /*!< Timer event 1               */
#define HRTIM_OUTPUT_TIMAEV2_TIMBCMP2       (HRTIM_OUTPUT_TIMEVNT(2))   /*!< Timer event 2               */
#define HRTIM_OUTPUT_TIMAEV3_TIMCCMP2       (HRTIM_OUTPUT_TIMEVNT(3))   /*!< Timer event 3               */
#define HRTIM_OUTPUT_TIMAEV4_TIMCCMP3       (HRTIM_OUTPUT_TIMEVNT(4))   /*!< Timer event 4               */
#define HRTIM_OUTPUT_TIMAEV5_TIMDCMP1       (HRTIM_OUTPUT_TIMEVNT(5))   /*!< Timer event 5               */
#define HRTIM_OUTPUT_TIMAEV6_TIMDCMP2       (HRTIM_OUTPUT_TIMEVNT(6))   /*!< Timer event 6               */
#define HRTIM_OUTPUT_TIMAEV7_TIMECMP3       (HRTIM_OUTPUT_TIMEVNT(7))   /*!< Timer event 7               */
#define HRTIM_OUTPUT_TIMAEV8_TIMECMP4       (HRTIM_OUTPUT_TIMEVNT(8))   /*!< Timer event 8               */
#define HRTIM_OUTPUT_TIMAEV9_TIMFCMP4       (HRTIM_OUTPUT_TIMEVNT(9))   /*!< Timer event 9               */
/* Timer Events mapping for Timer B */
#define HRTIM_OUTPUT_TIMBEV1_TIMACMP1       (HRTIM_OUTPUT_TIMEVNT(1))   /*!< Timer event 1               */
#define HRTIM_OUTPUT_TIMBEV2_TIMACMP2       (HRTIM_OUTPUT_TIMEVNT(2))   /*!< Timer event 2               */
#define HRTIM_OUTPUT_TIMBEV3_TIMCCMP3       (HRTIM_OUTPUT_TIMEVNT(3))   /*!< Timer event 3               */
#define HRTIM_OUTPUT_TIMBEV4_TIMCCMP4       (HRTIM_OUTPUT_TIMEVNT(4))   /*!< Timer event 4               */
#define HRTIM_OUTPUT_TIMBEV5_TIMDCMP3       (HRTIM_OUTPUT_TIMEVNT(5))   /*!< Timer event 5               */
#define HRTIM_OUTPUT_TIMBEV6_TIMDCMP4       (HRTIM_OUTPUT_TIMEVNT(6))   /*!< Timer event 6               */
#define HRTIM_OUTPUT_TIMBEV7_TIMECMP1       (HRTIM_OUTPUT_TIMEVNT(7))   /*!< Timer event 7               */
#define HRTIM_OUTPUT_TIMBEV8_TIMECMP2       (HRTIM_OUTPUT_TIMEVNT(8))   /*!< Timer event 8               */
#define HRTIM_OUTPUT_TIMBEV9_TIMFCMP3       (HRTIM_OUTPUT_TIMEVNT(9))   /*!< Timer event 9               */
/* Timer Events mapping for Timer C */
#define HRTIM_OUTPUT_TIMCEV1_TIMACMP2       (HRTIM_OUTPUT_TIMEVNT(1))   /*!< Timer event 1               */
#define HRTIM_OUTPUT_TIMCEV2_TIMACMP3       (HRTIM_OUTPUT_TIMEVNT(2))   /*!< Timer event 2               */
#define HRTIM_OUTPUT_TIMCEV3_TIMBCMP2       (HRTIM_OUTPUT_TIMEVNT(3))   /*!< Timer event 3               */
#define HRTIM_OUTPUT_TIMCEV4_TIMBCMP3       (HRTIM_OUTPUT_TIMEVNT(4))   /*!< Timer event 4               */
#define HRTIM_OUTPUT_TIMCEV5_TIMDCMP2       (HRTIM_OUTPUT_TIMEVNT(5))   /*!< Timer event 5               */
#define HRTIM_OUTPUT_TIMCEV6_TIMDCMP4       (HRTIM_OUTPUT_TIMEVNT(6))   /*!< Timer event 6               */
#define HRTIM_OUTPUT_TIMCEV7_TIMECMP3       (HRTIM_OUTPUT_TIMEVNT(7))   /*!< Timer event 7               */
#define HRTIM_OUTPUT_TIMCEV8_TIMECMP4       (HRTIM_OUTPUT_TIMEVNT(8))   /*!< Timer event 8               */
#define HRTIM_OUTPUT_TIMCEV9_TIMFCMP2       (HRTIM_OUTPUT_TIMEVNT(9))   /*!< Timer event 9               */
/* Timer Events mapping for Timer D */
#define HRTIM_OUTPUT_TIMDEV1_TIMACMP1       (HRTIM_OUTPUT_TIMEVNT(1))   /*!< Timer event 1               */
#define HRTIM_OUTPUT_TIMDEV2_TIMACMP4       (HRTIM_OUTPUT_TIMEVNT(2))   /*!< Timer event 2               */
#define HRTIM_OUTPUT_TIMDEV3_TIMBCMP2       (HRTIM_OUTPUT_TIMEVNT(3))   /*!< Timer event 3               */
#define HRTIM_OUTPUT_TIMDEV4_TIMBCMP4       (HRTIM_OUTPUT_TIMEVNT(4))   /*!< Timer event 4               */
#define HRTIM_OUTPUT_TIMDEV5_TIMCCMP4       (HRTIM_OUTPUT_TIMEVNT(5))   /*!< Timer event 5               */
#define HRTIM_OUTPUT_TIMDEV6_TIMECMP1       (HRTIM_OUTPUT_TIMEVNT(6))   /*!< Timer event 6               */
#define HRTIM_OUTPUT_TIMDEV7_TIMECMP4       (HRTIM_OUTPUT_TIMEVNT(7))   /*!< Timer event 7               */
#define HRTIM_OUTPUT_TIMDEV8_TIMFCMP1       (HRTIM_OUTPUT_TIMEVNT(8))   /*!< Timer event 8               */
#define HRTIM_OUTPUT_TIMDEV9_TIMFCMP3       (HRTIM_OUTPUT_TIMEVNT(9))   /*!< Timer event 9               */
/* Timer Events mapping for Timer E */
#define HRTIM_OUTPUT_TIMEEV1_TIMACMP4       (HRTIM_OUTPUT_TIMEVNT(1))   /*!< Timer event 1               */
#define HRTIM_OUTPUT_TIMEEV2_TIMBCMP3       (HRTIM_OUTPUT_TIMEVNT(2))   /*!< Timer event 2               */
#define HRTIM_OUTPUT_TIMEEV3_TIMBCMP4       (HRTIM_OUTPUT_TIMEVNT(3))   /*!< Timer event 3               */
#define HRTIM_OUTPUT_TIMEEV4_TIMCCMP1       (HRTIM_OUTPUT_TIMEVNT(4))   /*!< Timer event 4               */
#define HRTIM_OUTPUT_TIMEEV5_TIMCCMP2       (HRTIM_OUTPUT_TIMEVNT(5))   /*!< Timer event 5               */
#define HRTIM_OUTPUT_TIMEEV6_TIMDCMP1       (HRTIM_OUTPUT_TIMEVNT(6))   /*!< Timer event 6               */
#define HRTIM_OUTPUT_TIMEEV7_TIMDCMP2       (HRTIM_OUTPUT_TIMEVNT(7))   /*!< Timer event 7               */
#define HRTIM_OUTPUT_TIMEEV8_TIMFCMP3       (HRTIM_OUTPUT_TIMEVNT(8))   /*!< Timer event 8               */
#define HRTIM_OUTPUT_TIMEEV9_TIMFCMP4       (HRTIM_OUTPUT_TIMEVNT(9))   /*!< Timer event 9               */
/* Timer Events mapping for Timer F */
#define HRTIM_OUTPUT_TIMFEV1_TIMACMP3       (HRTIM_OUTPUT_TIMEVNT(1))   /*!< Timer event 1               */
#define HRTIM_OUTPUT_TIMFEV2_TIMBCMP1       (HRTIM_OUTPUT_TIMEVNT(2))   /*!< Timer event 2               */
#define HRTIM_OUTPUT_TIMFEV3_TIMBCMP4       (HRTIM_OUTPUT_TIMEVNT(3))   /*!< Timer event 3               */
#define HRTIM_OUTPUT_TIMFEV4_TIMCCMP1       (HRTIM_OUTPUT_TIMEVNT(4))   /*!< Timer event 4               */
#define HRTIM_OUTPUT_TIMFEV5_TIMCCMP4       (HRTIM_OUTPUT_TIMEVNT(5))   /*!< Timer event 5               */
#define HRTIM_OUTPUT_TIMFEV6_TIMDCMP3       (HRTIM_OUTPUT_TIMEVNT(6))   /*!< Timer event 6               */
#define HRTIM_OUTPUT_TIMFEV7_TIMDCMP4       (HRTIM_OUTPUT_TIMEVNT(7))   /*!< Timer event 7               */
#define HRTIM_OUTPUT_TIMFEV8_TIMECMP2       (HRTIM_OUTPUT_TIMEVNT(8))   /*!< Timer event 8               */
#define HRTIM_OUTPUT_TIMFEV9_TIMECMP3       (HRTIM_OUTPUT_TIMEVNT(9))   /*!< Timer event 9               */
#define HRTIM_OUTPUT_EEV_1                  (HRTIM_OUTPUT_EXT_EVN(1))   /*!< External event 1            */
#define HRTIM_OUTPUT_EEV_2                  (HRTIM_OUTPUT_EXT_EVN(2))   /*!< External event 2            */
#define HRTIM_OUTPUT_EEV_3                  (HRTIM_OUTPUT_EXT_EVN(3))   /*!< External event 3            */
#define HRTIM_OUTPUT_EEV_4                  (HRTIM_OUTPUT_EXT_EVN(4))   /*!< External event 4            */
#define HRTIM_OUTPUT_EEV_5                  (HRTIM_OUTPUT_EXT_EVN(5))   /*!< External event 5            */
#define HRTIM_OUTPUT_EEV_6                  (HRTIM_OUTPUT_EXT_EVN(6))   /*!< External event 6            */
#define HRTIM_OUTPUT_EEV_7                  (HRTIM_OUTPUT_EXT_EVN(7))   /*!< External event 7            */
#define HRTIM_OUTPUT_EEV_8                  (HRTIM_OUTPUT_EXT_EVN(8))   /*!< External event 8            */
#define HRTIM_OUTPUT_EEV_9                  (HRTIM_OUTPUT_EXT_EVN(9))   /*!< External event 9            */
#define HRTIM_OUTPUT_EEV_10                 (HRTIM_OUTPUT_EXT_EVN(10))  /*!< External event 10           */
#define HRTIM_OUTPUT_UPDATE                 0x80000000UL                /*!< Timer register update event */
/** @} */

/**
 * @name    HRTIM master/timer callback events
 * @{
 */
#define HRTIM_CB_EVENT_CMP1                 0x01U /**< Master/Timer compare 1 event  */
#define HRTIM_CB_EVENT_CMP2                 0x02U /**< Master/Timer compare 2 event  */
#define HRTIM_CB_EVENT_CMP3                 0x04U /**< Master/Timer compare 3 event  */
#define HRTIM_CB_EVENT_CMP4                 0x08U /**< Master/Timer compare 4 event  */
#define HRTIM_CB_EVENT_REP                  0x10U /**< Master/Timer repetition event */
#define HRTIM_CB_EVENT_SYNC                 0x20U /**< Master sync input event       */
#define HRTIM_CB_EVENT_UPD                  0x40U /**< Master/Timer update event     */
/** @} */

/**
 * @name    HRTIM fault callback events
 * @{
 */
#define HRTIM_CB_EVENT_FAULT1               0x01U /**< Fault 1 event      */
#define HRTIM_CB_EVENT_FAULT2               0x02U /**< Fault 2 event      */
#define HRTIM_CB_EVENT_FAULT3               0x04U /**< Fault 3 event      */
#define HRTIM_CB_EVENT_FAULT4               0x08U /**< Fault 4 event      */
#define HRTIM_CB_EVENT_FAULT5               0x10U /**< Fault 5 event      */
#define HRTIM_CB_EVENT_SYSFAULT             0x20U /**< System fault event */
#define HRTIM_CB_EVENT_FAULT6               0x40U /**< Fault 6 event      */
/** @} */

/**
 * @name    HRTIM number of ADC triggers
 * @{
 */
#define HRTIM_ADCTRIG_NUM                   10U

/** @} */

/**
 * @name    HRTIM number of external event
 * @{
 */
#define HRTIM_EXEVENT_NUM                   10U
/** @} */

/**
 * @name    HRTIM number of fault input
 * @{
 */
#define HRTIM_FAULT_NUM                     6U
/** @} */

/**
 * @name    HRTIM counter reset event events
 * @note    Supported events:
 *          – The timing unit: compare 2, compare 4 and update (3 events)
 *          – The master timer: reset and compare 1..4 (5 events)
 *          – The external events EXTEVNT1..10 (10 events)
 *          – All other timing units (for example, timer B..F for timer A): 
 *            compare 1, 2 and 4 (12 events)
 * @{
 */
/* Events common at each timer (A..F).*/
#define HRTIM_COUNTER_RESET_NOEVENT                0x00000000UL    /**< No counter reset event                       */
#define HRTIM_COUNTER_RESET_UPDATE                 (0x1UL << 1U)   /**< 0x00000002 < Update event                    */
#define HRTIM_COUNTER_RESET_CMP2                   (0x1UL << 2U)   /**< 0x00000004 < Timer compare 2 event           */
#define HRTIM_COUNTER_RESET_CMP4                   (0x1UL << 3U)   /**< 0x00000008 < Timer compare 4 event           */
#define HRTIM_COUNTER_RESET_MSTPER                 (0x1UL << 4U)   /**< 0x00000010 < Master timer roll-over event    */
#define HRTIM_COUNTER_RESET_MSTCMP1                (0x1UL << 5U)   /**< 0x00000020 < Master timer compare 1 event    */
#define HRTIM_COUNTER_RESET_MSTCMP2                (0x1UL << 6U)   /**< 0x00000040 < Master timer compare 2 event    */
#define HRTIM_COUNTER_RESET_MSTCMP3                (0x1UL << 7U)   /**< 0x00000080 < Master timer compare 3 event    */
#define HRTIM_COUNTER_RESET_MSTCMP4                (0x1UL << 8U)   /**< 0x00000100 < Master timer compare 4 event    */
#define HRTIM_COUNTER_RESET_EXTEVNT1               (0x1UL << 9U)   /**< 0x00000200 < External event 1                */
#define HRTIM_COUNTER_RESET_EXTEVNT2               (0x1UL << 10U)  /**< 0x00000400 < External event 2                */
#define HRTIM_COUNTER_RESET_EXTEVNT3               (0x1UL << 11U)  /**< 0x00000800 < External event 3                */
#define HRTIM_COUNTER_RESET_EXTEVNT4               (0x1UL << 12U)  /**< 0x00001000 < External event 4                */
#define HRTIM_COUNTER_RESET_EXTEVNT5               (0x1UL << 13U)  /**< 0x00002000 < External event 5                */
#define HRTIM_COUNTER_RESET_EXTEVNT6               (0x1UL << 14U)  /**< 0x00004000 < External event 6                */
#define HRTIM_COUNTER_RESET_EXTEVNT7               (0x1UL << 15U)  /**< 0x00008000 < External event 7                */
#define HRTIM_COUNTER_RESET_EXTEVNT8               (0x1UL << 16U)  /**< 0x00010000 < External event 8                */
#define HRTIM_COUNTER_RESET_EXTEVNT9               (0x1UL << 17U)  /**< 0x00020000 < External event 9                */
#define HRTIM_COUNTER_RESET_EXTEVNT10              (0x1UL << 18U)  /**< 0x00040000 < External event 10               */
/* Events customized for each timer.*/
#define HRTIM_COUNTER_RESET_TIMFCMP1               (0x1UL << 0U)   /**< 0x00000001 < Timer F compare 1 event         */
#define HRTIM_COUNTER_RESET_TIMECMP1_TIMERF        (0x1UL << 0U)   /**< 0x00000001 < Timer E compare 1 event (RSTFR) */
#define HRTIM_COUNTER_RESET_TIMACMP1               (0x1UL << 19U)  /**< 0x00080000 < Timer B compare 1 event         */
#define HRTIM_COUNTER_RESET_TIMACMP1_TIMERB        (0x1UL << 19U)  /**< 0x00080000 < Timer A compare 1 event (RSTBR) */
#define HRTIM_COUNTER_RESET_TIMBCMP2               (0x1UL << 20U)  /**< 0x00100000 < Timer B compare 2 event         */
#define HRTIM_COUNTER_RESET_TIMACMP2_TIMERB        (0x1UL << 20U)  /**< 0x00100000 < Timer A compare 2 event (RSTBR) */
#define HRTIM_COUNTER_RESET_TIMBCMP4               (0x1UL << 21U)  /**< 0x00200000 < Timer B compare 4 event         */
#define HRTIM_COUNTER_RESET_TIMACMP4_TIMERB        (0x1UL << 21U)  /**< 0x00200000 < Timer A compare 4 event (RSTBR) */
#define HRTIM_COUNTER_RESET_TIMCCMP1               (0x1UL << 22U)  /**< 0x00400000 < Timer B compare 1 event         */
#define HRTIM_COUNTER_RESET_TIMBCMP1_TIMERC        (0x1UL << 22U)  /**< 0x00400000 < Timer C compare 1 event (RSTCR) */
#define HRTIM_COUNTER_RESET_TIMCCMP2               (0x1UL << 23U)  /**< 0x00800000 < Timer C compare 2 event         */
#define HRTIM_COUNTER_RESET_TIMBCMP2_TIMERC        (0x1UL << 23U)  /**< 0x00800000 < Timer C compare 2 event (RSTCR) */
#define HRTIM_COUNTER_RESET_TIMCCMP4               (0x1UL << 24U)  /**< 0x01000000 < Timer C compare 4 event         */
#define HRTIM_COUNTER_RESET_TIMBCMP4_TIMERC        (0x1UL << 24U)  /**< 0x01000000 < Timer C compare 4 event (RSTCR) */
#define HRTIM_COUNTER_RESET_TIMDCMP1               (0x1UL << 25U)  /**< 0x02000000 < Timer D compare 1 event         */
#define HRTIM_COUNTER_RESET_TIMCCMP1_TIMERD        (0x1UL << 25U)  /**< 0x02000000 < Timer C compare 1 event (RSTDR) */
#define HRTIM_COUNTER_RESET_TIMDCMP2               (0x1UL << 26U)  /**< 0x04000000 < Timer D compare 2 event         */
#define HRTIM_COUNTER_RESET_TIMCCMP2_TIMERD        (0x1UL << 26U)  /**< 0x04000000 < Timer C compare 2 event (RSTDR) */
#define HRTIM_COUNTER_RESET_TIMDCMP4               (0x1UL << 27U)  /**< 0x08000000 < Timer D compare 4 event         */
#define HRTIM_COUNTER_RESET_TIMCCMP4_TIMERD        (0x1UL << 27U)  /**< 0x08000000 < Timer C compare 4 event (RSTDR) */
#define HRTIM_COUNTER_RESET_TIMECMP1               (0x1UL << 28U)  /**< 0x10000000 < Timer E compare 1 event         */
#define HRTIM_COUNTER_RESET_TIMDCMP1_TIMERE        (0x1UL << 28U)  /**< 0x10000000 < Timer D compare 1 event (RSTER) */
#define HRTIM_COUNTER_RESET_TIMECMP2               (0x1UL << 29U)  /**< 0x20000000 < Timer E compare 2 event         */
#define HRTIM_COUNTER_RESET_TIMDCMP2_TIMERE        (0x1UL << 29U)  /**< 0x20000000 < Timer D compare 2 event (RSTER) */
#define HRTIM_COUNTER_RESET_TIMECMP4               (0x1UL << 30U)  /**< 0x40000000 < Timer E compare 4 event         */
#define HRTIM_COUNTER_RESET_TIMDCMP4_TIMERE        (0x1UL << 30U)  /**< 0x40000000 < Timer D compare 4 event (RSTER) */
#define HRTIM_COUNTER_RESET_TIMFCMP2               (0x1UL << 31U)  /**< 0x80000000 < Timer F compare 2 event         */
#define HRTIM_COUNTER_RESET_TIMECMP2_TIMERF        (0x1UL << 31U)  /**< 0x80000000 < Timer E compare 2 event (RSTFR) */
/** @} */

/**
 * @name    HRTIM ADC Trigger Update Sources
 * @note    Constants defining the source triggering the update of the
 *          HRTIM_ADCxR register (transfer from preload to active register).
 * @{
 */
#define HRTIM_ADCTRIGGERUPDATE_MASTER              0x00000000U      /*!< Master timer */
#define HRTIM_ADCTRIGGERUPDATE_TIMER_A             0x00000001U      /*!< Timer A */
#define HRTIM_ADCTRIGGERUPDATE_TIMER_B             0x00000002U      /*!< Timer B */
#define HRTIM_ADCTRIGGERUPDATE_TIMER_C             0x00000003U      /*!< Timer C */
#define HRTIM_ADCTRIGGERUPDATE_TIMER_D             0x00000004U      /*!< Timer D */
#define HRTIM_ADCTRIGGERUPDATE_TIMER_E             0x00000005U      /*!< Timer E */
#define HRTIM_ADCTRIGGERUPDATE_TIMER_F             0x00000006U      /*!< Timer F */
/** @} */

/**
 * @name    HRTIM UPDATE GATING
 * @note    Constants defining how the update occurs relatively to the burst
 *          DMA transaction and the external update request on update enable
 *          inputs 1 to 3.
 * @{
 */
#define HRTIM_UPDATEGATING_INDEPENDENT             0x00000000U                                                             /*!< Update done independently from the DMA burst transfer completion                                          */
#define HRTIM_UPDATEGATING_DMABURST                (HRTIM_TIMxCR_UPDGAT_0)                                                 /*!< Update done when the DMA burst transfer is completed                                                      */
#define HRTIM_UPDATEGATING_DMABURST_UPDATE         (HRTIM_TIMxCR_UPDGAT_1)                                                 /*!< Update done on timer roll-over following a DMA burst transfer completion                                  */
#define HRTIM_UPDATEGATING_UPDEN1                  (HRTIM_TIMxCR_UPDGAT_1 | HRTIM_TIMxCR_UPDGAT_0)                         /*!< Slave timer only - Update done on a rising edge of HRTIM update enable input 1                            */
#define HRTIM_UPDATEGATING_UPDEN2                  (HRTIM_TIMxCR_UPDGAT_2)                                                 /*!< Slave timer only - Update done on a rising edge of HRTIM update enable input 2                            */
#define HRTIM_UPDATEGATING_UPDEN3                  (HRTIM_TIMxCR_UPDGAT_2 | HRTIM_TIMxCR_UPDGAT_0)                         /*!< Slave timer only - Update done on a rising edge of HRTIM update enable input 3                            */
#define HRTIM_UPDATEGATING_UPDEN1_UPDATE           (HRTIM_TIMxCR_UPDGAT_2 | HRTIM_TIMxCR_UPDGAT_1)                         /*!< Slave timer only - Update done on the update event following a rising edge of HRTIM update enable input 1 */
#define HRTIM_UPDATEGATING_UPDEN2_UPDATE           (HRTIM_TIMxCR_UPDGAT_2 | HRTIM_TIMxCR_UPDGAT_1 | HRTIM_TIMxCR_UPDGAT_0) /*!< Slave timer only - Update done on the update event following a rising edge of HRTIM update enable input 2 */
#define HRTIM_UPDATEGATING_UPDEN3_UPDATE           (HRTIM_TIMxCR_UPDGAT_3)                                                 /*!< Slave timer only - Update done on the update event following a rising edge of HRTIM update enable input 3 */
/** @} */

/**
 * @name    HRTIM Timer Update Trigger
 * @note    Constants defining whether the registers update is done
 *          synchronously with any other timer or master update.
 * @{  
 */
#define HRTIM_TIMUPDATETRIGGER_NONE                0x00000000U           /*!< Register update is disabled                                                                                        */
#define HRTIM_TIMUPDATETRIGGER_MASTER              (HRTIM_TIMxCR_MSTU)   /*!< Register update is triggered by the master timer update                                                            */
#define HRTIM_TIMUPDATETRIGGER_TIMER_A             (HRTIM_TIMxCR_TAU)    /*!< Register update is triggered by the timer A update                                                                 */
#define HRTIM_TIMUPDATETRIGGER_TIMER_B             (HRTIM_TIMxCR_TBU)    /*!< Register update is triggered by the timer B update                                                                 */
#define HRTIM_TIMUPDATETRIGGER_TIMER_C             (HRTIM_TIMxCR_TCU)    /*!< Register update is triggered by the timer C update                                                                 */
#define HRTIM_TIMUPDATETRIGGER_TIMER_D             (HRTIM_TIMxCR_TDU)    /*!< Register update is triggered by the timer D update                                                                 */
#define HRTIM_TIMUPDATETRIGGER_TIMER_E             (HRTIM_TIMxCR_TEU)    /*!< Register update is triggered by the timer E update                                                                 */
#define HRTIM_TIMUPDATETRIGGER_TIMER_F             (HRTIM_TIMxCR_TFU)    /*!< Register update is triggered by the timer F update                                                                 */
#define HRTIM_TIMUPDATETRIGGER_REPETITION          (HRTIM_TIMxCR_TxREPU) /*!< Register update is triggered when the counter rolls over and HRTIM_REPx = 0                                        */
#define HRTIM_TIMUPDATETRIGGER_RESET               (HRTIM_TIMxCR_TxRSTU) /*!< Register update is triggered by counter reset or roll-over to 0 after reaching the period value in continuous mode */
/** @} */

/**
 * @name    HRTIM Software Timer Update 
 * @note    Constants used to force timer registers update.
 * @{ 
 */
#define HRTIM_TIMERUPDATE_MASTER                   (HRTIM_CR2_MSWU)     /*!< Force an immediate transfer from the preload to the active register in the master timer */
#define HRTIM_TIMERUPDATE_A                        (HRTIM_CR2_TASWU)    /*!< Force an immediate transfer from the preload to the active register in the timer A      */
#define HRTIM_TIMERUPDATE_B                        (HRTIM_CR2_TBSWU)    /*!< Force an immediate transfer from the preload to the active register in the timer B      */
#define HRTIM_TIMERUPDATE_C                        (HRTIM_CR2_TCSWU)    /*!< Force an immediate transfer from the preload to the active register in the timer C      */
#define HRTIM_TIMERUPDATE_D                        (HRTIM_CR2_TDSWU)    /*!< Force an immediate transfer from the preload to the active register in the timer D      */
#define HRTIM_TIMERUPDATE_E                        (HRTIM_CR2_TESWU)    /*!< Force an immediate transfer from the preload to the active register in the timer E      */
#define HRTIM_TIMERUPDATE_F                        (HRTIM_CR2_TFSWU)    /*!< Force an immediate transfer from the preload to the active register in the timer F      */
/** @} */

/**
 * @name    HRTIM_ADC_Trigger_Event HRTIM ADC Trigger Event
 * @note    Constants defining the events triggering ADC conversion.
 *          HRTIM_ADCTRIGGEREVENT13_*  : ADC Triggers 1 and 3
 *          HRTIM_ADCTRIGGEREVENT24_*  : ADC Triggers 2 and 4
 *          HRTIM_ADCTRIGGEREVENT579_* : ADC Triggers 5 and 7 and 9
 *          HRTIM_ADCTRIGGEREVENT6810_*: ADC Triggers 6 and 8 and 10
 * @{  
 */
#define  HRTIM_ADCTRIGGEREVENT13_NONE             0x00000000U      /**< No ADC trigger event              */
#define  HRTIM_ADCTRIGGEREVENT13_MASTER_CMP1      0x00000001U      /**< ADC Trigger on master compare 1U  */
#define  HRTIM_ADCTRIGGEREVENT13_MASTER_CMP2      0x00000002U      /*!< ADC Trigger on master compare 2U  */
#define  HRTIM_ADCTRIGGEREVENT13_MASTER_CMP3      0x00000004U      /*!< ADC Trigger on master compare 3U  */
#define  HRTIM_ADCTRIGGEREVENT13_MASTER_CMP4      0x00000008U      /*!< ADC Trigger on master compare 4U  */
#define  HRTIM_ADCTRIGGEREVENT13_MASTER_PERIOD    0x00000010U      /*!< ADC Trigger on master period      */
#define  HRTIM_ADCTRIGGEREVENT13_EVENT_1          0x00000020U      /*!< ADC Trigger on external event 1U  */
#define  HRTIM_ADCTRIGGEREVENT13_EVENT_2          0x00000040U      /*!< ADC Trigger on external event 2U  */
#define  HRTIM_ADCTRIGGEREVENT13_EVENT_3          0x00000080U      /*!< ADC Trigger on external event 3U  */
#define  HRTIM_ADCTRIGGEREVENT13_EVENT_4          0x00000100U      /*!< ADC Trigger on external event 4U  */
#define  HRTIM_ADCTRIGGEREVENT13_EVENT_5          0x00000200U      /*!< ADC Trigger on external event 5U  */
#define  HRTIM_ADCTRIGGEREVENT13_TIMERF_CMP2      0x00000400U      /*!< ADC Trigger on Timer F compare 2U */
#define  HRTIM_ADCTRIGGEREVENT13_TIMERA_CMP3      0x00000800U      /*!< ADC Trigger on Timer A compare 3U */
#define  HRTIM_ADCTRIGGEREVENT13_TIMERA_CMP4      0x00001000U      /*!< ADC Trigger on Timer A compare 4U */
#define  HRTIM_ADCTRIGGEREVENT13_TIMERA_PERIOD    0x00002000U      /*!< ADC Trigger on Timer A period     */
#define  HRTIM_ADCTRIGGEREVENT13_TIMERA_RESET     0x00004000U      /*!< ADC Trigger on Timer A reset      */
#define  HRTIM_ADCTRIGGEREVENT13_TIMERF_CMP3      0x00008000U      /*!< ADC Trigger on Timer F compare 3U */
#define  HRTIM_ADCTRIGGEREVENT13_TIMERB_CMP3      0x00010000U      /*!< ADC Trigger on Timer B compare 3U */
#define  HRTIM_ADCTRIGGEREVENT13_TIMERB_CMP4      0x00020000U      /*!< ADC Trigger on Timer B compare 4U */
#define  HRTIM_ADCTRIGGEREVENT13_TIMERB_PERIOD    0x00040000U      /*!< ADC Trigger on Timer B period     */
#define  HRTIM_ADCTRIGGEREVENT13_TIMERB_RESET     0x00080000U      /*!< ADC Trigger on Timer B reset      */
#define  HRTIM_ADCTRIGGEREVENT13_TIMERF_CMP4      0x00100000U      /*!< ADC Trigger on Timer F compare 4U */
#define  HRTIM_ADCTRIGGEREVENT13_TIMERC_CMP3      0x00200000U      /*!< ADC Trigger on Timer C compare 3U */
#define  HRTIM_ADCTRIGGEREVENT13_TIMERC_CMP4      0x00400000U      /*!< ADC Trigger on Timer C compare 4U */
#define  HRTIM_ADCTRIGGEREVENT13_TIMERC_PERIOD    0x00800000U      /*!< ADC Trigger on Timer C period     */
#define  HRTIM_ADCTRIGGEREVENT13_TIMERF_PERIOD    0x01000000U      /*!< ADC Trigger on Timer F period     */
#define  HRTIM_ADCTRIGGEREVENT13_TIMERD_CMP3      0x02000000U      /*!< ADC Trigger on Timer D compare 3U */
#define  HRTIM_ADCTRIGGEREVENT13_TIMERD_CMP4      0x04000000U      /*!< ADC Trigger on Timer D compare 4U */
#define  HRTIM_ADCTRIGGEREVENT13_TIMERD_PERIOD    0x08000000U      /*!< ADC Trigger on Timer D period     */
#define  HRTIM_ADCTRIGGEREVENT13_TIMERF_RESET     0x10000000U      /*!< ADC Trigger on Timer F reset      */
#define  HRTIM_ADCTRIGGEREVENT13_TIMERE_CMP3      0x20000000U      /*!< ADC Trigger on Timer E compare 3U */
#define  HRTIM_ADCTRIGGEREVENT13_TIMERE_CMP4      0x40000000U      /*!< ADC Trigger on Timer E compare 4U */
#define  HRTIM_ADCTRIGGEREVENT13_TIMERE_PERIOD    0x80000000U      /*!< ADC Trigger on Timer E period     */

#define  HRTIM_ADCTRIGGEREVENT24_NONE             0x00000000U      /**< No ADC trigger event              */
#define  HRTIM_ADCTRIGGEREVENT24_MASTER_CMP1      0x00000001U      /**< ADC Trigger on master compare 1U  */
#define  HRTIM_ADCTRIGGEREVENT24_MASTER_CMP2      0x00000002U      /*!< ADC Trigger on master compare 2U  */
#define  HRTIM_ADCTRIGGEREVENT24_MASTER_CMP3      0x00000004U      /*!< ADC Trigger on master compare 3U  */
#define  HRTIM_ADCTRIGGEREVENT24_MASTER_CMP4      0x00000008U      /*!< ADC Trigger on master compare 4U  */
#define  HRTIM_ADCTRIGGEREVENT24_MASTER_PERIOD    0x00000010U      /*!< ADC Trigger on master period      */
#define  HRTIM_ADCTRIGGEREVENT24_EVENT_6          0x00000020U      /*!< ADC Trigger on external event 1U  */
#define  HRTIM_ADCTRIGGEREVENT24_EVENT_7          0x00000040U      /*!< ADC Trigger on external event 2U  */
#define  HRTIM_ADCTRIGGEREVENT24_EVENT_8          0x00000080U      /*!< ADC Trigger on external event 3U  */
#define  HRTIM_ADCTRIGGEREVENT24_EVENT_9          0x00000100U      /*!< ADC Trigger on external event 4U  */
#define  HRTIM_ADCTRIGGEREVENT24_EVENT_10         0x00000200U      /*!< ADC Trigger on external event 5U  */
#define  HRTIM_ADCTRIGGEREVENT24_TIMERA_CMP2      0x00000400U      /*!< ADC Trigger on Timer F compare 2U */
#define  HRTIM_ADCTRIGGEREVENT24_TIMERF_CMP2      0x00000800U      /*!< ADC Trigger on Timer A compare 3U */
#define  HRTIM_ADCTRIGGEREVENT24_TIMERA_CMP4      0x00001000U      /*!< ADC Trigger on Timer A compare 4U */
#define  HRTIM_ADCTRIGGEREVENT24_TIMERA_PERIOD    0x00002000U      /*!< ADC Trigger on Timer A period     */
#define  HRTIM_ADCTRIGGEREVENT24_TIMERB_CMP2      0x00004000U      /*!< ADC Trigger on Timer A reset      */
#define  HRTIM_ADCTRIGGEREVENT24_TIMERF_CMP3      0x00008000U      /*!< ADC Trigger on Timer F compare 3U */
#define  HRTIM_ADCTRIGGEREVENT24_TIMERB_CMP4      0x00010000U      /*!< ADC Trigger on Timer B compare 3U */
#define  HRTIM_ADCTRIGGEREVENT24_TIMERB_PERIOD    0x00020000U      /*!< ADC Trigger on Timer B compare 4U */
#define  HRTIM_ADCTRIGGEREVENT24_TIMERC_CMP2      0x00040000U      /*!< ADC Trigger on Timer B period     */
#define  HRTIM_ADCTRIGGEREVENT24_TIMERF_CMP4      0x00080000U      /*!< ADC Trigger on Timer B reset      */
#define  HRTIM_ADCTRIGGEREVENT24_TIMERC_CMP4      0x00100000U      /*!< ADC Trigger on Timer F compare 4U */
#define  HRTIM_ADCTRIGGEREVENT24_TIMERC_PERIOD    0x00200000U      /*!< ADC Trigger on Timer C compare 3U */
#define  HRTIM_ADCTRIGGEREVENT24_TIMERC_RESET     0x00400000U      /*!< ADC Trigger on Timer C compare 4U */
#define  HRTIM_ADCTRIGGEREVENT24_TIMERD_CMP2      0x00800000U      /*!< ADC Trigger on Timer C period     */
#define  HRTIM_ADCTRIGGEREVENT24_TIMERF_PERIOD    0x01000000U      /*!< ADC Trigger on Timer F period     */
#define  HRTIM_ADCTRIGGEREVENT24_TIMERD_CMP4      0x02000000U      /*!< ADC Trigger on Timer D compare 3U */
#define  HRTIM_ADCTRIGGEREVENT24_TIMERD_PERIOD    0x04000000U      /*!< ADC Trigger on Timer D compare 4U */
#define  HRTIM_ADCTRIGGEREVENT24_TIMERD_RESET     0x08000000U      /*!< ADC Trigger on Timer D period     */
#define  HRTIM_ADCTRIGGEREVENT24_TIMERE_CMP2      0x10000000U      /*!< ADC Trigger on Timer F reset      */
#define  HRTIM_ADCTRIGGEREVENT24_TIMERE_CMP3      0x20000000U      /*!< ADC Trigger on Timer E compare 3U */
#define  HRTIM_ADCTRIGGEREVENT24_TIMERE_CMP4      0x40000000U      /*!< ADC Trigger on Timer E compare 4U */
#define  HRTIM_ADCTRIGGEREVENT24_TIMERE_RESET     0x80000000U      /*!< ADC Trigger on Timer E period     */

#define  HRTIM_ADCTRIGGEREVENT579_NONE            0x00000000U      /**< No ADC trigger event              */
#define  HRTIM_ADCTRIGGEREVENT579_MASTER_CMP1     0x00000001U      /*!< ADC Trigger on master compare 1U  */
#define  HRTIM_ADCTRIGGEREVENT579_MASTER_CMP2     0x00000002U      /*!< ADC Trigger on master compare 2U  */
#define  HRTIM_ADCTRIGGEREVENT579_MASTER_CMP3     0x00000004U      /*!< ADC Trigger on master compare 3U  */
#define  HRTIM_ADCTRIGGEREVENT579_MASTER_CMP4     0x00000008U      /*!< ADC Trigger on master compare 4U  */
#define  HRTIM_ADCTRIGGEREVENT579_MASTER_PERIOD   0x00000010U      /*!< ADC Trigger on master period      */
#define  HRTIM_ADCTRIGGEREVENT579_EVENT_1         0x00000020U      /*!< ADC Trigger on external event 1U  */
#define  HRTIM_ADCTRIGGEREVENT579_EVENT_2         0x00000040U      /*!< ADC Trigger on external event 2U  */
#define  HRTIM_ADCTRIGGEREVENT579_EVENT_3         0x00000080U      /*!< ADC Trigger on external event 3U  */
#define  HRTIM_ADCTRIGGEREVENT579_EVENT_4         0x00000100U      /*!< ADC Trigger on external event 4U  */
#define  HRTIM_ADCTRIGGEREVENT579_EVENT_5         0x00000200U      /*!< ADC Trigger on external event 5U  */
#define  HRTIM_ADCTRIGGEREVENT579_TIMERA_CMP3     0x00000400U      /*!< ADC Trigger on Timer A compare 3U */
#define  HRTIM_ADCTRIGGEREVENT579_TIMERA_CMP4     0x00000800U      /*!< ADC Trigger on Timer A compare 4U */
#define  HRTIM_ADCTRIGGEREVENT579_TIMERA_PERIOD   0x00001000U      /*!< ADC Trigger on Timer A period     */
#define  HRTIM_ADCTRIGGEREVENT579_TIMERA_RESET    0x00002000U      /*!< ADC Trigger on Timer A reset      */
#define  HRTIM_ADCTRIGGEREVENT579_TIMERB_CMP3     0x00004000U      /*!< ADC Trigger on Timer B compare 3U */
#define  HRTIM_ADCTRIGGEREVENT579_TIMERB_CMP4     0x00008000U      /*!< ADC Trigger on Timer B compare 4U */
#define  HRTIM_ADCTRIGGEREVENT579_TIMERB_PERIOD   0x00010000U      /*!< ADC Trigger on Timer B period     */
#define  HRTIM_ADCTRIGGEREVENT579_TIMERB_RESET    0x00020000U      /*!< ADC Trigger on Timer B reset      */
#define  HRTIM_ADCTRIGGEREVENT579_TIMERC_CMP3     0x00040000U      /*!< ADC Trigger on Timer C compare 3U */
#define  HRTIM_ADCTRIGGEREVENT579_TIMERC_CMP4     0x00080000U      /*!< ADC Trigger on Timer C compare 4U */
#define  HRTIM_ADCTRIGGEREVENT579_TIMERC_PERIOD   0x00100000U      /*!< ADC Trigger on Timer C period     */
#define  HRTIM_ADCTRIGGEREVENT579_TIMERD_CMP3     0x00200000U      /*!< ADC Trigger on Timer D compare 3U */
#define  HRTIM_ADCTRIGGEREVENT579_TIMERD_CMP4     0x00400000U      /*!< ADC Trigger on Timer D compare 4U */
#define  HRTIM_ADCTRIGGEREVENT579_TIMERD_PERIOD   0x00800000U      /*!< ADC Trigger on Timer D period     */
#define  HRTIM_ADCTRIGGEREVENT579_TIMERE_CMP3     0x01000000U      /*!< ADC Trigger on Timer E compare 3U */
#define  HRTIM_ADCTRIGGEREVENT579_TIMERE_CMP4     0x02000000U      /*!< ADC Trigger on Timer E compare 4U */
#define  HRTIM_ADCTRIGGEREVENT579_TIMERE_PERIOD   0x04000000U      /*!< ADC Trigger on Timer E period     */
#define  HRTIM_ADCTRIGGEREVENT579_TIMERF_CMP2     0x08000000U      /*!< ADC Trigger on Timer F compare 2U */
#define  HRTIM_ADCTRIGGEREVENT579_TIMERF_CMP3     0x10000000U      /*!< ADC Trigger on Timer F compare 3U */
#define  HRTIM_ADCTRIGGEREVENT579_TIMERF_CMP4     0x20000000U      /*!< ADC Trigger on Timer F compare 4U */
#define  HRTIM_ADCTRIGGEREVENT579_TIMERF_PERIOD   0x40000000U      /*!< ADC Trigger on Timer F period     */
#define  HRTIM_ADCTRIGGEREVENT579_TIMERF_RESET    0x80000000U      /*!< ADC Trigger on Timer F reset      */

#define  HRTIM_ADCTRIGGEREVENT6810_NONE           0x00000000U      /**< No ADC trigger event              */
#define  HRTIM_ADCTRIGGEREVENT6810_MASTER_CMP1    0x00000001U      /*!< ADC Trigger on master compare 1U  */
#define  HRTIM_ADCTRIGGEREVENT6810_MASTER_CMP2    0x00000002U      /*!< ADC Trigger on master compare 2U  */
#define  HRTIM_ADCTRIGGEREVENT6810_MASTER_CMP3    0x00000004U      /*!< ADC Trigger on master compare 3U  */
#define  HRTIM_ADCTRIGGEREVENT6810_MASTER_CMP4    0x00000008U      /*!< ADC Trigger on master compare 4U  */
#define  HRTIM_ADCTRIGGEREVENT6810_MASTER_PERIOD  0x00000010U      /*!< ADC Trigger on master period      */
#define  HRTIM_ADCTRIGGEREVENT6810_EVENT_6        0x00000020U      /*!< ADC Trigger on external event 6U  */
#define  HRTIM_ADCTRIGGEREVENT6810_EVENT_7        0x00000040U      /*!< ADC Trigger on external event 7U  */
#define  HRTIM_ADCTRIGGEREVENT6810_EVENT_8        0x00000080U      /*!< ADC Trigger on external event 8U  */
#define  HRTIM_ADCTRIGGEREVENT6810_EVENT_9        0x00000100U      /*!< ADC Trigger on external event 9U  */
#define  HRTIM_ADCTRIGGEREVENT6810_EVENT_10       0x00000200U      /*!< ADC Trigger on external event 10U */
#define  HRTIM_ADCTRIGGEREVENT6810_TIMERA_CMP2    0x00000400U      /*!< ADC Trigger on Timer A compare 2U */
#define  HRTIM_ADCTRIGGEREVENT6810_TIMERA_CMP4    0x00000800U      /*!< ADC Trigger on Timer A compare 4U */
#define  HRTIM_ADCTRIGGEREVENT6810_TIMERA_PERIOD  0x00001000U      /*!< ADC Trigger on Timer A period     */
#define  HRTIM_ADCTRIGGEREVENT6810_TIMERB_CMP2    0x00002000U      /*!< ADC Trigger on Timer B compare 2U */
#define  HRTIM_ADCTRIGGEREVENT6810_TIMERB_CMP4    0x00004000U      /*!< ADC Trigger on Timer B compare 4U */
#define  HRTIM_ADCTRIGGEREVENT6810_TIMERB_PERIOD  0x00008000U      /*!< ADC Trigger on Timer B period     */
#define  HRTIM_ADCTRIGGEREVENT6810_TIMERC_CMP2    0x00010000U      /*!< ADC Trigger on Timer C compare 2U */
#define  HRTIM_ADCTRIGGEREVENT6810_TIMERC_CMP4    0x00020000U      /*!< ADC Trigger on Timer C compare 4U */
#define  HRTIM_ADCTRIGGEREVENT6810_TIMERC_PERIOD  0x00040000U      /*!< ADC Trigger on Timer C period     */
#define  HRTIM_ADCTRIGGEREVENT6810_TIMERC_RESET   0x00080000U      /*!< ADC Trigger on Timer C reset      */
#define  HRTIM_ADCTRIGGEREVENT6810_TIMERD_CMP2    0x00100000U      /*!< ADC Trigger on Timer D compare 2U */
#define  HRTIM_ADCTRIGGEREVENT6810_TIMERD_CMP4    0x00200000U      /*!< ADC Trigger on Timer D compare 4U */
#define  HRTIM_ADCTRIGGEREVENT6810_TIMERD_PERIOD  0x00400000U      /*!< ADC Trigger on Timer D period     */
#define  HRTIM_ADCTRIGGEREVENT6810_TIMERD_RESET   0x00800000U      /*!< ADC Trigger on Timer D reset      */
#define  HRTIM_ADCTRIGGEREVENT6810_TIMERE_CMP2    0x01000000U      /*!< ADC Trigger on Timer E compare 2U */
#define  HRTIM_ADCTRIGGEREVENT6810_TIMERE_CMP3    0x02000000U      /*!< ADC Trigger on Timer E compare 3U */
#define  HRTIM_ADCTRIGGEREVENT6810_TIMERE_CMP4    0x04000000U      /*!< ADC Trigger on Timer E compare 4U */
#define  HRTIM_ADCTRIGGEREVENT6810_TIMERE_RESET   0x08000000U      /*!< ADC Trigger on Timer E reset      */
#define  HRTIM_ADCTRIGGEREVENT6810_TIMERF_CMP2    0x10000000U      /*!< ADC Trigger on Timer F compare 2U */
#define  HRTIM_ADCTRIGGEREVENT6810_TIMERF_CMP3    0x20000000U      /*!< ADC Trigger on Timer F compare 3U */
#define  HRTIM_ADCTRIGGEREVENT6810_TIMERF_CMP4    0x40000000U      /*!< ADC Trigger on Timer F compare 4U */
#define  HRTIM_ADCTRIGGEREVENT6810_TIMERF_PERIOD  0x80000000U      /*!< ADC Trigger on Timer F period     */
/** @} */

/**
 * @name    HRTIM_External_Event_Channels HRTIM External Event Channels
 * @note    Constants defining external event channel identifiers.
 * @{  
 */
#define HRTIM_EVENT_NONE    (0x00000000U)     /*!< Undefined event channel              */
#define HRTIM_EVENT_1       (0x00000001U)     /*!< External event channel 1  identifier */
#define HRTIM_EVENT_2       (0x00000002U)     /*!< External event channel 2  identifier */
#define HRTIM_EVENT_3       (0x00000003U)     /*!< External event channel 3  identifier */
#define HRTIM_EVENT_4       (0x00000004U)     /*!< External event channel 4  identifier */
#define HRTIM_EVENT_5       (0x00000005U)     /*!< External event channel 5  identifier */
#define HRTIM_EVENT_6       (0x00000006U)     /*!< External event channel 6  identifier */
#define HRTIM_EVENT_7       (0x00000007U)     /*!< External event channel 7  identifier */
#define HRTIM_EVENT_8       (0x00000008U)     /*!< External event channel 8  identifier */
#define HRTIM_EVENT_9       (0x00000009U)     /*!< External event channel 9  identifier */
#define HRTIM_EVENT_10      (0x0000000AU)     /*!< External event channel 10 identifier */
/** @} */

/**
 * @name    HRTIM1 External Event Sources
 * @note    Constants defining available sources associated to external events.
 * @{  
 */
#define HRTIM1_EEV1SRC_GPIO        0x00000000U    /*!< External event source 1U for External Event 1  */
#define HRTIM1_EEV2SRC_GPIO        0x00000000U    /*!< External event source 1U for External Event 2  */
#define HRTIM1_EEV3SRC_GPIO        0x00000000U    /*!< External event source 1U for External Event 3  */
#define HRTIM1_EEV4SRC_GPIO        0x00000000U    /*!< External event source 1U for External Event 4  */
#define HRTIM1_EEV5SRC_GPIO        0x00000000U    /*!< External event source 1U for External Event 5  */
#define HRTIM1_EEV6SRC_GPIO        0x00000000U    /*!< External event source 1U for External Event 6  */
#define HRTIM1_EEV7SRC_GPIO        0x00000000U    /*!< External event source 1U for External Event 7  */
#define HRTIM1_EEV8SRC_GPIO        0x00000000U    /*!< External event source 1U for External Event 8  */
#define HRTIM1_EEV9SRC_GPIO        0x00000000U    /*!< External event source 1U for External Event 9  */
#define HRTIM1_EEV10SRC_GPIO       0x00000000U    /*!< External event source 1U for External Event 10 */
#define HRTIM1_EEV1SRC_COMP2_OUT   0x00000001U    /*!< External event source 2U for External Event 1  */
#define HRTIM1_EEV2SRC_COMP4_OUT   0x00000001U    /*!< External event source 2U for External Event 2  */
#define HRTIM1_EEV3SRC_COMP6_OUT   0x00000001U    /*!< External event source 2U for External Event 3  */
#define HRTIM1_EEV4SRC_COMP1_OUT   0x00000001U    /*!< External event source 2U for External Event 4  */
#define HRTIM1_EEV5SRC_COMP3_OUT   0x00000001U    /*!< External event source 2U for External Event 5  */
#define HRTIM1_EEV6SRC_COMP2_OUT   0x00000001U    /*!< External event source 2U for External Event 6  */
#define HRTIM1_EEV7SRC_COMP4_OUT   0x00000001U    /*!< External event source 2U for External Event 7  */
#define HRTIM1_EEV8SRC_COMP6_OUT   0x00000001U    /*!< External event source 2U for External Event 8  */
#define HRTIM1_EEV9SRC_COMP5_OUT   0x00000001U    /*!< External event source 2U for External Event 9  */
#define HRTIM1_EEV10SRC_COMP7_OUT  0x00000001U    /*!< External event source 2U for External Event 10 */
#define HRTIM1_EEV1SRC_TIM1_TRGO   0x00000002U    /*!< External event source 3U for External Event 1  */
#define HRTIM1_EEV2SRC_TIM2_TRGO   0x00000002U    /*!< External event source 3U for External Event 2  */
#define HRTIM1_EEV3SRC_TIM3_TRGO   0x00000002U    /*!< External event source 3U for External Event 3  */
#define HRTIM1_EEV4SRC_COMP5_OUT   0x00000002U    /*!< External event source 3U for External Event 4  */
#define HRTIM1_EEV5SRC_COMP7_OUT   0x00000002U    /*!< External event source 3U for External Event 5  */
#define HRTIM1_EEV6SRC_COMP1_OUT   0x00000002U    /*!< External event source 3U for External Event 6  */
#define HRTIM1_EEV7SRC_TIM7_TRGO   0x00000002U    /*!< External event source 3U for External Event 7  */
#define HRTIM1_EEV8SRC_COMP3_OUT   0x00000002U    /*!< External event source 3U for External Event 8  */
#define HRTIM1_EEV9SRC_TIM15_TRGO  0x00000002U    /*!< External event source 3U for External Event 9  */
#define HRTIM1_EEV10SRC_TIM6_TRGO  0x00000002U    /*!< External event source 3U for External Event 10 */
#define HRTIM1_EEV1SRC_ADC1_AWD1   0x00000003U    /*!< External event source 4U for External Event 1  */
#define HRTIM1_EEV2SRC_ADC1_AWD2   0x00000003U    /*!< External event source 4U for External Event 2  */
#define HRTIM1_EEV3SRC_ADC1_AWD3   0x00000003U    /*!< External event source 4U for External Event 3  */
#define HRTIM1_EEV4SRC_ADC2_AWD1   0x00000003U    /*!< External event source 4U for External Event 4  */
#define HRTIM1_EEV5SRC_ADC2_AWD2   0x00000003U    /*!< External event source 4U for External Event 5  */
#define HRTIM1_EEV6SRC_ADC2_AWD3   0x00000003U    /*!< External event source 4U for External Event 6  */
#define HRTIM1_EEV7SRC_ADC3_AWD1   0x00000003U    /*!< External event source 4U for External Event 7  */
#define HRTIM1_EEV8SRC_ADC4_AWD1   0x00000003U    /*!< External event source 4U for External Event 8  */
#define HRTIM1_EEV9SRC_COMP4_OUT   0x00000003U    /*!< External event source 4U for External Event 9  */
#define HRTIM1_EEV10SRC_ADC5_AWD1  0x00000003U    /*!< External event source 4U for External Event 10 */ 
/** @} */

/**
 * @name    HRTIM2 External Event Sources
 * @note    Constants defining available sources associated to external events.
 * @{  
 */
#define HRTIM2_EEV1SRC_GPIO        0x00000000U    /*!< External event source 1U for External Event 1  */
#define HRTIM2_EEV2SRC_GPIO        0x00000000U    /*!< External event source 1U for External Event 2  */
#define HRTIM2_EEV3SRC_GPIO        0x00000000U    /*!< External event source 1U for External Event 3  */
#define HRTIM2_EEV4SRC_GPIO        0x00000000U    /*!< External event source 1U for External Event 4  */
#define HRTIM2_EEV5SRC_GPIO        0x00000000U    /*!< External event source 1U for External Event 5  */
#define HRTIM2_EEV6SRC_GPIO        0x00000000U    /*!< External event source 1U for External Event 6  */
#define HRTIM2_EEV7SRC_GPIO        0x00000000U    /*!< External event source 1U for External Event 7  */
#define HRTIM2_EEV8SRC_GPIO        0x00000000U    /*!< External event source 1U for External Event 8  */
#define HRTIM2_EEV9SRC_GPIO        0x00000000U    /*!< External event source 1U for External Event 9  */
#define HRTIM2_EEV10SRC_GPIO       0x00000000U    /*!< External event source 1U for External Event 10 */
#define HRTIM2_EEV1SRC_COMP1_OUT   0x00000001U    /*!< External event source 2U for External Event 1  */
#define HRTIM2_EEV2SRC_COMP3_OUT   0x00000001U    /*!< External event source 2U for External Event 2  */
#define HRTIM2_EEV3SRC_COMP5_OUT   0x00000001U    /*!< External event source 2U for External Event 3  */
#define HRTIM2_EEV4SRC_COMP2_OUT   0x00000001U    /*!< External event source 2U for External Event 4  */
#define HRTIM2_EEV5SRC_COMP4_OUT   0x00000001U    /*!< External event source 2U for External Event 5  */
#define HRTIM2_EEV6SRC_COMP1_OUT   0x00000001U    /*!< External event source 2U for External Event 6  */
#define HRTIM2_EEV7SRC_COMP3_OUT   0x00000001U    /*!< External event source 2U for External Event 7  */
#define HRTIM2_EEV8SRC_COMP5_OUT   0x00000001U    /*!< External event source 2U for External Event 8  */
#define HRTIM2_EEV9SRC_COMP6_OUT   0x00000001U    /*!< External event source 2U for External Event 9  */
#define HRTIM2_EEV10SRC_COMP8_OUT  0x00000001U    /*!< External event source 2U for External Event 10 */
#define HRTIM2_EEV1SRC_TIM1_TRGO   0x00000002U    /*!< External event source 3U for External Event 1  */
#define HRTIM2_EEV2SRC_TIM2_TRGO   0x00000002U    /*!< External event source 3U for External Event 2  */
#define HRTIM2_EEV3SRC_TIM3_TRGO   0x00000002U    /*!< External event source 3U for External Event 3  */
#define HRTIM2_EEV4SRC_COMP6_OUT   0x00000002U    /*!< External event source 3U for External Event 4  */
#define HRTIM2_EEV5SRC_COMP8_OUT   0x00000002U    /*!< External event source 3U for External Event 5  */
#define HRTIM2_EEV6SRC_COMP2_OUT   0x00000002U    /*!< External event source 3U for External Event 6  */
#define HRTIM2_EEV7SRC_TIM7_TRGO   0x00000002U    /*!< External event source 3U for External Event 7  */
#define HRTIM2_EEV8SRC_COMP4_OUT   0x00000002U    /*!< External event source 3U for External Event 8  */
#define HRTIM2_EEV9SRC_TIM15_TRGO  0x00000002U    /*!< External event source 3U for External Event 9  */
#define HRTIM2_EEV10SRC_TIM6_TRGO  0x00000002U    /*!< External event source 3U for External Event 10 */
#define HRTIM2_EEV1SRC_ADC1_AWD1   0x00000003U    /*!< External event source 4U for External Event 1  */
#define HRTIM2_EEV2SRC_ADC1_AWD2   0x00000003U    /*!< External event source 4U for External Event 2  */
#define HRTIM2_EEV3SRC_ADC1_AWD3   0x00000003U    /*!< External event source 4U for External Event 3  */
#define HRTIM2_EEV4SRC_ADC2_AWD1   0x00000003U    /*!< External event source 4U for External Event 4  */
#define HRTIM2_EEV5SRC_ADC2_AWD2   0x00000003U    /*!< External event source 4U for External Event 5  */
#define HRTIM2_EEV6SRC_ADC2_AWD3   0x00000003U    /*!< External event source 4U for External Event 6  */
#define HRTIM2_EEV7SRC_ADC3_AWD1   0x00000003U    /*!< External event source 4U for External Event 7  */
#define HRTIM2_EEV8SRC_ADC4_AWD1   0x00000003U    /*!< External event source 4U for External Event 8  */
#define HRTIM2_EEV9SRC_COMP4_OUT   0x00000003U    /*!< External event source 4U for External Event 9  */
#define HRTIM2_EEV10SRC_ADC5_AWD1  0x00000003U    /*!< External event source 4U for External Event 10 */ 
/** @} */

/**
 * @name    HRTIM External Event Polarity
 * @note    Constants defining the polarity of an external event.
 * @{  
 */
#define HRTIM_EVENTPOLARITY_HIGH    (0x00000000U)                                            /*!< External event is active high */
#define HRTIM_EVENTPOLARITY_LOW     (0x00000004U)                                            /*!< External event is active low  */
/** @} */

/**
 * @name    HRTIM External Event Fast Mode
 * @note    Constants defining whether or not an external event is programmed
 *          in fast mode.
 * @{  
 */
#define HRTIM_EVENTFASTMODE_DISABLE    (0x00000000U)                                         /*!< External Event is re-synchronized by the HRTIM logic before acting on outputs */
#define HRTIM_EVENTFASTMODE_ENABLE     (0x00000020U)                                         /*!< External Event is acting asynchronously on outputs (low latency mode)         */
/** @} */

/**
 * @name    HRTIM External Event Sensitivity
 * @note    Constants defining the sensitivity (level-sensitive or
 *          edge-sensitive) of an external event.
 * @{ 
 */
#define HRTIM_EVENTSENSITIVITY_LEVEL          (0x00000000U)                                  /*!< External event is active on level                    */
#define HRTIM_EVENTSENSITIVITY_RISINGEDGE     (HRTIM_EECR1_EE1SNS_0)                         /*!< External event is active on Rising edge              */
#define HRTIM_EVENTSENSITIVITY_FALLINGEDGE    (HRTIM_EECR1_EE1SNS_1)                         /*!< External event is active on Falling edge             */
#define HRTIM_EVENTSENSITIVITY_BOTHEDGES      (HRTIM_EECR1_EE1SNS_1 | HRTIM_EECR1_EE1SNS_0)  /*!< External event is active on Rising and Falling edges */
/** @} */

/**
 * @name    HRTIM External Event Filter
 * @note    Constants defining the frequency used to sample an external event 6
 *          input and the length (N) of the digital filter applied.
 * @{  
 */
#define HRTIM_EVENTFILTER_NONE      (0x00000000U)                                                                         /*!< Filter disabled            */
#define HRTIM_EVENTFILTER_1         (HRTIM_EECR3_EE6F_0)                                                                  /*!< fSAMPLING= fHRTIM, N=2U    */
#define HRTIM_EVENTFILTER_2         (HRTIM_EECR3_EE6F_1)                                                                  /*!< fSAMPLING= fHRTIM, N=4U    */
#define HRTIM_EVENTFILTER_3         (HRTIM_EECR3_EE6F_1 | HRTIM_EECR3_EE6F_0)                                             /*!< fSAMPLING= fHRTIM, N=8U    */
#define HRTIM_EVENTFILTER_4         (HRTIM_EECR3_EE6F_2)                                                                  /*!< fSAMPLING= fEEVS/2U, N=6U  */
#define HRTIM_EVENTFILTER_5         (HRTIM_EECR3_EE6F_2 | HRTIM_EECR3_EE6F_0)                                             /*!< fSAMPLING= fEEVS/2U, N=8U  */
#define HRTIM_EVENTFILTER_6         (HRTIM_EECR3_EE6F_2 | HRTIM_EECR3_EE6F_1)                                             /*!< fSAMPLING= fEEVS/4U, N=6U  */
#define HRTIM_EVENTFILTER_7         (HRTIM_EECR3_EE6F_2 | HRTIM_EECR3_EE6F_1 | HRTIM_EECR3_EE6F_0)                        /*!< fSAMPLING= fEEVS/4U, N=8U  */
#define HRTIM_EVENTFILTER_8         (HRTIM_EECR3_EE6F_3)                                                                  /*!< fSAMPLING= fEEVS/8U, N=6U  */
#define HRTIM_EVENTFILTER_9         (HRTIM_EECR3_EE6F_3 | HRTIM_EECR3_EE6F_0)                                             /*!< fSAMPLING= fEEVS/8U, N=8U  */
#define HRTIM_EVENTFILTER_10        (HRTIM_EECR3_EE6F_3 | HRTIM_EECR3_EE6F_1)                                             /*!< fSAMPLING= fEEVS/16U, N=5U */
#define HRTIM_EVENTFILTER_11        (HRTIM_EECR3_EE6F_3 | HRTIM_EECR3_EE6F_1 | HRTIM_EECR3_EE6F_0)                        /*!< fSAMPLING= fEEVS/16U, N=6U */
#define HRTIM_EVENTFILTER_12        (HRTIM_EECR3_EE6F_3 | HRTIM_EECR3_EE6F_2)                                             /*!< fSAMPLING= fEEVS/16U, N=8U */
#define HRTIM_EVENTFILTER_13        (HRTIM_EECR3_EE6F_3 | HRTIM_EECR3_EE6F_2  | HRTIM_EECR3_EE6F_0)                       /*!< fSAMPLING= fEEVS/32U, N=5U */
#define HRTIM_EVENTFILTER_14        (HRTIM_EECR3_EE6F_3 | HRTIM_EECR3_EE6F_2  | HRTIM_EECR3_EE6F_1)                       /*!< fSAMPLING= fEEVS/32U, N=6U */
#define HRTIM_EVENTFILTER_15        (HRTIM_EECR3_EE6F_3 | HRTIM_EECR3_EE6F_2  | HRTIM_EECR3_EE6F_1 | HRTIM_EECR3_EE6F_0)  /*!< fSAMPLING= fEEVS/32U, N=8U */
/** @} */

/**
 * @name    HRTIM Timer External Event Filter
 * @note    Constants defining the event filtering applied to external events
 *          by a timer.
 * @{  
 */
#define HRTIM_TIMEEVFLT_NONE                            (0x00000000U)
#define HRTIM_TIMEEVFLT_BLANKINGCMP1                    (HRTIM_EEFxR1_EE1FLTR_0)                                                    /*!< Blanking from counter reset/roll-over to Compare 1U  */
#define HRTIM_TIMEEVFLT_BLANKINGCMP2                    (HRTIM_EEFxR1_EE1FLTR_1)                                                    /*!< Blanking from counter reset/roll-over to Compare 2U  */
#define HRTIM_TIMEEVFLT_BLANKINGCMP3                    (HRTIM_EEFxR1_EE1FLTR_1 | HRTIM_EEFxR1_EE1FLTR_0)                           /*!< Blanking from counter reset/roll-over to Compare 3U  */
#define HRTIM_TIMEEVFLT_BLANKINGCMP4                    (HRTIM_EEFxR1_EE1FLTR_2)                                                    /*!< Blanking from counter reset/roll-over to Compare 4U  */
/* Blanking Filter for TIMER A */
#define HRTIM_TIMEEVFLT_BLANKING_TIMAEEF1_TIMBCMP1      (HRTIM_EEFxR1_EE1FLTR_2 | HRTIM_EEFxR1_EE1FLTR_0)                           /*!< Blanking from another timing unit: TIMFLTR1 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMAEEF2_TIMBCMP4      (HRTIM_EEFxR1_EE1FLTR_2 | HRTIM_EEFxR1_EE1FLTR_1)                           /*!< Blanking from another timing unit: TIMFLTR2 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMAEEF3_TIMBOUT2      (HRTIM_EEFxR1_EE1FLTR_2 | HRTIM_EEFxR1_EE1FLTR_1 | HRTIM_EEFxR1_EE1FLTR_0)  /*!< Blanking from another timing unit: TIMFLTR3 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMAEEF4_TIMCCMP1      (HRTIM_EEFxR1_EE1FLTR_3)                                                    /*!< Blanking from another timing unit: TIMFLTR4 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMAEEF5_TIMCCMP4      (HRTIM_EEFxR1_EE1FLTR_3 | HRTIM_EEFxR1_EE1FLTR_0)                           /*!< Blanking from another timing unit: TIMFLTR5 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMAEEF6_TIMFCMP1      (HRTIM_EEFxR1_EE1FLTR_3 | HRTIM_EEFxR1_EE1FLTR_1)                           /*!< Blanking from another timing unit: TIMFLTR6 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMAEEF7_TIMDCMP1      (HRTIM_EEFxR1_EE1FLTR_3 | HRTIM_EEFxR1_EE1FLTR_1 | HRTIM_EEFxR1_EE1FLTR_0)  /*!< Blanking from another timing unit: TIMFLTR7 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMAEEF8_TIMECMP2      (HRTIM_EEFxR1_EE1FLTR_3 | HRTIM_EEFxR1_EE1FLTR_2)                           /*!< Blanking from another timing unit: TIMFLTR8 source   */
/* Blanking Filter for TIMER B */
#define HRTIM_TIMEEVFLT_BLANKING_TIMBEEF1_TIMACMP1      (HRTIM_EEFxR1_EE1FLTR_2 | HRTIM_EEFxR1_EE1FLTR_0)                           /*!< Blanking from another timing unit: TIMFLTR1 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMBEEF2_TIMACMP4      (HRTIM_EEFxR1_EE1FLTR_2 | HRTIM_EEFxR1_EE1FLTR_1)                           /*!< Blanking from another timing unit: TIMFLTR2 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMBEEF3_TIMAOUT2      (HRTIM_EEFxR1_EE1FLTR_2 | HRTIM_EEFxR1_EE1FLTR_1 | HRTIM_EEFxR1_EE1FLTR_0)  /*!< Blanking from another timing unit: TIMFLTR3 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMBEEF4_TIMCCMP1      (HRTIM_EEFxR1_EE1FLTR_3)                                                    /*!< Blanking from another timing unit: TIMFLTR4 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMBEEF5_TIMCCMP2      (HRTIM_EEFxR1_EE1FLTR_3 | HRTIM_EEFxR1_EE1FLTR_0)                           /*!< Blanking from another timing unit: TIMFLTR5 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMBEEF6_TIMFCMP2      (HRTIM_EEFxR1_EE1FLTR_3 | HRTIM_EEFxR1_EE1FLTR_1)                           /*!< Blanking from another timing unit: TIMFLTR6 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMBEEF7_TIMDCMP2      (HRTIM_EEFxR1_EE1FLTR_3 | HRTIM_EEFxR1_EE1FLTR_1 | HRTIM_EEFxR1_EE1FLTR_0)  /*!< Blanking from another timing unit: TIMFLTR7 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMBEEF8_TIMECMP1      (HRTIM_EEFxR1_EE1FLTR_3 | HRTIM_EEFxR1_EE1FLTR_2)                           /*!< Blanking from another timing unit: TIMFLTR8 source   */
/* Blanking Filter for TIMER C */
#define HRTIM_TIMEEVFLT_BLANKING_TIMCEEF1_TIMACMP2      (HRTIM_EEFxR1_EE1FLTR_2 | HRTIM_EEFxR1_EE1FLTR_0)                           /*!< Blanking from another timing unit: TIMFLTR1 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMCEEF2_TIMBCMP1      (HRTIM_EEFxR1_EE1FLTR_2 | HRTIM_EEFxR1_EE1FLTR_1)                           /*!< Blanking from another timing unit: TIMFLTR2 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMCEEF3_TIMBCMP4      (HRTIM_EEFxR1_EE1FLTR_2 | HRTIM_EEFxR1_EE1FLTR_1 | HRTIM_EEFxR1_EE1FLTR_0)  /*!< Blanking from another timing unit: TIMFLTR3 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMCEEF4_TIMFCMP1      (HRTIM_EEFxR1_EE1FLTR_3)                                                    /*!< Blanking from another timing unit: TIMFLTR4 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMCEEF5_TIMDCMP1      (HRTIM_EEFxR1_EE1FLTR_3 | HRTIM_EEFxR1_EE1FLTR_0)                           /*!< Blanking from another timing unit: TIMFLTR5 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMCEEF6_TIMDCMP4      (HRTIM_EEFxR1_EE1FLTR_3 | HRTIM_EEFxR1_EE1FLTR_1)                           /*!< Blanking from another timing unit: TIMFLTR6 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMCEEF7_TIMDOUT2      (HRTIM_EEFxR1_EE1FLTR_3 | HRTIM_EEFxR1_EE1FLTR_1 | HRTIM_EEFxR1_EE1FLTR_0)  /*!< Blanking from another timing unit: TIMFLTR7 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMCEEF8_TIMECMP4      (HRTIM_EEFxR1_EE1FLTR_3 | HRTIM_EEFxR1_EE1FLTR_2)                           /*!< Blanking from another timing unit: TIMFLTR8 source   */
/* Blanking Filter for TIMER D */
#define HRTIM_TIMEEVFLT_BLANKING_TIMDEEF1_TIMACMP1      (HRTIM_EEFxR1_EE1FLTR_2 | HRTIM_EEFxR1_EE1FLTR_0)                           /*!< Blanking from another timing unit: TIMFLTR1 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMDEEF2_TIMBCMP2      (HRTIM_EEFxR1_EE1FLTR_2 | HRTIM_EEFxR1_EE1FLTR_1)                           /*!< Blanking from another timing unit: TIMFLTR2 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMDEEF3_TIMCCMP1      (HRTIM_EEFxR1_EE1FLTR_2 | HRTIM_EEFxR1_EE1FLTR_1 | HRTIM_EEFxR1_EE1FLTR_0)  /*!< Blanking from another timing unit: TIMFLTR3 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMDEEF4_TIMCCMP2      (HRTIM_EEFxR1_EE1FLTR_3)                                                    /*!< Blanking from another timing unit: TIMFLTR4 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMDEEF5_TIMCOUT2      (HRTIM_EEFxR1_EE1FLTR_3 | HRTIM_EEFxR1_EE1FLTR_0)                           /*!< Blanking from another timing unit: TIMFLTR5 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMDEEF6_TIMECMP1      (HRTIM_EEFxR1_EE1FLTR_3 | HRTIM_EEFxR1_EE1FLTR_1)                           /*!< Blanking from another timing unit: TIMFLTR6 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMDEEF7_TIMECMP4      (HRTIM_EEFxR1_EE1FLTR_3 | HRTIM_EEFxR1_EE1FLTR_1 | HRTIM_EEFxR1_EE1FLTR_0)  /*!< Blanking from another timing unit: TIMFLTR7 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMDEEF8_TIMFCMP4      (HRTIM_EEFxR1_EE1FLTR_3 | HRTIM_EEFxR1_EE1FLTR_2)                           /*!< Blanking from another timing unit: TIMFLTR8 source   */
/* Blanking Filter for TIMER E */
#define HRTIM_TIMEEVFLT_BLANKING_TIMEEEF1_TIMACMP2      (HRTIM_EEFxR1_EE1FLTR_2 | HRTIM_EEFxR1_EE1FLTR_0)                           /*!< Blanking from another timing unit: TIMFLTR1 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMEEEF2_TIMBCMP1      (HRTIM_EEFxR1_EE1FLTR_2 | HRTIM_EEFxR1_EE1FLTR_1)                           /*!< Blanking from another timing unit: TIMFLTR2 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMEEEF3_TIMCCMP1      (HRTIM_EEFxR1_EE1FLTR_2 | HRTIM_EEFxR1_EE1FLTR_1 | HRTIM_EEFxR1_EE1FLTR_0)  /*!< Blanking from another timing unit: TIMFLTR3 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMEEEF4_TIMFCMP4      (HRTIM_EEFxR1_EE1FLTR_3)                                                    /*!< Blanking from another timing unit: TIMFLTR4 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMEEEF5_TIMFOUT2      (HRTIM_EEFxR1_EE1FLTR_3 | HRTIM_EEFxR1_EE1FLTR_0)                           /*!< Blanking from another timing unit: TIMFLTR5 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMEEEF6_TIMDCMP1      (HRTIM_EEFxR1_EE1FLTR_3 | HRTIM_EEFxR1_EE1FLTR_1)                           /*!< Blanking from another timing unit: TIMFLTR6 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMEEEF7_TIMDCMP4      (HRTIM_EEFxR1_EE1FLTR_3 | HRTIM_EEFxR1_EE1FLTR_1 | HRTIM_EEFxR1_EE1FLTR_0)  /*!< Blanking from another timing unit: TIMFLTR7 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMEEEF8_TIMDOUT2      (HRTIM_EEFxR1_EE1FLTR_3 | HRTIM_EEFxR1_EE1FLTR_2)                           /*!< Blanking from another timing unit: TIMFLTR8 source   */
/* Blanking Filter for TIMER F */
#define HRTIM_TIMEEVFLT_BLANKING_TIMFEEF1_TIMACMP4      (HRTIM_EEFxR1_EE1FLTR_2 | HRTIM_EEFxR1_EE1FLTR_0)                           /*!< Blanking from another timing unit: TIMFLTR1 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMFEEF2_TIMBCMP2      (HRTIM_EEFxR1_EE1FLTR_2 | HRTIM_EEFxR1_EE1FLTR_1)                           /*!< Blanking from another timing unit: TIMFLTR2 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMFEEF3_TIMCCMP4      (HRTIM_EEFxR1_EE1FLTR_2 | HRTIM_EEFxR1_EE1FLTR_1 | HRTIM_EEFxR1_EE1FLTR_0)  /*!< Blanking from another timing unit: TIMFLTR3 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMFEEF4_TIMDCMP2      (HRTIM_EEFxR1_EE1FLTR_3)                                                    /*!< Blanking from another timing unit: TIMFLTR4 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMFEEF5_TIMDCMP4      (HRTIM_EEFxR1_EE1FLTR_3 | HRTIM_EEFxR1_EE1FLTR_0)                           /*!< Blanking from another timing unit: TIMFLTR5 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMFEEF6_TIMECMP1      (HRTIM_EEFxR1_EE1FLTR_3 | HRTIM_EEFxR1_EE1FLTR_1)                           /*!< Blanking from another timing unit: TIMFLTR6 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMFEEF7_TIMECMP4      (HRTIM_EEFxR1_EE1FLTR_3 | HRTIM_EEFxR1_EE1FLTR_1 | HRTIM_EEFxR1_EE1FLTR_0)  /*!< Blanking from another timing unit: TIMFLTR7 source   */
#define HRTIM_TIMEEVFLT_BLANKING_TIMFEEF8_TIMEOUT2      (HRTIM_EEFxR1_EE1FLTR_3 | HRTIM_EEFxR1_EE1FLTR_2)                           /*!< Blanking from another timing unit: TIMFLTR8 source   */

#define HRTIM_TIMEEVFLT_WINDOWINGCMP2                   (HRTIM_EEFxR1_EE1FLTR_3 | HRTIM_EEFxR1_EE1FLTR_2 | HRTIM_EEFxR1_EE1FLTR_0)  /*!< Windowing from counter reset/roll-over to Compare 2U */
#define HRTIM_TIMEEVFLT_WINDOWINGCMP3                   (HRTIM_EEFxR1_EE1FLTR_3 | HRTIM_EEFxR1_EE1FLTR_2 | HRTIM_EEFxR1_EE1FLTR_1)  /*!< Windowing from counter reset/roll-over to Compare 3U */
#define HRTIM_TIMEEVFLT_WINDOWINGTIM                    (HRTIM_EEFxR1_EE1FLTR_3 | HRTIM_EEFxR1_EE1FLTR_2 | HRTIM_EEFxR1_EE1FLTR_1\
                                                                                                         | HRTIM_EEFxR1_EE1FLTR_0)  /*!< Windowing from another timing unit: TIMWIN source    */
/** @} */

/**
 * @name    HRTIM Timer External Event Latch
 * @note    Constants defining whether or not the external event is memorized
 *          (latched) and generated as soon as the blanking period is completed
 *          or the window ends.
 * @{
 */
#define HRTIM_TIMEVENTLATCH_DISABLED   (0x00000000U)            /*!< Event is ignored if it happens during a blank, or passed through during a window */
#define HRTIM_TIMEVENTLATCH_ENABLED    (0x00000001U)            /*!< Event is latched and delayed till the end of the blanking or windowing period    */
/** @} */

/**
 * @name    HRTIM Counter Mode
 * @note    Constants defining the Counter Up Down Mode.
 * @{  
 */
#define HRTIM_COUNTING_MODE_UP         0x00000000U             /*!< counter is operating in up-counting mode       */
#define HRTIM_COUNTING_MODE_UP_DOWN    HRTIM_TIMxCR2_UDM       /*!< counter is operating in up-down counting mode  */
/** @} */

/**
 * @name    HRTIM_COUNTER_Roll-Over counter Mode
 * @note    Constants defining the Roll-Over counter Mode.
 * @{  
 */
#define HRTIM_ROLLOVER_MODE_PER        HRTIM_TIMxCR2_ROM_1      /*!< 0x00000080 - Event generated when counter reaches period value  ('crest' mode)           */
#define HRTIM_ROLLOVER_MODE_RST        HRTIM_TIMxCR2_ROM_0      /*!< 0x00000040 - Event generated when counter equals 0 ('valley' mode)                       */
#define HRTIM_ROLLOVER_MODE_BOTH       0x00000000U              /*!< 0x00000000 - Event generated when counter reach both conditions (0 or HRTIM_PERxR value) */
/** @} */

/**
 * @name    HRTIM_HALF_MODE HALF MODE
 * @note    Constants defining the half mode of an HRTIM Timer instance.
 * @{  
 */
#define HRTIM_HALF_MODE_DISABLED       0x00000000U              /*!< HRTIM Half Mode is disabled */
#define HRTIM_HALF_MODE_ENABLE         HRTIM_MCR_HALF           /*!< HRTIM Half Mode is enabled  */
/** @} */

/**
 * @name    HRTIM_PRELOAD MODE
 * @note    Constants defining the preload mode of an HRTIM Timer instance.
 * @{  
 */
#define HRTIM_PRELOAD_DISABLED         0x00000000U              /*!< HRTIM Preload of MASTER is disabled    */
#define HRTIM_PRELOAD_PREEN            0x08000000U              /*!< HRTIM Preload of timer/master enabled  */
/** @} */

/**
 * @name    HRTIM Dual Channel Dac Reset Trigger
 * @note    Constants defining when the hrtim_dac_reset_trgx trigger is
 *          generated.
 * @{  
 */
#define HRTIM_DUALDAC_RESET_TRIGGER_RESET        0x00000000U              /*!< the trigger is generated on counter reset or roll-over event */
#define HRTIM_DUALDAC_RESET_TRIGGER_OUT1SET      (HRTIM_TIMxCR2_DCDR)     /*!< the trigger is generated on output 1 set event               */    
/** @} */

/**
 * @name    HRTIM Dual Channel Dac Step Trigger
 * @note    Constants defining when the hrtim_dac_step_trgx trigger is
 *          generated.
 * @{  
 */
#define HRTIM_DUALDAC_STEP_TRIGGER_CMP2          0x00000000U              /*!< the trigger is generated on compare 2 event      */
#define HRTIM_DUALDAC_STEP_TRIGGER_OUT1RST       (HRTIM_TIMxCR2_DCDS)     /*!< the trigger is generated on output 1 reset event */ 
/** @} */

/**
 * @name    HRTIM DAC synchronization event
 * @note    Constants defining on which output the DAC synchronization event is
 *          sent.
 * @{  
 */
#define HRTIM_DACSYNC_NONE     0x00000000U                                     /*!< No DAC synchronization event generated                                         */                
#define HRTIM_DACSYNC_TRIG1    (HRTIM_TIMxCR_DACSYNC_0)                        /*!< DAC synchronization event generated on hrtim_dac_trg1 output upon timer update */
#define HRTIM_DACSYNC_TRIG2    (HRTIM_TIMxCR_DACSYNC_1)                        /*!< DAC synchronization event generated on hrtim_dac_trg1 output upon timer update */
#define HRTIM_DACSYNC_TRIG3    (HRTIM_MCR_DACSYNC_1 | HRTIM_TIMxCR_DACSYNC_0)  /*!< DAC synchronization event generated on hrtim_dac_trg3 output upon timer update */
/** @} */

/**
 * @name    HRTIM Fault Lock
 * @note    Constants defining whether or not the fault programming bits are
 *          write protected
 * @{
 */
#define HRTIM_FAULTLOCK_READWRITE       (0x00000000U)               /*!< Fault settings bits are read/write */
#define HRTIM_FAULTLOCK_READONLY        (0x80000000U)               /*!< Fault settings bits are read only  */
/**@}*/

/**
 * @name    HRTIM Timer External Counter Reset Mode
 * @note    Constants enabling the External Event Counter A Reset Mode
 * @{ 
 */
#define HRTIM_EVENTCOUNTER_RSTMODE_UNCONDITIONAL   (0x00000000U)   /*!< External Event Counter is reset on each reset / roll-over event                                                     */
#define HRTIM_EVENTCOUNTER_RSTMODE_CONDITIONAL     (0x00000001U)   /*!< External Event Counter is reset on each reset / roll-over event only if no event occurs during last counting period */
/**@}*/

/**
 * @name    HRTIM Fault Filter
 * @note    Constants defining the frequency used to sample the fault input and
 *          the length (N) of the digital filter applied
 * @{ 
 */
#define HRTIM_FAULTFILTER_NONE      (0x00000000U)                                                                                    /*!< Filter disabled             */
#define HRTIM_FAULTFILTER_1         (HRTIM_FLTINR1_FLT1F_0)                                                                          /*!< fSAMPLING = fHRTIM, N=2U    */
#define HRTIM_FAULTFILTER_2         (HRTIM_FLTINR1_FLT1F_1)                                                                          /*!< fSAMPLING = fHRTIM, N=4U    */
#define HRTIM_FAULTFILTER_3         (HRTIM_FLTINR1_FLT1F_1 | HRTIM_FLTINR1_FLT1F_0)                                                  /*!< fSAMPLING = fHRTIM, N=8U    */
#define HRTIM_FAULTFILTER_4         (HRTIM_FLTINR1_FLT1F_2)                                                                          /*!< fSAMPLING = fFLTS/2U, N=6U  */
#define HRTIM_FAULTFILTER_5         (HRTIM_FLTINR1_FLT1F_2 | HRTIM_FLTINR1_FLT1F_0)                                                  /*!< fSAMPLING = fFLTS/2U, N=8U  */
#define HRTIM_FAULTFILTER_6         (HRTIM_FLTINR1_FLT1F_2 | HRTIM_FLTINR1_FLT1F_1)                                                  /*!< fSAMPLING = fFLTS/4U, N=6U  */
#define HRTIM_FAULTFILTER_7         (HRTIM_FLTINR1_FLT1F_2 | HRTIM_FLTINR1_FLT1F_1 | HRTIM_FLTINR1_FLT1F_0)                          /*!< fSAMPLING = fFLTS/4U, N=8U  */
#define HRTIM_FAULTFILTER_8         (HRTIM_FLTINR1_FLT1F_3)                                                                          /*!< fSAMPLING = fFLTS/8U, N=6U  */
#define HRTIM_FAULTFILTER_9         (HRTIM_FLTINR1_FLT1F_3 | HRTIM_FLTINR1_FLT1F_0)                                                  /*!< fSAMPLING = fFLTS/8U, N=8U  */
#define HRTIM_FAULTFILTER_10        (HRTIM_FLTINR1_FLT1F_3 | HRTIM_FLTINR1_FLT1F_1)                                                  /*!< fSAMPLING = fFLTS/16U, N=5U */
#define HRTIM_FAULTFILTER_11        (HRTIM_FLTINR1_FLT1F_3 | HRTIM_FLTINR1_FLT1F_1 | HRTIM_FLTINR1_FLT1F_0)                          /*!< fSAMPLING = fFLTS/16U, N=6U */
#define HRTIM_FAULTFILTER_12        (HRTIM_FLTINR1_FLT1F_3 | HRTIM_FLTINR1_FLT1F_2)                                                  /*!< fSAMPLING = fFLTS/16U, N=8U */
#define HRTIM_FAULTFILTER_13        (HRTIM_FLTINR1_FLT1F_3 | HRTIM_FLTINR1_FLT1F_2 | HRTIM_FLTINR1_FLT1F_0)                          /*!< fSAMPLING = fFLTS/32U, N=5U */
#define HRTIM_FAULTFILTER_14        (HRTIM_FLTINR1_FLT1F_3 | HRTIM_FLTINR1_FLT1F_2 | HRTIM_FLTINR1_FLT1F_1)                          /*!< fSAMPLING = fFLTS/32U, N=6U */
#define HRTIM_FAULTFILTER_15        (HRTIM_FLTINR1_FLT1F_3 | HRTIM_FLTINR1_FLT1F_2 | HRTIM_FLTINR1_FLT1F_1 | HRTIM_FLTINR1_FLT1F_0)  /*!< fSAMPLING = fFLTS/32U, N=8U */
/**@}*/

/**
 * @name    HRTIMHRTIM Fault Polarity
 * @note    Constants defining the polarity of a fault event
 * @{ 
 */
#define HRTIM_FAULTPOLARITY_LOW     (0x00000000U)               /*!< Fault input is active low  */
#define HRTIM_FAULTPOLARITY_HIGH    (HRTIM_FLTINR1_FLT1P)       /*!< Fault input is active high */
/**@}*/

/**
 * @name    HRTIM1 Fault Sources
 * @note    Constants defining whether a fault is triggered by any external or
 *          internal fault source
 * @{ 
 */
#define HRTIM1_FAULTSOURCE_FLT1_GPIO               (0x00000000U)       /*!< Fault input is FLT input pin                             */
#define HRTIM1_FAULTSOURCE_FLT2_GPIO               (0x00000000U)       /*!< Fault input is FLT input pin                             */
#define HRTIM1_FAULTSOURCE_FLT3_GPIO               (0x00000000U)       /*!< Fault input is FLT input pin                             */
#define HRTIM1_FAULTSOURCE_FLT4_GPIO               (0x00000000U)       /*!< Fault input is FLT input pin                             */
#define HRTIM1_FAULTSOURCE_FLT5_GPIO               (0x00000000U)       /*!< Fault input is FLT input pin                             */
#define HRTIM1_FAULTSOURCE_FLT6_GPIO               (0x00000000U)       /*!< Fault input is FLT input pin                             */
#define HRTIM1_FAULTSOURCE_FLT1_COMP2              (0x00000001U)       /*!< Fault input is FLT_Int signal (e.g. internal comparator) */
#define HRTIM1_FAULTSOURCE_FLT2_COMP4              (0x00000001U)       /*!< Fault input is FLT_Int signal (e.g. internal comparator) */
#define HRTIM1_FAULTSOURCE_FLT3_COMP6              (0x00000001U)       /*!< Fault input is FLT_Int signal (e.g. internal comparator) */
#define HRTIM1_FAULTSOURCE_FLT4_COMP1              (0x00000001U)       /*!< Fault input is FLT_Int signal (e.g. internal comparator) */
#define HRTIM1_FAULTSOURCE_FLT5_COMP3              (0x00000001U)       /*!< Fault input is FLT_Int signal (e.g. internal comparator) */
#define HRTIM1_FAULTSOURCE_FLT6_COMP5              (0x00000001U)       /*!< Fault input is FLT_Int signal (e.g. internal comparator) */
#define HRTIM1_FAULTSOURCE_FLT1_EEV1               (0x00000002U)       /*!< Fault input is EEV pin                                   */
#define HRTIM1_FAULTSOURCE_FLT2_EEV2               (0x00000002U)       /*!< Fault input is EEV pin                                   */
#define HRTIM1_FAULTSOURCE_FLT3_EEV3               (0x00000002U)       /*!< Fault input is EEV pin                                   */
#define HRTIM1_FAULTSOURCE_FLT4_EEV4               (0x00000002U)       /*!< Fault input is EEV pin                                   */
#define HRTIM1_FAULTSOURCE_FLT5_EEV5               (0x00000002U)       /*!< Fault input is EEV pin                                   */
#define HRTIM1_FAULTSOURCE_FLT6_EEV6               (0x00000002U)       /*!< Fault input is EEV pin                                   */
#define HRTIM1_FAULTSOURCE_FLT1_HRTIM2_EEV1        (0x00000003U)       /*!< Fault input is HRTIM2 EEV signal                         */
#define HRTIM1_FAULTSOURCE_FLT2_HRTIM2_EEV2        (0x00000003U)       /*!< Fault input is HRTIM2 EEV signal                         */
#define HRTIM1_FAULTSOURCE_FLT3_HRTIM2_EEV3        (0x00000003U)       /*!< Fault input is HRTIM2 EEV signal                         */
#define HRTIM1_FAULTSOURCE_FLT4_HRTIM2_EEV4        (0x00000003U)       /*!< Fault input is HRTIM2 EEV signal                         */
#define HRTIM1_FAULTSOURCE_FLT5_HRTIM2_EEV5        (0x00000003U)       /*!< Fault input is HRTIM2 EEV signal                         */
#define HRTIM1_FAULTSOURCE_FLT6_HRTIM2_EEV6        (0x00000003U)       /*!< Fault input is HRTIM2 EEV signal                         */
/**@}*/

/**
 * @name    HRTIM2 Fault Sources
 * @note    Constants defining whether a fault is triggered by any external or
 *          internal fault source
 * @{ 
 */
#define HRTIM2_FAULTSOURCE_FLT1_GPIO               (0x00000000U)       /*!< Fault input is FLT input pin                             */
#define HRTIM2_FAULTSOURCE_FLT2_GPIO               (0x00000000U)       /*!< Fault input is FLT input pin                             */
#define HRTIM2_FAULTSOURCE_FLT3_GPIO               (0x00000000U)       /*!< Fault input is FLT input pin                             */
#define HRTIM2_FAULTSOURCE_FLT4_GPIO               (0x00000000U)       /*!< Fault input is FLT input pin                             */
#define HRTIM2_FAULTSOURCE_FLT5_GPIO               (0x00000000U)       /*!< Fault input is FLT input pin                             */
#define HRTIM2_FAULTSOURCE_FLT6_GPIO               (0x00000000U)       /*!< Fault input is FLT input pin                             */
#define HRTIM2_FAULTSOURCE_FLT1_COMP1              (0x00000001U)       /*!< Fault input is FLT_Int signal (e.g. internal comparator) */
#define HRTIM2_FAULTSOURCE_FLT2_COMP3              (0x00000001U)       /*!< Fault input is FLT_Int signal (e.g. internal comparator) */
#define HRTIM2_FAULTSOURCE_FLT3_COMP5              (0x00000001U)       /*!< Fault input is FLT_Int signal (e.g. internal comparator) */
#define HRTIM2_FAULTSOURCE_FLT4_COMP2              (0x00000001U)       /*!< Fault input is FLT_Int signal (e.g. internal comparator) */
#define HRTIM2_FAULTSOURCE_FLT5_COMP4              (0x00000001U)       /*!< Fault input is FLT_Int signal (e.g. internal comparator) */
#define HRTIM2_FAULTSOURCE_FLT6_COMP6              (0x00000001U)       /*!< Fault input is FLT_Int signal (e.g. internal comparator) */
#define HRTIM2_FAULTSOURCE_FLT1_EEV1               (0x00000002U)       /*!< Fault input is EEV pin                                   */
#define HRTIM2_FAULTSOURCE_FLT2_EEV2               (0x00000002U)       /*!< Fault input is EEV pin                                   */
#define HRTIM2_FAULTSOURCE_FLT3_EEV3               (0x00000002U)       /*!< Fault input is EEV pin                                   */
#define HRTIM2_FAULTSOURCE_FLT4_EEV4               (0x00000002U)       /*!< Fault input is EEV pin                                   */
#define HRTIM2_FAULTSOURCE_FLT5_EEV5               (0x00000002U)       /*!< Fault input is EEV pin                                   */
#define HRTIM2_FAULTSOURCE_FLT6_EEV6               (0x00000002U)       /*!< Fault input is EEV pin                                   */
#define HRTIM2_FAULTSOURCE_FLT1_HRTIM1_EEV1        (0x00000003U)       /*!< Fault input is HRTIM1 EEV signal                         */
#define HRTIM2_FAULTSOURCE_FLT2_HRTIM1_EEV2        (0x00000003U)       /*!< Fault input is HRTIM1 EEV signal                         */
#define HRTIM2_FAULTSOURCE_FLT3_HRTIM1_EEV3        (0x00000003U)       /*!< Fault input is HRTIM1 EEV signal                         */
#define HRTIM2_FAULTSOURCE_FLT4_HRTIM1_EEV4        (0x00000003U)       /*!< Fault input is HRTIM1 EEV signal                         */
#define HRTIM2_FAULTSOURCE_FLT5_HRTIM1_EEV5        (0x00000003U)       /*!< Fault input is HRTIM1 EEV signal                         */
#define HRTIM2_FAULTSOURCE_FLT6_HRTIM1_EEV6        (0x00000003U)       /*!< Fault input is HRTIM1 EEV signal                         */
/**@}*/
 
/**
 * @name    HRTIM Fault Reset Mode
 * @note    Constants defining the Counter reset mode of a fault event
 * @{ 
 */
#define HRTIM_FAULTCOUNTERRST_UNCONDITIONAL  (0x00000000U)      /*!< Fault counter is reset on each reset / roll-over event                                                      */
#define HRTIM_FAULTCOUNTERRST_CONDITIONAL    (0x00000001U)      /*!< Fault counter is reset on each reset / roll-over event only if no fault occurred during last countingperiod */
/**@}*/

/**
 * @name    HRTIM Fault Blanking Source
 * @note    Constants defining the blanking source of a fault event
 * @{ 
 */
#define HRTIM_FAULTBLANKINGMODE_RSTALIGNED  (0x00000000U)       /*!< Fault blanking source is Reset-aligned window */
#define HRTIM_FAULTBLANKINGMODE_MOVING      (0x00000001U)       /*!< Fault blanking source is Moving window        */
/**@}*/
  
/**
 * @name    HRTIM_Private_Defines HRTIM Private Define
 * @{
 */
#define HRTIM_FLTINR1_FLTxLCK          ((0x00000080U) | \
                                        (0x00008000U) | \
                                        (0x00800000U) | \
                                        (0x80000000U))

#define HRTIM_FLTINR2_FLTxLCK          ((0x00000080U) | \
                                        (0x00008000U))
/**@}*/ 

/**
 * @name    HRTIM Capture Unit Trigger
 * @note    Constants defining the events that can be selected to trigger the
 *          capture of the timing unit counter
 * @{
 */
 /* capture trigger event common at each timer (A..F).*/
#define HRTIM_CAPTURE_TRG_NONE          0x00000000U                  /*!< Capture trigger is disabled                                      */
#define HRTIM_CAPTURE_TRG_UPDATE        0x00000002U                  /*!< The update event triggers the Capture                            */
#define HRTIM_CAPTURE_TRG_EEV_1         0x00000004U                  /*!< The External event 1 triggers the Capture                        */
#define HRTIM_CAPTURE_TRG_EEV_2         0x00000008U                  /*!< The External event 2 triggers the Capture                        */
#define HRTIM_CAPTURE_TRG_EEV_3         0x00000010U                  /*!< The External event 3 triggers the Capture                        */
#define HRTIM_CAPTURE_TRG_EEV_4         0x00000020U                  /*!< The External event 4 triggers the Capture                        */
#define HRTIM_CAPTURE_TRG_EEV_5         0x00000040U                  /*!< The External event 5 triggers the Capture                        */
#define HRTIM_CAPTURE_TRG_EEV_6         0x00000080U                  /*!< The External event 6 triggers the Capture                        */
#define HRTIM_CAPTURE_TRG_EEV_7         0x00000100U                  /*!< The External event 7 triggers the Capture                        */
#define HRTIM_CAPTURE_TRG_EEV_8         0x00000200U                  /*!< The External event 8 triggers the Capture                        */
#define HRTIM_CAPTURE_TRG_EEV_9         0x00000200U                  /*!< The External event 9 triggers the Capture                        */
#define HRTIM_CAPTURE_TRG_EEV_10        0x00000800U                  /*!< The External event 10 triggers the Capture                       */
/* capture trigger event common at each timer but A.*/
#define HRTIM_CAPTURE_TRG_TA1_SET       0x00001000U                  /*!< Capture is triggered by TA1 output inactive to active transition */
#define HRTIM_CAPTURE_TRG_TA1_RESET     0x00002000U                  /*!< Capture is triggered by TA1 output active to inactive transition */
#define HRTIM_CAPTURE_TRG_TIMERA_CMP1   0x00004000U                  /*!< Timer A Compare 1 triggers Capture                               */
#define HRTIM_CAPTURE_TRG_TIMERA_CMP2   0x00008000U                  /*!< Timer A Compare 2 triggers Capture                               */
/* capture trigger event common at each timer but B.*/
#define HRTIM_CAPTURE_TRG_TB1_SET       0x00010000U                  /*!< Capture is triggered by TB1 output inactive to active transition */
#define HRTIM_CAPTURE_TRG_TB1_RESET     0x00020000U                  /*!< Capture is triggered by TB1 output active to inactive transition */
#define HRTIM_CAPTURE_TRG_TIMERB_CMP1   0x00040000U                  /*!< Timer B Compare 1 triggers Capture                               */
#define HRTIM_CAPTURE_TRG_TIMERB_CMP2   0x00080000U                  /*!< Timer B Compare 2 triggers Capture                               */
/* capture trigger event common at each timer but C.*/
#define HRTIM_CAPTURE_TRG_TC1_SET       0x00100000U                  /*!< Capture is triggered by TC1 output inactive to active transition */
#define HRTIM_CAPTURE_TRG_TC1_RESET     0x00200000U                  /*!< Capture is triggered by TC1 output active to inactive transition */
#define HRTIM_CAPTURE_TRG_TIMERC_CMP1   0x00400000U                  /*!< Timer C Compare 1 triggers Capture                               */
#define HRTIM_CAPTURE_TRG_TIMERC_CMP2   0x00800000U                  /*!< Timer C Compare 2 triggers Capture                               */
/* capture trigger event common at each timer but D.*/
#define HRTIM_CAPTURE_TRG_TD1_SET       0x01000000U                  /*!< Capture is triggered by TD1 output inactive to active transition */
#define HRTIM_CAPTURE_TRG_TD1_RESET     0x02000000U                  /*!< Capture is triggered by TD1 output active to inactive transition */
#define HRTIM_CAPTURE_TRG_TIMERD_CMP1   0x04000000U                  /*!< Timer D Compare 1 triggers Capture                               */
#define HRTIM_CAPTURE_TRG_TIMERD_CMP2   0x08000000U                  /*!< Timer D Compare 2 triggers Capture                               */
/* capture trigger event common at each timer but E.*/
#define HRTIM_CAPTURE_TRG_TE1_SET       0x10000000U                  /*!< Capture is triggered by TE1 output inactive to active transition */
#define HRTIM_CAPTURE_TRG_TE1_RESET     0x20000000U                  /*!< Capture is triggered by TE1 output active to inactive transition */
#define HRTIM_CAPTURE_TRG_TIMERE_CMP1   0x40000000U                  /*!< Timer E Compare 1 triggers Capture                               */
#define HRTIM_CAPTURE_TRG_TIMERE_CMP2   0x80000000U                  /*!< Timer E Compare 2 triggers Capture                               */

/* capture trigger event by by TF customized for each timer.*/
/*TIMER A*/
#define HRTIM_CAPTURE_TRG_TF1_SET_TA    0x00001000U                  /*!< Capture is triggered by TF1 output inactive to active transition */
#define HRTIM_CAPTURE_TRG_TF1_RESET_TA  0x00002000U                  /*!< Capture is triggered by TF1 output active to inactive transition */
#define HRTIM_CAPTURE_TRG_TF_CMP1_TA    0x00004000U                  /*!< Timer F Compare 1 triggers Capture                               */
#define HRTIM_CAPTURE_TRG_TF_CMP2_TA    0x00008000U                  /*!< Timer F Compare 2 triggers Capture                               */
/*TIMER B*/                             
#define HRTIM_CAPTURE_TRG_TF1_SET_TB    0x00010000U                  /*!< Capture is triggered by TF1 output inactive to active transition */
#define HRTIM_CAPTURE_TRG_TF1_RESET_TB  0x00020000U                  /*!< Capture is triggered by TF1 output active to inactive transition */
#define HRTIM_CAPTURE_TRG_TF_CMP1_TB    0x00040000U                  /*!< Timer F Compare 1 triggers Capture                               */
#define HRTIM_CAPTURE_TRG_TF_CMP2_TB    0x00080000U                  /*!< Timer F Compare 2 triggers Capture                               */
/*TIMER C*/                             
#define HRTIM_CAPTURE_TRG_TF1_SET_TC    0x00100000U                  /*!< Capture is triggered by TF1 output inactive to active transition */
#define HRTIM_CAPTURE_TRG_TF1_RESET_TC  0x00200000U                  /*!< Capture is triggered by TF1 output active to inactive transition */
#define HRTIM_CAPTURE_TRG_TF_CMP1_TC    0x00400000U                  /*!< Timer F Compare 1 triggers Capture                               */
#define HRTIM_CAPTURE_TRG_TF_CMP2_TC    0x00800000U                  /*!< Timer F Compare 2 triggers Capture                               */
/*TIMER D*/                             
#define HRTIM_CAPTURE_TRG_TF1_SET_TD    0x01000000U                  /*!< Capture is triggered by TF1 output inactive to active transition */
#define HRTIM_CAPTURE_TRG_TF1_RESET_TD  0x02000000U                  /*!< Capture is triggered by TF1 output active to inactive transition */
#define HRTIM_CAPTURE_TRG_TF_CMP1_TD    0x04000000U                  /*!< Timer F Compare 1 triggers Capture                               */
#define HRTIM_CAPTURE_TRG_TF_CMP2_TD    0x08000000U                  /*!< Timer F Compare 2 triggers Capture                               */
/*TIMER E*/                             
#define HRTIM_CAPTURE_TRG_TF1_SET_TE    0x10000000U                  /*!< Capture is triggered by TF1 output inactive to active transition */
#define HRTIM_CAPTURE_TRG_TF1_RESET_TE  0x20000000U                  /*!< Capture is triggered by TF1 output active to inactive transition */
#define HRTIM_CAPTURE_TRG_TF_CMP1_TE    0x40000000U                  /*!< Timer F Compare 1 triggers Capture                               */
#define HRTIM_CAPTURE_TRG_TF_CMP2_TE    0x80000000U                  /*!< Timer F Compare 2 triggers Capture                               */
/**@}*/

/**
 * @name    HRTIM Capture Unit TimerF Trigger
 * @note    Constants defining the events that can be selected to trigger the
 *          capture of the timing unit counter
 * @{
 */
#define HRTIM_CAPTURE_TRG_TF1_SET       0x00001000U                  /*!< Capture is triggered by TF1 output inactive to active transition */
#define HRTIM_CAPTURE_TRG_TF1_RESET     0x00002000U                  /*!< Capture is triggered by TF1 output active to inactive transition */
#define HRTIM_CAPTURE_TRG_TIMERF_CMP1   0x00004000U                  /*!< Timer F Compare 1 triggers Capture                               */
#define HRTIM_CAPTURE_TRG_TIMERF_CMP2   0x00008000U                  /*!< Timer F Compare 2 triggers Capture                               */
/**@}*/

/**
 * @name    HRTIM Timer UpDown Mode
 * @note    Constants defining how the timer counter operates
 * @{
 */
#define HRTIM_TIMERUPDOWNMODE_UP           0x00000000U               /*!< Timer counter is operating in up-counting mode      */
#define HRTIM_TIMERUPDOWNMODE_UPDOWN       0x00000001U               /*!< Timer counter is operating in up-down counting mode */
/**@}*/

/*===========================================================================*/
/* Module pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Module data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Type of an HRTIM driver.
 */
typedef struct hrtim_driver hrtim_driver_t;

/**
 * @brief   Type of an HRTIM callback.
 *
 * @param[in] hdp       pointer to the @p hrtim_driver_t object
 * @param[in] events    interrupt flags as defined in @p ISR register
 */
typedef void (*hrtim_cb_t)(hrtim_driver_t *hdp, uint32_t events);

/**
 * @enum hrtim_timer_t
 * Supported HRTIM timer units.
 */
typedef enum {
    HRTIM_TIMER_A = 0,       /**< Timer A      */
    HRTIM_TIMER_B = 1,       /**< Timer B      */
    HRTIM_TIMER_C = 2,       /**< Timer C      */
    HRTIM_TIMER_D = 3,       /**< Timer D      */
    HRTIM_TIMER_E = 4,       /**< Timer E      */
    HRTIM_TIMER_F = 5,       /**< Timer F      */
    HRTIM_TIMER_MASTER = 6,  /**< Timer Master */
} hrtim_timer_t;

/**
 * @enum hrtim_cmp_t
 * Supported HRTIM comparators.
 */
typedef enum {
    HRTIM_CMP1,              /**< Compare 1 event */
    HRTIM_CMP2,              /**< Compare 2 event */
    HRTIM_CMP3,              /**< Compare 3 event */
    HRTIM_CMP4               /**< Compare 4 event */
} hrtim_cmp_t;

/**
 * @enum hrtim_cmp_ad_mode_t
 * Supported HRTIM comparator auto-delayed modes.
 */
typedef enum {
    HRTIM_CMP_AD_MODE_STANDARD,         /**< CMP2/CMP4 register is always active (standard compare mode)                                                                  */
    HRTIM_CMP_AD_MODE_CAP,              /**< CMP2/CMP4 value is recomputed and is active following a capture 1/2 event                                                    */
    HRTIM_CMP_AD_MODE_CAP_COMP1,        /**< CMP2/CMP4 value is recomputed and is active following a capture 1/2 event, or is recomputed and active after Compare 1 match */
    HRTIM_CMP_AD_MODE_CAP_COMP3         /**< CMP2/CMP4 value is recomputed and is active following a capture 1/2 event, or is recomputed and active after Compare 3 match */
} hrtim_cmp_ad_mode_t;

/**
 * @enum hrtim_prsc_t
 * Supported HRTIM master/timer prescalers.
 */
typedef enum {
    HRTIM_PRSC_DIV1,         /**< Master/Timer prescaler value = 0 => division by 1   */
    HRTIM_PRSC_DIV2,         /**< Master/Timer prescaler value = 1 => division by 2   */
    HRTIM_PRSC_DIV4,         /**< Master/Timer prescaler value = 2 => division by 4   */
    HRTIM_PRSC_DIV8,         /**< Master/Timer prescaler value = 3 => division by 8   */
    HRTIM_PRSC_DIV16,        /**< Master/Timer prescaler value = 4 => division by 16  */
    HRTIM_PRSC_DIV32,        /**< Master/Timer prescaler value = 5 => division by 32  */
    HRTIM_PRSC_DIV64,        /**< Master/Timer prescaler value = 6 => division by 64  */
    HRTIM_PRSC_DIV128        /**< Master/Timer prescaler value = 7 => division by 128 */
} hrtim_prsc_t;

/**
 * @enum hrtim_cntr_mode_t
 * Supported HRTIM master/timer modes.
 */
typedef enum {
    HRTIM_MODE_SINGLE_SHOT_NO_RETRIGGERED,  /**< Single-shot, Non-Retriggerable */
    HRTIM_MODE_SINGLE_SHOT_RETRIGGERED,     /**< Single-shot, Retriggerable     */
    HRTIM_MODE_CONTINUOS                    /**< Continuous mode                */
} hrtim_cntr_mode_t;

/**
 * @enum hrtim_dt_prsc_t
 * Supported HRTIM deadtime prescalers.
 */
typedef enum {
    HRTIM_DT_PRSC_DIV8,      /**< Deadtime prescaler value = 0 => division by 8        */
    HRTIM_DT_PRSC_DIV4,      /**< Deadtime prescaler value = 1 => division by 4        */
    HRTIM_DT_PRSC_DIV2,      /**< Deadtime prescaler value = 2 => division by 2        */
    HRTIM_DT_PRSC_DIV1,      /**< Deadtime prescaler value = 3 => division by 1        */
    HRTIM_DT_PRSC_MUL2,      /**< Deadtime prescaler value = 4 => multiplication by 2  */
    HRTIM_DT_PRSC_MUL4,      /**< Deadtime prescaler value = 5 => multiplication by 4  */
    HRTIM_DT_PRSC_MUL8,      /**< Deadtime prescaler value = 6 => multiplication by 8  */
    HRTIM_DT_PRSC_MUL16      /**< Deadtime prescaler value = 7 => multiplication by 16 */
} hrtim_dt_prsc_t;

/**
 * @enum hrtim_dt_sign_t
 * Supported HRTIM deadtime signs.
 */
typedef enum {
    HRTIM_DT_SIGN_POSITIVE,  /**< Deadtime positive sign */
    HRTIM_DT_SIGN_NEGATIVE   /**< Deadtime negative sign */
} hrtim_dt_sign_t;

/**
 * @enum hrtim_out_t
 * Supported HRTIM timer outputs.
 */
typedef enum {
    HRTIM_TIMER_OUTPUT_1,    /**< Timer output 1 */
    HRTIM_TIMER_OUTPUT_2     /**< Timer output 2 */
} hrtim_out_t;

/**
 * @enum hrtim_dt_t
 * HRTIM deadtime configuration.
 */
typedef struct {
    /**
     * @brief   Deadtime enable flag.
     */
    bool                     enable;
    /**
     * @brief   Deadtime prescaler [0:7].
     */
    hrtim_dt_prsc_t          prescaler;
    /**
     * @brief   Deadtime rising value [0:1FFU].
     */
    uint16_t                 rvalue;
    /**
     * @brief   Deadtime rising sign (positive or neagative).
     */
    hrtim_dt_sign_t          rsign;
    /**
     * @brief   Deadtime rising value [0:1FFU].
     */
    uint16_t                 fvalue;
    /**
     * @brief   Deadtime falling sign (positive or neagative).
     */
    hrtim_dt_sign_t          fsign;
} hrtim_dt_t;

/**
 * @enum hrtim_cb_ops_t
 * Supported HRTIM callback operations.
 */
typedef enum {
    HRTIM_CB_TIMER_A,        /**< Callback Timer A      */
    HRTIM_CB_TIMER_B,        /**< Callback Timer B      */
    HRTIM_CB_TIMER_C,        /**< Callback Timer C      */
    HRTIM_CB_TIMER_D,        /**< Callback Timer D      */
    HRTIM_CB_TIMER_E,        /**< Callback Timer E      */
    HRTIM_CB_TIMER_F,        /**< Callback Timer F      */
    HRTIM_CB_MASTER,         /**< Callback Timer Master */
    HRTIM_CB_FAULT           /**< Callback Fault        */
} hrtim_cb_ops_t;

/**
  * @brief  ADC trigger index
  */
typedef enum {
    HRTIM_ADCTRIGGER_1 = 0,       /**< ADCTRIGGER_1  */
    HRTIM_ADCTRIGGER_2 = 1,       /**< ADCTRIGGER_2  */
    HRTIM_ADCTRIGGER_3 = 2,       /**< ADCTRIGGER_3  */
    HRTIM_ADCTRIGGER_4 = 3,       /**< ADCTRIGGER_4  */
    HRTIM_ADCTRIGGER_5 = 4,       /**< ADCTRIGGER_5  */
    HRTIM_ADCTRIGGER_6 = 5,       /**< ADCTRIGGER_6  */
    HRTIM_ADCTRIGGER_7 = 6,       /**< ADCTRIGGER_7  */
    HRTIM_ADCTRIGGER_8 = 7,       /**< ADCTRIGGER_8  */
    HRTIM_ADCTRIGGER_9 = 8,       /**< ADCTRIGGER_9  */
    HRTIM_ADCTRIGGER_10 = 9       /**< ADCTRIGGER_10 */
} hrtim_timer_adctrigger_t; 
  
/**
  * @brief  ADC trigger configuration definition
  */
typedef struct {
    /**
     * @brief   Specifies the ADC trigger.
     */
    hrtim_timer_adctrigger_t adc_trigger;
    /**
     * @brief   Specifies the ADC trigger update source
     */
    uint32_t update_src;
    /**
     * @brief   Specifies the event(s) triggering the ADC conversion.
     */
    uint32_t event_trigger;
    /**
     * @brief   Specifies the ADC trigger rate.
     */
    uint32_t post_scaler_rate;
} hrtim_adc_trigger_cfg_t;

/**
 * HRTIM preload configuration definition
 */
typedef enum {
    HRTIM_UPDATE_SW = 0,     /**< Specifies an immediate update by xSWU bit  */
    HRTIM_UPDATE_EVENT = 1   /**< Specifies an update by event               */
} hrtim_update_event_t;

/**
 * HRTIM preload configuration definition
 */
typedef struct {
    uint32_t enable;         /**< Preload enable flag     */
    uint32_t update_event;   /**< Update event: HRTIM_ADC_Trigger_Update_Source     */
} hrtim_pl_t;

/**
 * @enum hrtim_countmode_t
 * HRTIM count mode configuration.
 */
typedef struct {
    /**
     * @brief   Up-Down count enable flag.
     */
    bool                     up_down_enable;
    /**
     * @brief   Count mode.
     */
    uint32_t                 up_down_mode;
    /**
     * @brief   Rollover mode.
     */
    uint16_t                 rollover;
    /**
     * @brief   OUTPUT Rollover mode.
     */
    uint16_t                 out_rollover;
    /**
     * @brief   ADC Rollover mode.
     */
    uint16_t                 adc_rollover;
    /**
     * @brief   BURST mode Rollover mode.
     */
    uint16_t                 burstmode_rollover;
    /**
     * @brief   Fault and event  Rollover mode.
     */
    uint16_t                 fault_event_rollover; 
} hrtim_countmode_t;

/**
 * @enum hrtim_mode_tpg_t
 * Supported HRTIM master/timer mode topologies.
 */
typedef enum {
    HRTIM_MODE_HALF_INTLVD_DISABLED,   /**< Interleaved mode and half mode disabled */
    HRTIM_MODE_TRIPLE_INTERVALLED,     /**< Triple interleaved (120°)               */
    HRTIM_MODE_QUAD_INTERVALLED,       /**< Quad interleaved (90°)                  */
    HRTIM_MODE_DUAL_INTERVALLED,       /**< Dual interleaved (120°)                 */
    HRTIM_MODE_HALF                    /**< HALF mode                               */
} hrtim_mode_tpg_t;

/**
 * @enum hrtim_eev_prsc_t
 * HRTIM External Event Prescaler
 */
typedef enum {
    HRTIM_EVENTPRESCALER_DIV1,         /*!< fEEVS=fHRTIM      */
    HRTIM_EVENTPRESCALER_DIV2,         /*!< fEEVS=fHRTIM / 2U */
    HRTIM_EVENTPRESCALER_DIV4,         /*!< fEEVS=fHRTIM / 4U */
    HRTIM_EVENTPRESCALER_DIV8          /*!< fEEVS=fHRTIM / 8U */
} hrtim_eev_prsc_t;

/**
  * @brief  Event channel configuration definition
  */
typedef struct {
    /**
     * @brief   Identifies the the external event.
     */
    uint8_t                  event;
    /**
     * @brief   Identifies the source of the external event.
     */
    uint32_t                 source;
    /**
     * @brief   Specifies the polarity of the external event 
                (in case of level sensitivity).
     */
    uint32_t                 polarity;
    /**
     * @brief   Specifies the sensitivity of the external event.
     */
    uint32_t                 sensitivity;
    /**
     * @brief   Defines the frequency used to sample the External Event and
                the length of the digital filter.
     */
    uint32_t                 filter;
    /**
     * @brief   Indicates whether or not low latency mode is enabled for the
                external event.
     */
    uint32_t                 fast_mode;
} hrtim_eev_cfg_t;

/**
  * @brief  External Event Counter A configuration definition
  */
typedef struct {
    /**
     * @brief   Specifies the External Event Counter A Reset Mode.
     */
    uint32_t                 reset_mode;
    /**
     * @brief   Specifies the External Event Counter source selection..
     */
    uint32_t                 source;
    /**
     * @brief   Specifies the type of event filtering within the timing unit.
                This parameter can be a number between 0x0 and 0x3F.
     */
    uint32_t                 counter;
} hrtim_eev_counter_cfg_t;

/**
  * @brief  External event filtering in timing units configuration definition
  */
typedef struct {
    /**
     * @brief   Specifies the type of event filtering within the timing unit.
     */
    uint32_t                 filter;
    /**
     * @brief   Specifies whether or not the signal is latched.
     */
    uint32_t                 latch;
} hrtim_eev_fltr_cfg_t;
 
/**
 * @brief   HRTIM Fault prescaler.
 */
typedef enum{
    HRTIM_FAULTPRESCALER_DIV1,        /**< fFLTS=fHRTIM     */
    HRTIM_FAULTPRESCALER_DIV2,        /**< fFLTS=fHRTIM / 2 */
    HRTIM_FAULTPRESCALER_DIV4,        /**< fFLTS=fHRTIM / 4 */
    HRTIM_FAULTPRESCALER_DIV8         /**< fFLTS=fHRTIM / 8 */
}hrtim_fault_prsc_t;

/**
  * @brief  HRTIM Fault channel.
  */
typedef enum {
    HRTIM_FAULT_1,      /**< Fault channel 1 identifier */
    HRTIM_FAULT_2,      /**< Fault channel 2 identifier */
    HRTIM_FAULT_3,      /**< Fault channel 3 identifier */
    HRTIM_FAULT_4,      /**< Fault channel 4 identifier */
    HRTIM_FAULT_5,      /**< Fault channel 5 identifier */
    HRTIM_FAULT_6,      /**< Fault channel 6 identifier */
    HRTIM_NO_FAULT      /**< No fault                   */
} hrtim_fault_t;

/**
  * @brief  Fault channel configuration definition
  */
typedef struct
{
    /**
     * @brief   Identifies the fault input.
     */
    hrtim_fault_t            fault_idx;
    /**
     * @brief   Fault enable status flag.
     */
    bool                     enable;
    /**
     * @brief   Identifies the source of the fault.
     */
    uint32_t                 source;
    /**
     * @brief   Specifies the polarity of the fault event.
     */
    uint32_t                 polarity;
    /**
     * @brief   Defines the frequency used to sample the Fault input and the
     *          length of the digital filter.
     */
    uint32_t                 filter;
    /**
     * @brief   Indicates whether or not fault programming bits are write
     *          protected.
     */
    uint32_t                 lock;
} hrtim_fault_cfg_t;

/**
  * @brief  Fault channel blanking configuration definition
  */
typedef struct{
    /**
     * @brief   Specifies the Fault counter Threshold.
                This parameter can be a number between 0x0 and 0xF 
     */
    uint32_t                 threshold;
    /**
     * @brief   Specifies the reset mode of a fault event counter.
     */
    uint32_t                 reset_mode;
    /**
     * @brief   Specifies the blanking source of a fault event.
     */
    uint32_t                 blanking_source;
} hrtim_fault_blnk_cfg_t;

/**
 * @enum hrtim_output_state_t
 * Supported output states.
 */
typedef enum {
    HRTIM_OUTPUT_STATE_RUN,       /**< Output enabled        */
    HRTIM_OUTPUT_STATE_IDLE,      /**< Output in idle state  */
    HRTIM_OUTPUT_STATE_FAULT      /**< Output in fault state */
} hrtim_output_state_t;

/**
 * @enum hrtim_out_idlestate_t
 * Supported output levels when output is in idle state.
 */
typedef enum{
    HRTIM_OUTPUT_IDLESTATE_INACTIVE,   /**< Output to inactive level in idle state */
    HRTIM_OUTPUT_IDLESTATE_ACTIVE      /**< Output to active level in idle state   */
} hrtim_out_idlestate_t;

/**
 * @enum hrtim_out_faultstate_t
 * Supported output levels when output is in fault state.
 */
typedef enum{
    HRTIM_OUTPUT_FAULTSTATE_NOACTIVE,  /**< Output never in fault state              */
    HRTIM_OUTPUT_FAULTSTATE_ACTIVE,    /**< Output to active level in fault state    */
    HRTIM_OUTPUT_FAULTSTATE_INACTIVE,  /**< Output to inactive level in fault state  */
    HRTIM_OUTPUT_FAULTSTATE_HIGHZ      /**< Output tri-stated in fault state         */
} hrtim_out_faultstate_t;

/**
 * @enum hrtim_out_polarity_t
 * Supported timer output polarities.
 */
typedef enum{
    HRTIM_OUTPUT_POLARITY_POSITIVE,    /**< Output positive polarity (output active high) */
    HRTIM_OUTPUT_POLARITY_NEGATIVE     /**< Output negative polarity (output active low)  */
} hrtim_out_polarity_t;

/**
 * @brief Capture unit triggering sources definition
 */
typedef struct{
    /**
     * @brief   Specifies event(s) triggering capture unit 1.
     */
    uint32_t                 capture_trg_1;
    /**
     * @brief   Specifies event(s) triggering capture unit 2.
     */
    uint32_t                 capture_trg_2;
} hrtim_cpt_unit_cfg_t;

/**
 * @brief  Capture unit content definition
 */
typedef struct{
    /**
     * @brief   Holds the counter value when the capture event occurred. This
     *          parameter can be a number between 0x0 and 0xFFFFU.
     */
    uint32_t value;
    /**
     * @brief   Holds the counting direction value when the capture event
     *          occurred.
     */
    uint32_t dir;
} hrtim_cpt_value_t;

/**
 * @enum hrtim_cmp_t
 * Supported HRTIM capture units.
 */
typedef enum {
    HRTIM_CAPTUREUNIT_1,              /**< Capture unit 1 identifier */
    HRTIM_CAPTUREUNIT_2               /**< Capture unit 2 identifier */
} hrtim_cpt_t;

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

/* Export driver modules.*/
#include <hrtim_instances.h>


#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Initializes an HRTIM instance.
 *
 * @param[out] hdp      pointer to a @p hrtim_driver_t structure to be
 *                      initialized
 *
 * @api
 */
void hrtim_init(hrtim_driver_t *hdp);

/**
 * @brief   Configures HRTIM interrupt priority.
 * @note    This configuration becomes effective after hrtim_start.
 *
 * @param[out] hdp      pointer to a @p hrtim_driver_t structure
 * @param[in] prio      interrupt priority to be configured
 * @return              previous interrupt priority.
 *
 * @api
 */
uint32_t hrtim_set_prio(hrtim_driver_t *hdp, uint32_t prio);

/**
 * @brief   Configures HRTIM master/timer mode.
 * @note    This configuration becomes effective after hrtim_start.
 *
 * @param[out] hdp      pointer to a @p hrtim_driver_t structure
 * @param[in] timer     master/timer to be configured. It can be one of the
 *                      following values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 *            @arg @ref HRTIM_TIMER_MASTER
 * @param[in] mode      master/timer mode to be configured. It can be one of
 *                      following values:
 *            @arg @ref HRTIM_MODE_SINGLE_SHOT_NO_RETRIGGERED
 *            @arg @ref HRTIM_MODE_SINGLE_SHOT_RETRIGGERED
 *            @arg @ref HRTIM_MODE_CONTINUOS
 * @return              previous master/timer mode. It can be one of the
 *                      following values:
 *            @arg @ref HRTIM_MODE_SINGLE_SHOT_NO_RETRIGGERED
 *            @arg @ref HRTIM_MODE_SINGLE_SHOT_RETRIGGERED
 *            @arg @ref HRTIM_MODE_CONTINUOS
 *
 * @api
 */
hrtim_cntr_mode_t hrtim_set_timer_mode(hrtim_driver_t *hdp, hrtim_timer_t timer,
                                       hrtim_cntr_mode_t mode);

/**
 * @brief   Configures HRTIM master/timer prescaler value.
 * @note    This configuration becomes effective after hrtim_start if the HRTIM
 *          is disabled, or immediately if the HRTIM is enabled (update on-fly).
 *
 * @param[out] hdp      pointer to a @p hrtim_driver_t structure
 * @param[in] timer     master/timer to be configured. It can be one of the
 *                      following values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 *            @arg @ref HRTIM_TIMER_MASTER
 * @param[in] prescaler master/timer prescaler value to be configured. It can
 *                      be one of the following values:
 *            @arg @ref HRTIM_PRSC_DIV1
 *            @arg @ref HRTIM_PRSC_DIV2
 *            @arg @ref HRTIM_PRSC_DIV4
 *            @arg @ref HRTIM_PRSC_DIV8
 *            @arg @ref HRTIM_PRSC_DIV16
 *            @arg @ref HRTIM_PRSC_DIV32
 *            @arg @ref HRTIM_PRSC_DIV64
 *            @arg @ref HRTIM_PRSC_DIV128
 * @return              previous master/timer prescaler value. It can be one of
 *                      the following values:
 *            @arg @ref HRTIM_PRSC_DIV1
 *            @arg @ref HRTIM_PRSC_DIV2
 *            @arg @ref HRTIM_PRSC_DIV4
 *            @arg @ref HRTIM_PRSC_DIV8
 *            @arg @ref HRTIM_PRSC_DIV16
 *            @arg @ref HRTIM_PRSC_DIV32
 *            @arg @ref HRTIM_PRSC_DIV64
 *            @arg @ref HRTIM_PRSC_DIV128
 *
 * @api
 */
hrtim_prsc_t hrtim_timer_set_prescaler(hrtim_driver_t *hdp, hrtim_timer_t timer,
                                       hrtim_prsc_t prescaler);

/**
 * @brief   Returns HRTIM master/timer prescaler value.
 *
 * @param[out] hdp      pointer to a @p hrtim_driver_t structure
 * @param[in] timer     master/timer which the prescaler is related to. It can
 *                      be one of the following values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 *            @arg @ref HRTIM_TIMER_MASTER
 * @return              current master/timer prescaler value. It can be one of
 *                      the following values:
 *            @arg @ref HRTIM_PRSC_DIV1
 *            @arg @ref HRTIM_PRSC_DIV2
 *            @arg @ref HRTIM_PRSC_DIV4
 *            @arg @ref HRTIM_PRSC_DIV8
 *            @arg @ref HRTIM_PRSC_DIV16
 *            @arg @ref HRTIM_PRSC_DIV32
 *            @arg @ref HRTIM_PRSC_DIV64
 *            @arg @ref HRTIM_PRSC_DIV128
 *
 * @api
 */
hrtim_prsc_t hrtim_timer_get_prescaler(hrtim_driver_t *hdp, hrtim_timer_t timer);

/**
 * @brief   Configures HRTIM master/timer period value.
 * @note    This configuration becomes effective after hrtim_start if the HRTIM
 *          is disabled, or immediately if the HRTIM is enabled (update on-fly).
 * @note    Period is the numer of ticks of fHRCK (for more details, refer to
 *          the device reference manual).
 *
 * @param[out] hdp      pointer to a @p hrtim_driver_t structure
 * @param[in] timer     master/timer to be configured. It can be one of the
 *                      following values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 *            @arg @ref HRTIM_TIMER_MASTER
 * @param[in] period    master/timer period value to be configured.
 * @return              previous master/timer period value.
 *
 * @api
 */
uint16_t hrtim_timer_set_period(hrtim_driver_t *hdp, hrtim_timer_t timer,
                                uint16_t period);

/**
 * @brief   Returns HRTIM master/timer period value.
 * @note    Period is the numer of ticks of fHRCK (for more details, refer to
 *          the device reference manual).
 *
 * @param[out] hdp      pointer to a @p hrtim_driver_t structure
 * @param[in] timer     master/timer which the period is related to. It can be
 *                      one of the following values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 *            @arg @ref HRTIM_TIMER_MASTER
 * @return              current master/timer period value.
 *
 * @api
 */
uint16_t hrtim_timer_get_period(hrtim_driver_t *hdp, hrtim_timer_t timer);

/**
 * @brief   Configures HRTIM master/timer comparator value.
 * @note    This configuration becomes effective after hrtim_start if the HRTIM
 *          is disabled, or immediately if the HRTIM is enabled (update on-fly).
 *
 * @param[out] hdp      pointer to a @p hrtim_driver_t structure
 * @param[in] timer     master/timer to be configured. It can be one of the
 *                      following values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 *            @arg @ref HRTIM_TIMER_MASTER
 * @param[in] comparator master/timer comparator to be configured. It can be
 *                      one of the following values:
 *            @arg @ref HRTIM_CMP1
 *            @arg @ref HRTIM_CMP2
 *            @arg @ref HRTIM_CMP3
 *            @arg @ref HRTIM_CMP4
 * @param[in] value     master/timer comparator value to be configured.
 * @return              previous master/timer comparator value.
 *
 * @api
 */
uint16_t hrtim_timer_set_cmp(hrtim_driver_t *hdp, hrtim_timer_t timer,
                             hrtim_cmp_t comparator, uint16_t value);

/**
 * @brief   Returns HRTIM master/timer comparator value.
 *
 * @param[out] hdp      pointer to a @p hrtim_driver_t structure
 * @param[in] timer     master/timer which the comparator is related to. It can
 *                      be one of the following values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 *            @arg @ref HRTIM_TIMER_MASTER
 * @param[in] comparator master/timer comparator. It can be one of the
 *                      following values:
 *            @arg @ref HRTIM_CMP1
 *            @arg @ref HRTIM_CMP2
 *            @arg @ref HRTIM_CMP3
 *            @arg @ref HRTIM_CMP4
 * @return              current master/timer comparator value.
 *
 * @api
 */
uint16_t hrtim_timer_get_cmp(hrtim_driver_t *hdp, hrtim_timer_t timer,
                             hrtim_cmp_t comparator);

/**
 * @brief   Configures timer comparator auto-delayed mode.
 *
 * @param[out] hdp      pointer to a @p hrtim_driver_t structure
 * @param[in] timer     timer which the mode is related to. It can be one of
 *                      the following values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 * @param[in] comparator timer comparator. It can be one of the following
 *                      values:
 *            @arg @ref HRTIM_CMP2
 *            @arg @ref HRTIM_CMP4
 * @param[in] mode      timer comparator auto-delayed mode. It can be one of
 *                      the following values: 
 *            @arg @ref HRTIM_CMP_AD_MODE_STANDARD
 *            @arg @ref HRTIM_CMP_AD_MODE_CAP
 *            @arg @ref HRTIM_CMP_AD_MODE_CAP_COMP1
 *            @arg @ref HRTIM_CMP_AD_MODE_CAP_COMP3
 * @api
 */
void hrtim_timer_set_autodelay(hrtim_driver_t *hdp,
                               hrtim_timer_t timer,
                               hrtim_cmp_t comparator,
                               hrtim_cmp_ad_mode_t mode);

/**
 * @brief   Configures HRTIM timer deadtime.
 * @note    This configuration becomes effective after hrtim_start if the HRTIM
 *          is disabled, or immediately if the HRTIM is enabled (update on-fly).
 * @note    Deadtime is the numer of ticks of 1/tDTG (for more details, refer
 *          to the device reference manual).
 *
 * @param[out] hdp      pointer to a @p hrtim_driver_t structure
 * @param[in] timer     timer to be configured. It can be one of the following
 *                      values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 * @param[in] prescaler deadtime prescaler. It can be one of the following
 *            values:
 *            @arg @ref HRTIM_DT_PRSC_DIV8
 *            @arg @ref HRTIM_DT_PRSC_DIV4
 *            @arg @ref HRTIM_DT_PRSC_DIV2
 *            @arg @ref HRTIM_DT_PRSC_DIV1
 *            @arg @ref HRTIM_DT_PRSC_MUL2
 *            @arg @ref HRTIM_DT_PRSC_MUL4
 *            @arg @ref HRTIM_DT_PRSC_MUL8
 *            @arg @ref HRTIM_DT_PRSC_MUL16
 * @param[in] rvalue    deadtime rising value [0:1FFU]
 * @param[in] rsign     deadtime rising sign. It can be one of the following
 *                      values:
 *            @arg @ref HRTIM_DT_SIGN_POSITIVE
 *            @arg @ref HRTIM_DT_SIGN_NEGATIVE
 * @param[in] fvalue    deadtime falling value [0:1FFU]
 * @param[in] fsign     deadtime falling sign. It can be one of the following
 *                      values:
 *            @arg @ref HRTIM_DT_SIGN_POSITIVE
 *            @arg @ref HRTIM_DT_SIGN_NEGATIVE
 *
 * @api
 */
void hrtim_timer_set_deadtime(hrtim_driver_t *hdp, hrtim_timer_t timer,
                              hrtim_dt_prsc_t prescaler,
                              uint16_t rvalue, hrtim_dt_sign_t rsign,
                              uint16_t fvalue, hrtim_dt_sign_t fsign);

/**
 * @brief   Enables HRTIM timer deadtime.
 * @note    This configuration becomes effective after hrtim_start if the HRTIM
 *          is disabled, or immediately if the HRTIM is enabled (update on-fly).
 *
 * @param[out] hdp      pointer to a @p hrtim_driver_t structure
 * @param[in] timer     timer to be configured. It can be one of the following
 *                      values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 *
 * @api
 */
void hrtim_timer_enable_deadtime(hrtim_driver_t *hdp, hrtim_timer_t timer);

/**
 * @brief   Disables HRTIM timer deadtime.
 * @note    This configuration becomes effective after hrtim_start if the HRTIM
 *          is disabled, or immediately if the HRTIM is enabled (update on-fly).
 *
 * @param[out] hdp      pointer to a @p hrtim_driver_t structure
 * @param[in] timer     timer to be configured. It can be one of the following
 *                      values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 *
 * @api
 */
void hrtim_timer_disable_deadtime(hrtim_driver_t *hdp, hrtim_timer_t timer);

/**
 * @brief   Sets HRTIM output set event.
 * @note    A "set" event correspond to a transition to the output active state,
 *          while a "reset" event corresponds to a transition to the output
 *          inactive state. For timer output = 2, the event is set only if
 *          deadtime is disabled.
 * @note    This configuration becomes effective after hrtim_start if the HRTIM
 *          is disabled, or immediately if the HRTIM is enabled (update on-fly).
 *
 * @param[out] hdp      pointer to a @p hrtim_driver_t structure
 * @param[in] timer     timer to be configured. It can be one of the following
 *                      values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 * @param[in] output    timer output. It can be one of the following values:
 *            @arg @ref HRTIM_TIMER_OUTPUT_1
 *            @arg @ref HRTIM_TIMER_OUTPUT_2
 * @param[in] event     output set event to be set. It can be one of the
 *                      following values:
 *            @arg @ref HRTIM_OUTPUT_NONE
 *            @arg @ref HRTIM_OUTPUT_SST
 *            @arg @ref HRTIM_OUTPUT_RESYNC          
 *            @arg @ref HRTIM_OUTPUT_TIMPER          
 *            @arg @ref HRTIM_OUTPUT_TIMCMP1         
 *            @arg @ref HRTIM_OUTPUT_TIMCMP2         
 *            @arg @ref HRTIM_OUTPUT_TIMCMP3         
 *            @arg @ref HRTIM_OUTPUT_TIMCMP4         
 *            @arg @ref HRTIM_OUTPUT_MASTERPER       
 *            @arg @ref HRTIM_OUTPUT_MASTERCMP1      
 *            @arg @ref HRTIM_OUTPUT_MASTERCMP2      
 *            @arg @ref HRTIM_OUTPUT_MASTERCMP3      
 *            @arg @ref HRTIM_OUTPUT_MASTERCMP4      
 *            @arg @ref HRTIM_OUTPUT_TIMAEV1_TIMBCMP1
 *            @arg @ref HRTIM_OUTPUT_TIMAEV2_TIMBCMP2
 *            @arg @ref HRTIM_OUTPUT_TIMAEV3_TIMCCMP2
 *            @arg @ref HRTIM_OUTPUT_TIMAEV4_TIMCCMP3
 *            @arg @ref HRTIM_OUTPUT_TIMAEV5_TIMDCMP1
 *            @arg @ref HRTIM_OUTPUT_TIMAEV6_TIMDCMP2
 *            @arg @ref HRTIM_OUTPUT_TIMAEV7_TIMECMP3
 *            @arg @ref HRTIM_OUTPUT_TIMAEV8_TIMECMP4
 *            @arg @ref HRTIM_OUTPUT_TIMAEV9_TIMFCMP4
 *            @arg @ref HRTIM_OUTPUT_TIMBEV1_TIMACMP1
 *            @arg @ref HRTIM_OUTPUT_TIMBEV2_TIMACMP2
 *            @arg @ref HRTIM_OUTPUT_TIMBEV3_TIMCCMP3
 *            @arg @ref HRTIM_OUTPUT_TIMBEV4_TIMCCMP4
 *            @arg @ref HRTIM_OUTPUT_TIMBEV5_TIMDCMP3
 *            @arg @ref HRTIM_OUTPUT_TIMBEV6_TIMDCMP4
 *            @arg @ref HRTIM_OUTPUT_TIMBEV7_TIMECMP1
 *            @arg @ref HRTIM_OUTPUT_TIMBEV8_TIMECMP2
 *            @arg @ref HRTIM_OUTPUT_TIMBEV9_TIMFCMP3
 *            @arg @ref HRTIM_OUTPUT_TIMCEV1_TIMACMP2
 *            @arg @ref HRTIM_OUTPUT_TIMCEV2_TIMACMP3
 *            @arg @ref HRTIM_OUTPUT_TIMCEV3_TIMBCMP2
 *            @arg @ref HRTIM_OUTPUT_TIMCEV4_TIMBCMP3
 *            @arg @ref HRTIM_OUTPUT_TIMCEV5_TIMDCMP2 
 *            @arg @ref HRTIM_OUTPUT_TIMCEV6_TIMDCMP4 
 *            @arg @ref HRTIM_OUTPUT_TIMCEV7_TIMECMP3 
 *            @arg @ref HRTIM_OUTPUT_TIMCEV8_TIMECMP4 
 *            @arg @ref HRTIM_OUTPUT_TIMCEV9_TIMFCMP2 
 *            @arg @ref HRTIM_OUTPUT_TIMDEV1_TIMACMP1 
 *            @arg @ref HRTIM_OUTPUT_TIMDEV2_TIMACMP4 
 *            @arg @ref HRTIM_OUTPUT_TIMDEV3_TIMBCMP2 
 *            @arg @ref HRTIM_OUTPUT_TIMDEV4_TIMBCMP4 
 *            @arg @ref HRTIM_OUTPUT_TIMDEV5_TIMCCMP4 
 *            @arg @ref HRTIM_OUTPUT_TIMDEV6_TIMECMP1 
 *            @arg @ref HRTIM_OUTPUT_TIMDEV7_TIMECMP4 
 *            @arg @ref HRTIM_OUTPUT_TIMDEV8_TIMFCMP1 
 *            @arg @ref HRTIM_OUTPUT_TIMDEV9_TIMFCMP3 
 *            @arg @ref HRTIM_OUTPUT_TIMEEV1_TIMACMP4 
 *            @arg @ref HRTIM_OUTPUT_TIMEEV2_TIMBCMP3 
 *            @arg @ref HRTIM_OUTPUT_TIMEEV3_TIMBCMP4 
 *            @arg @ref HRTIM_OUTPUT_TIMEEV4_TIMCCMP1 
 *            @arg @ref HRTIM_OUTPUT_TIMEEV5_TIMCCMP2 
 *            @arg @ref HRTIM_OUTPUT_TIMEEV6_TIMDCMP1 
 *            @arg @ref HRTIM_OUTPUT_TIMEEV7_TIMDCMP2 
 *            @arg @ref HRTIM_OUTPUT_TIMEEV8_TIMFCMP3 
 *            @arg @ref HRTIM_OUTPUT_TIMEEV9_TIMFCMP4 
 *            @arg @ref HRTIM_OUTPUT_TIMFEV1_TIMACMP3 
 *            @arg @ref HRTIM_OUTPUT_TIMFEV2_TIMBCMP1 
 *            @arg @ref HRTIM_OUTPUT_TIMFEV3_TIMBCMP4 
 *            @arg @ref HRTIM_OUTPUT_TIMFEV4_TIMCCMP1 
 *            @arg @ref HRTIM_OUTPUT_TIMFEV5_TIMCCMP4 
 *            @arg @ref HRTIM_OUTPUT_TIMFEV6_TIMDCMP3 
 *            @arg @ref HRTIM_OUTPUT_TIMFEV7_TIMDCMP4 
 *            @arg @ref HRTIM_OUTPUT_TIMFEV8_TIMECMP2 
 *            @arg @ref HRTIM_OUTPUT_TIMFEV9_TIMECMP3 
 *            @arg @ref HRTIM_OUTPUT_EEV_1            
 *            @arg @ref HRTIM_OUTPUT_EEV_2            
 *            @arg @ref HRTIM_OUTPUT_EEV_3            
 *            @arg @ref HRTIM_OUTPUT_EEV_4            
 *            @arg @ref HRTIM_OUTPUT_EEV_5            
 *            @arg @ref HRTIM_OUTPUT_EEV_6            
 *            @arg @ref HRTIM_OUTPUT_EEV_7            
 *            @arg @ref HRTIM_OUTPUT_EEV_8            
 *            @arg @ref HRTIM_OUTPUT_EEV_9            
 *            @arg @ref HRTIM_OUTPUT_EEV_10           
 *            @arg @ref HRTIM_OUTPUT_UPDATE           
 * @return              previous output set event.
 *
 * @api
 */
uint32_t hrtim_timer_set_outputset(hrtim_driver_t *hdp,
                                   hrtim_timer_t timer,
                                   hrtim_out_t output,
                                   uint32_t event);

/**
 * @brief   Sets HRTIM output reset event.
 * @note    A "set" event correspond to a transition to the output active state,
 *          while a "reset" event corresponds to a transition to the output
 *          inactive state. For timer output = 2, the event is set only if
 *          deadtime is disabled.
 * @note    This configuration becomes effective after hrtim_start if the HRTIM
 *          is disabled, or immediately if the HRTIM is enabled (update on-fly).
 *
 * @param[out] hdp      pointer to a @p hrtim_driver_t structure
 * @param[in] timer     timer to be configured. It can be one of the following
 *                      values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 * @param[in] output    timer output. It can be one of the following values:
 *            @arg @ref HRTIM_TIMER_OUTPUT_1
 *            @arg @ref HRTIM_TIMER_OUTPUT_2
 * @param[in] event     output reset event to be set. It can be one of the
 *                      following values:
 *            @arg @ref HRTIM_OUTPUT_NONE
 *            @arg @ref HRTIM_OUTPUT_SST
 *            @arg @ref HRTIM_OUTPUT_RESYNC          
 *            @arg @ref HRTIM_OUTPUT_TIMPER          
 *            @arg @ref HRTIM_OUTPUT_TIMCMP1         
 *            @arg @ref HRTIM_OUTPUT_TIMCMP2         
 *            @arg @ref HRTIM_OUTPUT_TIMCMP3         
 *            @arg @ref HRTIM_OUTPUT_TIMCMP4         
 *            @arg @ref HRTIM_OUTPUT_MASTERPER       
 *            @arg @ref HRTIM_OUTPUT_MASTERCMP1      
 *            @arg @ref HRTIM_OUTPUT_MASTERCMP2      
 *            @arg @ref HRTIM_OUTPUT_MASTERCMP3      
 *            @arg @ref HRTIM_OUTPUT_MASTERCMP4      
 *            @arg @ref HRTIM_OUTPUT_TIMAEV1_TIMBCMP1
 *            @arg @ref HRTIM_OUTPUT_TIMAEV2_TIMBCMP2
 *            @arg @ref HRTIM_OUTPUT_TIMAEV3_TIMCCMP2
 *            @arg @ref HRTIM_OUTPUT_TIMAEV4_TIMCCMP3
 *            @arg @ref HRTIM_OUTPUT_TIMAEV5_TIMDCMP1
 *            @arg @ref HRTIM_OUTPUT_TIMAEV6_TIMDCMP2
 *            @arg @ref HRTIM_OUTPUT_TIMAEV7_TIMECMP3
 *            @arg @ref HRTIM_OUTPUT_TIMAEV8_TIMECMP4
 *            @arg @ref HRTIM_OUTPUT_TIMAEV9_TIMFCMP4
 *            @arg @ref HRTIM_OUTPUT_TIMBEV1_TIMACMP1
 *            @arg @ref HRTIM_OUTPUT_TIMBEV2_TIMACMP2
 *            @arg @ref HRTIM_OUTPUT_TIMBEV3_TIMCCMP3
 *            @arg @ref HRTIM_OUTPUT_TIMBEV4_TIMCCMP4
 *            @arg @ref HRTIM_OUTPUT_TIMBEV5_TIMDCMP3
 *            @arg @ref HRTIM_OUTPUT_TIMBEV6_TIMDCMP4
 *            @arg @ref HRTIM_OUTPUT_TIMBEV7_TIMECMP1
 *            @arg @ref HRTIM_OUTPUT_TIMBEV8_TIMECMP2
 *            @arg @ref HRTIM_OUTPUT_TIMBEV9_TIMFCMP3
 *            @arg @ref HRTIM_OUTPUT_TIMCEV1_TIMACMP2
 *            @arg @ref HRTIM_OUTPUT_TIMCEV2_TIMACMP3
 *            @arg @ref HRTIM_OUTPUT_TIMCEV3_TIMBCMP2
 *            @arg @ref HRTIM_OUTPUT_TIMCEV4_TIMBCMP3
 *            @arg @ref HRTIM_OUTPUT_TIMCEV5_TIMDCMP2
 *            @arg @ref HRTIM_OUTPUT_TIMCEV6_TIMDCMP4
 *            @arg @ref HRTIM_OUTPUT_TIMCEV7_TIMECMP3
 *            @arg @ref HRTIM_OUTPUT_TIMCEV8_TIMECMP4
 *            @arg @ref HRTIM_OUTPUT_TIMCEV9_TIMFCMP2
 *            @arg @ref HRTIM_OUTPUT_TIMDEV1_TIMACMP1
 *            @arg @ref HRTIM_OUTPUT_TIMDEV2_TIMACMP4
 *            @arg @ref HRTIM_OUTPUT_TIMDEV3_TIMBCMP2
 *            @arg @ref HRTIM_OUTPUT_TIMDEV4_TIMBCMP4
 *            @arg @ref HRTIM_OUTPUT_TIMDEV5_TIMCCMP4
 *            @arg @ref HRTIM_OUTPUT_TIMDEV6_TIMECMP1
 *            @arg @ref HRTIM_OUTPUT_TIMDEV7_TIMECMP4
 *            @arg @ref HRTIM_OUTPUT_TIMDEV8_TIMFCMP1
 *            @arg @ref HRTIM_OUTPUT_TIMDEV9_TIMFCMP3
 *            @arg @ref HRTIM_OUTPUT_TIMEEV1_TIMACMP4
 *            @arg @ref HRTIM_OUTPUT_TIMEEV2_TIMBCMP3
 *            @arg @ref HRTIM_OUTPUT_TIMEEV3_TIMBCMP4
 *            @arg @ref HRTIM_OUTPUT_TIMEEV4_TIMCCMP1
 *            @arg @ref HRTIM_OUTPUT_TIMEEV5_TIMCCMP2
 *            @arg @ref HRTIM_OUTPUT_TIMEEV6_TIMDCMP1
 *            @arg @ref HRTIM_OUTPUT_TIMEEV7_TIMDCMP2
 *            @arg @ref HRTIM_OUTPUT_TIMEEV8_TIMFCMP3
 *            @arg @ref HRTIM_OUTPUT_TIMEEV9_TIMFCMP4
 *            @arg @ref HRTIM_OUTPUT_TIMFEV1_TIMACMP3
 *            @arg @ref HRTIM_OUTPUT_TIMFEV2_TIMBCMP1
 *            @arg @ref HRTIM_OUTPUT_TIMFEV3_TIMBCMP4
 *            @arg @ref HRTIM_OUTPUT_TIMFEV4_TIMCCMP1
 *            @arg @ref HRTIM_OUTPUT_TIMFEV5_TIMCCMP4
 *            @arg @ref HRTIM_OUTPUT_TIMFEV6_TIMDCMP3
 *            @arg @ref HRTIM_OUTPUT_TIMFEV7_TIMDCMP4
 *            @arg @ref HRTIM_OUTPUT_TIMFEV8_TIMECMP2
 *            @arg @ref HRTIM_OUTPUT_TIMFEV9_TIMECMP3
 *            @arg @ref HRTIM_OUTPUT_EEV_1           
 *            @arg @ref HRTIM_OUTPUT_EEV_2           
 *            @arg @ref HRTIM_OUTPUT_EEV_3           
 *            @arg @ref HRTIM_OUTPUT_EEV_4           
 *            @arg @ref HRTIM_OUTPUT_EEV_5           
 *            @arg @ref HRTIM_OUTPUT_EEV_6           
 *            @arg @ref HRTIM_OUTPUT_EEV_7           
 *            @arg @ref HRTIM_OUTPUT_EEV_8           
 *            @arg @ref HRTIM_OUTPUT_EEV_9           
 *            @arg @ref HRTIM_OUTPUT_EEV_10          
 *            @arg @ref HRTIM_OUTPUT_UPDATE          
 * @return              previous output reset event.
 *
 * @api
 */
uint32_t hrtim_timer_set_outputrst(hrtim_driver_t *hdp,
                                   hrtim_timer_t timer,
                                   hrtim_out_t output,
                                   uint32_t event);

/**
 * @brief   Clears HRTIM output set event.
 * @note    A "set" event correspond to a transition to the output active state,
 *          while a "reset" event corresponds to a transition to the output
 *          inactive state. For timer output = 2, the event is set only if
 *          deadtime is disabled.
 * @note    This configuration becomes effective after hrtim_start if the HRTIM
 *          is disabled, or immediately if the HRTIM is enabled (update on-fly).
 *
 * @param[out] hdp      pointer to a @p hrtim_driver_t structure
 * @param[in] timer     timer to be configured. It can be one of the following
 *                      values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 * @param[in] output    timer output. It can be one of the following values:
 *            @arg @ref HRTIM_TIMER_OUTPUT_1
 *            @arg @ref HRTIM_TIMER_OUTPUT_2
 * @param[in] event     output set event to be cleared. It can be one of the
 *                      following values:
 *            @arg @ref HRTIM_OUTPUT_NONE
 *            @arg @ref HRTIM_OUTPUT_SST
 *            @arg @ref HRTIM_OUTPUT_RESYNC          
 *            @arg @ref HRTIM_OUTPUT_TIMPER          
 *            @arg @ref HRTIM_OUTPUT_TIMCMP1         
 *            @arg @ref HRTIM_OUTPUT_TIMCMP2         
 *            @arg @ref HRTIM_OUTPUT_TIMCMP3         
 *            @arg @ref HRTIM_OUTPUT_TIMCMP4         
 *            @arg @ref HRTIM_OUTPUT_MASTERPER       
 *            @arg @ref HRTIM_OUTPUT_MASTERCMP1      
 *            @arg @ref HRTIM_OUTPUT_MASTERCMP2      
 *            @arg @ref HRTIM_OUTPUT_MASTERCMP3      
 *            @arg @ref HRTIM_OUTPUT_MASTERCMP4      
 *            @arg @ref HRTIM_OUTPUT_TIMAEV1_TIMBCMP1
 *            @arg @ref HRTIM_OUTPUT_TIMAEV2_TIMBCMP2
 *            @arg @ref HRTIM_OUTPUT_TIMAEV3_TIMCCMP2
 *            @arg @ref HRTIM_OUTPUT_TIMAEV4_TIMCCMP3
 *            @arg @ref HRTIM_OUTPUT_TIMAEV5_TIMDCMP1
 *            @arg @ref HRTIM_OUTPUT_TIMAEV6_TIMDCMP2
 *            @arg @ref HRTIM_OUTPUT_TIMAEV7_TIMECMP3
 *            @arg @ref HRTIM_OUTPUT_TIMAEV8_TIMECMP4
 *            @arg @ref HRTIM_OUTPUT_TIMAEV9_TIMFCMP4
 *            @arg @ref HRTIM_OUTPUT_TIMBEV1_TIMACMP1
 *            @arg @ref HRTIM_OUTPUT_TIMBEV2_TIMACMP2
 *            @arg @ref HRTIM_OUTPUT_TIMBEV3_TIMCCMP3
 *            @arg @ref HRTIM_OUTPUT_TIMBEV4_TIMCCMP4
 *            @arg @ref HRTIM_OUTPUT_TIMBEV5_TIMDCMP3
 *            @arg @ref HRTIM_OUTPUT_TIMBEV6_TIMDCMP4
 *            @arg @ref HRTIM_OUTPUT_TIMBEV7_TIMECMP1
 *            @arg @ref HRTIM_OUTPUT_TIMBEV8_TIMECMP2
 *            @arg @ref HRTIM_OUTPUT_TIMBEV9_TIMFCMP3
 *            @arg @ref HRTIM_OUTPUT_TIMCEV1_TIMACMP2
 *            @arg @ref HRTIM_OUTPUT_TIMCEV2_TIMACMP3
 *            @arg @ref HRTIM_OUTPUT_TIMCEV3_TIMBCMP2
 *            @arg @ref HRTIM_OUTPUT_TIMCEV4_TIMBCMP3
 *            @arg @ref HRTIM_OUTPUT_TIMCEV5_TIMDCMP2
 *            @arg @ref HRTIM_OUTPUT_TIMCEV6_TIMDCMP4
 *            @arg @ref HRTIM_OUTPUT_TIMCEV7_TIMECMP3
 *            @arg @ref HRTIM_OUTPUT_TIMCEV8_TIMECMP4
 *            @arg @ref HRTIM_OUTPUT_TIMCEV9_TIMFCMP2
 *            @arg @ref HRTIM_OUTPUT_TIMDEV1_TIMACMP1
 *            @arg @ref HRTIM_OUTPUT_TIMDEV2_TIMACMP4
 *            @arg @ref HRTIM_OUTPUT_TIMDEV3_TIMBCMP2
 *            @arg @ref HRTIM_OUTPUT_TIMDEV4_TIMBCMP4
 *            @arg @ref HRTIM_OUTPUT_TIMDEV5_TIMCCMP4
 *            @arg @ref HRTIM_OUTPUT_TIMDEV6_TIMECMP1
 *            @arg @ref HRTIM_OUTPUT_TIMDEV7_TIMECMP4
 *            @arg @ref HRTIM_OUTPUT_TIMDEV8_TIMFCMP1
 *            @arg @ref HRTIM_OUTPUT_TIMDEV9_TIMFCMP3
 *            @arg @ref HRTIM_OUTPUT_TIMEEV1_TIMACMP4
 *            @arg @ref HRTIM_OUTPUT_TIMEEV2_TIMBCMP3
 *            @arg @ref HRTIM_OUTPUT_TIMEEV3_TIMBCMP4
 *            @arg @ref HRTIM_OUTPUT_TIMEEV4_TIMCCMP1
 *            @arg @ref HRTIM_OUTPUT_TIMEEV5_TIMCCMP2
 *            @arg @ref HRTIM_OUTPUT_TIMEEV6_TIMDCMP1
 *            @arg @ref HRTIM_OUTPUT_TIMEEV7_TIMDCMP2
 *            @arg @ref HRTIM_OUTPUT_TIMEEV8_TIMFCMP3
 *            @arg @ref HRTIM_OUTPUT_TIMEEV9_TIMFCMP4
 *            @arg @ref HRTIM_OUTPUT_TIMFEV1_TIMACMP3
 *            @arg @ref HRTIM_OUTPUT_TIMFEV2_TIMBCMP1
 *            @arg @ref HRTIM_OUTPUT_TIMFEV3_TIMBCMP4
 *            @arg @ref HRTIM_OUTPUT_TIMFEV4_TIMCCMP1
 *            @arg @ref HRTIM_OUTPUT_TIMFEV5_TIMCCMP4
 *            @arg @ref HRTIM_OUTPUT_TIMFEV6_TIMDCMP3
 *            @arg @ref HRTIM_OUTPUT_TIMFEV7_TIMDCMP4
 *            @arg @ref HRTIM_OUTPUT_TIMFEV8_TIMECMP2
 *            @arg @ref HRTIM_OUTPUT_TIMFEV9_TIMECMP3
 *            @arg @ref HRTIM_OUTPUT_EEV_1           
 *            @arg @ref HRTIM_OUTPUT_EEV_2           
 *            @arg @ref HRTIM_OUTPUT_EEV_3           
 *            @arg @ref HRTIM_OUTPUT_EEV_4           
 *            @arg @ref HRTIM_OUTPUT_EEV_5           
 *            @arg @ref HRTIM_OUTPUT_EEV_6           
 *            @arg @ref HRTIM_OUTPUT_EEV_7           
 *            @arg @ref HRTIM_OUTPUT_EEV_8           
 *            @arg @ref HRTIM_OUTPUT_EEV_9           
 *            @arg @ref HRTIM_OUTPUT_EEV_10          
 *            @arg @ref HRTIM_OUTPUT_UPDATE          
 * @return              previous output set event.
 *
 * @api
 */
uint32_t hrtim_timer_clear_outputset(hrtim_driver_t *hdp,
                                     hrtim_timer_t timer,
                                     hrtim_out_t output,
                                     uint32_t event);

/**
 * @brief   Clears HRTIM output reset event.
 * @note    A "set" event correspond to a transition to the output active state,
 *          while a "reset" event corresponds to a transition to the output
 *          inactive state. For timer output = 2, the event is set only if
 *          deadtime is disabled.
 * @note    This configuration becomes effective after hrtim_start if the HRTIM
 *          is disabled, or immediately if the HRTIM is enabled (update on-fly).
 *
 * @param[out] hdp      pointer to a @p hrtim_driver_t structure
 * @param[in] timer     timer to be configured. It can be one of the following
 *                      values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 * @param[in] output    timer output. It can be one of the following values:
 *            @arg @ref HRTIM_TIMER_OUTPUT_1
 *            @arg @ref HRTIM_TIMER_OUTPUT_2
 * @param[in] event     output reset event to be cleared. It can be one of the
 *                      following values:
 *            @arg @ref HRTIM_OUTPUT_NONE
 *            @arg @ref HRTIM_OUTPUT_SST
 *            @arg @ref HRTIM_OUTPUT_RESYNC          
 *            @arg @ref HRTIM_OUTPUT_TIMPER          
 *            @arg @ref HRTIM_OUTPUT_TIMCMP1         
 *            @arg @ref HRTIM_OUTPUT_TIMCMP2         
 *            @arg @ref HRTIM_OUTPUT_TIMCMP3         
 *            @arg @ref HRTIM_OUTPUT_TIMCMP4         
 *            @arg @ref HRTIM_OUTPUT_MASTERPER       
 *            @arg @ref HRTIM_OUTPUT_MASTERCMP1      
 *            @arg @ref HRTIM_OUTPUT_MASTERCMP2      
 *            @arg @ref HRTIM_OUTPUT_MASTERCMP3      
 *            @arg @ref HRTIM_OUTPUT_MASTERCMP4      
 *            @arg @ref HRTIM_OUTPUT_TIMAEV1_TIMBCMP1
 *            @arg @ref HRTIM_OUTPUT_TIMAEV2_TIMBCMP2
 *            @arg @ref HRTIM_OUTPUT_TIMAEV3_TIMCCMP2
 *            @arg @ref HRTIM_OUTPUT_TIMAEV4_TIMCCMP3
 *            @arg @ref HRTIM_OUTPUT_TIMAEV5_TIMDCMP1
 *            @arg @ref HRTIM_OUTPUT_TIMAEV6_TIMDCMP2
 *            @arg @ref HRTIM_OUTPUT_TIMAEV7_TIMECMP3
 *            @arg @ref HRTIM_OUTPUT_TIMAEV8_TIMECMP4
 *            @arg @ref HRTIM_OUTPUT_TIMAEV9_TIMFCMP4
 *            @arg @ref HRTIM_OUTPUT_TIMBEV1_TIMACMP1
 *            @arg @ref HRTIM_OUTPUT_TIMBEV2_TIMACMP2
 *            @arg @ref HRTIM_OUTPUT_TIMBEV3_TIMCCMP3
 *            @arg @ref HRTIM_OUTPUT_TIMBEV4_TIMCCMP4
 *            @arg @ref HRTIM_OUTPUT_TIMBEV5_TIMDCMP3
 *            @arg @ref HRTIM_OUTPUT_TIMBEV6_TIMDCMP4
 *            @arg @ref HRTIM_OUTPUT_TIMBEV7_TIMECMP1
 *            @arg @ref HRTIM_OUTPUT_TIMBEV8_TIMECMP2
 *            @arg @ref HRTIM_OUTPUT_TIMBEV9_TIMFCMP3
 *            @arg @ref HRTIM_OUTPUT_TIMCEV1_TIMACMP2
 *            @arg @ref HRTIM_OUTPUT_TIMCEV2_TIMACMP3
 *            @arg @ref HRTIM_OUTPUT_TIMCEV3_TIMBCMP2
 *            @arg @ref HRTIM_OUTPUT_TIMCEV4_TIMBCMP3
 *            @arg @ref HRTIM_OUTPUT_TIMCEV5_TIMDCMP2
 *            @arg @ref HRTIM_OUTPUT_TIMCEV6_TIMDCMP4
 *            @arg @ref HRTIM_OUTPUT_TIMCEV7_TIMECMP3
 *            @arg @ref HRTIM_OUTPUT_TIMCEV8_TIMECMP4
 *            @arg @ref HRTIM_OUTPUT_TIMCEV9_TIMFCMP2
 *            @arg @ref HRTIM_OUTPUT_TIMDEV1_TIMACMP1
 *            @arg @ref HRTIM_OUTPUT_TIMDEV2_TIMACMP4
 *            @arg @ref HRTIM_OUTPUT_TIMDEV3_TIMBCMP2
 *            @arg @ref HRTIM_OUTPUT_TIMDEV4_TIMBCMP4
 *            @arg @ref HRTIM_OUTPUT_TIMDEV5_TIMCCMP4
 *            @arg @ref HRTIM_OUTPUT_TIMDEV6_TIMECMP1
 *            @arg @ref HRTIM_OUTPUT_TIMDEV7_TIMECMP4
 *            @arg @ref HRTIM_OUTPUT_TIMDEV8_TIMFCMP1
 *            @arg @ref HRTIM_OUTPUT_TIMDEV9_TIMFCMP3
 *            @arg @ref HRTIM_OUTPUT_TIMEEV1_TIMACMP4
 *            @arg @ref HRTIM_OUTPUT_TIMEEV2_TIMBCMP3
 *            @arg @ref HRTIM_OUTPUT_TIMEEV3_TIMBCMP4
 *            @arg @ref HRTIM_OUTPUT_TIMEEV4_TIMCCMP1
 *            @arg @ref HRTIM_OUTPUT_TIMEEV5_TIMCCMP2
 *            @arg @ref HRTIM_OUTPUT_TIMEEV6_TIMDCMP1
 *            @arg @ref HRTIM_OUTPUT_TIMEEV7_TIMDCMP2
 *            @arg @ref HRTIM_OUTPUT_TIMEEV8_TIMFCMP3
 *            @arg @ref HRTIM_OUTPUT_TIMEEV9_TIMFCMP4
 *            @arg @ref HRTIM_OUTPUT_TIMFEV1_TIMACMP3
 *            @arg @ref HRTIM_OUTPUT_TIMFEV2_TIMBCMP1
 *            @arg @ref HRTIM_OUTPUT_TIMFEV3_TIMBCMP4
 *            @arg @ref HRTIM_OUTPUT_TIMFEV4_TIMCCMP1
 *            @arg @ref HRTIM_OUTPUT_TIMFEV5_TIMCCMP4
 *            @arg @ref HRTIM_OUTPUT_TIMFEV6_TIMDCMP3
 *            @arg @ref HRTIM_OUTPUT_TIMFEV7_TIMDCMP4
 *            @arg @ref HRTIM_OUTPUT_TIMFEV8_TIMECMP2
 *            @arg @ref HRTIM_OUTPUT_TIMFEV9_TIMECMP3
 *            @arg @ref HRTIM_OUTPUT_EEV_1           
 *            @arg @ref HRTIM_OUTPUT_EEV_2           
 *            @arg @ref HRTIM_OUTPUT_EEV_3           
 *            @arg @ref HRTIM_OUTPUT_EEV_4           
 *            @arg @ref HRTIM_OUTPUT_EEV_5           
 *            @arg @ref HRTIM_OUTPUT_EEV_6           
 *            @arg @ref HRTIM_OUTPUT_EEV_7           
 *            @arg @ref HRTIM_OUTPUT_EEV_8           
 *            @arg @ref HRTIM_OUTPUT_EEV_9           
 *            @arg @ref HRTIM_OUTPUT_EEV_10          
 *            @arg @ref HRTIM_OUTPUT_UPDATE          
 * @return              previous output reset event.
 *
 * @api
 */
uint32_t hrtim_timer_clear_outputrst(hrtim_driver_t *hdp,
                                     hrtim_timer_t timer,
                                     hrtim_out_t output,
                                     uint32_t event);

/**
 * @brief   Configures pointers to HRTIM callback functions.
 *
 * @param[out] hdp      pointer to a @p hrtim_driver_t structure
 * @param[in] cb_op     callback operation type. It can be one of the following
 *                      values:
 *            @arg @ref HRTIM_CB_TIMER_A
 *            @arg @ref HRTIM_CB_TIMER_B
 *            @arg @ref HRTIM_CB_TIMER_C
 *            @arg @ref HRTIM_CB_TIMER_D
 *            @arg @ref HRTIM_CB_TIMER_E
 *            @arg @ref HRTIM_CB_TIMER_F
 *            @arg @ref HRTIM_CB_MASTER
 *            @arg @ref HRTIM_CB_FAULT
 * @param[in] cb        pointer to HRTIM callback function
 * @return              pointer to previuos HRTIM callback function.
 *
 * @api
 */
hrtim_cb_t hrtim_set_cb(hrtim_driver_t *hdp, hrtim_cb_ops_t cb_op,
                        hrtim_cb_t cb);

/**
 * @brief   Starts a HRTIM instance.
 *
 * @param[in] hdp       pointer to a @p hrtim_driver_t structure
 *
 * @api
 */
void hrtim_start(hrtim_driver_t *hdp);

/**
 * @brief   Enables callback for a specified event.
 * @note    This function must be invoked after hrtim_start, otherwise it has
 *          no effect.
 *
 * @param[out] hdp      pointer to a @p hrtim_driver_t structure
 * @param[in] cb_op     callback to be enabled. It can be one of the following
 *                      values:
 *            @arg @ref HRTIM_CB_TIMER_A
 *            @arg @ref HRTIM_CB_TIMER_B
 *            @arg @ref HRTIM_CB_TIMER_C
 *            @arg @ref HRTIM_CB_TIMER_D
 *            @arg @ref HRTIM_CB_TIMER_E
 *            @arg @ref HRTIM_CB_TIMER_F
 *            @arg @ref HRTIM_CB_MASTER
 *            @arg @ref HRTIM_CB_FAULT
 * @param[in] event     event related to callback to be enabled. For master
 *                      callbacks (cb_op = HRTIM_CB_MASTER), it can be one of
 *                      the following values:
 *            @arg @ref HRTIM_CB_EVENT_CMP1
 *            @arg @ref HRTIM_CB_EVENT_CMP2
 *            @arg @ref HRTIM_CB_EVENT_CMP3
 *            @arg @ref HRTIM_CB_EVENT_CMP4
 *            @arg @ref HRTIM_CB_EVENT_REP
 *            @arg @ref HRTIM_CB_EVENT_SYNC
 *            @arg @ref HRTIM_CB_EVENT_UPD
 *                      For timer callbacks (cb_op = HRTIM_CB_TIMER_x), it can
 *                      be one of the following values:
 *            @arg @ref HRTIM_CB_EVENT_CMP1
 *            @arg @ref HRTIM_CB_EVENT_CMP2
 *            @arg @ref HRTIM_CB_EVENT_CMP3
 *            @arg @ref HRTIM_CB_EVENT_CMP4
 *            @arg @ref HRTIM_CB_EVENT_REP
 *            @arg @ref HRTIM_CB_EVENT_UPD
 *                      For fault callbacks (cb_op = HRTIM_CB_FAULT), it can be
 *                      one of the following values:
 *            @arg @ref HRTIM_CB_EVENT_FAULT1
 *            @arg @ref HRTIM_CB_EVENT_FAULT2
 *            @arg @ref HRTIM_CB_EVENT_FAULT3
 *            @arg @ref HRTIM_CB_EVENT_FAULT4
 *            @arg @ref HRTIM_CB_EVENT_FAULT5
 *            @arg @ref HRTIM_CB_EVENT_SYSFAULT
 *            @arg @ref HRTIM_CB_EVENT_FAULT6
 *
 * @api
 */
void hrtim_enable_cb(hrtim_driver_t *hdp, hrtim_cb_ops_t cb_op,
                     uint8_t event);

/**
 * @brief   Disables callback for a specified event.
 * @note    This function must be invoked after hrtim_start, otherwise it has
 *          no effect.
 *
 * @param[out] hdp      pointer to a @p hrtim_driver_t structure
 * @param[in] cb_op     callback to be enabled. It can be one of the following
 *                      values:
 *            @arg @ref HRTIM_CB_TIMER_A
 *            @arg @ref HRTIM_CB_TIMER_B
 *            @arg @ref HRTIM_CB_TIMER_C
 *            @arg @ref HRTIM_CB_TIMER_D
 *            @arg @ref HRTIM_CB_TIMER_E
 *            @arg @ref HRTIM_CB_TIMER_F
 *            @arg @ref HRTIM_CB_MASTER
 *            @arg @ref HRTIM_CB_FAULT
 * @param[in] event     event related to callback to be enabled. For master
 *                      callbacks (cb_op = HRTIM_CB_MASTER), it can be one of
 *                      the following values:
 *            @arg @ref HRTIM_CB_EVENT_CMP1
 *            @arg @ref HRTIM_CB_EVENT_CMP2
 *            @arg @ref HRTIM_CB_EVENT_CMP3
 *            @arg @ref HRTIM_CB_EVENT_CMP4
 *            @arg @ref HRTIM_CB_EVENT_REP
 *            @arg @ref HRTIM_CB_EVENT_SYNC
 *            @arg @ref HRTIM_CB_EVENT_UPD
 *                      For timer callbacks (cb_op = HRTIM_CB_TIMER_x), it can
 *                      be one of the following values:
 *            @arg @ref HRTIM_CB_EVENT_CMP1
 *            @arg @ref HRTIM_CB_EVENT_CMP2
 *            @arg @ref HRTIM_CB_EVENT_CMP3
 *            @arg @ref HRTIM_CB_EVENT_CMP4
 *            @arg @ref HRTIM_CB_EVENT_REP
 *            @arg @ref HRTIM_CB_EVENT_UPD
 *                      For fault callbacks (cb_op = HRTIM_CB_FAULT), it can be
 *                      one of the following values:
 *            @arg @ref HRTIM_CB_EVENT_FAULT1
 *            @arg @ref HRTIM_CB_EVENT_FAULT2
 *            @arg @ref HRTIM_CB_EVENT_FAULT3
 *            @arg @ref HRTIM_CB_EVENT_FAULT4
 *            @arg @ref HRTIM_CB_EVENT_FAULT5
 *            @arg @ref HRTIM_CB_EVENT_SYSFAULT
 *            @arg @ref HRTIM_CB_EVENT_FAULT6
 *
 * @api
 */
void hrtim_disable_cb(hrtim_driver_t *hdp, hrtim_cb_ops_t cb_op,
                      uint8_t event);

/**
 * @brief   Enables HRTIM timer output.
 * @note    This function must be invoked after hrtim_start, otherwise it has
 *          no effect.
 *
 * @param[out] hdp      pointer to a @p hrtim_driver_t structure
 * @param[in] timer     timer which the ouput is related to. It can be one of
 *                      the following values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 * @param[in] output    timer ouput to be enabled. It can be one of the
 *                      following values:
 *            @arg @ref HRTIM_TIMER_OUTPUT_1
 *            @arg @ref HRTIM_TIMER_OUTPUT_2
 *
 * @api
 */
void hrtim_timer_enable_output(hrtim_driver_t *hdp, hrtim_timer_t timer,
                               hrtim_out_t output);

/**
 * @brief   Disables HRTIM timer output.
 * @note    This function must be invoked after hrtim_start, otherwise it has
 *          no effect.
 *
 * @param[out] hdp      pointer to a @p hrtim_driver_t structure
 * @param[in] timer     timer which the ouput is related to. It can be one of
 *                      the following values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 * @param[in] output    timer ouput to be disabled. It can be one of the
 *                      following values:
 *            @arg @ref HRTIM_TIMER_OUTPUT_1
 *            @arg @ref HRTIM_TIMER_OUTPUT_2
 *
 * @api
 */
void hrtim_timer_disable_output(hrtim_driver_t *hdp, hrtim_timer_t timer,
                                hrtim_out_t output);

/**
 * @brief   Enables HRTIM master/timer.
 * @note    This function must be invoked after hrtim_start, otherwise it has
 *          no effect.
 *
 * @param[out] hdp      pointer to a @p hrtim_driver_t structure
 * @param[in] timer     master/timer to be enabled. It can be one of the
 *                      following values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 *            @arg @ref HRTIM_TIMER_MASTER
 *
 * @api
 */
void hrtim_timer_enable(hrtim_driver_t *hdp, hrtim_timer_t timer);

/**
 * @brief   Disables HRTIM master/timer.
 * @note    This function must be invoked after hrtim_start, otherwise it has
 *          no effect.
 *
 * @param[out] hdp      pointer to a @p hrtim_driver_t structure
 * @param[in] timer     master/timer to be disabled. It can be one of the
 *                      following values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 *            @arg @ref HRTIM_TIMER_MASTER
 *
 * @api
 */
void hrtim_timer_disable(hrtim_driver_t *hdp, hrtim_timer_t timer);

/**
 * @brief   Configures HRTIM master/timer counter.
 * @note    This function must be invoked after hrtim_start and before the
 *          hrtim_timer_enable, otherwise it has no effect.
 *
 * @param[out] hdp      pointer to a @p hrtim_driver_t structure
 * @param[in] timer     master/timer to be enabled. It can be one of the
 *                      following values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 *            @arg @ref HRTIM_TIMER_MASTER
 * @param[in] value     counter value to be configured.
 *
 * @api
 */
void hrtim_timer_set_counter(hrtim_driver_t *hdp, hrtim_timer_t timer,
                             uint16_t value);

/**
 * @brief   Returns HRTIM master/timer counter value.
 * @note    This function must be invoked after hrtim_start, otherwise it has
 *          no effect.
 *
 * @param[out] hdp      pointer to a @p hrtim_driver_t structure
 * @param[in] timer     master/timer which the counter is related to. It can
 *                      be one of the following values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 *            @arg @ref HRTIM_TIMER_MASTER
 * @return              current master/timer counter value.
 *
 * @api
 */
uint16_t hrtim_timer_get_counter(hrtim_driver_t *hdp, hrtim_timer_t timer);

/**
 * @brief   Configures HRTIM master/timer repetition period value.
 * @note    The main purpose of the repetition counter is to adjust the period
 *          interrupt rate. If repetition is set to 0, an interrupt is
 *          generated for each and every period. For any value above 0, the
 *          interrupt is generated after (repetition + 1) periods.
 * @note    This function must be invoked after hrtim_start, otherwise it has
 *          no effect.
 *
 * @param[out] hdp      pointer to a @p hrtim_driver_t structure
 * @param[in] timer     master/timer to be configured. It can be one of the
 *                      following values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 *            @arg @ref HRTIM_TIMER_MASTER
 * @param[in] value     master/timer repetition period value to be configured.
 *
 * @api
 */
void hrtim_timer_set_repetition(hrtim_driver_t *hdp, hrtim_timer_t timer,
                                uint8_t value);

/**
 * @brief   Returns HRTIM master/timer repetition period value.
 * @note    The main purpose of the repetition counter is to adjust the period
 *          interrupt rate. If repetition is set to 0, an interrupt is
 *          generated for each and every period. For any value above 0, the
 *          interrupt is generated after (repetition + 1) periods.
 * @note    This function must be invoked after hrtim_start, otherwise it has
 *          no effect.
 *
 * @param[out] hdp      pointer to a @p hrtim_driver_t structure
 * @param[in] timer     master/timer which the counter is related to. It can
 *                      be one of the following values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 *            @arg @ref HRTIM_TIMER_MASTER
 * @return              current master/timer repetition counter value.
 *
 * @api
 */
uint8_t hrtim_timer_get_repetition(hrtim_driver_t *hdp, hrtim_timer_t timer);

/**
 * @brief   Returns the captured value of timer in the selected capture unit.
 * @note    This function must be invoked after hrtim_start, otherwise it has
 *          no effect.
 * @param[in] hdp       pointer to an @p hrtim_driver_t structure
 * @param[in] timer     timer which the configuration is related to. It can be
 *                      one of the following values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 * @param[in] cpt_idx   capture unit index. Identify the capture unit. It can
 *                      be one of the following values:   
 *            @arg @ref HRTIM_CAPTUREUNIT_1
 *            @arg @ref HRTIM_CAPTUREUNIT_2
 * @return              the counter value and he counting direction value when 
 *                      the capture event occurred.
 *
 * @api
 */
hrtim_cpt_value_t hrtim_timer_get_cpt(hrtim_driver_t *hdp, 
                                      hrtim_timer_t timer, 
                                      hrtim_cpt_t cpt_idx);

/**
 * @brief   Configures the trigger event that resets the timing unit counter.
 *
 * @param[in] hdp       pointer to an @p hrtim_driver_t structure
 * @param[in] timer     timer which the counter is related to. It can be one of
 *                      the following values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 * @param[in] event     event that triggers the reset of the timing unit
 *                      counter. It can be one of the following values:
 *            @arg @ref HRTIM_COUNTER_RESET_NOEVENT
 *            @arg @ref HRTIM_COUNTER_RESET_UPDATE
 *            @arg @ref HRTIM_COUNTER_RESET_CMP2
 *            @arg @ref HRTIM_COUNTER_RESET_CMP4
 *            @arg @ref HRTIM_COUNTER_RESET_MSTPER
 *            @arg @ref HRTIM_COUNTER_RESET_MSTCMP1
 *            @arg @ref HRTIM_COUNTER_RESET_MSTCMP2
 *            @arg @ref HRTIM_COUNTER_RESET_MSTCMP3
 *            @arg @ref HRTIM_COUNTER_RESET_MSTCMP4
 *            @arg @ref HRTIM_COUNTER_RESET_EXTEVNT1
 *            @arg @ref HRTIM_COUNTER_RESET_EXTEVNT2
 *            @arg @ref HRTIM_COUNTER_RESET_EXTEVNT3
 *            @arg @ref HRTIM_COUNTER_RESET_EXTEVNT4
 *            @arg @ref HRTIM_COUNTER_RESET_EXTEVNT5
 *            @arg @ref HRTIM_COUNTER_RESET_EXTEVNT6
 *            @arg @ref HRTIM_COUNTER_RESET_EXTEVNT7
 *            @arg @ref HRTIM_COUNTER_RESET_EXTEVNT8
 *            @arg @ref HRTIM_COUNTER_RESET_EXTEVNT9
 *            @arg @ref HRTIM_COUNTER_RESET_EXTEVNT10
 *            @arg @ref HRTIM_COUNTER_RESET_TIMFCMP1
 *            @arg @ref HRTIM_COUNTER_RESET_TIMECMP1_TIMERF
 *            @arg @ref HRTIM_COUNTER_RESET_TIMACMP1
 *            @arg @ref HRTIM_COUNTER_RESET_TIMACMP1_TIMERB
 *            @arg @ref HRTIM_COUNTER_RESET_TIMBCMP2
 *            @arg @ref HRTIM_COUNTER_RESET_TIMACMP2_TIMERB
 *            @arg @ref HRTIM_COUNTER_RESET_TIMBCMP4
 *            @arg @ref HRTIM_COUNTER_RESET_TIMACMP4_TIMERB
 *            @arg @ref HRTIM_COUNTER_RESET_TIMCCMP1
 *            @arg @ref HRTIM_COUNTER_RESET_TIMBCMP1_TIMERC
 *            @arg @ref HRTIM_COUNTER_RESET_TIMCCMP2
 *            @arg @ref HRTIM_COUNTER_RESET_TIMBCMP2_TIMERC
 *            @arg @ref HRTIM_COUNTER_RESET_TIMCCMP4
 *            @arg @ref HRTIM_COUNTER_RESET_TIMBCMP4_TIMERC
 *            @arg @ref HRTIM_COUNTER_RESET_TIMDCMP1
 *            @arg @ref HRTIM_COUNTER_RESET_TIMCCMP1_TIMERD
 *            @arg @ref HRTIM_COUNTER_RESET_TIMDCMP2
 *            @arg @ref HRTIM_COUNTER_RESET_TIMCCMP2_TIMERD
 *            @arg @ref HRTIM_COUNTER_RESET_TIMDCMP4
 *            @arg @ref HRTIM_COUNTER_RESET_TIMCCMP4_TIMERD
 *            @arg @ref HRTIM_COUNTER_RESET_TIMECMP1
 *            @arg @ref HRTIM_COUNTER_RESET_TIMDCMP1_TIMERE
 *            @arg @ref HRTIM_COUNTER_RESET_TIMECMP2
 *            @arg @ref HRTIM_COUNTER_RESET_TIMDCMP2_TIMERE
 *            @arg @ref HRTIM_COUNTER_RESET_TIMECMP4
 *            @arg @ref HRTIM_COUNTER_RESET_TIMDCMP4_TIMERE
 *            @arg @ref HRTIM_COUNTER_RESET_TIMFCMP2
 *            @arg @ref HRTIM_COUNTER_RESET_TIMECMP2_TIMERF
 * @return              current event triggering the counter value.
 *
 * @api
 */
uint32_t hrtim_timer_set_counter_reset_event(hrtim_driver_t *hdp, 
                                             hrtim_timer_t timer, 
                                             uint32_t event);

/**
 * @brief   Clears the trigger event that resets the timing unit counter.
 *
 * @param[in] hdp       pointer to an @p hrtim_driver_t structure
 * @param[in] timer     timer which the counter is related to. It can be one of
 *                      the following values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 * @param[in] event     event that triggers the reset of the timing unit
 *                      counter. It can be one of the following values:
 *            @arg @ref HRTIM_COUNTER_RESET_NOEVENT
 *            @arg @ref HRTIM_COUNTER_RESET_UPDATE
 *            @arg @ref HRTIM_COUNTER_RESET_CMP2
 *            @arg @ref HRTIM_COUNTER_RESET_CMP4
 *            @arg @ref HRTIM_COUNTER_RESET_MSTPER
 *            @arg @ref HRTIM_COUNTER_RESET_MSTCMP1
 *            @arg @ref HRTIM_COUNTER_RESET_MSTCMP2
 *            @arg @ref HRTIM_COUNTER_RESET_MSTCMP3
 *            @arg @ref HRTIM_COUNTER_RESET_MSTCMP4
 *            @arg @ref HRTIM_COUNTER_RESET_EXTEVNT1
 *            @arg @ref HRTIM_COUNTER_RESET_EXTEVNT2
 *            @arg @ref HRTIM_COUNTER_RESET_EXTEVNT3
 *            @arg @ref HRTIM_COUNTER_RESET_EXTEVNT4
 *            @arg @ref HRTIM_COUNTER_RESET_EXTEVNT5
 *            @arg @ref HRTIM_COUNTER_RESET_EXTEVNT6
 *            @arg @ref HRTIM_COUNTER_RESET_EXTEVNT7
 *            @arg @ref HRTIM_COUNTER_RESET_EXTEVNT8
 *            @arg @ref HRTIM_COUNTER_RESET_EXTEVNT9
 *            @arg @ref HRTIM_COUNTER_RESET_EXTEVNT10
 *            @arg @ref HRTIM_COUNTER_RESET_TIMFCMP1
 *            @arg @ref HRTIM_COUNTER_RESET_TIMECMP1_TIMERF
 *            @arg @ref HRTIM_COUNTER_RESET_TIMACMP1
 *            @arg @ref HRTIM_COUNTER_RESET_TIMACMP1_TIMERB
 *            @arg @ref HRTIM_COUNTER_RESET_TIMBCMP2
 *            @arg @ref HRTIM_COUNTER_RESET_TIMACMP2_TIMERB
 *            @arg @ref HRTIM_COUNTER_RESET_TIMBCMP4
 *            @arg @ref HRTIM_COUNTER_RESET_TIMACMP4_TIMERB
 *            @arg @ref HRTIM_COUNTER_RESET_TIMCCMP1
 *            @arg @ref HRTIM_COUNTER_RESET_TIMBCMP1_TIMERC
 *            @arg @ref HRTIM_COUNTER_RESET_TIMCCMP2
 *            @arg @ref HRTIM_COUNTER_RESET_TIMBCMP2_TIMERC
 *            @arg @ref HRTIM_COUNTER_RESET_TIMCCMP4
 *            @arg @ref HRTIM_COUNTER_RESET_TIMBCMP4_TIMERC
 *            @arg @ref HRTIM_COUNTER_RESET_TIMDCMP1
 *            @arg @ref HRTIM_COUNTER_RESET_TIMCCMP1_TIMERD
 *            @arg @ref HRTIM_COUNTER_RESET_TIMDCMP2
 *            @arg @ref HRTIM_COUNTER_RESET_TIMCCMP2_TIMERD
 *            @arg @ref HRTIM_COUNTER_RESET_TIMDCMP4
 *            @arg @ref HRTIM_COUNTER_RESET_TIMCCMP4_TIMERD
 *            @arg @ref HRTIM_COUNTER_RESET_TIMECMP1
 *            @arg @ref HRTIM_COUNTER_RESET_TIMDCMP1_TIMERE
 *            @arg @ref HRTIM_COUNTER_RESET_TIMECMP2
 *            @arg @ref HRTIM_COUNTER_RESET_TIMDCMP2_TIMERE
 *            @arg @ref HRTIM_COUNTER_RESET_TIMECMP4
 *            @arg @ref HRTIM_COUNTER_RESET_TIMDCMP4_TIMERE
 *            @arg @ref HRTIM_COUNTER_RESET_TIMFCMP2
 *            @arg @ref HRTIM_COUNTER_RESET_TIMECMP2_TIMERF
 *
 * @return              current event triggering the reset of the timing unit.
 * @api
 */
uint32_t hrtim_timer_clear_counter_reset_event(hrtim_driver_t *hdp, 
                                               hrtim_timer_t timer, 
                                               uint32_t event);

/**
 * @brief   Enables/Disables the access at shadow registers and configure the update
 *          event.
 * @note    When PREN is disabled the write in register directly updates the 
 *          active registers.
 * @note    When PREN is enabled the write in register is transferred into the
 *          active register after an update request. 
 * @param[in] hdp       pointer to an @p hrtim_driver_t structure
 * @param[in] timer     timer which the update is related to. It can be one of
 *                      the following values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 *            @arg @ref HRTIM_TIMER_MASTER
 * @param[in] preload   preload enable. It can be one of the following values:
 *            @arg @ref HRTIM_PRELOAD_DISABLED
 *            @arg @ref HRTIM_PRELOAD_PREEN
 * @param[in] update_src update sorce. It can be one of the following values:
 *            @arg @ref HRTIM_UPDATEGATING_INDEPENDENT
 *            @arg @ref HRTIM_UPDATEGATING_DMABURST
 *            @arg @ref HRTIM_UPDATEGATING_DMABURST_UPDATE
 *            @arg @ref HRTIM_UPDATEGATING_UPDEN1
 *            @arg @ref HRTIM_UPDATEGATING_UPDEN2
 *            @arg @ref HRTIM_UPDATEGATING_UPDEN3
 *            @arg @ref HRTIM_UPDATEGATING_UPDEN1_UPDATE
 *            @arg @ref HRTIM_UPDATEGATING_UPDEN2_UPDATE
 *            @arg @ref HRTIM_UPDATEGATING_UPDEN3_UPDATE
 *            @arg @ref HRTIM_TIMUPDATETRIGGER_NONE
 *            @arg @ref HRTIM_TIMUPDATETRIGGER_MASTER
 *            @arg @ref HRTIM_TIMUPDATETRIGGER_TIMER_A
 *            @arg @ref HRTIM_TIMUPDATETRIGGER_TIMER_B
 *            @arg @ref HRTIM_TIMUPDATETRIGGER_TIMER_C
 *            @arg @ref HRTIM_TIMUPDATETRIGGER_TIMER_D
 *            @arg @ref HRTIM_TIMUPDATETRIGGER_TIMER_E
 *            @arg @ref HRTIM_TIMUPDATETRIGGER_TIMER_F
 *            @arg @ref HRTIM_TIMUPDATETRIGGER_REPETITION
 *            @arg @ref HRTIM_TIMUPDATETRIGGER_RESET
 *
 * @api
 */
void hrtim_timer_set_preload_update(hrtim_driver_t *hdp, 
                                    hrtim_timer_t timer, 
                                    uint32_t preload, uint32_t update_src);

/**
 * @brief   Enables/Disables the access at shadow registers and configures the
 *          update event.
 * @note    When PREN is disabled the write in register directly updates the 
 *          active registers.
 * @note    When PREN is enabled the write in register is transferred into the
 *          active register after an update request. 
 * @param[in] hdp       pointer to an @p hrtim_driver_t structure
 * @param[in] timer     timer which the update is related to. It can be one of
 *                      the following values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 *            @arg @ref HRTIM_TIMER_MASTER
 * @param[in] preload   preload status. It can be one of the following values:
 *            @arg @ref HRTIM_PRELOAD_DISABLED
 *            @arg @ref HRTIM_PRELOAD_PREEN
 * @param[in] update_src update sorce. It can be one of the following values:
 *            @arg @ref HRTIM_UPDATEGATING_INDEPENDENT
 *            @arg @ref HRTIM_UPDATEGATING_DMABURST
 *            @arg @ref HRTIM_UPDATEGATING_DMABURST_UPDATE
 *            @arg @ref HRTIM_UPDATEGATING_UPDEN1
 *            @arg @ref HRTIM_UPDATEGATING_UPDEN2
 *            @arg @ref HRTIM_UPDATEGATING_UPDEN3
 *            @arg @ref HRTIM_UPDATEGATING_UPDEN1_UPDATE
 *            @arg @ref HRTIM_UPDATEGATING_UPDEN2_UPDATE
 *            @arg @ref HRTIM_UPDATEGATING_UPDEN3_UPDATE
 *            @arg @ref HRTIM_TIMUPDATETRIGGER_NONE
 *            @arg @ref HRTIM_TIMUPDATETRIGGER_MASTER
 *            @arg @ref HRTIM_TIMUPDATETRIGGER_TIMER_A
 *            @arg @ref HRTIM_TIMUPDATETRIGGER_TIMER_B
 *            @arg @ref HRTIM_TIMUPDATETRIGGER_TIMER_C
 *            @arg @ref HRTIM_TIMUPDATETRIGGER_TIMER_D
 *            @arg @ref HRTIM_TIMUPDATETRIGGER_TIMER_E
 *            @arg @ref HRTIM_TIMUPDATETRIGGER_TIMER_F
 *            @arg @ref HRTIM_TIMUPDATETRIGGER_REPETITION
 *            @arg @ref HRTIM_TIMUPDATETRIGGER_RESET
 *
 * @api
 */
void hrtim_timer_clear_preload_update(hrtim_driver_t *hdp,
                                      hrtim_timer_t timer,
                                      uint32_t preload,
                                      uint32_t update_src);

/**
 * @brief   Configures the HALF/INTERLEAVED mode of timer.
 *
 * @param[in] hdp       pointer to an @p hrtim_driver_t structure
 * @param[in] timer     master/timer which the counter is related to. It can
 *                      be one of the following values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 * @param[in] mode      Select the HALF mode or one of the intervaled modes. It
 *                      can be one of the following values:
 *            @arg @ref HRTIM_MODE_HALF
 *            @arg @ref HRTIM_MODE_DUAL_INTERVALLED 
 *            @arg @ref HRTIM_MODE_TRIPLE_INTERVALLED 
 *            @arg @ref HRTIM_MODE_QUAD_INTERVALLED 
 * @return              current mode value.
 *
 * @api
 */
hrtim_mode_tpg_t hrtim_timer_set_half_intlvd_mode(hrtim_driver_t *hdp,
                                                  hrtim_timer_t timer,
                                                  hrtim_mode_tpg_t mode);

/**
 * @brief   Selects the operating mode of timer_x counter:
 * @note    The master timer only works in up-counting mode.
 *
 * @param[in] hdp       pointer to an @p hrtim_driver_t structure
 * @param[in] timer     timer which the counter is related to. It can be one of
 *                      the following values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 * @param[in] mode      Select the counter mode of timer_x. It can be one of
 *                      the following values:
 *            @arg @ref HRTIM_COUNTING_MODE_UP     
 *            @arg @ref HRTIM_COUNTING_MODE_UP_DOWN
 *
 * @return              current counter mode value.
 *
 * @api
 */
uint32_t hrtim_timer_set_up_down_mode(hrtim_driver_t *hdp,
                                      hrtim_timer_t timer,
                                      uint32_t up_mode);

/**
 * @brief   Forces timer(s) registers software update.
 * @note    This function must be invoked after hrtim_start, otherwise it has
 *          no effect.
 *
 * @param[in] hdp       pointer to HRTIM handle
 * @param[in] timer     timer index. It can be one of the following values:
 *            @arg @ref HRTIM_TIMERINDEX_TIMER_A
 *            @arg @ref HRTIM_TIMERINDEX_TIMER_B
 *            @arg @ref HRTIM_TIMERINDEX_TIMER_C
 *            @arg @ref HRTIM_TIMERINDEX_TIMER_D
 *            @arg @ref HRTIM_TIMERINDEX_TIMER_E
 *            @arg @ref HRTIM_TIMERINDEX_TIMER_F
 *            @arg @ref HRTIM_TIMER_MASTER
 *
 * @api
 */
void hrtim_timer_set_sw_update(hrtim_driver_t *hdp,
                               hrtim_timer_t timer);

/**
 * @brief   Configures HRTIM master/timer ADC triggers
 * @note    There are different sets of event sources. ADC triggers 1/3 and 2/4
 *          are using the same source set. The ADC triggers 5/7/9 and 6/8/10
 *          are using the same source set.
 * @param[in] hdp       pointer to an @p hrtim_driver_t structure
 * @param[in] adc_trigger ADC trigger index which the configuration is related
 *                       to. It can be one of the following values:
 *            @arg @ref HRTIM_ADCTRIGGER_1
 *            @arg @ref HRTIM_ADCTRIGGER_2
 *            @arg @ref HRTIM_ADCTRIGGER_3
 *            @arg @ref HRTIM_ADCTRIGGER_4
 *            @arg @ref HRTIM_ADCTRIGGER_5 
 *            @arg @ref HRTIM_ADCTRIGGER_6
 *            @arg @ref HRTIM_ADCTRIGGER_7
 *            @arg @ref HRTIM_ADCTRIGGER_8
 *            @arg @ref HRTIM_ADCTRIGGER_9 
 *            @arg @ref HRTIM_ADCTRIGGER_10
 * @param[in] event_trigger event triggering the ADC. It can be one of the 
 *                      following values: 
 *            @arg @ref HRTIM_ADCTRIGGEREVENT13_NONE
 *            @arg @ref HRTIM_ADCTRIGGEREVENT13_MASTER_CMP1
 *            @arg @ref HRTIM_ADCTRIGGEREVENT13_MASTER_CMP2
 *            @arg @ref HRTIM_ADCTRIGGEREVENT13_MASTER_CMP3
 *            @arg @ref HRTIM_ADCTRIGGEREVENT13_MASTER_CMP4
 *            @arg @ref HRTIM_ADCTRIGGEREVENT13_MASTER_PERIOD
 *            @arg @ref HRTIM_ADCTRIGGEREVENT13_EVENT_1
 *            @arg @ref HRTIM_ADCTRIGGEREVENT13_EVENT_2
 *            @arg @ref HRTIM_ADCTRIGGEREVENT13_EVENT_3
 *            @arg @ref HRTIM_ADCTRIGGEREVENT13_EVENT_4
 *            @arg @ref HRTIM_ADCTRIGGEREVENT13_EVENT_5
 *            @arg @ref HRTIM_ADCTRIGGEREVENT13_TIMERF_CMP2
 *            @arg @ref HRTIM_ADCTRIGGEREVENT13_TIMERA_CMP3
 *            @arg @ref HRTIM_ADCTRIGGEREVENT13_TIMERA_CMP4
 *            @arg @ref HRTIM_ADCTRIGGEREVENT13_TIMERA_PERIOD
 *            @arg @ref HRTIM_ADCTRIGGEREVENT13_TIMERA_RESET
 *            @arg @ref HRTIM_ADCTRIGGEREVENT13_TIMERF_CMP3
 *            @arg @ref HRTIM_ADCTRIGGEREVENT13_TIMERB_CMP3
 *            @arg @ref HRTIM_ADCTRIGGEREVENT13_TIMERB_CMP4
 *            @arg @ref HRTIM_ADCTRIGGEREVENT13_TIMERB_PERIOD
 *            @arg @ref HRTIM_ADCTRIGGEREVENT13_TIMERB_RESET
 *            @arg @ref HRTIM_ADCTRIGGEREVENT13_TIMERF_CMP4
 *            @arg @ref HRTIM_ADCTRIGGEREVENT13_TIMERC_CMP3
 *            @arg @ref HRTIM_ADCTRIGGEREVENT13_TIMERC_CMP4
 *            @arg @ref HRTIM_ADCTRIGGEREVENT13_TIMERC_PERIOD
 *            @arg @ref HRTIM_ADCTRIGGEREVENT13_TIMERF_PERIOD
 *            @arg @ref HRTIM_ADCTRIGGEREVENT13_TIMERD_CMP3
 *            @arg @ref HRTIM_ADCTRIGGEREVENT13_TIMERD_CMP4
 *            @arg @ref HRTIM_ADCTRIGGEREVENT13_TIMERD_PERIOD
 *            @arg @ref HRTIM_ADCTRIGGEREVENT13_TIMERF_RESET
 *            @arg @ref HRTIM_ADCTRIGGEREVENT13_TIMERE_CMP3
 *            @arg @ref HRTIM_ADCTRIGGEREVENT13_TIMERE_CMP4
 *            @arg @ref HRTIM_ADCTRIGGEREVENT13_TIMERE_PERIOD
 *            @arg @ref HRTIM_ADCTRIGGEREVENT24_NONE
 *            @arg @ref HRTIM_ADCTRIGGEREVENT24_MASTER_CMP1
 *            @arg @ref HRTIM_ADCTRIGGEREVENT24_MASTER_CMP2
 *            @arg @ref HRTIM_ADCTRIGGEREVENT24_MASTER_CMP3
 *            @arg @ref HRTIM_ADCTRIGGEREVENT24_MASTER_CMP4
 *            @arg @ref HRTIM_ADCTRIGGEREVENT24_MASTER_PERIOD
 *            @arg @ref HRTIM_ADCTRIGGEREVENT24_EVENT_6
 *            @arg @ref HRTIM_ADCTRIGGEREVENT24_EVENT_7
 *            @arg @ref HRTIM_ADCTRIGGEREVENT24_EVENT_8
 *            @arg @ref HRTIM_ADCTRIGGEREVENT24_EVENT_9
 *            @arg @ref HRTIM_ADCTRIGGEREVENT24_EVENT_10
 *            @arg @ref HRTIM_ADCTRIGGEREVENT24_TIMERA_CMP2
 *            @arg @ref HRTIM_ADCTRIGGEREVENT24_TIMERF_CMP2
 *            @arg @ref HRTIM_ADCTRIGGEREVENT24_TIMERA_CMP4
 *            @arg @ref HRTIM_ADCTRIGGEREVENT24_TIMERA_PERIOD
 *            @arg @ref HRTIM_ADCTRIGGEREVENT24_TIMERB_CMP2
 *            @arg @ref HRTIM_ADCTRIGGEREVENT24_TIMERF_CMP3
 *            @arg @ref HRTIM_ADCTRIGGEREVENT24_TIMERB_CMP4
 *            @arg @ref HRTIM_ADCTRIGGEREVENT24_TIMERB_PERIOD
 *            @arg @ref HRTIM_ADCTRIGGEREVENT24_TIMERC_CMP2
 *            @arg @ref HRTIM_ADCTRIGGEREVENT24_TIMERF_CMP4
 *            @arg @ref HRTIM_ADCTRIGGEREVENT24_TIMERC_CMP4
 *            @arg @ref HRTIM_ADCTRIGGEREVENT24_TIMERC_PERIOD
 *            @arg @ref HRTIM_ADCTRIGGEREVENT24_TIMERC_RESET
 *            @arg @ref HRTIM_ADCTRIGGEREVENT24_TIMERD_CMP2
 *            @arg @ref HRTIM_ADCTRIGGEREVENT24_TIMERF_PERIOD
 *            @arg @ref HRTIM_ADCTRIGGEREVENT24_TIMERD_CMP4
 *            @arg @ref HRTIM_ADCTRIGGEREVENT24_TIMERD_PERIOD
 *            @arg @ref HRTIM_ADCTRIGGEREVENT24_TIMERD_RESET
 *            @arg @ref HRTIM_ADCTRIGGEREVENT24_TIMERE_CMP2
 *            @arg @ref HRTIM_ADCTRIGGEREVENT24_TIMERE_CMP3
 *            @arg @ref HRTIM_ADCTRIGGEREVENT24_TIMERE_CMP4
 *            @arg @ref HRTIM_ADCTRIGGEREVENT24_TIMERE_RESET
 *            @arg @ref HRTIM_ADCTRIGGEREVENT579_NONE
 *            @arg @ref HRTIM_ADCTRIGGEREVENT579_MASTER_CMP1
 *            @arg @ref HRTIM_ADCTRIGGEREVENT579_MASTER_CMP2
 *            @arg @ref HRTIM_ADCTRIGGEREVENT579_MASTER_CMP3
 *            @arg @ref HRTIM_ADCTRIGGEREVENT579_MASTER_CMP4
 *            @arg @ref HRTIM_ADCTRIGGEREVENT579_MASTER_PERIOD
 *            @arg @ref HRTIM_ADCTRIGGEREVENT579_EVENT_1
 *            @arg @ref HRTIM_ADCTRIGGEREVENT579_EVENT_2
 *            @arg @ref HRTIM_ADCTRIGGEREVENT579_EVENT_3
 *            @arg @ref HRTIM_ADCTRIGGEREVENT579_EVENT_4
 *            @arg @ref HRTIM_ADCTRIGGEREVENT579_EVENT_5
 *            @arg @ref HRTIM_ADCTRIGGEREVENT579_TIMERA_CMP3
 *            @arg @ref HRTIM_ADCTRIGGEREVENT579_TIMERA_CMP4
 *            @arg @ref HRTIM_ADCTRIGGEREVENT579_TIMERA_PERIOD
 *            @arg @ref HRTIM_ADCTRIGGEREVENT579_TIMERA_RESET
 *            @arg @ref HRTIM_ADCTRIGGEREVENT579_TIMERB_CMP3
 *            @arg @ref HRTIM_ADCTRIGGEREVENT579_TIMERB_CMP4
 *            @arg @ref HRTIM_ADCTRIGGEREVENT579_TIMERB_PERIOD
 *            @arg @ref HRTIM_ADCTRIGGEREVENT579_TIMERB_RESET
 *            @arg @ref HRTIM_ADCTRIGGEREVENT579_TIMERC_CMP3
 *            @arg @ref HRTIM_ADCTRIGGEREVENT579_TIMERC_CMP4
 *            @arg @ref HRTIM_ADCTRIGGEREVENT579_TIMERC_PERIOD
 *            @arg @ref HRTIM_ADCTRIGGEREVENT579_TIMERD_CMP3
 *            @arg @ref HRTIM_ADCTRIGGEREVENT579_TIMERD_CMP4
 *            @arg @ref HRTIM_ADCTRIGGEREVENT579_TIMERD_PERIOD
 *            @arg @ref HRTIM_ADCTRIGGEREVENT579_TIMERE_CMP3
 *            @arg @ref HRTIM_ADCTRIGGEREVENT579_TIMERE_CMP4
 *            @arg @ref HRTIM_ADCTRIGGEREVENT579_TIMERE_PERIOD
 *            @arg @ref HRTIM_ADCTRIGGEREVENT579_TIMERF_CMP2
 *            @arg @ref HRTIM_ADCTRIGGEREVENT579_TIMERF_CMP3
 *            @arg @ref HRTIM_ADCTRIGGEREVENT579_TIMERF_CMP4
 *            @arg @ref HRTIM_ADCTRIGGEREVENT579_TIMERF_PERIOD
 *            @arg @ref HRTIM_ADCTRIGGEREVENT579_TIMERF_RESET
 *            @arg @ref HRTIM_ADCTRIGGEREVENT6810_NONE
 *            @arg @ref HRTIM_ADCTRIGGEREVENT6810_MASTER_CMP1
 *            @arg @ref HRTIM_ADCTRIGGEREVENT6810_MASTER_CMP2
 *            @arg @ref HRTIM_ADCTRIGGEREVENT6810_MASTER_CMP3
 *            @arg @ref HRTIM_ADCTRIGGEREVENT6810_MASTER_CMP4
 *            @arg @ref HRTIM_ADCTRIGGEREVENT6810_MASTER_PERIOD
 *            @arg @ref HRTIM_ADCTRIGGEREVENT6810_EVENT_6
 *            @arg @ref HRTIM_ADCTRIGGEREVENT6810_EVENT_7
 *            @arg @ref HRTIM_ADCTRIGGEREVENT6810_EVENT_8
 *            @arg @ref HRTIM_ADCTRIGGEREVENT6810_EVENT_9
 *            @arg @ref HRTIM_ADCTRIGGEREVENT6810_EVENT_10
 *            @arg @ref HRTIM_ADCTRIGGEREVENT6810_TIMERA_CMP2
 *            @arg @ref HRTIM_ADCTRIGGEREVENT6810_TIMERA_CMP4
 *            @arg @ref HRTIM_ADCTRIGGEREVENT6810_TIMERA_PERIOD
 *            @arg @ref HRTIM_ADCTRIGGEREVENT6810_TIMERB_CMP2
 *            @arg @ref HRTIM_ADCTRIGGEREVENT6810_TIMERB_CMP4
 *            @arg @ref HRTIM_ADCTRIGGEREVENT6810_TIMERB_PERIOD
 *            @arg @ref HRTIM_ADCTRIGGEREVENT6810_TIMERC_CMP2
 *            @arg @ref HRTIM_ADCTRIGGEREVENT6810_TIMERC_CMP4
 *            @arg @ref HRTIM_ADCTRIGGEREVENT6810_TIMERC_PERIOD
 *            @arg @ref HRTIM_ADCTRIGGEREVENT6810_TIMERC_RESET
 *            @arg @ref HRTIM_ADCTRIGGEREVENT6810_TIMERD_CMP2
 *            @arg @ref HRTIM_ADCTRIGGEREVENT6810_TIMERD_CMP4
 *            @arg @ref HRTIM_ADCTRIGGEREVENT6810_TIMERD_PERIOD
 *            @arg @ref HRTIM_ADCTRIGGEREVENT6810_TIMERD_RESET
 *            @arg @ref HRTIM_ADCTRIGGEREVENT6810_TIMERE_CMP2
 *            @arg @ref HRTIM_ADCTRIGGEREVENT6810_TIMERE_CMP3
 *            @arg @ref HRTIM_ADCTRIGGEREVENT6810_TIMERE_CMP4
 *            @arg @ref HRTIM_ADCTRIGGEREVENT6810_TIMERE_RESET
 *            @arg @ref HRTIM_ADCTRIGGEREVENT6810_TIMERF_CMP2
 *            @arg @ref HRTIM_ADCTRIGGEREVENT6810_TIMERF_CMP3
 *            @arg @ref HRTIM_ADCTRIGGEREVENT6810_TIMERF_CMP4
 *            @arg @ref HRTIM_ADCTRIGGEREVENT6810_TIMERF_PERIOD
 * @param[in] update_src  update source. It can be one of the following values:
 *            @arg @ref HRTIM_ADCTRIGGERUPDATE_MASTER 
 *            @arg @ref HRTIM_ADCTRIGGERUPDATE_TIMER_A
 *            @arg @ref HRTIM_ADCTRIGGERUPDATE_TIMER_B
 *            @arg @ref HRTIM_ADCTRIGGERUPDATE_TIMER_C
 *            @arg @ref HRTIM_ADCTRIGGERUPDATE_TIMER_D
 *            @arg @ref HRTIM_ADCTRIGGERUPDATE_TIMER_E
 *            @arg @ref HRTIM_ADCTRIGGERUPDATE_TIMER_F
 * @api
 */   
void hrtim_timer_set_adc_trigger(hrtim_driver_t *hdp,
                                 hrtim_timer_adctrigger_t adc_trigger,
                                 uint32_t event_trigger, 
                                 uint32_t update_src);

/**
 * @brief   Selects the ADC trigger rate.
 *
 * @param[in] hdp       pointer to an @p hrtim_driver_t structure
 * @param[in] adc_trigger ADC trigger which the configuration is related to. It
 *                      can be one of the following values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 * @param[in] postscaler postscaler to reduce the ADC trigger rate. It can be
 *                       one of the following values: 0..1F  
 * @return              current prescaler value of ADC trigger.
 *
 * @api
 */
uint32_t hrtim_timer_set_adc_post_scaler(hrtim_driver_t *hdp,
                                         hrtim_timer_adctrigger_t adc_trigger,
                                         uint32_t postscaler);

/**
 * @brief   Configures an external event channel
 *
 * @param[in] hdp       pointer to an @p hrtim_driver_t structure
 * @param[in] ext_event External event to be configured. It can be one of the
 *                      following values:
 *            @arg @ref HRTIM_EVENT_NONE
 *            @arg @ref HRTIM_EVENT_1   
 *            @arg @ref HRTIM_EVENT_2   
 *            @arg @ref HRTIM_EVENT_3   
 *            @arg @ref HRTIM_EVENT_4   
 *            @arg @ref HRTIM_EVENT_5   
 *            @arg @ref HRTIM_EVENT_6   
 *            @arg @ref HRTIM_EVENT_7   
 *            @arg @ref HRTIM_EVENT_8   
 *            @arg @ref HRTIM_EVENT_9   
 *            @arg @ref HRTIM_EVENT_10 
 * @param[in] ext_source External event source. It can be one of the following
 *                      values based on HRTIM instance:
 *            @arg @ref HRTIM1_EEV1SRC_GPIO
 *            @arg @ref HRTIM1_EEV2SRC_GPIO
 *            @arg @ref HRTIM1_EEV3SRC_GPIO
 *            @arg @ref HRTIM1_EEV4SRC_GPIO
 *            @arg @ref HRTIM1_EEV5SRC_GPIO
 *            @arg @ref HRTIM1_EEV6SRC_GPIO
 *            @arg @ref HRTIM1_EEV7SRC_GPIO
 *            @arg @ref HRTIM1_EEV8SRC_GPIO
 *            @arg @ref HRTIM1_EEV9SRC_GPIO
 *            @arg @ref HRTIM1_EEV10SRC_GPIO
 *            @arg @ref HRTIM1_EEV1SRC_COMP2_OUT
 *            @arg @ref HRTIM1_EEV2SRC_COMP4_OUT
 *            @arg @ref HRTIM1_EEV3SRC_COMP6_OUT
 *            @arg @ref HRTIM1_EEV4SRC_COMP1_OUT
 *            @arg @ref HRTIM1_EEV5SRC_COMP3_OUT
 *            @arg @ref HRTIM1_EEV6SRC_COMP2_OUT
 *            @arg @ref HRTIM1_EEV7SRC_COMP4_OUT
 *            @arg @ref HRTIM1_EEV8SRC_COMP6_OUT
 *            @arg @ref HRTIM1_EEV9SRC_COMP5_OUT
 *            @arg @ref HRTIM1_EEV10SRC_COMP7_OUT
 *            @arg @ref HRTIM1_EEV1SRC_TIM1_TRGO
 *            @arg @ref HRTIM1_EEV2SRC_TIM2_TRGO
 *            @arg @ref HRTIM1_EEV3SRC_TIM3_TRGO
 *            @arg @ref HRTIM1_EEV4SRC_COMP5_OUT
 *            @arg @ref HRTIM1_EEV5SRC_COMP7_OUT
 *            @arg @ref HRTIM1_EEV6SRC_COMP1_OUT
 *            @arg @ref HRTIM1_EEV7SRC_TIM7_TRGO
 *            @arg @ref HRTIM1_EEV8SRC_COMP3_OUT
 *            @arg @ref HRTIM1_EEV9SRC_TIM15_TRGO
 *            @arg @ref HRTIM1_EEV10SRC_TIM6_TRGO
 *            @arg @ref HRTIM1_EEV1SRC_ADC1_AWD1
 *            @arg @ref HRTIM1_EEV2SRC_ADC1_AWD2
 *            @arg @ref HRTIM1_EEV3SRC_ADC1_AWD3
 *            @arg @ref HRTIM1_EEV4SRC_ADC2_AWD1
 *            @arg @ref HRTIM1_EEV5SRC_ADC2_AWD2
 *            @arg @ref HRTIM1_EEV6SRC_ADC2_AWD3
 *            @arg @ref HRTIM1_EEV7SRC_ADC3_AWD1
 *            @arg @ref HRTIM1_EEV8SRC_ADC4_AWD1
 *            @arg @ref HRTIM1_EEV9SRC_COMP4_OUT
 *            @arg @ref HRTIM1_EEV10SRC_ADC5_AWD1
 *            @arg @ref HRTIM2_EEV1SRC_GPIO      
 *            @arg @ref HRTIM2_EEV2SRC_GPIO      
 *            @arg @ref HRTIM2_EEV3SRC_GPIO      
 *            @arg @ref HRTIM2_EEV4SRC_GPIO      
 *            @arg @ref HRTIM2_EEV5SRC_GPIO      
 *            @arg @ref HRTIM2_EEV6SRC_GPIO      
 *            @arg @ref HRTIM2_EEV7SRC_GPIO      
 *            @arg @ref HRTIM2_EEV8SRC_GPIO      
 *            @arg @ref HRTIM2_EEV9SRC_GPIO      
 *            @arg @ref HRTIM2_EEV10SRC_GPIO     
 *            @arg @ref HRTIM2_EEV1SRC_COMP1_OUT 
 *            @arg @ref HRTIM2_EEV2SRC_COMP3_OUT 
 *            @arg @ref HRTIM2_EEV3SRC_COMP5_OUT 
 *            @arg @ref HRTIM2_EEV4SRC_COMP2_OUT 
 *            @arg @ref HRTIM2_EEV5SRC_COMP4_OUT 
 *            @arg @ref HRTIM2_EEV6SRC_COMP1_OUT 
 *            @arg @ref HRTIM2_EEV7SRC_COMP3_OUT 
 *            @arg @ref HRTIM2_EEV8SRC_COMP5_OUT 
 *            @arg @ref HRTIM2_EEV9SRC_COMP6_OUT 
 *            @arg @ref HRTIM2_EEV10SRC_COMP8_OUT
 *            @arg @ref HRTIM2_EEV1SRC_TIM1_TRGO 
 *            @arg @ref HRTIM2_EEV2SRC_TIM2_TRGO 
 *            @arg @ref HRTIM2_EEV3SRC_TIM3_TRGO 
 *            @arg @ref HRTIM2_EEV4SRC_COMP6_OUT 
 *            @arg @ref HRTIM2_EEV5SRC_COMP8_OUT 
 *            @arg @ref HRTIM2_EEV6SRC_COMP2_OUT 
 *            @arg @ref HRTIM2_EEV7SRC_TIM7_TRGO 
 *            @arg @ref HRTIM2_EEV8SRC_COMP4_OUT 
 *            @arg @ref HRTIM2_EEV9SRC_TIM15_TRGO
 *            @arg @ref HRTIM2_EEV10SRC_TIM6_TRGO
 *            @arg @ref HRTIM2_EEV1SRC_ADC1_AWD1 
 *            @arg @ref HRTIM2_EEV2SRC_ADC1_AWD2 
 *            @arg @ref HRTIM2_EEV3SRC_ADC1_AWD3 
 *            @arg @ref HRTIM2_EEV4SRC_ADC2_AWD1 
 *            @arg @ref HRTIM2_EEV5SRC_ADC2_AWD2 
 *            @arg @ref HRTIM2_EEV6SRC_ADC2_AWD3 
 *            @arg @ref HRTIM2_EEV7SRC_ADC3_AWD1 
 *            @arg @ref HRTIM2_EEV8SRC_ADC4_AWD1 
 *            @arg @ref HRTIM2_EEV9SRC_COMP4_OUT 
 *            @arg @ref HRTIM2_EEV10SRC_ADC5_AWD1
 * @param[in] ext_polarity External event polarity It can be one the following
 *                      values:
 *            @arg @ref HRTIM_EVENTPOLARITY_HIGH
 *            @arg @ref HRTIM_EVENTPOLARITY_LOW
 * @param[in] ext_sensitivity  to be either level-sensitive or edgesensitive
 *                      (rising, falling or both).It can be one of the
 *                      following values: 
 *            @arg @ref HRTIM_EVENTSENSITIVITY_LEVEL
 *            @arg @ref HRTIM_EVENTSENSITIVITY_RISINGEDGE
 *            @arg @ref HRTIM_EVENTSENSITIVITY_FALLINGEDGE
 *            @arg @ref HRTIM_EVENTSENSITIVITY_BOTHEDGES
 * @param[in] ext_filter Digital filter: Available ONLY for events
 *                      [HRTIM_EVENT_6:HRTIM_EVENT_10]. It can be one of the
 *                      following values:
 *            @arg @ref HRTIM_EVENTFILTER_NONE
 *            @arg @ref HRTIM_EVENTFILTER_1
 *            @arg @ref HRTIM_EVENTFILTER_2
 *            @arg @ref HRTIM_EVENTFILTER_3
 *            @arg @ref HRTIM_EVENTFILTER_4
 *            @arg @ref HRTIM_EVENTFILTER_5
 *            @arg @ref HRTIM_EVENTFILTER_6
 *            @arg @ref HRTIM_EVENTFILTER_7
 *            @arg @ref HRTIM_EVENTFILTER_8
 *            @arg @ref HRTIM_EVENTFILTER_9
 *            @arg @ref HRTIM_EVENTFILTER_10
 *            @arg @ref HRTIM_EVENTFILTER_11
 *            @arg @ref HRTIM_EVENTFILTER_12
 *            @arg @ref HRTIM_EVENTFILTER_13
 *            @arg @ref HRTIM_EVENTFILTER_14
 *            @arg @ref HRTIM_EVENTFILTER_15
 * @param[in] ext_fast_mode Latency mode: Available ONLY for events:
 *                      [HRTIM_EVENT_1:HRTIM_EVENT_5]. It can be one of the
 *                      following values:
 *            @arg @ref HRTIM_EVENTFASTMODE_DISABLE
 *            @arg @ref HRTIM_EVENTFASTMODE_ENABLE
 *
 * @api
 */
void hrtim_set_ex_event(hrtim_driver_t *hdp,
                        uint8_t  eev_idx,
                        uint32_t ext_source,
                        uint32_t ext_polarity,
                        uint32_t ext_sensitivity,
                        uint32_t ext_filter,
                        uint32_t ext_fast_mode);

/**
 * @brief   Configures the external event conditioning block prescaler.
 * 
 * @param[in] hdp       pointer to an @p hrtim_driver_t structure
 * @param[in] ext_ev_prescaler prescaler value. It can be one of the following
 *                      values:
 *            @arg @ref HRTIM_EVENTPRESCALER_DIV1
 *            @arg @ref HRTIM_EVENTPRESCALER_DIV2
 *            @arg @ref HRTIM_EVENTPRESCALER_DIV4
 *            @arg @ref HRTIM_EVENTPRESCALER_DIV8
 * @return              previous prescaler
 *
 * @api
 */ 
hrtim_eev_prsc_t hrtim_set_event_prescaler(hrtim_driver_t *hdp,
                                           hrtim_eev_prsc_t eev_prsc);

/**
 * @brief   Configures the event filtering capabilities of a timer (blanking,
 *          windowing).
 *
 * @param[in] hdp       pointer to an @p hrtim_driver_t structure
 * @param[in] timer     timer which the update is related to. It can be one of
 *                      the following values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 * @param[in] eev_idx   external event for which timer event filtering must be
 *                      configured. It can be one of the following values:
 *            @arg @ref HRTIM_EVENT_1
 *            @arg @ref HRTIM_EVENT_2
 *            @arg @ref HRTIM_EVENT_3
 *            @arg @ref HRTIM_EVENT_4
 *            @arg @ref HRTIM_EVENT_5
 *            @arg @ref HRTIM_EVENT_6
 *            @arg @ref HRTIM_EVENT_7
 *            @arg @ref HRTIM_EVENT_8
 *            @arg @ref HRTIM_EVENT_9
 *            @arg @ref HRTIM_EVENT_10
 * @param[in] filter event filtering applied to external events by a timer. It
 *                      can be one of the following values:
 *            @arg @ref HRTIM_TIMEEVFLT_NONE
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKINGCMP1
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKINGCMP2
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKINGCMP3
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKINGCMP4
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMAEEF1_TIMBCMP1
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMAEEF2_TIMBCMP4
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMAEEF3_TIMBOUT2
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMAEEF4_TIMCCMP1
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMAEEF5_TIMCCMP4
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMAEEF6_TIMFCMP1
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMAEEF7_TIMDCMP1
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMAEEF8_TIMECMP2
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMBEEF1_TIMACMP1
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMBEEF2_TIMACMP4
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMBEEF3_TIMAOUT2
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMBEEF4_TIMCCMP1
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMBEEF5_TIMCCMP2
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMBEEF6_TIMFCMP2
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMBEEF7_TIMDCMP2
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMBEEF8_TIMECMP1
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMCEEF1_TIMACMP2
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMCEEF2_TIMBCMP1
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMCEEF3_TIMBCMP4
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMCEEF4_TIMFCMP1
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMCEEF5_TIMDCMP1
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMCEEF6_TIMDCMP4
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMCEEF7_TIMDOUT2
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMCEEF8_TIMECMP4
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMDEEF1_TIMACMP1
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMDEEF2_TIMBCMP2
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMDEEF3_TIMCCMP1
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMDEEF4_TIMCCMP2
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMDEEF5_TIMCOUT2
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMDEEF6_TIMECMP1
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMDEEF7_TIMECMP4
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMDEEF8_TIMFCMP4
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMEEEF1_TIMACMP2
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMEEEF2_TIMBCMP1
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMEEEF3_TIMCCMP1
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMEEEF4_TIMFCMP4
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMEEEF5_TIMFOUT2
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMEEEF6_TIMDCMP1
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMEEEF7_TIMDCMP4
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMEEEF8_TIMDOUT2
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMFEEF1_TIMACMP4
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMFEEF2_TIMBCMP2
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMFEEF3_TIMCCMP4
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMFEEF4_TIMDCMP2
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMFEEF5_TIMDCMP4
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMFEEF6_TIMECMP1
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMFEEF7_TIMECMP4
 *            @arg @ref HRTIM_TIMEEVFLT_BLANKING_TIMFEEF8_TIMEOUT2
 *            @arg @ref HRTIM_TIMEEVFLT_WINDOWINGCMP2
 *            @arg @ref HRTIM_TIMEEVFLT_WINDOWINGCMP3
 *            @arg @ref HRTIM_TIMEEVFLT_WINDOWINGTIM
 * @param[in] latch Specifies whether or not the signal is latched. It can be
 *                      one of the following values:
 *            @arg @ref HRTIM_TIMEVENTLATCH_DISABLED 
 *            @arg @ref HRTIM_TIMEVENTLATCH_ENABLED
 * @api
 */
void hrtim_timer_set_eev_filtering(hrtim_driver_t *hdp,
                                   hrtim_timer_t timer,
                                   uint8_t eev_idx,
                                   uint32_t filter, 
                                   uint32_t latch);

/**
 * @brief   Configures the external event counter A of a timer (source,
 *          threshold, reset mode).
 * @note    This function must be called before starting the timer.
 *
 * @param[in] hdp       pointer to HRTIM handle
 * @param[in] timer     timer index. It can be one of the following values:
 *            @arg @ref HRTIM_TIMERINDEX_TIMER_A
 *            @arg @ref HRTIM_TIMERINDEX_TIMER_B
 *            @arg @ref HRTIM_TIMERINDEX_TIMER_C
 *            @arg @ref HRTIM_TIMERINDEX_TIMER_D
 *            @arg @ref HRTIM_TIMERINDEX_TIMER_E
 *            @arg @ref HRTIM_TIMERINDEX_TIMER_F
 * @param[in] eev_idx   external event for which external event counter must be
 *                      configured.
 * @param[in] reset_mode select the reset mode of the external event counter. 
 *                      It can be one of the following values:
 *            @arg @ref HRTIM_EVENTCOUNTER_RSTMODE_UNCONDITIONAL
 *            @arg @ref HRTIM_EVENTCOUNTER_RSTMODE_CONDITIONAL
 * @param[in] source    external event used as external event A source. It can
 *                      be one of the following values:
 *            @arg @ref HRTIM_EVENT_NONE
 *            @arg @ref HRTIM_EVENT_1
 *            @arg @ref HRTIM_EVENT_2
 *            @arg @ref HRTIM_EVENT_3
 *            @arg @ref HRTIM_EVENT_4
 *            @arg @ref HRTIM_EVENT_5
 *            @arg @ref HRTIM_EVENT_6
 *            @arg @ref HRTIM_EVENT_7
 *            @arg @ref HRTIM_EVENT_8
 *            @arg @ref HRTIM_EVENT_9
 *            @arg @ref HRTIM_EVENT_10
 * @param[in] counter   external event counter threshold. It can be a number 
 *                      between 0x0 and 0x3F.
 *
 * @api
 */
void hrtim_ext_even_counter_cfg(hrtim_driver_t *hdp,
                                hrtim_timer_t timer,
                                uint8_t eev_idx,
                                uint32_t reset_mode,
                                uint32_t source,
                                uint32_t counter);

/**
 * @brief   Enables the external event counter A of a timer.
 * @note    This function must be invoked after hrtim_start, otherwise it has
 *          no effect.
 *
 * @param[in] hdp       pointer to HRTIM handle
 * @param[in] timer     timer index. It can be one of the following values:
 *            @arg @ref HRTIM_TIMERINDEX_TIMER_A
 *            @arg @ref HRTIM_TIMERINDEX_TIMER_B
 *            @arg @ref HRTIM_TIMERINDEX_TIMER_C
 *            @arg @ref HRTIM_TIMERINDEX_TIMER_D
 *            @arg @ref HRTIM_TIMERINDEX_TIMER_E
 *            @arg @ref HRTIM_TIMERINDEX_TIMER_F
 *
 * @api
 */
void hrtim_timer_eev_counter_enable(hrtim_driver_t *hdp, hrtim_timer_t timer);

/**
 * @brief   Disables the external event counter A of a timer.
 * @note    This function must be invoked after hrtim_start, otherwise it has
 *          no effect.
 *
 * @param[in] hdp       pointer to HRTIM handle
 * @param[in] timer     timer index. It can be one of the following values:
 *            @arg @ref HRTIM_TIMERINDEX_TIMER_A
 *            @arg @ref HRTIM_TIMERINDEX_TIMER_B
 *            @arg @ref HRTIM_TIMERINDEX_TIMER_C
 *            @arg @ref HRTIM_TIMERINDEX_TIMER_D
 *            @arg @ref HRTIM_TIMERINDEX_TIMER_E
 *            @arg @ref HRTIM_TIMERINDEX_TIMER_F
 *
 * @api
 */
void hrtim_timer_eev_counter_disable(hrtim_driver_t *hdp, 
                                     hrtim_timer_t timer);

/**
 * @brief   Resets the external event counter A of a timer.
 * @note    This function must be invoked after hrtim_start, otherwise it has
 *          no effect.
 *
 * @param[in] hdp       pointer to HRTIM handle
 * @param[in] timer     timer index. It can be one of the following values:
 *            @arg @ref HRTIM_TIMERINDEX_TIMER_A
 *            @arg @ref HRTIM_TIMERINDEX_TIMER_B
 *            @arg @ref HRTIM_TIMERINDEX_TIMER_C
 *            @arg @ref HRTIM_TIMERINDEX_TIMER_D
 *            @arg @ref HRTIM_TIMERINDEX_TIMER_E
 *            @arg @ref HRTIM_TIMERINDEX_TIMER_F
 *
 * @api
 */
void hrtim_timer_eev_counter_reset(hrtim_driver_t *hdp, hrtim_timer_t timer);

/**
 * @brief   Sets the HRTIM output the DAC synchronization event is generated
 *          on.
 * @note    This function must be invoked after hrtim_start, otherwise it has
 *          no effect.
 *
 * @param[in] hdp       pointer to an @p hrtim_driver_t structure
 * @param[in] timer     timer which the configuration is related to. It can be
 *                      one of the following values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 *            @arg @ref HRTIM_TIMER_MASTER
 * @param[in] sync_trigger Indicates which output the DAC synchronization event
 *                      is generated. It can be one of the following values:
 *            @arg @ref HRTIM_DACSYNC_TRIG1
 *            @arg @ref HRTIM_DACSYNC_TRIG2
 *            @arg @ref HRTIM_DACSYNC_TRIG3
 *
 * @api
 */
void hrtim_timer_set_dacsync_trigger(hrtim_driver_t *hdp,
                                     hrtim_timer_t timer,
                                     uint32_t sync_trigger);

/**
 * @brief   Enables the dual channel DAC trigger mode
 *
 * @param[in] hdp       pointer to an @p hrtim_driver_t structure
 * @param[in] timer     timer which the configuration is related to. It can be
 *                      one of the following values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 *
 * @api
 */
void hrtim_timer_enable_dualdac_trigger(hrtim_driver_t *hdp,
                                        hrtim_timer_t timer);

/**
 * @brief   Configures the dual channel DAC trigger.
 * @note    This function must be invoked after hrtim_start, otherwise it has
 *          no effect.
 *
 * @param[in] hdp       pointer to an @p hrtim_driver_t structure
 * @param[in] timer     ADC trigger which the configuration is related to. It
 *                      can be one of the following values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 * @param[in] reset_trigger Specifies how the hrtim_dac_reset_trgx trigger is
 *                      generated. It can be one of the following values:
 *            @arg @ref HRTIM_DUALDAC_RESET_TRIGGER_RESET 
 *            @arg @ref HRTIM_DUALDAC_RESET_TRIGGER_OUT1SET
 * @param[in] step_trigger Specifies how the hrtim_dac_step_trgx trigger is
 *                      generated. It can be one of the following values:
 *            @arg @ref HRTIM_DUALDAC_STEP_TRIGGER_CMP2 
 *            @arg @ref HRTIM_DUALDAC_STEP_TRIGGER_OUT1RST
 *
 * @api
 */
void hrtim_timer_set_dualdac_trigger(hrtim_driver_t *hdp,
                                     hrtim_timer_t timer,
                                     uint32_t reset_trigger,
                                     uint32_t step_trigger);   

/**
 * @brief   Configures the roll-over event triggering the ADC.
 * @note    It is only applied when the timer is in up-down counting mode.
 *
 * @param[in] hdp       pointer to an @p hrtim_driver_t structure
 * @param[in] timer     timert which the configuration is related to. It can be
 *                      one of the following values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 * @param[in] adc_rollover_mode roll-over event which triggers the ADC. It can
 *                      be one of the following values:
 *            @arg @ref HRTIM_ROLLOVER_MODE_PER
 *            @arg @ref HRTIM_ROLLOVER_MODE_RST
 *            @arg @ref HRTIM_ROLLOVER_MODE_BOTH
 * @return              previous roll-over mode.
 *
 * @api
 */
uint16_t hrtim_timer_set_adc_rollover(hrtim_driver_t *hdp,
                                      hrtim_timer_t timer,
                                      uint16_t adc_rollover_mode);
/**
 * @brief   Configures the roll-over event used by the fault and event counter.
 * @note    It is only applied when the timer is in up-down counting mode.
 *
 * @param[in] hdp       pointer to an @p hrtim_driver_t structure
 * @param[in] timer     timer which the configuration is related to. It can be
 *                      one of the following values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 * @param[in] flt_rollover_mode roll-over event used by the fault and event
 *                      counters. It can be one of the following values:
 *            @arg @ref HRTIM_ROLLOVER_MODE_PER
 *            @arg @ref HRTIM_ROLLOVER_MODE_RST
 *            @arg @ref HRTIM_ROLLOVER_MODE_BOTH
 * @return              previous roll-over mode.
 *
 * @api
 */
uint16_t hrtim_timer_set_fault_event_rollover(hrtim_driver_t *hdp,
                                              hrtim_timer_t timer,
                                              uint16_t flt_rollover_mode);

/**
 * @brief   Configures the roll-over event which sets and/or resets the ouputs.
 * @note    It is only applied when the timer is in up-down counting mode.
 * @param[in] hdp       pointer to an @p hrtim_driver_t structure
 * @param[in] timer     timer which the configuration is related to. It can be
 *                      one of the following values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 * @param[in] out_rollover_mode rollover event which sets and/or resets the
 *                      ouputs. It can be one of the following values:
 *            @arg @ref HRTIM_ROLLOVER_MODE_PER
 *            @arg @ref HRTIM_ROLLOVER_MODE_RST
 *            @arg @ref HRTIM_ROLLOVER_MODE_BOTH
 * @return              previous output roll-over mode.
 *
 * @api
 */
uint16_t hrtim_timer_set_out_rollover(hrtim_driver_t *hdp,
                                      hrtim_timer_t timer,
                                      uint16_t out_rollover_mode);

/**
 * @brief   Configures the roll-over mode of timer used in the burst mode.
 * @note    It is only applied when the timer is in up-down counting mode.
 *
 * @param[in] hdp       pointer to an @p hrtim_driver_t structure
 * @param[in] timer     timer which the configuration is related to. It can be
 *                      one of the following values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 * @param[in] brst_rollover_mode rollover event used in the burst mode
 *                       controller.It can be one of the following values:
 *            @arg @ref HRTIM_ROLLOVER_MODE_PER
 *            @arg @ref HRTIM_ROLLOVER_MODE_RST
 *            @arg @ref HRTIM_ROLLOVER_MODE_BOTH
 * @return              previous Burst roll-over mode.
 *
 * @api
 */
uint16_t hrtim_timer_set_burstmode_rollover(hrtim_driver_t *hdp,
                                            hrtim_timer_t   timer,
                                            uint16_t  brst_rollover_mode);

/**
 * @brief   Configures the roll-over mode of timer.
 * @note    It is only applied when the timer is in up-down counting mode.
 *
 * @param[in] hdp       pointer to an @p hrtim_driver_t structure
 * @param[in] timer     timer which the configuration is related to. It can be
 *                      one of the following values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 * @param[in] rollover_mode timer rollover mode configuration. It can be one of
 *                       the following values:
 *            @arg @ref HRTIM_ROLLOVER_MODE_PER
 *            @arg @ref HRTIM_ROLLOVER_MODE_RST
 *            @arg @ref HRTIM_ROLLOVER_MODE_BOTH
 * @return              previous roll-over mode.
 *
 * @api
 */
uint16_t hrtim_timer_set_rollover(hrtim_driver_t *hdp,
                                  hrtim_timer_t timer,
                                  uint16_t  rollover_mode);


/**
 * @brief   Configures the conditioning of fault input
 * @note    This function must be called before starting the timer and before
 *          enabling faults inputs.
 * @param[in] hdp       pointer to an @p hrtim_driver_t structure
 * @param[in] fault_idx fault input to be configured. It can be one of the
 *                      following values:
 *            @arg @ref HRTIM_FAULT_1
 *            @arg @ref HRTIM_FAULT_2
 *            @arg @ref HRTIM_FAULT_3
 *            @arg @ref HRTIM_FAULT_4
 *            @arg @ref HRTIM_FAULT_5
 *            @arg @ref HRTIM_FAULT_6
 * @param[in] enable    fault channel enable flag (true or false)
 * @param[in] source    source of the fault. It can be one of the following
 *                      values based on HRTIM instance:
 *            @arg @ref HRTIM1_FAULTSOURCE_FLT1_GPIO       
 *            @arg @ref HRTIM1_FAULTSOURCE_FLT2_GPIO       
 *            @arg @ref HRTIM1_FAULTSOURCE_FLT3_GPIO       
 *            @arg @ref HRTIM1_FAULTSOURCE_FLT4_GPIO       
 *            @arg @ref HRTIM1_FAULTSOURCE_FLT5_GPIO       
 *            @arg @ref HRTIM1_FAULTSOURCE_FLT6_GPIO       
 *            @arg @ref HRTIM1_FAULTSOURCE_FLT1_COMP2      
 *            @arg @ref HRTIM1_FAULTSOURCE_FLT2_COMP4      
 *            @arg @ref HRTIM1_FAULTSOURCE_FLT3_COMP6      
 *            @arg @ref HRTIM1_FAULTSOURCE_FLT4_COMP1      
 *            @arg @ref HRTIM1_FAULTSOURCE_FLT5_COMP3      
 *            @arg @ref HRTIM1_FAULTSOURCE_FLT6_COMP5      
 *            @arg @ref HRTIM1_FAULTSOURCE_FLT1_EEV1       
 *            @arg @ref HRTIM1_FAULTSOURCE_FLT2_EEV2       
 *            @arg @ref HRTIM1_FAULTSOURCE_FLT3_EEV3       
 *            @arg @ref HRTIM1_FAULTSOURCE_FLT4_EEV4       
 *            @arg @ref HRTIM1_FAULTSOURCE_FLT5_EEV5       
 *            @arg @ref HRTIM1_FAULTSOURCE_FLT6_EEV6       
 *            @arg @ref HRTIM1_FAULTSOURCE_FLT1_HRTIM2_EEV1
 *            @arg @ref HRTIM1_FAULTSOURCE_FLT2_HRTIM2_EEV2
 *            @arg @ref HRTIM1_FAULTSOURCE_FLT3_HRTIM2_EEV3
 *            @arg @ref HRTIM1_FAULTSOURCE_FLT4_HRTIM2_EEV4
 *            @arg @ref HRTIM1_FAULTSOURCE_FLT5_HRTIM2_EEV5
 *            @arg @ref HRTIM1_FAULTSOURCE_FLT6_HRTIM2_EEV6
 *            @arg @ref HRTIM2_FAULTSOURCE_FLT1_GPIO       
 *            @arg @ref HRTIM2_FAULTSOURCE_FLT2_GPIO       
 *            @arg @ref HRTIM2_FAULTSOURCE_FLT3_GPIO       
 *            @arg @ref HRTIM2_FAULTSOURCE_FLT4_GPIO       
 *            @arg @ref HRTIM2_FAULTSOURCE_FLT5_GPIO       
 *            @arg @ref HRTIM2_FAULTSOURCE_FLT6_GPIO       
 *            @arg @ref HRTIM2_FAULTSOURCE_FLT1_COMP1      
 *            @arg @ref HRTIM2_FAULTSOURCE_FLT2_COMP3      
 *            @arg @ref HRTIM2_FAULTSOURCE_FLT3_COMP5      
 *            @arg @ref HRTIM2_FAULTSOURCE_FLT4_COMP2      
 *            @arg @ref HRTIM2_FAULTSOURCE_FLT5_COMP4      
 *            @arg @ref HRTIM2_FAULTSOURCE_FLT6_COMP6      
 *            @arg @ref HRTIM2_FAULTSOURCE_FLT1_EEV1       
 *            @arg @ref HRTIM2_FAULTSOURCE_FLT2_EEV2       
 *            @arg @ref HRTIM2_FAULTSOURCE_FLT3_EEV3       
 *            @arg @ref HRTIM2_FAULTSOURCE_FLT4_EEV4       
 *            @arg @ref HRTIM2_FAULTSOURCE_FLT5_EEV5       
 *            @arg @ref HRTIM2_FAULTSOURCE_FLT6_EEV6       
 *            @arg @ref HRTIM2_FAULTSOURCE_FLT1_HRTIM1_EEV1
 *            @arg @ref HRTIM2_FAULTSOURCE_FLT2_HRTIM1_EEV2
 *            @arg @ref HRTIM2_FAULTSOURCE_FLT3_HRTIM1_EEV3
 *            @arg @ref HRTIM2_FAULTSOURCE_FLT4_HRTIM1_EEV4
 *            @arg @ref HRTIM2_FAULTSOURCE_FLT5_HRTIM1_EEV5
 *            @arg @ref HRTIM2_FAULTSOURCE_FLT6_HRTIM1_EEV6 
 * @param[in] polarity  polarity of the fault event. It can be one of the
 *                      following values:
 *            @arg @ref HRTIM_FAULTPOLARITY_LOW
 *            @arg @ref HRTIM_FAULTPOLARITY_HIGH
 * @param[in] filter    frequency used to sample the Fault input and the length
 *                      of the digital filter. It can be one of the following
 *                      values:
 *            @arg @ref HRTIM_FAULTFILTER_NONE
 *            @arg @ref HRTIM_FAULTFILTER_1
 *            @arg @ref HRTIM_FAULTFILTER_2
 *            @arg @ref HRTIM_FAULTFILTER_3
 *            @arg @ref HRTIM_FAULTFILTER_4
 *            @arg @ref HRTIM_FAULTFILTER_5
 *            @arg @ref HRTIM_FAULTFILTER_6
 *            @arg @ref HRTIM_FAULTFILTER_7
 *            @arg @ref HRTIM_FAULTFILTER_8
 *            @arg @ref HRTIM_FAULTFILTER_9
 *            @arg @ref HRTIM_FAULTFILTER_10
 *            @arg @ref HRTIM_FAULTFILTER_11
 *            @arg @ref HRTIM_FAULTFILTER_12
 *            @arg @ref HRTIM_FAULTFILTER_13
 *            @arg @ref HRTIM_FAULTFILTER_14
 *            @arg @ref HRTIM_FAULTFILTER_15
 * @param[in] lock      write protection of fault programming bits. It can be
 *                      one of the following values:
 *            @arg @ref HRTIM_FAULTLOCK_READWRITE
 *            @arg @ref HRTIM_FAULTLOCK_READONLY 
 *
 * @api
 */
void hrtim_set_fault_cfg(hrtim_driver_t *hdp,
                         hrtim_fault_t fault_idx,
                         bool enable,
                         uint32_t source,
                         uint32_t polarity,
                         uint32_t filter,
                         uint32_t lock);

/**
 * @brief   Configures the fault conditioning block prescaler.
 * @note    This function must be called before starting the timer and before
 *          enabling faults inputs
 * @param[in] hdp       pointer to an @p hrtim_driver_t structure
 * @param[in] prescaler prescaler value. It can be one of the following values:
 *            @arg @ref HRTIM_FAULTPRESCALER_DIV1
 *            @arg @ref HRTIM_FAULTPRESCALER_DIV2
 *            @arg @ref HRTIM_FAULTPRESCALER_DIV4
 *            @arg @ref HRTIM_FAULTPRESCALER_DIV8
 *
 * @api
 */
hrtim_fault_prsc_t hrtim_set_fault_prsc(hrtim_driver_t *hdp,
                                        hrtim_fault_prsc_t prescaler);
/**
 * @brief   Configures the Fault Counter (threshold and reset mode), configures
 *          and enables the blanking source of a Fault input.
 * @note    A fault is considered valid when the number of events is equal to
 *          the (FLTxCNT[3:0]+1) value.
 * @param[in] hdp       pointer to an @p hrtim_driver_t structure
 * @param[in] fault_idx fault input to be configured. It can be one of the
 *                      following values:
 *            @arg @ref HRTIM_FAULT_1
 *            @arg @ref HRTIM_FAULT_2
 *            @arg @ref HRTIM_FAULT_3
 *            @arg @ref HRTIM_FAULT_4
 *            @arg @ref HRTIM_FAULT_5
 *            @arg @ref HRTIM_FAULT_6
 * @param[in] threshold the fault counter threshold. It can be a number between
 *                      0x0 and 0xF.
 * @param[in] reset_mode the reset mode of a fault event counter. It can be one
 *                       of the following values:
 *            @arg @ref HRTIM_FAULTCOUNTERRST_UNCONDITIONAL
 *            @arg @ref HRTIM_FAULTCOUNTERRST_CONDITIONAL 
 * @param[in] blanking_source the blanking source of a fault event. It can be
 *                      one of the following values:
 *            @arg @ref HRTIM_FAULTBLANKINGMODE_RSTALIGNED
 *            @arg @ref HRTIM_FAULTBLANKINGMODE_MOVING
 *
 * @api
 */
void hrtim_set_fault_counter_cfg(hrtim_driver_t *hdp,
                                 hrtim_fault_t fault_idx,
                                 uint32_t threshold, 
                                 uint32_t reset_mode,
                                 uint32_t blanking_source);

/**
 * @brief  Sets output level in FAULT state.
 * @param[in] hdp       pointer to an @p hrtim_driver_t structure
 * @param[in] timer     timer which the configuration is related to. It can be
 *                      one of the following values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 * @param[in] output    timer output. It can be one of the following values:
 *            @arg @ref HRTIM_TIMER_OUTPUT_1
 *            @arg @ref HRTIM_TIMER_OUTPUT_2
 * @param[in] fault_state fault state. It can be one of the following values:
 *            @arg @ref HRTIM_OUTPUT_FAULTSTATE_NOACTIVE
 *            @arg @ref HRTIM_OUTPUT_FAULTSTATE_INACTIVE
 *            @arg @ref HRTIM_OUTPUT_FAULTSTATE_ACTIVE
 *            @arg @ref HRTIM_OUTPUT_FAULTSTATE_HIGHZ
 * @return              previous output fault state.
 */
hrtim_out_faultstate_t hrtim_timer_set_output_faultstate(hrtim_driver_t *hdp,
                                                         hrtim_timer_t timer,
                                                         hrtim_out_t output,
                                                         hrtim_out_faultstate_t fault_state);

/**
 * @brief  Sets output level in IDLE state.
 * @param[in] hdp       pointer to an @p hrtim_driver_t structure
 * @param[in] timer     timer which the configuration is related to. It can be
 *                      one of the following values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 * @param[in] output    timer output. It can be one of the following values:
 *            @arg @ref HRTIM_TIMER_OUTPUT_1
 *            @arg @ref HRTIM_TIMER_OUTPUT_2
 * @param[in] idle_state idle state. It can be one of the following values:
 *            @arg @ref HRTIM_OUTPUT_IDLESTATE_INACTIVE
 *            @arg @ref HRTIM_OUTPUT_IDLESTATE_ACTIVE
 * @return              previous output idle state.
 */
hrtim_out_idlestate_t hrtim_timer_set_output_idlestate(hrtim_driver_t *hdp,
                                                       hrtim_timer_t timer,
                                                       hrtim_out_t output,
                                                       hrtim_out_idlestate_t idle_state);

/**
 * @brief  Sets output polarity.
 * @param[in] hdp       pointer to an @p hrtim_driver_t structure
 * @param[in] timer     timer which the configuration is related to. It can be
 *                      one of the following values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 * @param[in] output    timer output. It can be one of the following values:
 *            @arg @ref HRTIM_TIMER_OUTPUT_1
 *            @arg @ref HRTIM_TIMER_OUTPUT_2
 * @param[in] polarity  polarity. It can be one of the following values:
 *            @arg @ref HRTIM_OUTPUT_POLARITY_POSITIVE
 *            @arg @ref HRTIM_OUTPUT_POLARITY_NEGATIVE
 * @return              previous output polarity.
 */
hrtim_out_polarity_t hrtim_timer_set_output_polarity(hrtim_driver_t *hdp,
                                                     hrtim_timer_t timer,
                                                     hrtim_out_t output,
                                                     hrtim_out_polarity_t polarity);

/**
 * @brief  Gets timer output state.
 * @param[in] hdp       pointer to an @p hrtim_driver_t structure
 * @param[in] timer     timer which the configuration is related to. It can be
 *                      one of the following values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 * @param[in] output    timer output. It can be one of the following values:
 *            @arg @ref HRTIM_TIMER_OUTPUT_1
 *            @arg @ref HRTIM_TIMER_OUTPUT_2
 * @return              timer output state. It can be one of the following
 *                      values:
 *            @arg @ref HRTIM_OUTPUT_STATE_RUN
 *            @arg @ref HRTIM_OUTPUT_STATE_IDLE
 *            @arg @ref HRTIM_OUTPUT_STATE_FAULT
 */
hrtim_output_state_t hrtim_timer_get_output_state(hrtim_driver_t *hdp,
                                                  hrtim_timer_t timer,
                                                  hrtim_out_t output);

/**
 * @brief   Configures the capture circuitry of timer.
 * @param[in] hdp       pointer to an @p hrtim_driver_t structure
 * @param[in] timer     timer which the configuration is related to. It can be
 *                      one of the following values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 * @param[in] cpt1_source capture 1 triggering source timer output. It can be
 *                      one of the following values:
 *                      - capture trigger event common at each timer (A..F)
 *            @arg @ref HRTIM_CAPTURE_TRG_NONE
 *            @arg @ref HRTIM_CAPTURE_TRG_UPDATE
 *            @arg @ref HRTIM_CAPTURE_TRG_EEV_1
 *            @arg @ref HRTIM_CAPTURE_TRG_EEV_2
 *            @arg @ref HRTIM_CAPTURE_TRG_EEV_3
 *            @arg @ref HRTIM_CAPTURE_TRG_EEV_4
 *            @arg @ref HRTIM_CAPTURE_TRG_EEV_5
 *            @arg @ref HRTIM_CAPTURE_TRG_EEV_6
 *            @arg @ref HRTIM_CAPTURE_TRG_EEV_7
 *            @arg @ref HRTIM_CAPTURE_TRG_EEV_8
 *            @arg @ref HRTIM_CAPTURE_TRG_EEV_9
 *            @arg @ref HRTIM_CAPTURE_TRG_EEV_10
 *                      - capture trigger event common at each timer but A
 *            @arg @ref HRTIM_CAPTURE_TRG_TA1_SET
 *            @arg @ref HRTIM_CAPTURE_TRG_TA1_RESET
 *            @arg @ref HRTIM_CAPTURE_TRG_TIMERA_CMP1
 *            @arg @ref HRTIM_CAPTURE_TRG_TIMERA_CMP2
 *                      - capture trigger event common at each timer but B
 *            @arg @ref HRTIM_CAPTURE_TRG_TB1_SET
 *            @arg @ref HRTIM_CAPTURE_TRG_TB1_RESET
 *            @arg @ref HRTIM_CAPTURE_TRG_TIMERB_CMP1
 *            @arg @ref HRTIM_CAPTURE_TRG_TIMERB_CMP2
 *                      - capture trigger event common at each timer but C
 *            @arg @ref HRTIM_CAPTURE_TRG_TC1_SET
 *            @arg @ref HRTIM_CAPTURE_TRG_TC1_RESET
 *            @arg @ref HRTIM_CAPTURE_TRG_TIMERC_CMP1
 *            @arg @ref HRTIM_CAPTURE_TRG_TIMERC_CMP2
 *                      - capture trigger event common at each timer but D
 *            @arg @ref HRTIM_CAPTURE_TRG_TD1_SET
 *            @arg @ref HRTIM_CAPTURE_TRG_TD1_RESET
 *            @arg @ref HRTIM_CAPTURE_TRG_TIMERD_CMP1
 *            @arg @ref HRTIM_CAPTURE_TRG_TIMERD_CMP2
 *                      - capture trigger event common at each timer but E
 *            @arg @ref HRTIM_CAPTURE_TRG_TE1_SET
 *            @arg @ref HRTIM_CAPTURE_TRG_TE1_RESET
 *            @arg @ref HRTIM_CAPTURE_TRG_TIMERE_CMP1
 *            @arg @ref HRTIM_CAPTURE_TRG_TIMERE_CMP2
 *                      - ONLY TIMER A
 *            @arg @ref HRTIM_CAPTURE_TRG_TF1_SET_TA
 *            @arg @ref HRTIM_CAPTURE_TRG_TF1_RESET_TA
 *            @arg @ref HRTIM_CAPTURE_TRG_TF_CMP1_TA
 *            @arg @ref HRTIM_CAPTURE_TRG_TF_CMP2_TA
 *                      - ONLY TIMER B
 *            @arg @ref #define HRTIM_CAPTURE_TRG_TF1_SET_TB
 *            @arg @ref #define HRTIM_CAPTURE_TRG_TF1_RESET_TB
 *            @arg @ref #define HRTIM_CAPTURE_TRG_TF_CMP1_TB
 *            @arg @ref #define HRTIM_CAPTURE_TRG_TF_CMP2_TB
 *                      - ONLY TIMER C
 *            @arg @ref #define HRTIM_CAPTURE_TRG_TF1_SET_TC
 *            @arg @ref #define HRTIM_CAPTURE_TRG_TF1_RESET_TC
 *            @arg @ref #define HRTIM_CAPTURE_TRG_TF_CMP1_TC
 *            @arg @ref #define HRTIM_CAPTURE_TRG_TF_CMP2_TC
 *                      - ONLY TIMER D
 *            @arg @ref #define HRTIM_CAPTURE_TRG_TF1_SET_TD
 *            @arg @ref #define HRTIM_CAPTURE_TRG_TF1_RESET_TD
 *            @arg @ref #define HRTIM_CAPTURE_TRG_TF_CMP1_TD
 *            @arg @ref #define HRTIM_CAPTURE_TRG_TF_CMP2_TD
 *                      - ONLY TIMER E
 *            @arg @ref #define HRTIM_CAPTURE_TRG_TF1_SET_TE
 *            @arg @ref #define HRTIM_CAPTURE_TRG_TF1_RESET_TE
 *            @arg @ref #define HRTIM_CAPTURE_TRG_TF_CMP1_TE
 *            @arg @ref #define HRTIM_CAPTURE_TRG_TF_CMP2_TE
 * @param[in] cpt2_source capture 2 source triggering the timer. It can be one
 *                      of the following values:
 *                      - capture trigger event common at each timer (A..F)
 *            @arg @ref HRTIM_CAPTURE_TRG_NONE
 *            @arg @ref HRTIM_CAPTURE_TRG_UPDATE
 *            @arg @ref HRTIM_CAPTURE_TRG_EEV_1
 *            @arg @ref HRTIM_CAPTURE_TRG_EEV_2
 *            @arg @ref HRTIM_CAPTURE_TRG_EEV_3
 *            @arg @ref HRTIM_CAPTURE_TRG_EEV_4
 *            @arg @ref HRTIM_CAPTURE_TRG_EEV_5
 *            @arg @ref HRTIM_CAPTURE_TRG_EEV_6
 *            @arg @ref HRTIM_CAPTURE_TRG_EEV_7
 *            @arg @ref HRTIM_CAPTURE_TRG_EEV_8
 *            @arg @ref HRTIM_CAPTURE_TRG_EEV_9
 *            @arg @ref HRTIM_CAPTURE_TRG_EEV_10
 *                      - capture trigger event common at each timer but A
 *            @arg @ref HRTIM_CAPTURE_TRG_TA1_SET
 *            @arg @ref HRTIM_CAPTURE_TRG_TA1_RESET
 *            @arg @ref HRTIM_CAPTURE_TRG_TIMERA_CMP1
 *            @arg @ref HRTIM_CAPTURE_TRG_TIMERA_CMP2
 *                      - capture trigger event common at each timer but B
 *            @arg @ref HRTIM_CAPTURE_TRG_TB1_SET
 *            @arg @ref HRTIM_CAPTURE_TRG_TB1_RESET
 *            @arg @ref HRTIM_CAPTURE_TRG_TIMERB_CMP1
 *            @arg @ref HRTIM_CAPTURE_TRG_TIMERB_CMP2
 *                      - capture trigger event common at each timer but C
 *            @arg @ref HRTIM_CAPTURE_TRG_TC1_SET
 *            @arg @ref HRTIM_CAPTURE_TRG_TC1_RESET
 *            @arg @ref HRTIM_CAPTURE_TRG_TIMERC_CMP1
 *            @arg @ref HRTIM_CAPTURE_TRG_TIMERC_CMP2
 *                      - capture trigger event common at each timer but D
 *            @arg @ref HRTIM_CAPTURE_TRG_TD1_SET
 *            @arg @ref HRTIM_CAPTURE_TRG_TD1_RESET
 *            @arg @ref HRTIM_CAPTURE_TRG_TIMERD_CMP1
 *            @arg @ref HRTIM_CAPTURE_TRG_TIMERD_CMP2
 *                      - capture trigger event common at each timer but E
 *            @arg @ref HRTIM_CAPTURE_TRG_TE1_SET
 *            @arg @ref HRTIM_CAPTURE_TRG_TE1_RESET
 *            @arg @ref HRTIM_CAPTURE_TRG_TIMERE_CMP1
 *            @arg @ref HRTIM_CAPTURE_TRG_TIMERE_CMP2
 *                      - ONLY TIMER A
 *            @arg @ref HRTIM_CAPTURE_TRG_TF1_SET_TA
 *            @arg @ref HRTIM_CAPTURE_TRG_TF1_RESET_TA
 *            @arg @ref HRTIM_CAPTURE_TRG_TF_CMP1_TA
 *            @arg @ref HRTIM_CAPTURE_TRG_TF_CMP2_TA
 *                      - ONLY TIMER B
 *            @arg @ref #define HRTIM_CAPTURE_TRG_TF1_SET_TB
 *            @arg @ref #define HRTIM_CAPTURE_TRG_TF1_RESET_TB
 *            @arg @ref #define HRTIM_CAPTURE_TRG_TF_CMP1_TB
 *            @arg @ref #define HRTIM_CAPTURE_TRG_TF_CMP2_TB
 *                      - ONLY TIMER C
 *            @arg @ref #define HRTIM_CAPTURE_TRG_TF1_SET_TC
 *            @arg @ref #define HRTIM_CAPTURE_TRG_TF1_RESET_TC
 *            @arg @ref #define HRTIM_CAPTURE_TRG_TF_CMP1_TC
 *            @arg @ref #define HRTIM_CAPTURE_TRG_TF_CMP2_TC
 *                      - ONLY TIMER D
 *            @arg @ref #define HRTIM_CAPTURE_TRG_TF1_SET_TD
 *            @arg @ref #define HRTIM_CAPTURE_TRG_TF1_RESET_TD
 *            @arg @ref #define HRTIM_CAPTURE_TRG_TF_CMP1_TD
 *            @arg @ref #define HRTIM_CAPTURE_TRG_TF_CMP2_TD
 *                      - ONLY TIMER E
 *            @arg @ref #define HRTIM_CAPTURE_TRG_TF1_SET_TE
 *            @arg @ref #define HRTIM_CAPTURE_TRG_TF1_RESET_TE
 *            @arg @ref #define HRTIM_CAPTURE_TRG_TF_CMP1_TE
 *            @arg @ref #define HRTIM_CAPTURE_TRG_TF_CMP2_TE
 *
 * @api
 */
void hrtim_timer_set_capture_unit(hrtim_driver_t *hdp,
                                  hrtim_timer_t timer,
                                  uint32_t cpt1_source,
                                  uint32_t cpt2_source);

/**
 * @brief   Enables the fault channel(s) for a given timer.
 * @note    This function must be invoked after hrtim_start, otherwise it has
 *          no effect.
 *
 * @param[in] hdp       pointer to an @p hrtim_driver_t structure
 * @param[in] timer     timer which the configuration is related to. It can be
 *                      one of the following values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 * @param[in] fault_idx fault input to be enabled. It can be one of the
 *                      following values:
 *            @arg @ref HRTIM_FAULT_1
 *            @arg @ref HRTIM_FAULT_2
 *            @arg @ref HRTIM_FAULT_3
 *            @arg @ref HRTIM_FAULT_4
 *            @arg @ref HRTIM_FAULT_5
 *            @arg @ref HRTIM_FAULT_6
 * @param[in] flt_lock  fault sources lock. Once it has been set, it cannot be
 *                      modified till the next system or IP reset. It can be
 *                      one of the following values:
 *            @arg @ref HRTIM_FAULTLOCK_READWRITE
 *            @arg @ref HRTIM_FAULTLOCK_READONLY
 */
void hrtim_timer_fault_enable(hrtim_driver_t *hdp,
                              hrtim_timer_t timer,
                              hrtim_fault_t flt_source,
                              uint32_t flt_lock);

/**
 * @brief   Stops an HRTIM instance.
 *
 * @param[in] hdp       pointer to a @p hrtim_driver_t structure
 *
 * @api
 */
void hrtim_stop(hrtim_driver_t *hdp);

/**
 * @brief   De-initializes an HRTIM instance.
 *
 * @param[in] hdp       pointer to a @p hrtim_driver_t structure to
 *                      be de-initialized
 *
 * @api
 */
void hrtim_deinit(hrtim_driver_t *hdp);

/**
 * @brief   Serves an HRTIM fault interrupt.
 * @note    Not an API, used internally.
 *
 * @param[in] hdp       pointer to an @p hrtim_driver_t structure
 *
 * @isr
 */
void __hrtim_serve_flt_interrupt(hrtim_driver_t *hdp);

/**
 * @brief   Serves an HRTIM master/timer interrupt.
 * @note    Not an API, used internally.
 *
 * @param[in] hdp       pointer to an @p hrtim_driver_t structure
 * @param[in] timer     master/timer which the interrupt is related to. It can
 *                      be one of the following values:
 *            @arg @ref HRTIM_TIMER_A
 *            @arg @ref HRTIM_TIMER_B
 *            @arg @ref HRTIM_TIMER_C
 *            @arg @ref HRTIM_TIMER_D
 *            @arg @ref HRTIM_TIMER_E
 *            @arg @ref HRTIM_TIMER_F
 *            @arg @ref HRTIM_TIMER_MASTER
 *
 * @isr
 */
void __hrtim_serve_timer_interrupt(hrtim_driver_t *hdp, hrtim_timer_t timer);

#ifdef __cplusplus
}
#endif

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/*===========================================================================*/
/* Module late inclusions.                                                   */
/*===========================================================================*/

#endif /* _HRTIM_H_ */

/** @} */
