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

TileType TileIdentifier::type() {
   return _type;
}

unsigned long TileIdentifier::index() {
   return _index;
}

unsigned long TileIdentifier::nextIndex() {
   return _nextIndex;
}
