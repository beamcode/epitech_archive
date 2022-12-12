/*
** EPITECH PROJECT, 2021
** C4081.cpp
** File description:
** C4081 Component class file
*/

#include "C4081.hpp"

C4081::C4081()
{
    this->pins.push_back(new nts::Pin(this, "input"));
    this->pins.push_back(new nts::Pin(this, "input"));
    this->pins.push_back(new nts::Pin(this, "output"));
    this->pins.push_back(new nts::Pin(this, "output"));
    this->pins.push_back(new nts::Pin(this, "input"));
    this->pins.push_back(new nts::Pin(this, "input"));
    this->pins.push_back(new nts::Pin(this, "other"));
    this->pins.push_back(new nts::Pin(this, "input"));
    this->pins.push_back(new nts::Pin(this, "input"));
    this->pins.push_back(new nts::Pin(this, "output"));
    this->pins.push_back(new nts::Pin(this, "output"));
    this->pins.push_back(new nts::Pin(this, "input"));
    this->pins.push_back(new nts::Pin(this, "input"));
    this->pins.push_back(new nts::Pin(this, "other"));
}

C4081::~C4081()
{
    for (size_t i = 0; i < this->pins.size(); i++)
        delete this->pins[i];
}

nts::Tristate C4081::compute(std::size_t pin)
{
    LogicGate gate;

    pin--;
    if (pin == 2)
        this->pins[2]->setState(gate.GateAnd(this->pins[0]->getState(), this->pins[1]->getState()), 1);
    if (pin == 3)
        this->pins[3]->setState(gate.GateAnd(this->pins[4]->getState(), this->pins[5]->getState()), 1);
    if (pin == 9)
        this->pins[9]->setState(gate.GateAnd(this->pins[7]->getState(), this->pins[8]->getState()), 1);
    if (pin == 10)
        this->pins[10]->setState(gate.GateAnd(this->pins[11]->getState(), this->pins[12]->getState()), 1);
    return (this->pins.at(pin)->getActualState());
}
