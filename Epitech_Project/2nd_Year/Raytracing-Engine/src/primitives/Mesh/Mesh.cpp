/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Mesh.cpp
*/

#include "Mesh.hpp"
#include "Exception.hpp"

#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>

namespace RayTracer {
  Mesh::Mesh(const std::string& filename, const Math::Vector3D& color,
             const Math::Point3D& position, double scale)
      : color_(color), position_(position), scale_(scale), lastHitFace_(0) {
    if (!loadFromFile(filename)) {
      throw RayTracer::FileException("Failed to load mesh from file: " +
                                     filename);
    }
  }

  bool Mesh::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
      std::cerr << "Error: Cannot open file " << filename << std::endl;
      return false;
    }

    std::string line;
    while (std::getline(file, line)) {
      std::istringstream iss(line);
      std::string type;

      if (line.empty())
        continue;

      iss >> type;

      if (type == "v") {
        double x, y, z;
        if (!(iss >> x >> y >> z)) {
          std::cerr << "Error: Invalid vertex format in OBJ file" << std::endl;
          continue;
        }
        vertices_.emplace_back(x, y, z);
      } else if (type == "f") {
        std::string v1_str, v2_str, v3_str;

        if (!(iss >> v1_str >> v2_str >> v3_str)) {
          if (!v1_str.empty() && !v2_str.empty()) {
            std::cerr << "Warning: Face with less than 3 vertices detected"
                      << std::endl;
            continue;
          } else {
            std::cerr << "Error: Invalid face format in OBJ file" << std::endl;
            continue;
          }
        }

        size_t v1 = std::stoul(v1_str.substr(0, v1_str.find('/')));
        size_t v2 = std::stoul(v2_str.substr(0, v2_str.find('/')));
        size_t v3 = std::stoul(v3_str.substr(0, v3_str.find('/')));

        v1--;
        v2--;
        v3--;

        if (v1 >= vertices_.size() || v2 >= vertices_.size() ||
            v3 >= vertices_.size()) {
          std::cerr << "Error: Face references non-existent vertex"
                    << std::endl;
          continue;
        }

        faces_.push_back({v1, v2, v3});

        std::string v4_str;
        while (iss >> v4_str) {
          size_t v4 = std::stoul(v4_str.substr(0, v4_str.find('/')));
          v4--;

          if (v4 >= vertices_.size()) {
            std::cerr << "Error: Face references non-existent vertex"
                      << std::endl;
            continue;
          }

          faces_.push_back({v1, v3, v4});
          v3 = v4;
        }
      }
    }

    file.close();

    if (vertices_.empty() || faces_.empty()) {
      std::cerr << "Error: No vertices or faces found in OBJ file" << std::endl;
      return false;
    }
    return true;
  }

  Math::Point3D Mesh::transformPoint(const Math::Vector3D& point) const {
    return Math::Point3D(point.x * scale_ + position_.x,
                         point.y * scale_ + position_.y,
                         point.z * scale_ + position_.z);
  }

  bool Mesh::hits(const Ray& ray, double& t) const {
    const double EPSILON = 1e-8;
    bool hit = false;
    t = std::numeric_limits<double>::infinity();

    for (size_t i = 0; i < faces_.size(); i++) {
      const Face& face = faces_[i];

      Math::Point3D p0 = transformPoint(vertices_[face.v1]);
      Math::Point3D p1 = transformPoint(vertices_[face.v2]);
      Math::Point3D p2 = transformPoint(vertices_[face.v3]);

      Math::Vector3D v0(p0.x, p0.y, p0.z);
      Math::Vector3D v1(p1.x, p1.y, p1.z);
      Math::Vector3D v2(p2.x, p2.y, p2.z);

      Math::Vector3D edge1 = v1 - v0;
      Math::Vector3D edge2 = v2 - v0;

      Math::Vector3D h = ray.direction.cross(edge2);
      double a = edge1.dot(h);

      if (a > -EPSILON && a < EPSILON)
        continue;

      double f = 1.0 / a;
      Math::Vector3D originAsVector(ray.origin.x, ray.origin.y, ray.origin.z);
      Math::Vector3D s = originAsVector - v0;
      double u = f * s.dot(h);

      if (u < 0.0 || u > 1.0)
        continue;

      Math::Vector3D q = s.cross(edge1);
      double v = f * ray.direction.dot(q);

      if (v < 0.0 || u + v > 1.0)
        continue;

      double temp_t = f * edge2.dot(q);

      if (temp_t > EPSILON && temp_t < t) {
        t = temp_t;
        lastHitFace_ = i;
        hit = true;
      }
    }

    return hit;
  }

  Math::Vector3D Mesh::getNormal(const Math::Point3D& point) const {
    (void) point;
    if (faces_.empty() || lastHitFace_ >= faces_.size())
      return Math::Vector3D(0, 1, 0);

    const Face& face = faces_[lastHitFace_];

    Math::Point3D p0 = transformPoint(vertices_[face.v1]);
    Math::Point3D p1 = transformPoint(vertices_[face.v2]);
    Math::Point3D p2 = transformPoint(vertices_[face.v3]);

    Math::Vector3D v0(p0.x, p0.y, p0.z);
    Math::Vector3D v1(p1.x, p1.y, p1.z);
    Math::Vector3D v2(p2.x, p2.y, p2.z);

    Math::Vector3D edge1 = v1 - v0;
    Math::Vector3D edge2 = v2 - v0;
    Math::Vector3D normal = edge1.cross(edge2);

    static bool debug_printed = false;
    if (!debug_printed && (lastHitFace_ % 10 == 0)) {
      debug_printed = true;
    }

    return normal.normalized();
  }

  Math::Vector3D Mesh::getColor() const {
    return color_;
  }

  Math::Vector3D Mesh::getColor(const Math::Point3D& point) const {
    (void) point;
    return color_;
  }

  void Mesh::setPosition(const Math::Point3D& position) {
    position_ = position;
  }

  void Mesh::setColor(const Math::Vector3D& color) {
    color_ = color;
  }
}  // namespace RayTracer
