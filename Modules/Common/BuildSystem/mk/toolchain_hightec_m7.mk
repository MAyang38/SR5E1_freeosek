################################################################################
# StellarESDK HighTec toolchain makefile. Cortex-M7 oriented
################################################################################
ifeq ($(TOOLCHAIN), HIGHTEC)

ifeq ($(OS),Windows_NT)
# Currently STELLAR_E_SDK_TOOLCHAIN_PATH is not used since HighTec compiler
# path is stored in the environment variables during compiler installation.
STELLAR_E_SDK_TOOLCHAIN_PATH :=
else
UNAME_S := $(shell uname -s)
OS := Linux
ifeq ($(UNAME_S),Linux)
STELLAR_E_SDK_TOOLCHAIN_PATH :=
else
$(error $(UNAME_S) not supported yet)
endif
endif

TOOLCHAIN_ID := HighTec Cross C Compiler (M7)

# Compiler and linker tool
CC:= clang

# C++ Compiler
CCC := arm-none-eabi-g++

# Binary Flash image tool
GENBIN := llvm-objcopy
BIN_OPTS := -O binary
BIN_DSEC := -j ".data"
BIN_CSEC := -R ".data"

# Intel Hexadecimal Flash image tool
GENHEX := llvm-objcopy
HEX_OPTS := -O ihex

# Motorola S-Record Flash image tool
GENSREC := aarch32-objcopy
SREC_OPTS := -O srec

OUT_OPTS :=

# Size tool
SIZE := aarch32-size
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

TARGET_OPTS := --target=armv7-m-none-eabi

C_OPTS += \
	-mthumb \
	-march=armv7e-m \
	-mcpu=cortex-m7 \
	-fmessage-length=0 \
	-fsigned-char \
	-ffunction-sections \
	-fdata-sections \
	-fomit-frame-pointer \
	-falign-functions=16 \
	-fno-common \
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
	-Xlinker \
	--gc-sections \
	-Wl,-Map,"$(TARGET_BUILD_DIR)/$(APP_NAME).map" \
	-Xlinker \
	--cref \
	-Wl,--no-warn-mismatch,--script="$(TARGET_BUILD_DIR)/$(LINKER_SCRIPT_NAME)"

LST_OPTS +=

LANG_OPTS += -x c

DEP_OPTS += -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)"
endif