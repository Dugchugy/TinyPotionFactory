//
// Created by dugch on 2025-01-03.
//
#include <game-activity/GameActivity.cpp>
#include <game-text-input/gametextinput.cpp>

#include <chrono>

#include "logging.h"
#include "Graphics\ImageAndroid.h"
#include "Graphics\DisplayCameraAndroid.h"

extern "C" {
//includes android c file to make android work (needed for app to work)
#include <game-activity/native_app_glue/android_native_app_glue.c>

void handleAppCmd(android_app* app, int32_t cmd){
    
    LOGD("Processing app command:");

    if(cmd == APP_CMD_INIT_WINDOW){
        LOGD("initiated window");
        //creates a new game obejct
        Game* game = new Game(app);
        //stores the game in the user data
        app->userData = game;
    }else if(cmd == APP_CMD_TERM_WINDOW){
        LOGD("exiting app");

        //re-obtains the game from the user data
        Game* game = reinterpret_cast<Game*>(app->userData);
        //clears the user data
        app->userData = nullptr;
        //deletes the game
        delete game;
    }

}

//app main file. acts as start of program (takes app as argument)
void android_main(android_app* app){

    LOGD("entering android_main in main.cpp");

    //sets app command handler
    app->onAppCmd = handleAppCmd;

    //vars to store the number of events and the source for events
    int events;
    android_poll_source* pollSource;
    std::chrono::steady_clock::time_point lastTime = std::chrono::high_resolution_clock::now();

    //primary loop, runs while app is running
    do{
        //gets the current time and calculates time between frames
        std::chrono::steady_clock::time_point  currentTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        //requests events from OS
        if(ALooper_pollOnce(0, nullptr, &events, (void**) &pollSource) >= 0){
            //processes the events as needed
            if(pollSource) pollSource->process(app, pollSource);
        }

        //checks if the game has been initalized
        if(app->userData){
            Game* game = reinterpret_cast<Game*>(app->userData);

            game->update(deltaTime.count());
        }
    }while(!app->destroyRequested);

}


} // end of extern "C"