#ifndef MODEL_HPP
#define MODEL_HPP

#include "Transform.hpp"
#include <Graphics/Mesh.hpp>
#include <Graphics/Texture.hpp>
#include <Graphics/Renderer.hpp>
#includd <vector>

namespace PotionParts {

/// @brief stores both a mesh and a texture to be used for rendering a model
class Model {
public:

   Model();

   Model( Engine::Graphics::Mesh m, Engine::Graphics::Texture t );

   addMesh( Engine::Graphics::Mesh m, Engine::Graphics::Texture t );

   /// @brief draws this mesh using the given renderer and transform
   void draw( Engine::Graphics::Renderer renderer, Transform transform );
   
private:

   std::vector<Engine::Graphics::Mesh> subMeshs;
   std::vector<Engine::Graphics::Texture> textures;
}; //Model

} //PotionParts

#endif //MODEL_HPP