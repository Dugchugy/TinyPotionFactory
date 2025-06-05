#include "Vector3.hpp"

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

float Vector3::x() {
    return _x;
}

float Vector3::y() {
    return _y;
}

float Vector3::z() {
    return _z;
}

Engine::Vec3f Vector3::toVec() {
    return { _x, _y, _z };
}

Vector3 operator+( Vector3 const& v1, Vector3 const& v2 ) {
    return Vector3( v1._x + v2._x, v1._y + v2._y, v1._z + v2._z );
}

Vector3 operator-( Vector3 const& v1, Vector3 const& v2 ) {
    return Vector3( v1._x - v2._x, v1._y - v2._y, v1._z - v2._z );
}

Vector3 operator*( Vector3 const& v1, float const& s ) {
    return Vector3( v1._x * s, v1._y * s, v1._z * s );
}

bool operator==( Vector3 const& v1, Vector3 const& v2 ) {
    return v1._x == v2._x && v1._y == v2._y && v1._z == v2._z;
}