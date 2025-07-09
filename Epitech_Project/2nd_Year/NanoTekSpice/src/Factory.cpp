/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-titouan.bouillot-bachelier
** File description:
** Factory
*/

#include "Factory.hpp"
#include "AndComponent.hpp"
#include "OrComponent.hpp"
#include "XorComponent.hpp"
#include "FalseComponent.hpp"
#include "TrueComponent.hpp"
#include "ClockComponent.hpp"
#include "NotComponent.hpp"
#include "NandComponent.hpp"
#include "NorComponent.hpp"
#include "OutputComponent.hpp"
#include "InputComponent.hpp"
#include "4081Component.hpp"
#include "4071Component.hpp"
#include "4030Component.hpp"
#include "4069Component.hpp"
#include "4011Component.hpp"
#include "4001Component.hpp"
#include "FullAdder.hpp"
#include "SplitterComponent.hpp"
#include "4008Component.hpp"

namespace nts
{
    Factory::Factory()
    {
        _componentCreators = {
            {"and", []() -> std::shared_ptr<IComponent> { return std::make_shared<AndComponent>(); }},
            {"or", []() -> std::shared_ptr<IComponent> { return std::make_shared<OrComponent>(); }},
            {"xor", []() -> std::shared_ptr<IComponent> { return std::make_shared<XorComponent>(); }},
            {"false", []() -> std::shared_ptr<IComponent> { return std::make_shared<FalseComponent>(); }},
            {"true", []() -> std::shared_ptr<IComponent> { return std::make_shared<TrueComponent>(); }},
            {"not", []() -> std::shared_ptr<IComponent> { return std::make_shared<NotComponent>(); }},
            {"clock", []() -> std::shared_ptr<IComponent> { return std::make_shared<ClockComponent>(); }},
            {"nand", []() -> std::shared_ptr<IComponent> { return std::make_shared<NandComponent>(); }},
            {"nor", []() -> std::shared_ptr<IComponent> { return std::make_shared<NorComponent>(); }},
            {"output", []() -> std::shared_ptr<IComponent> { return std::make_shared<OutputComponent>(); }},
            {"input", []() -> std::shared_ptr<IComponent> { return std::make_shared<InputComponent>(); }},
            {"4081", []() -> std::shared_ptr<IComponent> { return std::make_shared<FourAndComponent>(); }},
            {"4071", []() -> std::shared_ptr<IComponent> { return std::make_shared<FourOrComponent>(); }},
            {"4030", []() -> std::shared_ptr<IComponent> { return std::make_shared<FourXorComponent>(); }},
            {"4011", []() -> std::shared_ptr<IComponent> { return std::make_shared<FourNandComponent>(); }},
            {"4001", []() -> std::shared_ptr<IComponent> { return std::make_shared<FourNorComponent>(); }},
            {"4069", []() -> std::shared_ptr<IComponent> { return std::make_shared<SixNotComponent>(); }},
            {"adder", []() -> std::shared_ptr<IComponent> { return std::make_shared<FullAdderComponent>(); }},
            {"splitter", []() -> std::shared_ptr<IComponent> { return std::make_shared<SplitterComponent>(); }},
            {"4008", []() -> std::shared_ptr<IComponent> { return std::make_shared<FourBitAdder>(); }}
        };
    }

    std::shared_ptr<IComponent> Factory::createComponent(const std::string &type)
    {
        auto it = _componentCreators.find(type);
        if (it != _componentCreators.end()) {
            return it->second();
        }
        return nullptr;
    }
}
