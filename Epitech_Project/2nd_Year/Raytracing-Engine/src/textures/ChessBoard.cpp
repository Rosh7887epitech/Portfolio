/*
** EPITECH PROJECT, 2025
** project
** File description:
** ChessBoard
*/

#include "ChessBoard.hpp"
#include <algorithm>
#include <cmath>
#include "Vector3D.hpp"

namespace RayTracer {

  Chessboard::Chessboard(const Color& color1, const Color& color2, float scale)
      : _color1(color1), _color2(color2), _scale(scale) {}

  Color Chessboard::getColor(const Math::Vector3D& point) const {
    double length =
        std::sqrt(point.x * point.x + point.y * point.y + point.z * point.z);
    if (length < 0.000001) {
      return _color1;
    }
    double nx = point.x / length;
    double ny = point.y / length;
    double nz = point.z / length;
    double theta = std::atan2(nz, nx);
    double phi = std::acos(std::clamp(ny, -1.0, 1.0));
    double u = (theta + M_PI) / (2 * M_PI);
    double v = phi / M_PI;
    int x = static_cast<int>(std::floor(u * _scale));
    int y = static_cast<int>(std::floor(v * _scale));

    if ((x ^ y) & 1)
      return _color1;
    return _color2;
  }
}  // namespace RayTracer
