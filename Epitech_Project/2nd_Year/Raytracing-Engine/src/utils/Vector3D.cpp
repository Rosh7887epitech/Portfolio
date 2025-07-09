/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-bsraytracer-robin.schuffenecker
** File description:
** Vector3D
*/

#include "Vector3D.hpp"

namespace Math {

  Vector3D::Vector3D() : x(0), y(0), z(0) {}

  Vector3D::Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

  double Vector3D::length() const {
    return sqrt(x * x + y * y + z * z);
  }

  Vector3D Vector3D::operator+(const Vector3D& other) const {
    return Vector3D(x + other.x, y + other.y, z + other.z);
  }

  Vector3D Vector3D::operator-(const Vector3D& other) const {
    return Vector3D(x - other.x, y - other.y, z - other.z);
  }

  Vector3D Vector3D::operator*(const Vector3D& other) const {
    return Vector3D(x * other.x, y * other.y, z * other.z);
  }

  Vector3D Vector3D::operator/(const Vector3D& other) const {
    return Vector3D(x / other.x, y / other.y, z / other.z);
  }

  Vector3D Vector3D::operator+=(const Vector3D& other) {
    this->x += other.x;
    this->y += other.y;
    this->z += other.z;
    return *this;
  }

  Vector3D Vector3D::operator-=(const Vector3D& other) {
    this->x -= other.x;
    this->y -= other.y;
    this->z -= other.z;
    return *this;
  }

  Vector3D Vector3D::operator*=(const Vector3D& other) {
    this->x *= other.x;
    this->y *= other.y;
    this->z *= other.z;
    return *this;
  }

  Vector3D Vector3D::operator/=(const Vector3D& other) {
    this->x /= other.x;
    this->y /= other.y;
    this->z /= other.z;
    return *this;
  }

  Vector3D Vector3D::operator*(double scalar) const {
    return Vector3D(x * scalar, y * scalar, z * scalar);
  }

  Vector3D Vector3D::operator/(double scalar) const {
    return Vector3D(x / scalar, y / scalar, z / scalar);
  }

  Vector3D Vector3D::operator*=(double scalar) {
    this->x *= scalar;
    this->y *= scalar;
    this->z *= scalar;
    return *this;
  }

  Vector3D Vector3D::operator/=(double scalar) {
    this->x /= scalar;
    this->y /= scalar;
    this->z /= scalar;
    return *this;
  }

  Vector3D Vector3D::operator-() const {
    return Vector3D(-x, -y, -z);
  }

  double Vector3D::dot(const Vector3D& other) const {
    return x * other.x + y * other.y + z * other.z;
  }

  Vector3D Vector3D::cross(const Vector3D& other) const {
    return Vector3D(y * other.z - z * other.y, z * other.x - x * other.z,
                    x * other.y - y * other.x);
  }

  Vector3D Vector3D::normalized() const {
    double len = length();
    if (len == 0)
      return *this;
    return *this / len;
  }

  Vector3D operator*(double scalar, const Vector3D& vec) {
    return Vector3D(vec.x * scalar, vec.y * scalar, vec.z * scalar);
  }

}  // namespace Math
