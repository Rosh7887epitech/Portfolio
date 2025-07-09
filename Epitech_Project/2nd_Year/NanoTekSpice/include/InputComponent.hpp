/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-titouan.bouillot-bachelier
** File description:
** InputComponent
*/

#pragma once

#include "AComponent.hpp"

namespace nts
{
    class InputComponent : public AComponent
    {
        public:
            InputComponent();
            ~InputComponent() override = default;
            void simulate(std::size_t tick) override;
            nts::state compute(std::size_t pin) override;
    };
}
