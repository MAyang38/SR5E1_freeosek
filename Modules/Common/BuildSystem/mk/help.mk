################################################################################
# StellarESDK help target.
################################################################################

help:
	@echo ' '
	@echo "Targets:"
	@echo "  all                              build everything"
	@echo "  clean                            remove generated files"
	@echo "  purge                            remove build directory for device/board"
	@echo "  purge_all                        remove build directory"
	@echo "  misra                            perform Misra check"
	@echo "  clang                            perform coding style check"
	@echo ' '
	@echo "Build system configuration options:"
	@echo "  TARGET_BUILD                     set it to 'Release' or 'Debug' (default)"
	@echo "  VERBOSE                          set to '1' to display executed commands, '0' (default) for silent builds"
	@echo "  TOOLCHAIN                        set it to 'ARM' (default) to use GNU ARM Cross C Compiler"
	@echo "                                   set it to 'HIGHTEC'       to use Hightec Cross C Compiler"
	@echo "                                   set it to 'GHS'           to use Green Hills Cross C Compiler"
	@echo "                                   set it to 'IAR'           to use IAR Cross C Compiler"
	@echo ' '
	@echo "Select modules to build:"
	@echo "  BUILD_BOOT                       set to '1' to build Boot module, '0' to exclude it from build"
	@echo "  BUILD_PLATFORM_BOARD             set to '1' to build Board module, '0' to exclude it from build"
	@echo "  BUILD_PLATFORM_CLOCK             set to '1' to build Clock module, '0' to exclude it from build"
	@echo "  BUILD_PLATFORM_CMSIS             set to '1' to build CMSIS module, '0' to exclude it from build"
	@echo "  BUILD_PLATFORM_IRQ               set to '1' to build IRQ module, '0' to exclude it from build"
	@echo "  BUILD_PLATFORM_MCU               set to '1' to build MCU module, '0' to exclude it from build"
	@echo "  BUILD_DRIVERS_CAN                set to '1' to build CAN driver, '0' to exclude it from build"
	@echo "  BUILD_DRIVERS_CEM                set to '1' to build CEM driver, '0' to exclude it from build"
	@echo "  BUILD_DRIVERS_COMP               set to '1' to build COMP driver, '0' to exclude it from build"
	@echo "  BUILD_DRIVERS_CORDIC             set to '1' to build CORDIC driver, '0' to exclude it from build"
	@echo "  BUILD_DRIVERS_DAC                set to '1' to build DAC driver, '0' to exclude it from build"
	@echo "  BUILD_DRIVERS_DMA                set to '1' to build DMA driver, '0' to exclude it from build"
	@echo "  BUILD_DRIVERS_DWT                set to '1' to build DWT driver, '0' to exclude it from build"
	@echo "  BUILD_DRIVERS_EED                set to '1' to build EED driver, '0' to exclude it from build"
	@echo "  BUILD_DRIVERS_EXTI               set to '1' to build EXTI driver, '0' to exclude it from build"
	@echo "  BUILD_DRIVERS_FCCU               set to '1' to build FCCU driver, '0' to exclude it from build"
	@echo "  BUILD_DRIVERS_FLASH              set to '1' to build FLASH driver, '0' to exclude it from build"
	@echo "  BUILD_DRIVERS_GPIO               set to '1' to build GPIO driver, '0' to exclude it from build"
	@echo "  BUILD_DRIVERS_HRTIM              set to '1' to build HRTIM driver, '0' to exclude it from build"
	@echo "  BUILD_DRIVERS_HSEM               set to '1' to build HSEM driver, '0' to exclude it from build"
	@echo "  BUILD_DRIVERS_I2S                set to '1' to build I2S driver, '0' to exclude it from build"
	@echo "  BUILD_DRIVERS_ILI9341            set to '1' to build ILI9341 driver, '0' to exclude it from build"
	@echo "  BUILD_DRIVERS_IWDG               set to '1' to build IWDG driver, '0' to exclude it from build"
	@echo "  BUILD_DRIVERS_MPU                set to '1' to build MPU driver, '0' to exclude it from build"
	@echo "  BUILD_DRIVERS_SARADC             set to '1' to build SARADC driver, '0' to exclude it from build"
	@echo "  BUILD_DRIVERS_SDADC              set to '1' to build SDADC driver, '0' to exclude it from build"
	@echo "  BUILD_DRIVERS_SPI                set to '1' to build SPI driver, '0' to exclude it from build"
	@echo "  BUILD_DRIVERS_SYSTICK            set to '1' to build SYSTICK driver, '0' to exclude it from build"
	@echo "  BUILD_DRIVERS_TIM                set to '1' to build TIM driver, '0' to exclude it from build"
	@echo "  BUILD_DRIVERS_UART               set to '1' to build UART driver, '0' to exclude it from build"
	@echo "  BUILD_DRIVERS_WWDG               set to '1' to build WWDG driver, '0' to exclude it from build"
	@echo "  BUILD_OS_OSAL                    set to '1' to build OSAL module, '0' to exclude it from build"
	@echo "  BUILD_RUNTIME_IO                 set to '1' to build RuntimeIO module, '0' to exclude it from build"
	@echo ' '
	@echo "Select image format:"
	@echo "  GENERATE_BIN_IMAGE               set to '1' to generate binary image, '0' do not generate it"
	@echo "  GENERATE_HEX_IMAGE               set to '1' to generate Intel-hex image, '0' do not generate it"
	@echo "  GENERATE_SREC_IMAGE              set to '1' to generate Motorola S-rec image, '0' do not generate it"
	@echo ' '
	@echo "Set application name:"
	@echo "  APP_NAME                         set it to the application name"
	@echo "  LINKER_SCRIPT_NAME               application linker script name (automatically generated)"
	@echo "  LINKER_SCRIPT_INCS               application linker script includes"
	@echo "  LINKER_SCRIPT_DEFS               application linker script defines"
	@echo ' '
	@echo "Set Device name:"
	@echo "  CONFIG_DEVICE                    set device name: sr5e1 (default)"
	@echo ' '
	@echo "Set Board name:"
	@echo "  CONFIG_BOARD                     set board name: evbe7000p (default), evbe7000s"
	@echo ' '
	@echo "Set core:"
	@echo "  CONFIG_TARGET_CORE               set target core: core1 (default), core2"
	@echo ' '
	@echo "Set boot memory:"
	@echo "  CONFIG_TARGET_MEMORY             set target memory: ram (default), nvm (or flash)"
	@echo ' '
	@echo "Set FPU configuration:"
	@echo "  CONFIG_FPU                       set FPU configuration: hard (default), softfp, no"
	@echo ' '
	@echo "Set Main Stack size:"
	@echo "  MAIN_STACK_SIZE                  set Main Stack size: 4k (default)"
	@echo ' '
	@echo "Set Main Stack size:"
	@echo "  PROCESS_STACK_SIZE               set Process Stack size: 4k (default)"
	@echo ' '
	@echo "Set Heap size:"
	@echo "  HEAP_SIZE                        set Heap size (only for IAR): 1k (default)"
	@echo ' '
	@echo "Set application option:"
	@echo "  C_SRCS                           list of 'C' sources"
	@echo "  A_SRCS                           list of Assembly sources"
	@echo "  C_INCS                           list of 'C' includes"
	@echo "  A_INCS                           list of Assembly includes"
	@echo "  C_DEFS                           list of 'C' defines"
	@echo "  A_DEFS                           list of Assembly defines"
	@echo "  C_OPTS                           list of additional 'C' options"
	@echo "  A_OPTS                           list of additional Assembly options"
	@echo ' '
	@echo "clang options:"
	@echo "  CLANG_OPTS                       Override default clang option (default: '-i')"
	@echo "                                     --dry-run : do not actually make the formatting changes."
	@echo "                                     --verbose : shows the list of processed files."
	@echo ' '
	@echo "misra options:"
	@echo "  MISRA_MODULES                    set to module directory name to check a sigle Module. (ex. MISRA_MODULES=OS)"
