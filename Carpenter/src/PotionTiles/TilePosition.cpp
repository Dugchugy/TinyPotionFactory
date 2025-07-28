#include "TilePosition.hpp"

using namespace PotionGrid

TilePosition::TilePosition() : TilePosition( 0, 0 ) {}

TilePosition::TilePosition( int x, int y ) {
   _x = x;
   _y = y;
}