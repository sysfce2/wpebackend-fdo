/*
 * Copyright (C) 2017, 2018 Igalia S.L.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "interfaces.h"
#include <cstring>
#include <wpe/wpe.h>

extern "C" {

__attribute__((visibility("default")))
struct wpe_loader_interface _wpe_loader_interface = {
    [](const char* object_name) -> void* {
        if (!std::strcmp(object_name, "_wpe_renderer_host_interface"))
            return &fdo_renderer_host;

        if (!std::strcmp(object_name, "_wpe_renderer_backend_egl_interface"))
            return &fdo_renderer_backend_egl;
        if (!std::strcmp(object_name, "_wpe_renderer_backend_egl_target_interface"))
            return &fdo_renderer_backend_egl_target;
        if (!std::strcmp(object_name, "_wpe_renderer_backend_egl_offscreen_target_interface"))
            return &fdo_renderer_backend_egl_offscreen_target;

        if (!std::strcmp(object_name, "_wpe_renderer_backend_vulkan_interface"))
            return &fdo_renderer_backend_vulkan;
        if (!std::strcmp(object_name, "_wpe_renderer_backend_vulkan_target_interface"))
            return &fdo_renderer_backend_vulkan_target;

        return nullptr;
    },
};

}
