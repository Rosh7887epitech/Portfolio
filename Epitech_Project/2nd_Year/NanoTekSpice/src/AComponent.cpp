/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-titouan.bouillot-bachelier
** File description:
** AComponent
*/

#include "AComponent.hpp"
#include "ACircuit.hpp"

#include <algorithm>

namespace nts
{
    AComponent::AComponent(std::string name) : _name(name)
    {
        _tick = -1;
        _isComponent = true;
        _value = nts::UNDEFINED;
        _old_value = nts::UNDEFINED;

    }

    void AComponent::simulate(std::size_t tick)
    {
        (void)tick;
    }

    std::string AComponent::getName() const
    {
        return _name;
    }

    void AComponent::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
    {
        static bool firstLoop = true;

        if (other.getIsComponent() == false) {
            ACircuit *circuit = dynamic_cast<ACircuit*>(&other);
            circuit->setLink(otherPin, *this, pin);
            return;
        }
        if (getIsInput(pin) == true && other.getIsInput(otherPin) == true) {
            std::cout << "Linking " << _name << " pin " << pin << " to " << other.getName() << " pin " << otherPin << std::endl;
            std::cerr << "Error: can't link two input" << std::endl;
            exit(84);
        }
        if (getIsOutput(pin) == true && other.getIsOutput(otherPin) == true) {
            std::cerr << "Error: can't link two output" << std::endl;
            exit(84);
        }
        _links[pin] = {std::shared_ptr<IComponent>(&other, [](IComponent*) {}), otherPin};
        if (firstLoop) {
            firstLoop = false;
            other.setLink(otherPin, *this, pin);
            firstLoop = true;
        }
    }

    std::shared_ptr<nts::IComponent>AComponent::getLink(std::size_t pin) const
    {
        for (std::size_t i = 0; i < _links.size(); i++) {
            if (_links.count(pin) > 0)
                return _links.at(pin).first;
        }
        return nullptr;
    }

    bool AComponent::getIsInput(std::size_t pin) const
    {
        bool ret = false;

        for (const auto &output : isInput) {
            if (pin > 0 && pin == output)
                ret = true;
            else
                ret = false;
        }
        return ret;
    }

    bool AComponent::getIsOutput(std::size_t pin) const
    {
        bool ret = false;

        for (const auto &output : isOutput) {
            if (pin > 0 && pin == output)
                ret = true;
            else
                ret = false;
        }
        return ret;
    }

    void AComponent::setState(std::string value)
    {
        if (value == "1") {
            _value = nts::TRUE;
        } else if (value == "0") {
            _value = nts::FALSE;
        } else if (value == "U") {
            _value = nts::UNDEFINED;
        } else
            return;
    }

    bool AComponent::getIsComponent() const
    {
        return _isComponent;
    }
}
