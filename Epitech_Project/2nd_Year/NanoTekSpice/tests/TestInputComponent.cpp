/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-titouan.bouillot-bachelier
** File description:
** TestInputComponent
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Factory.hpp"
#include "AComponent.hpp"
#include "IComponent.hpp"

Test(InputComponent, test_true_InputComponent)
{
    std::shared_ptr<nts::IComponent> input = nts::Factory().createComponent("input");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");
    std::string value = "1";

    input->setLink(1, *out, 1);
    input->setState(value);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::TRUE);
}

Test(InputComponent, test_false_InputComponent)
{
    std::shared_ptr<nts::IComponent> input = nts::Factory().createComponent("input");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");
    std::string value = "0";

    input->setLink(1, *out, 1);
    input->setState(value);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::FALSE);
}

Test(InputComponent, test_undefined_InputComponent)
{
    std::shared_ptr<nts::IComponent> input = nts::Factory().createComponent("input");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");
    std::string value = "U";

    input->setLink(1, *out, 1);
    input->setState(value);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::UNDEFINED);
}

Test(InputComponent, test_unlinked_InputComponent)
{
    std::shared_ptr<nts::IComponent> input = nts::Factory().createComponent("input");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");
    std::string value = "1";

    input->setState(value);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::UNDEFINED);
}

Test(InputComponent, test_sim_InputComponent)
{
    std::shared_ptr<nts::IComponent> input = nts::Factory().createComponent("input");
    std::string value = "1";

    input->setState(value);
    input->simulate(1);

    cr_assert_eq(input->compute(1), nts::state::TRUE);
}

Test(ClockComponent, test_true_ClockComponent)
{
    std::shared_ptr<nts::IComponent> input = nts::Factory().createComponent("clock");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");
    std::string value = "1";

    input->setLink(1, *out, 1);
    input->setState(value);
    out->simulate(1);
    cr_assert_eq(out->compute(1), nts::state::TRUE);
    out->simulate(2);
    cr_assert_eq(out->compute(1), nts::state::FALSE);
}

Test(ClockComponent, test_false_ClockComponent)
{
    std::shared_ptr<nts::IComponent> input = nts::Factory().createComponent("clock");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");
    std::string value = "0";

    input->setLink(1, *out, 1);
    input->setState(value);
    out->simulate(1);
    cr_assert_eq(out->compute(1), nts::state::FALSE);
    out->simulate(2);
    cr_assert_eq(out->compute(1), nts::state::TRUE);
}

Test(ClockComponent, test_undefined_ClockComponent)
{
    std::shared_ptr<nts::IComponent> input = nts::Factory().createComponent("clock");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");
    std::string value = "U";

    input->setLink(1, *out, 1);
    input->setState(value);
    out->simulate(1);
    cr_assert_eq(out->compute(1), nts::state::UNDEFINED);
    out->simulate(2);
    cr_assert_eq(out->compute(1), nts::state::UNDEFINED);
}

Test(ClockComponent, test_unset_undefined_ClockComponent)
{
    std::shared_ptr<nts::IComponent> input = nts::Factory().createComponent("clock");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input->setLink(1, *out, 1);
    out->simulate(1);
    cr_assert_eq(out->compute(1), nts::state::UNDEFINED);
    out->simulate(2);
    cr_assert_eq(out->compute(1), nts::state::UNDEFINED);
}

Test(ClockComponent, test_unlinked_ClockComponent)
{
    std::shared_ptr<nts::IComponent> input = nts::Factory().createComponent("clock");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");
    std::string value = "1";

    input->setState(value);
    out->simulate(1);
    cr_assert_eq(out->compute(1), nts::state::UNDEFINED);
    out->simulate(2);
    cr_assert_eq(out->compute(1), nts::state::UNDEFINED);
}

Test(ClockComponent, test_sim_ClockComponent)
{
    std::shared_ptr<nts::IComponent> input = nts::Factory().createComponent("clock");
    std::string value = "1";

    input->setState(value);
    input->simulate(1);
    cr_assert_eq(input->compute(1), nts::state::TRUE);
    input->simulate(2);
    cr_assert_eq(input->compute(1), nts::state::FALSE);
}
