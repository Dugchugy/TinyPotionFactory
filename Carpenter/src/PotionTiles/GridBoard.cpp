#include "GridBoard.hpp"

#include "../GameObjects/Transform.hpp"
#include "../GameObjects/Model.hpp"
#include "TileObject.hpp"

#include <iostream>

using namespace PotionGrid;

void GridBoard::draw( Engine::Graphics::Renderer& renderer ) {
   // calls draw on subGrids
   for ( auto iter = tileMap.begin(); iter != tileMap.end(); iter++ ) {
      std::cout << "drawing tile\n";
      auto currentTile = iter->second;
      currentTile->draw( renderer );
   }
}

void GridBoard::update( float timeSinceLastUpdate ) {
   // calls update on subGrids for each phase
   for ( auto iter = tileMap.begin(); iter != tileMap.end(); iter++ ) {
      auto currentTile = iter->second;

      currentTile->updatePrepare( timeSinceLastUpdate );
   }

   for ( auto iter = tileMap.begin(); iter != tileMap.end(); iter++ ) {
      auto currentTile = iter->second;

      currentTile->updateTransfer( timeSinceLastUpdate );
   }

   for ( auto iter = tileMap.begin(); iter != tileMap.end(); iter++ ) {
      auto currentTile = iter->second;

      currentTile->updateUpdate( timeSinceLastUpdate );
   }

   for ( auto iter = tileMap.begin(); iter != tileMap.end(); iter++ ) {
      auto currentTile = iter->second;

      currentTile->updateCleanup( timeSinceLastUpdate );
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
      if ( iter->bottomCorner() == flatPos ) {
         return &( *iter );
      }
   }

   if ( create ) {
      TileGrid newGrid = TileGrid( flatPos );
      subGrid.push_back( newGrid );
      return &( *subGrid.end() );
   }else {
      return nullptr;
   }
}

TileObject* GridBoard::getTile( TilePosition pos ) {
   auto curGrid = getClosestGrid( pos, false );
   
   if ( curGrid ) {
      return getTile( curGrid->getIdentifier( pos ) );
   } else {
      return nullptr;
   }
}

void GridBoard::addTile( TileObject* object ) {
   tileMap.insert_or_assign( object->id(), object );
}

void GridBoard::addTile( TileObject* object, TilePosition pos ) {
   tileMap.insert_or_assign( object->id(), object );

   auto curGrid = getClosestGrid( pos, true );

   curGrid->setIdentifier( pos, object->id() );
}

void GridBoard::delTile( TileIdentifier id ) {
   if ( tileMap.contains( id ) ) {
      TileObject* ptr = tileMap.at( id );
      tileMap.erase( id );
      delete ptr;
   }
}