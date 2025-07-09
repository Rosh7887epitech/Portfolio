/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-titouan.bouillot-bachelier
** File description:
** fullAdder
*/

#pragma once

#include "ACircuit.hpp"

namespace nts
{
    class FullAdderComponent : public ACircuit
    {
        public:
            FullAdderComponent();
            ~FullAdderComponent() override = default;
            void simulate(std::size_t tick) override;
            nts::state compute(size_t pin) override;
    };
}
