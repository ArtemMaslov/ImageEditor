CURRENT_DIR     := $(PROJECT_DIR)/Application
APPLICATION_DIR := $(CURRENT_DIR)

srcs_application = MainWindow.cpp main.cpp MainMenu.cpp ToolsMenu.cpp CanvasView.cpp PropertiesMenu.cpp

vpath %.cpp $(CURRENT_DIR)

include $(APPLICATION_DIR)/ToolsProperties/makefile

objs_application := $(addprefix $(OBJ)/, $(srcs_application:.cpp=.o))
srcs += $(srcs_application)