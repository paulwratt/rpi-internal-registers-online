/* ============================================================================
Copyright (c) 2010-2014, Broadcom Corporation
All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
============================================================================ */

#ifndef VCHIQ_TEST_H
#define VCHIQ_TEST_H

#include "vchiq.h"

#define VERBOSE_TRACE 0

#define FUNC_FOURCC VCHIQ_MAKE_FOURCC('f','u','n','c')
#define FUN2_FOURCC VCHIQ_MAKE_FOURCC('f','u','n','2')

#define SERVICE1_DATA_SIZE 1024
#define SERVICE2_DATA_SIZE 2048
#define FUN2_MAX_DATA_SIZE 16384

#if VERBOSE_TRACE

#define EXPECT(_e, _v) if (_e != _v) { VCOS_TRACE("%d: " #_e " != " #_v, __LINE__); VCOS_BKPT; goto error_exit; } else { VCOS_TRACE("%d: " #_e " == " #_v, __LINE__); }

#define START_CALLBACK(_r, _u) \
   if (++callback_index == callback_count) { \
      if (reason != _r) { \
         VCOS_TRACE("%d: expected callback reason " #_r ", got %d", __LINE__, reason); VCOS_BKPT; goto error_exit; \
      } \
      else if ((int)VCHIQ_GET_SERVICE_USERDATA(service) != _u) { \
         VCOS_TRACE("%d: expected userdata %d, got %d", __LINE__, _u, (int)VCHIQ_GET_SERVICE_USERDATA(service)); VCOS_BKPT; goto error_exit; \
      } \
      else \
      { \
         VCOS_TRACE("%d: " #_r ", " #_u, __LINE__); \
      }

#define START_BULK_CALLBACK(_r, _u, _bu)   \
   if (++bulk_index == bulk_count) {  \
      if (reason != _r) { \
         VCOS_TRACE("%d: expected callback reason " #_r ", got %d", __LINE__, reason); VCOS_BKPT; goto error_exit; \
      } \
      else if ((int)VCHIQ_GET_SERVICE_USERDATA(service) != _u) { \
         VCOS_TRACE("%d: expected userdata %d, got %d", __LINE__, _u, (int)VCHIQ_GET_SERVICE_USERDATA(service)); VCOS_BKPT; goto error_exit; \
      } \
      else if ((int)bulk_userdata != _bu) { \
         VCOS_TRACE("%d: expected bulk_userdata %d, got %d", __LINE__, _bu, (int)bulk_userdata); VCOS_BKPT; goto error_exit; \
      } \
      else \
      { \
         VCOS_TRACE("%d: " #_r ", " #_u ", " #_bu, __LINE__); \
      }

#else

#define EXPECT(_e, _v) if (_e != _v) { VCOS_TRACE("%d: " #_e " != " #_v, __LINE__); VCOS_BKPT; goto error_exit; }

#define START_CALLBACK(_r, _u) \
   if (++callback_index == callback_count) { \
      if (reason != _r) { \
         VCOS_TRACE("%d: expected callback reason " #_r ", got %d", __LINE__, reason); VCOS_BKPT; goto error_exit; \
      } \
      else if ((int)VCHIQ_GET_SERVICE_USERDATA(service) != _u) { \
         VCOS_TRACE("%d: expected userdata %d, got %d", __LINE__, _u, (int)VCHIQ_GET_SERVICE_USERDATA(service)); VCOS_BKPT; goto error_exit; \
      }

#define START_BULK_CALLBACK(_r, _u, _bu)   \
   if (++bulk_index == bulk_count) {  \
      if (reason != _r) { \
         VCOS_TRACE("%d: expected callback reason " #_r ", got %d", __LINE__, reason); VCOS_BKPT; goto error_exit; \
      } \
      else if ((int)VCHIQ_GET_SERVICE_USERDATA(service) != _u) { \
         VCOS_TRACE("%d: expected userdata %d, got %d", __LINE__, _u, (int)VCHIQ_GET_SERVICE_USERDATA(service)); VCOS_BKPT; goto error_exit; \
      } \
      else if ((int)bulk_userdata != _bu) { \
         VCOS_TRACE("%d: expected bulkuserdata %d, got %d", __LINE__, _bu, (int)bulk_userdata); VCOS_BKPT; goto error_exit; \
      }

#endif

#define END_CALLBACK(_s) \
      return _s; \
   }

extern void vchiq_test_start_services(VCHIQ_INSTANCE_T instance);

#endif
