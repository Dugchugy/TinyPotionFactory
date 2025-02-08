#ifndef TINY_POTION_FACTORY_GRAPHIC_FACTORY_H
#define TINY_POTION_FACTORY_GRAPHIC_FACTORY_H

#include "Image.h"
#include "ImageStore.h"
#include <string>
#include "DisplayCamera.h"
#include <bits/stdc++.h>

namespace GRAPHICS{

    class GraphicsFactory{
    public:

        /// @brief creates a new Graphics factory with a null image store
        GraphicsFactory() {store = nullptr;}

        /// @brief destructor, clears the iamge store if it has been allocated
        ~GraphicsFactory() {if(store != nullptr) delete store;};

        /// @brief gets the current isntance of the image store
        /// @return the current image store.
        ImageStore* GetImageStore() {
            if(store == nullptr){
                store = this->genImageStore();
            }

            return store;
        }

        /// @brief loads the iamge from the passed path using the active image store
        /// @param path the path to load the image from
        /// @return the image at the resouce path, may have been cached.
        Image* getImage(const std::string& path) {
            return GetImageStore()->load_image_from_path(path, [this](const std::string& path) -> Image*{
                return this->_constructImage(path);
            });
        }

        /// @brief creates new camera object and returns it
        /// @return the new camera to be used
        virtual DisplayCamera* getCamera() const = 0;

    private:

        ImageStore* store;

    protected:

        /// @brief an abstract function used to allocate an image store as needed
        /// @return the allocated image store of the known device type
        virtual ImageStore* genImageStore() = 0;

        /// @brief DO NOT USE! calls the image constructor to construct an image. should use getImage instead
        /// @return the image constructed from the path
        virtual Image* _constructImage(const std::string& path) const = 0;

    }; // GraphicsFactory

} // GRAPHICS

#endif