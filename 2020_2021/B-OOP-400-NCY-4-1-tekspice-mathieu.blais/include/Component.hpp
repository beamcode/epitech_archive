/*
** EPITECH PROJECT, 2021
** Component.hpp
** File description:
** Component class header
*/

#ifndef COMPONENT_H
#define COMPONENT_H

#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <map>

#include "IComponent.hpp"
#include "LogicGate.hpp"
#include "Pins.hpp"

class Component : public nts::IComponent {
    public:
        virtual ~Component();
        Component();

        void setName(const std::string &name);
        nts::Pin *getPin(size_t indxPin) const;
        size_t getMyPin(nts::Pin *pin) const;
        size_t getPinSize() const;
        std::string getName() const;
        std::string getType() const;
        void simulate();
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent *other, std::size_t otherPin);
        void dump() const;
    private:
    protected:
        std::vector<nts::Pin *> pins;
        std::string name;
        std::string type;
        nts::Tristate temp;
};

#endif /* !COMPONENT_HPP_ */
