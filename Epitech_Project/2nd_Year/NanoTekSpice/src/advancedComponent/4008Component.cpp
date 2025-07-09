/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-titouan.bouillot-bachelier
** File description:
** 4008Component
*/

#include "4008Component.hpp"
#include "Factory.hpp"

namespace nts
{
    FourBitAdder::FourBitAdder() : ACircuit("4008")
    {
        std::shared_ptr<nts::IComponent> gate1 = nts::Factory().createComponent("adder");
        std::shared_ptr<nts::IComponent> gate2 = nts::Factory().createComponent("adder");
        std::shared_ptr<nts::IComponent> gate3 = nts::Factory().createComponent("adder");
        std::shared_ptr<nts::IComponent> gate4 = nts::Factory().createComponent("adder");

        _circuit_isInput.push_back(15);
        _circuit_isInput.push_back(1);
        _circuit_isInput.push_back(2);
        _circuit_isInput.push_back(3);
        _circuit_isInput.push_back(4);
        _circuit_isInput.push_back(5);
        _circuit_isInput.push_back(6);
        _circuit_isInput.push_back(7);
        _circuit_isInput.push_back(9);

        _circuit_isOutput.push_back(10);
        _circuit_isOutput.push_back(11);
        _circuit_isOutput.push_back(12);
        _circuit_isOutput.push_back(13);
        _circuit_isOutput.push_back(14);

        _circuit_links[15] = {gate1, 1};
        _circuit_links[1] = {gate1, 2};
        _circuit_links[2] = {gate2, 1};
        _circuit_links[3] = {gate2, 2};
        _circuit_links[4] = {gate3, 1};
        _circuit_links[5] = {gate3, 2};
        _circuit_links[6] = {gate4, 1};
        _circuit_links[7] = {gate4, 2};
        _circuit_links[9] = {gate4, 3};

        _circuit_links[10] = {gate4, 4};
        _circuit_links[11] = {gate3, 4};
        _circuit_links[12] = {gate2, 4};
        _circuit_links[13] = {gate1, 4};
        _circuit_links[14] = {gate1, 5};

        gate4->setLink(5, *gate3, 3);
        gate3->setLink(5, *gate2, 3);
        gate2->setLink(5, *gate1, 3);

    }

    void FourBitAdder::simulate(std::size_t tick)
    {
        if (_circuit_tick == tick)
            return;
        _circuit_tick = tick;
    }

    nts::state FourBitAdder::compute(size_t pin)
    {
        return _circuit_links[pin].first->compute(_circuit_links[pin].second);
    }

}
