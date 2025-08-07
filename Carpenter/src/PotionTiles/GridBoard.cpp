#include "GridBoard.hpp"

#include "../GameObjects/Transform.hpp"
#include "../GameObjects/Model.hpp"

using namespace PotionGrid;

void GridBoard::draw( Engine::Graphics::Renderer& renderer ) {
   // calls draw on subGrids
}

void GridBoard::update( float timeSinceLastUpdate ) {
   // calls update on subGrids for each phase
   for ( auto iter = tileMap.begin(); iter != tileMap.end(); iter++ ) {
      auto currentTile = iter->first;

      tileMap[ currentTile ]->updatePrepare();
   }

   // calls update on subGrids for each phase
   for ( auto iter = tileMap.begin(); iter != tileMap.end(); iter++ ) {
      auto currentTile = iter->first;

      tileMap[ currentTile ]->updateTransfer();
   }

   // calls update on subGrids for each phase
   for ( auto iter = tileMap.begin(); iter != tileMap.end(); iter++ ) {
      auto currentTile = iter->first;

      tileMap[ currentTile ]->updateUpdate();
   }

   // calls update on subGrids for each phase
   for ( auto iter = tileMap.begin(); iter != tileMap.end(); iter++ ) {
      auto currentTile = iter->first;

      tileMap[ currentTile ]->updateCleanup();
   }
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