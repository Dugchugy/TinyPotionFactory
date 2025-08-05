#include "TileIdentifier.hpp"

using namespace PotionGrid;

TileIdentifier::TileIdentifier() {
   _type = TileType::NullTile;
   _index = 0;
}

TileIdentifier::TileIdentifier( TileType type ) {
   _type = type;
   _index = nextIndex();
}