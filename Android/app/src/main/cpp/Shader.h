//
// Created by dugch on 2025-01-04.
//

#ifndef TINY_POTION_FACTORY_SHADER_H
#define TINY_POTION_FACTORY_SHADER_H

#include <cstdint>

class Shader {
public:
    void fromSource(const char* vectCode, const char* fragCode);
    void use() const;

private:
    uint32_t id;

};


#endif //TINY_POTION_FACTORY_SHADER_H
