#include "Model.hpp"

#include <Graphics/Shapes.hpp>
#include <iostream>
#include <vector>

#include "LoadObjHelpers.hpp"
#include "AssetStream.hpp"

using namespace PotionParts;


ModelLink::ModelLink( Model* base ) : _base( base ) {}

void ModelLink::draw(Engine::Graphics::Renderer& renderer, const Transform transform) const {

   if ( _base != nullptr ) {
      _base->draw( renderer, transform );
   }
}

ModelManager::ModelManager() {

   modelMap = std::unordered_map<std::string, Model*>();

} //ModelManager::ModelManager()


ModelManager & ModelManager::getManager() {
   static ModelManager* manager;
   if ( manager == nullptr ) {
      manager = new ModelManager();
   }
   return *manager;
}

Model * ModelManager::checkLoaded( std::string filename ){
   if ( modelMap.contains( filename ) ) {
      return modelMap.at( filename );
   } else {
      return nullptr;
   }
}

ModelLink ModelManager::loadStlModel( std::string filename ) {

   Model* base = checkLoaded( filename );

   if ( base == nullptr ) {
      /*LoadedMesh mesh = loadStlMesh( filename );
      Engine::Graphics::Texture text( "Assets/Placeholder.png" );*/

      base = new Engine::Assets::Model( "temp" );
      *base = Engine::Assets::loadStlModel( filename );
      modelMap.insert( { filename, base } );

      base = checkLoaded( filename );
   }

   return ModelLink( base );
}

ModelLink ModelManager::loadCube( char* textFilename ) {

   ModelBase* base = checkLoaded( std::string( textFilename ) );

   if ( base == nullptr ) {
      /*Engine::Graphics::Cube cube;
      Engine::Graphics::Texture text( textFilename );*/

      base = new Engine::Assets::Model( "temp" );
      *base = Engine::Assets::LoadCube( textFilename );
      modelMap.insert( { std::string( textFilename ), base } );
   }

   return ModelLink( base );
}

ModelLink ModelManager::loadObjModel( std::string filename ) {
   

   ModelBase* base = checkLoaded( std::string( filename ) );

   if ( base == nullptr ) {

      /*base = new ModelBase();

      std::vector< Vector3 > verts;
      std::vector< TexCoords > uvs;
      std::vector< Tri > Tris;

      AssetStream stream( filename );
      stream.open();
      std::string line = "";
      stream >> line;

      while ( line != "" ) {

         if( line[0] == 'o' ) {
            if ( Tris.size() > 0 ) {
               std::cout << "new object has " << Tris.size() << " tris\n";
               base->addMesh( LoadedMesh( Tris ), 
                  Engine::Graphics::Texture( "Assets/Placeholder.png" ) );
            }
            std::cout << "starting object: " << line << "\n";
            //verts = std::vector< Vector3 >();
            //uvs = std::vector< TexCoords >();
            // no need to clear verts/uvs. face indicies are global
            Tris = std::vector< Tri >();
         }

         if( line[0] == 'v' && line[1] == ' ' ) {
            verts.push_back( parseVertex( line ) );
         }

         if( line[0] == 'v' && line[1] == 't' ) {
            uvs.push_back( parseUV( line ) );
         }

         if( line[0] == 'f' ) {
            //std::cout << "parsing face: " << line << "\n";
            std::vector< Tri > newTris = parseFace( line, verts, uvs );
            while ( newTris.size() > 0 ) {
               Tris.push_back( newTris.back() );
               newTris.pop_back();
            }
         }

         //all others (comment on unknown) are skipped
         stream >> line;
      }

      if ( Tris.size() > 0 ) {
         std::cout << "adding last object\n";
         std::cout << "new object has " << Tris.size() << " tris\n";
         base->addMesh( LoadedMesh( Tris ), 
            Engine::Graphics::Texture( "Assets/Placeholder.png" ) );
      }*/

      base = new Engine::Assets::Model();
      *base = Engine::Assets::loadObjModel( filename );

      modelMap.insert( { filename, base } );
   }

   std::cout << "returning model\n";

   return ModelLink( base );
}