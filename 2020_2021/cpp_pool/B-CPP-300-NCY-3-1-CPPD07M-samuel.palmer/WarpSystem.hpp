/*
** EPITECH PROJECT, 2021
** header.cpp
** File description:
** ex00
*/

#ifndef WARPSYSTEM_HPP_
#define WARPSYSTEM_HPP_

#include "Federation.hpp"

namespace WarpSystem {
    class QuantumReactor {
        private:
            bool _stability;
        public:
            QuantumReactor();
            ~QuantumReactor();
            bool isStable();
            void setStability(bool stability);
    };
    class Core {
        private:
            QuantumReactor *_coreReactor;
        public:
            Core(QuantumReactor *core);
            ~Core();
            QuantumReactor *checkReactor();
    };
};

#endif