################################################################################
# StellarESDK GHS toolchain makefile. Cortex-M7 oriented
################################################################################
ifeq ($(TOOLCHAIN), GHS)

TOOLCHAIN_ID := GHS Cross C Compiler (M7)

ifeq (, $(shell which ccarm 2> /dev/null))
$(error "No GHS compiler in PATH, please add it.")
endif

# Compiler and linker tool
CC:= ccarm

# Binary Flash image tool
GENBIN := gmemfile -w
BIN_OPTS :=
BIN_DSEC := -start ".data" -end ".data"
BIN_CSEC := -skip ".data"

# Intel Hexadecimal Flash image tool
GENHEX := gsrec
HEX_OPTS := -hex386

# Motorola S-Record Flash image tool
GENSREC := gsrec
SREC_OPTS :=

OUT_OPTS := -o

# Size tool
SIZE := gsize
SIZE_OPTS := -gcompare -totals

# Optimization flag
ifeq ($(TARGET_BUILD),Release)
C_OPTS += -Ospeed
else
ifeq ($(TARGET_BUILD),Debug)
C_OPTS += -Ogeneral
else
$(error Wrong target build '$(TARGET_BUILD)')
endif
endif

# FPU flag
ifeq ($(CONFIG_FPU),hard)
C_OPTS += \
	-fhard \
	-fpu=vfpv5_d16

A_OPTS += \
	-DUSE_FPU
else
ifeq ($(CONFIG_FPU),softfp)
C_OPTS += \
	-fsoft \
	-fpu=vfpv5_d16

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
	-thumb \
	-littleendian \
	-cpu=cortexm7 \
	--signed_chars \
	--gnu_asm \
	--warnings \
	-g \
	-dwarf2 \
	--commons

A_OPTS += \
	-preprocess_assembly_files \
	--gnu_asm

L_OPTS += \
	-nostartfiles \
	-map="$(TARGET_BUILD_DIR)/$(APP_NAME).map" \
	"$(TARGET_BUILD_DIR)/$(LINKER_SCRIPT_NAME)" \
	-overlap -w

LST_OPTS += -list="$(@:%.o=%.lst)"

LANG_OPTS +=

endif