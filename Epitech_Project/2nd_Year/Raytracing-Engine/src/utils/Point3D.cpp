/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-bsraytracer-robin.schuffenecker
** File description:
** Point3D
*/

#include "Point3D.hpp"

namespace Math {

  Point3D::Point3D() : x(0), y(0), z(0) {}

  Point3D::Point3D(double x, double y, double z) : x(x), y(y), z(z) {}

  Point3D Point3D::operator+(const Vector3D& vec) const {
    return Point3D(x + vec.x, y + vec.y, z + vec.z);
  }

  Point3D& Point3D::operator+=(const Vector3D& vec) {
    this->x += vec.x;
    this->y += vec.y;
    this->z += vec.z;
    return *this;
  }

  Vector3D Point3D::operator-(const Point3D& vec) const {
    return Vector3D(x - vec.x, y - vec.y, z - vec.z);
  }

  Point3D Point3D::operator-(const Vector3D& vec) const {
    return Point3D(x - vec.x, y - vec.y, z - vec.z);
  }

  Point3D Point3D::subtract(const Point3D& other) const {
    return Point3D(this->x - other.x, this->y - other.y, this->z - other.z);
  }
}  // namespace Math
