PROJECT_DIR := .

include $(PROJECT_DIR)/makefile_settings
include $(PROJECT_DIR)/makefile_utils

###############################################################################

srcs :=

include $(PROJECT_DIR)/Application/makefile
include $(PROJECT_DIR)/UtilLib/makefile
include $(PROJECT_DIR)/ViewLib/makefile

###############################################################################

dependencies     := $(addprefix $(DPND)/, $(srcs:.cpp=.d))

objs_to_compile  := $(call SRC_TO_OBJ, $(srcs))
objs_modules     := $(call SRC_TO_OBJ, $(srcs_view_lib)) $(call SRC_TO_OBJ, $(srcs_util_lib))
objs_application := $(call SRC_TO_OBJ, $(srcs_application))

###############################################################################

$(dependencies): $(DPND)/%.d: %.cpp | dir_dpnd
	@$(COMP) -MM -o $@ $< \
		-MT '$(DPND)/$*.d' \
		-MT '$(OBJ)/$*.obj' \
		$(INCLUDE_INTERNAL_LIBS) $(DEFINES)

include $(dependencies)

###############################################################################

$(objs_to_compile): $(OBJ)/%.obj: %.cpp $(DPND)/%.d
	$(call msg_compile, $*)
	@$(COMP) -o $@ $< $(COMP_FLAGS)

compile: $(objs_to_compile)

###############################################################################

build: dir_obj dir_bin
	$(call msg_build, проекта)
	@echo "Автоматически выбрана операционная система $(TARGET_OS)"

	$(call msg_compile, проекта)
	+$(call call_make, ./, compile)
	$(call msg_compile_complete)

	$(call msg_linking)
	
	@$(COMP) -o $(TARGET_PATH) \
		$(objs_modules) $(objs_application) $(LINK_FLAGS)

	$(if $(wildcard ../x64/Debug/Images), , cp ../Images ../x64/Debug/ -r)
	$(if $(wildcard ../x64/Debug/Liberation\ Sans), , cp ../"Liberation Sans" ../x64/Debug/ -r)
	
	$(call msg_build_complete)

###############################################################################

.PHONY: compile build compile_root view_test

.DEFAULT_GOAL = build