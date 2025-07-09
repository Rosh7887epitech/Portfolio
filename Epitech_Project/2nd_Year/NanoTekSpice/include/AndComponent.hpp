/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-titouan.bouillot-bachelier
** File description:
** AndComponent
*/

#pragma once

#include "AComponent.hpp"

namespace nts
{
    class AndComponent : public AComponent
    {
        public:
            AndComponent();
            ~AndComponent() override = default;
            void simulate(std::size_t tick) override;
            nts::state compute(size_t pin) override;
    };
}
