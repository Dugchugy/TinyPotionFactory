//
// Created by dugch on 2025-01-03.
//

#include "Game.h"
#include "logging.h"

using namespace GRAPHICS;

//runs once at begining of game
Game::Game(android_app *app) {
    //initalizes the renderer for future use
    cam = new DisplayCameraAndroid(app);

    //initalizes the image to draw on screen
    img = new ImageAndroid(app->activity->assetManager, "android_robot.png");

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
}

//runs once per frame
void Game::update(float deltaTime) {

    //starts by begining renderer update
    //renderer.beginUpdate();

    //DRAW HERE
    if(cam) {
        cam->PrepFrame();

        LOGI("frame prepped");

        if(img) {
            cam->DrawImage(Position(-256, -256), *img);
        }

        LOGI("images drawn");

        cam->finishFrame();

        LOGI("frame finished");
    }else{
        LOGI("failed to update, renderer null");
    }

    //ends by ending renderer update
    //renderer.endUpdate();

}