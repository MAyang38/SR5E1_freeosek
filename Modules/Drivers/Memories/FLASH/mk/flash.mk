################################################################################
# StellarESDK module makefile.
################################################################################

# Currently FLASH driver only supports GCC compiler
ifneq ($(TOOLCHAIN), ARM)
$(error FLASH driver does not support this compiler)
endif

#
# C sources
#
MODULE_C_SRCS := \
	src/flash.c

#
# Assembly sources
#
ifeq ($(SSD_SRC_TARGET), Release_carray)
MODULE_A_SRCS += \
	ssd/$(CONFIG_DEVICE)/$(TOOLCHAIN)/$(SSD_INSTRUCTION_SET)/c-array_driver/GetLock.S \
	ssd/$(CONFIG_DEVICE)/$(TOOLCHAIN)/$(SSD_INSTRUCTION_SET)/c-array_driver/SetLock.S \
	ssd/$(CONFIG_DEVICE)/$(TOOLCHAIN)/$(SSD_INSTRUCTION_SET)/c-array_driver/FlashCheckStatus.S \
	ssd/$(CONFIG_DEVICE)/$(TOOLCHAIN)/$(SSD_INSTRUCTION_SET)/c-array_driver/FlashProgram.S \
	ssd/$(CONFIG_DEVICE)/$(TOOLCHAIN)/$(SSD_INSTRUCTION_SET)/c-array_driver/ProgramVerify.S \
	ssd/$(CONFIG_DEVICE)/$(TOOLCHAIN)/$(SSD_INSTRUCTION_SET)/c-array_driver/FlashInit.S \
	ssd/$(CONFIG_DEVICE)/$(TOOLCHAIN)/$(SSD_INSTRUCTION_SET)/c-array_driver/FlashErase.S \
	ssd/$(CONFIG_DEVICE)/$(TOOLCHAIN)/$(SSD_INSTRUCTION_SET)/c-array_driver/BlankCheck.S
else
MODULE_A_SRCS :=
endif

#
# C include directories
#
MODULE_C_INCS := \
	include \
	ssd/$(CONFIG_DEVICE)/inc

#
# Assembly include directories
#
MODULE_A_INCS :=

#
# Linker script include directories
#
MODULE_LS_INCS :=

#
# C defines
#
MODULE_C_DEFS := \
	BUILD_DRIVERS_FLASH

ifeq ($(SSD_SRC_TARGET), Release_lib)
MODULE_C_DEFS += _SSD_SRC_RELEASE_LIB_
endif

ifeq ($(SSD_SRC_TARGET), Release_carray)
MODULE_C_DEFS += _SSD_SRC_RELEASE_CARRAY_
endif

#
# Libraries
#
ifeq ($(SSD_SRC_TARGET), Release_lib)
LIBS := $(STELLAR_E_SDK_ROOT_DIR)/$(DRIVERS_FLASH_PATH)/ssd/$(CONFIG_DEVICE)/$(TOOLCHAIN)/$(SSD_INSTRUCTION_SET)/driver_lib/SR5E1_C55_SSD.a
endif

#
# Assembly defines
#
MODULE_A_DEFS :=

#
# C compiler options
#
MODULE_C_OPTS :=

#
# Assembly compiler options
#
MODULE_A_OPTS := 

pre-build::
	-$(AT)$(RM) $(TARGET_BUILD_DIR)/$(DRIVERS_FLASH_PATH)/src/flash.o
