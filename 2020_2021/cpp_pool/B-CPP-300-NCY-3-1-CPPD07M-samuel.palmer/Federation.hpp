/*
** EPITECH PROJECT, 2021
** header.cpp
** File description:
** ex00
*/

#ifndef FEDERATION_HPP_
#define FEDERATION_HPP_

#include <string>
#include <iostream>
#include "WarpSystem.hpp"
#include "Borg.hpp"

namespace Federation {
    namespace Starfleet {
        class Captain {
            public:
                Captain(std::string _name);
                ~Captain();

                std::string getName();
                void setAge(int age);
                int getAge();
            private:
                std::string _name;
                int _age;
        };
        class Ship {
            private:
                int _length;
                int _width;
                std::string _name;
                short _maxWarp;
                WarpSystem::Core *_core;
                Captain *_captain;
            public:
                Ship(int length, int width, std::string name, short maxWarp);
                ~Ship();
                void setupCore(WarpSystem::Core *core);
                void checkCore();
                void promote(Captain *captain);
        };
        class Ensign {
            public:
                Ensign(std::string name);
                ~Ensign();
            private:
                std::string _name;
        };
    }
    class Ship {
        private:
            int _length;
            int _width;
            std::string _name;
            short _maxWarp;
            WarpSystem::Core *_core;
        public:
            Ship(int length, int width, std::string name);
            ~Ship();
            void setupCore(WarpSystem::Core *core);
            void checkCore();
    };
};

#endif