/*
** EPITECH PROJECT, 2021
** SickKoala.hpp
** File description:
** ex02 header file
*/

#ifndef SickKoala_H
#define SickKoala_H

#include <iostream>
#include <string>

class SickKoala{
    private:
        std::string name;

    public:
        ~SickKoala();
        SickKoala(std::string name);

        void overDrive(std::string name);
        bool takeDrug(std::string name);
        void poke(void);
};

#endif /* SickKoala */