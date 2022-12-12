/*
** EPITECH PROJECT, 2021
** Fruit.cpp
** File description:
** Fruit
*/

#include "Fruit.hpp"

Fruit::Fruit()
{
}

Fruit::~Fruit()
{
}

std::string Fruit::getName() const { return (_name); }
int Fruit::getVitamins() const { return (_vitamins); }