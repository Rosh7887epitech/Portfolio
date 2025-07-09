/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-raytracer-evann.bloutin
** File description:
** Matrix
*/

#include "Matrix.hpp"
#include <cmath>
#include <iostream>
#include <stdexcept>

namespace Math {

  Matrix::Matrix() {
    for (auto& row : data) row.fill(0.0);
    for (int i = 0; i < 4; ++i) data[i][i] = 1.0;
  }

  Matrix Matrix::identity() {
    return Matrix();
  }

  Matrix Matrix::translation(double tx, double ty, double tz) {
    Matrix mat = identity();
    mat.data[0][3] = tx;
    mat.data[1][3] = ty;
    mat.data[2][3] = tz;
    return mat;
  }

  Matrix Matrix::scale(double sx, double sy, double sz) {
    Matrix mat;
    mat.data[0][0] = sx;
    mat.data[1][1] = sy;
    mat.data[2][2] = sz;
    mat.data[3][3] = 1.0;
    return mat;
  }

  Matrix Matrix::rotationX(double angleRad) {
    Matrix mat = identity();
    double c = std::cos(angleRad);
    double s = std::sin(angleRad);
    mat.data[1][1] = c;
    mat.data[1][2] = -s;
    mat.data[2][1] = s;
    mat.data[2][2] = c;
    return mat;
  }

  Matrix Matrix::rotationY(double angleRad) {
    Matrix mat = identity();
    double c = std::cos(angleRad);
    double s = std::sin(angleRad);
    mat.data[0][0] = c;
    mat.data[0][2] = s;
    mat.data[2][0] = -s;
    mat.data[2][2] = c;
    return mat;
  }

  Matrix Matrix::rotationZ(double angleRad) {
    Matrix mat = identity();
    double c = std::cos(angleRad);
    double s = std::sin(angleRad);
    mat.data[0][0] = c;
    mat.data[0][1] = -s;
    mat.data[1][0] = s;
    mat.data[1][1] = c;
    return mat;
  }

  Matrix Matrix::shearing(double shxy, double shxz, double shyx, double shyz,
                          double shzx, double shzy) {
    Matrix mat = identity();

    mat.data[0][1] = shxy;
    mat.data[0][2] = shxz;

    mat.data[1][0] = shyx;
    mat.data[1][2] = shyz;

    mat.data[2][0] = shzx;
    mat.data[2][1] = shzy;

    return mat;
  }

  Point3D Matrix::transform(const Point3D& p) const {
    double x =
        data[0][0] * p.x + data[0][1] * p.y + data[0][2] * p.z + data[0][3];
    double y =
        data[1][0] * p.x + data[1][1] * p.y + data[1][2] * p.z + data[1][3];
    double z =
        data[2][0] * p.x + data[2][1] * p.y + data[2][2] * p.z + data[2][3];
    return Point3D(x, y, z);
  }

  Vector3D Matrix::transform(const Vector3D& v) const {
    double x = data[0][0] * v.x + data[0][1] * v.y + data[0][2] * v.z;
    double y = data[1][0] * v.x + data[1][1] * v.y + data[1][2] * v.z;
    double z = data[2][0] * v.x + data[2][1] * v.y + data[2][2] * v.z;
    return Vector3D(x, y, z);
  }

  Matrix Matrix::operator*(const Matrix& other) const {
    Matrix result;
    for (int i = 0; i < 4; ++i)
      for (int j = 0; j < 4; ++j)
        for (int k = 0; k < 4; ++k)
          result.data[i][j] += data[i][k] * other.data[k][j];
    return result;
  }

  double& Matrix::elementAt(int row, int col) {
    if (row < 0 || row > 3 || col < 0 || col > 3)
      throw std::out_of_range("Matrix::elementAt - index out of range");
    return data[row][col];
  }

  double Matrix::elementAt(int row, int col) const {
    if (row < 0 || row > 3 || col < 0 || col > 3)
      throw std::out_of_range("Matrix::elementAt - index out of range");
    return data[row][col];
  }

  void Matrix::print() const {
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) std::cout << data[i][j] << ' ';
      std::cout << '\n';
    }
  }

}  // namespace Math
