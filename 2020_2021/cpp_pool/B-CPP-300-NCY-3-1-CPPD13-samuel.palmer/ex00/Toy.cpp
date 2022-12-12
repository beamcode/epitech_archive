/*
** EPITECH PROJECT, 2021
** Toy.cpp
** File description:
** Toy
*/

#include "Toy.hpp"

//Ctors & Dtors
Toy::Toy(ToyType type, const std::string &name, const std::string &filename)
{
    this->toy_type = type;
    this->_name = name;
    this->_picture = Picture(filename);
}

Toy::~Toy() {}

//Members
bool Toy::setAscii(const std::string &filename)
{
    return (this->_picture.getPictureFromFile(filename));
}