#include "TileObject.hpp"

#include "GameObjects/Transform.hpp"

using namespace PotionGrid;
using PotionParts::Vector3;

TileType TileObject::type() {
    return TileType::NullTile;
}

TileObject::TileObject( TilePosition pos, PotionParts::ModelLink m ) : SerialObject( 
    PotionParts::Transform( pos.toVector(), Vector3(), Vector3( 0.5f ) ), m ){}

void TileObject::update( float timeSinceLastUpdate, GridBoard board ) {}