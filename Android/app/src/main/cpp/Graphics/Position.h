#ifndef TINY_POTION_FACTORY_GRAPHIC_POSITION_H
#define TINY_POTION_FACTORY_GRAPHIC_POSITION_H

namespace GRAPHICS {


    class Position{
    public:

        // constructors for the postion class

        /// @brief initalizes the Position with x and y set to 0
        Position() {this->x = 0, this->y = 0;}

        /// @brief initializes the position with set x and y values
        /// @param x the x coordinate to use
        /// @param y the y coordinate to use
        Position(int x, int y) {this->x = x; this->y = y;}

        //getters for the x and y values

        /// @brief gets the current value of x
        /// @return the x value
        int getX() {return x;}

        /// @brief gets the current value of y
        /// @return the y value
        int getY() {return y;}

        //setters for the x and y values

        /// @brief sets x to the passed argument
        /// @param x the new value for x
        void setX(int x) {this->x = x;}

        /// @brief sets y to the passed argument
        /// @param y the new value for y
        void setY(int y) {this->y = y;}

        //setter for both x and y at once

        /// @brief sets both x and y at the same time.
        /// @param x the new value for x
        /// @param y the new value for y
        void setPos(int x, int y) {this->x = x; this->y = y;}

    private:
        //stores the x and y coords of the object
        int x;
        int y;
    }; //Position

    Position operator +(const Position& A, const Position& B){
        return Position(A.x + B.x, A.y + B.y);
    }

    Position operator -(const Position& A, const Position& B){
        return Position(A.x - B.x, A.y - B.y);
    }


}//Graphics namespace


#endif //end of Header define