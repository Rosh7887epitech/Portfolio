/*
** EPITECH PROJECT, 2025
** project
** File description:
** Ray
*/

#pragma once
#include "Point3D.hpp"
#include "Vector3D.hpp"

namespace RayTracer {
  /**
   * @brief Represents a ray in 3D space.
   */
  class Ray {
  public:
    /**
     * @brief Default constructor.
     */
    Ray() = default;

    /**
     * @brief Constructs a ray with an origin and direction.
     * @param origin The starting point of the ray.
     * @param direction The direction vector of the ray.
     */
    Ray(const Math::Point3D& origin, const Math::Vector3D& direction);

    /**
     * @brief Default destructor.
     */
    ~Ray() = default;

    /**
     * @brief The origin point of the ray.
     */
    Math::Point3D origin;

    /**
     * @brief The direction vector of the ray.
     */
    Math::Vector3D direction;

    /**
     * @brief Gets the origin of the ray.
     * @return The origin point of the ray.
     */
    Math::Point3D getOrigin() const;

    /**
     * @brief Gets the direction of the ray.
     * @return The direction vector of the ray.
     */
    Math::Vector3D getDirection() const;
  };
}  // namespace RayTracer
