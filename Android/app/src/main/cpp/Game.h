//
// Created by dugch on 2025-01-03.
//

#ifndef TINY_POTION_FACTORY_GAME_H
#define TINY_POTION_FACTORY_GAME_H

#include "Renderer.h"

#include <game-activity/native_app_glue/android_native_app_glue.h>

class Game {
public:

    void begin(android_app* app);
    void update(float deltaTime);

private:
    Renderer renderer;
};


#endif //TINY_POTION_FACTORY_GAME_H
