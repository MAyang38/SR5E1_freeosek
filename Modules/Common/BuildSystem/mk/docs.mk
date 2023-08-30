################################################################################
# StellarESDK documentation makefile.
################################################################################

# Documentation directory for working files
DOCS_PATH := $(subst C:,/c,$(subst \,/,$(PROJECT_ROOT_DIR)/docs))

################################################################################
# Documentation configuration files
################################################################################

################################################################################
# Documentation generated configuration files
################################################################################

################################################################################
# Documentation tools
################################################################################

################################################################################
# Documentation temporary files
################################################################################

################################################################################
# Documentation commands
################################################################################

DOCS_OPTIONS := stellaresdk_doxyfile

################################################################################
# Host settings for documentation tool
################################################################################

DOCS_TOOL_LOG := $(DOCS_PATH)/doxygen.txt

################################################################################
# Documentation targets
################################################################################

.PHONY: docs pre-docs main-docs

docs:
	$(AT)"$(MAKE)" --no-print-directory pre-docs
	$(AT)"$(MAKE)" --no-print-directory main-docs

pre-docs:
	@echo Preparing...
	@$(RMDIR) $(PROJECT_ROOT_DIR)/docs
	@$(CPDIR) $(STELLAR_E_SDK_ROOT_DIR)/$(COMMON_BUILDSYSTEM_PATH)/docs $(PROJECT_ROOT_DIR)

main-docs:
	@echo Generating...
	$(AT)( cd $(DOCS_PATH) && ./docs.sh $(DOCS_VERSION) $(DOCS_OPTIONS) "$(DOCS_MODULES)" "$(DOCS_TESTS)" ) > $(DOCS_TOOL_LOG) 2>&1
