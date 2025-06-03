
namespace PotionParts {

class Transform {
public:

   /// @brief constructs a default transform with zero position and rotation and 1 scale
   Transform();

   /// @brief constructs a transform with the specified position
   Transform( float position );

   /// @brief constructs a transform with the specified position, rotation, and scale
   Transform( float position, float rotation, float scale );

private:

   Vector3 _position;
   Vector3 _rotation;
   Vector3 _scale;

}; // transform

} //PotionParts