#include "GameObject3D.hpp"

using namespace PotionParts;

GameObject3D::GameObject3D(Engine::Graphics::Mesh newMesh, Engine::Graphics::Texture texture) : model( mesh, text ), transform()  {}

void GameObject3D::draw(Engine::Graphics::Renderer renderer) {
    model.draw( renderer, transform );
}

