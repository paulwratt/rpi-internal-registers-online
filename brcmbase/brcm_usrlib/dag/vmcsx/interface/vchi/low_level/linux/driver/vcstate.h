/* ============================================================================
Copyright (c) 2006-2014, Broadcom Corporation
All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
============================================================================ */


#ifndef VC_STATE_HEADER
#define VC_STATE_HEADER

typedef enum {
	VC_POWER_STATE_OFF       = 0,
	VC_POWER_STATE_HIBERNATE = 1,
	VC_POWER_STATE_RUNNING   = 2
} VC_POWER_STATE_T;

// Identifiers for applications.
typedef enum {
	VC_APPLICATION_RINGER,
	VC_APPLICATION_FILEMGR,
	VC_APPLICATION_IMVIEWER,
	VC_APPLICATION_IMEDITOR,
	VC_APPLICATION_MPLAYER,
	VC_APPLICATION_MSTILLS,
	VC_APPLICATION_MRECORDER,
	VC_APPLICATION_DOWNLOAD,
	VC_APPLICATION_PCMPLAYER,
	VC_APPLICATION_USBMGR,
	// any new applications MUST be added here just above VC_APPLICATION_MAXNUM!
	// new applications MUST be added to the app_names table in vcstate.c
	VC_APPLICATION_MAXNUM
} VC_APPLICATION_T;

// Identifiers for different services.
typedef enum {
	VC_SERVICE_GENCMD,
	VC_SERVICE_DISPMAN,
	VC_SERVICE_FILESYS,
	VC_SERVICE_HOSTREQ,
	VC_SERVICE_DSERV,
	VC_SERVICE_MAXNUM
} VC_SERVICE_T;

// Should be called before first booting VideoCore.
int vc_state_init(void);

// NOTE: if you wish to use vc_state_set_power_state then you should avoid sending
// "power_control videocore <n>" gencmds directly as the state information is not updated when
// direct gencmds are sent.

// Prepare VideoCore to go into hibernation or power-down, prior to switching the RUN/HIB pins.
// If it's already hibernating, after setting the RUN/HIB pins back to running, can be used to
// bring VMCS out of hibernation.
// This will also start/stop all the services as necessary.
// Return non-zero for an error.
int vc_state_set_power_state(VC_POWER_STATE_T state);

// Return the current power state of VideoCore.
VC_POWER_STATE_T vc_state_get_power_state(void);

// Return >= 0 if the service given is running (returns its service number).
int vc_state_service_running(VC_SERVICE_T service);

// NOTE: if you wish to use vc_state_load/end_application then you should not send any
// load/end_application gencmds directly as the state is not recorded for direct gencmds.

// Return name to use to load an application.
const char *vc_state_application_name(VC_APPLICATION_T app);
// Start an application. Return its task id or < 0 for an error.
int vc_state_load_application(VC_APPLICATION_T app);
// End an application. Return non-zero for an error.
int vc_state_end_application(int task_id);
// Return the task_id of an application (assumes only one instance of any app).
// Return -1 for error.
int vc_state_application_task_id(VC_APPLICATION_T app);
// Return non-zero if the application with the given task_id is still running.
int vc_state_application_running(int task_id);

#endif
