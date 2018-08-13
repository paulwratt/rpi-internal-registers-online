# =============================================================================
# Copyright (c) 2009-2014, Broadcom Corporation
# All rights reserved.
# Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
# 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
# 3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
# =============================================================================

# Note: automatic dependency checking only works if using gcc.

COMPILER = gcc

RTOS=pthreads

IPATH+=-I../../.. -I../pthreads

ifeq ($(COMPILER),cl)
OBJEXT=obj
else
OBJEXT=o
endif

ifneq ($(OS),) # Improve this test
LIBS=-lvcos -lpthread
else
LIBS=-lvcos -lpthread -lrt
endif

#
# Rules for MSVC
#

ifeq ($(COMPILER),cl)
CC=cl
ldflags=/Zi
CFLAGS=/Zi /c ${DEFINES} ${IPATH} -Dmphi_get_func_table=local_mphi_get_func_table
define compile_cmd
	$(CC) $(CFLAGS) /c /Fo$@ $<
endef
define link_cmd
	${CC} ${ldflags} /Fe$@ $(OBJECTS) /link ../$(RTOS)/libvcos.a
endef
define link_cmd_nolibs
	${CC} ${ldflags} /Fe$@ $(OBJECTS)
endef

#
# Rules for gcc
#

else

CC=gcc
ldflags=-g -L../$(RTOS)
# This redefines the mphi func table to be the on in win32.c (linux_mphi_get_func_table)
CFLAGS= -Werror -MD -g -c $(DEFINES) ${IPATH} -O2 -Wall -Dmphi_get_func_table=local_mphi_get_func_table
CPPFLAGS= -Werror -MD -g -c $(DEFINES) ${IPATH} -O2 -Wall -Dmphi_get_func_table=local_mphi_get_func_table

ifdef NDEBUG
CFLAGS += -O2 -DNDEBUG
else
CFLAGS += -O1
endif

define compile_cmd
	$(CC) -c -o $@ $< $(CFLAGS)
endef

define link_cmd
	${CC} ${ldflags} -o $@ $(OBJECTS) $(LIBS)
endef

define link_cmd_nolibs
	${CC} ${ldflags} -o $@ $(OBJECTS)
endef

-include *.d

endif

%.obj: %.c
	$(compile_cmd)

%.obj: %.cpp
	$(compile_cmd)

define clean_cmd
	rm -f *.o *.d
	rm -f *.obj
	rm -f *.pdb
	rm -f *.ilk
	rm -f *.suo
	rm -f comms_test.exe
endef





