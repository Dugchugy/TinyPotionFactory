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

TileObject* GridBoard::getTile( TileIdentifier id ){
    if ( tileMap.contains( id ) ) {
        return tileMap.at( id );
    } else {
        return nullptr;
    }
}

void GridBoard::addTile( TileObject object, TileIdentifier id ) {
    tileMap.insert_or_assign( id, object );
}

void delTile( TileIdentifier id ) {
    if ( tileMap.contains( id ) ) {
        TileObject* ptr = tileMap.at( id );
        tileMap.erase( id );
        delete ptr;
    }
}