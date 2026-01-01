#include "LecturnTile.hpp"

using namespace PotionGrid;

LecturnTile::LecturnTile( TilePosition pos ) :
 TileObject( pos, PotionParts::ModelManager::getManager().loadObjModel( "Assets/JournalLecturn.obj" ) ) {}

TileType LecturnTile::tileType() {
   return TileType::LecturnTile;
}

