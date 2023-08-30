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
 * @file    exti.h
 * @brief   EXTI header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup SYSTEM
 * @ingroup DRIVERS
 * @addtogroup EXTI
 * @ingroup SYSTEM
 * @{
 */

#ifndef _EXTI_H_
#define _EXTI_H_

#include <gpio.h>
#include <platform.h>
#include <typedefs.h>

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

/**
 * @brief   Maximum number of EXTI lines.
 */
#define EXTI_MAX_LINE_NUM                   45U

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
 * @enum exti_line_t
 * EXTI lines supported.
 */
typedef enum {
    EXTI_LINE_0 = 0U,        /**< EXTI Line 0  */
    EXTI_LINE_1 = 1U,        /**< EXTI Line 1  */
    EXTI_LINE_2 = 2U,        /**< EXTI Line 2  */
    EXTI_LINE_3 = 3U,        /**< EXTI Line 3  */
    EXTI_LINE_4 = 4U,        /**< EXTI Line 4  */
    EXTI_LINE_5 = 5U,        /**< EXTI Line 5  */
    EXTI_LINE_6 = 6U,        /**< EXTI Line 6  */
    EXTI_LINE_7 = 7U,        /**< EXTI Line 7  */
    EXTI_LINE_8 = 8U,        /**< EXTI Line 8  */
    EXTI_LINE_9 = 9U,        /**< EXTI Line 9  */
    EXTI_LINE_10 = 10U,      /**< EXTI Line 10 */
    EXTI_LINE_11 = 11U,      /**< EXTI Line 11 */
    EXTI_LINE_12 = 12U,      /**< EXTI Line 12 */
    EXTI_LINE_13 = 13U,      /**< EXTI Line 13 */
    EXTI_LINE_14 = 14U,      /**< EXTI Line 14 */
    EXTI_LINE_15 = 15U,      /**< EXTI Line 15 */
    EXTI_LINE_18 = 18U,      /**< EXTI Line 18 */
    EXTI_LINE_20 = 20U,      /**< EXTI Line 20 */
    EXTI_LINE_21 = 21U,      /**< EXTI Line 21 */
    EXTI_LINE_22 = 22U,      /**< EXTI Line 22 */
    EXTI_LINE_23 = 23U,      /**< EXTI Line 23 */
    EXTI_LINE_24 = 24U,      /**< EXTI Line 24 */
    EXTI_LINE_25 = 25U,      /**< EXTI Line 25 */
    EXTI_LINE_26 = 26U,      /**< EXTI Line 26 */
    EXTI_LINE_28 = 28U,      /**< EXTI Line 28 */
    EXTI_LINE_29 = 29U,      /**< EXTI Line 29 */
    EXTI_LINE_30 = 30U,      /**< EXTI Line 30 */
    EXTI_LINE_31 = 31U,      /**< EXTI Line 31 */
    EXTI_LINE_32 = 32U,      /**< EXTI Line 32 */
    EXTI_LINE_33 = 33U,      /**< EXTI Line 33 */
    EXTI_LINE_34 = 34U,      /**< EXTI Line 34 */
    EXTI_LINE_44 = 44U,      /**< EXTI Line 44 */
    EXTI_LINE_45 = 45U       /**< EXTI Line 45 */
} exti_line_t;

/**
 * @enum exti_port_t
 * EXTI Port identifiers.
 */
typedef enum {
    EXTI_PORT_A,   /**< GPIO Port A */
    EXTI_PORT_B,   /**< GPIO Port B */
    EXTI_PORT_C,   /**< GPIO Port C */
    EXTI_PORT_D,   /**< GPIO Port D */
    EXTI_PORT_E,   /**< GPIO Port E */
    EXTI_PORT_F,   /**< GPIO Port F */
    EXTI_PORT_G,   /**< GPIO Port G */
    EXTI_PORT_H,   /**< GPIO Port G */
    EXTI_PORT_I,   /**< GPIO Port I */
    EXTI_PORT_J,   /**< GPIO Port J */
    EXTI_PORT_K,   /**< GPIO Port K */
    EXTI_PORT_L,   /**< GPIO Port L */
    EXTI_PORT_M,   /**< GPIO Port M */
    EXTI_PORT_N,   /**< GPIO Port N */
    EXTI_PORT_Q,   /**< GPIO Port Q */
    EXTI_PORT_R,   /**< GPIO Port R */
    EXTI_PORT_S,   /**< GPIO Port S */
    EXTI_PORT_T,   /**< GPIO Port T */
    EXTI_PORT_V,   /**< GPIO Port V */
    EXTI_PORT_W,   /**< GPIO Port W */
    EXTI_PORT_X,   /**< GPIO Port X */
    EXTI_PORT_Y    /**< GPIO Port Y */
} exti_port_t;

/**
 * @enum exti_mode_t
 * EXTI modes supported.
 */
typedef enum {
    EXTI_MODE_NONE,          /**< Interrupt/event masked mode */
    EXTI_MODE_INTERRUPT,     /**< Interrupt request mode      */
    EXTI_MODE_EVENT          /**< Event request mode          */
} exti_mode_t;

/**
 * @enum exti_trigger_t
 * EXTI triggers supported.
 */
typedef enum {
    EXTI_TRIGGER_NONE,       /**< No trigger event              */
    EXTI_TRIGGER_RISING,     /**< Trigger event on rising edge  */
    EXTI_TRIGGER_FALLING,    /**< Trigger event on falling edge */
    EXTI_TRIGGER_BOTH        /**< Trigger event on both edges   */
} exti_trigger_t;

/**
 * @enum exti_irq_t
 * EXTI interrupt supported.
 */
typedef enum {
    EXTI_IRQ_LINE0,          /**< EXTI Line 0 interrupt        */
    EXTI_IRQ_LINE1,          /**< EXTI Line 1 interrupt        */
    EXTI_IRQ_LINE2,          /**< EXTI Line 2 interrupt        */
    EXTI_IRQ_LINE3,          /**< EXTI Line 3 interrupt        */
    EXTI_IRQ_LINE4,          /**< EXTI Line 4 interrupt        */
    EXTI_IRQ_LINE9_5,        /**< EXTI Lines [5:9] interrupt   */
    EXTI_IRQ_LINE15_10,      /**< EXTI Lines [10:15] interrupt */
} exti_irq_t;

/**
 * @brief   Type of EXTI callbacks.
 */
typedef void (*exti_cb_t)(void);

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

/* Export driver modules.*/
#include <exti_dev.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Configures EXTI line setting the mode and the trigger.
 *
 * @param[in] line      line to be configured. It can be one of the following
 *                      values:
 *            @arg @ref EXTI_LINE_0
 *            @arg @ref EXTI_LINE_1
 *            @arg @ref EXTI_LINE_2
 *            @arg @ref EXTI_LINE_3
 *            @arg @ref EXTI_LINE_4
 *            @arg @ref EXTI_LINE_5
 *            @arg @ref EXTI_LINE_6
 *            @arg @ref EXTI_LINE_7
 *            @arg @ref EXTI_LINE_8
 *            @arg @ref EXTI_LINE_9
 *            @arg @ref EXTI_LINE_10
 *            @arg @ref EXTI_LINE_11
 *            @arg @ref EXTI_LINE_12
 *            @arg @ref EXTI_LINE_13
 *            @arg @ref EXTI_LINE_14
 *            @arg @ref EXTI_LINE_15
 *            @arg @ref EXTI_LINE_18
 *            @arg @ref EXTI_LINE_20
 *            @arg @ref EXTI_LINE_21
 *            @arg @ref EXTI_LINE_22
 *            @arg @ref EXTI_LINE_23
 *            @arg @ref EXTI_LINE_24
 *            @arg @ref EXTI_LINE_25
 *            @arg @ref EXTI_LINE_26
 *            @arg @ref EXTI_LINE_28
 *            @arg @ref EXTI_LINE_29
 *            @arg @ref EXTI_LINE_30
 *            @arg @ref EXTI_LINE_31
 *            @arg @ref EXTI_LINE_32
 *            @arg @ref EXTI_LINE_33
 *            @arg @ref EXTI_LINE_34
 *            @arg @ref EXTI_LINE_44
 *            @arg @ref EXTI_LINE_45
 * @param[in] mode      mode to be configured. It can be one of the following
 *                      values:
 *            @arg @ref EXTI_MODE_NONE
 *            @arg @ref EXTI_MODE_INTERRUPT
 *            @arg @ref EXTI_MODE_EVENT
 * @param[in] trigger   trigger to be configured. It can be one of the
 *                      following values:
 *            @arg @ref EXTI_TRIGGER_NONE
 *            @arg @ref EXTI_TRIGGER_RISING
 *            @arg @ref EXTI_TRIGGER_FALLING
 *            @arg @ref EXTI_TRIGGER_BOTH
 *
 * @api
 */
void exti_set_line(exti_line_t line, exti_mode_t mode, exti_trigger_t trigger);

/**
 * @brief   Checks if a trigger occurred on a specified line is 
 *
 * @param[in] line      line to be checked. It can be one of the following
 *                      values:
 *            @arg @ref EXTI_LINE_0
 *            @arg @ref EXTI_LINE_1
 *            @arg @ref EXTI_LINE_2
 *            @arg @ref EXTI_LINE_3
 *            @arg @ref EXTI_LINE_4
 *            @arg @ref EXTI_LINE_5
 *            @arg @ref EXTI_LINE_6
 *            @arg @ref EXTI_LINE_7
 *            @arg @ref EXTI_LINE_8
 *            @arg @ref EXTI_LINE_9
 *            @arg @ref EXTI_LINE_10
 *            @arg @ref EXTI_LINE_11
 *            @arg @ref EXTI_LINE_12
 *            @arg @ref EXTI_LINE_13
 *            @arg @ref EXTI_LINE_14
 *            @arg @ref EXTI_LINE_15
 *            @arg @ref EXTI_LINE_18
 *            @arg @ref EXTI_LINE_20
 *            @arg @ref EXTI_LINE_21
 *            @arg @ref EXTI_LINE_22
 *            @arg @ref EXTI_LINE_23
 *            @arg @ref EXTI_LINE_24
 *            @arg @ref EXTI_LINE_25
 *            @arg @ref EXTI_LINE_26
 *            @arg @ref EXTI_LINE_28
 *            @arg @ref EXTI_LINE_29
 *            @arg @ref EXTI_LINE_30
 *            @arg @ref EXTI_LINE_31
 *            @arg @ref EXTI_LINE_32
 *            @arg @ref EXTI_LINE_33
 *            @arg @ref EXTI_LINE_34
 *            @arg @ref EXTI_LINE_44
 *            @arg @ref EXTI_LINE_45
 *
 * @api
 */
bool exti_is_pending(exti_line_t line);

/**
 * @brief   Clears a pending trigger event for a specified line
 *
 * @param[in] line      line to be cleared. It can be one of the following
 *                      values:
 *            @arg @ref EXTI_LINE_0
 *            @arg @ref EXTI_LINE_1
 *            @arg @ref EXTI_LINE_2
 *            @arg @ref EXTI_LINE_3
 *            @arg @ref EXTI_LINE_4
 *            @arg @ref EXTI_LINE_5
 *            @arg @ref EXTI_LINE_6
 *            @arg @ref EXTI_LINE_7
 *            @arg @ref EXTI_LINE_8
 *            @arg @ref EXTI_LINE_9
 *            @arg @ref EXTI_LINE_10
 *            @arg @ref EXTI_LINE_11
 *            @arg @ref EXTI_LINE_12
 *            @arg @ref EXTI_LINE_13
 *            @arg @ref EXTI_LINE_14
 *            @arg @ref EXTI_LINE_15
 *            @arg @ref EXTI_LINE_18
 *            @arg @ref EXTI_LINE_20
 *            @arg @ref EXTI_LINE_21
 *            @arg @ref EXTI_LINE_22
 *            @arg @ref EXTI_LINE_23
 *            @arg @ref EXTI_LINE_24
 *            @arg @ref EXTI_LINE_25
 *            @arg @ref EXTI_LINE_26
 *            @arg @ref EXTI_LINE_28
 *            @arg @ref EXTI_LINE_29
 *            @arg @ref EXTI_LINE_30
 *            @arg @ref EXTI_LINE_31
 *            @arg @ref EXTI_LINE_32
 *            @arg @ref EXTI_LINE_33
 *            @arg @ref EXTI_LINE_34
 *            @arg @ref EXTI_LINE_44
 *            @arg @ref EXTI_LINE_45
 *
 * @api
 */
void exti_clear_pending(exti_line_t line);

/**
 * @brief   Configures EXTI port.
 * @note    EXTI lines [0:15] are dedicated to the GPIOx[0:15].
 *
 * @param[in] line      line to be configured. It can be one of the following
 *                      values:
 *            @arg @ref EXTI_LINE_0
 *            @arg @ref EXTI_LINE_1
 *            @arg @ref EXTI_LINE_2
 *            @arg @ref EXTI_LINE_3
 *            @arg @ref EXTI_LINE_4
 *            @arg @ref EXTI_LINE_5
 *            @arg @ref EXTI_LINE_6
 *            @arg @ref EXTI_LINE_7
 *            @arg @ref EXTI_LINE_8
 *            @arg @ref EXTI_LINE_9
 *            @arg @ref EXTI_LINE_10
 *            @arg @ref EXTI_LINE_11
 *            @arg @ref EXTI_LINE_12
 *            @arg @ref EXTI_LINE_13
 *            @arg @ref EXTI_LINE_14
 *            @arg @ref EXTI_LINE_15
 * @param[in] port      port to be configured. It can be one of the following
 *                      values:
 *            @arg @ref EXTI_PORT_A
 *            @arg @ref EXTI_PORT_B
 *            @arg @ref EXTI_PORT_C
 *            @arg @ref EXTI_PORT_D
 *            @arg @ref EXTI_PORT_E
 *            @arg @ref EXTI_PORT_F
 *            @arg @ref EXTI_PORT_G
 *            @arg @ref EXTI_PORT_H
 *            @arg @ref EXTI_PORT_I
 *            @arg @ref EXTI_PORT_J
 *            @arg @ref EXTI_PORT_K
 *            @arg @ref EXTI_PORT_L
 *            @arg @ref EXTI_PORT_M
 *            @arg @ref EXTI_PORT_N
 *            @arg @ref EXTI_PORT_Q
 *            @arg @ref EXTI_PORT_R
 *            @arg @ref EXTI_PORT_S
 *            @arg @ref EXTI_PORT_T
 *            @arg @ref EXTI_PORT_V
 *            @arg @ref EXTI_PORT_W
 *            @arg @ref EXTI_PORT_X
 *            @arg @ref EXTI_PORT_Y
 *
 * @api
 */
void exti_set_port(exti_line_t line, exti_port_t port);

/**
 * @brief   Configures priority and callback for interrupts related to EXTI
 *          lines [0:15].
 * @note    EXTI lines [0:15] are dedicated to the GPIOx[0:15].
 * @note    If callback is not NULL, the interrupt will be enabled, otherwise
 *          it will be disabled.
 *
 * @param[in] line      line which the callback is related to. It can be one of
 *                      the following values:
 *            @arg @ref EXTI_LINE_0
 *            @arg @ref EXTI_LINE_1
 *            @arg @ref EXTI_LINE_2
 *            @arg @ref EXTI_LINE_3
 *            @arg @ref EXTI_LINE_4
 *            @arg @ref EXTI_LINE_5
 *            @arg @ref EXTI_LINE_6
 *            @arg @ref EXTI_LINE_7
 *            @arg @ref EXTI_LINE_8
 *            @arg @ref EXTI_LINE_9
 *            @arg @ref EXTI_LINE_10
 *            @arg @ref EXTI_LINE_11
 *            @arg @ref EXTI_LINE_12
 *            @arg @ref EXTI_LINE_13
 *            @arg @ref EXTI_LINE_14
 *            @arg @ref EXTI_LINE_15
 * @param[in] prio      interrupt priority to be configured
 * @param[in] callback  pointer to EXTI callback function
 *
 * @api
 */
void exti_set_irq(exti_line_t line, uint32_t prio, exti_cb_t callback);

/**
 * @brief   Shared interrupt handler for EXTI lines [0:15].
 * @note    Not an API, used internally.
 * @note    EXTI lines [0:15] are dedicated to the GPIOx[0:15].
 *
 * @param[in] irq       interrupt to be managed. It can be one of the following
 *                      values:
 *            @arg @ref EXTI_IRQ_LINE0
 *            @arg @ref EXTI_IRQ_LINE1
 *            @arg @ref EXTI_IRQ_LINE2
 *            @arg @ref EXTI_IRQ_LINE3
 *            @arg @ref EXTI_IRQ_LINE4
 *            @arg @ref EXTI_IRQ_LINE9_5
 *            @arg @ref EXTI_IRQ_LINE10_15
 *
 * @isr
 */
void __exti_serve_interrupt(exti_irq_t irq);

#ifdef __cplusplus
}
#endif

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/*===========================================================================*/
/* Module late inclusions.                                                   */
/*===========================================================================*/

#endif /* _EXTI_H_ */

/** @} */
