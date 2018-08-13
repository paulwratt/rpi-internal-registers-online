/* ============================================================================
Copyright (c) 2009-2014, Broadcom Corporation
All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
============================================================================ */
#include "util.h"

#include <stdlib.h>

static __inline int is_pow2(int i)
{
   return i && !(i & i - 1);
}

int vchiu_queue_init(VCHIU_QUEUE_T *queue, int size)
{
   assert(is_pow2(size));

   queue->size = size;
   queue->read = 0;
   queue->write = 0;

   os_event_create(&queue->pop);
   os_event_create(&queue->push);

   queue->storage = (VCHIQ_HEADER_T **)malloc(size * sizeof(VCHIQ_HEADER_T *));
   if(queue->storage == NULL)
   {
      assert(queue->storage != NULL);
      return 0;
   }

   return 1;
}

void vchiu_queue_delete(VCHIU_QUEUE_T *queue)
{
   free(queue->storage);
}

int vchiu_queue_is_empty(VCHIU_QUEUE_T *queue)
{
   return queue->read == queue->write;
}

void vchiu_queue_push(VCHIU_QUEUE_T *queue, VCHIQ_HEADER_T *header)
{
   while (queue->write == queue->read + queue->size)
      os_event_wait(&queue->pop);

   queue->storage[queue->write & queue->size - 1] = header;

   queue->write++;

   os_event_signal(&queue->push);
}

VCHIQ_HEADER_T *vchiu_queue_peek(VCHIU_QUEUE_T *queue)
{
   while (queue->write == queue->read)
      os_event_wait(&queue->push);

   return queue->storage[queue->read & queue->size - 1];
}

VCHIQ_HEADER_T *vchiu_queue_pop(VCHIU_QUEUE_T *queue)
{
   VCHIQ_HEADER_T *header;

   while (queue->write == queue->read)
      os_event_wait(&queue->push);

   header = queue->storage[queue->read & queue->size - 1];

   queue->read++;

   os_event_signal(&queue->pop);

   return header;
}
