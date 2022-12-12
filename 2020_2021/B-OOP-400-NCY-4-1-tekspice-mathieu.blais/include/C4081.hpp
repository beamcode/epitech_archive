/*
** EPITECH PROJECT, 2021
** C4081.cpp
** File description:
** C4081 Component class header
*/

#ifndef C4081_H
#define C4081_H

#include "Component.hpp"

class C4081 : public Component {
    public:
        C4081();
        virtual ~C4081();

        nts::Tristate compute(std::size_t pin);
    protected:
    private:
};

#endif /* !C4081_HPP */
