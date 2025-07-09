/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-bsraytracer-robin.schuffenecker
** File description:
** Rectangle3D
*/

#include "Rectangle3D.hpp"

namespace Math {
  Rectangle3D::Rectangle3D(const Point3D& origin, const Vector3D& bottom_side,
                           const Vector3D& left_side)
      : origin(origin), bottom_side(bottom_side), left_side(left_side) {}

  Point3D Rectangle3D::pointAt(double u, double v) const {
    return origin + (bottom_side * u) + (left_side * v);
  }
}  // namespace Math
