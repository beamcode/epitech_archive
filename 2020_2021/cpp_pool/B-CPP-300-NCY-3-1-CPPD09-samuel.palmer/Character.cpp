/*
** EPITECH PROJECT, 2021
** Character.cpp
** File description:
** Character
*/

#include "Character.hpp"

//Ctor & Dtor
Character::Character(const std::string &name, int level)
{
    this->_name = name;
    this->_level = level;
    this->_race = "Human";
    this->_energy = 100;
    this->_pv = 100;
    this->_intelligence = 5;
    this->_strength = 5;
    this->_stamina = 5;
    this->_agility = 5;
    this->_spirit = 5;
    this->Range = CLOSE;
    std::cout << name << " Created" << std::endl;
}

Character::~Character() {}

//Members
const std::string &Character::getName() const { return (this->_name); }
int Character::getLvl() const { return (this->_level); }
int Character::getPv() const { return (this->_pv); }
int Character::getPower() const { return (this->_energy); }

int Character::CloseAttack()
{
    if (this->Range == RANGE)
        return (0);
    if (this->_energy < 10) {
        std::cout << this->_name << " out of power" << std::endl;
        return (0);
    }
    else {
        this->_energy -= 10;
        std::cout << this->_name << " strikes with a wooden stick" << std::endl;
    }
    return (this->_strength + 10);
}

void Character::Heal()
{
    std::cout << this->_name << " takes a potion" << std::endl;
    this->_pv = ((this->_pv + 50) > 100) ? 100 : this->_pv + 50;
}

void Character::RestorePower()
{
    std::cout << this->_name << " eats" << std::endl;
    this->_energy = 100;
}

int Character::RangeAttack()
{
    if (this->_energy < 10) {
        std::cout << this->_name << " out of power" << std::endl;
        return (0);
    }
    this->_energy -= 10;
    std::cout << this->_name << " tosses a stone" << std::endl;
    return (this->_strength + 5);
}

void Character::TakeDamage(int damage)
{
    if (damage >= this->_pv) {
        this->_pv -= damage;
        std::cout << this->_name << " out of combat" << std::endl;
    }
    else {
        std::cout << this->_name << " takes " << damage << " damage" << std::endl; 
        this->_pv -=damage;
    }
}