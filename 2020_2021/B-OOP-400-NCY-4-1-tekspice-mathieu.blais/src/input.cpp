/*
** EPITECH PROJECT, 2021
** input.cpp
** File description:
** input class file
*/

#include "input.hpp"

Input::~Input()
{
    for (size_t i = 0; i < this->pins.size(); i++)
        delete this->pins[i];
}

Input::Input()
{
    this->type = "input";
    this->pins.push_back(new nts::Pin(this, "output"));
}

nts::Tristate Input::compute(std::size_t pin)
{
    pin--;
    return (this->pins[pin]->getActualState());
}
