/*
** EPITECH PROJECT, 2021
** Victim.cpp
** File description:
** Victim
*/

#include "Victim.hpp"

//Ctor & Dtor
Victim::Victim(const std::string &name) : _name(name)
{
    std::cout << "Some random victim called " << this->_name
    << " just popped!" << std::endl;
}

Victim::~Victim()
{
    std::cout << "Victim " << this->_name <<
    " just died for no apparent reason!" << std::endl;
}

//Members
const std::string Victim::getName() const { return(this->_name); }

std::ostream &operator<<(std::ostream &os, const Victim &s) 
{
    os << "I'm " << s.getName() << " and I like otters!" << std::endl;
    return (os);
}

void Victim::getPolymorphed() const
{   
    std::cout << this->_name << " has been turned into a cute little sheep!"
    << std::endl;
}