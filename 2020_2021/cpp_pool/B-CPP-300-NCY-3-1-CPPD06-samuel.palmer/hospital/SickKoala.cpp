/*
** EPITECH PROJECT, 2021
** SickKoala.cpp
** File description:
** ex02 main file
*/

#include "SickKoala.hpp"

SickKoala::SickKoala(std::string str)
{
    if (str.empty() == true)
        return;
    this->name = str;
}

SickKoala::~SickKoala(void)
{
    std::cout << "Mr." << this->name <<
    ": Kreooogg!! I'm cuuuured!" << std::endl;
}

void SickKoala::overDrive(std::string str)
{
    const std::string rep = "1337!";

    for (int i = 0; (i = str.find("Kreog!")) != std::string::npos;)
        str.replace(i, rep.length(), rep);

    std::cout << "Mr." << this->name << ": " << str << std::endl;
}

bool SickKoala::takeDrug(std::string str)
{
    if (str.compare("Mars") == 0) {
        std::cout << "Mr." << this->name <<
        ": Mars, and it kreogs!" << std::endl;
        return (true);
    }
    else if (str.compare("Kinder") == 0) {
        std::cout << "Mr." << this->name <<
        ": There is a toy inside!" << std::endl;
        return (true);
    }
    else {
        std::cout << "Mr." << this->name << ": Goerkreog!" << std::endl;
        return (false);
    }
    return (false);
}

void SickKoala::poke(void)
{
    std::cout << "Mr." << this->name << ": Gooeeeeerrk!!" << std::endl;
}