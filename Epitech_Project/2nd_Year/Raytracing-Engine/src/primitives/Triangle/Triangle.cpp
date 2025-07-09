/*
** EPITECH PROJECT, 2025
** project
** File description:
** Triangle
*/

#include "Triangle.hpp"
#include <iostream>

namespace RayTracer {

  Triangle::Triangle(const Math::Point3D& vertex1, const Math::Point3D& vertex2,
                     const Math::Point3D& vertex3, const Math::Vector3D& color)
      : v1_(vertex1), v2_(vertex2), v3_(vertex3), color_(color) {}

  bool Triangle::hits(const Ray& ray, double& t) const {
    const double EPSILON = 1e-6;
    Math::Vector3D edge1 = v2_ - v1_;
    Math::Vector3D edge2 = v3_ - v1_;
    Math::Vector3D h = ray.direction.cross(edge2);
    double a = edge1.dot(h);

    if (std::abs(a) < EPSILON)
      return false;
    double f = 1.0 / a;
    Math::Vector3D s = ray.origin - v1_;
    double u = f * s.dot(h);
    if (u < 0.0 || u > 1.0)
      return false;
    Math::Vector3D q = s.cross(edge1);
    double v = f * ray.direction.dot(q);
    if (v < 0.0 || u + v > 1.0)
      return false;
    double tempT = f * edge2.dot(q);
    if (tempT > EPSILON) {
      t = tempT;
      return true;
    }
    return false;
  }

  Math::Vector3D Triangle::getNormal(const Math::Point3D& point) const {
    (void) point;
    Math::Vector3D edge1 = v2_ - v1_;
    Math::Vector3D edge2 = v3_ - v1_;
    return edge1.cross(edge2).normalized();
  }

  Math::Vector3D Triangle::getColor() const {
    return color_;
  }

  Math::Vector3D Triangle::getColor(const Math::Point3D& point) const {
    (void) point;
    return color_;
  }

  void Triangle::setPosition(const Math::Point3D& position) {
    v1_ = position;
  }

  void Triangle::setColor(const Math::Vector3D& color) {
    color_ = color;
  }

  void Triangle::setTexture(std::shared_ptr<ITexture> texture) {
    (void) texture;
  }
}  // namespace RayTracer
