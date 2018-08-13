/* ============================================================================
Copyright (c) 2001-2014, Broadcom Corporation
All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
============================================================================ */


/*
*
*****************************************************************************
*
*  vchost_int.h
*
*  PURPOSE:
*
*   This file contains private definitions to be shared amongst the VC02
*   Host Interface driver files.
*
*  NOTES:
*
*****************************************************************************/


#if !defined( VCHOST_INT_H )
#define VCHOST_INT_H

/* ---- Include Files ---------------------------------------------------- */

#include <linux/list.h>
#include <cfg_global.h>

#include <vc3host-port.h>

/* ---- Constants and Types ---------------------------------------------- */

typedef struct
{
    unsigned            magic;
    int                 index;
    struct list_head    node;
    wait_queue_head_t   waitQ;
    volatile int        flag;

#if VC_EVENT_DEBUG
    const char         *createFileName;
    int                 createLineNum;
    const char         *fileName;
    char                fileNameBuf[ 200 ];
    int                 lineNum;
#endif

} Event_t;

typedef struct
{
    unsigned            magic;
    struct list_head    node;
    struct semaphore    sem;

#if VC_LOCK_DEBUG
    const char         *fileName;
    char                fileNameBuf[ 200 ];
    int                 lineNum;
#endif

} Lock_t;

/* ---- Variable Externs ------------------------------------------------- */

extern   int   gLcdPrintStats;

extern   int   gVcGmtOffset;

/* ---- Function Prototypes ---------------------------------------------- */

void *vc_lock_create_on( struct list_head *list );

void vc_lock_free_list( struct list_head *list );


void vc_event_free_list( struct list_head *list );

#if VC_EVENT_DEBUG
#define vc_event_create_on( list )    vc_event_create_on_dbg( list, __FILE__, __LINE__ )

void *vc_event_create_on_dbg( struct list_head *list, const char *fileName, int lineNum );
#else
void *vc_event_create_on( struct list_head *list );

#define  vc_event_create_on_dbg( list, fileName, lineNum )  vc_create_on( list ) 

#endif

void vc_adjust_thread_priority( int *requestedPriority );


#endif  // VCHOST_INT_H
