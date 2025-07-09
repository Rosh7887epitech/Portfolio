/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-titouan.bouillot-bachelier
** File description:
** ClockComponent
*/

#include "ClockComponent.hpp"

namespace nts
{
    ClockComponent::ClockComponent() : AComponent("clock") {
        _states[1] = nts::UNDEFINED;
        isOutput.push_back(1);
    }

    void ClockComponent::simulate(size_t tick)
    {
        if (_tick == tick)
            return;
        _tick = tick;
        if (_value != _old_value) {
            _states[1] = _value;
            _old_value = _value;
        } else if (_states[1] != nts::UNDEFINED) {
            _states[1] = (_states[1] == nts::TRUE) ? nts::FALSE : nts::TRUE;
        }
    }

    nts::state ClockComponent::compute(size_t pin)
    {
        if (pin != 1) {
            std::cerr << "Error: out of range" << std::endl;
            exit(84);
        }
        return _states[pin];
    }
}
