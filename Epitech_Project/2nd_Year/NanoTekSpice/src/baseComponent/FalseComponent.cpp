/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-titouan.bouillot-bachelier
** File description:
** FalseComponent
*/

#include "FalseComponent.hpp"

namespace nts
{
    FalseComponent::FalseComponent() : AComponent("false") {
        _states[1] = nts::FALSE;
        isOutput.push_back(1);
    }

    void FalseComponent::simulate(std::size_t tick)
    {
        if (_tick == tick)
            return;
        _tick = tick;
    }

    nts::state FalseComponent::compute(size_t pin)
    {
        if (pin != 1) {
            std::cerr << "Error: out of range" << std::endl;
            exit(84);
        }
        return _states[pin];
    }
}
