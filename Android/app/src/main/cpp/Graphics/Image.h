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

        /// @brief create a new image loaded from the specified filename in the resource path
        /// @param filename the resource path to pull the image from
        Image(const std::string& filename) {};

        /// @brief Destroys the image after its deallocated.
        ~Image() {};

        /// @brief sets up the texture to prepare for it to be rendered
        /// @return returns the ID that this texture can be referenced at.
        virtual int SetupTexture() = 0;

    private: 

        //the width and heigh of the texture in pixels
        int width;
        int heigh;

    }; // Image

} //GRAPHICS


#endif