#!/bin/bash - 
#===============================================================================
#
#          FILE: makex86.sh
# 
#         USAGE: ./makex86.sh 
# 
#   DESCRIPTION: 
# 
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: YOUR NAME (), 
#  ORGANIZATION: 
#       CREATED: 2014年03月11日 10:24
#      REVISION:  ---
#===============================================================================

set -o nounset                              # Treat unset variables as an error

make PROJ=engine DEBUG=yes COMPILE=x86 CMOD=static CASM=no SUBPROJS=libgui
make PROJ=engine DEBUG=yes COMPILE=x86 CMOD=static CASM=no SUBPROJS=libresource
make PROJ=engine DEBUG=yes COMPILE=x86 CMOD=static CASM=no SUBPROJS=base
