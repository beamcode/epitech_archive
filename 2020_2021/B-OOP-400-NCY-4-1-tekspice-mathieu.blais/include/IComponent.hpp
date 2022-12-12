/*
** EPITECH PROJECT, 2021
** IComponent.cpp
** File description:
** IComponent class header
*/

#ifndef ICOMPONENT_H
#define ICOMPONENT_H

#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <vector>

namespace nts
{
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };

    class Pin;

    class IComponent {
        public:
            virtual ~IComponent() = default;
            virtual void setName(const std::string &name) = 0;
            virtual std::string getName(void) const = 0;
            virtual Pin *getPin(size_t indxPin) const = 0;
            virtual size_t getMyPin(nts::Pin *pin) const = 0;
            virtual size_t getPinSize() const = 0;
            virtual std::string getType(void) const = 0;
            virtual void simulate() = 0;
            virtual nts::Tristate compute(std::size_t pin) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent *other, std::size_t otherPin) = 0;
            virtual void dump() const = 0;
        private:
        protected:
    };
}

#endif /* !ICOMPONENT_HPP_ */
