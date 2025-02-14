#pragma once

#include "../defines.hpp"

namespace Events {
    void geometry(void *data, wl_output *output, int32_t x, int32_t y, int32_t width_mm, int32_t height_mm, int32_t subpixel, const char *make, const char *model, int32_t transform);

    void mode(void *data, wl_output *output, uint32_t flags, int32_t width, int32_t height, int32_t refresh);

    void done(void *data, wl_output *wl_output);

    void scale(void *data, wl_output *wl_output, int32_t scale);

    void name(void *data, wl_output *wl_output, const char *name);

    void description(void *data, wl_output *wl_output, const char *description);

    void ls_configure(void *data, zwlr_layer_surface_v1 *surface, uint32_t serial, uint32_t width, uint32_t height);

    void handleGlobal(void *data, struct wl_registry *registry, uint32_t name, const char *interface, uint32_t version);

    void handleGlobalRemove(void *data, struct wl_registry *registry, uint32_t name);

    inline const wl_output_listener outputListener = {.geometry = geometry, .mode = mode, .done = done, .scale = scale, .name = name, .description = description};

    inline const zwlr_layer_surface_v1_listener layersurfaceListener = { .configure = ls_configure };

    inline const struct wl_registry_listener registryListener = { .global = handleGlobal, .global_remove = handleGlobalRemove };
}
