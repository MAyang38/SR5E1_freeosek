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


ENTRY(Reset_Handler)


SECTIONS
{
    startup : ALIGN(16) SUBALIGN(1024)
    {
        KEEP(*(.vectors))
        KEEP(*(.reset_handler))
    } > EMBED_NVM


    constructors : ALIGN(4) SUBALIGN(4)
    {
        PROVIDE(__init_array_start = .);
        KEEP(*(SORT(.init_array.*)))
        KEEP(*(.init_array))
        PROVIDE(__init_array_end = .);
    } > EMBED_NVM


    destructors : ALIGN(4) SUBALIGN(4)
    {
        PROVIDE(__fini_array_start = .);
        KEEP(*(.fini_array))
        KEEP(*(SORT(.fini_array.*)))
        PROVIDE(__fini_array_end = .);
    } > EMBED_NVM


    .text : ALIGN(16) SUBALIGN(16)
    {
        *(.text)
        *(.text.*)
        *(.rodata)
        *(.rodata.*)
        *(.glue_7t)
        *(.glue_7)
        *(.gcc*)
    } > EMBED_NVM


    .ARM.extab :
    {
        *(.ARM.extab* .gnu.linkonce.armextab.*)
    } > EMBED_NVM


    .ARM.exidx :
    {
        PROVIDE(__exidx_start = .);
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
        PROVIDE(__exidx_end = .);
    } > EMBED_NVM


    .eh_frame_hdr :
    {
        *(.eh_frame_hdr)
    } > EMBED_NVM


    .eh_frame : ONLY_IF_RO
    {
        *(.eh_frame)
    } > EMBED_NVM


    .itcm ORIGIN(EMBED_ITCM) : ALIGN(16)
    {
        __itcm__ = . ;
    } > EMBED_ITCM AT> EMBED_NVM
    __itcm_start__ = ORIGIN(EMBED_ITCM);
    __itcm_len__   = LENGTH(EMBED_ITCM);
    __itcm_end__   = __itcm_start__ + __itcm_len__;
    __itcm_size__  = SIZEOF(.itcm);
    __itcm_load__  = LOADADDR(.itcm);


    .dtcm ORIGIN(EMBED_DTCM) : ALIGN(4)
    {
        __dtcm__ = . ;
    } > EMBED_DTCM AT> EMBED_NVM
    __dtcm_start__ = ORIGIN(EMBED_DTCM);
    __dtcm_len__   = LENGTH(EMBED_DTCM);
    __dtcm_end__   = __dtcm_start__ + __dtcm_len__;
    __dtcm_size__  = SIZEOF(.dtcm);
    __dtcm_load__  = LOADADDR(.dtcm);


    .data DATA_SEC_ORIGIN : ALIGN(4)
    {
        . = ALIGN(4);
        PROVIDE(__data_start__ = .);
        *(.data)
        *(.data.*)
        *(.gnu.linkonce.d.*)
        PROVIDE(__data_end__ = .);
    } > EMBED_RAM DATA_SEC_RELOC_AT DATA_SEC_RELOC
    __data_size__ = SIZEOF(.data);
    __data_load__ = LOADADDR(.data);


    .bss (NOLOAD) :
    {
        . = ALIGN(8);
        PROVIDE(__bss_start__ = .);
        *(.bss)
        *(.bss.*)
        *(.gnu.linkonce.b.*)
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
    __heap_end__  = ORIGIN(EMBED_RAM) + LENGTH(EMBED_RAM);


/* The following variable are used to clean-up the memory at boot time.
   See ram initialization in crt0.s.*/
    __mem_start__ = MEM_START;
    __mem_end__   = __heap_end__;

/* Others -------------------------------------------------------------- */

    .ARM.exidx      : { *(.ARM.exidx*) } > ARM_EXIDX
    .ARM.attributes : { *(.ARM.attributes) }

    /* Internal LLD tool sections */
    .rel           : { *(.rel*) }
    .plt           : { *(.plt*) }
    .eh_frame      : { *(.eh_frame) }
    .symtab        : { *(.symtab) }
    .symtab_shndxr : { *(.symtab_shndxr) }
    .shstrtab      : { *(.shstrtab) }
    .strtab        : { *(.strtab) }

    /* GNU sections */
    .note.GNU : { *(.note.GNU*) }
    .glue     : { *(.glue*) }
    .vfp11    : { *(.vfp11*) }
    .v4_bx    : { *(.v4_bx) }
    .iplt     : { *(.iplt) }
    .igot.plt : { *(.igot.plt) }

    /* Debug sections */
    .debug_abbrev   : { *(.debug_abbrev) }
    .debug_info     : { *(.debug_info) }
    .debug_ranges   : { *(.debug_ranges) }
    .debug_macinfo  : { *(.debug_macinfo) }
    .debug_pubnames : { *(.debug_pubnames) }
    .debug_pubtypes : { *(.debug_pubtypes) }
    .debug_frame    : { *(.debug_frame) }
    .debug_line     : { *(.debug_line) }
    .debug_str      : { *(.debug_str) }
    .debug_aranges  : { *(.debug_aranges) }
    .comment        : { *(.comment) }

    /DISCARD/ :
    {
        *(.ARM.exidx*)
        *(.ARM.attributes*)
        *(.comment)
        *(.got*)
    }
}
