#ifndef TINY_POTION_FACTORY_GRAPHIC_POSITION_H
#define TINY_POTION_FACTORY_GRAPHIC_POSITION_H

#include "Graphics/Position.h"

namespace GRAPHICS {

    class GObject {
    public:
        /// @brief gets a pointer to the current position of the object
        /// @return the current psotion pointer
        Position* getPosition() {return &this->pos;}

    private:
        Position pos; 
    }; // GObject

} //GRAPHICS

#endif