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

TileType TileIdentifier::type() const {
   return _type;
}

unsigned long TileIdentifier::index() const {
   return _index;
}

unsigned long TileIdentifier::nextIndex() {
   return _nextIndex;
}

void TileIdentifier::nextIndexIs( unsigned long nextIndex ) {
   _nextIndex = nextIndex;
}

bool TileIdentifier::operator==( const TileIdentifier& comp ) const {
   return _type == comp._type && _index == comp._index;
}
