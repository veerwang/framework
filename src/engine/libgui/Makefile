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
SONAME   := $(LIBNAME).so.0
REALNAME := $(LIBNAME).so.0.0.0
LINKNAME := $(LIBNAME).so
STATICLIB:= $(LIBNAME).a

TXTOBJS  :=OBJS
TXTDEPS  :=DEPS
OBJS_DIR :=./$(TXTOBJS)/
DEPS_DIR :=./$(TXTDEPS)/

SRCS	 :=$(wildcard *.cpp)
OBJS	 :=$(SRCS:=.o)
DEPS	 :=$(SRCS:=.dep)

OBJS	 :=$(addprefix $(OBJS_DIR),$(OBJS))
DEPS	 :=$(addprefix $(DEPS_DIR),$(DEPS))

ifeq 	($(COMPILE),arm9)
COMPILE_FLAG = -O2 -std=gnu++11 -fPIC -DPIC -march=armv4t
export DFLAG  = -DARM9
else ifeq ($(COMPILE),x86)
COMPILE_FLAG = -O2 -std=gnu++0x -fPIC -DPIC
export DFLAG = -DX86
endif

LIBS:=$(LIBS)
STATICLIBS:=

all: $(DEPS) $(REALNAME)
	@echo "build $(LIBNAME) ..."
	@ln -sf $(REALNAME) $(SONAME);ln -sf $(REALNAME) $(LINKNAME)

$(DEPS_DIR)%.cpp.dep: %.cpp | depsdir
	@set -e; \
	$(RM) -rf $@.tmp; \
	gcc -E -MM $^ > $@.tmp; \
	sed 's,\(.*\)\.o[ :]*,$(TXTOBJS)/\1.cpp.o:,g' < $@.tmp > $@; \
	$(RM) $@.tmp

depsdir:
	@mkdir -p $(DEPS_DIR)

-include $(DEPS)

$(REALNAME): $(OBJS)
	@$(CPP) -fPIC -DPIC -shared -Wl,-soname -Wl,$(SONAME) -o $@ $^ -Wl,-Bdynamic $(addprefix -l,$(LIBS)) -Wl,-Bstatic $(addprefix -l,$(STATICLIBS)) -Wl,-Bdynamic
	@echo "G++ -fPIC -DPIC -shared -Wl,-soname -Wl,$(SONAME) -o $@ $^ -Wl,-Bdynamic $(addprefix -l,$(LIBS)) -Wl,-Bstatic $(addprefix -l,$(STATICLIBS)) -Wl,-Bdynamic"
	@$(AR) -r $(STATICLIB) $^
	@echo "AR -r $(STATICLIB) $^"
	@$(RANLIB) $(STATICLIB)
	@echo "RANLIB $(STATICLIB)"

$(OBJS_DIR)%.cpp.o: %.cpp | objsdir
	@$(CPP) $(COMPILE_FLAG) $(DFLAG) $(EXTDEF) -c $< -o $@
	@echo "G++ $(COMPILE_FLAG) $(DFLAG) $(EXTDEF) -c $< -o $@"

objsdir:
	@mkdir -p $(OBJS_DIR)

.PHONY: clean
clean:
	$(RM) -rf $(OBJS_DIR) $(DEPS_DIR) $(REALNAME) $(LINKNAME) $(SONAME) $(STATICLIB)
