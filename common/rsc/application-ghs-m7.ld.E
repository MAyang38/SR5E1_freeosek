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

/* Memory map */
#include <memory_map.ld>


OPTION ("-e=Reset_Handler")


SECTIONS
{
    startup ALIGN(16) :
    {
        *(.vectors)
    } > EMBED_NVM


    reset ALIGN(1024) :
    {
        *(.reset_handler)
    } > EMBED_NVM


    constructors ALIGN(4) :
    {
        PROVIDE(__init_array_start = .);
        "*(SORT(.init_array.*))"
        *(.init_array)
        PROVIDE(__init_array_end = .);
    } > EMBED_NVM


    destructors ALIGN(4) :
    {
        PROVIDE(__fini_array_start = .);
        *(.fini_array)
        "*(SORT(.fini_array.*))"
        PROVIDE(__fini_array_end = .);
    } > EMBED_NVM


    .text ALIGN(16) :
    {
        *(.text)
        "*(.text.*)"
        *(.rodata)
        "*(.rodata.*)"
        *(.glue_7t)
        *(.glue_7)
        "*(.gcc*)"
        "*(.syscall)"
        "*(.ghs.linkonce.t.*)"
    } > EMBED_NVM


    .ARM.extab :
    {
        "*(.ARM.extab*)"
    } > EMBED_NVM


    .ARM.exidx :
    {
        PROVIDE(__exidx_start = .);
        "*(.ARM.exidx*)"
        PROVIDE(__exidx_end = .);
    } > EMBED_NVM


    .eh_frame_hdr :
    {
        *(.eh_frame_hdr)
    } > EMBED_NVM


    .eh_frame :
    {
        *(.eh_frame)
    } > EMBED_NVM


    .itcm ALIGN(16) :
    {
        __itcm__ = . ;
    } > EMBED_ITCM
    .ROM.itcm  ROM_NOCOPY(.itcm) : > EMBED_NVM
    __itcm_start__ = ADDR(EMBED_ITCM);
    __itcm_len__   = SIZEOF(EMBED_ITCM);
    __itcm_end__   = __itcm_start__ + __itcm_len__;
    __itcm_size__  = SIZEOF(.itcm);
    __itcm_load__  = ADDR(.ROM.itcm);


    .dtcm ALIGN(4):
    {
        __dtcm__ = . ;
    } > EMBED_DTCM
    .ROM.dtcm  ROM_NOCOPY(.dtcm) : > EMBED_NVM
    __dtcm_start__ = ADDR(EMBED_DTCM);
    __dtcm_len__   = SIZEOF(EMBED_DTCM);
    __dtcm_end__   = __dtcm_start__ + __dtcm_len__;
    __dtcm_size__  = SIZEOF(.dtcm);
    __dtcm_load__  = ADDR(.ROM.dtcm);


    .data ALIGN(4):
    {
        . = ALIGN(4);
        PROVIDE(__data_start__ = .);
        *(.data)
        "*(.data.*)"
        "*(.gnu.linkonce.d.*)"
        PROVIDE(__data_end__ = .);
    } > EMBED_RAM
    .ROM.data  ROM_NOCOPY(.data) : > EMBED_NVM
    __data_size__ = SIZEOF(.data);
    __data_load__ = ADDR(.ROM.data);


    .bss :
    {
        . = ALIGN(8);
        PROVIDE(__bss_start__ = .);
        *(.bss)
        "*(.bss.*)"
        "*(.gnu.linkonce.b.*)"
        *(COMMON)
        PROVIDE(__bss_end__ = .);
    } > EMBED_RAM


    .mstack (NOLOAD) :
    {
        . = ALIGN(8);
        __main_stack_base__ = .;
        . += MAIN_STACK_SIZE;
        . = ALIGN(8);
        __main_stack_end__ = .;
    } > EMBED_RAM


    .pstack (NOLOAD) :
    {
        __process_stack_base__ = .;
        __main_thread_stack_base__ = .;
        . += PROCESS_STACK_SIZE;
        . = ALIGN(8);
        __process_stack_end__ = .;
        __main_thread_stack_end__ = .;
    } > EMBED_RAM


    . = ALIGN(16);
    __heap_base__ = .;
    __heap_end__  = ADDR(EMBED_RAM) + SIZEOF(EMBED_RAM);


/* The following variable are used to clean-up the memory at boot time.
   See ram initialization in crt0.s.*/
    __mem_start__ = MEM_START;
    __mem_end__   = __heap_end__;
}
