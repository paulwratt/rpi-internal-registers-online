/* ============================================================================
Copyright (c) 2010-2014, Broadcom Corporation
All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
============================================================================ */
#ifndef _VC_HDCP2_H_
#define _VC_HDCP2_H_
#include "vcinclude/common.h"

/**
 *\file This file contains constants shared by both host side and Videocore side HDCP2
 */

/**
 * HDCP2 notifications, only 1 so far, note that hotplug is sent as a separate message
 * Reason           remark                           param1    param2
 * VC_HDCP2_AUTH    authentication state             success?  reason if failed  (success = 1 if authenticated)
 */
typedef enum {
   VC_HDCP2_AUTH = 0,
} VC_HDCP2_NOTIFY_T;

/**
 * HDCP2 hotplug state
 */
typedef enum {
   VC_HDCP2_HP_DETACHED = 0,
   VC_HDCP2_HP_ATTACHED = 1
} VC_HDCP2_HP_STATUS_T;


/**
 * HDCP2 errors
 */
typedef enum {
   HDCP2_ERROR_NONE = 0,            /**< Process completed successfully. */
   HDCP2_ERROR_INVALID_STREAM,      /**< Invalid stream (input counters) */
   HDCP2_ERROR_MISALIGNED,          /**< Misaligned buffer */
   HDCP2_ERROR_NOT_READY,           /**< Not ready for encryption */
   HDCP2_ERROR_CALLBACKS_EXCEEDED,  /**< Too many callbacks exceeded */
   HDCP2_ERROR_OUT_OF_MEMORY,       /**< Out of memory */
   HDCP2_ERROR_MAX_DEVICES_EXCEEDED,/**< Too many devices */
   HDCP2_ERROR_MAX_DEPTH_EXCEEDED,  /**< Too many levels */
   HDCP2_ERROR_INVALID_CERT,        /**< Invalid certificate */
   HDCP2_ERROR_RSA_ERROR,           /**< Error in RSA library */
   HDCP2_ERROR_RX_DETACHED,         /**< Rx detached */
   HDCP2_ERROR_H_MISMATCH,          /**< H mismatch */
   HDCP2_ERROR_L_MISMATCH,          /**< Locality check failed */
   HDCP2_ERROR_V_MISMATCH,          /**< receiver id list verify failed */
   HDCP2_ERROR_SRM_CORRUPTED,       /**< SRM integrity failed */
   HDCP2_ERROR_ID_REVOKED,          /**< receiver id revoked */
   HDCP2_ERROR_SEND_ERROR,          /**< Failed to send message */
   HDCP2_ERROR_RECEIVE_ERROR,       /**< Failed to receive message */
   HDCP2_ERROR_RNG_ERROR,           /**< rng failed */
   HDCP2_ERROR_TIMER,               /**< timer error */
   HDCP2_ERROR_TIMEOUT,             /**< Time out */
   HDCP2_ERROR_L_TIMEOUT,           /**< L timeout */
   HDCP2_ERROR_MAX                  /**< [Never returned - placeholder.] */
} HDCP2_ERROR_T;

#endif
