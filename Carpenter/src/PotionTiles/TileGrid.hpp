#ifndef TILEGRID_HPP
#define TILEGRID_HPP

#define GRID_SIZE 16

#include "GameObjects/SerialObject.hpp"

#include "TileObject.hpp"
#include "TilePosition.hpp"

namespace PotionGrid {

class TileGrid : public PotionParts::SerialObject {

public:
   
   /**
    * @brief creates a Tile grid with the bottom left corner coordinates passed
    * @param corner the tile coordinates of the bottom right corner.
    */
   TileGrid( TilePosition corner );

   /**
    * @brief looks up a TileIdentifier using the tiles position.
    * @param pos the position of the tile to look up
    * @return the TileIdentifier at this position (null if not in this grid)
    */
   TileIdentifier getIdentifier( TilePosition pos );

   /**
    * @brief sets the TileIdentifier for the specified position
    * @param pos the position to set the identifier at
    * @param id the identifier to set this position too
    */
   void setIdentifier( TilePosition pos, TileIdentifier id );

private:

    TilePosition _bottomCorner;

    TileIdentifier[ GRID_SIZE * GRID_SIZE ] grid;

}; //TileGrid

} //PotionGrid

#endif //TILEGRID_HPP