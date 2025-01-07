//
// Created by dugch on 2025-01-05.
//

#include "Renderer.h"

#include <cassert>
#include <GLES/egl.h>
#include <GLES3/gl3.h>

#include "logging.h"
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"

constexpr const char* VertexCode = R"(#version 300 es
precision mediump float; //specifies that openGL should use medium precision

layout (location=0) in vec2 a_pos; //specifies that the 0 index element is vec2
layout (location=1) in vec2 t_pos; //species the location on the texture to put in this location

uniform mat4 projection;

uniform mat4 model;

out vec2 tex_coords;

void main() {
    gl_Position = projection * model * vec4(a_pos, 0, 1.0f); //tells openGL to draw in this position
    tex_coords = t_pos;
}
)";
constexpr const char* FragmentCode = R"(#version 300 es
precision mediump float; //specifies that openGL should use medium precision

in vec2 tex_coords;

uniform sampler2D tex; //specifies a texture to sample from

out vec4 frag_color;

void main(){
    frag_color = texture(tex, tex_coords);
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

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    struct Vertex {
        glm::vec2 position;
        glm::vec2 tex_position;
    };

    //defines vertexs to render (will be moved elsewhere later
    Vertex verticies[] = {
            {{-0.5, 0.5f}, {0.0f, 0.0f}},
            {{-0.5f, -0.5f}, {0.0f, 1.0f}},
            {{0.5f, -0.5f}, {1.0f, 1.0f}},
            {{0.5f, 0.5f}, {1.0f, 0.0f}}
    };

    uint32_t indices[] = {
            0, 1, 2,
            0, 3, 2
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

    //creates an index buffer for drawing with
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    //generates a vertex array object and binds it to be used
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    //specifies the attributes for the verticies array in GPU memory
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, position));
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, tex_position));
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

    glUseProgram(shaderProgram);

    //gets links for the model and projection uniform matrices
    ProjectionLink = glGetUniformLocation(shaderProgram, "projection");
    ModelLink = glGetUniformLocation(shaderProgram, "model");

    //assign the texture var to use texture 0
    glUniform1i(glGetUniformLocation(shaderProgram, "tex"), 0);

    tex = std::make_unique<Texture>(app->activity->assetManager, "android_robot.png");

    LOGI("texture is %dx%d", tex->get_width(), tex->get_height());

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

    float invAspect = (float) height / (float) width;

    glm::mat4 projection = glm::ortho(-1.0f, 1.0f, -invAspect, invAspect);
    glm::mat4 model{1};
    //model = glm::rotate(model, glm::quarter_pi<float>() * 3.0f, {0.0f, 0.0f, 1.0f});

    //informs openGL that this program is being used
    glUseProgram(shaderProgram);

    //specifies model and projection matrices
    glUniformMatrix4fv(ProjectionLink, 1, GL_FALSE, glm::value_ptr(projection));
    glUniformMatrix4fv(ModelLink, 1, GL_FALSE, glm::value_ptr(model));

    glBindVertexArray(vao);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

    //swaps the surface buffer onto the screen
    auto res = eglSwapBuffers(display, surface);
    assert(res);

}//Renderer::doFrame
