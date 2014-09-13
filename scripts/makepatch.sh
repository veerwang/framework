#!/bin/bash - 
#===============================================================================
#
#          FILE: makestatic.sh
# 
#         USAGE: ./makestatic.sh 
# 
#   DESCRIPTION: 
# 
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: YOUR NAME (), 
#  ORGANIZATION: 
#       CREATED: 2013年08月05日 11时17分12秒 CST
#      REVISION:  ---
#===============================================================================

set -o nounset                              # Treat unset variables as an error

mkdir -p patch;cd patch;git format-patch -$1;cd ..;tar -cf patch.tar patch;rm -rf patch
