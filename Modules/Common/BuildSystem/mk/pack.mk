################################################################################
# StellarESDK packaging makefile.
################################################################################

################################################################################
# Packaging configuration files
################################################################################

################################################################################
# Packaging generated configuration files
################################################################################

################################################################################
# Packaging tools
################################################################################

# Zip tool
PACK_TOOL = 7z.exe

# Packaging tool options
PACK_OPTIONS =

################################################################################
# Packaging temporary files
################################################################################

################################################################################
# Packaging commands
################################################################################

################################################################################
# Host settings for packaging tool
################################################################################

################################################################################
# Packaging targets
################################################################################

.PHONY: pack pre-pack main-pack

pack:
	$(AT)"$(MAKE)" --no-print-directory pre-pack
	$(AT)"$(MAKE)" --no-print-directory main-pack

pre-pack:
	@echo Pre-packaging...
	@$(RMDIR) $(PROJECT_ROOT_DIR)/pack
	@$(CPDIR) $(STELLAR_E_SDK_ROOT_DIR)/$(COMMON_BUILDSYSTEM_PATH)/pack $(PROJECT_ROOT_DIR)

main-pack:
	@echo Start packaging...
	( cd $(PROJECT_ROOT_DIR)/pack && ./pack.sh $(STELLAR_E_SDK_ROOT_DIR) "$(PACK_RELEASE_NAME)" "$(PACK_EXCLUDE_DIRS)" )