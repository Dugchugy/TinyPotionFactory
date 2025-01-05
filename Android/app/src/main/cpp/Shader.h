//
// Created by dugch on 2025-01-04.
//

#ifndef TINY_POTION_FACTORY_SHADER_H
#define TINY_POTION_FACTORY_SHADER_H

#include <cstdint>
#include "glm/glm.hpp"
#include <string>

class Shader {
public:
    void fromSource(const char* vertCode, const char* fragCode);
    void use() const;

    void setVec2(const std::string &name, glm::vec2 value) const;
    void setVec3(const std::string &name, glm::vec3 value) const;
    void setMat4(const std::string &name, glm::mat4 value) const;
    void setFloat(const std::string  &name, float value) const;

private:
    uint32_t id;

};


#endif //TINY_POTION_FACTORY_SHADER_H
