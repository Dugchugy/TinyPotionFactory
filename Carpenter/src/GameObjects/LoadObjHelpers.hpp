#ifndef LOADOBJHELPERS_HPP
#define LOADOBJHELPERS_HPP

#include <string>
#include <vector>

#include "Vector3.hpp"
#include "LoadedMesh.hpp"

namespace PotionParts {

/// @brief stores the coordinates for a pair of texture coordinates
struct TexCoords {
   float u;
   float v;
};

Vector3 parseVertex( std::string line );



}

#endif //LOADOBJHELPERS_HPP