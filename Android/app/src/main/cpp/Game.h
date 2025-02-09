//
// Created by dugch on 2025-01-03.
//

#ifndef TINY_POTION_FACTORY_GAME_H
#define TINY_POTION_FACTORY_GAME_H

#include "Graphics/DisplayCamera.h"
#include "Graphics/Image.h"
#include "Graphics/GraphicsFactory.h"

#include <game-activity/native_app_glue/android_native_app_glue.h>

using namespace GRAPHICS;

class Game {
public:

    Game(android_app* app);
    void update(float deltaTime);

    ~Game();

private:
    DisplayCamera* cam = nullptr;

    Image* img = nullptr;

    GraphicsFactory* fact = nullptr;


};


#endif //TINY_POTION_FACTORY_GAME_H
