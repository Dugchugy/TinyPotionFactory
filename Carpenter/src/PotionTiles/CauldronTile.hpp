#ifndef CAULDRONTILE_HPP
#define CAULDRONTILE_HPP

#include "TileObject.hpp"
#include "TilePosition.hpp"
#include "TileIdentifier.hpp"

namespace PotionGrid {

class CauldronTile : public TileObject {

   CauldronTile( TilePosition pos );

   virtual TileType type();

}; //CauldronTile 

} //PotionGrid

#endif //CAULDRONTILE_HPP