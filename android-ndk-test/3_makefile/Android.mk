LOCAL_PATH := $(call my-dir) 
include $(CLEAR_VARS)
LOCAL_ARM_MODE := arm
LOCAL_MODULE    := wangvutils 
LOCAL_SRC_FILES := wangvutils.cpp
LOCAL_LDLIBS  := -landroid -llog
LOCAL_CFLAGS += -fPIE
LOCAL_LDFLAGS += -fPIE -pie
include $(BUILD_EXECUTABLE)
