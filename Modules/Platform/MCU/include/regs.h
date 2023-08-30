/****************************************************************************
 *
 * Copyright (c) 2021 STMicroelectronics - All Rights Reserved
 *
 * License terms: STMicroelectronics Proprietary in accordance with licensing
 * terms SLA0098 at www.st.com.
 *
 * THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
 * INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *****************************************************************************/
/**
 * @file    regs.h
 * @brief   register access macros.
 *
 * @addtogroup PLATFORM
 * @addtogroup MCU
 * @ingroup PLATFORM
 * @{
 */

#ifndef _REGS_H_
#define _REGS_H_

/**
 * @brief   Reads register
 * @details This macro reads a 32-bit register.
 *
 * @param[in] _regp_    pointer to the register to be read
 * @return              the value of reguster
 *
 * @api
 */
#define REG_READ(_regp_)                                            \
    ((_regp_))

/**
 * @brief   Clears register
 * @details This macro clears a 32-bit register.
 *
 * @param[in] _regp_    pointer to the register to be cleared
 *
 * @api
 */
#define REG_CLEAR(_regp_)                                            \
    ((_regp_) = (0x0UL))

/**
 * @brief   Sets register value
 * @details This macro sets a 32-bit register to a specified value.
 *
 * @param[in] _regp_    pointer to the register to be set
 * @param[in] _value_   value to which the field is set
 *
 * @api
 */
#define REG_SET(_regp_, _value_)                                     \
    ((_regp_) = ((uint32_t)(_value_)))

/**
 * @brief   Reads register field
 * @details This macro reads the value of a field in a register.
 *
 * @param[in] _regp_    pointer to the register contains the field to be read
 * @param[in] _field_   field to be read
 * @return              the value of field
 * @api
 */
#define REG_READ_FIELD(_regp_, _field_)                              \
    (((_regp_) & (_field_ ## _Msk)) >> (_field_ ## _Pos))

/**
 * @brief   Clears register field
 * @details This macro clears the value of a field in a register.
 *
 * @param[in] _regp_    pointer to the register contains the field to be cleared
 * @param[in] _field_   field to be cleared
 *
 * @api
 */
#define REG_CLEAR_FIELD(_regp_, _field_)                             \
    ((_regp_) = ((_regp_) & (~(_field_ ## _Msk))))

/**
 * @brief   Sets register field
 * @details This macro sets a field in a 32-bit register to a specified value.
 *
 * @param[in] _regp_    pointer to the register contains the field to be set
 * @param[in] _field_   field to be set
 * @param[in] _value_   value to which the field is set
 *
 * @api
 */
#define REG_SET_FIELD(_regp_, _field_, _value_)                      \
    ((_regp_) = (((_regp_) & (~(_field_ ## _Msk))) | ((_field_ ## _Msk) & ((((uint32_t)(_value_))) << (_field_ ## _Pos)))))

#endif /* _REGS_H_ */
