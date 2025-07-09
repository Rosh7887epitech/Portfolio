/*
** EPITECH PROJECT, 2025
** project
** File description:
** Mesh - OBJ File loader
*/

#pragma once

#include "IPrimitive.hpp"
#include "Matrix.hpp"
#include "Point3D.hpp"
#include "Vector3D.hpp"

#include <array>
#include <memory>
#include <string>
#include <vector>

namespace RayTracer {
  /**
   * @brief Class representing a 3D mesh loaded from an .obj file.
   *
   * Supports loading vertices and faces from an OBJ file.
   */
  class Mesh : public IPrimitive {
  public:
    /**
     * @brief Constructs a new Mesh from an OBJ file.
     * @param filename Path to the .obj file to load.
     * @param color Color of the mesh.
     * @param position Position of the mesh in the scene.
     * @param scale Scale factor of the mesh.
     */
    Mesh(const std::string& filename, const Math::Vector3D& color,
         const Math::Point3D& position = Math::Point3D(0, 0, 0),
         double scale = 1.0);

    /**
     * @brief Default destructor.
     */
    ~Mesh() = default;

    /**
     * @brief Checks if a ray hits the mesh.
     * @param ray The ray to check against.
     * @param t The distance to the hit point if a hit occurred.
     * @return True if hit, false otherwise.
     */
    bool hits(const Ray& ray, double& t) const override;

    /**
     * @brief Gets the normal vector at a given point on the mesh.
     * @param point The point to get the normal at.
     * @return The normal vector.
     */
    Math::Vector3D getNormal(const Math::Point3D& point) const override;

    /**
     * @brief Gets the color of the mesh.
     * @return The color vector.
     */
    Math::Vector3D getColor() const override;

    /**
     * @brief Gets the color of the mesh at a specific point.
     * @param point The point to get the color at.
     * @return The color vector at the given point.
     */
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
     * @brief Sets the scale of the mesh.
     * @param scale The new scale factor.
     */
    void setScale(double scale) { scale_ = scale; }

    /**
     * @brief Sets the texture of the mesh.
     * @param texture The new texture.
     */
    void setTexture(std::shared_ptr<ITexture> texture) override {
      (void) texture;
    }

    void setAlpha(float a) override { alpha_ = a; }

    void setRefractiveIndex(float ri) override { refractiveIndex_ = ri; }

  private:
    /**
     * @brief Loads mesh data from an OBJ file.
     * @param filename Path to the .obj file.
     * @return True if loading succeeded, false otherwise.
     */
    bool loadFromFile(const std::string& filename);

    /**
     * @brief Applies a transformation to a point.
     * @param point The point to transform.
     * @return The transformed point.
     */
    Math::Point3D transformPoint(const Math::Vector3D& point) const;

    /**
     * @brief Structure to represent a face (triangle) in the mesh.
     */
    struct Face {
      size_t v1, v2, v3;  ///< Vertex indices.
    };

    std::vector<Math::Vector3D> vertices_;  ///< Mesh vertices.
    std::vector<Face> faces_;               ///< Mesh faces.
    Math::Vector3D color_;                  ///< Mesh color.
    Math::Point3D position_;                ///< Mesh position in the scene.
    double scale_;                          ///< Mesh scale factor.
    mutable size_t lastHitFace_;  ///< Last face hit for normal calculation.
    float alpha_ = 1.0f;
    float refractiveIndex_ = 1.0f;
  };
}  // namespace RayTracer
