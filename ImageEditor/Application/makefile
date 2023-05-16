APPLICATION_DIR := $(PROJECT_DIR)/Application

srcs_application := main.cpp MainWindow.cpp MainMenu.cpp CanvasView.cpp ColorPicker.cpp

include $(APPLICATION_DIR)/Tools/makefile
include $(APPLICATION_DIR)/Filters/makefile
include $(APPLICATION_DIR)/Properties/makefile

srcs += $(srcs_application)

vpath %.cpp $(APPLICATION_DIR)