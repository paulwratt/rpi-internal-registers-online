/* ============================================================================
Copyright (c) 2008-2014, Broadcom Corporation
All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
============================================================================ */

#include "interface/vchi/os/os.h"

#include <kernel.h>
#include <kern_priv.h>

#include "../vcos/vcos_os.c"
#include "../vcos/vcos_cv.c"

/******************************************************************************
Private typedefs
******************************************************************************/

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
#ifdef _DEBUG
    // Aarghh - no Kern::VPrintf
    TBuf8<256> printBuf;
    VA_LIST list;
    VA_START(list,format);
    Kern::AppendFormat(printBuf,format,list);
    Kern::Printf("VC: %S", &printBuf);
#endif
}

static void my_sprintf(TDes8 &aBuf, const char *aFormat, ...)
{
    VA_LIST list;
    VA_START(list, aFormat);
    Kern::AppendFormat(aBuf, aFormat, list);
    aBuf.Append(TChar(0));
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
   TBuf8<256> printBuf;
   if (func)
       my_sprintf(printBuf, "VC: Assertion failed: %s, function %s, file %s, line %d", msg, func, file, line);
   else
       my_sprintf(printBuf, "VC: Assertion failed: %s, file %s, line %d", msg, file, line);
       
   Kern::Fault(reinterpret_cast<const char *>(printBuf.Ptr()), KErrGeneral);
}

/***********************************************************
 * Name: rand
 *
 * Arguments:  None
 *
 * Description: Generate a random number
 *
 * Returns: int
 *
 ***********************************************************/
int rand(void)
{
   NKern::LockSystem();
   TUint32 r = Kern::Random();
   NKern::UnlockSystem();
   return int(r);
}




/****************************** End of file ***********************************/
