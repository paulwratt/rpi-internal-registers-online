/* ============================================================================
Copyright (c) 2008-2014, Broadcom Corporation
All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
============================================================================ */

/*
 * Semantics for events
 *
 * They should be the same as Windows auto-reset events.
 *
 * If you signal an event, then it will return to unsignalled once one
 * listener has woken up. Other listeners will *not* be woken up.
 */

#include <stdio.h>
#include "interface/vcos/vcos.h"
#include "vcos_test.h"

#ifdef VCOS_HAVE_EVENT

#if VCOS_HAVE_RTOS
   #define MAX_WAITERS 4
#else
   #define MAX_WAITERS 1
#endif
static VCOS_MUTEX_T lock;
static int n_woken;
static VCOS_EVENT_T event;

static void *multiple_waiter_worker(void *cxt)
{
   vcos_event_wait(&event);
   vcos_mutex_lock(&lock);
   n_woken++;
   vcos_mutex_unlock(&lock);
   return 0;
}


/* multiple people waiting, only one should be woken */

static int multiple_event_waiters(void)
{
   int i, passed = 1;
   VCOS_THREAD_T threads[MAX_WAITERS];

   vcos_mutex_create(&lock,"multevw");
   vcos_event_create(&event,NULL);

   for (i=0; i<MAX_WAITERS; i++)
   {
      vcos_thread_create(threads+i,"",NULL,multiple_waiter_worker,NULL);
   }
   vcos_sleep(50);

   for (i=0; i<MAX_WAITERS; i++)
   {
      vcos_event_signal(&event);
      vcos_sleep(50);
      if (n_woken != i+1)
      {
         vcos_log("waiter %d: wrong number woken: got %d not 1", i, n_woken);
         vcos_assert(0);
         passed = 0;
      }
   }
   vcos_event_delete(&event);
   vcos_mutex_delete(&lock);

   for (i=0; i<MAX_WAITERS; i++)
      vcos_thread_join(threads+i,NULL);

   return passed;
}

static int no_waiters_worker_woken;

static void *no_waiters_worker(void *cxt)
{
   VCOS_EVENT_T *ev = cxt;
   vcos_event_wait(ev);
   no_waiters_worker_woken = 1;
   return 0;
}

/* no-one waiting, when one thread waits it should immediately wake up.
 */
static int no_waiters(void)
{
   int passed = 1;
   VCOS_THREAD_T th;
   VCOS_EVENT_T event;
   vcos_event_create(&event,"");
   vcos_event_signal(&event);

   vcos_thread_create(&th, "",NULL,no_waiters_worker,&event);

   vcos_thread_join(&th,NULL);
   if (no_waiters_worker_woken != 1)
   {
      vcos_log("thread woken up but woken = %d", no_waiters_worker_woken);
      passed = 0;
   }

   vcos_event_delete(&event);
   return passed;
}

int try_event_got_it;

static void *event_try_worker(void *arg) {
   VCOS_EVENT_T *e = arg;
   VCOS_STATUS_T st = vcos_event_try(e);
   try_event_got_it = st == VCOS_SUCCESS ? 1 : 0;
   return NULL;
}

static int try_event(void)
{
   int passed = 1;
   VCOS_THREAD_T th;
   VCOS_EVENT_T ev;
   vcos_event_create(&ev, "");
   vcos_thread_create(&th, "", NULL, event_try_worker, &ev);
   vcos_thread_join(&th, NULL);
   if (try_event_got_it)
   {
      vcos_log("thread got the event even though it was not signalled");
      passed = 0;
   }
   else
   {
      vcos_log("try: ok when event is unsignalled");
   }

   vcos_event_signal(&ev);
   vcos_thread_create(&th, "", NULL, event_try_worker, &ev);
   vcos_thread_join(&th, NULL);

   if (!try_event_got_it)
   {
      vcos_log("thread did not get the event though it was signalled");
      passed = 0;
   }
   else
   {
      vcos_log("try: ok when event is signalled");
   }

   vcos_event_delete(&ev);
   return passed;
}

void run_event_tests(int *run, int *passed)
{
   RUN_TEST(run,passed,multiple_event_waiters);
   RUN_TEST(run,passed,no_waiters);
   RUN_TEST(run,passed,try_event);
}

#else

void run_event_tests(int *run, int *passed)
{
}

#endif

