/*
** EPITECH PROJECT, 2021
** true.hpp
** File description:
** true class header
*/

#ifndef TRUE_H
#define TRUE_H

#include "Component.hpp"

class True : public Component {
    public:
        virtual ~True();
        True();
        nts::Tristate compute(std::size_t pin = 1);
    private:
    protected:
};

#endif /* !TRUE_HPP_ */
