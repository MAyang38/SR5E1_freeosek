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
 * @file    fccu_private.h
 * @brief   FCCU driver private header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup SAFETY
 * @ingroup DRIVERS
 * @addtogroup FCCU
 * @ingroup SAFETY
 * @{
 */

#ifndef _FCCU_PRIVATE_H_
#define _FCCU_PRIVATE_H_

#include <irq.h>
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
 * @brief   FCCU driver structure.
 * @note    This structure is internal to the FCCU driver.
 */
struct fccu_driver {
    /**
     * @brief   Pointer to FCCU registers block.
     */
    FCCU_TypeDef             *fccu;
    /**
     * @brief   FCCU interrupt priority.
     */
    uint32_t                 prio;
    /**
     * @brief   FCCU error output configuration.
     */
    fccu_eout_cfg_t          eout_cfg;
    /**
     * @brief   FCCU configuration timeout.
     */
    fccu_config_to_t         config_to;
    /**
     * @brief   FCCU configuration timeout interrupt flag ('true' means the
     *          configuration timeout is enabled, 'false' otherwise).
     */
    bool                     is_config_to_irq_en;
    /**
     * @brief   FCCU configuration timeout interrupt callback.
     */
    fccu_cb_t                config_to_irq_cb;
    /**
     * @brief   FCCU alarm timeout.
     */
    uint32_t                 alarm_to;
    /**
     * @brief   FCCU Delta_T (in microseconds).
     */
    uint32_t                 delta_t;
    /**
     * @brief   FCCU channel configurations.
     */
    fccu_ch_cfg_t            ch_cfg[FCCU_CH_NUMBER];
};

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

IRQ_HANDLER(IRQ_FCCU_HANDLER);

FCCU_TypeDef *fccu_dev_get_reg_ptr(fccu_driver_t *fdp);
IRQn_Type fccu_dev_get_vector(fccu_driver_t *fdp);

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/*===========================================================================*/
/* Module late inclusions.                                                   */
/*===========================================================================*/

#endif /* _FCCU_PRIVATE_H_ */

/** @} */
