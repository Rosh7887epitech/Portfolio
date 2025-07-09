/*
** EPITECH PROJECT, 2025
** project
** File description:
** Camera
*/

#pragma once

#include <cmath>
#include <iostream>
#include "Point3D.hpp"
#include "Ray.hpp"
#include "Rectangle3D.hpp"
#include "Vector3D.hpp"

namespace RayTracer {
  /**
   * @brief Represents a camera in the ray tracer.
   */
  class Camera {
  public:
    /**
     * @brief Constructs a camera with a position, field of view, and image
     * dimensions.
     * @param position The position of the camera in 3D space.
     * @param fov The field of view of the camera in degrees.
     * @param image_width The width of the image to render.
     * @param image_height The height of the image to render.
     */
    Camera(const Math::Point3D& position, double fov, int image_width,
           int image_height);

    /**
     * @brief Generates a ray for a specific pixel in the image.
     * @param i The row index of the pixel.
     * @param j The column index of the pixel.
     * @return The ray corresponding to the pixel.
     */
    Ray ray(int i, int j) const;

    /**
     * @brief Gets the origin of the camera.
     * @return The origin point of the camera.
     */
    Math::Point3D getOrigin() const { return origin_; }

    void setResolution(int width, int height) {
      image_width_ = width;
      image_height_ = height;
    }

    /**
     * @brief Sets the position of the camera.
     * @param position The new position of the camera.
     */
    void setPosition(const Math::Point3D& position) { origin_ = position; }

    void setFOV(double fov) {
      double aspect_ratio = static_cast<double>(image_width_) / image_height_;
      double theta = fov * M_PI / 180.0;
      double half_height = std::tan(theta / 2.0);
      double half_width = aspect_ratio * half_height;
      Math::Point3D screen_center = origin_ + Math::Vector3D(0, 0, -1);
      Math::Vector3D horizontal(2 * half_width, 0, 0);
      Math::Vector3D vertical(0, -2 * half_height, 0);
      Math::Point3D bottom_left = screen_center - horizontal / 2 - vertical / 2;
      screen_ = Math::Rectangle3D(bottom_left, horizontal, vertical);
    }

  private:
    Math::Point3D origin_;  ///< The position of the camera.
    Math::Rectangle3D
        screen_;        ///< The screen rectangle representing the view plane.
    int image_width_;   ///< The width of the image to render.
    int image_height_;  ///< The height of the image to render.
  };
}  // namespace RayTracer
