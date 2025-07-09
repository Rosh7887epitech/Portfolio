/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-titouan.bouillot-bachelier
** File description:
** AComponent
*/

#pragma once

#include "IComponent.hpp"
#include <map>
#include <vector>
#include <memory>
#include <list>

namespace nts
{

    class AComponent : public IComponent
    {
        public:
            AComponent(std::string name);
            ~AComponent() override = default;

            void simulate(std::size_t tick) override;
            virtual nts::state compute(size_t pin) = 0;

            void setLink(std::size_t pin, nts::IComponent &input, std::size_t inputPin) override;
            std::shared_ptr<nts::IComponent> getLink(std::size_t pin) const;
            bool getIsInput(std::size_t pin) const override;
            bool getIsOutput(std::size_t pin) const override;
            std::string getName() const override;
            bool getIsComponent() const override;
            void setState(std::string value) override;

        protected:
            std::string _name;
            std::size_t _tick;
            bool _isComponent;
            nts::state _value;
            nts::state _old_value;
            std::vector<std::size_t> isInput;
            std::vector<std::size_t> isOutput;
            std::map<std::size_t, nts::state> _states;
            std::map<std::size_t, std::pair<std::shared_ptr<nts::IComponent>, std::size_t>> _links;
    };

}
