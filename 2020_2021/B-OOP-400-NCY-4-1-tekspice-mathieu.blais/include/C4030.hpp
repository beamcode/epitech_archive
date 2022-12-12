/*
** EPITECH PROJECT, 2021
** C4030.hpp
** File description:
** C4030 Compenent class header
*/

#ifndef C4030_H
#define C4030_H

#include "Component.hpp"

class C4030 : public Component {
    public:
        C4030();

        virtual ~C4030();
        nts::Tristate compute(std::size_t pin);
    protected:
    private:
};

#endif /* !C4030_HPP */
