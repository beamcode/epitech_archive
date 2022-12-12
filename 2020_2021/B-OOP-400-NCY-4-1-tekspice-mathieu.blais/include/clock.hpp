/*
** EPITECH PROJECT, 2021
** clock.hpp
** File description:
** clock class header
*/

#ifndef CLOCK_H
#define CLOCK_H

#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>

#include "Component.hpp"

class Clock : public Component {
    public:
        virtual ~Clock();
        Clock();

        nts::Tristate Compute(std::size_t pin);
    protected:
    private:
};

#endif /* !CLOCK_HPP_ */
