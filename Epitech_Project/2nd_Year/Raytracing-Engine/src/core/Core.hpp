/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-bsraytracer-robin.schuffenecker
** File description:
** Core
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>

#include "AmbientLight.hpp"
#include "Camera.hpp"
#include "ChessBoard.hpp"
#include "Color.hpp"
#include "Cone.hpp"
#include "Cylinder.hpp"
#include "DirectionalLight.hpp"
#include "Exception.hpp"
#include "Factory.hpp"
#include "Matrix.hpp"
#include "Mesh.hpp"
#include "Parser.hpp"
#include "Point3D.hpp"
#include "PointLight.hpp"
#include "Ray.hpp"
#include "Rectangle3D.hpp"
#include "Vector3D.hpp"

namespace RayTracer {
  class Core {
  public:
    /**
     * @brief Default constructor.
     */
    Core();

    /**
     * @brief Default destructor.
     */
    ~Core() = default;

    /**
     * @brief Renders a scene based on a configuration file.
     * @param configfile The path to the configuration file.
     * @return An integer indicating the success or failure of the rendering
     * process.
     */
    int render(std::string configfile);

  private:
    /**
     * @brief Renders the entire scene.
     */
    void render_scene();

    /**
     * @brief Casts a ray and calculates its color.
     * @param ray The ray to cast.
     * @return The color resulting from the ray.
     */
    Color cast_ray(const Ray& ray, int depth = 0);

    /**
     * @brief Calculates lighting at a given point.
     * @param hit_point The point where the ray hits an object.
     * @param normal The normal vector at the hit point.
     * @param hit_obj The object that was hit.
     * @return The calculated color at the hit point.
     */
    Color calculate_lighting(const Math::Point3D& hit_point,
                             const Math::Vector3D& normal,
                             const std::shared_ptr<IPrimitive>& hit_obj);

    /**
     * @brief Determines if a point is in shadow.
     * @param hit_point The point to check.
     * @param light The light source to consider.
     * @return True if the point is in shadow, false otherwise.
     */
    bool calculate_shadow(const Math::Point3D& hit_point,
                          const std::shared_ptr<ILight>& light);

    /**
     * @brief Calculates the Phong lighting model at a point.
     * @param hit_point The point to calculate lighting for.
     * @param normal The normal vector at the point.
     * @param light The light source to consider.
     * @return The resulting vector from the Phong calculation.
     */
    Math::Vector3D calculate_phong(
        const Math::Point3D& hit_point, const Math::Vector3D& normal,
        const std::shared_ptr<RayTracer::ILight>& light);

    /**
     * @brief Saves the framebuffer to a file.
     * @param filename The name of the file to save to.
     */
    void save_framebuffer(const std::string& filename);

    /**
     * @brief Saves the framebuffer as a PPM image.
     * @param framebuffer The framebuffer data.
     * @param width The width of the image.
     * @param height The height of the image.
     * @param filename The name of the file to save to.
     */
    void save_as_ppm(const std::vector<Color>& framebuffer, int width,
                     int height, const std::string& filename);
    void sfmlWindow();

    /**
     * @brief Renders a section of the scene
     * @param start_y Starting Y coordinate
     * @param end_y Ending Y coordinate
     */
    void render_section(int start_y, int end_y);

    int image_width_;                ///< The width of the rendered image.
    int image_height_;               ///< The height of the rendered image.
    std::vector<Color> framebuffer;  ///< The framebuffer storing pixel colors.
    Camera cam;                      ///< The camera used for rendering.
    std::vector<std::shared_ptr<IPrimitive>>
        primitives_;  ///< The primitives in the scene.
    std::vector<std::shared_ptr<ILight>> lights_;  ///< The lights in the scene.
  };
}  // namespace RayTracer
