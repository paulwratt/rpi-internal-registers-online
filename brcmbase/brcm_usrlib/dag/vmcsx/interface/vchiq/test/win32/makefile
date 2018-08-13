
# You will need to change this compiler setting is not using the standard cl
COMPILER ?= cl

DEFINES=-DVCHI_LOCAL_HOST_PORT -DWIN32 -DUSE_DISPLAY -DVCHI_TEST_SERVER=1
IPATH=-I../../../ -I../../../../ -I../../../vmcs_host -I../../../vmcs_host/win32 \
      -I../../../vcos/win32

all: comms_test.exe

# Rules for MSVC
ifeq ($(COMPILER),cl)
CC=cl
ldflags=/Zi
CFLAGS= /Zi /c ${DEFINES} ${IPATH} -Dmphi_get_func_table=local_mphi_get_func_table
define compile_cmd
	$(CC) $(CFLAGS) /c /Fo$@ $<
endef
define link_cmd
	${CC} ${ldflags} /Fe$@ $(OBJECTS)
endef

# Rules for gcc

else
CC=gcc
ldflags=-g -mno-cygwin
# This redefines the mphi func table to be the on in win32.c (linux_mphi_get_func_table)
CFLAGS= -MD -g -c $(DEFINES) ${IPATH} -O2 -mno-cygwin -Wall -Dmphi_get_func_table=local_mphi_get_func_table
define compile_cmd
	$(CC) -c -o $@ $< $(CFLAGS)
endef
define link_cmd
	${CC} ${ldflags} -o $@ $(OBJECTS)
endef

-include *.d

endif


VPATH=../../../vchi/os/win32:../../common:../../connections/videocore:../../control_service:../../message_drivers/videocore:../../../../host_applications/framework/vmcs:../..:../../../vmcs_host:../../../vmcs_host/win32:..:../../../../applications/vmcs/vchi/test:../../../../host_applications/vmcs/test_apps/vchi_host_test ../../local 
VPATH += ../../../vcos/win32 ../../../vcos/generic ../../../vchi/os/vcos
#../../low_level/win32:

OBJECTS=comms_test.obj win32_os.obj core.obj shim.obj util.obj test_dc4.obj dc4.obj local.obj \
        vcos_generic_event_flags.obj vcos_mem_from_malloc.obj vcos_win32.obj \
        vcos_joinable_thread_from_plain.obj vcos_os.obj vcos_os_vchiq.obj vcos_msgqueue.obj \
        vcos_logcat.obj


comms_test.exe : $(OBJECTS)
	$(link_cmd)

mphi_test.exe : $(OBJECTS)
	$(link_cmd)

%.obj: %.c
	$(compile_cmd)

clean:
	rm -f *.o *.d
	rm -f *.obj
	rm -f *.pdb
	rm -f *.ilk
	rm -f *.suo
	rm -f comms_test.exe




