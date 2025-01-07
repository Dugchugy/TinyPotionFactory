//
// Created by dugch on 2025-01-05.
//

#ifndef TINY_POTION_FACTORY_RENDERER_H
#define TINY_POTION_FACTORY_RENDERER_H

#include <GLES/egl.h>
#include <game-activity/native_app_glue/android_native_app_glue.h>

class Renderer {
public:
    Renderer(android_app* app);
    ~Renderer();

    void doFrame();

private:
    EGLDisplay display;
    EGLConfig config;
    EGLSurface  surface;
    EGLContext  context;

    //voa = vertex area: used to draw, vbo = vertex buffer: stores type of vertex data
    //in GPU memory
    GLuint vao{}, vbo{}, ebo{};
    GLuint shaderProgram{};

    GLint ProjectionLink;

};


#endif //TINY_POTION_FACTORY_RENDERER_H
