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

Vector3 operator+( Vector3 const& v1, Vector3 const& v2 ) {
    return Vector3( v1.x() + v2.x(), v1.y() + v2.y(), v1.z() + v2.z() );
}

Vector3 operator-( Vector3 const& v1, Vector3 const& v2 ) {
    return Vector3( v1.x() - v2.x(), v1.y() - v2.y(), v1.z() - v2.z() );
}

Vector3 operator*( Vector3 const& v1, float const& s ) {
    return Vector3( v1.x() * s, v1.y() * s, v1.z() * s );
}

bool operator==( Vector3 const& v1, Vector3 const& v2 ) {
    return v1.x() == v2.x() && v1.y() == v2.y() && v1.z() == v2.z();
}