/*
** EPITECH PROJECT, 2025
** Project
** File description:
** Acircuit
*/

#pragma once

#include "IComponent.hpp"
#include <map>
#include <vector>
#include <memory>

namespace nts
{
    class ACircuit : public IComponent
    {
        public:
            ACircuit(std::string name);
            ~ACircuit() override = default;

            void simulate(std::size_t tick) override;
            virtual nts::state compute(size_t pin) = 0;

            void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) override;
            std::shared_ptr<nts::IComponent> getLink(std::size_t pin) const;
            bool getIsInput(std::size_t pin) const override;
            bool getIsOutput(std::size_t pin) const override;
            std::string getName() const override;
            bool getIsComponent() const override;
            void setState(std::string value) override;

        protected:
            std::string _circuit_name;
            bool _isComponent;
            std::map<std::size_t, std::pair<std::shared_ptr<nts::IComponent>, std::size_t>> _circuit_links;
            std::vector<std::shared_ptr<nts::IComponent>> _circuit_components;
            std::vector<std::size_t> _circuit_isInput;
            std::vector<std::size_t> _circuit_isOutput;
            std::map<std::size_t, nts::state> _circuit_states;
            std::size_t _circuit_tick;
    };
}
