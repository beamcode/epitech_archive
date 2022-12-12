/*
** EPITECH PROJECT, 2021
** Borg.cpp
** File description:
** Borg
*/

#include "Federation.hpp"

Borg::Ship::Ship() : _side(300), _maxWarp(9)
{
    std::cout << "We are the Borgs. Lower your shields and surrender"
    << " yourselves unconditionally." << std::endl;
    std::cout << "Your biological characteristics and technologies will"
    " be assimilated." << std::endl;
    std::cout << "Resistance is futile." << std::endl;
}

void Borg::Ship::setupCore(WarpSystem::Core *core)
{
    if (!core)
        return;
    this->_core = core;
}

void Borg::Ship::checkCore()
{
    if (!this->_core)
        return;
    std::cout << (this->_core->checkReactor()->isStable() ?
	"Everything is in order." : "Critical failure imminent.") << std::endl;
}