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
 * @file    sdadc.c
 * @brief   SDADC driver source file.
 *
 * @addtogroup DRIVERS
 * @addtogroup ANALOG
 * @ingroup DRIVERS
 * @addtogroup SDADC
 * @ingroup ANALOG
 * @{
 */

#include <sdadc.h>
#include <sdadc_private.h>

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
 * @brief   Resets SDADC parameters.
 *
 * @param[out] sdp      pointer to an @p sdadc_driver_t structure
 *
 * @notapi
 */
static void sdadc_reset_paramters(sdadc_driver_t *sdp) {

    sdp->prio               = IRQ_MIN_PRIORITY;
    sdp->vrefn              = 0.0f;
    sdp->vrefp              = 0.0f;
    sdp->calibration        = SDADC_CALIBRATION_BOTH;
    sdp->mode               = SDADC_MODE_DIFFERENTIAL_INPUT;
    sdp->vcomsel            = SDADC_VCOMSEL_VREFN;
    sdp->anchsel            = SDADC_ANCHSEL_0;
    sdp->pdr                = SDADC_PDR_24;
    sdp->pgain              = SDADC_PGAIN_1;
    sdp->is_hpass_en        = false;
    sdp->is_bias_en         = false;
    sdp->osd                = 0U;
    sdp->fsize              = SDADC_FIFO_SIZE_16;
    sdp->is_fifo_ow_en      = false;
    sdp->is_fifo_full_en    = false;
    sdp->fifo_threshold     = 0;
    sdp->fifo_full_cb       = NULL;
    sdp->is_fifo_overrun_en = false;
    sdp->fifo_overrun_cb    = NULL;
    sdp->is_watchdog_en     = false;
    sdp->watchdog_lowth     = 0.0f;
    sdp->watchdog_highth    = 0.0f;
    sdp->watchdog_cb        = NULL;
    sdp->offset_calibration = 0.0f;
    sdp->gain_calibration   = 1.0f;
}

/**
 * @brief   Performs Offset calibration
 *
 * @param[out] sdp      pointer to an @p sdadc_driver_t structure
 * @return              Offset calibration value
 *
 * @notapi
 */
static float sdadc_offset_calibration(sdadc_driver_t *sdp) {

    int32_t calibration_value = 0;
    int16_t converted_value;
    uint8_t counter;
    int16_t temp[16];
  
    /* Flush FIFO */
    sdp->sdadc->SDADC_FCR |= SDADC_SDADC_FCR_FRST;
    /* Reset Fifo Overrun flag.*/
    sdp->sdadc->SDADC_SFR |= SDADC_SDADC_SFR_DFORF;
    /* Reset FIFO Full flag.*/
    sdp->sdadc->SDADC_SFR |= SDADC_SDADC_SFR_DFFF;
    /* Enable FIFO.*/
    sdp->sdadc->SDADC_FCR |= SDADC_SDADC_FCR_FE;
    /* Set FIFO size to 16byte.*/
    sdp->sdadc->SDADC_FCR &=~ SDADC_SDADC_FCR_FSIZE;
    sdp->sdadc->SDADC_FCR |= SDADC_FCR_FSIZE(SDADC_FIFO_SIZE_16);
    /* Set FIFO threshold to 16 byte.*/
    sdp->sdadc->SDADC_FCR &=~ SDADC_SDADC_FCR_FTHLD; 
    sdp->sdadc->SDADC_FCR |= SDADC_FCR_THRESHOLD(16U);
    /* Set output settling time.*/
    sdp->sdadc->SDADC_OSDR &=~SDADC_SDADC_OSDR_OSD;
    sdp->sdadc->SDADC_OSDR |= SDADC_OSDR_OSD(0xFFU);
    /* Set gain used to calculate offset calibration.*/
    sdp->sdadc->SDADC_MCR &=~SDADC_SDADC_MCR_PGAN;
    sdp->sdadc->SDADC_MCR |= SDADC_MCR_PGAIN(sdp->pgain);
    /* Disable gain error mode.*/
    sdp->sdadc->SDADC_MCR &=~(SDADC_SDADC_MCR_GECEN);
    /* Select differential mode.*/
    sdp->sdadc->SDADC_MCR &=~ SDADC_SDADC_MCR_MODE;
    sdp->sdadc->SDADC_MCR |= SDADC_MCR_MODE(SDADC_MODE_DIFFERENTIAL_INPUT);
    /* Select channel to convert depending on which type of conversion will be
       performed after calibration.*/
    if (sdp->mode == SDADC_MODE_SINGLE_ENDED_INPUT && sdp->vcomsel == SDADC_VCOMSEL_VREFN) {
        sdp->sdadc->SDADC_CSR &=~ SDADC_SDADC_CSR_ANCHSEL;
        /* Set channel selection (VREFN - VREFN).*/
        sdp->sdadc->SDADC_CSR |= SDADC_CSR_ANCHSEL(4U);
    } else {
        /* Set channel selection (VREFP/2 - VREFP/2).*/
        sdp->sdadc->SDADC_CSR &=~ SDADC_SDADC_CSR_ANCHSEL;
        sdp->sdadc->SDADC_CSR |= SDADC_CSR_ANCHSEL(5U);
    }
    /* Disable BIAS on all inputs.*/
    sdp->sdadc->SDADC_CSR &=~(SDADC_SDADC_CSR_BIASEN);
    /* Disable high pass filter.*/
    sdp->sdadc->SDADC_MCR &=~(SDADC_SDADC_MCR_HPFEN);
    /* Enable SDADC module.*/
    sdp->sdadc->SDADC_MCR |= SDADC_SDADC_MCR_EN;
    /* Start conversion.*/
    sdp->sdadc->SDADC_RKR = SDADC_SDADC_RKR_RESET_KEY & 0x5AF0U;
    /* Wait til converted data is ready.*/
    while ((sdp->sdadc->SDADC_SFR & SDADC_SDADC_SFR_DFFF) == 0U) {
    }

    for (counter = 0U; counter < 16U; counter++) {
        /* Read data.*/
        temp[counter] = (int16_t)((uint16_t)sdp->sdadc->SDADC_CDR);
        converted_value = temp[counter];
        /* Calculate offset calibration.*/
        calibration_value += (0 - (int32_t)converted_value);
    }

    /* Disable SDADC module.*/
    sdp->sdadc->SDADC_MCR &= ~(SDADC_SDADC_MCR_EN);

    /* Return average value of calibration value.*/
    return (float)calibration_value / (float)16U;
}

/**
 * @brief   Performs GAIN calibration
 *
 * @param[out] sdp      pointer to an @p sdadc_driver_t structure
 * @return              GAIN calibration value
 *
 * @notapi
 */
static float sdadc_gain_calibration(sdadc_driver_t *sdp) {

    uint8_t counter;
    int32_t calibration_value;
    float calculated_gain;
    float dp, dn;
    int16_t temp[16];

    /* Flush FIFO.*/
    sdp->sdadc->SDADC_FCR |= SDADC_SDADC_FCR_FRST;
    /* Reset Fifo Overrun flag.*/
    sdp->sdadc->SDADC_SFR |= SDADC_SDADC_SFR_DFORF;
    /*Reset FIFO Full flag.*/
    sdp->sdadc->SDADC_SFR |= SDADC_SDADC_SFR_DFFF;
    /* Enable FIFO.*/
    sdp->sdadc->SDADC_FCR |= SDADC_SDADC_FCR_FE;
    /* Set FIFO size to 16byte.*/
    sdp->sdadc->SDADC_FCR &=~ SDADC_SDADC_FCR_FSIZE;
    sdp->sdadc->SDADC_FCR |= SDADC_FCR_FSIZE(SDADC_FIFO_SIZE_16);
    /* Set FIFO threshold to 16 byte.*/
    sdp->sdadc->SDADC_FCR &=~ SDADC_SDADC_FCR_FTHLD;
    sdp->sdadc->SDADC_FCR |= SDADC_FCR_THRESHOLD(16U);
    /* Set output settling time.*/
    sdp->sdadc->SDADC_OSDR &=~SDADC_SDADC_OSDR_OSD;
    sdp->sdadc->SDADC_OSDR |= SDADC_OSDR_OSD(0xFFU);
    /* Set programmable decimation rate */
    sdp->sdadc->SDADC_MCR &=~ SDADC_SDADC_MCR_PDR;
    sdp->sdadc->SDADC_MCR |= SDADC_MCR_PDR(sdp->pdr);
    /* Set gain 1 used to calculate gain calibration.*/
    sdp->sdadc->SDADC_MCR &=~(SDADC_SDADC_MCR_PGAN);
    sdp->sdadc->SDADC_MCR |= SDADC_MCR_PGAIN(SDADC_PGAIN_1);
    /* Enable gain error mode.*/
    sdp->sdadc->SDADC_MCR |= SDADC_SDADC_MCR_GECEN;
    /* Set differential mode.*/
    sdp->sdadc->SDADC_MCR &=~ SDADC_SDADC_MCR_MODE;
    sdp->sdadc->SDADC_MCR |=  SDADC_MCR_MODE(SDADC_MODE_DIFFERENTIAL_INPUT);
    /* Disable BIAS on all inputs.*/
    sdp->sdadc->SDADC_CSR &= ~(SDADC_SDADC_CSR_BIASEN);
    /* Disable high pass filter.*/
    sdp->sdadc->SDADC_MCR &= ~(SDADC_SDADC_MCR_HPFEN);
    /* Set channel selection (VREFP - VREFN).*/
    sdp->sdadc->SDADC_CSR &=~ SDADC_SDADC_CSR_ANCHSEL;
    sdp->sdadc->SDADC_CSR |= SDADC_CSR_ANCHSEL(6U);
    /* Enable SDADC module.*/
    sdp->sdadc->SDADC_MCR |= SDADC_SDADC_MCR_EN;
    /* Start conversion.*/
    sdp->sdadc->SDADC_RKR = SDADC_SDADC_RKR_RESET_KEY & 0x5AF0U;
    /* Wait til converted data is ready.*/
    while ((sdp->sdadc->SDADC_SFR & SDADC_SDADC_SFR_DFFF) == 0U) {
    }
    /* Expected output if there is no gain error is 0b0111_1001_1001_1001,
       corresponding to full positive scale after attenuation inserted by the
       internal filter (1*0.95). The measurement should be repeated to reduce
       contribution of noise during calibration process. Dp is the average
       value of attenuated positive full scale.*/
    calibration_value = 0;
    for (counter = 0U; counter < 16U; counter++) {
        temp[counter] = (int16_t)((uint16_t)sdp->sdadc->SDADC_CDR);
        calibration_value += temp[counter];
    }

    dp = (float)calibration_value / (float)16U;

    /* Disable SDADC module.*/
    sdp->sdadc->SDADC_MCR &=~(SDADC_SDADC_MCR_EN);
    /* Flush FIFO.*/
    sdp->sdadc->SDADC_FCR |= SDADC_SDADC_FCR_FRST;
    /* Reset FIFO Overrun flag.*/
    sdp->sdadc->SDADC_SFR |= SDADC_SDADC_SFR_DFORF;
    /* Reset FIFO Full flag.*/
    sdp->sdadc->SDADC_SFR |= SDADC_SDADC_SFR_DFFF;
    /* Set channel selection (VREFN - VREFP).*/
    sdp->sdadc->SDADC_CSR &=~ SDADC_SDADC_CSR_ANCHSEL;
    sdp->sdadc->SDADC_CSR |= SDADC_CSR_ANCHSEL(7U);
    /* Enable SDADC module.*/
    sdp->sdadc->SDADC_MCR |= SDADC_SDADC_MCR_EN;
    /* Start conversion.*/
    sdp->sdadc->SDADC_RKR = SDADC_SDADC_RKR_RESET_KEY & 0x5AF0U;

    /* Wait till converted data is ready.*/
    while ((sdp->sdadc->SDADC_SFR & SDADC_SDADC_SFR_DFFF) == 0U) {
    }
    /* Expected output if there is no gain error is 0b1000_0110_0110_0110,
       corresponding to full negative scale after attenuation inserted by the
       internal filter (-1*0.95). The measurement should be repeated to reduce
       contribution of noise during calibration process. Dn is the average
       value of attenuated negative full scale.*/
    calibration_value = 0;
    for (counter = 0U; counter < 16U; counter++) {
        temp[counter] = (int16_t)((uint16_t)sdp->sdadc->SDADC_CDR);
        calibration_value += temp[counter];
    }

    dn = (float)calibration_value / (float)16U;

    calculated_gain = (dp - dn) / (float)65536U;

    /* Disable SDADC module.*/
    sdp->sdadc->SDADC_MCR &=~(SDADC_SDADC_MCR_EN);

    return calculated_gain;
}

/*===========================================================================*/
/* Module exported functions.                                                */
/*===========================================================================*/

void sdadc_init(sdadc_driver_t *sdp) {

    /* Set pointer to SDADC register block.*/
    sdp->sdadc = sdadc_dev_get_reg_ptr(sdp);

    /* Reset SDADC parameters.*/
    sdadc_reset_paramters(sdp);
}

uint32_t sdadc_set_prio(sdadc_driver_t *sdp, uint32_t prio) {

    uint32_t prev_prio;

    prev_prio = sdp->prio;
    sdp->prio = prio;

    return prev_prio;
}

float sdadc_set_ground(sdadc_driver_t *sdp, float gnd_ref) {

    float prev_vrefn;

    prev_vrefn = sdp->vrefn;
    sdp->vrefn = gnd_ref;

    return prev_vrefn;
}

float sdadc_get_ground(sdadc_driver_t *sdp) {

    return sdp->vrefn;
}

float sdadc_set_voltage(sdadc_driver_t *sdp, float vol_ref) {

    float prev_vrefp;

    prev_vrefp = sdp->vrefp;
    sdp->vrefp = vol_ref;

    return prev_vrefp;
}

float sdadc_get_voltage(sdadc_driver_t *sdp) {

    return sdp->vrefp;
}

sdadc_calibration_t sdadc_set_calibration(sdadc_driver_t *sdp, sdadc_calibration_t calibration) {

    sdadc_calibration_t prev_calibration;

    prev_calibration = sdp->calibration;
    sdp->calibration = calibration;

    return prev_calibration;
}

sdadc_mode_t sdadc_set_mode(sdadc_driver_t *sdp, sdadc_mode_t mode) {

    sdadc_mode_t prev_mode;

    prev_mode = sdp->mode;
    sdp->mode = mode;

    return prev_mode;
}

sdadc_vcomsel_t sdadc_set_common_bias(sdadc_driver_t *sdp, sdadc_vcomsel_t bias) {

    sdadc_vcomsel_t prev_vcomsel;

    prev_vcomsel = sdp->vcomsel;
    sdp->vcomsel = bias;

    return prev_vcomsel;
}

sdadc_anchsel_t sdadc_set_channel(sdadc_driver_t *sdp, sdadc_anchsel_t anchsel) {

    sdadc_anchsel_t prev_anchsel;

    prev_anchsel = sdp->anchsel;
    sdp->anchsel = anchsel;

    return prev_anchsel;
}

sdadc_pdr_t sdadc_set_pdr(sdadc_driver_t *sdp, sdadc_pdr_t pdr) {

    sdadc_pdr_t prev_pdr;

    prev_pdr = sdp->pdr;
    sdp->pdr = pdr;

    return prev_pdr;
}

sdadc_pgain_t sdadc_set_pgain(sdadc_driver_t *sdp, sdadc_pgain_t pgain) {

    sdadc_pgain_t prev_pgain;

    prev_pgain = sdp->pgain;
    sdp->pgain = pgain;

    return prev_pgain;
}

bool sdadc_enable_highpass(sdadc_driver_t *sdp) {

    bool prev_is_hpass_en;

    prev_is_hpass_en = sdp->is_hpass_en;
    sdp->is_hpass_en = true;

    return prev_is_hpass_en;
}

bool sdadc_enable_bias(sdadc_driver_t *sdp) {

    bool prev_is_bias_en;

    prev_is_bias_en = sdp->is_bias_en;
    sdp->is_bias_en = true;

    return prev_is_bias_en;
}

uint8_t sdadc_set_osd(sdadc_driver_t *sdp, uint8_t osd) {

    uint8_t prev_osd;

    prev_osd = sdp->osd;
    sdp->osd = osd;

    return prev_osd;
}

sdadc_fsize_t sdadc_set_fsize(sdadc_driver_t *sdp, sdadc_fsize_t fsize) {

    sdadc_fsize_t prev_fsize;

    prev_fsize = sdp->fsize;
    sdp->fsize = fsize;

    return prev_fsize;
}

bool sdadc_enable_fifo_overwrite(sdadc_driver_t *sdp) {

    bool prev_is_fifo_ow_en;

    prev_is_fifo_ow_en = sdp->is_fifo_ow_en;
    sdp->is_fifo_ow_en = true;

    return prev_is_fifo_ow_en;
}

void sdadc_enable_fifo_full_event(sdadc_driver_t *sdp, uint8_t fifo_threshold,
                                  sdadc_cb_t fifo_full_cb) {

    sdp->is_fifo_full_en = true;
    sdp->fifo_threshold = fifo_threshold;
    sdp->fifo_full_cb = fifo_full_cb;
}

void sdadc_enable_fifo_overrun_event(sdadc_driver_t *sdp,
                                     sdadc_cb_t fifo_overrun_cb) {

    sdp->is_fifo_overrun_en = true;
    sdp->fifo_overrun_cb = fifo_overrun_cb;
}

void sdadc_enable_watchdog_event(sdadc_driver_t *sdp, float watchdog_lowth,
                                 float watchdog_highth, sdadc_cb_t watchdog_cb) {

    sdp->is_watchdog_en = true;
    sdp->watchdog_lowth = watchdog_lowth;
    sdp->watchdog_highth = watchdog_highth;
    sdp->watchdog_cb = watchdog_cb;
}

void sdadc_start(sdadc_driver_t *sdp) {

    IRQn_Type vector;

    /* Enable clock.*/
    sdadc_dev_clock_enable(sdp);

    /* Configure SDADC interrupt vector.*/
    vector = sdadc_dev_get_vector(sdp);
    irq_set_priority(vector, sdp->prio);
    irq_enable(vector);

    sdp->offset_calibration = 0.0f;
    sdp->gain_calibration   = 1.0f;
    /* Perform offset calibration if configured.*/
    if ((sdp->calibration == SDADC_CALIBRATION_OFFSET) ||
        (sdp->calibration == SDADC_CALIBRATION_BOTH)) {
        sdp->offset_calibration = sdadc_offset_calibration(sdp);
    }
    /* Perform gain calibration if configured.*/
    if ((sdp->calibration == SDADC_CALIBRATION_GAIN) ||
        (sdp->calibration == SDADC_CALIBRATION_BOTH)) {
        sdp->gain_calibration = sdadc_gain_calibration(sdp);
    }

    /* Flush FIFO.*/
    sdp->sdadc->SDADC_FCR |= SDADC_SDADC_FCR_FRST;
    /* Reset FIFO overrun flag.*/
    sdp->sdadc->SDADC_SFR |= SDADC_SDADC_SFR_DFORF;
    /* Reset FIFO Full flag.*/
    sdp->sdadc->SDADC_SFR |= SDADC_SDADC_SFR_DFFF;

    /* Configure conversion mode.*/
    sdp->sdadc->SDADC_MCR &=~ SDADC_SDADC_MCR_MODE;
    sdp->sdadc->SDADC_MCR |= SDADC_MCR_MODE(sdp->mode);

    /* Configure common voltage BIAS selection.*/
    sdp->sdadc->SDADC_MCR &=~SDADC_SDADC_MCR_VCOMSEL;
    sdp->sdadc->SDADC_MCR |= SDADC_MCR_VCOMSEL(sdp->vcomsel);

    /* Configure channel selection.*/
    sdp->sdadc->SDADC_CSR &=~ SDADC_SDADC_CSR_ANCHSEL;
    sdp->sdadc->SDADC_CSR |= SDADC_CSR_ANCHSEL(sdp->anchsel);

    /* Configure programmable gain.*/
    sdp->sdadc->SDADC_MCR &=~SDADC_SDADC_MCR_PGAN;
    sdp->sdadc->SDADC_MCR |= SDADC_MCR_PGAIN(sdp->pgain);

    /* Enable gain error calibration mode.*/
    sdp->sdadc->SDADC_MCR |= SDADC_SDADC_MCR_GECEN;

    /* Configure output settling time.*/
    sdp->sdadc->SDADC_OSDR &=~SDADC_SDADC_OSDR_OSD;
    sdp->sdadc->SDADC_OSDR |= SDADC_OSDR_OSD(sdp->osd);

    /* Configure programmable decimation rate.*/
    sdp->sdadc->SDADC_MCR &=~ SDADC_SDADC_MCR_PDR;
    sdp->sdadc->SDADC_MCR |= SDADC_MCR_PDR(sdp->pdr);

	/* Configure highpass filter.*/
    sdp->sdadc->SDADC_MCR &=~ SDADC_SDADC_MCR_HPFEN;
    if (sdp->is_hpass_en == true) {
        sdp->sdadc->SDADC_MCR |= SDADC_SDADC_MCR_HPFEN;
    }

    /* Configure BIAS enable.*/
    sdp->sdadc->SDADC_CSR &=~ SDADC_SDADC_CSR_BIASEN;
    if (sdp->is_bias_en == true) {
        sdp->sdadc->SDADC_CSR |= SDADC_SDADC_CSR_BIASEN;
    }

    /* Configure FIFO.*/
    sdp->sdadc->SDADC_FCR |= SDADC_SDADC_FCR_FE;
    sdp->sdadc->SDADC_FCR &=~ SDADC_SDADC_FCR_FOWEN;
    if (sdp->is_fifo_ow_en == true) {
        sdp->sdadc->SDADC_FCR |= SDADC_SDADC_FCR_FOWEN;
    }

    /* Configure FIFO size.*/
    sdp->sdadc->SDADC_FCR &=~ SDADC_SDADC_FCR_FSIZE;
    sdp->sdadc->SDADC_FCR |= SDADC_FCR_FSIZE(sdp->fsize);

    /* Configure FIFO full event.*/
    sdp->sdadc->SDADC_RSER &=~SDADC_SDADC_RSER_DFFDIRE;
    if (sdp->is_fifo_full_en == true) {
        sdp->sdadc->SDADC_FCR &=~ SDADC_SDADC_FCR_FTHLD;
        sdp->sdadc->SDADC_FCR |= SDADC_FCR_THRESHOLD(sdp->fifo_threshold);
        sdp->sdadc->SDADC_RSER |=SDADC_SDADC_RSER_DFFDIRE;
    }

    /* Configure FIFO overrun event.*/
    sdp->sdadc->SDADC_RSER &=~ SDADC_SDADC_RSER_DFORIE;
    if (sdp->is_fifo_overrun_en == true) {
        sdp->sdadc->SDADC_RSER |= SDADC_SDADC_RSER_DFORIE;
    }

    /* Configure watchdog.*/
    if (sdp->is_watchdog_en == true) {
        float step;
        float thr;
        uint16_t low;
        uint16_t high;
        /* Enable watchdog.*/
        sdp->sdadc->SDADC_MCR |= SDADC_SDADC_MCR_WDGEN;
        /* Set low threshold.*/
        step = (float)32768U / (sdp->vrefp - sdp->vrefn);
        thr = (step * sdp->watchdog_lowth * sdp->gain_calibration) - sdp->offset_calibration;
        low = (uint16_t)thr;
        sdp->sdadc->SDADC_WTHHLR &=~SDADC_SDADC_WTHHLR_THRL;
        sdp->sdadc->SDADC_WTHHLR |= SDADC_WTHHLR_THHL(low);
        /* Set high threshold.*/
        thr = (step * sdp->watchdog_highth * sdp->gain_calibration) - sdp->offset_calibration;
        high = (uint16_t)thr;
        sdp->sdadc->SDADC_WTHHLR &=~ SDADC_SDADC_WTHHLR_THRH;
        sdp->sdadc->SDADC_WTHHLR |= SDADC_WTHHLR_THHH(high);
        /* Enable interrupt.*/
        sdp->sdadc->SDADC_RSER |= SDADC_SDADC_RSER_WTHDIRE;
    }
}

void sdadc_start_conversion(sdadc_driver_t *sdp)
{
    /* Start Conversion */
    sdp->sdadc->SDADC_MCR |= SDADC_SDADC_MCR_EN;
    sdp->sdadc->SDADC_RKR = SDADC_SDADC_RKR_RESET_KEY & 0x5AF0U;
}

void sdadc_stop_conversion(sdadc_driver_t *sdp)
{
    /* Stop conversion by powering down ADC module.*/
    sdp->sdadc->SDADC_MCR &=~(SDADC_SDADC_MCR_EN);

    /* Flush FIFO.*/
    sdp->sdadc->SDADC_FCR |= SDADC_SDADC_FCR_FRST;

    /* Reset Data FIFO overrun flag.*/
    sdp->sdadc->SDADC_SFR |= SDADC_SDADC_SFR_DFORF;

    /*Reset Data FIFO Full Flag.*/
    sdp->sdadc->SDADC_SFR |= SDADC_SDADC_SFR_DFFF;
}

bool sdadc_read(sdadc_driver_t *sdp, float *value)
{
    int16_t data;
  
    /* Check if valid data is available.*/
    if ((sdp->sdadc->SDADC_SFR & SDADC_SDADC_SFR_DFEF) == 0U) {
        /* Read converted data.*/
        data = (int16_t)((uint16_t)sdp->sdadc->SDADC_CDR);
        /* Apply calibration.*/
        *value = (float)data + sdp->offset_calibration;
        *value = (*value) / sdp->gain_calibration;
        return true;
    }

    return false;
}

float sdadc_get_offset_calibration(sdadc_driver_t *sdp) {

    return sdp->offset_calibration;
}

float sdadc_get_gain_calibration(sdadc_driver_t *sdp) {

    return sdp->gain_calibration;
}

void sdadc_stop(sdadc_driver_t *sdp) {

    IRQn_Type vector;

    /* Power Down SDADC */
    sdp->sdadc->SDADC_MCR &=~(SDADC_SDADC_MCR_EN);

    /* Disable ADC interrupt.*/
    vector = sdadc_dev_get_vector(sdp);
    irq_disable(vector);

    /* Clear SDADC registers.*/
    sdp->sdadc->SDADC_MCR    = 0x00000000UL;
    sdp->sdadc->SDADC_CSR    = 0x00000000UL;
    sdp->sdadc->SDADC_RSER   = 0x00000000UL;
    sdp->sdadc->SDADC_OSDR   = 0x00000000UL;
    sdp->sdadc->SDADC_FCR    = 0x00000006UL;
    sdp->sdadc->SDADC_WTHHLR = 0x00000000UL;

    sdp->sdadc->SDADC_SFR   |= SDADC_SDADC_SFR_DFFF;
    sdp->sdadc->SDADC_SFR   |= SDADC_SDADC_SFR_DFORF;
    sdp->sdadc->SDADC_SFR   |= SDADC_SDADC_SFR_WTHL;
    sdp->sdadc->SDADC_SFR   |= SDADC_SDADC_SFR_WTHH;

    /* Disable ADC clock.*/
    sdadc_dev_clock_disable(sdp);
}

void sdadc_deinit(sdadc_driver_t *sdp) {

    /* Set pointer to SDADC register block to NULL.*/
    sdp->sdadc = NULL;

    /* Reset SDADC parameters.*/
    sdadc_reset_paramters(sdp);
}

void __sdadc_serve_interrupt(sdadc_driver_t *sdp) {

    uint32_t sfr = sdp->sdadc->SDADC_SFR;

    /* Check FIFO full event.*/
    if ((sfr & SDADC_SDADC_SFR_DFFF) != 0U) {
        /* callback*/
        if (sdp->fifo_full_cb != NULL) {
            sdp->fifo_full_cb(sdp);
        }
        /* Clear FIFO full event flag.*/
        sdp->sdadc->SDADC_SFR |= SDADC_SDADC_SFR_DFFF;
    }
    /* Check FIFO overrun event.*/
    if ((sfr & SDADC_SDADC_SFR_DFORF) != 0U) {
        /* callback*/
        if (sdp->fifo_overrun_cb != NULL) {
            sdp->fifo_overrun_cb(sdp);
        }
        /* Clear FIFO overrun event flag.*/
        sdp->sdadc->SDADC_SFR |= SDADC_SDADC_SFR_DFORF;
    }
    /* Check watchdog event.*/
    if (((sfr & SDADC_SDADC_SFR_WTHH) != 0U) ||
        ((sfr & SDADC_SDADC_SFR_WTHL) != 0U)) {
        if (sdp->watchdog_cb != NULL) {
            sdp->watchdog_cb(sdp);
        }
        /* Clear watchdog event flags.*/
        sdp->sdadc->SDADC_SFR |= SDADC_SDADC_SFR_WTHH;
        sdp->sdadc->SDADC_SFR |= SDADC_SDADC_SFR_WTHL;
    }
}

/** @} */
