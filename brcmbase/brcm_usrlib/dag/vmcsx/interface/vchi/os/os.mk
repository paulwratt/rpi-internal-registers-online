
LIB_NAME  := vchi_os
LIB_SRC   := vcfw_os.c vcos_os.c vcos_os_vchiq.c
	     
LIB_VPATH := vcfw vcos
LIB_IPATH := 
LIB_DEFINES := 
LIB_CFLAGS  :=
LIB_AFLAGS  :=

IPATH_GLOBAL  += $(SRC_ROOT)/interface/vchi/os/vcfw
