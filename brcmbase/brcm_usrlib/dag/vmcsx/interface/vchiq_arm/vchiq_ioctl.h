/* ============================================================================
Copyright (c) 2010-2014, Broadcom Corporation
All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
============================================================================ */

#ifndef VCHIQ_IOCTLS_H
#define VCHIQ_IOCTLS_H

#include <linux/ioctl.h>
#include "vchiq_if.h"

#define VCHIQ_IOC_MAGIC 0xc4
#define VCHIQ_INVALID_HANDLE -1

typedef struct {
   int fourcc;
   void *service_userdata;
   int handle;       /* OUT */
} VCHIQ_ADD_SERVICE_T, VCHIQ_OPEN_SERVICE_T;

typedef struct {
   int handle;
   int count;
   const VCHIQ_ELEMENT_T *elements;
} VCHIQ_QUEUE_MESSAGE_T;

typedef struct {
   int handle;
   const void *data;
   int size;
   void *userdata;
} VCHIQ_QUEUE_BULK_TRANSMIT_T;

typedef struct {
   int handle;
   void *data;
   int size;
   void *userdata;
} VCHIQ_QUEUE_BULK_RECEIVE_T;

typedef struct {
   VCHIQ_REASON_T reason;
   VCHIQ_HEADER_T *header;
   void *service_userdata;
   void *bulk_userdata;
} VCHIQ_COMPLETION_DATA_T;

typedef struct {
   int count;
   VCHIQ_COMPLETION_DATA_T *buf;
} VCHIQ_AWAIT_COMPLETION_T;

typedef struct {
   int handle;
   VCHIQ_HEADER_T *header;
} VCHIQ_RELEASE_MESSAGE_T;

#define VCHIQ_IOC_CONNECT              _IO(VCHIQ_IOC_MAGIC,   0)
#define VCHIQ_IOC_SHUTDOWN             _IO(VCHIQ_IOC_MAGIC,   1)
#define VCHIQ_IOC_ADD_SERVICE          _IOWR(VCHIQ_IOC_MAGIC, 2, VCHIQ_ADD_SERVICE_T)
#define VCHIQ_IOC_OPEN_SERVICE         _IOWR(VCHIQ_IOC_MAGIC, 3, VCHIQ_OPEN_SERVICE_T)
#define VCHIQ_IOC_REMOVE_SERVICE       _IO(VCHIQ_IOC_MAGIC,   4)
#define VCHIQ_IOC_QUEUE_MESSAGE        _IOW(VCHIQ_IOC_MAGIC,  5, VCHIQ_QUEUE_MESSAGE_T)
#define VCHIQ_IOC_QUEUE_BULK_TRANSMIT  _IOW(VCHIQ_IOC_MAGIC,  6, VCHIQ_QUEUE_BULK_TRANSMIT_T)
#define VCHIQ_IOC_QUEUE_BULK_RECEIVE   _IOW(VCHIQ_IOC_MAGIC,  7, VCHIQ_QUEUE_BULK_RECEIVE_T)
#define VCHIQ_IOC_AWAIT_COMPLETION     _IOW(VCHIQ_IOC_MAGIC,  8, VCHIQ_AWAIT_COMPLETION_T)
#define VCHIQ_IOC_RELEASE_MESSAGE      _IOW(VCHIQ_IOC_MAGIC,  9, VCHIQ_RELEASE_MESSAGE_T)
#define VCHIQ_IOC_MAX                  9

#endif
