/*
** EPITECH PROJECT, 2021
** Gate.cpp
** File description:
** Gate class file
*/

#include "LogicGate.hpp"

LogicGate::LogicGate()
{
}

LogicGate::~LogicGate()
{
}

nts::Tristate LogicGate::GateAnd(nts::Tristate a, nts::Tristate b) const
{
    if ((a < 0 || b < 0) && (a == nts::FALSE || b == nts::FALSE))
        return (nts::FALSE);
    if ((a < 0 && b < 0) || ((a < 0 || b < 0) && (a == nts::TRUE || b == nts::TRUE)))
        return (nts::UNDEFINED);
    return(a == nts::TRUE && b == nts::TRUE ? nts::TRUE : nts::FALSE);
}

nts::Tristate LogicGate::GateOr(nts::Tristate a, nts::Tristate b) const
{
    if ((a < 0 || b < 0) && (a == nts::TRUE || b == nts::TRUE))
        return (nts::TRUE);
    if ((a < 0 && b < 0) || ((a < 0 || b < 0) && (a == nts::FALSE || b == nts::FALSE)))
        return (nts::UNDEFINED);
    return(a == nts::TRUE || b == nts::TRUE ? nts::TRUE : nts::FALSE);
}

nts::Tristate LogicGate::GateNAnd(nts::Tristate a, nts::Tristate b) const
{
    if ((a < 0 || b < 0) && (a == nts::FALSE || b == nts::FALSE))
        return (nts::TRUE);
    if ((a < 0 && b < 0) || ((a < 0 || b < 0) && (a == nts::TRUE || b == nts::TRUE)))
        return (nts::UNDEFINED);
    return(a == nts::FALSE || b == nts::FALSE ? nts::TRUE : nts::FALSE);
}

nts::Tristate LogicGate::GateNor(nts::Tristate a, nts::Tristate b) const
{
    if ((a < 0 || b < 0) && (a == nts::TRUE || b == nts::TRUE))
        return (nts::FALSE);
    if ((a < 0 && b < 0) || ((a < 0 || b < 0) && (a == nts::FALSE || b == nts::FALSE)))
        return (nts::UNDEFINED);
    return(a == nts::FALSE && b == nts::FALSE ? nts::TRUE : nts::FALSE);
}

nts::Tristate LogicGate::GateXor(nts::Tristate a, nts::Tristate b) const
{
    return(a < 0 || b < 0 ? nts::UNDEFINED : (a != b ? nts::TRUE : nts::FALSE));
}

nts::Tristate LogicGate::GateNot(nts::Tristate a) const
{
    return(a < 0 ? nts::UNDEFINED : (!a ? nts::TRUE : nts::FALSE));
}
