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
 * @file    uart.h
 * @brief   UART driver header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup COMMS
 * @ingroup DRIVERS
 * @addtogroup UART
 * @ingroup COMMS
 * @{
 */

#ifndef _UART_H_
#define _UART_H_

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
 * @brief   Type of an UART driver.
 */
typedef struct uart_driver uart_driver_t;

/**
 * @enum uart_rx_sts_t
 * UART RX progress status.
 */
typedef enum {
    UART_RX_READY = 0U,                /**< RX status ready */
    UART_RX_BUSY  = 1U,                /**< RX status busy  */
} uart_rx_sts_t;

/**
 * @enum uart_tx_sts_t
 * UART TX progress status.
 */
typedef enum {
    UART_TX_READY = 0U,                /**< TX status ready */
    UART_TX_BUSY  = 1U,                /**< TX status busy  */
} uart_tx_sts_t;

/**
 * @enum uart_rx_drv_mode_t
 * UART RX driver mode supported configurations.
 */
typedef enum {
    UART_RX_DRV_MODE_INT_SYNC,         /**< Synchronous RX interrupt mode  */
    UART_RX_DRV_MODE_INT_ASYNC,        /**< Asynchronous RX interrupt mode */
    UART_RX_DRV_MODE_DMA_SYNC,         /**< Synchronous RX DMA mode        */
    UART_RX_DRV_MODE_DMA_ASYNC,        /**< Asynchronous RX DMA mode       */
    UART_RX_DRV_MODE_INT_BUFF_SYNC     /**< Synchronous RX buffered mode   */
} uart_rx_drv_mode_t;

/**
 * @enum uart_tx_drv_mode_t
 * UART TX driver mode supported configurations.
 */
typedef enum {
    UART_TX_DRV_MODE_INT_SYNC,         /**< Synchronous TX interrupt mode  */
    UART_TX_DRV_MODE_INT_ASYNC,        /**< Asynchronous TX interrupt mode */
    UART_TX_DRV_MODE_DMA_SYNC,         /**< Synchronous TX DMA mode        */
    UART_TX_DRV_MODE_DMA_ASYNC         /**< Asynchronous TX DMA mode       */
} uart_tx_drv_mode_t;

/**
 * @enum uart_rx_fifo_thr_t
 * UART RX FIFO threshold supported configurations.
 */
typedef enum {
    UART_RX_FIFO_THR_1_8 = 0,          /**< RX FIFO reaches 1/8 of its depth */
    UART_RX_FIFO_THR_1_4 = 1,          /**< RX FIFO reaches 1/4 of its depth */
    UART_RX_FIFO_THR_1_2 = 2,          /**< RX FIFO reaches 1/2 of its depth */
    UART_RX_FIFO_THR_3_4 = 3,          /**< RX FIFO reaches 3/4 of its depth */
    UART_RX_FIFO_THR_7_8 = 4,          /**< RX FIFO reaches 7/8 of its depth */
    UART_RX_FIFO_THR_FULL = 5,         /**< RX FIFO becomes full             */
} uart_rx_fifo_thr_t;

/**
 * @enum uart_tx_fifo_thr_t
 * UART TX FIFO threshold supported configurations.
 */
typedef enum {
    UART_TX_FIFO_THR_1_8 = 0,          /**< TX FIFO reaches 1/8 of its depth */
    UART_TX_FIFO_THR_1_4 = 1,          /**< TX FIFO reaches 1/4 of its depth */
    UART_TX_FIFO_THR_1_2 = 2,          /**< TX FIFO reaches 1/2 of its depth */
    UART_TX_FIFO_THR_3_4 = 3,          /**< TX FIFO reaches 3/4 of its depth */
    UART_TX_FIFO_THR_7_8 = 4,          /**< TX FIFO reaches 7/8 of its depth */
    UART_TX_FIFO_THR_EMPTY = 5,        /**< TX FIFO becomes empty            */
} uart_tx_fifo_thr_t;

/**
 * @brief   Type of UART DMA configuration.
 */
typedef struct {
    /**
     * @brief   UART TX DMA stream to be used for operations.
     */
    uint32_t                 dma_stream_tx_id;
    /**
     * @brief   UART RX DMA stream to be used for operations.
     */
    uint32_t                 dma_stream_rx_id;
    /**
     * @brief   UART DMA stream bus priority (3..0).
     */
    uint32_t                 dma_stream_bus_prio;
    /**
     * @brief   UART DMA stream IRQ priority (3..15).
     */
    uint32_t                 dma_stream_irq_prio;
} uart_dma_conf_t;

/**
 * @enum uart_baudrate_t
 * UART baudrate configuration.
 */
typedef enum {
    UART_BAUDRATE_110    = 110U,       /**<    110 bits per second */
    UART_BAUDRATE_300    = 300U,       /**<    300 bits per second */
    UART_BAUDRATE_600    = 600U,       /**<    600 bits per second */
    UART_BAUDRATE_1200   = 1200U,      /**<   1200 bits per second */
    UART_BAUDRATE_2400   = 2400U,      /**<   2400 bits per second */
    UART_BAUDRATE_4800   = 4800U,      /**<   4800 bits per second */
    UART_BAUDRATE_9600   = 9600U,      /**<   9600 bits per second */
    UART_BAUDRATE_14400  = 14400U,     /**<  14400 bits per second */
    UART_BAUDRATE_19200  = 19200U,     /**<  19200 bits per second */
    UART_BAUDRATE_38400  = 38400U,     /**<  38400 bits per second */
    UART_BAUDRATE_57600  = 57600U,     /**<  57600 bits per second */
    UART_BAUDRATE_115200 = 115200U,    /**< 115200 bits per second */
    UART_BAUDRATE_230400 = 230400U,    /**< 230400 bits per second */
    UART_BAUDRATE_460800 = 460800U,    /**< 460800 bits per second */
    UART_BAUDRATE_921600 = 921600U     /**< 921600 bits per second */
} uart_baud_t;

/**
 * @enum uart_presc_t
 * UART prescaler configuration.
 */
typedef enum {
    UART_PRESCALER_DIV1   = 0U,        /**< input clock not divided    */
    UART_PRESCALER_DIV2   = 1U,        /**< input clock divided by 2   */
    UART_PRESCALER_DIV4   = 2U,        /**< input clock divided by 4   */
    UART_PRESCALER_DIV6   = 3U,        /**< input clock divided by 6   */
    UART_PRESCALER_DIV8   = 4U,        /**< input clock divided by 8   */
    UART_PRESCALER_DIV10  = 5U,        /**< input clock divided by 10  */
    UART_PRESCALER_DIV12  = 6U,        /**< input clock divided by 12  */
    UART_PRESCALER_DIV16  = 7U,        /**< input clock divided by 16  */
    UART_PRESCALER_DIV32  = 8U,        /**< input clock divided by 32  */
    UART_PRESCALER_DIV64  = 9U,        /**< input clock divided by 64  */
    UART_PRESCALER_DIV128 = 10U,       /**< input clock divided by 128 */
    UART_PRESCALER_DIV256 = 11U,       /**< input clock divided by 256 */
} uart_presc_t;

/**
 * @enum uart_parity_t
 * UART parity control configuration.
 */
typedef enum {
    UART_PARITY_NONE,                  /**< No parity   */
    UART_PARITY_EVEN,                  /**< Even parity */
    UART_PARITY_ODD,                   /**< Odd parity  */
} uart_parity_t;

/**
 * @enum uart_over_t
 * UART oversampling configuration.
 */
typedef enum {
    UART_OVERSAMPLING_16 = 0U,         /**< oversampling by 16 */
    UART_OVERSAMPLING_8 = 1U,          /**< Oversampling by 8  */
} uart_over_t;

/**
 * @enum uart_sbit_t
 * UART stop bits configuration.
 */
typedef enum {
    UART_STOPBIT_1   = 0U,             /**< 1 stop bit    */
    UART_STOPBIT_0P5 = 1U,             /**< 0.5 stop bit  */
    UART_STOPBIT_2   = 2U,             /**< 2 stop bits   */
    UART_STOPBIT_1P5 = 3U,             /**< 1.5 stop bits */
} uart_sbit_t;

/**
 * @brief   Type of UART callbacks.
 *
 * @param[in] udp       pointer to the @p uart_driver_t object
 */
typedef void (*uart_cb_t)(uart_driver_t *udp);

/**
 * @enum uart_cb_ops_t
 * UART callback operation type.
 */
typedef enum {
    UART_CB_OPS_TX,                    /**< Transmit operation          */
    UART_CB_OPS_RX,                    /**< Receive operation           */
    UART_CB_OPS_ERR,                   /**< Error                       */
    UART_CB_OPS_PERR,                  /**< Parity error                */
    UART_CB_OPS_MAX                    /**< Number of driver operations */
} uart_cb_ops_t;

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

/* Export driver modules.*/
#include <uart_instances.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Configures UART interrupt priority.
 * @note    This configuration becomes effective after uart_start.
 *
 * @param[out] udp      pointer to a @p uart_driver_t structure
 * @param[in] prio      interrupt priority to be configured
 * @return              previous interrupt priority.
 *
 * @api
 */
uint32_t uart_set_prio(uart_driver_t *udp, uint32_t prio);

/**
 * @brief   Configures UART RX driver mode.
 * @note    This configuration becomes effective after uart_start.
 * @note    If DMA synchronous or asynchronous driver mode is selected, make
 *          sure to configure the DMA paramters with uart_set_dma_conf.
 * @note    If interrupt buffered mode is selected, make sure to configure the
 *          buffer with uart_set_sbrx_buf and keep the FIFO disabled.
 *
 * @param[out] udp        pointer to a @p uart_driver_t structure
 * @param[in] rx_drv_mode RX driver mode to be configured. It can be one of the
 *                        following values:
 *              @arg @ref UART_RX_DRV_MODE_INT_SYNC
 *              @arg @ref UART_RX_DRV_MODE_INT_ASYNC
 *              @arg @ref UART_RX_DRV_MODE_DMA_SYNC
 *              @arg @ref UART_RX_DRV_MODE_DMA_ASYNC
 *              @arg @ref UART_RX_DRV_MODE_INT_BUFF_SYNC
 * @return                previous RX driver mode. It can be one of the
 *                        following values:
 *              @arg @ref UART_RX_DRV_MODE_INT_SYNC
 *              @arg @ref UART_RX_DRV_MODE_INT_ASYNC
 *              @arg @ref UART_RX_DRV_MODE_DMA_SYNC
 *              @arg @ref UART_RX_DRV_MODE_DMA_ASYNC
 *              @arg @ref UART_RX_DRV_MODE_INT_BUFF_SYNC
 *
 * @api
 */
uart_rx_drv_mode_t uart_set_rx_drv_mode(uart_driver_t *udp,
                                        uart_rx_drv_mode_t rx_drv_mode);

/**
 * @brief   Configures UART TX driver mode.
 * @note    This configuration becomes effective after uart_start.
 * @note    If DMA synchronous or asynchronous driver mode is selected, make
 *          sure to configure the DMA paramters with uart_set_dma_conf.
 *
 * @param[out] udp        pointer to a @p uart_driver_t structure
 * @param[in] tx_drv_mode TX driver mode to be configured. It can be one of the
 *                        following values:
 *              @arg @ref UART_TX_DRV_MODE_INT_SYNC
 *              @arg @ref UART_TX_DRV_MODE_INT_ASYNC
 *              @arg @ref UART_TX_DRV_MODE_DMA_SYNC
 *              @arg @ref UART_TX_DRV_MODE_DMA_ASYNC
 * @return                previous TX driver mode. It can be one of the
 *                        following values:
 *              @arg @ref UART_TX_DRV_MODE_INT_SYNC
 *              @arg @ref UART_TX_DRV_MODE_INT_ASYNC
 *              @arg @ref UART_TX_DRV_MODE_DMA_SYNC
 *              @arg @ref UART_TX_DRV_MODE_DMA_ASYNC
 *
 * @api
 */
uart_tx_drv_mode_t uart_set_tx_drv_mode(uart_driver_t *udp,
                                        uart_tx_drv_mode_t tx_drv_mode);

/**
 * @brief   Enables/Disables UART FIFO.
 * @note    This configuration becomes effective after uart_start.
 * @note    If FIFO is enabled, make sure to configure the FIFO paramters with
 *          uart_set_fifo_threshold.
 *
 * @param[out] udp      pointer to a @p uart_driver_t structure
 * @param[in] enable    FIFO enable status ("true" means the FIFO is enabled,
 *                      "false" means the FIFO is disabled)
 * @return              previous FIFO enable status.
 *
 * @api
 */
bool uart_set_fifo_enable(uart_driver_t *udp, bool enable);

/**
 * @brief   Configures UART FIFO thresholds.
 * @note    This configuration becomes effective after uart_start.
 *
 * @param[out] udp      pointer to a @p uart_driver_t structure
 * @param[in] rxft      RX threshold configuration to be configured. It can
 *                      be one of the following values:
 *            @arg @ref UART_RX_FIFO_THR_1_8
 *            @arg @ref UART_RX_FIFO_THR_1_4
 *            @arg @ref UART_RX_FIFO_THR_1_2
 *            @arg @ref UART_RX_FIFO_THR_3_4
 *            @arg @ref UART_RX_FIFO_THR_7_8
 *            @arg @ref UART_RX_FIFO_THR_FULL
 * @param[in] txft      TX threshold configuration to be configured. It can
 *                      be one of the following values:
 *            @arg @ref UART_TX_FIFO_THR_1_8
 *            @arg @ref UART_TX_FIFO_THR_1_4
 *            @arg @ref UART_TX_FIFO_THR_1_2
 *            @arg @ref UART_TX_FIFO_THR_3_4
 *            @arg @ref UART_TX_FIFO_THR_7_8
 *            @arg @ref UART_TX_FIFO_THR_EMPTY
 * @api
 */
void uart_set_fifo_threshold(uart_driver_t *udp, uart_rx_fifo_thr_t rxft,
                             uart_tx_fifo_thr_t txft);
/**
 * @brief   Configures UART DMA.
 * @note    This configuration becomes effective after uart_start.
 *
 * @param[out] udp      pointer to a @p uart_driver_t structure
 * @param[in] dma_conf  pointer to DMA configuration to be configured
 * @return              pointer to previous DMA configuration.
 *
 * @api
 */
uart_dma_conf_t *uart_set_dma_conf(uart_driver_t *udp,
                                   uart_dma_conf_t *dma_conf);

/**
 * @brief   Configures UART baudrate.
 * @note    This configuration becomes effective after uart_start.
 *
 * @param[out] udp      pointer to a @p uart_driver_t structure
 * @param[in] baud      baudrate to be configured. It can be one of the
 *                      following values:
 *            @arg @ref UART_BAUDRATE_110
 *            @arg @ref UART_BAUDRATE_300
 *            @arg @ref UART_BAUDRATE_600
 *            @arg @ref UART_BAUDRATE_1200
 *            @arg @ref UART_BAUDRATE_2400
 *            @arg @ref UART_BAUDRATE_4800
 *            @arg @ref UART_BAUDRATE_9600
 *            @arg @ref UART_BAUDRATE_14400
 *            @arg @ref UART_BAUDRATE_19200
 *            @arg @ref UART_BAUDRATE_38400
 *            @arg @ref UART_BAUDRATE_57600
 *            @arg @ref UART_BAUDRATE_115200
 *            @arg @ref UART_BAUDRATE_230400
 *            @arg @ref UART_BAUDRATE_460800
 *            @arg @ref UART_BAUDRATE_921600
 * @return              previous baudrate. It can be one of the following
 *                      values:
 *            @arg @ref UART_BAUDRATE_110
 *            @arg @ref UART_BAUDRATE_300
 *            @arg @ref UART_BAUDRATE_600
 *            @arg @ref UART_BAUDRATE_1200
 *            @arg @ref UART_BAUDRATE_2400
 *            @arg @ref UART_BAUDRATE_4800
 *            @arg @ref UART_BAUDRATE_9600
 *            @arg @ref UART_BAUDRATE_14400
 *            @arg @ref UART_BAUDRATE_19200
 *            @arg @ref UART_BAUDRATE_38400
 *            @arg @ref UART_BAUDRATE_57600
 *            @arg @ref UART_BAUDRATE_115200
 *            @arg @ref UART_BAUDRATE_230400
 *            @arg @ref UART_BAUDRATE_460800
 *            @arg @ref UART_BAUDRATE_921600
 *
 * @api
 */
uart_baud_t uart_set_baud(uart_driver_t *udp, uart_baud_t baud);

/**
 * @brief   Configures UART prescaler.
 * @note    This configuration becomes effective after uart_start.
 *
 * @param[out] udp      pointer to a @p uart_driver_t structure
 * @param[in] presc     prescaler to be configured. It can be one of the
 *                      following values:
 *            @arg @ref UART_PRESCALER_DIV1
 *            @arg @ref UART_PRESCALER_DIV2
 *            @arg @ref UART_PRESCALER_DIV4
 *            @arg @ref UART_PRESCALER_DIV6
 *            @arg @ref UART_PRESCALER_DIV8
 *            @arg @ref UART_PRESCALER_DIV10
 *            @arg @ref UART_PRESCALER_DIV12
 *            @arg @ref UART_PRESCALER_DIV16
 *            @arg @ref UART_PRESCALER_DIV32
 *            @arg @ref UART_PRESCALER_DIV64
 *            @arg @ref UART_PRESCALER_DIV128
 *            @arg @ref UART_PRESCALER_DIV256
 * @return              previous prescaler. It can be one of the following
 *                      values:
 *            @arg @ref UART_PRESCALER_DIV1
 *            @arg @ref UART_PRESCALER_DIV2
 *            @arg @ref UART_PRESCALER_DIV4
 *            @arg @ref UART_PRESCALER_DIV6
 *            @arg @ref UART_PRESCALER_DIV8
 *            @arg @ref UART_PRESCALER_DIV10
 *            @arg @ref UART_PRESCALER_DIV12
 *            @arg @ref UART_PRESCALER_DIV16
 *            @arg @ref UART_PRESCALER_DIV32
 *            @arg @ref UART_PRESCALER_DIV64
 *            @arg @ref UART_PRESCALER_DIV128
 *            @arg @ref UART_PRESCALER_DIV256
 *
 * @api
 */
uart_presc_t uart_set_presc(uart_driver_t *udp, uart_presc_t presc);

/**
 * @brief   Configures UART parity.
 * @note    This configuration becomes effective after uart_start.
 *
 * @param[out] udp      pointer to a @p uart_driver_t structure
 * @param[in] parity    parity to be configured. It can be one of the following
 *                      values:
 *            @arg @ref UART_PARITY_NONE
 *            @arg @ref UART_PARITY_EVEN
 *            @arg @ref UART_PARITY_ODD
 * @return              previous parity. It can be one of the following values:
 *            @arg @ref UART_PARITY_NONE
 *            @arg @ref UART_PARITY_EVEN
 *            @arg @ref UART_PARITY_ODD
 *
 * @api
 */
uart_parity_t uart_set_parity(uart_driver_t *udp, uart_parity_t parity);

/**
 * @brief   Configures UART oversampling.
 * @note    This configuration becomes effective after uart_start.
 *
 * @param[out] udp      pointer to a @p uart_driver_t structure
 * @param[in] os        oversampling to be configured. It can be one of the
 *                      following values:
 *            @arg @ref UART_OVERSAMPLING_16
 *            @arg @ref UART_OVERSAMPLING_8
 * @return              previous oversampling. It can be one of the
 *                      following values:
 *            @arg @ref UART_OVERSAMPLING_16
 *            @arg @ref UART_OVERSAMPLING_8
 *
 * @api
 */
uart_over_t uart_set_over(uart_driver_t *udp, uart_over_t os);

/**
 * @brief   Configures UART stop bits.
 * @note    This configuration becomes effective after uart_start.
 *
 * @param[out] udp      pointer to a @p uart_driver_t structure
 * @param[in] sbit      stop bit value to be configured. It can be one of the
 *                      following values:
 *            @arg @ref UART_STOPBIT_1
 *            @arg @ref UART_STOPBIT_0P5
 *            @arg @ref UART_STOPBIT_2
 *            @arg @ref UART_STOPBIT_1P5
 * @return              previous stop bit value. It can be one of the following
 *                      values:
 *            @arg @ref UART_STOPBIT_1
 *            @arg @ref UART_STOPBIT_0P5
 *            @arg @ref UART_STOPBIT_2
 *            @arg @ref UART_STOPBIT_1P5
 *
 * @api
 */
uart_sbit_t uart_set_sbit(uart_driver_t *udp, uart_sbit_t sbit);

/**
 * @brief   Configures UART Synchronous Buffered mode buffer
 * @note    This configuration becomes effective after uart_start.
 *
 * @param[out] udp      pointer to a @p uart_driver_t structure
 * @param[in] sbrx_buf  pointer to the Synchronous Buffered mode buffer
 * @param[in] sbrx_size size of the Synchronous Buffered mode buffer
 *
 * @api
 */
void uart_set_sbrx_buf(uart_driver_t *udp, uint8_t *sbrx_buf, uint32_t sbrx_size);

/**
 * @brief   Configures pointers to UART callback functions.
 *
 * @param[out] udp      pointer to a @p uart_driver_t structure
 * @param[in] cb_op     callback operation type. It can be one of the following
 *                      values:
 *            @arg @ref UART_CB_OPS_TX
 *            @arg @ref UART_CB_OPS_RX
 *            @arg @ref UART_CB_OPS_ERR
 *            @arg @ref UART_CB_OPS_PERR
 *            @arg @ref UART_CB_OPS_MAX
 * @param[in] cb        pointer to UART callback function
 * @return              pointer to previuos UART callback function.
 *
 * @api
 */
uart_cb_t uart_set_cb(uart_driver_t *udp, uart_cb_ops_t cb_op, uart_cb_t cb);

/**
 * @brief   Initializes UART instance.
 *
 * @param[out] udp      pointer to a @p uart_driver_t structure
 *
 * @api
 */
void uart_init(uart_driver_t *udp);

/**
 * @brief   Starts an UART instance.
 *
 * @param[in] udp       pointer to a @p uart_driver_t structure
 *
 * @api
 */
void uart_start(uart_driver_t *udp);

/**
 * @brief   Writes frames via UART.
 *
 * @param[in] udp       pointer to a @p uart_driver_t structure
 * @param[in] data      pointer to the buffer to be written
 * @param[in] len       maximum number of frames to be written
 * @return              The number of frames copied from the buffer.
 *
 * @api
 */
size_t uart_write(uart_driver_t *udp, uint8_t *data, size_t len);

/**
 * @brief   Reads frames from UART.
 *
 * @param[in] udp       pointer to a @p uart_driver_t structure
 * @param[out] data     pointer to the buffer to be read
 * @param[in] len       maximum number of frames to be read
 * @return              The number of frames copied into the buffer.
 *
 * @api
 */
size_t uart_read(uart_driver_t *udp, uint8_t *data, size_t len);

/**
 * @brief   Returns the UART error status.
 *
 * @param[in] udp       pointer to a @p uart_driver_t structure
 * @return              error mask: "0" means no error occurred, otherwise
 *                      bit0=1 means a parity error occurred
 *                      bit1=1 means a framing error occurred
 *                      bit2=1 means an noise detection error occurred
 *                      bit3=1 means an overrun error occurred
 *                      bit4=1 means an underrun error occurred
 *                      bit5=1 means an auto baud rate error occurred.
 *
 * @api
 */
uint32_t uart_get_err_status(uart_driver_t *udp);

/**
 * @brief   Stops an UART instance.
 *
 * @param[in] udp       pointer to a @p uart_driver_t structure
 *
 * @api
 */
void uart_stop(uart_driver_t *udp);

/**
 * @brief   Deinitializes UART instance.
 *
 * @param[out] udp      pointer to a @p uart_driver_t structure
 *
 * @api
 */
void uart_deinit(uart_driver_t *udp);

/**
 * @brief   Shared interrupt handler.
 * @note    Not an API, used internally.
 *
 * @param[in] udp       pointer to a @p uart_driver_t structure
 *
 * @isr
 */
void __uart_serve_interrupt(uart_driver_t *udp);

#ifdef __cplusplus
}
#endif

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/*===========================================================================*/
/* Module late inclusions.                                                   */
/*===========================================================================*/

#endif /* _UART_H_ */

/** @} */
