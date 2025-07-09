/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-titouan.bouillot-bachelier
** File description:
** 4011
*/

#pragma once

#include "ACircuit.hpp"

namespace nts
{
    class FourNandComponent : public ACircuit
    {
        public:
            FourNandComponent();
            ~FourNandComponent() override = default;
            void simulate(std::size_t tick) override;
            nts::state compute(size_t pin) override;
    };
}
