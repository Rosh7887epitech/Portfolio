/*
** EPITECH PROJECT, 2025
** Project
** File description:
** TestNotComponent
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Factory.hpp"
#include "AComponent.hpp"
#include "IComponent.hpp"

Test(NotComponent, testNotComponent)
{
    std::shared_ptr<nts::IComponent> input = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("not");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input->setLink(1, *gate, 1);
    gate->setLink(2, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::FALSE);
}

Test(NotComponent, testNotComponent_false)
{
    std::shared_ptr<nts::IComponent> input = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("not");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input->setLink(1, *gate, 1);
    gate->setLink(2, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::TRUE);
}

Test(NotComponent, testNotComponent_undefined)
{
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("not");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    gate->setLink(2, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::UNDEFINED);
}
