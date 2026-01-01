#include "LecturnTile.hpp"

using namespace PotionGrid;

LecturnTile::LecturnTile( TilePosition pos ) :
 TileObject( pos, PotionParts::ModelManager::getManager().loadObjModel( "Assets/JournalLecturn.obj" ) ) {}

TileType CauldronTile::tileType() {
   return TileType::LecturnTile;
}

