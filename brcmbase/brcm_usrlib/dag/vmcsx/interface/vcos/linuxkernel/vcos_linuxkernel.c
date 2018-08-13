/* ============================================================================
Copyright (c) 2009-2014, Broadcom Corporation
All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
============================================================================ */

#define  VCOS_INLINE_BODIES
#include "interface/vcos/vcos.h"

#ifndef VCOS_DEFAULT_STACK_SIZE
#define VCOS_DEFAULT_STACK_SIZE 4096
#endif

static VCOS_THREAD_ATTR_T default_attrs = {
   0,
   VCOS_DEFAULT_STACK_SIZE,
};

DECLARE_MUTEX(lock);

VCOS_STATUS_T vcos_thread_create(VCOS_THREAD_T *thread,
                                 const char *name,
                                 VCOS_THREAD_ATTR_T *attrs,
                                 VCOS_THREAD_ENTRY_FN_T entry,
                                 void *arg)
{
   *thread = kthread_run((int (*)(void *))entry, arg, name);
   vcos_assert(*thread != NULL);
   return VCOS_SUCCESS;
}

void vcos_thread_join(VCOS_THREAD_T *thread,
                             void **pData)
{
   void *ret = (void *)kthread_stop(*thread);
   if (pData)
      *pData = ret;
}

uint32_t vcos_getmicrosecs( void )
{
   struct timeval tv;
   do_gettimeofday(&tv);
   return (tv.tv_sec*1000000) + tv.tv_usec;
}

void vcos_timer_init(void)
{
}

void vcos_log_impl(const VCOS_LOG_CAT_T *cat, const char *fmt, ...)
{
   va_list ap;
   if (cat->flags.want_prefix)
      printk("%s:", cat->name);

   va_start(ap,fmt);
   vprintk(fmt, ap);
   va_end(ap);
   printk("\n");
}

void vcos_vlog_impl(const VCOS_LOG_CAT_T *cat, const char *fmt, va_list args)
{
   if (cat->flags.want_prefix)
      printk("%s:", cat->name);
   vprintk(fmt, args);
   printk("\n");
}

VCOS_STATUS_T vcos_init(void)
{
   return VCOS_SUCCESS;
}

void vcos_deinit(void)
{
}

void vcos_global_lock(void)
{
   down(&lock);
}

void vcos_global_unlock(void)
{
   up(&lock);
}

void vcos_thread_exit(void *arg)
{
   /* This isn't possible */
   vcos_assert(0);
}


void vcos_thread_attr_init(VCOS_THREAD_ATTR_T *attrs)
{
   *attrs = default_attrs;
}

void _vcos_task_timer_set(void (*pfn)(void*), void *cxt, VCOS_UNSIGNED ms)
{
   vcos_assert(0); /* no timers on event groups yet */
}

void _vcos_task_timer_cancel(void)
{
}

int vcos_snprintf(char *buf, size_t buflen, const char *fmt, ...)
{
   int ret;
   va_list ap;
   va_start(ap,fmt);
   ret = vsnprintf(buf, buflen, fmt, ap);
   va_end(ap);
   return ret;
}

int vcos_llthread_running(VCOS_THREAD_T *t) {
   vcos_assert(0);   // this function only exists as a nasty hack for the video codecs!
   return 1;
}

