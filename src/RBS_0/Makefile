#******************************************************************************
#**  CarMaker - Version 13.0.1
#**  Vehicle Dynamics Simulation Toolkit
#**
#**  Copyright (C)   IPG Automotive GmbH
#**                  Bannwaldallee 60             Phone  +49.721.98520.0
#**                  76185 Karlsruhe              Fax    +49.721.98520.99
#**                  Germany                      WWW    www.ipg-automotive.com
#******************************************************************************
#**
#**  Application Makefile
#**  Run with 'make V=1 ...' for a verbose build.
#**
#******************************************************************************

MAKEDEFS ?= MakeDefs.xeno

include C:/IPG/carmaker/win64-13.0.1/include/$(MAKEDEFS)

ifneq ($(filter linux64 xeno nilrt dsrt dsrtlx dsrt64, $(ARCH)), )
RBS_EXT = .so
else
RBS_EXT = .dll
endif

RBS_NAME ?=			RBS_0
LIB_NAME =			$(RBS_NAME)$(RBS_EXT)
RBS_SRCS ?=			$(LIB_NAME:$(RBS_EXT)=.c)
RBS_LIB_NAME ?=			libRBS_0$(RBS_EXT)
RBS_LIBS ?=			
RBS_CFLAGS ?=			

TARGET_DIR ?=			../../lib

LD_LIBS =			$(RBS_LIBS) $(CARMAKER_LIB_DIR)/librbsutil.a

ifeq ($(ARCH), dsrt)
LD_LIBS += $(CARMAKER_LIB_DIR)/libipgrtif.a
endif

SUBDIRS = 			ECU Frame Signal

PDUMODE ?=			1
ifeq ($(PDUMODE),1)
SUBDIRS +=			PDU
endif

OBJS ?=				$(RBS_SRCS:.c=.o) $(RBS_SRCS:.c=_Init.o)
OBJS +=				$(foreach dir,$(SUBDIRS),$(dir)/$(dir).o) $(foreach dir,$(SUBDIRS),$(dir)/$(dir)_Init.o) 

CFLAGS +=			-I$(CARMAKER_DIR)/include/ -I../ -D__IPGRT_H__ $(RBS_CFLAGS)

#OPT_CFLAGS =			-g -O0

default:	$(LIB_NAME) install clean
$(LIB_NAME):	$(OBJS) $(LD_LIBS_MK)
	$(QECHO) " LD     $@"
	$Q $(CC) $(CFLAGS) $(LDFLAGS) -shared -o $@ $(OBJS) $(LD_LIBS)

makedir:	
	$(QECHO) " MKDIR  $(TARGET_DIR)"
	$Q mkdir -p $(TARGET_DIR)

install: 	makedir $(LIB_NAME)
	$(QECHO) " CP     $(RBS_LIB_NAME)"
ifneq ($(LIB_NAME), $(RBS_LIB_NAME))
	$Q mv $(LIB_NAME) $(RBS_LIB_NAME)
endif
	$Q cp $(RBS_LIB_NAME) $(TARGET_DIR)

.PHONY: clean_subdirs $(SUBDIRS)
clean: clean_subdirs clean_dir

clean_dir:
	-rm -f 	*~ *% *.o *.dll *.so core

clean_subdirs: $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) --no-print-directory -f ../Makefile -C $@ clean_dir
