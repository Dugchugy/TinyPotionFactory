#include "GameObject3D.hpp"

using namespace PotionParts;

GameObject3D::GameObject3D(Transform t, Model m) : model(m), transform(t)  {}

void GameObject3D::draw(Engine::Graphics::Renderer renderer) {
    model.draw( renderer, transform );
}

