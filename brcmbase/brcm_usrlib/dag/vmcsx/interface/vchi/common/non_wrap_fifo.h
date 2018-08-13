/* ============================================================================
Copyright (c) 2008-2014, Broadcom Corporation
All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
============================================================================ */

#ifndef _VCHI_NON_WRAP_FIFO_H_
#define _VCHI_NON_WRAP_FIFO_H_


typedef struct opaque_vchi_mqueue_t VCHI_NWFIFO_T;


VCHI_NWFIFO_T *non_wrap_fifo_create( const char *name, const uint32_t size, int alignment, int no_of_slots );
int32_t non_wrap_fifo_destroy( VCHI_NWFIFO_T *fifo );
int32_t non_wrap_fifo_read( VCHI_NWFIFO_T *fifo, void *data, const uint32_t max_data_size );
int32_t non_wrap_fifo_write( VCHI_NWFIFO_T *fifo, const void *data, const uint32_t data_size );
int32_t non_wrap_fifo_request_write_address( VCHI_NWFIFO_T *fifo, void **address, uint32_t size, int block );
int32_t non_wrap_fifo_write_complete( VCHI_NWFIFO_T *fifo, void *address );
int32_t non_wrap_fifo_request_read_address( VCHI_NWFIFO_T *fifo, const void **address, uint32_t *length );
int32_t non_wrap_fifo_read_complete( VCHI_NWFIFO_T *fifo, void *address );
int32_t non_wrap_fifo_remove( VCHI_NWFIFO_T *fifo, void *address );
void    non_wrap_fifo_debug( VCHI_NWFIFO_T *fifo );


#endif // _VCHI_NON_WRAP_FIFO_H_

/********************************** End of file ******************************************/
