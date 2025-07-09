#include "Torus.hpp"
#include <cmath>
#include <limits>

namespace RayTracer {

  Torus::Torus(const Math::Point3D& center, double radius, double tube_radius,
               const Math::Vector3D& color)
      : center_(center),
        radius_(radius),
        tube_radius_(tube_radius),
        color_(color) {}

  bool Torus::hits(const Ray& ray, double& t) const {
    const int maxSteps = 100;
    const double maxDistance = 100.0;
    const double surfaceThreshold = 0.001;

    t = 0.0;
    for (int i = 0; i < maxSteps; ++i) {
      Math::Point3D pos = ray.origin + ray.direction * t;
      Math::Vector3D p = pos - center_;
      double qx = std::sqrt(p.x * p.x + p.z * p.z) - radius_;
      double sdf = std::sqrt(qx * qx + p.y * p.y) - tube_radius_;

      if (sdf < surfaceThreshold) {
        return true;
      }

      t += sdf;
      if (t >= maxDistance)
        break;
    }
    return false;
  }

  Math::Vector3D Torus::getNormal(const Math::Point3D& point) const {
    const double epsilon = 0.001;
    const Math::Vector3D dx(epsilon, 0, 0);
    const Math::Vector3D dy(0, epsilon, 0);
    const Math::Vector3D dz(0, 0, epsilon);

    auto dist = [&](const Math::Point3D& p) {
      Math::Vector3D rel = p - center_;
      double qx = std::sqrt(rel.x * rel.x + rel.z * rel.z) - radius_;
      return std::sqrt(qx * qx + rel.y * rel.y) - tube_radius_;
    };

    double nx = dist(point + dx) - dist(point - dx);
    double ny = dist(point + dy) - dist(point - dy);
    double nz = dist(point + dz) - dist(point - dz);

    return Math::Vector3D(nx, ny, nz).normalized();
  }

  Math::Vector3D Torus::getColor() const {
    return color_;
  }

  Math::Vector3D Torus::getColor(const Math::Point3D& point) const {
    (void) point;
    return color_;
  }

  void Torus::setPosition(const Math::Point3D& position) {
    center_ = position;
  }

  void Torus::setColor(const Math::Vector3D& color) {
    color_ = color;
  }

  void Torus::setTexture(std::shared_ptr<ITexture> texture) {
    (void) texture;
  }
}  // namespace RayTracer
