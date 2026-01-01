#ifndef LECTURNTILE_HPP
#define LECTURNTILE_HPP

#include "TileObject.hpp"
#include "TilePosition.hpp"
#include "TileIdentifier.hpp"

class LecturnTile : public PotionGrid::TileObject {
public:

   /**
    * @brief constructs a new lecturn at the specified position 
    * @param pos the position of the new lecturn
    */
   LecturnTile( PotionGrid::TilePosition pos );

   /**
    * @brief returns that this is a lecturn
    * @retrun TileType::LecturnTile
    */
   virtual PotionGrid::TileType tileType();

}; //LecturnTile 

#endif //LECTURNTILE_HPP