#ifndef TINY_POTION_FACTORY_GRAPHIC_IMAGE_ANDROID_H
#define TINY_POTION_FACTORY_GRAPHIC_IMAGE_ANDROID_H

#include "stb_image.h"
#include <string>
#include "Image.h"
#include <GLES3/gl3.h>
#include <android/asset_manager.h>

namespace GRAPHICS{

    class ImageAndroid : public Image {

    public:

        /// @brief create a new image loaded from the specified filename in the resource path
        /// @param filename the resource path to pull the image from
        ImageAndroid(AAssetManager *assetMan, const std::string& filename);

        /// @brief Destroys the image after its deallocated.
        ~ImageAndroid() override;

        /// @brief sets up the texture to prepare for it to be rendered
        /// @return returns the ID that this texture can be referenced at.
        int SetupTexture() override;

    private:

        stbi_uc * data;

        GLuint id{};

    }; // ImageAndroid

} // GRAPHICS

#endif