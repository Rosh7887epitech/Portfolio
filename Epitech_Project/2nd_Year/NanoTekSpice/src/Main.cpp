/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-titouan.bouillot-bachelier
** File description:
** Main
*/

#include <iostream>
#include <string>
#include <map>
#include <csignal>
#include <algorithm>
#include "ACircuit.hpp"
#include "AComponent.hpp"
#include "Factory.hpp"
#include "Parse.hpp"

static bool loop = true;

std::ostream &operator<<(std::ostream &s, nts::state v)
{
    switch (v)
    {
        case nts::TRUE: s << "1"; break;
        case nts::FALSE: s << "0"; break;
        case nts::UNDEFINED: s << "U"; break;
    }
    return s;
}

void handle_sigint(int)
{
    loop = false;
}

int main(int ac, char **av)
{
    std::string input;
    class Parse parse;
    size_t tick = 0;
    std::map<std::string, std::shared_ptr<nts::IComponent>> components;
    std::map<std::string, std::shared_ptr<nts::IComponent>> outputs;
    size_t pos;
    std::string name;
    std::string value;

    if(ac != 2)
        return 84;
    parse.open_file(av[1], components);
    outputs = parse.get_map();
    while(1) {
        if (std::cin.eof())
            break;
        std::cout << "> ";
        std::getline(std::cin, input);
        input.erase(std::remove_if(input.begin(), input.end(), isspace), input.end());
        if (input == "exit")
            break;
        if (input == "simulate") {
            for (auto &component : parse.get_outputs()) {
                parse.get_map()[component]->simulate(tick);
            }
            tick++;
        }
        if (input == "display") {
            std::cout << "tick: " << tick << std::endl;
            std::cout << "input(s):\n";
            for (auto &input : parse.get_inputs()) {
                std::cout << "  " << input << ": ";
                std::cout << parse.get_map()[input]->compute(1) << std::endl;
            }
            std::cout << "output(s):\n";
            for (auto &output : parse.get_outputs()) {
                std::cout << "  " << output << ": ";
                std::cout << parse.get_map()[output]->compute(1) << std::endl;
            }
        }
        if (input == "loop") {
            signal(SIGINT, handle_sigint);
            while (loop) {
                for (auto &component : parse.get_outputs())
                    parse.get_map()[component]->simulate(tick);
                tick++;
                std::cout << "tick: " << tick << std::endl;
                std::cout << "input(s):\n";
                for (auto &input : parse.get_inputs()) {
                    std::cout << "  " << input << ": ";
                    std::cout << parse.get_map()[input]->compute(1) << std::endl;
                }
                std::cout << "output(s):\n";
                for (auto &output : parse.get_outputs()) {
                    std::cout << "  " << output << ": ";
                    std::cout << parse.get_map()[output]->compute(1) << std::endl;
                }
            }
        }
        loop = true;
        pos = input.find("=");
        if (pos != std::string::npos) {
            name = input.substr(0, pos);
            value = input.substr(pos + 1);
            for (auto &comp : parse.get_inputs()) {
                if (name == comp) {
                    parse.get_map()[comp]->setState(value);
                }
            }
        }
    }
}
