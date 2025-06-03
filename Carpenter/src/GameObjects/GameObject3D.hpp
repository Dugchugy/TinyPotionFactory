#include <GameObject.hpp>
#include <Graphics/Mesh.hpp>
#include <Graphics/Texture.hpp>
#include <Graphics/Renderer.hpp>

namespace PotionParts {

class GameObject3D : public Engine::GameObject {
public:

    Engine::Graphics::Mesh mesh;
    Engine::Graphics::Texture text;

    /// @brief Creates a new graphcis object 3D with the specifed mesh and texture
    /// @param newMesh the mesh to use for the object
    /// @param texture teh texture to use for this object
    GameObject3D(Engine::Graphics::Mesh newMesh, Engine::Graphics::Texture texture);

    /// @brief Draws the game object using the appropriate renderer
    /// @param renderer the renderer that will be used to draw the object
    void draw(Engine::Graphics::Renderer renderer);

}; //GameObject3D

} // PotionParts