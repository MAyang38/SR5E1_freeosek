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
 * @file    saradc.c
 * @brief   ADC driver source file.
 *
 * @addtogroup DRIVERS
 * @addtogroup ANALOG
 * @ingroup DRIVERS
 * @addtogroup ADC
 * @ingroup ANALOG
 * @{
 */

#include <saradc.h>
#include <saradc_private.h>
#include <osal.h>

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
 * @brief   Resets ADC parameters.
 *
 * @param[out] adp      pointer to an @p adc_driver_t structure
 *
 * @notapi
 */
static void adc_reset_paramters(adc_driver_t *adp) {

    uint8_t i;

    /* Set all driver configuration parameters to default values.*/
    adp->clk_mode          = ADC_CLK_MODE_ADCCLK;
    adp->presc             = ADC_CLK_PRESC_DIV_1;
    adp->data_res          = ADC_DATA_RES_12;
    adp->prio              = IRQ_MIN_PRIORITY;
    adp->is_interrupt_en   = true;
    adp->dma_conf          = NULL;
    adp->dma_descriptor    = NULL;
    /* Regular conversion parameters.*/
    adp->reg_mode          = ADC_REG_SINGLE;
    adp->reg_ext           = 0U;
    adp->reg_ext_pol       = ADC_EXT_POL_DISABLED;
    adp->n_reg_channels    = 0U;
    adp->reg_seq           = NULL;
    adp->reg_buffer        = NULL;
    /* Injected conversion parameters.*/
    adp->inj_ext           = 0U;
    adp->inj_ext_pol       = ADC_EXT_POL_DISABLED;
    adp->n_inj_channels    = 0U;
    adp->inj_seq           = NULL;
    adp->inj_buffer        = NULL;
    /* Channel sample time parameters.*/
    for (i = 0U; i < (uint8_t)ADC_CH_NUM; i++) {
        adp->smp_time[i]   = ADC_SMP_2P5;
    }
    /* Watchdog threshold parameters.*/ 
    for (i = 0U; i < (uint8_t)ADC_WATCHDOG_NUM; i++) {
        adp->aw_tr[i] = ADC_TR_DEFAULT;
    }
    adp->dif_mask  = 0U;
    /* ADC normal operation callbacks.*/
    for (i = 0U; i < (uint8_t)ADC_OP_MAX; i++) {
         adp->op_cb[i] = NULL;
    }
    /* ADC error callbacks.*/
    for (i = 0U; i < (uint8_t)ADC_ERR_MAX; i++) {
        adp->err_cb[i] = NULL;
    }
}

/**
 * @brief   ADC external trigger enable check.
 * @note    Checks if external triggers are enabled for regular conversion.
 *
 * @param[in] adp       pointer to the @p adc_driver_t structure
 *
 * @notapi
 */
static bool is_external_trigger_enable_regular(adc_driver_t *adp) {

    return (bool)(((adp->adc->CFGR & ADC_CFGR_EXTEN_Msk) >> ADC_CFGR_EXTEN_Pos) != 0U);
}

/**
 * @brief   ADC external trigger enable check.
 * @note    Checks if external triggers are enabled for injected conversion.
 *
 * @param[in] adp       pointer to the @p adc_driver_t structure
 *
 * @notapi
 */
static bool is_external_trigger_enable_injected(adc_driver_t *adp) {

    return (bool)(((adp->adc->JSQR & ADC_JSQR_JEXTEN_Msk) >> ADC_JSQR_JEXTEN_Pos) != 0U);
}

/**
 * @brief   ADC full buffer event handling for regular conversions.
 * @note    To be called from IRQ context.
 *
 * @param[in] adp       pointer to the @p adc_driver_t structure
 *
 * @notapi
 */
static void adc_data_full_event_regular(adc_driver_t *adp) {

    bool is_trigger_enable = is_external_trigger_enable_regular(adp);

    if ((adp->reg_mode == ADC_REG_CONTINUOUS) || (is_trigger_enable)) {
        /* Continuous conversion mode or single conversion mode with trigger,
           needs to notify and continue.*/
        if ( adp->op_cb[ADC_OP_REG_CONV] != NULL) {
             adp->op_cb[ADC_OP_REG_CONV](adp);
        }
    }
    else {
        /* Single conversion mode finished.*/
        adc_stop_regular(adp);

        /* Full buffer callback handling.*/
        if ( adp->op_cb[ADC_OP_REG_CONV] != NULL) {
             adp->op_cb[ADC_OP_REG_CONV](adp);

        }
    }
}

/**
 * @brief   ADC full buffer event handling for injected conversions.
 * @note    To be called from IRQ context.
 *
 * @param[in] adp       pointer to the @p adc_driver_t structure
 *
 * @notapi
 */
static void adc_data_full_event_injected(adc_driver_t *adp) {

    if (is_external_trigger_enable_injected(adp)) {
        /* Single conversion mode with trigger, needs to notify and continue.*/
        if ( adp->op_cb[ADC_OP_INJ_CONV] != NULL) {
             adp->op_cb[ADC_OP_INJ_CONV](adp);
        }
    }
    else {
        /* Single conversion mode finished.*/
        adc_stop_injected(adp);

        /* Full buffer callback handling.*/
        if ( adp->op_cb[ADC_OP_INJ_CONV] != NULL) {
             adp->op_cb[ADC_OP_INJ_CONV](adp);
        }
    }
}

/**
 * @brief   ADC normal error handling.
 * @note    To be called from IRQ context.
 *
 * @param[in] adp       pointer to the @p adc_driver_t structure
 * @param[in] err       error code
 */
static void adc_normal_error_event(adc_driver_t *adp, adc_err_t err) {

    /* Error callback handling.*/
    if (adp->err_cb[err] != NULL) {
        adp->err_cb[err](adp, err);
    }
}

/**
 * @brief   ADC critical error handling (only for regular conversions).
 * @note    To be called from IRQ context.
 *
 * @param[in] adp       pointer to the @p adc_driver_t structure
 * @param[in] err       ADC error code
 *
 * @notapi
 */
static void adc_critical_error_event(adc_driver_t *adp, adc_err_t err) {

    /* Error callback handling.*/
    if (adp->err_cb[err] != NULL) {
        adp->err_cb[err](adp, err);
    }

    adc_stop_regular(adp);
}

/**
 * @brief   DMA callback.
 *
 * @param[in] arg       argument associated to the callback
 * @param[in] sts       DMA callback cause status flags
 *
 * @notapi
 */
static void adc_dma_callback(void *arg, uint32_t sts) {

    /*lint -e9087 */
    adc_driver_t *adp = (adc_driver_t *)arg;
    /*lint +e9087 */

    /* Checking for errors.*/
    if ((sts & DMA_STS_TEIF) != 0U) {
        /* DMA critical error.*/
        adc_critical_error_event(adp, ADC_ERR_DMA);
    }
    else {
        if ((sts & DMA_STS_TCIF) != 0U) {
            /* Full buffer event.*/
            adc_data_full_event_regular(adp);
        } else {
            ; /* close "if" as required by MISRA */
        }
    }
}

/**
 * @brief   ADC activation and calibration procedure.
 *
 * @param[in] adp       pointer to the @p adc_driver_t structure
 *
 * @notapi
 */
static void adc_activate(adc_driver_t *adp) {

    /* Activating the regulator.*/
    adp->adc->CR = 0;
    adp->adc->CR = ADC_CR_ADVREGEN;
    osal_delay_microsec(ADCVREG_STUP_TIME_US);

    /* Differential calibration phase.*/
    adp->adc->CR = ADC_CR_ADVREGEN | ADC_CR_ADCALDIF;
    adp->adc->CR = ADC_CR_ADVREGEN | ADC_CR_ADCALDIF | ADC_CR_ADCAL;
    while ((adp->adc->CR & ADC_CR_ADCAL) != 0U) {
    }
    osal_delay_microsec(ADCVREG_STUP_TIME_US);

    /* Single-ended calibration phase.*/
    adp->adc->CR = ADC_CR_ADVREGEN;
    adp->adc->CR = ADC_CR_ADVREGEN | ADC_CR_ADCAL;
    while ((adp->adc->CR & ADC_CR_ADCAL) != 0U) {
    }
    osal_delay_microsec(ADCVREG_STUP_TIME_US);

    /* ADC activation.*/
    adp->adc->CR  = ADC_CR_ADVREGEN | ADC_CR_ADEN;
    while ((adp->adc->ISR & ADC_ISR_ADRDY) == 0U) {
    }
}

/**
 * @brief   ADC de-activation procedure.
 *
 * @param[in] adp       pointer to the @p adc_driver_t structure
 *
 * @notapi
 */
static void adc_deactivate(adc_driver_t *adp) {

    /* Disabling ADC.*/
    adp->adc->CR = ADC_CR_ADDIS;
    while ((adp->adc->CR & ADC_CR_ADDIS) != 0U) {
    }

    /* Deep sleep mode.*/
    adp->adc->CR = ADC_CR_DEEPPWD;
}

/*===========================================================================*/
/* Module exported functions.                                                */
/*===========================================================================*/

void adc_init(adc_driver_t *adp) {

    /* Set pointer to ADC register block.*/
    adp->adc = adc_dev_get_reg_ptr(adp);

    /* Set pointer to ADC common register block.*/
    adp->adc_common = adc_common_dev_get_reg_ptr(adp);

    /* Set ADC clock value based on clocktree configuration.*/
    adp->clock = adc_dev_get_clock(adp);

    /* Reset ADC parameters.*/
    adc_reset_paramters(adp);
}

adc_clk_mode_t adc_set_clk_mode(adc_driver_t *adp, adc_clk_mode_t clk_mode) {

    adc_clk_mode_t prev_clk_mode;

    prev_clk_mode = adp->clk_mode;
    adp->clk_mode = clk_mode;

    return prev_clk_mode;
}

adc_clk_presc_t adc_set_presc(adc_driver_t *adp, adc_clk_presc_t presc) {

    adc_clk_presc_t prev_presc;

    prev_presc = adp->presc;
    adp->presc = presc;

    return prev_presc;
}

adc_data_res_t adc_set_data_res(adc_driver_t *adp, adc_data_res_t data_res) {

    adc_data_res_t prev_data_res;

    prev_data_res = adp->data_res;
    adp->data_res = data_res;

    return prev_data_res;
}

uint32_t adc_set_prio(adc_driver_t *adp, uint32_t prio) {

    uint32_t prev_prio;

    prev_prio = adp->prio;
    adp->prio = prio;

    return prev_prio;
}

bool adc_set_interrupt_en(adc_driver_t *adp, bool is_interrupt_en) {

    bool prev_is_interrupt_en;

    prev_is_interrupt_en = adp->is_interrupt_en;
    adp->is_interrupt_en = is_interrupt_en;

    return prev_is_interrupt_en;
}

adc_dma_conf_t *adc_set_dma_conf(adc_driver_t *adp, adc_dma_conf_t *dma_conf) {

    adc_dma_conf_t *prev_dma_conf;

    prev_dma_conf = adp->dma_conf;
    adp->dma_conf = dma_conf;

    return prev_dma_conf;
}

adc_reg_mode_t adc_set_reg_mode(adc_driver_t *adp, adc_reg_mode_t reg_mode) {

    adc_reg_mode_t prev_reg_mode;

    prev_reg_mode = adp->reg_mode;
    adp->reg_mode = reg_mode;

    return prev_reg_mode;
}

void adc_set_ext(adc_driver_t *adp, adc_conv_t con_type, uint32_t ext,
                 adc_ext_pol_t ext_pol) {

    if (con_type == ADC_REG_CONV) {
        adp->reg_ext     = ext;
        adp->reg_ext_pol = ext_pol;
    } else {
        adp->inj_ext     = ext;
        adp->inj_ext_pol = ext_pol;
    }
}

void adc_reset_ext(adc_driver_t *adp, adc_conv_t con_type) {

    if (con_type == ADC_REG_CONV) {
        adp->reg_ext     = 0U;
        adp->reg_ext_pol = ADC_EXT_POL_DISABLED;
    } else {
        adp->inj_ext     = 0U;
        adp->inj_ext_pol = ADC_EXT_POL_DISABLED;
    }
}

void adc_set_seq(adc_driver_t *adp, adc_conv_t con_type, uint8_t n_channels,
                 uint8_t *seq, adc_sample_t *buffer) {

    if (con_type == ADC_REG_CONV) {
        adp->n_reg_channels = n_channels;
        adp->reg_seq        = seq;
        adp->reg_buffer     = buffer;
    } else {
        adp->n_inj_channels = n_channels;
        adp->inj_seq        = seq;
        adp->inj_buffer     = buffer;
    }
}

adc_smp_time_t adc_set_smp_time(adc_driver_t *adp, uint8_t ch,
                                adc_smp_time_t smp_time) {

    adc_smp_time_t prev_smp_time;

    prev_smp_time     = adp->smp_time[ch];
    adp->smp_time[ch] = smp_time;

    return prev_smp_time;
}

uint16_t adc_set_dif_sel(adc_driver_t *adp, uint16_t dif_mask) {

    uint16_t prev_dif_mask;

    prev_dif_mask = adp->dif_mask;
    adp->dif_mask = dif_mask;

    return prev_dif_mask;
}

uint32_t adc_set_aw_tr(adc_driver_t *adp, uint32_t watchdog, uint32_t aw_ltr,
                       uint32_t aw_htr) {

    uint32_t prev_aw_tr;

    prev_aw_tr = adp->aw_tr[(watchdog - 1U)];

    adp->aw_tr[watchdog] = ADC_TR(aw_ltr, aw_htr);

    return prev_aw_tr;
}

adc_cb_t adc_set_op_cb(adc_driver_t *adp, adc_op_t op, adc_cb_t op_cb) {

    adc_cb_t prev_op_cb;

    prev_op_cb     = adp->op_cb[op];
    adp->op_cb[op] = op_cb;

    return prev_op_cb;
}

adc_err_cb_t adc_set_err_cb(adc_driver_t *adp, adc_err_t err,
                            adc_err_cb_t err_cb) {

    adc_err_cb_t prev_err_cb;

    prev_err_cb     = adp->err_cb[err];
    adp->err_cb[err] = err_cb;

    return prev_err_cb;
}

void adc_start(adc_driver_t *adp) {

    uint32_t dma_mode = 0U;
    uint32_t cfgr = 0x80000000UL;
    uint32_t ier = 0U;
    IRQn_Type vector;
    uint32_t dma_trigger;
    uint8_t i;
    uint32_t smpr1 = 0U;
    uint32_t smpr2 = 0U;

    /* Enable clock.*/
    adc_dev_clock_enable(adp);

    /* Activate ADC.*/
    adc_activate(adp);

    /* ADC interrupt clearing.*/
    adp->adc->ISR = adp->adc->ISR;
    adp->adc->IER = 0U;

    /* Configure clock mode and prescaler.*/
    adp->adc_common->CCR = ((uint32_t)adp->clk_mode) << ADC_CCR_CKMODE_Pos |
                           ((uint32_t)adp->presc)    << ADC_CCR_PRESC_Pos;

    /* Configure data resolution.*/
    cfgr |= ((uint32_t)(adp->data_res)) << ADC_CFGR_RES_Pos;

    /* Enable analog watchdog interrupts.*/
    ier |= ADC_IER_AWD1IE | ADC_IER_AWD2IE | ADC_IER_AWD3IE;

    if (adp->is_interrupt_en == true) {
        /* Configure ADC interrupt vector.*/
        vector = adc_dev_get_vector(adp);
        irq_set_priority(vector, adp->prio);
        irq_enable(vector);
    }

    /* If enabled, configure regular conversion.*/
    if (adp->n_reg_channels > 0U) {

        uint8_t reg_seq_ch;
        uint32_t sqr1 = 0U;
        uint32_t sqr2 = 0U;
        uint32_t sqr3 = 0U;
        uint32_t sqr4 = 0U;

        /* Configure DMA for ADC regular conversions.*/
        dma_mode = DMA_CCR_PL_VALUE(adp->dma_conf->dma_stream_bus_prio) |
                   DMA_CCR_PSIZE_HWORD | DMA_CCR_MSIZE_HWORD            |
                   DMA_CCR_DIR_P2M     | DMA_CCR_MINC                   |
                   DMA_CCR_TCIE        | DMA_CCR_TEIE;
	    
        cfgr     |= ADC_CFGR_DMACFG | ADC_CFGR_DMAEN;
	    dma_mode |= DMA_CCR_CIRC;
        if (adp->reg_mode == ADC_REG_CONTINUOUS) {
            cfgr |= ADC_CFGR_CONT;
        }

        /* Allocates DMA streams for ADC regular conversions.*/
        /*lint -e9087 */
        adp->dma_descriptor = dma_stream_take(adp->dma_conf->dma_stream_id,
                                              adp->dma_conf->dma_stream_irq_prio,
                                              adc_dma_callback,
                                              (void *)adp);
        /*lint +e9087 */

        /* Configure DMA stream peripheral addresses.*/
        dma_stream_set_peripheral(adp->dma_descriptor, (uint32_t)(&adp->adc->DR));

        /* Configure DMA ADC trigger.*/
        dma_trigger = adc_dev_get_dma_trigger(adp);
        dma_stream_set_trigger(adp->dma_descriptor, dma_trigger);

        dma_stream_set_memory(adp->dma_descriptor, (uint32_t)(adp->reg_buffer));
        dma_stream_set_count(adp->dma_descriptor, adp->n_reg_channels);
        dma_stream_set_transfer_mode(adp->dma_descriptor, dma_mode);
        dma_stream_enable(adp->dma_descriptor);

        /* Configure ADC interrupts for regular conversions.*/
        ier |= ADC_IER_OVRIE;

        /* Configure ADC regular conversion external trigger.*/
        cfgr |= (uint32_t)(adp->reg_ext_pol) << ADC_CFGR_EXTEN_Pos |
                (uint32_t)(adp->reg_ext)     << ADC_CFGR_EXTSEL_Pos;

        /* Configure ADC regular conversion sequence.*/
        for (i = 0U; i < adp->n_reg_channels; i++) {
            reg_seq_ch = adp->reg_seq[i];
            if (i < 4U) {
                sqr1 |= ((uint32_t)reg_seq_ch) << ((i + 1U)  * 6U);		
            } else if (i < 9U) {
                sqr2 |= ((uint32_t)reg_seq_ch) << ((i - 4U)  * 6U);
            } else if (i < 14U) {
                sqr3 |= ((uint32_t)reg_seq_ch) << ((i - 9U)  * 6U);
            } else if (i < 16U) {
                sqr4 |= ((uint32_t)reg_seq_ch) << ((i - 15U) * 6U);
            } else {
                ; /* close "if" as required by MISRA */
            }
        }
        /* Configure regular conversion sequence number of channels.*/
        sqr1 |= ADC_SQR1_NUM_CH(adp->n_reg_channels);

        adp->adc->SQR1 = sqr1;
        adp->adc->SQR2 = sqr2;
        adp->adc->SQR3 = sqr3;
        adp->adc->SQR4 = sqr4;
    } else {
        /* Regular conversions disabled.*/
        if (adp->dma_descriptor != NULL) {
            /* Freeing and stopping DMA.*/
            dma_stream_free(adp->dma_descriptor);
            dma_stream_disable(adp->dma_descriptor);
		}
        adp->adc->SQR1 = 0U;
        adp->adc->SQR2 = 0U;
        adp->adc->SQR3 = 0U;
        adp->adc->SQR4 = 0U;
    }

    /* If enabled, configure injected conversion.*/
    if (adp->n_inj_channels > 0U) {

        uint8_t inj_seq_ch;
        uint32_t jsqr = 0U;

        /* Configure ADC interrupts for injected conversions.*/
        ier |= ADC_IER_JEOSIE;

        /* Configure ADC injected conversion external trigger.*/
        jsqr |= (uint32_t)(adp->inj_ext_pol) << ADC_JSQR_JEXTEN_Pos |
                (uint32_t)(adp->inj_ext)     << ADC_JSQR_JEXTSEL_Pos;

        /* Configure ADC injected conversion sequence.*/
        for (i = 0U; i < adp->n_inj_channels; i++) {
            inj_seq_ch = adp->inj_seq[i];
            jsqr |= ((uint32_t)inj_seq_ch) << (i * 6U + 9U);
        }

        /* Configure injected conversion sequence number of channels.*/
        jsqr |= ADC_JSQR_NUM_CH(adp->n_inj_channels);

        adp->adc->JSQR = jsqr;
    } else {
        adp->adc->JSQR = 0U;
    }

    /* Configure ADC watchdog thresholds.*/
    adp->adc->TR1     = adp->aw_tr[0];
    adp->adc->TR2     = adp->aw_tr[1];
    adp->adc->TR3     = adp->aw_tr[2];

    /* Configure ADC differential mode selection.*/
    adp->adc->DIFSEL  = adp->dif_mask;

    /* TODO: */
    //adp->adc->AWD2CR  = aop->AWD2CR;
    //adp->adc->AWD3CR  = aop->AWD3CR;

    /* Configure ADC channel sample times.*/
    for (i = 0U; i < (uint8_t)ADC_CH_NUM; i++) {
        if (i < 10U) {
            smpr1 |= ((uint32_t)adp->smp_time[i]) << (i  * 3U);
        } else {
            smpr2 |= ((uint32_t)adp->smp_time[i]) << ((i - 10U)  * 3U);
        }
    }
    adp->adc->SMPR1 = smpr1;
    adp->adc->SMPR2 = smpr2;

    /* Apply ADC configuration.*/
    adp->adc->CFGR  = cfgr;
    adp->adc->IER   = ier;
}

void adc_start_regular(adc_driver_t *adp) {

    adp->adc->CR |= ADC_CR_ADSTART;
}

void adc_start_injected(adc_driver_t *adp) {

    adp->adc->CR |= ADC_CR_JADSTART;
}

void adc_stop_regular(adc_driver_t *adp) {

    if ((adp->adc->CR & ADC_CR_ADSTART) != 0U) {
        adp->adc->CR |= ADC_CR_ADSTP;
        while ((adp->adc->CR & ADC_CR_ADSTP) != 0U) {
        }
        adp->adc->IER = 0U;
    }
}

void adc_stop_injected(adc_driver_t *adp) {

    if ((adp->adc->CR & ADC_CR_JADSTART) != 0U) {
        adp->adc->CR |= ADC_CR_JADSTP;
        while ((adp->adc->CR & ADC_CR_JADSTP) != 0U) {
        }
        adp->adc->IER = 0U;
    }
}

void adc_stop(adc_driver_t *adp) {

    uint32_t isr;
    IRQn_Type vector;

    /* Clearing IRQ sources for this ADC.*/
    isr = adp->adc->ISR;
    adp->adc->ISR = isr;

    /* If enabled, stop regular conversions.*/
    if (adp->n_reg_channels > 0U) {
        adc_stop_regular(adp);

        /* If a regular conversion is stopped, the bits CONT in CFGR register must
           be cleared before the DMA stream disable.*/
        adp->adc->CFGR &= ~ADC_CFGR_DMACFG;
        /* If a regular conversion in continuos mode is stopped, the bits CONT in
           CFGR register must be cleared before the DMA stream disable.*/
        if (adp->reg_mode == ADC_REG_CONTINUOUS) {
            adp->adc->CFGR &= ~ADC_CFGR_CONT;
        }
        /* Free and stop ADC DMA stream.*/
        dma_stream_free(adp->dma_descriptor);
        dma_stream_disable(adp->dma_descriptor);

    }

    /* If enabled, stop injected conversions.*/
    if (adp->n_inj_channels > 0U) {
        adc_stop_injected(adp);
    }

    if (adp->is_interrupt_en == true) {
        /* Disable ADC interrupt.*/
        vector = adc_dev_get_vector(adp);
        irq_disable(vector);
    }

    /* Clear ADC registers.*/
    adp->adc->IER     = 0U;
    adp->adc->CFGR    = 0x80000000UL;
    adp->adc->SMPR1   = 0x0UL;
    adp->adc->SMPR2   = 0x0UL;
    adp->adc->TR1     = 0x0FFF0000UL;
    adp->adc->TR2     = 0x0FFF0000UL;
    adp->adc->TR3     = 0x0FFF0000UL;
    adp->adc->SQR1    = 0x0UL;
    adp->adc->SQR2    = 0x0UL;
    adp->adc->SQR3    = 0x0UL;
    adp->adc->SQR4    = 0x0UL;
    adp->adc->JSQR    = 0x0UL;
    adp->adc->DIFSEL  = 0x0UL;

    /* Deactivate ADC.*/
    adc_deactivate(adp);

    /* Disable ADC clock.*/
    adc_dev_clock_disable(adp);
}

void adc_deinit(adc_driver_t *adp) {

    /* Set pointer to ADC register block to NULL.*/
    adp->adc = NULL;

    /* Set pointer to ADC common register block to NULL.*/
    adp->adc_common = NULL;

    /* Set ADC clock value to default value.*/
    adp->clock = 0U;

    /* Reset ADC parameters.*/
    adc_reset_paramters(adp);
}

uint32_t adc_get_clock(adc_driver_t *adp) {

    uint32_t clk_mode, presc;
    uint32_t presc_value = 1U;

    clk_mode = (adp->adc_common->CCR & ADC_CCR_CKMODE_Msk) >> ADC_CCR_CKMODE_Pos;
    presc    = (adp->adc_common->CCR & ADC_CCR_PRESC_Msk) >> ADC_CCR_PRESC_Pos;

    switch (presc) {
        case (uint32_t)(ADC_CLK_PRESC_DIV_1):
            presc_value = 1U;
            break;
        case (uint32_t)(ADC_CLK_PRESC_DIV_2):
            presc_value = 2U;
            break;
        case (uint32_t)(ADC_CLK_PRESC_DIV_4):
            presc_value = 4U;
            break;
        case (uint32_t)(ADC_CLK_PRESC_DIV_6):
            presc_value = 6U;
            break;
        case (uint32_t)(ADC_CLK_PRESC_DIV_8):
            presc_value = 8U;
            break;
        case (uint32_t)(ADC_CLK_PRESC_DIV_10):
            presc_value = 10U;
            break;
        case (uint32_t)(ADC_CLK_PRESC_DIV_12):
            presc_value = 12U;
            break;
        case (uint32_t)(ADC_CLK_PRESC_DIV_16):
            presc_value = 16U;
            break;
        case (uint32_t)(ADC_CLK_PRESC_DIV_32):
            presc_value = 32U;
            break;
        case (uint32_t)(ADC_CLK_PRESC_DIV_64):
            presc_value = 64U;
            break;
        case (uint32_t)(ADC_CLK_PRESC_DIV_128):
            presc_value = 128U;
            break;
        default:
            presc_value = 256U;
            break;
    }

    switch (clk_mode) {
        case (uint32_t)(ADC_CLK_MODE_ADCCLK):
            return (adp->clock / presc_value);
        case (uint32_t)(ADC_CLK_MODE_AHB_DIV2):
            return (CLOCK_SYSCLKDIV / 2U);
        case (uint32_t)(ADC_CLK_MODE_AHB_DIV4):
            return (CLOCK_SYSCLKDIV / 4U);
        default:
            return 0U;
    }
}

void __adc_serve_interrupt(adc_driver_t *adp) {

    uint32_t isr;

    /* Clearing IRQ sources for this ADC.*/
    isr = adp->adc->ISR;
    adp->adc->ISR = isr;

    /* Overflow critical error (only for regular conversions, that use DMA).*/
    if (adp->dma_descriptor != NULL) {
        if (dma_stream_is_enabled(adp->dma_descriptor)!= true && (isr & ADC_ISR_OVR) != 0U) {
            adc_critical_error_event(adp, ADC_ERR_OVF);
        }
    }

    /* Injected channel end of sequence.*/
    if ((isr & ADC_ISR_JEOS) != 0U) {
        uint8_t i;
        vuint32_t *jdr = (vuint32_t *)(&adp->adc->JDR1);
        for(i = 0U; i < adp->n_inj_channels; i++) {
            adp->inj_buffer[i] = (adc_sample_t)(jdr[i]);
        }
        adc_data_full_event_injected(adp);
    }

    /* AWD1 event.*/
    if ((isr & ADC_ISR_AWD1) != 0U) {
        adc_normal_error_event(adp, ADC_ERR_AWD1);
    }

    /* AWD2 event.*/
    if ((isr & ADC_ISR_AWD2) != 0U) {
        adc_normal_error_event(adp, ADC_ERR_AWD1);
    }

    /* AWD3 event.*/
    if ((isr & ADC_ISR_AWD3) != 0U) {
        adc_normal_error_event(adp, ADC_ERR_AWD1);
    }
}

/** @} */
