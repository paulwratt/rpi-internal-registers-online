/* ============================================================================
Copyright (c) 2008-2014, Broadcom Corporation
All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
============================================================================ */

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <process.h>

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "vcinclude/common.h"

#include "interface/vchi/os/os.h"
#include "interface/vcos/vcos.h"

/******************************************************************************
Private typedefs
******************************************************************************/

struct {
   int sem;
   int sem_cnt;
   int sem_glb;
   int event;
   int cond;
   int alloc;
} stats_obtain, stats_release;

#define STATS(type, obtain_release) stats_##obtain_release.type++

void os_print_stats(void)
{
   printf("S:%u %u SC:%u %u SG:%u %u E:%u %u C:%u %u A:%u %u\n", stats_obtain.sem, stats_release.sem, 
   stats_obtain.sem_cnt, stats_release.sem_cnt, 
   stats_obtain.sem_glb, stats_release.sem_glb, 
   stats_obtain.event, stats_release.event, 
   stats_obtain.cond, stats_release.cond,
   stats_obtain.alloc, stats_release.alloc);
}


/******************************************************************************
Static data
******************************************************************************/

/******************************************************************************
Static func forwards
******************************************************************************/

/******************************************************************************
Global functions
******************************************************************************/


/***********************************************************
 * Name: os_logging_message
 *
 * Arguments: int level - which logging channel to use
              const char *format - printf-style formatting string
              ... - varargs
 *
 * Description: Routine to write message to log
 *
 * Returns: void
 *
 ***********************************************************/

void os_logging_message(const char *format, ...)
{
#ifndef NDEBUG
   va_list args;
   va_start(args, format);
   vfprintf(stderr, format, args);
   va_end(args);

   putc('\n', stderr);
}

/***********************************************************
 * Name: os_assert_failure
 * 
 * Arguments: const char *msg - message for log (normally condition text)
 *            const char *file - filename of translation unit
 *            const char *func - name of function (NULL if not available)
 *            int line - line number
 */
void os_assert_failure(const char *msg, const char *file, const char *func, int line)
{
   fprintf(stderr, "In %s::%s(%d)\n%s\n", file, func, line, msg);
#if defined(_MSC_VER)                     // Visual C define equivalent types
   __asm { int 3 }
#endif //#if defined(_MSC_VER)                     // Visual C define equivalent types
   abort();
}

int32_t os_halt( void )
{
   os_assert(0); // shouldn't reach here
   return 0;
}

int32_t os_suspend( void )
{
   os_assert(0); // shouldn't reach here
   return 0;
}


/****************************** End of file ***********************************/
