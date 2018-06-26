LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)
TARGET_CPU_API := armeabi
LOCAL_SRC_FILES := main.c
LOCAL_MODULE := shellcode
LOCAL_MODULE_TAGS := optional
LOCAL_LDLIBS := -L$(SYSROOT)/usr/lib -I$(SYSROOT)/usr/include

LOCAL_CFLAGS += -pie -fPIE -fno-stack-protector -z execstack
LOCAL_LDFLAGS += -pie -fPIE -fno-stack-protector -z execstack
include $(BUILD_EXECUTABLE)
