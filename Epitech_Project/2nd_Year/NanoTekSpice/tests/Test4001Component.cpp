/*
** EPITECH PROJECT, 2025
** Project
** File description:
** TestFourNorComponent
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Factory.hpp"
#include "AComponent.hpp"
#include "IComponent.hpp"

Test(FourNorComponent, testFourNorComponent)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4001");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 1);
    input2->setLink(1, *gate, 2);
    gate->setLink(3, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::FALSE);
}

Test(FourNorComponent, testFourNorComponent_2_false)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4001");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 1);
    input2->setLink(1, *gate, 2);
    gate->setLink(3, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::TRUE);
}

Test(FourNorComponent, testFourNorComponent_2_true)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4001");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 1);
    input2->setLink(1, *gate, 2);
    gate->setLink(3, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::FALSE);
}

Test(FourNorComponent, testFourNorComponent_1_True_1_Undefined)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4001");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 1);
    gate->setLink(3, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::FALSE);
}

Test(FourNorComponent, testFourNorComponent_1_False_1_Undefined)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4001");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 1);
    gate->setLink(3, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::UNDEFINED);
}

Test(FourNorComponent, testFourNorComponent2)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4001");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 5);
    input2->setLink(1, *gate, 6);
    gate->setLink(4, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::FALSE);
}

Test(FourNorComponent, testFourNorComponent_2_false2)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4001");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 5);
    input2->setLink(1, *gate, 6);
    gate->setLink(4, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::TRUE);
}

Test(FourNorComponent, testFourNorComponent_2_true2)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4001");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 5);
    input2->setLink(1, *gate, 6);
    gate->setLink(4, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::FALSE);
}

Test(FourNorComponent, testFourNorComponent_1_True_1_Undefined2)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4001");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 5);
    gate->setLink(4, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::FALSE);
}

Test(FourNorComponent, testFourNorComponent_1_False_1_Undefined2)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4001");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 5);
    gate->setLink(4, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::UNDEFINED);
}

Test(FourNorComponent, testFourNorComponent3)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4001");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 8);
    input2->setLink(1, *gate, 9);
    gate->setLink(10, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::FALSE);
}

Test(FourNorComponent, testFourNorComponent_2_false3)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4001");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 8);
    input2->setLink(1, *gate, 9);
    gate->setLink(10, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::TRUE);
}

Test(FourNorComponent, testFourNorComponent_2_true3)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4001");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 8);
    input2->setLink(1, *gate, 9);
    gate->setLink(10, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::FALSE);
}

Test(FourNorComponent, testFourNorComponent_1_True_1_Undefined3)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4001");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 8);
    gate->setLink(10, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::FALSE);
}

Test(FourNorComponent, testFourNorComponent_1_False_1_Undefined3)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4001");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 8);
    gate->setLink(10, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::UNDEFINED);
}

Test(FourNorComponent, testFourNorComponent4)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4001");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 12);
    input2->setLink(1, *gate, 13);
    gate->setLink(11, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::FALSE);
}

Test(FourNorComponent, testFourNorComponent_2_false4)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4001");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 12);
    input2->setLink(1, *gate, 13);
    gate->setLink(11, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::TRUE);
}

Test(FourNorComponent, testFourNorComponent_2_true4)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4001");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 12);
    input2->setLink(1, *gate, 13);
    gate->setLink(11, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::FALSE);
}

Test(FourNorComponent, testFourNorComponent_1_True_1_Undefined4)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4001");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 12);
    gate->setLink(11, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::FALSE);
}

Test(FourNorComponent, testFourNorComponent_1_False_1_Undefined4)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4001");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 12);
    gate->setLink(11, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::UNDEFINED);
}
