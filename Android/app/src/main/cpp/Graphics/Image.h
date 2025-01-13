#ifndef TINY_POTION_FACTORY_GRAPHIC_IMAGE_H
#define TINY_POTION_FACTORY_GRAPHIC_IMAGE_H

#include <string>

namespace GRAPHICS{

    /// @brief Acts as a holder for an image. must be defined for the specifc system being used
    /// used by the camera to draw an object on the screen in 2D
    class Image{

    public:
        /// @brief default constructor, creates an empty image
        Image() {}; 

        /// @brief Destroys the image after its deallocated.
        ~Image() {};

    }; // Image

} //GRAPHICS


#endif