/* ============================================================================
Copyright (c) 2006-2014, Broadcom Corporation
All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
============================================================================ */

#ifndef _HARDWARE_H
#define _HARDWARE_H
#if defined(_ATHENA_)
   #define HW_REGISTER_RW(addr) ((addr))
#else   
   #define HW_REGISTER_RW(addr) (*(volatile unsigned long *)(addr))
#endif   
#define HW_REGISTER_RO(addr) (*(const volatile unsigned long *)(addr))

#define HW_POINTER_TO_ADDRESS(pointer) ((uint32_t)(void *)&(pointer))


#if defined (__VC4_BIG_ISLAND__)
   #include "hardware_vc4_bigisland.h"
#elif defined (__VIDEOCORE4__)
   #include "hardware_vc4.h"
#elif defined (__VIDEOCORE3__)
   #include "hardware_vc3.h"
#elif defined (__VIDEOCORE2__)
   #include "hardware_vc2.h"
#elif defined (_VIDEOCORE)
   #include "hardware_vc.h"
#elif !defined (_WIN32)
   #error "No valid processor defined in hardware.h!"
#endif // __VIDEOCORE4__ && __VIDEOCORE3__ && __VIDEOCORE2__ && _VIDEOCORE && _WIN32


#endif /* _HARDWARE_H */
