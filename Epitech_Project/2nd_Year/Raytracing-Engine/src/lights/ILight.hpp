/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-raytracer-evann.bloutin
** File description:
** Light
*/

#pragma once

#include <memory>
#include <string>
#include "Point3D.hpp"
#include "Vector3D.hpp"

namespace RayTracer {
  /**
   * @brief Interface for light sources in the ray tracer.
   */
  class ILight {
  public:
    /**
     * @brief Enum representing the type of light.
     */
    enum class Type { POINT, DIRECTIONAL, AMBIENT };

    /**
     * @brief Default virtual destructor.
     */
    virtual ~ILight() = default;

    /**
     * @brief Gets the direction to a point from the light.
     * @param point The point to calculate the direction to.
     * @return The direction vector.
     */
    virtual Math::Vector3D getDirectionTo(const Math::Point3D& point) const = 0;

    /**
     * @brief Gets the distance to a point from the light.
     * @param point The point to calculate the distance to.
     * @return The distance value.
     */
    virtual double getDistanceTo(const Math::Point3D& point) const = 0;

    /**
     * @brief Gets the type of the light.
     * @return The type of the light.
     */
    virtual Type getType() const = 0;

    /**
     * @brief Gets the color of the light.
     * @return The color vector.
     */
    virtual const Math::Vector3D& getColor() const = 0;

    /**
     * @brief Gets the intensity of the light.
     * @return The intensity value.
     */
    virtual double getIntensity() const = 0;

    /**
     * @brief Sets the position of the light.
     * @param position The new position.
     */
    virtual void setPosition(const Math::Point3D& position) = 0;

    /**
     * @brief Sets the color of the light.
     * @param color The new color.
     */
    virtual void setColor(const Math::Vector3D& color) = 0;

    /**
     * @brief Sets the intensity of the light.
     * @param intensity The new intensity.
     */
    virtual void setIntensity(double intensity) = 0;
  };

}  // namespace RayTracer
