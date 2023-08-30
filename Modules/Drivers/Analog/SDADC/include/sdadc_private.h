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
 * @file    sdadc_private.h
 * @brief   SDADC driver private header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup ANALOG
 * @ingroup DRIVERS
 * @addtogroup SDADC
 * @ingroup ANALOG
 * @{
 */

#ifndef _SDADC_PRIVATE_H_
#define _SDADC_PRIVATE_H_

#include <irq.h>
#include <platform.h>

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

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
 * @brief   SDADC driver structure.
 * @note    This structure is internal to the SDADC driver.
 */
struct sdadc_driver {
    /**
     * @brief   Pointer to SDADC registers block.
     */
    SDADC_TypeDef            *sdadc;
	/**
     * @brief   SDADC interrupt priority.
     */
    uint32_t                 prio;
    /**
     * @brief   Ground reference.
     */
    float                    vrefn;
    /**
     * @brief   Voltage reference.
     */
    float                    vrefp;
    /**
     * @brief   Calibration type.
     */
    sdadc_calibration_t      calibration;
    /**
     * @brief   Mode Selection.
     */
    sdadc_mode_t             mode;
    /**
     * @brief   Common voltage bias selection for single ended mode.
     */
    sdadc_vcomsel_t          vcomsel;
    /**
     * @brief   Analog channel selection
     */
    sdadc_anchsel_t          anchsel;
    /**
     * @brief   Programmable Decimation Rate
     */
    sdadc_pdr_t              pdr;
    /**
     * @brief   Programmable Gain
     */
    sdadc_pgain_t            pgain;
    /**
     * @brief   High Pass Filter enable flag
     */
    bool                     is_hpass_en;
    /**
     * @brief   BIAS enable flag
     */
    bool                     is_bias_en;
    /**
     * @brief   Output Settling Delay
     */
    uint8_t                  osd;
    /**
     * @brief   FIFO size
     */
    sdadc_fsize_t            fsize;
    /**
     * @brief   FIFO Overwrite enable flag
     */
    bool                     is_fifo_ow_en;
    /**
     * @brief   FIFO full event interrupt enabled flag
     */
    bool                     is_fifo_full_en;
    /**
     * @brief   FIFO threshold
     */
    uint8_t                  fifo_threshold;
    /**
     * @brief   FIFO full event callback function
     * @note    Set to @p NULL if not required.
     */
    sdadc_cb_t               fifo_full_cb;
    /**
     * @brief   FIFO overrun event interrupt enabled flag
     */
    bool                     is_fifo_overrun_en;
    /**
     * @brief   FIFO overrun event callback function
     * @note    Set to @p NULL if not required.
     */
    sdadc_cb_t               fifo_overrun_cb;
    /**
     * @brief   Watchdog event enable flag
     */
    bool                     is_watchdog_en;
    /**
     * @brief   Watchdog low threshold
     */
    float                    watchdog_lowth;
    /**
     * @brief   Watchdog event enable
     * @note    Set to @p NULL if not required.
     */
    float                    watchdog_highth;
    /**
     * @brief   Watchdog event callback function
     */
    sdadc_cb_t               watchdog_cb;
    /**
     * @brief   Offset calibration value
     */
    float                    offset_calibration;
    /**
     * @brief   Gain calibration value
     */
    float                    gain_calibration;
};

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

IRQ_HANDLER(IRQ_SD_ADC1_HANDLER);
IRQ_HANDLER(IRQ_SD_ADC2_HANDLER);

SDADC_TypeDef *sdadc_dev_get_reg_ptr(sdadc_driver_t *sdp);
void sdadc_dev_clock_enable(sdadc_driver_t *sdp);
void sdadc_dev_clock_disable(sdadc_driver_t *sdp);
IRQn_Type sdadc_dev_get_vector(sdadc_driver_t *sdp) ;

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/*===========================================================================*/
/* Module late inclusions.                                                   */
/*===========================================================================*/

#endif /* _SDADC_PRIVATE_H_ */

/** @} */
