/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-titouan.bouillot-bachelier
** File description:
** TestSplitter
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Factory.hpp"
#include "AComponent.hpp"
#include "IComponent.hpp"

Test(SplitterComponent, falseSplitterComponent)
{
    std::shared_ptr<nts::IComponent> input = nts::Factory().createComponent("false");
    std::shared_ptr<nts::IComponent> splitter = nts::Factory().createComponent("splitter");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input->setLink(1, *splitter, 1);
    splitter->setLink(2, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::FALSE);
}

Test(SplitterComponent, trueSplitterComponent)
{
    std::shared_ptr<nts::IComponent> input = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> splitter = nts::Factory().createComponent("splitter");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input->setLink(1, *splitter, 1);
    splitter->setLink(2, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::TRUE);
}

Test(SplitterComponent, undefinedSplitterComponent)
{
    std::shared_ptr<nts::IComponent> splitter = nts::Factory().createComponent("splitter");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    splitter->setLink(2, *out, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::UNDEFINED);
}

Test(SplitterComponent, unlinkedSplitterComponent2)
{
    std::shared_ptr<nts::IComponent> input = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> splitter = nts::Factory().createComponent("splitter");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input->setLink(1, *splitter, 1);
    out->simulate(1);

    cr_assert_eq(out->compute(1), nts::state::UNDEFINED);
}

Test(SplitterComponent, simSplitterComponent)
{
    std::shared_ptr<nts::IComponent> input = nts::Factory().createComponent("true");
    std::shared_ptr<nts::IComponent> splitter = nts::Factory().createComponent("splitter");
    std::shared_ptr<nts::IComponent> out = nts::Factory().createComponent("output");

    input->setLink(1, *splitter, 1);
    splitter->simulate(1);

    cr_assert_eq(splitter->compute(1), nts::state::TRUE);
}
