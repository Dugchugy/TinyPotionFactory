//
// Created by dugch on 2025-01-05.
//

#include "Renderer.h"

#include <cassert>
#include <GLES/egl.h>

#include "logging.h"


Renderer::Renderer(android_app* app) {

    //gets the display from the system
    display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    assert(display);

    //initializes the display
    EGLBoolean result = eglInitialize(display, nullptr, nullptr);
    assert(result == EGL_TRUE);

    EGLint attribs[] = {
            EGL_RENDERABLE_TYPE, EGL_OPENGL_ES3_BIT,
            EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
            EGL_RED_SIZE, 8,
            EGL_BLUE_SIZE, 8,
            EGL_GREEN_SIZE, 8,
        EGL_NONE
    };

    EGLint num_configs;

    eglChooseConfig(display, attribs, &config, 1, &num_configs);

    assert(num_configs == 1);

    surface = eglCreateWindowSurface(display, config, app->window, nullptr);

    assert(surface != EGL_NO_SURFACE);

    EGLint Contattribs[] = {
            EGL_CONTEXT_CLIENT_VERSION, 3,
            EGL_NONE
    };

    context = eglCreateContext(display, config, nullptr, Contattribs);

    assert(context != EGL_NO_CONTEXT);

    result = eglMakeCurrent(display, surface, surface, context);

    assert(result == EGL_TRUE);

    LOGI("Renderer has been initialized!");

    glClearColor(0.0f, 1.0f, 0.0f, 1.0f);

} //Renderer()

Renderer::~Renderer() {

    //destroys egl items
    eglDestroyContext(display, context);
    eglDestroySurface(display, surface);
    eglTerminate(display);

} //~Renderer()

void Renderer::doFrame() {


    int height, width;
    eglQuerySurface(display, surface, EGL_WIDTH, &width);
    eglQuerySurface(display, surface, EGL_HEIGHT, &height);

    //sets teh viewport to cover the whole screen
    glViewport(0, 0, width, height);

    //clears the screen
    glClear(GL_COLOR_BUFFER_BIT);

    //swaps the surface buffer onto the screen
    auto res = eglSwapBuffers(display, surface);
    assert(res);

}//Renderer::doFrame
