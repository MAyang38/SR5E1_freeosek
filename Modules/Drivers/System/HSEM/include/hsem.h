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
 * @file    hsem.h
 * @brief   SR5E1 HSEM header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup SYSTEM
 * @ingroup DRIVERS
 * @addtogroup HSEM
 * @ingroup SYSTEM
 * @{
 */

#ifndef _HSEM_H_
#define _HSEM_H_

#include <typedefs.h>

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

#define HSEM_SEM_NUM         32U

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
 * @brief   Type of an HSEM driver.
 */
typedef struct hsem_driver hsem_driver_t;

/**
 * @enum hsem_sem_id_t
 * HSEM semaphore ID type.
 */
typedef enum {
    HSEM_SEM_ID_0  = 0U,   /**< Semaphore ID 0  */
    HSEM_SEM_ID_1  = 1U,   /**< Semaphore ID 1  */
    HSEM_SEM_ID_2  = 2U,   /**< Semaphore ID 2  */
    HSEM_SEM_ID_3  = 3U,   /**< Semaphore ID 3  */
    HSEM_SEM_ID_4  = 4U,   /**< Semaphore ID 4  */
    HSEM_SEM_ID_5  = 5U,   /**< Semaphore ID 5  */
    HSEM_SEM_ID_6  = 6U,   /**< Semaphore ID 6  */
    HSEM_SEM_ID_7  = 7U,   /**< Semaphore ID 7  */
    HSEM_SEM_ID_8  = 8U,   /**< Semaphore ID 8  */
    HSEM_SEM_ID_9  = 9U,   /**< Semaphore ID 9  */
    HSEM_SEM_ID_10 = 10U,  /**< Semaphore ID 10 */
    HSEM_SEM_ID_11 = 11U,  /**< Semaphore ID 11 */
    HSEM_SEM_ID_12 = 12U,  /**< Semaphore ID 12 */
    HSEM_SEM_ID_13 = 13U,  /**< Semaphore ID 13 */
    HSEM_SEM_ID_14 = 14U,  /**< Semaphore ID 14 */
    HSEM_SEM_ID_15 = 15U,  /**< Semaphore ID 15 */
    HSEM_SEM_ID_16 = 16U,  /**< Semaphore ID 16 */
    HSEM_SEM_ID_17 = 17U,  /**< Semaphore ID 17 */
    HSEM_SEM_ID_18 = 18U,  /**< Semaphore ID 18 */
    HSEM_SEM_ID_19 = 19U,  /**< Semaphore ID 19 */
    HSEM_SEM_ID_20 = 20U,  /**< Semaphore ID 20 */
    HSEM_SEM_ID_21 = 21U,  /**< Semaphore ID 21 */
    HSEM_SEM_ID_22 = 22U,  /**< Semaphore ID 22 */
    HSEM_SEM_ID_23 = 23U,  /**< Semaphore ID 23 */
    HSEM_SEM_ID_24 = 24U,  /**< Semaphore ID 24 */
    HSEM_SEM_ID_25 = 25U,  /**< Semaphore ID 25 */
    HSEM_SEM_ID_26 = 26U,  /**< Semaphore ID 26 */
    HSEM_SEM_ID_27 = 27U,  /**< Semaphore ID 27 */
    HSEM_SEM_ID_28 = 28U,  /**< Semaphore ID 28 */
    HSEM_SEM_ID_29 = 29U,  /**< Semaphore ID 29 */
    HSEM_SEM_ID_30 = 30U,  /**< Semaphore ID 30 */
    HSEM_SEM_ID_31 = 31U   /**< Semaphore ID 31 */
} hsem_sem_id_t;

/**
 * @enum hsem_core_id_t
 * HSEM core ID type.
 */
typedef enum {
    HSEM_CORE_ID_CORE1 = 0x8U, /**< Bus master ID value for core 1   */
    HSEM_CORE_ID_CORE2 = 0x1U, /**< Bus master ID value for core 2   */
} hsem_core_id_t;

/**
 * @brief   Type of HSEM callbacks.
 *
 * @param[in] hdp       pointer to the @p hsem_driver_t object
 */
typedef void (*hsem_cb_t)(hsem_driver_t *hdp);

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

extern hsem_driver_t DRV_HSEM;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Configures HSEM core id.
 * @note    This configuration becomes effective after hsem_start.
 * @note    This function must be invoked before hsem_start to configure the
 *          core id on which this driver is executed.
 *
 * @param[out] hdp      pointer to a @p hsem_driver_t structure
 * @param[in] core_id   Core id. It can be one of the following values:
 *            @arg @ref HSEM_CORE_ID_CORE1
 *            @arg @ref HSEM_CORE_ID_CORE2
 *
 * @api
 */
void hsem_set_core(hsem_driver_t *hdp, hsem_core_id_t core_id);

/**
 * @brief   Configures HSEM interrupt priority.
 * @note    This configuration becomes effective after hsem_start.
 *
 * @param[out] hdp      pointer to a @p hsem_driver_t structure
 * @param[in] prio      interrupt priority to be configured
 * @return              previous interrupt priority.
 *
 * @api
 */
uint32_t hsem_set_prio(hsem_driver_t *hdp, uint32_t prio);

/**
 * @brief   Enable semphore interrupt.
 * @note    This configuration becomes effective after hsem_start.
 *
 * @param[out] hdp      pointer to a @p hsem_driver_t structure
 * @param[in] sem_id    Semaphore id. It can be one of the following values:
 *            @arg @ref HSEM_SEM_ID_0
 *            @arg @ref HSEM_SEM_ID_1
 *            @arg @ref HSEM_SEM_ID_2
 *            @arg @ref HSEM_SEM_ID_3
 *            @arg @ref HSEM_SEM_ID_4
 *            @arg @ref HSEM_SEM_ID_5
 *            @arg @ref HSEM_SEM_ID_6
 *            @arg @ref HSEM_SEM_ID_7
 *            @arg @ref HSEM_SEM_ID_8
 *            @arg @ref HSEM_SEM_ID_9
 *            @arg @ref HSEM_SEM_ID_10
 *            @arg @ref HSEM_SEM_ID_11
 *            @arg @ref HSEM_SEM_ID_12
 *            @arg @ref HSEM_SEM_ID_13
 *            @arg @ref HSEM_SEM_ID_14
 *            @arg @ref HSEM_SEM_ID_15
 *            @arg @ref HSEM_SEM_ID_16
 *            @arg @ref HSEM_SEM_ID_17
 *            @arg @ref HSEM_SEM_ID_18
 *            @arg @ref HSEM_SEM_ID_19
 *            @arg @ref HSEM_SEM_ID_20
 *            @arg @ref HSEM_SEM_ID_21
 *            @arg @ref HSEM_SEM_ID_22
 *            @arg @ref HSEM_SEM_ID_23
 *            @arg @ref HSEM_SEM_ID_24
 *            @arg @ref HSEM_SEM_ID_25
 *            @arg @ref HSEM_SEM_ID_26
 *            @arg @ref HSEM_SEM_ID_27
 *            @arg @ref HSEM_SEM_ID_28
 *            @arg @ref HSEM_SEM_ID_29
 *            @arg @ref HSEM_SEM_ID_30
 *            @arg @ref HSEM_SEM_ID_31
 *
 * @api
 */
void hsem_en_irq(hsem_driver_t *hdp, hsem_sem_id_t sem_id);

/**
 * @brief   Configures pointers to semaphore callback functions.
 * @note    This configuration becomes effective after hsem_start.
 *
 * @param[out] hdp      pointer to a @p hsem_driver_t structure
 * @param[in] sem_id    Semaphore id. It can be one of the following values:
 *            @arg @ref HSEM_SEM_ID_0
 *            @arg @ref HSEM_SEM_ID_1
 *            @arg @ref HSEM_SEM_ID_2
 *            @arg @ref HSEM_SEM_ID_3
 *            @arg @ref HSEM_SEM_ID_4
 *            @arg @ref HSEM_SEM_ID_5
 *            @arg @ref HSEM_SEM_ID_6
 *            @arg @ref HSEM_SEM_ID_7
 *            @arg @ref HSEM_SEM_ID_8
 *            @arg @ref HSEM_SEM_ID_9
 *            @arg @ref HSEM_SEM_ID_10
 *            @arg @ref HSEM_SEM_ID_11
 *            @arg @ref HSEM_SEM_ID_12
 *            @arg @ref HSEM_SEM_ID_13
 *            @arg @ref HSEM_SEM_ID_14
 *            @arg @ref HSEM_SEM_ID_15
 *            @arg @ref HSEM_SEM_ID_16
 *            @arg @ref HSEM_SEM_ID_17
 *            @arg @ref HSEM_SEM_ID_18
 *            @arg @ref HSEM_SEM_ID_19
 *            @arg @ref HSEM_SEM_ID_20
 *            @arg @ref HSEM_SEM_ID_21
 *            @arg @ref HSEM_SEM_ID_22
 *            @arg @ref HSEM_SEM_ID_23
 *            @arg @ref HSEM_SEM_ID_24
 *            @arg @ref HSEM_SEM_ID_25
 *            @arg @ref HSEM_SEM_ID_26
 *            @arg @ref HSEM_SEM_ID_27
 *            @arg @ref HSEM_SEM_ID_28
 *            @arg @ref HSEM_SEM_ID_29
 *            @arg @ref HSEM_SEM_ID_30
 *            @arg @ref HSEM_SEM_ID_31
 * @param[in] cb        pointer to semaphore callback function
 * @return              pointer to previuos semaphore callback function.
 *
 * @api
 */
hsem_cb_t hsem_set_cb(hsem_driver_t *hdp, hsem_sem_id_t sem_id, hsem_cb_t cb);

/**
 * @brief   Initializes HSEM instance.
 *
 * @param[out] hdp      pointer to a @p hsem_driver_t structure
 *
 * @api
 */
void hsem_init(hsem_driver_t *hdp);

/**
 * @brief   Starts HSEM instance.
 *
 * @param[out] hdp      pointer to a @p hsem_driver_t structure
 *
 * @api
 */
void hsem_start(hsem_driver_t *hdp);

/**
 * @brief   Takes semaphore with 2-step mode.
 *
 * @param[in] hdp       pointer to a @p hsem_driver_t structure
 * @param[in] sem_id    Semaphore id. It can be one of the following values:
 *            @arg @ref HSEM_SEM_ID_0
 *            @arg @ref HSEM_SEM_ID_1
 *            @arg @ref HSEM_SEM_ID_2
 *            @arg @ref HSEM_SEM_ID_3
 *            @arg @ref HSEM_SEM_ID_4
 *            @arg @ref HSEM_SEM_ID_5
 *            @arg @ref HSEM_SEM_ID_6
 *            @arg @ref HSEM_SEM_ID_7
 *            @arg @ref HSEM_SEM_ID_8
 *            @arg @ref HSEM_SEM_ID_9
 *            @arg @ref HSEM_SEM_ID_10
 *            @arg @ref HSEM_SEM_ID_11
 *            @arg @ref HSEM_SEM_ID_12
 *            @arg @ref HSEM_SEM_ID_13
 *            @arg @ref HSEM_SEM_ID_14
 *            @arg @ref HSEM_SEM_ID_15
 *            @arg @ref HSEM_SEM_ID_16
 *            @arg @ref HSEM_SEM_ID_17
 *            @arg @ref HSEM_SEM_ID_18
 *            @arg @ref HSEM_SEM_ID_19
 *            @arg @ref HSEM_SEM_ID_20
 *            @arg @ref HSEM_SEM_ID_21
 *            @arg @ref HSEM_SEM_ID_22
 *            @arg @ref HSEM_SEM_ID_23
 *            @arg @ref HSEM_SEM_ID_24
 *            @arg @ref HSEM_SEM_ID_25
 *            @arg @ref HSEM_SEM_ID_26
 *            @arg @ref HSEM_SEM_ID_27
 *            @arg @ref HSEM_SEM_ID_28
 *            @arg @ref HSEM_SEM_ID_29
 *            @arg @ref HSEM_SEM_ID_30
 *            @arg @ref HSEM_SEM_ID_31
 * @param[in] proc_id   Process id [0:255]
 * @return              true if semaphore is corretly taken, false otherwise.
 *
 * @api
 */
bool hsem_take_sem_2s(hsem_driver_t *hdp, hsem_sem_id_t sem_id,
                      uint8_t proc_id);

/**
 * @brief   Takes semaphore with 1-step mode.
 *
 * @param[in] hdp       pointer to a @p hsem_driver_t structure
 * @param[in] sem_id    Semaphore id. It can be one of the following values:
 *            @arg @ref HSEM_SEM_ID_0
 *            @arg @ref HSEM_SEM_ID_1
 *            @arg @ref HSEM_SEM_ID_2
 *            @arg @ref HSEM_SEM_ID_3
 *            @arg @ref HSEM_SEM_ID_4
 *            @arg @ref HSEM_SEM_ID_5
 *            @arg @ref HSEM_SEM_ID_6
 *            @arg @ref HSEM_SEM_ID_7
 *            @arg @ref HSEM_SEM_ID_8
 *            @arg @ref HSEM_SEM_ID_9
 *            @arg @ref HSEM_SEM_ID_10
 *            @arg @ref HSEM_SEM_ID_11
 *            @arg @ref HSEM_SEM_ID_12
 *            @arg @ref HSEM_SEM_ID_13
 *            @arg @ref HSEM_SEM_ID_14
 *            @arg @ref HSEM_SEM_ID_15
 *            @arg @ref HSEM_SEM_ID_16
 *            @arg @ref HSEM_SEM_ID_17
 *            @arg @ref HSEM_SEM_ID_18
 *            @arg @ref HSEM_SEM_ID_19
 *            @arg @ref HSEM_SEM_ID_20
 *            @arg @ref HSEM_SEM_ID_21
 *            @arg @ref HSEM_SEM_ID_22
 *            @arg @ref HSEM_SEM_ID_23
 *            @arg @ref HSEM_SEM_ID_24
 *            @arg @ref HSEM_SEM_ID_25
 *            @arg @ref HSEM_SEM_ID_26
 *            @arg @ref HSEM_SEM_ID_27
 *            @arg @ref HSEM_SEM_ID_28
 *            @arg @ref HSEM_SEM_ID_29
 *            @arg @ref HSEM_SEM_ID_30
 *            @arg @ref HSEM_SEM_ID_31
 * @return              true if semaphore is corretly taken, false otherwise.
 *
 * @api
 */
bool hsem_take_sem_1s(hsem_driver_t *hdp, hsem_sem_id_t sem_id);

/**
 * @brief   Checks if the semaphore is locked.
 *
 * @param[in] hdp       pointer to a @p hsem_driver_t structure
 * @param[in] sem_id    Semaphore id. It can be one of the following values:
 *            @arg @ref HSEM_SEM_ID_0
 *            @arg @ref HSEM_SEM_ID_1
 *            @arg @ref HSEM_SEM_ID_2
 *            @arg @ref HSEM_SEM_ID_3
 *            @arg @ref HSEM_SEM_ID_4
 *            @arg @ref HSEM_SEM_ID_5
 *            @arg @ref HSEM_SEM_ID_6
 *            @arg @ref HSEM_SEM_ID_7
 *            @arg @ref HSEM_SEM_ID_8
 *            @arg @ref HSEM_SEM_ID_9
 *            @arg @ref HSEM_SEM_ID_10
 *            @arg @ref HSEM_SEM_ID_11
 *            @arg @ref HSEM_SEM_ID_12
 *            @arg @ref HSEM_SEM_ID_13
 *            @arg @ref HSEM_SEM_ID_14
 *            @arg @ref HSEM_SEM_ID_15
 *            @arg @ref HSEM_SEM_ID_16
 *            @arg @ref HSEM_SEM_ID_17
 *            @arg @ref HSEM_SEM_ID_18
 *            @arg @ref HSEM_SEM_ID_19
 *            @arg @ref HSEM_SEM_ID_20
 *            @arg @ref HSEM_SEM_ID_21
 *            @arg @ref HSEM_SEM_ID_22
 *            @arg @ref HSEM_SEM_ID_23
 *            @arg @ref HSEM_SEM_ID_24
 *            @arg @ref HSEM_SEM_ID_25
 *            @arg @ref HSEM_SEM_ID_26
 *            @arg @ref HSEM_SEM_ID_27
 *            @arg @ref HSEM_SEM_ID_28
 *            @arg @ref HSEM_SEM_ID_29
 *            @arg @ref HSEM_SEM_ID_30
 *            @arg @ref HSEM_SEM_ID_31
 * @return              true if semaphore is locked, false otherwise.
 *
 * @api
 */
bool hsem_is_sem_taken(hsem_driver_t *hdp, hsem_sem_id_t sem_id);

/**
 * @brief   Releases semaphore.
 *
 * @param[in] hdp       pointer to a @p hsem_driver_t structure
 * @param[in] sem_id    Semaphore id. It can be one of the following values:
 *            @arg @ref HSEM_SEM_ID_0
 *            @arg @ref HSEM_SEM_ID_1
 *            @arg @ref HSEM_SEM_ID_2
 *            @arg @ref HSEM_SEM_ID_3
 *            @arg @ref HSEM_SEM_ID_4
 *            @arg @ref HSEM_SEM_ID_5
 *            @arg @ref HSEM_SEM_ID_6
 *            @arg @ref HSEM_SEM_ID_7
 *            @arg @ref HSEM_SEM_ID_8
 *            @arg @ref HSEM_SEM_ID_9
 *            @arg @ref HSEM_SEM_ID_10
 *            @arg @ref HSEM_SEM_ID_11
 *            @arg @ref HSEM_SEM_ID_12
 *            @arg @ref HSEM_SEM_ID_13
 *            @arg @ref HSEM_SEM_ID_14
 *            @arg @ref HSEM_SEM_ID_15
 *            @arg @ref HSEM_SEM_ID_16
 *            @arg @ref HSEM_SEM_ID_17
 *            @arg @ref HSEM_SEM_ID_18
 *            @arg @ref HSEM_SEM_ID_19
 *            @arg @ref HSEM_SEM_ID_20
 *            @arg @ref HSEM_SEM_ID_21
 *            @arg @ref HSEM_SEM_ID_22
 *            @arg @ref HSEM_SEM_ID_23
 *            @arg @ref HSEM_SEM_ID_24
 *            @arg @ref HSEM_SEM_ID_25
 *            @arg @ref HSEM_SEM_ID_26
 *            @arg @ref HSEM_SEM_ID_27
 *            @arg @ref HSEM_SEM_ID_28
 *            @arg @ref HSEM_SEM_ID_29
 *            @arg @ref HSEM_SEM_ID_30
 *            @arg @ref HSEM_SEM_ID_31
 * @param[in] proc_id   Process id [0:255]
 *
 * @api
 */
void hsem_release_sem(hsem_driver_t *hdp, hsem_sem_id_t sem_id,
                      uint8_t proc_id);

/**
 * @brief   Sets clear key for the release of all semaphores.
 *
 * @param[in] hdp       pointer to a @p hsem_driver_t structure
 * @param[in] key       clear key [0x0:0xFFFF]
 *
 * @api
 */
void hsem_set_clear_key(hsem_driver_t *hdp, uint16_t key);

/**
 * @brief   Returns clear key for the release of all semaphores.
 *
 * @param[in] hdp       pointer to a @p hsem_driver_t structure
 * @return              clear key [0x0:0xFFFF].
 *
 * @api
 */
uint16_t hsem_get_clear_key(hsem_driver_t *hdp);

/**
 * @brief   Releases all semaphores.
 *
 * @param[in] hdp       pointer to a @p hsem_driver_t structure
 * @param[in] core_id   Core id. It can be one of the following values:
 *            @arg @ref HSEM_CORE_ID_CORE1
 *            @arg @ref HSEM_CORE_ID_CORE2
 * @param[in] key       clear key [0x0:0xFFFF]
 *
 * @api
 */
void hsem_release_all(hsem_driver_t *hdp, hsem_core_id_t core_id,
                      uint16_t key);

/**
 * @brief   Stops HSEM instance.
 *
 * @param[out] hdp      pointer to a @p hsem_driver_t structure
 *
 * @api
 */
void hsem_stop(hsem_driver_t *hdp);

/**
 * @brief   Deinitializes HSEM instance.
 *
 * @param[out] hdp      pointer to a @p hsem_driver_t structure
 *
 * @api
 */
void hsem_deinit(hsem_driver_t *hdp);

/**
 * @brief   Shared interrupt handler.
 * @note    Not an API, used internally.
 *
 * @param[in] hdp       pointer to a @p hsem_driver_t structure
 *
 * @isr
 */
void __hsem_serve_interrupt(hsem_driver_t *hdp);

#ifdef __cplusplus
}
#endif

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/*===========================================================================*/
/* Module late inclusions.                                                   */
/*===========================================================================*/

#endif /* _HSEM_H_ */

/** @} */
