/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-raytracer-evann.bloutin
** File description:
** Plane
*/

#include "Plane.hpp"
#include "ITexture.hpp"

#include <cmath>

namespace RayTracer {
  bool Plane::hits(const Ray& ray, double& t) const {
    double denom = normal_.dot(ray.direction);
    if (std::abs(denom) > 1e-6) {
      Math::Vector3D p0l0 = position_ - ray.origin;
      t = normal_.dot(p0l0) / denom;
      return t >= 1e-4;
    }
    return false;
  }

  Math::Vector3D Plane::getColor() const {
    return color_;
  }

  Math::Vector3D Plane::getNormal(const Math::Point3D&) const {
    return normal_;
  }

  Math::Vector3D Plane::getColor(const Math::Point3D& point) const {
    if (texture_) {
      Math::Vector3D localPoint = point - position_;
      Color texColor = texture_->getColor(localPoint);
      return Math::Vector3D(texColor.r, texColor.g, texColor.b);
    }
    return color_;
  }

  void Plane::setPosition(const Math::Point3D& position) {
    position_ = position;
  }

  void Plane::setColor(const Math::Vector3D& color) {
    color_ = color;
  }

  void Plane::setTexture(std::shared_ptr<ITexture> texture) {
    texture_ = texture;
  }

}  // namespace RayTracer
