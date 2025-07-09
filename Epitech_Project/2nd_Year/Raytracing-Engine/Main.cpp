/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-raytracer-evann.bloutin
** File description:
** Main
*/

#include <iostream>
#include "Core.hpp"

int main(int ac, char** av) {
  if (ac != 2) {
    std::cerr << "USAGE: " << av[0] << " <SCENE_FILE>" << std::endl;
    std::cerr << "  SCENE_FILE: " << "scene configuration" << std::endl;
    return 84;
  } else if (std::string(av[1]) == "-help") {
    std::cout << "USAGE: " << av[0] << " <SCENE_FILE>" << std::endl;
    std::cout << "  SCENE_FILE: " << "scene configuration" << std::endl;
    return 0;
  }
  RayTracer::Core core;
  return core.render(av[1]);
}
