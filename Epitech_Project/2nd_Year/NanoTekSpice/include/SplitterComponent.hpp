/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-titouan.bouillot-bachelier
** File description:
** SplitterComponent
*/

#pragma once

#include "AComponent.hpp"

namespace nts
{
    class SplitterComponent : public AComponent
    {
        public:
            SplitterComponent();
            ~SplitterComponent() override = default;
            void simulate(std::size_t tick) override;
            nts::state compute(std::size_t pin) override;
    };
}
