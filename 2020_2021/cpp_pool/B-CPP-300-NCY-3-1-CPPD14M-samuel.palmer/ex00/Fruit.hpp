/*
** EPITECH PROJECT, 2021
** Fruit.hpp
** File description:
** Fruit
*/

#ifndef FRUIT_HPP_
#define FRUIT_HPP_

#include <iostream>
#include <string>

class Fruit {
    public:
        Fruit();
        ~Fruit();

        std::string getName() const; 
    protected:
        std::string _name;
        std::string _vitamins;
    private:
};

#endif /* !FRUIT_HPP_ */
