/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-raytracer-evann.bloutin
** File description:
** Plane
*/

#pragma once

#include "Core.hpp"
#include "IPrimitive.hpp"
#include "Point3D.hpp"
#include "Ray.hpp"
#include "Vector3D.hpp"

#include <memory>
#include <string>

namespace RayTracer {
  /**
   * @brief Represents a 3D plane primitive.
   */
  class Plane : public IPrimitive {
  public:
    /**
     * @brief Default constructor.
     */
    Plane() = default;

    /**
     * @brief Constructs a plane with an axis, position, and color.
     * @param axis The axis of the plane (e.g., "x", "y", or "z").
     * @param position The position of the plane in 3D space.
     * @param color The color of the plane.
     */
    Plane(const std::string& axis, const Math::Point3D& position,
          std::shared_ptr<ITexture> texture, float alpha, float refractiveIndex)
        : axis_(axis),
          position_(position),
          color_(Math::Vector3D(1.0, 1.0, 1.0)),
          alpha_(alpha),
          refractiveIndex_(refractiveIndex),
          texture_(texture) {}

    /**
     * @brief Default destructor.
     */
    ~Plane() = default;

    /**
     * @brief Checks if a ray intersects the plane.
     * @param ray The ray to check.
     * @param t The distance to the intersection point, if any.
     * @return True if the ray intersects the plane, false otherwise.
     */
    bool hits(const Ray& ray, double& t) const override;

    /**
     * @brief Gets the normal vector at a given point on the plane.
     * @param point The point on the plane.
     * @return The normal vector at the given point.
     */
    Math::Vector3D getNormal(const Math::Point3D& point) const override;

    /**
     * @brief Gets the color of the plane.
     * @return The color vector of the plane.
     */
    Math::Vector3D getColor() const override;

    Math::Vector3D getColor(const Math::Point3D& point) const override;
    /**
     * @brief Gets the color at a specific point on the plane.
     * @param point The point on the plane.
     * @return The color at the given point.
     */
    struct Color getColorAt(const Math::Point3D& point) const;

    /**
     * @brief Sets the position of the cone.
     * @param position The new position.
     */
    void setPosition(const Math::Point3D& position) override;

    /**
     * @brief Sets the color of the cone.
     * @param color The new color.
     */
    void setColor(const Math::Vector3D& color) override;

    /**
     * @brief Sets the axis of the plane.
     * @param axis The new axis.
     */
    void setAxis(const std::string& axis) {
      axis_ = axis;
      if (axis == "X") {
        normal_ = Math::Vector3D(1, 0, 0);
      } else if (axis == "Y") {
        normal_ = Math::Vector3D(0, 1, 0);
      } else if (axis == "Z") {
        normal_ = Math::Vector3D(0, 0, 1);
      }
    }

    void setTexture(std::shared_ptr<ITexture> texture) override;
    void setAlpha(float a) override { alpha_ = a; }
    void setRefractiveIndex(float ri) override { refractiveIndex_ = ri; }
    float getAlpha() const { return alpha_; }
    float getRefractiveIndex() const { return refractiveIndex_; }

  private:
    std::string axis_;        ///< The axis of the plane.
    Math::Point3D position_;  ///< The position of the plane.
    Math::Vector3D normal_;   ///< The normal vector of the plane.
    Math::Vector3D color_;    ///< The color of the plane.
    float alpha_ = 1.0f;
    float refractiveIndex_ = 1.0f;
    std::shared_ptr<ITexture> texture_ = nullptr;
  };
}  // namespace RayTracer
