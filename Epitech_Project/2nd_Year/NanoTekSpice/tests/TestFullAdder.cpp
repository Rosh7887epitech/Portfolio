/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-titouan.bouillot-bachelier
** File description:
** TestFullAdder
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Factory.hpp"
#include "AComponent.hpp"
#include "IComponent.hpp"

Test(FullAdderComponent, test_f_f_f_FullAdderComponent)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input3 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> adder = nts::Factory().createComponent("adder");
    std::shared_ptr<nts::IComponent> out1 = nts::Factory().createComponent("output");
    std::shared_ptr<nts::IComponent> out2 = nts::Factory().createComponent("output");

    input1->setLink(1, *adder, 1);
    input2->setLink(1, *adder, 2);
    input3->setLink(1, *adder, 3);
    adder->setLink(4, *out1, 1);
    adder->setLink(5, *out2, 1);
    out1->simulate(1);
    out2->simulate(1);

    cr_assert_eq(out1->compute(1), nts::state::FALSE);
    cr_assert_eq(out2->compute(1), nts::state::FALSE);
}

Test(FullAdderComponent, test_f_f_t_FullAdderComponent)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input3 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> adder = nts::Factory().createComponent("adder");
    std::shared_ptr<nts::IComponent> out1 = nts::Factory().createComponent("output");
    std::shared_ptr<nts::IComponent> out2 = nts::Factory().createComponent("output");

    input1->setLink(1, *adder, 1);
    input2->setLink(1, *adder, 2);
    input3->setLink(1, *adder, 3);
    adder->setLink(4, *out1, 1);
    adder->setLink(5, *out2, 1);
    out1->simulate(1);
    out2->simulate(1);

    cr_assert_eq(out1->compute(1), nts::state::TRUE);
    cr_assert_eq(out2->compute(1), nts::state::FALSE);
}

Test(FullAdderComponent, test_f_t_f_FullAdderComponent)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input3 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> adder = nts::Factory().createComponent("adder");
    std::shared_ptr<nts::IComponent> out1 = nts::Factory().createComponent("output");
    std::shared_ptr<nts::IComponent> out2 = nts::Factory().createComponent("output");

    input1->setLink(1, *adder, 1);
    input2->setLink(1, *adder, 2);
    input3->setLink(1, *adder, 3);
    adder->setLink(4, *out1, 1);
    adder->setLink(5, *out2, 1);
    out1->simulate(1);
    out2->simulate(1);

    cr_assert_eq(out1->compute(1), nts::state::TRUE);
    cr_assert_eq(out2->compute(1), nts::state::FALSE);
}

Test(FullAdderComponent, test_f_t_t_FullAdderComponent)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input3 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> adder = nts::Factory().createComponent("adder");
    std::shared_ptr<nts::IComponent> out1 = nts::Factory().createComponent("output");
    std::shared_ptr<nts::IComponent> out2 = nts::Factory().createComponent("output");

    input1->setLink(1, *adder, 1);
    input2->setLink(1, *adder, 2);
    input3->setLink(1, *adder, 3);
    adder->setLink(4, *out1, 1);
    adder->setLink(5, *out2, 1);
    out1->simulate(1);
    out2->simulate(1);

    cr_assert_eq(out1->compute(1), nts::state::FALSE);
    cr_assert_eq(out2->compute(1), nts::state::TRUE);
}

Test(FullAdderComponent, test_t_f_f_FullAdderComponent)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input3 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> adder = nts::Factory().createComponent("adder");
    std::shared_ptr<nts::IComponent> out1 = nts::Factory().createComponent("output");
    std::shared_ptr<nts::IComponent> out2 = nts::Factory().createComponent("output");

    input1->setLink(1, *adder, 1);
    input2->setLink(1, *adder, 2);
    input3->setLink(1, *adder, 3);
    adder->setLink(4, *out1, 1);
    adder->setLink(5, *out2, 1);
    out1->simulate(1);
    out2->simulate(1);

    cr_assert_eq(out1->compute(1), nts::state::TRUE);
    cr_assert_eq(out2->compute(1), nts::state::FALSE);
}

Test(FullAdderComponent, test_t_f_t_FullAdderComponent)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input3 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> adder = nts::Factory().createComponent("adder");
    std::shared_ptr<nts::IComponent> out1 = nts::Factory().createComponent("output");
    std::shared_ptr<nts::IComponent> out2 = nts::Factory().createComponent("output");

    input1->setLink(1, *adder, 1);
    input2->setLink(1, *adder, 2);
    input3->setLink(1, *adder, 3);
    adder->setLink(4, *out1, 1);
    adder->setLink(5, *out2, 1);
    out1->simulate(1);
    out2->simulate(1);

    cr_assert_eq(out1->compute(1), nts::state::FALSE);
    cr_assert_eq(out2->compute(1), nts::state::TRUE);
}

Test(FullAdderComponent, test_f_u_f_FullAdderComponent)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input3 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> adder = nts::Factory().createComponent("adder");
    std::shared_ptr<nts::IComponent> out1 = nts::Factory().createComponent("output");
    std::shared_ptr<nts::IComponent> out2 = nts::Factory().createComponent("output");

    input1->setLink(1, *adder, 1);
    input3->setLink(1, *adder, 3);
    adder->setLink(4, *out1, 1);
    adder->setLink(5, *out2, 1);
    out1->simulate(1);
    out2->simulate(1);

    cr_assert_eq(out1->compute(1), nts::state::UNDEFINED);
    cr_assert_eq(out2->compute(1), nts::state::FALSE);
}

Test(FullAdderComponent, test_t_u_f_FullAdderComponent)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input3 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> adder = nts::Factory().createComponent("adder");
    std::shared_ptr<nts::IComponent> out1 = nts::Factory().createComponent("output");
    std::shared_ptr<nts::IComponent> out2 = nts::Factory().createComponent("output");

    input1->setLink(1, *adder, 1);
    input3->setLink(1, *adder, 3);
    adder->setLink(4, *out1, 1);
    adder->setLink(5, *out2, 1);
    out1->simulate(1);
    out2->simulate(1);

    cr_assert_eq(out1->compute(1), nts::state::UNDEFINED);
    cr_assert_eq(out2->compute(1), nts::state::UNDEFINED);
}

Test(FullAdderComponent, test_t_t_t_FullAdderComponent)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input3 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> adder = nts::Factory().createComponent("adder");
    std::shared_ptr<nts::IComponent> out1 = nts::Factory().createComponent("output");
    std::shared_ptr<nts::IComponent> out2 = nts::Factory().createComponent("output");

    input1->setLink(1, *adder, 1);
    input2->setLink(1, *adder, 2);
    input3->setLink(1, *adder, 3);
    adder->setLink(4, *out1, 1);
    adder->setLink(5, *out2, 1);
    out1->simulate(1);
    out2->simulate(1);

    cr_assert_eq(out1->compute(1), nts::state::TRUE);
    cr_assert_eq(out2->compute(1), nts::state::TRUE);
}
