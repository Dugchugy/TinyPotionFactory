#include "Model.hpp"


using namespace PotionParts;

Model::draw(Engine::Graphics::Renderer renderer, Transform transform) {
   renderer.drawMesh( mesh, transform.position(), transform.rotation(), transform.scale() );
}