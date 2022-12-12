/*
** EPITECH PROJECT, 2021
** Circuit.hpp
** File description:
** Circuit class header
*/

#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>

#include "input.hpp"
#include "output.hpp"
#include "true.hpp"
#include "false.hpp"
#include "clock.hpp"
#include "Parser.hpp"
#include "LogicGate.hpp"
#include "C4001.hpp"
#include "C4071.hpp"
#include "C4011.hpp"
#include "C4030.hpp"
#include "C4081.hpp"
#include "C4069.hpp"

class Circuit {
    public:
        Circuit();
        ~Circuit();
        nts::IComponent *createComponent(const std::string &type);
        int fillCircuit(Parser *p);
        int startShell(void);
        int findEqual(std::string input);
        void changeComponentState(std::string input);
        void displayCircuit(void);
        void freeAll(void);
        int isGate(std::string gate);
        nts::Tristate callGate(std::string gateType, std::string a, std::string b);
        nts::Tristate convertState(std::string state);
        void createLink(std::vector<std::vector<std::string>> links);
        nts::IComponent *getComponentName(std::string const name);
        void simulateCircuit();

    private:
        static nts::IComponent *createOutput();
        static nts::IComponent *createInput();
        static nts::IComponent *createClock();
        static nts::IComponent *createTrue();
        static nts::IComponent *createFalse();
        static nts::IComponent *create4001();
        static nts::IComponent *create4011();
        static nts::IComponent *create4030();
        static nts::IComponent *create4071();
        static nts::IComponent *create4081();
        static nts::IComponent *create4069();
        typedef nts::IComponent *(*ptr)();
        typedef std::map<std::string, ptr> mapCall;
        std::vector<nts::IComponent*> comp;
        mapCall call;
        int tickNumber;
    protected:
};

#endif /* !CIRCUIT_HPP_ */
