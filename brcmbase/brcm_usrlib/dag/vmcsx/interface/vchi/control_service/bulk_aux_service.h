/* ============================================================================
Copyright (c) 2008-2014, Broadcom Corporation
All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
============================================================================ */

#ifndef BULK_AUX_SERVICE_H_
#define BULK_AUX_SERVICE_H_

#include "interface/vchi/os/types.h"

/******************************************************************************
 Global defs
 *****************************************************************************/

#define BULX_SERVICE_OFFSET     0 // service ID
#define BULX_SIZE_OFFSET        4 // size of entire transfer
#define BULX_CHUNKSIZE_OFFSET   8 // needed for some interfaces
#define BULX_CRC_OFFSET        12 // CRC of entire transfer (after reassembly)
#define BULX_DATA_SIZE_OFFSET  16 // amount of data actually transferred over data channel
#define BULX_DATA_SHIFT_OFFSET 20 // how many bytes receiver should shift that data by (signed)
#define BULX_CHANNEL_OFFSET    22 // which channel data is being sent on
#define BULX_RESERVED_OFFSET   23 //  reserved byte
#define BULX_HEAD_SIZE_OFFSET  24 // how many bytes of head data [0..HEAD_SIZE) enclosed
#define BULX_TAIL_SIZE_OFFSET  26 // how many bytes of tail data [SIZE-TAIL_SIZE..SIZE) enclosed
#define BULX_HEADER_SIZE       28


/******************************************************************************
 Global functions
 *****************************************************************************/

// Create the bulk aux services for our connection
int32_t vchi_bulk_aux_service_init( VCHI_CONNECTION_T **connections,
                                    const uint32_t num_connections,
                                    void **state );

// Close the connections we have previously init'ed
int32_t vchi_bulk_aux_service_close( void );

// Fill in a header structure, returning the length
size_t vchi_bulk_aux_service_form_header( void *dest,
                                          size_t dest_len,
                                          fourcc_t service_id,
                                          MESSAGE_TX_CHANNEL_T channel,
                                          uint32_t total_size,
                                          uint32_t chunk_size,
                                          uint32_t crc,
                                          uint32_t data_size,
                                          int16_t data_shift,
                                          uint16_t head_bytes,
                                          uint16_t tail_bytes );
                                         
#endif /* BULK_AUX_SERVICE_H_ */

/****************************** End of file **********************************/
