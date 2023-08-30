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
 * @file    wwdg_dev.c
 * @brief   WWDG device specific source file.
 *
 * @addtogroup DRIVERS
 * @addtogroup SYSTEM
 * @ingroup DRIVERS
 * @addtogroup WWDG
 * @ingroup SYSTEM
 * @{
 */

#include <wwdg.h>
#include <wwdg_private.h>
#include <clock.h>
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
 * @brief   Returns pointer to the WWDG register block.
 *
 * @param[in] wdp       pointer to a @p cordic_driver_t structure
 * @return              pointer to the WWDG register block.
 *
 * @notapi
 */
WWDG_TypeDef *wwdg_dev_get_reg_ptr(wwdg_driver_t *wdp) {

    (void)wdp;

    return WWDG1;
}

/**
 * @brief   Enables WWDG clock.
 *
 * @param[in] wdp       pointer to a @p wwdg_driver_t structure
 *
 * @notapi
 */
void wwdg_dev_clock_enable(wwdg_driver_t *wdp) {

    (void)wdp;

    clock_enable_WWDG1(true);
}

/**
 * @brief   Disables WWDG clock.
 *
 * @param[in] wdp       pointer to a @p wwdg_driver_t structure
 *
 * @notapi
 */
void wwdg_dev_clock_disable(wwdg_driver_t *wdp) {

    (void)wdp;

    clock_disable_WWDG1();
}

/**
 * @brief   Returns WWDG interrupt vector.
 *
 * @param[in] wdp       pointer to a @p wwdg_driver_t structure
 * @return              WWDG interrupt vector
 *
 * @notapi
 */
IRQn_Type wwdg_dev_get_vector(wwdg_driver_t *wdp) {

    (void)wdp;

    return IRQ_WWDG_VECTOR;
}

/**
 * @brief   WWDG interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_WWDG_HANDLER) {

    IRQ_PROLOGUE();

    __wwdg_serve_interrupt(&DRV_WWDG);

    IRQ_EPILOGUE();
}

/** @} */
