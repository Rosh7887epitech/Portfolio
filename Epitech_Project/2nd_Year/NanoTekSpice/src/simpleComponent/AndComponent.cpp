/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-titouan.bouillot-bachelier
** File description:
** AndComponent
*/

#include "AndComponent.hpp"

namespace nts
{
    AndComponent::AndComponent() : AComponent("and") {
        isInput.push_back(1);
        isInput.push_back(2);
        isOutput.push_back(3);
        _states[1] = nts::UNDEFINED;
        _states[2] = nts::UNDEFINED;
        _states[3] = nts::UNDEFINED;
    }

    void AndComponent::simulate(std::size_t tick)
    {
        if (_tick == tick)
            return;
        _tick = tick;
        nts::state a = nts::UNDEFINED;
        nts::state b = nts::UNDEFINED;
        if (_links[1].first != nullptr) {
            _links.at(1).first->simulate(tick);
            a = _links.at(1).first->compute(_links.at(1).second);
        }
        if (_links[2].first != nullptr) {
            _links.at(2).first->simulate(tick);
            b = _links.at(2).first->compute(_links.at(2).second);
        }
        if (a == nts::FALSE || b == nts::FALSE)
            _states[3] = nts::FALSE;
        else if (a == nts::TRUE && b == nts::TRUE)
            _states[3] = nts::TRUE;
        else
            _states[3] = nts::UNDEFINED;
    }

    nts::state AndComponent::compute(size_t pin)
    {
        if (pin != 3) {
            std::cerr << "Error: out of range" << std::endl;
            exit(84);
        }
        return _states[pin];
    }
}
