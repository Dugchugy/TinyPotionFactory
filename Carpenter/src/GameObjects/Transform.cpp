#include "Transform.hpp"

using namespace PotionParts;

Transform::Transform( Vector3 position, Vector3 rotation, Vector3 scale ) {
   _posotion = position;
   _rotation = rotation;
   _scale = scale;
}

Vector3& Transform::position() {
   return _position;
}

Vector3& Transform::rotation() {
   return _rotation;
}

Vector3& Transform::scale() {
   return _scale;
}