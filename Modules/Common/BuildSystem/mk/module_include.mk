################################################################################
# StellarESDK module makefile.
################################################################################
include $(STELLAR_E_SDK_ROOT_DIR)/$(MODULE_FILE_MK)

MODULE_SRC_PATH := $(shell dirname $(shell dirname $(MODULE_FILE_MK)))

C_INCS += $(MODULE_C_INCS:%=$(STELLAR_E_SDK_ROOT_DIR)/$(MODULE_SRC_PATH)/%)
A_INCS += $(MODULE_A_INCS:%=$(STELLAR_E_SDK_ROOT_DIR)/$(MODULE_SRC_PATH)/%)
C_DEFS += $(MODULE_C_DEFS)
A_DEFS += $(MODULE_A_DEFS)
C_OPTS += $(MODULE_C_OPTS)
A_OPTS += $(MODULE_A_OPTS)
