/*
** EPITECH PROJECT, 2021
** Sorcerer.cpp
** File description:
** Sorcerer
*/

#include "Sorcerer.hpp"
#include "Victim.hpp"

//Ctor & Dtor
Sorcerer::Sorcerer(const std::string &name, const std::string &title)
: _name(name), _title(title)
{
    std::cout << name << ", " << title << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer()
{
    std::cout << this->_name << ", " << this->_title <<
    ", is dead. Consequences will never be the same!" << std::endl;
}

//Members
std::ostream &operator<<(std::ostream &os, const Sorcerer &s) 
{
    os << "I am " << s.getName() << ", " << s.getTitle()
    << ", and I like ponies!" << std::endl;
    return (os);
}

void Sorcerer::polymorph(const Victim &victim) const
{
    victim.getPolymorphed();
}