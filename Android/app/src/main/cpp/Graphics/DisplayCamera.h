#ifndef TINY_POTION_FACTORY_GRAPHIC_IMAGE_H
#define TINY_POTION_FACTORY_GRAPHIC_IMAGE_H

#include "Graphics/GObject.h"
#include "Graphics/Position.h"
#include "Graphics/Image.h"

namespace GRAPHICS {

    /// @brief creats a camera used to render things on to the screen. only one should be needed
    class DisplayCamera : public GObject {

        /// @brief Draws teh passed image on the screen at the passed position
        /// @param pos the position of the image, position is in world space.
        /// @param i the image to draw.
        virtual void DrawImage(Position pos, Image i) = 0;

    }; //DisplayCamera

} //GRAPHICS

#endif