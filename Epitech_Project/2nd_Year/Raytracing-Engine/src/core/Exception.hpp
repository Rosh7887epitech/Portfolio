/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-raytracer-evann.bloutin
** File description:
** Exception
*/

#pragma once
#include <exception>
#include <string>

namespace RayTracer {

  class CoreException : public std::exception {
  public:
    CoreException(const std::string& message) : message_(message) {}
    virtual const char* what() const noexcept override {
      return message_.c_str();
    }

  private:
    std::string message_;
  };

  class FileException : public CoreException {
  public:
    FileException(const std::string& message)
        : CoreException("File Error: " + message) {}
  };

  class ConfigException : public CoreException {
  public:
    ConfigException(const std::string& message)
        : CoreException("Config Error: " + message) {}
  };

  class RenderException : public CoreException {
  public:
    RenderException(const std::string& message)
        : CoreException("Render Error: " + message) {}
  };

  class PrimitiveException : public CoreException {
  public:
    PrimitiveException(const std::string& message)
        : CoreException("Primitive Error: " + message) {}
  };

}  // namespace RayTracer
