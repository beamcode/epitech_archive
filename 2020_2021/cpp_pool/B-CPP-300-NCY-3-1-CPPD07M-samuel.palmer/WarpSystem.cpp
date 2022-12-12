/*
** EPITECH PROJECT, 2021
** main.cpp
** File description:
** ex00
*/

#include "Federation.hpp"

WarpSystem::QuantumReactor::QuantumReactor() : _stability(true) {}
WarpSystem::QuantumReactor::~QuantumReactor() {}
WarpSystem::Core::~Core() {}

WarpSystem::Core::Core(QuantumReactor *core)
{
    if (!core)
        return;
    this->_coreReactor = core;
}

bool WarpSystem::QuantumReactor::isStable()
{
    return (this->_stability);
}

void WarpSystem::QuantumReactor::setStability(bool stability)
{
    this->_stability = stability;
}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor()
{
    return (this->_coreReactor);
}