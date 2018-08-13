/* ============================================================================
Copyright (c) 2008-2014, Broadcom Corporation
All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
============================================================================ */
#include "interface/vmcs_host/wfc.h"
#include "interface/vmcs_host/owfstream.h"
#include "vc_vchi_bufman.h"

WFCNativeStreamType
createNativeStream (WFCint width,
                    WFCint height,
                    WFCint numBuffers)
{
  WFCNativeStreamType stream =
    owfNativeStreamCreateImageStream (width,
                                      height,
                                      OWF_IMAGE_ARGB8888,
                                      OWF_FALSE,
                                      OWF_TRUE,
                                      4,
                                      numBuffers);
  return stream;
}

void
writeImageToNativeStream (WFCNativeStreamType stream, WFCint width,
                          WFCint height, WFCint stride, void* data)
{
  OWFNativeStreamBuffer buffer;
  BUFMANX_HANDLE_T dummy_handle;
  BUFMANX_IMAGE_T image;
  VC_RECT_T src_rect, dst_rect;
  DISPMANX_RESOURCE_HANDLE_T resource;
  int status;

  buffer = owfNativeStreamAcquireWriteBuffer (stream);
  resource = owfNativeStreamGetResource(stream, buffer);
  image.type = FRAME_HOST_IMAGE_EFormatRgbA32;
  //    image.type = FRAME_HOST_IMAGE_EFormatRgb888;
  image.width = width;
  image.height = height;
  image.pitch = stride;
  image.bpp = 32;
  image.size = stride * height;
  image.pixels = data;
  src_rect.x = 0;
  src_rect.y = 0;
  src_rect.width = width << 16;
  src_rect.height = height << 16;
  dst_rect.x = 0;
  dst_rect.y = 0;
  dst_rect.width = width;
  dst_rect.height = height;
  status = vc_bufmanx_push_blocking (&dummy_handle, &image, resource,
                                     &src_rect, &dst_rect, 0);
  /* USBDK: the handle is created on the bridge */
  vcos_assert (status == 0);
  owfNativeStreamReleaseWriteBuffer (stream, buffer,
                                     EGL_DEFAULT_DISPLAY,
                                     EGL_NO_SYNC_KHR);
}

void
destroyNativeStream (WFCNativeStreamType stream)
{
  owfNativeStreamDestroy(stream);
}
