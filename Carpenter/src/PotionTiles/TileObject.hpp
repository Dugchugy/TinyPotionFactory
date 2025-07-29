#ifndef TILEOBJECT_HPP
#define TILEOBJECT_HPP

#include "TilePosition.hpp"

namespace PotionGrid {

class TileObject : public SerialObject {

private:
   TilePosition position;

}; //TileObject

} //PotionGrid 

#endif //TILEOBJECT_HPP