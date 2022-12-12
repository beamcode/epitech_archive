/*
** EPITECH PROJECT, 2021
** clock.cpp
** File description:
** clock class file
*/

#include "clock.hpp"

Clock::~Clock()
{
    for (size_t i = 0; i < this->pins.size(); i++)
        delete this->pins[i];
}

Clock::Clock()
{
    this->type = "clock";
    this->pins.push_back(new nts::Pin(this, "output"));
}

nts::Tristate Clock::Compute(std::size_t pin)
{
    pin--;
    return (this->pins.at(pin)->getActualState());
}
