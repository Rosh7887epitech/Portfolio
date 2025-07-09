/*
 ** EPITECH PROJECT, 2025
 ** project
 ** File description:
 ** Sphere
 */

#include "Sphere.hpp"

namespace RayTracer {
  Sphere::Sphere(const Math::Point3D& center, double radius,
                 const Math::Vector3D& color, float alpha,
                 float refractiveIndex)
      : center_(center),
        radius_(radius),
        color_(color),
        alpha_(alpha),
        refractiveIndex_(refractiveIndex) {
    Color textureColor(color.x, color.y, color.z);
    texture_ = std::make_shared<SolidColorTexture>(textureColor);
  }

  Sphere::Sphere(const Math::Point3D& center, double radius,
                 std::shared_ptr<ITexture> texture, float alpha,
                 float refractiveIndex)
      : center_(center),
        radius_(radius),
        color_(Math::Vector3D(1.0, 1.0, 1.0)),
        alpha_(alpha),
        refractiveIndex_(refractiveIndex),
        texture_(texture) {}

  bool Sphere::hits(const Ray& ray, double& t) const {
    Math::Vector3D oc = ray.origin - center_;
    double a = ray.direction.dot(ray.direction);
    double b = 2.0 * oc.dot(ray.direction);
    double c = oc.dot(oc) - radius_ * radius_;
    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
      return false;
    } else {
      t = (-b - std::sqrt(discriminant)) / (2.0 * a);
      if (t < 0)
        t = (-b + std::sqrt(discriminant)) / (2.0 * a);
      return t >= 0;
    }
  }

  Math::Vector3D Sphere::getNormal(const Math::Point3D& point) const {
    return (point - center_).normalized();
  }

  Math::Vector3D Sphere::getColor() const {
    if (texture_) {
      Math::Vector3D origin(0, 0, 0);
      Color texColor = texture_->getColor(origin);
      return Math::Vector3D(texColor.r, texColor.g, texColor.b);
    }
    return color_;
  }

  Math::Vector3D Sphere::getColor(const Math::Point3D& point) const {
    if (texture_) {
      // Spherical UV mapping
      Math::Vector3D p = (point - center_).normalized();
      double u = 0.5 + (std::atan2(p.z, p.x) / (2 * M_PI));
      double v = 0.5 - (std::asin(p.y) / M_PI);
      Color texColor = texture_->getColor(Math::Vector3D(u, v, 0));
      return Math::Vector3D(texColor.r, texColor.g, texColor.b);
    }
    return color_;
  }

  void Sphere::setPosition(const Math::Point3D& position) {
    center_ = position;
  }

  void Sphere::setColor(const Math::Vector3D& color) {
    color_ = color;
  }

  void Sphere::setTexture(std::shared_ptr<ITexture> texture) {
    texture_ = texture;
  }

}  // namespace RayTracer
