#include "GridBoard.hpp"

#include "../GameObjects/Transform.hpp"
#include "../GameObjects/Model.hpp"

using namespace PotionGrid;

void GridBoard::draw( Engine::Graphics::Renderer& renderer ) {
    // calls draw on subGrids
}

void GridBoard::update( float timeSinceLastUpdate ) {
    // calls update on subGrids for each phase
}

GridBoard::GridBoard() : SerialObject(
    PotionParts::Transform(), PotionParts::ModelLink( nullptr ) ) {}