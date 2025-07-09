/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-titouan.bouillot-bachelier
** File description:
** TestParse
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Factory.hpp"
#include "AComponent.hpp"
#include "IComponent.hpp"
#include "Parse.hpp"

Test(Parse, parse_chipset)
{
    std::string file = ".chipsets\ninput in\noutput out\ntrue true\nfalse false\n";
    std::map<std::string, std::shared_ptr<nts::IComponent>> components;
    Parse parse;
    parse.parse_chipset(file, components);
    cr_assert_eq(components.size(), 4);
}
