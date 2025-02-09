//
// Created by dugch on 2025-01-03.
//

#include "Game.h"
#include "logging.h"
#include "Graphics/GraphicsFactoryAndroid.h"

using namespace GRAPHICS;

//runs once at begining of game
Game::Game(android_app *app) {

    fact = new GraphicsFactoryAndroid(app);

    //initalizes the renderer for future use
    cam = fact->getCamera();

    //initalizes the image to draw on screen
    img = fact->getImage("android_robot.png");

    LOGI("game initalized");
}

//deletes the renderer
Game::~Game() {
    if(cam != nullptr){
        delete cam;
    }

    if(img != nullptr){
        delete img;
    }

    if(fact != nullptr){
        delete fact;
    }
}

//runs once per frame
void Game::update(float deltaTime) {

    //starts by begining renderer update
    //renderer.beginUpdate();

    //DRAW HERE
    if(cam) {
        cam->PrepFrame();


        if(img) {
            cam->DrawImage(Position(512, 512), *img);
        }


        cam->finishFrame();

    }else{
        LOGI("failed to update, renderer null");
    }

    //ends by ending renderer update
    //renderer.endUpdate();

}