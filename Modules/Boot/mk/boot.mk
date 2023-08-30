################################################################################
# StellarESDK module makefile.
################################################################################

#
# C sources
#
MODULE_C_SRCS := \
	src/crt1.c

# Assembly sources
ifeq ($(TOOLCHAIN), IAR)
MODULE_A_SRCS := \
	src/IAR/cstartup.S \
	src/IAR/vectors.S
else
MODULE_A_SRCS := \
	src/GCC/crt0.S \
	src/GCC/vectors.S
endif

#
# C include directories
#
MODULE_C_INCS := \
	include

#
# Assembly include directories
#
MODULE_A_INCS := \
	include

#
# Linker script include directories
#
MODULE_LS_INCS :=
#
# C defines
#
MODULE_C_DEFS := \
	BUILD_BOOT
	

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
