################################################################################
# StellarESDK module makefile.
################################################################################

#
# C sources
#
MODULE_C_SRCS := \
	src/$(CONFIG_DEVICE)/clock.c

#
# Assembly sources
#
MODULE_A_SRCS :=

#
# C include directories
#
MODULE_C_INCS := \
	include/$(CONFIG_DEVICE)

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
	BUILD_PLATFORM_CLOCK

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