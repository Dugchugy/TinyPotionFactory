#include "GameObject3D.hpp"

using namespace PotionParts;

GameObject3D::GameObject3D(Engine::Graphics::Mesh newMesh, Engine::Graphics::Texture texture) :
    GameObject("a 3d object"), text(texture), mesh(newMesh) {}

void GameObject3D::draw(Engine::Graphics::Renderer renderer) {
    model.draw( renderer, transform );
}

