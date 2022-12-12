/*
** EPITECH PROJECT, 2021
** Cesar.cpp
** File description:
** Cesar
*/

#include "Cesar.hpp"

//Ctors & Dtors
Cesar::Cesar() : _shift(3) {}

Cesar::~Cesar()
{
}

//Members
void Cesar::encryptChar(char plainchar)
{
    if (!isalpha(plainchar)) {
        std::cout << plainchar;
        _shift++;
        return;
    }
    if (islower(plainchar))
        plainchar = (plainchar + _shift - 'a') % 26 + 'a';
    else
        plainchar = ((plainchar+ _shift - 'A') % 26 + 'A';
    _shift++;
}

void Cesar::decryptChar(char cipherchar)
{
    if (!isalpha(cipherchar)) {
        std::cout << cipherchar;
        _shift++;
        return;
    }
    if (islower(cipherchar))

    else {

    _shift++;
}

void Cesar::reset()
{
    this->_shift = 3;
}