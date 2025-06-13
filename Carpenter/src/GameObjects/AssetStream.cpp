#include "AssetStream.hpp"

#include <emscripten>

using namespace PotionParts;

AssetStream::AssetStream( std::string path ) {
   _asset = nullptr;
   _path = path;
}

AssetStream::~AssetStream() {
   if ( _asset != nullptr ) {
      free( _asset );
      _asset = nullptr;
   }
}

AssetStream::AssetStream( const AssetStream& a ) {
   if ( _asset != nullptr ) {
      free( _asset );
      _asset = nullptr;
   }

   memcpy( &a._asset, &_asset );

   _path = a._path;
}

const &AssetStream AssetStream::operator= ( const &AssetStream a ) {
   cpy = AssetStream( a );

   void* tmp = cpy._asset;
   cpy._asset = _asset;
   _asset = tmp;

   _path = a._path;

   return a;
}

void* AssetStream::takeAsset() {
   if ( _asset == nullptr ) {
      // throw error
   }

   void* tmp = _asset;
   _asset = nullptr;
   return tmp;
}

void AssetStream::open() {
   int fileSize = 0
   int fileError= 0

   if ( _asset != nullptr ) {
      free( _asset );
      _asset = nullptr
   }

   emscripten_mget_data( _path, &_asset, &fileSize, &fileError );

   if ( fileError ) {
      // throw error
   }
}