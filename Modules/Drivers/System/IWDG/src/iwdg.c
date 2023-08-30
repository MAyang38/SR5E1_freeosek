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
 * @file    iwdg.c
 * @brief   IWDG driver source file.
 *
 * @addtogroup DRIVERS
 * @addtogroup SYSTEM
 * @ingroup DRIVERS
 * @addtogroup IWDG
 * @ingroup SYSTEM
 * @{
 */

#include <iwdg.h>
#include <iwdg_private.h>

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
 * @brief   Resets IWDG parameters.
 *
 * @param[out] idp      pointer to an @p iwdg_driver_t structure
 *
 * @notapi
 */
static void iwdg_reset_paramters(iwdg_driver_t *idp) {

    idp->prescaler = IWDG_PRESCALER_DIV4;
    idp->counter   = 0xFFF;
    idp->window    = 0xFFF;
}

/*===========================================================================*/
/* Module exported functions.                                                */
/*===========================================================================*/

void iwdg_init(iwdg_driver_t *idp) {

    /* Set pointer to IWDG register block.*/
    idp->iwdg = iwdg_dev_get_reg_ptr(idp);

    /* Reset IWDG parameters.*/
    iwdg_reset_paramters(idp);
}

iwdg_prescaler_t iwdg_set_prescaler(iwdg_driver_t *idp,
                                    iwdg_prescaler_t prescaler) {

    iwdg_prescaler_t prev_prescaler;

    prev_prescaler = idp->prescaler;
    idp->prescaler = prescaler;

    return prev_prescaler;
}

uint16_t iwdg_set_counter(iwdg_driver_t *idp, uint16_t counter) {

    uint16_t prev_counter;

    prev_counter = idp->counter;
    idp->counter = counter;

    return prev_counter;
}

uint16_t iwdg_set_window(iwdg_driver_t *idp, uint16_t window) {

    uint16_t prev_window;

    prev_window = idp->window;
    idp->window = window;

    return prev_window;
}

void iwdg_start(iwdg_driver_t *idp) {

    /* The independent watchdog (IWDG) is clocked by RCOSC 16MHz clock.*/

    /* If IWDG is not enable via HW, it will be enabled via SW.*/
    if (iwdg_dev_is_hw_en(idp) == 0U) {
        REG_SET_FIELD(idp->iwdg->KR, IWDG_KR_KEY, IWDG_KEY_ENABLE);
    }

    /* Enable access to the registers IWDG_PR, IWDG_RLR and IWDG_WINR.*/
    REG_SET_FIELD(idp->iwdg->KR, IWDG_KR_KEY, (uint32_t)(IWDG_KEY_WRITE_ACCESS_ENABLE));

    /* Configure IWDG prescaler.*/
    REG_SET_FIELD(idp->iwdg->PR, IWDG_PR_PR,(uint8_t)(idp->prescaler));
    
    /* Wait for register to be updated.*/
    while ( REG_READ_FIELD(idp->iwdg->SR,IWDG_SR_PVU) != 0x00U) {
        ;
    }

    /* Configure IWDG counter reload value.*/
    REG_SET_FIELD(idp->iwdg->RLR, IWDG_RLR_RL, idp->counter);

    /* Wait for register to be updated.*/
    while (REG_READ_FIELD(idp->iwdg->SR,IWDG_SR_RVU) != 0x00U) {
        ;
    }

    /* If window parameter is different than current value, update window
       register.*/
    if (REG_READ_FIELD(idp->iwdg->WINR,IWDG_WINR_WIN) != idp->window) {
        REG_SET_FIELD(idp->iwdg->WINR,IWDG_WINR_WIN, idp->window);
    } else {
        REG_SET_FIELD(idp->iwdg->KR,IWDG_KR_KEY, IWDG_KEY_RELOAD);
    }

    /* Disable access to registers IWDG_PR, IWDG_RLR and IWDG_WINR.*/
    REG_SET_FIELD(idp->iwdg->KR, IWDG_KR_KEY, IWDG_KEY_WRITE_ACCESS_DISABLE);
}

void iwdg_refresh(iwdg_driver_t *idp) {

    /* Refresh IWDG counter.*/
    REG_SET_FIELD(idp->iwdg->KR,IWDG_KR_KEY, IWDG_KEY_RELOAD);
}

void iwdg_stop(iwdg_driver_t *idp) {

    (void)idp;
}

void iwdg_deinit(iwdg_driver_t *idp) {

    /* Once running, the IWDG cannot be stopped.*/

    /* Reset pointer to IWDG register block.*/
    idp->iwdg = NULL;

    /* Reset IWDG parameters.*/
    iwdg_reset_paramters(idp);
}

/** @} */
