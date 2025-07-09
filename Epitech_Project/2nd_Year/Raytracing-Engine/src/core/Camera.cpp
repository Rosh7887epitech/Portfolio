/*
** EPITECH PROJECT, 2025
** project
** File description:
** Camera
*/

#include "Camera.hpp"

namespace RayTracer {

  Camera::Camera(const Math::Point3D& position, double fov, int image_width,
                 int image_height)
      : origin_(position),
        image_width_(image_width),
        image_height_(image_height) {
    double aspect_ratio = static_cast<double>(image_width) / image_height;
    double theta = fov * M_PI / 180.0;
    double half_height = std::tan(theta / 2.0);
    double half_width = aspect_ratio * half_height;
    Math::Point3D screen_center = origin_ + Math::Vector3D(0, 0, -1);
    Math::Vector3D horizontal(2 * half_width, 0, 0);
    Math::Vector3D vertical(0, -2 * half_height, 0);
    Math::Point3D bottom_left = screen_center - horizontal / 2 - vertical / 2;
    screen_ = Math::Rectangle3D(bottom_left, horizontal, vertical);
  }

  Ray Camera::ray(int i, int j) const {
    double u = static_cast<double>(i) / (image_width_ - 1);
    double v = static_cast<double>(j) / (image_height_ - 1);

    Math::Point3D point_on_screen = screen_.pointAt(u, v);
    Math::Vector3D direction = point_on_screen - origin_;
    return Ray(origin_, direction);
  }

}  // namespace RayTracer
