#include "Vector3.hpp"
#include <cmath>

using namespace PotionParts;

Vector3::Vector3( float x, float y, float z ) {
    set( x, y, z );
}

void Vector3::set( float x, float y, float z ) {
    xIs( x );
    yIs( y );
    zIs( z );
}

void Vector3::xIs( float x ){
    _x = x;
}

void Vector3::yIs( float y ){
    _y = y;
}

void Vector3::zIs( float z ){
    _z = z;
}

float Vector3::x() const {
    return _x;
}

float Vector3::y() const {
    return _y;
}

float Vector3::z() const {
    return _z;
}

Engine::Vec3f Vector3::toVec() const {
   return { _x, _y, _z };
}

float Vector3::mag() const {
    return (float) sqrt( 
        ( ( (double) _x ) * ( (double) _x ) ) +
        ( ( (double) _y ) * ( (double) _y ) ) + 
        ( ( (double) _z ) * ( (double) _z ) ) );
}

void Vector3::normalize(){
    float magnitude = mag();

    _x = _x / magnitude;
    _y = _y / magnitude;
    _z = _z / magnitude;
}

Engine::Graphics::Vertex Vector3::toVertex(float u, float v) const {
   Engine::Graphics::Vertex vert;

   vert.x = _x;
   vert.y = _y;
   vert.z = _z;
   vert.u = u;
   vert.v = v;

   return vert;
}

bool PotionParts::equalError( Vector3 v1, Vector3 v2, float err ){
    float dist = (v1 - v2).mag();

    return ( dist < err );
}

Vector3 PotionParts::operator+( Vector3 const& v1, Vector3 const& v2 ) {
    return Vector3( v1._x + v2._x, v1._y + v2._y, v1._z + v2._z );
}

Vector3 PotionParts::operator-( Vector3 const& v1, Vector3 const& v2 ) {
    return Vector3( v1._x - v2._x, v1._y - v2._y, v1._z - v2._z );
}

Vector3 PotionParts::operator*( Vector3 const& v1, float const& s ) {
    return Vector3( v1._x * s, v1._y * s, v1._z * s );
}

bool PotionParts::operator==( Vector3 const& v1, Vector3 const& v2 ) {
    return v1._x == v2._x && v1._y == v2._y && v1._z == v2._z;
}

Vector3 PotionParts::cross( Vector3 const& a, Vector3 const& b ){
    return Vector3(
        ( a._y * b._z ) - ( a._z*b._y ),
        ( a._x * b._z ) - ( a._z*b._x ),
        ( a._x * b._y ) - ( a._y*b._x )
    );
}

std::ostream& PotionParts::operator<< ( std::ostream& stream, Vector3 const& v ) {
    stream << "(" << v.x() << ", " << v.y() << ", " << v.z() << ")";
    return stream;
}