#include "Graphics/ImageAndroid.h"

#include <android/asset_manager.h>
#include <GLES3/gl3.h>

#include "stb_image.h"

#include "logging.h"

namespace GRAPHICS{

    /// @brief create a new image loaded from the specified filename in the resource path
    /// @param filename the resource path to pull the image from
    ImageAndroid::ImageAndroid(AAssetManager *assetMan, const std::string& filename) {


        //loads the texture from the assets
        AAsset* asset = AAssetManager_open(assetMan,
                                        filePath.c_str(),
                                        AASSET_MODE_BUFFER);

        //gets the length and buffer loaded
        off_t length = AAsset_getLength(asset);
        const void * buffer = AAsset_getBuffer(asset);

        if(!buffer){
            LOGE("failed to load asset at path %s", filePath.c_str());
            AAsset_close(asset);
            return;
        }

        //reads the image from the asset buffer
        ImgData = stbi_load_from_memory((const uint8_t *) buffer, length,
                                        &width, &height, nullptr, 4);

        if(!ImgData){
            LOGE("Failed to load image: %s", stbi_failure_reason());
            return;
        }

    } // end of ImageAndroid::ImageAndroid(AAssetManager *assetMan, const std::string& filename)

    ImageAndroid::~ImageAndroid() {
        //frees the loaded image data
        stbi_image_free(ImgData);
    } // end of ImageAndroid::~ImageAndroid()

} // GRAPHICS