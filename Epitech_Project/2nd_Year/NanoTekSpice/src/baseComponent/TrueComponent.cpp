/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-titouan.bouillot-bachelier
** File description:
** TrueComponent
*/

#include "TrueComponent.hpp"

namespace nts
{
    TrueComponent::TrueComponent() : AComponent("true") {
        _states[1] = nts::TRUE;
        isOutput.push_back(1);
    }

    void TrueComponent::simulate(std::size_t tick)
    {
        if (_tick == tick)
            return;
        _tick = tick;
    }

    nts::state TrueComponent::compute(std::size_t pin)
    {
        if (pin != 1) {
            std::cerr << "Error: out of range" << std::endl;
            exit(84);
        }
        return _states[pin];
    }
}
