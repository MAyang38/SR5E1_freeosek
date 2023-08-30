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
 * @file    i2s_private.h
 * @brief   I2S driver private header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup COMMS
 * @ingroup DRIVERS
 * @addtogroup I2S
 * @ingroup COMMS
 * @{
 */

#ifndef _I2S_PRIVATE_H_
#define _I2S_PRIVATE_H_

#include <dma.h>

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
 * @brief   I2S driver structure.
 * @note    This structure is internal to the I2S driver.
 */
struct i2s_driver {
    /**
     * @brief   Pointer to I2S registers block.
     */
    SPI_TypeDef              *i2s;
    /**
     * @brief   I2S Clock value.
     */
    uint32_t                 clock;
    /**
     * @brief   Pointer to transmission buffer.
     */
    uint16_t                 *tx_buf;
    /**
     * @brief   Transmission buffer length.
     */
    uint16_t                 tx_len;
    /**
     * @brief   Transmission in progress flag.
     */
    volatile i2s_tx_sts_t    tx_busy;
    /**
     * @brief   Pointer to receiving buffer.
     */
    uint16_t                 *rx_buf;
    /**
     * @brief   Receiving buffer length.
     */
    uint16_t                 rx_len;
    /**
     * @brief  Receiving in progress flag.
     */
    volatile i2s_rx_sts_t    rx_busy;
    /**
     * @brief   I2S interrupt priority.
     */
    uint32_t                 prio;
    /**
     * @brief   Driver mode (synchronous or asynchronous).
     */
    i2s_drv_mode_t           drv_mode;
    /**
     * @brief   DMA mode (enabled or disabled).
     */
    i2s_dma_mode_t           dma_mode;
    /**
     * @brief   DMA configuration.
     */
    i2s_dma_conf_t           *dma_conf;
    /**
     * @brief   Allocated RX DMA descriptor.
     */
    const dma_descriptor_t   *dma_rx_descriptor;
    /**
     * @brief   Allocated TX DMA descriptor.
     */
    const dma_descriptor_t   *dma_tx_descriptor;
    /**
     * @brief   I2S configuration mode.
     */
    i2s_mode_t               mode;
    /**
     * @brief   I2S standard selection.
     */
    i2s_standard_t           standard;
    /**
     * @brief   I2S channel length.
     */
    i2s_chlen_t              chlen;
    /**
     * @brief   I2S data length.
     */
    i2s_datalen_t            datalen;
    /**
     * @brief   I2S clock polarity.
     */
    i2s_ckpol_t              ckpol;
    /**
     * @brief   I2S master clock output.
     */
    i2s_mckout_t             mckout;
    /**
     * @brief   I2S audio frequency.
     */
    i2s_audiofreq_t          audiofreq;



    /**
     * @brief   Pointers to I2S callback functions.
     * @note    Set to @p NULL if not required.
     */
    i2s_cb_t                cb[I2S_CB_OPS_MAX];
};

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

IRQ_HANDLER(IRQ_SPI2_HANDLER);
IRQ_HANDLER(IRQ_SPI3_HANDLER);

SPI_TypeDef *i2s_dev_get_reg_ptr(i2s_driver_t *idp);
uint32_t i2s_dev_get_clock(i2s_driver_t *idp);
void i2s_dev_clock_enable(i2s_driver_t *idp);
void i2s_dev_clock_disable(i2s_driver_t *idp);
uint32_t i2s_dev_get_dma_tx_trigger(i2s_driver_t *idp);
uint32_t i2s_dev_get_dma_rx_trigger(i2s_driver_t *idp);
IRQn_Type i2s_dev_get_vector(i2s_driver_t *idp);

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/*===========================================================================*/
/* Module late inclusions.                                                   */
/*===========================================================================*/

#endif /* _I2S_PRIVATE_H_ */

/** @} */

