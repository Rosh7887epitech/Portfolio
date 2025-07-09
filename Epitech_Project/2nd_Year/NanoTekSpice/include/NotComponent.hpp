/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-titouan.bouillot-bachelier
** File description:
** NotComponent
*/

#pragma once

#include "AComponent.hpp"

namespace nts
{
    class NotComponent : public AComponent {
        public:
            NotComponent();
            ~NotComponent() = default;
            void simulate(std::size_t tick) override;
            nts::state compute(size_t pin) override;
    };
}
