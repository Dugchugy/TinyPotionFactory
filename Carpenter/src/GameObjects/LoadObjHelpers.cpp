#include "LoadObjHelpers.hpp"

using namespace PotionParts;

TexCoords operator+( const TexCoords & x, const TexCoords & y ) {
   return { x.u + y.u, x.v + y.v };
}