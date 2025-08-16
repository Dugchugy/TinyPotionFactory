#ifndef TILEIDENTIFIER_HPP
#define TILEIDENTIFIER_HPP

#include <functional>

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
   unsigned long index() const;

   /**
    * @brief gets the type for this Tile
    */
   TileType type() const;

   /**
    * @brief checks if this tileIdentifier is equal to the passed identifier
    * 
    * checks if the index and type are the same on both
    */
   bool operator==( const TileIdentifier& comp ) const;

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
   static void nextIndexIs( unsigned long index );

private:
   unsigned long _index;
   TileType _type;

   static unsigned long _nextIndex;

}; //TileIdentifier

} //PotionGrid 

template <>
struct std::hash< PotionGrid::TileIdentifier > {
   std::size_t operator() ( const PotionGrid::TileIdentifier& k ) const {
      return k.index();
   }
}; //std::hash< PotionGrid::TileIdentifier >

#endif //TILEIDENTIFIER_HPP