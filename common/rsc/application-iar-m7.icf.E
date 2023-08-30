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

/* Memory Regions */
#include <memory_map.icf>

define symbol __intvec_start__        = INTVEC_START;
define symbol __reset_handler_start__ = RESET_HANDLER_START + 0x400;
define symbol __region_rom_start__    = ROM_START;
define symbol __region_rom_end__      = ROM_END;
define symbol __region_ram_start__    = RAM_START;
define symbol __region_ram_end__      = RAM_END;
define symbol __region_itcm_start__   = ITCM_START;
define symbol __region_itcm_end__     = ITCM_END;
define symbol __region_dtcm_start__   = DTCM_START;
define symbol __region_dtcm_end__     = DTCM_END;

/*-Sizes-*/
define symbol __size_irqstack__ = MAIN_STACK_SIZE;    /* Size of the IRQ Stack (Main Stack).*/
define symbol __size_cstack__   = PROCESS_STACK_SIZE; /* Size of the Process Stack.*/
define symbol __size_heap__     = HEAP_SIZE;          /* Size of HEAP. */

define memory mem with size = 4G;
define region ROM_region   = mem:[from __region_rom_start__  to __region_rom_end__];
define region RAM_region   = mem:[from __region_ram_start__  to __region_ram_end__];
define region ITCM_region  = mem:[from __region_itcm_start__ to __region_itcm_end__];
define region DTCM_region  = mem:[from __region_dtcm_start__ to __region_dtcm_end__];

define block IRQSTACK   with alignment = 8,  size = __size_irqstack__, fixed order { };
define block CSTACK     with alignment = 8,  size = __size_cstack__,   fixed order { section CSTACK };
define block DATABSS    with alignment = 8,                            fixed order { readwrite, zeroinit };
define block HEAP       with alignment = 8,  size = __size_heap__,     fixed order { section HEAP };
define block ITCM                                                                  { section .itcm };
define block ITCM_INIT                                                             { section .itcm_init };
define block DTCM                                                                  { section .dtcm };
define block DTCM_INIT                                                             { section .dtcm_init };

define block RAM_BLOCKS with fixed order { block IRQSTACK, block CSTACK, block DATABSS, block HEAP };

initialize by copy { readwrite };
do not initialize { section .noinit };
initialize manually { section .itcm };
initialize manually { section .dtcm };

keep { section .intvec };
keep { section .reset_handler };

place at address mem:__intvec_start__ { readonly section .intvec };
place at address mem:__reset_handler_start__ { readonly section .reset_handler };

place in EMBED_REGION  { readonly };
place in EMBED_REGION  { block ITCM_INIT };
place in EMBED_REGION  { block DTCM_INIT };
place in RAM_region  { block RAM_BLOCKS };
place in ITCM_region { block ITCM }; 
place in DTCM_region { block DTCM };

define exported symbol __itcm_start__ = __region_itcm_start__;
define exported symbol __itcm_len__   = __region_itcm_end__ - __region_itcm_start__ + 1;
define exported symbol __itcm_end__   = __region_itcm_end__ + 1;

define exported symbol __dtcm_start__ = __region_dtcm_start__;
define exported symbol __dtcm_len__   = __region_dtcm_end__ - __region_dtcm_start__ + 1;
define exported symbol __dtcm_end__   = __region_dtcm_end__ + 1;
