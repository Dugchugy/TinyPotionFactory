#include "Model.hpp"

#include <Graphics/Shapes.hpp>
#include <iostream>
#include <vector>

#include "LoadObjHelpers.hpp"
#include "AssetStream.hpp"

using namespace PotionParts;


Model::Model( ModelBase* base ) : _base( base ) {}

void Model::draw(Engine::Graphics::Renderer renderer, const Transform transform) const {
   _base->draw( renderer, transform );
}

ModelBase::ModelBase(): 
   subMeshs( std::vector<Engine::Graphics::Mesh>() ),
   textures( std::vector<Engine:: Graphics::Texture>() ) {}

ModelBase::ModelBase( Engine::Graphics::Mesh m, Engine::Graphics::Texture t ) : ModelBase() {
   addMesh( m, t );
}

void ModelBase::addMesh( Engine::Graphics::Mesh m, Engine::Graphics::Texture t ) {
   subMeshs.push_back( m );
   textures.push_back( t );
}

void ModelBase::draw(Engine::Graphics::Renderer renderer, Transform transform) {
   for ( int i = 0; i < subMeshs.size(); i++ ) {
      std::cout << "drawing mesh " << i << " of model\n";
      renderer.UseTexture( textures[ i ], GL_TEXTURE0 );
      renderer.DrawMesh( &subMeshs[ i ], 
         transform.position().toVec(), 
         transform.scale().toVec(), 
         transform.rotation().toVec() );
   }
} //ModelBase::draw( render, texture )

ModelManager::ModelManager() {

   modelMap = std::unordered_map<std::string, ModelBase*>();

} //ModelManager::ModelManager()


ModelManager & ModelManager::getManager() {
   static ModelManager* manager;
   if ( manager == nullptr ) {
      manager = new ModelManager();
   }
   return *manager;
}

ModelBase * ModelManager::checkLoaded( std::string filename ){
   if ( modelMap.contains( filename ) ) {
      return modelMap.at( filename );
   } else {
      return nullptr;
   }
}

Model ModelManager::loadStlModel( std::string filename ) {

   ModelBase* base = checkLoaded( filename );

   if ( base == nullptr ) {
      LoadedMesh mesh = loadStlMesh( filename );
      Engine::Graphics::Texture text( "Assets/Placeholder.png" );

      base = new ModelBase( mesh, text );
      modelMap.insert( { filename, base } );

      base = checkLoaded( filename );
   }

   return Model( base );
}

Model ModelManager::loadCube( char* textFilename ) {

   ModelBase* base = checkLoaded( std::string( textFilename ) );

   if ( base == nullptr ) {
      Engine::Graphics::Cube cube;
      Engine::Graphics::Texture text( textFilename );

      base = new ModelBase( cube, text );

      base->addMesh( cube, text );

      modelMap.insert( { std::string( textFilename ), base } );
   }

   return Model( base );
}

Model ModelManager::loadObjModel( std::string filename ) {
   

   ModelBase* base = checkLoaded( std::string( filename ) );

   if ( base == nullptr ) {

      base = new ModelBase();

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
                  Engine::Graphics::Texture( "Assets/Placeholder_2.png") );
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
            Engine::Graphics::Texture( "Assets/Placeholder_3.png") );
      }

      modelMap.insert( { filename, base } );
   }

   std::cout << "returning model\n";

   return Model( base );
}