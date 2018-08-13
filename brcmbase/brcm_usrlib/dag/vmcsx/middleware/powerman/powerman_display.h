/* ============================================================================
Copyright (c) 2005-2014, Broadcom Corporation
All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
============================================================================ */

#ifndef POWERMAN_DISPLAY_H
#define POWERMAN_DISPLAY_H

#include "vcinclude/common.h"

/******************************************************************************
 Global Types
 *****************************************************************************/
typedef struct POWERMAN_DISPLAY_S * POWERMAN_DISPLAY_HANDLE_T;

//metrics
typedef enum
{
   POWERMAN_DISPLAY_METRIC_MIN,

   POWERMAN_DISPLAY_METRIC_MHZ = 1,
   POWERMAN_DISPLAY_METRIC_PERCENT,

   POWERMAN_DISPLAY_METRIC_MAX

} POWERMAN_DISPLAY_METRIC_T;

//macro to check the range of the metric
#define POWERMAN_DISPLAY_METRIC_CHECK( metric ) (( (metric) > POWERMAN_DISPLAY_METRIC_MIN) && ( (metric) < POWERMAN_DISPLAY_METRIC_MAX) )


//value types
typedef enum
{
   POWERMAN_DISPLAY_TYPE_MIN,

   POWERMAN_DISPLAY_TYPE_USED = 1,
   POWERMAN_DISPLAY_TYPE_FREE,
   POWERMAN_DISPLAY_TYPE_CORE,

   POWERMAN_DISPLAY_TYPE_MAX

} POWERMAN_DISPLAY_TYPE_T;

//macro to check the range of the metric
#define POWERMAN_DISPLAY_TYPE_CHECK( type ) (( (type) > POWERMAN_DISPLAY_TYPE_MIN) && ( (type) < POWERMAN_DISPLAY_TYPE_MAX) )

/******************************************************************************
 Global Funcs
 *****************************************************************************/

/* Routine to create a powerman display */
extern int powerman_display_create( POWERMAN_DISPLAY_HANDLE_T *powerman_display_handle );

/* Routine to delete a powerman display */
extern int powerman_display_delete( const POWERMAN_DISPLAY_HANDLE_T powerman_display_handle );

/* Routine to set the display region for the powerman stats */
extern int powerman_display_set_region(const POWERMAN_DISPLAY_HANDLE_T powerman_display_handle,
                                       const uint8_t display_number,
                                       const uint16_t x,
                                       const uint16_t y,
                                       const uint16_t width,
                                       const uint16_t height,
                                       const POWERMAN_DISPLAY_METRIC_T metric,
                                       const POWERMAN_DISPLAY_TYPE_T type );

/* routine to set the overrun stat */
int powerman_display_set_overrun_stat( const POWERMAN_DISPLAY_HANDLE_T powerman_display_handle,
                                       const uint32_t overrun_stat );

/* Routine to update the stats in the display */
extern int powerman_display_update_stats( const POWERMAN_DISPLAY_HANDLE_T powerman_display_handle,
                                          const uint32_t core_mhz, const uint32_t free );

#endif /* POWERMAN_DISPLAY_H */

/****************************** End of file **********************************/
