/*
** EPITECH PROJECT, 2021
** skat.hpp
** File description:
** ex00
*/

#ifndef SKAT_H_
#define SKAT_H_

#include <iostream>
#include <string>

class Skat
{
public:
    Skat(const std::string &name, int stimPaks);
    Skat();
    ~Skat();

    int &stimPaks();
    const std::string &name();
    void shareStimPaks(int number, int &stock);
    void addStimPaks(unsigned int number);
    void useStimPaks();
    void status();

private:
    int _stimPaks;
    std::string _name;
};

#endif