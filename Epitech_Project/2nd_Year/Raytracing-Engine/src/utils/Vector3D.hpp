/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-bsraytracer-robin.schuffenecker
** File description:
** Main
*/

#pragma once

#include <array>
#include <cmath>

namespace Math {
  /**
   * @brief Represents a 3D vector with various mathematical operations.
   */
  class Vector3D {
  public:
    /**
     * @brief Default constructor. Initializes the vector to (0, 0, 0).
     */
    Vector3D();

    /**
     * @brief Constructs a vector with given coordinates.
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     * @param z The z-coordinate.
     */
    Vector3D(double x, double y, double z);

    /**
     * @brief Default destructor.
     */
    ~Vector3D() = default;

    double x;  ///< The x-coordinate of the vector.
    double y;  ///< The y-coordinate of the vector.
    double z;  ///< The z-coordinate of the vector.

    /**
     * @brief Computes the length (magnitude) of the vector.
     * @return The length of the vector.
     */
    double length() const;

    Vector3D operator+(const Vector3D& other) const;
    Vector3D operator-(const Vector3D& other) const;
    Vector3D operator*(const Vector3D& other) const;
    Vector3D operator/(const Vector3D& other) const;
    Vector3D operator+=(const Vector3D& other);
    Vector3D operator-=(const Vector3D& other);
    Vector3D operator*=(const Vector3D& other);
    Vector3D operator/=(const Vector3D& other);

    Vector3D operator*(double scalar) const;
    Vector3D operator/(double scalar) const;
    Vector3D operator*=(double scalar);
    Vector3D operator/=(double scalar);

    Vector3D operator-() const;

    /**
     * @brief Computes the dot product of this vector with another.
     * @param other The other vector.
     * @return The dot product.
     */
    double dot(const Vector3D& other) const;

    /**
     * @brief Computes the cross product of this vector with another.
     * @param other The other vector.
     * @return The resulting vector from the cross product.
     */
    Vector3D cross(const Vector3D& other) const;

    /**
     * @brief Normalizes the vector to have a length of 1.
     * @return The normalized vector.
     */
    Vector3D normalized() const;
  };

  /**
   * @brief Multiplies a scalar with a vector.
   * @param scalar The scalar value.
   * @param vec The vector.
   * @return The resulting vector.
   */
  Vector3D operator*(double scalar, const Vector3D& vec);

  template <std::size_t N>
  class Vector {
  public:
    Vector() : components{} {}
    explicit Vector(const std::array<double, N>& components)
        : components(components) {}
    ~Vector() = default;

  private:
    std::array<double, N> components;
  };
}  // namespace Math
