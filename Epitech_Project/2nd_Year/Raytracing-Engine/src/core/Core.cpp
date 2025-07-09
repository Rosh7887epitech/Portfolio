/*
** EPITECH PROJECT, 2025
** project
** File description:
** Core
*/

#include "Core.hpp"
#include <thread>
#include "AmbientLight.hpp"
#include "Camera.hpp"
#include "DirectionalLight.hpp"
#include "Exception.hpp"
#include "IPrimitive.hpp"
#include "Matrix.hpp"
#include "Mesh.hpp"
#include "Parser.hpp"
#include "Plane.hpp"
#include "Point3D.hpp"
#include "Ray.hpp"
#include "Rectangle3D.hpp"
#include "ReflectionDecorator.hpp"
#include "Sphere.hpp"
#include "Vector3D.hpp"

namespace RayTracer {

  Core::Core()
      : image_width_(1920),
        image_height_(1080),
        framebuffer(image_width_ * image_height_),
        cam(Math::Point3D(0, 9, -55), 72.0, image_width_, image_height_) {}

  void Core::render_section(int start_y, int end_y) {
    for (int j = start_y; j < end_y; ++j) {
      for (int i = 0; i < image_width_; ++i) {
        Ray ray = cam.ray(i, j);
        Color pixel_color = cast_ray(ray, 0);
        framebuffer[j * image_width_ + i] = pixel_color;
      }
    }
  }

  void Core::render_scene() {
    int section_height = image_height_ / 4;
    std::vector<std::thread> threads;

    for (int i = 0; i < 4; ++i) {
      int start_y = i * section_height;
      int end_y = (i == 3) ? image_height_ : (i + 1) * section_height;
      threads.emplace_back(&Core::render_section, this, start_y, end_y);
    }

    for (auto& thread : threads) {
      thread.join();
    }
  }

  Color Core::cast_ray(const Ray& ray, int depth) {
    if (depth > 3)
      return Color(0.0, 0.0, 0.0);

    double closest_t = std::numeric_limits<double>::max();
    std::shared_ptr<IPrimitive> hit_obj = nullptr;
    for (auto& primitive : primitives_) {
      double t;
      if (primitive->hits(ray, t) && t < closest_t) {
        closest_t = t;
        hit_obj = primitive;
      }
    }
    if (hit_obj) {
      Math::Point3D hit_point = ray.origin + ray.direction * closest_t;
      Math::Vector3D normal = hit_obj->getNormal(hit_point);
      Color base_color = calculate_lighting(hit_point, normal, hit_obj);
      float alpha = 1.0f;
      if constexpr (std::is_base_of<
                        RayTracer::IPrimitive,
                        std::remove_reference_t<decltype(*hit_obj)>>::value) {
        alpha = hit_obj->getAlpha();
      } else {
        alpha = 1.0f;
      }
      Color final_color = base_color;
      if (alpha < 1.0f) {
        Ray behind_ray(hit_point + ray.direction * 0.001, ray.direction);
        Color bg_color = cast_ray(behind_ray, depth + 1);
        final_color = base_color * alpha + bg_color * (1.0f - alpha);
      }
      if (auto reflection =
              std::dynamic_pointer_cast<ReflectionDecorator>(hit_obj)) {
        float reflectivity = reflection->getReflectivity();
        Math::Vector3D reflected_dir =
            ray.direction - 2 * normal.dot(ray.direction) * normal;
        Ray reflected_ray(hit_point + reflected_dir * 0.001, reflected_dir);
        Color reflected_color = cast_ray(reflected_ray, depth + 1);
        final_color = final_color * (1.0f - reflectivity) +
                      reflected_color * reflectivity;
      }
      return final_color;
    }
    return Color(0.0, 0.0, 0.0);
  }

  Color Core::calculate_lighting(const Math::Point3D& hit_point,
                                 const Math::Vector3D& normal,
                                 const std::shared_ptr<IPrimitive>& hit_obj) {
    Math::Vector3D lighting(0.0, 0.0, 0.0);
    for (auto& light : lights_) {
      if (light->getType() == ILight::Type::AMBIENT) {
        lighting += light->getColor() * light->getIntensity();
        continue;
      }
      bool is_shadowed = calculate_shadow(hit_point, light);
      if (!is_shadowed) {
        lighting += calculate_phong(hit_point, normal, light);
      }
    }
    Math::Vector3D base_color = hit_obj->getColor(hit_point);
    Math::Vector3D final_color = base_color * lighting;
    return Color(final_color.x, final_color.y, final_color.z);
  }

  bool Core::calculate_shadow(const Math::Point3D& hit_point,
                              const std::shared_ptr<ILight>& light) {
    Math::Vector3D light_dir = light->getDirectionTo(hit_point);
    double distance_to_light = light->getDistanceTo(hit_point);
    Ray shadow_ray(hit_point + light_dir * 0.001, light_dir);

    for (const auto& obj : primitives_) {
      double t_shadow;
      if (obj->hits(shadow_ray, t_shadow) && t_shadow > 1e-3) {
        bool infinite_light = (light->getType() == ILight::Type::DIRECTIONAL);
        if (infinite_light || t_shadow < distance_to_light) {
          return true;
        }
      }
    }
    return false;
  }

  Math::Vector3D Core::calculate_phong(const Math::Point3D& hit_point,
                                       const Math::Vector3D& normal,
                                       const std::shared_ptr<ILight>& light) {
    Math::Vector3D light_dir = light->getDirectionTo(hit_point);
    Math::Vector3D view_dir = (cam.getOrigin() - hit_point).normalized();
    Math::Vector3D reflect_dir =
        (2 * normal.dot(light_dir) * normal - light_dir).normalized();
    double diffuse_intensity =
        std::max(0.0, normal.dot(light_dir)) * light->getIntensity();
    double specular_strength = 1.0;
    double shininess = 128.0;
    double spec = std::pow(std::max(view_dir.dot(reflect_dir), 0.0), shininess);
    Math::Vector3D specular = light->getColor() * spec * specular_strength;
    Math::Vector3D diffuse = light->getColor() * diffuse_intensity;
    return diffuse + specular;
  }

  void Core::save_framebuffer(const std::string& filename) {
    std::string base_name = filename.substr(filename.find_last_of("/\\") + 1);
    base_name = base_name.substr(0, base_name.find_last_of('.'));
    std::string output_filename = "screenshots/" + base_name + ".ppm";
    save_as_ppm(framebuffer, image_width_, image_height_, output_filename);
  }

  void Core::save_as_ppm(const std::vector<Color>& framebuffer, int width,
                         int height, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
      throw FileException("Cannot open file: " + filename);
    }

    file << "P3\n" << width << " " << height << "\n255\n";

    for (int j = 0; j < height; j++) {
      for (int i = 0; i < width; i++) {
        const Color& color = framebuffer[j * width + i];
        int ir = static_cast<int>(255.999 * std::clamp(color.r, 0.0, 1.0));
        int ig = static_cast<int>(255.999 * std::clamp(color.g, 0.0, 1.0));
        int ib = static_cast<int>(255.999 * std::clamp(color.b, 0.0, 1.0));
        file << ir << ' ' << ig << ' ' << ib << '\n';
      }
    }
  }

  sf::Uint8 clampColor(int value) {
    return static_cast<sf::Uint8>(std::min(std::max(0, value), 255));
  }

  void Core::sfmlWindow() {
    sf::RenderWindow window(sf::VideoMode(image_width_, image_height_),
                            "RayTracer");
    sf::Texture texture;
    texture.create(image_width_, image_height_);
    sf::Sprite sprite(texture);
    sf::Image image;

    image.create(image_width_, image_height_);
    for (int j = 0; j < image_height_; ++j) {
      for (int i = 0; i < image_width_; ++i) {
        const Color& color = framebuffer[j * image_width_ + i];
        int ir = static_cast<int>(255.999 * std::clamp(color.r, 0.0, 1.0));
        int ig = static_cast<int>(255.999 * std::clamp(color.g, 0.0, 1.0));
        int ib = static_cast<int>(255.999 * std::clamp(color.b, 0.0, 1.0));
        sf::Uint8 r = clampColor(ir);
        sf::Uint8 g = clampColor(ig);
        sf::Uint8 b = clampColor(ib);

        image.setPixel(i, j, sf::Color(r, g, b));
      }
    }
    texture.update(image);
    sprite.setTexture(texture);
    while (window.isOpen()) {
      sf::Event event;
      while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed ||
            (event.type == sf::Event::KeyPressed &&
             event.key.code == sf::Keyboard::Escape)) {
          window.close();
        }
      }
      window.clear();
      window.draw(sprite);
      window.display();
    }
  }
  int Core::render(std::string configfile) {
    try {
      Parser::Parser parser;
      parser.parse(configfile);
      cam = parser.getCamera();
      primitives_ = parser.getPrimitives();
      lights_ = parser.getLights();
      render_scene();
      save_framebuffer(configfile);
      sfmlWindow();
    } catch (const FileException& e) {
      std::cerr << e.what() << std::endl;
      return 84;
    } catch (const ConfigException& e) {
      std::cerr << e.what() << std::endl;
      return 84;
    } catch (const RenderException& e) {
      std::cerr << e.what() << std::endl;
      return 84;
    } catch (const PrimitiveException& e) {
      std::cerr << e.what() << std::endl;
      return 84;
    } catch (const CoreException& e) {
      std::cerr << e.what() << std::endl;
      return 84;
    } catch (const std::exception& e) {
      std::cerr << "Unknown exception caught: " << e.what() << std::endl;
      return 84;
    }
    return 0;
  }

}  // namespace RayTracer
