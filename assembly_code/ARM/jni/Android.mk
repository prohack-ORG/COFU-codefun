LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_ARM_NEON := true

LOCAL_CFLAGS += -fPIE -O3
LOCAL_CPPFLAGS += -fPIE -O3
LOCAL_LDFLAGS += -fPIE -pie

LOCAL_NEON_CFLAGS := -mfloat-abi=softfp -mfpu=neon -march=armv7
LOCAL_NEON_CPPFLAGS := -mfloat-abi=softfp -mfpu=neon -march=armv7

LOCAL_MODULE := sample

LOCAL_SRC_FILES := ../src/main.cpp \
                   ../src/sample_asm.s 

TARGET-process-src-files-tags += $(call add-src-files-target-cflags, $(LOCAL_SRC_FILES), $(LOCAL_NEON_CFLAGS))

include $(BUILD_EXECUTABLE)
