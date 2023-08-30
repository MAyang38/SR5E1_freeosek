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
 * @file    GCC/vectors.S
 * @brief   Interrupt vectors for ARMv7-M devices.
 *
 * @addtogroup BOOT
 * @{
 */

#define _FROM_ASM_
#include "cmparams.h"
#include "toolchain.h"

#if (CORTEX_NUM_VECTORS % 8) != 0
#error "the constant CORTEX_NUM_VECTORS must be a multiple of 8"
#endif

#if (CORTEX_NUM_VECTORS < 8) || (CORTEX_NUM_VECTORS > 240)
#error "the constant CORTEX_NUM_VECTORS must be between 8 and 240 inclusive"
#endif

/*===========================================================================*/
/* Code section.                                                             */
/*===========================================================================*/

#if !defined(__DOXYGEN__)

        .thumb
        .section .vectors, "ax"

        .global _vectors
        _ASM_THUMB_FUNCTION_
_vectors:
        .long       __main_stack_end__
        .long       Reset_Handler
        .long       NMI_Handler
        .long       HardFault_Handler
        .long       MemManage_Handler
        .long       BusFault_Handler
        .long       UsageFault_Handler
        .long       Vector1C
        .long       Vector20
        .long       Vector24
        .long       Vector28
        .long       SVC_Handler
        .long       DebugMon_Handler
        .long       Vector34
        .long       PendSV_Handler
        .long       SysTick_Handler
        .long       Vector40,   Vector44,   Vector48,   Vector4C
#if CORTEX_NUM_VECTORS > 4
        .long       Vector50,   Vector54,   Vector58,   Vector5C
#endif
#if CORTEX_NUM_VECTORS > 8
        .long       Vector60,   Vector64,   Vector68,   Vector6C
#endif
#if CORTEX_NUM_VECTORS > 12
        .long       Vector70,   Vector74,   Vector78,   Vector7C
#endif
#if CORTEX_NUM_VECTORS > 16
        .long       Vector80,   Vector84,   Vector88,   Vector8C
#endif
#if CORTEX_NUM_VECTORS > 20
        .long       Vector90,   Vector94,   Vector98,   Vector9C
#endif
#if CORTEX_NUM_VECTORS > 24
        .long       VectorA0,   VectorA4,   VectorA8,   VectorAC
#endif
#if CORTEX_NUM_VECTORS > 28
        .long       VectorB0,   VectorB4,   VectorB8,   VectorBC
#endif
#if CORTEX_NUM_VECTORS > 32
        .long       VectorC0,   VectorC4,   VectorC8,   VectorCC
#endif
#if CORTEX_NUM_VECTORS > 36
        .long       VectorD0,   VectorD4,   VectorD8,   VectorDC
#endif
#if CORTEX_NUM_VECTORS > 40
        .long       VectorE0,   VectorE4,   VectorE8,   VectorEC
#endif
#if CORTEX_NUM_VECTORS > 44
        .long       VectorF0,   VectorF4,   VectorF8,   VectorFC
#endif
#if CORTEX_NUM_VECTORS > 48
        .long       Vector100,  Vector104,  Vector108,  Vector10C
#endif
#if CORTEX_NUM_VECTORS > 52
        .long       Vector110,  Vector114,  Vector118,  Vector11C
#endif
#if CORTEX_NUM_VECTORS > 56
        .long       Vector120,  Vector124,  Vector128,  Vector12C
#endif
#if CORTEX_NUM_VECTORS > 60
        .long       Vector130,  Vector134,  Vector138,  Vector13C
#endif
#if CORTEX_NUM_VECTORS > 64
        .long       Vector140,  Vector144,  Vector148,  Vector14C
#endif
#if CORTEX_NUM_VECTORS > 68
        .long       Vector150,  Vector154,  Vector158,  Vector15C
#endif
#if CORTEX_NUM_VECTORS > 72
        .long       Vector160,  Vector164,  Vector168,  Vector16C
#endif
#if CORTEX_NUM_VECTORS > 76
        .long       Vector170,  Vector174,  Vector178,  Vector17C
#endif
#if CORTEX_NUM_VECTORS > 80
        .long       Vector180,  Vector184,  Vector188,  Vector18C
#endif
#if CORTEX_NUM_VECTORS > 84
        .long       Vector190,  Vector194,  Vector198,  Vector19C
#endif
#if CORTEX_NUM_VECTORS > 88
        .long       Vector1A0,  Vector1A4,  Vector1A8,  Vector1AC
#endif
#if CORTEX_NUM_VECTORS > 92
        .long       Vector1B0,  Vector1B4,  Vector1B8,  Vector1BC
#endif
#if CORTEX_NUM_VECTORS > 96
        .long       Vector1C0,  Vector1C4,  Vector1C8,  Vector1CC
#endif
#if CORTEX_NUM_VECTORS > 100
        .long       Vector1D0,  Vector1D4,  Vector1D8,  Vector1DC
#endif
#if CORTEX_NUM_VECTORS > 104
        .long       Vector1E0,  Vector1E4,  Vector1E8,  Vector1EC
#endif
#if CORTEX_NUM_VECTORS > 108
        .long       Vector1F0,  Vector1F4,  Vector1F8,  Vector1FC
#endif
#if CORTEX_NUM_VECTORS > 112
        .long       Vector200,  Vector204,  Vector208,  Vector20C
#endif
#if CORTEX_NUM_VECTORS > 116
        .long       Vector210,  Vector214,  Vector218,  Vector21C
#endif
#if CORTEX_NUM_VECTORS > 120
        .long       Vector220,  Vector224,  Vector228,  Vector22C
#endif
#if CORTEX_NUM_VECTORS > 124
        .long       Vector230,  Vector234,  Vector238,  Vector23C
#endif
#if CORTEX_NUM_VECTORS > 128
        .long       Vector240,  Vector244,  Vector248,  Vector24C
#endif
#if CORTEX_NUM_VECTORS > 132
        .long       Vector250,  Vector254,  Vector258,  Vector25C
#endif
#if CORTEX_NUM_VECTORS > 136
        .long       Vector260,  Vector264,  Vector268,  Vector26C
#endif
#if CORTEX_NUM_VECTORS > 140
        .long       Vector270,  Vector274,  Vector278,  Vector27C
#endif
#if CORTEX_NUM_VECTORS > 144
        .long       Vector280,  Vector284,  Vector288,  Vector28C
#endif
#if CORTEX_NUM_VECTORS > 148
        .long       Vector290,  Vector294,  Vector298,  Vector29C
#endif
#if CORTEX_NUM_VECTORS > 152
        .long       Vector2A0,  Vector2A4,  Vector2A8,  Vector2AC
#endif
#if CORTEX_NUM_VECTORS > 156
        .long       Vector2B0,  Vector2B4,  Vector2B8,  Vector2BC
#endif
#if CORTEX_NUM_VECTORS > 160
        .long       Vector2C0,  Vector2C4,  Vector2C8,  Vector2CC
#endif
#if CORTEX_NUM_VECTORS > 164
        .long       Vector2D0,  Vector2D4,  Vector2D8,  Vector2DC
#endif
#if CORTEX_NUM_VECTORS > 168
        .long       Vector2E0,  Vector2E4,  Vector2E8,  Vector2EC
#endif
#if CORTEX_NUM_VECTORS > 172
        .long       Vector2F0,  Vector2F4,  Vector2F8,  Vector2FC
#endif
#if CORTEX_NUM_VECTORS > 176
        .long       Vector300,  Vector304,  Vector308,  Vector30C
#endif
#if CORTEX_NUM_VECTORS > 180
        .long       Vector310,  Vector314,  Vector318,  Vector31C
#endif
#if CORTEX_NUM_VECTORS > 184
        .long       Vector320,  Vector324,  Vector328,  Vector32C
#endif
#if CORTEX_NUM_VECTORS > 188
        .long       Vector330,  Vector334,  Vector338,  Vector33C
#endif
#if CORTEX_NUM_VECTORS > 192
        .long       Vector340,  Vector344,  Vector348,  Vector34C
#endif
#if CORTEX_NUM_VECTORS > 196
        .long       Vector350,  Vector354,  Vector358,  Vector35C
#endif
#if CORTEX_NUM_VECTORS > 200
        .long       Vector360,  Vector364,  Vector368,  Vector36C
#endif
#if CORTEX_NUM_VECTORS > 204
        .long       Vector370,  Vector374,  Vector378,  Vector37C
#endif
#if CORTEX_NUM_VECTORS > 208
        .long       Vector380,  Vector384,  Vector388,  Vector38C
#endif
#if CORTEX_NUM_VECTORS > 212
        .long       Vector390,  Vector394,  Vector398,  Vector39C
#endif
#if CORTEX_NUM_VECTORS > 216
        .long       Vector3A0,  Vector3A4,  Vector3A8,  Vector3AC
#endif
#if CORTEX_NUM_VECTORS > 220
        .long       Vector3B0,  Vector3B4,  Vector3B8,  Vector3BC
#endif
#if CORTEX_NUM_VECTORS > 224
        .long       Vector3C0,  Vector3C4,  Vector3C8,  Vector3CC
#endif
#if CORTEX_NUM_VECTORS > 228
        .long       Vector3D0,  Vector3D4,  Vector3D8,  Vector3DC
#endif
#if CORTEX_NUM_VECTORS > 232
        .long       Vector3E0,  Vector3E4,  Vector3E8,  Vector3EC
#endif
#if CORTEX_NUM_VECTORS > 236
        .long       Vector3F0,  Vector3F4,  Vector3F8,  Vector3FC
#endif

        .section .reset_handler, "ax"

        .align      2
        _ASM_THUMB_FUNCTION_
        .global     Reset_Handler
Reset_Handler:
         b          _crt0_entry

        _ASM_THUMB_FUNCTION_
        .weak       NMI_Handler
        .weak       HardFault_Handler
        .weak       MemManage_Handler
        .weak       BusFault_Handler
        .weak       UsageFault_Handler
        .weak       Vector1C
        .weak       Vector20
        .weak       Vector24
        .weak       Vector28
        .weak       SVC_Handler
        .weak       DebugMon_Handler
        .weak       Vector34
        .weak       PendSV_Handler
        .weak       SysTick_Handler
        .weak       Vector40,   Vector44,   Vector48,   Vector4C
#if CORTEX_NUM_VECTORS > 4
        .weak       Vector50,   Vector54,   Vector58,   Vector5C
#endif
#if CORTEX_NUM_VECTORS > 8
        .weak       Vector60,   Vector64,   Vector68,   Vector6C
#endif
#if CORTEX_NUM_VECTORS > 12
        .weak       Vector70,   Vector74,   Vector78,   Vector7C
#endif
#if CORTEX_NUM_VECTORS > 16
        .weak       Vector80,   Vector84,   Vector88,   Vector8C
#endif
#if CORTEX_NUM_VECTORS > 20
        .weak       Vector90,   Vector94,   Vector98,   Vector9C
#endif
#if CORTEX_NUM_VECTORS > 24
        .weak       VectorA0,   VectorA4,   VectorA8,   VectorAC
#endif
#if CORTEX_NUM_VECTORS > 28
        .weak       VectorB0,   VectorB4,   VectorB8,   VectorBC
#endif
#if CORTEX_NUM_VECTORS > 32
        .weak       VectorC0,   VectorC4,   VectorC8,   VectorCC
#endif
#if CORTEX_NUM_VECTORS > 36
        .weak       VectorD0,   VectorD4,   VectorD8,   VectorDC
#endif
#if CORTEX_NUM_VECTORS > 40
        .weak       VectorE0,   VectorE4,   VectorE8,   VectorEC
#endif
#if CORTEX_NUM_VECTORS > 44
        .weak       VectorF0,   VectorF4,   VectorF8,   VectorFC
#endif
#if CORTEX_NUM_VECTORS > 48
        .weak       Vector100,  Vector104,  Vector108,  Vector10C
#endif
#if CORTEX_NUM_VECTORS > 52
        .weak       Vector110,  Vector114,  Vector118,  Vector11C
#endif
#if CORTEX_NUM_VECTORS > 56
        .weak       Vector120,  Vector124,  Vector128,  Vector12C
#endif
#if CORTEX_NUM_VECTORS > 60
        .weak       Vector130,  Vector134,  Vector138,  Vector13C
#endif
#if CORTEX_NUM_VECTORS > 64
        .weak       Vector140,  Vector144,  Vector148,  Vector14C
#endif
#if CORTEX_NUM_VECTORS > 68
        .weak       Vector150,  Vector154,  Vector158,  Vector15C
#endif
#if CORTEX_NUM_VECTORS > 72
        .weak       Vector160,  Vector164,  Vector168,  Vector16C
#endif
#if CORTEX_NUM_VECTORS > 76
        .weak       Vector170,  Vector174,  Vector178,  Vector17C
#endif
#if CORTEX_NUM_VECTORS > 80
        .weak       Vector180,  Vector184,  Vector188,  Vector18C
#endif
#if CORTEX_NUM_VECTORS > 84
        .weak       Vector190,  Vector194,  Vector198,  Vector19C
#endif
#if CORTEX_NUM_VECTORS > 88
        .weak       Vector1A0,  Vector1A4,  Vector1A8,  Vector1AC
#endif
#if CORTEX_NUM_VECTORS > 92
        .weak       Vector1B0,  Vector1B4,  Vector1B8,  Vector1BC
#endif
#if CORTEX_NUM_VECTORS > 96
        .weak       Vector1C0,  Vector1C4,  Vector1C8,  Vector1CC
#endif
#if CORTEX_NUM_VECTORS > 100
        .weak       Vector1D0,  Vector1D4,  Vector1D8,  Vector1DC
#endif
#if CORTEX_NUM_VECTORS > 104
        .weak       Vector1E0,  Vector1E4,  Vector1E8,  Vector1EC
#endif
#if CORTEX_NUM_VECTORS > 108
        .weak       Vector1F0,  Vector1F4,  Vector1F8,  Vector1FC
#endif
#if CORTEX_NUM_VECTORS > 112
        .weak       Vector200,  Vector204,  Vector208,  Vector20C
#endif
#if CORTEX_NUM_VECTORS > 116
        .weak       Vector210,  Vector214,  Vector218,  Vector21C
#endif
#if CORTEX_NUM_VECTORS > 120
        .weak       Vector220,  Vector224,  Vector228,  Vector22C
#endif
#if CORTEX_NUM_VECTORS > 124
        .weak       Vector230,  Vector234,  Vector238,  Vector23C
#endif
#if CORTEX_NUM_VECTORS > 128
        .weak       Vector240,  Vector244,  Vector248,  Vector24C
#endif
#if CORTEX_NUM_VECTORS > 132
        .weak       Vector250,  Vector254,  Vector258,  Vector25C
#endif
#if CORTEX_NUM_VECTORS > 136
        .weak       Vector260,  Vector264,  Vector268,  Vector26C
#endif
#if CORTEX_NUM_VECTORS > 140
        .weak       Vector270,  Vector274,  Vector278,  Vector27C
#endif
#if CORTEX_NUM_VECTORS > 144
        .weak       Vector280,  Vector284,  Vector288,  Vector28C
#endif
#if CORTEX_NUM_VECTORS > 148
        .weak       Vector290,  Vector294,  Vector298,  Vector29C
#endif
#if CORTEX_NUM_VECTORS > 152
        .weak       Vector2A0,  Vector2A4,  Vector2A8,  Vector2AC
#endif
#if CORTEX_NUM_VECTORS > 156
        .weak       Vector2B0,  Vector2B4,  Vector2B8,  Vector2BC
#endif
#if CORTEX_NUM_VECTORS > 160
        .weak       Vector2C0,  Vector2C4,  Vector2C8,  Vector2CC
#endif
#if CORTEX_NUM_VECTORS > 164
        .weak       Vector2D0,  Vector2D4,  Vector2D8,  Vector2DC
#endif
#if CORTEX_NUM_VECTORS > 168
        .weak       Vector2E0,  Vector2E4,  Vector2E8,  Vector2EC
#endif
#if CORTEX_NUM_VECTORS > 172
        .weak       Vector2F0,  Vector2F4,  Vector2F8,  Vector2FC
#endif
#if CORTEX_NUM_VECTORS > 176
        .weak       Vector300,  Vector304,  Vector308,  Vector30C
#endif
#if CORTEX_NUM_VECTORS > 180
        .weak       Vector310,  Vector314,  Vector318,  Vector31C
#endif
#if CORTEX_NUM_VECTORS > 184
        .weak       Vector320,  Vector324,  Vector328,  Vector32C
#endif
#if CORTEX_NUM_VECTORS > 188
        .weak       Vector330,  Vector334,  Vector338,  Vector33C
#endif
#if CORTEX_NUM_VECTORS > 192
        .weak       Vector340,  Vector344,  Vector348,  Vector34C
#endif
#if CORTEX_NUM_VECTORS > 196
        .weak       Vector350,  Vector354,  Vector358,  Vector35C
#endif
#if CORTEX_NUM_VECTORS > 200
        .weak       Vector360,  Vector364,  Vector368,  Vector36C
#endif
#if CORTEX_NUM_VECTORS > 204
        .weak       Vector370,  Vector374,  Vector378,  Vector37C
#endif
#if CORTEX_NUM_VECTORS > 208
        .weak       Vector380,  Vector384,  Vector388,  Vector38C
#endif
#if CORTEX_NUM_VECTORS > 212
        .weak       Vector390,  Vector394,  Vector398,  Vector39C
#endif
#if CORTEX_NUM_VECTORS > 216
        .weak       Vector3A0,  Vector3A4,  Vector3A8,  Vector3AC
#endif
#if CORTEX_NUM_VECTORS > 220
        .weak       Vector3B0,  Vector3B4,  Vector3B8,  Vector3BC
#endif
#if CORTEX_NUM_VECTORS > 224
        .weak       Vector3C0,  Vector3C4,  Vector3C8,  Vector3CC
#endif
#if CORTEX_NUM_VECTORS > 228
        .weak       Vector3D0,  Vector3D4,  Vector3D8,  Vector3DC
#endif
#if CORTEX_NUM_VECTORS > 232
        .weak       Vector3E0,  Vector3E4,  Vector3E8,  Vector3EC
#endif
#if CORTEX_NUM_VECTORS > 236
        .weak       Vector3F0,  Vector3F4,  Vector3F8,  Vector3FC
#endif

        _ASM_THUMB_FUNCTION_
NMI_Handler:
        _ASM_THUMB_FUNCTION_
HardFault_Handler:
        _ASM_THUMB_FUNCTION_
MemManage_Handler:
        _ASM_THUMB_FUNCTION_
BusFault_Handler:
        _ASM_THUMB_FUNCTION_
UsageFault_Handler:
        _ASM_THUMB_FUNCTION_
Vector1C:
        _ASM_THUMB_FUNCTION_
Vector20:
        _ASM_THUMB_FUNCTION_
Vector24:
        _ASM_THUMB_FUNCTION_
Vector28:
        _ASM_THUMB_FUNCTION_
SVC_Handler:
        _ASM_THUMB_FUNCTION_
DebugMon_Handler:
        _ASM_THUMB_FUNCTION_
Vector34:
        _ASM_THUMB_FUNCTION_
PendSV_Handler:
        _ASM_THUMB_FUNCTION_
SysTick_Handler:
        _ASM_THUMB_FUNCTION_
Vector40:
        _ASM_THUMB_FUNCTION_
Vector44:
        _ASM_THUMB_FUNCTION_
Vector48:
        _ASM_THUMB_FUNCTION_
Vector4C:
        _ASM_THUMB_FUNCTION_
Vector50:
        _ASM_THUMB_FUNCTION_
Vector54:
        _ASM_THUMB_FUNCTION_
Vector58:
        _ASM_THUMB_FUNCTION_
Vector5C:
#if CORTEX_NUM_VECTORS > 8
        _ASM_THUMB_FUNCTION_
Vector60:
        _ASM_THUMB_FUNCTION_
Vector64:
        _ASM_THUMB_FUNCTION_
Vector68:
        _ASM_THUMB_FUNCTION_
Vector6C:
        _ASM_THUMB_FUNCTION_
Vector70:
        _ASM_THUMB_FUNCTION_
Vector74:
        _ASM_THUMB_FUNCTION_
Vector78:
        _ASM_THUMB_FUNCTION_
Vector7C:
#endif
#if CORTEX_NUM_VECTORS > 16
        _ASM_THUMB_FUNCTION_
Vector80:
        _ASM_THUMB_FUNCTION_
Vector84:
        _ASM_THUMB_FUNCTION_
Vector88:
        _ASM_THUMB_FUNCTION_
Vector8C:
        _ASM_THUMB_FUNCTION_
Vector90:
        _ASM_THUMB_FUNCTION_
Vector94:
        _ASM_THUMB_FUNCTION_
Vector98:
        _ASM_THUMB_FUNCTION_
Vector9C:
#endif
#if CORTEX_NUM_VECTORS > 24
        _ASM_THUMB_FUNCTION_
VectorA0:
        _ASM_THUMB_FUNCTION_
VectorA4:
        _ASM_THUMB_FUNCTION_
VectorA8:
        _ASM_THUMB_FUNCTION_
VectorAC:
        _ASM_THUMB_FUNCTION_
VectorB0:
        _ASM_THUMB_FUNCTION_
VectorB4:
        _ASM_THUMB_FUNCTION_
VectorB8:
        _ASM_THUMB_FUNCTION_
VectorBC:
#endif
#if CORTEX_NUM_VECTORS > 32
        _ASM_THUMB_FUNCTION_
VectorC0:
        _ASM_THUMB_FUNCTION_
VectorC4:
        _ASM_THUMB_FUNCTION_
VectorC8:
        _ASM_THUMB_FUNCTION_
VectorCC:
        _ASM_THUMB_FUNCTION_
VectorD0:
        _ASM_THUMB_FUNCTION_
VectorD4:
        _ASM_THUMB_FUNCTION_
VectorD8:
        _ASM_THUMB_FUNCTION_
VectorDC:
#endif
#if CORTEX_NUM_VECTORS > 40
        _ASM_THUMB_FUNCTION_
VectorE0:
        _ASM_THUMB_FUNCTION_
VectorE4:
        _ASM_THUMB_FUNCTION_
VectorE8:
        _ASM_THUMB_FUNCTION_
VectorEC:
        _ASM_THUMB_FUNCTION_
VectorF0:
        _ASM_THUMB_FUNCTION_
VectorF4:
        _ASM_THUMB_FUNCTION_
VectorF8:
        _ASM_THUMB_FUNCTION_
VectorFC:
#endif
#if CORTEX_NUM_VECTORS > 48
        _ASM_THUMB_FUNCTION_
Vector100:
        _ASM_THUMB_FUNCTION_
Vector104:
        _ASM_THUMB_FUNCTION_
Vector108:
        _ASM_THUMB_FUNCTION_
Vector10C:
        _ASM_THUMB_FUNCTION_
Vector110:
        _ASM_THUMB_FUNCTION_
Vector114:
        _ASM_THUMB_FUNCTION_
Vector118:
        _ASM_THUMB_FUNCTION_
Vector11C:
#endif
#if CORTEX_NUM_VECTORS > 56
        _ASM_THUMB_FUNCTION_
Vector120:
        _ASM_THUMB_FUNCTION_
Vector124:
        _ASM_THUMB_FUNCTION_
Vector128:
        _ASM_THUMB_FUNCTION_
Vector12C:
        _ASM_THUMB_FUNCTION_
Vector130:
        _ASM_THUMB_FUNCTION_
Vector134:
        _ASM_THUMB_FUNCTION_
Vector138:
        _ASM_THUMB_FUNCTION_
Vector13C:
#endif
#if CORTEX_NUM_VECTORS > 64
        _ASM_THUMB_FUNCTION_
Vector140:
        _ASM_THUMB_FUNCTION_
Vector144:
        _ASM_THUMB_FUNCTION_
Vector148:
        _ASM_THUMB_FUNCTION_
Vector14C:
        _ASM_THUMB_FUNCTION_
Vector150:
        _ASM_THUMB_FUNCTION_
Vector154:
        _ASM_THUMB_FUNCTION_
Vector158:
        _ASM_THUMB_FUNCTION_
Vector15C:
#endif
#if CORTEX_NUM_VECTORS > 72
        _ASM_THUMB_FUNCTION_
Vector160:
        _ASM_THUMB_FUNCTION_
Vector164:
        _ASM_THUMB_FUNCTION_
Vector168:
        _ASM_THUMB_FUNCTION_
Vector16C:
        _ASM_THUMB_FUNCTION_
Vector170:
        _ASM_THUMB_FUNCTION_
Vector174:
        _ASM_THUMB_FUNCTION_
Vector178:
        _ASM_THUMB_FUNCTION_
Vector17C:
#endif
#if CORTEX_NUM_VECTORS > 80
        _ASM_THUMB_FUNCTION_
Vector180:
        _ASM_THUMB_FUNCTION_
Vector184:
        _ASM_THUMB_FUNCTION_
Vector188:
        _ASM_THUMB_FUNCTION_
Vector18C:
        _ASM_THUMB_FUNCTION_
Vector190:
        _ASM_THUMB_FUNCTION_
Vector194:
        _ASM_THUMB_FUNCTION_
Vector198:
        _ASM_THUMB_FUNCTION_
Vector19C:
#endif
#if CORTEX_NUM_VECTORS > 88
        _ASM_THUMB_FUNCTION_
Vector1A0:
        _ASM_THUMB_FUNCTION_
Vector1A4:
        _ASM_THUMB_FUNCTION_
Vector1A8:
        _ASM_THUMB_FUNCTION_
Vector1AC:
        _ASM_THUMB_FUNCTION_
Vector1B0:
        _ASM_THUMB_FUNCTION_
Vector1B4:
        _ASM_THUMB_FUNCTION_
Vector1B8:
        _ASM_THUMB_FUNCTION_
Vector1BC:
#endif
#if CORTEX_NUM_VECTORS > 96
        _ASM_THUMB_FUNCTION_
Vector1C0:
        _ASM_THUMB_FUNCTION_
Vector1C4:
        _ASM_THUMB_FUNCTION_
Vector1C8:
        _ASM_THUMB_FUNCTION_
Vector1CC:
        _ASM_THUMB_FUNCTION_
Vector1D0:
        _ASM_THUMB_FUNCTION_
Vector1D4:
        _ASM_THUMB_FUNCTION_
Vector1D8:
        _ASM_THUMB_FUNCTION_
Vector1DC:
#endif
#if CORTEX_NUM_VECTORS > 104
        _ASM_THUMB_FUNCTION_
Vector1E0:
        _ASM_THUMB_FUNCTION_
Vector1E4:
        _ASM_THUMB_FUNCTION_
Vector1E8:
        _ASM_THUMB_FUNCTION_
Vector1EC:
        _ASM_THUMB_FUNCTION_
Vector1F0:
        _ASM_THUMB_FUNCTION_
Vector1F4:
        _ASM_THUMB_FUNCTION_
Vector1F8:
        _ASM_THUMB_FUNCTION_
Vector1FC:
#endif
#if CORTEX_NUM_VECTORS > 112
        _ASM_THUMB_FUNCTION_
Vector200:
        _ASM_THUMB_FUNCTION_
Vector204:
        _ASM_THUMB_FUNCTION_
Vector208:
        _ASM_THUMB_FUNCTION_
Vector20C:
        _ASM_THUMB_FUNCTION_
Vector210:
        _ASM_THUMB_FUNCTION_
Vector214:
        _ASM_THUMB_FUNCTION_
Vector218:
        _ASM_THUMB_FUNCTION_
Vector21C:
#endif
#if CORTEX_NUM_VECTORS > 120
        _ASM_THUMB_FUNCTION_
Vector220:
        _ASM_THUMB_FUNCTION_
Vector224:
        _ASM_THUMB_FUNCTION_
Vector228:
        _ASM_THUMB_FUNCTION_
Vector22C:
        _ASM_THUMB_FUNCTION_
Vector230:
        _ASM_THUMB_FUNCTION_
Vector234:
        _ASM_THUMB_FUNCTION_
Vector238:
        _ASM_THUMB_FUNCTION_
Vector23C:
#endif
#if CORTEX_NUM_VECTORS > 128
        _ASM_THUMB_FUNCTION_
Vector240:
        _ASM_THUMB_FUNCTION_
Vector244:
        _ASM_THUMB_FUNCTION_
Vector248:
        _ASM_THUMB_FUNCTION_
Vector24C:
        _ASM_THUMB_FUNCTION_
Vector250:
        _ASM_THUMB_FUNCTION_
Vector254:
        _ASM_THUMB_FUNCTION_
Vector258:
        _ASM_THUMB_FUNCTION_
Vector25C:
#endif
#if CORTEX_NUM_VECTORS > 136
        _ASM_THUMB_FUNCTION_
Vector260:
        _ASM_THUMB_FUNCTION_
Vector264:
        _ASM_THUMB_FUNCTION_
Vector268:
        _ASM_THUMB_FUNCTION_
Vector26C:
        _ASM_THUMB_FUNCTION_
Vector270:
        _ASM_THUMB_FUNCTION_
Vector274:
        _ASM_THUMB_FUNCTION_
Vector278:
        _ASM_THUMB_FUNCTION_
Vector27C:
#endif
#if CORTEX_NUM_VECTORS > 144
        _ASM_THUMB_FUNCTION_
Vector280:
        _ASM_THUMB_FUNCTION_
Vector284:
        _ASM_THUMB_FUNCTION_
Vector288:
        _ASM_THUMB_FUNCTION_
Vector28C:
        _ASM_THUMB_FUNCTION_
Vector290:
        _ASM_THUMB_FUNCTION_
Vector294:
        _ASM_THUMB_FUNCTION_
Vector298:
        _ASM_THUMB_FUNCTION_
Vector29C:
#endif
#if CORTEX_NUM_VECTORS > 152
        _ASM_THUMB_FUNCTION_
Vector2A0:
        _ASM_THUMB_FUNCTION_
Vector2A4:
        _ASM_THUMB_FUNCTION_
Vector2A8:
        _ASM_THUMB_FUNCTION_
Vector2AC:
        _ASM_THUMB_FUNCTION_
Vector2B0:
        _ASM_THUMB_FUNCTION_
Vector2B4:
        _ASM_THUMB_FUNCTION_
Vector2B8:
        _ASM_THUMB_FUNCTION_
Vector2BC:
#endif
#if CORTEX_NUM_VECTORS > 160
        _ASM_THUMB_FUNCTION_
Vector2C0:
        _ASM_THUMB_FUNCTION_
Vector2C4:
        _ASM_THUMB_FUNCTION_
Vector2C8:
        _ASM_THUMB_FUNCTION_
Vector2CC:
        _ASM_THUMB_FUNCTION_
Vector2D0:
        _ASM_THUMB_FUNCTION_
Vector2D4:
        _ASM_THUMB_FUNCTION_
Vector2D8:
        _ASM_THUMB_FUNCTION_
Vector2DC:
#endif
#if CORTEX_NUM_VECTORS > 168
        _ASM_THUMB_FUNCTION_
Vector2E0:
        _ASM_THUMB_FUNCTION_
Vector2E4:
        _ASM_THUMB_FUNCTION_
Vector2E8:
        _ASM_THUMB_FUNCTION_
Vector2EC:
        _ASM_THUMB_FUNCTION_
Vector2F0:
        _ASM_THUMB_FUNCTION_
Vector2F4:
        _ASM_THUMB_FUNCTION_
Vector2F8:
        _ASM_THUMB_FUNCTION_
Vector2FC:
#endif
#if CORTEX_NUM_VECTORS > 176
        _ASM_THUMB_FUNCTION_
Vector300:
        _ASM_THUMB_FUNCTION_
Vector304:
        _ASM_THUMB_FUNCTION_
Vector308:
        _ASM_THUMB_FUNCTION_
Vector30C:
        _ASM_THUMB_FUNCTION_
Vector310:
        _ASM_THUMB_FUNCTION_
Vector314:
        _ASM_THUMB_FUNCTION_
Vector318:
        _ASM_THUMB_FUNCTION_
Vector31C:
#endif
#if CORTEX_NUM_VECTORS > 184
        _ASM_THUMB_FUNCTION_
Vector320:
        _ASM_THUMB_FUNCTION_
Vector324:
        _ASM_THUMB_FUNCTION_
Vector328:
        _ASM_THUMB_FUNCTION_
Vector32C:
        _ASM_THUMB_FUNCTION_
Vector330:
        _ASM_THUMB_FUNCTION_
Vector334:
        _ASM_THUMB_FUNCTION_
Vector338:
        _ASM_THUMB_FUNCTION_
Vector33C:
#endif
#if CORTEX_NUM_VECTORS > 192
        _ASM_THUMB_FUNCTION_
Vector340:
        _ASM_THUMB_FUNCTION_
Vector344:
        _ASM_THUMB_FUNCTION_
Vector348:
        _ASM_THUMB_FUNCTION_
Vector34C:
        _ASM_THUMB_FUNCTION_
Vector350:
        _ASM_THUMB_FUNCTION_
Vector354:
        _ASM_THUMB_FUNCTION_
Vector358:
        _ASM_THUMB_FUNCTION_
Vector35C:
#endif
#if CORTEX_NUM_VECTORS > 200
        _ASM_THUMB_FUNCTION_
Vector360:
        _ASM_THUMB_FUNCTION_
Vector364:
        _ASM_THUMB_FUNCTION_
Vector368:
        _ASM_THUMB_FUNCTION_
Vector36C:
        _ASM_THUMB_FUNCTION_
Vector370:
        _ASM_THUMB_FUNCTION_
Vector374:
        _ASM_THUMB_FUNCTION_
Vector378:
        _ASM_THUMB_FUNCTION_
Vector37C:
#endif
#if CORTEX_NUM_VECTORS > 208
        _ASM_THUMB_FUNCTION_
Vector380:
        _ASM_THUMB_FUNCTION_
Vector384:
        _ASM_THUMB_FUNCTION_
Vector388:
        _ASM_THUMB_FUNCTION_
Vector38C:
        _ASM_THUMB_FUNCTION_
Vector390:
        _ASM_THUMB_FUNCTION_
Vector394:
        _ASM_THUMB_FUNCTION_
Vector398:
        _ASM_THUMB_FUNCTION_
Vector39C:
#endif
#if CORTEX_NUM_VECTORS > 216
        _ASM_THUMB_FUNCTION_
Vector3A0:
        _ASM_THUMB_FUNCTION_
Vector3A4:
        _ASM_THUMB_FUNCTION_
Vector3A8:
        _ASM_THUMB_FUNCTION_
Vector3AC:
        _ASM_THUMB_FUNCTION_
Vector3B0:
        _ASM_THUMB_FUNCTION_
Vector3B4:
        _ASM_THUMB_FUNCTION_
Vector3B8:
        _ASM_THUMB_FUNCTION_
Vector3BC:
#endif
#if CORTEX_NUM_VECTORS > 224
        _ASM_THUMB_FUNCTION_
Vector3C0:
        _ASM_THUMB_FUNCTION_
Vector3C4:
        _ASM_THUMB_FUNCTION_
Vector3C8:
        _ASM_THUMB_FUNCTION_
Vector3CC:
        _ASM_THUMB_FUNCTION_
Vector3D0:
        _ASM_THUMB_FUNCTION_
Vector3D4:
        _ASM_THUMB_FUNCTION_
Vector3D8:
        _ASM_THUMB_FUNCTION_
Vector3DC:
#endif
#if CORTEX_NUM_VECTORS > 232
        _ASM_THUMB_FUNCTION_
Vector3E0:
        _ASM_THUMB_FUNCTION_
Vector3E4:
        _ASM_THUMB_FUNCTION_
Vector3E8:
        _ASM_THUMB_FUNCTION_
Vector3EC:
        _ASM_THUMB_FUNCTION_
Vector3F0:
        _ASM_THUMB_FUNCTION_
Vector3F4:
        _ASM_THUMB_FUNCTION_
Vector3F8:
        _ASM_THUMB_FUNCTION_
Vector3FC:
#endif
        bl          _unhandled_exception

        _ASM_THUMB_FUNCTION_
        .weak       _unhandled_exception
_unhandled_exception:
.stay:
        b           .stay

#endif /* !defined(__DOXYGEN__) */

/** @} */
