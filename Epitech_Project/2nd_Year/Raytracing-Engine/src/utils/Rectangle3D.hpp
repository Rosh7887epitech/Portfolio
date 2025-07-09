/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-bsraytracer-robin.schuffenecker
** File description:
** Rectangle3D
*/

#pragma once
#include "Point3D.hpp"
#include "Vector3D.hpp"

namespace Math {
  /**
   * @brief Represents a 3D rectangle defined by an origin and two side vectors.
   */
  class Rectangle3D {
  public:
    /**
     * @brief Default constructor.
     */
    Rectangle3D() = default;

    /**
     * @brief Constructs a rectangle with an origin and two side vectors.
     * @param origin The origin point of the rectangle.
     * @param bottom_side The vector representing the bottom side of the
     * rectangle.
     * @param left_side The vector representing the left side of the rectangle.
     */
    Rectangle3D(const Point3D& origin, const Vector3D& bottom_side,
                const Vector3D& left_side);

    /**
     * @brief Default destructor.
     */
    ~Rectangle3D() = default;

    /**
     * @brief The origin point of the rectangle.
     */
    Point3D origin;

    /**
     * @brief The vector representing the bottom side of the rectangle.
     */
    Vector3D bottom_side;

    /**
     * @brief The vector representing the left side of the rectangle.
     */
    Vector3D left_side;

    /**
     * @brief Computes a point on the rectangle given parameters u and v.
     * @param u The horizontal parameter (0 to 1).
     * @param v The vertical parameter (0 to 1).
     * @return The computed point on the rectangle.
     */
    Point3D pointAt(double u, double v) const;
  };
}  // namespace Math
