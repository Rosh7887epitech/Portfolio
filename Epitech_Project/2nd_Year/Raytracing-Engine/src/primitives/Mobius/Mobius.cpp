/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-raytracer-evann.bloutin
** File description:
** Mobius
*/

#include "Mobius.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>

namespace RayTracer {

  MobiusStrip::MobiusStrip(const Math::Point3D& center, double width,
                           const Math::Vector3D& color)
      : center_(center), width_(width), color_(color) {}

  bool MobiusStrip::hits(const Ray& ray, double& t) const {
    const int maxSteps = 100;
    const double maxDistance = 100.0;
    const double surfaceThreshold = 0.001;
    t = 0.0;
    for (int i = 0; i < maxSteps; ++i) {
      Math::Point3D pos = ray.origin + ray.direction * t;
      Math::Point3D p = pos.subtract(center_);
      double x = p.x;
      double y = p.y;
      double z = p.z;
      double theta = std::atan2(z, x);
      double distToCenter = std::sqrt(x * x + z * z);
      double sdf = std::abs(y - std::sin(theta / 2) * width_) - 0.1;
      sdf += std::abs(distToCenter - 1.0) - width_;
      if (sdf < surfaceThreshold) {
        return true;
      }
      t += sdf;
      if (t >= maxDistance)
        break;
    }
    return false;
  }

  Math::Vector3D MobiusStrip::getNormal(const Math::Point3D& point) const {
    const double epsilon = 0.001;
    const Math::Vector3D dx(epsilon, 0, 0);
    const Math::Vector3D dy(0, epsilon, 0);
    const Math::Vector3D dz(0, 0, epsilon);

    auto dist = [&](const Math::Point3D& p) {
      Math::Point3D rel = p.subtract(center_);
      double x = rel.x;
      double y = rel.y;
      double z = rel.z;
      double theta = std::atan2(z, x);
      double distToCenter = std::sqrt(x * x + z * z);
      double sdf = std::abs(y - std::sin(theta / 2) * width_) - 0.1;
      sdf += std::abs(distToCenter - 1.0) - width_;
      return sdf;
    };
    double nx = dist(point - dx) - dist(point + dx);
    double ny = dist(point - dy) - dist(point + dy);
    double nz = dist(point - dz) - dist(point + dz);
    return Math::Vector3D(nx, ny, nz).normalized();
  }

  Math::Vector3D MobiusStrip::getColor() const {
    return color_;
  }

  void MobiusStrip::setPosition(const Math::Point3D& position) {
    center_ = position;
  }

  void MobiusStrip::setColor(const Math::Vector3D& color) {
    color_ = color;
  }

  void MobiusStrip::setTexture(std::shared_ptr<ITexture> texture) {
    (void) texture;
  }

  void MobiusStrip::setAlpha(float alpha) {
    (void) alpha;
  }

  void MobiusStrip::setRefractiveIndex(float refractiveIndex) {
    (void) refractiveIndex;
  }

  void MobiusStrip::setSize(double size) {
    width_ = size;
  }

}  // namespace RayTracer
