/* ============================================================================
Copyright (c) 2010-2014, Broadcom Corporation
All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
============================================================================ */

#ifndef VC_VCHI_PMU_H
#define VC_VCHI_PMU_H

#include "vchost_config.h"
#include "interface/vchi/vchi.h"

#if !defined(VCHPRE_)
#error VCHPRE_ not defined!
#endif
#if !defined(VCHPOST_)
#error VCHPOST_ not defined!
#endif

/*-----------------------------------------------------------------------------*/
// Values returned by vc_pmu_get_battery_status()
typedef enum
{
   BATT_NONE,
   BATT_LOW,
   BATT_VERY_LOW,
   BATT_OK,
   BATT_CHARGED
} PMU_BATTERY_STATE_T;

/*-----------------------------------------------------------------------------*/

VCHPRE_ void VCHPOST_ vc_vchi_pmu_init
   (VCHI_INSTANCE_T initialise_instance, VCHI_CONNECTION_T **connections, uint32_t num_connections);

VCHPRE_ int32_t VCHPOST_ vc_pmu_enable_usb(uint32_t enable);
VCHPRE_ int32_t VCHPOST_ vc_pmu_usb_connected(void);
VCHPRE_ uint32_t VCHPOST_ vc_pmu_get_battery_status(void);

#endif /* VC_VCHI_PMU_H */
/* End of file */
/*-----------------------------------------------------------------------------*/
