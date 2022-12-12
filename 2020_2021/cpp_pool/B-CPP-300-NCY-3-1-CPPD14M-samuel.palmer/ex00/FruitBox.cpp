/*
** EPITECH PROJECT, 2021
** FruitBox.cpp
** File description:
** FruitBox
*/

#include "FruitBox.hpp"

FruitBox::FruitBox()
{
}

FruitBox::FruitBox(int size) : _size(size), _fruitlist(nullptr) {}

FruitBox::~FruitBox()
{
}

//Members

int nbFruits(FruitNode list)
{
    unsigned int a = 0;

    for ( ; list != nullptr; a++)
        list = list->next;
    return (a);
}

bool putFruit(Fruit *f)
{

}

Fruit *pickFruit()
{

}

FruitNode *head()
{
    
}