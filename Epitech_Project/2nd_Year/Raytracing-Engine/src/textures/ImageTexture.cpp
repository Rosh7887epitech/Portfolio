/*
** EPITECH PROJECT, 2025
** project
** File description:
** ImageTexture
*/

#include "ImageTexture.hpp"
#include <cmath>

namespace RayTracer {
  ImageTexture::ImageTexture(const std::string& filename, double repeat)
      : _isLoaded(false), _repeat(repeat) {
    if (_image.loadFromFile(filename)) {
      _isLoaded = true;
      _width = _image.getSize().x;
      _height = _image.getSize().y;
      std::cout << "Successfully loaded image texture: " << filename << " ("
                << _width << "x" << _height << ")" << std::endl;
    } else {
      std::cerr << "Failed to load image texture: " << filename << std::endl;
    }
  }

  Color ImageTexture::getColor(const Math::Vector3D& point) const {
    if (!_isLoaded) {
      return Color(1.0, 0.0, 1.0);
    }
    double u = point.x * _repeat - std::floor(point.x * _repeat);
    double v = point.y * _repeat - std::floor(point.y * _repeat);
    if (u < 0)
      u += 1.0;
    if (v < 0)
      v += 1.0;
    unsigned int x = static_cast<unsigned int>(u * _width) % _width;
    unsigned int y = static_cast<unsigned int>(v * _height) % _height;
    sf::Color pixel = _image.getPixel(x, y);
    return Color(pixel.r / 255.0, pixel.g / 255.0, pixel.b / 255.0);
  }
}  // namespace RayTracer
