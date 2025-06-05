#include<Utils.hpp>

namespace PotionParts {

class Vector3 {
public:

   /// @breif constructs a Vector3 with zero for all aspects
   Vector3() : Vector3( 0, 0, 0 ) {}

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