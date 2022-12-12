/*
** EPITECH PROJECT, 2021
** FruitNode.hpp
** File description:
** FruitNode
*/

#ifndef FRUITNODE_HPP_
#define FRUITNODE_HPP_

#include "Fruit.hpp"

typedef struct FruitNode
{
    Fruit *_fruit;
    FruitNode *_next;
} FruitNode_t;

#endif /* !FRUITNODE_HPP_ */
