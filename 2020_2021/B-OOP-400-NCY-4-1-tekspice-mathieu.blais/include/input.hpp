/*
** EPITECH PROJECT, 2021
** input.hpp
** File description:
** input class header
*/

#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>

#include "Component.hpp"
#include "Pins.hpp"

class Input : public Component {
    public:
        virtual ~Input();
        Input();

        nts::Tristate compute(std::size_t pin);
    protected:
    private:
};

#endif /* !INPUT_HPP_ */
