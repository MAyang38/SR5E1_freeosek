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
 * @file    uart.h
 * @brief   Runtime IO module header file.
 *
 * @addtogroup RUNTIME
 * @addtogroup IO
 * @ingroup RUNTIME
 * @{
 */

#ifndef _IO_H_
#define _IO_H_

#include <uart.h>
#include <platform.h>
#include <typedefs.h>

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Module pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Module data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Initialize IO module.
 *
 * @param[in] udp           pointer to an @p uart_driver_t structure of UART
 *                          used for IO redirection
 * @return                  None.
 *
 * @api
 */
void io_init(uart_driver_t *udp);

/**
 * @brief   Start IO module.
 *
 * @param[in] uop           pointer to an @p uart_operation_t structure
 * @return                  None.
 *
 * @api
 */
void io_start(void);

/**
 * @brief   Get pointer to UART structure used for IO redirection.
 *
 * @return                  pointer to the @p uart_driver_t structure used for
 *                          IO redirection or NULL if no UART has been selected.
 *
 * @api
 */
uart_driver_t* io_getptr(void);

/**
 * @brief   Stop IO module.
 *
 * @return                  None.
 *
 * @api
 */
void io_stop(void);

/**
 * @brief   Deinitialize IO module.
 *
 * @return                  None.
 *
 * @api
 */
void io_deinit(void);

#ifdef __cplusplus
}
#endif

#endif /* _IO_H_ */

/** @} */
