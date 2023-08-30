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
 * @file    i2s.h
 * @brief   I2S driver header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup COMMS
 * @ingroup DRIVERS
 * @addtogroup I2S
 * @ingroup COMMS
 * @{
 */

#ifndef _I2S_H_
#define _I2S_H_

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
 * @brief   Type of an I2S driver.
 */
typedef struct i2s_driver i2s_driver_t;

/**
 * @enum i2s_rx_sts_t
 * I2S RX progress status.
 */
typedef enum {
    I2S_RX_READY = 0U,                 /**< RX status ready */
    I2S_RX_BUSY  = 1U,                 /**< RX status busy  */
} i2s_rx_sts_t;

/**
 * @enum i2s_tx_sts_t
 * I2S TX progress status.
 */
typedef enum {
    I2S_TX_READY = 0U,                 /**< TX status ready */
    I2S_TX_BUSY  = 1U,                 /**< TX status busy  */
} i2s_tx_sts_t;

/**
 * @enum i2s_drv_mode_t
 * I2S driver mode configuration.
 */
typedef enum {
    I2S_DRV_MODE_SYNCHRONOUS,          /**< Synchronous driver mode  */
    I2S_DRV_MODE_ASYNCHRONOUS,         /**< Asynchronous driver mode */
} i2s_drv_mode_t;


/**
 * @enum i2s_dma_mode_t
 * I2S DMA configuration.
 */
typedef enum {
    I2S_DMA_OFF,                       /**< DMA disabled */
    I2S_DMA_ON,                        /**< DMA enabled  */
} i2s_dma_mode_t;

/**
 * @brief   Type of I2S DMA configuration.
 */
typedef struct {
    /**
     * @brief   I2S TX DMA stream to be used for operations.
     */
    uint32_t                 dma_stream_tx_id;
    /**
     * @brief   I2S RX DMA stream to be used for operations.
     */
    uint32_t                 dma_stream_rx_id;
    /**
     * @brief   I2S DMA stream bus priority (3..0).
     */
    uint32_t                 dma_stream_bus_prio;
    /**
     * @brief   I2S DMA stream IRQ priority (3..15).
     */
    uint32_t                 dma_stream_irq_prio;
} i2s_dma_conf_t;

/**
 * @enum i2s_parity_t
 * I2S mode configuration.
 */
typedef enum {
    I2S_MODE_SLAVE_TX,                 /**< Slave - transmit  */
    I2S_MODE_SLAVE_RX,                 /**< Slave - receive   */
    I2S_MODE_MASTER_TX,                /**< Master - transmit */
    I2S_MODE_MASTER_RX,                /**< Master - receive  */
} i2s_mode_t;

/**
 * @enum i2s_standard_t
 * I2S standard selection configuration.
 */
typedef enum {
    I2S_STANDARD_PHILIPS,              /**< I2S Philips standard                       */
    I2S_STANDARD_MSB,                  /**< MSB justified standard (left justified)    */
    I2S_STANDARD_LSB,                  /**< LSB justified standard (right justified)   */
    I2S_STANDARD_PCM_SHORT,            /**< PCM standard - Short frame synchronization */
    I2S_STANDARD_PCM_LONG,             /**< PCM standard - Long frame synchronization  */
} i2s_standard_t;

/**
 * @enum i2s_pcmsync_t
 * I2S PCM frame synchronization configuration.
 */
typedef enum {
    I2S_PCM_SYNCHRO_SHORT,             /**< Short frame synchronization */
    I2S_PCM_SYNCHRO_LONG,              /**< Long frame synchronization  */
} i2s_pcmsync_t;

/**
 * @enum i2s_chlen_t
 * I2S channel length (number of bits per audio channel) configuration.
 */
typedef enum {
    I2S_CHANNEL_LENGTH_16B,            /**< 16-bit wide */
    I2S_CHANNEL_LENGTH_32B,            /**< 32-bit wide */
} i2s_chlen_t;

/**
 * @enum i2s_datalen_t
 * I2S data length configuration.
 */
typedef enum {
    I2S_DATA_LENGTH_16B,               /**< 16-bit data length */
    I2S_DATA_LENGTH_24B,               /**< 24-bit data length */
    I2S_DATA_LENGTH_32B,               /**< 32-bit data length */
} i2s_datalen_t;

/**
 * @enum i2s_ckpol_t
 * I2S inactive state clock polarity configuration.
 */
typedef enum {
    I2S_CLOCK_POLARITY_LOW,            /**< I2S clock inactive state is low level  */
    I2S_CLOCK_POLARITY_HIGH,           /**< I2S clock inactive state is high level */
} i2s_ckpol_t;

/**
 * @enum i2s_mckout_t
 * I2S master clock output configuration.
 */
typedef enum {
    I2S_MASTER_CLOCK_OUTPUT_DISABLE,   /**< I2S master clock output disabled */
    I2S_MASTER_CLOCK_OUTPUT_ENABLE,    /**< I2S master clock output enabled  */
} i2s_mckout_t;

/**
 * @enum i2s_audiofreq_t
 * I2S audio frequency configuration.
 */
typedef enum {
    I2S_AUDIO_FREQUENCY_DEFAULT = 2U,  /**< I2S audio frequency = 2Hz    */
    I2S_AUDIO_FREQUENCY_8K  = 8000U,   /**< I2S audio frequency = 8KHz   */
    I2S_AUDIO_FREQUENCY_11K = 11025U,  /**< I2S audio frequency = 11KHz  */
    I2S_AUDIO_FREQUENCY_16K = 16000U,  /**< I2S audio frequency = 16KHz  */
    I2S_AUDIO_FREQUENCY_22K = 22050U,  /**< I2S audio frequency = 22KHz  */
    I2S_AUDIO_FREQUENCY_32K = 32000U,  /**< I2S audio frequency = 32KHz  */
    I2S_AUDIO_FREQUENCY_44K = 44100U,  /**< I2S audio frequency = 44KHz  */
    I2S_AUDIO_FREQUENCY_48K = 48000U,  /**< I2S audio frequency = 48KHz  */
    I2S_AUDIO_FREQUENCY_96K = 96000U,  /**< I2S audio frequency = 96KHz  */
    I2S_AUDIO_FREQUENCY_192K =192000U, /**< I2S audio frequency = 192KHz */
} i2s_audiofreq_t;

/**
 * @brief   Type of I2S callbacks.
 *
 * @param[in] idp       pointer to the @p i2s_driver_t object
 */
typedef void (*i2s_cb_t)(i2s_driver_t *idp);

/**
 * @enum i2s_cb_ops_t
 * I2S callback operation type.
 */
typedef enum {
    I2S_CB_OPS_TX,                    /**< Transmit operation          */
    I2S_CB_OPS_RX,                    /**< Receive operation           */
    I2S_CB_OPS_ERR,                   /**< Error                       */
    I2S_CB_OPS_MAX                    /**< Number of driver operations */
} i2s_cb_ops_t;

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

/* Export driver modules.*/
#include <i2s_instances.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Configures I2S interrupt priority.
 * @note    This configuration becomes effective after i2s_start.
 *
 * @param[out] idp      pointer to a @p i2s_driver_t structure
 * @param[in] prio      interrupt priority to be configured
 * @return              previous interrupt priority.
 *
 * @api
 */
uint32_t i2s_set_prio(i2s_driver_t *idp, uint32_t prio);

/**
 * @brief   Configures I2S driver mode (synchronous or asynchronous).
 * @note    This configuration becomes effective after i2s_start.
 *
 * @param[out] idp      pointer to a @p i2s_driver_t structure
 * @param[in] drv_mode  driver mode to be configured. It can be one of the
 *                      following values:
 *            @arg @ref I2S_DRV_MODE_SYNCHRONOUS
 *            @arg @ref I2S_DRV_MODE_ASYNCHRONOUS
 * @return              previous driver mode. It can be one of the following
 *                      values:
 *            @arg @ref I2S_DRV_MODE_SYNCHRONOUS
 *            @arg @ref I2S_DRV_MODE_ASYNCHRONOUS
 *
 * @api
 */
i2s_drv_mode_t i2s_set_drv_mode(i2s_driver_t *idp, i2s_drv_mode_t drv_mode);

/**
 * @brief   Configures I2S DMA mode (enabled or disabled).
 * @note    This configuration becomes effective after i2s_start.
 *
 * @param[out] idp      pointer to a @p i2s_driver_t structure
 * @param[in] dma_mode  DMA mode to be configured. It can be one of the
 *                      following values:
 *            @arg @ref I2S_DMA_OFF
 *            @arg @ref I2S_DMA_ON
 * @return              previous DMA mode. It can be one of the following
 *                      values:
 *            @arg @ref I2S_DMA_OFF
 *            @arg @ref I2S_DMA_ON
 *
 * @api
 */
i2s_dma_mode_t i2s_set_dma_mode(i2s_driver_t *idp, i2s_dma_mode_t dma_mode);

/**
 * @brief   Configures I2S DMA.
 * @note    This configuration becomes effective after i2s_start.
 *
 * @param[out] idp      pointer to a @p i2s_driver_t structure
 * @param[in] dma_conf  pointer to DMA configuration to be configured
 * @return              pointer to previous DMA configuration.
 *
 * @api
 */
i2s_dma_conf_t *i2s_set_dma_conf(i2s_driver_t *idp,
                                 i2s_dma_conf_t *dma_conf);

/**
 * @brief   Configures I2S mode.
 * @note    This configuration becomes effective after i2s_start.
 *
 * @param[out] idp      pointer to a @p i2s_driver_t structure
 * @param[in] mode      mode to be configured. It can be one of the following
 *                      values:
 *            @arg @ref I2S_MODE_SLAVE_TX
 *            @arg @ref I2S_MODE_SLAVE_RX
 *            @arg @ref I2S_MODE_MASTER_TX
 *            @arg @ref I2S_MODE_MASTER_RX
 * @return              previous mode. It can be one of the following values:
 *            @arg @ref I2S_MODE_SLAVE_TX
 *            @arg @ref I2S_MODE_SLAVE_RX
 *            @arg @ref I2S_MODE_MASTER_TX
 *            @arg @ref I2S_MODE_MASTER_RX
 *
 * @api
 */
i2s_mode_t i2s_set_mode(i2s_driver_t *idp, i2s_mode_t mode);

/**
 * @brief   Configures I2S standard selection.
 * @note    This configuration becomes effective after i2s_start.
 *
 * @param[out] idp      pointer to a @p i2s_driver_t structure
 * @param[in] standard  standard selection to be configured. It can be one of
 *                      the following values
 *            @arg @ref I2S_STANDARD_PHILIPS
 *            @arg @ref I2S_STANDARD_MSB
 *            @arg @ref I2S_STANDARD_LSB
 *            @arg @ref I2S_STANDARD_PCM_SHORT
 *            @arg @ref I2S_STANDARD_PCM_LONG
 * @return              previous standard selection. It can be one of the
 *                      following values:
 *            @arg @ref I2S_STANDARD_PHILIPS
 *            @arg @ref I2S_STANDARD_MSB
 *            @arg @ref I2S_STANDARD_LSB
 *            @arg @ref I2S_STANDARD_PCM_SHORT
 *            @arg @ref I2S_STANDARD_PCM_LONG
 *
 * @api
 */
i2s_standard_t i2s_set_standard(i2s_driver_t *idp, i2s_standard_t standard);

/**
 * @brief   Configures I2S channel length.
 * @note    This configuration becomes effective after i2s_start.
 *          Channel legth value is taken into account only if datalen = 16-bit,
 *          otherwise the channel length is fixed to 32-bit.
 *
 * @param[out] idp      pointer to a @p i2s_driver_t structure
 * @param[in] chlen     channel length to be configured. It can be one of the
 *                      following values:
 *            @arg @ref I2S_CHANNEL_LENGTH_16B
 *            @arg @ref I2S_CHANNEL_LENGTH_32B
 * @return              previous channel length. It can be one of the following
 *                      values:
 *            @arg @ref I2S_CHANNEL_LENGTH_16B
 *            @arg @ref I2S_CHANNEL_LENGTH_32B
 *
 * @api
 */
i2s_chlen_t i2s_set_chlen(i2s_driver_t *idp, i2s_chlen_t chlen);

/**
 * @brief   Configures I2S data length.
 * @note    This configuration becomes effective after i2s_start.
 *
 * @param[out] idp      pointer to a @p i2s_driver_t structure
 * @param[in] datalen   data length to be configured. It can be one of the
 *                      following values:
 *            @arg @ref I2S_DATA_LENGTH_16B
 *            @arg @ref I2S_DATA_LENGTH_24B
 *            @arg @ref I2S_DATA_LENGTH_32B
 * @return              previous data length. It can be one of the following
 *                      values:
 *            @arg @ref I2S_DATA_LENGTH_16B
 *            @arg @ref I2S_DATA_LENGTH_24B
 *            @arg @ref I2S_DATA_LENGTH_32B
 *
 * @api
 */
i2s_datalen_t i2s_set_datalen(i2s_driver_t *idp, i2s_datalen_t datalen);

/**
 * @brief   Configures I2S inactive state clock polarity.
 * @note    This configuration becomes effective after i2s_start.
 *
 * @param[out] idp      pointer to a @p i2s_driver_t structure
 * @param[in] ckpol     clock polarity to be configured. It can be one of the
 *                      following values:
 *            @arg @ref I2S_CLOCK_POLARITY_LOW
 *            @arg @ref I2S_CLOCK_POLARITY_HIGH
 * @return              previous clock polarity. It can be one of the following
 *                      values:
 *            @arg @ref I2S_CLOCK_POLARITY_LOW
 *            @arg @ref I2S_CLOCK_POLARITY_HIGH
 *
 * @api
 */
i2s_ckpol_t i2s_set_ckpol(i2s_driver_t *idp, i2s_ckpol_t ckpol);

/**
 * @brief   Configures I2S master clock output.
 * @note    This configuration becomes effective after i2s_start.
 *
 * @param[out] idp      pointer to a @p i2s_driver_t structure
 * @param[in] mckout    master clock output to be configured. It can be one of
 *                      the following values:
 *            @arg @ref I2S_MASTER_CLOCK_OUTPUT_DISABLE
 *            @arg @ref I2S_MASTER_CLOCK_OUTPUT_ENABLE
 * @return              previous master clock output. It can be one of the
 *                      following values:
 *            @arg @ref I2S_MASTER_CLOCK_OUTPUT_DISABLE
 *            @arg @ref I2S_MASTER_CLOCK_OUTPUT_ENABLE
 *
 * @api
 */
i2s_mckout_t i2s_set_mckout(i2s_driver_t *idp, i2s_mckout_t mckout);


/**
 * @brief   Configures I2S audio frequency.
 * @note    This configuration becomes effective after i2s_start.
 *
 * @param[out] idp      pointer to a @p i2s_driver_t structure
 * @param[in] audiofreq audio frequency to be configured. It can be one of the
 *                      following values:
 *            @arg @ref I2S_AUDIO_FREQUENCY_DEFAULT
 *            @arg @ref I2S_AUDIO_FREQUENCY_8K
 *            @arg @ref I2S_AUDIO_FREQUENCY_11K
 *            @arg @ref I2S_AUDIO_FREQUENCY_16K
 *            @arg @ref I2S_AUDIO_FREQUENCY_22K
 *            @arg @ref I2S_AUDIO_FREQUENCY_32K
 *            @arg @ref I2S_AUDIO_FREQUENCY_44K
 *            @arg @ref I2S_AUDIO_FREQUENCY_48K
 *            @arg @ref I2S_AUDIO_FREQUENCY_96K
 *            @arg @ref I2S_AUDIO_FREQUENCY_192K
 * @return              previous audio frequency. It can be one of the
 *                      following values:
 *            @arg @ref I2S_AUDIO_FREQUENCY_DEFAULT
 *            @arg @ref I2S_AUDIO_FREQUENCY_8K
 *            @arg @ref I2S_AUDIO_FREQUENCY_11K
 *            @arg @ref I2S_AUDIO_FREQUENCY_16K
 *            @arg @ref I2S_AUDIO_FREQUENCY_22K
 *            @arg @ref I2S_AUDIO_FREQUENCY_32K
 *            @arg @ref I2S_AUDIO_FREQUENCY_44K
 *            @arg @ref I2S_AUDIO_FREQUENCY_48K
 *            @arg @ref I2S_AUDIO_FREQUENCY_96K
 *            @arg @ref I2S_AUDIO_FREQUENCY_192K
 *
 * @api
 */
i2s_audiofreq_t i2s_set_audiofreq(i2s_driver_t *idp, i2s_audiofreq_t audiofreq);

/**
 * @brief   Configures pointers to I2S callback functions.
 *
 * @param[out] idp      pointer to a @p i2s_driver_t structure
 * @param[in] cb_op     callback operation type. It can be one of the following
 *                      values:
 *            @arg @ref I2S_CB_OPS_TX
 *            @arg @ref I2S_CB_OPS_RX
 *            @arg @ref I2S_CB_OPS_ERR
 *            @arg @ref I2S_CB_OPS_MAX
 * @param[in] cb        pointer to I2S callback function
 * @return              pointer to previuos I2S callback function.
 *
 * @api
 */
i2s_cb_t i2s_set_cb(i2s_driver_t *idp, i2s_cb_ops_t cb_op, i2s_cb_t cb);

/**
 * @brief   Initializes I2S instance.
 *
 * @param[out] idp      pointer to a @p i2s_driver_t structure
 *
 * @api
 */
void i2s_init(i2s_driver_t *idp);

/**
 * @brief   Starts an I2S instance.
 *
 * @param[in] idp       pointer to a @p i2s_driver_t structure
 *
 * @api
 */
void i2s_start(i2s_driver_t *idp);

/**
 * @brief   Sends frames via I2S.
 * @note    If I2S is configured for 16-bit or 16-bit extended data frames, len
 *          is the number of 16-bit data to send. Instead, if I2S is configured
 *          for 24-bit or 32-bit data frames, len is the number of 32-bit to
 *          send.
 *
 * @param[in] idp           pointer to a @p i2s_driver_t structure
 * @param[in] data          pointer to the buffer to be written
 * @param[in] len           maximum number of frames to be written
 * @return                  The number of frames copied from the buffer.
 *
 * @api
 */
uint16_t i2s_send(i2s_driver_t *idp, uint16_t *data, uint16_t len);

/**
 * @brief   Receives frames from I2S.
 * @note    If I2S is configured for 16-bit or 16-bit extended data frames, len
 *          is the number of 16-bit data to receive. Instead, if I2S is
 *          configured for 24-bit or 32-bit data frames, len is the number of
 *          32-bit to receive.
 *
 * @param[in] idp           pointer to a @p i2s_driver_t structure
 * @param[out] data         pointer to the buffer to be read
 * @param[in] len           maximum number of frames to be read
 * @return                  The number of frames copied into the buffer.
 *
 * @api
 */
uint16_t i2s_receive(i2s_driver_t *idp, uint16_t *data, uint16_t len);

/**
 * @brief   Stops an I2S instance.
 *
 * @param[in] idp       pointer to a @p i2s_driver_t structure
 *
 * @api
 */
void i2s_stop(i2s_driver_t *idp);

/**
 * @brief   Deinitializes I2S instance.
 *
 * @param[out] idp      pointer to a @p i2s_driver_t structure
 *
 * @api
 */
void i2s_deinit(i2s_driver_t *idp);

/**
 * @brief   Shared interrupt handler.
 * @note    Not an API, used internally.
 *
 * @param[in] idp       pointer to a @p i2s_driver_t structure
 *
 * @isr
 */
void __i2s_serve_interrupt(i2s_driver_t *idp);

#ifdef __cplusplus
}
#endif

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/*===========================================================================*/
/* Module late inclusions.                                                   */
/*===========================================================================*/

#endif /* _I2S_H_ */

/** @} */
