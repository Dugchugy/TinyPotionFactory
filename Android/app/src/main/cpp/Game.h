//
// Created by dugch on 2025-01-03.
//

#ifndef TINY_POTION_FACTORY_GAME_H
#define TINY_POTION_FACTORY_GAME_H

#include "Graphics/DisplayCameraAndroid.h"
#include "Graphics/ImageAndroid.h"

#include <game-activity/native_app_glue/android_native_app_glue.h>

using namespace GRAPHICS;

class Game {
public:

    Game(android_app* app);
    void update(float deltaTime);

    ~Game();

private:
    DisplayCameraAndroid* cam = nullptr;

    ImageAndroid* img = nullptr;
};


#endif //TINY_POTION_FACTORY_GAME_H
