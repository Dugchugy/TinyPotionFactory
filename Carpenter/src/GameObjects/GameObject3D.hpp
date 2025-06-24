#ifndef GAMEOBJECT3D_HPP
#define GAMEOBJECT3D_HPP

#include "Model.hpp"
#include "Transform.hpp"
#include <Graphics/Renderer.hpp>

namespace PotionParts {

class GameObject3D {
public:

    Transform transform;
    Model model;

    /// @brief Creates a new game object 3D with the specifed Model using the specified Transform
    GameObject3D( Transform t, Model m );

    /// @brief Draws the game object using the appropriate renderer
    /// @param renderer the renderer that will be used to draw the object
    void draw( Engine::Graphics::Renderer renderer );

}; //GameObject3D

} // PotionParts

#endif //GAMEOBJECT3D_HPP