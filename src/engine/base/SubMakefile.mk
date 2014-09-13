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

ifeq ($(DEBUG),yes)
COMPILE_FLAG = -g
else

ifeq ($(COMPILE),arm9)
COMPILE_FLAG = -O2 -march=armv4t
else 
COMPILE_FLAG = -O2
endif

endif

all: $(DEPS) build.o 

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

build.o: $(OBJS)
	@$(LD) -r -EL $^ -o $@

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
clean:
	$(RM) -rf *.o $(DEPS_DIR) $(OBJS_DIR) $(CASM_DIR)
