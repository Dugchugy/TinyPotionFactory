#include "StlMesh.hpp"

#include <emscripten.h>
#include "AssetStream.h"

using namespace PotionParts;

StlMesh::StlMesh( Std::String filename ){

   sltAsset = AssetStream( filename );
   stlAsset.open();

   // skips the 80 byte header
   stlAsset.skipBytes( 80 );

   int triangles = 0;
   stlAsset >> triangles;

   for ( i = 0, i < triangles; i++ ) {
      Vector3 normal, v1, v2, v3;

      stlAsset >> normal >> v1 >> v2 >> v3;

      // skip two byte mesh number
      stlAsset.skipBytes( 2 )
   }

   free( fileContent );

} //StlMesh( Std::String )