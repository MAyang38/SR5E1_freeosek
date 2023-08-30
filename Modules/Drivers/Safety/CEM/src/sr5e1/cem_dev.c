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
 * @file    cem_dev.c
 * @brief   CEM device specific source file.
 *
 * @addtogroup DRIVERS
 * @addtogroup SAFETY
 * @ingroup DRIVERS
 * @addtogroup CEM
 * @ingroup SAFETY
 * @{
 */

#include <cem.h>
#include <cem_private.h>
#include <platform.h>

/*===========================================================================*/
/* Module local definitions.                                                 */
/*===========================================================================*/

/**
 * @name    CEM number of instances
 * @{
 */
#define CEM_NUMBER                          15U
/** @} */

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
 * @brief   CEM descriptor.
 * @note    It specifies for each group of each CEM insance the number of CEM
 *          reg bits and the related FCCU fault. If the number of CEM reg bits
 *          is zero, the group is not used.
 */
static const cem_group_descriptor_t cem_descriptors[CEM_NUMBER][CEM_GPOUP_NUMBER] = {
                                    {{ 9U,  67U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, 
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, 
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U}},
                                    {{ 8U,  68U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U}},
                                    {{ 9U,  69U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U}},
                                    {{ 7U,  71U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U}},
                                    {{ 7U,  72U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U}},
                                    {{ 7U,  73U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U}},
                                    {{ 4U,  74U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U}},
                                    {{11U,  77U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U}},
                                    {{12U,  80U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U}},
                                    {{ 4U,  37U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U}},
                                    {{ 7U,  33U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U}},
                                    {{22U,  34U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U}},
                                    {{ 9U,  35U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U}},
                                    {{ 3U,  41U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U}},
                                    {{ 7U,  81U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U},
                                     { 0U,   0U}, { 0U,   0U}, { 0U,   0U}, { 0U,   0U}}};

/*===========================================================================*/
/* Module local functions.                                                   */
/*===========================================================================*/

static uint8_t cem_dev_get_index(cem_driver_t *cdp) {

    uint8_t index;

    if (cdp == &DRV_CEM0) {
        index = 0U;
    } else if (cdp == &DRV_CEM1) {
        index = 1U;
    } else if (cdp == &DRV_CEM2) {
        index = 2U;
    } else if (cdp == &DRV_CEM3) {
        index = 3U;
    } else if (cdp == &DRV_CEM4) {
        index = 4U;
    } else if (cdp == &DRV_CEM5) {
        index = 5U;
    } else if (cdp == &DRV_CEM6) {
        index = 6U;
    } else if (cdp == &DRV_CEM7) {
        index = 7U;
    } else if (cdp == &DRV_CEM8) {
        index = 8U;
    } else if (cdp == &DRV_CEM9) {
        index = 9U;
    } else if (cdp == &DRV_CEM10) {
        index = 10U;
    } else if (cdp == &DRV_CEM11) {
        index = 11U;
    } else if (cdp == &DRV_CEM12) {
        index = 12U;
    } else if (cdp == &DRV_CEM13) {
        index = 13U;
    } else {
        index = 14U;
    }

    return index;
}

/*===========================================================================*/
/* Module exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Returns pointer to the CEM register block.
 *
 * @param[in] cdp       pointer to a @p cem_driver_t structure
 * @return              pointer to the CEM register block.
 *
 * @notapi
 */
CEM_TypeDef *cem_dev_get_reg_ptr(cem_driver_t *cdp) {

    CEM_TypeDef *cem;

    if (cdp == &DRV_CEM0) {
        cem = CEM0;
    } else if (cdp == &DRV_CEM1) {
        cem = CEM1;
    } else if (cdp == &DRV_CEM2) {
        cem = CEM2;
    } else if (cdp == &DRV_CEM3) {
        cem = CEM3;
    } else if (cdp == &DRV_CEM4) {
        cem = CEM4;
    } else if (cdp == &DRV_CEM5) {
        cem = CEM5;
    } else if (cdp == &DRV_CEM6) {
        cem = CEM6;
    } else if (cdp == &DRV_CEM7) {
        cem = CEM7;
    } else if (cdp == &DRV_CEM8) {
        cem = CEM8;
    } else if (cdp == &DRV_CEM9) {
        cem = CEM9;
    } else if (cdp == &DRV_CEM10) {
        cem = CEM10;
    } else if (cdp == &DRV_CEM11) {
        cem = CEM11;
    } else if (cdp == &DRV_CEM12) {
        cem = CEM12;
    } else if (cdp == &DRV_CEM13) {
        cem = CEM13;
    } else {
        cem = CEM14;
    }

    return cem;
}

/**
 * @brief   Returns the number of groups for a specific CEM instances.
 *
 * @param[in] cdp       pointer to a @p cem_driver_t structure
 * @return              number of groups.
 *
 * @notapi
 */
uint8_t cem_dev_get_group_num(cem_driver_t *cdp) {

    (void)cdp;

    /* All CEM instances contains only 1 group.*/
    return 1U;
}

/**
 * @brief   Returns the FCCU fault number related to the specified group of the
 *          specified CEM instance.
 *
 * @param[in] cdp         pointer to a @p cem_driver_t structure
 * @param[in] group_num   group for which to return the FCCU fault
 * @param[out] fccu_fault FCCU fault number
 * @return                'true' if the group has an FCCU fault associated,
 *                        'false' otherwise.
 *
 * @notapi
 */
bool cem_dev_get_fccu_fault(cem_driver_t *cdp, uint16_t group_num,
                            uint8_t *fccu_fault) {

    uint8_t index;

    /* Get index related to CEM instance.*/
    index = cem_dev_get_index(cdp);

    if (cem_descriptors[index][group_num].reg_bit_num != 0U) {

        /* Return FCCU fault related to the specified group in CEM instance.*/
		*fccu_fault = (cem_descriptors[index][group_num].fccu_ch);
        return true;
    } else {
        return false;
    }
}

/** @} */
