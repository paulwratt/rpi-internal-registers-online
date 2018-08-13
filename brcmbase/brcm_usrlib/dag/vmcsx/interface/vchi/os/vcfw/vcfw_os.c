/* ============================================================================
Copyright (c) 2008-2014, Broadcom Corporation
All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
============================================================================ */

#include <string.h>
#include <stdlib.h>

#include "vcinclude/common.h"

#include "vcfw/rtos/rtos.h"
#include "vcfw/logging/logging.h"

#include "interface/vchi/os/os.h"

#include "helpers/vcsuspend/vcsuspend.h"

#ifdef __CC_ARM
#define inline __inline
#endif

/******************************************************************************
Private typedefs
******************************************************************************/

/******************************************************************************
Static data
******************************************************************************/

/******************************************************************************
Static func forwards
******************************************************************************/

#define rtos_quick_get_cpu_number() ((_vasm("version %D") >> 16) & 1)
static inline int32_t rtos_quick_disable_interrupts(void)
{
#ifdef __CC_ARM
   assert(0);
   return 0;
#else
   int32_t sr = _vasm("mov %D, %sr");
   _nop(); 
   _di();
   return sr;
#endif
}
static inline void rtos_quick_restore_interrupts(int32_t sr)
{
   if (sr & (1<<30))
      _ei();
   //else
   //   _di();
}

/******************************************************************************
Global functions
******************************************************************************/


/***********************************************************
 * Name: os_halt
 *
 * Arguments: void
 *
 * Description: Routine to prepare VideoCore for shutdown -
 *              called when VCHI DISCONNECT message received
 *
 * Returns: does not return
 *
 ***********************************************************/
int32_t os_halt( void )
{
#ifdef ANDROID
   return 0;
#else
   int32_t r = vcsuspend_halt();
   os_assert(0); // shouldn't reach here
   return r;
#endif
}

/***********************************************************
 * Name: os_suspend
 *
 * Arguments: void
 *
 * Description: Routine to suspend VideoCore -
 *              called when VCHI DISCONNECT message received
 *
 * Returns: int32_t - success == 0
 *
 ***********************************************************/
int32_t os_suspend( void )
{
#ifdef ANDROID
   return 0;
#else
   int32_t r = vcsuspend_suspend();
   os_assert(r == 0);
   return r;
#endif
}

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
#ifndef WIN32
void os_logging_message(const char *format, ...)
{
   va_list args;
   va_start(args, format);
   vlogging_message(LOGGING_VCHI, format, args);
   va_end(args);
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
   logging_assert(file, func, line, msg);
}
#endif

/****************************** End of file ***********************************/
