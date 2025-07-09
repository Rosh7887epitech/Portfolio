/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-raytracer-evann.bloutin
** File description:
** Parser
*/

#include "Parser.hpp"
#include <iostream>
#include "ChessBoard.hpp"
#include "Color.hpp"
#include "Matrix.hpp"
#include "ReflectionDecorator.hpp"

namespace Parser {

  Parser::Parser()
      : factory_(), cam_(Math::Point3D(0, 0, 0), 72.0, 1920, 1080) {}

  int Parser::parse(const std::string& filePath) {
    _filePath = filePath;
    libconfig::Config cfg;

    try {
      cfg.readFile(_filePath);
      const libconfig::Setting& root = cfg.getRoot();
      parseCamera(root);
      parsePrimitives(root);
      parseLight(root);

      if (root.exists("obj")) {
        parseMesh(root["obj"]);
      }

    } catch (const libconfig::FileIOException& fioex) {
      std::cerr << "I/O error while reading file." << std::endl;
      return EXIT_FAILURE;
    } catch (const libconfig::ParseException& pex) {
      std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
                << " - " << pex.getError() << std::endl;
      return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
  }

  void Parser::parseCamera(const libconfig::Setting& root) {
    const libconfig::Setting& camera = root["camera"];
    float x, y, z, fov;
    float width, height;

    const libconfig::Setting& resolution = camera["resolution"];
    resolution.lookupValue("width", width);
    resolution.lookupValue("height", height);
    const libconfig::Setting& position = camera["position"];
    position.lookupValue("x", x);
    position.lookupValue("y", y);
    position.lookupValue("z", z);
    camera.lookupValue("fieldOfView", fov);

    cam_.setResolution(width, height);
    cam_.setPosition(Math::Point3D(x, y, z));
    cam_.setFOV(fov);
  }

  void Parser::parsePrimitives(const libconfig::Setting& root) {
    const libconfig::Setting& primitives = root["primitives"];

    parseObjects(primitives, "spheres");
    parseObjects(primitives, "cylinders");
    parseObjects(primitives, "cones");
    parseObjects(primitives, "planes");
    parseObjects(primitives, "triangles");
    parseObjects(primitives, "torus");
    parseObjects(primitives, "cubes");
    parseObjects(primitives, "mobiusstrips");
    parseObjects(primitives, "infinitecylinders");
    parseObjects(primitives, "infinitecones");
  }

  void Parser::parseObjects(const libconfig::Setting& primitives,
                            const std::string& type) {
    if (!primitives.exists(type))
      return;
    const libconfig::Setting& objects = primitives[type];
    for (int i = 0; i < objects.getLength(); ++i) {
      const libconfig::Setting& object = objects[i];
      float x, y, z, radius = 1.0f, height = 1.0f, alpha = 1.0f,
                     refractiveIndex = 1.0f, reflectivity = 0.0f;
      float cr = 1.0f, cg = 1.0f, cb = 1.0f;
      float angle = 0.0f;
      std::string axis = "Y";
      float innerRadius = 0.5f;
      object.lookupValue("x", x);
      object.lookupValue("y", y);
      object.lookupValue("z", z);
      object.lookupValue("radius", radius);
      object.lookupValue("height", height);
      object.lookupValue("alpha", alpha);
      object.lookupValue("refractive_index", refractiveIndex);
      object.lookupValue("reflectivity", reflectivity);
      object.lookupValue("angle", angle);
      object.lookupValue("innerRadius", innerRadius);
      object.lookupValue("axis", axis);
      const libconfig::Setting& color = object["color"];
      std::shared_ptr<RayTracer::IPrimitive> primitive =
          factory_.createPrimitive(type);
      bool isPng = false;
      std::string image;
      if (color.getType() == libconfig::Setting::TypeString) {
        image = (std::string) color;
        if (image.size() >= 4 && image.substr(image.size() - 4) == ".png") {
          isPng = true;
        }
      } else {
        color.lookupValue("r", cr);
        color.lookupValue("g", cg);
        color.lookupValue("b", cb);
        color.lookupValue("a", alpha);
      }
      if (primitive) {
        primitive->setPosition(Math::Point3D(x, y, z));
        primitive->setColor(Math::Vector3D(cr, cg, cb));
        primitive->setAlpha(alpha);
        if (isPng) {
          if (auto sphere =
                  std::dynamic_pointer_cast<RayTracer::Sphere>(primitive)) {
            sphere->setRadius(radius);
            sphere->setTexture(
                std::make_shared<RayTracer::ImageTexture>(image, 4.0));
          } else if (auto plane = std::dynamic_pointer_cast<RayTracer::Plane>(
                         primitive)) {
            plane->setAxis(axis);
            plane->setTexture(
                std::make_shared<RayTracer::ImageTexture>(image, 4.0));
          } else if (auto cylinder =
                         std::dynamic_pointer_cast<RayTracer::Cylinder>(
                             primitive)) {
            cylinder->setRadius(radius);
            cylinder->setHeight(height);
            cylinder->setTexture(
                std::make_shared<RayTracer::ImageTexture>(image, 4.0));
          } else if (auto cone = std::dynamic_pointer_cast<RayTracer::Cone>(
                         primitive)) {
            cone->setRadius(radius);
            cone->setHeight(height);
            cone->setAxis(Math::Vector3D(axis == "X" ? 1.0f : 0.0f,
                                         axis == "Y" ? 1.0f : 0.0f,
                                         axis == "Z" ? 1.0f : 0.0f));
            cone->setTexture(
                std::make_shared<RayTracer::ImageTexture>(image, 4.0));
          } else if (auto torus = std::dynamic_pointer_cast<RayTracer::Torus>(
                         primitive)) {
            torus->setRadius(radius);
            torus->setTubeRadius(innerRadius);
            torus->setTexture(
                std::make_shared<RayTracer::ImageTexture>(image, 4.0));
          }
        } else {
          primitive->setColor(Math::Vector3D(cr, cg, cb));
          if (auto sphere =
                  std::dynamic_pointer_cast<RayTracer::Sphere>(primitive)) {
            sphere->setRadius(radius);
          } else if (auto cylinder =
                         std::dynamic_pointer_cast<RayTracer::Cylinder>(
                             primitive)) {
            cylinder->setRadius(radius);
            cylinder->setHeight(height);
          } else if (auto cone = std::dynamic_pointer_cast<RayTracer::Cone>(
                         primitive)) {
            cone->setRadius(radius);
            cone->setHeight(height);
            cone->setAxis(Math::Vector3D(axis == "X" ? 1.0f : 0.0f,
                                         axis == "Y" ? 1.0f : 0.0f,
                                         axis == "Z" ? 1.0f : 0.0f));
          } else if (auto plane = std::dynamic_pointer_cast<RayTracer::Plane>(
                         primitive)) {
            plane->setAxis(axis);
          } else if (auto torus = std::dynamic_pointer_cast<RayTracer::Torus>(
                         primitive)) {
            torus->setRadius(radius);
            torus->setTubeRadius(innerRadius);
          } else if (auto cube = std::dynamic_pointer_cast<RayTracer::Cube>(
                         primitive)) {
            cube->setSize(radius);
          } else if (auto mobius =
                         std::dynamic_pointer_cast<RayTracer::MobiusStrip>(
                             primitive)) {
            mobius->setSize(radius);
          } else if (type == "infinitecylinders") {
            primitive = std::make_shared<RayTracer::InfiniteCylinder>(
                Math::Point3D(x, y, z), radius, Math::Vector3D(cr, cg, cb));
          } else if (type == "infinitecones") {
            float angle = 0.5f;
            object.lookupValue("angle", angle);
            primitive = std::make_shared<RayTracer::InfiniteCone>(
                Math::Point3D(x, y, z), angle, Math::Vector3D(cr, cg, cb));
          } else if (type == "triangles") {
            float x1, y1, z1, x2, y2, z2, x3, y3, z3;
            const libconfig::Setting& v1 = object["v1"];
            const libconfig::Setting& v2 = object["v2"];
            const libconfig::Setting& v3 = object["v3"];
            v1.lookupValue("x", x1);
            v1.lookupValue("y", y1);
            v1.lookupValue("z", z1);
            v2.lookupValue("x", x2);
            v2.lookupValue("y", y2);
            v2.lookupValue("z", z2);
            v3.lookupValue("x", x3);
            v3.lookupValue("y", y3);
            v3.lookupValue("z", z3);

            primitive = std::make_shared<RayTracer::Triangle>(
                Math::Point3D(x1, y1, z1), Math::Point3D(x2, y2, z2),
                Math::Point3D(x3, y3, z3), Math::Vector3D(cr, cg, cb));
          }
          if (reflectivity > 0.0f) {
            primitive = std::make_shared<RayTracer::ReflectionDecorator>(
                primitive, reflectivity);
          }
          primitives_.push_back(primitive);
        }
      }
    }
  }

  void Parser::parseMesh(const libconfig::Setting& obj) {
    const libconfig::Setting& files = obj["files"];
    for (int i = 0; i < files.getLength(); ++i) {
      const libconfig::Setting& file = files[i];
      std::string meshPath;
      float scale, cr, cg, cb;
      file.lookupValue("meshPath", meshPath);
      file.lookupValue("scale", scale);
      const libconfig::Setting& position = file["position"];
      float x, y, z;
      position.lookupValue("x", x);
      position.lookupValue("y", y);
      position.lookupValue("z", z);
      const libconfig::Setting& color = file["color"];
      color.lookupValue("r", cr);
      color.lookupValue("g", cg);
      color.lookupValue("b", cb);
      auto mesh = std::make_shared<RayTracer::Mesh>(
          meshPath, Math::Vector3D(cr, cg, cb), Math::Point3D(x, y, z), scale);
      primitives_.push_back(mesh);
    }
  }

  void Parser::parseLight(const libconfig::Setting& root) {
    const libconfig::Setting& lights = root["lights"];
    float ambient, diffuse;

    lights.lookupValue("ambient", ambient);
    lights.lookupValue("diffuse", diffuse);
    lights_.push_back(factory_.createLight("ambient"));
    const libconfig::Setting& pointLights = lights["point"];
    for (int i = 0; i < pointLights.getLength(); ++i) {
      const libconfig::Setting& point = pointLights[i];
      float x, y, z, intensity;
      point.lookupValue("x", x);
      point.lookupValue("y", y);
      point.lookupValue("z", z);
      point.lookupValue("intensity", intensity);
      auto pointLight = factory_.createLight("point");
      pointLight->setPosition(Math::Point3D(x, y, z));
      pointLight->setIntensity(intensity * diffuse);
      lights_.push_back(pointLight);
    }
    const libconfig::Setting& directionalLights = lights["directional"];
    for (int i = 0; i < directionalLights.getLength(); ++i) {
      const libconfig::Setting& directional = directionalLights[i];
      float dx, dy, dz, intensity, cr, cg, cb;
      directional.lookupValue("intensity", intensity);
      const libconfig::Setting& dir = directional["direction"];
      dir.lookupValue("x", dx);
      dir.lookupValue("y", dy);
      dir.lookupValue("z", dz);
      const libconfig::Setting& color = directional["color"];
      color.lookupValue("r", cr);
      color.lookupValue("g", cg);
      color.lookupValue("b", cb);
      auto dirLight = factory_.createLight("directional");
      dirLight->setPosition(Math::Point3D(dx, dy, dz));
      dirLight->setColor(Math::Vector3D(cr, cg, cb));
      dirLight->setIntensity(intensity * diffuse);
      lights_.push_back(dirLight);
    }
  }
}  // namespace Parser
