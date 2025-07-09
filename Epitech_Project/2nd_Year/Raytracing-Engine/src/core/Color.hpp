/*
** EPITECH PROJECT, 2025
** project
** File description:
** Color
*/

#pragma once

namespace RayTracer {
  struct Color {
    double r, g, b;

    Color(double r = 0.0, double g = 0.0, double b = 0.0) : r(r), g(g), b(b) {}

    Color operator*(float scalar) const {
      return Color(r * scalar, g * scalar, b * scalar);
    }

    Color operator+(const Color& other) const {
      return Color(r + other.r, g + other.g, b + other.b);
    }

    Color& operator+=(const Color& other) {
      r += other.r;
      g += other.g;
      b += other.b;
      return *this;
    }

    Color& operator*=(float scalar) {
      r *= scalar;
      g *= scalar;
      b *= scalar;
      return *this;
    }
  };
}  // namespace RayTracer
