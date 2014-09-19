##########################################################
#
#                    The Top level Makefile
#
# Author:    kevin.wang
# Company:   Eddysun     xiamen
# Date:      2012.12.16
# Comment:   Try to re-structure the Project Makefile
#            
#
###########################################################
###########################################################
#     Project name
#     Selection: engine
export PROJ     :=
export DEBUG    :=
export CASM     :=
export SUBPROJS :=

###########################################################
#     Compile Mode 
#     Static or Dynamic 
#       static  or  dynamic
export CMOD    := dynamic

###########################################################
#     Select which cross compiler tools to be used
#     Selection: armv41,armv42,arm9 or x86; 
#     default value is x86
export COMPILE  := x86

ifeq 	($(COMPILE),arm9)
CROSS := /opt/host/arm-veer-linux-gnueabi/bin/arm-veer-linux-gnueabi-
export DFLAG  := -DARM9
else ifeq ($(COMPILE),x86)
CROSS ?=
export DFLAG := -DX86
endif

CROSS ?=
###########################################################
export MAKE_DIR     := $(shell pwd)
export PARENTS_DIR  := $(dir $(MAKE_DIR))
export DIR_NAME     := $(notdir $(MAKE_DIR))

ifeq 	($(COMPILE),arm9)
export MYLIBS_DIR   := $(MAKE_DIR)/lib_arm9
else ifeq ($(COMPILE),x86)
export MYLIBS_DIR   := $(MAKE_DIR)/lib_x86
endif

export TOOLS_DIR    := $(MAKE_DIR)/tools/
export DEST_DIR     := $(MAKE_DIR)/bin/
###########################################################
export CROSS
export CC 	    := ccache $(CROSS)gcc
export CPP 	    := ccache $(CROSS)g++
export AS 	    := ccache $(CROSS)as
export OBJCOPY      := ccache $(CROSS)objcopy
export LD	    := ccache $(CROSS)ld
export RM 	    := rm
export AR 	    := $(CROSS)ar
export RANLIB	    := $(CROSS)ranlib
export STRIP 	    := $(CROSS)strip
###########################################################

ifeq 	($(COMPILE),arm9)
export LIBS 	    := pthread dl rt
else ifeq ($(COMPILE),x86)
export LIBS 	    := pthread dl bz2 rt
endif

export CPP_COMPILE_FLAG \
		    := -Werror -finline-functions

ifeq 	($(COMPILE),arm9)
	CPP_COMPILE_FLAG += -std=c++0x
else ifeq ($(COMPILE),x86)
	CPP_COMPILE_FLAG += -std=c++0x
endif

export C_COMPILE_FLAG \
		    := -Wall -finline-functions
export FLAG 	    := -Wall

###########################################################
MAKEFLAG 	    := -j1 --no-print-directory

.PHONY : all
all:
ifeq ($(PROJ),)
	$(make_msg)
else
	@cd $(MAKE_DIR)/src;$(MAKE) $(MAKEFLAG) $(MAKECMDGOALS)
endif

.PHONY : clean
clean:
	@set -e;cd src;$(MAKE) $(MAKEFLAG) $(MAKECMDGOALS)
	@$(RM) -f $(MAKE_DIR)/bin/main* $(MAKE_DIR)/bin/lib*

.PHONY : tar
tar: 
	@echo tar the Ruby project
	@cd $(PARENTS_DIR);tar -cjf $(DIR_NAME).tar.bz2 $(DIR_NAME);cd $(MAKE_DIR) 
###########################################################
define make_msg
@echo " "    
@echo Usage:
@echo "        make PROJ=project COMPILE=tool CMOD=compile mode"
@echo "        make PROJ=project clean"
@echo " "    
@echo " project: EVA11 (default)       tool: arm9  (default)       compile mode = static/dynamic"
@echo "          MD5APP                      arm11		    				" 
@echo "          GUIP		     	     x86						"
@echo "                                      							"
endef
