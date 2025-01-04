//
// Created by dugch on 2025-01-03.
//
#include <game-activity/GameActivity.cpp>
#include <game-text-input/gametextinput.cpp>

extern "C" {
//includes android c file to make android work (needed for app to work)
#include <game-activity/native_app_glue/android_native_app_glue.c>
#include "logging.h"

void handleAppCmd(android_app* app, int32_t cmd){
    //TODO
    LOGD("Processing app command:");

    if(cmd == APP_CMD_INIT_WINDOW){
        LOGD("initiated window");
    }else if(cmd == APP_CMD_TERM_WINDOW){
        LOGD("exiting app");
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

    //primary loop, runs while app is running
    do{
        //requests events from OS
        if(ALooper_pollOnce(0, nullptr, &events, (void**) &pollSource) >= 0){
            //processes the events as needed
            if(pollSource) pollSource->process(app, pollSource);
        }
    }while(!app->destroyRequested);

}


} // end of extern "C"