#ifndef TINY_POTION_FACTORY_GRAPHIC_GOBJECT_H
#define TINY_POTION_FACTORY_GRAPHIC_GOBJECT_H

#include "Graphics/Position.h"

namespace GRAPHICS {

    class GObject {
    public:
        /// @brief gets a pointer to the current position of the object
        /// @return the current psotion pointer
        Position* getPosition() {return &this->pos;}

        /// @brief adds the passed X and Y coords to the GObjects position
        /// @param X the amount to add to the X coord
        /// @param Y the amount to add to the Y coord
        void Move(int X, int Y) {pos.setPos(pos.getX() + X, pos.getY() + Y);}

    private:
        Position pos; 
    }; // GObject

} //GRAPHICS

#endif