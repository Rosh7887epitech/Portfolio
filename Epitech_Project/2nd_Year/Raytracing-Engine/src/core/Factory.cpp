/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-raytracer-evann.bloutin
** File description:
** Factory
*/

#include "Factory.hpp"
#include "AmbientLight.hpp"
#include "Cone.hpp"
#include "Cube.hpp"
#include "Cylinder.hpp"
#include "DirectionalLight.hpp"
#include "InfCone.hpp"
#include "InfCylinder.hpp"
#include "Mobius.hpp"
#include "Plane.hpp"
#include "PointLight.hpp"
#include "Sphere.hpp"
#include "Torus.hpp"
#include "Triangle.hpp"

namespace RayTracer {

  Factory::Factory() {
    initPrimitives();
    initLights();
  }

  void Factory::initPrimitives() {
    primitiveList["spheres"] = []() { return std::make_shared<Sphere>(); };
    primitiveList["planes"] = []() { return std::make_shared<Plane>(); };
    primitiveList["cylinders"] = []() { return std::make_shared<Cylinder>(); };
    primitiveList["cones"] = []() { return std::make_shared<Cone>(); };
    primitiveList["torus"] = []() { return std::make_shared<Torus>(); };
    primitiveList["triangles"] = []() { return std::make_shared<Triangle>(); };
    primitiveList["cubes"] = []() { return std::make_shared<Cube>(); };
    primitiveList["mobiusstrips"] = []() {
      return std::make_shared<MobiusStrip>();
    };
    primitiveList["infinitecylinders"] = []() {
      return std::make_shared<InfiniteCylinder>();
    };
    primitiveList["infinitecones"] = []() {
      return std::make_shared<InfiniteCone>();
    };
  }

  void Factory::initLights() {
    lightList["directional"] = []() {
      return std::make_shared<DirectionalLight>();
    };
    lightList["point"] = []() { return std::make_shared<PointLight>(); };
    lightList["ambient"] = []() { return std::make_shared<AmbientLight>(); };
  }

  std::shared_ptr<IPrimitive> Factory::createPrimitive(
      const std::string& type) {
    auto it = primitiveList.find(type);
    if (it != primitiveList.end()) {
      return it->second();
    }
    std::cerr << "Primitive type not found: " << type << std::endl;
    return nullptr;
  }

  std::shared_ptr<ILight> Factory::createLight(const std::string& type) {
    auto it = lightList.find(type);
    if (it != lightList.end()) {
      return it->second();
    }
    return nullptr;
  }
}  // namespace RayTracer
