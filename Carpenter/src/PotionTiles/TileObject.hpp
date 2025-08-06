#ifndef TILEOBJECT_HPP
#define TILEOBJECT_HPP

#include "GameObjects/SerialObject.hpp"
#include "TilePosition.hpp"
#include "TileIdentifier.hpp"
#include "GridBoard.hpp"

namespace PotionGrid {

class TileObject : public SerialObject {

   TileObject( TilePosition pos, PotionParts::ModelLink m );

   virtual TileType type();

   virtual void update( float timeSinceLastUpdate, GridBoard board );

private:
   TilePosition position;

}; //TileObject

} //PotionGrid 

#endif //TILEOBJECT_HPP