#include "CauldronTile.hpp"

using namespace PotionGrid;

CauldronTile::CauldronTile( TilePosition pos ) :
 TileObject( pos, PotionParts::ModelManager::getManager().loadObjModel( "Assets/cauldren.obj" ) ) {}

CauldronTile::type() {
   return TileType::CauldronTile;
}

