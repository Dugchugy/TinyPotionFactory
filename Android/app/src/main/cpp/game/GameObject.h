#ifndef TINY_POTION_FACTORY_GAME_GAMEOBJECT_H
#define TINY_POTION_FACTORY_GAME_GAMEOBJECT_H

#include "Graphics/GObject2D.h"
#include "Graphics/Image.h"
#include "Graphics/DisplayCamera.h"
#include "Graphics/GraphicsFactory.h"

using GRAPHICS::Position;
using GRAPHICS::Image;
using GRAPHICS::GraphicsFactory;

namespace GAME
{
    class GameObject : public GRAPHICS::GObject2D {

    public:

        /// @brief creates a new game object with the specifed image loaded with the passed factory
        /// @param pos the position of the game object
        /// @param path the resource path to load the image from
        /// @param f the graphics factory to load the resources with
        /// @param offset the offset to apply onto the image from 0, 0
        GameObject(Position pos, const std::string& path, GraphicsFactory& fact, Position offset)
        : GObject2D(pos, path, fact, offset) {}

        /// @brief creates a new game object with the specifed image loaded with the passed factory
        /// @param pos the position of the game object
        /// @param path the resource path to load the image from
        /// @param f the graphics factory to load the resources with
        GameObject(Position pos, const std::string& path, GraphicsFactory& fact)
        : GObject2D(pos, path, fact) {}

        /// @brief creates a new game object with the specifed image loaded with the passed factory
        /// @param path the resource path to load the image from
        /// @param f the graphics factory to load the resources with
        GameObject(const std::string& path, GraphicsFactory& fact)
        : GObject2D(path, fact) {}
        
        /// @brief tirggers a physics update for this game object. does nothing by default but should be overwritten by subclasses
        /// @param timedelta the time in seconds since the last update
        virtual void update(float timedelta) {}

    }; // GameObject
} //GAME


#endif