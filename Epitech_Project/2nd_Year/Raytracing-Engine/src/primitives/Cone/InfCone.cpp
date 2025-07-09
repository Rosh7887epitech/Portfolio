#include "InfCone.hpp"
#include <cmath>

namespace RayTracer {

  InfiniteCone::InfiniteCone(const Math::Point3D& apex, double angle,
                             const Math::Vector3D& color)
      : apex_(apex), angle_(angle), color_(color) {}

  bool InfiniteCone::hits(const Ray& ray, double& t) const {
    Math::Vector3D oc = ray.origin - apex_;
    double cos2 = std::cos(angle_) * std::cos(angle_);
    double sin2 = std::sin(angle_) * std::sin(angle_);
    double a = ray.direction.x * ray.direction.x -
               cos2 * ray.direction.y * ray.direction.y +
               ray.direction.z * ray.direction.z;
    double b = 2.0 * (oc.x * ray.direction.x - cos2 * oc.y * ray.direction.y +
                      oc.z * ray.direction.z);
    double c = oc.x * oc.x - cos2 * oc.y * oc.y + oc.z * oc.z;
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

  Math::Vector3D InfiniteCone::getNormal(const Math::Point3D& point) const {
    Math::Vector3D pa = point - apex_;
    double cos2 = std::cos(angle_) * std::cos(angle_);

    Math::Vector3D normal(pa.x, -cos2 * pa.y, pa.z);
    return normal.normalized();
  }

  Math::Vector3D InfiniteCone::getColor() const {
    return color_;
  }

  void InfiniteCone::setPosition(const Math::Point3D& position) {
    apex_ = position;
  }

  void InfiniteCone::setColor(const Math::Vector3D& color) {
    color_ = color;
  }

  void InfiniteCone::setTexture(std::shared_ptr<ITexture> texture) {
    (void) texture;
  }

}  // namespace RayTracer
