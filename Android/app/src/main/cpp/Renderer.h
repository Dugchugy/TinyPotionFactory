//
// Created by dugch on 2025-01-03.
//

#ifndef TINY_POTION_FACTORY_RENDERER_H
#define TINY_POTION_FACTORY_RENDERER_H

#include <game-activity/native_app_glue/android_native_app_glue.h>
#include <EGL/egl.h>
#include "Shader.h"

class Renderer {
public:
    //initalizes openGL context (using openGL ES
    void init(android_app* app);

    void beginUpdate();
    void endUpdate();

private:
    Shader shader;

    EGLDisplay display;
    EGLConfig  config;
    EGLSurface surface;
    EGLContext context;
};


#endif //TINY_POTION_FACTORY_RENDERER_H
