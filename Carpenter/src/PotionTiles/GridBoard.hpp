#ifndef GRIDBOARD_HPP
#define GRIDBOARD_HPP

#include "../GameObjects/SerialObject.hpp"
#include "TileIdentifier.hpp"
#include "TileObject.hpp"

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
    * calls draw in all of the subgrids stored in this gridBoard
    */
   virtual void draw( Engine::Graphics::Renderer& renderer ); 

   /**
    * @brief updates the game object. used to implement a physics tick
    * @param timeSinceLastUpdate the time it has been since the last update in seconds
    * 
    * splits the update into the 4 phase update and runs all 4 update phases on the
    * subgrids stored in this object.
    */
   virtual void update( float timeSinceLastUpdate );

   TileObject* getTile( TileIdentifier id );

   void addTile( TileObject object, TileIdentifier id );

   void delTile( TileIdentifier id );

private:

    std::unordered_map< TileIdentifier, TileObject* > tileMap;

}; //GridBoard

} // PotionGrid

#endif