APPLICATION_DIR := $(PROJECT_DIR)/Application

srcs_application := main.cpp MainWindow.cpp MainMenu.cpp ToolsMenu.cpp PropertiesMenu.cpp \
	CanvasView.cpp ColorPicker.cpp

include $(APPLICATION_DIR)/ToolsProperties/makefile

srcs += $(srcs_application)

vpath %.cpp $(APPLICATION_DIR)