APP_STL := gnustl_static
APP_ABI := armeabi-v7a
APP_CPPFLAGS   := -pedantic -O2 -std=c++11 -lutil
APP_LDLIBS := -L$(SYSROOT)/usr/lib -I$(SYSROOT)/usr/include
