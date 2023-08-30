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
 * @file    wwdg_private.h
 * @brief   WWDG driver private header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup SYSTEM
 * @ingroup DRIVERS
 * @addtogroup WWDG
 * @ingroup SYSTEM
 * @{
 */

#ifndef _WWDG_PRIVATE_H_
#define _WWDG_PRIVATE_H_

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
 * @brief   WWDG driver structure.
 * @note    This structure is internal to the WWDG driver.
 */
struct wwdg_driver {
    /**
     * @brief   Pointer to WWDG registers block.
     */
    WWDG_TypeDef             *wwdg;
    /**
     * @brief   WWDG interrupt priority.
     */
    uint32_t                 prio;
    /**
     * @brief   WWDG prescaler.
     */
    wwdg_prescaler_t         prescaler;
    /**
     * @brief   WWDG free runnig downcounter value [0x40:0x7F].
     */
    uint16_t                 counter;
    /**
     * @brief   WWDG window value [0x40:0x7F].
     */
    uint16_t                 window;
    /**
     * @brief   WWDG early wakeup interrupt enable flag ("true" means the early
     *          wakeup interrupt is enabled, "false" otherwise).
     */
    bool                     is_ewk_irq_en;
    /**
     * @brief   Pointers to WWDG callback functions.
     * @note    Set to @p NULL if not required.
     */
    wwdg_cb_t                cb;
};

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

IRQ_HANDLER(IRQ_WWDG_HANDLER);

WWDG_TypeDef *wwdg_dev_get_reg_ptr(wwdg_driver_t *wdp);
void wwdg_dev_clock_enable(wwdg_driver_t *wdp);
void wwdg_dev_clock_disable(wwdg_driver_t *wdp);
IRQn_Type wwdg_dev_get_vector(wwdg_driver_t *wdp);

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/*===========================================================================*/
/* Module late inclusions.                                                   */
/*===========================================================================*/

#endif /* _WWDG_PRIVATE_H_ */

/** @} */

