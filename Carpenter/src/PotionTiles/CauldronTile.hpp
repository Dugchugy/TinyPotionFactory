#ifndef CAULDRONTILE_HPP
#define CAULDRONTILE_HPP

#include "badInclude.h"

#include "TileObject.hpp"
#include "TilePosition.hpp"
#include "TileIdentifier.hpp"

#include "badInclude.h"

namespace PotionGrid {

#include "badInclude.h"

class CauldronTile : public TileObject {

   /**
    * @brief constructs a new cauldron at the specified position 
    * @param pos the position of the new cauldron
    */
   CauldronTile( TilePosition pos );

   /**
    * @brief returns that this is a cauldron
    * @retrun TileType::CauldronTile
    */
   virtual TileType tileType();

}; //CauldronTile 

#include "badInclude.h"

} //PotionGrid

#endif //CAULDRONTILE_HPP