/*
** EPITECH PROJECT, 2021
** false.cpp
** File description:
** false class file
*/

#include "false.hpp"

False::~False()
{
    for (size_t i = 0; i < this->pins.size(); i++)
        delete this->pins[i];
}

False::False()
{
    this->pins.push_back(new nts::Pin(this, "output", nts::Tristate::FALSE));
}

nts::Tristate False::compute(std::size_t pin)
{
    pin--;
    return (this->pins.at(pin)->getActualState());
}
