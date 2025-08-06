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

void TileIdentifier::nextIndexIs( unsigned long nextIndex ) {
   _nextIndex = nextIndex;
}

bool PotionGrid::operator==( const TileIdentifier& a, const TileIdentifier& b ) {
   return a._index == b._index && a._type == b._type;
}
