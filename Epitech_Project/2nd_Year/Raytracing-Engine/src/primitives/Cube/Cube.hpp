/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-raytracer-evann.bloutin
** File description:
** Cube
*/

#pragma once

#include "IPrimitive.hpp"
#include "Point3D.hpp"
#include "Ray.hpp"
#include "Vector3D.hpp"

namespace RayTracer {

  class Cube : public IPrimitive {
  public:
    Cube() = default;
    Cube(const Math::Point3D& center, double size, const Math::Vector3D& color);

    bool hits(const Ray& ray, double& t) const override;
    Math::Vector3D getNormal(const Math::Point3D& point) const override;
    Math::Vector3D getColor() const override;
    void setPosition(const Math::Point3D& position) override;
    void setColor(const Math::Vector3D& color) override;
    void setTexture(std::shared_ptr<ITexture> texture) override;
    void setAlpha(float alpha) override { (void) alpha; }
    void setRefractiveIndex(float refractiveIndex) override {
      (void) refractiveIndex;
    }

    void setSize(double size) { size_ = size; }

  private:
    Math::Point3D center_;
    double size_;
    Math::Vector3D color_;
  };

}  // namespace RayTracer
