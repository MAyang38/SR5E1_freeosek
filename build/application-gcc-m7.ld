MEMORY
{

    cflash1 (rx) : org = 0x08000000, len = 960k
    cflash2 (rx) : org = 0x080F0000, len = 960k
    dflash (rx) : org = 0x08F00000, len = 64k


    sram1 (wx) : org = 0x24000000, len = 128k
    sram2 (wx) : org = 0x24020000, len = 128k


    itcm1 (wx) : org = 0x5A000000, len = 32k
    itcm2 (wx) : org = 0x5A040000, len = 32k
    dtcm1 (wx) : org = 0x5C000000, len = 64k
    dtcm2 (wx) : org = 0x5C040000, len = 64k


    core1_nvm (rx) : org = 0x08000000, len = 960k
    core2_nvm (rx) : org = 0x080F0000, len = 960k


    core1_ram (wx) : org = 0x24000000, len = 128k
    core2_ram (wx) : org = 0x24020000, len = 128k


    core1_itcm_dir (wx) : org = 0x00000000, len = 32k
    core1_itcm_ind (wx) : org = 0x5A000000, len = 32k
    core1_dtcm_dir (wx) : org = 0x20000000, len = 64k
    core1_dtcm_ind (wx) : org = 0x5C000000, len = 64k
    core2_itcm_dir (wx) : org = 0x00000000, len = 32k
    core2_itcm_ind (wx) : org = 0x5A040000, len = 32k
    core2_dtcm_dir (wx) : org = 0x20000000, len = 64k
    core2_dtcm_ind (wx) : org = 0x5C040000, len = 64k
}


ENTRY(Reset_Handler)


SECTIONS
{
    startup : ALIGN(16) SUBALIGN(1024)
    {
        KEEP(*(.vectors))
        KEEP(*(.reset_handler))
    } > core1_nvm


    constructors : ALIGN(4) SUBALIGN(4)
    {
        PROVIDE(__init_array_start = .);
        KEEP(*(SORT(.init_array.*)))
        KEEP(*(.init_array))
        PROVIDE(__init_array_end = .);
    } > core1_nvm


    destructors : ALIGN(4) SUBALIGN(4)
    {
        PROVIDE(__fini_array_start = .);
        KEEP(*(.fini_array))
        KEEP(*(SORT(.fini_array.*)))
        PROVIDE(__fini_array_end = .);
    } > core1_nvm


    .text : ALIGN(16) SUBALIGN(16)
    {
        *(.text)
        *(.text.*)
        *(.rodata)
        *(.rodata.*)
        *(.glue_7t)
        *(.glue_7)
        *(.gcc*)
    } > core1_nvm


    .ARM.extab :
    {
        *(.ARM.extab* .gnu.linkonce.armextab.*)
    } > core1_nvm


    .ARM.exidx :
    {
        PROVIDE(__exidx_start = .);
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
        PROVIDE(__exidx_end = .);
    } > core1_nvm


    .eh_frame_hdr :
    {
        *(.eh_frame_hdr)
    } > core1_nvm


    .eh_frame : ONLY_IF_RO
    {
        *(.eh_frame)
    } > core1_nvm


    .itcm ORIGIN(core1_itcm_dir) : ALIGN(16)
    {
        __itcm__ = . ;
    } > core1_itcm_dir AT> core1_nvm
    __itcm_start__ = ORIGIN(core1_itcm_dir);
    __itcm_len__ = LENGTH(core1_itcm_dir);
    __itcm_end__ = __itcm_start__ + __itcm_len__;
    __itcm_size__ = SIZEOF(.itcm);
    __itcm_load__ = LOADADDR(.itcm);


    .dtcm ORIGIN(core1_dtcm_dir) : ALIGN(4)
    {
        __dtcm__ = . ;
    } > core1_dtcm_dir AT> core1_nvm
    __dtcm_start__ = ORIGIN(core1_dtcm_dir);
    __dtcm_len__ = LENGTH(core1_dtcm_dir);
    __dtcm_end__ = __dtcm_start__ + __dtcm_len__;
    __dtcm_size__ = SIZEOF(.dtcm);
    __dtcm_load__ = LOADADDR(.dtcm);


    .data ORIGIN(core1_ram) : ALIGN(4)
    {
        . = ALIGN(4);
        PROVIDE(__data_start__ = .);
        *(.data)
        *(.data.*)
        *(.gnu.linkonce.d.*)
        PROVIDE(__data_end__ = .);
    } > core1_ram AT> core1_nvm
    __data_size__ = SIZEOF(.data);
    __data_load__ = LOADADDR(.data);


    .bss :
    {
        . = ALIGN(8);
        PROVIDE(__bss_start__ = .);
        *(.bss)
        *(.bss.*)
        *(.gnu.linkonce.b.*)
        *(COMMON)
        PROVIDE(__bss_end__ = .);
    } > core1_ram


    .mstack (NOLOAD) :
    {
        . = ALIGN(8);
        __main_stack_base__ = .;
        . += 4k;
        . = ALIGN(8);
        __main_stack_end__ = .;
    } > core1_ram


    .pstack (NOLOAD) :
    {
        __process_stack_base__ = .;
        __main_thread_stack_base__ = .;
        . += 4k;
        . = ALIGN(8);
        __process_stack_end__ = .;
        __main_thread_stack_end__ = .;
    } > core1_ram


    . = ALIGN(16);
    __heap_base__ = .;
    __heap_end__ = ORIGIN(core1_ram) + LENGTH(core1_ram);

    end = __heap_end__;


    __mem_start__ = ORIGIN(core1_ram);
    __mem_end__ = __heap_end__;
}
