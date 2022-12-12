/*
** EPITECH PROJECT, 2021
** Pins.hpp
** File description:
** Pins class header
*/

#ifndef PINS_HPP_
#define PINS_HPP_

#include "IComponent.hpp"

namespace nts
{
    class Pin {
        public:
            Pin(nts::IComponent *component, const std::string &type, nts::Tristate state = nts::Tristate::UNDEFINED);
            ~Pin();

            void setState(nts::Tristate state, int i);
            nts::Tristate getState();
            nts::Tristate getActualState() const;
            std::string getType() const;
            void reverseState();
            void addLink(Pin *otherPin);
        private:
            nts::Tristate temp;
            nts::Tristate state;
            nts::IComponent *comp;
            Pin *link;
            std::string type;
        protected:
    };
};

#endif /* !PINS_HPP_ */
