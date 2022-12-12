/*
** EPITECH PROJECT, 2021
** Victim.hpp
** File description:
** Victim
*/

#ifndef VICTIM_HPP_
#define VICTIM_HPP_

#include <iostream>
#include <string>
#include <ostream>

class Victim {
    public:
        Victim(const std::string &name);
        ~Victim();

        virtual void getPolymorphed() const;
        const std::string getName() const;
    protected:
        const std::string _name;
    private:
};

std::ostream &operator<<(std::ostream &os, const Victim &s);

#endif /* !VICTIM_HPP_ */
