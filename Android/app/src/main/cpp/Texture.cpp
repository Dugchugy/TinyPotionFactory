//
// Created by dugch on 2025-01-06.
//

#include "Texture.h"

#include <android/asset_manager.h>
#include <GLES3/gl3.h>

#define STB_IMAGE_IMPLEMENTATION

#include "logging.h"
#include "stb_image.h"

Texture::Texture(AAssetManager *assetMan, const std::string &filePath) {
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

    //reads teh image from the asset buffer
    stbi_uc * data = stbi_load_from_memory((const uint8_t *) buffer, length,
                                      &width, &height, nullptr, 4);

    if(!data){
        LOGE("Failed to load image: %s", stbi_failure_reason());
        return;
    }

    //creates a new texture and binds it to texture 0
    glGenTextures(1, &id);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, id);

    //allocates space for the texture and passes the required data
    glTexStorage2D(GL_TEXTURE_2D, 1, GL_RGBA8, width, height);
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width, height,
                    GL_RGBA, GL_UNSIGNED_BYTE, data);

    //frees the loaded image data
    stbi_image_free(data);
} //Texture::Texture

Texture::~Texture() {
    glDeleteTextures(1, &id);
}