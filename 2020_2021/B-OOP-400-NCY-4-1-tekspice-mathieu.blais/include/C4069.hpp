/*
** EPITECH PROJECT, 2021
** C4069.cpp
** File description:
** C4069 Compenent class header
*/

#ifndef C4069_H
#define C4069_H

#include "Component.hpp"

class C4069 : public Component {
    public:
        C4069();

        virtual ~C4069();
        nts::Tristate compute(std::size_t pin = 1) override;
    protected:
    private:
};

#endif /* !C4069_HPP */
