/*
** EPITECH PROJECT, 2021
** Paladin.cpp
** File description:
** Paladin
*/

#include "Paladin.hpp"

//Ctor & Dtor
Paladin::Paladin(const std::string &name, int level) : Character(name, level), Warrior(name, level), Priest(name, level)
{
    this->_name = name;
    this->_level = level;
    this->_intelligence = 10;
    this->_strength = 9;
    this->_stamina = 10;
    this->_agility = 2;
    this->_spirit = 10;
    std::cout << "the light falls on " << this->_name << std::endl;
}

Paladin::~Paladin() {}

//Members
int Paladin::Intercept()
{
    if (this->Range == CLOSE)
        return (0);
    if (this->_energy < 10) {
        std::cout << this->_name << " out of power" << std::endl;
        return (0);
    }
    else {
        this->_energy -= 10;
        std::cout << this->_name << " intercepts" << std::endl;
        this->Range = CLOSE;
    }
    return (0);
}