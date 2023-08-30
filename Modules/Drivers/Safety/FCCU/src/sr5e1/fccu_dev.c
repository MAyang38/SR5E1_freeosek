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
 * @file    fccu_dev.c
 * @brief   FCCU device specific source file.
 *
 * @addtogroup DRIVERS
 * @addtogroup SAFETY
 * @ingroup DRIVERS
 * @addtogroup FCCU
 * @ingroup SAFETY
 * @{
 */

#include <fccu.h>
#include <fccu_private.h>
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
 * @brief   Returns pointer to the FCCU register block.
 *
 * @param[in] fdp       pointer to a @p fccu_driver_t structure
 * @return              pointer to the FCCU register block.
 *
 * @notapi
 */
FCCU_TypeDef *fccu_dev_get_reg_ptr(fccu_driver_t *fdp) {

    (void)fdp;

    return FCCU;
}

/**
 * @brief   Returns FCCU interrupt vector.
 *
 * @param[in] fdp       pointer to a @p fccu_driver_t structure
 * @return              FCCU interrupt vector
 *
 * @notapi
 */
IRQn_Type fccu_dev_get_vector(fccu_driver_t *fdp) {

    (void)fdp;

    return IRQ_FCCU_VECTOR;
}

/**
 * @brief   FCCU interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_FCCU_HANDLER)
{
    IRQ_PROLOGUE();

    __fccu_serve_interrupt(&DRV_FCCU);

    IRQ_EPILOGUE();
}

/** @} */
