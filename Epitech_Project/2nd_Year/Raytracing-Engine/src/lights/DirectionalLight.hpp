/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-raytracer-evann.bloutin
** File description:
** DirectionalLight
*/

#pragma once

#include "ILight.hpp"
#include "Point3D.hpp"
#include "Vector3D.hpp"

namespace RayTracer {
  /**
   * @brief Represents a directional light source.
   */
  class DirectionalLight : public ILight {
  public:
    /**
     * @brief Constructs a directional light.
     * @param direction The direction of the light.
     * @param color The color of the light.
     * @param intensity The intensity of the light.
     */
    DirectionalLight(const Math::Vector3D& direction,
                     const Math::Vector3D& color, double intensity = 1.0);

    DirectionalLight() = default;

    /**
     * @brief Gets the direction to a point (always the light's direction).
     * @param point The point to calculate the direction to.
     * @return The direction vector.
     */
    Math::Vector3D getDirectionTo(const Math::Point3D& point) const override;

    /**
     * @brief Gets the distance to a point (infinite for directional light).
     * @param point The point to calculate the distance to.
     * @return The distance (always infinity).
     */
    double getDistanceTo(const Math::Point3D& point) const override;

    /**
     * @brief Gets the type of the light.
     * @return The type of the light (DIRECTIONAL).
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
     * @brief Sets the direction of the light.
     * @param direction The new direction.
     */
    void setPosition(const Math::Point3D& direction);
    /**
     * @brief Sets the color of the light.
     * @param color The new color.
     */
    void setColor(const Math::Vector3D& color);

    /**
     * @brief Sets the intensity of the light.
     * @param intensity The new intensity.
     */
    void setIntensity(double intensity) { intensity_ = intensity; }

  private:
    Math::Vector3D direction_;  ///< The direction of the light.
    Math::Vector3D color_;      ///< The color of the light.
    double intensity_;          ///< The intensity of the light.
  };

}  // namespace RayTracer
