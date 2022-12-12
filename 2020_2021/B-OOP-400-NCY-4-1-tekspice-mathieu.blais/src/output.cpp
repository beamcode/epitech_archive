/*
** EPITECH PROJECT, 2021
** output.cpp
** File description:
** output class file
*/

#include "output.hpp"

Output::~Output()
{
    for (size_t i = 0; i < this->pins.size(); i++)
        delete this->pins[i];
}

Output::Output()
{
    this->pins.push_back(new nts::Pin(this, "input"));
}

nts::Tristate Output::compute(std::size_t pin)
{
    pin--;
    return (this->pins[pin]->getState());
}
