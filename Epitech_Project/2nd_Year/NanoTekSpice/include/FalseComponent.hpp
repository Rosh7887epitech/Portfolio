/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-titouan.bouillot-bachelier
** File description:
** FalseComponent
*/

#pragma once

#include "AComponent.hpp"

namespace nts
{
    class FalseComponent : public AComponent
    {
        public:
            FalseComponent();
            ~FalseComponent() = default;
            void simulate(std::size_t tick) override;
            nts::state compute(size_t pin) override;
    };
}
