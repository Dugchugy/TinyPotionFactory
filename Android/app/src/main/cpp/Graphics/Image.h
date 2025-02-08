#ifndef TINY_POTION_FACTORY_GRAPHIC_IMAGE_H
#define TINY_POTION_FACTORY_GRAPHIC_IMAGE_H

#include <string>

namespace GRAPHICS{

    /// @brief Acts as a holder for an image. must be defined for the specifc system being used
    /// used by the camera to draw an object on the screen in 2D
    class Image{

    public:

        virtual ~Image() = default;

        /// @brief sets up the texture to prepare for it to be rendered
        /// @return returns the ID that this texture can be referenced at.
        virtual int SetupTexture() = 0;

        /// @brief gets the width of the image in pixels
        /// @return the images width in pixels
        int getWidth() {return width;}

        /// @brief gets the height of the image in pixels
        /// @return the images height in pixels
        int getHeight() {return height;}

    protected: 

        //the width and heigh of the texture in pixels
        int width;
        int height;

    }; // Image

} //GRAPHICS


#endif