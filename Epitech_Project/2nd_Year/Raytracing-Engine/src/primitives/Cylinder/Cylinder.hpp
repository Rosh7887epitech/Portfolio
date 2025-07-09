/*
** EPITECH PROJECT, 2025
** project
** File description:
** Cylinder
*/

#pragma once

#include "IPrimitive.hpp"
#include "Point3D.hpp"
#include "Vector3D.hpp"

#include <memory>

namespace RayTracer {
  /**
   * @brief Represents a 3D cylinder primitive.
   */
  class Cylinder : public IPrimitive {
  public:
    /**
     * @brief Constructs a cylinder with a base, radius, height, and color.
     * @param base The base point of the cylinder.
     * @param radius The radius of the cylinder.
     * @param height The height of the cylinder.
     * @param color The color of the cylinder.
     */
    Cylinder(const Math::Point3D& base, double radius, double height,
             std::shared_ptr<ITexture> texture, float alpha,
             float refractiveIndex);

    Cylinder() = default;

    /**
     * @brief Default destructor.
     */
    ~Cylinder() = default;

    /**
     * @brief Checks if a ray intersects the cylinder.
     * @param ray The ray to check.
     * @param t The distance to the intersection point, if any.
     * @return True if the ray intersects the cylinder, false otherwise.
     */
    bool hits(const Ray& ray, double& t) const override;

    /**
     * @brief Gets the normal vector at a given point on the cylinder.
     * @param point The point on the cylinder.
     * @return The normal vector at the given point.
     */
    Math::Vector3D getNormal(const Math::Point3D& point) const override;

    /**
     * @brief Gets the color of the cylinder.
     * @return The color vector of the cylinder.
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
     * @brief Sets the height of the cylinder.
     * @param height The new height.
     */
    void setHeight(double height) { height_ = height; }

    /**
     * @brief Sets the radius of the cylinder.
     * @param radius The new radius.
     */
    void setRadius(double radius) { radius_ = radius; }

    void setTexture(std::shared_ptr<ITexture> texture) override;
    void setAlpha(float a) override;
    void setRefractiveIndex(float ri) override;
    float getAlpha() const;
    float getRefractiveIndex() const;

  private:
    Math::Point3D base_;     ///< The base point of the cylinder.
    Math::Vector3D normal_;  ///< The normal vector of the cylinder.
    double radius_;          ///< The radius of the cylinder.
    double height_;          ///< The height of the cylinder.
    Math::Vector3D color_;   ///< The color of the cylinder.
    float alpha_ = 1.0f;
    float refractiveIndex_ = 1.0f;
    std::shared_ptr<ITexture> texture_;
  };
}  // namespace RayTracer
