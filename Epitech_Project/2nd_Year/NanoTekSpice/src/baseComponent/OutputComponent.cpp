/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-titouan.bouillot-bachelier
** File description:
** OutputComponent
*/

#include "OutputComponent.hpp"

namespace nts
{
    OutputComponent::OutputComponent() : AComponent("output") {
        _states[1] = nts::UNDEFINED;
        isInput.push_back(1);
    }

    void OutputComponent::simulate(std::size_t tick)
    {
        if (_tick == tick)
            return;
        _tick = tick;
        if (_links[1].first == nullptr)
            return;
        _links[1].first->simulate(tick);
        _states[1] = _links[1].first->compute(_links.at(1).second);
    }

    nts::state OutputComponent::compute(std::size_t pin)
    {
        if (pin != 1) {
            std::cerr << "Error: out of range" << std::endl;
            exit(84);
        }
        return _states[pin];
    }
}
