#include "LoadedMesh.hpp"

using namespace PotionParts;

LoadedMesh::LoadedMesh( std::vector<Tri> triangles ) {
   for ( int i = 0; i < triangles.size(); i++ ) {
      AddTriangle( triangles[i].v1, triangles[i].v2, triangles[i].v3 );
      AddTriangle( triangles[i].v3, triangles[i].v2, triangles[i].v1 );
   }
}