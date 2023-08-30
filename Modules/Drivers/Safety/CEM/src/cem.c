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
 * @file    cem.c
 * @brief   CEM driver source file.
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

void cem_init(cem_driver_t *cdp) {

    /* Set pointer to CEM register block.*/
    cdp->cem = cem_dev_get_reg_ptr(cdp);

    /* Set number of groups.*/
    cdp->group_num = cem_dev_get_group_num(cdp);
}

void cem_start(cem_driver_t *cdp) {

    (void)(cdp);
}

void cem_write_cmd(cem_driver_t *cdp, uint16_t key, cem_cmd_t command,
                   uint16_t fg_num) {

    uint32_t cmd;

    cmd = ((CEM_CMD_KEY_Msk & (((uint32_t)key) << CEM_CMD_KEY_Pos))                                  |
           (CEM_CMD_CMD_Msk & (((uint32_t)command) << CEM_CMD_CMD_Pos))                              |
           (CEM_CMD_FAULT_OR_GRP_NUM_Msk & (((uint32_t)fg_num) << CEM_CMD_FAULT_OR_GRP_NUM_Pos)));

    cdp->cem->CMD = cmd;
}

uint32_t cem_read_cmd(cem_driver_t *cdp) {

    return (cdp->cem->CMD);
}

uint32_t cem_read_rdata(cem_driver_t *cdp) {

    return (cdp->cem->RDATA);
}

void cem_write_wdata(cem_driver_t *cdp, uint32_t data) {

    cdp->cem->WDATA = data;
}

void cem_write_wmask(cem_driver_t *cdp, uint32_t mask) {

    cdp->cem->WMASK = mask;
}

bool cem_get_invalid_address_status(cem_driver_t *cdp) {

    if (REG_READ_FIELD(cdp->cem->CMD_STATUS, CEM_CMD_STATUS_INV_REG) == 0x1U) {
        return true;
    } else {
        return false;
    }
}

bool cem_get_invalid_key_status(cem_driver_t *cdp) {

    if (REG_READ_FIELD(cdp->cem->CMD_STATUS, CEM_CMD_STATUS_INV_KEY) == 0x1U) {
        return true;
    } else {
        return false;
    }
}

bool cem_get_invalid_command_status(cem_driver_t *cdp) {

    if (REG_READ_FIELD(cdp->cem->CMD_STATUS, CEM_CMD_STATUS_INV_CMD) == 0x1U) {
        return true;
    } else {
        return false;
    }
}

void cem_set_superkey(cem_driver_t *cdp, uint16_t superkey) {

    cdp->cem->SUPERKEY = superkey;
}

void cem_enable_fault(cem_driver_t *cdp, uint16_t fault_num) {

    cem_write_cmd(cdp, CEM_DEFAULT_KEY, CEM_CMD_ENABLE_FAULT, fault_num);
    (void)cem_read_cmd(cdp);
}

void cem_disable_fault(cem_driver_t *cdp, uint16_t fault_num) {

    cem_write_cmd(cdp, CEM_DEFAULT_KEY, CEM_CMD_DISABLE_FAULT, fault_num);
    (void)cem_read_cmd(cdp);
}

void cem_set_inject(cem_driver_t *cdp, uint16_t fault_num) {

    cem_write_cmd(cdp, CEM_DEFAULT_KEY, CEM_CMD_SET_INJECT, fault_num);
    (void)cem_read_cmd(cdp);
}

void cem_clear_inject(cem_driver_t *cdp, uint16_t fault_num) {

    cem_write_cmd(cdp, CEM_DEFAULT_KEY, CEM_CMD_CLEAR_INJECT, fault_num);
    (void)cem_read_cmd(cdp);
}

uint32_t cem_read_status(cem_driver_t *cdp, uint16_t fault_num) {

    cem_write_cmd(cdp, CEM_DEFAULT_KEY, CEM_CMD_READ_STATUS, fault_num);
    return cem_read_rdata(cdp);
}

void cem_clear_status(cem_driver_t *cdp, uint16_t fault_num) {

    cem_write_cmd(cdp, CEM_DEFAULT_KEY, CEM_CMD_CLEAR_STATUS, fault_num);
    (void)cem_read_status(cdp, fault_num);
}

uint32_t cem_read_fault_data(cem_driver_t *cdp, uint16_t fault_num) {

    cem_write_cmd(cdp, CEM_DEFAULT_KEY, CEM_CMD_READ_FAULT_DATA, fault_num);
    return cem_read_rdata(cdp);
}

uint32_t cem_group_read_enable(cem_driver_t *cdp, uint16_t group_num) {

    cem_write_cmd(cdp, CEM_DEFAULT_KEY, CEM_CMD_GROUP_READ_ENABLE, group_num);
    return cem_read_rdata(cdp);
}

void cem_group_write_enable(cem_driver_t *cdp, uint16_t group_num, bool enable) {

    cem_write_wmask(cdp, 0x1UL << group_num);
    if ((bool)enable == true) {
        cem_write_wdata(cdp, 0x1UL << group_num);
    } else {
        cem_write_wdata(cdp, 0x0UL);
    }

    cem_write_cmd(cdp, CEM_DEFAULT_KEY, CEM_CMD_GROUP_WRITE_ENABLE, group_num);
    (void)cem_read_cmd(cdp);
    (void)cem_read_rdata(cdp);
}

uint32_t cem_group_read_inject(cem_driver_t *cdp, uint16_t group_num) {

    cem_write_cmd(cdp, CEM_DEFAULT_KEY, CEM_CMD_GROUP_READ_INJECT, group_num);
    return cem_read_rdata(cdp);
}

void cem_write_inject(cem_driver_t *cdp, uint16_t group_num, uint32_t fault_msk,
                      bool enable) {

    cem_write_wmask(cdp, fault_msk);
    if ((bool)enable == true) {
        cem_write_wdata(cdp, fault_msk);
    } else {
        cem_write_wdata(cdp, 0x0UL);
    }

    cem_write_cmd(cdp, CEM_DEFAULT_KEY, CEM_CMD_GROUP_WRITE_INJECT, group_num);
    (void)cem_read_cmd(cdp);
    (void)cem_read_rdata(cdp);
}

uint32_t cem_group_read_status(cem_driver_t *cdp, uint16_t group_num) {

    cem_write_cmd(cdp, CEM_DEFAULT_KEY, CEM_CMD_GROUP_READ_STATUS, group_num);
    return cem_read_rdata(cdp);
}

void cem_group_w1c_status(cem_driver_t *cdp, uint16_t group_num,
                          uint32_t fault_msk) {

    cem_write_wdata(cdp, fault_msk);
    cem_write_cmd(cdp, CEM_DEFAULT_KEY, CEM_CMD_GROUP_W1C_STATUS, group_num);
    (void)cem_read_cmd(cdp);
    (void)cem_read_rdata(cdp);
    (void)cem_group_read_status(cdp, group_num);
}

void cem_group_w1s_status(cem_driver_t *cdp, uint16_t group_num,
                          uint32_t fault_msk) {

    cem_write_wdata(cdp, fault_msk);
    cem_write_cmd(cdp, CEM_DEFAULT_KEY, CEM_CMD_GROUP_W1S_STATUS, group_num);
    (void)cem_read_cmd(cdp);
    (void)cem_read_rdata(cdp);
}

void cem_enable_all_groups(cem_driver_t *cdp) {

    uint16_t i;

    for (i = 0U; i < cdp->group_num; i++) {
        cem_group_write_enable(cdp, i, true);
    }
}

void cem_disable_all_groups(cem_driver_t *cdp) {

    uint16_t i;

    for (i = 0U; i < cdp->group_num; i++) {
        cem_group_write_enable(cdp, i, false);
    }
}

bool cem_get_fccu_fault(cem_driver_t *cdp, uint16_t group_num,
                        uint8_t *fccu_fault) {

    return cem_dev_get_fccu_fault(cdp, group_num, fccu_fault);
}

/** @} */
