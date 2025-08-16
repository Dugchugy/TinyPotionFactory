#include "CauldronTile.hpp"

using namespace PotionGrid;

CauldronTile::CauldronTile( TilePosition pos ) :
 TileObject( pos, PotionParts::ModelLink() ) {}

CauldronTile::type() {
   return TileType::CauldronTile;
}

