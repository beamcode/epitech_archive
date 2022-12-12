/*
** EPITECH PROJECT, 2021
** main.cpp
** File description:
** ex00
*/

#include "Federation.hpp"

// Starfleet Ship functions
void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
    if (!core)
        return;
    this->_core = core;
    std::cout << "USS " << this->_name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore()
{
    std::string status = this->_core->checkReactor()->isStable() ? "stable" : "unstable";
    std::cout << "USS " << this->_name << ": The core is " << status << " at the time." << std::endl;
}

Federation::Starfleet::Ship::~Ship() {}

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp)
{
    this->_length = length;
    this->_width = width;
    this->_name = name;
    this->_maxWarp = maxWarp;

    std::cout << "The ship USS " << name << " has been finished." << std::endl;
    std::cout << "It is " << length << " m in length and " << width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << maxWarp << "!" << std::endl;
}

// Independent Ship functions
void Federation::Ship::setupCore(WarpSystem::Core *core)
{
    if (!core)
        return;
    this->_core = core;
    std::cout << this->_name << ": The core is set." << std::endl;
}

void Federation::Ship::checkCore()
{
    std::string status = this->_core->checkReactor()->isStable() ? "stable" : "unstable";
    std::cout << this->_name << ": The core is " << status << " at the time." << std::endl;
}

Federation::Ship::Ship(int length, int width, std::string name)
{
    this->_length = length;
    this->_width = width;
    this->_name = name;
    this->_maxWarp = 1;

    std::cout << "The independent ship " << name << " just finished its construction." << std::endl;
    std::cout << "It is " << length << " m in length and " << width << " m in width." << std::endl;
}

Federation::Ship::~Ship() {}

Federation::Starfleet::Captain::Captain(std::string name) : _name(name), _age(0) {}

Federation::Starfleet::Captain::~Captain() {}

std::string Federation::Starfleet::Captain::getName()
{
    return (this->_name);
}

int Federation::Starfleet::Captain::getAge()
{
    return (this->_age);
}

void Federation::Starfleet::Captain::setAge(int age)
{
    this->_age = age;
}

void Federation::Starfleet::Ship::promote(Captain *captain)
{
    if (!captain)
        return;
    this->_captain = captain;
    std::cout << this->_captain->getName() <<
    ": I'm glad to be the captain of the USS " <<
    this->_name << "." << std::endl;
}

Federation::Starfleet::Ensign::Ensign(std::string name)
{
    this->_name = name;
    std::cout << "Ensign " << this->_name << ", awaiting orders." << std::endl;
}

Federation::Starfleet::Ensign::~Ensign() {}