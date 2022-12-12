/*
** EPITECH PROJECT, 2021
** Priest.cpp
** File description:
** Priest
*/

#include "Priest.hpp"

//Ctor & Dtor
Priest::Priest(const std::string &name, int level) : Character(name, level), Mage(name, level)
{
    this->_name = name;
    this->_level = level;
    this->_race = "Orc";
    this->_intelligence = 42;
    this->_strength = 4;
    this->_stamina = 4;
    this->_agility = 2;
    this->_spirit = 21;
    std::cout << this->_name << " enters in the order" << std::endl;
}

Priest::~Priest() {}

//Members
int Priest::CloseAttack()
{
    if (this->Range == RANGE)
        return (0);
    if (this->_energy < 10) {
        std::cout << this->_name << " out of power" << std::endl;
        return (0);
    }
    this->Range = RANGE;
    this->_energy -= 10;
    std::cout << this->_name << " uses a spirit explosion" << std::endl;
    return (10 + this->_spirit);
}

int Priest::RangeAttack()
{
    if (this->Range == CLOSE)
        return (0);
    if (this->_energy < 25) {
        std::cout << this->_name << " out of power" << std::endl;
        return (0);
    }
    else {
        this->_energy -= 25;
        std::cout << this->_name << " launches a fire ball" << std::endl;
        this->Range = CLOSE;
    }
    return (20 + this->_spirit);
}

void Priest::Heal()
{
    std::cout << this->_name << " casts a little heal spell" << std::endl;
    this->_pv = ((this->_pv + 70) > 100) ? 100 : this->_pv + 70;
}