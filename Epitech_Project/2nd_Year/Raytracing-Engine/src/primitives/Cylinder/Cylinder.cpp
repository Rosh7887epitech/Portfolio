/*
** EPITECH PROJECT, 2025
** project
** File description:
** Cylinder
*/

#include "Cylinder.hpp"

#include <cmath>
#include <string>

namespace RayTracer {
  Cylinder::Cylinder(const Math::Point3D& base, double radius, double height,
                     std::shared_ptr<ITexture> texture, float alpha,
                     float refractiveIndex)
      : base_(base),
        radius_(radius),
        height_(height),
        color_(Math::Vector3D(1.0, 1.0, 1.0)),
        alpha_(alpha),
        refractiveIndex_(refractiveIndex),
        texture_(texture) {}

  bool Cylinder::hits(const Ray& ray, double& t) const {
    Math::Vector3D oc = ray.origin - base_;
    double a =
        ray.direction.x * ray.direction.x + ray.direction.z * ray.direction.z;
    double b = 2.0 * (oc.x * ray.direction.x + oc.z * ray.direction.z);
    double c = oc.x * oc.x + oc.z * oc.z - radius_ * radius_;
    double discriminant = b * b - 4 * a * c;
    double t_side = -1;
    if (discriminant >= 0) {
      double sqrt_disc = std::sqrt(discriminant);
      double t0 = (-b - sqrt_disc) / (2.0 * a);
      double t1 = (-b + sqrt_disc) / (2.0 * a);
      if (t0 > t1) {
        std::swap(t0, t1);
      }
      double y0 = ray.origin.y + t0 * ray.direction.y;
      if (t0 >= 0 && y0 >= base_.y && y0 <= base_.y + height_) {
        t_side = t0;
      } else {
        double y1 = ray.origin.y + t1 * ray.direction.y;
        if (t1 >= 0 && y1 >= base_.y && y1 <= base_.y + height_) {
          t_side = t1;
        }
      }
    }
    double t_cap = -1;
    if (std::abs(ray.direction.y) > 1e-6) {
      double t0 = (base_.y - ray.origin.y) / ray.direction.y;
      double x0 = ray.origin.x + t0 * ray.direction.x;
      double z0 = ray.origin.z + t0 * ray.direction.z;
      double dx0 = x0 - base_.x;
      double dz0 = z0 - base_.z;
      if (t0 >= 0 && dx0 * dx0 + dz0 * dz0 <= radius_ * radius_) {
        t_cap = t0;
      }
      double t1 = (base_.y + height_ - ray.origin.y) / ray.direction.y;
      double x1 = ray.origin.x + t1 * ray.direction.x;
      double z1 = ray.origin.z + t1 * ray.direction.z;
      double dx1 = x1 - base_.x;
      double dz1 = z1 - base_.z;
      if (t1 >= 0 && dx1 * dx1 + dz1 * dz1 <= radius_ * radius_) {
        if (t_cap < 0 || t1 < t_cap) {
          t_cap = t1;
        }
      }
    }
    if (t_side >= 0 && (t_cap < 0 || t_side < t_cap)) {
      t = t_side;
      return true;
    }
    if (t_cap >= 0) {
      t = t_cap;
      return true;
    }
    return false;
  }

  Math::Vector3D Cylinder::getNormal(const Math::Point3D& point) const {
    Math::Vector3D axis = Math::Vector3D(0, 1, 0);
    Math::Point3D top = base_ + axis * height_;
    double epsilon = 1e-6;

    if (std::abs((point - base_).dot(axis)) < epsilon) {
      return -axis;
    }
    if (std::abs((point - top).dot(axis)) < epsilon) {
      return axis;
    }
    Math::Vector3D radial = point - base_;
    radial = radial - axis * (radial.dot(axis));
    return radial.normalized();
  }

  Math::Vector3D Cylinder::getColor() const {
    return color_;
  }

  Math::Vector3D Cylinder::getColor(const Math::Point3D& point) const {
    (void) point;
    return color_;
  }

  void Cylinder::setPosition(const Math::Point3D& position) {
    base_ = position;
  }

  void Cylinder::setColor(const Math::Vector3D& color) {
    color_ = color;
  }

  void Cylinder::setAlpha(float a) {
    alpha_ = a;
  }

  void Cylinder::setRefractiveIndex(float ri) {
    refractiveIndex_ = ri;
  }

  float Cylinder::getAlpha() const {
    return alpha_;
  }

  float Cylinder::getRefractiveIndex() const {
    return refractiveIndex_;
  }

  void Cylinder::setTexture(std::shared_ptr<ITexture> texture) {
    (void) texture;
  }
}  // namespace RayTracer
