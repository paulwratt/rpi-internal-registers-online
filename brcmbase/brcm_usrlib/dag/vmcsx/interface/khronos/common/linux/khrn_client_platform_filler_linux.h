/* ============================================================================
Copyright (c) 2009-2014, Broadcom Corporation
All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
============================================================================ */

#ifndef KHRN_CLIENT_PLATFORM_LINUX_H
#define KHRN_CLIENT_PLATFORM_LINUX_H

#include "interface/vcos/vcos.h"

typedef int KHR_STATUS_T;
#define KHR_SUCCESS  0

typedef pthread_mutex_t PLATFORM_MUTEX_T;

VCOS_STATUS_T platform_mutex_create(PLATFORM_MUTEX_T *mtx);
void platform_mutex_destroy(PLATFORM_MUTEX_T *mutex);
void platform_mutex_acquire(PLATFORM_MUTEX_T *mutex);
void platform_mutex_release(PLATFORM_MUTEX_T *mutex);


typedef sem_t PLATFORM_SEMAPHORE_T;

VCOS_STATUS_T khronos_platform_semaphore_create(PLATFORM_SEMAPHORE_T *sem, int name[3], int count);
void khronos_platform_semaphore_destroy(PLATFORM_SEMAPHORE_T *semaphore);
void khronos_platform_semaphore_acquire(PLATFORM_SEMAPHORE_T *semaphore);
void khronos_platform_semaphore_release(PLATFORM_SEMAPHORE_T *semaphore);


typedef pthread_key_t PLATFORM_TLS_T;

VCOS_STATUS_T platform_tls_create(PLATFORM_TLS_T *tls);
void platform_tls_destroy(PLATFORM_TLS_T tls);
void platform_tls_set(PLATFORM_TLS_T tls, void *v);
void *platform_tls_get(PLATFORM_TLS_T tls);
void platform_tls_remove(PLATFORM_TLS_T tls);

#endif


