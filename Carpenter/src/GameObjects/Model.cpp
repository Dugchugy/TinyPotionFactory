#include "Model.hpp"


using namespace PotionParts;

Model::draw(Engine::Graphics::Renderer renderer, Transform transform) {
   renderer.UseTexture( text, GL_TEXTURE0 );
   renderer.DrawMesh( &mesh, transform.position(), transform.rotation(), transform.scale() );
}