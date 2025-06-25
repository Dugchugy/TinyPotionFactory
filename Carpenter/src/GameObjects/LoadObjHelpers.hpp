#ifndef LOADOBJHELPERS_HPP
#define LOADOBJHELPERS_HPP

#include <string>
#include <vector>
#include <exception>

#include "Vector3.hpp"
#include "LoadedMesh.hpp"

namespace PotionParts {

/// @brief stores the coordinates for a pair of texture coordinates
struct TexCoords {
   float u;
   float v;
};

std::vector<std::string> splitString( const std::string & str, char c );

Vector3 parseVertex( std::string & line );

TexCoords parseUV( std::string & line );

Vector3 parseNormal( std::string & line );

std::vector<Tri> parseFace( std::string & line, const std::vector<Vector3> & vertexes, const std::vector<TexCoords> & uVs );

TexCoords operator+( const TexCoords & x, const TexCoords & y );

class InvalidLineException : public std:: exception {
public:
   virtual const char* what() const throw();

}; //InvalidLineException 


}

#endif //LOADOBJHELPERS_HPP