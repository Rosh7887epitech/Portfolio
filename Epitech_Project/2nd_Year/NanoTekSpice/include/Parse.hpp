/*
** EPITECH PROJECT, 2025
** Project
** File description:
** Parse
*/

#ifndef PARSE_HPP_
#define PARSE_HPP_

class Parse {
    public:
        void parse_links(const std::string &section, std::vector<std::tuple<std::string, std::string, std::string, std::string>> &links, std::map<std::string, std::shared_ptr<nts::IComponent>> &components);
        void parse_chipset(const std::string &section, std::map<std::string, std::shared_ptr<nts::IComponent>> &components);
        std::map<std::string, std::shared_ptr<nts::IComponent>> get_map();
        void open_file(const std::string &fileName, std::map<std::string, std::shared_ptr<nts::IComponent>> components);
        std::list<std::string> get_inputs();
        std::list<std::string> get_outputs();

    private:
        std::map<std::string, std::shared_ptr<nts::IComponent>> _comp;
        std::list<std::string> _trueAndFalse;
        std::list<std::string> _inputs;
        std::list<std::string> _outputs;
};

#endif /* !PARSE_HPP_ */
