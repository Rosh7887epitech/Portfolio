/*
** EPITECH PROJECT, 2025
** Project
** File description:
** Acircuit
*/

#include "ACircuit.hpp"
#include "AComponent.hpp"


namespace nts
{
    ACircuit::ACircuit(std::string name) : _circuit_name(name)
    {
        _circuit_tick = -1;
        _isComponent = false;
    }

    void ACircuit::simulate(std::size_t tick)
    {
        (void)tick;
    }

    std::string ACircuit::getName() const
    {
        return _circuit_name;
    }

    void ACircuit::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
    {
        if (getIsInput(pin) == true && other.getIsInput(otherPin) == true) {
            std::cout << "Linking " << _circuit_name << " pin " << pin << " to " << other.getName() << " pin " << otherPin << std::endl;
            std::cerr << "Error: can't link two input" << std::endl;
            exit(84);
        }
        if (getIsOutput(pin) == true && other.getIsOutput(otherPin) == true) {
            std::cerr << "Error: can't link two output" << std::endl;
            exit(84);
        }
        _circuit_links[pin].first->setLink(_circuit_links[pin].second, other, otherPin);
    }

    std::shared_ptr<nts::IComponent>ACircuit::getLink(std::size_t pin) const
    {
        for (std::size_t i = 0; i < _circuit_links.size(); i++) {
            if (_circuit_links.count(pin) > 0)
                return _circuit_links.at(pin).first;
        }
        return nullptr;
    }

    bool ACircuit::getIsInput(std::size_t pin) const
    {
        bool ret = false;

        for (const auto &output : _circuit_isInput) {
            if (pin > 0 && pin == output)
                ret = true;
            else
                ret = false;
        }
        return ret;
    }

    bool ACircuit::getIsOutput(std::size_t pin) const
    {
        bool ret = false;

        for (const auto &output : _circuit_isOutput) {
            if (pin > 0 && pin == output)
                ret = true;
            else
                ret = false;
        }
        return ret;
    }

    void ACircuit::setState(std::string value)
    {
        (void)value;
    }

    bool ACircuit::getIsComponent() const
    {
        return _isComponent;
    }
}
