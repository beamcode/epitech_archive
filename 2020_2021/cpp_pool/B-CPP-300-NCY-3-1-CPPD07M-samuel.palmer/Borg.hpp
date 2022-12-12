/*
** EPITECH PROJECT, 2021
** Borg.hpp
** File description:
** Borg
*/

#ifndef BORG_HPP_
#define BORG_HPP_

#include "Federation.hpp"

namespace Borg
{
    class Ship {
        private:
            int _side;
            short _maxWarp;
            WarpSystem::Core *_core;
        public:
            //Ctor & Dtor
            Ship();

            //Members
            void setupCore(WarpSystem::Core *core);
            void checkCore();
        };
} // namespace Borg

#endif /* !BORG_HPP_ */
