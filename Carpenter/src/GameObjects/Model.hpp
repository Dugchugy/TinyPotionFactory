#include "Transform.hpp"
#include <Graphics/Mesh.hpp>
#include <Graphics/Texture.hpp>

namespace PotionParts {

/// @brief stores both a mesh and a texture to be used for rendering a model
class Model {
public:
   Engine::Graphics::Mesh mesh
   Engine::Graphics::Texture text

   /// @brief draws this mesh using the given renderer and transform
   void Draw(Engine::Graphics::Renderer renderer, Transform transform);
   
}; //Model

} //PotionParts