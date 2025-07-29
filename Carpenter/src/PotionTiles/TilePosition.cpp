#include "TilePosition.hpp"

using namespace PotionGrid

TilePosition::TilePosition() : TilePosition( 0, 0 ) {}

TilePosition::TilePosition( int x, int y ) {
   _x = x;
   _y = y;
}

int TilePosition::x() {
   return _x
}

int TilePosition::y() {
   return _y
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
   return TilePosition( a.x + b.x, a.y + b.y );
}

TilePosition PotionGrid::operator- ( const TilePosition& a, const TilePosition& b ) {
   return TilePosition( a.x - b.x, a.y - b.y );
}