LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_ARM_MODE := arm
LOCAL_MODULE    := poc 
LOCAL_SRC_FILES := poc.c   
LOCAL_LDLIBS  := -landroid -llog
LOCAL_CFLAGS += -fPIE
LOCAL_LDFLAGS += -fPIE -pie
include $(BUILD_EXECUTABLE)
