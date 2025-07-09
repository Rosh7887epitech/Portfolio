/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-titouan.bouillot-bachelier
** File description:
** InputComponent
*/

#include "InputComponent.hpp"

namespace nts
{
    InputComponent::InputComponent() : AComponent("input") {
        _states[1] = nts::UNDEFINED;
        isOutput.push_back(1);
    }

    void InputComponent::simulate(size_t tick)
    {
        if (_tick == tick)
            return;
        _tick = tick;
        _states[1] = _value;
    }

    nts::state InputComponent::compute(size_t pin)
    {
        if (pin != 1) {
            std::cerr << "Error: out of range" << std::endl;
            exit(84);
        }
        return _states[pin];
    }
}
