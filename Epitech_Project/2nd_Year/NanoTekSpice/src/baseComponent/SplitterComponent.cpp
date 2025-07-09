/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-titouan.bouillot-bachelier
** File description:
** SplitterComponent
*/

#include "SplitterComponent.hpp"

namespace nts
{
    SplitterComponent::SplitterComponent() : AComponent("splitter") {
        _states[1] = nts::UNDEFINED;
        _states[2] = nts::UNDEFINED;
        isInput.push_back(1);
        isOutput.push_back(2);
    }

    void SplitterComponent::simulate(size_t tick)
    {
        if (_tick == tick)
            return;
        _tick = tick;
        if (_links[1].first != nullptr) {
            _links[1].first->simulate(tick);
            _states[1] = _links[1].first->compute(_links[1].second);
        }
        _states[2] = _states[1];
    }

    nts::state SplitterComponent::compute(size_t pin)
    {
        return _states[pin];
    }
}
