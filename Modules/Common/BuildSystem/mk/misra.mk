################################################################################
# StellarESDK misra makefile.
################################################################################

# Misra directory for working files
MISRA_PATH := $(subst C:,/c,$(subst \,/,$(PROJECT_ROOT_DIR)/pclint))

# Chech a specific module if provided at command line
# make MISRA_MODULES=UART misra
ifeq ($(MISRA_MODULES), )
MISRA_TMP := Modules
else
MISRA_TMP := $(call FIND_DIR_BY_NAME, Modules, "$(MISRA_MODULES)")
endif

# List of C files included in misra check
MISRA_CFILES_0 := $(filter $(MISRA_TMP)/%, $(C_SRCS))
MISRA_CFILES_1 := $(MISRA_CFILES_0:%=$(STELLAR_E_SDK_ROOT_DIR)/%)
MISRA_CFILES := $(subst \,/,$(MISRA_CFILES_1))

# Misra output file
MISRA_OUT := $(TARGET_BUILD_DIR)/misra.txt

################################################################################
# Misra configuration files
################################################################################

MISRA_WAIVER_FILE := $(MISRA_PATH)/waivers.lnt
MISRA_GCC_FILE := $(MISRA_PATH)/co-gcc.lnt
MISRA_AUTO_FILE := $(MISRA_PATH)/au-misra3.lnt

################################################################################
# Misra generated configuration files
################################################################################

MISRA_COMPILER_INCLUDE_PATH := $(MISRA_PATH)/gcc-include-path.lnt
MISRA_DEFAULT_C_DEFINES_FILE := $(MISRA_PATH)/lint_cmac.h
MISRA_DEFAULT_CPP_DEFINES_FILE := $(MISRA_PATH)/lint_cppmac.h

################################################################################
# Misra tools
################################################################################

# Misra lint-nt tool
LINT_TOOL = lint-nt.exe

# lint-nt options
LINT_OPTIONS = $(MISRA_GCC_FILE) $(MISRA_AUTO_FILE) $(MISRA_WAIVER_FILE)

################################################################################
# Misra temporary files
################################################################################

MISRA_C_TMP := $(MISRA_PATH)/tmp.c
MISRA_CPP_TMP := $(MISRA_PATH)/tmp.cpp

################################################################################
# Misra commands
################################################################################

# awk command to generate compiler include path
MISRA_AWK_CMD = /search starts/{inc=1; next}/End of search list./{inc=0; next}{if (inc>0) { printf("--i""\""$$1 " " $$2 " " $$3 " " $$4 " " $$5 " " $$6 " " $$7 "\"\n") }}

# Generate compiler include path
MISRA_INCLUDE_PATHS = $(shell $(CC) -E -Wp,-v $(MISRA_C_TMP) 2>&1 | $(GAWK) '$(MISRA_AWK_CMD)' &> $(MISRA_COMPILER_INCLUDE_PATH))

################################################################################
# Host settings for Misra tool
################################################################################
export PATH := $(STELLAR_E_SDK_PREFIX_PATH)/Tools/HostTools/Misra/bin$(PATH_SEPARATOR)${PATH}

################################################################################
# Misra targets
################################################################################

.PHONY: misra pre-misra main-misra

misra:
	@echo Start MISRA Check ...
	$(AT)"$(MAKE)" --no-print-directory pre-misra
	$(AT)"$(MAKE)" --no-print-directory main-misra

pre-misra:
	@$(RMDIR) $(PROJECT_ROOT_DIR)/pclint
	@$(CPDIR) $(STELLAR_E_SDK_ROOT_DIR)/$(COMMON_BUILDSYSTEM_PATH)/pclint $(PROJECT_ROOT_DIR)
	@$(TOUCH) $(MISRA_C_TMP)

main-misra: $(MISRA_COMPILER_INCLUDE_PATH) $(MISRA_DEFAULT_C_DEFINES_FILE) $(MISRA_DEFAULT_CPP_DEFINES_FILE)
	@echo -e
	@echo MISRA Check results in ... $(MISRA_OUT)
	@echo -e
	@echo ${LINT_TOOL} ${LINT_OPTIONS} $(subst \,/,$(C_INCS:%=-I"%")) $(subst \,/,$(MISRA_CFILES)) > $(MISRA_OUT)
	$(AT)${LINT_TOOL} ${LINT_OPTIONS} $(subst \,/,$(C_INCS:%=-I"%")) $(subst \,/,$(MISRA_CFILES)) >> $(MISRA_OUT)


.PHONY: $(MISRA_COMPILER_INCLUDE_PATH)
$(MISRA_COMPILER_INCLUDE_PATH):
	@echo Generate $@ for current compiler
	$(AT)$(MISRA_INCLUDE_PATHS)
	@$(RM) $(MISRA_C_TMP)


.PHONY: $(MISRA_DEFAULT_C_DEFINES_FILE)
$(MISRA_DEFAULT_C_DEFINES_FILE):
	@echo Generate $@ for current compiler 
	@$(TOUCH) $(MISRA_C_TMP)
	$(CC) $(C_OPTS) -E -dM $(MISRA_C_TMP) > $@
	@$(RM) $(MISRA_C_TMP)


.PHONY: $(MISRA_DEFAULT_CPP_DEFINES_FILE)
$(MISRA_DEFAULT_CPP_DEFINES_FILE):
	@echo Generate $@ for current compiler
	@$(TOUCH) $(MISRA_CPP_TMP)
	$(CCC) -E -dM $(MISRA_CPP_TMP) > $@
	@$(RM) $(MISRA_CPP_TMP)
