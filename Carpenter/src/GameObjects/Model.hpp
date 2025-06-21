#ifndef MODEL_HPP
#define MODEL_HPP

#include "Transform.hpp"
#include <Graphics/Mesh.hpp>
#include <Graphics/Texture.hpp>
#include <Graphics/Renderer.hpp>
#includd <vector>

namespace PotionParts {

class Model {
public:

   Model( ModelBase* base );

   /// @brief draws this Model using the given renderer and transform
   void draw( Engine::Graphics::Renderer renderer, const Transform transform ) const;

private:

   ModelBase* _base;

}; //Model

/// @brief stores both a mesh and a texture to be used for rendering a model. model itself references the model base to determine its rendering process
class ModelBase {
public:

   ModelBase();

   ModelBase( Engine::Graphics::Mesh m, Engine::Graphics::Texture t );

   void addMesh( Engine::Graphics::Mesh m, Engine::Graphics::Texture t );

   /// @brief draws this mesh using the given renderer and transform
   void draw( Engine::Graphics::Renderer renderer, const Transform transform ) const;
   
private:

   std::vector<Engine::Graphics::Mesh> subMeshs;
   std::vector<Engine::Graphics::Texture> textures;
}; //ModelBase

/// @brief Singleton class that is used to load models from asset files. keeps memory usage down by reducing number of duplicate models loaded
class ModelManager {
public:
  /// @brief gets the model manager Singleton. if it does not exist, creates it
  static ModelManager & getManager();

  /// @brief loads an STL model from the passed filename
  /// @param filename the path to the STL file. must end in '.stl'
  /// checks the internal cache before loading the file and only loads it if it hasn't been loaded before
  Model loadStlModel( std::string filename );

private:
   ModelManager();

   /// @brief checks if a model has been loaded before and returns a pointer to it if it has
   ModelBase* checkLoaded( std::string filename )

   static ModelManager * manager;

   std::unordered_map<std::string, ModelBase> modelMap;

}; //ModelManager

} //PotionParts

#endif //MODEL_HPP