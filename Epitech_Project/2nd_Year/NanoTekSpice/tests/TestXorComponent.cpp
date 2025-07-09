/*
** EPITECH PROJECT, 2025
** Project
** File description:
** TestTrueComponent
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Factory.hpp"
#include "AComponent.hpp"
#include "IComponent.hpp"

Test(XorComponent, testXorComponent)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("xor");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 1);
    input2->setLink(1, *gate, 2);
    gate->setLink(3, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::TRUE);
}


Test(XorComponent, testXorComponent_2_false)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("xor");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 1);
    input2->setLink(1, *gate, 2);
    gate->setLink(3, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::FALSE);
}

Test(XorComponent, testXorComponent_2_true)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("xor");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 1);
    input2->setLink(1, *gate, 2);
    gate->setLink(3, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::FALSE);
}

Test(XorComponent, testXorComponent_1_Undefined_1_True)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("xor");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 1);
    gate->setLink(3, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::UNDEFINED);
}

Test(XorComponent, testXorComponent_1_Undefined_1_False)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("xor");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 1);
    gate->setLink(3, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::UNDEFINED);
}
