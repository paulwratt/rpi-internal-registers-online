/* ============================================================================
Copyright (c) 2006-2014, Broadcom Corporation
All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
============================================================================ */

#ifndef VCLOGGING_INT_H
#define VCLOGGING_INT_H

#define LOGGING_SYNC 'VLOG'
#define N_VCLIB_LOGS  3  //Does not include the task switch log

typedef enum {
   LOGGING_FIFO_LOG = 1,
   LOGGING_ASSERTION_LOG,
   LOGGING_TASK_LOG,
} LOG_FORMAT_T;

typedef struct {
   LOG_FORMAT_T type;
   void *log;
} LOG_DESCRIPTOR_T;

typedef struct {
   unsigned long time;
   unsigned short seq_num;
   unsigned short size;
} logging_fifo_log_msg_header_t;

typedef struct {
   char name[4];
   unsigned char *start;
   unsigned char *end;
   unsigned char *ptr;
   unsigned char *next_msg;
   logging_fifo_log_msg_header_t msg_header;
} logging_fifo_log_t;

typedef struct {
   char name[4];
   unsigned short nitems, item_size;
   unsigned long available;
   unsigned char *data;
} logging_array_log_t;


// The header at the start of the log may be one of a number of different types,
// but they all start with a common portion:

typedef unsigned long LOGGING_LOG_TYPE_T;
#define LOGGING_LOG_TYPE_VCLIB ((LOGGING_LOG_TYPE_T) 0)
#define LOGGING_LOG_TYPE_VMCS  ((LOGGING_LOG_TYPE_T) 1)

typedef struct {
   unsigned long sync;
   LOGGING_LOG_TYPE_T type;
   unsigned long version;
   void *self;
} logging_common_header_t;

typedef struct {
   logging_common_header_t common;
   unsigned long stc;
   int task_switch_log_size;
   unsigned char *task_switch_log;
   unsigned long n_logs;
   LOG_DESCRIPTOR_T assertion_log;
   LOG_DESCRIPTOR_T message_log;
   LOG_DESCRIPTOR_T task_log;

} logging_header_t;

#endif // VCLOGGING_INT_H
