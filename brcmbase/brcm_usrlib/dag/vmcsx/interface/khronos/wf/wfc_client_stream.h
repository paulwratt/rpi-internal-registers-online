/* ============================================================================
Copyright (c) 2010-2014, Broadcom Corporation
All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
============================================================================ */

#ifndef WF_INT_STREAM_H_
#define WF_INT_STREAM_H_

#include "helpers/vc_image/vc_image.h"

#include "interface/khronos/common/khrn_int_common.h"
#include "interface/khronos/include/WF/wfc.h"

//==============================================================================

//==============================================================================

// Create a stream able to queue the specified number of buffers, using either
// the given image properties, or an off-screen context, as a template.

#define WFC_STREAM_FLAGS_NONE          0
// Create asynchronous (KHAN) semaphore, for use with wfc_stream_await_buffer().
#define WFC_STREAM_FLAGS_ASYNC_SEM     (1 << 0)

// Create a stream, using the given stream handle (typically assigned by the
// window manager), containing the specified number of buffers, and using
// a bufman image as a template. Return zero if OK.
uint32_t wfc_stream_create_from_image
   (WFCNativeStreamType stream, VC_IMAGE_TYPE_T pixel_format,
      uint32_t width, uint32_t height, uint32_t flags);

WFCNativeStreamType wfc_stream_create_from_context
   (WFCContext context, uint32_t num_of_buffers, uint32_t flags);

// Suspend until buffer is available on the server (requires
// WFC_STREAM_FLAGS_ASYNC_SEM to have been specified on creation).
void wfc_stream_await_buffer(WFCNativeStreamType stream);

// Destroy a stream.
void wfc_stream_destroy(WFCNativeStreamType stream);

//------------------------------------------------------------------------------
// Off-screen composition functions

// Get off-screen image from stream. Fills buffer passed to it.
void wfc_stream_get_off_screen_image
   (WFCNativeStreamType stream, VC_IMAGE_T *image);

// Returns the number of buffers containing data.
uint32_t wfc_stream_num_of_ready_buffers(WFCNativeStreamType stream);

// Returns true if stream is not a valid stream.
bool wfc_stream_is_invalid(WFCNativeStreamType stream);

// TODO register notify callback. To be triggered when a new buffer is available
// for reading. Could be important for autonomous rendering.

// TODO may need some synchronisation.

//------------------------------------------------------------------------------
//==============================================================================

#endif /* WF_INT_STREAM_H_ */
