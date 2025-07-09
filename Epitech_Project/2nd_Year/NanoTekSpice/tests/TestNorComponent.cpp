/*
** EPITECH PROJECT, 2025
** Project
** File description:
** TestNorComponent
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Factory.hpp"
#include "AComponent.hpp"
#include "IComponent.hpp"

Test(NorComponent, testNorComponent)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("nor");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 1);
    input2->setLink(1, *gate, 2);
    gate->setLink(3, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::FALSE);
}

Test(NorComponent, testNorComponent_2_false)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("nor");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 1);
    input2->setLink(1, *gate, 2);
    gate->setLink(3, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::TRUE);
}

Test(NorComponent, testNorComponent_2_true)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("nor");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 1);
    input2->setLink(1, *gate, 2);
    gate->setLink(3, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::FALSE);
}

Test(NorComponent, testNorComponent_1_True_1_Undefined)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("nor");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 1);
    gate->setLink(3, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::FALSE);
}

Test(NorComponent, testNorComponent_1_False_1_Undefined)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("nor");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 1);
    gate->setLink(3, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::UNDEFINED);
}
