/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-bsraytracer-robin.schuffenecker
** File description:
** Point3D
*/

#pragma once

#include "Vector3D.hpp"

namespace Math {
  /**
   * @brief Represents a point in 3D space.
   */
  class Point3D {
  public:
    /**
     * @brief Default constructor.
     */
    Point3D();

    /**
     * @brief Constructs a point with given coordinates.
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     * @param z The z-coordinate.
     */
    Point3D(double x, double y, double z);

    /**
     * @brief Default destructor.
     */
    ~Point3D() = default;

    /**
     * @brief The x-coordinate of the point.
     */
    double x;

    /**
     * @brief The y-coordinate of the point.
     */
    double y;

    /**
     * @brief The z-coordinate of the point.
     */
    double z;

    /**
     * @brief Adds a vector to the point.
     * @param vec The vector to add.
     * @return A new point resulting from the addition.
     */
    Point3D operator+(const Vector3D& vec) const;

    /**
     * @brief Adds a vector to the point in place.
     * @param vec The vector to add.
     * @return A reference to the modified point.
     */
    Point3D& operator+=(const Vector3D& vec);

    /**
     * @brief Subtracts another point from this point.
     * @param point The point to subtract.
     * @return A vector representing the difference.
     */
    Vector3D operator-(const Point3D& point) const;

    /**
     * @brief Subtracts a vector from the point.
     * @param vec The vector to subtract.
     * @return A new point resulting from the subtraction.
     */
    Point3D operator-(const Vector3D& vec) const;
    /**
     * @brief Subtracts another point from this point.
     * @param other The point to subtract.
     * @return A new point resulting from the subtraction.
     */
    Point3D subtract(const Point3D& other) const;
  };
}  // namespace Math
