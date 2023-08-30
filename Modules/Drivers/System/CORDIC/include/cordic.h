/****************************************************************************
 *
 * Copyright (c) 2023 STMicroelectronics - All Rights Reserved
 *
 * License terms: STMicroelectronics Proprietary in accordance with licensing
 * terms SLA0098 at www.st.com.
 *
 * THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
 * INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *****************************************************************************/
/**
 * @file    cordic.h
 * @brief   CORDIC driver header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup SYSTEM
 * @ingroup DRIVERS
 * @addtogroup CORDIC
 * @ingroup SYSTEM
 * @{
 */

#ifndef _CORDIC_H_
#define _CORDIC_H_

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
 * @brief   Type of an CORDIC driver.
 */
typedef struct cordic_driver cordic_driver_t;

/**
 * @enum cordic_sts_t
 * CORDIC calculation progress status.
 */
typedef enum {
    CORDIC_READY = 0U,       /**< Calculation status ready */
    CORDIC_BUSY  = 1U,       /**< Calculation status busy  */
} cordic_sts_t;

/**
 * @enum cordic_drv_mode_t
 * CORDIC driver mode configuration.
 */
typedef enum {
    CORDIC_DRV_MODE_POLLING_SYNC,      /**< Polling mode                */
    CORDIC_DRV_MODE_INT_SYNC,          /**< Synchronous interrupt mode  */
    CORDIC_DRV_MODE_INT_ASYNC,         /**< Asynchronous interrupt mode */
    CORDIC_DRV_MODE_DMA_SYNC,          /**< Synchronous DMA mode        */
    CORDIC_DRV_MODE_DMA_ASYNC,         /**< Asynchronous DMA mode       */
} cordic_drv_mode_t;

/**
 * @enum cordic_func_t
 * CORDIC supported functions.
 */
typedef enum {
    CORDIC_FUNC_COSINE = 0U,           /**< Cosine            */
    CORDIC_FUNC_SINE = 1U,             /**< Sine              */
    CORDIC_FUNC_PHASE = 2U,            /**< Phase             */
    CORDIC_FUNC_MODULUS = 3U,          /**< Modulus           */
    CORDIC_FUNC_ARCTANGENT = 4U,       /**< Arctangent        */
    CORDIC_FUNC_HYP_COSINE = 5U,       /**< Hyperbolic cosine */
    CORDIC_FUNC_HYP_SINE = 6U,         /**< Hyperbolic sine   */
    CORDIC_FUNC_ARCTANH = 7U,          /**< Arctanh           */
    CORDIC_FUNC_NAT_LOG = 8U,          /**< Natural logarithm */
    CORDIC_FUNC_SQUARE_ROOT = 9U       /**< Square Root       */
} cordic_func_t;

/**
 * @enum cordic_prec_t
 * CORDIC supported precisions.
 */
typedef enum {
    CORDIC_PREC_1CYCLE = 1U,           /**< Precision = 1  cycle  */
    CORDIC_PREC_2CYCLES = 2U,          /**< Precision = 2  cycles */
    CORDIC_PREC_3CYCLES = 3U,          /**< Precision = 3  cycles */
    CORDIC_PREC_4CYCLES = 4U,          /**< Precision = 4  cycles */
    CORDIC_PREC_5CYCLES = 5U,          /**< Precision = 5  cycles */
    CORDIC_PREC_6CYCLES = 6U,          /**< Precision = 6  cycles */
    CORDIC_PREC_7CYCLES = 7U,          /**< Precision = 7  cycles */
    CORDIC_PREC_8CYCLES = 8U,          /**< Precision = 8  cycles */
    CORDIC_PREC_9CYCLES = 9U,          /**< Precision = 9  cycles */
    CORDIC_PREC_10CYCLES = 10U,        /**< Precision = 10 cycles */
    CORDIC_PREC_11CYCLES = 11U,        /**< Precision = 11 cycles */
    CORDIC_PREC_12CYCLES = 12U,        /**< Precision = 12 cycles */
    CORDIC_PREC_13CYCLES = 13U,        /**< Precision = 13 cycles */
    CORDIC_PREC_14CYCLES = 14U,        /**< Precision = 14 cycles */
    CORDIC_PREC_15CYCLES = 15U         /**< Precision = 15 cycles */
} cordic_prec_t;

/**
 * @enum cordic_scale_t
 * CORDIC supported scale factors.
 */
typedef enum {
    CORDIC_SCALE_0,          /**< Scale factor = 0 */
    CORDIC_SCALE_1,          /**< Scale factor = 1 */
    CORDIC_SCALE_2,          /**< Scale factor = 2 */
    CORDIC_SCALE_3,          /**< Scale factor = 3 */
    CORDIC_SCALE_4,          /**< Scale factor = 4 */
    CORDIC_SCALE_5,          /**< Scale factor = 5 */
    CORDIC_SCALE_6,          /**< Scale factor = 6 */
    CORDIC_SCALE_7           /**< Scale factor = 7 */
} cordic_scale_t;

/**
 * @enum cordic_num_t
 * CORDIC supported numbers of arguments/results.
 */
typedef enum {
    CORDIC_NUM_1_32BIT_OR_2_16BIT = 0U,     /**< One 32-bit argument/result or two 16-bit arguments/results */
    CORDIC_NUM_2_32BIT = 1U,                /**< Two 32-bit arguments/results                               */
} cordic_num_t;

/**
 * @enum cordic_width_t
 * CORDIC supported arguments/result widths.
 */
typedef enum {
    CORDIC_WIDTH_32BIT = 0U,      /**< 32-bit width */
    CORDIC_WIDTH_16BIT = 1U,      /**< 16-bit width */
} cordic_width_t;

/**
 * @brief   Type of CORDIC DMA configuration.
 */
typedef struct {
    /**
     * @brief   CORDIC Write DMA stream to be used for operations.
     */
    uint32_t                 dma_stream_wr_id;
    /**
     * @brief   CORDIC Read DMA stream to be used for operations.
     */
    uint32_t                 dma_stream_rd_id;
    /**
     * @brief   CORDIC DMA stream bus priority (3..0).
     */
    uint32_t                 dma_stream_bus_prio;
    /**
     * @brief   CORDIC DMA stream IRQ priority (3..15).
     */
    uint32_t                 dma_stream_irq_prio;
} cordic_dma_conf_t;

/**
 * @brief   Type of CORDIC callbacks.
 *
 * @param[in] cdp       pointer to the @p cordic_driver_t object
 */
typedef void (*cordic_cb_t)(cordic_driver_t *cdp);

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

/* Export driver modules.*/
#include <cordic_instances.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Initializes CORDIC instance.
 *
 * @param[out] cdp      pointer to a @p cordic_driver_t structure
 *
 * @api
 */
void cordic_init(cordic_driver_t *cdp);

/**
 * @brief   Configures CORDIC interrupt priority.
 * @note    This configuration becomes effective after cordic_start.
 *
 * @param[out] cdp      pointer to a @p cordic_driver_t structure
 * @param[in] prio      interrupt priority to be configured
 * @return              previous interrupt priority.
 *
 * @api
 */
uint32_t cordic_set_prio(cordic_driver_t *cdp, uint32_t prio);

/**
 * @brief   Configures CORDIC driver mode.
 * @note    This configuration becomes effective after cordic_start.
 * @note    For synchronous modes, when the cordic_calculate is invoked, it
 *          will return only when all calculations are completed. For
 *          asynchronous modes, instead, the cordic_calculate will only start
 *          the calculations and return. Then, a callback can be configured to
 *          notify when the calculations will be completed.
 *
 * @param[out] cdp      pointer to a @p cordic_driver_t structure
 * @param[in] drv_mode  driver mode to be configured. It can be one of the
 *                      following values:
 *            @arg @ref CORDIC_DRV_MODE_POLLING_SYNC
 *            @arg @ref CORDIC_DRV_MODE_INT_SYNC
 *            @arg @ref CORDIC_DRV_MODE_INT_ASYNC
 *            @arg @ref CORDIC_DRV_MODE_DMA_SYNC
 *            @arg @ref CORDIC_DRV_MODE_DMA_ASYNC
 * @return              previous driver mode. It can be one of the following
 *                      values:
 *            @arg @ref CORDIC_DRV_MODE_POLLING_SYNC
 *            @arg @ref CORDIC_DRV_MODE_INT_SYNC
 *            @arg @ref CORDIC_DRV_MODE_INT_ASYNC
 *            @arg @ref CORDIC_DRV_MODE_DMA_SYNC
 *            @arg @ref CORDIC_DRV_MODE_DMA_ASYNC
 *
 * @api
 */
cordic_drv_mode_t cordic_set_drv_mode(cordic_driver_t *cdp,
                                      cordic_drv_mode_t drv_mode);

/**
 * @brief   Configures CORDIC function.
 * @note    This configuration becomes effective after cordic_start.
 *
 * @param[out] cdp      pointer to a @p cordic_driver_t structure
 * @param[in] function  function to implement. It can be one of the following
 *                      values:
 *            @arg @ref CORDIC_FUNC_COSINE
 *            @arg @ref CORDIC_FUNC_SINE
 *            @arg @ref CORDIC_FUNC_PHASE
 *            @arg @ref CORDIC_FUNC_MODULUS
 *            @arg @ref CORDIC_FUNC_ARCTANGENT
 *            @arg @ref CORDIC_FUNC_HYP_COSINE
 *            @arg @ref CORDIC_FUNC_HYP_SINE
 *            @arg @ref CORDIC_FUNC_ARCTANH
 *            @arg @ref CORDIC_FUNC_NAT_LOG
 *            @arg @ref CORDIC_FUNC_SQUARE_ROOT
 * @return              previous implemented function. It can be one of the
 *                      following values:
 *            @arg @ref CORDIC_FUNC_COSINE
 *            @arg @ref CORDIC_FUNC_SINE
 *            @arg @ref CORDIC_FUNC_PHASE
 *            @arg @ref CORDIC_FUNC_MODULUS
 *            @arg @ref CORDIC_FUNC_ARCTANGENT
 *            @arg @ref CORDIC_FUNC_HYP_COSINE
 *            @arg @ref CORDIC_FUNC_HYP_SINE
 *            @arg @ref CORDIC_FUNC_ARCTANH
 *            @arg @ref CORDIC_FUNC_NAT_LOG
 *            @arg @ref CORDIC_FUNC_SQUARE_ROOT
 *
 * @api
 */
cordic_func_t cordic_set_function(cordic_driver_t *cdp, cordic_func_t function);

/**
 * @brief   Configures CORDIC precision.
 * @note    This configuration becomes effective after cordic_start.
 *
 * @param[out] cdp      pointer to a @p cordic_driver_t structure
 * @param[in] precision precision required (in terms of number of iterations).
 *                      It can be one of the following values:
 *            @arg @ref CORDIC_PREC_1CYCLE
 *            @arg @ref CORDIC_PREC_2CYCLES
 *            @arg @ref CORDIC_PREC_3CYCLES
 *            @arg @ref CORDIC_PREC_4CYCLES
 *            @arg @ref CORDIC_PREC_5CYCLES
 *            @arg @ref CORDIC_PREC_6CYCLES
 *            @arg @ref CORDIC_PREC_7CYCLES
 *            @arg @ref CORDIC_PREC_8CYCLES
 *            @arg @ref CORDIC_PREC_9CYCLES
 *            @arg @ref CORDIC_PREC_10CYCLES
 *            @arg @ref CORDIC_PREC_11CYCLES
 *            @arg @ref CORDIC_PREC_12CYCLES
 *            @arg @ref CORDIC_PREC_13CYCLES
 *            @arg @ref CORDIC_PREC_14CYCLES
 *            @arg @ref CORDIC_PREC_15CYCLES
 * @return              previous required precision. It can be one of the
 *                      following values:
 *            @arg @ref CORDIC_PREC_1CYCLE
 *            @arg @ref CORDIC_PREC_2CYCLES
 *            @arg @ref CORDIC_PREC_3CYCLES
 *            @arg @ref CORDIC_PREC_4CYCLES
 *            @arg @ref CORDIC_PREC_5CYCLES
 *            @arg @ref CORDIC_PREC_6CYCLES
 *            @arg @ref CORDIC_PREC_7CYCLES
 *            @arg @ref CORDIC_PREC_8CYCLES
 *            @arg @ref CORDIC_PREC_9CYCLES
 *            @arg @ref CORDIC_PREC_10CYCLES
 *            @arg @ref CORDIC_PREC_11CYCLES
 *            @arg @ref CORDIC_PREC_12CYCLES
 *            @arg @ref CORDIC_PREC_13CYCLES
 *            @arg @ref CORDIC_PREC_14CYCLES
 *            @arg @ref CORDIC_PREC_15CYCLES
 *
 * @api
 */
cordic_prec_t cordic_set_precision(cordic_driver_t *cdp,
                                   cordic_prec_t precision);

/**
 * @brief   Configures CORDIC scale.
 * @note    This configuration becomes effective after cordic_start.
 * @note    Refer to RM for the applicability of the scaling factor
 *          for each function and the appropriate range.
 *
 * @param[out] cdp      pointer to a @p cordic_driver_t structure
 * @param[in] scale     scaling factor. It can be one of the following values:
 *            @arg @ref CORDIC_SCALE_0
 *            @arg @ref CORDIC_SCALE_1
 *            @arg @ref CORDIC_SCALE_2
 *            @arg @ref CORDIC_SCALE_3
 *            @arg @ref CORDIC_SCALE_4
 *            @arg @ref CORDIC_SCALE_5
 *            @arg @ref CORDIC_SCALE_6
 *            @arg @ref CORDIC_SCALE_7
 * @return              previous scaling factor. It can be one of the following
 *                      values:
 *            @arg @ref CORDIC_SCALE_0
 *            @arg @ref CORDIC_SCALE_1
 *            @arg @ref CORDIC_SCALE_2
 *            @arg @ref CORDIC_SCALE_3
 *            @arg @ref CORDIC_SCALE_4
 *            @arg @ref CORDIC_SCALE_5
 *            @arg @ref CORDIC_SCALE_6
 *            @arg @ref CORDIC_SCALE_7
 *
 * @api
 */
cordic_scale_t cordic_set_scale(cordic_driver_t *cdp, cordic_scale_t scale);

/**
 * @brief   Configures CORDIC result in terms of number of results and width.
 * @note    This configuration becomes effective after cordic_start.
 *
 * @param[out] cdp      pointer to a @p cordic_driver_t structure
 * @param[in] nres      number of results. It can be one of the following
 *                      values:
 *            @arg @ref CORDIC_NUM_1_32BIT_OR_2_16BIT
 *            @arg @ref CORDIC_NUM_2_32BIT
 * @param[in] ressize   width of results. It can be one of the following
 *                      values:
 *            @arg @ref CORDIC_WIDTH_32BIT
 *            @arg @ref CORDIC_WIDTH_16BIT
 *
 * @api
 */
void cordic_set_res(cordic_driver_t *cdp, cordic_num_t nres,
                    cordic_width_t ressize);

/**
 * @brief   Configures CORDIC arguments in terms of number of arguments and
 *          width.
 * @note    This configuration becomes effective after cordic_start.
 *
 * @param[out] cdp      pointer to a @p cordic_driver_t structure
 * @param[in] nargs     number of arguments expected by CORDIC. It can be one
 *                      of the following values:
 *            @arg @ref CORDIC_NUM_1_32BIT_OR_2_16BIT
 *            @arg @ref CORDIC_NUM_2_32BIT
 * @param[in] argsize   width of arguments. It can be one of the following
 *                      values:
 *            @arg @ref CORDIC_WIDTH_32BIT
 *            @arg @ref CORDIC_WIDTH_16BIT
 *
 * @api
 */
void cordic_set_arg(cordic_driver_t *cdp, cordic_num_t nargs,
                    cordic_width_t argsize);

/**
 * @brief   Configures CORDIC DMA.
 * @note    This configuration becomes effective after uart_start.
 *
 * @param[out] cdp      pointer to a @p cordic_driver_t structure
 * @param[in] dma_conf  pointer to DMA configuration to be configured
 * @return              pointer to previous DMA configuration.
 *
 * @api
 */
cordic_dma_conf_t *cordic_set_dma_conf(cordic_driver_t *cdp,
                                       cordic_dma_conf_t *dma_conf);

/**
 * @brief   Configures pointers to CORDIC callback function.
 * @note    Callback function is supported only for the following driver modes:
 *            @arg @ref CORDIC_DRV_MODE_INT_SYNC
 *            @arg @ref CORDIC_DRV_MODE_INT_ASYNC
 *            @arg @ref CORDIC_DRV_MODE_DMA_SYNC
 *            @arg @ref CORDIC_DRV_MODE_DMA_ASYNC
 *
 * @param[out] cdp      pointer to a @p cordic_driver_t structure
 * @param[in] cb        pointer to CORDIC callback function
 * @return              pointer to previuos CORDIC callback function.
 *
 * @api
 */
cordic_cb_t cordic_set_cb(cordic_driver_t *cdp, cordic_cb_t cb);

/**
 * @brief   Starts CORDIC instance.
 *
 * @param[in] cdp       pointer to a @p cordic_driver_t structure
 *
 * @api
 */
void cordic_start(cordic_driver_t *cdp);

/**
 * @brief   Runs CORDIC calculation.
 *
 * @param[in] cdp       pointer to a @p cordic_driver_t structure
 * @param[in] input     pointer to input buffer containing the arguments for
 *                      the calculation
 * @param[in] output    pointer to ouput buffer containing the results of the
 *                      calculation
 * @param[in] calc_num  number of calculations to process.    
 *
 * @api
 */
void cordic_calculate(cordic_driver_t *cdp, int32_t *input, int32_t *output,
                      uint32_t calc_num);

/**
 * @brief   Stops CORDIC instance.
 *
 * @param[in] cdp       pointer to a @p cordic_driver_t structure
 *
 * @api
 */
void cordic_stop(cordic_driver_t *cdp);

/**
 * @brief   Deinitializes CORDIC instance.
 *
 * @param[out] cdp      pointer to a @p cordic_driver_t structure
 *
 * @api
 */
void cordic_deinit(cordic_driver_t *cdp);

/**
 * @brief   Shared interrupt handler.
 * @note    Not an API, used internally.
 *
 * @param[in] cdp       pointer to a @p cordic_driver_t structure
 *
 * @isr
 */
void __cordic_serve_interrupt(cordic_driver_t *cdp);

#ifdef __cplusplus
}
#endif

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/*===========================================================================*/
/* Module late inclusions.                                                   */
/*===========================================================================*/

#endif /* _CORDIC_H_ */

/** @} */
