LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)
TARGET_CPU_API := armeabi
LOCAL_SRC_FILES := main.cpp
LOCAL_MODULE := dirtycow
LOCAL_MODULE_TAGS := optional
LOCAL_LDLIBS := -L$(SYSROOT)/usr/lib -I$(SYSROOT)/usr/include
include $(BUILD_EXECUTABLE)
