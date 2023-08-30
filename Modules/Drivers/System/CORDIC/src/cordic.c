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
 * @file    cordic.c
 * @brief   CORDIC driver source file.
 *
 * @addtogroup DRIVERS
 * @addtogroup SYSTEM
 * @ingroup DRIVERS
 * @addtogroup CORDIC
 * @ingroup SYSTEM
 * @{
 */

#include <cordic.h>
#include <cordic_private.h>

/*===========================================================================*/
/* Module local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Module exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Module local types.                                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Module local variables.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Local function prototypes                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Module local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   Enters in calculation mode.
 * @note    Called when CORDIC driver enters in calculation mode.
 *
 * @param[in] \_cdp\_   pointer to a @p cordic_driver_t structure
 *
 * @notapi
 */
#define CORDIC_IN_PROGRESS(_cdp_)                                 \
    (_cdp_)->busy = CORDIC_BUSY

/**
 * @brief  Exits from calculation mode.
 * @note   Called when CORDIC driver exits from calculation mode.
 *
 * @param[in] \_cdp\_   pointer to a @p cordic_driver_t structure
 *
 * @notapi
 */
#define CORDIC_DONE(_cdp_)                                        \
    (_cdp_)->busy = CORDIC_READY

/**
 * @brief  Waits for calculation end.
 * @note   Called to wait for end of calculation.
 *
 * @param[in] \_cdp\_   pointer to a @p cordic_driver_t structure
  *
 * @notapi
 */
#define CORDIC_WAIT_FOR_COMPLETION(_cdp_)                         \
    if (((_cdp_)->drv_mode == CORDIC_DRV_MODE_POLLING_SYNC) ||    \
        ((_cdp_)->drv_mode == CORDIC_DRV_MODE_INT_SYNC) ||        \
        ((_cdp_)->drv_mode == CORDIC_DRV_MODE_DMA_SYNC)) {        \
        while ((_cdp_)->busy == CORDIC_BUSY) {;}                  \
    }

/**
 * @brief   Resets CORDIC parameters.
 *
 * @param[out] cdp      pointer to an @p cordic_driver_t structure
 *
 * @notapi
 */
static void cordic_reset_paramters(cordic_driver_t *cdp) {

    cdp->prio              = IRQ_MIN_PRIORITY;
    cdp->drv_mode          = CORDIC_DRV_MODE_POLLING_SYNC;
    cdp->function          = CORDIC_FUNC_COSINE;
    cdp->precision         = CORDIC_PREC_5CYCLES;
    cdp->scale             = CORDIC_SCALE_0;
    cdp->nres              = CORDIC_NUM_1_32BIT_OR_2_16BIT;
    cdp->nargs             = CORDIC_NUM_1_32BIT_OR_2_16BIT;
    cdp->ressize           = CORDIC_WIDTH_32BIT;
    cdp->argsize           = CORDIC_WIDTH_32BIT;
    cdp->input             = NULL;
    cdp->output            = NULL;
    cdp->calc_num          = 0U;
    cdp->busy              = CORDIC_READY;
    cdp->dma_conf          = NULL;
    cdp->dma_rd_descriptor = NULL;
    cdp->dma_wr_descriptor = NULL;
    cdp->cb                = NULL;
}

/**
 * @brief   DMA Read Interrupt handler.
 *
 * @param[in] arg       argument associated to the callback
 * @param[in] sts       DMA callback cause status flags
 *
 * @isr
 */
static void cordic_serve_dma_rd_interrupt(void *arg, uint32_t sts) {

    /*lint -e9087 */
    cordic_driver_t *cdp = (cordic_driver_t *)arg;
    /*lint +e9087 */

    /* Checking for errors.*/
    if ((sts & DMA_STS_TEIF) != 0U) {
        /* TODO: manage DMA error.*/
    } else {
        /* Read result completed.*/
        if ((sts & DMA_STS_TCIF) != 0U) {
            if (cdp->cb != NULL) {
                cdp->cb(cdp);
            } else {
                ; /* close "if" as required by MISRA */
            }
        } else {
            ; /* close "if" as required by MISRA */
        }
    }

    CORDIC_DONE(cdp);
}

/**
 * @brief   Writes arguments in WDATA register.
 *
 * @param[in] cdp       pointer to a @p cordic_driver_t structure
 *
 * @api
 */
__STATIC_INLINE void cordic_lld_write_input(cordic_driver_t *cdp) {

    /* Write first argument in WDATA register.*/
    cdp->cordic->WDATA = (uint32_t)(*cdp->input++);

    if (cdp->nargs == CORDIC_NUM_2_32BIT) {
        /* Write second argument in WDATA register.*/
        cdp->cordic->WDATA = (uint32_t)(*cdp->input++);
    }
}

/**
 * @brief   Reads results from WDATA register.
 *
 * @param[in] cdp       pointer to a @p cordic_driver_t structure
 *
 * @api
 */
__STATIC_INLINE void cordic_lld_read_output(cordic_driver_t *cdp) {

    /* Read first result from RDATA register.*/
    *cdp->output++ = (int32_t)(cdp->cordic->RDATA);

    if (cdp->nres == CORDIC_NUM_2_32BIT) {
        /* Read second result from RDATA register.*/
        *cdp->output++ = (int32_t)(cdp->cordic->RDATA);
    }
}

/**
 * @brief   Runs CORDIC calculation in polling mode.
 *
 * @param[in] cdp       pointer to a @p cordic_driver_t structure
 *
 * @api
 */
static void cordic_lld_calculate_polling(cordic_driver_t *cdp) {

    uint32_t i;

    if (cdp->input != NULL) {

        for (i = 0U; i < cdp->calc_num; i++) {
	    
            /* Start new calculation.*/
            cordic_lld_write_input(cdp);
	    
            /* Wait till the calculation is complited.*/
            do {
                ;
            } while (REG_READ_FIELD(cdp->cordic->CSR, CORDIC_CSR_RRDY) == 0U);
	    
            /* Read calculation result.*/
            cordic_lld_read_output(cdp);
        }
    }
    CORDIC_DONE(cdp);
}

/**
 * @brief   Runs CORDIC calculation in interrupt mode.
 *
 * @param[in] cdp       pointer to a @p cordic_driver_t structure
 *
 * @api
 */
static void cordic_lld_calculate_int(cordic_driver_t *cdp) {

    if (cdp->input != NULL) {
        /* Start new calculation.*/
        cordic_lld_write_input(cdp);
    }
}

/**
 * @brief   Runs CORDIC calculation in DMA mode.
 *
 * @param[in] cdp       pointer to a @p cordic_driver_t structure
 *
 * @api
 */
static void cordic_lld_calculate_dma(cordic_driver_t *cdp) {

    /* Configure DMA Write number of data items.*/
    if (cdp->nargs == CORDIC_NUM_1_32BIT_OR_2_16BIT) {
        dma_stream_set_count(cdp->dma_wr_descriptor, (uint32_t)(cdp->calc_num));
    } else {
        dma_stream_set_count(cdp->dma_wr_descriptor, (uint32_t)(2U * cdp->calc_num));
    }
    /* Configure DMA Read number of data items.*/
    if (cdp->nargs == CORDIC_NUM_1_32BIT_OR_2_16BIT) {
        dma_stream_set_count(cdp->dma_rd_descriptor, (uint32_t)(cdp->calc_num));
    } else {
        dma_stream_set_count(cdp->dma_rd_descriptor, (uint32_t)(2U * cdp->calc_num));
    }

    /* Configure DMA Write stream memory address.*/
    dma_stream_set_memory(cdp->dma_wr_descriptor, (uint32_t)(cdp->input));
    /* Configure DMA Read stream memory address.*/
    dma_stream_set_memory(cdp->dma_rd_descriptor, (uint32_t)(cdp->output));

    /* Enable DMA Write. It will be disabled on the DMA end of transfer.*/
    dma_stream_enable(cdp->dma_wr_descriptor);
    /* Enable DMA Read. It will be disabled on the DMA end of transfer.*/
    dma_stream_enable(cdp->dma_rd_descriptor);
}

/*===========================================================================*/
/* Module exported functions.                                                */
/*===========================================================================*/

void cordic_init(cordic_driver_t *cdp) {

    /* Set pointer to CORDIC register block.*/
    cdp->cordic = cordic_dev_get_reg_ptr(cdp);

    /* Reset CORDIC parameters.*/
    cordic_reset_paramters(cdp);
}

uint32_t cordic_set_prio(cordic_driver_t *cdp, uint32_t prio) {

    uint32_t prev_prio;

    prev_prio = cdp->prio;
    cdp->prio = prio;

    return prev_prio;
}

cordic_drv_mode_t cordic_set_drv_mode(cordic_driver_t *cdp,
                                      cordic_drv_mode_t drv_mode) {

    cordic_drv_mode_t prev_drv_mode;

    prev_drv_mode = cdp->drv_mode;
    cdp->drv_mode = drv_mode;

    return prev_drv_mode;
}

cordic_func_t cordic_set_function(cordic_driver_t *cdp, cordic_func_t function) {

    cordic_func_t prev_function;

    prev_function = cdp->function;
    cdp->function = function;

    return prev_function;
}

cordic_prec_t cordic_set_precision(cordic_driver_t *cdp, 
                                   cordic_prec_t precision) {

    cordic_prec_t prev_precision;

    prev_precision = cdp->precision;
    cdp->precision = precision;

    return prev_precision;
}

cordic_scale_t cordic_set_scale(cordic_driver_t *cdp, cordic_scale_t scale) {

    cordic_scale_t prev_scale;

    prev_scale = cdp->scale;
    cdp->scale = scale;

    return prev_scale;
}

void cordic_set_res(cordic_driver_t *cdp, cordic_num_t nres,
                    cordic_width_t ressize) {

    cdp->nres = nres;
    cdp->ressize = ressize;
}

void cordic_set_arg(cordic_driver_t *cdp, cordic_num_t nargs,
                    cordic_width_t argsize) {

    cdp->nargs = nargs;
    cdp->argsize = argsize;
}

cordic_dma_conf_t *cordic_set_dma_conf(cordic_driver_t *cdp,
                                       cordic_dma_conf_t *dma_conf) {

    cordic_dma_conf_t *prev_dma_conf;

    prev_dma_conf = cdp->dma_conf;
    cdp->dma_conf = dma_conf;

    return prev_dma_conf;
}

cordic_cb_t cordic_set_cb(cordic_driver_t *cdp, cordic_cb_t cb) {

    cordic_cb_t prev_cb;

    prev_cb = cdp->cb;
    cdp->cb = cb;

    return prev_cb;
}

void cordic_start(cordic_driver_t *cdp) {

    IRQn_Type vector;
    uint32_t dma_wr_trigger, dma_rd_trigger;
    uint32_t dma_wr_mode, dma_rd_mode;

    /* Enable clock.*/
    cordic_dev_clock_enable(cdp);

    /* Set interrupt used in interrupt mode.*/
    if ((cdp->drv_mode == CORDIC_DRV_MODE_INT_SYNC) ||
        (cdp->drv_mode == CORDIC_DRV_MODE_INT_ASYNC)) {
        /* Enable CORDIC interrupt.*/
        REG_SET_FIELD(cdp->cordic->CSR, CORDIC_CSR_IEN, 0x1U);

        vector = cordic_dev_get_vector(cdp);
        irq_set_priority(vector, cdp->prio);
        irq_enable(vector);
    } else {
        /* Disable CORDIC interrupt.*/
        REG_SET_FIELD(cdp->cordic->CSR, CORDIC_CSR_IEN, 0x0U);
    }

    /* Configure DMA.*/
    if ((cdp->drv_mode == CORDIC_DRV_MODE_DMA_SYNC) ||
        (cdp->drv_mode == CORDIC_DRV_MODE_DMA_ASYNC)) {
        /* Allocates DMA streams for CORDIC calculation.*/
        /*lint -e9087 */
        cdp->dma_wr_descriptor = dma_stream_take(cdp->dma_conf->dma_stream_wr_id,
                                                 cdp->dma_conf->dma_stream_irq_prio,
                                                 NULL,
                                                 (void *)cdp);
        cdp->dma_rd_descriptor = dma_stream_take(cdp->dma_conf->dma_stream_rd_id,
                                                 cdp->dma_conf->dma_stream_irq_prio,
                                                 cordic_serve_dma_rd_interrupt,
                                                 (void *)cdp);
        /*lint +e9087 */

        /* Configure DMA stream peripheral addresses.*/
        dma_stream_set_peripheral(cdp->dma_wr_descriptor, (uint32_t)(&cdp->cordic->WDATA));
        dma_stream_set_peripheral(cdp->dma_rd_descriptor, (uint32_t)(&cdp->cordic->RDATA));

        /* Configure DMA TX/RX triggers.*/
        dma_wr_trigger = cordic_dev_get_dma_wr_trigger(cdp);
        dma_stream_set_trigger(cdp->dma_wr_descriptor, dma_wr_trigger);
        dma_rd_trigger = cordic_dev_get_dma_rd_trigger(cdp);
        dma_stream_set_trigger(cdp->dma_rd_descriptor, dma_rd_trigger);

        /* Configure DMA priority level, data transfer direction and enable
           transfer complete interrupt.*/
        dma_wr_mode = DMA_CCR_PL_VALUE(cdp->dma_conf->dma_stream_bus_prio) |
                      DMA_CCR_DIR_M2P | DMA_CCR_TCIE;
        dma_rd_mode = DMA_CCR_PL_VALUE(cdp->dma_conf->dma_stream_bus_prio) |
                      DMA_CCR_DIR_P2M | DMA_CCR_TCIE;

        /* Configure DMA memory increment mode.*/
        dma_wr_mode |= DMA_CCR_MINC;
        dma_rd_mode |= DMA_CCR_MINC;

        /* Configure DMA frame size.*/
        dma_wr_mode |= DMA_CCR_PSIZE_WORD | DMA_CCR_MSIZE_WORD;
        dma_rd_mode |= DMA_CCR_PSIZE_WORD | DMA_CCR_MSIZE_WORD;

        /* Set up calculated DMA modes.*/
        dma_stream_set_transfer_mode(cdp->dma_wr_descriptor, dma_wr_mode);
        dma_stream_set_transfer_mode(cdp->dma_rd_descriptor, dma_rd_mode);

        /* Enable DMA.*/
        REG_SET_FIELD(cdp->cordic->CSR, CORDIC_CSR_DMAWEN, 1U);
        REG_SET_FIELD(cdp->cordic->CSR, CORDIC_CSR_DMAREN, 1U);
    } else {
        /* Disable DMA.*/
        REG_SET_FIELD(cdp->cordic->CSR, CORDIC_CSR_DMAWEN, 0U);
        REG_SET_FIELD(cdp->cordic->CSR, CORDIC_CSR_DMAREN, 0U);
    }

    /* Set CORDIC function.*/
    REG_SET_FIELD(cdp->cordic->CSR, CORDIC_CSR_FUNC, (uint8_t)cdp->function);

    /* Set CORDIC precision (number of iteractions).*/
    REG_SET_FIELD(cdp->cordic->CSR, CORDIC_CSR_PRECISION, (uint8_t)cdp->precision);

    /* Set CORDIC scale factor.*/
    REG_SET_FIELD(cdp->cordic->CSR, CORDIC_CSR_SCALE, (uint8_t)cdp->scale);

    /* Set number of results in the RDATA register.*/
    REG_SET_FIELD(cdp->cordic->CSR, CORDIC_CSR_NRES, (uint8_t)cdp->nres);

    /* Set width of output data.*/
    REG_SET_FIELD(cdp->cordic->CSR, CORDIC_CSR_RESSIZE, (uint8_t)cdp->ressize);

    /* Set number of arguments expected by the WDATA register.*/
    REG_SET_FIELD(cdp->cordic->CSR, CORDIC_CSR_NARGS, (uint8_t)cdp->nargs);

    /* Set width of input data.*/ 
    REG_SET_FIELD(cdp->cordic->CSR, CORDIC_CSR_ARGSIZE, (uint8_t)cdp->argsize);
}

void cordic_calculate(cordic_driver_t *cdp, int32_t *input, int32_t *output,
                      uint32_t calc_num) {

    if (calc_num > 0UL) {
        CORDIC_IN_PROGRESS(cdp);

        cdp->input = input;
        cdp->output = output;
        cdp->calc_num = calc_num;

        if (cdp->drv_mode == CORDIC_DRV_MODE_POLLING_SYNC) {
            cordic_lld_calculate_polling(cdp);
        } else if ((cdp->drv_mode == CORDIC_DRV_MODE_INT_SYNC) ||
                   (cdp->drv_mode == CORDIC_DRV_MODE_INT_ASYNC)) {
            cordic_lld_calculate_int(cdp);
        } else {
            cordic_lld_calculate_dma(cdp);
        }

        /* Wait for completion */
        CORDIC_WAIT_FOR_COMPLETION(cdp);
    }
}

void cordic_stop(cordic_driver_t *cdp) {

    IRQn_Type vector;

    /* Disable interrupt used in interrupt mode.*/
    if ((cdp->drv_mode == CORDIC_DRV_MODE_INT_SYNC) ||
        (cdp->drv_mode == CORDIC_DRV_MODE_INT_ASYNC)) {
        vector = cordic_dev_get_vector(cdp);
        irq_disable(vector);
    }

    /* Disable DMA.*/
    if ((cdp->drv_mode == CORDIC_DRV_MODE_DMA_SYNC) ||
        (cdp->drv_mode == CORDIC_DRV_MODE_DMA_ASYNC)) {
        REG_SET_FIELD(cdp->cordic->CSR, CORDIC_CSR_DMAWEN, 0U);
        REG_SET_FIELD(cdp->cordic->CSR, CORDIC_CSR_DMAREN, 0U);
    }

    /* Set CSR register to default values.*/
    cdp->cordic->CSR = 0x00000050UL;

    /* Disable clock.*/
    cordic_dev_clock_disable(cdp);
}

void cordic_deinit(cordic_driver_t *cdp) {

    /* Set pointer to CORDIC register block to NULL.*/
    cdp->cordic = NULL;

    /* Reset CORDIC parameters.*/
    cordic_reset_paramters(cdp);
}

void __cordic_serve_interrupt(cordic_driver_t *cdp) {

    uint32_t csr;

    csr = cdp->cordic->CSR;

    if ((csr & CORDIC_CSR_RRDY) != 0U) {
        if (cdp->output != NULL) {
            /* Read calculation result.*/
            cordic_lld_read_output(cdp);
            cdp->calc_num--;
            /* Calculation completed.*/
            if (cdp->calc_num == 0U) {
                /* If callback is defined, it is invoked.*/
                if (cdp->cb != NULL) {
                    cdp->cb(cdp);
                }
                CORDIC_DONE(cdp);
            } else {
                if (cdp->input != NULL) {
                    /* Start new calculation.*/
                    cordic_lld_write_input(cdp);
                }
            }
        }
    }
}

/** @} */
