/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-raytracer-evann.bloutin
** File description:
** IPrimitiveDecorator
*/

#pragma once

#include <memory>
#include "IPrimitive.hpp"

namespace RayTracer {

  class IPrimitiveDecorator : public IPrimitive {
  protected:
    std::shared_ptr<IPrimitive> wrapped_;

  public:
    IPrimitiveDecorator() = default;
    IPrimitiveDecorator(std::shared_ptr<IPrimitive> primitive)
        : wrapped_(primitive) {}

    void setPosition(const Math::Point3D& pos) override {
      wrapped_->setPosition(pos);
    }

    void setColor(const Math::Vector3D& color) override {
      wrapped_->setColor(color);
    }

    Math::Vector3D getColor() const override { return wrapped_->getColor(); }

    bool hits(const Ray& ray, double& t) const override {
      return wrapped_->hits(ray, t);
    }

    Math::Vector3D getNormal(const Math::Point3D& point) const override {
      return wrapped_->getNormal(point);
    }

    void setAlpha(float alpha) override { wrapped_->setAlpha(alpha); }

    void setRefractiveIndex(float refractiveIndex) override {
      wrapped_->setRefractiveIndex(refractiveIndex);
    }
  };

}  // namespace RayTracer
