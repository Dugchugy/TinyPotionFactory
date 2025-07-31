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

private:
   unsigned long _index;

}; //TileIdentifier

} //PotionGrid 

#endif //TILEIDENTIFIER_HPP