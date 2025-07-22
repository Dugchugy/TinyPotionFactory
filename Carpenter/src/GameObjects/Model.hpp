#ifndef MODEL_HPP
#define MODEL_HPP

#include "Transform.hpp"
#include <Graphics/Renderer.hpp>
#include <Assets/Model.hpp>
#include <vector>

namespace PotionParts {

class ModelLink {
public:

   ModelLink( Model* base );

   /// @brief draws this Model using the given renderer and transform
   void draw( Engine::Graphics::Renderer& renderer, const Transform transform ) const;

private:

   Model* _base;

}; //ModelLink

/// @brief Singleton class that is used to load models from asset files. keeps memory usage down by reducing number of duplicate models loaded
class ModelManager {
public:
   /// @brief gets the model manager Singleton. if it does not exist, creates it
   static ModelManager & getManager();

   /// @brief loads an STL model from the passed filename
   /// @param filename the path to the STL file. must end in '.stl'
   /// checks the internal cache before loading the file and only loads it if it hasn't been loaded before
   ModelLink loadStlModel( std::string filename );

   /// @brief loads a cube mesh with the appropriate texture
   /// @param textFilename the path to the PNG texture. must be a PNG file
   /// checks the internal cache before loading the file and only loads it if it hasn't been loaded before
   ModelLink loadCube( char* textFilename );

   /// @brief loads an OBJ model from the passed filename
   /// @param filename the the path to the .obj file
   /// @return the model read from the file
   /// checks the internal cache before loading the file and only loads it if it hasn't been loaded before
   /// also loads any .mtl files required by the .obj file as well as any textures
   ModelLink loadObjModel( std::string filename );

private:
   ModelManager();

   /// @brief checks if a model has been loaded before and returns a pointer to it if it has
   Model* checkLoaded( std::string filename );

   static ModelManager* manager;

   std::unordered_map<std::string, Model*> modelMap;

}; //ModelManager

} //PotionParts

#endif //MODEL_HPP