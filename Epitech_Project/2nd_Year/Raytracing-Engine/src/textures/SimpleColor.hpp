/*
** EPITECH PROJECT, 2025
** project
** File description:
** SimpleColor
*/

#ifndef SIMPLECOLOR_HPP_
#define SIMPLECOLOR_HPP_

#include "Color.hpp"
#include "ITexture.hpp"
#include "Vector3D.hpp"

namespace RayTracer {
  class SolidColorTexture : public ITexture {
  public:
    SolidColorTexture(const Color& color);
    Color getColor(const Math::Vector3D& point) const override;

  private:
    Color _color;
  };
}  // namespace RayTracer

#endif /* !SIMPLECOLOR_HPP_ */
