/*
** EPITECH PROJECT, 2025
** project
** File description:
** Cone
*/

#pragma once

#include "IPrimitive.hpp"
#include "Point3D.hpp"
#include "Vector3D.hpp"

#include <memory>

namespace RayTracer {
  /**
   * @brief Represents a 3D cone primitive.
   */
  class Cone : public IPrimitive {
  public:
    /**
     * @brief Constructs a cone with a base, radius, height, and color.
     * @param base The base point of the cone.
     * @param radius The radius of the cone's base.
     * @param height The height of the cone.
     * @param color The color of the cone.
     */
    Cone(const Math::Point3D& base, double radius, double height,
         const Math::Vector3D& axis, std::shared_ptr<ITexture> texture,
         float alpha, float refractiveIndex);

    Cone() = default;

    ~Cone() = default;

    /**
     * @brief Checks if a ray intersects the cone.
     * @param ray The ray to check.
     * @param t The distance to the intersection point, if any.
     * @return True if the ray intersects the cone, false otherwise.
     */
    bool hits(const Ray& ray, double& t) const override;

    /**
     * @brief Gets the normal vector at a given point on the cone.
     * @param point The point on the cone.
     * @return The normal vector at the given point.
     */
    Math::Vector3D getNormal(const Math::Point3D& point) const override;

    /**
     * @brief Gets the color of the cone.
     * @return The color vector of the cone.
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
     * @brief Sets the axis of the cone.
     * @param axis The new axis.
     */
    void setAxis(const Math::Vector3D& axis) { axis_ = axis; }

    /**
     * @brief Sets the radius of the cone.
     * @param radius The new radius.
     */
    void setRadius(double radius) { radius_ = radius; }

    /**
     * @brief Sets the height of the cone.
     * @param height The new height.
     */
    void setHeight(double height) { height_ = height; }

    void setTexture(std::shared_ptr<ITexture> texture) override;
    void setAlpha(float a) override;
    void setRefractiveIndex(float ri) override;
    float getAlpha() const;
    float getRefractiveIndex() const;

  private:
    Math::Point3D base_;
    double radius_;
    double height_;
    Math::Vector3D axis_;
    Math::Vector3D color_;
    Math::Vector3D normal_;
    float alpha_ = 1.0f;
    float refractiveIndex_ = 1.0f;
    std::shared_ptr<ITexture> texture_;
  };
}  // namespace RayTracer
