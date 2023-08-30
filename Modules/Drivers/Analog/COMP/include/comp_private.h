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
 * @file    comp_private.h
 * @brief   COMP driver private header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup ANALOG
 * @ingroup DRIVERS
 * @addtogroup COMP
 * @ingroup ANALOG
 * @{
 */

#ifndef _COMP_PRIVATE_H_
#define _COMP_PRIVATE_H_

#include <irq.h>
#include <exti.h>
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
 * @brief   COMP driver structure.
 * @note    This structure is internal to the COMP driver.
 */
struct comp_driver {
    /**
     * @brief   Pointer to COMP registers block.
     */
    COMP_TypeDef             *comp;
    /**
     * @brief   COMP interrupt priority.
     */
    uint32_t                 prio;
    /**
     * @brief   COMP input plus (non-inverting input).
     */
    uint8_t                  input_plus;
    /**
     * @brief   COMP input minus (inverting input).
     */
    uint8_t                  input_minus;
    /**
     * @brief   COMP hysteresis mode of the input minus.
     */
    comp_hysteresis_t        hysteresis;
    /**
     * @brief   COMP output polarity.
     */
    comp_outpol_t            out_pol;
    /**
     * @brief   COMP blanking selection.
     */
    uint8_t                  blank_sel;
    /**
     * @brief   Deglitch enable status flag (true or false).
     */
    bool                     is_deglitch_en;
    /**
     * @brief   Register lock enable status flag (true or false).
     */
    bool                     is_lock_en;
    /**
     * @brief   COMP output trigger mode through external interrupt line.
     */
    comp_triggermode_t       triggermode;
    /**
     * @brief   COMP event callback function.
     */
    comp_cb_t                cb;
};

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

IRQ_HANDLER(IRQ_COMP_1_2_HANDLER);
IRQ_HANDLER(IRQ_COMP_3_4_HANDLER);
IRQ_HANDLER(IRQ_COMP_5_6_HANDLER);
IRQ_HANDLER(IRQ_COMP_7_8_HANDLER);

COMP_TypeDef *comp_dev_get_reg_ptr(comp_driver_t *cdp);
void comp_dev_clock_enable(comp_driver_t *cdp);
void comp_dev_clock_disable(comp_driver_t *cdp);
IRQn_Type comp_dev_get_vector(comp_driver_t *cdp);
exti_line_t comp_dev_get_exti_line(comp_driver_t *cdp);

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/*===========================================================================*/
/* Module late inclusions.                                                   */
/*===========================================================================*/

#endif /* _COMP_PRIVATE_H_ */

/** @} */
