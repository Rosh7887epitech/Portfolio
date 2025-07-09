/*
** EPITECH PROJECT, 2025
** Project
** File description:
** Parse
*/

#include "AComponent.hpp"
#include "IComponent.hpp"
#include "ACircuit.hpp"
#include "Factory.hpp"
#include "Parse.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <tuple>
#include <memory>
#include <string.h>
#include <algorithm>

void Parse::parse_chipset(const std::string &section, std::map<std::string, std::shared_ptr<nts::IComponent>> &components)
{
    std::istringstream stream(section);
    nts::Factory factory;
    std::string line;

    while (std::getline(stream, line)) {
        std::istringstream lineStream(line);
        std::string type, name;
        if (lineStream >> type >> name) {
            std::shared_ptr<nts::IComponent> component;
            component = factory.createComponent(type);
            if (type == "true" || type == "false") {
                if (std::find(_trueAndFalse.begin(), _trueAndFalse.end(), name) != _trueAndFalse.end()) {
                    std::cerr << "Error: Duplicate component name '" << name << "'." << std::endl;
                    exit(84);
                }
                _trueAndFalse.push_back(name);
            }
            if (type == "output") {
                if (std::find(_outputs.begin(), _outputs.end(), name) != _outputs.end()) {
                    std::cerr << "Error: Duplicate component name '" << name << "'." << std::endl;
                    exit(84);
                }
                _outputs.push_back(name);
            }
            if (type == "input" || type == "clock") {
                if (std::find(_inputs.begin(), _inputs.end(), name) != _inputs.end()) {
                    std::cerr << "Error: Duplicate component name '" << name << "'." << std::endl;
                    exit(84);
                }
                _inputs.push_back(name);
            }
            if (!component) {
                std::cerr << "Unknown component type '" << type << "'."<< std::endl;
                exit(84);
            }
            components[name] = component;
            _comp[name] = component;
        }
    }
}

std::map<std::string, std::shared_ptr<nts::IComponent>> Parse::get_map()
{
    return _comp;
}

std::list<std::string> Parse::get_inputs()
{
    _inputs.sort();
    return _inputs;
}

std::list<std::string> Parse::get_outputs()
{
    _outputs.sort();
    return _outputs;
}

void Parse::parse_links(const std::string &section, std::vector<std::tuple<std::string, std::string, std::string, std::string>> &links, std::map<std::string, std::shared_ptr<nts::IComponent>> &components)
{
    std::istringstream stream(section);
    std::string line;

    while (std::getline(stream, line)) {
        std::istringstream lineStream(line);
        std::string comp1, pin1, comp2, pin2;

        if (std::getline(lineStream, comp1, ':') && std::getline(lineStream, pin1, ' ') &&
            std::getline(lineStream, comp2, ':') && std::getline(lineStream, pin2)) {
            links.emplace_back(comp1, pin1, comp2, pin2);
        } else {
            std::cerr << "Error: Invalid link format in line: " << line << std::endl;
            exit(84);
        }
    }
    for (auto &[name1, pin1, name2, pin2] : links) {
        if (name1.empty() || pin1.empty() || name2.empty() || pin2.empty() || std::stoi(pin1) < 0 || std::stoi(pin2) < 0) {
            std::cerr << "Invalid link format: " << name1 << ":" << pin1 << " -> " << name2 << ":" << pin2 << std::endl;
            exit(84);
        }
        for (long unsigned int i = 0; i < name2.size(); i++) {
            if (name2[i] == ' ') {
                name2.erase(i, 1);
                i--;
            }
        }
        if (components.find(name1) == components.end() || components.find(name2) == components.end()) {
            std::cerr << "Unknown component name in link." << std::endl;
            exit(84);
        }
        std::shared_ptr<nts::IComponent> component1 = components[name1];
        std::shared_ptr<nts::IComponent> component2 = components[name2];
        component1->setLink(std::stoi(pin1), *component2, std::stoi(pin2));
        if (std::find(_trueAndFalse.begin(), _trueAndFalse.end(), name1) != _trueAndFalse.end() && std::find(_outputs.begin(), _outputs.end(), name2) != _outputs.end()) {
            component2->simulate(1);
        }
        if (std::find(_trueAndFalse.begin(), _trueAndFalse.end(), name2) != _trueAndFalse.end() && std::find(_outputs.begin(), _outputs.end(), name1) != _outputs.end()) {
            component1->simulate(1);
        }
    }
}

void Parse::open_file(const std::string &fileName, std::map<std::string, std::shared_ptr<nts::IComponent>> components)
{
    std::ifstream file(fileName);
    if (fileName.substr(fileName.find_last_of(".") + 1) != "nts") {
        std::cerr << "Error: File " << fileName << " is not a .nts file." << std::endl;
        exit(84);
    }
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << fileName << std::endl;
        return;
    }

    std::string line, chipsetSection, linksSection;
    bool parsingChipset = false;
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#')
            continue;
        if (line == ".chipsets:") {
            parsingChipset = true;
            continue;
        }
        if (line == ".links:") {
            parsingChipset = false;
            continue;
        }
        if (parsingChipset) {
            chipsetSection += line + "\n";
        } else {
            linksSection += line + "\n";
        }
    }
    if (chipsetSection.empty()) {
        std::cerr << "Error: Empty chipset section." << std::endl;
        exit(84);
    }
    if (linksSection.empty()) {
        std::cerr << "Error: Empty links section." << std::endl;
        exit(84);
    }
    file.close();
    std::vector<std::tuple<std::string, std::string, std::string, std::string>> links;
    parse_chipset(chipsetSection, components);
    parse_links(linksSection, links, components);
}
