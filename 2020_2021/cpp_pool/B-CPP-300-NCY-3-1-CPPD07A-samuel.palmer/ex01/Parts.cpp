/*
** EPITECH PROJECT, 2021
** Parts.cpp
** File description:
** Parts
*/

#include "KoalaBot.hpp"
#include "Parts.hpp"

//Ctor
Arms::Arms() : _serial("A-01"), _functional(true) {}
Legs::Legs() : _serial("L-01"), _functional(true) {}
Head::Head() : _serial("H-01"), _functional(true) {}

Arms::Arms(std::string &serial, bool functional) : _serial(serial), _functional(functional) {}
Legs::Legs(std::string &serial, bool functional) : _serial(serial), _functional(functional) {}
Head::Head(std::string &serial, bool functional) : _serial(serial), _functional(functional) {}

//Dtor
Arms::~Arms() {}
Legs::~Legs() {}
Head::~Head() {}

//Members
std::string Arms::serial() const { return (this->_serial); }
std::string Legs::serial() const { return (this->_serial); }
std::string Head::serial() const { return (this->_serial); }

bool Arms::isFunctional() const { return (this->_functional); }
bool Legs::isFunctional() const { return (this->_functional); }
bool Head::isFunctional() const { return (this->_functional); }

void Arms::informations() const
{
    std::cout << "\t[Parts] Arms " << this->_serial <<
    " status : " << (this->_functional ? "OK" : "KO") << std::endl;
}

void Legs::informations() const
{
    std::cout << "\t[Parts] Legs " << this->_serial <<
    " status : " << (this->_functional ? "OK" : "KO") << std::endl;
}

void Head::informations() const
{
    std::cout << "\t[Parts] Head " << this->_serial <<
    " status : " << (this->_functional ? "OK" : "KO") << std::endl;
}