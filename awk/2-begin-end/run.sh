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
#       CREATED: 2020年06月30日 14:54
#      REVISION:  ---
#===============================================================================

set -o nounset                              # Treat unset variables as an error

awk 'BEGIN {print "start process ..."} {print $0} END { print "end process" }' data.txt
