#ifndef GAMEOBJECT3D_HPP
#define GAMEOBJECT3D_HPP

#include "Model.hpp"
#include "Transform.hpp"
#include <Graphics/Renderer.hpp>

namespace PotionParts {

class GameObject3D {
public:

    Transform transform;
    ModelLink model;

    /// @brief Creates a new game object 3D with the specifed Model using the specified Transform
    GameObject3D( Transform t, ModelLink m );

    /// @brief Draws the game object using the appropriate renderer
    /// @param renderer the renderer that will be used to draw the object
    virtual void draw( Engine::Graphics::Renderer renderer );

    /**
     * @brief updates the game object. used to implement a physics tick
     * @param timeSinceLastUpdate the time it has been since the last update in seconds
     * 
     * does nothing by default, should be overrode by any object using it
     */
    virtual void update( float timeSinceLastUpdate ) {};

}; //GameObject3D

} // PotionParts

#endif //GAMEOBJECT3D_HPP