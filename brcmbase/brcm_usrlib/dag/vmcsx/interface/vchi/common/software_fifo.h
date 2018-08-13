/* ============================================================================
Copyright (c) 2008-2014, Broadcom Corporation
All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
============================================================================ */

#ifndef SOFTWARE_FIFO_H_
#define SOFTWARE_FIFO_H_

#include "interface/vchi/os/os.h"

typedef struct {
   uint8_t        *malloc_address;
   uint8_t        *base_address;
   uint8_t        *read_ptr;
   uint8_t        *write_ptr;
   uint32_t       size;
   uint32_t       bytes_read;
   uint32_t       bytes_written;
   // semaphore to protect this structure
   OS_SEMAPHORE_T software_fifo_semaphore;
} SOFTWARE_FIFO_HANDLE_T;


int32_t software_fifo_create( const uint32_t size, int alignment, SOFTWARE_FIFO_HANDLE_T *handle );
int32_t software_fifo_destroy( SOFTWARE_FIFO_HANDLE_T *handle );

int32_t software_fifo_read( SOFTWARE_FIFO_HANDLE_T *handle, void *data, const uint32_t data_size );
int32_t software_fifo_write( SOFTWARE_FIFO_HANDLE_T *handle, const void *data, const uint32_t data_size );

int32_t software_fifo_data_available( SOFTWARE_FIFO_HANDLE_T *handle );
int32_t software_fifo_room_available( SOFTWARE_FIFO_HANDLE_T *handle );

int32_t software_fifo_peek( SOFTWARE_FIFO_HANDLE_T *handle, void *data, const uint32_t data_size );
int32_t software_fifo_remove( SOFTWARE_FIFO_HANDLE_T *handle, const uint32_t data_size );

int32_t software_fifo_protect( SOFTWARE_FIFO_HANDLE_T *handle );
int32_t software_fifo_unprotect( SOFTWARE_FIFO_HANDLE_T *handle );

#endif // SOFTWARE_FIFO_H_
