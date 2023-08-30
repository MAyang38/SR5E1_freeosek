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
 * @file    spi.h
 * @brief   SPI driver header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup COMMS
 * @ingroup DRIVERS
 * @addtogroup SPI
 * @ingroup COMMS
 * @{
 */

#ifndef _SPI_H_
#define _SPI_H_

#include <gpio.h>
#include <typedefs.h>

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
 * @brief   Type of a SPI driver.
 */
typedef struct spi_driver spi_driver_t;

/**
 * @enum spi_op_sts_t
 * SPI TX/RX operation progress status.
 */
typedef enum {
    SPI_OP_READY = 0U,                 /**< TX/RX operation status ready */
    SPI_OP_BUSY  = 1U,                 /**< TX/RX operation status busy  */
} spi_op_sts_t;

/**
 * @enum spi_drv_mode_t
 * SPI supported driver modes.
 */
typedef enum {
    SPI_DRV_MODE_INT_SYNC,             /**< Synchronous interrupt mode  */
    SPI_DRV_MODE_INT_ASYNC,            /**< Asynchronous interrupt mode */
    SPI_DRV_MODE_DMA_SYNC,             /**< Synchronous DMA mode        */
    SPI_DRV_MODE_DMA_ASYNC             /**< Asynchronous DMA mode       */
} spi_drv_mode_t;

/**
 * @brief   Type of SPI DMA configuration.
 */
typedef struct {
    /**
     * @brief   SPI RX DMA stream to be used for operations.
     */
    uint32_t                 dma_stream_rx_id;
    /**
     * @brief   SPI TX DMA stream to be used for operations.
     */
    uint32_t                 dma_stream_tx_id;
    /**
     * @brief   SPI DMA stream bus priority (3..0).
     */
    uint32_t                 dma_stream_bus_prio;
    /**
     * @brief   SPI IRQ priority to be assigned to the DMA stream (3..15).
     */
    uint32_t                 dma_stream_irq_prio;
} spi_dma_conf_t;

/**
 * @enum spi_mode_t
 * SPI mode configuration.
 */
typedef enum {
    SPI_MODE_SLAVE,                    /**< Slave mode   */
    SPI_MODE_MASTER,                   /**< Master mode  */
} spi_mode_t;

/**
 * @enum spi_baud_t
 * SPI baudrate configuration.
 */
typedef enum {
    SPI_BAUDRATE_DIV2,                 /**< fPCLK/2   */
    SPI_BAUDRATE_DIV4,                 /**< fPCLK/4   */
    SPI_BAUDRATE_DIV8,                 /**< fPCLK/8   */
    SPI_BAUDRATE_DIV16,                /**< fPCLK/16  */
    SPI_BAUDRATE_DIV32,                /**< fPCLK/32  */
    SPI_BAUDRATE_DIV64,                /**< fPCLK/64  */
    SPI_BAUDRATE_DIV128,               /**< fPCLK/128 */
    SPI_BAUDRATE_DIV256,               /**< fPCLK/256 */
} spi_baud_t;

/**
 * @enum spi_cpha_t
 * SPI cpha configuration.
 */
typedef enum {
    SPI_CPHA_0,                        /**< The first clock transition is the first data capture edge  */
    SPI_CPHA_1,                        /**< The second clock transition is the first data capture edge */
} spi_cpha_t;

/**
 * @enum spi_cpol_t
 * SPI cpol configuration.
 */
typedef enum {
    SPI_CPOL_0,                        /**< Clock to 0 when idle */
    SPI_CPOL_1,                        /**< Clock to 1 when idle */
} spi_cpol_t;

/**
 * @enum spi_fformat_t
 * SPI frame format configuration.
 */
typedef enum {
    SPI_FRAMEFORMAT_MSB = 0U,          /**< Data is transmitted/received with the MSB first  */
    SPI_FRAMEFORMAT_LSB = 1U,          /**< Data is transmitted/received with the LSB first  */
} spi_fformat_t;

/**
 * @enum spi_fsize_t
 * SPI frame size configuration.
 */
typedef enum {
    SPI_FRAMESIZE_4 = 3U,              /**< Frame size = 4bit  */
    SPI_FRAMESIZE_5 = 4U,              /**< Frame size = 5bit  */
    SPI_FRAMESIZE_6 = 5U,              /**< Frame size = 6bit  */
    SPI_FRAMESIZE_7 = 6U,              /**< Frame size = 7bit  */
    SPI_FRAMESIZE_8 = 7U,              /**< Frame size = 8bit  */
    SPI_FRAMESIZE_9 = 8U,              /**< Frame size = 9bit  */
    SPI_FRAMESIZE_10 = 9U,             /**< Frame size = 10bit */
    SPI_FRAMESIZE_11 = 10U,            /**< Frame size = 11bit */
    SPI_FRAMESIZE_12 = 11U,            /**< Frame size = 12bit */
    SPI_FRAMESIZE_13 = 12U,            /**< Frame size = 13bit */
    SPI_FRAMESIZE_14 = 13U,            /**< Frame size = 14bit */
    SPI_FRAMESIZE_15 = 14U,            /**< Frame size = 15bit */
    SPI_FRAMESIZE_16 = 15U,            /**< Frame size = 16bit */
} spi_fsize_t;

/**
 * @enum spi_nssp_mode_t
 * SPI chip select pulse mode.
 */
typedef enum {
    SPI_NSS_PULSE_MODE_OFF,            /**< No NSS pulse        */
    SPI_NSS_PULSE_MODE_ON,             /**< NSS pulse generated */
} spi_nssp_mode_t;

/**
 * @enum spi_nss_mode_t
 * SPI slave select modes.
 */
typedef enum {
    SPI_NSS_MODE_HARDWARE = 0U,        /**< Slave select mode = hardware */
    SPI_NSS_MODE_SOFTWARE = 1U,        /**< Slave select mode = software */
} spi_nss_mode_t;

/**
 * @brief   Type of SPI callbacks.
 *
 * @param[in] sdp       pointer to the @p spi_driver_t object
 */
typedef void (*spi_cb_t)(spi_driver_t *udp);

/**
 * @enum spi_cb_ops_t
 * SPI callback operation type.
 */
typedef enum {
    SPI_CB_OPS_DONE,                   /**< Operation completed event   */
    SPI_CB_OPS_ERR,                    /**< Error event                 */
    SPI_CB_OPS_MAX                     /**< Number of driver operations */
} spi_cb_ops_t;

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

/* Export driver modules.*/
#include <spi_instances.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Configures SPI interrupt priority.
 * @note    This configuration becomes effective after spi_start.
 *
 * @param[out] sdp      pointer to a @p spi_driver_t structure
 * @param[in] prio      interrupt priority to be configured
 * @return              previous interrupt priority.
 *
 * @api
 */
uint32_t spi_set_prio(spi_driver_t *sdp, uint32_t prio);

/**
 * @brief   Configures SPI driver mode (synchronous or asynchronous).
 * @note    This configuration becomes effective after spi_start.
 * @note    If DMA synchronous or asynchronous driver mode is selected, make
 *          sure to configure the DMA paramters with spi_set_dma_conf.
 *
 * @param[out] sdp      pointer to a @p spi_driver_t structure
 * @param[in] drv_mode  driver mode to be configured. It can be one of the
 *                      following values:
 *            @arg @ref SPI_DRV_MODE_INT_SYNC
 *            @arg @ref SPI_DRV_MODE_INT_ASYNC
 *            @arg @ref SPI_DRV_MODE_DMA_SYNC
 *            @arg @ref SPI_DRV_MODE_DMA_ASYNC
 * @return              previous driver mode. It can be one of the following
 *                      values:
 *            @arg @ref SPI_DRV_MODE_INT_SYNC
 *            @arg @ref SPI_DRV_MODE_INT_ASYNC
 *            @arg @ref SPI_DRV_MODE_DMA_SYNC
 *            @arg @ref SPI_DRV_MODE_DMA_ASYNC
 *
 * @api
 */
spi_drv_mode_t spi_set_drv_mode(spi_driver_t *sdp, spi_drv_mode_t drv_mode);

/**
 * @brief   Configures SPI DMA configuration.
 * @note    This configuration becomes effective after spi_start.
 *
 * @param[out] sdp      pointer to a @p spi_driver_t structure
 * @param[in] dma_conf  pointer to DMA configuration to be configured
 * @return              pointer to previous DMA configuration.
 *
 * @api
 */
spi_dma_conf_t *spi_set_dma_conf(spi_driver_t *sdp, spi_dma_conf_t *dma_conf);

/**
 * @brief   Configures SPI mode (master or slave).
 * @note    This configuration becomes effective after spi_start.
 *
 * @param[out] sdp      pointer to a @p spi_driver_t structure
 * @param[in] mode      SPI mode to be configured. It can be one of the
 *                      following values:
 *            @arg @ref SPI_MODE_SLAVE
 *            @arg @ref SPI_MODE_MASTER
 * @return              previous SPI mode. It can be one of the following
 *                      values:
 *            @arg @ref SPI_MODE_SLAVE
 *            @arg @ref SPI_MODE_MASTER
 *
 * @api
 */
spi_mode_t spi_set_mode(spi_driver_t *sdp, spi_mode_t mode);

/**
 * @brief   Configures SPI baudrate.
 * @note    This configuration becomes effective after spi_start.
 *
 * @param[out] sdp      pointer to a @p spi_driver_t structure
 * @param[in] baud      baudrate to be configured. It can be one of the
 *                      following values:
 *            @arg @ref SPI_BAUDRATE_DIV2
 *            @arg @ref SPI_BAUDRATE_DIV4
 *            @arg @ref SPI_BAUDRATE_DIV8
 *            @arg @ref SPI_BAUDRATE_DIV16
 *            @arg @ref SPI_BAUDRATE_DIV32
 *            @arg @ref SPI_BAUDRATE_DIV64
 *            @arg @ref SPI_BAUDRATE_DIV128
 *            @arg @ref SPI_BAUDRATE_DIV256
 * @return              previous baudrate. It can be one of the following
 *                      values:
 *            @arg @ref SPI_BAUDRATE_DIV2
 *            @arg @ref SPI_BAUDRATE_DIV4
 *            @arg @ref SPI_BAUDRATE_DIV8
 *            @arg @ref SPI_BAUDRATE_DIV16
 *            @arg @ref SPI_BAUDRATE_DIV32
 *            @arg @ref SPI_BAUDRATE_DIV64
 *            @arg @ref SPI_BAUDRATE_DIV128
 *            @arg @ref SPI_BAUDRATE_DIV256
 *
 * @api
 */
spi_baud_t spi_set_baud(spi_driver_t *sdp, spi_baud_t baud);

/**
 * @brief   Configures SPI clock phase.
 * @note    This configuration becomes effective after spi_start.
 *
 * @param[out] sdp      pointer to a @p spi_driver_t structure
 * @param[in] cpha      clock phase to be configured. It can be one of the
 *                      following values:
 *            @arg @ref SPI_CPHA_0
 *            @arg @ref SPI_CPHA_1
 * @return              previous clock phase. It can be one of the following
 *                      values:
 *            @arg @ref SPI_CPHA_0
 *            @arg @ref SPI_CPHA_1
 *
 * @api
 */
spi_cpha_t spi_set_cpha(spi_driver_t *sdp, spi_cpha_t cpha);

/**
 * @brief   Configures SPI clock polarity.
 * @note    This configuration becomes effective after spi_start.
 *
 * @param[out] sdp      pointer to a @p spi_driver_t structure
 * @param[in] cpol      clock polarity to be configured. It can be one of the
 *                      following values:
 *            @arg @ref SPI_CPOL_0
 *            @arg @ref SPI_CPOL_1
 * @return              previous clock polarity. It can be one of the following
 *                      values:
 *            @arg @ref SPI_CPOL_0
 *            @arg @ref SPI_CPOL_1
 *
 * @api
 */
spi_cpol_t spi_set_cpol(spi_driver_t *sdp, spi_cpol_t cpol);

/**
 * @brief   Configures SPI driver frame format.
 * @note    This configuration becomes effective after spi_start.
 *
 * @param[out] sdp      pointer to a @p spi_driver_t structure
 * @param[in] fformat   frame format to be configured. It can be one of the
 *                      following values:
 *            @arg @ref SPI_FRAMEFORMAT_MSB
 *            @arg @ref SPI_FRAMEFORMAT_LSB
 * @return              previous frame format. It can be one of the following
 *                      values:
 *            @arg @ref SPI_FRAMEFORMAT_MSB
 *            @arg @ref SPI_FRAMEFORMAT_LSB
 *
 * @api
 */
spi_fformat_t spi_set_fformat(spi_driver_t *sdp, spi_fformat_t fformat);

/**
 * @brief   Configures SPI driver frame size.
 * @note    This configuration becomes effective after spi_start.
 *
 * @param[out] sdp      pointer to a @p spi_driver_t structure
 * @param[in] fsize     frame size to be configured. It can be one of the
 *                      following values:
 *            @arg @ref SPI_FRAMESIZE_4
 *            @arg @ref SPI_FRAMESIZE_5
 *            @arg @ref SPI_FRAMESIZE_6
 *            @arg @ref SPI_FRAMESIZE_7
 *            @arg @ref SPI_FRAMESIZE_8
 *            @arg @ref SPI_FRAMESIZE_9
 *            @arg @ref SPI_FRAMESIZE_10
 *            @arg @ref SPI_FRAMESIZE_11
 *            @arg @ref SPI_FRAMESIZE_12
 *            @arg @ref SPI_FRAMESIZE_13
 *            @arg @ref SPI_FRAMESIZE_14
 *            @arg @ref SPI_FRAMESIZE_15
 *            @arg @ref SPI_FRAMESIZE_16
 * @return              previous frame size. It can be one of the following
 *                      values:
 *            @arg @ref SPI_FRAMESIZE_4
 *            @arg @ref SPI_FRAMESIZE_5
 *            @arg @ref SPI_FRAMESIZE_6
 *            @arg @ref SPI_FRAMESIZE_7
 *            @arg @ref SPI_FRAMESIZE_8
 *            @arg @ref SPI_FRAMESIZE_9
 *            @arg @ref SPI_FRAMESIZE_10
 *            @arg @ref SPI_FRAMESIZE_11
 *            @arg @ref SPI_FRAMESIZE_12
 *            @arg @ref SPI_FRAMESIZE_13
 *            @arg @ref SPI_FRAMESIZE_14
 *            @arg @ref SPI_FRAMESIZE_15
 *            @arg @ref SPI_FRAMESIZE_16
 *
 * @api
 */
spi_fsize_t spi_set_fsize(spi_driver_t *sdp, spi_fsize_t fsize);

/**
 * @brief   Configures SPI chip select pulse mode.
 * @note    This configuration becomes effective after spi_start.
 * @note    This configuration is taken into account only for master mode.
 *
 * @param[out] sdp      pointer to a @p spi_driver_t structure
 * @param[in] nssp      chip select pulse mode to be configured. It can be one
 *                      of the following values:
 *            @arg @ref SPI_NSS_PULSE_MODE_OFF
 *            @arg @ref SPI_NSS_PULSE_MODE_ON
 * @return              previous chip select pulse mode. It can be one of the
 *                      following values:
 *            @arg @ref SPI_NSS_PULSE_MODE_OFF
 *            @arg @ref SPI_NSS_PULSE_MODE_ON
 *
 * @api
 */
spi_nssp_mode_t spi_set_nssp_mode(spi_driver_t *sdp, spi_nssp_mode_t nssp_mode);

/**
 * @brief   Configures SPI slave select mode (hardware or software).
 * @note    This configuration becomes effective after spi_start.
 * @note    This configuration is taken into account only for master mode.
 *
 * @param[out] sdp      pointer to a @p spi_driver_t structure
 * @param[in] nss_mode  slave select mode to be configured. It can be one of
 *                      the following values:
 *            @arg @ref SPI_NSS_MODE_HARDWARE
 *            @arg @ref SPI_NSS_MODE_SOFTWARE
 * @return              previous slave select mode. It can be one of the
 *                      following values:
 *            @arg @ref SPI_NSS_MODE_HARDWARE
 *            @arg @ref SPI_NSS_MODE_SOFTWARE
 *
 * @api
 */
spi_nss_mode_t spi_set_nss_mode(spi_driver_t *sdp, spi_nss_mode_t nss_mode);

/**
 * @brief   Configures SPI slave select GPIO.
 * @note    This configuration is taken into account only for master mode.
 *
 * @param[out] sdp      pointer to a @p spi_driver_t structure
 * @param[in] nss_gpio  slave select GPIO to be configured.
 * @return              previous slave select GPIO.
 *
 * @api
 */
gpio_io_t spi_set_nss_gpio(spi_driver_t *sdp, gpio_io_t nss_gpio);

/**
 * @brief   Configures pointers to SPI callback functions.
 *
 * @param[out] sdp      pointer to a @p spi_driver_t structure
 * @param[in] cb_op     callback operation type. It can be one of the following
 *                      values:
 *            @arg @ref SPI_CB_OPS_DONE
 *            @arg @ref SPI_CB_OPS_ERR
 *            @arg @ref SPI_CB_OPS_MAX
 * @param[in] cb        pointer to SPI callback function
 * @return              pointer to previuos SPI callback function.
 *
 * @api
 */
spi_cb_t spi_set_cb(spi_driver_t *sdp, spi_cb_ops_t cb_op, spi_cb_t cb);

/**
 * @brief   Initializes a SPI instance.
 *
 * @param[out] sdp      pointer to a @p spi_driver_t structure
 *
 * @api
 */
void spi_init(spi_driver_t *sdp);

/**
 * @brief   Starts a SPI instance.
 *
 * @param[in] sdp       pointer to a @p spi_driver_t structure
 *
 * @api
 */
void spi_start(spi_driver_t *sdp);

/**
 * @brief   Exchanges frames via SPI.
 * @note    If the frame size is bigger than SPI_FRAMESIZE_8, the size of 
 *          tx_buf/rx_buf must be (2 * n_frames).
 *
 * @param[in] sdp           pointer to a @p spi_driver_t structure
 * @param[in] tx_buf        pointer to the tx buffer to be sent
 * @param[out] rx_buf       pointer to the tx buffer to be received
 * @param[in] n_frames      maximum number of frames to be exchanged
 * @return                  number of frames exchanged.
 *
 * @api
 */
uint32_t spi_exchange(spi_driver_t *sdp, const uint8_t *tx_buf,
                      uint8_t *rx_buf, uint32_t n_frames);

/**
 * @brief   Sends frames via SPI.
 * @note    If the frame size is bigger than SPI_FRAMESIZE_8, the size of 
 *          tx_buf must be (2 * n_frames).
 *
 * @param[in] sdp           pointer to a @p spi_driver_t structure
 * @param[in] tx_buf        pointer to the tx buffer to be sent
 * @param[in] n_frames      maximum number of frames to be sent
 * @return                  number of frames sent.
 *
 * @api
 */
uint32_t spi_send(spi_driver_t *sdp, const uint8_t *tx_buf, uint32_t n_frames);

/**
 * @brief   Receives frames via SPI.
 * @note    If the frame size is bigger than SPI_FRAMESIZE_8, the size of 
 *          rx_buf must be (2 * n_frames).
 *
 * @param[in] sdp           pointer to a @p spi_driver_t structure
 * @param[out] rx_buf       pointer to the tx buffer to be received
 * @param[in] n_frames      maximum number of frames to be received
 * @return                  number of frames received.
 *
 * @api
 */
uint32_t spi_receive(spi_driver_t *sdp, uint8_t *rx_buf, uint32_t n_frames);

/**
 * @brief   Stops a SPI instance.
 *
 * @param[in] sdp       pointer to an @p spi_driver_t structure
 *
 * @api
 */
void spi_stop(spi_driver_t *sdp);

/**
 * @brief   Deinitializes a SPI instance.
 *
 * @param[out] sdp      pointer to a @p spi_driver_t structure
 *
 * @api
 */
void spi_deinit(spi_driver_t *sdp);

/**
 * @brief   Shared interrupt handler.
 * @note    Not an API, used internally.
 *
 * @param[in] sdp       pointer to a @p spi_driver_t structure
 *
 * @isr
 */
void __spi_serve_interrupt(spi_driver_t *sdp);
	
#ifdef __cplusplus
}
#endif

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/*===========================================================================*/
/* Module late inclusions.                                                   */
/*===========================================================================*/

#endif /* _SPI_H_ */

/** @} */
