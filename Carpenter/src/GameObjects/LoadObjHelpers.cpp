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

TexCoords operator+( const TexCoords & x, const TexCoords & y ) {
   return { x.u + y.u, x.v + y.v };
}