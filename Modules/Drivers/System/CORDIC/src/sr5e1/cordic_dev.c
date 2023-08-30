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
 * @file    cordic_dev.c
 * @brief   CORDIC device specific source file.
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
#include <dma.h>
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
 * @brief   Returns pointer to the CORDIC register block.
 *
 * @param[in] cdp       pointer to a @p cordic_driver_t structure
 * @return              pointer to the CORDIC register block.
 *
 * @notapi
 */
CORDIC_TypeDef *cordic_dev_get_reg_ptr(cordic_driver_t *cdp) {

    (void)cdp;

    return CORDIC;
}

/**
 * @brief   Enables CORDIC clock.
 *
 * @param[in] cdp       pointer to a @p cordic_driver_t structure
 *
 * @notapi
 */
void cordic_dev_clock_enable(cordic_driver_t *cdp) {

    (void)cdp;

    clock_enable_CORDIC(true);
}

/**
 * @brief   Disables CORDIC clock.
 *
 * @param[in] cdp       pointer to a @p cordic_driver_t structure
 *
 * @notapi
 */
void cordic_dev_clock_disable(cordic_driver_t *cdp) {

    (void)cdp;

    clock_disable_CORDIC();
}

/**
 * @brief   Returns CORDCI DMA Write trigger.
 *
 * @param[in] cdp       pointer to a @p cordic_driver_t structure
 * @return              DMA Write trigger.
 *
 * @notapi
 */
uint32_t cordic_dev_get_dma_wr_trigger(cordic_driver_t *cdp) {

    (void)cdp;

    return DMAMUX1_CORDIC_WRITE;
}

/**
 * @brief   Returns CORDCI DMA Read trigger.
 *
 * @param[in] cdp       pointer to a @p cordic_driver_t structure
 * @return              DMA Read trigger.
 *
 * @notapi
 */
uint32_t cordic_dev_get_dma_rd_trigger(cordic_driver_t *cdp) {

    (void)cdp;

    return DMAMUX1_CORDIC_READ;
}

/**
 * @brief   Returns CORDIC interrupt vector.
 *
 * @param[in] cdp       pointer to a @p cordic_driver_t structure
 * @return              CORDIC interrupt vector
 *
 * @notapi
 */
IRQn_Type cordic_dev_get_vector(cordic_driver_t *cdp) {

    (void)cdp;

    return IRQ_CORDIC_VECTOR;
}

/**
 * @brief   CORDIC interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(IRQ_CORDIC_HANDLER) {

    IRQ_PROLOGUE();

    __cordic_serve_interrupt(&DRV_CORDIC);

    IRQ_EPILOGUE();
}

/** @} */
