/*
** EPITECH PROJECT, 2021
** Warrior.cpp
** File description:
** Warrior
*/

#include "Warrior.hpp"

//Ctor & Dtor
Warrior::Warrior(const std::string &name, int level) : Character(name, level), _weaponName("hammer")
{
    this->_name = name;
    this->_level = level;
    this->_race = "Dwarf";
    this->_intelligence = 6;
    this->_strength = 12;
    this->_stamina = 12;
    this->_agility = 7;
    this->_spirit = 5;
    std::cout << "I'm " << name << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG"
    << std::endl;
}

Warrior::~Warrior() {}

//Members
int Warrior::CloseAttack()
{
    if (this->Range == RANGE)
        return (0);
    if (this->_energy < 30) {
        std::cout << this->_name << " out of power" << std::endl;
        return (0);
    }
    this->_energy -= 30;
    std::cout << this->_name << " strikes with his " << this->_weaponName << std::endl;
    return (20 + this->_strength);
}

int Warrior::RangeAttack()
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