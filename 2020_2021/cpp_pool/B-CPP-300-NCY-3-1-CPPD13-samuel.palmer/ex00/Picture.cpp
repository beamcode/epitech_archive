/*
** EPITECH PROJECT, 2021
** Picture.cpp
** File description:
** Picture
*/

#include "Picture.hpp"

//Ctors & Dtors
Picture::Picture(const std::string &file)
{
    getPictureFromFile(file);
}
Picture::~Picture() {}

//Members
bool Picture::getPictureFromFile(const std::string &file)
{
    std::ifstream in(file);
    if (!in) {
        this->data = "ERROR";
        return (false);
    }
    std::string contents((std::istreambuf_iterator<char>(in)), 
    std::istreambuf_iterator<char>());
    this->data = contents;
    return (true);
}
