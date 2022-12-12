/*
** EPITECH PROJECT, 2021
** Buzz.cpp
** File description:
** Buzz
*/

#include "Buzz.hpp"

//Ctors & Dtors
Buzz::Buzz(const std::string &name, const std::string &filename)
: Toy(BUZZ, name, filename) {}

Buzz::Buzz(const std::string &name) : Toy(BUZZ, name, "")
{
    _picture.setAscii("");
    _picture.getPictureFromFile("buzz.txt");
}
Buzz::~Buzz() {}

//Members