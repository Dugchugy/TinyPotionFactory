//
// Created by dugch on 2025-05-04.
//

#ifndef TINY_POTION_FACTORY_GAME_GAMEGRID_H
#define TINY_POTION_FACTORY_GAME_GAMEGRID_H

#include "GameObject.h"
#include "GridObject.h"

namespace GAME
{

    class GameGrid : public GameObject {

    public:

    private:

        ///stores a variable array of grid object that determines the
        /// middle layer of objects in the grid
        GridObject** middleLayer;

        ///stores a variable array of grid object that determines the
        /// ground layer of objects in the grid
        GridObject** groundLayer;

        uint width;
        uint height;

        

    }; // GameGrid

} //GAME

#endif //TINY_POTION_FACTORY_GAME_GAMEGRID_H
