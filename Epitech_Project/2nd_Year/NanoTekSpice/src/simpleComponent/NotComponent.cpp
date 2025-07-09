/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-titouan.bouillot-bachelier
** File description:
** NotComponent
*/

#include "NotComponent.hpp"

namespace nts
{
    NotComponent::NotComponent() : AComponent("not") {
        _states[1] = nts::UNDEFINED;
        _states[2] = nts::UNDEFINED;
        isInput.push_back(1);
        isOutput.push_back(2);
    }

    void NotComponent::simulate(std::size_t tick)
    {
        if (_tick == tick)
            return;
        _tick = tick;
        nts::state input = nts::UNDEFINED;
        if (_links[1].first != nullptr) {
            _links.at(1).first->simulate(tick);
            input = _links.at(1).first->compute(_links.at(1).second);
        }
        if (input == nts::UNDEFINED)
            _states[2]  = nts::UNDEFINED;
        else
            _states[2]  = input == nts::TRUE ? nts::FALSE : nts::TRUE;
    }

    nts::state NotComponent::compute(std::size_t pin)
    {
        if (pin != 2) {
            std::cerr << "Error: out of range" << std::endl;
            exit(84);
        }
        return _states[pin];
    }
}
