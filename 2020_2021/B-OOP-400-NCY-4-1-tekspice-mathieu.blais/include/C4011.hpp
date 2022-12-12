/*
** EPITECH PROJECT, 2021
** C4011.cpp
** File description:
** C4011 Component class header
*/

#ifndef C4011_H
#define C4011_H

#include "Component.hpp"

class C4011 : public Component {
    public:
        C4011();
        virtual ~C4011();

        nts::Tristate compute(std::size_t pin);
    protected:
    private:
};

#endif /* !C4011_HPP */
