/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-raytracer-evann.bloutin
** File description:
** ReflectionDecorator
*/

#pragma once

#include <memory>
#include "IPrimitiveDecorator.hpp"

namespace RayTracer {

  class ReflectionDecorator : public IPrimitiveDecorator {
  public:
    ReflectionDecorator(std::shared_ptr<IPrimitive> base, float reflectivity)
        : base_(base), reflectivity_(reflectivity) {}

    bool hits(const Ray& ray, double& t) const override {
      return base_->hits(ray, t);
    }

    Math::Vector3D getNormal(const Math::Point3D& point) const override {
      return base_->getNormal(point);
    }

    Math::Vector3D getColor() const override { return base_->getColor(); }

    void setTexture(std::shared_ptr<ITexture> texture) override {
      base_->setTexture(texture);
    }

    float getReflectivity() const { return reflectivity_; }

  private:
    std::shared_ptr<IPrimitive> base_;
    float reflectivity_;
  };

}  // namespace RayTracer
