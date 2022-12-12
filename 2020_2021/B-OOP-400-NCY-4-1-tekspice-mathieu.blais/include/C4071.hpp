/*
** EPITECH PROJECT, 2021
** C4071.cpp
** File description:
** C4071 Component class header
*/

#ifndef C4071_H
#define C4071_H

#include "Component.hpp"

class C4071 : public Component {
    public:
        C4071();
        virtual ~C4071();

        nts::Tristate compute(std::size_t pin);
    protected:
    private:
};

#endif /* !C4071_HPP */
