/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Parser.hpp
*/

#pragma once

#include <algorithm>
#include <fstream>
#include <iostream>
#include <libconfig.h++>
#include <sstream>
#include <string>
#include <vector>

#include "AmbientLight.hpp"
#include "Camera.hpp"
#include "ChessBoard.hpp"
#include "Cone.hpp"
#include "Cube.hpp"
#include "Cylinder.hpp"
#include "DirectionalLight.hpp"
#include "Factory.hpp"
#include "ITexture.hpp"
#include "ImageTexture.hpp"
#include "InfCone.hpp"
#include "InfCylinder.hpp"
#include "Matrix.hpp"
#include "Mesh.hpp"
#include "Mobius.hpp"
#include "Plane.hpp"
#include "PointLight.hpp"
#include "Rectangle3D.hpp"
#include "Sphere.hpp"
#include "Torus.hpp"
#include "Triangle.hpp"

namespace Parser {

  /**
   * @brief Parses configuration files for the ray tracer.
   */
  class Parser {
  public:
    /**
     * @brief Default constructor.
     */
    Parser();

    /**
     * @brief Default destructor.
     */
    ~Parser() = default;

    /**
     * @brief Parses a configuration file.
     * @param filePath The path to the configuration file.
     * @return An integer indicating success or failure.
     */
    int parse(const std::string& filePath);

    /**
     * @brief Parses the camera settings from the configuration.
     * @param root The root setting of the configuration.
     */
    void parseCamera(const libconfig::Setting& root);

    /**
     * @brief Parses the lights from the configuration.
     * @param root The root setting of the configuration.
     */
    void parseLight(const libconfig::Setting& root);

    /**
     * @brief Parses primitives from the configuration.
     * @param root The root setting of the configuration.
     */
    void parsePrimitives(const libconfig::Setting& root);

    /**
     * @brief Parses objects of a specific type from the configuration.
     * @param primitives The setting containing the primitives.
     * @param type The type of objects to parse.
     */
    void parseObjects(const libconfig::Setting& primitives,
                      const std::string& type);

    /**
     * @brief Parses mesh objects from the configuration.
     * @param root The root setting of the configuration.
     */
    void parseMesh(const libconfig::Setting& root);

    /**
     * @brief Gets the parsed camera.
     * @return The camera object.
     */
    RayTracer::Camera getCamera() const { return cam_; }

    /**
     * @brief Gets the parsed primitives.
     * @return A vector of shared pointers to the primitives.
     */
    std::vector<std::shared_ptr<RayTracer::IPrimitive>> getPrimitives() const {
      return primitives_;
    }

    /**
     * @brief Gets the parsed lights.
     * @return A vector of shared pointers to the lights.
     */
    std::vector<std::shared_ptr<RayTracer::ILight>> getLights() const {
      return lights_;
    }

  private:
    std::string _filePath;  ///< The path to the configuration file.
    RayTracer::Factory factory_;
    RayTracer::Camera cam_;  ///< The parsed camera.
    std::vector<std::shared_ptr<RayTracer::IPrimitive>>
        primitives_;  ///< The parsed primitives.
    std::vector<std::shared_ptr<RayTracer::ILight>>
        lights_;  ///< The parsed lights
  };

}  // namespace Parser
