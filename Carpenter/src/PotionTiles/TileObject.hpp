#ifndef TILEOBJECT_HPP
#define TILEOBJECT_HPP

#include "GameObjects/SerialObject.hpp"
#include "TilePosition.hpp"
#include "TileIdentifier.hpp"

namespace PotionGrid {

class TileObject : public SerialObject {

   TileObject( TilePosition pos );

private:
   TilePosition position;

   virtual TileType type();

}; //TileObject

} //PotionGrid 

#endif //TILEOBJECT_HPP