################################################################################
# StellarESDK release Note generation makefile.
################################################################################

################################################################################
# Release Note configuration files
################################################################################
SESDK_MODULE_LIST := module.lst

################################################################################
# Packaging generated configuration files
################################################################################

################################################################################
# Release Note targets
################################################################################

.PHONY: relNote pre-relNote main-relNote

relNote:
	$(AT)"$(MAKE)" --no-print-directory pre-relNote
	$(AT)"$(MAKE)" --no-print-directory main-relNote

pre-relNote:
	@echo Pre-relNote...
	@$(RMDIR) $(PROJECT_ROOT_DIR)/releaseNote
	@$(CPDIR) $(STELLAR_E_SDK_ROOT_DIR)/$(COMMON_BUILDSYSTEM_PATH)/releaseNote $(PROJECT_ROOT_DIR)

main-relNote:
	@echo Start release Note...
	( cd $(PROJECT_ROOT_DIR)/releaseNote && ./releaseNote.sh $(STELLAR_E_SDK_ROOT_DIR) $(PROJECT_ROOT_DIR) $(SESDK_MODULE_LIST) "$(SESDK_RELEASE)" )
