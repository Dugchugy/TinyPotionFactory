#include "ImageAndroid.h"

#include <android/asset_manager.h>
#include <GLES3/gl3.h>


#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


#include "logging.h"

namespace GRAPHICS{

    /// @brief create a new image loaded from the specified filename in the resource path
    /// @param filename the resource path to pull the image from
    ImageAndroid::ImageAndroid(AAssetManager *assetMan, const std::string& filename) {

        //LOGI("loading image from file %s", filename.c_str());

        //loads the texture from the assets
        AAsset* asset = AAssetManager_open(assetMan,
                                        filename.c_str(),
                                        AASSET_MODE_BUFFER);

        //gets the length and buffer loaded
        off_t length = AAsset_getLength(asset);
        const void * buffer = AAsset_getBuffer(asset);

        if(!buffer){
            LOGE("failed to load asset at path %s", filename.c_str());
            AAsset_close(asset);
            return;
        }

        //reads the image from the asset buffer
        data = stbi_load_from_memory((const uint8_t *) buffer, length,
                                        &(this->width), &(this->height), nullptr, 4);

        if(!data){
            LOGE("Failed to load image: %s", stbi_failure_reason());
            return;
        }

        LOGI("successfully loaded image from %s with width %d  and height %d",
             filename.c_str(), this->width, this->height);



        //LOGI("finished image constructor!");

    } // end of ImageAndroid::ImageAndroid(AAssetManager *assetMan, const std::string& filename)

    int ImageAndroid::SetupTexture(){

        //creates a new texture and binds it to texture 0
        glGenTextures(1, &id);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, id);

        LOGI("preparing to store texture of size (%d, %d)",
             this->width, this->height);
        //allocates space for the texture and passes the required data
        glTexStorage2D(GL_TEXTURE_2D, 1, GL_RGBA8,
                       this->width, this->height);
        glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width, height,
                        GL_RGBA, GL_UNSIGNED_BYTE, data);

        LOGI("image set up");

        //returns 0;
        return 0;
    }

    ImageAndroid::~ImageAndroid() {
        glDeleteTextures(1, &id);

        //frees the loaded image data
        stbi_image_free(data);

    } // end of ImageAndroid::~ImageAndroid()

} // GRAPHICS