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
 * @file    hsem_dev.c
 * @brief   HSEM device specific source file.
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
#include <irq.h>
#include <platform.h>

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
/* Module local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Module exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Returns HSEM interrupt vector.
 *
 * @param[in] udp       pointer to a @p hsem_driver_t structure
 * @return              HSEM interrupt vector
 *
 * @notapi
 */
IRQn_Type hsem_dev_get_vector(hsem_driver_t *hdp) {

    IRQn_Type vector;

    if (hdp->core_id == HSEM_CORE_ID_CORE1) {
        vector = HSEM_INT1_IRQn;
    } else {
        vector = HSEM_INT2_IRQn;
    }

    return vector;
}

/**
 * @brief   Disable all HSEM interrupts.
 *
 * @param[in] udp       pointer to a @p hsem_driver_t structure
  *
 * @notapi
 */
void hsem_dev_irq_disable_all(void) {

    irq_disable(HSEM_INT1_IRQn);
    irq_disable(HSEM_INT2_IRQn);
}

/**
 * @brief   HSEM core 1 interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_HSEM_INT1_HANDLER) {

    IRQ_PROLOGUE();

    __hsem_serve_interrupt(&DRV_HSEM);

    IRQ_EPILOGUE();
}

/**
 * @brief   HSEM core 2 interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_HSEM_INT2_HANDLER) {

    IRQ_PROLOGUE();

    __hsem_serve_interrupt(&DRV_HSEM);

    IRQ_EPILOGUE();
}

/** @} */
