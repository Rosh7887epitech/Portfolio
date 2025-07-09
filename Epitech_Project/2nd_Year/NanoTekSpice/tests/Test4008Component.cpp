/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-titouan.bouillot-bachelier
** File description:
** Test4008Component
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Factory.hpp"
#include "AComponent.hpp"
#include "IComponent.hpp"

Test(FourBitAdderComponent, test_False_40008Component)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input3 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input4 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input5 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input6 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input7 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input8 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input9 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> adder = nts::Factory().createComponent("4008");
    std::shared_ptr<nts::IComponent> out1 = nts::Factory().createComponent("output");
    std::shared_ptr<nts::IComponent> out2 = nts::Factory().createComponent("output");
    std::shared_ptr<nts::IComponent> out3 = nts::Factory().createComponent("output");
    std::shared_ptr<nts::IComponent> out4 = nts::Factory().createComponent("output");
    std::shared_ptr<nts::IComponent> out5 = nts::Factory().createComponent("output");

    input1->setLink(1, *adder, 15);
    input2->setLink(1, *adder, 1);
    input3->setLink(1, *adder, 2);
    input4->setLink(1, *adder, 3);
    input5->setLink(1, *adder, 4);
    input6->setLink(1, *adder, 5);
    input7->setLink(1, *adder, 6);
    input8->setLink(1, *adder, 7);
    input9->setLink(1, *adder, 9);
    adder->setLink(10, *out1, 1);
    adder->setLink(11, *out2, 1);
    adder->setLink(12, *out3, 1);
    adder->setLink(13, *out4, 1);
    adder->setLink(14, *out5, 1);

    out1->simulate(1);
    out2->simulate(1);
    out3->simulate(1);
    out4->simulate(1);
    out5->simulate(1);

    cr_assert_eq(out1->compute(1), nts::state::FALSE);
    cr_assert_eq(out2->compute(1), nts::state::FALSE);
    cr_assert_eq(out3->compute(1), nts::state::FALSE);
    cr_assert_eq(out4->compute(1), nts::state::FALSE);
    cr_assert_eq(out5->compute(1), nts::state::FALSE);
}

Test(FourBitAdderComponent, test_True_40008Component)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input3 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input4 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input5 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input6 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input7 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input8 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input9 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> adder = nts::Factory().createComponent("4008");
    std::shared_ptr<nts::IComponent> out1 = nts::Factory().createComponent("output");
    std::shared_ptr<nts::IComponent> out2 = nts::Factory().createComponent("output");
    std::shared_ptr<nts::IComponent> out3 = nts::Factory().createComponent("output");
    std::shared_ptr<nts::IComponent> out4 = nts::Factory().createComponent("output");
    std::shared_ptr<nts::IComponent> out5 = nts::Factory().createComponent("output");

    input1->setLink(1, *adder, 15);
    input2->setLink(1, *adder, 1);
    input3->setLink(1, *adder, 2);
    input4->setLink(1, *adder, 3);
    input5->setLink(1, *adder, 4);
    input6->setLink(1, *adder, 5);
    input7->setLink(1, *adder, 6);
    input8->setLink(1, *adder, 7);
    input9->setLink(1, *adder, 9);
    adder->setLink(10, *out1, 1);
    adder->setLink(11, *out2, 1);
    adder->setLink(12, *out3, 1);
    adder->setLink(13, *out4, 1);
    adder->setLink(14, *out5, 1);

    out1->simulate(1);
    out2->simulate(1);
    out3->simulate(1);
    out4->simulate(1);
    out5->simulate(1);

    cr_assert_eq(out1->compute(1), nts::state::TRUE);
    cr_assert_eq(out2->compute(1), nts::state::TRUE);
    cr_assert_eq(out3->compute(1), nts::state::TRUE);
    cr_assert_eq(out4->compute(1), nts::state::TRUE);
    cr_assert_eq(out5->compute(1), nts::state::TRUE);
}

Test(FourBitAdderComponent, test_1false_40008Component)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input3 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input4 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input5 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input6 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input7 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input8 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input9 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> adder = nts::Factory().createComponent("4008");
    std::shared_ptr<nts::IComponent> out1 = nts::Factory().createComponent("output");
    std::shared_ptr<nts::IComponent> out2 = nts::Factory().createComponent("output");
    std::shared_ptr<nts::IComponent> out3 = nts::Factory().createComponent("output");
    std::shared_ptr<nts::IComponent> out4 = nts::Factory().createComponent("output");
    std::shared_ptr<nts::IComponent> out5 = nts::Factory().createComponent("output");

    input1->setLink(1, *adder, 15);
    input2->setLink(1, *adder, 1);
    input3->setLink(1, *adder, 2);
    input4->setLink(1, *adder, 3);
    input5->setLink(1, *adder, 4);
    input6->setLink(1, *adder, 5);
    input7->setLink(1, *adder, 6);
    input8->setLink(1, *adder, 7);
    input9->setLink(1, *adder, 9);
    adder->setLink(10, *out1, 1);
    adder->setLink(11, *out2, 1);
    adder->setLink(12, *out3, 1);
    adder->setLink(13, *out4, 1);
    adder->setLink(14, *out5, 1);

    out1->simulate(1);
    out2->simulate(1);
    out3->simulate(1);
    out4->simulate(1);
    out5->simulate(1);

    cr_assert_eq(out1->compute(1), nts::state::FALSE);
    cr_assert_eq(out2->compute(1), nts::state::TRUE);
    cr_assert_eq(out3->compute(1), nts::state::TRUE);
    cr_assert_eq(out4->compute(1), nts::state::TRUE);
    cr_assert_eq(out5->compute(1), nts::state::TRUE);
}

Test(FourBitAdderComponent, test_multi_40008Component)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input3 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input4 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input5 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input6 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input7 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input8 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input9 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> adder = nts::Factory().createComponent("4008");
    std::shared_ptr<nts::IComponent> out1 = nts::Factory().createComponent("output");
    std::shared_ptr<nts::IComponent> out2 = nts::Factory().createComponent("output");
    std::shared_ptr<nts::IComponent> out3 = nts::Factory().createComponent("output");
    std::shared_ptr<nts::IComponent> out4 = nts::Factory().createComponent("output");
    std::shared_ptr<nts::IComponent> out5 = nts::Factory().createComponent("output");

    input1->setLink(1, *adder, 15);
    input2->setLink(1, *adder, 1);
    input3->setLink(1, *adder, 2);
    input4->setLink(1, *adder, 3);
    input5->setLink(1, *adder, 4);
    input6->setLink(1, *adder, 5);
    input7->setLink(1, *adder, 6);
    input8->setLink(1, *adder, 7);
    input9->setLink(1, *adder, 9);
    adder->setLink(10, *out1, 1);
    adder->setLink(11, *out2, 1);
    adder->setLink(12, *out3, 1);
    adder->setLink(13, *out4, 1);
    adder->setLink(14, *out5, 1);

    out1->simulate(1);
    out2->simulate(1);
    out3->simulate(1);
    out4->simulate(1);
    out5->simulate(1);

    cr_assert_eq(out1->compute(1), nts::state::TRUE);
    cr_assert_eq(out2->compute(1), nts::state::TRUE);
    cr_assert_eq(out3->compute(1), nts::state::TRUE);
    cr_assert_eq(out4->compute(1), nts::state::TRUE);
    cr_assert_eq(out5->compute(1), nts::state::FALSE);
}

Test(FourBitAdderComponent, test_u1_40008Component)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input3 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input4 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input5 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input6 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input7 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input8 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> adder = nts::Factory().createComponent("4008");
    std::shared_ptr<nts::IComponent> out1 = nts::Factory().createComponent("output");
    std::shared_ptr<nts::IComponent> out2 = nts::Factory().createComponent("output");
    std::shared_ptr<nts::IComponent> out3 = nts::Factory().createComponent("output");
    std::shared_ptr<nts::IComponent> out4 = nts::Factory().createComponent("output");
    std::shared_ptr<nts::IComponent> out5 = nts::Factory().createComponent("output");

    input1->setLink(1, *adder, 15);
    input2->setLink(1, *adder, 1);
    input3->setLink(1, *adder, 2);
    input4->setLink(1, *adder, 3);
    input5->setLink(1, *adder, 4);
    input6->setLink(1, *adder, 5);
    input7->setLink(1, *adder, 6);
    input8->setLink(1, *adder, 7);
    adder->setLink(10, *out1, 1);
    adder->setLink(11, *out2, 1);
    adder->setLink(12, *out3, 1);
    adder->setLink(13, *out4, 1);
    adder->setLink(14, *out5, 1);

    out1->simulate(1);
    out2->simulate(1);
    out3->simulate(1);
    out4->simulate(1);
    out5->simulate(1);

    cr_assert_eq(out1->compute(1), nts::state::UNDEFINED);
    cr_assert_eq(out2->compute(1), nts::state::UNDEFINED);
    cr_assert_eq(out3->compute(1), nts::state::UNDEFINED);
    cr_assert_eq(out4->compute(1), nts::state::UNDEFINED);
    cr_assert_eq(out5->compute(1), nts::state::UNDEFINED);
}

Test(FourBitAdderComponent, test_u2_40008Component)
{
    std::shared_ptr<nts::IComponent> input1 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input2 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input3 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input4 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input5 = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> input6 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input8 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> input9 = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> adder = nts::Factory().createComponent("4008");
    std::shared_ptr<nts::IComponent> out1 = nts::Factory().createComponent("output");
    std::shared_ptr<nts::IComponent> out2 = nts::Factory().createComponent("output");
    std::shared_ptr<nts::IComponent> out3 = nts::Factory().createComponent("output");
    std::shared_ptr<nts::IComponent> out4 = nts::Factory().createComponent("output");
    std::shared_ptr<nts::IComponent> out5 = nts::Factory().createComponent("output");

    input1->setLink(1, *adder, 15);
    input2->setLink(1, *adder, 1);
    input3->setLink(1, *adder, 2);
    input4->setLink(1, *adder, 3);
    input5->setLink(1, *adder, 4);
    input6->setLink(1, *adder, 5);
    input8->setLink(1, *adder, 7);
    input9->setLink(1, *adder, 9);
    adder->setLink(10, *out1, 1);
    adder->setLink(11, *out2, 1);
    adder->setLink(12, *out3, 1);
    adder->setLink(13, *out4, 1);
    adder->setLink(14, *out5, 1);

    out1->simulate(1);
    out2->simulate(1);
    out3->simulate(1);
    out4->simulate(1);
    out5->simulate(1);

    cr_assert_eq(out1->compute(1), nts::state::UNDEFINED);
    cr_assert_eq(out2->compute(1), nts::state::TRUE);
    cr_assert_eq(out3->compute(1), nts::state::TRUE);
    cr_assert_eq(out4->compute(1), nts::state::TRUE);
    cr_assert_eq(out5->compute(1), nts::state::FALSE);
}
