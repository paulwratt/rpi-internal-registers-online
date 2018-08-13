/* ============================================================================
Copyright (c) 2010-2014, Broadcom Corporation
All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
============================================================================ */

#ifndef WFC_INT_H
#define WFC_INT_H

#include "interface/khronos/include/WF/wfc.h"

//==============================================================================

#define NO_ATTRIBUTES   NULL

// Values for rectangle types
#define WFC_RECT_X      0
#define WFC_RECT_Y      1
#define WFC_RECT_WIDTH  2
#define WFC_RECT_HEIGHT 3

#define WFC_RECT_SIZE   4

// Values for context background colour
#define WFC_BG_CLR_RED     0
#define WFC_BG_CLR_GREEN   1
#define WFC_BG_CLR_BLUE    2
#define WFC_BG_CLR_ALPHA   3

#define WFC_BG_CLR_SIZE    4

//==============================================================================

// Attributes associated with each element
typedef struct
{
   WFCint         dest_rect[WFC_RECT_SIZE];
   WFCSource      source_handle;
   WFCfloat       src_rect[WFC_RECT_SIZE];
   WFCboolean     flip;
   WFCRotation    rotation;
   WFCScaleFilter scale_filter;
   WFCbitfield    transparency_types;
   WFCfloat       global_alpha;
   WFCMask        mask_handle;
} WFC_ELEMENT_ATTRIB_T;

// Default values for elements
#define WFC_ELEMENT_ATTRIB_DEFAULT \
{ \
   {0, 0, 0, 0}, \
   WFC_INVALID_HANDLE, \
   {0.0, 0.0, 0.0, 0.0}, \
   WFC_FALSE, \
   WFC_ROTATION_0, \
   WFC_SCALE_FILTER_NONE, \
   0, \
   1.0, \
   WFC_INVALID_HANDLE \
}

// Attributes associated with each context
typedef struct
{
   WFCRotation    rotation;
   WFCfloat       background_clr[WFC_BG_CLR_SIZE];
} WFC_CONTEXT_ATTRIB_T;

// Default values for contexts
#define WFC_CONTEXT_ATTRIB_DEFAULT \
{ \
   WFC_ROTATION_0, \
   {0.0, 0.0, 0.0, 1.0} \
}

#endif /* WFC_INT_H */

//==============================================================================
