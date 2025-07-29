#ifndef GRIDBOARD_HPP
#define GRIDBOARD_HPP

#include "../GameObjects/SerialObject.hpp"
#include <Renderer.hpp>

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
    override void draw( Engine::Graphics::Renderer& renderer ); 

    /**
     * @brief updates the game object. used to implement a physics tick
     * @param timeSinceLastUpdate the time it has been since the last update in seconds
     * 
     * splits the update into the 4 phase update and runs all 4 update phases on the
     * subgrids stored in this object.
     */
    override void update( float timeSinceLastUpdate );

}; //GridBoard

} // PotionGrid

#endif