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

   for ( auto iter = tileMap.begin(); iter != tileMap.end(); iter++ ) {
      auto currentTile = iter->first;

      tileMap[ currentTile ]->updateTransfer();
   }

   for ( auto iter = tileMap.begin(); iter != tileMap.end(); iter++ ) {
      auto currentTile = iter->first;

      tileMap[ currentTile ]->updateUpdate();
   }

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

TileGrid* GridBoard::getClosestGrid( TilePosition pos, bool create ) {
   TilePosition flatPos = TilePosition( pos.x() - ( pos.x() % GRID_SIZE ),
                                        pos.y() - ( pos.y() % GRID_SIZE ) );

   for ( auto iter = subGrid.begin(); iter != subGrid.end(); iter++ ) {
      if ( iter->first.bottomCorner() == flatPos ) {
         return iter->first;
      }
   }

   if ( create ) {
      TileGrid newGrid = TileGrid( flatPos );
      subGrid.pushBack( newGrid );
      return subGrid.end()->first
   }else {
      return nullptr;
   }
}

TileObject* GridBoard::getTile( TilePosition pos ) {
   auto subGrid = getClosestGrid( pos, false );
   
   if ( subGrid ) {
      return getTile( subGrid.getIdentifier( pos ) );
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