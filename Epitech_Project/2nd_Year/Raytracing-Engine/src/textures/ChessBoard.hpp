/*
** EPITECH PROJECT, 2025
** project
** File description:
** ChessBoard
*/

#pragma once

#include "Color.hpp"
#include "ITexture.hpp"
#include "Vector3D.hpp"

namespace RayTracer {
  class Chessboard : public ITexture {
  public:
    Chessboard(const Color& color1, const Color& color2, float scale);
    ~Chessboard() override = default;

    Color getColor(const Math::Vector3D& point) const override;

  private:
    Color _color1, _color2;
    float _scale;
  };
}  // namespace RayTracer
