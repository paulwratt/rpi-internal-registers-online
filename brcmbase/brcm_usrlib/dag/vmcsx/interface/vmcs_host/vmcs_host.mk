# =============================================================================
# Copyright (c) 2006-2014, Broadcom Corporation
# All rights reserved.
# Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
# 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
# 3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
# =============================================================================

# Makefile for building vmcs_host for running on vc02
# Target is vmcs_host.a

LIB_NAME    := vmcs_host

LIB_SRC     := vc_vchi_gencmd.c
LIB_SRC     += vc_vchi_filesys.c
LIB_SRC     += vcilcs_in.c vcilcs_out.c vcilcs_common.c
#LIB_SRC     += vcilcs.c # needed when not building locally hosted applications
LIB_SRC     += vc_vchi_hostreq.c
LIB_SRC     += vc_vchi_dispmanx.c
LIB_SRC     += vc_vchi_bufman.c
LIB_SRC     += vc_vchi_touch.c
LIB_SRC     += vc_vchi_tvservice.c
LIB_SRC     += vc_vchi_cecservice.c

ifeq (ENABLE_HDCP2_LOOPBACK_TEST, $(findstring ENABLE_HDCP2_LOOPBACK_TEST, $(DEFINES_GLOBAL)))
   LIB_SRC     += vc_hdcp2_service_common.c vc_vchi_hdcp2_tx_service.c vc_vchi_hdcp2_rx_service.c vc_hdcp2_service_common.c hdcp2_server_common.c
   LIB_LIBS    += middleware/crypto/crypto middleware/crypto/pkilib applications/vmcs/hdcp2service/hdcp2_tx_server applications/vmcs/hdcp2service/hdcp2_rx_server
else ifeq (HDCP2_TX_SERVICE, $(findstring HDCP2_TX_SERVICE, $(DEFINES_GLOBAL)))
   LIB_SRC     += vc_hdcp2_service_common.c vc_vchi_hdcp2_tx_service.c vc_hdcp2_service_common.c hdcp2_server_common.c
   LIB_LIBS    += middleware/crypto/crypto middleware/crypto/pkilib applications/vmcs/hdcp2service/hdcp2_tx_server
else ifeq (HDCP2_RX_SERVICE, $(findstring HDCP2_RX_SERVICE, $(DEFINES_GLOBAL)))
   LIB_SRC     += vc_hdcp2_service_common.c vc_vchi_hdcp2_rx_service.c vc_hdcp2_service_common.c hdcp2_server_common.c
   LIB_LIBS    += middleware/crypto/crypto middleware/crypto/pkilib applications/vmcs/hdcp2service/hdcp2_rx_server
endif

ifeq (WANT_PMUSERV, $(findstring WANT_PMUSERV, $(DEFINES_GLOBAL)))    
   LIB_SRC     += vc_vchi_pmu.c
endif

# vcfile is in here
LIB_VPATH   += vchi_local ../../applications/vmcs/hdcp2service
LIB_SRC     += vcfile.c

# new wizzy khronos code
LIB_LIBS    += middleware/khronos/khronos_client

LIB_DEF     :=
LIB_CFLAGS  :=
LIB_AFLAGS  :=
LIB_TYPE    := TEST

ifdef USE_VCHI
LIB_DEF += USE_VCHI
LIB_NAME := vmcs_host_vchi
endif

ifdef USE_VCHIQ_ARM
LIB_NAME    := vmcs_host_arm
LIB_LIBS    += interface/vchiq_arm/vchiq_local
endif

ifdef USE_OPENWFC
 LIB_SRC += vc_vchi_openwfc.c owfnativestream.c
 LIB_IPATH += ../../opensrc/middleware/openwf/khronos_include \
              ../../opensrc/middleware/openwf/SI_Common/include \
              ../../opensrc/middleware/openwf/SI_Adaptation/include
endif
