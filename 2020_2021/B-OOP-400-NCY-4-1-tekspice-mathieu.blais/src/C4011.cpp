/*
** EPITECH PROJECT, 2021
** C4011.cpp
** File description:
** C4011 Component class file
*/

#include "C4011.hpp"

C4011::C4011()
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

C4011::~C4011()
{
    for (size_t i = 0; i < this->pins.size(); i++)
        delete this->pins[i];
}

nts::Tristate C4011::compute(std::size_t pin)
{
    LogicGate gate;

    pin--;
    if (pin == 2)
        this->pins[2]->setState(gate.GateNAnd(this->pins[0]->getState(), this->pins[1]->getState()), 1);
    if (pin == 3)
        this->pins[3]->setState(gate.GateNAnd(this->pins[4]->getState(), this->pins[5]->getState()), 1);
    if (pin == 9)
        this->pins[9]->setState(gate.GateNAnd(this->pins[7]->getState(), this->pins[8]->getState()), 1);
    if (pin == 10)
        this->pins[10]->setState(gate.GateNAnd(this->pins[11]->getState(), this->pins[12]->getState()), 1);
    return (this->pins[pin]->getActualState());
}
