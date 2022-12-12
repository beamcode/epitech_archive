/*
** EPITECH PROJECT, 2021
** C4069.cpp
** File description:
** C4069 Component class file
*/

#include "C4069.hpp"

C4069::C4069()
{
    this->pins.push_back(new nts::Pin(this, "input"));
    this->pins.push_back(new nts::Pin(this, "output"));
    this->pins.push_back(new nts::Pin(this, "input"));
    this->pins.push_back(new nts::Pin(this, "output"));
    this->pins.push_back(new nts::Pin(this, "input"));
    this->pins.push_back(new nts::Pin(this, "output"));
    this->pins.push_back(new nts::Pin(this, "other"));
    this->pins.push_back(new nts::Pin(this, "output"));
    this->pins.push_back(new nts::Pin(this, "input"));
    this->pins.push_back(new nts::Pin(this, "output"));
    this->pins.push_back(new nts::Pin(this, "input"));
    this->pins.push_back(new nts::Pin(this, "output"));
    this->pins.push_back(new nts::Pin(this, "input"));
    this->pins.push_back(new nts::Pin(this, "othe"));
}

C4069::~C4069()
{
    for (size_t i = 0; i < this->pins.size(); i++)
        delete this->pins[i];
}

nts::Tristate C4069::compute(std::size_t pin)
{
    LogicGate gate;

    pin--;
    if (pin == 1)
        this->pins[1]->setState(gate.GateNot(this->pins[0]->getState()), 1);
    if (pin == 3)
        this->pins[3]->setState(gate.GateNot(this->pins[2]->getState()), 1);
    if (pin == 5)
        this->pins[5]->setState(gate.GateNot(this->pins[4]->getState()), 1);
    if (pin == 7)
        this->pins[7]->setState(gate.GateNot(this->pins[8]->getState()), 1);
    if (pin == 9)
        this->pins[9]->setState(gate.GateNot(this->pins[10]->getState()), 1);
    if (pin == 11)
        this->pins[11]->setState(gate.GateNot(this->pins[12]->getState()), 1);
    return (this->pins[pin]->getActualState());
}
