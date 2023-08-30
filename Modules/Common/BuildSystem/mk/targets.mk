################################################################################
# StellarESDK targets makefile.
################################################################################

PARALLEL_BUILD := 8

################################################################################
# Commands
################################################################################

CP      := cp -f
CPDIR   := cp -rf
RM      := rm -f
RMDIR   := rm -rf
MKDIR   := mkdir -p
DIRNAME := dirname
GREP    := grep
GAWK    := gawk
TOUCH   := touch
CUT     := cut

################################################################################
# Image file formats
################################################################################

ifeq ($(GENERATE_BIN_IMAGE), 0)
BIN_IMAGE :=
else
BIN_IMAGE := $(TARGET_BUILD_DIR)/$(APP_NAME).bin
endif

ifeq ($(GENERATE_HEX_IMAGE), 0)
HEX_IMAGE :=
else
HEX_IMAGE := $(TARGET_BUILD_DIR)/$(APP_NAME).hex
endif

ifeq ($(GENERATE_SREC_IMAGE), 0)
SREC_IMAGE :=
else
SREC_IMAGE := $(TARGET_BUILD_DIR)/$(APP_NAME).srec
endif

ifneq ($(SIZE),)
# Size information always printed
SIZE_IMAGE := $(TARGET_BUILD_DIR)/$(APP_NAME).size
endif

################################################################################
# Targets
################################################################################

VPATH = $(STELLAR_E_SDK_ROOT_DIR)

.DEFAULT_GOAL := all

all:
	@echo Toolchain: '$(TOOLCHAIN_ID)'
	$(AT)$(MKDIR) $(TARGET_BUILD_DIR)
	$(foreach dir, $(C_OBJS), $(shell $(MKDIR) $(shell $(DIRNAME) $(dir))))
	$(foreach dir, $(A_OBJS), $(shell $(MKDIR) $(shell $(DIRNAME) $(dir))))
	$(AT)"$(MAKE)" -j $(PARALLEL_BUILD) --no-print-directory pre-build
	$(AT)"$(MAKE)" -j $(PARALLEL_BUILD) --no-print-directory main-build


$(TARGET_BUILD_DIR)/$(LINKER_SCRIPT_NAME):
	@echo Generating linker script file '$(TARGET_BUILD_DIR)/$(LINKER_SCRIPT_NAME)'
ifeq ($(TOOLCHAIN), IAR)
	$(AT)$(CC) $(TARGET_OPTS) $(LANG_OPTS) $(LINKER_SCRIPT_INCS:%=-I%) $(LINKER_SCRIPT_DEFS:%=-D%) "$(LINKER_SCRIPT_SOURCE)" --preprocess=n $(TARGET_BUILD_DIR)/$(LINKER_SCRIPT_NAME).tmp
else
	$(AT)$(CC) $(TARGET_OPTS) -E $(LANG_OPTS) $(LINKER_SCRIPT_INCS:%=-I%) $(LINKER_SCRIPT_DEFS:%=-D%) "$(LINKER_SCRIPT_SOURCE)" > $(TARGET_BUILD_DIR)/$(LINKER_SCRIPT_NAME).tmp
endif
	$(AT)$(GREP) -v "^#" $(TARGET_BUILD_DIR)/$(LINKER_SCRIPT_NAME).tmp > "$(TARGET_BUILD_DIR)/$(LINKER_SCRIPT_NAME)"
	-$(AT)$(RM) $(TARGET_BUILD_DIR)/$(LINKER_SCRIPT_NAME).tmp

main-build: $(TARGET_BUILD_DIR)/$(APP_NAME).elf secondary-outputs
	@echo Done.


$(TARGET_BUILD_DIR)/$(APP_NAME).bin: $(TARGET_BUILD_DIR)/$(APP_NAME).elf
ifeq ($(CONFIG_TARGET_MEMORY), ram)
	@echo Creating BINARY ram image
else
	@echo Creating BINARY nvm image
endif
	$(AT)$(GENBIN) $(BIN_OPTS) "$(TARGET_BUILD_DIR)/$(APP_NAME).elf" $(OUT_OPTS) "$(TARGET_BUILD_DIR)/$(APP_NAME).bin"
	$(AT)$(GENBIN) $(BIN_OPTS) $(BIN_CSEC) "$(TARGET_BUILD_DIR)/$(APP_NAME).elf" $(OUT_OPTS) "$(TARGET_BUILD_DIR)/$(APP_NAME).code.bin"
	$(AT)$(GENBIN) $(BIN_OPTS) $(BIN_DSEC) "$(TARGET_BUILD_DIR)/$(APP_NAME).elf" $(OUT_OPTS) "$(TARGET_BUILD_DIR)/$(APP_NAME).data.bin"


$(TARGET_BUILD_DIR)/$(APP_NAME).hex: $(TARGET_BUILD_DIR)/$(APP_NAME).elf
ifeq ($(CONFIG_TARGET_MEMORY), ram)
	@echo Creating HEX ram image
else
	@echo Creating HEX nvm image
endif
	$(AT)$(GENHEX) $(HEX_OPTS) "$(TARGET_BUILD_DIR)/$(APP_NAME).elf" $(OUT_OPTS) "$(TARGET_BUILD_DIR)/$(APP_NAME).hex"


$(TARGET_BUILD_DIR)/$(APP_NAME).srec: $(TARGET_BUILD_DIR)/$(APP_NAME).elf
ifeq ($(CONFIG_TARGET_MEMORY), ram)
	@echo Creating SREC ram image
else
	@echo Creating SREC nvm image
endif
	$(AT)$(GENSREC) $(SREC_OPTS) "$(TARGET_BUILD_DIR)/$(APP_NAME).elf" $(OUT_OPTS) "$(TARGET_BUILD_DIR)/$(APP_NAME).srec"


ifneq ($(SIZE),)
$(TARGET_BUILD_DIR)/$(APP_NAME).size: $(TARGET_BUILD_DIR)/$(APP_NAME).elf
	@echo 'Printing Size'
	$(AT)$(SIZE) $(SIZE_OPTS) "$(TARGET_BUILD_DIR)/$(APP_NAME).elf"
	$(AT)$(TOUCH) "$(TARGET_BUILD_DIR)/$(APP_NAME).size"
endif

	
$(TARGET_BUILD_DIR)/$(APP_NAME).elf: $(TARGET_BUILD_DIR)/$(LINKER_SCRIPT_NAME) $(C_OBJS) $(A_OBJS)
	@echo "Linking '$@'"
	$(file >c_objs.lst,$(C_OBJS) $(A_OBJS))
ifeq ($(TOOLCHAIN), IAR)
	$(AT)$(LD) $(L_OPTS) -o "$(@)" $(C_OBJS) $(A_OBJS) $(LIBS)
else
	$(AT)$(CC) $(C_OPTS) $(L_OPTS) -o "$(@)" @c_objs.lst $(LIBS)
endif

$(TARGET_BUILD_DIR)/%.o: %.S
	@echo Building file: '$(<F)'
ifeq ($(TOOLCHAIN), IAR)
	$(AT)$(AS) $(A_OPTS) $(C_INCS:%=-I"%") $(A_INCS:%=-I"%") $(A_DEFS:%=-D%) $(LST_OPTS) $(DEP_OPTS) -o "$(@)" "$(<)"
else
	$(AT)$(CC) -c $(C_OPTS) $(A_OPTS) $(C_INCS:%=-I"%") $(A_INCS:%=-I"%") $(A_DEFS:%=-D%) $(LST_OPTS) $(DEP_OPTS) -o "$(@)" "$(<)"
endif


$(TARGET_BUILD_DIR)/%.o: %.c
	@echo Building file: '$(<F)'
	$(AT)$(CC) -c $(C_OPTS) $(C_INCS:%=-I"%") $(C_DEFS:%=-D%) $(LST_OPTS) $(DEP_OPTS) -o "$(@)" "$(<)"


clean:
	@echo Removing object files
	$(file >c_objs.lst,$(C_OBJS) $(A_OBJS) $(A_DEPS) $(C_DEPS) $(A_OBJS:%.o=%.lst) $(C_OBJS:%.o=%.lst))
	-$(AT)$(RM) @c_objs.lst
	-$(AT)$(RM) $(TARGET_BUILD_DIR)/$(APP_NAME).elf $(TARGET_BUILD_DIR)/$(APP_NAME).map
ifneq ($(SIZE),)
	-$(AT)$(RM) $(TARGET_BUILD_DIR)/$(APP_NAME).bin $(TARGET_BUILD_DIR)/$(APP_NAME).hex $(TARGET_BUILD_DIR)/$(APP_NAME).srec $(TARGET_BUILD_DIR)/$(APP_NAME).size
else
	-$(AT)$(RM) $(TARGET_BUILD_DIR)/$(APP_NAME).bin $(TARGET_BUILD_DIR)/$(APP_NAME).hex $(TARGET_BUILD_DIR)/$(APP_NAME).srec
endif
	-$(AT)$(RM) $(TARGET_BUILD_DIR)/$(LINKER_SCRIPT_NAME)
	-$(AT)$(RM) c_objs.lst


purge:
	@echo Removing build directory for '$(CONFIG_DEVICE) - $(CONFIG_BOARD)'
	-$(AT)$(RMDIR) $(TARGET_BUILD_DIR)
	-$(AT)$(RM) c_objs.lst


purge_all:
	@echo Removing build directory
	-$(AT)$(RMDIR) $(shell echo "$(TARGET_BUILD_DIR)" | cut -d/ -f1)
	-$(AT)$(RM) c_objs.lst

ifneq ($(SIZE),)
secondary-outputs: $(BIN_IMAGE) $(HEX_IMAGE) $(SREC_IMAGE) $(SIZE_IMAGE)
else
secondary-outputs: $(BIN_IMAGE) $(HEX_IMAGE) $(SREC_IMAGE)
endif


.PHONY: all clean purge purge_all main-build pre-build

################################################################################
# Automatic generated dependency files
################################################################################

-include $(C_DEPS) $(A_DEPS)
