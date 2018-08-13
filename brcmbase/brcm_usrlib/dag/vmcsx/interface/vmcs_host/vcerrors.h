/* ============================================================================
Copyright (c) 2006-2014, Broadcom Corporation
All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
============================================================================ */

#ifndef VCERRORS_H
#define VCERRORS_H

// Enum to aid interpreting errors returned by VideoCore in general command responses.
// Their meanings are indicated in the comments, but only a few of them are ever likely
// to be of interest to end users. The error number should be returned in
// a "error=<number>" field of the response.

typedef enum {
   VC_ERR_NONE = 0,    // no error has occurred

   VC_ERR_NO_CMD,      // no such command exists
   VC_ERR_BAD_PARAMS,  // command parameters were bad in some way
   VC_ERR_BAD_CMD,     // command is inappropriate in some way

   VC_ERR_NO_MEMORY,   // insufficient memory to continue with request
   VC_ERR_NO_VLL,      // a required VLL is missing
   VC_ERR_BAD_VLL,     // VLL is bad in some way

   VC_ERR_NO_SOURCE,     // a named file/url does not appear to exist
   VC_ERR_UNIMPL_SOURCE, // the data in the source is unsupported/unimplemented
   VC_ERR_BAD_SOURCE,    // the file/url is incomplete or invalid in some way

   VC_ERR_AUDIO_BUSY,  // VideoCore audio was required but is in use

   VC_ERR_INTERRUPTED, // some operation has been interrupted

   VC_ERR_NO_SPACE,    // insufficient space on filesystem or similar

   VC_ERR_NO_SIGNAL,   // used by DMB to indicate a transmission signal failure

   VC_ERR_MAX_FILE_SIZE, // file write has reached the max file size allowed

   // New error types of error should be added right here:
   // ...

   VC_ERR_UNKNOWN=9999 // another kind of error has occurred
} VC_ERR_T;

#endif
