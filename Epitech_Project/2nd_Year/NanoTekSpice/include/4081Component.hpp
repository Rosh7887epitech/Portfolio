/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-titouan.bouillot-bachelier
** File description:
** 4081
*/

#pragma once

#include "ACircuit.hpp"

namespace nts
{
    class FourAndComponent : public ACircuit
    {
        public:
            FourAndComponent();
            ~FourAndComponent() override = default;
            void simulate(std::size_t tick) override;
            nts::state compute(size_t pin) override;
    };
}
