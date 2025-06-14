#ifndef MODEL_HPP
#define MODEL_HPP

#include "Transform.hpp"
#include <Graphics/Mesh.hpp>
#include <Graphics/Texture.hpp>
#include <Graphics/Renderer.hpp>

namespace PotionParts {

/// @brief stores both a mesh and a texture to be used for rendering a model
class Model {
public:
   Engine::Graphics::Mesh mesh;
   Engine::Graphics::Texture text;

   Model( Engine::Graphics::Mesh m, Engine::Graphics::Texture t );

   /// @brief draws this mesh using the given renderer and transform
   void draw( Engine::Graphics::Renderer renderer, Transform transform );
   
}; //Model

} //PotionParts

#endif //MODEL_HPP