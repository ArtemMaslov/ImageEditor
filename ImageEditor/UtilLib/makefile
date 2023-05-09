UTIL_LIB_DIR := $(PROJECT_DIR)/UtilLib

srcs_util_lib := Linux.cpp

include $(UTIL_LIB_DIR)/FileSystem/makefile
include $(UTIL_LIB_DIR)/Errors/makefile
include $(UTIL_LIB_DIR)/Logs/makefile
include $(UTIL_LIB_DIR)/Text/makefile

srcs += $(srcs_util_lib)

vpath %.cpp $(UTIL_LIB_DIR)