#include "Model.hpp"


using namespace PotionParts;

Model::Model(): 
   subMeshs( std::vector<Engine::Graphics::Mesh>() ),
   textures(std::vector<Engine:: Graphics::Texture>() ) {}

Model::Model( Engine::Graphics::Mesh m, Engine::Graphics::Texture t ) : Model() {
   addMesh( m, t );
}

void Model::addMesh( Engine::Graphics::Mesh m, Engine::Graphics::Texture t ) {
   subMeshs.push( m );
   textures.push( t );
}

void Model::draw(Engine::Graphics::Renderer renderer, Transform transform) {
   for ( int i = 0; i < subMeshs.length(); i++ ) {
      renderer.UseTexture( textures[ i ], GL_TEXTURE0 );
      renderer.DrawMesh( &subMeshs[ i ], 
         transform.position().toVec(), 
         transform.scale().toVec(), 
         transform.rotation().toVec() );
   }
}