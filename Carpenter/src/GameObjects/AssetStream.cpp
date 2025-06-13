#include "AssetStream.hpp"

#include <emscripten>

using namespace PotionParts;

AssetStream::AssetStream( std::string path ) {
   _asset = nullptr;
   _path = path;
   _size = 0;
   _position = 0;
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
   _size = a._size;
   _position = a._position;
}

const &AssetStream AssetStream::operator= ( const &AssetStream a ) {
   cpy = AssetStream( a );

   void* tmp = cpy._asset;
   cpy._asset = _asset;
   _asset = tmp;

   _path = a._path;
   _size = a._size;
   _position = a._position;

   return a;
}

void* AssetStream::takeAsset() {
   if ( _asset == nullptr ) {
      // throw error
   }

   void* tmp = _asset;
   _asset = nullptr;
   _size = 0;
   return tmp;
}

void AssetStream::open() {
   int fileError= 0

   if ( _asset != nullptr ) {
      free( _asset );
      _asset = nullptr
   }

   _position = 0;

   emscripten_mget_data( _path, &_asset, &_size, &fileError );

   if ( fileError ) {
      // throw error
   }
}


AssetStream& AssetStream::operator>>( float& x ) {
   if ( _asset == nullptr ) {
      // throw error
   }

   if ( _size - _position < 4 ) {
      // throw error
   }

   void* current = _asset + _position;
   x = *( (float*) current);

   _position += 4;

   return this;
}

AssetStream& AssetStream::operator>>( int& x ) {
   if ( _asset == nullptr ) {
      // throw error
   }

   if ( _size - _position < 4 ) {
      // throw error
   }

   void* current = _asset + _position;
   x = *( (int*) current);

   _position += 4;

   return this;
}

AssetStream& AssetStream::operator>>( uint8& x ) {
   if ( _asset == nullptr ) {
      // throw error
   }

   if ( _size - _position < 1 ) {
      // throw error
   }

   void* current = _asset + _position;
   x = *( (uint8*) current);

   _position += 1;

   return this;
}