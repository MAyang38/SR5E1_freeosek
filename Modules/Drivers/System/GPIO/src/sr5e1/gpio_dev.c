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
 * @file    gpio_dev.c
 * @brief   GPIO device specific source file.
 *
 * @addtogroup DRIVERS
 * @addtogroup SYSTEM
 * @ingroup DRIVERS
 * @addtogroup GPIO
 * @ingroup SYSTEM
 * @{
 */

#include <gpio.h>

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
 * @brief   Enables GPIO port clocks.
 *
 * @notapi
 */
void gpio_dev_init(void) {


    const uint32_t enr = (0UL                |
                          RCC_AHB2LENR_GPIOA |
                          RCC_AHB2LENR_GPIOB |
                          RCC_AHB2LENR_GPIOC |
                          RCC_AHB2LENR_GPIOD |
                          RCC_AHB2LENR_GPIOE |
                          RCC_AHB2LENR_GPIOF |
                          RCC_AHB2LENR_GPIOG |
                          RCC_AHB2LENR_GPIOH |
                          RCC_AHB2LENR_GPIOI);

    /* Enabling GPIO RCC clocks, reading back for synchronization.*/
    RCC->AHB2LENR |= enr;
    (void)RCC->AHB2LENR;
}

/**
 * @brief   Returns pointer to Port registers.
 *
 * @param[in] port      port number; it can be one of the following values:
 *            @arg @ref GPIO_PORT_A
 *            @arg @ref GPIO_PORT_B
 *            @arg @ref GPIO_PORT_C
 *            @arg @ref GPIO_PORT_D
 *            @arg @ref GPIO_PORT_E
 *            @arg @ref GPIO_PORT_F
 *            @arg @ref GPIO_PORT_G
 *            @arg @ref GPIO_PORT_H
 *            @arg @ref GPIO_PORT_I
 * @return              pointer to port registers
 *
 * @notapi
 */
GPIO_TypeDef *gpio_dev_get_port_reg_ptr(gpio_port_t port) {

    switch(port) {
        case GPIO_PORT_A:
            return (GPIOA);
        case GPIO_PORT_B:
            return (GPIOB);
        case GPIO_PORT_C:
            return (GPIOC);
        case GPIO_PORT_D:
            return (GPIOD);
        case GPIO_PORT_E:
            return (GPIOE);
        case GPIO_PORT_F:
            return (GPIOF);
        case GPIO_PORT_G:
            return (GPIOG);
        case GPIO_PORT_H:
            return (GPIOH);
        case GPIO_PORT_I:
            return (GPIOI);
        case GPIO_PORT_J:
        case GPIO_PORT_K:
        case GPIO_PORT_L:
        case GPIO_PORT_M:
        case GPIO_PORT_N:
        case GPIO_PORT_Q:
        case GPIO_PORT_R:
        case GPIO_PORT_S:
        case GPIO_PORT_T:
        case GPIO_PORT_V:
        case GPIO_PORT_W:
        case GPIO_PORT_X:
        case GPIO_PORT_Y:
        default:
            return (NULL);
    }
}

/** @} */
