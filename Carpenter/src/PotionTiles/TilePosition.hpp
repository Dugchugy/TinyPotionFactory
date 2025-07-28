#ifndef TILEPOSITION_HPP
#define TILEPOSITION_HPP

namespace PotionGrid {

class TilePosition {
public:

   /**
    * @brief constructs tile position ( 0, 0 )
    */
   TilePosition ();

   /**
    * @brief constructs tile position ( x，y )
    * @param x x
    * @param y y
    */
   TilePosition( int x, int y );

   /**
    * @brief piecewise add for two TilePositions
    * @param a a
    * @param b b
    * @return ( a.x + b.x, a.y + b.y )
    */
   friend TilePosition operator+ ( const TilePosition& a, const TilePosition& b );


private:
   int _x;
   int _y;

}; // TilePosition

}

#endif // TILEPOSITION_HPP