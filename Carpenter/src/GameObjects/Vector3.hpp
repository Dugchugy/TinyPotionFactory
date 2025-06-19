#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include<Utils.hpp>
#include <Graphics/Mesh.hpp>

namespace PotionParts {

class Vector3 {
public:

   /// @breif constructs a Vector3 with zero for all aspects
   Vector3() : Vector3( 0, 0, 0 ) {}

   /// @brief constructs a Vector3 with all attributes having the same value x
   Vector3( float x ) : Vector3( x, x, x ) {}

   /// @brief constructs a Vector3 with the specified X, Y, and Z coordinates
   Vector3( float x, float y, float z );

   /// @brief gets the x value
   float x() const;

   /// @brief gets the y value
   float y() const;

   /// @brief gets the z value
   float z() const;

   /// @brief sets the x value
   void xIs( float x );

   /// @brief sets the y value
   void yIs( float y );

   /// @brief sets the z value
   void zIs( float z );

   /// @brief sets all 3 values
   void set( float x, float y, float z );

   /// @brief converts the vector into a Vec3f for engine compatability
   /// @return the vector as a Vec3f struct
   Engine::Vec3f toVec() const;

   /// @brief calcualtes the magintude of this Vector3
   /// @return 
   float mag() const;

   /// @brief normalizes this vector3 by dividing all of its values by its magnitude (should have magnitude 1 after)
   void normalize();

   /// @brief creates a new vertex from this vector3 using the passed U and V values
   /// @param u the u coordinate for the texture for this vertex
   /// @param v the V coordinate for the texture for this vertex
   /// @return a vertex created from this Vector3
   Engine::Graphics::Vertex toVertex(float u, float v) const;

   /// @brief compares two vector3s to see if they're equal within a specified error amount
   /// @param v1 the first vector
   /// @param v2 the second vector
   /// @param err maximum allowed magnitude of difference between v1 and v2
   /// @return true if v1 is withing err of v2, otherwise false
   friend bool equalError( Vector3 v1, Vector3 v2, float err );

   /// @brief calculates the cross product of 2 3D vectors
   /// @param a the first vector inm the cross product
   /// @param b the second vector in the cross product
   /// @return the cross product of the two vectors
   /// the value is calculated as {(a.y*b.z) - (a.z*b.y), (a.x*b.z)-(a.z*b.x), (a.x*b.y)-(a.y*b.x)}
   friend Vector3 cross( Vector3 const& a, Vector3 const& b );

   /// @brief preforms componentwise add of two vector3s
   /// @param v1 the first vector
   /// @param v2 the second vector
   /// @return the sum
   friend Vector3 operator+( Vector3 const& v1, Vector3 const& v2 );

   /// @brief preforms componentwise subtraction of two vector3s
   /// @param v1 the first vector
   /// @param v2 the second vector
   /// @return the sum
   friend Vector3 operator-( Vector3 const& v1, Vector3 const& v2 );

   /// @brief scales the vector by a constant
   /// @param v1 the vector
   /// @param s the scaling factor
   /// @return the vector scaled by the scaling factor
   friend Vector3 operator*( Vector3 const& v1, float const& s );

   /// @brief performs a component wise check to see if two vector3s are equal
   /// @param v1 the first vector
   /// @param v2 the second vector
   /// @return true if x, y, and z match for both vectors, false otherwise
   friend bool operator==( Vector3 const& v1, Vector3 const& v2 );

private:

   float _x;
   float _y;
   float _z;

};

} //PotionParts

#endif //VECTOR3_HPP