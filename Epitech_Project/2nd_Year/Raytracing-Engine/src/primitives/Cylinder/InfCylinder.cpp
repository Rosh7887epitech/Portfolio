/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-raytracer-evann.bloutin
** File description:
** InfCylinder
*/

#include "InfCylinder.hpp"
#include <cmath>

namespace RayTracer {

  InfiniteCylinder::InfiniteCylinder(const Math::Point3D& base, double radius,
                                     const Math::Vector3D& color)
      : base_(base), radius_(radius), color_(color) {}

  bool InfiniteCylinder::hits(const Ray& ray, double& t) const {
    Math::Vector3D oc = ray.origin - base_;
    double a =
        ray.direction.x * ray.direction.x + ray.direction.z * ray.direction.z;
    double b = 2.0 * (oc.x * ray.direction.x + oc.z * ray.direction.z);
    double c = oc.x * oc.x + oc.z * oc.z - radius_ * radius_;

    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
      return false;
    }

    double sqrt_disc = std::sqrt(discriminant);
    double t0 = (-b - sqrt_disc) / (2.0 * a);
    double t1 = (-b + sqrt_disc) / (2.0 * a);

    if (t0 > t1)
      std::swap(t0, t1);

    if (t0 > 1e-4) {
      t = t0;
      return true;
    }

    if (t1 > 1e-4) {
      t = t1;
      return true;
    }

    return false;
  }

  Math::Vector3D InfiniteCylinder::getNormal(const Math::Point3D& point) const {
    Math::Vector3D radial = point - base_;
    radial.y = 0;  // On ignore la composante Y pour que le cylindre soit infini
    return radial.normalized();
  }

  Math::Vector3D InfiniteCylinder::getColor() const {
    return color_;
  }

  void InfiniteCylinder::setPosition(const Math::Point3D& position) {
    base_ = position;
  }

  void InfiniteCylinder::setColor(const Math::Vector3D& color) {
    color_ = color;
  }

  void InfiniteCylinder::setTexture(std::shared_ptr<ITexture> texture) {
    (void) texture;
  }

}  // namespace RayTracer
