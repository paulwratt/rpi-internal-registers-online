/* ============================================================================
Copyright (c) 2007-2014, Broadcom Corporation
All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
============================================================================ */

#ifndef VCILCS_INTERN_H
#define VCILCS_INTERN_H

// used by host functions that implement the IL component API
// to execute a marshalled function on a VideoCore component
VCHPRE_ int VCHPOST_ vc_ilcs_execute_function(IL_FUNCTION_T func, void *data, int len, void *data2, int len2,
                                              void *bulk, int bulk_len, void *resp);
VCHPRE_ OMX_ERRORTYPE VCHPOST_ vc_ilcs_pass_buffer(IL_FUNCTION_T func, void *reference, OMX_BUFFERHEADERTYPE *pBuffer);
VCHPRE_ OMX_BUFFERHEADERTYPE * VCHPOST_ vc_ilcs_receive_buffer(void *call, int clen, OMX_COMPONENTTYPE **pComp);

// functions that implement incoming functions calls
// from VideoCore components to host based components
VCHPRE_ void VCHPOST_ vcil_in_get_state(void *call, int clen, void *resp, int *rlen);
VCHPRE_ void VCHPOST_ vcil_in_get_parameter(void *call, int clen, void *resp, int *rlen);
VCHPRE_ void VCHPOST_ vcil_in_set_parameter(void *call, int clen, void *resp, int *rlen);
VCHPRE_ void VCHPOST_ vcil_in_get_config(void *call, int clen, void *resp, int *rlen);
VCHPRE_ void VCHPOST_ vcil_in_set_config(void *call, int clen, void *resp, int *rlen);
VCHPRE_ void VCHPOST_ vcil_in_use_buffer(void *call, int clen, void *resp, int *rlen);
VCHPRE_ void VCHPOST_ vcil_in_free_buffer(void *call, int clen, void *resp, int *rlen);
VCHPRE_ void VCHPOST_ vcil_in_empty_this_buffer(void *call, int clen, void *resp, int *rlen);
VCHPRE_ void VCHPOST_ vcil_in_fill_this_buffer(void *call, int clen, void *resp, int *rlen);
VCHPRE_ void VCHPOST_ vcil_in_get_component_version(void *call, int clen, void *resp, int *rlen);
VCHPRE_ void VCHPOST_ vcil_in_get_extension_index(void *call, int clen, void *resp, int *rlen);
VCHPRE_ void VCHPOST_ vcil_in_component_role_enum(void *call, int clen, void *resp, int *rlen);

// functions that implement callbacks from VideoCore
// components to the host core.
// The prefix is vcil_out since they implement part
// of the API that the host uses out to VideoCore
VCHPRE_ void VCHPOST_ vcil_out_event_handler(void *call, int clen, void *resp, int *rlen);
VCHPRE_ void VCHPOST_ vcil_out_empty_buffer_done(void *call, int clen, void *resp, int *rlen);
VCHPRE_ void VCHPOST_ vcil_out_fill_buffer_done(void *call, int clen, void *resp, int *rlen);

#endif // VCILCS_INTERN_H
