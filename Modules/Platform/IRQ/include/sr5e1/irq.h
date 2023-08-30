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
 * @file    irq.h
 * @brief   IRQ module header file.
 *
 * @addtogroup PLATFORM
 * @addtogroup IRQ
 * @ingroup PLATFORM
 * @{
 */

#ifndef _IRQ_H_
#define _IRQ_H_

#include <platform.h>
#include <core_cm7.h>
#include <typedefs.h>

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

/**
 * @name    Interrupt priorities
 * @{
 */
#define IRQ_PRIORITY_0                      0U
#define IRQ_PRIORITY_1                      1U
#define IRQ_PRIORITY_2                      2U
#define IRQ_PRIORITY_3                      3U
#define IRQ_PRIORITY_4                      4U
#define IRQ_PRIORITY_5                      5U
#define IRQ_PRIORITY_6                      6U
#define IRQ_PRIORITY_7                      7U
#define IRQ_PRIORITY_8                      8U
#define IRQ_PRIORITY_9                      9U
#define IRQ_PRIORITY_10                     10U
#define IRQ_PRIORITY_11                     11U
#define IRQ_PRIORITY_12                     12U
#define IRQ_PRIORITY_13                     13U
#define IRQ_PRIORITY_14                     14U
#define IRQ_PRIORITY_15                     15U
/** @} */

/**
 * @brief   Minimum interrupt priority.
 */
#define IRQ_MIN_PRIORITY                    IRQ_PRIORITY_15

/**
 * @brief   Maximum interrupt priority.
 */
#define IRQ_MAX_PRIORITY                    IRQ_PRIORITY_0

/*===========================================================================*/
/* Module pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Module data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/**
 * @brief   IRQ prologue code.
 * @details This macro must be inserted at the start of all IRQ handlers.
 */
#define IRQ_PROLOGUE()

/**
 * @brief   IRQ epilogue code.
 * @details This macro must be inserted at the end of all IRQ handlers.
 */
#define IRQ_EPILOGUE()

/**
 * @brief   IRQ handler function declaration.
 * @details This macro hides the details of an ISR function declaration.
 *
 * @param[in] id        a vector name as defined in @p vectors.s
 */
#define IRQ_HANDLER(id) void id(void)

/**
 * @brief   IRQ handler function declaration.
 * @note    IRQ handler is executed from ITCM.
 * @details This macro hides the details of an ISR function declaration.
 *
 * @param[in] id        a vector name as defined in @p vectors.s
 */
#define IRQ_HANDLER_ITCM(id) void __attribute__((section(".itcm"))) id(void)

/**
 * @brief   Checks if a IRQ priority is valid.
 *
 * @param[in] prio      IRQ priority
 * @retval              The function result.
 * @retval false        invalid priority.
 * @retval true         correct priority.
 */
#define IRQ_IS_VALID_PRIORITY(prio) ((uint32_t)(prio) <= IRQ_PRIORITY_15)

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/**
 * @brief   Disables all interrupts
 * @note    Disables all interrupts by clearing the I-bit in the CPSR register.
 *
 * @api
 */
__STATIC_INLINE void irq_disable_all(void) {

    __disable_irq();
}

/**
 * @brief   Enables all interrupts
 * @note    Enables all interrupts by setting the I-bit in the CPSR register.
 *
 * @api
 */
__STATIC_INLINE void irq_enable_all(void) {

    __enable_irq();
}
 
/**
 * @brief   Enables specific interrupt.
 * @note    Enables interrupt related to the interrupt identifier.
 *
 * @param[out] id       interrupt identifier
 *
 * @api
 */
__STATIC_INLINE void irq_enable(IRQn_Type id) {

    NVIC_EnableIRQ(id);
}

/**
 * @brief   Disables specific interrupt.
 * @note    Disables interrupt related to the interrupt identifier.
 *
 * @param[out] id       interrupt identifier
 *
 * @api
 */
__STATIC_INLINE void irq_disable(IRQn_Type id) {

    NVIC_DisableIRQ(id);
}

/**
 * @brief   Sets the priority of a specific interrupt.
 * @note    Sets the priority of the interrupt related to the interrupt
 *          identifier.
 *
 * @param[out] id       interrupt identifier
 *
 * @api
 */
__STATIC_INLINE void irq_set_priority(IRQn_Type id, uint32_t prio) {

    NVIC_SetPriority(id, prio);
}


/**
 * @brief   Returns the content of the Priority Mask register.
 *
 * @return              content of Priority Mask register
 *
 * @api
 */
__STATIC_INLINE uint32_t get_irq_status(void) {

    return (__get_PRIMASK());
}

/**
 * @brief   Checks if interrupts are enabled
 * @note    Checks if interrupts are enabled based on the content of the 
 *          Priority Mask bit in the Priority Mask register.
 *
 * @param[in] sts       content of Priority Mask register
 * @return              check result
 * @retval false        if interrupts are disabled
 * @retval true         if interrupts are enabled
 *
 * @api
 */
__STATIC_INLINE bool is_irq_enabled(uint32_t sts) {

    return (bool)((sts & 1UL) == 0UL);
}

/**
 * @brief   Checks if an ISR is curretly in execution
 * @note    Checks if an ISR is curretly in execution based on the content of
 *          the Interrupt Program Status register.
 *
 * @return              check result
 * @retval false        if this functions is not executed from ISR context
 * @retval true         if this functions is executed from ISR context
 *
 * @api
 */
__STATIC_INLINE bool is_isr_context(void) {

    return (bool)((__get_IPSR() & 0x1FFU) != 0U);
}

#endif /* _IRQ_H_ */

/** @} */
