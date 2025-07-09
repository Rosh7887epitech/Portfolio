/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-titouan.bouillot-bachelier
** File description:
** Factory
*/

#pragma once

#include "IComponent.hpp"
#include <map>
#include <functional>

namespace nts
{
    class Factory
    {
        public:
            Factory();
            ~Factory() = default;

            std::shared_ptr<IComponent> createComponent(const std::string &type);

        private:
            std::map<std::string, std::function<std::shared_ptr<IComponent>()>> _componentCreators;
    };
}
