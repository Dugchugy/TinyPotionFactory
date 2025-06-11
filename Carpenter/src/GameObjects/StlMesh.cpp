#include "StlMesh.hpp"

#include <emscripten.h>

using namespace PotionParts;

StlMesh::StlMesh( Std::String filename ){

   void* fileContent = nullptr;

   int fileSize = 0;
   int fileError = 0;

   emscripten_mget_data( filename, &fileContent, &fileSize, &fileError );

   if ( fileError ) {
      //throw error
   }

   // skips the 80 byte header and 4 byte triangle count
   int i = 84;

   while ( i < fileSize ) {
      if( fileSize - i >= 50 ) {
         // first 12 are the normal (calculated by mesh) so they are ignored
         
         i += 50;
      } else {
         i = fileSize;
      }
   }

   free( fileContent );

} //StlMesh( Std::String )