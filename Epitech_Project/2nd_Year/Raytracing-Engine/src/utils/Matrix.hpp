/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-raytracer-evann.bloutin
** File description:
** Matrix
*/

#pragma once

#include "Point3D.hpp"
#include "Vector3D.hpp"

#include <array>
#include <cmath>
#include <iostream>
#include <stdexcept>

namespace Math {
  /**
   * @brief Represents a 4x4 transformation matrix for 3D operations.
   */
  class Matrix {
  public:
    /**
     * @brief Default constructor. Initializes the matrix to zero.
     */
    Matrix();

    /**
     * @brief Creates an identity matrix.
     * @return An identity matrix.
     */
    static Matrix identity();

    /**
     * @brief Creates a translation matrix.
     * @param tx Translation along the x-axis.
     * @param ty Translation along the y-axis.
     * @param tz Translation along the z-axis.
     * @return A translation matrix.
     */
    static Matrix translation(double tx, double ty, double tz);

    /**
     * @brief Creates a scaling matrix.
     * @param sx Scaling factor along the x-axis.
     * @param sy Scaling factor along the y-axis.
     * @param sz Scaling factor along the z-axis.
     * @return A scaling matrix.
     */
    static Matrix scale(double sx, double sy, double sz);

    /**
     * @brief Creates a rotation matrix around the Z-axis.
     * @param angle The rotation angle in radians.
     * @return A rotation matrix for the Z-axis.
     */
    static Matrix rotationZ(double angle);

    /**
     * @brief Creates a rotation matrix around the X-axis.
     * @param angle The rotation angle in radians.
     * @return A rotation matrix for the X-axis.
     */
    static Matrix rotationX(double angle);

    /**
     * @brief Creates a rotation matrix around the Y-axis.
     * @param angle The rotation angle in radians.
     * @return A rotation matrix for the Y-axis.
     */
    static Matrix rotationY(double angle);
    static Matrix shearing(double shxy, double shxz, double shyx, double shyz,
                           double shzx, double shzy);

    /**
     * @brief Transforms a 3D point using the matrix.
     * @param p The point to transform.
     * @return The transformed point.
     */
    Point3D transform(const Point3D& p) const;

    /**
     * @brief Transforms a 3D vector using the matrix.
     * @param v The vector to transform.
     * @return The transformed vector.
     */
    Vector3D transform(const Vector3D& v) const;

    /**
     * @brief Multiplies this matrix with another matrix.
     * @param other The matrix to multiply with.
     * @return The resulting matrix.
     */
    Matrix operator*(const Matrix& other) const;

    /**
     * @brief Accesses an element of the matrix for modification.
     * @param row The row index (0-based).
     * @param col The column index (0-based).
     * @return A reference to the element.
     * @throws std::out_of_range If the indices are out of bounds.
     */
    double& elementAt(int row, int col);

    /**
     * @brief Accesses an element of the matrix for reading.
     * @param row The row index (0-based).
     * @param col The column index (0-based).
     * @return The value of the element.
     * @throws std::out_of_range If the indices are out of bounds.
     */
    double elementAt(int row, int col) const;

    /**
     * @brief Prints the matrix to the standard output.
     */
    void print() const;

  private:
    std::array<std::array<double, 4>, 4> data;  ///< The 4x4 matrix data.
  };

}  // namespace Math
