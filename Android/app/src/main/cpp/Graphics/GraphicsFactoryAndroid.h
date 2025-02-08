#ifndef TINY_POTION_FACTORY_GRAPHIC_FACTORY_ANDROID_H
#define TINY_POTION_FACTORY_GRAPHIC_FACTORY_ANDROID_H

#include "GraphicsFactory.h"
#include "DisplayCamera.h"
#include "DisplayCameraAndroid.h"
#include "Image.h"
#include "ImageAndroid.h"
#include "ImageStore.h"

namespace GRAPHICS {

    class GraphicsFactoryAndroid : public GraphicsFactory {

    public:

        GraphicsFactoryAndroid(android_app* app){ this-> app = app;}

        [[nodiscard]] DisplayCamera* getCamera() const override { return new DisplayCameraAndroid(app);}

    protected:

        ImageStore* genImageStore() override { return new ImageStore();}

        [[nodiscard]] Image* _constructImage(const std::string& path) const override {
            return new ImageAndroid(app->activity->assetManager, path);
        }

    private:

        android_app* app;

    }; //end of GraphicsFactoryAndroid

} //end of Graphics

#endif
