#ifndef CAMERAEXTRAS_HPP
#define CAMERAEXTRAS_HPP

#include "Utils.hpp"
#include "Camera.hpp"

namespace PotionParts {

    Engine::Vec3f GetCameraLocationOnPlane(
        const Engine::Camera& cam,
        const Engine::Vec2f& mouse_position,
        const Engine::Vec3f& perpendicular,
        const Engine::Vec3f& containts
    );

    Engine::Vec3f GetCameraLocationOnPlane(
        const Engine::Camera& cam,
        const Engine::Vec2f& mouse_position
    ) {
        return GetCameraLocationOnPlane( cam, mouse_position, {0, 0, 1}, {0, 0, 0});
    }

};

#endif //CAMERAEXTRAS_HPP