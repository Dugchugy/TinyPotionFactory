#include "Model.hpp"


using namespace PotionParts;


Model::Model( ModelBase* base ) : _base( base ) {}

Model::Draw(Engine::Graphics::Renderer renderer, const Transform transform) const {
   _base->Draw( renderer, transform );
}

ModelBase::ModelBase(): 
   subMeshs( std::vector<Engine::Graphics::Mesh>() ),
   textures(std::vector<Engine:: Graphics::Texture>() ) {}

ModelBase::ModelBase( Engine::Graphics::Mesh m, Engine::Graphics::Texture t ) : Model() {
   addMesh( m, t );
}

void ModelBase::addMesh( Engine::Graphics::Mesh m, Engine::Graphics::Texture t ) {
   subMeshs.push( m );
   textures.push( t );
}

void ModelBase::draw(Engine::Graphics::Renderer renderer, const Transform transform) const {
   for ( int i = 0; i < subMeshs.length(); i++ ) {
      renderer.UseTexture( textures[ i ], GL_TEXTURE0 );
      renderer.DrawMesh( &subMeshs[ i ], 
         transform.position().toVec(), 
         transform.scale().toVec(), 
         transform.rotation().toVec() );
   }
}