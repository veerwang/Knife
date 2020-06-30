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

# 这种结构和C语言非常相似
awk 'BEGIN {print "Starting ..";} 
{ 
	for ( i=0;i<3;i++ )
		print("%d",NR);
} 
    END {print "End ..";}' data.txt
