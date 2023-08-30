################################################################################
# StellarESDK IAR toolchain makefile. Cortex-M7 oriented
################################################################################
ifeq ($(TOOLCHAIN), IAR)

ifeq ($(OS),Windows_NT)
STELLAR_E_SDK_TOOLCHAIN_PATH := C:/Program Files/IAR Systems/Embedded Workbench 9.0/arm/bin
else
UNAME_S := $(shell uname -s)
OS := Linux
ifeq ($(UNAME_S),Linux)
STELLAR_E_SDK_TOOLCHAIN_PATH :=
else
$(error $(UNAME_S) not supported yet)
endif
endif

TOOLCHAIN_ID := IAR C/C++ Compiler (M7)

# Assembler tool
AS := iasmarm

# Compiler tool
CC := iccarm

# C++ Compiler tool
CCC := iccarm

# Linker tool
LD := ilinkarm

# Binary Flash image tool
GENBIN := ielftool
BIN_OPTS := --bin

# Intel Hexadecimal Flash image tool
GENHEX := ielftool
HEX_OPTS := --ihex

# Motorola S-Record Flash image tool
GENSREC := ielftool
SREC_OPTS := --srec

OUT_OPTS :=

# Size tool
SIZE :=
SIZE_OPTS :=

# Optimization flag
ifeq ($(TARGET_BUILD),Release)
C_OPTS += -Ohs
else
ifeq ($(TARGET_BUILD),Debug)
C_OPTS += -On
else
$(error Wrong target build '$(TARGET_BUILD)')
endif
endif

# FPU flag
ifeq ($(CONFIG_FPU),hard)
C_OPTS += \
	--fpu=VFPv5_d16

A_OPTS += \
	--fpu VFPv5_d16
else
ifeq ($(CONFIG_FPU),softfp)
$(error Option softfp not supported)
else
ifeq ($(CONFIG_FPU),no)
C_OPTS += \
	--fpu=None

A_OPTS += \
	--fpu None
else
$(error Wrong FPU configuration '$(CONFIG_FPU)')
endif
endif
endif

TARGET_OPTS :=

C_OPTS += \
	--thumb \
	--cpu=Cortex-M7 \
	-e \
	--debug \
	--no_size_constraints \
	--use_c++_inline

A_OPTS += \
	--cpu Cortex-M7

L_OPTS += \
	--map "$(TARGET_BUILD_DIR)/$(APP_NAME).map" \
	--config "$(TARGET_BUILD_DIR)/$(LINKER_SCRIPT_NAME)" \
	--entry __reset_handler \
	--vfe \
	--text_out locale

LST_OPTS +=

LANG_OPTS +=

DEP_OPTS +=
endif