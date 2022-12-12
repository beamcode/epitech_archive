/*
** EPITECH PROJECT, 2021
** C4001.hpp
** File description:
** C4001 Component class header
*/

#ifndef C4001_H
#define C4001_H

#include "Component.hpp"

class C4001 : public Component {
    public:
        C4001();
        virtual ~C4001();

        nts::Tristate compute(std::size_t pin);
    protected:
    private:
};

#endif /* !C4001_HPP */
