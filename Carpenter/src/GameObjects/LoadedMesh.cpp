#include "LoadedMesh.hpp"

#include "AssetStream.hpp"
#include "LoadObjHelpers.hpp"

using namespace PotionParts;

LoadedMesh::LoadedMesh( std::vector<Tri> triangles ) {
   for ( int i = 0; i < triangles.size(); i++ ) {
      AddTriangle( triangles[i].v1, triangles[i].v2, triangles[i].v3 );
      AddTriangle( triangles[i].v3, triangles[i].v2, triangles[i].v1 );
   }
}

LoadedMesh PotionParts::loadStlMesh( std::string filename ) {

   AssetStream stlAsset( filename );
   stlAsset.open();

   // skips the 80 byte header
   stlAsset.skipBytes( 80 );

   int triCount = 0;
   stlAsset >> triCount;

   std::vector<Tri> triangles;

   for ( int i = 0; i < triCount; i++ ) {
      Vector3 normal, v1, v2, v3;

      stlAsset >> normal >> v1 >> v2 >> v3;

      Vector3 calcNorm = cross( v2-v1, v3-v1 );

      normal.normalize();
      calcNorm.normalize();

      if( equalError( normal, calcNorm, 0.001f) ) {
         triangles.push_back( { v1.toVertex( 0, 0 ), v2.toVertex( 1, 0 ), v3.toVertex( 1, 1 ) } );
      } else {
         triangles.push_back( { v3.toVertex( 0, 0 ), v2.toVertex( 1, 0 ), v1.toVertex( 1, 1 ) } );
      }

      // skip two byte mesh number
      stlAsset.skipBytes( 2 );
   }

   return LoadedMesh( triangles );


}