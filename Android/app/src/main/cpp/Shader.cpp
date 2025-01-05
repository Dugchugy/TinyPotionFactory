//
// Created by dugch on 2025-01-04.
//

#include "Shader.h"

#include "logging.h"
#include "glm/gtc/type_ptr.hpp"
#include <GLES2/gl2.h>

void Shader::fromSource(const char *vertCode, const char *fragCode) {

    int success{};
    char infoLog[512]{};

    //creates a new vertex shader with the passed code and compiles it
    uint32_t vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vertCode, nullptr);
    glCompileShader(vertex);

    //checks that the shader compiled correctly
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(vertex, 512, nullptr, infoLog);
        LOGD("Failed to compile vertex shader!\n%s\n", infoLog);
    }

    //creates a new fragment shader with the passed code and compiles it
    uint32_t fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fragCode, nullptr);
    glCompileShader(fragment);

    //checks that the shader compiled correctly
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(fragment, 512, nullptr, infoLog);
        LOGD("Failed to compile fragment shader!\n%s\n", infoLog);
    }

    //creates a gl program to allow the shaders to be called from elsewhere in the code
    id = glCreateProgram();
    glAttachShader(id, vertex);
    glAttachShader(id, fragment);
    glLinkProgram(id); //compiles shader program (sorta)

    glGetProgramiv(id, GL_LINK_STATUS, &success);
    if(!success){
        glGetProgramInfoLog(id, 512, nullptr, infoLog);
        LOGD("Failed to link shader program!\n%s\n", infoLog);
    }

    //shaders now in program, not needed separately
    glDeleteShader(vertex);
    glDeleteShader(fragment);




}// Shader::fromSource

void Shader::use() const {
    //uses the created shader program
    glUseProgram(id);
}// Shader::use

void Shader::setVec2(const std::string &name, glm::vec2 value) const {
    //sets the vector2 of the passed name to the passed value
    glUniform2f(glGetUniformLocation(id, name.c_str()),
                value.x, value.y);
}

void Shader::setVec3(const std::string &name, glm::vec3 value) const {
    //sets the vector2 of the passed name to the passed value
    glUniform3f(glGetUniformLocation(id, name.c_str()),
                value.x, value.y, value.z);
}

void Shader::setMat4(const std::string &name, glm::mat4 value) const {
    //sets the vector2 of the passed name to the passed value
    glUniformMatrix4fv(glGetUniformLocation(id, name.c_str()),
                       1, GL_FALSE, glm::value_ptr(value));
}

void Shader::setFloat(const std::string &name, float value) const {
    //sets the vector2 of the passed name to the passed value
    glUniform1f(glGetUniformLocation(id, name.c_str()),
                value);
}