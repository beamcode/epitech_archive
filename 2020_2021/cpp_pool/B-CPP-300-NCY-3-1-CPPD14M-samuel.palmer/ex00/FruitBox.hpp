/*
** EPITECH PROJECT, 2021
** FruitBox.hpp
** File description:
** FruitBox
*/

#ifndef FRUITBOX_HPP_
#define FRUITBOX_HPP_

#include "FruitNode.hpp"

class FruitBox {
    public:
        FruitBox() : _next(nullptr), _fruit(nullptr) {}
        FruitBox();
        ~FruitBox();

    protected:
    private:
        int _size;
        FruitNode *_fruit;
};


#endif /* !FRUITBOX_HPP_ */
