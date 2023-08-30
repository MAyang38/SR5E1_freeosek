################################################################################
# StellarESDK clang makefile.
################################################################################

################################################################################
# Clang defines
################################################################################

# Coding style tool
CLANG_TOOL := clang-format.exe

ifeq ($(CLANG_OPTS),)
CLANG_OPTS := -i
endif

# Clang format file
CLANG_FORMAT_FILE := $(STELLAR_E_SDK_ROOT_DIR)/$(COMMON_BUILDSYSTEM_PATH)/clang/.clang-format

# List of C files included in coding style format
CLANG_CFILES := $(filter Modules/%,$(C_SRCS))

# List of header files excluded from coding style format (included also the Tools ones)
CLANG_HFILES_EXCLUDED := \
			$(COMMON_BUILDSYSTEM_PATH)/pclint/co-gcc.h \
			$(PLATFORM_MCU_PATH)/include/sr5e1/sr5e1xx.h \

# List of H files included in coding style format
CLANG_HFILES_ALL := $(subst $(STELLAR_E_SDK_ROOT_DIR)/,, $(shell find $(STELLAR_E_SDK_ROOT_DIR)/Modules -type f -name "*.h"))
CLANG_HFILES := $(filter-out $(CLANG_HFILES_EXCLUDED), $(CLANG_HFILES_ALL))

################################################################################
# Host settings for Clang tool
################################################################################
export PATH := $(STELLAR_E_SDK_PREFIX_PATH)/Tools/HostTools/Clang/bin$(PATH_SEPARATOR)${PATH}

################################################################################
# Clang targets
################################################################################
clang:
	@echo "Copying C language format file (coding style)"
	@$(CP) $(CLANG_FORMAT_FILE) $(STELLAR_E_SDK_ROOT_DIR)
	@echo "Performing clang format for C sources..."
	$(AT)( cd $(STELLAR_E_SDK_ROOT_DIR) && $(CLANG_TOOL) $(CLANG_OPTS) --style=file $(CLANG_CFILES) )
	@echo "Performing clang format for Headers..."
	$(AT)( cd $(STELLAR_E_SDK_ROOT_DIR) && $(CLANG_TOOL) $(CLANG_OPTS) --style=file $(CLANG_HFILES) )

.PHONY: clang

