#ifndef TINY_POTION_FACTORY_GRAPHIC_POSITION_H
#define TINY_POTION_FACTORY_GRAPHIC_POSITION_H

namespace GRAPHICS {


    class Position{
    public:

        // constructors for the postion class
        Position();
        Position(int x, int y);

        //getters for the x and y values
        int getX() {return x;}
        int getY() {return y;}

        //setters for the x and y values
        void setX(int x) {this->x = x;}
        void setY(int y) {this->y = y;}

        //setter for both x and y at once
        void setPos(int x, int y) {this->x = x; this->y = y;}


    private:
        //stores the x and y coords of the object
        int x;
        int y;
    }; //Position


}//Graphics namespace


#endif //end of Header define