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
 * @file    iwdg_dev.c
 * @brief   IWDG device specific source file.
 *
 * @addtogroup DRIVERS
 * @addtogroup SYSTEM
 * @ingroup DRIVERS
 * @addtogroup IWDG
 * @ingroup SYSTEM
 * @{
 */

#include <iwdg.h>
#include <iwdg_private.h>
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

/*===========================================================================*/
/* Module local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Module exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Returns pointer to the IWDG register block.
 *
 * @param[in] idp       pointer to a @p iwdg_driver_t structure
 * @return              pointer to the IWDG register block.
 *
 * @notapi
 */
IWDG_TypeDef *iwdg_dev_get_reg_ptr(iwdg_driver_t *idp) {

    if (idp == &DRV_IWDG1) {
        return IWDG1;
    } else {
        return IWDG2;
    }
}

/**
 * @brief   Returns IWDG harwdare enable status
 *
 * @param[in] idp       pointer to a @p iwdg_driver_t structure
 * @return              IWDG harwdare enable status ("1" means the IWDG is
 *                      enabled via HW, "0" otherwise).
 *
 * @notapi
 */
uint8_t iwdg_dev_is_hw_en(iwdg_driver_t *idp) {

    uint8_t is_hw_en;

    if (idp == &DRV_IWDG1) {
        is_hw_en = (uint8_t)REG_READ_FIELD(SSCM->UOPS, SSCM_UOPS_IWDG1_HW_EN);
    } else {
        is_hw_en = (uint8_t)REG_READ_FIELD(SSCM->UOPS, SSCM_UOPS_IWDG2_HW_EN);
    }

    return is_hw_en;
}

/** @} */
