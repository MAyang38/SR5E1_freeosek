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
 * @file    gpio.h
 * @brief   GPIO driver header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup SYSTEM
 * @ingroup DRIVERS
 * @addtogroup GPIO
 * @ingroup SYSTEM
 * @{
 */

#ifndef _GPIO_H_
#define _GPIO_H_

#include <platform.h>
#include <typedefs.h>

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

/**
 * @name    GPIO Port identifiers
 * @{
 */
#define GPIO_PORT_A                    0U   /**< GPIO Port A */
#define GPIO_PORT_B                    1U   /**< GPIO Port B */
#define GPIO_PORT_C                    2U   /**< GPIO Port C */
#define GPIO_PORT_D                    3U   /**< GPIO Port D */
#define GPIO_PORT_E                    4U   /**< GPIO Port E */
#define GPIO_PORT_F                    5U   /**< GPIO Port F */
#define GPIO_PORT_G                    6U   /**< GPIO Port G */
#define GPIO_PORT_H                    7U   /**< GPIO Port G */
#define GPIO_PORT_I                    8U   /**< GPIO Port I */
#define GPIO_PORT_J                    9U   /**< GPIO Port J */
#define GPIO_PORT_K                    10U  /**< GPIO Port K */
#define GPIO_PORT_L                    11U  /**< GPIO Port L */
#define GPIO_PORT_M                    12U  /**< GPIO Port M */
#define GPIO_PORT_N                    13U  /**< GPIO Port N */
#define GPIO_PORT_Q                    14U  /**< GPIO Port Q */
#define GPIO_PORT_R                    15U  /**< GPIO Port R */
#define GPIO_PORT_S                    16U  /**< GPIO Port S */
#define GPIO_PORT_T                    17U  /**< GPIO Port T */
#define GPIO_PORT_V                    18U  /**< GPIO Port V */
#define GPIO_PORT_W                    19U  /**< GPIO Port W */
#define GPIO_PORT_X                    20U  /**< GPIO Port X */
#define GPIO_PORT_Y                    21U  /**< GPIO Port Y */
/** @} */

/**
 * @name    GPIO Pin identifiers
 * @{
 */
#define GPIO_PIN_0                     0U   /**< GPIO Pin 0  */
#define GPIO_PIN_1                     1U   /**< GPIO Pin 1  */
#define GPIO_PIN_2                     2U   /**< GPIO Pin 2  */
#define GPIO_PIN_3                     3U   /**< GPIO Pin 3  */
#define GPIO_PIN_4                     4U   /**< GPIO Pin 4  */
#define GPIO_PIN_5                     5U   /**< GPIO Pin 5  */
#define GPIO_PIN_6                     6U   /**< GPIO Pin 6  */
#define GPIO_PIN_7                     7U   /**< GPIO Pin 7  */
#define GPIO_PIN_8                     8U   /**< GPIO Pin 8  */
#define GPIO_PIN_9                     9U   /**< GPIO Pin 9  */
#define GPIO_PIN_10                    10U  /**< GPIO Pin 10 */
#define GPIO_PIN_11                    11U  /**< GPIO Pin 11 */
#define GPIO_PIN_12                    12U  /**< GPIO Pin 12 */
#define GPIO_PIN_13                    13U  /**< GPIO Pin 13 */
#define GPIO_PIN_14                    14U  /**< GPIO Pin 14 */
#define GPIO_PIN_15                    15U  /**< GPIO Pin 15 */
/** @} */

/**
 * @name    GPIO mode flags
 * @{
 */
#define GPIO_MODE_MODER_POS            (0U)
#define GPIO_MODE_MODER_MASK           (3UL << GPIO_MODE_MODER_POS)
#define GPIO_MODE_MODER_INPUT          (0UL << GPIO_MODE_MODER_POS)
#define GPIO_MODE_MODER_OUTPUT         (1UL << GPIO_MODE_MODER_POS)
#define GPIO_MODE_MODER_ALTERNATE      (2UL << GPIO_MODE_MODER_POS)
#define GPIO_MODE_MODER_ANALOG         (3UL << GPIO_MODE_MODER_POS)

#define GPIO_MODE_OTYPER_POS           (2U)
#define GPIO_MODE_OTYPER_MASK          (1UL << GPIO_MODE_OTYPER_POS)
#define GPIO_MODE_OTYPER_PUSHPULL      (0UL << GPIO_MODE_OTYPER_POS)
#define GPIO_MODE_OTYPER_OPENDRAIN     (1UL << GPIO_MODE_OTYPER_POS)

#define GPIO_MODE_OSPEEDR_POS          (3U)
#define GPIO_MODE_OSPEEDR_MASK         (3UL << GPIO_MODE_OSPEEDR_POS)
#define GPIO_MODE_OSPEEDR_LOW          (0UL << GPIO_MODE_OSPEEDR_POS)
#define GPIO_MODE_OSPEEDR_MEDIUM       (1UL << GPIO_MODE_OSPEEDR_POS)
#define GPIO_MODE_OSPEEDR_HIGH         (2UL << GPIO_MODE_OSPEEDR_POS)
#define GPIO_MODE_OSPEEDR_VERYHIGH     (3UL << GPIO_MODE_OSPEEDR_POS)

#define GPIO_MODE_PUPDR_POS            (5U)
#define GPIO_MODE_PUPDR_MASK           (3UL << GPIO_MODE_PUPDR_POS)
#define GPIO_MODE_PUPDR_FLOATING       (0UL << GPIO_MODE_PUPDR_POS)
#define GPIO_MODE_PUPDR_PULLUP         (1UL << GPIO_MODE_PUPDR_POS)
#define GPIO_MODE_PUPDR_PULLDOWN       (2UL << GPIO_MODE_PUPDR_POS)

#define GPIO_MODE_AFR_POS              (7U)
#define GPIO_MODE_AFR_MASK             (15UL << GPIO_MODE_AFR_POS)
#define GPIO_MODE_AFR(n)               ((uint32_t)(n) << GPIO_MODE_AFR_POS)

#define GPIO_MODE_IHYSTR_POS           (11U)
#define GPIO_MODE_IHYSTR_MASK          (3UL << GPIO_MODE_IHYSTR_POS)
#define GPIO_MODE_IHYSTR_CMOS          (0UL << GPIO_MODE_IHYSTR_POS)
#define GPIO_MODE_IHYSTR_AUTO          (1UL << GPIO_MODE_IHYSTR_POS)
#define GPIO_MODE_IHYSTR_TTL           (2UL << GPIO_MODE_IHYSTR_POS)

#define GPIO_MODE_TRIGENR_POS          (13U)
#define GPIO_MODE_TRIGENR_MASK         (1UL << GPIO_MODE_TRIGENR_POS)
#define GPIO_MODE_TRIGENR_IN_DISABLED  (0UL << GPIO_MODE_TRIGENR_POS)
#define GPIO_MODE_TRIGENR_IN_ENABLED   (1UL << GPIO_MODE_TRIGENR_POS)

#define GPIO_MODE_SAFESELR_POS         (14U)
#define GPIO_MODE_SAFESELR_MASK        (1UL << GPIO_MODE_SAFESELR_POS)
#define GPIO_MODE_SAFESELR_DISABLED    (0UL << GPIO_MODE_SAFESELR_POS)
#define GPIO_MODE_SAFESELR_ENABLED     (1UL << GPIO_MODE_SAFESELR_POS)

#define GPIO_MODE_SAFEVALR_POS         (15U)
#define GPIO_MODE_SAFEVALR_MASK        (1UL << GPIO_MODE_SAFEVALR_POS)
#define GPIO_MODE_SAFEVALR_LOW         (0UL << GPIO_MODE_SAFEVALR_POS)
#define GPIO_MODE_SAFEVALR_HIGH        (1UL << GPIO_MODE_SAFEVALR_POS)
/** @} */

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
 * @brief   GPIO Port type.
 */
typedef uint8_t gpio_port_t;

/**
 * @brief   GPIO Pin type.
 */
typedef uint8_t gpio_pin_t;

/**
 * @brief   GPIO I/O type.
 */
typedef uint16_t gpio_io_t;

/**
 * @enum gpio_mode_t
 * GPIO Mode type.
 */
typedef enum {
    GPIO_MODER_INPUT,        /**< GPIO Mode Input              */
    GPIO_MODER_OUTPUT,       /**< GPIO Mode Output             */
    GPIO_MODER_ALTERNATE,    /**< GPIO Mode Alternate Function */
    GPIO_MODER_ANALOG        /**< GPIO Mode Analog             */
} gpio_mode_t;

/**
 * @enum gpio_otype_t
 * GPIO Output Type type.
 */
typedef enum {
    GPIO_OTYPER_PUSHPULL,    /**< GPIO Output Push-Pull  */
    GPIO_OTYPER_OPENDRAIN,   /**< GPIO Output Open-Drain */
} gpio_otype_t;

/**
 * @enum gpio_ospeed_t
 * GPIO Output Speed type.
 */
typedef enum {
    GPIO_OSPEEDR_LOW,        /**< GPIO Low Speed       */
    GPIO_OSPEEDR_MEDIUM,     /**< GPIO Medium Speed    */
    GPIO_OSPEEDR_HIGH,       /**< GPIO High Speed      */
    GPIO_OSPEEDR_VERYHIGH    /**< GPIO Very High Speed */
} gpio_ospeed_t;

/**
 * @enum gpio_pupd_t
 * GPIO Pull-up/Pull-down type.
 */
typedef enum {
    GPIO_PUPDR_FLOATING,     /**< GPIO No Pull-Up, No Pull-Down */
    GPIO_PUPDR_PULLUP,       /**< GPIO Pull-Up                  */
    GPIO_PUPDR_PULLDOWN      /**< GPIO Pull-Down                */
} gpio_pupd_t;

/**
 * @enum gpio_od_t
 * GPIO Output Data type.
 */
typedef enum {
    GPIO_ODR_LOW,            /**< GPIO Output Data Low  */
    GPIO_ODR_HIGH            /**< GPIO Output Data High */
} gpio_od_t;

/**
 * @brief   GPIO Alternate Function type.
 */
typedef uint8_t gpio_af_t;

/**
 * @enum gpio_ihyst_t
 * GPIO Port Hysteresis type.
 */
typedef enum {
    GPIO_IHYSTR_CMOS,        /**< GPIO Port Input Buffer Disabled */
    GPIO_IHYSTR_TTL,         /**< GPIO Port Input Buffer Enabled  */
    GPIO_IHYSTR_AUTO,        /**< GPIO Port Input Buffer Enabled  */
} gpio_ihyst_t;

/**
 * @enum gpio_trigen_t
 * GPIO Port Input Buffer Enable type.
 */
typedef enum {
    GPIO_TRIGENR_IN_DISABLED,     /**< GPIO Port Input Buffer Disabled */
    GPIO_TRIGENR_IN_ENABLED       /**< GPIO Port Input Buffer Enabled  */
} gpio_trigen_t;

/**
 * @enum gpio_safesel_t
 * GPIO Safe IO Selection Enable type.
 */
typedef enum {
    GPIO_SAFESEL_DISABLED,   /**< GPIO Safe IO Selection Disabled */
    GPIO_SAFESEL_ENABLED     /**< GPIO Safe IO Selection Enabled  */
} gpio_safesel_t;

/**
 * @enum gpio_safeval_t
 * GPIO Safe IO Selection value type.
 */
typedef enum {
    GPIO_SAFEVAL_LOW,        /**< GPIO Safe IO Selection Low  */
    GPIO_SAFEVAL_HIGT        /**< GPIO Safe IO Selection High */
} gpio_safeval_t;

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/**
 * @brief   Packs unique pin identifier.
 * @note    The low nibble contains the pin number, the high nibble the port
 *          number.
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
 *            @arg @ref GPIO_PORT_J
 *            @arg @ref GPIO_PORT_K
 *            @arg @ref GPIO_PORT_L
 *            @arg @ref GPIO_PORT_M
 *            @arg @ref GPIO_PORT_N
 *            @arg @ref GPIO_PORT_Q
 *            @arg @ref GPIO_PORT_R
 *            @arg @ref GPIO_PORT_S
 *            @arg @ref GPIO_PORT_T
 *            @arg @ref GPIO_PORT_V
 *            @arg @ref GPIO_PORT_W
 *            @arg @ref GPIO_PORT_X
 *            @arg @ref GPIO_PORT_Y
 * @param[in] pin       pin number; it can be one of the following values:
 *            @arg @ref GPIO_PIN_0
 *            @arg @ref GPIO_PIN_1
 *            @arg @ref GPIO_PIN_2
 *            @arg @ref GPIO_PIN_3
 *            @arg @ref GPIO_PIN_4
 *            @arg @ref GPIO_PIN_5
 *            @arg @ref GPIO_PIN_6
 *            @arg @ref GPIO_PIN_7
 *            @arg @ref GPIO_PIN_8
 *            @arg @ref GPIO_PIN_9
 *            @arg @ref GPIO_PIN_10
 *            @arg @ref GPIO_PIN_11
 *            @arg @ref GPIO_PIN_12
 *            @arg @ref GPIO_PIN_13
 *            @arg @ref GPIO_PIN_14
 *            @arg @ref GPIO_PIN_15
 * @return              unique pin identifier
 *
 * @api
 */
#define gpio_iopack(_port_, _pin_)                                             \
    ((gpio_io_t)((((uint32_t)(_port_)) << 4U) | (((uint32_t)(_pin_)) & 0x0FU)))

/**
 * @brief   Unpacks unique pin identifier.
 * @note    Returns port number related to the unique pin identifier.
 *
 * @param[in]           unique pin identifier
 * @return              port number; it can be one of the following values:
 *            @arg @ref GPIO_PORT_A
 *            @arg @ref GPIO_PORT_B
 *            @arg @ref GPIO_PORT_C
 *            @arg @ref GPIO_PORT_D
 *            @arg @ref GPIO_PORT_E
 *            @arg @ref GPIO_PORT_F
 *            @arg @ref GPIO_PORT_G
 *            @arg @ref GPIO_PORT_H
 *            @arg @ref GPIO_PORT_I
 *            @arg @ref GPIO_PORT_J
 *            @arg @ref GPIO_PORT_K
 *            @arg @ref GPIO_PORT_L
 *            @arg @ref GPIO_PORT_M
 *            @arg @ref GPIO_PORT_N
 *            @arg @ref GPIO_PORT_Q
 *            @arg @ref GPIO_PORT_R
 *            @arg @ref GPIO_PORT_S
 *            @arg @ref GPIO_PORT_T
 *            @arg @ref GPIO_PORT_V
 *            @arg @ref GPIO_PORT_W
 *            @arg @ref GPIO_PORT_X
 *            @arg @ref GPIO_PORT_Y
 *
 * @api
 */
#define gpio_iounpack_port(_io_)                                               \
    ((gpio_port_t)(((uint32_t)(_io_)) >> 4U))

/**
 * @brief   Unpacks unique pin identifier.
 * @note    Returns pin number related to the unique pin identifier.
 *
 * @param[in]           unique pin identifier
 * @return              pin number; it can be one of the following values:
 *            @arg @ref GPIO_PIN_0
 *            @arg @ref GPIO_PIN_1
 *            @arg @ref GPIO_PIN_2
 *            @arg @ref GPIO_PIN_3
 *            @arg @ref GPIO_PIN_4
 *            @arg @ref GPIO_PIN_5
 *            @arg @ref GPIO_PIN_6
 *            @arg @ref GPIO_PIN_7
 *            @arg @ref GPIO_PIN_8
 *            @arg @ref GPIO_PIN_9
 *            @arg @ref GPIO_PIN_10
 *            @arg @ref GPIO_PIN_11
 *            @arg @ref GPIO_PIN_12
 *            @arg @ref GPIO_PIN_13
 *            @arg @ref GPIO_PIN_14
 *            @arg @ref GPIO_PIN_15
 *
 * @api
 */
#define gpio_iounpack_pin(_io_)                                                \
    ((gpio_pin_t)(((uint32_t)(_io_)) & 0x0FU));

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

/* Export driver modules.*/
#include <gpio_dev.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Initializes GPIO instances.
 *
 * @api
 */
void gpio_init(void);

#ifdef __cplusplus
}
#endif

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/**
 * @brief   Sets Mode Register pin value.
 * @note    Sets Mode value of the pin related to the unique pin identifier.
 *
 * @param[in] io        unique pin identifier
 * @param[in] mode      mode value; it can be one of the following values:
 *            @arg @ref GPIO_MODER_INPUT
 *            @arg @ref GPIO_MODER_OUTPUT
 *            @arg @ref GPIO_MODER_ALTERNATE
 *            @arg @ref GPIO_MODER_ANALOG
 *
 * @api
 */
__STATIC_INLINE void gpio_set_pin_moder(gpio_io_t io,
                                        gpio_mode_t mode) {


    gpio_port_t port = gpio_iounpack_port(io);
    gpio_pin_t pin   = gpio_iounpack_pin(io);
    GPIO_TypeDef *p  = gpio_dev_get_port_reg_ptr(port);

    if (p != NULL) {
        p->MODER &= (uint32_t)(~(0x3U << (2 * pin)));
        p->MODER |= (uint32_t)((mode & 0x3U) << (2 * pin));
    }
}

/**
 * @brief   Sets Output Type pin value.
 * @note    Sets Output Type value of the pin related to the unique pin
 *          identifier.
 *
 * @param[in] io        unique pin identifier
 * @param[in] otype     output type value; it can be one of the following
 *                      values:
 *            @arg @ref GPIO_OTYPER_PUSHPULL
 *            @arg @ref GPIO_OTYPER_OPENDRAIN
 *
 * @api
 */
__STATIC_INLINE void gpio_set_pin_otyper(gpio_io_t io,
                                         gpio_otype_t otype) {

    gpio_port_t port = gpio_iounpack_port(io);
    gpio_pin_t pin   = gpio_iounpack_pin(io);
    GPIO_TypeDef *p  = gpio_dev_get_port_reg_ptr(port);

    if (p != NULL) {
        p->OTYPER &= (uint32_t)((~(0x1U << pin)));
        p->OTYPER |= (uint32_t)((otype & 0x1U) << pin);
    }
}

/**
 * @brief   Sets Output Speed pin value.
 * @note    Sets Output Speed value of the pin related to the unique pin
 *          identifier.
 *
 * @param[in] io        unique pin identifier
 * @param[in] ospeed    output speed value; it can be one of the following
 *                      values:
 *            @arg @ref GPIO_OSPEEDR_LOW
 *            @arg @ref GPIO_OSPEEDR_MEDIUM
 *            @arg @ref GPIO_OSPEEDR_HIGH
 *            @arg @ref GPIO_OSPEEDR_VERYHIGH
 *
 * @api
 */
__STATIC_INLINE void gpio_set_pin_ospeedr(gpio_io_t io,
                                          gpio_ospeed_t ospeed) {

    gpio_port_t port = gpio_iounpack_port(io);
    gpio_pin_t pin   = gpio_iounpack_pin(io);
    GPIO_TypeDef *p  = gpio_dev_get_port_reg_ptr(port);

    if (p != NULL) {
        p->OSPEEDR &= (uint32_t)(~(0x3U << (2 * pin)));
        p->OSPEEDR |= (uint32_t)((ospeed & 0x3U) << (2 * pin));
    }
}

/**
 * @brief   Sets Pull-up/Pull-down pin value.
 * @note    Sets Pull-up/Pull-down value of the pin related to the unique pin
 *          identifier.
 *
 * @param[in] io        unique pin identifier
 * @param[in] pupd      pull-up/pull-down value; it can be one of the following
 *                      values:
 *            @arg @ref GPIO_PUPDR_FLOATING
 *            @arg @ref GPIO_PUPDR_PULLUP
 *            @arg @ref GPIO_PUPDR_PULLDOWN
 *
 * @api
 */
__STATIC_INLINE void gpio_set_pin_pupdr(gpio_io_t io,
                                        gpio_pupd_t pupd) {

    gpio_port_t port = gpio_iounpack_port(io);
    gpio_pin_t pin   = gpio_iounpack_pin(io);
    GPIO_TypeDef *p  = gpio_dev_get_port_reg_ptr(port);

    if (p != NULL) {
        p->PUPDR &= (uint32_t)((~(0x3U << (2 * pin))));
        p->PUPDR |= (uint32_t)((pupd & 0x3U) << (2 * pin));
    }
}

/**
 * @brief   Sets Output Data pin value.
 * @note    Sets Output Data value of the pin related to the unique pin
 *          identifier.
 *
 * @param[in] io        unique pin identifier
 * @param[in] od        output data value; it can be one of the following
 *                      values:
 *            @arg @ref GPIO_ODR_LOW
 *            @arg @ref GPIO_ODR_HIGH
 *
 * @api
 */
__STATIC_INLINE void gpio_set_pin_odr(gpio_io_t io,
                                      gpio_od_t od) {

    gpio_port_t port = gpio_iounpack_port(io);
    gpio_pin_t pin   = gpio_iounpack_pin(io);
    GPIO_TypeDef *p  = gpio_dev_get_port_reg_ptr(port);

    if (p != NULL) {
        p->ODR &= (uint32_t)((~(0x1U << pin)));
        p->ODR |= (uint32_t)((od & 0x1U) << pin);
    }
}

/**
 * @brief   Sets Alternate Function pin value.
 * @note    Sets Alternate Function value of the pin related to the unique pin
 *          identifier.
 *
 * @param[in] io        unique pin identifier
 * @param[in] af        alternate function value
 *
 * @api
 */
__STATIC_INLINE void gpio_set_pin_afr(gpio_io_t io,
                                      gpio_af_t af) {

    gpio_port_t port = gpio_iounpack_port(io);
    gpio_pin_t pin   = gpio_iounpack_pin(io);
    GPIO_TypeDef *p  = gpio_dev_get_port_reg_ptr(port);

    if (p != NULL) {
        if (pin < 8U) {
            p->AFR[0] &= (uint32_t)(~(0xFU << (4 * pin)));
            p->AFR[0] |= (uint32_t)((af & 0xFU) << (4 * pin));
        } else {
            p->AFR[1] &= (uint32_t)(~(0xFU << (4 * (pin - 8))));
            p->AFR[1] |= (uint32_t)((af & 0xFU) << (4 * (pin - 8)));
        }
    }
}

/**
 * @brief   Sets Hysteresis pin value.
 * @note    Sets Hysteresis value of the pin related to the unique pin
 *          identifier.
 *
 * @param[in] io        unique pin identifier
 * @param[in] ihyst     pin hysteresis value; it can be one of the following
 *                      values:
 *            @arg @ref GPIO_IHYSTR_CMOS
 *            @arg @ref GPIO_IHYSTR_TTL
 *            @arg @ref GPIO_IHYSTR_AUTO
 *
 * @api
 */
__STATIC_INLINE void gpio_set_pin_ihystr(gpio_io_t io,
                                         gpio_ihyst_t ihyst) {

    gpio_port_t port = gpio_iounpack_port(io);
    gpio_pin_t pin   = gpio_iounpack_pin(io);
    GPIO_TypeDef *p  = gpio_dev_get_port_reg_ptr(port);

    if (p != NULL) {
        p->IHYSTR &= (uint32_t)((~(0x3U << (2 * pin))));
        p->IHYSTR |= (uint32_t)((ihyst & 0x3U) << (2 * pin));
    }
}

/**
 * @brief   Sets Port Input Buffer Enable pin value.
 * @note    Sets Port Input Buffer Enable value of the pin related to the
 *          unique pin identifier.
 *
 * @param[in] io        unique pin identifier
 * @param[in] trigen    pin input buffer enable value; it can be one of the
 *                      following values:
 *            @arg @ref GPIO_TRIGENR_IN_DISABLED
 *            @arg @ref GPIO_TRIGENR_IN_ENABLED
 *
 * @api
 */
__STATIC_INLINE void gpio_set_pin_trigenr(gpio_io_t io,
                                          gpio_trigen_t trigen) {

    gpio_port_t port = gpio_iounpack_port(io);
    gpio_pin_t pin   = gpio_iounpack_pin(io);
    GPIO_TypeDef *p  = gpio_dev_get_port_reg_ptr(port);

    if (p != NULL) {
        p->TRIGENR &= (uint32_t)(~(0x1U << pin));
        p->TRIGENR |= (uint32_t)((trigen & 0x1U) << pin);
    }
}

/**
 * @brief   Sets Safe IO Selection pin value.
 * @note    Sets Safe IO Selection value of the pin related to the unique pin
 *          identifier.
 *
 * @param[in] io        unique pin identifier
 * @param[in] safesel   safe io selection value; it can be one of the following
 *                      values:
 *            @arg @ref GPIO_SAFESEL_DISABLED
 *            @arg @ref GPIO_SAFESEL_ENABLED
 *
 * @api
 */
__STATIC_INLINE void gpio_set_pin_safeselr(gpio_io_t io,
                                           gpio_safesel_t safesel) {

    gpio_port_t port = gpio_iounpack_port(io);
    gpio_pin_t pin   = gpio_iounpack_pin(io);
    GPIO_TypeDef *p  = gpio_dev_get_port_reg_ptr(port);

    if (p != NULL) {
        p->SAFESELR &= (uint32_t)(~(0x1U << pin));
        p->SAFESELR |= (uint32_t)((safesel & 0x1U) << pin);
    }
}

/**
 * @brief   Sets Safe IO Output pin value.
 * @note    Sets Safe IO Output value of the pin related to the unique pin
 *          identifier.
 *
 * @param[in] io        unique pin identifier
 * @param[in] safeval   safe io output value; it can be one of the following
 *                      values:
 *            @arg @ref GPIO_SAFEVAL_LOW
 *            @arg @ref GPIO_SAFEVAL_HIGT
 *
 * @api
 */
__STATIC_INLINE void gpio_set_pin_safevalr(gpio_io_t io,
                                           gpio_safeval_t safeval) {

    gpio_port_t port = gpio_iounpack_port(io);
    gpio_pin_t pin   = gpio_iounpack_pin(io);
    GPIO_TypeDef *p  = gpio_dev_get_port_reg_ptr(port);

    if (p != NULL) {
        p->SAFEVALR &= (uint32_t)(~(0x1U << pin));
        p->SAFEVALR |= (uint32_t)((safeval & 0x1U) << pin);
    }
}

/**
 * @brief   Configures pin mode
 * @note    Congigures properties of the pin related to the unique pin
 *          identifier.
 *
 * @param[in] io        unique pin identifier
 * @param[in] mode      pin configuration
 *
 * @api
 */
__STATIC_INLINE void gpio_set_pin_mode(gpio_io_t io,
                                       uint32_t mode) {

    gpio_set_pin_moder   (io, (gpio_mode_t)((mode & GPIO_MODE_MODER_MASK) >> GPIO_MODE_MODER_POS));
    gpio_set_pin_otyper  (io, (gpio_otype_t)((mode & GPIO_MODE_OTYPER_MASK) >> GPIO_MODE_OTYPER_POS));
    gpio_set_pin_ospeedr (io, (gpio_ospeed_t)((mode & GPIO_MODE_OSPEEDR_MASK) >> GPIO_MODE_OSPEEDR_POS));
    gpio_set_pin_pupdr   (io, (gpio_pupd_t)((mode & GPIO_MODE_PUPDR_MASK) >> GPIO_MODE_PUPDR_POS));
    gpio_set_pin_afr     (io, (gpio_af_t)((mode & GPIO_MODE_AFR_MASK) >> GPIO_MODE_AFR_POS));
    gpio_set_pin_ihystr  (io, (gpio_ihyst_t)((mode & GPIO_MODE_IHYSTR_MASK) >> GPIO_MODE_IHYSTR_POS));
    gpio_set_pin_trigenr (io, (gpio_trigen_t)((mode & GPIO_MODE_TRIGENR_MASK) >> GPIO_MODE_TRIGENR_POS));
    gpio_set_pin_safeselr(io, (gpio_safesel_t)((mode & GPIO_MODE_SAFESELR_MASK) >> GPIO_MODE_SAFESELR_POS));
    gpio_set_pin_safevalr(io, (gpio_safeval_t)((mode & GPIO_MODE_SAFEVALR_MASK) >> GPIO_MODE_SAFEVALR_POS));
}

/**
 * @brief   Reads Port input data.
 *
 * @param[in] io        unique pin identifier
 * @return              port input data
 *
 * @api
 */
__STATIC_INLINE uint32_t gpio_read_port(gpio_io_t io) {

    gpio_port_t port = gpio_iounpack_port(io);
    GPIO_TypeDef *p  = gpio_dev_get_port_reg_ptr(port);

    if (p != NULL) {
        return p->IDR;
    } else {
        return 0UL;
    }
}

/**
 * @brief   Reads Port output data.
 *
 * @param[in] io        unique pin identifier
 * @return              port output data
 *
 * @api
 */
__STATIC_INLINE uint32_t gpio_read_port_latch(gpio_io_t io) {

    gpio_port_t port = gpio_iounpack_port(io);
    GPIO_TypeDef *p  = gpio_dev_get_port_reg_ptr(port);

    if (p != NULL) {
        return p->ODR;
    } else {
        return 0UL;
    }
}

/**
 * @brief   Writes Port ouput data.
 *
 * @param[in] io        unique pin identifier
 * @param[in] value     output data to write
 *
 * @api
 */
__STATIC_INLINE void gpio_write_port(gpio_io_t io,
                                     uint32_t value) {

    gpio_port_t port = gpio_iounpack_port(io);
    GPIO_TypeDef *p  = gpio_dev_get_port_reg_ptr(port);

    if (p != NULL) {
        p->ODR = value;
    }
}

/**
 * @brief   Sets Port value.
 *
 * @param[in] io        unique pin identifier
 * @param[in] value     value to be set
 *
 * @api
 */
__STATIC_INLINE void gpio_set_port(gpio_io_t io,
                                   uint32_t value) {

    gpio_port_t port = gpio_iounpack_port(io);
    GPIO_TypeDef *p  = gpio_dev_get_port_reg_ptr(port);

    if (p != NULL) {
        p->BSRR = value;
    }
}

/**
 * @brief   Resets Port value.
 *
 * @param[in] io        unique pin identifier
 * @param[in] value     reset value
 *
 * @api
 */
__STATIC_INLINE void gpio_clear_port(gpio_io_t io,
                                     uint32_t value) {

    gpio_port_t port = gpio_iounpack_port(io);
    GPIO_TypeDef *p  = gpio_dev_get_port_reg_ptr(port);

    if (p != NULL) {
        p->BSRR = (value << 16U);
    }
}

/**
 * @brief   Reads Pin input data.
 *
 * @param[in] io        unique pin identifier
 * @return              pin input data
 *
 * @api
 */
__STATIC_INLINE uint32_t gpio_read_pin(gpio_io_t io) {

    gpio_port_t port = gpio_iounpack_port(io);
    gpio_pin_t pin   = gpio_iounpack_pin(io);
    GPIO_TypeDef *p  = gpio_dev_get_port_reg_ptr(port);

    if (p != NULL) {
        return (p->IDR & (1U << pin)) != 0U;
    } else {
        return 0UL;
    }
}

/**
 * @brief   Reads Pin output data.
 *
 * @param[in] io        unique pin identifier
 * @return              pin output data
 *
 * @api
 */
__STATIC_INLINE uint32_t gpio_read_pin_latch(gpio_io_t io) {

    gpio_port_t port = gpio_iounpack_port(io);
    gpio_pin_t pin   = gpio_iounpack_pin(io);
    GPIO_TypeDef *p  = gpio_dev_get_port_reg_ptr(port);

    if (p != NULL) {
        return (p->ODR & (1U << pin)) != 0U;
    } else {
        return 0UL;
    }
}

/**
 * @brief   Writes Pin ouput data.
 *
 * @param[in] io        unique pin identifier
 * @param[in] bit       output data to write
 *
 * @api
 */
__STATIC_INLINE void gpio_write_pin(gpio_io_t io, uint32_t bit) {

    gpio_port_t port = gpio_iounpack_port(io);
    gpio_pin_t pin   = gpio_iounpack_pin(io);
    GPIO_TypeDef *p  = gpio_dev_get_port_reg_ptr(port);

    if (p != NULL) {
        if (bit != 0U) {
            p->BSRR = (uint32_t)(1U << pin);
        }
        else {
            p->BSRR = (uint32_t)(0x10000U << pin);
        }
    }
}

/**
 * @brief   Sets Pin value.
 *
 * @param[in] io        unique pin identifier
 *
 * @api
 */
__STATIC_INLINE void gpio_set_pin(gpio_io_t io) {

    gpio_port_t port = gpio_iounpack_port(io);
    gpio_pin_t pin   = gpio_iounpack_pin(io);
    GPIO_TypeDef *p  = gpio_dev_get_port_reg_ptr(port);

    if (p != NULL) {
        p->BSRR = (uint32_t)(1U << pin);
    }
}

/**
 * @brief   Resets Pin value.
 *
 * @param[in] io        unique pin identifier
 *
 * @api
 */
__STATIC_INLINE void gpio_clear_pin(gpio_io_t io) {

    gpio_port_t port = gpio_iounpack_port(io);
    gpio_pin_t pin   = gpio_iounpack_pin(io);
    GPIO_TypeDef *p  = gpio_dev_get_port_reg_ptr(port);

    if (p != NULL) {
        p->BSRR = (uint32_t)(0x10000U << pin);
    }
}

/**
 * @brief   Toggles Pin value.
 *
 * @param[in] io        unique pin identifier
 *
 * @api
 */
__STATIC_INLINE void gpio_toggle_pin(gpio_io_t io) {

    gpio_port_t port = gpio_iounpack_port(io);
    gpio_pin_t pin   = gpio_iounpack_pin(io);
    GPIO_TypeDef *p  = gpio_dev_get_port_reg_ptr(port);

    if (p != NULL) {
        if ((p->ODR & (1U << pin)) != 0U) {
            p->BSRR = (uint32_t)(0x10000U << pin);
        } else {
            p->BSRR = (uint32_t)(1U << pin);
        }
    }
}

/**
 * @brief   Locks Pin value.
 *
 * @param[in] io        unique pin identifier
 *
 * @api
 */
__STATIC_INLINE void gpio_lock_pin(gpio_io_t io) {

    gpio_port_t port = gpio_iounpack_port(io);
    gpio_pin_t pin   = gpio_iounpack_pin(io);
    GPIO_TypeDef *p  = gpio_dev_get_port_reg_ptr(port);
    __IO uint32_t temp;

    if (p != NULL) {
        p->LCKR = GPIO_LCKR_LCKK | (0x1U << pin);
        p->LCKR = (0x1U << pin);
        p->LCKR = GPIO_LCKR_LCKK | (0x1U << pin);
        temp = p->LCKR;
    }

    (void) temp;
}

/*===========================================================================*/
/* Module late inclusions.                                                   */
/*===========================================================================*/

#endif /* _GPIO_H_ */

/** @} */
