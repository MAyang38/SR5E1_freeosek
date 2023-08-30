################################################################################
# StellarESDK ARM toolchain makefile. Cortex-M7 oriented
################################################################################
ifeq ($(TOOLCHAIN), ARM)

ifeq ($(OS),Windows_NT)
STELLAR_E_SDK_TOOLCHAIN_PATH := $(STELLAR_E_SDK_PREFIX_PATH)/Tools/Toolchain/ARM/MINGW64_NT/10.3-2021.10/bin
else
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
OS := Linux
STELLAR_E_SDK_TOOLCHAIN_PATH := $(STELLAR_E_SDK_PREFIX_PATH)/Tools/Toolchain/ARM/x86_64-linux/10.3-2021.10/bin
else
ifeq ($(UNAME_S),Darwin)
OS := MAC
STELLAR_E_SDK_TOOLCHAIN_PATH := $(STELLAR_E_SDK_PREFIX_PATH)/Tools/Toolchain/ARM/MAC/10.3-2021.10/bin
else
$(error $(UNAME_S) not supported yet)
endif
endif
endif

TOOLCHAIN_ID := GNU ARM Cross C Compiler (M7)

# Compiler and linker tool
CC:= arm-none-eabi-gcc

# C++ Compiler
CCC := arm-none-eabi-g++

# Binary Flash image tool
GENBIN := arm-none-eabi-objcopy
BIN_OPTS := -O binary
BIN_DSEC := -j ".data"
BIN_CSEC := -R ".data"

# Intel Hexadecimal Flash image tool
GENHEX := arm-none-eabi-objcopy
HEX_OPTS := -O ihex

# Motorola S-Record Flash image tool
GENSREC := arm-none-eabi-objcopy
SREC_OPTS := -O srec

OUT_OPTS :=

# Size tool
SIZE := arm-none-eabi-size
SIZE_OPTS := --format=berkeley

# Optimization flag
ifeq ($(TARGET_BUILD),Release)
C_OPTS += -O3
else
ifeq ($(TARGET_BUILD),Debug)
C_OPTS += -O0
else
$(error Wrong target build '$(TARGET_BUILD)')
endif
endif

# FPU flag
ifeq ($(CONFIG_FPU),hard)
C_OPTS += \
	-mfloat-abi=hard \
	-mfpu=fpv5-d16

A_OPTS += \
	-DUSE_FPU
else
ifeq ($(CONFIG_FPU),softfp)
C_OPTS += \
	-mfloat-abi=softfp \
	-mfpu=fpv5-d16

A_OPTS += \
	-DUSE_FPU
else
ifeq ($(CONFIG_FPU),no)
else
$(error Wrong FPU configuration '$(CONFIG_FPU)')
endif
endif
endif

TARGET_OPTS :=

C_OPTS += \
	-mthumb \
	-mcpu=cortex-m7 \
	-fmessage-length=0 \
	-fsigned-char \
	-ffunction-sections \
	-fdata-sections \
	-fomit-frame-pointer \
	-falign-functions=16 \
	-std=gnu99 \
	-Wall \
	-Wextra \
	-Wundef \
	-Wstrict-prototypes \
	-g3 \
	-gdwarf-3

A_OPTS += \
	-x assembler-with-cpp

L_OPTS += \
	-nostartfiles \
	-Xlinker \
	--gc-sections \
	-Wl,-Map,"$(TARGET_BUILD_DIR)/$(APP_NAME).map" \
	-Xlinker \
	--cref \
	-Wl,--no-warn-mismatch,--script="$(TARGET_BUILD_DIR)/$(LINKER_SCRIPT_NAME)" \
	-specs=nosys.specs

LST_OPTS += -Wa,-adhlns="$(@:%.o=%.lst)"

LANG_OPTS += -x c

DEP_OPTS += -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)"
endif