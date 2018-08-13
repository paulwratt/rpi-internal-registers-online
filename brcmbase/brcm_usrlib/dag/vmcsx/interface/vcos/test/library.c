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

#ifdef LATER

int time_test()
{
   int passed = 1;
   int32_t then, now, diff;

   then = platform_get_ticks();
   platform_sleep(5);
   now = platform_get_ticks();

   diff = now - then;
   if(diff < 4 || diff > 20)
      passed = 0;

   then = platform_get_ticks();

   diff = then - now;
   if(diff < 0 || diff > 5)
      passed = 0;

   platform_sleep(50);
   now = platform_get_ticks();

   diff = now - then;
   if(diff < 40 || diff > 70)
      passed = 0;

   return passed;
}  
#endif

static int malloc_test()
{
   int passed = 1;
   int size;

   for(size = 1; size < 4096; size = (size*3)+7)
   {
      uint8_t *mem = vcos_malloc(size, "test");

      if(!mem)
         passed = 0;
      else
      {
         int i;
         for(i=0; i<size; i++)
            mem[i] = i&0xff;
         vcos_free(mem);
      }
   }

   if(passed)
   {
      uint8_t *mem1, *mem2, *mem3;
      mem1 = vcos_malloc(1<<10, "test1");
      mem2 = vcos_malloc(1<<11, "test2");
      mem3 = vcos_malloc(1<<16, "test3");

      if(!mem1 || !mem2 || !mem3 || mem1==mem2 || mem1==mem3 || mem2==mem3)
         passed = 0;

      if(mem1) vcos_free(mem1);
      if(mem2) vcos_free(mem2);
      if(mem3) vcos_free(mem3);
   }

   return passed;
}

static int calloc_test()
{
   int passed = 1;
   int num, size;

   for(num = 1; num < 10; num++)
   {
      for(size = 1; size < 512; size = (size*3)+7)
      {
         uint8_t *buf = vcos_calloc(num, size, "test4");
         int i;

         if(!buf)
            passed = 0;
         else
         {
            for(i=0; i<size*num; i++)
            {
               if(buf[i])
                  passed = 0;
               buf[i] = i & 0xff;
            }
            vcos_free(buf);
         }
      }
   }

   return passed;
}

static int malloc_aligned_test()
{
   int passed = 1;
   uint32_t size, align;

   for(size = 1; size < 1024; size = (size*3)+7)
   {
      for(align = 1; align < 4096; align<<=1)
      {
         uint8_t *buf = vcos_malloc_aligned(size, align, "test5");
         
         if(!buf)
            passed = 0;
         {
            if((unsigned long) buf & (align-1))
               passed = 0;

            memset(buf,0,size);

            vcos_free(buf);
         }
      }
   }

   return passed;
}
   

void run_library_tests(int *run, int *passed)
{
   /*(*run)++; (*passed) += stricmp_test();*/
   /*(*run)++; (*passed) += time_test();*/
   (*run)++; (*passed) += malloc_test();
   (*run)++; (*passed) += calloc_test();
   (*run)++; (*passed) += malloc_aligned_test();
}


