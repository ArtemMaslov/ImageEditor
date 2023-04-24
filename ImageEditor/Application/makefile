CURRENT_DIR     := $(PROJECT_DIR)/Application
APPLICATION_DIR := $(CURRENT_DIR)

srcs_application = main.cpp MainWindow.cpp MainMenu.cpp ToolsMenu.cpp PropertiesMenu.cpp CanvasView.cpp ColorPicker.cpp

vpath %.cpp $(CURRENT_DIR)

include $(APPLICATION_DIR)/ToolsProperties/makefile

objs_application := $(addprefix $(OBJ)/, $(srcs_application:.cpp=.o))
srcs += $(srcs_application)