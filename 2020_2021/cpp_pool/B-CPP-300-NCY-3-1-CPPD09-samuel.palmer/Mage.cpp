/*
** EPITECH PROJECT, 2021
** Mage.cpp
** File description:
** Mage
*/

#include "Mage.hpp"

//Ctor & Dtor
Mage::Mage(const std::string &name, int level) : Character(name, level)
{
    this->_name = name;
    this->_level = level;
    this->_race = "Gnome";
    this->_strength = 6;
    this->_stamina = 6;
    this->_intelligence = 12;
    this->_spirit = 11;
    this->_agility = 7;
    std::cout << this->_name << " teleported" << std::endl;
}

Mage::~Mage() {}

//Members
int Mage::CloseAttack()
{
    if (this->Range == RANGE)
        return (0);
    if (this->_energy < 10) {
        std::cout << this->_name << " out of power" << std::endl;
        return (0);
    }
    else {
        this->Range = RANGE;
        this->_energy -= 10;
        std::cout << this->_name << " blinks" << std::endl;
    }
    return (0);
}

void Mage::RestorePower()
{
    std::cout << this->_name << " takes a mana potion" << std::endl;
    this->_energy  = ((this->_energy + 50) > 100) ? 100 : this->_pv + 50;
}

int Mage::RangeAttack()
{
    if (this->_energy < 25) {
        std::cout << this->_name << " out of power" << std::endl;
        return (0);
    }
    else {
        this->_energy -= 25;
        std::cout << this->_name << " launches a fire ball" << std::endl;
    }
    return (20 + this->_spirit);
}