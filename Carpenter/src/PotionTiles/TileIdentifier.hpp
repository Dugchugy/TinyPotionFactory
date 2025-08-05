#ifndef TILEIDENTIFIER_HPP
#define TILEIDENTIFIER_HPP

namespace PotionGrid {

enum TileType {
   NullTile,
   CauldronTile,
   SalesBoxTile,
   BottlerTile,
   LecturnTile
}; //TileType

class TileIdentifier {
public:

   TileIdentifier();

   TileIdentifier( TileType type );

   /**
    * @brief gets the index for this Identifier
    */
   unsigned long index();

   /**
    * @brief gets the type for this Tile
    */
   TileType type();

   /**
    * @brief equality operator for TileIdentifiers
    *
    * checks if the index and type are the same on `a` and `b`
    */
   friend bool operator==( const TileIdentifier& a, const TileIdentifier& b );

   /**
    * @brief gets the next available index for identifiers
    *
    * increments the next index so each time this is called the index is unique
    */
   static unsigned long nextIndex();

   /**
    * @brief sets the next index provided by `nextIndex()`
    *
    * used to prevent counting from zero after loading.
    */
   static void NextIndexIs( unsigned long index );

private:
   unsigned long _index;
   TileType _type;

   static unsigned long _nextIndex = 0;

}; //TileIdentifier

} //PotionGrid 

#endif //TILEIDENTIFIER_HPP