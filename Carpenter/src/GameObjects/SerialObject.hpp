#ifndef SERIALOBJECT_HPP
#define SERIALOBJECT_HPP

#include "GameObject3D.hpp"
#include "Transform.hpp"
#include "Model.hpp"

/**
 * stores on object that can be serialized and written into a file
 */
class SerialObject : public GameObject3D {
public:
   SerialObject( Transform t, ModelLink m ) : GameObject3D( t, m ) {}
}

#endif //SERIALOBJECT_HPP