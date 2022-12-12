/*
** EPITECH PROJECT, 2021
** Peon.cpp
** File description:
** Peon
*/

#include "Peon.hpp"

//Ctor & Dtor
Peon::Peon(const std::string &name) : Victim(name)
{
    std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
    std::cout << "Bleuark..." << std::endl;
}

//Members
void Peon::getPolymorphed() const
{   
    std::cout << this->_name << " has been turned into a pink pony!" << std::endl;
}