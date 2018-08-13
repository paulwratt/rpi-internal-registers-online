/* ============================================================================
Copyright (c) 2008-2014, Broadcom Corporation
All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
============================================================================ */

#include <string.h>  /* for strcpy/cmp, etc. */
#include <stdio.h>
#include <stdlib.h>

#include "interface/vcos/vcos.h"
#include "vcos_test.h"

#ifdef WIN32
#define SLACK  30
#else
#define SLACK  2
#endif

#ifdef VCOS_HAVE_TIMER

static void *basic_cxt;
static void basic_pfn(void *cxt)
{
   basic_cxt = cxt;
}

static int sleeping(void)
{
   int duration;
   int ret = 1;
   for (duration = 10; duration < 1000; duration *=2)
   {
      unsigned ticks = vcos_get_ms();
      int delta;
      vcos_sleep(duration);
      ticks = vcos_get_ms()-ticks;
      delta = ticks-duration;
      if (abs(delta) > SLACK*(1000/VCOS_TICKS_PER_SECOND))
      {
         vcos_log("Got %d ticks, expected %d", ticks, duration);
         ret = 0;
      }
   }
   return ret;
}

/* create a single timer, and check it does as expected */
static int basic_timer_test(void)
{
   VCOS_TIMER_T timer;
   VCOS_STATUS_T status = vcos_timer_create(&timer, "test",
                                            basic_pfn, (void*)42);

   basic_cxt = 0;
   if (status != VCOS_SUCCESS)
      return 0;

   vcos_timer_set(&timer, 100);
   vcos_sleep(200);

   if (basic_cxt != (void*)42)
      return 0;

   vcos_timer_delete(&timer);

   return 1;
}
   
/* Create 2 separate timers */
static int results[32];
static void multi_pfn(void *cxt)
{
   int *p = (int*)cxt;
   *p = 1;
}

static int multiple_timer_test(void)
{
   int passed;
   VCOS_TIMER_T timers[32];
   int i;
   memset(results,0,sizeof(results));
   for (i=0; i<32; i++)
   {
      VCOS_STATUS_T st = vcos_timer_create(timers+i,"test",multi_pfn,&results[i]);
      if (st != VCOS_SUCCESS)
         return 0;
   }

   for (i=0; i<32; i++)
   {
      vcos_timer_set(timers+i,1+i*10);
   }
   vcos_sleep(i*20);

   /* check each timer fired */
   passed = 1;
   for (i=0; i<32; i++)
   {
      if (!results[i])
      {
         vcos_log("timer %d failed to go off", i);
         passed = 0;
      }
      vcos_timer_delete(timers+i);
   }
   return passed;
}



void run_timer_tests(int *run, int *passed)
{
   RUN_TEST(run,passed,sleeping);
   RUN_TEST(run,passed,basic_timer_test);
   RUN_TEST(run,passed,multiple_timer_test);
}

#else

void run_timer_tests(int *run, int *passed) {}

#endif

