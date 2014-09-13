##########################################################
#
#                    The Smart5097 project Makefile
#
# Author:    kevin.wang
# Company:   Eddysun     xiamen
# Date:      2010.05.13
# Comment:   Try to re-structure the Project Makefile
#            
#
###########################################################
TXTOBJS:=OBJS
TXTDEPS:=DEPS
OBJS_DIR:=./$(TXTOBJS)/
DEPS_DIR:=./$(TXTDEPS)/
EXOBJS_DIR:=../etio/

SRCS:=$(wildcard *.cpp *.c *.s)
OBJS:=$(SRCS:=.o)
DEPS:=$(SRCS:=.dep)

OBJS:=$(addprefix $(OBJS_DIR),$(OBJS))
DEPS:=$(addprefix $(DEPS_DIR),$(DEPS))
EXOBJS:=$(addprefix $(EXOBJS_DIR),$(EXOBJS))

COMPILE_FLAG = -O
LIBS:=$(LIBS) ssl crypto
SEARCH_LIBPATH = -L$(MYX86LIBS_DIR)/libopenssl/lib/
SEARCH_INCPATH = -I$(MYX86LIBS_DIR)/libopenssl/include/

all: $(DEPS) $(EXEC)

$(DEPS_DIR)%.cpp.dep: %.cpp
	@set -e; \
	$(RM) -rf $@.tmp; \
	gcc -E -MM $^ > $@.tmp; \
	sed 's,\(.*\)\.o[ :]*,$(TXTOBJS)/\1.cpp.o:,g' < $@.tmp > $@; \
	$(RM) $@.tmp

$(DEPS_DIR)%.c.dep: %.c
	@set -e; \
	$(RM) -rf $@.tmp; \
	gcc -E -MM $^ > $@.tmp; \
	sed 's,\(.*\)\.o[ :]*,$(TXTOBJS)/\1.c.o:,g' < $@.tmp > $@; \
	$(RM) $@.tmp

$(DEPS_DIR)%.s.dep: %.s
	@set -e; \
	$(RM) -rf $@.tmp; \
	echo $@ : $^ > $@.tmp; \
	sed 's,\(.*\)\.s.dep[ :]*,\1.s.o:,g' < $@.tmp > $@; \
	sed 's/$(TXTDEPS)/$(TXTOBJS)/g' < $@.tmp > $@; \
	$(RM) $@.tmp

-include $(DEPS)

$(EXEC): $(OBJS) $(EXOBJS)
	$(CPP) $(FLAG) -o $@ $^ $(addprefix -l,$(LIBS)) $(SEARCH_LIBPATH)

$(addprefix $(OBJS_DIR),%.s.o): %.s
	$(AS) $< -o $@

$(addprefix $(OBJS_DIR),%.c.o): %.c
	$(CC) $(COMPILE_FLAG) $(EXTDEF) $(SEARCH_INCPATH) -c $< -o $@

$(addprefix $(OBJS_DIR),%.cpp.o): %.cpp
	$(CPP) $(COMPILE_FLAG) $(EXTDEF) $(SEARCH_INCPATH) -c $< -o $@

$(addprefix $(OBJS_DIR),$(TXTJPGS)/%.jpg.o): $(TXTJPGS)/%.jpg
	$(OBJCOPY) -I binary -O elf32-littlearm -B arm $< $@

$(addprefix $(OBJS_DIR),$(TXTJPGS)/%.png.o): $(TXTJPGS)/%.png
	$(OBJCOPY) -I binary -O elf32-littlearm -B arm $< $@

.PHONY: clean
clean:
	$(RM) -rf $(addprefix $(OBJS_DIR),*.o) $(addprefix $(DEPS_DIR),*.dep) $(EXEC) 
