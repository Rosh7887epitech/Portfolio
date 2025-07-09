/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-titouan.bouillot-bachelier
** File description:
** IComponent
*/

#pragma once

#include <iostream>
#include <memory>

namespace nts
{
    enum state
    {
        UNDEFINED = -1,
        TRUE = true,
        FALSE = false
    };

    class IComponent
    {
        public:
            virtual ~IComponent() = default;

            virtual void simulate(std::size_t tick) = 0;
            virtual nts::state compute(size_t pin) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &input, std::size_t inputPin) = 0;
            virtual std::shared_ptr<nts::IComponent> getLink(std::size_t pin) const = 0;
            virtual bool getIsInput(std::size_t pin) const = 0;
            virtual bool getIsOutput(std::size_t pin) const = 0;
            virtual std::string getName() const = 0;
            virtual bool getIsComponent() const = 0;
            virtual void setState(std::string value) = 0;
    };
}
