##########################################################
#
#                    The EVA11 project Makefile
#
# Author:    kevin.wang
# Company:   Eddysun     xiamen
# Date:      2012.12.13
# Comment:   Try to re-structure the Project Makefile
#            
#
###########################################################
#LOOPDIR:=$(shell find * -maxdepth 0 -path 'OBJS' -o -path 'DEPS' -prune -o -name '*' -type d -print)
#SRCS+=$(wildcard $(foreach DIR,$(LOOPDIR),$(DIR))/*.cpp)

EXEC     := main_$(shell basename $(shell pwd))

include MKlib.mk

SUBDIRS :=$(shell find * -maxdepth 0 -path 'OBJS' -o -path 'CASM' -o -path 'DEPS' -o -path 'Include' -prune -o -name '*' -type d -print)

ifeq ($(CMOD),dynamic)
DYNAMICLIBS=$(THIRDLIB_STATIC) $(THIRDLIB_DYNAMIC) $(LIBS)
STATICLIBS=resource
else
DYNAMICLIBS:=$(LIBS) $(THIRDLIB_DYNAMIC)
STATICLIBS=$(THIRDLIB_STATIC) resource
endif

TXTOBJS	:=OBJS
TXTDEPS	:=DEPS
TXTCASM :=CASM
OBJS_DIR:=./$(TXTOBJS)/
DEPS_DIR:=./$(TXTDEPS)/
CASM_DIR:=./$(TXTCASM)/
SRCS=
SRCS+=$(wildcard *.cpp *.c)

ifeq ($(COMPILE),arm9)
SRCS+=$(wildcard *.s)
endif

OBJS:=$(SRCS:=.o)
DEPS:=$(SRCS:=.dep)

OBJS:=$(addprefix $(OBJS_DIR),$(OBJS))
DEPS:=$(addprefix $(DEPS_DIR),$(DEPS))

SUBOBJS=
SUBOBJS+=$(foreach DIR,$(SUBDIRS),$(DIR)/build.o)

ifeq ($(DEBUG),yes)
COMPILE_FLAG = -g
LD_FLAG = -Wl,--rpath=./,--enable-new-dtags
else

ifeq ($(COMPILE),arm9)
COMPILE_FLAG = -O2 -march=armv4t
LD_FLAG = -Wl,--rpath=./,--enable-new-dtags
else
COMPILE_FLAG = -O2
LD_FLAG = -Wl,--rpath=./,--enable-new-dtags
endif

endif

all: SUBSYSTEM $(DEPS) $(EXEC)
ifeq ($(DEBUG),yes)
else
	@$(STRIP) $(EXEC)
endif
	@$(TOOLS_DIR)/md5app $(EXEC)
	@cp $(EXEC) $(DEST_DIR)	

ifneq ($(COMPILE),x86)
	@echo Copy the $(MAKE_DIR)/bin/$(EXEC) /tftpboot/$(EXEC)
	@chmod +x $(EXEC)
	@cp $(EXEC) /tftpboot/$(EXEC)
endif

SUBSYSTEM:
	@for dir in $(SUBDIRS); \
		do $(MAKE) $(MAKECMDGOALS) -C $$dir || exit 1; \
	done

$(DEPS_DIR)%.cpp.dep: %.cpp | depsdir
	@set -e; \
	gcc -E -MM $^ > $@.tmp; \
	sed 's,\(.*\)\.o[ :]*,$(TXTOBJS)/\1.cpp.o:,g' < $@.tmp > $@; \
	$(RM) $@.tmp

$(DEPS_DIR)%.c.dep: %.c | depsdir
	@set -e; \
	gcc -E -MM $^ > $@.tmp; \
	sed 's,\(.*\)\.o[ :]*,$(TXTOBJS)/\1.c.o:,g' < $@.tmp > $@; \
	$(RM) $@.tmp

$(DEPS_DIR)%.s.dep: %.s | depsdir
	@set -e; \
	echo $^: $^ > $@.tmp; \
	sed 's,\(.*\)\.s: *,$(TXTOBJS)/\1.o:,g' < $@.tmp > $@; \
	$(RM) $@.tmp

depsdir:
	@mkdir -p $(DEPS_DIR)

-include $(DEPS)

$(EXEC):$(OBJS) $(SUBOBJS)
	@$(CPP) $(FLAG) $(LD_FLAG) -o $@ $^ -Wl,-Bdynamic $(addprefix -l,$(DYNAMICLIBS)) -Wl,-Bstatic $(addprefix -l,$(STATICLIBS)) $(SEARCH_LIBPATH) -Wl,-Bdynamic
	@echo "G++ $(FLAG) $(LD_FLAG) -o $@"

$(OBJS_DIR)%.c.o: %.c | objsdir
	@$(CC) $(C_COMPILE_FLAG) $(DFLAG) $(COMPILE_FLAG) $(SEARCH_INCPATH) -c $< -o $@

ifeq 	($(CASM),yes)
	@$(CC) $(C_COMPILE_FLAG) $(DFLAG) $(COMPILE_FLAG) $(SEARCH_INCPATH) -S $< -o $(CASM_DIR)/$<.s
endif
	@echo "GCC $(C_COMPILE_FLAG) $(DFLAG) $(COMPILE_FLAG) -c $<"

$(OBJS_DIR)%.cpp.o: %.cpp | objsdir
	@$(CPP) $(CPP_COMPILE_FLAG) $(DFLAG) $(COMPILE_FLAG) $(SEARCH_INCPATH) -c $< -o $@

ifeq 	($(CASM),yes)
	@$(CPP) $(CPP_COMPILE_FLAG) $(DFLAG) $(COMPILE_FLAG) $(SEARCH_INCPATH) -S $< -o $(CASM_DIR)/$<.s
endif
	@echo "G++ $(CPP_COMPILE_FLAG) $(DFLAG) $(COMPILE_FLAG) -c $<"

$(OBJS_DIR)%.s.o: %.s | objsdir
	@$(AS) $< -o $@
	@echo "AS $<"

objsdir:
	@mkdir -p $(OBJS_DIR)
ifeq 	($(CASM),yes)
	@mkdir -p $(CASM_DIR)
endif

.PHONY: clean
clean: SUBSYSTEM
	$(RM) -rf $(OBJS_DIR) $(DEPS_DIR) $(CASM_DIR) $(EXEC);
