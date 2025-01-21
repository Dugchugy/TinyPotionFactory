#ifndef TINY_POTION_FACTORY_GRAPHIC_GOBJECT2D_H
#define TINY_POTION_FACTORY_GRAPHIC_GOBJECT2D_H

#include "Graphics/GObject.h"
#include "Graphics/Image.h"
#include "Graphics/DisplayCamera.h"

namespace GRAPHICS {

    class GObject2D : public GObject {

    public:

        /// @brief draws the GraphicsObject using the current camera
        /// @param cam the camera to draw the graphics object with
        void Draw(DisplayCamera& cam){cam.DrawImage(*this->getPosition(), *this->im);}


    protected: 

        /// @brief a pointer to the iamge used by the graphic objects 2D
        Image* im;

    }; //GOBject 2D
} // GRAPHCIS

#endif