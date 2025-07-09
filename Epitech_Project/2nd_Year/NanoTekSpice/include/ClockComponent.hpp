/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-titouan.bouillot-bachelier
** File description:
** ClockComponent
*/

#include "AComponent.hpp"

#pragma once

namespace nts
{
    class ClockComponent : public AComponent
    {
        public:
            ClockComponent();
            ~ClockComponent() = default;
            void simulate(std::size_t tick) override;
            nts::state compute(size_t pin) override;
    };
}
