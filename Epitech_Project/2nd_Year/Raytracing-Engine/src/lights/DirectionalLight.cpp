/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-raytracer-evann.bloutin
** File description:
** DirectionalLight
*/

#include "DirectionalLight.hpp"

namespace RayTracer {

  DirectionalLight::DirectionalLight(const Math::Vector3D& direction,
                                     const Math::Vector3D& color,
                                     double intensity)
      : direction_(direction.normalized()),
        color_(color),
        intensity_(intensity) {}

  Math::Vector3D DirectionalLight::getDirectionTo(const Math::Point3D&) const {
    return Math::Vector3D(direction_.x, direction_.y, direction_.z);
  }

  double DirectionalLight::getDistanceTo(const Math::Point3D&) const {
    return std::numeric_limits<double>::infinity();
  }

  ILight::Type DirectionalLight::getType() const {
    return Type::DIRECTIONAL;
  }

  const Math::Vector3D& DirectionalLight::getColor() const {
    return color_;
  }

  double DirectionalLight::getIntensity() const {
    return intensity_;
  }

  void DirectionalLight::setColor(const Math::Vector3D& color) {
    color_ = color;
  }

  void DirectionalLight::setPosition(const Math::Point3D& direction) {
    Math::Vector3D new_direction;
    new_direction.x = direction.x;
    new_direction.y = direction.y;
    new_direction.z = direction.z;
    direction_ = new_direction.normalized();
  }
}  // namespace RayTracer
