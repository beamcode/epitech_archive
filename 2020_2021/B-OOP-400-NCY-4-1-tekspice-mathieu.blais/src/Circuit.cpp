/*
** EPITECH PROJECT, 2021
** Circuit.cpp
** File description:
** Circuit class file
*/

#include "Circuit.hpp"

Circuit::Circuit()
{
    this->tickNumber = 0;
    this->call.insert(mapCall::value_type("input", createInput));
    this->call.insert(mapCall::value_type("output", createOutput));
    this->call.insert(mapCall::value_type("clock", createClock));
    this->call.insert(mapCall::value_type("true", createTrue));
    this->call.insert(mapCall::value_type("false", createFalse));
    this->call.insert(mapCall::value_type("4001", create4001));
    this->call.insert(mapCall::value_type("4071", create4071));
    this->call.insert(mapCall::value_type("4011", create4011));
    this->call.insert(mapCall::value_type("4030", create4030));
    this->call.insert(mapCall::value_type("4081", create4081));
    this->call.insert(mapCall::value_type("4069", create4069));
}

Circuit::~Circuit()
{
}

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << INVALID_ARGS << std::endl;
        return (84);
    }
    Circuit *c = new Circuit;
    Parser *p = new Parser(av[1]);

    if (c->fillCircuit(p) == 84)
        return (84);
    if (c->startShell() == 1) {
        delete c;
        delete p;
        return (0);
    }
    return (0);
}

int Circuit::findEqual(std::string input)
{
    std::string name;
    std::string value;
    std::size_t pos;

    pos = input.find("=");
    if (pos == std::string::npos)
        return (0);
    name = input.substr(0, pos);
    value = input.substr(pos+1);
    for (size_t i = 0; i < this->comp.size(); i++) {
        if (this->comp[i]->getName() == name && (value == "1" || value == "0" || value == "U"))
            return (1);
    }
    return (0);
}

void Circuit::changeComponentState(std::string input)
{
    std::string name;
    std::string value;
    std::size_t pos;

    pos = input.find("=");
    name = input.substr(0, pos);
    value = input.substr(pos+1);
    for (size_t i = 0; i < this->comp.size(); i++) {
        if (this->comp[i]->getName() == name) {
            if (value == "0")
                this->comp[i]->getPin(1)->setState(nts::FALSE, 0);
            if (value == "1")
                this->comp[i]->getPin(1)->setState(nts::TRUE, 0);
            if (value == "U")
                this->comp[i]->getPin(1)->setState(nts::UNDEFINED, 0);
        }
    }
}

void Circuit::simulateCircuit()
{
    this->tickNumber++;
    for (size_t i = 0; i < this->comp.size(); i++) {
        if (dynamic_cast<Input *>(this->comp.at(i))) {
            this->comp[i]->getPin(1)->setState(nts::UNDEFINED, 1);
            this->comp[i]->compute(1);
        }
        if (dynamic_cast<Clock *>(this->comp.at(i))) {
            this->comp[i]->getPin(1)->setState(nts::UNDEFINED, 1);
            this->comp[i]->getPin(1)->reverseState();
            this->comp[i]->compute(1);
        }

    }
    for (size_t i = 0; i < this->comp.size(); i++) {
        if (dynamic_cast<Output *>(this->comp.at(i)))
            this->comp[i]->compute(1);
    }
}

void Circuit::freeAll(void)
{
    for (size_t i = 0; i < this->comp.size(); i++)
        delete this->comp[i];
}

int Circuit::startShell(void)
{
    std::string input;

    while (1) {
        std::cout << "> ";
        if (!(getline(std::cin, input))) {
            freeAll();
            return (1);
        }
        if (input == "exit") {
            freeAll();
            return (1);
        }
        if (findEqual(input) == 1)
            changeComponentState(input);
        if (input == "simulate")
            simulateCircuit();
        if (input == "display")
            displayCircuit();
        if (input != "exit" && input != "simulate" && input != "display" && findEqual(input) == 0)
            std::cout << "ERROR : invalid command !" << std::endl;
    }
    return(0);
}

nts::IComponent *Circuit::getComponentName(std::string const name)
{
    for (unsigned int i = 0; i < this->comp.size(); i++) {
        if (this->comp.at(i)->getName() == name)
            return (this->comp.at(i));
    }
    return (nullptr);
}

void Circuit::displayCircuit()
{
    std::cout << "tick: " << this->tickNumber << std::endl;
    std::cout << "input(s):" << std::endl;
    for (nts::IComponent *component : this->comp) {
        if (dynamic_cast<Input *>(component) || dynamic_cast<Clock *>(component))
            std::cout << "  " << component->getName() << ": " << (component->getPin(1)->getActualState() == \
            nts::UNDEFINED ? "U" : std::to_string(component->getPin(1)->getActualState())) << std::endl;
    }
    std::cout << "output(s):" << std::endl;
    for (nts::IComponent *component : this->comp) {
        if (dynamic_cast<Output *>(component)) {
            component->compute(1);
            std::cout << "  " << component->getName() << ": " << (component->getPin(1)->getActualState() == \
            nts::UNDEFINED ? "U" : std::to_string(component->getPin(1)->getActualState())) << std::endl;
        }
    }
}

void Circuit::createLink(std::vector<std::vector<std::string>> links)
{
    std::string component_name_one;
    std::string component_name_two;
    int pin_one = 0;
    int pin_two = 0;

    for (size_t i = 0; i < links.size(); i++) {
        component_name_two = links.at(i).back().substr(0, links.at(i).back().find_first_of(":"));
        component_name_one = links.at(i).front().substr(0, links.at(i).front().find_first_of(":"));
        pin_one = std::stoi(links.at(i).back().substr(links.at(i).back().find_first_of(":") + 1, std::string::npos).c_str());
        pin_two = std::stoi(links.at(i).front().substr(links.at(i).front().find_first_of(":") + 1, std::string::npos).c_str());
        getComponentName(component_name_one)->setLink(pin_two, getComponentName(component_name_two), pin_one);
        getComponentName(component_name_two)->setLink(pin_one, getComponentName(component_name_one), pin_two);
    }
}

int Circuit::fillCircuit(Parser *p)
{
    std::vector<std::vector<std::string>> components;
    std::vector<std::vector<std::string>> links;
    nts::IComponent *temp;
    int ret;

    ret = p->check_input();
    if (ret == 84)
        return (84);
    components = p->get_chipsets();
    links = p->get_links();
    for (size_t i = 0; i < components.size(); i++) {
        temp = createComponent(components.at(i).front());
        temp->setName(components.at(i).back());
        this->comp.push_back(temp);
    }
    this->createLink(links);
    return (0);
}

nts::IComponent *Circuit::createComponent(const std::string &type)
{
    for (std::map<std::string, ptr>::iterator it = this->call.begin(); it != this->call.end(); ++it) {
        if (it->first == type)
            return ((it->second)());
    }
    return (nullptr);
}

nts::IComponent *Circuit::createInput()
{
    nts::IComponent *input = new Input();
    return (input);
}

nts::IComponent *Circuit::createOutput()
{
    nts::IComponent *output = new Output();
    return (output);
}

nts::IComponent *Circuit::createClock()
{
    nts::IComponent *clock = new Clock();
    return (clock);
}

nts::IComponent *Circuit::createTrue()
{
    nts::IComponent *mytrue = new True();
    return (mytrue);
}

nts::IComponent *Circuit::createFalse()
{
    nts::IComponent *myfalse = new False();
    return (myfalse);
}

nts::IComponent *Circuit::create4001()
{
    nts::IComponent *my4001 = new C4001();
    return (my4001);
}

nts::IComponent *Circuit::create4011()
{
    nts::IComponent *my4011 = new C4011();
    return (my4011);
}

nts::IComponent *Circuit::create4071()
{
    nts::IComponent *my4071 = new C4071();
    return (my4071);
}

nts::IComponent *Circuit::create4030()
{
    nts::IComponent *my4030 = new C4030();
    return (my4030);
}

nts::IComponent *Circuit::create4081()
{
    nts::IComponent *my4081 = new C4081();
    return (my4081);
}

nts::IComponent *Circuit::create4069()
{
    nts::IComponent *my4069 = new C4069();
    return (my4069);
}
