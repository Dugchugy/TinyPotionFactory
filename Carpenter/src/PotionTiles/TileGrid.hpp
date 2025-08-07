#ifndef TILEGRID_HPP
#define TILEGRID_HPP

#define GRID_SIZE 16

#include "GameObjects/SerialObject.hpp"

#include "TileObject.hpp"
#include "TilePosition.hpp"

namespace PotionGrid {

class TileGrid : public PotionParts::SerialObject {

public:
   
   TileGrid( TilePosition corner );

private:

    TilePosition _bottomCorner;

    TileIdentifier[ GRID_SIZE * GRID_SIZE ];

}; //TileGrid

} //PotionGrid

#endif //TILEGRID_HPP