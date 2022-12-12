/*
** EPITECH PROJECT, 2021
** Pins.cpp
** File description:
** Pins class file
*/

#include "IComponent.hpp"
#include "Pins.hpp"

nts::Pin::Pin(nts::IComponent *component, const std::string &type, nts::Tristate state)
{
    this->temp = nts::UNDEFINED;
    this->state = state;
    this->type = type;
    this->comp = component;
}

nts::Pin::~Pin()
{
}

nts::Tristate nts::Pin::getState()
{
    if (this->type == "input") {
        if (!(this->link))
            return (this->state);
         this->state = this->link->getState();
    } else if (this->type == "output")
        this->comp->compute(this->comp->getMyPin(this)+1);
    return (this->state);
}

nts::Tristate nts::Pin::getActualState() const
{
    return (this->state);
}

std::string nts::Pin::getType() const
{
    return (this->type);
}

void nts::Pin::setState(nts::Tristate state, int i)
{
    if (this->comp->getType() == "input" || this->comp->getType() == "clock") {
      if (i == 0)
          this->temp = state;
      if (i == 1)
          this->state = this->temp;
    }
    else
        this->state = state;
}

void nts::Pin::reverseState()
{
    if (this->state == nts::TRUE)
        this->temp = nts::FALSE;
    if (this->state == nts::FALSE)
        this->temp = nts::TRUE;
}

void nts::Pin::addLink(nts::Pin *otherPin)
{
   this->link = otherPin;
}
