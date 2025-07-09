/*
** EPITECH PROJECT, 2025
** project
** File description:
** ITexture
*/

#pragma once

#include "Color.hpp"
#include "Vector3D.hpp"

namespace RayTracer {
  class ITexture {
  public:
    virtual ~ITexture() = default;
    virtual Color getColor(const Math::Vector3D& point) const = 0;
  };
}  // namespace RayTracer
