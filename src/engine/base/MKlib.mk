##########################################################
#
#                    The EVA11 project lib configrature 
#
# Author:    kevin.wang
# Company:   Eddysun     xiamen
# Date:      2012.12.13
# Comment:   Try to re-structure the Project Makefile
#            
#
###########################################################


########################################################### 
# Configrature the third library with follow selection
########################################################### 
LIBINC_STANDARD = yes
LIBINC_SDL      = no
LIBINC_SDL2     = no
LIBINC_GUI      = yes
LIBINC_RESOURCE = yes
LIBINC_GIF      = no
LIBINC_GSL      = no
LIBINC_LOG4CPP  = no
LIBINC_Z        = no
LIBINC_JPEG     = no
LIBINC_MD       = no
LIBINC_USB      = no
LIBINC_PNG      = no
LIBINC_FREETYPE = no
LIBINC_ICONV    = no
LIBINC_SQLITE3  = no
LIBINC_SSL      = no
LIBINC_SDLGFX   = no
LIBINC_SDLIMAGE = no
LIBINC_SDLNET   = no
LIBINC_SDLTTF   = no
LIBINC_SOCKETS  = no
LIBINC_BOOST    = no
LIBINC_ZTHREAD  = no
LIBINC_DIRECTFB = no
LIBINC_XML      = no
LIBINC_AGG      = no

export THIRDLIB_STATIC  =
export THIRDLIB_DYNAMIC =

export SEARCH_LIBPATH =
export SEARCH_INCPATH = -I$(MYLIBS_DIR)/sp++/include/

ifeq ($(LIBINC_STANDARD),yes)
SEARCH_INCPATH+=-I$(MYLIBS_DIR)/libstandard/
endif

ifeq ($(LIBINC_GUI),yes)
THIRDLIB_STATIC+=gui
SEARCH_LIBPATH+=-L../libgui/
SEARCH_INCPATH+=-I../libgui/
endif

ifeq ($(LIBINC_RESOURCE),yes)
SEARCH_LIBPATH+=-L../libresource/
SEARCH_INCPATH+=-I../libresource/
endif

ifeq ($(LIBINC_GIF),yes)
THIRDLIB_STATIC+=gif
SEARCH_LIBPATH+=-L$(MYLIBS_DIR)/libgif/lib/
SEARCH_INCPATH+=-I$(MYLIBS_DIR)/libgif/include/
endif

ifeq ($(LIBINC_GSL),yes)
THIRDLIB_STATIC+=gsl
THIRDLIB_STATIC+=gslcblas
SEARCH_LIBPATH+=-L$(MYLIBS_DIR)/libgsl/lib/
SEARCH_INCPATH+=-I$(MYLIBS_DIR)/libgsl/include/
endif

ifeq ($(LIBINC_LOG4CPP),yes)
THIRDLIB_STATIC+=log4cplus
SEARCH_LIBPATH+=-L$(MYLIBS_DIR)/liblog4cplus/lib/
SEARCH_INCPATH+=-I$(MYLIBS_DIR)/liblog4cplus/include/
endif

ifeq ($(LIBINC_Z),yes)
THIRDLIB_STATIC+=z
SEARCH_LIBPATH+=-L$(MYLIBS_DIR)/libz/lib/
SEARCH_INCPATH+=-I$(MYLIBS_DIR)/libz/include/
endif

ifeq ($(LIBINC_JPEG),yes)
THIRDLIB_STATIC+=jpeg
SEARCH_LIBPATH+=-L$(MYLIBS_DIR)/libjpeg/lib/
SEARCH_INCPATH+=-I$(MYLIBS_DIR)/libjpeg/include/
endif

ifeq ($(LIBINC_MD),yes)
THIRDLIB_STATIC+=md
SEARCH_LIBPATH+=-L$(MYLIBS_DIR)/libmd5/lib/
SEARCH_INCPATH+=-I$(MYLIBS_DIR)/libmd5/include/
endif

ifeq ($(LIBINC_USB),yes)
THIRDLIB_STATIC+=usb-1.0
SEARCH_LIBPATH+=-L$(MYLIBS_DIR)/libusb/lib/
SEARCH_INCPATH+=-I$(MYLIBS_DIR)/libusb/include/libusb-1.0/
endif

ifeq ($(LIBINC_PNG),yes)
THIRDLIB_STATIC+=png15
SEARCH_LIBPATH+=-L$(MYLIBS_DIR)/libpng/lib/
SEARCH_INCPATH+=-I$(MYLIBS_DIR)/libpng/include/
endif

ifeq ($(LIBINC_FREETYPE),yes)
THIRDLIB_STATIC+=freetype
SEARCH_LIBPATH+=-L$(MYLIBS_DIR)/libfreetype/lib/
SEARCH_INCPATH+=-I$(MYLIBS_DIR)/libfreetype/include/freetype2/
SEARCH_INCPATH+=-I$(MYLIBS_DIR)/libfreetype/include/
endif

ifeq ($(LIBINC_ICONV),yes)
THIRDLIB_STATIC+=iconv
SEARCH_LIBPATH+=-L$(MYLIBS_DIR)/libiconv/lib/
SEARCH_INCPATH+=-I$(MYLIBS_DIR)/libiconv/include/
endif

ifeq ($(LIBINC_SQLITE3),yes)
THIRDLIB_STATIC+=sqlite3
SEARCH_LIBPATH+=-L$(MYLIBS_DIR)/libsqlite/lib/
SEARCH_INCPATH+=-I$(MYLIBS_DIR)/libsqlite/include/
endif

ifeq ($(LIBINC_SSL),yes)
THIRDLIB_STATIC+=ssl crypto
SEARCH_LIBPATH+=-L$(MYLIBS_DIR)/libopenssl/lib/
SEARCH_INCPATH+=-I$(MYLIBS_DIR)/libopenssl/include/
endif

ifeq ($(LIBINC_SDLGFX),yes)
THIRDLIB_STATIC+=SDL_gfx
SEARCH_LIBPATH+=-L$(MYLIBS_DIR)/libsdl-gfx/lib/
SEARCH_INCPATH+=-I$(MYLIBS_DIR)/libsdl-gfx/include/
endif

ifeq ($(LIBINC_SDLIMAGE),yes)
THIRDLIB_STATIC+=SDL_image
SEARCH_LIBPATH+=-L$(MYLIBS_DIR)/libsdl-image/lib/
SEARCH_INCPATH+=-I$(MYLIBS_DIR)/libsdl-image/include/
endif

ifeq ($(LIBINC_SDLNET),yes)
THIRDLIB_STATIC+=SDL_net
SEARCH_LIBPATH+=-L$(MYLIBS_DIR)/libsdl-net/lib/
SEARCH_INCPATH+=-I$(MYLIBS_DIR)/libsdl-net/include/
endif

ifeq ($(LIBINC_SDLTTF),yes)
THIRDLIB_STATIC+=SDL_ttf
SEARCH_LIBPATH+=-L$(MYLIBS_DIR)/libsdl-ttf/lib/
SEARCH_INCPATH+=-I$(MYLIBS_DIR)/libsdl-ttf/include/
endif

ifeq ($(LIBINC_SDL),yes)
THIRDLIB_STATIC+=SDL
SEARCH_LIBPATH+=-L$(MYLIBS_DIR)/libsdl/lib/
SEARCH_INCPATH+=-I$(MYLIBS_DIR)/libsdl/include/SDL/
endif

ifeq ($(LIBINC_SDL2),yes)
THIRDLIB_STATIC+=SDL2
SEARCH_LIBPATH+=-L$(MYLIBS_DIR)/libsdl2.0/lib/
SEARCH_INCPATH+=-I$(MYLIBS_DIR)/libsdl2.0/include/
endif

ifeq ($(LIBINC_SOCKETS),yes)
THIRDLIB_STATIC+=Sockets
SEARCH_LIBPATH+=-L$(MYLIBS_DIR)/libsocket/lib/
SEARCH_INCPATH+=-I$(MYLIBS_DIR)/libsocket/include/
endif

ifeq ($(LIBINC_BOOST),yes)
THIRDLIB_STATIC+=boost_system boost_filesystem
SEARCH_LIBPATH+=-L$(MYLIBS_DIR)/libboost/lib/
SEARCH_INCPATH+=-I$(MYLIBS_DIR)/libboost/include/
endif

ifeq ($(LIBINC_ZTHREAD),yes)
THIRDLIB_STATIC+=ZThread
SEARCH_LIBPATH+=-L$(MYLIBS_DIR)/libzthread/lib/
SEARCH_INCPATH+=-I$(MYLIBS_DIR)/libzthread/include/
endif

ifeq ($(LIBINC_DIRECTFB),yes)
THIRDLIB_STATIC+=directfb
THIRDLIB_STATIC+=direct
THIRDLIB_STATIC+=fusion
THIRDLIB_STATIC+=++dfb
SEARCH_LIBPATH+=-L$(MYLIBS_DIR)/libdirectfb/lib/
SEARCH_INCPATH+=-I$(MYLIBS_DIR)/libdirectfb/include/

SEARCH_LIBPATH+=-L$(MYLIBS_DIR)/libdirectfb/lib/
SEARCH_INCPATH+=-I$(MYLIBS_DIR)/libdirectfb/include/
SEARCH_INCPATH+=-I$(MYLIBS_DIR)/libdirectfb/include/directfb/
endif

ifeq ($(LIBINC_XML),yes)
THIRDLIB_STATIC+=xml2
SEARCH_LIBPATH+=-L$(MYLIBS_DIR)/libxml2/lib/
SEARCH_INCPATH+=-I$(MYLIBS_DIR)/libxml2/include/libxml2/
endif

ifeq ($(LIBINC_AGG),yes)
THIRDLIB_STATIC+=agg
SEARCH_LIBPATH+=-L$(MYLIBS_DIR)/libagg/lib/
SEARCH_INCPATH+=-I$(MYLIBS_DIR)/libagg/include/
endif
