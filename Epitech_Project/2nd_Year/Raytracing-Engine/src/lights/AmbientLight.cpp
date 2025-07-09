/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-raytracer-evann.bloutin
** File description:
** AmbientLight
*/

#include "AmbientLight.hpp"

namespace RayTracer {

  AmbientLight::AmbientLight(const Math::Vector3D& color, double intensity)
      : color_(color), intensity_(intensity) {}

  Math::Vector3D AmbientLight::getDirectionTo(const Math::Point3D&) const {
    return Math::Vector3D(0, 0, 0);
  }

  double AmbientLight::getDistanceTo(const Math::Point3D&) const {
    return 0.0;
  }

  ILight::Type AmbientLight::getType() const {
    return Type::AMBIENT;
  }

  const Math::Vector3D& AmbientLight::getColor() const {
    return color_;
  }

  double AmbientLight::getIntensity() const {
    return intensity_;
  }

  void AmbientLight::setColor(const Math::Vector3D& color) {
    color_ = color;
  }

  void AmbientLight::setPosition(const Math::Point3D& position) {
    (void) position;
  }
}  // namespace RayTracer
