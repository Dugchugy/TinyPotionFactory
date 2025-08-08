#ifndef GRIDBOARD_HPP
#define GRIDBOARD_HPP

#include "../GameObjects/SerialObject.hpp"
#include "TileIdentifier.hpp"
#include "TileObject.hpp"
#include "TileGrid.hpp"

#include <Renderer.hpp>
#include <unordered_map>

namespace PotionGrid {

/**
 * a collection of grids that are updated as a set.
 */
class GridBoard : PotionParts::SerialObject {
public:

   /**
    * @brief constructs a new GribBoard with empty Grids
    */
   GridBoard();

   /**
    * @brief Draws the game object using the appropriate renderer
    * @param renderer the renderer that will be used to draw the object
    * 
    * calls draw in all of the tileObjects stored in this gridBoard
    */
   virtual void draw( Engine::Graphics::Renderer& renderer ); 

   /**
    * @brief updates the game object. used to implement a physics tick
    * @param timeSinceLastUpdate the time it has been since the last update in seconds
    * 
    * splits the update into the 4 phase update and runs all 4 update phases on the
    * tileObjects stored in this object.
    */
   virtual void update( float timeSinceLastUpdate );

   /**
    * @brief looks up a tile using its identifier
    * @param id the identifier to use for the lookup
    * @return a pointer to the tile with this Identifier (or null if not found)
    */
   TileObject* getTile( TileIdentifier id );

   /**
    * @brief looks up a tile using its position
    * @param pos the position of this tile
    * @return a pointer to the tile at this position (or null if not found)
    */
   TileObject* getTile( TilePosition pos );

   /**
    * @brief adds a tile with a particular identifier to the grids collection
    * @param object the TileObject to add
    * @param id the identifier for this tile
    */
   void addTile( TileObject object, TileIdentifier id );

   void addTile( TileObject object, TilePosition pos );

   void delTile( TileIdentifier id );

   void delTile( TilePosition pos );

private:

    std::unordered_map< TileIdentifier, TileObject* > tileMap;

    std::vector< TileGrid > subGrid;

}; //GridBoard

} // PotionGrid

#endif