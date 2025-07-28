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
    * @brief getter for x
    * @return x
    */
   int x();

   /**
    * @brief getter for y
    * @return y
    */
   int y();

   /**
    * @brief setter for x
    * @param x new x
    */
   void xIs( int x );

   /**
    * @brief setter for y
    * @param y new y
    */
   void yIs( int y );

   /**
    * @brief setter for position 
    * @param x x
    * @param y y
    * 
    * sets position to ( x, y )
    */
   void positionIs( int x, int y );

   /**
    * @brief piecewise add for two TilePositions
    * @param a a
    * @param b b
    * @return ( a.x + b.x, a.y + b.y )
    */
   friend TilePosition operator+ ( const TilePosition& a, const TilePosition& b );

   /**
    * @brief piecewise subtraction for two TilePositions
    * @param a a
    * @param b b
    * @return ( a.x - b.x, a.y - b.y )
    */
   friend TilePosition operator- ( const TilePosition& a, const TilePosition& b );

private:
   int _x;
   int _y;

}; // TilePosition

}

#endif // TILEPOSITION_HPP