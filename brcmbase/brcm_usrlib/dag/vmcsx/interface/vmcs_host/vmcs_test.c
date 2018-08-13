/* ============================================================================
Copyright (c) 2008-2014, Broadcom Corporation
All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
============================================================================ */
#include <stdio.h>
#include "interface/vchiq_arm/vchiq.h"
#include "interface/vchi/vchi.h"
#include "interface/vcos/vcos.h"
#include "interface/vmcs_host/vcilcs.h"
//#include "interface/vchi/vchi.h"
#include "host_applications/framework/common/host_ilcore.h"
#include "vcgencmd.h"
#include "vchost.h"


ILCS_SERVICE_T *il_service_global;

extern void do_stripes_default(void);
extern int do_blocks_test(void);
extern void do_playback_api_test(void);

int main(int argc, char **argv)
{
   VCHIQ_INSTANCE_T vchiq_instance;
   VCHI_INSTANCE_T initialise_instance;
   VCHI_CONNECTION_T *connection;

   int success = -1;
   ILCS_CONFIG_T config;
   char response[ 128 ];

   printf("vcos_init\n");
   vcos_init();

   if (vchiq_initialise(&vchiq_instance) != VCHIQ_SUCCESS)
   {
      printf("* failed to open vchiq instance\n");
      return -1;
   }

   // initialise the OS abstraction layer
   os_init();

   // initialise the mphi driver

   // mphi_get_func_table()->init();

   // initialise the vchi layer

   printf("vchi_initialise\n");
   success = vchi_initialise( &initialise_instance);
   assert(success == 0);
   vchiq_instance = (VCHIQ_INSTANCE_T)initialise_instance;

   connection = vchi_create_connection(single_get_func_table(),
                                       vchi_mphi_message_driver_func_table());

   printf("vchi_connect\n");
   vchi_connect(&connection, 1, initialise_instance);

   vc_vchi_gencmd_init(initialise_instance, &connection, 1);
   vc_vchi_filesys_init(initialise_instance, &connection, 1);

   if ( success == 0 )
   {
      success = vc_gencmd( response, sizeof(response), "set_vll_dir /sd/vlls" );
      vcos_assert( success == 0 );
   }

   printf("vcilcs_config\n");
   vcilcs_config(&config);
   
   printf("ilcs_init\n");
   il_service_global = ilcs_init(vchiq_instance, &config, 0, host_OMX_SetILCSState);

   printf("do_stripes\n");
   do_stripes_default();

   printf("do_blocks_test\n");
   do_blocks_test();

   printf("do_playback_api_test\n");
   do_playback_api_test();

   return 0;
}
