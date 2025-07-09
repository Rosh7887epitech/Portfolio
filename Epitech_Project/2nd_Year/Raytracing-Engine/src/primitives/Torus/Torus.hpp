/*
** EPITECH PROJECT, 2025
** project
** File description:
** Torus
*/

#pragma once

#include "IPrimitive.hpp"
#include "Point3D.hpp"
#include "Vector3D.hpp"

#include <memory>
#include <string>

namespace RayTracer {

  class Torus : public IPrimitive {
  public:
    Torus() = default;
    Torus(const Math::Point3D& center, double radius, double tube_radius,
          const Math::Vector3D& color);
    ~Torus() = default;

    bool hits(const Ray& ray, double& t) const override;
    Math::Vector3D getNormal(const Math::Point3D& point) const override;
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

    void setRadius(double radius) { radius_ = radius; }
    void setTubeRadius(double tube_radius) { tube_radius_ = tube_radius; }

    void setTexture(std::shared_ptr<ITexture> texture) override;

    void setAlpha(float a) override { alpha_ = a; }

    void setRefractiveIndex(float ri) override { refractiveIndex_ = ri; }

  private:
    Math::Point3D center_;
    double radius_;
    double tube_radius_;
    Math::Vector3D color_;
    float alpha_ = 1.0f;
    float refractiveIndex_ = 1.0f;
  };
}  // namespace RayTracer
