/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-raytracer-evann.bloutin
** File description:
** Cube
*/

#include "Cube.hpp"
#include <algorithm>

namespace RayTracer {

  Cube::Cube(const Math::Point3D& center, double size,
             const Math::Vector3D& color)
      : center_(center), size_(size), color_(color) {}

  bool Cube::hits(const Ray& ray, double& t) const {
    double tMin = -std::numeric_limits<double>::max();
    double tMax = std::numeric_limits<double>::max();

    for (int i = 0; i < 3; ++i) {
      double invDir;
      double t0, t1;

      if (i == 0) {
        invDir = 1.0 / ray.direction.x;
        t0 = (center_.x - size_ / 2 - ray.origin.x) * invDir;
        t1 = (center_.x + size_ / 2 - ray.origin.x) * invDir;
      } else if (i == 1) {
        invDir = 1.0 / ray.direction.y;
        t0 = (center_.y - size_ / 2 - ray.origin.y) * invDir;
        t1 = (center_.y + size_ / 2 - ray.origin.y) * invDir;
      } else {
        invDir = 1.0 / ray.direction.z;
        t0 = (center_.z - size_ / 2 - ray.origin.z) * invDir;
        t1 = (center_.z + size_ / 2 - ray.origin.z) * invDir;
      }

      if (t0 > t1)
        std::swap(t0, t1);

      tMin = std::max(tMin, t0);
      tMax = std::min(tMax, t1);

      if (tMin > tMax)
        return false;
    }
    t = tMin;
    return true;
  }

  Math::Vector3D Cube::getNormal(const Math::Point3D& point) const {
    Math::Vector3D p = point - center_;
    Math::Vector3D normal(0.0, 0.0, 0.0);
    double maxDist = -std::numeric_limits<double>::max();
    double distX = std::abs(p.x) - size_ / 2;
    double distY = std::abs(p.y) - size_ / 2;
    double distZ = std::abs(p.z) - size_ / 2;

    if (distX > maxDist) {
      maxDist = distX;
      normal = Math::Vector3D((p.x > 0) ? 1.0 : -1.0, 0.0, 0.0);
    }
    if (distY > maxDist) {
      maxDist = distY;
      normal = Math::Vector3D(0.0, (p.y > 0) ? 1.0 : -1.0, 0.0);
    }
    if (distZ > maxDist) {
      maxDist = distZ;
      normal = Math::Vector3D(0.0, 0.0, (p.z > 0) ? 1.0 : -1.0);
    }
    return normal;
  }

  Math::Vector3D Cube::getColor() const {
    return color_;
  }

  void Cube::setPosition(const Math::Point3D& position) {
    center_ = position;
  }

  void Cube::setColor(const Math::Vector3D& color) {
    color_ = color;
  }

  void Cube::setTexture(std::shared_ptr<ITexture> texture) {
    (void) texture;
  }

}  // namespace RayTracer
