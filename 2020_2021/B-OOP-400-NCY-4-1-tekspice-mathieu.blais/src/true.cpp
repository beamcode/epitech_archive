/*
** EPITECH PROJECT, 2021
** true.cpp
** File description:
** true class file
*/

#include "true.hpp"

True::~True()
{
    for (size_t i = 0; i < this->pins.size(); i++)
        delete this->pins[i];
}

True::True()
{
    this->pins.push_back(new nts::Pin(this, "output", nts::Tristate::TRUE));
}

nts::Tristate True::compute(std::size_t pin)
{
    pin--;
    return (this->pins.at(pin)->getActualState());
}
