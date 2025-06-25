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

Vector3 parseVertex( std::string & line );

TexCoords parseUV( std::string & line );

Vector3 parseNormal( std::string & line );

std::vector<Tri> parseFace( std::string & line, const std::vector<Vector3> & vertexes, const std::vector<TexCoords> & uVs );

TexCoords operator+( TexCoords x, TexCoords y );


}

#endif //LOADOBJHELPERS_HPP