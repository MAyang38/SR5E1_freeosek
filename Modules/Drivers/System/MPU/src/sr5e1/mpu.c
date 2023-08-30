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
 * @file    mpu.c
 * @brief   SR5E1 MPU source file.
 *
 * @addtogroup DRIVERS
 * @addtogroup SYSTEM
 * @ingroup DRIVERS
 * @addtogroup MPU
 * @ingroup SYSTEM
 * @{
 */

#include <mpu.h>

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
/* Local function prototypes                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Module local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Module exported functions.                                                */
/*===========================================================================*/

void mpu_enable(const mpu_control_t ctrl) {

    ARM_MPU_Enable((uint32_t)(ctrl));
}

void mpu_set_region(const mpu_region_config_t *mrcp) {

    uint32_t subregion_disable;
    uint32_t type_extension;
    uint32_t rasr = 0UL;

    if (mrcp->enable == MPU_REG_ENABLE) {
        /* Regions of 32, 64, and 128 bytes do not support subregions. For
           these regions, SRD field must be set to 0x00, otherwise the MPU
           behavior is unpredictable.*/
        if (mrcp->size <= MPU_REG_SIZE_128B) {
            subregion_disable = 0x00U;
        } else {
            subregion_disable = mrcp->subregion_disable;
        }

        /* For Type Extension equal to 4, last 2 bits of TEX field must fit the
           value of bits cachable and bufferable.*/
        if (mrcp->type_ext == MPU_REG_TEX_LEVEL4) {
            type_extension = (uint32_t)(mrcp->type_ext)         |
                             (uint32_t)(mrcp->cacheable)  << 1U |
                             (uint32_t)(mrcp->bufferable) << 0U;
        } else {
            type_extension = (uint32_t)(mrcp->type_ext);
        }

        rasr = (((uint32_t)mrcp->enable              << MPU_RASR_ENABLE_Pos) |
                ((uint32_t)mrcp->size                << MPU_RASR_SIZE_Pos)   |
                ((uint32_t)subregion_disable         << MPU_RASR_SRD_Pos)    |
                ((uint32_t)type_extension            << MPU_RASR_TEX_Pos)    |
                ((uint32_t)mrcp->access_permission   << MPU_RASR_AP_Pos)     |
                ((uint32_t)mrcp->instruction_disable << MPU_RASR_XN_Pos)     |
                ((uint32_t)mrcp->shareable           << MPU_RASR_S_Pos)      |
                ((uint32_t)mrcp->cacheable           << MPU_RASR_C_Pos)      |
                ((uint32_t)mrcp->bufferable          << MPU_RASR_B_Pos));

        ARM_MPU_SetRegionEx((uint32_t)(mrcp->number), (uint32_t)(mrcp->base_address), rasr);
    }
}

void mpu_disable(void) {

    ARM_MPU_Disable();
}

/** @} */
