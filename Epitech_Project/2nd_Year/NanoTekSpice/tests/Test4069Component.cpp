/*
** EPITECH PROJECT, 2025
** Project
** File description:
** TestSixNotComponent
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Factory.hpp"
#include "AComponent.hpp"
#include "IComponent.hpp"

Test(SixNotComponent, testSixNotComponent)
{
    std::shared_ptr<nts::IComponent> input = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4069");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input->setLink(1, *gate, 1);
    gate->setLink(2, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::FALSE);
}

Test(SixNotComponent, testSixNotComponent_false)
{
    std::shared_ptr<nts::IComponent> input = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4069");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input->setLink(1, *gate, 1);
    gate->setLink(2, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::TRUE);
}

Test(SixNotComponent, testSixNotComponent_undefined)
{
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4069");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    gate->setLink(2, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::UNDEFINED);
}

Test(SixNotComponent, testSixNotComponent2)
{
    std::shared_ptr<nts::IComponent> input = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4069");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input->setLink(1, *gate, 3);
    gate->setLink(4, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::FALSE);
}

Test(SixNotComponent, testSixNotComponent_false2)
{
    std::shared_ptr<nts::IComponent> input = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4069");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input->setLink(1, *gate, 3);
    gate->setLink(4, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::TRUE);
}

Test(SixNotComponent, testSixNotComponent_undefined2)
{
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4069");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    gate->setLink(2, *out, 4);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::UNDEFINED);
}

Test(SixNotComponent, testSixNotComponent3)
{
    std::shared_ptr<nts::IComponent> input = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4069");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input->setLink(1, *gate, 5);
    gate->setLink(6, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::FALSE);
}

Test(SixNotComponent, testSixNotComponent_false3)
{
    std::shared_ptr<nts::IComponent> input = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4069");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input->setLink(1, *gate, 5);
    gate->setLink(6, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::TRUE);
}

Test(SixNotComponent, testSixNotComponent_undefined3)
{
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4069");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    gate->setLink(2, *out, 5);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::UNDEFINED);
}

Test(SixNotComponent, testSixNotComponent4)
{
    std::shared_ptr<nts::IComponent> input = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4069");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input->setLink(1, *gate, 9);
    gate->setLink(8, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::FALSE);
}

Test(SixNotComponent, testSixNotComponent_false4)
{
    std::shared_ptr<nts::IComponent> input = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4069");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input->setLink(1, *gate, 9);
    gate->setLink(8, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::TRUE);
}

Test(SixNotComponent, testSixNotComponent_undefined4)
{
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4069");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    gate->setLink(2, *out, 9);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::UNDEFINED);
}

Test(SixNotComponent, testSixNotComponent5)
{
    std::shared_ptr<nts::IComponent> input = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4069");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input->setLink(1, *gate, 11);
    gate->setLink(10, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::FALSE);
}

Test(SixNotComponent, testSixNotComponent_false5)
{
    std::shared_ptr<nts::IComponent> input = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4069");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input->setLink(1, *gate, 11);
    gate->setLink(10, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::TRUE);
}

Test(SixNotComponent, testSixNotComponent_undefined5)
{
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4069");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    gate->setLink(2, *out, 11);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::UNDEFINED);
}

Test(SixNotComponent, testSixNotComponent6)
{
    std::shared_ptr<nts::IComponent> input = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4069");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input->setLink(1, *gate, 13);
    gate->setLink(12, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::FALSE);
}

Test(SixNotComponent, testSixNotComponent_false6)
{
    std::shared_ptr<nts::IComponent> input = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4069");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input->setLink(1, *gate, 13);
    gate->setLink(12, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::TRUE);
}

Test(SixNotComponent, testSixNotComponent_undefined6)
{
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4069");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    gate->setLink(2, *out, 13);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::UNDEFINED);
}
