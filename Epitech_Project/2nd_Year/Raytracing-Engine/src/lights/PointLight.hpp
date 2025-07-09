/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-raytracer-evann.bloutin
** File description:
** PointLight
*/

#pragma once

#include "ILight.hpp"

namespace RayTracer {
  /**
   * @brief Represents a point light source.
   */
  class PointLight : public ILight {
  public:
    /**
     * @brief Constructs a point light.
     * @param position The position of the light in 3D space.
     * @param color The color of the light.
     * @param intensity The intensity of the light.
     */
    PointLight(const Math::Point3D& position, const Math::Vector3D& color,
               double intensity = 1.0);

    PointLight() = default;

    /**
     * @brief Gets the direction to a point from the light.
     * @param point The point to calculate the direction to.
     * @return The direction vector.
     */
    Math::Vector3D getDirectionTo(const Math::Point3D& point) const override;

    /**
     * @brief Gets the distance to a point from the light.
     * @param point The point to calculate the distance to.
     * @return The distance value.
     */
    double getDistanceTo(const Math::Point3D& point) const override;

    /**
     * @brief Gets the type of the light.
     * @return The type of the light (POINT).
     */
    Type getType() const override;

    /**
     * @brief Gets the color of the light.
     * @return The color vector.
     */
    const Math::Vector3D& getColor() const override;

    /**
     * @brief Gets the intensity of the light.
     * @return The intensity value.
     */
    double getIntensity() const override;

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
     * @brief Sets the intensity of the light.
     * @param intensity The new intensity.
     */
    void setIntensity(double intensity) { intensity_ = intensity; }

  private:
    Math::Point3D position_;  ///< The position of the light.
    Math::Vector3D color_;    ///< The color of the light.
    double intensity_;        ///< The intensity of the light.
  };

}  // namespace RayTracer
