##########################################################
#
#                   For Shared library Test 
#
# Author:    kevin.wang
# Company:   Eddysun     xiamen
# Date:      2012.12.18
#            
#
###########################################################
LIBNAME  := $(shell basename $(shell pwd))
STATICLIB:= $(LIBNAME).a

TXTOBJS  :=OBJS
TXTDEPS  :=DEPS
OBJS_DIR :=./$(TXTOBJS)/
DEPS_DIR :=./$(TXTDEPS)/

SRCS	 :=$(wildcard *.jpg *.png *.gif)
OBJS	 :=$(SRCS:=.o)
DEPS	 :=$(SRCS:=.dep)

OBJS	 :=$(addprefix $(OBJS_DIR),$(OBJS))
DEPS	 :=$(addprefix $(DEPS_DIR),$(DEPS))

all: $(DEPS) $(STATICLIB)
	@echo "build $(STATICLIB) ..."

$(DEPS_DIR)%.jpg.dep: %.jpg | depsjpegdir
	@set -e;

$(DEPS_DIR)%.png.dep: %.png | depsjpegdir
	@set -e;

$(DEPS_DIR)%.gif.dep: %.gif | depsjpegdir
	@set -e;

depsjpegdir:
	@mkdir -p $(DEPS_DIR)

-include $(DEPS)

$(STATICLIB): $(OBJS)
	@$(AR) -r $(STATICLIB) $^
	@echo "AR -r $(STATICLIB) $^"
	@$(RANLIB) $(STATICLIB)
	@echo "RANLIB $(STATICLIB)"

$(OBJS_DIR)%.jpg.o: %.jpg | objsjpegdir
	$(makejpegresource)

$(OBJS_DIR)%.png.o: %.png | objsjpegdir
	$(makejpegresource)

$(OBJS_DIR)%.gif.o: %.gif | objsjpegdir
	$(makejpegresource)

ifeq ($(COMPILE),arm9)
define makejpegresource
	@$(OBJCOPY) -I binary -O elf32-littlearm -B arm $< $@
	@echo "OBJCOPY -I binary -O elf32-littlearm -B arm $< $@"
endef
else
define makejpegresource
	@$(OBJCOPY) -I binary -O elf32-i386 -B i386 $< $@
	@echo "OBJCOPY -I binary -O elf32-i386 -B i386 $< $@"
endef
endif

objsjpegdir :
	@mkdir -p $(OBJS_DIR)

.PHONY: clean
clean:
	$(RM) -rf $(OBJS_DIR) $(DEPS_DIR) $(STATICLIB)
