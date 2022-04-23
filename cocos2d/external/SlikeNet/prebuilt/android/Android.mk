LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := ext_slikenet
LOCAL_MODULE_FILENAME := slikenet
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/libslikenet.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/../../include
include $(PREBUILT_STATIC_LIBRARY)
