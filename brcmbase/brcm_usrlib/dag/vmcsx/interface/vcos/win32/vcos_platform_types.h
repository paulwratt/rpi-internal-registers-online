/* ============================================================================
Copyright (c) 2009-2014, Broadcom Corporation
All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
============================================================================ */

#ifndef VCOS_PLATFORM_TYPES_H
#define VCOS_PLATFORM_TYPES_H

#include "vcinclude/common.h"

#ifndef VCOSPRE_
   #define VCOSPRE_ extern
#endif
#define VCOSPOST_

#ifdef __GNUC__

/* Win32 assert just calls abort under GCC */
#define VCOS_ASSERT_MSG(...) _vcos_assert(__FILE__, __LINE__, __VA_ARGS__)
VCOSPRE_ void VCOSPOST_ _vcos_assert(const char *file, int line, const char *fmt, ...);

#else

#if !defined(_DEBUG) && !defined(NDEBUG)
#define NDEBUG
#endif

#include <crtdbg.h>
#define VCOS_BKPT _CrtDbgBreak()
#define VCOS_ASSERT_MSG(...) (void)((_CrtDbgReport(_CRT_ASSERT, __FILE__, __LINE__, NULL, __VA_ARGS__) != 1) || (VCOS_BKPT, 0))
/* Pre-define this macro to allow the breakpoint to be conditional based on user input */
#define VCOS_ASSERT_BKPT (void)0
#define VCOS_VERIFY_BKPT (void)0

#endif /* __GNUC__ */

#define VCOS_VERIFY_MSG(...) (VCOS_VERIFY_BKPTS ? VCOS_ASSERT_MSG(__VA_ARGS__) : (void)0)

#endif


