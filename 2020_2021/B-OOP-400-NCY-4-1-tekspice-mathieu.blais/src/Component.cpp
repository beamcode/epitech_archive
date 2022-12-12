/*
** EPITECH PROJECT, 2021
** Component.cpp
** File description:
** Component class file
*/

#include "Component.hpp"

Component::~Component()
{
}

Component::Component()
{
}

std::string Component::getName() const
{
    return (this->name);
}

std::string Component::getType() const
{
    return (this->type);
}

void Component::setName(const std::string &name)
{
    this->name = name;
}

void Component::simulate()
{
}

void Component::dump() const
{
}
nts::Tristate Component::compute(std::size_t pin)
{
    (void)pin;
    return (nts::UNDEFINED);
}

void Component::setLink(std::size_t pin, nts::IComponent *other, std::size_t otherPin)
{
    pin--;
    if (pin >= this->pins.size())
        return;
    if (otherPin > other->getPinSize())
        return;
    if (this->pins.at(pin)->getType() == other->getPin(otherPin)->getType())
        return;
    this->pins.at(pin)->addLink(other->getPin(otherPin));
}

size_t Component::getMyPin(nts::Pin *pin) const
{
    for (size_t i = 0; i < this->pins.size(); i++) {
        if (this->pins.at(i) == pin)
            return (i);
    }
    return (0);
}

nts::Pin *Component::getPin(size_t indxPin) const
{
    indxPin--;
    if (indxPin >= this->pins.size())
        return (nullptr);
    return (this->pins.at(indxPin));
}

size_t Component::getPinSize() const
{
    return (this->pins.size());
}
