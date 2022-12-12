/*
** EPITECH PROJECT, 2021
** Woody.cpp
** File description:
** Woody
*/

#include "Woody.hpp"

//Ctors & Dtors
Woody::Woody(const std::string &name, const std::string &filename)
: Toy(WOODY, name, filename) {}

Woody::Woody(const std::string &name) : Toy(WOODY, name, "")
{
    _picture.setAscii("");
    _picture.getPictureFromFile("woody.txt");
}

Woody::~Woody() {}

//Members