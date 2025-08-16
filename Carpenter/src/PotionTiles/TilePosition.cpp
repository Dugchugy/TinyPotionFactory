#include "TilePosition.hpp"

using namespace PotionGrid;

TilePosition::TilePosition() : TilePosition( 0, 0 ) {}

TilePosition::TilePosition( int x, int y ) {
   _x = x;
   _y = y;
}

PotionParts::Vector3 TilePosition::toVector() {
   return PotionParts::Vector3( _x, _y, 0 );
}

int TilePosition::x() {
   return _x;
}

int TilePosition::y() {
   return _y;
}

void TilePosition::xIs( int x ) {
   _x = x;
}

void TilePosition::yIs( int y ) {
   _y = y;
}

void TilePosition::positionIs( int x, int y ) {
   _x = x;
   _y = y;
}

TilePosition PotionGrid::operator+ ( const TilePosition& a, const TilePosition& b ) {
   return TilePosition( a._x + b._x, a._y + b._y );
}

TilePosition PotionGrid::operator- ( const TilePosition& a, const TilePosition& b ) {
   return TilePosition( a._x - b._x, a._y - b._y );
}

bool PotionGrid::operator== ( const TilePosition& a, const TilePosition& b ) {
   return ( a._x == b._x && a._y == b._y );
}
