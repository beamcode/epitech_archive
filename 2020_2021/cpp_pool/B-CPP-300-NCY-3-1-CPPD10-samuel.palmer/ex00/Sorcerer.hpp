/*
** EPITECH PROJECT, 2021
** Sorcerer.hpp
** File description:
** Sorcerer
*/

#ifndef SORCERER_HPP_
#define SORCERER_HPP_

#include <iostream>
#include <string>
#include "Victim.hpp"

class Sorcerer {
    public:
        //Ctor & Dtor
        Sorcerer(const std::string &name, const std::string &title);
        ~Sorcerer();

        //Members
        virtual void polymorph(const Victim &victim) const;
        const std::string getTitle() const { return _title; }
        const std::string getName() const { return _name; }
    protected:
        const std::string _name;
        const std::string _title;
    private:
};

std::ostream &operator<<(std::ostream &os, const Sorcerer &s);

#endif /* !SORCERER_HPP_ */
