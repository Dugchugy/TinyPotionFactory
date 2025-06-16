#include "StlMesh.hpp"

#include <emscripten.h>
#include "AssetStream.hpp"

using namespace PotionParts;

StlMesh::StlMesh( std::string filename ){

   AssetStream stlAsset( filename );
   stlAsset.open();

   // skips the 80 byte header
   stlAsset.skipBytes( 80 );

   int triangles = 0;
   stlAsset >> triangles;

   for ( int i = 0; i < triangles; i++ ) {
      Vector3 normal, v1, v2, v3;

      stlAsset >> normal >> v1 >> v2 >> v3;

      Vector3 calcNorm = cross( v2-v1, v3-v1 );

      normal.normalize();
      calcNorm.normalize();

      if( equalError( normal, calcNorm, 0.001f) ) {
         AddTriangle( v1.toVertex( 0, 0 ), v2.toVertex( 1, 0 ), v3.toVertex( 1, 1 ) );
      } else {
         AddTriangle( v3.toVertex( 0, 0 ), v2.toVertex( 1, 0 ), v1.toVertex( 1, 1 ) );
      }
      // skip two byte mesh number
      stlAsset.skipBytes( 2 );
   }

} //StlMesh( Std::String )