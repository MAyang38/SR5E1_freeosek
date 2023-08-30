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
 * @file    comp.h
 * @brief   COMP driver header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup ANALOG
 * @ingroup DRIVERS
 * @addtogroup COMP
 * @ingroup ANALOG
 * @{
 */

#ifndef _COMP_H_
#define _COMP_H_

#include <typedefs.h>

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

/**
 * @brief   COMP1 input plus (non-inverting input).
 */
#define COMP_COMP1_INPUT_PLUS_PB2           0U
#define COMP_COMP1_INPUT_PLUS_PB3           1U

/**
 * @brief   COMP2 input plus (non-inverting input).
 */
#define COMP_COMP2_INPUT_PLUS_PB2           0U
#define COMP_COMP2_INPUT_PLUS_PB4           1U

/**
 * @brief   COMP3 input plus (non-inverting input).
 */
#define COMP_COMP3_INPUT_PLUS_PB7           0U
#define COMP_COMP3_INPUT_PLUS_PB8           1U

/**
 * @brief   COMP4 input plus (non-inverting input).
 */
#define COMP_COMP4_INPUT_PLUS_PB7           0U
#define COMP_COMP4_INPUT_PLUS_PB9           1U

/**
 * @brief   COMP5 input plus (non-inverting input).
 */
#define COMP_COMP5_INPUT_PLUS_PB12          0U
#define COMP_COMP5_INPUT_PLUS_PB13          1U

/**
 * @brief   COMP6 input plus (non-inverting input).
 */
#define COMP_COMP6_INPUT_PLUS_PB12          0U
#define COMP_COMP6_INPUT_PLUS_PB14          1U

/**
 * @brief   COMP7 input plus (non-inverting input).
 */
#define COMP_COMP7_INPUT_PLUS_PC3           0U
#define COMP_COMP7_INPUT_PLUS_PC4           1U

/**
 * @brief   COMP8 input plus (non-inverting input).
 */
#define COMP_COMP8_INPUT_PLUS_PC3           0U
#define COMP_COMP8_INPUT_PLUS_PC6           1U

/**
 * @brief   COMP1 input minus (inverting input).
 */
#define COMP_COMP1_INPUT_MINUS_DAC1_CH1     0U
#define COMP_COMP1_INPUT_MINUS_PB1          1U
#define COMP_COMP1_INPUT_MINUS_TEST_CH      2U
#define COMP_COMP1_INPUT_MINUS_TEST_VREF    3U

/**
 * @brief   COMP2 input minus (inverting input).
 */
#define COMP_COMP2_INPUT_MINUS_DAC1_CH2     0U
#define COMP_COMP2_INPUT_MINUS_PB5          1U
#define COMP_COMP2_INPUT_MINUS_TEST_CH      2U
#define COMP_COMP2_INPUT_MINUS_TEST_VREF    3U

/**
 * @brief   COMP3 input minus (inverting input).
 */
#define COMP_COMP3_INPUT_MINUS_DAC2_CH1     0U
#define COMP_COMP3_INPUT_MINUS_PB13         1U
#define COMP_COMP3_INPUT_MINUS_TEST_CH      2U
#define COMP_COMP3_INPUT_MINUS_TEST_VREF    3U

/**
 * @brief   COMP4 input minus (inverting input).
 */
#define COMP_COMP4_INPUT_MINUS_DAC2_CH2     0U
#define COMP_COMP4_INPUT_MINUS_PB10         1U
#define COMP_COMP4_INPUT_MINUS_TEST_CH      2U
#define COMP_COMP4_INPUT_MINUS_TEST_VREF    3U

/**
 * @brief   COMP5 input minus (inverting input).
 */
#define COMP_COMP5_INPUT_MINUS_DAC3_CH1     0U
#define COMP_COMP5_INPUT_MINUS_PC4          1U
#define COMP_COMP5_INPUT_MINUS_TEST_CH      2U
#define COMP_COMP5_INPUT_MINUS_TEST_VREF    3U

/**
 * @brief   COMP6 input minus (inverting input).
 */
#define COMP_COMP6_INPUT_MINUS_DAC3_CH2     0U
#define COMP_COMP6_INPUT_MINUS_PB15         1U
#define COMP_COMP6_INPUT_MINUS_TEST_CH      2U
#define COMP_COMP6_INPUT_MINUS_TEST_VREF    3U

/**
 * @brief   COMP7 input minus (inverting input).
 */
#define COMP_COMP7_INPUT_MINUS_DAC4_CH1     0U
#define COMP_COMP7_INPUT_MINUS_PB8          1U
#define COMP_COMP7_INPUT_MINUS_TEST_CH      2U
#define COMP_COMP7_INPUT_MINUS_TEST_VREF    3U

/**
 * @brief   COMP8 input minus (inverting input).
 */
#define COMP_COMP8_INPUT_MINUS_DAC4_CH2     0U
#define COMP_COMP8_INPUT_MINUS_PC7          1U
#define COMP_COMP8_INPUT_MINUS_TEST_CH      2U
#define COMP_COMP8_INPUT_MINUS_TEST_VREF    3U

/**
 * @brief   COMP1 blanking selection.
 */
#define COMP_COMP1_BLANKSRC_NONE            0U
#define COMP_COMP1_BLANKSRC_TIM1_OC5        1U
#define COMP_COMP1_BLANKSRC_TIM2_OC3        2U
#define COMP_COMP1_BLANKSRC_TIM3_OC3        3U
#define COMP_COMP1_BLANKSRC_TIM8_OC5        4U
#define COMP_COMP1_BLANKSRC_TIM3_OC4        5U
#define COMP_COMP1_BLANKSRC_TIM15_OC1       6U
#define COMP_COMP1_BLANKSRC_TIM4_OC3        7U

/**
 * @brief   COMP2 blanking selection.
 */
#define COMP_COMP2_BLANKSRC_NONE            0U
#define COMP_COMP2_BLANKSRC_TIM1_OC5        1U
#define COMP_COMP2_BLANKSRC_TIM2_OC4        2U
#define COMP_COMP2_BLANKSRC_TIM3_OC3        3U
#define COMP_COMP2_BLANKSRC_TIM8_OC5        4U
#define COMP_COMP2_BLANKSRC_TIM3_OC4        5U
#define COMP_COMP2_BLANKSRC_TIM15_OC1       6U
#define COMP_COMP2_BLANKSRC_TIM4_OC3        7U

/**
 * @brief   COMP3 blanking selection.
 */
#define COMP_COMP3_BLANKSRC_NONE            0U
#define COMP_COMP3_BLANKSRC_TIM1_OC5        1U
#define COMP_COMP3_BLANKSRC_TIM3_OC3        2U
#define COMP_COMP3_BLANKSRC_TIM2_OC4        3U
#define COMP_COMP3_BLANKSRC_TIM8_OC5        4U
#define COMP_COMP3_BLANKSRC_TIM3_OC4        5U
#define COMP_COMP3_BLANKSRC_TIM15_OC1       6U
#define COMP_COMP3_BLANKSRC_TIM4_OC3        7U

/**
 * @brief   COMP4 blanking selection.
 */
#define COMP_COMP4_BLANKSRC_NONE            0U
#define COMP_COMP4_BLANKSRC_TIM1_OC5        1U
#define COMP_COMP4_BLANKSRC_TIM3_OC3        2U
#define COMP_COMP4_BLANKSRC_TIM2_OC4        3U
#define COMP_COMP4_BLANKSRC_TIM8_OC5        4U
#define COMP_COMP4_BLANKSRC_TIM3_OC4        5U
#define COMP_COMP4_BLANKSRC_TIM15_OC1       6U
#define COMP_COMP4_BLANKSRC_TIM4_OC3        7U

/**
 * @brief   COMP5 blanking selection.
 */
#define COMP_COMP5_BLANKSRC_NONE            0U
#define COMP_COMP5_BLANKSRC_TIM2_OC3        1U
#define COMP_COMP5_BLANKSRC_TIM8_OC5        2U
#define COMP_COMP5_BLANKSRC_TIM3_OC3        3U
#define COMP_COMP5_BLANKSRC_TIM1_OC5        4U
#define COMP_COMP5_BLANKSRC_TIM3_OC4        5U
#define COMP_COMP5_BLANKSRC_TIM15_OC1       6U
#define COMP_COMP5_BLANKSRC_TIM4_OC3        7U

/**
 * @brief   COMP6 blanking selection.
 */
#define COMP_COMP6_BLANKSRC_NONE            0U
#define COMP_COMP6_BLANKSRC_TIM2_OC3        1U
#define COMP_COMP6_BLANKSRC_TIM8_OC5        2U
#define COMP_COMP6_BLANKSRC_TIM3_OC3        3U
#define COMP_COMP6_BLANKSRC_TIM1_OC5        4U
#define COMP_COMP6_BLANKSRC_TIM3_OC4        5U
#define COMP_COMP6_BLANKSRC_TIM15_OC1       6U
#define COMP_COMP6_BLANKSRC_TIM4_OC3        7U

/**
 * @brief   COMP6 blanking selection.
 */
#define COMP_COMP7_BLANKSRC_NONE            0U
#define COMP_COMP7_BLANKSRC_TIM1_OC5        1U
#define COMP_COMP7_BLANKSRC_TIM8_OC5        2U
#define COMP_COMP7_BLANKSRC_TIM3_OC3        3U
#define COMP_COMP7_BLANKSRC_TIM15_OC2       4U
#define COMP_COMP7_BLANKSRC_TIM3_OC4        5U
#define COMP_COMP7_BLANKSRC_TIM15_OC1       6U
#define COMP_COMP7_BLANKSRC_TIM4_OC3        7U

/**
 * @brief   COMP8 blanking selection.
 */
#define COMP_COMP8_BLANKSRC_NONE            0U
#define COMP_COMP8_BLANKSRC_TIM1_OC5        1U
#define COMP_COMP8_BLANKSRC_TIM8_OC5        2U
#define COMP_COMP8_BLANKSRC_TIM3_OC3        3U
#define COMP_COMP8_BLANKSRC_TIM15_OC2       4U
#define COMP_COMP8_BLANKSRC_TIM3_OC4        5U
#define COMP_COMP8_BLANKSRC_TIM15_OC1       6U
#define COMP_COMP8_BLANKSRC_TIM4_OC3        7U

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
 * @brief   Type of an COMP driver.
 */
typedef struct comp_driver comp_driver_t;

/**
 * @brief   Type of an COMP notification callback.
 *
 * @param[in] cdp       pointer to the @p comp_driver_t object
 */
typedef void (*comp_cb_t)(comp_driver_t *cdp);

/**
 * @enum comp_hysteresis_t
 * COMP hysteresis supported configurations.
 */
typedef enum {
    COMP_HYSTERESIS_NONE,    /**< No hysteresis  */
    COMP_HYSTERESIS_10MV,    /**< Hysteresis level 10mV */
    COMP_HYSTERESIS_20MV,    /**< Hysteresis level 20mV */
    COMP_HYSTERESIS_30MV,    /**< Hysteresis level 30mV */
    COMP_HYSTERESIS_40MV,    /**< Hysteresis level 40mV */
    COMP_HYSTERESIS_50MV,    /**< Hysteresis level 50mV */
    COMP_HYSTERESIS_60MV,    /**< Hysteresis level 60mV */
    COMP_HYSTERESIS_70MV,    /**< Hysteresis level 70mV */
} comp_hysteresis_t;

/**
 * @enum comp_outpol_t
 * COMP output polarity supported configuration.
 */
typedef enum {
    COMP_OUTPOL_NOTINVERTED,      /**< COMP output level not inverted */
    COMP_OUTPOL_INVERTED,         /**< COMP output level inverted     */
} comp_outpol_t;

/**
 * @enum comp_triggermode_t
 * COMP trigger/mode supported configurations.
 */
typedef enum {
    COMP_TRIGGERMODE_NONE,        /**< COMP output triggering no external interrupt line */
    COMP_TRIGGERMODE_INT_RISING,  /**< COMP output triggering external interrupt line with interrupt on rising edge                  */
    COMP_TRIGGERMODE_INT_FALLING, /**< COMP output triggering external interrupt line with interrupt on falling edge                 */
    COMP_TRIGGERMODE_INT_BOTH,    /**< COMP output triggering external interrupt line with interrupt on both edges                   */
    COMP_TRIGGERMODE_EVT_RISING,  /**< COMP output triggering external interrupt line without interrupt (event only) on rising edge  */
    COMP_TRIGGERMODE_EVT_FALLING, /**< COMP output triggering external interrupt line without interrupt (event only) on falling edge */
    COMP_TRIGGERMODE_EVT_BOTH,    /**< COMP output triggering external interrupt line without interrupt (event only) on both edges   */
} comp_triggermode_t;

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

/* Export driver modules.*/
#include <comp_instances.h>


#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Initializes an COMP instance.
 *
 * @param[out] cdp      pointer to an @p comp_driver_t structure
 *
 * @init
 */
void comp_init(comp_driver_t *cdp);

/**
 * @brief   Configures COMP interrupt priority.
 * @note    This configuration becomes effective after comp_start.
 *
 * @param[in] cdp       pointer to an @p comp_driver_t structure
 * @param[in] prio      interrupt priority to be configured
 * @return              previous interrupt priority.
 *
 * @api
 */
uint32_t comp_set_prio(comp_driver_t *cdp, uint32_t prio);

/**
 * @brief   Configures COMP input plus (non-inverting input).
 * @note    This configuration becomes effective after comp_start.
 *
 * @param[in] cdp       pointer to an @p comp_driver_t structure
 * @param[in] input_plus input plus selection. It can be one of the following
 *                      values:
 *                      for COMP1:
 *            @arg @ref COMP_COMP1_INPUT_PLUS_PB2
 *            @arg @ref COMP_COMP1_INPUT_PLUS_PB3
 *                      for COMP2:
 *            @arg @ref COMP_COMP2_INPUT_PLUS_PB2
 *            @arg @ref COMP_COMP2_INPUT_PLUS_PB4
 *                      for COMP3:
 *            @arg @ref COMP_COMP3_INPUT_PLUS_PB7
 *            @arg @ref COMP_COMP3_INPUT_PLUS_PB8
 *                      for COMP4:
 *            @arg @ref COMP_COMP4_INPUT_PLUS_PB7
 *            @arg @ref COMP_COMP4_INPUT_PLUS_PB9
 *                      for COMP5:
 *            @arg @ref COMP_COMP5_INPUT_PLUS_PB12
 *            @arg @ref COMP_COMP5_INPUT_PLUS_PB13
 *                      for COMP6:
 *            @arg @ref COMP_COMP6_INPUT_PLUS_PB12
 *            @arg @ref COMP_COMP6_INPUT_PLUS_PB14
 *                      for COMP7:
 *            @arg @ref COMP_COMP7_INPUT_PLUS_PC3
 *            @arg @ref COMP_COMP7_INPUT_PLUS_PC4
 *                      for COMP8:
 *            @arg @ref COMP_COMP8_INPUT_PLUS_PC3
 *            @arg @ref COMP_COMP8_INPUT_PLUS_PC6
 * @return              input plus selection.
 *
 * @api
 */
uint8_t comp_set_input_plus(comp_driver_t *cdp, uint8_t input_plus);

/**
 * @brief   Configures COMP input minus (inverting input).
 * @note    This configuration becomes effective after comp_start.
 *
 * @param[in] cdp       pointer to an @p comp_driver_t structure
 * @param[in] input_minus input minus selection. It can be one of the following
 *                      values:
 *                      for COMP1:
 *            @arg @ref COMP_COMP1_INPUT_MINUS_DAC1_CH1
 *            @arg @ref COMP_COMP1_INPUT_MINUS_PB1
 *            @arg @ref COMP_COMP1_INPUT_MINUS_TEST_CH
 *            @arg @ref COMP_COMP1_INPUT_MINUS_TEST_VREF
 *                      for COMP2:
 *            @arg @ref COMP_COMP2_INPUT_MINUS_DAC1_CH2
 *            @arg @ref COMP_COMP2_INPUT_MINUS_PB5 
 *            @arg @ref COMP_COMP2_INPUT_MINUS_TEST_CH
 *            @arg @ref COMP_COMP2_INPUT_MINUS_TEST_VREF
 *                      for COMP3:
 *            @arg @ref COMP_COMP3_INPUT_MINUS_DAC2_CH1
 *            @arg @ref COMP_COMP3_INPUT_MINUS_PB13 
 *            @arg @ref COMP_COMP3_INPUT_MINUS_TEST_CH
 *            @arg @ref COMP_COMP3_INPUT_MINUS_TEST_VREF
 *                      for COMP4:
 *            @arg @ref COMP_COMP4_INPUT_MINUS_DAC2_CH2
 *            @arg @ref COMP_COMP4_INPUT_MINUS_PB10 
 *            @arg @ref COMP_COMP4_INPUT_MINUS_TEST_CH
 *            @arg @ref COMP_COMP4_INPUT_MINUS_TEST_VREF
 *                      for COMP5:
 *            @arg @ref COMP_COMP5_INPUT_MINUS_DAC3_CH1
 *            @arg @ref COMP_COMP5_INPUT_MINUS_PC4 
 *            @arg @ref COMP_COMP5_INPUT_MINUS_TEST_CH
 *            @arg @ref COMP_COMP5_INPUT_MINUS_TEST_VREF
 *                      for COMP6:
 *            @arg @ref COMP_COMP6_INPUT_MINUS_DAC3_CH2
 *            @arg @ref COMP_COMP6_INPUT_MINUS_PB15 
 *            @arg @ref COMP_COMP6_INPUT_MINUS_TEST_CH
 *            @arg @ref COMP_COMP6_INPUT_MINUS_TEST_VREF
 *                      for COMP7:
 *            @arg @ref COMP_COMP7_INPUT_MINUS_DAC4_CH1
 *            @arg @ref COMP_COMP7_INPUT_MINUS_PB8 
 *            @arg @ref COMP_COMP7_INPUT_MINUS_TEST_CH
 *            @arg @ref COMP_COMP7_INPUT_MINUS_TEST_VREF
 *                      for COMP8:
 *            @arg @ref COMP_COMP8_INPUT_MINUS_DAC4_CH2
 *            @arg @ref COMP_COMP8_INPUT_MINUS_PC7 
 *            @arg @ref COMP_COMP8_INPUT_MINUS_TEST_CH
 *            @arg @ref COMP_COMP8_INPUT_MINUS_TEST_VREF
 * @return              input minus selection.
 *
 * @api
 */
uint8_t comp_set_input_minus(comp_driver_t *cdp, uint8_t input_minus);

/**
 * @brief   Configures COMP blanking selection.
 * @note    This configuration becomes effective after comp_start.
 *
 * @param[in] cdp       pointer to an @p comp_driver_t structure
 * @param[in] blank_sel comparator blank selection. It can be one of the
 *                      following values:
 *                      for COMP1:
 *            @arg @ref COMP_COMP1_BLANKSRC_NONE
 *            @arg @ref COMP_COMP1_BLANKSRC_TIM1_OC5
 *            @arg @ref COMP_COMP1_BLANKSRC_TIM2_OC3
 *            @arg @ref COMP_COMP1_BLANKSRC_TIM3_OC3
 *            @arg @ref COMP_COMP1_BLANKSRC_TIM8_OC5
 *            @arg @ref COMP_COMP1_BLANKSRC_TIM3_OC4
 *            @arg @ref COMP_COMP1_BLANKSRC_TIM15_OC1
 *            @arg @ref COMP_COMP1_BLANKSRC_TIM4_OC3
 *                      for COMP2:
 *            @arg @ref COMP_COMP2_BLANKSRC_NONE
 *            @arg @ref COMP_COMP2_BLANKSRC_TIM1_OC5
 *            @arg @ref COMP_COMP2_BLANKSRC_TIM2_OC4
 *            @arg @ref COMP_COMP2_BLANKSRC_TIM3_OC3
 *            @arg @ref COMP_COMP2_BLANKSRC_TIM8_OC5
 *            @arg @ref COMP_COMP2_BLANKSRC_TIM3_OC4
 *            @arg @ref COMP_COMP2_BLANKSRC_TIM15_OC1
 *            @arg @ref COMP_COMP2_BLANKSRC_TIM4_OC3
 *                      for COMP3:
 *            @arg @ref COMP_COMP3_BLANKSRC_NONE
 *            @arg @ref COMP_COMP3_BLANKSRC_TIM1_OC5
 *            @arg @ref COMP_COMP3_BLANKSRC_TIM3_OC3
 *            @arg @ref COMP_COMP3_BLANKSRC_TIM2_OC4
 *            @arg @ref COMP_COMP3_BLANKSRC_TIM8_OC5
 *            @arg @ref COMP_COMP3_BLANKSRC_TIM3_OC4
 *            @arg @ref COMP_COMP3_BLANKSRC_TIM15_OC1
 *            @arg @ref COMP_COMP3_BLANKSRC_TIM4_OC3
 *                      for COMP4:
 *            @arg @ref COMP_COMP4_BLANKSRC_NONE
 *            @arg @ref COMP_COMP4_BLANKSRC_TIM1_OC5
 *            @arg @ref COMP_COMP4_BLANKSRC_TIM3_OC3
 *            @arg @ref COMP_COMP4_BLANKSRC_TIM2_OC4
 *            @arg @ref COMP_COMP4_BLANKSRC_TIM8_OC5
 *            @arg @ref COMP_COMP4_BLANKSRC_TIM3_OC4
 *            @arg @ref COMP_COMP4_BLANKSRC_TIM15_OC1
 *            @arg @ref COMP_COMP4_BLANKSRC_TIM4_OC3
 *                      for COMP5:
 *            @arg @ref COMP_COMP5_BLANKSRC_NONE
 *            @arg @ref COMP_COMP5_BLANKSRC_TIM2_OC3
 *            @arg @ref COMP_COMP5_BLANKSRC_TIM8_OC5
 *            @arg @ref COMP_COMP5_BLANKSRC_TIM3_OC3
 *            @arg @ref COMP_COMP5_BLANKSRC_TIM1_OC5
 *            @arg @ref COMP_COMP5_BLANKSRC_TIM3_OC4
 *            @arg @ref COMP_COMP5_BLANKSRC_TIM15_OC1
 *            @arg @ref COMP_COMP5_BLANKSRC_TIM4_OC3
 *                      for COMP6:
 *            @arg @ref COMP_COMP6_BLANKSRC_NONE
 *            @arg @ref COMP_COMP6_BLANKSRC_TIM2_OC3
 *            @arg @ref COMP_COMP6_BLANKSRC_TIM8_OC5
 *            @arg @ref COMP_COMP6_BLANKSRC_TIM3_OC3
 *            @arg @ref COMP_COMP6_BLANKSRC_TIM1_OC5
 *            @arg @ref COMP_COMP6_BLANKSRC_TIM3_OC4
 *            @arg @ref COMP_COMP6_BLANKSRC_TIM15_OC1
 *            @arg @ref COMP_COMP6_BLANKSRC_TIM4_OC3
 *                      for COMP7:
 *            @arg @ref COMP_COMP7_BLANKSRC_NONE
 *            @arg @ref COMP_COMP7_BLANKSRC_TIM1_OC5
 *            @arg @ref COMP_COMP7_BLANKSRC_TIM8_OC5
 *            @arg @ref COMP_COMP7_BLANKSRC_TIM3_OC3
 *            @arg @ref COMP_COMP7_BLANKSRC_TIM15_OC2
 *            @arg @ref COMP_COMP7_BLANKSRC_TIM3_OC4
 *            @arg @ref COMP_COMP7_BLANKSRC_TIM15_OC1
 *            @arg @ref COMP_COMP7_BLANKSRC_TIM4_OC3
 *                      for COMP8:
 *            @arg @ref COMP_COMP8_BLANKSRC_NONE
 *            @arg @ref COMP_COMP8_BLANKSRC_TIM1_OC5
 *            @arg @ref COMP_COMP8_BLANKSRC_TIM8_OC5
 *            @arg @ref COMP_COMP8_BLANKSRC_TIM3_OC3
 *            @arg @ref COMP_COMP8_BLANKSRC_TIM15_OC2
 *            @arg @ref COMP_COMP8_BLANKSRC_TIM3_OC4
 *            @arg @ref COMP_COMP8_BLANKSRC_TIM15_OC1
 *            @arg @ref COMP_COMP8_BLANKSRC_TIM4_OC3
 * @return              comparator blank selection.
 *
 * @api
 */
uint8_t comp_set_blank_sel(comp_driver_t *cdp, uint8_t blank_sel);

/**
 * @brief   Configures COMP hysteresis mode of the input minus.
 * @note    This configuration becomes effective after comp_start.
 *
 * @param[in] cdp        pointer to an @p comp_driver_t structure
 * @param[in] hysteresis hysteresis mode to be configured
 * @return               previous hysteresis mode.
 *
 * @api
 */
comp_hysteresis_t comp_set_hysteresis(comp_driver_t *cdp,
                                      comp_hysteresis_t hysteresis);

/**
 * @brief   Configures COMP output polarity.
 * @note    This configuration becomes effective after comp_start.
 *
 * @param[in] cdp       pointer to an @p comp_driver_t structure
 * @param[in] out_pol   output polarity to be configured
 * @return              previous output polarity.
 *
 * @api
 */
comp_outpol_t comp_set_output_polarity(comp_driver_t *cdp,
                                       comp_outpol_t out_pol);

/**
 * @brief   Enables/Disables COMP deglitch.
 * @note    This configuration becomes effective after comp_start.
 *
 * @param[in] cdp       pointer to an @p comp_driver_t structure
 * @param[in] enable    comparator deglitch enable status to be configured
 * @return              previous deglitch enable status.
 *
 * @api
 */
bool comp_set_deglitch(comp_driver_t *cdp, bool enable);

/**
 * @brief   Enables/Disables COMP register lock.
 * @note    This configuration becomes effective after comp_start.
 *
 * @param[in] cdp       pointer to an @p comp_driver_t structure
 * @param[in] enable    comparator register lock enable status to be configured
 * @return              previous register lock enable status.
 *
 * @api
 */
bool comp_set_lock(comp_driver_t *cdp, bool enable);

/**
 * @brief   Configures COMP triggermode.
 * @note    This configuration becomes effective after comp_start.
 *
 * @param[in] cdp         pointer to an @p comp_driver_t structure
 * @param[in] triggermode comparator triggermode to be configured. It can be
 *                        one of the following values:
 *              @arg @ref COMP_TRIGGERMODE_NONE
 *              @arg @ref COMP_TRIGGERMODE_INT_RISING
 *              @arg @ref COMP_TRIGGERMODE_INT_FALLING
 *              @arg @ref COMP_TRIGGERMODE_INT_BOTH
 *              @arg @ref COMP_TRIGGERMODE_EVT_RISING
 *              @arg @ref COMP_TRIGGERMODE_EVT_FALLING
 *              @arg @ref COMP_TRIGGERMODE_EVT_BOTH
 * @return                previous comparator triggermode.
 *
 * @api
 */
comp_triggermode_t comp_set_triggermode(comp_driver_t *cdp,
                                        comp_triggermode_t triggermode);

/**
 * @brief   Configure COMP callback function.
 * @note    This configuration becomes effective after comp_start.
 *
 * @param[in] cdp       pointer to an @p comp_driver_t structure
 * @param[in] cb        pointer to comparator callback function
 * @return              pointer to previous callback function.
 *
 * @api
 */
comp_cb_t comp_set_cb(comp_driver_t *cdp, comp_cb_t cb);

/**
 * @brief   Starts a COMP instance.
 *
 * @param[in] cdp       pointer to an @p comp_driver_t structure
 *
 * @api
 */
void comp_start(comp_driver_t *cdp);

/**
 * @brief   Enables a COMP instance.
 *
 * @param[in] cdp       pointer to an @p comp_driver_t structure
 *
 * @api
 */
void comp_enable(comp_driver_t *cdp);

/**
 * @brief   Returns the level of the comparator output before the polarity
 *          selector and blanking.
 *
 * @param[in] cdp       pointer to an @p comp_driver_t structure
 *
 * @api
 */
uint8_t comp_get_output(comp_driver_t *cdp);

/**
 * @brief   Disables a COMP instance.
 *
 * @param[in] cdp       pointer to an @p comp_driver_t structure
 *
 * @api
 */
void comp_disable(comp_driver_t *cdp);

/**
 * @brief   Stops a COMP instance.
 *
 * @param[in] cdp       pointer to an @p comp_driver_t structure
 *
 * @api
 */
void comp_stop(comp_driver_t *cdp);

/**
 * @brief   De-initializes a COMP instance.
 *
 * @param[out] cdp      pointer to an @p comp_driver_t structure
 *
 * @api
 */
void comp_deinit(comp_driver_t *cdp);

/**
 * @brief   Serves a COMP interrupt.
 * @note    Not an API, used internally.
 *
 * @param[in] cdp       pointer to an @p comp_driver_t structure
 *
 * @isr
 */
void __comp_serve_interrupt(comp_driver_t *cdp);

#ifdef __cplusplus
}
#endif

#endif /* _COMP_H_ */

/** @} */
