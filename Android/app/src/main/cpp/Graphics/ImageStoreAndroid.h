#ifndef TINY_POTION_FACTORY_GRAPHIC_IMAGE_STORE_ANDROID_H
#define TINY_POTION_FACTORY_GRAPHIC_IMAGE_STORE_ANDROID_H

#include "ImageStore.h"
#include "ImageAndroid.h"
#include <game-activity/native_app_glue/android_native_app_glue.h>

namespace GRAPHICS {

    class ImageStoreAndroid : public ImageStore {
    public:

        ImageStoreAndroid(android_app* app) {this->app = app;}

    protected:

        [[nodiscard]] Image* LoadNeededImage(const std::string& path) const override {
            return new ImageAndroid(this->app->activity->assetManager, path);
        }

    private:

        android_app* app;

    }; //end of ImageStoreAndroid

}//end of GRAPHICS

#endif