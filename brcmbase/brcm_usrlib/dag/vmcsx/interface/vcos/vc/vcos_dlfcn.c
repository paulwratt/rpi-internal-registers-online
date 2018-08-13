/* ============================================================================
Copyright (c) 2010-2014, Broadcom Corporation
All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
============================================================================ */

#include "interface/vcos/vcos.h"
#include "interface/vcos/vcos_dlfcn.h"
#include "middleware/dlloader/dlfcn.h"
#include "filesystem/filesys.h"

void *vcos_dlopen(const char *name, int mode)
{
   void *vll_handle;

   //filesys_register();

   vll_handle = dlopen(name, mode);
   
   return vll_handle;
}

void (*vcos_dlsym(void *handle, const char *name))()
{
   void (*symbol)();
   
   symbol = dlsym(handle, name);

   // Note that we intentionally call dldone here to encourage
   // VLLs with only a single entry-point! If you find this a 
   // problem you, should use dlshared_vll_load instead.
   dldone(handle);
   
   return symbol;
}

int vcos_dlclose (void *handle)
{
   dlclose(handle);
   return 0;
}

int vcos_dlerror(int *err, char *buf, size_t buflen)
{
   // not really threadsafe!
   const char *errmsg = dlerror();

   vcos_assert(buflen > 0);

   if (errmsg)
   {
      *err = -1;
      strncpy(buf, errmsg, buflen);
      buf[buflen-1] = '\0';
   }
   else
   {
      *err = 0;
      buf[0] = '\0';
   }
   return 0;
}




