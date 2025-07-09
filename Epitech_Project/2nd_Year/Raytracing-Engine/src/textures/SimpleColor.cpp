/*
** EPITECH PROJECT, 2025
** project
** File description:
** SimpleColor
*/

#include "SimpleColor.hpp"

namespace RayTracer {
  SolidColorTexture::SolidColorTexture(const Color& color) : _color(color) {}

  Color SolidColorTexture::getColor(const Math::Vector3D& point) const {
    (void) point;
    return _color;
  }
}  // namespace RayTracer
