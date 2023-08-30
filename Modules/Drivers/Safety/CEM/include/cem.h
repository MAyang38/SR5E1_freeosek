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
 * @file    cem.h
 * @brief   CEM driver header file.
 *
 * @addtogroup DRIVERS
 * @addtogroup SAFETY
 * @ingroup DRIVERS
 * @addtogroup CEM
 * @ingroup SAFETY
 * @{
 */

#ifndef _CEM_H_
#define _CEM_H_

#include <typedefs.h>

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

/**
 * @name    CEM default key
 * @{
 */
#define CEM_DEFAULT_KEY                     0xA5A5U
/** @} */

/**
 * @name    CEM maximum number of group for instance
 * @{
 */
#define CEM_GPOUP_NUMBER                    32U
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
 * @brief   Type of an CEM driver.
 */
typedef struct cem_driver cem_driver_t;

/**
 * @enum cem_cmd_t
 * CEM supported commands.
 */
typedef enum {
    CEM_CMD_ENABLE_FAULT = 0x1,        /**< Enable a specific input fault channel.                                                      */
    CEM_CMD_DISABLE_FAULT = 0x2,       /**< Disable a specific input fault channel.                                                     */
    CEM_CMD_SET_INJECT = 0x3,          /**< Inject a fault into a specific input fault channel.                                         */
    CEM_CMD_CLEAR_INJECT = 0x4,        /**< Clear the fault injected into a specific input fault channel.                               */
    CEM_CMD_READ_STATUS = 0x5,         /**< Read the fault status of a specific input fault channel.                                    */
    CEM_CMD_CLEAR_STATUS = 0x6,        /**< Clear the fault for a specific input fault channel.                                         */
    CEM_CMD_READ_FAULT_DATA = 0x7,     /**< Read the ENABLE, INJECT, and STATUS bits for a fault channel.                               */
    CEM_CMD_GROUP_READ_ENABLE = 0x10,  /**< Read the enabling status of the input fault channels for a specific OR-group.               */
    CEM_CMD_GROUP_WRITE_ENABLE = 0x11, /**< Enable or disable the input fault channels for a specific OR-group.                         */
    CEM_CMD_GROUP_READ_INJECT = 0x12,  /**< Read the fault injection status of the input fault channels for a specific OR-group.        */
    CEM_CMD_GROUP_WRITE_INJECT = 0x13, /**< Set or clear the injection faults for the input fault channels for a specific OR-group.     */
    CEM_CMD_GROUP_READ_STATUS = 0x14,  /**< Read the fault status of the input fault channels for a specific ORgroup.                   */
    CEM_CMD_GROUP_W1C_STATUS = 0x15,   /**< Write (write-1-clear) the fault status of the input fault channels for a specific OR-group. */
    CEM_CMD_GROUP_W1S_STATUS = 0x16    /**< Write (write-1-set) the fault status of the input fault channels for a specific OR-group.   */
} cem_cmd_t;

/**
 * @enum cem_group_descriptor_t
 * CEM group descriptor type.
 */
typedef struct {
    uint8_t reg_bit_num;     /**< Number of CEM reg bit in the group */
    uint8_t fccu_ch;         /**< FCCU channel related to the group  */
} cem_group_descriptor_t;

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

/* Export driver modules.*/
#include <cem_instances.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Initializes CEM instance.
 *
 * @param[out] cdp      pointer to a @p cem_driver_t structure
 *
 * @api
 */
void cem_init(cem_driver_t *cdp);

/**
 * @brief   Starts a CEM instance.
 *
 * @param[in] cdp       pointer to a @p cem_driver_t structure
 *
 * @api
 */
void cem_start(cem_driver_t *cdp);

/**
 * @brief   Writes CEM CMD register.
 *
 * @param[in] cdp       pointer to a @p cem_driver_t structure
 * @param[in] key       key for writing to CEM programmable registers
 * @param[in] command   command for accessing the CEM internal register. It can
 *                      be one of the following values:
 *            @arg @ref CEM_CMD_ENABLE_FAULT
 *            @arg @ref CEM_CMD_DISABLE_FAULT
 *            @arg @ref CEM_CMD_SET_INJECT
 *            @arg @ref CEM_CMD_CLEAR_INJECT
 *            @arg @ref CEM_CMD_READ_STATUS
 *            @arg @ref CEM_CMD_CLEAR_STATUS
 *            @arg @ref CEM_CMD_READ_FAULT_DATA
 *            @arg @ref CEM_CMD_GROUP_READ_ENABLE
 *            @arg @ref CEM_CMD_GROUP_WRITE_ENABLE
 *            @arg @ref CEM_CMD_GROUP_READ_INJECT
 *            @arg @ref CEM_CMD_GROUP_WRITE_INJECT
 *            @arg @ref CEM_CMD_GROUP_READ_STATUS
 *            @arg @ref CEM_CMD_GROUP_W1C_STATUS
 *            @arg @ref CEM_CMD_GROUP_W1S_STATUS
 * @param[in] fg_num    fault number or group number of corresponding internal
 *                      CEM registers
 *
 * @api
 */
void cem_write_cmd(cem_driver_t *cdp, uint16_t key, cem_cmd_t command,
                   uint16_t fg_num);

/**
 * @brief   Reads CEM CMD register.
 *
 * @param[in] cdp       pointer to a @p cem_driver_t structure
 * @return              CEM CMD register value.
 *
 * @api
 */
uint32_t cem_read_cmd(cem_driver_t *cdp);

/**
 * @brief   Reads CEM RDATA register.
 *
 * @param[in] cdp       pointer to a @p cem_driver_t structure
 * @return              data read after a command is executed.
 *
 * @api
 */
uint32_t cem_read_rdata(cem_driver_t *cdp);

/**
 * @brief   Writes CEM WDATA register.
 *
 * @param[in] cdp       pointer to a @p cem_driver_t structure
 * @param[in] data      data for setting/clearing internal RW register groups
 *
 * @api
 */
void cem_write_wdata(cem_driver_t *cdp, uint32_t data);

/**
 * @brief   Writes CEM WMASK register.
 *
 * @param[in] cdp       pointer to a @p cem_driver_t structure
 * @param[in] mask      mask bits for accessing individual fault group bits
 *                      during write operations
 *
 * @api
 */
void cem_write_wmask(cem_driver_t *cdp, uint32_t mask);

/**
 * @brief   Returns invalid address status from CEM CMD_STATUS register.
 *
 * @param[in] cdp       pointer to a @p cem_driver_t structure
 * @return              invalid address status: 'true' if an invalid address is
 *                      being accessed, 'false' otherwise.
 *
 * @api
 */
bool cem_get_invalid_address_status(cem_driver_t *cdp);

/**
 * @brief   Returns invalid key status from CEM CMD_STATUS register.
 *
 * @param[in] cdp       pointer to a @p cem_driver_t structure
 * @return              invalid key status: 'true' if an invalid key is written
 *                      in key field of CMD register, 'false' otherwise.
 *
 * @api
 */
bool cem_get_invalid_key_status(cem_driver_t *cdp);

/**
 * @brief   Returns invalid command status from CEM CMD_STATUS register.
 *
 * @param[in] cdp       pointer to a @p cem_driver_t structure
 * @return              invalid command status: 'true' if an invalid command is
 *                      written in command field of CMD register, 'false'
 *                      otherwise.
 *
 * @api
 */
bool cem_get_invalid_command_status(cem_driver_t *cdp);

/**
 * @brief   Sets golden key used for validation during write access.
 *
 * @param[in] cdp       pointer to a @p cem_driver_t structure
 * @param[in] superkey  golden key to be set
 *
 * @api
 */

void cem_set_superkey(cem_driver_t *cdp, uint16_t superkey);

/**
 * @brief   Enables a specific input fault channel.
 *
 * @param[in] cdp       pointer to a @p cem_driver_t structure
 * @param[in] fault_num fault channel to be enabled
 *
 * @api
 */
void cem_enable_fault(cem_driver_t *cdp, uint16_t fault_num);

/**
 * @brief   Disables a specific input fault channel.
 *
 * @param[in] cdp       pointer to a @p cem_driver_t structure
 * @param[in] fault_num fault channel to be disabled
 *
 * @api
 */
void cem_disable_fault(cem_driver_t *cdp, uint16_t fault_num);

/**
 * @brief   Injects a fault into a specific input fault channel.
 *
 * @param[in] cdp       pointer to a @p cem_driver_t structure
 * @param[in] fault_num fault channel on which injecting the fault
 *
 * @api
 */
void cem_set_inject(cem_driver_t *cdp, uint16_t fault_num);

/**
 * @brief   Clears the fault injected into a specific input fault channel.
 *
 * @param[in] cdp       pointer to a @p cem_driver_t structure
 * @param[in] fault_num fault channel on which clearing the injected fault
 *
 * @api
 */
void cem_clear_inject(cem_driver_t *cdp, uint16_t fault_num);

/**
 * @brief   Reads the fault status of a specific input fault channel.
 *
 * @param[in] cdp       pointer to a @p cem_driver_t structure
 * @param[in] fault_num fault channel for which to read the fault status
 * @return              fault status.
 *
 * @api
 */
uint32_t cem_read_status(cem_driver_t *cdp, uint16_t fault_num);

/**
 * @brief   Clears the fault for a specific input fault channel.
 *
 * @param[in] cdp       pointer to a @p cem_driver_t structure
 * @param[in] fault_num fault channel on which clearing the fault
 *
 * @api
 */
void cem_clear_status(cem_driver_t *cdp, uint16_t fault_num);

/**
 * @brief   Reads the ENABLE, INJECT, and STATUS bits for a fault channel.
 *
 * @param[in] cdp       pointer to a @p cem_driver_t structure
 * @param[in] fault_num fault cahnnel for which to read ENABLE, INJECT, and
 *                      STATUS bits
 * @return              fault ENABLE (bit0), INJECT (bit1), and STATUS (bit2)
 *                      bits.
 *
 * @api
 */
uint32_t cem_read_fault_data(cem_driver_t *cdp, uint16_t fault_num);

/**
 * @brief   Reads the enabling status of the input fault channels for a
 *          specific OR-group.
 *
 * @param[in] cdp       pointer to a @p cem_driver_t structure
 * @param[in] group_num group for which to read the enabling status
 * @return              group enabling status.
 *
 * @api
 */
uint32_t cem_group_read_enable(cem_driver_t *cdp, uint16_t group_num);

/**
 * @brief   Enables or disables the input fault channels for a specific
 *          OR-group.
 *
 * @param[in] cdp       pointer to a @p cem_driver_t structure
 * @param[in] group_num group for which to enable/disable the faults
 * @param[in] enable    enable flag: 'true' to enable the faults, 'false'
 *                      to disable the faults
 *
 * @api
 */
void cem_group_write_enable(cem_driver_t *cdp, uint16_t group_num, bool enable);

/**
 * @brief   Reads the fault injection status of the input fault channels for a
 *          specific OR-group.
 *
 * @param[in] cdp       pointer to a @p cem_driver_t structure
 * @param[in] group_num group for which to read the injection status
 * @return              group injection status.
 *
 * @api
 */
uint32_t cem_group_read_inject(cem_driver_t *cdp, uint16_t group_num);

/**
 * @brief   Sets or clears the injection faults for the input fault channels
 *          for a specific OR-group.
 *
 * @param[in] cdp       pointer to a @p cem_driver_t structure
 * @param[in] group_num group for which to set/clear the injection faults
 * @param[in] fault_msk fault mask specifing which faults to set/clear ('1' in
 *                      position 'i' means that the fault i must be set/clear)
 * @param[in] enable    enable flag: 'true' to enable the faults, 'false'
 *                      to disable the faults
 *
 * @api
 */
void cem_write_inject(cem_driver_t *cdp, uint16_t group_num, uint32_t fault_msk,
                      bool enable);

/**
 * @brief   Reads the fault status of the input fault channels for a specific
 *          OR-group.
 *
 * @param[in] cdp       pointer to a @p cem_driver_t structure
 * @param[in] group_num group for which to read the fault status
 * @return              group fault status.
 *
 * @api
 */
uint32_t cem_group_read_status(cem_driver_t *cdp, uint16_t group_num);

/**
 * @brief   Writes (write-1-clear) the fault status of the input fault channels
 *          for a specific OR-group.
 *
 * @param[in] cdp       pointer to a @p cem_driver_t structure
 * @param[in] group_num group for which to write (write-1-clear) the fault
 *                      status
 * @param[in] fault_msk fault mask specifing for which faults to write
 *                      (write-1-clear) the fault status
 *
 * @api
 */
void cem_group_w1c_status(cem_driver_t *cdp, uint16_t group_num,
                          uint32_t fault_msk);

/**
 * @brief   Writes (write-1-set) the fault status of the input fault channels
 *          for a specific OR-group.
 *
 * @param[in] cdp       pointer to a @p cem_driver_t structure
 * @param[in] group_num group for which to write (write-1-set) the fault status
 * @param[in] fault_msk fault mask specifing for which faults to write
 *                      (write-1-set) the fault status
 *
 * @api
 */
void cem_group_w1s_status(cem_driver_t *cdp, uint16_t group_num,
                          uint32_t fault_msk);

/**
 * @brief   Enables all input fault channels of all OR-groups of a CEM instance.
 *
 * @param[in] cdp       pointer to a @p cem_driver_t structure
 *
 * @api
 */
void cem_enable_all_groups(cem_driver_t *cdp);

/**
 * @brief   Disables all input fault channels of all OR-groups of a CEM instance.
 *
 * @param[in] cdp       pointer to a @p cem_driver_t structure
 *
 * @api
 */
void cem_disable_all_groups(cem_driver_t *cdp);

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
 * @api
 */
bool cem_get_fccu_fault(cem_driver_t *cdp, uint16_t group_num,
                        uint8_t *fccu_fault);

#ifdef __cplusplus
}
#endif

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/*===========================================================================*/
/* Module late inclusions.                                                   */
/*===========================================================================*/

#endif /* _CEM_H_ */

/** @} */
