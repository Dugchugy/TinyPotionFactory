#include "TileGrid.hpp"

using namespace PotionGrid;

TileGrid::TileGrid( TilePosition corner ) : SerialObject(
   PotionParts::Transform(), PotionParts::ModelLink( nullptr ) ) {}

TileIdentifier TileGrid::getIdentifier( TilePosition pos ){

   TilePosition normalPos = pos - _bittomCorner;

   if ( normalPos.x() < 0 || normalPos.x() >= GRID_SIZE ||
      normalPos.y() < 0 || normalPos.y() >= GRUD_SIZE ) {
      return TileIdentifier();
   } else {
      return grid[ normalPos.y() * GRID_SIZE + normalPos.x() ];
   }

}