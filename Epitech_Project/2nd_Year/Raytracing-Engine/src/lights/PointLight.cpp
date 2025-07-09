/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-raytracer-evann.bloutin
** File description:
** Light
*/

#include "PointLight.hpp"

namespace RayTracer {

  PointLight::PointLight(const Math::Point3D& position,
                         const Math::Vector3D& color, double intensity)
      : position_(position), color_(color), intensity_(intensity) {}

  Math::Vector3D PointLight::getDirectionTo(const Math::Point3D& point) const {
    return (position_ - point).normalized();
  }

  double PointLight::getDistanceTo(const Math::Point3D& point) const {
    return (position_ - point).length();
  }

  ILight::Type PointLight::getType() const {
    return Type::POINT;
  }

  const Math::Vector3D& PointLight::getColor() const {
    return color_;
  }

  double PointLight::getIntensity() const {
    return intensity_;
  }

  void PointLight::setPosition(const Math::Point3D& position) {
    position_ = position;
  }

  void PointLight::setColor(const Math::Vector3D& color) {
    color_ = color;
  }
}  // namespace RayTracer
