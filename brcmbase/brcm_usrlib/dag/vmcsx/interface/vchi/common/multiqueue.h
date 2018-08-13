/* ============================================================================
Copyright (c) 2008-2014, Broadcom Corporation
All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
============================================================================ */

#ifndef _VCHI_MULTIQUEUE_H_
#define _VCHI_MULTIQUEUE_H_

#include "interface/vchi/os/os.h"

// The user's elements must contain a next pointer at the start of the structure,
// followed by a prev pointer, if VCHI_MQUEUE_DOUBLY_LINKED is defined.
#undef VCHI_MQUEUE_DOUBLY_LINKED

// Previously, each multiqueue contained a semaphore that was obtained during each
// list manipulation. To reduce the number of semaphore obtains and releases, you
// now have the option to pass in your own semaphore on creation.
// multiqueue then performs no semaphore claims or releases during normal
// manipulation - it is up to you to ensure your accesses are either within the
// same thread, or protected by that semaphore. multiqueue only uses the semaphore
// when blocking - the semaphore is released during a block, so must have been
// obtained before making a blocking call.

typedef struct opaque_vchi_mqueue_t VCHI_MQUEUE_T;

// Create a pool and some queues
VCHI_MQUEUE_T *vchi_mqueue_create( const char *name, int nqueues, int nelements, int element_size, OS_SEMAPHORE_T *sem );

// Destroy the pool
int32_t vchi_mqueue_destroy( VCHI_MQUEUE_T *mq );

// Get the address of the first element in the 'from' queue
void *vchi_mqueue_peek( VCHI_MQUEUE_T *mq, int from, int block );

// Get the address of the last element in the 'from' queue
void *vchi_mqueue_peek_tail( VCHI_MQUEUE_T *mq, int from, int block );

// Get the address of both the first and last elements in the 'from' queue, atomically
void vchi_mqueue_limits( VCHI_MQUEUE_T *mq, int from, void **head, void **tail, int block );

// return pointer to head of 'from' (or NULL if empty)
void *vchi_mqueue_get( VCHI_MQUEUE_T *mq, int from, int block );

// push 'element' onto the end of 'to'
void vchi_mqueue_put( VCHI_MQUEUE_T *mq, int to, void *element );

// push 'element onto the head of 'to'
void vchi_mqueue_put_head( VCHI_MQUEUE_T *mq, int to, void *element );

// Move the first element from 'from' and add it to the end of 'to'.  Return pointer to the moved element.
void *vchi_mqueue_move( VCHI_MQUEUE_T *mq, int from, int to );

// Move the first element from 'from' and add it to the head of 'to'. Return pointer to the moved element. 
void *vchi_mqueue_move_head( VCHI_MQUEUE_T *mq, int from, int to );

// Find the given element on the 'from' queue and remove it
int32_t vchi_mqueue_element_get( VCHI_MQUEUE_T *mq, int from, void *element );

// Move the given element from the 'from' queue and add it to the end of 'to'
int32_t vchi_mqueue_element_move( VCHI_MQUEUE_T *mq, int from, int to, void *element );

// Move the given element from the 'from' queue and add it to the head of 'to'
int32_t vchi_mqueue_element_move_head( VCHI_MQUEUE_T *mq, int from, int to, void *element );

// dump debug info
void vchi_mqueue_debug( VCHI_MQUEUE_T *mq );


#endif /* _VCHI_MULTIQUEUE_H_ */

/********************************** End of file ******************************************/
