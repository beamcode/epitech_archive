/*
** EPITECH PROJECT, 2021
** Gate.hpp
** File description:
** Gate class header
*/

#ifndef GATE_HPP_
#define GATE_HPP_

#include "IComponent.hpp"

class LogicGate {
    public:
        LogicGate();
        ~LogicGate();

        nts::Tristate GateAnd(nts::Tristate a, nts::Tristate b) const;
        nts::Tristate GateOr(nts::Tristate a, nts::Tristate b) const;
        nts::Tristate GateXor(nts::Tristate a, nts::Tristate b) const;
        nts::Tristate GateNAnd(nts::Tristate a, nts::Tristate b) const;
        nts::Tristate GateNor(nts::Tristate a, nts::Tristate b) const;
        nts::Tristate GateNot(nts::Tristate a) const;
    protected:
    private:
};

#endif /* !GATE_HPP_ */
