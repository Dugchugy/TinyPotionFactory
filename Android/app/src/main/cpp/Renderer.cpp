//
// Created by dugch on 2025-01-05.
//

#include "Renderer.h"

#include <cassert>
#include <GLES/egl.h>
#include <GLES3/gl3.h>

#include "logging.h"

constexpr const char* VertexCode = R"(#version 300 es
precision mediump float; //specifies that openGL should use medium precision

layout (location=0) in vec2 a_pos; //specifies that the 0 index element is vec2
layout (location=1) in vec3 col; //reads the color as an input?

out vec3 color;

void main() {
    gl_Position = vec4(a_pos, 0, 1.0f); //tells openGL to draw in this position
    color = col;
}
)";
constexpr const char* FragmentCode = R"(#version 300 es
precision mediump float; //specifies that openGL should use medium precision

in vec3 color;
out vec4 frag_color;

void main(){
    frag_color = vec4(color, 1.0f);
}
)";

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
            0, 0.5f, 1.0f, 0.0f, 0.0f,
            -0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
            0.5f, -0.5f, 0.0f, 0.0f, 1.0f
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
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), nullptr);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*) (2 * sizeof(float )));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    //===================
    //compiles shaders
    //===================

    auto compileShaders = [](GLenum type, const char* src)-> GLuint {
        //creates a shader with the specified source and type and compiles it
        GLuint shader = glCreateShader(type);
        glShaderSource(shader, 1, &src, nullptr);
        glCompileShader(shader);

        //checks the shader compiled correctly
        GLint success;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if(!success) {
            char infoLog[1024];
            glGetShaderInfoLog(shader, 1024, nullptr, infoLog);
            LOGE("Failed to compile shader! info log: \n %s", infoLog);
        }

        return shader;

    };

    GLuint vert = compileShaders(GL_VERTEX_SHADER, VertexCode);
    GLuint frag = compileShaders(GL_FRAGMENT_SHADER, FragmentCode);

    //creates a program linking the shaders and links it
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vert);
    glAttachShader(shaderProgram, frag);
    glLinkProgram(shaderProgram);

    //checks that it links correctly
    GLint success;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success) {
        char infoLog[1024];
        glGetProgramInfoLog(shaderProgram, 1024, nullptr, infoLog);
        LOGE("Failed to link shader Program! info log: \n %s", infoLog);
    }

    //deletes the shaders now that they're linked
    glDeleteShader(vert);
    glDeleteShader(frag);


} //Renderer()

Renderer::~Renderer() {

    glDeleteProgram(shaderProgram);

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

    //informs openGL that this program is being used
    glUseProgram(shaderProgram);

    glBindVertexArray(vao);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    //swaps the surface buffer onto the screen
    auto res = eglSwapBuffers(display, surface);
    assert(res);

}//Renderer::doFrame
