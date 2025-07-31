#ifndef TILEIDENTIFIER_HPP
#define TILEIDENTIFIER_HPP

namespace PotionGrid {

class TileIdentifier {
public:

   TileIdentifier();

   /**
    * @brief gets the index for this Identifier
    */
   unsigned long index();

   /**
    * @brief gets the next available index for identifiers
    *
    * increments the next index so each time this is called the index is unique
    */
   static unsigned long getNextIndex();

   /**
    * @brief sets the next index provided by `getNextIndex()`
    *
    * used to prevent counting from zero after loading.
    */
   static void setNextIndex( unsigned long index );

private:
   unsigned long _index;

   static unsigned long nextIndex = 0;

}; //TileIdentifier

} //PotionGrid 

#endif //TILEIDENTIFIER_HPP