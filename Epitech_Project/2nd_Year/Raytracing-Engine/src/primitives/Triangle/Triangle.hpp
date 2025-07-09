/*
** EPITECH PROJECT, 2025
** project
** File description:
** Triangle
*/

#pragma once

#include "IPrimitive.hpp"
#include "Point3D.hpp"
#include "Vector3D.hpp"

#include <memory>
#include <string>

namespace RayTracer {

  class Triangle : public IPrimitive {
  public:
    Triangle() = default;
    Triangle(const Math::Point3D& vertex1, const Math::Point3D& vertex2,
             const Math::Point3D& vertex3, const Math::Vector3D& color);
    ~Triangle() = default;

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

    /**
     * @brief Sets the vertices of the triangle.
     * @param vertex1 The first vertex.
     * @param vertex2 The second vertex.
     * @param vertex3 The third vertex.
     */
    void setVertexs(const Math::Point3D& vertex1, const Math::Point3D& vertex2,
                    const Math::Point3D& vertex3) {
      v1_ = vertex1;
      v2_ = vertex2;
      v3_ = vertex3;
    }

    void setTexture(std::shared_ptr<ITexture> texture) override;

    void setAlpha(float a) override { alpha_ = a; }

    void setRefractiveIndex(float ri) override { refractiveIndex_ = ri; }

  private:
    Math::Point3D v1_;
    Math::Point3D v2_;
    Math::Point3D v3_;
    Math::Vector3D color_;
    float alpha_ = 1.0f;
    float refractiveIndex_ = 1.0f;
  };
}  // namespace RayTracer
