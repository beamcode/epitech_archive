/*
** EPITECH PROJECT, 2021
** Toy.cpp
** File description:
** Toy
*/

#include "Toy.hpp"

//Ctors & Dtors
Toy::Toy() : _toytype(BASIC_TOY), _name("toy"), _picture(Picture()) {}

Toy::Toy(const Toy &toy)
{
    this->_toytype = toy._toytype;
    this->_name = toy._name;
    this->_picture = toy._picture;
}

Toy::Toy(ToyType type, const std::string &name, const std::string &filename)
{
    this->_toytype = type;
    this->_name = name;
    this->_picture = Picture(filename);
}

Toy::~Toy() {}

//Members
bool Toy::setAscii(const std::string &filename)
{
    return _picture.getPictureFromFile(filename);
}

std::string Toy::getName() const { return _name; }
Picture Toy::getPicture() const { return _picture; }
Toy::ToyType Toy::getType() const { return _toytype; }
std::string Toy::getAscii() const { return _picture.getData(); }
void Toy::setName(const std::string &name) { _name = name; }

Toy &Toy::operator=(const Toy &toy)
{
    _name = toy.getName();
    _picture = toy.getPicture();
    _toytype = toy.getType();
    return (*this);
}

void Toy::speak(const std::string &str) const
{
    std::cout << this->_name << " \"" << str << "\"" << std::endl;
}

Toy &Toy::operator<<(const std::string &str)
{
    _picture.setAscii(str);
    return (*this);
}

std::ostream &operator<<(std::ostream &os, const Toy &toy)
{
    return(os << toy.getName() << std::endl << toy.getAscii() << std::endl);
}