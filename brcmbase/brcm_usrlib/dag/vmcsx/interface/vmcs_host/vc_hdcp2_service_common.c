/* ============================================================================
Copyright (c) 2011-2014, Broadcom Corporation
All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
============================================================================ */
#include "vc_hdcp2_service_common.h"

VCOS_LOG_CAT_T hdcp2_log_category;

/**
 * <DFN>vc_hdcp2_service_wait_for_reply</DFN> blocks until a response comes back
 * from Videocore.
 *
 * @param client_handle is the vchi client handle
 * 
 * @param sema is the signalling semaphore indicating a reply
 *
 * @param response is the reponse buffer
 *
 * @param max_length is the maximum length of the buffer
 *
 * @param actual_length will be set to the actual length of the buffer (or zero if error)
 *
 * @return zero if successful, vchi error code otherwise
 */
int32_t vc_hdcp2_service_wait_for_reply(VCHI_SERVICE_HANDLE_T client_handle,
                                        VCOS_SEMAPHORE_T *sema,
                                        void *response, uint32_t max_length, uint32_t *actual_length) {
   int32_t success = 0;
   VCOS_STATUS_T status;
   uint32_t length_read = 0;
   vcos_assert(sema);
   vcos_assert(response && max_length);
   do {
      //TODO : we need to deal with messages coming through on more than one connections properly
      //At the moment it will always try to read the first connection if there is something there
      //Check if there is something in the queue, if so return immediately
      //otherwise wait for the semaphore and read again
      success = vchi_msg_dequeue( client_handle, response, max_length, &length_read, VCHI_FLAGS_NONE );
   } while( length_read == 0 || (status = vcos_semaphore_trywait(sema)) != VCOS_SUCCESS);

   if(vcos_verify(*actual_length)) {
      *actual_length = (success == 0)? length_read : 0;
   }
   return success;
}

/**
 * <DFN>vc_hdcp2_service_send_command</DFN> sends a command which has no reply to Videocore
 * side HDCP2 service.
 *
 * @param client_handle is the vchi client handle
 *
 * @param sema is the locking semaphore to protect the buffer
 * 
 * @param command is the command (VC_HDCP2_CMD_CODE_T in vc_hdcp2service_defs.h)
 *
 * @param buffer is the command buffer to be sent
 *
 * @param length is the size of buffer in bytes
 *
 * @return zero if successful, VCHI error code if failed
 */
int32_t vc_hdcp2_service_send_command(VCHI_SERVICE_HANDLE_T client_handle,
                                      VCOS_SEMAPHORE_T *sema,
                                      uint32_t command, void *buffer, uint32_t length) {
   VCHI_MSG_VECTOR_T vector[] = { {&command, sizeof(command)},
                                  {buffer, length} };
   VCOS_STATUS_T status;
   int32_t success = 0;
   vcos_assert(sema);
   status = vcos_semaphore_wait(sema);
   vcos_assert(status == VCOS_SUCCESS);
   success = vchi_msg_queuev( client_handle, vector, sizeof(vector)/sizeof(vector[0]),
                              VCHI_FLAGS_BLOCK_UNTIL_QUEUED, NULL );
   status = vcos_semaphore_post(sema);
   vcos_assert(status == VCOS_SUCCESS);
   return success;
}

/**
 * <DFN>vc_hdcp2_service_send_command_reply</DFN> sends a command and waits for a reply from
 * Videocore side HDCP2 service.
 *
 * @param client_handle is the vchi client handle
 *
 * @param lock_sema is the locking semaphore to protect the buffer
 *
 * @param reply_sema is the signalling semaphore for the reply
 *
 * @param command is the command (VC_HDCP2_CMD_CODE_T in vc_hdcp2service_defs.h)
 *
 * @param buffer is the command buffer to be sent
 *
 * @param length is the size of buffer in bytes
 *
 * @param response is the reponse buffer
 *
 * @param response_length is the maximum length of the response buffer
 *
 * @param actual_length is set to the actual length of the message
 *
 * @return zero if successful, VCHI error code if failed
 */
int32_t vc_hdcp2_service_send_command_reply(VCHI_SERVICE_HANDLE_T client_handle,
                                            VCOS_SEMAPHORE_T *lock_sema,
                                            VCOS_SEMAPHORE_T *reply_sema,
                                            uint32_t command, 
                                            void *buffer, uint32_t length,
                                            void *response, uint32_t response_length,
                                            uint32_t *actual_length) {

   int32_t success = vc_hdcp2_service_send_command(client_handle,
                                                   lock_sema,
                                                   command, buffer, length);

   if(vcos_verify(!success)) {
      VCOS_STATUS_T status = vcos_semaphore_wait(lock_sema);
      vcos_assert(status == VCOS_SUCCESS);
      success = vc_hdcp2_service_wait_for_reply(client_handle,
                                                reply_sema,
                                                response, response_length, actual_length);
      status = vcos_semaphore_post(lock_sema);
      vcos_assert(status == VCOS_SUCCESS);
   }
   return success;
}
                                                   
