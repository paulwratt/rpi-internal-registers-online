/* ============================================================================
Copyright (c) 2007-2014, Broadcom Corporation
All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
============================================================================ */



#ifndef RNGHW_H
#define RNGHW_H

#define RNG_READFIELD(_w,_f) (((unsigned long)(_w) / _f) & (_f##_MASK))

enum
{
   RNG_CTRL_RBG_2X            = (1 << 1),
   RNG_CTRL_RBG_EN            = (1 << 0),
   
   RNG_STATUS_WARM_CNT        = (1 << 0),
   RNG_STATUS_WARM_CNT_MASK   = 0xfffff,
   RNG_STATUS_VAL             = (1 << 24),
   RNG_STATUS_VAL_MASK        = 0xff,

   RNG_FF_THRESHOLD_MAX       = 0x04,

// BCM2707_B0:
// RNG interrupt no longer uses Crypto local interrupt register 
// It is connected to interrupt bit 52 : ISRC1_0 bit 52-32=20 (0x0100000)
// Mask has 6 IRQ/reg => floor(52/8)=6  Bits = 16:19 

   RNG_INT_MASK_ENABLE        = (1 << 16),
   RNG_INT_MASK_DISABLE       = (0 << 16),
   
   RNG_SIMCTRL_DEBUG          = (1 << 0),
   RNG_SIMCTRL_SECURE         = (1 << 1)
};

#endif
