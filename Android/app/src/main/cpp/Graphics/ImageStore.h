#ifndef TINY_POTION_FACTORY_GRAPHIC_IMAGE_STORE_H
#define TINY_POTION_FACTORY_GRAPHIC_IMAGE_STORE_H

#include <unordered_map>
#include <functional>
#include <string>

#include "Image.h"

namespace GRAPHICS{

    class ImageStore {

    public:

        /// @brief default constructor, creates an empty image store
        ImageStore();

        /// @brief descructor, destroys the current image Store and releases its memory
        virtual ~ImageStore();

        /// @brief loads an image from the resouce stores with the specified path
        /// @param path the path to find the image to load
        /// @return the image found at the passed path (may be loaded)
        Image* load_image_from_path(const std::string& path);

    protected:

        /// @brief clears all mappings stored in the image store, functionally reseting it. very unsafe
        void Clear();

        [[nodiscard]] virtual Image* LoadNeededImage(const std::string& path) const = 0;


    private:

        /// @brief stores the map of all images loaded with the image store
        std::unordered_map<std::string, Image*> ImageSet;

    };

} // GRAPHICS

#endif