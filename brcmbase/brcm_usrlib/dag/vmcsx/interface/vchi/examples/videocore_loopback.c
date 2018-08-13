/* ============================================================================
Copyright (c) 2008-2014, Broadcom Corporation
All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
============================================================================ */

/******************************************************************************
Private typedefs
******************************************************************************/

/******************************************************************************
Static data
******************************************************************************/

static VCHI_OS_SEMAPHORE_T semaphore;

/******************************************************************************
Static func forward
******************************************************************************/

void videocore_loopback_callback(   void *callback_param,
                                    const VCHI_CALLBACK_REASON_T reason,
                                    const void *msg_handle );

/******************************************************************************
Global functions
******************************************************************************/

/***********************************************************
 * Name: 
 * 
 * Arguments: 
 *       
 *
 * Description: 
 *
 * Returns: 
 *
 ***********************************************************/
int32_t videocore_loopback( void )
{
   VCHI_SERVICE_CREATE_HANDLE_T loopback_service_create_handle;
   VCHI_SERVICE_HANDLE_T loopback_service_handle;
   void *data_rcv = NULL;
   uint32_t data_size = 128;

   success = vchi_initialise( a0fifo_get_instance(), 1 );
   assert(success >= 0 );

   success = vchi_service_create( "LoopBack", 1024, 1024, &loopback_service_create_handle );
   assert( success >= 0 );

   success = vchi_os_semaphore_create( &semaphore, OS_SEMAPHORE_BUSYWAIT );
   assert( success >= 0 );

   success = vchi_os_semaphore_obtain( semaphore );
   assert(success >= 0 );

   success = vchi_service_open( "LoopBack", 1 /*block until service is ready */, &loopback_service_handle, videocore_loopback_callback, &semaphore );
   assert(success >= 0 );

   data_rcv = malloc( data_size );

   while( 1 )
   {
      uint32_t data_read = 0;

      //wait for the message to be returned
      success = vchi_os_semaphore_obtain( semaphore );
      assert(success >= 0 );      

      success = vchi_service_dequeue_msg( loopback_service_handle, data_rcv, data_size, 0, &data_read );
      assert(success >= 0 );

      success = vchi_service_queue_msg( loopback_service_handle, data_send, data_size, NULL, 0 );
      assert(success >= 0 );      
   }
}

void videocore_loopback_callback(   void *callback_param,
                                    const VCHI_CALLBACK_REASON_T reason,
                                    const void *msg_handle )
{
   VCHI_OS_SEMAPHORE_T *semaphore = (VCHI_OS_SEMAPHORE_T *)callback_param;

   assert( reason == VCHI_CALLBACK_REASON_DATA_AVAILABLE );

   if( semaphore != NULL )
   {
      int32_t success = vchi_os_semaphore_release( *semaphore );
      assert( success >= 0 );
   }   
}

/****************************** End of file ***********************************/
