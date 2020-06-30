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

# 打印文件总体函数
awk 'END {print NR}' data.txt
