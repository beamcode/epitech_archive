/*
** EPITECH PROJECT, 2021
** Hunter.cpp
** File description:
** Hunter
*/

#include "Hunter.hpp"

Hunter::Hunter(const std::string &name, int level) : Character(name, level), Warrior(name, level), _weaponName("sword")
{
    this->_name = name;
    this->_level = level;
    this->_race = "Elf";
    this->_strength = 9;
    this->_stamina = 9;
    this->_intelligence = 5;
    this->_spirit = 6;
    this->_agility = 25;
    std::cout << " is born from a tree" << std::endl;
}

Hunter::~Hunter() {}

//Member
int Hunter::CloseAttack()
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

void Character::RestorePower()
{
    std::cout << this->_name << " meditates" << std::endl;
    this->_energy = 100;
}

int Character::RangeAttack()
{
    if (this->_energy < 25) {
        std::cout << this->_name << " out of power" << std::endl;
        return (0);
    }
    this->_energy -= 25;
    std::cout << this->_name << " uses his bow" << std::endl;
    return (20 + this->_agility);
}