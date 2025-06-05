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