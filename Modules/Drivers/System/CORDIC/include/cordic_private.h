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
 * @file    cordic_private.h
 * @brief   CORDIC driver private header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup SYSTEM
 * @ingroup DRIVERS
 * @addtogroup CORDIC
 * @ingroup SYSTEM
 * @{
 */

#ifndef _CORDIC_PRIVATE_H_
#define _CORDIC_PRIVATE_H_

#include <dma.h>
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
 * @brief   CORDIC driver structure.
 * @note    This structure is internal to the CORDIC driver.
 */
struct cordic_driver {
    /**
     * @brief   Pointer to CORDIC registers block.
     */
    CORDIC_TypeDef           *cordic;
    /**
     * @brief   CORDIC interrupt priority.
     */
    uint32_t                 prio;
    /**
     * @brief   Driver mode (synchronous or asynchronous).
     */
    cordic_drv_mode_t        drv_mode;
    /**
     * @brief   Function to calculate.
     */
    cordic_func_t            function;
    /**
     * @brief   Required precision.
     */
    cordic_prec_t            precision;
    /**
     * @brief   Scaling factor.
     */
    cordic_scale_t           scale;
    /**
     * @brief   Number of results.
     */
    cordic_num_t             nres;
    /**
     * @brief   Number of expected arguments.
     */
    cordic_num_t             nargs;
    /**
     * @brief   Width of output data.
     */
    cordic_width_t           ressize;
    /**
     * @brief   Width of input data.
     */
    cordic_width_t           argsize;
    /**
     * @brief   Pointer to input data buffer (containg arguments to be
     *          processed).
     */
    int32_t                  *input;
    /**
     * @brief   Pointer to output data buffer (containg results of processing).
     */
    int32_t                  *output;
    /**
     * @brief   Number of remaining calculations to process.
     */
    uint32_t                 calc_num;
    /**
     * @brief  Calculation progress flag.
     */
    volatile cordic_sts_t    busy;
    /**
     * @brief   DMA configuration.
     */
    cordic_dma_conf_t        *dma_conf;
    /**
     * @brief   Allocated Read DMA descriptor.
     */
    const dma_descriptor_t   *dma_rd_descriptor;
    /**
     * @brief   Allocated Write DMA descriptor.
     */
    const dma_descriptor_t   *dma_wr_descriptor;
    /**
     * @brief   Pointers to CORDIC callback functions.
     * @note    Set to @p NULL if not required.
     */
    cordic_cb_t              cb;
};

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

IRQ_HANDLER(IRQ_CORDIC_HANDLER);

CORDIC_TypeDef *cordic_dev_get_reg_ptr(cordic_driver_t *cdp);
void cordic_dev_clock_enable(cordic_driver_t *cdp);
void cordic_dev_clock_disable(cordic_driver_t *cdp);
uint32_t cordic_dev_get_dma_wr_trigger(cordic_driver_t *cdp);
uint32_t cordic_dev_get_dma_rd_trigger(cordic_driver_t *cdp);
IRQn_Type cordic_dev_get_vector(cordic_driver_t *cdp);

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/*===========================================================================*/
/* Module late inclusions.                                                   */
/*===========================================================================*/

#endif /* _CORDIC_PRIVATE_H_ */

/** @} */

