#include "TileObject.hpp"

#include "../GameObjects/Transform.hpp"

using namespace PotionGrid;
using PotionParts::Vector3;

TileType TileObject::tileType() {
   return TileType::NullTile;
}

TileObject::TileObject( TilePosition pos, PotionParts::ModelLink m ) : 
   position( pos ),
   PotionParts::SerialObject( PotionParts::Transform( pos.toVector(), Vector3(), 
   Vector3( 0.5f ) ), m ),
   _id( TileIdentifier( tileType() ) ) {}

void TileObject::updatePrepare( float timeSinceLastUpdate ) {}

void TileObject::updateTransfer( float timeSinceLastUpdate/*, GridBoard board*/ ) {}

void TileObject::updateUpdate( float timeSinceLastUpdate ) {}

void TileObject::updateCleanup( float timeSinceLastUpdate ) {}

TileIdentifier TileObject::id() const {
   return _id;
}