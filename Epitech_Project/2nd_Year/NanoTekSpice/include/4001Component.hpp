/*
** EPITECH PROJECT, 2025
** Project
** File description:
** 4001Component
*/

#pragma once

#include "ACircuit.hpp"

namespace nts
{
    class FourNorComponent : public ACircuit
    {
        public:
            FourNorComponent();
            ~FourNorComponent() override = default;
            void simulate(std::size_t tick) override;
            nts::state compute(size_t pin) override;
    };
}
