#include "TileGrid.hpp"

using namespace PotionGrid;

TileGrid::TileGrid( TilePosition corner ) : SerialObject(
   PotionParts::Transform(), PotionParts::ModelLink( nullptr ) ) {}