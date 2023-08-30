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
 * @file    exti.c
 * @brief   EXTI source file.
 *
 * @addtogroup DRIVERS
 * @addtogroup SYSTEM
 * @ingroup DRIVERS
 * @addtogroup EXTI
 * @ingroup SYSTEM
 * @{
 */

#include <exti.h>
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

/**
 * @brief   Pointer to EXTI registers block.
 */
/*lint -e843 -e953 */
static EXTI_TypeDef *exti = EXTI;
/*lint +e943 +e953 */

/**
 * @brief   Pointers to callbacks related to interrupts of EXTI lines [0:15].
 */
static exti_cb_t exti_callback[16] = {NULL,
                                      NULL,
                                      NULL,
                                      NULL,
                                      NULL,
                                      NULL,
                                      NULL,
                                      NULL,
                                      NULL,
                                      NULL,
                                      NULL,
                                      NULL,
                                      NULL,
                                      NULL,
                                      NULL,
                                      NULL};

/*===========================================================================*/
/* Local function prototypes                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Module local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Module exported functions.                                                */
/*===========================================================================*/

void exti_set_line(exti_line_t line, exti_mode_t mode, exti_trigger_t trigger) {

    switch(mode) {
        case EXTI_MODE_NONE:
            break;
        case EXTI_MODE_INTERRUPT:
            if (line <= EXTI_LINE_31) {
                exti->C1IMR1 |= 0x1UL << ((uint8_t)line);
            } else {
                exti->C1IMR2 |= 0x1UL << ((uint8_t)line);
            }
            break;
        case EXTI_MODE_EVENT:
            if (line <= EXTI_LINE_31) {
                exti->C1EMR1 |= 0x1UL << ((uint8_t)line);
            } else {
                exti->C1EMR2 |= 0x1UL << ((uint8_t)line);
            }
            break;
        default:
            /* Dummy comment as required by MISRA.*/
            break;
    }

    switch(trigger) {
        case EXTI_TRIGGER_NONE:
            break;
        case EXTI_TRIGGER_RISING:
            if (line <= EXTI_LINE_31) {
                exti->RTSR1 |= 0x1UL << ((uint8_t)line);
            } else {
                exti->RTSR2 |= 0x1UL << ((uint8_t)line);
            }
            break;
        case EXTI_TRIGGER_FALLING:
            if (line <= EXTI_LINE_31) {
                exti->FTSR1 |= 0x1UL << ((uint8_t)line);
            } else {
                exti->FTSR2 |= 0x1UL << ((uint8_t)line);
            }
            break;
        case EXTI_TRIGGER_BOTH:
            if (line <= EXTI_LINE_31) {
                exti->RTSR1 |= 0x1UL << ((uint8_t)line);
                exti->FTSR1 |= 0x1UL << ((uint8_t)line);
            } else {
                exti->RTSR2 |= 0x1UL << ((uint8_t)line);
                exti->FTSR2 |= 0x1UL << ((uint8_t)line);
            }
            break;
        default:
            /* Dummy comment as required by MISRA.*/
            break;
    }
}

bool exti_is_pending(exti_line_t line) {

    if (line <= EXTI_LINE_31) {
        if ((0x1UL & (exti->C1PR1 >> ((uint8_t)line))) == 1UL) {
            return true;
        } else {
            return false;
        }
    } else {
        if ((0x1UL & (exti->C1PR2 >> (((uint8_t)line) - ((uint8_t)EXTI_LINE_31)))) == 1UL) {
            return true;
        } else {
            return false;
        }
    }
}

void exti_clear_pending(exti_line_t line) {

    if (line <= EXTI_LINE_31) {
        exti->C1PR1 |= 0x1UL << ((uint8_t)line);
    } else {
        exti->C1PR2 |= 0x1UL << (((uint8_t)line) - ((uint8_t)EXTI_LINE_31));
    }
}

void exti_set_port(exti_line_t line, exti_port_t port) {

    if (line <= EXTI_LINE_15) {
        uint32_t exticr;
        /* Set port related to EXTI line.*/
        exticr = SYSCFG->EXTICR[((uint8_t)line) / 4U];
        exticr &= ~(0x0FUL << (4U * (((uint8_t)line) & 0x03U)));
        exticr |= (((uint32_t)port) << (4U * (((uint8_t)line) & 0x03U)));
        SYSCFG->EXTICR[((uint8_t)line) / 4U] = exticr;
    }
}

void exti_set_irq(exti_line_t line, uint32_t prio, exti_cb_t callback) {

    if (line <= EXTI_LINE_15) {
        IRQn_Type vector;

        /* Configure interrupt callback.*/
        exti_callback[((uint8_t)(line))] = callback;

        /* Get interrupt vector related to EXTI line.*/
        vector = exti_dev_get_vector(line);
        if (callback != NULL) {
            /* Clear pending interrupt.*/
            exti->C1PR1 |= 0x1UL << ((uint8_t)line);

            /* Enable interrupt.*/
            irq_set_priority(vector, prio);
            irq_enable(vector);
        } else {
            /* Disable interrupt.*/
            irq_disable(vector);

            /* Clear pending interrupt.*/
            exti->C1PR1 |= 0x1UL << ((uint8_t)line);
        }
    }
}

void __exti_serve_interrupt(exti_irq_t irq) {

    uint8_t i;

    switch(irq) {
        /* EXTI lines [5:9] have a common interrupt.*/
        case EXTI_IRQ_LINE9_5:
            for (i = 5U; i <= 9U; i++) {
                if ((0x1UL & (exti->C1PR1 >> i)) == 1UL) {
                    /* Clear pending interrupt.*/
                    exti->C1PR1 |= 0x1UL << i;

                    /* If defined, invoke related callback.*/
                    if (exti_callback[i] != NULL) {
                        exti_callback[i]();
                    }
                }
            }
            break;
        /* EXTI lines [10:15] have a common interrupt.*/
        case EXTI_IRQ_LINE15_10:
            for (i = 10U; i <= 15U; i++) {
                if ((0x1UL & (exti->C1PR1 >> i)) == 1UL) {
                    /* Clear pending interrupt.*/
                    exti->C1PR1 |= 0x1UL << i;

                    /* If defined, invoke related callback.*/
                    if (exti_callback[i] != NULL) {
                        exti_callback[i]();
                    }
                }
            }
            break;
        /* EXTI lines [0:4] have a dedicated interrupt.*/
        case EXTI_IRQ_LINE0:
        case EXTI_IRQ_LINE1:
        case EXTI_IRQ_LINE2:
        case EXTI_IRQ_LINE3:
        case EXTI_IRQ_LINE4:
            /* Clear pending interrupt.*/
            exti->C1PR1 |= 0x1UL << ((uint8_t)irq);

            /* If defined, invoke related callback.*/
            if (exti_callback[((uint8_t)irq)] != NULL) {
                exti_callback[((uint8_t)irq)]();
            }
            break;
        default:
            /* dummy comment as required by MISRA */
            break;
    }
}

/** @} */
