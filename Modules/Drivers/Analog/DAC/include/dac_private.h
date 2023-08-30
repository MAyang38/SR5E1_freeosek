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
 * @file    dac_private.h
 * @brief   DAC driver private header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup ANALOG
 * @ingroup DRIVERS
 * @addtogroup DAC
 * @ingroup ANALOG
 * @{
 */

#ifndef _DAC_PRIVATE_H_
#define _DAC_PRIVATE_H_

#include <irq.h>
#include <dma.h>
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
 * @brief   DAC driver structure.
 * @note    This structure is internal to the DAC driver.
 */
struct dac_driver {
    /**
     * @brief   Pointer to DAC registers block.
     */
    DAC_TypeDef              *dac;
    /**
     * @brief   DAC Clock value.
     */
    uint32_t                 clock;
    /**
     * @brief   DAC interrupt priority.
     */
    uint32_t                 prio;
    /**
     * @brief   DAC channel enable flag.
     */
    bool                     is_channel_en[DAC_CHANNEL_NUM];
    /**
     * @brief   DAC high frequency mode.
     */
    dac_hf_mode_t            hf_mode;
    /**
     * @brief   DAC channel calibration enable flag.
     */
    bool                     is_calibration_en[DAC_CHANNEL_NUM];
    /**
     * @brief   DAC channel data format (8bit or 12bit).
     */
    dac_data_format_t        data_format[DAC_CHANNEL_NUM];
    /**
     * @brief   DAC channel trigger source selection (software or external
     *          event).
     */
    dac_trigger_src_t        trigger_src[DAC_CHANNEL_NUM];
    /**
     * @brief   DAC channel increment trigger source selection (software or
     *          external event).
     */
    dac_inc_trigger_src_t    inc_trigger_src[DAC_CHANNEL_NUM];
    /**
     * @brief   DAC channel reset trigger source selection (software or
     *          external event).
     */
    dac_rst_trigger_src_t    rst_trigger_src[DAC_CHANNEL_NUM];
    /**
     * @brief   DAC channel trigger enable flag.
     */
    bool                     is_trigger_en[DAC_CHANNEL_NUM];
    /**
     * @brief   Driver mode (single or dual).
     */
    dac_drv_mode_t           drv_mode;
    /**
     * @brief   DAC channel wave mode (disable, noise, triangle or sawtooth).
     */
    dac_wave_mode_t          wave_mode[DAC_CHANNEL_NUM];
    /**
     * @brief   DAC channel output connection mode.
     */
    dac_out_con_mode_t       out_con_mode[DAC_CHANNEL_NUM];
    /**
     * @brief   DMA mode (enabled or disabled).
     */
    dac_dma_mode_t           dma_mode[DAC_CHANNEL_NUM];
    /**
     * @brief   Pointers to DAC callback functions.
     * @note    Set to @p NULL if not required.
     */
    dac_cb_t                 cb;
};

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

IRQ_HANDLER(IRQ_DAC1_HANDLER);
IRQ_HANDLER(IRQ_DAC2_HANDLER);
IRQ_HANDLER(IRQ_DAC3_HANDLER);
IRQ_HANDLER(IRQ_DAC4_HANDLER);
IRQ_HANDLER(IRQ_B_DAC1_HANDLER);

DAC_TypeDef *dac_dev_get_reg_ptr(dac_driver_t *ddp);
void dac_dev_clock_enable(dac_driver_t *ddp);
void dac_dev_clock_disable(dac_driver_t *ddp);
IRQn_Type dac_dev_get_vector(dac_driver_t *ddp);

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/*===========================================================================*/
/* Module late inclusions.                                                   */
/*===========================================================================*/

#endif /* _DAC_PRIVATE_H_ */

/** @} */
