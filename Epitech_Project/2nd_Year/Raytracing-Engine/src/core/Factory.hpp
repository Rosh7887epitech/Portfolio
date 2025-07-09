/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-raytracer-evann.bloutin
** File description:
** IFactory
*/

#pragma once

#include <functional>
#include <memory>
#include <string>
#include <unordered_map>
#include "ILight.hpp"
#include "IPrimitive.hpp"

namespace RayTracer {
  class Factory {
  public:
    Factory();
    std::shared_ptr<IPrimitive> createPrimitive(const std::string& type);
    std::shared_ptr<ILight> createLight(const std::string& type);

  private:
    std::unordered_map<std::string,
                       std::function<std::shared_ptr<IPrimitive>()>>
        primitiveList;
    std::unordered_map<std::string, std::function<std::shared_ptr<ILight>()>>
        lightList;

    void initPrimitives();
    void initLights();
  };
}  // namespace RayTracer
