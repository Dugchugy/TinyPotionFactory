#include "GameObject3D.hpp"

using namespace PotionParts;

GameObject3D::GameObject3D(Transform t, Model m) : model(m), transform(t)  {}

GameObject3D::GameObject3D(Engine::Graphics::Mesh mesh, Engine::Graphics::Texture text) :
   GameObject3D( mesh, text, Transform() ) {}

GameObject3D::GameObject3D( Engine::Graphics::Mesh mesh, Engine::Graphics::Texture text, Transform t ) :
   GameObject3D( t, Model( mesh, text ) ) {}

void GameObject3D::draw(Engine::Graphics::Renderer renderer) {
    model.draw( renderer, transform );
}

