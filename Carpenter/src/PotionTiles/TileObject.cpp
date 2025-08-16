#include "TileObject.hpp"

#include "../GameObjects/Transform.hpp"

using namespace PotionGrid;
using PotionParts::Vector3;

TileType TileObject::tileType() {
   return TileType::NullTile;
}

TileObject::TileObject( TilePosition pos, PotionParts::ModelLink m ) : SerialObject( 
   PotionParts::Transform( pos.toVector(), Vector3(), Vector3( 0.5f ) ), m ){}

void TileObject::updatePrepare( float timeSinceLastUpdate ) {}

void TileObject::updateTransfer( float timeSinceLastUpdate/*, GridBoard board*/ ) {}

void TileObject::updateUpdate( float timeSinceLastUpdate ) {}

void TileObject::updateCleanup( float timeSinceLastUpdate ) {}