#ifndef TINY_POTION_FACTORY_GRAPHIC_FACTORY_ANDROID_H
#define TINY_POTION_FACTORY_GRAPHIC_FACTORY_ANDROID_H

#include "GraphicsFactory.h"
#include "DisplayCamera.h"
#include "DisplayCameraAndroid.h"
#include "Image.h"
#include "ImageAndroid.h"
#include "ImageStore.h"
#include "ImageStoreAndroid.h"
#include <game-activity/native_app_glue/android_native_app_glue.h>

namespace GRAPHICS {

    class GraphicsFactoryAndroid : public GraphicsFactory {

    public:

        GraphicsFactoryAndroid(android_app* app){ this-> app = app;}

        [[nodiscard]] DisplayCamera* getCamera() const override {
            LOGI("creating enw DisplayCamera");
            return new DisplayCameraAndroid(app);
        }

    protected:

        ImageStore* genImageStore() override { return new ImageStoreAndroid(this->app);}

    private:

        android_app* app;

    }; //end of GraphicsFactoryAndroid

} //end of Graphics

#endif
