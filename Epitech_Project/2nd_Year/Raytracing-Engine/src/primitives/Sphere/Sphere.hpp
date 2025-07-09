/*
** EPITECH PROJECT, 2025
** project
** File description:
** Sphere
*/

#pragma once

#include "IPrimitive.hpp"
#include "Point3D.hpp"
#include "SimpleColor.hpp"

#include <memory>
#include <string>

namespace RayTracer {
  /**
   * @brief Represents a 3D sphere primitive.
   */
  class Sphere : public IPrimitive {
  public:
    /**
     * @brief Default constructor.
     */
    Sphere() = default;

    /**
     * @brief Constructs a sphere with a center, radius, and color.
     * @param center The center point of the sphere.
     * @param radius The radius of the sphere.
     * @param color The color of the sphere.
     */
    Sphere(const Math::Point3D& center, double radius,
           const Math::Vector3D& color, float alpha, float refractiveIndex);
    Sphere(const Math::Point3D& center, double radius,
           std::shared_ptr<ITexture> texture, float alpha,
           float refractiveIndex);

    /**
     * @brief Default destructor.
     */
    ~Sphere() = default;

    /**
     * @brief Checks if a ray intersects the sphere.
     * @param ray The ray to check.
     * @param t The distance to the intersection point, if any.
     * @return True if the ray intersects the sphere, false otherwise.
     */
    bool hits(const Ray& ray, double& t) const override;

    /**
     * @brief Gets the normal vector at a given point on the sphere.
     * @param point The point on the sphere.
     * @return The normal vector at the given point.
     */
    Math::Vector3D getNormal(const Math::Point3D& point) const override;

    /**
     * @brief Gets the color of the sphere.
     * @return The color vector of the sphere.
     */
    Math::Vector3D getColor() const override;
    Math::Vector3D getColor(const Math::Point3D& point) const override;

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
     * @brief Sets the radius of the sphere.
     * @param radius The new radius.
     */
    void setRadius(double radius) { radius_ = radius; }

    void setTexture(std::shared_ptr<ITexture> texture) override;

    float getAlpha() const { return alpha_; }

    float getRefractiveIndex() const { return refractiveIndex_; }

    void setAlpha(float a) override { alpha_ = a; }

    void setRefractiveIndex(float ri) override { refractiveIndex_ = ri; }

  private:
    Math::Point3D center_;  ///< The center point of the sphere.
    double radius_;         ///< The radius of the sphere.
    Math::Vector3D color_;  ///< The color of the sphere.
    float alpha_ = 1.0f;
    float refractiveIndex_ = 1.0f;
    std::shared_ptr<ITexture> texture_ = nullptr;
  };
}  // namespace RayTracer
