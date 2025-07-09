/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-titouan.bouillot-bachelier
** File description:
** fullAdder
*/

#include "FullAdder.hpp"
#include "Factory.hpp"

namespace nts
{

    FullAdderComponent::FullAdderComponent() : ACircuit("adder")
    {
        std::shared_ptr<nts::IComponent> xor1 = nts::Factory().createComponent("xor");
        std::shared_ptr<nts::IComponent> xor2 = nts::Factory().createComponent("xor");
        std::shared_ptr<nts::IComponent> and1 = nts::Factory().createComponent("and");
        std::shared_ptr<nts::IComponent> and2 = nts::Factory().createComponent("and");
        std::shared_ptr<nts::IComponent> or1 = nts::Factory().createComponent("or");
        std::shared_ptr<nts::IComponent> split1 = nts::Factory().createComponent("splitter");
        std::shared_ptr<nts::IComponent> split2 = nts::Factory().createComponent("splitter");
        std::shared_ptr<nts::IComponent> split3 = nts::Factory().createComponent("splitter");

        _circuit_isInput.push_back(1);
        _circuit_isInput.push_back(2);
        _circuit_isInput.push_back(3);

        _circuit_isOutput.push_back(4);
        _circuit_isOutput.push_back(5);

        _circuit_links[1] = {split1, 1};
        _circuit_links[2] = {split2, 1};
        _circuit_links[3] = {split3, 1};

        _circuit_links[4] = {xor2, 3};
        _circuit_links[5] = {or1, 3};

        _circuit_components.push_back(xor1);
        _circuit_components.push_back(and1);
        _circuit_components.push_back(and2);

        split1->setLink(2, *xor1, 1);
        split1->setLink(2, *and2, 1);
        split2->setLink(2, *xor1, 2);
        split2->setLink(2, *and2, 2);
        split3->setLink(2, *xor2, 2);
        split3->setLink(2, *and1, 2);
        xor1->setLink(3, *xor2, 1);
        xor1->setLink(3, *and1, 1);
        and1->setLink(3, *or1, 1);
        and2->setLink(3, *or1, 2);
    }

    void FullAdderComponent::simulate(std::size_t tick)
    {
        if (_circuit_tick == tick)
            return;
        _circuit_tick = tick;
    }

    nts::state FullAdderComponent::compute(size_t pin)
    {
        return _circuit_links[pin].first->compute(_circuit_links[pin].second);
    }

}
