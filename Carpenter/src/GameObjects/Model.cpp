#include "Model.hpp"


using namespace PotionParts;

Model::Model(): 
   subMeshs( std::vector<Engine::Graphics::Mesh>() ),
   textures(std::vector<Engine:: Graphics::Texture>() ) {}

Model::Model( Engine::Graphics::Mesh m, Engine::Graphics::Texture t ) : Model() {
   addMesh( m, t );
}

void Model::draw(Engine::Graphics::Renderer renderer, Transform transform) {
   renderer.UseTexture( text, GL_TEXTURE0 );
   renderer.DrawMesh( &mesh, 
      transform.position().toVec(), 
      transform.scale().toVec(), 
      transform.rotation().toVec() );
}