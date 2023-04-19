CURRENT_DIR  := $(PROJECT_DIR)/ViewLib
VIEW_LIB_DIR := $(PROJECT_DIR)/ViewLib

#srcs_view_lib := SimpleWindow.cpp
objs_view_lib := $(addprefix $(OBJ)/, $(srcs_view_lib:.cpp=.o))

srcs += $(srcs_view_lib)

vpath %.cpp $(VIEW_LIB_DIR)

include $(VIEW_LIB_DIR)/Graphics/makefile
include $(VIEW_LIB_DIR)/Event/makefile
#include $(VIEW_LIB_DIR)/ViewGroup/makefile
include $(VIEW_LIB_DIR)/View/makefile

srcs_view_lib += $(srcs_graphics) $(srcs_views) $(srcs_events) $(srcs_view_groups)
objs_view_lib += $(objs_graphics) $(objs_views) $(objs_events) $(objs_view_groups)