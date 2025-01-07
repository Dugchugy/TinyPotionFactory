//
// Created by dugch on 2025-01-06.
//

#ifndef TINY_POTION_FACTORY_TEXTURE_H
#define TINY_POTION_FACTORY_TEXTURE_H

#include <string>
#include <GLES3/gl3.h>
#include <android/asset_manager.h>


class Texture {
public:

    explicit Texture(AAssetManager *assetMan, const std::string  & filePath);
    ~Texture();

    [[nodiscard]] int get_width() const {return width;}
    [[nodiscard]] int get_height() const {return height;}
    [[nodiscard]] GLuint get_id() const {return id;}

private:
    int width{}, height{};
    GLuint id{};

};


#endif //TINY_POTION_FACTORY_TEXTURE_H
