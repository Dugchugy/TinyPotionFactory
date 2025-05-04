#ifndef TINY_POTION_FACTORY_GRAPHIC_GOBJECT2D_H
#define TINY_POTION_FACTORY_GRAPHIC_GOBJECT2D_H

#include "GObject.h"
#include "Image.h"
#include "DisplayCamera.h"
#include <string>
#include "GraphicsFactory.h"

namespace GRAPHICS {

    class GObject2D : public GObject {

    public:

        /// @brief creates a new graphics object with the specifed image loaded with the passed factory
        /// @param pos the position of the graphics object
        /// @param path the resource path to load the image from
        /// @param f the graphics factory to load the resources with
        /// @param offset the offset to apply onto the image from 0, 0
        GObject2D(Position pos, const std::string& path, GraphicsFactory& f, Position offset)
        : GObject(pos) {
            im = f.getImage(path);
            this->offset = offset;
        }

        /// @brief creates a new graphics object with the specifed image loaded with the passed factory
        /// @param pos the position of the graphics object
        /// @param path the resource path to load the image from
        /// @param f the graphics factory to load the resources with
        GObject2D(Position pos, const std::string& path, GraphicsFactory& f)
        : GObject2D(pos, path, f, Position(0, 0)) {}

        /// @brief creates a new graphics object with the specifed image loaded with the passed factory
        /// @param path the resource path to load the image from
        /// @param f the graphics factory to load the resources with
        GObject2D(const std::string& path, GraphicsFactory& f)
        : GObject2D(Position(0, 0), path, f, Position(0, 0)) {}

        /// @brief draws the GraphicsObject using the current camera
        /// @param cam the camera to draw the graphics object with
        virtual void Draw(DisplayCamera& cam){
            cam.DrawImage(*this->getPosition() - this->offset, *this->im);
        }


    protected: 

        /// @brief a pointer to the iamge used by the graphic objects 2D
        Image* im;

        Position offset;

    }; //GOBject 2D
} // GRAPHCIS

#endif