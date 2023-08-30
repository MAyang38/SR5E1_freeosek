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
 * @file    can.h
 * @brief   CAN driver header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup COMMS
 * @ingroup DRIVERS
 * @addtogroup CAN
 * @ingroup COMMS
 * @{
 */

#ifndef _CAN_H_
#define _CAN_H_

#include <typedefs.h>

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

/**
 * @name    Submodule Shared RAM size.
 * @{
 */
#define CAN_SUB_SRAM_SIZE                   16384U
/** @} */

/**
 * @name    Maximum number of Standard/Extended Filters per Submodule
 * @{
 */
#define CAN_SUB_MAX_STD_FILTERS             128U
#define CAN_SUB_MAX_XTD_FILTERS             64U
/** @} */

/**
 * @name    CANFD maximum data lenght
 * @{
 */
#define CAN_MAX_DATA_LENGTH                 64U
/** @} */

/**
 * @name    Start address bit position in CAN register
 * @{
 */
#define CAN_SA_BIT                          2U
/** @} */

/**
 * @name    FIFO Operation Mode
 * @{
 */
#define CAN_FIFO_BLOCKING_MODE              0U
#define CAN_FIFO_OVERWRITE_MODE             1U
/** @} */

/**
 * @name    FIFO Watermark
 * @{
 */
#define CAN_FIFO_WATERMARK_DISABLED         0U
/** @} */

/**
 * @name    CAN Transmission Modes
 * @note    The parameter msgbuf of the function can_transmit can be a number
 *          in the range [0:31] to transmit using a specific dedicated buffer
 *          or can be:
 *          CAN_TX_ANY_BUFFER to transmit using any dedicated buffer
 *          CAN_TX_FIFO       to transmit using FIFO
 *          CAN_TX_QUEUE      to transmit using Queue
 * @{
 */
#define CAN_TX_ANY_BUFFER                   0xFFU
#define CAN_TX_FIFO                         0xFEU
#define CAN_TX_QUEUE                        0xFDU
/** @} */

/**
 * @name    CAN Reception Modes.
 * @note    The parameter msgbuf of the function can_receive can be a number
 *          in the range [0:31] to receive using a specific dedicated buffer
 *          or can be:
 *          CAN_RX_ANY_BUFFER to receive usign any dedicated buffer
 *          CAN_RX_FIFO0      to receive usign FIFO 0
 *          CAN_RX_FIFO1      to receive usign FIFO 1
 * @{
 */
#define CAN_RX_ANY_BUFFER                   0xFFU
#define CAN_RX_FIFO0                        0xFEU
#define CAN_RX_FIFO1                        0xFDU
/** @} */

/**
 * @name    IRQ enable bit map
 * @{
 */
#define CAN_IRQ_ALL_DISABLED                0UL                                  /**< All interrupts disabled                                */
#define CAN_IRQ_TC_ENABLED                  FDCAN_IE_TCE                         /**< Transmission completed interrupt enable                */
#define CAN_IRQ_TX_FIFO_EMPTY_ENABLED       FDCAN_IE_TFEE                        /**< Transmission FIFO empty interrupt enable               */
#define CAN_IRQ_FIFO0_WATERMARK_ENABLED     FDCAN_IE_RF0WE                       /**< RX FIFO 0 watermark reached interrupt enable           */
#define CAN_IRQ_FIFO0_FULL_ENABLED          FDCAN_IE_RF0FE                       /**< RX FIFO 0 full interrupt enable                        */
#define CAN_IRQ_FIFO0_LOST_ENABLED          FDCAN_IE_RF0LE                       /**< RX FIFO 0 message lost interrupt enable                */
#define CAN_IRQ_FIFO1_WATERMARK_ENABLED     FDCAN_IE_RF1WE                       /**< RX FIFO 1 watermark reached interrupt enable           */
#define CAN_IRQ_FIFO1_FULL_ENABLED          FDCAN_IE_RF1FE                       /**< RX FIFO 1 full interrupt enable                        */
#define CAN_IRQ_FIFO1_LOST_ENABLED          FDCAN_IE_RF1LE                       /**< RX FIFO 1 message lost interrupt enable                */
#define CAN_IRQ_BOE_ENABLED                 FDCAN_IE_BOE                         /**< Bus Off interrupt enable                               */
#define CAN_IRQ_ALL_ENABLED                 (CAN_IRQ_TC_ENABLED              | \
                                             CAN_IRQ_TX_FIFO_EMPTY_ENABLED   | \
                                             CAN_IRQ_FIFO0_WATERMARK_ENABLED | \
                                             CAN_IRQ_FIFO0_FULL_ENABLED      | \
                                             CAN_IRQ_FIFO0_LOST_ENABLED      | \
                                             CAN_IRQ_FIFO1_WATERMARK_ENABLED | \
                                             CAN_IRQ_FIFO1_FULL_ENABLED      | \
                                             CAN_IRQ_FIFO1_LOST_ENABLED      | \
                                             CAN_IRQ_BOE_ENABLED)                /**< All interrupts enabled                                  */
/** @} */

/**
 * @name    IRQ error mask
 * @{
 */
#define CAN_IRQ_ERROR_MASK                  (FDCAN_IE_MRAFE | \
                                             FDCAN_IE_TOOE  | \
                                             FDCAN_IE_BECE  | \
                                             FDCAN_IE_BEUE  | \
                                             FDCAN_IE_ELOE  | \
                                             FDCAN_IE_EPE   | \
                                             FDCAN_IE_EWE   | \
                                             FDCAN_IE_WDIE  | \
                                             FDCAN_IE_PEAE  | \
                                             FDCAN_IE_PEDE  | \
                                             FDCAN_IE_ARAE)
/** @} */

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
 * @brief   Type of a CAN driver.
 */
typedef struct can_driver can_driver_t;

/**
 * @enum can_operation_t
 * CAN operation type.
 */
typedef enum {
    CAN_OPERATION_NORMAL,              /**< CAN standard frame operation */
    CAN_OPERATION_CANFD                /**< CANFD frame operation        */
} can_operation_t;

/**
 * @enum can_frame_type_t
 * CAN frame type.
 */
typedef enum {
    CAN_ID_STD,                        /**< Standard frame */
    CAN_ID_XTD                         /**< Extended frame */
} can_frame_type_t;

/**
 * @brief   Type of a CAN frame.
 */
typedef struct {
    uint16_t         TIME;             /**< Time stamp (Receive path only)     */
    can_operation_t  OPERATION;        /**< Operation type (Standard or CANFD) */
    uint8_t          RTR;              /**< Frame type                         */
    union {
        can_frame_type_t TYPE;         /**< Id type. STD or XTD */
        can_frame_type_t IDE;          /**< Id type. STD or XTD */
    };
    union {
        uint32_t SID;                  /**< Standard identifier */
        uint32_t EID;                  /**< Extended identifier */
        uint32_t ID;                   /**< Identifier          */
    };
    union{
        uint8_t  DLC;                  /**< Data length  */
        uint8_t  LENGTH;               /**< Data length  */
    };
    union {
        uint8_t  data8[CAN_MAX_DATA_LENGTH];     /**< Frame data */
        uint16_t data16[CAN_MAX_DATA_LENGTH/2U]; /**< Frame data */
        uint32_t data32[CAN_MAX_DATA_LENGTH/4U]; /**< Frame data */
        uint64_t data64[CAN_MAX_DATA_LENGTH/8U]; /**< Frame data */
    };
} can_frame_t;

/**
 * @enum can_irq_line_t
 * CAN driver interrupt line configurations.
 */
typedef enum {
    CAN_IRQ_LINE0,                     /**< Inerrupt Line 0 */
    CAN_IRQ_LINE1                      /**< Inerrupt Line 1 */
} can_irq_line_t;

/**
 * @enum can_lb_mode_t
 * CAN loopback mode configurations.
 */
typedef enum {
    CAN_NO_LOOPBACK,                   /**< No loopback            */
    CAN_LOOPBACK_INTERNAL,             /**< Internal loopback mode */
    CAN_LOOPBACK_EXTERNAL              /**< External loopback mode */
} can_lb_mode_t;

/**
 * @enum can_datasize_t
 * CAN data field size configurations.
 */
typedef enum {
    CAN_DATASIZE_8BYTE  = 8U,          /**< Data field size = 8 byte  */
    CAN_DATASIZE_12BYTE = 12U,         /**< Data field size = 12 byte */
    CAN_DATASIZE_16BYTE = 16U,         /**< Data field size = 16 byte */
    CAN_DATASIZE_20BYTE = 20U,         /**< Data field size = 20 byte */
    CAN_DATASIZE_24BYTE = 24U,         /**< Data field size = 24 byte */
    CAN_DATASIZE_32BYTE = 32U,         /**< Data field size = 32 byte */
    CAN_DATASIZE_48BYTE = 48U,         /**< Data field size = 48 byte */
    CAN_DATASIZE_64BYTE = 64U          /**< Data field size = 64 byte */
} can_datasize_t;

/**
 * @enum can_baudrate_t
 * CAN baudrate configurations.
 */
typedef enum {
    CAN_BAUDRATE_1MBIT   = 1000000U,   /**< Baudrate = 1   Mbits per second */
    CAN_BAUDRATE_2MBIT   = 2000000U,   /**< Baudrate = 2   Mbits per second */
    CAN_BAUDRATE_2_5MBIT = 2500000U,   /**< Baudrate = 2.5 Mbits per second */
    CAN_BAUDRATE_4MBIT   = 4000000U,   /**< Baudrate = 4   Mbits per second */
    CAN_BAUDRATE_5MBIT   = 5000000U,   /**< Baudrate = 5   Mbits per second */
    CAN_BAUDRATE_8MBIT   = 8000000U    /**< Baudrate = 8   Mbits per second */
} can_baudrate_t;

/**
 * @brief   CAN nominal bit timing and prescaler configuration.
 */
typedef struct {
    /**
     * @brief   Baud rate prescaler.
     */
    uint16_t            nbrp;
    /**
     * @brief   Time segment before sample point.
     */
    uint8_t             ntseg1;
    /**
     * @brief   Time segment after the sample point.
     */
    uint8_t             ntseg2;
    /**
     * @brief   Synchronization jump width.
     */
    uint8_t             nsjw;
} can_nbtp_t;

/**
 * @brief   CAN data bit timing and prescaler configuration.
 */
typedef struct {
    /**
     * @brief   Data baud rate prescaler.
     */
    uint8_t             dbrp;
    /**
     * @brief   Data time segment before sample point.
     */
    uint8_t             dtseg1;
    /**
     * @brief   Data time segment after sample point.
     */
    uint8_t             dtseg2;
    /**
     * @brief   Data synchronization jump width.
     */
    uint8_t             dsjw;
} can_dbtp_t;

/**
 * @brief   Transceiver delay compensation configuration.
 */
typedef struct {
    /**
     * @brief   Transceiver delay compensation enable status.
     */
    bool                is_tdc_en;
    /**
     * @brief   Transmitter delay compensation SSP offset.
     */
    uint8_t             tdco;
    /**
     * @brief   Transmitter delay compensation filter window length.
     */
    uint8_t             tdcf;
} can_tdc_t;

/**
 * @enum can_filter_type_t
 * CAN Standard/Extended filter configurations.
 */
typedef enum {
    CAN_FILTER_RANGE,                  /**< Range Filter Type   */
    CAN_FILTER_DUALID,                 /**< Dual ID Filter Type */
    CAN_FILTER_CLASSIC                 /**< Classic Filter Type */
} can_filter_type_t;

/**
 * @enum can_fec_type_t
 * CAN Standard/Extended filter element configurations.
 *
 */
typedef enum {
    CAN_FEC_DIS,                       /**< Disable filter element                                              */
    CAN_FEC_FIFO0,                     /**< Store in Rx FIFO 0 if filter matches                                */
    CAN_FEC_FIFO1,                     /**< Store in Rx FIFO 1 if filter matches                                */
    CAN_FEC_REJ_ONMATCH,               /**< Reject ID if filter matches                                         */
    CAN_FEC_PRIO_ONMATCH,              /**< Set priority if filter matches                                      */
    CAN_FEC_PRIO_FIFO0,                /**< Set priority and store in FIFO 0 if filter matches                  */
    CAN_FEC_PRIO_FIFO1,                /**< Set priority and store in FIFO 1 if filter matches                  */
    CAN_FEC_RX_BUF                     /**< Store into Rx Buffer or as debug message, configuration of SFT[1:0] */
} can_fec_type_t;

/**
 * @brief   CAN standard  buffer filter.
 */
typedef struct {
    /**
     * @brief   Filter value 1.
     */
    uint32_t            FID1;
    /**
     * @brief   Filter value 2.
     */
    uint32_t            FID2;
    /**
     * @brief   Standard filter type.
     */
    can_filter_type_t   FT;
    /**
     * @brief   Filter element configuration.
     */
    can_fec_type_t      FEC;
} can_filter_t;

/**
 * @enum can_msg_filter_type_t
 * Standard/Extended MessageID filter type.
 *
 */
typedef enum {
    CAN_STD_FILTER_TYPE,               /**< Standard filter type */
    CAN_XTD_FILTER_TYPE                /**< Extended filter type */
} can_msg_filter_type_t;

/**
 * @enum can_tx_mode_t
 * CAN transmission mode configurations.
 */
typedef enum {
    CAN_TX_MODE_DEDICATED_BUFF,        /**< Transmission mode = Dedicated TX Buffer            */
    CAN_TX_MODE_FIFO,                  /**< Transmission mode = TX FIFO                        */
    CAN_TX_MODE_QUEUE,                 /**< Transmission mode = TX Queue                       */
    CAN_TX_MODE_MIXED_FIFO,            /**< Transmission mode = Dedicated TX Buffer + TX FIFO  */
    CAN_TX_MODE_MIXED_QUEUE            /**< Transmission mode = Dedicated TX Buffer + TX Queue */
} can_tx_mode_t;

/**
 * @enum can_rx_mode_t
 * CAN reception mode configurations.
 */
typedef enum {
    CAN_RX_MODE_DEDICATED_BUFF,        /**< Reception mode = Dedicated RX Buffer */
    CAN_RX_MODE_FIFO0,                 /**< Reception mode = RX FIFO 0           */
    CAN_RX_MODE_FIFO1                  /**< Reception mode = RX FIFO 1           */
} can_rx_mode_t;

/**
 * @brief   Type of CAN DMA configuration.
 */
typedef struct {
    /**
     * @brief   CAN TX DMA stream to be used for TX FIFO/QUEUE operations.
     */
    uint32_t                 dma_stream_tx_id;
    /**
     * @brief   CAN RX DMA stream to be used for RX FIFO0 operations.
     */
    uint32_t                 dma_stream_rx0_id;
    /**
     * @brief   CAN RX DMA stream to be used for RX FIFO1 operations.
     */
    uint32_t                 dma_stream_rx1_id;
    /**
     * @brief   CAN DMA stream bus priority (3..0).
     */
    uint32_t                 dma_stream_bus_prio;
    /**
     * @brief   CAN DMA stream IRQ priority (3..15).
     */
    uint32_t                 dma_stream_irq_prio;
} can_dma_conf_t;

/**
 * @enum can_evt_t
 * CAN supported event callbacks.
 */
typedef enum {
    CAN_CB_RX,                         /**< Message stored to dedicated RX buffer event callback */
    CAN_CB_TX,                         /**< Transmission completed event callback                */
    CAN_CB_TX_FIFO_EMPTY,              /**< TX FIFO empty event callback                         */
    CAN_CB_FIFO0_NEW_MSG,              /**< RX FIFO 0 new message event callback                 */
    CAN_CB_FIFO0_WATERMARK,            /**< RX FIFO 0 watermark reached event callback           */
    CAN_CB_FIFO0_FULL,                 /**< RX FIFO 0 full event callback                        */
    CAN_CB_FIFO0_LOST,                 /**< RX FIFO 0 message lost event callback                */
    CAN_CB_FIFO1_NEW_MSG,              /**< RX FIFO 1 new message event callback                 */
    CAN_CB_FIFO1_WATERMARK,            /**< RX FIFO 1 watermark reached event callback           */
    CAN_CB_FIFO1_FULL,                 /**< RX FIFO 1 full event callback                        */
    CAN_CB_FIFO1_LOST,                 /**< RX FIFO 1 message lost event callback                */
    CAN_CB_DMU_RX0,                    /**< DMU RX0 element successfully dequeued event callback */
    CAN_CB_DMU_RX1,                    /**< DMU RX1 element successfully dequeued event callback */
    CAN_CB_DMU_TX                      /**< DMU TX  element successfully enqueued event callback */
} can_evt_t;

/**
 * @enum can_dmu_evt_t
 * CAN supported DMU event callbacks.
 */
typedef enum {
    CAN_DMU_CB_DMU_RX0,                /**< DMU RX0 element successfully dequeued event callback */
    CAN_DMU_CB_DMU_RX1,                /**< DMU RX1 element successfully dequeued event callback */
    CAN_DMU_CB_DMU_TX                  /**< DMU TX element successfully enqueued event callback  */
} can_dmu_evt_t;

/**
 * @brief   Type of an CAN notification callback.
 * @note    If a new frame is received and RX polling mode is disabled, the
 *          received frame is returned via frame parameter of the callback,
 *          otherwise frame parameter is don't care.
 *
 * @param[in] cdp       pointer to the @p can_driver_t object
 * @param[in] event     callback event. It can be one of the following values:
 *            @arg @ref CAN_CB_RX
 *            @arg @ref CAN_CB_TX
 *            @arg @ref CAN_CB_TX_FIFO_EMPTY
 *            @arg @ref CAN_CB_FIFO0_NEW_MSG
 *            @arg @ref CAN_CB_FIFO0_WATERMARK
 *            @arg @ref CAN_CB_FIFO0_FULL
 *            @arg @ref CAN_CB_FIFO0_LOST
 *            @arg @ref CAN_CB_FIFO1_NEW_MSG
 *            @arg @ref CAN_CB_FIFO1_WATERMARK
 *            @arg @ref CAN_CB_FIFO1_FULL
 *            @arg @ref CAN_CB_FIFO1_LOST
 *            @arg @ref CAN_CB_DMU_RX0
 *            @arg @ref CAN_CB_DMU_RX1
 *            @arg @ref CAN_CB_DMU_TX
 */
typedef void (*can_cb_t)(can_driver_t *cdp, can_frame_t frame, can_evt_t event);

/**
 * @brief   Type of an CAN error notification callback.
 *
 * @param[in] cdp       pointer to the @p can_driver_t object
 * @param[in] psr       Protocol Status Register value
 */
typedef void (*can_err_cb_t)(can_driver_t *cdp, uint32_t psr);

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

/* Export driver modules.*/
#include <can_instances.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Initializes a CAN instance.
 *
 * @param[out] cdp      pointer to a @p can_driver_t structure
 *
 * @api
 */
void can_init(can_driver_t *cdp);

/**
 * @brief   Configures CAN interrupt priority.
 * @note    This configuration becomes effective after can_start.
 *
 * @param[out] cdp      pointer to a @p can_driver_t structure
 * @param[in] prio      interrupt priority to be configured
 * @return              previous interrupt priority.
 *
 * @api
 */
uint32_t can_set_prio(can_driver_t *cdp, uint32_t prio);

/**
 * @brief   Configures interrupt line.
 * @note    This configuration becomes effective after can_start.
 *
 * @param[out] cdp      pointer to a @p can_driver_t structure
 * @param[in] irq_line  interrupt line to be configured. It can be one of the
 *                      following values:
 *            @arg @ref CAN_IRQ_LINE0
 *            @arg @ref CAN_IRQ_LINE1
 * @return              previous interrupt line. It can be one of the following
 *                      values:
 *            @arg @ref CAN_IRQ_LINE0
 *            @arg @ref CAN_IRQ_LINE1
 *
 * @api
 */
can_irq_line_t can_set_irq_line(can_driver_t *cdp, can_irq_line_t irq_line);

/**
 * @brief   Configures interrupt mask.
 * @note    This configuration becomes effective after can_start.
 * @note    Interrupt mask is a mask that specifies the interrupt enabled.
 *
 * @param[out] cdp      pointer to a @p can_driver_t structure
 * @param[in] irq_mask  interrupt mask to be configured. It can be one of the
 *                      following values:
 *            @arg @ref CAN_IRQ_ALL_DISABLED
 *            @arg @ref CAN_IRQ_ALL_ENABLED
 *                      or a combination (OR) of the following values:
 *            @arg @ref CAN_IRQ_TC_ENABLED
 *            @arg @ref CAN_IRQ_TX_FIFO_EMPTY_ENABLED
 *            @arg @ref CAN_IRQ_FIFO0_WATERMARK_ENABLED
 *            @arg @ref CAN_IRQ_FIFO0_FULL_ENABLED
 *            @arg @ref CAN_IRQ_FIFO0_LOST_ENABLED
 *            @arg @ref CAN_IRQ_FIFO1_WATERMARK_ENABLED
 *            @arg @ref CAN_IRQ_FIFO1_FULL_ENABLED 
 *            @arg @ref CAN_IRQ_FIFO1_LOST_ENABLED 
 *            @arg @ref CAN_IRQ_BOE_ENABLED
 * @return              previous interrupt mask. It can be one of the following
 *                      values:
 *            @arg @ref CAN_IRQ_ALL_DISABLED
 *            @arg @ref CAN_IRQ_ALL_ENABLED
 *                      or a combination (OR) of the following values:
 *            @arg @ref CAN_IRQ_TC_ENABLED
 *            @arg @ref CAN_IRQ_TX_FIFO_EMPTY_ENABLED
 *            @arg @ref CAN_IRQ_FIFO0_WATERMARK_ENABLED
 *            @arg @ref CAN_IRQ_FIFO0_FULL_ENABLED
 *            @arg @ref CAN_IRQ_FIFO0_LOST_ENABLED
 *            @arg @ref CAN_IRQ_FIFO1_WATERMARK_ENABLED
 *            @arg @ref CAN_IRQ_FIFO1_FULL_ENABLED 
 *            @arg @ref CAN_IRQ_FIFO1_LOST_ENABLED 
 *            @arg @ref CAN_IRQ_BOE_ENABLED
 *
 * @api
 */
uint32_t can_set_irq_mask(can_driver_t *cdp, uint32_t irq_mask);

/**
 * @brief   Configures internal shared RAM memory.
 * @note    This configuration becomes effective after can_start.
 *
 * @param[out] cdp      pointer to a @p can_driver_t structure
 * @param[in] ram_start shared RAM start address
 * @param[in] ram_size  shared RAM size
 *
 * @api
 */
void can_set_ram(can_driver_t *cdp, uint32_t ram_start, uint32_t ram_size);

/**
 * @brief   Configures loopback mode.
 * @note    This configuration becomes effective after can_start.
 *
 * @param[out] cdp      pointer to a @p can_driver_t structure
 * @param[in] lb_mode   loopback mode to be configured. It can be one of the
 *                      following values:
 *            @arg @ref CAN_NO_LOOPBACK
 *            @arg @ref CAN_LOOPBACK_INTERNAL
 *            @arg @ref CAN_LOOPBACK_EXTERNAL
 * @return              previous loopback mode. It can be one of the following
 *                      values:
 *            @arg @ref CAN_NO_LOOPBACK
 *            @arg @ref CAN_LOOPBACK_INTERNAL
 *            @arg @ref CAN_LOOPBACK_EXTERNAL
 *
 * @api
 */
can_lb_mode_t can_set_loopback(can_driver_t *cdp, can_lb_mode_t lb_mode);

/**
 * @brief   Enables/Disables CAN FD mode.
 * @note    This configuration becomes effective after can_start.
 *
 * @param[out] cdp       pointer to a @p can_driver_t structure
 * @param[in] is_fd_mode CAN FD mode to be configured (true to enable FD mode,
 *                       false to disable FD mode).
 * @return               previous CAN FD mode status.
 *
 * @api
 */
bool can_set_fd_mode(can_driver_t *cdp, bool is_fd_mode);

/**
 * @brief   Enables/Disables CAN FD bit rate switch.
 * @note    This configuration becomes effective after can_start.
 *
 * @param[out] cdp           pointer to a @p can_driver_t structure
 * @param[in] is_fd_brs_mode CAN FD bit rate switch to be configured (true to
 *                           enable FD bit rate switch, false to disable FD bit
 *                           rate switch).
 * @return                   previous CAN FD bit rate switch status.
 *
 * @api
 */
bool can_set_fd_brs_mode(can_driver_t *cdp, bool is_fd_brs_mode);

/**
 * @brief   Configures CAN baudrate.
 * @note    This configuration becomes effective after can_start.
 * @note    This function must be invoked after the selection of FD mode
 *          through the function can_set_fd_mode.
 * @note    This function configures HW according to the clock settings and the
 *          desired baudrate addressing most common configurations. If a fine
 *          tuning of baudrate parameters is required, the APIs can_set_nbtp,
 *          can_set_dbtp, can_enable_tdc, can_set_tdc can be used.
 *
 * @param[out] cdp      pointer to a @p can_driver_t structure
 * @param[in] baudrate  CAN baudrate to be configured. It can be one of the
 *                      following values:
 *            @arg @ref CAN_SPEED_1MBIT
 *            @arg @ref CAN_SPEED_2MBIT
 *            @arg @ref CAN_SPEED_2_5MBIT
 *            @arg @ref CAN_SPEED_4MBIT
 *            @arg @ref CAN_SPEED_5MBIT
 *            @arg @ref CAN_SPEED_8MBIT
 * @return              operation status (true if the baudrate is correctly
 *                      initialized, false otherwise).
 *
 * @api
 */
bool can_set_baudrate(can_driver_t *cdp, can_baudrate_t baudrate);

/**
 * @brief   Configures CAN nominal bit timing and prescaler.
 * @note    This configuration becomes effective after can_start.
 *
 * @param[out] cdp      pointer to a @p can_driver_t structure
 * @param[in] nbrp      baud rate prescaler to be configured. It can be in the
 *                      range [0:511]
 * @param[in] ntseg1    time segment before sample point to be configured. It
 *                      can be in the range [1:255]
 * @param[in] ntseg2    time segment after the sample point to be configured.
 *                      It can be in the range [1:127]
 * @param[in] nsjw      synchronization jump width to be configured. It can be
 *                      in the range [0:127]
 *
 * @api
 */
void can_set_nbtp(can_driver_t *cdp, uint16_t nbrp, uint8_t ntseg1,
                  uint8_t ntseg2, uint8_t nsjw);

/**
 * @brief   Configures CAN data bit timing and prescaler (only for CAN-FD).
 * @note    This configuration becomes effective after can_start.
 *
 * @param[out] cdp      pointer to a @p can_driver_t structure
 * @param[in] dbrp      data baud rate prescaler to be configured. It can be in
 *                      the range [0:31]
 * @param[in] dtseg1    data time segment before sample point to be configured.
 *                      It can be in the range [0:31]
 * @param[in] dtseg2    data time segment after the sample point to be
 *                      configured. It can be in the range [0:15]
 * @param[in] dsjw      data synchronization jump width to be configured. It
 *                      can be in the range [0:5]
 *
 * @api
 */
void can_set_dbtp(can_driver_t *cdp, uint8_t dbrp, uint8_t dtseg1,
                  uint8_t dtseg2, uint8_t dsjw);

/**
 * @brief   Enables/Disables CAN transceiver delay compensation (only for
 *          CAN-FD).
 * @note    This configuration becomes effective after can_start.
 *
 * @param[out] cdp      pointer to a @p can_driver_t structure
 * @param[in] enable    transceiver delay compensation enable status ("true"
 *                      means delay compensation is enabled, "false" otherwise)
 * @return              previuos transceiver delay compensation enable status.
 *
 * @api
 */
bool can_enable_tdc(can_driver_t *cdp, bool enable);

/**
 * @brief   Configures CAN transceiver delay compensation (only for CAN-FD).
 * @note    This configuration becomes effective after can_start.
 *
 * @param[out] cdp      pointer to a @p can_driver_t structure
 * @param[in] tdco      transmitter delay compensation SSP offset to be
 *                      configured. It can be in the range [0:127]
 * @param[in] tdcf      transmitter delay compensation filter window length to
 *                      be configured. It can be in the range [0:127]
 *
 * @api
 */
void can_set_tdc(can_driver_t *cdp, uint8_t tdco, uint8_t tdcf);

/**
 * @brief   Configures CAN data field size [byte].
 * @note    This configuration becomes effective after can_start.
 *
 * @param[out] cdp      pointer to a @p can_driver_t structure
 * @param[in] datasize  data size to be configured. It can be one of the
 *                      following values:
 *            @arg @ref CAN_DATASIZE_8BYTE
 *            @arg @ref CAN_DATASIZE_12BYTE
 *            @arg @ref CAN_DATASIZE_16BYTE
 *            @arg @ref CAN_DATASIZE_20BYTE
 *            @arg @ref CAN_DATASIZE_24BYTE
 *            @arg @ref CAN_DATASIZE_32BYTE
 *            @arg @ref CAN_DATASIZE_48BYTE
 *            @arg @ref CAN_DATASIZE_64BYTE
 * @return              previous data size. It can be one of the following
 *                      values:
 *            @arg @ref CAN_DATASIZE_8BYTE
 *            @arg @ref CAN_DATASIZE_12BYTE
 *            @arg @ref CAN_DATASIZE_16BYTE
 *            @arg @ref CAN_DATASIZE_20BYTE
 *            @arg @ref CAN_DATASIZE_24BYTE
 *            @arg @ref CAN_DATASIZE_32BYTE
 *            @arg @ref CAN_DATASIZE_48BYTE
 *            @arg @ref CAN_DATASIZE_64BYTE
 *
 * @api
 */
can_datasize_t can_set_datasize(can_driver_t *cdp, can_datasize_t datasize);

/**
 * @brief   Adds a filter (standard or extended).
 * @note    This configuration becomes effective after can_start.
 *
 * @param[out] cdp            pointer to a @p can_driver_t structure
 * @param[in] id1             filter ID1
 * @param[in] id2             filter ID2 or ID1 mask
 * @param[in] msg_filter_type Standard/Extended MessageID filter type. It can
 *                            be one of the following values:
 *            @arg @ref CAN_STD_FILTER_TYPE
 *            @arg @ref CAN_XTD_FILTER_TYPE
 * @param[in] filter_type     Standard/Extended filter type. It can be one of
 *                            the following values:
 *            @arg @ref CAN_FILTER_RANGE
 *            @arg @ref CAN_FILTER_DUALID
 *            @arg @ref CAN_FILTER_CLASSIC
 * @param[in] fec_type        Standard/Extended filter element type. It can be
 *                            one of the following values:
 *            @arg @ref CAN_FEC_DIS
 *            @arg @ref CAN_FEC_FIFO0
 *            @arg @ref CAN_FEC_FIFO1
 *            @arg @ref CAN_FEC_REJ_ONMATCH
 *            @arg @ref CAN_FEC_PRIO_ONMATCH
 *            @arg @ref CAN_FEC_PRIO_FIFO0
 *            @arg @ref CAN_FEC_PRIO_FIFO1
 *            @arg @ref CAN_FEC_RX_BUF
 * @return                    operation status (true if the filter is correctly
 *                            set, false otherwise).
 *
 * @api
 */
bool can_set_filter(can_driver_t *cdp, uint32_t id1, uint32_t id2,
                    can_msg_filter_type_t msg_filter_type,
                    can_filter_type_t filter_type, can_fec_type_t fec_type);

/**
 * @brief   Configures CAN buffers.
 * @note    This configuration becomes effective after can_start.
 *
 * @param[out] cdp         pointer to a @p can_driver_t structure
 * @param[in] rx_buff_num  number of dedicated RX buffers [0:63]
 * @param[in] tx_buff_num  number of dedicated TX buffers [0:31]
 * @param[in] rx_fifo0_num number of RX buffers in RX FIFO 0 [0:63]
 * @param[in] rx_fifo1_num number of RX buffers in RX FIFO 1 [0:63]
 * @param[in] tx_fifoq_num number of TX buffers in TX FIFO/Queue [0:31]
 *
 * @api
 */
void can_set_buffers(can_driver_t *cdp, uint8_t rx_buff_num,
                     uint8_t tx_buff_num, uint8_t rx_fifo0_num,
                     uint8_t rx_fifo1_num, uint8_t tx_fifoq_num);

/**
 * @brief   Enables/Disables CAN read polling mode.
 * @note    This configuration becomes effective after can_start.
 * @note    If DMU is disabled, the polling mode specifies how the received
 *          frames are read. In particular, if polling mode is disabled, the
 *          received frames are read in the interrupt handler and returned as
 *          parameter of related callback functions, otherwise, they must be
 *          read invoking a dedicated API (can_receive). 
 *          If DMU is enabled, the frames received via RX FIFO 0 and RX FIFO 1
 *          are read in the DMU interrupt handler and returned as parameter of
 *          the related callback funcion, while the frames received via
 *          dedicated buffers are read via interrupt handler or via dedicated
 *          API based on the value of polling mode. 
 *
 * @param[out] cdp               pointer to a @p can_driver_t structure
 * @param[in] is_rx_polling_mode read polling mode to be configured (true to
 *                               enable read polling mode, false to disable
 *                               read polling mode).
 * @return                       previuos read polling mode status.
 *
 * @api
 */
bool can_set_rx_polling_mode(can_driver_t *cdp, bool is_rx_polling_mode);

/**
 * @brief   Configures transmission mode.
 * @note    This configuration becomes effective after can_start.
 *
 * @param[out] cdp      pointer to a @p can_driver_t structure
 * @param[in] tx_mode   transmission mode to be configured. It can be one of
 *                      the following values:
 *            @arg @ref CAN_TX_MODE_DEDICATED_BUFF
 *            @arg @ref CAN_TX_MODE_FIFO
 *            @arg @ref CAN_TX_MODE_QUEUE
 *            @arg @ref CAN_TX_MODE_MIXED_FIFO
 *            @arg @ref CAN_TX_MODE_MIXED_QUEUE
 * @return              previous transmission mode. It can be one of the
 *                      following values:
 *            @arg @ref CAN_TX_MODE_DEDICATED_BUFF
 *            @arg @ref CAN_TX_MODE_FIFO
 *            @arg @ref CAN_TX_MODE_QUEUE
 *            @arg @ref CAN_TX_MODE_MIXED_FIFO
 *            @arg @ref CAN_TX_MODE_MIXED_QUEUE
 *
 * @api
 */
can_tx_mode_t can_set_tx_mode(can_driver_t *cdp, can_tx_mode_t tx_mode);

/**
 * @brief   Enables/Disables DMU mode.
 * @note    This configuration becomes effective after can_start.
 * @note    The DMU allows to transmit/receive only frames with a frame size of
 *          4 words (data size = 8bytes) For all other frames size, the DMU
 *          cannot be used and must be keept disabled.
 * @note    If DMU is disabled, the polling mode specifies how the received
 *          frames are read. In particular, if polling mode is disabled, the
 *          received frames are read in the interrupt handler and returned as
 *          parameter of related callback functions, otherwise, they must be
 *          read invoking a dedicated API (can_receive). 
 *          If DMU is enabled, the frames received via RX FIFO 0 and RX FIFO 1
 *          are read in the DMU interrupt handler and returned as parameter of
 *          the related callback funcion, while the frames received via
 *          dedicated buffers are read via interrupt handler or via dedicated
 *          API based on the value of polling mode. 
 *
 * @param[out] cdp        pointer to a @p can_driver_t structure
 * @param[in] is_dmu_mode DMU mode to be configured (true to enable DMU, false
 *                        to disable DMU).
 * @return                previous DMU mode status.
 *
 * @api
 */
bool can_set_dmu_mode(can_driver_t *cdp, bool is_dmu_mode);

/**
 * @brief   Configures CAN DMA configuration.
 * @note    This configuration becomes effective after can_start.
 *
 * @param[out] cdp      pointer to a @p can_driver_t structure
 * @param[in] dma_conf  pointer to DMA configuration to be configured
 * @return              pointer to previous DMA configuration.
 *
 * @api
 */
can_dma_conf_t *can_set_dma_conf(can_driver_t *cdp, can_dma_conf_t *dma_conf);

/**
 * @brief   Configures interrupt callback.
 * @note    This configuration becomes effective after can_start.
 *
 * @param[out] cdp      pointer to a @p can_driver_t structure
 * @param[in] cb        pointer to the callback function.
 * @return              pointer to the previous callback function.
 *
 * @api
 */
can_cb_t can_set_cb(can_driver_t *cdp, can_cb_t cb);

/**
 * @brief   Configures error interrupt callback.
 * @note    This configuration becomes effective after can_start.
 *
 * @param[out] cdp      pointer to a @p can_driver_t structure
 * @param[in] err_cb    pointer to the error callback function.
 * @return              pointer to the previous error callback function.
 *
 * @api
 */
can_err_cb_t can_set_err_cb(can_driver_t *cdp, can_err_cb_t err_cb);

/**
 * @brief   Starts a CAN instance.
 *
 * @param[in] cdp       pointer to a @p can_driver_t structure
 *
 * @api
 */
void can_start(can_driver_t *cdp);

/**
 * @brief   Transmits a CAN frame.
 *
 * @param[in] cdp       pointer to a @p can_driver_t structure
 * @param[in] msgbuf    It can be a number X in the range [0:31] to transmit
 *                      via the dedicated buffer X, or one of the following
 *                      values:
 *            @arg @ref CAN_TX_ANY_BUFFER to transmit via any dedicated buffer
 *            @arg @ref CAN_TX_FIFO       to transmit via FIFO
 *            @arg @ref CAN_TX_QUEUE      to transmit via Queue
 * @param[in] frame     pointer to frame to be transmitted
 * @return              operation status (true if the frame is correctly
 *                      transmitted, false otherwise).
 *
 * @api
 */
bool can_transmit(can_driver_t *cdp, uint8_t msgbuf, can_frame_t *frame);

/**
 * @brief   Receives a CAN frame.
 * @note    If DMU is disabled, this API can be used to read a specific frame
 *          when the polling mode is enabled.
 *          If DMU is enabled, this API can be used to read the only frames
 *          received via dedicated buffers when the polling mode is enabled.
 *
 * @param[in] cdp       pointer to a @p can_driver_t structure
 * @param[in] msgbuf    It can be a number X in the range [0:31] to receive
 *                      via the dedicated buffer X, or one of the following
 *                      values:
 *            @arg @ref CAN_RX_ANY_BUFFER to receive via any dedicated buffer
 *            @arg @ref CAN_RX_FIFO0      to receive via FIFO 0
 *            @arg @ref CAN_RX_FIFO1      to receive via FIFO 1
 * @param[in] frame     pointer to frame to be received
 * @return              operation status (true if the frame is correctly
 *                      received, false otherwise).
 *
 * @api
 */
bool can_receive(can_driver_t *cdp, uint8_t msgbuf, can_frame_t *frame);

/**
 * @brief   Returns CAN bus off.
 *
 * @param[in] cdp       pointer to an @p can_driver_t structure
 * @return              CAN bus off status ("true" means a bus off occurred, 
 *                      "false" otherwise).
 *
 * @api
 */
bool can_get_bo_status(can_driver_t *cdp);

/**
 * @brief   Returns CAN version.
 *
 * @param[in] cdp       pointer to an @p can_driver_t structure
 * @return              CAN version.
 *
 * @api
 */
uint16_t can_get_version(can_driver_t *cdp);

/**
 * @brief   Stops a CAN instance.
 *
 * @param[in] cdp       pointer to an @p can_driver_t structure
 *
 * @api
 */
void can_stop(can_driver_t *cdp);

/**
 * @brief   Deinitializes a CAN instance.
 *
 * @param[out] cdp      pointer to a @p can_driver_t structure
 *
 * @api
 */
void can_deinit(can_driver_t *cdp);

/**
 * @brief   Serves a Line0/Line1 CAN interrupt.
 * @note    Not an API, used internally.
 *
 * @param[in] cdp       pointer to an @p can_driver_t structure
 * @param[in] irq_line  interrupt line
 *
 * @isr
 */
void __can_serve_interrupt(can_driver_t *cdp, can_irq_line_t irq_line);

/**
 * @brief   Serves a DMU CAN interrupt.
 * @note    Not an API, used internally.
 *
 * @param[in] cdp       pointer to an @p can_driver_t structure
 *
 * @isr
 */
void __can_serve_dmu_interrupt(can_driver_t *cdp);

#ifdef __cplusplus
}
#endif

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/*===========================================================================*/
/* Module late inclusions.                                                   */
/*===========================================================================*/

#endif /* _CAN_H_ */

/** @} */
