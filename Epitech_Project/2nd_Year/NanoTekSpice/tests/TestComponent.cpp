/*
** EPITECH PROJECT, 2025
** Project
** File description:
** TestComponent
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Factory.hpp"
#include "AComponent.hpp"
#include "IComponent.hpp"

Test(FourAndComponent, testFourAndComponent)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4081");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 1);
    input2->setLink(1, *gate, 2);
    gate->setLink(3, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::FALSE);
}

Test(FourAndComponet, testFourAndComponet_2_false)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4081");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 1);
    input2->setLink(1, *gate, 2);
    gate->setLink(3, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::FALSE);
}

Test(FourAndComponet, testFourAndComponet_2_true)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4081");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 1);
    input2->setLink(1, *gate, 2);
    gate->setLink(3, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::TRUE);
}

Test(FourAndComponet, testFourAndComponet_1_Undefined_1_True)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4081");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 1);
    gate->setLink(3, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::UNDEFINED);
}

Test(FourAndComponet, testFourAndComponet_1_Undefined_1_False)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4081");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 1);
    gate->setLink(3, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::FALSE);
}

Test(FourAndComponent, testFourAndComponent2)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4081");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 5);
    input2->setLink(1, *gate, 6);
    gate->setLink(4, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::FALSE);
}

Test(FourAndComponet, testFourAndComponet_2_false2)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4081");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 5);
    input2->setLink(1, *gate, 6);
    gate->setLink(4, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::FALSE);
}

Test(FourAndComponet, testFourAndComponet_2_true2)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4081");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 5);
    input2->setLink(1, *gate, 6);
    gate->setLink(4, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::TRUE);
}

Test(FourAndComponet, testFourAndComponet_1_Undefined_1_True2)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4081");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 5);
    gate->setLink(4, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::UNDEFINED);
}

Test(FourAndComponet, testFourAndComponet_1_Undefined_1_False2)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4081");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 5);
    gate->setLink(4, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::FALSE);
}

Test(FourAndComponent, testFourAndComponent3)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4081");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 8);
    input2->setLink(1, *gate, 9);
    gate->setLink(10, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::FALSE);
}

Test(FourAndComponet, testFourAndComponet_2_false3)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4081");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 8);
    input2->setLink(1, *gate, 9);
    gate->setLink(10, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::FALSE);
}

Test(FourAndComponet, testFourAndComponet_2_true3)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4081");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 8);
    input2->setLink(1, *gate, 9);
    gate->setLink(10, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::TRUE);
}

Test(FourAndComponet, testFourAndComponet_1_Undefined_1_True3)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4081");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 8);
    gate->setLink(10, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::UNDEFINED);
}

Test(FourAndComponet, testFourAndComponet_1_Undefined_1_False3)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4081");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 8);
    gate->setLink(10, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::FALSE);
}

Test(FourAndComponent, testFourAndComponent4)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4081");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 12);
    input2->setLink(1, *gate, 13);
    gate->setLink(11, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::FALSE);
}

Test(FourAndComponet, testFourAndComponet_2_false4)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4081");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 12);
    input2->setLink(1, *gate, 13);
    gate->setLink(11, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::FALSE);
}

Test(FourAndComponet, testFourAndComponet_2_true4)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4081");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 12);
    input2->setLink(1, *gate, 13);
    gate->setLink(11, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::TRUE);
}

Test(FourAndComponet, testFourAndComponet_1_Undefined_1_True4)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4081");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 12);
    gate->setLink(11, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::UNDEFINED);
}

Test(FourAndComponet, testFourAndComponet_1_Undefined_1_False4)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> gate = nts::Factory().createComponent("4081");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input1->setLink(1, *gate, 12);
    gate->setLink(11, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::FALSE);
}
