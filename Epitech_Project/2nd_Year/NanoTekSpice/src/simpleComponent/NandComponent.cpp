/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-titouan.bouillot-bachelier
** File description:
** NandComponent
*/

#include "NandComponent.hpp"
#include "Factory.hpp"

namespace nts
{
    NandComponent::NandComponent() : ACircuit("nand")
    {
        std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("and");
        std::shared_ptr<nts::IComponent> inverter = nts::Factory().createComponent("not");
        _circuit_isInput.push_back(1);
        _circuit_isInput.push_back(2);
        _circuit_isOutput.push_back(3);
        _circuit_links[1] = {gate, 1};
        _circuit_links[2] = {gate, 2};
        _circuit_links[3] = {inverter, 2};
        gate->setLink(3, *inverter, 1);
    }

    void NandComponent::simulate(std::size_t tick)
    {
        if (_circuit_tick == tick)
            return;
        _circuit_tick = tick;
    }

    nts::state NandComponent::compute(size_t pin)
    {
        if (pin != 3) {
            std::cerr << "Error: out of range" << std::endl;
            exit(84);
        }
        return _circuit_links[pin].first->compute(_circuit_links[pin].second);
    }
}
