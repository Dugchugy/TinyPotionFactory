#ifndef TINY_POTION_FACTORY_GRAPHIC_FACTORY_H
#define TINY_POTION_FACTORY_GRAPHIC_FACTORY_H

#include "Graphics/Image.h"
#include "Graphics/ImageStore.h"
#include <string>
#include "Graphics/DisplayCamera.h"

namespace GRAPHICS{

    class GraphicsFactory{
    public:

        /// @brief destructor, clears the iamge store if it has been allocated
        ~GraphicsFactory() {if(store != nullptr) delete store;};

        /// @brief gets the current isntance of the image store
        /// @return the current image store.
        ImageStore* GetImageStore() {
            if(store == nullptr){
                store = genImageStore();
            }

            return store;
        }

        /// @brief loads the iamge from the passed path using the active image store
        /// @param path the path to load the image from
        /// @return the image at the resouce path, may have been cached.
        Image* getImage(std::string path) {return GetImageStore()->load_image_from_path(path);}

        virtual DisplayCamera getCamera() = 0;

    private:

        ImageStore* store;

    protected:

        /// @brief an abstract function used to allocate an image store as needed
        /// @return the allocated image store of the known device type
        virtual ImageStore* genImageStore() = 0;

    }; // GraphicsFactory

} // GRAPHICS

#endif