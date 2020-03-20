#!/bin/bash - 
#===============================================================================
#
#          FILE: compile-libpcap.sh
# 
#         USAGE: ./compile-libpcap.sh 
# 
#   DESCRIPTION: 
# 
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: YOUR NAME (), 
#  ORGANIZATION: 
#       CREATED: 2020年03月20日 10:42
#      REVISION:  ---
#===============================================================================

set -o nounset                              # Treat unset variables as an error

BASEPATH=$(cd `dirname $0`; pwd)
cd libpcap
 
export NDK=/home/kevin/android-ndk-r14b
export PREBUILT=$NDK/toolchains/arm-linux-androideabi-4.9/prebuilt
export PLATFORM=$NDK/platforms/android-23/arch-arm
export PREFIX=$BASEPATH/build-arm/libpcap
 
build_pcap() {
  ./configure --host=arm-linux \
  CC="$PREBUILT/linux-x86_64/bin/arm-linux-androideabi-gcc --sysroot=$PLATFORM" \
  --prefix=$PREFIX
}
 
build_pcap
 
make
make install
 
cd ..
