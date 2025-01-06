//
// Created by dugch on 2025-01-05.
//

#include "Renderer.h"

#include <cassert>
#include <GLES/egl.h>
#include <GLES3/gl3.h>

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

    //defines vertexs to render (will be moved elsewhere later
    float verticies[] = {
            0, 0.5f,
            -0.5f, -0.5f,
            0.5f, -0.5f
    };

    //===============================
    //Defines data passed to shaders
    //===============================

    //creates a memory buffer in the GPU's memory (stores it in vbo
    glGenBuffers(1, &vbo);

    //tells openGL to use the vbo buffer
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    //moves data from CPU to GPU (STATIC_DRAW: uploads only once and uses forever
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);

    //generates a vertex array object and binds it to be used
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    //specifies the attributes for the verticies array in GPU memory
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);

} //Renderer()

Renderer::~Renderer() {

    //destroys egl items
    eglDestroyContext(display, context);
    eglDestroySurface(display, surface);
    eglTerminate(display);

    glDeleteBuffers(1, &vbo);

    glDeleteVertexArrays(1, &vao);

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
