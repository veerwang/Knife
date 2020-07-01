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
#       CREATED: 2020年07月01日 11:05
#      REVISION:  ---
#===============================================================================

set -o nounset                              # Treat unset variables as an error

awk 'BEGIN {print "Starting ..";}
	/zsh/ { print $0; }
    END {print "End ..";}' data.txt
