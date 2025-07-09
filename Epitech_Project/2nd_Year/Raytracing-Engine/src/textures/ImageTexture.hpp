/*
** EPITECH PROJECT, 2025
** project
** File description:
** ImageTexture
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <string>
#include "Color.hpp"
#include "ITexture.hpp"

namespace RayTracer {
  class ImageTexture : public ITexture {
  public:
    ImageTexture(const std::string& filename, double repeat = 4.0);
    virtual ~ImageTexture() = default;

    virtual Color getColor(const Math::Vector3D& point) const override;
    void setRepeat(double repeat) { _repeat = repeat; }

  private:
    sf::Image _image;
    bool _isLoaded;
    unsigned int _width;
    unsigned int _height;
    double _repeat = 4.0;
  };
}  // namespace RayTracer
