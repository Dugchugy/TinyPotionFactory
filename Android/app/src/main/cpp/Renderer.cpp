//
// Created by dugch on 2025-01-03.
//

#include "Renderer.h"
#include "logging.h"

#include <GLES2/gl2.h>

//initalizes display and creates openGL context
void Renderer::init(android_app *app) {
    //creates settings for using EGL
    constexpr EGLint attribs[] = {
            EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
            EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
            EGL_BLUE_SIZE, 8,
            EGL_GREEN_SIZE, 8,
            EGL_RED_SIZE, 8,
            EGL_DEPTH_SIZE, 24,
            EGL_NONE
    };

    //gets the display for the app
    display = eglGetDisplay( EGL_DEFAULT_DISPLAY);

    //attempts to setup the display
    if(eglInitialize(display, nullptr, nullptr) == EGL_FALSE){
        LOGD("Failed to initialize EGL display! Error code: %d", eglGetError());
    }

    //sets the configuration as needed
    EGLint numConfigs;
    eglChooseConfig(display, attribs,
                    &config, 1, &numConfigs);

    //creates a surface to render on linked to the app window
    surface = eglCreateWindowSurface(display, config, app->window, nullptr);

    //checks the surface was created successfully
    if(surface == EGL_NO_SURFACE){
        LOGD("Failed to create surface! error code %d", eglGetError());
    }

    //creates the context attributes
    EGLint contextArribs[] = {
            EGL_CONTEXT_CLIENT_VERSION, 2, EGL_NONE
    };

    //creates a new context with the passed attributes
    context = eglCreateContext(display, config, nullptr, contextArribs);

    if(context == EGL_NO_CONTEXT ){
        LOGD("Failed to create context! error code %d", eglGetError());
    }

    //makes this context the current context
    eglMakeCurrent(display, surface, surface, context);

    //sets clear color to a white background
    glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
} //Renderer::init

void Renderer::beginUpdate() {
    //clears the screen
    glClear( GL_COLOR_BUFFER_BIT);

} //Renderer::beginUpdate

void Renderer::endUpdate() {

    //swaps the buffers on the display and surface (why???)
    if(eglSwapBuffers(display, surface) == EGL_FALSE){
        LOGD("EGL error while swapping buffers! error code: %d", eglGetError());
    }

} //Renderer::endUpdate