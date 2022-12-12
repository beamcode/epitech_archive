/*
** EPITECH PROJECT, 2021
** false.cpp
** File description:
** false class header
*/

#ifndef FALSE_H
#define FALSE_H

#include "Component.hpp"

class False : public Component {
    public:
        virtual ~False();
        False();
        nts::Tristate compute(std::size_t pin);
    protected:
    private:
};

#endif /* !FALSE_HPP_ */
