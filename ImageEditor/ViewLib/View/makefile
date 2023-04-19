CURRENT_DIR := $(VIEW_LIB_DIR)/View

srcs_views := View.cpp Button.cpp TextView.cpp EditText.cpp ImageView.cpp
objs_views := $(addprefix $(OBJ)/, $(srcs_views:.cpp=.o))

srcs += $(srcs_views) $(src_view_unit_test)

vpath %.cpp $(CURRENT_DIR)