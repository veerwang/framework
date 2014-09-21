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

make PROJ=engine CMOD=dynamic CASM=no SUBPROJS=libgui
make PROJ=engine CMOD=dynamic CASM=no SUBPROJS=libresource
make PROJ=engine CMOD=dynamic CASM=no SUBPROJS=base
