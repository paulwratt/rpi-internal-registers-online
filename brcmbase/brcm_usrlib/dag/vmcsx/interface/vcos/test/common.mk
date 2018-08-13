# =============================================================================
# Copyright (c) 2009-2014, Broadcom Corporation
# All rights reserved.
# Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
# 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
# 3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
# =============================================================================

SOURCES=timer.c eventgroup.c semaphore.c thread.c main.c library.c mutex.c named_sem.c event.c
SOURCES += logging.c

SOURCES_threadx  = abi.c queue.c cpp.cpp atomic_flags.c
SOURCES_nucleus  = abi.c queue.c
SOURCES_pthreads =
SOURCES_win32    = atomic_flags.c
SOURCES_none     =

SOURCES += $(SOURCES_$(RTOS))

SOURCES_none=timer.c main.c library.c semaphore.c abi.c cpp.cpp eventgroup.c mutex.c named_sem.c event.c atomic_flags.c
SOURCES_none += msgqueue.c

SOURCES += msgqueue.c
VPATH += ../generic

# CPP_SOURCES = cpp.cpp

