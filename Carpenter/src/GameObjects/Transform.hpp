#include "Vector3.hpp"

namespace PotionParts {

class Transform {
public:

   /// @brief constructs a default transform with zero position and rotation and 1 scale
   Transform() : Transform( Vector3() ) {}

   /// @brief constructs a transform with the specified position
   Transform( Vector3 position ) : Transform( position, Vector3(), Vector3(1) ) {}

   /// @brief constructs a transform with the specified position, rotation, and scale
   Transform( Vector3 position, Vector3 rotation, Vector3 scale );

   /// @brief returns the current position
   Vector3& position();

   /// @brief returns the current rotation
   Vector3& rotation();

   /// @brief returns the current scale
   Vector3& scale();

private:

   Vector3 _position;
   Vector3 _rotation;
   Vector3 _scale;

}; // transform

} //PotionParts