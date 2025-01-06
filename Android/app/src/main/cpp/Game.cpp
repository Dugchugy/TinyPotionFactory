//
// Created by dugch on 2025-01-03.
//

#include "Game.h"
#include "logging.h"

//runs once at begining of game
Game::Game(android_app *app) {
    //initalizes the renderer for future use
    renderer = new Renderer(app);
}

//deletes the renderer
Game::~Game() {
    if(renderer != nullptr){
        delete renderer;
    }
}

//runs once per frame
void Game::update(float deltaTime) {

    //starts by begining renderer update
    //renderer.beginUpdate();

    //DRAW HERE
    if(renderer) {
        renderer->doFrame();
    }else{
        LOGI("failed to update, renderer null");
    }

    //ends by ending renderer update
    //renderer.endUpdate();

}