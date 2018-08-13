/* ============================================================================
Copyright (c) 2009-2014, Broadcom Corporation
All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
============================================================================ */


#include "interface/vcos/vcos.h"
#include "interface/vcos/vcos_msgqueue.h"
#include "vcos_test.h"

struct my_msg_t {
   int i;
};
#define MSG_N_MY_MSG (VCOS_MSG_N_PRIVATE + 0)

// create a queue, with numitems items, each item is itemsz *bytes* long.

static int create_q_test(int numitems, int itemsz)
{
   char data[64]; // should be big enough
   int passed = 0;
   int q_valid = 0;
   VCOS_QUEUE_T q;
   char *mem = vcos_malloc(numitems*itemsz,"q");
   vcos_demand(mem);
   VCOS_STATUS_T st = vcos_queue_create(&q, "q", itemsz/sizeof(VCOS_UNSIGNED), mem, numitems*itemsz/sizeof(VCOS_UNSIGNED));
   if (st != VCOS_SUCCESS)
   {
      vcos_assert(0);
      goto finish;
   }

   q_valid = 1;

   // should be able to put in these objects without it blocking
   int i;
   for (i=0; i<numitems; i++)
   {
      memset(data, i, itemsz);
      vcos_demand(sizeof(data) >= itemsz);
      st = vcos_queue_send(&q, data, 0);
      if (st != VCOS_SUCCESS)
      {
         vcos_assert(0);
         goto finish;
      }
   }

   // put in one more - it should fail
   st = vcos_queue_send(&q, data, 0);
   if (st != VCOS_EAGAIN)
   {
      vcos_assert(0);
      goto finish;
   }

   // now read something from the queue
   char dst[64];
   st = vcos_queue_receive(&q, dst, 0);
   for (i=0; i<itemsz; i++)
   {
      if (dst[i] != 0)
      {
         vcos_assert(0);
         goto finish;
      }
   }
   passed = 1;

finish:

   if (q_valid)
      vcos_queue_delete(&q);

   vcos_free(mem);
   return passed;
}

struct pair {
   int numitems;
   int itemsz;
};

void run_queue_tests(int *run, int *passed)
{
   static struct pair tests[] = {
      {1,4},
      {2,8},
      {4,4},
   };

   int i;
   for (i=0; i<sizeof(tests)/sizeof(tests[0]); i++)
   {
      (*run)++;
      *passed += create_q_test(tests[i].numitems, tests[i].itemsz);
   }
}

