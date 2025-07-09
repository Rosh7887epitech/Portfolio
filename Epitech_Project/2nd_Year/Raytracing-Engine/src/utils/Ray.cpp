/*
** EPITECH PROJECT, 2025
** project
** File description:
** Ray
*/

#include "Ray.hpp"

namespace RayTracer {
  Ray::Ray(const Math::Point3D& origin, const Math::Vector3D& direction)
      : origin(origin), direction(direction) {}

  Math::Point3D Ray::getOrigin() const {
    return origin;
  }

  Math::Vector3D Ray::getDirection() const {
    return direction;
  }
}  // namespace RayTracer
