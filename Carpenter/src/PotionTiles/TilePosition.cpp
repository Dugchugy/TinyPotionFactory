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