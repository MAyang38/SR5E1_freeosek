################################################################################
# Project makefile.
################################################################################

# 'Stellar E SDK' project common dir
PROJECT_COMMON_DIR := ./common

include $(PROJECT_COMMON_DIR)/make/test_defs.mk

################################################################################
# Project builds
################################################################################
BUILD_OS_OSAL                  := 1

################################################################################
# Add project files
################################################################################

# Application name
APP_NAME := SR5E1_L9388_demo

# C sources
C_SRCS += \
	src/CAN_Init/CAN_LLD_Init.c\
	src/SPI_Init/SPI_LLD_Init.c\
	src/main.c\
	CDD/CDD_L9388/src/CDD_L9388_LLD.c\
	CDD/CDD_L9388/src/CDD_L9388_Drv.c\
	CDD/CDD_L9388/src/CDD_L9388_IF.c

C_INCS += \
	src/SPI_Init\
	src/CAN_Init\
	CDD/CDD_L9388/include
################################################################################
# Include 'Stellar E SDK' top level makefile
################################################################################
include $(STELLAR_E_SDK_BUILD_SYSTEM_DIR)/StellarESDK.mk
