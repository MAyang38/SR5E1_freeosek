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
 * @file    spi_private.h
 * @brief   SPI driver private header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup COMMS
 * @ingroup DRIVERS
 * @addtogroup SPI
 * @ingroup COMMS
 * @{
 */

#ifndef _SPI_PRIVATE_H_
#define _SPI_PRIVATE_H_

#include <dma.h>
#include <gpio.h>

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
 * @brief   SPI driver structure.
 * @note    This structure is internal to the SPI driver.
 */
struct spi_driver {
    /**
     * @brief  Pointer to SPI registers block.
     */
    SPI_TypeDef              *spi;
    /**
     * @brief   SPI Clock value.
     */
    uint32_t                 clock;
    /**
     * @brief   Number of frames to receive.
     */
    uint32_t                 rx_n_frames;
    /**
     * @brief   Number of frames to transmit.
     */
    uint32_t                 tx_n_frames;
    /**
     * @brief   Pointer to the SPI TX buffer or @p NULL.
     */
    const uint8_t            *tx_buf;
    /**
     * @brief   Pointer to the SPI RX buffer or @p NULL.
     */
    uint8_t                  *rx_buf;
    /**
     * @brief  Transmission/receiving operation in progress flag.
     */
    volatile spi_op_sts_t    op_busy;
    /**
     * @brief   SPI interrupt priority.
     */
    uint32_t                 prio;
    /**
     * @brief   Driver mode.
     */
    spi_drv_mode_t           drv_mode;
    /**
     * @brief   DMA configuration.
     */
    spi_dma_conf_t           *dma_conf;
    /**
     * @brief   Allocated TX DMA descriptor.
     */
    const dma_descriptor_t   *dma_tx_descriptor;
    /**
     * @brief   Allocated RX DMA descriptor.
     */
    const dma_descriptor_t   *dma_rx_descriptor;
    /**
     * @brief   TX DMA transfer mode flags.
     */
    uint32_t                 dma_tx_mode;
    /**
     * @brief   RX DMA transfer mode flags.
     */
    uint32_t                 dma_rx_mode;
    /**
     * @brief   SPI mode (master or slave).
     */
    spi_mode_t               mode;
    /**
     * @brief   SPI baud rate.
     */
    spi_baud_t               baud;
    /**
     * @brief   SPI clock phase.
     */
    spi_cpha_t               cpha;
    /**
     * @brief   SPI clock polarity.
     */
    spi_cpol_t               cpol;
    /**
     * @brief   SPI frame format (MSB or LSB).
     */
    spi_fformat_t            fformat;
    /**
     * @brief   SPI frame size.
     */
    spi_fsize_t              fsize;
    /**
     * @brief   SPI chip select pulse mode.
     * @note    This configuration is taken into account only for master mode.
     */
    spi_nssp_mode_t          nssp_mode;
    /**
     * @brief   SPI slave select mode (hardware or software).
     * @note    This configuration is taken into account only for master mode.
     * @note    In multi-slave communication, the master uses GPIO pins to
     *          manage the chip select lines for each slave. To manage the
     *          multi-slave communication, the slave select mode must be set
     *          as software and the slave select gpio must specify the unique
     *          identifier of the GPIO pin used as chip select.
     */
    spi_nss_mode_t           nss_mode;
    /**
     * @brief   SPI slave select GPIO.
     * @note    This configuration is taken into account only for master mode.
     * @note    This parameter specifies the unique identifier of the GPIO pin
     *          used as chip select in the multi-slave communication. It is used
     *          only when the SPI slave select mode is set as software.
     */
    gpio_io_t                nss_gpio;
    /**
     * @brief   Pointers to SPI callback functions.
     * @note    Set to @p NULL if not required.
     */
    spi_cb_t                 cb[SPI_CB_OPS_MAX];
};

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

IRQ_HANDLER(IRQ_SPI1_HANDLER);
IRQ_HANDLER(IRQ_SPI2_HANDLER);
IRQ_HANDLER(IRQ_SPI3_HANDLER);
IRQ_HANDLER(IRQ_SPI4_HANDLER);

SPI_TypeDef *spi_dev_get_reg_ptr(spi_driver_t *sdp);
uint32_t spi_dev_get_clock(spi_driver_t *sdp);
void spi_dev_clock_enable(spi_driver_t *sdp);
void spi_dev_clock_disable(spi_driver_t *sdp);
uint32_t spi_dev_get_dma_tx_trigger(spi_driver_t *sdp);
uint32_t spi_dev_get_dma_rx_trigger(spi_driver_t *sdp);
IRQn_Type spi_dev_get_vector(spi_driver_t *sdp);

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/*===========================================================================*/
/* Module late inclusions.                                                   */
/*===========================================================================*/

#endif /* _SPI_PRIVATE_H_ */

/** @} */
