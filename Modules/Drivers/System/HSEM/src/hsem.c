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
 * @file    hsem.c
 * @brief   SR5E1 HSEM source file.
 *
 * @addtogroup DRIVERS
 * @addtogroup SYSTEM
 * @ingroup DRIVERS
 * @addtogroup HSEM
 * @ingroup SYSTEM
 * @{
 */

#include <hsem.h>
#include <hsem_private.h>
#include <clock.h>

/*===========================================================================*/
/* Module local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Module exported variables.                                                */
/*===========================================================================*/

/* HSEM driver instance. */
hsem_driver_t DRV_HSEM;

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
 * @brief   Resets HSEM parameters.
 *
 * @param[out] hdp      pointer to an @p hsem_driver_t structure
 *
 * @notapi
 */
static void hsem_reset_paramters(hsem_driver_t *hdp) {

    uint8_t i;

    hdp->core_id  = HSEM_CORE_ID_CORE1;
    hdp->prio     = IRQ_MIN_PRIORITY;
    hdp->irq_mask = 0UL;

    for (i = 0U; i < (uint8_t)HSEM_SEM_NUM; i++) {
        hdp->cb[i] = NULL;
    }
}

/*===========================================================================*/
/* Module exported functions.                                                */
/*===========================================================================*/

void hsem_init(hsem_driver_t *hdp) {

    hdp->hsem = HSEM;

    /* Reset HSEM parameters.*/
    hsem_reset_paramters(hdp);
}

void hsem_set_core(hsem_driver_t *hdp, hsem_core_id_t core_id) {
    
    hdp->core_id = core_id;
}

uint32_t hsem_set_prio(hsem_driver_t *hdp, uint32_t prio) {

    uint32_t prev_prio;

    prev_prio = hdp->prio;
    hdp->prio = prio;

    return prev_prio;
}

void hsem_en_irq(hsem_driver_t *hdp, hsem_sem_id_t sem_id) {

    hdp->irq_mask |= (0x1UL << ((uint8_t)sem_id));
}

hsem_cb_t hsem_set_cb(hsem_driver_t *hdp, hsem_sem_id_t sem_id, hsem_cb_t cb) {

    hsem_cb_t prev_cb;

    prev_cb         = hdp->cb[sem_id];
    hdp->cb[sem_id] = cb;

    return prev_cb;
}

void hsem_start(hsem_driver_t *hdp) {

    IRQn_Type vector;

    /* If disabled, enable HSEM clock.*/
    if (is_clock_enable_HSEM() == false) {
        clock_enable_HSEM(true);
    }

    /* Clear pending interrupts.*/
    if (hdp->core_id == HSEM_CORE_ID_CORE1) {
        hdp->hsem->C1ICR = 0xFFFFFFFFUL;
    } else {
        hdp->hsem->C2ICR = 0xFFFFFFFFUL;
    }

    /* Enable selected interrupts.*/
    if (hdp->irq_mask != 0UL) {
        if (hdp->core_id == HSEM_CORE_ID_CORE1) {
            hdp->hsem->C1IER = hdp->irq_mask;
        } else {
            hdp->hsem->C2IER = hdp->irq_mask;
        }
    }

    /* If at least the interrupt of one semaphore is enabled, enable related
       interrupt vector.*/
    if (hdp->irq_mask != 0UL) {
        vector = hsem_dev_get_vector(hdp);
        irq_set_priority(vector, hdp->prio);
        irq_enable(vector);
    }
}

bool hsem_take_sem_2s(hsem_driver_t *hdp, hsem_sem_id_t sem_id,
                      uint8_t proc_id) {

    uint32_t val = (HSEM_R_LOCK                              | 
                    ((uint32_t)hdp->core_id) << HSEM_R_COREID_Pos |
                    ((uint32_t)proc_id)      << HSEM_R_PROCID_Pos);

    hdp->hsem->R[sem_id] = val;

    if (hdp->hsem->R[sem_id] == val) {
        return true;
    } else {
        return false;
    }
}

bool hsem_take_sem_1s(hsem_driver_t *hdp, hsem_sem_id_t sem_id) {

    if (hdp->hsem->RLR[sem_id] == (HSEM_R_LOCK | (((uint32_t)hdp->core_id) << HSEM_R_COREID_Pos))) {
        return true;
    } else {
        return false;
    }
}

bool hsem_is_sem_taken(hsem_driver_t *hdp, hsem_sem_id_t sem_id) {

    return (((hdp->hsem->R[sem_id] & HSEM_R_LOCK) != 0UL)  ? true : false);
}

void hsem_release_sem(hsem_driver_t *hdp, hsem_sem_id_t sem_id,
                      uint8_t proc_id) {

    hdp->hsem->R[sem_id] = (((uint32_t)hdp->core_id) << HSEM_R_COREID_Pos |
                            ((uint32_t)proc_id)      << HSEM_R_PROCID_Pos);
}

void hsem_set_clear_key(hsem_driver_t *hdp, uint16_t key) {

    hdp->hsem->KEYR = ((uint32_t)(key)) << HSEM_KEYR_KEY_Pos;
}

uint16_t hsem_get_clear_key(hsem_driver_t *hdp) {

    return (uint16_t)(hdp->hsem->KEYR >> HSEM_KEYR_KEY_Pos);
}

void hsem_release_all(hsem_driver_t *hdp, hsem_core_id_t core_id,
                      uint16_t key) {

    hdp->hsem->CR = ((((uint32_t)key) << HSEM_CR_KEY_Pos) |
                     ((uint32_t)core_id) << HSEM_R_COREID_Pos);
}

void hsem_stop(hsem_driver_t *hdp) {

    /* Clear pending interrupts and disable them for both cores.*/
    hdp->hsem->C1ICR = 0xFFFFFFFFUL;
    hdp->hsem->C2ICR = 0xFFFFFFFFUL;
    hdp->hsem->C1IER = 0x0UL;
    hdp->hsem->C2IER = 0x0UL;

    /* Disable HSEM interrupts for all cores.*/
    hsem_dev_irq_disable_all();

    /* Disable HSEM clock.*/
    clock_disable_HSEM();
}

void hsem_deinit(hsem_driver_t *hdp) {

    hdp->hsem = NULL;

    /* Reset HSEM parameters.*/
    hsem_reset_paramters(hdp);
}

void __hsem_serve_interrupt(hsem_driver_t *hdp) {

    uint32_t isr;
    uint8_t i;

    /* Reading and clearing status.*/
    if (hdp->core_id == HSEM_CORE_ID_CORE1) {
        isr = hdp->hsem->C1ISR;
        hdp->hsem->C1ICR = isr;
    } else {
        isr = hdp->hsem->C2ISR;
        hdp->hsem->C2ICR = isr;
    }

    for (i = 0U; i < (uint8_t)HSEM_SEM_NUM; i++) {
        if ((0x1UL & (hdp->irq_mask >> i)) != 0U) {
            if (hdp->cb[i] != NULL) {
                hdp->cb[i](hdp);
            }
        }
    }
}

/** @} */
