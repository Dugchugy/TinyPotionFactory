#ifndef TILEOBJECT_HPP
#define TILEOBJECT_HPP

#include "../GameObjects/SerialObject.hpp"
#include "TilePosition.hpp"
#include "TileIdentifier.hpp"
//#include "GridBoard.hpp"

namespace PotionGrid {

class TileObject : public PotionParts::SerialObject {
public:

   TileObject( TilePosition pos, PotionParts::ModelLink m );

   virtual TileType tileType();

   virtual void updatePrepare( float timeSinceLastUpdate );

   virtual void updateTransfer( float timeSinceLastUpdate/*, GridBoard board*/ );

   virtual void updateUpdate( float timeSinceLastUpdate );

   virtual void updateCleanup( float timeSinceLastUpdate );

   TileIdentifier id();

private:
   TilePosition position;
   TileIdentifier _id;
   bool idSet;

}; //TileObject

} //PotionGrid 

#endif //TILEOBJECT_HPP