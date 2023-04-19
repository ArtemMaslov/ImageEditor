PROJECT_DIR := .

include $(PROJECT_DIR)/makefile_settings
include $(PROJECT_DIR)/makefile_utils

vpath %.d $(DEPENDENCIES_DIR)
vpath %.o $(OBJ)

###############################################################################

srcs      := 

include $(PROJECT_DIR)/Application/makefile
include $(PROJECT_DIR)/UtilLib/makefile
include $(PROJECT_DIR)/ViewLib/makefile

###############################################################################

dependencies    := $(addprefix $(DEPENDENCIES_DIR)/, $(srcs:.cpp=.d))

objs_to_compile := $(srcs:.cpp=.o)
objs_modules    := $(objs_util_lib) $(objs_view_lib)

###############################################################################

$(dependencies): $(DEPENDENCIES_DIR)/%.d: %.cpp | dir_dpnd
	@$(COMP) -MM -o $@ $< -MT '$*.d' -MT '$*.o' $(INCLUDE_DIRS)

include $(dependencies)

###############################################################################

$(objs_to_compile): %.o: %.cpp %.d
	$(call msg_compile, $*)
	@$(COMP) -o $(OBJ)/$@ $< $(COMP_FLAGS)

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
	
	$(call msg_build_complete)

###############################################################################

view_test: dir_obj dir_bin
	$(call msg_build, проекта)
	@echo "Автоматически выбрана операционная система $(TARGET_OS)"

	$(call msg_compile, проекта)
	+$(call call_make, ./, compile)
	$(call msg_compile_complete)

	$(call msg_linking)

	@$(COMP) -o $(TARGET_PATH) \
		$(objs_modules) $(obj_view_unit_test) $(LINK_FLAGS)
	
	$(call msg_build_complete)

###############################################################################

.PHONY: compile build compile_root view_test

.DEFAULT_GOAL = build