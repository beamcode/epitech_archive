/*
** EPITECH PROJECT, 2021
** skat.cpp
** File description:
** ex00
*/

#include "Skat.hpp"

Skat::~Skat() {};

Skat::Skat()
{
    this->_name = "bob";
    this->_stimPaks = 15;
}

Skat::Skat(const std::string &name, int stimPaks)
{
    this->_name = name;
    this->_stimPaks = stimPaks;
}

void Skat::shareStimPaks(int number, int &stock)
{
    if (this->_stimPaks < number)
        std::cout << "Don't be greedy" << std::endl;
    else {
        std::cout << "Keep the change." << std::endl;
        stock += number;
        this->_stimPaks -= number;
    }
}

int &Skat::stimPaks()
{
    return (this->_stimPaks);
}

void Skat::addStimPaks(unsigned int number)
{
    if (number == 0)
        std::cout << "Hey boya, did you forget something?" << std::endl;
    this->_stimPaks += number;
}

void Skat::useStimPaks()
{
    if (this->_stimPaks > 0) {
        this->_stimPaks--;
        std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
    }
    else
        std::cout << "Mediiiiiic" << std::endl;
}

const std::string &Skat::name()
{
    return (this->_name);
}

void Skat::status()
{
    std::cout << "Soldier " << this->_name << " reporting " <<
    this->_stimPaks << " stimpaks remaining sir!" << std::endl;
}