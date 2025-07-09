/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-raytracer-evann.bloutin
** File description:
** IPrimitive
*/

#pragma once

#include <memory>
#include "ITexture.hpp"
#include "ImageTexture.hpp"
#include "Ray.hpp"

namespace RayTracer {
  /**
   * @brief Interface for 3D primitives in the ray tracer.
   */
  class IPrimitive {
  public:
    /**
     * @brief Default virtual destructor.
     */
    virtual ~IPrimitive() = default;

    /**
     * @brief Checks if a ray intersects the primitive.
     * @param ray The ray to check.
     * @param t The distance to the intersection point, if any.
     * @return True if the ray intersects the primitive, false otherwise.
     */
    virtual bool hits(const Ray& ray, double& t) const = 0;

    /**
     * @brief Gets the normal vector at a given point on the primitive.
     * @param point The point on the primitive.
     * @return The normal vector at the given point.
     */
    virtual Math::Vector3D getNormal(const Math::Point3D& point) const = 0;

    /**
     * @brief Gets the color of the primitive.
     * @return The color vector of the primitive.
     */
    virtual Math::Vector3D getColor() const = 0;

    /**
     * @brief Sets the position of the primitive.
     * @param position The new position.
     */
    virtual void setPosition(const Math::Point3D& position) = 0;

    /**
     * @brief Sets the color of the primitive.
     * @param color The new color.
     */
    virtual void setColor(const Math::Vector3D& color) = 0;
    virtual Math::Vector3D getColor(const Math::Point3D&) const {
      return Math::Vector3D(1, 1, 1);
    }

    virtual void setTexture(std::shared_ptr<ITexture>) = 0;

    virtual void setAlpha(float alpha) = 0;
    virtual float getAlpha() const { return 1.0f; }

    virtual void setRefractiveIndex(float refractiveIndex) = 0;
  };
}  // namespace RayTracer
