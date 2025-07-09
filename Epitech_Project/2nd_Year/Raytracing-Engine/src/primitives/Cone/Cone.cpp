/*
** EPITECH PROJECT, 2025
** project
** File description:
** Cone
*/

#include "Cone.hpp"

#include <cmath>
#include <iostream>
#include <string>

namespace RayTracer {
  Cone::Cone(const Math::Point3D& base, double radius, double height,
             const Math::Vector3D& axis, std::shared_ptr<ITexture> texture,
             float alpha, float refractiveIndex)
      : base_(base),
        radius_(radius),
        height_(height),
        axis_(axis.normalized()),
        color_(Math::Vector3D(1.0, 1.0, 1.0)),
        alpha_(alpha),
        refractiveIndex_(refractiveIndex),
        texture_(texture) {}

  bool Cone::hits(const Ray& ray, double& t) const {
    Math::Point3D apex = base_ + axis_ * height_;
    Math::Vector3D d = ray.direction;
    Math::Vector3D o = ray.origin - apex;
    double k = radius_ / height_;
    double k2 = k * k;
    Math::Vector3D va = axis_;
    double dv = d.dot(va);
    double ov = o.dot(va);
    Math::Vector3D d_ortho = d - va * dv;
    Math::Vector3D o_ortho = o - va * ov;
    double a = d_ortho.dot(d_ortho) - k2 * dv * dv;
    double b = 2 * (d_ortho.dot(o_ortho) - k2 * dv * ov);
    double c = o_ortho.dot(o_ortho) - k2 * ov * ov;
    double disc = b * b - 4 * a * c;
    if (disc < 0) {
      return false;
    }
    double sqrt_disc = std::sqrt(disc);
    double t0 = (-b - sqrt_disc) / (2 * a);
    double t1 = (-b + sqrt_disc) / (2 * a);
    if (t0 > t1)
      std::swap(t0, t1);
    Math::Point3D p0 = ray.origin + ray.direction * t0;
    Math::Vector3D v0 = p0 - base_;
    double h0 = v0.dot(axis_);
    if (t0 > 1e-4 && h0 >= 0 && h0 <= height_) {
      t = t0;
      return true;
    }
    Math::Point3D p1 = ray.origin + ray.direction * t1;
    Math::Vector3D v1 = p1 - base_;
    double h1 = v1.dot(axis_);
    if (t1 > 1e-4 && h1 >= 0 && h1 <= height_) {
      t = t1;
      return true;
    }
    return false;
  }

  Math::Vector3D Cone::getNormal(const Math::Point3D& point) const {
    Math::Point3D apex = base_ + axis_ * height_;
    Math::Vector3D pa = point - apex;
    Math::Vector3D va = axis_;
    Math::Vector3D pa_proj = pa - va * pa.dot(va);
    double slope = radius_ / height_;

    Math::Vector3D normal = pa_proj.normalized() + va * slope;
    return normal.normalized();
  }

  Math::Vector3D Cone::getColor() const {
    return color_;
  }

  Math::Vector3D Cone::getColor(const Math::Point3D& point) const {
    (void) point;
    return color_;
  }

  void Cone::setPosition(const Math::Point3D& position) {
    base_ = position;
  }

  void Cone::setColor(const Math::Vector3D& color) {
    color_ = color;
  }

  void Cone::setTexture(std::shared_ptr<ITexture> texture) {
    (void) texture;
  }

  void Cone::setAlpha(float a) {
    alpha_ = a;
  }

  void Cone::setRefractiveIndex(float ri) {
    refractiveIndex_ = ri;
  }

  float Cone::getAlpha() const {
    return alpha_;
  }

  float Cone::getRefractiveIndex() const {
    return refractiveIndex_;
  }
}  // namespace RayTracer
