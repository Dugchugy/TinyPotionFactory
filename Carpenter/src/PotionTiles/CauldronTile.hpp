#ifndef CAULDRONTILE_HPP
#define CAULDRONTILE_HPP

#include "TileObject.hpp"
#include "TilePosition.hpp"
#include "TileIdentifier.hpp"

namespace PotionGrid {

class CauldronTile : public TileObject {

   /**
    * @brief constructs a new cauldron at the specified position 
    * @param pos the position of the new cauldron
    */
   CauldronTile( TilePosition pos );

   /**
    * @brief returns that this is a cauldron
    */
   virtual TileType tileType();

}; //CauldronTile 

} //PotionGrid

#endif //CAULDRONTILE_HPP