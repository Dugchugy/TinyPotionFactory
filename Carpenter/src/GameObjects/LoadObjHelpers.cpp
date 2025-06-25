#include "LoadObjHelpers.hpp"

using namespace PotionParts;

std::vector<std::string> splitString( const std::string & str, char c ){
   std::vector<std::string> subStrs;

   std::string currStr = "";

   for ( int i = 0; i < str.size(); i++ ){
      if ( str[i] == c ) {
         subStrs.push_back( currStr );
         currStr = "";
      } else {
         subStrs += str[i]
      }
   }

   subStrs.push_back( currStr );

   return subStrs;
}

Vector3 parseVertex( std::string & line ) {
   std::vector<std::string> split = splitString( line, ' ' );

   if ( split.size() != 4 ) {
      throw InvalidLineException();
   }

   if ( split[0] != "v" ) {
      throw InvalidLineException();
   }

   float x = stof( split[1], nullptr );
   float y = stof( split[2], nullptr );
   float z = stof( split[3], nullptr );

   return Vector3( x, y, z );
}

TexCoords parseUV( std::string & line ){
   std::vector<std::string> split = splitString( line, ' ' );

   if ( split.size() != 3 ) {
      throw InvalidLineException();
   }

   if ( split[0] != "vt" ) {
      throw InvalidLineException();
   }

   float u = stof( split[1], nullptr );
   float v = stof( split[2], nullptr );

   return { u, v };
}

Vector3 parseNormal( std::string & line ) {
   std::vector<std::string> split = splitString( line, ' ' );

   if ( split.size() != 4 ) {
      throw InvalidLineException();
   }

   if ( split[0] != "vn" ) {
      throw InvalidLineException();
   }

   float x = stof( split[1], nullptr );
   float y = stof( split[2], nullptr );
   float z = stof( split[3], nullptr );

   return Vector3( x, y, z );
}

TexCoords operator+( const TexCoords & x, const TexCoords & y ) {
   return { x.u + y.u, x.v + y.v };
}