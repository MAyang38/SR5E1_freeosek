/****************************************************************************
 *
 * Copyright (c) 2015-2019 STMicroelectronics - All Rights Reserved
 *
 * License terms: STMicroelectronics Proprietary in accordance with licensing
 * terms SLA0098 at www.st.com.
 *
 * THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
 * INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *****************************************************************************/

/************************************************************************
*            (c) Copyright Freescale Semiconductor, 2011                *
*                        All Rights Reserved                            *
*************************************************************************

*************************************************************************
*                                                                       *
*               Standard Software Driver for C55                        *
*                                                                       *
* FILE NAME     :  ssd_types.h                                          *
* DATE          :  December 21, 2011                                    *
* AUTHOR        :  FPT Team                                             *
* E-mail        :  r56611@freescale.com                                 *
*                                                                       *
*************************************************************************/

/******************************* CHANGES *********************************
  0.1.0   12.21.2011      FPT Team    Initial Version
  0.5.0   20.08.2019      G. Cuce     Changed header according to STM
                                      Guidelines for SW Copyrights and
                                      Disclaimers (v 2.0)  
*************************************************************************/

#ifndef _SSD_TYPES_H_
#define _SSD_TYPES_H_

/*************************************************************************/
/*  SSD general data types                                               */
/*************************************************************************/

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE (!FALSE)
#endif

typedef unsigned char BOOL;

typedef signed char INT8;
typedef unsigned char UINT8;
typedef volatile signed char VINT8;
typedef volatile unsigned char VUINT8;

typedef signed short INT16;
typedef unsigned short UINT16;
typedef volatile signed short VINT16;
typedef volatile unsigned short VUINT16;

typedef signed long INT32;
typedef unsigned long UINT32;
typedef volatile signed long VINT32;
typedef volatile unsigned long VUINT32;


#ifdef __GNUC__
#ifndef ASM_KEYWORD
#define ASM_KEYWORD asm
#endif
//#define _GCC_
#endif

#ifdef __ghs__
#ifndef ASM_KEYWORD
#define ASM_KEYWORD __asm
#endif
//#define _GREENHILLS_
#endif

#endif  /* _SSD_TYPES_H_ */
