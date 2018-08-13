/* ============================================================================
Copyright (c) 2007-2014, Broadcom Corporation
All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
============================================================================ */

#ifndef CRYPTOHW_H
#define CRYPTOHW_H

#define CRYPTO_READFIELD(_w,_f) (((unsigned long)(_w) / _f) & (_f##_MASK))

enum
{
// BCM2707 has no crypto hardware but supports RNG interrupt
//   CRYPTO_ISR_RNG_INT = (1 << 2),
   CRYPTO_ISR_PKA_INT = (1 << 1),
   CRYPTO_ISR_SPU_INT = (1 << 0),
   
//   CRYPTO_IMR_RNG_INT_EN = (1 << 2),
   CRYPTO_IMR_PKA_INT_EN = (1 << 1),
   CRYPTO_IMR_SPU_INT_EN = (1 << 0),
   
   CRYPTO_CLK_CFG_PKA_CLK        = (1 << 8),
   CRYPTO_CLK_CFG_PKA_CLK_MASK   = 3,
   CRYPTO_CLK_CFG_PKA_CLK_FULL   = 0,
   CRYPTO_CLK_CFG_PKA_CLK_HALF   = 1,
   CRYPTO_CLK_CFG_PKA_CLK_THIRD  = 2,
   CRYPTO_CLK_CFG_PKA_CLK_DISABLED  = 3,

   CRYPTO_CLK_CFG_SPU_CLK        = (1 << 4),
   CRYPTO_CLK_CFG_SPU_CLK_MASK   = 3,
   CRYPTO_CLK_CFG_SPU_CLK_FULL   = 0,
   CRYPTO_CLK_CFG_SPU_CLK_HALF   = 1,
   CRYPTO_CLK_CFG_SPU_CLK_THIRD  = 2,
   CRYPTO_CLK_CFG_SPU_CLK_DISABLED  = 3,
 
   CRYPTO_CLK_CFG_OTP_CLKDIV      = (1 << 0),
   CRYPTO_CLK_CFG_OTP_CLKDIV_MASK = 0xf,
   
   CRYPTO_CLK_CFG_OTP_CLKDIV_2    = 0x0,
   CRYPTO_CLK_CFG_OTP_CLKDIV_4    = 0x1,
   CRYPTO_CLK_CFG_OTP_CLKDIV_6    = 0x2,
   CRYPTO_CLK_CFG_OTP_CLKDIV_8    = 0x3,
   CRYPTO_CLK_CFG_OTP_CLKDIV_10   = 0x4,
   CRYPTO_CLK_CFG_OTP_CLKDIV_12   = 0x5,
   CRYPTO_CLK_CFG_OTP_CLKDIV_14   = 0x6,
   CRYPTO_CLK_CFG_OTP_CLKDIV_16   = 0x7,
   CRYPTO_CLK_CFG_OTP_CLKDIV_18   = 0x8,
   CRYPTO_CLK_CFG_OTP_CLKDIV_20   = 0x9,
   CRYPTO_CLK_CFG_OTP_CLKDIV_22   = 0xa,
   CRYPTO_CLK_CFG_OTP_CLKDIV_24   = 0xb,
   CRYPTO_CLK_CFG_OTP_CLKDIV_26   = 0xc,
   CRYPTO_CLK_CFG_OTP_CLKDIV_28   = 0xd,
   CRYPTO_CLK_CFG_OTP_CLKDIV_30   = 0xe,
   CRYPTO_CLK_CFG_OTP_CLKDIV_32   = 0xf,
   
   CRYPTO_SIMCTRL_DEBUG  = (1 << 0),
   CRYPTO_SIMCTRL_SECURE = (1 << 1)
};

#endif
