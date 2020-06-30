#!/bin/bash - 
#===============================================================================
#
#          FILE: run.sh
# 
#         USAGE: ./run.sh 
# 
#   DESCRIPTION: 
# 
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: YOUR NAME (), 
#  ORGANIZATION: 
#       CREATED: 2020年06月30日 13:46
#      REVISION:  ---
#===============================================================================

set -o nounset                              # Treat unset variables as an error
echo "Get information from file"

# 打印文件当中的第二列
# 然后以:为分隔符，打印第二列
# 最后打印，第二行数据
awk '{print $2}' data.txt | awk -F"[:]" '{print $2}' | awk 'NR==2{print $0}'
