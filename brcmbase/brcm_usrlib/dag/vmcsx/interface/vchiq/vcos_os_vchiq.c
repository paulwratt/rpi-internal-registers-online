/* ============================================================================
Copyright (c) 2009-2014, Broadcom Corporation
All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
============================================================================ */

#include "interface/vchiq/os.h"


/***********************************************************
 * Name: os_thread_begin
 *
 * Arguments:  VCOS_THREAD_T *thread
 *             OS_THREAD_FUNC_T func
 *             int stack
 *             void *data
 *             const char *name
 *
 * Description: Routine to create and start a thread or task for VCHIQ
 * Thread function has different arguments (void*) to os_thread_start (int,void*).
 * 
 *
 * Returns: int32_t - success == 0
 *
 ***********************************************************/
void os_thread_begin(VCOS_THREAD_T *thread, void (*func)(void*), int stack, void *data, const char *name) 
{
   VCOS_THREAD_ATTR_T attrs;
   VCOS_STATUS_T status;
   vcos_thread_attr_init(&attrs);
   vcos_thread_attr_setstacksize(&attrs, stack);
   vcos_thread_attr_setpriority(&attrs, 5); /* FIXME: should not be hardcoded */
   vcos_thread_attr_settimeslice(&attrs, 20); /* FIXME: should not be hardcoded */

   status = vcos_thread_create(thread, name, &attrs, (VCOS_THREAD_ENTRY_FN_T)func, data);
   vcos_assert(status == VCOS_SUCCESS);
}

void os_cond_init(void)
{
}
