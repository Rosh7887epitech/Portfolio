/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-titouan.bouillot-bachelier
** File description:
** 4069
*/

#include "4069Component.hpp"
#include "Factory.hpp"

namespace nts {

    SixNotComponent::SixNotComponent() : ACircuit("4069")
    {
        std::shared_ptr<nts::IComponent> gate1 = nts::Factory().createComponent("not");
        std::shared_ptr<nts::IComponent> gate2 = nts::Factory().createComponent("not");
        std::shared_ptr<nts::IComponent> gate3 = nts::Factory().createComponent("not");
        std::shared_ptr<nts::IComponent> gate4 = nts::Factory().createComponent("not");
        std::shared_ptr<nts::IComponent> gate5 = nts::Factory().createComponent("not");
        std::shared_ptr<nts::IComponent> gate6 = nts::Factory().createComponent("not");

        _circuit_isInput.push_back(1);
        _circuit_isInput.push_back(3);
        _circuit_isInput.push_back(5);
        _circuit_isInput.push_back(9);
        _circuit_isInput.push_back(11);
        _circuit_isInput.push_back(13);

        _circuit_isOutput.push_back(2);
        _circuit_isOutput.push_back(4);
        _circuit_isOutput.push_back(6);
        _circuit_isOutput.push_back(8);
        _circuit_isOutput.push_back(10);
        _circuit_isOutput.push_back(12);

        _circuit_links[1] = {gate1, 1};
        _circuit_links[3] = {gate2, 1};
        _circuit_links[5] = {gate3, 1};
        _circuit_links[9] = {gate4, 1};
        _circuit_links[11] = {gate5, 1};
        _circuit_links[13] = {gate6, 1};

        _circuit_links[2] = {gate1, 2};
        _circuit_links[4] = {gate2, 2};
        _circuit_links[6] = {gate3, 2};
        _circuit_links[8] = {gate4, 2};
        _circuit_links[10] = {gate5, 2};
        _circuit_links[12] = {gate6, 2};
    }

    void SixNotComponent::simulate(std::size_t tick)
    {
        if (_circuit_tick == tick)
            return;
        _circuit_tick = tick;
    }

    nts::state SixNotComponent::compute(size_t pin)
    {
        return _circuit_links[pin].first->compute(_circuit_links[pin].second);
    }

}
